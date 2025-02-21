/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_DataHandleType.h>
 *  @brief      <>
 *  
 *  <MCU:E3420>
 *  
 *  @author     <>
 *  @date       <2025-02-19 14:25:38>
 */
/*============================================================================*/

/* Rte_DataHandleType.h */

#ifndef RTE_DATAHANDLETYPE_H
#define RTE_DATAHANDLETYPE_H

/*******************************************************************************
 **                        Revision Control History                           **
******************************************************************************/

/*******************************************************************************
 **                        Version Information                                **
******************************************************************************/

/*******************************************************************************
 **                        Include Section                                    **
******************************************************************************/
#include "Rte_Type.h"

typedef struct
{
    DT_IPM_TBOX_BJS_Time_BAC value;
    Std_ReturnType status;
} Rte_DE_DT_IPM_TBOX_BJS_Time_BAC_status;

typedef struct
{
    DT_IPM_CCP_PanelStatus_BOD value;
    Std_ReturnType status;
} Rte_DE_DT_IPM_CCP_PanelStatus_BOD_status;

typedef struct
{
    DT_IPM_ESC_7_FuncStatus_CHA value;
    Std_ReturnType status;
} Rte_DE_DT_IPM_ESC_7_FuncStatus_CHA_status;

typedef struct
{
    DT_IPM_HU_B_BAC value;
    Std_ReturnType status;
} Rte_DE_DT_IPM_HU_B_BAC_status;

typedef struct
{
    DT_IPM_SCS_LeSwitchSts_BOD value;
    Std_ReturnType status;
} Rte_DE_DT_IPM_SCS_LeSwitchSts_BOD_status;

typedef struct
{
    DT_Vcu2BcmTms_outputs value;
    Std_ReturnType status;
} Rte_DE_DT_Vcu2BcmTms_outputs_status;

typedef struct
{
    DT_Bcm2OpmBAC_outputs value;
    Std_ReturnType status;
} Rte_DE_DT_Bcm2OpmBAC_outputs_status;

typedef struct
{
    DT_Bcm2OpmEPT_outputs value;
    Std_ReturnType status;
} Rte_DE_DT_Bcm2OpmEPT_outputs_status;

typedef struct
{
    DT_Bcm2OpmOBD_outputs value;
    Std_ReturnType status;
} Rte_DE_DT_Bcm2OpmOBD_outputs_status;

typedef struct
{
    DT_Bcm2VcuTms_outputs value;
    Std_ReturnType status;
} Rte_DE_DT_Bcm2VcuTms_outputs_status;

typedef struct
{
    UInt8 value;
    Std_ReturnType status;
} Rte_DE_UInt8_status;

typedef struct
{
    DT_IPM_BMS_1_MainState_EPT value;
    Std_ReturnType status;
} Rte_DE_DT_IPM_BMS_1_MainState_EPT_status;

typedef struct
{
    DT_IPM_CRRR_A_CHA value;
    Std_ReturnType status;
} Rte_DE_DT_IPM_CRRR_A_CHA_status;

typedef struct
{
    DT_IPM_EHB_A_CHA value;
    Std_ReturnType status;
} Rte_DE_DT_IPM_EHB_A_CHA_status;

typedef struct
{
    DT_IPM_EHB_B_CHA value;
    Std_ReturnType status;
} Rte_DE_DT_IPM_EHB_B_CHA_status;

typedef struct
{
    DT_IPM_ESCL_ESCLStatus_BOD value;
    Std_ReturnType status;
} Rte_DE_DT_IPM_ESCL_ESCLStatus_BOD_status;

typedef struct
{
    DT_IPM_FCM_A_CHA value;
    Std_ReturnType status;
} Rte_DE_DT_IPM_FCM_A_CHA_status;

typedef struct
{
    DT_IPM_INV_IMMO_Req_EPT value;
    Std_ReturnType status;
} Rte_DE_DT_IPM_INV_IMMO_Req_EPT_status;

typedef struct
{
    DT_IPM_SRS_1_Status_CHA value;
    Std_ReturnType status;
} Rte_DE_DT_IPM_SRS_1_Status_CHA_status;

typedef struct
{
    ACCM_Version_BOD value;
    Std_ReturnType status;
} Rte_DE_ACCM_Version_BOD_status;

typedef struct
{
    BMS_5_BatTemp_EPT value;
    Std_ReturnType status;
} Rte_DE_BMS_5_BatTemp_EPT_status;

typedef struct
{
    BMS_9_BattInfo_EPT value;
    Std_ReturnType status;
} Rte_DE_BMS_9_BattInfo_EPT_status;

typedef struct
{
    COMP_AC_BOD value;
    Std_ReturnType status;
} Rte_DE_COMP_AC_BOD_status;

typedef struct
{
    FCM_A_CHA value;
    Std_ReturnType status;
} Rte_DE_FCM_A_CHA_status;

typedef struct
{
    HU_B_BAC value;
    Std_ReturnType status;
} Rte_DE_HU_B_BAC_status;

typedef struct
{
    HVCH_Status1_BOD value;
    Std_ReturnType status;
} Rte_DE_HVCH_Status1_BOD_status;

typedef struct
{
    HVCH_Status2_BOD value;
    Std_ReturnType status;
} Rte_DE_HVCH_Status2_BOD_status;

typedef struct
{
    ICU_2_Odo_BAC value;
    Std_ReturnType status;
} Rte_DE_ICU_2_Odo_BAC_status;

typedef struct
{
    INV_IMMO_Req_EPT value;
    Std_ReturnType status;
} Rte_DE_INV_IMMO_Req_EPT_status;

typedef struct
{
    IPU_DCC_1_State_EPT value;
    Std_ReturnType status;
} Rte_DE_IPU_DCC_1_State_EPT_status;

typedef struct
{
    IPU_DCC_2_ChrgInValue_EPT value;
    Std_ReturnType status;
} Rte_DE_IPU_DCC_2_ChrgInValue_EPT_status;

typedef struct
{
    IPU_OBC_1_State_EPT value;
    Std_ReturnType status;
} Rte_DE_IPU_OBC_1_State_EPT_status;

typedef struct
{
    IPU_OBC_2_Inlet_EPT value;
    Std_ReturnType status;
} Rte_DE_IPU_OBC_2_Inlet_EPT_status;

typedef struct
{
    TBOX_BJS_Time_BAC value;
    Std_ReturnType status;
} Rte_DE_TBOX_BJS_Time_BAC_status;

typedef struct
{
    DT_IPM_ACCM_Version_BOD value;
    Std_ReturnType status;
} Rte_DE_DT_IPM_ACCM_Version_BOD_status;

typedef struct
{
    DT_IPM_BMS_5_BatTemp_EPT value;
    Std_ReturnType status;
} Rte_DE_DT_IPM_BMS_5_BatTemp_EPT_status;

typedef struct
{
    DT_IPM_BMS_9_BattInfo_EPT value;
    Std_ReturnType status;
} Rte_DE_DT_IPM_BMS_9_BattInfo_EPT_status;

typedef struct
{
    DT_IPM_COMP_AC_BOD value;
    Std_ReturnType status;
} Rte_DE_DT_IPM_COMP_AC_BOD_status;

typedef struct
{
    DT_IPM_HVCH_Status1_BOD value;
    Std_ReturnType status;
} Rte_DE_DT_IPM_HVCH_Status1_BOD_status;

typedef struct
{
    DT_IPM_HVCH_Status2_BOD value;
    Std_ReturnType status;
} Rte_DE_DT_IPM_HVCH_Status2_BOD_status;

typedef struct
{
    DT_IPM_ICU_2_Odo_BAC value;
    Std_ReturnType status;
} Rte_DE_DT_IPM_ICU_2_Odo_BAC_status;

typedef struct
{
    DT_IPM_IPU_DCC_1_State_EPT value;
    Std_ReturnType status;
} Rte_DE_DT_IPM_IPU_DCC_1_State_EPT_status;

typedef struct
{
    DT_IPM_IPU_DCC_2_ChrgInValue_EPT value;
    Std_ReturnType status;
} Rte_DE_DT_IPM_IPU_DCC_2_ChrgInValue_EPT_status;

typedef struct
{
    DT_IPM_IPU_OBC_1_State_EPT value;
    Std_ReturnType status;
} Rte_DE_DT_IPM_IPU_OBC_1_State_EPT_status;

typedef struct
{
    DT_IPM_IPU_OBC_2_Inlet_EPT value;
    Std_ReturnType status;
} Rte_DE_DT_IPM_IPU_OBC_2_Inlet_EPT_status;

typedef struct
{
    EHB_B_CHA value;
    Std_ReturnType status;
} Rte_DE_EHB_B_CHA_status;

typedef struct
{
    EPS_2_StrWhlAng_CHA value;
    Std_ReturnType status;
} Rte_DE_EPS_2_StrWhlAng_CHA_status;

typedef struct
{
    ESC_7_FuncStatus_CHA value;
    Std_ReturnType status;
} Rte_DE_ESC_7_FuncStatus_CHA_status;

typedef struct
{
    ESC_A_CHA value;
    Std_ReturnType status;
} Rte_DE_ESC_A_CHA_status;

typedef struct
{
    INV_1_Value_EPT value;
    Std_ReturnType status;
} Rte_DE_INV_1_Value_EPT_status;

typedef struct
{
    INV_2_Value_EPT value;
    Std_ReturnType status;
} Rte_DE_INV_2_Value_EPT_status;

typedef struct
{
    INV_3_Value_EPT value;
    Std_ReturnType status;
} Rte_DE_INV_3_Value_EPT_status;

typedef struct
{
    INV_4_Value_EPT value;
    Std_ReturnType status;
} Rte_DE_INV_4_Value_EPT_status;

typedef struct
{
    DT_IPM_EPS_2_StrWhlAng_CHA value;
    Std_ReturnType status;
} Rte_DE_DT_IPM_EPS_2_StrWhlAng_CHA_status;

typedef struct
{
    DT_IPM_ESC_A_CHA value;
    Std_ReturnType status;
} Rte_DE_DT_IPM_ESC_A_CHA_status;

typedef struct
{
    DT_IPM_INV_1_Value_EPT value;
    Std_ReturnType status;
} Rte_DE_DT_IPM_INV_1_Value_EPT_status;

typedef struct
{
    DT_IPM_INV_2_Value_EPT value;
    Std_ReturnType status;
} Rte_DE_DT_IPM_INV_2_Value_EPT_status;

typedef struct
{
    DT_IPM_INV_3_Value_EPT value;
    Std_ReturnType status;
} Rte_DE_DT_IPM_INV_3_Value_EPT_status;

typedef struct
{
    DT_IPM_INV_4_Value_EPT value;
    Std_ReturnType status;
} Rte_DE_DT_IPM_INV_4_Value_EPT_status;

typedef struct
{
    BMS_10_DC_ChargeStates_EPT value;
    Std_ReturnType status;
} Rte_DE_BMS_10_DC_ChargeStates_EPT_status;

typedef struct
{
    BMS_1_MainState_EPT value;
    Std_ReturnType status;
} Rte_DE_BMS_1_MainState_EPT_status;

typedef struct
{
    BMS_2_BatState_EPT value;
    Std_ReturnType status;
} Rte_DE_BMS_2_BatState_EPT_status;

typedef struct
{
    BMS_3_DC_ChargeState_EPT value;
    Std_ReturnType status;
} Rte_DE_BMS_3_DC_ChargeState_EPT_status;

typedef struct
{
    BMS_4_AC_ChargeState_EPT value;
    Std_ReturnType status;
} Rte_DE_BMS_4_AC_ChargeState_EPT_status;

typedef struct
{
    BMS_6_DischrgRecup_EPT value;
    Std_ReturnType status;
} Rte_DE_BMS_6_DischrgRecup_EPT_status;

typedef struct
{
    BMS_7_CellVolt_EPT value;
    Std_ReturnType status;
} Rte_DE_BMS_7_CellVolt_EPT_status;

typedef struct
{
    CRRR_A_CHA value;
    Std_ReturnType status;
} Rte_DE_CRRR_A_CHA_status;

typedef struct
{
    EHB_A_CHA value;
    Std_ReturnType status;
} Rte_DE_EHB_A_CHA_status;

typedef struct
{
    FCM_B_CHA value;
    Std_ReturnType status;
} Rte_DE_FCM_B_CHA_status;

typedef struct
{
    SCS_RiSwitchSts_BOD value;
    Std_ReturnType status;
} Rte_DE_SCS_RiSwitchSts_BOD_status;

typedef struct
{
    DT_IPM_BMS_10_DC_ChargeStates_EPT value;
    Std_ReturnType status;
} Rte_DE_DT_IPM_BMS_10_DC_ChargeStates_EPT_status;

typedef struct
{
    DT_IPM_BMS_2_BatState_EPT value;
    Std_ReturnType status;
} Rte_DE_DT_IPM_BMS_2_BatState_EPT_status;

typedef struct
{
    DT_IPM_BMS_3_DC_ChargeState_EPT value;
    Std_ReturnType status;
} Rte_DE_DT_IPM_BMS_3_DC_ChargeState_EPT_status;

typedef struct
{
    DT_IPM_BMS_4_AC_ChargeState_EPT value;
    Std_ReturnType status;
} Rte_DE_DT_IPM_BMS_4_AC_ChargeState_EPT_status;

typedef struct
{
    DT_IPM_BMS_6_DischrgRecup_EPT value;
    Std_ReturnType status;
} Rte_DE_DT_IPM_BMS_6_DischrgRecup_EPT_status;

typedef struct
{
    DT_IPM_BMS_7_CellVolt_EPT value;
    Std_ReturnType status;
} Rte_DE_DT_IPM_BMS_7_CellVolt_EPT_status;

typedef struct
{
    DT_IPM_FCM_B_CHA value;
    Std_ReturnType status;
} Rte_DE_DT_IPM_FCM_B_CHA_status;

typedef struct
{
    DT_IPM_SCS_RiSwitchSts_BOD value;
    Std_ReturnType status;
} Rte_DE_DT_IPM_SCS_RiSwitchSts_BOD_status;

typedef struct
{
    CCP_PanelStatus_BOD value;
    Std_ReturnType status;
} Rte_DE_CCP_PanelStatus_BOD_status;

typedef struct
{
    ESCL_ESCLStatus_BOD value;
    Std_ReturnType status;
} Rte_DE_ESCL_ESCLStatus_BOD_status;

typedef struct
{
    SCS_LeSwitchSts_BOD value;
    Std_ReturnType status;
} Rte_DE_SCS_LeSwitchSts_BOD_status;

typedef struct
{
    SRS_1_Status_CHA value;
    Std_ReturnType status;
} Rte_DE_SRS_1_Status_CHA_status;

typedef struct
{
    DAG_Comm_outputs value;
    Std_ReturnType status;
} Rte_DE_DAG_Comm_outputs_status;

typedef struct
{
    DT_CANCommCRCFlt value;
    Std_ReturnType status;
} Rte_DE_DT_CANCommCRCFlt_status;

typedef struct
{
    DT_CANCommErr value;
    Std_ReturnType status;
} Rte_DE_DT_CANCommErr_status;

typedef struct
{
    DT_MsgActv value;
    Std_ReturnType status;
} Rte_DE_DT_MsgActv_status;

typedef struct
{
    TMS2VCU_AC_1_Command_Outputs value;
    Std_ReturnType status;
} Rte_DE_TMS2VCU_AC_1_Command_Outputs_status;

typedef struct
{
    TMS2VCU_AC_2_State_Outputs value;
    Std_ReturnType status;
} Rte_DE_TMS2VCU_AC_2_State_Outputs_status;

typedef struct
{
    TMS2VCU_AC_3_State_Outputs value;
    Std_ReturnType status;
} Rte_DE_TMS2VCU_AC_3_State_Outputs_status;

typedef struct
{
    TMS2VCU_AC_8_status_Outputs value;
    Std_ReturnType status;
} Rte_DE_TMS2VCU_AC_8_status_Outputs_status;

typedef struct
{
    TMS2VCU_AC_ACStatuts_Outputs value;
    Std_ReturnType status;
} Rte_DE_TMS2VCU_AC_ACStatuts_Outputs_status;

typedef struct
{
    TMS2VCU_AC_COMP_Outputs value;
    Std_ReturnType status;
} Rte_DE_TMS2VCU_AC_COMP_Outputs_status;

typedef struct
{
    TMS2VCU_HVCH_Command_Outputs value;
    Std_ReturnType status;
} Rte_DE_TMS2VCU_HVCH_Command_Outputs_status;

typedef struct
{
    TMS2VCU_TMS_LINTestData1_Outputs value;
    Std_ReturnType status;
} Rte_DE_TMS2VCU_TMS_LINTestData1_Outputs_status;

typedef struct
{
    TMS2VCU_TMS_LINTestData2_Outputs value;
    Std_ReturnType status;
} Rte_DE_TMS2VCU_TMS_LINTestData2_Outputs_status;

typedef struct
{
    TMS2VCU_TMS_LINTestData3_Outputs value;
    Std_ReturnType status;
} Rte_DE_TMS2VCU_TMS_LINTestData3_Outputs_status;

typedef struct
{
    AC_1_Command_BOD value;
    Std_ReturnType status;
} Rte_DE_AC_1_Command_BOD_status;

typedef struct
{
    AC_2_State_BOD value;
    Std_ReturnType status;
} Rte_DE_AC_2_State_BOD_status;

typedef struct
{
    AC_3_State_BOD value;
    Std_ReturnType status;
} Rte_DE_AC_3_State_BOD_status;

typedef struct
{
    AC_8_status_BOD value;
    Std_ReturnType status;
} Rte_DE_AC_8_status_BOD_status;

typedef struct
{
    AC_ACStatuts_BOD value;
    Std_ReturnType status;
} Rte_DE_AC_ACStatuts_BOD_status;

typedef struct
{
    AC_COMP_BOD value;
    Std_ReturnType status;
} Rte_DE_AC_COMP_BOD_status;

typedef struct
{
    BCM_ESCLCommand_BOD value;
    Std_ReturnType status;
} Rte_DE_BCM_ESCLCommand_BOD_status;

typedef struct
{
    BCM_HFSData_BAC value;
    Std_ReturnType status;
} Rte_DE_BCM_HFSData_BAC_status;

typedef struct
{
    BCM_IMMOAuthResp1_EPT value;
    Std_ReturnType status;
} Rte_DE_BCM_IMMOAuthResp1_EPT_status;

typedef struct
{
    HVCH_Command_BOD value;
    Std_ReturnType status;
} Rte_DE_HVCH_Command_BOD_status;

typedef struct
{
    TMS_LINTestData1_BOD value;
    Std_ReturnType status;
} Rte_DE_TMS_LINTestData1_BOD_status;

typedef struct
{
    TMS_LINTestData2_BOD value;
    Std_ReturnType status;
} Rte_DE_TMS_LINTestData2_BOD_status;

typedef struct
{
    TMS_LINTestData3_BOD value;
    Std_ReturnType status;
} Rte_DE_TMS_LINTestData3_BOD_status;

typedef struct
{
    VCU_0_Value_EPT value;
    Std_ReturnType status;
} Rte_DE_VCU_0_Value_EPT_status;

typedef struct
{
    VCU_10_Torque_CHA value;
    Std_ReturnType status;
} Rte_DE_VCU_10_Torque_CHA_status;

typedef struct
{
    VCU_1_InvCmd_EPT value;
    Std_ReturnType status;
} Rte_DE_VCU_1_InvCmd_EPT_status;

typedef struct
{
    VCU_3_OprtCmd_EPT value;
    Std_ReturnType status;
} Rte_DE_VCU_3_OprtCmd_EPT_status;

typedef struct
{
    VCU_4_ChrgCmd_EPT value;
    Std_ReturnType status;
} Rte_DE_VCU_4_ChrgCmd_EPT_status;

typedef struct
{
    VCU_B_AcclPedal_EPT value;
    Std_ReturnType status;
} Rte_DE_VCU_B_AcclPedal_EPT_status;

typedef struct
{
    VCU_C_OprtCmd_EPT value;
    Std_ReturnType status;
} Rte_DE_VCU_C_OprtCmd_EPT_status;

typedef struct
{
    VCU_D_Status_CHA value;
    Std_ReturnType status;
} Rte_DE_VCU_D_Status_CHA_status;

typedef struct
{
    VCU_DispInfo_BAC value;
    Std_ReturnType status;
} Rte_DE_VCU_DispInfo_BAC_status;

typedef struct
{
    BCM_B_Package_BAC value;
    Std_ReturnType status;
} Rte_DE_BCM_B_Package_BAC_status;

typedef struct
{
    CCU_VehInfo_BAC value;
    Std_ReturnType status;
} Rte_DE_CCU_VehInfo_BAC_status;

typedef struct
{
    TMS2VCU_PPVAddSignalGroup_Outputs value;
    Std_ReturnType status;
} Rte_DE_TMS2VCU_PPVAddSignalGroup_Outputs_status;

typedef struct
{
    DT_Vcu2OpmBAC_outputs value;
    Std_ReturnType status;
} Rte_DE_DT_Vcu2OpmBAC_outputs_status;

typedef struct
{
    DT_Vcu2OpmCHA_outputs value;
    Std_ReturnType status;
} Rte_DE_DT_Vcu2OpmCHA_outputs_status;

typedef struct
{
    DT_Vcu2OpmEPT_outputs value;
    Std_ReturnType status;
} Rte_DE_DT_Vcu2OpmEPT_outputs_status;

typedef struct
{
    Boolean value;
    Std_ReturnType status;
} Rte_DE_Boolean_status;

typedef struct
{
    UInt16 value;
    Std_ReturnType status;
} Rte_DE_UInt16_status;

typedef struct
{
    Tms2Vcu_Info value;
    Std_ReturnType status;
} Rte_DE_Tms2Vcu_Info_status;

#endif

