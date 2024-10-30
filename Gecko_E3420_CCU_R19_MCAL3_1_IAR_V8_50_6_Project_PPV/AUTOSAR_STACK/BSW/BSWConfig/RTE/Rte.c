/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte.c>
 *  @brief      <>
 *  
 *  <MCU:E3420>
 *  
 *  @author     <>
 *  @date       <2024-10-10 14:05:08>
 */
/*============================================================================*/

/* Rte.c */
/*******************************************************************************
 **                        Revision Control History                           **
******************************************************************************/

/*******************************************************************************
 **                        Version Information                                **
******************************************************************************/

#define RTE_CORE

/*******************************************************************************
 **                        Include Section                                    **
******************************************************************************/
#include "Os.h"
#include "Rte_Type.h"
#include "Rte_Data.h"
#include "Rte_Main.h"
#include "Rte_AppSwcBcm.h"
#include "Rte_AppSwcIpm.h"
#include "Rte_AppSwcOpm.h"
#include "Rte_ME11.h"
#include "Rte_AppSwcVcu.h"
#include "Com.h"

/*******************************************************************************
 **                        Global Variable Definitions                        **
******************************************************************************/

#define RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
Rte_InitStatusType RteInitState;
#define RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

/*******************************************************************************
 **                        Global Function Declarations                       **
******************************************************************************/

/*******************************************************************************
 **                        Global Function Definitions                        **
******************************************************************************/

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Runbl_AppSwcBcm_20ms_FCLL_TiWngSt_FCLL_TiWngSt_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Runbl_AppSwcBcm_20ms_FCLR_TiWngSt_FCLR_TiWngSt_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_BMS_1_MainState_EPT_status Rte_Buf_Runbl_AppSwcBcm_20ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_CCP_PanelStatus_BOD_status Rte_Buf_Runbl_AppSwcBcm_20ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_CRRR_A_CHA_status Rte_Buf_Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_EHB_A_CHA_status Rte_Buf_Runbl_AppSwcBcm_20ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_EHB_B_CHA_status Rte_Buf_Runbl_AppSwcBcm_20ms_IPM_EHB_B_CHA_IPM_EHB_B_CHA_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_ESC_7_FuncStatus_CHA_status Rte_Buf_Runbl_AppSwcBcm_20ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_HU_B_BAC_status Rte_Buf_Runbl_AppSwcBcm_20ms_IPM_HU_B_BAC_IPM_HU_B_BAC_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_SCS_LeSwitchSts_BOD_status Rte_Buf_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_SRS_1_Status_CHA_status Rte_Buf_Runbl_AppSwcBcm_20ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA_ibuffer = {.value = {0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_Vcu2BcmTms_outputs_status Rte_Buf_Runbl_AppSwcBcm_20ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_ESCL_ESCLStatus_BOD_status Rte_Buf_Runbl_AppSwcBcm_50ms_IPM_ESCL_ESCLStatus_BOD_IPM_ESCL_ESCLStatus_BOD_ibuffer = {.value = {0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_INV_IMMO_Req_EPT_status Rte_Buf_Runbl_AppSwcBcm_50ms_IPM_INV_IMMO_Req_EPT_IPM_INV_IMMO_Req_EPT_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_Bcm2OpmBAC_outputs_status Rte_Buf_Runbl_AppSwcBcm_20ms_Bcm2OpmBAC_outputs_Bcm2OpmBAC_outputs_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_Bcm2OpmEPT_outputs_status Rte_Buf_Runbl_AppSwcBcm_20ms_Bcm2OpmEPT_outputs_Bcm2OpmEPT_outputs_ibuffer = {.value = {0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_Bcm2OpmOBD_outputs_status Rte_Buf_Runbl_AppSwcBcm_20ms_Bcm2OpmOBD_outputs_Bcm2OpmOBD_outputs_ibuffer = {.value = {0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_Bcm2VcuTms_outputs_status Rte_Buf_Runbl_AppSwcBcm_20ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Runbl_AppSwcBcm_20ms_Sig_Cmd_DrlLightReq_Sig_Cmd_DrlLightReq_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Runbl_AppSwcBcm_20ms_Sig_Cmd_PosLightReq_Sig_Cmd_PosLightReq_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Runbl_AppSwcBcm_20ms_Sig_Cmd_TiLeLightReq_Sig_Cmd_TiLeLightReq_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Runbl_AppSwcBcm_20ms_Sig_Cmd_TiRiLightReq_Sig_Cmd_TiRiLightReq_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Runbl_AppSwcBcm_20ms_Sig_Cmd_TiWngFBSt_Sig_Cmd_TiWngFBSt_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_CONST_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
CONST(Rte_CDS_AppSwcBcm, RTE_CONST) Rte_Inst_AppSwcBcm =
{
    .Runbl_AppSwcBcm_20ms_FCLL_TiWngSt_FCLL_TiWngSt = &Rte_Buf_Runbl_AppSwcBcm_20ms_FCLL_TiWngSt_FCLL_TiWngSt_ibuffer,
    .Runbl_AppSwcBcm_20ms_FCLR_TiWngSt_FCLR_TiWngSt = &Rte_Buf_Runbl_AppSwcBcm_20ms_FCLR_TiWngSt_FCLR_TiWngSt_ibuffer,
    .Runbl_AppSwcBcm_20ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT = &Rte_Buf_Runbl_AppSwcBcm_20ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT_ibuffer,
    .Runbl_AppSwcBcm_20ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD = &Rte_Buf_Runbl_AppSwcBcm_20ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD_ibuffer,
    .Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA = &Rte_Buf_Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA_ibuffer,
    .Runbl_AppSwcBcm_20ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA = &Rte_Buf_Runbl_AppSwcBcm_20ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA_ibuffer,
    .Runbl_AppSwcBcm_20ms_IPM_EHB_B_CHA_IPM_EHB_B_CHA = &Rte_Buf_Runbl_AppSwcBcm_20ms_IPM_EHB_B_CHA_IPM_EHB_B_CHA_ibuffer,
    .Runbl_AppSwcBcm_20ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA = &Rte_Buf_Runbl_AppSwcBcm_20ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA_ibuffer,
    .Runbl_AppSwcBcm_20ms_IPM_HU_B_BAC_IPM_HU_B_BAC = &Rte_Buf_Runbl_AppSwcBcm_20ms_IPM_HU_B_BAC_IPM_HU_B_BAC_ibuffer,
    .Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD = &Rte_Buf_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD_ibuffer,
    .Runbl_AppSwcBcm_20ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA = &Rte_Buf_Runbl_AppSwcBcm_20ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA_ibuffer,
    .Runbl_AppSwcBcm_20ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs = &Rte_Buf_Runbl_AppSwcBcm_20ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs_ibuffer,
    .Runbl_AppSwcBcm_50ms_IPM_ESCL_ESCLStatus_BOD_IPM_ESCL_ESCLStatus_BOD = &Rte_Buf_Runbl_AppSwcBcm_50ms_IPM_ESCL_ESCLStatus_BOD_IPM_ESCL_ESCLStatus_BOD_ibuffer,
    .Runbl_AppSwcBcm_50ms_IPM_INV_IMMO_Req_EPT_IPM_INV_IMMO_Req_EPT = &Rte_Buf_Runbl_AppSwcBcm_50ms_IPM_INV_IMMO_Req_EPT_IPM_INV_IMMO_Req_EPT_ibuffer,
    .Runbl_AppSwcBcm_20ms_Bcm2OpmBAC_outputs_Bcm2OpmBAC_outputs = &Rte_Buf_Runbl_AppSwcBcm_20ms_Bcm2OpmBAC_outputs_Bcm2OpmBAC_outputs_ibuffer,
    .Runbl_AppSwcBcm_20ms_Bcm2OpmEPT_outputs_Bcm2OpmEPT_outputs = &Rte_Buf_Runbl_AppSwcBcm_20ms_Bcm2OpmEPT_outputs_Bcm2OpmEPT_outputs_ibuffer,
    .Runbl_AppSwcBcm_20ms_Bcm2OpmOBD_outputs_Bcm2OpmOBD_outputs = &Rte_Buf_Runbl_AppSwcBcm_20ms_Bcm2OpmOBD_outputs_Bcm2OpmOBD_outputs_ibuffer,
    .Runbl_AppSwcBcm_20ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs = &Rte_Buf_Runbl_AppSwcBcm_20ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs_ibuffer,
    .Runbl_AppSwcBcm_20ms_Sig_Cmd_DrlLightReq_Sig_Cmd_DrlLightReq = &Rte_Buf_Runbl_AppSwcBcm_20ms_Sig_Cmd_DrlLightReq_Sig_Cmd_DrlLightReq_ibuffer,
    .Runbl_AppSwcBcm_20ms_Sig_Cmd_PosLightReq_Sig_Cmd_PosLightReq = &Rte_Buf_Runbl_AppSwcBcm_20ms_Sig_Cmd_PosLightReq_Sig_Cmd_PosLightReq_ibuffer,
    .Runbl_AppSwcBcm_20ms_Sig_Cmd_TiLeLightReq_Sig_Cmd_TiLeLightReq = &Rte_Buf_Runbl_AppSwcBcm_20ms_Sig_Cmd_TiLeLightReq_Sig_Cmd_TiLeLightReq_ibuffer,
    .Runbl_AppSwcBcm_20ms_Sig_Cmd_TiRiLightReq_Sig_Cmd_TiRiLightReq = &Rte_Buf_Runbl_AppSwcBcm_20ms_Sig_Cmd_TiRiLightReq_Sig_Cmd_TiRiLightReq_ibuffer,
    .Runbl_AppSwcBcm_20ms_Sig_Cmd_TiWngFBSt_Sig_Cmd_TiWngFBSt = &Rte_Buf_Runbl_AppSwcBcm_20ms_Sig_Cmd_TiWngFBSt_Sig_Cmd_TiWngFBSt_ibuffer,
};
#define RTE_STOP_SEC_CONST_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_ACCM_Version_BOD_status Rte_Buf_Runbl_IpmCanRx_100ms_ACCM_Version_BOD_ACCM_Version_BOD_ibuffer = {.value = {0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_BMS_5_BatTemp_EPT_status Rte_Buf_Runbl_IpmCanRx_100ms_BMS_5_BatTemp_EPT_BMS_5_BatTemp_EPT_ibuffer = {.value = {0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_BMS_9_BattInfo_EPT_status Rte_Buf_Runbl_IpmCanRx_100ms_BMS_9_BattInfo_EPT_BMS_9_BattInfo_EPT_ibuffer = {.value = {0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_COMP_AC_BOD_status Rte_Buf_Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_HU_B_BAC_status Rte_Buf_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_HVCH_Status1_BOD_status Rte_Buf_Runbl_IpmCanRx_100ms_HVCH_Status1_BOD_HVCH_Status1_BOD_ibuffer = {.value = {0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_HVCH_Status2_BOD_status Rte_Buf_Runbl_IpmCanRx_100ms_HVCH_Status2_BOD_HVCH_Status2_BOD_ibuffer = {.value = {0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_INV_IMMO_Req_EPT_status Rte_Buf_Runbl_IpmCanRx_100ms_INV_IMMO_Req_EPT_INV_IMMO_Req_EPT_ibuffer = {.value = {0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_IPU_DCC_1_State_EPT_status Rte_Buf_Runbl_IpmCanRx_100ms_IPU_DCC_1_State_EPT_IPU_DCC_1_State_EPT_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_IPU_DCC_2_ChrgInValue_EPT_status Rte_Buf_Runbl_IpmCanRx_100ms_IPU_DCC_2_ChrgInValue_EPT_IPU_DCC_2_ChrgInValue_EPT_ibuffer = {.value = {0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_IPU_OBC_1_State_EPT_status Rte_Buf_Runbl_IpmCanRx_100ms_IPU_OBC_1_State_EPT_IPU_OBC_1_State_EPT_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_IPU_OBC_2_Inlet_EPT_status Rte_Buf_Runbl_IpmCanRx_100ms_IPU_OBC_2_Inlet_EPT_IPU_OBC_2_Inlet_EPT_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_TBOX_BJS_Time_BAC_status Rte_Buf_Runbl_IpmCanRx_100ms_TBOX_BJS_Time_BAC_TBOX_BJS_Time_BAC_ibuffer = {.value = {0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_EHB_B_CHA_status Rte_Buf_Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_EPS_2_StrWhlAng_CHA_status Rte_Buf_Runbl_IpmCanRx_10ms_EPS_2_StrWhlAng_CHA_EPS_2_StrWhlAng_CHA_ibuffer = {.value = {0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_ESC_7_FuncStatus_CHA_status Rte_Buf_Runbl_IpmCanRx_10ms_ESC_7_FuncStatus_CHA_ESC_7_FuncStatus_CHA_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_ESC_A_CHA_status Rte_Buf_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_INV_1_Value_EPT_status Rte_Buf_Runbl_IpmCanRx_10ms_INV_1_Value_EPT_INV_1_Value_EPT_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_INV_2_Value_EPT_status Rte_Buf_Runbl_IpmCanRx_10ms_INV_2_Value_EPT_INV_2_Value_EPT_ibuffer = {.value = {0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_INV_3_Value_EPT_status Rte_Buf_Runbl_IpmCanRx_10ms_INV_3_Value_EPT_INV_3_Value_EPT_ibuffer = {.value = {0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_INV_4_Value_EPT_status Rte_Buf_Runbl_IpmCanRx_10ms_INV_4_Value_EPT_INV_4_Value_EPT_ibuffer = {.value = {0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_BMS_10_DC_ChargeStates_EPT_status Rte_Buf_Runbl_IpmCanRx_20ms_BMS_10_DC_ChargeStates_EPT_BMS_10_DC_ChargeStates_EPT_ibuffer = {.value = {0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_BMS_1_MainState_EPT_status Rte_Buf_Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_BMS_2_BatState_EPT_status Rte_Buf_Runbl_IpmCanRx_20ms_BMS_2_BatState_EPT_BMS_2_BatState_EPT_ibuffer = {.value = {0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_BMS_3_DC_ChargeState_EPT_status Rte_Buf_Runbl_IpmCanRx_20ms_BMS_3_DC_ChargeState_EPT_BMS_3_DC_ChargeState_EPT_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_BMS_4_AC_ChargeState_EPT_status Rte_Buf_Runbl_IpmCanRx_20ms_BMS_4_AC_ChargeState_EPT_BMS_4_AC_ChargeState_EPT_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_BMS_6_DischrgRecup_EPT_status Rte_Buf_Runbl_IpmCanRx_20ms_BMS_6_DischrgRecup_EPT_BMS_6_DischrgRecup_EPT_ibuffer = {.value = {0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_BMS_7_CellVolt_EPT_status Rte_Buf_Runbl_IpmCanRx_20ms_BMS_7_CellVolt_EPT_BMS_7_CellVolt_EPT_ibuffer = {.value = {0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_CRRR_A_CHA_status Rte_Buf_Runbl_IpmCanRx_20ms_CRRR_A_CHA_CRRR_A_CHA_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_EHB_A_CHA_status Rte_Buf_Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_FCM_B_CHA_status Rte_Buf_Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_SCS_RiSwitchSts_BOD_status Rte_Buf_Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_CCP_PanelStatus_BOD_status Rte_Buf_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_ESCL_ESCLStatus_BOD_status Rte_Buf_Runbl_IpmCanRx_50ms_ESCL_ESCLStatus_BOD_ESCL_ESCLStatus_BOD_ibuffer = {.value = {0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_SCS_LeSwitchSts_BOD_status Rte_Buf_Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_SRS_1_Status_CHA_status Rte_Buf_Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DAG_Comm_outputs_status Rte_Buf_Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_ACCM_Version_BOD_status Rte_Buf_Runbl_IpmCanRx_100ms_IPM_ACCM_Version_BOD_IPM_ACCM_Version_BOD_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_BMS_5_BatTemp_EPT_status Rte_Buf_Runbl_IpmCanRx_100ms_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT_ibuffer = {.value = {0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_BMS_9_BattInfo_EPT_status Rte_Buf_Runbl_IpmCanRx_100ms_IPM_BMS_9_BattInfo_EPT_IPM_BMS_9_BattInfo_EPT_ibuffer = {.value = {0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_COMP_AC_BOD_status Rte_Buf_Runbl_IpmCanRx_100ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_HU_B_BAC_status Rte_Buf_Runbl_IpmCanRx_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_HVCH_Status1_BOD_status Rte_Buf_Runbl_IpmCanRx_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_HVCH_Status2_BOD_status Rte_Buf_Runbl_IpmCanRx_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_INV_IMMO_Req_EPT_status Rte_Buf_Runbl_IpmCanRx_100ms_IPM_INV_IMMO_Req_EPT_IPM_INV_IMMO_Req_EPT_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_IPU_DCC_1_State_EPT_status Rte_Buf_Runbl_IpmCanRx_100ms_IPM_IPU_DCC_1_State_EPT_IPM_IPU_DCC_1_State_EPT_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_IPU_DCC_2_ChrgInValue_EPT_status Rte_Buf_Runbl_IpmCanRx_100ms_IPM_IPU_DCC_2_ChrgInValue_EPT_IPM_IPU_DCC_2_ChrgInValue_EPT_ibuffer = {.value = {0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_IPU_OBC_1_State_EPT_status Rte_Buf_Runbl_IpmCanRx_100ms_IPM_IPU_OBC_1_State_EPT_IPM_IPU_OBC_1_State_EPT_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_IPU_OBC_2_Inlet_EPT_status Rte_Buf_Runbl_IpmCanRx_100ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_TBOX_BJS_Time_BAC_status Rte_Buf_Runbl_IpmCanRx_100ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_EHB_B_CHA_status Rte_Buf_Runbl_IpmCanRx_10ms_IPM_EHB_B_CHA_IPM_EHB_B_CHA_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_EPS_2_StrWhlAng_CHA_status Rte_Buf_Runbl_IpmCanRx_10ms_IPM_EPS_2_StrWhlAng_CHA_IPM_EPS_2_StrWhlAng_CHA_ibuffer = {.value = {0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_ESC_7_FuncStatus_CHA_status Rte_Buf_Runbl_IpmCanRx_10ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_ESC_A_CHA_status Rte_Buf_Runbl_IpmCanRx_10ms_IPM_ESC_A_CHA_IPM_ESC_A_CHA_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_INV_1_Value_EPT_status Rte_Buf_Runbl_IpmCanRx_10ms_IPM_INV_1_Value_EPT_IPM_INV_1_Value_EPT_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_INV_2_Value_EPT_status Rte_Buf_Runbl_IpmCanRx_10ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT_ibuffer = {.value = {0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_INV_3_Value_EPT_status Rte_Buf_Runbl_IpmCanRx_10ms_IPM_INV_3_Value_EPT_IPM_INV_3_Value_EPT_ibuffer = {.value = {0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_INV_4_Value_EPT_status Rte_Buf_Runbl_IpmCanRx_10ms_IPM_INV_4_Value_EPT_IPM_INV_4_Value_EPT_ibuffer = {.value = {0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_BMS_10_DC_ChargeStates_EPT_status Rte_Buf_Runbl_IpmCanRx_20ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT_ibuffer = {.value = {0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_BMS_1_MainState_EPT_status Rte_Buf_Runbl_IpmCanRx_20ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_BMS_2_BatState_EPT_status Rte_Buf_Runbl_IpmCanRx_20ms_IPM_BMS_2_BatState_EPT_IPM_BMS_2_BatState_EPT_ibuffer = {.value = {0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_BMS_3_DC_ChargeState_EPT_status Rte_Buf_Runbl_IpmCanRx_20ms_IPM_BMS_3_DC_ChargeState_EPT_IPM_BMS_3_DC_ChargeState_EPT_ibuffer = {.value = {0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_BMS_4_AC_ChargeState_EPT_status Rte_Buf_Runbl_IpmCanRx_20ms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_BMS_6_DischrgRecup_EPT_status Rte_Buf_Runbl_IpmCanRx_20ms_IPM_BMS_6_DischrgRecup_EPT_IPM_BMS_6_DischrgRecup_EPT_ibuffer = {.value = {0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_BMS_7_CellVolt_EPT_status Rte_Buf_Runbl_IpmCanRx_20ms_IPM_BMS_7_CellVolt_EPT_IPM_BMS_7_CellVolt_EPT_ibuffer = {.value = {0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_CRRR_A_CHA_status Rte_Buf_Runbl_IpmCanRx_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_EHB_A_CHA_status Rte_Buf_Runbl_IpmCanRx_20ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_FCM_B_CHA_status Rte_Buf_Runbl_IpmCanRx_20ms_IPM_FCM_B_CHA_IPM_FCM_B_CHA_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_SCS_RiSwitchSts_BOD_status Rte_Buf_Runbl_IpmCanRx_20ms_IPM_SCS_RiSwitchSts_BOD_IPM_SCS_RiSwitchSts_BOD_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_CCP_PanelStatus_BOD_status Rte_Buf_Runbl_IpmCanRx_50ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_ESCL_ESCLStatus_BOD_status Rte_Buf_Runbl_IpmCanRx_50ms_IPM_ESCL_ESCLStatus_BOD_IPM_ESCL_ESCLStatus_BOD_ibuffer = {.value = {0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_SCS_LeSwitchSts_BOD_status Rte_Buf_Runbl_IpmCanRx_50ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_SRS_1_Status_CHA_status Rte_Buf_Runbl_IpmCanRx_50ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA_ibuffer = {.value = {0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_CANCommCRCFlt_status Rte_Buf_Runbl_IpmMsgActv_10ms_CANCommCRCFlt_outputs_CANCommCRCFlt_outputs_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_CANCommErr_status Rte_Buf_Runbl_IpmMsgActv_10ms_CANCommErr_outputs_CANCommErr_outputs_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_MsgActv_status Rte_Buf_Runbl_IpmMsgActv_10ms_MsgActv_outputs_MsgActv_outputs_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_CONST_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
CONST(Rte_CDS_AppSwcIpm, RTE_CONST) Rte_Inst_AppSwcIpm =
{
    .Runbl_IpmCanRx_100ms_ACCM_Version_BOD_ACCM_Version_BOD = &Rte_Buf_Runbl_IpmCanRx_100ms_ACCM_Version_BOD_ACCM_Version_BOD_ibuffer,
    .Runbl_IpmCanRx_100ms_BMS_5_BatTemp_EPT_BMS_5_BatTemp_EPT = &Rte_Buf_Runbl_IpmCanRx_100ms_BMS_5_BatTemp_EPT_BMS_5_BatTemp_EPT_ibuffer,
    .Runbl_IpmCanRx_100ms_BMS_9_BattInfo_EPT_BMS_9_BattInfo_EPT = &Rte_Buf_Runbl_IpmCanRx_100ms_BMS_9_BattInfo_EPT_BMS_9_BattInfo_EPT_ibuffer,
    .Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD = &Rte_Buf_Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD_ibuffer,
    .Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC = &Rte_Buf_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC_ibuffer,
    .Runbl_IpmCanRx_100ms_HVCH_Status1_BOD_HVCH_Status1_BOD = &Rte_Buf_Runbl_IpmCanRx_100ms_HVCH_Status1_BOD_HVCH_Status1_BOD_ibuffer,
    .Runbl_IpmCanRx_100ms_HVCH_Status2_BOD_HVCH_Status2_BOD = &Rte_Buf_Runbl_IpmCanRx_100ms_HVCH_Status2_BOD_HVCH_Status2_BOD_ibuffer,
    .Runbl_IpmCanRx_100ms_INV_IMMO_Req_EPT_INV_IMMO_Req_EPT = &Rte_Buf_Runbl_IpmCanRx_100ms_INV_IMMO_Req_EPT_INV_IMMO_Req_EPT_ibuffer,
    .Runbl_IpmCanRx_100ms_IPU_DCC_1_State_EPT_IPU_DCC_1_State_EPT = &Rte_Buf_Runbl_IpmCanRx_100ms_IPU_DCC_1_State_EPT_IPU_DCC_1_State_EPT_ibuffer,
    .Runbl_IpmCanRx_100ms_IPU_DCC_2_ChrgInValue_EPT_IPU_DCC_2_ChrgInValue_EPT = &Rte_Buf_Runbl_IpmCanRx_100ms_IPU_DCC_2_ChrgInValue_EPT_IPU_DCC_2_ChrgInValue_EPT_ibuffer,
    .Runbl_IpmCanRx_100ms_IPU_OBC_1_State_EPT_IPU_OBC_1_State_EPT = &Rte_Buf_Runbl_IpmCanRx_100ms_IPU_OBC_1_State_EPT_IPU_OBC_1_State_EPT_ibuffer,
    .Runbl_IpmCanRx_100ms_IPU_OBC_2_Inlet_EPT_IPU_OBC_2_Inlet_EPT = &Rte_Buf_Runbl_IpmCanRx_100ms_IPU_OBC_2_Inlet_EPT_IPU_OBC_2_Inlet_EPT_ibuffer,
    .Runbl_IpmCanRx_100ms_TBOX_BJS_Time_BAC_TBOX_BJS_Time_BAC = &Rte_Buf_Runbl_IpmCanRx_100ms_TBOX_BJS_Time_BAC_TBOX_BJS_Time_BAC_ibuffer,
    .Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA = &Rte_Buf_Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_ibuffer,
    .Runbl_IpmCanRx_10ms_EPS_2_StrWhlAng_CHA_EPS_2_StrWhlAng_CHA = &Rte_Buf_Runbl_IpmCanRx_10ms_EPS_2_StrWhlAng_CHA_EPS_2_StrWhlAng_CHA_ibuffer,
    .Runbl_IpmCanRx_10ms_ESC_7_FuncStatus_CHA_ESC_7_FuncStatus_CHA = &Rte_Buf_Runbl_IpmCanRx_10ms_ESC_7_FuncStatus_CHA_ESC_7_FuncStatus_CHA_ibuffer,
    .Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA = &Rte_Buf_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ibuffer,
    .Runbl_IpmCanRx_10ms_INV_1_Value_EPT_INV_1_Value_EPT = &Rte_Buf_Runbl_IpmCanRx_10ms_INV_1_Value_EPT_INV_1_Value_EPT_ibuffer,
    .Runbl_IpmCanRx_10ms_INV_2_Value_EPT_INV_2_Value_EPT = &Rte_Buf_Runbl_IpmCanRx_10ms_INV_2_Value_EPT_INV_2_Value_EPT_ibuffer,
    .Runbl_IpmCanRx_10ms_INV_3_Value_EPT_INV_3_Value_EPT = &Rte_Buf_Runbl_IpmCanRx_10ms_INV_3_Value_EPT_INV_3_Value_EPT_ibuffer,
    .Runbl_IpmCanRx_10ms_INV_4_Value_EPT_INV_4_Value_EPT = &Rte_Buf_Runbl_IpmCanRx_10ms_INV_4_Value_EPT_INV_4_Value_EPT_ibuffer,
    .Runbl_IpmCanRx_20ms_BMS_10_DC_ChargeStates_EPT_BMS_10_DC_ChargeStates_EPT = &Rte_Buf_Runbl_IpmCanRx_20ms_BMS_10_DC_ChargeStates_EPT_BMS_10_DC_ChargeStates_EPT_ibuffer,
    .Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT = &Rte_Buf_Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT_ibuffer,
    .Runbl_IpmCanRx_20ms_BMS_2_BatState_EPT_BMS_2_BatState_EPT = &Rte_Buf_Runbl_IpmCanRx_20ms_BMS_2_BatState_EPT_BMS_2_BatState_EPT_ibuffer,
    .Runbl_IpmCanRx_20ms_BMS_3_DC_ChargeState_EPT_BMS_3_DC_ChargeState_EPT = &Rte_Buf_Runbl_IpmCanRx_20ms_BMS_3_DC_ChargeState_EPT_BMS_3_DC_ChargeState_EPT_ibuffer,
    .Runbl_IpmCanRx_20ms_BMS_4_AC_ChargeState_EPT_BMS_4_AC_ChargeState_EPT = &Rte_Buf_Runbl_IpmCanRx_20ms_BMS_4_AC_ChargeState_EPT_BMS_4_AC_ChargeState_EPT_ibuffer,
    .Runbl_IpmCanRx_20ms_BMS_6_DischrgRecup_EPT_BMS_6_DischrgRecup_EPT = &Rte_Buf_Runbl_IpmCanRx_20ms_BMS_6_DischrgRecup_EPT_BMS_6_DischrgRecup_EPT_ibuffer,
    .Runbl_IpmCanRx_20ms_BMS_7_CellVolt_EPT_BMS_7_CellVolt_EPT = &Rte_Buf_Runbl_IpmCanRx_20ms_BMS_7_CellVolt_EPT_BMS_7_CellVolt_EPT_ibuffer,
    .Runbl_IpmCanRx_20ms_CRRR_A_CHA_CRRR_A_CHA = &Rte_Buf_Runbl_IpmCanRx_20ms_CRRR_A_CHA_CRRR_A_CHA_ibuffer,
    .Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA = &Rte_Buf_Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_ibuffer,
    .Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA = &Rte_Buf_Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ibuffer,
    .Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD = &Rte_Buf_Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD_ibuffer,
    .Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD = &Rte_Buf_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD_ibuffer,
    .Runbl_IpmCanRx_50ms_ESCL_ESCLStatus_BOD_ESCL_ESCLStatus_BOD = &Rte_Buf_Runbl_IpmCanRx_50ms_ESCL_ESCLStatus_BOD_ESCL_ESCLStatus_BOD_ibuffer,
    .Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD = &Rte_Buf_Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD_ibuffer,
    .Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA = &Rte_Buf_Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA_ibuffer,
    .Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs = &Rte_Buf_Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs_ibuffer,
    .Runbl_IpmCanRx_100ms_IPM_ACCM_Version_BOD_IPM_ACCM_Version_BOD = &Rte_Buf_Runbl_IpmCanRx_100ms_IPM_ACCM_Version_BOD_IPM_ACCM_Version_BOD_ibuffer,
    .Runbl_IpmCanRx_100ms_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT = &Rte_Buf_Runbl_IpmCanRx_100ms_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT_ibuffer,
    .Runbl_IpmCanRx_100ms_IPM_BMS_9_BattInfo_EPT_IPM_BMS_9_BattInfo_EPT = &Rte_Buf_Runbl_IpmCanRx_100ms_IPM_BMS_9_BattInfo_EPT_IPM_BMS_9_BattInfo_EPT_ibuffer,
    .Runbl_IpmCanRx_100ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD = &Rte_Buf_Runbl_IpmCanRx_100ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD_ibuffer,
    .Runbl_IpmCanRx_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC = &Rte_Buf_Runbl_IpmCanRx_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC_ibuffer,
    .Runbl_IpmCanRx_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD = &Rte_Buf_Runbl_IpmCanRx_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD_ibuffer,
    .Runbl_IpmCanRx_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD = &Rte_Buf_Runbl_IpmCanRx_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD_ibuffer,
    .Runbl_IpmCanRx_100ms_IPM_INV_IMMO_Req_EPT_IPM_INV_IMMO_Req_EPT = &Rte_Buf_Runbl_IpmCanRx_100ms_IPM_INV_IMMO_Req_EPT_IPM_INV_IMMO_Req_EPT_ibuffer,
    .Runbl_IpmCanRx_100ms_IPM_IPU_DCC_1_State_EPT_IPM_IPU_DCC_1_State_EPT = &Rte_Buf_Runbl_IpmCanRx_100ms_IPM_IPU_DCC_1_State_EPT_IPM_IPU_DCC_1_State_EPT_ibuffer,
    .Runbl_IpmCanRx_100ms_IPM_IPU_DCC_2_ChrgInValue_EPT_IPM_IPU_DCC_2_ChrgInValue_EPT = &Rte_Buf_Runbl_IpmCanRx_100ms_IPM_IPU_DCC_2_ChrgInValue_EPT_IPM_IPU_DCC_2_ChrgInValue_EPT_ibuffer,
    .Runbl_IpmCanRx_100ms_IPM_IPU_OBC_1_State_EPT_IPM_IPU_OBC_1_State_EPT = &Rte_Buf_Runbl_IpmCanRx_100ms_IPM_IPU_OBC_1_State_EPT_IPM_IPU_OBC_1_State_EPT_ibuffer,
    .Runbl_IpmCanRx_100ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT = &Rte_Buf_Runbl_IpmCanRx_100ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT_ibuffer,
    .Runbl_IpmCanRx_100ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC = &Rte_Buf_Runbl_IpmCanRx_100ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC_ibuffer,
    .Runbl_IpmCanRx_10ms_IPM_EHB_B_CHA_IPM_EHB_B_CHA = &Rte_Buf_Runbl_IpmCanRx_10ms_IPM_EHB_B_CHA_IPM_EHB_B_CHA_ibuffer,
    .Runbl_IpmCanRx_10ms_IPM_EPS_2_StrWhlAng_CHA_IPM_EPS_2_StrWhlAng_CHA = &Rte_Buf_Runbl_IpmCanRx_10ms_IPM_EPS_2_StrWhlAng_CHA_IPM_EPS_2_StrWhlAng_CHA_ibuffer,
    .Runbl_IpmCanRx_10ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA = &Rte_Buf_Runbl_IpmCanRx_10ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA_ibuffer,
    .Runbl_IpmCanRx_10ms_IPM_ESC_A_CHA_IPM_ESC_A_CHA = &Rte_Buf_Runbl_IpmCanRx_10ms_IPM_ESC_A_CHA_IPM_ESC_A_CHA_ibuffer,
    .Runbl_IpmCanRx_10ms_IPM_INV_1_Value_EPT_IPM_INV_1_Value_EPT = &Rte_Buf_Runbl_IpmCanRx_10ms_IPM_INV_1_Value_EPT_IPM_INV_1_Value_EPT_ibuffer,
    .Runbl_IpmCanRx_10ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT = &Rte_Buf_Runbl_IpmCanRx_10ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT_ibuffer,
    .Runbl_IpmCanRx_10ms_IPM_INV_3_Value_EPT_IPM_INV_3_Value_EPT = &Rte_Buf_Runbl_IpmCanRx_10ms_IPM_INV_3_Value_EPT_IPM_INV_3_Value_EPT_ibuffer,
    .Runbl_IpmCanRx_10ms_IPM_INV_4_Value_EPT_IPM_INV_4_Value_EPT = &Rte_Buf_Runbl_IpmCanRx_10ms_IPM_INV_4_Value_EPT_IPM_INV_4_Value_EPT_ibuffer,
    .Runbl_IpmCanRx_20ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT = &Rte_Buf_Runbl_IpmCanRx_20ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT_ibuffer,
    .Runbl_IpmCanRx_20ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT = &Rte_Buf_Runbl_IpmCanRx_20ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT_ibuffer,
    .Runbl_IpmCanRx_20ms_IPM_BMS_2_BatState_EPT_IPM_BMS_2_BatState_EPT = &Rte_Buf_Runbl_IpmCanRx_20ms_IPM_BMS_2_BatState_EPT_IPM_BMS_2_BatState_EPT_ibuffer,
    .Runbl_IpmCanRx_20ms_IPM_BMS_3_DC_ChargeState_EPT_IPM_BMS_3_DC_ChargeState_EPT = &Rte_Buf_Runbl_IpmCanRx_20ms_IPM_BMS_3_DC_ChargeState_EPT_IPM_BMS_3_DC_ChargeState_EPT_ibuffer,
    .Runbl_IpmCanRx_20ms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT = &Rte_Buf_Runbl_IpmCanRx_20ms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT_ibuffer,
    .Runbl_IpmCanRx_20ms_IPM_BMS_6_DischrgRecup_EPT_IPM_BMS_6_DischrgRecup_EPT = &Rte_Buf_Runbl_IpmCanRx_20ms_IPM_BMS_6_DischrgRecup_EPT_IPM_BMS_6_DischrgRecup_EPT_ibuffer,
    .Runbl_IpmCanRx_20ms_IPM_BMS_7_CellVolt_EPT_IPM_BMS_7_CellVolt_EPT = &Rte_Buf_Runbl_IpmCanRx_20ms_IPM_BMS_7_CellVolt_EPT_IPM_BMS_7_CellVolt_EPT_ibuffer,
    .Runbl_IpmCanRx_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA = &Rte_Buf_Runbl_IpmCanRx_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA_ibuffer,
    .Runbl_IpmCanRx_20ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA = &Rte_Buf_Runbl_IpmCanRx_20ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA_ibuffer,
    .Runbl_IpmCanRx_20ms_IPM_FCM_B_CHA_IPM_FCM_B_CHA = &Rte_Buf_Runbl_IpmCanRx_20ms_IPM_FCM_B_CHA_IPM_FCM_B_CHA_ibuffer,
    .Runbl_IpmCanRx_20ms_IPM_SCS_RiSwitchSts_BOD_IPM_SCS_RiSwitchSts_BOD = &Rte_Buf_Runbl_IpmCanRx_20ms_IPM_SCS_RiSwitchSts_BOD_IPM_SCS_RiSwitchSts_BOD_ibuffer,
    .Runbl_IpmCanRx_50ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD = &Rte_Buf_Runbl_IpmCanRx_50ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD_ibuffer,
    .Runbl_IpmCanRx_50ms_IPM_ESCL_ESCLStatus_BOD_IPM_ESCL_ESCLStatus_BOD = &Rte_Buf_Runbl_IpmCanRx_50ms_IPM_ESCL_ESCLStatus_BOD_IPM_ESCL_ESCLStatus_BOD_ibuffer,
    .Runbl_IpmCanRx_50ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD = &Rte_Buf_Runbl_IpmCanRx_50ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD_ibuffer,
    .Runbl_IpmCanRx_50ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA = &Rte_Buf_Runbl_IpmCanRx_50ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA_ibuffer,
    .Runbl_IpmMsgActv_10ms_CANCommCRCFlt_outputs_CANCommCRCFlt_outputs = &Rte_Buf_Runbl_IpmMsgActv_10ms_CANCommCRCFlt_outputs_CANCommCRCFlt_outputs_ibuffer,
    .Runbl_IpmMsgActv_10ms_CANCommErr_outputs_CANCommErr_outputs = &Rte_Buf_Runbl_IpmMsgActv_10ms_CANCommErr_outputs_CANCommErr_outputs_ibuffer,
    .Runbl_IpmMsgActv_10ms_MsgActv_outputs_MsgActv_outputs = &Rte_Buf_Runbl_IpmMsgActv_10ms_MsgActv_outputs_MsgActv_outputs_ibuffer,
};
#define RTE_STOP_SEC_CONST_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_Bcm2OpmEPT_outputs_status Rte_Buf_Runbl_OpmCanTx_100ms_Bcm2OpmEPT_outputs_Bcm2OpmEPT_outputs_ibuffer = {.value = {0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_Bcm2OpmOBD_outputs_status Rte_Buf_Runbl_OpmCanTx_100ms_Bcm2OpmOBD_outputs_Bcm2OpmOBD_outputs_ibuffer = {.value = {0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_TMS2VCU_AC_1_Command_Outputs_status Rte_Buf_Runbl_OpmCanTx_100ms_TMS2VCU_AC_1_Command_Outputs_TMS2VCU_AC_1_Command_Outputs_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_TMS2VCU_AC_2_State_Outputs_status Rte_Buf_Runbl_OpmCanTx_100ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_TMS2VCU_AC_3_State_Outputs_status Rte_Buf_Runbl_OpmCanTx_100ms_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_TMS2VCU_AC_8_status_Outputs_status Rte_Buf_Runbl_OpmCanTx_100ms_TMS2VCU_AC_8_status_Outputs_TMS2VCU_AC_8_status_Outputs_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_TMS2VCU_AC_ACStatuts_Outputs_status Rte_Buf_Runbl_OpmCanTx_100ms_TMS2VCU_AC_ACStatuts_Outputs_TMS2VCU_AC_ACStatuts_Outputs_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_TMS2VCU_AC_COMP_Outputs_status Rte_Buf_Runbl_OpmCanTx_100ms_TMS2VCU_AC_COMP_Outputs_TMS2VCU_AC_COMP_Outputs_ibuffer = {.value = {0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_TMS2VCU_HVCH_Command_Outputs_status Rte_Buf_Runbl_OpmCanTx_100ms_TMS2VCU_HVCH_Command_Outputs_TMS2VCU_HVCH_Command_Outputs_ibuffer = {.value = {0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_TMS2VCU_TMS_LINTestData1_Outputs_status Rte_Buf_Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData1_Outputs_TMS2VCU_TMS_LINTestData1_Outputs_ibuffer = {.value = {0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_TMS2VCU_TMS_LINTestData2_Outputs_status Rte_Buf_Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData2_Outputs_TMS2VCU_TMS_LINTestData2_Outputs_ibuffer = {.value = {0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_TMS2VCU_TMS_LINTestData3_Outputs_status Rte_Buf_Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData3_Outputs_TMS2VCU_TMS_LINTestData3_Outputs_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_FCM_B_CHA_status Rte_Buf_Runbl_OpmCanTx_10ms_IPM_FCM_B_CHA_IPM_FCM_B_CHA_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_INV_1_Value_EPT_status Rte_Buf_Runbl_OpmCanTx_10ms_IPM_INV_1_Value_EPT_IPM_INV_1_Value_EPT_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_Bcm2OpmBAC_outputs_status Rte_Buf_Runbl_OpmRx_10ms_Bcm2OpmBAC_outputs_Bcm2OpmBAC_outputs_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_TMS2VCU_PPVAddSignalGroup_Outputs_status Rte_Buf_Runbl_OpmRx_10ms_TMS2VCU_PPV_outputs_TMS2VCU_PPV_outputs_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_Vcu2OpmBAC_outputs_status Rte_Buf_Runbl_OpmRx_10ms_Vcu2OpmBAC_outputs_Vcu2OpmBAC_outputs_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_Vcu2OpmCHA_outputs_status Rte_Buf_Runbl_OpmRx_10ms_Vcu2OpmCHA_outputs_Vcu2OpmCHA_outputs_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_Vcu2OpmEPT_outputs_status Rte_Buf_Runbl_OpmRx_10ms_Vcu2OpmEPT_outputs_Vcu2OpmEPT_outputs_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_AC_1_Command_BOD_status Rte_Buf_Runbl_OpmCanTx_100ms_AC_1_Command_BOD_AC_1_Command_BOD_ibuffer = {.value = {0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_AC_2_State_BOD_status Rte_Buf_Runbl_OpmCanTx_100ms_AC_2_State_BOD_AC_2_State_BOD_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_AC_3_State_BOD_status Rte_Buf_Runbl_OpmCanTx_100ms_AC_3_State_BOD_AC_3_State_BOD_ibuffer = {.value = {0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_AC_8_status_BOD_status Rte_Buf_Runbl_OpmCanTx_100ms_AC_8_status_BOD_AC_8_status_BOD_ibuffer = {.value = {0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_AC_ACStatuts_BOD_status Rte_Buf_Runbl_OpmCanTx_100ms_AC_ACStatuts_BOD_AC_ACStatuts_BOD_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_AC_COMP_BOD_status Rte_Buf_Runbl_OpmCanTx_100ms_AC_COMP_BOD_AC_COMP_BOD_ibuffer = {.value = {0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_BCM_ESCLCommand_BOD_status Rte_Buf_Runbl_OpmCanTx_100ms_BCM_ESCLCommand_BOD_BCM_ESCLCommand_BOD_ibuffer = {.value = {0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_BCM_HFSData_BAC_status Rte_Buf_Runbl_OpmCanTx_100ms_BCM_HFSData_BAC_BCM_HFSData_BAC_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_BCM_IMMOAuthResp1_EPT_status Rte_Buf_Runbl_OpmCanTx_100ms_BCM_IMMOAuthResp1_EPT_BCM_IMMOAuthResp1_EPT_ibuffer = {.value = {0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_HVCH_Command_BOD_status Rte_Buf_Runbl_OpmCanTx_100ms_HVCH_Command_BOD_HVCH_Command_BOD_ibuffer = {.value = {0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_TMS_LINTestData1_BOD_status Rte_Buf_Runbl_OpmCanTx_100ms_TMS_LINTestData1_BOD_TMS_LINTestData1_BOD_ibuffer = {.value = {0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_TMS_LINTestData2_BOD_status Rte_Buf_Runbl_OpmCanTx_100ms_TMS_LINTestData2_BOD_TMS_LINTestData2_BOD_ibuffer = {.value = {0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_TMS_LINTestData3_BOD_status Rte_Buf_Runbl_OpmCanTx_100ms_TMS_LINTestData3_BOD_TMS_LINTestData3_BOD_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_VCU_0_Value_EPT_status Rte_Buf_Runbl_OpmCanTx_10ms_VCU_0_Value_EPT_VCU_0_Value_EPT_ibuffer = {.value = {0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_VCU_10_Torque_CHA_status Rte_Buf_Runbl_OpmCanTx_10ms_VCU_10_Torque_CHA_VCU_10_Torque_CHA_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_VCU_1_InvCmd_EPT_status Rte_Buf_Runbl_OpmCanTx_10ms_VCU_1_InvCmd_EPT_VCU_1_InvCmd_EPT_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_VCU_3_OprtCmd_EPT_status Rte_Buf_Runbl_OpmCanTx_20ms_VCU_3_OprtCmd_EPT_VCU_3_OprtCmd_EPT_ibuffer = {.value = {0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_VCU_4_ChrgCmd_EPT_status Rte_Buf_Runbl_OpmCanTx_20ms_VCU_4_ChrgCmd_EPT_VCU_4_ChrgCmd_EPT_ibuffer = {.value = {0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_VCU_B_AcclPedal_EPT_status Rte_Buf_Runbl_OpmCanTx_20ms_VCU_B_AcclPedal_EPT_VCU_B_AcclPedal_EPT_ibuffer = {.value = {0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_VCU_C_OprtCmd_EPT_status Rte_Buf_Runbl_OpmCanTx_20ms_VCU_C_OprtCmd_EPT_VCU_C_OprtCmd_EPT_ibuffer = {.value = {0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_VCU_D_Status_CHA_status Rte_Buf_Runbl_OpmCanTx_20ms_VCU_D_Status_CHA_VCU_D_Status_CHA_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_VCU_DispInfo_BAC_status Rte_Buf_Runbl_OpmCanTx_20ms_VCU_DispInfo_BAC_VCU_DispInfo_BAC_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_BCM_B_Package_BAC_status Rte_Buf_Runbl_OpmCanTx_50ms_BCM_B_Package_BAC_BCM_B_Package_BAC_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_CCU_VehInfo_BAC_status Rte_Buf_Runbl_OpmCanTx_50ms_CCU_VehInfo_BAC_CCU_VehInfo_BAC_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_CONST_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
CONST(Rte_CDS_AppSwcOpm, RTE_CONST) Rte_Inst_AppSwcOpm =
{
    .Runbl_OpmCanTx_100ms_Bcm2OpmEPT_outputs_Bcm2OpmEPT_outputs = &Rte_Buf_Runbl_OpmCanTx_100ms_Bcm2OpmEPT_outputs_Bcm2OpmEPT_outputs_ibuffer,
    .Runbl_OpmCanTx_100ms_Bcm2OpmOBD_outputs_Bcm2OpmOBD_outputs = &Rte_Buf_Runbl_OpmCanTx_100ms_Bcm2OpmOBD_outputs_Bcm2OpmOBD_outputs_ibuffer,
    .Runbl_OpmCanTx_100ms_TMS2VCU_AC_1_Command_Outputs_TMS2VCU_AC_1_Command_Outputs = &Rte_Buf_Runbl_OpmCanTx_100ms_TMS2VCU_AC_1_Command_Outputs_TMS2VCU_AC_1_Command_Outputs_ibuffer,
    .Runbl_OpmCanTx_100ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs = &Rte_Buf_Runbl_OpmCanTx_100ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs_ibuffer,
    .Runbl_OpmCanTx_100ms_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs = &Rte_Buf_Runbl_OpmCanTx_100ms_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs_ibuffer,
    .Runbl_OpmCanTx_100ms_TMS2VCU_AC_8_status_Outputs_TMS2VCU_AC_8_status_Outputs = &Rte_Buf_Runbl_OpmCanTx_100ms_TMS2VCU_AC_8_status_Outputs_TMS2VCU_AC_8_status_Outputs_ibuffer,
    .Runbl_OpmCanTx_100ms_TMS2VCU_AC_ACStatuts_Outputs_TMS2VCU_AC_ACStatuts_Outputs = &Rte_Buf_Runbl_OpmCanTx_100ms_TMS2VCU_AC_ACStatuts_Outputs_TMS2VCU_AC_ACStatuts_Outputs_ibuffer,
    .Runbl_OpmCanTx_100ms_TMS2VCU_AC_COMP_Outputs_TMS2VCU_AC_COMP_Outputs = &Rte_Buf_Runbl_OpmCanTx_100ms_TMS2VCU_AC_COMP_Outputs_TMS2VCU_AC_COMP_Outputs_ibuffer,
    .Runbl_OpmCanTx_100ms_TMS2VCU_HVCH_Command_Outputs_TMS2VCU_HVCH_Command_Outputs = &Rte_Buf_Runbl_OpmCanTx_100ms_TMS2VCU_HVCH_Command_Outputs_TMS2VCU_HVCH_Command_Outputs_ibuffer,
    .Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData1_Outputs_TMS2VCU_TMS_LINTestData1_Outputs = &Rte_Buf_Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData1_Outputs_TMS2VCU_TMS_LINTestData1_Outputs_ibuffer,
    .Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData2_Outputs_TMS2VCU_TMS_LINTestData2_Outputs = &Rte_Buf_Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData2_Outputs_TMS2VCU_TMS_LINTestData2_Outputs_ibuffer,
    .Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData3_Outputs_TMS2VCU_TMS_LINTestData3_Outputs = &Rte_Buf_Runbl_OpmCanTx_100ms_TMS2VCU_TMS_LINTestData3_Outputs_TMS2VCU_TMS_LINTestData3_Outputs_ibuffer,
    .Runbl_OpmCanTx_10ms_IPM_FCM_B_CHA_IPM_FCM_B_CHA = &Rte_Buf_Runbl_OpmCanTx_10ms_IPM_FCM_B_CHA_IPM_FCM_B_CHA_ibuffer,
    .Runbl_OpmCanTx_10ms_IPM_INV_1_Value_EPT_IPM_INV_1_Value_EPT = &Rte_Buf_Runbl_OpmCanTx_10ms_IPM_INV_1_Value_EPT_IPM_INV_1_Value_EPT_ibuffer,
    .Runbl_OpmRx_10ms_Bcm2OpmBAC_outputs_Bcm2OpmBAC_outputs = &Rte_Buf_Runbl_OpmRx_10ms_Bcm2OpmBAC_outputs_Bcm2OpmBAC_outputs_ibuffer,
    .Runbl_OpmRx_10ms_TMS2VCU_PPV_outputs_TMS2VCU_PPV_outputs = &Rte_Buf_Runbl_OpmRx_10ms_TMS2VCU_PPV_outputs_TMS2VCU_PPV_outputs_ibuffer,
    .Runbl_OpmRx_10ms_Vcu2OpmBAC_outputs_Vcu2OpmBAC_outputs = &Rte_Buf_Runbl_OpmRx_10ms_Vcu2OpmBAC_outputs_Vcu2OpmBAC_outputs_ibuffer,
    .Runbl_OpmRx_10ms_Vcu2OpmCHA_outputs_Vcu2OpmCHA_outputs = &Rte_Buf_Runbl_OpmRx_10ms_Vcu2OpmCHA_outputs_Vcu2OpmCHA_outputs_ibuffer,
    .Runbl_OpmRx_10ms_Vcu2OpmEPT_outputs_Vcu2OpmEPT_outputs = &Rte_Buf_Runbl_OpmRx_10ms_Vcu2OpmEPT_outputs_Vcu2OpmEPT_outputs_ibuffer,
    .Runbl_OpmCanTx_100ms_AC_1_Command_BOD_AC_1_Command_BOD = &Rte_Buf_Runbl_OpmCanTx_100ms_AC_1_Command_BOD_AC_1_Command_BOD_ibuffer,
    .Runbl_OpmCanTx_100ms_AC_2_State_BOD_AC_2_State_BOD = &Rte_Buf_Runbl_OpmCanTx_100ms_AC_2_State_BOD_AC_2_State_BOD_ibuffer,
    .Runbl_OpmCanTx_100ms_AC_3_State_BOD_AC_3_State_BOD = &Rte_Buf_Runbl_OpmCanTx_100ms_AC_3_State_BOD_AC_3_State_BOD_ibuffer,
    .Runbl_OpmCanTx_100ms_AC_8_status_BOD_AC_8_status_BOD = &Rte_Buf_Runbl_OpmCanTx_100ms_AC_8_status_BOD_AC_8_status_BOD_ibuffer,
    .Runbl_OpmCanTx_100ms_AC_ACStatuts_BOD_AC_ACStatuts_BOD = &Rte_Buf_Runbl_OpmCanTx_100ms_AC_ACStatuts_BOD_AC_ACStatuts_BOD_ibuffer,
    .Runbl_OpmCanTx_100ms_AC_COMP_BOD_AC_COMP_BOD = &Rte_Buf_Runbl_OpmCanTx_100ms_AC_COMP_BOD_AC_COMP_BOD_ibuffer,
    .Runbl_OpmCanTx_100ms_BCM_ESCLCommand_BOD_BCM_ESCLCommand_BOD = &Rte_Buf_Runbl_OpmCanTx_100ms_BCM_ESCLCommand_BOD_BCM_ESCLCommand_BOD_ibuffer,
    .Runbl_OpmCanTx_100ms_BCM_HFSData_BAC_BCM_HFSData_BAC = &Rte_Buf_Runbl_OpmCanTx_100ms_BCM_HFSData_BAC_BCM_HFSData_BAC_ibuffer,
    .Runbl_OpmCanTx_100ms_BCM_IMMOAuthResp1_EPT_BCM_IMMOAuthResp1_EPT = &Rte_Buf_Runbl_OpmCanTx_100ms_BCM_IMMOAuthResp1_EPT_BCM_IMMOAuthResp1_EPT_ibuffer,
    .Runbl_OpmCanTx_100ms_HVCH_Command_BOD_HVCH_Command_BOD = &Rte_Buf_Runbl_OpmCanTx_100ms_HVCH_Command_BOD_HVCH_Command_BOD_ibuffer,
    .Runbl_OpmCanTx_100ms_TMS_LINTestData1_BOD_TMS_LINTestData1_BOD = &Rte_Buf_Runbl_OpmCanTx_100ms_TMS_LINTestData1_BOD_TMS_LINTestData1_BOD_ibuffer,
    .Runbl_OpmCanTx_100ms_TMS_LINTestData2_BOD_TMS_LINTestData2_BOD = &Rte_Buf_Runbl_OpmCanTx_100ms_TMS_LINTestData2_BOD_TMS_LINTestData2_BOD_ibuffer,
    .Runbl_OpmCanTx_100ms_TMS_LINTestData3_BOD_TMS_LINTestData3_BOD = &Rte_Buf_Runbl_OpmCanTx_100ms_TMS_LINTestData3_BOD_TMS_LINTestData3_BOD_ibuffer,
    .Runbl_OpmCanTx_10ms_VCU_0_Value_EPT_VCU_0_Value_EPT = &Rte_Buf_Runbl_OpmCanTx_10ms_VCU_0_Value_EPT_VCU_0_Value_EPT_ibuffer,
    .Runbl_OpmCanTx_10ms_VCU_10_Torque_CHA_VCU_10_Torque_CHA = &Rte_Buf_Runbl_OpmCanTx_10ms_VCU_10_Torque_CHA_VCU_10_Torque_CHA_ibuffer,
    .Runbl_OpmCanTx_10ms_VCU_1_InvCmd_EPT_VCU_1_InvCmd_EPT = &Rte_Buf_Runbl_OpmCanTx_10ms_VCU_1_InvCmd_EPT_VCU_1_InvCmd_EPT_ibuffer,
    .Runbl_OpmCanTx_20ms_VCU_3_OprtCmd_EPT_VCU_3_OprtCmd_EPT = &Rte_Buf_Runbl_OpmCanTx_20ms_VCU_3_OprtCmd_EPT_VCU_3_OprtCmd_EPT_ibuffer,
    .Runbl_OpmCanTx_20ms_VCU_4_ChrgCmd_EPT_VCU_4_ChrgCmd_EPT = &Rte_Buf_Runbl_OpmCanTx_20ms_VCU_4_ChrgCmd_EPT_VCU_4_ChrgCmd_EPT_ibuffer,
    .Runbl_OpmCanTx_20ms_VCU_B_AcclPedal_EPT_VCU_B_AcclPedal_EPT = &Rte_Buf_Runbl_OpmCanTx_20ms_VCU_B_AcclPedal_EPT_VCU_B_AcclPedal_EPT_ibuffer,
    .Runbl_OpmCanTx_20ms_VCU_C_OprtCmd_EPT_VCU_C_OprtCmd_EPT = &Rte_Buf_Runbl_OpmCanTx_20ms_VCU_C_OprtCmd_EPT_VCU_C_OprtCmd_EPT_ibuffer,
    .Runbl_OpmCanTx_20ms_VCU_D_Status_CHA_VCU_D_Status_CHA = &Rte_Buf_Runbl_OpmCanTx_20ms_VCU_D_Status_CHA_VCU_D_Status_CHA_ibuffer,
    .Runbl_OpmCanTx_20ms_VCU_DispInfo_BAC_VCU_DispInfo_BAC = &Rte_Buf_Runbl_OpmCanTx_20ms_VCU_DispInfo_BAC_VCU_DispInfo_BAC_ibuffer,
    .Runbl_OpmCanTx_50ms_BCM_B_Package_BAC_BCM_B_Package_BAC = &Rte_Buf_Runbl_OpmCanTx_50ms_BCM_B_Package_BAC_BCM_B_Package_BAC_ibuffer,
    .Runbl_OpmCanTx_50ms_CCU_VehInfo_BAC_CCU_VehInfo_BAC = &Rte_Buf_Runbl_OpmCanTx_50ms_CCU_VehInfo_BAC_CCU_VehInfo_BAC_ibuffer,
};
#define RTE_STOP_SEC_CONST_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_AcPMP_HWVersion_AcPMP_HWVersion_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_AcPMP_PartNumber_AcPMP_PartNumber_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_AcPMP_ProjectCode1_AcPMP_ProjectCode1_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_AcPMP_ProjectCode2_AcPMP_ProjectCode2_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_Boolean_status Rte_Buf_Task_100ms_AcPMP_PumpDryRunningSta_AcPMP_PumpDryRunningSta_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_AcPMP_PumpInputVolt_AcPMP_PumpInputVolt_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_AcPMP_PumpMotorSta_AcPMP_PumpMotorSta_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_AcPMP_PumpPowerSta_AcPMP_PumpPowerSta_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_AcPMP_PumpTempSta_AcPMP_PumpTempSta_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_Boolean_status Rte_Buf_Task_100ms_AcPMP_RESP_ERROR_AcPMP_RESP_ERROR_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_AcPMP_RealRPM_AcPMP_RealRPM_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_AcPMP_SWVersion_Main_AcPMP_SWVersion_Main_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_AcPMP_SWVersion_Patch_AcPMP_SWVersion_Patch_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_AcPMP_SWVersion_Sub_AcPMP_SWVersion_Sub_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_AcPMP_SupplierNumber_AcPMP_SupplierNumber_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt16_status Rte_Buf_Task_100ms_BAT_EXV_CurrentPosition_B_BAT_EXV_CurrentPosition_B_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_BAT_EXV_FaultState_B_BAT_EXV_FaultState_B_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_Boolean_status Rte_Buf_Task_100ms_BAT_EXV_ResponseError_B_BAT_EXV_ResponseError_B_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_Boolean_status Rte_Buf_Task_100ms_BAT_EXV_RunState_B_BAT_EXV_RunState_B_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_Boolean_status Rte_Buf_Task_100ms_BAT_EXV_SupplierLabel_BAT_EXV_SupplierLabel_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_BAT_EXV_VoltageState_B_BAT_EXV_VoltageState_B_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_Boolean_status Rte_Buf_Task_100ms_BAT_EXV_Warning_OverTemp_BAT_EXV_Warning_OverTemp_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_BAT_EXV_initialize_status_BAT_EXV_initialize_status_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_Boolean_status Rte_Buf_Task_100ms_BatPMP_PumpDryRunningSta_BatPMP_PumpDryRunningSta_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_BatPMP_PumpInputVolt_BatPMP_PumpInputVolt_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_BatPMP_PumpMotorSta_BatPMP_PumpMotorSta_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_BatPMP_PumpPowerSta_BatPMP_PumpPowerSta_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_BatPMP_PumpTempSta_BatPMP_PumpTempSta_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_Boolean_status Rte_Buf_Task_100ms_BatPMP_RESP_ERROR_BatPMP_RESP_ERROR_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_BatPMP_RealRPM_BatPMP_RealRPM_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_Bat_EXV_HWVersion_Bat_EXV_HWVersion_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_Bat_EXV_PartNumber_Bat_EXV_PartNumber_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_Bat_EXV_ProjectCode1_Bat_EXV_ProjectCode1_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_Bat_EXV_ProjectCode2_Bat_EXV_ProjectCode2_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_Bat_EXV_SWVersion_Main_Bat_EXV_SWVersion_Main_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_Bat_EXV_SWVersion_Patch_Bat_EXV_SWVersion_Patch_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_Bat_EXV_SWVersion_Sub_Bat_EXV_SWVersion_Sub_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_Bat_EXV_SupplierNumber_Bat_EXV_SupplierNumber_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_Bcm2VcuTms_outputs_status Rte_Buf_Task_100ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_Boolean_status Rte_Buf_Task_100ms_C3WV_ErrResp_C3WV_ErrResp_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_C3WV_FltSts_C3WV_FltSts_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_C3WV_Mode_C3WV_Mode_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt16_status Rte_Buf_Task_100ms_C3WV_PosRec_C3WV_PosRec_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_Boolean_status Rte_Buf_Task_100ms_C3WV_RunSts_C3WV_RunSts_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_C3WV_SpdLvl_C3WV_SpdLvl_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_C3WV_TempSts_C3WV_TempSts_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_C3WV_VoltSts_C3WV_VoltSts_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_C5WVFltSts_C5WVFltSts_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_C5WVMode_C5WVMode_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt16_status Rte_Buf_Task_100ms_C5WVPosRec_C5WVPosRec_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_Boolean_status Rte_Buf_Task_100ms_C5WVRunSts_C5WVRunSts_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_C5WVSpdLvl_C5WVSpdLvl_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_C5WVTempSts_C5WVTempSts_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_C5WVVoltSts_C5WVVoltSts_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_EXV_CurrentInitState_EXV_CurrentInitState_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt16_status Rte_Buf_Task_100ms_EXV_CurrentPosition_EXV_CurrentPosition_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_EXV_FaultState_EXV_FaultState_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_Boolean_status Rte_Buf_Task_100ms_EXV_ResponseError_EXV_ResponseError_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_Boolean_status Rte_Buf_Task_100ms_EXV_RunState_EXV_RunState_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_EXV_TemperatureWarn_EXV_TemperatureWarn_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_EXV_VoltageState_EXV_VoltageState_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_Boolean_status Rte_Buf_Task_100ms_ErrRespC5WV_ErrRespC5WV_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt16_status Rte_Buf_Task_100ms_HP_EXV_CurrentPosition_B_HP_EXV_CurrentPosition_B_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_HP_EXV_FaultState_B_HP_EXV_FaultState_B_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_HP_EXV_HWVersion_HP_EXV_HWVersion_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_HP_EXV_PartNumber_HP_EXV_PartNumber_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_HP_EXV_ProjectCode1_HP_EXV_ProjectCode1_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_HP_EXV_ProjectCode2_HP_EXV_ProjectCode2_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_Boolean_status Rte_Buf_Task_100ms_HP_EXV_ResponseError_B_HP_EXV_ResponseError_B_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_Boolean_status Rte_Buf_Task_100ms_HP_EXV_RunState_B_HP_EXV_RunState_B_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_HP_EXV_SWVersion_Main_HP_EXV_SWVersion_Main_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_HP_EXV_SWVersion_Patch_HP_EXV_SWVersion_Patch_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_HP_EXV_SWVersion_Sub_HP_EXV_SWVersion_Sub_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_Boolean_status Rte_Buf_Task_100ms_HP_EXV_SupplierLabel_HP_EXV_SupplierLabel_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_HP_EXV_SupplierNumber_HP_EXV_SupplierNumber_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_HP_EXV_VoltageState_B_HP_EXV_VoltageState_B_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_Boolean_status Rte_Buf_Task_100ms_HP_EXV_Warning_OverTemp_HP_EXV_Warning_OverTemp_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_HP_EXV_initialize_status_HP_EXV_initialize_status_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_BMS_10_DC_ChargeStates_EPT_status Rte_Buf_Task_100ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT_ibuffer = {.value = {0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_BMS_2_BatState_EPT_status Rte_Buf_Task_100ms_IPM_BMS_2_BatState_EPT_IPM_BMS_2_BatState_EPT_ibuffer = {.value = {0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_BMS_4_AC_ChargeState_EPT_status Rte_Buf_Task_100ms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_BMS_5_BatTemp_EPT_status Rte_Buf_Task_100ms_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT_ibuffer = {.value = {0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_CCP_PanelStatus_BOD_status Rte_Buf_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_COMP_AC_BOD_status Rte_Buf_Task_100ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_ESC_7_FuncStatus_CHA_status Rte_Buf_Task_100ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_HU_B_BAC_status Rte_Buf_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_HVCH_Status1_BOD_status Rte_Buf_Task_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_HVCH_Status2_BOD_status Rte_Buf_Task_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_INV_2_Value_EPT_status Rte_Buf_Task_100ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT_ibuffer = {.value = {0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_IPU_OBC_2_Inlet_EPT_status Rte_Buf_Task_100ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_Boolean_status Rte_Buf_Task_100ms_MotPMP_PumpDryRunningSta_MotPMP_PumpDryRunningSta_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_MotPMP_PumpInputVolt_MotPMP_PumpInputVolt_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_MotPMP_PumpMotorSta_MotPMP_PumpMotorSta_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_MotPMP_PumpPowerSta_MotPMP_PumpPowerSta_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_MotPMP_PumpTempSta_MotPMP_PumpTempSta_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_Boolean_status Rte_Buf_Task_100ms_MotPMP_RESP_ERROR_MotPMP_RESP_ERROR_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_MotPMP_RealRPM_MotPMP_RealRPM_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_Vcu2BcmTms_outputs_status Rte_Buf_Task_100ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_AcPMP_SpdSet_AcPMP_SpdSet_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_BAT_EXV_initialize_command_B_BAT_EXV_initialize_command_B_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_Boolean_status Rte_Buf_Task_100ms_BAT_EXV_movenable_command_B_BAT_EXV_movenable_command_B_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt16_status Rte_Buf_Task_100ms_BAT_EXV_position_command_B_BAT_EXV_position_command_B_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_BatPMP_SpdSet_BatPMP_SpdSet_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_C3WV_BPosSetReq_C3WV_BPosSetReq_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_C3WV_RefDrvReq_C3WV_RefDrvReq_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_C3WV_SpdLvlReq_C3WV_SpdLvlReq_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_C5WV_BPosSetReq_C5WV_BPosSetReq_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_C5WV_RefDrvReq_C5WV_RefDrvReq_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_C5WV_SpdLvlReq_C5WV_SpdLvlReq_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_HP_EXV_initialize_command_B_HP_EXV_initialize_command_B_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_Boolean_status Rte_Buf_Task_100ms_HP_EXV_movenable_command_B_HP_EXV_movenable_command_B_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt16_status Rte_Buf_Task_100ms_HP_EXV_position_command_B_HP_EXV_position_command_B_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_MotPMP_SpdSet_MotPMP_SpdSet_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_Boolean_status Rte_Buf_Task_100ms_TMM_EXV_EnableRequest_TMM_EXV_EnableRequest_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt16_status Rte_Buf_Task_100ms_TMM_EXV_PositionRequest_TMM_EXV_PositionRequest_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_UInt8_status Rte_Buf_Task_100ms_TMM_EXV_initRequest_TMM_EXV_initRequest_ibuffer = {.value = 0, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_TMS2VCU_AC_1_Command_Outputs_status Rte_Buf_Task_100ms_TMS2VCU_AC_1_Command_Outputs_TMS2VCU_AC_1_Command_Outputs_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_TMS2VCU_AC_2_State_Outputs_status Rte_Buf_Task_100ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_TMS2VCU_AC_3_State_Outputs_status Rte_Buf_Task_100ms_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_TMS2VCU_AC_8_status_Outputs_status Rte_Buf_Task_100ms_TMS2VCU_AC_8_status_Outputs_TMS2VCU_AC_8_status_Outputs_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_TMS2VCU_AC_ACStatuts_Outputs_status Rte_Buf_Task_100ms_TMS2VCU_AC_ACStatuts_Outputs_TMS2VCU_AC_ACStatuts_Outputs_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_TMS2VCU_AC_COMP_Outputs_status Rte_Buf_Task_100ms_TMS2VCU_AC_COMP_Outputs_TMS2VCU_AC_COMP_Outputs_ibuffer = {.value = {0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_TMS2VCU_HVCH_Command_Outputs_status Rte_Buf_Task_100ms_TMS2VCU_HVCH_Command_Outputs_TMS2VCU_HVCH_Command_Outputs_ibuffer = {.value = {0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_TMS2VCU_PPVAddSignalGroup_Outputs_status Rte_Buf_Task_100ms_TMS2VCU_PPV_outputs_TMS2VCU_PPV_outputs_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_TMS2VCU_TMS_LINTestData1_Outputs_status Rte_Buf_Task_100ms_TMS2VCU_TMS_LINTestData1_Outputs_TMS2VCU_TMS_LINTestData1_Outputs_ibuffer = {.value = {0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_TMS2VCU_TMS_LINTestData2_Outputs_status Rte_Buf_Task_100ms_TMS2VCU_TMS_LINTestData2_Outputs_TMS2VCU_TMS_LINTestData2_Outputs_ibuffer = {.value = {0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_TMS2VCU_TMS_LINTestData3_Outputs_status Rte_Buf_Task_100ms_TMS2VCU_TMS_LINTestData3_Outputs_TMS2VCU_TMS_LINTestData3_Outputs_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_Tms2Vcu_Info_status Rte_Buf_Task_100ms_Tms2Vcu_Info_Tms2Vcu_Info_ibuffer = {.value = {0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_CONST_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
CONST(Rte_CDS_ME11, RTE_CONST) Rte_Inst_ME11 =
{
    .Task_100ms_AcPMP_HWVersion_AcPMP_HWVersion = &Rte_Buf_Task_100ms_AcPMP_HWVersion_AcPMP_HWVersion_ibuffer,
    .Task_100ms_AcPMP_PartNumber_AcPMP_PartNumber = &Rte_Buf_Task_100ms_AcPMP_PartNumber_AcPMP_PartNumber_ibuffer,
    .Task_100ms_AcPMP_ProjectCode1_AcPMP_ProjectCode1 = &Rte_Buf_Task_100ms_AcPMP_ProjectCode1_AcPMP_ProjectCode1_ibuffer,
    .Task_100ms_AcPMP_ProjectCode2_AcPMP_ProjectCode2 = &Rte_Buf_Task_100ms_AcPMP_ProjectCode2_AcPMP_ProjectCode2_ibuffer,
    .Task_100ms_AcPMP_PumpDryRunningSta_AcPMP_PumpDryRunningSta = &Rte_Buf_Task_100ms_AcPMP_PumpDryRunningSta_AcPMP_PumpDryRunningSta_ibuffer,
    .Task_100ms_AcPMP_PumpInputVolt_AcPMP_PumpInputVolt = &Rte_Buf_Task_100ms_AcPMP_PumpInputVolt_AcPMP_PumpInputVolt_ibuffer,
    .Task_100ms_AcPMP_PumpMotorSta_AcPMP_PumpMotorSta = &Rte_Buf_Task_100ms_AcPMP_PumpMotorSta_AcPMP_PumpMotorSta_ibuffer,
    .Task_100ms_AcPMP_PumpPowerSta_AcPMP_PumpPowerSta = &Rte_Buf_Task_100ms_AcPMP_PumpPowerSta_AcPMP_PumpPowerSta_ibuffer,
    .Task_100ms_AcPMP_PumpTempSta_AcPMP_PumpTempSta = &Rte_Buf_Task_100ms_AcPMP_PumpTempSta_AcPMP_PumpTempSta_ibuffer,
    .Task_100ms_AcPMP_RESP_ERROR_AcPMP_RESP_ERROR = &Rte_Buf_Task_100ms_AcPMP_RESP_ERROR_AcPMP_RESP_ERROR_ibuffer,
    .Task_100ms_AcPMP_RealRPM_AcPMP_RealRPM = &Rte_Buf_Task_100ms_AcPMP_RealRPM_AcPMP_RealRPM_ibuffer,
    .Task_100ms_AcPMP_SWVersion_Main_AcPMP_SWVersion_Main = &Rte_Buf_Task_100ms_AcPMP_SWVersion_Main_AcPMP_SWVersion_Main_ibuffer,
    .Task_100ms_AcPMP_SWVersion_Patch_AcPMP_SWVersion_Patch = &Rte_Buf_Task_100ms_AcPMP_SWVersion_Patch_AcPMP_SWVersion_Patch_ibuffer,
    .Task_100ms_AcPMP_SWVersion_Sub_AcPMP_SWVersion_Sub = &Rte_Buf_Task_100ms_AcPMP_SWVersion_Sub_AcPMP_SWVersion_Sub_ibuffer,
    .Task_100ms_AcPMP_SupplierNumber_AcPMP_SupplierNumber = &Rte_Buf_Task_100ms_AcPMP_SupplierNumber_AcPMP_SupplierNumber_ibuffer,
    .Task_100ms_BAT_EXV_CurrentPosition_B_BAT_EXV_CurrentPosition_B = &Rte_Buf_Task_100ms_BAT_EXV_CurrentPosition_B_BAT_EXV_CurrentPosition_B_ibuffer,
    .Task_100ms_BAT_EXV_FaultState_B_BAT_EXV_FaultState_B = &Rte_Buf_Task_100ms_BAT_EXV_FaultState_B_BAT_EXV_FaultState_B_ibuffer,
    .Task_100ms_BAT_EXV_ResponseError_B_BAT_EXV_ResponseError_B = &Rte_Buf_Task_100ms_BAT_EXV_ResponseError_B_BAT_EXV_ResponseError_B_ibuffer,
    .Task_100ms_BAT_EXV_RunState_B_BAT_EXV_RunState_B = &Rte_Buf_Task_100ms_BAT_EXV_RunState_B_BAT_EXV_RunState_B_ibuffer,
    .Task_100ms_BAT_EXV_SupplierLabel_BAT_EXV_SupplierLabel = &Rte_Buf_Task_100ms_BAT_EXV_SupplierLabel_BAT_EXV_SupplierLabel_ibuffer,
    .Task_100ms_BAT_EXV_VoltageState_B_BAT_EXV_VoltageState_B = &Rte_Buf_Task_100ms_BAT_EXV_VoltageState_B_BAT_EXV_VoltageState_B_ibuffer,
    .Task_100ms_BAT_EXV_Warning_OverTemp_BAT_EXV_Warning_OverTemp = &Rte_Buf_Task_100ms_BAT_EXV_Warning_OverTemp_BAT_EXV_Warning_OverTemp_ibuffer,
    .Task_100ms_BAT_EXV_initialize_status_BAT_EXV_initialize_status = &Rte_Buf_Task_100ms_BAT_EXV_initialize_status_BAT_EXV_initialize_status_ibuffer,
    .Task_100ms_BatPMP_PumpDryRunningSta_BatPMP_PumpDryRunningSta = &Rte_Buf_Task_100ms_BatPMP_PumpDryRunningSta_BatPMP_PumpDryRunningSta_ibuffer,
    .Task_100ms_BatPMP_PumpInputVolt_BatPMP_PumpInputVolt = &Rte_Buf_Task_100ms_BatPMP_PumpInputVolt_BatPMP_PumpInputVolt_ibuffer,
    .Task_100ms_BatPMP_PumpMotorSta_BatPMP_PumpMotorSta = &Rte_Buf_Task_100ms_BatPMP_PumpMotorSta_BatPMP_PumpMotorSta_ibuffer,
    .Task_100ms_BatPMP_PumpPowerSta_BatPMP_PumpPowerSta = &Rte_Buf_Task_100ms_BatPMP_PumpPowerSta_BatPMP_PumpPowerSta_ibuffer,
    .Task_100ms_BatPMP_PumpTempSta_BatPMP_PumpTempSta = &Rte_Buf_Task_100ms_BatPMP_PumpTempSta_BatPMP_PumpTempSta_ibuffer,
    .Task_100ms_BatPMP_RESP_ERROR_BatPMP_RESP_ERROR = &Rte_Buf_Task_100ms_BatPMP_RESP_ERROR_BatPMP_RESP_ERROR_ibuffer,
    .Task_100ms_BatPMP_RealRPM_BatPMP_RealRPM = &Rte_Buf_Task_100ms_BatPMP_RealRPM_BatPMP_RealRPM_ibuffer,
    .Task_100ms_Bat_EXV_HWVersion_Bat_EXV_HWVersion = &Rte_Buf_Task_100ms_Bat_EXV_HWVersion_Bat_EXV_HWVersion_ibuffer,
    .Task_100ms_Bat_EXV_PartNumber_Bat_EXV_PartNumber = &Rte_Buf_Task_100ms_Bat_EXV_PartNumber_Bat_EXV_PartNumber_ibuffer,
    .Task_100ms_Bat_EXV_ProjectCode1_Bat_EXV_ProjectCode1 = &Rte_Buf_Task_100ms_Bat_EXV_ProjectCode1_Bat_EXV_ProjectCode1_ibuffer,
    .Task_100ms_Bat_EXV_ProjectCode2_Bat_EXV_ProjectCode2 = &Rte_Buf_Task_100ms_Bat_EXV_ProjectCode2_Bat_EXV_ProjectCode2_ibuffer,
    .Task_100ms_Bat_EXV_SWVersion_Main_Bat_EXV_SWVersion_Main = &Rte_Buf_Task_100ms_Bat_EXV_SWVersion_Main_Bat_EXV_SWVersion_Main_ibuffer,
    .Task_100ms_Bat_EXV_SWVersion_Patch_Bat_EXV_SWVersion_Patch = &Rte_Buf_Task_100ms_Bat_EXV_SWVersion_Patch_Bat_EXV_SWVersion_Patch_ibuffer,
    .Task_100ms_Bat_EXV_SWVersion_Sub_Bat_EXV_SWVersion_Sub = &Rte_Buf_Task_100ms_Bat_EXV_SWVersion_Sub_Bat_EXV_SWVersion_Sub_ibuffer,
    .Task_100ms_Bat_EXV_SupplierNumber_Bat_EXV_SupplierNumber = &Rte_Buf_Task_100ms_Bat_EXV_SupplierNumber_Bat_EXV_SupplierNumber_ibuffer,
    .Task_100ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs = &Rte_Buf_Task_100ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs_ibuffer,
    .Task_100ms_C3WV_ErrResp_C3WV_ErrResp = &Rte_Buf_Task_100ms_C3WV_ErrResp_C3WV_ErrResp_ibuffer,
    .Task_100ms_C3WV_FltSts_C3WV_FltSts = &Rte_Buf_Task_100ms_C3WV_FltSts_C3WV_FltSts_ibuffer,
    .Task_100ms_C3WV_Mode_C3WV_Mode = &Rte_Buf_Task_100ms_C3WV_Mode_C3WV_Mode_ibuffer,
    .Task_100ms_C3WV_PosRec_C3WV_PosRec = &Rte_Buf_Task_100ms_C3WV_PosRec_C3WV_PosRec_ibuffer,
    .Task_100ms_C3WV_RunSts_C3WV_RunSts = &Rte_Buf_Task_100ms_C3WV_RunSts_C3WV_RunSts_ibuffer,
    .Task_100ms_C3WV_SpdLvl_C3WV_SpdLvl = &Rte_Buf_Task_100ms_C3WV_SpdLvl_C3WV_SpdLvl_ibuffer,
    .Task_100ms_C3WV_TempSts_C3WV_TempSts = &Rte_Buf_Task_100ms_C3WV_TempSts_C3WV_TempSts_ibuffer,
    .Task_100ms_C3WV_VoltSts_C3WV_VoltSts = &Rte_Buf_Task_100ms_C3WV_VoltSts_C3WV_VoltSts_ibuffer,
    .Task_100ms_C5WVFltSts_C5WVFltSts = &Rte_Buf_Task_100ms_C5WVFltSts_C5WVFltSts_ibuffer,
    .Task_100ms_C5WVMode_C5WVMode = &Rte_Buf_Task_100ms_C5WVMode_C5WVMode_ibuffer,
    .Task_100ms_C5WVPosRec_C5WVPosRec = &Rte_Buf_Task_100ms_C5WVPosRec_C5WVPosRec_ibuffer,
    .Task_100ms_C5WVRunSts_C5WVRunSts = &Rte_Buf_Task_100ms_C5WVRunSts_C5WVRunSts_ibuffer,
    .Task_100ms_C5WVSpdLvl_C5WVSpdLvl = &Rte_Buf_Task_100ms_C5WVSpdLvl_C5WVSpdLvl_ibuffer,
    .Task_100ms_C5WVTempSts_C5WVTempSts = &Rte_Buf_Task_100ms_C5WVTempSts_C5WVTempSts_ibuffer,
    .Task_100ms_C5WVVoltSts_C5WVVoltSts = &Rte_Buf_Task_100ms_C5WVVoltSts_C5WVVoltSts_ibuffer,
    .Task_100ms_EXV_CurrentInitState_EXV_CurrentInitState = &Rte_Buf_Task_100ms_EXV_CurrentInitState_EXV_CurrentInitState_ibuffer,
    .Task_100ms_EXV_CurrentPosition_EXV_CurrentPosition = &Rte_Buf_Task_100ms_EXV_CurrentPosition_EXV_CurrentPosition_ibuffer,
    .Task_100ms_EXV_FaultState_EXV_FaultState = &Rte_Buf_Task_100ms_EXV_FaultState_EXV_FaultState_ibuffer,
    .Task_100ms_EXV_ResponseError_EXV_ResponseError = &Rte_Buf_Task_100ms_EXV_ResponseError_EXV_ResponseError_ibuffer,
    .Task_100ms_EXV_RunState_EXV_RunState = &Rte_Buf_Task_100ms_EXV_RunState_EXV_RunState_ibuffer,
    .Task_100ms_EXV_TemperatureWarn_EXV_TemperatureWarn = &Rte_Buf_Task_100ms_EXV_TemperatureWarn_EXV_TemperatureWarn_ibuffer,
    .Task_100ms_EXV_VoltageState_EXV_VoltageState = &Rte_Buf_Task_100ms_EXV_VoltageState_EXV_VoltageState_ibuffer,
    .Task_100ms_ErrRespC5WV_ErrRespC5WV = &Rte_Buf_Task_100ms_ErrRespC5WV_ErrRespC5WV_ibuffer,
    .Task_100ms_HP_EXV_CurrentPosition_B_HP_EXV_CurrentPosition_B = &Rte_Buf_Task_100ms_HP_EXV_CurrentPosition_B_HP_EXV_CurrentPosition_B_ibuffer,
    .Task_100ms_HP_EXV_FaultState_B_HP_EXV_FaultState_B = &Rte_Buf_Task_100ms_HP_EXV_FaultState_B_HP_EXV_FaultState_B_ibuffer,
    .Task_100ms_HP_EXV_HWVersion_HP_EXV_HWVersion = &Rte_Buf_Task_100ms_HP_EXV_HWVersion_HP_EXV_HWVersion_ibuffer,
    .Task_100ms_HP_EXV_PartNumber_HP_EXV_PartNumber = &Rte_Buf_Task_100ms_HP_EXV_PartNumber_HP_EXV_PartNumber_ibuffer,
    .Task_100ms_HP_EXV_ProjectCode1_HP_EXV_ProjectCode1 = &Rte_Buf_Task_100ms_HP_EXV_ProjectCode1_HP_EXV_ProjectCode1_ibuffer,
    .Task_100ms_HP_EXV_ProjectCode2_HP_EXV_ProjectCode2 = &Rte_Buf_Task_100ms_HP_EXV_ProjectCode2_HP_EXV_ProjectCode2_ibuffer,
    .Task_100ms_HP_EXV_ResponseError_B_HP_EXV_ResponseError_B = &Rte_Buf_Task_100ms_HP_EXV_ResponseError_B_HP_EXV_ResponseError_B_ibuffer,
    .Task_100ms_HP_EXV_RunState_B_HP_EXV_RunState_B = &Rte_Buf_Task_100ms_HP_EXV_RunState_B_HP_EXV_RunState_B_ibuffer,
    .Task_100ms_HP_EXV_SWVersion_Main_HP_EXV_SWVersion_Main = &Rte_Buf_Task_100ms_HP_EXV_SWVersion_Main_HP_EXV_SWVersion_Main_ibuffer,
    .Task_100ms_HP_EXV_SWVersion_Patch_HP_EXV_SWVersion_Patch = &Rte_Buf_Task_100ms_HP_EXV_SWVersion_Patch_HP_EXV_SWVersion_Patch_ibuffer,
    .Task_100ms_HP_EXV_SWVersion_Sub_HP_EXV_SWVersion_Sub = &Rte_Buf_Task_100ms_HP_EXV_SWVersion_Sub_HP_EXV_SWVersion_Sub_ibuffer,
    .Task_100ms_HP_EXV_SupplierLabel_HP_EXV_SupplierLabel = &Rte_Buf_Task_100ms_HP_EXV_SupplierLabel_HP_EXV_SupplierLabel_ibuffer,
    .Task_100ms_HP_EXV_SupplierNumber_HP_EXV_SupplierNumber = &Rte_Buf_Task_100ms_HP_EXV_SupplierNumber_HP_EXV_SupplierNumber_ibuffer,
    .Task_100ms_HP_EXV_VoltageState_B_HP_EXV_VoltageState_B = &Rte_Buf_Task_100ms_HP_EXV_VoltageState_B_HP_EXV_VoltageState_B_ibuffer,
    .Task_100ms_HP_EXV_Warning_OverTemp_HP_EXV_Warning_OverTemp = &Rte_Buf_Task_100ms_HP_EXV_Warning_OverTemp_HP_EXV_Warning_OverTemp_ibuffer,
    .Task_100ms_HP_EXV_initialize_status_HP_EXV_initialize_status = &Rte_Buf_Task_100ms_HP_EXV_initialize_status_HP_EXV_initialize_status_ibuffer,
    .Task_100ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT = &Rte_Buf_Task_100ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT_ibuffer,
    .Task_100ms_IPM_BMS_2_BatState_EPT_IPM_BMS_2_BatState_EPT = &Rte_Buf_Task_100ms_IPM_BMS_2_BatState_EPT_IPM_BMS_2_BatState_EPT_ibuffer,
    .Task_100ms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT = &Rte_Buf_Task_100ms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT_ibuffer,
    .Task_100ms_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT = &Rte_Buf_Task_100ms_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT_ibuffer,
    .Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD = &Rte_Buf_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD_ibuffer,
    .Task_100ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD = &Rte_Buf_Task_100ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD_ibuffer,
    .Task_100ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA = &Rte_Buf_Task_100ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA_ibuffer,
    .Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC = &Rte_Buf_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC_ibuffer,
    .Task_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD = &Rte_Buf_Task_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD_ibuffer,
    .Task_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD = &Rte_Buf_Task_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD_ibuffer,
    .Task_100ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT = &Rte_Buf_Task_100ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT_ibuffer,
    .Task_100ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT = &Rte_Buf_Task_100ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT_ibuffer,
    .Task_100ms_MotPMP_PumpDryRunningSta_MotPMP_PumpDryRunningSta = &Rte_Buf_Task_100ms_MotPMP_PumpDryRunningSta_MotPMP_PumpDryRunningSta_ibuffer,
    .Task_100ms_MotPMP_PumpInputVolt_MotPMP_PumpInputVolt = &Rte_Buf_Task_100ms_MotPMP_PumpInputVolt_MotPMP_PumpInputVolt_ibuffer,
    .Task_100ms_MotPMP_PumpMotorSta_MotPMP_PumpMotorSta = &Rte_Buf_Task_100ms_MotPMP_PumpMotorSta_MotPMP_PumpMotorSta_ibuffer,
    .Task_100ms_MotPMP_PumpPowerSta_MotPMP_PumpPowerSta = &Rte_Buf_Task_100ms_MotPMP_PumpPowerSta_MotPMP_PumpPowerSta_ibuffer,
    .Task_100ms_MotPMP_PumpTempSta_MotPMP_PumpTempSta = &Rte_Buf_Task_100ms_MotPMP_PumpTempSta_MotPMP_PumpTempSta_ibuffer,
    .Task_100ms_MotPMP_RESP_ERROR_MotPMP_RESP_ERROR = &Rte_Buf_Task_100ms_MotPMP_RESP_ERROR_MotPMP_RESP_ERROR_ibuffer,
    .Task_100ms_MotPMP_RealRPM_MotPMP_RealRPM = &Rte_Buf_Task_100ms_MotPMP_RealRPM_MotPMP_RealRPM_ibuffer,
    .Task_100ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs = &Rte_Buf_Task_100ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs_ibuffer,
    .Task_100ms_AcPMP_SpdSet_AcPMP_SpdSet = &Rte_Buf_Task_100ms_AcPMP_SpdSet_AcPMP_SpdSet_ibuffer,
    .Task_100ms_BAT_EXV_initialize_command_B_BAT_EXV_initialize_command_B = &Rte_Buf_Task_100ms_BAT_EXV_initialize_command_B_BAT_EXV_initialize_command_B_ibuffer,
    .Task_100ms_BAT_EXV_movenable_command_B_BAT_EXV_movenable_command_B = &Rte_Buf_Task_100ms_BAT_EXV_movenable_command_B_BAT_EXV_movenable_command_B_ibuffer,
    .Task_100ms_BAT_EXV_position_command_B_BAT_EXV_position_command_B = &Rte_Buf_Task_100ms_BAT_EXV_position_command_B_BAT_EXV_position_command_B_ibuffer,
    .Task_100ms_BatPMP_SpdSet_BatPMP_SpdSet = &Rte_Buf_Task_100ms_BatPMP_SpdSet_BatPMP_SpdSet_ibuffer,
    .Task_100ms_C3WV_BPosSetReq_C3WV_BPosSetReq = &Rte_Buf_Task_100ms_C3WV_BPosSetReq_C3WV_BPosSetReq_ibuffer,
    .Task_100ms_C3WV_RefDrvReq_C3WV_RefDrvReq = &Rte_Buf_Task_100ms_C3WV_RefDrvReq_C3WV_RefDrvReq_ibuffer,
    .Task_100ms_C3WV_SpdLvlReq_C3WV_SpdLvlReq = &Rte_Buf_Task_100ms_C3WV_SpdLvlReq_C3WV_SpdLvlReq_ibuffer,
    .Task_100ms_C5WV_BPosSetReq_C5WV_BPosSetReq = &Rte_Buf_Task_100ms_C5WV_BPosSetReq_C5WV_BPosSetReq_ibuffer,
    .Task_100ms_C5WV_RefDrvReq_C5WV_RefDrvReq = &Rte_Buf_Task_100ms_C5WV_RefDrvReq_C5WV_RefDrvReq_ibuffer,
    .Task_100ms_C5WV_SpdLvlReq_C5WV_SpdLvlReq = &Rte_Buf_Task_100ms_C5WV_SpdLvlReq_C5WV_SpdLvlReq_ibuffer,
    .Task_100ms_HP_EXV_initialize_command_B_HP_EXV_initialize_command_B = &Rte_Buf_Task_100ms_HP_EXV_initialize_command_B_HP_EXV_initialize_command_B_ibuffer,
    .Task_100ms_HP_EXV_movenable_command_B_HP_EXV_movenable_command_B = &Rte_Buf_Task_100ms_HP_EXV_movenable_command_B_HP_EXV_movenable_command_B_ibuffer,
    .Task_100ms_HP_EXV_position_command_B_HP_EXV_position_command_B = &Rte_Buf_Task_100ms_HP_EXV_position_command_B_HP_EXV_position_command_B_ibuffer,
    .Task_100ms_MotPMP_SpdSet_MotPMP_SpdSet = &Rte_Buf_Task_100ms_MotPMP_SpdSet_MotPMP_SpdSet_ibuffer,
    .Task_100ms_TMM_EXV_EnableRequest_TMM_EXV_EnableRequest = &Rte_Buf_Task_100ms_TMM_EXV_EnableRequest_TMM_EXV_EnableRequest_ibuffer,
    .Task_100ms_TMM_EXV_PositionRequest_TMM_EXV_PositionRequest = &Rte_Buf_Task_100ms_TMM_EXV_PositionRequest_TMM_EXV_PositionRequest_ibuffer,
    .Task_100ms_TMM_EXV_initRequest_TMM_EXV_initRequest = &Rte_Buf_Task_100ms_TMM_EXV_initRequest_TMM_EXV_initRequest_ibuffer,
    .Task_100ms_TMS2VCU_AC_1_Command_Outputs_TMS2VCU_AC_1_Command_Outputs = &Rte_Buf_Task_100ms_TMS2VCU_AC_1_Command_Outputs_TMS2VCU_AC_1_Command_Outputs_ibuffer,
    .Task_100ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs = &Rte_Buf_Task_100ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs_ibuffer,
    .Task_100ms_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs = &Rte_Buf_Task_100ms_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs_ibuffer,
    .Task_100ms_TMS2VCU_AC_8_status_Outputs_TMS2VCU_AC_8_status_Outputs = &Rte_Buf_Task_100ms_TMS2VCU_AC_8_status_Outputs_TMS2VCU_AC_8_status_Outputs_ibuffer,
    .Task_100ms_TMS2VCU_AC_ACStatuts_Outputs_TMS2VCU_AC_ACStatuts_Outputs = &Rte_Buf_Task_100ms_TMS2VCU_AC_ACStatuts_Outputs_TMS2VCU_AC_ACStatuts_Outputs_ibuffer,
    .Task_100ms_TMS2VCU_AC_COMP_Outputs_TMS2VCU_AC_COMP_Outputs = &Rte_Buf_Task_100ms_TMS2VCU_AC_COMP_Outputs_TMS2VCU_AC_COMP_Outputs_ibuffer,
    .Task_100ms_TMS2VCU_HVCH_Command_Outputs_TMS2VCU_HVCH_Command_Outputs = &Rte_Buf_Task_100ms_TMS2VCU_HVCH_Command_Outputs_TMS2VCU_HVCH_Command_Outputs_ibuffer,
    .Task_100ms_TMS2VCU_PPV_outputs_TMS2VCU_PPV_outputs = &Rte_Buf_Task_100ms_TMS2VCU_PPV_outputs_TMS2VCU_PPV_outputs_ibuffer,
    .Task_100ms_TMS2VCU_TMS_LINTestData1_Outputs_TMS2VCU_TMS_LINTestData1_Outputs = &Rte_Buf_Task_100ms_TMS2VCU_TMS_LINTestData1_Outputs_TMS2VCU_TMS_LINTestData1_Outputs_ibuffer,
    .Task_100ms_TMS2VCU_TMS_LINTestData2_Outputs_TMS2VCU_TMS_LINTestData2_Outputs = &Rte_Buf_Task_100ms_TMS2VCU_TMS_LINTestData2_Outputs_TMS2VCU_TMS_LINTestData2_Outputs_ibuffer,
    .Task_100ms_TMS2VCU_TMS_LINTestData3_Outputs_TMS2VCU_TMS_LINTestData3_Outputs = &Rte_Buf_Task_100ms_TMS2VCU_TMS_LINTestData3_Outputs_TMS2VCU_TMS_LINTestData3_Outputs_ibuffer,
    .Task_100ms_Tms2Vcu_Info_Tms2Vcu_Info = &Rte_Buf_Task_100ms_Tms2Vcu_Info_Tms2Vcu_Info_ibuffer,
};
#define RTE_STOP_SEC_CONST_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_CANCommCRCFlt_status Rte_Buf_Runbl_DAG_20ms_CANCommCRCFlt_outputs_CANCommCRCFlt_outputs_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_COMP_AC_BOD_status Rte_Buf_Runbl_DAG_20ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_TBOX_BJS_Time_BAC_status Rte_Buf_Runbl_DAG_20ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_TMS2VCU_AC_3_State_Outputs_status Rte_Buf_Runbl_IBS_100ms_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_Bcm2VcuTms_outputs_status Rte_Buf_Runbl_VcuRx_10ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_CANCommErr_status Rte_Buf_Runbl_VcuRx_10ms_CANCommErr_outputs_CANCommErr_outputs_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_BMS_10_DC_ChargeStates_EPT_status Rte_Buf_Runbl_VcuRx_10ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT_ibuffer = {.value = {0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_BMS_1_MainState_EPT_status Rte_Buf_Runbl_VcuRx_10ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_BMS_2_BatState_EPT_status Rte_Buf_Runbl_VcuRx_10ms_IPM_BMS_2_BatState_EPT_IPM_BMS_2_BatState_EPT_ibuffer = {.value = {0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_BMS_3_DC_ChargeState_EPT_status Rte_Buf_Runbl_VcuRx_10ms_IPM_BMS_3_DC_ChargeState_EPT_IPM_BMS_3_DC_ChargeState_EPT_ibuffer = {.value = {0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_BMS_4_AC_ChargeState_EPT_status Rte_Buf_Runbl_VcuRx_10ms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_BMS_5_BatTemp_EPT_status Rte_Buf_Runbl_VcuRx_10ms_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT_ibuffer = {.value = {0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_BMS_6_DischrgRecup_EPT_status Rte_Buf_Runbl_VcuRx_10ms_IPM_BMS_6_DischrgRecup_EPT_IPM_BMS_6_DischrgRecup_EPT_ibuffer = {.value = {0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_BMS_7_CellVolt_EPT_status Rte_Buf_Runbl_VcuRx_10ms_IPM_BMS_7_CellVolt_EPT_IPM_BMS_7_CellVolt_EPT_ibuffer = {.value = {0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_BMS_9_BattInfo_EPT_status Rte_Buf_Runbl_VcuRx_10ms_IPM_BMS_9_BattInfo_EPT_IPM_BMS_9_BattInfo_EPT_ibuffer = {.value = {0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_CCP_PanelStatus_BOD_status Rte_Buf_Runbl_VcuRx_10ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_EHB_A_CHA_status Rte_Buf_Runbl_VcuRx_10ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_EHB_B_CHA_status Rte_Buf_Runbl_VcuRx_10ms_IPM_EHB_B_CHA_IPM_EHB_B_CHA_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_ESC_7_FuncStatus_CHA_status Rte_Buf_Runbl_VcuRx_10ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_ESC_A_CHA_status Rte_Buf_Runbl_VcuRx_10ms_IPM_ESC_A_CHA_IPM_ESC_A_CHA_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_FCM_B_CHA_status Rte_Buf_Runbl_VcuRx_10ms_IPM_FCM_B_CHA_IPM_FCM_B_CHA_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_HU_B_BAC_status Rte_Buf_Runbl_VcuRx_10ms_IPM_HU_B_BAC_IPM_HU_B_BAC_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_INV_1_Value_EPT_status Rte_Buf_Runbl_VcuRx_10ms_IPM_INV_1_Value_EPT_IPM_INV_1_Value_EPT_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_INV_2_Value_EPT_status Rte_Buf_Runbl_VcuRx_10ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT_ibuffer = {.value = {0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_INV_3_Value_EPT_status Rte_Buf_Runbl_VcuRx_10ms_IPM_INV_3_Value_EPT_IPM_INV_3_Value_EPT_ibuffer = {.value = {0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_INV_4_Value_EPT_status Rte_Buf_Runbl_VcuRx_10ms_IPM_INV_4_Value_EPT_IPM_INV_4_Value_EPT_ibuffer = {.value = {0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_IPU_DCC_1_State_EPT_status Rte_Buf_Runbl_VcuRx_10ms_IPM_IPU_DCC_1_State_EPT_IPM_IPU_DCC_1_State_EPT_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_IPU_DCC_2_ChrgInValue_EPT_status Rte_Buf_Runbl_VcuRx_10ms_IPM_IPU_DCC_2_ChrgInValue_EPT_IPM_IPU_DCC_2_ChrgInValue_EPT_ibuffer = {.value = {0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_IPU_OBC_1_State_EPT_status Rte_Buf_Runbl_VcuRx_10ms_IPM_IPU_OBC_1_State_EPT_IPM_IPU_OBC_1_State_EPT_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_IPU_OBC_2_Inlet_EPT_status Rte_Buf_Runbl_VcuRx_10ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_SCS_RiSwitchSts_BOD_status Rte_Buf_Runbl_VcuRx_10ms_IPM_SCS_RiSwitchSts_BOD_IPM_SCS_RiSwitchSts_BOD_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_IPM_SRS_1_Status_CHA_status Rte_Buf_Runbl_VcuRx_10ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA_ibuffer = {.value = {0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_MsgActv_status Rte_Buf_Runbl_VcuRx_10ms_MsgActv_outputs_MsgActv_outputs_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_TMS2VCU_AC_2_State_Outputs_status Rte_Buf_Runbl_VcuRx_10ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_Tms2Vcu_Info_status Rte_Buf_Runbl_VcuTx_10ms_Tms2Vcu_Info_Tms2Vcu_Info_ibuffer = {.value = {0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DAG_Comm_outputs_status Rte_Buf_Runbl_VcuTx_10ms_DAG_Comm_outputs_DAG_Comm_outputs_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_Vcu2BcmTms_outputs_status Rte_Buf_Runbl_VcuTx_10ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_Vcu2OpmBAC_outputs_status Rte_Buf_Runbl_VcuTx_10ms_Vcu2OpmBAC_outputs_Vcu2OpmBAC_outputs_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_Vcu2OpmCHA_outputs_status Rte_Buf_Runbl_VcuTx_10ms_Vcu2OpmCHA_outputs_Vcu2OpmCHA_outputs_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_DE_DT_Vcu2OpmEPT_outputs_status Rte_Buf_Runbl_VcuTx_10ms_Vcu2OpmEPT_outputs_Vcu2OpmEPT_outputs_ibuffer = {.value = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, .status = RTE_E_OK};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

#define RTE_START_SEC_CONST_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
CONST(Rte_CDS_AppSwcVcu, RTE_CONST) Rte_Inst_AppSwcVcu =
{
    .Runbl_DAG_20ms_CANCommCRCFlt_outputs_CANCommCRCFlt_outputs = &Rte_Buf_Runbl_DAG_20ms_CANCommCRCFlt_outputs_CANCommCRCFlt_outputs_ibuffer,
    .Runbl_DAG_20ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD = &Rte_Buf_Runbl_DAG_20ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD_ibuffer,
    .Runbl_DAG_20ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC = &Rte_Buf_Runbl_DAG_20ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC_ibuffer,
    .Runbl_IBS_100ms_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs = &Rte_Buf_Runbl_IBS_100ms_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs_ibuffer,
    .Runbl_VcuRx_10ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs = &Rte_Buf_Runbl_VcuRx_10ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs_ibuffer,
    .Runbl_VcuRx_10ms_CANCommErr_outputs_CANCommErr_outputs = &Rte_Buf_Runbl_VcuRx_10ms_CANCommErr_outputs_CANCommErr_outputs_ibuffer,
    .Runbl_VcuRx_10ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT = &Rte_Buf_Runbl_VcuRx_10ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT_ibuffer,
    .Runbl_VcuRx_10ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT = &Rte_Buf_Runbl_VcuRx_10ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT_ibuffer,
    .Runbl_VcuRx_10ms_IPM_BMS_2_BatState_EPT_IPM_BMS_2_BatState_EPT = &Rte_Buf_Runbl_VcuRx_10ms_IPM_BMS_2_BatState_EPT_IPM_BMS_2_BatState_EPT_ibuffer,
    .Runbl_VcuRx_10ms_IPM_BMS_3_DC_ChargeState_EPT_IPM_BMS_3_DC_ChargeState_EPT = &Rte_Buf_Runbl_VcuRx_10ms_IPM_BMS_3_DC_ChargeState_EPT_IPM_BMS_3_DC_ChargeState_EPT_ibuffer,
    .Runbl_VcuRx_10ms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT = &Rte_Buf_Runbl_VcuRx_10ms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT_ibuffer,
    .Runbl_VcuRx_10ms_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT = &Rte_Buf_Runbl_VcuRx_10ms_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT_ibuffer,
    .Runbl_VcuRx_10ms_IPM_BMS_6_DischrgRecup_EPT_IPM_BMS_6_DischrgRecup_EPT = &Rte_Buf_Runbl_VcuRx_10ms_IPM_BMS_6_DischrgRecup_EPT_IPM_BMS_6_DischrgRecup_EPT_ibuffer,
    .Runbl_VcuRx_10ms_IPM_BMS_7_CellVolt_EPT_IPM_BMS_7_CellVolt_EPT = &Rte_Buf_Runbl_VcuRx_10ms_IPM_BMS_7_CellVolt_EPT_IPM_BMS_7_CellVolt_EPT_ibuffer,
    .Runbl_VcuRx_10ms_IPM_BMS_9_BattInfo_EPT_IPM_BMS_9_BattInfo_EPT = &Rte_Buf_Runbl_VcuRx_10ms_IPM_BMS_9_BattInfo_EPT_IPM_BMS_9_BattInfo_EPT_ibuffer,
    .Runbl_VcuRx_10ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD = &Rte_Buf_Runbl_VcuRx_10ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD_ibuffer,
    .Runbl_VcuRx_10ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA = &Rte_Buf_Runbl_VcuRx_10ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA_ibuffer,
    .Runbl_VcuRx_10ms_IPM_EHB_B_CHA_IPM_EHB_B_CHA = &Rte_Buf_Runbl_VcuRx_10ms_IPM_EHB_B_CHA_IPM_EHB_B_CHA_ibuffer,
    .Runbl_VcuRx_10ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA = &Rte_Buf_Runbl_VcuRx_10ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA_ibuffer,
    .Runbl_VcuRx_10ms_IPM_ESC_A_CHA_IPM_ESC_A_CHA = &Rte_Buf_Runbl_VcuRx_10ms_IPM_ESC_A_CHA_IPM_ESC_A_CHA_ibuffer,
    .Runbl_VcuRx_10ms_IPM_FCM_B_CHA_IPM_FCM_B_CHA = &Rte_Buf_Runbl_VcuRx_10ms_IPM_FCM_B_CHA_IPM_FCM_B_CHA_ibuffer,
    .Runbl_VcuRx_10ms_IPM_HU_B_BAC_IPM_HU_B_BAC = &Rte_Buf_Runbl_VcuRx_10ms_IPM_HU_B_BAC_IPM_HU_B_BAC_ibuffer,
    .Runbl_VcuRx_10ms_IPM_INV_1_Value_EPT_IPM_INV_1_Value_EPT = &Rte_Buf_Runbl_VcuRx_10ms_IPM_INV_1_Value_EPT_IPM_INV_1_Value_EPT_ibuffer,
    .Runbl_VcuRx_10ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT = &Rte_Buf_Runbl_VcuRx_10ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT_ibuffer,
    .Runbl_VcuRx_10ms_IPM_INV_3_Value_EPT_IPM_INV_3_Value_EPT = &Rte_Buf_Runbl_VcuRx_10ms_IPM_INV_3_Value_EPT_IPM_INV_3_Value_EPT_ibuffer,
    .Runbl_VcuRx_10ms_IPM_INV_4_Value_EPT_IPM_INV_4_Value_EPT = &Rte_Buf_Runbl_VcuRx_10ms_IPM_INV_4_Value_EPT_IPM_INV_4_Value_EPT_ibuffer,
    .Runbl_VcuRx_10ms_IPM_IPU_DCC_1_State_EPT_IPM_IPU_DCC_1_State_EPT = &Rte_Buf_Runbl_VcuRx_10ms_IPM_IPU_DCC_1_State_EPT_IPM_IPU_DCC_1_State_EPT_ibuffer,
    .Runbl_VcuRx_10ms_IPM_IPU_DCC_2_ChrgInValue_EPT_IPM_IPU_DCC_2_ChrgInValue_EPT = &Rte_Buf_Runbl_VcuRx_10ms_IPM_IPU_DCC_2_ChrgInValue_EPT_IPM_IPU_DCC_2_ChrgInValue_EPT_ibuffer,
    .Runbl_VcuRx_10ms_IPM_IPU_OBC_1_State_EPT_IPM_IPU_OBC_1_State_EPT = &Rte_Buf_Runbl_VcuRx_10ms_IPM_IPU_OBC_1_State_EPT_IPM_IPU_OBC_1_State_EPT_ibuffer,
    .Runbl_VcuRx_10ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT = &Rte_Buf_Runbl_VcuRx_10ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT_ibuffer,
    .Runbl_VcuRx_10ms_IPM_SCS_RiSwitchSts_BOD_IPM_SCS_RiSwitchSts_BOD = &Rte_Buf_Runbl_VcuRx_10ms_IPM_SCS_RiSwitchSts_BOD_IPM_SCS_RiSwitchSts_BOD_ibuffer,
    .Runbl_VcuRx_10ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA = &Rte_Buf_Runbl_VcuRx_10ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA_ibuffer,
    .Runbl_VcuRx_10ms_MsgActv_outputs_MsgActv_outputs = &Rte_Buf_Runbl_VcuRx_10ms_MsgActv_outputs_MsgActv_outputs_ibuffer,
    .Runbl_VcuRx_10ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs = &Rte_Buf_Runbl_VcuRx_10ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs_ibuffer,
    .Runbl_VcuTx_10ms_Tms2Vcu_Info_Tms2Vcu_Info = &Rte_Buf_Runbl_VcuTx_10ms_Tms2Vcu_Info_Tms2Vcu_Info_ibuffer,
    .Runbl_VcuTx_10ms_DAG_Comm_outputs_DAG_Comm_outputs = &Rte_Buf_Runbl_VcuTx_10ms_DAG_Comm_outputs_DAG_Comm_outputs_ibuffer,
    .Runbl_VcuTx_10ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs = &Rte_Buf_Runbl_VcuTx_10ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs_ibuffer,
    .Runbl_VcuTx_10ms_Vcu2OpmBAC_outputs_Vcu2OpmBAC_outputs = &Rte_Buf_Runbl_VcuTx_10ms_Vcu2OpmBAC_outputs_Vcu2OpmBAC_outputs_ibuffer,
    .Runbl_VcuTx_10ms_Vcu2OpmCHA_outputs_Vcu2OpmCHA_outputs = &Rte_Buf_Runbl_VcuTx_10ms_Vcu2OpmCHA_outputs_Vcu2OpmCHA_outputs_ibuffer,
    .Runbl_VcuTx_10ms_Vcu2OpmEPT_outputs_Vcu2OpmEPT_outputs = &Rte_Buf_Runbl_VcuTx_10ms_Vcu2OpmEPT_outputs_Vcu2OpmEPT_outputs_ibuffer,
};
#define RTE_STOP_SEC_CONST_INIT_UNSPECIFIED
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_Start
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
Std_ReturnType Rte_Start(void)
{
    (void)SetRelAlarm(OsAlarm_Core0_100ms, 100, OS_TICKS2MS_SystemTimer_Core0(100));
    (void)SetRelAlarm(OsAlarm_Core0_10ms, 10, OS_TICKS2MS_SystemTimer_Core0(10));
    (void)SetRelAlarm(OsAlarm_Core0_20ms, 20, OS_TICKS2MS_SystemTimer_Core0(20));
    (void)SetRelAlarm(OsAlarm_Core0_50ms, 50, OS_TICKS2MS_SystemTimer_Core0(50));
    RteInitState = RTE_INITED;
    return RTE_E_OK;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_Stop
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
Std_ReturnType Rte_Stop(void)
{
    RteInitState = RTE_UNINITED;
    return RTE_E_OK;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Os_TaskEntry_Rte_OsTask__Core0_100ms(void)
{
    Rte_Runbl_IpmCanRx_100ms();
    Rte_Runbl_RME_100ms();
    Rte_Runbl_IBS_100ms();
    Rte_Runbl_DSA_100ms();
    Rte_Runbl_HMI_100ms();
    Rte_Runbl_TBOX_100ms();
    Rte_Runbl_AppSwcBcm_100ms();
    Rte_Task_100ms();
    Rte_Runbl_OpmCanTx_100ms();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Os_TaskEntry_Rte_OsTask__Core0_10ms(void)
{
    Rte_Runbl_IpmMsgActv_10ms();
    Rte_Runbl_IpmCanRx_10ms();
    Rte_Runbl_VcuRx_10ms();
    Rte_Runbl_IPC_10ms();
    Rte_Runbl_VTM_10ms();
    Rte_Runbl_VSO_10ms();
    Rte_Runbl_VcuTx_10ms();
    Rte_Runbl_AppSwcBcm_10ms();
    Rte_Runbl_OpmRx_10ms();
    Rte_Runbl_OpmCanTx_10ms();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
#pragma default_function_attributes = @".iram_func"
void Os_TaskEntry_Rte_OsTask__Core0_20ms(void)
{
    Rte_Runbl_IpmCanRx_20ms();
    Rte_Runbl_DAG_20ms();
    Rte_Runbl_GSM_20ms();
    Rte_Runbl_HVM_20ms();
    Rte_Runbl_EMS_20ms();
     
    Rte_Runbl_AppSwcBcm_20ms();
    Rte_Runbl_OpmCanTx_20ms();
}
#pragma default_function_attributes =
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Os_TaskEntry_Rte_OsTask__Core0_50ms(void)
{

    Rte_Runbl_IpmCanRx_50ms();
    Rte_Runbl_AppSwcBcm_50ms();
    Rte_Runbl_OpmCanTx_50ms();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void Os_TaskEntry_Rte_OsTask_Core0_Init(void)
{
    Rte_AppSwcVcu_Init();
    Rte_ME11_Init();
    Rte_AppSwcOpm_Init();
    Rte_AppSwcIpm_Init();
    Rte_AppSwcBcm_Init();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

