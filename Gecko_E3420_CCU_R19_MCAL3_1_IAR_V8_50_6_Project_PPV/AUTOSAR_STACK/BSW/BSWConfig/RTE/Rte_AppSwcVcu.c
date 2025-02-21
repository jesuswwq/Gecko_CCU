/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_AppSwcVcu.c>
 *  @brief      <>
 *  
 *  <MCU:E3420>
 *  
 *  @author     <>
 *  @date       <2025-02-19 14:27:08>
 */
/*============================================================================*/

/* Rte_AppSwcVcu.c */
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
#include "Rte_AppSwcVcu.h"
#include "Rte_Data.h"

/*******************************************************************************
 **                        Private Function Declarations                      **
******************************************************************************/

static void Rte_PRE_Runbl_VCU_100ms(void);

static void Rte_PRE_Runbl_VCU_10ms(void);

static void Rte_PRE_Runbl_VCU_20ms(void);

static void Rte_PRE_Runbl_VcuRx_10ms(void);

static void Rte_PRE_Runbl_VcuTx_10ms(void);

static void Rte_POST_AppSwcVcu_Init(void);

static void Rte_POST_Runbl_VCU_100ms(void);

static void Rte_POST_Runbl_VCU_10ms(void);

static void Rte_POST_Runbl_VCU_20ms(void);

static void Rte_POST_Runbl_VcuRx_10ms(void);

static void Rte_POST_Runbl_VcuTx_10ms(void);

/*******************************************************************************
 **                        Global Function Declarations                       **
******************************************************************************/

/*******************************************************************************
 **                        Private Function Definitions                       **
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
static void Rte_PRE_Runbl_VCU_100ms(void)
{
    if (RteInitState == RTE_INITED)
    {
        SuspendAllInterrupts();
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcVcu.Runbl_VCU_100ms_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs->value), (uint8*)&Rte_Buf_Runbl_VCU_100ms_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs, sizeof(TMS2VCU_AC_3_State_Outputs));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcVcu.Runbl_VCU_100ms_TMS2VCU_PPV_outputs_TMS2VCU_PPV_outputs->value), (uint8*)&Rte_Buf_Runbl_VCU_100ms_TMS2VCU_PPV_outputs_TMS2VCU_PPV_outputs, sizeof(TMS2VCU_PPVAddSignalGroup_Outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_100ms_BSW2VCU_outputs, (uint8*)&Irv_AppSwcVcu_BSW2VCU_outputs, sizeof(BSW2VCU_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_100ms_Bcm2VcuTms_outputs, (uint8*)&Irv_AppSwcVcu_Bcm2VcuTms_outputs, sizeof(DT_Bcm2VcuTms_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_100ms_CANCommErr_outputs, (uint8*)&Irv_AppSwcVcu_CANCommErr_outputs, sizeof(DT_CANCommErr));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_100ms_DAG_FltActn_outputs, (uint8*)&Irv_AppSwcVcu_DAG_FltActn_outputs, sizeof(DAG_FltActn_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_100ms_DAG_Other_outputs, (uint8*)&Irv_AppSwcVcu_DAG_Other_outputs, sizeof(DAG_Other_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_100ms_EMS_outputs, (uint8*)&Irv_AppSwcVcu_EMS_outputs, sizeof(EMS_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_100ms_GSM_outputs, (uint8*)&Irv_AppSwcVcu_GSM_outputs, sizeof(GSM_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_100ms_HVM_outputs, (uint8*)&Irv_AppSwcVcu_HVM_outputs, sizeof(HVM_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_100ms_HardWire_Input_VCU, (uint8*)&Irv_AppSwcVcu_HardWire_Input_VCU, sizeof(DT_HardWire_Input_VCU));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_100ms_IPC_outputs, (uint8*)&Irv_AppSwcVcu_IPC_outputs, sizeof(IPC_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_100ms_IPM_BMS_10_DC_ChargeStates_EPT, (uint8*)&Irv_AppSwcVcu_IPM_BMS_10_DC_ChargeStates_EPT, sizeof(DT_IPM_BMS_10_DC_ChargeStates_EPT));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_100ms_IPM_BMS_1_MainState_EPT, (uint8*)&Irv_AppSwcVcu_IPM_BMS_1_MainState_EPT, sizeof(DT_IPM_BMS_1_MainState_EPT));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_100ms_IPM_BMS_2_BatState_EPT, (uint8*)&Irv_AppSwcVcu_IPM_BMS_2_BatState_EPT, sizeof(DT_IPM_BMS_2_BatState_EPT));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_100ms_IPM_BMS_5_BatTemp_EPT, (uint8*)&Irv_AppSwcVcu_IPM_BMS_5_BatTemp_EPT, sizeof(DT_IPM_BMS_5_BatTemp_EPT));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_100ms_IPM_BMS_9_BattInfo_EPT, (uint8*)&Irv_AppSwcVcu_IPM_BMS_9_BattInfo_EPT, sizeof(DT_IPM_BMS_9_BattInfo_EPT));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_100ms_IPM_ESC_7_FuncStatus_CHA, (uint8*)&Irv_AppSwcVcu_IPM_ESC_7_FuncStatus_CHA, sizeof(DT_IPM_ESC_7_FuncStatus_CHA));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_100ms_IPM_ESC_A_CHA, (uint8*)&Irv_AppSwcVcu_IPM_ESC_A_CHA, sizeof(DT_IPM_ESC_A_CHA));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_100ms_IPM_HU_B_BAC, (uint8*)&Irv_AppSwcVcu_IPM_HU_B_BAC, sizeof(DT_IPM_HU_B_BAC));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_100ms_IPM_INV_3_Value_EPT, (uint8*)&Irv_AppSwcVcu_IPM_INV_3_Value_EPT, sizeof(DT_IPM_INV_3_Value_EPT));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_100ms_IPM_IPU_DCC_1_State_EPT, (uint8*)&Irv_AppSwcVcu_IPM_IPU_DCC_1_State_EPT, sizeof(DT_IPM_IPU_DCC_1_State_EPT));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_100ms_IPM_IPU_OBC_1_State_EPT, (uint8*)&Irv_AppSwcVcu_IPM_IPU_OBC_1_State_EPT, sizeof(DT_IPM_IPU_OBC_1_State_EPT));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_100ms_IPM_SCS_RiSwitchSts_BOD, (uint8*)&Irv_AppSwcVcu_IPM_SCS_RiSwitchSts_BOD, sizeof(DT_IPM_SCS_RiSwitchSts_BOD));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_100ms_NVM_Imdt_outputs, (uint8*)&Irv_AppSwcVcu_NVM_Imdt_outputs, sizeof(NVM_Imdt_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_100ms_NVM_outputs, (uint8*)&Irv_AppSwcVcu_NVM_outputs, sizeof(NVM_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_100ms_VTM_outputs, (uint8*)&Irv_AppSwcVcu_VTM_outputs, sizeof(VTM_outputs));
        ResumeAllInterrupts();
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
static void Rte_PRE_Runbl_VCU_10ms(void)
{
    if (RteInitState == RTE_INITED)
    {
        SuspendAllInterrupts();
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcVcu.Runbl_VCU_10ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD->value), (uint8*)&Rte_Buf_Runbl_VCU_10ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD, sizeof(DT_IPM_CCP_PanelStatus_BOD));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcVcu.Runbl_VCU_10ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA->value), (uint8*)&Rte_Buf_Runbl_VCU_10ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA, sizeof(DT_IPM_EHB_A_CHA));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_10ms_BSW2VCU_outputs, (uint8*)&Irv_AppSwcVcu_BSW2VCU_outputs, sizeof(BSW2VCU_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_10ms_DAG_FltActn_outputs, (uint8*)&Irv_AppSwcVcu_DAG_FltActn_outputs, sizeof(DAG_FltActn_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_10ms_DAG_Sensor10ms_outputs, (uint8*)&Irv_AppSwcVcu_DAG_Sensor10ms_outputs, sizeof(DAG_Sensor10ms_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_10ms_DSA_outputs, (uint8*)&Irv_AppSwcVcu_DSA_outputs, sizeof(DSA_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_10ms_EMS_outputs, (uint8*)&Irv_AppSwcVcu_EMS_outputs, sizeof(EMS_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_10ms_GSM_outputs, (uint8*)&Irv_AppSwcVcu_GSM_outputs, sizeof(GSM_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_10ms_HVM_outputs, (uint8*)&Irv_AppSwcVcu_HVM_outputs, sizeof(HVM_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_10ms_HardWire_Input_VCU, (uint8*)&Irv_AppSwcVcu_HardWire_Input_VCU, sizeof(DT_HardWire_Input_VCU));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_10ms_IPM_BMS_10_DC_ChargeStates_EPT, (uint8*)&Irv_AppSwcVcu_IPM_BMS_10_DC_ChargeStates_EPT, sizeof(DT_IPM_BMS_10_DC_ChargeStates_EPT));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_10ms_IPM_BMS_2_BatState_EPT, (uint8*)&Irv_AppSwcVcu_IPM_BMS_2_BatState_EPT, sizeof(DT_IPM_BMS_2_BatState_EPT));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_10ms_IPM_EHB_B_CHA, (uint8*)&Irv_AppSwcVcu_IPM_EHB_B_CHA, sizeof(DT_IPM_EHB_B_CHA));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_10ms_IPM_ESC_7_FuncStatus_CHA, (uint8*)&Irv_AppSwcVcu_IPM_ESC_7_FuncStatus_CHA, sizeof(DT_IPM_ESC_7_FuncStatus_CHA));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_10ms_IPM_ESC_A_CHA, (uint8*)&Irv_AppSwcVcu_IPM_ESC_A_CHA, sizeof(DT_IPM_ESC_A_CHA));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_10ms_IPM_FCM_B_CHA, (uint8*)&Irv_AppSwcVcu_IPM_FCM_B_CHA, sizeof(DT_IPM_FCM_B_CHA));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_10ms_IPM_HU_B_BAC, (uint8*)&Irv_AppSwcVcu_IPM_HU_B_BAC, sizeof(DT_IPM_HU_B_BAC));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_10ms_IPM_INV_1_Value_EPT, (uint8*)&Irv_AppSwcVcu_IPM_INV_1_Value_EPT, sizeof(DT_IPM_INV_1_Value_EPT));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_10ms_IPM_INV_2_Value_EPT, (uint8*)&Irv_AppSwcVcu_IPM_INV_2_Value_EPT, sizeof(DT_IPM_INV_2_Value_EPT));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_10ms_IPM_INV_3_Value_EPT, (uint8*)&Irv_AppSwcVcu_IPM_INV_3_Value_EPT, sizeof(DT_IPM_INV_3_Value_EPT));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_10ms_IPM_INV_4_Value_EPT, (uint8*)&Irv_AppSwcVcu_IPM_INV_4_Value_EPT, sizeof(DT_IPM_INV_4_Value_EPT));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_10ms_IPM_IPU_OBC_1_State_EPT, (uint8*)&Irv_AppSwcVcu_IPM_IPU_OBC_1_State_EPT, sizeof(DT_IPM_IPU_OBC_1_State_EPT));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_10ms_IPM_SCS_RiSwitchSts_BOD, (uint8*)&Irv_AppSwcVcu_IPM_SCS_RiSwitchSts_BOD, sizeof(DT_IPM_SCS_RiSwitchSts_BOD));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_10ms_IPM_SRS_1_Status_CHA, (uint8*)&Irv_AppSwcVcu_IPM_SRS_1_Status_CHA, sizeof(DT_IPM_SRS_1_Status_CHA));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_10ms_MsgActv_outputs, (uint8*)&Irv_AppSwcVcu_MsgActv_outputs, sizeof(DT_MsgActv));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_10ms_NVM_Imdt_outputs, (uint8*)&Irv_AppSwcVcu_NVM_Imdt_outputs, sizeof(NVM_Imdt_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_10ms_NVM_outputs, (uint8*)&Irv_AppSwcVcu_NVM_outputs, sizeof(NVM_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_10ms_TBOX_outputs, (uint8*)&Irv_AppSwcVcu_TBOX_outputs, sizeof(TBOX_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_10ms_VehCfg_outputs, (uint8*)&Irv_AppSwcVcu_VehCfg_outputs, sizeof(VehCfg_outputs));
        ResumeAllInterrupts();
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
static void Rte_PRE_Runbl_VCU_20ms(void)
{
    if (RteInitState == RTE_INITED)
    {
        SuspendAllInterrupts();
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcVcu.Runbl_VCU_20ms_CANCommCRCFlt_outputs_CANCommCRCFlt_outputs->value), (uint8*)&Rte_Buf_Runbl_VCU_20ms_CANCommCRCFlt_outputs_CANCommCRCFlt_outputs, sizeof(DT_CANCommCRCFlt));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcVcu.Runbl_VCU_20ms_IPM_BMS_3_DC_ChargeState_EPT_IPM_BMS_3_DC_ChargeState_EPT->value), (uint8*)&Rte_Buf_Runbl_VCU_20ms_IPM_BMS_3_DC_ChargeState_EPT_IPM_BMS_3_DC_ChargeState_EPT, sizeof(DT_IPM_BMS_3_DC_ChargeState_EPT));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcVcu.Runbl_VCU_20ms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT->value), (uint8*)&Rte_Buf_Runbl_VCU_20ms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT, sizeof(DT_IPM_BMS_4_AC_ChargeState_EPT));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcVcu.Runbl_VCU_20ms_IPM_BMS_7_CellVolt_EPT_IPM_BMS_7_CellVolt_EPT->value), (uint8*)&Rte_Buf_Runbl_VCU_20ms_IPM_BMS_7_CellVolt_EPT_IPM_BMS_7_CellVolt_EPT, sizeof(DT_IPM_BMS_7_CellVolt_EPT));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcVcu.Runbl_VCU_20ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD->value), (uint8*)&Rte_Buf_Runbl_VCU_20ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD, sizeof(DT_IPM_COMP_AC_BOD));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcVcu.Runbl_VCU_20ms_IPM_ICU_2_Odo_BAC_IPM_ICU_2_Odo_BAC->value), (uint8*)&Rte_Buf_Runbl_VCU_20ms_IPM_ICU_2_Odo_BAC_IPM_ICU_2_Odo_BAC, sizeof(DT_IPM_ICU_2_Odo_BAC));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcVcu.Runbl_VCU_20ms_IPM_IPU_DCC_2_ChrgInValue_EPT_IPM_IPU_DCC_2_ChrgInValue_EPT->value), (uint8*)&Rte_Buf_Runbl_VCU_20ms_IPM_IPU_DCC_2_ChrgInValue_EPT_IPM_IPU_DCC_2_ChrgInValue_EPT, sizeof(DT_IPM_IPU_DCC_2_ChrgInValue_EPT));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcVcu.Runbl_VCU_20ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT->value), (uint8*)&Rte_Buf_Runbl_VCU_20ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT, sizeof(DT_IPM_IPU_OBC_2_Inlet_EPT));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcVcu.Runbl_VCU_20ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC->value), (uint8*)&Rte_Buf_Runbl_VCU_20ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC, sizeof(DT_IPM_TBOX_BJS_Time_BAC));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_20ms_BSW2VCU_outputs, (uint8*)&Irv_AppSwcVcu_BSW2VCU_outputs, sizeof(BSW2VCU_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_20ms_Bcm2VcuTms_outputs, (uint8*)&Irv_AppSwcVcu_Bcm2VcuTms_outputs, sizeof(DT_Bcm2VcuTms_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_20ms_CANCommErr_outputs, (uint8*)&Irv_AppSwcVcu_CANCommErr_outputs, sizeof(DT_CANCommErr));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_20ms_HardWire_Input_VCU, (uint8*)&Irv_AppSwcVcu_HardWire_Input_VCU, sizeof(DT_HardWire_Input_VCU));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_20ms_IPC_outputs, (uint8*)&Irv_AppSwcVcu_IPC_outputs, sizeof(IPC_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_BMS_10_DC_ChargeStates_EPT, (uint8*)&Irv_AppSwcVcu_IPM_BMS_10_DC_ChargeStates_EPT, sizeof(DT_IPM_BMS_10_DC_ChargeStates_EPT));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_BMS_1_MainState_EPT, (uint8*)&Irv_AppSwcVcu_IPM_BMS_1_MainState_EPT, sizeof(DT_IPM_BMS_1_MainState_EPT));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_BMS_2_BatState_EPT, (uint8*)&Irv_AppSwcVcu_IPM_BMS_2_BatState_EPT, sizeof(DT_IPM_BMS_2_BatState_EPT));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_BMS_5_BatTemp_EPT, (uint8*)&Irv_AppSwcVcu_IPM_BMS_5_BatTemp_EPT, sizeof(DT_IPM_BMS_5_BatTemp_EPT));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_BMS_6_DischrgRecup_EPT, (uint8*)&Irv_AppSwcVcu_IPM_BMS_6_DischrgRecup_EPT, sizeof(DT_IPM_BMS_6_DischrgRecup_EPT));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_BMS_9_BattInfo_EPT, (uint8*)&Irv_AppSwcVcu_IPM_BMS_9_BattInfo_EPT, sizeof(DT_IPM_BMS_9_BattInfo_EPT));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_EHB_B_CHA, (uint8*)&Irv_AppSwcVcu_IPM_EHB_B_CHA, sizeof(DT_IPM_EHB_B_CHA));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_ESC_7_FuncStatus_CHA, (uint8*)&Irv_AppSwcVcu_IPM_ESC_7_FuncStatus_CHA, sizeof(DT_IPM_ESC_7_FuncStatus_CHA));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_FCM_B_CHA, (uint8*)&Irv_AppSwcVcu_IPM_FCM_B_CHA, sizeof(DT_IPM_FCM_B_CHA));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_HU_B_BAC, (uint8*)&Irv_AppSwcVcu_IPM_HU_B_BAC, sizeof(DT_IPM_HU_B_BAC));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_INV_1_Value_EPT, (uint8*)&Irv_AppSwcVcu_IPM_INV_1_Value_EPT, sizeof(DT_IPM_INV_1_Value_EPT));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_INV_2_Value_EPT, (uint8*)&Irv_AppSwcVcu_IPM_INV_2_Value_EPT, sizeof(DT_IPM_INV_2_Value_EPT));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_INV_4_Value_EPT, (uint8*)&Irv_AppSwcVcu_IPM_INV_4_Value_EPT, sizeof(DT_IPM_INV_4_Value_EPT));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_IPU_DCC_1_State_EPT, (uint8*)&Irv_AppSwcVcu_IPM_IPU_DCC_1_State_EPT, sizeof(DT_IPM_IPU_DCC_1_State_EPT));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_IPU_OBC_1_State_EPT, (uint8*)&Irv_AppSwcVcu_IPM_IPU_OBC_1_State_EPT, sizeof(DT_IPM_IPU_OBC_1_State_EPT));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_SCS_RiSwitchSts_BOD, (uint8*)&Irv_AppSwcVcu_IPM_SCS_RiSwitchSts_BOD, sizeof(DT_IPM_SCS_RiSwitchSts_BOD));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_SRS_1_Status_CHA, (uint8*)&Irv_AppSwcVcu_IPM_SRS_1_Status_CHA, sizeof(DT_IPM_SRS_1_Status_CHA));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_20ms_MsgActv_outputs, (uint8*)&Irv_AppSwcVcu_MsgActv_outputs, sizeof(DT_MsgActv));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_20ms_NVM_Imdt_outputs, (uint8*)&Irv_AppSwcVcu_NVM_Imdt_outputs, sizeof(NVM_Imdt_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_20ms_NVM_outputs, (uint8*)&Irv_AppSwcVcu_NVM_outputs, sizeof(NVM_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_20ms_SIBS_Output, (uint8*)&Irv_AppSwcVcu_SIBS_Output, sizeof(DT_SIBS_Output));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_20ms_TBOX_outputs, (uint8*)&Irv_AppSwcVcu_TBOX_outputs, sizeof(TBOX_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_20ms_TMS2VCU_AC_2_State_Outputs, (uint8*)&Irv_AppSwcVcu_TMS2VCU_AC_2_State_Outputs, sizeof(TMS2VCU_AC_2_State_Outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_20ms_Tms2Vcu_Info, (uint8*)&Irv_AppSwcVcu_Tms2Vcu_Info, sizeof(Tms2Vcu_Info));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_20ms_VTM_outputs, (uint8*)&Irv_AppSwcVcu_VTM_outputs, sizeof(VTM_outputs));
        ResumeAllInterrupts();
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
static void Rte_PRE_Runbl_VcuRx_10ms(void)
{
    if (RteInitState == RTE_INITED)
    {
        SuspendAllInterrupts();
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs->value), (uint8*)&Rte_Buf_Runbl_VcuRx_10ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs, sizeof(DT_Bcm2VcuTms_outputs));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_CANCommErr_outputs_CANCommErr_outputs->value), (uint8*)&Rte_Buf_Runbl_VcuRx_10ms_CANCommErr_outputs_CANCommErr_outputs, sizeof(DT_CANCommErr));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT->value), (uint8*)&Rte_Buf_Runbl_VcuRx_10ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT, sizeof(DT_IPM_BMS_10_DC_ChargeStates_EPT));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT->value), (uint8*)&Rte_Buf_Runbl_VcuRx_10ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT, sizeof(DT_IPM_BMS_1_MainState_EPT));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_BMS_2_BatState_EPT_IPM_BMS_2_BatState_EPT->value), (uint8*)&Rte_Buf_Runbl_VcuRx_10ms_IPM_BMS_2_BatState_EPT_IPM_BMS_2_BatState_EPT, sizeof(DT_IPM_BMS_2_BatState_EPT));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT->value), (uint8*)&Rte_Buf_Runbl_VcuRx_10ms_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT, sizeof(DT_IPM_BMS_5_BatTemp_EPT));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_BMS_6_DischrgRecup_EPT_IPM_BMS_6_DischrgRecup_EPT->value), (uint8*)&Rte_Buf_Runbl_VcuRx_10ms_IPM_BMS_6_DischrgRecup_EPT_IPM_BMS_6_DischrgRecup_EPT, sizeof(DT_IPM_BMS_6_DischrgRecup_EPT));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_BMS_9_BattInfo_EPT_IPM_BMS_9_BattInfo_EPT->value), (uint8*)&Rte_Buf_Runbl_VcuRx_10ms_IPM_BMS_9_BattInfo_EPT_IPM_BMS_9_BattInfo_EPT, sizeof(DT_IPM_BMS_9_BattInfo_EPT));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_EHB_B_CHA_IPM_EHB_B_CHA->value), (uint8*)&Rte_Buf_Runbl_VcuRx_10ms_IPM_EHB_B_CHA_IPM_EHB_B_CHA, sizeof(DT_IPM_EHB_B_CHA));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA->value), (uint8*)&Rte_Buf_Runbl_VcuRx_10ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA, sizeof(DT_IPM_ESC_7_FuncStatus_CHA));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_ESC_A_CHA_IPM_ESC_A_CHA->value), (uint8*)&Rte_Buf_Runbl_VcuRx_10ms_IPM_ESC_A_CHA_IPM_ESC_A_CHA, sizeof(DT_IPM_ESC_A_CHA));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_FCM_B_CHA_IPM_FCM_B_CHA->value), (uint8*)&Rte_Buf_Runbl_VcuRx_10ms_IPM_FCM_B_CHA_IPM_FCM_B_CHA, sizeof(DT_IPM_FCM_B_CHA));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_HU_B_BAC_IPM_HU_B_BAC->value), (uint8*)&Rte_Buf_Runbl_VcuRx_10ms_IPM_HU_B_BAC_IPM_HU_B_BAC, sizeof(DT_IPM_HU_B_BAC));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_INV_1_Value_EPT_IPM_INV_1_Value_EPT->value), (uint8*)&Rte_Buf_Runbl_VcuRx_10ms_IPM_INV_1_Value_EPT_IPM_INV_1_Value_EPT, sizeof(DT_IPM_INV_1_Value_EPT));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT->value), (uint8*)&Rte_Buf_Runbl_VcuRx_10ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT, sizeof(DT_IPM_INV_2_Value_EPT));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_INV_3_Value_EPT_IPM_INV_3_Value_EPT->value), (uint8*)&Rte_Buf_Runbl_VcuRx_10ms_IPM_INV_3_Value_EPT_IPM_INV_3_Value_EPT, sizeof(DT_IPM_INV_3_Value_EPT));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_INV_4_Value_EPT_IPM_INV_4_Value_EPT->value), (uint8*)&Rte_Buf_Runbl_VcuRx_10ms_IPM_INV_4_Value_EPT_IPM_INV_4_Value_EPT, sizeof(DT_IPM_INV_4_Value_EPT));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_IPU_DCC_1_State_EPT_IPM_IPU_DCC_1_State_EPT->value), (uint8*)&Rte_Buf_Runbl_VcuRx_10ms_IPM_IPU_DCC_1_State_EPT_IPM_IPU_DCC_1_State_EPT, sizeof(DT_IPM_IPU_DCC_1_State_EPT));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_IPU_OBC_1_State_EPT_IPM_IPU_OBC_1_State_EPT->value), (uint8*)&Rte_Buf_Runbl_VcuRx_10ms_IPM_IPU_OBC_1_State_EPT_IPM_IPU_OBC_1_State_EPT, sizeof(DT_IPM_IPU_OBC_1_State_EPT));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_SCS_RiSwitchSts_BOD_IPM_SCS_RiSwitchSts_BOD->value), (uint8*)&Rte_Buf_Runbl_VcuRx_10ms_IPM_SCS_RiSwitchSts_BOD_IPM_SCS_RiSwitchSts_BOD, sizeof(DT_IPM_SCS_RiSwitchSts_BOD));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA->value), (uint8*)&Rte_Buf_Runbl_VcuRx_10ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA, sizeof(DT_IPM_SRS_1_Status_CHA));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_MsgActv_outputs_MsgActv_outputs->value), (uint8*)&Rte_Buf_Runbl_VcuRx_10ms_MsgActv_outputs_MsgActv_outputs, sizeof(DT_MsgActv));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs->value), (uint8*)&Rte_Buf_Runbl_VcuRx_10ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs, sizeof(TMS2VCU_AC_2_State_Outputs));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_Tms2Vcu_Info_Tms2Vcu_Info->value), (uint8*)&Rte_Buf_Runbl_VcuRx_10ms_Tms2Vcu_Info_Tms2Vcu_Info, sizeof(Tms2Vcu_Info));
        ResumeAllInterrupts();
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
static void Rte_PRE_Runbl_VcuTx_10ms(void)
{
    if (RteInitState == RTE_INITED)
    {
        SuspendAllInterrupts();
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VcuTx_10ms_BSW2VCU_outputs, (uint8*)&Irv_AppSwcVcu_BSW2VCU_outputs, sizeof(BSW2VCU_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VcuTx_10ms_Bcm2VcuTms_outputs, (uint8*)&Irv_AppSwcVcu_Bcm2VcuTms_outputs, sizeof(DT_Bcm2VcuTms_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VcuTx_10ms_DAG_Comm_outputsIRV, (uint8*)&Irv_AppSwcVcu_DAG_Comm_outputsIRV, sizeof(DAG_Comm_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VcuTx_10ms_DAG_FltActn_outputs, (uint8*)&Irv_AppSwcVcu_DAG_FltActn_outputs, sizeof(DAG_FltActn_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VcuTx_10ms_EMS_outputs, (uint8*)&Irv_AppSwcVcu_EMS_outputs, sizeof(EMS_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VcuTx_10ms_GSM_outputs, (uint8*)&Irv_AppSwcVcu_GSM_outputs, sizeof(GSM_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VcuTx_10ms_HMI_outputs, (uint8*)&Irv_AppSwcVcu_HMI_outputs, sizeof(HMI_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VcuTx_10ms_HVM_outputs, (uint8*)&Irv_AppSwcVcu_HVM_outputs, sizeof(HVM_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VcuTx_10ms_IPC_outputs, (uint8*)&Irv_AppSwcVcu_IPC_outputs, sizeof(IPC_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VcuTx_10ms_IPM_INV_2_Value_EPT, (uint8*)&Irv_AppSwcVcu_IPM_INV_2_Value_EPT, sizeof(DT_IPM_INV_2_Value_EPT));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VcuTx_10ms_NVM_Imdt_outputs, (uint8*)&Irv_AppSwcVcu_NVM_Imdt_outputs, sizeof(NVM_Imdt_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VcuTx_10ms_RME_outputs, (uint8*)&Irv_AppSwcVcu_RME_outputs, sizeof(RME_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VcuTx_10ms_SIBS_Output, (uint8*)&Irv_AppSwcVcu_SIBS_Output, sizeof(DT_SIBS_Output));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VcuTx_10ms_TBOX_outputs, (uint8*)&Irv_AppSwcVcu_TBOX_outputs, sizeof(TBOX_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VcuTx_10ms_Tms2Vcu_Info, (uint8*)&Irv_AppSwcVcu_Tms2Vcu_Info, sizeof(Tms2Vcu_Info));
        Irv_AppSwcVcu_Runbl_VcuTx_10ms_VDAG_VCUErrCode_enum = Irv_AppSwcVcu_VDAG_VCUErrCode_enum;
        Irv_AppSwcVcu_Runbl_VcuTx_10ms_VDAG_VCUFltLvl_enum = Irv_AppSwcVcu_VDAG_VCUFltLvl_enum;
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VcuTx_10ms_VSO_outputs, (uint8*)&Irv_AppSwcVcu_VSO_outputs, sizeof(VSO_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VcuTx_10ms_VTM_outputs, (uint8*)&Irv_AppSwcVcu_VTM_outputs, sizeof(VTM_outputs));
        ResumeAllInterrupts();
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
static void Rte_POST_AppSwcVcu_Init(void)
{
    if (RteInitState == RTE_INITED)
    {
        SuspendAllInterrupts();
        rte_memcpy((uint8*)&Irv_AppSwcVcu_DAG_Comm_outputsIRV, (uint8*)&Irv_AppSwcVcu_AppSwcVcu_Init_DAG_Comm_outputsIRV, sizeof(DAG_Comm_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_DAG_FltActn_outputs, (uint8*)&Irv_AppSwcVcu_AppSwcVcu_Init_DAG_FltActn_outputs, sizeof(DAG_FltActn_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_DAG_Other_outputs, (uint8*)&Irv_AppSwcVcu_AppSwcVcu_Init_DAG_Other_outputs, sizeof(DAG_Other_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_DAG_Sensor10ms_outputs, (uint8*)&Irv_AppSwcVcu_AppSwcVcu_Init_DAG_Sensor10ms_outputs, sizeof(DAG_Sensor10ms_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_DSA_outputs, (uint8*)&Irv_AppSwcVcu_AppSwcVcu_Init_DSA_outputs, sizeof(DSA_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_EMS_outputs, (uint8*)&Irv_AppSwcVcu_AppSwcVcu_Init_EMS_outputs, sizeof(EMS_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_GSM_outputs, (uint8*)&Irv_AppSwcVcu_AppSwcVcu_Init_GSM_outputs, sizeof(GSM_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_HMI_outputs, (uint8*)&Irv_AppSwcVcu_AppSwcVcu_Init_HMI_outputs, sizeof(HMI_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_HVM_outputs, (uint8*)&Irv_AppSwcVcu_AppSwcVcu_Init_HVM_outputs, sizeof(HVM_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_IPC_outputs, (uint8*)&Irv_AppSwcVcu_AppSwcVcu_Init_IPC_outputs, sizeof(IPC_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_NVM_Imdt_outputs, (uint8*)&Irv_AppSwcVcu_AppSwcVcu_Init_NVM_Imdt_outputs, sizeof(NVM_Imdt_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_NVM_outputs, (uint8*)&Irv_AppSwcVcu_AppSwcVcu_Init_NVM_outputs, sizeof(NVM_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_RME_outputs, (uint8*)&Irv_AppSwcVcu_AppSwcVcu_Init_RME_outputs, sizeof(RME_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_SIBS_Output, (uint8*)&Irv_AppSwcVcu_AppSwcVcu_Init_SIBS_Output, sizeof(DT_SIBS_Output));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_TBOX_outputs, (uint8*)&Irv_AppSwcVcu_AppSwcVcu_Init_TBOX_outputs, sizeof(TBOX_outputs));
        Irv_AppSwcVcu_VDAG_VCUFltLvl_enum = Irv_AppSwcVcu_AppSwcVcu_Init_VDAG_VCUFltLvl_enum;
        rte_memcpy((uint8*)&Irv_AppSwcVcu_VSO_outputs, (uint8*)&Irv_AppSwcVcu_AppSwcVcu_Init_VSO_outputs, sizeof(VSO_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_VTM_outputs, (uint8*)&Irv_AppSwcVcu_AppSwcVcu_Init_VTM_outputs, sizeof(VTM_outputs));
        ResumeAllInterrupts();
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
static void Rte_POST_Runbl_VCU_100ms(void)
{
    if (RteInitState == RTE_INITED)
    {
        SuspendAllInterrupts();
        rte_memcpy((uint8*)&Irv_AppSwcVcu_DSA_outputs, (uint8*)&Irv_AppSwcVcu_Runbl_VCU_100ms_DSA_outputs, sizeof(DSA_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_HMI_outputs, (uint8*)&Irv_AppSwcVcu_Runbl_VCU_100ms_HMI_outputs, sizeof(HMI_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_RME_outputs, (uint8*)&Irv_AppSwcVcu_Runbl_VCU_100ms_RME_outputs, sizeof(RME_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_SIBS_Output, (uint8*)&Irv_AppSwcVcu_Runbl_VCU_100ms_SIBS_Output, sizeof(DT_SIBS_Output));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_TBOX_outputs, (uint8*)&Irv_AppSwcVcu_Runbl_VCU_100ms_TBOX_outputs, sizeof(TBOX_outputs));
        ResumeAllInterrupts();
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
static void Rte_POST_Runbl_VCU_10ms(void)
{
    if (RteInitState == RTE_INITED)
    {
        SuspendAllInterrupts();
        rte_memcpy((uint8*)&Irv_AppSwcVcu_IPC_outputs, (uint8*)&Irv_AppSwcVcu_Runbl_VCU_10ms_IPC_outputs, sizeof(IPC_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_VSO_outputs, (uint8*)&Irv_AppSwcVcu_Runbl_VCU_10ms_VSO_outputs, sizeof(VSO_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_VTM_outputs, (uint8*)&Irv_AppSwcVcu_Runbl_VCU_10ms_VTM_outputs, sizeof(VTM_outputs));
        ResumeAllInterrupts();
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
static void Rte_POST_Runbl_VCU_20ms(void)
{
    if (RteInitState == RTE_INITED)
    {
        SuspendAllInterrupts();
        rte_memcpy((uint8*)&Irv_AppSwcVcu_DAG_Comm_outputsIRV, (uint8*)&Irv_AppSwcVcu_Runbl_VCU_20ms_DAG_Comm_outputsIRV, sizeof(DAG_Comm_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_DAG_FltActn_outputs, (uint8*)&Irv_AppSwcVcu_Runbl_VCU_20ms_DAG_FltActn_outputs, sizeof(DAG_FltActn_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_DAG_Other_outputs, (uint8*)&Irv_AppSwcVcu_Runbl_VCU_20ms_DAG_Other_outputs, sizeof(DAG_Other_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_DAG_Sensor10ms_outputs, (uint8*)&Irv_AppSwcVcu_Runbl_VCU_20ms_DAG_Sensor10ms_outputs, sizeof(DAG_Sensor10ms_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_EMS_outputs, (uint8*)&Irv_AppSwcVcu_Runbl_VCU_20ms_EMS_outputs, sizeof(EMS_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_GSM_outputs, (uint8*)&Irv_AppSwcVcu_Runbl_VCU_20ms_GSM_outputs, sizeof(GSM_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_HVM_outputs, (uint8*)&Irv_AppSwcVcu_Runbl_VCU_20ms_HVM_outputs, sizeof(HVM_outputs));
        Irv_AppSwcVcu_VDAG_VCUErrCode_enum = Irv_AppSwcVcu_Runbl_VCU_20ms_VDAG_VCUErrCode_enum;
        Irv_AppSwcVcu_VDAG_VCUFltLvl_enum = Irv_AppSwcVcu_Runbl_VCU_20ms_VDAG_VCUFltLvl_enum;
        ResumeAllInterrupts();
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
static void Rte_POST_Runbl_VcuRx_10ms(void)
{
    if (RteInitState == RTE_INITED)
    {
        SuspendAllInterrupts();
        rte_memcpy((uint8*)&Irv_AppSwcVcu_BSW2VCU_outputs, (uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_BSW2VCU_outputs, sizeof(BSW2VCU_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Bcm2VcuTms_outputs, (uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_Bcm2VcuTms_outputs, sizeof(DT_Bcm2VcuTms_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_CANCommErr_outputs, (uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_CANCommErr_outputs, sizeof(DT_CANCommErr));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_HardWire_Input_VCU, (uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_HardWire_Input_VCU, sizeof(DT_HardWire_Input_VCU));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_IPM_BMS_10_DC_ChargeStates_EPT, (uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_BMS_10_DC_ChargeStates_EPT, sizeof(DT_IPM_BMS_10_DC_ChargeStates_EPT));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_IPM_BMS_1_MainState_EPT, (uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_BMS_1_MainState_EPT, sizeof(DT_IPM_BMS_1_MainState_EPT));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_IPM_BMS_2_BatState_EPT, (uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_BMS_2_BatState_EPT, sizeof(DT_IPM_BMS_2_BatState_EPT));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_IPM_BMS_5_BatTemp_EPT, (uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_BMS_5_BatTemp_EPT, sizeof(DT_IPM_BMS_5_BatTemp_EPT));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_IPM_BMS_6_DischrgRecup_EPT, (uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_BMS_6_DischrgRecup_EPT, sizeof(DT_IPM_BMS_6_DischrgRecup_EPT));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_IPM_BMS_9_BattInfo_EPT, (uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_BMS_9_BattInfo_EPT, sizeof(DT_IPM_BMS_9_BattInfo_EPT));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_IPM_EHB_B_CHA, (uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_EHB_B_CHA, sizeof(DT_IPM_EHB_B_CHA));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_IPM_ESC_7_FuncStatus_CHA, (uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_ESC_7_FuncStatus_CHA, sizeof(DT_IPM_ESC_7_FuncStatus_CHA));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_IPM_ESC_A_CHA, (uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_ESC_A_CHA, sizeof(DT_IPM_ESC_A_CHA));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_IPM_FCM_B_CHA, (uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_FCM_B_CHA, sizeof(DT_IPM_FCM_B_CHA));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_IPM_HU_B_BAC, (uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_HU_B_BAC, sizeof(DT_IPM_HU_B_BAC));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_IPM_INV_1_Value_EPT, (uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_INV_1_Value_EPT, sizeof(DT_IPM_INV_1_Value_EPT));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_IPM_INV_2_Value_EPT, (uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_INV_2_Value_EPT, sizeof(DT_IPM_INV_2_Value_EPT));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_IPM_INV_3_Value_EPT, (uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_INV_3_Value_EPT, sizeof(DT_IPM_INV_3_Value_EPT));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_IPM_INV_4_Value_EPT, (uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_INV_4_Value_EPT, sizeof(DT_IPM_INV_4_Value_EPT));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_IPM_IPU_DCC_1_State_EPT, (uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_IPU_DCC_1_State_EPT, sizeof(DT_IPM_IPU_DCC_1_State_EPT));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_IPM_IPU_OBC_1_State_EPT, (uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_IPU_OBC_1_State_EPT, sizeof(DT_IPM_IPU_OBC_1_State_EPT));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_IPM_SCS_RiSwitchSts_BOD, (uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_SCS_RiSwitchSts_BOD, sizeof(DT_IPM_SCS_RiSwitchSts_BOD));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_IPM_SRS_1_Status_CHA, (uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_SRS_1_Status_CHA, sizeof(DT_IPM_SRS_1_Status_CHA));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_MsgActv_outputs, (uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_MsgActv_outputs, sizeof(DT_MsgActv));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_NVM_Imdt_outputs, (uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_NVM_Imdt_outputs, sizeof(NVM_Imdt_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_NVM_outputs, (uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_NVM_outputs, sizeof(NVM_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_TMS2VCU_AC_2_State_Outputs, (uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_TMS2VCU_AC_2_State_Outputs, sizeof(TMS2VCU_AC_2_State_Outputs));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Tms2Vcu_Info, (uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_Tms2Vcu_Info, sizeof(Tms2Vcu_Info));
        rte_memcpy((uint8*)&Irv_AppSwcVcu_VehCfg_outputs, (uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_VehCfg_outputs, sizeof(VehCfg_outputs));
        ResumeAllInterrupts();
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
static void Rte_POST_Runbl_VcuTx_10ms(void)
{
    if (RteInitState == RTE_INITED)
    {
        SuspendAllInterrupts();
        Rte_WriteBuffer_Rte_Buf_Runbl_VcuTx_10ms_DAG_Comm_outputs_DAG_Comm_outputs(Rte_Inst_AppSwcVcu.Runbl_VcuTx_10ms_DAG_Comm_outputs_DAG_Comm_outputs->value);
        Rte_WriteBuffer_Rte_Buf_Runbl_VcuTx_10ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs(Rte_Inst_AppSwcVcu.Runbl_VcuTx_10ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs->value);
        Rte_WriteBuffer_Rte_Buf_Runbl_VcuTx_10ms_Vcu2OpmBAC_outputs_Vcu2OpmBAC_outputs(Rte_Inst_AppSwcVcu.Runbl_VcuTx_10ms_Vcu2OpmBAC_outputs_Vcu2OpmBAC_outputs->value);
        Rte_WriteBuffer_Rte_Buf_Runbl_VcuTx_10ms_Vcu2OpmCHA_outputs_Vcu2OpmCHA_outputs(Rte_Inst_AppSwcVcu.Runbl_VcuTx_10ms_Vcu2OpmCHA_outputs_Vcu2OpmCHA_outputs->value);
        Rte_WriteBuffer_Rte_Buf_Runbl_VcuTx_10ms_Vcu2OpmEPT_outputs_Vcu2OpmEPT_outputs(Rte_Inst_AppSwcVcu.Runbl_VcuTx_10ms_Vcu2OpmEPT_outputs_Vcu2OpmEPT_outputs->value);
        ResumeAllInterrupts();
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
 **                        Global Function Definitions                        **
******************************************************************************/

/*******************************************************************************
*Function-Name        Runbl_VCU_100ms
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
void Rte_Runbl_VCU_100ms(void)
{
    Rte_PRE_Runbl_VCU_100ms();
    if (RteInitState == RTE_INITED)
    {
        Runbl_VCU_100ms();
    }
    Rte_POST_Runbl_VCU_100ms();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Runbl_VCU_10ms
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
void Rte_Runbl_VCU_10ms(void)
{
    Rte_PRE_Runbl_VCU_10ms();
    if (RteInitState == RTE_INITED)
    {
        Runbl_VCU_10ms();
    }
    Rte_POST_Runbl_VCU_10ms();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Runbl_VCU_20ms
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
void Rte_Runbl_VCU_20ms(void)
{
    Rte_PRE_Runbl_VCU_20ms();
    if (RteInitState == RTE_INITED)
    {
        Runbl_VCU_20ms();
    }
    Rte_POST_Runbl_VCU_20ms();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Runbl_VcuRx_10ms
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
void Rte_Runbl_VcuRx_10ms(void)
{
    Rte_PRE_Runbl_VcuRx_10ms();
    if (RteInitState == RTE_INITED)
    {
        Runbl_VcuRx_10ms();
    }
    Rte_POST_Runbl_VcuRx_10ms();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Runbl_VcuTx_10ms
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
void Rte_Runbl_VcuTx_10ms(void)
{
    Rte_PRE_Runbl_VcuTx_10ms();
    if (RteInitState == RTE_INITED)
    {
        Runbl_VcuTx_10ms();
    }
    Rte_POST_Runbl_VcuTx_10ms();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        AppSwcVcu_Init
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
void Rte_AppSwcVcu_Init(void)
{
    if (RteInitState == RTE_INITED)
    {
        AppSwcVcu_Init();
    }
    Rte_POST_AppSwcVcu_Init();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_100ms_BSW2VCU_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               BSW2VCU_outputs*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
BSW2VCU_outputs* Rte_IrvIRead_Runbl_VCU_100ms_BSW2VCU_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_100ms_BSW2VCU_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_10ms_BSW2VCU_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               BSW2VCU_outputs*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
BSW2VCU_outputs* Rte_IrvIRead_Runbl_VCU_10ms_BSW2VCU_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_10ms_BSW2VCU_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_20ms_BSW2VCU_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               BSW2VCU_outputs*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
BSW2VCU_outputs* Rte_IrvIRead_Runbl_VCU_20ms_BSW2VCU_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_20ms_BSW2VCU_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_VcuRx_10ms_BSW2VCU_outputs
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
void Rte_IrvIWrite_Runbl_VcuRx_10ms_BSW2VCU_outputs(BSW2VCU_outputs* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_BSW2VCU_outputs, (uint8*)data, sizeof(BSW2VCU_outputs));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_VcuRx_10ms_BSW2VCU_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               BSW2VCU_outputs *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
BSW2VCU_outputs * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_BSW2VCU_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VcuRx_10ms_BSW2VCU_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VcuTx_10ms_BSW2VCU_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               BSW2VCU_outputs*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
BSW2VCU_outputs* Rte_IrvIRead_Runbl_VcuTx_10ms_BSW2VCU_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VcuTx_10ms_BSW2VCU_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_100ms_Bcm2VcuTms_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_Bcm2VcuTms_outputs*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_Bcm2VcuTms_outputs* Rte_IrvIRead_Runbl_VCU_100ms_Bcm2VcuTms_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_100ms_Bcm2VcuTms_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_20ms_Bcm2VcuTms_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_Bcm2VcuTms_outputs*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_Bcm2VcuTms_outputs* Rte_IrvIRead_Runbl_VCU_20ms_Bcm2VcuTms_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_20ms_Bcm2VcuTms_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_VcuRx_10ms_Bcm2VcuTms_outputs
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
void Rte_IrvIWrite_Runbl_VcuRx_10ms_Bcm2VcuTms_outputs(DT_Bcm2VcuTms_outputs* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_Bcm2VcuTms_outputs, (uint8*)data, sizeof(DT_Bcm2VcuTms_outputs));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_VcuRx_10ms_Bcm2VcuTms_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_Bcm2VcuTms_outputs *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_Bcm2VcuTms_outputs * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_Bcm2VcuTms_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VcuRx_10ms_Bcm2VcuTms_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VcuTx_10ms_Bcm2VcuTms_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_Bcm2VcuTms_outputs*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_Bcm2VcuTms_outputs* Rte_IrvIRead_Runbl_VcuTx_10ms_Bcm2VcuTms_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VcuTx_10ms_Bcm2VcuTms_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_100ms_CANCommErr_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_CANCommErr*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_CANCommErr* Rte_IrvIRead_Runbl_VCU_100ms_CANCommErr_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_100ms_CANCommErr_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_20ms_CANCommErr_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_CANCommErr*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_CANCommErr* Rte_IrvIRead_Runbl_VCU_20ms_CANCommErr_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_20ms_CANCommErr_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_VcuRx_10ms_CANCommErr_outputs
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
void Rte_IrvIWrite_Runbl_VcuRx_10ms_CANCommErr_outputs(DT_CANCommErr* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_CANCommErr_outputs, (uint8*)data, sizeof(DT_CANCommErr));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_VcuRx_10ms_CANCommErr_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_CANCommErr *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_CANCommErr * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_CANCommErr_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VcuRx_10ms_CANCommErr_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_AppSwcVcu_Init_DAG_Comm_outputsIRV
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
void Rte_IrvIWrite_AppSwcVcu_Init_DAG_Comm_outputsIRV(DAG_Comm_outputs* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_AppSwcVcu_Init_DAG_Comm_outputsIRV, (uint8*)data, sizeof(DAG_Comm_outputs));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_AppSwcVcu_Init_DAG_Comm_outputsIRV
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DAG_Comm_outputs *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DAG_Comm_outputs * Rte_IrvIWriteRef_AppSwcVcu_Init_DAG_Comm_outputsIRV(void)
{
    return &Irv_AppSwcVcu_AppSwcVcu_Init_DAG_Comm_outputsIRV;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_VCU_20ms_DAG_Comm_outputsIRV
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
void Rte_IrvIWrite_Runbl_VCU_20ms_DAG_Comm_outputsIRV(DAG_Comm_outputs* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_20ms_DAG_Comm_outputsIRV, (uint8*)data, sizeof(DAG_Comm_outputs));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_VCU_20ms_DAG_Comm_outputsIRV
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DAG_Comm_outputs *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DAG_Comm_outputs * Rte_IrvIWriteRef_Runbl_VCU_20ms_DAG_Comm_outputsIRV(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_20ms_DAG_Comm_outputsIRV;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VcuTx_10ms_DAG_Comm_outputsIRV
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DAG_Comm_outputs*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DAG_Comm_outputs* Rte_IrvIRead_Runbl_VcuTx_10ms_DAG_Comm_outputsIRV(void)
{
    return &Irv_AppSwcVcu_Runbl_VcuTx_10ms_DAG_Comm_outputsIRV;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_AppSwcVcu_Init_DAG_FltActn_outputs
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
void Rte_IrvIWrite_AppSwcVcu_Init_DAG_FltActn_outputs(DAG_FltActn_outputs* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_AppSwcVcu_Init_DAG_FltActn_outputs, (uint8*)data, sizeof(DAG_FltActn_outputs));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_AppSwcVcu_Init_DAG_FltActn_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DAG_FltActn_outputs *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DAG_FltActn_outputs * Rte_IrvIWriteRef_AppSwcVcu_Init_DAG_FltActn_outputs(void)
{
    return &Irv_AppSwcVcu_AppSwcVcu_Init_DAG_FltActn_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_100ms_DAG_FltActn_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DAG_FltActn_outputs*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DAG_FltActn_outputs* Rte_IrvIRead_Runbl_VCU_100ms_DAG_FltActn_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_100ms_DAG_FltActn_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_10ms_DAG_FltActn_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DAG_FltActn_outputs*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DAG_FltActn_outputs* Rte_IrvIRead_Runbl_VCU_10ms_DAG_FltActn_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_10ms_DAG_FltActn_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_VCU_20ms_DAG_FltActn_outputs
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
void Rte_IrvIWrite_Runbl_VCU_20ms_DAG_FltActn_outputs(DAG_FltActn_outputs* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_20ms_DAG_FltActn_outputs, (uint8*)data, sizeof(DAG_FltActn_outputs));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_VCU_20ms_DAG_FltActn_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DAG_FltActn_outputs *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DAG_FltActn_outputs * Rte_IrvIWriteRef_Runbl_VCU_20ms_DAG_FltActn_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_20ms_DAG_FltActn_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VcuTx_10ms_DAG_FltActn_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DAG_FltActn_outputs*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DAG_FltActn_outputs* Rte_IrvIRead_Runbl_VcuTx_10ms_DAG_FltActn_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VcuTx_10ms_DAG_FltActn_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_AppSwcVcu_Init_DAG_Other_outputs
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
void Rte_IrvIWrite_AppSwcVcu_Init_DAG_Other_outputs(DAG_Other_outputs* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_AppSwcVcu_Init_DAG_Other_outputs, (uint8*)data, sizeof(DAG_Other_outputs));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_AppSwcVcu_Init_DAG_Other_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DAG_Other_outputs *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DAG_Other_outputs * Rte_IrvIWriteRef_AppSwcVcu_Init_DAG_Other_outputs(void)
{
    return &Irv_AppSwcVcu_AppSwcVcu_Init_DAG_Other_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_100ms_DAG_Other_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DAG_Other_outputs*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DAG_Other_outputs* Rte_IrvIRead_Runbl_VCU_100ms_DAG_Other_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_100ms_DAG_Other_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_VCU_20ms_DAG_Other_outputs
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
void Rte_IrvIWrite_Runbl_VCU_20ms_DAG_Other_outputs(DAG_Other_outputs* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_20ms_DAG_Other_outputs, (uint8*)data, sizeof(DAG_Other_outputs));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_VCU_20ms_DAG_Other_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DAG_Other_outputs *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DAG_Other_outputs * Rte_IrvIWriteRef_Runbl_VCU_20ms_DAG_Other_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_20ms_DAG_Other_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_AppSwcVcu_Init_DAG_Sensor10ms_outputs
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
void Rte_IrvIWrite_AppSwcVcu_Init_DAG_Sensor10ms_outputs(DAG_Sensor10ms_outputs* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_AppSwcVcu_Init_DAG_Sensor10ms_outputs, (uint8*)data, sizeof(DAG_Sensor10ms_outputs));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_AppSwcVcu_Init_DAG_Sensor10ms_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DAG_Sensor10ms_outputs *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DAG_Sensor10ms_outputs * Rte_IrvIWriteRef_AppSwcVcu_Init_DAG_Sensor10ms_outputs(void)
{
    return &Irv_AppSwcVcu_AppSwcVcu_Init_DAG_Sensor10ms_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_10ms_DAG_Sensor10ms_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DAG_Sensor10ms_outputs*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DAG_Sensor10ms_outputs* Rte_IrvIRead_Runbl_VCU_10ms_DAG_Sensor10ms_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_10ms_DAG_Sensor10ms_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_VCU_20ms_DAG_Sensor10ms_outputs
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
void Rte_IrvIWrite_Runbl_VCU_20ms_DAG_Sensor10ms_outputs(DAG_Sensor10ms_outputs* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_20ms_DAG_Sensor10ms_outputs, (uint8*)data, sizeof(DAG_Sensor10ms_outputs));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_VCU_20ms_DAG_Sensor10ms_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DAG_Sensor10ms_outputs *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DAG_Sensor10ms_outputs * Rte_IrvIWriteRef_Runbl_VCU_20ms_DAG_Sensor10ms_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_20ms_DAG_Sensor10ms_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_AppSwcVcu_Init_DSA_outputs
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
void Rte_IrvIWrite_AppSwcVcu_Init_DSA_outputs(DSA_outputs* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_AppSwcVcu_Init_DSA_outputs, (uint8*)data, sizeof(DSA_outputs));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_AppSwcVcu_Init_DSA_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DSA_outputs *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DSA_outputs * Rte_IrvIWriteRef_AppSwcVcu_Init_DSA_outputs(void)
{
    return &Irv_AppSwcVcu_AppSwcVcu_Init_DSA_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_VCU_100ms_DSA_outputs
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
void Rte_IrvIWrite_Runbl_VCU_100ms_DSA_outputs(DSA_outputs* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_100ms_DSA_outputs, (uint8*)data, sizeof(DSA_outputs));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_VCU_100ms_DSA_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DSA_outputs *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DSA_outputs * Rte_IrvIWriteRef_Runbl_VCU_100ms_DSA_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_100ms_DSA_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_10ms_DSA_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DSA_outputs*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DSA_outputs* Rte_IrvIRead_Runbl_VCU_10ms_DSA_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_10ms_DSA_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_AppSwcVcu_Init_EMS_outputs
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
void Rte_IrvIWrite_AppSwcVcu_Init_EMS_outputs(EMS_outputs* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_AppSwcVcu_Init_EMS_outputs, (uint8*)data, sizeof(EMS_outputs));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_AppSwcVcu_Init_EMS_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               EMS_outputs *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
EMS_outputs * Rte_IrvIWriteRef_AppSwcVcu_Init_EMS_outputs(void)
{
    return &Irv_AppSwcVcu_AppSwcVcu_Init_EMS_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_100ms_EMS_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               EMS_outputs*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
EMS_outputs* Rte_IrvIRead_Runbl_VCU_100ms_EMS_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_100ms_EMS_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_10ms_EMS_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               EMS_outputs*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
EMS_outputs* Rte_IrvIRead_Runbl_VCU_10ms_EMS_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_10ms_EMS_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_VCU_20ms_EMS_outputs
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
void Rte_IrvIWrite_Runbl_VCU_20ms_EMS_outputs(EMS_outputs* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_20ms_EMS_outputs, (uint8*)data, sizeof(EMS_outputs));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_VCU_20ms_EMS_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               EMS_outputs *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
EMS_outputs * Rte_IrvIWriteRef_Runbl_VCU_20ms_EMS_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_20ms_EMS_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VcuTx_10ms_EMS_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               EMS_outputs*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
EMS_outputs* Rte_IrvIRead_Runbl_VcuTx_10ms_EMS_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VcuTx_10ms_EMS_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_AppSwcVcu_Init_GSM_outputs
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
void Rte_IrvIWrite_AppSwcVcu_Init_GSM_outputs(GSM_outputs* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_AppSwcVcu_Init_GSM_outputs, (uint8*)data, sizeof(GSM_outputs));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_AppSwcVcu_Init_GSM_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               GSM_outputs *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
GSM_outputs * Rte_IrvIWriteRef_AppSwcVcu_Init_GSM_outputs(void)
{
    return &Irv_AppSwcVcu_AppSwcVcu_Init_GSM_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_100ms_GSM_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               GSM_outputs*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
GSM_outputs* Rte_IrvIRead_Runbl_VCU_100ms_GSM_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_100ms_GSM_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_10ms_GSM_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               GSM_outputs*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
GSM_outputs* Rte_IrvIRead_Runbl_VCU_10ms_GSM_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_10ms_GSM_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_VCU_20ms_GSM_outputs
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
void Rte_IrvIWrite_Runbl_VCU_20ms_GSM_outputs(GSM_outputs* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_20ms_GSM_outputs, (uint8*)data, sizeof(GSM_outputs));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_VCU_20ms_GSM_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               GSM_outputs *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
GSM_outputs * Rte_IrvIWriteRef_Runbl_VCU_20ms_GSM_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_20ms_GSM_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VcuTx_10ms_GSM_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               GSM_outputs*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
GSM_outputs* Rte_IrvIRead_Runbl_VcuTx_10ms_GSM_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VcuTx_10ms_GSM_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_AppSwcVcu_Init_HMI_outputs
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
void Rte_IrvIWrite_AppSwcVcu_Init_HMI_outputs(HMI_outputs* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_AppSwcVcu_Init_HMI_outputs, (uint8*)data, sizeof(HMI_outputs));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_AppSwcVcu_Init_HMI_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               HMI_outputs *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
HMI_outputs * Rte_IrvIWriteRef_AppSwcVcu_Init_HMI_outputs(void)
{
    return &Irv_AppSwcVcu_AppSwcVcu_Init_HMI_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_VCU_100ms_HMI_outputs
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
void Rte_IrvIWrite_Runbl_VCU_100ms_HMI_outputs(HMI_outputs* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_100ms_HMI_outputs, (uint8*)data, sizeof(HMI_outputs));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_VCU_100ms_HMI_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               HMI_outputs *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
HMI_outputs * Rte_IrvIWriteRef_Runbl_VCU_100ms_HMI_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_100ms_HMI_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VcuTx_10ms_HMI_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               HMI_outputs*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
HMI_outputs* Rte_IrvIRead_Runbl_VcuTx_10ms_HMI_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VcuTx_10ms_HMI_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_AppSwcVcu_Init_HVM_outputs
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
void Rte_IrvIWrite_AppSwcVcu_Init_HVM_outputs(HVM_outputs* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_AppSwcVcu_Init_HVM_outputs, (uint8*)data, sizeof(HVM_outputs));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_AppSwcVcu_Init_HVM_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               HVM_outputs *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
HVM_outputs * Rte_IrvIWriteRef_AppSwcVcu_Init_HVM_outputs(void)
{
    return &Irv_AppSwcVcu_AppSwcVcu_Init_HVM_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_100ms_HVM_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               HVM_outputs*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
HVM_outputs* Rte_IrvIRead_Runbl_VCU_100ms_HVM_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_100ms_HVM_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_10ms_HVM_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               HVM_outputs*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
HVM_outputs* Rte_IrvIRead_Runbl_VCU_10ms_HVM_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_10ms_HVM_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_VCU_20ms_HVM_outputs
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
void Rte_IrvIWrite_Runbl_VCU_20ms_HVM_outputs(HVM_outputs* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_20ms_HVM_outputs, (uint8*)data, sizeof(HVM_outputs));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_VCU_20ms_HVM_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               HVM_outputs *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
HVM_outputs * Rte_IrvIWriteRef_Runbl_VCU_20ms_HVM_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_20ms_HVM_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VcuTx_10ms_HVM_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               HVM_outputs*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
HVM_outputs* Rte_IrvIRead_Runbl_VcuTx_10ms_HVM_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VcuTx_10ms_HVM_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_100ms_HardWire_Input_VCU
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_HardWire_Input_VCU*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_HardWire_Input_VCU* Rte_IrvIRead_Runbl_VCU_100ms_HardWire_Input_VCU(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_100ms_HardWire_Input_VCU;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_10ms_HardWire_Input_VCU
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_HardWire_Input_VCU*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_HardWire_Input_VCU* Rte_IrvIRead_Runbl_VCU_10ms_HardWire_Input_VCU(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_10ms_HardWire_Input_VCU;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_20ms_HardWire_Input_VCU
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_HardWire_Input_VCU*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_HardWire_Input_VCU* Rte_IrvIRead_Runbl_VCU_20ms_HardWire_Input_VCU(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_20ms_HardWire_Input_VCU;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_VcuRx_10ms_HardWire_Input_VCU
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
void Rte_IrvIWrite_Runbl_VcuRx_10ms_HardWire_Input_VCU(DT_HardWire_Input_VCU* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_HardWire_Input_VCU, (uint8*)data, sizeof(DT_HardWire_Input_VCU));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_VcuRx_10ms_HardWire_Input_VCU
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_HardWire_Input_VCU *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_HardWire_Input_VCU * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_HardWire_Input_VCU(void)
{
    return &Irv_AppSwcVcu_Runbl_VcuRx_10ms_HardWire_Input_VCU;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_AppSwcVcu_Init_IPC_outputs
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
void Rte_IrvIWrite_AppSwcVcu_Init_IPC_outputs(IPC_outputs* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_AppSwcVcu_Init_IPC_outputs, (uint8*)data, sizeof(IPC_outputs));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_AppSwcVcu_Init_IPC_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               IPC_outputs *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
IPC_outputs * Rte_IrvIWriteRef_AppSwcVcu_Init_IPC_outputs(void)
{
    return &Irv_AppSwcVcu_AppSwcVcu_Init_IPC_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_100ms_IPC_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               IPC_outputs*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
IPC_outputs* Rte_IrvIRead_Runbl_VCU_100ms_IPC_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_100ms_IPC_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_VCU_10ms_IPC_outputs
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
void Rte_IrvIWrite_Runbl_VCU_10ms_IPC_outputs(IPC_outputs* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_10ms_IPC_outputs, (uint8*)data, sizeof(IPC_outputs));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_VCU_10ms_IPC_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               IPC_outputs *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
IPC_outputs * Rte_IrvIWriteRef_Runbl_VCU_10ms_IPC_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_10ms_IPC_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_20ms_IPC_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               IPC_outputs*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
IPC_outputs* Rte_IrvIRead_Runbl_VCU_20ms_IPC_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_20ms_IPC_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VcuTx_10ms_IPC_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               IPC_outputs*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
IPC_outputs* Rte_IrvIRead_Runbl_VcuTx_10ms_IPC_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VcuTx_10ms_IPC_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_100ms_IPM_BMS_10_DC_ChargeStates_EPT
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_BMS_10_DC_ChargeStates_EPT*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_BMS_10_DC_ChargeStates_EPT* Rte_IrvIRead_Runbl_VCU_100ms_IPM_BMS_10_DC_ChargeStates_EPT(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_100ms_IPM_BMS_10_DC_ChargeStates_EPT;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_10ms_IPM_BMS_10_DC_ChargeStates_EPT
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_BMS_10_DC_ChargeStates_EPT*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_BMS_10_DC_ChargeStates_EPT* Rte_IrvIRead_Runbl_VCU_10ms_IPM_BMS_10_DC_ChargeStates_EPT(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_10ms_IPM_BMS_10_DC_ChargeStates_EPT;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_20ms_IPM_BMS_10_DC_ChargeStates_EPT
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_BMS_10_DC_ChargeStates_EPT*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_BMS_10_DC_ChargeStates_EPT* Rte_IrvIRead_Runbl_VCU_20ms_IPM_BMS_10_DC_ChargeStates_EPT(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_BMS_10_DC_ChargeStates_EPT;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_BMS_10_DC_ChargeStates_EPT
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
void Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_BMS_10_DC_ChargeStates_EPT(DT_IPM_BMS_10_DC_ChargeStates_EPT* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_BMS_10_DC_ChargeStates_EPT, (uint8*)data, sizeof(DT_IPM_BMS_10_DC_ChargeStates_EPT));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_BMS_10_DC_ChargeStates_EPT
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_BMS_10_DC_ChargeStates_EPT *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_BMS_10_DC_ChargeStates_EPT * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_BMS_10_DC_ChargeStates_EPT(void)
{
    return &Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_BMS_10_DC_ChargeStates_EPT;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_100ms_IPM_BMS_1_MainState_EPT
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_BMS_1_MainState_EPT*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_BMS_1_MainState_EPT* Rte_IrvIRead_Runbl_VCU_100ms_IPM_BMS_1_MainState_EPT(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_100ms_IPM_BMS_1_MainState_EPT;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_20ms_IPM_BMS_1_MainState_EPT
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_BMS_1_MainState_EPT*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_BMS_1_MainState_EPT* Rte_IrvIRead_Runbl_VCU_20ms_IPM_BMS_1_MainState_EPT(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_BMS_1_MainState_EPT;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_BMS_1_MainState_EPT
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
void Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_BMS_1_MainState_EPT(DT_IPM_BMS_1_MainState_EPT* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_BMS_1_MainState_EPT, (uint8*)data, sizeof(DT_IPM_BMS_1_MainState_EPT));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_BMS_1_MainState_EPT
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_BMS_1_MainState_EPT *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_BMS_1_MainState_EPT * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_BMS_1_MainState_EPT(void)
{
    return &Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_BMS_1_MainState_EPT;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_100ms_IPM_BMS_2_BatState_EPT
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_BMS_2_BatState_EPT*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_BMS_2_BatState_EPT* Rte_IrvIRead_Runbl_VCU_100ms_IPM_BMS_2_BatState_EPT(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_100ms_IPM_BMS_2_BatState_EPT;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_10ms_IPM_BMS_2_BatState_EPT
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_BMS_2_BatState_EPT*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_BMS_2_BatState_EPT* Rte_IrvIRead_Runbl_VCU_10ms_IPM_BMS_2_BatState_EPT(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_10ms_IPM_BMS_2_BatState_EPT;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_20ms_IPM_BMS_2_BatState_EPT
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_BMS_2_BatState_EPT*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_BMS_2_BatState_EPT* Rte_IrvIRead_Runbl_VCU_20ms_IPM_BMS_2_BatState_EPT(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_BMS_2_BatState_EPT;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_BMS_2_BatState_EPT
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
void Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_BMS_2_BatState_EPT(DT_IPM_BMS_2_BatState_EPT* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_BMS_2_BatState_EPT, (uint8*)data, sizeof(DT_IPM_BMS_2_BatState_EPT));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_BMS_2_BatState_EPT
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_BMS_2_BatState_EPT *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_BMS_2_BatState_EPT * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_BMS_2_BatState_EPT(void)
{
    return &Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_BMS_2_BatState_EPT;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_100ms_IPM_BMS_5_BatTemp_EPT
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_BMS_5_BatTemp_EPT*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_BMS_5_BatTemp_EPT* Rte_IrvIRead_Runbl_VCU_100ms_IPM_BMS_5_BatTemp_EPT(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_100ms_IPM_BMS_5_BatTemp_EPT;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_20ms_IPM_BMS_5_BatTemp_EPT
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_BMS_5_BatTemp_EPT*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_BMS_5_BatTemp_EPT* Rte_IrvIRead_Runbl_VCU_20ms_IPM_BMS_5_BatTemp_EPT(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_BMS_5_BatTemp_EPT;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_BMS_5_BatTemp_EPT
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
void Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_BMS_5_BatTemp_EPT(DT_IPM_BMS_5_BatTemp_EPT* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_BMS_5_BatTemp_EPT, (uint8*)data, sizeof(DT_IPM_BMS_5_BatTemp_EPT));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_BMS_5_BatTemp_EPT
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_BMS_5_BatTemp_EPT *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_BMS_5_BatTemp_EPT * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_BMS_5_BatTemp_EPT(void)
{
    return &Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_BMS_5_BatTemp_EPT;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_20ms_IPM_BMS_6_DischrgRecup_EPT
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_BMS_6_DischrgRecup_EPT*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_BMS_6_DischrgRecup_EPT* Rte_IrvIRead_Runbl_VCU_20ms_IPM_BMS_6_DischrgRecup_EPT(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_BMS_6_DischrgRecup_EPT;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_BMS_6_DischrgRecup_EPT
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
void Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_BMS_6_DischrgRecup_EPT(DT_IPM_BMS_6_DischrgRecup_EPT* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_BMS_6_DischrgRecup_EPT, (uint8*)data, sizeof(DT_IPM_BMS_6_DischrgRecup_EPT));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_BMS_6_DischrgRecup_EPT
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_BMS_6_DischrgRecup_EPT *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_BMS_6_DischrgRecup_EPT * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_BMS_6_DischrgRecup_EPT(void)
{
    return &Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_BMS_6_DischrgRecup_EPT;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_100ms_IPM_BMS_9_BattInfo_EPT
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_BMS_9_BattInfo_EPT*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_BMS_9_BattInfo_EPT* Rte_IrvIRead_Runbl_VCU_100ms_IPM_BMS_9_BattInfo_EPT(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_100ms_IPM_BMS_9_BattInfo_EPT;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_20ms_IPM_BMS_9_BattInfo_EPT
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_BMS_9_BattInfo_EPT*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_BMS_9_BattInfo_EPT* Rte_IrvIRead_Runbl_VCU_20ms_IPM_BMS_9_BattInfo_EPT(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_BMS_9_BattInfo_EPT;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_BMS_9_BattInfo_EPT
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
void Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_BMS_9_BattInfo_EPT(DT_IPM_BMS_9_BattInfo_EPT* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_BMS_9_BattInfo_EPT, (uint8*)data, sizeof(DT_IPM_BMS_9_BattInfo_EPT));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_BMS_9_BattInfo_EPT
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_BMS_9_BattInfo_EPT *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_BMS_9_BattInfo_EPT * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_BMS_9_BattInfo_EPT(void)
{
    return &Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_BMS_9_BattInfo_EPT;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_10ms_IPM_EHB_B_CHA
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_EHB_B_CHA*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_EHB_B_CHA* Rte_IrvIRead_Runbl_VCU_10ms_IPM_EHB_B_CHA(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_10ms_IPM_EHB_B_CHA;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_20ms_IPM_EHB_B_CHA
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_EHB_B_CHA*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_EHB_B_CHA* Rte_IrvIRead_Runbl_VCU_20ms_IPM_EHB_B_CHA(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_EHB_B_CHA;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_EHB_B_CHA
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
void Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_EHB_B_CHA(DT_IPM_EHB_B_CHA* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_EHB_B_CHA, (uint8*)data, sizeof(DT_IPM_EHB_B_CHA));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_EHB_B_CHA
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_EHB_B_CHA *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_EHB_B_CHA * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_EHB_B_CHA(void)
{
    return &Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_EHB_B_CHA;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_100ms_IPM_ESC_7_FuncStatus_CHA
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_ESC_7_FuncStatus_CHA*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_ESC_7_FuncStatus_CHA* Rte_IrvIRead_Runbl_VCU_100ms_IPM_ESC_7_FuncStatus_CHA(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_100ms_IPM_ESC_7_FuncStatus_CHA;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_10ms_IPM_ESC_7_FuncStatus_CHA
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_ESC_7_FuncStatus_CHA*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_ESC_7_FuncStatus_CHA* Rte_IrvIRead_Runbl_VCU_10ms_IPM_ESC_7_FuncStatus_CHA(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_10ms_IPM_ESC_7_FuncStatus_CHA;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_20ms_IPM_ESC_7_FuncStatus_CHA
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_ESC_7_FuncStatus_CHA*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_ESC_7_FuncStatus_CHA* Rte_IrvIRead_Runbl_VCU_20ms_IPM_ESC_7_FuncStatus_CHA(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_ESC_7_FuncStatus_CHA;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_ESC_7_FuncStatus_CHA
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
void Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_ESC_7_FuncStatus_CHA(DT_IPM_ESC_7_FuncStatus_CHA* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_ESC_7_FuncStatus_CHA, (uint8*)data, sizeof(DT_IPM_ESC_7_FuncStatus_CHA));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_ESC_7_FuncStatus_CHA
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_ESC_7_FuncStatus_CHA *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_ESC_7_FuncStatus_CHA * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_ESC_7_FuncStatus_CHA(void)
{
    return &Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_ESC_7_FuncStatus_CHA;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_100ms_IPM_ESC_A_CHA
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_ESC_A_CHA*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_ESC_A_CHA* Rte_IrvIRead_Runbl_VCU_100ms_IPM_ESC_A_CHA(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_100ms_IPM_ESC_A_CHA;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_10ms_IPM_ESC_A_CHA
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_ESC_A_CHA*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_ESC_A_CHA* Rte_IrvIRead_Runbl_VCU_10ms_IPM_ESC_A_CHA(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_10ms_IPM_ESC_A_CHA;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_ESC_A_CHA
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
void Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_ESC_A_CHA(DT_IPM_ESC_A_CHA* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_ESC_A_CHA, (uint8*)data, sizeof(DT_IPM_ESC_A_CHA));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_ESC_A_CHA
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_ESC_A_CHA *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_ESC_A_CHA * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_ESC_A_CHA(void)
{
    return &Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_ESC_A_CHA;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_10ms_IPM_FCM_B_CHA
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_FCM_B_CHA*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_FCM_B_CHA* Rte_IrvIRead_Runbl_VCU_10ms_IPM_FCM_B_CHA(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_10ms_IPM_FCM_B_CHA;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_20ms_IPM_FCM_B_CHA
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_FCM_B_CHA*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_FCM_B_CHA* Rte_IrvIRead_Runbl_VCU_20ms_IPM_FCM_B_CHA(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_FCM_B_CHA;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_FCM_B_CHA
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
void Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_FCM_B_CHA(DT_IPM_FCM_B_CHA* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_FCM_B_CHA, (uint8*)data, sizeof(DT_IPM_FCM_B_CHA));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_FCM_B_CHA
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_FCM_B_CHA *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_FCM_B_CHA * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_FCM_B_CHA(void)
{
    return &Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_FCM_B_CHA;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_100ms_IPM_HU_B_BAC
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_HU_B_BAC*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_HU_B_BAC* Rte_IrvIRead_Runbl_VCU_100ms_IPM_HU_B_BAC(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_100ms_IPM_HU_B_BAC;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_10ms_IPM_HU_B_BAC
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_HU_B_BAC*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_HU_B_BAC* Rte_IrvIRead_Runbl_VCU_10ms_IPM_HU_B_BAC(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_10ms_IPM_HU_B_BAC;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_20ms_IPM_HU_B_BAC
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_HU_B_BAC*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_HU_B_BAC* Rte_IrvIRead_Runbl_VCU_20ms_IPM_HU_B_BAC(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_HU_B_BAC;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_HU_B_BAC
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
void Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_HU_B_BAC(DT_IPM_HU_B_BAC* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_HU_B_BAC, (uint8*)data, sizeof(DT_IPM_HU_B_BAC));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_HU_B_BAC
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_HU_B_BAC *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_HU_B_BAC * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_HU_B_BAC(void)
{
    return &Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_HU_B_BAC;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_10ms_IPM_INV_1_Value_EPT
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_INV_1_Value_EPT*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_INV_1_Value_EPT* Rte_IrvIRead_Runbl_VCU_10ms_IPM_INV_1_Value_EPT(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_10ms_IPM_INV_1_Value_EPT;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_20ms_IPM_INV_1_Value_EPT
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_INV_1_Value_EPT*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_INV_1_Value_EPT* Rte_IrvIRead_Runbl_VCU_20ms_IPM_INV_1_Value_EPT(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_INV_1_Value_EPT;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_INV_1_Value_EPT
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
void Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_INV_1_Value_EPT(DT_IPM_INV_1_Value_EPT* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_INV_1_Value_EPT, (uint8*)data, sizeof(DT_IPM_INV_1_Value_EPT));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_INV_1_Value_EPT
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_INV_1_Value_EPT *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_INV_1_Value_EPT * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_INV_1_Value_EPT(void)
{
    return &Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_INV_1_Value_EPT;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_10ms_IPM_INV_2_Value_EPT
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_INV_2_Value_EPT*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_INV_2_Value_EPT* Rte_IrvIRead_Runbl_VCU_10ms_IPM_INV_2_Value_EPT(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_10ms_IPM_INV_2_Value_EPT;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_20ms_IPM_INV_2_Value_EPT
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_INV_2_Value_EPT*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_INV_2_Value_EPT* Rte_IrvIRead_Runbl_VCU_20ms_IPM_INV_2_Value_EPT(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_INV_2_Value_EPT;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_INV_2_Value_EPT
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
void Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_INV_2_Value_EPT(DT_IPM_INV_2_Value_EPT* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_INV_2_Value_EPT, (uint8*)data, sizeof(DT_IPM_INV_2_Value_EPT));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_INV_2_Value_EPT
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_INV_2_Value_EPT *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_INV_2_Value_EPT * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_INV_2_Value_EPT(void)
{
    return &Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_INV_2_Value_EPT;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VcuTx_10ms_IPM_INV_2_Value_EPT
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_INV_2_Value_EPT*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_INV_2_Value_EPT* Rte_IrvIRead_Runbl_VcuTx_10ms_IPM_INV_2_Value_EPT(void)
{
    return &Irv_AppSwcVcu_Runbl_VcuTx_10ms_IPM_INV_2_Value_EPT;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_100ms_IPM_INV_3_Value_EPT
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_INV_3_Value_EPT*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_INV_3_Value_EPT* Rte_IrvIRead_Runbl_VCU_100ms_IPM_INV_3_Value_EPT(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_100ms_IPM_INV_3_Value_EPT;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_10ms_IPM_INV_3_Value_EPT
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_INV_3_Value_EPT*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_INV_3_Value_EPT* Rte_IrvIRead_Runbl_VCU_10ms_IPM_INV_3_Value_EPT(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_10ms_IPM_INV_3_Value_EPT;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_INV_3_Value_EPT
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
void Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_INV_3_Value_EPT(DT_IPM_INV_3_Value_EPT* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_INV_3_Value_EPT, (uint8*)data, sizeof(DT_IPM_INV_3_Value_EPT));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_INV_3_Value_EPT
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_INV_3_Value_EPT *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_INV_3_Value_EPT * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_INV_3_Value_EPT(void)
{
    return &Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_INV_3_Value_EPT;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_10ms_IPM_INV_4_Value_EPT
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_INV_4_Value_EPT*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_INV_4_Value_EPT* Rte_IrvIRead_Runbl_VCU_10ms_IPM_INV_4_Value_EPT(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_10ms_IPM_INV_4_Value_EPT;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_20ms_IPM_INV_4_Value_EPT
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_INV_4_Value_EPT*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_INV_4_Value_EPT* Rte_IrvIRead_Runbl_VCU_20ms_IPM_INV_4_Value_EPT(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_INV_4_Value_EPT;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_INV_4_Value_EPT
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
void Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_INV_4_Value_EPT(DT_IPM_INV_4_Value_EPT* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_INV_4_Value_EPT, (uint8*)data, sizeof(DT_IPM_INV_4_Value_EPT));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_INV_4_Value_EPT
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_INV_4_Value_EPT *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_INV_4_Value_EPT * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_INV_4_Value_EPT(void)
{
    return &Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_INV_4_Value_EPT;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_100ms_IPM_IPU_DCC_1_State_EPT
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_IPU_DCC_1_State_EPT*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_IPU_DCC_1_State_EPT* Rte_IrvIRead_Runbl_VCU_100ms_IPM_IPU_DCC_1_State_EPT(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_100ms_IPM_IPU_DCC_1_State_EPT;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_20ms_IPM_IPU_DCC_1_State_EPT
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_IPU_DCC_1_State_EPT*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_IPU_DCC_1_State_EPT* Rte_IrvIRead_Runbl_VCU_20ms_IPM_IPU_DCC_1_State_EPT(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_IPU_DCC_1_State_EPT;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_IPU_DCC_1_State_EPT
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
void Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_IPU_DCC_1_State_EPT(DT_IPM_IPU_DCC_1_State_EPT* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_IPU_DCC_1_State_EPT, (uint8*)data, sizeof(DT_IPM_IPU_DCC_1_State_EPT));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_IPU_DCC_1_State_EPT
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_IPU_DCC_1_State_EPT *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_IPU_DCC_1_State_EPT * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_IPU_DCC_1_State_EPT(void)
{
    return &Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_IPU_DCC_1_State_EPT;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_100ms_IPM_IPU_OBC_1_State_EPT
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_IPU_OBC_1_State_EPT*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_IPU_OBC_1_State_EPT* Rte_IrvIRead_Runbl_VCU_100ms_IPM_IPU_OBC_1_State_EPT(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_100ms_IPM_IPU_OBC_1_State_EPT;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_10ms_IPM_IPU_OBC_1_State_EPT
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_IPU_OBC_1_State_EPT*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_IPU_OBC_1_State_EPT* Rte_IrvIRead_Runbl_VCU_10ms_IPM_IPU_OBC_1_State_EPT(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_10ms_IPM_IPU_OBC_1_State_EPT;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_20ms_IPM_IPU_OBC_1_State_EPT
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_IPU_OBC_1_State_EPT*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_IPU_OBC_1_State_EPT* Rte_IrvIRead_Runbl_VCU_20ms_IPM_IPU_OBC_1_State_EPT(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_IPU_OBC_1_State_EPT;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_IPU_OBC_1_State_EPT
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
void Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_IPU_OBC_1_State_EPT(DT_IPM_IPU_OBC_1_State_EPT* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_IPU_OBC_1_State_EPT, (uint8*)data, sizeof(DT_IPM_IPU_OBC_1_State_EPT));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_IPU_OBC_1_State_EPT
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_IPU_OBC_1_State_EPT *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_IPU_OBC_1_State_EPT * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_IPU_OBC_1_State_EPT(void)
{
    return &Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_IPU_OBC_1_State_EPT;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_100ms_IPM_SCS_RiSwitchSts_BOD
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_SCS_RiSwitchSts_BOD*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_SCS_RiSwitchSts_BOD* Rte_IrvIRead_Runbl_VCU_100ms_IPM_SCS_RiSwitchSts_BOD(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_100ms_IPM_SCS_RiSwitchSts_BOD;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_10ms_IPM_SCS_RiSwitchSts_BOD
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_SCS_RiSwitchSts_BOD*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_SCS_RiSwitchSts_BOD* Rte_IrvIRead_Runbl_VCU_10ms_IPM_SCS_RiSwitchSts_BOD(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_10ms_IPM_SCS_RiSwitchSts_BOD;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_20ms_IPM_SCS_RiSwitchSts_BOD
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_SCS_RiSwitchSts_BOD*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_SCS_RiSwitchSts_BOD* Rte_IrvIRead_Runbl_VCU_20ms_IPM_SCS_RiSwitchSts_BOD(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_SCS_RiSwitchSts_BOD;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_SCS_RiSwitchSts_BOD
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
void Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_SCS_RiSwitchSts_BOD(DT_IPM_SCS_RiSwitchSts_BOD* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_SCS_RiSwitchSts_BOD, (uint8*)data, sizeof(DT_IPM_SCS_RiSwitchSts_BOD));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_SCS_RiSwitchSts_BOD
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_SCS_RiSwitchSts_BOD *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_SCS_RiSwitchSts_BOD * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_SCS_RiSwitchSts_BOD(void)
{
    return &Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_SCS_RiSwitchSts_BOD;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_10ms_IPM_SRS_1_Status_CHA
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_SRS_1_Status_CHA*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_SRS_1_Status_CHA* Rte_IrvIRead_Runbl_VCU_10ms_IPM_SRS_1_Status_CHA(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_10ms_IPM_SRS_1_Status_CHA;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_20ms_IPM_SRS_1_Status_CHA
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_SRS_1_Status_CHA*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_SRS_1_Status_CHA* Rte_IrvIRead_Runbl_VCU_20ms_IPM_SRS_1_Status_CHA(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_20ms_IPM_SRS_1_Status_CHA;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_SRS_1_Status_CHA
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
void Rte_IrvIWrite_Runbl_VcuRx_10ms_IPM_SRS_1_Status_CHA(DT_IPM_SRS_1_Status_CHA* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_SRS_1_Status_CHA, (uint8*)data, sizeof(DT_IPM_SRS_1_Status_CHA));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_SRS_1_Status_CHA
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_SRS_1_Status_CHA *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_SRS_1_Status_CHA * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_IPM_SRS_1_Status_CHA(void)
{
    return &Irv_AppSwcVcu_Runbl_VcuRx_10ms_IPM_SRS_1_Status_CHA;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_10ms_MsgActv_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_MsgActv*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_MsgActv* Rte_IrvIRead_Runbl_VCU_10ms_MsgActv_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_10ms_MsgActv_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_20ms_MsgActv_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_MsgActv*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_MsgActv* Rte_IrvIRead_Runbl_VCU_20ms_MsgActv_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_20ms_MsgActv_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_VcuRx_10ms_MsgActv_outputs
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
void Rte_IrvIWrite_Runbl_VcuRx_10ms_MsgActv_outputs(DT_MsgActv* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_MsgActv_outputs, (uint8*)data, sizeof(DT_MsgActv));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_VcuRx_10ms_MsgActv_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_MsgActv *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_MsgActv * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_MsgActv_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VcuRx_10ms_MsgActv_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_AppSwcVcu_Init_NVM_Imdt_outputs
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
void Rte_IrvIWrite_AppSwcVcu_Init_NVM_Imdt_outputs(NVM_Imdt_outputs* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_AppSwcVcu_Init_NVM_Imdt_outputs, (uint8*)data, sizeof(NVM_Imdt_outputs));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_AppSwcVcu_Init_NVM_Imdt_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               NVM_Imdt_outputs *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
NVM_Imdt_outputs * Rte_IrvIWriteRef_AppSwcVcu_Init_NVM_Imdt_outputs(void)
{
    return &Irv_AppSwcVcu_AppSwcVcu_Init_NVM_Imdt_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_100ms_NVM_Imdt_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               NVM_Imdt_outputs*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
NVM_Imdt_outputs* Rte_IrvIRead_Runbl_VCU_100ms_NVM_Imdt_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_100ms_NVM_Imdt_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_10ms_NVM_Imdt_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               NVM_Imdt_outputs*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
NVM_Imdt_outputs* Rte_IrvIRead_Runbl_VCU_10ms_NVM_Imdt_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_10ms_NVM_Imdt_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_20ms_NVM_Imdt_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               NVM_Imdt_outputs*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
NVM_Imdt_outputs* Rte_IrvIRead_Runbl_VCU_20ms_NVM_Imdt_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_20ms_NVM_Imdt_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_VcuRx_10ms_NVM_Imdt_outputs
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
void Rte_IrvIWrite_Runbl_VcuRx_10ms_NVM_Imdt_outputs(NVM_Imdt_outputs* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_NVM_Imdt_outputs, (uint8*)data, sizeof(NVM_Imdt_outputs));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_VcuRx_10ms_NVM_Imdt_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               NVM_Imdt_outputs *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
NVM_Imdt_outputs * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_NVM_Imdt_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VcuRx_10ms_NVM_Imdt_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VcuTx_10ms_NVM_Imdt_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               NVM_Imdt_outputs*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
NVM_Imdt_outputs* Rte_IrvIRead_Runbl_VcuTx_10ms_NVM_Imdt_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VcuTx_10ms_NVM_Imdt_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_AppSwcVcu_Init_NVM_outputs
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
void Rte_IrvIWrite_AppSwcVcu_Init_NVM_outputs(NVM_outputs* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_AppSwcVcu_Init_NVM_outputs, (uint8*)data, sizeof(NVM_outputs));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_AppSwcVcu_Init_NVM_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               NVM_outputs *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
NVM_outputs * Rte_IrvIWriteRef_AppSwcVcu_Init_NVM_outputs(void)
{
    return &Irv_AppSwcVcu_AppSwcVcu_Init_NVM_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_100ms_NVM_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               NVM_outputs*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
NVM_outputs* Rte_IrvIRead_Runbl_VCU_100ms_NVM_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_100ms_NVM_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_10ms_NVM_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               NVM_outputs*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
NVM_outputs* Rte_IrvIRead_Runbl_VCU_10ms_NVM_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_10ms_NVM_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_20ms_NVM_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               NVM_outputs*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
NVM_outputs* Rte_IrvIRead_Runbl_VCU_20ms_NVM_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_20ms_NVM_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_VcuRx_10ms_NVM_outputs
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
void Rte_IrvIWrite_Runbl_VcuRx_10ms_NVM_outputs(NVM_outputs* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_NVM_outputs, (uint8*)data, sizeof(NVM_outputs));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_VcuRx_10ms_NVM_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               NVM_outputs *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
NVM_outputs * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_NVM_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VcuRx_10ms_NVM_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_AppSwcVcu_Init_RME_outputs
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
void Rte_IrvIWrite_AppSwcVcu_Init_RME_outputs(RME_outputs* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_AppSwcVcu_Init_RME_outputs, (uint8*)data, sizeof(RME_outputs));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_AppSwcVcu_Init_RME_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               RME_outputs *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
RME_outputs * Rte_IrvIWriteRef_AppSwcVcu_Init_RME_outputs(void)
{
    return &Irv_AppSwcVcu_AppSwcVcu_Init_RME_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_VCU_100ms_RME_outputs
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
void Rte_IrvIWrite_Runbl_VCU_100ms_RME_outputs(RME_outputs* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_100ms_RME_outputs, (uint8*)data, sizeof(RME_outputs));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_VCU_100ms_RME_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               RME_outputs *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
RME_outputs * Rte_IrvIWriteRef_Runbl_VCU_100ms_RME_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_100ms_RME_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VcuTx_10ms_RME_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               RME_outputs*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
RME_outputs* Rte_IrvIRead_Runbl_VcuTx_10ms_RME_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VcuTx_10ms_RME_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_AppSwcVcu_Init_SIBS_Output
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
void Rte_IrvIWrite_AppSwcVcu_Init_SIBS_Output(DT_SIBS_Output* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_AppSwcVcu_Init_SIBS_Output, (uint8*)data, sizeof(DT_SIBS_Output));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_AppSwcVcu_Init_SIBS_Output
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_SIBS_Output *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_SIBS_Output * Rte_IrvIWriteRef_AppSwcVcu_Init_SIBS_Output(void)
{
    return &Irv_AppSwcVcu_AppSwcVcu_Init_SIBS_Output;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_VCU_100ms_SIBS_Output
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
void Rte_IrvIWrite_Runbl_VCU_100ms_SIBS_Output(DT_SIBS_Output* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_100ms_SIBS_Output, (uint8*)data, sizeof(DT_SIBS_Output));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_VCU_100ms_SIBS_Output
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_SIBS_Output *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_SIBS_Output * Rte_IrvIWriteRef_Runbl_VCU_100ms_SIBS_Output(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_100ms_SIBS_Output;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_20ms_SIBS_Output
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_SIBS_Output*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_SIBS_Output* Rte_IrvIRead_Runbl_VCU_20ms_SIBS_Output(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_20ms_SIBS_Output;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VcuTx_10ms_SIBS_Output
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_SIBS_Output*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_SIBS_Output* Rte_IrvIRead_Runbl_VcuTx_10ms_SIBS_Output(void)
{
    return &Irv_AppSwcVcu_Runbl_VcuTx_10ms_SIBS_Output;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_AppSwcVcu_Init_TBOX_outputs
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
void Rte_IrvIWrite_AppSwcVcu_Init_TBOX_outputs(TBOX_outputs* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_AppSwcVcu_Init_TBOX_outputs, (uint8*)data, sizeof(TBOX_outputs));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_AppSwcVcu_Init_TBOX_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               TBOX_outputs *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
TBOX_outputs * Rte_IrvIWriteRef_AppSwcVcu_Init_TBOX_outputs(void)
{
    return &Irv_AppSwcVcu_AppSwcVcu_Init_TBOX_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_VCU_100ms_TBOX_outputs
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
void Rte_IrvIWrite_Runbl_VCU_100ms_TBOX_outputs(TBOX_outputs* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_100ms_TBOX_outputs, (uint8*)data, sizeof(TBOX_outputs));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_VCU_100ms_TBOX_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               TBOX_outputs *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
TBOX_outputs * Rte_IrvIWriteRef_Runbl_VCU_100ms_TBOX_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_100ms_TBOX_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_10ms_TBOX_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               TBOX_outputs*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
TBOX_outputs* Rte_IrvIRead_Runbl_VCU_10ms_TBOX_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_10ms_TBOX_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_20ms_TBOX_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               TBOX_outputs*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
TBOX_outputs* Rte_IrvIRead_Runbl_VCU_20ms_TBOX_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_20ms_TBOX_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VcuTx_10ms_TBOX_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               TBOX_outputs*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
TBOX_outputs* Rte_IrvIRead_Runbl_VcuTx_10ms_TBOX_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VcuTx_10ms_TBOX_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_20ms_TMS2VCU_AC_2_State_Outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               TMS2VCU_AC_2_State_Outputs*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
TMS2VCU_AC_2_State_Outputs* Rte_IrvIRead_Runbl_VCU_20ms_TMS2VCU_AC_2_State_Outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_20ms_TMS2VCU_AC_2_State_Outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_VcuRx_10ms_TMS2VCU_AC_2_State_Outputs
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
void Rte_IrvIWrite_Runbl_VcuRx_10ms_TMS2VCU_AC_2_State_Outputs(TMS2VCU_AC_2_State_Outputs* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_TMS2VCU_AC_2_State_Outputs, (uint8*)data, sizeof(TMS2VCU_AC_2_State_Outputs));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_VcuRx_10ms_TMS2VCU_AC_2_State_Outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               TMS2VCU_AC_2_State_Outputs *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
TMS2VCU_AC_2_State_Outputs * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_TMS2VCU_AC_2_State_Outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VcuRx_10ms_TMS2VCU_AC_2_State_Outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_20ms_Tms2Vcu_Info
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Tms2Vcu_Info*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Tms2Vcu_Info* Rte_IrvIRead_Runbl_VCU_20ms_Tms2Vcu_Info(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_20ms_Tms2Vcu_Info;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_VcuRx_10ms_Tms2Vcu_Info
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
void Rte_IrvIWrite_Runbl_VcuRx_10ms_Tms2Vcu_Info(Tms2Vcu_Info* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_Tms2Vcu_Info, (uint8*)data, sizeof(Tms2Vcu_Info));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_VcuRx_10ms_Tms2Vcu_Info
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Tms2Vcu_Info *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Tms2Vcu_Info * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_Tms2Vcu_Info(void)
{
    return &Irv_AppSwcVcu_Runbl_VcuRx_10ms_Tms2Vcu_Info;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VcuTx_10ms_Tms2Vcu_Info
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Tms2Vcu_Info*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Tms2Vcu_Info* Rte_IrvIRead_Runbl_VcuTx_10ms_Tms2Vcu_Info(void)
{
    return &Irv_AppSwcVcu_Runbl_VcuTx_10ms_Tms2Vcu_Info;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_VCU_20ms_VDAG_VCUErrCode_enum
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
void Rte_IrvIWrite_Runbl_VCU_20ms_VDAG_VCUErrCode_enum(UInt16 data)
{
    if (RteInitState == RTE_INITED)
    {
        Irv_AppSwcVcu_Runbl_VCU_20ms_VDAG_VCUErrCode_enum = data;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_VCU_20ms_VDAG_VCUErrCode_enum
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               UInt16 *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
UInt16 * Rte_IrvIWriteRef_Runbl_VCU_20ms_VDAG_VCUErrCode_enum(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_20ms_VDAG_VCUErrCode_enum;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VcuTx_10ms_VDAG_VCUErrCode_enum
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               UInt16
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
UInt16 Rte_IrvIRead_Runbl_VcuTx_10ms_VDAG_VCUErrCode_enum(void)
{
    return Irv_AppSwcVcu_Runbl_VcuTx_10ms_VDAG_VCUErrCode_enum;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_AppSwcVcu_Init_VDAG_VCUFltLvl_enum
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
void Rte_IrvIWrite_AppSwcVcu_Init_VDAG_VCUFltLvl_enum(UInt8 data)
{
    if (RteInitState == RTE_INITED)
    {
        Irv_AppSwcVcu_AppSwcVcu_Init_VDAG_VCUFltLvl_enum = data;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_AppSwcVcu_Init_VDAG_VCUFltLvl_enum
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               UInt8 *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
UInt8 * Rte_IrvIWriteRef_AppSwcVcu_Init_VDAG_VCUFltLvl_enum(void)
{
    return &Irv_AppSwcVcu_AppSwcVcu_Init_VDAG_VCUFltLvl_enum;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_VCU_20ms_VDAG_VCUFltLvl_enum
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
void Rte_IrvIWrite_Runbl_VCU_20ms_VDAG_VCUFltLvl_enum(UInt8 data)
{
    if (RteInitState == RTE_INITED)
    {
        Irv_AppSwcVcu_Runbl_VCU_20ms_VDAG_VCUFltLvl_enum = data;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_VCU_20ms_VDAG_VCUFltLvl_enum
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               UInt8 *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
UInt8 * Rte_IrvIWriteRef_Runbl_VCU_20ms_VDAG_VCUFltLvl_enum(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_20ms_VDAG_VCUFltLvl_enum;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VcuTx_10ms_VDAG_VCUFltLvl_enum
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               UInt8
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
UInt8 Rte_IrvIRead_Runbl_VcuTx_10ms_VDAG_VCUFltLvl_enum(void)
{
    return Irv_AppSwcVcu_Runbl_VcuTx_10ms_VDAG_VCUFltLvl_enum;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_AppSwcVcu_Init_VSO_outputs
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
void Rte_IrvIWrite_AppSwcVcu_Init_VSO_outputs(VSO_outputs* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_AppSwcVcu_Init_VSO_outputs, (uint8*)data, sizeof(VSO_outputs));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_AppSwcVcu_Init_VSO_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               VSO_outputs *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
VSO_outputs * Rte_IrvIWriteRef_AppSwcVcu_Init_VSO_outputs(void)
{
    return &Irv_AppSwcVcu_AppSwcVcu_Init_VSO_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_VCU_10ms_VSO_outputs
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
void Rte_IrvIWrite_Runbl_VCU_10ms_VSO_outputs(VSO_outputs* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_10ms_VSO_outputs, (uint8*)data, sizeof(VSO_outputs));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_VCU_10ms_VSO_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               VSO_outputs *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
VSO_outputs * Rte_IrvIWriteRef_Runbl_VCU_10ms_VSO_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_10ms_VSO_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VcuTx_10ms_VSO_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               VSO_outputs*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
VSO_outputs* Rte_IrvIRead_Runbl_VcuTx_10ms_VSO_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VcuTx_10ms_VSO_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_AppSwcVcu_Init_VTM_outputs
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
void Rte_IrvIWrite_AppSwcVcu_Init_VTM_outputs(VTM_outputs* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_AppSwcVcu_Init_VTM_outputs, (uint8*)data, sizeof(VTM_outputs));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_AppSwcVcu_Init_VTM_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               VTM_outputs *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
VTM_outputs * Rte_IrvIWriteRef_AppSwcVcu_Init_VTM_outputs(void)
{
    return &Irv_AppSwcVcu_AppSwcVcu_Init_VTM_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_100ms_VTM_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               VTM_outputs*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
VTM_outputs* Rte_IrvIRead_Runbl_VCU_100ms_VTM_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_100ms_VTM_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_VCU_10ms_VTM_outputs
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
void Rte_IrvIWrite_Runbl_VCU_10ms_VTM_outputs(VTM_outputs* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VCU_10ms_VTM_outputs, (uint8*)data, sizeof(VTM_outputs));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_VCU_10ms_VTM_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               VTM_outputs *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
VTM_outputs * Rte_IrvIWriteRef_Runbl_VCU_10ms_VTM_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_10ms_VTM_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_20ms_VTM_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               VTM_outputs*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
VTM_outputs* Rte_IrvIRead_Runbl_VCU_20ms_VTM_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_20ms_VTM_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VcuTx_10ms_VTM_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               VTM_outputs*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
VTM_outputs* Rte_IrvIRead_Runbl_VcuTx_10ms_VTM_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VcuTx_10ms_VTM_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_VCU_10ms_VehCfg_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               VehCfg_outputs*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
VehCfg_outputs* Rte_IrvIRead_Runbl_VCU_10ms_VehCfg_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VCU_10ms_VehCfg_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_VcuRx_10ms_VehCfg_outputs
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
void Rte_IrvIWrite_Runbl_VcuRx_10ms_VehCfg_outputs(VehCfg_outputs* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcVcu_Runbl_VcuRx_10ms_VehCfg_outputs, (uint8*)data, sizeof(VehCfg_outputs));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_VcuRx_10ms_VehCfg_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               VehCfg_outputs *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
VehCfg_outputs * Rte_IrvIWriteRef_Runbl_VcuRx_10ms_VehCfg_outputs(void)
{
    return &Irv_AppSwcVcu_Runbl_VcuRx_10ms_VehCfg_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_VCU_100ms_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs
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
Std_ReturnType Rte_IStatus_Runbl_VCU_100ms_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs(void)
{
    return Rte_Inst_AppSwcVcu.Runbl_VCU_100ms_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_VCU_100ms_TMS2VCU_PPV_outputs_TMS2VCU_PPV_outputs
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
Std_ReturnType Rte_IStatus_Runbl_VCU_100ms_TMS2VCU_PPV_outputs_TMS2VCU_PPV_outputs(void)
{
    return Rte_Inst_AppSwcVcu.Runbl_VCU_100ms_TMS2VCU_PPV_outputs_TMS2VCU_PPV_outputs->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_VCU_10ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD
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
Std_ReturnType Rte_IStatus_Runbl_VCU_10ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD(void)
{
    return Rte_Inst_AppSwcVcu.Runbl_VCU_10ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_VCU_10ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA
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
Std_ReturnType Rte_IStatus_Runbl_VCU_10ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA(void)
{
    return Rte_Inst_AppSwcVcu.Runbl_VCU_10ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_VCU_20ms_CANCommCRCFlt_outputs_CANCommCRCFlt_outputs
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
Std_ReturnType Rte_IStatus_Runbl_VCU_20ms_CANCommCRCFlt_outputs_CANCommCRCFlt_outputs(void)
{
    return Rte_Inst_AppSwcVcu.Runbl_VCU_20ms_CANCommCRCFlt_outputs_CANCommCRCFlt_outputs->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_VCU_20ms_IPM_BMS_3_DC_ChargeState_EPT_IPM_BMS_3_DC_ChargeState_EPT
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
Std_ReturnType Rte_IStatus_Runbl_VCU_20ms_IPM_BMS_3_DC_ChargeState_EPT_IPM_BMS_3_DC_ChargeState_EPT(void)
{
    return Rte_Inst_AppSwcVcu.Runbl_VCU_20ms_IPM_BMS_3_DC_ChargeState_EPT_IPM_BMS_3_DC_ChargeState_EPT->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_VCU_20ms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT
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
Std_ReturnType Rte_IStatus_Runbl_VCU_20ms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT(void)
{
    return Rte_Inst_AppSwcVcu.Runbl_VCU_20ms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_VCU_20ms_IPM_BMS_7_CellVolt_EPT_IPM_BMS_7_CellVolt_EPT
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
Std_ReturnType Rte_IStatus_Runbl_VCU_20ms_IPM_BMS_7_CellVolt_EPT_IPM_BMS_7_CellVolt_EPT(void)
{
    return Rte_Inst_AppSwcVcu.Runbl_VCU_20ms_IPM_BMS_7_CellVolt_EPT_IPM_BMS_7_CellVolt_EPT->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_VCU_20ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD
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
Std_ReturnType Rte_IStatus_Runbl_VCU_20ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD(void)
{
    return Rte_Inst_AppSwcVcu.Runbl_VCU_20ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_VCU_20ms_IPM_ICU_2_Odo_BAC_IPM_ICU_2_Odo_BAC
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
Std_ReturnType Rte_IStatus_Runbl_VCU_20ms_IPM_ICU_2_Odo_BAC_IPM_ICU_2_Odo_BAC(void)
{
    return Rte_Inst_AppSwcVcu.Runbl_VCU_20ms_IPM_ICU_2_Odo_BAC_IPM_ICU_2_Odo_BAC->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_VCU_20ms_IPM_IPU_DCC_2_ChrgInValue_EPT_IPM_IPU_DCC_2_ChrgInValue_EPT
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
Std_ReturnType Rte_IStatus_Runbl_VCU_20ms_IPM_IPU_DCC_2_ChrgInValue_EPT_IPM_IPU_DCC_2_ChrgInValue_EPT(void)
{
    return Rte_Inst_AppSwcVcu.Runbl_VCU_20ms_IPM_IPU_DCC_2_ChrgInValue_EPT_IPM_IPU_DCC_2_ChrgInValue_EPT->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_VCU_20ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT
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
Std_ReturnType Rte_IStatus_Runbl_VCU_20ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT(void)
{
    return Rte_Inst_AppSwcVcu.Runbl_VCU_20ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_VCU_20ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC
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
Std_ReturnType Rte_IStatus_Runbl_VCU_20ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC(void)
{
    return Rte_Inst_AppSwcVcu.Runbl_VCU_20ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_VcuRx_10ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs
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
Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs(void)
{
    return Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_VcuRx_10ms_CANCommErr_outputs_CANCommErr_outputs
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
Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_CANCommErr_outputs_CANCommErr_outputs(void)
{
    return Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_CANCommErr_outputs_CANCommErr_outputs->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_VcuRx_10ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT
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
Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT(void)
{
    return Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_VcuRx_10ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT
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
Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT(void)
{
    return Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_VcuRx_10ms_IPM_BMS_2_BatState_EPT_IPM_BMS_2_BatState_EPT
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
Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_IPM_BMS_2_BatState_EPT_IPM_BMS_2_BatState_EPT(void)
{
    return Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_BMS_2_BatState_EPT_IPM_BMS_2_BatState_EPT->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_VcuRx_10ms_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT
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
Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT(void)
{
    return Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_VcuRx_10ms_IPM_BMS_6_DischrgRecup_EPT_IPM_BMS_6_DischrgRecup_EPT
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
Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_IPM_BMS_6_DischrgRecup_EPT_IPM_BMS_6_DischrgRecup_EPT(void)
{
    return Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_BMS_6_DischrgRecup_EPT_IPM_BMS_6_DischrgRecup_EPT->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_VcuRx_10ms_IPM_BMS_9_BattInfo_EPT_IPM_BMS_9_BattInfo_EPT
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
Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_IPM_BMS_9_BattInfo_EPT_IPM_BMS_9_BattInfo_EPT(void)
{
    return Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_BMS_9_BattInfo_EPT_IPM_BMS_9_BattInfo_EPT->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_VcuRx_10ms_IPM_EHB_B_CHA_IPM_EHB_B_CHA
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
Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_IPM_EHB_B_CHA_IPM_EHB_B_CHA(void)
{
    return Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_EHB_B_CHA_IPM_EHB_B_CHA->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_VcuRx_10ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA
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
Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA(void)
{
    return Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_VcuRx_10ms_IPM_ESC_A_CHA_IPM_ESC_A_CHA
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
Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_IPM_ESC_A_CHA_IPM_ESC_A_CHA(void)
{
    return Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_ESC_A_CHA_IPM_ESC_A_CHA->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_VcuRx_10ms_IPM_FCM_B_CHA_IPM_FCM_B_CHA
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
Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_IPM_FCM_B_CHA_IPM_FCM_B_CHA(void)
{
    return Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_FCM_B_CHA_IPM_FCM_B_CHA->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_VcuRx_10ms_IPM_HU_B_BAC_IPM_HU_B_BAC
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
Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_IPM_HU_B_BAC_IPM_HU_B_BAC(void)
{
    return Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_HU_B_BAC_IPM_HU_B_BAC->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_VcuRx_10ms_IPM_INV_1_Value_EPT_IPM_INV_1_Value_EPT
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
Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_IPM_INV_1_Value_EPT_IPM_INV_1_Value_EPT(void)
{
    return Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_INV_1_Value_EPT_IPM_INV_1_Value_EPT->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_VcuRx_10ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT
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
Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT(void)
{
    return Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_VcuRx_10ms_IPM_INV_3_Value_EPT_IPM_INV_3_Value_EPT
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
Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_IPM_INV_3_Value_EPT_IPM_INV_3_Value_EPT(void)
{
    return Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_INV_3_Value_EPT_IPM_INV_3_Value_EPT->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_VcuRx_10ms_IPM_INV_4_Value_EPT_IPM_INV_4_Value_EPT
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
Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_IPM_INV_4_Value_EPT_IPM_INV_4_Value_EPT(void)
{
    return Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_INV_4_Value_EPT_IPM_INV_4_Value_EPT->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_VcuRx_10ms_IPM_IPU_DCC_1_State_EPT_IPM_IPU_DCC_1_State_EPT
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
Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_IPM_IPU_DCC_1_State_EPT_IPM_IPU_DCC_1_State_EPT(void)
{
    return Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_IPU_DCC_1_State_EPT_IPM_IPU_DCC_1_State_EPT->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_VcuRx_10ms_IPM_IPU_OBC_1_State_EPT_IPM_IPU_OBC_1_State_EPT
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
Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_IPM_IPU_OBC_1_State_EPT_IPM_IPU_OBC_1_State_EPT(void)
{
    return Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_IPU_OBC_1_State_EPT_IPM_IPU_OBC_1_State_EPT->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_VcuRx_10ms_IPM_SCS_RiSwitchSts_BOD_IPM_SCS_RiSwitchSts_BOD
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
Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_IPM_SCS_RiSwitchSts_BOD_IPM_SCS_RiSwitchSts_BOD(void)
{
    return Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_SCS_RiSwitchSts_BOD_IPM_SCS_RiSwitchSts_BOD->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_VcuRx_10ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA
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
Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA(void)
{
    return Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_VcuRx_10ms_MsgActv_outputs_MsgActv_outputs
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
Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_MsgActv_outputs_MsgActv_outputs(void)
{
    return Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_MsgActv_outputs_MsgActv_outputs->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_VcuRx_10ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs
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
Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs(void)
{
    return Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_VcuRx_10ms_Tms2Vcu_Info_Tms2Vcu_Info
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
Std_ReturnType Rte_IStatus_Runbl_VcuRx_10ms_Tms2Vcu_Info_Tms2Vcu_Info(void)
{
    return Rte_Inst_AppSwcVcu.Runbl_VcuRx_10ms_Tms2Vcu_Info_Tms2Vcu_Info->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

