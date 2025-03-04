/*
 * File: AppSwcOpm.c
 *
 * Code generated for Simulink model 'AppSwcOpm'.
 *
 * Model version                  : 9.103
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Dec 17 18:02:01 2024
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "AppSwcOpm.h"
#include "rtwtypes.h"
#include "Rte_Type.h"
#include "calPrmsOpm.h"
#include "monPrmsOpm.h"
#include "AppSwcOpm_types.h"
#include "PEPS_ABI.h"

/* PublicStructure Variables for Internal Data */
ARID_DEF_AppSwcOpm_T AppSwcOpm_ARID_DEF;
static void Runbl_Opm100ms(void);
static void Runbl_Opm10ms(void);
static void Runbl_Opm20ms(void);
static void Runbl_Opm50ms(void);

/* Output and update for function-call system: '<Root>/Opm100ms' */
static void Runbl_Opm100ms(void)
{
  float32 tmp;

  /* Outputs for Atomic SubSystem: '<S145>/Subsys_VOPM_BCMLrngsubID_cnt' */
  /* Switch: '<S153>/Switch4' incorporates:
   *  Constant: '<S153>/sat3'
   */
  if (KOPM_BCMLrngsubID_cnt_ovrdflg)
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Constant: '<S153>/sat4'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum = KOPM_BCMLrngsubID_cnt_ovrdval;
  }
  else
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Inport: '<Root>/Bcm2OpmEPT_outputs'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum =
        (Rte_IRead_Runbl_OpmCanTx_100ms_Bcm2OpmEPT_outputs_Bcm2OpmEPT_outputs())
            ->BCM_Learning_subID;
  }

  /* End of Switch: '<S153>/Switch4' */

  /* MinMax: '<S153>/MinMax' incorporates:
   *  Constant: '<S153>/sat6'
   */
  if (VOPM_TMSC3WVMode_enum > KOPM_BCMLrngsubIDHi_cnt)
  {
    VOPM_TMSC3WVMode_enum = KOPM_BCMLrngsubIDHi_cnt;
  }

  /* MinMax: '<S153>/MinMax1' incorporates:
   *  Constant: '<S153>/sat7'
   */
  if (VOPM_TMSC3WVMode_enum >= KOPM_BCMLrngsubIDLo_cnt)
  {
    /* MinMax: '<S153>/MinMax1' */
    VOPM_BCMLrngsubID_cnt = VOPM_TMSC3WVMode_enum;
  }
  else
  {
    /* MinMax: '<S153>/MinMax1' */
    VOPM_BCMLrngsubID_cnt = KOPM_BCMLrngsubIDLo_cnt;
  }

  /* End of MinMax: '<S153>/MinMax1' */
  /* End of Outputs for SubSystem: '<S145>/Subsys_VOPM_BCMLrngsubID_cnt' */

  /* Outputs for Atomic SubSystem: '<S145>/Subsys_VOPM_BCMLrngSts_enum' */
  /* Switch: '<S152>/Switch4' incorporates:
   *  Constant: '<S152>/sat3'
   */
  if (KOPM_BCMLrngSts_enum_ovrdflg)
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Constant: '<S152>/sat4'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum = KOPM_BCMLrngSts_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Inport: '<Root>/Bcm2OpmEPT_outputs'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum =
        (Rte_IRead_Runbl_OpmCanTx_100ms_Bcm2OpmEPT_outputs_Bcm2OpmEPT_outputs())
            ->BCM_Learning_Status;
  }

  /* End of Switch: '<S152>/Switch4' */

  /* MinMax: '<S152>/MinMax' incorporates:
   *  Constant: '<S152>/sat6'
   */
  if (VOPM_TMSC3WVMode_enum > KOPM_BCMLrngStsHi_enum)
  {
    /* MinMax: '<S153>/MinMax' */
    VOPM_TMSC3WVMode_enum = KOPM_BCMLrngStsHi_enum;
  }

  /* End of MinMax: '<S152>/MinMax' */

  /* MinMax: '<S152>/MinMax1' incorporates:
   *  Constant: '<S152>/sat7'
   */
  if (VOPM_TMSC3WVMode_enum >= KOPM_BCMLrngStsLo_enum)
  {
    /* MinMax: '<S152>/MinMax1' */
    VOPM_BCMLrngSts_enum = VOPM_TMSC3WVMode_enum;
  }
  else
  {
    /* MinMax: '<S152>/MinMax1' */
    VOPM_BCMLrngSts_enum = KOPM_BCMLrngStsLo_enum;
  }

  /* End of MinMax: '<S152>/MinMax1' */
  /* End of Outputs for SubSystem: '<S145>/Subsys_VOPM_BCMLrngSts_enum' */

  /* Outputs for Atomic SubSystem: '<S145>/Subsys_VOPM_BCMLrngData02_nu' */
  /* Switch: '<S146>/Switch4' incorporates:
   *  Constant: '<S146>/sat3'
   */
  if (KOPM_BCMLrngData02_nu_ovrdflg)
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Constant: '<S146>/sat4'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum = KOPM_BCMLrngData02_nu_ovrdval;
  }
  else
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Inport: '<Root>/Bcm2OpmEPT_outputs'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum =
        (Rte_IRead_Runbl_OpmCanTx_100ms_Bcm2OpmEPT_outputs_Bcm2OpmEPT_outputs())
            ->BCM_Learning_Data_02;
  }

  /* End of Switch: '<S146>/Switch4' */

  /* MinMax: '<S146>/MinMax' incorporates:
   *  Constant: '<S146>/sat6'
   */
  if (VOPM_TMSC3WVMode_enum > KOPM_BCMLrngData02Hi_nu)
  {
    /* MinMax: '<S153>/MinMax' */
    VOPM_TMSC3WVMode_enum = KOPM_BCMLrngData02Hi_nu;
  }

  /* End of MinMax: '<S146>/MinMax' */

  /* MinMax: '<S146>/MinMax1' incorporates:
   *  Constant: '<S146>/sat7'
   */
  if (VOPM_TMSC3WVMode_enum >= KOPM_BCMLrngData02Lo_nu)
  {
    /* MinMax: '<S146>/MinMax1' */
    VOPM_BCMLrngData02_nu = VOPM_TMSC3WVMode_enum;
  }
  else
  {
    /* MinMax: '<S146>/MinMax1' */
    VOPM_BCMLrngData02_nu = KOPM_BCMLrngData02Lo_nu;
  }

  /* End of MinMax: '<S146>/MinMax1' */
  /* End of Outputs for SubSystem: '<S145>/Subsys_VOPM_BCMLrngData02_nu' */

  /* Outputs for Atomic SubSystem: '<S145>/Subsys_VOPM_BCMLrngData03_nu' */
  /* Switch: '<S147>/Switch4' incorporates:
   *  Constant: '<S147>/sat3'
   */
  if (KOPM_BCMLrngData03_nu_ovrdflg)
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Constant: '<S147>/sat4'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum = KOPM_BCMLrngData03_nu_ovrdval;
  }
  else
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Inport: '<Root>/Bcm2OpmEPT_outputs'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum =
        (Rte_IRead_Runbl_OpmCanTx_100ms_Bcm2OpmEPT_outputs_Bcm2OpmEPT_outputs())
            ->BCM_Learning_Data_03;
  }

  /* End of Switch: '<S147>/Switch4' */

  /* MinMax: '<S147>/MinMax' incorporates:
   *  Constant: '<S147>/sat6'
   */
  if (VOPM_TMSC3WVMode_enum > KOPM_BCMLrngData03Hi_nu)
  {
    /* MinMax: '<S153>/MinMax' */
    VOPM_TMSC3WVMode_enum = KOPM_BCMLrngData03Hi_nu;
  }

  /* End of MinMax: '<S147>/MinMax' */

  /* MinMax: '<S147>/MinMax1' incorporates:
   *  Constant: '<S147>/sat7'
   */
  if (VOPM_TMSC3WVMode_enum >= KOPM_BCMLrngData03Lo_nu)
  {
    /* MinMax: '<S147>/MinMax1' */
    VOPM_BCMLrngData03_nu = VOPM_TMSC3WVMode_enum;
  }
  else
  {
    /* MinMax: '<S147>/MinMax1' */
    VOPM_BCMLrngData03_nu = KOPM_BCMLrngData03Lo_nu;
  }

  /* End of MinMax: '<S147>/MinMax1' */
  /* End of Outputs for SubSystem: '<S145>/Subsys_VOPM_BCMLrngData03_nu' */

  /* Outputs for Atomic SubSystem: '<S145>/Subsys_VOPM_BCMLrngData04_nu' */
  /* Switch: '<S148>/Switch4' incorporates:
   *  Constant: '<S148>/sat3'
   */
  if (KOPM_BCMLrngData04_nu_ovrdflg)
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Constant: '<S148>/sat4'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum = KOPM_BCMLrngData04_nu_ovrdval;
  }
  else
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Inport: '<Root>/Bcm2OpmEPT_outputs'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum =
        (Rte_IRead_Runbl_OpmCanTx_100ms_Bcm2OpmEPT_outputs_Bcm2OpmEPT_outputs())
            ->BCM_Learning_Data_04;
  }

  /* End of Switch: '<S148>/Switch4' */

  /* MinMax: '<S148>/MinMax' incorporates:
   *  Constant: '<S148>/sat6'
   */
  if (VOPM_TMSC3WVMode_enum > KOPM_BCMLrngData04Hi_nu)
  {
    /* MinMax: '<S153>/MinMax' */
    VOPM_TMSC3WVMode_enum = KOPM_BCMLrngData04Hi_nu;
  }

  /* End of MinMax: '<S148>/MinMax' */

  /* MinMax: '<S148>/MinMax1' incorporates:
   *  Constant: '<S148>/sat7'
   */
  if (VOPM_TMSC3WVMode_enum >= KOPM_BCMLrngData04Lo_nu)
  {
    /* MinMax: '<S148>/MinMax1' */
    VOPM_BCMLrngData04_nu = VOPM_TMSC3WVMode_enum;
  }
  else
  {
    /* MinMax: '<S148>/MinMax1' */
    VOPM_BCMLrngData04_nu = KOPM_BCMLrngData04Lo_nu;
  }

  /* End of MinMax: '<S148>/MinMax1' */
  /* End of Outputs for SubSystem: '<S145>/Subsys_VOPM_BCMLrngData04_nu' */

  /* Outputs for Atomic SubSystem: '<S145>/Subsys_VOPM_BCMLrngData05_nu' */
  /* Switch: '<S149>/Switch4' incorporates:
   *  Constant: '<S149>/sat3'
   */
  if (KOPM_BCMLrngData05_nu_ovrdflg)
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Constant: '<S149>/sat4'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum = KOPM_BCMLrngData05_nu_ovrdval;
  }
  else
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Inport: '<Root>/Bcm2OpmEPT_outputs'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum =
        (Rte_IRead_Runbl_OpmCanTx_100ms_Bcm2OpmEPT_outputs_Bcm2OpmEPT_outputs())
            ->BCM_Learning_Data_05;
  }

  /* End of Switch: '<S149>/Switch4' */

  /* MinMax: '<S149>/MinMax' incorporates:
   *  Constant: '<S149>/sat6'
   */
  if (VOPM_TMSC3WVMode_enum > KOPM_BCMLrngData05Hi_nu)
  {
    /* MinMax: '<S153>/MinMax' */
    VOPM_TMSC3WVMode_enum = KOPM_BCMLrngData05Hi_nu;
  }

  /* End of MinMax: '<S149>/MinMax' */

  /* MinMax: '<S149>/MinMax1' incorporates:
   *  Constant: '<S149>/sat7'
   */
  if (VOPM_TMSC3WVMode_enum >= KOPM_BCMLrngData05Lo_nu)
  {
    /* MinMax: '<S149>/MinMax1' */
    VOPM_BCMLrngData05_nu = VOPM_TMSC3WVMode_enum;
  }
  else
  {
    /* MinMax: '<S149>/MinMax1' */
    VOPM_BCMLrngData05_nu = KOPM_BCMLrngData05Lo_nu;
  }

  /* End of MinMax: '<S149>/MinMax1' */
  /* End of Outputs for SubSystem: '<S145>/Subsys_VOPM_BCMLrngData05_nu' */

  /* Outputs for Atomic SubSystem: '<S145>/Subsys_VOPM_BCMLrngData06_nu' */
  /* Switch: '<S150>/Switch4' incorporates:
   *  Constant: '<S150>/sat3'
   */
  if (KOPM_BCMLrngData06_nu_ovrdflg)
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Constant: '<S150>/sat4'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum = KOPM_BCMLrngData06_nu_ovrdval;
  }
  else
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Inport: '<Root>/Bcm2OpmEPT_outputs'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum =
        (Rte_IRead_Runbl_OpmCanTx_100ms_Bcm2OpmEPT_outputs_Bcm2OpmEPT_outputs())
            ->BCM_Learning_Data_06;
  }

  /* End of Switch: '<S150>/Switch4' */

  /* MinMax: '<S150>/MinMax' incorporates:
   *  Constant: '<S150>/sat6'
   */
  if (VOPM_TMSC3WVMode_enum > KOPM_BCMLrngData06Hi_nu)
  {
    /* MinMax: '<S153>/MinMax' */
    VOPM_TMSC3WVMode_enum = KOPM_BCMLrngData06Hi_nu;
  }

  /* End of MinMax: '<S150>/MinMax' */

  /* MinMax: '<S150>/MinMax1' incorporates:
   *  Constant: '<S150>/sat7'
   */
  if (VOPM_TMSC3WVMode_enum >= KOPM_BCMLrngData06Lo_nu)
  {
    /* MinMax: '<S150>/MinMax1' */
    VOPM_BCMLrngData06_nu = VOPM_TMSC3WVMode_enum;
  }
  else
  {
    /* MinMax: '<S150>/MinMax1' */
    VOPM_BCMLrngData06_nu = KOPM_BCMLrngData06Lo_nu;
  }

  /* End of MinMax: '<S150>/MinMax1' */
  /* End of Outputs for SubSystem: '<S145>/Subsys_VOPM_BCMLrngData06_nu' */

  /* Outputs for Atomic SubSystem: '<S145>/Subsys_VOPM_BCMLrngData07_nu' */
  /* Switch: '<S151>/Switch4' incorporates:
   *  Constant: '<S151>/sat3'
   */
  if (KOPM_BCMLrngData07_nu_ovrdflg)
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Constant: '<S151>/sat4'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum = KOPM_BCMLrngData07_nu_ovrdval;
  }
  else
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Inport: '<Root>/Bcm2OpmEPT_outputs'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum =
        (Rte_IRead_Runbl_OpmCanTx_100ms_Bcm2OpmEPT_outputs_Bcm2OpmEPT_outputs())
            ->BCM_Learning_Data_07;
  }

  /* End of Switch: '<S151>/Switch4' */

  /* MinMax: '<S151>/MinMax' incorporates:
   *  Constant: '<S151>/sat6'
   */
  if (VOPM_TMSC3WVMode_enum > KOPM_BCMLrngData07Hi_nu)
  {
    /* MinMax: '<S153>/MinMax' */
    VOPM_TMSC3WVMode_enum = KOPM_BCMLrngData07Hi_nu;
  }

  /* End of MinMax: '<S151>/MinMax' */

  /* MinMax: '<S151>/MinMax1' incorporates:
   *  Constant: '<S151>/sat7'
   */
  if (VOPM_TMSC3WVMode_enum >= KOPM_BCMLrngData07Lo_nu)
  {
    /* MinMax: '<S151>/MinMax1' */
    VOPM_BCMLrngData07_nu = VOPM_TMSC3WVMode_enum;
  }
  else
  {
    /* MinMax: '<S151>/MinMax1' */
    VOPM_BCMLrngData07_nu = KOPM_BCMLrngData07Lo_nu;
  }

  /* End of MinMax: '<S151>/MinMax1' */
  /* End of Outputs for SubSystem: '<S145>/Subsys_VOPM_BCMLrngData07_nu' */

  /* BusCreator: '<S145>/BusCreator' */
  AppSwcOpm_ARID_DEF.BCM_IMMOAuthResp1_EPT_n.BCM_Learning_subID =
      VOPM_BCMLrngsubID_cnt;
  AppSwcOpm_ARID_DEF.BCM_IMMOAuthResp1_EPT_n.BCM_Learning_Status =
      VOPM_BCMLrngSts_enum;
  AppSwcOpm_ARID_DEF.BCM_IMMOAuthResp1_EPT_n.BCM_Learning_Data_02 =
      VOPM_BCMLrngData02_nu;
  AppSwcOpm_ARID_DEF.BCM_IMMOAuthResp1_EPT_n.BCM_Learning_Data_03 =
      VOPM_BCMLrngData03_nu;
  AppSwcOpm_ARID_DEF.BCM_IMMOAuthResp1_EPT_n.BCM_Learning_Data_04 =
      VOPM_BCMLrngData04_nu;
  AppSwcOpm_ARID_DEF.BCM_IMMOAuthResp1_EPT_n.BCM_Learning_Data_05 =
      VOPM_BCMLrngData05_nu;
  AppSwcOpm_ARID_DEF.BCM_IMMOAuthResp1_EPT_n.BCM_Learning_Data_06 =
      VOPM_BCMLrngData06_nu;
  AppSwcOpm_ARID_DEF.BCM_IMMOAuthResp1_EPT_n.BCM_Learning_Data_07 =
      VOPM_BCMLrngData07_nu;

  /* Outputs for Atomic SubSystem: '<S27>/Subsys_VOPM_ACCompMaxAllowPwrCmsp_kW' */
  /* Switch: '<S39>/Switch4' incorporates:
   *  Constant: '<S39>/sat3'
   */
  if (KOPM_ACCompMaxAllowPwrCmsp_kW_ovrdflg)
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Constant: '<S39>/sat4'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_ACCompMaxAllowPwrCmsp_kW_ovrdval;
  }
  else
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Inport: '<Root>/TMS2VCU_AC_1_Command_Outputs'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_1_Command_Outputs_TMS2VCU_AC_1_Command_Outputs())->AC_CompMaxAllowPwrCmsp;
  }

  /* End of Switch: '<S39>/Switch4' */

  /* MinMax: '<S39>/MinMax' incorporates:
   *  Constant: '<S39>/sat6'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm > KOPM_ACCompMaxAllowPwrCmspHi_kW)
  {
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_ACCompMaxAllowPwrCmspHi_kW;
  }

  /* MinMax: '<S39>/MinMax1' incorporates:
   *  Constant: '<S39>/sat7'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm >= KOPM_ACCompMaxAllowPwrCmspLo_kW)
  {
    /* MinMax: '<S39>/MinMax1' */
    VOPM_ACCompMaxAllowPwrCmsp_kW = VOPM_TMSAcPMPRealRPM_rpm;
  }
  else
  {
    /* MinMax: '<S39>/MinMax1' */
    VOPM_ACCompMaxAllowPwrCmsp_kW = KOPM_ACCompMaxAllowPwrCmspLo_kW;
  }

  /* End of MinMax: '<S39>/MinMax1' */
  /* End of Outputs for SubSystem: '<S27>/Subsys_VOPM_ACCompMaxAllowPwrCmsp_kW' */

  /* Outputs for Atomic SubSystem: '<S27>/Subsys_VOPM_ACCompFailModeOprtSta_flg' */
  /* Switch: '<S38>/Switch4' incorporates:
   *  Constant: '<S38>/sat3'
   */
  if (KOPM_ACCompFailModeOprtSta_flg_ovrdflg)
  {
    /* Switch: '<S38>/Switch4' incorporates:
     *  Constant: '<S38>/sat4'
     */
    VOPM_ACCompFailModeOprtSta_flg = KOPM_ACCompFailModeOprtSta_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S38>/Switch4' incorporates:
     *  Inport: '<Root>/TMS2VCU_AC_1_Command_Outputs'
     */
    VOPM_ACCompFailModeOprtSta_flg =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_1_Command_Outputs_TMS2VCU_AC_1_Command_Outputs())->AC_CompFailModeOprtSta;
  }

  /* End of Switch: '<S38>/Switch4' */
  /* End of Outputs for SubSystem: '<S27>/Subsys_VOPM_ACCompFailModeOprtSta_flg' */

  /* Outputs for Atomic SubSystem: '<S27>/Subsys_VOPM_ACCompOprtReq_flg' */
  /* Switch: '<S41>/Switch4' incorporates:
   *  Constant: '<S41>/sat3'
   */
  if (KOPM_ACCompOprtReq_flg_ovrdflg)
  {
    /* Switch: '<S41>/Switch4' incorporates:
     *  Constant: '<S41>/sat4'
     */
    VOPM_ACCompOprtReq_flg = KOPM_ACCompOprtReq_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S41>/Switch4' incorporates:
     *  Inport: '<Root>/TMS2VCU_AC_1_Command_Outputs'
     */
    VOPM_ACCompOprtReq_flg =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_1_Command_Outputs_TMS2VCU_AC_1_Command_Outputs())->AC_CompOprtReq;
  }

  /* End of Switch: '<S41>/Switch4' */
  /* End of Outputs for SubSystem: '<S27>/Subsys_VOPM_ACCompOprtReq_flg' */

  /* Outputs for Atomic SubSystem: '<S27>/Subsys_VOPM_ACCompOprtEnaCmd_flg' */
  /* Switch: '<S40>/Switch4' incorporates:
   *  Constant: '<S40>/sat3'
   */
  if (KOPM_ACCompOprtEnaCmd_flg_ovrdflg)
  {
    /* Switch: '<S40>/Switch4' incorporates:
     *  Constant: '<S40>/sat4'
     */
    VOPM_ACCompOprtEnaCmd_flg = KOPM_ACCompOprtEnaCmd_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S40>/Switch4' incorporates:
     *  Inport: '<Root>/TMS2VCU_AC_1_Command_Outputs'
     */
    VOPM_ACCompOprtEnaCmd_flg =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_1_Command_Outputs_TMS2VCU_AC_1_Command_Outputs())->AC_CompOprtEnaCmd;
  }

  /* End of Switch: '<S40>/Switch4' */
  /* End of Outputs for SubSystem: '<S27>/Subsys_VOPM_ACCompOprtEnaCmd_flg' */

  /* Outputs for Atomic SubSystem: '<S27>/Subsys_VOPM_ACCompTgtSpd_rpm' */
  /* Switch: '<S42>/Switch4' incorporates:
   *  Constant: '<S42>/sat3'
   */
  if (KOPM_ACCompTgtSpd_rpm_ovrdflg)
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Constant: '<S42>/sat4'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_ACCompTgtSpd_rpm_ovrdval;
  }
  else
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  DataTypeConversion: '<S42>/Data Type Conversion1'
     *  Inport: '<Root>/TMS2VCU_AC_1_Command_Outputs'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm = (float32)(Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_1_Command_Outputs_TMS2VCU_AC_1_Command_Outputs())->AC_CompTgtSpd;
  }

  /* End of Switch: '<S42>/Switch4' */

  /* MinMax: '<S42>/MinMax' incorporates:
   *  Constant: '<S42>/sat6'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm > KOPM_ACCompTgtSpdHi_rpm)
  {
    /* MinMax: '<S39>/MinMax' */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_ACCompTgtSpdHi_rpm;
  }

  /* End of MinMax: '<S42>/MinMax' */

  /* MinMax: '<S42>/MinMax1' incorporates:
   *  Constant: '<S42>/sat7'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm >= KOPM_ACCompTgtSpdLo_rpm)
  {
    /* MinMax: '<S42>/MinMax1' */
    VOPM_ACCompTgtSpd_rpm = VOPM_TMSAcPMPRealRPM_rpm;
  }
  else
  {
    /* MinMax: '<S42>/MinMax1' */
    VOPM_ACCompTgtSpd_rpm = KOPM_ACCompTgtSpdLo_rpm;
  }

  /* End of MinMax: '<S42>/MinMax1' */
  /* End of Outputs for SubSystem: '<S27>/Subsys_VOPM_ACCompTgtSpd_rpm' */

  /* DataTypeConversion: '<S27>/DataTypeConversion3' */
  if (VOPM_ACCompTgtSpd_rpm < 65536.0F)
  {
    if (VOPM_ACCompTgtSpd_rpm >= 0.0F)
    {
      AppSwcOpm_ARID_DEF.AC_1_Command_BOD_n.AC_CompTgtSpd = (uint16)
          VOPM_ACCompTgtSpd_rpm;
    }
    else
    {
      AppSwcOpm_ARID_DEF.AC_1_Command_BOD_n.AC_CompTgtSpd = 0U;
    }
  }
  else
  {
    AppSwcOpm_ARID_DEF.AC_1_Command_BOD_n.AC_CompTgtSpd = MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<S27>/DataTypeConversion3' */

  /* Outputs for Atomic SubSystem: '<S27>/Subsys_VOPM_ACPumpActlSpdDuty_pct' */
  /* Switch: '<S45>/Switch4' incorporates:
   *  Constant: '<S45>/sat3'
   */
  if (KOPM_ACPumpActlSpdDuty_pct_ovrdflg)
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Constant: '<S45>/sat4'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum = KOPM_ACPumpActlSpdDuty_pct_ovrdval;
  }
  else
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Inport: '<Root>/TMS2VCU_AC_1_Command_Outputs'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_1_Command_Outputs_TMS2VCU_AC_1_Command_Outputs())->AC_PumpActlSpdDuty;
  }

  /* End of Switch: '<S45>/Switch4' */

  /* MinMax: '<S45>/MinMax' incorporates:
   *  Constant: '<S45>/sat6'
   */
  if (VOPM_TMSC3WVMode_enum > KOPM_ACPumpActlSpdDutyHi_pct)
  {
    /* MinMax: '<S153>/MinMax' */
    VOPM_TMSC3WVMode_enum = KOPM_ACPumpActlSpdDutyHi_pct;
  }

  /* End of MinMax: '<S45>/MinMax' */

  /* MinMax: '<S45>/MinMax1' incorporates:
   *  Constant: '<S45>/sat7'
   */
  if (VOPM_TMSC3WVMode_enum >= KOPM_ACPumpActlSpdDutyLo_pct)
  {
    /* MinMax: '<S45>/MinMax1' */
    VOPM_ACPumpActlSpdDuty_pct = VOPM_TMSC3WVMode_enum;
  }
  else
  {
    /* MinMax: '<S45>/MinMax1' */
    VOPM_ACPumpActlSpdDuty_pct = KOPM_ACPumpActlSpdDutyLo_pct;
  }

  /* End of MinMax: '<S45>/MinMax1' */
  /* End of Outputs for SubSystem: '<S27>/Subsys_VOPM_ACPumpActlSpdDuty_pct' */

  /* Outputs for Atomic SubSystem: '<S27>/Subsys_VOPM_ACHighVolDCTotalPwr_kW' */
  /* Switch: '<S43>/Switch4' incorporates:
   *  Constant: '<S43>/sat3'
   */
  if (KOPM_ACHighVolDCTotalPwr_kW_ovrdflg)
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Constant: '<S43>/sat4'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_ACHighVolDCTotalPwr_kW_ovrdval;
  }
  else
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Inport: '<Root>/TMS2VCU_AC_1_Command_Outputs'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_1_Command_Outputs_TMS2VCU_AC_1_Command_Outputs())->AC_HighVolDCTolalPwr;
  }

  /* End of Switch: '<S43>/Switch4' */

  /* MinMax: '<S43>/MinMax' incorporates:
   *  Constant: '<S43>/sat6'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm > KOPM_ACHighVolDCTotalPwrHi_kW)
  {
    /* MinMax: '<S39>/MinMax' */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_ACHighVolDCTotalPwrHi_kW;
  }

  /* End of MinMax: '<S43>/MinMax' */

  /* MinMax: '<S43>/MinMax1' incorporates:
   *  Constant: '<S43>/sat7'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm >= KOPM_ACHighVolDCTotalPwrLo_kW)
  {
    /* MinMax: '<S43>/MinMax1' */
    VOPM_ACHighVolDCTotalPwr_kW = VOPM_TMSAcPMPRealRPM_rpm;
  }
  else
  {
    /* MinMax: '<S43>/MinMax1' */
    VOPM_ACHighVolDCTotalPwr_kW = KOPM_ACHighVolDCTotalPwrLo_kW;
  }

  /* End of MinMax: '<S43>/MinMax1' */
  /* End of Outputs for SubSystem: '<S27>/Subsys_VOPM_ACHighVolDCTotalPwr_kW' */

  /* Outputs for Atomic SubSystem: '<S27>/Subsys_VOPM_ACPumpActlSpdDutyVld_flg' */
  /* Switch: '<S44>/Switch4' incorporates:
   *  Constant: '<S44>/sat3'
   */
  if (KOPM_ACPumpActlSpdDutyVld_flg_ovrdflg)
  {
    /* Switch: '<S44>/Switch4' incorporates:
     *  Constant: '<S44>/sat4'
     */
    VOPM_ACPumpActlSpdDutyVld_flg = KOPM_ACPumpActlSpdDutyVld_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S44>/Switch4' incorporates:
     *  Inport: '<Root>/TMS2VCU_AC_1_Command_Outputs'
     */
    VOPM_ACPumpActlSpdDutyVld_flg =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_1_Command_Outputs_TMS2VCU_AC_1_Command_Outputs())->AC_PumpActlSpdDutyV;
  }

  /* End of Switch: '<S44>/Switch4' */
  /* End of Outputs for SubSystem: '<S27>/Subsys_VOPM_ACPumpActlSpdDutyVld_flg' */

  /* BusCreator: '<S27>/BusCreator' incorporates:
   *  Switch: '<S38>/Switch4'
   *  Switch: '<S40>/Switch4'
   *  Switch: '<S41>/Switch4'
   */
  AppSwcOpm_ARID_DEF.AC_1_Command_BOD_n.AC_CompFailModeOprtSta =
      VOPM_ACCompFailModeOprtSta_flg;
  AppSwcOpm_ARID_DEF.AC_1_Command_BOD_n.AC_CompOprtReq = VOPM_ACCompOprtReq_flg;
  AppSwcOpm_ARID_DEF.AC_1_Command_BOD_n.AC_CompOprtEnaCmd =
      VOPM_ACCompOprtEnaCmd_flg;

  /* DataTypeConversion: '<S27>/DataTypeConversion4' incorporates:
   *  Constant: '<S46>/Constant1'
   *  Product: '<S46>/Product1'
   *  Sum: '<S46>/Add'
   */
  tmp = VOPM_ACCompMaxAllowPwrCmsp_kW * 25.0F;
  if (tmp < 256.0F)
  {
    if (tmp >= 0.0F)
    {
      /* BusCreator: '<S27>/BusCreator' */
      AppSwcOpm_ARID_DEF.AC_1_Command_BOD_n.AC_CompMaxAllowPwrCmsp = (uint8)tmp;
    }
    else
    {
      /* BusCreator: '<S27>/BusCreator' */
      AppSwcOpm_ARID_DEF.AC_1_Command_BOD_n.AC_CompMaxAllowPwrCmsp = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S27>/BusCreator' */
    AppSwcOpm_ARID_DEF.AC_1_Command_BOD_n.AC_CompMaxAllowPwrCmsp = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S27>/DataTypeConversion4' */

  /* BusCreator: '<S27>/BusCreator' */
  AppSwcOpm_ARID_DEF.AC_1_Command_BOD_n.AC_PumpActlSpdDuty =
      VOPM_ACPumpActlSpdDuty_pct;

  /* DataTypeConversion: '<S27>/DataTypeConversion6' incorporates:
   *  Constant: '<S47>/Constant1'
   *  Product: '<S47>/Product1'
   *  Sum: '<S47>/Add'
   */
  tmp = VOPM_ACHighVolDCTotalPwr_kW * 25.0F;
  if (tmp < 65536.0F)
  {
    if (tmp >= 0.0F)
    {
      /* BusCreator: '<S27>/BusCreator' */
      AppSwcOpm_ARID_DEF.AC_1_Command_BOD_n.AC_HighVolDCTolalPwr = (uint16)tmp;
    }
    else
    {
      /* BusCreator: '<S27>/BusCreator' */
      AppSwcOpm_ARID_DEF.AC_1_Command_BOD_n.AC_HighVolDCTolalPwr = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S27>/BusCreator' */
    AppSwcOpm_ARID_DEF.AC_1_Command_BOD_n.AC_HighVolDCTolalPwr = MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<S27>/DataTypeConversion6' */

  /* BusCreator: '<S27>/BusCreator' incorporates:
   *  Switch: '<S44>/Switch4'
   */
  AppSwcOpm_ARID_DEF.AC_1_Command_BOD_n.AC_PumpActlSpdDutyV =
      VOPM_ACPumpActlSpdDutyVld_flg;

  /* Outputs for Atomic SubSystem: '<S28>/Subsys_VOPM_ACHVHActlPwr_KW' */
  /* Switch: '<S53>/Switch4' incorporates:
   *  Constant: '<S53>/sat3'
   */
  if (KOPM_ACHVHActlPwr_KW_ovrdflg)
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Constant: '<S53>/sat4'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_ACHVHActlPwr_KW_ovrdval;
  }
  else
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Inport: '<Root>/TMS2VCU_AC_2_State_Outputs'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs())->AC_HVHActlPwr_HVAC;
  }

  /* End of Switch: '<S53>/Switch4' */

  /* MinMax: '<S53>/MinMax' incorporates:
   *  Constant: '<S53>/sat6'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm > KOPM_ACHVHActlPwrHi_KW)
  {
    /* MinMax: '<S39>/MinMax' */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_ACHVHActlPwrHi_KW;
  }

  /* End of MinMax: '<S53>/MinMax' */

  /* MinMax: '<S53>/MinMax1' incorporates:
   *  Constant: '<S53>/sat7'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm >= KOPM_ACHVHActlPwrLo_KW)
  {
    /* MinMax: '<S53>/MinMax1' */
    VOPM_ACHVHActlPwr_KW = VOPM_TMSAcPMPRealRPM_rpm;
  }
  else
  {
    /* MinMax: '<S53>/MinMax1' */
    VOPM_ACHVHActlPwr_KW = KOPM_ACHVHActlPwrLo_KW;
  }

  /* End of MinMax: '<S53>/MinMax1' */
  /* End of Outputs for SubSystem: '<S28>/Subsys_VOPM_ACHVHActlPwr_KW' */

  /* Outputs for Atomic SubSystem: '<S28>/Subsys_VOPM_ACHVHDevInternTemp_C' */
  /* Switch: '<S54>/Switch4' incorporates:
   *  Constant: '<S54>/sat3'
   */
  if (KOPM_ACHVHDevInternTemp_C_ovrdflg)
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Constant: '<S54>/sat4'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_ACHVHDevInternTemp_C_ovrdval;
  }
  else
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  DataTypeConversion: '<S54>/Data Type Conversion1'
     *  Inport: '<Root>/TMS2VCU_AC_2_State_Outputs'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm = (float32)(Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs())->AC_HVHDeviceInternTemp_HVAC;
  }

  /* End of Switch: '<S54>/Switch4' */

  /* MinMax: '<S54>/MinMax' incorporates:
   *  Constant: '<S54>/sat6'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm > KOPM_ACHVHDevInternTempHi_C)
  {
    /* MinMax: '<S39>/MinMax' */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_ACHVHDevInternTempHi_C;
  }

  /* End of MinMax: '<S54>/MinMax' */

  /* MinMax: '<S54>/MinMax1' incorporates:
   *  Constant: '<S54>/sat7'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm >= KOPM_ACHVHDevInternTempLo_C)
  {
    /* MinMax: '<S54>/MinMax1' */
    VOPM_ACHVHDevInternTemp_C = VOPM_TMSAcPMPRealRPM_rpm;
  }
  else
  {
    /* MinMax: '<S54>/MinMax1' */
    VOPM_ACHVHDevInternTemp_C = KOPM_ACHVHDevInternTempLo_C;
  }

  /* End of MinMax: '<S54>/MinMax1' */
  /* End of Outputs for SubSystem: '<S28>/Subsys_VOPM_ACHVHDevInternTemp_C' */

  /* Outputs for Atomic SubSystem: '<S28>/Subsys_VOPM_TMSPTPres_kPa' */
  /* Switch: '<S57>/Switch4' incorporates:
   *  Constant: '<S57>/sat3'
   */
  if (KOPM_TMSPTPres_kPa_ovrdflg)
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Constant: '<S57>/sat4'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_TMSPTPres_kPa_ovrdval;
  }
  else
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Inport: '<Root>/TMS2VCU_AC_2_State_Outputs'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs())->TMS_PTPressure;
  }

  /* End of Switch: '<S57>/Switch4' */

  /* MinMax: '<S57>/MinMax' incorporates:
   *  Constant: '<S57>/sat6'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm > KOPM_TMSPTPresHi_kPa)
  {
    /* MinMax: '<S39>/MinMax' */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_TMSPTPresHi_kPa;
  }

  /* End of MinMax: '<S57>/MinMax' */

  /* MinMax: '<S57>/MinMax1' incorporates:
   *  Constant: '<S57>/sat7'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm >= KOPM_TMSPTPresLo_kPa)
  {
    /* MinMax: '<S57>/MinMax1' */
    VOPM_TMSPTPres_kPa = VOPM_TMSAcPMPRealRPM_rpm;
  }
  else
  {
    /* MinMax: '<S57>/MinMax1' */
    VOPM_TMSPTPres_kPa = KOPM_TMSPTPresLo_kPa;
  }

  /* End of MinMax: '<S57>/MinMax1' */
  /* End of Outputs for SubSystem: '<S28>/Subsys_VOPM_TMSPTPres_kPa' */

  /* Outputs for Atomic SubSystem: '<S28>/Subsys_VOPM_ACActTotPwr_kW' */
  /* Switch: '<S48>/Switch4' incorporates:
   *  Constant: '<S48>/sat3'
   */
  if (KOPM_ACActTotPwr_kW_ovrdflg)
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Constant: '<S48>/sat4'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_ACActTotPwr_kW_ovrdval;
  }
  else
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Inport: '<Root>/TMS2VCU_AC_2_State_Outputs'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs())->AC_ActTotalPower;
  }

  /* End of Switch: '<S48>/Switch4' */

  /* MinMax: '<S48>/MinMax' incorporates:
   *  Constant: '<S48>/sat6'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm > KOPM_ACActTotPwrHi_kW)
  {
    /* MinMax: '<S39>/MinMax' */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_ACActTotPwrHi_kW;
  }

  /* End of MinMax: '<S48>/MinMax' */

  /* MinMax: '<S48>/MinMax1' incorporates:
   *  Constant: '<S48>/sat7'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm >= KOPM_ACActTotPwrLo_kW)
  {
    /* MinMax: '<S48>/MinMax1' */
    VOPM_ACActTotPwr_kW = VOPM_TMSAcPMPRealRPM_rpm;
  }
  else
  {
    /* MinMax: '<S48>/MinMax1' */
    VOPM_ACActTotPwr_kW = KOPM_ACActTotPwrLo_kW;
  }

  /* End of MinMax: '<S48>/MinMax1' */
  /* End of Outputs for SubSystem: '<S28>/Subsys_VOPM_ACActTotPwr_kW' */

  /* Outputs for Atomic SubSystem: '<S28>/Subsys_VOPM_ACHVHFailSta_flg' */
  /* Switch: '<S55>/Switch4' incorporates:
   *  Constant: '<S55>/sat3'
   */
  if (KOPM_ACHVHFailSta_flg_ovrdflg)
  {
    /* Switch: '<S55>/Switch4' incorporates:
     *  Constant: '<S55>/sat4'
     */
    VOPM_ACHVHFailSta_flg = KOPM_ACHVHFailSta_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S55>/Switch4' incorporates:
     *  Inport: '<Root>/TMS2VCU_AC_2_State_Outputs'
     */
    VOPM_ACHVHFailSta_flg =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs())->AC_HVHFailSta_HVAC;
  }

  /* End of Switch: '<S55>/Switch4' */
  /* End of Outputs for SubSystem: '<S28>/Subsys_VOPM_ACHVHFailSta_flg' */

  /* Outputs for Atomic SubSystem: '<S28>/Subsys_VOPM_ACFailSta_flg' */
  /* Switch: '<S51>/Switch4' incorporates:
   *  Constant: '<S51>/sat3'
   */
  if (KOPM_ACFailSta_flg_ovrdflg)
  {
    /* Switch: '<S51>/Switch4' incorporates:
     *  Constant: '<S51>/sat4'
     */
    VOPM_ACFailSta_flg = KOPM_ACFailSta_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S51>/Switch4' incorporates:
     *  Inport: '<Root>/TMS2VCU_AC_2_State_Outputs'
     */
    VOPM_ACFailSta_flg =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs())->AC_FailSta;
  }

  /* End of Switch: '<S51>/Switch4' */
  /* End of Outputs for SubSystem: '<S28>/Subsys_VOPM_ACFailSta_flg' */

  /* Outputs for Atomic SubSystem: '<S28>/Subsys_VOPM_TMSBattTempCtrlRmnSwFb_flg' */
  /* Switch: '<S56>/Switch4' incorporates:
   *  Constant: '<S56>/sat3'
   */
  if (KOPM_TMSBattTempCtrlRmnSwFb_flg_ovrdflg)
  {
    /* Switch: '<S56>/Switch4' incorporates:
     *  Constant: '<S56>/sat4'
     */
    VOPM_TMSBattTempCtrlRmnSwFb_flg = KOPM_TMSBattTempCtrlRmnSwFb_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S56>/Switch4' incorporates:
     *  Inport: '<Root>/TMS2VCU_AC_2_State_Outputs'
     */
    VOPM_TMSBattTempCtrlRmnSwFb_flg =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs())->TMSR_BattTempCtrlRmnSwtFb;
  }

  /* End of Switch: '<S56>/Switch4' */
  /* End of Outputs for SubSystem: '<S28>/Subsys_VOPM_TMSBattTempCtrlRmnSwFb_flg' */

  /* Outputs for Atomic SubSystem: '<S28>/Subsys_VOPM_ACBatPmpFailSta_flg' */
  /* Switch: '<S50>/Switch4' incorporates:
   *  Constant: '<S50>/sat3'
   */
  if (KOPM_ACBatPmpFailSta_flg_ovrdflg)
  {
    /* Switch: '<S50>/Switch4' incorporates:
     *  Constant: '<S50>/sat4'
     */
    VOPM_ACBatPmpFailSta_flg = KOPM_ACBatPmpFailSta_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S50>/Switch4' incorporates:
     *  Inport: '<Root>/TMS2VCU_AC_2_State_Outputs'
     */
    VOPM_ACBatPmpFailSta_flg =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs())->AC_BatPumpFailSta;
  }

  /* End of Switch: '<S50>/Switch4' */
  /* End of Outputs for SubSystem: '<S28>/Subsys_VOPM_ACBatPmpFailSta_flg' */

  /* Outputs for Atomic SubSystem: '<S28>/Subsys_VOPM_ACHVHActlOprtMode_enum' */
  /* Switch: '<S52>/Switch4' incorporates:
   *  Constant: '<S52>/sat3'
   */
  if (KOPM_ACHVHActlOprtMode_enum_ovrdflg)
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Constant: '<S52>/sat4'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum = KOPM_ACHVHActlOprtMode_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Inport: '<Root>/TMS2VCU_AC_2_State_Outputs'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs())->AC_HVHActlOprtMode_HVAC;
  }

  /* End of Switch: '<S52>/Switch4' */

  /* MinMax: '<S52>/MinMax' incorporates:
   *  Constant: '<S52>/sat6'
   */
  if (VOPM_TMSC3WVMode_enum > KOPM_ACHVHActlOprtModeHi_enum)
  {
    /* MinMax: '<S153>/MinMax' */
    VOPM_TMSC3WVMode_enum = KOPM_ACHVHActlOprtModeHi_enum;
  }

  /* End of MinMax: '<S52>/MinMax' */

  /* MinMax: '<S52>/MinMax1' incorporates:
   *  Constant: '<S52>/sat7'
   */
  if (VOPM_TMSC3WVMode_enum >= KOPM_ACHVHActlOprtModeLo_enum)
  {
    /* MinMax: '<S52>/MinMax1' */
    VOPM_ACHVHActlOprtMode_enum = VOPM_TMSC3WVMode_enum;
  }
  else
  {
    /* MinMax: '<S52>/MinMax1' */
    VOPM_ACHVHActlOprtMode_enum = KOPM_ACHVHActlOprtModeLo_enum;
  }

  /* End of MinMax: '<S52>/MinMax1' */
  /* End of Outputs for SubSystem: '<S28>/Subsys_VOPM_ACHVHActlOprtMode_enum' */

  /* Outputs for Atomic SubSystem: '<S28>/Subsys_VOPM_ACActlOprtMode_enum' */
  /* Switch: '<S49>/Switch4' incorporates:
   *  Constant: '<S49>/sat3'
   */
  if (KOPM_ACActlOprtMode_enum_ovrdflg)
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Constant: '<S49>/sat4'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum = KOPM_ACActlOprtMode_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Inport: '<Root>/TMS2VCU_AC_2_State_Outputs'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs())->AC_ActlOprtMode;
  }

  /* End of Switch: '<S49>/Switch4' */

  /* MinMax: '<S49>/MinMax' incorporates:
   *  Constant: '<S49>/sat6'
   */
  if (VOPM_TMSC3WVMode_enum > KOPM_ACActlOprtModeHi_enum)
  {
    /* MinMax: '<S153>/MinMax' */
    VOPM_TMSC3WVMode_enum = KOPM_ACActlOprtModeHi_enum;
  }

  /* End of MinMax: '<S49>/MinMax' */

  /* MinMax: '<S49>/MinMax1' incorporates:
   *  Constant: '<S49>/sat7'
   */
  if (VOPM_TMSC3WVMode_enum >= KOPM_ACActlOprtModeLo_enum)
  {
    /* MinMax: '<S49>/MinMax1' */
    VOPM_ACActlOprtMode_enum = VOPM_TMSC3WVMode_enum;
  }
  else
  {
    /* MinMax: '<S49>/MinMax1' */
    VOPM_ACActlOprtMode_enum = KOPM_ACActlOprtModeLo_enum;
  }

  /* End of MinMax: '<S49>/MinMax1' */
  /* End of Outputs for SubSystem: '<S28>/Subsys_VOPM_ACActlOprtMode_enum' */

  /* Outputs for Atomic SubSystem: '<S28>/Subsys_VOPM_TMSPTTemp_C' */
  /* Switch: '<S58>/Switch4' incorporates:
   *  Constant: '<S58>/sat3'
   */
  if (KOPM_TMSPTTemp_C_ovrdflg)
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Constant: '<S58>/sat4'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_TMSPTTemp_C_ovrdval;
  }
  else
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  DataTypeConversion: '<S58>/Data Type Conversion1'
     *  Inport: '<Root>/TMS2VCU_AC_2_State_Outputs'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm = (float32)(Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs())->TMS_PTTemp;
  }

  /* End of Switch: '<S58>/Switch4' */

  /* MinMax: '<S58>/MinMax' incorporates:
   *  Constant: '<S58>/sat6'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm > KOPM_TMSPTTempHi_C)
  {
    /* MinMax: '<S39>/MinMax' */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_TMSPTTempHi_C;
  }

  /* End of MinMax: '<S58>/MinMax' */

  /* MinMax: '<S58>/MinMax1' incorporates:
   *  Constant: '<S58>/sat7'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm >= KOPM_TMSPTTempLo_C)
  {
    /* MinMax: '<S58>/MinMax1' */
    VOPM_TMSPTTemp_C = VOPM_TMSAcPMPRealRPM_rpm;
  }
  else
  {
    /* MinMax: '<S58>/MinMax1' */
    VOPM_TMSPTTemp_C = KOPM_TMSPTTempLo_C;
  }

  /* End of MinMax: '<S58>/MinMax1' */
  /* End of Outputs for SubSystem: '<S28>/Subsys_VOPM_TMSPTTemp_C' */

  /* DataTypeConversion: '<S28>/DataTypeConversion' incorporates:
   *  Constant: '<S59>/Constant1'
   *  Product: '<S59>/Product1'
   *  Sum: '<S59>/Add'
   */
  tmp = VOPM_ACHVHActlPwr_KW * 25.0F;
  if (tmp < 256.0F)
  {
    if (tmp >= 0.0F)
    {
      /* BusCreator: '<S28>/BusCreator' */
      AppSwcOpm_ARID_DEF.AC_2_State_BOD_g.AC_HVHActlPwr_HVAC = (uint8)tmp;
    }
    else
    {
      /* BusCreator: '<S28>/BusCreator' */
      AppSwcOpm_ARID_DEF.AC_2_State_BOD_g.AC_HVHActlPwr_HVAC = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S28>/BusCreator' */
    AppSwcOpm_ARID_DEF.AC_2_State_BOD_g.AC_HVHActlPwr_HVAC = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S28>/DataTypeConversion' */

  /* DataTypeConversion: '<S28>/DataTypeConversion1' incorporates:
   *  Constant: '<S60>/Constant'
   *  Sum: '<S60>/Add'
   */
  if (VOPM_ACHVHDevInternTemp_C - -40.0F < 256.0F)
  {
    if (VOPM_ACHVHDevInternTemp_C - -40.0F >= 0.0F)
    {
      /* BusCreator: '<S28>/BusCreator' */
      AppSwcOpm_ARID_DEF.AC_2_State_BOD_g.AC_HVHDeviceInternTemp_HVAC = (uint8)(VOPM_ACHVHDevInternTemp_C - -40.0F);
    }
    else
    {
      /* BusCreator: '<S28>/BusCreator' */
      AppSwcOpm_ARID_DEF.AC_2_State_BOD_g.AC_HVHDeviceInternTemp_HVAC = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S28>/BusCreator' */
    AppSwcOpm_ARID_DEF.AC_2_State_BOD_g.AC_HVHDeviceInternTemp_HVAC =
        MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S28>/DataTypeConversion1' */

  /* DataTypeConversion: '<S28>/DataTypeConversion2' incorporates:
   *  Constant: '<S61>/Constant1'
   *  Product: '<S61>/Product1'
   *  Sum: '<S61>/Add'
   */
  tmp = VOPM_TMSPTPres_kPa * 0.01F;
  if (tmp < 256.0F)
  {
    if (tmp >= 0.0F)
    {
      /* BusCreator: '<S28>/BusCreator' */
      AppSwcOpm_ARID_DEF.AC_2_State_BOD_g.TMS_PTPressure = (uint8)tmp;
    }
    else
    {
      /* BusCreator: '<S28>/BusCreator' */
      AppSwcOpm_ARID_DEF.AC_2_State_BOD_g.TMS_PTPressure = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S28>/BusCreator' */
    AppSwcOpm_ARID_DEF.AC_2_State_BOD_g.TMS_PTPressure = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S28>/DataTypeConversion2' */

  /* DataTypeConversion: '<S28>/DataTypeConversion3' incorporates:
   *  Constant: '<S62>/Constant1'
   *  Product: '<S62>/Product1'
   *  Sum: '<S62>/Add'
   */
  tmp = VOPM_ACActTotPwr_kW * 25.0F;
  if (tmp < 65536.0F)
  {
    if (tmp >= 0.0F)
    {
      /* BusCreator: '<S28>/BusCreator' */
      AppSwcOpm_ARID_DEF.AC_2_State_BOD_g.AC_ActTotalPower = (uint16)tmp;
    }
    else
    {
      /* BusCreator: '<S28>/BusCreator' */
      AppSwcOpm_ARID_DEF.AC_2_State_BOD_g.AC_ActTotalPower = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S28>/BusCreator' */
    AppSwcOpm_ARID_DEF.AC_2_State_BOD_g.AC_ActTotalPower = MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<S28>/DataTypeConversion3' */

  /* BusCreator: '<S28>/BusCreator' incorporates:
   *  Switch: '<S50>/Switch4'
   *  Switch: '<S51>/Switch4'
   *  Switch: '<S55>/Switch4'
   *  Switch: '<S56>/Switch4'
   */
  AppSwcOpm_ARID_DEF.AC_2_State_BOD_g.AC_HVHFailSta_HVAC = VOPM_ACHVHFailSta_flg;
  AppSwcOpm_ARID_DEF.AC_2_State_BOD_g.AC_FailSta = VOPM_ACFailSta_flg;
  AppSwcOpm_ARID_DEF.AC_2_State_BOD_g.TMSR_BattTempCtrlRmnSwtFb =
      VOPM_TMSBattTempCtrlRmnSwFb_flg;
  AppSwcOpm_ARID_DEF.AC_2_State_BOD_g.AC_BatPumpFailSta =
      VOPM_ACBatPmpFailSta_flg;
  AppSwcOpm_ARID_DEF.AC_2_State_BOD_g.AC_HVHActlOprtMode_HVAC =
      VOPM_ACHVHActlOprtMode_enum;
  AppSwcOpm_ARID_DEF.AC_2_State_BOD_g.AC_ActlOprtMode = VOPM_ACActlOprtMode_enum;

  /* DataTypeConversion: '<S28>/DataTypeConversion10' incorporates:
   *  Constant: '<S63>/Constant'
   *  Sum: '<S63>/Add'
   */
  if (VOPM_TMSPTTemp_C - -40.0F < 256.0F)
  {
    if (VOPM_TMSPTTemp_C - -40.0F >= 0.0F)
    {
      /* BusCreator: '<S28>/BusCreator' */
      AppSwcOpm_ARID_DEF.AC_2_State_BOD_g.TMS_PTTemp = (uint8)(VOPM_TMSPTTemp_C - -40.0F);
    }
    else
    {
      /* BusCreator: '<S28>/BusCreator' */
      AppSwcOpm_ARID_DEF.AC_2_State_BOD_g.TMS_PTTemp = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S28>/BusCreator' */
    AppSwcOpm_ARID_DEF.AC_2_State_BOD_g.TMS_PTTemp = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S28>/DataTypeConversion10' */

  /* Outputs for Atomic SubSystem: '<S10>/Subsys_VOPM_BCMHiFreqSigDataByte0_nu' */
  /* Switch: '<S11>/Switch4' incorporates:
   *  Constant: '<S11>/sat3'
   */
  if (KOPM_BCMHiFreqSigDataByte0_nu_ovrdflg)
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Constant: '<S11>/sat4'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum = KOPM_BCMHiFreqSigDataByte0_nu_ovrdval;
  }
  else
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S11>/Data Type Conversion1'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_100ms_Bcm2OpmBAC_outputs())
            ->BCM_HighFreqSigData_Byte0;
  }

  /* End of Switch: '<S11>/Switch4' */

  /* MinMax: '<S11>/MinMax' incorporates:
   *  Constant: '<S11>/sat6'
   */
  if (VOPM_TMSC3WVMode_enum > KOPM_BCMHiFreqSigDataByte0Hi_nu)
  {
    /* MinMax: '<S153>/MinMax' */
    VOPM_TMSC3WVMode_enum = KOPM_BCMHiFreqSigDataByte0Hi_nu;
  }

  /* End of MinMax: '<S11>/MinMax' */

  /* MinMax: '<S11>/MinMax1' incorporates:
   *  Constant: '<S11>/sat7'
   */
  if (VOPM_TMSC3WVMode_enum >= KOPM_BCMHiFreqSigDataByte0Lo_nu)
  {
    /* MinMax: '<S11>/MinMax1' */
    VOPM_BCMHiFreqSigDataByte0_nu = VOPM_TMSC3WVMode_enum;
  }
  else
  {
    /* MinMax: '<S11>/MinMax1' */
    VOPM_BCMHiFreqSigDataByte0_nu = KOPM_BCMHiFreqSigDataByte0Lo_nu;
  }

  /* End of MinMax: '<S11>/MinMax1' */
  /* End of Outputs for SubSystem: '<S10>/Subsys_VOPM_BCMHiFreqSigDataByte0_nu' */

  /* Outputs for Atomic SubSystem: '<S10>/Subsys_VOPM_BCMHiFreqSigDataByte1_nu' */
  /* Switch: '<S18>/Switch4' incorporates:
   *  Constant: '<S18>/sat3'
   */
  if (KOPM_BCMHiFreqSigDataByte1_nu_ovrdflg)
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Constant: '<S18>/sat4'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum = KOPM_BCMHiFreqSigDataByte1_nu_ovrdval;
  }
  else
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S18>/Data Type Conversion1'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_100ms_Bcm2OpmBAC_outputs())
            ->BCM_HighFreqSigData_Byte1;
  }

  /* End of Switch: '<S18>/Switch4' */

  /* MinMax: '<S18>/MinMax' incorporates:
   *  Constant: '<S18>/sat6'
   */
  if (VOPM_TMSC3WVMode_enum > KOPM_BCMHiFreqSigDataByte1Hi_nu)
  {
    /* MinMax: '<S153>/MinMax' */
    VOPM_TMSC3WVMode_enum = KOPM_BCMHiFreqSigDataByte1Hi_nu;
  }

  /* End of MinMax: '<S18>/MinMax' */

  /* MinMax: '<S18>/MinMax1' incorporates:
   *  Constant: '<S18>/sat7'
   */
  if (VOPM_TMSC3WVMode_enum >= KOPM_BCMHiFreqSigDataByte1Lo_nu)
  {
    /* MinMax: '<S18>/MinMax1' */
    VOPM_BCMHiFreqSigDataByte1_nu = VOPM_TMSC3WVMode_enum;
  }
  else
  {
    /* MinMax: '<S18>/MinMax1' */
    VOPM_BCMHiFreqSigDataByte1_nu = KOPM_BCMHiFreqSigDataByte1Lo_nu;
  }

  /* End of MinMax: '<S18>/MinMax1' */
  /* End of Outputs for SubSystem: '<S10>/Subsys_VOPM_BCMHiFreqSigDataByte1_nu' */

  /* Outputs for Atomic SubSystem: '<S10>/Subsys_VOPM_BCMHiFreqSigDataByte2_nu' */
  /* Switch: '<S19>/Switch4' incorporates:
   *  Constant: '<S19>/sat3'
   */
  if (KOPM_BCMHiFreqSigDataByte2_nu_ovrdflg)
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Constant: '<S19>/sat4'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum = KOPM_BCMHiFreqSigDataByte2_nu_ovrdval;
  }
  else
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S19>/Data Type Conversion1'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_100ms_Bcm2OpmBAC_outputs())
            ->BCM_HighFreqSigData_Byte2;
  }

  /* End of Switch: '<S19>/Switch4' */

  /* MinMax: '<S19>/MinMax' incorporates:
   *  Constant: '<S19>/sat6'
   */
  if (VOPM_TMSC3WVMode_enum > KOPM_BCMHiFreqSigDataByte2Hi_nu)
  {
    /* MinMax: '<S153>/MinMax' */
    VOPM_TMSC3WVMode_enum = KOPM_BCMHiFreqSigDataByte2Hi_nu;
  }

  /* End of MinMax: '<S19>/MinMax' */

  /* MinMax: '<S19>/MinMax1' incorporates:
   *  Constant: '<S19>/sat7'
   */
  if (VOPM_TMSC3WVMode_enum >= KOPM_BCMHiFreqSigDataByte2Lo_nu)
  {
    /* MinMax: '<S19>/MinMax1' */
    VOPM_BCMHiFreqSigDataByte2_nu = VOPM_TMSC3WVMode_enum;
  }
  else
  {
    /* MinMax: '<S19>/MinMax1' */
    VOPM_BCMHiFreqSigDataByte2_nu = KOPM_BCMHiFreqSigDataByte2Lo_nu;
  }

  /* End of MinMax: '<S19>/MinMax1' */
  /* End of Outputs for SubSystem: '<S10>/Subsys_VOPM_BCMHiFreqSigDataByte2_nu' */

  /* Outputs for Atomic SubSystem: '<S10>/Subsys_VOPM_BCMHiFreqSigDataByte3_nu' */
  /* Switch: '<S20>/Switch4' incorporates:
   *  Constant: '<S20>/sat3'
   */
  if (KOPM_BCMHiFreqSigDataByte3_nu_ovrdflg)
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Constant: '<S20>/sat4'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum = KOPM_BCMHiFreqSigDataByte3_nu_ovrdval;
  }
  else
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S20>/Data Type Conversion1'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_100ms_Bcm2OpmBAC_outputs())
            ->BCM_HighFreqSigData_Byte3;
  }

  /* End of Switch: '<S20>/Switch4' */

  /* MinMax: '<S20>/MinMax' incorporates:
   *  Constant: '<S20>/sat6'
   */
  if (VOPM_TMSC3WVMode_enum > KOPM_BCMHiFreqSigDataByte3Hi_nu)
  {
    /* MinMax: '<S153>/MinMax' */
    VOPM_TMSC3WVMode_enum = KOPM_BCMHiFreqSigDataByte3Hi_nu;
  }

  /* End of MinMax: '<S20>/MinMax' */

  /* MinMax: '<S20>/MinMax1' incorporates:
   *  Constant: '<S20>/sat7'
   */
  if (VOPM_TMSC3WVMode_enum >= KOPM_BCMHiFreqSigDataByte3Lo_nu)
  {
    /* MinMax: '<S20>/MinMax1' */
    VOPM_BCMHiFreqSigDataByte3_nu = VOPM_TMSC3WVMode_enum;
  }
  else
  {
    /* MinMax: '<S20>/MinMax1' */
    VOPM_BCMHiFreqSigDataByte3_nu = KOPM_BCMHiFreqSigDataByte3Lo_nu;
  }

  /* End of MinMax: '<S20>/MinMax1' */
  /* End of Outputs for SubSystem: '<S10>/Subsys_VOPM_BCMHiFreqSigDataByte3_nu' */

  /* Outputs for Atomic SubSystem: '<S10>/Subsys_VOPM_BCMHiFreqSigDataByte4_nu' */
  /* Switch: '<S21>/Switch4' incorporates:
   *  Constant: '<S21>/sat3'
   */
  if (KOPM_BCMHiFreqSigDataByte4_nu_ovrdflg)
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Constant: '<S21>/sat4'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum = KOPM_BCMHiFreqSigDataByte4_nu_ovrdval;
  }
  else
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S21>/Data Type Conversion1'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_100ms_Bcm2OpmBAC_outputs())
            ->BCM_HighFreqSigData_Byte4;
  }

  /* End of Switch: '<S21>/Switch4' */

  /* MinMax: '<S21>/MinMax' incorporates:
   *  Constant: '<S21>/sat6'
   */
  if (VOPM_TMSC3WVMode_enum > KOPM_BCMHiFreqSigDataByte4Hi_nu)
  {
    /* MinMax: '<S153>/MinMax' */
    VOPM_TMSC3WVMode_enum = KOPM_BCMHiFreqSigDataByte4Hi_nu;
  }

  /* End of MinMax: '<S21>/MinMax' */

  /* MinMax: '<S21>/MinMax1' incorporates:
   *  Constant: '<S21>/sat7'
   */
  if (VOPM_TMSC3WVMode_enum >= KOPM_BCMHiFreqSigDataByte4Lo_nu)
  {
    /* MinMax: '<S21>/MinMax1' */
    VOPM_BCMHiFreqSigDataByte4_nu = VOPM_TMSC3WVMode_enum;
  }
  else
  {
    /* MinMax: '<S21>/MinMax1' */
    VOPM_BCMHiFreqSigDataByte4_nu = KOPM_BCMHiFreqSigDataByte4Lo_nu;
  }

  /* End of MinMax: '<S21>/MinMax1' */
  /* End of Outputs for SubSystem: '<S10>/Subsys_VOPM_BCMHiFreqSigDataByte4_nu' */

  /* Outputs for Atomic SubSystem: '<S10>/Subsys_VOPM_BCMHiFreqSigDataByte5_nu' */
  /* Switch: '<S22>/Switch4' incorporates:
   *  Constant: '<S22>/sat3'
   */
  if (KOPM_BCMHiFreqSigDataByte5_nu_ovrdflg)
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Constant: '<S22>/sat4'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum = KOPM_BCMHiFreqSigDataByte5_nu_ovrdval;
  }
  else
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S22>/Data Type Conversion1'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_100ms_Bcm2OpmBAC_outputs())
            ->BCM_HighFreqSigData_Byte5;
  }

  /* End of Switch: '<S22>/Switch4' */

  /* MinMax: '<S22>/MinMax' incorporates:
   *  Constant: '<S22>/sat6'
   */
  if (VOPM_TMSC3WVMode_enum > KOPM_BCMHiFreqSigDataByte5Hi_nu)
  {
    /* MinMax: '<S153>/MinMax' */
    VOPM_TMSC3WVMode_enum = KOPM_BCMHiFreqSigDataByte5Hi_nu;
  }

  /* End of MinMax: '<S22>/MinMax' */

  /* MinMax: '<S22>/MinMax1' incorporates:
   *  Constant: '<S22>/sat7'
   */
  if (VOPM_TMSC3WVMode_enum >= KOPM_BCMHiFreqSigDataByte5Lo_nu)
  {
    /* MinMax: '<S22>/MinMax1' */
    VOPM_BCMHiFreqSigDataByte5_nu = VOPM_TMSC3WVMode_enum;
  }
  else
  {
    /* MinMax: '<S22>/MinMax1' */
    VOPM_BCMHiFreqSigDataByte5_nu = KOPM_BCMHiFreqSigDataByte5Lo_nu;
  }

  /* End of MinMax: '<S22>/MinMax1' */
  /* End of Outputs for SubSystem: '<S10>/Subsys_VOPM_BCMHiFreqSigDataByte5_nu' */

  /* Outputs for Atomic SubSystem: '<S10>/Subsys_VOPM_BCMHiFreqSigDataByte6_nu' */
  /* Switch: '<S23>/Switch4' incorporates:
   *  Constant: '<S23>/sat3'
   */
  if (KOPM_BCMHiFreqSigDataByte6_nu_ovrdflg)
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Constant: '<S23>/sat4'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum = KOPM_BCMHiFreqSigDataByte6_nu_ovrdval;
  }
  else
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S23>/Data Type Conversion1'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_100ms_Bcm2OpmBAC_outputs())
            ->BCM_HighFreqSigData_Byte6;
  }

  /* End of Switch: '<S23>/Switch4' */

  /* MinMax: '<S23>/MinMax' incorporates:
   *  Constant: '<S23>/sat6'
   */
  if (VOPM_TMSC3WVMode_enum > KOPM_BCMHiFreqSigDataByte6Hi_nu)
  {
    /* MinMax: '<S153>/MinMax' */
    VOPM_TMSC3WVMode_enum = KOPM_BCMHiFreqSigDataByte6Hi_nu;
  }

  /* End of MinMax: '<S23>/MinMax' */

  /* MinMax: '<S23>/MinMax1' incorporates:
   *  Constant: '<S23>/sat7'
   */
  if (VOPM_TMSC3WVMode_enum >= KOPM_BCMHiFreqSigDataByte6Lo_nu)
  {
    /* MinMax: '<S23>/MinMax1' */
    VOPM_BCMHiFreqSigDataByte6_nu = VOPM_TMSC3WVMode_enum;
  }
  else
  {
    /* MinMax: '<S23>/MinMax1' */
    VOPM_BCMHiFreqSigDataByte6_nu = KOPM_BCMHiFreqSigDataByte6Lo_nu;
  }

  /* End of MinMax: '<S23>/MinMax1' */
  /* End of Outputs for SubSystem: '<S10>/Subsys_VOPM_BCMHiFreqSigDataByte6_nu' */

  /* Outputs for Atomic SubSystem: '<S10>/Subsys_VOPM_BCMHiFreqSigDataByte7_nu' */
  /* Switch: '<S24>/Switch4' incorporates:
   *  Constant: '<S24>/sat3'
   */
  if (KOPM_BCMHiFreqSigDataByte7_nu_ovrdflg)
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Constant: '<S24>/sat4'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum = KOPM_BCMHiFreqSigDataByte7_nu_ovrdval;
  }
  else
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S24>/Data Type Conversion1'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_100ms_Bcm2OpmBAC_outputs())
            ->BCM_HighFreqSigData_Byte7;
  }

  /* End of Switch: '<S24>/Switch4' */

  /* MinMax: '<S24>/MinMax' incorporates:
   *  Constant: '<S24>/sat6'
   */
  if (VOPM_TMSC3WVMode_enum > KOPM_BCMHiFreqSigDataByte7Hi_nu)
  {
    /* MinMax: '<S153>/MinMax' */
    VOPM_TMSC3WVMode_enum = KOPM_BCMHiFreqSigDataByte7Hi_nu;
  }

  /* End of MinMax: '<S24>/MinMax' */

  /* MinMax: '<S24>/MinMax1' incorporates:
   *  Constant: '<S24>/sat7'
   */
  if (VOPM_TMSC3WVMode_enum >= KOPM_BCMHiFreqSigDataByte7Lo_nu)
  {
    /* MinMax: '<S24>/MinMax1' */
    VOPM_BCMHiFreqSigDataByte7_nu = VOPM_TMSC3WVMode_enum;
  }
  else
  {
    /* MinMax: '<S24>/MinMax1' */
    VOPM_BCMHiFreqSigDataByte7_nu = KOPM_BCMHiFreqSigDataByte7Lo_nu;
  }

  /* End of MinMax: '<S24>/MinMax1' */
  /* End of Outputs for SubSystem: '<S10>/Subsys_VOPM_BCMHiFreqSigDataByte7_nu' */

  /* Outputs for Atomic SubSystem: '<S10>/Subsys_VOPM_BCMHiFreqSigDataByte8_nu' */
  /* Switch: '<S25>/Switch4' incorporates:
   *  Constant: '<S25>/sat3'
   */
  if (KOPM_BCMHiFreqSigDataByte8_nu_ovrdflg)
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Constant: '<S25>/sat4'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum = KOPM_BCMHiFreqSigDataByte8_nu_ovrdval;
  }
  else
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S25>/Data Type Conversion1'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_100ms_Bcm2OpmBAC_outputs())
            ->BCM_HighFreqSigData_Byte8;
  }

  /* End of Switch: '<S25>/Switch4' */

  /* MinMax: '<S25>/MinMax' incorporates:
   *  Constant: '<S25>/sat6'
   */
  if (VOPM_TMSC3WVMode_enum > KOPM_BCMHiFreqSigDataByte8Hi_nu)
  {
    /* MinMax: '<S153>/MinMax' */
    VOPM_TMSC3WVMode_enum = KOPM_BCMHiFreqSigDataByte8Hi_nu;
  }

  /* End of MinMax: '<S25>/MinMax' */

  /* MinMax: '<S25>/MinMax1' incorporates:
   *  Constant: '<S25>/sat7'
   */
  if (VOPM_TMSC3WVMode_enum >= KOPM_BCMHiFreqSigDataByte8Lo_nu)
  {
    /* MinMax: '<S25>/MinMax1' */
    VOPM_BCMHiFreqSigDataByte8_nu = VOPM_TMSC3WVMode_enum;
  }
  else
  {
    /* MinMax: '<S25>/MinMax1' */
    VOPM_BCMHiFreqSigDataByte8_nu = KOPM_BCMHiFreqSigDataByte8Lo_nu;
  }

  /* End of MinMax: '<S25>/MinMax1' */
  /* End of Outputs for SubSystem: '<S10>/Subsys_VOPM_BCMHiFreqSigDataByte8_nu' */

  /* Outputs for Atomic SubSystem: '<S10>/Subsys_VOPM_BCMHiFreqSigDataByte9_nu' */
  /* Switch: '<S26>/Switch4' incorporates:
   *  Constant: '<S26>/sat3'
   */
  if (KOPM_BCMHiFreqSigDataByte9_nu_ovrdflg)
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Constant: '<S26>/sat4'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum = KOPM_BCMHiFreqSigDataByte9_nu_ovrdval;
  }
  else
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S26>/Data Type Conversion1'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_100ms_Bcm2OpmBAC_outputs())
            ->BCM_HighFreqSigData_Byte9;
  }

  /* End of Switch: '<S26>/Switch4' */

  /* MinMax: '<S26>/MinMax' incorporates:
   *  Constant: '<S26>/sat6'
   */
  if (VOPM_TMSC3WVMode_enum > KOPM_BCMHiFreqSigDataByte9Hi_nu)
  {
    /* MinMax: '<S153>/MinMax' */
    VOPM_TMSC3WVMode_enum = KOPM_BCMHiFreqSigDataByte9Hi_nu;
  }

  /* End of MinMax: '<S26>/MinMax' */

  /* MinMax: '<S26>/MinMax1' incorporates:
   *  Constant: '<S26>/sat7'
   */
  if (VOPM_TMSC3WVMode_enum >= KOPM_BCMHiFreqSigDataByte9Lo_nu)
  {
    /* MinMax: '<S26>/MinMax1' */
    VOPM_BCMHiFreqSigDataByte9_nu = VOPM_TMSC3WVMode_enum;
  }
  else
  {
    /* MinMax: '<S26>/MinMax1' */
    VOPM_BCMHiFreqSigDataByte9_nu = KOPM_BCMHiFreqSigDataByte9Lo_nu;
  }

  /* End of MinMax: '<S26>/MinMax1' */
  /* End of Outputs for SubSystem: '<S10>/Subsys_VOPM_BCMHiFreqSigDataByte9_nu' */

  /* Outputs for Atomic SubSystem: '<S10>/Subsys_VOPM_BCMHiFreqSigDataByte10_nu' */
  /* Switch: '<S12>/Switch4' incorporates:
   *  Constant: '<S12>/sat3'
   */
  if (KOPM_BCMHiFreqSigDataByte10_nu_ovrdflg)
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Constant: '<S12>/sat4'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum = KOPM_BCMHiFreqSigDataByte10_nu_ovrdval;
  }
  else
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S12>/Data Type Conversion1'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_100ms_Bcm2OpmBAC_outputs())
            ->BCM_HighFreqSigData_Byte10;
  }

  /* End of Switch: '<S12>/Switch4' */

  /* MinMax: '<S12>/MinMax' incorporates:
   *  Constant: '<S12>/sat6'
   */
  if (VOPM_TMSC3WVMode_enum > KOPM_BCMHiFreqSigDataByte10Hi_nu)
  {
    /* MinMax: '<S153>/MinMax' */
    VOPM_TMSC3WVMode_enum = KOPM_BCMHiFreqSigDataByte10Hi_nu;
  }

  /* End of MinMax: '<S12>/MinMax' */

  /* MinMax: '<S12>/MinMax1' incorporates:
   *  Constant: '<S12>/sat7'
   */
  if (VOPM_TMSC3WVMode_enum >= KOPM_BCMHiFreqSigDataByte10Lo_nu)
  {
    /* MinMax: '<S12>/MinMax1' */
    VOPM_BCMHiFreqSigDataByte10_nu = VOPM_TMSC3WVMode_enum;
  }
  else
  {
    /* MinMax: '<S12>/MinMax1' */
    VOPM_BCMHiFreqSigDataByte10_nu = KOPM_BCMHiFreqSigDataByte10Lo_nu;
  }

  /* End of MinMax: '<S12>/MinMax1' */
  /* End of Outputs for SubSystem: '<S10>/Subsys_VOPM_BCMHiFreqSigDataByte10_nu' */

  /* Outputs for Atomic SubSystem: '<S10>/Subsys_VOPM_BCMHiFreqSigDataByte11_nu' */
  /* Switch: '<S13>/Switch4' incorporates:
   *  Constant: '<S13>/sat3'
   */
  if (KOPM_BCMHiFreqSigDataByte11_nu_ovrdflg)
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Constant: '<S13>/sat4'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum = KOPM_BCMHiFreqSigDataByte11_nu_ovrdval;
  }
  else
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S13>/Data Type Conversion1'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_100ms_Bcm2OpmBAC_outputs())
            ->BCM_HighFreqSigData_Byte11;
  }

  /* End of Switch: '<S13>/Switch4' */

  /* MinMax: '<S13>/MinMax' incorporates:
   *  Constant: '<S13>/sat6'
   */
  if (VOPM_TMSC3WVMode_enum > KOPM_BCMHiFreqSigDataByte11Hi_nu)
  {
    /* MinMax: '<S153>/MinMax' */
    VOPM_TMSC3WVMode_enum = KOPM_BCMHiFreqSigDataByte11Hi_nu;
  }

  /* End of MinMax: '<S13>/MinMax' */

  /* MinMax: '<S13>/MinMax1' incorporates:
   *  Constant: '<S13>/sat7'
   */
  if (VOPM_TMSC3WVMode_enum >= KOPM_BCMHiFreqSigDataByte11Lo_nu)
  {
    /* MinMax: '<S13>/MinMax1' */
    VOPM_BCMHiFreqSigDataByte11_nu = VOPM_TMSC3WVMode_enum;
  }
  else
  {
    /* MinMax: '<S13>/MinMax1' */
    VOPM_BCMHiFreqSigDataByte11_nu = KOPM_BCMHiFreqSigDataByte11Lo_nu;
  }

  /* End of MinMax: '<S13>/MinMax1' */
  /* End of Outputs for SubSystem: '<S10>/Subsys_VOPM_BCMHiFreqSigDataByte11_nu' */

  /* Outputs for Atomic SubSystem: '<S10>/Subsys_VOPM_BCMHiFreqSigDataByte12_nu' */
  /* Switch: '<S14>/Switch4' incorporates:
   *  Constant: '<S14>/sat3'
   */
  if (KOPM_BCMHiFreqSigDataByte12_nu_ovrdflg)
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Constant: '<S14>/sat4'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum = KOPM_BCMHiFreqSigDataByte12_nu_ovrdval;
  }
  else
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S14>/Data Type Conversion1'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_100ms_Bcm2OpmBAC_outputs())
            ->BCM_HighFreqSigData_Byte12;
  }

  /* End of Switch: '<S14>/Switch4' */

  /* MinMax: '<S14>/MinMax' incorporates:
   *  Constant: '<S14>/sat6'
   */
  if (VOPM_TMSC3WVMode_enum > KOPM_BCMHiFreqSigDataByte12Hi_nu)
  {
    /* MinMax: '<S153>/MinMax' */
    VOPM_TMSC3WVMode_enum = KOPM_BCMHiFreqSigDataByte12Hi_nu;
  }

  /* End of MinMax: '<S14>/MinMax' */

  /* MinMax: '<S14>/MinMax1' incorporates:
   *  Constant: '<S14>/sat7'
   */
  if (VOPM_TMSC3WVMode_enum >= KOPM_BCMHiFreqSigDataByte12Lo_nu)
  {
    /* MinMax: '<S14>/MinMax1' */
    VOPM_BCMHiFreqSigDataByte12_nu = VOPM_TMSC3WVMode_enum;
  }
  else
  {
    /* MinMax: '<S14>/MinMax1' */
    VOPM_BCMHiFreqSigDataByte12_nu = KOPM_BCMHiFreqSigDataByte12Lo_nu;
  }

  /* End of MinMax: '<S14>/MinMax1' */
  /* End of Outputs for SubSystem: '<S10>/Subsys_VOPM_BCMHiFreqSigDataByte12_nu' */

  /* Outputs for Atomic SubSystem: '<S10>/Subsys_VOPM_BCMHiFreqSigDataByte13_nu' */
  /* Switch: '<S15>/Switch4' incorporates:
   *  Constant: '<S15>/sat3'
   */
  if (KOPM_BCMHiFreqSigDataByte13_nu_ovrdflg)
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Constant: '<S15>/sat4'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum = KOPM_BCMHiFreqSigDataByte13_nu_ovrdval;
  }
  else
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S15>/Data Type Conversion1'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_100ms_Bcm2OpmBAC_outputs())
            ->BCM_HighFreqSigData_Byte13;
  }

  /* End of Switch: '<S15>/Switch4' */

  /* MinMax: '<S15>/MinMax' incorporates:
   *  Constant: '<S15>/sat6'
   */
  if (VOPM_TMSC3WVMode_enum > KOPM_BCMHiFreqSigDataByte13Hi_nu)
  {
    /* MinMax: '<S153>/MinMax' */
    VOPM_TMSC3WVMode_enum = KOPM_BCMHiFreqSigDataByte13Hi_nu;
  }

  /* End of MinMax: '<S15>/MinMax' */

  /* MinMax: '<S15>/MinMax1' incorporates:
   *  Constant: '<S15>/sat7'
   */
  if (VOPM_TMSC3WVMode_enum >= KOPM_BCMHiFreqSigDataByte13Lo_nu)
  {
    /* MinMax: '<S15>/MinMax1' */
    VOPM_BCMHiFreqSigDataByte13_nu = VOPM_TMSC3WVMode_enum;
  }
  else
  {
    /* MinMax: '<S15>/MinMax1' */
    VOPM_BCMHiFreqSigDataByte13_nu = KOPM_BCMHiFreqSigDataByte13Lo_nu;
  }

  /* End of MinMax: '<S15>/MinMax1' */
  /* End of Outputs for SubSystem: '<S10>/Subsys_VOPM_BCMHiFreqSigDataByte13_nu' */

  /* Outputs for Atomic SubSystem: '<S10>/Subsys_VOPM_BCMHiFreqSigDataByte14_nu' */
  /* Switch: '<S16>/Switch4' incorporates:
   *  Constant: '<S16>/sat3'
   */
  if (KOPM_BCMHiFreqSigDataByte14_nu_ovrdflg)
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Constant: '<S16>/sat4'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum = KOPM_BCMHiFreqSigDataByte14_nu_ovrdval;
  }
  else
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S16>/Data Type Conversion1'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_100ms_Bcm2OpmBAC_outputs())
            ->BCM_HighFreqSigData_Byte14;
  }

  /* End of Switch: '<S16>/Switch4' */

  /* MinMax: '<S16>/MinMax' incorporates:
   *  Constant: '<S16>/sat6'
   */
  if (VOPM_TMSC3WVMode_enum > KOPM_BCMHiFreqSigDataByte14Hi_nu)
  {
    /* MinMax: '<S153>/MinMax' */
    VOPM_TMSC3WVMode_enum = KOPM_BCMHiFreqSigDataByte14Hi_nu;
  }

  /* End of MinMax: '<S16>/MinMax' */

  /* MinMax: '<S16>/MinMax1' incorporates:
   *  Constant: '<S16>/sat7'
   */
  if (VOPM_TMSC3WVMode_enum >= KOPM_BCMHiFreqSigDataByte14Lo_nu)
  {
    /* MinMax: '<S16>/MinMax1' */
    VOPM_BCMHiFreqSigDataByte14_nu = VOPM_TMSC3WVMode_enum;
  }
  else
  {
    /* MinMax: '<S16>/MinMax1' */
    VOPM_BCMHiFreqSigDataByte14_nu = KOPM_BCMHiFreqSigDataByte14Lo_nu;
  }

  /* End of MinMax: '<S16>/MinMax1' */
  /* End of Outputs for SubSystem: '<S10>/Subsys_VOPM_BCMHiFreqSigDataByte14_nu' */

  /* Outputs for Atomic SubSystem: '<S10>/Subsys_VOPM_BCMHiFreqSigDataByte15_nu' */
  /* Switch: '<S17>/Switch4' incorporates:
   *  Constant: '<S17>/sat3'
   */
  if (KOPM_BCMHiFreqSigDataByte15_nu_ovrdflg)
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Constant: '<S17>/sat4'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum = KOPM_BCMHiFreqSigDataByte15_nu_ovrdval;
  }
  else
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S17>/Data Type Conversion1'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_100ms_Bcm2OpmBAC_outputs())
            ->BCM_HighFreqSigData_Byte15;
  }

  /* End of Switch: '<S17>/Switch4' */

  /* MinMax: '<S17>/MinMax' incorporates:
   *  Constant: '<S17>/sat6'
   */
  if (VOPM_TMSC3WVMode_enum > KOPM_BCMHiFreqSigDataByte15Hi_nu)
  {
    /* MinMax: '<S153>/MinMax' */
    VOPM_TMSC3WVMode_enum = KOPM_BCMHiFreqSigDataByte15Hi_nu;
  }

  /* End of MinMax: '<S17>/MinMax' */

  /* MinMax: '<S17>/MinMax1' incorporates:
   *  Constant: '<S17>/sat7'
   */
  if (VOPM_TMSC3WVMode_enum >= KOPM_BCMHiFreqSigDataByte15Lo_nu)
  {
    /* MinMax: '<S17>/MinMax1' */
    VOPM_BCMHiFreqSigDataByte15_nu = VOPM_TMSC3WVMode_enum;
  }
  else
  {
    /* MinMax: '<S17>/MinMax1' */
    VOPM_BCMHiFreqSigDataByte15_nu = KOPM_BCMHiFreqSigDataByte15Lo_nu;
  }

  /* End of MinMax: '<S17>/MinMax1' */
  /* End of Outputs for SubSystem: '<S10>/Subsys_VOPM_BCMHiFreqSigDataByte15_nu' */

  /* BusCreator: '<S10>/BusCreator' */
  AppSwcOpm_ARID_DEF.BCM_HFSData_BAC_c.BCM_HighFreqSigData_Byte0 =
      VOPM_BCMHiFreqSigDataByte0_nu;
  AppSwcOpm_ARID_DEF.BCM_HFSData_BAC_c.BCM_HighFreqSigData_Byte1 =
      VOPM_BCMHiFreqSigDataByte1_nu;
  AppSwcOpm_ARID_DEF.BCM_HFSData_BAC_c.BCM_HighFreqSigData_Byte2 =
      VOPM_BCMHiFreqSigDataByte2_nu;
  AppSwcOpm_ARID_DEF.BCM_HFSData_BAC_c.BCM_HighFreqSigData_Byte3 =
      VOPM_BCMHiFreqSigDataByte3_nu;
  AppSwcOpm_ARID_DEF.BCM_HFSData_BAC_c.BCM_HighFreqSigData_Byte4 =
      VOPM_BCMHiFreqSigDataByte4_nu;
  AppSwcOpm_ARID_DEF.BCM_HFSData_BAC_c.BCM_HighFreqSigData_Byte5 =
      VOPM_BCMHiFreqSigDataByte5_nu;
  AppSwcOpm_ARID_DEF.BCM_HFSData_BAC_c.BCM_HighFreqSigData_Byte6 =
      VOPM_BCMHiFreqSigDataByte6_nu;
  AppSwcOpm_ARID_DEF.BCM_HFSData_BAC_c.BCM_HighFreqSigData_Byte7 =
      VOPM_BCMHiFreqSigDataByte7_nu;
  AppSwcOpm_ARID_DEF.BCM_HFSData_BAC_c.BCM_HighFreqSigData_Byte8 =
      VOPM_BCMHiFreqSigDataByte8_nu;
  AppSwcOpm_ARID_DEF.BCM_HFSData_BAC_c.BCM_HighFreqSigData_Byte9 =
      VOPM_BCMHiFreqSigDataByte9_nu;
  AppSwcOpm_ARID_DEF.BCM_HFSData_BAC_c.BCM_HighFreqSigData_Byte10 =
      VOPM_BCMHiFreqSigDataByte10_nu;
  AppSwcOpm_ARID_DEF.BCM_HFSData_BAC_c.BCM_HighFreqSigData_Byte11 =
      VOPM_BCMHiFreqSigDataByte11_nu;
  AppSwcOpm_ARID_DEF.BCM_HFSData_BAC_c.BCM_HighFreqSigData_Byte12 =
      VOPM_BCMHiFreqSigDataByte12_nu;
  AppSwcOpm_ARID_DEF.BCM_HFSData_BAC_c.BCM_HighFreqSigData_Byte13 =
      VOPM_BCMHiFreqSigDataByte13_nu;
  AppSwcOpm_ARID_DEF.BCM_HFSData_BAC_c.BCM_HighFreqSigData_Byte14 =
      VOPM_BCMHiFreqSigDataByte14_nu;
  AppSwcOpm_ARID_DEF.BCM_HFSData_BAC_c.BCM_HighFreqSigData_Byte15 =
      VOPM_BCMHiFreqSigDataByte15_nu;

  /* Outputs for Atomic SubSystem: '<S29>/Subsys_VOPM_ACIndoorTemp_C' */
  /* Switch: '<S67>/Switch4' incorporates:
   *  Constant: '<S67>/sat3'
   */
  if (KOPM_ACIndoorTemp_C_ovrdflg)
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Constant: '<S67>/sat4'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_ACIndoorTemp_C_ovrdval;
  }
  else
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Inport: '<Root>/TMS2VCU_AC_3_State_Outputs'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs())->AC_IndoorTemp;
  }

  /* End of Switch: '<S67>/Switch4' */

  /* MinMax: '<S67>/MinMax' incorporates:
   *  Constant: '<S67>/sat6'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm > KOPM_ACIndoorTempHi_C)
  {
    /* MinMax: '<S39>/MinMax' */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_ACIndoorTempHi_C;
  }

  /* End of MinMax: '<S67>/MinMax' */

  /* MinMax: '<S67>/MinMax1' incorporates:
   *  Constant: '<S67>/sat7'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm >= KOPM_ACIndoorTempLo_C)
  {
    /* MinMax: '<S67>/MinMax1' */
    VOPM_ACIndoorTemp_C = VOPM_TMSAcPMPRealRPM_rpm;
  }
  else
  {
    /* MinMax: '<S67>/MinMax1' */
    VOPM_ACIndoorTemp_C = KOPM_ACIndoorTempLo_C;
  }

  /* End of MinMax: '<S67>/MinMax1' */
  /* End of Outputs for SubSystem: '<S29>/Subsys_VOPM_ACIndoorTemp_C' */

  /* Outputs for Atomic SubSystem: '<S29>/Subsys_VOPM_ACExtdDefrstActvReq_flg' */
  /* Switch: '<S66>/Switch4' incorporates:
   *  Constant: '<S66>/sat3'
   */
  if (KOPM_ACExtdDefrstActvReq_flg_ovrdflg)
  {
    /* Switch: '<S66>/Switch4' incorporates:
     *  Constant: '<S66>/sat4'
     */
    VOPM_ACExtdDefrstActvReq_flg = KOPM_ACExtdDefrstActvReq_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S66>/Switch4' incorporates:
     *  Inport: '<Root>/TMS2VCU_AC_3_State_Outputs'
     */
    VOPM_ACExtdDefrstActvReq_flg =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs())->AC_ExtdDefrostActvReq;
  }

  /* End of Switch: '<S66>/Switch4' */
  /* End of Outputs for SubSystem: '<S29>/Subsys_VOPM_ACExtdDefrstActvReq_flg' */

  /* Outputs for Atomic SubSystem: '<S29>/Subsys_VOPM_ACEnvirTemp_C' */
  /* Switch: '<S65>/Switch4' incorporates:
   *  Constant: '<S65>/sat3'
   */
  if (KOPM_ACEnvirTemp_C_ovrdflg)
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Constant: '<S65>/sat4'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_ACEnvirTemp_C_ovrdval;
  }
  else
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Inport: '<Root>/TMS2VCU_AC_3_State_Outputs'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs())->AC_EnvirTemp;
  }

  /* End of Switch: '<S65>/Switch4' */

  /* MinMax: '<S65>/MinMax' incorporates:
   *  Constant: '<S65>/sat6'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm > KOPM_ACEnvirTempHi_C)
  {
    /* MinMax: '<S39>/MinMax' */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_ACEnvirTempHi_C;
  }

  /* End of MinMax: '<S65>/MinMax' */

  /* MinMax: '<S65>/MinMax1' incorporates:
   *  Constant: '<S65>/sat7'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm >= KOPM_ACEnvirTempLo_C)
  {
    /* MinMax: '<S65>/MinMax1' */
    VOPM_ACEnvirTemp_C = VOPM_TMSAcPMPRealRPM_rpm;
  }
  else
  {
    /* MinMax: '<S65>/MinMax1' */
    VOPM_ACEnvirTemp_C = KOPM_ACEnvirTempLo_C;
  }

  /* End of MinMax: '<S65>/MinMax1' */
  /* End of Outputs for SubSystem: '<S29>/Subsys_VOPM_ACEnvirTemp_C' */

  /* Outputs for Atomic SubSystem: '<S29>/Subsys_VOPM_ACEnvirTempVld_flg' */
  /* Switch: '<S64>/Switch4' incorporates:
   *  Constant: '<S64>/sat3'
   */
  if (KOPM_ACEnvirTempVld_flg_ovrdflg)
  {
    /* Switch: '<S64>/Switch4' incorporates:
     *  Constant: '<S64>/sat4'
     */
    VOPM_ACEnvirTempVld_flg = KOPM_ACEnvirTempVld_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S64>/Switch4' incorporates:
     *  Inport: '<Root>/TMS2VCU_AC_3_State_Outputs'
     */
    VOPM_ACEnvirTempVld_flg =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs())->AC_EnvirTempV;
  }

  /* End of Switch: '<S64>/Switch4' */
  /* End of Outputs for SubSystem: '<S29>/Subsys_VOPM_ACEnvirTempVld_flg' */

  /* Outputs for Atomic SubSystem: '<S29>/Subsys_VOPM_TMSOHXOutTmp_C' */
  /* Switch: '<S71>/Switch4' incorporates:
   *  Constant: '<S71>/sat3'
   */
  if (KOPM_TMSOHXOutTmp_C_ovrdflg)
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Constant: '<S71>/sat4'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_TMSOHXOutTmp_C_ovrdval;
  }
  else
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  DataTypeConversion: '<S71>/Data Type Conversion1'
     *  Inport: '<Root>/TMS2VCU_AC_3_State_Outputs'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm = (float32)(Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs())->TMS_OHXOutTmp;
  }

  /* End of Switch: '<S71>/Switch4' */

  /* MinMax: '<S71>/MinMax' incorporates:
   *  Constant: '<S71>/sat6'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm > KOPM_TMSOHXOutTmpHi_C)
  {
    /* MinMax: '<S39>/MinMax' */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_TMSOHXOutTmpHi_C;
  }

  /* End of MinMax: '<S71>/MinMax' */

  /* MinMax: '<S71>/MinMax1' incorporates:
   *  Constant: '<S71>/sat7'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm >= KOPM_TMSOHXOutTmpLo_C)
  {
    /* MinMax: '<S71>/MinMax1' */
    VOPM_TMSOHXOutTmp_C = VOPM_TMSAcPMPRealRPM_rpm;
  }
  else
  {
    /* MinMax: '<S71>/MinMax1' */
    VOPM_TMSOHXOutTmp_C = KOPM_TMSOHXOutTmpLo_C;
  }

  /* End of MinMax: '<S71>/MinMax1' */
  /* End of Outputs for SubSystem: '<S29>/Subsys_VOPM_TMSOHXOutTmp_C' */

  /* Outputs for Atomic SubSystem: '<S29>/Subsys_VOPM_TMSEvapTmp_C' */
  /* Switch: '<S70>/Switch4' incorporates:
   *  Constant: '<S70>/sat3'
   */
  if (KOPM_TMSEvapTmp_C_ovrdflg)
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Constant: '<S70>/sat4'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_TMSEvapTmp_C_ovrdval;
  }
  else
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  DataTypeConversion: '<S70>/Data Type Conversion1'
     *  Inport: '<Root>/TMS2VCU_AC_3_State_Outputs'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm = (float32)(Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs())->TMS_EvapTmp;
  }

  /* End of Switch: '<S70>/Switch4' */

  /* MinMax: '<S70>/MinMax' incorporates:
   *  Constant: '<S70>/sat6'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm > KOPM_TMSEvapTmpHi_C)
  {
    /* MinMax: '<S39>/MinMax' */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_TMSEvapTmpHi_C;
  }

  /* End of MinMax: '<S70>/MinMax' */

  /* MinMax: '<S70>/MinMax1' incorporates:
   *  Constant: '<S70>/sat7'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm >= KOPM_TMSEvapTmpLo_C)
  {
    /* MinMax: '<S70>/MinMax1' */
    VOPM_TMSEvapTmp_C = VOPM_TMSAcPMPRealRPM_rpm;
  }
  else
  {
    /* MinMax: '<S70>/MinMax1' */
    VOPM_TMSEvapTmp_C = KOPM_TMSEvapTmpLo_C;
  }

  /* End of MinMax: '<S70>/MinMax1' */
  /* End of Outputs for SubSystem: '<S29>/Subsys_VOPM_TMSEvapTmp_C' */

  /* Outputs for Atomic SubSystem: '<S29>/Subsys_VOPM_TMSEvapOutTmp_C' */
  /* Switch: '<S69>/Switch4' incorporates:
   *  Constant: '<S69>/sat3'
   */
  if (KOPM_TMSEvapOutTmp_C_ovrdflg)
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Constant: '<S69>/sat4'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_TMSEvapOutTmp_C_ovrdval;
  }
  else
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  DataTypeConversion: '<S69>/Data Type Conversion1'
     *  Inport: '<Root>/TMS2VCU_AC_3_State_Outputs'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm = (float32)(Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs())->TMS_EvapOutTmp;
  }

  /* End of Switch: '<S69>/Switch4' */

  /* MinMax: '<S69>/MinMax' incorporates:
   *  Constant: '<S69>/sat6'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm > KOPM_TMSEvapOutTmpHi_C)
  {
    /* MinMax: '<S39>/MinMax' */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_TMSEvapOutTmpHi_C;
  }

  /* End of MinMax: '<S69>/MinMax' */

  /* MinMax: '<S69>/MinMax1' incorporates:
   *  Constant: '<S69>/sat7'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm >= KOPM_TMSEvapOutTmpLo_C)
  {
    /* MinMax: '<S69>/MinMax1' */
    VOPM_TMSEvapOutTmp_C = VOPM_TMSAcPMPRealRPM_rpm;
  }
  else
  {
    /* MinMax: '<S69>/MinMax1' */
    VOPM_TMSEvapOutTmp_C = KOPM_TMSEvapOutTmpLo_C;
  }

  /* End of MinMax: '<S69>/MinMax1' */
  /* End of Outputs for SubSystem: '<S29>/Subsys_VOPM_TMSEvapOutTmp_C' */

  /* Outputs for Atomic SubSystem: '<S29>/Subsys_VOPM_TMSChillerOutTmp_C' */
  /* Switch: '<S68>/Switch4' incorporates:
   *  Constant: '<S68>/sat3'
   */
  if (KOPM_TMSChillerOutTmp_C_ovrdflg)
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Constant: '<S68>/sat4'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_TMSChillerOutTmp_C_ovrdval;
  }
  else
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  DataTypeConversion: '<S68>/Data Type Conversion1'
     *  Inport: '<Root>/TMS2VCU_AC_3_State_Outputs'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm = (float32)(Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs())->TMS_ChillerOutTmp;
  }

  /* End of Switch: '<S68>/Switch4' */

  /* MinMax: '<S68>/MinMax' incorporates:
   *  Constant: '<S68>/sat6'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm > KOPM_TMSChillerOutTmpHi_C)
  {
    /* MinMax: '<S39>/MinMax' */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_TMSChillerOutTmpHi_C;
  }

  /* End of MinMax: '<S68>/MinMax' */

  /* MinMax: '<S68>/MinMax1' incorporates:
   *  Constant: '<S68>/sat7'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm >= KOPM_TMSChillerOutTmpLo_C)
  {
    /* MinMax: '<S68>/MinMax1' */
    VOPM_TMSChillerOutTmp_C = VOPM_TMSAcPMPRealRPM_rpm;
  }
  else
  {
    /* MinMax: '<S68>/MinMax1' */
    VOPM_TMSChillerOutTmp_C = KOPM_TMSChillerOutTmpLo_C;
  }

  /* End of MinMax: '<S68>/MinMax1' */
  /* End of Outputs for SubSystem: '<S29>/Subsys_VOPM_TMSChillerOutTmp_C' */

  /* BusCreator: '<S29>/BusCreator' incorporates:
   *  Switch: '<S66>/Switch4'
   */
  AppSwcOpm_ARID_DEF.AC_3_State_BOD_k.AC_ExtdDefrostActvReq =
      VOPM_ACExtdDefrstActvReq_flg;

  /* DataTypeConversion: '<S29>/DataTypeConversion1' incorporates:
   *  Constant: '<S76>/Constant'
   *  Constant: '<S76>/Constant1'
   *  Product: '<S76>/Product1'
   *  Sum: '<S76>/Add'
   */
  tmp = (VOPM_ACEnvirTemp_C - -40.0F) * 2.0F;
  if (tmp < 256.0F)
  {
    if (tmp >= 0.0F)
    {
      /* BusCreator: '<S29>/BusCreator' */
      AppSwcOpm_ARID_DEF.AC_3_State_BOD_k.AC_EnvirTemp = (uint8)tmp;
    }
    else
    {
      /* BusCreator: '<S29>/BusCreator' */
      AppSwcOpm_ARID_DEF.AC_3_State_BOD_k.AC_EnvirTemp = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S29>/BusCreator' */
    AppSwcOpm_ARID_DEF.AC_3_State_BOD_k.AC_EnvirTemp = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S29>/DataTypeConversion1' */

  /* BusCreator: '<S29>/BusCreator' incorporates:
   *  Switch: '<S64>/Switch4'
   */
  AppSwcOpm_ARID_DEF.AC_3_State_BOD_k.AC_EnvirTempV = VOPM_ACEnvirTempVld_flg;

  /* DataTypeConversion: '<S29>/DataTypeConversion3' incorporates:
   *  Constant: '<S72>/Constant'
   *  Constant: '<S72>/Constant1'
   *  Product: '<S72>/Product1'
   *  Sum: '<S72>/Add'
   */
  tmp = (VOPM_ACIndoorTemp_C - -40.0F) * 2.0F;
  if (tmp < 256.0F)
  {
    if (tmp >= 0.0F)
    {
      /* BusCreator: '<S29>/BusCreator' */
      AppSwcOpm_ARID_DEF.AC_3_State_BOD_k.AC_IndoorTemp = (uint8)tmp;
    }
    else
    {
      /* BusCreator: '<S29>/BusCreator' */
      AppSwcOpm_ARID_DEF.AC_3_State_BOD_k.AC_IndoorTemp = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S29>/BusCreator' */
    AppSwcOpm_ARID_DEF.AC_3_State_BOD_k.AC_IndoorTemp = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S29>/DataTypeConversion3' */

  /* DataTypeConversion: '<S29>/DataTypeConversion4' incorporates:
   *  Constant: '<S73>/Constant'
   *  Sum: '<S73>/Add'
   */
  if (VOPM_TMSOHXOutTmp_C - -40.0F < 256.0F)
  {
    if (VOPM_TMSOHXOutTmp_C - -40.0F >= 0.0F)
    {
      /* BusCreator: '<S29>/BusCreator' */
      AppSwcOpm_ARID_DEF.AC_3_State_BOD_k.TMS_OHXOutTmp = (uint8)(VOPM_TMSOHXOutTmp_C - -40.0F);
    }
    else
    {
      /* BusCreator: '<S29>/BusCreator' */
      AppSwcOpm_ARID_DEF.AC_3_State_BOD_k.TMS_OHXOutTmp = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S29>/BusCreator' */
    AppSwcOpm_ARID_DEF.AC_3_State_BOD_k.TMS_OHXOutTmp = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S29>/DataTypeConversion4' */

  /* DataTypeConversion: '<S29>/DataTypeConversion5' incorporates:
   *  Constant: '<S74>/Constant'
   *  Sum: '<S74>/Add'
   */
  if (VOPM_TMSEvapTmp_C - -50.0F < 256.0F)
  {
    if (VOPM_TMSEvapTmp_C - -50.0F >= 0.0F)
    {
      /* BusCreator: '<S29>/BusCreator' */
      AppSwcOpm_ARID_DEF.AC_3_State_BOD_k.TMS_EvapTmp = (uint8)(VOPM_TMSEvapTmp_C - -50.0F);
    }
    else
    {
      /* BusCreator: '<S29>/BusCreator' */
      AppSwcOpm_ARID_DEF.AC_3_State_BOD_k.TMS_EvapTmp = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S29>/BusCreator' */
    AppSwcOpm_ARID_DEF.AC_3_State_BOD_k.TMS_EvapTmp = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S29>/DataTypeConversion5' */

  /* DataTypeConversion: '<S29>/DataTypeConversion6' incorporates:
   *  Constant: '<S75>/Constant'
   *  Sum: '<S75>/Add'
   */
  if (VOPM_TMSEvapOutTmp_C - -40.0F < 256.0F)
  {
    if (VOPM_TMSEvapOutTmp_C - -40.0F >= 0.0F)
    {
      /* BusCreator: '<S29>/BusCreator' */
      AppSwcOpm_ARID_DEF.AC_3_State_BOD_k.TMS_EvapOutTmp = (uint8)(VOPM_TMSEvapOutTmp_C - -40.0F);
    }
    else
    {
      /* BusCreator: '<S29>/BusCreator' */
      AppSwcOpm_ARID_DEF.AC_3_State_BOD_k.TMS_EvapOutTmp = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S29>/BusCreator' */
    AppSwcOpm_ARID_DEF.AC_3_State_BOD_k.TMS_EvapOutTmp = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S29>/DataTypeConversion6' */

  /* DataTypeConversion: '<S29>/DataTypeConversion7' incorporates:
   *  Constant: '<S77>/Constant'
   *  Sum: '<S77>/Add'
   */
  if (VOPM_TMSChillerOutTmp_C - -10.0F < 256.0F)
  {
    if (VOPM_TMSChillerOutTmp_C - -10.0F >= 0.0F)
    {
      /* BusCreator: '<S29>/BusCreator' */
      AppSwcOpm_ARID_DEF.AC_3_State_BOD_k.TMS_ChillerOutTmp = (uint8)(VOPM_TMSChillerOutTmp_C - -10.0F);
    }
    else
    {
      /* BusCreator: '<S29>/BusCreator' */
      AppSwcOpm_ARID_DEF.AC_3_State_BOD_k.TMS_ChillerOutTmp = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S29>/BusCreator' */
    AppSwcOpm_ARID_DEF.AC_3_State_BOD_k.TMS_ChillerOutTmp = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S29>/DataTypeConversion7' */

  /* Outputs for Atomic SubSystem: '<S30>/Subsys_VOPM_ACRefrgLoPres_kPa' */
  /* Switch: '<S82>/Switch4' incorporates:
   *  Constant: '<S82>/sat3'
   */
  if (KOPM_ACRefrgLoPres_kPa_ovrdflg)
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Constant: '<S82>/sat4'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_ACRefrgLoPres_kPa_ovrdval;
  }
  else
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Inport: '<Root>/TMS2VCU_AC_8_status_Outputs'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_8_status_Outputs_TMS2VCU_AC_8_status_Outputs())->AC_RefrgLoPressure;
  }

  /* End of Switch: '<S82>/Switch4' */

  /* MinMax: '<S82>/MinMax' incorporates:
   *  Constant: '<S82>/sat6'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm > KOPM_ACRefrgLoPresHi_kPa)
  {
    /* MinMax: '<S39>/MinMax' */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_ACRefrgLoPresHi_kPa;
  }

  /* End of MinMax: '<S82>/MinMax' */

  /* MinMax: '<S82>/MinMax1' incorporates:
   *  Constant: '<S82>/sat7'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm >= KOPM_ACRefrgLoPresLo_kPa)
  {
    /* MinMax: '<S82>/MinMax1' */
    VOPM_ACRefrgLoPres_kPa = VOPM_TMSAcPMPRealRPM_rpm;
  }
  else
  {
    /* MinMax: '<S82>/MinMax1' */
    VOPM_ACRefrgLoPres_kPa = KOPM_ACRefrgLoPresLo_kPa;
  }

  /* End of MinMax: '<S82>/MinMax1' */
  /* End of Outputs for SubSystem: '<S30>/Subsys_VOPM_ACRefrgLoPres_kPa' */

  /* Outputs for Atomic SubSystem: '<S30>/Subsys_VOPM_ACRefrgLoPresVld_flg' */
  /* Switch: '<S81>/Switch4' incorporates:
   *  Constant: '<S81>/sat3'
   */
  if (KOPM_ACRefrgLoPresVld_flg_ovrdflg)
  {
    /* Switch: '<S81>/Switch4' incorporates:
     *  Constant: '<S81>/sat4'
     */
    VOPM_ACRefrgLoPresVld_flg = KOPM_ACRefrgLoPresVld_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S81>/Switch4' incorporates:
     *  Inport: '<Root>/TMS2VCU_AC_8_status_Outputs'
     */
    VOPM_ACRefrgLoPresVld_flg =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_8_status_Outputs_TMS2VCU_AC_8_status_Outputs())->AC_RefrgLoPressureV;
  }

  /* End of Switch: '<S81>/Switch4' */
  /* End of Outputs for SubSystem: '<S30>/Subsys_VOPM_ACRefrgLoPresVld_flg' */

  /* Outputs for Atomic SubSystem: '<S30>/Subsys_VOPM_ACEvapTgtTemp_C' */
  /* Switch: '<S79>/Switch4' incorporates:
   *  Constant: '<S79>/sat3'
   */
  if (KOPM_ACEvapTgtTemp_C_ovrdflg)
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Constant: '<S79>/sat4'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_ACEvapTgtTemp_C_ovrdval;
  }
  else
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Inport: '<Root>/TMS2VCU_AC_8_status_Outputs'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_8_status_Outputs_TMS2VCU_AC_8_status_Outputs())->AC_EvapTgtTemp;
  }

  /* End of Switch: '<S79>/Switch4' */

  /* MinMax: '<S79>/MinMax' incorporates:
   *  Constant: '<S79>/sat6'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm > KOPM_ACEvapTgtTempHi_C)
  {
    /* MinMax: '<S39>/MinMax' */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_ACEvapTgtTempHi_C;
  }

  /* End of MinMax: '<S79>/MinMax' */

  /* MinMax: '<S79>/MinMax1' incorporates:
   *  Constant: '<S79>/sat7'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm >= KOPM_ACEvapTgtTempLo_C)
  {
    /* MinMax: '<S79>/MinMax1' */
    VOPM_ACEvapTgtTemp_C = VOPM_TMSAcPMPRealRPM_rpm;
  }
  else
  {
    /* MinMax: '<S79>/MinMax1' */
    VOPM_ACEvapTgtTemp_C = KOPM_ACEvapTgtTempLo_C;
  }

  /* End of MinMax: '<S79>/MinMax1' */
  /* End of Outputs for SubSystem: '<S30>/Subsys_VOPM_ACEvapTgtTemp_C' */

  /* Outputs for Atomic SubSystem: '<S30>/Subsys_VOPM_ACHVPTCOnRq_enum' */
  /* Switch: '<S80>/Switch4' incorporates:
   *  Constant: '<S80>/sat3'
   */
  if (KOPM_ACHVPTCOnRq_enum_ovrdflg)
  {
    /* MinMax: '<S80>/MinMax' incorporates:
     *  Constant: '<S80>/sat4'
     *  DataTypeConversion: '<S35>/DataTypeConversion2'
     */
    VOPM_HVCHEnbld_enum = KOPM_ACHVPTCOnRq_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S80>/MinMax' incorporates:
     *  DataTypeConversion: '<S35>/DataTypeConversion2'
     *  Inport: '<Root>/TMS2VCU_AC_8_status_Outputs'
     */
    VOPM_HVCHEnbld_enum =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_8_status_Outputs_TMS2VCU_AC_8_status_Outputs())->AC_HV_PTC_On_Rq;
  }

  /* End of Switch: '<S80>/Switch4' */

  /* MinMax: '<S80>/MinMax' incorporates:
   *  Constant: '<S80>/sat6'
   */
  if (VOPM_HVCHEnbld_enum > KOPM_ACHVPTCOnRqHi_enum)
  {
    VOPM_HVCHEnbld_enum = KOPM_ACHVPTCOnRqHi_enum;
  }

  /* MinMax: '<S80>/MinMax1' incorporates:
   *  Constant: '<S80>/sat7'
   */
  if (VOPM_HVCHEnbld_enum >= KOPM_ACHVPTCOnRqLo_enum)
  {
    /* MinMax: '<S80>/MinMax1' */
    VOPM_ACHVPTCOnRq_enum = VOPM_HVCHEnbld_enum;
  }
  else
  {
    /* MinMax: '<S80>/MinMax1' */
    VOPM_ACHVPTCOnRq_enum = KOPM_ACHVPTCOnRqLo_enum;
  }

  /* End of MinMax: '<S80>/MinMax1' */
  /* End of Outputs for SubSystem: '<S30>/Subsys_VOPM_ACHVPTCOnRq_enum' */

  /* Outputs for Atomic SubSystem: '<S30>/Subsys_VOPM_ACAutoFrntFanSpd_enum' */
  /* Switch: '<S78>/Switch4' incorporates:
   *  Constant: '<S78>/sat3'
   */
  if (KOPM_ACAutoFrntFanSpd_enum_ovrdflg)
  {
    /* MinMax: '<S80>/MinMax' incorporates:
     *  Constant: '<S78>/sat4'
     *  DataTypeConversion: '<S35>/DataTypeConversion2'
     */
    VOPM_HVCHEnbld_enum = KOPM_ACAutoFrntFanSpd_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S80>/MinMax' incorporates:
     *  DataTypeConversion: '<S35>/DataTypeConversion2'
     *  Inport: '<Root>/TMS2VCU_AC_8_status_Outputs'
     */
    VOPM_HVCHEnbld_enum =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_8_status_Outputs_TMS2VCU_AC_8_status_Outputs())->AC_Auto_FrontFanSpd;
  }

  /* End of Switch: '<S78>/Switch4' */

  /* MinMax: '<S78>/MinMax' incorporates:
   *  Constant: '<S78>/sat6'
   */
  if (VOPM_HVCHEnbld_enum > KOPM_ACAutoFrntFanSpdHi_enum)
  {
    /* MinMax: '<S80>/MinMax' */
    VOPM_HVCHEnbld_enum = KOPM_ACAutoFrntFanSpdHi_enum;
  }

  /* End of MinMax: '<S78>/MinMax' */

  /* MinMax: '<S78>/MinMax1' incorporates:
   *  Constant: '<S78>/sat7'
   */
  if (VOPM_HVCHEnbld_enum >= KOPM_ACAutoFrntFanSpdLo_enum)
  {
    /* MinMax: '<S78>/MinMax1' */
    VOPM_ACAutoFrntFanSpd_enum = VOPM_HVCHEnbld_enum;
  }
  else
  {
    /* MinMax: '<S78>/MinMax1' */
    VOPM_ACAutoFrntFanSpd_enum = KOPM_ACAutoFrntFanSpdLo_enum;
  }

  /* End of MinMax: '<S78>/MinMax1' */
  /* End of Outputs for SubSystem: '<S30>/Subsys_VOPM_ACAutoFrntFanSpd_enum' */

  /* Outputs for Atomic SubSystem: '<S30>/Subsys_VOPM_TMSMotInletCooltTemp_C' */
  /* Switch: '<S85>/Switch4' incorporates:
   *  Constant: '<S85>/sat3'
   */
  if (KOPM_TMSMotInletCooltTemp_C_ovrdflg)
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Constant: '<S85>/sat4'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_TMSMotInletCooltTemp_C_ovrdval;
  }
  else
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S85>/Data Type Conversion1'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm = (float32)(Rte_IrvIRead_Runbl_OpmCanTx_100ms_TMS2VCU_PPV_outputs())
                                   ->TMS_MotInletCooltTemp;
  }

  /* End of Switch: '<S85>/Switch4' */

  /* MinMax: '<S85>/MinMax' incorporates:
   *  Constant: '<S85>/sat6'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm > KOPM_TMSMotInletCooltTempHi_C)
  {
    /* MinMax: '<S39>/MinMax' */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_TMSMotInletCooltTempHi_C;
  }

  /* End of MinMax: '<S85>/MinMax' */

  /* MinMax: '<S85>/MinMax1' incorporates:
   *  Constant: '<S85>/sat7'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm >= KOPM_TMSMotInletCooltTempLo_C)
  {
    /* MinMax: '<S85>/MinMax1' */
    VOPM_TMSMotInletCooltTemp_C = VOPM_TMSAcPMPRealRPM_rpm;
  }
  else
  {
    /* MinMax: '<S85>/MinMax1' */
    VOPM_TMSMotInletCooltTemp_C = KOPM_TMSMotInletCooltTempLo_C;
  }

  /* End of MinMax: '<S85>/MinMax1' */
  /* End of Outputs for SubSystem: '<S30>/Subsys_VOPM_TMSMotInletCooltTemp_C' */

  /* Outputs for Atomic SubSystem: '<S30>/Subsys_VOPM_TMSBATThermMod_enum' */
  /* Switch: '<S83>/Switch4' incorporates:
   *  Constant: '<S83>/sat3'
   */
  if (KOPM_TMSBATThermMod_enum_ovrdflg)
  {
    /* MinMax: '<S83>/MinMax' incorporates:
     *  Constant: '<S83>/sat4'
     *  DataTypeConversion: '<S35>/DataTypeConversion3'
     */
    VOPM_TMSPwrCoolFanSpdDuty_pct = KOPM_TMSBATThermMod_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S83>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S35>/DataTypeConversion3'
     *  DataTypeConversion: '<S83>/Data Type Conversion1'
     */
    VOPM_TMSPwrCoolFanSpdDuty_pct =
        (Rte_IrvIRead_Runbl_OpmCanTx_100ms_TMS2VCU_PPV_outputs())
            ->TMS_BATThermalMod;
  }

  /* End of Switch: '<S83>/Switch4' */

  /* MinMax: '<S83>/MinMax' incorporates:
   *  Constant: '<S83>/sat6'
   */
  if (VOPM_TMSPwrCoolFanSpdDuty_pct > KOPM_TMSBATThermModHi_enum)
  {
    VOPM_TMSPwrCoolFanSpdDuty_pct = KOPM_TMSBATThermModHi_enum;
  }

  /* MinMax: '<S83>/MinMax1' incorporates:
   *  Constant: '<S83>/sat7'
   */
  if (VOPM_TMSPwrCoolFanSpdDuty_pct >= KOPM_TMSBATThermModLo_enum)
  {
    /* MinMax: '<S83>/MinMax1' */
    VOPM_TMSBATThermMod_enum = VOPM_TMSPwrCoolFanSpdDuty_pct;
  }
  else
  {
    /* MinMax: '<S83>/MinMax1' */
    VOPM_TMSBATThermMod_enum = KOPM_TMSBATThermModLo_enum;
  }

  /* End of MinMax: '<S83>/MinMax1' */
  /* End of Outputs for SubSystem: '<S30>/Subsys_VOPM_TMSBATThermMod_enum' */

  /* Outputs for Atomic SubSystem: '<S30>/Subsys_VOPM_TMSCabThermMod_enum' */
  /* Switch: '<S84>/Switch4' incorporates:
   *  Constant: '<S84>/sat3'
   */
  if (KOPM_TMSCabThermMod_enum_ovrdflg)
  {
    /* MinMax: '<S83>/MinMax' incorporates:
     *  Constant: '<S84>/sat4'
     *  DataTypeConversion: '<S35>/DataTypeConversion3'
     */
    VOPM_TMSPwrCoolFanSpdDuty_pct = KOPM_TMSCabThermMod_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S83>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S35>/DataTypeConversion3'
     *  DataTypeConversion: '<S84>/Data Type Conversion1'
     */
    VOPM_TMSPwrCoolFanSpdDuty_pct =
        (Rte_IrvIRead_Runbl_OpmCanTx_100ms_TMS2VCU_PPV_outputs())
            ->TMS_CabThermalMod;
  }

  /* End of Switch: '<S84>/Switch4' */

  /* MinMax: '<S84>/MinMax' incorporates:
   *  Constant: '<S84>/sat6'
   */
  if (VOPM_TMSPwrCoolFanSpdDuty_pct > KOPM_TMSCabThermModHi_enum)
  {
    /* MinMax: '<S83>/MinMax' */
    VOPM_TMSPwrCoolFanSpdDuty_pct = KOPM_TMSCabThermModHi_enum;
  }

  /* End of MinMax: '<S84>/MinMax' */

  /* MinMax: '<S84>/MinMax1' incorporates:
   *  Constant: '<S84>/sat7'
   */
  if (VOPM_TMSPwrCoolFanSpdDuty_pct >= KOPM_TMSCabThermModLo_enum)
  {
    /* MinMax: '<S84>/MinMax1' */
    VOPM_TMSCabThermMod_enum = VOPM_TMSPwrCoolFanSpdDuty_pct;
  }
  else
  {
    /* MinMax: '<S84>/MinMax1' */
    VOPM_TMSCabThermMod_enum = KOPM_TMSCabThermModLo_enum;
  }

  /* End of MinMax: '<S84>/MinMax1' */
  /* End of Outputs for SubSystem: '<S30>/Subsys_VOPM_TMSCabThermMod_enum' */

  /* Outputs for Atomic SubSystem: '<S30>/Subsys_VOPM_TMSPwrCoolFanSpdDuty_pct' */
  /* Switch: '<S86>/Switch4' incorporates:
   *  Constant: '<S86>/sat3'
   */
  if (KOPM_TMSPwrCoolFanSpdDuty_pct_ovrdflg)
  {
    /* MinMax: '<S83>/MinMax' incorporates:
     *  Constant: '<S86>/sat4'
     *  DataTypeConversion: '<S35>/DataTypeConversion3'
     */
    VOPM_TMSPwrCoolFanSpdDuty_pct = KOPM_TMSPwrCoolFanSpdDuty_pct_ovrdval;
  }
  else
  {
    /* MinMax: '<S83>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S35>/DataTypeConversion3'
     *  DataTypeConversion: '<S86>/Data Type Conversion1'
     */
    VOPM_TMSPwrCoolFanSpdDuty_pct = (uint8)(Rte_IrvIRead_Runbl_OpmCanTx_100ms_TMS2VCU_PPV_outputs())
                                        ->TMS_PwrCoolFanSpdDuty;
  }

  /* End of Switch: '<S86>/Switch4' */

  /* MinMax: '<S86>/MinMax' incorporates:
   *  Constant: '<S86>/sat6'
   */
  if (VOPM_TMSPwrCoolFanSpdDuty_pct > KOPM_TMSPwrCoolFanSpdDutyHi_pct)
  {
    /* MinMax: '<S83>/MinMax' */
    VOPM_TMSPwrCoolFanSpdDuty_pct = KOPM_TMSPwrCoolFanSpdDutyHi_pct;
  }

  /* End of MinMax: '<S86>/MinMax' */

  /* MinMax: '<S86>/MinMax1' incorporates:
   *  Constant: '<S86>/sat7'
   */
  if (VOPM_TMSPwrCoolFanSpdDuty_pct < KOPM_TMSPwrCoolFanSpdDutyLo_pct)
  {
    /* MinMax: '<S83>/MinMax' incorporates:
     *  MinMax: '<S86>/MinMax1'
     */
    VOPM_TMSPwrCoolFanSpdDuty_pct = KOPM_TMSPwrCoolFanSpdDutyLo_pct;
  }

  /* End of MinMax: '<S86>/MinMax1' */
  /* End of Outputs for SubSystem: '<S30>/Subsys_VOPM_TMSPwrCoolFanSpdDuty_pct' */

  /* DataTypeConversion: '<S30>/DataTypeConversion' incorporates:
   *  Constant: '<S87>/Constant1'
   *  Product: '<S87>/Product1'
   *  Sum: '<S87>/Add'
   */
  tmp = VOPM_ACRefrgLoPres_kPa * 0.1F;
  if (tmp < 256.0F)
  {
    if (tmp >= 0.0F)
    {
      /* BusCreator: '<S30>/BusCreator' */
      AppSwcOpm_ARID_DEF.AC_8_status_BOD_o.AC_RefrgLoPressure = (uint8)tmp;
    }
    else
    {
      /* BusCreator: '<S30>/BusCreator' */
      AppSwcOpm_ARID_DEF.AC_8_status_BOD_o.AC_RefrgLoPressure = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S30>/BusCreator' */
    AppSwcOpm_ARID_DEF.AC_8_status_BOD_o.AC_RefrgLoPressure = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S30>/DataTypeConversion' */

  /* BusCreator: '<S30>/BusCreator' incorporates:
   *  Switch: '<S81>/Switch4'
   */
  AppSwcOpm_ARID_DEF.AC_8_status_BOD_o.AC_RefrgLoPressureV =
      VOPM_ACRefrgLoPresVld_flg;

  /* DataTypeConversion: '<S30>/DataTypeConversion2' incorporates:
   *  Constant: '<S88>/Constant'
   *  Constant: '<S88>/Constant1'
   *  Product: '<S88>/Product1'
   *  Sum: '<S88>/Add'
   */
  tmp = (VOPM_ACEvapTgtTemp_C - -40.0F) * 2.0F;
  if (tmp < 256.0F)
  {
    if (tmp >= 0.0F)
    {
      /* BusCreator: '<S30>/BusCreator' */
      AppSwcOpm_ARID_DEF.AC_8_status_BOD_o.AC_EvapTgtTemp = (uint8)tmp;
    }
    else
    {
      /* BusCreator: '<S30>/BusCreator' */
      AppSwcOpm_ARID_DEF.AC_8_status_BOD_o.AC_EvapTgtTemp = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S30>/BusCreator' */
    AppSwcOpm_ARID_DEF.AC_8_status_BOD_o.AC_EvapTgtTemp = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S30>/DataTypeConversion2' */

  /* BusCreator: '<S30>/BusCreator' */
  AppSwcOpm_ARID_DEF.AC_8_status_BOD_o.AC_HV_PTC_On_Rq = VOPM_ACHVPTCOnRq_enum;
  AppSwcOpm_ARID_DEF.AC_8_status_BOD_o.AC_Auto_FrontFanSpd =
      VOPM_ACAutoFrntFanSpd_enum;

  /* DataTypeConversion: '<S30>/DataTypeConversion5' incorporates:
   *  Constant: '<S89>/Constant'
   *  Sum: '<S89>/Add'
   */
  if (VOPM_TMSMotInletCooltTemp_C - -40.0F < 256.0F)
  {
    if (VOPM_TMSMotInletCooltTemp_C - -40.0F >= 0.0F)
    {
      /* BusCreator: '<S30>/BusCreator' */
      AppSwcOpm_ARID_DEF.AC_8_status_BOD_o.TMS_MotInletCooltTemp = (uint8)(VOPM_TMSMotInletCooltTemp_C - -40.0F);
    }
    else
    {
      /* BusCreator: '<S30>/BusCreator' */
      AppSwcOpm_ARID_DEF.AC_8_status_BOD_o.TMS_MotInletCooltTemp = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S30>/BusCreator' */
    AppSwcOpm_ARID_DEF.AC_8_status_BOD_o.TMS_MotInletCooltTemp = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S30>/DataTypeConversion5' */

  /* BusCreator: '<S30>/BusCreator' incorporates:
   *  Constant: '<S90>/Constant1'
   *  DataTypeConversion: '<S30>/DataTypeConversion8'
   *  Product: '<S90>/Product1'
   *  Sum: '<S90>/Add'
   */
  AppSwcOpm_ARID_DEF.AC_8_status_BOD_o.TMS_BATThermalMod =
      VOPM_TMSBATThermMod_enum;
  AppSwcOpm_ARID_DEF.AC_8_status_BOD_o.TMS_CabThermalMod =
      VOPM_TMSCabThermMod_enum;
  AppSwcOpm_ARID_DEF.AC_8_status_BOD_o.TMS_PwrCoolFanSpdDuty = (uint8)((float32)
                                                                           VOPM_TMSPwrCoolFanSpdDuty_pct *
                                                                       0.1F);

  /* Outputs for Atomic SubSystem: '<S32>/Subsys_VOPM_COMPCompInPwrLim_W' */
  /* Switch: '<S101>/Switch4' incorporates:
   *  Constant: '<S101>/sat3'
   */
  if (KOPM_COMPCompInPwrLim_W_ovrdflg)
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Constant: '<S101>/sat4'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_COMPCompInPwrLim_W_ovrdval;
  }
  else
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Inport: '<Root>/TMS2VCU_AC_COMP_Outputs'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_COMP_Outputs_TMS2VCU_AC_COMP_Outputs())->COMP_CompInputPowerLimit;
  }

  /* End of Switch: '<S101>/Switch4' */

  /* MinMax: '<S101>/MinMax' incorporates:
   *  Constant: '<S101>/sat6'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm > KOPM_COMPCompInPwrLimHi_W)
  {
    /* MinMax: '<S39>/MinMax' */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_COMPCompInPwrLimHi_W;
  }

  /* End of MinMax: '<S101>/MinMax' */

  /* MinMax: '<S101>/MinMax1' incorporates:
   *  Constant: '<S101>/sat7'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm >= KOPM_COMPCompInPwrLimLo_W)
  {
    /* MinMax: '<S101>/MinMax1' */
    VOPM_COMPCompInPwrLim_W = VOPM_TMSAcPMPRealRPM_rpm;
  }
  else
  {
    /* MinMax: '<S101>/MinMax1' */
    VOPM_COMPCompInPwrLim_W = KOPM_COMPCompInPwrLimLo_W;
  }

  /* End of MinMax: '<S101>/MinMax1' */
  /* End of Outputs for SubSystem: '<S32>/Subsys_VOPM_COMPCompInPwrLim_W' */

  /* Outputs for Atomic SubSystem: '<S32>/Subsys_VOPM_COMPEcompSpdCtrl_rpm' */
  /* Switch: '<S105>/Switch4' incorporates:
   *  Constant: '<S105>/sat3'
   */
  if (KOPM_COMPEcompSpdCtrl_rpm_ovrdflg)
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Constant: '<S105>/sat4'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_COMPEcompSpdCtrl_rpm_ovrdval;
  }
  else
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Inport: '<Root>/TMS2VCU_AC_COMP_Outputs'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_COMP_Outputs_TMS2VCU_AC_COMP_Outputs())->COMP_EcompSpeedCtrl;
  }

  /* End of Switch: '<S105>/Switch4' */

  /* MinMax: '<S105>/MinMax' incorporates:
   *  Constant: '<S105>/sat6'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm > KOPM_COMPEcompSpdCtrlHi_rpm)
  {
    /* MinMax: '<S39>/MinMax' */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_COMPEcompSpdCtrlHi_rpm;
  }

  /* End of MinMax: '<S105>/MinMax' */

  /* MinMax: '<S105>/MinMax1' incorporates:
   *  Constant: '<S105>/sat7'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm >= KOPM_COMPEcompSpdCtrlLo_rpm)
  {
    /* MinMax: '<S105>/MinMax1' */
    VOPM_COMPEcompSpdCtrl_rpm = VOPM_TMSAcPMPRealRPM_rpm;
  }
  else
  {
    /* MinMax: '<S105>/MinMax1' */
    VOPM_COMPEcompSpdCtrl_rpm = KOPM_COMPEcompSpdCtrlLo_rpm;
  }

  /* End of MinMax: '<S105>/MinMax1' */
  /* End of Outputs for SubSystem: '<S32>/Subsys_VOPM_COMPEcompSpdCtrl_rpm' */

  /* Outputs for Atomic SubSystem: '<S32>/Subsys_VOPM_COMPEcompEnbl_enum' */
  /* Switch: '<S102>/Switch4' incorporates:
   *  Constant: '<S102>/sat3'
   */
  if (KOPM_COMPEcompEnbl_enum_ovrdflg)
  {
    /* MinMax: '<S80>/MinMax' incorporates:
     *  Constant: '<S102>/sat4'
     *  DataTypeConversion: '<S35>/DataTypeConversion2'
     */
    VOPM_HVCHEnbld_enum = KOPM_COMPEcompEnbl_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S80>/MinMax' incorporates:
     *  DataTypeConversion: '<S35>/DataTypeConversion2'
     *  Inport: '<Root>/TMS2VCU_AC_COMP_Outputs'
     */
    VOPM_HVCHEnbld_enum =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_COMP_Outputs_TMS2VCU_AC_COMP_Outputs())->COMP_EcompEnable;
  }

  /* End of Switch: '<S102>/Switch4' */

  /* MinMax: '<S102>/MinMax' incorporates:
   *  Constant: '<S102>/sat6'
   */
  if (VOPM_HVCHEnbld_enum > KOPM_COMPEcompEnblHi_enum)
  {
    /* MinMax: '<S80>/MinMax' */
    VOPM_HVCHEnbld_enum = KOPM_COMPEcompEnblHi_enum;
  }

  /* End of MinMax: '<S102>/MinMax' */

  /* MinMax: '<S102>/MinMax1' incorporates:
   *  Constant: '<S102>/sat7'
   */
  if (VOPM_HVCHEnbld_enum >= KOPM_COMPEcompEnblLo_enum)
  {
    /* MinMax: '<S102>/MinMax1' */
    VOPM_COMPEcompEnbl_enum = VOPM_HVCHEnbld_enum;
  }
  else
  {
    /* MinMax: '<S102>/MinMax1' */
    VOPM_COMPEcompEnbl_enum = KOPM_COMPEcompEnblLo_enum;
  }

  /* End of MinMax: '<S102>/MinMax1' */
  /* End of Outputs for SubSystem: '<S32>/Subsys_VOPM_COMPEcompEnbl_enum' */

  /* Outputs for Atomic SubSystem: '<S32>/Subsys_VOPM_COMPEcompHVSt_enum' */
  /* Switch: '<S104>/Switch4' incorporates:
   *  Constant: '<S104>/sat3'
   */
  if (KOPM_COMPEcompHVSt_enum_ovrdflg)
  {
    /* MinMax: '<S80>/MinMax' incorporates:
     *  Constant: '<S104>/sat4'
     *  DataTypeConversion: '<S35>/DataTypeConversion2'
     */
    VOPM_HVCHEnbld_enum = KOPM_COMPEcompHVSt_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S80>/MinMax' incorporates:
     *  DataTypeConversion: '<S35>/DataTypeConversion2'
     *  Inport: '<Root>/TMS2VCU_AC_COMP_Outputs'
     */
    VOPM_HVCHEnbld_enum =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_COMP_Outputs_TMS2VCU_AC_COMP_Outputs())->COMP_EcompHVSt;
  }

  /* End of Switch: '<S104>/Switch4' */

  /* MinMax: '<S104>/MinMax' incorporates:
   *  Constant: '<S104>/sat6'
   */
  if (VOPM_HVCHEnbld_enum > KOPM_COMPEcompHVStHi_enum)
  {
    /* MinMax: '<S80>/MinMax' */
    VOPM_HVCHEnbld_enum = KOPM_COMPEcompHVStHi_enum;
  }

  /* End of MinMax: '<S104>/MinMax' */

  /* MinMax: '<S104>/MinMax1' incorporates:
   *  Constant: '<S104>/sat7'
   */
  if (VOPM_HVCHEnbld_enum >= KOPM_COMPEcompHVStLo_enum)
  {
    /* MinMax: '<S104>/MinMax1' */
    VOPM_COMPEcompHVSt_enum = VOPM_HVCHEnbld_enum;
  }
  else
  {
    /* MinMax: '<S104>/MinMax1' */
    VOPM_COMPEcompHVSt_enum = KOPM_COMPEcompHVStLo_enum;
  }

  /* End of MinMax: '<S104>/MinMax1' */
  /* End of Outputs for SubSystem: '<S32>/Subsys_VOPM_COMPEcompHVSt_enum' */

  /* Outputs for Atomic SubSystem: '<S32>/Subsys_VOPM_COMPEcompErrClean_enum' */
  /* Switch: '<S103>/Switch4' incorporates:
   *  Constant: '<S103>/sat3'
   */
  if (KOPM_COMPEcompErrClean_enum_ovrdflg)
  {
    /* MinMax: '<S80>/MinMax' incorporates:
     *  Constant: '<S103>/sat4'
     *  DataTypeConversion: '<S35>/DataTypeConversion2'
     */
    VOPM_HVCHEnbld_enum = KOPM_COMPEcompErrClean_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S80>/MinMax' incorporates:
     *  DataTypeConversion: '<S35>/DataTypeConversion2'
     *  Inport: '<Root>/TMS2VCU_AC_COMP_Outputs'
     */
    VOPM_HVCHEnbld_enum =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_COMP_Outputs_TMS2VCU_AC_COMP_Outputs())->COMP_EcompErrorClean;
  }

  /* End of Switch: '<S103>/Switch4' */

  /* MinMax: '<S103>/MinMax' incorporates:
   *  Constant: '<S103>/sat6'
   */
  if (VOPM_HVCHEnbld_enum > KOPM_COMPEcompErrCleanHi_enum)
  {
    /* MinMax: '<S80>/MinMax' */
    VOPM_HVCHEnbld_enum = KOPM_COMPEcompErrCleanHi_enum;
  }

  /* End of MinMax: '<S103>/MinMax' */

  /* MinMax: '<S103>/MinMax1' incorporates:
   *  Constant: '<S103>/sat7'
   */
  if (VOPM_HVCHEnbld_enum >= KOPM_COMPEcompErrCleanLo_enum)
  {
    /* MinMax: '<S103>/MinMax1' */
    VOPM_COMPEcompErrClean_enum = VOPM_HVCHEnbld_enum;
  }
  else
  {
    /* MinMax: '<S103>/MinMax1' */
    VOPM_COMPEcompErrClean_enum = KOPM_COMPEcompErrCleanLo_enum;
  }

  /* End of MinMax: '<S103>/MinMax1' */
  /* End of Outputs for SubSystem: '<S32>/Subsys_VOPM_COMPEcompErrClean_enum' */

  /* Outputs for Atomic SubSystem: '<S32>/Subsys_VOPM_TMSACPExhtTmp_C' */
  /* Switch: '<S106>/Switch4' incorporates:
   *  Constant: '<S106>/sat3'
   */
  if (KOPM_TMSACPExhtTmp_C_ovrdflg)
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Constant: '<S106>/sat4'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_TMSACPExhtTmp_C_ovrdval;
  }
  else
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  DataTypeConversion: '<S106>/Data Type Conversion1'
     *  Inport: '<Root>/TMS2VCU_AC_COMP_Outputs'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm = (float32)(Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_COMP_Outputs_TMS2VCU_AC_COMP_Outputs())->TMS_ACPExhaustTmp;
  }

  /* End of Switch: '<S106>/Switch4' */

  /* MinMax: '<S106>/MinMax' incorporates:
   *  Constant: '<S106>/sat6'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm > KOPM_TMSACPExhtTmpHi_C)
  {
    /* MinMax: '<S39>/MinMax' */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_TMSACPExhtTmpHi_C;
  }

  /* End of MinMax: '<S106>/MinMax' */

  /* MinMax: '<S106>/MinMax1' incorporates:
   *  Constant: '<S106>/sat7'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm >= KOPM_TMSACPExhtTmpLo_C)
  {
    /* MinMax: '<S106>/MinMax1' */
    VOPM_TMSACPExhtTmp_C = VOPM_TMSAcPMPRealRPM_rpm;
  }
  else
  {
    /* MinMax: '<S106>/MinMax1' */
    VOPM_TMSACPExhtTmp_C = KOPM_TMSACPExhtTmpLo_C;
  }

  /* End of MinMax: '<S106>/MinMax1' */
  /* End of Outputs for SubSystem: '<S32>/Subsys_VOPM_TMSACPExhtTmp_C' */

  /* Outputs for Atomic SubSystem: '<S32>/Subsys_VOPM_TMSACPInletPres_kPa' */
  /* Switch: '<S107>/Switch4' incorporates:
   *  Constant: '<S107>/sat3'
   */
  if (KOPM_TMSACPInletPres_kPa_ovrdflg)
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Constant: '<S107>/sat4'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_TMSACPInletPres_kPa_ovrdval;
  }
  else
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Inport: '<Root>/TMS2VCU_AC_COMP_Outputs'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_COMP_Outputs_TMS2VCU_AC_COMP_Outputs())->TMS_ACPInletPressure;
  }

  /* End of Switch: '<S107>/Switch4' */

  /* MinMax: '<S107>/MinMax' incorporates:
   *  Constant: '<S107>/sat6'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm > KOPM_TMSACPInletPresHi_kPa)
  {
    /* MinMax: '<S39>/MinMax' */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_TMSACPInletPresHi_kPa;
  }

  /* End of MinMax: '<S107>/MinMax' */

  /* MinMax: '<S107>/MinMax1' incorporates:
   *  Constant: '<S107>/sat7'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm >= KOPM_TMSACPInletPresLo_kPa)
  {
    /* MinMax: '<S107>/MinMax1' */
    VOPM_TMSACPInletPres_kPa = VOPM_TMSAcPMPRealRPM_rpm;
  }
  else
  {
    /* MinMax: '<S107>/MinMax1' */
    VOPM_TMSACPInletPres_kPa = KOPM_TMSACPInletPresLo_kPa;
  }

  /* End of MinMax: '<S107>/MinMax1' */
  /* End of Outputs for SubSystem: '<S32>/Subsys_VOPM_TMSACPInletPres_kPa' */

  /* DataTypeConversion: '<S32>/DataTypeConversion' incorporates:
   *  Constant: '<S110>/Constant1'
   *  Product: '<S110>/Product1'
   *  Sum: '<S110>/Add'
   */
  tmp = VOPM_COMPEcompSpdCtrl_rpm * 0.02F;
  if (tmp < 256.0F)
  {
    if (tmp >= 0.0F)
    {
      /* BusCreator: '<S32>/BusCreator' */
      AppSwcOpm_ARID_DEF.AC_COMP_BOD_o.COMP_EcompSpeedCtrl = (uint8)tmp;
    }
    else
    {
      /* BusCreator: '<S32>/BusCreator' */
      AppSwcOpm_ARID_DEF.AC_COMP_BOD_o.COMP_EcompSpeedCtrl = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S32>/BusCreator' */
    AppSwcOpm_ARID_DEF.AC_COMP_BOD_o.COMP_EcompSpeedCtrl = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S32>/DataTypeConversion' */

  /* BusCreator: '<S32>/BusCreator' */
  AppSwcOpm_ARID_DEF.AC_COMP_BOD_o.COMP_EcompEnable = VOPM_COMPEcompEnbl_enum;
  AppSwcOpm_ARID_DEF.AC_COMP_BOD_o.COMP_EcompHVSt = VOPM_COMPEcompHVSt_enum;
  AppSwcOpm_ARID_DEF.AC_COMP_BOD_o.COMP_EcompErrorClean =
      VOPM_COMPEcompErrClean_enum;

  /* DataTypeConversion: '<S32>/DataTypeConversion4' incorporates:
   *  Constant: '<S108>/Constant1'
   *  Product: '<S108>/Product1'
   *  Sum: '<S108>/Add'
   */
  tmp = VOPM_COMPCompInPwrLim_W * 0.01F;
  if (tmp < 256.0F)
  {
    if (tmp >= 0.0F)
    {
      /* BusCreator: '<S32>/BusCreator' */
      AppSwcOpm_ARID_DEF.AC_COMP_BOD_o.COMP_CompInputPowerLimit = (uint8)tmp;
    }
    else
    {
      /* BusCreator: '<S32>/BusCreator' */
      AppSwcOpm_ARID_DEF.AC_COMP_BOD_o.COMP_CompInputPowerLimit = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S32>/BusCreator' */
    AppSwcOpm_ARID_DEF.AC_COMP_BOD_o.COMP_CompInputPowerLimit = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S32>/DataTypeConversion4' */

  /* DataTypeConversion: '<S32>/DataTypeConversion5' incorporates:
   *  Constant: '<S109>/Constant'
   *  Sum: '<S109>/Add'
   */
  if (VOPM_TMSACPExhtTmp_C - -40.0F < 256.0F)
  {
    if (VOPM_TMSACPExhtTmp_C - -40.0F >= 0.0F)
    {
      /* BusCreator: '<S32>/BusCreator' */
      AppSwcOpm_ARID_DEF.AC_COMP_BOD_o.TMS_ACPExhaustTmp = (uint8)(VOPM_TMSACPExhtTmp_C - -40.0F);
    }
    else
    {
      /* BusCreator: '<S32>/BusCreator' */
      AppSwcOpm_ARID_DEF.AC_COMP_BOD_o.TMS_ACPExhaustTmp = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S32>/BusCreator' */
    AppSwcOpm_ARID_DEF.AC_COMP_BOD_o.TMS_ACPExhaustTmp = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S32>/DataTypeConversion5' */

  /* DataTypeConversion: '<S32>/DataTypeConversion6' incorporates:
   *  Constant: '<S111>/Constant1'
   *  Product: '<S111>/Product1'
   *  Sum: '<S111>/Add'
   */
  tmp = VOPM_TMSACPInletPres_kPa * 0.1F;
  if (tmp < 256.0F)
  {
    if (tmp >= 0.0F)
    {
      /* BusCreator: '<S32>/BusCreator' */
      AppSwcOpm_ARID_DEF.AC_COMP_BOD_o.TMS_ACPInletPressure = (uint8)tmp;
    }
    else
    {
      /* BusCreator: '<S32>/BusCreator' */
      AppSwcOpm_ARID_DEF.AC_COMP_BOD_o.TMS_ACPInletPressure = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S32>/BusCreator' */
    AppSwcOpm_ARID_DEF.AC_COMP_BOD_o.TMS_ACPInletPressure = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S32>/DataTypeConversion6' */

  /* Outputs for Atomic SubSystem: '<S34>/Subsys_VOPM_HVCHReqPwr_kW' */
  /* Switch: '<S114>/Switch4' incorporates:
   *  Constant: '<S114>/sat3'
   */
  if (KOPM_HVCHReqPwr_kW_ovrdflg)
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Constant: '<S114>/sat4'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_HVCHReqPwr_kW_ovrdval;
  }
  else
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Inport: '<Root>/TMS2VCU_HVCH_Command_Outputs'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_HVCH_Command_Outputs_TMS2VCU_HVCH_Command_Outputs())->HVCH_RequestPower;
  }

  /* End of Switch: '<S114>/Switch4' */

  /* MinMax: '<S114>/MinMax' incorporates:
   *  Constant: '<S114>/sat6'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm > KOPM_HVCHReqPwrHi_kW)
  {
    /* MinMax: '<S39>/MinMax' */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_HVCHReqPwrHi_kW;
  }

  /* End of MinMax: '<S114>/MinMax' */

  /* MinMax: '<S114>/MinMax1' incorporates:
   *  Constant: '<S114>/sat7'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm >= KOPM_HVCHReqPwrLo_kW)
  {
    /* MinMax: '<S114>/MinMax1' */
    VOPM_HVCHReqPwr_kW = VOPM_TMSAcPMPRealRPM_rpm;
  }
  else
  {
    /* MinMax: '<S114>/MinMax1' */
    VOPM_HVCHReqPwr_kW = KOPM_HVCHReqPwrLo_kW;
  }

  /* End of MinMax: '<S114>/MinMax1' */
  /* End of Outputs for SubSystem: '<S34>/Subsys_VOPM_HVCHReqPwr_kW' */

  /* Outputs for Atomic SubSystem: '<S34>/Subsys_VOPM_HVCHReqTemp_C' */
  /* Switch: '<S115>/Switch4' incorporates:
   *  Constant: '<S115>/sat3'
   */
  if (KOPM_HVCHReqTemp_C_ovrdflg)
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Constant: '<S115>/sat4'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_HVCHReqTemp_C_ovrdval;
  }
  else
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  DataTypeConversion: '<S115>/Data Type Conversion1'
     *  Inport: '<Root>/TMS2VCU_HVCH_Command_Outputs'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm = (float32)(Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_HVCH_Command_Outputs_TMS2VCU_HVCH_Command_Outputs())->HVCH_RequestTemp;
  }

  /* End of Switch: '<S115>/Switch4' */

  /* MinMax: '<S115>/MinMax' incorporates:
   *  Constant: '<S115>/sat6'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm > KOPM_HVCHReqTempHi_C)
  {
    /* MinMax: '<S39>/MinMax' */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_HVCHReqTempHi_C;
  }

  /* End of MinMax: '<S115>/MinMax' */

  /* MinMax: '<S115>/MinMax1' incorporates:
   *  Constant: '<S115>/sat7'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm >= KOPM_HVCHReqTempLo_C)
  {
    /* MinMax: '<S115>/MinMax1' */
    VOPM_HVCHReqTemp_C = VOPM_TMSAcPMPRealRPM_rpm;
  }
  else
  {
    /* MinMax: '<S115>/MinMax1' */
    VOPM_HVCHReqTemp_C = KOPM_HVCHReqTempLo_C;
  }

  /* End of MinMax: '<S115>/MinMax1' */
  /* End of Outputs for SubSystem: '<S34>/Subsys_VOPM_HVCHReqTemp_C' */

  /* Outputs for Atomic SubSystem: '<S34>/Subsys_VOPM_HVCHEnbld_enum' */
  /* Switch: '<S113>/Switch4' incorporates:
   *  Constant: '<S113>/sat3'
   */
  if (KOPM_HVCHEnbld_enum_ovrdflg)
  {
    /* MinMax: '<S80>/MinMax' incorporates:
     *  Constant: '<S113>/sat4'
     *  DataTypeConversion: '<S35>/DataTypeConversion2'
     */
    VOPM_HVCHEnbld_enum = KOPM_HVCHEnbld_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S80>/MinMax' incorporates:
     *  DataTypeConversion: '<S35>/DataTypeConversion2'
     *  Inport: '<Root>/TMS2VCU_HVCH_Command_Outputs'
     */
    VOPM_HVCHEnbld_enum =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_HVCH_Command_Outputs_TMS2VCU_HVCH_Command_Outputs())->HVCH_Enabled;
  }

  /* End of Switch: '<S113>/Switch4' */

  /* MinMax: '<S113>/MinMax' incorporates:
   *  Constant: '<S113>/sat6'
   */
  if (VOPM_HVCHEnbld_enum > KOPM_HVCHEnbldHi_enum)
  {
    /* MinMax: '<S80>/MinMax' */
    VOPM_HVCHEnbld_enum = KOPM_HVCHEnbldHi_enum;
  }

  /* End of MinMax: '<S113>/MinMax' */

  /* MinMax: '<S113>/MinMax1' incorporates:
   *  Constant: '<S113>/sat7'
   */
  if (VOPM_HVCHEnbld_enum < KOPM_HVCHEnbldLo_enum)
  {
    /* MinMax: '<S80>/MinMax' incorporates:
     *  MinMax: '<S113>/MinMax1'
     */
    VOPM_HVCHEnbld_enum = KOPM_HVCHEnbldLo_enum;
  }

  /* End of MinMax: '<S113>/MinMax1' */
  /* End of Outputs for SubSystem: '<S34>/Subsys_VOPM_HVCHEnbld_enum' */

  /* DataTypeConversion: '<S34>/DataTypeConversion' incorporates:
   *  Constant: '<S117>/Constant'
   *  Sum: '<S117>/Add'
   */
  if (VOPM_HVCHReqTemp_C - -40.0F < 256.0F)
  {
    if (VOPM_HVCHReqTemp_C - -40.0F >= 0.0F)
    {
      /* BusCreator: '<S34>/BusCreator' */
      AppSwcOpm_ARID_DEF.HVCH_Command_BOD_k.HVCH_RequestTemp = (uint8)(VOPM_HVCHReqTemp_C - -40.0F);
    }
    else
    {
      /* BusCreator: '<S34>/BusCreator' */
      AppSwcOpm_ARID_DEF.HVCH_Command_BOD_k.HVCH_RequestTemp = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S34>/BusCreator' */
    AppSwcOpm_ARID_DEF.HVCH_Command_BOD_k.HVCH_RequestTemp = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S34>/DataTypeConversion' */

  /* DataTypeConversion: '<S34>/DataTypeConversion1' incorporates:
   *  Constant: '<S116>/Constant1'
   *  Product: '<S116>/Product1'
   *  Sum: '<S116>/Add'
   */
  tmp = VOPM_HVCHReqPwr_kW * 10.0F;
  if (tmp < 256.0F)
  {
    if (tmp >= 0.0F)
    {
      /* BusCreator: '<S34>/BusCreator' */
      AppSwcOpm_ARID_DEF.HVCH_Command_BOD_k.HVCH_RequestPower = (uint8)tmp;
    }
    else
    {
      /* BusCreator: '<S34>/BusCreator' */
      AppSwcOpm_ARID_DEF.HVCH_Command_BOD_k.HVCH_RequestPower = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S34>/BusCreator' */
    AppSwcOpm_ARID_DEF.HVCH_Command_BOD_k.HVCH_RequestPower = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S34>/DataTypeConversion1' */

  /* BusCreator: '<S34>/BusCreator' */
  AppSwcOpm_ARID_DEF.HVCH_Command_BOD_k.HVCH_Enabled = VOPM_HVCHEnbld_enum;

  /* Outputs for Atomic SubSystem: '<S35>/Subsys_VOPM_TMSBatPMPSpdSet_rpm' */
  /* Switch: '<S121>/Switch4' incorporates:
   *  Constant: '<S121>/sat3'
   */
  if (KOPM_TMSBatPMPSpdSet_rpm_ovrdflg)
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Constant: '<S121>/sat4'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_TMSBatPMPSpdSet_rpm_ovrdval;
  }
  else
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Inport: '<Root>/TMS2VCU_TMS_LINTestData1_Outputs'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData1_Outputs_TMS2VCU_TMS_LINTestData1_Outputs())->TMS_BatPMPSpdSet;
  }

  /* End of Switch: '<S121>/Switch4' */

  /* MinMax: '<S121>/MinMax' incorporates:
   *  Constant: '<S121>/sat6'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm > KOPM_TMSBatPMPSpdSetHi_rpm)
  {
    /* MinMax: '<S39>/MinMax' */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_TMSBatPMPSpdSetHi_rpm;
  }

  /* End of MinMax: '<S121>/MinMax' */

  /* MinMax: '<S121>/MinMax1' incorporates:
   *  Constant: '<S121>/sat7'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm >= KOPM_TMSBatPMPSpdSetLo_rpm)
  {
    /* MinMax: '<S121>/MinMax1' */
    VOPM_TMSBatPMPSpdSet_rpm = VOPM_TMSAcPMPRealRPM_rpm;
  }
  else
  {
    /* MinMax: '<S121>/MinMax1' */
    VOPM_TMSBatPMPSpdSet_rpm = KOPM_TMSBatPMPSpdSetLo_rpm;
  }

  /* End of MinMax: '<S121>/MinMax1' */
  /* End of Outputs for SubSystem: '<S35>/Subsys_VOPM_TMSBatPMPSpdSet_rpm' */

  /* Outputs for Atomic SubSystem: '<S35>/Subsys_VOPM_TMSAcPMPSpdSet_rpm' */
  /* Switch: '<S119>/Switch4' incorporates:
   *  Constant: '<S119>/sat3'
   */
  if (KOPM_TMSAcPMPSpdSet_rpm_ovrdflg)
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Constant: '<S119>/sat4'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_TMSAcPMPSpdSet_rpm_ovrdval;
  }
  else
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Inport: '<Root>/TMS2VCU_TMS_LINTestData1_Outputs'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData1_Outputs_TMS2VCU_TMS_LINTestData1_Outputs())->TMS_AcPMPSpdSet;
  }

  /* End of Switch: '<S119>/Switch4' */

  /* MinMax: '<S119>/MinMax' incorporates:
   *  Constant: '<S119>/sat6'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm > KOPM_TMSAcPMPSpdSetHi_rpm)
  {
    /* MinMax: '<S39>/MinMax' */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_TMSAcPMPSpdSetHi_rpm;
  }

  /* End of MinMax: '<S119>/MinMax' */

  /* MinMax: '<S119>/MinMax1' incorporates:
   *  Constant: '<S119>/sat7'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm >= KOPM_TMSAcPMPSpdSetLo_rpm)
  {
    /* MinMax: '<S119>/MinMax1' */
    VOPM_TMSAcPMPSpdSet_rpm = VOPM_TMSAcPMPRealRPM_rpm;
  }
  else
  {
    /* MinMax: '<S119>/MinMax1' */
    VOPM_TMSAcPMPSpdSet_rpm = KOPM_TMSAcPMPSpdSetLo_rpm;
  }

  /* End of MinMax: '<S119>/MinMax1' */
  /* End of Outputs for SubSystem: '<S35>/Subsys_VOPM_TMSAcPMPSpdSet_rpm' */

  /* Outputs for Atomic SubSystem: '<S35>/Subsys_VOPM_TMSMotPMPSpdSet_rpm' */
  /* Switch: '<S124>/Switch4' incorporates:
   *  Constant: '<S124>/sat3'
   */
  if (KOPM_TMSMotPMPSpdSet_rpm_ovrdflg)
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Constant: '<S124>/sat4'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_TMSMotPMPSpdSet_rpm_ovrdval;
  }
  else
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Inport: '<Root>/TMS2VCU_TMS_LINTestData1_Outputs'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData1_Outputs_TMS2VCU_TMS_LINTestData1_Outputs())->TMS_MotPMPSpdSet;
  }

  /* End of Switch: '<S124>/Switch4' */

  /* MinMax: '<S124>/MinMax' incorporates:
   *  Constant: '<S124>/sat6'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm > KOPM_TMSMotPMPSpdSetHi_rpm)
  {
    /* MinMax: '<S39>/MinMax' */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_TMSMotPMPSpdSetHi_rpm;
  }

  /* End of MinMax: '<S124>/MinMax' */

  /* MinMax: '<S124>/MinMax1' incorporates:
   *  Constant: '<S124>/sat7'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm >= KOPM_TMSMotPMPSpdSetLo_rpm)
  {
    /* MinMax: '<S124>/MinMax1' */
    VOPM_TMSMotPMPSpdSet_rpm = VOPM_TMSAcPMPRealRPM_rpm;
  }
  else
  {
    /* MinMax: '<S124>/MinMax1' */
    VOPM_TMSMotPMPSpdSet_rpm = KOPM_TMSMotPMPSpdSetLo_rpm;
  }

  /* End of MinMax: '<S124>/MinMax1' */
  /* End of Outputs for SubSystem: '<S35>/Subsys_VOPM_TMSMotPMPSpdSet_rpm' */

  /* Outputs for Atomic SubSystem: '<S35>/Subsys_VOPM_TMSMotPMPRealRPM_rpm' */
  /* Switch: '<S123>/Switch4' incorporates:
   *  Constant: '<S123>/sat3'
   */
  if (KOPM_TMSMotPMPRealRPM_rpm_ovrdflg)
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Constant: '<S123>/sat4'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_TMSMotPMPRealRPM_rpm_ovrdval;
  }
  else
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Inport: '<Root>/TMS2VCU_TMS_LINTestData1_Outputs'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData1_Outputs_TMS2VCU_TMS_LINTestData1_Outputs())->TMS_MotPMPRealRPM;
  }

  /* End of Switch: '<S123>/Switch4' */

  /* MinMax: '<S123>/MinMax' incorporates:
   *  Constant: '<S123>/sat6'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm > KOPM_TMSMotPMPRealRPMHi_rpm)
  {
    /* MinMax: '<S39>/MinMax' */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_TMSMotPMPRealRPMHi_rpm;
  }

  /* End of MinMax: '<S123>/MinMax' */

  /* MinMax: '<S123>/MinMax1' incorporates:
   *  Constant: '<S123>/sat7'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm >= KOPM_TMSMotPMPRealRPMLo_rpm)
  {
    /* MinMax: '<S123>/MinMax1' */
    VOPM_TMSMotPMPRealRPM_rpm = VOPM_TMSAcPMPRealRPM_rpm;
  }
  else
  {
    /* MinMax: '<S123>/MinMax1' */
    VOPM_TMSMotPMPRealRPM_rpm = KOPM_TMSMotPMPRealRPMLo_rpm;
  }

  /* End of MinMax: '<S123>/MinMax1' */
  /* End of Outputs for SubSystem: '<S35>/Subsys_VOPM_TMSMotPMPRealRPM_rpm' */

  /* Outputs for Atomic SubSystem: '<S35>/Subsys_VOPM_TMSBatPMPRealRPM_rpm' */
  /* Switch: '<S120>/Switch4' incorporates:
   *  Constant: '<S120>/sat3'
   */
  if (KOPM_TMSBatPMPRealRPM_rpm_ovrdflg)
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Constant: '<S120>/sat4'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_TMSBatPMPRealRPM_rpm_ovrdval;
  }
  else
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Inport: '<Root>/TMS2VCU_TMS_LINTestData1_Outputs'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData1_Outputs_TMS2VCU_TMS_LINTestData1_Outputs())->TMS_BatPMPRealRPM;
  }

  /* End of Switch: '<S120>/Switch4' */

  /* MinMax: '<S120>/MinMax' incorporates:
   *  Constant: '<S120>/sat6'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm > KOPM_TMSBatPMPRealRPMHi_rpm)
  {
    /* MinMax: '<S39>/MinMax' */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_TMSBatPMPRealRPMHi_rpm;
  }

  /* End of MinMax: '<S120>/MinMax' */

  /* MinMax: '<S120>/MinMax1' incorporates:
   *  Constant: '<S120>/sat7'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm >= KOPM_TMSBatPMPRealRPMLo_rpm)
  {
    /* MinMax: '<S120>/MinMax1' */
    VOPM_TMSBatPMPRealRPM_rpm = VOPM_TMSAcPMPRealRPM_rpm;
  }
  else
  {
    /* MinMax: '<S120>/MinMax1' */
    VOPM_TMSBatPMPRealRPM_rpm = KOPM_TMSBatPMPRealRPMLo_rpm;
  }

  /* End of MinMax: '<S120>/MinMax1' */
  /* End of Outputs for SubSystem: '<S35>/Subsys_VOPM_TMSBatPMPRealRPM_rpm' */

  /* Outputs for Atomic SubSystem: '<S35>/Subsys_VOPM_TMSAcPMPRealRPM_rpm' */
  /* Switch: '<S118>/Switch4' incorporates:
   *  Constant: '<S118>/sat3'
   */
  if (KOPM_TMSAcPMPRealRPM_rpm_ovrdflg)
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Constant: '<S118>/sat4'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_TMSAcPMPRealRPM_rpm_ovrdval;
  }
  else
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  Inport: '<Root>/TMS2VCU_TMS_LINTestData1_Outputs'
     *  Product: '<S130>/Product1'
     */
    VOPM_TMSAcPMPRealRPM_rpm =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData1_Outputs_TMS2VCU_TMS_LINTestData1_Outputs())->TMS_AcPMPRealRPM;
  }

  /* End of Switch: '<S118>/Switch4' */

  /* MinMax: '<S118>/MinMax' incorporates:
   *  Constant: '<S118>/sat6'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm > KOPM_TMSAcPMPRealRPMHi_rpm)
  {
    /* MinMax: '<S39>/MinMax' */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_TMSAcPMPRealRPMHi_rpm;
  }

  /* End of MinMax: '<S118>/MinMax' */

  /* MinMax: '<S118>/MinMax1' incorporates:
   *  Constant: '<S118>/sat7'
   */
  if (VOPM_TMSAcPMPRealRPM_rpm < KOPM_TMSAcPMPRealRPMLo_rpm)
  {
    /* MinMax: '<S39>/MinMax' incorporates:
     *  MinMax: '<S118>/MinMax1'
     */
    VOPM_TMSAcPMPRealRPM_rpm = KOPM_TMSAcPMPRealRPMLo_rpm;
  }

  /* End of MinMax: '<S118>/MinMax1' */
  /* End of Outputs for SubSystem: '<S35>/Subsys_VOPM_TMSAcPMPRealRPM_rpm' */

  /* Outputs for Atomic SubSystem: '<S35>/Subsys_VOPM_TMSHPEXVPstnCmd_cnt' */
  /* Switch: '<S122>/Switch4' incorporates:
   *  Constant: '<S122>/sat3'
   */
  if (KOPM_TMSHPEXVPstnCmd_cnt_ovrdflg)
  {
    /* MinMax: '<S122>/MinMax' incorporates:
     *  Constant: '<S122>/sat4'
     *  MinMax: '<S139>/MinMax'
     */
    VOPM_TMSC3WVPosRec_enum = KOPM_TMSHPEXVPstnCmd_cnt_ovrdval;
  }
  else
  {
    /* MinMax: '<S122>/MinMax' incorporates:
     *  Inport: '<Root>/TMS2VCU_TMS_LINTestData1_Outputs'
     *  MinMax: '<S139>/MinMax'
     */
    VOPM_TMSC3WVPosRec_enum =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData1_Outputs_TMS2VCU_TMS_LINTestData1_Outputs())->TMS_HPEXVPositionCmd;
  }

  /* End of Switch: '<S122>/Switch4' */

  /* MinMax: '<S122>/MinMax' incorporates:
   *  Constant: '<S122>/sat6'
   */
  if (VOPM_TMSC3WVPosRec_enum > KOPM_TMSHPEXVPstnCmdHi_cnt)
  {
    VOPM_TMSC3WVPosRec_enum = KOPM_TMSHPEXVPstnCmdHi_cnt;
  }

  /* MinMax: '<S122>/MinMax1' incorporates:
   *  Constant: '<S122>/sat7'
   */
  if (VOPM_TMSC3WVPosRec_enum >= KOPM_TMSHPEXVPstnCmdLo_cnt)
  {
    /* MinMax: '<S122>/MinMax1' */
    VOPM_TMSHPEXVPstnCmd_cnt = VOPM_TMSC3WVPosRec_enum;
  }
  else
  {
    /* MinMax: '<S122>/MinMax1' */
    VOPM_TMSHPEXVPstnCmd_cnt = KOPM_TMSHPEXVPstnCmdLo_cnt;
  }

  /* End of MinMax: '<S122>/MinMax1' */
  /* End of Outputs for SubSystem: '<S35>/Subsys_VOPM_TMSHPEXVPstnCmd_cnt' */

  /* DataTypeConversion: '<S35>/DataTypeConversion' incorporates:
   *  Constant: '<S128>/Constant1'
   *  Product: '<S128>/Product1'
   *  Sum: '<S128>/Add'
   */
  tmp = VOPM_TMSAcPMPSpdSet_rpm * 2.5F;
  if (tmp < 256.0F)
  {
    if (tmp >= 0.0F)
    {
      /* BusCreator: '<S35>/BusCreator' */
      AppSwcOpm_ARID_DEF.TMS_LINTestData1_BOD_f_m.TMS_AcPMPSpdSet = (uint8)tmp;
    }
    else
    {
      /* BusCreator: '<S35>/BusCreator' */
      AppSwcOpm_ARID_DEF.TMS_LINTestData1_BOD_f_m.TMS_AcPMPSpdSet = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S35>/BusCreator' */
    AppSwcOpm_ARID_DEF.TMS_LINTestData1_BOD_f_m.TMS_AcPMPSpdSet = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S35>/DataTypeConversion' */

  /* DataTypeConversion: '<S35>/DataTypeConversion1' incorporates:
   *  Constant: '<S125>/Constant1'
   *  Product: '<S125>/Product1'
   *  Sum: '<S125>/Add'
   */
  tmp = VOPM_TMSBatPMPSpdSet_rpm * 2.5F;
  if (tmp < 256.0F)
  {
    if (tmp >= 0.0F)
    {
      /* BusCreator: '<S35>/BusCreator' */
      AppSwcOpm_ARID_DEF.TMS_LINTestData1_BOD_f_m.TMS_BatPMPSpdSet = (uint8)tmp;
    }
    else
    {
      /* BusCreator: '<S35>/BusCreator' */
      AppSwcOpm_ARID_DEF.TMS_LINTestData1_BOD_f_m.TMS_BatPMPSpdSet = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S35>/BusCreator' */
    AppSwcOpm_ARID_DEF.TMS_LINTestData1_BOD_f_m.TMS_BatPMPSpdSet = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S35>/DataTypeConversion1' */

  /* DataTypeConversion: '<S35>/DataTypeConversion2' incorporates:
   *  Constant: '<S126>/Constant1'
   *  Product: '<S126>/Product1'
   *  Sum: '<S126>/Add'
   */
  tmp = VOPM_TMSMotPMPSpdSet_rpm * 2.5F;
  if (tmp < 256.0F)
  {
    if (tmp >= 0.0F)
    {
      /* BusCreator: '<S35>/BusCreator' */
      AppSwcOpm_ARID_DEF.TMS_LINTestData1_BOD_f_m.TMS_MotPMPSpdSet = (uint8)tmp;
    }
    else
    {
      /* BusCreator: '<S35>/BusCreator' */
      AppSwcOpm_ARID_DEF.TMS_LINTestData1_BOD_f_m.TMS_MotPMPSpdSet = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S35>/BusCreator' */
    AppSwcOpm_ARID_DEF.TMS_LINTestData1_BOD_f_m.TMS_MotPMPSpdSet = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S35>/DataTypeConversion2' */

  /* DataTypeConversion: '<S35>/DataTypeConversion3' incorporates:
   *  Constant: '<S127>/Constant1'
   *  Product: '<S127>/Product1'
   *  Sum: '<S127>/Add'
   */
  tmp = VOPM_TMSMotPMPRealRPM_rpm * 2.5F;
  if (tmp < 256.0F)
  {
    if (tmp >= 0.0F)
    {
      /* BusCreator: '<S35>/BusCreator' */
      AppSwcOpm_ARID_DEF.TMS_LINTestData1_BOD_f_m.TMS_MotPMPRealRPM = (uint8)tmp;
    }
    else
    {
      /* BusCreator: '<S35>/BusCreator' */
      AppSwcOpm_ARID_DEF.TMS_LINTestData1_BOD_f_m.TMS_MotPMPRealRPM = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S35>/BusCreator' */
    AppSwcOpm_ARID_DEF.TMS_LINTestData1_BOD_f_m.TMS_MotPMPRealRPM = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S35>/DataTypeConversion3' */

  /* DataTypeConversion: '<S35>/DataTypeConversion4' incorporates:
   *  Constant: '<S129>/Constant1'
   *  Product: '<S129>/Product1'
   *  Sum: '<S129>/Add'
   */
  tmp = VOPM_TMSBatPMPRealRPM_rpm * 2.5F;
  if (tmp < 256.0F)
  {
    if (tmp >= 0.0F)
    {
      /* BusCreator: '<S35>/BusCreator' */
      AppSwcOpm_ARID_DEF.TMS_LINTestData1_BOD_f_m.TMS_BatPMPRealRPM = (uint8)tmp;
    }
    else
    {
      /* BusCreator: '<S35>/BusCreator' */
      AppSwcOpm_ARID_DEF.TMS_LINTestData1_BOD_f_m.TMS_BatPMPRealRPM = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S35>/BusCreator' */
    AppSwcOpm_ARID_DEF.TMS_LINTestData1_BOD_f_m.TMS_BatPMPRealRPM = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S35>/DataTypeConversion4' */

  /* DataTypeConversion: '<S35>/DataTypeConversion5' incorporates:
   *  Constant: '<S130>/Constant1'
   *  Product: '<S130>/Product1'
   *  Sum: '<S130>/Add'
   */
  tmp = VOPM_TMSAcPMPRealRPM_rpm * 2.5F;
  if (tmp < 256.0F)
  {
    if (tmp >= 0.0F)
    {
      /* BusCreator: '<S35>/BusCreator' */
      AppSwcOpm_ARID_DEF.TMS_LINTestData1_BOD_f_m.TMS_AcPMPRealRPM = (uint8)tmp;
    }
    else
    {
      /* BusCreator: '<S35>/BusCreator' */
      AppSwcOpm_ARID_DEF.TMS_LINTestData1_BOD_f_m.TMS_AcPMPRealRPM = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S35>/BusCreator' */
    AppSwcOpm_ARID_DEF.TMS_LINTestData1_BOD_f_m.TMS_AcPMPRealRPM = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S35>/DataTypeConversion5' */

  /* BusCreator: '<S35>/BusCreator' */
  AppSwcOpm_ARID_DEF.TMS_LINTestData1_BOD_f_m.TMS_HPEXVPositionCmd =
      VOPM_TMSHPEXVPstnCmd_cnt;

  /* Outputs for Atomic SubSystem: '<S31>/Subsys_VOPM_ACLeftTempVal_enum' */
  /* Switch: '<S97>/Switch4' incorporates:
   *  Constant: '<S97>/sat3'
   */
  if (KOPM_ACLeftTempVal_enum_ovrdflg)
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Constant: '<S97>/sat4'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum = KOPM_ACLeftTempVal_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Inport: '<Root>/TMS2VCU_AC_ACStatuts_Outputs'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_ACStatuts_Outputs_TMS2VCU_AC_ACStatuts_Outputs())->AC_leftTempValue;
  }

  /* End of Switch: '<S97>/Switch4' */

  /* MinMax: '<S97>/MinMax' incorporates:
   *  Constant: '<S97>/sat6'
   */
  if (VOPM_TMSC3WVMode_enum > KOPM_ACLeftTempValHi_enum)
  {
    /* MinMax: '<S153>/MinMax' */
    VOPM_TMSC3WVMode_enum = KOPM_ACLeftTempValHi_enum;
  }

  /* End of MinMax: '<S97>/MinMax' */

  /* MinMax: '<S97>/MinMax1' incorporates:
   *  Constant: '<S97>/sat7'
   */
  if (VOPM_TMSC3WVMode_enum >= KOPM_ACLeftTempValLo_enum)
  {
    /* MinMax: '<S97>/MinMax1' */
    VOPM_ACLeftTempVal_enum = VOPM_TMSC3WVMode_enum;
  }
  else
  {
    /* MinMax: '<S97>/MinMax1' */
    VOPM_ACLeftTempVal_enum = KOPM_ACLeftTempValLo_enum;
  }

  /* End of MinMax: '<S97>/MinMax1' */
  /* End of Outputs for SubSystem: '<S31>/Subsys_VOPM_ACLeftTempVal_enum' */

  /* Outputs for Atomic SubSystem: '<S31>/Subsys_VOPM_ACManlDefrstFb_flg' */
  /* Switch: '<S98>/Switch4' incorporates:
   *  Constant: '<S98>/sat3'
   */
  if (KOPM_ACManlDefrstFb_flg_ovrdflg)
  {
    /* Switch: '<S98>/Switch4' incorporates:
     *  Constant: '<S98>/sat4'
     */
    VOPM_ACManlDefrstFb_flg = KOPM_ACManlDefrstFb_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S98>/Switch4' incorporates:
     *  Inport: '<Root>/TMS2VCU_AC_ACStatuts_Outputs'
     */
    VOPM_ACManlDefrstFb_flg =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_ACStatuts_Outputs_TMS2VCU_AC_ACStatuts_Outputs())->AC_ManualDefrostFb;
  }

  /* End of Switch: '<S98>/Switch4' */
  /* End of Outputs for SubSystem: '<S31>/Subsys_VOPM_ACManlDefrstFb_flg' */

  /* Outputs for Atomic SubSystem: '<S31>/Subsys_VOPM_ACAutoFb_flg' */
  /* Switch: '<S93>/Switch4' incorporates:
   *  Constant: '<S93>/sat3'
   */
  if (KOPM_ACAutoFb_flg_ovrdflg)
  {
    /* Switch: '<S93>/Switch4' incorporates:
     *  Constant: '<S93>/sat4'
     */
    VOPM_ACAutoFb_flg = KOPM_ACAutoFb_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S93>/Switch4' incorporates:
     *  Inport: '<Root>/TMS2VCU_AC_ACStatuts_Outputs'
     */
    VOPM_ACAutoFb_flg =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_ACStatuts_Outputs_TMS2VCU_AC_ACStatuts_Outputs())->AC_ACAutoFb;
  }

  /* End of Switch: '<S93>/Switch4' */
  /* End of Outputs for SubSystem: '<S31>/Subsys_VOPM_ACAutoFb_flg' */

  /* Outputs for Atomic SubSystem: '<S31>/Subsys_VOPM_ACBlwrModeSta_enum' */
  /* Switch: '<S94>/Switch4' incorporates:
   *  Constant: '<S94>/sat3'
   */
  if (KOPM_ACBlwrModeSta_enum_ovrdflg)
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Constant: '<S94>/sat4'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum = KOPM_ACBlwrModeSta_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Inport: '<Root>/TMS2VCU_AC_ACStatuts_Outputs'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_ACStatuts_Outputs_TMS2VCU_AC_ACStatuts_Outputs())->AC_BlowerModeSta;
  }

  /* End of Switch: '<S94>/Switch4' */

  /* MinMax: '<S94>/MinMax' incorporates:
   *  Constant: '<S94>/sat6'
   */
  if (VOPM_TMSC3WVMode_enum > KOPM_ACBlwrModeStaHi_enum)
  {
    /* MinMax: '<S153>/MinMax' */
    VOPM_TMSC3WVMode_enum = KOPM_ACBlwrModeStaHi_enum;
  }

  /* End of MinMax: '<S94>/MinMax' */

  /* MinMax: '<S94>/MinMax1' incorporates:
   *  Constant: '<S94>/sat7'
   */
  if (VOPM_TMSC3WVMode_enum >= KOPM_ACBlwrModeStaLo_enum)
  {
    /* MinMax: '<S94>/MinMax1' */
    VOPM_ACBlwrModeSta_enum = VOPM_TMSC3WVMode_enum;
  }
  else
  {
    /* MinMax: '<S94>/MinMax1' */
    VOPM_ACBlwrModeSta_enum = KOPM_ACBlwrModeStaLo_enum;
  }

  /* End of MinMax: '<S94>/MinMax1' */
  /* End of Outputs for SubSystem: '<S31>/Subsys_VOPM_ACBlwrModeSta_enum' */

  /* Outputs for Atomic SubSystem: '<S31>/Subsys_VOPM_ACFrntFanSpdVal_enum' */
  /* Switch: '<S95>/Switch4' incorporates:
   *  Constant: '<S95>/sat3'
   */
  if (KOPM_ACFrntFanSpdVal_enum_ovrdflg)
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Constant: '<S95>/sat4'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum = KOPM_ACFrntFanSpdVal_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Inport: '<Root>/TMS2VCU_AC_ACStatuts_Outputs'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_ACStatuts_Outputs_TMS2VCU_AC_ACStatuts_Outputs())->AC_FrontFanSpdValue;
  }

  /* End of Switch: '<S95>/Switch4' */

  /* MinMax: '<S95>/MinMax' incorporates:
   *  Constant: '<S95>/sat6'
   */
  if (VOPM_TMSC3WVMode_enum > KOPM_ACFrntFanSpdValHi_enum)
  {
    /* MinMax: '<S153>/MinMax' */
    VOPM_TMSC3WVMode_enum = KOPM_ACFrntFanSpdValHi_enum;
  }

  /* End of MinMax: '<S95>/MinMax' */

  /* MinMax: '<S95>/MinMax1' incorporates:
   *  Constant: '<S95>/sat7'
   */
  if (VOPM_TMSC3WVMode_enum >= KOPM_ACFrntFanSpdValLo_enum)
  {
    /* MinMax: '<S95>/MinMax1' */
    VOPM_ACFrntFanSpdVal_enum = VOPM_TMSC3WVMode_enum;
  }
  else
  {
    /* MinMax: '<S95>/MinMax1' */
    VOPM_ACFrntFanSpdVal_enum = KOPM_ACFrntFanSpdValLo_enum;
  }

  /* End of MinMax: '<S95>/MinMax1' */
  /* End of Outputs for SubSystem: '<S31>/Subsys_VOPM_ACFrntFanSpdVal_enum' */

  /* Outputs for Atomic SubSystem: '<S31>/Subsys_VOPM_ACPwrFb_flg' */
  /* Switch: '<S99>/Switch4' incorporates:
   *  Constant: '<S99>/sat3'
   */
  if (KOPM_ACPwrFb_flg_ovrdflg)
  {
    /* Switch: '<S99>/Switch4' incorporates:
     *  Constant: '<S99>/sat4'
     */
    VOPM_ACPwrFb_flg = KOPM_ACPwrFb_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S99>/Switch4' incorporates:
     *  Inport: '<Root>/TMS2VCU_AC_ACStatuts_Outputs'
     */
    VOPM_ACPwrFb_flg =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_ACStatuts_Outputs_TMS2VCU_AC_ACStatuts_Outputs())->AC_ACPowerFb;
  }

  /* End of Switch: '<S99>/Switch4' */
  /* End of Outputs for SubSystem: '<S31>/Subsys_VOPM_ACPwrFb_flg' */

  /* Outputs for Atomic SubSystem: '<S31>/Subsys_VOPM_ACAutoBlwrModeSta_enum' */
  /* Switch: '<S92>/Switch4' incorporates:
   *  Constant: '<S92>/sat3'
   */
  if (KOPM_ACAutoBlwrModeSta_enum_ovrdflg)
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Constant: '<S92>/sat4'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum = KOPM_ACAutoBlwrModeSta_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Inport: '<Root>/TMS2VCU_AC_ACStatuts_Outputs'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_ACStatuts_Outputs_TMS2VCU_AC_ACStatuts_Outputs())->AC_AutoBlowerModeSta;
  }

  /* End of Switch: '<S92>/Switch4' */

  /* MinMax: '<S92>/MinMax' incorporates:
   *  Constant: '<S92>/sat6'
   */
  if (VOPM_TMSC3WVMode_enum > KOPM_ACAutoBlwrModeStaHi_enum)
  {
    /* MinMax: '<S153>/MinMax' */
    VOPM_TMSC3WVMode_enum = KOPM_ACAutoBlwrModeStaHi_enum;
  }

  /* End of MinMax: '<S92>/MinMax' */

  /* MinMax: '<S92>/MinMax1' incorporates:
   *  Constant: '<S92>/sat7'
   */
  if (VOPM_TMSC3WVMode_enum >= KOPM_ACAutoBlwrModeStaLo_enum)
  {
    /* MinMax: '<S92>/MinMax1' */
    VOPM_ACAutoBlwrModeSta_enum = VOPM_TMSC3WVMode_enum;
  }
  else
  {
    /* MinMax: '<S92>/MinMax1' */
    VOPM_ACAutoBlwrModeSta_enum = KOPM_ACAutoBlwrModeStaLo_enum;
  }

  /* End of MinMax: '<S92>/MinMax1' */
  /* End of Outputs for SubSystem: '<S31>/Subsys_VOPM_ACAutoBlwrModeSta_enum' */

  /* Outputs for Atomic SubSystem: '<S31>/Subsys_VOPM_ACHybEcoModeSta_enum' */
  /* Switch: '<S96>/Switch4' incorporates:
   *  Constant: '<S96>/sat3'
   */
  if (KOPM_ACHybEcoModeSta_enum_ovrdflg)
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Constant: '<S96>/sat4'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum = KOPM_ACHybEcoModeSta_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Inport: '<Root>/TMS2VCU_AC_ACStatuts_Outputs'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_ACStatuts_Outputs_TMS2VCU_AC_ACStatuts_Outputs())->AC_HybridEcoModeSta;
  }

  /* End of Switch: '<S96>/Switch4' */

  /* MinMax: '<S96>/MinMax' incorporates:
   *  Constant: '<S96>/sat6'
   */
  if (VOPM_TMSC3WVMode_enum > KOPM_ACHybEcoModeStaHi_enum)
  {
    /* MinMax: '<S153>/MinMax' */
    VOPM_TMSC3WVMode_enum = KOPM_ACHybEcoModeStaHi_enum;
  }

  /* End of MinMax: '<S96>/MinMax' */

  /* MinMax: '<S96>/MinMax1' incorporates:
   *  Constant: '<S96>/sat7'
   */
  if (VOPM_TMSC3WVMode_enum >= KOPM_ACHybEcoModeStaLo_enum)
  {
    /* MinMax: '<S96>/MinMax1' */
    VOPM_ACHybEcoModeSta_enum = VOPM_TMSC3WVMode_enum;
  }
  else
  {
    /* MinMax: '<S96>/MinMax1' */
    VOPM_ACHybEcoModeSta_enum = KOPM_ACHybEcoModeStaLo_enum;
  }

  /* End of MinMax: '<S96>/MinMax1' */
  /* End of Outputs for SubSystem: '<S31>/Subsys_VOPM_ACHybEcoModeSta_enum' */

  /* Outputs for Atomic SubSystem: '<S31>/Subsys_VOPM_ACAirInletModeSta_enum' */
  /* Switch: '<S91>/Switch4' incorporates:
   *  Constant: '<S91>/sat3'
   */
  if (KOPM_ACAirInletModeSta_enum_ovrdflg)
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Constant: '<S91>/sat4'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum = KOPM_ACAirInletModeSta_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Inport: '<Root>/TMS2VCU_AC_ACStatuts_Outputs'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_ACStatuts_Outputs_TMS2VCU_AC_ACStatuts_Outputs())->AC_AirInletModeSta;
  }

  /* End of Switch: '<S91>/Switch4' */

  /* MinMax: '<S91>/MinMax' incorporates:
   *  Constant: '<S91>/sat6'
   */
  if (VOPM_TMSC3WVMode_enum > KOPM_ACAirInletModeStaHi_enum)
  {
    /* MinMax: '<S153>/MinMax' */
    VOPM_TMSC3WVMode_enum = KOPM_ACAirInletModeStaHi_enum;
  }

  /* End of MinMax: '<S91>/MinMax' */

  /* MinMax: '<S91>/MinMax1' incorporates:
   *  Constant: '<S91>/sat7'
   */
  if (VOPM_TMSC3WVMode_enum >= KOPM_ACAirInletModeStaLo_enum)
  {
    /* MinMax: '<S91>/MinMax1' */
    VOPM_ACAirInletModeSta_enum = VOPM_TMSC3WVMode_enum;
  }
  else
  {
    /* MinMax: '<S91>/MinMax1' */
    VOPM_ACAirInletModeSta_enum = KOPM_ACAirInletModeStaLo_enum;
  }

  /* End of MinMax: '<S91>/MinMax1' */
  /* End of Outputs for SubSystem: '<S31>/Subsys_VOPM_ACAirInletModeSta_enum' */

  /* Outputs for Atomic SubSystem: '<S31>/Subsys_VOPM_BCMRrViewMirrHeatgSts_flg' */
  /* Switch: '<S100>/Switch4' incorporates:
   *  Constant: '<S100>/sat3'
   */
  if (KOPM_BCMRrViewMirrHeatgSts_flg_ovrdflg)
  {
    /* Switch: '<S100>/Switch4' incorporates:
     *  Constant: '<S100>/sat4'
     */
    VOPM_BCMRrViewMirrHeatgSts_flg = KOPM_BCMRrViewMirrHeatgSts_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S100>/Switch4' incorporates:
     *  Inport: '<Root>/TMS2VCU_AC_ACStatuts_Outputs'
     */
    VOPM_BCMRrViewMirrHeatgSts_flg =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_ACStatuts_Outputs_TMS2VCU_AC_ACStatuts_Outputs())->BCM_RearViewMirrHeatingSts;
  }

  /* End of Switch: '<S100>/Switch4' */
  /* End of Outputs for SubSystem: '<S31>/Subsys_VOPM_BCMRrViewMirrHeatgSts_flg' */

  /* BusCreator: '<S31>/BusCreator' incorporates:
   *  Switch: '<S100>/Switch4'
   *  Switch: '<S93>/Switch4'
   *  Switch: '<S98>/Switch4'
   *  Switch: '<S99>/Switch4'
   */
  AppSwcOpm_ARID_DEF.AC_ACStatuts_BOD_g.AC_leftTempValue =
      VOPM_ACLeftTempVal_enum;
  AppSwcOpm_ARID_DEF.AC_ACStatuts_BOD_g.AC_ManualDefrostFb =
      VOPM_ACManlDefrstFb_flg;
  AppSwcOpm_ARID_DEF.AC_ACStatuts_BOD_g.AC_ACAutoFb = VOPM_ACAutoFb_flg;
  AppSwcOpm_ARID_DEF.AC_ACStatuts_BOD_g.AC_BlowerModeSta =
      VOPM_ACBlwrModeSta_enum;
  AppSwcOpm_ARID_DEF.AC_ACStatuts_BOD_g.AC_FrontFanSpdValue =
      VOPM_ACFrntFanSpdVal_enum;
  AppSwcOpm_ARID_DEF.AC_ACStatuts_BOD_g.AC_ACPowerFb = VOPM_ACPwrFb_flg;
  AppSwcOpm_ARID_DEF.AC_ACStatuts_BOD_g.AC_AutoBlowerModeSta =
      VOPM_ACAutoBlwrModeSta_enum;
  AppSwcOpm_ARID_DEF.AC_ACStatuts_BOD_g.AC_HybridEcoModeSta =
      VOPM_ACHybEcoModeSta_enum;
  AppSwcOpm_ARID_DEF.AC_ACStatuts_BOD_g.AC_AirInletModeSta =
      VOPM_ACAirInletModeSta_enum;
  AppSwcOpm_ARID_DEF.AC_ACStatuts_BOD_g.BCM_RearViewMirrHeatingSts =
      VOPM_BCMRrViewMirrHeatgSts_flg;

  /* Outputs for Atomic SubSystem: '<S33>/Subsys_VOPM_ESCLUnOrLockCrtl_nu' */
  /* Switch: '<S112>/Switch4' incorporates:
   *  Constant: '<S112>/sat3'
   */
  if (KOPM_ESCLUnOrLockCrtl_nu_ovrdflg)
  {
    /* Switch: '<S112>/Switch4' incorporates:
     *  Constant: '<S112>/sat4'
     */
    VOPM_ESCLUnOrLockCrtl_nu = KOPM_ESCLUnOrLockCrtl_nu_ovrdval;
  }
  else
  {
    /* Switch: '<S112>/Switch4' incorporates:
     *  Inport: '<Root>/Bcm2OpmOBD_outputs'
     */
    VOPM_ESCLUnOrLockCrtl_nu =
        (Rte_IRead_Runbl_OpmCanTx_100ms_Bcm2OpmOBD_outputs_Bcm2OpmOBD_outputs())
            ->ESCL_UnOrLockCrtl;
  }

  /* End of Switch: '<S112>/Switch4' */

  /* MinMax: '<S112>/MinMax' incorporates:
   *  Constant: '<S112>/sat6'
   *  Switch: '<S112>/Switch4'
   */
  if (VOPM_ESCLUnOrLockCrtl_nu > KOPM_ESCLUnOrLockCrtlHi_nu)
  {
    /* MinMax: '<S112>/MinMax' */
    VOPM_ESCLUnOrLockCrtl_nu = KOPM_ESCLUnOrLockCrtlHi_nu;
  }

  /* End of MinMax: '<S112>/MinMax' */

  /* MinMax: '<S112>/MinMax1' incorporates:
   *  Constant: '<S112>/sat7'
   *  MinMax: '<S112>/MinMax'
   */
  if (VOPM_ESCLUnOrLockCrtl_nu < KOPM_ESCLUnOrLockCrtlLo_nu)
  {
    /* MinMax: '<S112>/MinMax1' */
    VOPM_ESCLUnOrLockCrtl_nu = KOPM_ESCLUnOrLockCrtlLo_nu;
  }

  /* End of MinMax: '<S112>/MinMax1' */
  /* End of Outputs for SubSystem: '<S33>/Subsys_VOPM_ESCLUnOrLockCrtl_nu' */

  /* BusCreator: '<S33>/BusCreator' incorporates:
   *  MinMax: '<S112>/MinMax1'
   */
  AppSwcOpm_ARID_DEF.BCM_ESCLCommand_BOD_c.ESCL_UnOrLockCrtl =
      VOPM_ESCLUnOrLockCrtl_nu;

  /* Outputs for Atomic SubSystem: '<S36>/Subsys_VOPM_TMSBEXVPstnCmd_cnt' */
  /* Switch: '<S134>/Switch4' incorporates:
   *  Constant: '<S134>/sat3'
   */
  if (KOPM_TMSBEXVPstnCmd_cnt_ovrdflg)
  {
    /* MinMax: '<S122>/MinMax' incorporates:
     *  Constant: '<S134>/sat4'
     *  MinMax: '<S139>/MinMax'
     */
    VOPM_TMSC3WVPosRec_enum = KOPM_TMSBEXVPstnCmd_cnt_ovrdval;
  }
  else
  {
    /* MinMax: '<S122>/MinMax' incorporates:
     *  Inport: '<Root>/TMS2VCU_TMS_LINTestData2_Outputs'
     *  MinMax: '<S139>/MinMax'
     */
    VOPM_TMSC3WVPosRec_enum =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData2_Outputs_TMS2VCU_TMS_LINTestData2_Outputs())->TMS_BEXVPositionCmd;
  }

  /* End of Switch: '<S134>/Switch4' */

  /* MinMax: '<S134>/MinMax' incorporates:
   *  Constant: '<S134>/sat6'
   */
  if (VOPM_TMSC3WVPosRec_enum > KOPM_TMSBEXVPstnCmdHi_cnt)
  {
    /* MinMax: '<S122>/MinMax' */
    VOPM_TMSC3WVPosRec_enum = KOPM_TMSBEXVPstnCmdHi_cnt;
  }

  /* End of MinMax: '<S134>/MinMax' */

  /* MinMax: '<S134>/MinMax1' incorporates:
   *  Constant: '<S134>/sat7'
   */
  if (VOPM_TMSC3WVPosRec_enum >= KOPM_TMSBEXVPstnCmdLo_cnt)
  {
    /* MinMax: '<S134>/MinMax1' */
    VOPM_TMSBEXVPstnCmd_cnt = VOPM_TMSC3WVPosRec_enum;
  }
  else
  {
    /* MinMax: '<S134>/MinMax1' */
    VOPM_TMSBEXVPstnCmd_cnt = KOPM_TMSBEXVPstnCmdLo_cnt;
  }

  /* End of MinMax: '<S134>/MinMax1' */
  /* End of Outputs for SubSystem: '<S36>/Subsys_VOPM_TMSBEXVPstnCmd_cnt' */

  /* Outputs for Atomic SubSystem: '<S36>/Subsys_VOPM_TMSBEXVCurrentPstn_cnt' */
  /* Switch: '<S133>/Switch4' incorporates:
   *  Constant: '<S133>/sat3'
   */
  if (KOPM_TMSBEXVCurrentPstn_cnt_ovrdflg)
  {
    /* MinMax: '<S122>/MinMax' incorporates:
     *  Constant: '<S133>/sat4'
     *  MinMax: '<S139>/MinMax'
     */
    VOPM_TMSC3WVPosRec_enum = KOPM_TMSBEXVCurrentPstn_cnt_ovrdval;
  }
  else
  {
    /* MinMax: '<S122>/MinMax' incorporates:
     *  Inport: '<Root>/TMS2VCU_TMS_LINTestData2_Outputs'
     *  MinMax: '<S139>/MinMax'
     */
    VOPM_TMSC3WVPosRec_enum =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData2_Outputs_TMS2VCU_TMS_LINTestData2_Outputs())->TMS_BEXVCurrentPosition;
  }

  /* End of Switch: '<S133>/Switch4' */

  /* MinMax: '<S133>/MinMax' incorporates:
   *  Constant: '<S133>/sat6'
   */
  if (VOPM_TMSC3WVPosRec_enum > KOPM_TMSBEXVCurrentPstnHi_cnt)
  {
    /* MinMax: '<S122>/MinMax' */
    VOPM_TMSC3WVPosRec_enum = KOPM_TMSBEXVCurrentPstnHi_cnt;
  }

  /* End of MinMax: '<S133>/MinMax' */

  /* MinMax: '<S133>/MinMax1' incorporates:
   *  Constant: '<S133>/sat7'
   */
  if (VOPM_TMSC3WVPosRec_enum >= KOPM_TMSBEXVCurrentPstnLo_cnt)
  {
    /* MinMax: '<S133>/MinMax1' */
    VOPM_TMSBEXVCurrentPstn_cnt = VOPM_TMSC3WVPosRec_enum;
  }
  else
  {
    /* MinMax: '<S133>/MinMax1' */
    VOPM_TMSBEXVCurrentPstn_cnt = KOPM_TMSBEXVCurrentPstnLo_cnt;
  }

  /* End of MinMax: '<S133>/MinMax1' */
  /* End of Outputs for SubSystem: '<S36>/Subsys_VOPM_TMSBEXVCurrentPstn_cnt' */

  /* Outputs for Atomic SubSystem: '<S36>/Subsys_VOPM_TMSAEXVPstnReq_cnt' */
  /* Switch: '<S132>/Switch4' incorporates:
   *  Constant: '<S132>/sat3'
   */
  if (KOPM_TMSAEXVPstnReq_cnt_ovrdflg)
  {
    /* MinMax: '<S122>/MinMax' incorporates:
     *  Constant: '<S132>/sat4'
     *  MinMax: '<S139>/MinMax'
     */
    VOPM_TMSC3WVPosRec_enum = KOPM_TMSAEXVPstnReq_cnt_ovrdval;
  }
  else
  {
    /* MinMax: '<S122>/MinMax' incorporates:
     *  Inport: '<Root>/TMS2VCU_TMS_LINTestData2_Outputs'
     *  MinMax: '<S139>/MinMax'
     */
    VOPM_TMSC3WVPosRec_enum =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData2_Outputs_TMS2VCU_TMS_LINTestData2_Outputs())->TMS_AEXVPositionReq;
  }

  /* End of Switch: '<S132>/Switch4' */

  /* MinMax: '<S132>/MinMax' incorporates:
   *  Constant: '<S132>/sat6'
   */
  if (VOPM_TMSC3WVPosRec_enum > KOPM_TMSAEXVPstnReqHi_cnt)
  {
    /* MinMax: '<S122>/MinMax' */
    VOPM_TMSC3WVPosRec_enum = KOPM_TMSAEXVPstnReqHi_cnt;
  }

  /* End of MinMax: '<S132>/MinMax' */

  /* MinMax: '<S132>/MinMax1' incorporates:
   *  Constant: '<S132>/sat7'
   */
  if (VOPM_TMSC3WVPosRec_enum >= KOPM_TMSAEXVPstnReqLo_cnt)
  {
    /* MinMax: '<S132>/MinMax1' */
    VOPM_TMSAEXVPstnReq_cnt = VOPM_TMSC3WVPosRec_enum;
  }
  else
  {
    /* MinMax: '<S132>/MinMax1' */
    VOPM_TMSAEXVPstnReq_cnt = KOPM_TMSAEXVPstnReqLo_cnt;
  }

  /* End of MinMax: '<S132>/MinMax1' */
  /* End of Outputs for SubSystem: '<S36>/Subsys_VOPM_TMSAEXVPstnReq_cnt' */

  /* Outputs for Atomic SubSystem: '<S36>/Subsys_VOPM_TMSAEXVCurrentPstn_cnt' */
  /* Switch: '<S131>/Switch4' incorporates:
   *  Constant: '<S131>/sat3'
   */
  if (KOPM_TMSAEXVCurrentPstn_cnt_ovrdflg)
  {
    /* MinMax: '<S122>/MinMax' incorporates:
     *  Constant: '<S131>/sat4'
     *  MinMax: '<S139>/MinMax'
     */
    VOPM_TMSC3WVPosRec_enum = KOPM_TMSAEXVCurrentPstn_cnt_ovrdval;
  }
  else
  {
    /* MinMax: '<S122>/MinMax' incorporates:
     *  Inport: '<Root>/TMS2VCU_TMS_LINTestData2_Outputs'
     *  MinMax: '<S139>/MinMax'
     */
    VOPM_TMSC3WVPosRec_enum =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData2_Outputs_TMS2VCU_TMS_LINTestData2_Outputs())->TMS_AEXVCurrentPosition;
  }

  /* End of Switch: '<S131>/Switch4' */

  /* MinMax: '<S131>/MinMax' incorporates:
   *  Constant: '<S131>/sat6'
   */
  if (VOPM_TMSC3WVPosRec_enum > KOPM_TMSAEXVCurrentPstnHi_cnt)
  {
    /* MinMax: '<S122>/MinMax' */
    VOPM_TMSC3WVPosRec_enum = KOPM_TMSAEXVCurrentPstnHi_cnt;
  }

  /* End of MinMax: '<S131>/MinMax' */

  /* MinMax: '<S131>/MinMax1' incorporates:
   *  Constant: '<S131>/sat7'
   */
  if (VOPM_TMSC3WVPosRec_enum >= KOPM_TMSAEXVCurrentPstnLo_cnt)
  {
    /* MinMax: '<S131>/MinMax1' */
    VOPM_TMSAEXVCurrentPstn_cnt = VOPM_TMSC3WVPosRec_enum;
  }
  else
  {
    /* MinMax: '<S131>/MinMax1' */
    VOPM_TMSAEXVCurrentPstn_cnt = KOPM_TMSAEXVCurrentPstnLo_cnt;
  }

  /* End of MinMax: '<S131>/MinMax1' */
  /* End of Outputs for SubSystem: '<S36>/Subsys_VOPM_TMSAEXVCurrentPstn_cnt' */

  /* BusCreator: '<S36>/BusCreator' */
  AppSwcOpm_ARID_DEF.TMS_LINTestData2_BOD_p.TMS_BEXVPositionCmd =
      VOPM_TMSBEXVPstnCmd_cnt;
  AppSwcOpm_ARID_DEF.TMS_LINTestData2_BOD_p.TMS_BEXVCurrentPosition =
      VOPM_TMSBEXVCurrentPstn_cnt;
  AppSwcOpm_ARID_DEF.TMS_LINTestData2_BOD_p.TMS_AEXVPositionReq =
      VOPM_TMSAEXVPstnReq_cnt;
  AppSwcOpm_ARID_DEF.TMS_LINTestData2_BOD_p.TMS_AEXVCurrentPosition =
      VOPM_TMSAEXVCurrentPstn_cnt;

  /* Outputs for Atomic SubSystem: '<S37>/Subsys_VOPM_TMSHPEXVCurrentPstn_cnt' */
  /* Switch: '<S143>/Switch4' incorporates:
   *  Constant: '<S143>/sat3'
   */
  if (KOPM_TMSHPEXVCurrentPstn_cnt_ovrdflg)
  {
    /* MinMax: '<S122>/MinMax' incorporates:
     *  Constant: '<S143>/sat4'
     *  MinMax: '<S139>/MinMax'
     */
    VOPM_TMSC3WVPosRec_enum = KOPM_TMSHPEXVCurrentPstn_cnt_ovrdval;
  }
  else
  {
    /* MinMax: '<S122>/MinMax' incorporates:
     *  Inport: '<Root>/TMS2VCU_TMS_LINTestData3_Outputs'
     *  MinMax: '<S139>/MinMax'
     */
    VOPM_TMSC3WVPosRec_enum =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData3_Outputs_TMS2VCU_TMS_LINTestData3_Outputs())->TMS_HPEXVCurrentPosition;
  }

  /* End of Switch: '<S143>/Switch4' */

  /* MinMax: '<S143>/MinMax' incorporates:
   *  Constant: '<S143>/sat6'
   */
  if (VOPM_TMSC3WVPosRec_enum > KOPM_TMSHPEXVCurrentPstnHi_cnt)
  {
    /* MinMax: '<S122>/MinMax' */
    VOPM_TMSC3WVPosRec_enum = KOPM_TMSHPEXVCurrentPstnHi_cnt;
  }

  /* End of MinMax: '<S143>/MinMax' */

  /* MinMax: '<S143>/MinMax1' incorporates:
   *  Constant: '<S143>/sat7'
   */
  if (VOPM_TMSC3WVPosRec_enum >= KOPM_TMSHPEXVCurrentPstnLo_cnt)
  {
    /* MinMax: '<S143>/MinMax1' */
    VOPM_TMSHPEXVCurrentPstn_cnt = VOPM_TMSC3WVPosRec_enum;
  }
  else
  {
    /* MinMax: '<S143>/MinMax1' */
    VOPM_TMSHPEXVCurrentPstn_cnt = KOPM_TMSHPEXVCurrentPstnLo_cnt;
  }

  /* End of MinMax: '<S143>/MinMax1' */
  /* End of Outputs for SubSystem: '<S37>/Subsys_VOPM_TMSHPEXVCurrentPstn_cnt' */

  /* Outputs for Atomic SubSystem: '<S37>/Subsys_VOPM_TMSC5WVBPosSetReq_enum' */
  /* Switch: '<S140>/Switch4' incorporates:
   *  Constant: '<S140>/sat3'
   */
  if (KOPM_TMSC5WVBPosSetReq_enum_ovrdflg)
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Constant: '<S140>/sat4'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum = KOPM_TMSC5WVBPosSetReq_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Inport: '<Root>/TMS2VCU_TMS_LINTestData3_Outputs'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData3_Outputs_TMS2VCU_TMS_LINTestData3_Outputs())->TMS_C5WVBPosSetReq;
  }

  /* End of Switch: '<S140>/Switch4' */

  /* MinMax: '<S140>/MinMax' incorporates:
   *  Constant: '<S140>/sat6'
   */
  if (VOPM_TMSC3WVMode_enum > KOPM_TMSC5WVBPosSetReqHi_enum)
  {
    /* MinMax: '<S153>/MinMax' */
    VOPM_TMSC3WVMode_enum = KOPM_TMSC5WVBPosSetReqHi_enum;
  }

  /* End of MinMax: '<S140>/MinMax' */

  /* MinMax: '<S140>/MinMax1' incorporates:
   *  Constant: '<S140>/sat7'
   */
  if (VOPM_TMSC3WVMode_enum >= KOPM_TMSC5WVBPosSetReqLo_enum)
  {
    /* MinMax: '<S140>/MinMax1' */
    VOPM_TMSC5WVBPosSetReq_enum = VOPM_TMSC3WVMode_enum;
  }
  else
  {
    /* MinMax: '<S140>/MinMax1' */
    VOPM_TMSC5WVBPosSetReq_enum = KOPM_TMSC5WVBPosSetReqLo_enum;
  }

  /* End of MinMax: '<S140>/MinMax1' */
  /* End of Outputs for SubSystem: '<S37>/Subsys_VOPM_TMSC5WVBPosSetReq_enum' */

  /* Outputs for Atomic SubSystem: '<S37>/Subsys_VOPM_TMSC3WVBPosSetReq_enum' */
  /* Switch: '<S137>/Switch4' incorporates:
   *  Constant: '<S137>/sat3'
   */
  if (KOPM_TMSC3WVBPosSetReq_enum_ovrdflg)
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Constant: '<S137>/sat4'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum = KOPM_TMSC3WVBPosSetReq_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Inport: '<Root>/TMS2VCU_TMS_LINTestData3_Outputs'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData3_Outputs_TMS2VCU_TMS_LINTestData3_Outputs())->TMS_C3WVBPosSetReq;
  }

  /* End of Switch: '<S137>/Switch4' */

  /* MinMax: '<S137>/MinMax' incorporates:
   *  Constant: '<S137>/sat6'
   */
  if (VOPM_TMSC3WVMode_enum > KOPM_TMSC3WVBPosSetReqHi_enum)
  {
    /* MinMax: '<S153>/MinMax' */
    VOPM_TMSC3WVMode_enum = KOPM_TMSC3WVBPosSetReqHi_enum;
  }

  /* End of MinMax: '<S137>/MinMax' */

  /* MinMax: '<S137>/MinMax1' incorporates:
   *  Constant: '<S137>/sat7'
   */
  if (VOPM_TMSC3WVMode_enum >= KOPM_TMSC3WVBPosSetReqLo_enum)
  {
    /* MinMax: '<S137>/MinMax1' */
    VOPM_TMSC3WVBPosSetReq_enum = VOPM_TMSC3WVMode_enum;
  }
  else
  {
    /* MinMax: '<S137>/MinMax1' */
    VOPM_TMSC3WVBPosSetReq_enum = KOPM_TMSC3WVBPosSetReqLo_enum;
  }

  /* End of MinMax: '<S137>/MinMax1' */
  /* End of Outputs for SubSystem: '<S37>/Subsys_VOPM_TMSC3WVBPosSetReq_enum' */

  /* Outputs for Atomic SubSystem: '<S37>/Subsys_VOPM_TMSHPEXVEnblCmd_flg' */
  /* Switch: '<S144>/Switch4' incorporates:
   *  Constant: '<S144>/sat3'
   */
  if (KOPM_TMSHPEXVEnblCmd_flg_ovrdflg)
  {
    /* Switch: '<S144>/Switch4' incorporates:
     *  Constant: '<S144>/sat4'
     */
    VOPM_TMSHPEXVEnblCmd_flg = KOPM_TMSHPEXVEnblCmd_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S144>/Switch4' incorporates:
     *  Inport: '<Root>/TMS2VCU_TMS_LINTestData3_Outputs'
     */
    VOPM_TMSHPEXVEnblCmd_flg =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData3_Outputs_TMS2VCU_TMS_LINTestData3_Outputs())->TMS_HPEXVEnableCmd;
  }

  /* End of Switch: '<S144>/Switch4' */
  /* End of Outputs for SubSystem: '<S37>/Subsys_VOPM_TMSHPEXVEnblCmd_flg' */

  /* Outputs for Atomic SubSystem: '<S37>/Subsys_VOPM_TMSBEXVEnblCmd_flg' */
  /* Switch: '<S136>/Switch4' incorporates:
   *  Constant: '<S136>/sat3'
   */
  if (KOPM_TMSBEXVEnblCmd_flg_ovrdflg)
  {
    /* Switch: '<S136>/Switch4' incorporates:
     *  Constant: '<S136>/sat4'
     */
    VOPM_TMSBEXVEnblCmd_flg = KOPM_TMSBEXVEnblCmd_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S136>/Switch4' incorporates:
     *  Inport: '<Root>/TMS2VCU_TMS_LINTestData3_Outputs'
     */
    VOPM_TMSBEXVEnblCmd_flg =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData3_Outputs_TMS2VCU_TMS_LINTestData3_Outputs())->TMS_BEXVEnableCmd;
  }

  /* End of Switch: '<S136>/Switch4' */
  /* End of Outputs for SubSystem: '<S37>/Subsys_VOPM_TMSBEXVEnblCmd_flg' */

  /* Outputs for Atomic SubSystem: '<S37>/Subsys_VOPM_TMSAEXVEnblReq_flg' */
  /* Switch: '<S135>/Switch4' incorporates:
   *  Constant: '<S135>/sat3'
   */
  if (KOPM_TMSAEXVEnblReq_flg_ovrdflg)
  {
    /* Switch: '<S135>/Switch4' incorporates:
     *  Constant: '<S135>/sat4'
     */
    VOPM_TMSAEXVEnblReq_flg = KOPM_TMSAEXVEnblReq_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S135>/Switch4' incorporates:
     *  Inport: '<Root>/TMS2VCU_TMS_LINTestData3_Outputs'
     */
    VOPM_TMSAEXVEnblReq_flg =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData3_Outputs_TMS2VCU_TMS_LINTestData3_Outputs())->TMS_AEXVEnableReq;
  }

  /* End of Switch: '<S135>/Switch4' */
  /* End of Outputs for SubSystem: '<S37>/Subsys_VOPM_TMSAEXVEnblReq_flg' */

  /* Outputs for Atomic SubSystem: '<S37>/Subsys_VOPM_TMSC5WVPosRec_enum' */
  /* Switch: '<S142>/Switch4' incorporates:
   *  Constant: '<S142>/sat3'
   */
  if (KOPM_TMSC5WVPosRec_enum_ovrdflg)
  {
    /* MinMax: '<S122>/MinMax' incorporates:
     *  Constant: '<S142>/sat4'
     *  MinMax: '<S139>/MinMax'
     */
    VOPM_TMSC3WVPosRec_enum = KOPM_TMSC5WVPosRec_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S122>/MinMax' incorporates:
     *  Inport: '<Root>/TMS2VCU_TMS_LINTestData3_Outputs'
     *  MinMax: '<S139>/MinMax'
     */
    VOPM_TMSC3WVPosRec_enum =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData3_Outputs_TMS2VCU_TMS_LINTestData3_Outputs())->TMS_C5WVPosRec;
  }

  /* End of Switch: '<S142>/Switch4' */

  /* MinMax: '<S142>/MinMax' incorporates:
   *  Constant: '<S142>/sat6'
   */
  if (VOPM_TMSC3WVPosRec_enum > KOPM_TMSC5WVPosRecHi_enum)
  {
    /* MinMax: '<S122>/MinMax' */
    VOPM_TMSC3WVPosRec_enum = KOPM_TMSC5WVPosRecHi_enum;
  }

  /* End of MinMax: '<S142>/MinMax' */

  /* MinMax: '<S142>/MinMax1' incorporates:
   *  Constant: '<S142>/sat7'
   */
  if (VOPM_TMSC3WVPosRec_enum >= KOPM_TMSC5WVPosRecLo_enum)
  {
    /* MinMax: '<S142>/MinMax1' */
    VOPM_TMSC5WVPosRec_enum = VOPM_TMSC3WVPosRec_enum;
  }
  else
  {
    /* MinMax: '<S142>/MinMax1' */
    VOPM_TMSC5WVPosRec_enum = KOPM_TMSC5WVPosRecLo_enum;
  }

  /* End of MinMax: '<S142>/MinMax1' */
  /* End of Outputs for SubSystem: '<S37>/Subsys_VOPM_TMSC5WVPosRec_enum' */

  /* Outputs for Atomic SubSystem: '<S37>/Subsys_VOPM_TMSC3WVPosRec_enum' */
  /* Switch: '<S139>/Switch4' incorporates:
   *  Constant: '<S139>/sat3'
   */
  if (KOPM_TMSC3WVPosRec_enum_ovrdflg)
  {
    /* MinMax: '<S122>/MinMax' incorporates:
     *  Constant: '<S139>/sat4'
     *  MinMax: '<S139>/MinMax'
     */
    VOPM_TMSC3WVPosRec_enum = KOPM_TMSC3WVPosRec_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S122>/MinMax' incorporates:
     *  Inport: '<Root>/TMS2VCU_TMS_LINTestData3_Outputs'
     *  MinMax: '<S139>/MinMax'
     */
    VOPM_TMSC3WVPosRec_enum =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData3_Outputs_TMS2VCU_TMS_LINTestData3_Outputs())->TMS_C3WVPosRec;
  }

  /* End of Switch: '<S139>/Switch4' */

  /* MinMax: '<S139>/MinMax' incorporates:
   *  Constant: '<S139>/sat6'
   */
  if (VOPM_TMSC3WVPosRec_enum > KOPM_TMSC3WVPosRecHi_enum)
  {
    /* MinMax: '<S122>/MinMax' */
    VOPM_TMSC3WVPosRec_enum = KOPM_TMSC3WVPosRecHi_enum;
  }

  /* End of MinMax: '<S139>/MinMax' */

  /* MinMax: '<S139>/MinMax1' incorporates:
   *  Constant: '<S139>/sat7'
   */
  if (VOPM_TMSC3WVPosRec_enum < KOPM_TMSC3WVPosRecLo_enum)
  {
    /* MinMax: '<S122>/MinMax' incorporates:
     *  MinMax: '<S139>/MinMax1'
     */
    VOPM_TMSC3WVPosRec_enum = KOPM_TMSC3WVPosRecLo_enum;
  }

  /* End of MinMax: '<S139>/MinMax1' */
  /* End of Outputs for SubSystem: '<S37>/Subsys_VOPM_TMSC3WVPosRec_enum' */

  /* Outputs for Atomic SubSystem: '<S37>/Subsys_VOPM_TMSC5WVMode_enum' */
  /* Switch: '<S141>/Switch4' incorporates:
   *  Constant: '<S141>/sat3'
   */
  if (KOPM_TMSC5WVMode_enum_ovrdflg)
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Constant: '<S141>/sat4'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum = KOPM_TMSC5WVMode_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Inport: '<Root>/TMS2VCU_TMS_LINTestData3_Outputs'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData3_Outputs_TMS2VCU_TMS_LINTestData3_Outputs())->TMS_C5WVMode;
  }

  /* End of Switch: '<S141>/Switch4' */

  /* MinMax: '<S141>/MinMax' incorporates:
   *  Constant: '<S141>/sat6'
   */
  if (VOPM_TMSC3WVMode_enum > KOPM_TMSC5WVModeHi_enum)
  {
    /* MinMax: '<S153>/MinMax' */
    VOPM_TMSC3WVMode_enum = KOPM_TMSC5WVModeHi_enum;
  }

  /* End of MinMax: '<S141>/MinMax' */

  /* MinMax: '<S141>/MinMax1' incorporates:
   *  Constant: '<S141>/sat7'
   */
  if (VOPM_TMSC3WVMode_enum >= KOPM_TMSC5WVModeLo_enum)
  {
    /* MinMax: '<S141>/MinMax1' */
    VOPM_TMSC5WVMode_enum = VOPM_TMSC3WVMode_enum;
  }
  else
  {
    /* MinMax: '<S141>/MinMax1' */
    VOPM_TMSC5WVMode_enum = KOPM_TMSC5WVModeLo_enum;
  }

  /* End of MinMax: '<S141>/MinMax1' */
  /* End of Outputs for SubSystem: '<S37>/Subsys_VOPM_TMSC5WVMode_enum' */

  /* Outputs for Atomic SubSystem: '<S37>/Subsys_VOPM_TMSC3WVMode_enum' */
  /* Switch: '<S138>/Switch4' incorporates:
   *  Constant: '<S138>/sat3'
   */
  if (KOPM_TMSC3WVMode_enum_ovrdflg)
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Constant: '<S138>/sat4'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum = KOPM_TMSC3WVMode_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  Inport: '<Root>/TMS2VCU_TMS_LINTestData3_Outputs'
     *  MinMax: '<S138>/MinMax'
     */
    VOPM_TMSC3WVMode_enum =
        (Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData3_Outputs_TMS2VCU_TMS_LINTestData3_Outputs())->TMS_C3WVMode;
  }

  /* End of Switch: '<S138>/Switch4' */

  /* MinMax: '<S138>/MinMax' incorporates:
   *  Constant: '<S138>/sat6'
   */
  if (VOPM_TMSC3WVMode_enum > KOPM_TMSC3WVModeHi_enum)
  {
    /* MinMax: '<S153>/MinMax' */
    VOPM_TMSC3WVMode_enum = KOPM_TMSC3WVModeHi_enum;
  }

  /* End of MinMax: '<S138>/MinMax' */

  /* MinMax: '<S138>/MinMax1' incorporates:
   *  Constant: '<S138>/sat7'
   */
  if (VOPM_TMSC3WVMode_enum < KOPM_TMSC3WVModeLo_enum)
  {
    /* MinMax: '<S153>/MinMax' incorporates:
     *  MinMax: '<S138>/MinMax1'
     */
    VOPM_TMSC3WVMode_enum = KOPM_TMSC3WVModeLo_enum;
  }

  /* End of MinMax: '<S138>/MinMax1' */
  /* End of Outputs for SubSystem: '<S37>/Subsys_VOPM_TMSC3WVMode_enum' */

  /* BusCreator: '<S37>/BusCreator' incorporates:
   *  Switch: '<S135>/Switch4'
   *  Switch: '<S136>/Switch4'
   *  Switch: '<S144>/Switch4'
   */
  AppSwcOpm_ARID_DEF.TMS_LINTestData3_BOD_a.TMS_HPEXVCurrentPosition =
      VOPM_TMSHPEXVCurrentPstn_cnt;
  AppSwcOpm_ARID_DEF.TMS_LINTestData3_BOD_a.TMS_C5WVBPosSetReq =
      VOPM_TMSC5WVBPosSetReq_enum;
  AppSwcOpm_ARID_DEF.TMS_LINTestData3_BOD_a.TMS_C3WVBPosSetReq =
      VOPM_TMSC3WVBPosSetReq_enum;
  AppSwcOpm_ARID_DEF.TMS_LINTestData3_BOD_a.TMS_HPEXVEnableCmd =
      VOPM_TMSHPEXVEnblCmd_flg;
  AppSwcOpm_ARID_DEF.TMS_LINTestData3_BOD_a.TMS_BEXVEnableCmd =
      VOPM_TMSBEXVEnblCmd_flg;
  AppSwcOpm_ARID_DEF.TMS_LINTestData3_BOD_a.TMS_AEXVEnableReq =
      VOPM_TMSAEXVEnblReq_flg;
  AppSwcOpm_ARID_DEF.TMS_LINTestData3_BOD_a.TMS_C5WVPosRec =
      VOPM_TMSC5WVPosRec_enum;
  AppSwcOpm_ARID_DEF.TMS_LINTestData3_BOD_a.TMS_C3WVPosRec =
      VOPM_TMSC3WVPosRec_enum;
  AppSwcOpm_ARID_DEF.TMS_LINTestData3_BOD_a.TMS_C5WVMode = VOPM_TMSC5WVMode_enum;
  AppSwcOpm_ARID_DEF.TMS_LINTestData3_BOD_a.TMS_C3WVMode = VOPM_TMSC3WVMode_enum;
}

/* Output and update for function-call system: '<Root>/Opm10ms' */
static void Runbl_Opm10ms(void)
{
  float32 tmp;

  /* Outputs for Atomic SubSystem: '<S189>/Subsys_VOPM_BraSwi_flg' */
  /* Switch: '<S192>/Switch4' incorporates:
   *  Constant: '<S192>/sat3'
   */
  if (KOPM_BraSwi_flg_ovrdflg)
  {
    /* Switch: '<S192>/Switch4' incorporates:
     *  Constant: '<S192>/sat4'
     */
    VOPM_BraSwi_flg = KOPM_BraSwi_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S192>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S192>/Data Type Conversion1'
     */
    VOPM_BraSwi_flg = (Rte_IrvIRead_Runbl_OpmCanTx_10ms_Vcu2OpmEPT_outputs())
                          ->VIPC_BrkSwActv_flg;
  }

  /* End of Switch: '<S192>/Switch4' */
  /* End of Outputs for SubSystem: '<S189>/Subsys_VOPM_BraSwi_flg' */

  /* Outputs for Atomic SubSystem: '<S189>/Subsys_VOPM_DrvSwi_flg' */
  /* Switch: '<S194>/Switch4' incorporates:
   *  Constant: '<S194>/sat3'
   */
  if (KOPM_DrvSwi_flg_ovrdflg)
  {
    /* Switch: '<S194>/Switch4' incorporates:
     *  Constant: '<S194>/sat4'
     */
    VOPM_DrvSwi_flg = KOPM_DrvSwi_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S194>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S194>/Data Type Conversion1'
     */
    VOPM_DrvSwi_flg = (Rte_IrvIRead_Runbl_OpmCanTx_10ms_Vcu2OpmEPT_outputs())
                          ->VIPC_DrvSw_flg;
  }

  /* End of Switch: '<S194>/Switch4' */
  /* End of Outputs for SubSystem: '<S189>/Subsys_VOPM_DrvSwi_flg' */

  /* Outputs for Atomic SubSystem: '<S189>/Subsys_VOPM_Zdznswi_flg' */
  /* Switch: '<S196>/Switch4' incorporates:
   *  Constant: '<S196>/sat3'
   */
  if (KOPM_Zdznswi_flg_ovrdflg)
  {
    /* Switch: '<S196>/Switch4' incorporates:
     *  Constant: '<S196>/sat4'
     */
    VOPM_Zdznswi_flg = KOPM_Zdznswi_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S196>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S196>/Data Type Conversion1'
     */
    VOPM_Zdznswi_flg = (Rte_IrvIRead_Runbl_OpmCanTx_10ms_Vcu2OpmEPT_outputs())
                           ->VVTM_MotDampngEnbl_flg;
  }

  /* End of Switch: '<S196>/Switch4' */
  /* End of Outputs for SubSystem: '<S189>/Subsys_VOPM_Zdznswi_flg' */

  /* Outputs for Atomic SubSystem: '<S189>/Subsys_VOPM_DrvPed_pct' */
  /* Switch: '<S193>/Switch4' incorporates:
   *  Constant: '<S193>/sat3'
   */
  if (KOPM_DrvPed_pct_ovrdflg)
  {
    /* MinMax: '<S193>/MinMax' incorporates:
     *  Constant: '<S193>/sat4'
     *  Product: '<S180>/Product1'
     */
    VOPM_VCUMasterCylinderPreReq_Bar = KOPM_DrvPed_pct_ovrdval;
  }
  else
  {
    /* MinMax: '<S193>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S193>/Data Type Conversion1'
     *  Product: '<S180>/Product1'
     */
    VOPM_VCUMasterCylinderPreReq_Bar =
        (Rte_IrvIRead_Runbl_OpmCanTx_10ms_Vcu2OpmEPT_outputs())
            ->VIPC_AccPedPstn_pct;
  }

  /* End of Switch: '<S193>/Switch4' */

  /* MinMax: '<S193>/MinMax' incorporates:
   *  Constant: '<S193>/sat6'
   */
  if (VOPM_VCUMasterCylinderPreReq_Bar > KOPM_DrvPedHi_pct)
  {
    VOPM_VCUMasterCylinderPreReq_Bar = KOPM_DrvPedHi_pct;
  }

  /* MinMax: '<S193>/MinMax1' incorporates:
   *  Constant: '<S193>/sat7'
   */
  if (VOPM_VCUMasterCylinderPreReq_Bar >= KOPM_DrvPedLo_pct)
  {
    /* MinMax: '<S193>/MinMax1' */
    VOPM_DrvPed_pct = VOPM_VCUMasterCylinderPreReq_Bar;
  }
  else
  {
    /* MinMax: '<S193>/MinMax1' */
    VOPM_DrvPed_pct = KOPM_DrvPedLo_pct;
  }

  /* End of MinMax: '<S193>/MinMax1' */
  /* End of Outputs for SubSystem: '<S189>/Subsys_VOPM_DrvPed_pct' */

  /* Outputs for Atomic SubSystem: '<S189>/Subsys_VOPM_MotDmpgLmt_Nm' */
  /* Switch: '<S195>/Switch4' incorporates:
   *  Constant: '<S195>/sat3'
   */
  if (KOPM_MotDmpgLmt_Nm_ovrdflg)
  {
    /* MinMax: '<S193>/MinMax' incorporates:
     *  Constant: '<S195>/sat4'
     *  Product: '<S180>/Product1'
     */
    VOPM_VCUMasterCylinderPreReq_Bar = KOPM_MotDmpgLmt_Nm_ovrdval;
  }
  else
  {
    /* MinMax: '<S193>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S195>/Data Type Conversion1'
     *  Product: '<S180>/Product1'
     */
    VOPM_VCUMasterCylinderPreReq_Bar =
        (Rte_IrvIRead_Runbl_OpmCanTx_10ms_Vcu2OpmEPT_outputs())
            ->VVTM_MotDampngLmt_Nm;
  }

  /* End of Switch: '<S195>/Switch4' */

  /* MinMax: '<S195>/MinMax' incorporates:
   *  Constant: '<S195>/sat6'
   */
  if (VOPM_VCUMasterCylinderPreReq_Bar > KOPM_MotDmpgLmtHi_Nm)
  {
    /* MinMax: '<S193>/MinMax' */
    VOPM_VCUMasterCylinderPreReq_Bar = KOPM_MotDmpgLmtHi_Nm;
  }

  /* End of MinMax: '<S195>/MinMax' */

  /* MinMax: '<S195>/MinMax1' incorporates:
   *  Constant: '<S195>/sat7'
   */
  if (VOPM_VCUMasterCylinderPreReq_Bar >= KOPM_MotDmpgLmtLo_Nm)
  {
    /* MinMax: '<S195>/MinMax1' */
    VOPM_MotDmpgLmt_Nm = VOPM_VCUMasterCylinderPreReq_Bar;
  }
  else
  {
    /* MinMax: '<S195>/MinMax1' */
    VOPM_MotDmpgLmt_Nm = KOPM_MotDmpgLmtLo_Nm;
  }

  /* End of MinMax: '<S195>/MinMax1' */
  /* End of Outputs for SubSystem: '<S189>/Subsys_VOPM_MotDmpgLmt_Nm' */

  /* Outputs for Atomic SubSystem: '<S189>/Subsys_VOPM_AppSoftNumb_nu' */
  /* Switch: '<S191>/Switch4' incorporates:
   *  Constant: '<S191>/sat3'
   */
  if (KOPM_AppSoftNumb_nu_ovrdflg)
  {
    /* MinMax: '<S191>/MinMax' incorporates:
     *  Constant: '<S191>/sat4'
     *  MinMax: '<S164>/MinMax'
     */
    VOPM_BrkPwrRecupActlWhlTqSts_enum = KOPM_AppSoftNumb_nu_ovrdval;
  }
  else
  {
    /* MinMax: '<S191>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S191>/Data Type Conversion1'
     *  MinMax: '<S164>/MinMax'
     */
    VOPM_BrkPwrRecupActlWhlTqSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_10ms_Vcu2OpmEPT_outputs())
            ->VVCU_SoftWareVer_cnt;
  }

  /* End of Switch: '<S191>/Switch4' */

  /* MinMax: '<S191>/MinMax' incorporates:
   *  Constant: '<S191>/sat6'
   */
  if (VOPM_BrkPwrRecupActlWhlTqSts_enum > KOPM_AppSoftNumbHi_nu)
  {
    VOPM_BrkPwrRecupActlWhlTqSts_enum = KOPM_AppSoftNumbHi_nu;
  }

  /* MinMax: '<S191>/MinMax1' incorporates:
   *  Constant: '<S191>/sat7'
   */
  if (VOPM_BrkPwrRecupActlWhlTqSts_enum >= KOPM_AppSoftNumbLo_nu)
  {
    /* MinMax: '<S191>/MinMax1' */
    VOPM_AppSoftNumb_nu = VOPM_BrkPwrRecupActlWhlTqSts_enum;
  }
  else
  {
    /* MinMax: '<S191>/MinMax1' */
    VOPM_AppSoftNumb_nu = KOPM_AppSoftNumbLo_nu;
  }

  /* End of MinMax: '<S191>/MinMax1' */
  /* End of Outputs for SubSystem: '<S189>/Subsys_VOPM_AppSoftNumb_nu' */

  /* BusCreator: '<S189>/BusCreator' incorporates:
   *  Switch: '<S192>/Switch4'
   *  Switch: '<S194>/Switch4'
   *  Switch: '<S196>/Switch4'
   */
  AppSwcOpm_ARID_DEF.VCU_0_Value_EPT_m.VCU_0_BraSwi = VOPM_BraSwi_flg;
  AppSwcOpm_ARID_DEF.VCU_0_Value_EPT_m.VCU_0_DrvSwi = VOPM_DrvSwi_flg;
  AppSwcOpm_ARID_DEF.VCU_0_Value_EPT_m.VCU_0_Zdznswi = VOPM_Zdznswi_flg;

  /* DataTypeConversion: '<S189>/DataTypeConversion3' incorporates:
   *  Constant: '<S197>/Constant1'
   *  Product: '<S197>/Product1'
   *  Sum: '<S197>/Add'
   */
  tmp = VOPM_DrvPed_pct * 10.0F;
  if (tmp < 65536.0F)
  {
    if (tmp >= 0.0F)
    {
      /* BusCreator: '<S189>/BusCreator' */
      AppSwcOpm_ARID_DEF.VCU_0_Value_EPT_m.VCU_0_DrvPed = (uint16)tmp;
    }
    else
    {
      /* BusCreator: '<S189>/BusCreator' */
      AppSwcOpm_ARID_DEF.VCU_0_Value_EPT_m.VCU_0_DrvPed = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S189>/BusCreator' */
    AppSwcOpm_ARID_DEF.VCU_0_Value_EPT_m.VCU_0_DrvPed = MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<S189>/DataTypeConversion3' */

  /* DataTypeConversion: '<S189>/DataTypeConversion4' incorporates:
   *  Constant: '<S198>/Constant1'
   *  Product: '<S198>/Product1'
   *  Sum: '<S198>/Add'
   */
  tmp = VOPM_MotDmpgLmt_Nm * 10.0F;
  if (tmp < 256.0F)
  {
    if (tmp >= 0.0F)
    {
      /* BusCreator: '<S189>/BusCreator' */
      AppSwcOpm_ARID_DEF.VCU_0_Value_EPT_m.VCU_MotDampngLmt = (uint8)tmp;
    }
    else
    {
      /* BusCreator: '<S189>/BusCreator' */
      AppSwcOpm_ARID_DEF.VCU_0_Value_EPT_m.VCU_MotDampngLmt = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S189>/BusCreator' */
    AppSwcOpm_ARID_DEF.VCU_0_Value_EPT_m.VCU_MotDampngLmt = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S189>/DataTypeConversion4' */

  /* BusCreator: '<S189>/BusCreator' */
  AppSwcOpm_ARID_DEF.VCU_0_Value_EPT_m.VCU_AppSoftNumb = VOPM_AppSoftNumb_nu;

  /* Outputs for Atomic SubSystem: '<S190>/Subsys_VOPM_MotModeReq_enum' */
  /* Switch: '<S203>/Switch4' incorporates:
   *  Constant: '<S203>/sat3'
   */
  if (KOPM_MotModeReq_enum_ovrdflg)
  {
    /* MinMax: '<S191>/MinMax' incorporates:
     *  Constant: '<S203>/sat4'
     *  DataTypeConversion: '<S203>/Data Type Conversion3'
     *  MinMax: '<S164>/MinMax'
     */
    VOPM_BrkPwrRecupActlWhlTqSts_enum = KOPM_MotModeReq_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S191>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S203>/Data Type Conversion1'
     *  MinMax: '<S164>/MinMax'
     */
    VOPM_BrkPwrRecupActlWhlTqSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_10ms_Vcu2OpmEPT_outputs())
            ->VVTM_MotorModeReq_enum;
  }

  /* End of Switch: '<S203>/Switch4' */

  /* MinMax: '<S203>/MinMax' incorporates:
   *  Constant: '<S203>/sat6'
   */
  if (VOPM_BrkPwrRecupActlWhlTqSts_enum > KOPM_MotModeReqHi_enum)
  {
    /* MinMax: '<S191>/MinMax' */
    VOPM_BrkPwrRecupActlWhlTqSts_enum = KOPM_MotModeReqHi_enum;
  }

  /* End of MinMax: '<S203>/MinMax' */

  /* MinMax: '<S203>/MinMax1' incorporates:
   *  Constant: '<S203>/sat7'
   */
  if (VOPM_BrkPwrRecupActlWhlTqSts_enum >= KOPM_MotModeReqLo_enum)
  {
    /* DataTypeConversion: '<S203>/Data Type Conversion2' */
    VOPM_MotModeReq_enum = VOPM_BrkPwrRecupActlWhlTqSts_enum;
  }
  else
  {
    /* DataTypeConversion: '<S203>/Data Type Conversion2' */
    VOPM_MotModeReq_enum = KOPM_MotModeReqLo_enum;
  }

  /* End of MinMax: '<S203>/MinMax1' */
  /* End of Outputs for SubSystem: '<S190>/Subsys_VOPM_MotModeReq_enum' */

  /* Outputs for Atomic SubSystem: '<S190>/Subsys_VOPM_EnaDisChg_flg' */
  /* Switch: '<S200>/Switch4' incorporates:
   *  Constant: '<S200>/sat3'
   */
  if (KOPM_EnaDisChg_flg_ovrdflg)
  {
    /* Switch: '<S200>/Switch4' incorporates:
     *  Constant: '<S200>/sat4'
     */
    VOPM_EnaDisChg_flg = KOPM_EnaDisChg_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S200>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S200>/Data Type Conversion1'
     */
    VOPM_EnaDisChg_flg = (Rte_IrvIRead_Runbl_OpmCanTx_10ms_Vcu2OpmEPT_outputs())->VHVM_EnaDisChg_flg;
  }

  /* End of Switch: '<S200>/Switch4' */
  /* End of Outputs for SubSystem: '<S190>/Subsys_VOPM_EnaDisChg_flg' */

  /* Outputs for Atomic SubSystem: '<S190>/Subsys_VOPM_MotDirReq_enum' */
  /* Switch: '<S202>/Switch4' incorporates:
   *  Constant: '<S202>/sat3'
   */
  if (KOPM_MotDirReq_enum_ovrdflg)
  {
    /* MinMax: '<S191>/MinMax' incorporates:
     *  Constant: '<S202>/sat4'
     *  DataTypeConversion: '<S202>/Data Type Conversion3'
     *  MinMax: '<S164>/MinMax'
     */
    VOPM_BrkPwrRecupActlWhlTqSts_enum = KOPM_MotDirReq_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S191>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S202>/Data Type Conversion1'
     *  MinMax: '<S164>/MinMax'
     */
    VOPM_BrkPwrRecupActlWhlTqSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_10ms_Vcu2OpmEPT_outputs())
            ->VVTM_MotorDirReq_enum;
  }

  /* End of Switch: '<S202>/Switch4' */

  /* MinMax: '<S202>/MinMax' incorporates:
   *  Constant: '<S202>/sat6'
   */
  if (VOPM_BrkPwrRecupActlWhlTqSts_enum > KOPM_MotDirReqHi_enum)
  {
    /* MinMax: '<S191>/MinMax' */
    VOPM_BrkPwrRecupActlWhlTqSts_enum = KOPM_MotDirReqHi_enum;
  }

  /* End of MinMax: '<S202>/MinMax' */

  /* MinMax: '<S202>/MinMax1' incorporates:
   *  Constant: '<S202>/sat7'
   */
  if (VOPM_BrkPwrRecupActlWhlTqSts_enum >= KOPM_MotDirReqLo_enum)
  {
    /* DataTypeConversion: '<S202>/Data Type Conversion2' */
    VOPM_MotDirReq_enum = VOPM_BrkPwrRecupActlWhlTqSts_enum;
  }
  else
  {
    /* DataTypeConversion: '<S202>/Data Type Conversion2' */
    VOPM_MotDirReq_enum = KOPM_MotDirReqLo_enum;
  }

  /* End of MinMax: '<S202>/MinMax1' */
  /* End of Outputs for SubSystem: '<S190>/Subsys_VOPM_MotDirReq_enum' */

  /* DataTypeConversion: '<S190>/DataTypeConversion2' incorporates:
   *  DataTypeConversion: '<S202>/Data Type Conversion2'
   */
  AppSwcOpm_ARID_DEF.VCU_1_InvCmd_EPT_g.VCU_1_MotDirReq = VOPM_MotDirReq_enum;

  /* Outputs for Atomic SubSystem: '<S190>/Subsys_VOPM_MotTorqReq_Nm' */
  /* Switch: '<S205>/Switch4' incorporates:
   *  Constant: '<S205>/sat3'
   */
  if (KOPM_MotTorqReq_Nm_ovrdflg)
  {
    /* MinMax: '<S193>/MinMax' incorporates:
     *  Constant: '<S205>/sat4'
     *  Product: '<S180>/Product1'
     */
    VOPM_VCUMasterCylinderPreReq_Bar = KOPM_MotTorqReq_Nm_ovrdval;
  }
  else
  {
    /* MinMax: '<S193>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S205>/Data Type Conversion1'
     *  Product: '<S180>/Product1'
     */
    VOPM_VCUMasterCylinderPreReq_Bar =
        (Rte_IrvIRead_Runbl_OpmCanTx_10ms_Vcu2OpmEPT_outputs())
            ->VVTM_MotorTqReq_Nm;
  }

  /* End of Switch: '<S205>/Switch4' */

  /* MinMax: '<S205>/MinMax' incorporates:
   *  Constant: '<S205>/sat6'
   */
  if (VOPM_VCUMasterCylinderPreReq_Bar > KOPM_MotTorqReqHi_Nm)
  {
    /* MinMax: '<S193>/MinMax' */
    VOPM_VCUMasterCylinderPreReq_Bar = KOPM_MotTorqReqHi_Nm;
  }

  /* End of MinMax: '<S205>/MinMax' */

  /* MinMax: '<S205>/MinMax1' incorporates:
   *  Constant: '<S205>/sat7'
   */
  if (VOPM_VCUMasterCylinderPreReq_Bar >= KOPM_MotTorqReqLo_Nm)
  {
    /* MinMax: '<S205>/MinMax1' */
    VOPM_MotTorqReq_Nm = VOPM_VCUMasterCylinderPreReq_Bar;
  }
  else
  {
    /* MinMax: '<S205>/MinMax1' */
    VOPM_MotTorqReq_Nm = KOPM_MotTorqReqLo_Nm;
  }

  /* End of MinMax: '<S205>/MinMax1' */
  /* End of Outputs for SubSystem: '<S190>/Subsys_VOPM_MotTorqReq_Nm' */

  /* Outputs for Atomic SubSystem: '<S190>/Subsys_VOPM_EnaInvRun_flg' */
  /* Switch: '<S201>/Switch4' incorporates:
   *  Constant: '<S201>/sat3'
   */
  if (KOPM_EnaInvRun_flg_ovrdflg)
  {
    /* Switch: '<S201>/Switch4' incorporates:
     *  Constant: '<S201>/sat4'
     */
    VOPM_EnaInvRun_flg = KOPM_EnaInvRun_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S201>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S201>/Data Type Conversion1'
     */
    VOPM_EnaInvRun_flg = (Rte_IrvIRead_Runbl_OpmCanTx_10ms_Vcu2OpmEPT_outputs())->VGSM_INVRunEnbl_flg;
  }

  /* End of Switch: '<S201>/Switch4' */
  /* End of Outputs for SubSystem: '<S190>/Subsys_VOPM_EnaInvRun_flg' */

  /* Outputs for Atomic SubSystem: '<S190>/Subsys_VOPM_EmgcySdn_flg' */
  /* Switch: '<S199>/Switch4' incorporates:
   *  Constant: '<S199>/sat3'
   */
  if (KOPM_EmgcySdn_flg_ovrdflg)
  {
    /* Switch: '<S199>/Switch4' incorporates:
     *  Constant: '<S199>/sat4'
     */
    VOPM_EmgcySdn_flg = KOPM_EmgcySdn_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S199>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S199>/Data Type Conversion1'
     */
    VOPM_EmgcySdn_flg = (Rte_IrvIRead_Runbl_OpmCanTx_10ms_Vcu2OpmEPT_outputs())->VHVM_EmgcySdn_flg;
  }

  /* End of Switch: '<S199>/Switch4' */
  /* End of Outputs for SubSystem: '<S190>/Subsys_VOPM_EmgcySdn_flg' */

  /* Outputs for Atomic SubSystem: '<S190>/Subsys_VOPM_MotSpdReq_rpm' */
  /* Switch: '<S204>/Switch4' incorporates:
   *  Constant: '<S204>/sat3'
   */
  if (KOPM_MotSpdReq_rpm_ovrdflg)
  {
    /* MinMax: '<S193>/MinMax' incorporates:
     *  Constant: '<S204>/sat4'
     *  Product: '<S180>/Product1'
     */
    VOPM_VCUMasterCylinderPreReq_Bar = KOPM_MotSpdReq_rpm_ovrdval;
  }
  else
  {
    /* MinMax: '<S193>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S204>/Data Type Conversion1'
     *  Product: '<S180>/Product1'
     */
    VOPM_VCUMasterCylinderPreReq_Bar = (float32)(Rte_IrvIRead_Runbl_OpmCanTx_10ms_Vcu2OpmEPT_outputs())
                                           ->VVTM_MotorSpdReq_rpm;
  }

  /* End of Switch: '<S204>/Switch4' */

  /* MinMax: '<S204>/MinMax' incorporates:
   *  Constant: '<S204>/sat6'
   */
  if (VOPM_VCUMasterCylinderPreReq_Bar > KOPM_MotSpdReqHi_rpm)
  {
    /* MinMax: '<S193>/MinMax' */
    VOPM_VCUMasterCylinderPreReq_Bar = KOPM_MotSpdReqHi_rpm;
  }

  /* End of MinMax: '<S204>/MinMax' */

  /* MinMax: '<S204>/MinMax1' incorporates:
   *  Constant: '<S204>/sat7'
   */
  if (VOPM_VCUMasterCylinderPreReq_Bar >= KOPM_MotSpdReqLo_rpm)
  {
    /* MinMax: '<S204>/MinMax1' */
    VOPM_MotSpdReq_rpm = VOPM_VCUMasterCylinderPreReq_Bar;
  }
  else
  {
    /* MinMax: '<S204>/MinMax1' */
    VOPM_MotSpdReq_rpm = KOPM_MotSpdReqLo_rpm;
  }

  /* End of MinMax: '<S204>/MinMax1' */
  /* End of Outputs for SubSystem: '<S190>/Subsys_VOPM_MotSpdReq_rpm' */

  /* Outputs for Atomic SubSystem: '<S190>/Subsys_VOPM_VehTrgtGearPos_enum' */
  /* Switch: '<S206>/Switch4' incorporates:
   *  Constant: '<S206>/sat3'
   */
  if (KOPM_VehTrgtGearPos_enum_ovrdflg)
  {
    /* MinMax: '<S191>/MinMax' incorporates:
     *  Constant: '<S206>/sat4'
     *  DataTypeConversion: '<S206>/Data Type Conversion3'
     *  MinMax: '<S164>/MinMax'
     */
    VOPM_BrkPwrRecupActlWhlTqSts_enum = KOPM_VehTrgtGearPos_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S191>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S206>/Data Type Conversion1'
     *  MinMax: '<S164>/MinMax'
     */
    VOPM_BrkPwrRecupActlWhlTqSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_10ms_Vcu2OpmEPT_outputs())
            ->VGSM_VehTgtGrReq_enum;
  }

  /* End of Switch: '<S206>/Switch4' */

  /* MinMax: '<S206>/MinMax' incorporates:
   *  Constant: '<S206>/sat6'
   */
  if (VOPM_BrkPwrRecupActlWhlTqSts_enum > KOPM_VehTrgtGearPosHi_enum)
  {
    /* MinMax: '<S191>/MinMax' */
    VOPM_BrkPwrRecupActlWhlTqSts_enum = KOPM_VehTrgtGearPosHi_enum;
  }

  /* End of MinMax: '<S206>/MinMax' */

  /* MinMax: '<S206>/MinMax1' incorporates:
   *  Constant: '<S206>/sat7'
   */
  if (VOPM_BrkPwrRecupActlWhlTqSts_enum >= KOPM_VehTrgtGearPosLo_enum)
  {
    /* DataTypeConversion: '<S206>/Data Type Conversion2' */
    VOPM_VehTrgtGearPos_enum = VOPM_BrkPwrRecupActlWhlTqSts_enum;
  }
  else
  {
    /* DataTypeConversion: '<S206>/Data Type Conversion2' */
    VOPM_VehTrgtGearPos_enum = KOPM_VehTrgtGearPosLo_enum;
  }

  /* End of MinMax: '<S206>/MinMax1' */
  /* End of Outputs for SubSystem: '<S190>/Subsys_VOPM_VehTrgtGearPos_enum' */

  /* BusCreator: '<S190>/BusCreator' incorporates:
   *  DataTypeConversion: '<S190>/DataTypeConversion'
   *  DataTypeConversion: '<S203>/Data Type Conversion2'
   *  Switch: '<S200>/Switch4'
   */
  AppSwcOpm_ARID_DEF.VCU_1_InvCmd_EPT_g.VCU_1_MotModeReq = VOPM_MotModeReq_enum;
  AppSwcOpm_ARID_DEF.VCU_1_InvCmd_EPT_g.VCU_1_EnaDisChg = VOPM_EnaDisChg_flg;

  /* DataTypeConversion: '<S190>/DataTypeConversion3' incorporates:
   *  Constant: '<S207>/Constant'
   *  Constant: '<S207>/Constant1'
   *  Product: '<S207>/Product1'
   *  Sum: '<S207>/Add'
   */
  tmp = (VOPM_MotTorqReq_Nm - -819.2F) * 10.0F;
  if (tmp < 65536.0F)
  {
    if (tmp >= 0.0F)
    {
      /* BusCreator: '<S190>/BusCreator' */
      AppSwcOpm_ARID_DEF.VCU_1_InvCmd_EPT_g.VCU_1_MotTorqueReq = (uint16)tmp;
    }
    else
    {
      /* BusCreator: '<S190>/BusCreator' */
      AppSwcOpm_ARID_DEF.VCU_1_InvCmd_EPT_g.VCU_1_MotTorqueReq = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S190>/BusCreator' */
    AppSwcOpm_ARID_DEF.VCU_1_InvCmd_EPT_g.VCU_1_MotTorqueReq = MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<S190>/DataTypeConversion3' */

  /* BusCreator: '<S190>/BusCreator' incorporates:
   *  Constant: '<S190>/Constant'
   *  Switch: '<S199>/Switch4'
   *  Switch: '<S201>/Switch4'
   */
  AppSwcOpm_ARID_DEF.VCU_1_InvCmd_EPT_g.VCU_1_EnaInvRun = VOPM_EnaInvRun_flg;
  AppSwcOpm_ARID_DEF.VCU_1_InvCmd_EPT_g.VCU_1_EmShutDown = VOPM_EmgcySdn_flg;
  AppSwcOpm_ARID_DEF.VCU_1_InvCmd_EPT_g.VCU_ShiftMotorParkReq = 0U;

  /* DataTypeConversion: '<S190>/DataTypeConversion7' incorporates:
   *  Constant: '<S208>/Constant'
   *  Sum: '<S208>/Add'
   */
  if (VOPM_MotSpdReq_rpm - -16384.0F < 65536.0F)
  {
    if (VOPM_MotSpdReq_rpm - -16384.0F >= 0.0F)
    {
      /* BusCreator: '<S190>/BusCreator' */
      AppSwcOpm_ARID_DEF.VCU_1_InvCmd_EPT_g.VCU_1_MotSpdReq = (uint16)(VOPM_MotSpdReq_rpm - -16384.0F);
    }
    else
    {
      /* BusCreator: '<S190>/BusCreator' */
      AppSwcOpm_ARID_DEF.VCU_1_InvCmd_EPT_g.VCU_1_MotSpdReq = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S190>/BusCreator' */
    AppSwcOpm_ARID_DEF.VCU_1_InvCmd_EPT_g.VCU_1_MotSpdReq = MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<S190>/DataTypeConversion7' */

  /* BusCreator: '<S190>/BusCreator' incorporates:
   *  Constant: '<S190>/Constant1'
   *  DataTypeConversion: '<S190>/DataTypeConversion9'
   *  DataTypeConversion: '<S206>/Data Type Conversion2'
   */
  AppSwcOpm_ARID_DEF.VCU_1_InvCmd_EPT_g.VCU_INVSkid = false;
  AppSwcOpm_ARID_DEF.VCU_1_InvCmd_EPT_g.VCU_VhclTrgtGearPos =
      VOPM_VehTrgtGearPos_enum;

  /* Outputs for Atomic SubSystem: '<S156>/Subsys_VOPM_ActWhlTqVld_flg' */
  /* Switch: '<S157>/Switch4' incorporates:
   *  Constant: '<S157>/sat3'
   */
  if (KOPM_ActWhlTqVld_flg_ovrdflg)
  {
    /* Switch: '<S157>/Switch4' incorporates:
     *  Constant: '<S157>/sat4'
     */
    VOPM_ActWhlTqVld_flg = KOPM_ActWhlTqVld_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S157>/Switch4' incorporates:
     *  Inport: '<Root>/IPM_INV_1_Value_EPT'
     */
    VOPM_ActWhlTqVld_flg =
        (Rte_IRead_Runbl_OpmCanTx_10ms_IPM_INV_1_Value_EPT_IPM_INV_1_Value_EPT())->VIPM_INV1ActTorqVld_flg;
  }

  /* End of Switch: '<S157>/Switch4' */
  /* End of Outputs for SubSystem: '<S156>/Subsys_VOPM_ActWhlTqVld_flg' */

  /* Outputs for Atomic SubSystem: '<S156>/Subsys_VOPM_ActWhlTq_Nm' */
  /* Switch: '<S158>/Switch4' incorporates:
   *  Constant: '<S158>/sat3'
   */
  if (KOPM_ActWhlTq_Nm_ovrdflg)
  {
    /* MinMax: '<S193>/MinMax' incorporates:
     *  Constant: '<S158>/sat4'
     *  Product: '<S180>/Product1'
     */
    VOPM_VCUMasterCylinderPreReq_Bar = KOPM_ActWhlTq_Nm_ovrdval;
  }
  else
  {
    /* MinMax: '<S193>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S158>/Data Type Conversion1'
     *  Product: '<S180>/Product1'
     */
    VOPM_VCUMasterCylinderPreReq_Bar =
        (Rte_IrvIRead_Runbl_OpmCanTx_10ms_Vcu2OpmCHA_outputs())->VVTM_ActWhlTq_Nm;
  }

  /* End of Switch: '<S158>/Switch4' */

  /* MinMax: '<S158>/MinMax' incorporates:
   *  Constant: '<S158>/sat6'
   */
  if (VOPM_VCUMasterCylinderPreReq_Bar > KOPM_ActWhlTqHi_Nm)
  {
    /* MinMax: '<S193>/MinMax' */
    VOPM_VCUMasterCylinderPreReq_Bar = KOPM_ActWhlTqHi_Nm;
  }

  /* End of MinMax: '<S158>/MinMax' */

  /* MinMax: '<S158>/MinMax1' incorporates:
   *  Constant: '<S158>/sat7'
   */
  if (VOPM_VCUMasterCylinderPreReq_Bar >= KOPM_ActWhlTqLo_Nm)
  {
    /* MinMax: '<S158>/MinMax1' */
    VOPM_ActWhlTq_Nm = VOPM_VCUMasterCylinderPreReq_Bar;
  }
  else
  {
    /* MinMax: '<S158>/MinMax1' */
    VOPM_ActWhlTq_Nm = KOPM_ActWhlTqLo_Nm;
  }

  /* End of MinMax: '<S158>/MinMax1' */
  /* End of Outputs for SubSystem: '<S156>/Subsys_VOPM_ActWhlTq_Nm' */

  /* Outputs for Atomic SubSystem: '<S156>/Subsys_VOPM_DrvReqWhlTqVld_flg' */
  /* Switch: '<S168>/Switch4' incorporates:
   *  Constant: '<S168>/sat3'
   */
  if (KOPM_DrvReqWhlTqVld_flg_ovrdflg)
  {
    /* Switch: '<S168>/Switch4' incorporates:
     *  Constant: '<S168>/sat4'
     */
    VOPM_DrvReqWhlTqVld_flg = KOPM_DrvReqWhlTqVld_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S168>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S168>/Data Type Conversion1'
     */
    VOPM_DrvReqWhlTqVld_flg =
        (Rte_IrvIRead_Runbl_OpmCanTx_10ms_Vcu2OpmCHA_outputs())
            ->VVTM_DrvReqMotorTorqV_flg;
  }

  /* End of Switch: '<S168>/Switch4' */
  /* End of Outputs for SubSystem: '<S156>/Subsys_VOPM_DrvReqWhlTqVld_flg' */

  /* Outputs for Atomic SubSystem: '<S156>/Subsys_VOPM_DrvReqWhlTq_Nm' */
  /* Switch: '<S169>/Switch4' incorporates:
   *  Constant: '<S169>/sat3'
   */
  if (KOPM_DrvReqWhlTq_Nm_ovrdflg)
  {
    /* MinMax: '<S193>/MinMax' incorporates:
     *  Constant: '<S169>/sat4'
     *  Product: '<S180>/Product1'
     */
    VOPM_VCUMasterCylinderPreReq_Bar = KOPM_DrvReqWhlTq_Nm_ovrdval;
  }
  else
  {
    /* MinMax: '<S193>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S169>/Data Type Conversion1'
     *  Product: '<S180>/Product1'
     */
    VOPM_VCUMasterCylinderPreReq_Bar =
        (Rte_IrvIRead_Runbl_OpmCanTx_10ms_Vcu2OpmCHA_outputs())
            ->VVTM_DrvReqWhlTq_Nm;
  }

  /* End of Switch: '<S169>/Switch4' */

  /* MinMax: '<S169>/MinMax' incorporates:
   *  Constant: '<S169>/sat6'
   */
  if (VOPM_VCUMasterCylinderPreReq_Bar > KOPM_DrvReqWhlTqHi_Nm)
  {
    /* MinMax: '<S193>/MinMax' */
    VOPM_VCUMasterCylinderPreReq_Bar = KOPM_DrvReqWhlTqHi_Nm;
  }

  /* End of MinMax: '<S169>/MinMax' */

  /* MinMax: '<S169>/MinMax1' incorporates:
   *  Constant: '<S169>/sat7'
   */
  if (VOPM_VCUMasterCylinderPreReq_Bar >= KOPM_DrvReqWhlTqLo_Nm)
  {
    /* MinMax: '<S169>/MinMax1' */
    VOPM_DrvReqWhlTq_Nm = VOPM_VCUMasterCylinderPreReq_Bar;
  }
  else
  {
    /* MinMax: '<S169>/MinMax1' */
    VOPM_DrvReqWhlTq_Nm = KOPM_DrvReqWhlTqLo_Nm;
  }

  /* End of MinMax: '<S169>/MinMax1' */
  /* End of Outputs for SubSystem: '<S156>/Subsys_VOPM_DrvReqWhlTq_Nm' */

  /* Outputs for Atomic SubSystem: '<S156>/Subsys_VOPM_DrvWhlTqAllwdMax_Nm' */
  /* Switch: '<S170>/Switch4' incorporates:
   *  Constant: '<S170>/sat3'
   */
  if (KOPM_DrvWhlTqAllwdMax_Nm_ovrdflg)
  {
    /* MinMax: '<S193>/MinMax' incorporates:
     *  Constant: '<S170>/sat4'
     *  Product: '<S180>/Product1'
     */
    VOPM_VCUMasterCylinderPreReq_Bar = KOPM_DrvWhlTqAllwdMax_Nm_ovrdval;
  }
  else
  {
    /* MinMax: '<S193>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S170>/Data Type Conversion1'
     *  Product: '<S180>/Product1'
     */
    VOPM_VCUMasterCylinderPreReq_Bar =
        (Rte_IrvIRead_Runbl_OpmCanTx_10ms_Vcu2OpmCHA_outputs())
            ->VVTM_WhlDrvMaxTq_Nm;
  }

  /* End of Switch: '<S170>/Switch4' */

  /* MinMax: '<S170>/MinMax' incorporates:
   *  Constant: '<S170>/sat6'
   */
  if (VOPM_VCUMasterCylinderPreReq_Bar > KOPM_DrvWhlTqAllwdMaxHi_Nm)
  {
    /* MinMax: '<S193>/MinMax' */
    VOPM_VCUMasterCylinderPreReq_Bar = KOPM_DrvWhlTqAllwdMaxHi_Nm;
  }

  /* End of MinMax: '<S170>/MinMax' */

  /* MinMax: '<S170>/MinMax1' incorporates:
   *  Constant: '<S170>/sat7'
   */
  if (VOPM_VCUMasterCylinderPreReq_Bar >= KOPM_DrvWhlTqAllwdMaxLo_Nm)
  {
    /* MinMax: '<S170>/MinMax1' */
    VOPM_DrvWhlTqAllwdMax_Nm = VOPM_VCUMasterCylinderPreReq_Bar;
  }
  else
  {
    /* MinMax: '<S170>/MinMax1' */
    VOPM_DrvWhlTqAllwdMax_Nm = KOPM_DrvWhlTqAllwdMaxLo_Nm;
  }

  /* End of MinMax: '<S170>/MinMax1' */
  /* End of Outputs for SubSystem: '<S156>/Subsys_VOPM_DrvWhlTqAllwdMax_Nm' */

  /* DataTypeConversion: '<S156>/DataTypeConversion4' */
  if (VOPM_DrvWhlTqAllwdMax_Nm < 65536.0F)
  {
    if (VOPM_DrvWhlTqAllwdMax_Nm >= 0.0F)
    {
      AppSwcOpm_ARID_DEF.VCU_10_Torque_CHA_j.VCU_DrvWhlTqAllwdMax = (uint16)
          VOPM_DrvWhlTqAllwdMax_Nm;
    }
    else
    {
      AppSwcOpm_ARID_DEF.VCU_10_Torque_CHA_j.VCU_DrvWhlTqAllwdMax = 0U;
    }
  }
  else
  {
    AppSwcOpm_ARID_DEF.VCU_10_Torque_CHA_j.VCU_DrvWhlTqAllwdMax = MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<S156>/DataTypeConversion4' */

  /* Outputs for Atomic SubSystem: '<S156>/Subsys_VOPM_PwrRecupActlWhlTqSts_enum' */
  /* Switch: '<S172>/Switch4' incorporates:
   *  Constant: '<S172>/sat3'
   */
  if (KOPM_PwrRecupActlWhlTqSts_enum_ovrdflg)
  {
    /* MinMax: '<S191>/MinMax' incorporates:
     *  Constant: '<S172>/sat4'
     *  MinMax: '<S164>/MinMax'
     */
    VOPM_BrkPwrRecupActlWhlTqSts_enum = KOPM_PwrRecupActlWhlTqSts_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S191>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S172>/Data Type Conversion1'
     *  MinMax: '<S164>/MinMax'
     */
    VOPM_BrkPwrRecupActlWhlTqSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_10ms_Vcu2OpmCHA_outputs())
            ->VVTM_PwrRecActWhlTorqSta_enum;
  }

  /* End of Switch: '<S172>/Switch4' */

  /* MinMax: '<S172>/MinMax' incorporates:
   *  Constant: '<S172>/sat6'
   */
  if (VOPM_BrkPwrRecupActlWhlTqSts_enum > KOPM_PwrRecupActlWhlTqStsHi_enum)
  {
    /* MinMax: '<S191>/MinMax' */
    VOPM_BrkPwrRecupActlWhlTqSts_enum = KOPM_PwrRecupActlWhlTqStsHi_enum;
  }

  /* End of MinMax: '<S172>/MinMax' */

  /* MinMax: '<S172>/MinMax1' incorporates:
   *  Constant: '<S172>/sat7'
   */
  if (VOPM_BrkPwrRecupActlWhlTqSts_enum >= KOPM_PwrRecupActlWhlTqStsLo_enum)
  {
    /* MinMax: '<S172>/MinMax1' */
    VOPM_PwrRecupActlWhlTqSts_enum = VOPM_BrkPwrRecupActlWhlTqSts_enum;
  }
  else
  {
    /* MinMax: '<S172>/MinMax1' */
    VOPM_PwrRecupActlWhlTqSts_enum = KOPM_PwrRecupActlWhlTqStsLo_enum;
  }

  /* End of MinMax: '<S172>/MinMax1' */
  /* End of Outputs for SubSystem: '<S156>/Subsys_VOPM_PwrRecupActlWhlTqSts_enum' */

  /* Outputs for Atomic SubSystem: '<S156>/Subsys_VOPM_PwrRecupActWhlTq_Nm' */
  /* Switch: '<S171>/Switch4' incorporates:
   *  Constant: '<S171>/sat3'
   */
  if (KOPM_PwrRecupActWhlTq_Nm_ovrdflg)
  {
    /* MinMax: '<S193>/MinMax' incorporates:
     *  Constant: '<S171>/sat4'
     *  Product: '<S180>/Product1'
     */
    VOPM_VCUMasterCylinderPreReq_Bar = KOPM_PwrRecupActWhlTq_Nm_ovrdval;
  }
  else
  {
    /* MinMax: '<S193>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S171>/Data Type Conversion1'
     *  Product: '<S180>/Product1'
     */
    VOPM_VCUMasterCylinderPreReq_Bar =
        (Rte_IrvIRead_Runbl_OpmCanTx_10ms_Vcu2OpmCHA_outputs())
            ->VVTM_PwrRecActWhlTorq_Nm;
  }

  /* End of Switch: '<S171>/Switch4' */

  /* MinMax: '<S171>/MinMax' incorporates:
   *  Constant: '<S171>/sat6'
   */
  if (VOPM_VCUMasterCylinderPreReq_Bar > KOPM_PwrRecupActWhlTqHi_Nm)
  {
    /* MinMax: '<S193>/MinMax' */
    VOPM_VCUMasterCylinderPreReq_Bar = KOPM_PwrRecupActWhlTqHi_Nm;
  }

  /* End of MinMax: '<S171>/MinMax' */

  /* MinMax: '<S171>/MinMax1' incorporates:
   *  Constant: '<S171>/sat7'
   */
  if (VOPM_VCUMasterCylinderPreReq_Bar >= KOPM_PwrRecupActWhlTqLo_Nm)
  {
    /* MinMax: '<S171>/MinMax1' */
    VOPM_PwrRecupActWhlTq_Nm = VOPM_VCUMasterCylinderPreReq_Bar;
  }
  else
  {
    /* MinMax: '<S171>/MinMax1' */
    VOPM_PwrRecupActWhlTq_Nm = KOPM_PwrRecupActWhlTqLo_Nm;
  }

  /* End of MinMax: '<S171>/MinMax1' */
  /* End of Outputs for SubSystem: '<S156>/Subsys_VOPM_PwrRecupActWhlTq_Nm' */

  /* DataTypeConversion: '<S156>/DataTypeConversion6' incorporates:
   *  Constant: '<S182>/Constant'
   *  Sum: '<S182>/Add'
   */
  if (VOPM_PwrRecupActWhlTq_Nm - -32768.0F < 65536.0F)
  {
    if (VOPM_PwrRecupActWhlTq_Nm - -32768.0F >= 0.0F)
    {
      AppSwcOpm_ARID_DEF.VCU_10_Torque_CHA_j.VCU_PwrRecupActWhlTq = (uint16)(VOPM_PwrRecupActWhlTq_Nm - -32768.0F);
    }
    else
    {
      AppSwcOpm_ARID_DEF.VCU_10_Torque_CHA_j.VCU_PwrRecupActWhlTq = 0U;
    }
  }
  else
  {
    AppSwcOpm_ARID_DEF.VCU_10_Torque_CHA_j.VCU_PwrRecupActWhlTq = MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<S156>/DataTypeConversion6' */

  /* Outputs for Atomic SubSystem: '<S156>/Subsys_VOPM_PwrRecupMaxAvlbWhlTqSts_enum' */
  /* Switch: '<S173>/Switch4' incorporates:
   *  Constant: '<S173>/sat3'
   */
  if (KOPM_PwrRecupMaxAvlbWhlTqSts_enum_ovrdflg)
  {
    /* MinMax: '<S191>/MinMax' incorporates:
     *  Constant: '<S173>/sat4'
     *  MinMax: '<S164>/MinMax'
     */
    VOPM_BrkPwrRecupActlWhlTqSts_enum =
        KOPM_PwrRecupMaxAvlbWhlTqSts_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S191>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S173>/Data Type Conversion1'
     *  MinMax: '<S164>/MinMax'
     */
    VOPM_BrkPwrRecupActlWhlTqSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_10ms_Vcu2OpmCHA_outputs())
            ->VVTM_BrkPwrRecMaxWhlTorqSta_enum;
  }

  /* End of Switch: '<S173>/Switch4' */

  /* MinMax: '<S173>/MinMax' incorporates:
   *  Constant: '<S173>/sat6'
   */
  if (VOPM_BrkPwrRecupActlWhlTqSts_enum > KOPM_PwrRecupMaxAvlbWhlTqStsHi_enum)
  {
    /* MinMax: '<S191>/MinMax' */
    VOPM_BrkPwrRecupActlWhlTqSts_enum = KOPM_PwrRecupMaxAvlbWhlTqStsHi_enum;
  }

  /* End of MinMax: '<S173>/MinMax' */

  /* MinMax: '<S173>/MinMax1' incorporates:
   *  Constant: '<S173>/sat7'
   */
  if (VOPM_BrkPwrRecupActlWhlTqSts_enum >= KOPM_PwrRecupMaxAvlbWhlTqStsLo_enum)
  {
    /* MinMax: '<S173>/MinMax1' */
    VOPM_PwrRecupMaxAvlbWhlTqSts_enum = VOPM_BrkPwrRecupActlWhlTqSts_enum;
  }
  else
  {
    /* MinMax: '<S173>/MinMax1' */
    VOPM_PwrRecupMaxAvlbWhlTqSts_enum = KOPM_PwrRecupMaxAvlbWhlTqStsLo_enum;
  }

  /* End of MinMax: '<S173>/MinMax1' */
  /* End of Outputs for SubSystem: '<S156>/Subsys_VOPM_PwrRecupMaxAvlbWhlTqSts_enum' */

  /* Outputs for Atomic SubSystem: '<S156>/Subsys_VOPM_BrkPwrRecupMaxAvlbWhlTq_Nm' */
  /* Switch: '<S165>/Switch4' incorporates:
   *  Constant: '<S165>/sat3'
   */
  if (KOPM_BrkPwrRecupMaxAvlbWhlTq_Nm_ovrdflg)
  {
    /* MinMax: '<S193>/MinMax' incorporates:
     *  Constant: '<S165>/sat4'
     *  Product: '<S180>/Product1'
     */
    VOPM_VCUMasterCylinderPreReq_Bar = KOPM_BrkPwrRecupMaxAvlbWhlTq_Nm_ovrdval;
  }
  else
  {
    /* MinMax: '<S193>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S165>/Data Type Conversion1'
     *  Product: '<S180>/Product1'
     */
    VOPM_VCUMasterCylinderPreReq_Bar =
        (Rte_IrvIRead_Runbl_OpmCanTx_10ms_Vcu2OpmCHA_outputs())
            ->VVTM_BrkPwrRecMaxWhlTorq_Nm;
  }

  /* End of Switch: '<S165>/Switch4' */

  /* MinMax: '<S165>/MinMax' incorporates:
   *  Constant: '<S165>/sat6'
   */
  if (VOPM_VCUMasterCylinderPreReq_Bar > KOPM_BrkPwrRecupMaxAvlbWhlTqHi_Nm)
  {
    /* MinMax: '<S193>/MinMax' */
    VOPM_VCUMasterCylinderPreReq_Bar = KOPM_BrkPwrRecupMaxAvlbWhlTqHi_Nm;
  }

  /* End of MinMax: '<S165>/MinMax' */

  /* MinMax: '<S165>/MinMax1' incorporates:
   *  Constant: '<S165>/sat7'
   */
  if (VOPM_VCUMasterCylinderPreReq_Bar >= KOPM_BrkPwrRecupMaxAvlbWhlTqLo_Nm)
  {
    /* MinMax: '<S165>/MinMax1' */
    VOPM_BrkPwrRecupMaxAvlbWhlTq_Nm = VOPM_VCUMasterCylinderPreReq_Bar;
  }
  else
  {
    /* MinMax: '<S165>/MinMax1' */
    VOPM_BrkPwrRecupMaxAvlbWhlTq_Nm = KOPM_BrkPwrRecupMaxAvlbWhlTqLo_Nm;
  }

  /* End of MinMax: '<S165>/MinMax1' */
  /* End of Outputs for SubSystem: '<S156>/Subsys_VOPM_BrkPwrRecupMaxAvlbWhlTq_Nm' */

  /* DataTypeConversion: '<S156>/DataTypeConversion8' incorporates:
   *  Constant: '<S183>/Constant'
   *  Sum: '<S183>/Add'
   */
  if (VOPM_BrkPwrRecupMaxAvlbWhlTq_Nm - -32768.0F < 65536.0F)
  {
    if (VOPM_BrkPwrRecupMaxAvlbWhlTq_Nm - -32768.0F >= 0.0F)
    {
      AppSwcOpm_ARID_DEF.VCU_10_Torque_CHA_j.VCU_BrkPwrRecupMaxAvlbWhlTq =
          (uint16)(VOPM_BrkPwrRecupMaxAvlbWhlTq_Nm - -32768.0F);
    }
    else
    {
      AppSwcOpm_ARID_DEF.VCU_10_Torque_CHA_j.VCU_BrkPwrRecupMaxAvlbWhlTq = 0U;
    }
  }
  else
  {
    AppSwcOpm_ARID_DEF.VCU_10_Torque_CHA_j.VCU_BrkPwrRecupMaxAvlbWhlTq =
        MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<S156>/DataTypeConversion8' */

  /* Outputs for Atomic SubSystem: '<S156>/Subsys_VOPM_BrkPwrRecupActlWhlTqSts_enum' */
  /* Switch: '<S164>/Switch4' incorporates:
   *  Constant: '<S164>/sat3'
   */
  if (KOPM_BrkPwrRecupActlWhlTqSts_enum_ovrdflg)
  {
    /* MinMax: '<S191>/MinMax' incorporates:
     *  Constant: '<S164>/sat4'
     *  MinMax: '<S164>/MinMax'
     */
    VOPM_BrkPwrRecupActlWhlTqSts_enum =
        KOPM_BrkPwrRecupActlWhlTqSts_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S191>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S164>/Data Type Conversion1'
     *  MinMax: '<S164>/MinMax'
     */
    VOPM_BrkPwrRecupActlWhlTqSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_10ms_Vcu2OpmCHA_outputs())
            ->VVTM_BrkPwrRecActWhlTorqSt_enum;
  }

  /* End of Switch: '<S164>/Switch4' */

  /* MinMax: '<S164>/MinMax' incorporates:
   *  Constant: '<S164>/sat6'
   */
  if (VOPM_BrkPwrRecupActlWhlTqSts_enum > KOPM_BrkPwrRecupActlWhlTqStsHi_enum)
  {
    /* MinMax: '<S191>/MinMax' */
    VOPM_BrkPwrRecupActlWhlTqSts_enum = KOPM_BrkPwrRecupActlWhlTqStsHi_enum;
  }

  /* End of MinMax: '<S164>/MinMax' */

  /* MinMax: '<S164>/MinMax1' incorporates:
   *  Constant: '<S164>/sat7'
   */
  if (VOPM_BrkPwrRecupActlWhlTqSts_enum < KOPM_BrkPwrRecupActlWhlTqStsLo_enum)
  {
    /* MinMax: '<S191>/MinMax' incorporates:
     *  MinMax: '<S164>/MinMax1'
     */
    VOPM_BrkPwrRecupActlWhlTqSts_enum = KOPM_BrkPwrRecupActlWhlTqStsLo_enum;
  }

  /* End of MinMax: '<S164>/MinMax1' */
  /* End of Outputs for SubSystem: '<S156>/Subsys_VOPM_BrkPwrRecupActlWhlTqSts_enum' */

  /* Outputs for Atomic SubSystem: '<S156>/Subsys_VOPM_BrkPwrRecupActWhlTq_Nm' */
  /* Switch: '<S163>/Switch4' incorporates:
   *  Constant: '<S163>/sat3'
   */
  if (KOPM_BrkPwrRecupActWhlTq_Nm_ovrdflg)
  {
    /* MinMax: '<S193>/MinMax' incorporates:
     *  Constant: '<S163>/sat4'
     *  Product: '<S180>/Product1'
     */
    VOPM_VCUMasterCylinderPreReq_Bar = KOPM_BrkPwrRecupActWhlTq_Nm_ovrdval;
  }
  else
  {
    /* MinMax: '<S193>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S163>/Data Type Conversion1'
     *  Product: '<S180>/Product1'
     */
    VOPM_VCUMasterCylinderPreReq_Bar =
        (Rte_IrvIRead_Runbl_OpmCanTx_10ms_Vcu2OpmCHA_outputs())
            ->VVTM_BrkPwrRecActWhlTorq_Nm;
  }

  /* End of Switch: '<S163>/Switch4' */

  /* MinMax: '<S163>/MinMax' incorporates:
   *  Constant: '<S163>/sat6'
   */
  if (VOPM_VCUMasterCylinderPreReq_Bar > KOPM_BrkPwrRecupActWhlTqHi_Nm)
  {
    /* MinMax: '<S193>/MinMax' */
    VOPM_VCUMasterCylinderPreReq_Bar = KOPM_BrkPwrRecupActWhlTqHi_Nm;
  }

  /* End of MinMax: '<S163>/MinMax' */

  /* MinMax: '<S163>/MinMax1' incorporates:
   *  Constant: '<S163>/sat7'
   */
  if (VOPM_VCUMasterCylinderPreReq_Bar >= KOPM_BrkPwrRecupActWhlTqLo_Nm)
  {
    /* MinMax: '<S163>/MinMax1' */
    VOPM_BrkPwrRecupActWhlTq_Nm = VOPM_VCUMasterCylinderPreReq_Bar;
  }
  else
  {
    /* MinMax: '<S163>/MinMax1' */
    VOPM_BrkPwrRecupActWhlTq_Nm = KOPM_BrkPwrRecupActWhlTqLo_Nm;
  }

  /* End of MinMax: '<S163>/MinMax1' */
  /* End of Outputs for SubSystem: '<S156>/Subsys_VOPM_BrkPwrRecupActWhlTq_Nm' */

  /* DataTypeConversion: '<S156>/DataTypeConversion10' incorporates:
   *  Constant: '<S184>/Constant'
   *  Sum: '<S184>/Add'
   */
  if (VOPM_BrkPwrRecupActWhlTq_Nm - -6200.0F < 65536.0F)
  {
    if (VOPM_BrkPwrRecupActWhlTq_Nm - -6200.0F >= 0.0F)
    {
      AppSwcOpm_ARID_DEF.VCU_10_Torque_CHA_j.VCU_BrkPwrRecupActWhlTq = (uint16)(VOPM_BrkPwrRecupActWhlTq_Nm - -6200.0F);
    }
    else
    {
      AppSwcOpm_ARID_DEF.VCU_10_Torque_CHA_j.VCU_BrkPwrRecupActWhlTq = 0U;
    }
  }
  else
  {
    AppSwcOpm_ARID_DEF.VCU_10_Torque_CHA_j.VCU_BrkPwrRecupActWhlTq =
        MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<S156>/DataTypeConversion10' */

  /* Outputs for Atomic SubSystem: '<S156>/Subsys_VOPM_VCUAccReqDrvOff_flg' */
  /* Switch: '<S174>/Switch4' incorporates:
   *  Constant: '<S174>/sat3'
   */
  if (KOPM_VCUAccReqDrvOff_flg_ovrdflg)
  {
    /* Switch: '<S174>/Switch4' incorporates:
     *  Constant: '<S174>/sat4'
     */
    VOPM_VCUAccReqDrvOff_flg = KOPM_VCUAccReqDrvOff_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S174>/Switch4' incorporates:
     *  Inport: '<Root>/IPM_FCM_B_CHA'
     */
    VOPM_VCUAccReqDrvOff_flg =
        (Rte_IRead_Runbl_OpmCanTx_10ms_IPM_FCM_B_CHA_IPM_FCM_B_CHA())
            ->VIPM_FCMAccReqDriveOff_flg;
  }

  /* End of Switch: '<S174>/Switch4' */
  /* End of Outputs for SubSystem: '<S156>/Subsys_VOPM_VCUAccReqDrvOff_flg' */

  /* Outputs for Atomic SubSystem: '<S156>/Subsys_VOPM_ActlMotorRotateSpd_rpm' */
  /* Switch: '<S160>/Switch4' incorporates:
   *  Constant: '<S160>/sat3'
   */
  if (KOPM_ActlMotorRotateSpd_rpm_ovrdflg)
  {
    /* MinMax: '<S193>/MinMax' incorporates:
     *  Constant: '<S160>/sat4'
     *  Product: '<S180>/Product1'
     */
    VOPM_VCUMasterCylinderPreReq_Bar = KOPM_ActlMotorRotateSpd_rpm_ovrdval;
  }
  else
  {
    /* MinMax: '<S193>/MinMax' incorporates:
     *  Inport: '<Root>/IPM_INV_1_Value_EPT'
     *  Product: '<S180>/Product1'
     */
    VOPM_VCUMasterCylinderPreReq_Bar =
        (Rte_IRead_Runbl_OpmCanTx_10ms_IPM_INV_1_Value_EPT_IPM_INV_1_Value_EPT())->VIPM_INV1MotSpd_rpm;
  }

  /* End of Switch: '<S160>/Switch4' */

  /* MinMax: '<S160>/MinMax' incorporates:
   *  Constant: '<S160>/sat6'
   */
  if (VOPM_VCUMasterCylinderPreReq_Bar > KOPM_ActlMotorRotateSpdHi_rpm)
  {
    /* MinMax: '<S193>/MinMax' */
    VOPM_VCUMasterCylinderPreReq_Bar = KOPM_ActlMotorRotateSpdHi_rpm;
  }

  /* End of MinMax: '<S160>/MinMax' */

  /* MinMax: '<S160>/MinMax1' incorporates:
   *  Constant: '<S160>/sat7'
   */
  if (VOPM_VCUMasterCylinderPreReq_Bar >= KOPM_ActlMotorRotateSpdLo_rpm)
  {
    /* MinMax: '<S160>/MinMax1' */
    VOPM_ActlMotorRotateSpd_rpm = VOPM_VCUMasterCylinderPreReq_Bar;
  }
  else
  {
    /* MinMax: '<S160>/MinMax1' */
    VOPM_ActlMotorRotateSpd_rpm = KOPM_ActlMotorRotateSpdLo_rpm;
  }

  /* End of MinMax: '<S160>/MinMax1' */
  /* End of Outputs for SubSystem: '<S156>/Subsys_VOPM_ActlMotorRotateSpd_rpm' */

  /* Outputs for Atomic SubSystem: '<S156>/Subsys_VOPM_ActlMotorRotateSpdVld_flg' */
  /* Switch: '<S159>/Switch4' incorporates:
   *  Constant: '<S159>/sat3'
   */
  if (KOPM_ActlMotorRotateSpdVld_flg_ovrdflg)
  {
    /* Switch: '<S159>/Switch4' incorporates:
     *  Constant: '<S159>/sat4'
     */
    VOPM_ActlMotorRotateSpdVld_flg = KOPM_ActlMotorRotateSpdVld_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S159>/Switch4' incorporates:
     *  Inport: '<Root>/IPM_INV_1_Value_EPT'
     */
    VOPM_ActlMotorRotateSpdVld_flg =
        (Rte_IRead_Runbl_OpmCanTx_10ms_IPM_INV_1_Value_EPT_IPM_INV_1_Value_EPT())->VIPM_INV1MotSpdVld_flg;
  }

  /* End of Switch: '<S159>/Switch4' */
  /* End of Outputs for SubSystem: '<S156>/Subsys_VOPM_ActlMotorRotateSpdVld_flg' */

  /* Outputs for Atomic SubSystem: '<S156>/Subsys_VOPM_ActlMotorTorq_Nm' */
  /* Switch: '<S162>/Switch4' incorporates:
   *  Constant: '<S162>/sat3'
   */
  if (KOPM_ActlMotorTorq_Nm_ovrdflg)
  {
    /* MinMax: '<S193>/MinMax' incorporates:
     *  Constant: '<S162>/sat4'
     *  Product: '<S180>/Product1'
     */
    VOPM_VCUMasterCylinderPreReq_Bar = KOPM_ActlMotorTorq_Nm_ovrdval;
  }
  else
  {
    /* MinMax: '<S193>/MinMax' incorporates:
     *  Inport: '<Root>/IPM_INV_1_Value_EPT'
     *  Product: '<S180>/Product1'
     */
    VOPM_VCUMasterCylinderPreReq_Bar =
        (Rte_IRead_Runbl_OpmCanTx_10ms_IPM_INV_1_Value_EPT_IPM_INV_1_Value_EPT())->VIPM_INV1ActTorq_Nm;
  }

  /* End of Switch: '<S162>/Switch4' */

  /* MinMax: '<S162>/MinMax' incorporates:
   *  Constant: '<S162>/sat6'
   */
  if (VOPM_VCUMasterCylinderPreReq_Bar > KOPM_ActlMotorTorqHi_Nm)
  {
    /* MinMax: '<S193>/MinMax' */
    VOPM_VCUMasterCylinderPreReq_Bar = KOPM_ActlMotorTorqHi_Nm;
  }

  /* End of MinMax: '<S162>/MinMax' */

  /* MinMax: '<S162>/MinMax1' incorporates:
   *  Constant: '<S162>/sat7'
   */
  if (VOPM_VCUMasterCylinderPreReq_Bar >= KOPM_ActlMotorTorqLo_Nm)
  {
    /* MinMax: '<S162>/MinMax1' */
    VOPM_ActlMotorTorq_Nm = VOPM_VCUMasterCylinderPreReq_Bar;
  }
  else
  {
    /* MinMax: '<S162>/MinMax1' */
    VOPM_ActlMotorTorq_Nm = KOPM_ActlMotorTorqLo_Nm;
  }

  /* End of MinMax: '<S162>/MinMax1' */
  /* End of Outputs for SubSystem: '<S156>/Subsys_VOPM_ActlMotorTorq_Nm' */

  /* Outputs for Atomic SubSystem: '<S156>/Subsys_VOPM_ActlMotorTorqVld_flg' */
  /* Switch: '<S161>/Switch4' incorporates:
   *  Constant: '<S161>/sat3'
   */
  if (KOPM_ActlMotorTorqVld_flg_ovrdflg)
  {
    /* Switch: '<S161>/Switch4' incorporates:
     *  Constant: '<S161>/sat4'
     */
    VOPM_ActlMotorTorqVld_flg = KOPM_ActlMotorTorqVld_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S161>/Switch4' incorporates:
     *  Inport: '<Root>/IPM_INV_1_Value_EPT'
     */
    VOPM_ActlMotorTorqVld_flg =
        (Rte_IRead_Runbl_OpmCanTx_10ms_IPM_INV_1_Value_EPT_IPM_INV_1_Value_EPT())->VIPM_INV1ActTorqVld_flg;
  }

  /* End of Switch: '<S161>/Switch4' */
  /* End of Outputs for SubSystem: '<S156>/Subsys_VOPM_ActlMotorTorqVld_flg' */

  /* Outputs for Atomic SubSystem: '<S156>/Subsys_VOPM_DrvReqMotorTorq_Nm' */
  /* Switch: '<S167>/Switch4' incorporates:
   *  Constant: '<S167>/sat3'
   */
  if (KOPM_DrvReqMotorTorq_Nm_ovrdflg)
  {
    /* MinMax: '<S193>/MinMax' incorporates:
     *  Constant: '<S167>/sat4'
     *  Product: '<S180>/Product1'
     */
    VOPM_VCUMasterCylinderPreReq_Bar = KOPM_DrvReqMotorTorq_Nm_ovrdval;
  }
  else
  {
    /* MinMax: '<S193>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S167>/Data Type Conversion1'
     *  Product: '<S180>/Product1'
     */
    VOPM_VCUMasterCylinderPreReq_Bar =
        (Rte_IrvIRead_Runbl_OpmCanTx_10ms_Vcu2OpmCHA_outputs())
            ->VVTM_DrvReqMotorTorq_Nm;
  }

  /* End of Switch: '<S167>/Switch4' */

  /* MinMax: '<S167>/MinMax' incorporates:
   *  Constant: '<S167>/sat6'
   */
  if (VOPM_VCUMasterCylinderPreReq_Bar > KOPM_DrvReqMotorTorqHi_Nm)
  {
    /* MinMax: '<S193>/MinMax' */
    VOPM_VCUMasterCylinderPreReq_Bar = KOPM_DrvReqMotorTorqHi_Nm;
  }

  /* End of MinMax: '<S167>/MinMax' */

  /* MinMax: '<S167>/MinMax1' incorporates:
   *  Constant: '<S167>/sat7'
   */
  if (VOPM_VCUMasterCylinderPreReq_Bar >= KOPM_DrvReqMotorTorqLo_Nm)
  {
    /* MinMax: '<S167>/MinMax1' */
    VOPM_DrvReqMotorTorq_Nm = VOPM_VCUMasterCylinderPreReq_Bar;
  }
  else
  {
    /* MinMax: '<S167>/MinMax1' */
    VOPM_DrvReqMotorTorq_Nm = KOPM_DrvReqMotorTorqLo_Nm;
  }

  /* End of MinMax: '<S167>/MinMax1' */
  /* End of Outputs for SubSystem: '<S156>/Subsys_VOPM_DrvReqMotorTorq_Nm' */

  /* Outputs for Atomic SubSystem: '<S156>/Subsys_VOPM_DrvReqMotorTorqVld_flg' */
  /* Switch: '<S166>/Switch4' incorporates:
   *  Constant: '<S166>/sat3'
   */
  if (KOPM_DrvReqMotorTorqVld_flg_ovrdflg)
  {
    /* Switch: '<S166>/Switch4' incorporates:
     *  Constant: '<S166>/sat4'
     */
    VOPM_DrvReqMotorTorqVld_flg = KOPM_DrvReqMotorTorqVld_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S166>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S166>/Data Type Conversion1'
     */
    VOPM_DrvReqMotorTorqVld_flg =
        (Rte_IrvIRead_Runbl_OpmCanTx_10ms_Vcu2OpmCHA_outputs())
            ->VVTM_DrvReqMotorTorqV_flg;
  }

  /* End of Switch: '<S166>/Switch4' */
  /* End of Outputs for SubSystem: '<S156>/Subsys_VOPM_DrvReqMotorTorqVld_flg' */

  /* Outputs for Atomic SubSystem: '<S156>/Subsys_VOPM_VCUEnaEHBBrkRun_flg' */
  /* Switch: '<S176>/Switch4' incorporates:
   *  Constant: '<S176>/sat3'
   */
  if (KOPM_VCUEnaEHBBrkRun_flg_ovrdflg)
  {
    /* Switch: '<S176>/Switch4' incorporates:
     *  Constant: '<S176>/sat4'
     */
    VOPM_VCUEnaEHBBrkRun_flg = KOPM_VCUEnaEHBBrkRun_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S176>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S176>/Data Type Conversion1'
     */
    VOPM_VCUEnaEHBBrkRun_flg =
        (Rte_IrvIRead_Runbl_OpmCanTx_10ms_Vcu2OpmCHA_outputs())
            ->VVTM_EnblEHBBrkRun_flg;
  }

  /* End of Switch: '<S176>/Switch4' */
  /* End of Outputs for SubSystem: '<S156>/Subsys_VOPM_VCUEnaEHBBrkRun_flg' */

  /* Outputs for Atomic SubSystem: '<S156>/Subsys_VOPM_VCUAccReqStandstill_flg' */
  /* Switch: '<S175>/Switch4' incorporates:
   *  Constant: '<S175>/sat3'
   */
  if (KOPM_VCUAccReqStandstill_flg_ovrdflg)
  {
    /* Switch: '<S175>/Switch4' incorporates:
     *  Constant: '<S175>/sat4'
     */
    VOPM_VCUAccReqStandstill_flg = KOPM_VCUAccReqStandstill_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S175>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S175>/Data Type Conversion1'
     */
    VOPM_VCUAccReqStandstill_flg =
        (Rte_IrvIRead_Runbl_OpmCanTx_10ms_Vcu2OpmCHA_outputs())
            ->VVTM_AccReqStandstill_flg;
  }

  /* End of Switch: '<S175>/Switch4' */
  /* End of Outputs for SubSystem: '<S156>/Subsys_VOPM_VCUAccReqStandstill_flg' */

  /* Outputs for Atomic SubSystem: '<S156>/Subsys_VOPM_VCUMotTorqueReqToEHB_Nm' */
  /* Switch: '<S178>/Switch4' incorporates:
   *  Constant: '<S178>/sat3'
   */
  if (KOPM_VCUMotTorqueReqToEHB_Nm_ovrdflg)
  {
    /* MinMax: '<S193>/MinMax' incorporates:
     *  Constant: '<S178>/sat4'
     *  Product: '<S180>/Product1'
     */
    VOPM_VCUMasterCylinderPreReq_Bar = KOPM_VCUMotTorqueReqToEHB_Nm_ovrdval;
  }
  else
  {
    /* MinMax: '<S193>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S178>/Data Type Conversion1'
     *  Product: '<S180>/Product1'
     */
    VOPM_VCUMasterCylinderPreReq_Bar =
        (Rte_IrvIRead_Runbl_OpmCanTx_10ms_Vcu2OpmCHA_outputs())
            ->VVTM_MotorTqReqToEHB_Nm;
  }

  /* End of Switch: '<S178>/Switch4' */

  /* MinMax: '<S178>/MinMax' incorporates:
   *  Constant: '<S178>/sat6'
   */
  if (VOPM_VCUMasterCylinderPreReq_Bar > KOPM_VCUMotTorqueReqToEHBHi_Nm)
  {
    /* MinMax: '<S193>/MinMax' */
    VOPM_VCUMasterCylinderPreReq_Bar = KOPM_VCUMotTorqueReqToEHBHi_Nm;
  }

  /* End of MinMax: '<S178>/MinMax' */

  /* MinMax: '<S178>/MinMax1' incorporates:
   *  Constant: '<S178>/sat7'
   */
  if (VOPM_VCUMasterCylinderPreReq_Bar >= KOPM_VCUMotTorqueReqToEHBLo_Nm)
  {
    /* MinMax: '<S178>/MinMax1' */
    VOPM_VCUMotTorqueReqToEHB_Nm = VOPM_VCUMasterCylinderPreReq_Bar;
  }
  else
  {
    /* MinMax: '<S178>/MinMax1' */
    VOPM_VCUMotTorqueReqToEHB_Nm = KOPM_VCUMotTorqueReqToEHBLo_Nm;
  }

  /* End of MinMax: '<S178>/MinMax1' */
  /* End of Outputs for SubSystem: '<S156>/Subsys_VOPM_VCUMotTorqueReqToEHB_Nm' */

  /* DataTypeConversion: '<S156>/DataTypeConversion22' incorporates:
   *  Constant: '<S188>/Constant'
   *  Constant: '<S188>/Constant1'
   *  Product: '<S188>/Product1'
   *  Sum: '<S188>/Add'
   */
  tmp = (VOPM_VCUMotTorqueReqToEHB_Nm - -819.2F) * 10.0F;
  if (tmp < 65536.0F)
  {
    if (tmp >= 0.0F)
    {
      AppSwcOpm_ARID_DEF.VCU_10_Torque_CHA_j.VCU_1_MotTorqueReqToEHB = (uint16)
          tmp;
    }
    else
    {
      AppSwcOpm_ARID_DEF.VCU_10_Torque_CHA_j.VCU_1_MotTorqueReqToEHB = 0U;
    }
  }
  else
  {
    AppSwcOpm_ARID_DEF.VCU_10_Torque_CHA_j.VCU_1_MotTorqueReqToEHB =
        MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<S156>/DataTypeConversion22' */

  /* Outputs for Atomic SubSystem: '<S156>/Subsys_VOPM_VCUMasterCylinderPreReq_Bar' */
  /* Switch: '<S177>/Switch4' incorporates:
   *  Constant: '<S177>/sat3'
   */
  if (KOPM_VCUMasterCylinderPreReq_Bar_ovrdflg)
  {
    /* MinMax: '<S193>/MinMax' incorporates:
     *  Constant: '<S177>/sat4'
     *  Product: '<S180>/Product1'
     */
    VOPM_VCUMasterCylinderPreReq_Bar = KOPM_VCUMasterCylinderPreReq_Bar_ovrdval;
  }
  else
  {
    /* MinMax: '<S193>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S177>/Data Type Conversion1'
     *  Product: '<S180>/Product1'
     */
    VOPM_VCUMasterCylinderPreReq_Bar =
        (Rte_IrvIRead_Runbl_OpmCanTx_10ms_Vcu2OpmCHA_outputs())
            ->VVTM_MstrCylPresrReq_Bar;
  }

  /* End of Switch: '<S177>/Switch4' */

  /* MinMax: '<S177>/MinMax' incorporates:
   *  Constant: '<S177>/sat6'
   */
  if (VOPM_VCUMasterCylinderPreReq_Bar > KOPM_VCUMasterCylinderPreReqHi_Bar)
  {
    /* MinMax: '<S193>/MinMax' */
    VOPM_VCUMasterCylinderPreReq_Bar = KOPM_VCUMasterCylinderPreReqHi_Bar;
  }

  /* End of MinMax: '<S177>/MinMax' */

  /* MinMax: '<S177>/MinMax1' incorporates:
   *  Constant: '<S177>/sat7'
   */
  if (VOPM_VCUMasterCylinderPreReq_Bar < KOPM_VCUMasterCylinderPreReqLo_Bar)
  {
    /* MinMax: '<S193>/MinMax' incorporates:
     *  MinMax: '<S177>/MinMax1'
     */
    VOPM_VCUMasterCylinderPreReq_Bar = KOPM_VCUMasterCylinderPreReqLo_Bar;
  }

  /* End of MinMax: '<S177>/MinMax1' */
  /* End of Outputs for SubSystem: '<S156>/Subsys_VOPM_VCUMasterCylinderPreReq_Bar' */

  /* DataTypeConversion: '<S156>/DataTypeConversion23' incorporates:
   *  Constant: '<S180>/Constant1'
   *  Product: '<S180>/Product1'
   *  Sum: '<S180>/Add'
   */
  tmp = VOPM_VCUMasterCylinderPreReq_Bar * 8.0F;
  if (tmp < 65536.0F)
  {
    if (tmp >= 0.0F)
    {
      AppSwcOpm_ARID_DEF.VCU_10_Torque_CHA_j.VCU_MasterCylinderPreReq = (uint16)
          tmp;
    }
    else
    {
      AppSwcOpm_ARID_DEF.VCU_10_Torque_CHA_j.VCU_MasterCylinderPreReq = 0U;
    }
  }
  else
  {
    AppSwcOpm_ARID_DEF.VCU_10_Torque_CHA_j.VCU_MasterCylinderPreReq =
        MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<S156>/DataTypeConversion23' */

  /* BusCreator: '<S156>/BusCreator' incorporates:
   *  Switch: '<S157>/Switch4'
   */
  AppSwcOpm_ARID_DEF.VCU_10_Torque_CHA_j.VCU_ActWhlTqVld = VOPM_ActWhlTqVld_flg;

  /* DataTypeConversion: '<S156>/DataTypeConversion1' incorporates:
   *  Constant: '<S179>/Constant'
   *  Constant: '<S179>/Constant1'
   *  Product: '<S179>/Product1'
   *  Sum: '<S179>/Add'
   */
  tmp = (VOPM_ActWhlTq_Nm - -6200.0F) * 2.0F;
  if (tmp < 65536.0F)
  {
    if (tmp >= 0.0F)
    {
      /* BusCreator: '<S156>/BusCreator' */
      AppSwcOpm_ARID_DEF.VCU_10_Torque_CHA_j.VCU_ActWhlTq = (uint16)tmp;
    }
    else
    {
      /* BusCreator: '<S156>/BusCreator' */
      AppSwcOpm_ARID_DEF.VCU_10_Torque_CHA_j.VCU_ActWhlTq = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S156>/BusCreator' */
    AppSwcOpm_ARID_DEF.VCU_10_Torque_CHA_j.VCU_ActWhlTq = MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<S156>/DataTypeConversion1' */

  /* BusCreator: '<S156>/BusCreator' incorporates:
   *  Switch: '<S168>/Switch4'
   */
  AppSwcOpm_ARID_DEF.VCU_10_Torque_CHA_j.VCU_DrvReqWhlTqVld =
      VOPM_DrvReqWhlTqVld_flg;

  /* DataTypeConversion: '<S156>/DataTypeConversion3' incorporates:
   *  Constant: '<S181>/Constant'
   *  Constant: '<S181>/Constant1'
   *  Product: '<S181>/Product1'
   *  Sum: '<S181>/Add'
   */
  tmp = (VOPM_DrvReqWhlTq_Nm - -6200.0F) * 2.0F;
  if (tmp < 65536.0F)
  {
    if (tmp >= 0.0F)
    {
      /* BusCreator: '<S156>/BusCreator' */
      AppSwcOpm_ARID_DEF.VCU_10_Torque_CHA_j.VCU_DrvReqWhlTq = (uint16)tmp;
    }
    else
    {
      /* BusCreator: '<S156>/BusCreator' */
      AppSwcOpm_ARID_DEF.VCU_10_Torque_CHA_j.VCU_DrvReqWhlTq = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S156>/BusCreator' */
    AppSwcOpm_ARID_DEF.VCU_10_Torque_CHA_j.VCU_DrvReqWhlTq = MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<S156>/DataTypeConversion3' */

  /* BusCreator: '<S156>/BusCreator' incorporates:
   *  Switch: '<S174>/Switch4'
   */
  AppSwcOpm_ARID_DEF.VCU_10_Torque_CHA_j.VCU_PwrRecupActlWhlTqSts =
      VOPM_PwrRecupActlWhlTqSts_enum;
  AppSwcOpm_ARID_DEF.VCU_10_Torque_CHA_j.VCU_PwrRecupMaxAvlbWhlTqSts =
      VOPM_PwrRecupMaxAvlbWhlTqSts_enum;
  AppSwcOpm_ARID_DEF.VCU_10_Torque_CHA_j.VCU_BrkPwrRecupActlWhlTqSts =
      VOPM_BrkPwrRecupActlWhlTqSts_enum;
  AppSwcOpm_ARID_DEF.VCU_10_Torque_CHA_j.VCU_AccReqDriveOff =
      VOPM_VCUAccReqDrvOff_flg;

  /* DataTypeConversion: '<S156>/DataTypeConversion12' incorporates:
   *  Constant: '<S185>/Constant'
   *  Sum: '<S185>/Add'
   */
  if (VOPM_ActlMotorRotateSpd_rpm - -10000.0F < 65536.0F)
  {
    if (VOPM_ActlMotorRotateSpd_rpm - -10000.0F >= 0.0F)
    {
      /* BusCreator: '<S156>/BusCreator' */
      AppSwcOpm_ARID_DEF.VCU_10_Torque_CHA_j.VCU_Actl_MotorRotateSpd = (uint16)(VOPM_ActlMotorRotateSpd_rpm - -10000.0F);
    }
    else
    {
      /* BusCreator: '<S156>/BusCreator' */
      AppSwcOpm_ARID_DEF.VCU_10_Torque_CHA_j.VCU_Actl_MotorRotateSpd = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S156>/BusCreator' */
    AppSwcOpm_ARID_DEF.VCU_10_Torque_CHA_j.VCU_Actl_MotorRotateSpd =
        MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<S156>/DataTypeConversion12' */

  /* BusCreator: '<S156>/BusCreator' incorporates:
   *  Switch: '<S159>/Switch4'
   */
  AppSwcOpm_ARID_DEF.VCU_10_Torque_CHA_j.VCU_Actl_MotorRotateSpdV =
      VOPM_ActlMotorRotateSpdVld_flg;

  /* DataTypeConversion: '<S156>/DataTypeConversion14' incorporates:
   *  Constant: '<S186>/Constant'
   *  Constant: '<S186>/Constant1'
   *  Product: '<S186>/Product1'
   *  Sum: '<S186>/Add'
   */
  tmp = (VOPM_ActlMotorTorq_Nm - -1000.0F) * 2.0F;
  if (tmp < 65536.0F)
  {
    if (tmp >= 0.0F)
    {
      /* BusCreator: '<S156>/BusCreator' */
      AppSwcOpm_ARID_DEF.VCU_10_Torque_CHA_j.VCU_Actl_MotorTorque = (uint16)tmp;
    }
    else
    {
      /* BusCreator: '<S156>/BusCreator' */
      AppSwcOpm_ARID_DEF.VCU_10_Torque_CHA_j.VCU_Actl_MotorTorque = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S156>/BusCreator' */
    AppSwcOpm_ARID_DEF.VCU_10_Torque_CHA_j.VCU_Actl_MotorTorque = MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<S156>/DataTypeConversion14' */

  /* BusCreator: '<S156>/BusCreator' incorporates:
   *  Switch: '<S161>/Switch4'
   */
  AppSwcOpm_ARID_DEF.VCU_10_Torque_CHA_j.VCU_Actl_MotorTorqueV =
      VOPM_ActlMotorTorqVld_flg;

  /* DataTypeConversion: '<S156>/DataTypeConversion16' incorporates:
   *  Constant: '<S187>/Constant'
   *  Constant: '<S187>/Constant1'
   *  Product: '<S187>/Product1'
   *  Sum: '<S187>/Add'
   */
  tmp = (VOPM_DrvReqMotorTorq_Nm - -1000.0F) * 2.0F;
  if (tmp < 65536.0F)
  {
    if (tmp >= 0.0F)
    {
      /* BusCreator: '<S156>/BusCreator' */
      AppSwcOpm_ARID_DEF.VCU_10_Torque_CHA_j.VCU_DrvReq_MotorTorq = (uint16)tmp;
    }
    else
    {
      /* BusCreator: '<S156>/BusCreator' */
      AppSwcOpm_ARID_DEF.VCU_10_Torque_CHA_j.VCU_DrvReq_MotorTorq = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S156>/BusCreator' */
    AppSwcOpm_ARID_DEF.VCU_10_Torque_CHA_j.VCU_DrvReq_MotorTorq = MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<S156>/DataTypeConversion16' */

  /* BusCreator: '<S156>/BusCreator' incorporates:
   *  Switch: '<S166>/Switch4'
   *  Switch: '<S175>/Switch4'
   *  Switch: '<S176>/Switch4'
   */
  AppSwcOpm_ARID_DEF.VCU_10_Torque_CHA_j.VCU_DrvReq_MotorTorqV =
      VOPM_DrvReqMotorTorqVld_flg;
  AppSwcOpm_ARID_DEF.VCU_10_Torque_CHA_j.VCU_EparkSysSta = false;
  AppSwcOpm_ARID_DEF.VCU_10_Torque_CHA_j.VCU_EnaEHBBrkRun =
      VOPM_VCUEnaEHBBrkRun_flg;
  AppSwcOpm_ARID_DEF.VCU_10_Torque_CHA_j.VCU_AccReqStandstill =
      VOPM_VCUAccReqStandstill_flg;
}

/* Output and update for function-call system: '<Root>/Opm20ms' */
static void Runbl_Opm20ms(void)
{
  float32 tmp;
  uint8 rtb_VCU_CruiseCtrlSta;

  /* Outputs for Atomic SubSystem: '<S314>/Subsys_VOPM_MotorOutputCooltTemp_C' */
  /* Switch: '<S322>/Switch4' incorporates:
   *  Constant: '<S314>/Constant'
   *  Constant: '<S322>/sat3'
   *  Constant: '<S322>/sat4'
   */
  if (KOPM_MotorOutputCooltTemp_C_ovrdflg)
  {
    VOPM_MotorOutputCooltTemp_C = KOPM_MotorOutputCooltTemp_C_ovrdval;
  }
  else
  {
    VOPM_MotorOutputCooltTemp_C = 0.0F;
  }

  /* MinMax: '<S322>/MinMax' incorporates:
   *  Constant: '<S322>/sat6'
   *  Switch: '<S322>/Switch4'
   */
  if (VOPM_MotorOutputCooltTemp_C > KOPM_MotorOutputCooltTempHi_C)
  {
    VOPM_MotorOutputCooltTemp_C = KOPM_MotorOutputCooltTempHi_C;
  }

  /* End of MinMax: '<S322>/MinMax' */

  /* MinMax: '<S322>/MinMax1' incorporates:
   *  Constant: '<S322>/sat7'
   */
  if (VOPM_MotorOutputCooltTemp_C < KOPM_MotorOutputCooltTempLo_C)
  {
    /* Switch: '<S322>/Switch4' incorporates:
     *  MinMax: '<S322>/MinMax1'
     */
    VOPM_MotorOutputCooltTemp_C = KOPM_MotorOutputCooltTempLo_C;
  }

  /* End of MinMax: '<S322>/MinMax1' */
  /* End of Outputs for SubSystem: '<S314>/Subsys_VOPM_MotorOutputCooltTemp_C' */

  /* Outputs for Atomic SubSystem: '<S314>/Subsys_VOPM_AllowHeatCoolMaxPwrCmsp_kW' */
  /* Switch: '<S318>/Switch4' incorporates:
   *  Constant: '<S318>/sat3'
   */
  if (KOPM_AllowHeatCoolMaxPwrCmsp_kW_ovrdflg)
  {
    /* MinMax: '<S318>/MinMax' incorporates:
     *  Constant: '<S318>/sat4'
     *  Product: '<S313>/Product1'
     */
    VOPM_VCUCruiseCtrTgtSpd_kph = KOPM_AllowHeatCoolMaxPwrCmsp_kW_ovrdval;
  }
  else
  {
    /* MinMax: '<S318>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S318>/Data Type Conversion1'
     *  Product: '<S313>/Product1'
     */
    VOPM_VCUCruiseCtrTgtSpd_kph =
        (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmEPT_outputs())
            ->VEMS_HeatCoolMaxPwrCmsp_kW;
  }

  /* End of Switch: '<S318>/Switch4' */

  /* MinMax: '<S318>/MinMax' incorporates:
   *  Constant: '<S318>/sat6'
   */
  if (VOPM_VCUCruiseCtrTgtSpd_kph > KOPM_AllowHeatCoolMaxPwrCmspHi_kW)
  {
    VOPM_VCUCruiseCtrTgtSpd_kph = KOPM_AllowHeatCoolMaxPwrCmspHi_kW;
  }

  /* MinMax: '<S318>/MinMax1' incorporates:
   *  Constant: '<S318>/sat7'
   */
  if (VOPM_VCUCruiseCtrTgtSpd_kph >= KOPM_AllowHeatCoolMaxPwrCmspLo_kW)
  {
    /* MinMax: '<S318>/MinMax1' */
    VOPM_AllowHeatCoolMaxPwrCmsp_kW = VOPM_VCUCruiseCtrTgtSpd_kph;
  }
  else
  {
    /* MinMax: '<S318>/MinMax1' */
    VOPM_AllowHeatCoolMaxPwrCmsp_kW = KOPM_AllowHeatCoolMaxPwrCmspLo_kW;
  }

  /* End of MinMax: '<S318>/MinMax1' */
  /* End of Outputs for SubSystem: '<S314>/Subsys_VOPM_AllowHeatCoolMaxPwrCmsp_kW' */

  /* Outputs for Atomic SubSystem: '<S314>/Subsys_VOPM_Bat2DrvTrainEnb_flg' */
  /* Switch: '<S320>/Switch4' incorporates:
   *  Constant: '<S320>/sat3'
   */
  if (KOPM_Bat2DrvTrainEnb_flg_ovrdflg)
  {
    /* Switch: '<S320>/Switch4' incorporates:
     *  Constant: '<S320>/sat4'
     */
    VOPM_Bat2DrvTrainEnb_flg = KOPM_Bat2DrvTrainEnb_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S320>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S320>/Data Type Conversion1'
     */
    VOPM_Bat2DrvTrainEnb_flg =
        (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmEPT_outputs())
            ->VHVM_Bat2DrvTrainEnbl_flg;
  }

  /* End of Switch: '<S320>/Switch4' */
  /* End of Outputs for SubSystem: '<S314>/Subsys_VOPM_Bat2DrvTrainEnb_flg' */

  /* Outputs for Atomic SubSystem: '<S314>/Subsys_VOPM_ChrgEnaAC_enum' */
  /* Switch: '<S321>/Switch4' incorporates:
   *  Constant: '<S321>/sat3'
   */
  if (KOPM_ChrgEnaAC_enum_ovrdflg)
  {
    /* DataTypeConversion: '<S278>/DataTypeConversion51' incorporates:
     *  Constant: '<S321>/sat4'
     *  DataTypeConversion: '<S321>/Data Type Conversion3'
     */
    rtb_VCU_CruiseCtrlSta = KOPM_ChrgEnaAC_enum_ovrdval;
  }
  else
  {
    /* DataTypeConversion: '<S278>/DataTypeConversion51' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S321>/Data Type Conversion1'
     */
    rtb_VCU_CruiseCtrlSta = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmEPT_outputs())->VHVM_ChrgEnaAC_enum;
  }

  /* End of Switch: '<S321>/Switch4' */

  /* MinMax: '<S321>/MinMax' incorporates:
   *  Constant: '<S321>/sat6'
   */
  if (rtb_VCU_CruiseCtrlSta > KOPM_ChrgEnaACHi_enum)
  {
    rtb_VCU_CruiseCtrlSta = KOPM_ChrgEnaACHi_enum;
  }

  /* End of MinMax: '<S321>/MinMax' */

  /* MinMax: '<S321>/MinMax1' incorporates:
   *  Constant: '<S321>/sat7'
   */
  if (rtb_VCU_CruiseCtrlSta >= KOPM_ChrgEnaACLo_enum)
  {
    /* DataTypeConversion: '<S321>/Data Type Conversion2' */
    VOPM_ChrgEnaAC_enum = rtb_VCU_CruiseCtrlSta;
  }
  else
  {
    /* DataTypeConversion: '<S321>/Data Type Conversion2' */
    VOPM_ChrgEnaAC_enum = KOPM_ChrgEnaACLo_enum;
  }

  /* End of MinMax: '<S321>/MinMax1' */
  /* End of Outputs for SubSystem: '<S314>/Subsys_VOPM_ChrgEnaAC_enum' */

  /* Outputs for Atomic SubSystem: '<S314>/Subsys_VOPM_BMSWakeupMode_enum' */
  /* Switch: '<S319>/Switch4' incorporates:
   *  Constant: '<S319>/sat3'
   */
  if (KOPM_BMSWakeupMode_enum_ovrdflg)
  {
    /* DataTypeConversion: '<S278>/DataTypeConversion51' incorporates:
     *  Constant: '<S319>/sat4'
     *  DataTypeConversion: '<S319>/Data Type Conversion3'
     */
    rtb_VCU_CruiseCtrlSta = KOPM_BMSWakeupMode_enum_ovrdval;
  }
  else
  {
    /* DataTypeConversion: '<S278>/DataTypeConversion51' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S319>/Data Type Conversion1'
     */
    rtb_VCU_CruiseCtrlSta = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmEPT_outputs())->VHVM_BMSWakeUpMode_enum;
  }

  /* End of Switch: '<S319>/Switch4' */

  /* MinMax: '<S319>/MinMax' incorporates:
   *  Constant: '<S319>/sat6'
   */
  if (rtb_VCU_CruiseCtrlSta > KOPM_BMSWakeupModeHi_enum)
  {
    rtb_VCU_CruiseCtrlSta = KOPM_BMSWakeupModeHi_enum;
  }

  /* End of MinMax: '<S319>/MinMax' */

  /* MinMax: '<S319>/MinMax1' incorporates:
   *  Constant: '<S319>/sat7'
   */
  if (rtb_VCU_CruiseCtrlSta >= KOPM_BMSWakeupModeLo_enum)
  {
    /* DataTypeConversion: '<S319>/Data Type Conversion2' */
    VOPM_BMSWakeupMode_enum = rtb_VCU_CruiseCtrlSta;
  }
  else
  {
    /* DataTypeConversion: '<S319>/Data Type Conversion2' */
    VOPM_BMSWakeupMode_enum = KOPM_BMSWakeupModeLo_enum;
  }

  /* End of MinMax: '<S319>/MinMax1' */
  /* End of Outputs for SubSystem: '<S314>/Subsys_VOPM_BMSWakeupMode_enum' */

  /* DataTypeConversion: '<S314>/DataTypeConversion' incorporates:
   *  Constant: '<S323>/Constant'
   *  Sum: '<S323>/Add'
   */
  if (VOPM_MotorOutputCooltTemp_C - -40.0F < 256.0F)
  {
    if (VOPM_MotorOutputCooltTemp_C - -40.0F >= 0.0F)
    {
      /* BusCreator: '<S314>/BusCreator' */
      AppSwcOpm_ARID_DEF.VCU_3_OprtCmd_EPT_k.VCU_MotoroutputCoolantTemp = (uint8)(VOPM_MotorOutputCooltTemp_C - -40.0F);
    }
    else
    {
      /* BusCreator: '<S314>/BusCreator' */
      AppSwcOpm_ARID_DEF.VCU_3_OprtCmd_EPT_k.VCU_MotoroutputCoolantTemp = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S314>/BusCreator' */
    AppSwcOpm_ARID_DEF.VCU_3_OprtCmd_EPT_k.VCU_MotoroutputCoolantTemp =
        MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S314>/DataTypeConversion' */

  /* DataTypeConversion: '<S314>/DataTypeConversion1' incorporates:
   *  Constant: '<S324>/Constant1'
   *  Product: '<S324>/Product1'
   *  Sum: '<S324>/Add'
   */
  tmp = VOPM_AllowHeatCoolMaxPwrCmsp_kW * 25.0F;
  if (tmp < 65536.0F)
  {
    if (tmp >= 0.0F)
    {
      /* BusCreator: '<S314>/BusCreator' */
      AppSwcOpm_ARID_DEF.VCU_3_OprtCmd_EPT_k.VCU_AllowHeatCoolMaxPwrCmsp =
          (uint16)tmp;
    }
    else
    {
      /* BusCreator: '<S314>/BusCreator' */
      AppSwcOpm_ARID_DEF.VCU_3_OprtCmd_EPT_k.VCU_AllowHeatCoolMaxPwrCmsp = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S314>/BusCreator' */
    AppSwcOpm_ARID_DEF.VCU_3_OprtCmd_EPT_k.VCU_AllowHeatCoolMaxPwrCmsp =
        MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<S314>/DataTypeConversion1' */

  /* BusCreator: '<S314>/BusCreator' incorporates:
   *  DataTypeConversion: '<S314>/DataTypeConversion3'
   *  DataTypeConversion: '<S314>/DataTypeConversion4'
   *  DataTypeConversion: '<S319>/Data Type Conversion2'
   *  DataTypeConversion: '<S321>/Data Type Conversion2'
   *  Switch: '<S320>/Switch4'
   */
  AppSwcOpm_ARID_DEF.VCU_3_OprtCmd_EPT_k.VCU_Bat2DrvTrainEnb =
      VOPM_Bat2DrvTrainEnb_flg;
  AppSwcOpm_ARID_DEF.VCU_3_OprtCmd_EPT_k.VCU_ChrgEna_AC = VOPM_ChrgEnaAC_enum;
  AppSwcOpm_ARID_DEF.VCU_3_OprtCmd_EPT_k.VCU_BMS_WakeupMode =
      VOPM_BMSWakeupMode_enum;

  /* Outputs for Atomic SubSystem: '<S315>/Subsys_VOPM_MaxChrgCurntDC_A' */
  /* Switch: '<S329>/Switch4' incorporates:
   *  Constant: '<S329>/sat3'
   */
  if (KOPM_MaxChrgCurntDC_A_ovrdflg)
  {
    /* MinMax: '<S318>/MinMax' incorporates:
     *  Constant: '<S329>/sat4'
     *  Product: '<S313>/Product1'
     */
    VOPM_VCUCruiseCtrTgtSpd_kph = KOPM_MaxChrgCurntDC_A_ovrdval;
  }
  else
  {
    /* MinMax: '<S318>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S329>/Data Type Conversion1'
     *  Product: '<S313>/Product1'
     */
    VOPM_VCUCruiseCtrTgtSpd_kph =
        (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmEPT_outputs())
            ->VHVM_MaxChrgCurntDC_A;
  }

  /* End of Switch: '<S329>/Switch4' */

  /* MinMax: '<S329>/MinMax' incorporates:
   *  Constant: '<S329>/sat6'
   */
  if (VOPM_VCUCruiseCtrTgtSpd_kph > KOPM_MaxChrgCurntDCHi_A)
  {
    /* MinMax: '<S318>/MinMax' */
    VOPM_VCUCruiseCtrTgtSpd_kph = KOPM_MaxChrgCurntDCHi_A;
  }

  /* End of MinMax: '<S329>/MinMax' */

  /* MinMax: '<S329>/MinMax1' incorporates:
   *  Constant: '<S329>/sat7'
   */
  if (VOPM_VCUCruiseCtrTgtSpd_kph >= KOPM_MaxChrgCurntDCLo_A)
  {
    /* MinMax: '<S329>/MinMax1' */
    VOPM_MaxChrgCurntDC_A = VOPM_VCUCruiseCtrTgtSpd_kph;
  }
  else
  {
    /* MinMax: '<S329>/MinMax1' */
    VOPM_MaxChrgCurntDC_A = KOPM_MaxChrgCurntDCLo_A;
  }

  /* End of MinMax: '<S329>/MinMax1' */
  /* End of Outputs for SubSystem: '<S315>/Subsys_VOPM_MaxChrgCurntDC_A' */

  /* Outputs for Atomic SubSystem: '<S315>/Subsys_VOPM_BMSShutdown_enum' */
  /* Switch: '<S325>/Switch4' incorporates:
   *  Constant: '<S325>/sat3'
   */
  if (KOPM_BMSShutdown_enum_ovrdflg)
  {
    /* DataTypeConversion: '<S278>/DataTypeConversion51' incorporates:
     *  Constant: '<S325>/sat4'
     *  DataTypeConversion: '<S325>/Data Type Conversion3'
     */
    rtb_VCU_CruiseCtrlSta = KOPM_BMSShutdown_enum_ovrdval;
  }
  else
  {
    /* DataTypeConversion: '<S278>/DataTypeConversion51' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S325>/Data Type Conversion1'
     */
    rtb_VCU_CruiseCtrlSta = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmEPT_outputs())->VHVM_BMSShutdown_enum;
  }

  /* End of Switch: '<S325>/Switch4' */

  /* MinMax: '<S325>/MinMax' incorporates:
   *  Constant: '<S325>/sat6'
   */
  if (rtb_VCU_CruiseCtrlSta > KOPM_BMSShutdownHi_enum)
  {
    rtb_VCU_CruiseCtrlSta = KOPM_BMSShutdownHi_enum;
  }

  /* End of MinMax: '<S325>/MinMax' */

  /* MinMax: '<S325>/MinMax1' incorporates:
   *  Constant: '<S325>/sat7'
   */
  if (rtb_VCU_CruiseCtrlSta >= KOPM_BMSShutdownLo_enum)
  {
    /* DataTypeConversion: '<S325>/Data Type Conversion2' */
    VOPM_BMSShutdown_enum = rtb_VCU_CruiseCtrlSta;
  }
  else
  {
    /* DataTypeConversion: '<S325>/Data Type Conversion2' */
    VOPM_BMSShutdown_enum = KOPM_BMSShutdownLo_enum;
  }

  /* End of MinMax: '<S325>/MinMax1' */
  /* End of Outputs for SubSystem: '<S315>/Subsys_VOPM_BMSShutdown_enum' */

  /* Outputs for Atomic SubSystem: '<S315>/Subsys_VOPM_ChrgAllowCmd_enum' */
  /* Switch: '<S326>/Switch4' incorporates:
   *  Constant: '<S326>/sat3'
   */
  if (KOPM_ChrgAllowCmd_enum_ovrdflg)
  {
    /* DataTypeConversion: '<S278>/DataTypeConversion51' incorporates:
     *  Constant: '<S326>/sat4'
     *  DataTypeConversion: '<S326>/Data Type Conversion3'
     */
    rtb_VCU_CruiseCtrlSta = KOPM_ChrgAllowCmd_enum_ovrdval;
  }
  else
  {
    /* DataTypeConversion: '<S278>/DataTypeConversion51' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S326>/Data Type Conversion1'
     */
    rtb_VCU_CruiseCtrlSta = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmEPT_outputs())->VHVM_ChrgAllowCmd_enum;
  }

  /* End of Switch: '<S326>/Switch4' */

  /* MinMax: '<S326>/MinMax' incorporates:
   *  Constant: '<S326>/sat6'
   */
  if (rtb_VCU_CruiseCtrlSta > KOPM_ChrgAllowCmdHi_enum)
  {
    rtb_VCU_CruiseCtrlSta = KOPM_ChrgAllowCmdHi_enum;
  }

  /* End of MinMax: '<S326>/MinMax' */

  /* MinMax: '<S326>/MinMax1' incorporates:
   *  Constant: '<S326>/sat7'
   */
  if (rtb_VCU_CruiseCtrlSta >= KOPM_ChrgAllowCmdLo_enum)
  {
    /* DataTypeConversion: '<S326>/Data Type Conversion2' */
    VOPM_ChrgAllowCmd_enum = rtb_VCU_CruiseCtrlSta;
  }
  else
  {
    /* DataTypeConversion: '<S326>/Data Type Conversion2' */
    VOPM_ChrgAllowCmd_enum = KOPM_ChrgAllowCmdLo_enum;
  }

  /* End of MinMax: '<S326>/MinMax1' */
  /* End of Outputs for SubSystem: '<S315>/Subsys_VOPM_ChrgAllowCmd_enum' */

  /* Outputs for Atomic SubSystem: '<S315>/Subsys_VOPM_ChrgEnaDC_flg' */
  /* Switch: '<S327>/Switch4' incorporates:
   *  Constant: '<S327>/sat3'
   */
  if (KOPM_ChrgEnaDC_flg_ovrdflg)
  {
    /* Switch: '<S327>/Switch4' incorporates:
     *  Constant: '<S327>/sat4'
     */
    VOPM_ChrgEnaDC_flg = KOPM_ChrgEnaDC_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S327>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S327>/Data Type Conversion1'
     */
    VOPM_ChrgEnaDC_flg = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmEPT_outputs())->VHVM_ChrgEnaDC_flg;
  }

  /* End of Switch: '<S327>/Switch4' */
  /* End of Outputs for SubSystem: '<S315>/Subsys_VOPM_ChrgEnaDC_flg' */

  /* Outputs for Atomic SubSystem: '<S315>/Subsys_VOPM_MaxChrgVoltDC_V' */
  /* Switch: '<S330>/Switch4' incorporates:
   *  Constant: '<S330>/sat3'
   */
  if (KOPM_MaxChrgVoltDC_V_ovrdflg)
  {
    /* MinMax: '<S318>/MinMax' incorporates:
     *  Constant: '<S330>/sat4'
     *  Product: '<S313>/Product1'
     */
    VOPM_VCUCruiseCtrTgtSpd_kph = KOPM_MaxChrgVoltDC_V_ovrdval;
  }
  else
  {
    /* MinMax: '<S318>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S330>/Data Type Conversion1'
     *  Product: '<S313>/Product1'
     */
    VOPM_VCUCruiseCtrTgtSpd_kph =
        (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmEPT_outputs())
            ->VHVM_MaxChrgVoltDC_V;
  }

  /* End of Switch: '<S330>/Switch4' */

  /* MinMax: '<S330>/MinMax' incorporates:
   *  Constant: '<S330>/sat6'
   */
  if (VOPM_VCUCruiseCtrTgtSpd_kph > KOPM_MaxChrgVoltDCHi_V)
  {
    /* MinMax: '<S318>/MinMax' */
    VOPM_VCUCruiseCtrTgtSpd_kph = KOPM_MaxChrgVoltDCHi_V;
  }

  /* End of MinMax: '<S330>/MinMax' */

  /* MinMax: '<S330>/MinMax1' incorporates:
   *  Constant: '<S330>/sat7'
   */
  if (VOPM_VCUCruiseCtrTgtSpd_kph >= KOPM_MaxChrgVoltDCLo_V)
  {
    /* MinMax: '<S330>/MinMax1' */
    VOPM_MaxChrgVoltDC_V = VOPM_VCUCruiseCtrTgtSpd_kph;
  }
  else
  {
    /* MinMax: '<S330>/MinMax1' */
    VOPM_MaxChrgVoltDC_V = KOPM_MaxChrgVoltDCLo_V;
  }

  /* End of MinMax: '<S330>/MinMax1' */
  /* End of Outputs for SubSystem: '<S315>/Subsys_VOPM_MaxChrgVoltDC_V' */

  /* Outputs for Atomic SubSystem: '<S315>/Subsys_VOPM_OBCOprtCmd_enum' */
  /* Switch: '<S331>/Switch4' incorporates:
   *  Constant: '<S331>/sat3'
   */
  if (KOPM_OBCOprtCmd_enum_ovrdflg)
  {
    /* DataTypeConversion: '<S278>/DataTypeConversion51' incorporates:
     *  Constant: '<S331>/sat4'
     *  DataTypeConversion: '<S331>/Data Type Conversion3'
     */
    rtb_VCU_CruiseCtrlSta = KOPM_OBCOprtCmd_enum_ovrdval;
  }
  else
  {
    /* DataTypeConversion: '<S278>/DataTypeConversion51' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S331>/Data Type Conversion1'
     */
    rtb_VCU_CruiseCtrlSta = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmEPT_outputs())->VHVM_OBCOprtCmd_enum;
  }

  /* End of Switch: '<S331>/Switch4' */

  /* MinMax: '<S331>/MinMax' incorporates:
   *  Constant: '<S331>/sat6'
   */
  if (rtb_VCU_CruiseCtrlSta > KOPM_OBCOprtCmdHi_enum)
  {
    rtb_VCU_CruiseCtrlSta = KOPM_OBCOprtCmdHi_enum;
  }

  /* End of MinMax: '<S331>/MinMax' */

  /* MinMax: '<S331>/MinMax1' incorporates:
   *  Constant: '<S331>/sat7'
   */
  if (rtb_VCU_CruiseCtrlSta >= KOPM_OBCOprtCmdLo_enum)
  {
    /* DataTypeConversion: '<S331>/Data Type Conversion2' */
    VOPM_OBCOprtCmd_enum = rtb_VCU_CruiseCtrlSta;
  }
  else
  {
    /* DataTypeConversion: '<S331>/Data Type Conversion2' */
    VOPM_OBCOprtCmd_enum = KOPM_OBCOprtCmdLo_enum;
  }

  /* End of MinMax: '<S331>/MinMax1' */
  /* End of Outputs for SubSystem: '<S315>/Subsys_VOPM_OBCOprtCmd_enum' */

  /* Outputs for Atomic SubSystem: '<S315>/Subsys_VOPM_MaxChrgCurntAC_A' */
  /* Switch: '<S328>/Switch4' incorporates:
   *  Constant: '<S328>/sat3'
   */
  if (KOPM_MaxChrgCurntAC_A_ovrdflg)
  {
    /* DataTypeConversion: '<S278>/DataTypeConversion51' incorporates:
     *  Constant: '<S328>/sat4'
     */
    rtb_VCU_CruiseCtrlSta = KOPM_MaxChrgCurntAC_A_ovrdval;
  }
  else
  {
    /* DataTypeConversion: '<S278>/DataTypeConversion51' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S328>/Data Type Conversion1'
     */
    rtb_VCU_CruiseCtrlSta = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmEPT_outputs())->VHVM_MaxChrgCurntAC_A;
  }

  /* End of Switch: '<S328>/Switch4' */

  /* MinMax: '<S328>/MinMax' incorporates:
   *  Constant: '<S328>/sat6'
   */
  if (rtb_VCU_CruiseCtrlSta > KOPM_MaxChrgCurntACHi_A)
  {
    rtb_VCU_CruiseCtrlSta = KOPM_MaxChrgCurntACHi_A;
  }

  /* End of MinMax: '<S328>/MinMax' */

  /* MinMax: '<S328>/MinMax1' incorporates:
   *  Constant: '<S328>/sat7'
   */
  if (rtb_VCU_CruiseCtrlSta >= KOPM_MaxChrgCurntACLo_A)
  {
    /* MinMax: '<S328>/MinMax1' */
    VOPM_MaxChrgCurntAC_A = rtb_VCU_CruiseCtrlSta;
  }
  else
  {
    /* MinMax: '<S328>/MinMax1' */
    VOPM_MaxChrgCurntAC_A = KOPM_MaxChrgCurntACLo_A;
  }

  /* End of MinMax: '<S328>/MinMax1' */
  /* End of Outputs for SubSystem: '<S315>/Subsys_VOPM_MaxChrgCurntAC_A' */

  /* BusCreator: '<S315>/BusCreator' incorporates:
   *  DataTypeConversion: '<S315>/DataTypeConversion'
   *  DataTypeConversion: '<S315>/DataTypeConversion1'
   *  DataTypeConversion: '<S325>/Data Type Conversion2'
   *  DataTypeConversion: '<S326>/Data Type Conversion2'
   *  Switch: '<S327>/Switch4'
   */
  AppSwcOpm_ARID_DEF.VCU_4_ChrgCmd_EPT_j.VCU_BMS_Shutdown =
      VOPM_BMSShutdown_enum;
  AppSwcOpm_ARID_DEF.VCU_4_ChrgCmd_EPT_j.VCU_ChrgAllowCmd =
      VOPM_ChrgAllowCmd_enum;
  AppSwcOpm_ARID_DEF.VCU_4_ChrgCmd_EPT_j.VCU_ChrgEna_DC = VOPM_ChrgEnaDC_flg;

  /* DataTypeConversion: '<S315>/DataTypeConversion3' incorporates:
   *  Constant: '<S332>/Constant1'
   *  Product: '<S332>/Product1'
   *  Sum: '<S332>/Add'
   */
  tmp = VOPM_MaxChrgCurntDC_A * 10.0F;
  if (tmp < 65536.0F)
  {
    if (tmp >= 0.0F)
    {
      /* BusCreator: '<S315>/BusCreator' */
      AppSwcOpm_ARID_DEF.VCU_4_ChrgCmd_EPT_j.VCU_MaxChrgCrnt_DC = (uint16)tmp;
    }
    else
    {
      /* BusCreator: '<S315>/BusCreator' */
      AppSwcOpm_ARID_DEF.VCU_4_ChrgCmd_EPT_j.VCU_MaxChrgCrnt_DC = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S315>/BusCreator' */
    AppSwcOpm_ARID_DEF.VCU_4_ChrgCmd_EPT_j.VCU_MaxChrgCrnt_DC = MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<S315>/DataTypeConversion3' */

  /* DataTypeConversion: '<S315>/DataTypeConversion4' incorporates:
   *  Constant: '<S333>/Constant1'
   *  Product: '<S333>/Product1'
   *  Sum: '<S333>/Add'
   */
  tmp = VOPM_MaxChrgVoltDC_V * 2.0F;
  if (tmp < 65536.0F)
  {
    if (tmp >= 0.0F)
    {
      /* BusCreator: '<S315>/BusCreator' */
      AppSwcOpm_ARID_DEF.VCU_4_ChrgCmd_EPT_j.VCU_MaxChrgVol_DC = (uint16)tmp;
    }
    else
    {
      /* BusCreator: '<S315>/BusCreator' */
      AppSwcOpm_ARID_DEF.VCU_4_ChrgCmd_EPT_j.VCU_MaxChrgVol_DC = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S315>/BusCreator' */
    AppSwcOpm_ARID_DEF.VCU_4_ChrgCmd_EPT_j.VCU_MaxChrgVol_DC = MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<S315>/DataTypeConversion4' */

  /* BusCreator: '<S315>/BusCreator' incorporates:
   *  DataTypeConversion: '<S315>/DataTypeConversion5'
   *  DataTypeConversion: '<S331>/Data Type Conversion2'
   */
  AppSwcOpm_ARID_DEF.VCU_4_ChrgCmd_EPT_j.VCU_OBCOprtCmd = VOPM_OBCOprtCmd_enum;
  AppSwcOpm_ARID_DEF.VCU_4_ChrgCmd_EPT_j.VCU_MaxChrgCurnt_AC =
      VOPM_MaxChrgCurntAC_A;

  /* Outputs for Atomic SubSystem: '<S316>/Subsys_VOPM_ErrAmount_cnt' */
  /* Switch: '<S335>/Switch4' incorporates:
   *  Constant: '<S335>/sat3'
   */
  if (KOPM_ErrAmount_cnt_ovrdflg)
  {
    /* DataTypeConversion: '<S278>/DataTypeConversion51' incorporates:
     *  Constant: '<S335>/sat4'
     */
    rtb_VCU_CruiseCtrlSta = KOPM_ErrAmount_cnt_ovrdval;
  }
  else
  {
    /* DataTypeConversion: '<S278>/DataTypeConversion51' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S335>/Data Type Conversion1'
     */
    rtb_VCU_CruiseCtrlSta = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmEPT_outputs())->VHVM_SysSta_enum;
  }

  /* End of Switch: '<S335>/Switch4' */

  /* MinMax: '<S335>/MinMax' incorporates:
   *  Constant: '<S335>/sat6'
   */
  if (rtb_VCU_CruiseCtrlSta > KOPM_ErrAmountHi_cnt)
  {
    rtb_VCU_CruiseCtrlSta = KOPM_ErrAmountHi_cnt;
  }

  /* End of MinMax: '<S335>/MinMax' */

  /* MinMax: '<S335>/MinMax1' incorporates:
   *  Constant: '<S335>/sat7'
   */
  if (rtb_VCU_CruiseCtrlSta >= KOPM_ErrAmountLo_cnt)
  {
    /* MinMax: '<S335>/MinMax1' */
    VOPM_ErrAmount_cnt = rtb_VCU_CruiseCtrlSta;
  }
  else
  {
    /* MinMax: '<S335>/MinMax1' */
    VOPM_ErrAmount_cnt = KOPM_ErrAmountLo_cnt;
  }

  /* End of MinMax: '<S335>/MinMax1' */
  /* End of Outputs for SubSystem: '<S316>/Subsys_VOPM_ErrAmount_cnt' */

  /* Outputs for Atomic SubSystem: '<S316>/Subsys_VOPM_DCCOprtCmd_enum' */
  /* Switch: '<S334>/Switch4' incorporates:
   *  Constant: '<S334>/sat3'
   */
  if (KOPM_DCCOprtCmd_enum_ovrdflg)
  {
    /* DataTypeConversion: '<S278>/DataTypeConversion51' incorporates:
     *  Constant: '<S334>/sat4'
     *  DataTypeConversion: '<S334>/Data Type Conversion3'
     */
    rtb_VCU_CruiseCtrlSta = KOPM_DCCOprtCmd_enum_ovrdval;
  }
  else
  {
    /* DataTypeConversion: '<S278>/DataTypeConversion51' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S334>/Data Type Conversion1'
     */
    rtb_VCU_CruiseCtrlSta = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmEPT_outputs())->VHVM_DCCOprtCmd_enum;
  }

  /* End of Switch: '<S334>/Switch4' */

  /* MinMax: '<S334>/MinMax' incorporates:
   *  Constant: '<S334>/sat6'
   */
  if (rtb_VCU_CruiseCtrlSta > KOPM_DCCOprtCmdHi_enum)
  {
    rtb_VCU_CruiseCtrlSta = KOPM_DCCOprtCmdHi_enum;
  }

  /* End of MinMax: '<S334>/MinMax' */

  /* MinMax: '<S334>/MinMax1' incorporates:
   *  Constant: '<S334>/sat7'
   */
  if (rtb_VCU_CruiseCtrlSta >= KOPM_DCCOprtCmdLo_enum)
  {
    /* DataTypeConversion: '<S334>/Data Type Conversion2' */
    VOPM_DCCOprtCmd_enum = rtb_VCU_CruiseCtrlSta;
  }
  else
  {
    /* DataTypeConversion: '<S334>/Data Type Conversion2' */
    VOPM_DCCOprtCmd_enum = KOPM_DCCOprtCmdLo_enum;
  }

  /* End of MinMax: '<S334>/MinMax1' */
  /* End of Outputs for SubSystem: '<S316>/Subsys_VOPM_DCCOprtCmd_enum' */

  /* Outputs for Atomic SubSystem: '<S316>/Subsys_VOPM_SysFailSta_enum' */
  /* Switch: '<S337>/Switch4' incorporates:
   *  Constant: '<S337>/sat3'
   */
  if (KOPM_SysFailSta_enum_ovrdflg)
  {
    /* DataTypeConversion: '<S278>/DataTypeConversion51' incorporates:
     *  Constant: '<S337>/sat4'
     */
    rtb_VCU_CruiseCtrlSta = KOPM_SysFailSta_enum_ovrdval;
  }
  else
  {
    /* DataTypeConversion: '<S278>/DataTypeConversion51' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S337>/Data Type Conversion1'
     */
    rtb_VCU_CruiseCtrlSta = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmEPT_outputs())->VDAG_VCUFltLvl_enum;
  }

  /* End of Switch: '<S337>/Switch4' */

  /* MinMax: '<S337>/MinMax' incorporates:
   *  Constant: '<S337>/sat6'
   */
  if (rtb_VCU_CruiseCtrlSta > KOPM_SysFailStaHi_enum)
  {
    rtb_VCU_CruiseCtrlSta = KOPM_SysFailStaHi_enum;
  }

  /* End of MinMax: '<S337>/MinMax' */

  /* MinMax: '<S337>/MinMax1' incorporates:
   *  Constant: '<S337>/sat7'
   */
  if (rtb_VCU_CruiseCtrlSta >= KOPM_SysFailStaLo_enum)
  {
    /* MinMax: '<S337>/MinMax1' */
    VOPM_SysFailSta_enum = rtb_VCU_CruiseCtrlSta;
  }
  else
  {
    /* MinMax: '<S337>/MinMax1' */
    VOPM_SysFailSta_enum = KOPM_SysFailStaLo_enum;
  }

  /* End of MinMax: '<S337>/MinMax1' */
  /* End of Outputs for SubSystem: '<S316>/Subsys_VOPM_SysFailSta_enum' */

  /* Outputs for Atomic SubSystem: '<S316>/Subsys_VOPM_ErrBit_nu' */
  /* Switch: '<S336>/Switch4' incorporates:
   *  Constant: '<S336>/sat3'
   */
  if (KOPM_ErrBit_nu_ovrdflg)
  {
    /* MinMax: '<S336>/MinMax' incorporates:
     *  Constant: '<S336>/sat4'
     *  DataTypeConversion: '<S278>/DataTypeConversion48'
     */
    VOPM_ErrBit_nu = KOPM_ErrBit_nu_ovrdval;
  }
  else
  {
    /* MinMax: '<S336>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S278>/DataTypeConversion48'
     *  DataTypeConversion: '<S336>/Data Type Conversion1'
     */
    VOPM_ErrBit_nu = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmEPT_outputs())
                         ->VDAG_VCUErrCode_enum;
  }

  /* End of Switch: '<S336>/Switch4' */

  /* MinMax: '<S336>/MinMax' incorporates:
   *  Constant: '<S336>/sat6'
   */
  if (VOPM_ErrBit_nu > KOPM_ErrBitHi_nu)
  {
    VOPM_ErrBit_nu = KOPM_ErrBitHi_nu;
  }

  /* MinMax: '<S336>/MinMax1' incorporates:
   *  Constant: '<S336>/sat7'
   */
  if (VOPM_ErrBit_nu < KOPM_ErrBitLo_nu)
  {
    /* MinMax: '<S336>/MinMax' incorporates:
     *  MinMax: '<S336>/MinMax1'
     */
    VOPM_ErrBit_nu = KOPM_ErrBitLo_nu;
  }

  /* End of MinMax: '<S336>/MinMax1' */
  /* End of Outputs for SubSystem: '<S316>/Subsys_VOPM_ErrBit_nu' */

  /* BusCreator: '<S316>/BusCreator' incorporates:
   *  Constant: '<S316>/Constant'
   *  DataTypeConversion: '<S316>/DataTypeConversion2'
   *  DataTypeConversion: '<S334>/Data Type Conversion2'
   */
  AppSwcOpm_ARID_DEF.VCU_B_AcclPedal_EPT_e.VCU_ErrAmount = VOPM_ErrAmount_cnt;
  AppSwcOpm_ARID_DEF.VCU_B_AcclPedal_EPT_e.VCU_EPK_ParkLock = 0U;
  AppSwcOpm_ARID_DEF.VCU_B_AcclPedal_EPT_e.VCU_DCCOprtCmd = VOPM_DCCOprtCmd_enum;
  AppSwcOpm_ARID_DEF.VCU_B_AcclPedal_EPT_e.VCU_SysFailSta = VOPM_SysFailSta_enum;
  AppSwcOpm_ARID_DEF.VCU_B_AcclPedal_EPT_e.VCU_ErrBit = VOPM_ErrBit_nu;

  /* Outputs for Atomic SubSystem: '<S317>/Subsys_VOPM_OBCIntDchrgEna_flg' */
  /* Switch: '<S342>/Switch4' incorporates:
   *  Constant: '<S342>/sat3'
   *  Constant: '<S342>/sat4'
   */
  VOPM_OBCIntDchrgEna_flg = (KOPM_OBCIntDchrgEna_flg_ovrdflg &&
                             KOPM_OBCIntDchrgEna_flg_ovrdval);

  /* End of Outputs for SubSystem: '<S317>/Subsys_VOPM_OBCIntDchrgEna_flg' */

  /* Outputs for Atomic SubSystem: '<S317>/Subsys_VOPM_DCCBuckLVVolt_V' */
  /* Switch: '<S339>/Switch4' incorporates:
   *  Constant: '<S339>/sat3'
   */
  if (KOPM_DCCBuckLVVolt_V_ovrdflg)
  {
    /* MinMax: '<S318>/MinMax' incorporates:
     *  Constant: '<S339>/sat4'
     *  Product: '<S313>/Product1'
     */
    VOPM_VCUCruiseCtrTgtSpd_kph = KOPM_DCCBuckLVVolt_V_ovrdval;
  }
  else
  {
    /* MinMax: '<S318>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S339>/Data Type Conversion1'
     *  Product: '<S313>/Product1'
     */
    VOPM_VCUCruiseCtrTgtSpd_kph =
        (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmEPT_outputs())
            ->VHVM_DCCBuckLVVolt_V;
  }

  /* End of Switch: '<S339>/Switch4' */

  /* MinMax: '<S339>/MinMax' incorporates:
   *  Constant: '<S339>/sat6'
   */
  if (VOPM_VCUCruiseCtrTgtSpd_kph > KOPM_DCCBuckLVVoltHi_V)
  {
    /* MinMax: '<S318>/MinMax' */
    VOPM_VCUCruiseCtrTgtSpd_kph = KOPM_DCCBuckLVVoltHi_V;
  }

  /* End of MinMax: '<S339>/MinMax' */

  /* MinMax: '<S339>/MinMax1' incorporates:
   *  Constant: '<S339>/sat7'
   */
  if (VOPM_VCUCruiseCtrTgtSpd_kph >= KOPM_DCCBuckLVVoltLo_V)
  {
    /* MinMax: '<S339>/MinMax1' */
    VOPM_DCCBuckLVVolt_V = VOPM_VCUCruiseCtrTgtSpd_kph;
  }
  else
  {
    /* MinMax: '<S339>/MinMax1' */
    VOPM_DCCBuckLVVolt_V = KOPM_DCCBuckLVVoltLo_V;
  }

  /* End of MinMax: '<S339>/MinMax1' */
  /* End of Outputs for SubSystem: '<S317>/Subsys_VOPM_DCCBuckLVVolt_V' */

  /* Outputs for Atomic SubSystem: '<S317>/Subsys_VOPM_DCCBoostHvVolt_V' */
  /* Switch: '<S338>/Switch4' incorporates:
   *  Constant: '<S317>/Constant1'
   *  Constant: '<S338>/sat3'
   *  Constant: '<S338>/sat4'
   */
  if (KOPM_DCCBoostHvVolt_V_ovrdflg)
  {
    VOPM_DCCBoostHvVolt_V = KOPM_DCCBoostHvVolt_V_ovrdval;
  }
  else
  {
    VOPM_DCCBoostHvVolt_V = 0.0F;
  }

  /* MinMax: '<S338>/MinMax' incorporates:
   *  Constant: '<S338>/sat6'
   *  Switch: '<S338>/Switch4'
   */
  if (VOPM_DCCBoostHvVolt_V > KOPM_DCCBoostHvVoltHi_V)
  {
    VOPM_DCCBoostHvVolt_V = KOPM_DCCBoostHvVoltHi_V;
  }

  /* End of MinMax: '<S338>/MinMax' */

  /* MinMax: '<S338>/MinMax1' incorporates:
   *  Constant: '<S338>/sat7'
   */
  if (VOPM_DCCBoostHvVolt_V < KOPM_DCCBoostHvVoltLo_V)
  {
    /* Switch: '<S338>/Switch4' incorporates:
     *  MinMax: '<S338>/MinMax1'
     */
    VOPM_DCCBoostHvVolt_V = KOPM_DCCBoostHvVoltLo_V;
  }

  /* End of MinMax: '<S338>/MinMax1' */
  /* End of Outputs for SubSystem: '<S317>/Subsys_VOPM_DCCBoostHvVolt_V' */

  /* Outputs for Atomic SubSystem: '<S317>/Subsys_VOPM_MaxHVDCCurntAC_A' */
  /* Switch: '<S340>/Switch4' incorporates:
   *  Constant: '<S340>/sat3'
   */
  if (KOPM_MaxHVDCCurntAC_A_ovrdflg)
  {
    /* MinMax: '<S318>/MinMax' incorporates:
     *  Constant: '<S340>/sat4'
     *  Product: '<S313>/Product1'
     */
    VOPM_VCUCruiseCtrTgtSpd_kph = KOPM_MaxHVDCCurntAC_A_ovrdval;
  }
  else
  {
    /* MinMax: '<S318>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S340>/Data Type Conversion1'
     *  Product: '<S313>/Product1'
     */
    VOPM_VCUCruiseCtrTgtSpd_kph =
        (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmEPT_outputs())
            ->VHVM_MaxHVDCCurntAC_A;
  }

  /* End of Switch: '<S340>/Switch4' */

  /* MinMax: '<S340>/MinMax' incorporates:
   *  Constant: '<S340>/sat6'
   */
  if (VOPM_VCUCruiseCtrTgtSpd_kph > KOPM_MaxHVDCCurntACHi_A)
  {
    /* MinMax: '<S318>/MinMax' */
    VOPM_VCUCruiseCtrTgtSpd_kph = KOPM_MaxHVDCCurntACHi_A;
  }

  /* End of MinMax: '<S340>/MinMax' */

  /* MinMax: '<S340>/MinMax1' incorporates:
   *  Constant: '<S340>/sat7'
   */
  if (VOPM_VCUCruiseCtrTgtSpd_kph >= KOPM_MaxHVDCCurntACLo_A)
  {
    /* MinMax: '<S340>/MinMax1' */
    VOPM_MaxHVDCCurntAC_A = VOPM_VCUCruiseCtrTgtSpd_kph;
  }
  else
  {
    /* MinMax: '<S340>/MinMax1' */
    VOPM_MaxHVDCCurntAC_A = KOPM_MaxHVDCCurntACLo_A;
  }

  /* End of MinMax: '<S340>/MinMax1' */
  /* End of Outputs for SubSystem: '<S317>/Subsys_VOPM_MaxHVDCCurntAC_A' */

  /* Outputs for Atomic SubSystem: '<S317>/Subsys_VOPM_MaxHVDCVoltAC_V' */
  /* Switch: '<S341>/Switch4' incorporates:
   *  Constant: '<S341>/sat3'
   */
  if (KOPM_MaxHVDCVoltAC_V_ovrdflg)
  {
    /* MinMax: '<S318>/MinMax' incorporates:
     *  Constant: '<S341>/sat4'
     *  Product: '<S313>/Product1'
     */
    VOPM_VCUCruiseCtrTgtSpd_kph = KOPM_MaxHVDCVoltAC_V_ovrdval;
  }
  else
  {
    /* MinMax: '<S318>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S341>/Data Type Conversion1'
     *  Product: '<S313>/Product1'
     */
    VOPM_VCUCruiseCtrTgtSpd_kph =
        (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmEPT_outputs())
            ->VHVM_MaxHVDCVoltAC_V;
  }

  /* End of Switch: '<S341>/Switch4' */

  /* MinMax: '<S341>/MinMax' incorporates:
   *  Constant: '<S341>/sat6'
   */
  if (VOPM_VCUCruiseCtrTgtSpd_kph > KOPM_MaxHVDCVoltACHi_V)
  {
    /* MinMax: '<S318>/MinMax' */
    VOPM_VCUCruiseCtrTgtSpd_kph = KOPM_MaxHVDCVoltACHi_V;
  }

  /* End of MinMax: '<S341>/MinMax' */

  /* MinMax: '<S341>/MinMax1' incorporates:
   *  Constant: '<S341>/sat7'
   */
  if (VOPM_VCUCruiseCtrTgtSpd_kph >= KOPM_MaxHVDCVoltACLo_V)
  {
    /* MinMax: '<S341>/MinMax1' */
    VOPM_MaxHVDCVoltAC_V = VOPM_VCUCruiseCtrTgtSpd_kph;
  }
  else
  {
    /* MinMax: '<S341>/MinMax1' */
    VOPM_MaxHVDCVoltAC_V = KOPM_MaxHVDCVoltACLo_V;
  }

  /* End of MinMax: '<S341>/MinMax1' */
  /* End of Outputs for SubSystem: '<S317>/Subsys_VOPM_MaxHVDCVoltAC_V' */

  /* DataTypeConversion: '<S317>/DataTypeConversion' incorporates:
   *  Constant: '<S343>/Constant1'
   *  Product: '<S343>/Product1'
   *  Sum: '<S343>/Add'
   */
  tmp = VOPM_DCCBuckLVVolt_V * 10.0F;
  if (tmp < 256.0F)
  {
    if (tmp >= 0.0F)
    {
      /* BusCreator: '<S317>/BusCreator' */
      AppSwcOpm_ARID_DEF.VCU_C_OprtCmd_EPT_m.VCU_DCCBuckLV_Vol = (uint8)tmp;
    }
    else
    {
      /* BusCreator: '<S317>/BusCreator' */
      AppSwcOpm_ARID_DEF.VCU_C_OprtCmd_EPT_m.VCU_DCCBuckLV_Vol = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S317>/BusCreator' */
    AppSwcOpm_ARID_DEF.VCU_C_OprtCmd_EPT_m.VCU_DCCBuckLV_Vol = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S317>/DataTypeConversion' */

  /* BusCreator: '<S317>/BusCreator' incorporates:
   *  Switch: '<S342>/Switch4'
   */
  AppSwcOpm_ARID_DEF.VCU_C_OprtCmd_EPT_m.VCU_OBCIntDischargeEnable =
      VOPM_OBCIntDchrgEna_flg;

  /* DataTypeConversion: '<S317>/DataTypeConversion2' incorporates:
   *  Constant: '<S344>/Constant1'
   *  Product: '<S344>/Product1'
   *  Sum: '<S344>/Add'
   */
  tmp = VOPM_DCCBoostHvVolt_V * 2.0F;
  if (tmp < 65536.0F)
  {
    if (tmp >= 0.0F)
    {
      /* BusCreator: '<S317>/BusCreator' */
      AppSwcOpm_ARID_DEF.VCU_C_OprtCmd_EPT_m.VCU_DCCBoostHv_Vol = (uint16)tmp;
    }
    else
    {
      /* BusCreator: '<S317>/BusCreator' */
      AppSwcOpm_ARID_DEF.VCU_C_OprtCmd_EPT_m.VCU_DCCBoostHv_Vol = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S317>/BusCreator' */
    AppSwcOpm_ARID_DEF.VCU_C_OprtCmd_EPT_m.VCU_DCCBoostHv_Vol = MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<S317>/DataTypeConversion2' */

  /* DataTypeConversion: '<S317>/DataTypeConversion3' incorporates:
   *  Constant: '<S345>/Constant1'
   *  Product: '<S345>/Product1'
   *  Sum: '<S345>/Add'
   */
  tmp = VOPM_MaxHVDCCurntAC_A * 10.0F;
  if (tmp < 65536.0F)
  {
    if (tmp >= 0.0F)
    {
      /* BusCreator: '<S317>/BusCreator' */
      AppSwcOpm_ARID_DEF.VCU_C_OprtCmd_EPT_m.VCU_MaxHVDC_Cur_AC = (uint16)tmp;
    }
    else
    {
      /* BusCreator: '<S317>/BusCreator' */
      AppSwcOpm_ARID_DEF.VCU_C_OprtCmd_EPT_m.VCU_MaxHVDC_Cur_AC = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S317>/BusCreator' */
    AppSwcOpm_ARID_DEF.VCU_C_OprtCmd_EPT_m.VCU_MaxHVDC_Cur_AC = MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<S317>/DataTypeConversion3' */

  /* DataTypeConversion: '<S317>/DataTypeConversion4' incorporates:
   *  Constant: '<S346>/Constant1'
   *  Product: '<S346>/Product1'
   *  Sum: '<S346>/Add'
   */
  tmp = VOPM_MaxHVDCVoltAC_V * 2.0F;
  if (tmp < 65536.0F)
  {
    if (tmp >= 0.0F)
    {
      /* BusCreator: '<S317>/BusCreator' */
      AppSwcOpm_ARID_DEF.VCU_C_OprtCmd_EPT_m.VCU_MaxHVDC_Vol_AC = (uint16)tmp;
    }
    else
    {
      /* BusCreator: '<S317>/BusCreator' */
      AppSwcOpm_ARID_DEF.VCU_C_OprtCmd_EPT_m.VCU_MaxHVDC_Vol_AC = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S317>/BusCreator' */
    AppSwcOpm_ARID_DEF.VCU_C_OprtCmd_EPT_m.VCU_MaxHVDC_Vol_AC = MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<S317>/DataTypeConversion4' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_CruiseCtrTgtSpd_kph' */
  /* Switch: '<S227>/Switch4' incorporates:
   *  Constant: '<S227>/sat3'
   */
  if (KOPM_CruiseCtrTgtSpd_kph_ovrdflg)
  {
    /* MinMax: '<S318>/MinMax' incorporates:
     *  Constant: '<S227>/sat4'
     *  Product: '<S313>/Product1'
     */
    VOPM_VCUCruiseCtrTgtSpd_kph = KOPM_CruiseCtrTgtSpd_kph_ovrdval;
  }
  else
  {
    /* MinMax: '<S318>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S227>/Data Type Conversion1'
     *  Product: '<S313>/Product1'
     */
    VOPM_VCUCruiseCtrTgtSpd_kph =
        (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs())->VVTM_CCTgtSpd_kph;
  }

  /* End of Switch: '<S227>/Switch4' */

  /* MinMax: '<S227>/MinMax' incorporates:
   *  Constant: '<S227>/sat6'
   */
  if (VOPM_VCUCruiseCtrTgtSpd_kph > KOPM_CruiseCtrTgtSpdHi_kph)
  {
    /* MinMax: '<S318>/MinMax' */
    VOPM_VCUCruiseCtrTgtSpd_kph = KOPM_CruiseCtrTgtSpdHi_kph;
  }

  /* End of MinMax: '<S227>/MinMax' */

  /* MinMax: '<S227>/MinMax1' incorporates:
   *  Constant: '<S227>/sat7'
   */
  if (VOPM_VCUCruiseCtrTgtSpd_kph >= KOPM_CruiseCtrTgtSpdLo_kph)
  {
    /* MinMax: '<S227>/MinMax1' */
    VOPM_CruiseCtrTgtSpd_kph = VOPM_VCUCruiseCtrTgtSpd_kph;
  }
  else
  {
    /* MinMax: '<S227>/MinMax1' */
    VOPM_CruiseCtrTgtSpd_kph = KOPM_CruiseCtrTgtSpdLo_kph;
  }

  /* End of MinMax: '<S227>/MinMax1' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_CruiseCtrTgtSpd_kph' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_MotActPwrTyp_enum1' */
  /* Switch: '<S236>/Switch4' incorporates:
   *  Constant: '<S236>/sat3'
   */
  if (KOPM_MotActPwrTyp_enum_ovrdflg)
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  Constant: '<S236>/sat4'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = KOPM_MotActPwrTyp_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S236>/Data Type Conversion1'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = (uint8)(Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs())
                               ->VVTM_MotorActlPwrType_flg;
  }

  /* End of Switch: '<S236>/Switch4' */

  /* MinMax: '<S236>/MinMax' incorporates:
   *  Constant: '<S236>/sat6'
   */
  if (VOPM_VCUACCStat_enum > KOPM_MotActPwrTypHi_enum)
  {
    VOPM_VCUACCStat_enum = KOPM_MotActPwrTypHi_enum;
  }

  /* MinMax: '<S236>/MinMax1' incorporates:
   *  Constant: '<S236>/sat7'
   */
  if (VOPM_VCUACCStat_enum >= KOPM_MotActPwrTypLo_enum)
  {
    /* MinMax: '<S236>/MinMax1' */
    VOPM_MotActPwrTyp_enum = VOPM_VCUACCStat_enum;
  }
  else
  {
    /* MinMax: '<S236>/MinMax1' */
    VOPM_MotActPwrTyp_enum = KOPM_MotActPwrTypLo_enum;
  }

  /* End of MinMax: '<S236>/MinMax1' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_MotActPwrTyp_enum1' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_DrvRangeDistEstVld_flg1' */
  /* Switch: '<S231>/Switch4' incorporates:
   *  Constant: '<S231>/sat3'
   */
  if (KOPM_DrvRangeDistEstVld_flg_ovrdflg)
  {
    /* Switch: '<S231>/Switch4' incorporates:
     *  Constant: '<S231>/sat4'
     */
    VOPM_DrvRangeDistEstVld_flg = KOPM_DrvRangeDistEstVld_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S231>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S231>/Data Type Conversion1'
     */
    VOPM_DrvRangeDistEstVld_flg =
        (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs())
            ->VRME_CHTCRmnMilEstV_flg;
  }

  /* End of Switch: '<S231>/Switch4' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_DrvRangeDistEstVld_flg1' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_DrvRangeDistEst_km1' */
  /* Switch: '<S232>/Switch4' incorporates:
   *  Constant: '<S232>/sat3'
   */
  if (KOPM_DrvRangeDistEst_km_ovrdflg)
  {
    /* MinMax: '<S318>/MinMax' incorporates:
     *  Constant: '<S232>/sat4'
     *  Product: '<S313>/Product1'
     */
    VOPM_VCUCruiseCtrTgtSpd_kph = KOPM_DrvRangeDistEst_km_ovrdval;
  }
  else
  {
    /* MinMax: '<S318>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S232>/Data Type Conversion1'
     *  Product: '<S313>/Product1'
     */
    VOPM_VCUCruiseCtrTgtSpd_kph =
        (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs())
            ->VRME_CHTCRmnMilEst_km;
  }

  /* End of Switch: '<S232>/Switch4' */

  /* MinMax: '<S232>/MinMax' incorporates:
   *  Constant: '<S232>/sat6'
   */
  if (VOPM_VCUCruiseCtrTgtSpd_kph > KOPM_DrvRangeDistEstHi_km)
  {
    /* MinMax: '<S318>/MinMax' */
    VOPM_VCUCruiseCtrTgtSpd_kph = KOPM_DrvRangeDistEstHi_km;
  }

  /* End of MinMax: '<S232>/MinMax' */

  /* MinMax: '<S232>/MinMax1' incorporates:
   *  Constant: '<S232>/sat7'
   */
  if (VOPM_VCUCruiseCtrTgtSpd_kph >= KOPM_DrvRangeDistEstLo_km)
  {
    /* MinMax: '<S232>/MinMax1' */
    VOPM_DrvRangeDistEst_km = VOPM_VCUCruiseCtrTgtSpd_kph;
  }
  else
  {
    /* MinMax: '<S232>/MinMax1' */
    VOPM_DrvRangeDistEst_km = KOPM_DrvRangeDistEstLo_km;
  }

  /* End of MinMax: '<S232>/MinMax1' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_DrvRangeDistEst_km1' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_WLTPDrvgRngDstVld_flg1' */
  /* Switch: '<S267>/Switch4' incorporates:
   *  Constant: '<S267>/sat3'
   */
  if (KOPM_WLTPDrvgRngDstVld_flg_ovrdflg)
  {
    /* Switch: '<S267>/Switch4' incorporates:
     *  Constant: '<S267>/sat4'
     */
    VOPM_WLTPDrvgRngDstVld_flg = KOPM_WLTPDrvgRngDstVld_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S267>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S267>/Data Type Conversion1'
     */
    VOPM_WLTPDrvgRngDstVld_flg =
        (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs())
            ->VRME_DynRmnMilEstV_flg;
  }

  /* End of Switch: '<S267>/Switch4' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_WLTPDrvgRngDstVld_flg1' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_WLTPDrvgRngDst_km1' */
  /* Switch: '<S268>/Switch4' incorporates:
   *  Constant: '<S268>/sat3'
   */
  if (KOPM_WLTPDrvgRngDst_km_ovrdflg)
  {
    /* MinMax: '<S318>/MinMax' incorporates:
     *  Constant: '<S268>/sat4'
     *  Product: '<S313>/Product1'
     */
    VOPM_VCUCruiseCtrTgtSpd_kph = KOPM_WLTPDrvgRngDst_km_ovrdval;
  }
  else
  {
    /* MinMax: '<S318>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S268>/Data Type Conversion1'
     *  Product: '<S313>/Product1'
     */
    VOPM_VCUCruiseCtrTgtSpd_kph =
        (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs())
            ->VRME_DynRmnMilEst_km;
  }

  /* End of Switch: '<S268>/Switch4' */

  /* MinMax: '<S268>/MinMax' incorporates:
   *  Constant: '<S268>/sat6'
   */
  if (VOPM_VCUCruiseCtrTgtSpd_kph > KOPM_WLTPDrvgRngDstHi_km)
  {
    /* MinMax: '<S318>/MinMax' */
    VOPM_VCUCruiseCtrTgtSpd_kph = KOPM_WLTPDrvgRngDstHi_km;
  }

  /* End of MinMax: '<S268>/MinMax' */

  /* MinMax: '<S268>/MinMax1' incorporates:
   *  Constant: '<S268>/sat7'
   */
  if (VOPM_VCUCruiseCtrTgtSpd_kph >= KOPM_WLTPDrvgRngDstLo_km)
  {
    /* MinMax: '<S268>/MinMax1' */
    VOPM_WLTPDrvgRngDst_km = VOPM_VCUCruiseCtrTgtSpd_kph;
  }
  else
  {
    /* MinMax: '<S268>/MinMax1' */
    VOPM_WLTPDrvgRngDst_km = KOPM_WLTPDrvgRngDstLo_km;
  }

  /* End of MinMax: '<S268>/MinMax1' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_WLTPDrvgRngDst_km1' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_RsrvdPwr_kW1' */
  /* Switch: '<S246>/Switch4' incorporates:
   *  Constant: '<S246>/sat3'
   */
  if (KOPM_RsrvdPwr_kW_ovrdflg)
  {
    /* MinMax: '<S318>/MinMax' incorporates:
     *  Constant: '<S246>/sat4'
     *  Product: '<S313>/Product1'
     */
    VOPM_VCUCruiseCtrTgtSpd_kph = KOPM_RsrvdPwr_kW_ovrdval;
  }
  else
  {
    /* MinMax: '<S318>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S246>/Data Type Conversion1'
     *  Product: '<S313>/Product1'
     */
    VOPM_VCUCruiseCtrTgtSpd_kph =
        (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs())->VVTM_RsrvPwr_kW;
  }

  /* End of Switch: '<S246>/Switch4' */

  /* MinMax: '<S246>/MinMax' incorporates:
   *  Constant: '<S246>/sat6'
   */
  if (VOPM_VCUCruiseCtrTgtSpd_kph > KOPM_RsrvdPwrHi_kW)
  {
    /* MinMax: '<S318>/MinMax' */
    VOPM_VCUCruiseCtrTgtSpd_kph = KOPM_RsrvdPwrHi_kW;
  }

  /* End of MinMax: '<S246>/MinMax' */

  /* MinMax: '<S246>/MinMax1' incorporates:
   *  Constant: '<S246>/sat7'
   */
  if (VOPM_VCUCruiseCtrTgtSpd_kph >= KOPM_RsrvdPwrLo_kW)
  {
    /* MinMax: '<S246>/MinMax1' */
    VOPM_RsrvdPwr_kW = VOPM_VCUCruiseCtrTgtSpd_kph;
  }
  else
  {
    /* MinMax: '<S246>/MinMax1' */
    VOPM_RsrvdPwr_kW = KOPM_RsrvdPwrLo_kW;
  }

  /* End of MinMax: '<S246>/MinMax1' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_RsrvdPwr_kW1' */

  /* DataTypeConversion: '<S212>/DataTypeConversion45' incorporates:
   *  Constant: '<S276>/Constant1'
   *  Product: '<S276>/Product1'
   *  Sum: '<S276>/Add'
   */
  tmp = VOPM_RsrvdPwr_kW * 5.0F;
  if (tmp < 65536.0F)
  {
    if (tmp >= 0.0F)
    {
      AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_ReservePower = (uint16)tmp;
    }
    else
    {
      AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_ReservePower = 0U;
    }
  }
  else
  {
    AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_ReservePower = MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<S212>/DataTypeConversion45' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_MotActPwr_Kw1' */
  /* Switch: '<S237>/Switch4' incorporates:
   *  Constant: '<S237>/sat3'
   */
  if (KOPM_MotActPwr_Kw_ovrdflg)
  {
    /* MinMax: '<S318>/MinMax' incorporates:
     *  Constant: '<S237>/sat4'
     *  Product: '<S313>/Product1'
     */
    VOPM_VCUCruiseCtrTgtSpd_kph = KOPM_MotActPwr_Kw_ovrdval;
  }
  else
  {
    /* MinMax: '<S318>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S237>/Data Type Conversion1'
     *  Product: '<S313>/Product1'
     */
    VOPM_VCUCruiseCtrTgtSpd_kph =
        (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs())
            ->VVTM_MotorActlPwr_kW;
  }

  /* End of Switch: '<S237>/Switch4' */

  /* MinMax: '<S237>/MinMax' incorporates:
   *  Constant: '<S237>/sat6'
   */
  if (VOPM_VCUCruiseCtrTgtSpd_kph > KOPM_MotActPwrHi_Kw)
  {
    /* MinMax: '<S318>/MinMax' */
    VOPM_VCUCruiseCtrTgtSpd_kph = KOPM_MotActPwrHi_Kw;
  }

  /* End of MinMax: '<S237>/MinMax' */

  /* MinMax: '<S237>/MinMax1' incorporates:
   *  Constant: '<S237>/sat7'
   */
  if (VOPM_VCUCruiseCtrTgtSpd_kph >= KOPM_MotActPwrLo_Kw)
  {
    /* MinMax: '<S237>/MinMax1' */
    VOPM_MotActPwr_Kw = VOPM_VCUCruiseCtrTgtSpd_kph;
  }
  else
  {
    /* MinMax: '<S237>/MinMax1' */
    VOPM_MotActPwr_Kw = KOPM_MotActPwrLo_Kw;
  }

  /* End of MinMax: '<S237>/MinMax1' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_MotActPwr_Kw1' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_DrvMotorSta_enum1' */
  /* Switch: '<S230>/Switch4' incorporates:
   *  Constant: '<S230>/sat3'
   */
  if (KOPM_DrvMotorSta_enum_ovrdflg)
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  Constant: '<S230>/sat4'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = KOPM_DrvMotorSta_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S230>/Data Type Conversion1'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs())
                               ->VVTM_DrvMotorSta_enum;
  }

  /* End of Switch: '<S230>/Switch4' */

  /* MinMax: '<S230>/MinMax' incorporates:
   *  Constant: '<S230>/sat6'
   */
  if (VOPM_VCUACCStat_enum > KOPM_DrvMotorStaHi_enum)
  {
    /* MinMax: '<S236>/MinMax' */
    VOPM_VCUACCStat_enum = KOPM_DrvMotorStaHi_enum;
  }

  /* End of MinMax: '<S230>/MinMax' */

  /* MinMax: '<S230>/MinMax1' incorporates:
   *  Constant: '<S230>/sat7'
   */
  if (VOPM_VCUACCStat_enum >= KOPM_DrvMotorStaLo_enum)
  {
    /* MinMax: '<S230>/MinMax1' */
    VOPM_DrvMotorSta_enum = VOPM_VCUACCStat_enum;
  }
  else
  {
    /* MinMax: '<S230>/MinMax1' */
    VOPM_DrvMotorSta_enum = KOPM_DrvMotorStaLo_enum;
  }

  /* End of MinMax: '<S230>/MinMax1' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_DrvMotorSta_enum1' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_InfoDisp_enum1' */
  /* Switch: '<S233>/Switch4' incorporates:
   *  Constant: '<S233>/sat3'
   */
  if (KOPM_InfoDisp_enum_ovrdflg)
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  Constant: '<S233>/sat4'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = KOPM_InfoDisp_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S233>/Data Type Conversion1'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs())
                               ->VHMI_InfoDisp_enum;
  }

  /* End of Switch: '<S233>/Switch4' */

  /* MinMax: '<S233>/MinMax' incorporates:
   *  Constant: '<S233>/sat6'
   */
  if (VOPM_VCUACCStat_enum > KOPM_InfoDispHi_enum)
  {
    /* MinMax: '<S236>/MinMax' */
    VOPM_VCUACCStat_enum = KOPM_InfoDispHi_enum;
  }

  /* End of MinMax: '<S233>/MinMax' */

  /* MinMax: '<S233>/MinMax1' incorporates:
   *  Constant: '<S233>/sat7'
   */
  if (VOPM_VCUACCStat_enum >= KOPM_InfoDispLo_enum)
  {
    /* MinMax: '<S233>/MinMax1' */
    VOPM_InfoDisp_enum = VOPM_VCUACCStat_enum;
  }
  else
  {
    /* MinMax: '<S233>/MinMax1' */
    VOPM_InfoDisp_enum = KOPM_InfoDispLo_enum;
  }

  /* End of MinMax: '<S233>/MinMax1' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_InfoDisp_enum1' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_VehPGearError_flg1' */
  /* Switch: '<S263>/Switch4' incorporates:
   *  Constant: '<S263>/sat3'
   */
  if (KOPM_VehPGearError_flg_ovrdflg)
  {
    /* Switch: '<S263>/Switch4' incorporates:
     *  Constant: '<S263>/sat4'
     */
    VOPM_VehPGearError_flg = KOPM_VehPGearError_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S263>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S263>/Data Type Conversion1'
     */
    VOPM_VehPGearError_flg =
        (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs())
            ->VGSM_VehPGearErr_flg;
  }

  /* End of Switch: '<S263>/Switch4' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_VehPGearError_flg1' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_VhclActlCnsmPwr_kWh1' */
  /* Switch: '<S265>/Switch4' incorporates:
   *  Constant: '<S265>/sat3'
   */
  if (KOPM_VhclActlCnsmPwr_kWh_ovrdflg)
  {
    /* MinMax: '<S318>/MinMax' incorporates:
     *  Constant: '<S265>/sat4'
     *  Product: '<S313>/Product1'
     */
    VOPM_VCUCruiseCtrTgtSpd_kph = KOPM_VhclActlCnsmPwr_kWh_ovrdval;
  }
  else
  {
    /* MinMax: '<S318>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S265>/Data Type Conversion1'
     *  Product: '<S313>/Product1'
     */
    VOPM_VCUCruiseCtrTgtSpd_kph =
        (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs())
            ->VRME_VehPwrCnsmIns_kWhp100km;
  }

  /* End of Switch: '<S265>/Switch4' */

  /* MinMax: '<S265>/MinMax' incorporates:
   *  Constant: '<S265>/sat6'
   */
  if (VOPM_VCUCruiseCtrTgtSpd_kph > KOPM_VhclActlCnsmPwrHi_kWh)
  {
    /* MinMax: '<S318>/MinMax' */
    VOPM_VCUCruiseCtrTgtSpd_kph = KOPM_VhclActlCnsmPwrHi_kWh;
  }

  /* End of MinMax: '<S265>/MinMax' */

  /* MinMax: '<S265>/MinMax1' incorporates:
   *  Constant: '<S265>/sat7'
   */
  if (VOPM_VCUCruiseCtrTgtSpd_kph >= KOPM_VhclActlCnsmPwrLo_kWh)
  {
    /* MinMax: '<S265>/MinMax1' */
    VOPM_VhclActlCnsmPwr_kWh = VOPM_VCUCruiseCtrTgtSpd_kph;
  }
  else
  {
    /* MinMax: '<S265>/MinMax1' */
    VOPM_VhclActlCnsmPwr_kWh = KOPM_VhclActlCnsmPwrLo_kWh;
  }

  /* End of MinMax: '<S265>/MinMax1' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_VhclActlCnsmPwr_kWh1' */

  /* DataTypeConversion: '<S212>/DataTypeConversion33' incorporates:
   *  Constant: '<S274>/Constant'
   *  Constant: '<S274>/Constant1'
   *  Product: '<S274>/Product1'
   *  Sum: '<S274>/Add'
   */
  tmp = (VOPM_VhclActlCnsmPwr_kWh - -51.1F) * 10.0F;
  if (tmp < 65536.0F)
  {
    if (tmp >= 0.0F)
    {
      AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_VhclActlCnsmPwr = (uint16)tmp;
    }
    else
    {
      AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_VhclActlCnsmPwr = 0U;
    }
  }
  else
  {
    AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_VhclActlCnsmPwr = MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<S212>/DataTypeConversion33' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_VhclSpdFstWarn_flg1' */
  /* Switch: '<S266>/Switch4' incorporates:
   *  Constant: '<S266>/sat3'
   */
  if (KOPM_VhclSpdFstWarn_flg_ovrdflg)
  {
    /* Switch: '<S266>/Switch4' incorporates:
     *  Constant: '<S266>/sat4'
     */
    VOPM_VhclSpdFstWarn_flg = KOPM_VhclSpdFstWarn_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S266>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S266>/Data Type Conversion1'
     */
    VOPM_VhclSpdFstWarn_flg =
        (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs())
            ->VGSM_VehSpdFstWrn_flg;
  }

  /* End of Switch: '<S266>/Switch4' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_VhclSpdFstWarn_flg1' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_OBCOprtCmdToICU_enum1' */
  /* Switch: '<S239>/Switch4' incorporates:
   *  Constant: '<S239>/sat3'
   */
  if (KOPM_OBCOprtCmdToICU_enum_ovrdflg)
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  Constant: '<S239>/sat4'
     *  DataTypeConversion: '<S239>/Data Type Conversion3'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = KOPM_OBCOprtCmdToICU_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S239>/Data Type Conversion1'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs())
                               ->VHVM_OBCOprtCmd_enum;
  }

  /* End of Switch: '<S239>/Switch4' */

  /* MinMax: '<S239>/MinMax' incorporates:
   *  Constant: '<S239>/sat6'
   */
  if (VOPM_VCUACCStat_enum > KOPM_OBCOprtCmdToICUHi_enum)
  {
    /* MinMax: '<S236>/MinMax' */
    VOPM_VCUACCStat_enum = KOPM_OBCOprtCmdToICUHi_enum;
  }

  /* End of MinMax: '<S239>/MinMax' */

  /* MinMax: '<S239>/MinMax1' incorporates:
   *  Constant: '<S239>/sat7'
   */
  if (VOPM_VCUACCStat_enum >= KOPM_OBCOprtCmdToICULo_enum)
  {
    /* DataTypeConversion: '<S239>/Data Type Conversion2' */
    VOPM_OBCOprtCmdToICU_enum = VOPM_VCUACCStat_enum;
  }
  else
  {
    /* DataTypeConversion: '<S239>/Data Type Conversion2' */
    VOPM_OBCOprtCmdToICU_enum = KOPM_OBCOprtCmdToICULo_enum;
  }

  /* End of MinMax: '<S239>/MinMax1' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_OBCOprtCmdToICU_enum1' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_MotorHiTempWrning_flg1' */
  /* Switch: '<S238>/Switch4' incorporates:
   *  Constant: '<S238>/sat3'
   */
  if (KOPM_MotorHiTempWrning_flg_ovrdflg)
  {
    /* Switch: '<S238>/Switch4' incorporates:
     *  Constant: '<S238>/sat4'
     */
    VOPM_MotorHiTempWrning_flg = KOPM_MotorHiTempWrning_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S238>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S238>/Data Type Conversion1'
     */
    VOPM_MotorHiTempWrning_flg =
        (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs())
            ->VVcuTx_MotorHiTempWrning_flg;
  }

  /* End of Switch: '<S238>/Switch4' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_MotorHiTempWrning_flg1' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_MCUHiTempWrning_flg1' */
  /* Switch: '<S235>/Switch4' incorporates:
   *  Constant: '<S235>/sat3'
   */
  if (KOPM_MCUHiTempWrning_flg_ovrdflg)
  {
    /* Switch: '<S235>/Switch4' incorporates:
     *  Constant: '<S235>/sat4'
     */
    VOPM_MCUHiTempWrning_flg = KOPM_MCUHiTempWrning_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S235>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S235>/Data Type Conversion1'
     */
    VOPM_MCUHiTempWrning_flg =
        (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs())
            ->VVcuTx_MCUHiTempWrning_flg;
  }

  /* End of Switch: '<S235>/Switch4' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_MCUHiTempWrning_flg1' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_VehPwrCnsmpAvrg_kWh1' */
  /* Switch: '<S264>/Switch4' incorporates:
   *  Constant: '<S264>/sat3'
   */
  if (KOPM_VehPwrCnsmpAvrg_kWh_ovrdflg)
  {
    /* MinMax: '<S318>/MinMax' incorporates:
     *  Constant: '<S264>/sat4'
     *  Product: '<S313>/Product1'
     */
    VOPM_VCUCruiseCtrTgtSpd_kph = KOPM_VehPwrCnsmpAvrg_kWh_ovrdval;
  }
  else
  {
    /* MinMax: '<S318>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S264>/Data Type Conversion1'
     *  Product: '<S313>/Product1'
     */
    VOPM_VCUCruiseCtrTgtSpd_kph =
        (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs())
            ->VRME_VehPwrCnsmAvg_kWhp100km;
  }

  /* End of Switch: '<S264>/Switch4' */

  /* MinMax: '<S264>/MinMax' incorporates:
   *  Constant: '<S264>/sat6'
   */
  if (VOPM_VCUCruiseCtrTgtSpd_kph > KOPM_VehPwrCnsmpAvrgHi_kWh)
  {
    /* MinMax: '<S318>/MinMax' */
    VOPM_VCUCruiseCtrTgtSpd_kph = KOPM_VehPwrCnsmpAvrgHi_kWh;
  }

  /* End of MinMax: '<S264>/MinMax' */

  /* MinMax: '<S264>/MinMax1' incorporates:
   *  Constant: '<S264>/sat7'
   */
  if (VOPM_VCUCruiseCtrTgtSpd_kph >= KOPM_VehPwrCnsmpAvrgLo_kWh)
  {
    /* MinMax: '<S264>/MinMax1' */
    VOPM_VehPwrCnsmpAvrg_kWh = VOPM_VCUCruiseCtrTgtSpd_kph;
  }
  else
  {
    /* MinMax: '<S264>/MinMax1' */
    VOPM_VehPwrCnsmpAvrg_kWh = KOPM_VehPwrCnsmpAvrgLo_kWh;
  }

  /* End of MinMax: '<S264>/MinMax1' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_VehPwrCnsmpAvrg_kWh1' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_ShftKeyStgntn_enum1' */
  /* Switch: '<S255>/Switch4' incorporates:
   *  Constant: '<S255>/sat3'
   */
  if (KOPM_ShftKeyStgntn_enum_ovrdflg)
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  Constant: '<S255>/sat4'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = KOPM_ShftKeyStgntn_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S255>/Data Type Conversion1'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs())
                               ->VVcuTx_ShftKeyStgntn_enum;
  }

  /* End of Switch: '<S255>/Switch4' */

  /* MinMax: '<S255>/MinMax' incorporates:
   *  Constant: '<S255>/sat6'
   */
  if (VOPM_VCUACCStat_enum > KOPM_ShftKeyStgntnHi_enum)
  {
    /* MinMax: '<S236>/MinMax' */
    VOPM_VCUACCStat_enum = KOPM_ShftKeyStgntnHi_enum;
  }

  /* End of MinMax: '<S255>/MinMax' */

  /* MinMax: '<S255>/MinMax1' incorporates:
   *  Constant: '<S255>/sat7'
   */
  if (VOPM_VCUACCStat_enum >= KOPM_ShftKeyStgntnLo_enum)
  {
    /* MinMax: '<S255>/MinMax1' */
    VOPM_ShftKeyStgntn_enum = VOPM_VCUACCStat_enum;
  }
  else
  {
    /* MinMax: '<S255>/MinMax1' */
    VOPM_ShftKeyStgntn_enum = KOPM_ShftKeyStgntnLo_enum;
  }

  /* End of MinMax: '<S255>/MinMax1' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_ShftKeyStgntn_enum1' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_CCKeyStgntn_enum1' */
  /* Switch: '<S221>/Switch4' incorporates:
   *  Constant: '<S221>/sat3'
   */
  if (KOPM_CCKeyStgntn_enum_ovrdflg)
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  Constant: '<S221>/sat4'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = KOPM_CCKeyStgntn_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S221>/Data Type Conversion1'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs())
                               ->VVcuTx_CCKeyStgntn_enum;
  }

  /* End of Switch: '<S221>/Switch4' */

  /* MinMax: '<S221>/MinMax' incorporates:
   *  Constant: '<S221>/sat6'
   */
  if (VOPM_VCUACCStat_enum > KOPM_CCKeyStgntnHi_enum)
  {
    /* MinMax: '<S236>/MinMax' */
    VOPM_VCUACCStat_enum = KOPM_CCKeyStgntnHi_enum;
  }

  /* End of MinMax: '<S221>/MinMax' */

  /* MinMax: '<S221>/MinMax1' incorporates:
   *  Constant: '<S221>/sat7'
   */
  if (VOPM_VCUACCStat_enum >= KOPM_CCKeyStgntnLo_enum)
  {
    /* MinMax: '<S221>/MinMax1' */
    VOPM_CCKeyStgntn_enum = VOPM_VCUACCStat_enum;
  }
  else
  {
    /* MinMax: '<S221>/MinMax1' */
    VOPM_CCKeyStgntn_enum = KOPM_CCKeyStgntnLo_enum;
  }

  /* End of MinMax: '<S221>/MinMax1' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_CCKeyStgntn_enum1' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_DrvModeKeyStgntn_enum1' */
  /* Switch: '<S229>/Switch4' incorporates:
   *  Constant: '<S229>/sat3'
   */
  if (KOPM_DrvModeKeyStgntn_enum_ovrdflg)
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  Constant: '<S229>/sat4'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = KOPM_DrvModeKeyStgntn_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S229>/Data Type Conversion1'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs())
                               ->VVcuTx_DrvModeKeyStgntn_enum;
  }

  /* End of Switch: '<S229>/Switch4' */

  /* MinMax: '<S229>/MinMax' incorporates:
   *  Constant: '<S229>/sat6'
   */
  if (VOPM_VCUACCStat_enum > KOPM_DrvModeKeyStgntnHi_enum)
  {
    /* MinMax: '<S236>/MinMax' */
    VOPM_VCUACCStat_enum = KOPM_DrvModeKeyStgntnHi_enum;
  }

  /* End of MinMax: '<S229>/MinMax' */

  /* MinMax: '<S229>/MinMax1' incorporates:
   *  Constant: '<S229>/sat7'
   */
  if (VOPM_VCUACCStat_enum >= KOPM_DrvModeKeyStgntnLo_enum)
  {
    /* MinMax: '<S229>/MinMax1' */
    VOPM_DrvModeKeyStgntn_enum = VOPM_VCUACCStat_enum;
  }
  else
  {
    /* MinMax: '<S229>/MinMax1' */
    VOPM_DrvModeKeyStgntn_enum = KOPM_DrvModeKeyStgntnLo_enum;
  }

  /* End of MinMax: '<S229>/MinMax1' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_DrvModeKeyStgntn_enum1' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_SIBSKL30Volt_V' */
  /* Switch: '<S250>/Switch4' incorporates:
   *  Constant: '<S250>/sat3'
   */
  if (KOPM_SIBSKL30Volt_V_ovrdflg)
  {
    /* MinMax: '<S318>/MinMax' incorporates:
     *  Constant: '<S250>/sat4'
     *  Product: '<S313>/Product1'
     */
    VOPM_VCUCruiseCtrTgtSpd_kph = KOPM_SIBSKL30Volt_V_ovrdval;
  }
  else
  {
    /* MinMax: '<S318>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S250>/Data Type Conversion1'
     *  Product: '<S313>/Product1'
     */
    VOPM_VCUCruiseCtrTgtSpd_kph =
        (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs())->VIBS_HwKL30_V;
  }

  /* End of Switch: '<S250>/Switch4' */

  /* MinMax: '<S250>/MinMax' incorporates:
   *  Constant: '<S250>/sat6'
   */
  if (VOPM_VCUCruiseCtrTgtSpd_kph > KOPM_SIBSKL30VoltHi_V)
  {
    /* MinMax: '<S318>/MinMax' */
    VOPM_VCUCruiseCtrTgtSpd_kph = KOPM_SIBSKL30VoltHi_V;
  }

  /* End of MinMax: '<S250>/MinMax' */

  /* MinMax: '<S250>/MinMax1' incorporates:
   *  Constant: '<S250>/sat7'
   */
  if (VOPM_VCUCruiseCtrTgtSpd_kph >= KOPM_SIBSKL30VoltLo_V)
  {
    /* MinMax: '<S250>/MinMax1' */
    VOPM_SIBSKL30Volt_V = VOPM_VCUCruiseCtrTgtSpd_kph;
  }
  else
  {
    /* MinMax: '<S250>/MinMax1' */
    VOPM_SIBSKL30Volt_V = KOPM_SIBSKL30VoltLo_V;
  }

  /* End of MinMax: '<S250>/MinMax1' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_SIBSKL30Volt_V' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_SIBSChgNumAllow_flg' */
  /* Switch: '<S248>/Switch4' incorporates:
   *  Constant: '<S248>/sat3'
   */
  if (KOPM_SIBSChgNumAllow_flg_ovrdflg)
  {
    /* Switch: '<S248>/Switch4' incorporates:
     *  Constant: '<S248>/sat4'
     */
    VOPM_SIBSChgNumAllow_flg = KOPM_SIBSChgNumAllow_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S248>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S248>/Data Type Conversion1'
     */
    VOPM_SIBSChgNumAllow_flg =
        (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs())
            ->VIBS_ChgNumAllow_flg;
  }

  /* End of Switch: '<S248>/Switch4' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_SIBSChgNumAllow_flg' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_SIBSRTCWUChgNum_cnt' */
  /* Switch: '<S253>/Switch4' incorporates:
   *  Constant: '<S253>/sat3'
   */
  if (KOPM_SIBSRTCWUChgNum_cnt_ovrdflg)
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  Constant: '<S253>/sat4'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = KOPM_SIBSRTCWUChgNum_cnt_ovrdval;
  }
  else
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S253>/Data Type Conversion1'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs())
                               ->VIBS_ChgNum_cnt;
  }

  /* End of Switch: '<S253>/Switch4' */

  /* MinMax: '<S253>/MinMax' incorporates:
   *  Constant: '<S253>/sat6'
   */
  if (VOPM_VCUACCStat_enum > KOPM_SIBSRTCWUChgNumHi_cnt)
  {
    /* MinMax: '<S236>/MinMax' */
    VOPM_VCUACCStat_enum = KOPM_SIBSRTCWUChgNumHi_cnt;
  }

  /* End of MinMax: '<S253>/MinMax' */

  /* MinMax: '<S253>/MinMax1' incorporates:
   *  Constant: '<S253>/sat7'
   */
  if (VOPM_VCUACCStat_enum >= KOPM_SIBSRTCWUChgNumLo_cnt)
  {
    /* MinMax: '<S253>/MinMax1' */
    VOPM_SIBSRTCWUChgNum_cnt = VOPM_VCUACCStat_enum;
  }
  else
  {
    /* MinMax: '<S253>/MinMax1' */
    VOPM_SIBSRTCWUChgNum_cnt = KOPM_SIBSRTCWUChgNumLo_cnt;
  }

  /* End of MinMax: '<S253>/MinMax1' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_SIBSRTCWUChgNum_cnt' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_SIBSRTCChrgSt_enum' */
  /* Switch: '<S251>/Switch4' incorporates:
   *  Constant: '<S251>/sat3'
   */
  if (KOPM_SIBSRTCChrgSt_enum_ovrdflg)
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  Constant: '<S251>/sat4'
     *  DataTypeConversion: '<S251>/Data Type Conversion3'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = KOPM_SIBSRTCChrgSt_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S251>/Data Type Conversion1'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs())
                               ->VIBS_RTCChrgSt_enum;
  }

  /* End of Switch: '<S251>/Switch4' */

  /* MinMax: '<S251>/MinMax' incorporates:
   *  Constant: '<S251>/sat6'
   */
  if (VOPM_VCUACCStat_enum > KOPM_SIBSRTCChrgStHi_enum)
  {
    /* MinMax: '<S236>/MinMax' */
    VOPM_VCUACCStat_enum = KOPM_SIBSRTCChrgStHi_enum;
  }

  /* End of MinMax: '<S251>/MinMax' */

  /* MinMax: '<S251>/MinMax1' incorporates:
   *  Constant: '<S251>/sat7'
   */
  if (VOPM_VCUACCStat_enum >= KOPM_SIBSRTCChrgStLo_enum)
  {
    /* DataTypeConversion: '<S251>/Data Type Conversion2' */
    VOPM_SIBSRTCChrgSt_enum = VOPM_VCUACCStat_enum;
  }
  else
  {
    /* DataTypeConversion: '<S251>/Data Type Conversion2' */
    VOPM_SIBSRTCChrgSt_enum = KOPM_SIBSRTCChrgStLo_enum;
  }

  /* End of MinMax: '<S251>/MinMax1' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_SIBSRTCChrgSt_enum' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_SIBSRTCWUChgFailNum_cnt' */
  /* Switch: '<S252>/Switch4' incorporates:
   *  Constant: '<S252>/sat3'
   */
  if (KOPM_SIBSRTCWUChgFailNum_cnt_ovrdflg)
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  Constant: '<S252>/sat4'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = KOPM_SIBSRTCWUChgFailNum_cnt_ovrdval;
  }
  else
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S252>/Data Type Conversion1'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs())
                               ->VIBS_FailChgNum_cnt;
  }

  /* End of Switch: '<S252>/Switch4' */

  /* MinMax: '<S252>/MinMax' incorporates:
   *  Constant: '<S252>/sat6'
   */
  if (VOPM_VCUACCStat_enum > KOPM_SIBSRTCWUChgFailNumHi_cnt)
  {
    /* MinMax: '<S236>/MinMax' */
    VOPM_VCUACCStat_enum = KOPM_SIBSRTCWUChgFailNumHi_cnt;
  }

  /* End of MinMax: '<S252>/MinMax' */

  /* MinMax: '<S252>/MinMax1' incorporates:
   *  Constant: '<S252>/sat7'
   */
  if (VOPM_VCUACCStat_enum >= KOPM_SIBSRTCWUChgFailNumLo_cnt)
  {
    /* MinMax: '<S252>/MinMax1' */
    VOPM_SIBSRTCWUChgFailNum_cnt = VOPM_VCUACCStat_enum;
  }
  else
  {
    /* MinMax: '<S252>/MinMax1' */
    VOPM_SIBSRTCWUChgFailNum_cnt = KOPM_SIBSRTCWUChgFailNumLo_cnt;
  }

  /* End of MinMax: '<S252>/MinMax1' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_SIBSRTCWUChgFailNum_cnt' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_BCMIllmndLckStsFb_flg' */
  /* Switch: '<S219>/Switch4' incorporates:
   *  Constant: '<S219>/sat3'
   */
  if (KOPM_BCMIllmndLckStsFb_flg_ovrdflg)
  {
    /* Switch: '<S219>/Switch4' incorporates:
     *  Constant: '<S219>/sat4'
     */
    VOPM_BCMIllmndLckStsFb_flg = KOPM_BCMIllmndLckStsFb_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S219>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S219>/Data Type Conversion1'
     */
    VOPM_BCMIllmndLckStsFb_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_20ms_Bcm2OpmBAC_outputs())
             ->BCM_IllmndLockStsFb != 0);
  }

  /* End of Switch: '<S219>/Switch4' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_BCMIllmndLckStsFb_flg' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_BCMIllmndUnlckStsFb_flg' */
  /* Switch: '<S220>/Switch4' incorporates:
   *  Constant: '<S220>/sat3'
   */
  if (KOPM_BCMIllmndUnlckStsFb_flg_ovrdflg)
  {
    /* Switch: '<S220>/Switch4' incorporates:
     *  Constant: '<S220>/sat4'
     */
    VOPM_BCMIllmndUnlckStsFb_flg = KOPM_BCMIllmndUnlckStsFb_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S220>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S220>/Data Type Conversion1'
     */
    VOPM_BCMIllmndUnlckStsFb_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_20ms_Bcm2OpmBAC_outputs())
             ->BCM_IllmndUnlockStsFb != 0);
  }

  /* End of Switch: '<S220>/Switch4' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_BCMIllmndUnlckStsFb_flg' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_SIBSFbRTCWupFlg_flg' */
  /* Switch: '<S249>/Switch4' incorporates:
   *  Constant: '<S249>/sat3'
   */
  if (KOPM_SIBSFbRTCWupFlg_flg_ovrdflg)
  {
    /* Switch: '<S249>/Switch4' incorporates:
     *  Constant: '<S249>/sat4'
     */
    VOPM_SIBSFbRTCWupFlg_flg = KOPM_SIBSFbRTCWupFlg_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S249>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S249>/Data Type Conversion1'
     */
    VOPM_SIBSFbRTCWupFlg_flg =
        (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs())->VIBS_FbRctWup_flg;
  }

  /* End of Switch: '<S249>/Switch4' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_SIBSFbRTCWupFlg_flg' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_SIBSBMSBatSOCAllow_flg' */
  /* Switch: '<S247>/Switch4' incorporates:
   *  Constant: '<S247>/sat3'
   */
  if (KOPM_SIBSBMSBatSOCAllow_flg_ovrdflg)
  {
    /* Switch: '<S247>/Switch4' incorporates:
     *  Constant: '<S247>/sat4'
     */
    VOPM_SIBSBMSBatSOCAllow_flg = KOPM_SIBSBMSBatSOCAllow_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S247>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S247>/Data Type Conversion1'
     */
    VOPM_SIBSBMSBatSOCAllow_flg =
        (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs())
            ->VIBS_BMSBatSOCAllow_flg;
  }

  /* End of Switch: '<S247>/Switch4' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_SIBSBMSBatSOCAllow_flg' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_SIBSWupVoltAllow_flg' */
  /* Switch: '<S254>/Switch4' incorporates:
   *  Constant: '<S254>/sat3'
   */
  if (KOPM_SIBSWupVoltAllow_flg_ovrdflg)
  {
    /* Switch: '<S254>/Switch4' incorporates:
     *  Constant: '<S254>/sat4'
     */
    VOPM_SIBSWupVoltAllow_flg = KOPM_SIBSWupVoltAllow_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S254>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S254>/Data Type Conversion1'
     */
    VOPM_SIBSWupVoltAllow_flg =
        (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs())
            ->VIBS_WupVoltAllow_flg;
  }

  /* End of Switch: '<S254>/Switch4' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_SIBSWupVoltAllow_flg' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_VehActDrvPwr_pct' */
  /* Switch: '<S261>/Switch4' incorporates:
   *  Constant: '<S261>/sat3'
   */
  if (KOPM_VehActDrvPwr_pct_ovrdflg)
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  Constant: '<S261>/sat4'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = KOPM_VehActDrvPwr_pct_ovrdval;
  }
  else
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S261>/Data Type Conversion1'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs())
                               ->VIPC_DrvPwrIntnsty_pct;
  }

  /* End of Switch: '<S261>/Switch4' */

  /* MinMax: '<S261>/MinMax' incorporates:
   *  Constant: '<S261>/sat6'
   */
  if (VOPM_VCUACCStat_enum > KOPM_VehActDrvPwrHi_pct)
  {
    /* MinMax: '<S236>/MinMax' */
    VOPM_VCUACCStat_enum = KOPM_VehActDrvPwrHi_pct;
  }

  /* End of MinMax: '<S261>/MinMax' */

  /* MinMax: '<S261>/MinMax1' incorporates:
   *  Constant: '<S261>/sat7'
   */
  if (VOPM_VCUACCStat_enum >= KOPM_VehActDrvPwrLo_pct)
  {
    /* MinMax: '<S261>/MinMax1' */
    VOPM_VehActDrvPwr_pct = VOPM_VCUACCStat_enum;
  }
  else
  {
    /* MinMax: '<S261>/MinMax1' */
    VOPM_VehActDrvPwr_pct = KOPM_VehActDrvPwrLo_pct;
  }

  /* End of MinMax: '<S261>/MinMax1' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_VehActDrvPwr_pct' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_VehActRecupPwr_pct' */
  /* Switch: '<S262>/Switch4' incorporates:
   *  Constant: '<S262>/sat3'
   */
  if (KOPM_VehActRecupPwr_pct_ovrdflg)
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  Constant: '<S262>/sat4'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = KOPM_VehActRecupPwr_pct_ovrdval;
  }
  else
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S262>/Data Type Conversion1'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs())
                               ->VIPC_RegenPwrIntnsty_pct;
  }

  /* End of Switch: '<S262>/Switch4' */

  /* MinMax: '<S262>/MinMax' incorporates:
   *  Constant: '<S262>/sat6'
   */
  if (VOPM_VCUACCStat_enum > KOPM_VehActRecupPwrHi_pct)
  {
    /* MinMax: '<S236>/MinMax' */
    VOPM_VCUACCStat_enum = KOPM_VehActRecupPwrHi_pct;
  }

  /* End of MinMax: '<S262>/MinMax' */

  /* MinMax: '<S262>/MinMax1' incorporates:
   *  Constant: '<S262>/sat7'
   */
  if (VOPM_VCUACCStat_enum >= KOPM_VehActRecupPwrLo_pct)
  {
    /* MinMax: '<S262>/MinMax1' */
    VOPM_VehActRecupPwr_pct = VOPM_VCUACCStat_enum;
  }
  else
  {
    /* MinMax: '<S262>/MinMax1' */
    VOPM_VehActRecupPwr_pct = KOPM_VehActRecupPwrLo_pct;
  }

  /* End of MinMax: '<S262>/MinMax1' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_VehActRecupPwr_pct' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_LckVehWrm_enum' */
  /* Switch: '<S234>/Switch4' incorporates:
   *  Constant: '<S234>/sat3'
   */
  if (KOPM_LckVehWrm_enum_ovrdflg)
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  Constant: '<S234>/sat4'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = KOPM_LckVehWrm_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S234>/Data Type Conversion1'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs())
                               ->VTBX_VCULckVehWrn_enum;
  }

  /* End of Switch: '<S234>/Switch4' */

  /* MinMax: '<S234>/MinMax' incorporates:
   *  Constant: '<S234>/sat6'
   */
  if (VOPM_VCUACCStat_enum > KOPM_LckVehWrmHi_enum)
  {
    /* MinMax: '<S236>/MinMax' */
    VOPM_VCUACCStat_enum = KOPM_LckVehWrmHi_enum;
  }

  /* End of MinMax: '<S234>/MinMax' */

  /* MinMax: '<S234>/MinMax1' incorporates:
   *  Constant: '<S234>/sat7'
   */
  if (VOPM_VCUACCStat_enum >= KOPM_LckVehWrmLo_enum)
  {
    /* MinMax: '<S234>/MinMax1' */
    VOPM_LckVehWrm_enum = VOPM_VCUACCStat_enum;
  }
  else
  {
    /* MinMax: '<S234>/MinMax1' */
    VOPM_LckVehWrm_enum = KOPM_LckVehWrmLo_enum;
  }

  /* End of MinMax: '<S234>/MinMax1' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_LckVehWrm_enum' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_ACChrgMode_enum' */
  /* Switch: '<S214>/Switch4' incorporates:
   *  Constant: '<S214>/sat3'
   */
  if (KOPM_ACChrgMode_enum_ovrdflg)
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  Constant: '<S214>/sat4'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = KOPM_ACChrgMode_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S214>/Data Type Conversion1'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs())
                               ->VHVM_ACChrgModeFb_enum;
  }

  /* End of Switch: '<S214>/Switch4' */

  /* MinMax: '<S214>/MinMax' incorporates:
   *  Constant: '<S214>/sat6'
   */
  if (VOPM_VCUACCStat_enum > KOPM_ACChrgModeHi_enum)
  {
    /* MinMax: '<S236>/MinMax' */
    VOPM_VCUACCStat_enum = KOPM_ACChrgModeHi_enum;
  }

  /* End of MinMax: '<S214>/MinMax' */

  /* MinMax: '<S214>/MinMax1' incorporates:
   *  Constant: '<S214>/sat7'
   */
  if (VOPM_VCUACCStat_enum >= KOPM_ACChrgModeLo_enum)
  {
    /* MinMax: '<S214>/MinMax1' */
    VOPM_ACChrgMode_enum = VOPM_VCUACCStat_enum;
  }
  else
  {
    /* MinMax: '<S214>/MinMax1' */
    VOPM_ACChrgMode_enum = KOPM_ACChrgModeLo_enum;
  }

  /* End of MinMax: '<S214>/MinMax1' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_ACChrgMode_enum' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_ACChrgMaxCurr_A' */
  /* Switch: '<S213>/Switch4' incorporates:
   *  Constant: '<S213>/sat3'
   */
  if (KOPM_ACChrgMaxCurr_A_ovrdflg)
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  Constant: '<S213>/sat4'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = KOPM_ACChrgMaxCurr_A_ovrdval;
  }
  else
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S213>/Data Type Conversion1'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs())
                               ->VHVM_ACChrgMaxCurrFb_A;
  }

  /* End of Switch: '<S213>/Switch4' */

  /* MinMax: '<S213>/MinMax' incorporates:
   *  Constant: '<S213>/sat6'
   */
  if (VOPM_VCUACCStat_enum > KOPM_ACChrgMaxCurrHi_A)
  {
    /* MinMax: '<S236>/MinMax' */
    VOPM_VCUACCStat_enum = KOPM_ACChrgMaxCurrHi_A;
  }

  /* End of MinMax: '<S213>/MinMax' */

  /* MinMax: '<S213>/MinMax1' incorporates:
   *  Constant: '<S213>/sat7'
   */
  if (VOPM_VCUACCStat_enum >= KOPM_ACChrgMaxCurrLo_A)
  {
    /* MinMax: '<S213>/MinMax1' */
    VOPM_ACChrgMaxCurr_A = VOPM_VCUACCStat_enum;
  }
  else
  {
    /* MinMax: '<S213>/MinMax1' */
    VOPM_ACChrgMaxCurr_A = KOPM_ACChrgMaxCurrLo_A;
  }

  /* End of MinMax: '<S213>/MinMax1' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_ACChrgMaxCurr_A' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_ACUnlckVentSetFB_enum' */
  /* Switch: '<S218>/Switch4' incorporates:
   *  Constant: '<S218>/sat3'
   */
  if (KOPM_ACUnlckVentSetFB_enum_ovrdflg)
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  Constant: '<S218>/sat4'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = KOPM_ACUnlckVentSetFB_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S218>/Data Type Conversion1'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_TMS2VCU_PPV_outputs())->AC_ACUnlockVentSetFB;
  }

  /* End of Switch: '<S218>/Switch4' */

  /* MinMax: '<S218>/MinMax' incorporates:
   *  Constant: '<S218>/sat6'
   */
  if (VOPM_VCUACCStat_enum > KOPM_ACUnlckVentSetFBHi_enum)
  {
    /* MinMax: '<S236>/MinMax' */
    VOPM_VCUACCStat_enum = KOPM_ACUnlckVentSetFBHi_enum;
  }

  /* End of MinMax: '<S218>/MinMax' */

  /* MinMax: '<S218>/MinMax1' incorporates:
   *  Constant: '<S218>/sat7'
   */
  if (VOPM_VCUACCStat_enum >= KOPM_ACUnlckVentSetFBLo_enum)
  {
    /* MinMax: '<S218>/MinMax1' */
    VOPM_ACUnlckVentSetFB_enum = VOPM_VCUACCStat_enum;
  }
  else
  {
    /* MinMax: '<S218>/MinMax1' */
    VOPM_ACUnlckVentSetFB_enum = KOPM_ACUnlckVentSetFBLo_enum;
  }

  /* End of MinMax: '<S218>/MinMax1' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_ACUnlckVentSetFB_enum' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_CCURmtLckFb_enum' */
  /* Switch: '<S224>/Switch4' incorporates:
   *  Constant: '<S224>/sat3'
   */
  if (KOPM_CCURmtLckFb_enum_ovrdflg)
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  Constant: '<S224>/sat4'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = KOPM_CCURmtLckFb_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S224>/Data Type Conversion1'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Bcm2OpmBAC_outputs())
                               ->CCU_RemoteLockFb;
  }

  /* End of Switch: '<S224>/Switch4' */

  /* MinMax: '<S224>/MinMax' incorporates:
   *  Constant: '<S224>/sat6'
   */
  if (VOPM_VCUACCStat_enum > KOPM_CCURmtLckFbHi_enum)
  {
    /* MinMax: '<S236>/MinMax' */
    VOPM_VCUACCStat_enum = KOPM_CCURmtLckFbHi_enum;
  }

  /* End of MinMax: '<S224>/MinMax' */

  /* MinMax: '<S224>/MinMax1' incorporates:
   *  Constant: '<S224>/sat7'
   */
  if (VOPM_VCUACCStat_enum >= KOPM_CCURmtLckFbLo_enum)
  {
    /* MinMax: '<S224>/MinMax1' */
    VOPM_CCURmtLckFb_enum = VOPM_VCUACCStat_enum;
  }
  else
  {
    /* MinMax: '<S224>/MinMax1' */
    VOPM_CCURmtLckFb_enum = KOPM_CCURmtLckFbLo_enum;
  }

  /* End of MinMax: '<S224>/MinMax1' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_CCURmtLckFb_enum' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_CCURmtCarSearchFb_enum' */
  /* Switch: '<S223>/Switch4' incorporates:
   *  Constant: '<S223>/sat3'
   */
  if (KOPM_CCURmtCarSearchFb_enum_ovrdflg)
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  Constant: '<S223>/sat4'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = KOPM_CCURmtCarSearchFb_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S223>/Data Type Conversion1'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Bcm2OpmBAC_outputs())
                               ->CCU_RemoteCarSearchFb;
  }

  /* End of Switch: '<S223>/Switch4' */

  /* MinMax: '<S223>/MinMax' incorporates:
   *  Constant: '<S223>/sat6'
   */
  if (VOPM_VCUACCStat_enum > KOPM_CCURmtCarSearchFbHi_enum)
  {
    /* MinMax: '<S236>/MinMax' */
    VOPM_VCUACCStat_enum = KOPM_CCURmtCarSearchFbHi_enum;
  }

  /* End of MinMax: '<S223>/MinMax' */

  /* MinMax: '<S223>/MinMax1' incorporates:
   *  Constant: '<S223>/sat7'
   */
  if (VOPM_VCUACCStat_enum >= KOPM_CCURmtCarSearchFbLo_enum)
  {
    /* MinMax: '<S223>/MinMax1' */
    VOPM_CCURmtCarSearchFb_enum = VOPM_VCUACCStat_enum;
  }
  else
  {
    /* MinMax: '<S223>/MinMax1' */
    VOPM_CCURmtCarSearchFb_enum = KOPM_CCURmtCarSearchFbLo_enum;
  }

  /* End of MinMax: '<S223>/MinMax1' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_CCURmtCarSearchFb_enum' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_CCUOpenVentnFb_enum' */
  /* Switch: '<S222>/Switch4' incorporates:
   *  Constant: '<S222>/sat3'
   */
  if (KOPM_CCUOpenVentnFb_enum_ovrdflg)
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  Constant: '<S222>/sat4'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = KOPM_CCUOpenVentnFb_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S222>/Data Type Conversion1'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_TMS2VCU_PPV_outputs())->CCU_OpenVentilationFb;
  }

  /* End of Switch: '<S222>/Switch4' */

  /* MinMax: '<S222>/MinMax' incorporates:
   *  Constant: '<S222>/sat6'
   */
  if (VOPM_VCUACCStat_enum > KOPM_CCUOpenVentnFbHi_enum)
  {
    /* MinMax: '<S236>/MinMax' */
    VOPM_VCUACCStat_enum = KOPM_CCUOpenVentnFbHi_enum;
  }

  /* End of MinMax: '<S222>/MinMax' */

  /* MinMax: '<S222>/MinMax1' incorporates:
   *  Constant: '<S222>/sat7'
   */
  if (VOPM_VCUACCStat_enum >= KOPM_CCUOpenVentnFbLo_enum)
  {
    /* MinMax: '<S222>/MinMax1' */
    VOPM_CCUOpenVentnFb_enum = VOPM_VCUACCStat_enum;
  }
  else
  {
    /* MinMax: '<S222>/MinMax1' */
    VOPM_CCUOpenVentnFb_enum = KOPM_CCUOpenVentnFbLo_enum;
  }

  /* End of MinMax: '<S222>/MinMax1' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_CCUOpenVentnFb_enum' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_ACRemtCtrlFb_enum' */
  /* Switch: '<S215>/Switch4' incorporates:
   *  Constant: '<S215>/sat3'
   */
  if (KOPM_ACRemtCtrlFb_enum_ovrdflg)
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  Constant: '<S215>/sat4'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = KOPM_ACRemtCtrlFb_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S215>/Data Type Conversion1'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_TMS2VCU_PPV_outputs())->AC_RemtCtrlFb;
  }

  /* End of Switch: '<S215>/Switch4' */

  /* MinMax: '<S215>/MinMax' incorporates:
   *  Constant: '<S215>/sat6'
   */
  if (VOPM_VCUACCStat_enum > KOPM_ACRemtCtrlFbHi_enum)
  {
    /* MinMax: '<S236>/MinMax' */
    VOPM_VCUACCStat_enum = KOPM_ACRemtCtrlFbHi_enum;
  }

  /* End of MinMax: '<S215>/MinMax' */

  /* MinMax: '<S215>/MinMax1' incorporates:
   *  Constant: '<S215>/sat7'
   */
  if (VOPM_VCUACCStat_enum >= KOPM_ACRemtCtrlFbLo_enum)
  {
    /* MinMax: '<S215>/MinMax1' */
    VOPM_ACRemtCtrlFb_enum = VOPM_VCUACCStat_enum;
  }
  else
  {
    /* MinMax: '<S215>/MinMax1' */
    VOPM_ACRemtCtrlFb_enum = KOPM_ACRemtCtrlFbLo_enum;
  }

  /* End of MinMax: '<S215>/MinMax1' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_ACRemtCtrlFb_enum' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_ACTempSetFb_enum' */
  /* Switch: '<S217>/Switch4' incorporates:
   *  Constant: '<S217>/sat3'
   */
  if (KOPM_ACTempSetFb_enum_ovrdflg)
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  Constant: '<S217>/sat4'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = KOPM_ACTempSetFb_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S217>/Data Type Conversion1'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_TMS2VCU_PPV_outputs())->AC_TempSetFb;
  }

  /* End of Switch: '<S217>/Switch4' */

  /* MinMax: '<S217>/MinMax' incorporates:
   *  Constant: '<S217>/sat6'
   */
  if (VOPM_VCUACCStat_enum > KOPM_ACTempSetFbHi_enum)
  {
    /* MinMax: '<S236>/MinMax' */
    VOPM_VCUACCStat_enum = KOPM_ACTempSetFbHi_enum;
  }

  /* End of MinMax: '<S217>/MinMax' */

  /* MinMax: '<S217>/MinMax1' incorporates:
   *  Constant: '<S217>/sat7'
   */
  if (VOPM_VCUACCStat_enum >= KOPM_ACTempSetFbLo_enum)
  {
    /* MinMax: '<S217>/MinMax1' */
    VOPM_ACTempSetFb_enum = VOPM_VCUACCStat_enum;
  }
  else
  {
    /* MinMax: '<S217>/MinMax1' */
    VOPM_ACTempSetFb_enum = KOPM_ACTempSetFbLo_enum;
  }

  /* End of MinMax: '<S217>/MinMax1' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_ACTempSetFb_enum' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_ACRmtDefrstCtlFb_enum' */
  /* Switch: '<S216>/Switch4' incorporates:
   *  Constant: '<S216>/sat3'
   */
  if (KOPM_ACRmtDefrstCtlFb_enum_ovrdflg)
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  Constant: '<S216>/sat4'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = KOPM_ACRmtDefrstCtlFb_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S216>/Data Type Conversion1'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_TMS2VCU_PPV_outputs())->AC_RemoteDefrostCtlFb;
  }

  /* End of Switch: '<S216>/Switch4' */

  /* MinMax: '<S216>/MinMax' incorporates:
   *  Constant: '<S216>/sat6'
   */
  if (VOPM_VCUACCStat_enum > KOPM_ACRmtDefrstCtlFbHi_enum)
  {
    /* MinMax: '<S236>/MinMax' */
    VOPM_VCUACCStat_enum = KOPM_ACRmtDefrstCtlFbHi_enum;
  }

  /* End of MinMax: '<S216>/MinMax' */

  /* MinMax: '<S216>/MinMax1' incorporates:
   *  Constant: '<S216>/sat7'
   */
  if (VOPM_VCUACCStat_enum >= KOPM_ACRmtDefrstCtlFbLo_enum)
  {
    /* MinMax: '<S216>/MinMax1' */
    VOPM_ACRmtDefrstCtlFb_enum = VOPM_VCUACCStat_enum;
  }
  else
  {
    /* MinMax: '<S216>/MinMax1' */
    VOPM_ACRmtDefrstCtlFb_enum = KOPM_ACRmtDefrstCtlFbLo_enum;
  }

  /* End of MinMax: '<S216>/MinMax1' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_ACRmtDefrstCtlFb_enum' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_VCUVerSetFb_enum' */
  /* Switch: '<S260>/Switch4' incorporates:
   *  Constant: '<S260>/sat3'
   */
  if (KOPM_VCUVerSetFb_enum_ovrdflg)
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  Constant: '<S260>/sat4'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = KOPM_VCUVerSetFb_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S260>/Data Type Conversion1'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs())
                               ->VTBX_VCUVerSetFb_enum;
  }

  /* End of Switch: '<S260>/Switch4' */

  /* MinMax: '<S260>/MinMax' incorporates:
   *  Constant: '<S260>/sat6'
   */
  if (VOPM_VCUACCStat_enum > KOPM_VCUVerSetFbHi_enum)
  {
    /* MinMax: '<S236>/MinMax' */
    VOPM_VCUACCStat_enum = KOPM_VCUVerSetFbHi_enum;
  }

  /* End of MinMax: '<S260>/MinMax' */

  /* MinMax: '<S260>/MinMax1' incorporates:
   *  Constant: '<S260>/sat7'
   */
  if (VOPM_VCUACCStat_enum >= KOPM_VCUVerSetFbLo_enum)
  {
    /* MinMax: '<S260>/MinMax1' */
    VOPM_VCUVerSetFb_enum = VOPM_VCUACCStat_enum;
  }
  else
  {
    /* MinMax: '<S260>/MinMax1' */
    VOPM_VCUVerSetFb_enum = KOPM_VCUVerSetFbLo_enum;
  }

  /* End of MinMax: '<S260>/MinMax1' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_VCUVerSetFb_enum' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_VCUSpdLimLvlSetFb_enum' */
  /* Switch: '<S258>/Switch4' incorporates:
   *  Constant: '<S258>/sat3'
   */
  if (KOPM_VCUSpdLimLvlSetFb_enum_ovrdflg)
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  Constant: '<S258>/sat4'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = KOPM_VCUSpdLimLvlSetFb_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S258>/Data Type Conversion1'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs())
                               ->VTBX_VCUSpdLimLvlSetFb_enum;
  }

  /* End of Switch: '<S258>/Switch4' */

  /* MinMax: '<S258>/MinMax' incorporates:
   *  Constant: '<S258>/sat6'
   */
  if (VOPM_VCUACCStat_enum > KOPM_VCUSpdLimLvlSetFbHi_enum)
  {
    /* MinMax: '<S236>/MinMax' */
    VOPM_VCUACCStat_enum = KOPM_VCUSpdLimLvlSetFbHi_enum;
  }

  /* End of MinMax: '<S258>/MinMax' */

  /* MinMax: '<S258>/MinMax1' incorporates:
   *  Constant: '<S258>/sat7'
   */
  if (VOPM_VCUACCStat_enum >= KOPM_VCUSpdLimLvlSetFbLo_enum)
  {
    /* MinMax: '<S258>/MinMax1' */
    VOPM_VCUSpdLimLvlSetFb_enum = VOPM_VCUACCStat_enum;
  }
  else
  {
    /* MinMax: '<S258>/MinMax1' */
    VOPM_VCUSpdLimLvlSetFb_enum = KOPM_VCUSpdLimLvlSetFbLo_enum;
  }

  /* End of MinMax: '<S258>/MinMax1' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_VCUSpdLimLvlSetFb_enum' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_VCUVerFb_flg' */
  /* Switch: '<S259>/Switch4' incorporates:
   *  Constant: '<S259>/sat3'
   */
  if (KOPM_VCUVerFb_flg_ovrdflg)
  {
    /* Switch: '<S259>/Switch4' incorporates:
     *  Constant: '<S259>/sat4'
     */
    VOPM_VCUVerFb_flg = KOPM_VCUVerFb_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S259>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S259>/Data Type Conversion1'
     */
    VOPM_VCUVerFb_flg = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs())->VTBX_VCUVerFb_flg;
  }

  /* End of Switch: '<S259>/Switch4' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_VCUVerFb_flg' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_VCUOprtLicFb_flg' */
  /* Switch: '<S256>/Switch4' incorporates:
   *  Constant: '<S256>/sat3'
   */
  if (KOPM_VCUOprtLicFb_flg_ovrdflg)
  {
    /* Switch: '<S256>/Switch4' incorporates:
     *  Constant: '<S256>/sat4'
     */
    VOPM_VCUOprtLicFb_flg = KOPM_VCUOprtLicFb_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S256>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S256>/Data Type Conversion1'
     */
    VOPM_VCUOprtLicFb_flg = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs())->VTBX_VCUOprtLicFb_flg;
  }

  /* End of Switch: '<S256>/Switch4' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_VCUOprtLicFb_flg' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_VCUSpdLimLvlFb_enum' */
  /* Switch: '<S257>/Switch4' incorporates:
   *  Constant: '<S257>/sat3'
   */
  if (KOPM_VCUSpdLimLvlFb_enum_ovrdflg)
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  Constant: '<S257>/sat4'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = KOPM_VCUSpdLimLvlFb_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S257>/Data Type Conversion1'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs())
                               ->VTBX_VCUSpdLimLvlFb_enum;
  }

  /* End of Switch: '<S257>/Switch4' */

  /* MinMax: '<S257>/MinMax' incorporates:
   *  Constant: '<S257>/sat6'
   */
  if (VOPM_VCUACCStat_enum > KOPM_VCUSpdLimLvlFbHi_enum)
  {
    /* MinMax: '<S236>/MinMax' */
    VOPM_VCUACCStat_enum = KOPM_VCUSpdLimLvlFbHi_enum;
  }

  /* End of MinMax: '<S257>/MinMax' */

  /* MinMax: '<S257>/MinMax1' incorporates:
   *  Constant: '<S257>/sat7'
   */
  if (VOPM_VCUACCStat_enum >= KOPM_VCUSpdLimLvlFbLo_enum)
  {
    /* MinMax: '<S257>/MinMax1' */
    VOPM_VCUSpdLimLvlFb_enum = VOPM_VCUACCStat_enum;
  }
  else
  {
    /* MinMax: '<S257>/MinMax1' */
    VOPM_VCUSpdLimLvlFb_enum = KOPM_VCUSpdLimLvlFbLo_enum;
  }

  /* End of MinMax: '<S257>/MinMax1' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_VCUSpdLimLvlFb_enum' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_CCURmtPwrLckFb_enum' */
  /* Switch: '<S225>/Switch4' incorporates:
   *  Constant: '<S225>/sat3'
   */
  if (KOPM_CCURmtPwrLckFb_enum_ovrdflg)
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  Constant: '<S225>/sat4'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = KOPM_CCURmtPwrLckFb_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S225>/Data Type Conversion1'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Bcm2OpmBAC_outputs())
                               ->CCU_RemotePowerLockFb;
  }

  /* End of Switch: '<S225>/Switch4' */

  /* MinMax: '<S225>/MinMax' incorporates:
   *  Constant: '<S225>/sat6'
   */
  if (VOPM_VCUACCStat_enum > KOPM_CCURmtPwrLckFbHi_enum)
  {
    /* MinMax: '<S236>/MinMax' */
    VOPM_VCUACCStat_enum = KOPM_CCURmtPwrLckFbHi_enum;
  }

  /* End of MinMax: '<S225>/MinMax' */

  /* MinMax: '<S225>/MinMax1' incorporates:
   *  Constant: '<S225>/sat7'
   */
  if (VOPM_VCUACCStat_enum >= KOPM_CCURmtPwrLckFbLo_enum)
  {
    /* MinMax: '<S225>/MinMax1' */
    VOPM_CCURmtPwrLckFb_enum = VOPM_VCUACCStat_enum;
  }
  else
  {
    /* MinMax: '<S225>/MinMax1' */
    VOPM_CCURmtPwrLckFb_enum = KOPM_CCURmtPwrLckFbLo_enum;
  }

  /* End of MinMax: '<S225>/MinMax1' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_CCURmtPwrLckFb_enum' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_WghConfdence_flg' */
  /* Switch: '<S269>/Switch4' incorporates:
   *  Constant: '<S269>/sat3'
   */
  if (KOPM_WghConfdence_flg_ovrdflg)
  {
    /* Switch: '<S269>/Switch4' incorporates:
     *  Constant: '<S269>/sat4'
     */
    VOPM_WghConfdence_flg = KOPM_WghConfdence_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S269>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S269>/Data Type Conversion1'
     */
    VOPM_WghConfdence_flg = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs())->VVSO_WghConfdence_flg;
  }

  /* End of Switch: '<S269>/Switch4' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_WghConfdence_flg' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_WghEst_kg' */
  /* Switch: '<S271>/Switch4' incorporates:
   *  Constant: '<S271>/sat3'
   */
  if (KOPM_WghEst_kg_ovrdflg)
  {
    /* MinMax: '<S318>/MinMax' incorporates:
     *  Constant: '<S271>/sat4'
     *  Product: '<S313>/Product1'
     */
    VOPM_VCUCruiseCtrTgtSpd_kph = KOPM_WghEst_kg_ovrdval;
  }
  else
  {
    /* MinMax: '<S318>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S271>/Data Type Conversion1'
     *  Product: '<S313>/Product1'
     */
    VOPM_VCUCruiseCtrTgtSpd_kph =
        (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs())->VVSO_WghEst_kg;
  }

  /* End of Switch: '<S271>/Switch4' */

  /* MinMax: '<S271>/MinMax' incorporates:
   *  Constant: '<S271>/sat6'
   */
  if (VOPM_VCUCruiseCtrTgtSpd_kph > KOPM_WghEstHi_kg)
  {
    /* MinMax: '<S318>/MinMax' */
    VOPM_VCUCruiseCtrTgtSpd_kph = KOPM_WghEstHi_kg;
  }

  /* End of MinMax: '<S271>/MinMax' */

  /* MinMax: '<S271>/MinMax1' incorporates:
   *  Constant: '<S271>/sat7'
   */
  if (VOPM_VCUCruiseCtrTgtSpd_kph >= KOPM_WghEstLo_kg)
  {
    /* MinMax: '<S271>/MinMax1' */
    VOPM_WghEst_kg = VOPM_VCUCruiseCtrTgtSpd_kph;
  }
  else
  {
    /* MinMax: '<S271>/MinMax1' */
    VOPM_WghEst_kg = KOPM_WghEstLo_kg;
  }

  /* End of MinMax: '<S271>/MinMax1' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_WghEst_kg' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_WghDistb_enum' */
  /* Switch: '<S270>/Switch4' incorporates:
   *  Constant: '<S270>/sat3'
   */
  if (KOPM_WghDistb_enum_ovrdflg)
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  Constant: '<S270>/sat4'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = KOPM_WghDistb_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S270>/Data Type Conversion1'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs())
                               ->VVSO_WghDistb_enum;
  }

  /* End of Switch: '<S270>/Switch4' */

  /* MinMax: '<S270>/MinMax' incorporates:
   *  Constant: '<S270>/sat6'
   */
  if (VOPM_VCUACCStat_enum > KOPM_WghDistbHi_enum)
  {
    /* MinMax: '<S236>/MinMax' */
    VOPM_VCUACCStat_enum = KOPM_WghDistbHi_enum;
  }

  /* End of MinMax: '<S270>/MinMax' */

  /* MinMax: '<S270>/MinMax1' incorporates:
   *  Constant: '<S270>/sat7'
   */
  if (VOPM_VCUACCStat_enum >= KOPM_WghDistbLo_enum)
  {
    /* MinMax: '<S270>/MinMax1' */
    VOPM_WghDistb_enum = VOPM_VCUACCStat_enum;
  }
  else
  {
    /* MinMax: '<S270>/MinMax1' */
    VOPM_WghDistb_enum = KOPM_WghDistbLo_enum;
  }

  /* End of MinMax: '<S270>/MinMax1' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_WghDistb_enum' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_CruiseCtrlSta_enum' */
  /* Switch: '<S228>/Switch4' incorporates:
   *  Constant: '<S228>/sat3'
   */
  if (KOPM_CruiseCtrlSta_enum_ovrdflg)
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  Constant: '<S228>/sat4'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = KOPM_CruiseCtrlSta_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S228>/Data Type Conversion1'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs())
                               ->VVTM_CruzCtrlStat_enum;
  }

  /* End of Switch: '<S228>/Switch4' */

  /* MinMax: '<S228>/MinMax' incorporates:
   *  Constant: '<S228>/sat6'
   */
  if (VOPM_VCUACCStat_enum > KOPM_CruiseCtrlStaHi_enum)
  {
    /* MinMax: '<S236>/MinMax' */
    VOPM_VCUACCStat_enum = KOPM_CruiseCtrlStaHi_enum;
  }

  /* End of MinMax: '<S228>/MinMax' */

  /* MinMax: '<S228>/MinMax1' incorporates:
   *  Constant: '<S228>/sat7'
   */
  if (VOPM_VCUACCStat_enum >= KOPM_CruiseCtrlStaLo_enum)
  {
    /* MinMax: '<S228>/MinMax1' */
    VOPM_CruiseCtrlSta_enum = VOPM_VCUACCStat_enum;
  }
  else
  {
    /* MinMax: '<S228>/MinMax1' */
    VOPM_CruiseCtrlSta_enum = KOPM_CruiseCtrlStaLo_enum;
  }

  /* End of MinMax: '<S228>/MinMax1' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_CruiseCtrlSta_enum' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_ChrgngCondsFb_flg' */
  /* Switch: '<S226>/Switch4' incorporates:
   *  Constant: '<S226>/sat3'
   */
  if (KOPM_ChrgngCondsFb_flg_ovrdflg)
  {
    /* Switch: '<S226>/Switch4' incorporates:
     *  Constant: '<S226>/sat4'
     */
    VOPM_ChrgngCondsFb_flg = KOPM_ChrgngCondsFb_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S226>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S226>/Data Type Conversion1'
     */
    VOPM_ChrgngCondsFb_flg =
        (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs())
            ->VTBX_VCUChrgngCondsFb_flg;
  }

  /* End of Switch: '<S226>/Switch4' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_ChrgngCondsFb_flg' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_RmtACCtrlReq_flg' */
  /* Switch: '<S240>/Switch4' incorporates:
   *  Constant: '<S240>/sat3'
   */
  if (KOPM_RmtACCtrlReq_flg_ovrdflg)
  {
    /* Switch: '<S240>/Switch4' incorporates:
     *  Constant: '<S240>/sat4'
     */
    VOPM_RmtACCtrlReq_flg = KOPM_RmtACCtrlReq_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S240>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S240>/Data Type Conversion1'
     */
    VOPM_RmtACCtrlReq_flg = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs())->VTBX_VCURmtACCtrlReq_flg;
  }

  /* End of Switch: '<S240>/Switch4' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_RmtACCtrlReq_flg' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_RmtACDefrstReq_flg' */
  /* Switch: '<S242>/Switch4' incorporates:
   *  Constant: '<S242>/sat3'
   */
  if (KOPM_RmtACDefrstReq_flg_ovrdflg)
  {
    /* Switch: '<S242>/Switch4' incorporates:
     *  Constant: '<S242>/sat4'
     */
    VOPM_RmtACDefrstReq_flg = KOPM_RmtACDefrstReq_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S242>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S242>/Data Type Conversion1'
     */
    VOPM_RmtACDefrstReq_flg =
        (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs())
            ->VTBX_VCURmtACDefrstReq_flg;
  }

  /* End of Switch: '<S242>/Switch4' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_RmtACDefrstReq_flg' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_RmtACCtrlSt_enum' */
  /* Switch: '<S241>/Switch4' incorporates:
   *  Constant: '<S241>/sat3'
   */
  if (KOPM_RmtACCtrlSt_enum_ovrdflg)
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  Constant: '<S241>/sat4'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = KOPM_RmtACCtrlSt_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S241>/Data Type Conversion1'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs())
                               ->VTBX_VCURmtACCtrlSt_enum;
  }

  /* End of Switch: '<S241>/Switch4' */

  /* MinMax: '<S241>/MinMax' incorporates:
   *  Constant: '<S241>/sat6'
   */
  if (VOPM_VCUACCStat_enum > KOPM_RmtACCtrlStHi_enum)
  {
    /* MinMax: '<S236>/MinMax' */
    VOPM_VCUACCStat_enum = KOPM_RmtACCtrlStHi_enum;
  }

  /* End of MinMax: '<S241>/MinMax' */

  /* MinMax: '<S241>/MinMax1' incorporates:
   *  Constant: '<S241>/sat7'
   */
  if (VOPM_VCUACCStat_enum >= KOPM_RmtACCtrlStLo_enum)
  {
    /* MinMax: '<S241>/MinMax1' */
    VOPM_RmtACCtrlSt_enum = VOPM_VCUACCStat_enum;
  }
  else
  {
    /* MinMax: '<S241>/MinMax1' */
    VOPM_RmtACCtrlSt_enum = KOPM_RmtACCtrlStLo_enum;
  }

  /* End of MinMax: '<S241>/MinMax1' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_RmtACCtrlSt_enum' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_RmtPwrCtrlFb_enum' */
  /* Switch: '<S244>/Switch4' incorporates:
   *  Constant: '<S244>/sat3'
   */
  if (KOPM_RmtPwrCtrlFb_enum_ovrdflg)
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  Constant: '<S244>/sat4'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = KOPM_RmtPwrCtrlFb_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S244>/Data Type Conversion1'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Bcm2OpmBAC_outputs())
                               ->CCU_RemtPowerCtrlFb;
  }

  /* End of Switch: '<S244>/Switch4' */

  /* MinMax: '<S244>/MinMax' incorporates:
   *  Constant: '<S244>/sat6'
   */
  if (VOPM_VCUACCStat_enum > KOPM_RmtPwrCtrlFbHi_enum)
  {
    /* MinMax: '<S236>/MinMax' */
    VOPM_VCUACCStat_enum = KOPM_RmtPwrCtrlFbHi_enum;
  }

  /* End of MinMax: '<S244>/MinMax' */

  /* MinMax: '<S244>/MinMax1' incorporates:
   *  Constant: '<S244>/sat7'
   */
  if (VOPM_VCUACCStat_enum >= KOPM_RmtPwrCtrlFbLo_enum)
  {
    /* MinMax: '<S244>/MinMax1' */
    VOPM_RmtPwrCtrlFb_enum = VOPM_VCUACCStat_enum;
  }
  else
  {
    /* MinMax: '<S244>/MinMax1' */
    VOPM_RmtPwrCtrlFb_enum = KOPM_RmtPwrCtrlFbLo_enum;
  }

  /* End of MinMax: '<S244>/MinMax1' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_RmtPwrCtrlFb_enum' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_RmtSteerWhlHeatFb_enum' */
  /* Switch: '<S245>/Switch4' incorporates:
   *  Constant: '<S245>/sat3'
   */
  if (KOPM_RmtSteerWhlHeatFb_enum_ovrdflg)
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  Constant: '<S245>/sat4'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = KOPM_RmtSteerWhlHeatFb_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S245>/Data Type Conversion1'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Bcm2OpmBAC_outputs())
                               ->CCU_RemtSteerWhlHeatFb;
  }

  /* End of Switch: '<S245>/Switch4' */

  /* MinMax: '<S245>/MinMax' incorporates:
   *  Constant: '<S245>/sat6'
   */
  if (VOPM_VCUACCStat_enum > KOPM_RmtSteerWhlHeatFbHi_enum)
  {
    /* MinMax: '<S236>/MinMax' */
    VOPM_VCUACCStat_enum = KOPM_RmtSteerWhlHeatFbHi_enum;
  }

  /* End of MinMax: '<S245>/MinMax' */

  /* MinMax: '<S245>/MinMax1' incorporates:
   *  Constant: '<S245>/sat7'
   */
  if (VOPM_VCUACCStat_enum >= KOPM_RmtSteerWhlHeatFbLo_enum)
  {
    /* MinMax: '<S245>/MinMax1' */
    VOPM_RmtSteerWhlHeatFb_enum = VOPM_VCUACCStat_enum;
  }
  else
  {
    /* MinMax: '<S245>/MinMax1' */
    VOPM_RmtSteerWhlHeatFb_enum = KOPM_RmtSteerWhlHeatFbLo_enum;
  }

  /* End of MinMax: '<S245>/MinMax1' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_RmtSteerWhlHeatFb_enum' */

  /* Outputs for Atomic SubSystem: '<S212>/Subsys_VOPM_RmtMainDrvrSeatHeatFb_enum' */
  /* Switch: '<S243>/Switch4' incorporates:
   *  Constant: '<S243>/sat3'
   */
  if (KOPM_RmtMainDrvrSeatHeatFb_enum_ovrdflg)
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  Constant: '<S243>/sat4'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = KOPM_RmtMainDrvrSeatHeatFb_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S243>/Data Type Conversion1'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Bcm2OpmBAC_outputs())
                               ->CCU_RemtMaiDrSeatHeatFb;
  }

  /* End of Switch: '<S243>/Switch4' */

  /* MinMax: '<S243>/MinMax' incorporates:
   *  Constant: '<S243>/sat6'
   */
  if (VOPM_VCUACCStat_enum > KOPM_RmtMainDrvrSeatHeatFbHi_enum)
  {
    /* MinMax: '<S236>/MinMax' */
    VOPM_VCUACCStat_enum = KOPM_RmtMainDrvrSeatHeatFbHi_enum;
  }

  /* End of MinMax: '<S243>/MinMax' */

  /* MinMax: '<S243>/MinMax1' incorporates:
   *  Constant: '<S243>/sat7'
   */
  if (VOPM_VCUACCStat_enum >= KOPM_RmtMainDrvrSeatHeatFbLo_enum)
  {
    /* MinMax: '<S243>/MinMax1' */
    VOPM_RmtMainDrvrSeatHeatFb_enum = VOPM_VCUACCStat_enum;
  }
  else
  {
    /* MinMax: '<S243>/MinMax1' */
    VOPM_RmtMainDrvrSeatHeatFb_enum = KOPM_RmtMainDrvrSeatHeatFbLo_enum;
  }

  /* End of MinMax: '<S243>/MinMax1' */
  /* End of Outputs for SubSystem: '<S212>/Subsys_VOPM_RmtMainDrvrSeatHeatFb_enum' */

  /* BusCreator: '<S212>/BusCreator1' incorporates:
   *  DataTypeConversion: '<S212>/DataTypeConversion31'
   *  Switch: '<S231>/Switch4'
   */
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_MotorActualPowerType =
      (VOPM_MotActPwrTyp_enum != 0);
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_DrvRangeDistEstV =
      VOPM_DrvRangeDistEstVld_flg;

  /* DataTypeConversion: '<S212>/DataTypeConversion42' */
  if (VOPM_DrvRangeDistEst_km < 65536.0F)
  {
    if (VOPM_DrvRangeDistEst_km >= 0.0F)
    {
      /* BusCreator: '<S212>/BusCreator1' */
      AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_DrvRangeDistEst = (uint16)
          VOPM_DrvRangeDistEst_km;
    }
    else
    {
      /* BusCreator: '<S212>/BusCreator1' */
      AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_DrvRangeDistEst = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S212>/BusCreator1' */
    AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_DrvRangeDistEst = MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<S212>/DataTypeConversion42' */

  /* BusCreator: '<S212>/BusCreator1' incorporates:
   *  Switch: '<S267>/Switch4'
   */
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_WLTPDrvgRngDstVldty =
      VOPM_WLTPDrvgRngDstVld_flg;

  /* DataTypeConversion: '<S212>/DataTypeConversion44' */
  if (VOPM_WLTPDrvgRngDst_km < 65536.0F)
  {
    if (VOPM_WLTPDrvgRngDst_km >= 0.0F)
    {
      /* BusCreator: '<S212>/BusCreator1' */
      AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_WLTPDrvgRngDst = (uint16)
          VOPM_WLTPDrvgRngDst_km;
    }
    else
    {
      /* BusCreator: '<S212>/BusCreator1' */
      AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_WLTPDrvgRngDst = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S212>/BusCreator1' */
    AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_WLTPDrvgRngDst = MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<S212>/DataTypeConversion44' */

  /* DataTypeConversion: '<S212>/DataTypeConversion46' incorporates:
   *  Constant: '<S273>/Constant1'
   *  Product: '<S273>/Product1'
   *  Sum: '<S273>/Add'
   */
  tmp = VOPM_MotActPwr_Kw * 5.0F;
  if (tmp < 65536.0F)
  {
    if (tmp >= 0.0F)
    {
      /* BusCreator: '<S212>/BusCreator1' */
      AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_MotorActualPower = (uint16)tmp;
    }
    else
    {
      /* BusCreator: '<S212>/BusCreator1' */
      AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_MotorActualPower = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S212>/BusCreator1' */
    AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_MotorActualPower = MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<S212>/DataTypeConversion46' */

  /* BusCreator: '<S212>/BusCreator1' incorporates:
   *  DataTypeConversion: '<S212>/DataTypeConversion35'
   *  DataTypeConversion: '<S239>/Data Type Conversion2'
   *  Switch: '<S235>/Switch4'
   *  Switch: '<S238>/Switch4'
   *  Switch: '<S263>/Switch4'
   *  Switch: '<S266>/Switch4'
   */
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_DrvMotorSta = VOPM_DrvMotorSta_enum;
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_InfoDisp = VOPM_InfoDisp_enum;
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_VhclPGearError =
      VOPM_VehPGearError_flg;
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_VhclSpeedFastWarn =
      VOPM_VhclSpdFstWarn_flg;
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_OBCOprtCmdToICU =
      VOPM_OBCOprtCmdToICU_enum;
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_MotorHighTempWrning =
      VOPM_MotorHiTempWrning_flg;
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_MCUHighTempWrning =
      VOPM_MCUHiTempWrning_flg;

  /* DataTypeConversion: '<S212>/DataTypeConversion38' incorporates:
   *  Constant: '<S275>/Constant1'
   *  Product: '<S275>/Product1'
   *  Sum: '<S275>/Add'
   */
  tmp = VOPM_VehPwrCnsmpAvrg_kWh * 10.0F;
  if (tmp < 65536.0F)
  {
    if (tmp >= 0.0F)
    {
      /* BusCreator: '<S212>/BusCreator1' */
      AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_VhclPwrCnsmpAvrg = (uint16)tmp;
    }
    else
    {
      /* BusCreator: '<S212>/BusCreator1' */
      AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_VhclPwrCnsmpAvrg = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S212>/BusCreator1' */
    AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_VhclPwrCnsmpAvrg = MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<S212>/DataTypeConversion38' */

  /* BusCreator: '<S212>/BusCreator1' */
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_ShiftKeyStagnation =
      VOPM_ShftKeyStgntn_enum;
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_CCKeyStagnation =
      VOPM_CCKeyStgntn_enum;
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_DriveModeKeyStagnation =
      VOPM_DrvModeKeyStgntn_enum;

  /* DataTypeConversion: '<S212>/DataTypeConversion19' incorporates:
   *  Constant: '<S277>/Constant1'
   *  Product: '<S277>/Product1'
   *  Sum: '<S277>/Add'
   */
  tmp = VOPM_SIBSKL30Volt_V * 10.0F;
  if (tmp < 256.0F)
  {
    if (tmp >= 0.0F)
    {
      /* BusCreator: '<S212>/BusCreator1' */
      AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_SIBS_KL30Voltage = (uint8)tmp;
    }
    else
    {
      /* BusCreator: '<S212>/BusCreator1' */
      AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_SIBS_KL30Voltage = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S212>/BusCreator1' */
    AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_SIBS_KL30Voltage = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S212>/DataTypeConversion19' */

  /* BusCreator: '<S212>/BusCreator1' incorporates:
   *  DataTypeConversion: '<S212>/DataTypeConversion22'
   *  DataTypeConversion: '<S251>/Data Type Conversion2'
   *  Switch: '<S219>/Switch4'
   *  Switch: '<S220>/Switch4'
   *  Switch: '<S247>/Switch4'
   *  Switch: '<S248>/Switch4'
   *  Switch: '<S249>/Switch4'
   *  Switch: '<S254>/Switch4'
   *  Switch: '<S256>/Switch4'
   *  Switch: '<S259>/Switch4'
   *  Switch: '<S269>/Switch4'
   */
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_SIBS_ChgNumAllow =
      VOPM_SIBSChgNumAllow_flg;
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_SIBS_RTCWUChgNum =
      VOPM_SIBSRTCWUChgNum_cnt;
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_SIBS_RTCChrgSt =
      VOPM_SIBSRTCChrgSt_enum;
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_SIBS_RTCWUChgFailNum =
      VOPM_SIBSRTCWUChgFailNum_cnt;
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.BCM_IllmndLockStsFb =
      VOPM_BCMIllmndLckStsFb_flg;
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.BCM_IllmndUnlockStsFb =
      VOPM_BCMIllmndUnlckStsFb_flg;
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_SIBS_FbRTCWupFlg =
      VOPM_SIBSFbRTCWupFlg_flg;
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_SIBS_BMSBatSOCAllow =
      VOPM_SIBSBMSBatSOCAllow_flg;
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_SIBS_WupVoltAllow =
      VOPM_SIBSWupVoltAllow_flg;
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_VehActDrivingPwr =
      VOPM_VehActDrvPwr_pct;
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_VehActRecuperatePwr =
      VOPM_VehActRecupPwr_pct;
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_LockVehWarm = VOPM_LckVehWrm_enum;
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_ACChrgMode = VOPM_ACChrgMode_enum;
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_ACChrgMaxCurr = VOPM_ACChrgMaxCurr_A;
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.AC_ACUnlockVentSetFB =
      VOPM_ACUnlckVentSetFB_enum;
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.CCU_RemoteLockFb = VOPM_CCURmtLckFb_enum;
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.CCU_RemoteCarSearchFb =
      VOPM_CCURmtCarSearchFb_enum;
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.CCU_OpenVentilationFb =
      VOPM_CCUOpenVentnFb_enum;
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.AC_RemtCtrlFb = VOPM_ACRemtCtrlFb_enum;
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.AC_TempSetFb = VOPM_ACTempSetFb_enum;
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.AC_RemoteDefrostCtlFb =
      VOPM_ACRmtDefrstCtlFb_enum;
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_VesionSetFb = VOPM_VCUVerSetFb_enum;
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_SpeedLimitLevelSetFb =
      VOPM_VCUSpdLimLvlSetFb_enum;
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_VersionFb = VOPM_VCUVerFb_flg;
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_OperatLicenceFb =
      VOPM_VCUOprtLicFb_flg;
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_SpeedLimitLevelFb =
      VOPM_VCUSpdLimLvlFb_enum;
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.CCU_RemotePowerLockFb =
      VOPM_CCURmtPwrLckFb_enum;
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_WghConfdence = VOPM_WghConfdence_flg;

  /* DataTypeConversion: '<S212>/DataTypeConversion17' */
  if (VOPM_WghEst_kg < 65536.0F)
  {
    if (VOPM_WghEst_kg >= 0.0F)
    {
      /* BusCreator: '<S212>/BusCreator1' */
      AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_WghEst = (uint16)VOPM_WghEst_kg;
    }
    else
    {
      /* BusCreator: '<S212>/BusCreator1' */
      AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_WghEst = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S212>/BusCreator1' */
    AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_WghEst = MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<S212>/DataTypeConversion17' */

  /* BusCreator: '<S212>/BusCreator1' */
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_WghDistb = VOPM_WghDistb_enum;
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_CruiseCtrlSta_forBAC =
      VOPM_CruiseCtrlSta_enum;

  /* DataTypeConversion: '<S212>/DataTypeConversion51' incorporates:
   *  Constant: '<S272>/Constant1'
   *  Product: '<S272>/Product1'
   *  Sum: '<S272>/Add'
   */
  tmp = VOPM_CruiseCtrTgtSpd_kph * 17.7777786F;
  if (tmp < 65536.0F)
  {
    if (tmp >= 0.0F)
    {
      /* BusCreator: '<S212>/BusCreator1' */
      AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_CruiseCtrTgtSpd_forBAC = (uint16)
          tmp;
    }
    else
    {
      /* BusCreator: '<S212>/BusCreator1' */
      AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_CruiseCtrTgtSpd_forBAC = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S212>/BusCreator1' */
    AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_CruiseCtrTgtSpd_forBAC =
        MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<S212>/DataTypeConversion51' */

  /* BusCreator: '<S212>/BusCreator1' incorporates:
   *  Switch: '<S226>/Switch4'
   *  Switch: '<S240>/Switch4'
   *  Switch: '<S242>/Switch4'
   */
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_ChargingConditionsFb =
      VOPM_ChrgngCondsFb_flg;
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_RemtACCtrlReq =
      VOPM_RmtACCtrlReq_flg;
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_RemtACDefrostlReq =
      VOPM_RmtACDefrstReq_flg;
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.VCU_RemtACCtrlSt = VOPM_RmtACCtrlSt_enum;
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.CCU_RemtPowerCtrlFb =
      VOPM_RmtPwrCtrlFb_enum;
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.CCU_RemtSteerWhlHeatFb =
      VOPM_RmtSteerWhlHeatFb_enum;
  AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l.CCU_RemtMaiDrSeatHeatFb =
      VOPM_RmtMainDrvrSeatHeatFb_enum;

  /* Outputs for Atomic SubSystem: '<S278>/Subsys_VOPM_AcclPedalPos_pct1' */
  /* Switch: '<S283>/Switch4' incorporates:
   *  Constant: '<S283>/sat3'
   */
  if (KOPM_AcclPedalPos_pct_ovrdflg)
  {
    /* MinMax: '<S318>/MinMax' incorporates:
     *  Constant: '<S283>/sat4'
     *  Product: '<S313>/Product1'
     */
    VOPM_VCUCruiseCtrTgtSpd_kph = KOPM_AcclPedalPos_pct_ovrdval;
  }
  else
  {
    /* MinMax: '<S318>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S283>/Data Type Conversion1'
     *  Product: '<S313>/Product1'
     */
    VOPM_VCUCruiseCtrTgtSpd_kph =
        (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmCHA_outputs())
            ->VIPC_AccPedPstn_pct;
  }

  /* End of Switch: '<S283>/Switch4' */

  /* MinMax: '<S283>/MinMax' incorporates:
   *  Constant: '<S283>/sat6'
   */
  if (VOPM_VCUCruiseCtrTgtSpd_kph > KOPM_AcclPedalPosHi_pct)
  {
    /* MinMax: '<S318>/MinMax' */
    VOPM_VCUCruiseCtrTgtSpd_kph = KOPM_AcclPedalPosHi_pct;
  }

  /* End of MinMax: '<S283>/MinMax' */

  /* MinMax: '<S283>/MinMax1' incorporates:
   *  Constant: '<S283>/sat7'
   */
  if (VOPM_VCUCruiseCtrTgtSpd_kph >= KOPM_AcclPedalPosLo_pct)
  {
    /* MinMax: '<S283>/MinMax1' */
    VOPM_AcclPedalPos_pct = VOPM_VCUCruiseCtrTgtSpd_kph;
  }
  else
  {
    /* MinMax: '<S283>/MinMax1' */
    VOPM_AcclPedalPos_pct = KOPM_AcclPedalPosLo_pct;
  }

  /* End of MinMax: '<S283>/MinMax1' */
  /* End of Outputs for SubSystem: '<S278>/Subsys_VOPM_AcclPedalPos_pct1' */

  /* Outputs for Atomic SubSystem: '<S278>/Subsys_VOPM_BrkPedalPos_pct1' */
  /* Switch: '<S285>/Switch4' incorporates:
   *  Constant: '<S285>/sat3'
   */
  if (KOPM_BrkPedalPos_pct_ovrdflg)
  {
    /* MinMax: '<S318>/MinMax' incorporates:
     *  Constant: '<S285>/sat4'
     *  Product: '<S313>/Product1'
     */
    VOPM_VCUCruiseCtrTgtSpd_kph = KOPM_BrkPedalPos_pct_ovrdval;
  }
  else
  {
    /* MinMax: '<S318>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S285>/Data Type Conversion1'
     *  Product: '<S313>/Product1'
     */
    VOPM_VCUCruiseCtrTgtSpd_kph =
        (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmCHA_outputs())
            ->VIPC_BrkPedPstn_pct;
  }

  /* End of Switch: '<S285>/Switch4' */

  /* MinMax: '<S285>/MinMax' incorporates:
   *  Constant: '<S285>/sat6'
   */
  if (VOPM_VCUCruiseCtrTgtSpd_kph > KOPM_BrkPedalPosHi_pct)
  {
    /* MinMax: '<S318>/MinMax' */
    VOPM_VCUCruiseCtrTgtSpd_kph = KOPM_BrkPedalPosHi_pct;
  }

  /* End of MinMax: '<S285>/MinMax' */

  /* MinMax: '<S285>/MinMax1' incorporates:
   *  Constant: '<S285>/sat7'
   */
  if (VOPM_VCUCruiseCtrTgtSpd_kph >= KOPM_BrkPedalPosLo_pct)
  {
    /* MinMax: '<S285>/MinMax1' */
    VOPM_BrkPedalPos_pct = VOPM_VCUCruiseCtrTgtSpd_kph;
  }
  else
  {
    /* MinMax: '<S285>/MinMax1' */
    VOPM_BrkPedalPos_pct = KOPM_BrkPedalPosLo_pct;
  }

  /* End of MinMax: '<S285>/MinMax1' */
  /* End of Outputs for SubSystem: '<S278>/Subsys_VOPM_BrkPedalPos_pct1' */

  /* Outputs for Atomic SubSystem: '<S278>/Subsys_VOPM_OTAModeSts_flg1' */
  /* Switch: '<S289>/Switch4' incorporates:
   *  Constant: '<S289>/sat3'
   */
  if (KOPM_OTAModeSts_flg_ovrdflg)
  {
    /* Switch: '<S289>/Switch4' incorporates:
     *  Constant: '<S289>/sat4'
     */
    VOPM_OTAModeSts_flg = KOPM_OTAModeSts_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S289>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S289>/Data Type Conversion1'
     */
    VOPM_OTAModeSts_flg = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmCHA_outputs())
                              ->VHVM_OTAModeSts_flg;
  }

  /* End of Switch: '<S289>/Switch4' */
  /* End of Outputs for SubSystem: '<S278>/Subsys_VOPM_OTAModeSts_flg1' */

  /* Outputs for Atomic SubSystem: '<S278>/Subsys_VOPM_DrvReqTorqOvrdESC_flg1' */
  /* Switch: '<S287>/Switch4' incorporates:
   *  Constant: '<S287>/sat3'
   */
  if (KOPM_DrvReqTorqOvrdESC_flg_ovrdflg)
  {
    /* Switch: '<S287>/Switch4' incorporates:
     *  Constant: '<S287>/sat4'
     */
    VOPM_DrvReqTorqOvrdESC_flg = KOPM_DrvReqTorqOvrdESC_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S287>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S287>/Data Type Conversion1'
     */
    VOPM_DrvReqTorqOvrdESC_flg =
        (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmCHA_outputs())->VVTM_ACCOvrd_flg;
  }

  /* End of Switch: '<S287>/Switch4' */
  /* End of Outputs for SubSystem: '<S278>/Subsys_VOPM_DrvReqTorqOvrdESC_flg1' */

  /* Outputs for Atomic SubSystem: '<S278>/Subsys_VOPM_BrkPedSnsrPosVRsrvd_enum1' */
  /* Switch: '<S284>/Switch4' incorporates:
   *  Constant: '<S284>/sat3'
   */
  if (KOPM_BrkPedSnsrPosVRsrvd_enum_ovrdflg)
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  Constant: '<S284>/sat4'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = KOPM_BrkPedSnsrPosVRsrvd_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S284>/Data Type Conversion1'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = (uint8)(Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmCHA_outputs())
                               ->VIPC_BrkPedPstnVld_flg;
  }

  /* End of Switch: '<S284>/Switch4' */

  /* MinMax: '<S284>/MinMax' incorporates:
   *  Constant: '<S284>/sat6'
   */
  if (VOPM_VCUACCStat_enum > KOPM_BrkPedSnsrPosVRsrvdHi_enum)
  {
    /* MinMax: '<S236>/MinMax' */
    VOPM_VCUACCStat_enum = KOPM_BrkPedSnsrPosVRsrvdHi_enum;
  }

  /* End of MinMax: '<S284>/MinMax' */

  /* MinMax: '<S284>/MinMax1' incorporates:
   *  Constant: '<S284>/sat7'
   */
  if (VOPM_VCUACCStat_enum >= KOPM_BrkPedSnsrPosVRsrvdLo_enum)
  {
    /* MinMax: '<S284>/MinMax1' */
    VOPM_BrkPedSnsrPosVRsrvd_enum = VOPM_VCUACCStat_enum;
  }
  else
  {
    /* MinMax: '<S284>/MinMax1' */
    VOPM_BrkPedSnsrPosVRsrvd_enum = KOPM_BrkPedSnsrPosVRsrvdLo_enum;
  }

  /* End of MinMax: '<S284>/MinMax1' */
  /* End of Outputs for SubSystem: '<S278>/Subsys_VOPM_BrkPedSnsrPosVRsrvd_enum1' */

  /* Outputs for Atomic SubSystem: '<S278>/Subsys_VOPM_ACCTrqCtrlAvl_flg1' */
  /* Switch: '<S279>/Switch4' incorporates:
   *  Constant: '<S279>/sat3'
   */
  if (KOPM_ACCTrqCtrlAvl_flg_ovrdflg)
  {
    /* Switch: '<S279>/Switch4' incorporates:
     *  Constant: '<S279>/sat4'
     */
    VOPM_ACCTrqCtrlAvl_flg = KOPM_ACCTrqCtrlAvl_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S279>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S279>/Data Type Conversion1'
     */
    VOPM_ACCTrqCtrlAvl_flg =
        (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmCHA_outputs())->VVTM_ACCAvail_flg;
  }

  /* End of Switch: '<S279>/Switch4' */
  /* End of Outputs for SubSystem: '<S278>/Subsys_VOPM_ACCTrqCtrlAvl_flg1' */

  /* Outputs for Atomic SubSystem: '<S278>/Subsys_VOPM_AccPedPosSnsrSta_enum1' */
  /* Switch: '<S280>/Switch4' incorporates:
   *  Constant: '<S280>/sat3'
   */
  if (KOPM_AccPedPosSnsrSta_enum_ovrdflg)
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  Constant: '<S280>/sat4'
     *  DataTypeConversion: '<S280>/Data Type Conversion3'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = KOPM_AccPedPosSnsrSta_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S280>/Data Type Conversion1'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmCHA_outputs())
                               ->VIPC_AccPedSnsrSta_enum;
  }

  /* End of Switch: '<S280>/Switch4' */

  /* MinMax: '<S280>/MinMax' incorporates:
   *  Constant: '<S280>/sat6'
   */
  if (VOPM_VCUACCStat_enum > KOPM_AccPedPosSnsrStaHi_enum)
  {
    /* MinMax: '<S236>/MinMax' */
    VOPM_VCUACCStat_enum = KOPM_AccPedPosSnsrStaHi_enum;
  }

  /* End of MinMax: '<S280>/MinMax' */

  /* MinMax: '<S280>/MinMax1' incorporates:
   *  Constant: '<S280>/sat7'
   */
  if (VOPM_VCUACCStat_enum >= KOPM_AccPedPosSnsrStaLo_enum)
  {
    /* DataTypeConversion: '<S280>/Data Type Conversion2' */
    VOPM_AccPedPosSnsrSta_enum = VOPM_VCUACCStat_enum;
  }
  else
  {
    /* DataTypeConversion: '<S280>/Data Type Conversion2' */
    VOPM_AccPedPosSnsrSta_enum = KOPM_AccPedPosSnsrStaLo_enum;
  }

  /* End of MinMax: '<S280>/MinMax1' */
  /* End of Outputs for SubSystem: '<S278>/Subsys_VOPM_AccPedPosSnsrSta_enum1' */

  /* Outputs for Atomic SubSystem: '<S278>/Subsys_VOPM_PGrSwcSt_enum' */
  /* Switch: '<S290>/Switch4' incorporates:
   *  Constant: '<S290>/sat3'
   */
  if (KOPM_PGrSwcSt_enum_ovrdflg)
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  Constant: '<S290>/sat4'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = KOPM_PGrSwcSt_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S290>/Data Type Conversion1'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmCHA_outputs())
                               ->VGSM_PGrSwSts_enum;
  }

  /* End of Switch: '<S290>/Switch4' */

  /* MinMax: '<S290>/MinMax' incorporates:
   *  Constant: '<S290>/sat6'
   */
  if (VOPM_VCUACCStat_enum > KOPM_PGrSwcStHi_enum)
  {
    /* MinMax: '<S236>/MinMax' */
    VOPM_VCUACCStat_enum = KOPM_PGrSwcStHi_enum;
  }

  /* End of MinMax: '<S290>/MinMax' */

  /* MinMax: '<S290>/MinMax1' incorporates:
   *  Constant: '<S290>/sat7'
   */
  if (VOPM_VCUACCStat_enum >= KOPM_PGrSwcStLo_enum)
  {
    /* MinMax: '<S290>/MinMax1' */
    VOPM_PGrSwcSt_enum = VOPM_VCUACCStat_enum;
  }
  else
  {
    /* MinMax: '<S290>/MinMax1' */
    VOPM_PGrSwcSt_enum = KOPM_PGrSwcStLo_enum;
  }

  /* End of MinMax: '<S290>/MinMax1' */
  /* End of Outputs for SubSystem: '<S278>/Subsys_VOPM_PGrSwcSt_enum' */

  /* Outputs for Atomic SubSystem: '<S278>/Subsys_VOPM_DrvReqTorqOverrideFCM_flg1' */
  /* Switch: '<S286>/Switch4' incorporates:
   *  Constant: '<S286>/sat3'
   */
  if (KOPM_DrvReqTorqOverrideFCM_flg_ovrdflg)
  {
    /* Switch: '<S286>/Switch4' incorporates:
     *  Constant: '<S286>/sat4'
     */
    VOPM_DrvReqTorqOverrideFCM_flg = KOPM_DrvReqTorqOverrideFCM_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S286>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S286>/Data Type Conversion1'
     */
    VOPM_DrvReqTorqOverrideFCM_flg =
        (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmCHA_outputs())->VVTM_ACCOvrd_flg;
  }

  /* End of Switch: '<S286>/Switch4' */
  /* End of Outputs for SubSystem: '<S278>/Subsys_VOPM_DrvReqTorqOverrideFCM_flg1' */

  /* Outputs for Atomic SubSystem: '<S278>/Subsys_VOPM_AccPedPosToESC_pct1' */
  /* Switch: '<S282>/Switch4' incorporates:
   *  Constant: '<S282>/sat3'
   */
  if (KOPM_AccPedPosToESC_pct_ovrdflg)
  {
    /* MinMax: '<S318>/MinMax' incorporates:
     *  Constant: '<S282>/sat4'
     *  Product: '<S313>/Product1'
     */
    VOPM_VCUCruiseCtrTgtSpd_kph = KOPM_AccPedPosToESC_pct_ovrdval;
  }
  else
  {
    /* MinMax: '<S318>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S282>/Data Type Conversion1'
     *  Product: '<S313>/Product1'
     */
    VOPM_VCUCruiseCtrTgtSpd_kph =
        (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmCHA_outputs())
            ->VVTM_VirtAccPedPstn_pct;
  }

  /* End of Switch: '<S282>/Switch4' */

  /* MinMax: '<S282>/MinMax' incorporates:
   *  Constant: '<S282>/sat6'
   */
  if (VOPM_VCUCruiseCtrTgtSpd_kph > KOPM_AccPedPosToESCHi_pct)
  {
    /* MinMax: '<S318>/MinMax' */
    VOPM_VCUCruiseCtrTgtSpd_kph = KOPM_AccPedPosToESCHi_pct;
  }

  /* End of MinMax: '<S282>/MinMax' */

  /* MinMax: '<S282>/MinMax1' incorporates:
   *  Constant: '<S282>/sat7'
   */
  if (VOPM_VCUCruiseCtrTgtSpd_kph >= KOPM_AccPedPosToESCLo_pct)
  {
    /* MinMax: '<S282>/MinMax1' */
    VOPM_AccPedPosToESC_pct = VOPM_VCUCruiseCtrTgtSpd_kph;
  }
  else
  {
    /* MinMax: '<S282>/MinMax1' */
    VOPM_AccPedPosToESC_pct = KOPM_AccPedPosToESCLo_pct;
  }

  /* End of MinMax: '<S282>/MinMax1' */
  /* End of Outputs for SubSystem: '<S278>/Subsys_VOPM_AccPedPosToESC_pct1' */

  /* Outputs for Atomic SubSystem: '<S278>/Subsys_VOPM_PwrRecupMaxAvlbMotorTorqSta_enum1' */
  /* Switch: '<S291>/Switch4' incorporates:
   *  Constant: '<S291>/sat3'
   */
  if (KOPM_PwrRecupMaxAvlbMotorTorqSta_enum_ovrdflg)
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  Constant: '<S291>/sat4'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = KOPM_PwrRecupMaxAvlbMotorTorqSta_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S291>/Data Type Conversion1'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmCHA_outputs())
                               ->VVTM_BrkPwrRecMaxWhlTorqSta_enum;
  }

  /* End of Switch: '<S291>/Switch4' */

  /* MinMax: '<S291>/MinMax' incorporates:
   *  Constant: '<S291>/sat6'
   */
  if (VOPM_VCUACCStat_enum > KOPM_PwrRecupMaxAvlbMotorTorqStaHi_enum)
  {
    /* MinMax: '<S236>/MinMax' */
    VOPM_VCUACCStat_enum = KOPM_PwrRecupMaxAvlbMotorTorqStaHi_enum;
  }

  /* End of MinMax: '<S291>/MinMax' */

  /* MinMax: '<S291>/MinMax1' incorporates:
   *  Constant: '<S291>/sat7'
   */
  if (VOPM_VCUACCStat_enum >= KOPM_PwrRecupMaxAvlbMotorTorqStaLo_enum)
  {
    /* MinMax: '<S291>/MinMax1' */
    VOPM_PwrRecupMaxAvlbMotorTorqSta_enum = VOPM_VCUACCStat_enum;
  }
  else
  {
    /* MinMax: '<S291>/MinMax1' */
    VOPM_PwrRecupMaxAvlbMotorTorqSta_enum =
        KOPM_PwrRecupMaxAvlbMotorTorqStaLo_enum;
  }

  /* End of MinMax: '<S291>/MinMax1' */
  /* End of Outputs for SubSystem: '<S278>/Subsys_VOPM_PwrRecupMaxAvlbMotorTorqSta_enum1' */

  /* Outputs for Atomic SubSystem: '<S278>/Subsys_VOPM_VCUReqEPB_enum1' */
  /* Switch: '<S306>/Switch4' incorporates:
   *  Constant: '<S306>/sat3'
   */
  if (KOPM_VCUReqEPB_enum_ovrdflg)
  {
    /* DataTypeConversion: '<S278>/DataTypeConversion51' incorporates:
     *  Constant: '<S306>/sat4'
     *  DataTypeConversion: '<S306>/Data Type Conversion3'
     */
    rtb_VCU_CruiseCtrlSta = KOPM_VCUReqEPB_enum_ovrdval;
  }
  else
  {
    /* DataTypeConversion: '<S278>/DataTypeConversion51' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S306>/Data Type Conversion1'
     */
    rtb_VCU_CruiseCtrlSta = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmCHA_outputs())->VGSM_ReqEPB_enum;
  }

  /* End of Switch: '<S306>/Switch4' */

  /* MinMax: '<S306>/MinMax' incorporates:
   *  Constant: '<S306>/sat6'
   */
  if (rtb_VCU_CruiseCtrlSta > KOPM_VCUReqEPBHi_enum)
  {
    rtb_VCU_CruiseCtrlSta = KOPM_VCUReqEPBHi_enum;
  }

  /* End of MinMax: '<S306>/MinMax' */

  /* MinMax: '<S306>/MinMax1' incorporates:
   *  Constant: '<S306>/sat7'
   */
  if (rtb_VCU_CruiseCtrlSta >= KOPM_VCUReqEPBLo_enum)
  {
    /* DataTypeConversion: '<S306>/Data Type Conversion2' */
    VOPM_VCUReqEPB_enum = rtb_VCU_CruiseCtrlSta;
  }
  else
  {
    /* DataTypeConversion: '<S306>/Data Type Conversion2' */
    VOPM_VCUReqEPB_enum = KOPM_VCUReqEPBLo_enum;
  }

  /* End of MinMax: '<S306>/MinMax1' */
  /* End of Outputs for SubSystem: '<S278>/Subsys_VOPM_VCUReqEPB_enum1' */

  /* Outputs for Atomic SubSystem: '<S278>/Subsys_VOPM_VCUReqEPBVld_flg1' */
  /* Switch: '<S305>/Switch4' incorporates:
   *  Constant: '<S305>/sat3'
   */
  if (KOPM_VCUReqEPBVld_flg_ovrdflg)
  {
    /* Switch: '<S305>/Switch4' incorporates:
     *  Constant: '<S305>/sat4'
     */
    VOPM_VCUReqEPBVld_flg = KOPM_VCUReqEPBVld_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S305>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S305>/Data Type Conversion1'
     */
    VOPM_VCUReqEPBVld_flg = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmCHA_outputs())->VGSM_ReqEPBV_flg;
  }

  /* End of Switch: '<S305>/Switch4' */
  /* End of Outputs for SubSystem: '<S278>/Subsys_VOPM_VCUReqEPBVld_flg1' */

  /* Outputs for Atomic SubSystem: '<S278>/Subsys_VOPM_AccPedPosToESCSta_enum1' */
  /* Switch: '<S281>/Switch4' incorporates:
   *  Constant: '<S281>/sat3'
   */
  if (KOPM_AccPedPosToESCSta_enum_ovrdflg)
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  Constant: '<S281>/sat4'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = KOPM_AccPedPosToESCSta_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S281>/Data Type Conversion1'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmCHA_outputs())
                               ->VVTM_VirtAccPedPstnSta_enum;
  }

  /* End of Switch: '<S281>/Switch4' */

  /* MinMax: '<S281>/MinMax' incorporates:
   *  Constant: '<S281>/sat6'
   */
  if (VOPM_VCUACCStat_enum > KOPM_AccPedPosToESCStaHi_enum)
  {
    /* MinMax: '<S236>/MinMax' */
    VOPM_VCUACCStat_enum = KOPM_AccPedPosToESCStaHi_enum;
  }

  /* End of MinMax: '<S281>/MinMax' */

  /* MinMax: '<S281>/MinMax1' incorporates:
   *  Constant: '<S281>/sat7'
   */
  if (VOPM_VCUACCStat_enum >= KOPM_AccPedPosToESCStaLo_enum)
  {
    /* MinMax: '<S281>/MinMax1' */
    VOPM_AccPedPosToESCSta_enum = VOPM_VCUACCStat_enum;
  }
  else
  {
    /* MinMax: '<S281>/MinMax1' */
    VOPM_AccPedPosToESCSta_enum = KOPM_AccPedPosToESCStaLo_enum;
  }

  /* End of MinMax: '<S281>/MinMax1' */
  /* End of Outputs for SubSystem: '<S278>/Subsys_VOPM_AccPedPosToESCSta_enum1' */

  /* Outputs for Atomic SubSystem: '<S278>/Subsys_VOPM_VCUParkSwStaVld_flg1' */
  /* Switch: '<S301>/Switch4' incorporates:
   *  Constant: '<S301>/sat3'
   */
  if (KOPM_VCUParkSwStaVld_flg_ovrdflg)
  {
    /* Switch: '<S301>/Switch4' incorporates:
     *  Constant: '<S301>/sat4'
     */
    VOPM_VCUParkSwStaVld_flg = KOPM_VCUParkSwStaVld_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S301>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S301>/Data Type Conversion1'
     */
    VOPM_VCUParkSwStaVld_flg =
        (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmCHA_outputs())
            ->VVcuTx_ParkSwStaVld_flg;
  }

  /* End of Switch: '<S301>/Switch4' */
  /* End of Outputs for SubSystem: '<S278>/Subsys_VOPM_VCUParkSwStaVld_flg1' */

  /* Outputs for Atomic SubSystem: '<S278>/Subsys_VOPM_VCUParkSwSta_flg1' */
  /* Switch: '<S302>/Switch4' incorporates:
   *  Constant: '<S302>/sat3'
   */
  if (KOPM_VCUParkSwSta_flg_ovrdflg)
  {
    /* Switch: '<S302>/Switch4' incorporates:
     *  Constant: '<S302>/sat4'
     */
    VOPM_VCUParkSwSta_flg = KOPM_VCUParkSwSta_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S302>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S302>/Data Type Conversion1'
     */
    VOPM_VCUParkSwSta_flg = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmCHA_outputs())->VVcuTx_ParkSwSta_flg;
  }

  /* End of Switch: '<S302>/Switch4' */
  /* End of Outputs for SubSystem: '<S278>/Subsys_VOPM_VCUParkSwSta_flg1' */

  /* Outputs for Atomic SubSystem: '<S278>/Subsys_VOPM_StrgRecupReqBrkLampOn_flg1' */
  /* Switch: '<S292>/Switch4' incorporates:
   *  Constant: '<S292>/sat3'
   */
  if (KOPM_StrgRecupReqBrkLampOn_flg_ovrdflg)
  {
    /* Switch: '<S292>/Switch4' incorporates:
     *  Constant: '<S292>/sat4'
     */
    VOPM_StrgRecupReqBrkLampOn_flg = KOPM_StrgRecupReqBrkLampOn_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S292>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S292>/Data Type Conversion1'
     */
    VOPM_StrgRecupReqBrkLampOn_flg =
        (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmCHA_outputs())
            ->VVTM_RegenReqBrkLampOn_flg;
  }

  /* End of Switch: '<S292>/Switch4' */
  /* End of Outputs for SubSystem: '<S278>/Subsys_VOPM_StrgRecupReqBrkLampOn_flg1' */

  /* Outputs for Atomic SubSystem: '<S278>/Subsys_VOPM_GearShiftInhibited_flg1' */
  /* Switch: '<S288>/Switch4' incorporates:
   *  Constant: '<S288>/sat3'
   */
  if (KOPM_GearShiftInhibited_flg_ovrdflg)
  {
    /* Switch: '<S288>/Switch4' incorporates:
     *  Constant: '<S288>/sat4'
     */
    VOPM_GearShiftInhibited_flg = KOPM_GearShiftInhibited_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S288>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S288>/Data Type Conversion1'
     */
    VOPM_GearShiftInhibited_flg =
        (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmCHA_outputs())
            ->VGSM_GrShftInhbed_flg;
  }

  /* End of Switch: '<S288>/Switch4' */
  /* End of Outputs for SubSystem: '<S278>/Subsys_VOPM_GearShiftInhibited_flg1' */

  /* Outputs for Atomic SubSystem: '<S278>/Subsys_VOPM_VCUEPBApplyForbid_enum1' */
  /* Switch: '<S300>/Switch4' incorporates:
   *  Constant: '<S300>/sat3'
   */
  if (KOPM_VCUEPBApplyForbid_enum_ovrdflg)
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  Constant: '<S300>/sat4'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = KOPM_VCUEPBApplyForbid_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S300>/Data Type Conversion1'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmCHA_outputs())
                               ->VGSM_EPBApplyFbd_enum;
  }

  /* End of Switch: '<S300>/Switch4' */

  /* MinMax: '<S300>/MinMax' incorporates:
   *  Constant: '<S300>/sat6'
   */
  if (VOPM_VCUACCStat_enum > KOPM_VCUEPBApplyForbidHi_enum)
  {
    /* MinMax: '<S236>/MinMax' */
    VOPM_VCUACCStat_enum = KOPM_VCUEPBApplyForbidHi_enum;
  }

  /* End of MinMax: '<S300>/MinMax' */

  /* MinMax: '<S300>/MinMax1' incorporates:
   *  Constant: '<S300>/sat7'
   */
  if (VOPM_VCUACCStat_enum >= KOPM_VCUEPBApplyForbidLo_enum)
  {
    /* MinMax: '<S300>/MinMax1' */
    VOPM_VCUEPBApplyForbid_enum = VOPM_VCUACCStat_enum;
  }
  else
  {
    /* MinMax: '<S300>/MinMax1' */
    VOPM_VCUEPBApplyForbid_enum = KOPM_VCUEPBApplyForbidLo_enum;
  }

  /* End of MinMax: '<S300>/MinMax1' */
  /* End of Outputs for SubSystem: '<S278>/Subsys_VOPM_VCUEPBApplyForbid_enum1' */

  /* Outputs for Atomic SubSystem: '<S278>/Subsys_VOPM_VCUAccTgtAx_mps1' */
  /* Switch: '<S296>/Switch4' incorporates:
   *  Constant: '<S278>/Constant4'
   *  Constant: '<S296>/sat3'
   *  Constant: '<S296>/sat4'
   */
  if (KOPM_VCUAccTgtAx_mps2_ovrdflg)
  {
    VOPM_VCUAccTgtAx_mps2 = KOPM_VCUAccTgtAx_mps2_ovrdval;
  }
  else
  {
    VOPM_VCUAccTgtAx_mps2 = 0.0F;
  }

  /* MinMax: '<S296>/MinMax' incorporates:
   *  Constant: '<S296>/sat6'
   *  Switch: '<S296>/Switch4'
   */
  if (VOPM_VCUAccTgtAx_mps2 > KOPM_VCUAccTgtAxHi_mps2)
  {
    VOPM_VCUAccTgtAx_mps2 = KOPM_VCUAccTgtAxHi_mps2;
  }

  /* End of MinMax: '<S296>/MinMax' */

  /* MinMax: '<S296>/MinMax1' incorporates:
   *  Constant: '<S296>/sat7'
   */
  if (VOPM_VCUAccTgtAx_mps2 < KOPM_VCUAccTgtAxLo_mps2)
  {
    /* Switch: '<S296>/Switch4' incorporates:
     *  MinMax: '<S296>/MinMax1'
     */
    VOPM_VCUAccTgtAx_mps2 = KOPM_VCUAccTgtAxLo_mps2;
  }

  /* End of MinMax: '<S296>/MinMax1' */
  /* End of Outputs for SubSystem: '<S278>/Subsys_VOPM_VCUAccTgtAx_mps1' */

  /* Outputs for Atomic SubSystem: '<S278>/Subsys_VOPM_VCUAccTgtAxReq_flg1' */
  /* Switch: '<S295>/Switch4' incorporates:
   *  Constant: '<S295>/sat3'
   *  Constant: '<S295>/sat4'
   */
  VOPM_VCUAccTgtAxReq_flg = (KOPM_VCUAccTgtAxReq_flg_ovrdflg &&
                             KOPM_VCUAccTgtAxReq_flg_ovrdval);

  /* End of Outputs for SubSystem: '<S278>/Subsys_VOPM_VCUAccTgtAxReq_flg1' */

  /* Outputs for Atomic SubSystem: '<S278>/Subsys_VOPM_VCUBraTorReq_Nm1' */
  /* Switch: '<S297>/Switch4' incorporates:
   *  Constant: '<S278>/Constant5'
   *  Constant: '<S297>/sat3'
   *  Constant: '<S297>/sat4'
   */
  if (KOPM_VCUBraTorReq_Nm_ovrdflg)
  {
    VOPM_VCUBraTorReq_Nm = KOPM_VCUBraTorReq_Nm_ovrdval;
  }
  else
  {
    VOPM_VCUBraTorReq_Nm = 0.0F;
  }

  /* MinMax: '<S297>/MinMax' incorporates:
   *  Constant: '<S297>/sat6'
   *  Switch: '<S297>/Switch4'
   */
  if (VOPM_VCUBraTorReq_Nm > KOPM_VCUBraTorReqHi_Nm)
  {
    VOPM_VCUBraTorReq_Nm = KOPM_VCUBraTorReqHi_Nm;
  }

  /* End of MinMax: '<S297>/MinMax' */

  /* MinMax: '<S297>/MinMax1' incorporates:
   *  Constant: '<S297>/sat7'
   */
  if (VOPM_VCUBraTorReq_Nm < KOPM_VCUBraTorReqLo_Nm)
  {
    /* Switch: '<S297>/Switch4' incorporates:
     *  MinMax: '<S297>/MinMax1'
     */
    VOPM_VCUBraTorReq_Nm = KOPM_VCUBraTorReqLo_Nm;
  }

  /* End of MinMax: '<S297>/MinMax1' */
  /* End of Outputs for SubSystem: '<S278>/Subsys_VOPM_VCUBraTorReq_Nm1' */

  /* Outputs for Atomic SubSystem: '<S278>/Subsys_VOPM_VCUACCStandstillReq_flg1' */
  /* Switch: '<S293>/Switch4' incorporates:
   *  Constant: '<S293>/sat3'
   *  Constant: '<S293>/sat4'
   */
  VOPM_VCUACCStandstillReq_flg = (KOPM_VCUACCStandstillReq_flg_ovrdflg &&
                                  KOPM_VCUACCStandstillReq_flg_ovrdval);

  /* End of Outputs for SubSystem: '<S278>/Subsys_VOPM_VCUACCStandstillReq_flg1' */

  /* Outputs for Atomic SubSystem: '<S278>/Subsys_VOPM_VCUPreKeReq_flg1' */
  /* Switch: '<S303>/Switch4' incorporates:
   *  Constant: '<S303>/sat3'
   *  Constant: '<S303>/sat4'
   */
  VOPM_VCUPreKeReq_flg = (KOPM_VCUPreKeReq_flg_ovrdflg &&
                          KOPM_VCUPreKeReq_flg_ovrdval);

  /* End of Outputs for SubSystem: '<S278>/Subsys_VOPM_VCUPreKeReq_flg1' */

  /* Outputs for Atomic SubSystem: '<S278>/Subsys_VOPM_VCUCruiseCtrlSta_enum1' */
  /* Switch: '<S299>/Switch4' incorporates:
   *  Constant: '<S299>/sat3'
   */
  if (KOPM_VCUCruiseCtrlSta_enum_ovrdflg)
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  Constant: '<S299>/sat4'
     *  DataTypeConversion: '<S299>/Data Type Conversion3'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = KOPM_VCUCruiseCtrlSta_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S299>/Data Type Conversion1'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmCHA_outputs())
                               ->VVTM_CruzCtrlStat_enum;
  }

  /* End of Switch: '<S299>/Switch4' */

  /* MinMax: '<S299>/MinMax' incorporates:
   *  Constant: '<S299>/sat6'
   */
  if (VOPM_VCUACCStat_enum > KOPM_VCUCruiseCtrlStaHi_enum)
  {
    /* MinMax: '<S236>/MinMax' */
    VOPM_VCUACCStat_enum = KOPM_VCUCruiseCtrlStaHi_enum;
  }

  /* End of MinMax: '<S299>/MinMax' */

  /* MinMax: '<S299>/MinMax1' incorporates:
   *  Constant: '<S299>/sat7'
   */
  if (VOPM_VCUACCStat_enum >= KOPM_VCUCruiseCtrlStaLo_enum)
  {
    /* DataTypeConversion: '<S299>/Data Type Conversion2' */
    VOPM_VCUCruiseCtrlSta_enum = VOPM_VCUACCStat_enum;
  }
  else
  {
    /* DataTypeConversion: '<S299>/Data Type Conversion2' */
    VOPM_VCUCruiseCtrlSta_enum = KOPM_VCUCruiseCtrlStaLo_enum;
  }

  /* End of MinMax: '<S299>/MinMax1' */
  /* End of Outputs for SubSystem: '<S278>/Subsys_VOPM_VCUCruiseCtrlSta_enum1' */

  /* Outputs for Atomic SubSystem: '<S278>/Subsys_VOPM_VCUCruiseCtrTgtSpd_kph1' */
  /* Switch: '<S298>/Switch4' incorporates:
   *  Constant: '<S298>/sat3'
   */
  if (KOPM_VCUCruiseCtrTgtSpd_kph_ovrdflg)
  {
    /* MinMax: '<S318>/MinMax' incorporates:
     *  Constant: '<S298>/sat4'
     *  Product: '<S313>/Product1'
     */
    VOPM_VCUCruiseCtrTgtSpd_kph = KOPM_VCUCruiseCtrTgtSpd_kph_ovrdval;
  }
  else
  {
    /* MinMax: '<S318>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S298>/Data Type Conversion1'
     *  Product: '<S313>/Product1'
     */
    VOPM_VCUCruiseCtrTgtSpd_kph =
        (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmCHA_outputs())->VVTM_CCTgtSpd_kph;
  }

  /* End of Switch: '<S298>/Switch4' */

  /* MinMax: '<S298>/MinMax' incorporates:
   *  Constant: '<S298>/sat6'
   */
  if (VOPM_VCUCruiseCtrTgtSpd_kph > KOPM_VCUCruiseCtrTgtSpdHi_kph)
  {
    /* MinMax: '<S318>/MinMax' */
    VOPM_VCUCruiseCtrTgtSpd_kph = KOPM_VCUCruiseCtrTgtSpdHi_kph;
  }

  /* End of MinMax: '<S298>/MinMax' */

  /* MinMax: '<S298>/MinMax1' incorporates:
   *  Constant: '<S298>/sat7'
   */
  if (VOPM_VCUCruiseCtrTgtSpd_kph < KOPM_VCUCruiseCtrTgtSpdLo_kph)
  {
    /* MinMax: '<S318>/MinMax' incorporates:
     *  MinMax: '<S298>/MinMax1'
     */
    VOPM_VCUCruiseCtrTgtSpd_kph = KOPM_VCUCruiseCtrTgtSpdLo_kph;
  }

  /* End of MinMax: '<S298>/MinMax1' */
  /* End of Outputs for SubSystem: '<S278>/Subsys_VOPM_VCUCruiseCtrTgtSpd_kph1' */

  /* Outputs for Atomic SubSystem: '<S278>/Subsys_VOPM_VCUReqAutoBrk_enum1' */
  /* Switch: '<S304>/Switch4' incorporates:
   *  Constant: '<S304>/sat3'
   */
  if (KOPM_VCUReqAutoBrk_enum_ovrdflg)
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  Constant: '<S304>/sat4'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = KOPM_VCUReqAutoBrk_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S304>/Data Type Conversion1'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmCHA_outputs())
                               ->VVTM_AutoBrkReq_enum;
  }

  /* End of Switch: '<S304>/Switch4' */

  /* MinMax: '<S304>/MinMax' incorporates:
   *  Constant: '<S304>/sat6'
   */
  if (VOPM_VCUACCStat_enum > KOPM_VCUReqAutoBrkHi_enum)
  {
    /* MinMax: '<S236>/MinMax' */
    VOPM_VCUACCStat_enum = KOPM_VCUReqAutoBrkHi_enum;
  }

  /* End of MinMax: '<S304>/MinMax' */

  /* MinMax: '<S304>/MinMax1' incorporates:
   *  Constant: '<S304>/sat7'
   */
  if (VOPM_VCUACCStat_enum >= KOPM_VCUReqAutoBrkLo_enum)
  {
    /* MinMax: '<S304>/MinMax1' */
    VOPM_VCUReqAutoBrk_enum = VOPM_VCUACCStat_enum;
  }
  else
  {
    /* MinMax: '<S304>/MinMax1' */
    VOPM_VCUReqAutoBrk_enum = KOPM_VCUReqAutoBrkLo_enum;
  }

  /* End of MinMax: '<S304>/MinMax1' */
  /* End of Outputs for SubSystem: '<S278>/Subsys_VOPM_VCUReqAutoBrk_enum1' */

  /* Outputs for Atomic SubSystem: '<S278>/Subsys_VOPM_VCUACCStat_enum' */
  /* Switch: '<S294>/Switch4' incorporates:
   *  Constant: '<S294>/sat3'
   */
  if (KOPM_VCUACCStat_enum_ovrdflg)
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  Constant: '<S294>/sat4'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = KOPM_VCUACCStat_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S294>/Data Type Conversion1'
     *  MinMax: '<S294>/MinMax'
     */
    VOPM_VCUACCStat_enum = (Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmCHA_outputs())
                               ->VVTM_ACCStat_enum;
  }

  /* End of Switch: '<S294>/Switch4' */

  /* MinMax: '<S294>/MinMax' incorporates:
   *  Constant: '<S294>/sat6'
   */
  if (VOPM_VCUACCStat_enum > KOPM_VCUACCStatHi_enum)
  {
    /* MinMax: '<S236>/MinMax' */
    VOPM_VCUACCStat_enum = KOPM_VCUACCStatHi_enum;
  }

  /* End of MinMax: '<S294>/MinMax' */

  /* MinMax: '<S294>/MinMax1' incorporates:
   *  Constant: '<S294>/sat7'
   */
  if (VOPM_VCUACCStat_enum < KOPM_VCUACCStatLo_enum)
  {
    /* MinMax: '<S236>/MinMax' incorporates:
     *  MinMax: '<S294>/MinMax1'
     */
    VOPM_VCUACCStat_enum = KOPM_VCUACCStatLo_enum;
  }

  /* End of MinMax: '<S294>/MinMax1' */
  /* End of Outputs for SubSystem: '<S278>/Subsys_VOPM_VCUACCStat_enum' */

  /* DataTypeConversion: '<S278>/DataTypeConversion31' incorporates:
   *  Constant: '<S309>/Constant1'
   *  Product: '<S309>/Product1'
   *  Sum: '<S309>/Add'
   */
  tmp = VOPM_AcclPedalPos_pct * 2.5F;
  if (tmp < 256.0F)
  {
    if (tmp >= 0.0F)
    {
      /* BusCreator: '<S278>/BusCreator1' */
      AppSwcOpm_ARID_DEF.VCU_D_Status_CHA_a.VCU_AcclPedalPos = (uint8)tmp;
    }
    else
    {
      /* BusCreator: '<S278>/BusCreator1' */
      AppSwcOpm_ARID_DEF.VCU_D_Status_CHA_a.VCU_AcclPedalPos = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S278>/BusCreator1' */
    AppSwcOpm_ARID_DEF.VCU_D_Status_CHA_a.VCU_AcclPedalPos = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S278>/DataTypeConversion31' */

  /* DataTypeConversion: '<S278>/DataTypeConversion32' incorporates:
   *  Constant: '<S307>/Constant1'
   *  Product: '<S307>/Product1'
   *  Sum: '<S307>/Add'
   */
  tmp = VOPM_BrkPedalPos_pct * 2.5F;
  if (tmp < 256.0F)
  {
    if (tmp >= 0.0F)
    {
      /* BusCreator: '<S278>/BusCreator1' */
      AppSwcOpm_ARID_DEF.VCU_D_Status_CHA_a.VCU_BrkPedalPos = (uint8)tmp;
    }
    else
    {
      /* BusCreator: '<S278>/BusCreator1' */
      AppSwcOpm_ARID_DEF.VCU_D_Status_CHA_a.VCU_BrkPedalPos = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S278>/BusCreator1' */
    AppSwcOpm_ARID_DEF.VCU_D_Status_CHA_a.VCU_BrkPedalPos = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S278>/DataTypeConversion32' */

  /* BusCreator: '<S278>/BusCreator1' incorporates:
   *  Constant: '<S278>/Constant'
   *  DataTypeConversion: '<S278>/DataTypeConversion58'
   *  DataTypeConversion: '<S280>/Data Type Conversion2'
   *  Switch: '<S279>/Switch4'
   *  Switch: '<S286>/Switch4'
   *  Switch: '<S287>/Switch4'
   *  Switch: '<S289>/Switch4'
   */
  AppSwcOpm_ARID_DEF.VCU_D_Status_CHA_a.VCU_OTAModeSts = VOPM_OTAModeSts_flg;
  AppSwcOpm_ARID_DEF.VCU_D_Status_CHA_a.VCU_DrvReqTorqOverrideESC =
      VOPM_DrvReqTorqOvrdESC_flg;
  AppSwcOpm_ARID_DEF.VCU_D_Status_CHA_a.VCU_BrkPedalSnsrPosV_Reserved =
      VOPM_BrkPedSnsrPosVRsrvd_enum;
  AppSwcOpm_ARID_DEF.VCU_D_Status_CHA_a.VCU_ACCTrqCtrlAvl =
      VOPM_ACCTrqCtrlAvl_flg;
  AppSwcOpm_ARID_DEF.VCU_D_Status_CHA_a.VCU_StandStilDecelReq = false;
  AppSwcOpm_ARID_DEF.VCU_D_Status_CHA_a.VCU_AcclPedalPosSnsrSta =
      VOPM_AccPedPosSnsrSta_enum;
  AppSwcOpm_ARID_DEF.VCU_D_Status_CHA_a.VCU_PGearSwcSt = VOPM_PGrSwcSt_enum;
  AppSwcOpm_ARID_DEF.VCU_D_Status_CHA_a.VCU_DrvReqTorqOverrideFCM =
      VOPM_DrvReqTorqOverrideFCM_flg;
  AppSwcOpm_ARID_DEF.VCU_D_Status_CHA_a.VCU_StandStilOverride = 0U;
  AppSwcOpm_ARID_DEF.VCU_D_Status_CHA_a.VCU_StandStilTarDecelVal = 320U;

  /* DataTypeConversion: '<S278>/DataTypeConversion34' incorporates:
   *  Constant: '<S310>/Constant1'
   *  Product: '<S310>/Product1'
   *  Sum: '<S310>/Add'
   */
  tmp = VOPM_AccPedPosToESC_pct * 2.5F;
  if (tmp < 256.0F)
  {
    if (tmp >= 0.0F)
    {
      /* BusCreator: '<S278>/BusCreator1' */
      AppSwcOpm_ARID_DEF.VCU_D_Status_CHA_a.VCU_AcclPedalPosToESC = (uint8)tmp;
    }
    else
    {
      /* BusCreator: '<S278>/BusCreator1' */
      AppSwcOpm_ARID_DEF.VCU_D_Status_CHA_a.VCU_AcclPedalPosToESC = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S278>/BusCreator1' */
    AppSwcOpm_ARID_DEF.VCU_D_Status_CHA_a.VCU_AcclPedalPosToESC = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S278>/DataTypeConversion34' */

  /* BusCreator: '<S278>/BusCreator1' incorporates:
   *  Constant: '<S278>/Constant3'
   *  DataTypeConversion: '<S278>/DataTypeConversion36'
   *  DataTypeConversion: '<S306>/Data Type Conversion2'
   *  Switch: '<S288>/Switch4'
   *  Switch: '<S292>/Switch4'
   *  Switch: '<S301>/Switch4'
   *  Switch: '<S302>/Switch4'
   *  Switch: '<S305>/Switch4'
   */
  AppSwcOpm_ARID_DEF.VCU_D_Status_CHA_a.VCU_PwrRecupMaxAvlbMotorTorqSta =
      VOPM_PwrRecupMaxAvlbMotorTorqSta_enum;
  AppSwcOpm_ARID_DEF.VCU_D_Status_CHA_a.VCU_ReqEPB = VOPM_VCUReqEPB_enum;
  AppSwcOpm_ARID_DEF.VCU_D_Status_CHA_a.VCU_ReqEPBV = VOPM_VCUReqEPBVld_flg;
  AppSwcOpm_ARID_DEF.VCU_D_Status_CHA_a.VCU_AcclPedalPosToESCSta =
      VOPM_AccPedPosToESCSta_enum;
  AppSwcOpm_ARID_DEF.VCU_D_Status_CHA_a.VCU_ParkSwStaV =
      VOPM_VCUParkSwStaVld_flg;
  AppSwcOpm_ARID_DEF.VCU_D_Status_CHA_a.VCU_ParkSwSta = VOPM_VCUParkSwSta_flg;
  AppSwcOpm_ARID_DEF.VCU_D_Status_CHA_a.VCU_StrgRecupReqBrkLampOn =
      VOPM_StrgRecupReqBrkLampOn_flg;
  AppSwcOpm_ARID_DEF.VCU_D_Status_CHA_a.VCU_GearShiftInhibited =
      VOPM_GearShiftInhibited_flg;
  AppSwcOpm_ARID_DEF.VCU_D_Status_CHA_a.VCU_EPK_ParkLocktoCHA = 0U;
  AppSwcOpm_ARID_DEF.VCU_D_Status_CHA_a.VCU_EPBApplyForbid =
      VOPM_VCUEPBApplyForbid_enum;

  /* DataTypeConversion: '<S278>/DataTypeConversion46' incorporates:
   *  Constant: '<S311>/Constant'
   *  Constant: '<S311>/Constant1'
   *  Product: '<S311>/Product1'
   *  Sum: '<S311>/Add'
   */
  tmp = (VOPM_VCUAccTgtAx_mps2 - -9.5F) * 20.0F;
  if (tmp < 256.0F)
  {
    if (tmp >= 0.0F)
    {
      /* BusCreator: '<S278>/BusCreator1' */
      AppSwcOpm_ARID_DEF.VCU_D_Status_CHA_a.VCU_AccTgtAx = (uint8)tmp;
    }
    else
    {
      /* BusCreator: '<S278>/BusCreator1' */
      AppSwcOpm_ARID_DEF.VCU_D_Status_CHA_a.VCU_AccTgtAx = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S278>/BusCreator1' */
    AppSwcOpm_ARID_DEF.VCU_D_Status_CHA_a.VCU_AccTgtAx = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S278>/DataTypeConversion46' */

  /* BusCreator: '<S278>/BusCreator1' incorporates:
   *  Switch: '<S295>/Switch4'
   */
  AppSwcOpm_ARID_DEF.VCU_D_Status_CHA_a.VCU_AccTgtAxReq =
      VOPM_VCUAccTgtAxReq_flg;

  /* DataTypeConversion: '<S278>/DataTypeConversion48' incorporates:
   *  Constant: '<S312>/Constant'
   *  Constant: '<S312>/Constant1'
   *  Product: '<S312>/Product1'
   *  Sum: '<S312>/Add'
   */
  tmp = (VOPM_VCUBraTorReq_Nm - -6200.0F) * 2.0F;
  if (tmp < 65536.0F)
  {
    if (tmp >= 0.0F)
    {
      /* BusCreator: '<S278>/BusCreator1' */
      AppSwcOpm_ARID_DEF.VCU_D_Status_CHA_a.VCU_BraTorReq = (uint16)tmp;
    }
    else
    {
      /* BusCreator: '<S278>/BusCreator1' */
      AppSwcOpm_ARID_DEF.VCU_D_Status_CHA_a.VCU_BraTorReq = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S278>/BusCreator1' */
    AppSwcOpm_ARID_DEF.VCU_D_Status_CHA_a.VCU_BraTorReq = MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<S278>/DataTypeConversion48' */

  /* BusCreator: '<S278>/BusCreator1' incorporates:
   *  DataTypeConversion: '<S278>/DataTypeConversion51'
   *  DataTypeConversion: '<S299>/Data Type Conversion2'
   *  Switch: '<S293>/Switch4'
   *  Switch: '<S303>/Switch4'
   */
  AppSwcOpm_ARID_DEF.VCU_D_Status_CHA_a.VCU_ACCStandstillReq =
      VOPM_VCUACCStandstillReq_flg;
  AppSwcOpm_ARID_DEF.VCU_D_Status_CHA_a.VCU_PreKeReq = VOPM_VCUPreKeReq_flg;
  AppSwcOpm_ARID_DEF.VCU_D_Status_CHA_a.VCU_CruiseCtrlSta =
      VOPM_VCUCruiseCtrlSta_enum;

  /* DataTypeConversion: '<S278>/DataTypeConversion52' incorporates:
   *  Constant: '<S313>/Constant1'
   *  Product: '<S313>/Product1'
   *  Sum: '<S313>/Add'
   */
  tmp = VOPM_VCUCruiseCtrTgtSpd_kph * 17.7777786F;
  if (tmp < 65536.0F)
  {
    if (tmp >= 0.0F)
    {
      /* BusCreator: '<S278>/BusCreator1' */
      AppSwcOpm_ARID_DEF.VCU_D_Status_CHA_a.VCU_CruiseCtrTgtSpd = (uint16)tmp;
    }
    else
    {
      /* BusCreator: '<S278>/BusCreator1' */
      AppSwcOpm_ARID_DEF.VCU_D_Status_CHA_a.VCU_CruiseCtrTgtSpd = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S278>/BusCreator1' */
    AppSwcOpm_ARID_DEF.VCU_D_Status_CHA_a.VCU_CruiseCtrTgtSpd = MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<S278>/DataTypeConversion52' */

  /* BusCreator: '<S278>/BusCreator1' */
  AppSwcOpm_ARID_DEF.VCU_D_Status_CHA_a.VCU_ReqAutoBrk = VOPM_VCUReqAutoBrk_enum;
  AppSwcOpm_ARID_DEF.VCU_D_Status_CHA_a.VCU_ACCStatus = VOPM_VCUACCStat_enum;
}

/* Output and update for function-call system: '<Root>/Opm50ms' */
static void Runbl_Opm50ms(void)
{
  float32 tmp;
  boolean rtb_MinMax_b;

  /* Outputs for Atomic SubSystem: '<S348>/Subsys_VOPM_PTActlOprtMode_enum' */
  /* Switch: '<S363>/Switch4' incorporates:
   *  Constant: '<S363>/sat3'
   */
  if (KOPM_PTActlOprtMode_enum_ovrdflg)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  Constant: '<S363>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S363>/Data Type Conversion3'
     */
    VOPM_BCMIllmndSts_enum = KOPM_PTActlOprtMode_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S363>/Data Type Conversion1'
     */
    VOPM_BCMIllmndSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Vcu2OpmBAC_outputs())
            ->VHVM_PTActOprtMode_enum;
  }

  /* End of Switch: '<S363>/Switch4' */

  /* MinMax: '<S363>/MinMax' incorporates:
   *  Constant: '<S363>/sat6'
   */
  if (VOPM_BCMIllmndSts_enum > KOPM_PTActlOprtModeHi_enum)
  {
    VOPM_BCMIllmndSts_enum = KOPM_PTActlOprtModeHi_enum;
  }

  /* MinMax: '<S363>/MinMax1' incorporates:
   *  Constant: '<S363>/sat7'
   */
  if (VOPM_BCMIllmndSts_enum >= KOPM_PTActlOprtModeLo_enum)
  {
    /* DataTypeConversion: '<S363>/Data Type Conversion2' */
    VOPM_PTActlOprtMode_enum = VOPM_BCMIllmndSts_enum;
  }
  else
  {
    /* DataTypeConversion: '<S363>/Data Type Conversion2' */
    VOPM_PTActlOprtMode_enum = KOPM_PTActlOprtModeLo_enum;
  }

  /* End of MinMax: '<S363>/MinMax1' */
  /* End of Outputs for SubSystem: '<S348>/Subsys_VOPM_PTActlOprtMode_enum' */

  /* DataTypeConversion: '<S348>/DataTypeConversion' incorporates:
   *  DataTypeConversion: '<S363>/Data Type Conversion2'
   */
  AppSwcOpm_ARID_DEF.CCU_VehInfo_BAC_i.VCU_PTActlOprtMode =
      VOPM_PTActlOprtMode_enum;

  /* Outputs for Atomic SubSystem: '<S348>/Subsys_VOPM_VehActlGearPosVld_flg' */
  /* Switch: '<S367>/Switch4' incorporates:
   *  Constant: '<S367>/sat3'
   */
  if (KOPM_VehActlGearPosVld_flg_ovrdflg)
  {
    /* Switch: '<S367>/Switch4' incorporates:
     *  Constant: '<S367>/sat4'
     */
    VOPM_VehActlGearPosVld_flg = KOPM_VehActlGearPosVld_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S367>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S367>/Data Type Conversion1'
     */
    VOPM_VehActlGearPosVld_flg =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Vcu2OpmBAC_outputs())
            ->VGSM_VehActGearPstnV_flg;
  }

  /* End of Switch: '<S367>/Switch4' */
  /* End of Outputs for SubSystem: '<S348>/Subsys_VOPM_VehActlGearPosVld_flg' */

  /* Outputs for Atomic SubSystem: '<S348>/Subsys_VOPM_VehActlGearPos_enum' */
  /* Switch: '<S368>/Switch4' incorporates:
   *  Constant: '<S368>/sat3'
   */
  if (KOPM_VehActlGearPos_enum_ovrdflg)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  Constant: '<S368>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S368>/Data Type Conversion3'
     */
    VOPM_BCMIllmndSts_enum = KOPM_VehActlGearPos_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S368>/Data Type Conversion1'
     */
    VOPM_BCMIllmndSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Vcu2OpmBAC_outputs())
            ->VGSM_VehActGearPstn_enum;
  }

  /* End of Switch: '<S368>/Switch4' */

  /* MinMax: '<S368>/MinMax' incorporates:
   *  Constant: '<S368>/sat6'
   */
  if (VOPM_BCMIllmndSts_enum > KOPM_VehActlGearPosHi_enum)
  {
    /* MinMax: '<S363>/MinMax' */
    VOPM_BCMIllmndSts_enum = KOPM_VehActlGearPosHi_enum;
  }

  /* End of MinMax: '<S368>/MinMax' */

  /* MinMax: '<S368>/MinMax1' incorporates:
   *  Constant: '<S368>/sat7'
   */
  if (VOPM_BCMIllmndSts_enum >= KOPM_VehActlGearPosLo_enum)
  {
    /* DataTypeConversion: '<S368>/Data Type Conversion2' */
    VOPM_VehActlGearPos_enum = VOPM_BCMIllmndSts_enum;
  }
  else
  {
    /* DataTypeConversion: '<S368>/Data Type Conversion2' */
    VOPM_VehActlGearPos_enum = KOPM_VehActlGearPosLo_enum;
  }

  /* End of MinMax: '<S368>/MinMax1' */
  /* End of Outputs for SubSystem: '<S348>/Subsys_VOPM_VehActlGearPos_enum' */

  /* Outputs for Atomic SubSystem: '<S348>/Subsys_VOPM_BCMBrkPedSta_flg' */
  /* Switch: '<S352>/Switch4' incorporates:
   *  Constant: '<S352>/sat3'
   */
  if (KOPM_BCMBrkPedSta_flg_ovrdflg)
  {
    /* Switch: '<S352>/Switch4' incorporates:
     *  Constant: '<S352>/sat4'
     */
    VOPM_BCMBrkPedSta_flg = KOPM_BCMBrkPedSta_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S352>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S352>/Data Type Conversion1'
     */
    VOPM_BCMBrkPedSta_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
             ->BCM_BrakePedalSta != 0);
  }

  /* End of Switch: '<S352>/Switch4' */
  /* End of Outputs for SubSystem: '<S348>/Subsys_VOPM_BCMBrkPedSta_flg' */

  /* Outputs for Atomic SubSystem: '<S348>/Subsys_VOPM_BCMSysPwrModeVld_flg' */
  /* Switch: '<S358>/Switch4' incorporates:
   *  Constant: '<S358>/sat3'
   */
  if (KOPM_BCMSysPwrModeVld_flg_ovrdflg)
  {
    /* Switch: '<S358>/Switch4' incorporates:
     *  Constant: '<S358>/sat4'
     */
    VOPM_BCMSysPwrModeVld_flg = KOPM_BCMSysPwrModeVld_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S358>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S358>/Data Type Conversion1'
     */
    VOPM_BCMSysPwrModeVld_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_SysPwrModeV != 0);
  }

  /* End of Switch: '<S358>/Switch4' */
  /* End of Outputs for SubSystem: '<S348>/Subsys_VOPM_BCMSysPwrModeVld_flg' */

  /* Outputs for Atomic SubSystem: '<S348>/Subsys_VOPM_BCMSysPwrMode_enum' */
  /* Switch: '<S359>/Switch4' incorporates:
   *  Constant: '<S359>/sat3'
   */
  if (KOPM_BCMSysPwrMode_enum_ovrdflg)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  Constant: '<S359>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     */
    VOPM_BCMIllmndSts_enum = KOPM_BCMSysPwrMode_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S359>/Data Type Conversion1'
     */
    VOPM_BCMIllmndSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_SysPwrMode;
  }

  /* End of Switch: '<S359>/Switch4' */

  /* MinMax: '<S359>/MinMax' incorporates:
   *  Constant: '<S359>/sat6'
   */
  if (VOPM_BCMIllmndSts_enum > KOPM_BCMSysPwrModeHi_enum)
  {
    /* MinMax: '<S363>/MinMax' */
    VOPM_BCMIllmndSts_enum = KOPM_BCMSysPwrModeHi_enum;
  }

  /* End of MinMax: '<S359>/MinMax' */

  /* MinMax: '<S359>/MinMax1' incorporates:
   *  Constant: '<S359>/sat7'
   */
  if (VOPM_BCMIllmndSts_enum >= KOPM_BCMSysPwrModeLo_enum)
  {
    /* MinMax: '<S359>/MinMax1' */
    VOPM_BCMSysPwrMode_enum = VOPM_BCMIllmndSts_enum;
  }
  else
  {
    /* MinMax: '<S359>/MinMax1' */
    VOPM_BCMSysPwrMode_enum = KOPM_BCMSysPwrModeLo_enum;
  }

  /* End of MinMax: '<S359>/MinMax1' */
  /* End of Outputs for SubSystem: '<S348>/Subsys_VOPM_BCMSysPwrMode_enum' */

  /* Outputs for Atomic SubSystem: '<S348>/Subsys_VOPM_12VBatLowVolSta_enum' */
  /* Switch: '<S350>/Switch4' incorporates:
   *  Constant: '<S350>/sat3'
   */
  if (KOPM_12VBatLowVolSta_enum_ovrdflg)
  {
    /* MinMax: '<S350>/MinMax' incorporates:
     *  Constant: '<S350>/sat4'
     *  MinMax: '<S351>/MinMax'
     */
    VOPM_BCMBackLadjvalFb_enum = KOPM_12VBatLowVolSta_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S350>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S350>/Data Type Conversion1'
     *  MinMax: '<S351>/MinMax'
     */
    VOPM_BCMBackLadjvalFb_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Vcu2OpmBAC_outputs())
            ->VHMI_12VBatLoVolSta_enum;
  }

  /* End of Switch: '<S350>/Switch4' */

  /* MinMax: '<S350>/MinMax' incorporates:
   *  Constant: '<S350>/sat6'
   */
  if (VOPM_BCMBackLadjvalFb_enum > KOPM_12VBatLowVolStaHi_enum)
  {
    VOPM_BCMBackLadjvalFb_enum = KOPM_12VBatLowVolStaHi_enum;
  }

  /* MinMax: '<S350>/MinMax1' incorporates:
   *  Constant: '<S350>/sat7'
   */
  if (VOPM_BCMBackLadjvalFb_enum >= KOPM_12VBatLowVolStaLo_enum)
  {
    /* MinMax: '<S350>/MinMax1' */
    VOPM_12VBatLowVolSta_enum = VOPM_BCMBackLadjvalFb_enum;
  }
  else
  {
    /* MinMax: '<S350>/MinMax1' */
    VOPM_12VBatLowVolSta_enum = KOPM_12VBatLowVolStaLo_enum;
  }

  /* End of MinMax: '<S350>/MinMax1' */
  /* End of Outputs for SubSystem: '<S348>/Subsys_VOPM_12VBatLowVolSta_enum' */

  /* Outputs for Atomic SubSystem: '<S348>/Subsys_VOPM_LimpHomeSta_flg' */
  /* Switch: '<S361>/Switch4' incorporates:
   *  Constant: '<S361>/sat3'
   */
  if (KOPM_LimpHomeSta_flg_ovrdflg)
  {
    /* Switch: '<S361>/Switch4' incorporates:
     *  Constant: '<S361>/sat4'
     */
    VOPM_LimpHomeSta_flg = KOPM_LimpHomeSta_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S361>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S361>/Data Type Conversion1'
     */
    VOPM_LimpHomeSta_flg = (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Vcu2OpmBAC_outputs())
                               ->VDAG_LimpHome_flg;
  }

  /* End of Switch: '<S361>/Switch4' */
  /* End of Outputs for SubSystem: '<S348>/Subsys_VOPM_LimpHomeSta_flg' */

  /* Outputs for Atomic SubSystem: '<S348>/Subsys_VOPM_PCUFailSta_flg' */
  /* Switch: '<S362>/Switch4' incorporates:
   *  Constant: '<S362>/sat3'
   */
  if (KOPM_PCUFailSta_flg_ovrdflg)
  {
    /* Switch: '<S362>/Switch4' incorporates:
     *  Constant: '<S362>/sat4'
     */
    VOPM_PCUFailSta_flg = KOPM_PCUFailSta_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S362>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S362>/Data Type Conversion1'
     */
    VOPM_PCUFailSta_flg = (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Vcu2OpmBAC_outputs())
                              ->VVTM_PCUFailSta_flg;
  }

  /* End of Switch: '<S362>/Switch4' */
  /* End of Outputs for SubSystem: '<S348>/Subsys_VOPM_PCUFailSta_flg' */

  /* Outputs for Atomic SubSystem: '<S348>/Subsys_VOPM_BCMCenLckSts_enum' */
  /* Switch: '<S353>/Switch4' incorporates:
   *  Constant: '<S353>/sat3'
   */
  if (KOPM_BCMCenLckSts_enum_ovrdflg)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  Constant: '<S353>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     */
    VOPM_BCMIllmndSts_enum = KOPM_BCMCenLckSts_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S353>/Data Type Conversion1'
     */
    VOPM_BCMIllmndSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
            ->BCM_CentralLockSts;
  }

  /* End of Switch: '<S353>/Switch4' */

  /* MinMax: '<S353>/MinMax' incorporates:
   *  Constant: '<S353>/sat6'
   */
  if (VOPM_BCMIllmndSts_enum > KOPM_BCMCenLckStsHi_enum)
  {
    /* MinMax: '<S363>/MinMax' */
    VOPM_BCMIllmndSts_enum = KOPM_BCMCenLckStsHi_enum;
  }

  /* End of MinMax: '<S353>/MinMax' */

  /* MinMax: '<S353>/MinMax1' incorporates:
   *  Constant: '<S353>/sat7'
   */
  if (VOPM_BCMIllmndSts_enum >= KOPM_BCMCenLckStsLo_enum)
  {
    /* MinMax: '<S353>/MinMax1' */
    VOPM_BCMCenLckSts_enum = VOPM_BCMIllmndSts_enum;
  }
  else
  {
    /* MinMax: '<S353>/MinMax1' */
    VOPM_BCMCenLckSts_enum = KOPM_BCMCenLckStsLo_enum;
  }

  /* End of MinMax: '<S353>/MinMax1' */
  /* End of Outputs for SubSystem: '<S348>/Subsys_VOPM_BCMCenLckSts_enum' */

  /* Outputs for Atomic SubSystem: '<S348>/Subsys_VOPM_BCMSysPowerSts_enum' */
  /* Switch: '<S357>/Switch4' incorporates:
   *  Constant: '<S357>/sat3'
   */
  if (KOPM_BCMSysPowerSts_enum_ovrdflg)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  Constant: '<S357>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     */
    VOPM_BCMIllmndSts_enum = KOPM_BCMSysPowerSts_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S357>/Data Type Conversion1'
     */
    VOPM_BCMIllmndSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_SysPowerSts;
  }

  /* End of Switch: '<S357>/Switch4' */

  /* MinMax: '<S357>/MinMax' incorporates:
   *  Constant: '<S357>/sat6'
   */
  if (VOPM_BCMIllmndSts_enum > KOPM_BCMSysPowerStsHi_enum)
  {
    /* MinMax: '<S363>/MinMax' */
    VOPM_BCMIllmndSts_enum = KOPM_BCMSysPowerStsHi_enum;
  }

  /* End of MinMax: '<S357>/MinMax' */

  /* MinMax: '<S357>/MinMax1' incorporates:
   *  Constant: '<S357>/sat7'
   */
  if (VOPM_BCMIllmndSts_enum >= KOPM_BCMSysPowerStsLo_enum)
  {
    /* MinMax: '<S357>/MinMax1' */
    VOPM_BCMSysPowerSts_enum = VOPM_BCMIllmndSts_enum;
  }
  else
  {
    /* MinMax: '<S357>/MinMax1' */
    VOPM_BCMSysPowerSts_enum = KOPM_BCMSysPowerStsLo_enum;
  }

  /* End of MinMax: '<S357>/MinMax1' */
  /* End of Outputs for SubSystem: '<S348>/Subsys_VOPM_BCMSysPowerSts_enum' */

  /* Outputs for Atomic SubSystem: '<S348>/Subsys_VOPM_PwrRecupIntnsty_enum' */
  /* Switch: '<S365>/Switch4' incorporates:
   *  Constant: '<S365>/sat3'
   */
  if (KOPM_PwrRecupIntnsty_enum_ovrdflg)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  Constant: '<S365>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S365>/Data Type Conversion3'
     */
    VOPM_BCMIllmndSts_enum = KOPM_PwrRecupIntnsty_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S365>/Data Type Conversion1'
     */
    VOPM_BCMIllmndSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Vcu2OpmBAC_outputs())
            ->VIPC_RegenModeAct_enum;
  }

  /* End of Switch: '<S365>/Switch4' */

  /* MinMax: '<S365>/MinMax' incorporates:
   *  Constant: '<S365>/sat6'
   */
  if (VOPM_BCMIllmndSts_enum > KOPM_PwrRecupIntnstyHi_enum)
  {
    /* MinMax: '<S363>/MinMax' */
    VOPM_BCMIllmndSts_enum = KOPM_PwrRecupIntnstyHi_enum;
  }

  /* End of MinMax: '<S365>/MinMax' */

  /* MinMax: '<S365>/MinMax1' incorporates:
   *  Constant: '<S365>/sat7'
   */
  if (VOPM_BCMIllmndSts_enum >= KOPM_PwrRecupIntnstyLo_enum)
  {
    /* DataTypeConversion: '<S365>/Data Type Conversion2' */
    VOPM_PwrRecupIntnsty_enum = VOPM_BCMIllmndSts_enum;
  }
  else
  {
    /* DataTypeConversion: '<S365>/Data Type Conversion2' */
    VOPM_PwrRecupIntnsty_enum = KOPM_PwrRecupIntnstyLo_enum;
  }

  /* End of MinMax: '<S365>/MinMax1' */
  /* End of Outputs for SubSystem: '<S348>/Subsys_VOPM_PwrRecupIntnsty_enum' */

  /* DataTypeConversion: '<S348>/DataTypeConversion11' incorporates:
   *  DataTypeConversion: '<S365>/Data Type Conversion2'
   */
  AppSwcOpm_ARID_DEF.CCU_VehInfo_BAC_i.VCU_PwrRecupIntensity =
      VOPM_PwrRecupIntnsty_enum;

  /* Outputs for Atomic SubSystem: '<S348>/Subsys_VOPM_BCMDoorLckStaFL_flg' */
  /* Switch: '<S354>/Switch4' incorporates:
   *  Constant: '<S354>/sat3'
   */
  if (KOPM_BCMDoorLckStaFL_flg_ovrdflg)
  {
    /* Switch: '<S354>/Switch4' incorporates:
     *  Constant: '<S354>/sat4'
     */
    VOPM_BCMDoorLckStaFL_flg = KOPM_BCMDoorLckStaFL_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S354>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S354>/Data Type Conversion1'
     */
    VOPM_BCMDoorLckStaFL_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
             ->BCM_DoorLockSta_FL != 0);
  }

  /* End of Switch: '<S354>/Switch4' */
  /* End of Outputs for SubSystem: '<S348>/Subsys_VOPM_BCMDoorLckStaFL_flg' */

  /* Outputs for Atomic SubSystem: '<S348>/Subsys_VOPM_PrstlsStaFb_enum' */
  /* Switch: '<S364>/Switch4' incorporates:
   *  Constant: '<S364>/sat3'
   */
  if (KOPM_PrstlsStaFb_enum_ovrdflg)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  Constant: '<S364>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S364>/Data Type Conversion3'
     */
    VOPM_BCMIllmndSts_enum = KOPM_PrstlsStaFb_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S364>/Data Type Conversion1'
     */
    VOPM_BCMIllmndSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Vcu2OpmBAC_outputs())
            ->VIPC_CrpModeAct_enum;
  }

  /* End of Switch: '<S364>/Switch4' */

  /* MinMax: '<S364>/MinMax' incorporates:
   *  Constant: '<S364>/sat6'
   */
  if (VOPM_BCMIllmndSts_enum > KOPM_PrstlsStaFbHi_enum)
  {
    /* MinMax: '<S363>/MinMax' */
    VOPM_BCMIllmndSts_enum = KOPM_PrstlsStaFbHi_enum;
  }

  /* End of MinMax: '<S364>/MinMax' */

  /* MinMax: '<S364>/MinMax1' incorporates:
   *  Constant: '<S364>/sat7'
   */
  if (VOPM_BCMIllmndSts_enum >= KOPM_PrstlsStaFbLo_enum)
  {
    /* DataTypeConversion: '<S364>/Data Type Conversion2' */
    VOPM_PrstlsStaFb_enum = VOPM_BCMIllmndSts_enum;
  }
  else
  {
    /* DataTypeConversion: '<S364>/Data Type Conversion2' */
    VOPM_PrstlsStaFb_enum = KOPM_PrstlsStaFbLo_enum;
  }

  /* End of MinMax: '<S364>/MinMax1' */
  /* End of Outputs for SubSystem: '<S348>/Subsys_VOPM_PrstlsStaFb_enum' */

  /* Outputs for Atomic SubSystem: '<S348>/Subsys_VOPM_VehActDrvMod1_enum' */
  /* Switch: '<S366>/Switch4' incorporates:
   *  Constant: '<S366>/sat3'
   */
  if (KOPM_VehActDrvMod1_enum_ovrdflg)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  Constant: '<S366>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S366>/Data Type Conversion3'
     */
    VOPM_BCMIllmndSts_enum = KOPM_VehActDrvMod1_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S366>/Data Type Conversion1'
     */
    VOPM_BCMIllmndSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Vcu2OpmBAC_outputs())
            ->VIPC_DrvModeAct_enum;
  }

  /* End of Switch: '<S366>/Switch4' */

  /* MinMax: '<S366>/MinMax' incorporates:
   *  Constant: '<S366>/sat6'
   */
  if (VOPM_BCMIllmndSts_enum > KOPM_VehActDrvMod1Hi_enum)
  {
    /* MinMax: '<S363>/MinMax' */
    VOPM_BCMIllmndSts_enum = KOPM_VehActDrvMod1Hi_enum;
  }

  /* End of MinMax: '<S366>/MinMax' */

  /* MinMax: '<S366>/MinMax1' incorporates:
   *  Constant: '<S366>/sat7'
   */
  if (VOPM_BCMIllmndSts_enum >= KOPM_VehActDrvMod1Lo_enum)
  {
    /* DataTypeConversion: '<S366>/Data Type Conversion2' */
    VOPM_VehActDrvMod1_enum = VOPM_BCMIllmndSts_enum;
  }
  else
  {
    /* DataTypeConversion: '<S366>/Data Type Conversion2' */
    VOPM_VehActDrvMod1_enum = KOPM_VehActDrvMod1Lo_enum;
  }

  /* End of MinMax: '<S366>/MinMax1' */
  /* End of Outputs for SubSystem: '<S348>/Subsys_VOPM_VehActDrvMod1_enum' */

  /* Outputs for Atomic SubSystem: '<S348>/Subsys_VOPM_HDCStat_enum' */
  /* Switch: '<S360>/Switch4' incorporates:
   *  Constant: '<S360>/sat3'
   */
  if (KOPM_HDCStat_enum_ovrdflg)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  Constant: '<S360>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     */
    VOPM_BCMIllmndSts_enum = KOPM_HDCStat_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S360>/Data Type Conversion1'
     */
    VOPM_BCMIllmndSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Vcu2OpmBAC_outputs())->VVTM_HDCStat_enum;
  }

  /* End of Switch: '<S360>/Switch4' */

  /* MinMax: '<S360>/MinMax' incorporates:
   *  Constant: '<S360>/sat6'
   */
  if (VOPM_BCMIllmndSts_enum > KOPM_HDCStatHi_enum)
  {
    /* MinMax: '<S363>/MinMax' */
    VOPM_BCMIllmndSts_enum = KOPM_HDCStatHi_enum;
  }

  /* End of MinMax: '<S360>/MinMax' */

  /* MinMax: '<S360>/MinMax1' incorporates:
   *  Constant: '<S360>/sat7'
   */
  if (VOPM_BCMIllmndSts_enum >= KOPM_HDCStatLo_enum)
  {
    /* MinMax: '<S360>/MinMax1' */
    VOPM_HDCStat_enum = VOPM_BCMIllmndSts_enum;
  }
  else
  {
    /* MinMax: '<S360>/MinMax1' */
    VOPM_HDCStat_enum = KOPM_HDCStatLo_enum;
  }

  /* End of MinMax: '<S360>/MinMax1' */
  /* End of Outputs for SubSystem: '<S348>/Subsys_VOPM_HDCStat_enum' */

  /* Outputs for Atomic SubSystem: '<S348>/Subsys_VOPM_BCMHazardLampSts_flg' */
  /* Switch: '<S355>/Switch4' incorporates:
   *  Constant: '<S355>/sat3'
   */
  if (KOPM_BCMHazardLampSts_flg_ovrdflg)
  {
    /* Switch: '<S355>/Switch4' incorporates:
     *  Constant: '<S355>/sat4'
     */
    VOPM_BCMHazardLampSts_flg = KOPM_BCMHazardLampSts_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S355>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S355>/Data Type Conversion1'
     */
    VOPM_BCMHazardLampSts_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
             ->BCM_HazardLampSts != 0);
  }

  /* End of Switch: '<S355>/Switch4' */
  /* End of Outputs for SubSystem: '<S348>/Subsys_VOPM_BCMHazardLampSts_flg' */

  /* Outputs for Atomic SubSystem: '<S348>/Subsys_VOPM_BCMBackLadjvalFb_enum' */
  /* Switch: '<S351>/Switch4' incorporates:
   *  Constant: '<S351>/sat3'
   */
  if (KOPM_BCMBackLadjvalFb_enum_ovrdflg)
  {
    /* MinMax: '<S350>/MinMax' incorporates:
     *  Constant: '<S351>/sat4'
     *  MinMax: '<S351>/MinMax'
     */
    VOPM_BCMBackLadjvalFb_enum = KOPM_BCMBackLadjvalFb_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S350>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S351>/Data Type Conversion1'
     *  MinMax: '<S351>/MinMax'
     */
    VOPM_BCMBackLadjvalFb_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_BackLadjvalFb;
  }

  /* End of Switch: '<S351>/Switch4' */

  /* MinMax: '<S351>/MinMax' incorporates:
   *  Constant: '<S351>/sat6'
   */
  if (VOPM_BCMBackLadjvalFb_enum > KOPM_BCMBackLadjvalFbHi_enum)
  {
    /* MinMax: '<S350>/MinMax' */
    VOPM_BCMBackLadjvalFb_enum = KOPM_BCMBackLadjvalFbHi_enum;
  }

  /* End of MinMax: '<S351>/MinMax' */

  /* MinMax: '<S351>/MinMax1' incorporates:
   *  Constant: '<S351>/sat7'
   */
  if (VOPM_BCMBackLadjvalFb_enum < KOPM_BCMBackLadjvalFbLo_enum)
  {
    /* MinMax: '<S350>/MinMax' incorporates:
     *  MinMax: '<S351>/MinMax1'
     */
    VOPM_BCMBackLadjvalFb_enum = KOPM_BCMBackLadjvalFbLo_enum;
  }

  /* End of MinMax: '<S351>/MinMax1' */
  /* End of Outputs for SubSystem: '<S348>/Subsys_VOPM_BCMBackLadjvalFb_enum' */

  /* Outputs for Atomic SubSystem: '<S348>/Subsys_VOPM_BCMPosLampSta_flg' */
  /* Switch: '<S356>/Switch4' incorporates:
   *  Constant: '<S356>/sat3'
   */
  if (KOPM_BCMPosLampSta_flg_ovrdflg)
  {
    /* Switch: '<S356>/Switch4' incorporates:
     *  Constant: '<S356>/sat4'
     */
    VOPM_BCMPosLampSta_flg = KOPM_BCMPosLampSta_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S356>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S356>/Data Type Conversion1'
     */
    VOPM_BCMPosLampSta_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_PosLampSta != 0);
  }

  /* End of Switch: '<S356>/Switch4' */
  /* End of Outputs for SubSystem: '<S348>/Subsys_VOPM_BCMPosLampSta_flg' */

  /* BusCreator: '<S348>/BusCreator' incorporates:
   *  Constant: '<S348>/Constant'
   *  DataTypeConversion: '<S348>/DataTypeConversion13'
   *  DataTypeConversion: '<S348>/DataTypeConversion14'
   *  DataTypeConversion: '<S348>/DataTypeConversion17'
   *  DataTypeConversion: '<S348>/DataTypeConversion2'
   *  DataTypeConversion: '<S364>/Data Type Conversion2'
   *  DataTypeConversion: '<S366>/Data Type Conversion2'
   *  DataTypeConversion: '<S368>/Data Type Conversion2'
   *  Switch: '<S352>/Switch4'
   *  Switch: '<S354>/Switch4'
   *  Switch: '<S355>/Switch4'
   *  Switch: '<S356>/Switch4'
   *  Switch: '<S358>/Switch4'
   *  Switch: '<S361>/Switch4'
   *  Switch: '<S362>/Switch4'
   *  Switch: '<S367>/Switch4'
   */
  AppSwcOpm_ARID_DEF.CCU_VehInfo_BAC_i.VCU_VhclActlGearPosV =
      VOPM_VehActlGearPosVld_flg;
  AppSwcOpm_ARID_DEF.CCU_VehInfo_BAC_i.VCU_VhclActlGearPos =
      VOPM_VehActlGearPos_enum;
  AppSwcOpm_ARID_DEF.CCU_VehInfo_BAC_i.BCM_BrakePedalSta = VOPM_BCMBrkPedSta_flg;
  AppSwcOpm_ARID_DEF.CCU_VehInfo_BAC_i.BCM_SysPwrModeV =
      VOPM_BCMSysPwrModeVld_flg;
  AppSwcOpm_ARID_DEF.CCU_VehInfo_BAC_i.BCM_SysPwrMode = VOPM_BCMSysPwrMode_enum;
  AppSwcOpm_ARID_DEF.CCU_VehInfo_BAC_i.VCU_12VBatLowVolSta =
      VOPM_12VBatLowVolSta_enum;
  AppSwcOpm_ARID_DEF.CCU_VehInfo_BAC_i.VCU_LimpHomeSta = VOPM_LimpHomeSta_flg;
  AppSwcOpm_ARID_DEF.CCU_VehInfo_BAC_i.VCU_PCUFailSta = VOPM_PCUFailSta_flg;
  AppSwcOpm_ARID_DEF.CCU_VehInfo_BAC_i.BCM_CentralLockSts =
      VOPM_BCMCenLckSts_enum;
  AppSwcOpm_ARID_DEF.CCU_VehInfo_BAC_i.BCM_SysPowerSts =
      VOPM_BCMSysPowerSts_enum;
  AppSwcOpm_ARID_DEF.CCU_VehInfo_BAC_i.BCM_DoorLockSta_FL =
      VOPM_BCMDoorLckStaFL_flg;
  AppSwcOpm_ARID_DEF.CCU_VehInfo_BAC_i.VCU_PrstlsStaFb = VOPM_PrstlsStaFb_enum;
  AppSwcOpm_ARID_DEF.CCU_VehInfo_BAC_i.VCU_VehActDrvMod1 =
      VOPM_VehActDrvMod1_enum;
  AppSwcOpm_ARID_DEF.CCU_VehInfo_BAC_i.CCU_DiagTesterOnline = CCU_DiagTesterOnlineFlag;
  AppSwcOpm_ARID_DEF.CCU_VehInfo_BAC_i.VCU_HDCStatus = VOPM_HDCStat_enum;
  AppSwcOpm_ARID_DEF.CCU_VehInfo_BAC_i.BCM_HazardLampSts =
      VOPM_BCMHazardLampSts_flg;
  AppSwcOpm_ARID_DEF.CCU_VehInfo_BAC_i.BCM_BackLadjvalFb =
      VOPM_BCMBackLadjvalFb_enum;
  AppSwcOpm_ARID_DEF.CCU_VehInfo_BAC_i.BCM_PosLampSta = VOPM_BCMPosLampSta_flg;

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMTurnLampStaLeft_flg' */
  /* Switch: '<S469>/Switch4' incorporates:
   *  Constant: '<S469>/sat3'
   */
  if (KOPM_BCMTurnLampStaLeft_flg_ovrdflg)
  {
    /* Switch: '<S469>/Switch4' incorporates:
     *  Constant: '<S469>/sat4'
     */
    VOPM_BCMTurnLampStaLeft_flg = KOPM_BCMTurnLampStaLeft_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S469>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S469>/Data Type Conversion1'
     */
    VOPM_BCMTurnLampStaLeft_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
             ->BCM_TurnLampSta_Left != 0);
  }

  /* End of Switch: '<S469>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMTurnLampStaLeft_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMTurnLampStaRight_flg' */
  /* Switch: '<S470>/Switch4' incorporates:
   *  Constant: '<S470>/sat3'
   */
  if (KOPM_BCMTurnLampStaRight_flg_ovrdflg)
  {
    /* Switch: '<S470>/Switch4' incorporates:
     *  Constant: '<S470>/sat4'
     */
    VOPM_BCMTurnLampStaRight_flg = KOPM_BCMTurnLampStaRight_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S470>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S470>/Data Type Conversion1'
     */
    VOPM_BCMTurnLampStaRight_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
             ->BCM_TurnLampSta_Right != 0);
  }

  /* End of Switch: '<S470>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMTurnLampStaRight_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMFogLampStaRear_flg' */
  /* Switch: '<S407>/Switch4' incorporates:
   *  Constant: '<S407>/sat3'
   */
  if (KOPM_BCMFogLampStaRear_flg_ovrdflg)
  {
    /* Switch: '<S407>/Switch4' incorporates:
     *  Constant: '<S407>/sat4'
     */
    VOPM_BCMFogLampStaRear_flg = KOPM_BCMFogLampStaRear_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S407>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S407>/Data Type Conversion1'
     */
    VOPM_BCMFogLampStaRear_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
             ->BCM_FogLampSta_Rear != 0);
  }

  /* End of Switch: '<S407>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMFogLampStaRear_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMHighBeamSta_flg' */
  /* Switch: '<S418>/Switch4' incorporates:
   *  Constant: '<S418>/sat3'
   */
  if (KOPM_BCMHighBeamSta_flg_ovrdflg)
  {
    /* Switch: '<S418>/Switch4' incorporates:
     *  Constant: '<S418>/sat4'
     */
    VOPM_BCMHighBeamSta_flg = KOPM_BCMHighBeamSta_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S418>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S418>/Data Type Conversion1'
     */
    VOPM_BCMHighBeamSta_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_HighBeamSta != 0);
  }

  /* End of Switch: '<S418>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMHighBeamSta_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMLowBeamSta_flg' */
  /* Switch: '<S442>/Switch4' incorporates:
   *  Constant: '<S442>/sat3'
   */
  if (KOPM_BCMLowBeamSta_flg_ovrdflg)
  {
    /* Switch: '<S442>/Switch4' incorporates:
     *  Constant: '<S442>/sat4'
     */
    VOPM_BCMLowBeamSta_flg = KOPM_BCMLowBeamSta_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S442>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S442>/Data Type Conversion1'
     */
    VOPM_BCMLowBeamSta_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_LowBeamSta != 0);
  }

  /* End of Switch: '<S442>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMLowBeamSta_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMFogLampStaFront_flg' */
  /* Switch: '<S406>/Switch4' incorporates:
   *  Constant: '<S406>/sat3'
   */
  if (KOPM_BCMFogLampStaFront_flg_ovrdflg)
  {
    /* Switch: '<S406>/Switch4' incorporates:
     *  Constant: '<S406>/sat4'
     */
    VOPM_BCMFogLampStaFront_flg = KOPM_BCMFogLampStaFront_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S406>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S406>/Data Type Conversion1'
     */
    VOPM_BCMFogLampStaFront_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
             ->BCM_FogLampSta_Front != 0);
  }

  /* End of Switch: '<S406>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMFogLampStaFront_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMAutoLampStatus_flg' */
  /* Switch: '<S374>/Switch4' incorporates:
   *  Constant: '<S374>/sat3'
   */
  if (KOPM_BCMAutoLampStatus_flg_ovrdflg)
  {
    /* Switch: '<S374>/Switch4' incorporates:
     *  Constant: '<S374>/sat4'
     */
    VOPM_BCMAutoLampStatus_flg = KOPM_BCMAutoLampStatus_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S374>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S374>/Data Type Conversion1'
     */
    VOPM_BCMAutoLampStatus_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
             ->BCM_AutoLampStatus != 0);
  }

  /* End of Switch: '<S374>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMAutoLampStatus_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMDayRunLightSta_flg' */
  /* Switch: '<S387>/Switch4' incorporates:
   *  Constant: '<S387>/sat3'
   */
  if (KOPM_BCMDayRunLightSta_flg_ovrdflg)
  {
    /* Switch: '<S387>/Switch4' incorporates:
     *  Constant: '<S387>/sat4'
     */
    VOPM_BCMDayRunLightSta_flg = KOPM_BCMDayRunLightSta_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S387>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S387>/Data Type Conversion1'
     */
    VOPM_BCMDayRunLightSta_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
             ->BCM_DayRunLightSta != 0);
  }

  /* End of Switch: '<S387>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMDayRunLightSta_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMReverseLampSta_flg' */
  /* Switch: '<S454>/Switch4' incorporates:
   *  Constant: '<S454>/sat3'
   */
  if (KOPM_BCMReverseLampSta_flg_ovrdflg)
  {
    /* Switch: '<S454>/Switch4' incorporates:
     *  Constant: '<S454>/sat4'
     */
    VOPM_BCMReverseLampSta_flg = KOPM_BCMReverseLampSta_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S454>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S454>/Data Type Conversion1'
     */
    VOPM_BCMReverseLampSta_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
             ->BCM_ReverseLampSta != 0);
  }

  /* End of Switch: '<S454>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMReverseLampSta_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMBrakeLampSta_flg' */
  /* Switch: '<S380>/Switch4' incorporates:
   *  Constant: '<S380>/sat3'
   */
  if (KOPM_BCMBrakeLampSta_flg_ovrdflg)
  {
    /* Switch: '<S380>/Switch4' incorporates:
     *  Constant: '<S380>/sat4'
     */
    VOPM_BCMBrakeLampSta_flg = KOPM_BCMBrakeLampSta_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S380>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S380>/Data Type Conversion1'
     */
    VOPM_BCMBrakeLampSta_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_BrakeLampSta != 0);
  }

  /* End of Switch: '<S380>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMBrakeLampSta_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMDayRunLiSwSig_flg' */
  /* Switch: '<S386>/Switch4' incorporates:
   *  Constant: '<S386>/sat3'
   */
  if (KOPM_BCMDayRunLiSwSig_flg_ovrdflg)
  {
    /* Switch: '<S386>/Switch4' incorporates:
     *  Constant: '<S386>/sat4'
     */
    VOPM_BCMDayRunLiSwSig_flg = KOPM_BCMDayRunLiSwSig_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S386>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S386>/Data Type Conversion1'
     */
    VOPM_BCMDayRunLiSwSig_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
             ->BCM_DayRunLiSwSig != 0);
  }

  /* End of Switch: '<S386>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMDayRunLiSwSig_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMTurnLiSts_enum' */
  /* Switch: '<S471>/Switch4' incorporates:
   *  Constant: '<S471>/sat3'
   */
  if (KOPM_BCMTurnLiSts_enum_ovrdflg)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  Constant: '<S471>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     */
    VOPM_BCMIllmndSts_enum = KOPM_BCMTurnLiSts_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S471>/Data Type Conversion1'
     */
    VOPM_BCMIllmndSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_TurnLiSts;
  }

  /* End of Switch: '<S471>/Switch4' */

  /* MinMax: '<S471>/MinMax' incorporates:
   *  Constant: '<S471>/sat6'
   */
  if (VOPM_BCMIllmndSts_enum > KOPM_BCMTurnLiStsHi_enum)
  {
    /* MinMax: '<S363>/MinMax' */
    VOPM_BCMIllmndSts_enum = KOPM_BCMTurnLiStsHi_enum;
  }

  /* End of MinMax: '<S471>/MinMax' */

  /* MinMax: '<S471>/MinMax1' incorporates:
   *  Constant: '<S471>/sat7'
   */
  if (VOPM_BCMIllmndSts_enum >= KOPM_BCMTurnLiStsLo_enum)
  {
    /* MinMax: '<S471>/MinMax1' */
    VOPM_BCMTurnLiSts_enum = VOPM_BCMIllmndSts_enum;
  }
  else
  {
    /* MinMax: '<S471>/MinMax1' */
    VOPM_BCMTurnLiSts_enum = KOPM_BCMTurnLiStsLo_enum;
  }

  /* End of MinMax: '<S471>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMTurnLiSts_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMTrnngLiSwSig_enum' */
  /* Switch: '<S467>/Switch4' incorporates:
   *  Constant: '<S467>/sat3'
   */
  if (KOPM_BCMTrnngLiSwSig_enum_ovrdflg)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  Constant: '<S467>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     */
    VOPM_BCMIllmndSts_enum = KOPM_BCMTrnngLiSwSig_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S467>/Data Type Conversion1'
     */
    VOPM_BCMIllmndSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_TurnngLiSwSig;
  }

  /* End of Switch: '<S467>/Switch4' */

  /* MinMax: '<S467>/MinMax' incorporates:
   *  Constant: '<S467>/sat6'
   */
  if (VOPM_BCMIllmndSts_enum > KOPM_BCMTrnngLiSwSigHi_enum)
  {
    /* MinMax: '<S363>/MinMax' */
    VOPM_BCMIllmndSts_enum = KOPM_BCMTrnngLiSwSigHi_enum;
  }

  /* End of MinMax: '<S467>/MinMax' */

  /* MinMax: '<S467>/MinMax1' incorporates:
   *  Constant: '<S467>/sat7'
   */
  if (VOPM_BCMIllmndSts_enum >= KOPM_BCMTrnngLiSwSigLo_enum)
  {
    /* MinMax: '<S467>/MinMax1' */
    VOPM_BCMTrnngLiSwSig_enum = VOPM_BCMIllmndSts_enum;
  }
  else
  {
    /* MinMax: '<S467>/MinMax1' */
    VOPM_BCMTrnngLiSwSig_enum = KOPM_BCMTrnngLiSwSigLo_enum;
  }

  /* End of MinMax: '<S467>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMTrnngLiSwSig_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMLightIntensity_enum' */
  /* Switch: '<S439>/Switch4' incorporates:
   *  Constant: '<S439>/sat3'
   */
  if (KOPM_BCMLightIntensity_enum_ovrdflg)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  Constant: '<S439>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     */
    VOPM_BCMIllmndSts_enum = KOPM_BCMLightIntensity_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S439>/Data Type Conversion1'
     */
    VOPM_BCMIllmndSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
            ->BCM_LightIntensity;
  }

  /* End of Switch: '<S439>/Switch4' */

  /* MinMax: '<S439>/MinMax' incorporates:
   *  Constant: '<S439>/sat6'
   */
  if (VOPM_BCMIllmndSts_enum > KOPM_BCMLightIntensityHi_enum)
  {
    /* MinMax: '<S363>/MinMax' */
    VOPM_BCMIllmndSts_enum = KOPM_BCMLightIntensityHi_enum;
  }

  /* End of MinMax: '<S439>/MinMax' */

  /* MinMax: '<S439>/MinMax1' incorporates:
   *  Constant: '<S439>/sat7'
   */
  if (VOPM_BCMIllmndSts_enum >= KOPM_BCMLightIntensityLo_enum)
  {
    /* MinMax: '<S439>/MinMax1' */
    VOPM_BCMLightIntensity_enum = VOPM_BCMIllmndSts_enum;
  }
  else
  {
    /* MinMax: '<S439>/MinMax1' */
    VOPM_BCMLightIntensity_enum = KOPM_BCMLightIntensityLo_enum;
  }

  /* End of MinMax: '<S439>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMLightIntensity_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMLghtSwSig_enum' */
  /* Switch: '<S438>/Switch4' incorporates:
   *  Constant: '<S438>/sat3'
   */
  if (KOPM_BCMLghtSwSig_enum_ovrdflg)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  Constant: '<S438>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     */
    VOPM_BCMIllmndSts_enum = KOPM_BCMLghtSwSig_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S438>/Data Type Conversion1'
     */
    VOPM_BCMIllmndSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_LightSwSig;
  }

  /* End of Switch: '<S438>/Switch4' */

  /* MinMax: '<S438>/MinMax' incorporates:
   *  Constant: '<S438>/sat6'
   */
  if (VOPM_BCMIllmndSts_enum > KOPM_BCMLghtSwSigHi_enum)
  {
    /* MinMax: '<S363>/MinMax' */
    VOPM_BCMIllmndSts_enum = KOPM_BCMLghtSwSigHi_enum;
  }

  /* End of MinMax: '<S438>/MinMax' */

  /* MinMax: '<S438>/MinMax1' incorporates:
   *  Constant: '<S438>/sat7'
   */
  if (VOPM_BCMIllmndSts_enum >= KOPM_BCMLghtSwSigLo_enum)
  {
    /* MinMax: '<S438>/MinMax1' */
    VOPM_BCMLghtSwSig_enum = VOPM_BCMIllmndSts_enum;
  }
  else
  {
    /* MinMax: '<S438>/MinMax1' */
    VOPM_BCMLghtSwSig_enum = KOPM_BCMLghtSwSigLo_enum;
  }

  /* End of MinMax: '<S438>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMLghtSwSig_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMHiBeamSwSig_enum' */
  /* Switch: '<S417>/Switch4' incorporates:
   *  Constant: '<S417>/sat3'
   */
  if (KOPM_BCMHiBeamSwSig_enum_ovrdflg)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  Constant: '<S417>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     */
    VOPM_BCMIllmndSts_enum = KOPM_BCMHiBeamSwSig_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S417>/Data Type Conversion1'
     */
    VOPM_BCMIllmndSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_HighBeamSwSig;
  }

  /* End of Switch: '<S417>/Switch4' */

  /* MinMax: '<S417>/MinMax' incorporates:
   *  Constant: '<S417>/sat6'
   */
  if (VOPM_BCMIllmndSts_enum > KOPM_BCMHiBeamSwSigHi_enum)
  {
    /* MinMax: '<S363>/MinMax' */
    VOPM_BCMIllmndSts_enum = KOPM_BCMHiBeamSwSigHi_enum;
  }

  /* End of MinMax: '<S417>/MinMax' */

  /* MinMax: '<S417>/MinMax1' incorporates:
   *  Constant: '<S417>/sat7'
   */
  if (VOPM_BCMIllmndSts_enum >= KOPM_BCMHiBeamSwSigLo_enum)
  {
    /* MinMax: '<S417>/MinMax1' */
    VOPM_BCMHiBeamSwSig_enum = VOPM_BCMIllmndSts_enum;
  }
  else
  {
    /* MinMax: '<S417>/MinMax1' */
    VOPM_BCMHiBeamSwSig_enum = KOPM_BCMHiBeamSwSigLo_enum;
  }

  /* End of MinMax: '<S417>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMHiBeamSwSig_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMAjarStaVHoodVld_flg' */
  /* Switch: '<S371>/Switch4' incorporates:
   *  Constant: '<S371>/sat3'
   */
  if (KOPM_BCMAjarStaVHoodVld_flg_ovrdflg)
  {
    /* Switch: '<S371>/Switch4' incorporates:
     *  Constant: '<S371>/sat4'
     */
    VOPM_BCMAjarStaVHoodVld_flg = KOPM_BCMAjarStaVHoodVld_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S371>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S371>/Data Type Conversion1'
     */
    VOPM_BCMAjarStaVHoodVld_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
             ->BCM_AjarStaV_Hood != 0);
  }

  /* End of Switch: '<S371>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMAjarStaVHoodVld_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMAjarStaHood_flg' */
  /* Switch: '<S369>/Switch4' incorporates:
   *  Constant: '<S369>/sat3'
   */
  if (KOPM_BCMAjarStaHood_flg_ovrdflg)
  {
    /* Switch: '<S369>/Switch4' incorporates:
     *  Constant: '<S369>/sat4'
     */
    VOPM_BCMAjarStaHood_flg = KOPM_BCMAjarStaHood_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S369>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S369>/Data Type Conversion1'
     */
    VOPM_BCMAjarStaHood_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_AjarSta_Hood != 0);
  }

  /* End of Switch: '<S369>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMAjarStaHood_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMHzrdWrngLghtSwSig_flg' */
  /* Switch: '<S420>/Switch4' incorporates:
   *  Constant: '<S420>/sat3'
   */
  if (KOPM_BCMHzrdWrngLghtSwSig_flg_ovrdflg)
  {
    /* Switch: '<S420>/Switch4' incorporates:
     *  Constant: '<S420>/sat4'
     */
    VOPM_BCMHzrdWrngLghtSwSig_flg = KOPM_BCMHzrdWrngLghtSwSig_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S420>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S420>/Data Type Conversion1'
     */
    VOPM_BCMHzrdWrngLghtSwSig_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
             ->BCM_HazardWarningLightSwSig != 0);
  }

  /* End of Switch: '<S420>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMHzrdWrngLghtSwSig_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMFrntFogLiSwSig_flg' */
  /* Switch: '<S410>/Switch4' incorporates:
   *  Constant: '<S410>/sat3'
   */
  if (KOPM_BCMFrntFogLiSwSig_flg_ovrdflg)
  {
    /* Switch: '<S410>/Switch4' incorporates:
     *  Constant: '<S410>/sat4'
     */
    VOPM_BCMFrntFogLiSwSig_flg = KOPM_BCMFrntFogLiSwSig_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S410>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S410>/Data Type Conversion1'
     */
    VOPM_BCMFrntFogLiSwSig_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
             ->BCM_FrntFogLiSwSig != 0);
  }

  /* End of Switch: '<S410>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMFrntFogLiSwSig_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMRrFogLiSwSig_flg' */
  /* Switch: '<S457>/Switch4' incorporates:
   *  Constant: '<S457>/sat3'
   */
  if (KOPM_BCMRrFogLiSwSig_flg_ovrdflg)
  {
    /* Switch: '<S457>/Switch4' incorporates:
     *  Constant: '<S457>/sat4'
     */
    VOPM_BCMRrFogLiSwSig_flg = KOPM_BCMRrFogLiSwSig_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S457>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S457>/Data Type Conversion1'
     */
    VOPM_BCMRrFogLiSwSig_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
             ->BCM_RearFogLiSwSig != 0);
  }

  /* End of Switch: '<S457>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMRrFogLiSwSig_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMFlwrMeHmCtrlFb_enum' */
  /* Switch: '<S405>/Switch4' incorporates:
   *  Constant: '<S405>/sat3'
   */
  if (KOPM_BCMFlwrMeHmCtrlFb_enum_ovrdflg)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  Constant: '<S405>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     */
    VOPM_BCMIllmndSts_enum = KOPM_BCMFlwrMeHmCtrlFb_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S405>/Data Type Conversion1'
     */
    VOPM_BCMIllmndSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
            ->BCM_FlwrMeHmCtrlFb;
  }

  /* End of Switch: '<S405>/Switch4' */

  /* MinMax: '<S405>/MinMax' incorporates:
   *  Constant: '<S405>/sat6'
   */
  if (VOPM_BCMIllmndSts_enum > KOPM_BCMFlwrMeHmCtrlFbHi_enum)
  {
    /* MinMax: '<S363>/MinMax' */
    VOPM_BCMIllmndSts_enum = KOPM_BCMFlwrMeHmCtrlFbHi_enum;
  }

  /* End of MinMax: '<S405>/MinMax' */

  /* MinMax: '<S405>/MinMax1' incorporates:
   *  Constant: '<S405>/sat7'
   */
  if (VOPM_BCMIllmndSts_enum >= KOPM_BCMFlwrMeHmCtrlFbLo_enum)
  {
    /* MinMax: '<S405>/MinMax1' */
    VOPM_BCMFlwrMeHmCtrlFb_enum = VOPM_BCMIllmndSts_enum;
  }
  else
  {
    /* MinMax: '<S405>/MinMax1' */
    VOPM_BCMFlwrMeHmCtrlFb_enum = KOPM_BCMFlwrMeHmCtrlFbLo_enum;
  }

  /* End of MinMax: '<S405>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMFlwrMeHmCtrlFb_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMBassHornReq_enum' */
  /* Switch: '<S378>/Switch4' incorporates:
   *  Constant: '<S378>/sat3'
   */
  if (KOPM_BCMBassHornReq_enum_ovrdflg)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  Constant: '<S378>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     */
    VOPM_BCMIllmndSts_enum = KOPM_BCMBassHornReq_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S378>/Data Type Conversion1'
     */
    VOPM_BCMIllmndSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_BassHornReq;
  }

  /* End of Switch: '<S378>/Switch4' */

  /* MinMax: '<S378>/MinMax' incorporates:
   *  Constant: '<S378>/sat6'
   */
  if (VOPM_BCMIllmndSts_enum > KOPM_BCMBassHornReqHi_enum)
  {
    /* MinMax: '<S363>/MinMax' */
    VOPM_BCMIllmndSts_enum = KOPM_BCMBassHornReqHi_enum;
  }

  /* End of MinMax: '<S378>/MinMax' */

  /* MinMax: '<S378>/MinMax1' incorporates:
   *  Constant: '<S378>/sat7'
   */
  if (VOPM_BCMIllmndSts_enum >= KOPM_BCMBassHornReqLo_enum)
  {
    /* MinMax: '<S378>/MinMax1' */
    VOPM_BCMBassHornReq_enum = VOPM_BCMIllmndSts_enum;
  }
  else
  {
    /* MinMax: '<S378>/MinMax1' */
    VOPM_BCMBassHornReq_enum = KOPM_BCMBassHornReqLo_enum;
  }

  /* End of MinMax: '<S378>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMBassHornReq_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMAjarStaTrunk_flg' */
  /* Switch: '<S370>/Switch4' incorporates:
   *  Constant: '<S370>/sat3'
   */
  if (KOPM_BCMAjarStaTrunk_flg_ovrdflg)
  {
    /* Switch: '<S370>/Switch4' incorporates:
     *  Constant: '<S370>/sat4'
     */
    VOPM_BCMAjarStaTrunk_flg = KOPM_BCMAjarStaTrunk_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S370>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S370>/Data Type Conversion1'
     */
    VOPM_BCMAjarStaTrunk_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
             ->BCM_AjarSta_Trunk != 0);
  }

  /* End of Switch: '<S370>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMAjarStaTrunk_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMDoorAjarStaFL_flg' */
  /* Switch: '<S389>/Switch4' incorporates:
   *  Constant: '<S389>/sat3'
   */
  if (KOPM_BCMDoorAjarStaFL_flg_ovrdflg)
  {
    /* Switch: '<S389>/Switch4' incorporates:
     *  Constant: '<S389>/sat4'
     */
    VOPM_BCMDoorAjarStaFL_flg = KOPM_BCMDoorAjarStaFL_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S389>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S389>/Data Type Conversion1'
     */
    VOPM_BCMDoorAjarStaFL_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
             ->BCM_DoorAjarSta_FL != 0);
  }

  /* End of Switch: '<S389>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMDoorAjarStaFL_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMDoorAjarStaFR_flg' */
  /* Switch: '<S390>/Switch4' incorporates:
   *  Constant: '<S390>/sat3'
   */
  if (KOPM_BCMDoorAjarStaFR_flg_ovrdflg)
  {
    /* Switch: '<S390>/Switch4' incorporates:
     *  Constant: '<S390>/sat4'
     */
    VOPM_BCMDoorAjarStaFR_flg = KOPM_BCMDoorAjarStaFR_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S390>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S390>/Data Type Conversion1'
     */
    VOPM_BCMDoorAjarStaFR_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
             ->BCM_DoorAjarSta_FR != 0);
  }

  /* End of Switch: '<S390>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMDoorAjarStaFR_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMDoorAjarStaRL_flg' */
  /* Switch: '<S391>/Switch4' incorporates:
   *  Constant: '<S391>/sat3'
   */
  if (KOPM_BCMDoorAjarStaRL_flg_ovrdflg)
  {
    /* Switch: '<S391>/Switch4' incorporates:
     *  Constant: '<S391>/sat4'
     */
    VOPM_BCMDoorAjarStaRL_flg = KOPM_BCMDoorAjarStaRL_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S391>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S391>/Data Type Conversion1'
     */
    VOPM_BCMDoorAjarStaRL_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
             ->BCM_DoorAjarSta_RL != 0);
  }

  /* End of Switch: '<S391>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMDoorAjarStaRL_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMDoorAjarStaRR_flg' */
  /* Switch: '<S392>/Switch4' incorporates:
   *  Constant: '<S392>/sat3'
   */
  if (KOPM_BCMDoorAjarStaRR_flg_ovrdflg)
  {
    /* Switch: '<S392>/Switch4' incorporates:
     *  Constant: '<S392>/sat4'
     */
    VOPM_BCMDoorAjarStaRR_flg = KOPM_BCMDoorAjarStaRR_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S392>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S392>/Data Type Conversion1'
     */
    VOPM_BCMDoorAjarStaRR_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
             ->BCM_DoorAjarSta_RR != 0);
  }

  /* End of Switch: '<S392>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMDoorAjarStaRR_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMLckHornOnStFb_flg' */
  /* Switch: '<S436>/Switch4' incorporates:
   *  Constant: '<S436>/sat3'
   */
  if (KOPM_BCMLckHornOnStFb_flg_ovrdflg)
  {
    /* Switch: '<S436>/Switch4' incorporates:
     *  Constant: '<S436>/sat4'
     */
    VOPM_BCMLckHornOnStFb_flg = KOPM_BCMLckHornOnStFb_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S436>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S436>/Data Type Conversion1'
     */
    VOPM_BCMLckHornOnStFb_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
             ->BCM_LockHornOnStFb != 0);
  }

  /* End of Switch: '<S436>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMLckHornOnStFb_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMAlrmHornReq_flg' */
  /* Switch: '<S372>/Switch4' incorporates:
   *  Constant: '<S372>/sat3'
   */
  if (KOPM_BCMAlrmHornReq_flg_ovrdflg)
  {
    /* Switch: '<S372>/Switch4' incorporates:
     *  Constant: '<S372>/sat4'
     */
    VOPM_BCMAlrmHornReq_flg = KOPM_BCMAlrmHornReq_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S372>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S372>/Data Type Conversion1'
     */
    VOPM_BCMAlrmHornReq_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_AlrmHornReq != 0);
  }

  /* End of Switch: '<S372>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMAlrmHornReq_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_TPMSPressureStaFL_enum' */
  /* Switch: '<S487>/Switch4' incorporates:
   *  Constant: '<S487>/sat3'
   */
  if (KOPM_TPMSPressureStaFL_enum_ovrdflg)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  Constant: '<S487>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     */
    VOPM_BCMIllmndSts_enum = KOPM_TPMSPressureStaFL_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S487>/Data Type Conversion1'
     */
    VOPM_BCMIllmndSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Vcu2OpmBAC_outputs())
            ->VVSO_TPMSPrsrStaFL_enum;
  }

  /* End of Switch: '<S487>/Switch4' */

  /* MinMax: '<S487>/MinMax' incorporates:
   *  Constant: '<S487>/sat6'
   */
  if (VOPM_BCMIllmndSts_enum > KOPM_TPMSPressureStaFLHi_enum)
  {
    /* MinMax: '<S363>/MinMax' */
    VOPM_BCMIllmndSts_enum = KOPM_TPMSPressureStaFLHi_enum;
  }

  /* End of MinMax: '<S487>/MinMax' */

  /* MinMax: '<S487>/MinMax1' incorporates:
   *  Constant: '<S487>/sat7'
   */
  if (VOPM_BCMIllmndSts_enum >= KOPM_TPMSPressureStaFLLo_enum)
  {
    /* MinMax: '<S487>/MinMax1' */
    VOPM_TPMSPressureStaFL_enum = VOPM_BCMIllmndSts_enum;
  }
  else
  {
    /* MinMax: '<S487>/MinMax1' */
    VOPM_TPMSPressureStaFL_enum = KOPM_TPMSPressureStaFLLo_enum;
  }

  /* End of MinMax: '<S487>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_TPMSPressureStaFL_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_TPMSPressureStaFR_enum' */
  /* Switch: '<S488>/Switch4' incorporates:
   *  Constant: '<S488>/sat3'
   */
  if (KOPM_TPMSPressureStaFR_enum_ovrdflg)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  Constant: '<S488>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     */
    VOPM_BCMIllmndSts_enum = KOPM_TPMSPressureStaFR_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S488>/Data Type Conversion1'
     */
    VOPM_BCMIllmndSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Vcu2OpmBAC_outputs())
            ->VVSO_TPMSPrsrStaFR_enum;
  }

  /* End of Switch: '<S488>/Switch4' */

  /* MinMax: '<S488>/MinMax' incorporates:
   *  Constant: '<S488>/sat6'
   */
  if (VOPM_BCMIllmndSts_enum > KOPM_TPMSPressureStaFRHi_enum)
  {
    /* MinMax: '<S363>/MinMax' */
    VOPM_BCMIllmndSts_enum = KOPM_TPMSPressureStaFRHi_enum;
  }

  /* End of MinMax: '<S488>/MinMax' */

  /* MinMax: '<S488>/MinMax1' incorporates:
   *  Constant: '<S488>/sat7'
   */
  if (VOPM_BCMIllmndSts_enum >= KOPM_TPMSPressureStaFRLo_enum)
  {
    /* MinMax: '<S488>/MinMax1' */
    VOPM_TPMSPressureStaFR_enum = VOPM_BCMIllmndSts_enum;
  }
  else
  {
    /* MinMax: '<S488>/MinMax1' */
    VOPM_TPMSPressureStaFR_enum = KOPM_TPMSPressureStaFRLo_enum;
  }

  /* End of MinMax: '<S488>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_TPMSPressureStaFR_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMTPMSRstSts_enum' */
  /* Switch: '<S464>/Switch4' incorporates:
   *  Constant: '<S464>/sat3'
   */
  if (KOPM_BCMTPMSRstSts_enum_ovrdflg)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  Constant: '<S464>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     */
    VOPM_BCMIllmndSts_enum = KOPM_BCMTPMSRstSts_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S464>/Data Type Conversion1'
     */
    VOPM_BCMIllmndSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Vcu2OpmBAC_outputs())
            ->VVSO_BCMTPMSRstSts_enum;
  }

  /* End of Switch: '<S464>/Switch4' */

  /* MinMax: '<S464>/MinMax' incorporates:
   *  Constant: '<S464>/sat6'
   */
  if (VOPM_BCMIllmndSts_enum > KOPM_BCMTPMSRstStsHi_enum)
  {
    /* MinMax: '<S363>/MinMax' */
    VOPM_BCMIllmndSts_enum = KOPM_BCMTPMSRstStsHi_enum;
  }

  /* End of MinMax: '<S464>/MinMax' */

  /* MinMax: '<S464>/MinMax1' incorporates:
   *  Constant: '<S464>/sat7'
   */
  if (VOPM_BCMIllmndSts_enum >= KOPM_BCMTPMSRstStsLo_enum)
  {
    /* MinMax: '<S464>/MinMax1' */
    VOPM_BCMTPMSRstSts_enum = VOPM_BCMIllmndSts_enum;
  }
  else
  {
    /* MinMax: '<S464>/MinMax1' */
    VOPM_BCMTPMSRstSts_enum = KOPM_BCMTPMSRstStsLo_enum;
  }

  /* End of MinMax: '<S464>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMTPMSRstSts_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_TMPSAbnmPrsrWarn_flg' */
  /* Switch: '<S486>/Switch4' incorporates:
   *  Constant: '<S486>/sat3'
   */
  if (KOPM_TMPSAbnmPrsrWarn_flg_ovrdflg)
  {
    /* Switch: '<S486>/Switch4' incorporates:
     *  Constant: '<S486>/sat4'
     */
    VOPM_TMPSAbnmPrsrWarn_flg = KOPM_TMPSAbnmPrsrWarn_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S486>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S486>/Data Type Conversion1'
     */
    VOPM_TMPSAbnmPrsrWarn_flg =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Vcu2OpmBAC_outputs())
            ->VVSO_TMPSAbnmPrsrWarn_flg;
  }

  /* End of Switch: '<S486>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_TMPSAbnmPrsrWarn_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_TPMSPressureStaRL_enum' */
  /* Switch: '<S489>/Switch4' incorporates:
   *  Constant: '<S489>/sat3'
   */
  if (KOPM_TPMSPressureStaRL_enum_ovrdflg)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  Constant: '<S489>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     */
    VOPM_BCMIllmndSts_enum = KOPM_TPMSPressureStaRL_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S489>/Data Type Conversion1'
     */
    VOPM_BCMIllmndSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Vcu2OpmBAC_outputs())
            ->VVSO_TPMSPrsrStaRL_enum;
  }

  /* End of Switch: '<S489>/Switch4' */

  /* MinMax: '<S489>/MinMax' incorporates:
   *  Constant: '<S489>/sat6'
   */
  if (VOPM_BCMIllmndSts_enum > KOPM_TPMSPressureStaRLHi_enum)
  {
    /* MinMax: '<S363>/MinMax' */
    VOPM_BCMIllmndSts_enum = KOPM_TPMSPressureStaRLHi_enum;
  }

  /* End of MinMax: '<S489>/MinMax' */

  /* MinMax: '<S489>/MinMax1' incorporates:
   *  Constant: '<S489>/sat7'
   */
  if (VOPM_BCMIllmndSts_enum >= KOPM_TPMSPressureStaRLLo_enum)
  {
    /* MinMax: '<S489>/MinMax1' */
    VOPM_TPMSPressureStaRL_enum = VOPM_BCMIllmndSts_enum;
  }
  else
  {
    /* MinMax: '<S489>/MinMax1' */
    VOPM_TPMSPressureStaRL_enum = KOPM_TPMSPressureStaRLLo_enum;
  }

  /* End of MinMax: '<S489>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_TPMSPressureStaRL_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_TPMSPressureStaRR_enum' */
  /* Switch: '<S490>/Switch4' incorporates:
   *  Constant: '<S490>/sat3'
   */
  if (KOPM_TPMSPressureStaRR_enum_ovrdflg)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  Constant: '<S490>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     */
    VOPM_BCMIllmndSts_enum = KOPM_TPMSPressureStaRR_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S490>/Data Type Conversion1'
     */
    VOPM_BCMIllmndSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Vcu2OpmBAC_outputs())
            ->VVSO_TPMSPrsrStaRR_enum;
  }

  /* End of Switch: '<S490>/Switch4' */

  /* MinMax: '<S490>/MinMax' incorporates:
   *  Constant: '<S490>/sat6'
   */
  if (VOPM_BCMIllmndSts_enum > KOPM_TPMSPressureStaRRHi_enum)
  {
    /* MinMax: '<S363>/MinMax' */
    VOPM_BCMIllmndSts_enum = KOPM_TPMSPressureStaRRHi_enum;
  }

  /* End of MinMax: '<S490>/MinMax' */

  /* MinMax: '<S490>/MinMax1' incorporates:
   *  Constant: '<S490>/sat7'
   */
  if (VOPM_BCMIllmndSts_enum >= KOPM_TPMSPressureStaRRLo_enum)
  {
    /* MinMax: '<S490>/MinMax1' */
    VOPM_TPMSPressureStaRR_enum = VOPM_BCMIllmndSts_enum;
  }
  else
  {
    /* MinMax: '<S490>/MinMax1' */
    VOPM_TPMSPressureStaRR_enum = KOPM_TPMSPressureStaRRLo_enum;
  }

  /* End of MinMax: '<S490>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_TPMSPressureStaRR_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMWiperCtrlFront_enum' */
  /* Switch: '<S478>/Switch4' incorporates:
   *  Constant: '<S478>/sat3'
   */
  if (KOPM_BCMWiperCtrlFront_enum_ovrdflg)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  Constant: '<S478>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     */
    VOPM_BCMIllmndSts_enum = KOPM_BCMWiperCtrlFront_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S478>/Data Type Conversion1'
     */
    VOPM_BCMIllmndSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
            ->BCM_WiperCtrl_Front;
  }

  /* End of Switch: '<S478>/Switch4' */

  /* MinMax: '<S478>/MinMax' incorporates:
   *  Constant: '<S478>/sat6'
   */
  if (VOPM_BCMIllmndSts_enum > KOPM_BCMWiperCtrlFrontHi_enum)
  {
    /* MinMax: '<S363>/MinMax' */
    VOPM_BCMIllmndSts_enum = KOPM_BCMWiperCtrlFrontHi_enum;
  }

  /* End of MinMax: '<S478>/MinMax' */

  /* MinMax: '<S478>/MinMax1' incorporates:
   *  Constant: '<S478>/sat7'
   */
  if (VOPM_BCMIllmndSts_enum >= KOPM_BCMWiperCtrlFrontLo_enum)
  {
    /* MinMax: '<S478>/MinMax1' */
    VOPM_BCMWiperCtrlFront_enum = VOPM_BCMIllmndSts_enum;
  }
  else
  {
    /* MinMax: '<S478>/MinMax1' */
    VOPM_BCMWiperCtrlFront_enum = KOPM_BCMWiperCtrlFrontLo_enum;
  }

  /* End of MinMax: '<S478>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMWiperCtrlFront_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMWashLiquidLvlWarn_flg' */
  /* Switch: '<S475>/Switch4' incorporates:
   *  Constant: '<S475>/sat3'
   */
  if (KOPM_BCMWashLiquidLvlWarn_flg_ovrdflg)
  {
    /* Switch: '<S475>/Switch4' incorporates:
     *  Constant: '<S475>/sat4'
     */
    VOPM_BCMWashLiquidLvlWarn_flg = KOPM_BCMWashLiquidLvlWarn_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S475>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S475>/Data Type Conversion1'
     */
    VOPM_BCMWashLiquidLvlWarn_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
             ->BCM_WashLiquidLevelWarn != 0);
  }

  /* End of Switch: '<S475>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMWashLiquidLvlWarn_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMDrvSeatOccptSnsrSts_enum' */
  /* Switch: '<S396>/Switch4' incorporates:
   *  Constant: '<S396>/sat3'
   */
  if (KOPM_BCMDrvSeatOccptSnsrSts_enum_ovrdflg)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  Constant: '<S396>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     */
    VOPM_BCMIllmndSts_enum = KOPM_BCMDrvSeatOccptSnsrSts_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S396>/Data Type Conversion1'
     */
    VOPM_BCMIllmndSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
            ->BCM_DrvSeatOccupantSensorSts;
  }

  /* End of Switch: '<S396>/Switch4' */

  /* MinMax: '<S396>/MinMax' incorporates:
   *  Constant: '<S396>/sat6'
   */
  if (VOPM_BCMIllmndSts_enum > KOPM_BCMDrvSeatOccptSnsrStsHi_enum)
  {
    /* MinMax: '<S363>/MinMax' */
    VOPM_BCMIllmndSts_enum = KOPM_BCMDrvSeatOccptSnsrStsHi_enum;
  }

  /* End of MinMax: '<S396>/MinMax' */

  /* MinMax: '<S396>/MinMax1' incorporates:
   *  Constant: '<S396>/sat7'
   */
  if (VOPM_BCMIllmndSts_enum >= KOPM_BCMDrvSeatOccptSnsrStsLo_enum)
  {
    /* MinMax: '<S396>/MinMax1' */
    VOPM_BCMDrvSeatOccptSnsrSts_enum = VOPM_BCMIllmndSts_enum;
  }
  else
  {
    /* MinMax: '<S396>/MinMax1' */
    VOPM_BCMDrvSeatOccptSnsrSts_enum = KOPM_BCMDrvSeatOccptSnsrStsLo_enum;
  }

  /* End of MinMax: '<S396>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMDrvSeatOccptSnsrSts_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMHvyRainInd_flg' */
  /* Switch: '<S419>/Switch4' incorporates:
   *  Constant: '<S419>/sat3'
   *  Constant: '<S419>/sat4'
   */
  VOPM_BCMHvyRainInd_flg = (KOPM_BCMHvyRainInd_flg_ovrdflg &&
                            KOPM_BCMHvyRainInd_flg_ovrdval);

  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMHvyRainInd_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMFrntWshrSwSig_flg' */
  /* Switch: '<S414>/Switch4' incorporates:
   *  Constant: '<S414>/sat3'
   */
  if (KOPM_BCMFrntWshrSwSig_flg_ovrdflg)
  {
    /* Switch: '<S414>/Switch4' incorporates:
     *  Constant: '<S414>/sat4'
     */
    VOPM_BCMFrntWshrSwSig_flg = KOPM_BCMFrntWshrSwSig_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S414>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S414>/Data Type Conversion1'
     */
    VOPM_BCMFrntWshrSwSig_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
             ->BCM_FrntWshrSwSig != 0);
  }

  /* End of Switch: '<S414>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMFrntWshrSwSig_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMPaswdwInit_flg' */
  /* Switch: '<S450>/Switch4' incorporates:
   *  Constant: '<S450>/sat3'
   *  Constant: '<S450>/sat4'
   */
  VOPM_BCMPaswdwInit_flg = (KOPM_BCMPaswdwInit_flg_ovrdflg &&
                            KOPM_BCMPaswdwInit_flg_ovrdval);

  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMPaswdwInit_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMFrontWashSts_flg' */
  /* Switch: '<S415>/Switch4' incorporates:
   *  Constant: '<S415>/sat3'
   */
  if (KOPM_BCMFrontWashSts_flg_ovrdflg)
  {
    /* Switch: '<S415>/Switch4' incorporates:
     *  Constant: '<S415>/sat4'
     */
    VOPM_BCMFrontWashSts_flg = KOPM_BCMFrontWashSts_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S415>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S415>/Data Type Conversion1'
     */
    VOPM_BCMFrontWashSts_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_FrontWashSts != 0);
  }

  /* End of Switch: '<S415>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMFrontWashSts_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMWiprIntlGrSwtSig_enum' */
  /* Switch: '<S480>/Switch4' incorporates:
   *  Constant: '<S480>/sat3'
   */
  if (KOPM_BCMWiprIntlGrSwtSig_enum_ovrdflg)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  Constant: '<S480>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     */
    VOPM_BCMIllmndSts_enum = KOPM_BCMWiprIntlGrSwtSig_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S480>/Data Type Conversion1'
     */
    VOPM_BCMIllmndSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
            ->BCM_WiprIntlGearSwtSig;
  }

  /* End of Switch: '<S480>/Switch4' */

  /* MinMax: '<S480>/MinMax' incorporates:
   *  Constant: '<S480>/sat6'
   */
  if (VOPM_BCMIllmndSts_enum > KOPM_BCMWiprIntlGrSwtSigHi_enum)
  {
    /* MinMax: '<S363>/MinMax' */
    VOPM_BCMIllmndSts_enum = KOPM_BCMWiprIntlGrSwtSigHi_enum;
  }

  /* End of MinMax: '<S480>/MinMax' */

  /* MinMax: '<S480>/MinMax1' incorporates:
   *  Constant: '<S480>/sat7'
   */
  if (VOPM_BCMIllmndSts_enum >= KOPM_BCMWiprIntlGrSwtSigLo_enum)
  {
    /* MinMax: '<S480>/MinMax1' */
    VOPM_BCMWiprIntlGrSwtSig_enum = VOPM_BCMIllmndSts_enum;
  }
  else
  {
    /* MinMax: '<S480>/MinMax1' */
    VOPM_BCMWiprIntlGrSwtSig_enum = KOPM_BCMWiprIntlGrSwtSigLo_enum;
  }

  /* End of MinMax: '<S480>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMWiprIntlGrSwtSig_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMWiperSwSig_enum' */
  /* Switch: '<S479>/Switch4' incorporates:
   *  Constant: '<S479>/sat3'
   */
  if (KOPM_BCMWiperSwSig_enum_ovrdflg)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  Constant: '<S479>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     */
    VOPM_BCMIllmndSts_enum = KOPM_BCMWiperSwSig_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S479>/Data Type Conversion1'
     */
    VOPM_BCMIllmndSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_WiperSwSig;
  }

  /* End of Switch: '<S479>/Switch4' */

  /* MinMax: '<S479>/MinMax' incorporates:
   *  Constant: '<S479>/sat6'
   */
  if (VOPM_BCMIllmndSts_enum > KOPM_BCMWiperSwSigHi_enum)
  {
    /* MinMax: '<S363>/MinMax' */
    VOPM_BCMIllmndSts_enum = KOPM_BCMWiperSwSigHi_enum;
  }

  /* End of MinMax: '<S479>/MinMax' */

  /* MinMax: '<S479>/MinMax1' incorporates:
   *  Constant: '<S479>/sat7'
   */
  if (VOPM_BCMIllmndSts_enum >= KOPM_BCMWiperSwSigLo_enum)
  {
    /* MinMax: '<S479>/MinMax1' */
    VOPM_BCMWiperSwSig_enum = VOPM_BCMIllmndSts_enum;
  }
  else
  {
    /* MinMax: '<S479>/MinMax1' */
    VOPM_BCMWiperSwSig_enum = KOPM_BCMWiperSwSigLo_enum;
  }

  /* End of MinMax: '<S479>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMWiperSwSig_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMWinLockSts_flg' */
  /* Switch: '<S477>/Switch4' incorporates:
   *  Constant: '<S477>/sat3'
   */
  if (KOPM_BCMWinLockSts_flg_ovrdflg)
  {
    /* Switch: '<S477>/Switch4' incorporates:
     *  Constant: '<S477>/sat4'
     */
    VOPM_BCMWinLockSts_flg = KOPM_BCMWinLockSts_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S477>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S477>/Data Type Conversion1'
     */
    VOPM_BCMWinLockSts_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_WinLockSts != 0);
  }

  /* End of Switch: '<S477>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMWinLockSts_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMWinLockSig_flg' */
  /* Switch: '<S476>/Switch4' incorporates:
   *  Constant: '<S476>/sat3'
   */
  if (KOPM_BCMWinLockSig_flg_ovrdflg)
  {
    /* Switch: '<S476>/Switch4' incorporates:
     *  Constant: '<S476>/sat4'
     */
    VOPM_BCMWinLockSig_flg = KOPM_BCMWinLockSig_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S476>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S476>/Data Type Conversion1'
     */
    VOPM_BCMWinLockSig_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_WinLockSig != 0);
  }

  /* End of Switch: '<S476>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMWinLockSig_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMDrvrWinSwSig_enum' */
  /* Switch: '<S397>/Switch4' incorporates:
   *  Constant: '<S397>/sat3'
   */
  if (KOPM_BCMDrvrWinSwSig_enum_ovrdflg)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  Constant: '<S397>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     */
    VOPM_BCMIllmndSts_enum = KOPM_BCMDrvrWinSwSig_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S397>/Data Type Conversion1'
     */
    VOPM_BCMIllmndSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
            ->BCM_DriverWinSwSig;
  }

  /* End of Switch: '<S397>/Switch4' */

  /* MinMax: '<S397>/MinMax' incorporates:
   *  Constant: '<S397>/sat6'
   */
  if (VOPM_BCMIllmndSts_enum > KOPM_BCMDrvrWinSwSigHi_enum)
  {
    /* MinMax: '<S363>/MinMax' */
    VOPM_BCMIllmndSts_enum = KOPM_BCMDrvrWinSwSigHi_enum;
  }

  /* End of MinMax: '<S397>/MinMax' */

  /* MinMax: '<S397>/MinMax1' incorporates:
   *  Constant: '<S397>/sat7'
   */
  if (VOPM_BCMIllmndSts_enum >= KOPM_BCMDrvrWinSwSigLo_enum)
  {
    /* MinMax: '<S397>/MinMax1' */
    VOPM_BCMDrvrWinSwSig_enum = VOPM_BCMIllmndSts_enum;
  }
  else
  {
    /* MinMax: '<S397>/MinMax1' */
    VOPM_BCMDrvrWinSwSig_enum = KOPM_BCMDrvrWinSwSigLo_enum;
  }

  /* End of MinMax: '<S397>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMDrvrWinSwSig_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMPassWinSwSig_enum' */
  /* Switch: '<S449>/Switch4' incorporates:
   *  Constant: '<S449>/sat3'
   */
  if (KOPM_BCMPassWinSwSig_enum_ovrdflg)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  Constant: '<S449>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     */
    VOPM_BCMIllmndSts_enum = KOPM_BCMPassWinSwSig_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S449>/Data Type Conversion1'
     */
    VOPM_BCMIllmndSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_PassWinSwSig;
  }

  /* End of Switch: '<S449>/Switch4' */

  /* MinMax: '<S449>/MinMax' incorporates:
   *  Constant: '<S449>/sat6'
   */
  if (VOPM_BCMIllmndSts_enum > KOPM_BCMPassWinSwSigHi_enum)
  {
    /* MinMax: '<S363>/MinMax' */
    VOPM_BCMIllmndSts_enum = KOPM_BCMPassWinSwSigHi_enum;
  }

  /* End of MinMax: '<S449>/MinMax' */

  /* MinMax: '<S449>/MinMax1' incorporates:
   *  Constant: '<S449>/sat7'
   */
  if (VOPM_BCMIllmndSts_enum >= KOPM_BCMPassWinSwSigLo_enum)
  {
    /* MinMax: '<S449>/MinMax1' */
    VOPM_BCMPassWinSwSig_enum = VOPM_BCMIllmndSts_enum;
  }
  else
  {
    /* MinMax: '<S449>/MinMax1' */
    VOPM_BCMPassWinSwSig_enum = KOPM_BCMPassWinSwSigLo_enum;
  }

  /* End of MinMax: '<S449>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMPassWinSwSig_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMFLWinSts_flg' */
  /* Switch: '<S398>/Switch4' incorporates:
   *  Constant: '<S398>/sat3'
   */
  if (KOPM_BCMFLWinSts_flg_ovrdflg)
  {
    /* Switch: '<S398>/Switch4' incorporates:
     *  Constant: '<S398>/sat4'
     */
    VOPM_BCMFLWinSts_flg = KOPM_BCMFLWinSts_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S398>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S398>/Data Type Conversion1'
     */
    VOPM_BCMFLWinSts_flg = ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_FLWindowSts != 0);
  }

  /* End of Switch: '<S398>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMFLWinSts_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMFRWinSts_flg' */
  /* Switch: '<S402>/Switch4' incorporates:
   *  Constant: '<S402>/sat3'
   */
  if (KOPM_BCMFRWinSts_flg_ovrdflg)
  {
    /* Switch: '<S402>/Switch4' incorporates:
     *  Constant: '<S402>/sat4'
     */
    VOPM_BCMFRWinSts_flg = KOPM_BCMFRWinSts_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S402>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S402>/Data Type Conversion1'
     */
    VOPM_BCMFRWinSts_flg = ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_FRWindowSts != 0);
  }

  /* End of Switch: '<S402>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMFRWinSts_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMFLWinmotorSts_enum' */
  /* Switch: '<S399>/Switch4' incorporates:
   *  Constant: '<S399>/sat3'
   */
  if (KOPM_BCMFLWinmotorSts_enum_ovrdflg)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  Constant: '<S399>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     */
    VOPM_BCMIllmndSts_enum = KOPM_BCMFLWinmotorSts_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S399>/Data Type Conversion1'
     */
    VOPM_BCMIllmndSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
            ->BCM_FLWindowmotorSts;
  }

  /* End of Switch: '<S399>/Switch4' */

  /* MinMax: '<S399>/MinMax' incorporates:
   *  Constant: '<S399>/sat6'
   */
  if (VOPM_BCMIllmndSts_enum > KOPM_BCMFLWinmotorStsHi_enum)
  {
    /* MinMax: '<S363>/MinMax' */
    VOPM_BCMIllmndSts_enum = KOPM_BCMFLWinmotorStsHi_enum;
  }

  /* End of MinMax: '<S399>/MinMax' */

  /* MinMax: '<S399>/MinMax1' incorporates:
   *  Constant: '<S399>/sat7'
   */
  if (VOPM_BCMIllmndSts_enum >= KOPM_BCMFLWinmotorStsLo_enum)
  {
    /* MinMax: '<S399>/MinMax1' */
    VOPM_BCMFLWinmotorSts_enum = VOPM_BCMIllmndSts_enum;
  }
  else
  {
    /* MinMax: '<S399>/MinMax1' */
    VOPM_BCMFLWinmotorSts_enum = KOPM_BCMFLWinmotorStsLo_enum;
  }

  /* End of MinMax: '<S399>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMFLWinmotorSts_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMFRWinmotorSts_enum' */
  /* Switch: '<S403>/Switch4' incorporates:
   *  Constant: '<S403>/sat3'
   */
  if (KOPM_BCMFRWinmotorSts_enum_ovrdflg)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  Constant: '<S403>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     */
    VOPM_BCMIllmndSts_enum = KOPM_BCMFRWinmotorSts_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S403>/Data Type Conversion1'
     */
    VOPM_BCMIllmndSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
            ->BCM_FRWindowmotorSts;
  }

  /* End of Switch: '<S403>/Switch4' */

  /* MinMax: '<S403>/MinMax' incorporates:
   *  Constant: '<S403>/sat6'
   */
  if (VOPM_BCMIllmndSts_enum > KOPM_BCMFRWinmotorStsHi_enum)
  {
    /* MinMax: '<S363>/MinMax' */
    VOPM_BCMIllmndSts_enum = KOPM_BCMFRWinmotorStsHi_enum;
  }

  /* End of MinMax: '<S403>/MinMax' */

  /* MinMax: '<S403>/MinMax1' incorporates:
   *  Constant: '<S403>/sat7'
   */
  if (VOPM_BCMIllmndSts_enum >= KOPM_BCMFRWinmotorStsLo_enum)
  {
    /* MinMax: '<S403>/MinMax1' */
    VOPM_BCMFRWinmotorSts_enum = VOPM_BCMIllmndSts_enum;
  }
  else
  {
    /* MinMax: '<S403>/MinMax1' */
    VOPM_BCMFRWinmotorSts_enum = KOPM_BCMFRWinmotorStsLo_enum;
  }

  /* End of MinMax: '<S403>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMFRWinmotorSts_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMFrntLeDoorHndlSwt_enum' */
  /* Switch: '<S411>/Switch4' incorporates:
   *  Constant: '<S411>/sat3'
   */
  if (KOPM_BCMFrntLeDoorHndlSwt_enum_ovrdflg)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  Constant: '<S411>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     */
    VOPM_BCMIllmndSts_enum = KOPM_BCMFrntLeDoorHndlSwt_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S411>/Data Type Conversion1'
     */
    VOPM_BCMIllmndSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
            ->BCM_FrntLeDoorHndlSwt;
  }

  /* End of Switch: '<S411>/Switch4' */

  /* MinMax: '<S411>/MinMax' incorporates:
   *  Constant: '<S411>/sat6'
   */
  if (VOPM_BCMIllmndSts_enum > KOPM_BCMFrntLeDoorHndlSwtHi_enum)
  {
    /* MinMax: '<S363>/MinMax' */
    VOPM_BCMIllmndSts_enum = KOPM_BCMFrntLeDoorHndlSwtHi_enum;
  }

  /* End of MinMax: '<S411>/MinMax' */

  /* MinMax: '<S411>/MinMax1' incorporates:
   *  Constant: '<S411>/sat7'
   */
  if (VOPM_BCMIllmndSts_enum >= KOPM_BCMFrntLeDoorHndlSwtLo_enum)
  {
    /* MinMax: '<S411>/MinMax1' */
    VOPM_BCMFrntLeDoorHndlSwt_enum = VOPM_BCMIllmndSts_enum;
  }
  else
  {
    /* MinMax: '<S411>/MinMax1' */
    VOPM_BCMFrntLeDoorHndlSwt_enum = KOPM_BCMFrntLeDoorHndlSwtLo_enum;
  }

  /* End of MinMax: '<S411>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMFrntLeDoorHndlSwt_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMFrntRiDoorHndlSwt_enum' */
  /* Switch: '<S412>/Switch4' incorporates:
   *  Constant: '<S412>/sat3'
   */
  if (KOPM_BCMFrntRiDoorHndlSwt_enum_ovrdflg)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  Constant: '<S412>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     */
    VOPM_BCMIllmndSts_enum = KOPM_BCMFrntRiDoorHndlSwt_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S412>/Data Type Conversion1'
     */
    VOPM_BCMIllmndSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
            ->BCM_FrntRiDoorHndlSwt;
  }

  /* End of Switch: '<S412>/Switch4' */

  /* MinMax: '<S412>/MinMax' incorporates:
   *  Constant: '<S412>/sat6'
   */
  if (VOPM_BCMIllmndSts_enum > KOPM_BCMFrntRiDoorHndlSwtHi_enum)
  {
    /* MinMax: '<S363>/MinMax' */
    VOPM_BCMIllmndSts_enum = KOPM_BCMFrntRiDoorHndlSwtHi_enum;
  }

  /* End of MinMax: '<S412>/MinMax' */

  /* MinMax: '<S412>/MinMax1' incorporates:
   *  Constant: '<S412>/sat7'
   */
  if (VOPM_BCMIllmndSts_enum >= KOPM_BCMFrntRiDoorHndlSwtLo_enum)
  {
    /* MinMax: '<S412>/MinMax1' */
    VOPM_BCMFrntRiDoorHndlSwt_enum = VOPM_BCMIllmndSts_enum;
  }
  else
  {
    /* MinMax: '<S412>/MinMax1' */
    VOPM_BCMFrntRiDoorHndlSwt_enum = KOPM_BCMFrntRiDoorHndlSwtLo_enum;
  }

  /* End of MinMax: '<S412>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMFrntRiDoorHndlSwt_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMTrunkSwtSig_flg' */
  /* Switch: '<S468>/Switch4' incorporates:
   *  Constant: '<S468>/sat3'
   */
  if (KOPM_BCMTrunkSwtSig_flg_ovrdflg)
  {
    /* Switch: '<S468>/Switch4' incorporates:
     *  Constant: '<S468>/sat4'
     */
    VOPM_BCMTrunkSwtSig_flg = KOPM_BCMTrunkSwtSig_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S468>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S468>/Data Type Conversion1'
     */
    VOPM_BCMTrunkSwtSig_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_TrunkSwtSig != 0);
  }

  /* End of Switch: '<S468>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMTrunkSwtSig_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMWarnNoKeyFound_flg' */
  /* Switch: '<S474>/Switch4' incorporates:
   *  Constant: '<S474>/sat3'
   */
  if (KOPM_BCMWarnNoKeyFound_flg_ovrdflg)
  {
    /* Switch: '<S474>/Switch4' incorporates:
     *  Constant: '<S474>/sat4'
     */
    VOPM_BCMWarnNoKeyFound_flg = KOPM_BCMWarnNoKeyFound_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S474>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S474>/Data Type Conversion1'
     */
    VOPM_BCMWarnNoKeyFound_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
             ->BCM_WarnNoKeyFound != 0);
  }

  /* End of Switch: '<S474>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMWarnNoKeyFound_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMBodyWarnSts_enum' */
  /* Switch: '<S379>/Switch4' incorporates:
   *  Constant: '<S379>/sat3'
   */
  if (KOPM_BCMBodyWarnSts_enum_ovrdflg)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  Constant: '<S379>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     */
    VOPM_BCMIllmndSts_enum = KOPM_BCMBodyWarnSts_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S379>/Data Type Conversion1'
     */
    VOPM_BCMIllmndSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_BodyWarnSts;
  }

  /* End of Switch: '<S379>/Switch4' */

  /* MinMax: '<S379>/MinMax' incorporates:
   *  Constant: '<S379>/sat6'
   */
  if (VOPM_BCMIllmndSts_enum > KOPM_BCMBodyWarnStsHi_enum)
  {
    /* MinMax: '<S363>/MinMax' */
    VOPM_BCMIllmndSts_enum = KOPM_BCMBodyWarnStsHi_enum;
  }

  /* End of MinMax: '<S379>/MinMax' */

  /* MinMax: '<S379>/MinMax1' incorporates:
   *  Constant: '<S379>/sat7'
   */
  if (VOPM_BCMIllmndSts_enum >= KOPM_BCMBodyWarnStsLo_enum)
  {
    /* MinMax: '<S379>/MinMax1' */
    VOPM_BCMBodyWarnSts_enum = VOPM_BCMIllmndSts_enum;
  }
  else
  {
    /* MinMax: '<S379>/MinMax1' */
    VOPM_BCMBodyWarnSts_enum = KOPM_BCMBodyWarnStsLo_enum;
  }

  /* End of MinMax: '<S379>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMBodyWarnSts_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMPSAuthentRes_enum' */
  /* Switch: '<S446>/Switch4' incorporates:
   *  Constant: '<S446>/sat3'
   */
  if (KOPM_BCMPSAuthentRes_enum_ovrdflg)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  Constant: '<S446>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     */
    VOPM_BCMIllmndSts_enum = KOPM_BCMPSAuthentRes_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S446>/Data Type Conversion1'
     */
    VOPM_BCMIllmndSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_PSAuthentRes;
  }

  /* End of Switch: '<S446>/Switch4' */

  /* MinMax: '<S446>/MinMax' incorporates:
   *  Constant: '<S446>/sat6'
   */
  if (VOPM_BCMIllmndSts_enum > KOPM_BCMPSAuthentResHi_enum)
  {
    /* MinMax: '<S363>/MinMax' */
    VOPM_BCMIllmndSts_enum = KOPM_BCMPSAuthentResHi_enum;
  }

  /* End of MinMax: '<S446>/MinMax' */

  /* MinMax: '<S446>/MinMax1' incorporates:
   *  Constant: '<S446>/sat7'
   */
  if (VOPM_BCMIllmndSts_enum >= KOPM_BCMPSAuthentResLo_enum)
  {
    /* MinMax: '<S446>/MinMax1' */
    VOPM_BCMPSAuthentRes_enum = VOPM_BCMIllmndSts_enum;
  }
  else
  {
    /* MinMax: '<S446>/MinMax1' */
    VOPM_BCMPSAuthentRes_enum = KOPM_BCMPSAuthentResLo_enum;
  }

  /* End of MinMax: '<S446>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMPSAuthentRes_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMChrgLidLockReq_enum' */
  /* Switch: '<S384>/Switch4' incorporates:
   *  Constant: '<S384>/sat3'
   */
  if (KOPM_BCMChrgLidLockReq_enum_ovrdflg)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  Constant: '<S384>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     */
    VOPM_BCMIllmndSts_enum = KOPM_BCMChrgLidLockReq_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S384>/Data Type Conversion1'
     */
    VOPM_BCMIllmndSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
            ->BCM_ChrgLidLockReq;
  }

  /* End of Switch: '<S384>/Switch4' */

  /* MinMax: '<S384>/MinMax' incorporates:
   *  Constant: '<S384>/sat6'
   */
  if (VOPM_BCMIllmndSts_enum > KOPM_BCMChrgLidLockReqHi_enum)
  {
    /* MinMax: '<S363>/MinMax' */
    VOPM_BCMIllmndSts_enum = KOPM_BCMChrgLidLockReqHi_enum;
  }

  /* End of MinMax: '<S384>/MinMax' */

  /* MinMax: '<S384>/MinMax1' incorporates:
   *  Constant: '<S384>/sat7'
   */
  if (VOPM_BCMIllmndSts_enum >= KOPM_BCMChrgLidLockReqLo_enum)
  {
    /* MinMax: '<S384>/MinMax1' */
    VOPM_BCMChrgLidLockReq_enum = VOPM_BCMIllmndSts_enum;
  }
  else
  {
    /* MinMax: '<S384>/MinMax1' */
    VOPM_BCMChrgLidLockReq_enum = KOPM_BCMChrgLidLockReqLo_enum;
  }

  /* End of MinMax: '<S384>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMChrgLidLockReq_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMRKEReq_enum' */
  /* Switch: '<S453>/Switch4' incorporates:
   *  Constant: '<S453>/sat3'
   */
  if (KOPM_BCMRKEReq_enum_ovrdflg)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  Constant: '<S453>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     */
    VOPM_BCMIllmndSts_enum = KOPM_BCMRKEReq_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S453>/Data Type Conversion1'
     */
    VOPM_BCMIllmndSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_RKEReq;
  }

  /* End of Switch: '<S453>/Switch4' */

  /* MinMax: '<S453>/MinMax' incorporates:
   *  Constant: '<S453>/sat6'
   */
  if (VOPM_BCMIllmndSts_enum > KOPM_BCMRKEReqHi_enum)
  {
    /* MinMax: '<S363>/MinMax' */
    VOPM_BCMIllmndSts_enum = KOPM_BCMRKEReqHi_enum;
  }

  /* End of MinMax: '<S453>/MinMax' */

  /* MinMax: '<S453>/MinMax1' incorporates:
   *  Constant: '<S453>/sat7'
   */
  if (VOPM_BCMIllmndSts_enum >= KOPM_BCMRKEReqLo_enum)
  {
    /* MinMax: '<S453>/MinMax1' */
    VOPM_BCMRKEReq_enum = VOPM_BCMIllmndSts_enum;
  }
  else
  {
    /* MinMax: '<S453>/MinMax1' */
    VOPM_BCMRKEReq_enum = KOPM_BCMRKEReqLo_enum;
  }

  /* End of MinMax: '<S453>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMRKEReq_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMKeyInCarSta_flg' */
  /* Switch: '<S431>/Switch4' incorporates:
   *  Constant: '<S431>/sat3'
   */
  if (KOPM_BCMKeyInCarSta_flg_ovrdflg)
  {
    /* Switch: '<S431>/Switch4' incorporates:
     *  Constant: '<S431>/sat4'
     */
    VOPM_BCMKeyInCarSta_flg = KOPM_BCMKeyInCarSta_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S431>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S431>/Data Type Conversion1'
     */
    VOPM_BCMKeyInCarSta_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_KeyInCarSta != 0);
  }

  /* End of Switch: '<S431>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMKeyInCarSta_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMDrvPEAuthentAcsd_enum' */
  /* Switch: '<S394>/Switch4' incorporates:
   *  Constant: '<S394>/sat3'
   */
  if (KOPM_BCMDrvPEAuthentAcsd_enum_ovrdflg)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  Constant: '<S394>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     */
    VOPM_BCMIllmndSts_enum = KOPM_BCMDrvPEAuthentAcsd_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S394>/Data Type Conversion1'
     */
    VOPM_BCMIllmndSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
            ->BCM_DrvPEAuthentAcsd;
  }

  /* End of Switch: '<S394>/Switch4' */

  /* MinMax: '<S394>/MinMax' incorporates:
   *  Constant: '<S394>/sat6'
   */
  if (VOPM_BCMIllmndSts_enum > KOPM_BCMDrvPEAuthentAcsdHi_enum)
  {
    /* MinMax: '<S363>/MinMax' */
    VOPM_BCMIllmndSts_enum = KOPM_BCMDrvPEAuthentAcsdHi_enum;
  }

  /* End of MinMax: '<S394>/MinMax' */

  /* MinMax: '<S394>/MinMax1' incorporates:
   *  Constant: '<S394>/sat7'
   */
  if (VOPM_BCMIllmndSts_enum >= KOPM_BCMDrvPEAuthentAcsdLo_enum)
  {
    /* MinMax: '<S394>/MinMax1' */
    VOPM_BCMDrvPEAuthentAcsd_enum = VOPM_BCMIllmndSts_enum;
  }
  else
  {
    /* MinMax: '<S394>/MinMax1' */
    VOPM_BCMDrvPEAuthentAcsd_enum = KOPM_BCMDrvPEAuthentAcsdLo_enum;
  }

  /* End of MinMax: '<S394>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMDrvPEAuthentAcsd_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMFRPEAuthentAcsd_enum' */
  /* Switch: '<S401>/Switch4' incorporates:
   *  Constant: '<S401>/sat3'
   */
  if (KOPM_BCMFRPEAuthentAcsd_enum_ovrdflg)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  Constant: '<S401>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     */
    VOPM_BCMIllmndSts_enum = KOPM_BCMFRPEAuthentAcsd_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S401>/Data Type Conversion1'
     */
    VOPM_BCMIllmndSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
            ->BCM_FRPEAuthentAcsd;
  }

  /* End of Switch: '<S401>/Switch4' */

  /* MinMax: '<S401>/MinMax' incorporates:
   *  Constant: '<S401>/sat6'
   */
  if (VOPM_BCMIllmndSts_enum > KOPM_BCMFRPEAuthentAcsdHi_enum)
  {
    /* MinMax: '<S363>/MinMax' */
    VOPM_BCMIllmndSts_enum = KOPM_BCMFRPEAuthentAcsdHi_enum;
  }

  /* End of MinMax: '<S401>/MinMax' */

  /* MinMax: '<S401>/MinMax1' incorporates:
   *  Constant: '<S401>/sat7'
   */
  if (VOPM_BCMIllmndSts_enum >= KOPM_BCMFRPEAuthentAcsdLo_enum)
  {
    /* MinMax: '<S401>/MinMax1' */
    VOPM_BCMFRPEAuthentAcsd_enum = VOPM_BCMIllmndSts_enum;
  }
  else
  {
    /* MinMax: '<S401>/MinMax1' */
    VOPM_BCMFRPEAuthentAcsd_enum = KOPM_BCMFRPEAuthentAcsdLo_enum;
  }

  /* End of MinMax: '<S401>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMFRPEAuthentAcsd_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMPSReq_flg' */
  /* Switch: '<S447>/Switch4' incorporates:
   *  Constant: '<S447>/sat3'
   */
  if (KOPM_BCMPSReq_flg_ovrdflg)
  {
    /* Switch: '<S447>/Switch4' incorporates:
     *  Constant: '<S447>/sat4'
     */
    VOPM_BCMPSReq_flg = KOPM_BCMPSReq_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S447>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S447>/Data Type Conversion1'
     */
    VOPM_BCMPSReq_flg = ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_PSReq != 0);
  }

  /* End of Switch: '<S447>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMPSReq_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMWiprIntlTimeSetFb_enum' */
  /* Switch: '<S481>/Switch4' incorporates:
   *  Constant: '<S481>/sat3'
   */
  if (KOPM_BCMWiprIntlTimeSetFb_enum_ovrdflg)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  Constant: '<S481>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     */
    VOPM_BCMIllmndSts_enum = KOPM_BCMWiprIntlTimeSetFb_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S481>/Data Type Conversion1'
     */
    VOPM_BCMIllmndSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
            ->BCM_WiprIntlTimeSetFb;
  }

  /* End of Switch: '<S481>/Switch4' */

  /* MinMax: '<S481>/MinMax' incorporates:
   *  Constant: '<S481>/sat6'
   */
  if (VOPM_BCMIllmndSts_enum > KOPM_BCMWiprIntlTimeSetFbHi_enum)
  {
    /* MinMax: '<S363>/MinMax' */
    VOPM_BCMIllmndSts_enum = KOPM_BCMWiprIntlTimeSetFbHi_enum;
  }

  /* End of MinMax: '<S481>/MinMax' */

  /* MinMax: '<S481>/MinMax1' incorporates:
   *  Constant: '<S481>/sat7'
   */
  if (VOPM_BCMIllmndSts_enum >= KOPM_BCMWiprIntlTimeSetFbLo_enum)
  {
    /* MinMax: '<S481>/MinMax1' */
    VOPM_BCMWiprIntlTimeSetFb_enum = VOPM_BCMIllmndSts_enum;
  }
  else
  {
    /* MinMax: '<S481>/MinMax1' */
    VOPM_BCMWiprIntlTimeSetFb_enum = KOPM_BCMWiprIntlTimeSetFbLo_enum;
  }

  /* End of MinMax: '<S481>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMWiprIntlTimeSetFb_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMStartReq_enum' */
  /* Switch: '<S461>/Switch4' incorporates:
   *  Constant: '<S461>/sat3'
   */
  if (KOPM_BCMStartReq_enum_ovrdflg)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  Constant: '<S461>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     */
    VOPM_BCMIllmndSts_enum = KOPM_BCMStartReq_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S461>/Data Type Conversion1'
     */
    VOPM_BCMIllmndSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_StartReq;
  }

  /* End of Switch: '<S461>/Switch4' */

  /* MinMax: '<S461>/MinMax' incorporates:
   *  Constant: '<S461>/sat6'
   */
  if (VOPM_BCMIllmndSts_enum > KOPM_BCMStartReqHi_enum)
  {
    /* MinMax: '<S363>/MinMax' */
    VOPM_BCMIllmndSts_enum = KOPM_BCMStartReqHi_enum;
  }

  /* End of MinMax: '<S461>/MinMax' */

  /* MinMax: '<S461>/MinMax1' incorporates:
   *  Constant: '<S461>/sat7'
   */
  if (VOPM_BCMIllmndSts_enum >= KOPM_BCMStartReqLo_enum)
  {
    /* MinMax: '<S461>/MinMax1' */
    VOPM_BCMStartReq_enum = VOPM_BCMIllmndSts_enum;
  }
  else
  {
    /* MinMax: '<S461>/MinMax1' */
    VOPM_BCMStartReq_enum = KOPM_BCMStartReqLo_enum;
  }

  /* End of MinMax: '<S461>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMStartReq_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMChgWiprMtMdSwSetFb_enum' */
  /* Switch: '<S383>/Switch4' incorporates:
   *  Constant: '<S383>/sat3'
   */
  if (KOPM_BCMChgWiprMtMdSwSetFb_enum_ovrdflg)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  Constant: '<S383>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     */
    VOPM_BCMIllmndSts_enum = KOPM_BCMChgWiprMtMdSwSetFb_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S383>/Data Type Conversion1'
     */
    VOPM_BCMIllmndSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
            ->BCM_ChgWiperMtMdSwSetFb;
  }

  /* End of Switch: '<S383>/Switch4' */

  /* MinMax: '<S383>/MinMax' incorporates:
   *  Constant: '<S383>/sat6'
   */
  if (VOPM_BCMIllmndSts_enum > KOPM_BCMChgWiprMtMdSwSetFbHi_enum)
  {
    /* MinMax: '<S363>/MinMax' */
    VOPM_BCMIllmndSts_enum = KOPM_BCMChgWiprMtMdSwSetFbHi_enum;
  }

  /* End of MinMax: '<S383>/MinMax' */

  /* MinMax: '<S383>/MinMax1' incorporates:
   *  Constant: '<S383>/sat7'
   */
  if (VOPM_BCMIllmndSts_enum >= KOPM_BCMChgWiprMtMdSwSetFbLo_enum)
  {
    /* MinMax: '<S383>/MinMax1' */
    VOPM_BCMChgWiprMtMdSwSetFb_enum = VOPM_BCMIllmndSts_enum;
  }
  else
  {
    /* MinMax: '<S383>/MinMax1' */
    VOPM_BCMChgWiprMtMdSwSetFb_enum = KOPM_BCMChgWiprMtMdSwSetFbLo_enum;
  }

  /* End of MinMax: '<S383>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMChgWiprMtMdSwSetFb_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMParkAutoUnlckSetFb_flg' */
  /* Switch: '<S448>/Switch4' incorporates:
   *  Constant: '<S448>/sat3'
   */
  if (KOPM_BCMParkAutoUnlckSetFb_flg_ovrdflg)
  {
    /* Switch: '<S448>/Switch4' incorporates:
     *  Constant: '<S448>/sat4'
     */
    VOPM_BCMParkAutoUnlckSetFb_flg = KOPM_BCMParkAutoUnlckSetFb_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S448>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S448>/Data Type Conversion1'
     */
    VOPM_BCMParkAutoUnlckSetFb_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
             ->BCM_ParkAutoUnlockSetFb != 0);
  }

  /* End of Switch: '<S448>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMParkAutoUnlckSetFb_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMOvrspdCntrlLckSetFb_flg' */
  /* Switch: '<S445>/Switch4' incorporates:
   *  Constant: '<S445>/sat3'
   */
  if (KOPM_BCMOvrspdCntrlLckSetFb_flg_ovrdflg)
  {
    /* Switch: '<S445>/Switch4' incorporates:
     *  Constant: '<S445>/sat4'
     */
    VOPM_BCMOvrspdCntrlLckSetFb_flg = KOPM_BCMOvrspdCntrlLckSetFb_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S445>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S445>/Data Type Conversion1'
     */
    VOPM_BCMOvrspdCntrlLckSetFb_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
             ->BCM_OverspdCntrlLockSetFb != 0);
  }

  /* End of Switch: '<S445>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMOvrspdCntrlLckSetFb_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMTrnkLckSta_flg' */
  /* Switch: '<S465>/Switch4' incorporates:
   *  Constant: '<S465>/sat3'
   */
  if (KOPM_BCMTrnkLckSta_flg_ovrdflg)
  {
    /* Switch: '<S465>/Switch4' incorporates:
     *  Constant: '<S465>/sat4'
     */
    VOPM_BCMTrnkLckSta_flg = KOPM_BCMTrnkLckSta_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S465>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S465>/Data Type Conversion1'
     */
    VOPM_BCMTrnkLckSta_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_TrunkLockSta != 0);
  }

  /* End of Switch: '<S465>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMTrnkLckSta_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMTrnkLckSwCtrlFb_flg' */
  /* Switch: '<S466>/Switch4' incorporates:
   *  Constant: '<S466>/sat3'
   */
  if (KOPM_BCMTrnkLckSwCtrlFb_flg_ovrdflg)
  {
    /* Switch: '<S466>/Switch4' incorporates:
     *  Constant: '<S466>/sat4'
     */
    VOPM_BCMTrnkLckSwCtrlFb_flg = KOPM_BCMTrnkLckSwCtrlFb_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S466>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S466>/Data Type Conversion1'
     */
    VOPM_BCMTrnkLckSwCtrlFb_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
             ->BCM_TrunkLockSwCtrlFb != 0);
  }

  /* End of Switch: '<S466>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMTrnkLckSwCtrlFb_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMAuthentKeyNr_enum' */
  /* Switch: '<S373>/Switch4' incorporates:
   *  Constant: '<S373>/sat3'
   */
  if (KOPM_BCMAuthentKeyNr_enum_ovrdflg)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  Constant: '<S373>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     */
    VOPM_BCMIllmndSts_enum = KOPM_BCMAuthentKeyNr_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S373>/Data Type Conversion1'
     */
    VOPM_BCMIllmndSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_AuthentKeyNr;
  }

  /* End of Switch: '<S373>/Switch4' */

  /* MinMax: '<S373>/MinMax' incorporates:
   *  Constant: '<S373>/sat6'
   */
  if (VOPM_BCMIllmndSts_enum > KOPM_BCMAuthentKeyNrHi_enum)
  {
    /* MinMax: '<S363>/MinMax' */
    VOPM_BCMIllmndSts_enum = KOPM_BCMAuthentKeyNrHi_enum;
  }

  /* End of MinMax: '<S373>/MinMax' */

  /* MinMax: '<S373>/MinMax1' incorporates:
   *  Constant: '<S373>/sat7'
   */
  if (VOPM_BCMIllmndSts_enum >= KOPM_BCMAuthentKeyNrLo_enum)
  {
    /* MinMax: '<S373>/MinMax1' */
    VOPM_BCMAuthentKeyNr_enum = VOPM_BCMIllmndSts_enum;
  }
  else
  {
    /* MinMax: '<S373>/MinMax1' */
    VOPM_BCMAuthentKeyNr_enum = KOPM_BCMAuthentKeyNrLo_enum;
  }

  /* End of MinMax: '<S373>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMAuthentKeyNr_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMKeyFrbdn_flg' */
  /* Switch: '<S429>/Switch4' incorporates:
   *  Constant: '<S429>/sat3'
   */
  if (KOPM_BCMKeyFrbdn_flg_ovrdflg)
  {
    /* Switch: '<S429>/Switch4' incorporates:
     *  Constant: '<S429>/sat4'
     */
    VOPM_BCMKeyFrbdn_flg = KOPM_BCMKeyFrbdn_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S429>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S429>/Data Type Conversion1'
     */
    VOPM_BCMKeyFrbdn_flg = ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_KeyFrbdn != 0);
  }

  /* End of Switch: '<S429>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMKeyFrbdn_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMFrbdnKeyNr_enum' */
  /* Switch: '<S408>/Switch4' incorporates:
   *  Constant: '<S408>/sat3'
   */
  if (KOPM_BCMFrbdnKeyNr_enum_ovrdflg)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  Constant: '<S408>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     */
    VOPM_BCMIllmndSts_enum = KOPM_BCMFrbdnKeyNr_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S408>/Data Type Conversion1'
     */
    VOPM_BCMIllmndSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_FrbdnKeyNr;
  }

  /* End of Switch: '<S408>/Switch4' */

  /* MinMax: '<S408>/MinMax' incorporates:
   *  Constant: '<S408>/sat6'
   */
  if (VOPM_BCMIllmndSts_enum > KOPM_BCMFrbdnKeyNrHi_enum)
  {
    /* MinMax: '<S363>/MinMax' */
    VOPM_BCMIllmndSts_enum = KOPM_BCMFrbdnKeyNrHi_enum;
  }

  /* End of MinMax: '<S408>/MinMax' */

  /* MinMax: '<S408>/MinMax1' incorporates:
   *  Constant: '<S408>/sat7'
   */
  if (VOPM_BCMIllmndSts_enum >= KOPM_BCMFrbdnKeyNrLo_enum)
  {
    /* MinMax: '<S408>/MinMax1' */
    VOPM_BCMFrbdnKeyNr_enum = VOPM_BCMIllmndSts_enum;
  }
  else
  {
    /* MinMax: '<S408>/MinMax1' */
    VOPM_BCMFrbdnKeyNr_enum = KOPM_BCMFrbdnKeyNrLo_enum;
  }

  /* End of MinMax: '<S408>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMFrbdnKeyNr_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMKeyIDFb_enum' */
  /* Switch: '<S430>/Switch4' incorporates:
   *  Constant: '<S430>/sat3'
   */
  if (KOPM_BCMKeyIDFb_enum_ovrdflg)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  Constant: '<S430>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     */
    VOPM_BCMIllmndSts_enum = KOPM_BCMKeyIDFb_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S430>/Data Type Conversion1'
     */
    VOPM_BCMIllmndSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_KeyIDFb;
  }

  /* End of Switch: '<S430>/Switch4' */

  /* MinMax: '<S430>/MinMax' incorporates:
   *  Constant: '<S430>/sat6'
   */
  if (VOPM_BCMIllmndSts_enum > KOPM_BCMKeyIDFbHi_enum)
  {
    /* MinMax: '<S363>/MinMax' */
    VOPM_BCMIllmndSts_enum = KOPM_BCMKeyIDFbHi_enum;
  }

  /* End of MinMax: '<S430>/MinMax' */

  /* MinMax: '<S430>/MinMax1' incorporates:
   *  Constant: '<S430>/sat7'
   */
  if (VOPM_BCMIllmndSts_enum >= KOPM_BCMKeyIDFbLo_enum)
  {
    /* MinMax: '<S430>/MinMax1' */
    VOPM_BCMKeyIDFb_enum = VOPM_BCMIllmndSts_enum;
  }
  else
  {
    /* MinMax: '<S430>/MinMax1' */
    VOPM_BCMKeyIDFb_enum = KOPM_BCMKeyIDFbLo_enum;
  }

  /* End of MinMax: '<S430>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMKeyIDFb_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMKeyLocn_mm' */
  /* Switch: '<S433>/Switch4' incorporates:
   *  Constant: '<S433>/sat3'
   */
  if (KOPM_BCMKeyLocn_mm_ovrdflg)
  {
    /* MinMax: '<S433>/MinMax' incorporates:
     *  Constant: '<S433>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion92'
     */
    VOPM_BCMKeyLocn_mm = KOPM_BCMKeyLocn_mm_ovrdval;
  }
  else
  {
    /* MinMax: '<S433>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion92'
     *  DataTypeConversion: '<S433>/Data Type Conversion1'
     */
    VOPM_BCMKeyLocn_mm = (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_KeyLocn;
  }

  /* End of Switch: '<S433>/Switch4' */

  /* MinMax: '<S433>/MinMax' incorporates:
   *  Constant: '<S433>/sat6'
   */
  if (VOPM_BCMKeyLocn_mm > KOPM_BCMKeyLocnHi_mm)
  {
    VOPM_BCMKeyLocn_mm = KOPM_BCMKeyLocnHi_mm;
  }

  /* MinMax: '<S433>/MinMax1' incorporates:
   *  Constant: '<S433>/sat7'
   */
  if (VOPM_BCMKeyLocn_mm < KOPM_BCMKeyLocnLo_mm)
  {
    /* MinMax: '<S433>/MinMax' incorporates:
     *  MinMax: '<S433>/MinMax1'
     */
    VOPM_BCMKeyLocn_mm = KOPM_BCMKeyLocnLo_mm;
  }

  /* End of MinMax: '<S433>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMKeyLocn_mm' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMIllmndEntryStsFb_flg' */
  /* Switch: '<S421>/Switch4' incorporates:
   *  Constant: '<S421>/sat3'
   */
  if (KOPM_BCMIllmndEntryStsFb_flg_ovrdflg)
  {
    /* Switch: '<S421>/Switch4' incorporates:
     *  Constant: '<S421>/sat4'
     */
    VOPM_BCMIllmndEntryStsFb_flg = KOPM_BCMIllmndEntryStsFb_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S421>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S421>/Data Type Conversion1'
     */
    VOPM_BCMIllmndEntryStsFb_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
             ->BCM_IllmndEntryStsFb != 0);
  }

  /* End of Switch: '<S421>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMIllmndEntryStsFb_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMAvaluebleKeyInCar_flg' */
  /* Switch: '<S375>/Switch4' incorporates:
   *  Constant: '<S375>/sat3'
   */
  if (KOPM_BCMAvaluebleKeyInCar_flg_ovrdflg)
  {
    /* Switch: '<S375>/Switch4' incorporates:
     *  Constant: '<S375>/sat4'
     */
    VOPM_BCMAvaluebleKeyInCar_flg = KOPM_BCMAvaluebleKeyInCar_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S375>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S375>/Data Type Conversion1'
     */
    VOPM_BCMAvaluebleKeyInCar_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
             ->BCM_AvaluebleKeyInCar != 0);
  }

  /* End of Switch: '<S375>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMAvaluebleKeyInCar_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMKeyBattLvlSts_flg' */
  /* Switch: '<S427>/Switch4' incorporates:
   *  Constant: '<S427>/sat3'
   */
  if (KOPM_BCMKeyBattLvlSts_flg_ovrdflg)
  {
    /* Switch: '<S427>/Switch4' incorporates:
     *  Constant: '<S427>/sat4'
     */
    VOPM_BCMKeyBattLvlSts_flg = KOPM_BCMKeyBattLvlSts_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S427>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S427>/Data Type Conversion1'
     */
    VOPM_BCMKeyBattLvlSts_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
             ->BCM_KeyBattLvlSts != 0);
  }

  /* End of Switch: '<S427>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMKeyBattLvlSts_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMKeyBattLvl_pct' */
  /* Switch: '<S428>/Switch4' incorporates:
   *  Constant: '<S428>/sat3'
   */
  if (KOPM_BCMKeyBattLvl_pct_ovrdflg)
  {
    /* MinMax: '<S428>/MinMax' incorporates:
     *  Constant: '<S428>/sat4'
     *  Product: '<S493>/Product1'
     */
    VOPM_BCMMaiDrvrSeatTemp_C = KOPM_BCMKeyBattLvl_pct_ovrdval;
  }
  else
  {
    /* MinMax: '<S428>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S428>/Data Type Conversion1'
     *  Product: '<S493>/Product1'
     */
    VOPM_BCMMaiDrvrSeatTemp_C = (float32)(Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_KeyBattLvl;
  }

  /* End of Switch: '<S428>/Switch4' */

  /* MinMax: '<S428>/MinMax' incorporates:
   *  Constant: '<S428>/sat6'
   */
  if (VOPM_BCMMaiDrvrSeatTemp_C > KOPM_BCMKeyBattLvlHi_pct)
  {
    VOPM_BCMMaiDrvrSeatTemp_C = KOPM_BCMKeyBattLvlHi_pct;
  }

  /* MinMax: '<S428>/MinMax1' incorporates:
   *  Constant: '<S428>/sat7'
   */
  if (VOPM_BCMMaiDrvrSeatTemp_C >= KOPM_BCMKeyBattLvlLo_pct)
  {
    /* MinMax: '<S428>/MinMax1' */
    VOPM_BCMKeyBattLvl_pct = VOPM_BCMMaiDrvrSeatTemp_C;
  }
  else
  {
    /* MinMax: '<S428>/MinMax1' */
    VOPM_BCMKeyBattLvl_pct = KOPM_BCMKeyBattLvlLo_pct;
  }

  /* End of MinMax: '<S428>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMKeyBattLvl_pct' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMKeyLoBattLvlWarn_flg' */
  /* Switch: '<S432>/Switch4' incorporates:
   *  Constant: '<S432>/sat3'
   */
  if (KOPM_BCMKeyLoBattLvlWarn_flg_ovrdflg)
  {
    /* Switch: '<S432>/Switch4' incorporates:
     *  Constant: '<S432>/sat4'
     */
    VOPM_BCMKeyLoBattLvlWarn_flg = KOPM_BCMKeyLoBattLvlWarn_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S432>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S432>/Data Type Conversion1'
     */
    VOPM_BCMKeyLoBattLvlWarn_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
             ->BCM_KeyLoBattLvlWarn != 0);
  }

  /* End of Switch: '<S432>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMKeyLoBattLvlWarn_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMKeySta_enum' */
  /* Switch: '<S434>/Switch4' incorporates:
   *  Constant: '<S434>/sat3'
   */
  if (KOPM_BCMKeySta_enum_ovrdflg)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  Constant: '<S434>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     */
    VOPM_BCMIllmndSts_enum = KOPM_BCMKeySta_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S434>/Data Type Conversion1'
     */
    VOPM_BCMIllmndSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_KeySta;
  }

  /* End of Switch: '<S434>/Switch4' */

  /* MinMax: '<S434>/MinMax' incorporates:
   *  Constant: '<S434>/sat6'
   */
  if (VOPM_BCMIllmndSts_enum > KOPM_BCMKeyStaHi_enum)
  {
    /* MinMax: '<S363>/MinMax' */
    VOPM_BCMIllmndSts_enum = KOPM_BCMKeyStaHi_enum;
  }

  /* End of MinMax: '<S434>/MinMax' */

  /* MinMax: '<S434>/MinMax1' incorporates:
   *  Constant: '<S434>/sat7'
   */
  if (VOPM_BCMIllmndSts_enum >= KOPM_BCMKeyStaLo_enum)
  {
    /* MinMax: '<S434>/MinMax1' */
    VOPM_BCMKeySta_enum = VOPM_BCMIllmndSts_enum;
  }
  else
  {
    /* MinMax: '<S434>/MinMax1' */
    VOPM_BCMKeySta_enum = KOPM_BCMKeyStaLo_enum;
  }

  /* End of MinMax: '<S434>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMKeySta_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMIllmndLampReq_flg' */
  /* Switch: '<S422>/Switch4' incorporates:
   *  Constant: '<S422>/sat3'
   */
  if (KOPM_BCMIllmndLampReq_flg_ovrdflg)
  {
    /* Switch: '<S422>/Switch4' incorporates:
     *  Constant: '<S422>/sat4'
     */
    VOPM_BCMIllmndLampReq_flg = KOPM_BCMIllmndLampReq_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S422>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S422>/Data Type Conversion1'
     */
    VOPM_BCMIllmndLampReq_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
             ->BCM_IllmndLampReq != 0);
  }

  /* End of Switch: '<S422>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMIllmndLampReq_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMIllmndLockReq_enum' */
  /* Switch: '<S423>/Switch4' incorporates:
   *  Constant: '<S423>/sat3'
   */
  if (KOPM_BCMIllmndLockReq_enum_ovrdflg)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  Constant: '<S423>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     */
    VOPM_BCMIllmndSts_enum = KOPM_BCMIllmndLockReq_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S423>/Data Type Conversion1'
     */
    VOPM_BCMIllmndSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_IllmndLockReq;
  }

  /* End of Switch: '<S423>/Switch4' */

  /* MinMax: '<S423>/MinMax' incorporates:
   *  Constant: '<S423>/sat6'
   */
  if (VOPM_BCMIllmndSts_enum > KOPM_BCMIllmndLockReqHi_enum)
  {
    /* MinMax: '<S363>/MinMax' */
    VOPM_BCMIllmndSts_enum = KOPM_BCMIllmndLockReqHi_enum;
  }

  /* End of MinMax: '<S423>/MinMax' */

  /* MinMax: '<S423>/MinMax1' incorporates:
   *  Constant: '<S423>/sat7'
   */
  if (VOPM_BCMIllmndSts_enum >= KOPM_BCMIllmndLockReqLo_enum)
  {
    /* MinMax: '<S423>/MinMax1' */
    VOPM_BCMIllmndLockReq_enum = VOPM_BCMIllmndSts_enum;
  }
  else
  {
    /* MinMax: '<S423>/MinMax1' */
    VOPM_BCMIllmndLockReq_enum = KOPM_BCMIllmndLockReqLo_enum;
  }

  /* End of MinMax: '<S423>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMIllmndLockReq_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMIndcnShfttoNeut_flg' */
  /* Switch: '<S426>/Switch4' incorporates:
   *  Constant: '<S426>/sat3'
   */
  if (KOPM_BCMIndcnShfttoNeut_flg_ovrdflg)
  {
    /* Switch: '<S426>/Switch4' incorporates:
     *  Constant: '<S426>/sat4'
     */
    VOPM_BCMIndcnShfttoNeut_flg = KOPM_BCMIndcnShfttoNeut_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S426>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S426>/Data Type Conversion1'
     */
    VOPM_BCMIndcnShfttoNeut_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
             ->BCM_IndicationShifttoNeutral != 0);
  }

  /* End of Switch: '<S426>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMIndcnShfttoNeut_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMWarnKeyOutRmndr_flg' */
  /* Switch: '<S473>/Switch4' incorporates:
   *  Constant: '<S473>/sat3'
   */
  if (KOPM_BCMWarnKeyOutRmndr_flg_ovrdflg)
  {
    /* Switch: '<S473>/Switch4' incorporates:
     *  Constant: '<S473>/sat4'
     */
    VOPM_BCMWarnKeyOutRmndr_flg = KOPM_BCMWarnKeyOutRmndr_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S473>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S473>/Data Type Conversion1'
     */
    VOPM_BCMWarnKeyOutRmndr_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
             ->BCM_WarnKeyOutReminder != 0);
  }

  /* End of Switch: '<S473>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMWarnKeyOutRmndr_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMIndcnKeyClsr_flg' */
  /* Switch: '<S425>/Switch4' incorporates:
   *  Constant: '<S425>/sat3'
   */
  if (KOPM_BCMIndcnKeyClsr_flg_ovrdflg)
  {
    /* Switch: '<S425>/Switch4' incorporates:
     *  Constant: '<S425>/sat4'
     */
    VOPM_BCMIndcnKeyClsr_flg = KOPM_BCMIndcnKeyClsr_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S425>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S425>/Data Type Conversion1'
     */
    VOPM_BCMIndcnKeyClsr_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
             ->BCM_IndicationKeyCloser != 0);
  }

  /* End of Switch: '<S425>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMIndcnKeyClsr_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMIllmndSts_enum' */
  /* Switch: '<S424>/Switch4' incorporates:
   *  Constant: '<S424>/sat3'
   */
  if (KOPM_BCMIllmndSts_enum_ovrdflg)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  Constant: '<S424>/sat4'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     */
    VOPM_BCMIllmndSts_enum = KOPM_BCMIllmndSts_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S349>/DataTypeConversion102'
     *  DataTypeConversion: '<S424>/Data Type Conversion1'
     */
    VOPM_BCMIllmndSts_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_IllmndSts;
  }

  /* End of Switch: '<S424>/Switch4' */

  /* MinMax: '<S424>/MinMax' incorporates:
   *  Constant: '<S424>/sat6'
   */
  if (VOPM_BCMIllmndSts_enum > KOPM_BCMIllmndStsHi_enum)
  {
    /* MinMax: '<S363>/MinMax' */
    VOPM_BCMIllmndSts_enum = KOPM_BCMIllmndStsHi_enum;
  }

  /* End of MinMax: '<S424>/MinMax' */

  /* MinMax: '<S424>/MinMax1' incorporates:
   *  Constant: '<S424>/sat7'
   */
  if (VOPM_BCMIllmndSts_enum < KOPM_BCMIllmndStsLo_enum)
  {
    /* MinMax: '<S363>/MinMax' incorporates:
     *  MinMax: '<S424>/MinMax1'
     */
    VOPM_BCMIllmndSts_enum = KOPM_BCMIllmndStsLo_enum;
  }

  /* End of MinMax: '<S424>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMIllmndSts_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMSteerWhlHeatSts_flg' */
  /* Switch: '<S462>/Switch4' incorporates:
   *  Constant: '<S462>/sat3'
   */
  if (KOPM_BCMSteerWhlHeatSts_flg_ovrdflg)
  {
    /* MinMax: '<S462>/MinMax' incorporates:
     *  Constant: '<S462>/sat4'
     */
    rtb_MinMax_b = KOPM_BCMSteerWhlHeatSts_flg_ovrdval;
  }
  else
  {
    /* MinMax: '<S462>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S462>/Data Type Conversion1'
     */
    rtb_MinMax_b = ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
                        ->BCM_SteerWhlHeatSts != 0);
  }

  /* End of Switch: '<S462>/Switch4' */

  /* MinMax: '<S462>/MinMax1' incorporates:
   *  Constant: '<S462>/sat6'
   *  Constant: '<S462>/sat7'
   *  MinMax: '<S462>/MinMax'
   */
  VOPM_BCMSteerWhlHeatSts_flg = ((rtb_MinMax_b && KOPM_BCMSteerWhlHeatStsHi_flg) || KOPM_BCMSteerWhlHeatStsLo_flg);

  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMSteerWhlHeatSts_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMSteerWhlTemp_C' */
  /* Switch: '<S463>/Switch4' incorporates:
   *  Constant: '<S463>/sat3'
   */
  if (KOPM_BCMSteerWhlTemp_C_ovrdflg)
  {
    /* MinMax: '<S428>/MinMax' incorporates:
     *  Constant: '<S463>/sat4'
     *  Product: '<S493>/Product1'
     */
    VOPM_BCMMaiDrvrSeatTemp_C = KOPM_BCMSteerWhlTemp_C_ovrdval;
  }
  else
  {
    /* MinMax: '<S428>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S463>/Data Type Conversion1'
     *  Product: '<S493>/Product1'
     */
    VOPM_BCMMaiDrvrSeatTemp_C = (float32)(Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_SteerWhlTemp;
  }

  /* End of Switch: '<S463>/Switch4' */

  /* MinMax: '<S463>/MinMax' incorporates:
   *  Constant: '<S463>/sat6'
   */
  if (VOPM_BCMMaiDrvrSeatTemp_C > KOPM_BCMSteerWhlTempHi_C)
  {
    /* MinMax: '<S428>/MinMax' */
    VOPM_BCMMaiDrvrSeatTemp_C = KOPM_BCMSteerWhlTempHi_C;
  }

  /* End of MinMax: '<S463>/MinMax' */

  /* MinMax: '<S463>/MinMax1' incorporates:
   *  Constant: '<S463>/sat7'
   */
  if (VOPM_BCMMaiDrvrSeatTemp_C >= KOPM_BCMSteerWhlTempLo_C)
  {
    /* MinMax: '<S463>/MinMax1' */
    VOPM_BCMSteerWhlTemp_C = VOPM_BCMMaiDrvrSeatTemp_C;
  }
  else
  {
    /* MinMax: '<S463>/MinMax1' */
    VOPM_BCMSteerWhlTemp_C = KOPM_BCMSteerWhlTempLo_C;
  }

  /* End of MinMax: '<S463>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMSteerWhlTemp_C' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMMaiDrvrSeatTemp_C' */
  /* Switch: '<S444>/Switch4' incorporates:
   *  Constant: '<S444>/sat3'
   */
  if (KOPM_BCMMaiDrvrSeatTemp_C_ovrdflg)
  {
    /* MinMax: '<S428>/MinMax' incorporates:
     *  Constant: '<S444>/sat4'
     *  Product: '<S493>/Product1'
     */
    VOPM_BCMMaiDrvrSeatTemp_C = KOPM_BCMMaiDrvrSeatTemp_C_ovrdval;
  }
  else
  {
    /* MinMax: '<S428>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S444>/Data Type Conversion1'
     *  Product: '<S493>/Product1'
     */
    VOPM_BCMMaiDrvrSeatTemp_C = (float32)(Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
                                    ->BCM_MaiDrvrSeatTemp;
  }

  /* End of Switch: '<S444>/Switch4' */

  /* MinMax: '<S444>/MinMax' incorporates:
   *  Constant: '<S444>/sat6'
   */
  if (VOPM_BCMMaiDrvrSeatTemp_C > KOPM_BCMMaiDrvrSeatTempHi_C)
  {
    /* MinMax: '<S428>/MinMax' */
    VOPM_BCMMaiDrvrSeatTemp_C = KOPM_BCMMaiDrvrSeatTempHi_C;
  }

  /* End of MinMax: '<S444>/MinMax' */

  /* MinMax: '<S444>/MinMax1' incorporates:
   *  Constant: '<S444>/sat7'
   */
  if (VOPM_BCMMaiDrvrSeatTemp_C < KOPM_BCMMaiDrvrSeatTempLo_C)
  {
    /* MinMax: '<S428>/MinMax' incorporates:
     *  MinMax: '<S444>/MinMax1'
     */
    VOPM_BCMMaiDrvrSeatTemp_C = KOPM_BCMMaiDrvrSeatTempLo_C;
  }

  /* End of MinMax: '<S444>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMMaiDrvrSeatTemp_C' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMRrMirrHeatSts_flg' */
  /* Switch: '<S458>/Switch4' incorporates:
   *  Constant: '<S458>/sat3'
   */
  if (KOPM_BCMRrMirrHeatSts_flg_ovrdflg)
  {
    /* Switch: '<S458>/Switch4' incorporates:
     *  Constant: '<S458>/sat4'
     */
    VOPM_BCMRrMirrHeatSts_flg = KOPM_BCMRrMirrHeatSts_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S458>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S458>/Data Type Conversion1'
     */
    VOPM_BCMRrMirrHeatSts_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
             ->BCM_RearMirrorHeatSts != 0);
  }

  /* End of Switch: '<S458>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMRrMirrHeatSts_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMMaiDrvrSeatSts_enum' */
  /* Switch: '<S443>/Switch4' incorporates:
   *  Constant: '<S443>/sat3'
   */
  if (KOPM_BCMMaiDrvrSeatSts_enum_ovrdflg)
  {
    /* MinMax: '<S443>/MinMax' incorporates:
     *  Constant: '<S443>/sat4'
     *  MinMax: '<S377>/MinMax'
     */
    VOPM_BCMBackLiFltFb_enum = KOPM_BCMMaiDrvrSeatSts_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S443>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S443>/Data Type Conversion1'
     *  MinMax: '<S377>/MinMax'
     */
    VOPM_BCMBackLiFltFb_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
            ->BCM_MaiDrvrSeatSts;
  }

  /* End of Switch: '<S443>/Switch4' */

  /* MinMax: '<S443>/MinMax' incorporates:
   *  Constant: '<S443>/sat6'
   */
  if (VOPM_BCMBackLiFltFb_enum > KOPM_BCMMaiDrvrSeatStsHi_enum)
  {
    VOPM_BCMBackLiFltFb_enum = KOPM_BCMMaiDrvrSeatStsHi_enum;
  }

  /* MinMax: '<S443>/MinMax1' incorporates:
   *  Constant: '<S443>/sat7'
   */
  if (VOPM_BCMBackLiFltFb_enum >= KOPM_BCMMaiDrvrSeatStsLo_enum)
  {
    /* MinMax: '<S443>/MinMax1' */
    VOPM_BCMMaiDrvrSeatSts_enum = VOPM_BCMBackLiFltFb_enum;
  }
  else
  {
    /* MinMax: '<S443>/MinMax1' */
    VOPM_BCMMaiDrvrSeatSts_enum = KOPM_BCMMaiDrvrSeatStsLo_enum;
  }

  /* End of MinMax: '<S443>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMMaiDrvrSeatSts_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMFrntWiprMotSts_enum' */
  /* Switch: '<S413>/Switch4' incorporates:
   *  Constant: '<S413>/sat3'
   */
  if (KOPM_BCMFrntWiprMotSts_enum_ovrdflg)
  {
    /* MinMax: '<S443>/MinMax' incorporates:
     *  Constant: '<S413>/sat4'
     *  MinMax: '<S377>/MinMax'
     */
    VOPM_BCMBackLiFltFb_enum = KOPM_BCMFrntWiprMotSts_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S443>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S413>/Data Type Conversion1'
     *  MinMax: '<S377>/MinMax'
     */
    VOPM_BCMBackLiFltFb_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
            ->BCM_FrontWiperMotorSts;
  }

  /* End of Switch: '<S413>/Switch4' */

  /* MinMax: '<S413>/MinMax' incorporates:
   *  Constant: '<S413>/sat6'
   */
  if (VOPM_BCMBackLiFltFb_enum > KOPM_BCMFrntWiprMotStsHi_enum)
  {
    /* MinMax: '<S443>/MinMax' */
    VOPM_BCMBackLiFltFb_enum = KOPM_BCMFrntWiprMotStsHi_enum;
  }

  /* End of MinMax: '<S413>/MinMax' */

  /* MinMax: '<S413>/MinMax1' incorporates:
   *  Constant: '<S413>/sat7'
   */
  if (VOPM_BCMBackLiFltFb_enum >= KOPM_BCMFrntWiprMotStsLo_enum)
  {
    /* MinMax: '<S413>/MinMax1' */
    VOPM_BCMFrntWiprMotSts_enum = VOPM_BCMBackLiFltFb_enum;
  }
  else
  {
    /* MinMax: '<S413>/MinMax1' */
    VOPM_BCMFrntWiprMotSts_enum = KOPM_BCMFrntWiprMotStsLo_enum;
  }

  /* End of MinMax: '<S413>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMFrntWiprMotSts_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMLogoActvFlg_enum' */
  /* Switch: '<S441>/Switch4' incorporates:
   *  Constant: '<S441>/sat3'
   */
  if (KOPM_BCMLogoActvFlg_enum_ovrdflg)
  {
    /* MinMax: '<S443>/MinMax' incorporates:
     *  Constant: '<S441>/sat4'
     *  MinMax: '<S377>/MinMax'
     */
    VOPM_BCMBackLiFltFb_enum = KOPM_BCMLogoActvFlg_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S443>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S441>/Data Type Conversion1'
     *  MinMax: '<S377>/MinMax'
     */
    VOPM_BCMBackLiFltFb_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
            ->BCM_LogoActiveFlag;
  }

  /* End of Switch: '<S441>/Switch4' */

  /* MinMax: '<S441>/MinMax' incorporates:
   *  Constant: '<S441>/sat6'
   */
  if (VOPM_BCMBackLiFltFb_enum > KOPM_BCMLogoActvFlgHi_enum)
  {
    /* MinMax: '<S443>/MinMax' */
    VOPM_BCMBackLiFltFb_enum = KOPM_BCMLogoActvFlgHi_enum;
  }

  /* End of MinMax: '<S441>/MinMax' */

  /* MinMax: '<S441>/MinMax1' incorporates:
   *  Constant: '<S441>/sat7'
   */
  if (VOPM_BCMBackLiFltFb_enum >= KOPM_BCMLogoActvFlgLo_enum)
  {
    /* MinMax: '<S441>/MinMax1' */
    VOPM_BCMLogoActvFlg_enum = VOPM_BCMBackLiFltFb_enum;
  }
  else
  {
    /* MinMax: '<S441>/MinMax1' */
    VOPM_BCMLogoActvFlg_enum = KOPM_BCMLogoActvFlgLo_enum;
  }

  /* End of MinMax: '<S441>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMLogoActvFlg_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMVehSeek_flg' */
  /* Switch: '<S472>/Switch4' incorporates:
   *  Constant: '<S472>/sat3'
   */
  if (KOPM_BCMVehSeek_flg_ovrdflg)
  {
    /* Switch: '<S472>/Switch4' incorporates:
     *  Constant: '<S472>/sat4'
     */
    VOPM_BCMVehSeek_flg = KOPM_BCMVehSeek_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S472>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S472>/Data Type Conversion1'
     */
    VOPM_BCMVehSeek_flg = ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
                               ->BCM_VhclSeek != 0);
  }

  /* End of Switch: '<S472>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMVehSeek_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMRFInitSta_flg' */
  /* Switch: '<S452>/Switch4' incorporates:
   *  Constant: '<S452>/sat3'
   */
  if (KOPM_BCMRFInitSta_flg_ovrdflg)
  {
    /* Switch: '<S452>/Switch4' incorporates:
     *  Constant: '<S452>/sat4'
     */
    VOPM_BCMRFInitSta_flg = KOPM_BCMRFInitSta_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S452>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S452>/Data Type Conversion1'
     */
    VOPM_BCMRFInitSta_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_RFInitSta !=
         0);
  }

  /* End of Switch: '<S452>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMRFInitSta_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMRiTrnLiFltFb_enum' */
  /* Switch: '<S455>/Switch4' incorporates:
   *  Constant: '<S455>/sat3'
   */
  if (KOPM_BCMRiTrnLiFltFb_enum_ovrdflg)
  {
    /* MinMax: '<S443>/MinMax' incorporates:
     *  Constant: '<S455>/sat4'
     *  MinMax: '<S377>/MinMax'
     */
    VOPM_BCMBackLiFltFb_enum = KOPM_BCMRiTrnLiFltFb_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S443>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S455>/Data Type Conversion1'
     *  MinMax: '<S377>/MinMax'
     */
    VOPM_BCMBackLiFltFb_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
            ->BCM_RiTurnLiFaultFb;
  }

  /* End of Switch: '<S455>/Switch4' */

  /* MinMax: '<S455>/MinMax' incorporates:
   *  Constant: '<S455>/sat6'
   */
  if (VOPM_BCMBackLiFltFb_enum > KOPM_BCMRiTrnLiFltFbHi_enum)
  {
    /* MinMax: '<S443>/MinMax' */
    VOPM_BCMBackLiFltFb_enum = KOPM_BCMRiTrnLiFltFbHi_enum;
  }

  /* End of MinMax: '<S455>/MinMax' */

  /* MinMax: '<S455>/MinMax1' incorporates:
   *  Constant: '<S455>/sat7'
   */
  if (VOPM_BCMBackLiFltFb_enum >= KOPM_BCMRiTrnLiFltFbLo_enum)
  {
    /* MinMax: '<S455>/MinMax1' */
    VOPM_BCMRiTrnLiFltFb_enum = VOPM_BCMBackLiFltFb_enum;
  }
  else
  {
    /* MinMax: '<S455>/MinMax1' */
    VOPM_BCMRiTrnLiFltFb_enum = KOPM_BCMRiTrnLiFltFbLo_enum;
  }

  /* End of MinMax: '<S455>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMRiTrnLiFltFb_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMLeTrnLiFltFb_enum' */
  /* Switch: '<S437>/Switch4' incorporates:
   *  Constant: '<S437>/sat3'
   */
  if (KOPM_BCMLeTrnLiFltFb_enum_ovrdflg)
  {
    /* MinMax: '<S443>/MinMax' incorporates:
     *  Constant: '<S437>/sat4'
     *  MinMax: '<S377>/MinMax'
     */
    VOPM_BCMBackLiFltFb_enum = KOPM_BCMLeTrnLiFltFb_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S443>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S437>/Data Type Conversion1'
     *  MinMax: '<S377>/MinMax'
     */
    VOPM_BCMBackLiFltFb_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
            ->BCM_LeTurnLiFaultFb;
  }

  /* End of Switch: '<S437>/Switch4' */

  /* MinMax: '<S437>/MinMax' incorporates:
   *  Constant: '<S437>/sat6'
   */
  if (VOPM_BCMBackLiFltFb_enum > KOPM_BCMLeTrnLiFltFbHi_enum)
  {
    /* MinMax: '<S443>/MinMax' */
    VOPM_BCMBackLiFltFb_enum = KOPM_BCMLeTrnLiFltFbHi_enum;
  }

  /* End of MinMax: '<S437>/MinMax' */

  /* MinMax: '<S437>/MinMax1' incorporates:
   *  Constant: '<S437>/sat7'
   */
  if (VOPM_BCMBackLiFltFb_enum >= KOPM_BCMLeTrnLiFltFbLo_enum)
  {
    /* MinMax: '<S437>/MinMax1' */
    VOPM_BCMLeTrnLiFltFb_enum = VOPM_BCMBackLiFltFb_enum;
  }
  else
  {
    /* MinMax: '<S437>/MinMax1' */
    VOPM_BCMLeTrnLiFltFb_enum = KOPM_BCMLeTrnLiFltFbLo_enum;
  }

  /* End of MinMax: '<S437>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMLeTrnLiFltFb_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMFLWinmotor_flg' */
  /* Switch: '<S400>/Switch4' incorporates:
   *  Constant: '<S400>/sat3'
   */
  if (KOPM_BCMFLWinmotor_flg_ovrdflg)
  {
    /* Switch: '<S400>/Switch4' incorporates:
     *  Constant: '<S400>/sat4'
     */
    VOPM_BCMFLWinmotor_flg = KOPM_BCMFLWinmotor_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S400>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S400>/Data Type Conversion1'
     */
    VOPM_BCMFLWinmotor_flg =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
            ->BCM_FLWindowmotorFlags;
  }

  /* End of Switch: '<S400>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMFLWinmotor_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMFRWinmotor_flg' */
  /* Switch: '<S404>/Switch4' incorporates:
   *  Constant: '<S404>/sat3'
   */
  if (KOPM_BCMFRWinmotor_flg_ovrdflg)
  {
    /* Switch: '<S404>/Switch4' incorporates:
     *  Constant: '<S404>/sat4'
     */
    VOPM_BCMFRWinmotor_flg = KOPM_BCMFRWinmotor_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S404>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S404>/Data Type Conversion1'
     */
    VOPM_BCMFRWinmotor_flg =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
            ->BCM_FRWindowmotorFlags;
  }

  /* End of Switch: '<S404>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMFRWinmotor_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMDrvPassWinSwSig_enum' */
  /* Switch: '<S395>/Switch4' incorporates:
   *  Constant: '<S395>/sat3'
   */
  if (KOPM_BCMDrvPassWinSwSig_enum_ovrdflg)
  {
    /* MinMax: '<S443>/MinMax' incorporates:
     *  Constant: '<S395>/sat4'
     *  MinMax: '<S377>/MinMax'
     */
    VOPM_BCMBackLiFltFb_enum = KOPM_BCMDrvPassWinSwSig_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S443>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S395>/Data Type Conversion1'
     *  MinMax: '<S377>/MinMax'
     */
    VOPM_BCMBackLiFltFb_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
            ->BCM_DrvPassWinSwSig;
  }

  /* End of Switch: '<S395>/Switch4' */

  /* MinMax: '<S395>/MinMax' incorporates:
   *  Constant: '<S395>/sat6'
   */
  if (VOPM_BCMBackLiFltFb_enum > KOPM_BCMDrvPassWinSwSigHi_enum)
  {
    /* MinMax: '<S443>/MinMax' */
    VOPM_BCMBackLiFltFb_enum = KOPM_BCMDrvPassWinSwSigHi_enum;
  }

  /* End of MinMax: '<S395>/MinMax' */

  /* MinMax: '<S395>/MinMax1' incorporates:
   *  Constant: '<S395>/sat7'
   */
  if (VOPM_BCMBackLiFltFb_enum >= KOPM_BCMDrvPassWinSwSigLo_enum)
  {
    /* MinMax: '<S395>/MinMax1' */
    VOPM_BCMDrvPassWinSwSig_enum = VOPM_BCMBackLiFltFb_enum;
  }
  else
  {
    /* MinMax: '<S395>/MinMax1' */
    VOPM_BCMDrvPassWinSwSig_enum = KOPM_BCMDrvPassWinSwSigLo_enum;
  }

  /* End of MinMax: '<S395>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMDrvPassWinSwSig_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMDoorLckOpRec_enum' */
  /* Switch: '<S393>/Switch4' incorporates:
   *  Constant: '<S393>/sat3'
   */
  if (KOPM_BCMDoorLckOpRec_enum_ovrdflg)
  {
    /* MinMax: '<S443>/MinMax' incorporates:
     *  Constant: '<S393>/sat4'
     *  MinMax: '<S377>/MinMax'
     */
    VOPM_BCMBackLiFltFb_enum = KOPM_BCMDoorLckOpRec_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S443>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S393>/Data Type Conversion1'
     *  MinMax: '<S377>/MinMax'
     */
    VOPM_BCMBackLiFltFb_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
            ->BCM_DoorLockOperationRecord;
  }

  /* End of Switch: '<S393>/Switch4' */

  /* MinMax: '<S393>/MinMax' incorporates:
   *  Constant: '<S393>/sat6'
   */
  if (VOPM_BCMBackLiFltFb_enum > KOPM_BCMDoorLckOpRecHi_enum)
  {
    /* MinMax: '<S443>/MinMax' */
    VOPM_BCMBackLiFltFb_enum = KOPM_BCMDoorLckOpRecHi_enum;
  }

  /* End of MinMax: '<S393>/MinMax' */

  /* MinMax: '<S393>/MinMax1' incorporates:
   *  Constant: '<S393>/sat7'
   */
  if (VOPM_BCMBackLiFltFb_enum >= KOPM_BCMDoorLckOpRecLo_enum)
  {
    /* MinMax: '<S393>/MinMax1' */
    VOPM_BCMDoorLckOpRec_enum = VOPM_BCMBackLiFltFb_enum;
  }
  else
  {
    /* MinMax: '<S393>/MinMax1' */
    VOPM_BCMDoorLckOpRec_enum = KOPM_BCMDoorLckOpRecLo_enum;
  }

  /* End of MinMax: '<S393>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMDoorLckOpRec_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMLFInitSta_flg' */
  /* Switch: '<S435>/Switch4' incorporates:
   *  Constant: '<S435>/sat3'
   */
  if (KOPM_BCMLFInitSta_flg_ovrdflg)
  {
    /* Switch: '<S435>/Switch4' incorporates:
     *  Constant: '<S435>/sat4'
     */
    VOPM_BCMLFInitSta_flg = KOPM_BCMLFInitSta_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S435>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S435>/Data Type Conversion1'
     */
    VOPM_BCMLFInitSta_flg = (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_LFInitSta;
  }

  /* End of Switch: '<S435>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMLFInitSta_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_DrvLfAntDiagStat_enum' */
  /* Switch: '<S483>/Switch4' incorporates:
   *  Constant: '<S483>/sat3'
   */
  if (KOPM_DrvLfAntDiagStat_enum_ovrdflg)
  {
    /* MinMax: '<S443>/MinMax' incorporates:
     *  Constant: '<S483>/sat4'
     *  MinMax: '<S377>/MinMax'
     */
    VOPM_BCMBackLiFltFb_enum = KOPM_DrvLfAntDiagStat_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S443>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S483>/Data Type Conversion1'
     *  MinMax: '<S377>/MinMax'
     */
    VOPM_BCMBackLiFltFb_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
            ->DrvLfAnt_DiagStatus;
  }

  /* End of Switch: '<S483>/Switch4' */

  /* MinMax: '<S483>/MinMax' incorporates:
   *  Constant: '<S483>/sat6'
   */
  if (VOPM_BCMBackLiFltFb_enum > KOPM_DrvLfAntDiagStatHi_enum)
  {
    /* MinMax: '<S443>/MinMax' */
    VOPM_BCMBackLiFltFb_enum = KOPM_DrvLfAntDiagStatHi_enum;
  }

  /* End of MinMax: '<S483>/MinMax' */

  /* MinMax: '<S483>/MinMax1' incorporates:
   *  Constant: '<S483>/sat7'
   */
  if (VOPM_BCMBackLiFltFb_enum >= KOPM_DrvLfAntDiagStatLo_enum)
  {
    /* MinMax: '<S483>/MinMax1' */
    VOPM_DrvLfAntDiagStat_enum = VOPM_BCMBackLiFltFb_enum;
  }
  else
  {
    /* MinMax: '<S483>/MinMax1' */
    VOPM_DrvLfAntDiagStat_enum = KOPM_DrvLfAntDiagStatLo_enum;
  }

  /* End of MinMax: '<S483>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_DrvLfAntDiagStat_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_PassLfAntDiagStat_enum' */
  /* Switch: '<S485>/Switch4' incorporates:
   *  Constant: '<S485>/sat3'
   */
  if (KOPM_PassLfAntDiagStat_enum_ovrdflg)
  {
    /* MinMax: '<S443>/MinMax' incorporates:
     *  Constant: '<S485>/sat4'
     *  MinMax: '<S377>/MinMax'
     */
    VOPM_BCMBackLiFltFb_enum = KOPM_PassLfAntDiagStat_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S443>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S485>/Data Type Conversion1'
     *  MinMax: '<S377>/MinMax'
     */
    VOPM_BCMBackLiFltFb_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
            ->PassLfAnt_DiagStatus;
  }

  /* End of Switch: '<S485>/Switch4' */

  /* MinMax: '<S485>/MinMax' incorporates:
   *  Constant: '<S485>/sat6'
   */
  if (VOPM_BCMBackLiFltFb_enum > KOPM_PassLfAntDiagStatHi_enum)
  {
    /* MinMax: '<S443>/MinMax' */
    VOPM_BCMBackLiFltFb_enum = KOPM_PassLfAntDiagStatHi_enum;
  }

  /* End of MinMax: '<S485>/MinMax' */

  /* MinMax: '<S485>/MinMax1' incorporates:
   *  Constant: '<S485>/sat7'
   */
  if (VOPM_BCMBackLiFltFb_enum >= KOPM_PassLfAntDiagStatLo_enum)
  {
    /* MinMax: '<S485>/MinMax1' */
    VOPM_PassLfAntDiagStat_enum = VOPM_BCMBackLiFltFb_enum;
  }
  else
  {
    /* MinMax: '<S485>/MinMax1' */
    VOPM_PassLfAntDiagStat_enum = KOPM_PassLfAntDiagStatLo_enum;
  }

  /* End of MinMax: '<S485>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_PassLfAntDiagStat_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_IntLfAntDiagStat_enum' */
  /* Switch: '<S484>/Switch4' incorporates:
   *  Constant: '<S484>/sat3'
   */
  if (KOPM_IntLfAntDiagStat_enum_ovrdflg)
  {
    /* MinMax: '<S443>/MinMax' incorporates:
     *  Constant: '<S484>/sat4'
     *  MinMax: '<S377>/MinMax'
     */
    VOPM_BCMBackLiFltFb_enum = KOPM_IntLfAntDiagStat_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S443>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S484>/Data Type Conversion1'
     *  MinMax: '<S377>/MinMax'
     */
    VOPM_BCMBackLiFltFb_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
            ->IntLfAnt_DiagStatus;
  }

  /* End of Switch: '<S484>/Switch4' */

  /* MinMax: '<S484>/MinMax' incorporates:
   *  Constant: '<S484>/sat6'
   */
  if (VOPM_BCMBackLiFltFb_enum > KOPM_IntLfAntDiagStatHi_enum)
  {
    /* MinMax: '<S443>/MinMax' */
    VOPM_BCMBackLiFltFb_enum = KOPM_IntLfAntDiagStatHi_enum;
  }

  /* End of MinMax: '<S484>/MinMax' */

  /* MinMax: '<S484>/MinMax1' incorporates:
   *  Constant: '<S484>/sat7'
   */
  if (VOPM_BCMBackLiFltFb_enum >= KOPM_IntLfAntDiagStatLo_enum)
  {
    /* MinMax: '<S484>/MinMax1' */
    VOPM_IntLfAntDiagStat_enum = VOPM_BCMBackLiFltFb_enum;
  }
  else
  {
    /* MinMax: '<S484>/MinMax1' */
    VOPM_IntLfAntDiagStat_enum = KOPM_IntLfAntDiagStatLo_enum;
  }

  /* End of MinMax: '<S484>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_IntLfAntDiagStat_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMRrFogLiFltFb_enum' */
  /* Switch: '<S456>/Switch4' incorporates:
   *  Constant: '<S456>/sat3'
   */
  if (KOPM_BCMRrFogLiFltFb_enum_ovrdflg)
  {
    /* MinMax: '<S443>/MinMax' incorporates:
     *  Constant: '<S456>/sat4'
     *  MinMax: '<S377>/MinMax'
     */
    VOPM_BCMBackLiFltFb_enum = KOPM_BCMRrFogLiFltFb_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S443>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S456>/Data Type Conversion1'
     *  MinMax: '<S377>/MinMax'
     */
    VOPM_BCMBackLiFltFb_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
            ->BCM_RearFogLiFaultFb;
  }

  /* End of Switch: '<S456>/Switch4' */

  /* MinMax: '<S456>/MinMax' incorporates:
   *  Constant: '<S456>/sat6'
   */
  if (VOPM_BCMBackLiFltFb_enum > KOPM_BCMRrFogLiFltFbHi_enum)
  {
    /* MinMax: '<S443>/MinMax' */
    VOPM_BCMBackLiFltFb_enum = KOPM_BCMRrFogLiFltFbHi_enum;
  }

  /* End of MinMax: '<S456>/MinMax' */

  /* MinMax: '<S456>/MinMax1' incorporates:
   *  Constant: '<S456>/sat7'
   */
  if (VOPM_BCMBackLiFltFb_enum >= KOPM_BCMRrFogLiFltFbLo_enum)
  {
    /* MinMax: '<S456>/MinMax1' */
    VOPM_BCMRrFogLiFltFb_enum = VOPM_BCMBackLiFltFb_enum;
  }
  else
  {
    /* MinMax: '<S456>/MinMax1' */
    VOPM_BCMRrFogLiFltFb_enum = KOPM_BCMRrFogLiFltFbLo_enum;
  }

  /* End of MinMax: '<S456>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMRrFogLiFltFb_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMPosLiFltFb_enum' */
  /* Switch: '<S451>/Switch4' incorporates:
   *  Constant: '<S451>/sat3'
   */
  if (KOPM_BCMPosLiFltFb_enum_ovrdflg)
  {
    /* MinMax: '<S443>/MinMax' incorporates:
     *  Constant: '<S451>/sat4'
     *  MinMax: '<S377>/MinMax'
     */
    VOPM_BCMBackLiFltFb_enum = KOPM_BCMPosLiFltFb_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S443>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S451>/Data Type Conversion1'
     *  MinMax: '<S377>/MinMax'
     */
    VOPM_BCMBackLiFltFb_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_PosLiFaultFb;
  }

  /* End of Switch: '<S451>/Switch4' */

  /* MinMax: '<S451>/MinMax' incorporates:
   *  Constant: '<S451>/sat6'
   */
  if (VOPM_BCMBackLiFltFb_enum > KOPM_BCMPosLiFltFbHi_enum)
  {
    /* MinMax: '<S443>/MinMax' */
    VOPM_BCMBackLiFltFb_enum = KOPM_BCMPosLiFltFbHi_enum;
  }

  /* End of MinMax: '<S451>/MinMax' */

  /* MinMax: '<S451>/MinMax1' incorporates:
   *  Constant: '<S451>/sat7'
   */
  if (VOPM_BCMBackLiFltFb_enum >= KOPM_BCMPosLiFltFbLo_enum)
  {
    /* MinMax: '<S451>/MinMax1' */
    VOPM_BCMPosLiFltFb_enum = VOPM_BCMBackLiFltFb_enum;
  }
  else
  {
    /* MinMax: '<S451>/MinMax1' */
    VOPM_BCMPosLiFltFb_enum = KOPM_BCMPosLiFltFbLo_enum;
  }

  /* End of MinMax: '<S451>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMPosLiFltFb_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMHiBeamLiFltFb_enum' */
  /* Switch: '<S416>/Switch4' incorporates:
   *  Constant: '<S416>/sat3'
   */
  if (KOPM_BCMHiBeamLiFltFb_enum_ovrdflg)
  {
    /* MinMax: '<S443>/MinMax' incorporates:
     *  Constant: '<S416>/sat4'
     *  MinMax: '<S377>/MinMax'
     */
    VOPM_BCMBackLiFltFb_enum = KOPM_BCMHiBeamLiFltFb_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S443>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S416>/Data Type Conversion1'
     *  MinMax: '<S377>/MinMax'
     */
    VOPM_BCMBackLiFltFb_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
            ->BCM_HighBeamLiFaultFb;
  }

  /* End of Switch: '<S416>/Switch4' */

  /* MinMax: '<S416>/MinMax' incorporates:
   *  Constant: '<S416>/sat6'
   */
  if (VOPM_BCMBackLiFltFb_enum > KOPM_BCMHiBeamLiFltFbHi_enum)
  {
    /* MinMax: '<S443>/MinMax' */
    VOPM_BCMBackLiFltFb_enum = KOPM_BCMHiBeamLiFltFbHi_enum;
  }

  /* End of MinMax: '<S416>/MinMax' */

  /* MinMax: '<S416>/MinMax1' incorporates:
   *  Constant: '<S416>/sat7'
   */
  if (VOPM_BCMBackLiFltFb_enum >= KOPM_BCMHiBeamLiFltFbLo_enum)
  {
    /* MinMax: '<S416>/MinMax1' */
    VOPM_BCMHiBeamLiFltFb_enum = VOPM_BCMBackLiFltFb_enum;
  }
  else
  {
    /* MinMax: '<S416>/MinMax1' */
    VOPM_BCMHiBeamLiFltFb_enum = KOPM_BCMHiBeamLiFltFbLo_enum;
  }

  /* End of MinMax: '<S416>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMHiBeamLiFltFb_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMLoBeamLiFltFb_enum' */
  /* Switch: '<S440>/Switch4' incorporates:
   *  Constant: '<S440>/sat3'
   */
  if (KOPM_BCMLoBeamLiFltFb_enum_ovrdflg)
  {
    /* MinMax: '<S443>/MinMax' incorporates:
     *  Constant: '<S440>/sat4'
     *  MinMax: '<S377>/MinMax'
     */
    VOPM_BCMBackLiFltFb_enum = KOPM_BCMLoBeamLiFltFb_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S443>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S440>/Data Type Conversion1'
     *  MinMax: '<S377>/MinMax'
     */
    VOPM_BCMBackLiFltFb_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
            ->BCM_LowBeamLiFaultFb;
  }

  /* End of Switch: '<S440>/Switch4' */

  /* MinMax: '<S440>/MinMax' incorporates:
   *  Constant: '<S440>/sat6'
   */
  if (VOPM_BCMBackLiFltFb_enum > KOPM_BCMLoBeamLiFltFbHi_enum)
  {
    /* MinMax: '<S443>/MinMax' */
    VOPM_BCMBackLiFltFb_enum = KOPM_BCMLoBeamLiFltFbHi_enum;
  }

  /* End of MinMax: '<S440>/MinMax' */

  /* MinMax: '<S440>/MinMax1' incorporates:
   *  Constant: '<S440>/sat7'
   */
  if (VOPM_BCMBackLiFltFb_enum >= KOPM_BCMLoBeamLiFltFbLo_enum)
  {
    /* MinMax: '<S440>/MinMax1' */
    VOPM_BCMLoBeamLiFltFb_enum = VOPM_BCMBackLiFltFb_enum;
  }
  else
  {
    /* MinMax: '<S440>/MinMax1' */
    VOPM_BCMLoBeamLiFltFb_enum = KOPM_BCMLoBeamLiFltFbLo_enum;
  }

  /* End of MinMax: '<S440>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMLoBeamLiFltFb_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMFrntFogLiFltFb_enum' */
  /* Switch: '<S409>/Switch4' incorporates:
   *  Constant: '<S409>/sat3'
   */
  if (KOPM_BCMFrntFogLiFltFb_enum_ovrdflg)
  {
    /* MinMax: '<S443>/MinMax' incorporates:
     *  Constant: '<S409>/sat4'
     *  MinMax: '<S377>/MinMax'
     */
    VOPM_BCMBackLiFltFb_enum = KOPM_BCMFrntFogLiFltFb_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S443>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S409>/Data Type Conversion1'
     *  MinMax: '<S377>/MinMax'
     */
    VOPM_BCMBackLiFltFb_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
            ->BCM_FrontFogLiFaultFb;
  }

  /* End of Switch: '<S409>/Switch4' */

  /* MinMax: '<S409>/MinMax' incorporates:
   *  Constant: '<S409>/sat6'
   */
  if (VOPM_BCMBackLiFltFb_enum > KOPM_BCMFrntFogLiFltFbHi_enum)
  {
    /* MinMax: '<S443>/MinMax' */
    VOPM_BCMBackLiFltFb_enum = KOPM_BCMFrntFogLiFltFbHi_enum;
  }

  /* End of MinMax: '<S409>/MinMax' */

  /* MinMax: '<S409>/MinMax1' incorporates:
   *  Constant: '<S409>/sat7'
   */
  if (VOPM_BCMBackLiFltFb_enum >= KOPM_BCMFrntFogLiFltFbLo_enum)
  {
    /* MinMax: '<S409>/MinMax1' */
    VOPM_BCMFrntFogLiFltFb_enum = VOPM_BCMBackLiFltFb_enum;
  }
  else
  {
    /* MinMax: '<S409>/MinMax1' */
    VOPM_BCMFrntFogLiFltFb_enum = KOPM_BCMFrntFogLiFltFbLo_enum;
  }

  /* End of MinMax: '<S409>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMFrntFogLiFltFb_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMDayRunLiFltFb_enum' */
  /* Switch: '<S385>/Switch4' incorporates:
   *  Constant: '<S385>/sat3'
   */
  if (KOPM_BCMDayRunLiFltFb_enum_ovrdflg)
  {
    /* MinMax: '<S443>/MinMax' incorporates:
     *  Constant: '<S385>/sat4'
     *  MinMax: '<S377>/MinMax'
     */
    VOPM_BCMBackLiFltFb_enum = KOPM_BCMDayRunLiFltFb_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S443>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S385>/Data Type Conversion1'
     *  MinMax: '<S377>/MinMax'
     */
    VOPM_BCMBackLiFltFb_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
            ->BCM_DayRunLiFaultFb;
  }

  /* End of Switch: '<S385>/Switch4' */

  /* MinMax: '<S385>/MinMax' incorporates:
   *  Constant: '<S385>/sat6'
   */
  if (VOPM_BCMBackLiFltFb_enum > KOPM_BCMDayRunLiFltFbHi_enum)
  {
    /* MinMax: '<S443>/MinMax' */
    VOPM_BCMBackLiFltFb_enum = KOPM_BCMDayRunLiFltFbHi_enum;
  }

  /* End of MinMax: '<S385>/MinMax' */

  /* MinMax: '<S385>/MinMax1' incorporates:
   *  Constant: '<S385>/sat7'
   */
  if (VOPM_BCMBackLiFltFb_enum >= KOPM_BCMDayRunLiFltFbLo_enum)
  {
    /* MinMax: '<S385>/MinMax1' */
    VOPM_BCMDayRunLiFltFb_enum = VOPM_BCMBackLiFltFb_enum;
  }
  else
  {
    /* MinMax: '<S385>/MinMax1' */
    VOPM_BCMDayRunLiFltFb_enum = KOPM_BCMDayRunLiFltFbLo_enum;
  }

  /* End of MinMax: '<S385>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMDayRunLiFltFb_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMRvrsLiFltFb_enum' */
  /* Switch: '<S459>/Switch4' incorporates:
   *  Constant: '<S459>/sat3'
   */
  if (KOPM_BCMRvrsLiFltFb_enum_ovrdflg)
  {
    /* MinMax: '<S443>/MinMax' incorporates:
     *  Constant: '<S459>/sat4'
     *  MinMax: '<S377>/MinMax'
     */
    VOPM_BCMBackLiFltFb_enum = KOPM_BCMRvrsLiFltFb_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S443>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S459>/Data Type Conversion1'
     *  MinMax: '<S377>/MinMax'
     */
    VOPM_BCMBackLiFltFb_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
            ->BCM_ReverseLiFaultFb;
  }

  /* End of Switch: '<S459>/Switch4' */

  /* MinMax: '<S459>/MinMax' incorporates:
   *  Constant: '<S459>/sat6'
   */
  if (VOPM_BCMBackLiFltFb_enum > KOPM_BCMRvrsLiFltFbHi_enum)
  {
    /* MinMax: '<S443>/MinMax' */
    VOPM_BCMBackLiFltFb_enum = KOPM_BCMRvrsLiFltFbHi_enum;
  }

  /* End of MinMax: '<S459>/MinMax' */

  /* MinMax: '<S459>/MinMax1' incorporates:
   *  Constant: '<S459>/sat7'
   */
  if (VOPM_BCMBackLiFltFb_enum >= KOPM_BCMRvrsLiFltFbLo_enum)
  {
    /* MinMax: '<S459>/MinMax1' */
    VOPM_BCMRvrsLiFltFb_enum = VOPM_BCMBackLiFltFb_enum;
  }
  else
  {
    /* MinMax: '<S459>/MinMax1' */
    VOPM_BCMRvrsLiFltFb_enum = KOPM_BCMRvrsLiFltFbLo_enum;
  }

  /* End of MinMax: '<S459>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMRvrsLiFltFb_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMBrkLiFltFb_enum' */
  /* Switch: '<S381>/Switch4' incorporates:
   *  Constant: '<S381>/sat3'
   */
  if (KOPM_BCMBrkLiFltFb_enum_ovrdflg)
  {
    /* MinMax: '<S443>/MinMax' incorporates:
     *  Constant: '<S381>/sat4'
     *  MinMax: '<S377>/MinMax'
     */
    VOPM_BCMBackLiFltFb_enum = KOPM_BCMBrkLiFltFb_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S443>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S381>/Data Type Conversion1'
     *  MinMax: '<S377>/MinMax'
     */
    VOPM_BCMBackLiFltFb_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
            ->BCM_BrakeLiFaultFb;
  }

  /* End of Switch: '<S381>/Switch4' */

  /* MinMax: '<S381>/MinMax' incorporates:
   *  Constant: '<S381>/sat6'
   */
  if (VOPM_BCMBackLiFltFb_enum > KOPM_BCMBrkLiFltFbHi_enum)
  {
    /* MinMax: '<S443>/MinMax' */
    VOPM_BCMBackLiFltFb_enum = KOPM_BCMBrkLiFltFbHi_enum;
  }

  /* End of MinMax: '<S381>/MinMax' */

  /* MinMax: '<S381>/MinMax1' incorporates:
   *  Constant: '<S381>/sat7'
   */
  if (VOPM_BCMBackLiFltFb_enum >= KOPM_BCMBrkLiFltFbLo_enum)
  {
    /* MinMax: '<S381>/MinMax1' */
    VOPM_BCMBrkLiFltFb_enum = VOPM_BCMBackLiFltFb_enum;
  }
  else
  {
    /* MinMax: '<S381>/MinMax1' */
    VOPM_BCMBrkLiFltFb_enum = KOPM_BCMBrkLiFltFbLo_enum;
  }

  /* End of MinMax: '<S381>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMBrkLiFltFb_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMBackLiFltFb_enum' */
  /* Switch: '<S377>/Switch4' incorporates:
   *  Constant: '<S377>/sat3'
   */
  if (KOPM_BCMBackLiFltFb_enum_ovrdflg)
  {
    /* MinMax: '<S443>/MinMax' incorporates:
     *  Constant: '<S377>/sat4'
     *  MinMax: '<S377>/MinMax'
     */
    VOPM_BCMBackLiFltFb_enum = KOPM_BCMBackLiFltFb_enum_ovrdval;
  }
  else
  {
    /* MinMax: '<S443>/MinMax' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S377>/Data Type Conversion1'
     *  MinMax: '<S377>/MinMax'
     */
    VOPM_BCMBackLiFltFb_enum =
        (Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_BackLiFaultFb;
  }

  /* End of Switch: '<S377>/Switch4' */

  /* MinMax: '<S377>/MinMax' incorporates:
   *  Constant: '<S377>/sat6'
   */
  if (VOPM_BCMBackLiFltFb_enum > KOPM_BCMBackLiFltFbHi_enum)
  {
    /* MinMax: '<S443>/MinMax' */
    VOPM_BCMBackLiFltFb_enum = KOPM_BCMBackLiFltFbHi_enum;
  }

  /* End of MinMax: '<S377>/MinMax' */

  /* MinMax: '<S377>/MinMax1' incorporates:
   *  Constant: '<S377>/sat7'
   */
  if (VOPM_BCMBackLiFltFb_enum < KOPM_BCMBackLiFltFbLo_enum)
  {
    /* MinMax: '<S443>/MinMax' incorporates:
     *  MinMax: '<S377>/MinMax1'
     */
    VOPM_BCMBackLiFltFb_enum = KOPM_BCMBackLiFltFbLo_enum;
  }

  /* End of MinMax: '<S377>/MinMax1' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMBackLiFltFb_enum' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMDomeLghtSt_flg' */
  /* Switch: '<S388>/Switch4' incorporates:
   *  Constant: '<S388>/sat3'
   */
  if (KOPM_BCMDomeLghtSt_flg_ovrdflg)
  {
    /* Switch: '<S388>/Switch4' incorporates:
     *  Constant: '<S388>/sat4'
     */
    VOPM_BCMDomeLghtSt_flg = KOPM_BCMDomeLghtSt_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S388>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S388>/Data Type Conversion1'
     */
    VOPM_BCMDomeLghtSt_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_DomeLightSta != 0);
  }

  /* End of Switch: '<S388>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMDomeLghtSt_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMCarrgLghtSt_flg' */
  /* Switch: '<S382>/Switch4' incorporates:
   *  Constant: '<S382>/sat3'
   */
  if (KOPM_BCMCarrgLghtSt_flg_ovrdflg)
  {
    /* Switch: '<S382>/Switch4' incorporates:
     *  Constant: '<S382>/sat4'
     */
    VOPM_BCMCarrgLghtSt_flg = KOPM_BCMCarrgLghtSt_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S382>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S382>/Data Type Conversion1'
     */
    VOPM_BCMCarrgLghtSt_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
             ->BCM_CarriageLightSta != 0);
  }

  /* End of Switch: '<S382>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMCarrgLghtSt_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMBackLampSt_flg' */
  /* Switch: '<S376>/Switch4' incorporates:
   *  Constant: '<S376>/sat3'
   */
  if (KOPM_BCMBackLampSt_flg_ovrdflg)
  {
    /* Switch: '<S376>/Switch4' incorporates:
     *  Constant: '<S376>/sat4'
     */
    VOPM_BCMBackLampSt_flg = KOPM_BCMBackLampSt_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S376>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S376>/Data Type Conversion1'
     */
    VOPM_BCMBackLampSt_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_BackLampSta != 0);
  }

  /* End of Switch: '<S376>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMBackLampSt_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMWiprStopPstnSt_flg' */
  /* Switch: '<S482>/Switch4' incorporates:
   *  Constant: '<S482>/sat3'
   */
  if (KOPM_BCMWiprStopPstnSt_flg_ovrdflg)
  {
    /* Switch: '<S482>/Switch4' incorporates:
     *  Constant: '<S482>/sat4'
     */
    VOPM_BCMWiprStopPstnSt_flg = KOPM_BCMWiprStopPstnSt_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S482>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S482>/Data Type Conversion1'
     */
    VOPM_BCMWiprStopPstnSt_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())
             ->BCM_WiperStopPosSta != 0);
  }

  /* End of Switch: '<S482>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMWiprStopPstnSt_flg' */

  /* Outputs for Atomic SubSystem: '<S349>/Subsys_VOPM_BCMSavePwrSt_flg' */
  /* Switch: '<S460>/Switch4' incorporates:
   *  Constant: '<S460>/sat3'
   */
  if (KOPM_BCMSavePwrSt_flg_ovrdflg)
  {
    /* Switch: '<S460>/Switch4' incorporates:
     *  Constant: '<S460>/sat4'
     */
    VOPM_BCMSavePwrSt_flg = KOPM_BCMSavePwrSt_flg_ovrdval;
  }
  else
  {
    /* Switch: '<S460>/Switch4' incorporates:
     *  DataTransferBlock generated from: '<Root>/OpmRx'
     *  DataTypeConversion: '<S460>/Data Type Conversion1'
     */
    VOPM_BCMSavePwrSt_flg =
        ((Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs())->BCM_SavePowerSta != 0);
  }

  /* End of Switch: '<S460>/Switch4' */
  /* End of Outputs for SubSystem: '<S349>/Subsys_VOPM_BCMSavePwrSt_flg' */

  /* BusCreator: '<S349>/BusCreator' incorporates:
   *  Constant: '<S349>/Constant'
   *  Constant: '<S349>/Constant2'
   *  Switch: '<S369>/Switch4'
   *  Switch: '<S370>/Switch4'
   *  Switch: '<S371>/Switch4'
   *  Switch: '<S372>/Switch4'
   *  Switch: '<S374>/Switch4'
   *  Switch: '<S375>/Switch4'
   *  Switch: '<S380>/Switch4'
   *  Switch: '<S386>/Switch4'
   *  Switch: '<S387>/Switch4'
   *  Switch: '<S389>/Switch4'
   *  Switch: '<S390>/Switch4'
   *  Switch: '<S391>/Switch4'
   *  Switch: '<S392>/Switch4'
   *  Switch: '<S398>/Switch4'
   *  Switch: '<S402>/Switch4'
   *  Switch: '<S406>/Switch4'
   *  Switch: '<S407>/Switch4'
   *  Switch: '<S410>/Switch4'
   *  Switch: '<S414>/Switch4'
   *  Switch: '<S415>/Switch4'
   *  Switch: '<S418>/Switch4'
   *  Switch: '<S419>/Switch4'
   *  Switch: '<S420>/Switch4'
   *  Switch: '<S421>/Switch4'
   *  Switch: '<S427>/Switch4'
   *  Switch: '<S429>/Switch4'
   *  Switch: '<S431>/Switch4'
   *  Switch: '<S436>/Switch4'
   *  Switch: '<S442>/Switch4'
   *  Switch: '<S445>/Switch4'
   *  Switch: '<S447>/Switch4'
   *  Switch: '<S448>/Switch4'
   *  Switch: '<S450>/Switch4'
   *  Switch: '<S454>/Switch4'
   *  Switch: '<S457>/Switch4'
   *  Switch: '<S465>/Switch4'
   *  Switch: '<S466>/Switch4'
   *  Switch: '<S468>/Switch4'
   *  Switch: '<S469>/Switch4'
   *  Switch: '<S470>/Switch4'
   *  Switch: '<S474>/Switch4'
   *  Switch: '<S475>/Switch4'
   *  Switch: '<S476>/Switch4'
   *  Switch: '<S477>/Switch4'
   *  Switch: '<S486>/Switch4'
   */
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_TurnLampSta_Left =
      VOPM_BCMTurnLampStaLeft_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_TurnLampSta_Right =
      VOPM_BCMTurnLampStaRight_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_FogLampSta_Rear =
      VOPM_BCMFogLampStaRear_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_HighBeamSta =
      VOPM_BCMHighBeamSta_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_LowBeamSta = VOPM_BCMLowBeamSta_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_FogLampSta_Front =
      VOPM_BCMFogLampStaFront_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_AutoLampStatus =
      VOPM_BCMAutoLampStatus_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_DayRunLightSta =
      VOPM_BCMDayRunLightSta_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_ReverseLampSta =
      VOPM_BCMReverseLampSta_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_BrakeLampSta =
      VOPM_BCMBrakeLampSta_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_DayRunLiSwSig =
      VOPM_BCMDayRunLiSwSig_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_TurnLiSts = VOPM_BCMTurnLiSts_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_TurnngLiSwSig =
      u8PE_Auth_FobStatus; // VOPM_BCMTrnngLiSwSig_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_LightIntensity =
      VOPM_BCMLightIntensity_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_LightSwSig = u8PS_Auth_FobStatus; // VOPM_BCMLghtSwSig_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_HighBeamSwSig =
      VOPM_BCMHiBeamSwSig_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_AjarStaV_Hood =
      VOPM_BCMAjarStaVHoodVld_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_AjarSta_Hood =
      VOPM_BCMAjarStaHood_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_HazardWarningLightSwSig =
      VOPM_BCMHzrdWrngLghtSwSig_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_FrntFogLiSwSig =
      VOPM_BCMFrntFogLiSwSig_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_RearFogLiSwSig =
      VOPM_BCMRrFogLiSwSig_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_FlwrMeHmCtrlFb =
      VOPM_BCMFlwrMeHmCtrlFb_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_BassHornReq =
      VOPM_BCMBassHornReq_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_AjarSta_Trunk =
      VOPM_BCMAjarStaTrunk_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_DoorAjarSta_FL =
      VOPM_BCMDoorAjarStaFL_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_DoorAjarSta_FR =
      VOPM_BCMDoorAjarStaFR_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_DoorAjarSta_RL =
      VOPM_BCMDoorAjarStaRL_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_DoorAjarSta_RR =
      VOPM_BCMDoorAjarStaRR_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_LockHornOnStFb =
      VOPM_BCMLckHornOnStFb_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_AlrmHornReq =
      VOPM_BCMAlrmHornReq_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.TPMS_TempSts_FL = false;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.TPMS_PressureSta_FL =
      VOPM_TPMSPressureStaFL_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.TPMS_TempSts_FR = false;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.TPMS_PressureSta_FR =
      VOPM_TPMSPressureStaFR_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.TPMS_PressureValue_FL = 0U;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.TPMS_PressureValue_FR = 0U;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.TPMS_TireTempValue_FL = GetFobKeyCmdRequest();
  // 60U;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.TPMS_TireTempValue_FR = u8FobKeyEnterWorkState; // 60U;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_TPMSResetSts =
      VOPM_BCMTPMSRstSts_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.TMPS_AbnmPrsrWarn =
      VOPM_TMPSAbnmPrsrWarn_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.TPMS_TempSts_RL = u8FobKey_Disable_Status_Feedback;
  // false;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.TPMS_PressureSta_RL =
      VOPM_TPMSPressureStaRL_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.TPMS_TempSts_RR = false;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.TPMS_PressureSta_RR =
      VOPM_TPMSPressureStaRR_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.TPMS_PressureValue_RL = RxNum2910; // 0U;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.TPMS_PressureValue_RR = 0U;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.TPMS_TireTempValue_RL = 60U;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.TPMS_TireTempValue_RR = 60U;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_WiperCtrl_Front =
      VOPM_BCMWiperCtrlFront_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_WashLiquidLevelWarn =
      VOPM_BCMWashLiquidLvlWarn_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_DrvSeatOccupantSensorSts =
      VOPM_BCMDrvSeatOccptSnsrSts_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_HeavyRainInd =
      VOPM_BCMHvyRainInd_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_FrntWshrSwSig =
      VOPM_BCMFrntWshrSwSig_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_Pas_wdw_Init =
      VOPM_BCMPaswdwInit_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_FrontWashSts =
      VOPM_BCMFrontWashSts_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_WiprIntlGearSwtSig = u8PS_Auth_KeyPosReq;
  // VOPM_BCMWiprIntlGrSwtSig_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_WiperSwSig = u8PE_Auth_KeyPosReq;
  // VOPM_BCMWiperSwSig_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_WinLockSts = VOPM_BCMWinLockSts_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_WinLockSig = VOPM_BCMWinLockSig_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_DriverWinSwSig =
      VOPM_BCMDrvrWinSwSig_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_PassWinSwSig =
      VOPM_BCMPassWinSwSig_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_FLWindowSts = VOPM_BCMFLWinSts_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_FRWindowSts = VOPM_BCMFRWinSts_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_FLWindowmotorSts =
      VOPM_BCMFLWinmotorSts_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_FRWindowmotorSts =
      VOPM_BCMFRWinmotorSts_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_FrntLeDoorHndlSwt =
      VOPM_BCMFrntLeDoorHndlSwt_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_FrntRiDoorHndlSwt =
      VOPM_BCMFrntRiDoorHndlSwt_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_TrunkSwtSig =
      VOPM_BCMTrunkSwtSig_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_WarnNoKeyFound =
      VOPM_BCMWarnNoKeyFound_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_BodyWarnSts =
      VOPM_BCMBodyWarnSts_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_PSAuthentRes =
      VOPM_BCMPSAuthentRes_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_ChrgLidLockReq =
      VOPM_BCMChrgLidLockReq_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_RKEReq = VOPM_BCMRKEReq_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_KeyInCarSta =
      VOPM_BCMKeyInCarSta_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_DrvPEAuthentAcsd =
      VOPM_BCMDrvPEAuthentAcsd_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_FRPEAuthentAcsd =
      VOPM_BCMFRPEAuthentAcsd_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_PSReq = VOPM_BCMPSReq_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_WiprIntlTimeSetFb =
      VOPM_BCMWiprIntlTimeSetFb_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_StartReq = VOPM_BCMStartReq_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_ChgWiperMtMdSwSetFb =
      VOPM_BCMChgWiprMtMdSwSetFb_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_ParkAutoUnlockSetFb =
      VOPM_BCMParkAutoUnlckSetFb_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_OverspdCntrlLockSetFb =
      VOPM_BCMOvrspdCntrlLckSetFb_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_TrunkLockSta =
      VOPM_BCMTrnkLckSta_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_TrunkLockSwCtrlFb =
      VOPM_BCMTrnkLckSwCtrlFb_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_AuthentKeyNr =
      VOPM_BCMAuthentKeyNr_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_KeyFrbdn = VOPM_BCMKeyFrbdn_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_FrbdnKeyNr =
      VOPM_BCMFrbdnKeyNr_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_KeyIDFb = VOPM_BCMKeyIDFb_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_KeyLocn = VOPM_BCMKeyLocn_mm;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_IllmndEntryStsFb =
      VOPM_BCMIllmndEntryStsFb_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_AvaluebleKeyInCar =
      VOPM_BCMAvaluebleKeyInCar_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_KeyBattLvlSts =
      VOPM_BCMKeyBattLvlSts_flg;

  /* DataTypeConversion: '<S349>/DataTypeConversion92' incorporates:
   *  Constant: '<S500>/Constant1'
   *  Product: '<S500>/Product1'
   *  Sum: '<S500>/Add'
   */
  tmp = VOPM_BCMKeyBattLvl_pct * 10.0F;
  if (tmp < 65536.0F)
  {
    if (tmp >= 0.0F)
    {
      /* BusCreator: '<S349>/BusCreator' */
      AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_KeyBattLvl = (uint16)tmp;
    }
    else
    {
      /* BusCreator: '<S349>/BusCreator' */
      AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_KeyBattLvl = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S349>/BusCreator' */
    AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_KeyBattLvl = MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<S349>/DataTypeConversion92' */

  /* BusCreator: '<S349>/BusCreator' incorporates:
   *  Switch: '<S422>/Switch4'
   *  Switch: '<S425>/Switch4'
   *  Switch: '<S426>/Switch4'
   *  Switch: '<S432>/Switch4'
   *  Switch: '<S473>/Switch4'
   */
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_KeyLoBattLvlWarn =
      VOPM_BCMKeyLoBattLvlWarn_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_KeySta = VOPM_BCMKeySta_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_IllmndLampReq =
      VOPM_BCMIllmndLampReq_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_IllmndLockReq =
      VOPM_BCMIllmndLockReq_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_IndicationShifttoNeutral =
      VOPM_BCMIndcnShfttoNeut_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_WarnKeyOutReminder =
      VOPM_BCMWarnKeyOutRmndr_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_IndicationKeyCloser =
      VOPM_BCMIndcnKeyClsr_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_IllmndSts = VOPM_BCMIllmndSts_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_SteerWhlHeatSts =
      VOPM_BCMSteerWhlHeatSts_flg;

  /* DataTypeConversion: '<S349>/DataTypeConversion102' incorporates:
   *  Constant: '<S501>/Constant'
   *  Sum: '<S501>/Add'
   */
  if (VOPM_BCMSteerWhlTemp_C - -40.0F < 256.0F)
  {
    if (VOPM_BCMSteerWhlTemp_C - -40.0F >= 0.0F)
    {
      /* BusCreator: '<S349>/BusCreator' */
      AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_SteerWhlTemp = (uint8)(VOPM_BCMSteerWhlTemp_C - -40.0F);
    }
    else
    {
      /* BusCreator: '<S349>/BusCreator' */
      AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_SteerWhlTemp = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S349>/BusCreator' */
    AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_SteerWhlTemp = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S349>/DataTypeConversion102' */

  /* DataTypeConversion: '<S349>/DataTypeConversion103' incorporates:
   *  Constant: '<S493>/Constant'
   *  Sum: '<S493>/Add'
   */
  if (VOPM_BCMMaiDrvrSeatTemp_C - -40.0F < 256.0F)
  {
    if (VOPM_BCMMaiDrvrSeatTemp_C - -40.0F >= 0.0F)
    {
      /* BusCreator: '<S349>/BusCreator' */
      AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_MaiDrvrSeatTemp = (uint8)(VOPM_BCMMaiDrvrSeatTemp_C - -40.0F);
    }
    else
    {
      /* BusCreator: '<S349>/BusCreator' */
      AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_MaiDrvrSeatTemp = 0U;
    }
  }
  else
  {
    /* BusCreator: '<S349>/BusCreator' */
    AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_MaiDrvrSeatTemp = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S349>/DataTypeConversion103' */

  /* BusCreator: '<S349>/BusCreator' incorporates:
   *  Switch: '<S376>/Switch4'
   *  Switch: '<S382>/Switch4'
   *  Switch: '<S388>/Switch4'
   *  Switch: '<S400>/Switch4'
   *  Switch: '<S404>/Switch4'
   *  Switch: '<S435>/Switch4'
   *  Switch: '<S452>/Switch4'
   *  Switch: '<S458>/Switch4'
   *  Switch: '<S460>/Switch4'
   *  Switch: '<S472>/Switch4'
   *  Switch: '<S482>/Switch4'
   */
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_RearMirrorHeatSts =
      VOPM_BCMRrMirrHeatSts_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_MaiDrvrSeatSts =
      VOPM_BCMMaiDrvrSeatSts_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_FrontWiperMotorSts =
      VOPM_BCMFrntWiprMotSts_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_LogoActiveFlag =
      VOPM_BCMLogoActvFlg_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_VhclSeek = VOPM_BCMVehSeek_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_RFInitSta = status2910; // VOPM_BCMRFInitSta_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_RiTurnLiFaultFb =
      VOPM_BCMRiTrnLiFltFb_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_LeTurnLiFaultFb =
      VOPM_BCMLeTrnLiFltFb_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_FLWindowmotorFlags =
      VOPM_BCMFLWinmotor_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_FRWindowmotorFlags =
      VOPM_BCMFRWinmotor_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_DrvPassWinSwSig =
      VOPM_BCMDrvPassWinSwSig_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_DoorLockOperationRecord =
      VOPM_BCMDoorLckOpRec_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_LFInitSta = status29c0;
  // VOPM_BCMLFInitSta_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.DrvLfAnt_DiagStatus =
      VOPM_DrvLfAntDiagStat_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.PassLfAnt_DiagStatus =
      VOPM_PassLfAntDiagStat_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.IntLfAnt_DiagStatus =
      VOPM_IntLfAntDiagStat_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_RearFogLiFaultFb =
      VOPM_BCMRrFogLiFltFb_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_PosLiFaultFb =
      VOPM_BCMPosLiFltFb_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_HighBeamLiFaultFb =
      VOPM_BCMHiBeamLiFltFb_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_LowBeamLiFaultFb =
      VOPM_BCMLoBeamLiFltFb_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_FrontFogLiFaultFb =
      VOPM_BCMFrntFogLiFltFb_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_DayRunLiFaultFb =
      VOPM_BCMDayRunLiFltFb_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_ReverseLiFaultFb =
      VOPM_BCMRvrsLiFltFb_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_BrakeLiFaultFb =
      VOPM_BCMBrkLiFltFb_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_BackLiFaultFb =
      VOPM_BCMBackLiFltFb_enum;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_DomeLightSta =
      VOPM_BCMDomeLghtSt_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_CarriageLightSta =
      VOPM_BCMCarrgLghtSt_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_BackLampSta =
      VOPM_BCMBackLampSt_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_WiperStopPosSta =
      VOPM_BCMWiprStopPstnSt_flg;
  AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f.BCM_SavePowerSta =
      VOPM_BCMSavePwrSt_flg;
}

/* Model step function for TID1 */
void Runbl_OpmRx_10ms(void) /* Explicit Task: Runbl_OpmRx_10ms */
{
  DT_Bcm2OpmBAC_outputs rtb_Bcm2OpmBAC_outputs;
  DT_Vcu2OpmBAC_outputs rtb_Vcu2OpmBAC_outputs;
  DT_Vcu2OpmCHA_outputs rtb_Vcu2OpmCHA_outputs;
  DT_Vcu2OpmEPT_outputs rtb_Vcu2OpmEPT_outputs;
  TMS2VCU_PPVAddSignalGroup_Outputs rtb_TMS2VCU_PPV_outputs;

  /* RootInportFunctionCallGenerator generated from: '<Root>/Runbl_OpmRx_10ms' incorporates:
   *  SubSystem: '<Root>/OpmRx'
   */
  /* SignalConversion generated from: '<S6>/Vcu2OpmEPT_outputs' incorporates:
   *  Inport: '<Root>/Vcu2OpmEPT_outputs'
   */
  rtb_Vcu2OpmEPT_outputs =
      *Rte_IRead_Runbl_OpmRx_10ms_Vcu2OpmEPT_outputs_Vcu2OpmEPT_outputs();

  /* SignalConversion generated from: '<S6>/Vcu2OpmCHA_outputs' incorporates:
   *  Inport: '<Root>/Vcu2OpmCHA_outputs'
   */
  rtb_Vcu2OpmCHA_outputs =
      *Rte_IRead_Runbl_OpmRx_10ms_Vcu2OpmCHA_outputs_Vcu2OpmCHA_outputs();

  /* SignalConversion generated from: '<S6>/Vcu2OpmBAC_outputs' incorporates:
   *  Inport: '<Root>/Vcu2OpmBAC_outputs'
   */
  rtb_Vcu2OpmBAC_outputs =
      *Rte_IRead_Runbl_OpmRx_10ms_Vcu2OpmBAC_outputs_Vcu2OpmBAC_outputs();

  /* SignalConversion generated from: '<S6>/Bcm2OpmBAC_outputs' incorporates:
   *  Inport: '<Root>/Bcm2OpmBAC_outputs'
   */
  rtb_Bcm2OpmBAC_outputs =
      *Rte_IRead_Runbl_OpmRx_10ms_Bcm2OpmBAC_outputs_Bcm2OpmBAC_outputs();

  /* SignalConversion generated from: '<S6>/TMS2VCU_PPV_outputs' incorporates:
   *  Inport: '<Root>/TMS2VCU_PPV_outputs'
   */
  rtb_TMS2VCU_PPV_outputs =
      *Rte_IRead_Runbl_OpmRx_10ms_TMS2VCU_PPV_outputs_TMS2VCU_PPV_outputs();

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/Runbl_OpmRx_10ms' */

  /* DataTransferBlock generated from: '<Root>/OpmRx' */
  Rte_IrvIWrite_Runbl_OpmRx_10ms_Vcu2OpmEPT_outputs(&rtb_Vcu2OpmEPT_outputs);

  /* DataTransferBlock generated from: '<Root>/OpmRx' */
  Rte_IrvIWrite_Runbl_OpmRx_10ms_Vcu2OpmCHA_outputs(&rtb_Vcu2OpmCHA_outputs);

  /* DataTransferBlock generated from: '<Root>/OpmRx' */
  Rte_IrvIWrite_Runbl_OpmRx_10ms_Vcu2OpmBAC_outputs(&rtb_Vcu2OpmBAC_outputs);

  /* DataTransferBlock generated from: '<Root>/OpmRx' */
  Rte_IrvIWrite_Runbl_OpmRx_10ms_Bcm2OpmBAC_outputs(&rtb_Bcm2OpmBAC_outputs);

  /* DataTransferBlock generated from: '<Root>/OpmRx' */
  Rte_IrvIWrite_Runbl_OpmRx_10ms_TMS2VCU_PPV_outputs(&rtb_TMS2VCU_PPV_outputs);
}

/* Model step function for TID2 */
void Runbl_OpmCanTx_10ms(void) /* Explicit Task: Runbl_OpmCanTx_10ms */
{
  /* RootInportFunctionCallGenerator generated from: '<Root>/Runbl_OpmCanTx_10ms' incorporates:
   *  SubSystem: '<Root>/Opm10ms'
   */
  Runbl_Opm10ms();

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/Runbl_OpmCanTx_10ms' */

  /* Outport: '<Root>/VCU_0_Value_EPT' */
  Rte_IWrite_Runbl_OpmCanTx_10ms_VCU_0_Value_EPT_VCU_0_Value_EPT(&AppSwcOpm_ARID_DEF.VCU_0_Value_EPT_m);

  /* Outport: '<Root>/VCU_1_InvCmd_EPT' */
  Rte_IWrite_Runbl_OpmCanTx_10ms_VCU_1_InvCmd_EPT_VCU_1_InvCmd_EPT(&AppSwcOpm_ARID_DEF.VCU_1_InvCmd_EPT_g);

  /* Outport: '<Root>/VCU_10_Torque_CHA' */
  Rte_IWrite_Runbl_OpmCanTx_10ms_VCU_10_Torque_CHA_VCU_10_Torque_CHA(&AppSwcOpm_ARID_DEF.VCU_10_Torque_CHA_j);
}

/* Model step function for TID3 */
void Runbl_OpmCanTx_20ms(void) /* Explicit Task: Runbl_OpmCanTx_20ms */
{
  /* RootInportFunctionCallGenerator generated from: '<Root>/Runbl_OpmCanTx_20ms' incorporates:
   *  SubSystem: '<Root>/Opm20ms'
   */
  Runbl_Opm20ms();

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/Runbl_OpmCanTx_20ms' */

  /* Outport: '<Root>/VCU_3_OprtCmd_EPT' */
  Rte_IWrite_Runbl_OpmCanTx_20ms_VCU_3_OprtCmd_EPT_VCU_3_OprtCmd_EPT(&AppSwcOpm_ARID_DEF.VCU_3_OprtCmd_EPT_k);

  /* Outport: '<Root>/VCU_4_ChrgCmd_EPT' */
  Rte_IWrite_Runbl_OpmCanTx_20ms_VCU_4_ChrgCmd_EPT_VCU_4_ChrgCmd_EPT(&AppSwcOpm_ARID_DEF.VCU_4_ChrgCmd_EPT_j);

  /* Outport: '<Root>/VCU_B_AcclPedal_EPT' */
  Rte_IWrite_Runbl_OpmCanTx_20ms_VCU_B_AcclPedal_EPT_VCU_B_AcclPedal_EPT(&AppSwcOpm_ARID_DEF.VCU_B_AcclPedal_EPT_e);

  /* Outport: '<Root>/VCU_C_OprtCmd_EPT' */
  Rte_IWrite_Runbl_OpmCanTx_20ms_VCU_C_OprtCmd_EPT_VCU_C_OprtCmd_EPT(&AppSwcOpm_ARID_DEF.VCU_C_OprtCmd_EPT_m);

  /* Outport: '<Root>/VCU_DispInfo_BAC' */
  Rte_IWrite_Runbl_OpmCanTx_20ms_VCU_DispInfo_BAC_VCU_DispInfo_BAC(&AppSwcOpm_ARID_DEF.VCU_DispInfo_BAC_l);

  /* Outport: '<Root>/VCU_D_Status_CHA' */
  Rte_IWrite_Runbl_OpmCanTx_20ms_VCU_D_Status_CHA_VCU_D_Status_CHA(&AppSwcOpm_ARID_DEF.VCU_D_Status_CHA_a);
}

/* Model step function for TID4 */
void Runbl_OpmCanTx_50ms(void) /* Explicit Task: Runbl_OpmCanTx_50ms */
{
  /* RootInportFunctionCallGenerator generated from: '<Root>/Runbl_OpmCanTx_50ms' incorporates:
   *  SubSystem: '<Root>/Opm50ms'
   */
  Runbl_Opm50ms();

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/Runbl_OpmCanTx_50ms' */

  /* Outport: '<Root>/BCM_B_Package_BAC' */
  Rte_IWrite_Runbl_OpmCanTx_50ms_BCM_B_Package_BAC_BCM_B_Package_BAC(&AppSwcOpm_ARID_DEF.BCM_B_Package_BAC_f);

  /* Outport: '<Root>/CCU_VehInfo_BAC' */
  Rte_IWrite_Runbl_OpmCanTx_50ms_CCU_VehInfo_BAC_CCU_VehInfo_BAC(&AppSwcOpm_ARID_DEF.CCU_VehInfo_BAC_i);
}

/* Model step function for TID5 */
void Runbl_OpmCanTx_100ms(void) /* Explicit Task: Runbl_OpmCanTx_100ms */
{
  /* RootInportFunctionCallGenerator generated from: '<Root>/Runbl_OpmCanTx_100ms' incorporates:
   *  SubSystem: '<Root>/Opm100ms'
   */
  Runbl_Opm100ms();

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/Runbl_OpmCanTx_100ms' */

  /* Outport: '<Root>/BCM_IMMOAuthResp1_EPT' */
  Rte_IWrite_Runbl_OpmCanTx_100ms_BCM_IMMOAuthResp1_EPT_BCM_IMMOAuthResp1_EPT(&AppSwcOpm_ARID_DEF.BCM_IMMOAuthResp1_EPT_n);

  /* Outport: '<Root>/BCM_HFSData_BAC' */
  Rte_IWrite_Runbl_OpmCanTx_100ms_BCM_HFSData_BAC_BCM_HFSData_BAC(&AppSwcOpm_ARID_DEF.BCM_HFSData_BAC_c);

  /* Outport: '<Root>/AC_1_Command_BOD' */
  Rte_IWrite_Runbl_OpmCanTx_100ms_AC_1_Command_BOD_AC_1_Command_BOD(&AppSwcOpm_ARID_DEF.AC_1_Command_BOD_n);

  /* Outport: '<Root>/AC_2_State_BOD' */
  Rte_IWrite_Runbl_OpmCanTx_100ms_AC_2_State_BOD_AC_2_State_BOD(&AppSwcOpm_ARID_DEF.AC_2_State_BOD_g);

  /* Outport: '<Root>/AC_3_State_BOD' */
  Rte_IWrite_Runbl_OpmCanTx_100ms_AC_3_State_BOD_AC_3_State_BOD(&AppSwcOpm_ARID_DEF.AC_3_State_BOD_k);

  /* Outport: '<Root>/AC_8_status_BOD' */
  Rte_IWrite_Runbl_OpmCanTx_100ms_AC_8_status_BOD_AC_8_status_BOD(&AppSwcOpm_ARID_DEF.AC_8_status_BOD_o);

  /* Outport: '<Root>/AC_ACStatuts_BOD' */
  Rte_IWrite_Runbl_OpmCanTx_100ms_AC_ACStatuts_BOD_AC_ACStatuts_BOD(&AppSwcOpm_ARID_DEF.AC_ACStatuts_BOD_g);

  /* Outport: '<Root>/AC_COMP_BOD' */
  Rte_IWrite_Runbl_OpmCanTx_100ms_AC_COMP_BOD_AC_COMP_BOD(&AppSwcOpm_ARID_DEF.AC_COMP_BOD_o);

  /* Outport: '<Root>/BCM_ESCLCommand_BOD' incorporates:
   *  BusCreator: '<S33>/BusCreator'
   */
  Rte_IWrite_Runbl_OpmCanTx_100ms_BCM_ESCLCommand_BOD_BCM_ESCLCommand_BOD(&AppSwcOpm_ARID_DEF.BCM_ESCLCommand_BOD_c);

  /* Outport: '<Root>/HVCH_Command_BOD' */
  Rte_IWrite_Runbl_OpmCanTx_100ms_HVCH_Command_BOD_HVCH_Command_BOD(&AppSwcOpm_ARID_DEF.HVCH_Command_BOD_k);

  /* Outport: '<Root>/TMS_LINTestData1_BOD' */
  Rte_IWrite_Runbl_OpmCanTx_100ms_TMS_LINTestData1_BOD_TMS_LINTestData1_BOD(&AppSwcOpm_ARID_DEF.TMS_LINTestData1_BOD_f_m);

  /* Outport: '<Root>/TMS_LINTestData2_BOD' */
  Rte_IWrite_Runbl_OpmCanTx_100ms_TMS_LINTestData2_BOD_TMS_LINTestData2_BOD(&AppSwcOpm_ARID_DEF.TMS_LINTestData2_BOD_p);

  /* Outport: '<Root>/TMS_LINTestData3_BOD' */
  Rte_IWrite_Runbl_OpmCanTx_100ms_TMS_LINTestData3_BOD_TMS_LINTestData3_BOD(&AppSwcOpm_ARID_DEF.TMS_LINTestData3_BOD_a);
}

/* Model initialize function */
void AppSwcOpm_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
