/*
 * File: AppSwcIpm.c
 *
 * Code generated for Simulink model 'AppSwcIpm'.
 *
 * Model version                  : 9.219
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Nov 13 16:55:17 2024
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
ARID_DEF_AppSwcIpm_T AppSwcIpm_ARID_DEF;/* '<S176>/BusCreator' */
static void Runbl_Ipm100ms(void);
static void Runbl_Ipm10ms(void);
static void Runbl_Ipm20ms(void);
static void Runbl_Ipm50ms(void);

/* Output and update for function-call system: '<Root>/Ipm100ms' */
static void Runbl_Ipm100ms(void)
{
  sint32 rtb_Product_mh;
  float32 rtb_Product_l3f;
  boolean rtb_LogicalOperator2_j;

  /* Outputs for Atomic SubSystem: '<S14>/Subsys_VIPM_ClientNum_enum' */
  /* Logic: '<S18>/Logical Operator3' incorporates:
   *  Constant: '<S18>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_ClientNumVld_flg = (KIPM_ClientNum_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S18>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S18>/Switch' incorporates:
     *  Inport: '<Root>/ACCM_Version_BOD'
     *  Switch: '<S18>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hzk =
      (Rte_IRead_Runbl_IpmCanRx_100ms_ACCM_Version_BOD_ACCM_Version_BOD())
      ->Client_Number;
  } else {
    /* Switch: '<S18>/Switch' incorporates:
     *  Constant: '<S18>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hzk = KIPM_ClientNumDflt_enum;
  }

  /* End of Switch: '<S18>/Switch' */

  /* Switch: '<S18>/Switch4' incorporates:
   *  Constant: '<S18>/sat3'
   */
  if (KIPM_ClientNum_enum_ovrdflg) {
    /* Switch: '<S18>/Switch4' incorporates:
     *  Constant: '<S18>/sat4'
     */
    VIPM_ClientNum_enum = KIPM_ClientNum_enum_ovrdval;
  } else {
    /* Switch: '<S18>/Switch4' */
    VIPM_ClientNum_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hzk;
  }

  /* End of Switch: '<S18>/Switch4' */
  /* End of Outputs for SubSystem: '<S14>/Subsys_VIPM_ClientNum_enum' */

  /* Outputs for Atomic SubSystem: '<S14>/Subsys_VIPM_APPVerMax_enum' */
  /* Logic: '<S15>/Logical Operator3' incorporates:
   *  Constant: '<S15>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_APPVerMaxVld_flg = (KIPM_APPVerMax_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S15>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S15>/Switch' incorporates:
     *  Inport: '<Root>/ACCM_Version_BOD'
     *  Switch: '<S15>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ce =
      (Rte_IRead_Runbl_IpmCanRx_100ms_ACCM_Version_BOD_ACCM_Version_BOD())
      ->APP_Version_Max;
  } else {
    /* Switch: '<S15>/Switch' incorporates:
     *  Constant: '<S15>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ce = KIPM_APPVerMaxDflt_enum;
  }

  /* End of Switch: '<S15>/Switch' */

  /* Switch: '<S15>/Switch4' incorporates:
   *  Constant: '<S15>/sat3'
   */
  if (KIPM_APPVerMax_enum_ovrdflg) {
    /* Switch: '<S15>/Switch4' incorporates:
     *  Constant: '<S15>/sat4'
     */
    VIPM_APPVerMax_enum = KIPM_APPVerMax_enum_ovrdval;
  } else {
    /* Switch: '<S15>/Switch4' */
    VIPM_APPVerMax_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ce;
  }

  /* End of Switch: '<S15>/Switch4' */
  /* End of Outputs for SubSystem: '<S14>/Subsys_VIPM_APPVerMax_enum' */

  /* Outputs for Atomic SubSystem: '<S14>/Subsys_VIPM_APPVerMin_enum' */
  /* Logic: '<S16>/Logical Operator3' incorporates:
   *  Constant: '<S16>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_APPVerMinVld_flg = (KIPM_APPVerMin_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S16>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S16>/Switch' incorporates:
     *  Inport: '<Root>/ACCM_Version_BOD'
     *  Switch: '<S16>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ge =
      (Rte_IRead_Runbl_IpmCanRx_100ms_ACCM_Version_BOD_ACCM_Version_BOD())
      ->APP_Version_Min;
  } else {
    /* Switch: '<S16>/Switch' incorporates:
     *  Constant: '<S16>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ge = KIPM_APPVerMinDflt_enum;
  }

  /* End of Switch: '<S16>/Switch' */

  /* Switch: '<S16>/Switch4' incorporates:
   *  Constant: '<S16>/sat3'
   */
  if (KIPM_APPVerMin_enum_ovrdflg) {
    /* Switch: '<S16>/Switch4' incorporates:
     *  Constant: '<S16>/sat4'
     */
    VIPM_APPVerMin_enum = KIPM_APPVerMin_enum_ovrdval;
  } else {
    /* Switch: '<S16>/Switch4' */
    VIPM_APPVerMin_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ge;
  }

  /* End of Switch: '<S16>/Switch4' */
  /* End of Outputs for SubSystem: '<S14>/Subsys_VIPM_APPVerMin_enum' */

  /* Outputs for Atomic SubSystem: '<S14>/Subsys_VIPM_HwVerMax_enum' */
  /* Logic: '<S19>/Logical Operator3' incorporates:
   *  Constant: '<S19>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HwVerMaxVld_flg = (KIPM_HwVerMax_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S19>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S19>/Switch' incorporates:
     *  Inport: '<Root>/ACCM_Version_BOD'
     *  Switch: '<S19>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pyg =
      (Rte_IRead_Runbl_IpmCanRx_100ms_ACCM_Version_BOD_ACCM_Version_BOD())
      ->Hardware_Version_Max;
  } else {
    /* Switch: '<S19>/Switch' incorporates:
     *  Constant: '<S19>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pyg = KIPM_HwVerMaxDflt_enum;
  }

  /* End of Switch: '<S19>/Switch' */

  /* Switch: '<S19>/Switch4' incorporates:
   *  Constant: '<S19>/sat3'
   */
  if (KIPM_HwVerMax_enum_ovrdflg) {
    /* Switch: '<S19>/Switch4' incorporates:
     *  Constant: '<S19>/sat4'
     */
    VIPM_HwVerMax_enum = KIPM_HwVerMax_enum_ovrdval;
  } else {
    /* Switch: '<S19>/Switch4' */
    VIPM_HwVerMax_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pyg;
  }

  /* End of Switch: '<S19>/Switch4' */
  /* End of Outputs for SubSystem: '<S14>/Subsys_VIPM_HwVerMax_enum' */

  /* Outputs for Atomic SubSystem: '<S14>/Subsys_VIPM_HwVerMin_enum' */
  /* Logic: '<S20>/Logical Operator3' incorporates:
   *  Constant: '<S20>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HwVerMinVld_flg = (KIPM_HwVerMin_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S20>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S20>/Switch' incorporates:
     *  Inport: '<Root>/ACCM_Version_BOD'
     *  Switch: '<S20>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ha =
      (Rte_IRead_Runbl_IpmCanRx_100ms_ACCM_Version_BOD_ACCM_Version_BOD())
      ->Hardware_Version_Min;
  } else {
    /* Switch: '<S20>/Switch' incorporates:
     *  Constant: '<S20>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ha = KIPM_HwVerMinDflt_enum;
  }

  /* End of Switch: '<S20>/Switch' */

  /* Switch: '<S20>/Switch4' incorporates:
   *  Constant: '<S20>/sat3'
   */
  if (KIPM_HwVerMin_enum_ovrdflg) {
    /* Switch: '<S20>/Switch4' incorporates:
     *  Constant: '<S20>/sat4'
     */
    VIPM_HwVerMin_enum = KIPM_HwVerMin_enum_ovrdval;
  } else {
    /* Switch: '<S20>/Switch4' */
    VIPM_HwVerMin_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ha;
  }

  /* End of Switch: '<S20>/Switch4' */
  /* End of Outputs for SubSystem: '<S14>/Subsys_VIPM_HwVerMin_enum' */

  /* Outputs for Atomic SubSystem: '<S14>/Subsys_VIPM_BootVer_enum' */
  /* Logic: '<S17>/Logical Operator3' incorporates:
   *  Constant: '<S17>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BootVerVld_flg = (KIPM_BootVer_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S17>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S17>/Switch' incorporates:
     *  Inport: '<Root>/ACCM_Version_BOD'
     *  Switch: '<S17>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_evy =
      (Rte_IRead_Runbl_IpmCanRx_100ms_ACCM_Version_BOD_ACCM_Version_BOD())
      ->Boot_Version;
  } else {
    /* Switch: '<S17>/Switch' incorporates:
     *  Constant: '<S17>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_evy = KIPM_BootVerDflt_enum;
  }

  /* End of Switch: '<S17>/Switch' */

  /* Switch: '<S17>/Switch4' incorporates:
   *  Constant: '<S17>/sat3'
   */
  if (KIPM_BootVer_enum_ovrdflg) {
    /* Switch: '<S17>/Switch4' incorporates:
     *  Constant: '<S17>/sat4'
     */
    VIPM_BootVer_enum = KIPM_BootVer_enum_ovrdval;
  } else {
    /* Switch: '<S17>/Switch4' */
    VIPM_BootVer_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_evy;
  }

  /* End of Switch: '<S17>/Switch4' */
  /* End of Outputs for SubSystem: '<S14>/Subsys_VIPM_BootVer_enum' */

  /* BusCreator: '<S14>/BusCreator' incorporates:
   *  Logic: '<S15>/Logical Operator3'
   *  Logic: '<S16>/Logical Operator3'
   *  Logic: '<S17>/Logical Operator3'
   *  Logic: '<S18>/Logical Operator3'
   *  Logic: '<S19>/Logical Operator3'
   *  Logic: '<S20>/Logical Operator3'
   *  Switch: '<S15>/Switch4'
   *  Switch: '<S16>/Switch4'
   *  Switch: '<S17>/Switch4'
   *  Switch: '<S18>/Switch4'
   *  Switch: '<S19>/Switch4'
   *  Switch: '<S20>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_ACCM_Version_BOD.VIPM_ClientNum_enum =
    VIPM_ClientNum_enum;
  AppSwcIpm_ARID_DEF.IPM_ACCM_Version_BOD.VIPM_ClientNumVld_flg =
    VIPM_ClientNumVld_flg;
  AppSwcIpm_ARID_DEF.IPM_ACCM_Version_BOD.VIPM_APPVerMax_enum =
    VIPM_APPVerMax_enum;
  AppSwcIpm_ARID_DEF.IPM_ACCM_Version_BOD.VIPM_APPVerMaxVld_flg =
    VIPM_APPVerMaxVld_flg;
  AppSwcIpm_ARID_DEF.IPM_ACCM_Version_BOD.VIPM_APPVerMin_enum =
    VIPM_APPVerMin_enum;
  AppSwcIpm_ARID_DEF.IPM_ACCM_Version_BOD.VIPM_APPVerMinVld_flg =
    VIPM_APPVerMinVld_flg;
  AppSwcIpm_ARID_DEF.IPM_ACCM_Version_BOD.VIPM_HwVerMax_enum =
    VIPM_HwVerMax_enum;
  AppSwcIpm_ARID_DEF.IPM_ACCM_Version_BOD.VIPM_HwVerMaxVld_flg =
    VIPM_HwVerMaxVld_flg;
  AppSwcIpm_ARID_DEF.IPM_ACCM_Version_BOD.VIPM_HwVerMin_enum =
    VIPM_HwVerMin_enum;
  AppSwcIpm_ARID_DEF.IPM_ACCM_Version_BOD.VIPM_HwVerMinVld_flg =
    VIPM_HwVerMinVld_flg;
  AppSwcIpm_ARID_DEF.IPM_ACCM_Version_BOD.VIPM_BootVer_enum = VIPM_BootVer_enum;
  AppSwcIpm_ARID_DEF.IPM_ACCM_Version_BOD.VIPM_BootVerVld_flg =
    VIPM_BootVerVld_flg;

  /* Outputs for Atomic SubSystem: '<S21>/Subsys_VIPM_COMPOverDuty_flg' */
  /* Logic: '<S35>/Logical Operator3' incorporates:
   *  Constant: '<S35>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_COMPOverDutyVld_flg = (KIPM_COMPOverDuty_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S35>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S35>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_COMP_AC_CRCFlt_flg) {
      /* Switch: '<S35>/Switch' incorporates:
       *  Inport: '<Root>/COMP_AC_BOD'
       *  Switch: '<S35>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ig =
        (Rte_IRead_Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD())
        ->COMP_OverDuty;
    }

    /* End of Switch: '<S35>/Switch3' */
  } else {
    /* Switch: '<S35>/Switch' incorporates:
     *  Constant: '<S35>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ig = KIPM_COMPOverDutyDflt_flg;
  }

  /* End of Switch: '<S35>/Switch' */

  /* Switch: '<S35>/Switch4' incorporates:
   *  Constant: '<S35>/sat3'
   */
  if (KIPM_COMPOverDuty_flg_ovrdflg) {
    /* Switch: '<S35>/Switch4' incorporates:
     *  Constant: '<S35>/sat4'
     */
    VIPM_COMPOverDuty_flg = KIPM_COMPOverDuty_flg_ovrdval;
  } else {
    /* Switch: '<S35>/Switch4' */
    VIPM_COMPOverDuty_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ig;
  }

  /* End of Switch: '<S35>/Switch4' */
  /* End of Outputs for SubSystem: '<S21>/Subsys_VIPM_COMPOverDuty_flg' */

  /* Outputs for Atomic SubSystem: '<S21>/Subsys_VIPM_COMPCommuError_flg' */
  /* Logic: '<S25>/Logical Operator3' incorporates:
   *  Constant: '<S25>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_COMPCommuErrorVld_flg = (KIPM_COMPCommuError_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S25>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S25>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_COMP_AC_CRCFlt_flg) {
      /* Switch: '<S25>/Switch' incorporates:
       *  Inport: '<Root>/COMP_AC_BOD'
       *  Switch: '<S25>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ch =
        (Rte_IRead_Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD())
        ->COMP_Commu_Error;
    }

    /* End of Switch: '<S25>/Switch3' */
  } else {
    /* Switch: '<S25>/Switch' incorporates:
     *  Constant: '<S25>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ch = KIPM_COMPCommuErrorDflt_flg;
  }

  /* End of Switch: '<S25>/Switch' */

  /* Switch: '<S25>/Switch4' incorporates:
   *  Constant: '<S25>/sat3'
   */
  if (KIPM_COMPCommuError_flg_ovrdflg) {
    /* Switch: '<S25>/Switch4' incorporates:
     *  Constant: '<S25>/sat4'
     */
    VIPM_COMPCommuError_flg = KIPM_COMPCommuError_flg_ovrdval;
  } else {
    /* Switch: '<S25>/Switch4' */
    VIPM_COMPCommuError_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ch;
  }

  /* End of Switch: '<S25>/Switch4' */
  /* End of Outputs for SubSystem: '<S21>/Subsys_VIPM_COMPCommuError_flg' */

  /* Outputs for Atomic SubSystem: '<S21>/Subsys_VIPM_COMPPISaturation_flg' */
  /* Logic: '<S37>/Logical Operator3' incorporates:
   *  Constant: '<S37>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_COMPPISaturationVld_flg = (KIPM_COMPPISaturation_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S37>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S37>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_COMP_AC_CRCFlt_flg) {
      /* Switch: '<S37>/Switch' incorporates:
       *  Inport: '<Root>/COMP_AC_BOD'
       *  Switch: '<S37>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_bf =
        (Rte_IRead_Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD())
        ->COMP_PI_Saturation;
    }

    /* End of Switch: '<S37>/Switch3' */
  } else {
    /* Switch: '<S37>/Switch' incorporates:
     *  Constant: '<S37>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_bf = KIPM_COMPPISaturationDflt_flg;
  }

  /* End of Switch: '<S37>/Switch' */

  /* Switch: '<S37>/Switch4' incorporates:
   *  Constant: '<S37>/sat3'
   */
  if (KIPM_COMPPISaturation_flg_ovrdflg) {
    /* Switch: '<S37>/Switch4' incorporates:
     *  Constant: '<S37>/sat4'
     */
    VIPM_COMPPISaturation_flg = KIPM_COMPPISaturation_flg_ovrdval;
  } else {
    /* Switch: '<S37>/Switch4' */
    VIPM_COMPPISaturation_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_bf;
  }

  /* End of Switch: '<S37>/Switch4' */
  /* End of Outputs for SubSystem: '<S21>/Subsys_VIPM_COMPPISaturation_flg' */

  /* Outputs for Atomic SubSystem: '<S21>/Subsys_VIPM_COMPLoseStep_flg' */
  /* Logic: '<S33>/Logical Operator3' incorporates:
   *  Constant: '<S33>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_COMPLoseStepVld_flg = (KIPM_COMPLoseStep_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S33>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S33>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_COMP_AC_CRCFlt_flg) {
      /* Switch: '<S33>/Switch' incorporates:
       *  Inport: '<Root>/COMP_AC_BOD'
       *  Switch: '<S33>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ii =
        (Rte_IRead_Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD())
        ->COMP_LoseStep;
    }

    /* End of Switch: '<S33>/Switch3' */
  } else {
    /* Switch: '<S33>/Switch' incorporates:
     *  Constant: '<S33>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ii = KIPM_COMPLoseStepDflt_flg;
  }

  /* End of Switch: '<S33>/Switch' */

  /* Switch: '<S33>/Switch4' incorporates:
   *  Constant: '<S33>/sat3'
   */
  if (KIPM_COMPLoseStep_flg_ovrdflg) {
    /* Switch: '<S33>/Switch4' incorporates:
     *  Constant: '<S33>/sat4'
     */
    VIPM_COMPLoseStep_flg = KIPM_COMPLoseStep_flg_ovrdval;
  } else {
    /* Switch: '<S33>/Switch4' */
    VIPM_COMPLoseStep_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ii;
  }

  /* End of Switch: '<S33>/Switch4' */
  /* End of Outputs for SubSystem: '<S21>/Subsys_VIPM_COMPLoseStep_flg' */

  /* Outputs for Atomic SubSystem: '<S21>/Subsys_VIPM_COMPSelfChkErr_enum' */
  /* Logic: '<S38>/Logical Operator3' incorporates:
   *  Constant: '<S38>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_COMPSelfChkErrVld_flg = (KIPM_COMPSelfChkErr_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S38>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S38>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_COMP_AC_CRCFlt_flg) {
      /* Switch: '<S38>/Switch' incorporates:
       *  Inport: '<Root>/COMP_AC_BOD'
       *  Switch: '<S38>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_iv =
        (Rte_IRead_Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD())
        ->COMP_SelfCheckError;
    }

    /* End of Switch: '<S38>/Switch3' */
  } else {
    /* Switch: '<S38>/Switch' incorporates:
     *  Constant: '<S38>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_iv = KIPM_COMPSelfChkErrDflt_enum;
  }

  /* End of Switch: '<S38>/Switch' */

  /* Switch: '<S38>/Switch4' incorporates:
   *  Constant: '<S38>/sat3'
   */
  if (KIPM_COMPSelfChkErr_enum_ovrdflg) {
    /* Switch: '<S38>/Switch4' incorporates:
     *  Constant: '<S38>/sat4'
     */
    VIPM_COMPSelfChkErr_enum = KIPM_COMPSelfChkErr_enum_ovrdval;
  } else {
    /* Switch: '<S38>/Switch4' */
    VIPM_COMPSelfChkErr_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_iv;
  }

  /* End of Switch: '<S38>/Switch4' */
  /* End of Outputs for SubSystem: '<S21>/Subsys_VIPM_COMPSelfChkErr_enum' */

  /* Outputs for Atomic SubSystem: '<S21>/Subsys_VIPM_COMPIPMErr_flg' */
  /* Logic: '<S31>/Logical Operator3' incorporates:
   *  Constant: '<S31>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_COMPIPMErrVld_flg = (KIPM_COMPIPMErr_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S31>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S31>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_COMP_AC_CRCFlt_flg) {
      /* Switch: '<S31>/Switch' incorporates:
       *  Inport: '<Root>/COMP_AC_BOD'
       *  Switch: '<S31>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_do =
        (Rte_IRead_Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD())
        ->COMP_IPM_Error;
    }

    /* End of Switch: '<S31>/Switch3' */
  } else {
    /* Switch: '<S31>/Switch' incorporates:
     *  Constant: '<S31>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_do = KIPM_COMPIPMErrDflt_flg;
  }

  /* End of Switch: '<S31>/Switch' */

  /* Switch: '<S31>/Switch4' incorporates:
   *  Constant: '<S31>/sat3'
   */
  if (KIPM_COMPIPMErr_flg_ovrdflg) {
    /* Switch: '<S31>/Switch4' incorporates:
     *  Constant: '<S31>/sat4'
     */
    VIPM_COMPIPMErr_flg = KIPM_COMPIPMErr_flg_ovrdval;
  } else {
    /* Switch: '<S31>/Switch4' */
    VIPM_COMPIPMErr_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_do;
  }

  /* End of Switch: '<S31>/Switch4' */
  /* End of Outputs for SubSystem: '<S21>/Subsys_VIPM_COMPIPMErr_flg' */

  /* Outputs for Atomic SubSystem: '<S21>/Subsys_VIPM_COMPTempErr_flg' */
  /* Logic: '<S39>/Logical Operator3' incorporates:
   *  Constant: '<S39>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_COMPTempErrVld_flg = (KIPM_COMPTempErr_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S39>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S39>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_COMP_AC_CRCFlt_flg) {
      /* Switch: '<S39>/Switch' incorporates:
       *  Inport: '<Root>/COMP_AC_BOD'
       *  Switch: '<S39>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ja =
        (Rte_IRead_Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD())
        ->COMP_TempError;
    }

    /* End of Switch: '<S39>/Switch3' */
  } else {
    /* Switch: '<S39>/Switch' incorporates:
     *  Constant: '<S39>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ja = KIPM_COMPTempErrDflt_flg;
  }

  /* End of Switch: '<S39>/Switch' */

  /* Switch: '<S39>/Switch4' incorporates:
   *  Constant: '<S39>/sat3'
   */
  if (KIPM_COMPTempErr_flg_ovrdflg) {
    /* Switch: '<S39>/Switch4' incorporates:
     *  Constant: '<S39>/sat4'
     */
    VIPM_COMPTempErr_flg = KIPM_COMPTempErr_flg_ovrdval;
  } else {
    /* Switch: '<S39>/Switch4' */
    VIPM_COMPTempErr_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ja;
  }

  /* End of Switch: '<S39>/Switch4' */
  /* End of Outputs for SubSystem: '<S21>/Subsys_VIPM_COMPTempErr_flg' */

  /* Outputs for Atomic SubSystem: '<S21>/Subsys_VIPM_COMPLvErr_enum' */
  /* Logic: '<S34>/Logical Operator3' incorporates:
   *  Constant: '<S34>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_COMPLvErrVld_flg = (KIPM_COMPLvErr_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S34>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S34>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_COMP_AC_CRCFlt_flg) {
      /* Switch: '<S34>/Switch' incorporates:
       *  Inport: '<Root>/COMP_AC_BOD'
       *  Switch: '<S34>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ck =
        (Rte_IRead_Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD())->COMP_LvError;
    }

    /* End of Switch: '<S34>/Switch3' */
  } else {
    /* Switch: '<S34>/Switch' incorporates:
     *  Constant: '<S34>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ck = KIPM_COMPLvErrDflt_enum;
  }

  /* End of Switch: '<S34>/Switch' */

  /* Switch: '<S34>/Switch4' incorporates:
   *  Constant: '<S34>/sat3'
   */
  if (KIPM_COMPLvErr_enum_ovrdflg) {
    /* Switch: '<S34>/Switch4' incorporates:
     *  Constant: '<S34>/sat4'
     */
    VIPM_COMPLvErr_enum = KIPM_COMPLvErr_enum_ovrdval;
  } else {
    /* Switch: '<S34>/Switch4' */
    VIPM_COMPLvErr_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ck;
  }

  /* End of Switch: '<S34>/Switch4' */
  /* End of Outputs for SubSystem: '<S21>/Subsys_VIPM_COMPLvErr_enum' */

  /* Outputs for Atomic SubSystem: '<S21>/Subsys_VIPM_COMPHvErr_enum' */
  /* Logic: '<S30>/Logical Operator3' incorporates:
   *  Constant: '<S30>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_COMPHvErrVld_flg = (KIPM_COMPHvErr_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S30>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S30>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_COMP_AC_CRCFlt_flg) {
      /* Switch: '<S30>/Switch' incorporates:
       *  Inport: '<Root>/COMP_AC_BOD'
       *  Switch: '<S30>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pcn =
        (Rte_IRead_Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD())->COMP_HvError;
    }

    /* End of Switch: '<S30>/Switch3' */
  } else {
    /* Switch: '<S30>/Switch' incorporates:
     *  Constant: '<S30>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pcn = KIPM_COMPHvErrDflt_enum;
  }

  /* End of Switch: '<S30>/Switch' */

  /* Switch: '<S30>/Switch4' incorporates:
   *  Constant: '<S30>/sat3'
   */
  if (KIPM_COMPHvErr_enum_ovrdflg) {
    /* Switch: '<S30>/Switch4' incorporates:
     *  Constant: '<S30>/sat4'
     */
    VIPM_COMPHvErr_enum = KIPM_COMPHvErr_enum_ovrdval;
  } else {
    /* Switch: '<S30>/Switch4' */
    VIPM_COMPHvErr_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pcn;
  }

  /* End of Switch: '<S30>/Switch4' */
  /* End of Outputs for SubSystem: '<S21>/Subsys_VIPM_COMPHvErr_enum' */

  /* Outputs for Atomic SubSystem: '<S21>/Subsys_VIPM_COMPOvrCurr_enum' */
  /* Logic: '<S36>/Logical Operator3' incorporates:
   *  Constant: '<S36>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_COMPOvrCurrVld_flg = (KIPM_COMPOvrCurr_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S36>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S36>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_COMP_AC_CRCFlt_flg) {
      /* Switch: '<S36>/Switch' incorporates:
       *  Inport: '<Root>/COMP_AC_BOD'
       *  Switch: '<S36>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pr =
        (Rte_IRead_Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD())
        ->COMP_OverCurrent;
    }

    /* End of Switch: '<S36>/Switch3' */
  } else {
    /* Switch: '<S36>/Switch' incorporates:
     *  Constant: '<S36>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pr = KIPM_COMPOvrCurrDflt_enum;
  }

  /* End of Switch: '<S36>/Switch' */

  /* Switch: '<S36>/Switch4' incorporates:
   *  Constant: '<S36>/sat3'
   */
  if (KIPM_COMPOvrCurr_enum_ovrdflg) {
    /* Switch: '<S36>/Switch4' incorporates:
     *  Constant: '<S36>/sat4'
     */
    VIPM_COMPOvrCurr_enum = KIPM_COMPOvrCurr_enum_ovrdval;
  } else {
    /* Switch: '<S36>/Switch4' */
    VIPM_COMPOvrCurr_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pr;
  }

  /* End of Switch: '<S36>/Switch4' */
  /* End of Outputs for SubSystem: '<S21>/Subsys_VIPM_COMPOvrCurr_enum' */

  /* Outputs for Atomic SubSystem: '<S21>/Subsys_VIPM_COMPEcompST_enum' */
  /* Logic: '<S28>/Logical Operator3' incorporates:
   *  Constant: '<S28>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_COMPEcompSTVld_flg = (KIPM_COMPEcompST_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S28>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S28>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_COMP_AC_CRCFlt_flg) {
      /* Switch: '<S28>/Switch' incorporates:
       *  Inport: '<Root>/COMP_AC_BOD'
       *  Switch: '<S28>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lo =
        (Rte_IRead_Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD())->COMP_EcompST;
    }

    /* End of Switch: '<S28>/Switch3' */
  } else {
    /* Switch: '<S28>/Switch' incorporates:
     *  Constant: '<S28>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lo = KIPM_COMPEcompSTDflt_enum;
  }

  /* End of Switch: '<S28>/Switch' */

  /* Switch: '<S28>/Switch4' incorporates:
   *  Constant: '<S28>/sat3'
   */
  if (KIPM_COMPEcompST_enum_ovrdflg) {
    /* Switch: '<S28>/Switch4' incorporates:
     *  Constant: '<S28>/sat4'
     */
    VIPM_COMPEcompST_enum = KIPM_COMPEcompST_enum_ovrdval;
  } else {
    /* Switch: '<S28>/Switch4' */
    VIPM_COMPEcompST_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lo;
  }

  /* End of Switch: '<S28>/Switch4' */
  /* End of Outputs for SubSystem: '<S21>/Subsys_VIPM_COMPEcompST_enum' */

  /* Outputs for Atomic SubSystem: '<S21>/Subsys_VIPM_COMPCurrOfst_flg' */
  /* Logic: '<S26>/Logical Operator3' incorporates:
   *  Constant: '<S26>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_COMPCurrOfstVld_flg = (KIPM_COMPCurrOfst_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S26>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S26>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_COMP_AC_CRCFlt_flg) {
      /* Switch: '<S26>/Switch' incorporates:
       *  Inport: '<Root>/COMP_AC_BOD'
       *  Switch: '<S26>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_h2u =
        (Rte_IRead_Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD())
        ->COMP_CurrentOffset;
    }

    /* End of Switch: '<S26>/Switch3' */
  } else {
    /* Switch: '<S26>/Switch' incorporates:
     *  Constant: '<S26>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_h2u = KIPM_COMPCurrOfstDflt_flg;
  }

  /* End of Switch: '<S26>/Switch' */

  /* Switch: '<S26>/Switch4' incorporates:
   *  Constant: '<S26>/sat3'
   */
  if (KIPM_COMPCurrOfst_flg_ovrdflg) {
    /* Switch: '<S26>/Switch4' incorporates:
     *  Constant: '<S26>/sat4'
     */
    VIPM_COMPCurrOfst_flg = KIPM_COMPCurrOfst_flg_ovrdval;
  } else {
    /* Switch: '<S26>/Switch4' */
    VIPM_COMPCurrOfst_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_h2u;
  }

  /* End of Switch: '<S26>/Switch4' */
  /* End of Outputs for SubSystem: '<S21>/Subsys_VIPM_COMPCurrOfst_flg' */

  /* Outputs for Atomic SubSystem: '<S21>/Subsys_VIPM_COMPCANBusOff_flg' */
  /* Logic: '<S24>/Logical Operator3' incorporates:
   *  Constant: '<S24>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_COMPCANBusOffVld_flg = (KIPM_COMPCANBusOff_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S24>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S24>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_COMP_AC_CRCFlt_flg) {
      /* Switch: '<S24>/Switch' incorporates:
       *  Inport: '<Root>/COMP_AC_BOD'
       *  Switch: '<S24>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_g3l =
        (Rte_IRead_Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD())
        ->COMP_CANBusOff;
    }

    /* End of Switch: '<S24>/Switch3' */
  } else {
    /* Switch: '<S24>/Switch' incorporates:
     *  Constant: '<S24>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_g3l = KIPM_COMPCANBusOffDflt_flg;
  }

  /* End of Switch: '<S24>/Switch' */

  /* Switch: '<S24>/Switch4' incorporates:
   *  Constant: '<S24>/sat3'
   */
  if (KIPM_COMPCANBusOff_flg_ovrdflg) {
    /* Switch: '<S24>/Switch4' incorporates:
     *  Constant: '<S24>/sat4'
     */
    VIPM_COMPCANBusOff_flg = KIPM_COMPCANBusOff_flg_ovrdval;
  } else {
    /* Switch: '<S24>/Switch4' */
    VIPM_COMPCANBusOff_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_g3l;
  }

  /* End of Switch: '<S24>/Switch4' */
  /* End of Outputs for SubSystem: '<S21>/Subsys_VIPM_COMPCANBusOff_flg' */

  /* Outputs for Atomic SubSystem: '<S21>/Subsys_VIPM_ECUHiVoltInterlockSig_flg' */
  /* Logic: '<S41>/Logical Operator3' incorporates:
   *  Constant: '<S41>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_ECUHiVoltInterlockSigVld_flg = (KIPM_ECUHiVoltInterlockSig_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S41>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S41>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_COMP_AC_CRCFlt_flg) {
      /* Switch: '<S41>/Switch' incorporates:
       *  Inport: '<Root>/COMP_AC_BOD'
       *  Switch: '<S41>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lg3 =
        (Rte_IRead_Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD())
        ->ECUHighVoltInterlockSignal;
    }

    /* End of Switch: '<S41>/Switch3' */
  } else {
    /* Switch: '<S41>/Switch' incorporates:
     *  Constant: '<S41>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lg3 = KIPM_ECUHiVoltInterlockSigDflt_flg;
  }

  /* End of Switch: '<S41>/Switch' */

  /* Switch: '<S41>/Switch4' incorporates:
   *  Constant: '<S41>/sat3'
   */
  if (KIPM_ECUHiVoltInterlockSig_flg_ovrdflg) {
    /* Switch: '<S41>/Switch4' incorporates:
     *  Constant: '<S41>/sat4'
     */
    VIPM_ECUHiVoltInterlockSig_flg = KIPM_ECUHiVoltInterlockSig_flg_ovrdval;
  } else {
    /* Switch: '<S41>/Switch4' */
    VIPM_ECUHiVoltInterlockSig_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lg3;
  }

  /* End of Switch: '<S41>/Switch4' */
  /* End of Outputs for SubSystem: '<S21>/Subsys_VIPM_ECUHiVoltInterlockSig_flg' */

  /* Outputs for Atomic SubSystem: '<S21>/Subsys_VIPM_COMPTemp_C' */
  /* Logic: '<S40>/Logical Operator3' incorporates:
   *  Constant: '<S40>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_COMPTempVld_flg = (KIPM_COMPTemp_C_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S40>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S40>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_COMP_AC_CRCFlt_flg) {
      /* Product: '<S42>/Product' incorporates:
       *  Inport: '<Root>/COMP_AC_BOD'
       */
      rtb_Product_mh = (Rte_IRead_Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD())
        ->COMP_Temperature;

      /* Switch: '<S40>/Switch' incorporates:
       *  Sum: '<S42>/Add'
       *  Switch: '<S40>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lq = (float32)rtb_Product_mh - 60.0F;
    }

    /* End of Switch: '<S40>/Switch3' */
  } else {
    /* Switch: '<S40>/Switch' incorporates:
     *  Constant: '<S40>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lq = KIPM_COMPTempDflt_C;
  }

  /* End of Switch: '<S40>/Switch' */

  /* Switch: '<S40>/Switch4' incorporates:
   *  Constant: '<S40>/sat3'
   *  Constant: '<S40>/sat4'
   */
  if (KIPM_COMPTemp_C_ovrdflg) {
    VIPM_COMPTemp_C = KIPM_COMPTemp_C_ovrdval;
  } else {
    VIPM_COMPTemp_C = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lq;
  }

  /* MinMax: '<S40>/MinMax' incorporates:
   *  Constant: '<S40>/sat6'
   *  Switch: '<S40>/Switch4'
   */
  if (VIPM_COMPTemp_C > KIPM_COMPTempHi_C) {
    VIPM_COMPTemp_C = KIPM_COMPTempHi_C;
  }

  /* End of MinMax: '<S40>/MinMax' */

  /* MinMax: '<S40>/MinMax1' incorporates:
   *  Constant: '<S40>/sat7'
   */
  if (VIPM_COMPTemp_C < KIPM_COMPTempLo_C) {
    /* Switch: '<S40>/Switch4' incorporates:
     *  MinMax: '<S40>/MinMax1'
     */
    VIPM_COMPTemp_C = KIPM_COMPTempLo_C;
  }

  /* End of MinMax: '<S40>/MinMax1' */
  /* End of Outputs for SubSystem: '<S21>/Subsys_VIPM_COMPTemp_C' */

  /* Outputs for Atomic SubSystem: '<S21>/Subsys_VIPM_COMPInCurr_A' */
  /* Logic: '<S32>/Logical Operator3' incorporates:
   *  Constant: '<S32>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_COMPInCurrVld_flg = (KIPM_COMPInCurr_A_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S32>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S32>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_COMP_AC_CRCFlt_flg) {
      /* Switch: '<S32>/Switch' incorporates:
       *  Constant: '<S43>/Constant'
       *  Inport: '<Root>/COMP_AC_BOD'
       *  Product: '<S43>/Product'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_h = (float32)
        (Rte_IRead_Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD())
        ->COMP_InputCurrent * 0.25F;
    }

    /* End of Switch: '<S32>/Switch3' */
  } else {
    /* Switch: '<S32>/Switch' incorporates:
     *  Constant: '<S32>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_h = KIPM_COMPInCurrDflt_A;
  }

  /* End of Switch: '<S32>/Switch' */

  /* Switch: '<S32>/Switch4' incorporates:
   *  Constant: '<S32>/sat3'
   *  Constant: '<S32>/sat4'
   */
  if (KIPM_COMPInCurr_A_ovrdflg) {
    VIPM_COMPInCurr_A = KIPM_COMPInCurr_A_ovrdval;
  } else {
    VIPM_COMPInCurr_A = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_h;
  }

  /* MinMax: '<S32>/MinMax' incorporates:
   *  Constant: '<S32>/sat6'
   *  Switch: '<S32>/Switch4'
   */
  if (VIPM_COMPInCurr_A > KIPM_COMPInCurrHi_A) {
    VIPM_COMPInCurr_A = KIPM_COMPInCurrHi_A;
  }

  /* End of MinMax: '<S32>/MinMax' */

  /* MinMax: '<S32>/MinMax1' incorporates:
   *  Constant: '<S32>/sat7'
   */
  if (VIPM_COMPInCurr_A < KIPM_COMPInCurrLo_A) {
    /* Switch: '<S32>/Switch4' incorporates:
     *  MinMax: '<S32>/MinMax1'
     */
    VIPM_COMPInCurr_A = KIPM_COMPInCurrLo_A;
  }

  /* End of MinMax: '<S32>/MinMax1' */
  /* End of Outputs for SubSystem: '<S21>/Subsys_VIPM_COMPInCurr_A' */

  /* Outputs for Atomic SubSystem: '<S21>/Subsys_VIPM_COMPHiVolt_V' */
  /* Logic: '<S29>/Logical Operator3' incorporates:
   *  Constant: '<S29>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_COMPHiVoltVld_flg = (KIPM_COMPHiVolt_V_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S29>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S29>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_COMP_AC_CRCFlt_flg) {
      /* Product: '<S44>/Product' incorporates:
       *  Constant: '<S44>/Constant'
       *  Inport: '<Root>/COMP_AC_BOD'
       */
      rtb_Product_mh = (Rte_IRead_Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD())
        ->COMP_High_Voltage << 2;

      /* Switch: '<S29>/Switch' incorporates:
       *  Sum: '<S44>/Add'
       *  Switch: '<S29>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_kc = (float32)rtb_Product_mh;
    }

    /* End of Switch: '<S29>/Switch3' */
  } else {
    /* Switch: '<S29>/Switch' incorporates:
     *  Constant: '<S29>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_kc = KIPM_COMPHiVoltDflt_V;
  }

  /* End of Switch: '<S29>/Switch' */

  /* Switch: '<S29>/Switch4' incorporates:
   *  Constant: '<S29>/sat3'
   *  Constant: '<S29>/sat4'
   */
  if (KIPM_COMPHiVolt_V_ovrdflg) {
    VIPM_COMPHiVolt_V = KIPM_COMPHiVolt_V_ovrdval;
  } else {
    VIPM_COMPHiVolt_V = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_kc;
  }

  /* MinMax: '<S29>/MinMax' incorporates:
   *  Constant: '<S29>/sat6'
   *  Switch: '<S29>/Switch4'
   */
  if (VIPM_COMPHiVolt_V > KIPM_COMPHiVoltHi_V) {
    VIPM_COMPHiVolt_V = KIPM_COMPHiVoltHi_V;
  }

  /* End of MinMax: '<S29>/MinMax' */

  /* MinMax: '<S29>/MinMax1' incorporates:
   *  Constant: '<S29>/sat7'
   */
  if (VIPM_COMPHiVolt_V < KIPM_COMPHiVoltLo_V) {
    /* Switch: '<S29>/Switch4' incorporates:
     *  MinMax: '<S29>/MinMax1'
     */
    VIPM_COMPHiVolt_V = KIPM_COMPHiVoltLo_V;
  }

  /* End of MinMax: '<S29>/MinMax1' */
  /* End of Outputs for SubSystem: '<S21>/Subsys_VIPM_COMPHiVolt_V' */

  /* Outputs for Atomic SubSystem: '<S21>/Subsys_VIPM_COMPEcompActSpd_rpm' */
  /* Logic: '<S27>/Logical Operator3' incorporates:
   *  Constant: '<S27>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_COMPEcompActSpdVld_flg = (KIPM_COMPEcompActSpd_rpm_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S27>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S27>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_COMP_AC_CRCFlt_flg) {
      /* Product: '<S45>/Product' incorporates:
       *  Constant: '<S45>/Constant'
       *  Inport: '<Root>/COMP_AC_BOD'
       */
      rtb_Product_mh = (Rte_IRead_Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD())
        ->COMP_EcompActSpd * 50;

      /* Switch: '<S27>/Switch' incorporates:
       *  Sum: '<S45>/Add'
       *  Switch: '<S27>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hz = (float32)rtb_Product_mh;
    }

    /* End of Switch: '<S27>/Switch3' */
  } else {
    /* Switch: '<S27>/Switch' incorporates:
     *  Constant: '<S27>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hz = KIPM_COMPEcompActSpdDflt_rpm;
  }

  /* End of Switch: '<S27>/Switch' */

  /* Switch: '<S27>/Switch4' incorporates:
   *  Constant: '<S27>/sat3'
   *  Constant: '<S27>/sat4'
   */
  if (KIPM_COMPEcompActSpd_rpm_ovrdflg) {
    VIPM_COMPEcompActSpd_rpm = KIPM_COMPEcompActSpd_rpm_ovrdval;
  } else {
    VIPM_COMPEcompActSpd_rpm = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hz;
  }

  /* MinMax: '<S27>/MinMax' incorporates:
   *  Constant: '<S27>/sat6'
   *  Switch: '<S27>/Switch4'
   */
  if (VIPM_COMPEcompActSpd_rpm > KIPM_COMPEcompActSpdHi_rpm) {
    VIPM_COMPEcompActSpd_rpm = KIPM_COMPEcompActSpdHi_rpm;
  }

  /* End of MinMax: '<S27>/MinMax' */

  /* MinMax: '<S27>/MinMax1' incorporates:
   *  Constant: '<S27>/sat7'
   */
  if (VIPM_COMPEcompActSpd_rpm < KIPM_COMPEcompActSpdLo_rpm) {
    /* Switch: '<S27>/Switch4' incorporates:
     *  MinMax: '<S27>/MinMax1'
     */
    VIPM_COMPEcompActSpd_rpm = KIPM_COMPEcompActSpdLo_rpm;
  }

  /* End of MinMax: '<S27>/MinMax1' */
  /* End of Outputs for SubSystem: '<S21>/Subsys_VIPM_COMPEcompActSpd_rpm' */

  /* BusCreator: '<S21>/BusCreator' incorporates:
   *  Logic: '<S24>/Logical Operator3'
   *  Logic: '<S25>/Logical Operator3'
   *  Logic: '<S26>/Logical Operator3'
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
   *  MinMax: '<S27>/MinMax1'
   *  MinMax: '<S29>/MinMax1'
   *  MinMax: '<S32>/MinMax1'
   *  MinMax: '<S40>/MinMax1'
   *  Switch: '<S24>/Switch4'
   *  Switch: '<S25>/Switch4'
   *  Switch: '<S26>/Switch4'
   *  Switch: '<S28>/Switch4'
   *  Switch: '<S30>/Switch4'
   *  Switch: '<S31>/Switch4'
   *  Switch: '<S33>/Switch4'
   *  Switch: '<S34>/Switch4'
   *  Switch: '<S35>/Switch4'
   *  Switch: '<S36>/Switch4'
   *  Switch: '<S37>/Switch4'
   *  Switch: '<S38>/Switch4'
   *  Switch: '<S39>/Switch4'
   *  Switch: '<S41>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD.VIPM_COMPOverDuty_flg =
    VIPM_COMPOverDuty_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD.VIPM_COMPOverDutyVld_flg =
    VIPM_COMPOverDutyVld_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD.VIPM_COMPCommuError_flg =
    VIPM_COMPCommuError_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD.VIPM_COMPCommuErrorVld_flg =
    VIPM_COMPCommuErrorVld_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD.VIPM_COMPPISaturation_flg =
    VIPM_COMPPISaturation_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD.VIPM_COMPPISaturationVld_flg =
    VIPM_COMPPISaturationVld_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD.VIPM_COMPLoseStep_flg =
    VIPM_COMPLoseStep_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD.VIPM_COMPLoseStepVld_flg =
    VIPM_COMPLoseStepVld_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD.VIPM_COMPSelfChkErr_enum =
    VIPM_COMPSelfChkErr_enum;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD.VIPM_COMPSelfChkErrVld_flg =
    VIPM_COMPSelfChkErrVld_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD.VIPM_COMPIPMErr_flg = VIPM_COMPIPMErr_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD.VIPM_COMPIPMErrVld_flg =
    VIPM_COMPIPMErrVld_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD.VIPM_COMPTempErr_flg = VIPM_COMPTempErr_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD.VIPM_COMPTempErrVld_flg =
    VIPM_COMPTempErrVld_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD.VIPM_COMPLvErr_enum = VIPM_COMPLvErr_enum;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD.VIPM_COMPLvErrVld_flg =
    VIPM_COMPLvErrVld_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD.VIPM_COMPHvErr_enum = VIPM_COMPHvErr_enum;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD.VIPM_COMPHvErrVld_flg =
    VIPM_COMPHvErrVld_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD.VIPM_COMPOvrCurr_enum =
    VIPM_COMPOvrCurr_enum;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD.VIPM_COMPOvrCurrVld_flg =
    VIPM_COMPOvrCurrVld_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD.VIPM_COMPEcompST_enum =
    VIPM_COMPEcompST_enum;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD.VIPM_COMPEcompSTVld_flg =
    VIPM_COMPEcompSTVld_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD.VIPM_COMPCurrOfst_flg =
    VIPM_COMPCurrOfst_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD.VIPM_COMPCurrOfstVld_flg =
    VIPM_COMPCurrOfstVld_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD.VIPM_COMPCANBusOff_flg =
    VIPM_COMPCANBusOff_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD.VIPM_COMPCANBusOffVld_flg =
    VIPM_COMPCANBusOffVld_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD.VIPM_ECUHiVoltInterlockSig_flg =
    VIPM_ECUHiVoltInterlockSig_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD.VIPM_ECUHiVoltInterlockSigVld_flg =
    VIPM_ECUHiVoltInterlockSigVld_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD.VIPM_COMPTemp_C = VIPM_COMPTemp_C;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD.VIPM_COMPTempVld_flg = VIPM_COMPTempVld_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD.VIPM_COMPInCurr_A = VIPM_COMPInCurr_A;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD.VIPM_COMPInCurrVld_flg =
    VIPM_COMPInCurrVld_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD.VIPM_COMPHiVolt_V = VIPM_COMPHiVolt_V;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD.VIPM_COMPHiVoltVld_flg =
    VIPM_COMPHiVoltVld_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD.VIPM_COMPEcompActSpd_rpm =
    VIPM_COMPEcompActSpd_rpm;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD.VIPM_COMPEcompActSpdVld_flg =
    VIPM_COMPEcompActSpdVld_flg;

  /* Outputs for Atomic SubSystem: '<S22>/Subsys_VIPM_HVCHInletTemp_C' */
  /* Logic: '<S47>/Logical Operator3' incorporates:
   *  Constant: '<S47>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HVCHInletTempVld_flg = (KIPM_HVCHInletTemp_C_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_PTCMsgActv_flg);

  /* Switch: '<S47>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_PTCMsgActv_flg) {
    /* Switch: '<S47>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HVCH_Status1_CRCFlt_flg) {
      /* Product: '<S52>/Product' incorporates:
       *  Inport: '<Root>/HVCH_Status1_BOD'
       */
      rtb_Product_mh =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HVCH_Status1_BOD_HVCH_Status1_BOD())
        ->HVCH_InletTemp;

      /* Switch: '<S47>/Switch' incorporates:
       *  Sum: '<S52>/Add'
       *  Switch: '<S47>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lk = (float32)rtb_Product_mh - 40.0F;
    }

    /* End of Switch: '<S47>/Switch3' */
  } else {
    /* Switch: '<S47>/Switch' incorporates:
     *  Constant: '<S47>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lk = KIPM_HVCHInletTempDflt_C;
  }

  /* End of Switch: '<S47>/Switch' */

  /* Switch: '<S47>/Switch4' incorporates:
   *  Constant: '<S47>/sat3'
   *  Constant: '<S47>/sat4'
   */
  if (KIPM_HVCHInletTemp_C_ovrdflg) {
    VIPM_HVCHInletTemp_C = KIPM_HVCHInletTemp_C_ovrdval;
  } else {
    VIPM_HVCHInletTemp_C = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lk;
  }

  /* MinMax: '<S47>/MinMax' incorporates:
   *  Constant: '<S47>/sat6'
   *  Switch: '<S47>/Switch4'
   */
  if (VIPM_HVCHInletTemp_C > KIPM_HVCHInletTempHi_C) {
    VIPM_HVCHInletTemp_C = KIPM_HVCHInletTempHi_C;
  }

  /* End of MinMax: '<S47>/MinMax' */

  /* MinMax: '<S47>/MinMax1' incorporates:
   *  Constant: '<S47>/sat7'
   */
  if (VIPM_HVCHInletTemp_C < KIPM_HVCHInletTempLo_C) {
    /* Switch: '<S47>/Switch4' incorporates:
     *  MinMax: '<S47>/MinMax1'
     */
    VIPM_HVCHInletTemp_C = KIPM_HVCHInletTempLo_C;
  }

  /* End of MinMax: '<S47>/MinMax1' */
  /* End of Outputs for SubSystem: '<S22>/Subsys_VIPM_HVCHInletTemp_C' */

  /* Outputs for Atomic SubSystem: '<S22>/Subsys_VIPM_HVCHOutlTemp_C' */
  /* Logic: '<S48>/Logical Operator3' incorporates:
   *  Constant: '<S48>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HVCHOutlTempVld_flg = (KIPM_HVCHOutlTemp_C_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_PTCMsgActv_flg);

  /* Switch: '<S48>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_PTCMsgActv_flg) {
    /* Switch: '<S48>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HVCH_Status1_CRCFlt_flg) {
      /* Product: '<S53>/Product' incorporates:
       *  Inport: '<Root>/HVCH_Status1_BOD'
       */
      rtb_Product_mh =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HVCH_Status1_BOD_HVCH_Status1_BOD())
        ->HVCH_OutletTemp;

      /* Switch: '<S48>/Switch' incorporates:
       *  Sum: '<S53>/Add'
       *  Switch: '<S48>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_py = (float32)rtb_Product_mh - 40.0F;
    }

    /* End of Switch: '<S48>/Switch3' */
  } else {
    /* Switch: '<S48>/Switch' incorporates:
     *  Constant: '<S48>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_py = KIPM_HVCHOutlTempDflt_C;
  }

  /* End of Switch: '<S48>/Switch' */

  /* Switch: '<S48>/Switch4' incorporates:
   *  Constant: '<S48>/sat3'
   *  Constant: '<S48>/sat4'
   */
  if (KIPM_HVCHOutlTemp_C_ovrdflg) {
    VIPM_HVCHOutlTemp_C = KIPM_HVCHOutlTemp_C_ovrdval;
  } else {
    VIPM_HVCHOutlTemp_C = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_py;
  }

  /* MinMax: '<S48>/MinMax' incorporates:
   *  Constant: '<S48>/sat6'
   *  Switch: '<S48>/Switch4'
   */
  if (VIPM_HVCHOutlTemp_C > KIPM_HVCHOutlTempHi_C) {
    VIPM_HVCHOutlTemp_C = KIPM_HVCHOutlTempHi_C;
  }

  /* End of MinMax: '<S48>/MinMax' */

  /* MinMax: '<S48>/MinMax1' incorporates:
   *  Constant: '<S48>/sat7'
   */
  if (VIPM_HVCHOutlTemp_C < KIPM_HVCHOutlTempLo_C) {
    /* Switch: '<S48>/Switch4' incorporates:
     *  MinMax: '<S48>/MinMax1'
     */
    VIPM_HVCHOutlTemp_C = KIPM_HVCHOutlTempLo_C;
  }

  /* End of MinMax: '<S48>/MinMax1' */
  /* End of Outputs for SubSystem: '<S22>/Subsys_VIPM_HVCHOutlTemp_C' */

  /* Outputs for Atomic SubSystem: '<S22>/Subsys_VIPM_HVCHPCBTemp_C' */
  /* Logic: '<S49>/Logical Operator3' incorporates:
   *  Constant: '<S49>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HVCHPCBTempVld_flg = (KIPM_HVCHPCBTemp_C_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_PTCMsgActv_flg);

  /* Switch: '<S49>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_PTCMsgActv_flg) {
    /* Switch: '<S49>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HVCH_Status1_CRCFlt_flg) {
      /* Product: '<S54>/Product' incorporates:
       *  Inport: '<Root>/HVCH_Status1_BOD'
       */
      rtb_Product_mh =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HVCH_Status1_BOD_HVCH_Status1_BOD())
        ->HVCH_PCBTemp;

      /* Switch: '<S49>/Switch' incorporates:
       *  Sum: '<S54>/Add'
       *  Switch: '<S49>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_e1 = (float32)rtb_Product_mh - 40.0F;
    }

    /* End of Switch: '<S49>/Switch3' */
  } else {
    /* Switch: '<S49>/Switch' incorporates:
     *  Constant: '<S49>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_e1 = KIPM_HVCHPCBTempDflt_C;
  }

  /* End of Switch: '<S49>/Switch' */

  /* Switch: '<S49>/Switch4' incorporates:
   *  Constant: '<S49>/sat3'
   *  Constant: '<S49>/sat4'
   */
  if (KIPM_HVCHPCBTemp_C_ovrdflg) {
    VIPM_HVCHPCBTemp_C = KIPM_HVCHPCBTemp_C_ovrdval;
  } else {
    VIPM_HVCHPCBTemp_C = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_e1;
  }

  /* MinMax: '<S49>/MinMax' incorporates:
   *  Constant: '<S49>/sat6'
   *  Switch: '<S49>/Switch4'
   */
  if (VIPM_HVCHPCBTemp_C > KIPM_HVCHPCBTempHi_C) {
    VIPM_HVCHPCBTemp_C = KIPM_HVCHPCBTempHi_C;
  }

  /* End of MinMax: '<S49>/MinMax' */

  /* MinMax: '<S49>/MinMax1' incorporates:
   *  Constant: '<S49>/sat7'
   */
  if (VIPM_HVCHPCBTemp_C < KIPM_HVCHPCBTempLo_C) {
    /* Switch: '<S49>/Switch4' incorporates:
     *  MinMax: '<S49>/MinMax1'
     */
    VIPM_HVCHPCBTemp_C = KIPM_HVCHPCBTempLo_C;
  }

  /* End of MinMax: '<S49>/MinMax1' */
  /* End of Outputs for SubSystem: '<S22>/Subsys_VIPM_HVCHPCBTemp_C' */

  /* Outputs for Atomic SubSystem: '<S22>/Subsys_VIPM_HVCHWorkMode_enum' */
  /* Logic: '<S51>/Logical Operator3' incorporates:
   *  Constant: '<S51>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HVCHWorkModeVld_flg = (KIPM_HVCHWorkMode_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_PTCMsgActv_flg);

  /* Switch: '<S51>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_PTCMsgActv_flg) {
    /* Switch: '<S51>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HVCH_Status1_CRCFlt_flg) {
      /* Switch: '<S51>/Switch' incorporates:
       *  Inport: '<Root>/HVCH_Status1_BOD'
       *  Switch: '<S51>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_h2 =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HVCH_Status1_BOD_HVCH_Status1_BOD())
        ->HVCH_State;
    }

    /* End of Switch: '<S51>/Switch3' */
  } else {
    /* Switch: '<S51>/Switch' incorporates:
     *  Constant: '<S51>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_h2 = KIPM_HVCHWorkModeDflt_enum;
  }

  /* End of Switch: '<S51>/Switch' */

  /* Switch: '<S51>/Switch4' incorporates:
   *  Constant: '<S51>/sat3'
   */
  if (KIPM_HVCHWorkMode_enum_ovrdflg) {
    /* Switch: '<S51>/Switch4' incorporates:
     *  Constant: '<S51>/sat4'
     */
    VIPM_HVCHWorkMode_enum = KIPM_HVCHWorkMode_enum_ovrdval;
  } else {
    /* Switch: '<S51>/Switch4' */
    VIPM_HVCHWorkMode_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_h2;
  }

  /* End of Switch: '<S51>/Switch4' */
  /* End of Outputs for SubSystem: '<S22>/Subsys_VIPM_HVCHWorkMode_enum' */

  /* Outputs for Atomic SubSystem: '<S22>/Subsys_VIPM_HVCHHVSt_flg' */
  /* Logic: '<S46>/Logical Operator3' incorporates:
   *  Constant: '<S46>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HVCHHVStVld_flg = (KIPM_HVCHHVSt_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_PTCMsgActv_flg);

  /* Switch: '<S46>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_PTCMsgActv_flg) {
    /* Switch: '<S46>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HVCH_Status1_CRCFlt_flg) {
      /* Switch: '<S46>/Switch' incorporates:
       *  Inport: '<Root>/HVCH_Status1_BOD'
       *  Switch: '<S46>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_kzl =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HVCH_Status1_BOD_HVCH_Status1_BOD())
        ->HVCH_HVState;
    }

    /* End of Switch: '<S46>/Switch3' */
  } else {
    /* Switch: '<S46>/Switch' incorporates:
     *  Constant: '<S46>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_kzl = KIPM_HVCHHVStDflt_flg;
  }

  /* End of Switch: '<S46>/Switch' */

  /* Switch: '<S46>/Switch4' incorporates:
   *  Constant: '<S46>/sat3'
   */
  if (KIPM_HVCHHVSt_flg_ovrdflg) {
    /* Switch: '<S46>/Switch4' incorporates:
     *  Constant: '<S46>/sat4'
     */
    VIPM_HVCHHVSt_flg = KIPM_HVCHHVSt_flg_ovrdval;
  } else {
    /* Switch: '<S46>/Switch4' */
    VIPM_HVCHHVSt_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_kzl;
  }

  /* End of Switch: '<S46>/Switch4' */
  /* End of Outputs for SubSystem: '<S22>/Subsys_VIPM_HVCHHVSt_flg' */

  /* Outputs for Atomic SubSystem: '<S22>/Subsys_VIPM_HVCHSt_enum' */
  /* Logic: '<S50>/Logical Operator3' incorporates:
   *  Constant: '<S50>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HVCHStVld_flg = (KIPM_HVCHSt_enum_ovrdflg ||
                        (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV()
                        )->VIPM_PTCMsgActv_flg);

  /* Switch: '<S50>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_PTCMsgActv_flg) {
    /* Switch: '<S50>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HVCH_Status1_CRCFlt_flg) {
      /* Switch: '<S50>/Switch' incorporates:
       *  DataTypeConversion: '<S50>/Data Type Conversion2'
       *  Inport: '<Root>/HVCH_Status1_BOD'
       *  Switch: '<S50>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_g5 =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HVCH_Status1_BOD_HVCH_Status1_BOD())
        ->HVCH_WorkMode;
    }

    /* End of Switch: '<S50>/Switch3' */
  } else {
    /* Switch: '<S50>/Switch' incorporates:
     *  Constant: '<S50>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_g5 = KIPM_HVCHStDflt_enum;
  }

  /* End of Switch: '<S50>/Switch' */

  /* Switch: '<S50>/Switch4' incorporates:
   *  Constant: '<S50>/sat3'
   */
  if (KIPM_HVCHSt_enum_ovrdflg) {
    /* Switch: '<S50>/Switch4' incorporates:
     *  Constant: '<S50>/sat4'
     */
    VIPM_HVCHSt_enum = KIPM_HVCHSt_enum_ovrdval;
  } else {
    /* Switch: '<S50>/Switch4' */
    VIPM_HVCHSt_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_g5;
  }

  /* End of Switch: '<S50>/Switch4' */
  /* End of Outputs for SubSystem: '<S22>/Subsys_VIPM_HVCHSt_enum' */

  /* BusCreator: '<S22>/BusCreator' incorporates:
   *  Logic: '<S46>/Logical Operator3'
   *  Logic: '<S47>/Logical Operator3'
   *  Logic: '<S48>/Logical Operator3'
   *  Logic: '<S49>/Logical Operator3'
   *  Logic: '<S50>/Logical Operator3'
   *  Logic: '<S51>/Logical Operator3'
   *  MinMax: '<S47>/MinMax1'
   *  MinMax: '<S48>/MinMax1'
   *  MinMax: '<S49>/MinMax1'
   *  Switch: '<S46>/Switch4'
   *  Switch: '<S50>/Switch4'
   *  Switch: '<S51>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_HVCH_Status1_BOD.VIPM_HVCHInletTemp_C =
    VIPM_HVCHInletTemp_C;
  AppSwcIpm_ARID_DEF.IPM_HVCH_Status1_BOD.VIPM_HVCHInletTempVld_flg =
    VIPM_HVCHInletTempVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HVCH_Status1_BOD.VIPM_HVCHOutlTemp_C =
    VIPM_HVCHOutlTemp_C;
  AppSwcIpm_ARID_DEF.IPM_HVCH_Status1_BOD.VIPM_HVCHOutlTempVld_flg =
    VIPM_HVCHOutlTempVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HVCH_Status1_BOD.VIPM_HVCHPCBTemp_C =
    VIPM_HVCHPCBTemp_C;
  AppSwcIpm_ARID_DEF.IPM_HVCH_Status1_BOD.VIPM_HVCHPCBTempVld_flg =
    VIPM_HVCHPCBTempVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HVCH_Status1_BOD.VIPM_HVCHWorkMode_enum =
    VIPM_HVCHWorkMode_enum;
  AppSwcIpm_ARID_DEF.IPM_HVCH_Status1_BOD.VIPM_HVCHWorkModeVld_flg =
    VIPM_HVCHWorkModeVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HVCH_Status1_BOD.VIPM_HVCHHVSt_flg = VIPM_HVCHHVSt_flg;
  AppSwcIpm_ARID_DEF.IPM_HVCH_Status1_BOD.VIPM_HVCHHVStVld_flg =
    VIPM_HVCHHVStVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HVCH_Status1_BOD.VIPM_HVCHSt_enum = VIPM_HVCHSt_enum;
  AppSwcIpm_ARID_DEF.IPM_HVCH_Status1_BOD.VIPM_HVCHStVld_flg =
    VIPM_HVCHStVld_flg;

  /* Outputs for Atomic SubSystem: '<S23>/Subsys_VIPM_HVCHFltCod_enum' */
  /* Logic: '<S56>/Logical Operator3' incorporates:
   *  Constant: '<S56>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HVCHFltCodVld_flg = (KIPM_HVCHFltCod_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_PTCMsgActv_flg);

  /* Switch: '<S56>/Switch4' incorporates:
   *  Constant: '<S56>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S56>/Switch'
   */
  if (KIPM_HVCHFltCod_enum_ovrdflg) {
    /* Switch: '<S56>/Switch4' incorporates:
     *  Constant: '<S56>/sat4'
     */
    VIPM_HVCHFltCod_enum = KIPM_HVCHFltCod_enum_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
             ->VIPM_PTCMsgActv_flg) {
    /* Switch: '<S56>/Switch4' incorporates:
     *  DataTypeConversion: '<S56>/Data Type Conversion2'
     *  Inport: '<Root>/HVCH_Status2_BOD'
     *  Switch: '<S56>/Switch'
     */
    VIPM_HVCHFltCod_enum =
      (Rte_IRead_Runbl_IpmCanRx_100ms_HVCH_Status2_BOD_HVCH_Status2_BOD())
      ->HVCH_FaultCode;
  } else {
    /* Switch: '<S56>/Switch4' incorporates:
     *  Constant: '<S56>/sat5'
     *  Switch: '<S56>/Switch'
     */
    VIPM_HVCHFltCod_enum = KIPM_HVCHFltCodDflt_enum;
  }

  /* End of Switch: '<S56>/Switch4' */
  /* End of Outputs for SubSystem: '<S23>/Subsys_VIPM_HVCHFltCod_enum' */

  /* Outputs for Atomic SubSystem: '<S23>/Subsys_VIPM_HVCHHVVolts_V' */
  /* Logic: '<S57>/Logical Operator3' incorporates:
   *  Constant: '<S57>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HVCHHVVoltsVld_flg = (KIPM_HVCHHVVolts_V_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_PTCMsgActv_flg);

  /* Switch: '<S57>/Switch4' incorporates:
   *  Constant: '<S57>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S57>/Switch'
   */
  if (KIPM_HVCHHVVolts_V_ovrdflg) {
    /* MinMax: '<S57>/MinMax' incorporates:
     *  Constant: '<S57>/sat4'
     *  MinMax: '<S163>/MinMax'
     */
    VIPM_IPUOBCTempInt_C = KIPM_HVCHHVVolts_V_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
             ->VIPM_PTCMsgActv_flg) {
    /* Product: '<S60>/Product' incorporates:
     *  Constant: '<S60>/Constant'
     *  Inport: '<Root>/HVCH_Status2_BOD'
     *  Switch: '<S57>/Switch'
     */
    rtb_Product_mh =
      (Rte_IRead_Runbl_IpmCanRx_100ms_HVCH_Status2_BOD_HVCH_Status2_BOD())
      ->HVCH_HV_Volts << 2;

    /* MinMax: '<S57>/MinMax' incorporates:
     *  MinMax: '<S163>/MinMax'
     *  Sum: '<S60>/Add'
     *  Switch: '<S57>/Switch'
     */
    VIPM_IPUOBCTempInt_C = (float32)rtb_Product_mh;
  } else {
    /* MinMax: '<S57>/MinMax' incorporates:
     *  Constant: '<S57>/sat5'
     *  MinMax: '<S163>/MinMax'
     *  Switch: '<S57>/Switch'
     */
    VIPM_IPUOBCTempInt_C = KIPM_HVCHHVVoltsDflt_V;
  }

  /* End of Switch: '<S57>/Switch4' */

  /* MinMax: '<S57>/MinMax' incorporates:
   *  Constant: '<S57>/sat6'
   */
  if (VIPM_IPUOBCTempInt_C > KIPM_HVCHHVVoltsHi_V) {
    VIPM_IPUOBCTempInt_C = KIPM_HVCHHVVoltsHi_V;
  }

  /* MinMax: '<S57>/MinMax1' incorporates:
   *  Constant: '<S57>/sat7'
   */
  if (VIPM_IPUOBCTempInt_C >= KIPM_HVCHHVVoltsLo_V) {
    /* MinMax: '<S57>/MinMax1' */
    VIPM_HVCHHVVolts_V = VIPM_IPUOBCTempInt_C;
  } else {
    /* MinMax: '<S57>/MinMax1' */
    VIPM_HVCHHVVolts_V = KIPM_HVCHHVVoltsLo_V;
  }

  /* End of MinMax: '<S57>/MinMax1' */
  /* End of Outputs for SubSystem: '<S23>/Subsys_VIPM_HVCHHVVolts_V' */

  /* Outputs for Atomic SubSystem: '<S23>/Subsys_VIPM_HVCHCurr_A' */
  /* Logic: '<S55>/Logical Operator3' incorporates:
   *  Constant: '<S55>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HVCHCurrVld_flg = (KIPM_HVCHCurr_A_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_PTCMsgActv_flg);

  /* Switch: '<S55>/Switch4' incorporates:
   *  Constant: '<S55>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S55>/Switch'
   */
  if (KIPM_HVCHCurr_A_ovrdflg) {
    /* MinMax: '<S57>/MinMax' incorporates:
     *  Constant: '<S55>/sat4'
     *  MinMax: '<S163>/MinMax'
     */
    VIPM_IPUOBCTempInt_C = KIPM_HVCHCurr_A_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
             ->VIPM_PTCMsgActv_flg) {
    /* MinMax: '<S57>/MinMax' incorporates:
     *  Constant: '<S61>/Constant'
     *  Inport: '<Root>/HVCH_Status2_BOD'
     *  MinMax: '<S163>/MinMax'
     *  Product: '<S61>/Product'
     *  Switch: '<S55>/Switch'
     */
    VIPM_IPUOBCTempInt_C = (float32)
      (Rte_IRead_Runbl_IpmCanRx_100ms_HVCH_Status2_BOD_HVCH_Status2_BOD())
      ->HVCH_Current * 0.25F;
  } else {
    /* MinMax: '<S57>/MinMax' incorporates:
     *  Constant: '<S55>/sat5'
     *  MinMax: '<S163>/MinMax'
     *  Switch: '<S55>/Switch'
     */
    VIPM_IPUOBCTempInt_C = KIPM_HVCHCurrDflt_A;
  }

  /* End of Switch: '<S55>/Switch4' */

  /* MinMax: '<S55>/MinMax' incorporates:
   *  Constant: '<S55>/sat6'
   */
  if (VIPM_IPUOBCTempInt_C > KIPM_HVCHCurrHi_A) {
    /* MinMax: '<S57>/MinMax' */
    VIPM_IPUOBCTempInt_C = KIPM_HVCHCurrHi_A;
  }

  /* End of MinMax: '<S55>/MinMax' */

  /* MinMax: '<S55>/MinMax1' incorporates:
   *  Constant: '<S55>/sat7'
   */
  if (VIPM_IPUOBCTempInt_C >= KIPM_HVCHCurrLo_A) {
    /* MinMax: '<S55>/MinMax1' */
    VIPM_HVCHCurr_A = VIPM_IPUOBCTempInt_C;
  } else {
    /* MinMax: '<S55>/MinMax1' */
    VIPM_HVCHCurr_A = KIPM_HVCHCurrLo_A;
  }

  /* End of MinMax: '<S55>/MinMax1' */
  /* End of Outputs for SubSystem: '<S23>/Subsys_VIPM_HVCHCurr_A' */

  /* Outputs for Atomic SubSystem: '<S23>/Subsys_VIPM_HVCHPwr_kW' */
  /* Logic: '<S58>/Logical Operator3' incorporates:
   *  Constant: '<S58>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HVCHPwrVld_flg = (KIPM_HVCHPwr_kW_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_PTCMsgActv_flg);

  /* Switch: '<S58>/Switch4' incorporates:
   *  Constant: '<S58>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S58>/Switch'
   */
  if (KIPM_HVCHPwr_kW_ovrdflg) {
    /* MinMax: '<S57>/MinMax' incorporates:
     *  Constant: '<S58>/sat4'
     *  MinMax: '<S163>/MinMax'
     */
    VIPM_IPUOBCTempInt_C = KIPM_HVCHPwr_kW_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
             ->VIPM_PTCMsgActv_flg) {
    /* MinMax: '<S57>/MinMax' incorporates:
     *  Constant: '<S62>/Constant'
     *  Inport: '<Root>/HVCH_Status2_BOD'
     *  MinMax: '<S163>/MinMax'
     *  Product: '<S62>/Product'
     *  Switch: '<S58>/Switch'
     */
    VIPM_IPUOBCTempInt_C = (float32)
      (Rte_IRead_Runbl_IpmCanRx_100ms_HVCH_Status2_BOD_HVCH_Status2_BOD())
      ->HVCH_Power * 0.1F;
  } else {
    /* MinMax: '<S57>/MinMax' incorporates:
     *  Constant: '<S58>/sat5'
     *  MinMax: '<S163>/MinMax'
     *  Switch: '<S58>/Switch'
     */
    VIPM_IPUOBCTempInt_C = KIPM_HVCHPwrDflt_kW;
  }

  /* End of Switch: '<S58>/Switch4' */

  /* MinMax: '<S58>/MinMax' incorporates:
   *  Constant: '<S58>/sat6'
   */
  if (VIPM_IPUOBCTempInt_C > KIPM_HVCHPwrHi_kW) {
    /* MinMax: '<S57>/MinMax' */
    VIPM_IPUOBCTempInt_C = KIPM_HVCHPwrHi_kW;
  }

  /* End of MinMax: '<S58>/MinMax' */

  /* MinMax: '<S58>/MinMax1' incorporates:
   *  Constant: '<S58>/sat7'
   */
  if (VIPM_IPUOBCTempInt_C >= KIPM_HVCHPwrLo_kW) {
    /* MinMax: '<S58>/MinMax1' */
    VIPM_HVCHPwr_kW = VIPM_IPUOBCTempInt_C;
  } else {
    /* MinMax: '<S58>/MinMax1' */
    VIPM_HVCHPwr_kW = KIPM_HVCHPwrLo_kW;
  }

  /* End of MinMax: '<S58>/MinMax1' */
  /* End of Outputs for SubSystem: '<S23>/Subsys_VIPM_HVCHPwr_kW' */

  /* Outputs for Atomic SubSystem: '<S23>/Subsys_VIPM_HVCHWorkSt_enum' */
  /* Logic: '<S59>/Logical Operator3' incorporates:
   *  Constant: '<S59>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HVCHWorkStVld_flg = (KIPM_HVCHWorkSt_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_PTCMsgActv_flg);

  /* Switch: '<S59>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_PTCMsgActv_flg) {
    /* Switch: '<S59>/Switch' incorporates:
     *  Inport: '<Root>/HVCH_Status2_BOD'
     *  Switch: '<S59>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_c4 =
      (Rte_IRead_Runbl_IpmCanRx_100ms_HVCH_Status2_BOD_HVCH_Status2_BOD())
      ->HVCH_WorkState;
  } else {
    /* Switch: '<S59>/Switch' incorporates:
     *  Constant: '<S59>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_c4 = KIPM_HVCHWorkStDflt_enum;
  }

  /* End of Switch: '<S59>/Switch' */

  /* Switch: '<S59>/Switch4' incorporates:
   *  Constant: '<S59>/sat3'
   */
  if (KIPM_HVCHWorkSt_enum_ovrdflg) {
    /* Switch: '<S59>/Switch4' incorporates:
     *  Constant: '<S59>/sat4'
     */
    VIPM_HVCHWorkSt_enum = KIPM_HVCHWorkSt_enum_ovrdval;
  } else {
    /* Switch: '<S59>/Switch4' */
    VIPM_HVCHWorkSt_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_c4;
  }

  /* End of Switch: '<S59>/Switch4' */
  /* End of Outputs for SubSystem: '<S23>/Subsys_VIPM_HVCHWorkSt_enum' */

  /* BusCreator: '<S23>/BusCreator' incorporates:
   *  Logic: '<S55>/Logical Operator3'
   *  Logic: '<S56>/Logical Operator3'
   *  Logic: '<S57>/Logical Operator3'
   *  Logic: '<S58>/Logical Operator3'
   *  Logic: '<S59>/Logical Operator3'
   *  MinMax: '<S55>/MinMax1'
   *  MinMax: '<S57>/MinMax1'
   *  MinMax: '<S58>/MinMax1'
   *  Switch: '<S56>/Switch4'
   *  Switch: '<S59>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_HVCH_Status2_BOD.VIPM_HVCHFltCod_enum =
    VIPM_HVCHFltCod_enum;
  AppSwcIpm_ARID_DEF.IPM_HVCH_Status2_BOD.VIPM_HVCHFltCodVld_flg =
    VIPM_HVCHFltCodVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HVCH_Status2_BOD.VIPM_HVCHHVVolts_V =
    VIPM_HVCHHVVolts_V;
  AppSwcIpm_ARID_DEF.IPM_HVCH_Status2_BOD.VIPM_HVCHHVVoltsVld_flg =
    VIPM_HVCHHVVoltsVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HVCH_Status2_BOD.VIPM_HVCHCurr_A = VIPM_HVCHCurr_A;
  AppSwcIpm_ARID_DEF.IPM_HVCH_Status2_BOD.VIPM_HVCHCurrVld_flg =
    VIPM_HVCHCurrVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HVCH_Status2_BOD.VIPM_HVCHPwr_kW = VIPM_HVCHPwr_kW;
  AppSwcIpm_ARID_DEF.IPM_HVCH_Status2_BOD.VIPM_HVCHPwrVld_flg =
    VIPM_HVCHPwrVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HVCH_Status2_BOD.VIPM_HVCHWorkSt_enum =
    VIPM_HVCHWorkSt_enum;
  AppSwcIpm_ARID_DEF.IPM_HVCH_Status2_BOD.VIPM_HVCHWorkStVld_flg =
    VIPM_HVCHWorkStVld_flg;

  /* Outputs for Atomic SubSystem: '<S63>/Subsys_VIPM_TBOXBJSTimeYear_nu' */
  /* Logic: '<S69>/Logical Operator3' incorporates:
   *  Constant: '<S69>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_TBOXBJSTimeYearVld_flg = (KIPM_TBOXBJSTimeYear_nu_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_TBOXMsgActv_flg);

  /* Switch: '<S69>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_TBOXMsgActv_flg) {
    /* Switch: '<S69>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_TBOX_BJS_Time_CRCFlt_flg) {
      /* Sum: '<S70>/Add' incorporates:
       *  Inport: '<Root>/TBOX_BJS_Time_BAC'
       *  Product: '<S70>/Product'
       */
      rtb_Product_mh =
        (Rte_IRead_Runbl_IpmCanRx_100ms_TBOX_BJS_Time_BAC_TBOX_BJS_Time_BAC())
        ->TBOX_BJS_Time_Year;

      /* Switch: '<S69>/Switch' incorporates:
       *  Constant: '<S70>/Constant1'
       *  Sum: '<S70>/Add'
       *  Switch: '<S69>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_g = (uint16)(rtb_Product_mh + 2000);
    }

    /* End of Switch: '<S69>/Switch3' */
  } else {
    /* Switch: '<S69>/Switch' incorporates:
     *  Constant: '<S69>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_g = KIPM_TBOXBJSTimeYearDflt_nu;
  }

  /* End of Switch: '<S69>/Switch' */

  /* Switch: '<S69>/Switch4' incorporates:
   *  Constant: '<S69>/sat3'
   */
  if (KIPM_TBOXBJSTimeYear_nu_ovrdflg) {
    /* Switch: '<S69>/Switch4' incorporates:
     *  Constant: '<S69>/sat4'
     */
    VIPM_TBOXBJSTimeYear_nu = KIPM_TBOXBJSTimeYear_nu_ovrdval;
  } else {
    /* Switch: '<S69>/Switch4' */
    VIPM_TBOXBJSTimeYear_nu = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_g;
  }

  /* End of Switch: '<S69>/Switch4' */
  /* End of Outputs for SubSystem: '<S63>/Subsys_VIPM_TBOXBJSTimeYear_nu' */

  /* Outputs for Atomic SubSystem: '<S63>/Subsys_VIPM_TBOXBJSTimeMonth_nu' */
  /* Logic: '<S67>/Logical Operator3' incorporates:
   *  Constant: '<S67>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_TBOXBJSTimeMonthVld_flg = (KIPM_TBOXBJSTimeMonth_nu_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_TBOXMsgActv_flg);

  /* Switch: '<S67>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_TBOXMsgActv_flg) {
    /* Switch: '<S67>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_TBOX_BJS_Time_CRCFlt_flg) {
      /* Switch: '<S67>/Switch' incorporates:
       *  Inport: '<Root>/TBOX_BJS_Time_BAC'
       *  Switch: '<S67>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ah =
        (Rte_IRead_Runbl_IpmCanRx_100ms_TBOX_BJS_Time_BAC_TBOX_BJS_Time_BAC())
        ->TBOX_BJS_Time_Month;
    }

    /* End of Switch: '<S67>/Switch3' */
  } else {
    /* Switch: '<S67>/Switch' incorporates:
     *  Constant: '<S67>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ah = KIPM_TBOXBJSTimeMonthDflt_nu;
  }

  /* End of Switch: '<S67>/Switch' */

  /* Switch: '<S67>/Switch4' incorporates:
   *  Constant: '<S67>/sat3'
   */
  if (KIPM_TBOXBJSTimeMonth_nu_ovrdflg) {
    /* Switch: '<S67>/Switch4' incorporates:
     *  Constant: '<S67>/sat4'
     */
    VIPM_TBOXBJSTimeMonth_nu = KIPM_TBOXBJSTimeMonth_nu_ovrdval;
  } else {
    /* Switch: '<S67>/Switch4' */
    VIPM_TBOXBJSTimeMonth_nu = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ah;
  }

  /* End of Switch: '<S67>/Switch4' */
  /* End of Outputs for SubSystem: '<S63>/Subsys_VIPM_TBOXBJSTimeMonth_nu' */

  /* Outputs for Atomic SubSystem: '<S63>/Subsys_VIPM_TBOXBJSTimeDay_nu' */
  /* Logic: '<S64>/Logical Operator3' incorporates:
   *  Constant: '<S64>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_TBOXBJSTimeDayVld_flg = (KIPM_TBOXBJSTimeDay_nu_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_TBOXMsgActv_flg);

  /* Switch: '<S64>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_TBOXMsgActv_flg) {
    /* Switch: '<S64>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_TBOX_BJS_Time_CRCFlt_flg) {
      /* Switch: '<S64>/Switch' incorporates:
       *  Inport: '<Root>/TBOX_BJS_Time_BAC'
       *  Switch: '<S64>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_iy =
        (Rte_IRead_Runbl_IpmCanRx_100ms_TBOX_BJS_Time_BAC_TBOX_BJS_Time_BAC())
        ->TBOX_BJS_Time_Day;
    }

    /* End of Switch: '<S64>/Switch3' */
  } else {
    /* Switch: '<S64>/Switch' incorporates:
     *  Constant: '<S64>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_iy = KIPM_TBOXBJSTimeDayDflt_nu;
  }

  /* End of Switch: '<S64>/Switch' */

  /* Switch: '<S64>/Switch4' incorporates:
   *  Constant: '<S64>/sat3'
   */
  if (KIPM_TBOXBJSTimeDay_nu_ovrdflg) {
    /* Switch: '<S64>/Switch4' incorporates:
     *  Constant: '<S64>/sat4'
     */
    VIPM_TBOXBJSTimeDay_nu = KIPM_TBOXBJSTimeDay_nu_ovrdval;
  } else {
    /* Switch: '<S64>/Switch4' */
    VIPM_TBOXBJSTimeDay_nu = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_iy;
  }

  /* End of Switch: '<S64>/Switch4' */
  /* End of Outputs for SubSystem: '<S63>/Subsys_VIPM_TBOXBJSTimeDay_nu' */

  /* Outputs for Atomic SubSystem: '<S63>/Subsys_VIPM_TBOXBJSTimeHour_nu' */
  /* Logic: '<S65>/Logical Operator3' incorporates:
   *  Constant: '<S65>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_TBOXBJSTimeHourVld_flg = (KIPM_TBOXBJSTimeHour_nu_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_TBOXMsgActv_flg);

  /* Switch: '<S65>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_TBOXMsgActv_flg) {
    /* Switch: '<S65>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_TBOX_BJS_Time_CRCFlt_flg) {
      /* Switch: '<S65>/Switch' incorporates:
       *  Inport: '<Root>/TBOX_BJS_Time_BAC'
       *  Switch: '<S65>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ke =
        (Rte_IRead_Runbl_IpmCanRx_100ms_TBOX_BJS_Time_BAC_TBOX_BJS_Time_BAC())
        ->TBOX_BJS_Time_Hour;
    }

    /* End of Switch: '<S65>/Switch3' */
  } else {
    /* Switch: '<S65>/Switch' incorporates:
     *  Constant: '<S65>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ke = KIPM_TBOXBJSTimeHourDflt_nu;
  }

  /* End of Switch: '<S65>/Switch' */

  /* Switch: '<S65>/Switch4' incorporates:
   *  Constant: '<S65>/sat3'
   */
  if (KIPM_TBOXBJSTimeHour_nu_ovrdflg) {
    /* Switch: '<S65>/Switch4' incorporates:
     *  Constant: '<S65>/sat4'
     */
    VIPM_TBOXBJSTimeHour_nu = KIPM_TBOXBJSTimeHour_nu_ovrdval;
  } else {
    /* Switch: '<S65>/Switch4' */
    VIPM_TBOXBJSTimeHour_nu = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ke;
  }

  /* End of Switch: '<S65>/Switch4' */
  /* End of Outputs for SubSystem: '<S63>/Subsys_VIPM_TBOXBJSTimeHour_nu' */

  /* Outputs for Atomic SubSystem: '<S63>/Subsys_VIPM_TBOXBJSTimeMin_nu' */
  /* Logic: '<S66>/Logical Operator3' incorporates:
   *  Constant: '<S66>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_TBOXBJSTimeMinVld_flg = (KIPM_TBOXBJSTimeMin_nu_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_TBOXMsgActv_flg);

  /* Switch: '<S66>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_TBOXMsgActv_flg) {
    /* Switch: '<S66>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_TBOX_BJS_Time_CRCFlt_flg) {
      /* Switch: '<S66>/Switch' incorporates:
       *  Inport: '<Root>/TBOX_BJS_Time_BAC'
       *  Switch: '<S66>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jg0 =
        (Rte_IRead_Runbl_IpmCanRx_100ms_TBOX_BJS_Time_BAC_TBOX_BJS_Time_BAC())
        ->TBOX_BJS_Time_Min;
    }

    /* End of Switch: '<S66>/Switch3' */
  } else {
    /* Switch: '<S66>/Switch' incorporates:
     *  Constant: '<S66>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jg0 = KIPM_TBOXBJSTimeMinDflt_nu;
  }

  /* End of Switch: '<S66>/Switch' */

  /* Switch: '<S66>/Switch4' incorporates:
   *  Constant: '<S66>/sat3'
   */
  if (KIPM_TBOXBJSTimeMin_nu_ovrdflg) {
    /* Switch: '<S66>/Switch4' incorporates:
     *  Constant: '<S66>/sat4'
     */
    VIPM_TBOXBJSTimeMin_nu = KIPM_TBOXBJSTimeMin_nu_ovrdval;
  } else {
    /* Switch: '<S66>/Switch4' */
    VIPM_TBOXBJSTimeMin_nu = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jg0;
  }

  /* End of Switch: '<S66>/Switch4' */
  /* End of Outputs for SubSystem: '<S63>/Subsys_VIPM_TBOXBJSTimeMin_nu' */

  /* Outputs for Atomic SubSystem: '<S63>/Subsys_VIPM_TBOXBJSTimeSec_nu' */
  /* Logic: '<S68>/Logical Operator3' incorporates:
   *  Constant: '<S68>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_TBOXBJSTimeSecVld_flg = (KIPM_TBOXBJSTimeSec_nu_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_TBOXMsgActv_flg);

  /* Switch: '<S68>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_TBOXMsgActv_flg) {
    /* Switch: '<S68>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_TBOX_BJS_Time_CRCFlt_flg) {
      /* Switch: '<S68>/Switch' incorporates:
       *  Inport: '<Root>/TBOX_BJS_Time_BAC'
       *  Switch: '<S68>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_no =
        (Rte_IRead_Runbl_IpmCanRx_100ms_TBOX_BJS_Time_BAC_TBOX_BJS_Time_BAC())
        ->TBOX_BJS_Time_Sec;
    }

    /* End of Switch: '<S68>/Switch3' */
  } else {
    /* Switch: '<S68>/Switch' incorporates:
     *  Constant: '<S68>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_no = KIPM_TBOXBJSTimeSecDflt_nu;
  }

  /* End of Switch: '<S68>/Switch' */

  /* Switch: '<S68>/Switch4' incorporates:
   *  Constant: '<S68>/sat3'
   */
  if (KIPM_TBOXBJSTimeSec_nu_ovrdflg) {
    /* Switch: '<S68>/Switch4' incorporates:
     *  Constant: '<S68>/sat4'
     */
    VIPM_TBOXBJSTimeSec_nu = KIPM_TBOXBJSTimeSec_nu_ovrdval;
  } else {
    /* Switch: '<S68>/Switch4' */
    VIPM_TBOXBJSTimeSec_nu = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_no;
  }

  /* End of Switch: '<S68>/Switch4' */
  /* End of Outputs for SubSystem: '<S63>/Subsys_VIPM_TBOXBJSTimeSec_nu' */

  /* BusCreator: '<S63>/BusCreator' incorporates:
   *  Logic: '<S64>/Logical Operator3'
   *  Logic: '<S65>/Logical Operator3'
   *  Logic: '<S66>/Logical Operator3'
   *  Logic: '<S67>/Logical Operator3'
   *  Logic: '<S68>/Logical Operator3'
   *  Logic: '<S69>/Logical Operator3'
   *  Switch: '<S64>/Switch4'
   *  Switch: '<S65>/Switch4'
   *  Switch: '<S66>/Switch4'
   *  Switch: '<S67>/Switch4'
   *  Switch: '<S68>/Switch4'
   *  Switch: '<S69>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_TBOX_BJS_Time_BAC.VIPM_TBOXBJSTimeYear_nu =
    VIPM_TBOXBJSTimeYear_nu;
  AppSwcIpm_ARID_DEF.IPM_TBOX_BJS_Time_BAC.VIPM_TBOXBJSTimeYearVld_flg =
    VIPM_TBOXBJSTimeYearVld_flg;
  AppSwcIpm_ARID_DEF.IPM_TBOX_BJS_Time_BAC.VIPM_TBOXBJSTimeMonth_nu =
    VIPM_TBOXBJSTimeMonth_nu;
  AppSwcIpm_ARID_DEF.IPM_TBOX_BJS_Time_BAC.VIPM_TBOXBJSTimeMonthVld_flg =
    VIPM_TBOXBJSTimeMonthVld_flg;
  AppSwcIpm_ARID_DEF.IPM_TBOX_BJS_Time_BAC.VIPM_TBOXBJSTimeDay_nu =
    VIPM_TBOXBJSTimeDay_nu;
  AppSwcIpm_ARID_DEF.IPM_TBOX_BJS_Time_BAC.VIPM_TBOXBJSTimeDayVld_flg =
    VIPM_TBOXBJSTimeDayVld_flg;
  AppSwcIpm_ARID_DEF.IPM_TBOX_BJS_Time_BAC.VIPM_TBOXBJSTimeHour_nu =
    VIPM_TBOXBJSTimeHour_nu;
  AppSwcIpm_ARID_DEF.IPM_TBOX_BJS_Time_BAC.VIPM_TBOXBJSTimeHourVld_flg =
    VIPM_TBOXBJSTimeHourVld_flg;
  AppSwcIpm_ARID_DEF.IPM_TBOX_BJS_Time_BAC.VIPM_TBOXBJSTimeMin_nu =
    VIPM_TBOXBJSTimeMin_nu;
  AppSwcIpm_ARID_DEF.IPM_TBOX_BJS_Time_BAC.VIPM_TBOXBJSTimeMinVld_flg =
    VIPM_TBOXBJSTimeMinVld_flg;
  AppSwcIpm_ARID_DEF.IPM_TBOX_BJS_Time_BAC.VIPM_TBOXBJSTimeSec_nu =
    VIPM_TBOXBJSTimeSec_nu;
  AppSwcIpm_ARID_DEF.IPM_TBOX_BJS_Time_BAC.VIPM_TBOXBJSTimeSecVld_flg =
    VIPM_TBOXBJSTimeSecVld_flg;

  /* Outputs for Atomic SubSystem: '<S71>/Subsys_VIPM_ICUTotOdo_km' */
  /* Logic: '<S73>/Logical Operator3' incorporates:
   *  Constant: '<S73>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_ICUTotOdoVld_flg = (KIPM_ICUTotOdo_km_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_CDCMsgActv_flg);

  /* Switch: '<S73>/Switch4' incorporates:
   *  Constant: '<S73>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S73>/Switch'
   */
  if (KIPM_ICUTotOdo_km_ovrdflg) {
    /* MinMax: '<S57>/MinMax' incorporates:
     *  Constant: '<S73>/sat4'
     *  MinMax: '<S163>/MinMax'
     */
    VIPM_IPUOBCTempInt_C = KIPM_ICUTotOdo_km_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
             ->VIPM_CDCMsgActv_flg) {
    /* MinMax: '<S57>/MinMax' incorporates:
     *  Constant: '<S74>/Constant'
     *  Inport: '<Root>/ICU_2_Odo_BAC'
     *  MinMax: '<S163>/MinMax'
     *  Product: '<S74>/Product'
     *  Switch: '<S73>/Switch'
     */
    VIPM_IPUOBCTempInt_C = (float32)
      (Rte_IRead_Runbl_IpmCanRx_100ms_ICU_2_Odo_BAC_ICU_2_Odo_BAC())
      ->ICU_ICUTotalOdometer * 0.1F;
  } else {
    /* MinMax: '<S57>/MinMax' incorporates:
     *  Constant: '<S73>/sat5'
     *  MinMax: '<S163>/MinMax'
     *  Switch: '<S73>/Switch'
     */
    VIPM_IPUOBCTempInt_C = KIPM_ICUTotOdoDflt_km;
  }

  /* End of Switch: '<S73>/Switch4' */

  /* MinMax: '<S73>/MinMax' incorporates:
   *  Constant: '<S73>/sat6'
   */
  if (VIPM_IPUOBCTempInt_C > KIPM_ICUTotOdoHi_km) {
    /* MinMax: '<S57>/MinMax' */
    VIPM_IPUOBCTempInt_C = KIPM_ICUTotOdoHi_km;
  }

  /* End of MinMax: '<S73>/MinMax' */

  /* MinMax: '<S73>/MinMax1' incorporates:
   *  Constant: '<S73>/sat7'
   */
  if (VIPM_IPUOBCTempInt_C >= KIPM_ICUTotOdoLo_km) {
    /* MinMax: '<S73>/MinMax1' */
    VIPM_ICUTotOdo_km = VIPM_IPUOBCTempInt_C;
  } else {
    /* MinMax: '<S73>/MinMax1' */
    VIPM_ICUTotOdo_km = KIPM_ICUTotOdoLo_km;
  }

  /* End of MinMax: '<S73>/MinMax1' */
  /* End of Outputs for SubSystem: '<S71>/Subsys_VIPM_ICUTotOdo_km' */

  /* BusCreator: '<S71>/BusCreator' incorporates:
   *  Logic: '<S73>/Logical Operator3'
   *  MinMax: '<S73>/MinMax1'
   */
  AppSwcIpm_ARID_DEF.IPM_ICU_2_Odo_BAC.VIPM_ICUTotOdo_km = VIPM_ICUTotOdo_km;
  AppSwcIpm_ARID_DEF.IPM_ICU_2_Odo_BAC.VIPM_ICUTotOdoVld_flg =
    VIPM_ICUTotOdoVld_flg;

  /* Outputs for Atomic SubSystem: '<S72>/Subsys_VIPM_HUHybEcoModeSet_enum' */
  /* Logic: '<S89>/Logical Operator3' incorporates:
   *  Constant: '<S89>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUHybEcoModeSetVld_flg = (KIPM_HUHybEcoModeSet_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S89>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S89>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S89>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S89>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_o3 =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())
        ->HU_HybridEcoModeSet;
    }

    /* End of Switch: '<S89>/Switch3' */
  } else {
    /* Switch: '<S89>/Switch' incorporates:
     *  Constant: '<S89>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_o3 = KIPM_HUHybEcoModeSetDflt_enum;
  }

  /* End of Switch: '<S89>/Switch' */

  /* Switch: '<S89>/Switch4' incorporates:
   *  Constant: '<S89>/sat3'
   */
  if (KIPM_HUHybEcoModeSet_enum_ovrdflg) {
    /* Switch: '<S89>/Switch4' incorporates:
     *  Constant: '<S89>/sat4'
     */
    VIPM_HUHybEcoModeSet_enum = KIPM_HUHybEcoModeSet_enum_ovrdval;
  } else {
    /* Switch: '<S89>/Switch4' */
    VIPM_HUHybEcoModeSet_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_o3;
  }

  /* End of Switch: '<S89>/Switch4' */
  /* End of Outputs for SubSystem: '<S72>/Subsys_VIPM_HUHybEcoModeSet_enum' */

  /* Outputs for Atomic SubSystem: '<S72>/Subsys_VIPM_HULeftTempSet_enum' */
  /* Logic: '<S94>/Logical Operator3' incorporates:
   *  Constant: '<S94>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HULeftTempSetVld_flg = (KIPM_HULeftTempSet_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S94>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S94>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S94>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S94>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lz =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_LeftTempSet;
    }

    /* End of Switch: '<S94>/Switch3' */
  } else {
    /* Switch: '<S94>/Switch' incorporates:
     *  Constant: '<S94>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lz = KIPM_HULeftTempSetDflt_enum;
  }

  /* End of Switch: '<S94>/Switch' */

  /* Switch: '<S94>/Switch4' incorporates:
   *  Constant: '<S94>/sat3'
   */
  if (KIPM_HULeftTempSet_enum_ovrdflg) {
    /* Switch: '<S94>/Switch4' incorporates:
     *  Constant: '<S94>/sat4'
     */
    VIPM_HULeftTempSet_enum = KIPM_HULeftTempSet_enum_ovrdval;
  } else {
    /* Switch: '<S94>/Switch4' */
    VIPM_HULeftTempSet_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lz;
  }

  /* End of Switch: '<S94>/Switch4' */
  /* End of Outputs for SubSystem: '<S72>/Subsys_VIPM_HULeftTempSet_enum' */

  /* Outputs for Atomic SubSystem: '<S72>/Subsys_VIPM_HUACPwrCtl_enum' */
  /* Logic: '<S77>/Logical Operator3' incorporates:
   *  Constant: '<S77>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUACPwrCtlVld_flg = (KIPM_HUACPwrCtl_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S77>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S77>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S77>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S77>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_m2 =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_ACPowerCtl;
    }

    /* End of Switch: '<S77>/Switch3' */
  } else {
    /* Switch: '<S77>/Switch' incorporates:
     *  Constant: '<S77>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_m2 = KIPM_HUACPwrCtlDflt_enum;
  }

  /* End of Switch: '<S77>/Switch' */

  /* Switch: '<S77>/Switch4' incorporates:
   *  Constant: '<S77>/sat3'
   */
  if (KIPM_HUACPwrCtl_enum_ovrdflg) {
    /* Switch: '<S77>/Switch4' incorporates:
     *  Constant: '<S77>/sat4'
     */
    VIPM_HUACPwrCtl_enum = KIPM_HUACPwrCtl_enum_ovrdval;
  } else {
    /* Switch: '<S77>/Switch4' */
    VIPM_HUACPwrCtl_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_m2;
  }

  /* End of Switch: '<S77>/Switch4' */
  /* End of Outputs for SubSystem: '<S72>/Subsys_VIPM_HUACPwrCtl_enum' */

  /* Outputs for Atomic SubSystem: '<S72>/Subsys_VIPM_HUAirInletModeSet_enum' */
  /* Logic: '<S79>/Logical Operator3' incorporates:
   *  Constant: '<S79>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUAirInletModeSetVld_flg = (KIPM_HUAirInletModeSet_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S79>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S79>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S79>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S79>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jp =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_AirInletModeSet;
    }

    /* End of Switch: '<S79>/Switch3' */
  } else {
    /* Switch: '<S79>/Switch' incorporates:
     *  Constant: '<S79>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jp = KIPM_HUAirInletModeSetDflt_enum;
  }

  /* End of Switch: '<S79>/Switch' */

  /* Switch: '<S79>/Switch4' incorporates:
   *  Constant: '<S79>/sat3'
   */
  if (KIPM_HUAirInletModeSet_enum_ovrdflg) {
    /* Switch: '<S79>/Switch4' incorporates:
     *  Constant: '<S79>/sat4'
     */
    VIPM_HUAirInletModeSet_enum = KIPM_HUAirInletModeSet_enum_ovrdval;
  } else {
    /* Switch: '<S79>/Switch4' */
    VIPM_HUAirInletModeSet_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jp;
  }

  /* End of Switch: '<S79>/Switch4' */
  /* End of Outputs for SubSystem: '<S72>/Subsys_VIPM_HUAirInletModeSet_enum' */

  /* Outputs for Atomic SubSystem: '<S72>/Subsys_VIPM_HUFrntFanSpdSet_enum' */
  /* Logic: '<S88>/Logical Operator3' incorporates:
   *  Constant: '<S88>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUFrntFanSpdSetVld_flg = (KIPM_HUFrntFanSpdSet_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S88>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S88>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S88>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S88>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ap =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_FrontFanSpdSet;
    }

    /* End of Switch: '<S88>/Switch3' */
  } else {
    /* Switch: '<S88>/Switch' incorporates:
     *  Constant: '<S88>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ap = KIPM_HUFrntFanSpdSetDflt_enum;
  }

  /* End of Switch: '<S88>/Switch' */

  /* Switch: '<S88>/Switch4' incorporates:
   *  Constant: '<S88>/sat3'
   */
  if (KIPM_HUFrntFanSpdSet_enum_ovrdflg) {
    /* Switch: '<S88>/Switch4' incorporates:
     *  Constant: '<S88>/sat4'
     */
    VIPM_HUFrntFanSpdSet_enum = KIPM_HUFrntFanSpdSet_enum_ovrdval;
  } else {
    /* Switch: '<S88>/Switch4' */
    VIPM_HUFrntFanSpdSet_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ap;
  }

  /* End of Switch: '<S88>/Switch4' */
  /* End of Outputs for SubSystem: '<S72>/Subsys_VIPM_HUFrntFanSpdSet_enum' */

  /* Outputs for Atomic SubSystem: '<S72>/Subsys_VIPM_HUManlDefrstCtl_enum' */
  /* Logic: '<S96>/Logical Operator3' incorporates:
   *  Constant: '<S96>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUManlDefrstCtlVld_flg = (KIPM_HUManlDefrstCtl_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S96>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S96>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S96>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S96>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_kz =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())
        ->HU_ManualDefrostCtl;
    }

    /* End of Switch: '<S96>/Switch3' */
  } else {
    /* Switch: '<S96>/Switch' incorporates:
     *  Constant: '<S96>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_kz = KIPM_HUManlDefrstCtlDflt_enum;
  }

  /* End of Switch: '<S96>/Switch' */

  /* Switch: '<S96>/Switch4' incorporates:
   *  Constant: '<S96>/sat3'
   */
  if (KIPM_HUManlDefrstCtl_enum_ovrdflg) {
    /* Switch: '<S96>/Switch4' incorporates:
     *  Constant: '<S96>/sat4'
     */
    VIPM_HUManlDefrstCtl_enum = KIPM_HUManlDefrstCtl_enum_ovrdval;
  } else {
    /* Switch: '<S96>/Switch4' */
    VIPM_HUManlDefrstCtl_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_kz;
  }

  /* End of Switch: '<S96>/Switch4' */
  /* End of Outputs for SubSystem: '<S72>/Subsys_VIPM_HUManlDefrstCtl_enum' */

  /* Outputs for Atomic SubSystem: '<S72>/Subsys_VIPM_HUBlwrModeSet_enum' */
  /* Logic: '<S80>/Logical Operator3' incorporates:
   *  Constant: '<S80>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUBlwrModeSetVld_flg = (KIPM_HUBlwrModeSet_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S80>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S80>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S80>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S80>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_fe =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_BlowerModeSet;
    }

    /* End of Switch: '<S80>/Switch3' */
  } else {
    /* Switch: '<S80>/Switch' incorporates:
     *  Constant: '<S80>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_fe = KIPM_HUBlwrModeSetDflt_enum;
  }

  /* End of Switch: '<S80>/Switch' */

  /* Switch: '<S80>/Switch4' incorporates:
   *  Constant: '<S80>/sat3'
   */
  if (KIPM_HUBlwrModeSet_enum_ovrdflg) {
    /* Switch: '<S80>/Switch4' incorporates:
     *  Constant: '<S80>/sat4'
     */
    VIPM_HUBlwrModeSet_enum = KIPM_HUBlwrModeSet_enum_ovrdval;
  } else {
    /* Switch: '<S80>/Switch4' */
    VIPM_HUBlwrModeSet_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_fe;
  }

  /* End of Switch: '<S80>/Switch4' */
  /* End of Outputs for SubSystem: '<S72>/Subsys_VIPM_HUBlwrModeSet_enum' */

  /* Outputs for Atomic SubSystem: '<S72>/Subsys_VIPM_HUFlwrMeHmCtrl_enum' */
  /* Logic: '<S87>/Logical Operator3' incorporates:
   *  Constant: '<S87>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUFlwrMeHmCtrlVld_flg = (KIPM_HUFlwrMeHmCtrl_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S87>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S87>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S87>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S87>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hv =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_FlwrMeHmCtrl;
    }

    /* End of Switch: '<S87>/Switch3' */
  } else {
    /* Switch: '<S87>/Switch' incorporates:
     *  Constant: '<S87>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hv = KIPM_HUFlwrMeHmCtrlDflt_enum;
  }

  /* End of Switch: '<S87>/Switch' */

  /* Switch: '<S87>/Switch4' incorporates:
   *  Constant: '<S87>/sat3'
   */
  if (KIPM_HUFlwrMeHmCtrl_enum_ovrdflg) {
    /* Switch: '<S87>/Switch4' incorporates:
     *  Constant: '<S87>/sat4'
     */
    VIPM_HUFlwrMeHmCtrl_enum = KIPM_HUFlwrMeHmCtrl_enum_ovrdval;
  } else {
    /* Switch: '<S87>/Switch4' */
    VIPM_HUFlwrMeHmCtrl_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hv;
  }

  /* End of Switch: '<S87>/Switch4' */
  /* End of Outputs for SubSystem: '<S72>/Subsys_VIPM_HUFlwrMeHmCtrl_enum' */

  /* Outputs for Atomic SubSystem: '<S72>/Subsys_VIPM_HUIllmndEntrySts_enum' */
  /* Logic: '<S90>/Logical Operator3' incorporates:
   *  Constant: '<S90>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUIllmndEntryStsVld_flg = (KIPM_HUIllmndEntrySts_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S90>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S90>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S90>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S90>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ad =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_IllmndEntrySts;
    }

    /* End of Switch: '<S90>/Switch3' */
  } else {
    /* Switch: '<S90>/Switch' incorporates:
     *  Constant: '<S90>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ad = KIPM_HUIllmndEntryStsDflt_enum;
  }

  /* End of Switch: '<S90>/Switch' */

  /* Switch: '<S90>/Switch4' incorporates:
   *  Constant: '<S90>/sat3'
   */
  if (KIPM_HUIllmndEntrySts_enum_ovrdflg) {
    /* Switch: '<S90>/Switch4' incorporates:
     *  Constant: '<S90>/sat4'
     */
    VIPM_HUIllmndEntrySts_enum = KIPM_HUIllmndEntrySts_enum_ovrdval;
  } else {
    /* Switch: '<S90>/Switch4' */
    VIPM_HUIllmndEntrySts_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ad;
  }

  /* End of Switch: '<S90>/Switch4' */
  /* End of Outputs for SubSystem: '<S72>/Subsys_VIPM_HUIllmndEntrySts_enum' */

  /* Outputs for Atomic SubSystem: '<S72>/Subsys_VIPM_HULckHornOnSt_enum' */
  /* Logic: '<S93>/Logical Operator3' incorporates:
   *  Constant: '<S93>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HULckHornOnStVld_flg = (KIPM_HULckHornOnSt_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S93>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S93>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S93>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S93>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_fc =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_LockHornOnSt;
    }

    /* End of Switch: '<S93>/Switch3' */
  } else {
    /* Switch: '<S93>/Switch' incorporates:
     *  Constant: '<S93>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_fc = KIPM_HULckHornOnStDflt_enum;
  }

  /* End of Switch: '<S93>/Switch' */

  /* Switch: '<S93>/Switch4' incorporates:
   *  Constant: '<S93>/sat3'
   */
  if (KIPM_HULckHornOnSt_enum_ovrdflg) {
    /* Switch: '<S93>/Switch4' incorporates:
     *  Constant: '<S93>/sat4'
     */
    VIPM_HULckHornOnSt_enum = KIPM_HULckHornOnSt_enum_ovrdval;
  } else {
    /* Switch: '<S93>/Switch4' */
    VIPM_HULckHornOnSt_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_fc;
  }

  /* End of Switch: '<S93>/Switch4' */
  /* End of Outputs for SubSystem: '<S72>/Subsys_VIPM_HULckHornOnSt_enum' */

  /* Outputs for Atomic SubSystem: '<S72>/Subsys_VIPM_HUACAutoCtl_enum' */
  /* Logic: '<S76>/Logical Operator3' incorporates:
   *  Constant: '<S76>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUACAutoCtlVld_flg = (KIPM_HUACAutoCtl_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S76>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S76>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S76>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S76>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_px =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_ACAutoCtl;
    }

    /* End of Switch: '<S76>/Switch3' */
  } else {
    /* Switch: '<S76>/Switch' incorporates:
     *  Constant: '<S76>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_px = KIPM_HUACAutoCtlDflt_enum;
  }

  /* End of Switch: '<S76>/Switch' */

  /* Switch: '<S76>/Switch4' incorporates:
   *  Constant: '<S76>/sat3'
   */
  if (KIPM_HUACAutoCtl_enum_ovrdflg) {
    /* Switch: '<S76>/Switch4' incorporates:
     *  Constant: '<S76>/sat4'
     */
    VIPM_HUACAutoCtl_enum = KIPM_HUACAutoCtl_enum_ovrdval;
  } else {
    /* Switch: '<S76>/Switch4' */
    VIPM_HUACAutoCtl_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_px;
  }

  /* End of Switch: '<S76>/Switch4' */
  /* End of Outputs for SubSystem: '<S72>/Subsys_VIPM_HUACAutoCtl_enum' */

  /* Outputs for Atomic SubSystem: '<S72>/Subsys_VIPM_HUParkAutoUnlckSet_enum' */
  /* Logic: '<S98>/Logical Operator3' incorporates:
   *  Constant: '<S98>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUParkAutoUnlckSetVld_flg = (KIPM_HUParkAutoUnlckSet_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S98>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S98>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S98>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S98>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_fq =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())
        ->HU_ParkAutoUnlckSet;
    }

    /* End of Switch: '<S98>/Switch3' */
  } else {
    /* Switch: '<S98>/Switch' incorporates:
     *  Constant: '<S98>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_fq = KIPM_HUParkAutoUnlckSetDflt_enum;
  }

  /* End of Switch: '<S98>/Switch' */

  /* Switch: '<S98>/Switch4' incorporates:
   *  Constant: '<S98>/sat3'
   */
  if (KIPM_HUParkAutoUnlckSet_enum_ovrdflg) {
    /* Switch: '<S98>/Switch4' incorporates:
     *  Constant: '<S98>/sat4'
     */
    VIPM_HUParkAutoUnlckSet_enum = KIPM_HUParkAutoUnlckSet_enum_ovrdval;
  } else {
    /* Switch: '<S98>/Switch4' */
    VIPM_HUParkAutoUnlckSet_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_fq;
  }

  /* End of Switch: '<S98>/Switch4' */
  /* End of Outputs for SubSystem: '<S72>/Subsys_VIPM_HUParkAutoUnlckSet_enum' */

  /* Outputs for Atomic SubSystem: '<S72>/Subsys_VIPM_HUOvrspdCntrlLckSet_enum' */
  /* Logic: '<S97>/Logical Operator3' incorporates:
   *  Constant: '<S97>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUOvrspdCntrlLckSetVld_flg = (KIPM_HUOvrspdCntrlLckSet_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S97>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S97>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S97>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S97>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hig =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())
        ->HU_OverspdCntrlLockSet;
    }

    /* End of Switch: '<S97>/Switch3' */
  } else {
    /* Switch: '<S97>/Switch' incorporates:
     *  Constant: '<S97>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hig = KIPM_HUOvrspdCntrlLckSetDflt_enum;
  }

  /* End of Switch: '<S97>/Switch' */

  /* Switch: '<S97>/Switch4' incorporates:
   *  Constant: '<S97>/sat3'
   */
  if (KIPM_HUOvrspdCntrlLckSet_enum_ovrdflg) {
    /* Switch: '<S97>/Switch4' incorporates:
     *  Constant: '<S97>/sat4'
     */
    VIPM_HUOvrspdCntrlLckSet_enum = KIPM_HUOvrspdCntrlLckSet_enum_ovrdval;
  } else {
    /* Switch: '<S97>/Switch4' */
    VIPM_HUOvrspdCntrlLckSet_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hig;
  }

  /* End of Switch: '<S97>/Switch4' */
  /* End of Outputs for SubSystem: '<S72>/Subsys_VIPM_HUOvrspdCntrlLckSet_enum' */

  /* Outputs for Atomic SubSystem: '<S72>/Subsys_VIPM_HUTrnkLckSwCtrl_enum' */
  /* Logic: '<S105>/Logical Operator3' incorporates:
   *  Constant: '<S105>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUTrnkLckSwCtrlVld_flg = (KIPM_HUTrnkLckSwCtrl_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S105>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S105>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S105>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S105>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_a5 =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_TrunkLockSwCtrl;
    }

    /* End of Switch: '<S105>/Switch3' */
  } else {
    /* Switch: '<S105>/Switch' incorporates:
     *  Constant: '<S105>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_a5 = KIPM_HUTrnkLckSwCtrlDflt_enum;
  }

  /* End of Switch: '<S105>/Switch' */

  /* Switch: '<S105>/Switch4' incorporates:
   *  Constant: '<S105>/sat3'
   */
  if (KIPM_HUTrnkLckSwCtrl_enum_ovrdflg) {
    /* Switch: '<S105>/Switch4' incorporates:
     *  Constant: '<S105>/sat4'
     */
    VIPM_HUTrnkLckSwCtrl_enum = KIPM_HUTrnkLckSwCtrl_enum_ovrdval;
  } else {
    /* Switch: '<S105>/Switch4' */
    VIPM_HUTrnkLckSwCtrl_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_a5;
  }

  /* End of Switch: '<S105>/Switch4' */
  /* End of Outputs for SubSystem: '<S72>/Subsys_VIPM_HUTrnkLckSwCtrl_enum' */

  /* Outputs for Atomic SubSystem: '<S72>/Subsys_VIPM_HUChgWiprMtMdSwSet_enum' */
  /* Logic: '<S81>/Logical Operator3' incorporates:
   *  Constant: '<S81>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUChgWiprMtMdSwSetVld_flg = (KIPM_HUChgWiprMtMdSwSet_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S81>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S81>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S81>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S81>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_gw =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())
        ->HU_ChgWiperMtMdSwSet;
    }

    /* End of Switch: '<S81>/Switch3' */
  } else {
    /* Switch: '<S81>/Switch' incorporates:
     *  Constant: '<S81>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_gw = KIPM_HUChgWiprMtMdSwSetDflt_enum;
  }

  /* End of Switch: '<S81>/Switch' */

  /* Switch: '<S81>/Switch4' incorporates:
   *  Constant: '<S81>/sat3'
   */
  if (KIPM_HUChgWiprMtMdSwSet_enum_ovrdflg) {
    /* Switch: '<S81>/Switch4' incorporates:
     *  Constant: '<S81>/sat4'
     */
    VIPM_HUChgWiprMtMdSwSet_enum = KIPM_HUChgWiprMtMdSwSet_enum_ovrdval;
  } else {
    /* Switch: '<S81>/Switch4' */
    VIPM_HUChgWiprMtMdSwSet_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_gw;
  }

  /* End of Switch: '<S81>/Switch4' */
  /* End of Outputs for SubSystem: '<S72>/Subsys_VIPM_HUChgWiprMtMdSwSet_enum' */

  /* Outputs for Atomic SubSystem: '<S72>/Subsys_VIPM_HUTPMSRstReq_flg' */
  /* Logic: '<S104>/Logical Operator3' incorporates:
   *  Constant: '<S104>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUTPMSRstReqVld_flg = (KIPM_HUTPMSRstReq_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S104>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S104>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S104>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S104>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_aq =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_TPMSResetReq;
    }

    /* End of Switch: '<S104>/Switch3' */
  } else {
    /* Switch: '<S104>/Switch' incorporates:
     *  Constant: '<S104>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_aq = KIPM_HUTPMSRstReqDflt_flg;
  }

  /* End of Switch: '<S104>/Switch' */

  /* Switch: '<S104>/Switch4' incorporates:
   *  Constant: '<S104>/sat3'
   */
  if (KIPM_HUTPMSRstReq_flg_ovrdflg) {
    /* Switch: '<S104>/Switch4' incorporates:
     *  Constant: '<S104>/sat4'
     */
    VIPM_HUTPMSRstReq_flg = KIPM_HUTPMSRstReq_flg_ovrdval;
  } else {
    /* Switch: '<S104>/Switch4' */
    VIPM_HUTPMSRstReq_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_aq;
  }

  /* End of Switch: '<S104>/Switch4' */
  /* End of Outputs for SubSystem: '<S72>/Subsys_VIPM_HUTPMSRstReq_flg' */

  /* Outputs for Atomic SubSystem: '<S72>/Subsys_VIPM_HUMaiDrvrSeatHeat_enum' */
  /* Logic: '<S95>/Logical Operator3' incorporates:
   *  Constant: '<S95>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUMaiDrvrSeatHeatVld_flg = (KIPM_HUMaiDrvrSeatHeat_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S95>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S95>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S95>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S95>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_h0 =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_MaiDrvrSeatHeat;
    }

    /* End of Switch: '<S95>/Switch3' */
  } else {
    /* Switch: '<S95>/Switch' incorporates:
     *  Constant: '<S95>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_h0 = KIPM_HUMaiDrvrSeatHeatDflt_enum;
  }

  /* End of Switch: '<S95>/Switch' */

  /* Switch: '<S95>/Switch4' incorporates:
   *  Constant: '<S95>/sat3'
   */
  if (KIPM_HUMaiDrvrSeatHeat_enum_ovrdflg) {
    /* Switch: '<S95>/Switch4' incorporates:
     *  Constant: '<S95>/sat4'
     */
    VIPM_HUMaiDrvrSeatHeat_enum = KIPM_HUMaiDrvrSeatHeat_enum_ovrdval;
  } else {
    /* Switch: '<S95>/Switch4' */
    VIPM_HUMaiDrvrSeatHeat_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_h0;
  }

  /* End of Switch: '<S95>/Switch4' */
  /* End of Outputs for SubSystem: '<S72>/Subsys_VIPM_HUMaiDrvrSeatHeat_enum' */

  /* Outputs for Atomic SubSystem: '<S72>/Subsys_VIPM_HUPwrOffReq_flg' */
  /* Logic: '<S100>/Logical Operator3' incorporates:
   *  Constant: '<S100>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUPwrOffReqVld_flg = (KIPM_HUPwrOffReq_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S100>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S100>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S100>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S100>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_m2g =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_PwrOFFReq;
    }

    /* End of Switch: '<S100>/Switch3' */
  } else {
    /* Switch: '<S100>/Switch' incorporates:
     *  Constant: '<S100>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_m2g = KIPM_HUPwrOffReqDflt_flg;
  }

  /* End of Switch: '<S100>/Switch' */

  /* Switch: '<S100>/Switch4' incorporates:
   *  Constant: '<S100>/sat3'
   */
  if (KIPM_HUPwrOffReq_flg_ovrdflg) {
    /* Switch: '<S100>/Switch4' incorporates:
     *  Constant: '<S100>/sat4'
     */
    VIPM_HUPwrOffReq_flg = KIPM_HUPwrOffReq_flg_ovrdval;
  } else {
    /* Switch: '<S100>/Switch4' */
    VIPM_HUPwrOffReq_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_m2g;
  }

  /* End of Switch: '<S100>/Switch4' */
  /* End of Outputs for SubSystem: '<S72>/Subsys_VIPM_HUPwrOffReq_flg' */

  /* Outputs for Atomic SubSystem: '<S72>/Subsys_VIPM_HUWiprIntlTmSet_enum' */
  /* Logic: '<S107>/Logical Operator3' incorporates:
   *  Constant: '<S107>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUWiprIntlTmSetVld_flg = (KIPM_HUWiprIntlTmSet_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S107>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S107>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S107>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_a1 =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_WiprIntlTimeSet;
    }

    /* End of Switch: '<S107>/Switch3' */
  } else {
    /* Switch: '<S107>/Switch' incorporates:
     *  Constant: '<S107>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_a1 = KIPM_HUWiprIntlTmSetDflt_enum;
  }

  /* End of Switch: '<S107>/Switch' */

  /* Switch: '<S107>/Switch4' incorporates:
   *  Constant: '<S107>/sat3'
   */
  if (KIPM_HUWiprIntlTmSet_enum_ovrdflg) {
    /* Switch: '<S107>/Switch4' incorporates:
     *  Constant: '<S107>/sat4'
     */
    VIPM_HUWiprIntlTmSet_enum = KIPM_HUWiprIntlTmSet_enum_ovrdval;
  } else {
    /* Switch: '<S107>/Switch4' */
    VIPM_HUWiprIntlTmSet_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_a1;
  }

  /* End of Switch: '<S107>/Switch4' */
  /* End of Outputs for SubSystem: '<S72>/Subsys_VIPM_HUWiprIntlTmSet_enum' */

  /* Outputs for Atomic SubSystem: '<S72>/Subsys_VIPM_CDCBackLadjval_enum' */
  /* Logic: '<S75>/Logical Operator3' incorporates:
   *  Constant: '<S75>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CDCBackLadjvalVld_flg = (KIPM_CDCBackLadjval_enum_ovrdflg ||
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
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_af =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->CDC_BackLadjval;
    }

    /* End of Switch: '<S75>/Switch3' */
  } else {
    /* Switch: '<S75>/Switch' incorporates:
     *  Constant: '<S75>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_af = KIPM_CDCBackLadjvalDflt_enum;
  }

  /* End of Switch: '<S75>/Switch' */

  /* Switch: '<S75>/Switch4' incorporates:
   *  Constant: '<S75>/sat3'
   */
  if (KIPM_CDCBackLadjval_enum_ovrdflg) {
    /* Switch: '<S75>/Switch4' incorporates:
     *  Constant: '<S75>/sat4'
     */
    VIPM_CDCBackLadjval_enum = KIPM_CDCBackLadjval_enum_ovrdval;
  } else {
    /* Switch: '<S75>/Switch4' */
    VIPM_CDCBackLadjval_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_af;
  }

  /* End of Switch: '<S75>/Switch4' */
  /* End of Outputs for SubSystem: '<S72>/Subsys_VIPM_CDCBackLadjval_enum' */

  /* Outputs for Atomic SubSystem: '<S72>/Subsys_VIPM_HURrMirrHeat_enum' */
  /* Logic: '<S102>/Logical Operator3' incorporates:
   *  Constant: '<S102>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HURrMirrHeatVld_flg = (KIPM_HURrMirrHeat_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S102>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S102>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S102>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S102>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_fiu =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_RearMirrorHeat;
    }

    /* End of Switch: '<S102>/Switch3' */
  } else {
    /* Switch: '<S102>/Switch' incorporates:
     *  Constant: '<S102>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_fiu = KIPM_HURrMirrHeatDflt_enum;
  }

  /* End of Switch: '<S102>/Switch' */

  /* Switch: '<S102>/Switch4' incorporates:
   *  Constant: '<S102>/sat3'
   */
  if (KIPM_HURrMirrHeat_enum_ovrdflg) {
    /* Switch: '<S102>/Switch4' incorporates:
     *  Constant: '<S102>/sat4'
     */
    VIPM_HURrMirrHeat_enum = KIPM_HURrMirrHeat_enum_ovrdval;
  } else {
    /* Switch: '<S102>/Switch4' */
    VIPM_HURrMirrHeat_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_fiu;
  }

  /* End of Switch: '<S102>/Switch4' */
  /* End of Outputs for SubSystem: '<S72>/Subsys_VIPM_HURrMirrHeat_enum' */

  /* Outputs for Atomic SubSystem: '<S72>/Subsys_VIPM_HUSteerWhlHeat_enum' */
  /* Logic: '<S103>/Logical Operator3' incorporates:
   *  Constant: '<S103>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUSteerWhlHeatVld_flg = (KIPM_HUSteerWhlHeat_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S103>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S103>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S103>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S103>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_mj =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_SteerWhlHeat;
    }

    /* End of Switch: '<S103>/Switch3' */
  } else {
    /* Switch: '<S103>/Switch' incorporates:
     *  Constant: '<S103>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_mj = KIPM_HUSteerWhlHeatDflt_enum;
  }

  /* End of Switch: '<S103>/Switch' */

  /* Switch: '<S103>/Switch4' incorporates:
   *  Constant: '<S103>/sat3'
   */
  if (KIPM_HUSteerWhlHeat_enum_ovrdflg) {
    /* Switch: '<S103>/Switch4' incorporates:
     *  Constant: '<S103>/sat4'
     */
    VIPM_HUSteerWhlHeat_enum = KIPM_HUSteerWhlHeat_enum_ovrdval;
  } else {
    /* Switch: '<S103>/Switch4' */
    VIPM_HUSteerWhlHeat_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_mj;
  }

  /* End of Switch: '<S103>/Switch4' */
  /* End of Outputs for SubSystem: '<S72>/Subsys_VIPM_HUSteerWhlHeat_enum' */

  /* Outputs for Atomic SubSystem: '<S72>/Subsys_VIPM_HUCstRecupModeSel_enum' */
  /* Logic: '<S84>/Logical Operator3' incorporates:
   *  Constant: '<S84>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUCstRecupModeSelVld_flg = (KIPM_HUCstRecupModeSel_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S84>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S84>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S84>/Switch' incorporates:
       *  DataTypeConversion: '<S84>/Data Type Conversion2'
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S84>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ca =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())
        ->HU_CoastRecupModeSelect;
    }

    /* End of Switch: '<S84>/Switch3' */
  } else {
    /* Switch: '<S84>/Switch' incorporates:
     *  Constant: '<S84>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ca = KIPM_HUCstRecupModeSelDflt_enum;
  }

  /* End of Switch: '<S84>/Switch' */

  /* Switch: '<S84>/Switch4' incorporates:
   *  Constant: '<S84>/sat3'
   */
  if (KIPM_HUCstRecupModeSel_enum_ovrdflg) {
    /* Switch: '<S84>/Switch4' incorporates:
     *  Constant: '<S84>/sat4'
     */
    VIPM_HUCstRecupModeSel_enum = KIPM_HUCstRecupModeSel_enum_ovrdval;
  } else {
    /* Switch: '<S84>/Switch4' incorporates:
     *  Switch: '<S84>/Switch'
     */
    VIPM_HUCstRecupModeSel_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ca;
  }

  /* End of Switch: '<S84>/Switch4' */
  /* End of Outputs for SubSystem: '<S72>/Subsys_VIPM_HUCstRecupModeSel_enum' */

  /* Outputs for Atomic SubSystem: '<S72>/Subsys_VIPM_HUPeristalsisModeEnbl_enum' */
  /* Logic: '<S99>/Logical Operator3' incorporates:
   *  Constant: '<S99>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUPeristalsisModeEnblVld_flg = (KIPM_HUPeristalsisModeEnbl_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S99>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S99>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S99>/Switch' incorporates:
       *  DataTypeConversion: '<S99>/Data Type Conversion2'
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S99>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_dt =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())
        ->HU_PeristalsisModeEnb;
    }

    /* End of Switch: '<S99>/Switch3' */
  } else {
    /* Switch: '<S99>/Switch' incorporates:
     *  Constant: '<S99>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_dt = KIPM_HUPeristalsisModeEnblDflt_enum;
  }

  /* End of Switch: '<S99>/Switch' */

  /* Switch: '<S99>/Switch4' incorporates:
   *  Constant: '<S99>/sat3'
   */
  if (KIPM_HUPeristalsisModeEnbl_enum_ovrdflg) {
    /* Switch: '<S99>/Switch4' incorporates:
     *  Constant: '<S99>/sat4'
     */
    VIPM_HUPeristalsisModeEnbl_enum = KIPM_HUPeristalsisModeEnbl_enum_ovrdval;
  } else {
    /* Switch: '<S99>/Switch4' incorporates:
     *  Switch: '<S99>/Switch'
     */
    VIPM_HUPeristalsisModeEnbl_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_dt;
  }

  /* End of Switch: '<S99>/Switch4' */
  /* End of Outputs for SubSystem: '<S72>/Subsys_VIPM_HUPeristalsisModeEnbl_enum' */

  /* Outputs for Atomic SubSystem: '<S72>/Subsys_VIPM_HUIllmndUnlckSts_enum' */
  /* Logic: '<S92>/Logical Operator3' incorporates:
   *  Constant: '<S92>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUIllmndUnlckStsVld_flg = (KIPM_HUIllmndUnlckSts_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S92>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S92>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S92>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S92>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nfb =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_IllmndUnlockSts;
    }

    /* End of Switch: '<S92>/Switch3' */
  } else {
    /* Switch: '<S92>/Switch' incorporates:
     *  Constant: '<S92>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nfb = KIPM_HUIllmndUnlckStsDflt_enum;
  }

  /* End of Switch: '<S92>/Switch' */

  /* Switch: '<S92>/Switch4' incorporates:
   *  Constant: '<S92>/sat3'
   */
  if (KIPM_HUIllmndUnlckSts_enum_ovrdflg) {
    /* Switch: '<S92>/Switch4' incorporates:
     *  Constant: '<S92>/sat4'
     */
    VIPM_HUIllmndUnlckSts_enum = KIPM_HUIllmndUnlckSts_enum_ovrdval;
  } else {
    /* Switch: '<S92>/Switch4' */
    VIPM_HUIllmndUnlckSts_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nfb;
  }

  /* End of Switch: '<S92>/Switch4' */
  /* End of Outputs for SubSystem: '<S72>/Subsys_VIPM_HUIllmndUnlckSts_enum' */

  /* Outputs for Atomic SubSystem: '<S72>/Subsys_VIPM_HUIllmndLckSts_enum' */
  /* Logic: '<S91>/Logical Operator3' incorporates:
   *  Constant: '<S91>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUIllmndLckStsVld_flg = (KIPM_HUIllmndLckSts_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S91>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S91>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S91>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S91>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jks =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_IllmndLockSts;
    }

    /* End of Switch: '<S91>/Switch3' */
  } else {
    /* Switch: '<S91>/Switch' incorporates:
     *  Constant: '<S91>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jks = KIPM_HUIllmndLckStsDflt_enum;
  }

  /* End of Switch: '<S91>/Switch' */

  /* Switch: '<S91>/Switch4' incorporates:
   *  Constant: '<S91>/sat3'
   */
  if (KIPM_HUIllmndLckSts_enum_ovrdflg) {
    /* Switch: '<S91>/Switch4' incorporates:
     *  Constant: '<S91>/sat4'
     */
    VIPM_HUIllmndLckSts_enum = KIPM_HUIllmndLckSts_enum_ovrdval;
  } else {
    /* Switch: '<S91>/Switch4' */
    VIPM_HUIllmndLckSts_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jks;
  }

  /* End of Switch: '<S91>/Switch4' */
  /* End of Outputs for SubSystem: '<S72>/Subsys_VIPM_HUIllmndLckSts_enum' */

  /* Outputs for Atomic SubSystem: '<S72>/Subsys_VIPM_HUDrvModeSel_enum' */
  /* Logic: '<S85>/Logical Operator3' incorporates:
   *  Constant: '<S85>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUDrvModeSelVld_flg = (KIPM_HUDrvModeSel_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S85>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S85>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S85>/Switch' incorporates:
       *  DataTypeConversion: '<S85>/Data Type Conversion2'
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S85>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_k0 =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())
        ->HU_DrivingModeSelect;
    }

    /* End of Switch: '<S85>/Switch3' */
  } else {
    /* Switch: '<S85>/Switch' incorporates:
     *  Constant: '<S85>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_k0 = KIPM_HUDrvModeSelDflt_enum;
  }

  /* End of Switch: '<S85>/Switch' */

  /* Switch: '<S85>/Switch4' incorporates:
   *  Constant: '<S85>/sat3'
   */
  if (KIPM_HUDrvModeSel_enum_ovrdflg) {
    /* Switch: '<S85>/Switch4' incorporates:
     *  Constant: '<S85>/sat4'
     */
    VIPM_HUDrvModeSel_enum = KIPM_HUDrvModeSel_enum_ovrdval;
  } else {
    /* Switch: '<S85>/Switch4' incorporates:
     *  Switch: '<S85>/Switch'
     */
    VIPM_HUDrvModeSel_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_k0;
  }

  /* End of Switch: '<S85>/Switch4' */
  /* End of Outputs for SubSystem: '<S72>/Subsys_VIPM_HUDrvModeSel_enum' */

  /* Outputs for Atomic SubSystem: '<S72>/Subsys_VIPM_HURecupPwrSet_pct' */
  /* Logic: '<S101>/Logical Operator3' incorporates:
   *  Constant: '<S101>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HURecupPwrSetVld_flg = (KIPM_HURecupPwrSet_pct_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S101>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S101>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S101>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S101>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_dk =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())
        ->HU_RecuperatePowerSet;
    }

    /* End of Switch: '<S101>/Switch3' */
  } else {
    /* Switch: '<S101>/Switch' incorporates:
     *  Constant: '<S101>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_dk = KIPM_HURecupPwrSetDflt_pct;
  }

  /* End of Switch: '<S101>/Switch' */

  /* Switch: '<S101>/Switch4' incorporates:
   *  Constant: '<S101>/sat3'
   */
  if (KIPM_HURecupPwrSet_pct_ovrdflg) {
    /* Switch: '<S101>/Switch4' incorporates:
     *  Constant: '<S101>/sat4'
     */
    VIPM_HURecupPwrSet_pct = KIPM_HURecupPwrSet_pct_ovrdval;
  } else {
    /* Switch: '<S101>/Switch4' */
    VIPM_HURecupPwrSet_pct = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_dk;
  }

  /* End of Switch: '<S101>/Switch4' */
  /* End of Outputs for SubSystem: '<S72>/Subsys_VIPM_HURecupPwrSet_pct' */

  /* Outputs for Atomic SubSystem: '<S72>/Subsys_VIPM_HUDrvPwrSet_cnt' */
  /* Logic: '<S86>/Logical Operator3' incorporates:
   *  Constant: '<S86>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUDrvPwrSetVld_flg = (KIPM_HUDrvPwrSet_cnt_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S86>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S86>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S86>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S86>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_bg =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_DrivingPowerSet;
    }

    /* End of Switch: '<S86>/Switch3' */
  } else {
    /* Switch: '<S86>/Switch' incorporates:
     *  Constant: '<S86>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_bg = KIPM_HUDrvPwrSetDflt_cnt;
  }

  /* End of Switch: '<S86>/Switch' */

  /* Switch: '<S86>/Switch4' incorporates:
   *  Constant: '<S86>/sat3'
   */
  if (KIPM_HUDrvPwrSet_cnt_ovrdflg) {
    /* Switch: '<S86>/Switch4' incorporates:
     *  Constant: '<S86>/sat4'
     */
    VIPM_HUDrvPwrSet_cnt = KIPM_HUDrvPwrSet_cnt_ovrdval;
  } else {
    /* Switch: '<S86>/Switch4' */
    VIPM_HUDrvPwrSet_cnt = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_bg;
  }

  /* End of Switch: '<S86>/Switch4' */
  /* End of Outputs for SubSystem: '<S72>/Subsys_VIPM_HUDrvPwrSet_cnt' */

  /* Outputs for Atomic SubSystem: '<S72>/Subsys_VIPM_HUChrgngmode_enum' */
  /* Logic: '<S83>/Logical Operator3' incorporates:
   *  Constant: '<S83>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUChrgngmodeVld_flg = (KIPM_HUChrgngmode_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S83>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S83>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S83>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S83>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_mv =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_Chargingmode;
    }

    /* End of Switch: '<S83>/Switch3' */
  } else {
    /* Switch: '<S83>/Switch' incorporates:
     *  Constant: '<S83>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_mv = KIPM_HUChrgngmodeDflt_enum;
  }

  /* End of Switch: '<S83>/Switch' */

  /* Switch: '<S83>/Switch4' incorporates:
   *  Constant: '<S83>/sat3'
   */
  if (KIPM_HUChrgngmode_enum_ovrdflg) {
    /* Switch: '<S83>/Switch4' incorporates:
     *  Constant: '<S83>/sat4'
     */
    VIPM_HUChrgngmode_enum = KIPM_HUChrgngmode_enum_ovrdval;
  } else {
    /* Switch: '<S83>/Switch4' */
    VIPM_HUChrgngmode_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_mv;
  }

  /* End of Switch: '<S83>/Switch4' */
  /* End of Outputs for SubSystem: '<S72>/Subsys_VIPM_HUChrgngmode_enum' */

  /* Outputs for Atomic SubSystem: '<S72>/Subsys_VIPM_HUChrgngReq_enum' */
  /* Logic: '<S82>/Logical Operator3' incorporates:
   *  Constant: '<S82>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUChrgngReqVld_flg = (KIPM_HUChrgngReq_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S82>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S82>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S82>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S82>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cd =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_ChargingRequest;
    }

    /* End of Switch: '<S82>/Switch3' */
  } else {
    /* Switch: '<S82>/Switch' incorporates:
     *  Constant: '<S82>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cd = KIPM_HUChrgngReqDflt_enum;
  }

  /* End of Switch: '<S82>/Switch' */

  /* Switch: '<S82>/Switch4' incorporates:
   *  Constant: '<S82>/sat3'
   */
  if (KIPM_HUChrgngReq_enum_ovrdflg) {
    /* Switch: '<S82>/Switch4' incorporates:
     *  Constant: '<S82>/sat4'
     */
    VIPM_HUChrgngReq_enum = KIPM_HUChrgngReq_enum_ovrdval;
  } else {
    /* Switch: '<S82>/Switch4' */
    VIPM_HUChrgngReq_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cd;
  }

  /* End of Switch: '<S82>/Switch4' */
  /* End of Outputs for SubSystem: '<S72>/Subsys_VIPM_HUChrgngReq_enum' */

  /* Outputs for Atomic SubSystem: '<S72>/Subsys_VIPM_HUVehMaxCurr_A' */
  /* Logic: '<S106>/Logical Operator3' incorporates:
   *  Constant: '<S106>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUVehMaxCurrVld_flg = (KIPM_HUVehMaxCurr_A_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S106>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S106>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S106>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S106>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ks =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_VehMaxCurrent;
    }

    /* End of Switch: '<S106>/Switch3' */
  } else {
    /* Switch: '<S106>/Switch' incorporates:
     *  Constant: '<S106>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ks = KIPM_HUVehMaxCurrDflt_A;
  }

  /* End of Switch: '<S106>/Switch' */

  /* Switch: '<S106>/Switch4' incorporates:
   *  Constant: '<S106>/sat3'
   */
  if (KIPM_HUVehMaxCurr_A_ovrdflg) {
    /* Switch: '<S106>/Switch4' incorporates:
     *  Constant: '<S106>/sat4'
     */
    VIPM_HUVehMaxCurr_A = KIPM_HUVehMaxCurr_A_ovrdval;
  } else {
    /* Switch: '<S106>/Switch4' */
    VIPM_HUVehMaxCurr_A = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ks;
  }

  /* End of Switch: '<S106>/Switch4' */
  /* End of Outputs for SubSystem: '<S72>/Subsys_VIPM_HUVehMaxCurr_A' */

  /* Outputs for Atomic SubSystem: '<S72>/Subsys_VIPM_HUACUnlckVentSet_enum' */
  /* Logic: '<S78>/Logical Operator3' incorporates:
   *  Constant: '<S78>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUACUnlckVentSetVld_flg = (KIPM_HUACUnlckVentSet_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S78>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S78>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S78>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S78>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jv =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_ACUnlockVentSet;
    }

    /* End of Switch: '<S78>/Switch3' */
  } else {
    /* Switch: '<S78>/Switch' incorporates:
     *  Constant: '<S78>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jv = KIPM_HUACUnlckVentSetDflt_enum;
  }

  /* End of Switch: '<S78>/Switch' */

  /* Switch: '<S78>/Switch4' incorporates:
   *  Constant: '<S78>/sat3'
   */
  if (KIPM_HUACUnlckVentSet_enum_ovrdflg) {
    /* Switch: '<S78>/Switch4' incorporates:
     *  Constant: '<S78>/sat4'
     */
    VIPM_HUACUnlckVentSet_enum = KIPM_HUACUnlckVentSet_enum_ovrdval;
  } else {
    /* Switch: '<S78>/Switch4' */
    VIPM_HUACUnlckVentSet_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jv;
  }

  /* End of Switch: '<S78>/Switch4' */
  /* End of Outputs for SubSystem: '<S72>/Subsys_VIPM_HUACUnlckVentSet_enum' */

  /* Outputs for Atomic SubSystem: '<S72>/Subsys_VIPM_TBoxRmtCarSearch_enum' */
  /* Logic: '<S116>/Logical Operator3' incorporates:
   *  Constant: '<S116>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_TBoxRmtCarSearchVld_flg = (KIPM_TBoxRmtCarSearch_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S116>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S116>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S116>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S116>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_c3 =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())
        ->TBox_RemoteCarSearch;
    }

    /* End of Switch: '<S116>/Switch3' */
  } else {
    /* Switch: '<S116>/Switch' incorporates:
     *  Constant: '<S116>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_c3 = KIPM_TBoxRmtCarSearchDflt_enum;
  }

  /* End of Switch: '<S116>/Switch' */

  /* Switch: '<S116>/Switch4' incorporates:
   *  Constant: '<S116>/sat3'
   */
  if (KIPM_TBoxRmtCarSearch_enum_ovrdflg) {
    /* Switch: '<S116>/Switch4' incorporates:
     *  Constant: '<S116>/sat4'
     */
    VIPM_TBoxRmtCarSearch_enum = KIPM_TBoxRmtCarSearch_enum_ovrdval;
  } else {
    /* Switch: '<S116>/Switch4' */
    VIPM_TBoxRmtCarSearch_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_c3;
  }

  /* End of Switch: '<S116>/Switch4' */
  /* End of Outputs for SubSystem: '<S72>/Subsys_VIPM_TBoxRmtCarSearch_enum' */

  /* Outputs for Atomic SubSystem: '<S72>/Subsys_VIPM_TBoxOpenVentn_enum' */
  /* Logic: '<S115>/Logical Operator3' incorporates:
   *  Constant: '<S115>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_TBoxOpenVentnVld_flg = (KIPM_TBoxOpenVentn_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S115>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S115>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S115>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S115>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ps =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())
        ->TBox_OpenVentilation;
    }

    /* End of Switch: '<S115>/Switch3' */
  } else {
    /* Switch: '<S115>/Switch' incorporates:
     *  Constant: '<S115>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ps = KIPM_TBoxOpenVentnDflt_enum;
  }

  /* End of Switch: '<S115>/Switch' */

  /* Switch: '<S115>/Switch4' incorporates:
   *  Constant: '<S115>/sat3'
   */
  if (KIPM_TBoxOpenVentn_enum_ovrdflg) {
    /* Switch: '<S115>/Switch4' incorporates:
     *  Constant: '<S115>/sat4'
     */
    VIPM_TBoxOpenVentn_enum = KIPM_TBoxOpenVentn_enum_ovrdval;
  } else {
    /* Switch: '<S115>/Switch4' */
    VIPM_TBoxOpenVentn_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ps;
  }

  /* End of Switch: '<S115>/Switch4' */
  /* End of Outputs for SubSystem: '<S72>/Subsys_VIPM_TBoxOpenVentn_enum' */

  /* Outputs for Atomic SubSystem: '<S72>/Subsys_VIPM_TBOXACRemtCtrlFlg_enum' */
  /* Logic: '<S108>/Logical Operator3' incorporates:
   *  Constant: '<S108>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_TBOXACRemtCtrlFlgVld_flg = (KIPM_TBOXACRemtCtrlFlg_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S108>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S108>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S108>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S108>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_np =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())
        ->TBOX_AC_RemtCtrlFlag;
    }

    /* End of Switch: '<S108>/Switch3' */
  } else {
    /* Switch: '<S108>/Switch' incorporates:
     *  Constant: '<S108>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_np = KIPM_TBOXACRemtCtrlFlgDflt_enum;
  }

  /* End of Switch: '<S108>/Switch' */

  /* Switch: '<S108>/Switch4' incorporates:
   *  Constant: '<S108>/sat3'
   */
  if (KIPM_TBOXACRemtCtrlFlg_enum_ovrdflg) {
    /* Switch: '<S108>/Switch4' incorporates:
     *  Constant: '<S108>/sat4'
     */
    VIPM_TBOXACRemtCtrlFlg_enum = KIPM_TBOXACRemtCtrlFlg_enum_ovrdval;
  } else {
    /* Switch: '<S108>/Switch4' */
    VIPM_TBOXACRemtCtrlFlg_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_np;
  }

  /* End of Switch: '<S108>/Switch4' */
  /* End of Outputs for SubSystem: '<S72>/Subsys_VIPM_TBOXACRemtCtrlFlg_enum' */

  /* Outputs for Atomic SubSystem: '<S72>/Subsys_VIPM_TBOXACTempSet_enum' */
  /* Logic: '<S109>/Logical Operator3' incorporates:
   *  Constant: '<S109>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_TBOXACTempSetVld_flg = (KIPM_TBOXACTempSet_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S109>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S109>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S109>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S109>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nuf =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->TBOX_AC_TempSet;
    }

    /* End of Switch: '<S109>/Switch3' */
  } else {
    /* Switch: '<S109>/Switch' incorporates:
     *  Constant: '<S109>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nuf = KIPM_TBOXACTempSetDflt_enum;
  }

  /* End of Switch: '<S109>/Switch' */

  /* Switch: '<S109>/Switch4' incorporates:
   *  Constant: '<S109>/sat3'
   */
  if (KIPM_TBOXACTempSet_enum_ovrdflg) {
    /* Switch: '<S109>/Switch4' incorporates:
     *  Constant: '<S109>/sat4'
     */
    VIPM_TBOXACTempSet_enum = KIPM_TBOXACTempSet_enum_ovrdval;
  } else {
    /* Switch: '<S109>/Switch4' */
    VIPM_TBOXACTempSet_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nuf;
  }

  /* End of Switch: '<S109>/Switch4' */
  /* End of Outputs for SubSystem: '<S72>/Subsys_VIPM_TBOXACTempSet_enum' */

  /* Outputs for Atomic SubSystem: '<S72>/Subsys_VIPM_TboxRmtDefrstCtl_enum' */
  /* Logic: '<S118>/Logical Operator3' incorporates:
   *  Constant: '<S118>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_TboxRmtDefrstCtlVld_flg = (KIPM_TboxRmtDefrstCtl_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S118>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S118>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S118>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S118>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_mn =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())
        ->Tbox_RemoteDefrostCtl;
    }

    /* End of Switch: '<S118>/Switch3' */
  } else {
    /* Switch: '<S118>/Switch' incorporates:
     *  Constant: '<S118>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_mn = KIPM_TboxRmtDefrstCtlDflt_enum;
  }

  /* End of Switch: '<S118>/Switch' */

  /* Switch: '<S118>/Switch4' incorporates:
   *  Constant: '<S118>/sat3'
   */
  if (KIPM_TboxRmtDefrstCtl_enum_ovrdflg) {
    /* Switch: '<S118>/Switch4' incorporates:
     *  Constant: '<S118>/sat4'
     */
    VIPM_TboxRmtDefrstCtl_enum = KIPM_TboxRmtDefrstCtl_enum_ovrdval;
  } else {
    /* Switch: '<S118>/Switch4' */
    VIPM_TboxRmtDefrstCtl_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_mn;
  }

  /* End of Switch: '<S118>/Switch4' */
  /* End of Outputs for SubSystem: '<S72>/Subsys_VIPM_TboxRmtDefrstCtl_enum' */

  /* Outputs for Atomic SubSystem: '<S72>/Subsys_VIPM_TBOXVCUVer_flg' */
  /* Logic: '<S114>/Logical Operator3' incorporates:
   *  Constant: '<S114>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_TBOXVCUVerVld_flg = (KIPM_TBOXVCUVer_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S114>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S114>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S114>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S114>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_a2i =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->TBOX_VCU_Version;
    }

    /* End of Switch: '<S114>/Switch3' */
  } else {
    /* Switch: '<S114>/Switch' incorporates:
     *  Constant: '<S114>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_a2i = KIPM_TBOXVCUVerDflt_flg;
  }

  /* End of Switch: '<S114>/Switch' */

  /* Switch: '<S114>/Switch4' incorporates:
   *  Constant: '<S114>/sat3'
   */
  if (KIPM_TBOXVCUVer_flg_ovrdflg) {
    /* Switch: '<S114>/Switch4' incorporates:
     *  Constant: '<S114>/sat4'
     */
    VIPM_TBOXVCUVer_flg = KIPM_TBOXVCUVer_flg_ovrdval;
  } else {
    /* Switch: '<S114>/Switch4' */
    VIPM_TBOXVCUVer_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_a2i;
  }

  /* End of Switch: '<S114>/Switch4' */
  /* End of Outputs for SubSystem: '<S72>/Subsys_VIPM_TBOXVCUVer_flg' */

  /* Outputs for Atomic SubSystem: '<S72>/Subsys_VIPM_TBOXVCUOprtLic_flg' */
  /* Logic: '<S113>/Logical Operator3' incorporates:
   *  Constant: '<S113>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_TBOXVCUOprtLicVld_flg = (KIPM_TBOXVCUOprtLic_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S113>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S113>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S113>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S113>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_et =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())
        ->TBOX_VCU_OperatLicence;
    }

    /* End of Switch: '<S113>/Switch3' */
  } else {
    /* Switch: '<S113>/Switch' incorporates:
     *  Constant: '<S113>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_et = KIPM_TBOXVCUOprtLicDflt_flg;
  }

  /* End of Switch: '<S113>/Switch' */

  /* Switch: '<S113>/Switch4' incorporates:
   *  Constant: '<S113>/sat3'
   */
  if (KIPM_TBOXVCUOprtLic_flg_ovrdflg) {
    /* Switch: '<S113>/Switch4' incorporates:
     *  Constant: '<S113>/sat4'
     */
    VIPM_TBOXVCUOprtLic_flg = KIPM_TBOXVCUOprtLic_flg_ovrdval;
  } else {
    /* Switch: '<S113>/Switch4' */
    VIPM_TBOXVCUOprtLic_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_et;
  }

  /* End of Switch: '<S113>/Switch4' */
  /* End of Outputs for SubSystem: '<S72>/Subsys_VIPM_TBOXVCUOprtLic_flg' */

  /* Outputs for Atomic SubSystem: '<S72>/Subsys_VIPM_TBOXVCUChrgngConds_flg' */
  /* Logic: '<S112>/Logical Operator3' incorporates:
   *  Constant: '<S112>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_TBOXVCUChrgngCondsVld_flg = (KIPM_TBOXVCUChrgngConds_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S112>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S112>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S112>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S112>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_bo =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())
        ->TBOX_VCU_ChargingConditions;
    }

    /* End of Switch: '<S112>/Switch3' */
  } else {
    /* Switch: '<S112>/Switch' incorporates:
     *  Constant: '<S112>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_bo = KIPM_TBOXVCUChrgngCondsDflt_flg;
  }

  /* End of Switch: '<S112>/Switch' */

  /* Switch: '<S112>/Switch4' incorporates:
   *  Constant: '<S112>/sat3'
   */
  if (KIPM_TBOXVCUChrgngConds_flg_ovrdflg) {
    /* Switch: '<S112>/Switch4' incorporates:
     *  Constant: '<S112>/sat4'
     */
    VIPM_TBOXVCUChrgngConds_flg = KIPM_TBOXVCUChrgngConds_flg_ovrdval;
  } else {
    /* Switch: '<S112>/Switch4' */
    VIPM_TBOXVCUChrgngConds_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_bo;
  }

  /* End of Switch: '<S112>/Switch4' */
  /* End of Outputs for SubSystem: '<S72>/Subsys_VIPM_TBOXVCUChrgngConds_flg' */

  /* Outputs for Atomic SubSystem: '<S72>/Subsys_VIPM_TBOXRmtPwrLck_enum' */
  /* Logic: '<S110>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/HU_B_BAC'
   */
  rtb_LogicalOperator2_j = ((Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC()
    )->TBOX_RemotePowerLockV &&
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Logic: '<S110>/Logical Operator3' incorporates:
   *  Constant: '<S110>/sat3'
   */
  VIPM_TBOXRmtPwrLckVld_flg = (KIPM_TBOXRmtPwrLck_enum_ovrdflg ||
    rtb_LogicalOperator2_j);

  /* Switch: '<S110>/Switch' */
  if (rtb_LogicalOperator2_j) {
    /* Switch: '<S110>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S110>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S110>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_js =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())
        ->TBOX_RemotePowerLock;
    }

    /* End of Switch: '<S110>/Switch3' */
  } else {
    /* Switch: '<S110>/Switch' incorporates:
     *  Constant: '<S110>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_js = KIPM_TBOXRmtPwrLckDflt_enum;
  }

  /* End of Switch: '<S110>/Switch' */

  /* Switch: '<S110>/Switch4' incorporates:
   *  Constant: '<S110>/sat3'
   */
  if (KIPM_TBOXRmtPwrLck_enum_ovrdflg) {
    /* Switch: '<S110>/Switch4' incorporates:
     *  Constant: '<S110>/sat4'
     */
    VIPM_TBOXRmtPwrLck_enum = KIPM_TBOXRmtPwrLck_enum_ovrdval;
  } else {
    /* Switch: '<S110>/Switch4' */
    VIPM_TBOXRmtPwrLck_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_js;
  }

  /* End of Switch: '<S110>/Switch4' */
  /* End of Outputs for SubSystem: '<S72>/Subsys_VIPM_TBOXRmtPwrLck_enum' */

  /* Outputs for Atomic SubSystem: '<S72>/Subsys_VIPM_TBOXVCUCCMSpdLimLvl_enum' */
  /* Logic: '<S111>/Logical Operator3' incorporates:
   *  Constant: '<S111>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_TBOXVCUCCMSpdLimLvlVld_flg = (KIPM_TBOXVCUCCMSpdLimLvl_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S111>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S111>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S111>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S111>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_as =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())
        ->TBOX_VCU_CCM_SpeedLimitLevel;
    }

    /* End of Switch: '<S111>/Switch3' */
  } else {
    /* Switch: '<S111>/Switch' incorporates:
     *  Constant: '<S111>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_as = KIPM_TBOXVCUCCMSpdLimLvlDflt_enum;
  }

  /* End of Switch: '<S111>/Switch' */

  /* Switch: '<S111>/Switch4' incorporates:
   *  Constant: '<S111>/sat3'
   */
  if (KIPM_TBOXVCUCCMSpdLimLvl_enum_ovrdflg) {
    /* Switch: '<S111>/Switch4' incorporates:
     *  Constant: '<S111>/sat4'
     */
    VIPM_TBOXVCUCCMSpdLimLvl_enum = KIPM_TBOXVCUCCMSpdLimLvl_enum_ovrdval;
  } else {
    /* Switch: '<S111>/Switch4' */
    VIPM_TBOXVCUCCMSpdLimLvl_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_as;
  }

  /* End of Switch: '<S111>/Switch4' */
  /* End of Outputs for SubSystem: '<S72>/Subsys_VIPM_TBOXVCUCCMSpdLimLvl_enum' */

  /* Outputs for Atomic SubSystem: '<S72>/Subsys_VIPM_TBoxRmtLck_enum' */
  /* Logic: '<S117>/Logical Operator3' incorporates:
   *  Constant: '<S117>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_TBoxRmtLckVld_flg = (KIPM_TBoxRmtLck_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S117>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S117>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S117>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S117>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_c5 =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->TBox_RemoteLock;
    }

    /* End of Switch: '<S117>/Switch3' */
  } else {
    /* Switch: '<S117>/Switch' incorporates:
     *  Constant: '<S117>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_c5 = KIPM_TBoxRmtLckDflt_enum;
  }

  /* End of Switch: '<S117>/Switch' */

  /* Switch: '<S117>/Switch4' incorporates:
   *  Constant: '<S117>/sat3'
   */
  if (KIPM_TBoxRmtLck_enum_ovrdflg) {
    /* Switch: '<S117>/Switch4' incorporates:
     *  Constant: '<S117>/sat4'
     */
    VIPM_TBoxRmtLck_enum = KIPM_TBoxRmtLck_enum_ovrdval;
  } else {
    /* Switch: '<S117>/Switch4' */
    VIPM_TBoxRmtLck_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_c5;
  }

  /* End of Switch: '<S117>/Switch4' */
  /* End of Outputs for SubSystem: '<S72>/Subsys_VIPM_TBoxRmtLck_enum' */

  /* BusCreator: '<S72>/BusCreator' incorporates:
   *  DataTypeConversion: '<S72>/Data Type Conversion'
   *  DataTypeConversion: '<S72>/Data Type Conversion1'
   *  DataTypeConversion: '<S72>/Data Type Conversion2'
   *  Logic: '<S100>/Logical Operator3'
   *  Logic: '<S101>/Logical Operator3'
   *  Logic: '<S102>/Logical Operator3'
   *  Logic: '<S103>/Logical Operator3'
   *  Logic: '<S104>/Logical Operator3'
   *  Logic: '<S105>/Logical Operator3'
   *  Logic: '<S106>/Logical Operator3'
   *  Logic: '<S107>/Logical Operator3'
   *  Logic: '<S108>/Logical Operator3'
   *  Logic: '<S109>/Logical Operator3'
   *  Logic: '<S110>/Logical Operator3'
   *  Logic: '<S111>/Logical Operator3'
   *  Logic: '<S112>/Logical Operator3'
   *  Logic: '<S113>/Logical Operator3'
   *  Logic: '<S114>/Logical Operator3'
   *  Logic: '<S115>/Logical Operator3'
   *  Logic: '<S116>/Logical Operator3'
   *  Logic: '<S117>/Logical Operator3'
   *  Logic: '<S118>/Logical Operator3'
   *  Logic: '<S75>/Logical Operator3'
   *  Logic: '<S76>/Logical Operator3'
   *  Logic: '<S77>/Logical Operator3'
   *  Logic: '<S78>/Logical Operator3'
   *  Logic: '<S79>/Logical Operator3'
   *  Logic: '<S80>/Logical Operator3'
   *  Logic: '<S81>/Logical Operator3'
   *  Logic: '<S82>/Logical Operator3'
   *  Logic: '<S83>/Logical Operator3'
   *  Logic: '<S84>/Logical Operator3'
   *  Logic: '<S85>/Logical Operator3'
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
   *  Switch: '<S100>/Switch4'
   *  Switch: '<S101>/Switch4'
   *  Switch: '<S102>/Switch4'
   *  Switch: '<S103>/Switch4'
   *  Switch: '<S104>/Switch4'
   *  Switch: '<S105>/Switch4'
   *  Switch: '<S106>/Switch4'
   *  Switch: '<S107>/Switch4'
   *  Switch: '<S108>/Switch4'
   *  Switch: '<S109>/Switch4'
   *  Switch: '<S110>/Switch4'
   *  Switch: '<S111>/Switch4'
   *  Switch: '<S112>/Switch4'
   *  Switch: '<S113>/Switch4'
   *  Switch: '<S114>/Switch4'
   *  Switch: '<S115>/Switch4'
   *  Switch: '<S116>/Switch4'
   *  Switch: '<S117>/Switch4'
   *  Switch: '<S118>/Switch4'
   *  Switch: '<S75>/Switch4'
   *  Switch: '<S76>/Switch4'
   *  Switch: '<S77>/Switch4'
   *  Switch: '<S78>/Switch4'
   *  Switch: '<S79>/Switch4'
   *  Switch: '<S80>/Switch4'
   *  Switch: '<S81>/Switch4'
   *  Switch: '<S82>/Switch4'
   *  Switch: '<S83>/Switch4'
   *  Switch: '<S84>/Switch4'
   *  Switch: '<S85>/Switch4'
   *  Switch: '<S86>/Switch4'
   *  Switch: '<S87>/Switch4'
   *  Switch: '<S88>/Switch4'
   *  Switch: '<S89>/Switch4'
   *  Switch: '<S90>/Switch4'
   *  Switch: '<S91>/Switch4'
   *  Switch: '<S92>/Switch4'
   *  Switch: '<S93>/Switch4'
   *  Switch: '<S94>/Switch4'
   *  Switch: '<S95>/Switch4'
   *  Switch: '<S96>/Switch4'
   *  Switch: '<S97>/Switch4'
   *  Switch: '<S98>/Switch4'
   *  Switch: '<S99>/Switch4'
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

  /* Outputs for Atomic SubSystem: '<S119>/Subsys_VIPM_BMSHVBatCellTempAve_C' */
  /* Logic: '<S124>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/BMS_5_BatTemp_EPT'
   */
  rtb_LogicalOperator2_j =
    ((Rte_IRead_Runbl_IpmCanRx_100ms_BMS_5_BatTemp_EPT_BMS_5_BatTemp_EPT())
     ->BMS_HVBatCellTempValid &&
     (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
     ->VIPM_BMSMsgActv_flg);

  /* Logic: '<S124>/Logical Operator3' incorporates:
   *  Constant: '<S124>/sat3'
   */
  VIPM_BMSHVBatCellTempAveVld_flg = (KIPM_BMSHVBatCellTempAve_C_ovrdflg ||
    rtb_LogicalOperator2_j);

  /* Switch: '<S124>/Switch4' incorporates:
   *  Constant: '<S124>/sat3'
   *  Switch: '<S124>/Switch'
   */
  if (KIPM_BMSHVBatCellTempAve_C_ovrdflg) {
    /* MinMax: '<S57>/MinMax' incorporates:
     *  Constant: '<S124>/sat4'
     *  MinMax: '<S163>/MinMax'
     */
    VIPM_IPUOBCTempInt_C = KIPM_BMSHVBatCellTempAve_C_ovrdval;
  } else if (rtb_LogicalOperator2_j) {
    /* Product: '<S127>/Product' incorporates:
     *  Inport: '<Root>/BMS_5_BatTemp_EPT'
     *  Switch: '<S124>/Switch'
     */
    rtb_Product_mh =
      (Rte_IRead_Runbl_IpmCanRx_100ms_BMS_5_BatTemp_EPT_BMS_5_BatTemp_EPT())
      ->BMS_HVBatCellTempAve;

    /* MinMax: '<S57>/MinMax' incorporates:
     *  MinMax: '<S163>/MinMax'
     *  Sum: '<S127>/Add'
     *  Switch: '<S124>/Switch'
     */
    VIPM_IPUOBCTempInt_C = (float32)rtb_Product_mh - 40.0F;
  } else {
    /* MinMax: '<S57>/MinMax' incorporates:
     *  Constant: '<S124>/sat5'
     *  MinMax: '<S163>/MinMax'
     *  Switch: '<S124>/Switch'
     */
    VIPM_IPUOBCTempInt_C = KIPM_BMSHVBatCellTempAveDflt_C;
  }

  /* End of Switch: '<S124>/Switch4' */

  /* MinMax: '<S124>/MinMax' incorporates:
   *  Constant: '<S124>/sat6'
   */
  if (VIPM_IPUOBCTempInt_C > KIPM_BMSHVBatCellTempAveHi_C) {
    /* MinMax: '<S57>/MinMax' */
    VIPM_IPUOBCTempInt_C = KIPM_BMSHVBatCellTempAveHi_C;
  }

  /* End of MinMax: '<S124>/MinMax' */

  /* MinMax: '<S124>/MinMax1' incorporates:
   *  Constant: '<S124>/sat7'
   */
  if (VIPM_IPUOBCTempInt_C >= KIPM_BMSHVBatCellTempAveLo_C) {
    /* MinMax: '<S124>/MinMax1' */
    VIPM_BMSHVBatCellTempAve_C = VIPM_IPUOBCTempInt_C;
  } else {
    /* MinMax: '<S124>/MinMax1' */
    VIPM_BMSHVBatCellTempAve_C = KIPM_BMSHVBatCellTempAveLo_C;
  }

  /* End of MinMax: '<S124>/MinMax1' */
  /* End of Outputs for SubSystem: '<S119>/Subsys_VIPM_BMSHVBatCellTempAve_C' */

  /* Outputs for Atomic SubSystem: '<S119>/Subsys_VIPM_BMSHVBatCellTempMax_C' */
  /* Logic: '<S125>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/BMS_5_BatTemp_EPT'
   */
  rtb_LogicalOperator2_j =
    ((Rte_IRead_Runbl_IpmCanRx_100ms_BMS_5_BatTemp_EPT_BMS_5_BatTemp_EPT())
     ->BMS_HVBatCellTempValid &&
     (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
     ->VIPM_BMSMsgActv_flg);

  /* Logic: '<S125>/Logical Operator3' incorporates:
   *  Constant: '<S125>/sat3'
   */
  VIPM_BMSHVBatCellTempMaxVld_flg = (KIPM_BMSHVBatCellTempMax_C_ovrdflg ||
    rtb_LogicalOperator2_j);

  /* Switch: '<S125>/Switch4' incorporates:
   *  Constant: '<S125>/sat3'
   *  Switch: '<S125>/Switch'
   */
  if (KIPM_BMSHVBatCellTempMax_C_ovrdflg) {
    /* MinMax: '<S57>/MinMax' incorporates:
     *  Constant: '<S125>/sat4'
     *  MinMax: '<S163>/MinMax'
     */
    VIPM_IPUOBCTempInt_C = KIPM_BMSHVBatCellTempMax_C_ovrdval;
  } else if (rtb_LogicalOperator2_j) {
    /* Product: '<S128>/Product' incorporates:
     *  Inport: '<Root>/BMS_5_BatTemp_EPT'
     *  Switch: '<S125>/Switch'
     */
    rtb_Product_mh =
      (Rte_IRead_Runbl_IpmCanRx_100ms_BMS_5_BatTemp_EPT_BMS_5_BatTemp_EPT())
      ->BMS_HVBatCellTempMax;

    /* MinMax: '<S57>/MinMax' incorporates:
     *  MinMax: '<S163>/MinMax'
     *  Sum: '<S128>/Add'
     *  Switch: '<S125>/Switch'
     */
    VIPM_IPUOBCTempInt_C = (float32)rtb_Product_mh - 40.0F;
  } else {
    /* MinMax: '<S57>/MinMax' incorporates:
     *  Constant: '<S125>/sat5'
     *  MinMax: '<S163>/MinMax'
     *  Switch: '<S125>/Switch'
     */
    VIPM_IPUOBCTempInt_C = KIPM_BMSHVBatCellTempMaxDflt_C;
  }

  /* End of Switch: '<S125>/Switch4' */

  /* MinMax: '<S125>/MinMax' incorporates:
   *  Constant: '<S125>/sat6'
   */
  if (VIPM_IPUOBCTempInt_C > KIPM_BMSHVBatCellTempMaxHi_C) {
    /* MinMax: '<S57>/MinMax' */
    VIPM_IPUOBCTempInt_C = KIPM_BMSHVBatCellTempMaxHi_C;
  }

  /* End of MinMax: '<S125>/MinMax' */

  /* MinMax: '<S125>/MinMax1' incorporates:
   *  Constant: '<S125>/sat7'
   */
  if (VIPM_IPUOBCTempInt_C >= KIPM_BMSHVBatCellTempMaxLo_C) {
    /* MinMax: '<S125>/MinMax1' */
    VIPM_BMSHVBatCellTempMax_C = VIPM_IPUOBCTempInt_C;
  } else {
    /* MinMax: '<S125>/MinMax1' */
    VIPM_BMSHVBatCellTempMax_C = KIPM_BMSHVBatCellTempMaxLo_C;
  }

  /* End of MinMax: '<S125>/MinMax1' */
  /* End of Outputs for SubSystem: '<S119>/Subsys_VIPM_BMSHVBatCellTempMax_C' */

  /* Outputs for Atomic SubSystem: '<S119>/Subsys_VIPM_BMSHVBatCellTempMin_C' */
  /* Logic: '<S126>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/BMS_5_BatTemp_EPT'
   */
  rtb_LogicalOperator2_j =
    ((Rte_IRead_Runbl_IpmCanRx_100ms_BMS_5_BatTemp_EPT_BMS_5_BatTemp_EPT())
     ->BMS_HVBatCellTempValid &&
     (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
     ->VIPM_BMSMsgActv_flg);

  /* Logic: '<S126>/Logical Operator3' incorporates:
   *  Constant: '<S126>/sat3'
   */
  VIPM_BMSHVBatCellTempMinVld_flg = (KIPM_BMSHVBatCellTempMin_C_ovrdflg ||
    rtb_LogicalOperator2_j);

  /* Switch: '<S126>/Switch4' incorporates:
   *  Constant: '<S126>/sat3'
   *  Switch: '<S126>/Switch'
   */
  if (KIPM_BMSHVBatCellTempMin_C_ovrdflg) {
    /* MinMax: '<S57>/MinMax' incorporates:
     *  Constant: '<S126>/sat4'
     *  MinMax: '<S163>/MinMax'
     */
    VIPM_IPUOBCTempInt_C = KIPM_BMSHVBatCellTempMin_C_ovrdval;
  } else if (rtb_LogicalOperator2_j) {
    /* Product: '<S129>/Product' incorporates:
     *  Inport: '<Root>/BMS_5_BatTemp_EPT'
     *  Switch: '<S126>/Switch'
     */
    rtb_Product_mh =
      (Rte_IRead_Runbl_IpmCanRx_100ms_BMS_5_BatTemp_EPT_BMS_5_BatTemp_EPT())
      ->BMS_HVBatCellTempMin;

    /* MinMax: '<S57>/MinMax' incorporates:
     *  MinMax: '<S163>/MinMax'
     *  Sum: '<S129>/Add'
     *  Switch: '<S126>/Switch'
     */
    VIPM_IPUOBCTempInt_C = (float32)rtb_Product_mh - 40.0F;
  } else {
    /* MinMax: '<S57>/MinMax' incorporates:
     *  Constant: '<S126>/sat5'
     *  MinMax: '<S163>/MinMax'
     *  Switch: '<S126>/Switch'
     */
    VIPM_IPUOBCTempInt_C = KIPM_BMSHVBatCellTempMinDflt_C;
  }

  /* End of Switch: '<S126>/Switch4' */

  /* MinMax: '<S126>/MinMax' incorporates:
   *  Constant: '<S126>/sat6'
   */
  if (VIPM_IPUOBCTempInt_C > KIPM_BMSHVBatCellTempMinHi_C) {
    /* MinMax: '<S57>/MinMax' */
    VIPM_IPUOBCTempInt_C = KIPM_BMSHVBatCellTempMinHi_C;
  }

  /* End of MinMax: '<S126>/MinMax' */

  /* MinMax: '<S126>/MinMax1' incorporates:
   *  Constant: '<S126>/sat7'
   */
  if (VIPM_IPUOBCTempInt_C >= KIPM_BMSHVBatCellTempMinLo_C) {
    /* MinMax: '<S126>/MinMax1' */
    VIPM_BMSHVBatCellTempMin_C = VIPM_IPUOBCTempInt_C;
  } else {
    /* MinMax: '<S126>/MinMax1' */
    VIPM_BMSHVBatCellTempMin_C = KIPM_BMSHVBatCellTempMinLo_C;
  }

  /* End of MinMax: '<S126>/MinMax1' */
  /* End of Outputs for SubSystem: '<S119>/Subsys_VIPM_BMSHVBatCellTempMin_C' */

  /* BusCreator: '<S119>/BusCreator' incorporates:
   *  Logic: '<S124>/Logical Operator3'
   *  Logic: '<S125>/Logical Operator3'
   *  Logic: '<S126>/Logical Operator3'
   *  MinMax: '<S124>/MinMax1'
   *  MinMax: '<S125>/MinMax1'
   *  MinMax: '<S126>/MinMax1'
   */
  AppSwcIpm_ARID_DEF.IPM_BMS_5_BatTemp_EPT.VIPM_BMSHVBatCellTempAve_C =
    VIPM_BMSHVBatCellTempAve_C;
  AppSwcIpm_ARID_DEF.IPM_BMS_5_BatTemp_EPT.VIPM_BMSHVBatCellTempAveVld_flg =
    VIPM_BMSHVBatCellTempAveVld_flg;
  AppSwcIpm_ARID_DEF.IPM_BMS_5_BatTemp_EPT.VIPM_BMSHVBatCellTempMax_C =
    VIPM_BMSHVBatCellTempMax_C;
  AppSwcIpm_ARID_DEF.IPM_BMS_5_BatTemp_EPT.VIPM_BMSHVBatCellTempMaxVld_flg =
    VIPM_BMSHVBatCellTempMaxVld_flg;
  AppSwcIpm_ARID_DEF.IPM_BMS_5_BatTemp_EPT.VIPM_BMSHVBatCellTempMin_C =
    VIPM_BMSHVBatCellTempMin_C;
  AppSwcIpm_ARID_DEF.IPM_BMS_5_BatTemp_EPT.VIPM_BMSHVBatCellTempMinVld_flg =
    VIPM_BMSHVBatCellTempMinVld_flg;

  /* Outputs for Atomic SubSystem: '<S120>/Subsys_VIPM_INVLrngSubID_cnt' */
  /* Logic: '<S137>/Logical Operator3' incorporates:
   *  Constant: '<S137>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_INVLrngSubIDVld_flg = (KIPM_INVLrngSubID_cnt_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_INVMsgActv_flg);

  /* Switch: '<S137>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_INVMsgActv_flg) {
    /* Switch: '<S137>/Switch' incorporates:
     *  Inport: '<Root>/INV_IMMO_Req_EPT'
     *  Switch: '<S137>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nf =
      (Rte_IRead_Runbl_IpmCanRx_100ms_INV_IMMO_Req_EPT_INV_IMMO_Req_EPT())
      ->INV_LrngSubID;
  } else {
    /* Switch: '<S137>/Switch' incorporates:
     *  Constant: '<S137>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nf = KIPM_INVLrngSubIDDflt_cnt;
  }

  /* End of Switch: '<S137>/Switch' */

  /* Switch: '<S137>/Switch4' incorporates:
   *  Constant: '<S137>/sat3'
   */
  if (KIPM_INVLrngSubID_cnt_ovrdflg) {
    /* Switch: '<S137>/Switch4' incorporates:
     *  Constant: '<S137>/sat4'
     */
    VIPM_INVLrngSubID_cnt = KIPM_INVLrngSubID_cnt_ovrdval;
  } else {
    /* Switch: '<S137>/Switch4' */
    VIPM_INVLrngSubID_cnt = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nf;
  }

  /* End of Switch: '<S137>/Switch4' */
  /* End of Outputs for SubSystem: '<S120>/Subsys_VIPM_INVLrngSubID_cnt' */

  /* Outputs for Atomic SubSystem: '<S120>/Subsys_VIPM_INVLrngSts_enum' */
  /* Logic: '<S136>/Logical Operator3' incorporates:
   *  Constant: '<S136>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_INVLrngStsVld_flg = (KIPM_INVLrngSts_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_INVMsgActv_flg);

  /* Switch: '<S136>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_INVMsgActv_flg) {
    /* Switch: '<S136>/Switch' incorporates:
     *  Inport: '<Root>/INV_IMMO_Req_EPT'
     *  Switch: '<S136>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_i5 =
      (Rte_IRead_Runbl_IpmCanRx_100ms_INV_IMMO_Req_EPT_INV_IMMO_Req_EPT())
      ->INV_LrngSts;
  } else {
    /* Switch: '<S136>/Switch' incorporates:
     *  Constant: '<S136>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_i5 = KIPM_INVLrngStsDflt_enum;
  }

  /* End of Switch: '<S136>/Switch' */

  /* Switch: '<S136>/Switch4' incorporates:
   *  Constant: '<S136>/sat3'
   */
  if (KIPM_INVLrngSts_enum_ovrdflg) {
    /* Switch: '<S136>/Switch4' incorporates:
     *  Constant: '<S136>/sat4'
     */
    VIPM_INVLrngSts_enum = KIPM_INVLrngSts_enum_ovrdval;
  } else {
    /* Switch: '<S136>/Switch4' */
    VIPM_INVLrngSts_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_i5;
  }

  /* End of Switch: '<S136>/Switch4' */
  /* End of Outputs for SubSystem: '<S120>/Subsys_VIPM_INVLrngSts_enum' */

  /* Outputs for Atomic SubSystem: '<S120>/Subsys_VIPM_INVLrngData02_nu' */
  /* Logic: '<S130>/Logical Operator3' incorporates:
   *  Constant: '<S130>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_INVLrngData02Vld_flg = (KIPM_INVLrngData02_nu_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_INVMsgActv_flg);

  /* Switch: '<S130>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_INVMsgActv_flg) {
    /* Switch: '<S130>/Switch' incorporates:
     *  Inport: '<Root>/INV_IMMO_Req_EPT'
     *  Switch: '<S130>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ju =
      (Rte_IRead_Runbl_IpmCanRx_100ms_INV_IMMO_Req_EPT_INV_IMMO_Req_EPT())
      ->INV_LrngData02;
  } else {
    /* Switch: '<S130>/Switch' incorporates:
     *  Constant: '<S130>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ju = KIPM_INVLrngData02Dflt_nu;
  }

  /* End of Switch: '<S130>/Switch' */

  /* Switch: '<S130>/Switch4' incorporates:
   *  Constant: '<S130>/sat3'
   */
  if (KIPM_INVLrngData02_nu_ovrdflg) {
    /* Switch: '<S130>/Switch4' incorporates:
     *  Constant: '<S130>/sat4'
     */
    VIPM_INVLrngData02_nu = KIPM_INVLrngData02_nu_ovrdval;
  } else {
    /* Switch: '<S130>/Switch4' */
    VIPM_INVLrngData02_nu = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ju;
  }

  /* End of Switch: '<S130>/Switch4' */
  /* End of Outputs for SubSystem: '<S120>/Subsys_VIPM_INVLrngData02_nu' */

  /* Outputs for Atomic SubSystem: '<S120>/Subsys_VIPM_INVLrngData03_nu' */
  /* Logic: '<S131>/Logical Operator3' incorporates:
   *  Constant: '<S131>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_INVLrngData03Vld_flg = (KIPM_INVLrngData03_nu_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_INVMsgActv_flg);

  /* Switch: '<S131>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_INVMsgActv_flg) {
    /* Switch: '<S131>/Switch' incorporates:
     *  Inport: '<Root>/INV_IMMO_Req_EPT'
     *  Switch: '<S131>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ec =
      (Rte_IRead_Runbl_IpmCanRx_100ms_INV_IMMO_Req_EPT_INV_IMMO_Req_EPT())
      ->INV_LrngData03;
  } else {
    /* Switch: '<S131>/Switch' incorporates:
     *  Constant: '<S131>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ec = KIPM_INVLrngData03Dflt_nu;
  }

  /* End of Switch: '<S131>/Switch' */

  /* Switch: '<S131>/Switch4' incorporates:
   *  Constant: '<S131>/sat3'
   */
  if (KIPM_INVLrngData03_nu_ovrdflg) {
    /* Switch: '<S131>/Switch4' incorporates:
     *  Constant: '<S131>/sat4'
     */
    VIPM_INVLrngData03_nu = KIPM_INVLrngData03_nu_ovrdval;
  } else {
    /* Switch: '<S131>/Switch4' */
    VIPM_INVLrngData03_nu = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ec;
  }

  /* End of Switch: '<S131>/Switch4' */
  /* End of Outputs for SubSystem: '<S120>/Subsys_VIPM_INVLrngData03_nu' */

  /* Outputs for Atomic SubSystem: '<S120>/Subsys_VIPM_INVLrngData04_nu' */
  /* Logic: '<S132>/Logical Operator3' incorporates:
   *  Constant: '<S132>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_INVLrngData04Vld_flg = (KIPM_INVLrngData04_nu_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_INVMsgActv_flg);

  /* Switch: '<S132>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_INVMsgActv_flg) {
    /* Switch: '<S132>/Switch' incorporates:
     *  Inport: '<Root>/INV_IMMO_Req_EPT'
     *  Switch: '<S132>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_euu =
      (Rte_IRead_Runbl_IpmCanRx_100ms_INV_IMMO_Req_EPT_INV_IMMO_Req_EPT())
      ->INV_LrngData04;
  } else {
    /* Switch: '<S132>/Switch' incorporates:
     *  Constant: '<S132>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_euu = KIPM_INVLrngData04Dflt_nu;
  }

  /* End of Switch: '<S132>/Switch' */

  /* Switch: '<S132>/Switch4' incorporates:
   *  Constant: '<S132>/sat3'
   */
  if (KIPM_INVLrngData04_nu_ovrdflg) {
    /* Switch: '<S132>/Switch4' incorporates:
     *  Constant: '<S132>/sat4'
     */
    VIPM_INVLrngData04_nu = KIPM_INVLrngData04_nu_ovrdval;
  } else {
    /* Switch: '<S132>/Switch4' */
    VIPM_INVLrngData04_nu = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_euu;
  }

  /* End of Switch: '<S132>/Switch4' */
  /* End of Outputs for SubSystem: '<S120>/Subsys_VIPM_INVLrngData04_nu' */

  /* Outputs for Atomic SubSystem: '<S120>/Subsys_VIPM_INVLrngData05_nu' */
  /* Logic: '<S133>/Logical Operator3' incorporates:
   *  Constant: '<S133>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_INVLrngData05Vld_flg = (KIPM_INVLrngData05_nu_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_INVMsgActv_flg);

  /* Switch: '<S133>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_INVMsgActv_flg) {
    /* Switch: '<S133>/Switch' incorporates:
     *  Inport: '<Root>/INV_IMMO_Req_EPT'
     *  Switch: '<S133>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hl =
      (Rte_IRead_Runbl_IpmCanRx_100ms_INV_IMMO_Req_EPT_INV_IMMO_Req_EPT())
      ->INV_LrngData05;
  } else {
    /* Switch: '<S133>/Switch' incorporates:
     *  Constant: '<S133>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hl = KIPM_INVLrngData05Dflt_nu;
  }

  /* End of Switch: '<S133>/Switch' */

  /* Switch: '<S133>/Switch4' incorporates:
   *  Constant: '<S133>/sat3'
   */
  if (KIPM_INVLrngData05_nu_ovrdflg) {
    /* Switch: '<S133>/Switch4' incorporates:
     *  Constant: '<S133>/sat4'
     */
    VIPM_INVLrngData05_nu = KIPM_INVLrngData05_nu_ovrdval;
  } else {
    /* Switch: '<S133>/Switch4' */
    VIPM_INVLrngData05_nu = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hl;
  }

  /* End of Switch: '<S133>/Switch4' */
  /* End of Outputs for SubSystem: '<S120>/Subsys_VIPM_INVLrngData05_nu' */

  /* Outputs for Atomic SubSystem: '<S120>/Subsys_VIPM_INVLrngData06_nu' */
  /* Logic: '<S134>/Logical Operator3' incorporates:
   *  Constant: '<S134>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_INVLrngData06Vld_flg = (KIPM_INVLrngData06_nu_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_INVMsgActv_flg);

  /* Switch: '<S134>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_INVMsgActv_flg) {
    /* Switch: '<S134>/Switch' incorporates:
     *  Inport: '<Root>/INV_IMMO_Req_EPT'
     *  Switch: '<S134>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pc =
      (Rte_IRead_Runbl_IpmCanRx_100ms_INV_IMMO_Req_EPT_INV_IMMO_Req_EPT())
      ->INV_LrngData06;
  } else {
    /* Switch: '<S134>/Switch' incorporates:
     *  Constant: '<S134>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pc = KIPM_INVLrngData06Dflt_nu;
  }

  /* End of Switch: '<S134>/Switch' */

  /* Switch: '<S134>/Switch4' incorporates:
   *  Constant: '<S134>/sat3'
   */
  if (KIPM_INVLrngData06_nu_ovrdflg) {
    /* Switch: '<S134>/Switch4' incorporates:
     *  Constant: '<S134>/sat4'
     */
    VIPM_INVLrngData06_nu = KIPM_INVLrngData06_nu_ovrdval;
  } else {
    /* Switch: '<S134>/Switch4' */
    VIPM_INVLrngData06_nu = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pc;
  }

  /* End of Switch: '<S134>/Switch4' */
  /* End of Outputs for SubSystem: '<S120>/Subsys_VIPM_INVLrngData06_nu' */

  /* Outputs for Atomic SubSystem: '<S120>/Subsys_VIPM_INVLrngData07_nu' */
  /* Logic: '<S135>/Logical Operator3' incorporates:
   *  Constant: '<S135>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_INVLrngData07Vld_flg = (KIPM_INVLrngData07_nu_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_INVMsgActv_flg);

  /* Switch: '<S135>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_INVMsgActv_flg) {
    /* Switch: '<S135>/Switch' incorporates:
     *  Inport: '<Root>/INV_IMMO_Req_EPT'
     *  Switch: '<S135>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lg =
      (Rte_IRead_Runbl_IpmCanRx_100ms_INV_IMMO_Req_EPT_INV_IMMO_Req_EPT())
      ->INV_LrngData07;
  } else {
    /* Switch: '<S135>/Switch' incorporates:
     *  Constant: '<S135>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lg = KIPM_INVLrngData07Dflt_nu;
  }

  /* End of Switch: '<S135>/Switch' */

  /* Switch: '<S135>/Switch4' incorporates:
   *  Constant: '<S135>/sat3'
   */
  if (KIPM_INVLrngData07_nu_ovrdflg) {
    /* Switch: '<S135>/Switch4' incorporates:
     *  Constant: '<S135>/sat4'
     */
    VIPM_INVLrngData07_nu = KIPM_INVLrngData07_nu_ovrdval;
  } else {
    /* Switch: '<S135>/Switch4' */
    VIPM_INVLrngData07_nu = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lg;
  }

  /* End of Switch: '<S135>/Switch4' */
  /* End of Outputs for SubSystem: '<S120>/Subsys_VIPM_INVLrngData07_nu' */

  /* BusCreator: '<S120>/BusCreator' incorporates:
   *  Logic: '<S130>/Logical Operator3'
   *  Logic: '<S131>/Logical Operator3'
   *  Logic: '<S132>/Logical Operator3'
   *  Logic: '<S133>/Logical Operator3'
   *  Logic: '<S134>/Logical Operator3'
   *  Logic: '<S135>/Logical Operator3'
   *  Logic: '<S136>/Logical Operator3'
   *  Logic: '<S137>/Logical Operator3'
   *  Switch: '<S130>/Switch4'
   *  Switch: '<S131>/Switch4'
   *  Switch: '<S132>/Switch4'
   *  Switch: '<S133>/Switch4'
   *  Switch: '<S134>/Switch4'
   *  Switch: '<S135>/Switch4'
   *  Switch: '<S136>/Switch4'
   *  Switch: '<S137>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_INV_IMMO_Req_EPT_g.VIPM_INVLrngSubID_cnt =
    VIPM_INVLrngSubID_cnt;
  AppSwcIpm_ARID_DEF.IPM_INV_IMMO_Req_EPT_g.VIPM_INVLrngSubIDVld_flg =
    VIPM_INVLrngSubIDVld_flg;
  AppSwcIpm_ARID_DEF.IPM_INV_IMMO_Req_EPT_g.VIPM_INVLrngSts_enum =
    VIPM_INVLrngSts_enum;
  AppSwcIpm_ARID_DEF.IPM_INV_IMMO_Req_EPT_g.VIPM_INVLrngStsVld_flg =
    VIPM_INVLrngStsVld_flg;
  AppSwcIpm_ARID_DEF.IPM_INV_IMMO_Req_EPT_g.VIPM_INVLrngData02_nu =
    VIPM_INVLrngData02_nu;
  AppSwcIpm_ARID_DEF.IPM_INV_IMMO_Req_EPT_g.VIPM_INVLrngData02Vld_flg =
    VIPM_INVLrngData02Vld_flg;
  AppSwcIpm_ARID_DEF.IPM_INV_IMMO_Req_EPT_g.VIPM_INVLrngData03_nu =
    VIPM_INVLrngData03_nu;
  AppSwcIpm_ARID_DEF.IPM_INV_IMMO_Req_EPT_g.VIPM_INVLrngData03Vld_flg =
    VIPM_INVLrngData03Vld_flg;
  AppSwcIpm_ARID_DEF.IPM_INV_IMMO_Req_EPT_g.VIPM_INVLrngData04_nu =
    VIPM_INVLrngData04_nu;
  AppSwcIpm_ARID_DEF.IPM_INV_IMMO_Req_EPT_g.VIPM_INVLrngData04Vld_flg =
    VIPM_INVLrngData04Vld_flg;
  AppSwcIpm_ARID_DEF.IPM_INV_IMMO_Req_EPT_g.VIPM_INVLrngData05_nu =
    VIPM_INVLrngData05_nu;
  AppSwcIpm_ARID_DEF.IPM_INV_IMMO_Req_EPT_g.VIPM_INVLrngData05Vld_flg =
    VIPM_INVLrngData05Vld_flg;
  AppSwcIpm_ARID_DEF.IPM_INV_IMMO_Req_EPT_g.VIPM_INVLrngData06_nu =
    VIPM_INVLrngData06_nu;
  AppSwcIpm_ARID_DEF.IPM_INV_IMMO_Req_EPT_g.VIPM_INVLrngData06Vld_flg =
    VIPM_INVLrngData06Vld_flg;
  AppSwcIpm_ARID_DEF.IPM_INV_IMMO_Req_EPT_g.VIPM_INVLrngData07_nu =
    VIPM_INVLrngData07_nu;
  AppSwcIpm_ARID_DEF.IPM_INV_IMMO_Req_EPT_g.VIPM_INVLrngData07Vld_flg =
    VIPM_INVLrngData07Vld_flg;

  /* Outputs for Atomic SubSystem: '<S121>/Subsys_VIPM_IPUDCCActOprtMode_enum' */
  /* Logic: '<S138>/Logical Operator3' incorporates:
   *  Constant: '<S138>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_IPUDCCActOprtModeVld_flg = (KIPM_IPUDCCActOprtMode_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_DCDCMsgActv_flg);

  /* Switch: '<S138>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_DCDCMsgActv_flg) {
    /* Switch: '<S138>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_IPU_DCC_1_State_CRCFlt_flg) {
      /* Switch: '<S138>/Switch' incorporates:
       *  DataTypeConversion: '<S138>/Data Type Conversion2'
       *  Inport: '<Root>/IPU_DCC_1_State_EPT'
       *  Switch: '<S138>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ov =
        (Rte_IRead_Runbl_IpmCanRx_100ms_IPU_DCC_1_State_EPT_IPU_DCC_1_State_EPT())
        ->IPU_DCC_ActlOprtMode;
    }

    /* End of Switch: '<S138>/Switch3' */
  } else {
    /* Switch: '<S138>/Switch' incorporates:
     *  Constant: '<S138>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ov = KIPM_IPUDCCActOprtModeDflt_enum;
  }

  /* End of Switch: '<S138>/Switch' */

  /* Switch: '<S138>/Switch4' incorporates:
   *  Constant: '<S138>/sat3'
   */
  if (KIPM_IPUDCCActOprtMode_enum_ovrdflg) {
    /* Switch: '<S138>/Switch4' incorporates:
     *  Constant: '<S138>/sat4'
     */
    VIPM_IPUDCCActOprtMode_enum = KIPM_IPUDCCActOprtMode_enum_ovrdval;
  } else {
    /* Switch: '<S138>/Switch4' incorporates:
     *  Switch: '<S138>/Switch'
     */
    VIPM_IPUDCCActOprtMode_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ov;
  }

  /* End of Switch: '<S138>/Switch4' */
  /* End of Outputs for SubSystem: '<S121>/Subsys_VIPM_IPUDCCActOprtMode_enum' */

  /* Outputs for Atomic SubSystem: '<S121>/Subsys_VIPM_IPUDCCLoVoltActVolt_V' */
  /* Logic: '<S140>/Logical Operator3' incorporates:
   *  Constant: '<S140>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_IPUDCCLoVoltActVoltVld_flg = (KIPM_IPUDCCLoVoltActVolt_V_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_DCDCMsgActv_flg);

  /* Switch: '<S140>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_DCDCMsgActv_flg) {
    /* Switch: '<S140>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_IPU_DCC_1_State_CRCFlt_flg) {
      /* Switch: '<S140>/Switch' incorporates:
       *  Constant: '<S143>/Constant'
       *  Inport: '<Root>/IPU_DCC_1_State_EPT'
       *  Product: '<S143>/Product'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ow = (float32)
        (Rte_IRead_Runbl_IpmCanRx_100ms_IPU_DCC_1_State_EPT_IPU_DCC_1_State_EPT())
        ->IPU_DCC_LowVolActlVol * 0.1F;
    }

    /* End of Switch: '<S140>/Switch3' */
  } else {
    /* Switch: '<S140>/Switch' incorporates:
     *  Constant: '<S140>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ow = KIPM_IPUDCCLoVoltActVoltDflt_V;
  }

  /* End of Switch: '<S140>/Switch' */

  /* Switch: '<S140>/Switch4' incorporates:
   *  Constant: '<S140>/sat3'
   *  Constant: '<S140>/sat4'
   */
  if (KIPM_IPUDCCLoVoltActVolt_V_ovrdflg) {
    VIPM_IPUDCCLoVoltActVolt_V = KIPM_IPUDCCLoVoltActVolt_V_ovrdval;
  } else {
    VIPM_IPUDCCLoVoltActVolt_V = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ow;
  }

  /* MinMax: '<S140>/MinMax' incorporates:
   *  Constant: '<S140>/sat6'
   *  Switch: '<S140>/Switch4'
   */
  if (VIPM_IPUDCCLoVoltActVolt_V > KIPM_IPUDCCLoVoltActVoltHi_V) {
    VIPM_IPUDCCLoVoltActVolt_V = KIPM_IPUDCCLoVoltActVoltHi_V;
  }

  /* End of MinMax: '<S140>/MinMax' */

  /* MinMax: '<S140>/MinMax1' incorporates:
   *  Constant: '<S140>/sat7'
   */
  if (VIPM_IPUDCCLoVoltActVolt_V < KIPM_IPUDCCLoVoltActVoltLo_V) {
    /* Switch: '<S140>/Switch4' incorporates:
     *  MinMax: '<S140>/MinMax1'
     */
    VIPM_IPUDCCLoVoltActVolt_V = KIPM_IPUDCCLoVoltActVoltLo_V;
  }

  /* End of MinMax: '<S140>/MinMax1' */
  /* End of Outputs for SubSystem: '<S121>/Subsys_VIPM_IPUDCCLoVoltActVolt_V' */

  /* Outputs for Atomic SubSystem: '<S121>/Subsys_VIPM_IPUDCCLoVoltActCurnt_A' */
  /* Logic: '<S139>/Logical Operator3' incorporates:
   *  Constant: '<S139>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_IPUDCCLoVoltActCurntVld_flg = (KIPM_IPUDCCLoVoltActCurnt_A_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_DCDCMsgActv_flg);

  /* Switch: '<S139>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_DCDCMsgActv_flg) {
    /* Switch: '<S139>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_IPU_DCC_1_State_CRCFlt_flg) {
      /* Product: '<S144>/Product' incorporates:
       *  Constant: '<S144>/Constant'
       *  Inport: '<Root>/IPU_DCC_1_State_EPT'
       */
      rtb_Product_l3f = (float32)
        (Rte_IRead_Runbl_IpmCanRx_100ms_IPU_DCC_1_State_EPT_IPU_DCC_1_State_EPT())
        ->IPU_DCC_LowVolActlCur * 0.1F;

      /* Switch: '<S139>/Switch' incorporates:
       *  Sum: '<S144>/Add'
       *  Switch: '<S139>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_p = rtb_Product_l3f - 409.6F;
    }

    /* End of Switch: '<S139>/Switch3' */
  } else {
    /* Switch: '<S139>/Switch' incorporates:
     *  Constant: '<S139>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_p = KIPM_IPUDCCLoVoltActCurntDflt_A;
  }

  /* End of Switch: '<S139>/Switch' */

  /* Switch: '<S139>/Switch4' incorporates:
   *  Constant: '<S139>/sat3'
   *  Constant: '<S139>/sat4'
   */
  if (KIPM_IPUDCCLoVoltActCurnt_A_ovrdflg) {
    VIPM_IPUDCCLoVoltActCurnt_A = KIPM_IPUDCCLoVoltActCurnt_A_ovrdval;
  } else {
    VIPM_IPUDCCLoVoltActCurnt_A = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_p;
  }

  /* MinMax: '<S139>/MinMax' incorporates:
   *  Constant: '<S139>/sat6'
   *  Switch: '<S139>/Switch4'
   */
  if (VIPM_IPUDCCLoVoltActCurnt_A > KIPM_IPUDCCLoVoltActCurntHi_A) {
    VIPM_IPUDCCLoVoltActCurnt_A = KIPM_IPUDCCLoVoltActCurntHi_A;
  }

  /* End of MinMax: '<S139>/MinMax' */

  /* MinMax: '<S139>/MinMax1' incorporates:
   *  Constant: '<S139>/sat7'
   */
  if (VIPM_IPUDCCLoVoltActCurnt_A < KIPM_IPUDCCLoVoltActCurntLo_A) {
    /* Switch: '<S139>/Switch4' incorporates:
     *  MinMax: '<S139>/MinMax1'
     */
    VIPM_IPUDCCLoVoltActCurnt_A = KIPM_IPUDCCLoVoltActCurntLo_A;
  }

  /* End of MinMax: '<S139>/MinMax1' */
  /* End of Outputs for SubSystem: '<S121>/Subsys_VIPM_IPUDCCLoVoltActCurnt_A' */

  /* Outputs for Atomic SubSystem: '<S121>/Subsys_VIPM_IPUDCCSysFailSta_enum' */
  /* Logic: '<S141>/Logical Operator3' incorporates:
   *  Constant: '<S141>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_IPUDCCSysFailStaVld_flg = (KIPM_IPUDCCSysFailSta_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_DCDCMsgActv_flg);

  /* Switch: '<S141>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_DCDCMsgActv_flg) {
    /* Switch: '<S141>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_IPU_DCC_1_State_CRCFlt_flg) {
      /* Switch: '<S141>/Switch' incorporates:
       *  Inport: '<Root>/IPU_DCC_1_State_EPT'
       *  Switch: '<S141>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ph =
        (Rte_IRead_Runbl_IpmCanRx_100ms_IPU_DCC_1_State_EPT_IPU_DCC_1_State_EPT())
        ->IPU_DCC_SysFailSta;
    }

    /* End of Switch: '<S141>/Switch3' */
  } else {
    /* Switch: '<S141>/Switch' incorporates:
     *  Constant: '<S141>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ph = KIPM_IPUDCCSysFailStaDflt_enum;
  }

  /* End of Switch: '<S141>/Switch' */

  /* Switch: '<S141>/Switch4' incorporates:
   *  Constant: '<S141>/sat3'
   */
  if (KIPM_IPUDCCSysFailSta_enum_ovrdflg) {
    /* Switch: '<S141>/Switch4' incorporates:
     *  Constant: '<S141>/sat4'
     */
    VIPM_IPUDCCSysFailSta_enum = KIPM_IPUDCCSysFailSta_enum_ovrdval;
  } else {
    /* Switch: '<S141>/Switch4' */
    VIPM_IPUDCCSysFailSta_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ph;
  }

  /* End of Switch: '<S141>/Switch4' */
  /* End of Outputs for SubSystem: '<S121>/Subsys_VIPM_IPUDCCSysFailSta_enum' */

  /* Outputs for Atomic SubSystem: '<S121>/Subsys_VIPM_IPUHVILFailSt_flg' */
  /* Logic: '<S142>/Logical Operator3' incorporates:
   *  Constant: '<S142>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_IPUHVILFailStVld_flg = (KIPM_IPUHVILFailSt_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_DCDCMsgActv_flg);

  /* Switch: '<S142>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_DCDCMsgActv_flg) {
    /* Switch: '<S142>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_IPU_DCC_1_State_CRCFlt_flg) {
      /* Switch: '<S142>/Switch' incorporates:
       *  Inport: '<Root>/IPU_DCC_1_State_EPT'
       *  Switch: '<S142>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lku =
        (Rte_IRead_Runbl_IpmCanRx_100ms_IPU_DCC_1_State_EPT_IPU_DCC_1_State_EPT())
        ->IPU_HVILFailSta;
    }

    /* End of Switch: '<S142>/Switch3' */
  } else {
    /* Switch: '<S142>/Switch' incorporates:
     *  Constant: '<S142>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lku = KIPM_IPUHVILFailStDflt_flg;
  }

  /* End of Switch: '<S142>/Switch' */

  /* Switch: '<S142>/Switch4' incorporates:
   *  Constant: '<S142>/sat3'
   */
  if (KIPM_IPUHVILFailSt_flg_ovrdflg) {
    /* Switch: '<S142>/Switch4' incorporates:
     *  Constant: '<S142>/sat4'
     */
    VIPM_IPUHVILFailSt_flg = KIPM_IPUHVILFailSt_flg_ovrdval;
  } else {
    /* Switch: '<S142>/Switch4' */
    VIPM_IPUHVILFailSt_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lku;
  }

  /* End of Switch: '<S142>/Switch4' */
  /* End of Outputs for SubSystem: '<S121>/Subsys_VIPM_IPUHVILFailSt_flg' */

  /* BusCreator: '<S121>/BusCreator' incorporates:
   *  DataTypeConversion: '<S121>/Data Type Conversion'
   *  Logic: '<S138>/Logical Operator3'
   *  Logic: '<S139>/Logical Operator3'
   *  Logic: '<S140>/Logical Operator3'
   *  Logic: '<S141>/Logical Operator3'
   *  Logic: '<S142>/Logical Operator3'
   *  MinMax: '<S139>/MinMax1'
   *  MinMax: '<S140>/MinMax1'
   *  Switch: '<S138>/Switch4'
   *  Switch: '<S141>/Switch4'
   *  Switch: '<S142>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_IPU_DCC_1_State_EPT.VIPM_IPUDCCActOprtMode_enum =
    VIPM_IPUDCCActOprtMode_enum;
  AppSwcIpm_ARID_DEF.IPM_IPU_DCC_1_State_EPT.VIPM_IPUDCCActOprtModeVld_flg =
    VIPM_IPUDCCActOprtModeVld_flg;
  AppSwcIpm_ARID_DEF.IPM_IPU_DCC_1_State_EPT.VIPM_IPUDCCLoVoltActVolt_V =
    VIPM_IPUDCCLoVoltActVolt_V;
  AppSwcIpm_ARID_DEF.IPM_IPU_DCC_1_State_EPT.VIPM_IPUDCCLoVoltActVoltVld_flg =
    VIPM_IPUDCCLoVoltActVoltVld_flg;
  AppSwcIpm_ARID_DEF.IPM_IPU_DCC_1_State_EPT.VIPM_IPUDCCLoVoltActCurnt_A =
    VIPM_IPUDCCLoVoltActCurnt_A;
  AppSwcIpm_ARID_DEF.IPM_IPU_DCC_1_State_EPT.VIPM_IPUDCCLoVoltActCurntVld_flg =
    VIPM_IPUDCCLoVoltActCurntVld_flg;
  AppSwcIpm_ARID_DEF.IPM_IPU_DCC_1_State_EPT.VIPM_IPUDCCSysFailSta_enum =
    VIPM_IPUDCCSysFailSta_enum;
  AppSwcIpm_ARID_DEF.IPM_IPU_DCC_1_State_EPT.VIPM_IPUDCCSysFailStaVld_flg =
    VIPM_IPUDCCSysFailStaVld_flg;
  AppSwcIpm_ARID_DEF.IPM_IPU_DCC_1_State_EPT.VIPM_IPUHVILFailSt_flg =
    VIPM_IPUHVILFailSt_flg;
  AppSwcIpm_ARID_DEF.IPM_IPU_DCC_1_State_EPT.VIPM_IPUHVILFailStVld_flg =
    VIPM_IPUHVILFailStVld_flg;

  /* Outputs for Atomic SubSystem: '<S122>/Subsys_VIPM_IPUDCCHiVoltActCurnt_A' */
  /* Logic: '<S145>/Logical Operator3' incorporates:
   *  Constant: '<S145>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_IPUDCCHiVoltActCurntVld_flg = (KIPM_IPUDCCHiVoltActCurnt_A_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_DCDCMsgActv_flg);

  /* Switch: '<S145>/Switch4' incorporates:
   *  Constant: '<S145>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S145>/Switch'
   */
  if (KIPM_IPUDCCHiVoltActCurnt_A_ovrdflg) {
    /* MinMax: '<S57>/MinMax' incorporates:
     *  Constant: '<S145>/sat4'
     *  MinMax: '<S163>/MinMax'
     */
    VIPM_IPUOBCTempInt_C = KIPM_IPUDCCHiVoltActCurnt_A_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
             ->VIPM_DCDCMsgActv_flg) {
    /* Product: '<S147>/Product' incorporates:
     *  Constant: '<S147>/Constant'
     *  Inport: '<Root>/IPU_DCC_2_ChrgInValue_EPT'
     *  Switch: '<S145>/Switch'
     */
    rtb_Product_l3f = (float32)
      (Rte_IRead_Runbl_IpmCanRx_100ms_IPU_DCC_2_ChrgInValue_EPT_IPU_DCC_2_ChrgInValue_EPT
       ())->IPU_DCC_HighVoltActlCur * 0.1F;

    /* MinMax: '<S57>/MinMax' incorporates:
     *  MinMax: '<S163>/MinMax'
     *  Sum: '<S147>/Add'
     *  Switch: '<S145>/Switch'
     */
    VIPM_IPUOBCTempInt_C = rtb_Product_l3f - 25.6F;
  } else {
    /* MinMax: '<S57>/MinMax' incorporates:
     *  Constant: '<S145>/sat5'
     *  MinMax: '<S163>/MinMax'
     *  Switch: '<S145>/Switch'
     */
    VIPM_IPUOBCTempInt_C = KIPM_IPUDCCHiVoltActCurntDflt_A;
  }

  /* End of Switch: '<S145>/Switch4' */

  /* MinMax: '<S145>/MinMax' incorporates:
   *  Constant: '<S145>/sat6'
   */
  if (VIPM_IPUOBCTempInt_C > KIPM_IPUDCCHiVoltActCurntHi_A) {
    /* MinMax: '<S57>/MinMax' */
    VIPM_IPUOBCTempInt_C = KIPM_IPUDCCHiVoltActCurntHi_A;
  }

  /* End of MinMax: '<S145>/MinMax' */

  /* MinMax: '<S145>/MinMax1' incorporates:
   *  Constant: '<S145>/sat7'
   */
  if (VIPM_IPUOBCTempInt_C >= KIPM_IPUDCCHiVoltActCurntLo_A) {
    /* MinMax: '<S145>/MinMax1' */
    VIPM_IPUDCCHiVoltActCurnt_A = VIPM_IPUOBCTempInt_C;
  } else {
    /* MinMax: '<S145>/MinMax1' */
    VIPM_IPUDCCHiVoltActCurnt_A = KIPM_IPUDCCHiVoltActCurntLo_A;
  }

  /* End of MinMax: '<S145>/MinMax1' */
  /* End of Outputs for SubSystem: '<S122>/Subsys_VIPM_IPUDCCHiVoltActCurnt_A' */

  /* Outputs for Atomic SubSystem: '<S122>/Subsys_VIPM_IPUDCCHiVoltActVolt_V' */
  /* Logic: '<S146>/Logical Operator3' incorporates:
   *  Constant: '<S146>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_IPUDCCHiVoltActVoltVld_flg = (KIPM_IPUDCCHiVoltActVolt_V_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_DCDCMsgActv_flg);

  /* Switch: '<S146>/Switch4' incorporates:
   *  Constant: '<S146>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S146>/Switch'
   */
  if (KIPM_IPUDCCHiVoltActVolt_V_ovrdflg) {
    /* MinMax: '<S57>/MinMax' incorporates:
     *  Constant: '<S146>/sat4'
     *  MinMax: '<S163>/MinMax'
     */
    VIPM_IPUOBCTempInt_C = KIPM_IPUDCCHiVoltActVolt_V_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
             ->VIPM_DCDCMsgActv_flg) {
    /* MinMax: '<S57>/MinMax' incorporates:
     *  Constant: '<S148>/Constant'
     *  Inport: '<Root>/IPU_DCC_2_ChrgInValue_EPT'
     *  MinMax: '<S163>/MinMax'
     *  Product: '<S148>/Product'
     *  Switch: '<S146>/Switch'
     */
    VIPM_IPUOBCTempInt_C = (float32)
      (Rte_IRead_Runbl_IpmCanRx_100ms_IPU_DCC_2_ChrgInValue_EPT_IPU_DCC_2_ChrgInValue_EPT
       ())->IPU_DCC_HighVoltActlVol * 0.5F;
  } else {
    /* MinMax: '<S57>/MinMax' incorporates:
     *  Constant: '<S146>/sat5'
     *  MinMax: '<S163>/MinMax'
     *  Switch: '<S146>/Switch'
     */
    VIPM_IPUOBCTempInt_C = KIPM_IPUDCCHiVoltActVoltDflt_V;
  }

  /* End of Switch: '<S146>/Switch4' */

  /* MinMax: '<S146>/MinMax' incorporates:
   *  Constant: '<S146>/sat6'
   */
  if (VIPM_IPUOBCTempInt_C > KIPM_IPUDCCHiVoltActVoltHi_V) {
    /* MinMax: '<S57>/MinMax' */
    VIPM_IPUOBCTempInt_C = KIPM_IPUDCCHiVoltActVoltHi_V;
  }

  /* End of MinMax: '<S146>/MinMax' */

  /* MinMax: '<S146>/MinMax1' incorporates:
   *  Constant: '<S146>/sat7'
   */
  if (VIPM_IPUOBCTempInt_C >= KIPM_IPUDCCHiVoltActVoltLo_V) {
    /* MinMax: '<S146>/MinMax1' */
    VIPM_IPUDCCHiVoltActVolt_V = VIPM_IPUOBCTempInt_C;
  } else {
    /* MinMax: '<S146>/MinMax1' */
    VIPM_IPUDCCHiVoltActVolt_V = KIPM_IPUDCCHiVoltActVoltLo_V;
  }

  /* End of MinMax: '<S146>/MinMax1' */
  /* End of Outputs for SubSystem: '<S122>/Subsys_VIPM_IPUDCCHiVoltActVolt_V' */

  /* BusCreator: '<S122>/BusCreator' incorporates:
   *  Logic: '<S145>/Logical Operator3'
   *  Logic: '<S146>/Logical Operator3'
   *  MinMax: '<S145>/MinMax1'
   *  MinMax: '<S146>/MinMax1'
   */
  AppSwcIpm_ARID_DEF.IPM_IPU_DCC_2_ChrgInValue_EPT.VIPM_IPUDCCHiVoltActCurnt_A =
    VIPM_IPUDCCHiVoltActCurnt_A;
  AppSwcIpm_ARID_DEF.IPM_IPU_DCC_2_ChrgInValue_EPT.VIPM_IPUDCCHiVoltActCurntVld_flg
    = VIPM_IPUDCCHiVoltActCurntVld_flg;
  AppSwcIpm_ARID_DEF.IPM_IPU_DCC_2_ChrgInValue_EPT.VIPM_IPUDCCHiVoltActVolt_V =
    VIPM_IPUDCCHiVoltActVolt_V;
  AppSwcIpm_ARID_DEF.IPM_IPU_DCC_2_ChrgInValue_EPT.VIPM_IPUDCCHiVoltActVoltVld_flg
    = VIPM_IPUDCCHiVoltActVoltVld_flg;

  /* Outputs for Atomic SubSystem: '<S123>/Subsys_VIPM_IPUOBCReq_enum' */
  /* Logic: '<S155>/Logical Operator3' incorporates:
   *  Constant: '<S155>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_IPUOBCReqVld_flg = (KIPM_IPUOBCReq_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_OBCMsgActv_flg);

  /* Switch: '<S155>/Switch4' incorporates:
   *  Constant: '<S155>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S155>/Switch'
   */
  if (KIPM_IPUOBCReq_enum_ovrdflg) {
    /* Switch: '<S155>/Switch4' incorporates:
     *  Constant: '<S155>/sat4'
     */
    VIPM_IPUOBCReq_enum = KIPM_IPUOBCReq_enum_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
             ->VIPM_OBCMsgActv_flg) {
    /* Switch: '<S155>/Switch4' incorporates:
     *  DataTypeConversion: '<S155>/Data Type Conversion2'
     *  Inport: '<Root>/IPU_OBC_1_State_EPT'
     *  Switch: '<S155>/Switch'
     */
    VIPM_IPUOBCReq_enum =
      (Rte_IRead_Runbl_IpmCanRx_100ms_IPU_OBC_1_State_EPT_IPU_OBC_1_State_EPT()
      )->IPU_OBC_Request;
  } else {
    /* Switch: '<S155>/Switch4' incorporates:
     *  Constant: '<S155>/sat5'
     *  Switch: '<S155>/Switch'
     */
    VIPM_IPUOBCReq_enum = KIPM_IPUOBCReqDflt_enum;
  }

  /* End of Switch: '<S155>/Switch4' */
  /* End of Outputs for SubSystem: '<S123>/Subsys_VIPM_IPUOBCReq_enum' */

  /* Outputs for Atomic SubSystem: '<S123>/Subsys_VIPM_IPUOBCSysFailSta_enum' */
  /* Logic: '<S156>/Logical Operator3' incorporates:
   *  Constant: '<S156>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_IPUOBCSysFailStaVld_flg = (KIPM_IPUOBCSysFailSta_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_OBCMsgActv_flg);

  /* Switch: '<S156>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_OBCMsgActv_flg) {
    /* Switch: '<S156>/Switch' incorporates:
     *  Inport: '<Root>/IPU_OBC_1_State_EPT'
     *  Switch: '<S156>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_mu =
      (Rte_IRead_Runbl_IpmCanRx_100ms_IPU_OBC_1_State_EPT_IPU_OBC_1_State_EPT()
      )->IPU_OBC_SysFailSta;
  } else {
    /* Switch: '<S156>/Switch' incorporates:
     *  Constant: '<S156>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_mu = KIPM_IPUOBCSysFailStaDflt_enum;
  }

  /* End of Switch: '<S156>/Switch' */

  /* Switch: '<S156>/Switch4' incorporates:
   *  Constant: '<S156>/sat3'
   */
  if (KIPM_IPUOBCSysFailSta_enum_ovrdflg) {
    /* Switch: '<S156>/Switch4' incorporates:
     *  Constant: '<S156>/sat4'
     */
    VIPM_IPUOBCSysFailSta_enum = KIPM_IPUOBCSysFailSta_enum_ovrdval;
  } else {
    /* Switch: '<S156>/Switch4' */
    VIPM_IPUOBCSysFailSta_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_mu;
  }

  /* End of Switch: '<S156>/Switch4' */
  /* End of Outputs for SubSystem: '<S123>/Subsys_VIPM_IPUOBCSysFailSta_enum' */

  /* Outputs for Atomic SubSystem: '<S123>/Subsys_VIPM_IPUOBCConnectMainSta_flg' */
  /* Logic: '<S150>/Logical Operator3' incorporates:
   *  Constant: '<S150>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_IPUOBCConnectMainStaVld_flg = (KIPM_IPUOBCConnectMainSta_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_OBCMsgActv_flg);

  /* Switch: '<S150>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_OBCMsgActv_flg) {
    /* Switch: '<S150>/Switch' incorporates:
     *  Inport: '<Root>/IPU_OBC_1_State_EPT'
     *  Switch: '<S150>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_f1x =
      (Rte_IRead_Runbl_IpmCanRx_100ms_IPU_OBC_1_State_EPT_IPU_OBC_1_State_EPT()
      )->IPU_OBC_ConnectMainSta;
  } else {
    /* Switch: '<S150>/Switch' incorporates:
     *  Constant: '<S150>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_f1x = KIPM_IPUOBCConnectMainStaDflt_flg;
  }

  /* End of Switch: '<S150>/Switch' */

  /* Switch: '<S150>/Switch4' incorporates:
   *  Constant: '<S150>/sat3'
   */
  if (KIPM_IPUOBCConnectMainSta_flg_ovrdflg) {
    /* Switch: '<S150>/Switch4' incorporates:
     *  Constant: '<S150>/sat4'
     */
    VIPM_IPUOBCConnectMainSta_flg = KIPM_IPUOBCConnectMainSta_flg_ovrdval;
  } else {
    /* Switch: '<S150>/Switch4' */
    VIPM_IPUOBCConnectMainSta_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_f1x;
  }

  /* End of Switch: '<S150>/Switch4' */
  /* End of Outputs for SubSystem: '<S123>/Subsys_VIPM_IPUOBCConnectMainSta_flg' */

  /* Outputs for Atomic SubSystem: '<S123>/Subsys_VIPM_IPUOBCActOprtMode_enum' */
  /* Logic: '<S149>/Logical Operator3' incorporates:
   *  Constant: '<S149>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_IPUOBCActOprtModeVld_flg = (KIPM_IPUOBCActOprtMode_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_OBCMsgActv_flg);

  /* Switch: '<S149>/Switch4' incorporates:
   *  Constant: '<S149>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S149>/Switch'
   */
  if (KIPM_IPUOBCActOprtMode_enum_ovrdflg) {
    /* Switch: '<S149>/Switch4' incorporates:
     *  Constant: '<S149>/sat4'
     */
    VIPM_IPUOBCActOprtMode_enum = KIPM_IPUOBCActOprtMode_enum_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
             ->VIPM_OBCMsgActv_flg) {
    /* Switch: '<S149>/Switch4' incorporates:
     *  DataTypeConversion: '<S149>/Data Type Conversion2'
     *  Inport: '<Root>/IPU_OBC_1_State_EPT'
     *  Switch: '<S149>/Switch'
     */
    VIPM_IPUOBCActOprtMode_enum =
      (Rte_IRead_Runbl_IpmCanRx_100ms_IPU_OBC_1_State_EPT_IPU_OBC_1_State_EPT()
      )->IPU_OBC_ActlOprtMode;
  } else {
    /* Switch: '<S149>/Switch4' incorporates:
     *  Constant: '<S149>/sat5'
     *  Switch: '<S149>/Switch'
     */
    VIPM_IPUOBCActOprtMode_enum = KIPM_IPUOBCActOprtModeDflt_enum;
  }

  /* End of Switch: '<S149>/Switch4' */
  /* End of Outputs for SubSystem: '<S123>/Subsys_VIPM_IPUOBCActOprtMode_enum' */

  /* Outputs for Atomic SubSystem: '<S123>/Subsys_VIPM_IPUOBCInletConnectSta_enum' */
  /* Logic: '<S154>/Logical Operator3' incorporates:
   *  Constant: '<S154>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_IPUOBCInletConnectStaVld_flg = (KIPM_IPUOBCInletConnectSta_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_OBCMsgActv_flg);

  /* Switch: '<S154>/Switch4' incorporates:
   *  Constant: '<S154>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S154>/Switch'
   */
  if (KIPM_IPUOBCInletConnectSta_enum_ovrdflg) {
    /* Switch: '<S154>/Switch4' incorporates:
     *  Constant: '<S154>/sat4'
     */
    VIPM_IPUOBCInletConnectSta_enum = KIPM_IPUOBCInletConnectSta_enum_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
             ->VIPM_OBCMsgActv_flg) {
    /* Switch: '<S154>/Switch4' incorporates:
     *  DataTypeConversion: '<S154>/Data Type Conversion2'
     *  Inport: '<Root>/IPU_OBC_1_State_EPT'
     *  Switch: '<S154>/Switch'
     */
    VIPM_IPUOBCInletConnectSta_enum =
      (Rte_IRead_Runbl_IpmCanRx_100ms_IPU_OBC_1_State_EPT_IPU_OBC_1_State_EPT()
      )->IPU_OBC_InletConnctSta;
  } else {
    /* Switch: '<S154>/Switch4' incorporates:
     *  Constant: '<S154>/sat5'
     *  Switch: '<S154>/Switch'
     */
    VIPM_IPUOBCInletConnectSta_enum = KIPM_IPUOBCInletConnectStaDflt_enum;
  }

  /* End of Switch: '<S154>/Switch4' */
  /* End of Outputs for SubSystem: '<S123>/Subsys_VIPM_IPUOBCInletConnectSta_enum' */

  /* Outputs for Atomic SubSystem: '<S123>/Subsys_VIPM_IPUOBCHVDCActCur_A' */
  /* Logic: '<S151>/Logical Operator3' incorporates:
   *  Constant: '<S151>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_IPUOBCHVDCActCurVld_flg = (KIPM_IPUOBCHVDCActCur_A_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_OBCMsgActv_flg);

  /* Switch: '<S151>/Switch4' incorporates:
   *  Constant: '<S151>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S151>/Switch'
   */
  if (KIPM_IPUOBCHVDCActCur_A_ovrdflg) {
    /* MinMax: '<S57>/MinMax' incorporates:
     *  Constant: '<S151>/sat4'
     *  MinMax: '<S163>/MinMax'
     */
    VIPM_IPUOBCTempInt_C = KIPM_IPUOBCHVDCActCur_A_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
             ->VIPM_OBCMsgActv_flg) {
    /* Product: '<S157>/Product' incorporates:
     *  Inport: '<Root>/IPU_OBC_1_State_EPT'
     *  Switch: '<S151>/Switch'
     */
    rtb_Product_mh =
      (Rte_IRead_Runbl_IpmCanRx_100ms_IPU_OBC_1_State_EPT_IPU_OBC_1_State_EPT()
      )->IPU_OBC_HVDC_ActlCur;

    /* MinMax: '<S57>/MinMax' incorporates:
     *  MinMax: '<S163>/MinMax'
     *  Sum: '<S157>/Add'
     *  Switch: '<S151>/Switch'
     */
    VIPM_IPUOBCTempInt_C = (float32)rtb_Product_mh - 64.0F;
  } else {
    /* MinMax: '<S57>/MinMax' incorporates:
     *  Constant: '<S151>/sat5'
     *  MinMax: '<S163>/MinMax'
     *  Switch: '<S151>/Switch'
     */
    VIPM_IPUOBCTempInt_C = KIPM_IPUOBCHVDCActCurDflt_A;
  }

  /* End of Switch: '<S151>/Switch4' */

  /* MinMax: '<S151>/MinMax' incorporates:
   *  Constant: '<S151>/sat6'
   */
  if (VIPM_IPUOBCTempInt_C > KIPM_IPUOBCHVDCActCurHi_A) {
    /* MinMax: '<S57>/MinMax' */
    VIPM_IPUOBCTempInt_C = KIPM_IPUOBCHVDCActCurHi_A;
  }

  /* End of MinMax: '<S151>/MinMax' */

  /* MinMax: '<S151>/MinMax1' incorporates:
   *  Constant: '<S151>/sat7'
   */
  if (VIPM_IPUOBCTempInt_C >= KIPM_IPUOBCHVDCActCurLo_A) {
    /* MinMax: '<S151>/MinMax1' */
    VIPM_IPUOBCHVDCActCur_A = VIPM_IPUOBCTempInt_C;
  } else {
    /* MinMax: '<S151>/MinMax1' */
    VIPM_IPUOBCHVDCActCur_A = KIPM_IPUOBCHVDCActCurLo_A;
  }

  /* End of MinMax: '<S151>/MinMax1' */
  /* End of Outputs for SubSystem: '<S123>/Subsys_VIPM_IPUOBCHVDCActCur_A' */

  /* Outputs for Atomic SubSystem: '<S123>/Subsys_VIPM_IPUOBCHVDCActVol_V' */
  /* Logic: '<S152>/Logical Operator3' incorporates:
   *  Constant: '<S152>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_IPUOBCHVDCActVolVld_flg = (KIPM_IPUOBCHVDCActVol_V_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_OBCMsgActv_flg);

  /* Switch: '<S152>/Switch4' incorporates:
   *  Constant: '<S152>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S152>/Switch'
   */
  if (KIPM_IPUOBCHVDCActVol_V_ovrdflg) {
    /* MinMax: '<S57>/MinMax' incorporates:
     *  Constant: '<S152>/sat4'
     *  MinMax: '<S163>/MinMax'
     */
    VIPM_IPUOBCTempInt_C = KIPM_IPUOBCHVDCActVol_V_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
             ->VIPM_OBCMsgActv_flg) {
    /* MinMax: '<S57>/MinMax' incorporates:
     *  DataTypeConversion: '<S152>/Data Type Conversion2'
     *  Inport: '<Root>/IPU_OBC_1_State_EPT'
     *  MinMax: '<S163>/MinMax'
     *  Switch: '<S152>/Switch'
     */
    VIPM_IPUOBCTempInt_C = (float32)
      (Rte_IRead_Runbl_IpmCanRx_100ms_IPU_OBC_1_State_EPT_IPU_OBC_1_State_EPT()
      )->IPU_OBC_HVDC_ActlVol;
  } else {
    /* MinMax: '<S57>/MinMax' incorporates:
     *  Constant: '<S152>/sat5'
     *  MinMax: '<S163>/MinMax'
     *  Switch: '<S152>/Switch'
     */
    VIPM_IPUOBCTempInt_C = KIPM_IPUOBCHVDCActVolDflt_V;
  }

  /* End of Switch: '<S152>/Switch4' */

  /* MinMax: '<S152>/MinMax' incorporates:
   *  Constant: '<S152>/sat6'
   */
  if (VIPM_IPUOBCTempInt_C > KIPM_IPUOBCHVDCActVolHi_V) {
    /* MinMax: '<S57>/MinMax' */
    VIPM_IPUOBCTempInt_C = KIPM_IPUOBCHVDCActVolHi_V;
  }

  /* End of MinMax: '<S152>/MinMax' */

  /* MinMax: '<S152>/MinMax1' incorporates:
   *  Constant: '<S152>/sat7'
   */
  if (VIPM_IPUOBCTempInt_C >= KIPM_IPUOBCHVDCActVolLo_V) {
    /* MinMax: '<S152>/MinMax1' */
    VIPM_IPUOBCHVDCActVol_V = VIPM_IPUOBCTempInt_C;
  } else {
    /* MinMax: '<S152>/MinMax1' */
    VIPM_IPUOBCHVDCActVol_V = KIPM_IPUOBCHVDCActVolLo_V;
  }

  /* End of MinMax: '<S152>/MinMax1' */
  /* End of Outputs for SubSystem: '<S123>/Subsys_VIPM_IPUOBCHVDCActVol_V' */

  /* Outputs for Atomic SubSystem: '<S123>/Subsys_VIPM_IPUOBCInletActPwr_kW' */
  /* Logic: '<S153>/Logical Operator3' incorporates:
   *  Constant: '<S153>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_IPUOBCInletActPwrVld_flg = (KIPM_IPUOBCInletActPwr_kW_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_OBCMsgActv_flg);

  /* Switch: '<S153>/Switch4' incorporates:
   *  Constant: '<S153>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S153>/Switch'
   */
  if (KIPM_IPUOBCInletActPwr_kW_ovrdflg) {
    /* MinMax: '<S57>/MinMax' incorporates:
     *  Constant: '<S153>/sat4'
     *  MinMax: '<S163>/MinMax'
     */
    VIPM_IPUOBCTempInt_C = KIPM_IPUOBCInletActPwr_kW_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
             ->VIPM_OBCMsgActv_flg) {
    /* Product: '<S158>/Product' incorporates:
     *  Constant: '<S158>/Constant'
     *  Inport: '<Root>/IPU_OBC_1_State_EPT'
     *  Switch: '<S153>/Switch'
     */
    rtb_Product_l3f = (float32)
      (Rte_IRead_Runbl_IpmCanRx_100ms_IPU_OBC_1_State_EPT_IPU_OBC_1_State_EPT()
      )->IPU_OBC_InleltActlPower * 0.1F;

    /* MinMax: '<S57>/MinMax' incorporates:
     *  MinMax: '<S163>/MinMax'
     *  Sum: '<S158>/Add'
     *  Switch: '<S153>/Switch'
     */
    VIPM_IPUOBCTempInt_C = rtb_Product_l3f - 25.6F;
  } else {
    /* MinMax: '<S57>/MinMax' incorporates:
     *  Constant: '<S153>/sat5'
     *  MinMax: '<S163>/MinMax'
     *  Switch: '<S153>/Switch'
     */
    VIPM_IPUOBCTempInt_C = KIPM_IPUOBCInletActPwrDflt_kW;
  }

  /* End of Switch: '<S153>/Switch4' */

  /* MinMax: '<S153>/MinMax' incorporates:
   *  Constant: '<S153>/sat6'
   */
  if (VIPM_IPUOBCTempInt_C > KIPM_IPUOBCInletActPwrHi_kW) {
    /* MinMax: '<S57>/MinMax' */
    VIPM_IPUOBCTempInt_C = KIPM_IPUOBCInletActPwrHi_kW;
  }

  /* End of MinMax: '<S153>/MinMax' */

  /* MinMax: '<S153>/MinMax1' incorporates:
   *  Constant: '<S153>/sat7'
   */
  if (VIPM_IPUOBCTempInt_C >= KIPM_IPUOBCInletActPwrLo_kW) {
    /* MinMax: '<S153>/MinMax1' */
    VIPM_IPUOBCInletActPwr_kW = VIPM_IPUOBCTempInt_C;
  } else {
    /* MinMax: '<S153>/MinMax1' */
    VIPM_IPUOBCInletActPwr_kW = KIPM_IPUOBCInletActPwrLo_kW;
  }

  /* End of MinMax: '<S153>/MinMax1' */
  /* End of Outputs for SubSystem: '<S123>/Subsys_VIPM_IPUOBCInletActPwr_kW' */

  /* BusCreator: '<S123>/BusCreator' incorporates:
   *  DataTypeConversion: '<S123>/Data Type Conversion'
   *  DataTypeConversion: '<S123>/Data Type Conversion1'
   *  DataTypeConversion: '<S123>/Data Type Conversion2'
   *  Logic: '<S149>/Logical Operator3'
   *  Logic: '<S150>/Logical Operator3'
   *  Logic: '<S151>/Logical Operator3'
   *  Logic: '<S152>/Logical Operator3'
   *  Logic: '<S153>/Logical Operator3'
   *  Logic: '<S154>/Logical Operator3'
   *  Logic: '<S155>/Logical Operator3'
   *  Logic: '<S156>/Logical Operator3'
   *  MinMax: '<S151>/MinMax1'
   *  MinMax: '<S152>/MinMax1'
   *  MinMax: '<S153>/MinMax1'
   *  Switch: '<S149>/Switch4'
   *  Switch: '<S150>/Switch4'
   *  Switch: '<S154>/Switch4'
   *  Switch: '<S155>/Switch4'
   *  Switch: '<S156>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_1_State_EPT.VIPM_IPUOBCReq_enum =
    VIPM_IPUOBCReq_enum;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_1_State_EPT.VIPM_IPUOBCReqVld_flg =
    VIPM_IPUOBCReqVld_flg;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_1_State_EPT.VIPM_IPUOBCSysFailSta_enum =
    VIPM_IPUOBCSysFailSta_enum;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_1_State_EPT.VIPM_IPUOBCSysFailStaVld_flg =
    VIPM_IPUOBCSysFailStaVld_flg;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_1_State_EPT.VIPM_IPUOBCConnectMainSta_flg =
    VIPM_IPUOBCConnectMainSta_flg;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_1_State_EPT.VIPM_IPUOBCConnectMainStaVld_flg =
    VIPM_IPUOBCConnectMainStaVld_flg;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_1_State_EPT.VIPM_IPUOBCActOprtMode_enum =
    VIPM_IPUOBCActOprtMode_enum;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_1_State_EPT.VIPM_IPUOBCActOprtModeVld_flg =
    VIPM_IPUOBCActOprtModeVld_flg;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_1_State_EPT.VIPM_IPUOBCInletConnectSta_enum =
    VIPM_IPUOBCInletConnectSta_enum;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_1_State_EPT.VIPM_IPUOBCInletConnectStaVld_flg =
    VIPM_IPUOBCInletConnectStaVld_flg;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_1_State_EPT.VIPM_IPUOBCHVDCActCur_A =
    VIPM_IPUOBCHVDCActCur_A;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_1_State_EPT.VIPM_IPUOBCHVDCActCurVld_flg =
    VIPM_IPUOBCHVDCActCurVld_flg;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_1_State_EPT.VIPM_IPUOBCHVDCActVol_V =
    VIPM_IPUOBCHVDCActVol_V;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_1_State_EPT.VIPM_IPUOBCHVDCActVolVld_flg =
    VIPM_IPUOBCHVDCActVolVld_flg;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_1_State_EPT.VIPM_IPUOBCInletActPwr_kW =
    VIPM_IPUOBCInletActPwr_kW;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_1_State_EPT.VIPM_IPUOBCInletActPwrVld_flg =
    VIPM_IPUOBCInletActPwrVld_flg;

  /* Outputs for Atomic SubSystem: '<S159>/Subsys_VIPM_IPUOBCWakeUpMode_enum' */
  /* Logic: '<S164>/Logical Operator3' incorporates:
   *  Constant: '<S164>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_IPUOBCWakeUpModeVld_flg = (KIPM_IPUOBCWakeUpMode_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_OBCMsgActv_flg);

  /* Switch: '<S164>/Switch4' incorporates:
   *  Constant: '<S164>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S164>/Switch'
   */
  if (KIPM_IPUOBCWakeUpMode_enum_ovrdflg) {
    /* Switch: '<S164>/Switch4' incorporates:
     *  Constant: '<S164>/sat4'
     */
    VIPM_IPUOBCWakeUpMode_enum = KIPM_IPUOBCWakeUpMode_enum_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
             ->VIPM_OBCMsgActv_flg) {
    /* Switch: '<S164>/Switch4' incorporates:
     *  DataTypeConversion: '<S164>/Data Type Conversion2'
     *  Inport: '<Root>/IPU_OBC_2_Inlet_EPT'
     *  Switch: '<S164>/Switch'
     */
    VIPM_IPUOBCWakeUpMode_enum =
      (Rte_IRead_Runbl_IpmCanRx_100ms_IPU_OBC_2_Inlet_EPT_IPU_OBC_2_Inlet_EPT()
      )->IPU_OBC_Wake_Up_Mode;
  } else {
    /* Switch: '<S164>/Switch4' incorporates:
     *  Constant: '<S164>/sat5'
     *  Switch: '<S164>/Switch'
     */
    VIPM_IPUOBCWakeUpMode_enum = KIPM_IPUOBCWakeUpModeDflt_enum;
  }

  /* End of Switch: '<S164>/Switch4' */
  /* End of Outputs for SubSystem: '<S159>/Subsys_VIPM_IPUOBCWakeUpMode_enum' */

  /* Outputs for Atomic SubSystem: '<S159>/Subsys_VIPM_IPUOBCS2State_flg' */
  /* Logic: '<S162>/Logical Operator3' incorporates:
   *  Constant: '<S162>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_IPUOBCS2StateVld_flg = (KIPM_IPUOBCS2State_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_OBCMsgActv_flg);

  /* Switch: '<S162>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_OBCMsgActv_flg) {
    /* Switch: '<S162>/Switch' incorporates:
     *  Inport: '<Root>/IPU_OBC_2_Inlet_EPT'
     *  Switch: '<S162>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_aj =
      (Rte_IRead_Runbl_IpmCanRx_100ms_IPU_OBC_2_Inlet_EPT_IPU_OBC_2_Inlet_EPT()
      )->IPU_OBC_S2_State;
  } else {
    /* Switch: '<S162>/Switch' incorporates:
     *  Constant: '<S162>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_aj = KIPM_IPUOBCS2StateDflt_flg;
  }

  /* End of Switch: '<S162>/Switch' */

  /* Switch: '<S162>/Switch4' incorporates:
   *  Constant: '<S162>/sat3'
   */
  if (KIPM_IPUOBCS2State_flg_ovrdflg) {
    /* Switch: '<S162>/Switch4' incorporates:
     *  Constant: '<S162>/sat4'
     */
    VIPM_IPUOBCS2State_flg = KIPM_IPUOBCS2State_flg_ovrdval;
  } else {
    /* Switch: '<S162>/Switch4' */
    VIPM_IPUOBCS2State_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_aj;
  }

  /* End of Switch: '<S162>/Switch4' */
  /* End of Outputs for SubSystem: '<S159>/Subsys_VIPM_IPUOBCS2State_flg' */

  /* Outputs for Atomic SubSystem: '<S159>/Subsys_VIPM_IPUOBCACMaxPwrAllow_kW' */
  /* Logic: '<S161>/Logical Operator3' incorporates:
   *  Constant: '<S161>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_IPUOBCACMaxPwrAllowVld_flg = (KIPM_IPUOBCACMaxPwrAllow_kW_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_OBCMsgActv_flg);

  /* Switch: '<S161>/Switch4' incorporates:
   *  Constant: '<S161>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S161>/Switch'
   */
  if (KIPM_IPUOBCACMaxPwrAllow_kW_ovrdflg) {
    /* MinMax: '<S57>/MinMax' incorporates:
     *  Constant: '<S161>/sat4'
     *  MinMax: '<S163>/MinMax'
     */
    VIPM_IPUOBCTempInt_C = KIPM_IPUOBCACMaxPwrAllow_kW_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
             ->VIPM_OBCMsgActv_flg) {
    /* Product: '<S165>/Product' incorporates:
     *  Constant: '<S165>/Constant'
     *  Inport: '<Root>/IPU_OBC_2_Inlet_EPT'
     *  Switch: '<S161>/Switch'
     */
    rtb_Product_l3f = (float32)
      (Rte_IRead_Runbl_IpmCanRx_100ms_IPU_OBC_2_Inlet_EPT_IPU_OBC_2_Inlet_EPT()
      )->IPU_OBC_ACMaxPwAllow * 0.2F;

    /* MinMax: '<S57>/MinMax' incorporates:
     *  MinMax: '<S163>/MinMax'
     *  Sum: '<S165>/Add'
     *  Switch: '<S161>/Switch'
     */
    VIPM_IPUOBCTempInt_C = rtb_Product_l3f - 102.4F;
  } else {
    /* MinMax: '<S57>/MinMax' incorporates:
     *  Constant: '<S161>/sat5'
     *  MinMax: '<S163>/MinMax'
     *  Switch: '<S161>/Switch'
     */
    VIPM_IPUOBCTempInt_C = KIPM_IPUOBCACMaxPwrAllowDflt_kW;
  }

  /* End of Switch: '<S161>/Switch4' */

  /* MinMax: '<S161>/MinMax' incorporates:
   *  Constant: '<S161>/sat6'
   */
  if (VIPM_IPUOBCTempInt_C > KIPM_IPUOBCACMaxPwrAllowHi_kW) {
    /* MinMax: '<S57>/MinMax' */
    VIPM_IPUOBCTempInt_C = KIPM_IPUOBCACMaxPwrAllowHi_kW;
  }

  /* End of MinMax: '<S161>/MinMax' */

  /* MinMax: '<S161>/MinMax1' incorporates:
   *  Constant: '<S161>/sat7'
   */
  if (VIPM_IPUOBCTempInt_C >= KIPM_IPUOBCACMaxPwrAllowLo_kW) {
    /* MinMax: '<S161>/MinMax1' */
    VIPM_IPUOBCACMaxPwrAllow_kW = VIPM_IPUOBCTempInt_C;
  } else {
    /* MinMax: '<S161>/MinMax1' */
    VIPM_IPUOBCACMaxPwrAllow_kW = KIPM_IPUOBCACMaxPwrAllowLo_kW;
  }

  /* End of MinMax: '<S161>/MinMax1' */
  /* End of Outputs for SubSystem: '<S159>/Subsys_VIPM_IPUOBCACMaxPwrAllow_kW' */

  /* Outputs for Atomic SubSystem: '<S159>/Subsys_VIPM_IPUDeviceIntTemp_C' */
  /* Logic: '<S160>/Logical Operator3' incorporates:
   *  Constant: '<S160>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_IPUDeviceIntTempVld_flg = (KIPM_IPUDeviceIntTemp_C_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_OBCMsgActv_flg);

  /* Switch: '<S160>/Switch4' incorporates:
   *  Constant: '<S160>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S160>/Switch'
   */
  if (KIPM_IPUDeviceIntTemp_C_ovrdflg) {
    /* MinMax: '<S57>/MinMax' incorporates:
     *  Constant: '<S160>/sat4'
     *  MinMax: '<S163>/MinMax'
     */
    VIPM_IPUOBCTempInt_C = KIPM_IPUDeviceIntTemp_C_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
             ->VIPM_OBCMsgActv_flg) {
    /* Product: '<S166>/Product' incorporates:
     *  Inport: '<Root>/IPU_OBC_2_Inlet_EPT'
     *  Switch: '<S160>/Switch'
     */
    rtb_Product_mh =
      (Rte_IRead_Runbl_IpmCanRx_100ms_IPU_OBC_2_Inlet_EPT_IPU_OBC_2_Inlet_EPT()
      )->IPU_DeviceIntTemp;

    /* MinMax: '<S57>/MinMax' incorporates:
     *  MinMax: '<S163>/MinMax'
     *  Sum: '<S166>/Add'
     *  Switch: '<S160>/Switch'
     */
    VIPM_IPUOBCTempInt_C = (float32)rtb_Product_mh - 40.0F;
  } else {
    /* MinMax: '<S57>/MinMax' incorporates:
     *  Constant: '<S160>/sat5'
     *  MinMax: '<S163>/MinMax'
     *  Switch: '<S160>/Switch'
     */
    VIPM_IPUOBCTempInt_C = KIPM_IPUDeviceIntTempDflt_C;
  }

  /* End of Switch: '<S160>/Switch4' */

  /* MinMax: '<S160>/MinMax' incorporates:
   *  Constant: '<S160>/sat6'
   */
  if (VIPM_IPUOBCTempInt_C > KIPM_IPUDeviceIntTempHi_C) {
    /* MinMax: '<S57>/MinMax' */
    VIPM_IPUOBCTempInt_C = KIPM_IPUDeviceIntTempHi_C;
  }

  /* End of MinMax: '<S160>/MinMax' */

  /* MinMax: '<S160>/MinMax1' incorporates:
   *  Constant: '<S160>/sat7'
   */
  if (VIPM_IPUOBCTempInt_C >= KIPM_IPUDeviceIntTempLo_C) {
    /* MinMax: '<S160>/MinMax1' */
    VIPM_IPUDeviceIntTemp_C = VIPM_IPUOBCTempInt_C;
  } else {
    /* MinMax: '<S160>/MinMax1' */
    VIPM_IPUDeviceIntTemp_C = KIPM_IPUDeviceIntTempLo_C;
  }

  /* End of MinMax: '<S160>/MinMax1' */
  /* End of Outputs for SubSystem: '<S159>/Subsys_VIPM_IPUDeviceIntTemp_C' */

  /* Outputs for Atomic SubSystem: '<S159>/Subsys_VIPM_IPUOBCTempInt_C' */
  /* Logic: '<S163>/Logical Operator3' incorporates:
   *  Constant: '<S163>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_IPUOBCTempIntVld_flg = (KIPM_IPUOBCTempInt_C_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_OBCMsgActv_flg);

  /* Switch: '<S163>/Switch4' incorporates:
   *  Constant: '<S163>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S163>/Switch'
   */
  if (KIPM_IPUOBCTempInt_C_ovrdflg) {
    /* MinMax: '<S57>/MinMax' incorporates:
     *  Constant: '<S163>/sat4'
     *  MinMax: '<S163>/MinMax'
     */
    VIPM_IPUOBCTempInt_C = KIPM_IPUOBCTempInt_C_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
             ->VIPM_OBCMsgActv_flg) {
    /* Product: '<S167>/Product' incorporates:
     *  Inport: '<Root>/IPU_OBC_2_Inlet_EPT'
     *  Switch: '<S163>/Switch'
     */
    rtb_Product_mh =
      (Rte_IRead_Runbl_IpmCanRx_100ms_IPU_OBC_2_Inlet_EPT_IPU_OBC_2_Inlet_EPT()
      )->IPU_OBC_TempInlet;

    /* MinMax: '<S57>/MinMax' incorporates:
     *  MinMax: '<S163>/MinMax'
     *  Sum: '<S167>/Add'
     *  Switch: '<S163>/Switch'
     */
    VIPM_IPUOBCTempInt_C = (float32)rtb_Product_mh - 40.0F;
  } else {
    /* MinMax: '<S57>/MinMax' incorporates:
     *  Constant: '<S163>/sat5'
     *  MinMax: '<S163>/MinMax'
     *  Switch: '<S163>/Switch'
     */
    VIPM_IPUOBCTempInt_C = KIPM_IPUOBCTempIntDflt_C;
  }

  /* End of Switch: '<S163>/Switch4' */

  /* MinMax: '<S163>/MinMax' incorporates:
   *  Constant: '<S163>/sat6'
   */
  if (VIPM_IPUOBCTempInt_C > KIPM_IPUOBCTempIntHi_C) {
    /* MinMax: '<S57>/MinMax' */
    VIPM_IPUOBCTempInt_C = KIPM_IPUOBCTempIntHi_C;
  }

  /* End of MinMax: '<S163>/MinMax' */

  /* MinMax: '<S163>/MinMax1' incorporates:
   *  Constant: '<S163>/sat7'
   */
  if (VIPM_IPUOBCTempInt_C < KIPM_IPUOBCTempIntLo_C) {
    /* MinMax: '<S57>/MinMax' incorporates:
     *  MinMax: '<S163>/MinMax1'
     */
    VIPM_IPUOBCTempInt_C = KIPM_IPUOBCTempIntLo_C;
  }

  /* End of MinMax: '<S163>/MinMax1' */
  /* End of Outputs for SubSystem: '<S159>/Subsys_VIPM_IPUOBCTempInt_C' */

  /* BusCreator: '<S159>/BusCreator' incorporates:
   *  DataTypeConversion: '<S159>/Data Type Conversion'
   *  Logic: '<S160>/Logical Operator3'
   *  Logic: '<S161>/Logical Operator3'
   *  Logic: '<S162>/Logical Operator3'
   *  Logic: '<S163>/Logical Operator3'
   *  Logic: '<S164>/Logical Operator3'
   *  MinMax: '<S160>/MinMax1'
   *  MinMax: '<S161>/MinMax1'
   *  MinMax: '<S163>/MinMax1'
   *  Switch: '<S162>/Switch4'
   *  Switch: '<S164>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_2_Inlet_EPT.VIPM_IPUOBCWakeUpMode_enum =
    VIPM_IPUOBCWakeUpMode_enum;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_2_Inlet_EPT.VIPM_IPUOBCWakeUpModeVld_flg =
    VIPM_IPUOBCWakeUpModeVld_flg;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_2_Inlet_EPT.VIPM_IPUOBCS2State_flg =
    VIPM_IPUOBCS2State_flg;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_2_Inlet_EPT.VIPM_IPUOBCS2StateVld_flg =
    VIPM_IPUOBCS2StateVld_flg;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_2_Inlet_EPT.VIPM_IPUOBCACMaxPwrAllow_kW =
    VIPM_IPUOBCACMaxPwrAllow_kW;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_2_Inlet_EPT.VIPM_IPUOBCACMaxPwrAllowVld_flg =
    VIPM_IPUOBCACMaxPwrAllowVld_flg;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_2_Inlet_EPT.VIPM_IPUDeviceIntTemp_C =
    VIPM_IPUDeviceIntTemp_C;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_2_Inlet_EPT.VIPM_IPUDeviceIntTempVld_flg =
    VIPM_IPUDeviceIntTempVld_flg;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_2_Inlet_EPT.VIPM_IPUOBCTempInt_C =
    VIPM_IPUOBCTempInt_C;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_2_Inlet_EPT.VIPM_IPUOBCTempIntVld_flg =
    VIPM_IPUOBCTempIntVld_flg;

  /* Outputs for Atomic SubSystem: '<S168>/Subsys_VIPM_BMSPackID_enum' */
  /* Logic: '<S170>/Logical Operator3' incorporates:
   *  Constant: '<S170>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSPackIDVld_flg = (KIPM_BMSPackID_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_BMSMsgActv_flg);

  /* Switch: '<S170>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_BMSMsgActv_flg) {
    /* Switch: '<S170>/Switch' incorporates:
     *  Inport: '<Root>/BMS_9_BattInfo_EPT'
     *  Switch: '<S170>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jhg =
      (Rte_IRead_Runbl_IpmCanRx_100ms_BMS_9_BattInfo_EPT_BMS_9_BattInfo_EPT())
      ->BMS_Pack_Identity;
  } else {
    /* Switch: '<S170>/Switch' incorporates:
     *  Constant: '<S170>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jhg = KIPM_BMSPackIDDflt_enum;
  }

  /* End of Switch: '<S170>/Switch' */

  /* Switch: '<S170>/Switch4' incorporates:
   *  Constant: '<S170>/sat3'
   */
  if (KIPM_BMSPackID_enum_ovrdflg) {
    /* Switch: '<S170>/Switch4' incorporates:
     *  Constant: '<S170>/sat4'
     */
    VIPM_BMSPackID_enum = KIPM_BMSPackID_enum_ovrdval;
  } else {
    /* Switch: '<S170>/Switch4' */
    VIPM_BMSPackID_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jhg;
  }

  /* End of Switch: '<S170>/Switch4' */
  /* End of Outputs for SubSystem: '<S168>/Subsys_VIPM_BMSPackID_enum' */

  /* Outputs for Atomic SubSystem: '<S168>/Subsys_VIPM_BMSBatCapcty_Ah' */
  /* Logic: '<S169>/Logical Operator3' incorporates:
   *  Constant: '<S169>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSBatCapctyVld_flg = (KIPM_BMSBatCapcty_Ah_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_BMSMsgActv_flg);

  /* Switch: '<S169>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_BMSMsgActv_flg) {
    /* Switch: '<S169>/Switch' incorporates:
     *  Inport: '<Root>/BMS_9_BattInfo_EPT'
     *  Switch: '<S169>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ol =
      (Rte_IRead_Runbl_IpmCanRx_100ms_BMS_9_BattInfo_EPT_BMS_9_BattInfo_EPT())
      ->BMS_BatCapacity;
  } else {
    /* Switch: '<S169>/Switch' incorporates:
     *  Constant: '<S169>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ol = KIPM_BMSBatCapctyDflt_Ah;
  }

  /* End of Switch: '<S169>/Switch' */

  /* Switch: '<S169>/Switch4' incorporates:
   *  Constant: '<S169>/sat3'
   */
  if (KIPM_BMSBatCapcty_Ah_ovrdflg) {
    /* Switch: '<S169>/Switch4' incorporates:
     *  Constant: '<S169>/sat4'
     */
    VIPM_BMSBatCapcty_Ah = KIPM_BMSBatCapcty_Ah_ovrdval;
  } else {
    /* Switch: '<S169>/Switch4' */
    VIPM_BMSBatCapcty_Ah = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ol;
  }

  /* End of Switch: '<S169>/Switch4' */
  /* End of Outputs for SubSystem: '<S168>/Subsys_VIPM_BMSBatCapcty_Ah' */

  /* BusCreator: '<S168>/BusCreator' incorporates:
   *  Logic: '<S169>/Logical Operator3'
   *  Logic: '<S170>/Logical Operator3'
   *  Switch: '<S169>/Switch4'
   *  Switch: '<S170>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_BMS_9_BattInfo_EPT.VIPM_BMSPackID_enum =
    VIPM_BMSPackID_enum;
  AppSwcIpm_ARID_DEF.IPM_BMS_9_BattInfo_EPT.VIPM_BMSPackIDVld_flg =
    VIPM_BMSPackIDVld_flg;
  AppSwcIpm_ARID_DEF.IPM_BMS_9_BattInfo_EPT.VIPM_BMSBatCapcty_Ah =
    VIPM_BMSBatCapcty_Ah;
  AppSwcIpm_ARID_DEF.IPM_BMS_9_BattInfo_EPT.VIPM_BMSBatCapctyVld_flg =
    VIPM_BMSBatCapctyVld_flg;
}

/* Output and update for function-call system: '<Root>/Ipm10ms' */
static void Runbl_Ipm10ms(void)
{
  sint32 rtb_Product_i4;
  float32 rtb_Product_dq;
  boolean rtb_LogicalOperator2_mn;

  /* Outputs for Atomic SubSystem: '<S173>/Subsys_VIPM_EHBEPBDynAppSt_enum' */
  /* Logic: '<S182>/Logical Operator3' incorporates:
   *  Constant: '<S182>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_EHBEPBDynAppStVld_flg = (KIPM_EHBEPBDynAppSt_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_EHBMsgActv_flg);

  /* Switch: '<S182>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_EHBMsgActv_flg) {
    /* Switch: '<S182>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_EHB_B_CRCFlt_flg) {
      /* Switch: '<S182>/Switch' incorporates:
       *  Inport: '<Root>/EHB_B_CHA'
       *  Switch: '<S182>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_i =
        (Rte_IRead_Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA())
        ->EHB_EPB_DynamicApplySta;
    }

    /* End of Switch: '<S182>/Switch3' */
  } else {
    /* Switch: '<S182>/Switch' incorporates:
     *  Constant: '<S182>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_i = KIPM_EHBEPBDynAppStDflt_enum;
  }

  /* End of Switch: '<S182>/Switch' */

  /* Switch: '<S182>/Switch4' incorporates:
   *  Constant: '<S182>/sat3'
   */
  if (KIPM_EHBEPBDynAppSt_enum_ovrdflg) {
    /* Switch: '<S182>/Switch4' incorporates:
     *  Constant: '<S182>/sat4'
     */
    VIPM_EHBEPBDynAppSt_enum = KIPM_EHBEPBDynAppSt_enum_ovrdval;
  } else {
    /* Switch: '<S182>/Switch4' */
    VIPM_EHBEPBDynAppSt_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_i;
  }

  /* End of Switch: '<S182>/Switch4' */
  /* End of Outputs for SubSystem: '<S173>/Subsys_VIPM_EHBEPBDynAppSt_enum' */

  /* Outputs for Atomic SubSystem: '<S173>/Subsys_VIPM_EHBBrkPedlValPerc_pct' */
  /* Logic: '<S199>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/EHB_B_CHA'
   *  Logic: '<S177>/Logical Operator2'
   */
  rtb_LogicalOperator2_mn = ((Rte_IRead_Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA())
    ->EHB_BrkPedlValPercVld &&
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_EHBMsgActv_flg);

  /* Logic: '<S177>/Logical Operator3' incorporates:
   *  Constant: '<S177>/sat3'
   */
  VIPM_EHBBrkPedlValPercVld_flg = (KIPM_EHBBrkPedlValPerc_pct_ovrdflg ||
    rtb_LogicalOperator2_mn);

  /* Switch: '<S177>/Switch' */
  if (rtb_LogicalOperator2_mn) {
    /* Switch: '<S177>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_EHB_B_CRCFlt_flg) {
      /* Switch: '<S177>/Switch' incorporates:
       *  DataTypeConversion: '<S177>/Data Type Conversion2'
       *  Inport: '<Root>/EHB_B_CHA'
       *  Switch: '<S177>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jg =
        (Rte_IRead_Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA())
        ->EHB_BrkPedlValPerc;
    }

    /* End of Switch: '<S177>/Switch3' */
  } else {
    /* Switch: '<S177>/Switch' incorporates:
     *  Constant: '<S177>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jg = KIPM_EHBBrkPedlValPercDflt_pct;
  }

  /* End of Switch: '<S177>/Switch' */

  /* Switch: '<S177>/Switch4' incorporates:
   *  Constant: '<S177>/sat3'
   *  Constant: '<S177>/sat4'
   */
  if (KIPM_EHBBrkPedlValPerc_pct_ovrdflg) {
    VIPM_EHBBrkPedlValPerc_pct = KIPM_EHBBrkPedlValPerc_pct_ovrdval;
  } else {
    VIPM_EHBBrkPedlValPerc_pct = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jg;
  }

  /* MinMax: '<S177>/MinMax' incorporates:
   *  Constant: '<S177>/sat6'
   *  Switch: '<S177>/Switch4'
   */
  if (VIPM_EHBBrkPedlValPerc_pct > KIPM_EHBBrkPedlValPercHi_pct) {
    VIPM_EHBBrkPedlValPerc_pct = KIPM_EHBBrkPedlValPercHi_pct;
  }

  /* End of MinMax: '<S177>/MinMax' */

  /* MinMax: '<S177>/MinMax1' incorporates:
   *  Constant: '<S177>/sat7'
   */
  if (VIPM_EHBBrkPedlValPerc_pct < KIPM_EHBBrkPedlValPercLo_pct) {
    /* Switch: '<S177>/Switch4' incorporates:
     *  MinMax: '<S177>/MinMax1'
     */
    VIPM_EHBBrkPedlValPerc_pct = KIPM_EHBBrkPedlValPercLo_pct;
  }

  /* End of MinMax: '<S177>/MinMax1' */
  /* End of Outputs for SubSystem: '<S173>/Subsys_VIPM_EHBBrkPedlValPerc_pct' */

  /* Outputs for Atomic SubSystem: '<S173>/Subsys_VIPM_EHBFltLvl_enum' */
  /* Logic: '<S183>/Logical Operator3' incorporates:
   *  Constant: '<S183>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_EHBFltLvlVld_flg = (KIPM_EHBFltLvl_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_EHBMsgActv_flg);

  /* Switch: '<S183>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_EHBMsgActv_flg) {
    /* Switch: '<S183>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_EHB_B_CRCFlt_flg) {
      /* Switch: '<S183>/Switch' incorporates:
       *  Inport: '<Root>/EHB_B_CHA'
       *  Switch: '<S183>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_da =
        (Rte_IRead_Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA())->EHB_FaultLevel;
    }

    /* End of Switch: '<S183>/Switch3' */
  } else {
    /* Switch: '<S183>/Switch' incorporates:
     *  Constant: '<S183>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_da = KIPM_EHBFltLvlDflt_enum;
  }

  /* End of Switch: '<S183>/Switch' */

  /* Switch: '<S183>/Switch4' incorporates:
   *  Constant: '<S183>/sat3'
   */
  if (KIPM_EHBFltLvl_enum_ovrdflg) {
    /* Switch: '<S183>/Switch4' incorporates:
     *  Constant: '<S183>/sat4'
     */
    VIPM_EHBFltLvl_enum = KIPM_EHBFltLvl_enum_ovrdval;
  } else {
    /* Switch: '<S183>/Switch4' */
    VIPM_EHBFltLvl_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_da;
  }

  /* End of Switch: '<S183>/Switch4' */
  /* End of Outputs for SubSystem: '<S173>/Subsys_VIPM_EHBFltLvl_enum' */

  /* Outputs for Atomic SubSystem: '<S173>/Subsys_VIPM_EHBReqBrkLiOn_flg' */
  /* Logic: '<S184>/Logical Operator3' incorporates:
   *  Constant: '<S184>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_EHBReqBrkLiOnVld_flg = (KIPM_EHBReqBrkLiOn_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_EHBMsgActv_flg);

  /* Switch: '<S184>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_EHBMsgActv_flg) {
    /* Switch: '<S184>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_EHB_B_CRCFlt_flg) {
      /* Switch: '<S184>/Switch' incorporates:
       *  Inport: '<Root>/EHB_B_CHA'
       *  Switch: '<S184>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pk =
        (Rte_IRead_Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA())->EHB_ReqBrkLiOn;
    }

    /* End of Switch: '<S184>/Switch3' */
  } else {
    /* Switch: '<S184>/Switch' incorporates:
     *  Constant: '<S184>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pk = KIPM_EHBReqBrkLiOnDflt_flg;
  }

  /* End of Switch: '<S184>/Switch' */

  /* Switch: '<S184>/Switch4' incorporates:
   *  Constant: '<S184>/sat3'
   */
  if (KIPM_EHBReqBrkLiOn_flg_ovrdflg) {
    /* Switch: '<S184>/Switch4' incorporates:
     *  Constant: '<S184>/sat4'
     */
    VIPM_EHBReqBrkLiOn_flg = KIPM_EHBReqBrkLiOn_flg_ovrdval;
  } else {
    /* Switch: '<S184>/Switch4' */
    VIPM_EHBReqBrkLiOn_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pk;
  }

  /* End of Switch: '<S184>/Switch4' */
  /* End of Outputs for SubSystem: '<S173>/Subsys_VIPM_EHBReqBrkLiOn_flg' */

  /* Outputs for Atomic SubSystem: '<S173>/Subsys_VIPM_EHBBrkPwrRecupTarWhlTq_Nm' */
  /* Logic: '<S179>/Logical Operator3' incorporates:
   *  Constant: '<S179>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_EHBBrkPwrRecupTarWhlTqVld_flg = (KIPM_EHBBrkPwrRecupTarWhlTq_Nm_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_EHBMsgActv_flg);

  /* Switch: '<S179>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_EHBMsgActv_flg) {
    /* Switch: '<S179>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_EHB_B_CRCFlt_flg) {
      /* Product: '<S185>/Product' incorporates:
       *  Inport: '<Root>/EHB_B_CHA'
       */
      rtb_Product_i4 = (Rte_IRead_Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA())
        ->EHB_BrkPwrRecupTarWhlTq;

      /* Switch: '<S179>/Switch' incorporates:
       *  Sum: '<S185>/Add'
       *  Switch: '<S179>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_eu = (float32)rtb_Product_i4 -
        32768.0F;
    }

    /* End of Switch: '<S179>/Switch3' */
  } else {
    /* Switch: '<S179>/Switch' incorporates:
     *  Constant: '<S179>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_eu = KIPM_EHBBrkPwrRecupTarWhlTqDflt_Nm;
  }

  /* End of Switch: '<S179>/Switch' */

  /* Switch: '<S179>/Switch4' incorporates:
   *  Constant: '<S179>/sat3'
   *  Constant: '<S179>/sat4'
   */
  if (KIPM_EHBBrkPwrRecupTarWhlTq_Nm_ovrdflg) {
    VIPM_EHBBrkPwrRecupTarWhlTq_Nm = KIPM_EHBBrkPwrRecupTarWhlTq_Nm_ovrdval;
  } else {
    VIPM_EHBBrkPwrRecupTarWhlTq_Nm = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_eu;
  }

  /* MinMax: '<S179>/MinMax' incorporates:
   *  Constant: '<S179>/sat6'
   *  Switch: '<S179>/Switch4'
   */
  if (VIPM_EHBBrkPwrRecupTarWhlTq_Nm > KIPM_EHBBrkPwrRecupTarWhlTqHi_Nm) {
    VIPM_EHBBrkPwrRecupTarWhlTq_Nm = KIPM_EHBBrkPwrRecupTarWhlTqHi_Nm;
  }

  /* End of MinMax: '<S179>/MinMax' */

  /* MinMax: '<S179>/MinMax1' incorporates:
   *  Constant: '<S179>/sat7'
   */
  if (VIPM_EHBBrkPwrRecupTarWhlTq_Nm < KIPM_EHBBrkPwrRecupTarWhlTqLo_Nm) {
    /* Switch: '<S179>/Switch4' incorporates:
     *  MinMax: '<S179>/MinMax1'
     */
    VIPM_EHBBrkPwrRecupTarWhlTq_Nm = KIPM_EHBBrkPwrRecupTarWhlTqLo_Nm;
  }

  /* End of MinMax: '<S179>/MinMax1' */
  /* End of Outputs for SubSystem: '<S173>/Subsys_VIPM_EHBBrkPwrRecupTarWhlTq_Nm' */

  /* Outputs for Atomic SubSystem: '<S173>/Subsys_VIPM_EHBBrkPwrRecupTarWhlTqSts_enum' */
  /* Logic: '<S178>/Logical Operator3' incorporates:
   *  Constant: '<S178>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_EHBBrkPwrRecupTarWhlTqStsVld_flg =
    (KIPM_EHBBrkPwrRecupTarWhlTqSts_enum_ovrdflg ||
     (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
     ->VIPM_EHBMsgActv_flg);

  /* Switch: '<S178>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_EHBMsgActv_flg) {
    /* Switch: '<S178>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_EHB_B_CRCFlt_flg) {
      /* Switch: '<S178>/Switch' incorporates:
       *  DataTypeConversion: '<S178>/Data Type Conversion2'
       *  Inport: '<Root>/EHB_B_CHA'
       *  Switch: '<S178>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_n0 =
        (Rte_IRead_Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA())
        ->EHB_BrkPwrRecupTarWhlTqSts;
    }

    /* End of Switch: '<S178>/Switch3' */
  } else {
    /* Switch: '<S178>/Switch' incorporates:
     *  Constant: '<S178>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_n0 =
      KIPM_EHBBrkPwrRecupTarWhlTqStsDflt_enum;
  }

  /* End of Switch: '<S178>/Switch' */

  /* Switch: '<S178>/Switch4' incorporates:
   *  Constant: '<S178>/sat3'
   */
  if (KIPM_EHBBrkPwrRecupTarWhlTqSts_enum_ovrdflg) {
    /* Switch: '<S178>/Switch4' incorporates:
     *  Constant: '<S178>/sat4'
     */
    VIPM_EHBBrkPwrRecupTarWhlTqSts_enum =
      KIPM_EHBBrkPwrRecupTarWhlTqSts_enum_ovrdval;
  } else {
    /* Switch: '<S178>/Switch4' incorporates:
     *  Switch: '<S178>/Switch'
     */
    VIPM_EHBBrkPwrRecupTarWhlTqSts_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_n0;
  }

  /* End of Switch: '<S178>/Switch4' */
  /* End of Outputs for SubSystem: '<S173>/Subsys_VIPM_EHBBrkPwrRecupTarWhlTqSts_enum' */

  /* DataTypeConversion: '<S173>/Data Type Conversion1' incorporates:
   *  Switch: '<S178>/Switch4'
   */
  AppSwcIpm_ARID_DEF.EHB_B_CHA_l.VIPM_EHBBrkPwrRecupTarWhlTqSts_enum =
    VIPM_EHBBrkPwrRecupTarWhlTqSts_enum;

  /* Outputs for Atomic SubSystem: '<S173>/Subsys_VIPM_EHBEPBActuatorStR_enum' */
  /* Logic: '<S181>/Logical Operator3' incorporates:
   *  Constant: '<S181>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_EHBEPBActuatorStRVld_flg = (KIPM_EHBEPBActuatorStR_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_EHBMsgActv_flg);

  /* Switch: '<S181>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_EHBMsgActv_flg) {
    /* Switch: '<S181>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_EHB_B_CRCFlt_flg) {
      /* Switch: '<S181>/Switch' incorporates:
       *  DataTypeConversion: '<S181>/Data Type Conversion2'
       *  Inport: '<Root>/EHB_B_CHA'
       *  Switch: '<S181>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cj =
        (Rte_IRead_Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA())
        ->EHB_EPB_ActuatorSt_R;
    }

    /* End of Switch: '<S181>/Switch3' */
  } else {
    /* Switch: '<S181>/Switch' incorporates:
     *  Constant: '<S181>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cj = KIPM_EHBEPBActuatorStRDflt_enum;
  }

  /* End of Switch: '<S181>/Switch' */

  /* Switch: '<S181>/Switch4' incorporates:
   *  Constant: '<S181>/sat3'
   */
  if (KIPM_EHBEPBActuatorStR_enum_ovrdflg) {
    /* Switch: '<S181>/Switch4' incorporates:
     *  Constant: '<S181>/sat4'
     */
    VIPM_EHBEPBActuatorStR_enum = KIPM_EHBEPBActuatorStR_enum_ovrdval;
  } else {
    /* Switch: '<S181>/Switch4' incorporates:
     *  Switch: '<S181>/Switch'
     */
    VIPM_EHBEPBActuatorStR_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cj;
  }

  /* End of Switch: '<S181>/Switch4' */
  /* End of Outputs for SubSystem: '<S173>/Subsys_VIPM_EHBEPBActuatorStR_enum' */

  /* Outputs for Atomic SubSystem: '<S173>/Subsys_VIPM_EHBCDDActv_flg' */
  /* Logic: '<S180>/Logical Operator3' incorporates:
   *  Constant: '<S180>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_EHBCDDActvVld_flg = (KIPM_EHBCDDActv_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_EHBMsgActv_flg);

  /* Switch: '<S180>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_EHBMsgActv_flg) {
    /* Switch: '<S180>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_EHB_B_CRCFlt_flg) {
      /* Switch: '<S180>/Switch' incorporates:
       *  Inport: '<Root>/EHB_B_CHA'
       *  Switch: '<S180>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cn =
        (Rte_IRead_Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA())->EHB_CDDActive;
    }

    /* End of Switch: '<S180>/Switch3' */
  } else {
    /* Switch: '<S180>/Switch' incorporates:
     *  Constant: '<S180>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cn = KIPM_EHBCDDActvDflt_flg;
  }

  /* End of Switch: '<S180>/Switch' */

  /* Switch: '<S180>/Switch4' incorporates:
   *  Constant: '<S180>/sat3'
   */
  if (KIPM_EHBCDDActv_flg_ovrdflg) {
    /* Switch: '<S180>/Switch4' incorporates:
     *  Constant: '<S180>/sat4'
     */
    VIPM_EHBCDDActv_flg = KIPM_EHBCDDActv_flg_ovrdval;
  } else {
    /* Switch: '<S180>/Switch4' */
    VIPM_EHBCDDActv_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cn;
  }

  /* End of Switch: '<S180>/Switch4' */
  /* End of Outputs for SubSystem: '<S173>/Subsys_VIPM_EHBCDDActv_flg' */

  /* BusCreator: '<S173>/BusCreator' incorporates:
   *  DataTypeConversion: '<S173>/Data Type Conversion'
   *  Logic: '<S177>/Logical Operator3'
   *  Logic: '<S178>/Logical Operator3'
   *  Logic: '<S179>/Logical Operator3'
   *  Logic: '<S180>/Logical Operator3'
   *  Logic: '<S181>/Logical Operator3'
   *  Logic: '<S182>/Logical Operator3'
   *  Logic: '<S183>/Logical Operator3'
   *  Logic: '<S184>/Logical Operator3'
   *  MinMax: '<S177>/MinMax1'
   *  MinMax: '<S179>/MinMax1'
   *  Switch: '<S180>/Switch4'
   *  Switch: '<S181>/Switch4'
   *  Switch: '<S182>/Switch4'
   *  Switch: '<S183>/Switch4'
   *  Switch: '<S184>/Switch4'
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

  /* Outputs for Atomic SubSystem: '<S174>/Subsys_VIPM_EPSSteerWhlAng_deg' */
  /* Logic: '<S199>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/EPS_2_StrWhlAng_CHA'
   *  Logic: '<S189>/Logical Operator2'
   */
  rtb_LogicalOperator2_mn =
    ((Rte_IRead_Runbl_IpmCanRx_10ms_EPS_2_StrWhlAng_CHA_EPS_2_StrWhlAng_CHA())
     ->EPS_SteerWheelAngleValid &&
     (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
     ->VIPM_EPSMsgActv_flg);

  /* Logic: '<S189>/Logical Operator3' incorporates:
   *  Constant: '<S189>/sat3'
   */
  VIPM_EPSSteerWhlAngVld_flg = (KIPM_EPSSteerWhlAng_deg_ovrdflg ||
    rtb_LogicalOperator2_mn);

  /* Switch: '<S189>/Switch' */
  if (rtb_LogicalOperator2_mn) {
    /* Switch: '<S189>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_EPS_2_StrWhlAng_CRCFlt_flg) {
      /* Product: '<S190>/Product' incorporates:
       *  Constant: '<S190>/Constant'
       *  Inport: '<Root>/EPS_2_StrWhlAng_CHA'
       */
      rtb_Product_dq = (float32)
        (Rte_IRead_Runbl_IpmCanRx_10ms_EPS_2_StrWhlAng_CHA_EPS_2_StrWhlAng_CHA())
        ->EPS_SteerWheelAngle * 0.1F;

      /* Switch: '<S189>/Switch' incorporates:
       *  Sum: '<S190>/Add'
       *  Switch: '<S189>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_a = rtb_Product_dq - 780.0F;
    }

    /* End of Switch: '<S189>/Switch3' */
  } else {
    /* Switch: '<S189>/Switch' incorporates:
     *  Constant: '<S189>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_a = KIPM_EPSSteerWhlAngDflt_deg;
  }

  /* End of Switch: '<S189>/Switch' */

  /* Switch: '<S189>/Switch4' incorporates:
   *  Constant: '<S189>/sat3'
   *  Constant: '<S189>/sat4'
   */
  if (KIPM_EPSSteerWhlAng_deg_ovrdflg) {
    VIPM_EPSSteerWhlAng_deg = KIPM_EPSSteerWhlAng_deg_ovrdval;
  } else {
    VIPM_EPSSteerWhlAng_deg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_a;
  }

  /* MinMax: '<S189>/MinMax' incorporates:
   *  Constant: '<S189>/sat6'
   *  Switch: '<S189>/Switch4'
   */
  if (VIPM_EPSSteerWhlAng_deg > KIPM_EPSSteerWhlAngHi_deg) {
    VIPM_EPSSteerWhlAng_deg = KIPM_EPSSteerWhlAngHi_deg;
  }

  /* End of MinMax: '<S189>/MinMax' */

  /* MinMax: '<S189>/MinMax1' incorporates:
   *  Constant: '<S189>/sat7'
   */
  if (VIPM_EPSSteerWhlAng_deg < KIPM_EPSSteerWhlAngLo_deg) {
    /* Switch: '<S189>/Switch4' incorporates:
     *  MinMax: '<S189>/MinMax1'
     */
    VIPM_EPSSteerWhlAng_deg = KIPM_EPSSteerWhlAngLo_deg;
  }

  /* End of MinMax: '<S189>/MinMax1' */
  /* End of Outputs for SubSystem: '<S174>/Subsys_VIPM_EPSSteerWhlAng_deg' */

  /* Outputs for Atomic SubSystem: '<S174>/Subsys_VIPM_EPSRotSpd_degps' */
  /* Logic: '<S186>/Logical Operator3' incorporates:
   *  Constant: '<S186>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_EPSRotSpdVld_flg = (KIPM_EPSRotSpd_degps_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_EPSMsgActv_flg);

  /* Switch: '<S186>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_EPSMsgActv_flg) {
    /* Switch: '<S186>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_EPS_2_StrWhlAng_CRCFlt_flg) {
      /* Product: '<S191>/Product' incorporates:
       *  Constant: '<S191>/Constant'
       *  Inport: '<Root>/EPS_2_StrWhlAng_CHA'
       */
      rtb_Product_dq = (float32)
        (Rte_IRead_Runbl_IpmCanRx_10ms_EPS_2_StrWhlAng_CHA_EPS_2_StrWhlAng_CHA())
        ->EPS_RotSpeed * 0.1F;

      /* Switch: '<S186>/Switch' incorporates:
       *  Sum: '<S191>/Add'
       *  Switch: '<S186>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_au = rtb_Product_dq - 1024.0F;
    }

    /* End of Switch: '<S186>/Switch3' */
  } else {
    /* Switch: '<S186>/Switch' incorporates:
     *  Constant: '<S186>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_au = KIPM_EPSRotSpdDflt_degps;
  }

  /* End of Switch: '<S186>/Switch' */

  /* Switch: '<S186>/Switch4' incorporates:
   *  Constant: '<S186>/sat3'
   *  Constant: '<S186>/sat4'
   */
  if (KIPM_EPSRotSpd_degps_ovrdflg) {
    VIPM_EPSRotSpd_degps = KIPM_EPSRotSpd_degps_ovrdval;
  } else {
    VIPM_EPSRotSpd_degps = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_au;
  }

  /* MinMax: '<S186>/MinMax' incorporates:
   *  Constant: '<S186>/sat6'
   *  Switch: '<S186>/Switch4'
   */
  if (VIPM_EPSRotSpd_degps > KIPM_EPSRotSpdHi_degps) {
    VIPM_EPSRotSpd_degps = KIPM_EPSRotSpdHi_degps;
  }

  /* End of MinMax: '<S186>/MinMax' */

  /* MinMax: '<S186>/MinMax1' incorporates:
   *  Constant: '<S186>/sat7'
   */
  if (VIPM_EPSRotSpd_degps < KIPM_EPSRotSpdLo_degps) {
    /* Switch: '<S186>/Switch4' incorporates:
     *  MinMax: '<S186>/MinMax1'
     */
    VIPM_EPSRotSpd_degps = KIPM_EPSRotSpdLo_degps;
  }

  /* End of MinMax: '<S186>/MinMax1' */
  /* End of Outputs for SubSystem: '<S174>/Subsys_VIPM_EPSRotSpd_degps' */

  /* Outputs for Atomic SubSystem: '<S174>/Subsys_VIPM_EPSSteerWhlAngCald_flg' */
  /* Logic: '<S187>/Logical Operator3' incorporates:
   *  Constant: '<S187>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_EPSSteerWhlAngCaldVld_flg = (KIPM_EPSSteerWhlAngCald_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_EPSMsgActv_flg);

  /* Switch: '<S187>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_EPSMsgActv_flg) {
    /* Switch: '<S187>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_EPS_2_StrWhlAng_CRCFlt_flg) {
      /* Switch: '<S187>/Switch' incorporates:
       *  Inport: '<Root>/EPS_2_StrWhlAng_CHA'
       *  Switch: '<S187>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ls =
        (Rte_IRead_Runbl_IpmCanRx_10ms_EPS_2_StrWhlAng_CHA_EPS_2_StrWhlAng_CHA())
        ->EPS_SteerWheelAngleCalibrated;
    }

    /* End of Switch: '<S187>/Switch3' */
  } else {
    /* Switch: '<S187>/Switch' incorporates:
     *  Constant: '<S187>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ls = KIPM_EPSSteerWhlAngCaldDflt_flg;
  }

  /* End of Switch: '<S187>/Switch' */

  /* Switch: '<S187>/Switch4' incorporates:
   *  Constant: '<S187>/sat3'
   */
  if (KIPM_EPSSteerWhlAngCald_flg_ovrdflg) {
    /* Switch: '<S187>/Switch4' incorporates:
     *  Constant: '<S187>/sat4'
     */
    VIPM_EPSSteerWhlAngCald_flg = KIPM_EPSSteerWhlAngCald_flg_ovrdval;
  } else {
    /* Switch: '<S187>/Switch4' */
    VIPM_EPSSteerWhlAngCald_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ls;
  }

  /* End of Switch: '<S187>/Switch4' */
  /* End of Outputs for SubSystem: '<S174>/Subsys_VIPM_EPSSteerWhlAngCald_flg' */

  /* Outputs for Atomic SubSystem: '<S174>/Subsys_VIPM_EPSSteerWhlAngFailr_flg' */
  /* Logic: '<S188>/Logical Operator3' incorporates:
   *  Constant: '<S188>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_EPSSteerWhlAngFailrVld_flg = (KIPM_EPSSteerWhlAngFailr_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_EPSMsgActv_flg);

  /* Switch: '<S188>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_EPSMsgActv_flg) {
    /* Switch: '<S188>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_EPS_2_StrWhlAng_CRCFlt_flg) {
      /* Switch: '<S188>/Switch' incorporates:
       *  Inport: '<Root>/EPS_2_StrWhlAng_CHA'
       *  Switch: '<S188>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_dj =
        (Rte_IRead_Runbl_IpmCanRx_10ms_EPS_2_StrWhlAng_CHA_EPS_2_StrWhlAng_CHA())
        ->EPS_SteerWheelAngleFailure;
    }

    /* End of Switch: '<S188>/Switch3' */
  } else {
    /* Switch: '<S188>/Switch' incorporates:
     *  Constant: '<S188>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_dj = KIPM_EPSSteerWhlAngFailrDflt_flg;
  }

  /* End of Switch: '<S188>/Switch' */

  /* Switch: '<S188>/Switch4' incorporates:
   *  Constant: '<S188>/sat3'
   */
  if (KIPM_EPSSteerWhlAngFailr_flg_ovrdflg) {
    /* Switch: '<S188>/Switch4' incorporates:
     *  Constant: '<S188>/sat4'
     */
    VIPM_EPSSteerWhlAngFailr_flg = KIPM_EPSSteerWhlAngFailr_flg_ovrdval;
  } else {
    /* Switch: '<S188>/Switch4' */
    VIPM_EPSSteerWhlAngFailr_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_dj;
  }

  /* End of Switch: '<S188>/Switch4' */
  /* End of Outputs for SubSystem: '<S174>/Subsys_VIPM_EPSSteerWhlAngFailr_flg' */

  /* BusCreator: '<S174>/BusCreator' incorporates:
   *  Logic: '<S186>/Logical Operator3'
   *  Logic: '<S187>/Logical Operator3'
   *  Logic: '<S188>/Logical Operator3'
   *  Logic: '<S189>/Logical Operator3'
   *  MinMax: '<S186>/MinMax1'
   *  MinMax: '<S189>/MinMax1'
   *  Switch: '<S187>/Switch4'
   *  Switch: '<S188>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_EPS_2_StrWhlAng_CHA.VIPM_EPSSteerWhlAng_deg =
    VIPM_EPSSteerWhlAng_deg;
  AppSwcIpm_ARID_DEF.IPM_EPS_2_StrWhlAng_CHA.VIPM_EPSSteerWhlAngVld_flg =
    VIPM_EPSSteerWhlAngVld_flg;
  AppSwcIpm_ARID_DEF.IPM_EPS_2_StrWhlAng_CHA.VIPM_EPSRotSpd_degps =
    VIPM_EPSRotSpd_degps;
  AppSwcIpm_ARID_DEF.IPM_EPS_2_StrWhlAng_CHA.VIPM_EPSRotSpdVld_flg =
    VIPM_EPSRotSpdVld_flg;
  AppSwcIpm_ARID_DEF.IPM_EPS_2_StrWhlAng_CHA.VIPM_EPSSteerWhlAngCald_flg =
    VIPM_EPSSteerWhlAngCald_flg;
  AppSwcIpm_ARID_DEF.IPM_EPS_2_StrWhlAng_CHA.VIPM_EPSSteerWhlAngCaldVld_flg =
    VIPM_EPSSteerWhlAngCaldVld_flg;
  AppSwcIpm_ARID_DEF.IPM_EPS_2_StrWhlAng_CHA.VIPM_EPSSteerWhlAngFailr_flg =
    VIPM_EPSSteerWhlAngFailr_flg;
  AppSwcIpm_ARID_DEF.IPM_EPS_2_StrWhlAng_CHA.VIPM_EPSSteerWhlAngFailrVld_flg =
    VIPM_EPSSteerWhlAngFailrVld_flg;

  /* Outputs for Atomic SubSystem: '<S175>/Subsys_VIPM_ESCABSActvSta_flg' */
  /* Logic: '<S192>/Logical Operator3' incorporates:
   *  Constant: '<S192>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_ESCABSActvStaVld_flg = (KIPM_ESCABSActvSta_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_ESCMsgActv_flg);

  /* Switch: '<S192>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_ESCMsgActv_flg) {
    /* Switch: '<S192>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_ESC_7_FuncStatus_CRCFlt_flg) {
      /* Switch: '<S192>/Switch' incorporates:
       *  Inport: '<Root>/ESC_7_FuncStatus_CHA'
       *  Switch: '<S192>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_a50 =
        (Rte_IRead_Runbl_IpmCanRx_10ms_ESC_7_FuncStatus_CHA_ESC_7_FuncStatus_CHA
         ())->ESC_ABSActiveSta;
    }

    /* End of Switch: '<S192>/Switch3' */
  } else {
    /* Switch: '<S192>/Switch' incorporates:
     *  Constant: '<S192>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_a50 = KIPM_ESCABSActvStaDflt_flg;
  }

  /* End of Switch: '<S192>/Switch' */

  /* Switch: '<S192>/Switch4' incorporates:
   *  Constant: '<S192>/sat3'
   */
  if (KIPM_ESCABSActvSta_flg_ovrdflg) {
    /* Switch: '<S192>/Switch4' incorporates:
     *  Constant: '<S192>/sat4'
     */
    VIPM_ESCABSActvSta_flg = KIPM_ESCABSActvSta_flg_ovrdval;
  } else {
    /* Switch: '<S192>/Switch4' */
    VIPM_ESCABSActvSta_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_a50;
  }

  /* End of Switch: '<S192>/Switch4' */
  /* End of Outputs for SubSystem: '<S175>/Subsys_VIPM_ESCABSActvSta_flg' */

  /* Outputs for Atomic SubSystem: '<S175>/Subsys_VIPM_ESCVehSpd_kph' */
  /* Logic: '<S199>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/ESC_7_FuncStatus_CHA'
   *  Logic: '<S201>/Logical Operator2'
   */
  rtb_LogicalOperator2_mn =
    ((Rte_IRead_Runbl_IpmCanRx_10ms_ESC_7_FuncStatus_CHA_ESC_7_FuncStatus_CHA()
     )->ESC_VehicleSpeedV &&
     (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
     ->VIPM_ESCMsgActv_flg);

  /* Logic: '<S201>/Logical Operator3' incorporates:
   *  Constant: '<S201>/sat3'
   */
  VIPM_ESCVehSpdVld_flg = (KIPM_ESCVehSpd_kph_ovrdflg || rtb_LogicalOperator2_mn);

  /* Switch: '<S201>/Switch' */
  if (rtb_LogicalOperator2_mn) {
    /* Switch: '<S201>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_ESC_7_FuncStatus_CRCFlt_flg) {
      /* Switch: '<S201>/Switch' incorporates:
       *  Constant: '<S202>/Constant'
       *  Inport: '<Root>/ESC_7_FuncStatus_CHA'
       *  Product: '<S202>/Product'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_dc = (float32)
        (Rte_IRead_Runbl_IpmCanRx_10ms_ESC_7_FuncStatus_CHA_ESC_7_FuncStatus_CHA
         ())->ESC_VehicleSpeed * 0.05625F;
    }

    /* End of Switch: '<S201>/Switch3' */
  } else {
    /* Switch: '<S201>/Switch' incorporates:
     *  Constant: '<S201>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_dc = KIPM_ESCVehSpdDflt_kph;
  }

  /* End of Switch: '<S201>/Switch' */

  /* Switch: '<S201>/Switch4' incorporates:
   *  Constant: '<S201>/sat3'
   *  Constant: '<S201>/sat4'
   */
  if (KIPM_ESCVehSpd_kph_ovrdflg) {
    VIPM_ESCVehSpd_kph = KIPM_ESCVehSpd_kph_ovrdval;
  } else {
    VIPM_ESCVehSpd_kph = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_dc;
  }

  /* MinMax: '<S201>/MinMax' incorporates:
   *  Constant: '<S201>/sat6'
   *  Switch: '<S201>/Switch4'
   */
  if (VIPM_ESCVehSpd_kph > KIPM_ESCVehSpdHi_kph) {
    VIPM_ESCVehSpd_kph = KIPM_ESCVehSpdHi_kph;
  }

  /* End of MinMax: '<S201>/MinMax' */

  /* MinMax: '<S201>/MinMax1' incorporates:
   *  Constant: '<S201>/sat7'
   */
  if (VIPM_ESCVehSpd_kph < KIPM_ESCVehSpdLo_kph) {
    /* Switch: '<S201>/Switch4' incorporates:
     *  MinMax: '<S201>/MinMax1'
     */
    VIPM_ESCVehSpd_kph = KIPM_ESCVehSpdLo_kph;
  }

  /* End of MinMax: '<S201>/MinMax1' */
  /* End of Outputs for SubSystem: '<S175>/Subsys_VIPM_ESCVehSpd_kph' */

  /* Outputs for Atomic SubSystem: '<S175>/Subsys_VIPM_ESCTCSActvSta_flg' */
  /* Logic: '<S200>/Logical Operator3' incorporates:
   *  Constant: '<S200>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_ESCTCSActvStaVld_flg = (KIPM_ESCTCSActvSta_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_ESCMsgActv_flg);

  /* Switch: '<S200>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_ESCMsgActv_flg) {
    /* Switch: '<S200>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_ESC_7_FuncStatus_CRCFlt_flg) {
      /* Switch: '<S200>/Switch' incorporates:
       *  Inport: '<Root>/ESC_7_FuncStatus_CHA'
       *  Switch: '<S200>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_b3 =
        (Rte_IRead_Runbl_IpmCanRx_10ms_ESC_7_FuncStatus_CHA_ESC_7_FuncStatus_CHA
         ())->ESC_TCSActiveSta;
    }

    /* End of Switch: '<S200>/Switch3' */
  } else {
    /* Switch: '<S200>/Switch' incorporates:
     *  Constant: '<S200>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_b3 = KIPM_ESCTCSActvStaDflt_flg;
  }

  /* End of Switch: '<S200>/Switch' */

  /* Switch: '<S200>/Switch4' incorporates:
   *  Constant: '<S200>/sat3'
   */
  if (KIPM_ESCTCSActvSta_flg_ovrdflg) {
    /* Switch: '<S200>/Switch4' incorporates:
     *  Constant: '<S200>/sat4'
     */
    VIPM_ESCTCSActvSta_flg = KIPM_ESCTCSActvSta_flg_ovrdval;
  } else {
    /* Switch: '<S200>/Switch4' */
    VIPM_ESCTCSActvSta_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_b3;
  }

  /* End of Switch: '<S200>/Switch4' */
  /* End of Outputs for SubSystem: '<S175>/Subsys_VIPM_ESCTCSActvSta_flg' */

  /* Outputs for Atomic SubSystem: '<S175>/Subsys_VIPM_ESCESPActvSta_flg' */
  /* Logic: '<S195>/Logical Operator3' incorporates:
   *  Constant: '<S195>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_ESCESPActvStaVld_flg = (KIPM_ESCESPActvSta_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_ESCMsgActv_flg);

  /* Switch: '<S195>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_ESCMsgActv_flg) {
    /* Switch: '<S195>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_ESC_7_FuncStatus_CRCFlt_flg) {
      /* Switch: '<S195>/Switch' incorporates:
       *  Inport: '<Root>/ESC_7_FuncStatus_CHA'
       *  Switch: '<S195>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_a2 =
        (Rte_IRead_Runbl_IpmCanRx_10ms_ESC_7_FuncStatus_CHA_ESC_7_FuncStatus_CHA
         ())->ESC_ESPActiveSta;
    }

    /* End of Switch: '<S195>/Switch3' */
  } else {
    /* Switch: '<S195>/Switch' incorporates:
     *  Constant: '<S195>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_a2 = KIPM_ESCESPActvStaDflt_flg;
  }

  /* End of Switch: '<S195>/Switch' */

  /* Switch: '<S195>/Switch4' incorporates:
   *  Constant: '<S195>/sat3'
   */
  if (KIPM_ESCESPActvSta_flg_ovrdflg) {
    /* Switch: '<S195>/Switch4' incorporates:
     *  Constant: '<S195>/sat4'
     */
    VIPM_ESCESPActvSta_flg = KIPM_ESCESPActvSta_flg_ovrdval;
  } else {
    /* Switch: '<S195>/Switch4' */
    VIPM_ESCESPActvSta_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_a2;
  }

  /* End of Switch: '<S195>/Switch4' */
  /* End of Outputs for SubSystem: '<S175>/Subsys_VIPM_ESCESPActvSta_flg' */

  /* Outputs for Atomic SubSystem: '<S175>/Subsys_VIPM_ESCReqBrkLghtOn_flg' */
  /* Logic: '<S198>/Logical Operator3' incorporates:
   *  Constant: '<S198>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_ESCReqBrkLghtOnVld_flg = (KIPM_ESCReqBrkLghtOn_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_ESCMsgActv_flg);

  /* Switch: '<S198>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_ESCMsgActv_flg) {
    /* Switch: '<S198>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_ESC_7_FuncStatus_CRCFlt_flg) {
      /* Switch: '<S198>/Switch' incorporates:
       *  Inport: '<Root>/ESC_7_FuncStatus_CHA'
       *  Switch: '<S198>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_g2 =
        (Rte_IRead_Runbl_IpmCanRx_10ms_ESC_7_FuncStatus_CHA_ESC_7_FuncStatus_CHA
         ())->ESC_ReqBrakeLightOn;
    }

    /* End of Switch: '<S198>/Switch3' */
  } else {
    /* Switch: '<S198>/Switch' incorporates:
     *  Constant: '<S198>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_g2 = KIPM_ESCReqBrkLghtOnDflt_flg;
  }

  /* End of Switch: '<S198>/Switch' */

  /* Switch: '<S198>/Switch4' incorporates:
   *  Constant: '<S198>/sat3'
   */
  if (KIPM_ESCReqBrkLghtOn_flg_ovrdflg) {
    /* Switch: '<S198>/Switch4' incorporates:
     *  Constant: '<S198>/sat4'
     */
    VIPM_ESCReqBrkLghtOn_flg = KIPM_ESCReqBrkLghtOn_flg_ovrdval;
  } else {
    /* Switch: '<S198>/Switch4' */
    VIPM_ESCReqBrkLghtOn_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_g2;
  }

  /* End of Switch: '<S198>/Switch4' */
  /* End of Outputs for SubSystem: '<S175>/Subsys_VIPM_ESCReqBrkLghtOn_flg' */

  /* Outputs for Atomic SubSystem: '<S175>/Subsys_VIPM_ESCCDPActv_flg' */
  /* Logic: '<S193>/Logical Operator3' incorporates:
   *  Constant: '<S193>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_ESCCDPActvVld_flg = (KIPM_ESCCDPActv_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_ESCMsgActv_flg);

  /* Switch: '<S193>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_ESCMsgActv_flg) {
    /* Switch: '<S193>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_ESC_7_FuncStatus_CRCFlt_flg) {
      /* Switch: '<S193>/Switch' incorporates:
       *  Inport: '<Root>/ESC_7_FuncStatus_CHA'
       *  Switch: '<S193>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_fx =
        (Rte_IRead_Runbl_IpmCanRx_10ms_ESC_7_FuncStatus_CHA_ESC_7_FuncStatus_CHA
         ())->ESC_CDPActive;
    }

    /* End of Switch: '<S193>/Switch3' */
  } else {
    /* Switch: '<S193>/Switch' incorporates:
     *  Constant: '<S193>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_fx = KIPM_ESCCDPActvDflt_flg;
  }

  /* End of Switch: '<S193>/Switch' */

  /* Switch: '<S193>/Switch4' incorporates:
   *  Constant: '<S193>/sat3'
   */
  if (KIPM_ESCCDPActv_flg_ovrdflg) {
    /* Switch: '<S193>/Switch4' incorporates:
     *  Constant: '<S193>/sat4'
     */
    VIPM_ESCCDPActv_flg = KIPM_ESCCDPActv_flg_ovrdval;
  } else {
    /* Switch: '<S193>/Switch4' */
    VIPM_ESCCDPActv_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_fx;
  }

  /* End of Switch: '<S193>/Switch4' */
  /* End of Outputs for SubSystem: '<S175>/Subsys_VIPM_ESCCDPActv_flg' */

  /* Outputs for Atomic SubSystem: '<S175>/Subsys_VIPM_ESCESSActv_flg' */
  /* Logic: '<S196>/Logical Operator3' incorporates:
   *  Constant: '<S196>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_ESCESSActvVld_flg = (KIPM_ESCESSActv_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_ESCMsgActv_flg);

  /* Switch: '<S196>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_ESCMsgActv_flg) {
    /* Switch: '<S196>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_ESC_7_FuncStatus_CRCFlt_flg) {
      /* Switch: '<S196>/Switch' incorporates:
       *  Inport: '<Root>/ESC_7_FuncStatus_CHA'
       *  Switch: '<S196>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ieu =
        (Rte_IRead_Runbl_IpmCanRx_10ms_ESC_7_FuncStatus_CHA_ESC_7_FuncStatus_CHA
         ())->ESC_ESSActive;
    }

    /* End of Switch: '<S196>/Switch3' */
  } else {
    /* Switch: '<S196>/Switch' incorporates:
     *  Constant: '<S196>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ieu = KIPM_ESCESSActvDflt_flg;
  }

  /* End of Switch: '<S196>/Switch' */

  /* Switch: '<S196>/Switch4' incorporates:
   *  Constant: '<S196>/sat3'
   */
  if (KIPM_ESCESSActv_flg_ovrdflg) {
    /* Switch: '<S196>/Switch4' incorporates:
     *  Constant: '<S196>/sat4'
     */
    VIPM_ESCESSActv_flg = KIPM_ESCESSActv_flg_ovrdval;
  } else {
    /* Switch: '<S196>/Switch4' */
    VIPM_ESCESSActv_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ieu;
  }

  /* End of Switch: '<S196>/Switch4' */
  /* End of Outputs for SubSystem: '<S175>/Subsys_VIPM_ESCESSActv_flg' */

  /* Outputs for Atomic SubSystem: '<S175>/Subsys_VIPM_ESCEBDActv_flg' */
  /* Logic: '<S194>/Logical Operator3' incorporates:
   *  Constant: '<S194>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_ESCEBDActvVld_flg = (KIPM_ESCEBDActv_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_ESCMsgActv_flg);

  /* Switch: '<S194>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_ESCMsgActv_flg) {
    /* Switch: '<S194>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_ESC_7_FuncStatus_CRCFlt_flg) {
      /* Switch: '<S194>/Switch' incorporates:
       *  Inport: '<Root>/ESC_7_FuncStatus_CHA'
       *  Switch: '<S194>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lx =
        (Rte_IRead_Runbl_IpmCanRx_10ms_ESC_7_FuncStatus_CHA_ESC_7_FuncStatus_CHA
         ())->ESC_EBDActiveSta;
    }

    /* End of Switch: '<S194>/Switch3' */
  } else {
    /* Switch: '<S194>/Switch' incorporates:
     *  Constant: '<S194>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lx = KIPM_ESCEBDActvDflt_flg;
  }

  /* End of Switch: '<S194>/Switch' */

  /* Switch: '<S194>/Switch4' incorporates:
   *  Constant: '<S194>/sat3'
   */
  if (KIPM_ESCEBDActv_flg_ovrdflg) {
    /* Switch: '<S194>/Switch4' incorporates:
     *  Constant: '<S194>/sat4'
     */
    VIPM_ESCEBDActv_flg = KIPM_ESCEBDActv_flg_ovrdval;
  } else {
    /* Switch: '<S194>/Switch4' */
    VIPM_ESCEBDActv_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lx;
  }

  /* End of Switch: '<S194>/Switch4' */
  /* End of Outputs for SubSystem: '<S175>/Subsys_VIPM_ESCEBDActv_flg' */

  /* Outputs for Atomic SubSystem: '<S175>/Subsys_VIPM_ESCFltLvl_enum' */
  /* Logic: '<S197>/Logical Operator3' incorporates:
   *  Constant: '<S197>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_ESCFltLvlVld_flg = (KIPM_ESCFltLvl_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_ESCMsgActv_flg);

  /* Switch: '<S197>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_ESCMsgActv_flg) {
    /* Switch: '<S197>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_ESC_7_FuncStatus_CRCFlt_flg) {
      /* Switch: '<S197>/Switch' incorporates:
       *  Inport: '<Root>/ESC_7_FuncStatus_CHA'
       *  Switch: '<S197>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_kv =
        (Rte_IRead_Runbl_IpmCanRx_10ms_ESC_7_FuncStatus_CHA_ESC_7_FuncStatus_CHA
         ())->ESC_FaultLevel;
    }

    /* End of Switch: '<S197>/Switch3' */
  } else {
    /* Switch: '<S197>/Switch' incorporates:
     *  Constant: '<S197>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_kv = KIPM_ESCFltLvlDflt_enum;
  }

  /* End of Switch: '<S197>/Switch' */

  /* Switch: '<S197>/Switch4' incorporates:
   *  Constant: '<S197>/sat3'
   */
  if (KIPM_ESCFltLvl_enum_ovrdflg) {
    /* Switch: '<S197>/Switch4' incorporates:
     *  Constant: '<S197>/sat4'
     */
    VIPM_ESCFltLvl_enum = KIPM_ESCFltLvl_enum_ovrdval;
  } else {
    /* Switch: '<S197>/Switch4' */
    VIPM_ESCFltLvl_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_kv;
  }

  /* End of Switch: '<S197>/Switch4' */
  /* End of Outputs for SubSystem: '<S175>/Subsys_VIPM_ESCFltLvl_enum' */

  /* Outputs for Atomic SubSystem: '<S175>/Subsys_VIPM_ESCSlopPct_pct' */
  /* Logic: '<S199>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/ESC_7_FuncStatus_CHA'
   */
  rtb_LogicalOperator2_mn =
    (((Rte_IRead_Runbl_IpmCanRx_10ms_ESC_7_FuncStatus_CHA_ESC_7_FuncStatus_CHA())
      ->ESC_SlopePercentV != 0) &&
     (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
     ->VIPM_ESCMsgActv_flg);

  /* Logic: '<S199>/Logical Operator3' incorporates:
   *  Constant: '<S199>/sat3'
   */
  VIPM_ESCSlopPctVld_flg = (KIPM_ESCSlopPct_pct_ovrdflg ||
    rtb_LogicalOperator2_mn);

  /* Switch: '<S199>/Switch' */
  if (rtb_LogicalOperator2_mn) {
    /* Switch: '<S199>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_ESC_7_FuncStatus_CRCFlt_flg) {
      /* Product: '<S203>/Product' incorporates:
       *  Inport: '<Root>/ESC_7_FuncStatus_CHA'
       */
      rtb_Product_i4 =
        (Rte_IRead_Runbl_IpmCanRx_10ms_ESC_7_FuncStatus_CHA_ESC_7_FuncStatus_CHA
         ())->ESC_SlopePercent;

      /* Switch: '<S199>/Switch' incorporates:
       *  Sum: '<S203>/Add'
       *  Switch: '<S199>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ev = (float32)rtb_Product_i4 - 100.0F;
    }

    /* End of Switch: '<S199>/Switch3' */
  } else {
    /* Switch: '<S199>/Switch' incorporates:
     *  Constant: '<S199>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ev = KIPM_ESCSlopPctDflt_pct;
  }

  /* End of Switch: '<S199>/Switch' */

  /* Switch: '<S199>/Switch4' incorporates:
   *  Constant: '<S199>/sat3'
   *  Constant: '<S199>/sat4'
   */
  if (KIPM_ESCSlopPct_pct_ovrdflg) {
    VIPM_ESCSlopPct_pct = KIPM_ESCSlopPct_pct_ovrdval;
  } else {
    VIPM_ESCSlopPct_pct = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ev;
  }

  /* MinMax: '<S199>/MinMax' incorporates:
   *  Constant: '<S199>/sat6'
   *  Switch: '<S199>/Switch4'
   */
  if (VIPM_ESCSlopPct_pct > KIPM_ESCSlopPctHi_pct) {
    VIPM_ESCSlopPct_pct = KIPM_ESCSlopPctHi_pct;
  }

  /* End of MinMax: '<S199>/MinMax' */

  /* MinMax: '<S199>/MinMax1' incorporates:
   *  Constant: '<S199>/sat7'
   */
  if (VIPM_ESCSlopPct_pct < KIPM_ESCSlopPctLo_pct) {
    /* Switch: '<S199>/Switch4' incorporates:
     *  MinMax: '<S199>/MinMax1'
     */
    VIPM_ESCSlopPct_pct = KIPM_ESCSlopPctLo_pct;
  }

  /* End of MinMax: '<S199>/MinMax1' */
  /* End of Outputs for SubSystem: '<S175>/Subsys_VIPM_ESCSlopPct_pct' */

  /* BusCreator: '<S175>/BusCreator' incorporates:
   *  Logic: '<S192>/Logical Operator3'
   *  Logic: '<S193>/Logical Operator3'
   *  Logic: '<S194>/Logical Operator3'
   *  Logic: '<S195>/Logical Operator3'
   *  Logic: '<S196>/Logical Operator3'
   *  Logic: '<S197>/Logical Operator3'
   *  Logic: '<S198>/Logical Operator3'
   *  Logic: '<S199>/Logical Operator3'
   *  Logic: '<S200>/Logical Operator3'
   *  Logic: '<S201>/Logical Operator3'
   *  MinMax: '<S199>/MinMax1'
   *  MinMax: '<S201>/MinMax1'
   *  Switch: '<S192>/Switch4'
   *  Switch: '<S193>/Switch4'
   *  Switch: '<S194>/Switch4'
   *  Switch: '<S195>/Switch4'
   *  Switch: '<S196>/Switch4'
   *  Switch: '<S197>/Switch4'
   *  Switch: '<S198>/Switch4'
   *  Switch: '<S200>/Switch4'
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

  /* Outputs for Atomic SubSystem: '<S176>/Subsys_VIPM_ESCVehStandStillSta_enum' */
  /* Logic: '<S207>/Logical Operator3' incorporates:
   *  Constant: '<S207>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_ESCVehStandStillStaVld_flg = (KIPM_ESCVehStandStillSta_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_ESCMsgActv_flg);

  /* Switch: '<S207>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_ESCMsgActv_flg) {
    /* Switch: '<S207>/Switch' incorporates:
     *  Inport: '<Root>/ESC_A_CHA'
     *  Switch: '<S207>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hi =
      (Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA())
      ->ESC_VhclStandstillSta;
  } else {
    /* Switch: '<S207>/Switch' incorporates:
     *  Constant: '<S207>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hi = KIPM_ESCVehStandStillStaDflt_enum;
  }

  /* End of Switch: '<S207>/Switch' */

  /* Switch: '<S207>/Switch4' incorporates:
   *  Constant: '<S207>/sat3'
   */
  if (KIPM_ESCVehStandStillSta_enum_ovrdflg) {
    /* Switch: '<S207>/Switch4' incorporates:
     *  Constant: '<S207>/sat4'
     */
    VIPM_ESCVehStandStillSta_enum = KIPM_ESCVehStandStillSta_enum_ovrdval;
  } else {
    /* Switch: '<S207>/Switch4' */
    VIPM_ESCVehStandStillSta_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hi;
  }

  /* End of Switch: '<S207>/Switch4' */
  /* End of Outputs for SubSystem: '<S176>/Subsys_VIPM_ESCVehStandStillSta_enum' */

  /* Outputs for Atomic SubSystem: '<S176>/Subsys_VIPM_ESCWhlDirctnFL_enum' */
  /* Logic: '<S208>/Logical Operator3' incorporates:
   *  Constant: '<S208>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_ESCWhlDirctnFLVld_flg = (KIPM_ESCWhlDirctnFL_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_ESCMsgActv_flg);

  /* Switch: '<S208>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_ESCMsgActv_flg) {
    /* Switch: '<S208>/Switch' incorporates:
     *  Inport: '<Root>/ESC_A_CHA'
     *  Switch: '<S208>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jc =
      (Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA())
      ->ESC_WheelDirection_FL;
  } else {
    /* Switch: '<S208>/Switch' incorporates:
     *  Constant: '<S208>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jc = KIPM_ESCWhlDirctnFLDflt_enum;
  }

  /* End of Switch: '<S208>/Switch' */

  /* Switch: '<S208>/Switch4' incorporates:
   *  Constant: '<S208>/sat3'
   */
  if (KIPM_ESCWhlDirctnFL_enum_ovrdflg) {
    /* Switch: '<S208>/Switch4' incorporates:
     *  Constant: '<S208>/sat4'
     */
    VIPM_ESCWhlDirctnFL_enum = KIPM_ESCWhlDirctnFL_enum_ovrdval;
  } else {
    /* Switch: '<S208>/Switch4' */
    VIPM_ESCWhlDirctnFL_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jc;
  }

  /* End of Switch: '<S208>/Switch4' */
  /* End of Outputs for SubSystem: '<S176>/Subsys_VIPM_ESCWhlDirctnFL_enum' */

  /* Outputs for Atomic SubSystem: '<S176>/Subsys_VIPM_ESCWhlSpdKphFL_kph' */
  /* Logic: '<S212>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/ESC_A_CHA'
   */
  rtb_LogicalOperator2_mn = ((Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA())
    ->ESC_WheelSpeedKphV_FL &&
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_ESCMsgActv_flg);

  /* Logic: '<S212>/Logical Operator3' incorporates:
   *  Constant: '<S212>/sat3'
   */
  VIPM_ESCWhlSpdKphFLVld_flg = (KIPM_ESCWhlSpdKphFL_kph_ovrdflg ||
    rtb_LogicalOperator2_mn);

  /* Switch: '<S212>/Switch4' incorporates:
   *  Constant: '<S212>/sat3'
   *  Switch: '<S212>/Switch'
   */
  if (KIPM_ESCWhlSpdKphFL_kph_ovrdflg) {
    /* MinMax: '<S212>/MinMax' incorporates:
     *  Constant: '<S212>/sat4'
     *  MinMax: '<S251>/MinMax'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCWhlSpdKphFL_kph_ovrdval;
  } else if (rtb_LogicalOperator2_mn) {
    /* MinMax: '<S212>/MinMax' incorporates:
     *  Constant: '<S221>/Constant'
     *  Inport: '<Root>/ESC_A_CHA'
     *  MinMax: '<S251>/MinMax'
     *  Product: '<S221>/Product'
     *  Switch: '<S212>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = (float32)
      (Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA())
      ->ESC_WheelSpeedKph_FL * 0.05625F;
  } else {
    /* MinMax: '<S212>/MinMax' incorporates:
     *  Constant: '<S212>/sat5'
     *  MinMax: '<S251>/MinMax'
     *  Switch: '<S212>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCWhlSpdKphFLDflt_kph;
  }

  /* End of Switch: '<S212>/Switch4' */

  /* MinMax: '<S212>/MinMax' incorporates:
   *  Constant: '<S212>/sat6'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm > KIPM_ESCWhlSpdKphFLHi_kph) {
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCWhlSpdKphFLHi_kph;
  }

  /* MinMax: '<S212>/MinMax1' incorporates:
   *  Constant: '<S212>/sat7'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm >= KIPM_ESCWhlSpdKphFLLo_kph) {
    /* MinMax: '<S212>/MinMax1' */
    VIPM_ESCWhlSpdKphFL_kph = VIPM_INV3RecupTqAllwdMax_Nm;
  } else {
    /* MinMax: '<S212>/MinMax1' */
    VIPM_ESCWhlSpdKphFL_kph = KIPM_ESCWhlSpdKphFLLo_kph;
  }

  /* End of MinMax: '<S212>/MinMax1' */
  /* End of Outputs for SubSystem: '<S176>/Subsys_VIPM_ESCWhlSpdKphFL_kph' */

  /* Outputs for Atomic SubSystem: '<S176>/Subsys_VIPM_ESCWhlDirctnFR_enum' */
  /* Logic: '<S209>/Logical Operator3' incorporates:
   *  Constant: '<S209>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_ESCWhlDirctnFRVld_flg = (KIPM_ESCWhlDirctnFR_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_ESCMsgActv_flg);

  /* Switch: '<S209>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_ESCMsgActv_flg) {
    /* Switch: '<S209>/Switch' incorporates:
     *  Inport: '<Root>/ESC_A_CHA'
     *  Switch: '<S209>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nj =
      (Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA())
      ->ESC_WheelDirection_FR;
  } else {
    /* Switch: '<S209>/Switch' incorporates:
     *  Constant: '<S209>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nj = KIPM_ESCWhlDirctnFRDflt_enum;
  }

  /* End of Switch: '<S209>/Switch' */

  /* Switch: '<S209>/Switch4' incorporates:
   *  Constant: '<S209>/sat3'
   */
  if (KIPM_ESCWhlDirctnFR_enum_ovrdflg) {
    /* Switch: '<S209>/Switch4' incorporates:
     *  Constant: '<S209>/sat4'
     */
    VIPM_ESCWhlDirctnFR_enum = KIPM_ESCWhlDirctnFR_enum_ovrdval;
  } else {
    /* Switch: '<S209>/Switch4' */
    VIPM_ESCWhlDirctnFR_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nj;
  }

  /* End of Switch: '<S209>/Switch4' */
  /* End of Outputs for SubSystem: '<S176>/Subsys_VIPM_ESCWhlDirctnFR_enum' */

  /* Outputs for Atomic SubSystem: '<S176>/Subsys_VIPM_ESCWhlSpdKphFR_kph' */
  /* Logic: '<S213>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/ESC_A_CHA'
   */
  rtb_LogicalOperator2_mn = ((Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA())
    ->ESC_WheelSpeedKphV_FR &&
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_ESCMsgActv_flg);

  /* Logic: '<S213>/Logical Operator3' incorporates:
   *  Constant: '<S213>/sat3'
   */
  VIPM_ESCWhlSpdKphFRVld_flg = (KIPM_ESCWhlSpdKphFR_kph_ovrdflg ||
    rtb_LogicalOperator2_mn);

  /* Switch: '<S213>/Switch4' incorporates:
   *  Constant: '<S213>/sat3'
   *  Switch: '<S213>/Switch'
   */
  if (KIPM_ESCWhlSpdKphFR_kph_ovrdflg) {
    /* MinMax: '<S212>/MinMax' incorporates:
     *  Constant: '<S213>/sat4'
     *  MinMax: '<S251>/MinMax'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCWhlSpdKphFR_kph_ovrdval;
  } else if (rtb_LogicalOperator2_mn) {
    /* MinMax: '<S212>/MinMax' incorporates:
     *  Constant: '<S222>/Constant'
     *  Inport: '<Root>/ESC_A_CHA'
     *  MinMax: '<S251>/MinMax'
     *  Product: '<S222>/Product'
     *  Switch: '<S213>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = (float32)
      (Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA())
      ->ESC_WheelSpeedKph_FR * 0.05625F;
  } else {
    /* MinMax: '<S212>/MinMax' incorporates:
     *  Constant: '<S213>/sat5'
     *  MinMax: '<S251>/MinMax'
     *  Switch: '<S213>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCWhlSpdKphFRDflt_kph;
  }

  /* End of Switch: '<S213>/Switch4' */

  /* MinMax: '<S213>/MinMax' incorporates:
   *  Constant: '<S213>/sat6'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm > KIPM_ESCWhlSpdKphFRHi_kph) {
    /* MinMax: '<S212>/MinMax' */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCWhlSpdKphFRHi_kph;
  }

  /* End of MinMax: '<S213>/MinMax' */

  /* MinMax: '<S213>/MinMax1' incorporates:
   *  Constant: '<S213>/sat7'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm >= KIPM_ESCWhlSpdKphFRLo_kph) {
    /* MinMax: '<S213>/MinMax1' */
    VIPM_ESCWhlSpdKphFR_kph = VIPM_INV3RecupTqAllwdMax_Nm;
  } else {
    /* MinMax: '<S213>/MinMax1' */
    VIPM_ESCWhlSpdKphFR_kph = KIPM_ESCWhlSpdKphFRLo_kph;
  }

  /* End of MinMax: '<S213>/MinMax1' */
  /* End of Outputs for SubSystem: '<S176>/Subsys_VIPM_ESCWhlSpdKphFR_kph' */

  /* Outputs for Atomic SubSystem: '<S176>/Subsys_VIPM_ESCMstrCylPresr_bar' */
  /* Logic: '<S206>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/ESC_A_CHA'
   */
  rtb_LogicalOperator2_mn = ((Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA())
    ->ESC_MasterCylinderPresrV &&
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_ESCMsgActv_flg);

  /* Logic: '<S206>/Logical Operator3' incorporates:
   *  Constant: '<S206>/sat3'
   */
  VIPM_ESCMstrCylPresrVld_flg = (KIPM_ESCMstrCylPresr_bar_ovrdflg ||
    rtb_LogicalOperator2_mn);

  /* Switch: '<S206>/Switch4' incorporates:
   *  Constant: '<S206>/sat3'
   *  Switch: '<S206>/Switch'
   */
  if (KIPM_ESCMstrCylPresr_bar_ovrdflg) {
    /* MinMax: '<S212>/MinMax' incorporates:
     *  Constant: '<S206>/sat4'
     *  MinMax: '<S251>/MinMax'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCMstrCylPresr_bar_ovrdval;
  } else if (rtb_LogicalOperator2_mn) {
    /* MinMax: '<S212>/MinMax' incorporates:
     *  DataTypeConversion: '<S206>/Data Type Conversion2'
     *  Inport: '<Root>/ESC_A_CHA'
     *  MinMax: '<S251>/MinMax'
     *  Switch: '<S206>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = (float32)
      (Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA())
      ->ESC_MasterCylinderPresr;
  } else {
    /* MinMax: '<S212>/MinMax' incorporates:
     *  Constant: '<S206>/sat5'
     *  MinMax: '<S251>/MinMax'
     *  Switch: '<S206>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCMstrCylPresrDflt_bar;
  }

  /* End of Switch: '<S206>/Switch4' */

  /* MinMax: '<S206>/MinMax' incorporates:
   *  Constant: '<S206>/sat6'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm > KIPM_ESCMstrCylPresrHi_bar) {
    /* MinMax: '<S212>/MinMax' */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCMstrCylPresrHi_bar;
  }

  /* End of MinMax: '<S206>/MinMax' */

  /* MinMax: '<S206>/MinMax1' incorporates:
   *  Constant: '<S206>/sat7'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm >= KIPM_ESCMstrCylPresrLo_bar) {
    /* MinMax: '<S206>/MinMax1' */
    VIPM_ESCMstrCylPresr_bar = VIPM_INV3RecupTqAllwdMax_Nm;
  } else {
    /* MinMax: '<S206>/MinMax1' */
    VIPM_ESCMstrCylPresr_bar = KIPM_ESCMstrCylPresrLo_bar;
  }

  /* End of MinMax: '<S206>/MinMax1' */
  /* End of Outputs for SubSystem: '<S176>/Subsys_VIPM_ESCMstrCylPresr_bar' */

  /* Outputs for Atomic SubSystem: '<S176>/Subsys_VIPM_ESCWhlDirctnRL_enum' */
  /* Logic: '<S210>/Logical Operator3' incorporates:
   *  Constant: '<S210>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_ESCWhlDirctnRLVld_flg = (KIPM_ESCWhlDirctnRL_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_ESCMsgActv_flg);

  /* Switch: '<S210>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_ESCMsgActv_flg) {
    /* Switch: '<S210>/Switch' incorporates:
     *  Inport: '<Root>/ESC_A_CHA'
     *  Switch: '<S210>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ff =
      (Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA())
      ->ESC_WheelDirection_RL;
  } else {
    /* Switch: '<S210>/Switch' incorporates:
     *  Constant: '<S210>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ff = KIPM_ESCWhlDirctnRLDflt_enum;
  }

  /* End of Switch: '<S210>/Switch' */

  /* Switch: '<S210>/Switch4' incorporates:
   *  Constant: '<S210>/sat3'
   */
  if (KIPM_ESCWhlDirctnRL_enum_ovrdflg) {
    /* Switch: '<S210>/Switch4' incorporates:
     *  Constant: '<S210>/sat4'
     */
    VIPM_ESCWhlDirctnRL_enum = KIPM_ESCWhlDirctnRL_enum_ovrdval;
  } else {
    /* Switch: '<S210>/Switch4' */
    VIPM_ESCWhlDirctnRL_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ff;
  }

  /* End of Switch: '<S210>/Switch4' */
  /* End of Outputs for SubSystem: '<S176>/Subsys_VIPM_ESCWhlDirctnRL_enum' */

  /* Outputs for Atomic SubSystem: '<S176>/Subsys_VIPM_ESCWhlSpdKphRL_kph' */
  /* Logic: '<S214>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/ESC_A_CHA'
   */
  rtb_LogicalOperator2_mn = ((Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA())
    ->ESC_WheelSpeedKphV_RL &&
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_ESCMsgActv_flg);

  /* Logic: '<S214>/Logical Operator3' incorporates:
   *  Constant: '<S214>/sat3'
   */
  VIPM_ESCWhlSpdKphRLVld_flg = (KIPM_ESCWhlSpdKphRL_kph_ovrdflg ||
    rtb_LogicalOperator2_mn);

  /* Switch: '<S214>/Switch4' incorporates:
   *  Constant: '<S214>/sat3'
   *  Switch: '<S214>/Switch'
   */
  if (KIPM_ESCWhlSpdKphRL_kph_ovrdflg) {
    /* MinMax: '<S212>/MinMax' incorporates:
     *  Constant: '<S214>/sat4'
     *  MinMax: '<S251>/MinMax'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCWhlSpdKphRL_kph_ovrdval;
  } else if (rtb_LogicalOperator2_mn) {
    /* MinMax: '<S212>/MinMax' incorporates:
     *  Constant: '<S223>/Constant'
     *  Inport: '<Root>/ESC_A_CHA'
     *  MinMax: '<S251>/MinMax'
     *  Product: '<S223>/Product'
     *  Switch: '<S214>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = (float32)
      (Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA())
      ->ESC_WheelSpeedKph_RL * 0.05625F;
  } else {
    /* MinMax: '<S212>/MinMax' incorporates:
     *  Constant: '<S214>/sat5'
     *  MinMax: '<S251>/MinMax'
     *  Switch: '<S214>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCWhlSpdKphRLDflt_kph;
  }

  /* End of Switch: '<S214>/Switch4' */

  /* MinMax: '<S214>/MinMax' incorporates:
   *  Constant: '<S214>/sat6'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm > KIPM_ESCWhlSpdKphRLHi_kph) {
    /* MinMax: '<S212>/MinMax' */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCWhlSpdKphRLHi_kph;
  }

  /* End of MinMax: '<S214>/MinMax' */

  /* MinMax: '<S214>/MinMax1' incorporates:
   *  Constant: '<S214>/sat7'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm >= KIPM_ESCWhlSpdKphRLLo_kph) {
    /* MinMax: '<S214>/MinMax1' */
    VIPM_ESCWhlSpdKphRL_kph = VIPM_INV3RecupTqAllwdMax_Nm;
  } else {
    /* MinMax: '<S214>/MinMax1' */
    VIPM_ESCWhlSpdKphRL_kph = KIPM_ESCWhlSpdKphRLLo_kph;
  }

  /* End of MinMax: '<S214>/MinMax1' */
  /* End of Outputs for SubSystem: '<S176>/Subsys_VIPM_ESCWhlSpdKphRL_kph' */

  /* Outputs for Atomic SubSystem: '<S176>/Subsys_VIPM_ESCWhlDirctnRR_enum' */
  /* Logic: '<S211>/Logical Operator3' incorporates:
   *  Constant: '<S211>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_ESCWhlDirctnRRVld_flg = (KIPM_ESCWhlDirctnRR_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_ESCMsgActv_flg);

  /* Switch: '<S211>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_ESCMsgActv_flg) {
    /* Switch: '<S211>/Switch' incorporates:
     *  Inport: '<Root>/ESC_A_CHA'
     *  Switch: '<S211>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lj =
      (Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA())
      ->ESC_WheelDirection_RR;
  } else {
    /* Switch: '<S211>/Switch' incorporates:
     *  Constant: '<S211>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lj = KIPM_ESCWhlDirctnRRDflt_enum;
  }

  /* End of Switch: '<S211>/Switch' */

  /* Switch: '<S211>/Switch4' incorporates:
   *  Constant: '<S211>/sat3'
   */
  if (KIPM_ESCWhlDirctnRR_enum_ovrdflg) {
    /* Switch: '<S211>/Switch4' incorporates:
     *  Constant: '<S211>/sat4'
     */
    VIPM_ESCWhlDirctnRR_enum = KIPM_ESCWhlDirctnRR_enum_ovrdval;
  } else {
    /* Switch: '<S211>/Switch4' */
    VIPM_ESCWhlDirctnRR_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lj;
  }

  /* End of Switch: '<S211>/Switch4' */
  /* End of Outputs for SubSystem: '<S176>/Subsys_VIPM_ESCWhlDirctnRR_enum' */

  /* Outputs for Atomic SubSystem: '<S176>/Subsys_VIPM_ESCWhlSpdKphRR_kph' */
  /* Logic: '<S215>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/ESC_A_CHA'
   */
  rtb_LogicalOperator2_mn = ((Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA())
    ->ESC_WheelSpeedKphV_RR &&
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_ESCMsgActv_flg);

  /* Logic: '<S215>/Logical Operator3' incorporates:
   *  Constant: '<S215>/sat3'
   */
  VIPM_ESCWhlSpdKphRRVld_flg = (KIPM_ESCWhlSpdKphRR_kph_ovrdflg ||
    rtb_LogicalOperator2_mn);

  /* Switch: '<S215>/Switch4' incorporates:
   *  Constant: '<S215>/sat3'
   *  Switch: '<S215>/Switch'
   */
  if (KIPM_ESCWhlSpdKphRR_kph_ovrdflg) {
    /* MinMax: '<S212>/MinMax' incorporates:
     *  Constant: '<S215>/sat4'
     *  MinMax: '<S251>/MinMax'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCWhlSpdKphRR_kph_ovrdval;
  } else if (rtb_LogicalOperator2_mn) {
    /* MinMax: '<S212>/MinMax' incorporates:
     *  Constant: '<S224>/Constant'
     *  Inport: '<Root>/ESC_A_CHA'
     *  MinMax: '<S251>/MinMax'
     *  Product: '<S224>/Product'
     *  Switch: '<S215>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = (float32)
      (Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA())
      ->ESC_WheelSpeedKph_RR * 0.05625F;
  } else {
    /* MinMax: '<S212>/MinMax' incorporates:
     *  Constant: '<S215>/sat5'
     *  MinMax: '<S251>/MinMax'
     *  Switch: '<S215>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCWhlSpdKphRRDflt_kph;
  }

  /* End of Switch: '<S215>/Switch4' */

  /* MinMax: '<S215>/MinMax' incorporates:
   *  Constant: '<S215>/sat6'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm > KIPM_ESCWhlSpdKphRRHi_kph) {
    /* MinMax: '<S212>/MinMax' */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCWhlSpdKphRRHi_kph;
  }

  /* End of MinMax: '<S215>/MinMax' */

  /* MinMax: '<S215>/MinMax1' incorporates:
   *  Constant: '<S215>/sat7'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm >= KIPM_ESCWhlSpdKphRRLo_kph) {
    /* MinMax: '<S215>/MinMax1' */
    VIPM_ESCWhlSpdKphRR_kph = VIPM_INV3RecupTqAllwdMax_Nm;
  } else {
    /* MinMax: '<S215>/MinMax1' */
    VIPM_ESCWhlSpdKphRR_kph = KIPM_ESCWhlSpdKphRRLo_kph;
  }

  /* End of MinMax: '<S215>/MinMax1' */
  /* End of Outputs for SubSystem: '<S176>/Subsys_VIPM_ESCWhlSpdKphRR_kph' */

  /* Outputs for Atomic SubSystem: '<S176>/Subsys_VIPM_ESCLongAccSnsrVal_g' */
  /* Logic: '<S205>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/ESC_A_CHA'
   */
  rtb_LogicalOperator2_mn = ((Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA())
    ->ESC_LongAccSensorValueVld &&
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_ESCMsgActv_flg);

  /* Logic: '<S205>/Logical Operator3' incorporates:
   *  Constant: '<S205>/sat3'
   */
  VIPM_ESCLongAccSnsrValVld_flg = (KIPM_ESCLongAccSnsrVal_g_ovrdflg ||
    rtb_LogicalOperator2_mn);

  /* Switch: '<S205>/Switch4' incorporates:
   *  Constant: '<S205>/sat3'
   *  Switch: '<S205>/Switch'
   */
  if (KIPM_ESCLongAccSnsrVal_g_ovrdflg) {
    /* MinMax: '<S212>/MinMax' incorporates:
     *  Constant: '<S205>/sat4'
     *  MinMax: '<S251>/MinMax'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCLongAccSnsrVal_g_ovrdval;
  } else if (rtb_LogicalOperator2_mn) {
    /* Product: '<S225>/Product' incorporates:
     *  Constant: '<S225>/Constant'
     *  Inport: '<Root>/ESC_A_CHA'
     *  Switch: '<S205>/Switch'
     */
    rtb_Product_dq = (float32)(Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA
      ())->ESC_LongAccSensorValue * 0.005F;

    /* MinMax: '<S212>/MinMax' incorporates:
     *  MinMax: '<S251>/MinMax'
     *  Sum: '<S225>/Add'
     *  Switch: '<S205>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = rtb_Product_dq - 36.0F;
  } else {
    /* MinMax: '<S212>/MinMax' incorporates:
     *  Constant: '<S205>/sat5'
     *  MinMax: '<S251>/MinMax'
     *  Switch: '<S205>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCLongAccSnsrValDflt_g;
  }

  /* End of Switch: '<S205>/Switch4' */

  /* MinMax: '<S205>/MinMax' incorporates:
   *  Constant: '<S205>/sat6'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm > KIPM_ESCLongAccSnsrValHi_g) {
    /* MinMax: '<S212>/MinMax' */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCLongAccSnsrValHi_g;
  }

  /* End of MinMax: '<S205>/MinMax' */

  /* MinMax: '<S205>/MinMax1' incorporates:
   *  Constant: '<S205>/sat7'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm >= KIPM_ESCLongAccSnsrValLo_g) {
    /* MinMax: '<S205>/MinMax1' */
    VIPM_ESCLongAccSnsrVal_g = VIPM_INV3RecupTqAllwdMax_Nm;
  } else {
    /* MinMax: '<S205>/MinMax1' */
    VIPM_ESCLongAccSnsrVal_g = KIPM_ESCLongAccSnsrValLo_g;
  }

  /* End of MinMax: '<S205>/MinMax1' */
  /* End of Outputs for SubSystem: '<S176>/Subsys_VIPM_ESCLongAccSnsrVal_g' */

  /* Outputs for Atomic SubSystem: '<S176>/Subsys_VIPM_ESCLatAccSnsrVal_g' */
  /* Logic: '<S204>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/ESC_A_CHA'
   */
  rtb_LogicalOperator2_mn = ((Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA())
    ->ESC_LatAccSensorValueVld &&
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_ESCMsgActv_flg);

  /* Logic: '<S204>/Logical Operator3' incorporates:
   *  Constant: '<S204>/sat3'
   */
  VIPM_ESCLatAccSnsrValVld_flg = (KIPM_ESCLatAccSnsrVal_g_ovrdflg ||
    rtb_LogicalOperator2_mn);

  /* Switch: '<S204>/Switch4' incorporates:
   *  Constant: '<S204>/sat3'
   *  Switch: '<S204>/Switch'
   */
  if (KIPM_ESCLatAccSnsrVal_g_ovrdflg) {
    /* MinMax: '<S212>/MinMax' incorporates:
     *  Constant: '<S204>/sat4'
     *  MinMax: '<S251>/MinMax'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCLatAccSnsrVal_g_ovrdval;
  } else if (rtb_LogicalOperator2_mn) {
    /* Product: '<S226>/Product' incorporates:
     *  Constant: '<S226>/Constant'
     *  Inport: '<Root>/ESC_A_CHA'
     *  Switch: '<S204>/Switch'
     */
    rtb_Product_dq = (float32)(Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA
      ())->ESC_LatAccSensorValue * 0.005F;

    /* MinMax: '<S212>/MinMax' incorporates:
     *  MinMax: '<S251>/MinMax'
     *  Sum: '<S226>/Add'
     *  Switch: '<S204>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = rtb_Product_dq - 36.0F;
  } else {
    /* MinMax: '<S212>/MinMax' incorporates:
     *  Constant: '<S204>/sat5'
     *  MinMax: '<S251>/MinMax'
     *  Switch: '<S204>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCLatAccSnsrValDflt_g;
  }

  /* End of Switch: '<S204>/Switch4' */

  /* MinMax: '<S204>/MinMax' incorporates:
   *  Constant: '<S204>/sat6'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm > KIPM_ESCLatAccSnsrValHi_g) {
    /* MinMax: '<S212>/MinMax' */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCLatAccSnsrValHi_g;
  }

  /* End of MinMax: '<S204>/MinMax' */

  /* MinMax: '<S204>/MinMax1' incorporates:
   *  Constant: '<S204>/sat7'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm >= KIPM_ESCLatAccSnsrValLo_g) {
    /* MinMax: '<S204>/MinMax1' */
    VIPM_ESCLatAccSnsrVal_g = VIPM_INV3RecupTqAllwdMax_Nm;
  } else {
    /* MinMax: '<S204>/MinMax1' */
    VIPM_ESCLatAccSnsrVal_g = KIPM_ESCLatAccSnsrValLo_g;
  }

  /* End of MinMax: '<S204>/MinMax1' */
  /* End of Outputs for SubSystem: '<S176>/Subsys_VIPM_ESCLatAccSnsrVal_g' */

  /* Outputs for Atomic SubSystem: '<S176>/Subsys_VIPM_ESCYawRate_degps' */
  /* Logic: '<S220>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/ESC_A_CHA'
   */
  rtb_LogicalOperator2_mn = ((Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA())
    ->ESC_YawRateVld && (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV()
    )->VIPM_ESCMsgActv_flg);

  /* Logic: '<S220>/Logical Operator3' incorporates:
   *  Constant: '<S220>/sat3'
   */
  VIPM_ESCYawRateVld_flg = (KIPM_ESCYawRate_degps_ovrdflg ||
    rtb_LogicalOperator2_mn);

  /* Switch: '<S220>/Switch4' incorporates:
   *  Constant: '<S220>/sat3'
   *  Switch: '<S220>/Switch'
   */
  if (KIPM_ESCYawRate_degps_ovrdflg) {
    /* MinMax: '<S212>/MinMax' incorporates:
     *  Constant: '<S220>/sat4'
     *  MinMax: '<S251>/MinMax'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCYawRate_degps_ovrdval;
  } else if (rtb_LogicalOperator2_mn) {
    /* Product: '<S227>/Product' incorporates:
     *  Constant: '<S227>/Constant'
     *  Inport: '<Root>/ESC_A_CHA'
     *  Switch: '<S220>/Switch'
     */
    rtb_Product_dq = (float32)(Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA
      ())->ESC_YawRate * 0.01F;

    /* MinMax: '<S212>/MinMax' incorporates:
     *  MinMax: '<S251>/MinMax'
     *  Sum: '<S227>/Add'
     *  Switch: '<S220>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = rtb_Product_dq - 300.0F;
  } else {
    /* MinMax: '<S212>/MinMax' incorporates:
     *  Constant: '<S220>/sat5'
     *  MinMax: '<S251>/MinMax'
     *  Switch: '<S220>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCYawRateDflt_degps;
  }

  /* End of Switch: '<S220>/Switch4' */

  /* MinMax: '<S220>/MinMax' incorporates:
   *  Constant: '<S220>/sat6'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm > KIPM_ESCYawRateHi_degps) {
    /* MinMax: '<S212>/MinMax' */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCYawRateHi_degps;
  }

  /* End of MinMax: '<S220>/MinMax' */

  /* MinMax: '<S220>/MinMax1' incorporates:
   *  Constant: '<S220>/sat7'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm >= KIPM_ESCYawRateLo_degps) {
    /* MinMax: '<S220>/MinMax1' */
    VIPM_ESCYawRate_degps = VIPM_INV3RecupTqAllwdMax_Nm;
  } else {
    /* MinMax: '<S220>/MinMax1' */
    VIPM_ESCYawRate_degps = KIPM_ESCYawRateLo_degps;
  }

  /* End of MinMax: '<S220>/MinMax1' */
  /* End of Outputs for SubSystem: '<S176>/Subsys_VIPM_ESCYawRate_degps' */

  /* Outputs for Atomic SubSystem: '<S176>/Subsys_VIPM_ESCWhlTqDecReqActv_flg' */
  /* Logic: '<S216>/Logical Operator3' incorporates:
   *  Constant: '<S216>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_ESCWhlTqDecReqActvVld_flg = (KIPM_ESCWhlTqDecReqActv_flg_ovrdflg ||
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
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_gg =
      (Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA())->ESC_WhlTqDecReqActv;
  } else {
    /* Switch: '<S216>/Switch' incorporates:
     *  Constant: '<S216>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_gg = KIPM_ESCWhlTqDecReqActvDflt_flg;
  }

  /* End of Switch: '<S216>/Switch' */

  /* Switch: '<S216>/Switch4' incorporates:
   *  Constant: '<S216>/sat3'
   */
  if (KIPM_ESCWhlTqDecReqActv_flg_ovrdflg) {
    /* Switch: '<S216>/Switch4' incorporates:
     *  Constant: '<S216>/sat4'
     */
    VIPM_ESCWhlTqDecReqActv_flg = KIPM_ESCWhlTqDecReqActv_flg_ovrdval;
  } else {
    /* Switch: '<S216>/Switch4' */
    VIPM_ESCWhlTqDecReqActv_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_gg;
  }

  /* End of Switch: '<S216>/Switch4' */
  /* End of Outputs for SubSystem: '<S176>/Subsys_VIPM_ESCWhlTqDecReqActv_flg' */

  /* Outputs for Atomic SubSystem: '<S176>/Subsys_VIPM_ESCWhlTqDecReqVal_Nm' */
  /* Logic: '<S217>/Logical Operator3' incorporates:
   *  Constant: '<S217>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_ESCWhlTqDecReqValVld_flg = (KIPM_ESCWhlTqDecReqVal_Nm_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_ESCMsgActv_flg);

  /* Switch: '<S217>/Switch4' incorporates:
   *  Constant: '<S217>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S217>/Switch'
   */
  if (KIPM_ESCWhlTqDecReqVal_Nm_ovrdflg) {
    /* MinMax: '<S212>/MinMax' incorporates:
     *  Constant: '<S217>/sat4'
     *  MinMax: '<S251>/MinMax'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCWhlTqDecReqVal_Nm_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
             ->VIPM_ESCMsgActv_flg) {
    /* Product: '<S228>/Product' incorporates:
     *  Constant: '<S228>/Constant'
     *  Inport: '<Root>/ESC_A_CHA'
     *  Switch: '<S217>/Switch'
     */
    rtb_Product_dq = (float32)(Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA
      ())->ESC_WhlTqDecReqVal * 0.5F;

    /* MinMax: '<S212>/MinMax' incorporates:
     *  MinMax: '<S251>/MinMax'
     *  Sum: '<S228>/Add'
     *  Switch: '<S217>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = rtb_Product_dq - 6200.0F;
  } else {
    /* MinMax: '<S212>/MinMax' incorporates:
     *  Constant: '<S217>/sat5'
     *  MinMax: '<S251>/MinMax'
     *  Switch: '<S217>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCWhlTqDecReqValDflt_Nm;
  }

  /* End of Switch: '<S217>/Switch4' */

  /* MinMax: '<S217>/MinMax' incorporates:
   *  Constant: '<S217>/sat6'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm > KIPM_ESCWhlTqDecReqValHi_Nm) {
    /* MinMax: '<S212>/MinMax' */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCWhlTqDecReqValHi_Nm;
  }

  /* End of MinMax: '<S217>/MinMax' */

  /* MinMax: '<S217>/MinMax1' incorporates:
   *  Constant: '<S217>/sat7'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm >= KIPM_ESCWhlTqDecReqValLo_Nm) {
    /* MinMax: '<S217>/MinMax1' */
    VIPM_ESCWhlTqDecReqVal_Nm = VIPM_INV3RecupTqAllwdMax_Nm;
  } else {
    /* MinMax: '<S217>/MinMax1' */
    VIPM_ESCWhlTqDecReqVal_Nm = KIPM_ESCWhlTqDecReqValLo_Nm;
  }

  /* End of MinMax: '<S217>/MinMax1' */
  /* End of Outputs for SubSystem: '<S176>/Subsys_VIPM_ESCWhlTqDecReqVal_Nm' */

  /* Outputs for Atomic SubSystem: '<S176>/Subsys_VIPM_ESCWhlTqIncReqActv_flg' */
  /* Logic: '<S218>/Logical Operator3' incorporates:
   *  Constant: '<S218>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_ESCWhlTqIncReqActvVld_flg = (KIPM_ESCWhlTqIncReqActv_flg_ovrdflg ||
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
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ofi =
      (Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA())->ESC_WhlTqIncReqActv;
  } else {
    /* Switch: '<S218>/Switch' incorporates:
     *  Constant: '<S218>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ofi = KIPM_ESCWhlTqIncReqActvDflt_flg;
  }

  /* End of Switch: '<S218>/Switch' */

  /* Switch: '<S218>/Switch4' incorporates:
   *  Constant: '<S218>/sat3'
   */
  if (KIPM_ESCWhlTqIncReqActv_flg_ovrdflg) {
    /* Switch: '<S218>/Switch4' incorporates:
     *  Constant: '<S218>/sat4'
     */
    VIPM_ESCWhlTqIncReqActv_flg = KIPM_ESCWhlTqIncReqActv_flg_ovrdval;
  } else {
    /* Switch: '<S218>/Switch4' */
    VIPM_ESCWhlTqIncReqActv_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ofi;
  }

  /* End of Switch: '<S218>/Switch4' */
  /* End of Outputs for SubSystem: '<S176>/Subsys_VIPM_ESCWhlTqIncReqActv_flg' */

  /* Outputs for Atomic SubSystem: '<S176>/Subsys_VIPM_ESCWhlTqIncReqVal_Nm' */
  /* Logic: '<S219>/Logical Operator3' incorporates:
   *  Constant: '<S219>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_ESCWhlTqIncReqValVld_flg = (KIPM_ESCWhlTqIncReqVal_Nm_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_ESCMsgActv_flg);

  /* Switch: '<S219>/Switch4' incorporates:
   *  Constant: '<S219>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S219>/Switch'
   */
  if (KIPM_ESCWhlTqIncReqVal_Nm_ovrdflg) {
    /* MinMax: '<S212>/MinMax' incorporates:
     *  Constant: '<S219>/sat4'
     *  MinMax: '<S251>/MinMax'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCWhlTqIncReqVal_Nm_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
             ->VIPM_ESCMsgActv_flg) {
    /* Product: '<S229>/Product' incorporates:
     *  Constant: '<S229>/Constant'
     *  Inport: '<Root>/ESC_A_CHA'
     *  Switch: '<S219>/Switch'
     */
    rtb_Product_dq = (float32)(Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA
      ())->ESC_WhlTqIncReqVal * 0.5F;

    /* MinMax: '<S212>/MinMax' incorporates:
     *  MinMax: '<S251>/MinMax'
     *  Sum: '<S229>/Add'
     *  Switch: '<S219>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = rtb_Product_dq - 6200.0F;
  } else {
    /* MinMax: '<S212>/MinMax' incorporates:
     *  Constant: '<S219>/sat5'
     *  MinMax: '<S251>/MinMax'
     *  Switch: '<S219>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCWhlTqIncReqValDflt_Nm;
  }

  /* End of Switch: '<S219>/Switch4' */

  /* MinMax: '<S219>/MinMax' incorporates:
   *  Constant: '<S219>/sat6'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm > KIPM_ESCWhlTqIncReqValHi_Nm) {
    /* MinMax: '<S212>/MinMax' */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCWhlTqIncReqValHi_Nm;
  }

  /* End of MinMax: '<S219>/MinMax' */

  /* MinMax: '<S219>/MinMax1' incorporates:
   *  Constant: '<S219>/sat7'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm >= KIPM_ESCWhlTqIncReqValLo_Nm) {
    /* MinMax: '<S219>/MinMax1' */
    VIPM_ESCWhlTqIncReqVal_Nm = VIPM_INV3RecupTqAllwdMax_Nm;
  } else {
    /* MinMax: '<S219>/MinMax1' */
    VIPM_ESCWhlTqIncReqVal_Nm = KIPM_ESCWhlTqIncReqValLo_Nm;
  }

  /* End of MinMax: '<S219>/MinMax1' */
  /* End of Outputs for SubSystem: '<S176>/Subsys_VIPM_ESCWhlTqIncReqVal_Nm' */

  /* BusCreator: '<S176>/BusCreator' incorporates:
   *  Logic: '<S204>/Logical Operator3'
   *  Logic: '<S205>/Logical Operator3'
   *  Logic: '<S206>/Logical Operator3'
   *  Logic: '<S207>/Logical Operator3'
   *  Logic: '<S208>/Logical Operator3'
   *  Logic: '<S209>/Logical Operator3'
   *  Logic: '<S210>/Logical Operator3'
   *  Logic: '<S211>/Logical Operator3'
   *  Logic: '<S212>/Logical Operator3'
   *  Logic: '<S213>/Logical Operator3'
   *  Logic: '<S214>/Logical Operator3'
   *  Logic: '<S215>/Logical Operator3'
   *  Logic: '<S216>/Logical Operator3'
   *  Logic: '<S217>/Logical Operator3'
   *  Logic: '<S218>/Logical Operator3'
   *  Logic: '<S219>/Logical Operator3'
   *  Logic: '<S220>/Logical Operator3'
   *  MinMax: '<S204>/MinMax1'
   *  MinMax: '<S205>/MinMax1'
   *  MinMax: '<S206>/MinMax1'
   *  MinMax: '<S212>/MinMax1'
   *  MinMax: '<S213>/MinMax1'
   *  MinMax: '<S214>/MinMax1'
   *  MinMax: '<S215>/MinMax1'
   *  MinMax: '<S217>/MinMax1'
   *  MinMax: '<S219>/MinMax1'
   *  MinMax: '<S220>/MinMax1'
   *  Switch: '<S207>/Switch4'
   *  Switch: '<S208>/Switch4'
   *  Switch: '<S209>/Switch4'
   *  Switch: '<S210>/Switch4'
   *  Switch: '<S211>/Switch4'
   *  Switch: '<S216>/Switch4'
   *  Switch: '<S218>/Switch4'
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

  /* Outputs for Atomic SubSystem: '<S230>/Subsys_VIPM_INV1MotSpd_rpm' */
  /* Logic: '<S237>/Logical Operator3' incorporates:
   *  Constant: '<S237>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_INV1MotSpdVld_flg = (KIPM_INV1MotSpd_rpm_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_INVMsgActv_flg);

  /* Switch: '<S237>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_INVMsgActv_flg) {
    /* Switch: '<S237>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_INV_1_Value_CRCFlt_flg) {
      /* Product: '<S241>/Product' incorporates:
       *  Inport: '<Root>/INV_1_Value_EPT'
       */
      rtb_Product_i4 =
        (Rte_IRead_Runbl_IpmCanRx_10ms_INV_1_Value_EPT_INV_1_Value_EPT())
        ->INV_1_MotSpeed;

      /* Switch: '<S237>/Switch' incorporates:
       *  Sum: '<S241>/Add'
       *  Switch: '<S237>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jy = (float32)rtb_Product_i4 -
        12000.0F;
    }

    /* End of Switch: '<S237>/Switch3' */
  } else {
    /* Switch: '<S237>/Switch' incorporates:
     *  Constant: '<S237>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jy = KIPM_INV1MotSpdDflt_rpm;
  }

  /* End of Switch: '<S237>/Switch' */

  /* Switch: '<S237>/Switch4' incorporates:
   *  Constant: '<S237>/sat3'
   *  Constant: '<S237>/sat4'
   */
  if (KIPM_INV1MotSpd_rpm_ovrdflg) {
    VIPM_INV1MotSpd_rpm = KIPM_INV1MotSpd_rpm_ovrdval;
  } else {
    VIPM_INV1MotSpd_rpm = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jy;
  }

  /* MinMax: '<S237>/MinMax' incorporates:
   *  Constant: '<S237>/sat6'
   *  Switch: '<S237>/Switch4'
   */
  if (VIPM_INV1MotSpd_rpm > KIPM_INV1MotSpdHi_rpm) {
    VIPM_INV1MotSpd_rpm = KIPM_INV1MotSpdHi_rpm;
  }

  /* End of MinMax: '<S237>/MinMax' */

  /* MinMax: '<S237>/MinMax1' incorporates:
   *  Constant: '<S237>/sat7'
   */
  if (VIPM_INV1MotSpd_rpm < KIPM_INV1MotSpdLo_rpm) {
    /* Switch: '<S237>/Switch4' incorporates:
     *  MinMax: '<S237>/MinMax1'
     */
    VIPM_INV1MotSpd_rpm = KIPM_INV1MotSpdLo_rpm;
  }

  /* End of MinMax: '<S237>/MinMax1' */
  /* End of Outputs for SubSystem: '<S230>/Subsys_VIPM_INV1MotSpd_rpm' */

  /* Outputs for Atomic SubSystem: '<S230>/Subsys_VIPM_INV1ActTorq_Nm' */
  /* Logic: '<S235>/Logical Operator3' incorporates:
   *  Constant: '<S235>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_INV1ActTorqVld_flg = (KIPM_INV1ActTorq_Nm_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_INVMsgActv_flg);

  /* Switch: '<S235>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_INVMsgActv_flg) {
    /* Switch: '<S235>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_INV_1_Value_CRCFlt_flg) {
      /* Product: '<S242>/Product' incorporates:
       *  Constant: '<S242>/Constant'
       *  Inport: '<Root>/INV_1_Value_EPT'
       */
      rtb_Product_dq = (float32)
        (Rte_IRead_Runbl_IpmCanRx_10ms_INV_1_Value_EPT_INV_1_Value_EPT())
        ->INV_1_ActTorque * 0.1F;

      /* Switch: '<S235>/Switch' incorporates:
       *  Sum: '<S242>/Add'
       *  Switch: '<S235>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_k = rtb_Product_dq - 819.2F;
    }

    /* End of Switch: '<S235>/Switch3' */
  } else {
    /* Switch: '<S235>/Switch' incorporates:
     *  Constant: '<S235>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_k = KIPM_INV1ActTorqDflt_Nm;
  }

  /* End of Switch: '<S235>/Switch' */

  /* Switch: '<S235>/Switch4' incorporates:
   *  Constant: '<S235>/sat3'
   *  Constant: '<S235>/sat4'
   */
  if (KIPM_INV1ActTorq_Nm_ovrdflg) {
    VIPM_INV1ActTorq_Nm = KIPM_INV1ActTorq_Nm_ovrdval;
  } else {
    VIPM_INV1ActTorq_Nm = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_k;
  }

  /* MinMax: '<S235>/MinMax' incorporates:
   *  Constant: '<S235>/sat6'
   *  Switch: '<S235>/Switch4'
   */
  if (VIPM_INV1ActTorq_Nm > KIPM_INV1ActTorqHi_Nm) {
    VIPM_INV1ActTorq_Nm = KIPM_INV1ActTorqHi_Nm;
  }

  /* End of MinMax: '<S235>/MinMax' */

  /* MinMax: '<S235>/MinMax1' incorporates:
   *  Constant: '<S235>/sat7'
   */
  if (VIPM_INV1ActTorq_Nm < KIPM_INV1ActTorqLo_Nm) {
    /* Switch: '<S235>/Switch4' incorporates:
     *  MinMax: '<S235>/MinMax1'
     */
    VIPM_INV1ActTorq_Nm = KIPM_INV1ActTorqLo_Nm;
  }

  /* End of MinMax: '<S235>/MinMax1' */
  /* End of Outputs for SubSystem: '<S230>/Subsys_VIPM_INV1ActTorq_Nm' */

  /* Outputs for Atomic SubSystem: '<S230>/Subsys_VIPM_INV1PreChrgAllwd_enum' */
  /* Logic: '<S238>/Logical Operator3' incorporates:
   *  Constant: '<S238>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_INV1PreChrgAllwdVld_flg = (KIPM_INV1PreChrgAllwd_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_INVMsgActv_flg);

  /* Switch: '<S238>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_INVMsgActv_flg) {
    /* Switch: '<S238>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_INV_1_Value_CRCFlt_flg) {
      /* Switch: '<S238>/Switch' incorporates:
       *  Inport: '<Root>/INV_1_Value_EPT'
       *  Switch: '<S238>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_gn =
        (Rte_IRead_Runbl_IpmCanRx_10ms_INV_1_Value_EPT_INV_1_Value_EPT())
        ->INV_1_PreChargeAllowed;
    }

    /* End of Switch: '<S238>/Switch3' */
  } else {
    /* Switch: '<S238>/Switch' incorporates:
     *  Constant: '<S238>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_gn = KIPM_INV1PreChrgAllwdDflt_enum;
  }

  /* End of Switch: '<S238>/Switch' */

  /* Switch: '<S238>/Switch4' incorporates:
   *  Constant: '<S238>/sat3'
   */
  if (KIPM_INV1PreChrgAllwd_enum_ovrdflg) {
    /* Switch: '<S238>/Switch4' incorporates:
     *  Constant: '<S238>/sat4'
     */
    VIPM_INV1PreChrgAllwd_enum = KIPM_INV1PreChrgAllwd_enum_ovrdval;
  } else {
    /* Switch: '<S238>/Switch4' */
    VIPM_INV1PreChrgAllwd_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_gn;
  }

  /* End of Switch: '<S238>/Switch4' */
  /* End of Outputs for SubSystem: '<S230>/Subsys_VIPM_INV1PreChrgAllwd_enum' */

  /* Outputs for Atomic SubSystem: '<S230>/Subsys_VIPM_INV1ShutdownAllwd_enum' */
  /* Logic: '<S240>/Logical Operator3' incorporates:
   *  Constant: '<S240>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_INV1ShutdownAllwdVld_flg = (KIPM_INV1ShutdownAllwd_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_INVMsgActv_flg);

  /* Switch: '<S240>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_INVMsgActv_flg) {
    /* Switch: '<S240>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_INV_1_Value_CRCFlt_flg) {
      /* Switch: '<S240>/Switch' incorporates:
       *  Inport: '<Root>/INV_1_Value_EPT'
       *  Switch: '<S240>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nu =
        (Rte_IRead_Runbl_IpmCanRx_10ms_INV_1_Value_EPT_INV_1_Value_EPT())
        ->INV_1_ShutdownAllowed;
    }

    /* End of Switch: '<S240>/Switch3' */
  } else {
    /* Switch: '<S240>/Switch' incorporates:
     *  Constant: '<S240>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nu = KIPM_INV1ShutdownAllwdDflt_enum;
  }

  /* End of Switch: '<S240>/Switch' */

  /* Switch: '<S240>/Switch4' incorporates:
   *  Constant: '<S240>/sat3'
   */
  if (KIPM_INV1ShutdownAllwd_enum_ovrdflg) {
    /* Switch: '<S240>/Switch4' incorporates:
     *  Constant: '<S240>/sat4'
     */
    VIPM_INV1ShutdownAllwd_enum = KIPM_INV1ShutdownAllwd_enum_ovrdval;
  } else {
    /* Switch: '<S240>/Switch4' */
    VIPM_INV1ShutdownAllwd_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nu;
  }

  /* End of Switch: '<S240>/Switch4' */
  /* End of Outputs for SubSystem: '<S230>/Subsys_VIPM_INV1ShutdownAllwd_enum' */

  /* Outputs for Atomic SubSystem: '<S230>/Subsys_VIPM_INV1ActMode_enum' */
  /* Logic: '<S234>/Logical Operator3' incorporates:
   *  Constant: '<S234>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_INV1ActModeVld_flg = (KIPM_INV1ActMode_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_INVMsgActv_flg);

  /* Switch: '<S234>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_INVMsgActv_flg) {
    /* Switch: '<S234>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_INV_1_Value_CRCFlt_flg) {
      /* Switch: '<S234>/Switch' incorporates:
       *  DataTypeConversion: '<S234>/Data Type Conversion2'
       *  Inport: '<Root>/INV_1_Value_EPT'
       *  Switch: '<S234>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cw =
        (Rte_IRead_Runbl_IpmCanRx_10ms_INV_1_Value_EPT_INV_1_Value_EPT())
        ->INV_1_ActMode;
    }

    /* End of Switch: '<S234>/Switch3' */
  } else {
    /* Switch: '<S234>/Switch' incorporates:
     *  Constant: '<S234>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cw = KIPM_INV1ActModeDflt_enum;
  }

  /* End of Switch: '<S234>/Switch' */

  /* Switch: '<S234>/Switch4' incorporates:
   *  Constant: '<S234>/sat3'
   */
  if (KIPM_INV1ActMode_enum_ovrdflg) {
    /* Switch: '<S234>/Switch4' incorporates:
     *  Constant: '<S234>/sat4'
     */
    VIPM_INV1ActMode_enum = KIPM_INV1ActMode_enum_ovrdval;
  } else {
    /* Switch: '<S234>/Switch4' incorporates:
     *  Switch: '<S234>/Switch'
     */
    VIPM_INV1ActMode_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cw;
  }

  /* End of Switch: '<S234>/Switch4' */
  /* End of Outputs for SubSystem: '<S230>/Subsys_VIPM_INV1ActMode_enum' */

  /* Outputs for Atomic SubSystem: '<S230>/Subsys_VIPM_INV1PreprogmFlg_flg' */
  /* Logic: '<S239>/Logical Operator3' incorporates:
   *  Constant: '<S239>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_INV1PreprogmFlgVld_flg = (KIPM_INV1PreprogmFlg_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_INVMsgActv_flg);

  /* Switch: '<S239>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_INVMsgActv_flg) {
    /* Switch: '<S239>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_INV_1_Value_CRCFlt_flg) {
      /* Switch: '<S239>/Switch' incorporates:
       *  Inport: '<Root>/INV_1_Value_EPT'
       *  Switch: '<S239>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_mvx =
        (Rte_IRead_Runbl_IpmCanRx_10ms_INV_1_Value_EPT_INV_1_Value_EPT())
        ->INV_PreprogmFlg;
    }

    /* End of Switch: '<S239>/Switch3' */
  } else {
    /* Switch: '<S239>/Switch' incorporates:
     *  Constant: '<S239>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_mvx = KIPM_INV1PreprogmFlgDflt_flg;
  }

  /* End of Switch: '<S239>/Switch' */

  /* Switch: '<S239>/Switch4' incorporates:
   *  Constant: '<S239>/sat3'
   */
  if (KIPM_INV1PreprogmFlg_flg_ovrdflg) {
    /* Switch: '<S239>/Switch4' incorporates:
     *  Constant: '<S239>/sat4'
     */
    VIPM_INV1PreprogmFlg_flg = KIPM_INV1PreprogmFlg_flg_ovrdval;
  } else {
    /* Switch: '<S239>/Switch4' */
    VIPM_INV1PreprogmFlg_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_mvx;
  }

  /* End of Switch: '<S239>/Switch4' */
  /* End of Outputs for SubSystem: '<S230>/Subsys_VIPM_INV1PreprogmFlg_flg' */

  /* Outputs for Atomic SubSystem: '<S230>/Subsys_VIPM_INV1AntithftAuthRslt_enum' */
  /* Logic: '<S236>/Logical Operator3' incorporates:
   *  Constant: '<S236>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_INV1AntithftAuthRsltVld_flg = (KIPM_INV1AntithftAuthRslt_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_INVMsgActv_flg);

  /* Switch: '<S236>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_INVMsgActv_flg) {
    /* Switch: '<S236>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_INV_1_Value_CRCFlt_flg) {
      /* Switch: '<S236>/Switch' incorporates:
       *  Inport: '<Root>/INV_1_Value_EPT'
       *  Switch: '<S236>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jq =
        (Rte_IRead_Runbl_IpmCanRx_10ms_INV_1_Value_EPT_INV_1_Value_EPT())
        ->INV_AntithftAuthRslt;
    }

    /* End of Switch: '<S236>/Switch3' */
  } else {
    /* Switch: '<S236>/Switch' incorporates:
     *  Constant: '<S236>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jq = KIPM_INV1AntithftAuthRsltDflt_enum;
  }

  /* End of Switch: '<S236>/Switch' */

  /* Switch: '<S236>/Switch4' incorporates:
   *  Constant: '<S236>/sat3'
   */
  if (KIPM_INV1AntithftAuthRslt_enum_ovrdflg) {
    /* Switch: '<S236>/Switch4' incorporates:
     *  Constant: '<S236>/sat4'
     */
    VIPM_INV1AntithftAuthRslt_enum = KIPM_INV1AntithftAuthRslt_enum_ovrdval;
  } else {
    /* Switch: '<S236>/Switch4' */
    VIPM_INV1AntithftAuthRslt_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jq;
  }

  /* End of Switch: '<S236>/Switch4' */
  /* End of Outputs for SubSystem: '<S230>/Subsys_VIPM_INV1AntithftAuthRslt_enum' */

  /* BusCreator: '<S230>/BusCreator' incorporates:
   *  DataTypeConversion: '<S230>/Data Type Conversion'
   *  Logic: '<S234>/Logical Operator3'
   *  Logic: '<S235>/Logical Operator3'
   *  Logic: '<S236>/Logical Operator3'
   *  Logic: '<S237>/Logical Operator3'
   *  Logic: '<S238>/Logical Operator3'
   *  Logic: '<S239>/Logical Operator3'
   *  Logic: '<S240>/Logical Operator3'
   *  MinMax: '<S235>/MinMax1'
   *  MinMax: '<S237>/MinMax1'
   *  Switch: '<S234>/Switch4'
   *  Switch: '<S236>/Switch4'
   *  Switch: '<S238>/Switch4'
   *  Switch: '<S239>/Switch4'
   *  Switch: '<S240>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_INV_1_Value_EPT.VIPM_INV1MotSpd_rpm =
    VIPM_INV1MotSpd_rpm;
  AppSwcIpm_ARID_DEF.IPM_INV_1_Value_EPT.VIPM_INV1MotSpdVld_flg =
    VIPM_INV1MotSpdVld_flg;
  AppSwcIpm_ARID_DEF.IPM_INV_1_Value_EPT.VIPM_INV1ActTorq_Nm =
    VIPM_INV1ActTorq_Nm;
  AppSwcIpm_ARID_DEF.IPM_INV_1_Value_EPT.VIPM_INV1ActTorqVld_flg =
    VIPM_INV1ActTorqVld_flg;
  AppSwcIpm_ARID_DEF.IPM_INV_1_Value_EPT.VIPM_INV1PreChrgAllwd_enum =
    VIPM_INV1PreChrgAllwd_enum;
  AppSwcIpm_ARID_DEF.IPM_INV_1_Value_EPT.VIPM_INV1PreChrgAllwdVld_flg =
    VIPM_INV1PreChrgAllwdVld_flg;
  AppSwcIpm_ARID_DEF.IPM_INV_1_Value_EPT.VIPM_INV1ShutdownAllwd_enum =
    VIPM_INV1ShutdownAllwd_enum;
  AppSwcIpm_ARID_DEF.IPM_INV_1_Value_EPT.VIPM_INV1ShutdownAllwdVld_flg =
    VIPM_INV1ShutdownAllwdVld_flg;
  AppSwcIpm_ARID_DEF.IPM_INV_1_Value_EPT.VIPM_INV1ActMode_enum =
    VIPM_INV1ActMode_enum;
  AppSwcIpm_ARID_DEF.IPM_INV_1_Value_EPT.VIPM_INV1ActModeVld_flg =
    VIPM_INV1ActModeVld_flg;
  AppSwcIpm_ARID_DEF.IPM_INV_1_Value_EPT.VIPM_INV1PreprogmFlg_flg =
    VIPM_INV1PreprogmFlg_flg;
  AppSwcIpm_ARID_DEF.IPM_INV_1_Value_EPT.VIPM_INV1PreprogmFlgVld_flg =
    VIPM_INV1PreprogmFlgVld_flg;
  AppSwcIpm_ARID_DEF.IPM_INV_1_Value_EPT.VIPM_INV1AntithftAuthRslt_enum =
    VIPM_INV1AntithftAuthRslt_enum;
  AppSwcIpm_ARID_DEF.IPM_INV_1_Value_EPT.VIPM_INV1AntithftAuthRsltVld_flg =
    VIPM_INV1AntithftAuthRsltVld_flg;

  /* Outputs for Atomic SubSystem: '<S231>/Subsys_VIPM_INV2MotorMaxTemp_C' */
  /* Logic: '<S246>/Logical Operator3' incorporates:
   *  Constant: '<S246>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_INV2MotorMaxTempVld_flg = (KIPM_INV2MotorMaxTemp_C_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_INVMsgActv_flg);

  /* Switch: '<S246>/Switch4' incorporates:
   *  Constant: '<S246>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S246>/Switch'
   */
  if (KIPM_INV2MotorMaxTemp_C_ovrdflg) {
    /* MinMax: '<S212>/MinMax' incorporates:
     *  Constant: '<S246>/sat4'
     *  MinMax: '<S251>/MinMax'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_INV2MotorMaxTemp_C_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
             ->VIPM_INVMsgActv_flg) {
    /* Product: '<S247>/Product' incorporates:
     *  Inport: '<Root>/INV_2_Value_EPT'
     *  Switch: '<S246>/Switch'
     */
    rtb_Product_i4 =
      (Rte_IRead_Runbl_IpmCanRx_10ms_INV_2_Value_EPT_INV_2_Value_EPT())
      ->INV_2_MotorMaxTem;

    /* MinMax: '<S212>/MinMax' incorporates:
     *  MinMax: '<S251>/MinMax'
     *  Sum: '<S247>/Add'
     *  Switch: '<S246>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = (float32)rtb_Product_i4 - 40.0F;
  } else {
    /* MinMax: '<S212>/MinMax' incorporates:
     *  Constant: '<S246>/sat5'
     *  MinMax: '<S251>/MinMax'
     *  Switch: '<S246>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_INV2MotorMaxTempDflt_C;
  }

  /* End of Switch: '<S246>/Switch4' */

  /* MinMax: '<S246>/MinMax' incorporates:
   *  Constant: '<S246>/sat6'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm > KIPM_INV2MotorMaxTempHi_C) {
    /* MinMax: '<S212>/MinMax' */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_INV2MotorMaxTempHi_C;
  }

  /* End of MinMax: '<S246>/MinMax' */

  /* MinMax: '<S246>/MinMax1' incorporates:
   *  Constant: '<S246>/sat7'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm >= KIPM_INV2MotorMaxTempLo_C) {
    /* MinMax: '<S246>/MinMax1' */
    VIPM_INV2MotorMaxTemp_C = VIPM_INV3RecupTqAllwdMax_Nm;
  } else {
    /* MinMax: '<S246>/MinMax1' */
    VIPM_INV2MotorMaxTemp_C = KIPM_INV2MotorMaxTempLo_C;
  }

  /* End of MinMax: '<S246>/MinMax1' */
  /* End of Outputs for SubSystem: '<S231>/Subsys_VIPM_INV2MotorMaxTemp_C' */

  /* Outputs for Atomic SubSystem: '<S231>/Subsys_VIPM_INV2IgbtMaxTemp_C' */
  /* Logic: '<S243>/Logical Operator3' incorporates:
   *  Constant: '<S243>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_INV2IgbtMaxTempVld_flg = (KIPM_INV2IgbtMaxTemp_C_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_INVMsgActv_flg);

  /* Switch: '<S243>/Switch4' incorporates:
   *  Constant: '<S243>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S243>/Switch'
   */
  if (KIPM_INV2IgbtMaxTemp_C_ovrdflg) {
    /* MinMax: '<S212>/MinMax' incorporates:
     *  Constant: '<S243>/sat4'
     *  MinMax: '<S251>/MinMax'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_INV2IgbtMaxTemp_C_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
             ->VIPM_INVMsgActv_flg) {
    /* Product: '<S248>/Product' incorporates:
     *  Inport: '<Root>/INV_2_Value_EPT'
     *  Switch: '<S243>/Switch'
     */
    rtb_Product_i4 =
      (Rte_IRead_Runbl_IpmCanRx_10ms_INV_2_Value_EPT_INV_2_Value_EPT())
      ->INV_2_IgbtMaxTem;

    /* MinMax: '<S212>/MinMax' incorporates:
     *  MinMax: '<S251>/MinMax'
     *  Sum: '<S248>/Add'
     *  Switch: '<S243>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = (float32)rtb_Product_i4 - 40.0F;
  } else {
    /* MinMax: '<S212>/MinMax' incorporates:
     *  Constant: '<S243>/sat5'
     *  MinMax: '<S251>/MinMax'
     *  Switch: '<S243>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_INV2IgbtMaxTempDflt_C;
  }

  /* End of Switch: '<S243>/Switch4' */

  /* MinMax: '<S243>/MinMax' incorporates:
   *  Constant: '<S243>/sat6'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm > KIPM_INV2IgbtMaxTempHi_C) {
    /* MinMax: '<S212>/MinMax' */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_INV2IgbtMaxTempHi_C;
  }

  /* End of MinMax: '<S243>/MinMax' */

  /* MinMax: '<S243>/MinMax1' incorporates:
   *  Constant: '<S243>/sat7'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm >= KIPM_INV2IgbtMaxTempLo_C) {
    /* MinMax: '<S243>/MinMax1' */
    VIPM_INV2IgbtMaxTemp_C = VIPM_INV3RecupTqAllwdMax_Nm;
  } else {
    /* MinMax: '<S243>/MinMax1' */
    VIPM_INV2IgbtMaxTemp_C = KIPM_INV2IgbtMaxTempLo_C;
  }

  /* End of MinMax: '<S243>/MinMax1' */
  /* End of Outputs for SubSystem: '<S231>/Subsys_VIPM_INV2IgbtMaxTemp_C' */

  /* Outputs for Atomic SubSystem: '<S231>/Subsys_VIPM_INV2InpCurnt_A' */
  /* Logic: '<S244>/Logical Operator3' incorporates:
   *  Constant: '<S244>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_INV2InpCurntVld_flg = (KIPM_INV2InpCurnt_A_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_INVMsgActv_flg);

  /* Switch: '<S244>/Switch4' incorporates:
   *  Constant: '<S244>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S244>/Switch'
   */
  if (KIPM_INV2InpCurnt_A_ovrdflg) {
    /* MinMax: '<S212>/MinMax' incorporates:
     *  Constant: '<S244>/sat4'
     *  MinMax: '<S251>/MinMax'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_INV2InpCurnt_A_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
             ->VIPM_INVMsgActv_flg) {
    /* Product: '<S249>/Product' incorporates:
     *  Constant: '<S249>/Constant'
     *  Inport: '<Root>/INV_2_Value_EPT'
     *  Switch: '<S244>/Switch'
     */
    rtb_Product_dq = (float32)
      (Rte_IRead_Runbl_IpmCanRx_10ms_INV_2_Value_EPT_INV_2_Value_EPT())
      ->INV_2_InpCurrent * 0.1F;

    /* MinMax: '<S212>/MinMax' incorporates:
     *  MinMax: '<S251>/MinMax'
     *  Sum: '<S249>/Add'
     *  Switch: '<S244>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = rtb_Product_dq - 819.2F;
  } else {
    /* MinMax: '<S212>/MinMax' incorporates:
     *  Constant: '<S244>/sat5'
     *  MinMax: '<S251>/MinMax'
     *  Switch: '<S244>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_INV2InpCurntDflt_A;
  }

  /* End of Switch: '<S244>/Switch4' */

  /* MinMax: '<S244>/MinMax' incorporates:
   *  Constant: '<S244>/sat6'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm > KIPM_INV2InpCurntHi_A) {
    /* MinMax: '<S212>/MinMax' */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_INV2InpCurntHi_A;
  }

  /* End of MinMax: '<S244>/MinMax' */

  /* MinMax: '<S244>/MinMax1' incorporates:
   *  Constant: '<S244>/sat7'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm >= KIPM_INV2InpCurntLo_A) {
    /* MinMax: '<S244>/MinMax1' */
    VIPM_INV2InpCurnt_A = VIPM_INV3RecupTqAllwdMax_Nm;
  } else {
    /* MinMax: '<S244>/MinMax1' */
    VIPM_INV2InpCurnt_A = KIPM_INV2InpCurntLo_A;
  }

  /* End of MinMax: '<S244>/MinMax1' */
  /* End of Outputs for SubSystem: '<S231>/Subsys_VIPM_INV2InpCurnt_A' */

  /* Outputs for Atomic SubSystem: '<S231>/Subsys_VIPM_INV2InpVolt_V' */
  /* Logic: '<S245>/Logical Operator3' incorporates:
   *  Constant: '<S245>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_INV2InpVoltVld_flg = (KIPM_INV2InpVolt_V_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_INVMsgActv_flg);

  /* Switch: '<S245>/Switch4' incorporates:
   *  Constant: '<S245>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S245>/Switch'
   */
  if (KIPM_INV2InpVolt_V_ovrdflg) {
    /* MinMax: '<S212>/MinMax' incorporates:
     *  Constant: '<S245>/sat4'
     *  MinMax: '<S251>/MinMax'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_INV2InpVolt_V_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
             ->VIPM_INVMsgActv_flg) {
    /* MinMax: '<S212>/MinMax' incorporates:
     *  DataTypeConversion: '<S245>/Data Type Conversion2'
     *  Inport: '<Root>/INV_2_Value_EPT'
     *  MinMax: '<S251>/MinMax'
     *  Switch: '<S245>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = (float32)
      (Rte_IRead_Runbl_IpmCanRx_10ms_INV_2_Value_EPT_INV_2_Value_EPT())
      ->INV_2_InpVoltage;
  } else {
    /* MinMax: '<S212>/MinMax' incorporates:
     *  Constant: '<S245>/sat5'
     *  MinMax: '<S251>/MinMax'
     *  Switch: '<S245>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_INV2InpVoltDflt_V;
  }

  /* End of Switch: '<S245>/Switch4' */

  /* MinMax: '<S245>/MinMax' incorporates:
   *  Constant: '<S245>/sat6'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm > KIPM_INV2InpVoltHi_V) {
    /* MinMax: '<S212>/MinMax' */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_INV2InpVoltHi_V;
  }

  /* End of MinMax: '<S245>/MinMax' */

  /* MinMax: '<S245>/MinMax1' incorporates:
   *  Constant: '<S245>/sat7'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm >= KIPM_INV2InpVoltLo_V) {
    /* MinMax: '<S245>/MinMax1' */
    VIPM_INV2InpVolt_V = VIPM_INV3RecupTqAllwdMax_Nm;
  } else {
    /* MinMax: '<S245>/MinMax1' */
    VIPM_INV2InpVolt_V = KIPM_INV2InpVoltLo_V;
  }

  /* End of MinMax: '<S245>/MinMax1' */
  /* End of Outputs for SubSystem: '<S231>/Subsys_VIPM_INV2InpVolt_V' */

  /* BusCreator: '<S231>/BusCreator' incorporates:
   *  Logic: '<S243>/Logical Operator3'
   *  Logic: '<S244>/Logical Operator3'
   *  Logic: '<S245>/Logical Operator3'
   *  Logic: '<S246>/Logical Operator3'
   *  MinMax: '<S243>/MinMax1'
   *  MinMax: '<S244>/MinMax1'
   *  MinMax: '<S245>/MinMax1'
   *  MinMax: '<S246>/MinMax1'
   */
  AppSwcIpm_ARID_DEF.IPM_INV_2_Value_EPT.VIPM_INV2MotorMaxTemp_C =
    VIPM_INV2MotorMaxTemp_C;
  AppSwcIpm_ARID_DEF.IPM_INV_2_Value_EPT.VIPM_INV2MotorMaxTempVld_flg =
    VIPM_INV2MotorMaxTempVld_flg;
  AppSwcIpm_ARID_DEF.IPM_INV_2_Value_EPT.VIPM_INV2IgbtMaxTemp_C =
    VIPM_INV2IgbtMaxTemp_C;
  AppSwcIpm_ARID_DEF.IPM_INV_2_Value_EPT.VIPM_INV2IgbtMaxTempVld_flg =
    VIPM_INV2IgbtMaxTempVld_flg;
  AppSwcIpm_ARID_DEF.IPM_INV_2_Value_EPT.VIPM_INV2InpCurnt_A =
    VIPM_INV2InpCurnt_A;
  AppSwcIpm_ARID_DEF.IPM_INV_2_Value_EPT.VIPM_INV2InpCurntVld_flg =
    VIPM_INV2InpCurntVld_flg;
  AppSwcIpm_ARID_DEF.IPM_INV_2_Value_EPT.VIPM_INV2InpVolt_V = VIPM_INV2InpVolt_V;
  AppSwcIpm_ARID_DEF.IPM_INV_2_Value_EPT.VIPM_INV2InpVoltVld_flg =
    VIPM_INV2InpVoltVld_flg;

  /* Outputs for Atomic SubSystem: '<S232>/Subsys_VIPM_INV3DrvTqAllwdMax_Nm' */
  /* Logic: '<S250>/Logical Operator3' incorporates:
   *  Constant: '<S250>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_INV3DrvTqAllwdMaxVld_flg = (KIPM_INV3DrvTqAllwdMax_Nm_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_INVMsgActv_flg);

  /* Switch: '<S250>/Switch4' incorporates:
   *  Constant: '<S250>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S250>/Switch'
   */
  if (KIPM_INV3DrvTqAllwdMax_Nm_ovrdflg) {
    /* MinMax: '<S212>/MinMax' incorporates:
     *  Constant: '<S250>/sat4'
     *  MinMax: '<S251>/MinMax'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_INV3DrvTqAllwdMax_Nm_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
             ->VIPM_INVMsgActv_flg) {
    /* MinMax: '<S212>/MinMax' incorporates:
     *  Constant: '<S252>/Constant'
     *  Inport: '<Root>/INV_3_Value_EPT'
     *  MinMax: '<S251>/MinMax'
     *  Product: '<S252>/Product'
     *  Switch: '<S250>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = (float32)
      (Rte_IRead_Runbl_IpmCanRx_10ms_INV_3_Value_EPT_INV_3_Value_EPT())
      ->INV_3_DriveTqAllowedMax * 0.5F;
  } else {
    /* MinMax: '<S212>/MinMax' incorporates:
     *  Constant: '<S250>/sat5'
     *  MinMax: '<S251>/MinMax'
     *  Switch: '<S250>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_INV3DrvTqAllwdMaxDflt_Nm;
  }

  /* End of Switch: '<S250>/Switch4' */

  /* MinMax: '<S250>/MinMax' incorporates:
   *  Constant: '<S250>/sat6'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm > KIPM_INV3DrvTqAllwdMaxHi_Nm) {
    /* MinMax: '<S212>/MinMax' */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_INV3DrvTqAllwdMaxHi_Nm;
  }

  /* End of MinMax: '<S250>/MinMax' */

  /* MinMax: '<S250>/MinMax1' incorporates:
   *  Constant: '<S250>/sat7'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm >= KIPM_INV3DrvTqAllwdMaxLo_Nm) {
    /* MinMax: '<S250>/MinMax1' */
    VIPM_INV3DrvTqAllwdMax_Nm = VIPM_INV3RecupTqAllwdMax_Nm;
  } else {
    /* MinMax: '<S250>/MinMax1' */
    VIPM_INV3DrvTqAllwdMax_Nm = KIPM_INV3DrvTqAllwdMaxLo_Nm;
  }

  /* End of MinMax: '<S250>/MinMax1' */
  /* End of Outputs for SubSystem: '<S232>/Subsys_VIPM_INV3DrvTqAllwdMax_Nm' */

  /* Outputs for Atomic SubSystem: '<S232>/Subsys_VIPM_INV3RecupTqAllwdMax_Nm' */
  /* Logic: '<S251>/Logical Operator3' incorporates:
   *  Constant: '<S251>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_INV3RecupTqAllwdMaxVld_flg = (KIPM_INV3RecupTqAllwdMax_Nm_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_INVMsgActv_flg);

  /* Switch: '<S251>/Switch4' incorporates:
   *  Constant: '<S251>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S251>/Switch'
   */
  if (KIPM_INV3RecupTqAllwdMax_Nm_ovrdflg) {
    /* MinMax: '<S212>/MinMax' incorporates:
     *  Constant: '<S251>/sat4'
     *  MinMax: '<S251>/MinMax'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_INV3RecupTqAllwdMax_Nm_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
             ->VIPM_INVMsgActv_flg) {
    /* Product: '<S253>/Product' incorporates:
     *  Constant: '<S253>/Constant'
     *  Inport: '<Root>/INV_3_Value_EPT'
     *  Switch: '<S251>/Switch'
     */
    rtb_Product_dq = (float32)
      (Rte_IRead_Runbl_IpmCanRx_10ms_INV_3_Value_EPT_INV_3_Value_EPT())
      ->INV_3_RecuperationTqAllowedMax * 0.5F;

    /* MinMax: '<S212>/MinMax' incorporates:
     *  MinMax: '<S251>/MinMax'
     *  Sum: '<S253>/Add'
     *  Switch: '<S251>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = rtb_Product_dq - 500.0F;
  } else {
    /* MinMax: '<S212>/MinMax' incorporates:
     *  Constant: '<S251>/sat5'
     *  MinMax: '<S251>/MinMax'
     *  Switch: '<S251>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_INV3RecupTqAllwdMaxDflt_Nm;
  }

  /* End of Switch: '<S251>/Switch4' */

  /* MinMax: '<S251>/MinMax' incorporates:
   *  Constant: '<S251>/sat6'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm > KIPM_INV3RecupTqAllwdMaxHi_Nm) {
    /* MinMax: '<S212>/MinMax' */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_INV3RecupTqAllwdMaxHi_Nm;
  }

  /* End of MinMax: '<S251>/MinMax' */

  /* MinMax: '<S251>/MinMax1' incorporates:
   *  Constant: '<S251>/sat7'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm < KIPM_INV3RecupTqAllwdMaxLo_Nm) {
    /* MinMax: '<S212>/MinMax' incorporates:
     *  MinMax: '<S251>/MinMax1'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_INV3RecupTqAllwdMaxLo_Nm;
  }

  /* End of MinMax: '<S251>/MinMax1' */
  /* End of Outputs for SubSystem: '<S232>/Subsys_VIPM_INV3RecupTqAllwdMax_Nm' */

  /* BusCreator: '<S232>/BusCreator' incorporates:
   *  Logic: '<S250>/Logical Operator3'
   *  Logic: '<S251>/Logical Operator3'
   *  MinMax: '<S250>/MinMax1'
   *  MinMax: '<S251>/MinMax1'
   */
  AppSwcIpm_ARID_DEF.IPM_INV_3_Value_EPT.VIPM_INV3DrvTqAllwdMax_Nm =
    VIPM_INV3DrvTqAllwdMax_Nm;
  AppSwcIpm_ARID_DEF.IPM_INV_3_Value_EPT.VIPM_INV3DrvTqAllwdMaxVld_flg =
    VIPM_INV3DrvTqAllwdMaxVld_flg;
  AppSwcIpm_ARID_DEF.IPM_INV_3_Value_EPT.VIPM_INV3RecupTqAllwdMax_Nm =
    VIPM_INV3RecupTqAllwdMax_Nm;
  AppSwcIpm_ARID_DEF.IPM_INV_3_Value_EPT.VIPM_INV3RecupTqAllwdMaxVld_flg =
    VIPM_INV3RecupTqAllwdMaxVld_flg;

  /* Outputs for Atomic SubSystem: '<S233>/Subsys_VIPM_INV4FltLvl_enum' */
  /* Logic: '<S254>/Logical Operator3' incorporates:
   *  Constant: '<S254>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_INV4FltLvlVld_flg = (KIPM_INV4FltLvl_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_INVMsgActv_flg);

  /* Switch: '<S254>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_INVMsgActv_flg) {
    /* Switch: '<S254>/Switch' incorporates:
     *  Inport: '<Root>/INV_4_Value_EPT'
     *  Switch: '<S254>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ga =
      (Rte_IRead_Runbl_IpmCanRx_10ms_INV_4_Value_EPT_INV_4_Value_EPT())
      ->INV_4_FaultLevl;
  } else {
    /* Switch: '<S254>/Switch' incorporates:
     *  Constant: '<S254>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ga = KIPM_INV4FltLvlDflt_enum;
  }

  /* End of Switch: '<S254>/Switch' */

  /* Switch: '<S254>/Switch4' incorporates:
   *  Constant: '<S254>/sat3'
   */
  if (KIPM_INV4FltLvl_enum_ovrdflg) {
    /* Switch: '<S254>/Switch4' incorporates:
     *  Constant: '<S254>/sat4'
     */
    VIPM_INV4FltLvl_enum = KIPM_INV4FltLvl_enum_ovrdval;
  } else {
    /* Switch: '<S254>/Switch4' */
    VIPM_INV4FltLvl_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ga;
  }

  /* End of Switch: '<S254>/Switch4' */
  /* End of Outputs for SubSystem: '<S233>/Subsys_VIPM_INV4FltLvl_enum' */

  /* BusCreator: '<S233>/BusCreator' incorporates:
   *  Logic: '<S254>/Logical Operator3'
   *  Switch: '<S254>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_INV_4_Value_EPT.VIPM_INV4FltLvl_enum =
    VIPM_INV4FltLvl_enum;
  AppSwcIpm_ARID_DEF.IPM_INV_4_Value_EPT.VIPM_INV4FltLvlVld_flg =
    VIPM_INV4FltLvlVld_flg;
}

/* Output and update for function-call system: '<Root>/Ipm20ms' */
static void Runbl_Ipm20ms(void)
{
  sint32 rtb_Product_a;
  float32 rtb_Product_b2;
  boolean rtb_LogicalOperator2_fz;

  /* Outputs for Atomic SubSystem: '<S258>/Subsys_VIPM_SCSGrShftLvrPstnReq_enum' */
  /* Logic: '<S318>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/SCS_RiSwitchSts_BOD'
   *  Logic: '<S259>/Logical Operator2'
   */
  rtb_LogicalOperator2_fz =
    ((Rte_IRead_Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD())
     ->SCS_GearShiftLeverPstReqVD &&
     (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
     ->VIPM_SCSMsgActv_flg);

  /* Logic: '<S259>/Logical Operator3' incorporates:
   *  Constant: '<S259>/sat3'
   */
  VIPM_SCSGrShftLvrPstnReqVld_flg = (KIPM_SCSGrShftLvrPstnReq_enum_ovrdflg ||
    rtb_LogicalOperator2_fz);

  /* Switch: '<S259>/Switch' */
  if (rtb_LogicalOperator2_fz) {
    /* Switch: '<S259>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_SCS_RiSwitchSts_CRCFlt_flg) {
      /* Switch: '<S259>/Switch' incorporates:
       *  DataTypeConversion: '<S259>/Data Type Conversion2'
       *  Inport: '<Root>/SCS_RiSwitchSts_BOD'
       *  Switch: '<S259>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_n1 =
        (Rte_IRead_Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD())
        ->SCS_GearShiftLeverPstReq;
    }

    /* End of Switch: '<S259>/Switch3' */
  } else {
    /* Switch: '<S259>/Switch' incorporates:
     *  Constant: '<S259>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_n1 = KIPM_SCSGrShftLvrPstnReqDflt_enum;
  }

  /* End of Switch: '<S259>/Switch' */

  /* Switch: '<S259>/Switch4' incorporates:
   *  Constant: '<S259>/sat3'
   */
  if (KIPM_SCSGrShftLvrPstnReq_enum_ovrdflg) {
    /* Switch: '<S259>/Switch4' incorporates:
     *  Constant: '<S259>/sat4'
     */
    VIPM_SCSGrShftLvrPstnReq_enum = KIPM_SCSGrShftLvrPstnReq_enum_ovrdval;
  } else {
    /* Switch: '<S259>/Switch4' incorporates:
     *  Switch: '<S259>/Switch'
     */
    VIPM_SCSGrShftLvrPstnReq_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_n1;
  }

  /* End of Switch: '<S259>/Switch4' */
  /* End of Outputs for SubSystem: '<S258>/Subsys_VIPM_SCSGrShftLvrPstnReq_enum' */

  /* Outputs for Atomic SubSystem: '<S258>/Subsys_VIPM_SCSRghtSwVldty_flg' */
  /* Logic: '<S263>/Logical Operator3' incorporates:
   *  Constant: '<S263>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_SCSRghtSwVldtyVld_flg = (KIPM_SCSRghtSwVldty_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_SCSMsgActv_flg);

  /* Switch: '<S263>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_SCSMsgActv_flg) {
    /* Switch: '<S263>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_SCS_RiSwitchSts_CRCFlt_flg) {
      /* Switch: '<S263>/Switch' incorporates:
       *  Inport: '<Root>/SCS_RiSwitchSts_BOD'
       *  Switch: '<S263>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pcv =
        (Rte_IRead_Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD())
        ->SCS_RightSwtVD;
    }

    /* End of Switch: '<S263>/Switch3' */
  } else {
    /* Switch: '<S263>/Switch' incorporates:
     *  Constant: '<S263>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pcv = KIPM_SCSRghtSwVldtyDflt_flg;
  }

  /* End of Switch: '<S263>/Switch' */

  /* Switch: '<S263>/Switch4' incorporates:
   *  Constant: '<S263>/sat3'
   */
  if (KIPM_SCSRghtSwVldty_flg_ovrdflg) {
    /* Switch: '<S263>/Switch4' incorporates:
     *  Constant: '<S263>/sat4'
     */
    VIPM_SCSRghtSwVldty_flg = KIPM_SCSRghtSwVldty_flg_ovrdval;
  } else {
    /* Switch: '<S263>/Switch4' */
    VIPM_SCSRghtSwVldty_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pcv;
  }

  /* End of Switch: '<S263>/Switch4' */
  /* End of Outputs for SubSystem: '<S258>/Subsys_VIPM_SCSRghtSwVldty_flg' */

  /* Outputs for Atomic SubSystem: '<S258>/Subsys_VIPM_SCSRght11Sw_flg' */
  /* Logic: '<S260>/Logical Operator3' incorporates:
   *  Constant: '<S260>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_SCSRght11SwVld_flg = (KIPM_SCSRght11Sw_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_SCSMsgActv_flg);

  /* Switch: '<S260>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_SCSMsgActv_flg) {
    /* Switch: '<S260>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_SCS_RiSwitchSts_CRCFlt_flg) {
      /* Switch: '<S260>/Switch' incorporates:
       *  Inport: '<Root>/SCS_RiSwitchSts_BOD'
       *  Switch: '<S260>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jyd =
        (Rte_IRead_Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD())
        ->SCS_Right_11Swt;
    }

    /* End of Switch: '<S260>/Switch3' */
  } else {
    /* Switch: '<S260>/Switch' incorporates:
     *  Constant: '<S260>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jyd = KIPM_SCSRght11SwDflt_flg;
  }

  /* End of Switch: '<S260>/Switch' */

  /* Switch: '<S260>/Switch4' incorporates:
   *  Constant: '<S260>/sat3'
   */
  if (KIPM_SCSRght11Sw_flg_ovrdflg) {
    /* Switch: '<S260>/Switch4' incorporates:
     *  Constant: '<S260>/sat4'
     */
    VIPM_SCSRght11Sw_flg = KIPM_SCSRght11Sw_flg_ovrdval;
  } else {
    /* Switch: '<S260>/Switch4' */
    VIPM_SCSRght11Sw_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jyd;
  }

  /* End of Switch: '<S260>/Switch4' */
  /* End of Outputs for SubSystem: '<S258>/Subsys_VIPM_SCSRght11Sw_flg' */

  /* Outputs for Atomic SubSystem: '<S258>/Subsys_VIPM_SCSRght12Sw_flg' */
  /* Logic: '<S261>/Logical Operator3' incorporates:
   *  Constant: '<S261>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_SCSRght12SwVld_flg = (KIPM_SCSRght12Sw_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_SCSMsgActv_flg);

  /* Switch: '<S261>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_SCSMsgActv_flg) {
    /* Switch: '<S261>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_SCS_RiSwitchSts_CRCFlt_flg) {
      /* Switch: '<S261>/Switch' incorporates:
       *  Inport: '<Root>/SCS_RiSwitchSts_BOD'
       *  Switch: '<S261>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ka =
        (Rte_IRead_Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD())
        ->SCS_Right_12Swt;
    }

    /* End of Switch: '<S261>/Switch3' */
  } else {
    /* Switch: '<S261>/Switch' incorporates:
     *  Constant: '<S261>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ka = KIPM_SCSRght12SwDflt_flg;
  }

  /* End of Switch: '<S261>/Switch' */

  /* Switch: '<S261>/Switch4' incorporates:
   *  Constant: '<S261>/sat3'
   */
  if (KIPM_SCSRght12Sw_flg_ovrdflg) {
    /* Switch: '<S261>/Switch4' incorporates:
     *  Constant: '<S261>/sat4'
     */
    VIPM_SCSRght12Sw_flg = KIPM_SCSRght12Sw_flg_ovrdval;
  } else {
    /* Switch: '<S261>/Switch4' */
    VIPM_SCSRght12Sw_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ka;
  }

  /* End of Switch: '<S261>/Switch4' */
  /* End of Outputs for SubSystem: '<S258>/Subsys_VIPM_SCSRght12Sw_flg' */

  /* Outputs for Atomic SubSystem: '<S258>/Subsys_VIPM_SCSRght13Sw_flg' */
  /* Logic: '<S262>/Logical Operator3' incorporates:
   *  Constant: '<S262>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_SCSRght13SwVld_flg = (KIPM_SCSRght13Sw_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_SCSMsgActv_flg);

  /* Switch: '<S262>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_SCSMsgActv_flg) {
    /* Switch: '<S262>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_SCS_RiSwitchSts_CRCFlt_flg) {
      /* Switch: '<S262>/Switch' incorporates:
       *  Inport: '<Root>/SCS_RiSwitchSts_BOD'
       *  Switch: '<S262>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_el =
        (Rte_IRead_Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD())
        ->SCS_Right_13Swt;
    }

    /* End of Switch: '<S262>/Switch3' */
  } else {
    /* Switch: '<S262>/Switch' incorporates:
     *  Constant: '<S262>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_el = KIPM_SCSRght13SwDflt_flg;
  }

  /* End of Switch: '<S262>/Switch' */

  /* Switch: '<S262>/Switch4' incorporates:
   *  Constant: '<S262>/sat3'
   */
  if (KIPM_SCSRght13Sw_flg_ovrdflg) {
    /* Switch: '<S262>/Switch4' incorporates:
     *  Constant: '<S262>/sat4'
     */
    VIPM_SCSRght13Sw_flg = KIPM_SCSRght13Sw_flg_ovrdval;
  } else {
    /* Switch: '<S262>/Switch4' */
    VIPM_SCSRght13Sw_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_el;
  }

  /* End of Switch: '<S262>/Switch4' */
  /* End of Outputs for SubSystem: '<S258>/Subsys_VIPM_SCSRght13Sw_flg' */

  /* BusCreator: '<S258>/BusCreator1' incorporates:
   *  DataTypeConversion: '<S258>/Data Type Conversion3'
   *  Logic: '<S259>/Logical Operator3'
   *  Logic: '<S260>/Logical Operator3'
   *  Logic: '<S261>/Logical Operator3'
   *  Logic: '<S262>/Logical Operator3'
   *  Logic: '<S263>/Logical Operator3'
   *  Switch: '<S259>/Switch4'
   *  Switch: '<S260>/Switch4'
   *  Switch: '<S261>/Switch4'
   *  Switch: '<S262>/Switch4'
   *  Switch: '<S263>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_SCS_RiSwitchSts_BOD.VIPM_SCSGrShftLvrPstnReq_enum =
    VIPM_SCSGrShftLvrPstnReq_enum;
  AppSwcIpm_ARID_DEF.IPM_SCS_RiSwitchSts_BOD.VIPM_SCSGrShftLvrPstnReqVld_flg =
    VIPM_SCSGrShftLvrPstnReqVld_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_RiSwitchSts_BOD.VIPM_SCSRghtSwVldty_flg =
    VIPM_SCSRghtSwVldty_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_RiSwitchSts_BOD.VIPM_SCSRghtSwVldtyVld_flg =
    VIPM_SCSRghtSwVldtyVld_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_RiSwitchSts_BOD.VIPM_SCSRght11Sw_flg =
    VIPM_SCSRght11Sw_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_RiSwitchSts_BOD.VIPM_SCSRght11SwVld_flg =
    VIPM_SCSRght11SwVld_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_RiSwitchSts_BOD.VIPM_SCSRght12Sw_flg =
    VIPM_SCSRght12Sw_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_RiSwitchSts_BOD.VIPM_SCSRght12SwVld_flg =
    VIPM_SCSRght12SwVld_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_RiSwitchSts_BOD.VIPM_SCSRght13Sw_flg =
    VIPM_SCSRght13Sw_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_RiSwitchSts_BOD.VIPM_SCSRght13SwVld_flg =
    VIPM_SCSRght13SwVld_flg;

  /* Outputs for Atomic SubSystem: '<S264>/Subsys_VIPM_CRRRBSDWarnLt_enum' */
  /* Logic: '<S267>/Logical Operator3' incorporates:
   *  Constant: '<S267>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CRRRBSDWarnLtVld_flg = (KIPM_CRRRBSDWarnLt_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
    ->VIPM_CRRRMsgActv_flg);

  /* Switch: '<S267>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_CRRRMsgActv_flg) {
    /* Switch: '<S267>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_CRRR_A_CRCFlt_flg) {
      /* Switch: '<S267>/Switch' incorporates:
       *  Inport: '<Root>/CRRR_A_CHA'
       *  Switch: '<S267>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ows =
        (Rte_IRead_Runbl_IpmCanRx_20ms_CRRR_A_CHA_CRRR_A_CHA())
        ->CRRR_BSD_Warn_Left;
    }

    /* End of Switch: '<S267>/Switch3' */
  } else {
    /* Switch: '<S267>/Switch' incorporates:
     *  Constant: '<S267>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ows = KIPM_CRRRBSDWarnLtDflt_enum;
  }

  /* End of Switch: '<S267>/Switch' */

  /* Switch: '<S267>/Switch4' incorporates:
   *  Constant: '<S267>/sat3'
   */
  if (KIPM_CRRRBSDWarnLt_enum_ovrdflg) {
    /* Switch: '<S267>/Switch4' incorporates:
     *  Constant: '<S267>/sat4'
     */
    VIPM_CRRRBSDWarnLt_enum = KIPM_CRRRBSDWarnLt_enum_ovrdval;
  } else {
    /* Switch: '<S267>/Switch4' */
    VIPM_CRRRBSDWarnLt_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ows;
  }

  /* End of Switch: '<S267>/Switch4' */
  /* End of Outputs for SubSystem: '<S264>/Subsys_VIPM_CRRRBSDWarnLt_enum' */

  /* Outputs for Atomic SubSystem: '<S264>/Subsys_VIPM_CRRRBSDWarnRt_enum' */
  /* Logic: '<S268>/Logical Operator3' incorporates:
   *  Constant: '<S268>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CRRRBSDWarnRtVld_flg = (KIPM_CRRRBSDWarnRt_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
    ->VIPM_CRRRMsgActv_flg);

  /* Switch: '<S268>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_CRRRMsgActv_flg) {
    /* Switch: '<S268>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_CRRR_A_CRCFlt_flg) {
      /* Switch: '<S268>/Switch' incorporates:
       *  Inport: '<Root>/CRRR_A_CHA'
       *  Switch: '<S268>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ki =
        (Rte_IRead_Runbl_IpmCanRx_20ms_CRRR_A_CHA_CRRR_A_CHA())
        ->CRRR_BSD_Warn_Right;
    }

    /* End of Switch: '<S268>/Switch3' */
  } else {
    /* Switch: '<S268>/Switch' incorporates:
     *  Constant: '<S268>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ki = KIPM_CRRRBSDWarnRtDflt_enum;
  }

  /* End of Switch: '<S268>/Switch' */

  /* Switch: '<S268>/Switch4' incorporates:
   *  Constant: '<S268>/sat3'
   */
  if (KIPM_CRRRBSDWarnRt_enum_ovrdflg) {
    /* Switch: '<S268>/Switch4' incorporates:
     *  Constant: '<S268>/sat4'
     */
    VIPM_CRRRBSDWarnRt_enum = KIPM_CRRRBSDWarnRt_enum_ovrdval;
  } else {
    /* Switch: '<S268>/Switch4' */
    VIPM_CRRRBSDWarnRt_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ki;
  }

  /* End of Switch: '<S268>/Switch4' */
  /* End of Outputs for SubSystem: '<S264>/Subsys_VIPM_CRRRBSDWarnRt_enum' */

  /* Outputs for Atomic SubSystem: '<S264>/Subsys_VIPM_CRRRDOWWarnLt_enum' */
  /* Logic: '<S269>/Logical Operator3' incorporates:
   *  Constant: '<S269>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CRRRDOWWarnLtVld_flg = (KIPM_CRRRDOWWarnLt_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
    ->VIPM_CRRRMsgActv_flg);

  /* Switch: '<S269>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_CRRRMsgActv_flg) {
    /* Switch: '<S269>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_CRRR_A_CRCFlt_flg) {
      /* Switch: '<S269>/Switch' incorporates:
       *  Inport: '<Root>/CRRR_A_CHA'
       *  Switch: '<S269>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ms =
        (Rte_IRead_Runbl_IpmCanRx_20ms_CRRR_A_CHA_CRRR_A_CHA())
        ->CRRR_DOW_Warn_Left;
    }

    /* End of Switch: '<S269>/Switch3' */
  } else {
    /* Switch: '<S269>/Switch' incorporates:
     *  Constant: '<S269>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ms = KIPM_CRRRDOWWarnLtDflt_enum;
  }

  /* End of Switch: '<S269>/Switch' */

  /* Switch: '<S269>/Switch4' incorporates:
   *  Constant: '<S269>/sat3'
   */
  if (KIPM_CRRRDOWWarnLt_enum_ovrdflg) {
    /* Switch: '<S269>/Switch4' incorporates:
     *  Constant: '<S269>/sat4'
     */
    VIPM_CRRRDOWWarnLt_enum = KIPM_CRRRDOWWarnLt_enum_ovrdval;
  } else {
    /* Switch: '<S269>/Switch4' */
    VIPM_CRRRDOWWarnLt_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ms;
  }

  /* End of Switch: '<S269>/Switch4' */
  /* End of Outputs for SubSystem: '<S264>/Subsys_VIPM_CRRRDOWWarnLt_enum' */

  /* Outputs for Atomic SubSystem: '<S264>/Subsys_VIPM_CRRRDOWWarnRt_enum' */
  /* Logic: '<S270>/Logical Operator3' incorporates:
   *  Constant: '<S270>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CRRRDOWWarnRtVld_flg = (KIPM_CRRRDOWWarnRt_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
    ->VIPM_CRRRMsgActv_flg);

  /* Switch: '<S270>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_CRRRMsgActv_flg) {
    /* Switch: '<S270>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_CRRR_A_CRCFlt_flg) {
      /* Switch: '<S270>/Switch' incorporates:
       *  Inport: '<Root>/CRRR_A_CHA'
       *  Switch: '<S270>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hg =
        (Rte_IRead_Runbl_IpmCanRx_20ms_CRRR_A_CHA_CRRR_A_CHA())
        ->CRRR_DOW_Warn_Right;
    }

    /* End of Switch: '<S270>/Switch3' */
  } else {
    /* Switch: '<S270>/Switch' incorporates:
     *  Constant: '<S270>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hg = KIPM_CRRRDOWWarnRtDflt_enum;
  }

  /* End of Switch: '<S270>/Switch' */

  /* Switch: '<S270>/Switch4' incorporates:
   *  Constant: '<S270>/sat3'
   */
  if (KIPM_CRRRDOWWarnRt_enum_ovrdflg) {
    /* Switch: '<S270>/Switch4' incorporates:
     *  Constant: '<S270>/sat4'
     */
    VIPM_CRRRDOWWarnRt_enum = KIPM_CRRRDOWWarnRt_enum_ovrdval;
  } else {
    /* Switch: '<S270>/Switch4' */
    VIPM_CRRRDOWWarnRt_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hg;
  }

  /* End of Switch: '<S270>/Switch4' */
  /* End of Outputs for SubSystem: '<S264>/Subsys_VIPM_CRRRDOWWarnRt_enum' */

  /* Outputs for Atomic SubSystem: '<S264>/Subsys_VIPM_CRRRRCTAWarnLt_enum' */
  /* Logic: '<S271>/Logical Operator3' incorporates:
   *  Constant: '<S271>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CRRRRCTAWarnLtVld_flg = (KIPM_CRRRRCTAWarnLt_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
    ->VIPM_CRRRMsgActv_flg);

  /* Switch: '<S271>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_CRRRMsgActv_flg) {
    /* Switch: '<S271>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_CRRR_A_CRCFlt_flg) {
      /* Switch: '<S271>/Switch' incorporates:
       *  Inport: '<Root>/CRRR_A_CHA'
       *  Switch: '<S271>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hf =
        (Rte_IRead_Runbl_IpmCanRx_20ms_CRRR_A_CHA_CRRR_A_CHA())
        ->CRRR_RCTA_Warn_Left;
    }

    /* End of Switch: '<S271>/Switch3' */
  } else {
    /* Switch: '<S271>/Switch' incorporates:
     *  Constant: '<S271>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hf = KIPM_CRRRRCTAWarnLtDflt_enum;
  }

  /* End of Switch: '<S271>/Switch' */

  /* Switch: '<S271>/Switch4' incorporates:
   *  Constant: '<S271>/sat3'
   */
  if (KIPM_CRRRRCTAWarnLt_enum_ovrdflg) {
    /* Switch: '<S271>/Switch4' incorporates:
     *  Constant: '<S271>/sat4'
     */
    VIPM_CRRRRCTAWarnLt_enum = KIPM_CRRRRCTAWarnLt_enum_ovrdval;
  } else {
    /* Switch: '<S271>/Switch4' */
    VIPM_CRRRRCTAWarnLt_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hf;
  }

  /* End of Switch: '<S271>/Switch4' */
  /* End of Outputs for SubSystem: '<S264>/Subsys_VIPM_CRRRRCTAWarnLt_enum' */

  /* Outputs for Atomic SubSystem: '<S264>/Subsys_VIPM_CRRRRCTAWarnRt_enum' */
  /* Logic: '<S272>/Logical Operator3' incorporates:
   *  Constant: '<S272>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CRRRRCTAWarnRtVld_flg = (KIPM_CRRRRCTAWarnRt_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
    ->VIPM_CRRRMsgActv_flg);

  /* Switch: '<S272>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_CRRRMsgActv_flg) {
    /* Switch: '<S272>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_CRRR_A_CRCFlt_flg) {
      /* Switch: '<S272>/Switch' incorporates:
       *  Inport: '<Root>/CRRR_A_CHA'
       *  Switch: '<S272>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_m =
        (Rte_IRead_Runbl_IpmCanRx_20ms_CRRR_A_CHA_CRRR_A_CHA())
        ->CRRR_RCTA_Warn_Right;
    }

    /* End of Switch: '<S272>/Switch3' */
  } else {
    /* Switch: '<S272>/Switch' incorporates:
     *  Constant: '<S272>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_m = KIPM_CRRRRCTAWarnRtDflt_enum;
  }

  /* End of Switch: '<S272>/Switch' */

  /* Switch: '<S272>/Switch4' incorporates:
   *  Constant: '<S272>/sat3'
   */
  if (KIPM_CRRRRCTAWarnRt_enum_ovrdflg) {
    /* Switch: '<S272>/Switch4' incorporates:
     *  Constant: '<S272>/sat4'
     */
    VIPM_CRRRRCTAWarnRt_enum = KIPM_CRRRRCTAWarnRt_enum_ovrdval;
  } else {
    /* Switch: '<S272>/Switch4' */
    VIPM_CRRRRCTAWarnRt_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_m;
  }

  /* End of Switch: '<S272>/Switch4' */
  /* End of Outputs for SubSystem: '<S264>/Subsys_VIPM_CRRRRCTAWarnRt_enum' */

  /* BusCreator: '<S264>/BusCreator' incorporates:
   *  Logic: '<S267>/Logical Operator3'
   *  Logic: '<S268>/Logical Operator3'
   *  Logic: '<S269>/Logical Operator3'
   *  Logic: '<S270>/Logical Operator3'
   *  Logic: '<S271>/Logical Operator3'
   *  Logic: '<S272>/Logical Operator3'
   *  Switch: '<S267>/Switch4'
   *  Switch: '<S268>/Switch4'
   *  Switch: '<S269>/Switch4'
   *  Switch: '<S270>/Switch4'
   *  Switch: '<S271>/Switch4'
   *  Switch: '<S272>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_CRRR_A_CHA.VIPM_CRRRBSDWarnLt_enum =
    VIPM_CRRRBSDWarnLt_enum;
  AppSwcIpm_ARID_DEF.IPM_CRRR_A_CHA.VIPM_CRRRBSDWarnLtVld_flg =
    VIPM_CRRRBSDWarnLtVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CRRR_A_CHA.VIPM_CRRRBSDWarnRt_enum =
    VIPM_CRRRBSDWarnRt_enum;
  AppSwcIpm_ARID_DEF.IPM_CRRR_A_CHA.VIPM_CRRRBSDWarnRtVld_flg =
    VIPM_CRRRBSDWarnRtVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CRRR_A_CHA.VIPM_CRRRDOWWarnLt_enum =
    VIPM_CRRRDOWWarnLt_enum;
  AppSwcIpm_ARID_DEF.IPM_CRRR_A_CHA.VIPM_CRRRDOWWarnLtVld_flg =
    VIPM_CRRRDOWWarnLtVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CRRR_A_CHA.VIPM_CRRRDOWWarnRt_enum =
    VIPM_CRRRDOWWarnRt_enum;
  AppSwcIpm_ARID_DEF.IPM_CRRR_A_CHA.VIPM_CRRRDOWWarnRtVld_flg =
    VIPM_CRRRDOWWarnRtVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CRRR_A_CHA.VIPM_CRRRRCTAWarnLt_enum =
    VIPM_CRRRRCTAWarnLt_enum;
  AppSwcIpm_ARID_DEF.IPM_CRRR_A_CHA.VIPM_CRRRRCTAWarnLtVld_flg =
    VIPM_CRRRRCTAWarnLtVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CRRR_A_CHA.VIPM_CRRRRCTAWarnRt_enum =
    VIPM_CRRRRCTAWarnRt_enum;
  AppSwcIpm_ARID_DEF.IPM_CRRR_A_CHA.VIPM_CRRRRCTAWarnRtVld_flg =
    VIPM_CRRRRCTAWarnRtVld_flg;

  /* Outputs for Atomic SubSystem: '<S265>/Subsys_VIPM_EHBEPBActuatorStL_enum' */
  /* Logic: '<S275>/Logical Operator3' incorporates:
   *  Constant: '<S275>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_EHBEPBActuatorStLVld_flg = (KIPM_EHBEPBActuatorStL_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_EHBMsgActv_flg);

  /* Switch: '<S275>/Switch4' incorporates:
   *  Constant: '<S275>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S275>/Switch'
   */
  if (KIPM_EHBEPBActuatorStL_enum_ovrdflg) {
    /* Switch: '<S275>/Switch4' incorporates:
     *  Constant: '<S275>/sat4'
     */
    VIPM_EHBEPBActuatorStL_enum = KIPM_EHBEPBActuatorStL_enum_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
             ->VIPM_EHBMsgActv_flg) {
    /* Switch: '<S275>/Switch4' incorporates:
     *  DataTypeConversion: '<S275>/Data Type Conversion2'
     *  Inport: '<Root>/EHB_A_CHA'
     *  Switch: '<S275>/Switch'
     */
    VIPM_EHBEPBActuatorStL_enum =
      (Rte_IRead_Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA())
      ->EHB_EPB_ActuatorSt_L;
  } else {
    /* Switch: '<S275>/Switch4' incorporates:
     *  Constant: '<S275>/sat5'
     *  Switch: '<S275>/Switch'
     */
    VIPM_EHBEPBActuatorStL_enum = KIPM_EHBEPBActuatorStLDflt_enum;
  }

  /* End of Switch: '<S275>/Switch4' */
  /* End of Outputs for SubSystem: '<S265>/Subsys_VIPM_EHBEPBActuatorStL_enum' */

  /* Outputs for Atomic SubSystem: '<S265>/Subsys_VIPM_EHBEPBSwitchSts_enum' */
  /* Logic: '<S276>/Logical Operator3' incorporates:
   *  Constant: '<S276>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_EHBEPBSwitchStsVld_flg = (KIPM_EHBEPBSwitchSts_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_EHBMsgActv_flg);

  /* Switch: '<S276>/Switch4' incorporates:
   *  Constant: '<S276>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S276>/Switch'
   */
  if (KIPM_EHBEPBSwitchSts_enum_ovrdflg) {
    /* Switch: '<S276>/Switch4' incorporates:
     *  Constant: '<S276>/sat4'
     */
    VIPM_EHBEPBSwitchSts_enum = KIPM_EHBEPBSwitchSts_enum_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
             ->VIPM_EHBMsgActv_flg) {
    /* Switch: '<S276>/Switch4' incorporates:
     *  DataTypeConversion: '<S276>/Data Type Conversion2'
     *  Inport: '<Root>/EHB_A_CHA'
     *  Switch: '<S276>/Switch'
     */
    VIPM_EHBEPBSwitchSts_enum =
      (Rte_IRead_Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA())->EHB_EPB_SwitchSts;
  } else {
    /* Switch: '<S276>/Switch4' incorporates:
     *  Constant: '<S276>/sat5'
     *  Switch: '<S276>/Switch'
     */
    VIPM_EHBEPBSwitchSts_enum = KIPM_EHBEPBSwitchStsDflt_enum;
  }

  /* End of Switch: '<S276>/Switch4' */
  /* End of Outputs for SubSystem: '<S265>/Subsys_VIPM_EHBEPBSwitchSts_enum' */

  /* DataTypeConversion: '<S265>/Data Type Conversion1' incorporates:
   *  Switch: '<S276>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_EHB_A_CHA.VIPM_EHBEPBSwitchSts_enum =
    VIPM_EHBEPBSwitchSts_enum;

  /* Outputs for Atomic SubSystem: '<S265>/Subsys_VIPM_EHBEPBSysSt_enum' */
  /* Logic: '<S277>/Logical Operator3' incorporates:
   *  Constant: '<S277>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_EHBEPBSysStVld_flg = (KIPM_EHBEPBSysSt_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_EHBMsgActv_flg);

  /* Switch: '<S277>/Switch4' incorporates:
   *  Constant: '<S277>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S277>/Switch'
   */
  if (KIPM_EHBEPBSysSt_enum_ovrdflg) {
    /* Switch: '<S277>/Switch4' incorporates:
     *  Constant: '<S277>/sat4'
     */
    VIPM_EHBEPBSysSt_enum = KIPM_EHBEPBSysSt_enum_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
             ->VIPM_EHBMsgActv_flg) {
    /* Switch: '<S277>/Switch4' incorporates:
     *  DataTypeConversion: '<S277>/Data Type Conversion2'
     *  Inport: '<Root>/EHB_A_CHA'
     *  Switch: '<S277>/Switch'
     */
    VIPM_EHBEPBSysSt_enum = (Rte_IRead_Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA())
      ->EHB_EPB_SystemState;
  } else {
    /* Switch: '<S277>/Switch4' incorporates:
     *  Constant: '<S277>/sat5'
     *  Switch: '<S277>/Switch'
     */
    VIPM_EHBEPBSysSt_enum = KIPM_EHBEPBSysStDflt_enum;
  }

  /* End of Switch: '<S277>/Switch4' */
  /* End of Outputs for SubSystem: '<S265>/Subsys_VIPM_EHBEPBSysSt_enum' */

  /* DataTypeConversion: '<S265>/Data Type Conversion2' incorporates:
   *  Switch: '<S277>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_EHB_A_CHA.VIPM_EHBEPBSysSt_enum = VIPM_EHBEPBSysSt_enum;

  /* Outputs for Atomic SubSystem: '<S265>/Subsys_VIPM_EHBHDCFucFault_flg' */
  /* Logic: '<S278>/Logical Operator3' incorporates:
   *  Constant: '<S278>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_EHBHDCFucFaultVld_flg = (KIPM_EHBHDCFucFault_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_EHBMsgActv_flg);

  /* Switch: '<S278>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_EHBMsgActv_flg) {
    /* Switch: '<S278>/Switch' incorporates:
     *  Inport: '<Root>/EHB_A_CHA'
     *  Switch: '<S278>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ie =
      (Rte_IRead_Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA())->EHB_HDCFucFault;
  } else {
    /* Switch: '<S278>/Switch' incorporates:
     *  Constant: '<S278>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ie = KIPM_EHBHDCFucFaultDflt_flg;
  }

  /* End of Switch: '<S278>/Switch' */

  /* Switch: '<S278>/Switch4' incorporates:
   *  Constant: '<S278>/sat3'
   */
  if (KIPM_EHBHDCFucFault_flg_ovrdflg) {
    /* Switch: '<S278>/Switch4' incorporates:
     *  Constant: '<S278>/sat4'
     */
    VIPM_EHBHDCFucFault_flg = KIPM_EHBHDCFucFault_flg_ovrdval;
  } else {
    /* Switch: '<S278>/Switch4' */
    VIPM_EHBHDCFucFault_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ie;
  }

  /* End of Switch: '<S278>/Switch4' */
  /* End of Outputs for SubSystem: '<S265>/Subsys_VIPM_EHBHDCFucFault_flg' */

  /* Outputs for Atomic SubSystem: '<S265>/Subsys_VIPM_EHBAVHAppldSt_enum' */
  /* Logic: '<S273>/Logical Operator3' incorporates:
   *  Constant: '<S273>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_EHBAVHAppldStVld_flg = (KIPM_EHBAVHAppldSt_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_EHBMsgActv_flg);

  /* Switch: '<S273>/Switch4' incorporates:
   *  Constant: '<S273>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S273>/Switch'
   */
  if (KIPM_EHBAVHAppldSt_enum_ovrdflg) {
    /* Switch: '<S273>/Switch4' incorporates:
     *  Constant: '<S273>/sat4'
     */
    VIPM_EHBAVHAppldSt_enum = KIPM_EHBAVHAppldSt_enum_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
             ->VIPM_EHBMsgActv_flg) {
    /* Switch: '<S273>/Switch4' incorporates:
     *  DataTypeConversion: '<S273>/Data Type Conversion2'
     *  Inport: '<Root>/EHB_A_CHA'
     *  Switch: '<S273>/Switch'
     */
    VIPM_EHBAVHAppldSt_enum = (Rte_IRead_Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA
      ())->EHB_AVHAppldSt;
  } else {
    /* Switch: '<S273>/Switch4' incorporates:
     *  Constant: '<S273>/sat5'
     *  Switch: '<S273>/Switch'
     */
    VIPM_EHBAVHAppldSt_enum = KIPM_EHBAVHAppldStDflt_enum;
  }

  /* End of Switch: '<S273>/Switch4' */
  /* End of Outputs for SubSystem: '<S265>/Subsys_VIPM_EHBAVHAppldSt_enum' */

  /* Outputs for Atomic SubSystem: '<S265>/Subsys_VIPM_EHBBLA_flg' */
  /* Logic: '<S274>/Logical Operator3' incorporates:
   *  Constant: '<S274>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_EHBBLAVld_flg = (KIPM_EHBBLA_flg_ovrdflg ||
                        (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV()
                        )->VIPM_EHBMsgActv_flg);

  /* Switch: '<S274>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_EHBMsgActv_flg) {
    /* Switch: '<S274>/Switch' incorporates:
     *  Inport: '<Root>/EHB_A_CHA'
     *  Switch: '<S274>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_mg =
      (Rte_IRead_Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA())->EHB_BLA;
  } else {
    /* Switch: '<S274>/Switch' incorporates:
     *  Constant: '<S274>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_mg = KIPM_EHBBLADflt_flg;
  }

  /* End of Switch: '<S274>/Switch' */

  /* Switch: '<S274>/Switch4' incorporates:
   *  Constant: '<S274>/sat3'
   */
  if (KIPM_EHBBLA_flg_ovrdflg) {
    /* Switch: '<S274>/Switch4' incorporates:
     *  Constant: '<S274>/sat4'
     */
    VIPM_EHBBLA_flg = KIPM_EHBBLA_flg_ovrdval;
  } else {
    /* Switch: '<S274>/Switch4' */
    VIPM_EHBBLA_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_mg;
  }

  /* End of Switch: '<S274>/Switch4' */
  /* End of Outputs for SubSystem: '<S265>/Subsys_VIPM_EHBBLA_flg' */

  /* BusCreator: '<S265>/BusCreator' incorporates:
   *  DataTypeConversion: '<S265>/Data Type Conversion'
   *  DataTypeConversion: '<S265>/Data Type Conversion3'
   *  Logic: '<S273>/Logical Operator3'
   *  Logic: '<S274>/Logical Operator3'
   *  Logic: '<S275>/Logical Operator3'
   *  Logic: '<S276>/Logical Operator3'
   *  Logic: '<S277>/Logical Operator3'
   *  Logic: '<S278>/Logical Operator3'
   *  Switch: '<S273>/Switch4'
   *  Switch: '<S274>/Switch4'
   *  Switch: '<S275>/Switch4'
   *  Switch: '<S278>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_EHB_A_CHA.VIPM_EHBEPBActuatorStL_enum =
    VIPM_EHBEPBActuatorStL_enum;
  AppSwcIpm_ARID_DEF.IPM_EHB_A_CHA.VIPM_EHBEPBActuatorStLVld_flg =
    VIPM_EHBEPBActuatorStLVld_flg;
  AppSwcIpm_ARID_DEF.IPM_EHB_A_CHA.VIPM_EHBEPBSwitchStsVld_flg =
    VIPM_EHBEPBSwitchStsVld_flg;
  AppSwcIpm_ARID_DEF.IPM_EHB_A_CHA.VIPM_EHBEPBSysStVld_flg =
    VIPM_EHBEPBSysStVld_flg;
  AppSwcIpm_ARID_DEF.IPM_EHB_A_CHA.VIPM_EHBHDCFucFault_flg =
    VIPM_EHBHDCFucFault_flg;
  AppSwcIpm_ARID_DEF.IPM_EHB_A_CHA.VIPM_EHBHDCFucFaultVld_flg =
    VIPM_EHBHDCFucFaultVld_flg;
  AppSwcIpm_ARID_DEF.IPM_EHB_A_CHA.VIPM_EHBAVHAppldSt_enum =
    VIPM_EHBAVHAppldSt_enum;
  AppSwcIpm_ARID_DEF.IPM_EHB_A_CHA.VIPM_EHBAVHAppldStVld_flg =
    VIPM_EHBAVHAppldStVld_flg;
  AppSwcIpm_ARID_DEF.IPM_EHB_A_CHA.VIPM_EHBBLA_flg = VIPM_EHBBLA_flg;
  AppSwcIpm_ARID_DEF.IPM_EHB_A_CHA.VIPM_EHBBLAVld_flg = VIPM_EHBBLAVld_flg;

  /* Outputs for Atomic SubSystem: '<S266>/Subsys_VIPM_FCMACCWhlTqReqActv_flg' */
  /* Logic: '<S281>/Logical Operator3' incorporates:
   *  Constant: '<S281>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_FCMACCWhlTqReqActvVld_flg = (KIPM_FCMACCWhlTqReqActv_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_FCMMsgActv_flg);

  /* Switch: '<S281>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_FCMMsgActv_flg) {
    /* Switch: '<S281>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_FCM_B_CRCFlt_flg) {
      /* Switch: '<S281>/Switch' incorporates:
       *  Inport: '<Root>/FCM_B_CHA'
       *  Switch: '<S281>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ep =
        (Rte_IRead_Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA())
        ->FCM_ACCWhlTqReqActv;
    }

    /* End of Switch: '<S281>/Switch3' */
  } else {
    /* Switch: '<S281>/Switch' incorporates:
     *  Constant: '<S281>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ep = KIPM_FCMACCWhlTqReqActvDflt_flg;
  }

  /* End of Switch: '<S281>/Switch' */

  /* Switch: '<S281>/Switch4' incorporates:
   *  Constant: '<S281>/sat3'
   */
  if (KIPM_FCMACCWhlTqReqActv_flg_ovrdflg) {
    /* Switch: '<S281>/Switch4' incorporates:
     *  Constant: '<S281>/sat4'
     */
    VIPM_FCMACCWhlTqReqActv_flg = KIPM_FCMACCWhlTqReqActv_flg_ovrdval;
  } else {
    /* Switch: '<S281>/Switch4' */
    VIPM_FCMACCWhlTqReqActv_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ep;
  }

  /* End of Switch: '<S281>/Switch4' */
  /* End of Outputs for SubSystem: '<S266>/Subsys_VIPM_FCMACCWhlTqReqActv_flg' */

  /* Outputs for Atomic SubSystem: '<S266>/Subsys_VIPM_FCMACCWhlTqReqVal_Nm' */
  /* Logic: '<S282>/Logical Operator3' incorporates:
   *  Constant: '<S282>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_FCMACCWhlTqReqValVld_flg = (KIPM_FCMACCWhlTqReqVal_Nm_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_FCMMsgActv_flg);

  /* Switch: '<S282>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_FCMMsgActv_flg) {
    /* Switch: '<S282>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_FCM_B_CRCFlt_flg) {
      /* Product: '<S293>/Product' incorporates:
       *  Constant: '<S293>/Constant'
       *  Inport: '<Root>/FCM_B_CHA'
       */
      rtb_Product_b2 = (float32)
        (Rte_IRead_Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA())
        ->FCM_ACCWhlTqReqVal * 0.5F;

      /* Switch: '<S282>/Switch' incorporates:
       *  Sum: '<S293>/Add'
       *  Switch: '<S282>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_f = rtb_Product_b2 - 6200.0F;
    }

    /* End of Switch: '<S282>/Switch3' */
  } else {
    /* Switch: '<S282>/Switch' incorporates:
     *  Constant: '<S282>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_f = KIPM_FCMACCWhlTqReqValDflt_Nm;
  }

  /* End of Switch: '<S282>/Switch' */

  /* Switch: '<S282>/Switch4' incorporates:
   *  Constant: '<S282>/sat3'
   *  Constant: '<S282>/sat4'
   */
  if (KIPM_FCMACCWhlTqReqVal_Nm_ovrdflg) {
    VIPM_FCMACCWhlTqReqVal_Nm = KIPM_FCMACCWhlTqReqVal_Nm_ovrdval;
  } else {
    VIPM_FCMACCWhlTqReqVal_Nm = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_f;
  }

  /* MinMax: '<S282>/MinMax' incorporates:
   *  Constant: '<S282>/sat6'
   *  Switch: '<S282>/Switch4'
   */
  if (VIPM_FCMACCWhlTqReqVal_Nm > KIPM_FCMACCWhlTqReqValHi_Nm) {
    VIPM_FCMACCWhlTqReqVal_Nm = KIPM_FCMACCWhlTqReqValHi_Nm;
  }

  /* End of MinMax: '<S282>/MinMax' */

  /* MinMax: '<S282>/MinMax1' incorporates:
   *  Constant: '<S282>/sat7'
   */
  if (VIPM_FCMACCWhlTqReqVal_Nm < KIPM_FCMACCWhlTqReqValLo_Nm) {
    /* Switch: '<S282>/Switch4' incorporates:
     *  MinMax: '<S282>/MinMax1'
     */
    VIPM_FCMACCWhlTqReqVal_Nm = KIPM_FCMACCWhlTqReqValLo_Nm;
  }

  /* End of MinMax: '<S282>/MinMax1' */
  /* End of Outputs for SubSystem: '<S266>/Subsys_VIPM_FCMACCWhlTqReqVal_Nm' */

  /* Outputs for Atomic SubSystem: '<S266>/Subsys_VIPM_FCMACCWhlDece_mps2' */
  /* Logic: '<S280>/Logical Operator3' incorporates:
   *  Constant: '<S280>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_FCMACCWhlDeceVld_flg = (KIPM_FCMACCWhlDece_mps2_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_FCMMsgActv_flg);

  /* Switch: '<S280>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_FCMMsgActv_flg) {
    /* Switch: '<S280>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_FCM_B_CRCFlt_flg) {
      /* Product: '<S294>/Product' incorporates:
       *  Constant: '<S294>/Constant'
       *  Inport: '<Root>/FCM_B_CHA'
       */
      rtb_Product_b2 = (float32)
        (Rte_IRead_Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA())->FCM_ACCWhlDece *
        0.05F;

      /* Switch: '<S280>/Switch' incorporates:
       *  Sum: '<S294>/Add'
       *  Switch: '<S280>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_o = rtb_Product_b2 - 9.5F;
    }

    /* End of Switch: '<S280>/Switch3' */
  } else {
    /* Switch: '<S280>/Switch' incorporates:
     *  Constant: '<S280>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_o = KIPM_FCMACCWhlDeceDflt_mps2;
  }

  /* End of Switch: '<S280>/Switch' */

  /* Switch: '<S280>/Switch4' incorporates:
   *  Constant: '<S280>/sat3'
   *  Constant: '<S280>/sat4'
   */
  if (KIPM_FCMACCWhlDece_mps2_ovrdflg) {
    VIPM_FCMACCWhlDece_mps2 = KIPM_FCMACCWhlDece_mps2_ovrdval;
  } else {
    VIPM_FCMACCWhlDece_mps2 = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_o;
  }

  /* MinMax: '<S280>/MinMax' incorporates:
   *  Constant: '<S280>/sat6'
   *  Switch: '<S280>/Switch4'
   */
  if (VIPM_FCMACCWhlDece_mps2 > KIPM_FCMACCWhlDeceHi_mps2) {
    VIPM_FCMACCWhlDece_mps2 = KIPM_FCMACCWhlDeceHi_mps2;
  }

  /* End of MinMax: '<S280>/MinMax' */

  /* MinMax: '<S280>/MinMax1' incorporates:
   *  Constant: '<S280>/sat7'
   */
  if (VIPM_FCMACCWhlDece_mps2 < KIPM_FCMACCWhlDeceLo_mps2) {
    /* Switch: '<S280>/Switch4' incorporates:
     *  MinMax: '<S280>/MinMax1'
     */
    VIPM_FCMACCWhlDece_mps2 = KIPM_FCMACCWhlDeceLo_mps2;
  }

  /* End of MinMax: '<S280>/MinMax1' */
  /* End of Outputs for SubSystem: '<S266>/Subsys_VIPM_FCMACCWhlDece_mps2' */

  /* Outputs for Atomic SubSystem: '<S266>/Subsys_VIPM_FCMAccTarAccrnReqActv_flg' */
  /* Logic: '<S287>/Logical Operator3' incorporates:
   *  Constant: '<S287>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_FCMAccTarAccrnReqActvVld_flg = (KIPM_FCMAccTarAccrnReqActv_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_FCMMsgActv_flg);

  /* Switch: '<S287>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_FCMMsgActv_flg) {
    /* Switch: '<S287>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_FCM_B_CRCFlt_flg) {
      /* Switch: '<S287>/Switch' incorporates:
       *  Inport: '<Root>/FCM_B_CHA'
       *  Switch: '<S287>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_m2f =
        (Rte_IRead_Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA())
        ->FCM_AccTarAccrnReqActv;
    }

    /* End of Switch: '<S287>/Switch3' */
  } else {
    /* Switch: '<S287>/Switch' incorporates:
     *  Constant: '<S287>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_m2f = KIPM_FCMAccTarAccrnReqActvDflt_flg;
  }

  /* End of Switch: '<S287>/Switch' */

  /* Switch: '<S287>/Switch4' incorporates:
   *  Constant: '<S287>/sat3'
   */
  if (KIPM_FCMAccTarAccrnReqActv_flg_ovrdflg) {
    /* Switch: '<S287>/Switch4' incorporates:
     *  Constant: '<S287>/sat4'
     */
    VIPM_FCMAccTarAccrnReqActv_flg = KIPM_FCMAccTarAccrnReqActv_flg_ovrdval;
  } else {
    /* Switch: '<S287>/Switch4' */
    VIPM_FCMAccTarAccrnReqActv_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_m2f;
  }

  /* End of Switch: '<S287>/Switch4' */
  /* End of Outputs for SubSystem: '<S266>/Subsys_VIPM_FCMAccTarAccrnReqActv_flg' */

  /* Outputs for Atomic SubSystem: '<S266>/Subsys_VIPM_FCMAccTarAccrn_mps2' */
  /* Logic: '<S288>/Logical Operator3' incorporates:
   *  Constant: '<S288>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_FCMAccTarAccrnVld_flg = (KIPM_FCMAccTarAccrn_mps2_ovrdflg ||
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
      /* Product: '<S295>/Product' incorporates:
       *  Constant: '<S295>/Constant'
       *  Inport: '<Root>/FCM_B_CHA'
       */
      rtb_Product_b2 = (float32)
        (Rte_IRead_Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA())->FCM_AccTarAccrn *
        0.05F;

      /* Switch: '<S288>/Switch' incorporates:
       *  Sum: '<S295>/Add'
       *  Switch: '<S288>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_j = rtb_Product_b2 - 5.0F;
    }

    /* End of Switch: '<S288>/Switch3' */
  } else {
    /* Switch: '<S288>/Switch' incorporates:
     *  Constant: '<S288>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_j = KIPM_FCMAccTarAccrnDflt_mps2;
  }

  /* End of Switch: '<S288>/Switch' */

  /* Switch: '<S288>/Switch4' incorporates:
   *  Constant: '<S288>/sat3'
   *  Constant: '<S288>/sat4'
   */
  if (KIPM_FCMAccTarAccrn_mps2_ovrdflg) {
    VIPM_FCMAccTarAccrn_mps2 = KIPM_FCMAccTarAccrn_mps2_ovrdval;
  } else {
    VIPM_FCMAccTarAccrn_mps2 = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_j;
  }

  /* MinMax: '<S288>/MinMax' incorporates:
   *  Constant: '<S288>/sat6'
   *  Switch: '<S288>/Switch4'
   */
  if (VIPM_FCMAccTarAccrn_mps2 > KIPM_FCMAccTarAccrnHi_mps2) {
    VIPM_FCMAccTarAccrn_mps2 = KIPM_FCMAccTarAccrnHi_mps2;
  }

  /* End of MinMax: '<S288>/MinMax' */

  /* MinMax: '<S288>/MinMax1' incorporates:
   *  Constant: '<S288>/sat7'
   */
  if (VIPM_FCMAccTarAccrn_mps2 < KIPM_FCMAccTarAccrnLo_mps2) {
    /* Switch: '<S288>/Switch4' incorporates:
     *  MinMax: '<S288>/MinMax1'
     */
    VIPM_FCMAccTarAccrn_mps2 = KIPM_FCMAccTarAccrnLo_mps2;
  }

  /* End of MinMax: '<S288>/MinMax1' */
  /* End of Outputs for SubSystem: '<S266>/Subsys_VIPM_FCMAccTarAccrn_mps2' */

  /* Outputs for Atomic SubSystem: '<S266>/Subsys_VIPM_FCMEPBReq_enum' */
  /* Logic: '<S318>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/FCM_B_CHA'
   *  Logic: '<S291>/Logical Operator2'
   */
  rtb_LogicalOperator2_fz = ((Rte_IRead_Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA())
    ->FCM_EPBReqV && (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
    ->VIPM_FCMMsgActv_flg);

  /* Logic: '<S291>/Logical Operator3' incorporates:
   *  Constant: '<S291>/sat3'
   */
  VIPM_FCMEPBReqVld_flg = (KIPM_FCMEPBReq_enum_ovrdflg ||
    rtb_LogicalOperator2_fz);

  /* Switch: '<S291>/Switch' */
  if (rtb_LogicalOperator2_fz) {
    /* Switch: '<S291>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_FCM_B_CRCFlt_flg) {
      /* Switch: '<S291>/Switch' incorporates:
       *  Inport: '<Root>/FCM_B_CHA'
       *  Switch: '<S291>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pi =
        (Rte_IRead_Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA())->FCM_EPBReq;
    }

    /* End of Switch: '<S291>/Switch3' */
  } else {
    /* Switch: '<S291>/Switch' incorporates:
     *  Constant: '<S291>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pi = KIPM_FCMEPBReqDflt_enum;
  }

  /* End of Switch: '<S291>/Switch' */

  /* Switch: '<S291>/Switch4' incorporates:
   *  Constant: '<S291>/sat3'
   */
  if (KIPM_FCMEPBReq_enum_ovrdflg) {
    /* Switch: '<S291>/Switch4' incorporates:
     *  Constant: '<S291>/sat4'
     */
    VIPM_FCMEPBReq_enum = KIPM_FCMEPBReq_enum_ovrdval;
  } else {
    /* Switch: '<S291>/Switch4' */
    VIPM_FCMEPBReq_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pi;
  }

  /* End of Switch: '<S291>/Switch4' */
  /* End of Outputs for SubSystem: '<S266>/Subsys_VIPM_FCMEPBReq_enum' */

  /* Outputs for Atomic SubSystem: '<S266>/Subsys_VIPM_FCMAccTgtAxReq_flg' */
  /* Logic: '<S289>/Logical Operator3' incorporates:
   *  Constant: '<S289>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_FCMAccTgtAxReqVld_flg = (KIPM_FCMAccTgtAxReq_flg_ovrdflg ||
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
      /* Switch: '<S289>/Switch' incorporates:
       *  Inport: '<Root>/FCM_B_CHA'
       *  Switch: '<S289>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cb =
        (Rte_IRead_Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA())->FCM_AccTgtAxReq;
    }

    /* End of Switch: '<S289>/Switch3' */
  } else {
    /* Switch: '<S289>/Switch' incorporates:
     *  Constant: '<S289>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cb = KIPM_FCMAccTgtAxReqDflt_flg;
  }

  /* End of Switch: '<S289>/Switch' */

  /* Switch: '<S289>/Switch4' incorporates:
   *  Constant: '<S289>/sat3'
   */
  if (KIPM_FCMAccTgtAxReq_flg_ovrdflg) {
    /* Switch: '<S289>/Switch4' incorporates:
     *  Constant: '<S289>/sat4'
     */
    VIPM_FCMAccTgtAxReq_flg = KIPM_FCMAccTgtAxReq_flg_ovrdval;
  } else {
    /* Switch: '<S289>/Switch4' */
    VIPM_FCMAccTgtAxReq_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cb;
  }

  /* End of Switch: '<S289>/Switch4' */
  /* End of Outputs for SubSystem: '<S266>/Subsys_VIPM_FCMAccTgtAxReq_flg' */

  /* Outputs for Atomic SubSystem: '<S266>/Subsys_VIPM_FCMAccTgtAx_mps2' */
  /* Logic: '<S290>/Logical Operator3' incorporates:
   *  Constant: '<S290>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_FCMAccTgtAxVld_flg = (KIPM_FCMAccTgtAx_mps2_ovrdflg ||
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
      /* Product: '<S296>/Product' incorporates:
       *  Constant: '<S296>/Constant'
       *  Inport: '<Root>/FCM_B_CHA'
       */
      rtb_Product_b2 = (float32)
        (Rte_IRead_Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA())->FCM_AccTgtAx *
        0.05F;

      /* Switch: '<S290>/Switch' incorporates:
       *  Sum: '<S296>/Add'
       *  Switch: '<S290>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_e = rtb_Product_b2 - 9.5F;
    }

    /* End of Switch: '<S290>/Switch3' */
  } else {
    /* Switch: '<S290>/Switch' incorporates:
     *  Constant: '<S290>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_e = KIPM_FCMAccTgtAxDflt_mps2;
  }

  /* End of Switch: '<S290>/Switch' */

  /* Switch: '<S290>/Switch4' incorporates:
   *  Constant: '<S290>/sat3'
   *  Constant: '<S290>/sat4'
   */
  if (KIPM_FCMAccTgtAx_mps2_ovrdflg) {
    VIPM_FCMAccTgtAx_mps2 = KIPM_FCMAccTgtAx_mps2_ovrdval;
  } else {
    VIPM_FCMAccTgtAx_mps2 = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_e;
  }

  /* MinMax: '<S290>/MinMax' incorporates:
   *  Constant: '<S290>/sat6'
   *  Switch: '<S290>/Switch4'
   */
  if (VIPM_FCMAccTgtAx_mps2 > KIPM_FCMAccTgtAxHi_mps2) {
    VIPM_FCMAccTgtAx_mps2 = KIPM_FCMAccTgtAxHi_mps2;
  }

  /* End of MinMax: '<S290>/MinMax' */

  /* MinMax: '<S290>/MinMax1' incorporates:
   *  Constant: '<S290>/sat7'
   */
  if (VIPM_FCMAccTgtAx_mps2 < KIPM_FCMAccTgtAxLo_mps2) {
    /* Switch: '<S290>/Switch4' incorporates:
     *  MinMax: '<S290>/MinMax1'
     */
    VIPM_FCMAccTgtAx_mps2 = KIPM_FCMAccTgtAxLo_mps2;
  }

  /* End of MinMax: '<S290>/MinMax1' */
  /* End of Outputs for SubSystem: '<S266>/Subsys_VIPM_FCMAccTgtAx_mps2' */

  /* Outputs for Atomic SubSystem: '<S266>/Subsys_VIPM_FCMAccReqStandstill_flg' */
  /* Logic: '<S286>/Logical Operator3' incorporates:
   *  Constant: '<S286>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_FCMAccReqStandstillVld_flg = (KIPM_FCMAccReqStandstill_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_FCMMsgActv_flg);

  /* Switch: '<S286>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_FCMMsgActv_flg) {
    /* Switch: '<S286>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_FCM_B_CRCFlt_flg) {
      /* Switch: '<S286>/Switch' incorporates:
       *  Inport: '<Root>/FCM_B_CHA'
       *  Switch: '<S286>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_iv1 =
        (Rte_IRead_Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA())
        ->FCM_AccReqStandstill;
    }

    /* End of Switch: '<S286>/Switch3' */
  } else {
    /* Switch: '<S286>/Switch' incorporates:
     *  Constant: '<S286>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_iv1 = KIPM_FCMAccReqStandstillDflt_flg;
  }

  /* End of Switch: '<S286>/Switch' */

  /* Switch: '<S286>/Switch4' incorporates:
   *  Constant: '<S286>/sat3'
   */
  if (KIPM_FCMAccReqStandstill_flg_ovrdflg) {
    /* Switch: '<S286>/Switch4' incorporates:
     *  Constant: '<S286>/sat4'
     */
    VIPM_FCMAccReqStandstill_flg = KIPM_FCMAccReqStandstill_flg_ovrdval;
  } else {
    /* Switch: '<S286>/Switch4' */
    VIPM_FCMAccReqStandstill_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_iv1;
  }

  /* End of Switch: '<S286>/Switch4' */
  /* End of Outputs for SubSystem: '<S266>/Subsys_VIPM_FCMAccReqStandstill_flg' */

  /* Outputs for Atomic SubSystem: '<S266>/Subsys_VIPM_FCMAccReqDriveOff_flg' */
  /* Logic: '<S285>/Logical Operator3' incorporates:
   *  Constant: '<S285>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_FCMAccReqDriveOffVld_flg = (KIPM_FCMAccReqDriveOff_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_FCMMsgActv_flg);

  /* Switch: '<S285>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_FCMMsgActv_flg) {
    /* Switch: '<S285>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_FCM_B_CRCFlt_flg) {
      /* Switch: '<S285>/Switch' incorporates:
       *  Inport: '<Root>/FCM_B_CHA'
       *  Switch: '<S285>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_g3 =
        (Rte_IRead_Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA())
        ->FCM_AccReqDriveOff;
    }

    /* End of Switch: '<S285>/Switch3' */
  } else {
    /* Switch: '<S285>/Switch' incorporates:
     *  Constant: '<S285>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_g3 = KIPM_FCMAccReqDriveOffDflt_flg;
  }

  /* End of Switch: '<S285>/Switch' */

  /* Switch: '<S285>/Switch4' incorporates:
   *  Constant: '<S285>/sat3'
   */
  if (KIPM_FCMAccReqDriveOff_flg_ovrdflg) {
    /* Switch: '<S285>/Switch4' incorporates:
     *  Constant: '<S285>/sat4'
     */
    VIPM_FCMAccReqDriveOff_flg = KIPM_FCMAccReqDriveOff_flg_ovrdval;
  } else {
    /* Switch: '<S285>/Switch4' */
    VIPM_FCMAccReqDriveOff_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_g3;
  }

  /* End of Switch: '<S285>/Switch4' */
  /* End of Outputs for SubSystem: '<S266>/Subsys_VIPM_FCMAccReqDriveOff_flg' */

  /* Outputs for Atomic SubSystem: '<S266>/Subsys_VIPM_FCMAccMode_enum' */
  /* Logic: '<S284>/Logical Operator3' incorporates:
   *  Constant: '<S284>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_FCMAccModeVld_flg = (KIPM_FCMAccMode_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_FCMMsgActv_flg);

  /* Switch: '<S284>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_FCMMsgActv_flg) {
    /* Switch: '<S284>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_FCM_B_CRCFlt_flg) {
      /* Switch: '<S284>/Switch' incorporates:
       *  DataTypeConversion: '<S284>/Data Type Conversion2'
       *  Inport: '<Root>/FCM_B_CHA'
       *  Switch: '<S284>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ecm =
        (Rte_IRead_Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA())->FCM_AccMode;
    }

    /* End of Switch: '<S284>/Switch3' */
  } else {
    /* Switch: '<S284>/Switch' incorporates:
     *  Constant: '<S284>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ecm = KIPM_FCMAccModeDflt_enum;
  }

  /* End of Switch: '<S284>/Switch' */

  /* Switch: '<S284>/Switch4' incorporates:
   *  Constant: '<S284>/sat3'
   */
  if (KIPM_FCMAccMode_enum_ovrdflg) {
    /* Switch: '<S284>/Switch4' incorporates:
     *  Constant: '<S284>/sat4'
     */
    VIPM_FCMAccMode_enum = KIPM_FCMAccMode_enum_ovrdval;
  } else {
    /* Switch: '<S284>/Switch4' incorporates:
     *  Switch: '<S284>/Switch'
     */
    VIPM_FCMAccMode_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ecm;
  }

  /* End of Switch: '<S284>/Switch4' */
  /* End of Outputs for SubSystem: '<S266>/Subsys_VIPM_FCMAccMode_enum' */

  /* Outputs for Atomic SubSystem: '<S266>/Subsys_VIPM_FCMAEBReq_flg' */
  /* Logic: '<S283>/Logical Operator3' incorporates:
   *  Constant: '<S283>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_FCMAEBReqVld_flg = (KIPM_FCMAEBReq_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_FCMMsgActv_flg);

  /* Switch: '<S283>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_FCMMsgActv_flg) {
    /* Switch: '<S283>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_FCM_B_CRCFlt_flg) {
      /* Switch: '<S283>/Switch' incorporates:
       *  Inport: '<Root>/FCM_B_CHA'
       *  Switch: '<S283>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jg0u =
        (Rte_IRead_Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA())->FCM_AEBReq;
    }

    /* End of Switch: '<S283>/Switch3' */
  } else {
    /* Switch: '<S283>/Switch' incorporates:
     *  Constant: '<S283>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jg0u = KIPM_FCMAEBReqDflt_flg;
  }

  /* End of Switch: '<S283>/Switch' */

  /* Switch: '<S283>/Switch4' incorporates:
   *  Constant: '<S283>/sat3'
   */
  if (KIPM_FCMAEBReq_flg_ovrdflg) {
    /* Switch: '<S283>/Switch4' incorporates:
     *  Constant: '<S283>/sat4'
     */
    VIPM_FCMAEBReq_flg = KIPM_FCMAEBReq_flg_ovrdval;
  } else {
    /* Switch: '<S283>/Switch4' */
    VIPM_FCMAEBReq_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jg0u;
  }

  /* End of Switch: '<S283>/Switch4' */
  /* End of Outputs for SubSystem: '<S266>/Subsys_VIPM_FCMAEBReq_flg' */

  /* Outputs for Atomic SubSystem: '<S266>/Subsys_VIPM_FCMTrnLampReq_enum' */
  /* Logic: '<S292>/Logical Operator3' incorporates:
   *  Constant: '<S292>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_FCMTrnLampReqVld_flg = (KIPM_FCMTrnLampReq_enum_ovrdflg ||
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
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jk =
        (Rte_IRead_Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA())->FCM_TurnLampReq;
    }

    /* End of Switch: '<S292>/Switch3' */
  } else {
    /* Switch: '<S292>/Switch' incorporates:
     *  Constant: '<S292>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jk = KIPM_FCMTrnLampReqDflt_enum;
  }

  /* End of Switch: '<S292>/Switch' */

  /* Switch: '<S292>/Switch4' incorporates:
   *  Constant: '<S292>/sat3'
   */
  if (KIPM_FCMTrnLampReq_enum_ovrdflg) {
    /* Switch: '<S292>/Switch4' incorporates:
     *  Constant: '<S292>/sat4'
     */
    VIPM_FCMTrnLampReq_enum = KIPM_FCMTrnLampReq_enum_ovrdval;
  } else {
    /* Switch: '<S292>/Switch4' */
    VIPM_FCMTrnLampReq_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jk;
  }

  /* End of Switch: '<S292>/Switch4' */
  /* End of Outputs for SubSystem: '<S266>/Subsys_VIPM_FCMTrnLampReq_enum' */

  /* Outputs for Atomic SubSystem: '<S266>/Subsys_VIPM_FCMACCSdnMode_enum' */
  /* Logic: '<S279>/Logical Operator3' incorporates:
   *  Constant: '<S279>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_FCMACCSdnModeVld_flg = (KIPM_FCMACCSdnMode_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_FCMMsgActv_flg);

  /* Switch: '<S279>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_FCMMsgActv_flg) {
    /* Switch: '<S279>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_FCM_B_CRCFlt_flg) {
      /* Switch: '<S279>/Switch' incorporates:
       *  Inport: '<Root>/FCM_B_CHA'
       *  Switch: '<S279>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_k3 =
        (Rte_IRead_Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA())
        ->FCM_ACC_ShutdownMode;
    }

    /* End of Switch: '<S279>/Switch3' */
  } else {
    /* Switch: '<S279>/Switch' incorporates:
     *  Constant: '<S279>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_k3 = KIPM_FCMACCSdnModeDflt_enum;
  }

  /* End of Switch: '<S279>/Switch' */

  /* Switch: '<S279>/Switch4' incorporates:
   *  Constant: '<S279>/sat3'
   */
  if (KIPM_FCMACCSdnMode_enum_ovrdflg) {
    /* Switch: '<S279>/Switch4' incorporates:
     *  Constant: '<S279>/sat4'
     */
    VIPM_FCMACCSdnMode_enum = KIPM_FCMACCSdnMode_enum_ovrdval;
  } else {
    /* Switch: '<S279>/Switch4' */
    VIPM_FCMACCSdnMode_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_k3;
  }

  /* End of Switch: '<S279>/Switch4' */
  /* End of Outputs for SubSystem: '<S266>/Subsys_VIPM_FCMACCSdnMode_enum' */

  /* BusCreator: '<S266>/BusCreator' incorporates:
   *  DataTypeConversion: '<S266>/Data Type Conversion3'
   *  Logic: '<S279>/Logical Operator3'
   *  Logic: '<S280>/Logical Operator3'
   *  Logic: '<S281>/Logical Operator3'
   *  Logic: '<S282>/Logical Operator3'
   *  Logic: '<S283>/Logical Operator3'
   *  Logic: '<S284>/Logical Operator3'
   *  Logic: '<S285>/Logical Operator3'
   *  Logic: '<S286>/Logical Operator3'
   *  Logic: '<S287>/Logical Operator3'
   *  Logic: '<S288>/Logical Operator3'
   *  Logic: '<S289>/Logical Operator3'
   *  Logic: '<S290>/Logical Operator3'
   *  Logic: '<S291>/Logical Operator3'
   *  Logic: '<S292>/Logical Operator3'
   *  MinMax: '<S280>/MinMax1'
   *  MinMax: '<S282>/MinMax1'
   *  MinMax: '<S288>/MinMax1'
   *  MinMax: '<S290>/MinMax1'
   *  Switch: '<S279>/Switch4'
   *  Switch: '<S281>/Switch4'
   *  Switch: '<S283>/Switch4'
   *  Switch: '<S284>/Switch4'
   *  Switch: '<S285>/Switch4'
   *  Switch: '<S286>/Switch4'
   *  Switch: '<S287>/Switch4'
   *  Switch: '<S289>/Switch4'
   *  Switch: '<S291>/Switch4'
   *  Switch: '<S292>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA.VIPM_FCMACCWhlTqReqActv_flg =
    VIPM_FCMACCWhlTqReqActv_flg;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA.VIPM_FCMACCWhlTqReqActvVld_flg =
    VIPM_FCMACCWhlTqReqActvVld_flg;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA.VIPM_FCMACCWhlTqReqVal_Nm =
    VIPM_FCMACCWhlTqReqVal_Nm;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA.VIPM_FCMACCWhlTqReqValVld_flg =
    VIPM_FCMACCWhlTqReqValVld_flg;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA.VIPM_FCMACCWhlDece_mps2 =
    VIPM_FCMACCWhlDece_mps2;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA.VIPM_FCMACCWhlDeceVld_flg =
    VIPM_FCMACCWhlDeceVld_flg;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA.VIPM_FCMAccTarAccrnReqActv_flg =
    VIPM_FCMAccTarAccrnReqActv_flg;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA.VIPM_FCMAccTarAccrnReqActvVld_flg =
    VIPM_FCMAccTarAccrnReqActvVld_flg;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA.VIPM_FCMAccTarAccrn_mps2 =
    VIPM_FCMAccTarAccrn_mps2;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA.VIPM_FCMAccTarAccrnVld_flg =
    VIPM_FCMAccTarAccrnVld_flg;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA.VIPM_FCMEPBReq_enum = VIPM_FCMEPBReq_enum;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA.VIPM_FCMEPBReqVld_flg = VIPM_FCMEPBReqVld_flg;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA.VIPM_FCMAccTgtAxReq_flg =
    VIPM_FCMAccTgtAxReq_flg;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA.VIPM_FCMAccTgtAxReqVld_flg =
    VIPM_FCMAccTgtAxReqVld_flg;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA.VIPM_FCMAccTgtAx_mps2 = VIPM_FCMAccTgtAx_mps2;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA.VIPM_FCMAccTgtAxVld_flg =
    VIPM_FCMAccTgtAxVld_flg;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA.VIPM_FCMAccReqStandstill_flg =
    VIPM_FCMAccReqStandstill_flg;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA.VIPM_FCMAccReqStandstillVld_flg =
    VIPM_FCMAccReqStandstillVld_flg;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA.VIPM_FCMAccReqDriveOff_flg =
    VIPM_FCMAccReqDriveOff_flg;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA.VIPM_FCMAccReqDriveOffVld_flg =
    VIPM_FCMAccReqDriveOffVld_flg;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA.VIPM_FCMAccMode_enum = VIPM_FCMAccMode_enum;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA.VIPM_FCMAccModeVld_flg =
    VIPM_FCMAccModeVld_flg;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA.VIPM_FCMAEBReq_flg = VIPM_FCMAEBReq_flg;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA.VIPM_FCMAEBReqVld_flg = VIPM_FCMAEBReqVld_flg;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA.VIPM_FCMTrnLampReq_enum =
    VIPM_FCMTrnLampReq_enum;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA.VIPM_FCMTrnLampReqVld_flg =
    VIPM_FCMTrnLampReqVld_flg;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA.VIPM_FCMACCSdnMode_enum =
    VIPM_FCMACCSdnMode_enum;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA.VIPM_FCMACCSdnModeVld_flg =
    VIPM_FCMACCSdnModeVld_flg;

  /* Outputs for Atomic SubSystem: '<S297>/Subsys_VIPM_BMSDCSInletConnectSta_flg' */
  /* Logic: '<S305>/Logical Operator3' incorporates:
   *  Constant: '<S305>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSDCSInletConnectStaVld_flg = (KIPM_BMSDCSInletConnectSta_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S305>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_BMSMsgActv_flg) {
    /* Switch: '<S305>/Switch' incorporates:
     *  Inport: '<Root>/BMS_10_DC_ChargeStates_EPT'
     *  Switch: '<S305>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_df =
      (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_10_DC_ChargeStates_EPT_BMS_10_DC_ChargeStates_EPT
       ())->BMS_DCS_InletConnectSta;
  } else {
    /* Switch: '<S305>/Switch' incorporates:
     *  Constant: '<S305>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_df = KIPM_BMSDCSInletConnectStaDflt_flg;
  }

  /* End of Switch: '<S305>/Switch' */

  /* Switch: '<S305>/Switch4' incorporates:
   *  Constant: '<S305>/sat3'
   */
  if (KIPM_BMSDCSInletConnectSta_flg_ovrdflg) {
    /* Switch: '<S305>/Switch4' incorporates:
     *  Constant: '<S305>/sat4'
     */
    VIPM_BMSDCSInletConnectSta_flg = KIPM_BMSDCSInletConnectSta_flg_ovrdval;
  } else {
    /* Switch: '<S305>/Switch4' */
    VIPM_BMSDCSInletConnectSta_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_df;
  }

  /* End of Switch: '<S305>/Switch4' */
  /* End of Outputs for SubSystem: '<S297>/Subsys_VIPM_BMSDCSInletConnectSta_flg' */

  /* Outputs for Atomic SubSystem: '<S297>/Subsys_VIPM_BMSDCSActOprtMode_enum' */
  /* Logic: '<S304>/Logical Operator3' incorporates:
   *  Constant: '<S304>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSDCSActOprtModeVld_flg = (KIPM_BMSDCSActOprtMode_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S304>/Switch4' incorporates:
   *  Constant: '<S304>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S304>/Switch'
   */
  if (KIPM_BMSDCSActOprtMode_enum_ovrdflg) {
    /* Switch: '<S304>/Switch4' incorporates:
     *  Constant: '<S304>/sat4'
     */
    VIPM_BMSDCSActOprtMode_enum = KIPM_BMSDCSActOprtMode_enum_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
             ->VIPM_BMSMsgActv_flg) {
    /* Switch: '<S304>/Switch4' incorporates:
     *  DataTypeConversion: '<S304>/Data Type Conversion2'
     *  Inport: '<Root>/BMS_10_DC_ChargeStates_EPT'
     *  Switch: '<S304>/Switch'
     */
    VIPM_BMSDCSActOprtMode_enum =
      (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_10_DC_ChargeStates_EPT_BMS_10_DC_ChargeStates_EPT
       ())->BMS_DCS_ActOprtMode;
  } else {
    /* Switch: '<S304>/Switch4' incorporates:
     *  Constant: '<S304>/sat5'
     *  Switch: '<S304>/Switch'
     */
    VIPM_BMSDCSActOprtMode_enum = KIPM_BMSDCSActOprtModeDflt_enum;
  }

  /* End of Switch: '<S304>/Switch4' */
  /* End of Outputs for SubSystem: '<S297>/Subsys_VIPM_BMSDCSActOprtMode_enum' */

  /* BusCreator: '<S297>/BusCreator' incorporates:
   *  DataTypeConversion: '<S297>/Data Type Conversion'
   *  Logic: '<S304>/Logical Operator3'
   *  Logic: '<S305>/Logical Operator3'
   *  Switch: '<S304>/Switch4'
   *  Switch: '<S305>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_BMS_10_DC_ChargeStates_EPT.VIPM_BMSDCSInletConnectSta_flg
    = VIPM_BMSDCSInletConnectSta_flg;
  AppSwcIpm_ARID_DEF.IPM_BMS_10_DC_ChargeStates_EPT.VIPM_BMSDCSInletConnectStaVld_flg
    = VIPM_BMSDCSInletConnectStaVld_flg;
  AppSwcIpm_ARID_DEF.IPM_BMS_10_DC_ChargeStates_EPT.VIPM_BMSDCSActOprtMode_enum =
    VIPM_BMSDCSActOprtMode_enum;
  AppSwcIpm_ARID_DEF.IPM_BMS_10_DC_ChargeStates_EPT.VIPM_BMSDCSActOprtModeVld_flg
    = VIPM_BMSDCSActOprtModeVld_flg;

  /* Outputs for Atomic SubSystem: '<S298>/Subsys_VIPM_BMSThermrunawayWrn_enum' */
  /* Logic: '<S313>/Logical Operator3' incorporates:
   *  Constant: '<S313>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSThermrunawayWrnVld_flg = (KIPM_BMSThermrunawayWrn_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S313>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_BMSMsgActv_flg) {
    /* Switch: '<S313>/Switch' incorporates:
     *  Inport: '<Root>/BMS_1_MainState_EPT'
     *  Switch: '<S313>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_dg =
      (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT()
      )->BMS_ThermalrunawayWrn;
  } else {
    /* Switch: '<S313>/Switch' incorporates:
     *  Constant: '<S313>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_dg = KIPM_BMSThermrunawayWrnDflt_enum;
  }

  /* End of Switch: '<S313>/Switch' */

  /* Switch: '<S313>/Switch4' incorporates:
   *  Constant: '<S313>/sat3'
   */
  if (KIPM_BMSThermrunawayWrn_enum_ovrdflg) {
    /* Switch: '<S313>/Switch4' incorporates:
     *  Constant: '<S313>/sat4'
     */
    VIPM_BMSThermrunawayWrn_enum = KIPM_BMSThermrunawayWrn_enum_ovrdval;
  } else {
    /* Switch: '<S313>/Switch4' */
    VIPM_BMSThermrunawayWrn_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_dg;
  }

  /* End of Switch: '<S313>/Switch4' */
  /* End of Outputs for SubSystem: '<S298>/Subsys_VIPM_BMSThermrunawayWrn_enum' */

  /* Outputs for Atomic SubSystem: '<S298>/Subsys_VIPM_BMSDchrgInterlockSta_enum' */
  /* Logic: '<S308>/Logical Operator3' incorporates:
   *  Constant: '<S308>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSDchrgInterlockStaVld_flg = (KIPM_BMSDchrgInterlockSta_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S308>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_BMSMsgActv_flg) {
    /* Switch: '<S308>/Switch' incorporates:
     *  Inport: '<Root>/BMS_1_MainState_EPT'
     *  Switch: '<S308>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_of =
      (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT()
      )->BMS_DisChargeInterlockSta;
  } else {
    /* Switch: '<S308>/Switch' incorporates:
     *  Constant: '<S308>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_of = KIPM_BMSDchrgInterlockStaDflt_enum;
  }

  /* End of Switch: '<S308>/Switch' */

  /* Switch: '<S308>/Switch4' incorporates:
   *  Constant: '<S308>/sat3'
   */
  if (KIPM_BMSDchrgInterlockSta_enum_ovrdflg) {
    /* Switch: '<S308>/Switch4' incorporates:
     *  Constant: '<S308>/sat4'
     */
    VIPM_BMSDchrgInterlockSta_enum = KIPM_BMSDchrgInterlockSta_enum_ovrdval;
  } else {
    /* Switch: '<S308>/Switch4' */
    VIPM_BMSDchrgInterlockSta_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_of;
  }

  /* End of Switch: '<S308>/Switch4' */
  /* End of Outputs for SubSystem: '<S298>/Subsys_VIPM_BMSDchrgInterlockSta_enum' */

  /* Outputs for Atomic SubSystem: '<S298>/Subsys_VIPM_BMSChrgInterlockSta_enum' */
  /* Logic: '<S307>/Logical Operator3' incorporates:
   *  Constant: '<S307>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSChrgInterlockStaVld_flg = (KIPM_BMSChrgInterlockSta_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S307>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_BMSMsgActv_flg) {
    /* Switch: '<S307>/Switch' incorporates:
     *  Inport: '<Root>/BMS_1_MainState_EPT'
     *  Switch: '<S307>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_gr =
      (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT()
      )->BMS_ChargeInterlockSta;
  } else {
    /* Switch: '<S307>/Switch' incorporates:
     *  Constant: '<S307>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_gr = KIPM_BMSChrgInterlockStaDflt_enum;
  }

  /* End of Switch: '<S307>/Switch' */

  /* Switch: '<S307>/Switch4' incorporates:
   *  Constant: '<S307>/sat3'
   */
  if (KIPM_BMSChrgInterlockSta_enum_ovrdflg) {
    /* Switch: '<S307>/Switch4' incorporates:
     *  Constant: '<S307>/sat4'
     */
    VIPM_BMSChrgInterlockSta_enum = KIPM_BMSChrgInterlockSta_enum_ovrdval;
  } else {
    /* Switch: '<S307>/Switch4' */
    VIPM_BMSChrgInterlockSta_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_gr;
  }

  /* End of Switch: '<S307>/Switch4' */
  /* End of Outputs for SubSystem: '<S298>/Subsys_VIPM_BMSChrgInterlockSta_enum' */

  /* Outputs for Atomic SubSystem: '<S298>/Subsys_VIPM_BMSActExchgCurnt_A' */
  /* Logic: '<S306>/Logical Operator3' incorporates:
   *  Constant: '<S306>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSActExchgCurntVld_flg = (KIPM_BMSActExchgCurnt_A_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S306>/Switch4' incorporates:
   *  Constant: '<S306>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S306>/Switch'
   */
  if (KIPM_BMSActExchgCurnt_A_ovrdflg) {
    /* MinMax: '<S306>/MinMax' incorporates:
     *  Constant: '<S306>/sat4'
     *  MinMax: '<S344>/MinMax'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSActExchgCurnt_A_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
             ->VIPM_BMSMsgActv_flg) {
    /* Product: '<S314>/Product' incorporates:
     *  Constant: '<S314>/Constant'
     *  Inport: '<Root>/BMS_1_MainState_EPT'
     *  Switch: '<S306>/Switch'
     */
    rtb_Product_b2 = (float32)
      (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT()
      )->BMS_ActlExchgCurnt * 0.1F;

    /* MinMax: '<S306>/MinMax' incorporates:
     *  MinMax: '<S344>/MinMax'
     *  Sum: '<S314>/Add'
     *  Switch: '<S306>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = rtb_Product_b2 - 1000.0F;
  } else {
    /* MinMax: '<S306>/MinMax' incorporates:
     *  Constant: '<S306>/sat5'
     *  MinMax: '<S344>/MinMax'
     *  Switch: '<S306>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSActExchgCurntDflt_A;
  }

  /* End of Switch: '<S306>/Switch4' */

  /* MinMax: '<S306>/MinMax' incorporates:
   *  Constant: '<S306>/sat6'
   */
  if (VIPM_BMSCellVoltMin_mV > KIPM_BMSActExchgCurntHi_A) {
    VIPM_BMSCellVoltMin_mV = KIPM_BMSActExchgCurntHi_A;
  }

  /* MinMax: '<S306>/MinMax1' incorporates:
   *  Constant: '<S306>/sat7'
   */
  if (VIPM_BMSCellVoltMin_mV >= KIPM_BMSActExchgCurntLo_A) {
    /* MinMax: '<S306>/MinMax1' */
    VIPM_BMSActExchgCurnt_A = VIPM_BMSCellVoltMin_mV;
  } else {
    /* MinMax: '<S306>/MinMax1' */
    VIPM_BMSActExchgCurnt_A = KIPM_BMSActExchgCurntLo_A;
  }

  /* End of MinMax: '<S306>/MinMax1' */
  /* End of Outputs for SubSystem: '<S298>/Subsys_VIPM_BMSActExchgCurnt_A' */

  /* Outputs for Atomic SubSystem: '<S298>/Subsys_VIPM_BMSEmgcySdnReq_flg' */
  /* Logic: '<S309>/Logical Operator3' incorporates:
   *  Constant: '<S309>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSEmgcySdnReqVld_flg = (KIPM_BMSEmgcySdnReq_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S309>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_BMSMsgActv_flg) {
    /* Switch: '<S309>/Switch' incorporates:
     *  Inport: '<Root>/BMS_1_MainState_EPT'
     *  Switch: '<S309>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nv =
      (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT()
      )->BMS_Emeshutdown_Req;
  } else {
    /* Switch: '<S309>/Switch' incorporates:
     *  Constant: '<S309>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nv = KIPM_BMSEmgcySdnReqDflt_flg;
  }

  /* End of Switch: '<S309>/Switch' */

  /* Switch: '<S309>/Switch4' incorporates:
   *  Constant: '<S309>/sat3'
   */
  if (KIPM_BMSEmgcySdnReq_flg_ovrdflg) {
    /* Switch: '<S309>/Switch4' incorporates:
     *  Constant: '<S309>/sat4'
     */
    VIPM_BMSEmgcySdnReq_flg = KIPM_BMSEmgcySdnReq_flg_ovrdval;
  } else {
    /* Switch: '<S309>/Switch4' */
    VIPM_BMSEmgcySdnReq_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nv;
  }

  /* End of Switch: '<S309>/Switch4' */
  /* End of Outputs for SubSystem: '<S298>/Subsys_VIPM_BMSEmgcySdnReq_flg' */

  /* Outputs for Atomic SubSystem: '<S298>/Subsys_VIPM_BMSSysFailSta_enum' */
  /* Logic: '<S312>/Logical Operator3' incorporates:
   *  Constant: '<S312>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSSysFailStaVld_flg = (KIPM_BMSSysFailSta_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S312>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_BMSMsgActv_flg) {
    /* Switch: '<S312>/Switch' incorporates:
     *  Inport: '<Root>/BMS_1_MainState_EPT'
     *  Switch: '<S312>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jh =
      (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT()
      )->BMS_SysFailSta;
  } else {
    /* Switch: '<S312>/Switch' incorporates:
     *  Constant: '<S312>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jh = KIPM_BMSSysFailStaDflt_enum;
  }

  /* End of Switch: '<S312>/Switch' */

  /* Switch: '<S312>/Switch4' incorporates:
   *  Constant: '<S312>/sat3'
   */
  if (KIPM_BMSSysFailSta_enum_ovrdflg) {
    /* Switch: '<S312>/Switch4' incorporates:
     *  Constant: '<S312>/sat4'
     */
    VIPM_BMSSysFailSta_enum = KIPM_BMSSysFailSta_enum_ovrdval;
  } else {
    /* Switch: '<S312>/Switch4' */
    VIPM_BMSSysFailSta_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jh;
  }

  /* End of Switch: '<S312>/Switch4' */
  /* End of Outputs for SubSystem: '<S298>/Subsys_VIPM_BMSSysFailSta_enum' */

  /* Outputs for Atomic SubSystem: '<S298>/Subsys_VIPM_BMSPwrTrainConnectSta_enum' */
  /* Logic: '<S310>/Logical Operator3' incorporates:
   *  Constant: '<S310>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSPwrTrainConnectStaVld_flg = (KIPM_BMSPwrTrainConnectSta_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S310>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_BMSMsgActv_flg) {
    /* Switch: '<S310>/Switch' incorporates:
     *  Inport: '<Root>/BMS_1_MainState_EPT'
     *  Switch: '<S310>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_b =
      (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT()
      )->BMS_PwrTrainConnectSta;
  } else {
    /* Switch: '<S310>/Switch' incorporates:
     *  Constant: '<S310>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_b = KIPM_BMSPwrTrainConnectStaDflt_enum;
  }

  /* End of Switch: '<S310>/Switch' */

  /* Switch: '<S310>/Switch4' incorporates:
   *  Constant: '<S310>/sat3'
   */
  if (KIPM_BMSPwrTrainConnectSta_enum_ovrdflg) {
    /* Switch: '<S310>/Switch4' incorporates:
     *  Constant: '<S310>/sat4'
     */
    VIPM_BMSPwrTrainConnectSta_enum = KIPM_BMSPwrTrainConnectSta_enum_ovrdval;
  } else {
    /* Switch: '<S310>/Switch4' */
    VIPM_BMSPwrTrainConnectSta_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_b;
  }

  /* End of Switch: '<S310>/Switch4' */
  /* End of Outputs for SubSystem: '<S298>/Subsys_VIPM_BMSPwrTrainConnectSta_enum' */

  /* Outputs for Atomic SubSystem: '<S298>/Subsys_VIPM_BMSRunSta_enum' */
  /* Logic: '<S311>/Logical Operator3' incorporates:
   *  Constant: '<S311>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSRunStaVld_flg = (KIPM_BMSRunSta_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S311>/Switch4' incorporates:
   *  Constant: '<S311>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S311>/Switch'
   */
  if (KIPM_BMSRunSta_enum_ovrdflg) {
    /* Switch: '<S311>/Switch4' incorporates:
     *  Constant: '<S311>/sat4'
     */
    VIPM_BMSRunSta_enum = KIPM_BMSRunSta_enum_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
             ->VIPM_BMSMsgActv_flg) {
    /* Switch: '<S311>/Switch4' incorporates:
     *  DataTypeConversion: '<S311>/Data Type Conversion2'
     *  Inport: '<Root>/BMS_1_MainState_EPT'
     *  Switch: '<S311>/Switch'
     */
    VIPM_BMSRunSta_enum =
      (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT()
      )->BMS_RunState;
  } else {
    /* Switch: '<S311>/Switch4' incorporates:
     *  Constant: '<S311>/sat5'
     *  Switch: '<S311>/Switch'
     */
    VIPM_BMSRunSta_enum = KIPM_BMSRunStaDflt_enum;
  }

  /* End of Switch: '<S311>/Switch4' */
  /* End of Outputs for SubSystem: '<S298>/Subsys_VIPM_BMSRunSta_enum' */

  /* BusCreator: '<S298>/BusCreator' incorporates:
   *  DataTypeConversion: '<S298>/Data Type Conversion'
   *  Logic: '<S306>/Logical Operator3'
   *  Logic: '<S307>/Logical Operator3'
   *  Logic: '<S308>/Logical Operator3'
   *  Logic: '<S309>/Logical Operator3'
   *  Logic: '<S310>/Logical Operator3'
   *  Logic: '<S311>/Logical Operator3'
   *  Logic: '<S312>/Logical Operator3'
   *  Logic: '<S313>/Logical Operator3'
   *  MinMax: '<S306>/MinMax1'
   *  Switch: '<S307>/Switch4'
   *  Switch: '<S308>/Switch4'
   *  Switch: '<S309>/Switch4'
   *  Switch: '<S310>/Switch4'
   *  Switch: '<S311>/Switch4'
   *  Switch: '<S312>/Switch4'
   *  Switch: '<S313>/Switch4'
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

  /* Outputs for Atomic SubSystem: '<S299>/Subsys_VIPM_BMSBatSOCRpt_pct' */
  /* Logic: '<S316>/Logical Operator3' incorporates:
   *  Constant: '<S316>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSBatSOCRptVld_flg = (KIPM_BMSBatSOCRpt_pct_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S316>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_BMSMsgActv_flg) {
    /* Switch: '<S316>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_BMS_2_BatState_CRCFlt_flg) {
      /* Switch: '<S316>/Switch' incorporates:
       *  Constant: '<S319>/Constant'
       *  Inport: '<Root>/BMS_2_BatState_EPT'
       *  Product: '<S319>/Product'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_c = (float32)
        (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_2_BatState_EPT_BMS_2_BatState_EPT()
        )->BMS_BatSOC_Rpt * 0.1F;
    }

    /* End of Switch: '<S316>/Switch3' */
  } else {
    /* Switch: '<S316>/Switch' incorporates:
     *  Constant: '<S316>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_c = KIPM_BMSBatSOCRptDflt_pct;
  }

  /* End of Switch: '<S316>/Switch' */

  /* Switch: '<S316>/Switch4' incorporates:
   *  Constant: '<S316>/sat3'
   *  Constant: '<S316>/sat4'
   */
  if (KIPM_BMSBatSOCRpt_pct_ovrdflg) {
    VIPM_BMSBatSOCRpt_pct = KIPM_BMSBatSOCRpt_pct_ovrdval;
  } else {
    VIPM_BMSBatSOCRpt_pct = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_c;
  }

  /* MinMax: '<S316>/MinMax' incorporates:
   *  Constant: '<S316>/sat6'
   *  Switch: '<S316>/Switch4'
   */
  if (VIPM_BMSBatSOCRpt_pct > KIPM_BMSBatSOCRptHi_pct) {
    VIPM_BMSBatSOCRpt_pct = KIPM_BMSBatSOCRptHi_pct;
  }

  /* End of MinMax: '<S316>/MinMax' */

  /* MinMax: '<S316>/MinMax1' incorporates:
   *  Constant: '<S316>/sat7'
   */
  if (VIPM_BMSBatSOCRpt_pct < KIPM_BMSBatSOCRptLo_pct) {
    /* Switch: '<S316>/Switch4' incorporates:
     *  MinMax: '<S316>/MinMax1'
     */
    VIPM_BMSBatSOCRpt_pct = KIPM_BMSBatSOCRptLo_pct;
  }

  /* End of MinMax: '<S316>/MinMax1' */
  /* End of Outputs for SubSystem: '<S299>/Subsys_VIPM_BMSBatSOCRpt_pct' */

  /* Outputs for Atomic SubSystem: '<S299>/Subsys_VIPM_BMSBatSOH_pct' */
  /* Logic: '<S317>/Logical Operator3' incorporates:
   *  Constant: '<S317>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSBatSOHVld_flg = (KIPM_BMSBatSOH_pct_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S317>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_BMSMsgActv_flg) {
    /* Switch: '<S317>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_BMS_2_BatState_CRCFlt_flg) {
      /* Switch: '<S317>/Switch' incorporates:
       *  Constant: '<S320>/Constant'
       *  Inport: '<Root>/BMS_2_BatState_EPT'
       *  Product: '<S320>/Product'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_d = (float32)
        (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_2_BatState_EPT_BMS_2_BatState_EPT()
        )->BMS_BatSOH * 0.1F;
    }

    /* End of Switch: '<S317>/Switch3' */
  } else {
    /* Switch: '<S317>/Switch' incorporates:
     *  Constant: '<S317>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_d = KIPM_BMSBatSOHDflt_pct;
  }

  /* End of Switch: '<S317>/Switch' */

  /* Switch: '<S317>/Switch4' incorporates:
   *  Constant: '<S317>/sat3'
   *  Constant: '<S317>/sat4'
   */
  if (KIPM_BMSBatSOH_pct_ovrdflg) {
    VIPM_BMSBatSOH_pct = KIPM_BMSBatSOH_pct_ovrdval;
  } else {
    VIPM_BMSBatSOH_pct = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_d;
  }

  /* MinMax: '<S317>/MinMax' incorporates:
   *  Constant: '<S317>/sat6'
   *  Switch: '<S317>/Switch4'
   */
  if (VIPM_BMSBatSOH_pct > KIPM_BMSBatSOHHi_pct) {
    VIPM_BMSBatSOH_pct = KIPM_BMSBatSOHHi_pct;
  }

  /* End of MinMax: '<S317>/MinMax' */

  /* MinMax: '<S317>/MinMax1' incorporates:
   *  Constant: '<S317>/sat7'
   */
  if (VIPM_BMSBatSOH_pct < KIPM_BMSBatSOHLo_pct) {
    /* Switch: '<S317>/Switch4' incorporates:
     *  MinMax: '<S317>/MinMax1'
     */
    VIPM_BMSBatSOH_pct = KIPM_BMSBatSOHLo_pct;
  }

  /* End of MinMax: '<S317>/MinMax1' */
  /* End of Outputs for SubSystem: '<S299>/Subsys_VIPM_BMSBatSOH_pct' */

  /* Outputs for Atomic SubSystem: '<S299>/Subsys_VIPM_BMSHVBatActVolt_V' */
  /* Logic: '<S318>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/BMS_2_BatState_EPT'
   */
  rtb_LogicalOperator2_fz =
    ((Rte_IRead_Runbl_IpmCanRx_20ms_BMS_2_BatState_EPT_BMS_2_BatState_EPT())
     ->BMS_HVBatActlVoltageV &&
     (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
     ->VIPM_BMSMsgActv_flg);

  /* Logic: '<S318>/Logical Operator3' incorporates:
   *  Constant: '<S318>/sat3'
   */
  VIPM_BMSHVBatActVoltVld_flg = (KIPM_BMSHVBatActVolt_V_ovrdflg ||
    rtb_LogicalOperator2_fz);

  /* Switch: '<S318>/Switch' */
  if (rtb_LogicalOperator2_fz) {
    /* Switch: '<S318>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_BMS_2_BatState_CRCFlt_flg) {
      /* Switch: '<S318>/Switch' incorporates:
       *  Constant: '<S321>/Constant'
       *  Inport: '<Root>/BMS_2_BatState_EPT'
       *  Product: '<S321>/Product'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_l = (float32)
        (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_2_BatState_EPT_BMS_2_BatState_EPT()
        )->BMS_HVBatActlVoltage * 0.1F;
    }

    /* End of Switch: '<S318>/Switch3' */
  } else {
    /* Switch: '<S318>/Switch' incorporates:
     *  Constant: '<S318>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_l = KIPM_BMSHVBatActVoltDflt_V;
  }

  /* End of Switch: '<S318>/Switch' */

  /* Switch: '<S318>/Switch4' incorporates:
   *  Constant: '<S318>/sat3'
   *  Constant: '<S318>/sat4'
   */
  if (KIPM_BMSHVBatActVolt_V_ovrdflg) {
    VIPM_BMSHVBatActVolt_V = KIPM_BMSHVBatActVolt_V_ovrdval;
  } else {
    VIPM_BMSHVBatActVolt_V = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_l;
  }

  /* MinMax: '<S318>/MinMax' incorporates:
   *  Constant: '<S318>/sat6'
   *  Switch: '<S318>/Switch4'
   */
  if (VIPM_BMSHVBatActVolt_V > KIPM_BMSHVBatActVoltHi_V) {
    VIPM_BMSHVBatActVolt_V = KIPM_BMSHVBatActVoltHi_V;
  }

  /* End of MinMax: '<S318>/MinMax' */

  /* MinMax: '<S318>/MinMax1' incorporates:
   *  Constant: '<S318>/sat7'
   */
  if (VIPM_BMSHVBatActVolt_V < KIPM_BMSHVBatActVoltLo_V) {
    /* Switch: '<S318>/Switch4' incorporates:
     *  MinMax: '<S318>/MinMax1'
     */
    VIPM_BMSHVBatActVolt_V = KIPM_BMSHVBatActVoltLo_V;
  }

  /* End of MinMax: '<S318>/MinMax1' */
  /* End of Outputs for SubSystem: '<S299>/Subsys_VIPM_BMSHVBatActVolt_V' */

  /* Outputs for Atomic SubSystem: '<S299>/Subsys_VIPM_BMSBatSOCAct_pct' */
  /* Logic: '<S315>/Logical Operator3' incorporates:
   *  Constant: '<S315>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSBatSOCActVld_flg = (KIPM_BMSBatSOCAct_pct_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S315>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_BMSMsgActv_flg) {
    /* Switch: '<S315>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_BMS_2_BatState_CRCFlt_flg) {
      /* Switch: '<S315>/Switch' incorporates:
       *  Constant: '<S322>/Constant'
       *  Inport: '<Root>/BMS_2_BatState_EPT'
       *  Product: '<S322>/Product'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_n = (float32)
        (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_2_BatState_EPT_BMS_2_BatState_EPT()
        )->BMS_BatSOC_Actl * 0.1F;
    }

    /* End of Switch: '<S315>/Switch3' */
  } else {
    /* Switch: '<S315>/Switch' incorporates:
     *  Constant: '<S315>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_n = KIPM_BMSBatSOCActDflt_pct;
  }

  /* End of Switch: '<S315>/Switch' */

  /* Switch: '<S315>/Switch4' incorporates:
   *  Constant: '<S315>/sat3'
   *  Constant: '<S315>/sat4'
   */
  if (KIPM_BMSBatSOCAct_pct_ovrdflg) {
    VIPM_BMSBatSOCAct_pct = KIPM_BMSBatSOCAct_pct_ovrdval;
  } else {
    VIPM_BMSBatSOCAct_pct = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_n;
  }

  /* MinMax: '<S315>/MinMax' incorporates:
   *  Constant: '<S315>/sat6'
   *  Switch: '<S315>/Switch4'
   */
  if (VIPM_BMSBatSOCAct_pct > KIPM_BMSBatSOCActHi_pct) {
    VIPM_BMSBatSOCAct_pct = KIPM_BMSBatSOCActHi_pct;
  }

  /* End of MinMax: '<S315>/MinMax' */

  /* MinMax: '<S315>/MinMax1' incorporates:
   *  Constant: '<S315>/sat7'
   */
  if (VIPM_BMSBatSOCAct_pct < KIPM_BMSBatSOCActLo_pct) {
    /* Switch: '<S315>/Switch4' incorporates:
     *  MinMax: '<S315>/MinMax1'
     */
    VIPM_BMSBatSOCAct_pct = KIPM_BMSBatSOCActLo_pct;
  }

  /* End of MinMax: '<S315>/MinMax1' */
  /* End of Outputs for SubSystem: '<S299>/Subsys_VIPM_BMSBatSOCAct_pct' */

  /* BusCreator: '<S299>/BusCreator' incorporates:
   *  Logic: '<S315>/Logical Operator3'
   *  Logic: '<S316>/Logical Operator3'
   *  Logic: '<S317>/Logical Operator3'
   *  Logic: '<S318>/Logical Operator3'
   *  MinMax: '<S315>/MinMax1'
   *  MinMax: '<S316>/MinMax1'
   *  MinMax: '<S317>/MinMax1'
   *  MinMax: '<S318>/MinMax1'
   */
  AppSwcIpm_ARID_DEF.IPM_BMS_2_BatState_EPT.VIPM_BMSBatSOCRpt_pct =
    VIPM_BMSBatSOCRpt_pct;
  AppSwcIpm_ARID_DEF.IPM_BMS_2_BatState_EPT.VIPM_BMSBatSOCRptVld_flg =
    VIPM_BMSBatSOCRptVld_flg;
  AppSwcIpm_ARID_DEF.IPM_BMS_2_BatState_EPT.VIPM_BMSBatSOH_pct =
    VIPM_BMSBatSOH_pct;
  AppSwcIpm_ARID_DEF.IPM_BMS_2_BatState_EPT.VIPM_BMSBatSOHVld_flg =
    VIPM_BMSBatSOHVld_flg;
  AppSwcIpm_ARID_DEF.IPM_BMS_2_BatState_EPT.VIPM_BMSHVBatActVolt_V =
    VIPM_BMSHVBatActVolt_V;
  AppSwcIpm_ARID_DEF.IPM_BMS_2_BatState_EPT.VIPM_BMSHVBatActVoltVld_flg =
    VIPM_BMSHVBatActVoltVld_flg;
  AppSwcIpm_ARID_DEF.IPM_BMS_2_BatState_EPT.VIPM_BMSBatSOCAct_pct =
    VIPM_BMSBatSOCAct_pct;
  AppSwcIpm_ARID_DEF.IPM_BMS_2_BatState_EPT.VIPM_BMSBatSOCActVld_flg =
    VIPM_BMSBatSOCActVld_flg;

  /* Outputs for Atomic SubSystem: '<S300>/Subsys_VIPM_BMSDCSChrgReq_flg' */
  /* Logic: '<S323>/Logical Operator3' incorporates:
   *  Constant: '<S323>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSDCSChrgReqVld_flg = (KIPM_BMSDCSChrgReq_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S323>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_BMSMsgActv_flg) {
    /* Switch: '<S323>/Switch' incorporates:
     *  Inport: '<Root>/BMS_3_DC_ChargeState_EPT'
     *  Switch: '<S323>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jn =
      (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_3_DC_ChargeState_EPT_BMS_3_DC_ChargeState_EPT
       ())->BMS_DCS_ChargeRequest;
  } else {
    /* Switch: '<S323>/Switch' incorporates:
     *  Constant: '<S323>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jn = KIPM_BMSDCSChrgReqDflt_flg;
  }

  /* End of Switch: '<S323>/Switch' */

  /* Switch: '<S323>/Switch4' incorporates:
   *  Constant: '<S323>/sat3'
   */
  if (KIPM_BMSDCSChrgReq_flg_ovrdflg) {
    /* Switch: '<S323>/Switch4' incorporates:
     *  Constant: '<S323>/sat4'
     */
    VIPM_BMSDCSChrgReq_flg = KIPM_BMSDCSChrgReq_flg_ovrdval;
  } else {
    /* Switch: '<S323>/Switch4' */
    VIPM_BMSDCSChrgReq_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jn;
  }

  /* End of Switch: '<S323>/Switch4' */
  /* End of Outputs for SubSystem: '<S300>/Subsys_VIPM_BMSDCSChrgReq_flg' */

  /* BusCreator: '<S300>/BusCreator' incorporates:
   *  Logic: '<S323>/Logical Operator3'
   *  Switch: '<S323>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_BMS_3_DC_ChargeState_EPT.VIPM_BMSDCSChrgReq_flg =
    VIPM_BMSDCSChrgReq_flg;
  AppSwcIpm_ARID_DEF.IPM_BMS_3_DC_ChargeState_EPT.VIPM_BMSDCSChrgReqVld_flg =
    VIPM_BMSDCSChrgReqVld_flg;

  /* Outputs for Atomic SubSystem: '<S301>/Subsys_VIPM_BMSACChrgAtclSta_enum' */
  /* Logic: '<S324>/Logical Operator3' incorporates:
   *  Constant: '<S324>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSACChrgAtclStaVld_flg = (KIPM_BMSACChrgAtclSta_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S324>/Switch4' incorporates:
   *  Constant: '<S324>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S324>/Switch'
   */
  if (KIPM_BMSACChrgAtclSta_enum_ovrdflg) {
    /* Switch: '<S324>/Switch4' incorporates:
     *  Constant: '<S324>/sat4'
     */
    VIPM_BMSACChrgAtclSta_enum = KIPM_BMSACChrgAtclSta_enum_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
             ->VIPM_BMSMsgActv_flg) {
    /* Switch: '<S324>/Switch4' incorporates:
     *  DataTypeConversion: '<S324>/Data Type Conversion2'
     *  Inport: '<Root>/BMS_4_AC_ChargeState_EPT'
     *  Switch: '<S324>/Switch'
     */
    VIPM_BMSACChrgAtclSta_enum =
      (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_4_AC_ChargeState_EPT_BMS_4_AC_ChargeState_EPT
       ())->BMS_ACChrgAtclSta;
  } else {
    /* Switch: '<S324>/Switch4' incorporates:
     *  Constant: '<S324>/sat5'
     *  Switch: '<S324>/Switch'
     */
    VIPM_BMSACChrgAtclSta_enum = KIPM_BMSACChrgAtclStaDflt_enum;
  }

  /* End of Switch: '<S324>/Switch4' */
  /* End of Outputs for SubSystem: '<S301>/Subsys_VIPM_BMSACChrgAtclSta_enum' */

  /* Outputs for Atomic SubSystem: '<S301>/Subsys_VIPM_BMSOutlCooltActlTemp_C' */
  /* Logic: '<S329>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/BMS_4_AC_ChargeState_EPT'
   */
  rtb_LogicalOperator2_fz =
    ((Rte_IRead_Runbl_IpmCanRx_20ms_BMS_4_AC_ChargeState_EPT_BMS_4_AC_ChargeState_EPT
      ())->BMS_OutletCoolantActlTempValid &&
     (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
     ->VIPM_BMSMsgActv_flg);

  /* Logic: '<S329>/Logical Operator3' incorporates:
   *  Constant: '<S329>/sat3'
   */
  VIPM_BMSOutlCooltActlTempVld_flg = (KIPM_BMSOutlCooltActlTemp_C_ovrdflg ||
    rtb_LogicalOperator2_fz);

  /* Switch: '<S329>/Switch4' incorporates:
   *  Constant: '<S329>/sat3'
   *  Switch: '<S329>/Switch'
   */
  if (KIPM_BMSOutlCooltActlTemp_C_ovrdflg) {
    /* MinMax: '<S306>/MinMax' incorporates:
     *  Constant: '<S329>/sat4'
     *  MinMax: '<S344>/MinMax'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSOutlCooltActlTemp_C_ovrdval;
  } else if (rtb_LogicalOperator2_fz) {
    /* Product: '<S330>/Product' incorporates:
     *  Inport: '<Root>/BMS_4_AC_ChargeState_EPT'
     *  Switch: '<S329>/Switch'
     */
    rtb_Product_a =
      (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_4_AC_ChargeState_EPT_BMS_4_AC_ChargeState_EPT
       ())->BMS_OutletCoolantActlTemp;

    /* MinMax: '<S306>/MinMax' incorporates:
     *  MinMax: '<S344>/MinMax'
     *  Sum: '<S330>/Add'
     *  Switch: '<S329>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = (float32)rtb_Product_a - 40.0F;
  } else {
    /* MinMax: '<S306>/MinMax' incorporates:
     *  Constant: '<S329>/sat5'
     *  MinMax: '<S344>/MinMax'
     *  Switch: '<S329>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSOutlCooltActlTempDflt_C;
  }

  /* End of Switch: '<S329>/Switch4' */

  /* MinMax: '<S329>/MinMax' incorporates:
   *  Constant: '<S329>/sat6'
   */
  if (VIPM_BMSCellVoltMin_mV > KIPM_BMSOutlCooltActlTempHi_C) {
    /* MinMax: '<S306>/MinMax' */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSOutlCooltActlTempHi_C;
  }

  /* End of MinMax: '<S329>/MinMax' */

  /* MinMax: '<S329>/MinMax1' incorporates:
   *  Constant: '<S329>/sat7'
   */
  if (VIPM_BMSCellVoltMin_mV >= KIPM_BMSOutlCooltActlTempLo_C) {
    /* MinMax: '<S329>/MinMax1' */
    VIPM_BMSOutlCooltActlTemp_C = VIPM_BMSCellVoltMin_mV;
  } else {
    /* MinMax: '<S329>/MinMax1' */
    VIPM_BMSOutlCooltActlTemp_C = KIPM_BMSOutlCooltActlTempLo_C;
  }

  /* End of MinMax: '<S329>/MinMax1' */
  /* End of Outputs for SubSystem: '<S301>/Subsys_VIPM_BMSOutlCooltActlTemp_C' */

  /* Outputs for Atomic SubSystem: '<S301>/Subsys_VIPM_BMSInletCooltActlTemp_C' */
  /* Logic: '<S325>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/BMS_4_AC_ChargeState_EPT'
   */
  rtb_LogicalOperator2_fz =
    ((Rte_IRead_Runbl_IpmCanRx_20ms_BMS_4_AC_ChargeState_EPT_BMS_4_AC_ChargeState_EPT
      ())->BMS_InletCoolantActlTempValid &&
     (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
     ->VIPM_BMSMsgActv_flg);

  /* Logic: '<S325>/Logical Operator3' incorporates:
   *  Constant: '<S325>/sat3'
   */
  VIPM_BMSInletCooltActlTempVld_flg = (KIPM_BMSInletCooltActlTemp_C_ovrdflg ||
    rtb_LogicalOperator2_fz);

  /* Switch: '<S325>/Switch4' incorporates:
   *  Constant: '<S325>/sat3'
   *  Switch: '<S325>/Switch'
   */
  if (KIPM_BMSInletCooltActlTemp_C_ovrdflg) {
    /* MinMax: '<S306>/MinMax' incorporates:
     *  Constant: '<S325>/sat4'
     *  MinMax: '<S344>/MinMax'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSInletCooltActlTemp_C_ovrdval;
  } else if (rtb_LogicalOperator2_fz) {
    /* Product: '<S331>/Product' incorporates:
     *  Inport: '<Root>/BMS_4_AC_ChargeState_EPT'
     *  Switch: '<S325>/Switch'
     */
    rtb_Product_a =
      (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_4_AC_ChargeState_EPT_BMS_4_AC_ChargeState_EPT
       ())->BMS_InletCoolantActlTemp;

    /* MinMax: '<S306>/MinMax' incorporates:
     *  MinMax: '<S344>/MinMax'
     *  Sum: '<S331>/Add'
     *  Switch: '<S325>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = (float32)rtb_Product_a - 40.0F;
  } else {
    /* MinMax: '<S306>/MinMax' incorporates:
     *  Constant: '<S325>/sat5'
     *  MinMax: '<S344>/MinMax'
     *  Switch: '<S325>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSInletCooltActlTempDflt_C;
  }

  /* End of Switch: '<S325>/Switch4' */

  /* MinMax: '<S325>/MinMax' incorporates:
   *  Constant: '<S325>/sat6'
   */
  if (VIPM_BMSCellVoltMin_mV > KIPM_BMSInletCooltActlTempHi_C) {
    /* MinMax: '<S306>/MinMax' */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSInletCooltActlTempHi_C;
  }

  /* End of MinMax: '<S325>/MinMax' */

  /* MinMax: '<S325>/MinMax1' incorporates:
   *  Constant: '<S325>/sat7'
   */
  if (VIPM_BMSCellVoltMin_mV >= KIPM_BMSInletCooltActlTempLo_C) {
    /* MinMax: '<S325>/MinMax1' */
    VIPM_BMSInletCooltActlTemp_C = VIPM_BMSCellVoltMin_mV;
  } else {
    /* MinMax: '<S325>/MinMax1' */
    VIPM_BMSInletCooltActlTemp_C = KIPM_BMSInletCooltActlTempLo_C;
  }

  /* End of MinMax: '<S325>/MinMax1' */
  /* End of Outputs for SubSystem: '<S301>/Subsys_VIPM_BMSInletCooltActlTemp_C' */

  /* Outputs for Atomic SubSystem: '<S301>/Subsys_VIPM_BMSIsoResist_MOhm' */
  /* Logic: '<S326>/Logical Operator3' incorporates:
   *  Constant: '<S326>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSIsoResistVld_flg = (KIPM_BMSIsoResist_MOhm_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S326>/Switch4' incorporates:
   *  Constant: '<S326>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S326>/Switch'
   */
  if (KIPM_BMSIsoResist_MOhm_ovrdflg) {
    /* MinMax: '<S306>/MinMax' incorporates:
     *  Constant: '<S326>/sat4'
     *  MinMax: '<S344>/MinMax'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSIsoResist_MOhm_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
             ->VIPM_BMSMsgActv_flg) {
    /* MinMax: '<S306>/MinMax' incorporates:
     *  Constant: '<S332>/Constant'
     *  Inport: '<Root>/BMS_4_AC_ChargeState_EPT'
     *  MinMax: '<S344>/MinMax'
     *  Product: '<S332>/Product'
     *  Switch: '<S326>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = (float32)
      (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_4_AC_ChargeState_EPT_BMS_4_AC_ChargeState_EPT
       ())->BMS_IsoResistance * 0.02F;
  } else {
    /* MinMax: '<S306>/MinMax' incorporates:
     *  Constant: '<S326>/sat5'
     *  MinMax: '<S344>/MinMax'
     *  Switch: '<S326>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSIsoResistDflt_MOhm;
  }

  /* End of Switch: '<S326>/Switch4' */

  /* MinMax: '<S326>/MinMax' incorporates:
   *  Constant: '<S326>/sat6'
   */
  if (VIPM_BMSCellVoltMin_mV > KIPM_BMSIsoResistHi_MOhm) {
    /* MinMax: '<S306>/MinMax' */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSIsoResistHi_MOhm;
  }

  /* End of MinMax: '<S326>/MinMax' */

  /* MinMax: '<S326>/MinMax1' incorporates:
   *  Constant: '<S326>/sat7'
   */
  if (VIPM_BMSCellVoltMin_mV >= KIPM_BMSIsoResistLo_MOhm) {
    /* MinMax: '<S326>/MinMax1' */
    VIPM_BMSIsoResist_MOhm = VIPM_BMSCellVoltMin_mV;
  } else {
    /* MinMax: '<S326>/MinMax1' */
    VIPM_BMSIsoResist_MOhm = KIPM_BMSIsoResistLo_MOhm;
  }

  /* End of MinMax: '<S326>/MinMax1' */
  /* End of Outputs for SubSystem: '<S301>/Subsys_VIPM_BMSIsoResist_MOhm' */

  /* Outputs for Atomic SubSystem: '<S301>/Subsys_VIPM_BMSMaxChrgVoltAC_V' */
  /* Logic: '<S328>/Logical Operator3' incorporates:
   *  Constant: '<S328>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSMaxChrgVoltACVld_flg = (KIPM_BMSMaxChrgVoltAC_V_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S328>/Switch4' incorporates:
   *  Constant: '<S328>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S328>/Switch'
   */
  if (KIPM_BMSMaxChrgVoltAC_V_ovrdflg) {
    /* MinMax: '<S306>/MinMax' incorporates:
     *  Constant: '<S328>/sat4'
     *  MinMax: '<S344>/MinMax'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSMaxChrgVoltAC_V_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
             ->VIPM_BMSMsgActv_flg) {
    /* MinMax: '<S306>/MinMax' incorporates:
     *  Constant: '<S333>/Constant'
     *  Inport: '<Root>/BMS_4_AC_ChargeState_EPT'
     *  MinMax: '<S344>/MinMax'
     *  Product: '<S333>/Product'
     *  Switch: '<S328>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = (float32)
      (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_4_AC_ChargeState_EPT_BMS_4_AC_ChargeState_EPT
       ())->BMS_MaxChrgVoltage_AC * 0.5F;
  } else {
    /* MinMax: '<S306>/MinMax' incorporates:
     *  Constant: '<S328>/sat5'
     *  MinMax: '<S344>/MinMax'
     *  Switch: '<S328>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSMaxChrgVoltACDflt_V;
  }

  /* End of Switch: '<S328>/Switch4' */

  /* MinMax: '<S328>/MinMax' incorporates:
   *  Constant: '<S328>/sat6'
   */
  if (VIPM_BMSCellVoltMin_mV > KIPM_BMSMaxChrgVoltACHi_V) {
    /* MinMax: '<S306>/MinMax' */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSMaxChrgVoltACHi_V;
  }

  /* End of MinMax: '<S328>/MinMax' */

  /* MinMax: '<S328>/MinMax1' incorporates:
   *  Constant: '<S328>/sat7'
   */
  if (VIPM_BMSCellVoltMin_mV >= KIPM_BMSMaxChrgVoltACLo_V) {
    /* MinMax: '<S328>/MinMax1' */
    VIPM_BMSMaxChrgVoltAC_V = VIPM_BMSCellVoltMin_mV;
  } else {
    /* MinMax: '<S328>/MinMax1' */
    VIPM_BMSMaxChrgVoltAC_V = KIPM_BMSMaxChrgVoltACLo_V;
  }

  /* End of MinMax: '<S328>/MinMax1' */
  /* End of Outputs for SubSystem: '<S301>/Subsys_VIPM_BMSMaxChrgVoltAC_V' */

  /* Outputs for Atomic SubSystem: '<S301>/Subsys_VIPM_BMSMaxChrgCurntAC_A' */
  /* Logic: '<S327>/Logical Operator3' incorporates:
   *  Constant: '<S327>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSMaxChrgCurntACVld_flg = (KIPM_BMSMaxChrgCurntAC_A_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S327>/Switch4' incorporates:
   *  Constant: '<S327>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S327>/Switch'
   */
  if (KIPM_BMSMaxChrgCurntAC_A_ovrdflg) {
    /* MinMax: '<S306>/MinMax' incorporates:
     *  Constant: '<S327>/sat4'
     *  MinMax: '<S344>/MinMax'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSMaxChrgCurntAC_A_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
             ->VIPM_BMSMsgActv_flg) {
    /* MinMax: '<S306>/MinMax' incorporates:
     *  Constant: '<S334>/Constant'
     *  Inport: '<Root>/BMS_4_AC_ChargeState_EPT'
     *  MinMax: '<S344>/MinMax'
     *  Product: '<S334>/Product'
     *  Switch: '<S327>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = (float32)
      (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_4_AC_ChargeState_EPT_BMS_4_AC_ChargeState_EPT
       ())->BMS_MaxChrgCurrent_AC * 0.1F;
  } else {
    /* MinMax: '<S306>/MinMax' incorporates:
     *  Constant: '<S327>/sat5'
     *  MinMax: '<S344>/MinMax'
     *  Switch: '<S327>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSMaxChrgCurntACDflt_A;
  }

  /* End of Switch: '<S327>/Switch4' */

  /* MinMax: '<S327>/MinMax' incorporates:
   *  Constant: '<S327>/sat6'
   */
  if (VIPM_BMSCellVoltMin_mV > KIPM_BMSMaxChrgCurntACHi_A) {
    /* MinMax: '<S306>/MinMax' */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSMaxChrgCurntACHi_A;
  }

  /* End of MinMax: '<S327>/MinMax' */

  /* MinMax: '<S327>/MinMax1' incorporates:
   *  Constant: '<S327>/sat7'
   */
  if (VIPM_BMSCellVoltMin_mV >= KIPM_BMSMaxChrgCurntACLo_A) {
    /* MinMax: '<S327>/MinMax1' */
    VIPM_BMSMaxChrgCurntAC_A = VIPM_BMSCellVoltMin_mV;
  } else {
    /* MinMax: '<S327>/MinMax1' */
    VIPM_BMSMaxChrgCurntAC_A = KIPM_BMSMaxChrgCurntACLo_A;
  }

  /* End of MinMax: '<S327>/MinMax1' */
  /* End of Outputs for SubSystem: '<S301>/Subsys_VIPM_BMSMaxChrgCurntAC_A' */

  /* BusCreator: '<S301>/BusCreator' incorporates:
   *  DataTypeConversion: '<S301>/Data Type Conversion'
   *  Logic: '<S324>/Logical Operator3'
   *  Logic: '<S325>/Logical Operator3'
   *  Logic: '<S326>/Logical Operator3'
   *  Logic: '<S327>/Logical Operator3'
   *  Logic: '<S328>/Logical Operator3'
   *  Logic: '<S329>/Logical Operator3'
   *  MinMax: '<S325>/MinMax1'
   *  MinMax: '<S326>/MinMax1'
   *  MinMax: '<S327>/MinMax1'
   *  MinMax: '<S328>/MinMax1'
   *  MinMax: '<S329>/MinMax1'
   *  Switch: '<S324>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_BMS_4_AC_ChargeState_EPT.VIPM_BMSACChrgAtclSta_enum =
    VIPM_BMSACChrgAtclSta_enum;
  AppSwcIpm_ARID_DEF.IPM_BMS_4_AC_ChargeState_EPT.VIPM_BMSACChrgAtclStaVld_flg =
    VIPM_BMSACChrgAtclStaVld_flg;
  AppSwcIpm_ARID_DEF.IPM_BMS_4_AC_ChargeState_EPT.VIPM_BMSOutlCooltActlTemp_C =
    VIPM_BMSOutlCooltActlTemp_C;
  AppSwcIpm_ARID_DEF.IPM_BMS_4_AC_ChargeState_EPT.VIPM_BMSOutlCooltActlTempVld_flg
    = VIPM_BMSOutlCooltActlTempVld_flg;
  AppSwcIpm_ARID_DEF.IPM_BMS_4_AC_ChargeState_EPT.VIPM_BMSInletCooltActlTemp_C =
    VIPM_BMSInletCooltActlTemp_C;
  AppSwcIpm_ARID_DEF.IPM_BMS_4_AC_ChargeState_EPT.VIPM_BMSInletCooltActlTempVld_flg
    = VIPM_BMSInletCooltActlTempVld_flg;
  AppSwcIpm_ARID_DEF.IPM_BMS_4_AC_ChargeState_EPT.VIPM_BMSIsoResist_MOhm =
    VIPM_BMSIsoResist_MOhm;
  AppSwcIpm_ARID_DEF.IPM_BMS_4_AC_ChargeState_EPT.VIPM_BMSIsoResistVld_flg =
    VIPM_BMSIsoResistVld_flg;
  AppSwcIpm_ARID_DEF.IPM_BMS_4_AC_ChargeState_EPT.VIPM_BMSMaxChrgVoltAC_V =
    VIPM_BMSMaxChrgVoltAC_V;
  AppSwcIpm_ARID_DEF.IPM_BMS_4_AC_ChargeState_EPT.VIPM_BMSMaxChrgVoltACVld_flg =
    VIPM_BMSMaxChrgVoltACVld_flg;
  AppSwcIpm_ARID_DEF.IPM_BMS_4_AC_ChargeState_EPT.VIPM_BMSMaxChrgCurntAC_A =
    VIPM_BMSMaxChrgCurntAC_A;
  AppSwcIpm_ARID_DEF.IPM_BMS_4_AC_ChargeState_EPT.VIPM_BMSMaxChrgCurntACVld_flg =
    VIPM_BMSMaxChrgCurntACVld_flg;

  /* Outputs for Atomic SubSystem: '<S302>/Subsys_VIPM_BMSMaxConDisCurnt_A' */
  /* Logic: '<S336>/Logical Operator3' incorporates:
   *  Constant: '<S336>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSMaxConDisCurntVld_flg = (KIPM_BMSMaxConDisCurnt_A_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S336>/Switch4' incorporates:
   *  Constant: '<S336>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S336>/Switch'
   */
  if (KIPM_BMSMaxConDisCurnt_A_ovrdflg) {
    /* MinMax: '<S306>/MinMax' incorporates:
     *  Constant: '<S336>/sat4'
     *  MinMax: '<S344>/MinMax'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSMaxConDisCurnt_A_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
             ->VIPM_BMSMsgActv_flg) {
    /* MinMax: '<S306>/MinMax' incorporates:
     *  Constant: '<S339>/Constant'
     *  Inport: '<Root>/BMS_6_DischrgRecup_EPT'
     *  MinMax: '<S344>/MinMax'
     *  Product: '<S339>/Product'
     *  Switch: '<S336>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = (float32)
      (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_6_DischrgRecup_EPT_BMS_6_DischrgRecup_EPT
       ())->BMS_MaxConDisCurnt * 0.1F;
  } else {
    /* MinMax: '<S306>/MinMax' incorporates:
     *  Constant: '<S336>/sat5'
     *  MinMax: '<S344>/MinMax'
     *  Switch: '<S336>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSMaxConDisCurntDflt_A;
  }

  /* End of Switch: '<S336>/Switch4' */

  /* MinMax: '<S336>/MinMax' incorporates:
   *  Constant: '<S336>/sat6'
   */
  if (VIPM_BMSCellVoltMin_mV > KIPM_BMSMaxConDisCurntHi_A) {
    /* MinMax: '<S306>/MinMax' */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSMaxConDisCurntHi_A;
  }

  /* End of MinMax: '<S336>/MinMax' */

  /* MinMax: '<S336>/MinMax1' incorporates:
   *  Constant: '<S336>/sat7'
   */
  if (VIPM_BMSCellVoltMin_mV >= KIPM_BMSMaxConDisCurntLo_A) {
    /* MinMax: '<S336>/MinMax1' */
    VIPM_BMSMaxConDisCurnt_A = VIPM_BMSCellVoltMin_mV;
  } else {
    /* MinMax: '<S336>/MinMax1' */
    VIPM_BMSMaxConDisCurnt_A = KIPM_BMSMaxConDisCurntLo_A;
  }

  /* End of MinMax: '<S336>/MinMax1' */
  /* End of Outputs for SubSystem: '<S302>/Subsys_VIPM_BMSMaxConDisCurnt_A' */

  /* Outputs for Atomic SubSystem: '<S302>/Subsys_VIPM_BMSMaxInsDisCurnt_A' */
  /* Logic: '<S338>/Logical Operator3' incorporates:
   *  Constant: '<S338>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSMaxInsDisCurntVld_flg = (KIPM_BMSMaxInsDisCurnt_A_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S338>/Switch4' incorporates:
   *  Constant: '<S338>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S338>/Switch'
   */
  if (KIPM_BMSMaxInsDisCurnt_A_ovrdflg) {
    /* MinMax: '<S306>/MinMax' incorporates:
     *  Constant: '<S338>/sat4'
     *  MinMax: '<S344>/MinMax'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSMaxInsDisCurnt_A_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
             ->VIPM_BMSMsgActv_flg) {
    /* MinMax: '<S306>/MinMax' incorporates:
     *  Constant: '<S340>/Constant'
     *  Inport: '<Root>/BMS_6_DischrgRecup_EPT'
     *  MinMax: '<S344>/MinMax'
     *  Product: '<S340>/Product'
     *  Switch: '<S338>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = (float32)
      (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_6_DischrgRecup_EPT_BMS_6_DischrgRecup_EPT
       ())->BMS_MaxInstanDisCurnt * 0.1F;
  } else {
    /* MinMax: '<S306>/MinMax' incorporates:
     *  Constant: '<S338>/sat5'
     *  MinMax: '<S344>/MinMax'
     *  Switch: '<S338>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSMaxInsDisCurntDflt_A;
  }

  /* End of Switch: '<S338>/Switch4' */

  /* MinMax: '<S338>/MinMax' incorporates:
   *  Constant: '<S338>/sat6'
   */
  if (VIPM_BMSCellVoltMin_mV > KIPM_BMSMaxInsDisCurntHi_A) {
    /* MinMax: '<S306>/MinMax' */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSMaxInsDisCurntHi_A;
  }

  /* End of MinMax: '<S338>/MinMax' */

  /* MinMax: '<S338>/MinMax1' incorporates:
   *  Constant: '<S338>/sat7'
   */
  if (VIPM_BMSCellVoltMin_mV >= KIPM_BMSMaxInsDisCurntLo_A) {
    /* MinMax: '<S338>/MinMax1' */
    VIPM_BMSMaxInsDisCurnt_A = VIPM_BMSCellVoltMin_mV;
  } else {
    /* MinMax: '<S338>/MinMax1' */
    VIPM_BMSMaxInsDisCurnt_A = KIPM_BMSMaxInsDisCurntLo_A;
  }

  /* End of MinMax: '<S338>/MinMax1' */
  /* End of Outputs for SubSystem: '<S302>/Subsys_VIPM_BMSMaxInsDisCurnt_A' */

  /* Outputs for Atomic SubSystem: '<S302>/Subsys_VIPM_BMSMaxConChrgCurnt_A' */
  /* Logic: '<S335>/Logical Operator3' incorporates:
   *  Constant: '<S335>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSMaxConChrgCurntVld_flg = (KIPM_BMSMaxConChrgCurnt_A_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S335>/Switch4' incorporates:
   *  Constant: '<S335>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S335>/Switch'
   */
  if (KIPM_BMSMaxConChrgCurnt_A_ovrdflg) {
    /* MinMax: '<S306>/MinMax' incorporates:
     *  Constant: '<S335>/sat4'
     *  MinMax: '<S344>/MinMax'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSMaxConChrgCurnt_A_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
             ->VIPM_BMSMsgActv_flg) {
    /* MinMax: '<S306>/MinMax' incorporates:
     *  Constant: '<S341>/Constant'
     *  Inport: '<Root>/BMS_6_DischrgRecup_EPT'
     *  MinMax: '<S344>/MinMax'
     *  Product: '<S341>/Product'
     *  Switch: '<S335>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = (float32)
      (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_6_DischrgRecup_EPT_BMS_6_DischrgRecup_EPT
       ())->BMS_PwrRecupMaxConChrgCurnt * 0.1F;
  } else {
    /* MinMax: '<S306>/MinMax' incorporates:
     *  Constant: '<S335>/sat5'
     *  MinMax: '<S344>/MinMax'
     *  Switch: '<S335>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSMaxConChrgCurntDflt_A;
  }

  /* End of Switch: '<S335>/Switch4' */

  /* MinMax: '<S335>/MinMax' incorporates:
   *  Constant: '<S335>/sat6'
   */
  if (VIPM_BMSCellVoltMin_mV > KIPM_BMSMaxConChrgCurntHi_A) {
    /* MinMax: '<S306>/MinMax' */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSMaxConChrgCurntHi_A;
  }

  /* End of MinMax: '<S335>/MinMax' */

  /* MinMax: '<S335>/MinMax1' incorporates:
   *  Constant: '<S335>/sat7'
   */
  if (VIPM_BMSCellVoltMin_mV >= KIPM_BMSMaxConChrgCurntLo_A) {
    /* MinMax: '<S335>/MinMax1' */
    VIPM_BMSMaxConChrgCurnt_A = VIPM_BMSCellVoltMin_mV;
  } else {
    /* MinMax: '<S335>/MinMax1' */
    VIPM_BMSMaxConChrgCurnt_A = KIPM_BMSMaxConChrgCurntLo_A;
  }

  /* End of MinMax: '<S335>/MinMax1' */
  /* End of Outputs for SubSystem: '<S302>/Subsys_VIPM_BMSMaxConChrgCurnt_A' */

  /* Outputs for Atomic SubSystem: '<S302>/Subsys_VIPM_BMSMaxInsChrgCurnt_A' */
  /* Logic: '<S337>/Logical Operator3' incorporates:
   *  Constant: '<S337>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSMaxInsChrgCurntVld_flg = (KIPM_BMSMaxInsChrgCurnt_A_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S337>/Switch4' incorporates:
   *  Constant: '<S337>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S337>/Switch'
   */
  if (KIPM_BMSMaxInsChrgCurnt_A_ovrdflg) {
    /* MinMax: '<S306>/MinMax' incorporates:
     *  Constant: '<S337>/sat4'
     *  MinMax: '<S344>/MinMax'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSMaxInsChrgCurnt_A_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
             ->VIPM_BMSMsgActv_flg) {
    /* MinMax: '<S306>/MinMax' incorporates:
     *  Constant: '<S342>/Constant'
     *  Inport: '<Root>/BMS_6_DischrgRecup_EPT'
     *  MinMax: '<S344>/MinMax'
     *  Product: '<S342>/Product'
     *  Switch: '<S337>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = (float32)
      (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_6_DischrgRecup_EPT_BMS_6_DischrgRecup_EPT
       ())->BMS_PwrRecupMaxInstanChrgCurnt * 0.1F;
  } else {
    /* MinMax: '<S306>/MinMax' incorporates:
     *  Constant: '<S337>/sat5'
     *  MinMax: '<S344>/MinMax'
     *  Switch: '<S337>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSMaxInsChrgCurntDflt_A;
  }

  /* End of Switch: '<S337>/Switch4' */

  /* MinMax: '<S337>/MinMax' incorporates:
   *  Constant: '<S337>/sat6'
   */
  if (VIPM_BMSCellVoltMin_mV > KIPM_BMSMaxInsChrgCurntHi_A) {
    /* MinMax: '<S306>/MinMax' */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSMaxInsChrgCurntHi_A;
  }

  /* End of MinMax: '<S337>/MinMax' */

  /* MinMax: '<S337>/MinMax1' incorporates:
   *  Constant: '<S337>/sat7'
   */
  if (VIPM_BMSCellVoltMin_mV >= KIPM_BMSMaxInsChrgCurntLo_A) {
    /* MinMax: '<S337>/MinMax1' */
    VIPM_BMSMaxInsChrgCurnt_A = VIPM_BMSCellVoltMin_mV;
  } else {
    /* MinMax: '<S337>/MinMax1' */
    VIPM_BMSMaxInsChrgCurnt_A = KIPM_BMSMaxInsChrgCurntLo_A;
  }

  /* End of MinMax: '<S337>/MinMax1' */
  /* End of Outputs for SubSystem: '<S302>/Subsys_VIPM_BMSMaxInsChrgCurnt_A' */

  /* BusCreator: '<S302>/BusCreator' incorporates:
   *  Logic: '<S335>/Logical Operator3'
   *  Logic: '<S336>/Logical Operator3'
   *  Logic: '<S337>/Logical Operator3'
   *  Logic: '<S338>/Logical Operator3'
   *  MinMax: '<S335>/MinMax1'
   *  MinMax: '<S336>/MinMax1'
   *  MinMax: '<S337>/MinMax1'
   *  MinMax: '<S338>/MinMax1'
   */
  AppSwcIpm_ARID_DEF.IPM_BMS_6_DischrgRecup_EPT.VIPM_BMSMaxConDisCurnt_A =
    VIPM_BMSMaxConDisCurnt_A;
  AppSwcIpm_ARID_DEF.IPM_BMS_6_DischrgRecup_EPT.VIPM_BMSMaxConDisCurntVld_flg =
    VIPM_BMSMaxConDisCurntVld_flg;
  AppSwcIpm_ARID_DEF.IPM_BMS_6_DischrgRecup_EPT.VIPM_BMSMaxInsDisCurnt_A =
    VIPM_BMSMaxInsDisCurnt_A;
  AppSwcIpm_ARID_DEF.IPM_BMS_6_DischrgRecup_EPT.VIPM_BMSMaxInsDisCurntVld_flg =
    VIPM_BMSMaxInsDisCurntVld_flg;
  AppSwcIpm_ARID_DEF.IPM_BMS_6_DischrgRecup_EPT.VIPM_BMSMaxConChrgCurnt_A =
    VIPM_BMSMaxConChrgCurnt_A;
  AppSwcIpm_ARID_DEF.IPM_BMS_6_DischrgRecup_EPT.VIPM_BMSMaxConChrgCurntVld_flg =
    VIPM_BMSMaxConChrgCurntVld_flg;
  AppSwcIpm_ARID_DEF.IPM_BMS_6_DischrgRecup_EPT.VIPM_BMSMaxInsChrgCurnt_A =
    VIPM_BMSMaxInsChrgCurnt_A;
  AppSwcIpm_ARID_DEF.IPM_BMS_6_DischrgRecup_EPT.VIPM_BMSMaxInsChrgCurntVld_flg =
    VIPM_BMSMaxInsChrgCurntVld_flg;

  /* Outputs for Atomic SubSystem: '<S303>/Subsys_VIPM_BMSCellVoltMax_mV' */
  /* Logic: '<S343>/Logical Operator3' incorporates:
   *  Constant: '<S343>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSCellVoltMaxVld_flg = (KIPM_BMSCellVoltMax_mV_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S343>/Switch4' incorporates:
   *  Constant: '<S343>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S343>/Switch'
   */
  if (KIPM_BMSCellVoltMax_mV_ovrdflg) {
    /* MinMax: '<S306>/MinMax' incorporates:
     *  Constant: '<S343>/sat4'
     *  MinMax: '<S344>/MinMax'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSCellVoltMax_mV_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
             ->VIPM_BMSMsgActv_flg) {
    /* MinMax: '<S306>/MinMax' incorporates:
     *  DataTypeConversion: '<S343>/Data Type Conversion2'
     *  Inport: '<Root>/BMS_7_CellVolt_EPT'
     *  MinMax: '<S344>/MinMax'
     *  Switch: '<S343>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = (float32)
      (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_7_CellVolt_EPT_BMS_7_CellVolt_EPT())
      ->BMS_CellVolMax;
  } else {
    /* MinMax: '<S306>/MinMax' incorporates:
     *  Constant: '<S343>/sat5'
     *  MinMax: '<S344>/MinMax'
     *  Switch: '<S343>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSCellVoltMaxDflt_mV;
  }

  /* End of Switch: '<S343>/Switch4' */

  /* MinMax: '<S343>/MinMax' incorporates:
   *  Constant: '<S343>/sat6'
   */
  if (VIPM_BMSCellVoltMin_mV > KIPM_BMSCellVoltMaxHi_mV) {
    /* MinMax: '<S306>/MinMax' */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSCellVoltMaxHi_mV;
  }

  /* End of MinMax: '<S343>/MinMax' */

  /* MinMax: '<S343>/MinMax1' incorporates:
   *  Constant: '<S343>/sat7'
   */
  if (VIPM_BMSCellVoltMin_mV >= KIPM_BMSCellVoltMaxLo_mV) {
    /* MinMax: '<S343>/MinMax1' */
    VIPM_BMSCellVoltMax_mV = VIPM_BMSCellVoltMin_mV;
  } else {
    /* MinMax: '<S343>/MinMax1' */
    VIPM_BMSCellVoltMax_mV = KIPM_BMSCellVoltMaxLo_mV;
  }

  /* End of MinMax: '<S343>/MinMax1' */
  /* End of Outputs for SubSystem: '<S303>/Subsys_VIPM_BMSCellVoltMax_mV' */

  /* Outputs for Atomic SubSystem: '<S303>/Subsys_VIPM_BMSCellVoltMin_mV' */
  /* Logic: '<S344>/Logical Operator3' incorporates:
   *  Constant: '<S344>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSCellVoltMinVld_flg = (KIPM_BMSCellVoltMin_mV_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S344>/Switch4' incorporates:
   *  Constant: '<S344>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S344>/Switch'
   */
  if (KIPM_BMSCellVoltMin_mV_ovrdflg) {
    /* MinMax: '<S306>/MinMax' incorporates:
     *  Constant: '<S344>/sat4'
     *  MinMax: '<S344>/MinMax'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSCellVoltMin_mV_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
             ->VIPM_BMSMsgActv_flg) {
    /* MinMax: '<S306>/MinMax' incorporates:
     *  DataTypeConversion: '<S344>/Data Type Conversion2'
     *  Inport: '<Root>/BMS_7_CellVolt_EPT'
     *  MinMax: '<S344>/MinMax'
     *  Switch: '<S344>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = (float32)
      (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_7_CellVolt_EPT_BMS_7_CellVolt_EPT())
      ->BMS_CellVolMin;
  } else {
    /* MinMax: '<S306>/MinMax' incorporates:
     *  Constant: '<S344>/sat5'
     *  MinMax: '<S344>/MinMax'
     *  Switch: '<S344>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSCellVoltMinDflt_mV;
  }

  /* End of Switch: '<S344>/Switch4' */

  /* MinMax: '<S344>/MinMax' incorporates:
   *  Constant: '<S344>/sat6'
   */
  if (VIPM_BMSCellVoltMin_mV > KIPM_BMSCellVoltMinHi_mV) {
    /* MinMax: '<S306>/MinMax' */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSCellVoltMinHi_mV;
  }

  /* End of MinMax: '<S344>/MinMax' */

  /* MinMax: '<S344>/MinMax1' incorporates:
   *  Constant: '<S344>/sat7'
   */
  if (VIPM_BMSCellVoltMin_mV < KIPM_BMSCellVoltMinLo_mV) {
    /* MinMax: '<S306>/MinMax' incorporates:
     *  MinMax: '<S344>/MinMax1'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSCellVoltMinLo_mV;
  }

  /* End of MinMax: '<S344>/MinMax1' */
  /* End of Outputs for SubSystem: '<S303>/Subsys_VIPM_BMSCellVoltMin_mV' */

  /* BusCreator: '<S303>/BusCreator' incorporates:
   *  Logic: '<S343>/Logical Operator3'
   *  Logic: '<S344>/Logical Operator3'
   *  MinMax: '<S343>/MinMax1'
   *  MinMax: '<S344>/MinMax1'
   */
  AppSwcIpm_ARID_DEF.IPM_BMS_7_CellVolt_EPT.VIPM_BMSCellVoltMax_mV =
    VIPM_BMSCellVoltMax_mV;
  AppSwcIpm_ARID_DEF.IPM_BMS_7_CellVolt_EPT.VIPM_BMSCellVoltMaxVld_flg =
    VIPM_BMSCellVoltMaxVld_flg;
  AppSwcIpm_ARID_DEF.IPM_BMS_7_CellVolt_EPT.VIPM_BMSCellVoltMin_mV =
    VIPM_BMSCellVoltMin_mV;
  AppSwcIpm_ARID_DEF.IPM_BMS_7_CellVolt_EPT.VIPM_BMSCellVoltMinVld_flg =
    VIPM_BMSCellVoltMinVld_flg;
}

/* Output and update for function-call system: '<Root>/Ipm50ms' */
static void Runbl_Ipm50ms(void)
{
  boolean rtb_LogicalOperator2_lt;

  /* Outputs for Atomic SubSystem: '<S347>/Subsys_VIPM_CCPTempAddKey_flg' */
  /* Logic: '<S368>/Logical Operator3' incorporates:
   *  Constant: '<S368>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CCPTempAddKeyVld_flg = (KIPM_CCPTempAddKey_flg_ovrdflg ||
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
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nz =
        (Rte_IRead_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD())
        ->CCP_TempAddKey;
    }

    /* End of Switch: '<S368>/Switch3' */
  } else {
    /* Switch: '<S368>/Switch' incorporates:
     *  Constant: '<S368>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nz = KIPM_CCPTempAddKeyDflt_flg;
  }

  /* End of Switch: '<S368>/Switch' */

  /* Switch: '<S368>/Switch4' incorporates:
   *  Constant: '<S368>/sat3'
   */
  if (KIPM_CCPTempAddKey_flg_ovrdflg) {
    /* Switch: '<S368>/Switch4' incorporates:
     *  Constant: '<S368>/sat4'
     */
    VIPM_CCPTempAddKey_flg = KIPM_CCPTempAddKey_flg_ovrdval;
  } else {
    /* Switch: '<S368>/Switch4' */
    VIPM_CCPTempAddKey_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nz;
  }

  /* End of Switch: '<S368>/Switch4' */
  /* End of Outputs for SubSystem: '<S347>/Subsys_VIPM_CCPTempAddKey_flg' */

  /* Outputs for Atomic SubSystem: '<S347>/Subsys_VIPM_CCPTempDecKey_flg' */
  /* Logic: '<S369>/Logical Operator3' incorporates:
   *  Constant: '<S369>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CCPTempDecKeyVld_flg = (KIPM_CCPTempDecKey_flg_ovrdflg ||
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
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_i5p =
        (Rte_IRead_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD())
        ->CCP_TempDecreaseKey;
    }

    /* End of Switch: '<S369>/Switch3' */
  } else {
    /* Switch: '<S369>/Switch' incorporates:
     *  Constant: '<S369>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_i5p = KIPM_CCPTempDecKeyDflt_flg;
  }

  /* End of Switch: '<S369>/Switch' */

  /* Switch: '<S369>/Switch4' incorporates:
   *  Constant: '<S369>/sat3'
   */
  if (KIPM_CCPTempDecKey_flg_ovrdflg) {
    /* Switch: '<S369>/Switch4' incorporates:
     *  Constant: '<S369>/sat4'
     */
    VIPM_CCPTempDecKey_flg = KIPM_CCPTempDecKey_flg_ovrdval;
  } else {
    /* Switch: '<S369>/Switch4' */
    VIPM_CCPTempDecKey_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_i5p;
  }

  /* End of Switch: '<S369>/Switch4' */
  /* End of Outputs for SubSystem: '<S347>/Subsys_VIPM_CCPTempDecKey_flg' */

  /* Outputs for Atomic SubSystem: '<S347>/Subsys_VIPM_CCPBlwrLvlAddKey_flg' */
  /* Logic: '<S357>/Logical Operator3' incorporates:
   *  Constant: '<S357>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CCPBlwrLvlAddKeyVld_flg = (KIPM_CCPBlwrLvlAddKey_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())->VIPM_CCPMsgActv_flg);

  /* Switch: '<S357>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
      ->VIPM_CCPMsgActv_flg) {
    /* Switch: '<S357>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_50ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_CCP_PanelStatus_CRCFlt_flg) {
      /* Switch: '<S357>/Switch' incorporates:
       *  Inport: '<Root>/CCP_PanelStatus_BOD'
       *  Switch: '<S357>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ah2 =
        (Rte_IRead_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD())
        ->CCP_BlowerLevelAddKey;
    }

    /* End of Switch: '<S357>/Switch3' */
  } else {
    /* Switch: '<S357>/Switch' incorporates:
     *  Constant: '<S357>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ah2 = KIPM_CCPBlwrLvlAddKeyDflt_flg;
  }

  /* End of Switch: '<S357>/Switch' */

  /* Switch: '<S357>/Switch4' incorporates:
   *  Constant: '<S357>/sat3'
   */
  if (KIPM_CCPBlwrLvlAddKey_flg_ovrdflg) {
    /* Switch: '<S357>/Switch4' incorporates:
     *  Constant: '<S357>/sat4'
     */
    VIPM_CCPBlwrLvlAddKey_flg = KIPM_CCPBlwrLvlAddKey_flg_ovrdval;
  } else {
    /* Switch: '<S357>/Switch4' */
    VIPM_CCPBlwrLvlAddKey_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ah2;
  }

  /* End of Switch: '<S357>/Switch4' */
  /* End of Outputs for SubSystem: '<S347>/Subsys_VIPM_CCPBlwrLvlAddKey_flg' */

  /* Outputs for Atomic SubSystem: '<S347>/Subsys_VIPM_CCPBlwrLvlDecKey_flg' */
  /* Logic: '<S358>/Logical Operator3' incorporates:
   *  Constant: '<S358>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CCPBlwrLvlDecKeyVld_flg = (KIPM_CCPBlwrLvlDecKey_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())->VIPM_CCPMsgActv_flg);

  /* Switch: '<S358>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
      ->VIPM_CCPMsgActv_flg) {
    /* Switch: '<S358>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_50ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_CCP_PanelStatus_CRCFlt_flg) {
      /* Switch: '<S358>/Switch' incorporates:
       *  Inport: '<Root>/CCP_PanelStatus_BOD'
       *  Switch: '<S358>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ei =
        (Rte_IRead_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD())
        ->CCP_BlowerLvlDecreaseKey;
    }

    /* End of Switch: '<S358>/Switch3' */
  } else {
    /* Switch: '<S358>/Switch' incorporates:
     *  Constant: '<S358>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ei = KIPM_CCPBlwrLvlDecKeyDflt_flg;
  }

  /* End of Switch: '<S358>/Switch' */

  /* Switch: '<S358>/Switch4' incorporates:
   *  Constant: '<S358>/sat3'
   */
  if (KIPM_CCPBlwrLvlDecKey_flg_ovrdflg) {
    /* Switch: '<S358>/Switch4' incorporates:
     *  Constant: '<S358>/sat4'
     */
    VIPM_CCPBlwrLvlDecKey_flg = KIPM_CCPBlwrLvlDecKey_flg_ovrdval;
  } else {
    /* Switch: '<S358>/Switch4' */
    VIPM_CCPBlwrLvlDecKey_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ei;
  }

  /* End of Switch: '<S358>/Switch4' */
  /* End of Outputs for SubSystem: '<S347>/Subsys_VIPM_CCPBlwrLvlDecKey_flg' */

  /* Outputs for Atomic SubSystem: '<S347>/Subsys_VIPM_CCPBlwngModeNextKey_flg' */
  /* Logic: '<S355>/Logical Operator3' incorporates:
   *  Constant: '<S355>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CCPBlwngModeNextKeyVld_flg = (KIPM_CCPBlwngModeNextKey_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())->VIPM_CCPMsgActv_flg);

  /* Switch: '<S355>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
      ->VIPM_CCPMsgActv_flg) {
    /* Switch: '<S355>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_50ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_CCP_PanelStatus_CRCFlt_flg) {
      /* Switch: '<S355>/Switch' incorporates:
       *  Inport: '<Root>/CCP_PanelStatus_BOD'
       *  Switch: '<S355>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_bd =
        (Rte_IRead_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD())
        ->CCP_BlowingModeNextKey;
    }

    /* End of Switch: '<S355>/Switch3' */
  } else {
    /* Switch: '<S355>/Switch' incorporates:
     *  Constant: '<S355>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_bd = KIPM_CCPBlwngModeNextKeyDflt_flg;
  }

  /* End of Switch: '<S355>/Switch' */

  /* Switch: '<S355>/Switch4' incorporates:
   *  Constant: '<S355>/sat3'
   */
  if (KIPM_CCPBlwngModeNextKey_flg_ovrdflg) {
    /* Switch: '<S355>/Switch4' incorporates:
     *  Constant: '<S355>/sat4'
     */
    VIPM_CCPBlwngModeNextKey_flg = KIPM_CCPBlwngModeNextKey_flg_ovrdval;
  } else {
    /* Switch: '<S355>/Switch4' */
    VIPM_CCPBlwngModeNextKey_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_bd;
  }

  /* End of Switch: '<S355>/Switch4' */
  /* End of Outputs for SubSystem: '<S347>/Subsys_VIPM_CCPBlwngModeNextKey_flg' */

  /* Outputs for Atomic SubSystem: '<S347>/Subsys_VIPM_CCPBlwngModePrevKey_flg' */
  /* Logic: '<S356>/Logical Operator3' incorporates:
   *  Constant: '<S356>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CCPBlwngModePrevKeyVld_flg = (KIPM_CCPBlwngModePrevKey_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())->VIPM_CCPMsgActv_flg);

  /* Switch: '<S356>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
      ->VIPM_CCPMsgActv_flg) {
    /* Switch: '<S356>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_50ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_CCP_PanelStatus_CRCFlt_flg) {
      /* Switch: '<S356>/Switch' incorporates:
       *  Inport: '<Root>/CCP_PanelStatus_BOD'
       *  Switch: '<S356>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ob =
        (Rte_IRead_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD())
        ->CCP_BlowingModePreviousKey;
    }

    /* End of Switch: '<S356>/Switch3' */
  } else {
    /* Switch: '<S356>/Switch' incorporates:
     *  Constant: '<S356>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ob = KIPM_CCPBlwngModePrevKeyDflt_flg;
  }

  /* End of Switch: '<S356>/Switch' */

  /* Switch: '<S356>/Switch4' incorporates:
   *  Constant: '<S356>/sat3'
   */
  if (KIPM_CCPBlwngModePrevKey_flg_ovrdflg) {
    /* Switch: '<S356>/Switch4' incorporates:
     *  Constant: '<S356>/sat4'
     */
    VIPM_CCPBlwngModePrevKey_flg = KIPM_CCPBlwngModePrevKey_flg_ovrdval;
  } else {
    /* Switch: '<S356>/Switch4' */
    VIPM_CCPBlwngModePrevKey_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ob;
  }

  /* End of Switch: '<S356>/Switch4' */
  /* End of Outputs for SubSystem: '<S347>/Subsys_VIPM_CCPBlwngModePrevKey_flg' */

  /* Outputs for Atomic SubSystem: '<S347>/Subsys_VIPM_CCPACSwKey_flg' */
  /* Logic: '<S351>/Logical Operator3' incorporates:
   *  Constant: '<S351>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CCPACSwKeyVld_flg = (KIPM_CCPACSwKey_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())->VIPM_CCPMsgActv_flg);

  /* Switch: '<S351>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
      ->VIPM_CCPMsgActv_flg) {
    /* Switch: '<S351>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_50ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_CCP_PanelStatus_CRCFlt_flg) {
      /* Switch: '<S351>/Switch' incorporates:
       *  Inport: '<Root>/CCP_PanelStatus_BOD'
       *  Switch: '<S351>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pz =
        (Rte_IRead_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD())
        ->CCP_ACSwitchKey;
    }

    /* End of Switch: '<S351>/Switch3' */
  } else {
    /* Switch: '<S351>/Switch' incorporates:
     *  Constant: '<S351>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pz = KIPM_CCPACSwKeyDflt_flg;
  }

  /* End of Switch: '<S351>/Switch' */

  /* Switch: '<S351>/Switch4' incorporates:
   *  Constant: '<S351>/sat3'
   */
  if (KIPM_CCPACSwKey_flg_ovrdflg) {
    /* Switch: '<S351>/Switch4' incorporates:
     *  Constant: '<S351>/sat4'
     */
    VIPM_CCPACSwKey_flg = KIPM_CCPACSwKey_flg_ovrdval;
  } else {
    /* Switch: '<S351>/Switch4' */
    VIPM_CCPACSwKey_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pz;
  }

  /* End of Switch: '<S351>/Switch4' */
  /* End of Outputs for SubSystem: '<S347>/Subsys_VIPM_CCPACSwKey_flg' */

  /* Outputs for Atomic SubSystem: '<S347>/Subsys_VIPM_CCPACAutoKey_flg' */
  /* Logic: '<S350>/Logical Operator3' incorporates:
   *  Constant: '<S350>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CCPACAutoKeyVld_flg = (KIPM_CCPACAutoKey_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())->VIPM_CCPMsgActv_flg);

  /* Switch: '<S350>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
      ->VIPM_CCPMsgActv_flg) {
    /* Switch: '<S350>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_50ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_CCP_PanelStatus_CRCFlt_flg) {
      /* Switch: '<S350>/Switch' incorporates:
       *  Inport: '<Root>/CCP_PanelStatus_BOD'
       *  Switch: '<S350>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cr =
        (Rte_IRead_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD())
        ->CCP_ACAutoKey;
    }

    /* End of Switch: '<S350>/Switch3' */
  } else {
    /* Switch: '<S350>/Switch' incorporates:
     *  Constant: '<S350>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cr = KIPM_CCPACAutoKeyDflt_flg;
  }

  /* End of Switch: '<S350>/Switch' */

  /* Switch: '<S350>/Switch4' incorporates:
   *  Constant: '<S350>/sat3'
   */
  if (KIPM_CCPACAutoKey_flg_ovrdflg) {
    /* Switch: '<S350>/Switch4' incorporates:
     *  Constant: '<S350>/sat4'
     */
    VIPM_CCPACAutoKey_flg = KIPM_CCPACAutoKey_flg_ovrdval;
  } else {
    /* Switch: '<S350>/Switch4' */
    VIPM_CCPACAutoKey_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cr;
  }

  /* End of Switch: '<S350>/Switch4' */
  /* End of Outputs for SubSystem: '<S347>/Subsys_VIPM_CCPACAutoKey_flg' */

  /* Outputs for Atomic SubSystem: '<S347>/Subsys_VIPM_CCPRrViewMirrHeatgKey_flg' */
  /* Logic: '<S366>/Logical Operator3' incorporates:
   *  Constant: '<S366>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CCPRrViewMirrHeatgKeyVld_flg = (KIPM_CCPRrViewMirrHeatgKey_flg_ovrdflg ||
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
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_dp =
        (Rte_IRead_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD())
        ->CCP_RearViewMirrHeatingKey;
    }

    /* End of Switch: '<S366>/Switch3' */
  } else {
    /* Switch: '<S366>/Switch' incorporates:
     *  Constant: '<S366>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_dp = KIPM_CCPRrViewMirrHeatgKeyDflt_flg;
  }

  /* End of Switch: '<S366>/Switch' */

  /* Switch: '<S366>/Switch4' incorporates:
   *  Constant: '<S366>/sat3'
   */
  if (KIPM_CCPRrViewMirrHeatgKey_flg_ovrdflg) {
    /* Switch: '<S366>/Switch4' incorporates:
     *  Constant: '<S366>/sat4'
     */
    VIPM_CCPRrViewMirrHeatgKey_flg = KIPM_CCPRrViewMirrHeatgKey_flg_ovrdval;
  } else {
    /* Switch: '<S366>/Switch4' */
    VIPM_CCPRrViewMirrHeatgKey_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_dp;
  }

  /* End of Switch: '<S366>/Switch4' */
  /* End of Outputs for SubSystem: '<S347>/Subsys_VIPM_CCPRrViewMirrHeatgKey_flg' */

  /* Outputs for Atomic SubSystem: '<S347>/Subsys_VIPM_CCPAirInletModeKey_flg' */
  /* Logic: '<S354>/Logical Operator3' incorporates:
   *  Constant: '<S354>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CCPAirInletModeKeyVld_flg = (KIPM_CCPAirInletModeKey_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())->VIPM_CCPMsgActv_flg);

  /* Switch: '<S354>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
      ->VIPM_CCPMsgActv_flg) {
    /* Switch: '<S354>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_50ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_CCP_PanelStatus_CRCFlt_flg) {
      /* Switch: '<S354>/Switch' incorporates:
       *  Inport: '<Root>/CCP_PanelStatus_BOD'
       *  Switch: '<S354>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_go =
        (Rte_IRead_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD())
        ->CCP_AirInletModeKey;
    }

    /* End of Switch: '<S354>/Switch3' */
  } else {
    /* Switch: '<S354>/Switch' incorporates:
     *  Constant: '<S354>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_go = KIPM_CCPAirInletModeKeyDflt_flg;
  }

  /* End of Switch: '<S354>/Switch' */

  /* Switch: '<S354>/Switch4' incorporates:
   *  Constant: '<S354>/sat3'
   */
  if (KIPM_CCPAirInletModeKey_flg_ovrdflg) {
    /* Switch: '<S354>/Switch4' incorporates:
     *  Constant: '<S354>/sat4'
     */
    VIPM_CCPAirInletModeKey_flg = KIPM_CCPAirInletModeKey_flg_ovrdval;
  } else {
    /* Switch: '<S354>/Switch4' */
    VIPM_CCPAirInletModeKey_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_go;
  }

  /* End of Switch: '<S354>/Switch4' */
  /* End of Outputs for SubSystem: '<S347>/Subsys_VIPM_CCPAirInletModeKey_flg' */

  /* Outputs for Atomic SubSystem: '<S347>/Subsys_VIPM_CCPFrntWindDefrstKey_flg' */
  /* Logic: '<S361>/Logical Operator3' incorporates:
   *  Constant: '<S361>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CCPFrntWindDefrstKeyVld_flg = (KIPM_CCPFrntWindDefrstKey_flg_ovrdflg ||
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
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ab =
        (Rte_IRead_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD())
        ->CCP_FrontWindDefrostKey;
    }

    /* End of Switch: '<S361>/Switch3' */
  } else {
    /* Switch: '<S361>/Switch' incorporates:
     *  Constant: '<S361>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ab = KIPM_CCPFrntWindDefrstKeyDflt_flg;
  }

  /* End of Switch: '<S361>/Switch' */

  /* Switch: '<S361>/Switch4' incorporates:
   *  Constant: '<S361>/sat3'
   */
  if (KIPM_CCPFrntWindDefrstKey_flg_ovrdflg) {
    /* Switch: '<S361>/Switch4' incorporates:
     *  Constant: '<S361>/sat4'
     */
    VIPM_CCPFrntWindDefrstKey_flg = KIPM_CCPFrntWindDefrstKey_flg_ovrdval;
  } else {
    /* Switch: '<S361>/Switch4' */
    VIPM_CCPFrntWindDefrstKey_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ab;
  }

  /* End of Switch: '<S361>/Switch4' */
  /* End of Outputs for SubSystem: '<S347>/Subsys_VIPM_CCPFrntWindDefrstKey_flg' */

  /* Outputs for Atomic SubSystem: '<S347>/Subsys_VIPM_CCPModeKey_flg' */
  /* Logic: '<S364>/Logical Operator3' incorporates:
   *  Constant: '<S364>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CCPModeKeyVld_flg = (KIPM_CCPModeKey_flg_ovrdflg ||
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
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_p1 =
        (Rte_IRead_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD())
        ->CCP_ModeKey;
    }

    /* End of Switch: '<S364>/Switch3' */
  } else {
    /* Switch: '<S364>/Switch' incorporates:
     *  Constant: '<S364>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_p1 = KIPM_CCPModeKeyDflt_flg;
  }

  /* End of Switch: '<S364>/Switch' */

  /* Switch: '<S364>/Switch4' incorporates:
   *  Constant: '<S364>/sat3'
   */
  if (KIPM_CCPModeKey_flg_ovrdflg) {
    /* Switch: '<S364>/Switch4' incorporates:
     *  Constant: '<S364>/sat4'
     */
    VIPM_CCPModeKey_flg = KIPM_CCPModeKey_flg_ovrdval;
  } else {
    /* Switch: '<S364>/Switch4' */
    VIPM_CCPModeKey_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_p1;
  }

  /* End of Switch: '<S364>/Switch4' */
  /* End of Outputs for SubSystem: '<S347>/Subsys_VIPM_CCPModeKey_flg' */

  /* Outputs for Atomic SubSystem: '<S347>/Subsys_VIPM_CCPHzrdKey_flg' */
  /* Logic: '<S363>/Logical Operator3' incorporates:
   *  Constant: '<S363>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CCPHzrdKeyVld_flg = (KIPM_CCPHzrdKey_flg_ovrdflg ||
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
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_it =
        (Rte_IRead_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD())
        ->CCP_HazardKey;
    }

    /* End of Switch: '<S363>/Switch3' */
  } else {
    /* Switch: '<S363>/Switch' incorporates:
     *  Constant: '<S363>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_it = KIPM_CCPHzrdKeyDflt_flg;
  }

  /* End of Switch: '<S363>/Switch' */

  /* Switch: '<S363>/Switch4' incorporates:
   *  Constant: '<S363>/sat3'
   */
  if (KIPM_CCPHzrdKey_flg_ovrdflg) {
    /* Switch: '<S363>/Switch4' incorporates:
     *  Constant: '<S363>/sat4'
     */
    VIPM_CCPHzrdKey_flg = KIPM_CCPHzrdKey_flg_ovrdval;
  } else {
    /* Switch: '<S363>/Switch4' */
    VIPM_CCPHzrdKey_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_it;
  }

  /* End of Switch: '<S363>/Switch4' */
  /* End of Outputs for SubSystem: '<S347>/Subsys_VIPM_CCPHzrdKey_flg' */

  /* Outputs for Atomic SubSystem: '<S347>/Subsys_VIPM_CCPCenLckKey_flg' */
  /* Logic: '<S359>/Logical Operator3' incorporates:
   *  Constant: '<S359>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CCPCenLckKeyVld_flg = (KIPM_CCPCenLckKey_flg_ovrdflg ||
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
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_eo =
        (Rte_IRead_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD())
        ->CCP_CentralLockKey;
    }

    /* End of Switch: '<S359>/Switch3' */
  } else {
    /* Switch: '<S359>/Switch' incorporates:
     *  Constant: '<S359>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_eo = KIPM_CCPCenLckKeyDflt_flg;
  }

  /* End of Switch: '<S359>/Switch' */

  /* Switch: '<S359>/Switch4' incorporates:
   *  Constant: '<S359>/sat3'
   */
  if (KIPM_CCPCenLckKey_flg_ovrdflg) {
    /* Switch: '<S359>/Switch4' incorporates:
     *  Constant: '<S359>/sat4'
     */
    VIPM_CCPCenLckKey_flg = KIPM_CCPCenLckKey_flg_ovrdval;
  } else {
    /* Switch: '<S359>/Switch4' */
    VIPM_CCPCenLckKey_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_eo;
  }

  /* End of Switch: '<S359>/Switch4' */
  /* End of Outputs for SubSystem: '<S347>/Subsys_VIPM_CCPCenLckKey_flg' */

  /* Outputs for Atomic SubSystem: '<S347>/Subsys_VIPM_CCPTPMSKey_flg' */
  /* Logic: '<S367>/Logical Operator3' incorporates:
   *  Constant: '<S367>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CCPTPMSKeyVld_flg = (KIPM_CCPTPMSKey_flg_ovrdflg ||
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
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_e1e =
        (Rte_IRead_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD())
        ->CCP_TPMSKey;
    }

    /* End of Switch: '<S367>/Switch3' */
  } else {
    /* Switch: '<S367>/Switch' incorporates:
     *  Constant: '<S367>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_e1e = KIPM_CCPTPMSKeyDflt_flg;
  }

  /* End of Switch: '<S367>/Switch' */

  /* Switch: '<S367>/Switch4' incorporates:
   *  Constant: '<S367>/sat3'
   */
  if (KIPM_CCPTPMSKey_flg_ovrdflg) {
    /* Switch: '<S367>/Switch4' incorporates:
     *  Constant: '<S367>/sat4'
     */
    VIPM_CCPTPMSKey_flg = KIPM_CCPTPMSKey_flg_ovrdval;
  } else {
    /* Switch: '<S367>/Switch4' */
    VIPM_CCPTPMSKey_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_e1e;
  }

  /* End of Switch: '<S367>/Switch4' */
  /* End of Outputs for SubSystem: '<S347>/Subsys_VIPM_CCPTPMSKey_flg' */

  /* Outputs for Atomic SubSystem: '<S347>/Subsys_VIPM_CCPESCOffKey_flg' */
  /* Logic: '<S360>/Logical Operator3' incorporates:
   *  Constant: '<S360>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CCPESCOffKeyVld_flg = (KIPM_CCPESCOffKey_flg_ovrdflg ||
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
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_phn =
        (Rte_IRead_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD())
        ->CCP_ESCOFFKey;
    }

    /* End of Switch: '<S360>/Switch3' */
  } else {
    /* Switch: '<S360>/Switch' incorporates:
     *  Constant: '<S360>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_phn = KIPM_CCPESCOffKeyDflt_flg;
  }

  /* End of Switch: '<S360>/Switch' */

  /* Switch: '<S360>/Switch4' incorporates:
   *  Constant: '<S360>/sat3'
   */
  if (KIPM_CCPESCOffKey_flg_ovrdflg) {
    /* Switch: '<S360>/Switch4' incorporates:
     *  Constant: '<S360>/sat4'
     */
    VIPM_CCPESCOffKey_flg = KIPM_CCPESCOffKey_flg_ovrdval;
  } else {
    /* Switch: '<S360>/Switch4' */
    VIPM_CCPESCOffKey_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_phn;
  }

  /* End of Switch: '<S360>/Switch4' */
  /* End of Outputs for SubSystem: '<S347>/Subsys_VIPM_CCPESCOffKey_flg' */

  /* Outputs for Atomic SubSystem: '<S347>/Subsys_VIPM_CCPAVASOffKey_flg' */
  /* Logic: '<S352>/Logical Operator3' incorporates:
   *  Constant: '<S352>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CCPAVASOffKeyVld_flg = (KIPM_CCPAVASOffKey_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())->VIPM_CCPMsgActv_flg);

  /* Switch: '<S352>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
      ->VIPM_CCPMsgActv_flg) {
    /* Switch: '<S352>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_50ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_CCP_PanelStatus_CRCFlt_flg) {
      /* Switch: '<S352>/Switch' incorporates:
       *  Inport: '<Root>/CCP_PanelStatus_BOD'
       *  Switch: '<S352>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ky =
        (Rte_IRead_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD())
        ->CCP_AVASOffKey;
    }

    /* End of Switch: '<S352>/Switch3' */
  } else {
    /* Switch: '<S352>/Switch' incorporates:
     *  Constant: '<S352>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ky = KIPM_CCPAVASOffKeyDflt_flg;
  }

  /* End of Switch: '<S352>/Switch' */

  /* Switch: '<S352>/Switch4' incorporates:
   *  Constant: '<S352>/sat3'
   */
  if (KIPM_CCPAVASOffKey_flg_ovrdflg) {
    /* Switch: '<S352>/Switch4' incorporates:
     *  Constant: '<S352>/sat4'
     */
    VIPM_CCPAVASOffKey_flg = KIPM_CCPAVASOffKey_flg_ovrdval;
  } else {
    /* Switch: '<S352>/Switch4' */
    VIPM_CCPAVASOffKey_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ky;
  }

  /* End of Switch: '<S352>/Switch4' */
  /* End of Outputs for SubSystem: '<S347>/Subsys_VIPM_CCPAVASOffKey_flg' */

  /* Outputs for Atomic SubSystem: '<S347>/Subsys_VIPM_CCPHDCKey_flg' */
  /* Logic: '<S362>/Logical Operator3' incorporates:
   *  Constant: '<S362>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CCPHDCKeyVld_flg = (KIPM_CCPHDCKey_flg_ovrdflg ||
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
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_kd =
        (Rte_IRead_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD())
        ->CCP_HDCKey;
    }

    /* End of Switch: '<S362>/Switch3' */
  } else {
    /* Switch: '<S362>/Switch' incorporates:
     *  Constant: '<S362>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_kd = KIPM_CCPHDCKeyDflt_flg;
  }

  /* End of Switch: '<S362>/Switch' */

  /* Switch: '<S362>/Switch4' incorporates:
   *  Constant: '<S362>/sat3'
   */
  if (KIPM_CCPHDCKey_flg_ovrdflg) {
    /* Switch: '<S362>/Switch4' incorporates:
     *  Constant: '<S362>/sat4'
     */
    VIPM_CCPHDCKey_flg = KIPM_CCPHDCKey_flg_ovrdval;
  } else {
    /* Switch: '<S362>/Switch4' */
    VIPM_CCPHDCKey_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_kd;
  }

  /* End of Switch: '<S362>/Switch4' */
  /* End of Outputs for SubSystem: '<S347>/Subsys_VIPM_CCPHDCKey_flg' */

  /* Outputs for Atomic SubSystem: '<S347>/Subsys_VIPM_CCPAVHKey_flg' */
  /* Logic: '<S353>/Logical Operator3' incorporates:
   *  Constant: '<S353>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CCPAVHKeyVld_flg = (KIPM_CCPAVHKey_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())->VIPM_CCPMsgActv_flg);

  /* Switch: '<S353>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
      ->VIPM_CCPMsgActv_flg) {
    /* Switch: '<S353>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_50ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_CCP_PanelStatus_CRCFlt_flg) {
      /* Switch: '<S353>/Switch' incorporates:
       *  Inport: '<Root>/CCP_PanelStatus_BOD'
       *  Switch: '<S353>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jb =
        (Rte_IRead_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD())
        ->CCP_AVHKey;
    }

    /* End of Switch: '<S353>/Switch3' */
  } else {
    /* Switch: '<S353>/Switch' incorporates:
     *  Constant: '<S353>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jb = KIPM_CCPAVHKeyDflt_flg;
  }

  /* End of Switch: '<S353>/Switch' */

  /* Switch: '<S353>/Switch4' incorporates:
   *  Constant: '<S353>/sat3'
   */
  if (KIPM_CCPAVHKey_flg_ovrdflg) {
    /* Switch: '<S353>/Switch4' incorporates:
     *  Constant: '<S353>/sat4'
     */
    VIPM_CCPAVHKey_flg = KIPM_CCPAVHKey_flg_ovrdval;
  } else {
    /* Switch: '<S353>/Switch4' */
    VIPM_CCPAVHKey_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jb;
  }

  /* End of Switch: '<S353>/Switch4' */
  /* End of Outputs for SubSystem: '<S347>/Subsys_VIPM_CCPAVHKey_flg' */

  /* Outputs for Atomic SubSystem: '<S347>/Subsys_VIPM_CCPPwrRecupLvlKey_flg' */
  /* Logic: '<S365>/Logical Operator3' incorporates:
   *  Constant: '<S365>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CCPPwrRecupLvlKeyVld_flg = (KIPM_CCPPwrRecupLvlKey_flg_ovrdflg ||
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
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_b1 =
        (Rte_IRead_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD())
        ->CCP_PwrRecupLevelKey;
    }

    /* End of Switch: '<S365>/Switch3' */
  } else {
    /* Switch: '<S365>/Switch' incorporates:
     *  Constant: '<S365>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_b1 = KIPM_CCPPwrRecupLvlKeyDflt_flg;
  }

  /* End of Switch: '<S365>/Switch' */

  /* Switch: '<S365>/Switch4' incorporates:
   *  Constant: '<S365>/sat3'
   */
  if (KIPM_CCPPwrRecupLvlKey_flg_ovrdflg) {
    /* Switch: '<S365>/Switch4' incorporates:
     *  Constant: '<S365>/sat4'
     */
    VIPM_CCPPwrRecupLvlKey_flg = KIPM_CCPPwrRecupLvlKey_flg_ovrdval;
  } else {
    /* Switch: '<S365>/Switch4' */
    VIPM_CCPPwrRecupLvlKey_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_b1;
  }

  /* End of Switch: '<S365>/Switch4' */
  /* End of Outputs for SubSystem: '<S347>/Subsys_VIPM_CCPPwrRecupLvlKey_flg' */

  /* BusCreator: '<S347>/BusCreator' incorporates:
   *  Logic: '<S350>/Logical Operator3'
   *  Logic: '<S351>/Logical Operator3'
   *  Logic: '<S352>/Logical Operator3'
   *  Logic: '<S353>/Logical Operator3'
   *  Logic: '<S354>/Logical Operator3'
   *  Logic: '<S355>/Logical Operator3'
   *  Logic: '<S356>/Logical Operator3'
   *  Logic: '<S357>/Logical Operator3'
   *  Logic: '<S358>/Logical Operator3'
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
   *  Switch: '<S350>/Switch4'
   *  Switch: '<S351>/Switch4'
   *  Switch: '<S352>/Switch4'
   *  Switch: '<S353>/Switch4'
   *  Switch: '<S354>/Switch4'
   *  Switch: '<S355>/Switch4'
   *  Switch: '<S356>/Switch4'
   *  Switch: '<S357>/Switch4'
   *  Switch: '<S358>/Switch4'
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
   */
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_k.VIPM_CCPTempAddKey_flg =
    VIPM_CCPTempAddKey_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_k.VIPM_CCPTempAddKeyVld_flg =
    VIPM_CCPTempAddKeyVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_k.VIPM_CCPTempDecKey_flg =
    VIPM_CCPTempDecKey_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_k.VIPM_CCPTempDecKeyVld_flg =
    VIPM_CCPTempDecKeyVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_k.VIPM_CCPBlwrLvlAddKey_flg =
    VIPM_CCPBlwrLvlAddKey_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_k.VIPM_CCPBlwrLvlAddKeyVld_flg =
    VIPM_CCPBlwrLvlAddKeyVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_k.VIPM_CCPBlwrLvlDecKey_flg =
    VIPM_CCPBlwrLvlDecKey_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_k.VIPM_CCPBlwrLvlDecKeyVld_flg =
    VIPM_CCPBlwrLvlDecKeyVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_k.VIPM_CCPBlwngModeNextKey_flg =
    VIPM_CCPBlwngModeNextKey_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_k.VIPM_CCPBlwngModeNextKeyVld_flg =
    VIPM_CCPBlwngModeNextKeyVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_k.VIPM_CCPBlwngModePrevKey_flg =
    VIPM_CCPBlwngModePrevKey_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_k.VIPM_CCPBlwngModePrevKeyVld_flg =
    VIPM_CCPBlwngModePrevKeyVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_k.VIPM_CCPACSwKey_flg =
    VIPM_CCPACSwKey_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_k.VIPM_CCPACSwKeyVld_flg =
    VIPM_CCPACSwKeyVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_k.VIPM_CCPACAutoKey_flg =
    VIPM_CCPACAutoKey_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_k.VIPM_CCPACAutoKeyVld_flg =
    VIPM_CCPACAutoKeyVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_k.VIPM_CCPRrViewMirrHeatgKey_flg =
    VIPM_CCPRrViewMirrHeatgKey_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_k.VIPM_CCPRrViewMirrHeatgKeyVld_flg
    = VIPM_CCPRrViewMirrHeatgKeyVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_k.VIPM_CCPAirInletModeKey_flg =
    VIPM_CCPAirInletModeKey_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_k.VIPM_CCPAirInletModeKeyVld_flg =
    VIPM_CCPAirInletModeKeyVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_k.VIPM_CCPFrntWindDefrstKey_flg =
    VIPM_CCPFrntWindDefrstKey_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_k.VIPM_CCPFrntWindDefrstKeyVld_flg =
    VIPM_CCPFrntWindDefrstKeyVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_k.VIPM_CCPModeKey_flg =
    VIPM_CCPModeKey_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_k.VIPM_CCPModeKeyVld_flg =
    VIPM_CCPModeKeyVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_k.VIPM_CCPHzrdKey_flg =
    VIPM_CCPHzrdKey_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_k.VIPM_CCPHzrdKeyVld_flg =
    VIPM_CCPHzrdKeyVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_k.VIPM_CCPCenLckKey_flg =
    VIPM_CCPCenLckKey_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_k.VIPM_CCPCenLckKeyVld_flg =
    VIPM_CCPCenLckKeyVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_k.VIPM_CCPTPMSKey_flg =
    VIPM_CCPTPMSKey_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_k.VIPM_CCPTPMSKeyVld_flg =
    VIPM_CCPTPMSKeyVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_k.VIPM_CCPESCOffKey_flg =
    VIPM_CCPESCOffKey_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_k.VIPM_CCPESCOffKeyVld_flg =
    VIPM_CCPESCOffKeyVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_k.VIPM_CCPAVASOffKey_flg =
    VIPM_CCPAVASOffKey_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_k.VIPM_CCPAVASOffKeyVld_flg =
    VIPM_CCPAVASOffKeyVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_k.VIPM_CCPHDCKey_flg =
    VIPM_CCPHDCKey_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_k.VIPM_CCPHDCKeyVld_flg =
    VIPM_CCPHDCKeyVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_k.VIPM_CCPAVHKey_flg =
    VIPM_CCPAVHKey_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_k.VIPM_CCPAVHKeyVld_flg =
    VIPM_CCPAVHKeyVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_k.VIPM_CCPPwrRecupLvlKey_flg =
    VIPM_CCPPwrRecupLvlKey_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_k.VIPM_CCPPwrRecupLvlKeyVld_flg =
    VIPM_CCPPwrRecupLvlKeyVld_flg;

  /* Outputs for Atomic SubSystem: '<S348>/Subsys_VIPM_ESCLUnOrLockfeedback_nu' */
  /* Logic: '<S370>/Logical Operator3' incorporates:
   *  Constant: '<S370>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_ESCLUnOrLockfeedbackVld_flg = (KIPM_ESCLUnOrLockfeedback_nu_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
    ->VIPM_ESCLMsgActv_flg);

  /* Switch: '<S370>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
      ->VIPM_ESCLMsgActv_flg) {
    /* Switch: '<S370>/Switch' incorporates:
     *  Inport: '<Root>/ESCL_ESCLStatus_BOD'
     *  Switch: '<S370>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE =
      (Rte_IRead_Runbl_IpmCanRx_50ms_ESCL_ESCLStatus_BOD_ESCL_ESCLStatus_BOD()
      )->ESCL_UnOrLock_feedback;
  } else {
    /* Switch: '<S370>/Switch' incorporates:
     *  Constant: '<S370>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE = KIPM_ESCLUnOrLockfeedbackDflt_nu;
  }

  /* End of Switch: '<S370>/Switch' */

  /* Switch: '<S370>/Switch4' incorporates:
   *  Constant: '<S370>/sat3'
   */
  if (KIPM_ESCLUnOrLockfeedback_nu_ovrdflg) {
    /* Switch: '<S370>/Switch4' incorporates:
     *  Constant: '<S370>/sat4'
     */
    VIPM_ESCLUnOrLockfeedback_nu = KIPM_ESCLUnOrLockfeedback_nu_ovrdval;
  } else {
    /* Switch: '<S370>/Switch4' incorporates:
     *  Switch: '<S370>/Switch'
     */
    VIPM_ESCLUnOrLockfeedback_nu = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE;
  }

  /* End of Switch: '<S370>/Switch4' */
  /* End of Outputs for SubSystem: '<S348>/Subsys_VIPM_ESCLUnOrLockfeedback_nu' */

  /* BusCreator: '<S348>/BusCreator' incorporates:
   *  Logic: '<S370>/Logical Operator3'
   *  Switch: '<S370>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_ESCL_ESCLStatus_BOD.VIPM_ESCLUnOrLockfeedback_nu =
    VIPM_ESCLUnOrLockfeedback_nu;
  AppSwcIpm_ARID_DEF.IPM_ESCL_ESCLStatus_BOD.VIPM_ESCLUnOrLockfeedbackVld_flg =
    VIPM_ESCLUnOrLockfeedbackVld_flg;

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VIPM_SCSFrntWshrSwtSt_flg' */
  /* Logic: '<S382>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/SCS_LeSwitchSts_BOD'
   *  Logic: '<S372>/Logical Operator2'
   */
  rtb_LogicalOperator2_lt =
    ((Rte_IRead_Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD())
     ->SCS_FrntWshrSwtStVD &&
     (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
     ->VIPM_SCSMsgActv_flg);

  /* Logic: '<S372>/Logical Operator3' incorporates:
   *  Constant: '<S372>/sat3'
   */
  VIPM_SCSFrntWshrSwtStVld_flg = (KIPM_SCSFrntWshrSwtSt_flg_ovrdflg ||
    rtb_LogicalOperator2_lt);

  /* Switch: '<S372>/Switch' */
  if (rtb_LogicalOperator2_lt) {
    /* Switch: '<S372>/Switch' incorporates:
     *  Inport: '<Root>/SCS_LeSwitchSts_BOD'
     *  Switch: '<S372>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_f1 =
      (Rte_IRead_Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD()
      )->SCS_FrntWshrSwtSt;
  } else {
    /* Switch: '<S372>/Switch' incorporates:
     *  Constant: '<S372>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_f1 = KIPM_SCSFrntWshrSwtStDflt_flg;
  }

  /* End of Switch: '<S372>/Switch' */

  /* Switch: '<S372>/Switch4' incorporates:
   *  Constant: '<S372>/sat3'
   */
  if (KIPM_SCSFrntWshrSwtSt_flg_ovrdflg) {
    /* Switch: '<S372>/Switch4' incorporates:
     *  Constant: '<S372>/sat4'
     */
    VIPM_SCSFrntWshrSwtSt_flg = KIPM_SCSFrntWshrSwtSt_flg_ovrdval;
  } else {
    /* Switch: '<S372>/Switch4' */
    VIPM_SCSFrntWshrSwtSt_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_f1;
  }

  /* End of Switch: '<S372>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VIPM_SCSFrntWshrSwtSt_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VIPM_SCSFrntWiprSwtSt_enum' */
  /* Logic: '<S382>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/SCS_LeSwitchSts_BOD'
   *  Logic: '<S371>/Logical Operator2'
   */
  rtb_LogicalOperator2_lt =
    ((Rte_IRead_Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD())
     ->SCS_WiprSwtStVD && (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
     ->VIPM_SCSMsgActv_flg);

  /* Logic: '<S371>/Logical Operator3' incorporates:
   *  Constant: '<S371>/sat3'
   */
  VIPM_SCSFrntWiprSwtStVld_flg = (KIPM_SCSFrntWiprSwtSt_enum_ovrdflg ||
    rtb_LogicalOperator2_lt);

  /* Switch: '<S371>/Switch' */
  if (rtb_LogicalOperator2_lt) {
    /* Switch: '<S371>/Switch' incorporates:
     *  Inport: '<Root>/SCS_LeSwitchSts_BOD'
     *  Switch: '<S371>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nh =
      (Rte_IRead_Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD()
      )->SCS_FrntWiprSwtSt;
  } else {
    /* Switch: '<S371>/Switch' incorporates:
     *  Constant: '<S371>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nh = KIPM_SCSFrntWiprSwtStDflt_enum;
  }

  /* End of Switch: '<S371>/Switch' */

  /* Switch: '<S371>/Switch4' incorporates:
   *  Constant: '<S371>/sat3'
   */
  if (KIPM_SCSFrntWiprSwtSt_enum_ovrdflg) {
    /* Switch: '<S371>/Switch4' incorporates:
     *  Constant: '<S371>/sat4'
     */
    VIPM_SCSFrntWiprSwtSt_enum = KIPM_SCSFrntWiprSwtSt_enum_ovrdval;
  } else {
    /* Switch: '<S371>/Switch4' */
    VIPM_SCSFrntWiprSwtSt_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nh;
  }

  /* End of Switch: '<S371>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VIPM_SCSFrntWiprSwtSt_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VIPM_SCSPstnLghtSwSt_flg' */
  /* Logic: '<S382>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/SCS_LeSwitchSts_BOD'
   *  Logic: '<S378>/Logical Operator2'
   */
  rtb_LogicalOperator2_lt =
    ((Rte_IRead_Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD())
     ->SCS_KnobBeamSwtStVD &&
     (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
     ->VIPM_SCSMsgActv_flg);

  /* Logic: '<S378>/Logical Operator3' incorporates:
   *  Constant: '<S378>/sat3'
   */
  VIPM_SCSPstnLghtSwStVld_flg = (KIPM_SCSPstnLghtSwSt_flg_ovrdflg ||
    rtb_LogicalOperator2_lt);

  /* Switch: '<S378>/Switch' */
  if (rtb_LogicalOperator2_lt) {
    /* Switch: '<S378>/Switch' incorporates:
     *  Inport: '<Root>/SCS_LeSwitchSts_BOD'
     *  Switch: '<S378>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ko =
      (Rte_IRead_Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD()
      )->SCS_PositionLightswitchSt;
  } else {
    /* Switch: '<S378>/Switch' incorporates:
     *  Constant: '<S378>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ko = KIPM_SCSPstnLghtSwStDflt_flg;
  }

  /* End of Switch: '<S378>/Switch' */

  /* Switch: '<S378>/Switch4' incorporates:
   *  Constant: '<S378>/sat3'
   */
  if (KIPM_SCSPstnLghtSwSt_flg_ovrdflg) {
    /* Switch: '<S378>/Switch4' incorporates:
     *  Constant: '<S378>/sat4'
     */
    VIPM_SCSPstnLghtSwSt_flg = KIPM_SCSPstnLghtSwSt_flg_ovrdval;
  } else {
    /* Switch: '<S378>/Switch4' */
    VIPM_SCSPstnLghtSwSt_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ko;
  }

  /* End of Switch: '<S378>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VIPM_SCSPstnLghtSwSt_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VIPM_SCSLoBeamSwSt_flg' */
  /* Logic: '<S382>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/SCS_LeSwitchSts_BOD'
   *  Logic: '<S376>/Logical Operator2'
   */
  rtb_LogicalOperator2_lt =
    ((Rte_IRead_Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD())
     ->SCS_KnobBeamSwtStVD &&
     (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
     ->VIPM_SCSMsgActv_flg);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Constant: '<S376>/sat3'
   */
  VIPM_SCSLoBeamSwStVld_flg = (KIPM_SCSLoBeamSwSt_flg_ovrdflg ||
    rtb_LogicalOperator2_lt);

  /* Switch: '<S376>/Switch' */
  if (rtb_LogicalOperator2_lt) {
    /* Switch: '<S376>/Switch' incorporates:
     *  Inport: '<Root>/SCS_LeSwitchSts_BOD'
     *  Switch: '<S376>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_oa =
      (Rte_IRead_Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD()
      )->SCS_LowBeamSwtSt;
  } else {
    /* Switch: '<S376>/Switch' incorporates:
     *  Constant: '<S376>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_oa = KIPM_SCSLoBeamSwStDflt_flg;
  }

  /* End of Switch: '<S376>/Switch' */

  /* Switch: '<S376>/Switch4' incorporates:
   *  Constant: '<S376>/sat3'
   */
  if (KIPM_SCSLoBeamSwSt_flg_ovrdflg) {
    /* Switch: '<S376>/Switch4' incorporates:
     *  Constant: '<S376>/sat4'
     */
    VIPM_SCSLoBeamSwSt_flg = KIPM_SCSLoBeamSwSt_flg_ovrdval;
  } else {
    /* Switch: '<S376>/Switch4' */
    VIPM_SCSLoBeamSwSt_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_oa;
  }

  /* End of Switch: '<S376>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VIPM_SCSLoBeamSwSt_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VIPM_SCSHiBeamSwSt_flg' */
  /* Logic: '<S382>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/SCS_LeSwitchSts_BOD'
   *  Logic: '<S373>/Logical Operator2'
   */
  rtb_LogicalOperator2_lt =
    ((Rte_IRead_Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD())
     ->SCS_RodBeamSwtStVD &&
     (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
     ->VIPM_SCSMsgActv_flg);

  /* Logic: '<S373>/Logical Operator3' incorporates:
   *  Constant: '<S373>/sat3'
   */
  VIPM_SCSHiBeamSwStVld_flg = (KIPM_SCSHiBeamSwSt_flg_ovrdflg ||
    rtb_LogicalOperator2_lt);

  /* Switch: '<S373>/Switch' */
  if (rtb_LogicalOperator2_lt) {
    /* Switch: '<S373>/Switch' incorporates:
     *  Inport: '<Root>/SCS_LeSwitchSts_BOD'
     *  Switch: '<S373>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_dcs =
      (Rte_IRead_Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD()
      )->SCS_HiBeamSwtSt;
  } else {
    /* Switch: '<S373>/Switch' incorporates:
     *  Constant: '<S373>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_dcs = KIPM_SCSHiBeamSwStDflt_flg;
  }

  /* End of Switch: '<S373>/Switch' */

  /* Switch: '<S373>/Switch4' incorporates:
   *  Constant: '<S373>/sat3'
   */
  if (KIPM_SCSHiBeamSwSt_flg_ovrdflg) {
    /* Switch: '<S373>/Switch4' incorporates:
     *  Constant: '<S373>/sat4'
     */
    VIPM_SCSHiBeamSwSt_flg = KIPM_SCSHiBeamSwSt_flg_ovrdval;
  } else {
    /* Switch: '<S373>/Switch4' */
    VIPM_SCSHiBeamSwSt_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_dcs;
  }

  /* End of Switch: '<S373>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VIPM_SCSHiBeamSwSt_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VIPM_SCSOvrVehBeamSwSt_flg' */
  /* Logic: '<S382>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/SCS_LeSwitchSts_BOD'
   *  Logic: '<S377>/Logical Operator2'
   */
  rtb_LogicalOperator2_lt =
    ((Rte_IRead_Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD())
     ->SCS_RodBeamSwtStVD &&
     (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
     ->VIPM_SCSMsgActv_flg);

  /* Logic: '<S377>/Logical Operator3' incorporates:
   *  Constant: '<S377>/sat3'
   */
  VIPM_SCSOvrVehBeamSwStVld_flg = (KIPM_SCSOvrVehBeamSwSt_flg_ovrdflg ||
    rtb_LogicalOperator2_lt);

  /* Switch: '<S377>/Switch' */
  if (rtb_LogicalOperator2_lt) {
    /* Switch: '<S377>/Switch' incorporates:
     *  Inport: '<Root>/SCS_LeSwitchSts_BOD'
     *  Switch: '<S377>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cds =
      (Rte_IRead_Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD()
      )->SCS_OverVehBeamSwtSt;
  } else {
    /* Switch: '<S377>/Switch' incorporates:
     *  Constant: '<S377>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cds = KIPM_SCSOvrVehBeamSwStDflt_flg;
  }

  /* End of Switch: '<S377>/Switch' */

  /* Switch: '<S377>/Switch4' incorporates:
   *  Constant: '<S377>/sat3'
   */
  if (KIPM_SCSOvrVehBeamSwSt_flg_ovrdflg) {
    /* Switch: '<S377>/Switch4' incorporates:
     *  Constant: '<S377>/sat4'
     */
    VIPM_SCSOvrVehBeamSwSt_flg = KIPM_SCSOvrVehBeamSwSt_flg_ovrdval;
  } else {
    /* Switch: '<S377>/Switch4' */
    VIPM_SCSOvrVehBeamSwSt_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cds;
  }

  /* End of Switch: '<S377>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VIPM_SCSOvrVehBeamSwSt_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VIPM_SCSLampAutoSt_flg' */
  /* Logic: '<S374>/Logical Operator3' incorporates:
   *  Constant: '<S374>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_SCSLampAutoStVld_flg = (KIPM_SCSLampAutoSt_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())->VIPM_SCSMsgActv_flg);

  /* Switch: '<S374>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
      ->VIPM_SCSMsgActv_flg) {
    /* Switch: '<S374>/Switch' incorporates:
     *  Inport: '<Root>/SCS_LeSwitchSts_BOD'
     *  Switch: '<S374>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_bc =
      (Rte_IRead_Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD()
      )->SCS_LampAutoSt;
  } else {
    /* Switch: '<S374>/Switch' incorporates:
     *  Constant: '<S374>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_bc = KIPM_SCSLampAutoStDflt_flg;
  }

  /* End of Switch: '<S374>/Switch' */

  /* Switch: '<S374>/Switch4' incorporates:
   *  Constant: '<S374>/sat3'
   */
  if (KIPM_SCSLampAutoSt_flg_ovrdflg) {
    /* Switch: '<S374>/Switch4' incorporates:
     *  Constant: '<S374>/sat4'
     */
    VIPM_SCSLampAutoSt_flg = KIPM_SCSLampAutoSt_flg_ovrdval;
  } else {
    /* Switch: '<S374>/Switch4' */
    VIPM_SCSLampAutoSt_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_bc;
  }

  /* End of Switch: '<S374>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VIPM_SCSLampAutoSt_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VIPM_SCSLeTrnLmpSwSt_flg' */
  /* Logic: '<S382>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/SCS_LeSwitchSts_BOD'
   *  Logic: '<S375>/Logical Operator2'
   */
  rtb_LogicalOperator2_lt =
    ((Rte_IRead_Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD())
     ->SCS_RodBeamSwtStVD &&
     (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
     ->VIPM_SCSMsgActv_flg);

  /* Logic: '<S375>/Logical Operator3' incorporates:
   *  Constant: '<S375>/sat3'
   */
  VIPM_SCSLeTrnLmpSwStVld_flg = (KIPM_SCSLeTrnLmpSwSt_flg_ovrdflg ||
    rtb_LogicalOperator2_lt);

  /* Switch: '<S375>/Switch' */
  if (rtb_LogicalOperator2_lt) {
    /* Switch: '<S375>/Switch' incorporates:
     *  Inport: '<Root>/SCS_LeSwitchSts_BOD'
     *  Switch: '<S375>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_du =
      (Rte_IRead_Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD()
      )->SCS_LeTurnLmpSwtSt;
  } else {
    /* Switch: '<S375>/Switch' incorporates:
     *  Constant: '<S375>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_du = KIPM_SCSLeTrnLmpSwStDflt_flg;
  }

  /* End of Switch: '<S375>/Switch' */

  /* Switch: '<S375>/Switch4' incorporates:
   *  Constant: '<S375>/sat3'
   */
  if (KIPM_SCSLeTrnLmpSwSt_flg_ovrdflg) {
    /* Switch: '<S375>/Switch4' incorporates:
     *  Constant: '<S375>/sat4'
     */
    VIPM_SCSLeTrnLmpSwSt_flg = KIPM_SCSLeTrnLmpSwSt_flg_ovrdval;
  } else {
    /* Switch: '<S375>/Switch4' */
    VIPM_SCSLeTrnLmpSwSt_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_du;
  }

  /* End of Switch: '<S375>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VIPM_SCSLeTrnLmpSwSt_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VIPM_SCSRiTrnLmpSwSt_flg' */
  /* Logic: '<S382>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/SCS_LeSwitchSts_BOD'
   *  Logic: '<S379>/Logical Operator2'
   */
  rtb_LogicalOperator2_lt =
    ((Rte_IRead_Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD())
     ->SCS_RodBeamSwtStVD &&
     (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
     ->VIPM_SCSMsgActv_flg);

  /* Logic: '<S379>/Logical Operator3' incorporates:
   *  Constant: '<S379>/sat3'
   */
  VIPM_SCSRiTrnLmpSwStVld_flg = (KIPM_SCSRiTrnLmpSwSt_flg_ovrdflg ||
    rtb_LogicalOperator2_lt);

  /* Switch: '<S379>/Switch' */
  if (rtb_LogicalOperator2_lt) {
    /* Switch: '<S379>/Switch' incorporates:
     *  Inport: '<Root>/SCS_LeSwitchSts_BOD'
     *  Switch: '<S379>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ds =
      (Rte_IRead_Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD()
      )->SCS_RiTurnLmpSwtSt;
  } else {
    /* Switch: '<S379>/Switch' incorporates:
     *  Constant: '<S379>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ds = KIPM_SCSRiTrnLmpSwStDflt_flg;
  }

  /* End of Switch: '<S379>/Switch' */

  /* Switch: '<S379>/Switch4' incorporates:
   *  Constant: '<S379>/sat3'
   */
  if (KIPM_SCSRiTrnLmpSwSt_flg_ovrdflg) {
    /* Switch: '<S379>/Switch4' incorporates:
     *  Constant: '<S379>/sat4'
     */
    VIPM_SCSRiTrnLmpSwSt_flg = KIPM_SCSRiTrnLmpSwSt_flg_ovrdval;
  } else {
    /* Switch: '<S379>/Switch4' */
    VIPM_SCSRiTrnLmpSwSt_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ds;
  }

  /* End of Switch: '<S379>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VIPM_SCSRiTrnLmpSwSt_flg' */

  /* BusCreator: '<S349>/BusCreator' incorporates:
   *  Logic: '<S371>/Logical Operator3'
   *  Logic: '<S372>/Logical Operator3'
   *  Logic: '<S373>/Logical Operator3'
   *  Logic: '<S374>/Logical Operator3'
   *  Logic: '<S375>/Logical Operator3'
   *  Logic: '<S376>/Logical Operator3'
   *  Logic: '<S377>/Logical Operator3'
   *  Logic: '<S378>/Logical Operator3'
   *  Logic: '<S379>/Logical Operator3'
   *  Switch: '<S371>/Switch4'
   *  Switch: '<S372>/Switch4'
   *  Switch: '<S373>/Switch4'
   *  Switch: '<S374>/Switch4'
   *  Switch: '<S375>/Switch4'
   *  Switch: '<S376>/Switch4'
   *  Switch: '<S377>/Switch4'
   *  Switch: '<S378>/Switch4'
   *  Switch: '<S379>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSFrntWshrSwtSt_flg =
    VIPM_SCSFrntWshrSwtSt_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSFrntWshrSwtStVld_flg =
    VIPM_SCSFrntWshrSwtStVld_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSFrntWiprSwtSt_enum =
    VIPM_SCSFrntWiprSwtSt_enum;
  AppSwcIpm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSFrntWiprSwtStVld_flg =
    VIPM_SCSFrntWiprSwtStVld_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSPstnLghtSwSt_flg =
    VIPM_SCSPstnLghtSwSt_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSPstnLghtSwStVld_flg =
    VIPM_SCSPstnLghtSwStVld_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSLoBeamSwSt_flg =
    VIPM_SCSLoBeamSwSt_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSLoBeamSwStVld_flg =
    VIPM_SCSLoBeamSwStVld_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSHiBeamSwSt_flg =
    VIPM_SCSHiBeamSwSt_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSHiBeamSwStVld_flg =
    VIPM_SCSHiBeamSwStVld_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSOvrVehBeamSwSt_flg =
    VIPM_SCSOvrVehBeamSwSt_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSOvrVehBeamSwStVld_flg =
    VIPM_SCSOvrVehBeamSwStVld_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSLampAutoSt_flg =
    VIPM_SCSLampAutoSt_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSLampAutoStVld_flg =
    VIPM_SCSLampAutoStVld_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSLeTrnLmpSwSt_flg =
    VIPM_SCSLeTrnLmpSwSt_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSLeTrnLmpSwStVld_flg =
    VIPM_SCSLeTrnLmpSwStVld_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSRiTrnLmpSwSt_flg =
    VIPM_SCSRiTrnLmpSwSt_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSRiTrnLmpSwStVld_flg =
    VIPM_SCSRiTrnLmpSwStVld_flg;

  /* Outputs for Atomic SubSystem: '<S380>/Subsys_VIPM_SRSDrvSeatbeltBkld_flg' */
  /* Logic: '<S382>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/SRS_1_Status_CHA'
   */
  rtb_LogicalOperator2_lt =
    ((Rte_IRead_Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA())
     ->SRS_DrvSeatbeltBuckleValid &&
     (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
     ->VIPM_SRSMsgActv_flg);

  /* Logic: '<S382>/Logical Operator3' incorporates:
   *  Constant: '<S382>/sat3'
   */
  VIPM_SRSDrvSeatbeltBkldVld_flg = (KIPM_SRSDrvSeatbeltBkld_flg_ovrdflg ||
    rtb_LogicalOperator2_lt);

  /* Switch: '<S382>/Switch' */
  if (rtb_LogicalOperator2_lt) {
    /* Switch: '<S382>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_50ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_SRS_1_Status_CRCFlt_flg) {
      /* Switch: '<S382>/Switch' incorporates:
       *  Inport: '<Root>/SRS_1_Status_CHA'
       *  Switch: '<S382>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_fl =
        (Rte_IRead_Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA())
        ->SRS_DrvSeatbeltBucklestatus;
    }

    /* End of Switch: '<S382>/Switch3' */
  } else {
    /* Switch: '<S382>/Switch' incorporates:
     *  Constant: '<S382>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_fl = KIPM_SRSDrvSeatbeltBkldDflt_flg;
  }

  /* End of Switch: '<S382>/Switch' */

  /* Switch: '<S382>/Switch4' incorporates:
   *  Constant: '<S382>/sat3'
   */
  if (KIPM_SRSDrvSeatbeltBkld_flg_ovrdflg) {
    /* Switch: '<S382>/Switch4' incorporates:
     *  Constant: '<S382>/sat4'
     */
    VIPM_SRSDrvSeatbeltBkld_flg = KIPM_SRSDrvSeatbeltBkld_flg_ovrdval;
  } else {
    /* Switch: '<S382>/Switch4' */
    VIPM_SRSDrvSeatbeltBkld_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_fl;
  }

  /* End of Switch: '<S382>/Switch4' */
  /* End of Outputs for SubSystem: '<S380>/Subsys_VIPM_SRSDrvSeatbeltBkld_flg' */

  /* Outputs for Atomic SubSystem: '<S380>/Subsys_VIPM_SRSCrashOutputSts_enum' */
  /* Logic: '<S381>/Logical Operator3' incorporates:
   *  Constant: '<S381>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_SRSCrashOutputStsVld_flg = (KIPM_SRSCrashOutputSts_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())->VIPM_SRSMsgActv_flg);

  /* Switch: '<S381>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
      ->VIPM_SRSMsgActv_flg) {
    /* Switch: '<S381>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_50ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_SRS_1_Status_CRCFlt_flg) {
      /* Switch: '<S381>/Switch' incorporates:
       *  Inport: '<Root>/SRS_1_Status_CHA'
       *  Switch: '<S381>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_fi =
        (Rte_IRead_Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA())
        ->SRS_CrashOutputSts;
    }

    /* End of Switch: '<S381>/Switch3' */
  } else {
    /* Switch: '<S381>/Switch' incorporates:
     *  Constant: '<S381>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_fi = KIPM_SRSCrashOutputStsDflt_enum;
  }

  /* End of Switch: '<S381>/Switch' */

  /* Switch: '<S381>/Switch4' incorporates:
   *  Constant: '<S381>/sat3'
   */
  if (KIPM_SRSCrashOutputSts_enum_ovrdflg) {
    /* Switch: '<S381>/Switch4' incorporates:
     *  Constant: '<S381>/sat4'
     */
    VIPM_SRSCrashOutputSts_enum = KIPM_SRSCrashOutputSts_enum_ovrdval;
  } else {
    /* Switch: '<S381>/Switch4' */
    VIPM_SRSCrashOutputSts_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_fi;
  }

  /* End of Switch: '<S381>/Switch4' */
  /* End of Outputs for SubSystem: '<S380>/Subsys_VIPM_SRSCrashOutputSts_enum' */

  /* BusCreator: '<S380>/BusCreator' incorporates:
   *  Logic: '<S381>/Logical Operator3'
   *  Logic: '<S382>/Logical Operator3'
   *  Switch: '<S381>/Switch4'
   *  Switch: '<S382>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_SRS_1_Status_CHA.VIPM_SRSDrvSeatbeltBkld_flg =
    VIPM_SRSDrvSeatbeltBkld_flg;
  AppSwcIpm_ARID_DEF.IPM_SRS_1_Status_CHA.VIPM_SRSDrvSeatbeltBkldVld_flg =
    VIPM_SRSDrvSeatbeltBkldVld_flg;
  AppSwcIpm_ARID_DEF.IPM_SRS_1_Status_CHA.VIPM_SRSCrashOutputSts_enum =
    VIPM_SRSCrashOutputSts_enum;
  AppSwcIpm_ARID_DEF.IPM_SRS_1_Status_CHA.VIPM_SRSCrashOutputStsVld_flg =
    VIPM_SRSCrashOutputStsVld_flg;
}

/* Model step function for TID1 */
void Runbl_IpmMsgActv_10ms(void)      /* Explicit Task: Runbl_IpmMsgActv_10ms */
{
  DT_CANCommCRCFlt CANCommCRCFlt_outputs;
  DT_CANCommCRCFlt rtb_SignalConversion1;
  DT_CANCommErr rtb_CANCommErr_outputs;
  DT_MsgActv rtb_SignalConversion;
  uint8 rtb_DTC_0xC04688_ErrCode368;
  boolean MsgActv_outputs_tmp;

  /* RootInportFunctionCallGenerator generated from: '<Root>/Runbl_IpmMsgActv_10ms' incorporates:
   *  SubSystem: '<Root>/IpmMsgActv'
   */
  /* CCaller: '<S384>/DTC_0xC04688_ErrCode368' */
  rtb_DTC_0xC04688_ErrCode368 = App_Call_Event_DTC_0xC04688_GetEventStatus();

  /* Switch: '<S384>/Switch' incorporates:
   *  Constant: '<S384>/KIPC_LimpHomeOvrdSw_flg11'
   */
  if (KIPM_EPTCANBusOffOvrdSw_flg) {
    /* Switch: '<S384>/Switch' incorporates:
     *  Constant: '<S384>/KIPC_LimpHomeOvrdSw_flg4'
     */
    VIPM_EPTCANBusOff_flg = KIPM_EPTCANBusOffOvrdVal_flg;
  } else {
    /* Switch: '<S384>/Switch' incorporates:
     *  DataTypeConversion: '<S384>/Data Type Conversion'
     *  S-Function (sfix_bitop): '<S384>/Bitwise AND'
     */
    VIPM_EPTCANBusOff_flg = ((rtb_DTC_0xC04688_ErrCode368 & 1U) != 0U);
  }

  /* End of Switch: '<S384>/Switch' */

  /* CCaller: '<S384>/DTC_0xC11287_ErrCode354' */
  rtb_DTC_0xC04688_ErrCode368 = App_Call_Event_DTC_0xC11287_GetEventStatus();

  /* Switch: '<S384>/Switch4' incorporates:
   *  Constant: '<S384>/KIPC_LimpHomeOvrdSw_flg8'
   */
  if (KIPM_BMSLostCommOvrdSw_flg) {
    /* Switch: '<S384>/Switch4' incorporates:
     *  Constant: '<S384>/KIPC_LimpHomeOvrdSw_flg9'
     */
    VIPM_BMSLostComm_flg = KIPM_BMSLostCommOvrdVal_flg;
  } else {
    /* Switch: '<S384>/Switch4' incorporates:
     *  DataTypeConversion: '<S384>/Data Type Conversion4'
     *  S-Function (sfix_bitop): '<S384>/Bitwise AND4'
     */
    VIPM_BMSLostComm_flg = ((rtb_DTC_0xC04688_ErrCode368 & 1U) != 0U);
  }

  /* End of Switch: '<S384>/Switch4' */

  /* Logic: '<S385>/Logical Operator' incorporates:
   *  Inport: '<Root>/DAG_Comm_outputs'
   *  Switch: '<S384>/Switch'
   *  Switch: '<S384>/Switch4'
   */
  AppSwcIpm_ARID_DEF.MsgActv_outputs.VIPM_BMSMsgActv_flg =
    ((!VIPM_EPTCANBusOff_flg) && (!VIPM_BMSLostComm_flg) &&
     (!(Rte_IRead_Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs())
      ->VDAG_BMSCRCChkFlt_flg));

  /* CCaller: '<S384>/DTC_0xD10887_ErrCode364' */
  rtb_DTC_0xC04688_ErrCode368 = App_Call_Event_DTC_0xD10887_GetEventStatus();

  /* Switch: '<S384>/Switch13' incorporates:
   *  Constant: '<S384>/KIPC_LimpHomeOvrdSw_flg27'
   */
  if (KIPM_MCULostCommOvrdSw_flg) {
    /* Switch: '<S384>/Switch13' incorporates:
     *  Constant: '<S384>/KIPC_LimpHomeOvrdSw_flg28'
     */
    VIPM_MCULostComm_flg = KIPM_MCULostCommOvrdVal_flg;
  } else {
    /* Switch: '<S384>/Switch13' incorporates:
     *  DataTypeConversion: '<S384>/Data Type Conversion13'
     *  S-Function (sfix_bitop): '<S384>/Bitwise AND13'
     */
    VIPM_MCULostComm_flg = ((rtb_DTC_0xC04688_ErrCode368 & 1U) != 0U);
  }

  /* End of Switch: '<S384>/Switch13' */

  /* Logic: '<S385>/Logical Operator1' incorporates:
   *  Inport: '<Root>/DAG_Comm_outputs'
   *  Switch: '<S384>/Switch'
   *  Switch: '<S384>/Switch13'
   */
  AppSwcIpm_ARID_DEF.MsgActv_outputs.VIPM_INVMsgActv_flg =
    ((!VIPM_EPTCANBusOff_flg) && (!VIPM_MCULostComm_flg) &&
     (!(Rte_IRead_Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs())
      ->VDAG_INVCRCChkFlt_flg));

  /* CCaller: '<S384>/DTC_0xC14687_ErrCode376' */
  rtb_DTC_0xC04688_ErrCode368 = App_Call_Event_DTC_0xC14687_GetEventStatus();

  /* Switch: '<S384>/Switch17' incorporates:
   *  Constant: '<S384>/KIPC_LimpHomeOvrdSw_flg35'
   */
  if (KIPM_IPULostCommOvrdSw_flg) {
    /* Switch: '<S384>/Switch17' incorporates:
     *  Constant: '<S384>/KIPC_LimpHomeOvrdSw_flg36'
     */
    VIPM_IPULostComm_flg = KIPM_IPULostCommOvrdVal_flg;
  } else {
    /* Switch: '<S384>/Switch17' incorporates:
     *  DataTypeConversion: '<S384>/Data Type Conversion17'
     *  S-Function (sfix_bitop): '<S384>/Bitwise AND17'
     */
    VIPM_IPULostComm_flg = ((rtb_DTC_0xC04688_ErrCode368 & 1U) != 0U);
  }

  /* End of Switch: '<S384>/Switch17' */

  /* Logic: '<S385>/Logical Operator2' incorporates:
   *  Inport: '<Root>/DAG_Comm_outputs'
   *  Logic: '<S385>/Logical Operator3'
   *  Switch: '<S384>/Switch'
   *  Switch: '<S384>/Switch17'
   */
  MsgActv_outputs_tmp = ((!VIPM_EPTCANBusOff_flg) && (!VIPM_IPULostComm_flg));
  AppSwcIpm_ARID_DEF.MsgActv_outputs.VIPM_OBCMsgActv_flg = (MsgActv_outputs_tmp &&
    (!(Rte_IRead_Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs())
     ->VDAG_IPUCRCChkFlt_flg));

  /* Logic: '<S385>/Logical Operator3' incorporates:
   *  Inport: '<Root>/DAG_Comm_outputs'
   */
  AppSwcIpm_ARID_DEF.MsgActv_outputs.VIPM_DCDCMsgActv_flg = (MsgActv_outputs_tmp
    && (!(Rte_IRead_Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs())
        ->VDAG_IPUCRCChkFlt_flg));

  /* CCaller: '<S384>/DTC_0xC06488_ErrCode379' */
  rtb_DTC_0xC04688_ErrCode368 = App_Call_Event_DTC_0xC06488_GetEventStatus();

  /* Switch: '<S384>/Switch3' incorporates:
   *  Constant: '<S384>/KIPC_LimpHomeOvrdSw_flg6'
   */
  if (KIPM_CHACANBusOffOvrdSw_flg) {
    /* Switch: '<S384>/Switch3' incorporates:
     *  Constant: '<S384>/KIPC_LimpHomeOvrdSw_flg7'
     */
    VIPM_CHACANBusOff_flg = KIPM_CHACANBusOffOvrdVal_flg;
  } else {
    /* Switch: '<S384>/Switch3' incorporates:
     *  DataTypeConversion: '<S384>/Data Type Conversion3'
     *  S-Function (sfix_bitop): '<S384>/Bitwise AND3'
     */
    VIPM_CHACANBusOff_flg = ((rtb_DTC_0xC04688_ErrCode368 & 1U) != 0U);
  }

  /* End of Switch: '<S384>/Switch3' */

  /* CCaller: '<S384>/DTC_0xC13087_ErrCode366' */
  rtb_DTC_0xC04688_ErrCode368 = App_Call_Event_DTC_0xC13087_GetEventStatus();

  /* Switch: '<S384>/Switch9' incorporates:
   *  Constant: '<S384>/KIPC_LimpHomeOvrdSw_flg19'
   */
  if (KIPM_EPSLostCommOvrdSw_flg) {
    /* Switch: '<S384>/Switch9' incorporates:
     *  Constant: '<S384>/KIPC_LimpHomeOvrdSw_flg20'
     */
    VIPM_EPSLostComm_flg = KIPM_EPSLostCommOvrdVal_flg;
  } else {
    /* Switch: '<S384>/Switch9' incorporates:
     *  DataTypeConversion: '<S384>/Data Type Conversion9'
     *  S-Function (sfix_bitop): '<S384>/Bitwise AND9'
     */
    VIPM_EPSLostComm_flg = ((rtb_DTC_0xC04688_ErrCode368 & 1U) != 0U);
  }

  /* End of Switch: '<S384>/Switch9' */

  /* Logic: '<S385>/Logical Operator4' incorporates:
   *  Inport: '<Root>/DAG_Comm_outputs'
   *  Switch: '<S384>/Switch3'
   *  Switch: '<S384>/Switch9'
   */
  AppSwcIpm_ARID_DEF.MsgActv_outputs.VIPM_EPSMsgActv_flg =
    ((!VIPM_CHACANBusOff_flg) && (!VIPM_EPSLostComm_flg) &&
     (!(Rte_IRead_Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs())
      ->VDAG_EPSCRCChkFlt_flg));

  /* CCaller: '<S384>/DTC_0xC15187_ErrCode363' */
  rtb_DTC_0xC04688_ErrCode368 = App_Call_Event_DTC_0xC15187_GetEventStatus();

  /* Switch: '<S384>/Switch10' incorporates:
   *  Constant: '<S384>/KIPC_LimpHomeOvrdSw_flg21'
   */
  if (KIPM_SRSLostCommOvrdSw_flg) {
    /* Switch: '<S384>/Switch10' incorporates:
     *  Constant: '<S384>/KIPC_LimpHomeOvrdSw_flg22'
     */
    VIPM_SRSLostComm_flg = KIPM_SRSLostCommOvrdVal_flg;
  } else {
    /* Switch: '<S384>/Switch10' incorporates:
     *  DataTypeConversion: '<S384>/Data Type Conversion10'
     *  S-Function (sfix_bitop): '<S384>/Bitwise AND10'
     */
    VIPM_SRSLostComm_flg = ((rtb_DTC_0xC04688_ErrCode368 & 1U) != 0U);
  }

  /* End of Switch: '<S384>/Switch10' */

  /* Logic: '<S385>/Logical Operator5' incorporates:
   *  Inport: '<Root>/DAG_Comm_outputs'
   *  Switch: '<S384>/Switch10'
   *  Switch: '<S384>/Switch3'
   */
  AppSwcIpm_ARID_DEF.MsgActv_outputs.VIPM_SRSMsgActv_flg =
    ((!VIPM_CHACANBusOff_flg) && (!VIPM_SRSLostComm_flg) &&
     (!(Rte_IRead_Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs())
      ->VDAG_SRSCRCChkFlt_flg));

  /* CCaller: '<S384>/DTC_0xC12287_ErrCode359' */
  rtb_DTC_0xC04688_ErrCode368 = App_Call_Event_DTC_0xC12287_GetEventStatus();

  /* Switch: '<S384>/Switch5' incorporates:
   *  Constant: '<S384>/KIPC_LimpHomeOvrdSw_flg10'
   */
  if (KIPM_ESCLostCommOvrdSw_flg) {
    /* Switch: '<S384>/Switch5' incorporates:
     *  Constant: '<S384>/KIPC_LimpHomeOvrdSw_flg12'
     */
    VIPM_ESCLostComm_flg = KIPM_ESCLostCommOvrdVal_flg;
  } else {
    /* Switch: '<S384>/Switch5' incorporates:
     *  DataTypeConversion: '<S384>/Data Type Conversion5'
     *  S-Function (sfix_bitop): '<S384>/Bitwise AND5'
     */
    VIPM_ESCLostComm_flg = ((rtb_DTC_0xC04688_ErrCode368 & 1U) != 0U);
  }

  /* End of Switch: '<S384>/Switch5' */

  /* Logic: '<S385>/Logical Operator6' incorporates:
   *  Inport: '<Root>/DAG_Comm_outputs'
   *  Switch: '<S384>/Switch3'
   *  Switch: '<S384>/Switch5'
   */
  AppSwcIpm_ARID_DEF.MsgActv_outputs.VIPM_ESCMsgActv_flg =
    ((!VIPM_CHACANBusOff_flg) && (!VIPM_ESCLostComm_flg) &&
     (!(Rte_IRead_Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs())
      ->VDAG_ESCCRCChkFlt_flg));

  /* CCaller: '<S384>/DTC_0xD10287_ErrCode372' */
  rtb_DTC_0xC04688_ErrCode368 = App_Call_Event_DTC_0xD10287_GetEventStatus();

  /* Switch: '<S384>/Switch6' incorporates:
   *  Constant: '<S384>/KIPC_LimpHomeOvrdSw_flg13'
   */
  if (KIPM_FCMLostCommOvrdSw_flg) {
    /* Switch: '<S384>/Switch6' incorporates:
     *  Constant: '<S384>/KIPC_LimpHomeOvrdSw_flg14'
     */
    VIPM_FCMLostComm_flg = KIPM_FCMLostCommOvrdVal_flg;
  } else {
    /* Switch: '<S384>/Switch6' incorporates:
     *  DataTypeConversion: '<S384>/Data Type Conversion6'
     *  S-Function (sfix_bitop): '<S384>/Bitwise AND6'
     */
    VIPM_FCMLostComm_flg = ((rtb_DTC_0xC04688_ErrCode368 & 1U) != 0U);
  }

  /* End of Switch: '<S384>/Switch6' */

  /* Logic: '<S385>/Logical Operator7' incorporates:
   *  Inport: '<Root>/DAG_Comm_outputs'
   *  Switch: '<S384>/Switch3'
   *  Switch: '<S384>/Switch6'
   */
  AppSwcIpm_ARID_DEF.MsgActv_outputs.VIPM_FCMMsgActv_flg =
    ((!VIPM_CHACANBusOff_flg) && (!VIPM_FCMLostComm_flg) &&
     (!(Rte_IRead_Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs())
      ->VDAG_FCMCRCChkFlt_flg));

  /* CCaller: '<S384>/DTC_0xC13187_ErrCode377' */
  rtb_DTC_0xC04688_ErrCode368 = App_Call_Event_DTC_0xC13187_GetEventStatus();

  /* Switch: '<S384>/Switch18' incorporates:
   *  Constant: '<S384>/KIPC_LimpHomeOvrdSw_flg37'
   */
  if (KIPM_EHBLostCommOvrdSw_flg) {
    /* Switch: '<S384>/Switch18' incorporates:
     *  Constant: '<S384>/KIPC_LimpHomeOvrdSw_flg38'
     */
    VIPM_EHBLostComm_flg = KIPM_EHBLostCommOvrdVal_flg;
  } else {
    /* Switch: '<S384>/Switch18' incorporates:
     *  DataTypeConversion: '<S384>/Data Type Conversion18'
     *  S-Function (sfix_bitop): '<S384>/Bitwise AND18'
     */
    VIPM_EHBLostComm_flg = ((rtb_DTC_0xC04688_ErrCode368 & 1U) != 0U);
  }

  /* End of Switch: '<S384>/Switch18' */

  /* Logic: '<S385>/Logical Operator17' incorporates:
   *  Inport: '<Root>/DAG_Comm_outputs'
   *  Switch: '<S384>/Switch18'
   *  Switch: '<S384>/Switch3'
   */
  AppSwcIpm_ARID_DEF.MsgActv_outputs.VIPM_EHBMsgActv_flg =
    ((!VIPM_CHACANBusOff_flg) && (!VIPM_EHBLostComm_flg) &&
     (!(Rte_IRead_Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs())
      ->VDAG_EHBCRCChkFlt_flg));

  /* CCaller: '<S384>/DTC_0xC07388_ErrCode367' */
  rtb_DTC_0xC04688_ErrCode368 = App_Call_Event_DTC_0xC07388_GetEventStatus();

  /* Switch: '<S384>/Switch2' incorporates:
   *  Constant: '<S384>/KIPC_LimpHomeOvrdSw_flg3'
   */
  if (KIPM_BACCANBusOffOvrdSw_flg) {
    /* Switch: '<S384>/Switch2' incorporates:
     *  Constant: '<S384>/KIPC_LimpHomeOvrdSw_flg5'
     */
    VIPM_BACCANBusOff_flg = KIPM_BACCANBusOffOvrdVal_flg;
  } else {
    /* Switch: '<S384>/Switch2' incorporates:
     *  DataTypeConversion: '<S384>/Data Type Conversion2'
     *  S-Function (sfix_bitop): '<S384>/Bitwise AND2'
     */
    VIPM_BACCANBusOff_flg = ((rtb_DTC_0xC04688_ErrCode368 & 1U) != 0U);
  }

  /* End of Switch: '<S384>/Switch2' */

  /* CCaller: '<S384>/DTC_0xD11687_ErrCode369' */
  rtb_DTC_0xC04688_ErrCode368 = App_Call_Event_DTC_0xD11687_GetEventStatus();

  /* Switch: '<S384>/Switch11' incorporates:
   *  Constant: '<S384>/KIPC_LimpHomeOvrdSw_flg23'
   */
  if (KIPM_ICULostCommOvrdSw_flg) {
    /* Switch: '<S384>/Switch11' incorporates:
     *  Constant: '<S384>/KIPC_LimpHomeOvrdSw_flg24'
     */
    VIPM_ICULostComm_flg = KIPM_ICULostCommOvrdVal_flg;
  } else {
    /* Switch: '<S384>/Switch11' incorporates:
     *  DataTypeConversion: '<S384>/Data Type Conversion11'
     *  S-Function (sfix_bitop): '<S384>/Bitwise AND11'
     */
    VIPM_ICULostComm_flg = ((rtb_DTC_0xC04688_ErrCode368 & 1U) != 0U);
  }

  /* End of Switch: '<S384>/Switch11' */

  /* Logic: '<S385>/Logical Operator8' incorporates:
   *  Inport: '<Root>/DAG_Comm_outputs'
   *  Switch: '<S384>/Switch11'
   *  Switch: '<S384>/Switch2'
   */
  AppSwcIpm_ARID_DEF.MsgActv_outputs.VIPM_CDCMsgActv_flg =
    ((!VIPM_BACCANBusOff_flg) && (!VIPM_ICULostComm_flg) &&
     (!(Rte_IRead_Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs())
      ->VDAG_ICUCRCChkFlt_flg));

  /* CCaller: '<S384>/DTC_0xD11687_ErrCode365' */
  rtb_DTC_0xC04688_ErrCode368 = App_Call_Event_DTC_0xC19887_GetEventStatus();

  /* Switch: '<S384>/Switch12' incorporates:
   *  Constant: '<S384>/KIPC_LimpHomeOvrdSw_flg25'
   */
  if (KIPM_TBOXLostCommOvrdSw_flg) {
    /* Switch: '<S384>/Switch12' incorporates:
     *  Constant: '<S384>/KIPC_LimpHomeOvrdSw_flg26'
     */
    VIPM_TBOXLostComm_flg = KIPM_TBOXLostCommOvrdVal_flg;
  } else {
    /* Switch: '<S384>/Switch12' incorporates:
     *  DataTypeConversion: '<S384>/Data Type Conversion12'
     *  S-Function (sfix_bitop): '<S384>/Bitwise AND12'
     */
    VIPM_TBOXLostComm_flg = ((rtb_DTC_0xC04688_ErrCode368 & 1U) != 0U);
  }

  /* End of Switch: '<S384>/Switch12' */

  /* Logic: '<S385>/Logical Operator9' incorporates:
   *  Inport: '<Root>/DAG_Comm_outputs'
   *  Switch: '<S384>/Switch12'
   *  Switch: '<S384>/Switch2'
   */
  AppSwcIpm_ARID_DEF.MsgActv_outputs.VIPM_TBOXMsgActv_flg =
    ((!VIPM_BACCANBusOff_flg) && (!VIPM_TBOXLostComm_flg) &&
     (!(Rte_IRead_Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs())
      ->VDAG_TBOXCRCChkFlt_flg));

  /* CCaller: '<S384>/DTC_0xC05588_ErrCode378' */
  rtb_DTC_0xC04688_ErrCode368 = App_Call_Event_DTC_0xC05588_GetEventStatus();

  /* Switch: '<S384>/Switch1' incorporates:
   *  Constant: '<S384>/KIPC_LimpHomeOvrdSw_flg1'
   */
  if (KIPM_BODCANBusOffOvrdSw_flg) {
    /* Switch: '<S384>/Switch1' incorporates:
     *  Constant: '<S384>/KIPC_LimpHomeOvrdSw_flg2'
     */
    VIPM_BODCANBusOff_flg = KIPM_BODCANBusOffOvrdVal_flg;
  } else {
    /* Switch: '<S384>/Switch1' incorporates:
     *  DataTypeConversion: '<S384>/Data Type Conversion1'
     *  S-Function (sfix_bitop): '<S384>/Bitwise AND1'
     */
    VIPM_BODCANBusOff_flg = ((rtb_DTC_0xC04688_ErrCode368 & 1U) != 0U);
  }

  /* End of Switch: '<S384>/Switch1' */

  /* CCaller: '<S384>/DTC_0xC10F87_ErrCode370' */
  rtb_DTC_0xC04688_ErrCode368 = App_Call_Event_DTC_0xC10F87_GetEventStatus();

  /* Switch: '<S384>/Switch14' incorporates:
   *  Constant: '<S384>/KIPC_LimpHomeOvrdSw_flg29'
   */
  if (KIPM_ACCMLostCommOvrdSw_flg) {
    /* Switch: '<S384>/Switch14' incorporates:
     *  Constant: '<S384>/KIPC_LimpHomeOvrdSw_flg30'
     */
    VIPM_ACCMLostComm_flg = KIPM_ACCMLostCommOvrdVal_flg;
  } else {
    /* Switch: '<S384>/Switch14' incorporates:
     *  DataTypeConversion: '<S384>/Data Type Conversion14'
     *  S-Function (sfix_bitop): '<S384>/Bitwise AND14'
     */
    VIPM_ACCMLostComm_flg = ((rtb_DTC_0xC04688_ErrCode368 & 1U) != 0U);
  }

  /* End of Switch: '<S384>/Switch14' */

  /* Logic: '<S385>/Logical Operator10' incorporates:
   *  Inport: '<Root>/DAG_Comm_outputs'
   *  Switch: '<S384>/Switch1'
   *  Switch: '<S384>/Switch14'
   */
  AppSwcIpm_ARID_DEF.MsgActv_outputs.VIPM_ACCMMsgActv_flg =
    ((!VIPM_BODCANBusOff_flg) && (!VIPM_ACCMLostComm_flg) &&
     (!(Rte_IRead_Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs())
      ->VDAG_ACCMCRCChkFlt_flg));

  /* CCaller: '<S384>/DTC_0xC24087_ErrCode252' */
  rtb_DTC_0xC04688_ErrCode368 = App_Call_Event_DTC_0xC24087_GetEventStatus();

  /* Switch: '<S384>/Switch19' incorporates:
   *  Constant: '<S384>/KIPC_LimpHomeOvrdSw_flg39'
   */
  if (KIPM_SCSLostCommOvrdSw_flg) {
    /* Switch: '<S384>/Switch19' incorporates:
     *  Constant: '<S384>/KIPC_LimpHomeOvrdSw_flg40'
     */
    VIPM_SCSLostComm_flg = KIPM_SCSLostCommOvrdVal_flg;
  } else {
    /* Switch: '<S384>/Switch19' incorporates:
     *  DataTypeConversion: '<S384>/Data Type Conversion19'
     *  S-Function (sfix_bitop): '<S384>/Bitwise AND19'
     */
    VIPM_SCSLostComm_flg = ((rtb_DTC_0xC04688_ErrCode368 & 1U) != 0U);
  }

  /* End of Switch: '<S384>/Switch19' */

  /* Logic: '<S385>/Logical Operator18' incorporates:
   *  Inport: '<Root>/DAG_Comm_outputs'
   *  Switch: '<S384>/Switch1'
   *  Switch: '<S384>/Switch19'
   */
  AppSwcIpm_ARID_DEF.MsgActv_outputs.VIPM_SCSMsgActv_flg =
    ((!VIPM_BODCANBusOff_flg) && (!VIPM_SCSLostComm_flg) &&
     (!(Rte_IRead_Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs())
      ->VDAG_SCSCRCChkFlt_flg));

  /* CCaller: '<S384>/DTC_0xC27087_ErrCode373' */
  rtb_DTC_0xC04688_ErrCode368 = App_Call_Event_DTC_0xC27087_GetEventStatus();

  /* Switch: '<S384>/Switch20' incorporates:
   *  Constant: '<S384>/KIPC_LimpHomeOvrdSw_flg41'
   */
  if (KIPM_CCPLostCommOvrdSw_flg) {
    /* Switch: '<S384>/Switch20' incorporates:
     *  Constant: '<S384>/KIPC_LimpHomeOvrdSw_flg42'
     */
    VIPM_CCPLostComm_flg = KIPM_CCPLostCommOvrdVal_flg;
  } else {
    /* Switch: '<S384>/Switch20' incorporates:
     *  DataTypeConversion: '<S384>/Data Type Conversion20'
     *  S-Function (sfix_bitop): '<S384>/Bitwise AND20'
     */
    VIPM_CCPLostComm_flg = ((rtb_DTC_0xC04688_ErrCode368 & 1U) != 0U);
  }

  /* End of Switch: '<S384>/Switch20' */

  /* Logic: '<S385>/Logical Operator19' incorporates:
   *  Inport: '<Root>/DAG_Comm_outputs'
   *  Switch: '<S384>/Switch1'
   *  Switch: '<S384>/Switch20'
   */
  AppSwcIpm_ARID_DEF.MsgActv_outputs.VIPM_CCPMsgActv_flg =
    ((!VIPM_BODCANBusOff_flg) && (!VIPM_CCPLostComm_flg) &&
     (!(Rte_IRead_Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs())
      ->VDAG_CCPCRCChkFlt_flg));

  /* Logic: '<S385>/Logical Operator13' incorporates:
   *  Switch: '<S384>/Switch1'
   */
  AppSwcIpm_ARID_DEF.MsgActv_outputs.VIPM_ESCLMsgActv_flg =
    !VIPM_BODCANBusOff_flg;

  /* CCaller: '<S384>/DTC_0xD11D87_ErrCode360' */
  rtb_DTC_0xC04688_ErrCode368 = App_Call_Event_DTC_0xD11D87_GetEventStatus();

  /* Switch: '<S384>/Switch16' incorporates:
   *  Constant: '<S384>/KIPC_LimpHomeOvrdSw_flg33'
   */
  if (KIPM_CDCLostCommOvrdSw_flg) {
    /* Switch: '<S384>/Switch16' incorporates:
     *  Constant: '<S384>/KIPC_LimpHomeOvrdSw_flg34'
     */
    VIPM_CDCLostComm_flg = KIPM_CDCLostCommOvrdVal_flg;
  } else {
    /* Switch: '<S384>/Switch16' incorporates:
     *  DataTypeConversion: '<S384>/Data Type Conversion16'
     *  S-Function (sfix_bitop): '<S384>/Bitwise AND16'
     */
    VIPM_CDCLostComm_flg = ((rtb_DTC_0xC04688_ErrCode368 & 1U) != 0U);
  }

  /* End of Switch: '<S384>/Switch16' */

  /* Logic: '<S385>/Logical Operator16' incorporates:
   *  Inport: '<Root>/DAG_Comm_outputs'
   *  Switch: '<S384>/Switch16'
   *  Switch: '<S384>/Switch2'
   */
  AppSwcIpm_ARID_DEF.MsgActv_outputs.VIPM_HUMsgActv_flg =
    ((!VIPM_BACCANBusOff_flg) && (!VIPM_CDCLostComm_flg) &&
     (!(Rte_IRead_Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs())
      ->VDAG_HUCRCChkFlt_flg));

  /* CCaller: '<S384>/DTC_0xC23087_ErrCode371' */
  rtb_DTC_0xC04688_ErrCode368 = App_Call_Event_DTC_0xC23087_GetEventStatus();

  /* Switch: '<S384>/Switch15' incorporates:
   *  Constant: '<S384>/KIPC_LimpHomeOvrdSw_flg31'
   */
  if (KIPM_PTCLostCommOvrdSw_flg) {
    /* Switch: '<S384>/Switch15' incorporates:
     *  Constant: '<S384>/KIPC_LimpHomeOvrdSw_flg32'
     */
    VIPM_PTCLostComm_flg = KIPM_PTCLostCommOvrdVal_flg;
  } else {
    /* Switch: '<S384>/Switch15' incorporates:
     *  DataTypeConversion: '<S384>/Data Type Conversion15'
     *  S-Function (sfix_bitop): '<S384>/Bitwise AND15'
     */
    VIPM_PTCLostComm_flg = ((rtb_DTC_0xC04688_ErrCode368 & 1U) != 0U);
  }

  /* End of Switch: '<S384>/Switch15' */

  /* Logic: '<S385>/Logical Operator14' incorporates:
   *  Inport: '<Root>/DAG_Comm_outputs'
   *  Switch: '<S384>/Switch1'
   *  Switch: '<S384>/Switch15'
   */
  AppSwcIpm_ARID_DEF.MsgActv_outputs.VIPM_PTCMsgActv_flg =
    ((!VIPM_BODCANBusOff_flg) && (!VIPM_PTCLostComm_flg) &&
     (!(Rte_IRead_Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs())
      ->VDAG_PTCCRCChkFlt_flg));

  /* CCaller: '<S384>/DTC_0xD11287_ErrCode361' */
  rtb_DTC_0xC04688_ErrCode368 = App_Call_Event_DTC_0xD11287_GetEventStatus();

  /* Switch: '<S384>/Switch7' incorporates:
   *  Constant: '<S384>/KIPC_LimpHomeOvrdSw_flg15'
   */
  if (KIPM_CRRRLostCommOvrdSw_flg) {
    /* Switch: '<S384>/Switch7' incorporates:
     *  Constant: '<S384>/KIPC_LimpHomeOvrdSw_flg16'
     */
    VIPM_CRRRLostComm_flg = KIPM_CRRRLostCommOvrdVal_flg;
  } else {
    /* Switch: '<S384>/Switch7' incorporates:
     *  DataTypeConversion: '<S384>/Data Type Conversion7'
     *  S-Function (sfix_bitop): '<S384>/Bitwise AND7'
     */
    VIPM_CRRRLostComm_flg = ((rtb_DTC_0xC04688_ErrCode368 & 1U) != 0U);
  }

  /* End of Switch: '<S384>/Switch7' */

  /* Logic: '<S385>/Logical Operator15' incorporates:
   *  Inport: '<Root>/DAG_Comm_outputs'
   *  Switch: '<S384>/Switch2'
   *  Switch: '<S384>/Switch7'
   */
  AppSwcIpm_ARID_DEF.MsgActv_outputs.VIPM_CRRRMsgActv_flg =
    ((!VIPM_BACCANBusOff_flg) && (!VIPM_CRRRLostComm_flg) &&
     (!(Rte_IRead_Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs())
      ->VDAG_CRRRCRCChkFlt_flg));

  /* CCaller: '<S384>/DTC_0xD10E87_ErrCode362' */
  rtb_DTC_0xC04688_ErrCode368 = App_Call_Event_DTC_0xD10E87_GetEventStatus();

  /* Switch: '<S384>/Switch8' incorporates:
   *  Constant: '<S384>/KIPC_LimpHomeOvrdSw_flg17'
   */
  if (KIPM_PPLostCommOvrdSw_flg) {
    /* Switch: '<S384>/Switch8' incorporates:
     *  Constant: '<S384>/KIPC_LimpHomeOvrdSw_flg18'
     */
    VIPM_PPLostComm_flg = KIPM_PPLostCommOvrdVal_flg;
  } else {
    /* Switch: '<S384>/Switch8' incorporates:
     *  DataTypeConversion: '<S384>/Data Type Conversion8'
     *  S-Function (sfix_bitop): '<S384>/Bitwise AND8'
     */
    VIPM_PPLostComm_flg = ((rtb_DTC_0xC04688_ErrCode368 & 1U) != 0U);
  }

  /* End of Switch: '<S384>/Switch8' */

  /* BusCreator: '<S384>/Bus Creator' incorporates:
   *  Switch: '<S384>/Switch'
   *  Switch: '<S384>/Switch1'
   *  Switch: '<S384>/Switch10'
   *  Switch: '<S384>/Switch11'
   *  Switch: '<S384>/Switch12'
   *  Switch: '<S384>/Switch13'
   *  Switch: '<S384>/Switch14'
   *  Switch: '<S384>/Switch15'
   *  Switch: '<S384>/Switch16'
   *  Switch: '<S384>/Switch17'
   *  Switch: '<S384>/Switch18'
   *  Switch: '<S384>/Switch19'
   *  Switch: '<S384>/Switch2'
   *  Switch: '<S384>/Switch20'
   *  Switch: '<S384>/Switch3'
   *  Switch: '<S384>/Switch4'
   *  Switch: '<S384>/Switch5'
   *  Switch: '<S384>/Switch6'
   *  Switch: '<S384>/Switch7'
   *  Switch: '<S384>/Switch8'
   *  Switch: '<S384>/Switch9'
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
  rtb_SignalConversion = AppSwcIpm_ARID_DEF.MsgActv_outputs;

  /* Logic: '<S383>/Logical Operator' incorporates:
   *  Constant: '<S383>/Cnst'
   *  Constant: '<S383>/Constant1'
   *  DataStoreRead: '<S383>/Data Store Read'
   *  Selector: '<S383>/Selector'
   */
  VIPM_HU_B_CRCFlt_flg = (VBSW_CANComCRCInstFlt_flg[89] && KIPM_HUCRCChkEnbl_flg);

  /* Logic: '<S383>/Logical Operator1' incorporates:
   *  Constant: '<S383>/Cnst1'
   *  Constant: '<S383>/Constant2'
   *  DataStoreRead: '<S383>/Data Store Read'
   *  Selector: '<S383>/Selector1'
   */
  VIPM_ICU_Info_CRCFlt_flg = (VBSW_CANComCRCInstFlt_flg[43] &&
    KIPM_ICUCRCChkEnbl_flg);

  /* Logic: '<S383>/Logical Operator2' incorporates:
   *  Constant: '<S383>/Cnst2'
   *  Constant: '<S383>/Constant3'
   *  DataStoreRead: '<S383>/Data Store Read'
   *  Selector: '<S383>/Selector2'
   */
  VIPM_TBOX_BJS_Time_CRCFlt_flg = (VBSW_CANComCRCInstFlt_flg[45] &&
    KIPM_TBOXCRCChkEnbl_flg);

  /* Logic: '<S383>/Logical Operator3' incorporates:
   *  Constant: '<S383>/Cnst3'
   *  Constant: '<S383>/Constant4'
   *  DataStoreRead: '<S383>/Data Store Read'
   *  Selector: '<S383>/Selector3'
   */
  VIPM_CCP_PanelStatus_CRCFlt_flg = (VBSW_CANComCRCInstFlt_flg[11] &&
    KIPM_CCPCRCChkEnbl_flg);

  /* Logic: '<S383>/Logical Operator4' incorporates:
   *  Constant: '<S383>/Cnst4'
   *  Constant: '<S383>/Constant5'
   *  DataStoreRead: '<S383>/Data Store Read'
   *  Selector: '<S383>/Selector4'
   */
  VIPM_COMP_AC_CRCFlt_flg = (VBSW_CANComCRCInstFlt_flg[16] &&
    KIPM_ACCMCRCChkEnbl_flg);

  /* Logic: '<S383>/Logical Operator5' incorporates:
   *  Constant: '<S383>/Cnst5'
   *  Constant: '<S383>/Constant6'
   *  DataStoreRead: '<S383>/Data Store Read'
   *  Selector: '<S383>/Selector5'
   */
  VIPM_HVCH_Status1_CRCFlt_flg = (VBSW_CANComCRCInstFlt_flg[18] &&
    KIPM_PTCCRCChkEnbl_flg);

  /* Logic: '<S383>/Logical Operator6' incorporates:
   *  Constant: '<S383>/Cnst6'
   *  Constant: '<S383>/Constant7'
   *  DataStoreRead: '<S383>/Data Store Read'
   *  Selector: '<S383>/Selector6'
   */
  VIPM_SCS_RiSwitchSts_CRCFlt_flg = (VBSW_CANComCRCInstFlt_flg[74] &&
    KIPM_SCSCRCChkEnbl_flg);

  /* Logic: '<S383>/Logical Operator7' incorporates:
   *  Constant: '<S383>/Cnst7'
   *  Constant: '<S383>/Constant8'
   *  DataStoreRead: '<S383>/Data Store Read'
   *  Selector: '<S383>/Selector7'
   */
  VIPM_CRRR_A_CRCFlt_flg = (VBSW_CANComCRCInstFlt_flg[9] &&
    KIPM_CRRRCRCChkEnbl_flg);

  /* Logic: '<S383>/Logical Operator8' incorporates:
   *  Constant: '<S383>/Cnst8'
   *  Constant: '<S383>/Constant9'
   *  DataStoreRead: '<S383>/Data Store Read'
   *  Selector: '<S383>/Selector8'
   */
  VIPM_EHB_B_CRCFlt_flg = (VBSW_CANComCRCInstFlt_flg[77] &&
    KIPM_EHBCRCChkEnbl_flg);

  /* Logic: '<S383>/Logical Operator9' incorporates:
   *  Constant: '<S383>/Cnst9'
   *  Constant: '<S383>/Constant10'
   *  DataStoreRead: '<S383>/Data Store Read'
   *  Selector: '<S383>/Selector9'
   */
  VIPM_EPS_2_StrWhlAng_CRCFlt_flg = (VBSW_CANComCRCInstFlt_flg[7] &&
    KIPM_EPSCRCChkEnbl_flg);

  /* Logic: '<S383>/Logical Operator10' incorporates:
   *  Constant: '<S383>/Cnst10'
   *  Constant: '<S383>/Constant11'
   *  DataStoreRead: '<S383>/Data Store Read'
   *  Selector: '<S383>/Selector10'
   */
  VIPM_ESC_7_FuncStatus_CRCFlt_flg = (VBSW_CANComCRCInstFlt_flg[76] &&
    KIPM_ESCCRCChkEnbl_flg);

  /* Logic: '<S383>/Logical Operator11' incorporates:
   *  Constant: '<S383>/Cnst11'
   *  Constant: '<S383>/Constant12'
   *  DataStoreRead: '<S383>/Data Store Read'
   *  Selector: '<S383>/Selector11'
   */
  VIPM_FCM_B_CRCFlt_flg = (VBSW_CANComCRCInstFlt_flg[81] &&
    KIPM_FCMCRCChkEnbl_flg);

  /* Logic: '<S383>/Logical Operator12' incorporates:
   *  Constant: '<S383>/Cnst12'
   *  Constant: '<S383>/Constant13'
   *  DataStoreRead: '<S383>/Data Store Read'
   *  Selector: '<S383>/Selector12'
   */
  VIPM_PP_InformAndStatus_CRCFlt_flg = (VBSW_CANComCRCInstFlt_flg[79] &&
    KIPM_PPCRCChkEnbl_flg);

  /* Logic: '<S383>/Logical Operator13' incorporates:
   *  Constant: '<S383>/Cnst13'
   *  Constant: '<S383>/Constant14'
   *  DataStoreRead: '<S383>/Data Store Read'
   *  Selector: '<S383>/Selector13'
   */
  VIPM_SRS_1_Status_CRCFlt_flg = (VBSW_CANComCRCInstFlt_flg[78] &&
    KIPM_SRSCRCChkEnbl_flg);

  /* Logic: '<S383>/Logical Operator14' incorporates:
   *  Constant: '<S383>/Cnst14'
   *  Constant: '<S383>/Constant15'
   *  DataStoreRead: '<S383>/Data Store Read'
   *  Selector: '<S383>/Selector14'
   */
  VIPM_BMS_2_BatState_CRCFlt_flg = (VBSW_CANComCRCInstFlt_flg[20] &&
    KIPM_BMSCRCChkEnbl_flg);

  /* Logic: '<S383>/Logical Operator15' incorporates:
   *  Constant: '<S383>/Cnst15'
   *  Constant: '<S383>/Constant16'
   *  DataStoreRead: '<S383>/Data Store Read'
   *  Selector: '<S383>/Selector15'
   */
  VIPM_INV_1_Value_CRCFlt_flg = (VBSW_CANComCRCInstFlt_flg[37] &&
    KIPM_INVCRCChkEnbl_flg);

  /* Logic: '<S383>/Logical Operator16' incorporates:
   *  Constant: '<S383>/Cnst16'
   *  Constant: '<S383>/Constant17'
   *  DataStoreRead: '<S383>/Data Store Read'
   *  Selector: '<S383>/Selector16'
   */
  VIPM_IPU_DCC_1_State_CRCFlt_flg = (VBSW_CANComCRCInstFlt_flg[32] &&
    KIPM_IPUCRCChkEnbl_flg);

  /* BusCreator: '<S383>/Bus Creator' incorporates:
   *  Logic: '<S383>/Logical Operator'
   *  Logic: '<S383>/Logical Operator1'
   *  Logic: '<S383>/Logical Operator10'
   *  Logic: '<S383>/Logical Operator11'
   *  Logic: '<S383>/Logical Operator12'
   *  Logic: '<S383>/Logical Operator13'
   *  Logic: '<S383>/Logical Operator14'
   *  Logic: '<S383>/Logical Operator15'
   *  Logic: '<S383>/Logical Operator16'
   *  Logic: '<S383>/Logical Operator2'
   *  Logic: '<S383>/Logical Operator3'
   *  Logic: '<S383>/Logical Operator4'
   *  Logic: '<S383>/Logical Operator5'
   *  Logic: '<S383>/Logical Operator6'
   *  Logic: '<S383>/Logical Operator7'
   *  Logic: '<S383>/Logical Operator8'
   *  Logic: '<S383>/Logical Operator9'
   */
  CANCommCRCFlt_outputs.VIPM_HU_B_CRCFlt_flg = VIPM_HU_B_CRCFlt_flg;
  CANCommCRCFlt_outputs.VIPM_ICU_Info_CRCFlt_flg = VIPM_ICU_Info_CRCFlt_flg;
  CANCommCRCFlt_outputs.VIPM_TBOX_BJS_Time_CRCFlt_flg =
    VIPM_TBOX_BJS_Time_CRCFlt_flg;
  CANCommCRCFlt_outputs.VIPM_CCP_PanelStatus_CRCFlt_flg =
    VIPM_CCP_PanelStatus_CRCFlt_flg;
  CANCommCRCFlt_outputs.VIPM_COMP_AC_CRCFlt_flg = VIPM_COMP_AC_CRCFlt_flg;
  CANCommCRCFlt_outputs.VIPM_HVCH_Status1_CRCFlt_flg =
    VIPM_HVCH_Status1_CRCFlt_flg;
  CANCommCRCFlt_outputs.VIPM_SCS_RiSwitchSts_CRCFlt_flg =
    VIPM_SCS_RiSwitchSts_CRCFlt_flg;
  CANCommCRCFlt_outputs.VIPM_CRRR_A_CRCFlt_flg = VIPM_CRRR_A_CRCFlt_flg;
  CANCommCRCFlt_outputs.VIPM_EHB_B_CRCFlt_flg = VIPM_EHB_B_CRCFlt_flg;
  CANCommCRCFlt_outputs.VIPM_EPS_2_StrWhlAng_CRCFlt_flg =
    VIPM_EPS_2_StrWhlAng_CRCFlt_flg;
  CANCommCRCFlt_outputs.VIPM_ESC_7_FuncStatus_CRCFlt_flg =
    VIPM_ESC_7_FuncStatus_CRCFlt_flg;
  CANCommCRCFlt_outputs.VIPM_FCM_B_CRCFlt_flg = VIPM_FCM_B_CRCFlt_flg;
  CANCommCRCFlt_outputs.VIPM_PP_InformAndStatus_CRCFlt_flg =
    VIPM_PP_InformAndStatus_CRCFlt_flg;
  CANCommCRCFlt_outputs.VIPM_SRS_1_Status_CRCFlt_flg =
    VIPM_SRS_1_Status_CRCFlt_flg;
  CANCommCRCFlt_outputs.VIPM_BMS_2_BatState_CRCFlt_flg =
    VIPM_BMS_2_BatState_CRCFlt_flg;
  CANCommCRCFlt_outputs.VIPM_INV_1_Value_CRCFlt_flg =
    VIPM_INV_1_Value_CRCFlt_flg;
  CANCommCRCFlt_outputs.VIPM_IPU_DCC_1_State_CRCFlt_flg =
    VIPM_IPU_DCC_1_State_CRCFlt_flg;

  /* SignalConversion: '<S6>/Signal Conversion1' */
  rtb_SignalConversion1 = CANCommCRCFlt_outputs;

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
    (&AppSwcIpm_ARID_DEF.MsgActv_outputs);

  /* Outport: '<Root>/CANCommCRCFlt_outputs' */
  Rte_IWrite_Runbl_IpmMsgActv_10ms_CANCommCRCFlt_outputs_CANCommCRCFlt_outputs
    (&CANCommCRCFlt_outputs);
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
    (&AppSwcIpm_ARID_DEF.IPM_INV_1_Value_EPT);

  /* Outport: '<Root>/IPM_INV_2_Value_EPT' */
  Rte_IWrite_Runbl_IpmCanRx_10ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT
    (&AppSwcIpm_ARID_DEF.IPM_INV_2_Value_EPT);

  /* Outport: '<Root>/IPM_INV_3_Value_EPT' */
  Rte_IWrite_Runbl_IpmCanRx_10ms_IPM_INV_3_Value_EPT_IPM_INV_3_Value_EPT
    (&AppSwcIpm_ARID_DEF.IPM_INV_3_Value_EPT);

  /* Outport: '<Root>/IPM_INV_4_Value_EPT' */
  Rte_IWrite_Runbl_IpmCanRx_10ms_IPM_INV_4_Value_EPT_IPM_INV_4_Value_EPT
    (&AppSwcIpm_ARID_DEF.IPM_INV_4_Value_EPT);

  /* Outport: '<Root>/IPM_EPS_2_StrWhlAng_CHA' */
  Rte_IWrite_Runbl_IpmCanRx_10ms_IPM_EPS_2_StrWhlAng_CHA_IPM_EPS_2_StrWhlAng_CHA
    (&AppSwcIpm_ARID_DEF.IPM_EPS_2_StrWhlAng_CHA);

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
    (&AppSwcIpm_ARID_DEF.IPM_BMS_2_BatState_EPT);

  /* Outport: '<Root>/IPM_BMS_3_DC_ChargeState_EPT' */
  Rte_IWrite_Runbl_IpmCanRx_20ms_IPM_BMS_3_DC_ChargeState_EPT_IPM_BMS_3_DC_ChargeState_EPT
    (&AppSwcIpm_ARID_DEF.IPM_BMS_3_DC_ChargeState_EPT);

  /* Outport: '<Root>/IPM_BMS_6_DischrgRecup_EPT' */
  Rte_IWrite_Runbl_IpmCanRx_20ms_IPM_BMS_6_DischrgRecup_EPT_IPM_BMS_6_DischrgRecup_EPT
    (&AppSwcIpm_ARID_DEF.IPM_BMS_6_DischrgRecup_EPT);

  /* Outport: '<Root>/IPM_BMS_7_CellVolt_EPT' */
  Rte_IWrite_Runbl_IpmCanRx_20ms_IPM_BMS_7_CellVolt_EPT_IPM_BMS_7_CellVolt_EPT
    (&AppSwcIpm_ARID_DEF.IPM_BMS_7_CellVolt_EPT);

  /* Outport: '<Root>/IPM_BMS_10_DC_ChargeStates_EPT' */
  Rte_IWrite_Runbl_IpmCanRx_20ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT
    (&AppSwcIpm_ARID_DEF.IPM_BMS_10_DC_ChargeStates_EPT);

  /* Outport: '<Root>/IPM_BMS_4_AC_ChargeState_EPT' */
  Rte_IWrite_Runbl_IpmCanRx_20ms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT
    (&AppSwcIpm_ARID_DEF.IPM_BMS_4_AC_ChargeState_EPT);

  /* Outport: '<Root>/IPM_EHB_A_CHA' */
  Rte_IWrite_Runbl_IpmCanRx_20ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA
    (&AppSwcIpm_ARID_DEF.IPM_EHB_A_CHA);

  /* Outport: '<Root>/IPM_FCM_B_CHA' */
  Rte_IWrite_Runbl_IpmCanRx_20ms_IPM_FCM_B_CHA_IPM_FCM_B_CHA
    (&AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA);

  /* Outport: '<Root>/IPM_CRRR_A_CHA' */
  Rte_IWrite_Runbl_IpmCanRx_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA
    (&AppSwcIpm_ARID_DEF.IPM_CRRR_A_CHA);

  /* Outport: '<Root>/IPM_SCS_RiSwitchSts_BOD' */
  Rte_IWrite_Runbl_IpmCanRx_20ms_IPM_SCS_RiSwitchSts_BOD_IPM_SCS_RiSwitchSts_BOD
    (&AppSwcIpm_ARID_DEF.IPM_SCS_RiSwitchSts_BOD);
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
    (&AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_k);

  /* Outport: '<Root>/IPM_ESCL_ESCLStatus_BOD' incorporates:
   *  BusCreator: '<S348>/BusCreator'
   */
  Rte_IWrite_Runbl_IpmCanRx_50ms_IPM_ESCL_ESCLStatus_BOD_IPM_ESCL_ESCLStatus_BOD
    (&AppSwcIpm_ARID_DEF.IPM_ESCL_ESCLStatus_BOD);

  /* Outport: '<Root>/IPM_SCS_LeSwitchSts_BOD' */
  Rte_IWrite_Runbl_IpmCanRx_50ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
    (&AppSwcIpm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD);

  /* Outport: '<Root>/IPM_SRS_1_Status_CHA' */
  Rte_IWrite_Runbl_IpmCanRx_50ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA
    (&AppSwcIpm_ARID_DEF.IPM_SRS_1_Status_CHA);
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
    (&AppSwcIpm_ARID_DEF.IPM_BMS_5_BatTemp_EPT);

  /* Outport: '<Root>/IPM_IPU_OBC_1_State_EPT' */
  Rte_IWrite_Runbl_IpmCanRx_100ms_IPM_IPU_OBC_1_State_EPT_IPM_IPU_OBC_1_State_EPT
    (&AppSwcIpm_ARID_DEF.IPM_IPU_OBC_1_State_EPT);

  /* Outport: '<Root>/IPM_IPU_DCC_1_State_EPT' */
  Rte_IWrite_Runbl_IpmCanRx_100ms_IPM_IPU_DCC_1_State_EPT_IPM_IPU_DCC_1_State_EPT
    (&AppSwcIpm_ARID_DEF.IPM_IPU_DCC_1_State_EPT);

  /* Outport: '<Root>/IPM_IPU_DCC_2_ChrgInValue_EPT' */
  Rte_IWrite_Runbl_IpmCanRx_100ms_IPM_IPU_DCC_2_ChrgInValue_EPT_IPM_IPU_DCC_2_ChrgInValue_EPT
    (&AppSwcIpm_ARID_DEF.IPM_IPU_DCC_2_ChrgInValue_EPT);

  /* Outport: '<Root>/IPM_INV_IMMO_Req_EPT' */
  Rte_IWrite_Runbl_IpmCanRx_100ms_IPM_INV_IMMO_Req_EPT_IPM_INV_IMMO_Req_EPT
    (&AppSwcIpm_ARID_DEF.IPM_INV_IMMO_Req_EPT_g);

  /* Outport: '<Root>/IPM_IPU_OBC_2_Inlet_EPT' */
  Rte_IWrite_Runbl_IpmCanRx_100ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT
    (&AppSwcIpm_ARID_DEF.IPM_IPU_OBC_2_Inlet_EPT);

  /* Outport: '<Root>/IPM_BMS_9_BattInfo_EPT' */
  Rte_IWrite_Runbl_IpmCanRx_100ms_IPM_BMS_9_BattInfo_EPT_IPM_BMS_9_BattInfo_EPT(
    &AppSwcIpm_ARID_DEF.IPM_BMS_9_BattInfo_EPT);

  /* Outport: '<Root>/IPM_HU_B_BAC' */
  Rte_IWrite_Runbl_IpmCanRx_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC
    (&AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m);

  /* Outport: '<Root>/IPM_TBOX_BJS_Time_BAC' */
  Rte_IWrite_Runbl_IpmCanRx_100ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC
    (&AppSwcIpm_ARID_DEF.IPM_TBOX_BJS_Time_BAC);

  /* Outport: '<Root>/IPM_COMP_AC_BOD' */
  Rte_IWrite_Runbl_IpmCanRx_100ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD
    (&AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD);

  /* Outport: '<Root>/IPM_HVCH_Status1_BOD' */
  Rte_IWrite_Runbl_IpmCanRx_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD
    (&AppSwcIpm_ARID_DEF.IPM_HVCH_Status1_BOD);

  /* Outport: '<Root>/IPM_HVCH_Status2_BOD' */
  Rte_IWrite_Runbl_IpmCanRx_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD
    (&AppSwcIpm_ARID_DEF.IPM_HVCH_Status2_BOD);

  /* Outport: '<Root>/IPM_ACCM_Version_BOD' */
  Rte_IWrite_Runbl_IpmCanRx_100ms_IPM_ACCM_Version_BOD_IPM_ACCM_Version_BOD
    (&AppSwcIpm_ARID_DEF.IPM_ACCM_Version_BOD);

  /* Outport: '<Root>/IPM_ICU_2_Odo_BAC' */
  Rte_IWrite_Runbl_IpmCanRx_100ms_IPM_ICU_2_Odo_BAC_IPM_ICU_2_Odo_BAC
    (&AppSwcIpm_ARID_DEF.IPM_ICU_2_Odo_BAC);
}

/* Model initialize function */
void AppSwcIpm_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
