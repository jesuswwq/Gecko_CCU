/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_ME11.c>
 *  @brief      <>
 *  
 *  <MCU:E3420>
 *  
 *  @author     <>
 *  @date       <2024-10-10 14:07:22>
 */
/*============================================================================*/

/* Rte_ME11.c */
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
#include "Rte_ME11.h"
#include "Rte_Data.h"
#include "Com.h"

/*******************************************************************************
 **                        Private Function Declarations                      **
******************************************************************************/

static void Rte_PRE_Task_100ms(void);

static void Rte_POST_Task_100ms(void);

/*******************************************************************************
 **                        Global Function Declarations                       **
******************************************************************************/

/*******************************************************************************
 **                        Private Function Definitions                       **
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
static void Rte_PRE_Task_100ms(void)
{
    if (RteInitState == RTE_INITED)
    {
        SuspendAllInterrupts();
        Rte_Inst_ME11.Task_100ms_AcPMP_HWVersion_AcPMP_HWVersion->value = Rte_Buf_Task_100ms_AcPMP_HWVersion_AcPMP_HWVersion;
        Rte_Inst_ME11.Task_100ms_AcPMP_PartNumber_AcPMP_PartNumber->value = Rte_Buf_Task_100ms_AcPMP_PartNumber_AcPMP_PartNumber;
        Rte_Inst_ME11.Task_100ms_AcPMP_ProjectCode1_AcPMP_ProjectCode1->value = Rte_Buf_Task_100ms_AcPMP_ProjectCode1_AcPMP_ProjectCode1;
        Rte_Inst_ME11.Task_100ms_AcPMP_ProjectCode2_AcPMP_ProjectCode2->value = Rte_Buf_Task_100ms_AcPMP_ProjectCode2_AcPMP_ProjectCode2;
        Rte_Inst_ME11.Task_100ms_AcPMP_PumpDryRunningSta_AcPMP_PumpDryRunningSta->value = Rte_Buf_Task_100ms_AcPMP_PumpDryRunningSta_AcPMP_PumpDryRunningSta;
        Rte_Inst_ME11.Task_100ms_AcPMP_PumpInputVolt_AcPMP_PumpInputVolt->value = Rte_Buf_Task_100ms_AcPMP_PumpInputVolt_AcPMP_PumpInputVolt;
        Rte_Inst_ME11.Task_100ms_AcPMP_PumpMotorSta_AcPMP_PumpMotorSta->value = Rte_Buf_Task_100ms_AcPMP_PumpMotorSta_AcPMP_PumpMotorSta;
        Rte_Inst_ME11.Task_100ms_AcPMP_PumpPowerSta_AcPMP_PumpPowerSta->value = Rte_Buf_Task_100ms_AcPMP_PumpPowerSta_AcPMP_PumpPowerSta;
        Rte_Inst_ME11.Task_100ms_AcPMP_PumpTempSta_AcPMP_PumpTempSta->value = Rte_Buf_Task_100ms_AcPMP_PumpTempSta_AcPMP_PumpTempSta;
        Rte_Inst_ME11.Task_100ms_AcPMP_RESP_ERROR_AcPMP_RESP_ERROR->value = Rte_Buf_Task_100ms_AcPMP_RESP_ERROR_AcPMP_RESP_ERROR;
        Rte_Inst_ME11.Task_100ms_AcPMP_RealRPM_AcPMP_RealRPM->value = Rte_Buf_Task_100ms_AcPMP_RealRPM_AcPMP_RealRPM;
        Rte_Inst_ME11.Task_100ms_AcPMP_SWVersion_Main_AcPMP_SWVersion_Main->value = Rte_Buf_Task_100ms_AcPMP_SWVersion_Main_AcPMP_SWVersion_Main;
        Rte_Inst_ME11.Task_100ms_AcPMP_SWVersion_Patch_AcPMP_SWVersion_Patch->value = Rte_Buf_Task_100ms_AcPMP_SWVersion_Patch_AcPMP_SWVersion_Patch;
        Rte_Inst_ME11.Task_100ms_AcPMP_SWVersion_Sub_AcPMP_SWVersion_Sub->value = Rte_Buf_Task_100ms_AcPMP_SWVersion_Sub_AcPMP_SWVersion_Sub;
        Rte_Inst_ME11.Task_100ms_AcPMP_SupplierNumber_AcPMP_SupplierNumber->value = Rte_Buf_Task_100ms_AcPMP_SupplierNumber_AcPMP_SupplierNumber;
        Rte_Inst_ME11.Task_100ms_BAT_EXV_CurrentPosition_B_BAT_EXV_CurrentPosition_B->value = Rte_Buf_Task_100ms_BAT_EXV_CurrentPosition_B_BAT_EXV_CurrentPosition_B;
        Rte_Inst_ME11.Task_100ms_BAT_EXV_FaultState_B_BAT_EXV_FaultState_B->value = Rte_Buf_Task_100ms_BAT_EXV_FaultState_B_BAT_EXV_FaultState_B;
        Rte_Inst_ME11.Task_100ms_BAT_EXV_ResponseError_B_BAT_EXV_ResponseError_B->value = Rte_Buf_Task_100ms_BAT_EXV_ResponseError_B_BAT_EXV_ResponseError_B;
        Rte_Inst_ME11.Task_100ms_BAT_EXV_RunState_B_BAT_EXV_RunState_B->value = Rte_Buf_Task_100ms_BAT_EXV_RunState_B_BAT_EXV_RunState_B;
        Rte_Inst_ME11.Task_100ms_BAT_EXV_SupplierLabel_BAT_EXV_SupplierLabel->value = Rte_Buf_Task_100ms_BAT_EXV_SupplierLabel_BAT_EXV_SupplierLabel;
        Rte_Inst_ME11.Task_100ms_BAT_EXV_VoltageState_B_BAT_EXV_VoltageState_B->value = Rte_Buf_Task_100ms_BAT_EXV_VoltageState_B_BAT_EXV_VoltageState_B;
        Rte_Inst_ME11.Task_100ms_BAT_EXV_Warning_OverTemp_BAT_EXV_Warning_OverTemp->value = Rte_Buf_Task_100ms_BAT_EXV_Warning_OverTemp_BAT_EXV_Warning_OverTemp;
        Rte_Inst_ME11.Task_100ms_BAT_EXV_initialize_status_BAT_EXV_initialize_status->value = Rte_Buf_Task_100ms_BAT_EXV_initialize_status_BAT_EXV_initialize_status;
        Rte_Inst_ME11.Task_100ms_BatPMP_PumpDryRunningSta_BatPMP_PumpDryRunningSta->value = Rte_Buf_Task_100ms_BatPMP_PumpDryRunningSta_BatPMP_PumpDryRunningSta;
        Rte_Inst_ME11.Task_100ms_BatPMP_PumpInputVolt_BatPMP_PumpInputVolt->value = Rte_Buf_Task_100ms_BatPMP_PumpInputVolt_BatPMP_PumpInputVolt;
        Rte_Inst_ME11.Task_100ms_BatPMP_PumpMotorSta_BatPMP_PumpMotorSta->value = Rte_Buf_Task_100ms_BatPMP_PumpMotorSta_BatPMP_PumpMotorSta;
        Rte_Inst_ME11.Task_100ms_BatPMP_PumpPowerSta_BatPMP_PumpPowerSta->value = Rte_Buf_Task_100ms_BatPMP_PumpPowerSta_BatPMP_PumpPowerSta;
        Rte_Inst_ME11.Task_100ms_BatPMP_PumpTempSta_BatPMP_PumpTempSta->value = Rte_Buf_Task_100ms_BatPMP_PumpTempSta_BatPMP_PumpTempSta;
        Rte_Inst_ME11.Task_100ms_BatPMP_RESP_ERROR_BatPMP_RESP_ERROR->value = Rte_Buf_Task_100ms_BatPMP_RESP_ERROR_BatPMP_RESP_ERROR;
        Rte_Inst_ME11.Task_100ms_BatPMP_RealRPM_BatPMP_RealRPM->value = Rte_Buf_Task_100ms_BatPMP_RealRPM_BatPMP_RealRPM;
        Rte_Inst_ME11.Task_100ms_Bat_EXV_HWVersion_Bat_EXV_HWVersion->value = Rte_Buf_Task_100ms_Bat_EXV_HWVersion_Bat_EXV_HWVersion;
        Rte_Inst_ME11.Task_100ms_Bat_EXV_PartNumber_Bat_EXV_PartNumber->value = Rte_Buf_Task_100ms_Bat_EXV_PartNumber_Bat_EXV_PartNumber;
        Rte_Inst_ME11.Task_100ms_Bat_EXV_ProjectCode1_Bat_EXV_ProjectCode1->value = Rte_Buf_Task_100ms_Bat_EXV_ProjectCode1_Bat_EXV_ProjectCode1;
        Rte_Inst_ME11.Task_100ms_Bat_EXV_ProjectCode2_Bat_EXV_ProjectCode2->value = Rte_Buf_Task_100ms_Bat_EXV_ProjectCode2_Bat_EXV_ProjectCode2;
        Rte_Inst_ME11.Task_100ms_Bat_EXV_SWVersion_Main_Bat_EXV_SWVersion_Main->value = Rte_Buf_Task_100ms_Bat_EXV_SWVersion_Main_Bat_EXV_SWVersion_Main;
        Rte_Inst_ME11.Task_100ms_Bat_EXV_SWVersion_Patch_Bat_EXV_SWVersion_Patch->value = Rte_Buf_Task_100ms_Bat_EXV_SWVersion_Patch_Bat_EXV_SWVersion_Patch;
        Rte_Inst_ME11.Task_100ms_Bat_EXV_SWVersion_Sub_Bat_EXV_SWVersion_Sub->value = Rte_Buf_Task_100ms_Bat_EXV_SWVersion_Sub_Bat_EXV_SWVersion_Sub;
        Rte_Inst_ME11.Task_100ms_Bat_EXV_SupplierNumber_Bat_EXV_SupplierNumber->value = Rte_Buf_Task_100ms_Bat_EXV_SupplierNumber_Bat_EXV_SupplierNumber;
        rte_memcpy((uint8*)&(Rte_Inst_ME11.Task_100ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs->value), (uint8*)&Rte_Buf_Task_100ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs, sizeof(DT_Bcm2VcuTms_outputs));
        Rte_Inst_ME11.Task_100ms_C3WV_ErrResp_C3WV_ErrResp->value = Rte_Buf_Task_100ms_C3WV_ErrResp_C3WV_ErrResp;
        Rte_Inst_ME11.Task_100ms_C3WV_FltSts_C3WV_FltSts->value = Rte_Buf_Task_100ms_C3WV_FltSts_C3WV_FltSts;
        Rte_Inst_ME11.Task_100ms_C3WV_Mode_C3WV_Mode->value = Rte_Buf_Task_100ms_C3WV_Mode_C3WV_Mode;
        Rte_Inst_ME11.Task_100ms_C3WV_PosRec_C3WV_PosRec->value = Rte_Buf_Task_100ms_C3WV_PosRec_C3WV_PosRec;
        Rte_Inst_ME11.Task_100ms_C3WV_RunSts_C3WV_RunSts->value = Rte_Buf_Task_100ms_C3WV_RunSts_C3WV_RunSts;
        Rte_Inst_ME11.Task_100ms_C3WV_SpdLvl_C3WV_SpdLvl->value = Rte_Buf_Task_100ms_C3WV_SpdLvl_C3WV_SpdLvl;
        Rte_Inst_ME11.Task_100ms_C3WV_TempSts_C3WV_TempSts->value = Rte_Buf_Task_100ms_C3WV_TempSts_C3WV_TempSts;
        Rte_Inst_ME11.Task_100ms_C3WV_VoltSts_C3WV_VoltSts->value = Rte_Buf_Task_100ms_C3WV_VoltSts_C3WV_VoltSts;
        Rte_Inst_ME11.Task_100ms_C5WVFltSts_C5WVFltSts->value = Rte_Buf_Task_100ms_C5WVFltSts_C5WVFltSts;
        Rte_Inst_ME11.Task_100ms_C5WVMode_C5WVMode->value = Rte_Buf_Task_100ms_C5WVMode_C5WVMode;
        Rte_Inst_ME11.Task_100ms_C5WVPosRec_C5WVPosRec->value = Rte_Buf_Task_100ms_C5WVPosRec_C5WVPosRec;
        Rte_Inst_ME11.Task_100ms_C5WVRunSts_C5WVRunSts->value = Rte_Buf_Task_100ms_C5WVRunSts_C5WVRunSts;
        Rte_Inst_ME11.Task_100ms_C5WVSpdLvl_C5WVSpdLvl->value = Rte_Buf_Task_100ms_C5WVSpdLvl_C5WVSpdLvl;
        Rte_Inst_ME11.Task_100ms_C5WVTempSts_C5WVTempSts->value = Rte_Buf_Task_100ms_C5WVTempSts_C5WVTempSts;
        Rte_Inst_ME11.Task_100ms_C5WVVoltSts_C5WVVoltSts->value = Rte_Buf_Task_100ms_C5WVVoltSts_C5WVVoltSts;
        Rte_Inst_ME11.Task_100ms_EXV_CurrentInitState_EXV_CurrentInitState->value = Rte_Buf_Task_100ms_EXV_CurrentInitState_EXV_CurrentInitState;
        Rte_Inst_ME11.Task_100ms_EXV_CurrentPosition_EXV_CurrentPosition->value = Rte_Buf_Task_100ms_EXV_CurrentPosition_EXV_CurrentPosition;
        Rte_Inst_ME11.Task_100ms_EXV_FaultState_EXV_FaultState->value = Rte_Buf_Task_100ms_EXV_FaultState_EXV_FaultState;
        Rte_Inst_ME11.Task_100ms_EXV_ResponseError_EXV_ResponseError->value = Rte_Buf_Task_100ms_EXV_ResponseError_EXV_ResponseError;
        Rte_Inst_ME11.Task_100ms_EXV_RunState_EXV_RunState->value = Rte_Buf_Task_100ms_EXV_RunState_EXV_RunState;
        Rte_Inst_ME11.Task_100ms_EXV_TemperatureWarn_EXV_TemperatureWarn->value = Rte_Buf_Task_100ms_EXV_TemperatureWarn_EXV_TemperatureWarn;
        Rte_Inst_ME11.Task_100ms_EXV_VoltageState_EXV_VoltageState->value = Rte_Buf_Task_100ms_EXV_VoltageState_EXV_VoltageState;
        Rte_Inst_ME11.Task_100ms_ErrRespC5WV_ErrRespC5WV->value = Rte_Buf_Task_100ms_ErrRespC5WV_ErrRespC5WV;
        Rte_Inst_ME11.Task_100ms_HP_EXV_CurrentPosition_B_HP_EXV_CurrentPosition_B->value = Rte_Buf_Task_100ms_HP_EXV_CurrentPosition_B_HP_EXV_CurrentPosition_B;
        Rte_Inst_ME11.Task_100ms_HP_EXV_FaultState_B_HP_EXV_FaultState_B->value = Rte_Buf_Task_100ms_HP_EXV_FaultState_B_HP_EXV_FaultState_B;
        Rte_Inst_ME11.Task_100ms_HP_EXV_HWVersion_HP_EXV_HWVersion->value = Rte_Buf_Task_100ms_HP_EXV_HWVersion_HP_EXV_HWVersion;
        Rte_Inst_ME11.Task_100ms_HP_EXV_PartNumber_HP_EXV_PartNumber->value = Rte_Buf_Task_100ms_HP_EXV_PartNumber_HP_EXV_PartNumber;
        Rte_Inst_ME11.Task_100ms_HP_EXV_ProjectCode1_HP_EXV_ProjectCode1->value = Rte_Buf_Task_100ms_HP_EXV_ProjectCode1_HP_EXV_ProjectCode1;
        Rte_Inst_ME11.Task_100ms_HP_EXV_ProjectCode2_HP_EXV_ProjectCode2->value = Rte_Buf_Task_100ms_HP_EXV_ProjectCode2_HP_EXV_ProjectCode2;
        Rte_Inst_ME11.Task_100ms_HP_EXV_ResponseError_B_HP_EXV_ResponseError_B->value = Rte_Buf_Task_100ms_HP_EXV_ResponseError_B_HP_EXV_ResponseError_B;
        Rte_Inst_ME11.Task_100ms_HP_EXV_RunState_B_HP_EXV_RunState_B->value = Rte_Buf_Task_100ms_HP_EXV_RunState_B_HP_EXV_RunState_B;
        Rte_Inst_ME11.Task_100ms_HP_EXV_SWVersion_Main_HP_EXV_SWVersion_Main->value = Rte_Buf_Task_100ms_HP_EXV_SWVersion_Main_HP_EXV_SWVersion_Main;
        Rte_Inst_ME11.Task_100ms_HP_EXV_SWVersion_Patch_HP_EXV_SWVersion_Patch->value = Rte_Buf_Task_100ms_HP_EXV_SWVersion_Patch_HP_EXV_SWVersion_Patch;
        Rte_Inst_ME11.Task_100ms_HP_EXV_SWVersion_Sub_HP_EXV_SWVersion_Sub->value = Rte_Buf_Task_100ms_HP_EXV_SWVersion_Sub_HP_EXV_SWVersion_Sub;
        Rte_Inst_ME11.Task_100ms_HP_EXV_SupplierLabel_HP_EXV_SupplierLabel->value = Rte_Buf_Task_100ms_HP_EXV_SupplierLabel_HP_EXV_SupplierLabel;
        Rte_Inst_ME11.Task_100ms_HP_EXV_SupplierNumber_HP_EXV_SupplierNumber->value = Rte_Buf_Task_100ms_HP_EXV_SupplierNumber_HP_EXV_SupplierNumber;
        Rte_Inst_ME11.Task_100ms_HP_EXV_VoltageState_B_HP_EXV_VoltageState_B->value = Rte_Buf_Task_100ms_HP_EXV_VoltageState_B_HP_EXV_VoltageState_B;
        Rte_Inst_ME11.Task_100ms_HP_EXV_Warning_OverTemp_HP_EXV_Warning_OverTemp->value = Rte_Buf_Task_100ms_HP_EXV_Warning_OverTemp_HP_EXV_Warning_OverTemp;
        Rte_Inst_ME11.Task_100ms_HP_EXV_initialize_status_HP_EXV_initialize_status->value = Rte_Buf_Task_100ms_HP_EXV_initialize_status_HP_EXV_initialize_status;
        rte_memcpy((uint8*)&(Rte_Inst_ME11.Task_100ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT->value), (uint8*)&Rte_Buf_Task_100ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT, sizeof(DT_IPM_BMS_10_DC_ChargeStates_EPT));
        rte_memcpy((uint8*)&(Rte_Inst_ME11.Task_100ms_IPM_BMS_2_BatState_EPT_IPM_BMS_2_BatState_EPT->value), (uint8*)&Rte_Buf_Task_100ms_IPM_BMS_2_BatState_EPT_IPM_BMS_2_BatState_EPT, sizeof(DT_IPM_BMS_2_BatState_EPT));
        rte_memcpy((uint8*)&(Rte_Inst_ME11.Task_100ms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT->value), (uint8*)&Rte_Buf_Task_100ms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT, sizeof(DT_IPM_BMS_4_AC_ChargeState_EPT));
        rte_memcpy((uint8*)&(Rte_Inst_ME11.Task_100ms_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT->value), (uint8*)&Rte_Buf_Task_100ms_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT, sizeof(DT_IPM_BMS_5_BatTemp_EPT));
        rte_memcpy((uint8*)&(Rte_Inst_ME11.Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD->value), (uint8*)&Rte_Buf_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD, sizeof(DT_IPM_CCP_PanelStatus_BOD));
        rte_memcpy((uint8*)&(Rte_Inst_ME11.Task_100ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD->value), (uint8*)&Rte_Buf_Task_100ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD, sizeof(DT_IPM_COMP_AC_BOD));
        rte_memcpy((uint8*)&(Rte_Inst_ME11.Task_100ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA->value), (uint8*)&Rte_Buf_Task_100ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA, sizeof(DT_IPM_ESC_7_FuncStatus_CHA));
        rte_memcpy((uint8*)&(Rte_Inst_ME11.Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC->value), (uint8*)&Rte_Buf_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC, sizeof(DT_IPM_HU_B_BAC));
        rte_memcpy((uint8*)&(Rte_Inst_ME11.Task_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD->value), (uint8*)&Rte_Buf_Task_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD, sizeof(DT_IPM_HVCH_Status1_BOD));
        rte_memcpy((uint8*)&(Rte_Inst_ME11.Task_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD->value), (uint8*)&Rte_Buf_Task_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD, sizeof(DT_IPM_HVCH_Status2_BOD));
        rte_memcpy((uint8*)&(Rte_Inst_ME11.Task_100ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT->value), (uint8*)&Rte_Buf_Task_100ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT, sizeof(DT_IPM_INV_2_Value_EPT));
        rte_memcpy((uint8*)&(Rte_Inst_ME11.Task_100ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT->value), (uint8*)&Rte_Buf_Task_100ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT, sizeof(DT_IPM_IPU_OBC_2_Inlet_EPT));
        Rte_Inst_ME11.Task_100ms_MotPMP_PumpDryRunningSta_MotPMP_PumpDryRunningSta->value = Rte_Buf_Task_100ms_MotPMP_PumpDryRunningSta_MotPMP_PumpDryRunningSta;
        Rte_Inst_ME11.Task_100ms_MotPMP_PumpInputVolt_MotPMP_PumpInputVolt->value = Rte_Buf_Task_100ms_MotPMP_PumpInputVolt_MotPMP_PumpInputVolt;
        Rte_Inst_ME11.Task_100ms_MotPMP_PumpMotorSta_MotPMP_PumpMotorSta->value = Rte_Buf_Task_100ms_MotPMP_PumpMotorSta_MotPMP_PumpMotorSta;
        Rte_Inst_ME11.Task_100ms_MotPMP_PumpPowerSta_MotPMP_PumpPowerSta->value = Rte_Buf_Task_100ms_MotPMP_PumpPowerSta_MotPMP_PumpPowerSta;
        Rte_Inst_ME11.Task_100ms_MotPMP_PumpTempSta_MotPMP_PumpTempSta->value = Rte_Buf_Task_100ms_MotPMP_PumpTempSta_MotPMP_PumpTempSta;
        Rte_Inst_ME11.Task_100ms_MotPMP_RESP_ERROR_MotPMP_RESP_ERROR->value = Rte_Buf_Task_100ms_MotPMP_RESP_ERROR_MotPMP_RESP_ERROR;
        Rte_Inst_ME11.Task_100ms_MotPMP_RealRPM_MotPMP_RealRPM->value = Rte_Buf_Task_100ms_MotPMP_RealRPM_MotPMP_RealRPM;
        rte_memcpy((uint8*)&(Rte_Inst_ME11.Task_100ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs->value), (uint8*)&Rte_Buf_Task_100ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs, sizeof(DT_Vcu2BcmTms_outputs));
        ResumeAllInterrupts();
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
static void Rte_POST_Task_100ms(void)
{
    if (RteInitState == RTE_INITED)
    {
        SuspendAllInterrupts();
        Rte_WriteBuffer_Rte_Buf_Task_100ms_TMS2VCU_AC_1_Command_Outputs_TMS2VCU_AC_1_Command_Outputs(Rte_Inst_ME11.Task_100ms_TMS2VCU_AC_1_Command_Outputs_TMS2VCU_AC_1_Command_Outputs->value);
        Rte_WriteBuffer_Rte_Buf_Task_100ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs(Rte_Inst_ME11.Task_100ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs->value);
        Rte_WriteBuffer_Rte_Buf_Task_100ms_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs(Rte_Inst_ME11.Task_100ms_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs->value);
        Rte_WriteBuffer_Rte_Buf_Task_100ms_TMS2VCU_AC_8_status_Outputs_TMS2VCU_AC_8_status_Outputs(Rte_Inst_ME11.Task_100ms_TMS2VCU_AC_8_status_Outputs_TMS2VCU_AC_8_status_Outputs->value);
        Rte_WriteBuffer_Rte_Buf_Task_100ms_TMS2VCU_AC_ACStatuts_Outputs_TMS2VCU_AC_ACStatuts_Outputs(Rte_Inst_ME11.Task_100ms_TMS2VCU_AC_ACStatuts_Outputs_TMS2VCU_AC_ACStatuts_Outputs->value);
        Rte_WriteBuffer_Rte_Buf_Task_100ms_TMS2VCU_AC_COMP_Outputs_TMS2VCU_AC_COMP_Outputs(Rte_Inst_ME11.Task_100ms_TMS2VCU_AC_COMP_Outputs_TMS2VCU_AC_COMP_Outputs->value);
        Rte_WriteBuffer_Rte_Buf_Task_100ms_TMS2VCU_HVCH_Command_Outputs_TMS2VCU_HVCH_Command_Outputs(Rte_Inst_ME11.Task_100ms_TMS2VCU_HVCH_Command_Outputs_TMS2VCU_HVCH_Command_Outputs->value);
        Rte_WriteBuffer_Rte_Buf_Task_100ms_TMS2VCU_PPV_outputs_TMS2VCU_PPV_outputs(Rte_Inst_ME11.Task_100ms_TMS2VCU_PPV_outputs_TMS2VCU_PPV_outputs->value);
        Rte_WriteBuffer_Rte_Buf_Task_100ms_TMS2VCU_TMS_LINTestData1_Outputs_TMS2VCU_TMS_LINTestData1_Outputs(Rte_Inst_ME11.Task_100ms_TMS2VCU_TMS_LINTestData1_Outputs_TMS2VCU_TMS_LINTestData1_Outputs->value);
        Rte_WriteBuffer_Rte_Buf_Task_100ms_TMS2VCU_TMS_LINTestData2_Outputs_TMS2VCU_TMS_LINTestData2_Outputs(Rte_Inst_ME11.Task_100ms_TMS2VCU_TMS_LINTestData2_Outputs_TMS2VCU_TMS_LINTestData2_Outputs->value);
        Rte_WriteBuffer_Rte_Buf_Task_100ms_TMS2VCU_TMS_LINTestData3_Outputs_TMS2VCU_TMS_LINTestData3_Outputs(Rte_Inst_ME11.Task_100ms_TMS2VCU_TMS_LINTestData3_Outputs_TMS2VCU_TMS_LINTestData3_Outputs->value);
        Rte_WriteBuffer_Rte_Buf_Task_100ms_Tms2Vcu_Info_Tms2Vcu_Info(Rte_Inst_ME11.Task_100ms_Tms2Vcu_Info_Tms2Vcu_Info->value);
        Com_SendSignal(AcPMP_SpdSet_PMP_Cmd_LIN1, &Rte_Inst_ME11.Task_100ms_AcPMP_SpdSet_AcPMP_SpdSet->value);
        Com_SendSignal(AcPMP_SpdSet_PMP_Cmd_LIN2, &Rte_Inst_ME11.Task_100ms_AcPMP_SpdSet_AcPMP_SpdSet->value);
        Com_SendSignal(BAT_EXV_initialize_command_B_BAT_EXV_Cmd_LIN1, &Rte_Inst_ME11.Task_100ms_BAT_EXV_initialize_command_B_BAT_EXV_initialize_command_B->value);
        Com_SendSignal(BAT_EXV_initialize_command_B_BAT_EXV_Cmd_LIN2, &Rte_Inst_ME11.Task_100ms_BAT_EXV_initialize_command_B_BAT_EXV_initialize_command_B->value);
        Com_SendSignal(BAT_EXV_movenable_command_B_BAT_EXV_Cmd_LIN1, &Rte_Inst_ME11.Task_100ms_BAT_EXV_movenable_command_B_BAT_EXV_movenable_command_B->value);
        Com_SendSignal(BAT_EXV_movenable_command_B_BAT_EXV_Cmd_LIN2, &Rte_Inst_ME11.Task_100ms_BAT_EXV_movenable_command_B_BAT_EXV_movenable_command_B->value);
        Com_SendSignal(BAT_EXV_position_command_B_BAT_EXV_Cmd_LIN1, &Rte_Inst_ME11.Task_100ms_BAT_EXV_position_command_B_BAT_EXV_position_command_B->value);
        Com_SendSignal(BAT_EXV_position_command_B_BAT_EXV_Cmd_LIN2, &Rte_Inst_ME11.Task_100ms_BAT_EXV_position_command_B_BAT_EXV_position_command_B->value);
        Com_SendSignal(BatPMP_SpdSet_PMP_Cmd_LIN1, &Rte_Inst_ME11.Task_100ms_BatPMP_SpdSet_BatPMP_SpdSet->value);
        Com_SendSignal(BatPMP_SpdSet_PMP_Cmd_LIN2, &Rte_Inst_ME11.Task_100ms_BatPMP_SpdSet_BatPMP_SpdSet->value);
        Com_SendSignal(C3WV_BPosSetReq_C3WV_Cmd_LIN2, &Rte_Inst_ME11.Task_100ms_C3WV_BPosSetReq_C3WV_BPosSetReq->value);
        Com_SendSignal(C3WV_RefDrvReq_C3WV_Cmd_LIN2, &Rte_Inst_ME11.Task_100ms_C3WV_RefDrvReq_C3WV_RefDrvReq->value);
        Com_SendSignal(C3WV_SpdLvlReq_C3WV_Cmd_LIN2, &Rte_Inst_ME11.Task_100ms_C3WV_SpdLvlReq_C3WV_SpdLvlReq->value);
        Com_SendSignal(C3WV_SpdLvl_C3WV_Sts_LIN2, &Rte_Inst_ME11.Task_100ms_C3WV_SpdLvlReq_C3WV_SpdLvlReq->value);
        Com_SendSignal(C5WV_BPosSetReq_C5WV_Cmd_LIN2, &Rte_Inst_ME11.Task_100ms_C5WV_BPosSetReq_C5WV_BPosSetReq->value);
        Com_SendSignal(C5WV_RefDrvReq_C5WV_Cmd_LIN2, &Rte_Inst_ME11.Task_100ms_C5WV_RefDrvReq_C5WV_RefDrvReq->value);
        Com_SendSignal(C5WV_SpdLvlReq_C5WV_Cmd_LIN2, &Rte_Inst_ME11.Task_100ms_C5WV_SpdLvlReq_C5WV_SpdLvlReq->value);
        Com_SendSignal(HP_EXV_initialize_command_B_HP_EXV_Cmd_LIN1, &Rte_Inst_ME11.Task_100ms_HP_EXV_initialize_command_B_HP_EXV_initialize_command_B->value);
        Com_SendSignal(HP_EXV_initialize_command_B_HP_EXV_Cmd_LIN2, &Rte_Inst_ME11.Task_100ms_HP_EXV_initialize_command_B_HP_EXV_initialize_command_B->value);
        Com_SendSignal(HP_EXV_movenable_command_B_HP_EXV_Cmd_LIN1, &Rte_Inst_ME11.Task_100ms_HP_EXV_movenable_command_B_HP_EXV_movenable_command_B->value);
        Com_SendSignal(HP_EXV_movenable_command_B_HP_EXV_Cmd_LIN2, &Rte_Inst_ME11.Task_100ms_HP_EXV_movenable_command_B_HP_EXV_movenable_command_B->value);
        Com_SendSignal(HP_EXV_position_command_B_HP_EXV_Cmd_LIN1, &Rte_Inst_ME11.Task_100ms_HP_EXV_position_command_B_HP_EXV_position_command_B->value);
        Com_SendSignal(HP_EXV_position_command_B_HP_EXV_Cmd_LIN2, &Rte_Inst_ME11.Task_100ms_HP_EXV_position_command_B_HP_EXV_position_command_B->value);
        Com_SendSignal(MotPMP_SpdSet_PMP_Cmd_LIN1, &Rte_Inst_ME11.Task_100ms_MotPMP_SpdSet_MotPMP_SpdSet->value);
        Com_SendSignal(MotPMP_SpdSet_PMP_Cmd_LIN2, &Rte_Inst_ME11.Task_100ms_MotPMP_SpdSet_MotPMP_SpdSet->value);
        Com_SendSignal(TMM_EXV_EnableRequest_AC_EXV_Cmd_LIN1, &Rte_Inst_ME11.Task_100ms_TMM_EXV_EnableRequest_TMM_EXV_EnableRequest->value);
        Com_SendSignal(TMM_EXV_EnableRequest_AC_EXV_Cmd_LIN2, &Rte_Inst_ME11.Task_100ms_TMM_EXV_EnableRequest_TMM_EXV_EnableRequest->value);
        Com_SendSignal(TMM_EXV_PositionRequest_AC_EXV_Cmd_LIN1, &Rte_Inst_ME11.Task_100ms_TMM_EXV_PositionRequest_TMM_EXV_PositionRequest->value);
        Com_SendSignal(TMM_EXV_PositionRequest_AC_EXV_Cmd_LIN2, &Rte_Inst_ME11.Task_100ms_TMM_EXV_PositionRequest_TMM_EXV_PositionRequest->value);
        Com_SendSignal(TMM_EXV_initRequest_AC_EXV_Cmd_LIN1, &Rte_Inst_ME11.Task_100ms_TMM_EXV_initRequest_TMM_EXV_initRequest->value);
        Com_SendSignal(TMM_EXV_initRequest_AC_EXV_Cmd_LIN2, &Rte_Inst_ME11.Task_100ms_TMM_EXV_initRequest_TMM_EXV_initRequest->value);
        ResumeAllInterrupts();
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
 **                        Global Function Definitions                        **
******************************************************************************/

/*******************************************************************************
*Function-Name        Task_100ms
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_Task_100ms(void)
{
    Rte_PRE_Task_100ms();
    if (RteInitState == RTE_INITED)
    {
        Task_100ms();
    }
    Rte_POST_Task_100ms();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        ME11_Init
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_ME11_Init(void)
{
    if (RteInitState == RTE_INITED)
    {
        ME11_Init();
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_AcPMP_HWVersion_AcPMP_HWVersion
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_AcPMP_HWVersion_AcPMP_HWVersion(void)
{
    return Rte_Inst_ME11.Task_100ms_AcPMP_HWVersion_AcPMP_HWVersion->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_AcPMP_PartNumber_AcPMP_PartNumber
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_AcPMP_PartNumber_AcPMP_PartNumber(void)
{
    return Rte_Inst_ME11.Task_100ms_AcPMP_PartNumber_AcPMP_PartNumber->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_AcPMP_ProjectCode1_AcPMP_ProjectCode1
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_AcPMP_ProjectCode1_AcPMP_ProjectCode1(void)
{
    return Rte_Inst_ME11.Task_100ms_AcPMP_ProjectCode1_AcPMP_ProjectCode1->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_AcPMP_ProjectCode2_AcPMP_ProjectCode2
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_AcPMP_ProjectCode2_AcPMP_ProjectCode2(void)
{
    return Rte_Inst_ME11.Task_100ms_AcPMP_ProjectCode2_AcPMP_ProjectCode2->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_AcPMP_PumpDryRunningSta_AcPMP_PumpDryRunningSta
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_AcPMP_PumpDryRunningSta_AcPMP_PumpDryRunningSta(void)
{
    return Rte_Inst_ME11.Task_100ms_AcPMP_PumpDryRunningSta_AcPMP_PumpDryRunningSta->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_AcPMP_PumpInputVolt_AcPMP_PumpInputVolt
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_AcPMP_PumpInputVolt_AcPMP_PumpInputVolt(void)
{
    return Rte_Inst_ME11.Task_100ms_AcPMP_PumpInputVolt_AcPMP_PumpInputVolt->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_AcPMP_PumpMotorSta_AcPMP_PumpMotorSta
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_AcPMP_PumpMotorSta_AcPMP_PumpMotorSta(void)
{
    return Rte_Inst_ME11.Task_100ms_AcPMP_PumpMotorSta_AcPMP_PumpMotorSta->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_AcPMP_PumpPowerSta_AcPMP_PumpPowerSta
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_AcPMP_PumpPowerSta_AcPMP_PumpPowerSta(void)
{
    return Rte_Inst_ME11.Task_100ms_AcPMP_PumpPowerSta_AcPMP_PumpPowerSta->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_AcPMP_PumpTempSta_AcPMP_PumpTempSta
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_AcPMP_PumpTempSta_AcPMP_PumpTempSta(void)
{
    return Rte_Inst_ME11.Task_100ms_AcPMP_PumpTempSta_AcPMP_PumpTempSta->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_AcPMP_RESP_ERROR_AcPMP_RESP_ERROR
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_AcPMP_RESP_ERROR_AcPMP_RESP_ERROR(void)
{
    return Rte_Inst_ME11.Task_100ms_AcPMP_RESP_ERROR_AcPMP_RESP_ERROR->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_AcPMP_RealRPM_AcPMP_RealRPM
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_AcPMP_RealRPM_AcPMP_RealRPM(void)
{
    return Rte_Inst_ME11.Task_100ms_AcPMP_RealRPM_AcPMP_RealRPM->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_AcPMP_SWVersion_Main_AcPMP_SWVersion_Main
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_AcPMP_SWVersion_Main_AcPMP_SWVersion_Main(void)
{
    return Rte_Inst_ME11.Task_100ms_AcPMP_SWVersion_Main_AcPMP_SWVersion_Main->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_AcPMP_SWVersion_Patch_AcPMP_SWVersion_Patch
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_AcPMP_SWVersion_Patch_AcPMP_SWVersion_Patch(void)
{
    return Rte_Inst_ME11.Task_100ms_AcPMP_SWVersion_Patch_AcPMP_SWVersion_Patch->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_AcPMP_SWVersion_Sub_AcPMP_SWVersion_Sub
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_AcPMP_SWVersion_Sub_AcPMP_SWVersion_Sub(void)
{
    return Rte_Inst_ME11.Task_100ms_AcPMP_SWVersion_Sub_AcPMP_SWVersion_Sub->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_AcPMP_SupplierNumber_AcPMP_SupplierNumber
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_AcPMP_SupplierNumber_AcPMP_SupplierNumber(void)
{
    return Rte_Inst_ME11.Task_100ms_AcPMP_SupplierNumber_AcPMP_SupplierNumber->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_BAT_EXV_CurrentPosition_B_BAT_EXV_CurrentPosition_B
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_BAT_EXV_CurrentPosition_B_BAT_EXV_CurrentPosition_B(void)
{
    return Rte_Inst_ME11.Task_100ms_BAT_EXV_CurrentPosition_B_BAT_EXV_CurrentPosition_B->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_BAT_EXV_FaultState_B_BAT_EXV_FaultState_B
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_BAT_EXV_FaultState_B_BAT_EXV_FaultState_B(void)
{
    return Rte_Inst_ME11.Task_100ms_BAT_EXV_FaultState_B_BAT_EXV_FaultState_B->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_BAT_EXV_ResponseError_B_BAT_EXV_ResponseError_B
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_BAT_EXV_ResponseError_B_BAT_EXV_ResponseError_B(void)
{
    return Rte_Inst_ME11.Task_100ms_BAT_EXV_ResponseError_B_BAT_EXV_ResponseError_B->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_BAT_EXV_RunState_B_BAT_EXV_RunState_B
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_BAT_EXV_RunState_B_BAT_EXV_RunState_B(void)
{
    return Rte_Inst_ME11.Task_100ms_BAT_EXV_RunState_B_BAT_EXV_RunState_B->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_BAT_EXV_SupplierLabel_BAT_EXV_SupplierLabel
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_BAT_EXV_SupplierLabel_BAT_EXV_SupplierLabel(void)
{
    return Rte_Inst_ME11.Task_100ms_BAT_EXV_SupplierLabel_BAT_EXV_SupplierLabel->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_BAT_EXV_VoltageState_B_BAT_EXV_VoltageState_B
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_BAT_EXV_VoltageState_B_BAT_EXV_VoltageState_B(void)
{
    return Rte_Inst_ME11.Task_100ms_BAT_EXV_VoltageState_B_BAT_EXV_VoltageState_B->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_BAT_EXV_Warning_OverTemp_BAT_EXV_Warning_OverTemp
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_BAT_EXV_Warning_OverTemp_BAT_EXV_Warning_OverTemp(void)
{
    return Rte_Inst_ME11.Task_100ms_BAT_EXV_Warning_OverTemp_BAT_EXV_Warning_OverTemp->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_BAT_EXV_initialize_status_BAT_EXV_initialize_status
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_BAT_EXV_initialize_status_BAT_EXV_initialize_status(void)
{
    return Rte_Inst_ME11.Task_100ms_BAT_EXV_initialize_status_BAT_EXV_initialize_status->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_BatPMP_PumpDryRunningSta_BatPMP_PumpDryRunningSta
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_BatPMP_PumpDryRunningSta_BatPMP_PumpDryRunningSta(void)
{
    return Rte_Inst_ME11.Task_100ms_BatPMP_PumpDryRunningSta_BatPMP_PumpDryRunningSta->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_BatPMP_PumpInputVolt_BatPMP_PumpInputVolt
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_BatPMP_PumpInputVolt_BatPMP_PumpInputVolt(void)
{
    return Rte_Inst_ME11.Task_100ms_BatPMP_PumpInputVolt_BatPMP_PumpInputVolt->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_BatPMP_PumpMotorSta_BatPMP_PumpMotorSta
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_BatPMP_PumpMotorSta_BatPMP_PumpMotorSta(void)
{
    return Rte_Inst_ME11.Task_100ms_BatPMP_PumpMotorSta_BatPMP_PumpMotorSta->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_BatPMP_PumpPowerSta_BatPMP_PumpPowerSta
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_BatPMP_PumpPowerSta_BatPMP_PumpPowerSta(void)
{
    return Rte_Inst_ME11.Task_100ms_BatPMP_PumpPowerSta_BatPMP_PumpPowerSta->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_BatPMP_PumpTempSta_BatPMP_PumpTempSta
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_BatPMP_PumpTempSta_BatPMP_PumpTempSta(void)
{
    return Rte_Inst_ME11.Task_100ms_BatPMP_PumpTempSta_BatPMP_PumpTempSta->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_BatPMP_RESP_ERROR_BatPMP_RESP_ERROR
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_BatPMP_RESP_ERROR_BatPMP_RESP_ERROR(void)
{
    return Rte_Inst_ME11.Task_100ms_BatPMP_RESP_ERROR_BatPMP_RESP_ERROR->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_BatPMP_RealRPM_BatPMP_RealRPM
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_BatPMP_RealRPM_BatPMP_RealRPM(void)
{
    return Rte_Inst_ME11.Task_100ms_BatPMP_RealRPM_BatPMP_RealRPM->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_Bat_EXV_HWVersion_Bat_EXV_HWVersion
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_Bat_EXV_HWVersion_Bat_EXV_HWVersion(void)
{
    return Rte_Inst_ME11.Task_100ms_Bat_EXV_HWVersion_Bat_EXV_HWVersion->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_Bat_EXV_PartNumber_Bat_EXV_PartNumber
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_Bat_EXV_PartNumber_Bat_EXV_PartNumber(void)
{
    return Rte_Inst_ME11.Task_100ms_Bat_EXV_PartNumber_Bat_EXV_PartNumber->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_Bat_EXV_ProjectCode1_Bat_EXV_ProjectCode1
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_Bat_EXV_ProjectCode1_Bat_EXV_ProjectCode1(void)
{
    return Rte_Inst_ME11.Task_100ms_Bat_EXV_ProjectCode1_Bat_EXV_ProjectCode1->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_Bat_EXV_ProjectCode2_Bat_EXV_ProjectCode2
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_Bat_EXV_ProjectCode2_Bat_EXV_ProjectCode2(void)
{
    return Rte_Inst_ME11.Task_100ms_Bat_EXV_ProjectCode2_Bat_EXV_ProjectCode2->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_Bat_EXV_SWVersion_Main_Bat_EXV_SWVersion_Main
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_Bat_EXV_SWVersion_Main_Bat_EXV_SWVersion_Main(void)
{
    return Rte_Inst_ME11.Task_100ms_Bat_EXV_SWVersion_Main_Bat_EXV_SWVersion_Main->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_Bat_EXV_SWVersion_Patch_Bat_EXV_SWVersion_Patch
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_Bat_EXV_SWVersion_Patch_Bat_EXV_SWVersion_Patch(void)
{
    return Rte_Inst_ME11.Task_100ms_Bat_EXV_SWVersion_Patch_Bat_EXV_SWVersion_Patch->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_Bat_EXV_SWVersion_Sub_Bat_EXV_SWVersion_Sub
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_Bat_EXV_SWVersion_Sub_Bat_EXV_SWVersion_Sub(void)
{
    return Rte_Inst_ME11.Task_100ms_Bat_EXV_SWVersion_Sub_Bat_EXV_SWVersion_Sub->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_Bat_EXV_SupplierNumber_Bat_EXV_SupplierNumber
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_Bat_EXV_SupplierNumber_Bat_EXV_SupplierNumber(void)
{
    return Rte_Inst_ME11.Task_100ms_Bat_EXV_SupplierNumber_Bat_EXV_SupplierNumber->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs(void)
{
    return Rte_Inst_ME11.Task_100ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_C3WV_ErrResp_C3WV_ErrResp
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_C3WV_ErrResp_C3WV_ErrResp(void)
{
    return Rte_Inst_ME11.Task_100ms_C3WV_ErrResp_C3WV_ErrResp->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_C3WV_FltSts_C3WV_FltSts
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_C3WV_FltSts_C3WV_FltSts(void)
{
    return Rte_Inst_ME11.Task_100ms_C3WV_FltSts_C3WV_FltSts->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_C3WV_Mode_C3WV_Mode
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_C3WV_Mode_C3WV_Mode(void)
{
    return Rte_Inst_ME11.Task_100ms_C3WV_Mode_C3WV_Mode->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_C3WV_PosRec_C3WV_PosRec
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_C3WV_PosRec_C3WV_PosRec(void)
{
    return Rte_Inst_ME11.Task_100ms_C3WV_PosRec_C3WV_PosRec->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_C3WV_RunSts_C3WV_RunSts
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_C3WV_RunSts_C3WV_RunSts(void)
{
    return Rte_Inst_ME11.Task_100ms_C3WV_RunSts_C3WV_RunSts->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_C3WV_SpdLvl_C3WV_SpdLvl
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_C3WV_SpdLvl_C3WV_SpdLvl(void)
{
    return Rte_Inst_ME11.Task_100ms_C3WV_SpdLvl_C3WV_SpdLvl->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_C3WV_TempSts_C3WV_TempSts
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_C3WV_TempSts_C3WV_TempSts(void)
{
    return Rte_Inst_ME11.Task_100ms_C3WV_TempSts_C3WV_TempSts->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_C3WV_VoltSts_C3WV_VoltSts
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_C3WV_VoltSts_C3WV_VoltSts(void)
{
    return Rte_Inst_ME11.Task_100ms_C3WV_VoltSts_C3WV_VoltSts->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_C5WVFltSts_C5WVFltSts
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_C5WVFltSts_C5WVFltSts(void)
{
    return Rte_Inst_ME11.Task_100ms_C5WVFltSts_C5WVFltSts->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_C5WVMode_C5WVMode
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_C5WVMode_C5WVMode(void)
{
    return Rte_Inst_ME11.Task_100ms_C5WVMode_C5WVMode->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_C5WVPosRec_C5WVPosRec
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_C5WVPosRec_C5WVPosRec(void)
{
    return Rte_Inst_ME11.Task_100ms_C5WVPosRec_C5WVPosRec->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_C5WVRunSts_C5WVRunSts
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_C5WVRunSts_C5WVRunSts(void)
{
    return Rte_Inst_ME11.Task_100ms_C5WVRunSts_C5WVRunSts->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_C5WVSpdLvl_C5WVSpdLvl
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_C5WVSpdLvl_C5WVSpdLvl(void)
{
    return Rte_Inst_ME11.Task_100ms_C5WVSpdLvl_C5WVSpdLvl->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_C5WVTempSts_C5WVTempSts
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_C5WVTempSts_C5WVTempSts(void)
{
    return Rte_Inst_ME11.Task_100ms_C5WVTempSts_C5WVTempSts->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_C5WVVoltSts_C5WVVoltSts
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_C5WVVoltSts_C5WVVoltSts(void)
{
    return Rte_Inst_ME11.Task_100ms_C5WVVoltSts_C5WVVoltSts->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_EXV_CurrentInitState_EXV_CurrentInitState
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_EXV_CurrentInitState_EXV_CurrentInitState(void)
{
    return Rte_Inst_ME11.Task_100ms_EXV_CurrentInitState_EXV_CurrentInitState->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_EXV_CurrentPosition_EXV_CurrentPosition
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_EXV_CurrentPosition_EXV_CurrentPosition(void)
{
    return Rte_Inst_ME11.Task_100ms_EXV_CurrentPosition_EXV_CurrentPosition->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_EXV_FaultState_EXV_FaultState
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_EXV_FaultState_EXV_FaultState(void)
{
    return Rte_Inst_ME11.Task_100ms_EXV_FaultState_EXV_FaultState->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_EXV_ResponseError_EXV_ResponseError
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_EXV_ResponseError_EXV_ResponseError(void)
{
    return Rte_Inst_ME11.Task_100ms_EXV_ResponseError_EXV_ResponseError->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_EXV_RunState_EXV_RunState
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_EXV_RunState_EXV_RunState(void)
{
    return Rte_Inst_ME11.Task_100ms_EXV_RunState_EXV_RunState->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_EXV_TemperatureWarn_EXV_TemperatureWarn
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_EXV_TemperatureWarn_EXV_TemperatureWarn(void)
{
    return Rte_Inst_ME11.Task_100ms_EXV_TemperatureWarn_EXV_TemperatureWarn->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_EXV_VoltageState_EXV_VoltageState
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_EXV_VoltageState_EXV_VoltageState(void)
{
    return Rte_Inst_ME11.Task_100ms_EXV_VoltageState_EXV_VoltageState->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_ErrRespC5WV_ErrRespC5WV
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_ErrRespC5WV_ErrRespC5WV(void)
{
    return Rte_Inst_ME11.Task_100ms_ErrRespC5WV_ErrRespC5WV->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_HP_EXV_CurrentPosition_B_HP_EXV_CurrentPosition_B
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_HP_EXV_CurrentPosition_B_HP_EXV_CurrentPosition_B(void)
{
    return Rte_Inst_ME11.Task_100ms_HP_EXV_CurrentPosition_B_HP_EXV_CurrentPosition_B->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_HP_EXV_FaultState_B_HP_EXV_FaultState_B
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_HP_EXV_FaultState_B_HP_EXV_FaultState_B(void)
{
    return Rte_Inst_ME11.Task_100ms_HP_EXV_FaultState_B_HP_EXV_FaultState_B->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_HP_EXV_HWVersion_HP_EXV_HWVersion
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_HP_EXV_HWVersion_HP_EXV_HWVersion(void)
{
    return Rte_Inst_ME11.Task_100ms_HP_EXV_HWVersion_HP_EXV_HWVersion->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_HP_EXV_PartNumber_HP_EXV_PartNumber
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_HP_EXV_PartNumber_HP_EXV_PartNumber(void)
{
    return Rte_Inst_ME11.Task_100ms_HP_EXV_PartNumber_HP_EXV_PartNumber->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_HP_EXV_ProjectCode1_HP_EXV_ProjectCode1
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_HP_EXV_ProjectCode1_HP_EXV_ProjectCode1(void)
{
    return Rte_Inst_ME11.Task_100ms_HP_EXV_ProjectCode1_HP_EXV_ProjectCode1->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_HP_EXV_ProjectCode2_HP_EXV_ProjectCode2
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_HP_EXV_ProjectCode2_HP_EXV_ProjectCode2(void)
{
    return Rte_Inst_ME11.Task_100ms_HP_EXV_ProjectCode2_HP_EXV_ProjectCode2->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_HP_EXV_ResponseError_B_HP_EXV_ResponseError_B
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_HP_EXV_ResponseError_B_HP_EXV_ResponseError_B(void)
{
    return Rte_Inst_ME11.Task_100ms_HP_EXV_ResponseError_B_HP_EXV_ResponseError_B->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_HP_EXV_RunState_B_HP_EXV_RunState_B
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_HP_EXV_RunState_B_HP_EXV_RunState_B(void)
{
    return Rte_Inst_ME11.Task_100ms_HP_EXV_RunState_B_HP_EXV_RunState_B->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_HP_EXV_SWVersion_Main_HP_EXV_SWVersion_Main
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_HP_EXV_SWVersion_Main_HP_EXV_SWVersion_Main(void)
{
    return Rte_Inst_ME11.Task_100ms_HP_EXV_SWVersion_Main_HP_EXV_SWVersion_Main->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_HP_EXV_SWVersion_Patch_HP_EXV_SWVersion_Patch
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_HP_EXV_SWVersion_Patch_HP_EXV_SWVersion_Patch(void)
{
    return Rte_Inst_ME11.Task_100ms_HP_EXV_SWVersion_Patch_HP_EXV_SWVersion_Patch->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_HP_EXV_SWVersion_Sub_HP_EXV_SWVersion_Sub
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_HP_EXV_SWVersion_Sub_HP_EXV_SWVersion_Sub(void)
{
    return Rte_Inst_ME11.Task_100ms_HP_EXV_SWVersion_Sub_HP_EXV_SWVersion_Sub->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_HP_EXV_SupplierLabel_HP_EXV_SupplierLabel
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_HP_EXV_SupplierLabel_HP_EXV_SupplierLabel(void)
{
    return Rte_Inst_ME11.Task_100ms_HP_EXV_SupplierLabel_HP_EXV_SupplierLabel->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_HP_EXV_SupplierNumber_HP_EXV_SupplierNumber
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_HP_EXV_SupplierNumber_HP_EXV_SupplierNumber(void)
{
    return Rte_Inst_ME11.Task_100ms_HP_EXV_SupplierNumber_HP_EXV_SupplierNumber->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_HP_EXV_VoltageState_B_HP_EXV_VoltageState_B
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_HP_EXV_VoltageState_B_HP_EXV_VoltageState_B(void)
{
    return Rte_Inst_ME11.Task_100ms_HP_EXV_VoltageState_B_HP_EXV_VoltageState_B->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_HP_EXV_Warning_OverTemp_HP_EXV_Warning_OverTemp
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_HP_EXV_Warning_OverTemp_HP_EXV_Warning_OverTemp(void)
{
    return Rte_Inst_ME11.Task_100ms_HP_EXV_Warning_OverTemp_HP_EXV_Warning_OverTemp->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_HP_EXV_initialize_status_HP_EXV_initialize_status
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_HP_EXV_initialize_status_HP_EXV_initialize_status(void)
{
    return Rte_Inst_ME11.Task_100ms_HP_EXV_initialize_status_HP_EXV_initialize_status->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT(void)
{
    return Rte_Inst_ME11.Task_100ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_IPM_BMS_2_BatState_EPT_IPM_BMS_2_BatState_EPT
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_IPM_BMS_2_BatState_EPT_IPM_BMS_2_BatState_EPT(void)
{
    return Rte_Inst_ME11.Task_100ms_IPM_BMS_2_BatState_EPT_IPM_BMS_2_BatState_EPT->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT(void)
{
    return Rte_Inst_ME11.Task_100ms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT(void)
{
    return Rte_Inst_ME11.Task_100ms_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD(void)
{
    return Rte_Inst_ME11.Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD(void)
{
    return Rte_Inst_ME11.Task_100ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA(void)
{
    return Rte_Inst_ME11.Task_100ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC(void)
{
    return Rte_Inst_ME11.Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD(void)
{
    return Rte_Inst_ME11.Task_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD(void)
{
    return Rte_Inst_ME11.Task_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT(void)
{
    return Rte_Inst_ME11.Task_100ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT(void)
{
    return Rte_Inst_ME11.Task_100ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_MotPMP_PumpDryRunningSta_MotPMP_PumpDryRunningSta
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_MotPMP_PumpDryRunningSta_MotPMP_PumpDryRunningSta(void)
{
    return Rte_Inst_ME11.Task_100ms_MotPMP_PumpDryRunningSta_MotPMP_PumpDryRunningSta->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_MotPMP_PumpInputVolt_MotPMP_PumpInputVolt
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_MotPMP_PumpInputVolt_MotPMP_PumpInputVolt(void)
{
    return Rte_Inst_ME11.Task_100ms_MotPMP_PumpInputVolt_MotPMP_PumpInputVolt->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_MotPMP_PumpMotorSta_MotPMP_PumpMotorSta
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_MotPMP_PumpMotorSta_MotPMP_PumpMotorSta(void)
{
    return Rte_Inst_ME11.Task_100ms_MotPMP_PumpMotorSta_MotPMP_PumpMotorSta->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_MotPMP_PumpPowerSta_MotPMP_PumpPowerSta
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_MotPMP_PumpPowerSta_MotPMP_PumpPowerSta(void)
{
    return Rte_Inst_ME11.Task_100ms_MotPMP_PumpPowerSta_MotPMP_PumpPowerSta->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_MotPMP_PumpTempSta_MotPMP_PumpTempSta
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_MotPMP_PumpTempSta_MotPMP_PumpTempSta(void)
{
    return Rte_Inst_ME11.Task_100ms_MotPMP_PumpTempSta_MotPMP_PumpTempSta->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_MotPMP_RESP_ERROR_MotPMP_RESP_ERROR
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_MotPMP_RESP_ERROR_MotPMP_RESP_ERROR(void)
{
    return Rte_Inst_ME11.Task_100ms_MotPMP_RESP_ERROR_MotPMP_RESP_ERROR->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_MotPMP_RealRPM_MotPMP_RealRPM
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_MotPMP_RealRPM_MotPMP_RealRPM(void)
{
    return Rte_Inst_ME11.Task_100ms_MotPMP_RealRPM_MotPMP_RealRPM->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Task_100ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType Rte_IStatus_Task_100ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs(void)
{
    return Rte_Inst_ME11.Task_100ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

