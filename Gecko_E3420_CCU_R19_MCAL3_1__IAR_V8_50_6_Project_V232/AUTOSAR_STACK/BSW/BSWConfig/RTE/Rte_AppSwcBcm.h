/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_AppSwcBcm.h>
 *  @brief      <>
 *  
 *  <MCU:E3420>
 *  
 *  @author     <>
 *  @date       <2024-08-17 16:07:03>
 */
/*============================================================================*/

/* Rte_AppSwcBcm.h */

#ifndef RTE_APPSWCBCM_H
#define RTE_APPSWCBCM_H

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
#include "Rte_AppSwcBcm_Type.h"

/*******************************************************************************
 **                        Macro Definitions                                  **
******************************************************************************/

typedef struct
{
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Runbl_AppSwcBcm_20ms_FCLL_TiWngSt_FCLL_TiWngSt;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Runbl_AppSwcBcm_20ms_FCLR_TiWngSt_FCLR_TiWngSt;
    P2VAR(Rte_DE_DT_IPM_BMS_1_MainState_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_AppSwcBcm_20ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT;
    P2VAR(Rte_DE_DT_IPM_CCP_PanelStatus_BOD_status, AUTOMATIC, RTE_DATA)  Runbl_AppSwcBcm_20ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD;
    P2VAR(Rte_DE_DT_IPM_CRRR_A_CHA_status, AUTOMATIC, RTE_DATA)  Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA;
    P2VAR(Rte_DE_DT_IPM_EHB_A_CHA_status, AUTOMATIC, RTE_DATA)  Runbl_AppSwcBcm_20ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA;
    P2VAR(Rte_DE_DT_IPM_ESC_7_FuncStatus_CHA_status, AUTOMATIC, RTE_DATA)  Runbl_AppSwcBcm_20ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA;
    P2VAR(Rte_DE_DT_IPM_HU_B_BAC_status, AUTOMATIC, RTE_DATA)  Runbl_AppSwcBcm_20ms_IPM_HU_B_BAC_IPM_HU_B_BAC;
    P2VAR(Rte_DE_DT_IPM_SCS_LeSwitchSts_BOD_status, AUTOMATIC, RTE_DATA)  Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD;
    P2VAR(Rte_DE_DT_IPM_SRS_1_Status_CHA_status, AUTOMATIC, RTE_DATA)  Runbl_AppSwcBcm_20ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA;
    P2VAR(Rte_DE_DT_Vcu2BcmTms_outputs_status, AUTOMATIC, RTE_DATA)  Runbl_AppSwcBcm_20ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs;
    P2VAR(Rte_DE_DT_IPM_ESCL_ESCLStatus_BOD_status, AUTOMATIC, RTE_DATA)  Runbl_AppSwcBcm_50ms_IPM_ESCL_ESCLStatus_BOD_IPM_ESCL_ESCLStatus_BOD;
    P2VAR(Rte_DE_DT_IPM_INV_IMMO_Req_EPT_status, AUTOMATIC, RTE_DATA)  Runbl_AppSwcBcm_50ms_IPM_INV_IMMO_Req_EPT_IPM_INV_IMMO_Req_EPT;
    P2VAR(Rte_DE_DT_Bcm2OpmBAC_outputs_status, AUTOMATIC, RTE_DATA)  Runbl_AppSwcBcm_20ms_Bcm2OpmBAC_outputs_Bcm2OpmBAC_outputs;
    P2VAR(Rte_DE_DT_Bcm2OpmEPT_outputs_status, AUTOMATIC, RTE_DATA)  Runbl_AppSwcBcm_20ms_Bcm2OpmEPT_outputs_Bcm2OpmEPT_outputs;
    P2VAR(Rte_DE_DT_Bcm2OpmOBD_outputs_status, AUTOMATIC, RTE_DATA)  Runbl_AppSwcBcm_20ms_Bcm2OpmOBD_outputs_Bcm2OpmOBD_outputs;
    P2VAR(Rte_DE_DT_Bcm2VcuTms_outputs_status, AUTOMATIC, RTE_DATA)  Runbl_AppSwcBcm_20ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Runbl_AppSwcBcm_20ms_Sig_Cmd_DrlLightReq_Sig_Cmd_DrlLightReq;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Runbl_AppSwcBcm_20ms_Sig_Cmd_PosLightReq_Sig_Cmd_PosLightReq;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Runbl_AppSwcBcm_20ms_Sig_Cmd_TiLeLightReq_Sig_Cmd_TiLeLightReq;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Runbl_AppSwcBcm_20ms_Sig_Cmd_TiRiLightReq_Sig_Cmd_TiRiLightReq;
    P2VAR(Rte_DE_UInt8_status, AUTOMATIC, RTE_DATA)  Runbl_AppSwcBcm_20ms_Sig_Cmd_TiWngFBSt_Sig_Cmd_TiWngFBSt;
} Rte_CDS_AppSwcBcm;

extern CONST(Rte_CDS_AppSwcBcm, RTE_CONST) Rte_Inst_AppSwcBcm;

#ifndef RTE_CORE
typedef CONSTP2CONST(Rte_CDS_AppSwcBcm, AUTOMATIC, RTE_CONST) Rte_Instance;
#endif

/** API mappings */

#ifndef RTE_CORE

#define Rte_IrvIRead_Runbl_AppSwcBcm_100ms_AlmSysCtl_Bus Rte_IrvIRead_Runbl_AppSwcBcm_100ms_AlmSysCtl_Bus

#define Rte_IrvIRead_Runbl_AppSwcBcm_10ms_AlmSysCtl_Bus Rte_IrvIRead_Runbl_AppSwcBcm_10ms_AlmSysCtl_Bus

#define Rte_IrvIRead_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus Rte_IrvIRead_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus

#define Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_AlmSysCtl_Bus Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_AlmSysCtl_Bus

#define Rte_IrvIRead_Runbl_AppSwcBcm_20ms_BatSaveCtl_Bus Rte_IrvIRead_Runbl_AppSwcBcm_20ms_BatSaveCtl_Bus

#define Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_BatSaveCtl_Bus Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_BatSaveCtl_Bus

#define Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus

#define Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus

#define Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_DoorLckCtl_Bus Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_DoorLckCtl_Bus

#define Rte_IrvIWrite_AppSwcBcm_Init_EEReadCtl_Bus Rte_IrvIWrite_AppSwcBcm_Init_EEReadCtl_Bus

#define Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_EEReadCtl_Bus Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_EEReadCtl_Bus

#define Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus

#define Rte_IrvIRead_Runbl_AppSwcBcm_20ms_ESCLCtl_Bus Rte_IrvIRead_Runbl_AppSwcBcm_20ms_ESCLCtl_Bus

#define Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_ESCLCtl_Bus Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_ESCLCtl_Bus

#define Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_HornCtl_Bus Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_HornCtl_Bus

#define Rte_IrvIRead_Runbl_AppSwcBcm_50ms_HornCtl_Bus Rte_IrvIRead_Runbl_AppSwcBcm_50ms_HornCtl_Bus

#define Rte_IrvIWrite_AppSwcBcm_Init_IMMOCtl_Bus Rte_IrvIWrite_AppSwcBcm_Init_IMMOCtl_Bus

#define Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IMMOCtl_Bus Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IMMOCtl_Bus

#define Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_IMMOCtl_Bus Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_IMMOCtl_Bus

#define Rte_IrvIWrite_Runbl_AppSwcBcm_100ms_IODID_Bus Rte_IrvIWrite_Runbl_AppSwcBcm_100ms_IODID_Bus

#define Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus

#define Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus

#define Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_CCP_PanelStatus_BOD Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_CCP_PanelStatus_BOD

#define Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_IPM_CCP_PanelStatus_BOD Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_IPM_CCP_PanelStatus_BOD

#define Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_CCP_PanelStatus_BOD Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_CCP_PanelStatus_BOD

#define Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_IPM_ESC_7_FuncStatus_CHA Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_IPM_ESC_7_FuncStatus_CHA

#define Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_ESC_7_FuncStatus_CHA Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_ESC_7_FuncStatus_CHA

#define Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_HU_B_BAC Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_HU_B_BAC

#define Rte_IrvIRead_Runbl_AppSwcBcm_10ms_IPM_HU_B_BAC Rte_IrvIRead_Runbl_AppSwcBcm_10ms_IPM_HU_B_BAC

#define Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_IPM_HU_B_BAC Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_IPM_HU_B_BAC

#define Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC

#define Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus

#define Rte_IrvIRead_Runbl_AppSwcBcm_10ms_LampCtl_Bus Rte_IrvIRead_Runbl_AppSwcBcm_10ms_LampCtl_Bus

#define Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_LampCtl_Bus Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_LampCtl_Bus

#define Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus

#define Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus

#define Rte_IrvIRead_Runbl_AppSwcBcm_10ms_PDUCtl_Bus Rte_IrvIRead_Runbl_AppSwcBcm_10ms_PDUCtl_Bus

#define Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus

#define Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_PDUCtl_Bus Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_PDUCtl_Bus

#define Rte_IrvIWrite_AppSwcBcm_Init_PEPSCtl_Bus Rte_IrvIWrite_AppSwcBcm_Init_PEPSCtl_Bus

#define Rte_IrvIWrite_Runbl_AppSwcBcm_10ms_PEPSCtl_Bus Rte_IrvIWrite_Runbl_AppSwcBcm_10ms_PEPSCtl_Bus

#define Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus

#define Rte_IrvIRead_Runbl_AppSwcBcm_50ms_PEPSCtl_Bus Rte_IrvIRead_Runbl_AppSwcBcm_50ms_PEPSCtl_Bus

#define Rte_IrvIWrite_Runbl_AppSwcBcm_100ms_RVMCtl_Bus Rte_IrvIWrite_Runbl_AppSwcBcm_100ms_RVMCtl_Bus

#define Rte_IrvIRead_Runbl_AppSwcBcm_20ms_RVMCtl_Bus Rte_IrvIRead_Runbl_AppSwcBcm_20ms_RVMCtl_Bus

#define Rte_IrvIWrite_Runbl_AppSwcBcm_100ms_SeatCtl_Bus Rte_IrvIWrite_Runbl_AppSwcBcm_100ms_SeatCtl_Bus

#define Rte_IrvIRead_Runbl_AppSwcBcm_20ms_SeatCtl_Bus Rte_IrvIRead_Runbl_AppSwcBcm_20ms_SeatCtl_Bus

#define Rte_IrvIWrite_Runbl_AppSwcBcm_100ms_SteerWhlCtl_Bus Rte_IrvIWrite_Runbl_AppSwcBcm_100ms_SteerWhlCtl_Bus

#define Rte_IrvIRead_Runbl_AppSwcBcm_20ms_SteerWhlCtl_Bus Rte_IrvIRead_Runbl_AppSwcBcm_20ms_SteerWhlCtl_Bus

#define Rte_IrvIRead_Runbl_AppSwcBcm_10ms_Vcu2BcmTms_outputs Rte_IrvIRead_Runbl_AppSwcBcm_10ms_Vcu2BcmTms_outputs

#define Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_Vcu2BcmTms_outputs Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_Vcu2BcmTms_outputs

#define Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs

#define Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WakeUpCtl_Bus Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WakeUpCtl_Bus

#define Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_WakeUpCtl_Bus Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_WakeUpCtl_Bus

#define Rte_IrvIWrite_Runbl_AppSwcBcm_100ms_WinCtl_Bus Rte_IrvIWrite_Runbl_AppSwcBcm_100ms_WinCtl_Bus

#define Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus

#define Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_Wiper_Bus Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_Wiper_Bus

#define Rte_IRead_Runbl_AppSwcBcm_20ms_FCLL_TiWngSt_FCLL_TiWngSt() (Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_FCLL_TiWngSt_FCLL_TiWngSt->value)

#define Rte_IRead_Runbl_AppSwcBcm_20ms_FCLR_TiWngSt_FCLR_TiWngSt() (Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_FCLR_TiWngSt_FCLR_TiWngSt->value)

#define Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT() (&Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT->value)

#define Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD() (&Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD->value)

#define Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA() (&Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA->value)

#define Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA() (&Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA->value)

#define Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA() (&Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA->value)

#define Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_HU_B_BAC_IPM_HU_B_BAC() (&Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_IPM_HU_B_BAC_IPM_HU_B_BAC->value)

#define Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD() (&Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD->value)

#define Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA() (&Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA->value)

#define Rte_IRead_Runbl_AppSwcBcm_20ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs() (&Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs->value)

#define Rte_IWrite_Runbl_AppSwcBcm_20ms_Bcm2OpmBAC_outputs_Bcm2OpmBAC_outputs(data) (Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_Bcm2OpmBAC_outputs_Bcm2OpmBAC_outputs->value = *(data))

#define Rte_IWriteRef_Runbl_AppSwcBcm_20ms_Bcm2OpmBAC_outputs_Bcm2OpmBAC_outputs() (&Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_Bcm2OpmBAC_outputs_Bcm2OpmBAC_outputs->value)

#define Rte_IWrite_Runbl_AppSwcBcm_20ms_Bcm2OpmEPT_outputs_Bcm2OpmEPT_outputs(data) (Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_Bcm2OpmEPT_outputs_Bcm2OpmEPT_outputs->value = *(data))

#define Rte_IWriteRef_Runbl_AppSwcBcm_20ms_Bcm2OpmEPT_outputs_Bcm2OpmEPT_outputs() (&Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_Bcm2OpmEPT_outputs_Bcm2OpmEPT_outputs->value)

#define Rte_IWrite_Runbl_AppSwcBcm_20ms_Bcm2OpmOBD_outputs_Bcm2OpmOBD_outputs(data) (Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_Bcm2OpmOBD_outputs_Bcm2OpmOBD_outputs->value = *(data))

#define Rte_IWriteRef_Runbl_AppSwcBcm_20ms_Bcm2OpmOBD_outputs_Bcm2OpmOBD_outputs() (&Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_Bcm2OpmOBD_outputs_Bcm2OpmOBD_outputs->value)

#define Rte_IWrite_Runbl_AppSwcBcm_20ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs(data) (Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs->value = *(data))

#define Rte_IWriteRef_Runbl_AppSwcBcm_20ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs() (&Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs->value)

#define Rte_IWrite_Runbl_AppSwcBcm_20ms_Sig_Cmd_DrlLightReq_Sig_Cmd_DrlLightReq(data) (Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_Sig_Cmd_DrlLightReq_Sig_Cmd_DrlLightReq->value = (data))

#define Rte_IWriteRef_Runbl_AppSwcBcm_20ms_Sig_Cmd_DrlLightReq_Sig_Cmd_DrlLightReq() (&Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_Sig_Cmd_DrlLightReq_Sig_Cmd_DrlLightReq->value)

#define Rte_IWrite_Runbl_AppSwcBcm_20ms_Sig_Cmd_PosLightReq_Sig_Cmd_PosLightReq(data) (Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_Sig_Cmd_PosLightReq_Sig_Cmd_PosLightReq->value = (data))

#define Rte_IWriteRef_Runbl_AppSwcBcm_20ms_Sig_Cmd_PosLightReq_Sig_Cmd_PosLightReq() (&Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_Sig_Cmd_PosLightReq_Sig_Cmd_PosLightReq->value)

#define Rte_IWrite_Runbl_AppSwcBcm_20ms_Sig_Cmd_TiLeLightReq_Sig_Cmd_TiLeLightReq(data) (Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_Sig_Cmd_TiLeLightReq_Sig_Cmd_TiLeLightReq->value = (data))

#define Rte_IWriteRef_Runbl_AppSwcBcm_20ms_Sig_Cmd_TiLeLightReq_Sig_Cmd_TiLeLightReq() (&Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_Sig_Cmd_TiLeLightReq_Sig_Cmd_TiLeLightReq->value)

#define Rte_IWrite_Runbl_AppSwcBcm_20ms_Sig_Cmd_TiRiLightReq_Sig_Cmd_TiRiLightReq(data) (Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_Sig_Cmd_TiRiLightReq_Sig_Cmd_TiRiLightReq->value = (data))

#define Rte_IWriteRef_Runbl_AppSwcBcm_20ms_Sig_Cmd_TiRiLightReq_Sig_Cmd_TiRiLightReq() (&Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_Sig_Cmd_TiRiLightReq_Sig_Cmd_TiRiLightReq->value)

#define Rte_IWrite_Runbl_AppSwcBcm_20ms_Sig_Cmd_TiWngFBSt_Sig_Cmd_TiWngFBSt(data) (Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_Sig_Cmd_TiWngFBSt_Sig_Cmd_TiWngFBSt->value = (data))

#define Rte_IWriteRef_Runbl_AppSwcBcm_20ms_Sig_Cmd_TiWngFBSt_Sig_Cmd_TiWngFBSt() (&Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_Sig_Cmd_TiWngFBSt_Sig_Cmd_TiWngFBSt->value)

#define Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_ESCL_ESCLStatus_BOD_IPM_ESCL_ESCLStatus_BOD() (&Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_50ms_IPM_ESCL_ESCLStatus_BOD_IPM_ESCL_ESCLStatus_BOD->value)

#define Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_INV_IMMO_Req_EPT_IPM_INV_IMMO_Req_EPT() (&Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_50ms_IPM_INV_IMMO_Req_EPT_IPM_INV_IMMO_Req_EPT->value)

#endif

/*******************************************************************************
 **                        Global Function Declarations                       **
******************************************************************************/

/** API functions */

void Rte_Runbl_AppSwcBcm_100ms(void);

void Rte_Runbl_AppSwcBcm_10ms(void);

void Rte_Runbl_AppSwcBcm_20ms(void);

void Rte_Runbl_AppSwcBcm_50ms(void);

void Rte_AppSwcBcm_Init(void);

AlmSysCtl* Rte_IrvIRead_Runbl_AppSwcBcm_100ms_AlmSysCtl_Bus(void);

AlmSysCtl* Rte_IrvIRead_Runbl_AppSwcBcm_10ms_AlmSysCtl_Bus(void);

AlmSysCtl* Rte_IrvIRead_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus(void);

void Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_AlmSysCtl_Bus(AlmSysCtl* data);

AlmSysCtl * Rte_IrvIWriteRef_Runbl_AppSwcBcm_50ms_AlmSysCtl_Bus(void);

BatSaveCtl* Rte_IrvIRead_Runbl_AppSwcBcm_20ms_BatSaveCtl_Bus(void);

void Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_BatSaveCtl_Bus(BatSaveCtl* data);

BatSaveCtl * Rte_IrvIWriteRef_Runbl_AppSwcBcm_50ms_BatSaveCtl_Bus(void);

DoorLckCtl* Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus(void);

DoorLckCtl* Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus(void);

void Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_DoorLckCtl_Bus(DoorLckCtl* data);

DoorLckCtl * Rte_IrvIWriteRef_Runbl_AppSwcBcm_50ms_DoorLckCtl_Bus(void);

void Rte_IrvIWrite_AppSwcBcm_Init_EEReadCtl_Bus(EEReadCtl* data);

EEReadCtl * Rte_IrvIWriteRef_AppSwcBcm_Init_EEReadCtl_Bus(void);

void Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_EEReadCtl_Bus(EEReadCtl* data);

EEReadCtl * Rte_IrvIWriteRef_Runbl_AppSwcBcm_20ms_EEReadCtl_Bus(void);

EEReadCtl* Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus(void);

ESCLCtl* Rte_IrvIRead_Runbl_AppSwcBcm_20ms_ESCLCtl_Bus(void);

void Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_ESCLCtl_Bus(ESCLCtl* data);

ESCLCtl * Rte_IrvIWriteRef_Runbl_AppSwcBcm_50ms_ESCLCtl_Bus(void);

void Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_HornCtl_Bus(HornCtl* data);

HornCtl * Rte_IrvIWriteRef_Runbl_AppSwcBcm_20ms_HornCtl_Bus(void);

HornCtl* Rte_IrvIRead_Runbl_AppSwcBcm_50ms_HornCtl_Bus(void);

void Rte_IrvIWrite_AppSwcBcm_Init_IMMOCtl_Bus(IMMOCtl* data);

IMMOCtl * Rte_IrvIWriteRef_AppSwcBcm_Init_IMMOCtl_Bus(void);

IMMOCtl* Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IMMOCtl_Bus(void);

void Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_IMMOCtl_Bus(IMMOCtl* data);

IMMOCtl * Rte_IrvIWriteRef_Runbl_AppSwcBcm_50ms_IMMOCtl_Bus(void);

void Rte_IrvIWrite_Runbl_AppSwcBcm_100ms_IODID_Bus(IODID* data);

IODID * Rte_IrvIWriteRef_Runbl_AppSwcBcm_100ms_IODID_Bus(void);

IODID* Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus(void);

IODID* Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus(void);

DT_IPM_CCP_PanelStatus_BOD* Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_CCP_PanelStatus_BOD(void);

void Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_IPM_CCP_PanelStatus_BOD(DT_IPM_CCP_PanelStatus_BOD* data);

DT_IPM_CCP_PanelStatus_BOD * Rte_IrvIWriteRef_Runbl_AppSwcBcm_20ms_IPM_CCP_PanelStatus_BOD(void);

DT_IPM_CCP_PanelStatus_BOD* Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_CCP_PanelStatus_BOD(void);

void Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_IPM_ESC_7_FuncStatus_CHA(DT_IPM_ESC_7_FuncStatus_CHA* data);

DT_IPM_ESC_7_FuncStatus_CHA * Rte_IrvIWriteRef_Runbl_AppSwcBcm_20ms_IPM_ESC_7_FuncStatus_CHA(void);

DT_IPM_ESC_7_FuncStatus_CHA* Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_ESC_7_FuncStatus_CHA(void);

DT_IPM_HU_B_BAC* Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_HU_B_BAC(void);

DT_IPM_HU_B_BAC* Rte_IrvIRead_Runbl_AppSwcBcm_10ms_IPM_HU_B_BAC(void);

void Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_IPM_HU_B_BAC(DT_IPM_HU_B_BAC* data);

DT_IPM_HU_B_BAC * Rte_IrvIWriteRef_Runbl_AppSwcBcm_20ms_IPM_HU_B_BAC(void);

DT_IPM_HU_B_BAC* Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC(void);

LampCtl* Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus(void);

LampCtl* Rte_IrvIRead_Runbl_AppSwcBcm_10ms_LampCtl_Bus(void);

void Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_LampCtl_Bus(LampCtl* data);

LampCtl * Rte_IrvIWriteRef_Runbl_AppSwcBcm_20ms_LampCtl_Bus(void);

LampCtl* Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus(void);

PDUCtl* Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus(void);

PDUCtl* Rte_IrvIRead_Runbl_AppSwcBcm_10ms_PDUCtl_Bus(void);

PDUCtl* Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus(void);

void Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_PDUCtl_Bus(PDUCtl* data);

PDUCtl * Rte_IrvIWriteRef_Runbl_AppSwcBcm_50ms_PDUCtl_Bus(void);

void Rte_IrvIWrite_AppSwcBcm_Init_PEPSCtl_Bus(PEPSCtl* data);

PEPSCtl * Rte_IrvIWriteRef_AppSwcBcm_Init_PEPSCtl_Bus(void);

void Rte_IrvIWrite_Runbl_AppSwcBcm_10ms_PEPSCtl_Bus(PEPSCtl* data);

PEPSCtl * Rte_IrvIWriteRef_Runbl_AppSwcBcm_10ms_PEPSCtl_Bus(void);

PEPSCtl* Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus(void);

PEPSCtl* Rte_IrvIRead_Runbl_AppSwcBcm_50ms_PEPSCtl_Bus(void);

void Rte_IrvIWrite_Runbl_AppSwcBcm_100ms_RVMCtl_Bus(RVMCtl* data);

RVMCtl * Rte_IrvIWriteRef_Runbl_AppSwcBcm_100ms_RVMCtl_Bus(void);

RVMCtl* Rte_IrvIRead_Runbl_AppSwcBcm_20ms_RVMCtl_Bus(void);

void Rte_IrvIWrite_Runbl_AppSwcBcm_100ms_SeatCtl_Bus(SeatCtl* data);

SeatCtl * Rte_IrvIWriteRef_Runbl_AppSwcBcm_100ms_SeatCtl_Bus(void);

SeatCtl* Rte_IrvIRead_Runbl_AppSwcBcm_20ms_SeatCtl_Bus(void);

void Rte_IrvIWrite_Runbl_AppSwcBcm_100ms_SteerWhlCtl_Bus(SteerWhlCtl* data);

SteerWhlCtl * Rte_IrvIWriteRef_Runbl_AppSwcBcm_100ms_SteerWhlCtl_Bus(void);

SteerWhlCtl* Rte_IrvIRead_Runbl_AppSwcBcm_20ms_SteerWhlCtl_Bus(void);

DT_Vcu2BcmTms_outputs* Rte_IrvIRead_Runbl_AppSwcBcm_10ms_Vcu2BcmTms_outputs(void);

void Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_Vcu2BcmTms_outputs(DT_Vcu2BcmTms_outputs* data);

DT_Vcu2BcmTms_outputs * Rte_IrvIWriteRef_Runbl_AppSwcBcm_20ms_Vcu2BcmTms_outputs(void);

DT_Vcu2BcmTms_outputs* Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs(void);

WakeUpCtl* Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WakeUpCtl_Bus(void);

void Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_WakeUpCtl_Bus(WakeUpCtl* data);

WakeUpCtl * Rte_IrvIWriteRef_Runbl_AppSwcBcm_50ms_WakeUpCtl_Bus(void);

void Rte_IrvIWrite_Runbl_AppSwcBcm_100ms_WinCtl_Bus(WinCtl* data);

WinCtl * Rte_IrvIWriteRef_Runbl_AppSwcBcm_100ms_WinCtl_Bus(void);

WinCtl* Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus(void);

void Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_Wiper_Bus(WiperCtl* data);

WiperCtl * Rte_IrvIWriteRef_Runbl_AppSwcBcm_20ms_Wiper_Bus(void);

Std_ReturnType Rte_IStatus_Runbl_AppSwcBcm_20ms_FCLL_TiWngSt_FCLL_TiWngSt(void);

Std_ReturnType Rte_IStatus_Runbl_AppSwcBcm_20ms_FCLR_TiWngSt_FCLR_TiWngSt(void);

Std_ReturnType Rte_IStatus_Runbl_AppSwcBcm_20ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT(void);

Std_ReturnType Rte_IStatus_Runbl_AppSwcBcm_20ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD(void);

Std_ReturnType Rte_IStatus_Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA(void);

Std_ReturnType Rte_IStatus_Runbl_AppSwcBcm_20ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA(void);

Std_ReturnType Rte_IStatus_Runbl_AppSwcBcm_20ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA(void);

Std_ReturnType Rte_IStatus_Runbl_AppSwcBcm_20ms_IPM_HU_B_BAC_IPM_HU_B_BAC(void);

Std_ReturnType Rte_IStatus_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD(void);

Std_ReturnType Rte_IStatus_Runbl_AppSwcBcm_20ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA(void);

Std_ReturnType Rte_IStatus_Runbl_AppSwcBcm_20ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs(void);

Std_ReturnType Rte_IStatus_Runbl_AppSwcBcm_50ms_IPM_ESCL_ESCLStatus_BOD_IPM_ESCL_ESCLStatus_BOD(void);

Std_ReturnType Rte_IStatus_Runbl_AppSwcBcm_50ms_IPM_INV_IMMO_Req_EPT_IPM_INV_IMMO_Req_EPT(void);

/** runnables */

void Runbl_AppSwcBcm_100ms(void);

void Runbl_AppSwcBcm_10ms(void);

void Runbl_AppSwcBcm_20ms(void);

void Runbl_AppSwcBcm_50ms(void);

void AppSwcBcm_Init(void);

#endif

