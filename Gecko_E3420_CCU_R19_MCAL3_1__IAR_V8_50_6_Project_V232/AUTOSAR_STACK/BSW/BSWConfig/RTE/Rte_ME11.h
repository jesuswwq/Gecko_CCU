/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_ME11.h>
 *  @brief      <>
 *  
 *  <MCU:E3420>
 *  
 *  @author     <>
 *  @date       <2024-07-16 14:44:01>
 */
/*============================================================================*/

/* Rte_ME11.h */

#ifndef RTE_ME11_H
#define RTE_ME11_H

/*******************************************************************************
 **                        Revision Control History                           **
******************************************************************************/

/*******************************************************************************
 **                        Version Information                                **
******************************************************************************/

/*******************************************************************************
 **                        Include Section                                    **
******************************************************************************/
#include "Rte_DataHandleType.h"
#include "Rte_ME11_Type.h"

/*******************************************************************************
 **                        Macro Definitions                                  **
******************************************************************************/

typedef struct
{
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_AcPMP_HWVersion_AcPMP_HWVersion;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_AcPMP_PartNumber_AcPMP_PartNumber;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_AcPMP_ProjectCode1_AcPMP_ProjectCode1;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_AcPMP_ProjectCode2_AcPMP_ProjectCode2;
    P2VAR(Rte_DE_Boolean_status, AUTOMATIC, RTE_DATA)  Task_100ms_AcPMP_PumpDryRunningSta_AcPMP_PumpDryRunningSta;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_AcPMP_PumpInputVolt_AcPMP_PumpInputVolt;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_AcPMP_PumpMotorSta_AcPMP_PumpMotorSta;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_AcPMP_PumpPowerSta_AcPMP_PumpPowerSta;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_AcPMP_PumpTempSta_AcPMP_PumpTempSta;
    P2VAR(Rte_DE_Boolean_status, AUTOMATIC, RTE_DATA)  Task_100ms_AcPMP_RESP_ERROR_AcPMP_RESP_ERROR;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_AcPMP_RealRPM_AcPMP_RealRPM;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_AcPMP_SWVersion_Main_AcPMP_SWVersion_Main;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_AcPMP_SWVersion_Patch_AcPMP_SWVersion_Patch;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_AcPMP_SWVersion_Sub_AcPMP_SWVersion_Sub;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_AcPMP_SupplierNumber_AcPMP_SupplierNumber;
    P2VAR(Rte_DE_UInt16_status, AUTOMATIC, RTE_DATA)  Task_100ms_BAT_EXV_CurrentPosition_B_BAT_EXV_CurrentPosition_B;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_BAT_EXV_FaultState_B_BAT_EXV_FaultState_B;
    P2VAR(Rte_DE_Boolean_status, AUTOMATIC, RTE_DATA)  Task_100ms_BAT_EXV_ResponseError_B_BAT_EXV_ResponseError_B;
    P2VAR(Rte_DE_Boolean_status, AUTOMATIC, RTE_DATA)  Task_100ms_BAT_EXV_RunState_B_BAT_EXV_RunState_B;
    P2VAR(Rte_DE_Boolean_status, AUTOMATIC, RTE_DATA)  Task_100ms_BAT_EXV_SupplierLabel_BAT_EXV_SupplierLabel;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_BAT_EXV_VoltageState_B_BAT_EXV_VoltageState_B;
    P2VAR(Rte_DE_Boolean_status, AUTOMATIC, RTE_DATA)  Task_100ms_BAT_EXV_Warning_OverTemp_BAT_EXV_Warning_OverTemp;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_BAT_EXV_initialize_status_BAT_EXV_initialize_status;
    P2VAR(Rte_DE_Boolean_status, AUTOMATIC, RTE_DATA)  Task_100ms_BatPMP_PumpDryRunningSta_BatPMP_PumpDryRunningSta;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_BatPMP_PumpInputVolt_BatPMP_PumpInputVolt;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_BatPMP_PumpMotorSta_BatPMP_PumpMotorSta;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_BatPMP_PumpPowerSta_BatPMP_PumpPowerSta;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_BatPMP_PumpTempSta_BatPMP_PumpTempSta;
    P2VAR(Rte_DE_Boolean_status, AUTOMATIC, RTE_DATA)  Task_100ms_BatPMP_RESP_ERROR_BatPMP_RESP_ERROR;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_BatPMP_RealRPM_BatPMP_RealRPM;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_Bat_EXV_HWVersion_Bat_EXV_HWVersion;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_Bat_EXV_PartNumber_Bat_EXV_PartNumber;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_Bat_EXV_ProjectCode1_Bat_EXV_ProjectCode1;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_Bat_EXV_ProjectCode2_Bat_EXV_ProjectCode2;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_Bat_EXV_SWVersion_Main_Bat_EXV_SWVersion_Main;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_Bat_EXV_SWVersion_Patch_Bat_EXV_SWVersion_Patch;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_Bat_EXV_SWVersion_Sub_Bat_EXV_SWVersion_Sub;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_Bat_EXV_SupplierNumber_Bat_EXV_SupplierNumber;
    P2VAR(Rte_DE_DT_Bcm2VcuTms_outputs_status, AUTOMATIC, RTE_DATA)  Task_100ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs;
    P2VAR(Rte_DE_Boolean_status, AUTOMATIC, RTE_DATA)  Task_100ms_C3WV_ErrResp_C3WV_ErrResp;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_C3WV_FltSts_C3WV_FltSts;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_C3WV_Mode_C3WV_Mode;
    P2VAR(Rte_DE_UInt16_status, AUTOMATIC, RTE_DATA)  Task_100ms_C3WV_PosRec_C3WV_PosRec;
    P2VAR(Rte_DE_Boolean_status, AUTOMATIC, RTE_DATA)  Task_100ms_C3WV_RunSts_C3WV_RunSts;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_C3WV_SpdLvl_C3WV_SpdLvl;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_C3WV_TempSts_C3WV_TempSts;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_C3WV_VoltSts_C3WV_VoltSts;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_C5WVFltSts_C5WVFltSts;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_C5WVMode_C5WVMode;
    P2VAR(Rte_DE_UInt16_status, AUTOMATIC, RTE_DATA)  Task_100ms_C5WVPosRec_C5WVPosRec;
    P2VAR(Rte_DE_Boolean_status, AUTOMATIC, RTE_DATA)  Task_100ms_C5WVRunSts_C5WVRunSts;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_C5WVSpdLvl_C5WVSpdLvl;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_C5WVTempSts_C5WVTempSts;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_C5WVVoltSts_C5WVVoltSts;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_EXV_CurrentInitState_EXV_CurrentInitState;
    P2VAR(Rte_DE_UInt16_status, AUTOMATIC, RTE_DATA)  Task_100ms_EXV_CurrentPosition_EXV_CurrentPosition;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_EXV_FaultState_EXV_FaultState;
    P2VAR(Rte_DE_Boolean_status, AUTOMATIC, RTE_DATA)  Task_100ms_EXV_ResponseError_EXV_ResponseError;
    P2VAR(Rte_DE_Boolean_status, AUTOMATIC, RTE_DATA)  Task_100ms_EXV_RunState_EXV_RunState;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_EXV_TemperatureWarn_EXV_TemperatureWarn;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_EXV_VoltageState_EXV_VoltageState;
    P2VAR(Rte_DE_Boolean_status, AUTOMATIC, RTE_DATA)  Task_100ms_ErrRespC5WV_ErrRespC5WV;
    P2VAR(Rte_DE_UInt16_status, AUTOMATIC, RTE_DATA)  Task_100ms_HP_EXV_CurrentPosition_B_HP_EXV_CurrentPosition_B;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_HP_EXV_FaultState_B_HP_EXV_FaultState_B;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_HP_EXV_HWVersion_HP_EXV_HWVersion;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_HP_EXV_PartNumber_HP_EXV_PartNumber;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_HP_EXV_ProjectCode1_HP_EXV_ProjectCode1;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_HP_EXV_ProjectCode2_HP_EXV_ProjectCode2;
    P2VAR(Rte_DE_Boolean_status, AUTOMATIC, RTE_DATA)  Task_100ms_HP_EXV_ResponseError_B_HP_EXV_ResponseError_B;
    P2VAR(Rte_DE_Boolean_status, AUTOMATIC, RTE_DATA)  Task_100ms_HP_EXV_RunState_B_HP_EXV_RunState_B;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_HP_EXV_SWVersion_Main_HP_EXV_SWVersion_Main;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_HP_EXV_SWVersion_Patch_HP_EXV_SWVersion_Patch;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_HP_EXV_SWVersion_Sub_HP_EXV_SWVersion_Sub;
    P2VAR(Rte_DE_Boolean_status, AUTOMATIC, RTE_DATA)  Task_100ms_HP_EXV_SupplierLabel_HP_EXV_SupplierLabel;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_HP_EXV_SupplierNumber_HP_EXV_SupplierNumber;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_HP_EXV_VoltageState_B_HP_EXV_VoltageState_B;
    P2VAR(Rte_DE_Boolean_status, AUTOMATIC, RTE_DATA)  Task_100ms_HP_EXV_Warning_OverTemp_HP_EXV_Warning_OverTemp;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_HP_EXV_initialize_status_HP_EXV_initialize_status;
    P2VAR(Rte_DE_DT_IPM_BMS_10_DC_ChargeStates_EPT_status, AUTOMATIC, RTE_DATA)  Task_100ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT;
    P2VAR(Rte_DE_DT_IPM_BMS_2_BatState_EPT_status, AUTOMATIC, RTE_DATA)  Task_100ms_IPM_BMS_2_BatState_EPT_IPM_BMS_2_BatState_EPT;
    P2VAR(Rte_DE_DT_IPM_BMS_4_AC_ChargeState_EPT_status, AUTOMATIC, RTE_DATA)  Task_100ms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT;
    P2VAR(Rte_DE_DT_IPM_BMS_5_BatTemp_EPT_status, AUTOMATIC, RTE_DATA)  Task_100ms_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT;
    P2VAR(Rte_DE_DT_IPM_CCP_PanelStatus_BOD_status, AUTOMATIC, RTE_DATA)  Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD;
    P2VAR(Rte_DE_DT_IPM_COMP_AC_BOD_status, AUTOMATIC, RTE_DATA)  Task_100ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD;
    P2VAR(Rte_DE_DT_IPM_ESC_7_FuncStatus_CHA_status, AUTOMATIC, RTE_DATA)  Task_100ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA;
    P2VAR(Rte_DE_DT_IPM_HU_B_BAC_status, AUTOMATIC, RTE_DATA)  Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC;
    P2VAR(Rte_DE_DT_IPM_HVCH_Status1_BOD_status, AUTOMATIC, RTE_DATA)  Task_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD;
    P2VAR(Rte_DE_DT_IPM_HVCH_Status2_BOD_status, AUTOMATIC, RTE_DATA)  Task_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD;
    P2VAR(Rte_DE_DT_IPM_INV_2_Value_EPT_status, AUTOMATIC, RTE_DATA)  Task_100ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT;
    P2VAR(Rte_DE_DT_IPM_IPU_OBC_2_Inlet_EPT_status, AUTOMATIC, RTE_DATA)  Task_100ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT;
    P2VAR(Rte_DE_Boolean_status, AUTOMATIC, RTE_DATA)  Task_100ms_MotPMP_PumpDryRunningSta_MotPMP_PumpDryRunningSta;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_MotPMP_PumpInputVolt_MotPMP_PumpInputVolt;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_MotPMP_PumpMotorSta_MotPMP_PumpMotorSta;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_MotPMP_PumpPowerSta_MotPMP_PumpPowerSta;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_MotPMP_PumpTempSta_MotPMP_PumpTempSta;
    P2VAR(Rte_DE_Boolean_status, AUTOMATIC, RTE_DATA)  Task_100ms_MotPMP_RESP_ERROR_MotPMP_RESP_ERROR;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_MotPMP_RealRPM_MotPMP_RealRPM;
    P2VAR(Rte_DE_DT_Vcu2BcmTms_outputs_status, AUTOMATIC, RTE_DATA)  Task_100ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_AcPMP_SpdSet_AcPMP_SpdSet;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_BAT_EXV_initialize_command_B_BAT_EXV_initialize_command_B;
    P2VAR(Rte_DE_Boolean_status, AUTOMATIC, RTE_DATA)  Task_100ms_BAT_EXV_movenable_command_B_BAT_EXV_movenable_command_B;
    P2VAR(Rte_DE_UInt16_status, AUTOMATIC, RTE_DATA)  Task_100ms_BAT_EXV_position_command_B_BAT_EXV_position_command_B;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_BatPMP_SpdSet_BatPMP_SpdSet;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_C3WV_BPosSetReq_C3WV_BPosSetReq;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_C3WV_RefDrvReq_C3WV_RefDrvReq;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_C3WV_SpdLvlReq_C3WV_SpdLvlReq;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_C5WV_BPosSetReq_C5WV_BPosSetReq;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_C5WV_RefDrvReq_C5WV_RefDrvReq;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_C5WV_SpdLvlReq_C5WV_SpdLvlReq;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_HP_EXV_initialize_command_B_HP_EXV_initialize_command_B;
    P2VAR(Rte_DE_Boolean_status, AUTOMATIC, RTE_DATA)  Task_100ms_HP_EXV_movenable_command_B_HP_EXV_movenable_command_B;
    P2VAR(Rte_DE_UInt16_status, AUTOMATIC, RTE_DATA)  Task_100ms_HP_EXV_position_command_B_HP_EXV_position_command_B;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_MotPMP_SpdSet_MotPMP_SpdSet;
    P2VAR(Rte_DE_Boolean_status, AUTOMATIC, RTE_DATA)  Task_100ms_TMM_EXV_EnableRequest_TMM_EXV_EnableRequest;
    P2VAR(Rte_DE_UInt16_status, AUTOMATIC, RTE_DATA)  Task_100ms_TMM_EXV_PositionRequest_TMM_EXV_PositionRequest;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Task_100ms_TMM_EXV_initRequest_TMM_EXV_initRequest;
    P2VAR(Rte_DE_TMS2VCU_AC_1_Command_Outputs_status, AUTOMATIC, RTE_DATA)  Task_100ms_TMS2VCU_AC_1_Command_Outputs_TMS2VCU_AC_1_Command_Outputs;
    P2VAR(Rte_DE_TMS2VCU_AC_2_State_Outputs_status, AUTOMATIC, RTE_DATA)  Task_100ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs;
    P2VAR(Rte_DE_TMS2VCU_AC_3_State_Outputs_status, AUTOMATIC, RTE_DATA)  Task_100ms_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs;
    P2VAR(Rte_DE_TMS2VCU_AC_8_status_Outputs_status, AUTOMATIC, RTE_DATA)  Task_100ms_TMS2VCU_AC_8_status_Outputs_TMS2VCU_AC_8_status_Outputs;
    P2VAR(Rte_DE_TMS2VCU_AC_ACStatuts_Outputs_status, AUTOMATIC, RTE_DATA)  Task_100ms_TMS2VCU_AC_ACStatuts_Outputs_TMS2VCU_AC_ACStatuts_Outputs;
    P2VAR(Rte_DE_TMS2VCU_AC_COMP_Outputs_status, AUTOMATIC, RTE_DATA)  Task_100ms_TMS2VCU_AC_COMP_Outputs_TMS2VCU_AC_COMP_Outputs;
    P2VAR(Rte_DE_TMS2VCU_HVCH_Command_Outputs_status, AUTOMATIC, RTE_DATA)  Task_100ms_TMS2VCU_HVCH_Command_Outputs_TMS2VCU_HVCH_Command_Outputs;
    P2VAR(Rte_DE_TMS2VCU_TMS_LINTestData1_Outputs_status, AUTOMATIC, RTE_DATA)  Task_100ms_TMS2VCU_TMS_LINTestData1_Outputs_TMS2VCU_TMS_LINTestData1_Outputs;
    P2VAR(Rte_DE_TMS2VCU_TMS_LINTestData2_Outputs_status, AUTOMATIC, RTE_DATA)  Task_100ms_TMS2VCU_TMS_LINTestData2_Outputs_TMS2VCU_TMS_LINTestData2_Outputs;
    P2VAR(Rte_DE_TMS2VCU_TMS_LINTestData3_Outputs_status, AUTOMATIC, RTE_DATA)  Task_100ms_TMS2VCU_TMS_LINTestData3_Outputs_TMS2VCU_TMS_LINTestData3_Outputs;
    P2VAR(Rte_DE_Tms2Vcu_Info_status, AUTOMATIC, RTE_DATA)  Task_100ms_Tms2Vcu_Info_Tms2Vcu_Info;
} Rte_CDS_ME11;

extern CONST(Rte_CDS_ME11, RTE_CONST) Rte_Inst_ME11;

#ifndef RTE_CORE
typedef CONSTP2CONST(Rte_CDS_ME11, AUTOMATIC, RTE_CONST) Rte_Instance;
#endif

/** API mappings */

#ifndef RTE_CORE

#define Rte_IRead_Task_100ms_AcPMP_HWVersion_AcPMP_HWVersion() (Rte_Inst_ME11.Task_100ms_AcPMP_HWVersion_AcPMP_HWVersion->value)

#define Rte_IRead_Task_100ms_AcPMP_PartNumber_AcPMP_PartNumber() (Rte_Inst_ME11.Task_100ms_AcPMP_PartNumber_AcPMP_PartNumber->value)

#define Rte_IRead_Task_100ms_AcPMP_ProjectCode1_AcPMP_ProjectCode1() (Rte_Inst_ME11.Task_100ms_AcPMP_ProjectCode1_AcPMP_ProjectCode1->value)

#define Rte_IRead_Task_100ms_AcPMP_ProjectCode2_AcPMP_ProjectCode2() (Rte_Inst_ME11.Task_100ms_AcPMP_ProjectCode2_AcPMP_ProjectCode2->value)

#define Rte_IRead_Task_100ms_AcPMP_PumpDryRunningSta_AcPMP_PumpDryRunningSta() (Rte_Inst_ME11.Task_100ms_AcPMP_PumpDryRunningSta_AcPMP_PumpDryRunningSta->value)

#define Rte_IRead_Task_100ms_AcPMP_PumpInputVolt_AcPMP_PumpInputVolt() (Rte_Inst_ME11.Task_100ms_AcPMP_PumpInputVolt_AcPMP_PumpInputVolt->value)

#define Rte_IRead_Task_100ms_AcPMP_PumpMotorSta_AcPMP_PumpMotorSta() (Rte_Inst_ME11.Task_100ms_AcPMP_PumpMotorSta_AcPMP_PumpMotorSta->value)

#define Rte_IRead_Task_100ms_AcPMP_PumpPowerSta_AcPMP_PumpPowerSta() (Rte_Inst_ME11.Task_100ms_AcPMP_PumpPowerSta_AcPMP_PumpPowerSta->value)

#define Rte_IRead_Task_100ms_AcPMP_PumpTempSta_AcPMP_PumpTempSta() (Rte_Inst_ME11.Task_100ms_AcPMP_PumpTempSta_AcPMP_PumpTempSta->value)

#define Rte_IRead_Task_100ms_AcPMP_RESP_ERROR_AcPMP_RESP_ERROR() (Rte_Inst_ME11.Task_100ms_AcPMP_RESP_ERROR_AcPMP_RESP_ERROR->value)

#define Rte_IRead_Task_100ms_AcPMP_RealRPM_AcPMP_RealRPM() (Rte_Inst_ME11.Task_100ms_AcPMP_RealRPM_AcPMP_RealRPM->value)

#define Rte_IRead_Task_100ms_AcPMP_SWVersion_Main_AcPMP_SWVersion_Main() (Rte_Inst_ME11.Task_100ms_AcPMP_SWVersion_Main_AcPMP_SWVersion_Main->value)

#define Rte_IRead_Task_100ms_AcPMP_SWVersion_Patch_AcPMP_SWVersion_Patch() (Rte_Inst_ME11.Task_100ms_AcPMP_SWVersion_Patch_AcPMP_SWVersion_Patch->value)

#define Rte_IRead_Task_100ms_AcPMP_SWVersion_Sub_AcPMP_SWVersion_Sub() (Rte_Inst_ME11.Task_100ms_AcPMP_SWVersion_Sub_AcPMP_SWVersion_Sub->value)

#define Rte_IRead_Task_100ms_AcPMP_SupplierNumber_AcPMP_SupplierNumber() (Rte_Inst_ME11.Task_100ms_AcPMP_SupplierNumber_AcPMP_SupplierNumber->value)

#define Rte_IRead_Task_100ms_BAT_EXV_CurrentPosition_B_BAT_EXV_CurrentPosition_B() (Rte_Inst_ME11.Task_100ms_BAT_EXV_CurrentPosition_B_BAT_EXV_CurrentPosition_B->value)

#define Rte_IRead_Task_100ms_BAT_EXV_FaultState_B_BAT_EXV_FaultState_B() (Rte_Inst_ME11.Task_100ms_BAT_EXV_FaultState_B_BAT_EXV_FaultState_B->value)

#define Rte_IRead_Task_100ms_BAT_EXV_ResponseError_B_BAT_EXV_ResponseError_B() (Rte_Inst_ME11.Task_100ms_BAT_EXV_ResponseError_B_BAT_EXV_ResponseError_B->value)

#define Rte_IRead_Task_100ms_BAT_EXV_RunState_B_BAT_EXV_RunState_B() (Rte_Inst_ME11.Task_100ms_BAT_EXV_RunState_B_BAT_EXV_RunState_B->value)

#define Rte_IRead_Task_100ms_BAT_EXV_SupplierLabel_BAT_EXV_SupplierLabel() (Rte_Inst_ME11.Task_100ms_BAT_EXV_SupplierLabel_BAT_EXV_SupplierLabel->value)

#define Rte_IRead_Task_100ms_BAT_EXV_VoltageState_B_BAT_EXV_VoltageState_B() (Rte_Inst_ME11.Task_100ms_BAT_EXV_VoltageState_B_BAT_EXV_VoltageState_B->value)

#define Rte_IRead_Task_100ms_BAT_EXV_Warning_OverTemp_BAT_EXV_Warning_OverTemp() (Rte_Inst_ME11.Task_100ms_BAT_EXV_Warning_OverTemp_BAT_EXV_Warning_OverTemp->value)

#define Rte_IRead_Task_100ms_BAT_EXV_initialize_status_BAT_EXV_initialize_status() (Rte_Inst_ME11.Task_100ms_BAT_EXV_initialize_status_BAT_EXV_initialize_status->value)

#define Rte_IRead_Task_100ms_BatPMP_PumpDryRunningSta_BatPMP_PumpDryRunningSta() (Rte_Inst_ME11.Task_100ms_BatPMP_PumpDryRunningSta_BatPMP_PumpDryRunningSta->value)

#define Rte_IRead_Task_100ms_BatPMP_PumpInputVolt_BatPMP_PumpInputVolt() (Rte_Inst_ME11.Task_100ms_BatPMP_PumpInputVolt_BatPMP_PumpInputVolt->value)

#define Rte_IRead_Task_100ms_BatPMP_PumpMotorSta_BatPMP_PumpMotorSta() (Rte_Inst_ME11.Task_100ms_BatPMP_PumpMotorSta_BatPMP_PumpMotorSta->value)

#define Rte_IRead_Task_100ms_BatPMP_PumpPowerSta_BatPMP_PumpPowerSta() (Rte_Inst_ME11.Task_100ms_BatPMP_PumpPowerSta_BatPMP_PumpPowerSta->value)

#define Rte_IRead_Task_100ms_BatPMP_PumpTempSta_BatPMP_PumpTempSta() (Rte_Inst_ME11.Task_100ms_BatPMP_PumpTempSta_BatPMP_PumpTempSta->value)

#define Rte_IRead_Task_100ms_BatPMP_RESP_ERROR_BatPMP_RESP_ERROR() (Rte_Inst_ME11.Task_100ms_BatPMP_RESP_ERROR_BatPMP_RESP_ERROR->value)

#define Rte_IRead_Task_100ms_BatPMP_RealRPM_BatPMP_RealRPM() (Rte_Inst_ME11.Task_100ms_BatPMP_RealRPM_BatPMP_RealRPM->value)

#define Rte_IRead_Task_100ms_Bat_EXV_HWVersion_Bat_EXV_HWVersion() (Rte_Inst_ME11.Task_100ms_Bat_EXV_HWVersion_Bat_EXV_HWVersion->value)

#define Rte_IRead_Task_100ms_Bat_EXV_PartNumber_Bat_EXV_PartNumber() (Rte_Inst_ME11.Task_100ms_Bat_EXV_PartNumber_Bat_EXV_PartNumber->value)

#define Rte_IRead_Task_100ms_Bat_EXV_ProjectCode1_Bat_EXV_ProjectCode1() (Rte_Inst_ME11.Task_100ms_Bat_EXV_ProjectCode1_Bat_EXV_ProjectCode1->value)

#define Rte_IRead_Task_100ms_Bat_EXV_ProjectCode2_Bat_EXV_ProjectCode2() (Rte_Inst_ME11.Task_100ms_Bat_EXV_ProjectCode2_Bat_EXV_ProjectCode2->value)

#define Rte_IRead_Task_100ms_Bat_EXV_SWVersion_Main_Bat_EXV_SWVersion_Main() (Rte_Inst_ME11.Task_100ms_Bat_EXV_SWVersion_Main_Bat_EXV_SWVersion_Main->value)

#define Rte_IRead_Task_100ms_Bat_EXV_SWVersion_Patch_Bat_EXV_SWVersion_Patch() (Rte_Inst_ME11.Task_100ms_Bat_EXV_SWVersion_Patch_Bat_EXV_SWVersion_Patch->value)

#define Rte_IRead_Task_100ms_Bat_EXV_SWVersion_Sub_Bat_EXV_SWVersion_Sub() (Rte_Inst_ME11.Task_100ms_Bat_EXV_SWVersion_Sub_Bat_EXV_SWVersion_Sub->value)

#define Rte_IRead_Task_100ms_Bat_EXV_SupplierNumber_Bat_EXV_SupplierNumber() (Rte_Inst_ME11.Task_100ms_Bat_EXV_SupplierNumber_Bat_EXV_SupplierNumber->value)

#define Rte_IRead_Task_100ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs() (&Rte_Inst_ME11.Task_100ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs->value)

#define Rte_IRead_Task_100ms_C3WV_ErrResp_C3WV_ErrResp() (Rte_Inst_ME11.Task_100ms_C3WV_ErrResp_C3WV_ErrResp->value)

#define Rte_IRead_Task_100ms_C3WV_FltSts_C3WV_FltSts() (Rte_Inst_ME11.Task_100ms_C3WV_FltSts_C3WV_FltSts->value)

#define Rte_IRead_Task_100ms_C3WV_Mode_C3WV_Mode() (Rte_Inst_ME11.Task_100ms_C3WV_Mode_C3WV_Mode->value)

#define Rte_IRead_Task_100ms_C3WV_PosRec_C3WV_PosRec() (Rte_Inst_ME11.Task_100ms_C3WV_PosRec_C3WV_PosRec->value)

#define Rte_IRead_Task_100ms_C3WV_RunSts_C3WV_RunSts() (Rte_Inst_ME11.Task_100ms_C3WV_RunSts_C3WV_RunSts->value)

#define Rte_IRead_Task_100ms_C3WV_SpdLvl_C3WV_SpdLvl() (Rte_Inst_ME11.Task_100ms_C3WV_SpdLvl_C3WV_SpdLvl->value)

#define Rte_IRead_Task_100ms_C3WV_TempSts_C3WV_TempSts() (Rte_Inst_ME11.Task_100ms_C3WV_TempSts_C3WV_TempSts->value)

#define Rte_IRead_Task_100ms_C3WV_VoltSts_C3WV_VoltSts() (Rte_Inst_ME11.Task_100ms_C3WV_VoltSts_C3WV_VoltSts->value)

#define Rte_IRead_Task_100ms_C5WVFltSts_C5WVFltSts() (Rte_Inst_ME11.Task_100ms_C5WVFltSts_C5WVFltSts->value)

#define Rte_IRead_Task_100ms_C5WVMode_C5WVMode() (Rte_Inst_ME11.Task_100ms_C5WVMode_C5WVMode->value)

#define Rte_IRead_Task_100ms_C5WVPosRec_C5WVPosRec() (Rte_Inst_ME11.Task_100ms_C5WVPosRec_C5WVPosRec->value)

#define Rte_IRead_Task_100ms_C5WVRunSts_C5WVRunSts() (Rte_Inst_ME11.Task_100ms_C5WVRunSts_C5WVRunSts->value)

#define Rte_IRead_Task_100ms_C5WVSpdLvl_C5WVSpdLvl() (Rte_Inst_ME11.Task_100ms_C5WVSpdLvl_C5WVSpdLvl->value)

#define Rte_IRead_Task_100ms_C5WVTempSts_C5WVTempSts() (Rte_Inst_ME11.Task_100ms_C5WVTempSts_C5WVTempSts->value)

#define Rte_IRead_Task_100ms_C5WVVoltSts_C5WVVoltSts() (Rte_Inst_ME11.Task_100ms_C5WVVoltSts_C5WVVoltSts->value)

#define Rte_IRead_Task_100ms_EXV_CurrentInitState_EXV_CurrentInitState() (Rte_Inst_ME11.Task_100ms_EXV_CurrentInitState_EXV_CurrentInitState->value)

#define Rte_IRead_Task_100ms_EXV_CurrentPosition_EXV_CurrentPosition() (Rte_Inst_ME11.Task_100ms_EXV_CurrentPosition_EXV_CurrentPosition->value)

#define Rte_IRead_Task_100ms_EXV_FaultState_EXV_FaultState() (Rte_Inst_ME11.Task_100ms_EXV_FaultState_EXV_FaultState->value)

#define Rte_IRead_Task_100ms_EXV_ResponseError_EXV_ResponseError() (Rte_Inst_ME11.Task_100ms_EXV_ResponseError_EXV_ResponseError->value)

#define Rte_IRead_Task_100ms_EXV_RunState_EXV_RunState() (Rte_Inst_ME11.Task_100ms_EXV_RunState_EXV_RunState->value)

#define Rte_IRead_Task_100ms_EXV_TemperatureWarn_EXV_TemperatureWarn() (Rte_Inst_ME11.Task_100ms_EXV_TemperatureWarn_EXV_TemperatureWarn->value)

#define Rte_IRead_Task_100ms_EXV_VoltageState_EXV_VoltageState() (Rte_Inst_ME11.Task_100ms_EXV_VoltageState_EXV_VoltageState->value)

#define Rte_IRead_Task_100ms_ErrRespC5WV_ErrRespC5WV() (Rte_Inst_ME11.Task_100ms_ErrRespC5WV_ErrRespC5WV->value)

#define Rte_IRead_Task_100ms_HP_EXV_CurrentPosition_B_HP_EXV_CurrentPosition_B() (Rte_Inst_ME11.Task_100ms_HP_EXV_CurrentPosition_B_HP_EXV_CurrentPosition_B->value)

#define Rte_IRead_Task_100ms_HP_EXV_FaultState_B_HP_EXV_FaultState_B() (Rte_Inst_ME11.Task_100ms_HP_EXV_FaultState_B_HP_EXV_FaultState_B->value)

#define Rte_IRead_Task_100ms_HP_EXV_HWVersion_HP_EXV_HWVersion() (Rte_Inst_ME11.Task_100ms_HP_EXV_HWVersion_HP_EXV_HWVersion->value)

#define Rte_IRead_Task_100ms_HP_EXV_PartNumber_HP_EXV_PartNumber() (Rte_Inst_ME11.Task_100ms_HP_EXV_PartNumber_HP_EXV_PartNumber->value)

#define Rte_IRead_Task_100ms_HP_EXV_ProjectCode1_HP_EXV_ProjectCode1() (Rte_Inst_ME11.Task_100ms_HP_EXV_ProjectCode1_HP_EXV_ProjectCode1->value)

#define Rte_IRead_Task_100ms_HP_EXV_ProjectCode2_HP_EXV_ProjectCode2() (Rte_Inst_ME11.Task_100ms_HP_EXV_ProjectCode2_HP_EXV_ProjectCode2->value)

#define Rte_IRead_Task_100ms_HP_EXV_ResponseError_B_HP_EXV_ResponseError_B() (Rte_Inst_ME11.Task_100ms_HP_EXV_ResponseError_B_HP_EXV_ResponseError_B->value)

#define Rte_IRead_Task_100ms_HP_EXV_RunState_B_HP_EXV_RunState_B() (Rte_Inst_ME11.Task_100ms_HP_EXV_RunState_B_HP_EXV_RunState_B->value)

#define Rte_IRead_Task_100ms_HP_EXV_SWVersion_Main_HP_EXV_SWVersion_Main() (Rte_Inst_ME11.Task_100ms_HP_EXV_SWVersion_Main_HP_EXV_SWVersion_Main->value)

#define Rte_IRead_Task_100ms_HP_EXV_SWVersion_Patch_HP_EXV_SWVersion_Patch() (Rte_Inst_ME11.Task_100ms_HP_EXV_SWVersion_Patch_HP_EXV_SWVersion_Patch->value)

#define Rte_IRead_Task_100ms_HP_EXV_SWVersion_Sub_HP_EXV_SWVersion_Sub() (Rte_Inst_ME11.Task_100ms_HP_EXV_SWVersion_Sub_HP_EXV_SWVersion_Sub->value)

#define Rte_IRead_Task_100ms_HP_EXV_SupplierLabel_HP_EXV_SupplierLabel() (Rte_Inst_ME11.Task_100ms_HP_EXV_SupplierLabel_HP_EXV_SupplierLabel->value)

#define Rte_IRead_Task_100ms_HP_EXV_SupplierNumber_HP_EXV_SupplierNumber() (Rte_Inst_ME11.Task_100ms_HP_EXV_SupplierNumber_HP_EXV_SupplierNumber->value)

#define Rte_IRead_Task_100ms_HP_EXV_VoltageState_B_HP_EXV_VoltageState_B() (Rte_Inst_ME11.Task_100ms_HP_EXV_VoltageState_B_HP_EXV_VoltageState_B->value)

#define Rte_IRead_Task_100ms_HP_EXV_Warning_OverTemp_HP_EXV_Warning_OverTemp() (Rte_Inst_ME11.Task_100ms_HP_EXV_Warning_OverTemp_HP_EXV_Warning_OverTemp->value)

#define Rte_IRead_Task_100ms_HP_EXV_initialize_status_HP_EXV_initialize_status() (Rte_Inst_ME11.Task_100ms_HP_EXV_initialize_status_HP_EXV_initialize_status->value)

#define Rte_IRead_Task_100ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT() (&Rte_Inst_ME11.Task_100ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT->value)

#define Rte_IRead_Task_100ms_IPM_BMS_2_BatState_EPT_IPM_BMS_2_BatState_EPT() (&Rte_Inst_ME11.Task_100ms_IPM_BMS_2_BatState_EPT_IPM_BMS_2_BatState_EPT->value)

#define Rte_IRead_Task_100ms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT() (&Rte_Inst_ME11.Task_100ms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT->value)

#define Rte_IRead_Task_100ms_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT() (&Rte_Inst_ME11.Task_100ms_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT->value)

#define Rte_IRead_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD() (&Rte_Inst_ME11.Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD->value)

#define Rte_IRead_Task_100ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD() (&Rte_Inst_ME11.Task_100ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD->value)

#define Rte_IRead_Task_100ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA() (&Rte_Inst_ME11.Task_100ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA->value)

#define Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC() (&Rte_Inst_ME11.Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC->value)

#define Rte_IRead_Task_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD() (&Rte_Inst_ME11.Task_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD->value)

#define Rte_IRead_Task_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD() (&Rte_Inst_ME11.Task_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD->value)

#define Rte_IRead_Task_100ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT() (&Rte_Inst_ME11.Task_100ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT->value)

#define Rte_IRead_Task_100ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT() (&Rte_Inst_ME11.Task_100ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT->value)

#define Rte_IRead_Task_100ms_MotPMP_PumpDryRunningSta_MotPMP_PumpDryRunningSta() (Rte_Inst_ME11.Task_100ms_MotPMP_PumpDryRunningSta_MotPMP_PumpDryRunningSta->value)

#define Rte_IRead_Task_100ms_MotPMP_PumpInputVolt_MotPMP_PumpInputVolt() (Rte_Inst_ME11.Task_100ms_MotPMP_PumpInputVolt_MotPMP_PumpInputVolt->value)

#define Rte_IRead_Task_100ms_MotPMP_PumpMotorSta_MotPMP_PumpMotorSta() (Rte_Inst_ME11.Task_100ms_MotPMP_PumpMotorSta_MotPMP_PumpMotorSta->value)

#define Rte_IRead_Task_100ms_MotPMP_PumpPowerSta_MotPMP_PumpPowerSta() (Rte_Inst_ME11.Task_100ms_MotPMP_PumpPowerSta_MotPMP_PumpPowerSta->value)

#define Rte_IRead_Task_100ms_MotPMP_PumpTempSta_MotPMP_PumpTempSta() (Rte_Inst_ME11.Task_100ms_MotPMP_PumpTempSta_MotPMP_PumpTempSta->value)

#define Rte_IRead_Task_100ms_MotPMP_RESP_ERROR_MotPMP_RESP_ERROR() (Rte_Inst_ME11.Task_100ms_MotPMP_RESP_ERROR_MotPMP_RESP_ERROR->value)

#define Rte_IRead_Task_100ms_MotPMP_RealRPM_MotPMP_RealRPM() (Rte_Inst_ME11.Task_100ms_MotPMP_RealRPM_MotPMP_RealRPM->value)

#define Rte_IRead_Task_100ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs() (&Rte_Inst_ME11.Task_100ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs->value)

#define Rte_IWrite_Task_100ms_AcPMP_SpdSet_AcPMP_SpdSet(data) (Rte_Inst_ME11.Task_100ms_AcPMP_SpdSet_AcPMP_SpdSet->value = (data))

#define Rte_IWriteRef_Task_100ms_AcPMP_SpdSet_AcPMP_SpdSet() (&Rte_Inst_ME11.Task_100ms_AcPMP_SpdSet_AcPMP_SpdSet->value)

#define Rte_IWrite_Task_100ms_BAT_EXV_initialize_command_B_BAT_EXV_initialize_command_B(data) (Rte_Inst_ME11.Task_100ms_BAT_EXV_initialize_command_B_BAT_EXV_initialize_command_B->value = (data))

#define Rte_IWriteRef_Task_100ms_BAT_EXV_initialize_command_B_BAT_EXV_initialize_command_B() (&Rte_Inst_ME11.Task_100ms_BAT_EXV_initialize_command_B_BAT_EXV_initialize_command_B->value)

#define Rte_IWrite_Task_100ms_BAT_EXV_movenable_command_B_BAT_EXV_movenable_command_B(data) (Rte_Inst_ME11.Task_100ms_BAT_EXV_movenable_command_B_BAT_EXV_movenable_command_B->value = (data))

#define Rte_IWriteRef_Task_100ms_BAT_EXV_movenable_command_B_BAT_EXV_movenable_command_B() (&Rte_Inst_ME11.Task_100ms_BAT_EXV_movenable_command_B_BAT_EXV_movenable_command_B->value)

#define Rte_IWrite_Task_100ms_BAT_EXV_position_command_B_BAT_EXV_position_command_B(data) (Rte_Inst_ME11.Task_100ms_BAT_EXV_position_command_B_BAT_EXV_position_command_B->value = (data))

#define Rte_IWriteRef_Task_100ms_BAT_EXV_position_command_B_BAT_EXV_position_command_B() (&Rte_Inst_ME11.Task_100ms_BAT_EXV_position_command_B_BAT_EXV_position_command_B->value)

#define Rte_IWrite_Task_100ms_BatPMP_SpdSet_BatPMP_SpdSet(data) (Rte_Inst_ME11.Task_100ms_BatPMP_SpdSet_BatPMP_SpdSet->value = (data))

#define Rte_IWriteRef_Task_100ms_BatPMP_SpdSet_BatPMP_SpdSet() (&Rte_Inst_ME11.Task_100ms_BatPMP_SpdSet_BatPMP_SpdSet->value)

#define Rte_IWrite_Task_100ms_C3WV_BPosSetReq_C3WV_BPosSetReq(data) (Rte_Inst_ME11.Task_100ms_C3WV_BPosSetReq_C3WV_BPosSetReq->value = (data))

#define Rte_IWriteRef_Task_100ms_C3WV_BPosSetReq_C3WV_BPosSetReq() (&Rte_Inst_ME11.Task_100ms_C3WV_BPosSetReq_C3WV_BPosSetReq->value)

#define Rte_IWrite_Task_100ms_C3WV_RefDrvReq_C3WV_RefDrvReq(data) (Rte_Inst_ME11.Task_100ms_C3WV_RefDrvReq_C3WV_RefDrvReq->value = (data))

#define Rte_IWriteRef_Task_100ms_C3WV_RefDrvReq_C3WV_RefDrvReq() (&Rte_Inst_ME11.Task_100ms_C3WV_RefDrvReq_C3WV_RefDrvReq->value)

#define Rte_IWrite_Task_100ms_C3WV_SpdLvlReq_C3WV_SpdLvlReq(data) (Rte_Inst_ME11.Task_100ms_C3WV_SpdLvlReq_C3WV_SpdLvlReq->value = (data))

#define Rte_IWriteRef_Task_100ms_C3WV_SpdLvlReq_C3WV_SpdLvlReq() (&Rte_Inst_ME11.Task_100ms_C3WV_SpdLvlReq_C3WV_SpdLvlReq->value)

#define Rte_IWrite_Task_100ms_C5WV_BPosSetReq_C5WV_BPosSetReq(data) (Rte_Inst_ME11.Task_100ms_C5WV_BPosSetReq_C5WV_BPosSetReq->value = (data))

#define Rte_IWriteRef_Task_100ms_C5WV_BPosSetReq_C5WV_BPosSetReq() (&Rte_Inst_ME11.Task_100ms_C5WV_BPosSetReq_C5WV_BPosSetReq->value)

#define Rte_IWrite_Task_100ms_C5WV_RefDrvReq_C5WV_RefDrvReq(data) (Rte_Inst_ME11.Task_100ms_C5WV_RefDrvReq_C5WV_RefDrvReq->value = (data))

#define Rte_IWriteRef_Task_100ms_C5WV_RefDrvReq_C5WV_RefDrvReq() (&Rte_Inst_ME11.Task_100ms_C5WV_RefDrvReq_C5WV_RefDrvReq->value)

#define Rte_IWrite_Task_100ms_C5WV_SpdLvlReq_C5WV_SpdLvlReq(data) (Rte_Inst_ME11.Task_100ms_C5WV_SpdLvlReq_C5WV_SpdLvlReq->value = (data))

#define Rte_IWriteRef_Task_100ms_C5WV_SpdLvlReq_C5WV_SpdLvlReq() (&Rte_Inst_ME11.Task_100ms_C5WV_SpdLvlReq_C5WV_SpdLvlReq->value)

#define Rte_IWrite_Task_100ms_HP_EXV_initialize_command_B_HP_EXV_initialize_command_B(data) (Rte_Inst_ME11.Task_100ms_HP_EXV_initialize_command_B_HP_EXV_initialize_command_B->value = (data))

#define Rte_IWriteRef_Task_100ms_HP_EXV_initialize_command_B_HP_EXV_initialize_command_B() (&Rte_Inst_ME11.Task_100ms_HP_EXV_initialize_command_B_HP_EXV_initialize_command_B->value)

#define Rte_IWrite_Task_100ms_HP_EXV_movenable_command_B_HP_EXV_movenable_command_B(data) (Rte_Inst_ME11.Task_100ms_HP_EXV_movenable_command_B_HP_EXV_movenable_command_B->value = (data))

#define Rte_IWriteRef_Task_100ms_HP_EXV_movenable_command_B_HP_EXV_movenable_command_B() (&Rte_Inst_ME11.Task_100ms_HP_EXV_movenable_command_B_HP_EXV_movenable_command_B->value)

#define Rte_IWrite_Task_100ms_HP_EXV_position_command_B_HP_EXV_position_command_B(data) (Rte_Inst_ME11.Task_100ms_HP_EXV_position_command_B_HP_EXV_position_command_B->value = (data))

#define Rte_IWriteRef_Task_100ms_HP_EXV_position_command_B_HP_EXV_position_command_B() (&Rte_Inst_ME11.Task_100ms_HP_EXV_position_command_B_HP_EXV_position_command_B->value)

#define Rte_IWrite_Task_100ms_MotPMP_SpdSet_MotPMP_SpdSet(data) (Rte_Inst_ME11.Task_100ms_MotPMP_SpdSet_MotPMP_SpdSet->value = (data))

#define Rte_IWriteRef_Task_100ms_MotPMP_SpdSet_MotPMP_SpdSet() (&Rte_Inst_ME11.Task_100ms_MotPMP_SpdSet_MotPMP_SpdSet->value)

#define Rte_IWrite_Task_100ms_TMM_EXV_EnableRequest_TMM_EXV_EnableRequest(data) (Rte_Inst_ME11.Task_100ms_TMM_EXV_EnableRequest_TMM_EXV_EnableRequest->value = (data))

#define Rte_IWriteRef_Task_100ms_TMM_EXV_EnableRequest_TMM_EXV_EnableRequest() (&Rte_Inst_ME11.Task_100ms_TMM_EXV_EnableRequest_TMM_EXV_EnableRequest->value)

#define Rte_IWrite_Task_100ms_TMM_EXV_PositionRequest_TMM_EXV_PositionRequest(data) (Rte_Inst_ME11.Task_100ms_TMM_EXV_PositionRequest_TMM_EXV_PositionRequest->value = (data))

#define Rte_IWriteRef_Task_100ms_TMM_EXV_PositionRequest_TMM_EXV_PositionRequest() (&Rte_Inst_ME11.Task_100ms_TMM_EXV_PositionRequest_TMM_EXV_PositionRequest->value)

#define Rte_IWrite_Task_100ms_TMM_EXV_initRequest_TMM_EXV_initRequest(data) (Rte_Inst_ME11.Task_100ms_TMM_EXV_initRequest_TMM_EXV_initRequest->value = (data))

#define Rte_IWriteRef_Task_100ms_TMM_EXV_initRequest_TMM_EXV_initRequest() (&Rte_Inst_ME11.Task_100ms_TMM_EXV_initRequest_TMM_EXV_initRequest->value)

#define Rte_IWrite_Task_100ms_TMS2VCU_AC_1_Command_Outputs_TMS2VCU_AC_1_Command_Outputs(data) (Rte_Inst_ME11.Task_100ms_TMS2VCU_AC_1_Command_Outputs_TMS2VCU_AC_1_Command_Outputs->value = *(data))

#define Rte_IWriteRef_Task_100ms_TMS2VCU_AC_1_Command_Outputs_TMS2VCU_AC_1_Command_Outputs() (&Rte_Inst_ME11.Task_100ms_TMS2VCU_AC_1_Command_Outputs_TMS2VCU_AC_1_Command_Outputs->value)

#define Rte_IWrite_Task_100ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs(data) (Rte_Inst_ME11.Task_100ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs->value = *(data))

#define Rte_IWriteRef_Task_100ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs() (&Rte_Inst_ME11.Task_100ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs->value)

#define Rte_IWrite_Task_100ms_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs(data) (Rte_Inst_ME11.Task_100ms_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs->value = *(data))

#define Rte_IWriteRef_Task_100ms_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs() (&Rte_Inst_ME11.Task_100ms_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs->value)

#define Rte_IWrite_Task_100ms_TMS2VCU_AC_8_status_Outputs_TMS2VCU_AC_8_status_Outputs(data) (Rte_Inst_ME11.Task_100ms_TMS2VCU_AC_8_status_Outputs_TMS2VCU_AC_8_status_Outputs->value = *(data))

#define Rte_IWriteRef_Task_100ms_TMS2VCU_AC_8_status_Outputs_TMS2VCU_AC_8_status_Outputs() (&Rte_Inst_ME11.Task_100ms_TMS2VCU_AC_8_status_Outputs_TMS2VCU_AC_8_status_Outputs->value)

#define Rte_IWrite_Task_100ms_TMS2VCU_AC_ACStatuts_Outputs_TMS2VCU_AC_ACStatuts_Outputs(data) (Rte_Inst_ME11.Task_100ms_TMS2VCU_AC_ACStatuts_Outputs_TMS2VCU_AC_ACStatuts_Outputs->value = *(data))

#define Rte_IWriteRef_Task_100ms_TMS2VCU_AC_ACStatuts_Outputs_TMS2VCU_AC_ACStatuts_Outputs() (&Rte_Inst_ME11.Task_100ms_TMS2VCU_AC_ACStatuts_Outputs_TMS2VCU_AC_ACStatuts_Outputs->value)

#define Rte_IWrite_Task_100ms_TMS2VCU_AC_COMP_Outputs_TMS2VCU_AC_COMP_Outputs(data) (Rte_Inst_ME11.Task_100ms_TMS2VCU_AC_COMP_Outputs_TMS2VCU_AC_COMP_Outputs->value = *(data))

#define Rte_IWriteRef_Task_100ms_TMS2VCU_AC_COMP_Outputs_TMS2VCU_AC_COMP_Outputs() (&Rte_Inst_ME11.Task_100ms_TMS2VCU_AC_COMP_Outputs_TMS2VCU_AC_COMP_Outputs->value)

#define Rte_IWrite_Task_100ms_TMS2VCU_HVCH_Command_Outputs_TMS2VCU_HVCH_Command_Outputs(data) (Rte_Inst_ME11.Task_100ms_TMS2VCU_HVCH_Command_Outputs_TMS2VCU_HVCH_Command_Outputs->value = *(data))

#define Rte_IWriteRef_Task_100ms_TMS2VCU_HVCH_Command_Outputs_TMS2VCU_HVCH_Command_Outputs() (&Rte_Inst_ME11.Task_100ms_TMS2VCU_HVCH_Command_Outputs_TMS2VCU_HVCH_Command_Outputs->value)

#define Rte_IWrite_Task_100ms_TMS2VCU_TMS_LINTestData1_Outputs_TMS2VCU_TMS_LINTestData1_Outputs(data) (Rte_Inst_ME11.Task_100ms_TMS2VCU_TMS_LINTestData1_Outputs_TMS2VCU_TMS_LINTestData1_Outputs->value = *(data))

#define Rte_IWriteRef_Task_100ms_TMS2VCU_TMS_LINTestData1_Outputs_TMS2VCU_TMS_LINTestData1_Outputs() (&Rte_Inst_ME11.Task_100ms_TMS2VCU_TMS_LINTestData1_Outputs_TMS2VCU_TMS_LINTestData1_Outputs->value)

#define Rte_IWrite_Task_100ms_TMS2VCU_TMS_LINTestData2_Outputs_TMS2VCU_TMS_LINTestData2_Outputs(data) (Rte_Inst_ME11.Task_100ms_TMS2VCU_TMS_LINTestData2_Outputs_TMS2VCU_TMS_LINTestData2_Outputs->value = *(data))

#define Rte_IWriteRef_Task_100ms_TMS2VCU_TMS_LINTestData2_Outputs_TMS2VCU_TMS_LINTestData2_Outputs() (&Rte_Inst_ME11.Task_100ms_TMS2VCU_TMS_LINTestData2_Outputs_TMS2VCU_TMS_LINTestData2_Outputs->value)

#define Rte_IWrite_Task_100ms_TMS2VCU_TMS_LINTestData3_Outputs_TMS2VCU_TMS_LINTestData3_Outputs(data) (Rte_Inst_ME11.Task_100ms_TMS2VCU_TMS_LINTestData3_Outputs_TMS2VCU_TMS_LINTestData3_Outputs->value = *(data))

#define Rte_IWriteRef_Task_100ms_TMS2VCU_TMS_LINTestData3_Outputs_TMS2VCU_TMS_LINTestData3_Outputs() (&Rte_Inst_ME11.Task_100ms_TMS2VCU_TMS_LINTestData3_Outputs_TMS2VCU_TMS_LINTestData3_Outputs->value)

#define Rte_IWrite_Task_100ms_Tms2Vcu_Info_Tms2Vcu_Info(data) (Rte_Inst_ME11.Task_100ms_Tms2Vcu_Info_Tms2Vcu_Info->value = *(data))

#define Rte_IWriteRef_Task_100ms_Tms2Vcu_Info_Tms2Vcu_Info() (&Rte_Inst_ME11.Task_100ms_Tms2Vcu_Info_Tms2Vcu_Info->value)

#endif

/*******************************************************************************
 **                        Global Function Declarations                       **
******************************************************************************/

/** API functions */

void Rte_Task_100ms(void);

void Rte_ME11_Init(void);

Std_ReturnType Rte_IStatus_Task_100ms_AcPMP_HWVersion_AcPMP_HWVersion(void);

Std_ReturnType Rte_IStatus_Task_100ms_AcPMP_PartNumber_AcPMP_PartNumber(void);

Std_ReturnType Rte_IStatus_Task_100ms_AcPMP_ProjectCode1_AcPMP_ProjectCode1(void);

Std_ReturnType Rte_IStatus_Task_100ms_AcPMP_ProjectCode2_AcPMP_ProjectCode2(void);

Std_ReturnType Rte_IStatus_Task_100ms_AcPMP_PumpDryRunningSta_AcPMP_PumpDryRunningSta(void);

Std_ReturnType Rte_IStatus_Task_100ms_AcPMP_PumpInputVolt_AcPMP_PumpInputVolt(void);

Std_ReturnType Rte_IStatus_Task_100ms_AcPMP_PumpMotorSta_AcPMP_PumpMotorSta(void);

Std_ReturnType Rte_IStatus_Task_100ms_AcPMP_PumpPowerSta_AcPMP_PumpPowerSta(void);

Std_ReturnType Rte_IStatus_Task_100ms_AcPMP_PumpTempSta_AcPMP_PumpTempSta(void);

Std_ReturnType Rte_IStatus_Task_100ms_AcPMP_RESP_ERROR_AcPMP_RESP_ERROR(void);

Std_ReturnType Rte_IStatus_Task_100ms_AcPMP_RealRPM_AcPMP_RealRPM(void);

Std_ReturnType Rte_IStatus_Task_100ms_AcPMP_SWVersion_Main_AcPMP_SWVersion_Main(void);

Std_ReturnType Rte_IStatus_Task_100ms_AcPMP_SWVersion_Patch_AcPMP_SWVersion_Patch(void);

Std_ReturnType Rte_IStatus_Task_100ms_AcPMP_SWVersion_Sub_AcPMP_SWVersion_Sub(void);

Std_ReturnType Rte_IStatus_Task_100ms_AcPMP_SupplierNumber_AcPMP_SupplierNumber(void);

Std_ReturnType Rte_IStatus_Task_100ms_BAT_EXV_CurrentPosition_B_BAT_EXV_CurrentPosition_B(void);

Std_ReturnType Rte_IStatus_Task_100ms_BAT_EXV_FaultState_B_BAT_EXV_FaultState_B(void);

Std_ReturnType Rte_IStatus_Task_100ms_BAT_EXV_ResponseError_B_BAT_EXV_ResponseError_B(void);

Std_ReturnType Rte_IStatus_Task_100ms_BAT_EXV_RunState_B_BAT_EXV_RunState_B(void);

Std_ReturnType Rte_IStatus_Task_100ms_BAT_EXV_SupplierLabel_BAT_EXV_SupplierLabel(void);

Std_ReturnType Rte_IStatus_Task_100ms_BAT_EXV_VoltageState_B_BAT_EXV_VoltageState_B(void);

Std_ReturnType Rte_IStatus_Task_100ms_BAT_EXV_Warning_OverTemp_BAT_EXV_Warning_OverTemp(void);

Std_ReturnType Rte_IStatus_Task_100ms_BAT_EXV_initialize_status_BAT_EXV_initialize_status(void);

Std_ReturnType Rte_IStatus_Task_100ms_BatPMP_PumpDryRunningSta_BatPMP_PumpDryRunningSta(void);

Std_ReturnType Rte_IStatus_Task_100ms_BatPMP_PumpInputVolt_BatPMP_PumpInputVolt(void);

Std_ReturnType Rte_IStatus_Task_100ms_BatPMP_PumpMotorSta_BatPMP_PumpMotorSta(void);

Std_ReturnType Rte_IStatus_Task_100ms_BatPMP_PumpPowerSta_BatPMP_PumpPowerSta(void);

Std_ReturnType Rte_IStatus_Task_100ms_BatPMP_PumpTempSta_BatPMP_PumpTempSta(void);

Std_ReturnType Rte_IStatus_Task_100ms_BatPMP_RESP_ERROR_BatPMP_RESP_ERROR(void);

Std_ReturnType Rte_IStatus_Task_100ms_BatPMP_RealRPM_BatPMP_RealRPM(void);

Std_ReturnType Rte_IStatus_Task_100ms_Bat_EXV_HWVersion_Bat_EXV_HWVersion(void);

Std_ReturnType Rte_IStatus_Task_100ms_Bat_EXV_PartNumber_Bat_EXV_PartNumber(void);

Std_ReturnType Rte_IStatus_Task_100ms_Bat_EXV_ProjectCode1_Bat_EXV_ProjectCode1(void);

Std_ReturnType Rte_IStatus_Task_100ms_Bat_EXV_ProjectCode2_Bat_EXV_ProjectCode2(void);

Std_ReturnType Rte_IStatus_Task_100ms_Bat_EXV_SWVersion_Main_Bat_EXV_SWVersion_Main(void);

Std_ReturnType Rte_IStatus_Task_100ms_Bat_EXV_SWVersion_Patch_Bat_EXV_SWVersion_Patch(void);

Std_ReturnType Rte_IStatus_Task_100ms_Bat_EXV_SWVersion_Sub_Bat_EXV_SWVersion_Sub(void);

Std_ReturnType Rte_IStatus_Task_100ms_Bat_EXV_SupplierNumber_Bat_EXV_SupplierNumber(void);

Std_ReturnType Rte_IStatus_Task_100ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs(void);

Std_ReturnType Rte_IStatus_Task_100ms_C3WV_ErrResp_C3WV_ErrResp(void);

Std_ReturnType Rte_IStatus_Task_100ms_C3WV_FltSts_C3WV_FltSts(void);

Std_ReturnType Rte_IStatus_Task_100ms_C3WV_Mode_C3WV_Mode(void);

Std_ReturnType Rte_IStatus_Task_100ms_C3WV_PosRec_C3WV_PosRec(void);

Std_ReturnType Rte_IStatus_Task_100ms_C3WV_RunSts_C3WV_RunSts(void);

Std_ReturnType Rte_IStatus_Task_100ms_C3WV_SpdLvl_C3WV_SpdLvl(void);

Std_ReturnType Rte_IStatus_Task_100ms_C3WV_TempSts_C3WV_TempSts(void);

Std_ReturnType Rte_IStatus_Task_100ms_C3WV_VoltSts_C3WV_VoltSts(void);

Std_ReturnType Rte_IStatus_Task_100ms_C5WVFltSts_C5WVFltSts(void);

Std_ReturnType Rte_IStatus_Task_100ms_C5WVMode_C5WVMode(void);

Std_ReturnType Rte_IStatus_Task_100ms_C5WVPosRec_C5WVPosRec(void);

Std_ReturnType Rte_IStatus_Task_100ms_C5WVRunSts_C5WVRunSts(void);

Std_ReturnType Rte_IStatus_Task_100ms_C5WVSpdLvl_C5WVSpdLvl(void);

Std_ReturnType Rte_IStatus_Task_100ms_C5WVTempSts_C5WVTempSts(void);

Std_ReturnType Rte_IStatus_Task_100ms_C5WVVoltSts_C5WVVoltSts(void);

Std_ReturnType Rte_IStatus_Task_100ms_EXV_CurrentInitState_EXV_CurrentInitState(void);

Std_ReturnType Rte_IStatus_Task_100ms_EXV_CurrentPosition_EXV_CurrentPosition(void);

Std_ReturnType Rte_IStatus_Task_100ms_EXV_FaultState_EXV_FaultState(void);

Std_ReturnType Rte_IStatus_Task_100ms_EXV_ResponseError_EXV_ResponseError(void);

Std_ReturnType Rte_IStatus_Task_100ms_EXV_RunState_EXV_RunState(void);

Std_ReturnType Rte_IStatus_Task_100ms_EXV_TemperatureWarn_EXV_TemperatureWarn(void);

Std_ReturnType Rte_IStatus_Task_100ms_EXV_VoltageState_EXV_VoltageState(void);

Std_ReturnType Rte_IStatus_Task_100ms_ErrRespC5WV_ErrRespC5WV(void);

Std_ReturnType Rte_IStatus_Task_100ms_HP_EXV_CurrentPosition_B_HP_EXV_CurrentPosition_B(void);

Std_ReturnType Rte_IStatus_Task_100ms_HP_EXV_FaultState_B_HP_EXV_FaultState_B(void);

Std_ReturnType Rte_IStatus_Task_100ms_HP_EXV_HWVersion_HP_EXV_HWVersion(void);

Std_ReturnType Rte_IStatus_Task_100ms_HP_EXV_PartNumber_HP_EXV_PartNumber(void);

Std_ReturnType Rte_IStatus_Task_100ms_HP_EXV_ProjectCode1_HP_EXV_ProjectCode1(void);

Std_ReturnType Rte_IStatus_Task_100ms_HP_EXV_ProjectCode2_HP_EXV_ProjectCode2(void);

Std_ReturnType Rte_IStatus_Task_100ms_HP_EXV_ResponseError_B_HP_EXV_ResponseError_B(void);

Std_ReturnType Rte_IStatus_Task_100ms_HP_EXV_RunState_B_HP_EXV_RunState_B(void);

Std_ReturnType Rte_IStatus_Task_100ms_HP_EXV_SWVersion_Main_HP_EXV_SWVersion_Main(void);

Std_ReturnType Rte_IStatus_Task_100ms_HP_EXV_SWVersion_Patch_HP_EXV_SWVersion_Patch(void);

Std_ReturnType Rte_IStatus_Task_100ms_HP_EXV_SWVersion_Sub_HP_EXV_SWVersion_Sub(void);

Std_ReturnType Rte_IStatus_Task_100ms_HP_EXV_SupplierLabel_HP_EXV_SupplierLabel(void);

Std_ReturnType Rte_IStatus_Task_100ms_HP_EXV_SupplierNumber_HP_EXV_SupplierNumber(void);

Std_ReturnType Rte_IStatus_Task_100ms_HP_EXV_VoltageState_B_HP_EXV_VoltageState_B(void);

Std_ReturnType Rte_IStatus_Task_100ms_HP_EXV_Warning_OverTemp_HP_EXV_Warning_OverTemp(void);

Std_ReturnType Rte_IStatus_Task_100ms_HP_EXV_initialize_status_HP_EXV_initialize_status(void);

Std_ReturnType Rte_IStatus_Task_100ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT(void);

Std_ReturnType Rte_IStatus_Task_100ms_IPM_BMS_2_BatState_EPT_IPM_BMS_2_BatState_EPT(void);

Std_ReturnType Rte_IStatus_Task_100ms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT(void);

Std_ReturnType Rte_IStatus_Task_100ms_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT(void);

Std_ReturnType Rte_IStatus_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD(void);

Std_ReturnType Rte_IStatus_Task_100ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD(void);

Std_ReturnType Rte_IStatus_Task_100ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA(void);

Std_ReturnType Rte_IStatus_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC(void);

Std_ReturnType Rte_IStatus_Task_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD(void);

Std_ReturnType Rte_IStatus_Task_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD(void);

Std_ReturnType Rte_IStatus_Task_100ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT(void);

Std_ReturnType Rte_IStatus_Task_100ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT(void);

Std_ReturnType Rte_IStatus_Task_100ms_MotPMP_PumpDryRunningSta_MotPMP_PumpDryRunningSta(void);

Std_ReturnType Rte_IStatus_Task_100ms_MotPMP_PumpInputVolt_MotPMP_PumpInputVolt(void);

Std_ReturnType Rte_IStatus_Task_100ms_MotPMP_PumpMotorSta_MotPMP_PumpMotorSta(void);

Std_ReturnType Rte_IStatus_Task_100ms_MotPMP_PumpPowerSta_MotPMP_PumpPowerSta(void);

Std_ReturnType Rte_IStatus_Task_100ms_MotPMP_PumpTempSta_MotPMP_PumpTempSta(void);

Std_ReturnType Rte_IStatus_Task_100ms_MotPMP_RESP_ERROR_MotPMP_RESP_ERROR(void);

Std_ReturnType Rte_IStatus_Task_100ms_MotPMP_RealRPM_MotPMP_RealRPM(void);

Std_ReturnType Rte_IStatus_Task_100ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs(void);

/** runnables */

void Task_100ms(void);

void ME11_Init(void);

#endif

