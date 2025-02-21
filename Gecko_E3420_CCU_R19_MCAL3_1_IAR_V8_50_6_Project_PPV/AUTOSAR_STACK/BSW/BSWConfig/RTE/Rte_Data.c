/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_Data.c>
 *  @brief      <>
 *  
 *  <MCU:E3420>
 *  
 *  @author     <>
 *  @date       <2025-02-19 14:25:38>
 */
/*============================================================================*/

/* Rte_Data.c */
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
#include "Rte_Data.h"
#define RTE_CORE
#include "Rte_AppSwcBcm.h"
#include "Rte_AppSwcIpm.h"
#include "Rte_AppSwcOpm.h"
#include "Rte_ME11.h"
#include "Rte_AppSwcVcu.h"

/*******************************************************************************
 **                        Global Variable Definitions                        **
******************************************************************************/

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
ACCM_Version_BOD Rte_Buf_Runbl_IpmCanRx_100ms_ACCM_Version_BOD_ACCM_Version_BOD = {0, 0, 0, 0, 0, 0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
AlmSysCtl Irv_AppSwcBcm_AlmSysCtl_Bus = {0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
AlmSysCtl Irv_AppSwcBcm_AppSwcBcm_Init_AlmSysCtl_Bus = {0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
AlmSysCtl Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_AlmSysCtl_Bus = {0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
AlmSysCtl Irv_AppSwcBcm_Runbl_AppSwcBcm_10ms_AlmSysCtl_Bus = {0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
AlmSysCtl Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus = {0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
AlmSysCtl Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_AlmSysCtl_Bus = {0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
BMS_10_DC_ChargeStates_EPT Rte_Buf_Runbl_IpmCanRx_20ms_BMS_10_DC_ChargeStates_EPT_BMS_10_DC_ChargeStates_EPT = {0, 0, 0, 0, 0, 0, 0, 0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
BMS_1_MainState_EPT Rte_Buf_Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
BMS_2_BatState_EPT Rte_Buf_Runbl_IpmCanRx_20ms_BMS_2_BatState_EPT_BMS_2_BatState_EPT = {0, 0, 0, 0, 0, 0, 0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
BMS_3_DC_ChargeState_EPT Rte_Buf_Runbl_IpmCanRx_20ms_BMS_3_DC_ChargeState_EPT_BMS_3_DC_ChargeState_EPT = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 65};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
BMS_4_AC_ChargeState_EPT Rte_Buf_Runbl_IpmCanRx_20ms_BMS_4_AC_ChargeState_EPT_BMS_4_AC_ChargeState_EPT = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
BMS_5_BatTemp_EPT Rte_Buf_Runbl_IpmCanRx_100ms_BMS_5_BatTemp_EPT_BMS_5_BatTemp_EPT = {0, 0, 0, 0, 0, 0, 0, 0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
BMS_6_DischrgRecup_EPT Rte_Buf_Runbl_IpmCanRx_20ms_BMS_6_DischrgRecup_EPT_BMS_6_DischrgRecup_EPT = {0, 0, 0, 0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
BMS_7_CellVolt_EPT Rte_Buf_Runbl_IpmCanRx_20ms_BMS_7_CellVolt_EPT_BMS_7_CellVolt_EPT = {0, 0, 0, 0, 0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
BMS_9_BattInfo_EPT Rte_Buf_Runbl_IpmCanRx_100ms_BMS_9_BattInfo_EPT_BMS_9_BattInfo_EPT = {0, 0, 0, 0, 0, 0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
BSW2VCU_outputs Irv_AppSwcVcu_BSW2VCU_outputs = {0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
BSW2VCU_outputs Irv_AppSwcVcu_Runbl_VCU_100ms_BSW2VCU_outputs = {0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
BSW2VCU_outputs Irv_AppSwcVcu_Runbl_VCU_10ms_BSW2VCU_outputs = {0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
BSW2VCU_outputs Irv_AppSwcVcu_Runbl_VCU_20ms_BSW2VCU_outputs = {0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
BSW2VCU_outputs Irv_AppSwcVcu_Runbl_VcuRx_10ms_BSW2VCU_outputs = {0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
BSW2VCU_outputs Irv_AppSwcVcu_Runbl_VcuTx_10ms_BSW2VCU_outputs = {0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
BatSaveCtl Irv_AppSwcBcm_BatSaveCtl_Bus = {0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
BatSaveCtl Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_BatSaveCtl_Bus = {0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
BatSaveCtl Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_BatSaveCtl_Bus = {0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_BOOLEAN
#include "Rte_MemMap.h"
Boolean Rte_Buf_Task_100ms_AcPMP_PumpDryRunningSta_AcPMP_PumpDryRunningSta = {0};
#define RTE_STOP_SEC_VAR_INIT_BOOLEAN
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_BOOLEAN
#include "Rte_MemMap.h"
Boolean Rte_Buf_Task_100ms_AcPMP_RESP_ERROR_AcPMP_RESP_ERROR = {0};
#define RTE_STOP_SEC_VAR_INIT_BOOLEAN
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_BOOLEAN
#include "Rte_MemMap.h"
Boolean Rte_Buf_Task_100ms_BAT_EXV_ResponseError_B_BAT_EXV_ResponseError_B = {0};
#define RTE_STOP_SEC_VAR_INIT_BOOLEAN
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_BOOLEAN
#include "Rte_MemMap.h"
Boolean Rte_Buf_Task_100ms_BAT_EXV_RunState_B_BAT_EXV_RunState_B = {0};
#define RTE_STOP_SEC_VAR_INIT_BOOLEAN
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_BOOLEAN
#include "Rte_MemMap.h"
Boolean Rte_Buf_Task_100ms_BAT_EXV_SupplierLabel_BAT_EXV_SupplierLabel = {0};
#define RTE_STOP_SEC_VAR_INIT_BOOLEAN
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_BOOLEAN
#include "Rte_MemMap.h"
Boolean Rte_Buf_Task_100ms_BAT_EXV_Warning_OverTemp_BAT_EXV_Warning_OverTemp = {0};
#define RTE_STOP_SEC_VAR_INIT_BOOLEAN
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_BOOLEAN
#include "Rte_MemMap.h"
Boolean Rte_Buf_Task_100ms_BatPMP_PumpDryRunningSta_BatPMP_PumpDryRunningSta = {0};
#define RTE_STOP_SEC_VAR_INIT_BOOLEAN
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_BOOLEAN
#include "Rte_MemMap.h"
Boolean Rte_Buf_Task_100ms_BatPMP_RESP_ERROR_BatPMP_RESP_ERROR = {0};
#define RTE_STOP_SEC_VAR_INIT_BOOLEAN
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_BOOLEAN
#include "Rte_MemMap.h"
Boolean Rte_Buf_Task_100ms_C3WV_ErrResp_C3WV_ErrResp = {0};
#define RTE_STOP_SEC_VAR_INIT_BOOLEAN
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_BOOLEAN
#include "Rte_MemMap.h"
Boolean Rte_Buf_Task_100ms_C3WV_RunSts_C3WV_RunSts = {0};
#define RTE_STOP_SEC_VAR_INIT_BOOLEAN
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_BOOLEAN
#include "Rte_MemMap.h"
Boolean Rte_Buf_Task_100ms_C5WVRunSts_C5WVRunSts = {0};
#define RTE_STOP_SEC_VAR_INIT_BOOLEAN
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_BOOLEAN
#include "Rte_MemMap.h"
Boolean Rte_Buf_Task_100ms_EXV_ResponseError_EXV_ResponseError = {0};
#define RTE_STOP_SEC_VAR_INIT_BOOLEAN
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_BOOLEAN
#include "Rte_MemMap.h"
Boolean Rte_Buf_Task_100ms_EXV_RunState_EXV_RunState = {0};
#define RTE_STOP_SEC_VAR_INIT_BOOLEAN
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_BOOLEAN
#include "Rte_MemMap.h"
Boolean Rte_Buf_Task_100ms_ErrRespC5WV_ErrRespC5WV = {0};
#define RTE_STOP_SEC_VAR_INIT_BOOLEAN
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_BOOLEAN
#include "Rte_MemMap.h"
Boolean Rte_Buf_Task_100ms_HP_EXV_ResponseError_B_HP_EXV_ResponseError_B = {0};
#define RTE_STOP_SEC_VAR_INIT_BOOLEAN
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_BOOLEAN
#include "Rte_MemMap.h"
Boolean Rte_Buf_Task_100ms_HP_EXV_RunState_B_HP_EXV_RunState_B = {0};
#define RTE_STOP_SEC_VAR_INIT_BOOLEAN
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_BOOLEAN
#include "Rte_MemMap.h"
Boolean Rte_Buf_Task_100ms_HP_EXV_SupplierLabel_HP_EXV_SupplierLabel = {0};
#define RTE_STOP_SEC_VAR_INIT_BOOLEAN
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_BOOLEAN
#include "Rte_MemMap.h"
Boolean Rte_Buf_Task_100ms_HP_EXV_Warning_OverTemp_HP_EXV_Warning_OverTemp = {0};
#define RTE_STOP_SEC_VAR_INIT_BOOLEAN
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_BOOLEAN
#include "Rte_MemMap.h"
Boolean Rte_Buf_Task_100ms_MotPMP_PumpDryRunningSta_MotPMP_PumpDryRunningSta = {0};
#define RTE_STOP_SEC_VAR_INIT_BOOLEAN
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_BOOLEAN
#include "Rte_MemMap.h"
Boolean Rte_Buf_Task_100ms_MotPMP_RESP_ERROR_MotPMP_RESP_ERROR = {0};
#define RTE_STOP_SEC_VAR_INIT_BOOLEAN
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
CCP_PanelStatus_BOD Rte_Buf_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
COMP_AC_BOD Rte_Buf_Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
CRRR_A_CHA Rte_Buf_Runbl_IpmCanRx_20ms_CRRR_A_CHA_CRRR_A_CHA = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DAG_Comm_outputs Rte_Buf_Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DAG_Comm_outputs Irv_AppSwcVcu_DAG_Comm_outputsIRV = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DAG_Comm_outputs Irv_AppSwcVcu_AppSwcVcu_Init_DAG_Comm_outputsIRV = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DAG_Comm_outputs Irv_AppSwcVcu_Runbl_VCU_20ms_DAG_Comm_outputsIRV = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DAG_Comm_outputs Irv_AppSwcVcu_Runbl_VcuTx_10ms_DAG_Comm_outputsIRV = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DAG_FltActn_outputs Irv_AppSwcVcu_DAG_FltActn_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DAG_FltActn_outputs Irv_AppSwcVcu_AppSwcVcu_Init_DAG_FltActn_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DAG_FltActn_outputs Irv_AppSwcVcu_Runbl_VCU_100ms_DAG_FltActn_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DAG_FltActn_outputs Irv_AppSwcVcu_Runbl_VCU_10ms_DAG_FltActn_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DAG_FltActn_outputs Irv_AppSwcVcu_Runbl_VCU_20ms_DAG_FltActn_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DAG_FltActn_outputs Irv_AppSwcVcu_Runbl_VcuTx_10ms_DAG_FltActn_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DAG_Other_outputs Irv_AppSwcVcu_DAG_Other_outputs = {0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DAG_Other_outputs Irv_AppSwcVcu_AppSwcVcu_Init_DAG_Other_outputs = {0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DAG_Other_outputs Irv_AppSwcVcu_Runbl_VCU_100ms_DAG_Other_outputs = {0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DAG_Other_outputs Irv_AppSwcVcu_Runbl_VCU_20ms_DAG_Other_outputs = {0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DAG_Sensor10ms_outputs Irv_AppSwcVcu_DAG_Sensor10ms_outputs = {0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DAG_Sensor10ms_outputs Irv_AppSwcVcu_AppSwcVcu_Init_DAG_Sensor10ms_outputs = {0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DAG_Sensor10ms_outputs Irv_AppSwcVcu_Runbl_VCU_10ms_DAG_Sensor10ms_outputs = {0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DAG_Sensor10ms_outputs Irv_AppSwcVcu_Runbl_VCU_20ms_DAG_Sensor10ms_outputs = {0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DSA_outputs Irv_AppSwcVcu_DSA_outputs = {0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DSA_outputs Irv_AppSwcVcu_AppSwcVcu_Init_DSA_outputs = {0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DSA_outputs Irv_AppSwcVcu_Runbl_VCU_100ms_DSA_outputs = {0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DSA_outputs Irv_AppSwcVcu_Runbl_VCU_10ms_DSA_outputs = {0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_Bcm2OpmBAC_outputs Rte_Buf_Runbl_OpmRx_10ms_Bcm2OpmBAC_outputs_Bcm2OpmBAC_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_Bcm2OpmBAC_outputs Irv_AppSwcOpm_Bcm2OpmBAC_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_Bcm2OpmBAC_outputs Irv_AppSwcOpm_Runbl_OpmCanTx_100ms_Bcm2OpmBAC_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_Bcm2OpmBAC_outputs Irv_AppSwcOpm_Runbl_OpmCanTx_20ms_Bcm2OpmBAC_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_Bcm2OpmBAC_outputs Irv_AppSwcOpm_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_Bcm2OpmBAC_outputs Irv_AppSwcOpm_Runbl_OpmRx_10ms_Bcm2OpmBAC_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_Bcm2OpmEPT_outputs Rte_Buf_Runbl_OpmCanTx_100ms_Bcm2OpmEPT_outputs_Bcm2OpmEPT_outputs = {0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_Bcm2OpmOBD_outputs Rte_Buf_Runbl_OpmCanTx_100ms_Bcm2OpmOBD_outputs_Bcm2OpmOBD_outputs = {0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_Bcm2VcuTms_outputs Rte_Buf_Task_100ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_Bcm2VcuTms_outputs Rte_Buf_Runbl_VcuRx_10ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_Bcm2VcuTms_outputs Irv_AppSwcVcu_Bcm2VcuTms_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_Bcm2VcuTms_outputs Irv_AppSwcVcu_Runbl_VCU_100ms_Bcm2VcuTms_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_Bcm2VcuTms_outputs Irv_AppSwcVcu_Runbl_VCU_20ms_Bcm2VcuTms_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_Bcm2VcuTms_outputs Irv_AppSwcVcu_Runbl_VcuRx_10ms_Bcm2VcuTms_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_Bcm2VcuTms_outputs Irv_AppSwcVcu_Runbl_VcuTx_10ms_Bcm2VcuTms_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_CANCommCRCFlt Rte_Buf_Runbl_VCU_20ms_CANCommCRCFlt_outputs_CANCommCRCFlt_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_CANCommCRCFlt Irv_AppSwcIpm_CANCommCRCFlt_outputsIRV = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_CANCommCRCFlt Irv_AppSwcIpm_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_CANCommCRCFlt Irv_AppSwcIpm_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_CANCommCRCFlt Irv_AppSwcIpm_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_CANCommCRCFlt Irv_AppSwcIpm_Runbl_IpmCanRx_50ms_CANCommCRCFlt_outputsIRV = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_CANCommCRCFlt Irv_AppSwcIpm_Runbl_IpmMsgActv_10ms_CANCommCRCFlt_outputsIRV = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_CANCommErr Rte_Buf_Runbl_VcuRx_10ms_CANCommErr_outputs_CANCommErr_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_CANCommErr Irv_AppSwcVcu_CANCommErr_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_CANCommErr Irv_AppSwcVcu_Runbl_VCU_100ms_CANCommErr_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_CANCommErr Irv_AppSwcVcu_Runbl_VCU_20ms_CANCommErr_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_CANCommErr Irv_AppSwcVcu_Runbl_VcuRx_10ms_CANCommErr_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_HardWire_Input_VCU Irv_AppSwcVcu_HardWire_Input_VCU = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_HardWire_Input_VCU Irv_AppSwcVcu_Runbl_VCU_100ms_HardWire_Input_VCU = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_HardWire_Input_VCU Irv_AppSwcVcu_Runbl_VCU_10ms_HardWire_Input_VCU = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_HardWire_Input_VCU Irv_AppSwcVcu_Runbl_VCU_20ms_HardWire_Input_VCU = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_HardWire_Input_VCU Irv_AppSwcVcu_Runbl_VcuRx_10ms_HardWire_Input_VCU = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_BMS_10_DC_ChargeStates_EPT Rte_Buf_Task_100ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT = {0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_BMS_10_DC_ChargeStates_EPT Rte_Buf_Runbl_VcuRx_10ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT = {0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_BMS_10_DC_ChargeStates_EPT Irv_AppSwcVcu_IPM_BMS_10_DC_ChargeStates_EPT = {0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_BMS_10_DC_ChargeStates_EPT Irv_AppSwcVcu_Runbl_VCU_100ms_IPM_BMS_10_DC_ChargeStates_EPT = {0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_BMS_10_DC_ChargeStates_EPT Irv_AppSwcVcu_Runbl_VCU_10ms_IPM_BMS_10_DC_ChargeStates_EPT = {0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_BMS_10_DC_ChargeStates_EPT Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_BMS_10_DC_ChargeStates_EPT = {0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_BMS_10_DC_ChargeStates_EPT Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_BMS_10_DC_ChargeStates_EPT = {0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_BMS_1_MainState_EPT Rte_Buf_Runbl_AppSwcBcm_50ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_BMS_1_MainState_EPT Rte_Buf_Runbl_VcuRx_10ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_BMS_1_MainState_EPT Irv_AppSwcVcu_IPM_BMS_1_MainState_EPT = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_BMS_1_MainState_EPT Irv_AppSwcVcu_Runbl_VCU_100ms_IPM_BMS_1_MainState_EPT = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_BMS_1_MainState_EPT Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_BMS_1_MainState_EPT = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_BMS_1_MainState_EPT Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_BMS_1_MainState_EPT = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_BMS_2_BatState_EPT Rte_Buf_Task_100ms_IPM_BMS_2_BatState_EPT_IPM_BMS_2_BatState_EPT = {0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_BMS_2_BatState_EPT Rte_Buf_Runbl_VcuRx_10ms_IPM_BMS_2_BatState_EPT_IPM_BMS_2_BatState_EPT = {0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_BMS_2_BatState_EPT Irv_AppSwcVcu_IPM_BMS_2_BatState_EPT = {0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_BMS_2_BatState_EPT Irv_AppSwcVcu_Runbl_VCU_100ms_IPM_BMS_2_BatState_EPT = {0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_BMS_2_BatState_EPT Irv_AppSwcVcu_Runbl_VCU_10ms_IPM_BMS_2_BatState_EPT = {0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_BMS_2_BatState_EPT Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_BMS_2_BatState_EPT = {0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_BMS_2_BatState_EPT Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_BMS_2_BatState_EPT = {0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_BMS_3_DC_ChargeState_EPT Rte_Buf_Runbl_VCU_20ms_IPM_BMS_3_DC_ChargeState_EPT_IPM_BMS_3_DC_ChargeState_EPT = {0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_BMS_4_AC_ChargeState_EPT Rte_Buf_Task_100ms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT = {0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_BMS_4_AC_ChargeState_EPT Rte_Buf_Runbl_VCU_20ms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT = {0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_BMS_5_BatTemp_EPT Rte_Buf_Task_100ms_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT = {0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_BMS_5_BatTemp_EPT Rte_Buf_Runbl_VcuRx_10ms_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT = {0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_BMS_5_BatTemp_EPT Irv_AppSwcVcu_IPM_BMS_5_BatTemp_EPT = {0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_BMS_5_BatTemp_EPT Irv_AppSwcVcu_Runbl_VCU_100ms_IPM_BMS_5_BatTemp_EPT = {0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_BMS_5_BatTemp_EPT Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_BMS_5_BatTemp_EPT = {0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_BMS_5_BatTemp_EPT Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_BMS_5_BatTemp_EPT = {0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_BMS_6_DischrgRecup_EPT Rte_Buf_Runbl_VcuRx_10ms_IPM_BMS_6_DischrgRecup_EPT_IPM_BMS_6_DischrgRecup_EPT = {0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_BMS_6_DischrgRecup_EPT Irv_AppSwcVcu_IPM_BMS_6_DischrgRecup_EPT = {0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_BMS_6_DischrgRecup_EPT Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_BMS_6_DischrgRecup_EPT = {0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_BMS_6_DischrgRecup_EPT Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_BMS_6_DischrgRecup_EPT = {0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_BMS_7_CellVolt_EPT Rte_Buf_Runbl_VCU_20ms_IPM_BMS_7_CellVolt_EPT_IPM_BMS_7_CellVolt_EPT = {0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_BMS_9_BattInfo_EPT Rte_Buf_Runbl_VcuRx_10ms_IPM_BMS_9_BattInfo_EPT_IPM_BMS_9_BattInfo_EPT = {0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_BMS_9_BattInfo_EPT Irv_AppSwcVcu_IPM_BMS_9_BattInfo_EPT = {0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_BMS_9_BattInfo_EPT Irv_AppSwcVcu_Runbl_VCU_100ms_IPM_BMS_9_BattInfo_EPT = {0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_BMS_9_BattInfo_EPT Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_BMS_9_BattInfo_EPT = {0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_BMS_9_BattInfo_EPT Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_BMS_9_BattInfo_EPT = {0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_CCP_PanelStatus_BOD Rte_Buf_Runbl_AppSwcBcm_20ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_CCP_PanelStatus_BOD Rte_Buf_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_CCP_PanelStatus_BOD Rte_Buf_Runbl_VCU_10ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_CCP_PanelStatus_BOD Irv_AppSwcBcm_IPM_CCP_PanelStatus_BOD = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_CCP_PanelStatus_BOD Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_IPM_CCP_PanelStatus_BOD = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_CCP_PanelStatus_BOD Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_IPM_CCP_PanelStatus_BOD = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_CCP_PanelStatus_BOD Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_IPM_CCP_PanelStatus_BOD = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_COMP_AC_BOD Rte_Buf_Task_100ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_COMP_AC_BOD Rte_Buf_Runbl_VCU_20ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_CRRR_A_CHA Rte_Buf_Runbl_AppSwcBcm_50ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA = {0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_EHB_A_CHA Rte_Buf_Runbl_AppSwcBcm_50ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA = {0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_EHB_A_CHA Rte_Buf_Runbl_VCU_10ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA = {0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_EHB_B_CHA Rte_Buf_Runbl_AppSwcBcm_50ms_IPM_EHB_B_CHA_IPM_EHB_B_CHA = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_EHB_B_CHA Rte_Buf_Runbl_VcuRx_10ms_IPM_EHB_B_CHA_IPM_EHB_B_CHA = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_EHB_B_CHA Irv_AppSwcVcu_IPM_EHB_B_CHA = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_EHB_B_CHA Irv_AppSwcVcu_Runbl_VCU_10ms_IPM_EHB_B_CHA = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_EHB_B_CHA Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_EHB_B_CHA = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_EHB_B_CHA Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_EHB_B_CHA = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_ESCL_ESCLStatus_BOD Rte_Buf_Runbl_AppSwcBcm_50ms_IPM_ESCL_ESCLStatus_BOD_IPM_ESCL_ESCLStatus_BOD = {0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_ESC_7_FuncStatus_CHA Rte_Buf_Runbl_AppSwcBcm_20ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_ESC_7_FuncStatus_CHA Rte_Buf_Task_100ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_ESC_7_FuncStatus_CHA Rte_Buf_Runbl_VcuRx_10ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_ESC_7_FuncStatus_CHA Irv_AppSwcBcm_IPM_ESC_7_FuncStatus_CHA = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_ESC_7_FuncStatus_CHA Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_IPM_ESC_7_FuncStatus_CHA = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_ESC_7_FuncStatus_CHA Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_IPM_ESC_7_FuncStatus_CHA = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_ESC_7_FuncStatus_CHA Irv_AppSwcVcu_IPM_ESC_7_FuncStatus_CHA = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_ESC_7_FuncStatus_CHA Irv_AppSwcVcu_Runbl_VCU_100ms_IPM_ESC_7_FuncStatus_CHA = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_ESC_7_FuncStatus_CHA Irv_AppSwcVcu_Runbl_VCU_10ms_IPM_ESC_7_FuncStatus_CHA = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_ESC_7_FuncStatus_CHA Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_ESC_7_FuncStatus_CHA = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_ESC_7_FuncStatus_CHA Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_ESC_7_FuncStatus_CHA = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_ESC_A_CHA Rte_Buf_Runbl_VcuRx_10ms_IPM_ESC_A_CHA_IPM_ESC_A_CHA = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_ESC_A_CHA Irv_AppSwcVcu_IPM_ESC_A_CHA = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_ESC_A_CHA Irv_AppSwcVcu_Runbl_VCU_100ms_IPM_ESC_A_CHA = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_ESC_A_CHA Irv_AppSwcVcu_Runbl_VCU_10ms_IPM_ESC_A_CHA = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_ESC_A_CHA Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_ESC_A_CHA = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_FCM_A_CHA Rte_Buf_Runbl_AppSwcBcm_50ms_IPM_FCM_A_CHA_IPM_FCM_A_CHA = {0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_FCM_B_CHA Rte_Buf_Runbl_OpmCanTx_10ms_IPM_FCM_B_CHA_IPM_FCM_B_CHA = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_FCM_B_CHA Rte_Buf_Runbl_VcuRx_10ms_IPM_FCM_B_CHA_IPM_FCM_B_CHA = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_FCM_B_CHA Irv_AppSwcVcu_IPM_FCM_B_CHA = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_FCM_B_CHA Irv_AppSwcVcu_Runbl_VCU_10ms_IPM_FCM_B_CHA = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_FCM_B_CHA Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_FCM_B_CHA = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_FCM_B_CHA Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_FCM_B_CHA = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_HU_B_BAC Rte_Buf_Runbl_AppSwcBcm_20ms_IPM_HU_B_BAC_IPM_HU_B_BAC = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_HU_B_BAC Rte_Buf_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_HU_B_BAC Rte_Buf_Runbl_VcuRx_10ms_IPM_HU_B_BAC_IPM_HU_B_BAC = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_HU_B_BAC Irv_AppSwcBcm_IPM_HU_B_BAC = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_HU_B_BAC Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_IPM_HU_B_BAC = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_HU_B_BAC Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_IPM_HU_B_BAC = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_HU_B_BAC Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_HU_B_BAC Irv_AppSwcVcu_IPM_HU_B_BAC = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_HU_B_BAC Irv_AppSwcVcu_Runbl_VCU_100ms_IPM_HU_B_BAC = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_HU_B_BAC Irv_AppSwcVcu_Runbl_VCU_10ms_IPM_HU_B_BAC = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_HU_B_BAC Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_HU_B_BAC = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_HU_B_BAC Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_HU_B_BAC = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_HVCH_Status1_BOD Rte_Buf_Task_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD = {0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_HVCH_Status2_BOD Rte_Buf_Task_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD = {0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_ICU_2_Odo_BAC Rte_Buf_Runbl_VCU_20ms_IPM_ICU_2_Odo_BAC_IPM_ICU_2_Odo_BAC = {0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_INV_1_Value_EPT Rte_Buf_Runbl_OpmCanTx_10ms_IPM_INV_1_Value_EPT_IPM_INV_1_Value_EPT = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_INV_1_Value_EPT Rte_Buf_Runbl_VcuRx_10ms_IPM_INV_1_Value_EPT_IPM_INV_1_Value_EPT = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_INV_1_Value_EPT Irv_AppSwcVcu_IPM_INV_1_Value_EPT = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_INV_1_Value_EPT Irv_AppSwcVcu_Runbl_VCU_10ms_IPM_INV_1_Value_EPT = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_INV_1_Value_EPT Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_INV_1_Value_EPT = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_INV_1_Value_EPT Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_INV_1_Value_EPT = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_INV_2_Value_EPT Rte_Buf_Task_100ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT = {0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_INV_2_Value_EPT Rte_Buf_Runbl_VcuRx_10ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT = {0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_INV_2_Value_EPT Irv_AppSwcVcu_IPM_INV_2_Value_EPT = {0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_INV_2_Value_EPT Irv_AppSwcVcu_Runbl_VCU_10ms_IPM_INV_2_Value_EPT = {0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_INV_2_Value_EPT Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_INV_2_Value_EPT = {0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_INV_2_Value_EPT Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_INV_2_Value_EPT = {0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_INV_2_Value_EPT Irv_AppSwcVcu_Runbl_VcuTx_10ms_IPM_INV_2_Value_EPT = {0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_INV_3_Value_EPT Rte_Buf_Runbl_VcuRx_10ms_IPM_INV_3_Value_EPT_IPM_INV_3_Value_EPT = {0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_INV_3_Value_EPT Irv_AppSwcVcu_IPM_INV_3_Value_EPT = {0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_INV_3_Value_EPT Irv_AppSwcVcu_Runbl_VCU_100ms_IPM_INV_3_Value_EPT = {0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_INV_3_Value_EPT Irv_AppSwcVcu_Runbl_VCU_10ms_IPM_INV_3_Value_EPT = {0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_INV_3_Value_EPT Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_INV_3_Value_EPT = {0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_INV_4_Value_EPT Rte_Buf_Runbl_VcuRx_10ms_IPM_INV_4_Value_EPT_IPM_INV_4_Value_EPT = {0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_INV_4_Value_EPT Irv_AppSwcVcu_IPM_INV_4_Value_EPT = {0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_INV_4_Value_EPT Irv_AppSwcVcu_Runbl_VCU_10ms_IPM_INV_4_Value_EPT = {0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_INV_4_Value_EPT Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_INV_4_Value_EPT = {0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_INV_4_Value_EPT Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_INV_4_Value_EPT = {0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_INV_IMMO_Req_EPT Rte_Buf_Runbl_AppSwcBcm_50ms_IPM_INV_IMMO_Req_EPT_IPM_INV_IMMO_Req_EPT = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_IPU_DCC_1_State_EPT Rte_Buf_Runbl_VcuRx_10ms_IPM_IPU_DCC_1_State_EPT_IPM_IPU_DCC_1_State_EPT = {0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_IPU_DCC_1_State_EPT Irv_AppSwcVcu_IPM_IPU_DCC_1_State_EPT = {0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_IPU_DCC_1_State_EPT Irv_AppSwcVcu_Runbl_VCU_100ms_IPM_IPU_DCC_1_State_EPT = {0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_IPU_DCC_1_State_EPT Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_IPU_DCC_1_State_EPT = {0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_IPU_DCC_1_State_EPT Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_IPU_DCC_1_State_EPT = {0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_IPU_DCC_2_ChrgInValue_EPT Rte_Buf_Runbl_VCU_20ms_IPM_IPU_DCC_2_ChrgInValue_EPT_IPM_IPU_DCC_2_ChrgInValue_EPT = {0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_IPU_OBC_1_State_EPT Rte_Buf_Runbl_VcuRx_10ms_IPM_IPU_OBC_1_State_EPT_IPM_IPU_OBC_1_State_EPT = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_IPU_OBC_1_State_EPT Irv_AppSwcVcu_IPM_IPU_OBC_1_State_EPT = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_IPU_OBC_1_State_EPT Irv_AppSwcVcu_Runbl_VCU_100ms_IPM_IPU_OBC_1_State_EPT = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_IPU_OBC_1_State_EPT Irv_AppSwcVcu_Runbl_VCU_10ms_IPM_IPU_OBC_1_State_EPT = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_IPU_OBC_1_State_EPT Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_IPU_OBC_1_State_EPT = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_IPU_OBC_1_State_EPT Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_IPU_OBC_1_State_EPT = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_IPU_OBC_2_Inlet_EPT Rte_Buf_Task_100ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT = {0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_IPU_OBC_2_Inlet_EPT Rte_Buf_Runbl_VCU_20ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT = {0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_SCS_LeSwitchSts_BOD Rte_Buf_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_SCS_LeSwitchSts_BOD Irv_AppSwcBcm_IPM_SCS_LeSwitchSts_BOD = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_SCS_LeSwitchSts_BOD Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_SCS_LeSwitchSts_BOD Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_IPM_SCS_LeSwitchSts_BOD = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_SCS_RiSwitchSts_BOD Rte_Buf_Runbl_VcuRx_10ms_IPM_SCS_RiSwitchSts_BOD_IPM_SCS_RiSwitchSts_BOD = {0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_SCS_RiSwitchSts_BOD Irv_AppSwcVcu_IPM_SCS_RiSwitchSts_BOD = {0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_SCS_RiSwitchSts_BOD Irv_AppSwcVcu_Runbl_VCU_100ms_IPM_SCS_RiSwitchSts_BOD = {0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_SCS_RiSwitchSts_BOD Irv_AppSwcVcu_Runbl_VCU_10ms_IPM_SCS_RiSwitchSts_BOD = {0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_SCS_RiSwitchSts_BOD Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_SCS_RiSwitchSts_BOD = {0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_SCS_RiSwitchSts_BOD Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_SCS_RiSwitchSts_BOD = {0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_SRS_1_Status_CHA Rte_Buf_Runbl_AppSwcBcm_50ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA = {0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_SRS_1_Status_CHA Rte_Buf_Runbl_VcuRx_10ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA = {0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_SRS_1_Status_CHA Irv_AppSwcVcu_IPM_SRS_1_Status_CHA = {0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_SRS_1_Status_CHA Irv_AppSwcVcu_Runbl_VCU_10ms_IPM_SRS_1_Status_CHA = {0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_SRS_1_Status_CHA Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_SRS_1_Status_CHA = {0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_SRS_1_Status_CHA Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_SRS_1_Status_CHA = {0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_TBOX_BJS_Time_BAC Rte_Buf_Runbl_AppSwcBcm_100ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC = {0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_TBOX_BJS_Time_BAC Rte_Buf_Task_100ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC = {0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_IPM_TBOX_BJS_Time_BAC Rte_Buf_Runbl_VCU_20ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC = {0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_MsgActv Rte_Buf_Runbl_VcuRx_10ms_MsgActv_outputs_MsgActv_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_MsgActv Irv_AppSwcIpm_MsgActv_outputsIRV = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_MsgActv Irv_AppSwcIpm_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_MsgActv Irv_AppSwcIpm_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_MsgActv Irv_AppSwcIpm_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_MsgActv Irv_AppSwcIpm_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_MsgActv Irv_AppSwcIpm_Runbl_IpmMsgActv_10ms_MsgActv_outputsIRV = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_MsgActv Irv_AppSwcVcu_MsgActv_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_MsgActv Irv_AppSwcVcu_Runbl_VCU_10ms_MsgActv_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_MsgActv Irv_AppSwcVcu_Runbl_VCU_20ms_MsgActv_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_MsgActv Irv_AppSwcVcu_Runbl_VcuRx_10ms_MsgActv_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_SIBS_Output Irv_AppSwcVcu_SIBS_Output = {0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_SIBS_Output Irv_AppSwcVcu_AppSwcVcu_Init_SIBS_Output = {0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_SIBS_Output Irv_AppSwcVcu_Runbl_VCU_100ms_SIBS_Output = {0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_SIBS_Output Irv_AppSwcVcu_Runbl_VCU_20ms_SIBS_Output = {0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_SIBS_Output Irv_AppSwcVcu_Runbl_VcuTx_10ms_SIBS_Output = {0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_Vcu2BcmTms_outputs Rte_Buf_Runbl_AppSwcBcm_20ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_Vcu2BcmTms_outputs Rte_Buf_Task_100ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_Vcu2BcmTms_outputs Irv_AppSwcBcm_Vcu2BcmTms_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_Vcu2BcmTms_outputs Irv_AppSwcBcm_Runbl_AppSwcBcm_10ms_Vcu2BcmTms_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_Vcu2BcmTms_outputs Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_Vcu2BcmTms_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_Vcu2BcmTms_outputs Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_Vcu2OpmBAC_outputs Rte_Buf_Runbl_OpmRx_10ms_Vcu2OpmBAC_outputs_Vcu2OpmBAC_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_Vcu2OpmBAC_outputs Irv_AppSwcOpm_Vcu2OpmBAC_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_Vcu2OpmBAC_outputs Irv_AppSwcOpm_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_Vcu2OpmBAC_outputs Irv_AppSwcOpm_Runbl_OpmCanTx_50ms_Vcu2OpmBAC_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_Vcu2OpmBAC_outputs Irv_AppSwcOpm_Runbl_OpmRx_10ms_Vcu2OpmBAC_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_Vcu2OpmCHA_outputs Rte_Buf_Runbl_OpmRx_10ms_Vcu2OpmCHA_outputs_Vcu2OpmCHA_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_Vcu2OpmCHA_outputs Irv_AppSwcOpm_Vcu2OpmCHA_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_Vcu2OpmCHA_outputs Irv_AppSwcOpm_Runbl_OpmCanTx_10ms_Vcu2OpmCHA_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_Vcu2OpmCHA_outputs Irv_AppSwcOpm_Runbl_OpmCanTx_20ms_Vcu2OpmCHA_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_Vcu2OpmCHA_outputs Irv_AppSwcOpm_Runbl_OpmRx_10ms_Vcu2OpmCHA_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_Vcu2OpmEPT_outputs Rte_Buf_Runbl_OpmRx_10ms_Vcu2OpmEPT_outputs_Vcu2OpmEPT_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_Vcu2OpmEPT_outputs Irv_AppSwcOpm_Vcu2OpmEPT_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_Vcu2OpmEPT_outputs Irv_AppSwcOpm_Runbl_OpmCanTx_10ms_Vcu2OpmEPT_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_Vcu2OpmEPT_outputs Irv_AppSwcOpm_Runbl_OpmCanTx_20ms_Vcu2OpmEPT_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DT_Vcu2OpmEPT_outputs Irv_AppSwcOpm_Runbl_OpmRx_10ms_Vcu2OpmEPT_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DoorLckCtl Irv_AppSwcBcm_DoorLckCtl_Bus = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DoorLckCtl Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_DoorLckCtl_Bus = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DoorLckCtl Irv_AppSwcBcm_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DoorLckCtl Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DoorLckCtl Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_DoorLckCtl_Bus = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DynDID Irv_AppSwcBcm_DynDID_Bus = {0,{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0},0,{0,0,0,0,0},0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DynDID Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_DynDID_Bus = {0,{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0},0,{0,0,0,0,0},0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DynDID Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_DynDID_Bus = {0,{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0},0,{0,0,0,0,0},0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
DynDID Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_DynDID_Bus = {0,{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0},0,{0,0,0,0,0},0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
EEReadCtl Irv_AppSwcBcm_EEReadCtl_Bus = {0,0,0,0,0,0,0,0,0,0,0,0,{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
EEReadCtl Irv_AppSwcBcm_AppSwcBcm_Init_EEReadCtl_Bus = {0,0,0,0,0,0,0,0,0,0,0,0,{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
EEReadCtl Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_EEReadCtl_Bus = {0,0,0,0,0,0,0,0,0,0,0,0,{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
EEReadCtl Irv_AppSwcBcm_Runbl_AppSwcBcm_10ms_EEReadCtl_Bus = {0,0,0,0,0,0,0,0,0,0,0,0,{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
EEReadCtl Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_EEReadCtl_Bus = {0,0,0,0,0,0,0,0,0,0,0,0,{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
EEReadCtl Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus = {0,0,0,0,0,0,0,0,0,0,0,0,{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
EHB_A_CHA Rte_Buf_Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
EHB_B_CHA Rte_Buf_Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
EMS_outputs Irv_AppSwcVcu_EMS_outputs = {0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
EMS_outputs Irv_AppSwcVcu_AppSwcVcu_Init_EMS_outputs = {0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
EMS_outputs Irv_AppSwcVcu_Runbl_VCU_100ms_EMS_outputs = {0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
EMS_outputs Irv_AppSwcVcu_Runbl_VCU_10ms_EMS_outputs = {0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
EMS_outputs Irv_AppSwcVcu_Runbl_VCU_20ms_EMS_outputs = {0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
EMS_outputs Irv_AppSwcVcu_Runbl_VcuTx_10ms_EMS_outputs = {0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
EPS_2_StrWhlAng_CHA Rte_Buf_Runbl_IpmCanRx_10ms_EPS_2_StrWhlAng_CHA_EPS_2_StrWhlAng_CHA = {0, 0, 0, 10240, 7800, 0, 0, 0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
ESCLCtl Irv_AppSwcBcm_ESCLCtl_Bus = {0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
ESCLCtl Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_ESCLCtl_Bus = {0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
ESCLCtl Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_ESCLCtl_Bus = {0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
ESCL_ESCLStatus_BOD Rte_Buf_Runbl_IpmCanRx_50ms_ESCL_ESCLStatus_BOD_ESCL_ESCLStatus_BOD = {0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
ESC_7_FuncStatus_CHA Rte_Buf_Runbl_IpmCanRx_10ms_ESC_7_FuncStatus_CHA_ESC_7_FuncStatus_CHA = {0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
ESC_A_CHA Rte_Buf_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 2, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 24800, 0, 24800, 0, 1};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
FCM_A_CHA Rte_Buf_Runbl_IpmCanRx_100ms_FCM_A_CHA_FCM_A_CHA = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
FCM_B_CHA Rte_Buf_Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA = {0, 0, 0, 0, 0, 0, 12400, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7800, 0, 0, 0, 0, 0, 0, 0, 0, 0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
GSM_outputs Irv_AppSwcVcu_GSM_outputs = {0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
GSM_outputs Irv_AppSwcVcu_AppSwcVcu_Init_GSM_outputs = {0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
GSM_outputs Irv_AppSwcVcu_Runbl_VCU_100ms_GSM_outputs = {0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
GSM_outputs Irv_AppSwcVcu_Runbl_VCU_10ms_GSM_outputs = {0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
GSM_outputs Irv_AppSwcVcu_Runbl_VCU_20ms_GSM_outputs = {0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
GSM_outputs Irv_AppSwcVcu_Runbl_VcuTx_10ms_GSM_outputs = {0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
HMI_outputs Irv_AppSwcVcu_HMI_outputs = {0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
HMI_outputs Irv_AppSwcVcu_AppSwcVcu_Init_HMI_outputs = {0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
HMI_outputs Irv_AppSwcVcu_Runbl_VCU_100ms_HMI_outputs = {0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
HMI_outputs Irv_AppSwcVcu_Runbl_VcuTx_10ms_HMI_outputs = {0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
HU_B_BAC Rte_Buf_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
HVCH_Status1_BOD Rte_Buf_Runbl_IpmCanRx_100ms_HVCH_Status1_BOD_HVCH_Status1_BOD = {0, 0, 0, 0, 0, 0, 0, 0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
HVCH_Status2_BOD Rte_Buf_Runbl_IpmCanRx_100ms_HVCH_Status2_BOD_HVCH_Status2_BOD = {0, 0, 0, 0, 0, 0, 0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
HVM_outputs Irv_AppSwcVcu_HVM_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
HVM_outputs Irv_AppSwcVcu_AppSwcVcu_Init_HVM_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
HVM_outputs Irv_AppSwcVcu_Runbl_VCU_100ms_HVM_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
HVM_outputs Irv_AppSwcVcu_Runbl_VCU_10ms_HVM_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
HVM_outputs Irv_AppSwcVcu_Runbl_VCU_20ms_HVM_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
HVM_outputs Irv_AppSwcVcu_Runbl_VcuTx_10ms_HVM_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
HornCtl Irv_AppSwcBcm_HornCtl_Bus = {0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
HornCtl Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_HornCtl_Bus = {0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
HornCtl Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_HornCtl_Bus = {0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
HornCtl Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_HornCtl_Bus = {0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
ICU_2_Odo_BAC Rte_Buf_Runbl_IpmCanRx_100ms_ICU_2_Odo_BAC_ICU_2_Odo_BAC = {0, 0, 0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
IMMOCtl Irv_AppSwcBcm_IMMOCtl_Bus = {{0,0,0,0,0,0,0,0},0,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
IMMOCtl Irv_AppSwcBcm_AppSwcBcm_Init_IMMOCtl_Bus = {{0,0,0,0,0,0,0,0},0,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
IMMOCtl Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_IMMOCtl_Bus = {{0,0,0,0,0,0,0,0},0,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
IMMOCtl Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_IMMOCtl_Bus = {{0,0,0,0,0,0,0,0},0,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
INV_1_Value_EPT Rte_Buf_Runbl_IpmCanRx_10ms_INV_1_Value_EPT_INV_1_Value_EPT = {0, 8192, 0, 0, 0, 0, 12000, 0, 0, 0, 0, 0, 0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
INV_2_Value_EPT Rte_Buf_Runbl_IpmCanRx_10ms_INV_2_Value_EPT_INV_2_Value_EPT = {0, 0, 0, 8192, 0, 0, 0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
INV_3_Value_EPT Rte_Buf_Runbl_IpmCanRx_10ms_INV_3_Value_EPT_INV_3_Value_EPT = {0, 0, 1000, 0, 0, 500};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
INV_4_Value_EPT Rte_Buf_Runbl_IpmCanRx_10ms_INV_4_Value_EPT_INV_4_Value_EPT = {0, 0, 0, 16384, 16384, 0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
INV_IMMO_Req_EPT Rte_Buf_Runbl_IpmCanRx_100ms_INV_IMMO_Req_EPT_INV_IMMO_Req_EPT = {0, 0, 0, 0, 0, 0, 0, 0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
IODID Irv_AppSwcBcm_IODID_Bus = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
IODID Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_IODID_Bus = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
IODID Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_IODID_Bus = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
IODID Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_IODID_Bus = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
IPC_outputs Irv_AppSwcVcu_IPC_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
IPC_outputs Irv_AppSwcVcu_AppSwcVcu_Init_IPC_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
IPC_outputs Irv_AppSwcVcu_Runbl_VCU_100ms_IPC_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
IPC_outputs Irv_AppSwcVcu_Runbl_VCU_10ms_IPC_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
IPC_outputs Irv_AppSwcVcu_Runbl_VCU_20ms_IPC_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
IPC_outputs Irv_AppSwcVcu_Runbl_VcuTx_10ms_IPC_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
IPU_DCC_1_State_EPT Rte_Buf_Runbl_IpmCanRx_100ms_IPU_DCC_1_State_EPT_IPU_DCC_1_State_EPT = {0, 0, 0, 0, 0, 4096, 0, 0, 0, 0, 0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
IPU_DCC_2_ChrgInValue_EPT Rte_Buf_Runbl_IpmCanRx_100ms_IPU_DCC_2_ChrgInValue_EPT_IPU_DCC_2_ChrgInValue_EPT = {0, 0, 256, 0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
IPU_OBC_1_State_EPT Rte_Buf_Runbl_IpmCanRx_100ms_IPU_OBC_1_State_EPT_IPU_OBC_1_State_EPT = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
IPU_OBC_2_Inlet_EPT Rte_Buf_Runbl_IpmCanRx_100ms_IPU_OBC_2_Inlet_EPT_IPU_OBC_2_Inlet_EPT = {0, 0, 0, 512, 0, 0, 0, 0, 0, 0, 0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
LampCtl Irv_AppSwcBcm_LampCtl_Bus = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
LampCtl Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_LampCtl_Bus = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
LampCtl Irv_AppSwcBcm_Runbl_AppSwcBcm_10ms_LampCtl_Bus = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
LampCtl Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_LampCtl_Bus = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
LampCtl Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_LampCtl_Bus = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
NVM_Imdt_outputs Irv_AppSwcVcu_NVM_Imdt_outputs = {0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
NVM_Imdt_outputs Irv_AppSwcVcu_AppSwcVcu_Init_NVM_Imdt_outputs = {0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
NVM_Imdt_outputs Irv_AppSwcVcu_Runbl_VCU_100ms_NVM_Imdt_outputs = {0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
NVM_Imdt_outputs Irv_AppSwcVcu_Runbl_VCU_10ms_NVM_Imdt_outputs = {0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
NVM_Imdt_outputs Irv_AppSwcVcu_Runbl_VCU_20ms_NVM_Imdt_outputs = {0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
NVM_Imdt_outputs Irv_AppSwcVcu_Runbl_VcuRx_10ms_NVM_Imdt_outputs = {0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
NVM_Imdt_outputs Irv_AppSwcVcu_Runbl_VcuTx_10ms_NVM_Imdt_outputs = {0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
NVM_outputs Irv_AppSwcVcu_NVM_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
NVM_outputs Irv_AppSwcVcu_AppSwcVcu_Init_NVM_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
NVM_outputs Irv_AppSwcVcu_Runbl_VCU_100ms_NVM_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
NVM_outputs Irv_AppSwcVcu_Runbl_VCU_10ms_NVM_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
NVM_outputs Irv_AppSwcVcu_Runbl_VCU_20ms_NVM_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
NVM_outputs Irv_AppSwcVcu_Runbl_VcuRx_10ms_NVM_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
PDUCtl Irv_AppSwcBcm_PDUCtl_Bus = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
PDUCtl Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_PDUCtl_Bus = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
PDUCtl Irv_AppSwcBcm_Runbl_AppSwcBcm_10ms_PDUCtl_Bus = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
PDUCtl Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_PDUCtl_Bus = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
PDUCtl Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_PDUCtl_Bus = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
PEPSCtl Irv_AppSwcBcm_PEPSCtl_Bus = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
PEPSCtl Irv_AppSwcBcm_AppSwcBcm_Init_PEPSCtl_Bus = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
PEPSCtl Irv_AppSwcBcm_Runbl_AppSwcBcm_10ms_PEPSCtl_Bus = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
PEPSCtl Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
PEPSCtl Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_PEPSCtl_Bus = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
RME_outputs Irv_AppSwcVcu_RME_outputs = {0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
RME_outputs Irv_AppSwcVcu_AppSwcVcu_Init_RME_outputs = {0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
RME_outputs Irv_AppSwcVcu_Runbl_VCU_100ms_RME_outputs = {0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
RME_outputs Irv_AppSwcVcu_Runbl_VcuTx_10ms_RME_outputs = {0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
RVMCtl Irv_AppSwcBcm_RVMCtl_Bus = {0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
RVMCtl Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_RVMCtl_Bus = {0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
RVMCtl Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_RVMCtl_Bus = {0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
SCS_LeSwitchSts_BOD Rte_Buf_Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
SCS_RiSwitchSts_BOD Rte_Buf_Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
SRS_1_Status_CHA Rte_Buf_Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA = {0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 0, 2, 1, 1, 0, 0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
SeatCtl Irv_AppSwcBcm_SeatCtl_Bus = {0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
SeatCtl Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_SeatCtl_Bus = {0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
SeatCtl Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_SeatCtl_Bus = {0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Bcm_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Bcm_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Bcm_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Bcm_IPM_HU_B_BAC_IPM_HU_B_BAC_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Bcm_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Bcm_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Bcm_FCLL_TiWngSt_FCLL_TiWngSt_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Bcm_FCLR_TiWngSt_FCLR_TiWngSt_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Bcm_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Bcm_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Bcm_IPM_EHB_A_CHA_IPM_EHB_A_CHA_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Bcm_IPM_EHB_B_CHA_IPM_EHB_B_CHA_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Bcm_IPM_ESCL_ESCLStatus_BOD_IPM_ESCL_ESCLStatus_BOD_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Bcm_IPM_FCM_A_CHA_IPM_FCM_A_CHA_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Bcm_IPM_INV_IMMO_Req_EPT_IPM_INV_IMMO_Req_EPT_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Bcm_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Ipm_ACCM_Version_BOD_ACCM_Version_BOD_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Ipm_BMS_5_BatTemp_EPT_BMS_5_BatTemp_EPT_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Ipm_BMS_9_BattInfo_EPT_BMS_9_BattInfo_EPT_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Ipm_COMP_AC_BOD_COMP_AC_BOD_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Ipm_FCM_A_CHA_FCM_A_CHA_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Ipm_HU_B_BAC_HU_B_BAC_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Ipm_HVCH_Status1_BOD_HVCH_Status1_BOD_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Ipm_HVCH_Status2_BOD_HVCH_Status2_BOD_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Ipm_ICU_2_Odo_BAC_ICU_2_Odo_BAC_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Ipm_INV_IMMO_Req_EPT_INV_IMMO_Req_EPT_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Ipm_IPU_DCC_1_State_EPT_IPU_DCC_1_State_EPT_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Ipm_IPU_DCC_2_ChrgInValue_EPT_IPU_DCC_2_ChrgInValue_EPT_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Ipm_IPU_OBC_1_State_EPT_IPU_OBC_1_State_EPT_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Ipm_IPU_OBC_2_Inlet_EPT_IPU_OBC_2_Inlet_EPT_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Ipm_TBOX_BJS_Time_BAC_TBOX_BJS_Time_BAC_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Ipm_EHB_B_CHA_EHB_B_CHA_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Ipm_EPS_2_StrWhlAng_CHA_EPS_2_StrWhlAng_CHA_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Ipm_ESC_7_FuncStatus_CHA_ESC_7_FuncStatus_CHA_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Ipm_ESC_A_CHA_ESC_A_CHA_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Ipm_INV_1_Value_EPT_INV_1_Value_EPT_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Ipm_INV_2_Value_EPT_INV_2_Value_EPT_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Ipm_INV_3_Value_EPT_INV_3_Value_EPT_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Ipm_INV_4_Value_EPT_INV_4_Value_EPT_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Ipm_BMS_10_DC_ChargeStates_EPT_BMS_10_DC_ChargeStates_EPT_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Ipm_BMS_1_MainState_EPT_BMS_1_MainState_EPT_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Ipm_BMS_2_BatState_EPT_BMS_2_BatState_EPT_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Ipm_BMS_3_DC_ChargeState_EPT_BMS_3_DC_ChargeState_EPT_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Ipm_BMS_4_AC_ChargeState_EPT_BMS_4_AC_ChargeState_EPT_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Ipm_BMS_6_DischrgRecup_EPT_BMS_6_DischrgRecup_EPT_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Ipm_BMS_7_CellVolt_EPT_BMS_7_CellVolt_EPT_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Ipm_CRRR_A_CHA_CRRR_A_CHA_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Ipm_EHB_A_CHA_EHB_A_CHA_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Ipm_FCM_B_CHA_FCM_B_CHA_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Ipm_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Ipm_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Ipm_ESCL_ESCLStatus_BOD_ESCL_ESCLStatus_BOD_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Ipm_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Ipm_SRS_1_Status_CHA_SRS_1_Status_CHA_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Ipm_DAG_Comm_outputs_DAG_Comm_outputs_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Opm_Bcm2OpmEPT_outputs_Bcm2OpmEPT_outputs_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Opm_Bcm2OpmOBD_outputs_Bcm2OpmOBD_outputs_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Opm_TMS2VCU_AC_1_Command_Outputs_TMS2VCU_AC_1_Command_Outputs_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Opm_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Opm_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Opm_TMS2VCU_AC_8_status_Outputs_TMS2VCU_AC_8_status_Outputs_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Opm_TMS2VCU_AC_ACStatuts_Outputs_TMS2VCU_AC_ACStatuts_Outputs_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Opm_TMS2VCU_AC_COMP_Outputs_TMS2VCU_AC_COMP_Outputs_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Opm_TMS2VCU_HVCH_Command_Outputs_TMS2VCU_HVCH_Command_Outputs_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Opm_TMS2VCU_TMS_LINTestData1_Outputs_TMS2VCU_TMS_LINTestData1_Outputs_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Opm_TMS2VCU_TMS_LINTestData2_Outputs_TMS2VCU_TMS_LINTestData2_Outputs_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Opm_TMS2VCU_TMS_LINTestData3_Outputs_TMS2VCU_TMS_LINTestData3_Outputs_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Opm_IPM_FCM_B_CHA_IPM_FCM_B_CHA_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Opm_IPM_INV_1_Value_EPT_IPM_INV_1_Value_EPT_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Opm_Bcm2OpmBAC_outputs_Bcm2OpmBAC_outputs_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Opm_TMS2VCU_PPV_outputs_TMS2VCU_PPV_outputs_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Opm_Vcu2OpmBAC_outputs_Vcu2OpmBAC_outputs_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Opm_Vcu2OpmCHA_outputs_Vcu2OpmCHA_outputs_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Opm_Vcu2OpmEPT_outputs_Vcu2OpmEPT_outputs_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_AcPMP_HWVersion_AcPMP_HWVersion_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_AcPMP_PartNumber_AcPMP_PartNumber_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_AcPMP_ProjectCode1_AcPMP_ProjectCode1_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_AcPMP_ProjectCode2_AcPMP_ProjectCode2_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_AcPMP_PumpDryRunningSta_AcPMP_PumpDryRunningSta_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_AcPMP_PumpInputVolt_AcPMP_PumpInputVolt_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_AcPMP_PumpMotorSta_AcPMP_PumpMotorSta_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_AcPMP_PumpPowerSta_AcPMP_PumpPowerSta_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_AcPMP_PumpTempSta_AcPMP_PumpTempSta_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_AcPMP_RESP_ERROR_AcPMP_RESP_ERROR_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_AcPMP_RealRPM_AcPMP_RealRPM_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_AcPMP_SWVersion_Main_AcPMP_SWVersion_Main_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_AcPMP_SWVersion_Patch_AcPMP_SWVersion_Patch_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_AcPMP_SWVersion_Sub_AcPMP_SWVersion_Sub_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_AcPMP_SupplierNumber_AcPMP_SupplierNumber_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_BAT_EXV_CurrentPosition_B_BAT_EXV_CurrentPosition_B_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_BAT_EXV_FaultState_B_BAT_EXV_FaultState_B_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_BAT_EXV_ResponseError_B_BAT_EXV_ResponseError_B_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_BAT_EXV_RunState_B_BAT_EXV_RunState_B_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_BAT_EXV_SupplierLabel_BAT_EXV_SupplierLabel_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_BAT_EXV_VoltageState_B_BAT_EXV_VoltageState_B_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_BAT_EXV_Warning_OverTemp_BAT_EXV_Warning_OverTemp_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_BAT_EXV_initialize_status_BAT_EXV_initialize_status_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_BatPMP_PumpDryRunningSta_BatPMP_PumpDryRunningSta_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_BatPMP_PumpInputVolt_BatPMP_PumpInputVolt_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_BatPMP_PumpMotorSta_BatPMP_PumpMotorSta_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_BatPMP_PumpPowerSta_BatPMP_PumpPowerSta_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_BatPMP_PumpTempSta_BatPMP_PumpTempSta_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_BatPMP_RESP_ERROR_BatPMP_RESP_ERROR_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_BatPMP_RealRPM_BatPMP_RealRPM_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_Bat_EXV_HWVersion_Bat_EXV_HWVersion_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_Bat_EXV_PartNumber_Bat_EXV_PartNumber_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_Bat_EXV_ProjectCode1_Bat_EXV_ProjectCode1_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_Bat_EXV_ProjectCode2_Bat_EXV_ProjectCode2_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_Bat_EXV_SWVersion_Main_Bat_EXV_SWVersion_Main_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_Bat_EXV_SWVersion_Patch_Bat_EXV_SWVersion_Patch_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_Bat_EXV_SWVersion_Sub_Bat_EXV_SWVersion_Sub_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_Bat_EXV_SupplierNumber_Bat_EXV_SupplierNumber_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_C3WV_ErrResp_C3WV_ErrResp_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_C3WV_FltSts_C3WV_FltSts_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_C3WV_Mode_C3WV_Mode_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_C3WV_PosRec_C3WV_PosRec_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_C3WV_RunSts_C3WV_RunSts_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_C3WV_SpdLvl_C3WV_SpdLvl_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_C3WV_TempSts_C3WV_TempSts_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_C3WV_VoltSts_C3WV_VoltSts_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_C5WVFltSts_C5WVFltSts_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_C5WVMode_C5WVMode_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_C5WVPosRec_C5WVPosRec_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_C5WVRunSts_C5WVRunSts_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_C5WVSpdLvl_C5WVSpdLvl_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_C5WVTempSts_C5WVTempSts_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_C5WVVoltSts_C5WVVoltSts_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_EXV_CurrentInitState_EXV_CurrentInitState_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_EXV_CurrentPosition_EXV_CurrentPosition_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_EXV_FaultState_EXV_FaultState_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_EXV_ResponseError_EXV_ResponseError_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_EXV_RunState_EXV_RunState_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_EXV_TemperatureWarn_EXV_TemperatureWarn_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_EXV_VoltageState_EXV_VoltageState_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_ErrRespC5WV_ErrRespC5WV_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_HP_EXV_CurrentPosition_B_HP_EXV_CurrentPosition_B_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_HP_EXV_FaultState_B_HP_EXV_FaultState_B_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_HP_EXV_HWVersion_HP_EXV_HWVersion_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_HP_EXV_PartNumber_HP_EXV_PartNumber_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_HP_EXV_ProjectCode1_HP_EXV_ProjectCode1_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_HP_EXV_ProjectCode2_HP_EXV_ProjectCode2_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_HP_EXV_ResponseError_B_HP_EXV_ResponseError_B_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_HP_EXV_RunState_B_HP_EXV_RunState_B_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_HP_EXV_SWVersion_Main_HP_EXV_SWVersion_Main_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_HP_EXV_SWVersion_Patch_HP_EXV_SWVersion_Patch_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_HP_EXV_SWVersion_Sub_HP_EXV_SWVersion_Sub_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_HP_EXV_SupplierLabel_HP_EXV_SupplierLabel_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_HP_EXV_SupplierNumber_HP_EXV_SupplierNumber_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_HP_EXV_VoltageState_B_HP_EXV_VoltageState_B_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_HP_EXV_Warning_OverTemp_HP_EXV_Warning_OverTemp_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_HP_EXV_initialize_status_HP_EXV_initialize_status_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_IPM_BMS_2_BatState_EPT_IPM_BMS_2_BatState_EPT_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_IPM_HU_B_BAC_IPM_HU_B_BAC_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_MotPMP_PumpDryRunningSta_MotPMP_PumpDryRunningSta_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_MotPMP_PumpInputVolt_MotPMP_PumpInputVolt_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_MotPMP_PumpMotorSta_MotPMP_PumpMotorSta_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_MotPMP_PumpPowerSta_MotPMP_PumpPowerSta_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_MotPMP_PumpTempSta_MotPMP_PumpTempSta_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_MotPMP_RESP_ERROR_MotPMP_RESP_ERROR_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_MotPMP_RealRPM_MotPMP_RealRPM_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_Tms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_VCU_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_VCU_TMS2VCU_PPV_outputs_TMS2VCU_PPV_outputs_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_VCU_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_VCU_IPM_EHB_A_CHA_IPM_EHB_A_CHA_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_VCU_CANCommCRCFlt_outputs_CANCommCRCFlt_outputs_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_VCU_IPM_BMS_3_DC_ChargeState_EPT_IPM_BMS_3_DC_ChargeState_EPT_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_VCU_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_VCU_IPM_BMS_7_CellVolt_EPT_IPM_BMS_7_CellVolt_EPT_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_VCU_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_VCU_IPM_ICU_2_Odo_BAC_IPM_ICU_2_Odo_BAC_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_VCU_IPM_IPU_DCC_2_ChrgInValue_EPT_IPM_IPU_DCC_2_ChrgInValue_EPT_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_VCU_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_VCU_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_VCU_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_VCU_CANCommErr_outputs_CANCommErr_outputs_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_VCU_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_VCU_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_VCU_IPM_BMS_2_BatState_EPT_IPM_BMS_2_BatState_EPT_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_VCU_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_VCU_IPM_BMS_6_DischrgRecup_EPT_IPM_BMS_6_DischrgRecup_EPT_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_VCU_IPM_BMS_9_BattInfo_EPT_IPM_BMS_9_BattInfo_EPT_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_VCU_IPM_EHB_B_CHA_IPM_EHB_B_CHA_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_VCU_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_VCU_IPM_ESC_A_CHA_IPM_ESC_A_CHA_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_VCU_IPM_FCM_B_CHA_IPM_FCM_B_CHA_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_VCU_IPM_HU_B_BAC_IPM_HU_B_BAC_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_VCU_IPM_INV_1_Value_EPT_IPM_INV_1_Value_EPT_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_VCU_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_VCU_IPM_INV_3_Value_EPT_IPM_INV_3_Value_EPT_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_VCU_IPM_INV_4_Value_EPT_IPM_INV_4_Value_EPT_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_VCU_IPM_IPU_DCC_1_State_EPT_IPM_IPU_DCC_1_State_EPT_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_VCU_IPM_IPU_OBC_1_State_EPT_IPM_IPU_OBC_1_State_EPT_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_VCU_IPM_SCS_RiSwitchSts_BOD_IPM_SCS_RiSwitchSts_BOD_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_VCU_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_VCU_MsgActv_outputs_MsgActv_outputs_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_VCU_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
Std_ReturnType Rte_swComponentPrototype_VCU_Tms2Vcu_Info_Tms2Vcu_Info_ibuffer_status = RTE_E_OK;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
SteerWhlCtl Irv_AppSwcBcm_SteerWhlCtl_Bus = {0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
SteerWhlCtl Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_SteerWhlCtl_Bus = {0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
SteerWhlCtl Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_SteerWhlCtl_Bus = {0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
TBOX_BJS_Time_BAC Rte_Buf_Runbl_IpmCanRx_100ms_TBOX_BJS_Time_BAC_TBOX_BJS_Time_BAC = {0, 0, 1, 0, 0, 1, 0, 0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
TBOX_outputs Irv_AppSwcVcu_TBOX_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
TBOX_outputs Irv_AppSwcVcu_AppSwcVcu_Init_TBOX_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
TBOX_outputs Irv_AppSwcVcu_Runbl_VCU_100ms_TBOX_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
TBOX_outputs Irv_AppSwcVcu_Runbl_VCU_10ms_TBOX_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
TBOX_outputs Irv_AppSwcVcu_Runbl_VCU_20ms_TBOX_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
TBOX_outputs Irv_AppSwcVcu_Runbl_VcuTx_10ms_TBOX_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
TMS2VCU_AC_1_Command_Outputs Rte_Buf_Runbl_OpmCanTx_100ms_TMS2VCU_AC_1_Command_Outputs_TMS2VCU_AC_1_Command_Outputs = {0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
TMS2VCU_AC_2_State_Outputs Rte_Buf_Runbl_OpmCanTx_100ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
TMS2VCU_AC_2_State_Outputs Rte_Buf_Runbl_VcuRx_10ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
TMS2VCU_AC_2_State_Outputs Irv_AppSwcVcu_TMS2VCU_AC_2_State_Outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
TMS2VCU_AC_2_State_Outputs Irv_AppSwcVcu_Runbl_VCU_20ms_TMS2VCU_AC_2_State_Outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
TMS2VCU_AC_2_State_Outputs Irv_AppSwcVcu_Runbl_VcuRx_10ms_TMS2VCU_AC_2_State_Outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
TMS2VCU_AC_3_State_Outputs Rte_Buf_Runbl_OpmCanTx_100ms_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs = {0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
TMS2VCU_AC_3_State_Outputs Rte_Buf_Runbl_VCU_100ms_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs = {0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
TMS2VCU_AC_8_status_Outputs Rte_Buf_Runbl_OpmCanTx_100ms_TMS2VCU_AC_8_status_Outputs_TMS2VCU_AC_8_status_Outputs = {0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
TMS2VCU_AC_ACStatuts_Outputs Rte_Buf_Runbl_OpmCanTx_100ms_TMS2VCU_AC_ACStatuts_Outputs_TMS2VCU_AC_ACStatuts_Outputs = {0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
TMS2VCU_AC_COMP_Outputs Rte_Buf_Runbl_OpmCanTx_100ms_TMS2VCU_AC_COMP_Outputs_TMS2VCU_AC_COMP_Outputs = {0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
TMS2VCU_HVCH_Command_Outputs Rte_Buf_Runbl_OpmCanTx_100ms_TMS2VCU_HVCH_Command_Outputs_TMS2VCU_HVCH_Command_Outputs = {0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
TMS2VCU_PPVAddSignalGroup_Outputs Rte_Buf_Runbl_OpmRx_10ms_TMS2VCU_PPV_outputs_TMS2VCU_PPV_outputs = {0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
TMS2VCU_PPVAddSignalGroup_Outputs Irv_AppSwcOpm_TMS2VCU_PPV_outputs = {0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
TMS2VCU_PPVAddSignalGroup_Outputs Irv_AppSwcOpm_Runbl_OpmCanTx_100ms_TMS2VCU_PPV_outputs = {0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
TMS2VCU_PPVAddSignalGroup_Outputs Irv_AppSwcOpm_Runbl_OpmCanTx_20ms_TMS2VCU_PPV_outputs = {0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
TMS2VCU_PPVAddSignalGroup_Outputs Irv_AppSwcOpm_Runbl_OpmRx_10ms_TMS2VCU_PPV_outputs = {0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
TMS2VCU_PPVAddSignalGroup_Outputs Rte_Buf_Runbl_VCU_100ms_TMS2VCU_PPV_outputs_TMS2VCU_PPV_outputs = {0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
TMS2VCU_TMS_LINTestData1_Outputs Rte_Buf_Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData1_Outputs_TMS2VCU_TMS_LINTestData1_Outputs = {0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
TMS2VCU_TMS_LINTestData2_Outputs Rte_Buf_Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData2_Outputs_TMS2VCU_TMS_LINTestData2_Outputs = {0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
TMS2VCU_TMS_LINTestData3_Outputs Rte_Buf_Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData3_Outputs_TMS2VCU_TMS_LINTestData3_Outputs = {0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
TboxTim Irv_AppSwcBcm_TboxTim_Bus = {0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
TboxTim Irv_AppSwcBcm_AppSwcBcm_Init_TboxTim_Bus = {0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
TboxTim Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_TboxTim_Bus = {0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
TboxTim Irv_AppSwcBcm_Runbl_AppSwcBcm_10ms_TboxTim_Bus = {0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
Tms2Vcu_Info Rte_Buf_Runbl_VcuRx_10ms_Tms2Vcu_Info_Tms2Vcu_Info = {0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
Tms2Vcu_Info Irv_AppSwcVcu_Tms2Vcu_Info = {0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
Tms2Vcu_Info Irv_AppSwcVcu_Runbl_VCU_20ms_Tms2Vcu_Info = {0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
Tms2Vcu_Info Irv_AppSwcVcu_Runbl_VcuRx_10ms_Tms2Vcu_Info = {0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
Tms2Vcu_Info Irv_AppSwcVcu_Runbl_VcuTx_10ms_Tms2Vcu_Info = {0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_16
#include "Rte_MemMap.h"
UInt16 Rte_Buf_Task_100ms_BAT_EXV_CurrentPosition_B_BAT_EXV_CurrentPosition_B = {0};
#define RTE_STOP_SEC_VAR_INIT_16
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_16
#include "Rte_MemMap.h"
UInt16 Rte_Buf_Task_100ms_C3WV_PosRec_C3WV_PosRec = {0};
#define RTE_STOP_SEC_VAR_INIT_16
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_16
#include "Rte_MemMap.h"
UInt16 Rte_Buf_Task_100ms_C5WVPosRec_C5WVPosRec = {0};
#define RTE_STOP_SEC_VAR_INIT_16
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_16
#include "Rte_MemMap.h"
UInt16 Rte_Buf_Task_100ms_EXV_CurrentPosition_EXV_CurrentPosition = {0};
#define RTE_STOP_SEC_VAR_INIT_16
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_16
#include "Rte_MemMap.h"
UInt16 Rte_Buf_Task_100ms_HP_EXV_CurrentPosition_B_HP_EXV_CurrentPosition_B = {0};
#define RTE_STOP_SEC_VAR_INIT_16
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_16
#include "Rte_MemMap.h"
UInt16 Irv_AppSwcVcu_VDAG_VCUErrCode_enum = 0;
#define RTE_STOP_SEC_VAR_INIT_16
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_16
#include "Rte_MemMap.h"
UInt16 Irv_AppSwcVcu_Runbl_VCU_20ms_VDAG_VCUErrCode_enum = 0;
#define RTE_STOP_SEC_VAR_INIT_16
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_16
#include "Rte_MemMap.h"
UInt16 Irv_AppSwcVcu_Runbl_VcuTx_10ms_VDAG_VCUErrCode_enum = 0;
#define RTE_STOP_SEC_VAR_INIT_16
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Runbl_AppSwcBcm_50ms_FCLL_TiWngSt_FCLL_TiWngSt = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Runbl_AppSwcBcm_50ms_FCLR_TiWngSt_FCLR_TiWngSt = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_AcPMP_HWVersion_AcPMP_HWVersion = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_AcPMP_PartNumber_AcPMP_PartNumber = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_AcPMP_ProjectCode1_AcPMP_ProjectCode1 = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_AcPMP_ProjectCode2_AcPMP_ProjectCode2 = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_AcPMP_PumpInputVolt_AcPMP_PumpInputVolt = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_AcPMP_PumpMotorSta_AcPMP_PumpMotorSta = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_AcPMP_PumpPowerSta_AcPMP_PumpPowerSta = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_AcPMP_PumpTempSta_AcPMP_PumpTempSta = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_AcPMP_RealRPM_AcPMP_RealRPM = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_AcPMP_SWVersion_Main_AcPMP_SWVersion_Main = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_AcPMP_SWVersion_Patch_AcPMP_SWVersion_Patch = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_AcPMP_SWVersion_Sub_AcPMP_SWVersion_Sub = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_AcPMP_SupplierNumber_AcPMP_SupplierNumber = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_BAT_EXV_FaultState_B_BAT_EXV_FaultState_B = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_BAT_EXV_VoltageState_B_BAT_EXV_VoltageState_B = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_BAT_EXV_initialize_status_BAT_EXV_initialize_status = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_BatPMP_PumpInputVolt_BatPMP_PumpInputVolt = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_BatPMP_PumpMotorSta_BatPMP_PumpMotorSta = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_BatPMP_PumpPowerSta_BatPMP_PumpPowerSta = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_BatPMP_PumpTempSta_BatPMP_PumpTempSta = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_BatPMP_RealRPM_BatPMP_RealRPM = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_Bat_EXV_HWVersion_Bat_EXV_HWVersion = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_Bat_EXV_PartNumber_Bat_EXV_PartNumber = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_Bat_EXV_ProjectCode1_Bat_EXV_ProjectCode1 = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_Bat_EXV_ProjectCode2_Bat_EXV_ProjectCode2 = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_Bat_EXV_SWVersion_Main_Bat_EXV_SWVersion_Main = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_Bat_EXV_SWVersion_Patch_Bat_EXV_SWVersion_Patch = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_Bat_EXV_SWVersion_Sub_Bat_EXV_SWVersion_Sub = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_Bat_EXV_SupplierNumber_Bat_EXV_SupplierNumber = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_C3WV_FltSts_C3WV_FltSts = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_C3WV_Mode_C3WV_Mode = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_C3WV_SpdLvl_C3WV_SpdLvl = 0;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_C3WV_TempSts_C3WV_TempSts = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_C3WV_VoltSts_C3WV_VoltSts = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_C5WVFltSts_C5WVFltSts = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_C5WVMode_C5WVMode = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_C5WVSpdLvl_C5WVSpdLvl = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_C5WVTempSts_C5WVTempSts = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_C5WVVoltSts_C5WVVoltSts = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_EXV_CurrentInitState_EXV_CurrentInitState = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_EXV_FaultState_EXV_FaultState = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_EXV_TemperatureWarn_EXV_TemperatureWarn = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_EXV_VoltageState_EXV_VoltageState = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_HP_EXV_FaultState_B_HP_EXV_FaultState_B = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_HP_EXV_HWVersion_HP_EXV_HWVersion = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_HP_EXV_PartNumber_HP_EXV_PartNumber = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_HP_EXV_ProjectCode1_HP_EXV_ProjectCode1 = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_HP_EXV_ProjectCode2_HP_EXV_ProjectCode2 = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_HP_EXV_SWVersion_Main_HP_EXV_SWVersion_Main = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_HP_EXV_SWVersion_Patch_HP_EXV_SWVersion_Patch = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_HP_EXV_SWVersion_Sub_HP_EXV_SWVersion_Sub = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_HP_EXV_SupplierNumber_HP_EXV_SupplierNumber = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_HP_EXV_VoltageState_B_HP_EXV_VoltageState_B = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_HP_EXV_initialize_status_HP_EXV_initialize_status = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_MotPMP_PumpInputVolt_MotPMP_PumpInputVolt = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_MotPMP_PumpMotorSta_MotPMP_PumpMotorSta = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_MotPMP_PumpPowerSta_MotPMP_PumpPowerSta = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_MotPMP_PumpTempSta_MotPMP_PumpTempSta = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Rte_Buf_Task_100ms_MotPMP_RealRPM_MotPMP_RealRPM = {0};
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Irv_AppSwcVcu_VDAG_VCUFltLvl_enum = 0;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Irv_AppSwcVcu_AppSwcVcu_Init_VDAG_VCUFltLvl_enum = 0;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Irv_AppSwcVcu_Runbl_VCU_20ms_VDAG_VCUFltLvl_enum = 0;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h"
UInt8 Irv_AppSwcVcu_Runbl_VcuTx_10ms_VDAG_VCUFltLvl_enum = 0;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
VSO_outputs Irv_AppSwcVcu_VSO_outputs = {0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
VSO_outputs Irv_AppSwcVcu_AppSwcVcu_Init_VSO_outputs = {0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
VSO_outputs Irv_AppSwcVcu_Runbl_VCU_10ms_VSO_outputs = {0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
VSO_outputs Irv_AppSwcVcu_Runbl_VcuTx_10ms_VSO_outputs = {0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
VTM_outputs Irv_AppSwcVcu_VTM_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
VTM_outputs Irv_AppSwcVcu_AppSwcVcu_Init_VTM_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
VTM_outputs Irv_AppSwcVcu_Runbl_VCU_100ms_VTM_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
VTM_outputs Irv_AppSwcVcu_Runbl_VCU_10ms_VTM_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
VTM_outputs Irv_AppSwcVcu_Runbl_VCU_20ms_VTM_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
VTM_outputs Irv_AppSwcVcu_Runbl_VcuTx_10ms_VTM_outputs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
VehCfg_outputs Irv_AppSwcVcu_VehCfg_outputs = {0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
VehCfg_outputs Irv_AppSwcVcu_Runbl_VCU_10ms_VehCfg_outputs = {0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
VehCfg_outputs Irv_AppSwcVcu_Runbl_VcuRx_10ms_VehCfg_outputs = {0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
WakeUpCtl Irv_AppSwcBcm_WakeUpCtl_Bus = {0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
WakeUpCtl Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_WakeUpCtl_Bus = {0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
WakeUpCtl Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_WakeUpCtl_Bus = {0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
WinCtl Irv_AppSwcBcm_WinCtl_Bus = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
WinCtl Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_WinCtl_Bus = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
WinCtl Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_WinCtl_Bus = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
WinCtl Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_WinCtl_Bus = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
WiperCtl Irv_AppSwcBcm_Wiper_Bus = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
WiperCtl Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_Wiper_Bus = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
WiperCtl Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_Wiper_Bus = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
WiperCtl Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_Wiper_Bus = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void rte_memcpy(uint8 * pDest, const uint8 * pSrc, uint32 length)
{
    while (length > 0U)
    {
        *pDest = *pSrc;
        pDest++;
        pSrc++;
        length--;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void *rte_memset(void * pDest, uint8 set, sint32 length)
{
    if ((pDest == NULL_PTR) || (length < 0))
    {
        return NULL_PTR;
    }
    uint8 * dest = (uint8*)pDest;
    while (length > 0)
    {
        *dest = set;
        dest++;
        length--;
    }
    return dest;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_AppSwcBcm_20ms_Bcm2OpmBAC_outputs_Bcm2OpmBAC_outputs(DT_Bcm2OpmBAC_outputs value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_OpmRx_10ms_Bcm2OpmBAC_outputs_Bcm2OpmBAC_outputs, (uint8*)&value, sizeof(DT_Bcm2OpmBAC_outputs));
        Rte_Inst_AppSwcOpm.Runbl_OpmRx_10ms_Bcm2OpmBAC_outputs_Bcm2OpmBAC_outputs->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_AppSwcBcm_20ms_Bcm2OpmEPT_outputs_Bcm2OpmEPT_outputs(DT_Bcm2OpmEPT_outputs value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_OpmCanTx_100ms_Bcm2OpmEPT_outputs_Bcm2OpmEPT_outputs, (uint8*)&value, sizeof(DT_Bcm2OpmEPT_outputs));
        Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_Bcm2OpmEPT_outputs_Bcm2OpmEPT_outputs->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_AppSwcBcm_20ms_Bcm2OpmOBD_outputs_Bcm2OpmOBD_outputs(DT_Bcm2OpmOBD_outputs value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_OpmCanTx_100ms_Bcm2OpmOBD_outputs_Bcm2OpmOBD_outputs, (uint8*)&value, sizeof(DT_Bcm2OpmOBD_outputs));
        Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_Bcm2OpmOBD_outputs_Bcm2OpmOBD_outputs->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_AppSwcBcm_20ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs(DT_Bcm2VcuTms_outputs value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Task_100ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs, (uint8*)&value, sizeof(DT_Bcm2VcuTms_outputs));
        Rte_Inst_ME11.Task_100ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs->status = RTE_E_OK;
        rte_memcpy((uint8*)&Rte_Buf_Runbl_VcuRx_10ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs, (uint8*)&value, sizeof(DT_Bcm2VcuTms_outputs));
        Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_100ms_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT(DT_IPM_BMS_5_BatTemp_EPT value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Task_100ms_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT, (uint8*)&value, sizeof(DT_IPM_BMS_5_BatTemp_EPT));
        Rte_Inst_ME11.Task_100ms_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT->status = RTE_E_OK;
        rte_memcpy((uint8*)&Rte_Buf_Runbl_VcuRx_10ms_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT, (uint8*)&value, sizeof(DT_IPM_BMS_5_BatTemp_EPT));
        Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_100ms_IPM_BMS_9_BattInfo_EPT_IPM_BMS_9_BattInfo_EPT(DT_IPM_BMS_9_BattInfo_EPT value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_VcuRx_10ms_IPM_BMS_9_BattInfo_EPT_IPM_BMS_9_BattInfo_EPT, (uint8*)&value, sizeof(DT_IPM_BMS_9_BattInfo_EPT));
        Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_BMS_9_BattInfo_EPT_IPM_BMS_9_BattInfo_EPT->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_100ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD(DT_IPM_COMP_AC_BOD value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Task_100ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD, (uint8*)&value, sizeof(DT_IPM_COMP_AC_BOD));
        Rte_Inst_ME11.Task_100ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD->status = RTE_E_OK;
        rte_memcpy((uint8*)&Rte_Buf_Runbl_VCU_20ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD, (uint8*)&value, sizeof(DT_IPM_COMP_AC_BOD));
        Rte_Inst_AppSwcVcu.Runbl_VCU_20ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_100ms_IPM_FCM_A_CHA_IPM_FCM_A_CHA(DT_IPM_FCM_A_CHA value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_AppSwcBcm_50ms_IPM_FCM_A_CHA_IPM_FCM_A_CHA, (uint8*)&value, sizeof(DT_IPM_FCM_A_CHA));
        Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_50ms_IPM_FCM_A_CHA_IPM_FCM_A_CHA->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC(DT_IPM_HU_B_BAC value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_AppSwcBcm_20ms_IPM_HU_B_BAC_IPM_HU_B_BAC, (uint8*)&value, sizeof(DT_IPM_HU_B_BAC));
        Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_IPM_HU_B_BAC_IPM_HU_B_BAC->status = RTE_E_OK;
        rte_memcpy((uint8*)&Rte_Buf_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC, (uint8*)&value, sizeof(DT_IPM_HU_B_BAC));
        Rte_Inst_ME11.Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC->status = RTE_E_OK;
        rte_memcpy((uint8*)&Rte_Buf_Runbl_VcuRx_10ms_IPM_HU_B_BAC_IPM_HU_B_BAC, (uint8*)&value, sizeof(DT_IPM_HU_B_BAC));
        Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_HU_B_BAC_IPM_HU_B_BAC->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD(DT_IPM_HVCH_Status1_BOD value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Task_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD, (uint8*)&value, sizeof(DT_IPM_HVCH_Status1_BOD));
        Rte_Inst_ME11.Task_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD(DT_IPM_HVCH_Status2_BOD value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Task_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD, (uint8*)&value, sizeof(DT_IPM_HVCH_Status2_BOD));
        Rte_Inst_ME11.Task_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_100ms_IPM_ICU_2_Odo_BAC_IPM_ICU_2_Odo_BAC(DT_IPM_ICU_2_Odo_BAC value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_VCU_20ms_IPM_ICU_2_Odo_BAC_IPM_ICU_2_Odo_BAC, (uint8*)&value, sizeof(DT_IPM_ICU_2_Odo_BAC));
        Rte_Inst_AppSwcVcu.Runbl_VCU_20ms_IPM_ICU_2_Odo_BAC_IPM_ICU_2_Odo_BAC->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_100ms_IPM_INV_IMMO_Req_EPT_IPM_INV_IMMO_Req_EPT(DT_IPM_INV_IMMO_Req_EPT value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_AppSwcBcm_50ms_IPM_INV_IMMO_Req_EPT_IPM_INV_IMMO_Req_EPT, (uint8*)&value, sizeof(DT_IPM_INV_IMMO_Req_EPT));
        Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_50ms_IPM_INV_IMMO_Req_EPT_IPM_INV_IMMO_Req_EPT->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_100ms_IPM_IPU_DCC_1_State_EPT_IPM_IPU_DCC_1_State_EPT(DT_IPM_IPU_DCC_1_State_EPT value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_VcuRx_10ms_IPM_IPU_DCC_1_State_EPT_IPM_IPU_DCC_1_State_EPT, (uint8*)&value, sizeof(DT_IPM_IPU_DCC_1_State_EPT));
        Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_IPU_DCC_1_State_EPT_IPM_IPU_DCC_1_State_EPT->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_100ms_IPM_IPU_DCC_2_ChrgInValue_EPT_IPM_IPU_DCC_2_ChrgInValue_EPT(DT_IPM_IPU_DCC_2_ChrgInValue_EPT value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_VCU_20ms_IPM_IPU_DCC_2_ChrgInValue_EPT_IPM_IPU_DCC_2_ChrgInValue_EPT, (uint8*)&value, sizeof(DT_IPM_IPU_DCC_2_ChrgInValue_EPT));
        Rte_Inst_AppSwcVcu.Runbl_VCU_20ms_IPM_IPU_DCC_2_ChrgInValue_EPT_IPM_IPU_DCC_2_ChrgInValue_EPT->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_100ms_IPM_IPU_OBC_1_State_EPT_IPM_IPU_OBC_1_State_EPT(DT_IPM_IPU_OBC_1_State_EPT value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_VcuRx_10ms_IPM_IPU_OBC_1_State_EPT_IPM_IPU_OBC_1_State_EPT, (uint8*)&value, sizeof(DT_IPM_IPU_OBC_1_State_EPT));
        Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_IPU_OBC_1_State_EPT_IPM_IPU_OBC_1_State_EPT->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_100ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT(DT_IPM_IPU_OBC_2_Inlet_EPT value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Task_100ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT, (uint8*)&value, sizeof(DT_IPM_IPU_OBC_2_Inlet_EPT));
        Rte_Inst_ME11.Task_100ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT->status = RTE_E_OK;
        rte_memcpy((uint8*)&Rte_Buf_Runbl_VCU_20ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT, (uint8*)&value, sizeof(DT_IPM_IPU_OBC_2_Inlet_EPT));
        Rte_Inst_AppSwcVcu.Runbl_VCU_20ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_100ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC(DT_IPM_TBOX_BJS_Time_BAC value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_AppSwcBcm_100ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC, (uint8*)&value, sizeof(DT_IPM_TBOX_BJS_Time_BAC));
        Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_100ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC->status = RTE_E_OK;
        rte_memcpy((uint8*)&Rte_Buf_Task_100ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC, (uint8*)&value, sizeof(DT_IPM_TBOX_BJS_Time_BAC));
        Rte_Inst_ME11.Task_100ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC->status = RTE_E_OK;
        rte_memcpy((uint8*)&Rte_Buf_Runbl_VCU_20ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC, (uint8*)&value, sizeof(DT_IPM_TBOX_BJS_Time_BAC));
        Rte_Inst_AppSwcVcu.Runbl_VCU_20ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_10ms_IPM_EHB_B_CHA_IPM_EHB_B_CHA(DT_IPM_EHB_B_CHA value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_AppSwcBcm_50ms_IPM_EHB_B_CHA_IPM_EHB_B_CHA, (uint8*)&value, sizeof(DT_IPM_EHB_B_CHA));
        Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_50ms_IPM_EHB_B_CHA_IPM_EHB_B_CHA->status = RTE_E_OK;
        rte_memcpy((uint8*)&Rte_Buf_Runbl_VcuRx_10ms_IPM_EHB_B_CHA_IPM_EHB_B_CHA, (uint8*)&value, sizeof(DT_IPM_EHB_B_CHA));
        Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_EHB_B_CHA_IPM_EHB_B_CHA->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_10ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA(DT_IPM_ESC_7_FuncStatus_CHA value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_AppSwcBcm_20ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA, (uint8*)&value, sizeof(DT_IPM_ESC_7_FuncStatus_CHA));
        Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA->status = RTE_E_OK;
        rte_memcpy((uint8*)&Rte_Buf_Task_100ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA, (uint8*)&value, sizeof(DT_IPM_ESC_7_FuncStatus_CHA));
        Rte_Inst_ME11.Task_100ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA->status = RTE_E_OK;
        rte_memcpy((uint8*)&Rte_Buf_Runbl_VcuRx_10ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA, (uint8*)&value, sizeof(DT_IPM_ESC_7_FuncStatus_CHA));
        Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_10ms_IPM_ESC_A_CHA_IPM_ESC_A_CHA(DT_IPM_ESC_A_CHA value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_VcuRx_10ms_IPM_ESC_A_CHA_IPM_ESC_A_CHA, (uint8*)&value, sizeof(DT_IPM_ESC_A_CHA));
        Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_ESC_A_CHA_IPM_ESC_A_CHA->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_10ms_IPM_INV_1_Value_EPT_IPM_INV_1_Value_EPT(DT_IPM_INV_1_Value_EPT value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_OpmCanTx_10ms_IPM_INV_1_Value_EPT_IPM_INV_1_Value_EPT, (uint8*)&value, sizeof(DT_IPM_INV_1_Value_EPT));
        Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_10ms_IPM_INV_1_Value_EPT_IPM_INV_1_Value_EPT->status = RTE_E_OK;
        rte_memcpy((uint8*)&Rte_Buf_Runbl_VcuRx_10ms_IPM_INV_1_Value_EPT_IPM_INV_1_Value_EPT, (uint8*)&value, sizeof(DT_IPM_INV_1_Value_EPT));
        Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_INV_1_Value_EPT_IPM_INV_1_Value_EPT->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_10ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT(DT_IPM_INV_2_Value_EPT value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Task_100ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT, (uint8*)&value, sizeof(DT_IPM_INV_2_Value_EPT));
        Rte_Inst_ME11.Task_100ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT->status = RTE_E_OK;
        rte_memcpy((uint8*)&Rte_Buf_Runbl_VcuRx_10ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT, (uint8*)&value, sizeof(DT_IPM_INV_2_Value_EPT));
        Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_10ms_IPM_INV_3_Value_EPT_IPM_INV_3_Value_EPT(DT_IPM_INV_3_Value_EPT value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_VcuRx_10ms_IPM_INV_3_Value_EPT_IPM_INV_3_Value_EPT, (uint8*)&value, sizeof(DT_IPM_INV_3_Value_EPT));
        Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_INV_3_Value_EPT_IPM_INV_3_Value_EPT->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_10ms_IPM_INV_4_Value_EPT_IPM_INV_4_Value_EPT(DT_IPM_INV_4_Value_EPT value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_VcuRx_10ms_IPM_INV_4_Value_EPT_IPM_INV_4_Value_EPT, (uint8*)&value, sizeof(DT_IPM_INV_4_Value_EPT));
        Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_INV_4_Value_EPT_IPM_INV_4_Value_EPT->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_20ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT(DT_IPM_BMS_10_DC_ChargeStates_EPT value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Task_100ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT, (uint8*)&value, sizeof(DT_IPM_BMS_10_DC_ChargeStates_EPT));
        Rte_Inst_ME11.Task_100ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT->status = RTE_E_OK;
        rte_memcpy((uint8*)&Rte_Buf_Runbl_VcuRx_10ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT, (uint8*)&value, sizeof(DT_IPM_BMS_10_DC_ChargeStates_EPT));
        Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_20ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT(DT_IPM_BMS_1_MainState_EPT value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_AppSwcBcm_50ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT, (uint8*)&value, sizeof(DT_IPM_BMS_1_MainState_EPT));
        Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_50ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT->status = RTE_E_OK;
        rte_memcpy((uint8*)&Rte_Buf_Runbl_VcuRx_10ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT, (uint8*)&value, sizeof(DT_IPM_BMS_1_MainState_EPT));
        Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_20ms_IPM_BMS_2_BatState_EPT_IPM_BMS_2_BatState_EPT(DT_IPM_BMS_2_BatState_EPT value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Task_100ms_IPM_BMS_2_BatState_EPT_IPM_BMS_2_BatState_EPT, (uint8*)&value, sizeof(DT_IPM_BMS_2_BatState_EPT));
        Rte_Inst_ME11.Task_100ms_IPM_BMS_2_BatState_EPT_IPM_BMS_2_BatState_EPT->status = RTE_E_OK;
        rte_memcpy((uint8*)&Rte_Buf_Runbl_VcuRx_10ms_IPM_BMS_2_BatState_EPT_IPM_BMS_2_BatState_EPT, (uint8*)&value, sizeof(DT_IPM_BMS_2_BatState_EPT));
        Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_BMS_2_BatState_EPT_IPM_BMS_2_BatState_EPT->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_20ms_IPM_BMS_3_DC_ChargeState_EPT_IPM_BMS_3_DC_ChargeState_EPT(DT_IPM_BMS_3_DC_ChargeState_EPT value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_VCU_20ms_IPM_BMS_3_DC_ChargeState_EPT_IPM_BMS_3_DC_ChargeState_EPT, (uint8*)&value, sizeof(DT_IPM_BMS_3_DC_ChargeState_EPT));
        Rte_Inst_AppSwcVcu.Runbl_VCU_20ms_IPM_BMS_3_DC_ChargeState_EPT_IPM_BMS_3_DC_ChargeState_EPT->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_20ms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT(DT_IPM_BMS_4_AC_ChargeState_EPT value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Task_100ms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT, (uint8*)&value, sizeof(DT_IPM_BMS_4_AC_ChargeState_EPT));
        Rte_Inst_ME11.Task_100ms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT->status = RTE_E_OK;
        rte_memcpy((uint8*)&Rte_Buf_Runbl_VCU_20ms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT, (uint8*)&value, sizeof(DT_IPM_BMS_4_AC_ChargeState_EPT));
        Rte_Inst_AppSwcVcu.Runbl_VCU_20ms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_20ms_IPM_BMS_6_DischrgRecup_EPT_IPM_BMS_6_DischrgRecup_EPT(DT_IPM_BMS_6_DischrgRecup_EPT value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_VcuRx_10ms_IPM_BMS_6_DischrgRecup_EPT_IPM_BMS_6_DischrgRecup_EPT, (uint8*)&value, sizeof(DT_IPM_BMS_6_DischrgRecup_EPT));
        Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_BMS_6_DischrgRecup_EPT_IPM_BMS_6_DischrgRecup_EPT->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_20ms_IPM_BMS_7_CellVolt_EPT_IPM_BMS_7_CellVolt_EPT(DT_IPM_BMS_7_CellVolt_EPT value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_VCU_20ms_IPM_BMS_7_CellVolt_EPT_IPM_BMS_7_CellVolt_EPT, (uint8*)&value, sizeof(DT_IPM_BMS_7_CellVolt_EPT));
        Rte_Inst_AppSwcVcu.Runbl_VCU_20ms_IPM_BMS_7_CellVolt_EPT_IPM_BMS_7_CellVolt_EPT->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA(DT_IPM_CRRR_A_CHA value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_AppSwcBcm_50ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA, (uint8*)&value, sizeof(DT_IPM_CRRR_A_CHA));
        Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_50ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_20ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA(DT_IPM_EHB_A_CHA value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_AppSwcBcm_50ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA, (uint8*)&value, sizeof(DT_IPM_EHB_A_CHA));
        Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_50ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA->status = RTE_E_OK;
        rte_memcpy((uint8*)&Rte_Buf_Runbl_VCU_10ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA, (uint8*)&value, sizeof(DT_IPM_EHB_A_CHA));
        Rte_Inst_AppSwcVcu.Runbl_VCU_10ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_20ms_IPM_FCM_B_CHA_IPM_FCM_B_CHA(DT_IPM_FCM_B_CHA value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_OpmCanTx_10ms_IPM_FCM_B_CHA_IPM_FCM_B_CHA, (uint8*)&value, sizeof(DT_IPM_FCM_B_CHA));
        Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_10ms_IPM_FCM_B_CHA_IPM_FCM_B_CHA->status = RTE_E_OK;
        rte_memcpy((uint8*)&Rte_Buf_Runbl_VcuRx_10ms_IPM_FCM_B_CHA_IPM_FCM_B_CHA, (uint8*)&value, sizeof(DT_IPM_FCM_B_CHA));
        Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_FCM_B_CHA_IPM_FCM_B_CHA->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_20ms_IPM_SCS_RiSwitchSts_BOD_IPM_SCS_RiSwitchSts_BOD(DT_IPM_SCS_RiSwitchSts_BOD value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_VcuRx_10ms_IPM_SCS_RiSwitchSts_BOD_IPM_SCS_RiSwitchSts_BOD, (uint8*)&value, sizeof(DT_IPM_SCS_RiSwitchSts_BOD));
        Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_SCS_RiSwitchSts_BOD_IPM_SCS_RiSwitchSts_BOD->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_50ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD(DT_IPM_CCP_PanelStatus_BOD value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_AppSwcBcm_20ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD, (uint8*)&value, sizeof(DT_IPM_CCP_PanelStatus_BOD));
        Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD->status = RTE_E_OK;
        rte_memcpy((uint8*)&Rte_Buf_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD, (uint8*)&value, sizeof(DT_IPM_CCP_PanelStatus_BOD));
        Rte_Inst_ME11.Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD->status = RTE_E_OK;
        rte_memcpy((uint8*)&Rte_Buf_Runbl_VCU_10ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD, (uint8*)&value, sizeof(DT_IPM_CCP_PanelStatus_BOD));
        Rte_Inst_AppSwcVcu.Runbl_VCU_10ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_50ms_IPM_ESCL_ESCLStatus_BOD_IPM_ESCL_ESCLStatus_BOD(DT_IPM_ESCL_ESCLStatus_BOD value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_AppSwcBcm_50ms_IPM_ESCL_ESCLStatus_BOD_IPM_ESCL_ESCLStatus_BOD, (uint8*)&value, sizeof(DT_IPM_ESCL_ESCLStatus_BOD));
        Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_50ms_IPM_ESCL_ESCLStatus_BOD_IPM_ESCL_ESCLStatus_BOD->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_50ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD(DT_IPM_SCS_LeSwitchSts_BOD value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD, (uint8*)&value, sizeof(DT_IPM_SCS_LeSwitchSts_BOD));
        Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_50ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA(DT_IPM_SRS_1_Status_CHA value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_AppSwcBcm_50ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA, (uint8*)&value, sizeof(DT_IPM_SRS_1_Status_CHA));
        Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_50ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA->status = RTE_E_OK;
        rte_memcpy((uint8*)&Rte_Buf_Runbl_VcuRx_10ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA, (uint8*)&value, sizeof(DT_IPM_SRS_1_Status_CHA));
        Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_IpmMsgActv_10ms_CANCommCRCFlt_outputs_CANCommCRCFlt_outputs(DT_CANCommCRCFlt value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_VCU_20ms_CANCommCRCFlt_outputs_CANCommCRCFlt_outputs, (uint8*)&value, sizeof(DT_CANCommCRCFlt));
        Rte_Inst_AppSwcVcu.Runbl_VCU_20ms_CANCommCRCFlt_outputs_CANCommCRCFlt_outputs->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_IpmMsgActv_10ms_CANCommErr_outputs_CANCommErr_outputs(DT_CANCommErr value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_VcuRx_10ms_CANCommErr_outputs_CANCommErr_outputs, (uint8*)&value, sizeof(DT_CANCommErr));
        Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_CANCommErr_outputs_CANCommErr_outputs->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_IpmMsgActv_10ms_MsgActv_outputs_MsgActv_outputs(DT_MsgActv value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_VcuRx_10ms_MsgActv_outputs_MsgActv_outputs, (uint8*)&value, sizeof(DT_MsgActv));
        Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_MsgActv_outputs_MsgActv_outputs->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_VcuTx_10ms_DAG_Comm_outputs_DAG_Comm_outputs(DAG_Comm_outputs value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs, (uint8*)&value, sizeof(DAG_Comm_outputs));
        Rte_Inst_AppSwcIpm.Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_VcuTx_10ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs(DT_Vcu2BcmTms_outputs value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_AppSwcBcm_20ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs, (uint8*)&value, sizeof(DT_Vcu2BcmTms_outputs));
        Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs->status = RTE_E_OK;
        rte_memcpy((uint8*)&Rte_Buf_Task_100ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs, (uint8*)&value, sizeof(DT_Vcu2BcmTms_outputs));
        Rte_Inst_ME11.Task_100ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_VcuTx_10ms_Vcu2OpmBAC_outputs_Vcu2OpmBAC_outputs(DT_Vcu2OpmBAC_outputs value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_OpmRx_10ms_Vcu2OpmBAC_outputs_Vcu2OpmBAC_outputs, (uint8*)&value, sizeof(DT_Vcu2OpmBAC_outputs));
        Rte_Inst_AppSwcOpm.Runbl_OpmRx_10ms_Vcu2OpmBAC_outputs_Vcu2OpmBAC_outputs->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_VcuTx_10ms_Vcu2OpmCHA_outputs_Vcu2OpmCHA_outputs(DT_Vcu2OpmCHA_outputs value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_OpmRx_10ms_Vcu2OpmCHA_outputs_Vcu2OpmCHA_outputs, (uint8*)&value, sizeof(DT_Vcu2OpmCHA_outputs));
        Rte_Inst_AppSwcOpm.Runbl_OpmRx_10ms_Vcu2OpmCHA_outputs_Vcu2OpmCHA_outputs->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Runbl_VcuTx_10ms_Vcu2OpmEPT_outputs_Vcu2OpmEPT_outputs(DT_Vcu2OpmEPT_outputs value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_OpmRx_10ms_Vcu2OpmEPT_outputs_Vcu2OpmEPT_outputs, (uint8*)&value, sizeof(DT_Vcu2OpmEPT_outputs));
        Rte_Inst_AppSwcOpm.Runbl_OpmRx_10ms_Vcu2OpmEPT_outputs_Vcu2OpmEPT_outputs->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Task_100ms_TMS2VCU_AC_1_Command_Outputs_TMS2VCU_AC_1_Command_Outputs(TMS2VCU_AC_1_Command_Outputs value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_OpmCanTx_100ms_TMS2VCU_AC_1_Command_Outputs_TMS2VCU_AC_1_Command_Outputs, (uint8*)&value, sizeof(TMS2VCU_AC_1_Command_Outputs));
        Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_TMS2VCU_AC_1_Command_Outputs_TMS2VCU_AC_1_Command_Outputs->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Task_100ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs(TMS2VCU_AC_2_State_Outputs value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_OpmCanTx_100ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs, (uint8*)&value, sizeof(TMS2VCU_AC_2_State_Outputs));
        Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs->status = RTE_E_OK;
        rte_memcpy((uint8*)&Rte_Buf_Runbl_VcuRx_10ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs, (uint8*)&value, sizeof(TMS2VCU_AC_2_State_Outputs));
        Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Task_100ms_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs(TMS2VCU_AC_3_State_Outputs value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_OpmCanTx_100ms_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs, (uint8*)&value, sizeof(TMS2VCU_AC_3_State_Outputs));
        Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs->status = RTE_E_OK;
        rte_memcpy((uint8*)&Rte_Buf_Runbl_VCU_100ms_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs, (uint8*)&value, sizeof(TMS2VCU_AC_3_State_Outputs));
        Rte_Inst_AppSwcVcu.Runbl_VCU_100ms_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Task_100ms_TMS2VCU_AC_8_status_Outputs_TMS2VCU_AC_8_status_Outputs(TMS2VCU_AC_8_status_Outputs value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_OpmCanTx_100ms_TMS2VCU_AC_8_status_Outputs_TMS2VCU_AC_8_status_Outputs, (uint8*)&value, sizeof(TMS2VCU_AC_8_status_Outputs));
        Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_TMS2VCU_AC_8_status_Outputs_TMS2VCU_AC_8_status_Outputs->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Task_100ms_TMS2VCU_AC_ACStatuts_Outputs_TMS2VCU_AC_ACStatuts_Outputs(TMS2VCU_AC_ACStatuts_Outputs value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_OpmCanTx_100ms_TMS2VCU_AC_ACStatuts_Outputs_TMS2VCU_AC_ACStatuts_Outputs, (uint8*)&value, sizeof(TMS2VCU_AC_ACStatuts_Outputs));
        Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_TMS2VCU_AC_ACStatuts_Outputs_TMS2VCU_AC_ACStatuts_Outputs->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Task_100ms_TMS2VCU_AC_COMP_Outputs_TMS2VCU_AC_COMP_Outputs(TMS2VCU_AC_COMP_Outputs value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_OpmCanTx_100ms_TMS2VCU_AC_COMP_Outputs_TMS2VCU_AC_COMP_Outputs, (uint8*)&value, sizeof(TMS2VCU_AC_COMP_Outputs));
        Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_TMS2VCU_AC_COMP_Outputs_TMS2VCU_AC_COMP_Outputs->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Task_100ms_TMS2VCU_HVCH_Command_Outputs_TMS2VCU_HVCH_Command_Outputs(TMS2VCU_HVCH_Command_Outputs value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_OpmCanTx_100ms_TMS2VCU_HVCH_Command_Outputs_TMS2VCU_HVCH_Command_Outputs, (uint8*)&value, sizeof(TMS2VCU_HVCH_Command_Outputs));
        Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_TMS2VCU_HVCH_Command_Outputs_TMS2VCU_HVCH_Command_Outputs->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Task_100ms_TMS2VCU_PPV_outputs_TMS2VCU_PPV_outputs(TMS2VCU_PPVAddSignalGroup_Outputs value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_OpmRx_10ms_TMS2VCU_PPV_outputs_TMS2VCU_PPV_outputs, (uint8*)&value, sizeof(TMS2VCU_PPVAddSignalGroup_Outputs));
        Rte_Inst_AppSwcOpm.Runbl_OpmRx_10ms_TMS2VCU_PPV_outputs_TMS2VCU_PPV_outputs->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Task_100ms_TMS2VCU_TMS_LINTestData1_Outputs_TMS2VCU_TMS_LINTestData1_Outputs(TMS2VCU_TMS_LINTestData1_Outputs value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData1_Outputs_TMS2VCU_TMS_LINTestData1_Outputs, (uint8*)&value, sizeof(TMS2VCU_TMS_LINTestData1_Outputs));
        Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData1_Outputs_TMS2VCU_TMS_LINTestData1_Outputs->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Task_100ms_TMS2VCU_TMS_LINTestData2_Outputs_TMS2VCU_TMS_LINTestData2_Outputs(TMS2VCU_TMS_LINTestData2_Outputs value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData2_Outputs_TMS2VCU_TMS_LINTestData2_Outputs, (uint8*)&value, sizeof(TMS2VCU_TMS_LINTestData2_Outputs));
        Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData2_Outputs_TMS2VCU_TMS_LINTestData2_Outputs->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Task_100ms_TMS2VCU_TMS_LINTestData3_Outputs_TMS2VCU_TMS_LINTestData3_Outputs(TMS2VCU_TMS_LINTestData3_Outputs value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData3_Outputs_TMS2VCU_TMS_LINTestData3_Outputs, (uint8*)&value, sizeof(TMS2VCU_TMS_LINTestData3_Outputs));
        Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData3_Outputs_TMS2VCU_TMS_LINTestData3_Outputs->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Rte_WriteBuffer_Rte_Buf_Task_100ms_Tms2Vcu_Info_Tms2Vcu_Info(Tms2Vcu_Info value)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Rte_Buf_Runbl_VcuRx_10ms_Tms2Vcu_Info_Tms2Vcu_Info, (uint8*)&value, sizeof(Tms2Vcu_Info));
        Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_Tms2Vcu_Info_Tms2Vcu_Info->status = RTE_E_OK;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

