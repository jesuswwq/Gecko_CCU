/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_AppSwcOpm.h>
 *  @brief      <>
 *  
 *  <MCU:E3420>
 *  
 *  @author     <>
 *  @date       <2024-10-10 14:07:58>
 */
/*============================================================================*/

/* Rte_AppSwcOpm.h */

#ifndef RTE_APPSWCOPM_H
#define RTE_APPSWCOPM_H

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
#include "Rte_AppSwcOpm_Type.h"

/*******************************************************************************
 **                        Macro Definitions                                  **
******************************************************************************/

typedef struct
{
    P2VAR(Rte_DE_DT_Bcm2OpmEPT_outputs_status, AUTOMATIC, RTE_DATA)  Runbl_OpmCanTx_100ms_Bcm2OpmEPT_outputs_Bcm2OpmEPT_outputs;
    P2VAR(Rte_DE_DT_Bcm2OpmOBD_outputs_status, AUTOMATIC, RTE_DATA)  Runbl_OpmCanTx_100ms_Bcm2OpmOBD_outputs_Bcm2OpmOBD_outputs;
    P2VAR(Rte_DE_TMS2VCU_AC_1_Command_Outputs_status, AUTOMATIC, RTE_DATA)  Runbl_OpmCanTx_100ms_TMS2VCU_AC_1_Command_Outputs_TMS2VCU_AC_1_Command_Outputs;
    P2VAR(Rte_DE_TMS2VCU_AC_2_State_Outputs_status, AUTOMATIC, RTE_DATA)  Runbl_OpmCanTx_100ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs;
    P2VAR(Rte_DE_TMS2VCU_AC_3_State_Outputs_status, AUTOMATIC, RTE_DATA)  Runbl_OpmCanTx_100ms_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs;
    P2VAR(Rte_DE_TMS2VCU_AC_8_status_Outputs_status, AUTOMATIC, RTE_DATA)  Runbl_OpmCanTx_100ms_TMS2VCU_AC_8_status_Outputs_TMS2VCU_AC_8_status_Outputs;
    P2VAR(Rte_DE_TMS2VCU_AC_ACStatuts_Outputs_status, AUTOMATIC, RTE_DATA)  Runbl_OpmCanTx_100ms_TMS2VCU_AC_ACStatuts_Outputs_TMS2VCU_AC_ACStatuts_Outputs;
    P2VAR(Rte_DE_TMS2VCU_AC_COMP_Outputs_status, AUTOMATIC, RTE_DATA)  Runbl_OpmCanTx_100ms_TMS2VCU_AC_COMP_Outputs_TMS2VCU_AC_COMP_Outputs;
    P2VAR(Rte_DE_TMS2VCU_HVCH_Command_Outputs_status, AUTOMATIC, RTE_DATA)  Runbl_OpmCanTx_100ms_TMS2VCU_HVCH_Command_Outputs_TMS2VCU_HVCH_Command_Outputs;
    P2VAR(Rte_DE_TMS2VCU_TMS_LINTestData1_Outputs_status, AUTOMATIC, RTE_DATA)  Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData1_Outputs_TMS2VCU_TMS_LINTestData1_Outputs;
    P2VAR(Rte_DE_TMS2VCU_TMS_LINTestData2_Outputs_status, AUTOMATIC, RTE_DATA)  Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData2_Outputs_TMS2VCU_TMS_LINTestData2_Outputs;
    P2VAR(Rte_DE_TMS2VCU_TMS_LINTestData3_Outputs_status, AUTOMATIC, RTE_DATA)  Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData3_Outputs_TMS2VCU_TMS_LINTestData3_Outputs;
    P2VAR(Rte_DE_DT_IPM_FCM_B_CHA_status, AUTOMATIC, RTE_DATA)  Runbl_OpmCanTx_10ms_IPM_FCM_B_CHA_IPM_FCM_B_CHA;
    P2VAR(Rte_DE_DT_IPM_INV_1_Value_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_OpmCanTx_10ms_IPM_INV_1_Value_EPT_IPM_INV_1_Value_EPT;
    P2VAR(Rte_DE_DT_Bcm2OpmBAC_outputs_status, AUTOMATIC, RTE_DATA)  Runbl_OpmRx_10ms_Bcm2OpmBAC_outputs_Bcm2OpmBAC_outputs;
    P2VAR(Rte_DE_TMS2VCU_PPVAddSignalGroup_Outputs_status, AUTOMATIC, RTE_DATA)  Runbl_OpmRx_10ms_TMS2VCU_PPV_outputs_TMS2VCU_PPV_outputs;
    P2VAR(Rte_DE_DT_Vcu2OpmBAC_outputs_status, AUTOMATIC, RTE_DATA)  Runbl_OpmRx_10ms_Vcu2OpmBAC_outputs_Vcu2OpmBAC_outputs;
    P2VAR(Rte_DE_DT_Vcu2OpmCHA_outputs_status, AUTOMATIC, RTE_DATA)  Runbl_OpmRx_10ms_Vcu2OpmCHA_outputs_Vcu2OpmCHA_outputs;
    P2VAR(Rte_DE_DT_Vcu2OpmEPT_outputs_status, AUTOMATIC, RTE_DATA)  Runbl_OpmRx_10ms_Vcu2OpmEPT_outputs_Vcu2OpmEPT_outputs;
    P2VAR(Rte_DE_AC_1_Command_BOD_status, AUTOMATIC, RTE_DATA)  Runbl_OpmCanTx_100ms_AC_1_Command_BOD_AC_1_Command_BOD;
    P2VAR(Rte_DE_AC_2_State_BOD_status, AUTOMATIC, RTE_DATA)  Runbl_OpmCanTx_100ms_AC_2_State_BOD_AC_2_State_BOD;
    P2VAR(Rte_DE_AC_3_State_BOD_status, AUTOMATIC, RTE_DATA)  Runbl_OpmCanTx_100ms_AC_3_State_BOD_AC_3_State_BOD;
    P2VAR(Rte_DE_AC_8_status_BOD_status, AUTOMATIC, RTE_DATA)  Runbl_OpmCanTx_100ms_AC_8_status_BOD_AC_8_status_BOD;
    P2VAR(Rte_DE_AC_ACStatuts_BOD_status, AUTOMATIC, RTE_DATA)  Runbl_OpmCanTx_100ms_AC_ACStatuts_BOD_AC_ACStatuts_BOD;
    P2VAR(Rte_DE_AC_COMP_BOD_status, AUTOMATIC, RTE_DATA)  Runbl_OpmCanTx_100ms_AC_COMP_BOD_AC_COMP_BOD;
    P2VAR(Rte_DE_BCM_ESCLCommand_BOD_status, AUTOMATIC, RTE_DATA)  Runbl_OpmCanTx_100ms_BCM_ESCLCommand_BOD_BCM_ESCLCommand_BOD;
    P2VAR(Rte_DE_BCM_HFSData_BAC_status, AUTOMATIC, RTE_DATA)  Runbl_OpmCanTx_100ms_BCM_HFSData_BAC_BCM_HFSData_BAC;
    P2VAR(Rte_DE_BCM_IMMOAuthResp1_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_OpmCanTx_100ms_BCM_IMMOAuthResp1_EPT_BCM_IMMOAuthResp1_EPT;
    P2VAR(Rte_DE_HVCH_Command_BOD_status, AUTOMATIC, RTE_DATA)  Runbl_OpmCanTx_100ms_HVCH_Command_BOD_HVCH_Command_BOD;
    P2VAR(Rte_DE_TMS_LINTestData1_BOD_status, AUTOMATIC, RTE_DATA)  Runbl_OpmCanTx_100ms_TMS_LINTestData1_BOD_TMS_LINTestData1_BOD;
    P2VAR(Rte_DE_TMS_LINTestData2_BOD_status, AUTOMATIC, RTE_DATA)  Runbl_OpmCanTx_100ms_TMS_LINTestData2_BOD_TMS_LINTestData2_BOD;
    P2VAR(Rte_DE_TMS_LINTestData3_BOD_status, AUTOMATIC, RTE_DATA)  Runbl_OpmCanTx_100ms_TMS_LINTestData3_BOD_TMS_LINTestData3_BOD;
    P2VAR(Rte_DE_VCU_0_Value_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_OpmCanTx_10ms_VCU_0_Value_EPT_VCU_0_Value_EPT;
    P2VAR(Rte_DE_VCU_10_Torque_CHA_status, AUTOMATIC, RTE_DATA)  Runbl_OpmCanTx_10ms_VCU_10_Torque_CHA_VCU_10_Torque_CHA;
    P2VAR(Rte_DE_VCU_1_InvCmd_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_OpmCanTx_10ms_VCU_1_InvCmd_EPT_VCU_1_InvCmd_EPT;
    P2VAR(Rte_DE_VCU_3_OprtCmd_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_OpmCanTx_20ms_VCU_3_OprtCmd_EPT_VCU_3_OprtCmd_EPT;
    P2VAR(Rte_DE_VCU_4_ChrgCmd_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_OpmCanTx_20ms_VCU_4_ChrgCmd_EPT_VCU_4_ChrgCmd_EPT;
    P2VAR(Rte_DE_VCU_B_AcclPedal_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_OpmCanTx_20ms_VCU_B_AcclPedal_EPT_VCU_B_AcclPedal_EPT;
    P2VAR(Rte_DE_VCU_C_OprtCmd_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_OpmCanTx_20ms_VCU_C_OprtCmd_EPT_VCU_C_OprtCmd_EPT;
    P2VAR(Rte_DE_VCU_D_Status_CHA_status, AUTOMATIC, RTE_DATA)  Runbl_OpmCanTx_20ms_VCU_D_Status_CHA_VCU_D_Status_CHA;
    P2VAR(Rte_DE_VCU_DispInfo_BAC_status, AUTOMATIC, RTE_DATA)  Runbl_OpmCanTx_20ms_VCU_DispInfo_BAC_VCU_DispInfo_BAC;
    P2VAR(Rte_DE_BCM_B_Package_BAC_status, AUTOMATIC, RTE_DATA)  Runbl_OpmCanTx_50ms_BCM_B_Package_BAC_BCM_B_Package_BAC;
    P2VAR(Rte_DE_CCU_VehInfo_BAC_status, AUTOMATIC, RTE_DATA)  Runbl_OpmCanTx_50ms_CCU_VehInfo_BAC_CCU_VehInfo_BAC;
} Rte_CDS_AppSwcOpm;

extern CONST(Rte_CDS_AppSwcOpm, RTE_CONST) Rte_Inst_AppSwcOpm;

#ifndef RTE_CORE
typedef CONSTP2CONST(Rte_CDS_AppSwcOpm, AUTOMATIC, RTE_CONST) Rte_Instance;
#endif

/** API mappings */

#ifndef RTE_CORE

#define Rte_IrvIRead_Runbl_OpmCanTx_100ms_Bcm2OpmBAC_outputs Rte_IrvIRead_Runbl_OpmCanTx_100ms_Bcm2OpmBAC_outputs

#define Rte_IrvIRead_Runbl_OpmCanTx_20ms_Bcm2OpmBAC_outputs Rte_IrvIRead_Runbl_OpmCanTx_20ms_Bcm2OpmBAC_outputs

#define Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs

#define Rte_IrvIWrite_Runbl_OpmRx_10ms_Bcm2OpmBAC_outputs Rte_IrvIWrite_Runbl_OpmRx_10ms_Bcm2OpmBAC_outputs

#define Rte_IrvIRead_Runbl_OpmCanTx_100ms_TMS2VCU_PPV_outputs Rte_IrvIRead_Runbl_OpmCanTx_100ms_TMS2VCU_PPV_outputs

#define Rte_IrvIRead_Runbl_OpmCanTx_20ms_TMS2VCU_PPV_outputs Rte_IrvIRead_Runbl_OpmCanTx_20ms_TMS2VCU_PPV_outputs

#define Rte_IrvIWrite_Runbl_OpmRx_10ms_TMS2VCU_PPV_outputs Rte_IrvIWrite_Runbl_OpmRx_10ms_TMS2VCU_PPV_outputs

#define Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs

#define Rte_IrvIRead_Runbl_OpmCanTx_50ms_Vcu2OpmBAC_outputs Rte_IrvIRead_Runbl_OpmCanTx_50ms_Vcu2OpmBAC_outputs

#define Rte_IrvIWrite_Runbl_OpmRx_10ms_Vcu2OpmBAC_outputs Rte_IrvIWrite_Runbl_OpmRx_10ms_Vcu2OpmBAC_outputs

#define Rte_IrvIRead_Runbl_OpmCanTx_10ms_Vcu2OpmCHA_outputs Rte_IrvIRead_Runbl_OpmCanTx_10ms_Vcu2OpmCHA_outputs

#define Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmCHA_outputs Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmCHA_outputs

#define Rte_IrvIWrite_Runbl_OpmRx_10ms_Vcu2OpmCHA_outputs Rte_IrvIWrite_Runbl_OpmRx_10ms_Vcu2OpmCHA_outputs

#define Rte_IrvIRead_Runbl_OpmCanTx_10ms_Vcu2OpmEPT_outputs Rte_IrvIRead_Runbl_OpmCanTx_10ms_Vcu2OpmEPT_outputs

#define Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmEPT_outputs Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmEPT_outputs

#define Rte_IrvIWrite_Runbl_OpmRx_10ms_Vcu2OpmEPT_outputs Rte_IrvIWrite_Runbl_OpmRx_10ms_Vcu2OpmEPT_outputs

#define Rte_IRead_Runbl_OpmCanTx_100ms_Bcm2OpmEPT_outputs_Bcm2OpmEPT_outputs() (&Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_Bcm2OpmEPT_outputs_Bcm2OpmEPT_outputs->value)

#define Rte_IRead_Runbl_OpmCanTx_100ms_Bcm2OpmOBD_outputs_Bcm2OpmOBD_outputs() (&Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_Bcm2OpmOBD_outputs_Bcm2OpmOBD_outputs->value)

#define Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_1_Command_Outputs_TMS2VCU_AC_1_Command_Outputs() (&Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_TMS2VCU_AC_1_Command_Outputs_TMS2VCU_AC_1_Command_Outputs->value)

#define Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs() (&Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs->value)

#define Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs() (&Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs->value)

#define Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_8_status_Outputs_TMS2VCU_AC_8_status_Outputs() (&Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_TMS2VCU_AC_8_status_Outputs_TMS2VCU_AC_8_status_Outputs->value)

#define Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_ACStatuts_Outputs_TMS2VCU_AC_ACStatuts_Outputs() (&Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_TMS2VCU_AC_ACStatuts_Outputs_TMS2VCU_AC_ACStatuts_Outputs->value)

#define Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_AC_COMP_Outputs_TMS2VCU_AC_COMP_Outputs() (&Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_TMS2VCU_AC_COMP_Outputs_TMS2VCU_AC_COMP_Outputs->value)

#define Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_HVCH_Command_Outputs_TMS2VCU_HVCH_Command_Outputs() (&Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_TMS2VCU_HVCH_Command_Outputs_TMS2VCU_HVCH_Command_Outputs->value)

#define Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData1_Outputs_TMS2VCU_TMS_LINTestData1_Outputs() (&Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData1_Outputs_TMS2VCU_TMS_LINTestData1_Outputs->value)

#define Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData2_Outputs_TMS2VCU_TMS_LINTestData2_Outputs() (&Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData2_Outputs_TMS2VCU_TMS_LINTestData2_Outputs->value)

#define Rte_IRead_Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData3_Outputs_TMS2VCU_TMS_LINTestData3_Outputs() (&Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData3_Outputs_TMS2VCU_TMS_LINTestData3_Outputs->value)

#define Rte_IWrite_Runbl_OpmCanTx_100ms_AC_1_Command_BOD_AC_1_Command_BOD(data) (Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_AC_1_Command_BOD_AC_1_Command_BOD->value = *(data))

#define Rte_IWriteRef_Runbl_OpmCanTx_100ms_AC_1_Command_BOD_AC_1_Command_BOD() (&Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_AC_1_Command_BOD_AC_1_Command_BOD->value)

#define Rte_IWrite_Runbl_OpmCanTx_100ms_AC_2_State_BOD_AC_2_State_BOD(data) (Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_AC_2_State_BOD_AC_2_State_BOD->value = *(data))

#define Rte_IWriteRef_Runbl_OpmCanTx_100ms_AC_2_State_BOD_AC_2_State_BOD() (&Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_AC_2_State_BOD_AC_2_State_BOD->value)

#define Rte_IWrite_Runbl_OpmCanTx_100ms_AC_3_State_BOD_AC_3_State_BOD(data) (Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_AC_3_State_BOD_AC_3_State_BOD->value = *(data))

#define Rte_IWriteRef_Runbl_OpmCanTx_100ms_AC_3_State_BOD_AC_3_State_BOD() (&Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_AC_3_State_BOD_AC_3_State_BOD->value)

#define Rte_IWrite_Runbl_OpmCanTx_100ms_AC_8_status_BOD_AC_8_status_BOD(data) (Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_AC_8_status_BOD_AC_8_status_BOD->value = *(data))

#define Rte_IWriteRef_Runbl_OpmCanTx_100ms_AC_8_status_BOD_AC_8_status_BOD() (&Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_AC_8_status_BOD_AC_8_status_BOD->value)

#define Rte_IWrite_Runbl_OpmCanTx_100ms_AC_ACStatuts_BOD_AC_ACStatuts_BOD(data) (Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_AC_ACStatuts_BOD_AC_ACStatuts_BOD->value = *(data))

#define Rte_IWriteRef_Runbl_OpmCanTx_100ms_AC_ACStatuts_BOD_AC_ACStatuts_BOD() (&Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_AC_ACStatuts_BOD_AC_ACStatuts_BOD->value)

#define Rte_IWrite_Runbl_OpmCanTx_100ms_AC_COMP_BOD_AC_COMP_BOD(data) (Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_AC_COMP_BOD_AC_COMP_BOD->value = *(data))

#define Rte_IWriteRef_Runbl_OpmCanTx_100ms_AC_COMP_BOD_AC_COMP_BOD() (&Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_AC_COMP_BOD_AC_COMP_BOD->value)

#define Rte_IWrite_Runbl_OpmCanTx_100ms_BCM_ESCLCommand_BOD_BCM_ESCLCommand_BOD(data) (Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_BCM_ESCLCommand_BOD_BCM_ESCLCommand_BOD->value = *(data))

#define Rte_IWriteRef_Runbl_OpmCanTx_100ms_BCM_ESCLCommand_BOD_BCM_ESCLCommand_BOD() (&Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_BCM_ESCLCommand_BOD_BCM_ESCLCommand_BOD->value)

#define Rte_IWrite_Runbl_OpmCanTx_100ms_BCM_HFSData_BAC_BCM_HFSData_BAC(data) (Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_BCM_HFSData_BAC_BCM_HFSData_BAC->value = *(data))

#define Rte_IWriteRef_Runbl_OpmCanTx_100ms_BCM_HFSData_BAC_BCM_HFSData_BAC() (&Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_BCM_HFSData_BAC_BCM_HFSData_BAC->value)

#define Rte_IWrite_Runbl_OpmCanTx_100ms_BCM_IMMOAuthResp1_EPT_BCM_IMMOAuthResp1_EPT(data) (Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_BCM_IMMOAuthResp1_EPT_BCM_IMMOAuthResp1_EPT->value = *(data))

#define Rte_IWriteRef_Runbl_OpmCanTx_100ms_BCM_IMMOAuthResp1_EPT_BCM_IMMOAuthResp1_EPT() (&Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_BCM_IMMOAuthResp1_EPT_BCM_IMMOAuthResp1_EPT->value)

#define Rte_IWrite_Runbl_OpmCanTx_100ms_HVCH_Command_BOD_HVCH_Command_BOD(data) (Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_HVCH_Command_BOD_HVCH_Command_BOD->value = *(data))

#define Rte_IWriteRef_Runbl_OpmCanTx_100ms_HVCH_Command_BOD_HVCH_Command_BOD() (&Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_HVCH_Command_BOD_HVCH_Command_BOD->value)

#define Rte_IWrite_Runbl_OpmCanTx_100ms_TMS_LINTestData1_BOD_TMS_LINTestData1_BOD(data) (Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_TMS_LINTestData1_BOD_TMS_LINTestData1_BOD->value = *(data))

#define Rte_IWriteRef_Runbl_OpmCanTx_100ms_TMS_LINTestData1_BOD_TMS_LINTestData1_BOD() (&Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_TMS_LINTestData1_BOD_TMS_LINTestData1_BOD->value)

#define Rte_IWrite_Runbl_OpmCanTx_100ms_TMS_LINTestData2_BOD_TMS_LINTestData2_BOD(data) (Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_TMS_LINTestData2_BOD_TMS_LINTestData2_BOD->value = *(data))

#define Rte_IWriteRef_Runbl_OpmCanTx_100ms_TMS_LINTestData2_BOD_TMS_LINTestData2_BOD() (&Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_TMS_LINTestData2_BOD_TMS_LINTestData2_BOD->value)

#define Rte_IWrite_Runbl_OpmCanTx_100ms_TMS_LINTestData3_BOD_TMS_LINTestData3_BOD(data) (Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_TMS_LINTestData3_BOD_TMS_LINTestData3_BOD->value = *(data))

#define Rte_IWriteRef_Runbl_OpmCanTx_100ms_TMS_LINTestData3_BOD_TMS_LINTestData3_BOD() (&Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_100ms_TMS_LINTestData3_BOD_TMS_LINTestData3_BOD->value)

#define Rte_IRead_Runbl_OpmCanTx_10ms_IPM_FCM_B_CHA_IPM_FCM_B_CHA() (&Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_10ms_IPM_FCM_B_CHA_IPM_FCM_B_CHA->value)

#define Rte_IRead_Runbl_OpmCanTx_10ms_IPM_INV_1_Value_EPT_IPM_INV_1_Value_EPT() (&Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_10ms_IPM_INV_1_Value_EPT_IPM_INV_1_Value_EPT->value)

#define Rte_IWrite_Runbl_OpmCanTx_10ms_VCU_0_Value_EPT_VCU_0_Value_EPT(data) (Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_10ms_VCU_0_Value_EPT_VCU_0_Value_EPT->value = *(data))

#define Rte_IWriteRef_Runbl_OpmCanTx_10ms_VCU_0_Value_EPT_VCU_0_Value_EPT() (&Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_10ms_VCU_0_Value_EPT_VCU_0_Value_EPT->value)

#define Rte_IWrite_Runbl_OpmCanTx_10ms_VCU_10_Torque_CHA_VCU_10_Torque_CHA(data) (Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_10ms_VCU_10_Torque_CHA_VCU_10_Torque_CHA->value = *(data))

#define Rte_IWriteRef_Runbl_OpmCanTx_10ms_VCU_10_Torque_CHA_VCU_10_Torque_CHA() (&Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_10ms_VCU_10_Torque_CHA_VCU_10_Torque_CHA->value)

#define Rte_IWrite_Runbl_OpmCanTx_10ms_VCU_1_InvCmd_EPT_VCU_1_InvCmd_EPT(data) (Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_10ms_VCU_1_InvCmd_EPT_VCU_1_InvCmd_EPT->value = *(data))

#define Rte_IWriteRef_Runbl_OpmCanTx_10ms_VCU_1_InvCmd_EPT_VCU_1_InvCmd_EPT() (&Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_10ms_VCU_1_InvCmd_EPT_VCU_1_InvCmd_EPT->value)

#define Rte_IWrite_Runbl_OpmCanTx_20ms_VCU_3_OprtCmd_EPT_VCU_3_OprtCmd_EPT(data) (Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_20ms_VCU_3_OprtCmd_EPT_VCU_3_OprtCmd_EPT->value = *(data))

#define Rte_IWriteRef_Runbl_OpmCanTx_20ms_VCU_3_OprtCmd_EPT_VCU_3_OprtCmd_EPT() (&Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_20ms_VCU_3_OprtCmd_EPT_VCU_3_OprtCmd_EPT->value)

#define Rte_IWrite_Runbl_OpmCanTx_20ms_VCU_4_ChrgCmd_EPT_VCU_4_ChrgCmd_EPT(data) (Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_20ms_VCU_4_ChrgCmd_EPT_VCU_4_ChrgCmd_EPT->value = *(data))

#define Rte_IWriteRef_Runbl_OpmCanTx_20ms_VCU_4_ChrgCmd_EPT_VCU_4_ChrgCmd_EPT() (&Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_20ms_VCU_4_ChrgCmd_EPT_VCU_4_ChrgCmd_EPT->value)

#define Rte_IWrite_Runbl_OpmCanTx_20ms_VCU_B_AcclPedal_EPT_VCU_B_AcclPedal_EPT(data) (Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_20ms_VCU_B_AcclPedal_EPT_VCU_B_AcclPedal_EPT->value = *(data))

#define Rte_IWriteRef_Runbl_OpmCanTx_20ms_VCU_B_AcclPedal_EPT_VCU_B_AcclPedal_EPT() (&Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_20ms_VCU_B_AcclPedal_EPT_VCU_B_AcclPedal_EPT->value)

#define Rte_IWrite_Runbl_OpmCanTx_20ms_VCU_C_OprtCmd_EPT_VCU_C_OprtCmd_EPT(data) (Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_20ms_VCU_C_OprtCmd_EPT_VCU_C_OprtCmd_EPT->value = *(data))

#define Rte_IWriteRef_Runbl_OpmCanTx_20ms_VCU_C_OprtCmd_EPT_VCU_C_OprtCmd_EPT() (&Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_20ms_VCU_C_OprtCmd_EPT_VCU_C_OprtCmd_EPT->value)

#define Rte_IWrite_Runbl_OpmCanTx_20ms_VCU_D_Status_CHA_VCU_D_Status_CHA(data) (Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_20ms_VCU_D_Status_CHA_VCU_D_Status_CHA->value = *(data))

#define Rte_IWriteRef_Runbl_OpmCanTx_20ms_VCU_D_Status_CHA_VCU_D_Status_CHA() (&Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_20ms_VCU_D_Status_CHA_VCU_D_Status_CHA->value)

#define Rte_IWrite_Runbl_OpmCanTx_20ms_VCU_DispInfo_BAC_VCU_DispInfo_BAC(data) (Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_20ms_VCU_DispInfo_BAC_VCU_DispInfo_BAC->value = *(data))

#define Rte_IWriteRef_Runbl_OpmCanTx_20ms_VCU_DispInfo_BAC_VCU_DispInfo_BAC() (&Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_20ms_VCU_DispInfo_BAC_VCU_DispInfo_BAC->value)

#define Rte_IWrite_Runbl_OpmCanTx_50ms_BCM_B_Package_BAC_BCM_B_Package_BAC(data) (Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_50ms_BCM_B_Package_BAC_BCM_B_Package_BAC->value = *(data))

#define Rte_IWriteRef_Runbl_OpmCanTx_50ms_BCM_B_Package_BAC_BCM_B_Package_BAC() (&Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_50ms_BCM_B_Package_BAC_BCM_B_Package_BAC->value)

#define Rte_IWrite_Runbl_OpmCanTx_50ms_CCU_VehInfo_BAC_CCU_VehInfo_BAC(data) (Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_50ms_CCU_VehInfo_BAC_CCU_VehInfo_BAC->value = *(data))

#define Rte_IWriteRef_Runbl_OpmCanTx_50ms_CCU_VehInfo_BAC_CCU_VehInfo_BAC() (&Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_50ms_CCU_VehInfo_BAC_CCU_VehInfo_BAC->value)

#define Rte_IRead_Runbl_OpmRx_10ms_Bcm2OpmBAC_outputs_Bcm2OpmBAC_outputs() (&Rte_Inst_AppSwcOpm.Runbl_OpmRx_10ms_Bcm2OpmBAC_outputs_Bcm2OpmBAC_outputs->value)

#define Rte_IRead_Runbl_OpmRx_10ms_TMS2VCU_PPV_outputs_TMS2VCU_PPV_outputs() (&Rte_Inst_AppSwcOpm.Runbl_OpmRx_10ms_TMS2VCU_PPV_outputs_TMS2VCU_PPV_outputs->value)

#define Rte_IRead_Runbl_OpmRx_10ms_Vcu2OpmBAC_outputs_Vcu2OpmBAC_outputs() (&Rte_Inst_AppSwcOpm.Runbl_OpmRx_10ms_Vcu2OpmBAC_outputs_Vcu2OpmBAC_outputs->value)

#define Rte_IRead_Runbl_OpmRx_10ms_Vcu2OpmCHA_outputs_Vcu2OpmCHA_outputs() (&Rte_Inst_AppSwcOpm.Runbl_OpmRx_10ms_Vcu2OpmCHA_outputs_Vcu2OpmCHA_outputs->value)

#define Rte_IRead_Runbl_OpmRx_10ms_Vcu2OpmEPT_outputs_Vcu2OpmEPT_outputs() (&Rte_Inst_AppSwcOpm.Runbl_OpmRx_10ms_Vcu2OpmEPT_outputs_Vcu2OpmEPT_outputs->value)

#endif

/*******************************************************************************
 **                        Global Function Declarations                       **
******************************************************************************/

/** API functions */

void Rte_Runbl_OpmCanTx_100ms(void);

void Rte_Runbl_OpmCanTx_10ms(void);

void Rte_Runbl_OpmCanTx_20ms(void);

void Rte_Runbl_OpmCanTx_50ms(void);

void Rte_Runbl_OpmRx_10ms(void);

void Rte_AppSwcOpm_Init(void);

DT_Bcm2OpmBAC_outputs* Rte_IrvIRead_Runbl_OpmCanTx_100ms_Bcm2OpmBAC_outputs(void);

DT_Bcm2OpmBAC_outputs* Rte_IrvIRead_Runbl_OpmCanTx_20ms_Bcm2OpmBAC_outputs(void);

DT_Bcm2OpmBAC_outputs* Rte_IrvIRead_Runbl_OpmCanTx_50ms_Bcm2OpmBAC_outputs(void);

void Rte_IrvIWrite_Runbl_OpmRx_10ms_Bcm2OpmBAC_outputs(DT_Bcm2OpmBAC_outputs* data);

DT_Bcm2OpmBAC_outputs * Rte_IrvIWriteRef_Runbl_OpmRx_10ms_Bcm2OpmBAC_outputs(void);

TMS2VCU_PPVAddSignalGroup_Outputs* Rte_IrvIRead_Runbl_OpmCanTx_100ms_TMS2VCU_PPV_outputs(void);

TMS2VCU_PPVAddSignalGroup_Outputs* Rte_IrvIRead_Runbl_OpmCanTx_20ms_TMS2VCU_PPV_outputs(void);

void Rte_IrvIWrite_Runbl_OpmRx_10ms_TMS2VCU_PPV_outputs(TMS2VCU_PPVAddSignalGroup_Outputs* data);

TMS2VCU_PPVAddSignalGroup_Outputs * Rte_IrvIWriteRef_Runbl_OpmRx_10ms_TMS2VCU_PPV_outputs(void);

DT_Vcu2OpmBAC_outputs* Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmBAC_outputs(void);

DT_Vcu2OpmBAC_outputs* Rte_IrvIRead_Runbl_OpmCanTx_50ms_Vcu2OpmBAC_outputs(void);

void Rte_IrvIWrite_Runbl_OpmRx_10ms_Vcu2OpmBAC_outputs(DT_Vcu2OpmBAC_outputs* data);

DT_Vcu2OpmBAC_outputs * Rte_IrvIWriteRef_Runbl_OpmRx_10ms_Vcu2OpmBAC_outputs(void);

DT_Vcu2OpmCHA_outputs* Rte_IrvIRead_Runbl_OpmCanTx_10ms_Vcu2OpmCHA_outputs(void);

DT_Vcu2OpmCHA_outputs* Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmCHA_outputs(void);

void Rte_IrvIWrite_Runbl_OpmRx_10ms_Vcu2OpmCHA_outputs(DT_Vcu2OpmCHA_outputs* data);

DT_Vcu2OpmCHA_outputs * Rte_IrvIWriteRef_Runbl_OpmRx_10ms_Vcu2OpmCHA_outputs(void);

DT_Vcu2OpmEPT_outputs* Rte_IrvIRead_Runbl_OpmCanTx_10ms_Vcu2OpmEPT_outputs(void);

DT_Vcu2OpmEPT_outputs* Rte_IrvIRead_Runbl_OpmCanTx_20ms_Vcu2OpmEPT_outputs(void);

void Rte_IrvIWrite_Runbl_OpmRx_10ms_Vcu2OpmEPT_outputs(DT_Vcu2OpmEPT_outputs* data);

DT_Vcu2OpmEPT_outputs * Rte_IrvIWriteRef_Runbl_OpmRx_10ms_Vcu2OpmEPT_outputs(void);

Std_ReturnType Rte_IStatus_Runbl_OpmCanTx_100ms_Bcm2OpmEPT_outputs_Bcm2OpmEPT_outputs(void);

Std_ReturnType Rte_IStatus_Runbl_OpmCanTx_100ms_Bcm2OpmOBD_outputs_Bcm2OpmOBD_outputs(void);

Std_ReturnType Rte_IStatus_Runbl_OpmCanTx_100ms_TMS2VCU_AC_1_Command_Outputs_TMS2VCU_AC_1_Command_Outputs(void);

Std_ReturnType Rte_IStatus_Runbl_OpmCanTx_100ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs(void);

Std_ReturnType Rte_IStatus_Runbl_OpmCanTx_100ms_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs(void);

Std_ReturnType Rte_IStatus_Runbl_OpmCanTx_100ms_TMS2VCU_AC_8_status_Outputs_TMS2VCU_AC_8_status_Outputs(void);

Std_ReturnType Rte_IStatus_Runbl_OpmCanTx_100ms_TMS2VCU_AC_ACStatuts_Outputs_TMS2VCU_AC_ACStatuts_Outputs(void);

Std_ReturnType Rte_IStatus_Runbl_OpmCanTx_100ms_TMS2VCU_AC_COMP_Outputs_TMS2VCU_AC_COMP_Outputs(void);

Std_ReturnType Rte_IStatus_Runbl_OpmCanTx_100ms_TMS2VCU_HVCH_Command_Outputs_TMS2VCU_HVCH_Command_Outputs(void);

Std_ReturnType Rte_IStatus_Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData1_Outputs_TMS2VCU_TMS_LINTestData1_Outputs(void);

Std_ReturnType Rte_IStatus_Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData2_Outputs_TMS2VCU_TMS_LINTestData2_Outputs(void);

Std_ReturnType Rte_IStatus_Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData3_Outputs_TMS2VCU_TMS_LINTestData3_Outputs(void);

Std_ReturnType Rte_IStatus_Runbl_OpmCanTx_10ms_IPM_FCM_B_CHA_IPM_FCM_B_CHA(void);

Std_ReturnType Rte_IStatus_Runbl_OpmCanTx_10ms_IPM_INV_1_Value_EPT_IPM_INV_1_Value_EPT(void);

Std_ReturnType Rte_IStatus_Runbl_OpmRx_10ms_Bcm2OpmBAC_outputs_Bcm2OpmBAC_outputs(void);

Std_ReturnType Rte_IStatus_Runbl_OpmRx_10ms_TMS2VCU_PPV_outputs_TMS2VCU_PPV_outputs(void);

Std_ReturnType Rte_IStatus_Runbl_OpmRx_10ms_Vcu2OpmBAC_outputs_Vcu2OpmBAC_outputs(void);

Std_ReturnType Rte_IStatus_Runbl_OpmRx_10ms_Vcu2OpmCHA_outputs_Vcu2OpmCHA_outputs(void);

Std_ReturnType Rte_IStatus_Runbl_OpmRx_10ms_Vcu2OpmEPT_outputs_Vcu2OpmEPT_outputs(void);

/** runnables */

void Runbl_OpmCanTx_100ms(void);

void Runbl_OpmCanTx_10ms(void);

void Runbl_OpmCanTx_20ms(void);

void Runbl_OpmCanTx_50ms(void);

void Runbl_OpmRx_10ms(void);

void AppSwcOpm_Init(void);

#endif

