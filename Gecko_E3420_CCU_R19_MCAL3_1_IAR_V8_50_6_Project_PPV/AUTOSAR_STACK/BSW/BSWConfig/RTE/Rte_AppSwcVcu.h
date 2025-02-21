/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_AppSwcVcu.h>
 *  @brief      <>
 *  
 *  <MCU:E3420>
 *  
 *  @author     <>
 *  @date       <2025-02-19 14:27:08>
 */
/*============================================================================*/

/* Rte_AppSwcVcu.h */

#ifndef RTE_APPSWCVCU_H
#define RTE_APPSWCVCU_H

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
#include "Rte_AppSwcVcu_Type.h"

/*******************************************************************************
 **                        Macro Definitions                                  **
******************************************************************************/

typedef struct
{
    P2VAR(Rte_DE_TMS2VCU_AC_3_State_Outputs_status, AUTOMATIC, RTE_DATA)  Runbl_VCU_100ms_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs;
    P2VAR(Rte_DE_TMS2VCU_PPVAddSignalGroup_Outputs_status, AUTOMATIC, RTE_DATA)  Runbl_VCU_100ms_TMS2VCU_PPV_outputs_TMS2VCU_PPV_outputs;
    P2VAR(Rte_DE_DT_IPM_CCP_PanelStatus_BOD_status, AUTOMATIC, RTE_DATA)  Runbl_VCU_10ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD;
    P2VAR(Rte_DE_DT_IPM_EHB_A_CHA_status, AUTOMATIC, RTE_DATA)  Runbl_VCU_10ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA;
    P2VAR(Rte_DE_DT_CANCommCRCFlt_status, AUTOMATIC, RTE_DATA)  Runbl_VCU_20ms_CANCommCRCFlt_outputs_CANCommCRCFlt_outputs;
    P2VAR(Rte_DE_DT_IPM_BMS_3_DC_ChargeState_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_VCU_20ms_IPM_BMS_3_DC_ChargeState_EPT_IPM_BMS_3_DC_ChargeState_EPT;
    P2VAR(Rte_DE_DT_IPM_BMS_4_AC_ChargeState_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_VCU_20ms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT;
    P2VAR(Rte_DE_DT_IPM_BMS_7_CellVolt_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_VCU_20ms_IPM_BMS_7_CellVolt_EPT_IPM_BMS_7_CellVolt_EPT;
    P2VAR(Rte_DE_DT_IPM_COMP_AC_BOD_status, AUTOMATIC, RTE_DATA)  Runbl_VCU_20ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD;
    P2VAR(Rte_DE_DT_IPM_ICU_2_Odo_BAC_status, AUTOMATIC, RTE_DATA)  Runbl_VCU_20ms_IPM_ICU_2_Odo_BAC_IPM_ICU_2_Odo_BAC;
    P2VAR(Rte_DE_DT_IPM_IPU_DCC_2_ChrgInValue_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_VCU_20ms_IPM_IPU_DCC_2_ChrgInValue_EPT_IPM_IPU_DCC_2_ChrgInValue_EPT;
    P2VAR(Rte_DE_DT_IPM_IPU_OBC_2_Inlet_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_VCU_20ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT;
    P2VAR(Rte_DE_DT_IPM_TBOX_BJS_Time_BAC_status, AUTOMATIC, RTE_DATA)  Runbl_VCU_20ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC;
    P2VAR(Rte_DE_DT_Bcm2VcuTms_outputs_status, AUTOMATIC, RTE_DATA)  Runbl_VcuRx_10ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs;
    P2VAR(Rte_DE_DT_CANCommErr_status, AUTOMATIC, RTE_DATA)  Runbl_VcuRx_10ms_CANCommErr_outputs_CANCommErr_outputs;
    P2VAR(Rte_DE_DT_IPM_BMS_10_DC_ChargeStates_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_VcuRx_10ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT;
    P2VAR(Rte_DE_DT_IPM_BMS_1_MainState_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_VcuRx_10ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT;
    P2VAR(Rte_DE_DT_IPM_BMS_2_BatState_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_VcuRx_10ms_IPM_BMS_2_BatState_EPT_IPM_BMS_2_BatState_EPT;
    P2VAR(Rte_DE_DT_IPM_BMS_5_BatTemp_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_VcuRx_10ms_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT;
    P2VAR(Rte_DE_DT_IPM_BMS_6_DischrgRecup_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_VcuRx_10ms_IPM_BMS_6_DischrgRecup_EPT_IPM_BMS_6_DischrgRecup_EPT;
    P2VAR(Rte_DE_DT_IPM_BMS_9_BattInfo_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_VcuRx_10ms_IPM_BMS_9_BattInfo_EPT_IPM_BMS_9_BattInfo_EPT;
    P2VAR(Rte_DE_DT_IPM_EHB_B_CHA_status, AUTOMATIC, RTE_DATA)  Runbl_VcuRx_10ms_IPM_EHB_B_CHA_IPM_EHB_B_CHA;
    P2VAR(Rte_DE_DT_IPM_ESC_7_FuncStatus_CHA_status, AUTOMATIC, RTE_DATA)  Runbl_VcuRx_10ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA;
    P2VAR(Rte_DE_DT_IPM_ESC_A_CHA_status, AUTOMATIC, RTE_DATA)  Runbl_VcuRx_10ms_IPM_ESC_A_CHA_IPM_ESC_A_CHA;
    P2VAR(Rte_DE_DT_IPM_FCM_B_CHA_status, AUTOMATIC, RTE_DATA)  Runbl_VcuRx_10ms_IPM_FCM_B_CHA_IPM_FCM_B_CHA;
    P2VAR(Rte_DE_DT_IPM_HU_B_BAC_status, AUTOMATIC, RTE_DATA)  Runbl_VcuRx_10ms_IPM_HU_B_BAC_IPM_HU_B_BAC;
    P2VAR(Rte_DE_DT_IPM_INV_1_Value_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_VcuRx_10ms_IPM_INV_1_Value_EPT_IPM_INV_1_Value_EPT;
    P2VAR(Rte_DE_DT_IPM_INV_2_Value_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_VcuRx_10ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT;
    P2VAR(Rte_DE_DT_IPM_INV_3_Value_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_VcuRx_10ms_IPM_INV_3_Value_EPT_IPM_INV_3_Value_EPT;
    P2VAR(Rte_DE_DT_IPM_INV_4_Value_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_VcuRx_10ms_IPM_INV_4_Value_EPT_IPM_INV_4_Value_EPT;
    P2VAR(Rte_DE_DT_IPM_IPU_DCC_1_State_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_VcuRx_10ms_IPM_IPU_DCC_1_State_EPT_IPM_IPU_DCC_1_State_EPT;
    P2VAR(Rte_DE_DT_IPM_IPU_OBC_1_State_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_VcuRx_10ms_IPM_IPU_OBC_1_State_EPT_IPM_IPU_OBC_1_State_EPT;
    P2VAR(Rte_DE_DT_IPM_SCS_RiSwitchSts_BOD_status, AUTOMATIC, RTE_DATA)  Runbl_VcuRx_10ms_IPM_SCS_RiSwitchSts_BOD_IPM_SCS_RiSwitchSts_BOD;
    P2VAR(Rte_DE_DT_IPM_SRS_1_Status_CHA_status, AUTOMATIC, RTE_DATA)  Runbl_VcuRx_10ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA;
    P2VAR(Rte_DE_DT_MsgActv_status, AUTOMATIC, RTE_DATA)  Runbl_VcuRx_10ms_MsgActv_outputs_MsgActv_outputs;
    P2VAR(Rte_DE_TMS2VCU_AC_2_State_Outputs_status, AUTOMATIC, RTE_DATA)  Runbl_VcuRx_10ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs;
    P2VAR(Rte_DE_Tms2Vcu_Info_status, AUTOMATIC, RTE_DATA)  Runbl_VcuRx_10ms_Tms2Vcu_Info_Tms2Vcu_Info;
    P2VAR(Rte_DE_DAG_Comm_outputs_status, AUTOMATIC, RTE_DATA)  Runbl_VcuTx_10ms_DAG_Comm_outputs_DAG_Comm_outputs;
    P2VAR(Rte_DE_DT_Vcu2BcmTms_outputs_status, AUTOMATIC, RTE_DATA)  Runbl_VcuTx_10ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs;
    P2VAR(Rte_DE_DT_Vcu2OpmBAC_outputs_status, AUTOMATIC, RTE_DATA)  Runbl_VcuTx_10ms_Vcu2OpmBAC_outputs_Vcu2OpmBAC_outputs;
    P2VAR(Rte_DE_DT_Vcu2OpmCHA_outputs_status, AUTOMATIC, RTE_DATA)  Runbl_VcuTx_10ms_Vcu2OpmCHA_outputs_Vcu2OpmCHA_outputs;
    P2VAR(Rte_DE_DT_Vcu2OpmEPT_outputs_status, AUTOMATIC, RTE_DATA)  Runbl_VcuTx_10ms_Vcu2OpmEPT_outputs_Vcu2OpmEPT_outputs;
} Rte_CDS_AppSwcVcu;

extern CONST(Rte_CDS_AppSwcVcu, RTE_CONST) Rte_Inst_AppSwcVcu;

#ifndef RTE_CORE
typedef CONSTP2CONST(Rte_CDS_AppSwcVcu, AUTOMATIC, RTE_CONST) Rte_Instance;
#endif

/** API mappings */

#ifndef RTE_CORE

#define Rte_IrvIRead_Runbl_VCU_100ms_BSW2VCU_outputs Rte_IrvIRead_Runbl_VCU_100ms_BSW2VCU_outputs

#define Rte_IrvIRead_Runbl_VCU_10ms_BSW2VCU_outputs Rte_IrvIRead_Runbl_VCU_10ms_BSW2VCU_outputs

#define Rte_IrvIRead_Runbl_VCU_20ms_BSW2VCU_outputs Rte_IrvIRead_Runbl_VCU_20ms_BSW2VCU_outputs

#define Rte_IrvIWrite_Runbl_VcuRx_10ms_BSW2VCU_outputs Rte_IrvIWrite_Runbl_VcuRx_10ms_BSW2VCU_outputs

#define Rte_IrvIRead_Runbl_VcuTx_10ms_BSW2VCU_outputs Rte_IrvIRead_Runbl_VcuTx_10ms_BSW2VCU_outputs

#define Rte_IrvIRead_Runbl_VCU_100ms_Bcm2VcuTms_outputs Rte_IrvIRead_Runbl_VCU_100ms_Bcm2VcuTms_outputs

#define Rte_IrvIRead_Runbl_VCU_20ms_Bcm2VcuTms_outputs Rte_IrvIRead_Runbl_VCU_20ms_Bcm2VcuTms_outputs

#define Rte_IrvIWrite_Runbl_VcuRx_10ms_Bcm2VcuTms_outputs Rte_IrvIWrite_Runbl_VcuRx_10ms_Bcm2VcuTms_outputs

#define Rte_IrvIRead_Runbl_VcuTx_10ms_Bcm2VcuTms_outputs Rte_IrvIRead_Runbl_VcuTx_10ms_Bcm2VcuTms_outputs

#define Rte_IrvIRead_Runbl_VCU_100ms_CANCommErr_outputs Rte_IrvIRead_Runbl_VCU_100ms_CANCommErr_outputs

#define Rte_IrvIRead_Runbl_VCU_20ms_CANCommErr_outputs Rte_IrvIRead_Runbl_VCU_20ms_CANCommErr_outputs

#define Rte_IrvIWrite_Runbl_VcuRx_10ms_CANCommErr_outputs Rte_IrvIWrite_Runbl_VcuRx_10ms_CANCommErr_outputs

#define Rte_IrvIWrite_AppSwcVcu_Init_DAG_Comm_outputsIRV Rte_IrvIWrite_AppSwcVcu_Init_DAG_Comm_outputsIRV

#define Rte_IrvIWrite_Runbl_VCU_20ms_DAG_Comm_outputsIRV Rte_IrvIWrite_Runbl_VCU_20ms_DAG_Comm_outputsIRV

#define Rte_IrvIRead_Runbl_VcuTx_10ms_DAG_Comm_outputsIRV Rte_IrvIRead_Runbl_VcuTx_10ms_DAG_Comm_outputsIRV

#define Rte_IrvIWrite_AppSwcVcu_Init_DAG_FltActn_outputs Rte_IrvIWrite_AppSwcVcu_Init_DAG_FltActn_outputs

#define Rte_IrvIRead_Runbl_VCU_100ms_DAG_FltActn_outputs Rte_IrvIRead_Runbl_VCU_100ms_DAG_FltActn_outputs

#define Rte_IrvIRead_Runbl_VCU_10ms_DAG_FltActn_outputs Rte_IrvIRead_Runbl_VCU_10ms_DAG_FltActn_outputs

#define Rte_IrvIWrite_Runbl_VCU_20ms_DAG_FltActn_outputs Rte_IrvIWrite_Runbl_VCU_20ms_DAG_FltActn_outputs

#define Rte_IrvIRead_Runbl_VcuTx_10ms_DAG_FltActn_outputs Rte_IrvIRead_Runbl_VcuTx_10ms_DAG_FltActn_outputs

#define Rte_IrvIWrite_AppSwcVcu_Init_DAG_Other_outputs Rte_IrvIWrite_AppSwcVcu_Init_DAG_Other_outputs

#define Rte_IrvIRead_Runbl_VCU_100ms_DAG_Other_outputs Rte_IrvIRead_Runbl_VCU_100ms_DAG_Other_outputs

#define Rte_IrvIWrite_Runbl_VCU_20ms_DAG_Other_outputs Rte_IrvIWrite_Runbl_VCU_20ms_DAG_Other_outputs

#define Rte_IrvIWrite_AppSwcVcu_Init_DAG_Sensor10ms_outputs Rte_IrvIWrite_AppSwcVcu_Init_DAG_Sensor10ms_outputs

#define Rte_IrvIRead_Runbl_VCU_10ms_DAG_Sensor10ms_outputs Rte_IrvIRead_Runbl_VCU_10ms_DAG_Sensor10ms_outputs

#define Rte_IrvIWrite_Runbl_VCU_20ms_DAG_Sensor10ms_outputs Rte_IrvIWrite_Runbl_VCU_20ms_DAG_Sensor10ms_outputs

#define Rte_IrvIWrite_AppSwcVcu_Init_DSA_outputs Rte_IrvIWrite_AppSwcVcu_Init_DSA_outputs

#define Rte_IrvIWrite_Runbl_VCU_100ms_DSA_outputs Rte_IrvIWrite_Runbl_VCU_100ms_DSA_outputs

#define Rte_IrvIRead_Runbl_VCU_10ms_DSA_outputs Rte_IrvIRead_Runbl_VCU_10ms_DSA_outputs

#define Rte_IrvIWrite_AppSwcVcu_Init_EMS_outputs Rte_IrvIWrite_AppSwcVcu_Init_EMS_outputs

#define Rte_IrvIRead_Runbl_VCU_100ms_EMS_outputs Rte_IrvIRead_Runbl_VCU_100ms_EMS_outputs

#define Rte_IrvIRead_Runbl_VCU_10ms_EMS_outputs Rte_IrvIRead_Runbl_VCU_10ms_EMS_outputs

#define Rte_IrvIWrite_Runbl_VCU_20ms_EMS_outputs Rte_IrvIWrite_Runbl_VCU_20ms_EMS_outputs

#define Rte_IrvIRead_Runbl_VcuTx_10ms_EMS_outputs Rte_IrvIRead_Runbl_VcuTx_10ms_EMS_outputs

#define Rte_IrvIWrite_AppSwcVcu_Init_GSM_outputs Rte_IrvIWrite_AppSwcVcu_Init_GSM_outputs

#define Rte_IrvIRead_Runbl_VCU_100ms_GSM_outputs Rte_IrvIRead_Runbl_VCU_100ms_GSM_outputs

#define Rte_IrvIRead_Runbl_VCU_10ms_GSM_outputs Rte_IrvIRead_Runbl_VCU_10ms_GSM_outputs

#define Rte_IrvIWrite_Runbl_VCU_20ms_GSM_outputs Rte_IrvIWrite_Runbl_VCU_20ms_GSM_outputs

#define Rte_IrvIRead_Runbl_VcuTx_10ms_GSM_outputs Rte_IrvIRead_Runbl_VcuTx_10ms_GSM_outputs

#define Rte_IrvIWrite_AppSwcVcu_Init_HMI_outputs Rte_IrvIWrite_AppSwcVcu_Init_HMI_outputs

#define Rte_IrvIWrite_Runbl_VCU_100ms_HMI_outputs Rte_IrvIWrite_Runbl_VCU_100ms_HMI_outputs

#define Rte_IrvIRead_Runbl_VcuTx_10ms_HMI_outputs Rte_IrvIRead_Runbl_VcuTx_10ms_HMI_outputs

#define Rte_IrvIWrite_AppSwcVcu_Init_HVM_outputs Rte_IrvIWrite_AppSwcVcu_Init_HVM_outputs

#define Rte_IrvIRead_Runbl_VCU_100ms_HVM_outputs Rte_IrvIRead_Runbl_VCU_100ms_HVM_outputs

#define Rte_IrvIRead_Runbl_VCU_10ms_HVM_outputs Rte_IrvIRead_Runbl_VCU_10ms_HVM_outputs

#define Rte_IrvIWrite_Runbl_VCU_20ms_HVM_outputs Rte_IrvIWrite_Runbl_VCU_20ms_HVM_outputs

#define Rte_IrvIRead_Runbl_VcuTx_10ms_HVM_outputs Rte_IrvIRead_Runbl_VcuTx_10ms_HVM_outputs

#define Rte_IrvIRead_Runbl_VCU_100ms_HardWire_Input_VCU Rte_IrvIRead_Runbl_VCU_100ms_HardWire_Input_VCU

#define Rte_IrvIRead_Runbl_VCU_10ms_HardWire_Input_VCU Rte_IrvIRead_Runbl_VCU_10ms_HardWire_Input_VCU

#define Rte_IrvIRead_Runbl_VCU_20ms_HardWire_Input_VCU Rte_IrvIRead_Runbl_VCU_20ms_HardWire_Input_VCU

#define Rte_IrvIWrite_Runbl_VcuRx_10ms_HardWire_Input_VCU Rte_IrvIWrite_Runbl_VcuRx_10ms_HardWire_Input_VCU

#define Rte_IrvIWrite_AppSwcVcu_Init_IPC_outputs Rte_IrvIWrite_AppSwcVcu_Init_IPC_outputs

#define Rte_IrvIRead_Runbl_VCU_100ms_IPC_outputs Rte_IrvIRead_Runbl_VCU_100ms_IPC_outputs

#define Rte_IrvIWrite_Runbl_VCU_10ms_IPC_outputs Rte_IrvIWrite_Runbl_VCU_10ms_IPC_outputs

#define Rte_IrvIRead_Runbl_VCU_20ms_IPC_outputs Rte_IrvIRead_Runbl_VCU_20ms_IPC_outputs

#define Rte_IrvIRead_Runbl_VcuTx_10ms_IPC_outputs Rte_IrvIRead_Runbl_VcuTx_10ms_IPC_outputs

#define Rte_IrvIRead_Runbl_VCU_100ms_IPM_BMS_10_DC_ChargeStates_EPT Rte_IrvIRead_Runbl_VCU_100ms_IPM_BMS_10_DC_ChargeStates_EPT

#define Rte_IrvIRead_Runbl_VCU_10ms_IPM_BMS_10_DC_ChargeStates_EPT Rte_IrvIRead_Runbl_VCU_10ms_IPM_BMS_10_DC_ChargeStates_EPT

#define Rte_IrvIRead_Runbl_VCU_20ms_IPM_BMS_10_DC_ChargeStates_EPT Rte_IrvIRead_Runbl_VCU_20ms_IPM_BMS_10_DC_ChargeStates_EPT

#define Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_BMS_10_DC_ChargeStates_EPT Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_BMS_10_DC_ChargeStates_EPT

#define Rte_IrvIRead_Runbl_VCU_100ms_IPM_BMS_1_MainState_EPT Rte_IrvIRead_Runbl_VCU_100ms_IPM_BMS_1_MainState_EPT

#define Rte_IrvIRead_Runbl_VCU_20ms_IPM_BMS_1_MainState_EPT Rte_IrvIRead_Runbl_VCU_20ms_IPM_BMS_1_MainState_EPT

#define Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_BMS_1_MainState_EPT Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_BMS_1_MainState_EPT

#define Rte_IrvIRead_Runbl_VCU_100ms_IPM_BMS_2_BatState_EPT Rte_IrvIRead_Runbl_VCU_100ms_IPM_BMS_2_BatState_EPT

#define Rte_IrvIRead_Runbl_VCU_10ms_IPM_BMS_2_BatState_EPT Rte_IrvIRead_Runbl_VCU_10ms_IPM_BMS_2_BatState_EPT

#define Rte_IrvIRead_Runbl_VCU_20ms_IPM_BMS_2_BatState_EPT Rte_IrvIRead_Runbl_VCU_20ms_IPM_BMS_2_BatState_EPT

#define Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_BMS_2_BatState_EPT Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_BMS_2_BatState_EPT

#define Rte_IrvIRead_Runbl_VCU_100ms_IPM_BMS_5_BatTemp_EPT Rte_IrvIRead_Runbl_VCU_100ms_IPM_BMS_5_BatTemp_EPT

#define Rte_IrvIRead_Runbl_VCU_20ms_IPM_BMS_5_BatTemp_EPT Rte_IrvIRead_Runbl_VCU_20ms_IPM_BMS_5_BatTemp_EPT

#define Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_BMS_5_BatTemp_EPT Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_BMS_5_BatTemp_EPT

#define Rte_IrvIRead_Runbl_VCU_20ms_IPM_BMS_6_DischrgRecup_EPT Rte_IrvIRead_Runbl_VCU_20ms_IPM_BMS_6_DischrgRecup_EPT

#define Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_BMS_6_DischrgRecup_EPT Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_BMS_6_DischrgRecup_EPT

#define Rte_IrvIRead_Runbl_VCU_100ms_IPM_BMS_9_BattInfo_EPT Rte_IrvIRead_Runbl_VCU_100ms_IPM_BMS_9_BattInfo_EPT

#define Rte_IrvIRead_Runbl_VCU_20ms_IPM_BMS_9_BattInfo_EPT Rte_IrvIRead_Runbl_VCU_20ms_IPM_BMS_9_BattInfo_EPT

#define Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_BMS_9_BattInfo_EPT Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_BMS_9_BattInfo_EPT

#define Rte_IrvIRead_Runbl_VCU_10ms_IPM_EHB_B_CHA Rte_IrvIRead_Runbl_VCU_10ms_IPM_EHB_B_CHA

#define Rte_IrvIRead_Runbl_VCU_20ms_IPM_EHB_B_CHA Rte_IrvIRead_Runbl_VCU_20ms_IPM_EHB_B_CHA

#define Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_EHB_B_CHA Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_EHB_B_CHA

#define Rte_IrvIRead_Runbl_VCU_100ms_IPM_ESC_7_FuncStatus_CHA Rte_IrvIRead_Runbl_VCU_100ms_IPM_ESC_7_FuncStatus_CHA

#define Rte_IrvIRead_Runbl_VCU_10ms_IPM_ESC_7_FuncStatus_CHA Rte_IrvIRead_Runbl_VCU_10ms_IPM_ESC_7_FuncStatus_CHA

#define Rte_IrvIRead_Runbl_VCU_20ms_IPM_ESC_7_FuncStatus_CHA Rte_IrvIRead_Runbl_VCU_20ms_IPM_ESC_7_FuncStatus_CHA

#define Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_ESC_7_FuncStatus_CHA Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_ESC_7_FuncStatus_CHA

#define Rte_IrvIRead_Runbl_VCU_100ms_IPM_ESC_A_CHA Rte_IrvIRead_Runbl_VCU_100ms_IPM_ESC_A_CHA

#define Rte_IrvIRead_Runbl_VCU_10ms_IPM_ESC_A_CHA Rte_IrvIRead_Runbl_VCU_10ms_IPM_ESC_A_CHA

#define Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_ESC_A_CHA Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_ESC_A_CHA

#define Rte_IrvIRead_Runbl_VCU_10ms_IPM_FCM_B_CHA Rte_IrvIRead_Runbl_VCU_10ms_IPM_FCM_B_CHA

#define Rte_IrvIRead_Runbl_VCU_20ms_IPM_FCM_B_CHA Rte_IrvIRead_Runbl_VCU_20ms_IPM_FCM_B_CHA

#define Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_FCM_B_CHA Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_FCM_B_CHA

#define Rte_IrvIRead_Runbl_VCU_100ms_IPM_HU_B_BAC Rte_IrvIRead_Runbl_VCU_100ms_IPM_HU_B_BAC

#define Rte_IrvIRead_Runbl_VCU_10ms_IPM_HU_B_BAC Rte_IrvIRead_Runbl_VCU_10ms_IPM_HU_B_BAC

#define Rte_IrvIRead_Runbl_VCU_20ms_IPM_HU_B_BAC Rte_IrvIRead_Runbl_VCU_20ms_IPM_HU_B_BAC

#define Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_HU_B_BAC Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_HU_B_BAC

#define Rte_IrvIRead_Runbl_VCU_10ms_IPM_INV_1_Value_EPT Rte_IrvIRead_Runbl_VCU_10ms_IPM_INV_1_Value_EPT

#define Rte_IrvIRead_Runbl_VCU_20ms_IPM_INV_1_Value_EPT Rte_IrvIRead_Runbl_VCU_20ms_IPM_INV_1_Value_EPT

#define Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_INV_1_Value_EPT Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_INV_1_Value_EPT

#define Rte_IrvIRead_Runbl_VCU_10ms_IPM_INV_2_Value_EPT Rte_IrvIRead_Runbl_VCU_10ms_IPM_INV_2_Value_EPT

#define Rte_IrvIRead_Runbl_VCU_20ms_IPM_INV_2_Value_EPT Rte_IrvIRead_Runbl_VCU_20ms_IPM_INV_2_Value_EPT

#define Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_INV_2_Value_EPT Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_INV_2_Value_EPT

#define Rte_IrvIRead_Runbl_VcuTx_10ms_IPM_INV_2_Value_EPT Rte_IrvIRead_Runbl_VcuTx_10ms_IPM_INV_2_Value_EPT

#define Rte_IrvIRead_Runbl_VCU_100ms_IPM_INV_3_Value_EPT Rte_IrvIRead_Runbl_VCU_100ms_IPM_INV_3_Value_EPT

#define Rte_IrvIRead_Runbl_VCU_10ms_IPM_INV_3_Value_EPT Rte_IrvIRead_Runbl_VCU_10ms_IPM_INV_3_Value_EPT

#define Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_INV_3_Value_EPT Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_INV_3_Value_EPT

#define Rte_IrvIRead_Runbl_VCU_10ms_IPM_INV_4_Value_EPT Rte_IrvIRead_Runbl_VCU_10ms_IPM_INV_4_Value_EPT

#define Rte_IrvIRead_Runbl_VCU_20ms_IPM_INV_4_Value_EPT Rte_IrvIRead_Runbl_VCU_20ms_IPM_INV_4_Value_EPT

#define Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_INV_4_Value_EPT Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_INV_4_Value_EPT

#define Rte_IrvIRead_Runbl_VCU_100ms_IPM_IPU_DCC_1_State_EPT Rte_IrvIRead_Runbl_VCU_100ms_IPM_IPU_DCC_1_State_EPT

#define Rte_IrvIRead_Runbl_VCU_20ms_IPM_IPU_DCC_1_State_EPT Rte_IrvIRead_Runbl_VCU_20ms_IPM_IPU_DCC_1_State_EPT

#define Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_IPU_DCC_1_State_EPT Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_IPU_DCC_1_State_EPT

#define Rte_IrvIRead_Runbl_VCU_100ms_IPM_IPU_OBC_1_State_EPT Rte_IrvIRead_Runbl_VCU_100ms_IPM_IPU_OBC_1_State_EPT

#define Rte_IrvIRead_Runbl_VCU_10ms_IPM_IPU_OBC_1_State_EPT Rte_IrvIRead_Runbl_VCU_10ms_IPM_IPU_OBC_1_State_EPT

#define Rte_IrvIRead_Runbl_VCU_20ms_IPM_IPU_OBC_1_State_EPT Rte_IrvIRead_Runbl_VCU_20ms_IPM_IPU_OBC_1_State_EPT

#define Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_IPU_OBC_1_State_EPT Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_IPU_OBC_1_State_EPT

#define Rte_IrvIRead_Runbl_VCU_100ms_IPM_SCS_RiSwitchSts_BOD Rte_IrvIRead_Runbl_VCU_100ms_IPM_SCS_RiSwitchSts_BOD

#define Rte_IrvIRead_Runbl_VCU_10ms_IPM_SCS_RiSwitchSts_BOD Rte_IrvIRead_Runbl_VCU_10ms_IPM_SCS_RiSwitchSts_BOD

#define Rte_IrvIRead_Runbl_VCU_20ms_IPM_SCS_RiSwitchSts_BOD Rte_IrvIRead_Runbl_VCU_20ms_IPM_SCS_RiSwitchSts_BOD

#define Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_SCS_RiSwitchSts_BOD Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_SCS_RiSwitchSts_BOD

#define Rte_IrvIRead_Runbl_VCU_10ms_IPM_SRS_1_Status_CHA Rte_IrvIRead_Runbl_VCU_10ms_IPM_SRS_1_Status_CHA

#define Rte_IrvIRead_Runbl_VCU_20ms_IPM_SRS_1_Status_CHA Rte_IrvIRead_Runbl_VCU_20ms_IPM_SRS_1_Status_CHA

#define Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_SRS_1_Status_CHA Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_SRS_1_Status_CHA

#define Rte_IrvIRead_Runbl_VCU_10ms_MsgActv_outputs Rte_IrvIRead_Runbl_VCU_10ms_MsgActv_outputs

#define Rte_IrvIRead_Runbl_VCU_20ms_MsgActv_outputs Rte_IrvIRead_Runbl_VCU_20ms_MsgActv_outputs

#define Rte_IrvIWrite_Runbl_VcuRx_10ms_MsgActv_outputs Rte_IrvIWrite_Runbl_VcuRx_10ms_MsgActv_outputs

#define Rte_IrvIWrite_AppSwcVcu_Init_NVM_Imdt_outputs Rte_IrvIWrite_AppSwcVcu_Init_NVM_Imdt_outputs

#define Rte_IrvIRead_Runbl_VCU_100ms_NVM_Imdt_outputs Rte_IrvIRead_Runbl_VCU_100ms_NVM_Imdt_outputs

#define Rte_IrvIRead_Runbl_VCU_10ms_NVM_Imdt_outputs Rte_IrvIRead_Runbl_VCU_10ms_NVM_Imdt_outputs

#define Rte_IrvIRead_Runbl_VCU_20ms_NVM_Imdt_outputs Rte_IrvIRead_Runbl_VCU_20ms_NVM_Imdt_outputs

#define Rte_IrvIWrite_Runbl_VcuRx_10ms_NVM_Imdt_outputs Rte_IrvIWrite_Runbl_VcuRx_10ms_NVM_Imdt_outputs

#define Rte_IrvIRead_Runbl_VcuTx_10ms_NVM_Imdt_outputs Rte_IrvIRead_Runbl_VcuTx_10ms_NVM_Imdt_outputs

#define Rte_IrvIWrite_AppSwcVcu_Init_NVM_outputs Rte_IrvIWrite_AppSwcVcu_Init_NVM_outputs

#define Rte_IrvIRead_Runbl_VCU_100ms_NVM_outputs Rte_IrvIRead_Runbl_VCU_100ms_NVM_outputs

#define Rte_IrvIRead_Runbl_VCU_10ms_NVM_outputs Rte_IrvIRead_Runbl_VCU_10ms_NVM_outputs

#define Rte_IrvIRead_Runbl_VCU_20ms_NVM_outputs Rte_IrvIRead_Runbl_VCU_20ms_NVM_outputs

#define Rte_IrvIWrite_Runbl_VcuRx_10ms_NVM_outputs Rte_IrvIWrite_Runbl_VcuRx_10ms_NVM_outputs

#define Rte_IrvIWrite_AppSwcVcu_Init_RME_outputs Rte_IrvIWrite_AppSwcVcu_Init_RME_outputs

#define Rte_IrvIWrite_Runbl_VCU_100ms_RME_outputs Rte_IrvIWrite_Runbl_VCU_100ms_RME_outputs

#define Rte_IrvIRead_Runbl_VcuTx_10ms_RME_outputs Rte_IrvIRead_Runbl_VcuTx_10ms_RME_outputs

#define Rte_IrvIWrite_AppSwcVcu_Init_SIBS_Output Rte_IrvIWrite_AppSwcVcu_Init_SIBS_Output

#define Rte_IrvIWrite_Runbl_VCU_100ms_SIBS_Output Rte_IrvIWrite_Runbl_VCU_100ms_SIBS_Output

#define Rte_IrvIRead_Runbl_VCU_20ms_SIBS_Output Rte_IrvIRead_Runbl_VCU_20ms_SIBS_Output

#define Rte_IrvIRead_Runbl_VcuTx_10ms_SIBS_Output Rte_IrvIRead_Runbl_VcuTx_10ms_SIBS_Output

#define Rte_IrvIWrite_AppSwcVcu_Init_TBOX_outputs Rte_IrvIWrite_AppSwcVcu_Init_TBOX_outputs

#define Rte_IrvIWrite_Runbl_VCU_100ms_TBOX_outputs Rte_IrvIWrite_Runbl_VCU_100ms_TBOX_outputs

#define Rte_IrvIRead_Runbl_VCU_10ms_TBOX_outputs Rte_IrvIRead_Runbl_VCU_10ms_TBOX_outputs

#define Rte_IrvIRead_Runbl_VCU_20ms_TBOX_outputs Rte_IrvIRead_Runbl_VCU_20ms_TBOX_outputs

#define Rte_IrvIRead_Runbl_VcuTx_10ms_TBOX_outputs Rte_IrvIRead_Runbl_VcuTx_10ms_TBOX_outputs

#define Rte_IrvIRead_Runbl_VCU_20ms_TMS2VCU_AC_2_State_Outputs Rte_IrvIRead_Runbl_VCU_20ms_TMS2VCU_AC_2_State_Outputs

#define Rte_IrvIWrite_Runbl_VcuRx_10ms_TMS2VCU_AC_2_State_Outputs Rte_IrvIWrite_Runbl_VcuRx_10ms_TMS2VCU_AC_2_State_Outputs

#define Rte_IrvIRead_Runbl_VCU_20ms_Tms2Vcu_Info Rte_IrvIRead_Runbl_VCU_20ms_Tms2Vcu_Info

#define Rte_IrvIWrite_Runbl_VcuRx_10ms_Tms2Vcu_Info Rte_IrvIWrite_Runbl_VcuRx_10ms_Tms2Vcu_Info

#define Rte_IrvIRead_Runbl_VcuTx_10ms_Tms2Vcu_Info Rte_IrvIRead_Runbl_VcuTx_10ms_Tms2Vcu_Info

#define Rte_IrvIWrite_Runbl_VCU_20ms_VDAG_VCUErrCode_enum Rte_IrvIWrite_Runbl_VCU_20ms_VDAG_VCUErrCode_enum

#define Rte_IrvIRead_Runbl_VcuTx_10ms_VDAG_VCUErrCode_enum Rte_IrvIRead_Runbl_VcuTx_10ms_VDAG_VCUErrCode_enum

#define Rte_IrvIWrite_AppSwcVcu_Init_VDAG_VCUFltLvl_enum Rte_IrvIWrite_AppSwcVcu_Init_VDAG_VCUFltLvl_enum

#define Rte_IrvIWrite_Runbl_VCU_20ms_VDAG_VCUFltLvl_enum Rte_IrvIWrite_Runbl_VCU_20ms_VDAG_VCUFltLvl_enum

#define Rte_IrvIRead_Runbl_VcuTx_10ms_VDAG_VCUFltLvl_enum Rte_IrvIRead_Runbl_VcuTx_10ms_VDAG_VCUFltLvl_enum

#define Rte_IrvIWrite_AppSwcVcu_Init_VSO_outputs Rte_IrvIWrite_AppSwcVcu_Init_VSO_outputs

#define Rte_IrvIWrite_Runbl_VCU_10ms_VSO_outputs Rte_IrvIWrite_Runbl_VCU_10ms_VSO_outputs

#define Rte_IrvIRead_Runbl_VcuTx_10ms_VSO_outputs Rte_IrvIRead_Runbl_VcuTx_10ms_VSO_outputs

#define Rte_IrvIWrite_AppSwcVcu_Init_VTM_outputs Rte_IrvIWrite_AppSwcVcu_Init_VTM_outputs

#define Rte_IrvIRead_Runbl_VCU_100ms_VTM_outputs Rte_IrvIRead_Runbl_VCU_100ms_VTM_outputs

#define Rte_IrvIWrite_Runbl_VCU_10ms_VTM_outputs Rte_IrvIWrite_Runbl_VCU_10ms_VTM_outputs

#define Rte_IrvIRead_Runbl_VCU_20ms_VTM_outputs Rte_IrvIRead_Runbl_VCU_20ms_VTM_outputs

#define Rte_IrvIRead_Runbl_VcuTx_10ms_VTM_outputs Rte_IrvIRead_Runbl_VcuTx_10ms_VTM_outputs

#define Rte_IrvIRead_Runbl_VCU_10ms_VehCfg_outputs Rte_IrvIRead_Runbl_VCU_10ms_VehCfg_outputs

#define Rte_IrvIWrite_Runbl_VcuRx_10ms_VehCfg_outputs Rte_IrvIWrite_Runbl_VcuRx_10ms_VehCfg_outputs

#define Rte_IRead_Runbl_VCU_100ms_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs() (&Rte_Inst_AppSwcVcu.Runbl_VCU_100ms_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs->value)

#define Rte_IRead_Runbl_VCU_100ms_TMS2VCU_PPV_outputs_TMS2VCU_PPV_outputs() (&Rte_Inst_AppSwcVcu.Runbl_VCU_100ms_TMS2VCU_PPV_outputs_TMS2VCU_PPV_outputs->value)

#define Rte_IRead_Runbl_VCU_10ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD() (&Rte_Inst_AppSwcVcu.Runbl_VCU_10ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD->value)

#define Rte_IRead_Runbl_VCU_10ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA() (&Rte_Inst_AppSwcVcu.Runbl_VCU_10ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA->value)

#define Rte_IRead_Runbl_VCU_20ms_CANCommCRCFlt_outputs_CANCommCRCFlt_outputs() (&Rte_Inst_AppSwcVcu.Runbl_VCU_20ms_CANCommCRCFlt_outputs_CANCommCRCFlt_outputs->value)

#define Rte_IRead_Runbl_VCU_20ms_IPM_BMS_3_DC_ChargeState_EPT_IPM_BMS_3_DC_ChargeState_EPT() (&Rte_Inst_AppSwcVcu.Runbl_VCU_20ms_IPM_BMS_3_DC_ChargeState_EPT_IPM_BMS_3_DC_ChargeState_EPT->value)

#define Rte_IRead_Runbl_VCU_20ms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT() (&Rte_Inst_AppSwcVcu.Runbl_VCU_20ms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT->value)

#define Rte_IRead_Runbl_VCU_20ms_IPM_BMS_7_CellVolt_EPT_IPM_BMS_7_CellVolt_EPT() (&Rte_Inst_AppSwcVcu.Runbl_VCU_20ms_IPM_BMS_7_CellVolt_EPT_IPM_BMS_7_CellVolt_EPT->value)

#define Rte_IRead_Runbl_VCU_20ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD() (&Rte_Inst_AppSwcVcu.Runbl_VCU_20ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD->value)

#define Rte_IRead_Runbl_VCU_20ms_IPM_ICU_2_Odo_BAC_IPM_ICU_2_Odo_BAC() (&Rte_Inst_AppSwcVcu.Runbl_VCU_20ms_IPM_ICU_2_Odo_BAC_IPM_ICU_2_Odo_BAC->value)

#define Rte_IRead_Runbl_VCU_20ms_IPM_IPU_DCC_2_ChrgInValue_EPT_IPM_IPU_DCC_2_ChrgInValue_EPT() (&Rte_Inst_AppSwcVcu.Runbl_VCU_20ms_IPM_IPU_DCC_2_ChrgInValue_EPT_IPM_IPU_DCC_2_ChrgInValue_EPT->value)

#define Rte_IRead_Runbl_VCU_20ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT() (&Rte_Inst_AppSwcVcu.Runbl_VCU_20ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT->value)

#define Rte_IRead_Runbl_VCU_20ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC() (&Rte_Inst_AppSwcVcu.Runbl_VCU_20ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC->value)

#define Rte_IRead_Runbl_VcuRx_10ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs() (&Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs->value)

#define Rte_IRead_Runbl_VcuRx_10ms_CANCommErr_outputs_CANCommErr_outputs() (&Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_CANCommErr_outputs_CANCommErr_outputs->value)

#define Rte_IRead_Runbl_VcuRx_10ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT() (&Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT->value)

#define Rte_IRead_Runbl_VcuRx_10ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT() (&Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT->value)

#define Rte_IRead_Runbl_VcuRx_10ms_IPM_BMS_2_BatState_EPT_IPM_BMS_2_BatState_EPT() (&Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_BMS_2_BatState_EPT_IPM_BMS_2_BatState_EPT->value)

#define Rte_IRead_Runbl_VcuRx_10ms_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT() (&Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT->value)

#define Rte_IRead_Runbl_VcuRx_10ms_IPM_BMS_6_DischrgRecup_EPT_IPM_BMS_6_DischrgRecup_EPT() (&Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_BMS_6_DischrgRecup_EPT_IPM_BMS_6_DischrgRecup_EPT->value)

#define Rte_IRead_Runbl_VcuRx_10ms_IPM_BMS_9_BattInfo_EPT_IPM_BMS_9_BattInfo_EPT() (&Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_BMS_9_BattInfo_EPT_IPM_BMS_9_BattInfo_EPT->value)

#define Rte_IRead_Runbl_VcuRx_10ms_IPM_EHB_B_CHA_IPM_EHB_B_CHA() (&Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_EHB_B_CHA_IPM_EHB_B_CHA->value)

#define Rte_IRead_Runbl_VcuRx_10ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA() (&Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA->value)

#define Rte_IRead_Runbl_VcuRx_10ms_IPM_ESC_A_CHA_IPM_ESC_A_CHA() (&Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_ESC_A_CHA_IPM_ESC_A_CHA->value)

#define Rte_IRead_Runbl_VcuRx_10ms_IPM_FCM_B_CHA_IPM_FCM_B_CHA() (&Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_FCM_B_CHA_IPM_FCM_B_CHA->value)

#define Rte_IRead_Runbl_VcuRx_10ms_IPM_HU_B_BAC_IPM_HU_B_BAC() (&Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_HU_B_BAC_IPM_HU_B_BAC->value)

#define Rte_IRead_Runbl_VcuRx_10ms_IPM_INV_1_Value_EPT_IPM_INV_1_Value_EPT() (&Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_INV_1_Value_EPT_IPM_INV_1_Value_EPT->value)

#define Rte_IRead_Runbl_VcuRx_10ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT() (&Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT->value)

#define Rte_IRead_Runbl_VcuRx_10ms_IPM_INV_3_Value_EPT_IPM_INV_3_Value_EPT() (&Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_INV_3_Value_EPT_IPM_INV_3_Value_EPT->value)

#define Rte_IRead_Runbl_VcuRx_10ms_IPM_INV_4_Value_EPT_IPM_INV_4_Value_EPT() (&Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_INV_4_Value_EPT_IPM_INV_4_Value_EPT->value)

#define Rte_IRead_Runbl_VcuRx_10ms_IPM_IPU_DCC_1_State_EPT_IPM_IPU_DCC_1_State_EPT() (&Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_IPU_DCC_1_State_EPT_IPM_IPU_DCC_1_State_EPT->value)

#define Rte_IRead_Runbl_VcuRx_10ms_IPM_IPU_OBC_1_State_EPT_IPM_IPU_OBC_1_State_EPT() (&Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_IPU_OBC_1_State_EPT_IPM_IPU_OBC_1_State_EPT->value)

#define Rte_IRead_Runbl_VcuRx_10ms_IPM_SCS_RiSwitchSts_BOD_IPM_SCS_RiSwitchSts_BOD() (&Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_SCS_RiSwitchSts_BOD_IPM_SCS_RiSwitchSts_BOD->value)

#define Rte_IRead_Runbl_VcuRx_10ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA() (&Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA->value)

#define Rte_IRead_Runbl_VcuRx_10ms_MsgActv_outputs_MsgActv_outputs() (&Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_MsgActv_outputs_MsgActv_outputs->value)

#define Rte_IRead_Runbl_VcuRx_10ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs() (&Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs->value)

#define Rte_IRead_Runbl_VcuRx_10ms_Tms2Vcu_Info_Tms2Vcu_Info() (&Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_Tms2Vcu_Info_Tms2Vcu_Info->value)

#define Rte_IWrite_Runbl_VcuTx_10ms_DAG_Comm_outputs_DAG_Comm_outputs(data) (Rte_Inst_AppSwcVcu.Runbl_VcuTx_10ms_DAG_Comm_outputs_DAG_Comm_outputs->value = *(data))

#define Rte_IWriteRef_Runbl_VcuTx_10ms_DAG_Comm_outputs_DAG_Comm_outputs() (&Rte_Inst_AppSwcVcu.Runbl_VcuTx_10ms_DAG_Comm_outputs_DAG_Comm_outputs->value)

#define Rte_IWrite_Runbl_VcuTx_10ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs(data) (Rte_Inst_AppSwcVcu.Runbl_VcuTx_10ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs->value = *(data))

#define Rte_IWriteRef_Runbl_VcuTx_10ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs() (&Rte_Inst_AppSwcVcu.Runbl_VcuTx_10ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs->value)

#define Rte_IWrite_Runbl_VcuTx_10ms_Vcu2OpmBAC_outputs_Vcu2OpmBAC_outputs(data) (Rte_Inst_AppSwcVcu.Runbl_VcuTx_10ms_Vcu2OpmBAC_outputs_Vcu2OpmBAC_outputs->value = *(data))

#define Rte_IWriteRef_Runbl_VcuTx_10ms_Vcu2OpmBAC_outputs_Vcu2OpmBAC_outputs() (&Rte_Inst_AppSwcVcu.Runbl_VcuTx_10ms_Vcu2OpmBAC_outputs_Vcu2OpmBAC_outputs->value)

#define Rte_IWrite_Runbl_VcuTx_10ms_Vcu2OpmCHA_outputs_Vcu2OpmCHA_outputs(data) (Rte_Inst_AppSwcVcu.Runbl_VcuTx_10ms_Vcu2OpmCHA_outputs_Vcu2OpmCHA_outputs->value = *(data))

#define Rte_IWriteRef_Runbl_VcuTx_10ms_Vcu2OpmCHA_outputs_Vcu2OpmCHA_outputs() (&Rte_Inst_AppSwcVcu.Runbl_VcuTx_10ms_Vcu2OpmCHA_outputs_Vcu2OpmCHA_outputs->value)

#define Rte_IWrite_Runbl_VcuTx_10ms_Vcu2OpmEPT_outputs_Vcu2OpmEPT_outputs(data) (Rte_Inst_AppSwcVcu.Runbl_VcuTx_10ms_Vcu2OpmEPT_outputs_Vcu2OpmEPT_outputs->value = *(data))

#define Rte_IWriteRef_Runbl_VcuTx_10ms_Vcu2OpmEPT_outputs_Vcu2OpmEPT_outputs() (&Rte_Inst_AppSwcVcu.Runbl_VcuTx_10ms_Vcu2OpmEPT_outputs_Vcu2OpmEPT_outputs->value)

#endif

/*******************************************************************************
 **                        Global Function Declarations                       **
******************************************************************************/

/** API functions */

void Rte_Runbl_VCU_100ms(void);

void Rte_Runbl_VCU_10ms(void);

void Rte_Runbl_VCU_20ms(void);

void Rte_Runbl_VcuRx_10ms(void);

void Rte_Runbl_VcuTx_10ms(void);

void Rte_AppSwcVcu_Init(void);

BSW2VCU_outputs* Rte_IrvIRead_Runbl_VCU_100ms_BSW2VCU_outputs(void);

BSW2VCU_outputs* Rte_IrvIRead_Runbl_VCU_10ms_BSW2VCU_outputs(void);

BSW2VCU_outputs* Rte_IrvIRead_Runbl_VCU_20ms_BSW2VCU_outputs(void);

void Rte_IrvIWrite_Runbl_VcuRx_10ms_BSW2VCU_outputs(BSW2VCU_outputs* data);

BSW2VCU_outputs * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_BSW2VCU_outputs(void);

BSW2VCU_outputs* Rte_IrvIRead_Runbl_VcuTx_10ms_BSW2VCU_outputs(void);

DT_Bcm2VcuTms_outputs* Rte_IrvIRead_Runbl_VCU_100ms_Bcm2VcuTms_outputs(void);

DT_Bcm2VcuTms_outputs* Rte_IrvIRead_Runbl_VCU_20ms_Bcm2VcuTms_outputs(void);

void Rte_IrvIWrite_Runbl_VcuRx_10ms_Bcm2VcuTms_outputs(DT_Bcm2VcuTms_outputs* data);

DT_Bcm2VcuTms_outputs * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_Bcm2VcuTms_outputs(void);

DT_Bcm2VcuTms_outputs* Rte_IrvIRead_Runbl_VcuTx_10ms_Bcm2VcuTms_outputs(void);

DT_CANCommErr* Rte_IrvIRead_Runbl_VCU_100ms_CANCommErr_outputs(void);

DT_CANCommErr* Rte_IrvIRead_Runbl_VCU_20ms_CANCommErr_outputs(void);

void Rte_IrvIWrite_Runbl_VcuRx_10ms_CANCommErr_outputs(DT_CANCommErr* data);

DT_CANCommErr * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_CANCommErr_outputs(void);

void Rte_IrvIWrite_AppSwcVcu_Init_DAG_Comm_outputsIRV(DAG_Comm_outputs* data);

DAG_Comm_outputs * Rte_IrvIWriteRef_AppSwcVcu_Init_DAG_Comm_outputsIRV(void);

void Rte_IrvIWrite_Runbl_VCU_20ms_DAG_Comm_outputsIRV(DAG_Comm_outputs* data);

DAG_Comm_outputs * Rte_IrvIWriteRef_Runbl_VCU_20ms_DAG_Comm_outputsIRV(void);

DAG_Comm_outputs* Rte_IrvIRead_Runbl_VcuTx_10ms_DAG_Comm_outputsIRV(void);

void Rte_IrvIWrite_AppSwcVcu_Init_DAG_FltActn_outputs(DAG_FltActn_outputs* data);

DAG_FltActn_outputs * Rte_IrvIWriteRef_AppSwcVcu_Init_DAG_FltActn_outputs(void);

DAG_FltActn_outputs* Rte_IrvIRead_Runbl_VCU_100ms_DAG_FltActn_outputs(void);

DAG_FltActn_outputs* Rte_IrvIRead_Runbl_VCU_10ms_DAG_FltActn_outputs(void);

void Rte_IrvIWrite_Runbl_VCU_20ms_DAG_FltActn_outputs(DAG_FltActn_outputs* data);

DAG_FltActn_outputs * Rte_IrvIWriteRef_Runbl_VCU_20ms_DAG_FltActn_outputs(void);

DAG_FltActn_outputs* Rte_IrvIRead_Runbl_VcuTx_10ms_DAG_FltActn_outputs(void);

void Rte_IrvIWrite_AppSwcVcu_Init_DAG_Other_outputs(DAG_Other_outputs* data);

DAG_Other_outputs * Rte_IrvIWriteRef_AppSwcVcu_Init_DAG_Other_outputs(void);

DAG_Other_outputs* Rte_IrvIRead_Runbl_VCU_100ms_DAG_Other_outputs(void);

void Rte_IrvIWrite_Runbl_VCU_20ms_DAG_Other_outputs(DAG_Other_outputs* data);

DAG_Other_outputs * Rte_IrvIWriteRef_Runbl_VCU_20ms_DAG_Other_outputs(void);

void Rte_IrvIWrite_AppSwcVcu_Init_DAG_Sensor10ms_outputs(DAG_Sensor10ms_outputs* data);

DAG_Sensor10ms_outputs * Rte_IrvIWriteRef_AppSwcVcu_Init_DAG_Sensor10ms_outputs(void);

DAG_Sensor10ms_outputs* Rte_IrvIRead_Runbl_VCU_10ms_DAG_Sensor10ms_outputs(void);

void Rte_IrvIWrite_Runbl_VCU_20ms_DAG_Sensor10ms_outputs(DAG_Sensor10ms_outputs* data);

DAG_Sensor10ms_outputs * Rte_IrvIWriteRef_Runbl_VCU_20ms_DAG_Sensor10ms_outputs(void);

void Rte_IrvIWrite_AppSwcVcu_Init_DSA_outputs(DSA_outputs* data);

DSA_outputs * Rte_IrvIWriteRef_AppSwcVcu_Init_DSA_outputs(void);

void Rte_IrvIWrite_Runbl_VCU_100ms_DSA_outputs(DSA_outputs* data);

DSA_outputs * Rte_IrvIWriteRef_Runbl_VCU_100ms_DSA_outputs(void);

DSA_outputs* Rte_IrvIRead_Runbl_VCU_10ms_DSA_outputs(void);

void Rte_IrvIWrite_AppSwcVcu_Init_EMS_outputs(EMS_outputs* data);

EMS_outputs * Rte_IrvIWriteRef_AppSwcVcu_Init_EMS_outputs(void);

EMS_outputs* Rte_IrvIRead_Runbl_VCU_100ms_EMS_outputs(void);

EMS_outputs* Rte_IrvIRead_Runbl_VCU_10ms_EMS_outputs(void);

void Rte_IrvIWrite_Runbl_VCU_20ms_EMS_outputs(EMS_outputs* data);

EMS_outputs * Rte_IrvIWriteRef_Runbl_VCU_20ms_EMS_outputs(void);

EMS_outputs* Rte_IrvIRead_Runbl_VcuTx_10ms_EMS_outputs(void);

void Rte_IrvIWrite_AppSwcVcu_Init_GSM_outputs(GSM_outputs* data);

GSM_outputs * Rte_IrvIWriteRef_AppSwcVcu_Init_GSM_outputs(void);

GSM_outputs* Rte_IrvIRead_Runbl_VCU_100ms_GSM_outputs(void);

GSM_outputs* Rte_IrvIRead_Runbl_VCU_10ms_GSM_outputs(void);

void Rte_IrvIWrite_Runbl_VCU_20ms_GSM_outputs(GSM_outputs* data);

GSM_outputs * Rte_IrvIWriteRef_Runbl_VCU_20ms_GSM_outputs(void);

GSM_outputs* Rte_IrvIRead_Runbl_VcuTx_10ms_GSM_outputs(void);

void Rte_IrvIWrite_AppSwcVcu_Init_HMI_outputs(HMI_outputs* data);

HMI_outputs * Rte_IrvIWriteRef_AppSwcVcu_Init_HMI_outputs(void);

void Rte_IrvIWrite_Runbl_VCU_100ms_HMI_outputs(HMI_outputs* data);

HMI_outputs * Rte_IrvIWriteRef_Runbl_VCU_100ms_HMI_outputs(void);

HMI_outputs* Rte_IrvIRead_Runbl_VcuTx_10ms_HMI_outputs(void);

void Rte_IrvIWrite_AppSwcVcu_Init_HVM_outputs(HVM_outputs* data);

HVM_outputs * Rte_IrvIWriteRef_AppSwcVcu_Init_HVM_outputs(void);

HVM_outputs* Rte_IrvIRead_Runbl_VCU_100ms_HVM_outputs(void);

HVM_outputs* Rte_IrvIRead_Runbl_VCU_10ms_HVM_outputs(void);

void Rte_IrvIWrite_Runbl_VCU_20ms_HVM_outputs(HVM_outputs* data);

HVM_outputs * Rte_IrvIWriteRef_Runbl_VCU_20ms_HVM_outputs(void);

HVM_outputs* Rte_IrvIRead_Runbl_VcuTx_10ms_HVM_outputs(void);

DT_HardWire_Input_VCU* Rte_IrvIRead_Runbl_VCU_100ms_HardWire_Input_VCU(void);

DT_HardWire_Input_VCU* Rte_IrvIRead_Runbl_VCU_10ms_HardWire_Input_VCU(void);

DT_HardWire_Input_VCU* Rte_IrvIRead_Runbl_VCU_20ms_HardWire_Input_VCU(void);

void Rte_IrvIWrite_Runbl_VcuRx_10ms_HardWire_Input_VCU(DT_HardWire_Input_VCU* data);

DT_HardWire_Input_VCU * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_HardWire_Input_VCU(void);

void Rte_IrvIWrite_AppSwcVcu_Init_IPC_outputs(IPC_outputs* data);

IPC_outputs * Rte_IrvIWriteRef_AppSwcVcu_Init_IPC_outputs(void);

IPC_outputs* Rte_IrvIRead_Runbl_VCU_100ms_IPC_outputs(void);

void Rte_IrvIWrite_Runbl_VCU_10ms_IPC_outputs(IPC_outputs* data);

IPC_outputs * Rte_IrvIWriteRef_Runbl_VCU_10ms_IPC_outputs(void);

IPC_outputs* Rte_IrvIRead_Runbl_VCU_20ms_IPC_outputs(void);

IPC_outputs* Rte_IrvIRead_Runbl_VcuTx_10ms_IPC_outputs(void);

DT_IPM_BMS_10_DC_ChargeStates_EPT* Rte_IrvIRead_Runbl_VCU_100ms_IPM_BMS_10_DC_ChargeStates_EPT(void);

DT_IPM_BMS_10_DC_ChargeStates_EPT* Rte_IrvIRead_Runbl_VCU_10ms_IPM_BMS_10_DC_ChargeStates_EPT(void);

DT_IPM_BMS_10_DC_ChargeStates_EPT* Rte_IrvIRead_Runbl_VCU_20ms_IPM_BMS_10_DC_ChargeStates_EPT(void);

void Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_BMS_10_DC_ChargeStates_EPT(DT_IPM_BMS_10_DC_ChargeStates_EPT* data);

DT_IPM_BMS_10_DC_ChargeStates_EPT * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_BMS_10_DC_ChargeStates_EPT(void);

DT_IPM_BMS_1_MainState_EPT* Rte_IrvIRead_Runbl_VCU_100ms_IPM_BMS_1_MainState_EPT(void);

DT_IPM_BMS_1_MainState_EPT* Rte_IrvIRead_Runbl_VCU_20ms_IPM_BMS_1_MainState_EPT(void);

void Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_BMS_1_MainState_EPT(DT_IPM_BMS_1_MainState_EPT* data);

DT_IPM_BMS_1_MainState_EPT * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_BMS_1_MainState_EPT(void);

DT_IPM_BMS_2_BatState_EPT* Rte_IrvIRead_Runbl_VCU_100ms_IPM_BMS_2_BatState_EPT(void);

DT_IPM_BMS_2_BatState_EPT* Rte_IrvIRead_Runbl_VCU_10ms_IPM_BMS_2_BatState_EPT(void);

DT_IPM_BMS_2_BatState_EPT* Rte_IrvIRead_Runbl_VCU_20ms_IPM_BMS_2_BatState_EPT(void);

void Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_BMS_2_BatState_EPT(DT_IPM_BMS_2_BatState_EPT* data);

DT_IPM_BMS_2_BatState_EPT * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_BMS_2_BatState_EPT(void);

DT_IPM_BMS_5_BatTemp_EPT* Rte_IrvIRead_Runbl_VCU_100ms_IPM_BMS_5_BatTemp_EPT(void);

DT_IPM_BMS_5_BatTemp_EPT* Rte_IrvIRead_Runbl_VCU_20ms_IPM_BMS_5_BatTemp_EPT(void);

void Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_BMS_5_BatTemp_EPT(DT_IPM_BMS_5_BatTemp_EPT* data);

DT_IPM_BMS_5_BatTemp_EPT * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_BMS_5_BatTemp_EPT(void);

DT_IPM_BMS_6_DischrgRecup_EPT* Rte_IrvIRead_Runbl_VCU_20ms_IPM_BMS_6_DischrgRecup_EPT(void);

void Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_BMS_6_DischrgRecup_EPT(DT_IPM_BMS_6_DischrgRecup_EPT* data);

DT_IPM_BMS_6_DischrgRecup_EPT * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_BMS_6_DischrgRecup_EPT(void);

DT_IPM_BMS_9_BattInfo_EPT* Rte_IrvIRead_Runbl_VCU_100ms_IPM_BMS_9_BattInfo_EPT(void);

DT_IPM_BMS_9_BattInfo_EPT* Rte_IrvIRead_Runbl_VCU_20ms_IPM_BMS_9_BattInfo_EPT(void);

void Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_BMS_9_BattInfo_EPT(DT_IPM_BMS_9_BattInfo_EPT* data);

DT_IPM_BMS_9_BattInfo_EPT * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_BMS_9_BattInfo_EPT(void);

DT_IPM_EHB_B_CHA* Rte_IrvIRead_Runbl_VCU_10ms_IPM_EHB_B_CHA(void);

DT_IPM_EHB_B_CHA* Rte_IrvIRead_Runbl_VCU_20ms_IPM_EHB_B_CHA(void);

void Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_EHB_B_CHA(DT_IPM_EHB_B_CHA* data);

DT_IPM_EHB_B_CHA * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_EHB_B_CHA(void);

DT_IPM_ESC_7_FuncStatus_CHA* Rte_IrvIRead_Runbl_VCU_100ms_IPM_ESC_7_FuncStatus_CHA(void);

DT_IPM_ESC_7_FuncStatus_CHA* Rte_IrvIRead_Runbl_VCU_10ms_IPM_ESC_7_FuncStatus_CHA(void);

DT_IPM_ESC_7_FuncStatus_CHA* Rte_IrvIRead_Runbl_VCU_20ms_IPM_ESC_7_FuncStatus_CHA(void);

void Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_ESC_7_FuncStatus_CHA(DT_IPM_ESC_7_FuncStatus_CHA* data);

DT_IPM_ESC_7_FuncStatus_CHA * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_ESC_7_FuncStatus_CHA(void);

DT_IPM_ESC_A_CHA* Rte_IrvIRead_Runbl_VCU_100ms_IPM_ESC_A_CHA(void);

DT_IPM_ESC_A_CHA* Rte_IrvIRead_Runbl_VCU_10ms_IPM_ESC_A_CHA(void);

void Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_ESC_A_CHA(DT_IPM_ESC_A_CHA* data);

DT_IPM_ESC_A_CHA * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_ESC_A_CHA(void);

DT_IPM_FCM_B_CHA* Rte_IrvIRead_Runbl_VCU_10ms_IPM_FCM_B_CHA(void);

DT_IPM_FCM_B_CHA* Rte_IrvIRead_Runbl_VCU_20ms_IPM_FCM_B_CHA(void);

void Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_FCM_B_CHA(DT_IPM_FCM_B_CHA* data);

DT_IPM_FCM_B_CHA * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_FCM_B_CHA(void);

DT_IPM_HU_B_BAC* Rte_IrvIRead_Runbl_VCU_100ms_IPM_HU_B_BAC(void);

DT_IPM_HU_B_BAC* Rte_IrvIRead_Runbl_VCU_10ms_IPM_HU_B_BAC(void);

DT_IPM_HU_B_BAC* Rte_IrvIRead_Runbl_VCU_20ms_IPM_HU_B_BAC(void);

void Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_HU_B_BAC(DT_IPM_HU_B_BAC* data);

DT_IPM_HU_B_BAC * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_HU_B_BAC(void);

DT_IPM_INV_1_Value_EPT* Rte_IrvIRead_Runbl_VCU_10ms_IPM_INV_1_Value_EPT(void);

DT_IPM_INV_1_Value_EPT* Rte_IrvIRead_Runbl_VCU_20ms_IPM_INV_1_Value_EPT(void);

void Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_INV_1_Value_EPT(DT_IPM_INV_1_Value_EPT* data);

DT_IPM_INV_1_Value_EPT * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_INV_1_Value_EPT(void);

DT_IPM_INV_2_Value_EPT* Rte_IrvIRead_Runbl_VCU_10ms_IPM_INV_2_Value_EPT(void);

DT_IPM_INV_2_Value_EPT* Rte_IrvIRead_Runbl_VCU_20ms_IPM_INV_2_Value_EPT(void);

void Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_INV_2_Value_EPT(DT_IPM_INV_2_Value_EPT* data);

DT_IPM_INV_2_Value_EPT * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_INV_2_Value_EPT(void);

DT_IPM_INV_2_Value_EPT* Rte_IrvIRead_Runbl_VcuTx_10ms_IPM_INV_2_Value_EPT(void);

DT_IPM_INV_3_Value_EPT* Rte_IrvIRead_Runbl_VCU_100ms_IPM_INV_3_Value_EPT(void);

DT_IPM_INV_3_Value_EPT* Rte_IrvIRead_Runbl_VCU_10ms_IPM_INV_3_Value_EPT(void);

void Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_INV_3_Value_EPT(DT_IPM_INV_3_Value_EPT* data);

DT_IPM_INV_3_Value_EPT * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_INV_3_Value_EPT(void);

DT_IPM_INV_4_Value_EPT* Rte_IrvIRead_Runbl_VCU_10ms_IPM_INV_4_Value_EPT(void);

DT_IPM_INV_4_Value_EPT* Rte_IrvIRead_Runbl_VCU_20ms_IPM_INV_4_Value_EPT(void);

void Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_INV_4_Value_EPT(DT_IPM_INV_4_Value_EPT* data);

DT_IPM_INV_4_Value_EPT * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_INV_4_Value_EPT(void);

DT_IPM_IPU_DCC_1_State_EPT* Rte_IrvIRead_Runbl_VCU_100ms_IPM_IPU_DCC_1_State_EPT(void);

DT_IPM_IPU_DCC_1_State_EPT* Rte_IrvIRead_Runbl_VCU_20ms_IPM_IPU_DCC_1_State_EPT(void);

void Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_IPU_DCC_1_State_EPT(DT_IPM_IPU_DCC_1_State_EPT* data);

DT_IPM_IPU_DCC_1_State_EPT * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_IPU_DCC_1_State_EPT(void);

DT_IPM_IPU_OBC_1_State_EPT* Rte_IrvIRead_Runbl_VCU_100ms_IPM_IPU_OBC_1_State_EPT(void);

DT_IPM_IPU_OBC_1_State_EPT* Rte_IrvIRead_Runbl_VCU_10ms_IPM_IPU_OBC_1_State_EPT(void);

DT_IPM_IPU_OBC_1_State_EPT* Rte_IrvIRead_Runbl_VCU_20ms_IPM_IPU_OBC_1_State_EPT(void);

void Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_IPU_OBC_1_State_EPT(DT_IPM_IPU_OBC_1_State_EPT* data);

DT_IPM_IPU_OBC_1_State_EPT * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_IPU_OBC_1_State_EPT(void);

DT_IPM_SCS_RiSwitchSts_BOD* Rte_IrvIRead_Runbl_VCU_100ms_IPM_SCS_RiSwitchSts_BOD(void);

DT_IPM_SCS_RiSwitchSts_BOD* Rte_IrvIRead_Runbl_VCU_10ms_IPM_SCS_RiSwitchSts_BOD(void);

DT_IPM_SCS_RiSwitchSts_BOD* Rte_IrvIRead_Runbl_VCU_20ms_IPM_SCS_RiSwitchSts_BOD(void);

void Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_SCS_RiSwitchSts_BOD(DT_IPM_SCS_RiSwitchSts_BOD* data);

DT_IPM_SCS_RiSwitchSts_BOD * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_SCS_RiSwitchSts_BOD(void);

DT_IPM_SRS_1_Status_CHA* Rte_IrvIRead_Runbl_VCU_10ms_IPM_SRS_1_Status_CHA(void);

DT_IPM_SRS_1_Status_CHA* Rte_IrvIRead_Runbl_VCU_20ms_IPM_SRS_1_Status_CHA(void);

void Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_SRS_1_Status_CHA(DT_IPM_SRS_1_Status_CHA* data);

DT_IPM_SRS_1_Status_CHA * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_SRS_1_Status_CHA(void);

DT_MsgActv* Rte_IrvIRead_Runbl_VCU_10ms_MsgActv_outputs(void);

DT_MsgActv* Rte_IrvIRead_Runbl_VCU_20ms_MsgActv_outputs(void);

void Rte_IrvIWrite_Runbl_VcuRx_10ms_MsgActv_outputs(DT_MsgActv* data);

DT_MsgActv * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_MsgActv_outputs(void);

void Rte_IrvIWrite_AppSwcVcu_Init_NVM_Imdt_outputs(NVM_Imdt_outputs* data);

NVM_Imdt_outputs * Rte_IrvIWriteRef_AppSwcVcu_Init_NVM_Imdt_outputs(void);

NVM_Imdt_outputs* Rte_IrvIRead_Runbl_VCU_100ms_NVM_Imdt_outputs(void);

NVM_Imdt_outputs* Rte_IrvIRead_Runbl_VCU_10ms_NVM_Imdt_outputs(void);

NVM_Imdt_outputs* Rte_IrvIRead_Runbl_VCU_20ms_NVM_Imdt_outputs(void);

void Rte_IrvIWrite_Runbl_VcuRx_10ms_NVM_Imdt_outputs(NVM_Imdt_outputs* data);

NVM_Imdt_outputs * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_NVM_Imdt_outputs(void);

NVM_Imdt_outputs* Rte_IrvIRead_Runbl_VcuTx_10ms_NVM_Imdt_outputs(void);

void Rte_IrvIWrite_AppSwcVcu_Init_NVM_outputs(NVM_outputs* data);

NVM_outputs * Rte_IrvIWriteRef_AppSwcVcu_Init_NVM_outputs(void);

NVM_outputs* Rte_IrvIRead_Runbl_VCU_100ms_NVM_outputs(void);

NVM_outputs* Rte_IrvIRead_Runbl_VCU_10ms_NVM_outputs(void);

NVM_outputs* Rte_IrvIRead_Runbl_VCU_20ms_NVM_outputs(void);

void Rte_IrvIWrite_Runbl_VcuRx_10ms_NVM_outputs(NVM_outputs* data);

NVM_outputs * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_NVM_outputs(void);

void Rte_IrvIWrite_AppSwcVcu_Init_RME_outputs(RME_outputs* data);

RME_outputs * Rte_IrvIWriteRef_AppSwcVcu_Init_RME_outputs(void);

void Rte_IrvIWrite_Runbl_VCU_100ms_RME_outputs(RME_outputs* data);

RME_outputs * Rte_IrvIWriteRef_Runbl_VCU_100ms_RME_outputs(void);

RME_outputs* Rte_IrvIRead_Runbl_VcuTx_10ms_RME_outputs(void);

void Rte_IrvIWrite_AppSwcVcu_Init_SIBS_Output(DT_SIBS_Output* data);

DT_SIBS_Output * Rte_IrvIWriteRef_AppSwcVcu_Init_SIBS_Output(void);

void Rte_IrvIWrite_Runbl_VCU_100ms_SIBS_Output(DT_SIBS_Output* data);

DT_SIBS_Output * Rte_IrvIWriteRef_Runbl_VCU_100ms_SIBS_Output(void);

DT_SIBS_Output* Rte_IrvIRead_Runbl_VCU_20ms_SIBS_Output(void);

DT_SIBS_Output* Rte_IrvIRead_Runbl_VcuTx_10ms_SIBS_Output(void);

void Rte_IrvIWrite_AppSwcVcu_Init_TBOX_outputs(TBOX_outputs* data);

TBOX_outputs * Rte_IrvIWriteRef_AppSwcVcu_Init_TBOX_outputs(void);

void Rte_IrvIWrite_Runbl_VCU_100ms_TBOX_outputs(TBOX_outputs* data);

TBOX_outputs * Rte_IrvIWriteRef_Runbl_VCU_100ms_TBOX_outputs(void);

TBOX_outputs* Rte_IrvIRead_Runbl_VCU_10ms_TBOX_outputs(void);

TBOX_outputs* Rte_IrvIRead_Runbl_VCU_20ms_TBOX_outputs(void);

TBOX_outputs* Rte_IrvIRead_Runbl_VcuTx_10ms_TBOX_outputs(void);

TMS2VCU_AC_2_State_Outputs* Rte_IrvIRead_Runbl_VCU_20ms_TMS2VCU_AC_2_State_Outputs(void);

void Rte_IrvIWrite_Runbl_VcuRx_10ms_TMS2VCU_AC_2_State_Outputs(TMS2VCU_AC_2_State_Outputs* data);

TMS2VCU_AC_2_State_Outputs * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_TMS2VCU_AC_2_State_Outputs(void);

Tms2Vcu_Info* Rte_IrvIRead_Runbl_VCU_20ms_Tms2Vcu_Info(void);

void Rte_IrvIWrite_Runbl_VcuRx_10ms_Tms2Vcu_Info(Tms2Vcu_Info* data);

Tms2Vcu_Info * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_Tms2Vcu_Info(void);

Tms2Vcu_Info* Rte_IrvIRead_Runbl_VcuTx_10ms_Tms2Vcu_Info(void);

void Rte_IrvIWrite_Runbl_VCU_20ms_VDAG_VCUErrCode_enum(UInt16 data);

UInt16 * Rte_IrvIWriteRef_Runbl_VCU_20ms_VDAG_VCUErrCode_enum(void);

UInt16 Rte_IrvIRead_Runbl_VcuTx_10ms_VDAG_VCUErrCode_enum(void);

void Rte_IrvIWrite_AppSwcVcu_Init_VDAG_VCUFltLvl_enum(UInt8 data);

UInt8 * Rte_IrvIWriteRef_AppSwcVcu_Init_VDAG_VCUFltLvl_enum(void);

void Rte_IrvIWrite_Runbl_VCU_20ms_VDAG_VCUFltLvl_enum(UInt8 data);

UInt8 * Rte_IrvIWriteRef_Runbl_VCU_20ms_VDAG_VCUFltLvl_enum(void);

UInt8 Rte_IrvIRead_Runbl_VcuTx_10ms_VDAG_VCUFltLvl_enum(void);

void Rte_IrvIWrite_AppSwcVcu_Init_VSO_outputs(VSO_outputs* data);

VSO_outputs * Rte_IrvIWriteRef_AppSwcVcu_Init_VSO_outputs(void);

void Rte_IrvIWrite_Runbl_VCU_10ms_VSO_outputs(VSO_outputs* data);

VSO_outputs * Rte_IrvIWriteRef_Runbl_VCU_10ms_VSO_outputs(void);

VSO_outputs* Rte_IrvIRead_Runbl_VcuTx_10ms_VSO_outputs(void);

void Rte_IrvIWrite_AppSwcVcu_Init_VTM_outputs(VTM_outputs* data);

VTM_outputs * Rte_IrvIWriteRef_AppSwcVcu_Init_VTM_outputs(void);

VTM_outputs* Rte_IrvIRead_Runbl_VCU_100ms_VTM_outputs(void);

void Rte_IrvIWrite_Runbl_VCU_10ms_VTM_outputs(VTM_outputs* data);

VTM_outputs * Rte_IrvIWriteRef_Runbl_VCU_10ms_VTM_outputs(void);

VTM_outputs* Rte_IrvIRead_Runbl_VCU_20ms_VTM_outputs(void);

VTM_outputs* Rte_IrvIRead_Runbl_VcuTx_10ms_VTM_outputs(void);

VehCfg_outputs* Rte_IrvIRead_Runbl_VCU_10ms_VehCfg_outputs(void);

void Rte_IrvIWrite_Runbl_VcuRx_10ms_VehCfg_outputs(VehCfg_outputs* data);

VehCfg_outputs * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_VehCfg_outputs(void);

Std_ReturnType Rte_IStatus_Runbl_VCU_100ms_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs(void);

Std_ReturnType Rte_IStatus_Runbl_VCU_100ms_TMS2VCU_PPV_outputs_TMS2VCU_PPV_outputs(void);

Std_ReturnType Rte_IStatus_Runbl_VCU_10ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD(void);

Std_ReturnType Rte_IStatus_Runbl_VCU_10ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA(void);

Std_ReturnType Rte_IStatus_Runbl_VCU_20ms_CANCommCRCFlt_outputs_CANCommCRCFlt_outputs(void);

Std_ReturnType Rte_IStatus_Runbl_VCU_20ms_IPM_BMS_3_DC_ChargeState_EPT_IPM_BMS_3_DC_ChargeState_EPT(void);

Std_ReturnType Rte_IStatus_Runbl_VCU_20ms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT(void);

Std_ReturnType Rte_IStatus_Runbl_VCU_20ms_IPM_BMS_7_CellVolt_EPT_IPM_BMS_7_CellVolt_EPT(void);

Std_ReturnType Rte_IStatus_Runbl_VCU_20ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD(void);

Std_ReturnType Rte_IStatus_Runbl_VCU_20ms_IPM_ICU_2_Odo_BAC_IPM_ICU_2_Odo_BAC(void);

Std_ReturnType Rte_IStatus_Runbl_VCU_20ms_IPM_IPU_DCC_2_ChrgInValue_EPT_IPM_IPU_DCC_2_ChrgInValue_EPT(void);

Std_ReturnType Rte_IStatus_Runbl_VCU_20ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT(void);

Std_ReturnType Rte_IStatus_Runbl_VCU_20ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC(void);

Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs(void);

Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_CANCommErr_outputs_CANCommErr_outputs(void);

Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT(void);

Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT(void);

Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_IPM_BMS_2_BatState_EPT_IPM_BMS_2_BatState_EPT(void);

Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT(void);

Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_IPM_BMS_6_DischrgRecup_EPT_IPM_BMS_6_DischrgRecup_EPT(void);

Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_IPM_BMS_9_BattInfo_EPT_IPM_BMS_9_BattInfo_EPT(void);

Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_IPM_EHB_B_CHA_IPM_EHB_B_CHA(void);

Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA(void);

Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_IPM_ESC_A_CHA_IPM_ESC_A_CHA(void);

Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_IPM_FCM_B_CHA_IPM_FCM_B_CHA(void);

Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_IPM_HU_B_BAC_IPM_HU_B_BAC(void);

Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_IPM_INV_1_Value_EPT_IPM_INV_1_Value_EPT(void);

Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT(void);

Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_IPM_INV_3_Value_EPT_IPM_INV_3_Value_EPT(void);

Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_IPM_INV_4_Value_EPT_IPM_INV_4_Value_EPT(void);

Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_IPM_IPU_DCC_1_State_EPT_IPM_IPU_DCC_1_State_EPT(void);

Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_IPM_IPU_OBC_1_State_EPT_IPM_IPU_OBC_1_State_EPT(void);

Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_IPM_SCS_RiSwitchSts_BOD_IPM_SCS_RiSwitchSts_BOD(void);

Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA(void);

Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_MsgActv_outputs_MsgActv_outputs(void);

Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs(void);

Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_Tms2Vcu_Info_Tms2Vcu_Info(void);

/** runnables */

void Runbl_VCU_100ms(void);

void Runbl_VCU_10ms(void);

void Runbl_VCU_20ms(void);

void Runbl_VcuRx_10ms(void);

void Runbl_VcuTx_10ms(void);

void AppSwcVcu_Init(void);

#endif

