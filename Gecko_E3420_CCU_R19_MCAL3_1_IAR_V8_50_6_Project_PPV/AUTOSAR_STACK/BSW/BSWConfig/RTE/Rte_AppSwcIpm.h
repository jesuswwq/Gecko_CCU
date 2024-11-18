/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_AppSwcIpm.h>
 *  @brief      <>
 *  
 *  <MCU:E3420>
 *  
 *  @author     <>
 *  @date       <2024-11-13 17:39:59>
 */
/*============================================================================*/

/* Rte_AppSwcIpm.h */

#ifndef RTE_APPSWCIPM_H
#define RTE_APPSWCIPM_H

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
#include "Rte_AppSwcIpm_Type.h"

/*******************************************************************************
 **                        Macro Definitions                                  **
******************************************************************************/

typedef struct
{
    P2VAR(Rte_DE_ACCM_Version_BOD_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_100ms_ACCM_Version_BOD_ACCM_Version_BOD;
    P2VAR(Rte_DE_BMS_5_BatTemp_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_100ms_BMS_5_BatTemp_EPT_BMS_5_BatTemp_EPT;
    P2VAR(Rte_DE_BMS_9_BattInfo_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_100ms_BMS_9_BattInfo_EPT_BMS_9_BattInfo_EPT;
    P2VAR(Rte_DE_COMP_AC_BOD_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD;
    P2VAR(Rte_DE_HU_B_BAC_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC;
    P2VAR(Rte_DE_HVCH_Status1_BOD_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_100ms_HVCH_Status1_BOD_HVCH_Status1_BOD;
    P2VAR(Rte_DE_HVCH_Status2_BOD_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_100ms_HVCH_Status2_BOD_HVCH_Status2_BOD;
    P2VAR(Rte_DE_ICU_2_Odo_BAC_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_100ms_ICU_2_Odo_BAC_ICU_2_Odo_BAC;
    P2VAR(Rte_DE_INV_IMMO_Req_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_100ms_INV_IMMO_Req_EPT_INV_IMMO_Req_EPT;
    P2VAR(Rte_DE_IPU_DCC_1_State_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_100ms_IPU_DCC_1_State_EPT_IPU_DCC_1_State_EPT;
    P2VAR(Rte_DE_IPU_DCC_2_ChrgInValue_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_100ms_IPU_DCC_2_ChrgInValue_EPT_IPU_DCC_2_ChrgInValue_EPT;
    P2VAR(Rte_DE_IPU_OBC_1_State_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_100ms_IPU_OBC_1_State_EPT_IPU_OBC_1_State_EPT;
    P2VAR(Rte_DE_IPU_OBC_2_Inlet_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_100ms_IPU_OBC_2_Inlet_EPT_IPU_OBC_2_Inlet_EPT;
    P2VAR(Rte_DE_TBOX_BJS_Time_BAC_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_100ms_TBOX_BJS_Time_BAC_TBOX_BJS_Time_BAC;
    P2VAR(Rte_DE_EHB_B_CHA_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA;
    P2VAR(Rte_DE_EPS_2_StrWhlAng_CHA_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_10ms_EPS_2_StrWhlAng_CHA_EPS_2_StrWhlAng_CHA;
    P2VAR(Rte_DE_ESC_7_FuncStatus_CHA_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_10ms_ESC_7_FuncStatus_CHA_ESC_7_FuncStatus_CHA;
    P2VAR(Rte_DE_ESC_A_CHA_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA;
    P2VAR(Rte_DE_INV_1_Value_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_10ms_INV_1_Value_EPT_INV_1_Value_EPT;
    P2VAR(Rte_DE_INV_2_Value_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_10ms_INV_2_Value_EPT_INV_2_Value_EPT;
    P2VAR(Rte_DE_INV_3_Value_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_10ms_INV_3_Value_EPT_INV_3_Value_EPT;
    P2VAR(Rte_DE_INV_4_Value_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_10ms_INV_4_Value_EPT_INV_4_Value_EPT;
    P2VAR(Rte_DE_BMS_10_DC_ChargeStates_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_20ms_BMS_10_DC_ChargeStates_EPT_BMS_10_DC_ChargeStates_EPT;
    P2VAR(Rte_DE_BMS_1_MainState_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT;
    P2VAR(Rte_DE_BMS_2_BatState_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_20ms_BMS_2_BatState_EPT_BMS_2_BatState_EPT;
    P2VAR(Rte_DE_BMS_3_DC_ChargeState_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_20ms_BMS_3_DC_ChargeState_EPT_BMS_3_DC_ChargeState_EPT;
    P2VAR(Rte_DE_BMS_4_AC_ChargeState_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_20ms_BMS_4_AC_ChargeState_EPT_BMS_4_AC_ChargeState_EPT;
    P2VAR(Rte_DE_BMS_6_DischrgRecup_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_20ms_BMS_6_DischrgRecup_EPT_BMS_6_DischrgRecup_EPT;
    P2VAR(Rte_DE_BMS_7_CellVolt_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_20ms_BMS_7_CellVolt_EPT_BMS_7_CellVolt_EPT;
    P2VAR(Rte_DE_CRRR_A_CHA_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_20ms_CRRR_A_CHA_CRRR_A_CHA;
    P2VAR(Rte_DE_EHB_A_CHA_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA;
    P2VAR(Rte_DE_FCM_B_CHA_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA;
    P2VAR(Rte_DE_SCS_RiSwitchSts_BOD_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD;
    P2VAR(Rte_DE_CCP_PanelStatus_BOD_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD;
    P2VAR(Rte_DE_ESCL_ESCLStatus_BOD_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_50ms_ESCL_ESCLStatus_BOD_ESCL_ESCLStatus_BOD;
    P2VAR(Rte_DE_SCS_LeSwitchSts_BOD_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD;
    P2VAR(Rte_DE_SRS_1_Status_CHA_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA;
    P2VAR(Rte_DE_DAG_Comm_outputs_status, AUTOMATIC, RTE_DATA)  Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs;
    P2VAR(Rte_DE_DT_IPM_ACCM_Version_BOD_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_100ms_IPM_ACCM_Version_BOD_IPM_ACCM_Version_BOD;
    P2VAR(Rte_DE_DT_IPM_BMS_5_BatTemp_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_100ms_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT;
    P2VAR(Rte_DE_DT_IPM_BMS_9_BattInfo_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_100ms_IPM_BMS_9_BattInfo_EPT_IPM_BMS_9_BattInfo_EPT;
    P2VAR(Rte_DE_DT_IPM_COMP_AC_BOD_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_100ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD;
    P2VAR(Rte_DE_DT_IPM_HU_B_BAC_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC;
    P2VAR(Rte_DE_DT_IPM_HVCH_Status1_BOD_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD;
    P2VAR(Rte_DE_DT_IPM_HVCH_Status2_BOD_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD;
    P2VAR(Rte_DE_DT_IPM_ICU_2_Odo_BAC_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_100ms_IPM_ICU_2_Odo_BAC_IPM_ICU_2_Odo_BAC;
    P2VAR(Rte_DE_DT_IPM_INV_IMMO_Req_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_100ms_IPM_INV_IMMO_Req_EPT_IPM_INV_IMMO_Req_EPT;
    P2VAR(Rte_DE_DT_IPM_IPU_DCC_1_State_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_100ms_IPM_IPU_DCC_1_State_EPT_IPM_IPU_DCC_1_State_EPT;
    P2VAR(Rte_DE_DT_IPM_IPU_DCC_2_ChrgInValue_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_100ms_IPM_IPU_DCC_2_ChrgInValue_EPT_IPM_IPU_DCC_2_ChrgInValue_EPT;
    P2VAR(Rte_DE_DT_IPM_IPU_OBC_1_State_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_100ms_IPM_IPU_OBC_1_State_EPT_IPM_IPU_OBC_1_State_EPT;
    P2VAR(Rte_DE_DT_IPM_IPU_OBC_2_Inlet_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_100ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT;
    P2VAR(Rte_DE_DT_IPM_TBOX_BJS_Time_BAC_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_100ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC;
    P2VAR(Rte_DE_DT_IPM_EHB_B_CHA_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_10ms_IPM_EHB_B_CHA_IPM_EHB_B_CHA;
    P2VAR(Rte_DE_DT_IPM_EPS_2_StrWhlAng_CHA_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_10ms_IPM_EPS_2_StrWhlAng_CHA_IPM_EPS_2_StrWhlAng_CHA;
    P2VAR(Rte_DE_DT_IPM_ESC_7_FuncStatus_CHA_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_10ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA;
    P2VAR(Rte_DE_DT_IPM_ESC_A_CHA_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_10ms_IPM_ESC_A_CHA_IPM_ESC_A_CHA;
    P2VAR(Rte_DE_DT_IPM_INV_1_Value_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_10ms_IPM_INV_1_Value_EPT_IPM_INV_1_Value_EPT;
    P2VAR(Rte_DE_DT_IPM_INV_2_Value_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_10ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT;
    P2VAR(Rte_DE_DT_IPM_INV_3_Value_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_10ms_IPM_INV_3_Value_EPT_IPM_INV_3_Value_EPT;
    P2VAR(Rte_DE_DT_IPM_INV_4_Value_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_10ms_IPM_INV_4_Value_EPT_IPM_INV_4_Value_EPT;
    P2VAR(Rte_DE_DT_IPM_BMS_10_DC_ChargeStates_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_20ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT;
    P2VAR(Rte_DE_DT_IPM_BMS_1_MainState_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_20ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT;
    P2VAR(Rte_DE_DT_IPM_BMS_2_BatState_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_20ms_IPM_BMS_2_BatState_EPT_IPM_BMS_2_BatState_EPT;
    P2VAR(Rte_DE_DT_IPM_BMS_3_DC_ChargeState_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_20ms_IPM_BMS_3_DC_ChargeState_EPT_IPM_BMS_3_DC_ChargeState_EPT;
    P2VAR(Rte_DE_DT_IPM_BMS_4_AC_ChargeState_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_20ms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT;
    P2VAR(Rte_DE_DT_IPM_BMS_6_DischrgRecup_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_20ms_IPM_BMS_6_DischrgRecup_EPT_IPM_BMS_6_DischrgRecup_EPT;
    P2VAR(Rte_DE_DT_IPM_BMS_7_CellVolt_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_20ms_IPM_BMS_7_CellVolt_EPT_IPM_BMS_7_CellVolt_EPT;
    P2VAR(Rte_DE_DT_IPM_CRRR_A_CHA_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA;
    P2VAR(Rte_DE_DT_IPM_EHB_A_CHA_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_20ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA;
    P2VAR(Rte_DE_DT_IPM_FCM_B_CHA_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_20ms_IPM_FCM_B_CHA_IPM_FCM_B_CHA;
    P2VAR(Rte_DE_DT_IPM_SCS_RiSwitchSts_BOD_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_20ms_IPM_SCS_RiSwitchSts_BOD_IPM_SCS_RiSwitchSts_BOD;
    P2VAR(Rte_DE_DT_IPM_CCP_PanelStatus_BOD_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_50ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD;
    P2VAR(Rte_DE_DT_IPM_ESCL_ESCLStatus_BOD_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_50ms_IPM_ESCL_ESCLStatus_BOD_IPM_ESCL_ESCLStatus_BOD;
    P2VAR(Rte_DE_DT_IPM_SCS_LeSwitchSts_BOD_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_50ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD;
    P2VAR(Rte_DE_DT_IPM_SRS_1_Status_CHA_status, AUTOMATIC, RTE_DATA)  Runbl_IpmCanRx_50ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA;
    P2VAR(Rte_DE_DT_CANCommCRCFlt_status, AUTOMATIC, RTE_DATA)  Runbl_IpmMsgActv_10ms_CANCommCRCFlt_outputs_CANCommCRCFlt_outputs;
    P2VAR(Rte_DE_DT_CANCommErr_status, AUTOMATIC, RTE_DATA)  Runbl_IpmMsgActv_10ms_CANCommErr_outputs_CANCommErr_outputs;
    P2VAR(Rte_DE_DT_MsgActv_status, AUTOMATIC, RTE_DATA)  Runbl_IpmMsgActv_10ms_MsgActv_outputs_MsgActv_outputs;
} Rte_CDS_AppSwcIpm;

extern CONST(Rte_CDS_AppSwcIpm, RTE_CONST) Rte_Inst_AppSwcIpm;

#ifndef RTE_CORE
typedef CONSTP2CONST(Rte_CDS_AppSwcIpm, AUTOMATIC, RTE_CONST) Rte_Instance;
#endif

/** API mappings */

#ifndef RTE_CORE

#define Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV

#define Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV

#define Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV

#define Rte_IrvIRead_Runbl_IpmCanRx_50ms_CANCommCRCFlt_outputsIRV Rte_IrvIRead_Runbl_IpmCanRx_50ms_CANCommCRCFlt_outputsIRV

#define Rte_IrvIWrite_Runbl_IpmMsgActv_10ms_CANCommCRCFlt_outputsIRV Rte_IrvIWrite_Runbl_IpmMsgActv_10ms_CANCommCRCFlt_outputsIRV

#define Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV

#define Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV

#define Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV

#define Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV

#define Rte_IrvIWrite_Runbl_IpmMsgActv_10ms_MsgActv_outputsIRV Rte_IrvIWrite_Runbl_IpmMsgActv_10ms_MsgActv_outputsIRV

#define Rte_IRead_Runbl_IpmCanRx_100ms_ACCM_Version_BOD_ACCM_Version_BOD() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_ACCM_Version_BOD_ACCM_Version_BOD->value)

#define Rte_IRead_Runbl_IpmCanRx_100ms_BMS_5_BatTemp_EPT_BMS_5_BatTemp_EPT() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_BMS_5_BatTemp_EPT_BMS_5_BatTemp_EPT->value)

#define Rte_IRead_Runbl_IpmCanRx_100ms_BMS_9_BattInfo_EPT_BMS_9_BattInfo_EPT() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_BMS_9_BattInfo_EPT_BMS_9_BattInfo_EPT->value)

#define Rte_IRead_Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD->value)

#define Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC->value)

#define Rte_IRead_Runbl_IpmCanRx_100ms_HVCH_Status1_BOD_HVCH_Status1_BOD() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_HVCH_Status1_BOD_HVCH_Status1_BOD->value)

#define Rte_IRead_Runbl_IpmCanRx_100ms_HVCH_Status2_BOD_HVCH_Status2_BOD() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_HVCH_Status2_BOD_HVCH_Status2_BOD->value)

#define Rte_IRead_Runbl_IpmCanRx_100ms_ICU_2_Odo_BAC_ICU_2_Odo_BAC() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_ICU_2_Odo_BAC_ICU_2_Odo_BAC->value)

#define Rte_IRead_Runbl_IpmCanRx_100ms_INV_IMMO_Req_EPT_INV_IMMO_Req_EPT() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_INV_IMMO_Req_EPT_INV_IMMO_Req_EPT->value)

#define Rte_IRead_Runbl_IpmCanRx_100ms_IPU_DCC_1_State_EPT_IPU_DCC_1_State_EPT() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPU_DCC_1_State_EPT_IPU_DCC_1_State_EPT->value)

#define Rte_IRead_Runbl_IpmCanRx_100ms_IPU_DCC_2_ChrgInValue_EPT_IPU_DCC_2_ChrgInValue_EPT() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPU_DCC_2_ChrgInValue_EPT_IPU_DCC_2_ChrgInValue_EPT->value)

#define Rte_IRead_Runbl_IpmCanRx_100ms_IPU_OBC_1_State_EPT_IPU_OBC_1_State_EPT() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPU_OBC_1_State_EPT_IPU_OBC_1_State_EPT->value)

#define Rte_IRead_Runbl_IpmCanRx_100ms_IPU_OBC_2_Inlet_EPT_IPU_OBC_2_Inlet_EPT() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPU_OBC_2_Inlet_EPT_IPU_OBC_2_Inlet_EPT->value)

#define Rte_IRead_Runbl_IpmCanRx_100ms_TBOX_BJS_Time_BAC_TBOX_BJS_Time_BAC() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_TBOX_BJS_Time_BAC_TBOX_BJS_Time_BAC->value)

#define Rte_IWrite_Runbl_IpmCanRx_100ms_IPM_ACCM_Version_BOD_IPM_ACCM_Version_BOD(data) (Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPM_ACCM_Version_BOD_IPM_ACCM_Version_BOD->value = *(data))

#define Rte_IWriteRef_Runbl_IpmCanRx_100ms_IPM_ACCM_Version_BOD_IPM_ACCM_Version_BOD() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPM_ACCM_Version_BOD_IPM_ACCM_Version_BOD->value)

#define Rte_IWrite_Runbl_IpmCanRx_100ms_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT(data) (Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT->value = *(data))

#define Rte_IWriteRef_Runbl_IpmCanRx_100ms_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT->value)

#define Rte_IWrite_Runbl_IpmCanRx_100ms_IPM_BMS_9_BattInfo_EPT_IPM_BMS_9_BattInfo_EPT(data) (Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPM_BMS_9_BattInfo_EPT_IPM_BMS_9_BattInfo_EPT->value = *(data))

#define Rte_IWriteRef_Runbl_IpmCanRx_100ms_IPM_BMS_9_BattInfo_EPT_IPM_BMS_9_BattInfo_EPT() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPM_BMS_9_BattInfo_EPT_IPM_BMS_9_BattInfo_EPT->value)

#define Rte_IWrite_Runbl_IpmCanRx_100ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD(data) (Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD->value = *(data))

#define Rte_IWriteRef_Runbl_IpmCanRx_100ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD->value)

#define Rte_IWrite_Runbl_IpmCanRx_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC(data) (Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC->value = *(data))

#define Rte_IWriteRef_Runbl_IpmCanRx_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC->value)

#define Rte_IWrite_Runbl_IpmCanRx_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD(data) (Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD->value = *(data))

#define Rte_IWriteRef_Runbl_IpmCanRx_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD->value)

#define Rte_IWrite_Runbl_IpmCanRx_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD(data) (Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD->value = *(data))

#define Rte_IWriteRef_Runbl_IpmCanRx_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD->value)

#define Rte_IWrite_Runbl_IpmCanRx_100ms_IPM_ICU_2_Odo_BAC_IPM_ICU_2_Odo_BAC(data) (Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPM_ICU_2_Odo_BAC_IPM_ICU_2_Odo_BAC->value = *(data))

#define Rte_IWriteRef_Runbl_IpmCanRx_100ms_IPM_ICU_2_Odo_BAC_IPM_ICU_2_Odo_BAC() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPM_ICU_2_Odo_BAC_IPM_ICU_2_Odo_BAC->value)

#define Rte_IWrite_Runbl_IpmCanRx_100ms_IPM_INV_IMMO_Req_EPT_IPM_INV_IMMO_Req_EPT(data) (Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPM_INV_IMMO_Req_EPT_IPM_INV_IMMO_Req_EPT->value = *(data))

#define Rte_IWriteRef_Runbl_IpmCanRx_100ms_IPM_INV_IMMO_Req_EPT_IPM_INV_IMMO_Req_EPT() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPM_INV_IMMO_Req_EPT_IPM_INV_IMMO_Req_EPT->value)

#define Rte_IWrite_Runbl_IpmCanRx_100ms_IPM_IPU_DCC_1_State_EPT_IPM_IPU_DCC_1_State_EPT(data) (Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPM_IPU_DCC_1_State_EPT_IPM_IPU_DCC_1_State_EPT->value = *(data))

#define Rte_IWriteRef_Runbl_IpmCanRx_100ms_IPM_IPU_DCC_1_State_EPT_IPM_IPU_DCC_1_State_EPT() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPM_IPU_DCC_1_State_EPT_IPM_IPU_DCC_1_State_EPT->value)

#define Rte_IWrite_Runbl_IpmCanRx_100ms_IPM_IPU_DCC_2_ChrgInValue_EPT_IPM_IPU_DCC_2_ChrgInValue_EPT(data) (Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPM_IPU_DCC_2_ChrgInValue_EPT_IPM_IPU_DCC_2_ChrgInValue_EPT->value = *(data))

#define Rte_IWriteRef_Runbl_IpmCanRx_100ms_IPM_IPU_DCC_2_ChrgInValue_EPT_IPM_IPU_DCC_2_ChrgInValue_EPT() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPM_IPU_DCC_2_ChrgInValue_EPT_IPM_IPU_DCC_2_ChrgInValue_EPT->value)

#define Rte_IWrite_Runbl_IpmCanRx_100ms_IPM_IPU_OBC_1_State_EPT_IPM_IPU_OBC_1_State_EPT(data) (Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPM_IPU_OBC_1_State_EPT_IPM_IPU_OBC_1_State_EPT->value = *(data))

#define Rte_IWriteRef_Runbl_IpmCanRx_100ms_IPM_IPU_OBC_1_State_EPT_IPM_IPU_OBC_1_State_EPT() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPM_IPU_OBC_1_State_EPT_IPM_IPU_OBC_1_State_EPT->value)

#define Rte_IWrite_Runbl_IpmCanRx_100ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT(data) (Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT->value = *(data))

#define Rte_IWriteRef_Runbl_IpmCanRx_100ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT->value)

#define Rte_IWrite_Runbl_IpmCanRx_100ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC(data) (Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC->value = *(data))

#define Rte_IWriteRef_Runbl_IpmCanRx_100ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC->value)

#define Rte_IRead_Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA->value)

#define Rte_IRead_Runbl_IpmCanRx_10ms_EPS_2_StrWhlAng_CHA_EPS_2_StrWhlAng_CHA() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_EPS_2_StrWhlAng_CHA_EPS_2_StrWhlAng_CHA->value)

#define Rte_IRead_Runbl_IpmCanRx_10ms_ESC_7_FuncStatus_CHA_ESC_7_FuncStatus_CHA() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_ESC_7_FuncStatus_CHA_ESC_7_FuncStatus_CHA->value)

#define Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA->value)

#define Rte_IRead_Runbl_IpmCanRx_10ms_INV_1_Value_EPT_INV_1_Value_EPT() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_INV_1_Value_EPT_INV_1_Value_EPT->value)

#define Rte_IRead_Runbl_IpmCanRx_10ms_INV_2_Value_EPT_INV_2_Value_EPT() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_INV_2_Value_EPT_INV_2_Value_EPT->value)

#define Rte_IRead_Runbl_IpmCanRx_10ms_INV_3_Value_EPT_INV_3_Value_EPT() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_INV_3_Value_EPT_INV_3_Value_EPT->value)

#define Rte_IRead_Runbl_IpmCanRx_10ms_INV_4_Value_EPT_INV_4_Value_EPT() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_INV_4_Value_EPT_INV_4_Value_EPT->value)

#define Rte_IWrite_Runbl_IpmCanRx_10ms_IPM_EHB_B_CHA_IPM_EHB_B_CHA(data) (Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_IPM_EHB_B_CHA_IPM_EHB_B_CHA->value = *(data))

#define Rte_IWriteRef_Runbl_IpmCanRx_10ms_IPM_EHB_B_CHA_IPM_EHB_B_CHA() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_IPM_EHB_B_CHA_IPM_EHB_B_CHA->value)

#define Rte_IWrite_Runbl_IpmCanRx_10ms_IPM_EPS_2_StrWhlAng_CHA_IPM_EPS_2_StrWhlAng_CHA(data) (Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_IPM_EPS_2_StrWhlAng_CHA_IPM_EPS_2_StrWhlAng_CHA->value = *(data))

#define Rte_IWriteRef_Runbl_IpmCanRx_10ms_IPM_EPS_2_StrWhlAng_CHA_IPM_EPS_2_StrWhlAng_CHA() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_IPM_EPS_2_StrWhlAng_CHA_IPM_EPS_2_StrWhlAng_CHA->value)

#define Rte_IWrite_Runbl_IpmCanRx_10ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA(data) (Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA->value = *(data))

#define Rte_IWriteRef_Runbl_IpmCanRx_10ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA->value)

#define Rte_IWrite_Runbl_IpmCanRx_10ms_IPM_ESC_A_CHA_IPM_ESC_A_CHA(data) (Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_IPM_ESC_A_CHA_IPM_ESC_A_CHA->value = *(data))

#define Rte_IWriteRef_Runbl_IpmCanRx_10ms_IPM_ESC_A_CHA_IPM_ESC_A_CHA() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_IPM_ESC_A_CHA_IPM_ESC_A_CHA->value)

#define Rte_IWrite_Runbl_IpmCanRx_10ms_IPM_INV_1_Value_EPT_IPM_INV_1_Value_EPT(data) (Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_IPM_INV_1_Value_EPT_IPM_INV_1_Value_EPT->value = *(data))

#define Rte_IWriteRef_Runbl_IpmCanRx_10ms_IPM_INV_1_Value_EPT_IPM_INV_1_Value_EPT() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_IPM_INV_1_Value_EPT_IPM_INV_1_Value_EPT->value)

#define Rte_IWrite_Runbl_IpmCanRx_10ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT(data) (Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT->value = *(data))

#define Rte_IWriteRef_Runbl_IpmCanRx_10ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT->value)

#define Rte_IWrite_Runbl_IpmCanRx_10ms_IPM_INV_3_Value_EPT_IPM_INV_3_Value_EPT(data) (Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_IPM_INV_3_Value_EPT_IPM_INV_3_Value_EPT->value = *(data))

#define Rte_IWriteRef_Runbl_IpmCanRx_10ms_IPM_INV_3_Value_EPT_IPM_INV_3_Value_EPT() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_IPM_INV_3_Value_EPT_IPM_INV_3_Value_EPT->value)

#define Rte_IWrite_Runbl_IpmCanRx_10ms_IPM_INV_4_Value_EPT_IPM_INV_4_Value_EPT(data) (Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_IPM_INV_4_Value_EPT_IPM_INV_4_Value_EPT->value = *(data))

#define Rte_IWriteRef_Runbl_IpmCanRx_10ms_IPM_INV_4_Value_EPT_IPM_INV_4_Value_EPT() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_IPM_INV_4_Value_EPT_IPM_INV_4_Value_EPT->value)

#define Rte_IRead_Runbl_IpmCanRx_20ms_BMS_10_DC_ChargeStates_EPT_BMS_10_DC_ChargeStates_EPT() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_BMS_10_DC_ChargeStates_EPT_BMS_10_DC_ChargeStates_EPT->value)

#define Rte_IRead_Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT->value)

#define Rte_IRead_Runbl_IpmCanRx_20ms_BMS_2_BatState_EPT_BMS_2_BatState_EPT() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_BMS_2_BatState_EPT_BMS_2_BatState_EPT->value)

#define Rte_IRead_Runbl_IpmCanRx_20ms_BMS_3_DC_ChargeState_EPT_BMS_3_DC_ChargeState_EPT() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_BMS_3_DC_ChargeState_EPT_BMS_3_DC_ChargeState_EPT->value)

#define Rte_IRead_Runbl_IpmCanRx_20ms_BMS_4_AC_ChargeState_EPT_BMS_4_AC_ChargeState_EPT() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_BMS_4_AC_ChargeState_EPT_BMS_4_AC_ChargeState_EPT->value)

#define Rte_IRead_Runbl_IpmCanRx_20ms_BMS_6_DischrgRecup_EPT_BMS_6_DischrgRecup_EPT() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_BMS_6_DischrgRecup_EPT_BMS_6_DischrgRecup_EPT->value)

#define Rte_IRead_Runbl_IpmCanRx_20ms_BMS_7_CellVolt_EPT_BMS_7_CellVolt_EPT() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_BMS_7_CellVolt_EPT_BMS_7_CellVolt_EPT->value)

#define Rte_IRead_Runbl_IpmCanRx_20ms_CRRR_A_CHA_CRRR_A_CHA() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_CRRR_A_CHA_CRRR_A_CHA->value)

#define Rte_IRead_Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA->value)

#define Rte_IRead_Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA->value)

#define Rte_IRead_Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD->value)

#define Rte_IWrite_Runbl_IpmCanRx_20ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT(data) (Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT->value = *(data))

#define Rte_IWriteRef_Runbl_IpmCanRx_20ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT->value)

#define Rte_IWrite_Runbl_IpmCanRx_20ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT(data) (Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT->value = *(data))

#define Rte_IWriteRef_Runbl_IpmCanRx_20ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT->value)

#define Rte_IWrite_Runbl_IpmCanRx_20ms_IPM_BMS_2_BatState_EPT_IPM_BMS_2_BatState_EPT(data) (Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_IPM_BMS_2_BatState_EPT_IPM_BMS_2_BatState_EPT->value = *(data))

#define Rte_IWriteRef_Runbl_IpmCanRx_20ms_IPM_BMS_2_BatState_EPT_IPM_BMS_2_BatState_EPT() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_IPM_BMS_2_BatState_EPT_IPM_BMS_2_BatState_EPT->value)

#define Rte_IWrite_Runbl_IpmCanRx_20ms_IPM_BMS_3_DC_ChargeState_EPT_IPM_BMS_3_DC_ChargeState_EPT(data) (Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_IPM_BMS_3_DC_ChargeState_EPT_IPM_BMS_3_DC_ChargeState_EPT->value = *(data))

#define Rte_IWriteRef_Runbl_IpmCanRx_20ms_IPM_BMS_3_DC_ChargeState_EPT_IPM_BMS_3_DC_ChargeState_EPT() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_IPM_BMS_3_DC_ChargeState_EPT_IPM_BMS_3_DC_ChargeState_EPT->value)

#define Rte_IWrite_Runbl_IpmCanRx_20ms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT(data) (Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT->value = *(data))

#define Rte_IWriteRef_Runbl_IpmCanRx_20ms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT->value)

#define Rte_IWrite_Runbl_IpmCanRx_20ms_IPM_BMS_6_DischrgRecup_EPT_IPM_BMS_6_DischrgRecup_EPT(data) (Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_IPM_BMS_6_DischrgRecup_EPT_IPM_BMS_6_DischrgRecup_EPT->value = *(data))

#define Rte_IWriteRef_Runbl_IpmCanRx_20ms_IPM_BMS_6_DischrgRecup_EPT_IPM_BMS_6_DischrgRecup_EPT() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_IPM_BMS_6_DischrgRecup_EPT_IPM_BMS_6_DischrgRecup_EPT->value)

#define Rte_IWrite_Runbl_IpmCanRx_20ms_IPM_BMS_7_CellVolt_EPT_IPM_BMS_7_CellVolt_EPT(data) (Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_IPM_BMS_7_CellVolt_EPT_IPM_BMS_7_CellVolt_EPT->value = *(data))

#define Rte_IWriteRef_Runbl_IpmCanRx_20ms_IPM_BMS_7_CellVolt_EPT_IPM_BMS_7_CellVolt_EPT() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_IPM_BMS_7_CellVolt_EPT_IPM_BMS_7_CellVolt_EPT->value)

#define Rte_IWrite_Runbl_IpmCanRx_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA(data) (Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA->value = *(data))

#define Rte_IWriteRef_Runbl_IpmCanRx_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA->value)

#define Rte_IWrite_Runbl_IpmCanRx_20ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA(data) (Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA->value = *(data))

#define Rte_IWriteRef_Runbl_IpmCanRx_20ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA->value)

#define Rte_IWrite_Runbl_IpmCanRx_20ms_IPM_FCM_B_CHA_IPM_FCM_B_CHA(data) (Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_IPM_FCM_B_CHA_IPM_FCM_B_CHA->value = *(data))

#define Rte_IWriteRef_Runbl_IpmCanRx_20ms_IPM_FCM_B_CHA_IPM_FCM_B_CHA() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_IPM_FCM_B_CHA_IPM_FCM_B_CHA->value)

#define Rte_IWrite_Runbl_IpmCanRx_20ms_IPM_SCS_RiSwitchSts_BOD_IPM_SCS_RiSwitchSts_BOD(data) (Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_IPM_SCS_RiSwitchSts_BOD_IPM_SCS_RiSwitchSts_BOD->value = *(data))

#define Rte_IWriteRef_Runbl_IpmCanRx_20ms_IPM_SCS_RiSwitchSts_BOD_IPM_SCS_RiSwitchSts_BOD() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_IPM_SCS_RiSwitchSts_BOD_IPM_SCS_RiSwitchSts_BOD->value)

#define Rte_IRead_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD->value)

#define Rte_IRead_Runbl_IpmCanRx_50ms_ESCL_ESCLStatus_BOD_ESCL_ESCLStatus_BOD() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_50ms_ESCL_ESCLStatus_BOD_ESCL_ESCLStatus_BOD->value)

#define Rte_IRead_Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD->value)

#define Rte_IRead_Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA->value)

#define Rte_IWrite_Runbl_IpmCanRx_50ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD(data) (Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_50ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD->value = *(data))

#define Rte_IWriteRef_Runbl_IpmCanRx_50ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_50ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD->value)

#define Rte_IWrite_Runbl_IpmCanRx_50ms_IPM_ESCL_ESCLStatus_BOD_IPM_ESCL_ESCLStatus_BOD(data) (Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_50ms_IPM_ESCL_ESCLStatus_BOD_IPM_ESCL_ESCLStatus_BOD->value = *(data))

#define Rte_IWriteRef_Runbl_IpmCanRx_50ms_IPM_ESCL_ESCLStatus_BOD_IPM_ESCL_ESCLStatus_BOD() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_50ms_IPM_ESCL_ESCLStatus_BOD_IPM_ESCL_ESCLStatus_BOD->value)

#define Rte_IWrite_Runbl_IpmCanRx_50ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD(data) (Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_50ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD->value = *(data))

#define Rte_IWriteRef_Runbl_IpmCanRx_50ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_50ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD->value)

#define Rte_IWrite_Runbl_IpmCanRx_50ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA(data) (Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_50ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA->value = *(data))

#define Rte_IWriteRef_Runbl_IpmCanRx_50ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA() (&Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_50ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA->value)

#define Rte_IRead_Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs() (&Rte_Inst_AppSwcIpm.Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs->value)

#define Rte_IWrite_Runbl_IpmMsgActv_10ms_CANCommCRCFlt_outputs_CANCommCRCFlt_outputs(data) (Rte_Inst_AppSwcIpm.Runbl_IpmMsgActv_10ms_CANCommCRCFlt_outputs_CANCommCRCFlt_outputs->value = *(data))

#define Rte_IWriteRef_Runbl_IpmMsgActv_10ms_CANCommCRCFlt_outputs_CANCommCRCFlt_outputs() (&Rte_Inst_AppSwcIpm.Runbl_IpmMsgActv_10ms_CANCommCRCFlt_outputs_CANCommCRCFlt_outputs->value)

#define Rte_IWrite_Runbl_IpmMsgActv_10ms_CANCommErr_outputs_CANCommErr_outputs(data) (Rte_Inst_AppSwcIpm.Runbl_IpmMsgActv_10ms_CANCommErr_outputs_CANCommErr_outputs->value = *(data))

#define Rte_IWriteRef_Runbl_IpmMsgActv_10ms_CANCommErr_outputs_CANCommErr_outputs() (&Rte_Inst_AppSwcIpm.Runbl_IpmMsgActv_10ms_CANCommErr_outputs_CANCommErr_outputs->value)

#define Rte_IWrite_Runbl_IpmMsgActv_10ms_MsgActv_outputs_MsgActv_outputs(data) (Rte_Inst_AppSwcIpm.Runbl_IpmMsgActv_10ms_MsgActv_outputs_MsgActv_outputs->value = *(data))

#define Rte_IWriteRef_Runbl_IpmMsgActv_10ms_MsgActv_outputs_MsgActv_outputs() (&Rte_Inst_AppSwcIpm.Runbl_IpmMsgActv_10ms_MsgActv_outputs_MsgActv_outputs->value)

#endif

/*******************************************************************************
 **                        Global Function Declarations                       **
******************************************************************************/

/** API functions */

void Rte_Runbl_IpmCanRx_100ms(void);

void Rte_Runbl_IpmCanRx_10ms(void);

void Rte_Runbl_IpmCanRx_20ms(void);

void Rte_Runbl_IpmCanRx_50ms(void);

void Rte_Runbl_IpmMsgActv_10ms(void);

void Rte_AppSwcIpm_Init(void);

DT_CANCommCRCFlt* Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV(void);

DT_CANCommCRCFlt* Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV(void);

DT_CANCommCRCFlt* Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV(void);

DT_CANCommCRCFlt* Rte_IrvIRead_Runbl_IpmCanRx_50ms_CANCommCRCFlt_outputsIRV(void);

void Rte_IrvIWrite_Runbl_IpmMsgActv_10ms_CANCommCRCFlt_outputsIRV(DT_CANCommCRCFlt* data);

DT_CANCommCRCFlt * Rte_IrvIWriteRef_Runbl_IpmMsgActv_10ms_CANCommCRCFlt_outputsIRV(void);

DT_MsgActv* Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV(void);

DT_MsgActv* Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV(void);

DT_MsgActv* Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV(void);

DT_MsgActv* Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV(void);

void Rte_IrvIWrite_Runbl_IpmMsgActv_10ms_MsgActv_outputsIRV(DT_MsgActv* data);

DT_MsgActv * Rte_IrvIWriteRef_Runbl_IpmMsgActv_10ms_MsgActv_outputsIRV(void);

Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_100ms_ACCM_Version_BOD_ACCM_Version_BOD(void);

Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_100ms_BMS_5_BatTemp_EPT_BMS_5_BatTemp_EPT(void);

Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_100ms_BMS_9_BattInfo_EPT_BMS_9_BattInfo_EPT(void);

Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD(void);

Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC(void);

Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_100ms_HVCH_Status1_BOD_HVCH_Status1_BOD(void);

Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_100ms_HVCH_Status2_BOD_HVCH_Status2_BOD(void);

Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_100ms_ICU_2_Odo_BAC_ICU_2_Odo_BAC(void);

Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_100ms_INV_IMMO_Req_EPT_INV_IMMO_Req_EPT(void);

Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_100ms_IPU_DCC_1_State_EPT_IPU_DCC_1_State_EPT(void);

Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_100ms_IPU_DCC_2_ChrgInValue_EPT_IPU_DCC_2_ChrgInValue_EPT(void);

Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_100ms_IPU_OBC_1_State_EPT_IPU_OBC_1_State_EPT(void);

Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_100ms_IPU_OBC_2_Inlet_EPT_IPU_OBC_2_Inlet_EPT(void);

Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_100ms_TBOX_BJS_Time_BAC_TBOX_BJS_Time_BAC(void);

Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA(void);

Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_10ms_EPS_2_StrWhlAng_CHA_EPS_2_StrWhlAng_CHA(void);

Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_10ms_ESC_7_FuncStatus_CHA_ESC_7_FuncStatus_CHA(void);

Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA(void);

Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_10ms_INV_1_Value_EPT_INV_1_Value_EPT(void);

Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_10ms_INV_2_Value_EPT_INV_2_Value_EPT(void);

Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_10ms_INV_3_Value_EPT_INV_3_Value_EPT(void);

Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_10ms_INV_4_Value_EPT_INV_4_Value_EPT(void);

Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_20ms_BMS_10_DC_ChargeStates_EPT_BMS_10_DC_ChargeStates_EPT(void);

Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT(void);

Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_20ms_BMS_2_BatState_EPT_BMS_2_BatState_EPT(void);

Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_20ms_BMS_3_DC_ChargeState_EPT_BMS_3_DC_ChargeState_EPT(void);

Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_20ms_BMS_4_AC_ChargeState_EPT_BMS_4_AC_ChargeState_EPT(void);

Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_20ms_BMS_6_DischrgRecup_EPT_BMS_6_DischrgRecup_EPT(void);

Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_20ms_BMS_7_CellVolt_EPT_BMS_7_CellVolt_EPT(void);

Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_20ms_CRRR_A_CHA_CRRR_A_CHA(void);

Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA(void);

Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA(void);

Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD(void);

Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD(void);

Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_50ms_ESCL_ESCLStatus_BOD_ESCL_ESCLStatus_BOD(void);

Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD(void);

Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA(void);

Std_ReturnType Rte_IStatus_Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs(void);

/** runnables */

void Runbl_IpmCanRx_100ms(void);

void Runbl_IpmCanRx_10ms(void);

void Runbl_IpmCanRx_20ms(void);

void Runbl_IpmCanRx_50ms(void);

void Runbl_IpmMsgActv_10ms(void);

void AppSwcIpm_Init(void);

#endif

