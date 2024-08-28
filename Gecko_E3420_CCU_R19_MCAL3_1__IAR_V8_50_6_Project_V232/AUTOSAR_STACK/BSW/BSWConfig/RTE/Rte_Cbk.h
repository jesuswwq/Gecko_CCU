/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_Cbk.h>
 *  @brief      <>
 *  
 *  <MCU:E3420>
 *  
 *  @author     <>
 *  @date       <2024-07-16 14:43:10>
 */
/*============================================================================*/

/* Rte_Cbk.h */

#ifndef RTE_CBK_H
#define RTE_CBK_H

/*******************************************************************************
 **                        Revision Control History                           **
******************************************************************************/

/*******************************************************************************
 **                        Version Information                                **
******************************************************************************/

/*******************************************************************************
 **                        Include Section                                    **
******************************************************************************/
#include "Os.h"
#include "Com.h"
#include "Rte_Data.h"

/*******************************************************************************
 **                        Global Function Declarations                       **
******************************************************************************/

/*******************************************************************************
 **                        Global Function Definitions                        **
******************************************************************************/

void Rte_COMCbkRxTOut_BMS_2_BatState_EPT_IPDU_COM_BMS_2_BatState_EPT(void);

void Rte_COMCbkRxTOut_COMP_AC_BOD_IPDU_COM_COMP_AC_BOD(void);

void Rte_COMCbkRxTOut_CRRR_A_CHA_IPDU_COM_CRRR_A_CHA(void);

void Rte_COMCbkRxTOut_EPS_2_StrWhlAng_CHA_IPDU_COM_EPS_2_StrWhlAng_CHA(void);

void Rte_COMCbkRxTOut_ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5(void);

void Rte_COMCbkRxTOut_FCM_D_CHA_IPDU_COM_RX_FCM_D_CHA_CANFD3_CHA_CAN5(void);

void Rte_COMCbkRxTOut_HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1(void);

void Rte_COMCbkRxTOut_HVCH_Status1_BOD_IPDU_COM_HVCH_Status1_BOD(void);

void Rte_COMCbkRxTOut_ICU_2_Odo_BAC_IPDU_COM_ICU_2_Odo_BAC(void);

void Rte_COMCbkRxTOut_IPU_OBC_1_State_EPT_IPDU_COM_IPU_OBC_1_State_EPT(void);

void Rte_COMCbkRxTOut_PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5(void);

void Rte_COMCbkRxTOut_SRS_2_YRSOriginalSts_CHA_IPDU_COM_SRS_2_YRSOriginalSts_CHA(void);

void Rte_COMCbkRxTOut_TBOX_BJS_Time_BAC_IPDU_COM_TBOX_BJS_Time_BAC(void);

void Rte_COMCbkTxTOut_VCU_1_InvCmd_EPT_IPDU_COM_VCU_1_InvCmd_EPT(void);

void Rte_COMCbk_ACCM_Version_BOD_IPDU_COM_ACCM_Version_BOD(void);

void Rte_COMCbk_AcPMP_HWVersion_AcPMP_Version_LIN1(void);

void Rte_COMCbk_AcPMP_HWVersion_AcPMP_Version_LIN2(void);

void Rte_COMCbk_AcPMP_PartNumber_AcPMP_Version_LIN1(void);

void Rte_COMCbk_AcPMP_PartNumber_AcPMP_Version_LIN2(void);

void Rte_COMCbk_AcPMP_ProjectCode1_AcPMP_Version_LIN1(void);

void Rte_COMCbk_AcPMP_ProjectCode1_AcPMP_Version_LIN2(void);

void Rte_COMCbk_AcPMP_ProjectCode2_AcPMP_Version_LIN1(void);

void Rte_COMCbk_AcPMP_ProjectCode2_AcPMP_Version_LIN2(void);

void Rte_COMCbk_AcPMP_PumpDryRunningSta_AcPMP_Sts_LIN1(void);

void Rte_COMCbk_AcPMP_PumpDryRunningSta_AcPMP_Sts_LIN2(void);

void Rte_COMCbk_AcPMP_PumpInputVolt_AcPMP_Sts_LIN1(void);

void Rte_COMCbk_AcPMP_PumpInputVolt_AcPMP_Sts_LIN2(void);

void Rte_COMCbk_AcPMP_PumpMotorSta_AcPMP_Sts_LIN1(void);

void Rte_COMCbk_AcPMP_PumpMotorSta_AcPMP_Sts_LIN2(void);

void Rte_COMCbk_AcPMP_PumpPowerSta_AcPMP_Sts_LIN1(void);

void Rte_COMCbk_AcPMP_PumpPowerSta_AcPMP_Sts_LIN2(void);

void Rte_COMCbk_AcPMP_PumpTempSta_AcPMP_Sts_LIN1(void);

void Rte_COMCbk_AcPMP_PumpTempSta_AcPMP_Sts_LIN2(void);

void Rte_COMCbk_AcPMP_RESP_ERROR_AcPMP_Sts_LIN1(void);

void Rte_COMCbk_AcPMP_RESP_ERROR_AcPMP_Sts_LIN2(void);

void Rte_COMCbk_AcPMP_RealRPM_AcPMP_Sts_LIN1(void);

void Rte_COMCbk_AcPMP_RealRPM_AcPMP_Sts_LIN2(void);

void Rte_COMCbk_AcPMP_SWVersion_Main_AcPMP_Version_LIN1(void);

void Rte_COMCbk_AcPMP_SWVersion_Main_AcPMP_Version_LIN2(void);

void Rte_COMCbk_AcPMP_SWVersion_Patch_AcPMP_Version_LIN1(void);

void Rte_COMCbk_AcPMP_SWVersion_Patch_AcPMP_Version_LIN2(void);

void Rte_COMCbk_AcPMP_SWVersion_Sub_AcPMP_Version_LIN1(void);

void Rte_COMCbk_AcPMP_SWVersion_Sub_AcPMP_Version_LIN2(void);

void Rte_COMCbk_AcPMP_SupplierNumber_AcPMP_Version_LIN1(void);

void Rte_COMCbk_AcPMP_SupplierNumber_AcPMP_Version_LIN2(void);

void Rte_COMCbk_BAT_EXV_CurrentPosition_B_BAT_EXV_Rsp_LIN1(void);

void Rte_COMCbk_BAT_EXV_CurrentPosition_B_BAT_EXV_Rsp_LIN2(void);

void Rte_COMCbk_BAT_EXV_FaultState_B_BAT_EXV_Rsp_LIN1(void);

void Rte_COMCbk_BAT_EXV_FaultState_B_BAT_EXV_Rsp_LIN2(void);

void Rte_COMCbk_BAT_EXV_ResponseError_B_BAT_EXV_Rsp_LIN1(void);

void Rte_COMCbk_BAT_EXV_ResponseError_B_BAT_EXV_Rsp_LIN2(void);

void Rte_COMCbk_BAT_EXV_RunState_B_BAT_EXV_Rsp_LIN1(void);

void Rte_COMCbk_BAT_EXV_RunState_B_BAT_EXV_Rsp_LIN2(void);

void Rte_COMCbk_BAT_EXV_SupplierLabel_BAT_EXV_Rsp_LIN1(void);

void Rte_COMCbk_BAT_EXV_SupplierLabel_BAT_EXV_Rsp_LIN2(void);

void Rte_COMCbk_BAT_EXV_VoltageState_B_BAT_EXV_Rsp_LIN1(void);

void Rte_COMCbk_BAT_EXV_VoltageState_B_BAT_EXV_Rsp_LIN2(void);

void Rte_COMCbk_BAT_EXV_Warning_OverTemp_BAT_EXV_Rsp_LIN2(void);

void Rte_COMCbk_BAT_EXV_initialize_status_BAT_EXV_Rsp_LIN2(void);

void Rte_COMCbk_BMS_10_DC_ChargeStates_EPT_IPDU_COM_BMS_10_DC_ChargeStates_EPT(void);

void Rte_COMCbk_BMS_1_MainState_EPT_IPDU_COM_BMS_1_MainState_EPT(void);

void Rte_COMCbk_BMS_2_BatState_EPT_IPDU_COM_BMS_2_BatState_EPT(void);

void Rte_COMCbk_BMS_3_DC_ChargeState_EPT_IPDU_COM_BMS_3_DC_ChargeState_EPT(void);

void Rte_COMCbk_BMS_4_AC_ChargeState_EPT_IPDU_COM_BMS_4_AC_ChargeState_EPT(void);

void Rte_COMCbk_BMS_5_BatTemp_EPT_IPDU_COM_BMS_5_BatTemp_EPT(void);

void Rte_COMCbk_BMS_6_DischrgRecup_EPT_IPDU_COM_BMS_6_DischrgRecup_EPT(void);

void Rte_COMCbk_BMS_7_CellVolt_EPT_IPDU_COM_BMS_7_CellVolt_EPT(void);

void Rte_COMCbk_BMS_9_BattInfo_EPT_IPDU_COM_BMS_9_BattInfo_EPT(void);

void Rte_COMCbk_BatPMP_PumpDryRunningSta_BatPMP_Sts_LIN1(void);

void Rte_COMCbk_BatPMP_PumpDryRunningSta_BatPMP_Sts_LIN2(void);

void Rte_COMCbk_BatPMP_PumpInputVolt_BatPMP_Sts_LIN1(void);

void Rte_COMCbk_BatPMP_PumpInputVolt_BatPMP_Sts_LIN2(void);

void Rte_COMCbk_BatPMP_PumpMotorSta_BatPMP_Sts_LIN1(void);

void Rte_COMCbk_BatPMP_PumpMotorSta_BatPMP_Sts_LIN2(void);

void Rte_COMCbk_BatPMP_PumpPowerSta_BatPMP_Sts_LIN1(void);

void Rte_COMCbk_BatPMP_PumpPowerSta_BatPMP_Sts_LIN2(void);

void Rte_COMCbk_BatPMP_PumpTempSta_BatPMP_Sts_LIN1(void);

void Rte_COMCbk_BatPMP_PumpTempSta_BatPMP_Sts_LIN2(void);

void Rte_COMCbk_BatPMP_RESP_ERROR_BatPMP_Sts_LIN1(void);

void Rte_COMCbk_BatPMP_RESP_ERROR_BatPMP_Sts_LIN2(void);

void Rte_COMCbk_BatPMP_RealRPM_BatPMP_Sts_LIN1(void);

void Rte_COMCbk_BatPMP_RealRPM_BatPMP_Sts_LIN2(void);

void Rte_COMCbk_Bat_EXV_HWVersion_Bat_EXV_Version_LIN1(void);

void Rte_COMCbk_Bat_EXV_HWVersion_Bat_EXV_Version_LIN2(void);

void Rte_COMCbk_Bat_EXV_PartNumber_Bat_EXV_Version_LIN1(void);

void Rte_COMCbk_Bat_EXV_PartNumber_Bat_EXV_Version_LIN2(void);

void Rte_COMCbk_Bat_EXV_ProjectCode1_Bat_EXV_Version_LIN1(void);

void Rte_COMCbk_Bat_EXV_ProjectCode1_Bat_EXV_Version_LIN2(void);

void Rte_COMCbk_Bat_EXV_ProjectCode2_Bat_EXV_Version_LIN1(void);

void Rte_COMCbk_Bat_EXV_ProjectCode2_Bat_EXV_Version_LIN2(void);

void Rte_COMCbk_Bat_EXV_SWVersion_Main_Bat_EXV_Version_LIN1(void);

void Rte_COMCbk_Bat_EXV_SWVersion_Main_Bat_EXV_Version_LIN2(void);

void Rte_COMCbk_Bat_EXV_SWVersion_Patch_Bat_EXV_Version_LIN1(void);

void Rte_COMCbk_Bat_EXV_SWVersion_Patch_Bat_EXV_Version_LIN2(void);

void Rte_COMCbk_Bat_EXV_SWVersion_Sub_Bat_EXV_Version_LIN1(void);

void Rte_COMCbk_Bat_EXV_SWVersion_Sub_Bat_EXV_Version_LIN2(void);

void Rte_COMCbk_Bat_EXV_SupplierNumber_Bat_EXV_Version_LIN1(void);

void Rte_COMCbk_Bat_EXV_SupplierNumber_Bat_EXV_Version_LIN2(void);

void Rte_COMCbk_C3WV_ErrResp_C3WV_Sts_LIN2(void);

void Rte_COMCbk_C3WV_FltSts_C3WV_Sts_LIN2(void);

void Rte_COMCbk_C3WV_Mode_C3WV_Sts_LIN2(void);

void Rte_COMCbk_C3WV_PosRec_C3WV_Sts_LIN2(void);

void Rte_COMCbk_C3WV_RunSts_C3WV_Sts_LIN2(void);

void Rte_COMCbk_C3WV_SpdLvl_C3WV_Sts_LIN2(void);

void Rte_COMCbk_C3WV_TempSts_C3WV_Sts_LIN2(void);

void Rte_COMCbk_C3WV_VoltSts_C3WV_Sts_LIN2(void);

void Rte_COMCbk_C5WVFltSts_C5WV_Sts_LIN2(void);

void Rte_COMCbk_C5WVMode_C5WV_Sts_LIN2(void);

void Rte_COMCbk_C5WVPosRec_C5WV_Sts_LIN2(void);

void Rte_COMCbk_C5WVRunSts_C5WV_Sts_LIN2(void);

void Rte_COMCbk_C5WVSpdLvl_C5WV_Sts_LIN2(void);

void Rte_COMCbk_C5WVTempSts_C5WV_Sts_LIN2(void);

void Rte_COMCbk_C5WVVoltSts_C5WV_Sts_LIN2(void);

void Rte_COMCbk_CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD(void);

void Rte_COMCbk_COMP_AC_BOD_IPDU_COM_COMP_AC_BOD(void);

void Rte_COMCbk_CRRR_A_CHA_IPDU_COM_CRRR_A_CHA(void);

void Rte_COMCbk_EPS_2_StrWhlAng_CHA_IPDU_COM_EPS_2_StrWhlAng_CHA(void);

void Rte_COMCbk_ESCL_ESCLStatus_BOD_IPDU_COM_ESCL_ESCLStatus_BOD(void);

void Rte_COMCbk_ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5(void);

void Rte_COMCbk_EXV_CurrentInitState_AC_EXV_Rsp_LIN1(void);

void Rte_COMCbk_EXV_CurrentInitState_AC_EXV_Rsp_LIN2(void);

void Rte_COMCbk_EXV_CurrentPosition_AC_EXV_Rsp_LIN1(void);

void Rte_COMCbk_EXV_CurrentPosition_AC_EXV_Rsp_LIN2(void);

void Rte_COMCbk_EXV_FaultState_AC_EXV_Rsp_LIN1(void);

void Rte_COMCbk_EXV_FaultState_AC_EXV_Rsp_LIN2(void);

void Rte_COMCbk_EXV_ResponseError_AC_EXV_Rsp_LIN1(void);

void Rte_COMCbk_EXV_ResponseError_AC_EXV_Rsp_LIN2(void);

void Rte_COMCbk_EXV_RunState_AC_EXV_Rsp_LIN1(void);

void Rte_COMCbk_EXV_RunState_AC_EXV_Rsp_LIN2(void);

void Rte_COMCbk_EXV_TemperatureWarn_AC_EXV_Rsp_LIN1(void);

void Rte_COMCbk_EXV_TemperatureWarn_AC_EXV_Rsp_LIN2(void);

void Rte_COMCbk_EXV_VoltageState_AC_EXV_Rsp_LIN1(void);

void Rte_COMCbk_EXV_VoltageState_AC_EXV_Rsp_LIN2(void);

void Rte_COMCbk_ErrRespC5WV_C5WV_Sts_LIN2(void);

void Rte_COMCbk_FCLL_TiWngSt_FCLL_Status_LIN3(void);

void Rte_COMCbk_FCLR_TiWngSt_FCLR_Status_LIN3(void);

void Rte_COMCbk_FCM_D_CHA_IPDU_COM_RX_FCM_D_CHA_CANFD3_CHA_CAN5(void);

void Rte_COMCbk_HP_EXV_CurrentPosition_B_HP_EXV_Rsp_LIN2(void);

void Rte_COMCbk_HP_EXV_CurrentPosition_B_HP_EXV__Rsp_LIN1(void);

void Rte_COMCbk_HP_EXV_FaultState_B_HP_EXV_Rsp_LIN2(void);

void Rte_COMCbk_HP_EXV_FaultState_B_HP_EXV__Rsp_LIN1(void);

void Rte_COMCbk_HP_EXV_HWVersion_HP_EXV_Version_LIN1(void);

void Rte_COMCbk_HP_EXV_HWVersion_HP_EXV_Version_LIN2(void);

void Rte_COMCbk_HP_EXV_PartNumber_HP_EXV_Version_LIN1(void);

void Rte_COMCbk_HP_EXV_PartNumber_HP_EXV_Version_LIN2(void);

void Rte_COMCbk_HP_EXV_ProjectCode1_HP_EXV_Version_LIN1(void);

void Rte_COMCbk_HP_EXV_ProjectCode1_HP_EXV_Version_LIN2(void);

void Rte_COMCbk_HP_EXV_ProjectCode2_HP_EXV_Version_LIN1(void);

void Rte_COMCbk_HP_EXV_ProjectCode2_HP_EXV_Version_LIN2(void);

void Rte_COMCbk_HP_EXV_ResponseError_B_HP_EXV_Rsp_LIN2(void);

void Rte_COMCbk_HP_EXV_ResponseError_B_HP_EXV__Rsp_LIN1(void);

void Rte_COMCbk_HP_EXV_RunState_B_HP_EXV_Rsp_LIN2(void);

void Rte_COMCbk_HP_EXV_RunState_B_HP_EXV__Rsp_LIN1(void);

void Rte_COMCbk_HP_EXV_SWVersion_Main_HP_EXV_Version_LIN1(void);

void Rte_COMCbk_HP_EXV_SWVersion_Main_HP_EXV_Version_LIN2(void);

void Rte_COMCbk_HP_EXV_SWVersion_Patch_HP_EXV_Version_LIN1(void);

void Rte_COMCbk_HP_EXV_SWVersion_Patch_HP_EXV_Version_LIN2(void);

void Rte_COMCbk_HP_EXV_SWVersion_Sub_HP_EXV_Version_LIN1(void);

void Rte_COMCbk_HP_EXV_SWVersion_Sub_HP_EXV_Version_LIN2(void);

void Rte_COMCbk_HP_EXV_SupplierLabel_HP_EXV_Rsp_LIN2(void);

void Rte_COMCbk_HP_EXV_SupplierLabel_HP_EXV__Rsp_LIN1(void);

void Rte_COMCbk_HP_EXV_SupplierNumber_HP_EXV_Version_LIN1(void);

void Rte_COMCbk_HP_EXV_SupplierNumber_HP_EXV_Version_LIN2(void);

void Rte_COMCbk_HP_EXV_VoltageState_B_HP_EXV_Rsp_LIN2(void);

void Rte_COMCbk_HP_EXV_VoltageState_B_HP_EXV__Rsp_LIN1(void);

void Rte_COMCbk_HP_EXV_Warning_OverTemp_HP_EXV_Rsp_LIN2(void);

void Rte_COMCbk_HP_EXV_Warning_OverTemp_HP_EXV__Rsp_LIN1(void);

void Rte_COMCbk_HP_EXV_initialize_status_HP_EXV_Rsp_LIN2(void);

void Rte_COMCbk_HP_EXV_initialize_status_HP_EXV__Rsp_LIN1(void);

void Rte_COMCbk_HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1(void);

void Rte_COMCbk_HVCH_Status1_BOD_IPDU_COM_HVCH_Status1_BOD(void);

void Rte_COMCbk_HVCH_Status2_BOD_IPDU_COM_HVCH_Status2_BOD(void);

void Rte_COMCbk_ICU_2_Odo_BAC_IPDU_COM_ICU_2_Odo_BAC(void);

void Rte_COMCbk_INV_1_Value_EPT_IPDU_COM_INV_1_Value_EPT(void);

void Rte_COMCbk_INV_2_Value_EPT_IPDU_COM_INV_2_Value_EPT(void);

void Rte_COMCbk_INV_3_Value_EPT_IPDU_COM_INV_3_Value_EPT(void);

void Rte_COMCbk_INV_4_Value_EPT_IPDU_COM_INV_4_Value_EPT(void);

void Rte_COMCbk_INV_IMMO_Req_EPT_IPDU_COM_INV_IMMO_Req_EPT(void);

void Rte_COMCbk_IPU_DCC_1_State_EPT_IPDU_COM_IPU_DCC_1_State_EPT(void);

void Rte_COMCbk_IPU_DCC_2_ChrgInValue_EPT_IPDU_COM_IPU_DCC_2_ChrgInValue_EPT(void);

void Rte_COMCbk_IPU_OBC_1_State_EPT_IPDU_COM_IPU_OBC_1_State_EPT(void);

void Rte_COMCbk_IPU_OBC_2_Inlet_EPT_IPDU_COM_IPU_OBC_2_Inlet_EPT(void);

void Rte_COMCbk_MotPMP_PumpDryRunningSta_MotPMP_Sts_LIN1(void);

void Rte_COMCbk_MotPMP_PumpDryRunningSta_MotPMP_Sts_LIN2(void);

void Rte_COMCbk_MotPMP_PumpInputVolt_MotPMP_Sts_LIN1(void);

void Rte_COMCbk_MotPMP_PumpInputVolt_MotPMP_Sts_LIN2(void);

void Rte_COMCbk_MotPMP_PumpMotorSta_MotPMP_Sts_LIN1(void);

void Rte_COMCbk_MotPMP_PumpMotorSta_MotPMP_Sts_LIN2(void);

void Rte_COMCbk_MotPMP_PumpPowerSta_MotPMP_Sts_LIN1(void);

void Rte_COMCbk_MotPMP_PumpPowerSta_MotPMP_Sts_LIN2(void);

void Rte_COMCbk_MotPMP_PumpTempSta_MotPMP_Sts_LIN1(void);

void Rte_COMCbk_MotPMP_PumpTempSta_MotPMP_Sts_LIN2(void);

void Rte_COMCbk_MotPMP_RESP_ERROR_MotPMP_Sts_LIN1(void);

void Rte_COMCbk_MotPMP_RESP_ERROR_MotPMP_Sts_LIN2(void);

void Rte_COMCbk_MotPMP_RealRPM_MotPMP_Sts_LIN1(void);

void Rte_COMCbk_MotPMP_RealRPM_MotPMP_Sts_LIN2(void);

void Rte_COMCbk_PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5(void);

void Rte_COMCbk_SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD(void);

void Rte_COMCbk_SRS_2_YRSOriginalSts_CHA_IPDU_COM_SRS_2_YRSOriginalSts_CHA(void);

void Rte_COMCbk_TBOX_BJS_Time_BAC_IPDU_COM_TBOX_BJS_Time_BAC(void);

void Rte_COMCbk_VCU_1_InvCmd_EPT_IPDU_COM_VCU_1_InvCmd_EPT(void);

#endif

