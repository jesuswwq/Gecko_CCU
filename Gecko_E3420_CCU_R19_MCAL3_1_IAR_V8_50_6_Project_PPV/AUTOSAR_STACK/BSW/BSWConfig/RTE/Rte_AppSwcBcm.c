/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_AppSwcBcm.c>
 *  @brief      <>
 *  
 *  <MCU:E3420>
 *  
 *  @author     <>
 *  @date       <2024-11-13 17:39:08>
 */
/*============================================================================*/

/* Rte_AppSwcBcm.c */
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
#include "Rte_AppSwcBcm.h"
#include "Rte_Data.h"
#include "Com.h"

/*******************************************************************************
 **                        Private Function Declarations                      **
******************************************************************************/

static void Rte_PRE_Runbl_AppSwcBcm_100ms(void);

static void Rte_PRE_Runbl_AppSwcBcm_10ms(void);

static void Rte_PRE_Runbl_AppSwcBcm_20ms(void);

static void Rte_PRE_Runbl_AppSwcBcm_50ms(void);

static void Rte_POST_AppSwcBcm_Init(void);

static void Rte_POST_Runbl_AppSwcBcm_100ms(void);

static void Rte_POST_Runbl_AppSwcBcm_10ms(void);

static void Rte_POST_Runbl_AppSwcBcm_20ms(void);

static void Rte_POST_Runbl_AppSwcBcm_50ms(void);

/*******************************************************************************
 **                        Global Function Declarations                       **
******************************************************************************/

/*******************************************************************************
 **                        Private Function Definitions                       **
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
static void Rte_PRE_Runbl_AppSwcBcm_100ms(void)
{
    if (RteInitState == RTE_INITED)
    {
        SuspendAllInterrupts();
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_AlmSysCtl_Bus, (uint8*)&Irv_AppSwcBcm_AlmSysCtl_Bus, sizeof(AlmSysCtl));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_DoorLckCtl_Bus, (uint8*)&Irv_AppSwcBcm_DoorLckCtl_Bus, sizeof(DoorLckCtl));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_DynDID_Bus, (uint8*)&Irv_AppSwcBcm_DynDID_Bus, sizeof(DynDID));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_HornCtl_Bus, (uint8*)&Irv_AppSwcBcm_HornCtl_Bus, sizeof(HornCtl));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_IPM_CCP_PanelStatus_BOD, (uint8*)&Irv_AppSwcBcm_IPM_CCP_PanelStatus_BOD, sizeof(DT_IPM_CCP_PanelStatus_BOD));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_IPM_HU_B_BAC, (uint8*)&Irv_AppSwcBcm_IPM_HU_B_BAC, sizeof(DT_IPM_HU_B_BAC));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_LampCtl_Bus, (uint8*)&Irv_AppSwcBcm_LampCtl_Bus, sizeof(LampCtl));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_PDUCtl_Bus, (uint8*)&Irv_AppSwcBcm_PDUCtl_Bus, sizeof(PDUCtl));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_Wiper_Bus, (uint8*)&Irv_AppSwcBcm_Wiper_Bus, sizeof(WiperCtl));
        ResumeAllInterrupts();
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
static void Rte_PRE_Runbl_AppSwcBcm_10ms(void)
{
    if (RteInitState == RTE_INITED)
    {
        SuspendAllInterrupts();
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_10ms_AlmSysCtl_Bus, (uint8*)&Irv_AppSwcBcm_AlmSysCtl_Bus, sizeof(AlmSysCtl));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus, (uint8*)&Irv_AppSwcBcm_DoorLckCtl_Bus, sizeof(DoorLckCtl));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_10ms_IPM_HU_B_BAC, (uint8*)&Irv_AppSwcBcm_IPM_HU_B_BAC, sizeof(DT_IPM_HU_B_BAC));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_10ms_LampCtl_Bus, (uint8*)&Irv_AppSwcBcm_LampCtl_Bus, sizeof(LampCtl));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_10ms_PDUCtl_Bus, (uint8*)&Irv_AppSwcBcm_PDUCtl_Bus, sizeof(PDUCtl));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_10ms_Vcu2BcmTms_outputs, (uint8*)&Irv_AppSwcBcm_Vcu2BcmTms_outputs, sizeof(DT_Vcu2BcmTms_outputs));
        ResumeAllInterrupts();
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
static void Rte_PRE_Runbl_AppSwcBcm_20ms(void)
{
    if (RteInitState == RTE_INITED)
    {
        SuspendAllInterrupts();
        Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_FCLL_TiWngSt_FCLL_TiWngSt->value = Rte_Buf_Runbl_AppSwcBcm_20ms_FCLL_TiWngSt_FCLL_TiWngSt;
        Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_FCLR_TiWngSt_FCLR_TiWngSt->value = Rte_Buf_Runbl_AppSwcBcm_20ms_FCLR_TiWngSt_FCLR_TiWngSt;
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT->value), (uint8*)&Rte_Buf_Runbl_AppSwcBcm_20ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT, sizeof(DT_IPM_BMS_1_MainState_EPT));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD->value), (uint8*)&Rte_Buf_Runbl_AppSwcBcm_20ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD, sizeof(DT_IPM_CCP_PanelStatus_BOD));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA->value), (uint8*)&Rte_Buf_Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA, sizeof(DT_IPM_CRRR_A_CHA));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA->value), (uint8*)&Rte_Buf_Runbl_AppSwcBcm_20ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA, sizeof(DT_IPM_EHB_A_CHA));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_IPM_EHB_B_CHA_IPM_EHB_B_CHA->value), (uint8*)&Rte_Buf_Runbl_AppSwcBcm_20ms_IPM_EHB_B_CHA_IPM_EHB_B_CHA, sizeof(DT_IPM_EHB_B_CHA));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA->value), (uint8*)&Rte_Buf_Runbl_AppSwcBcm_20ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA, sizeof(DT_IPM_ESC_7_FuncStatus_CHA));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_IPM_HU_B_BAC_IPM_HU_B_BAC->value), (uint8*)&Rte_Buf_Runbl_AppSwcBcm_20ms_IPM_HU_B_BAC_IPM_HU_B_BAC, sizeof(DT_IPM_HU_B_BAC));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD->value), (uint8*)&Rte_Buf_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD, sizeof(DT_IPM_SCS_LeSwitchSts_BOD));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA->value), (uint8*)&Rte_Buf_Runbl_AppSwcBcm_20ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA, sizeof(DT_IPM_SRS_1_Status_CHA));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs->value), (uint8*)&Rte_Buf_Runbl_AppSwcBcm_20ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs, sizeof(DT_Vcu2BcmTms_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus, (uint8*)&Irv_AppSwcBcm_AlmSysCtl_Bus, sizeof(AlmSysCtl));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_BatSaveCtl_Bus, (uint8*)&Irv_AppSwcBcm_BatSaveCtl_Bus, sizeof(BatSaveCtl));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus, (uint8*)&Irv_AppSwcBcm_DoorLckCtl_Bus, sizeof(DoorLckCtl));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_DynDID_Bus, (uint8*)&Irv_AppSwcBcm_DynDID_Bus, sizeof(DynDID));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_ESCLCtl_Bus, (uint8*)&Irv_AppSwcBcm_ESCLCtl_Bus, sizeof(ESCLCtl));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_IMMOCtl_Bus, (uint8*)&Irv_AppSwcBcm_IMMOCtl_Bus, sizeof(IMMOCtl));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_IODID_Bus, (uint8*)&Irv_AppSwcBcm_IODID_Bus, sizeof(IODID));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_PDUCtl_Bus, (uint8*)&Irv_AppSwcBcm_PDUCtl_Bus, sizeof(PDUCtl));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus, (uint8*)&Irv_AppSwcBcm_PEPSCtl_Bus, sizeof(PEPSCtl));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_RVMCtl_Bus, (uint8*)&Irv_AppSwcBcm_RVMCtl_Bus, sizeof(RVMCtl));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_SeatCtl_Bus, (uint8*)&Irv_AppSwcBcm_SeatCtl_Bus, sizeof(SeatCtl));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_SteerWhlCtl_Bus, (uint8*)&Irv_AppSwcBcm_SteerWhlCtl_Bus, sizeof(SteerWhlCtl));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_WakeUpCtl_Bus, (uint8*)&Irv_AppSwcBcm_WakeUpCtl_Bus, sizeof(WakeUpCtl));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_WinCtl_Bus, (uint8*)&Irv_AppSwcBcm_WinCtl_Bus, sizeof(WinCtl));
        ResumeAllInterrupts();
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
static void Rte_PRE_Runbl_AppSwcBcm_50ms(void)
{
    if (RteInitState == RTE_INITED)
    {
        SuspendAllInterrupts();
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_50ms_IPM_ESCL_ESCLStatus_BOD_IPM_ESCL_ESCLStatus_BOD->value), (uint8*)&Rte_Buf_Runbl_AppSwcBcm_50ms_IPM_ESCL_ESCLStatus_BOD_IPM_ESCL_ESCLStatus_BOD, sizeof(DT_IPM_ESCL_ESCLStatus_BOD));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_50ms_IPM_INV_IMMO_Req_EPT_IPM_INV_IMMO_Req_EPT->value), (uint8*)&Rte_Buf_Runbl_AppSwcBcm_50ms_IPM_INV_IMMO_Req_EPT_IPM_INV_IMMO_Req_EPT, sizeof(DT_IPM_INV_IMMO_Req_EPT));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus, (uint8*)&Irv_AppSwcBcm_EEReadCtl_Bus, sizeof(EEReadCtl));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_HornCtl_Bus, (uint8*)&Irv_AppSwcBcm_HornCtl_Bus, sizeof(HornCtl));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_IODID_Bus, (uint8*)&Irv_AppSwcBcm_IODID_Bus, sizeof(IODID));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_IPM_CCP_PanelStatus_BOD, (uint8*)&Irv_AppSwcBcm_IPM_CCP_PanelStatus_BOD, sizeof(DT_IPM_CCP_PanelStatus_BOD));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC, (uint8*)&Irv_AppSwcBcm_IPM_HU_B_BAC, sizeof(DT_IPM_HU_B_BAC));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_LampCtl_Bus, (uint8*)&Irv_AppSwcBcm_LampCtl_Bus, sizeof(LampCtl));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_PEPSCtl_Bus, (uint8*)&Irv_AppSwcBcm_PEPSCtl_Bus, sizeof(PEPSCtl));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs, (uint8*)&Irv_AppSwcBcm_Vcu2BcmTms_outputs, sizeof(DT_Vcu2BcmTms_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_WinCtl_Bus, (uint8*)&Irv_AppSwcBcm_WinCtl_Bus, sizeof(WinCtl));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_Wiper_Bus, (uint8*)&Irv_AppSwcBcm_Wiper_Bus, sizeof(WiperCtl));
        ResumeAllInterrupts();
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
static void Rte_POST_AppSwcBcm_Init(void)
{
    if (RteInitState == RTE_INITED)
    {
        SuspendAllInterrupts();
        rte_memcpy((uint8*)&Irv_AppSwcBcm_AlmSysCtl_Bus, (uint8*)&Irv_AppSwcBcm_AppSwcBcm_Init_AlmSysCtl_Bus, sizeof(AlmSysCtl));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_EEReadCtl_Bus, (uint8*)&Irv_AppSwcBcm_AppSwcBcm_Init_EEReadCtl_Bus, sizeof(EEReadCtl));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_IMMOCtl_Bus, (uint8*)&Irv_AppSwcBcm_AppSwcBcm_Init_IMMOCtl_Bus, sizeof(IMMOCtl));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_PEPSCtl_Bus, (uint8*)&Irv_AppSwcBcm_AppSwcBcm_Init_PEPSCtl_Bus, sizeof(PEPSCtl));
        ResumeAllInterrupts();
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
static void Rte_POST_Runbl_AppSwcBcm_100ms(void)
{
    if (RteInitState == RTE_INITED)
    {
        SuspendAllInterrupts();
        rte_memcpy((uint8*)&Irv_AppSwcBcm_IODID_Bus, (uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_IODID_Bus, sizeof(IODID));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_RVMCtl_Bus, (uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_RVMCtl_Bus, sizeof(RVMCtl));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_SeatCtl_Bus, (uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_SeatCtl_Bus, sizeof(SeatCtl));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_SteerWhlCtl_Bus, (uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_SteerWhlCtl_Bus, sizeof(SteerWhlCtl));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_WinCtl_Bus, (uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_WinCtl_Bus, sizeof(WinCtl));
        ResumeAllInterrupts();
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
static void Rte_POST_Runbl_AppSwcBcm_10ms(void)
{
    if (RteInitState == RTE_INITED)
    {
        SuspendAllInterrupts();
        rte_memcpy((uint8*)&Irv_AppSwcBcm_PEPSCtl_Bus, (uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_10ms_PEPSCtl_Bus, sizeof(PEPSCtl));
        ResumeAllInterrupts();
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
static void Rte_POST_Runbl_AppSwcBcm_20ms(void)
{
    if (RteInitState == RTE_INITED)
    {
        SuspendAllInterrupts();
        Rte_WriteBuffer_Rte_Buf_Runbl_AppSwcBcm_20ms_Bcm2OpmBAC_outputs_Bcm2OpmBAC_outputs(Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_Bcm2OpmBAC_outputs_Bcm2OpmBAC_outputs->value);
        Rte_WriteBuffer_Rte_Buf_Runbl_AppSwcBcm_20ms_Bcm2OpmEPT_outputs_Bcm2OpmEPT_outputs(Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_Bcm2OpmEPT_outputs_Bcm2OpmEPT_outputs->value);
        Rte_WriteBuffer_Rte_Buf_Runbl_AppSwcBcm_20ms_Bcm2OpmOBD_outputs_Bcm2OpmOBD_outputs(Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_Bcm2OpmOBD_outputs_Bcm2OpmOBD_outputs->value);
        Rte_WriteBuffer_Rte_Buf_Runbl_AppSwcBcm_20ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs(Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs->value);
        Com_SendSignal(Sig_Cmd_DrlLightReq_CCU_FCLCommand_LIN3, &Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_Sig_Cmd_DrlLightReq_Sig_Cmd_DrlLightReq->value);
        Com_SendSignal(Sig_Cmd_PosLightReq_CCU_FCLCommand_LIN3, &Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_Sig_Cmd_PosLightReq_Sig_Cmd_PosLightReq->value);
        Com_SendSignal(Sig_Cmd_TiLeLightReq_CCU_FCLCommand_LIN3, &Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_Sig_Cmd_TiLeLightReq_Sig_Cmd_TiLeLightReq->value);
        Com_SendSignal(Sig_Cmd_TiRiLightReq_CCU_FCLCommand_LIN3, &Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_Sig_Cmd_TiRiLightReq_Sig_Cmd_TiRiLightReq->value);
        Com_SendSignal(Sig_Cmd_TiWngFBSt_CCU_FCLCommand_LIN3, &Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_Sig_Cmd_TiWngFBSt_Sig_Cmd_TiWngFBSt->value);
        rte_memcpy((uint8*)&Irv_AppSwcBcm_EEReadCtl_Bus, (uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_EEReadCtl_Bus, sizeof(EEReadCtl));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_HornCtl_Bus, (uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_HornCtl_Bus, sizeof(HornCtl));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_IPM_CCP_PanelStatus_BOD, (uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_IPM_CCP_PanelStatus_BOD, sizeof(DT_IPM_CCP_PanelStatus_BOD));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_IPM_ESC_7_FuncStatus_CHA, (uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_IPM_ESC_7_FuncStatus_CHA, sizeof(DT_IPM_ESC_7_FuncStatus_CHA));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_IPM_HU_B_BAC, (uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_IPM_HU_B_BAC, sizeof(DT_IPM_HU_B_BAC));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_LampCtl_Bus, (uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_LampCtl_Bus, sizeof(LampCtl));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Vcu2BcmTms_outputs, (uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_Vcu2BcmTms_outputs, sizeof(DT_Vcu2BcmTms_outputs));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Wiper_Bus, (uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_Wiper_Bus, sizeof(WiperCtl));
        ResumeAllInterrupts();
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
static void Rte_POST_Runbl_AppSwcBcm_50ms(void)
{
    if (RteInitState == RTE_INITED)
    {
        SuspendAllInterrupts();
        rte_memcpy((uint8*)&Irv_AppSwcBcm_AlmSysCtl_Bus, (uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_AlmSysCtl_Bus, sizeof(AlmSysCtl));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_BatSaveCtl_Bus, (uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_BatSaveCtl_Bus, sizeof(BatSaveCtl));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_DoorLckCtl_Bus, (uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_DoorLckCtl_Bus, sizeof(DoorLckCtl));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_DynDID_Bus, (uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_DynDID_Bus, sizeof(DynDID));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_ESCLCtl_Bus, (uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_ESCLCtl_Bus, sizeof(ESCLCtl));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_IMMOCtl_Bus, (uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_IMMOCtl_Bus, sizeof(IMMOCtl));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_PDUCtl_Bus, (uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_PDUCtl_Bus, sizeof(PDUCtl));
        rte_memcpy((uint8*)&Irv_AppSwcBcm_WakeUpCtl_Bus, (uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_WakeUpCtl_Bus, sizeof(WakeUpCtl));
        ResumeAllInterrupts();
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
 **                        Global Function Definitions                        **
******************************************************************************/

/*******************************************************************************
*Function-Name        Runbl_AppSwcBcm_100ms
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
void Rte_Runbl_AppSwcBcm_100ms(void)
{
    Rte_PRE_Runbl_AppSwcBcm_100ms();
    if (RteInitState == RTE_INITED)
    {
        Runbl_AppSwcBcm_100ms();
    }
    Rte_POST_Runbl_AppSwcBcm_100ms();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Runbl_AppSwcBcm_10ms
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
void Rte_Runbl_AppSwcBcm_10ms(void)
{
    Rte_PRE_Runbl_AppSwcBcm_10ms();
    if (RteInitState == RTE_INITED)
    {
        Runbl_AppSwcBcm_10ms();
    }
    Rte_POST_Runbl_AppSwcBcm_10ms();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Runbl_AppSwcBcm_20ms
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
void Rte_Runbl_AppSwcBcm_20ms(void)
{
    Rte_PRE_Runbl_AppSwcBcm_20ms();
    if (RteInitState == RTE_INITED)
    {
        Runbl_AppSwcBcm_20ms();
    }
    Rte_POST_Runbl_AppSwcBcm_20ms();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Runbl_AppSwcBcm_50ms
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
void Rte_Runbl_AppSwcBcm_50ms(void)
{
    Rte_PRE_Runbl_AppSwcBcm_50ms();
    if (RteInitState == RTE_INITED)
    {
        Runbl_AppSwcBcm_50ms();
    }
    Rte_POST_Runbl_AppSwcBcm_50ms();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        AppSwcBcm_Init
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
void Rte_AppSwcBcm_Init(void)
{
    if (RteInitState == RTE_INITED)
    {
        AppSwcBcm_Init();
    }
    Rte_POST_AppSwcBcm_Init();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_AppSwcBcm_Init_AlmSysCtl_Bus
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
void Rte_IrvIWrite_AppSwcBcm_Init_AlmSysCtl_Bus(AlmSysCtl* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcBcm_AppSwcBcm_Init_AlmSysCtl_Bus, (uint8*)data, sizeof(AlmSysCtl));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_AppSwcBcm_Init_AlmSysCtl_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               AlmSysCtl *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
AlmSysCtl * Rte_IrvIWriteRef_AppSwcBcm_Init_AlmSysCtl_Bus(void)
{
    return &Irv_AppSwcBcm_AppSwcBcm_Init_AlmSysCtl_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_AppSwcBcm_100ms_AlmSysCtl_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               AlmSysCtl*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
AlmSysCtl* Rte_IrvIRead_Runbl_AppSwcBcm_100ms_AlmSysCtl_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_AlmSysCtl_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_AppSwcBcm_10ms_AlmSysCtl_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               AlmSysCtl*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
AlmSysCtl* Rte_IrvIRead_Runbl_AppSwcBcm_10ms_AlmSysCtl_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_10ms_AlmSysCtl_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               AlmSysCtl*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
AlmSysCtl* Rte_IrvIRead_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_AlmSysCtl_Bus
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
void Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_AlmSysCtl_Bus(AlmSysCtl* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_AlmSysCtl_Bus, (uint8*)data, sizeof(AlmSysCtl));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_AppSwcBcm_50ms_AlmSysCtl_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               AlmSysCtl *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
AlmSysCtl * Rte_IrvIWriteRef_Runbl_AppSwcBcm_50ms_AlmSysCtl_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_AlmSysCtl_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_AppSwcBcm_20ms_BatSaveCtl_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               BatSaveCtl*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
BatSaveCtl* Rte_IrvIRead_Runbl_AppSwcBcm_20ms_BatSaveCtl_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_BatSaveCtl_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_BatSaveCtl_Bus
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
void Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_BatSaveCtl_Bus(BatSaveCtl* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_BatSaveCtl_Bus, (uint8*)data, sizeof(BatSaveCtl));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_AppSwcBcm_50ms_BatSaveCtl_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               BatSaveCtl *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
BatSaveCtl * Rte_IrvIWriteRef_Runbl_AppSwcBcm_50ms_BatSaveCtl_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_BatSaveCtl_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_AppSwcBcm_100ms_DoorLckCtl_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DoorLckCtl*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DoorLckCtl* Rte_IrvIRead_Runbl_AppSwcBcm_100ms_DoorLckCtl_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_DoorLckCtl_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DoorLckCtl*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DoorLckCtl* Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DoorLckCtl*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DoorLckCtl* Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_DoorLckCtl_Bus
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
void Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_DoorLckCtl_Bus(DoorLckCtl* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_DoorLckCtl_Bus, (uint8*)data, sizeof(DoorLckCtl));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_AppSwcBcm_50ms_DoorLckCtl_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DoorLckCtl *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DoorLckCtl * Rte_IrvIWriteRef_Runbl_AppSwcBcm_50ms_DoorLckCtl_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_DoorLckCtl_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_AppSwcBcm_100ms_DynDID_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DynDID*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DynDID* Rte_IrvIRead_Runbl_AppSwcBcm_100ms_DynDID_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_DynDID_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DynDID_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DynDID*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DynDID* Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DynDID_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_DynDID_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_DynDID_Bus
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
void Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_DynDID_Bus(DynDID* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_DynDID_Bus, (uint8*)data, sizeof(DynDID));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_AppSwcBcm_50ms_DynDID_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DynDID *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DynDID * Rte_IrvIWriteRef_Runbl_AppSwcBcm_50ms_DynDID_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_DynDID_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_AppSwcBcm_Init_EEReadCtl_Bus
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
void Rte_IrvIWrite_AppSwcBcm_Init_EEReadCtl_Bus(EEReadCtl* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcBcm_AppSwcBcm_Init_EEReadCtl_Bus, (uint8*)data, sizeof(EEReadCtl));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_AppSwcBcm_Init_EEReadCtl_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               EEReadCtl *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
EEReadCtl * Rte_IrvIWriteRef_AppSwcBcm_Init_EEReadCtl_Bus(void)
{
    return &Irv_AppSwcBcm_AppSwcBcm_Init_EEReadCtl_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_EEReadCtl_Bus
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
void Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_EEReadCtl_Bus(EEReadCtl* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_EEReadCtl_Bus, (uint8*)data, sizeof(EEReadCtl));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_AppSwcBcm_20ms_EEReadCtl_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               EEReadCtl *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
EEReadCtl * Rte_IrvIWriteRef_Runbl_AppSwcBcm_20ms_EEReadCtl_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_EEReadCtl_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               EEReadCtl*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
EEReadCtl* Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_AppSwcBcm_20ms_ESCLCtl_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               ESCLCtl*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
ESCLCtl* Rte_IrvIRead_Runbl_AppSwcBcm_20ms_ESCLCtl_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_ESCLCtl_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_ESCLCtl_Bus
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
void Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_ESCLCtl_Bus(ESCLCtl* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_ESCLCtl_Bus, (uint8*)data, sizeof(ESCLCtl));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_AppSwcBcm_50ms_ESCLCtl_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               ESCLCtl *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
ESCLCtl * Rte_IrvIWriteRef_Runbl_AppSwcBcm_50ms_ESCLCtl_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_ESCLCtl_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_AppSwcBcm_100ms_HornCtl_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               HornCtl*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
HornCtl* Rte_IrvIRead_Runbl_AppSwcBcm_100ms_HornCtl_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_HornCtl_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_HornCtl_Bus
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
void Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_HornCtl_Bus(HornCtl* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_HornCtl_Bus, (uint8*)data, sizeof(HornCtl));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_AppSwcBcm_20ms_HornCtl_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               HornCtl *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
HornCtl * Rte_IrvIWriteRef_Runbl_AppSwcBcm_20ms_HornCtl_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_HornCtl_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_AppSwcBcm_50ms_HornCtl_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               HornCtl*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
HornCtl* Rte_IrvIRead_Runbl_AppSwcBcm_50ms_HornCtl_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_HornCtl_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_AppSwcBcm_Init_IMMOCtl_Bus
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
void Rte_IrvIWrite_AppSwcBcm_Init_IMMOCtl_Bus(IMMOCtl* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcBcm_AppSwcBcm_Init_IMMOCtl_Bus, (uint8*)data, sizeof(IMMOCtl));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_AppSwcBcm_Init_IMMOCtl_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               IMMOCtl *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
IMMOCtl * Rte_IrvIWriteRef_AppSwcBcm_Init_IMMOCtl_Bus(void)
{
    return &Irv_AppSwcBcm_AppSwcBcm_Init_IMMOCtl_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IMMOCtl_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               IMMOCtl*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
IMMOCtl* Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IMMOCtl_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_IMMOCtl_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_IMMOCtl_Bus
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
void Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_IMMOCtl_Bus(IMMOCtl* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_IMMOCtl_Bus, (uint8*)data, sizeof(IMMOCtl));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_AppSwcBcm_50ms_IMMOCtl_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               IMMOCtl *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
IMMOCtl * Rte_IrvIWriteRef_Runbl_AppSwcBcm_50ms_IMMOCtl_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_IMMOCtl_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_AppSwcBcm_100ms_IODID_Bus
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
void Rte_IrvIWrite_Runbl_AppSwcBcm_100ms_IODID_Bus(IODID* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_IODID_Bus, (uint8*)data, sizeof(IODID));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_AppSwcBcm_100ms_IODID_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               IODID *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
IODID * Rte_IrvIWriteRef_Runbl_AppSwcBcm_100ms_IODID_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_IODID_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               IODID*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
IODID* Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_IODID_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               IODID*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
IODID* Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_IODID_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_CCP_PanelStatus_BOD
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_CCP_PanelStatus_BOD*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_CCP_PanelStatus_BOD* Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_CCP_PanelStatus_BOD(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_IPM_CCP_PanelStatus_BOD;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_IPM_CCP_PanelStatus_BOD
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
void Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_IPM_CCP_PanelStatus_BOD(DT_IPM_CCP_PanelStatus_BOD* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_IPM_CCP_PanelStatus_BOD, (uint8*)data, sizeof(DT_IPM_CCP_PanelStatus_BOD));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_AppSwcBcm_20ms_IPM_CCP_PanelStatus_BOD
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_CCP_PanelStatus_BOD *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_CCP_PanelStatus_BOD * Rte_IrvIWriteRef_Runbl_AppSwcBcm_20ms_IPM_CCP_PanelStatus_BOD(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_IPM_CCP_PanelStatus_BOD;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_CCP_PanelStatus_BOD
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_IPM_CCP_PanelStatus_BOD*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_IPM_CCP_PanelStatus_BOD* Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_CCP_PanelStatus_BOD(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_IPM_CCP_PanelStatus_BOD;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_IPM_ESC_7_FuncStatus_CHA
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
void Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_IPM_ESC_7_FuncStatus_CHA(DT_IPM_ESC_7_FuncStatus_CHA* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_IPM_ESC_7_FuncStatus_CHA, (uint8*)data, sizeof(DT_IPM_ESC_7_FuncStatus_CHA));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_AppSwcBcm_20ms_IPM_ESC_7_FuncStatus_CHA
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
DT_IPM_ESC_7_FuncStatus_CHA * Rte_IrvIWriteRef_Runbl_AppSwcBcm_20ms_IPM_ESC_7_FuncStatus_CHA(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_IPM_ESC_7_FuncStatus_CHA;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_HU_B_BAC
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
DT_IPM_HU_B_BAC* Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_HU_B_BAC(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_IPM_HU_B_BAC;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_AppSwcBcm_10ms_IPM_HU_B_BAC
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
DT_IPM_HU_B_BAC* Rte_IrvIRead_Runbl_AppSwcBcm_10ms_IPM_HU_B_BAC(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_10ms_IPM_HU_B_BAC;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_IPM_HU_B_BAC
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
void Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_IPM_HU_B_BAC(DT_IPM_HU_B_BAC* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_IPM_HU_B_BAC, (uint8*)data, sizeof(DT_IPM_HU_B_BAC));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_AppSwcBcm_20ms_IPM_HU_B_BAC
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
DT_IPM_HU_B_BAC * Rte_IrvIWriteRef_Runbl_AppSwcBcm_20ms_IPM_HU_B_BAC(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_IPM_HU_B_BAC;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC
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
DT_IPM_HU_B_BAC* Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               LampCtl*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
LampCtl* Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_LampCtl_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_AppSwcBcm_10ms_LampCtl_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               LampCtl*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
LampCtl* Rte_IrvIRead_Runbl_AppSwcBcm_10ms_LampCtl_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_10ms_LampCtl_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_LampCtl_Bus
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
void Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_LampCtl_Bus(LampCtl* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_LampCtl_Bus, (uint8*)data, sizeof(LampCtl));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_AppSwcBcm_20ms_LampCtl_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               LampCtl *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
LampCtl * Rte_IrvIWriteRef_Runbl_AppSwcBcm_20ms_LampCtl_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_LampCtl_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               LampCtl*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
LampCtl* Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_LampCtl_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               PDUCtl*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
PDUCtl* Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_PDUCtl_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_AppSwcBcm_10ms_PDUCtl_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               PDUCtl*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
PDUCtl* Rte_IrvIRead_Runbl_AppSwcBcm_10ms_PDUCtl_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_10ms_PDUCtl_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               PDUCtl*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
PDUCtl* Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_PDUCtl_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_PDUCtl_Bus
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
void Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_PDUCtl_Bus(PDUCtl* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_PDUCtl_Bus, (uint8*)data, sizeof(PDUCtl));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_AppSwcBcm_50ms_PDUCtl_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               PDUCtl *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
PDUCtl * Rte_IrvIWriteRef_Runbl_AppSwcBcm_50ms_PDUCtl_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_PDUCtl_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_AppSwcBcm_Init_PEPSCtl_Bus
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
void Rte_IrvIWrite_AppSwcBcm_Init_PEPSCtl_Bus(PEPSCtl* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcBcm_AppSwcBcm_Init_PEPSCtl_Bus, (uint8*)data, sizeof(PEPSCtl));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_AppSwcBcm_Init_PEPSCtl_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               PEPSCtl *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
PEPSCtl * Rte_IrvIWriteRef_AppSwcBcm_Init_PEPSCtl_Bus(void)
{
    return &Irv_AppSwcBcm_AppSwcBcm_Init_PEPSCtl_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_AppSwcBcm_10ms_PEPSCtl_Bus
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
void Rte_IrvIWrite_Runbl_AppSwcBcm_10ms_PEPSCtl_Bus(PEPSCtl* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_10ms_PEPSCtl_Bus, (uint8*)data, sizeof(PEPSCtl));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_AppSwcBcm_10ms_PEPSCtl_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               PEPSCtl *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
PEPSCtl * Rte_IrvIWriteRef_Runbl_AppSwcBcm_10ms_PEPSCtl_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_10ms_PEPSCtl_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               PEPSCtl*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
PEPSCtl* Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_AppSwcBcm_50ms_PEPSCtl_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               PEPSCtl*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
PEPSCtl* Rte_IrvIRead_Runbl_AppSwcBcm_50ms_PEPSCtl_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_PEPSCtl_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_AppSwcBcm_100ms_RVMCtl_Bus
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
void Rte_IrvIWrite_Runbl_AppSwcBcm_100ms_RVMCtl_Bus(RVMCtl* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_RVMCtl_Bus, (uint8*)data, sizeof(RVMCtl));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_AppSwcBcm_100ms_RVMCtl_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               RVMCtl *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
RVMCtl * Rte_IrvIWriteRef_Runbl_AppSwcBcm_100ms_RVMCtl_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_RVMCtl_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_AppSwcBcm_20ms_RVMCtl_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               RVMCtl*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
RVMCtl* Rte_IrvIRead_Runbl_AppSwcBcm_20ms_RVMCtl_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_RVMCtl_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_AppSwcBcm_100ms_SeatCtl_Bus
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
void Rte_IrvIWrite_Runbl_AppSwcBcm_100ms_SeatCtl_Bus(SeatCtl* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_SeatCtl_Bus, (uint8*)data, sizeof(SeatCtl));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_AppSwcBcm_100ms_SeatCtl_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               SeatCtl *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
SeatCtl * Rte_IrvIWriteRef_Runbl_AppSwcBcm_100ms_SeatCtl_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_SeatCtl_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_AppSwcBcm_20ms_SeatCtl_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               SeatCtl*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
SeatCtl* Rte_IrvIRead_Runbl_AppSwcBcm_20ms_SeatCtl_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_SeatCtl_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_AppSwcBcm_100ms_SteerWhlCtl_Bus
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
void Rte_IrvIWrite_Runbl_AppSwcBcm_100ms_SteerWhlCtl_Bus(SteerWhlCtl* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_SteerWhlCtl_Bus, (uint8*)data, sizeof(SteerWhlCtl));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_AppSwcBcm_100ms_SteerWhlCtl_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               SteerWhlCtl *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
SteerWhlCtl * Rte_IrvIWriteRef_Runbl_AppSwcBcm_100ms_SteerWhlCtl_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_SteerWhlCtl_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_AppSwcBcm_20ms_SteerWhlCtl_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               SteerWhlCtl*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
SteerWhlCtl* Rte_IrvIRead_Runbl_AppSwcBcm_20ms_SteerWhlCtl_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_SteerWhlCtl_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_AppSwcBcm_10ms_Vcu2BcmTms_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_Vcu2BcmTms_outputs*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_Vcu2BcmTms_outputs* Rte_IrvIRead_Runbl_AppSwcBcm_10ms_Vcu2BcmTms_outputs(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_10ms_Vcu2BcmTms_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_Vcu2BcmTms_outputs
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
void Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_Vcu2BcmTms_outputs(DT_Vcu2BcmTms_outputs* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_Vcu2BcmTms_outputs, (uint8*)data, sizeof(DT_Vcu2BcmTms_outputs));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_AppSwcBcm_20ms_Vcu2BcmTms_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_Vcu2BcmTms_outputs *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_Vcu2BcmTms_outputs * Rte_IrvIWriteRef_Runbl_AppSwcBcm_20ms_Vcu2BcmTms_outputs(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_Vcu2BcmTms_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_Vcu2BcmTms_outputs*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_Vcu2BcmTms_outputs* Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WakeUpCtl_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               WakeUpCtl*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
WakeUpCtl* Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WakeUpCtl_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_WakeUpCtl_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_WakeUpCtl_Bus
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
void Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_WakeUpCtl_Bus(WakeUpCtl* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_WakeUpCtl_Bus, (uint8*)data, sizeof(WakeUpCtl));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_AppSwcBcm_50ms_WakeUpCtl_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               WakeUpCtl *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
WakeUpCtl * Rte_IrvIWriteRef_Runbl_AppSwcBcm_50ms_WakeUpCtl_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_WakeUpCtl_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_AppSwcBcm_100ms_WinCtl_Bus
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
void Rte_IrvIWrite_Runbl_AppSwcBcm_100ms_WinCtl_Bus(WinCtl* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_WinCtl_Bus, (uint8*)data, sizeof(WinCtl));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_AppSwcBcm_100ms_WinCtl_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               WinCtl *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
WinCtl * Rte_IrvIWriteRef_Runbl_AppSwcBcm_100ms_WinCtl_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_WinCtl_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               WinCtl*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
WinCtl* Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_WinCtl_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_AppSwcBcm_50ms_WinCtl_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               WinCtl*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
WinCtl* Rte_IrvIRead_Runbl_AppSwcBcm_50ms_WinCtl_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_WinCtl_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_AppSwcBcm_100ms_Wiper_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               WiperCtl*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
WiperCtl* Rte_IrvIRead_Runbl_AppSwcBcm_100ms_Wiper_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_100ms_Wiper_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_Wiper_Bus
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
void Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_Wiper_Bus(WiperCtl* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_Wiper_Bus, (uint8*)data, sizeof(WiperCtl));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_AppSwcBcm_20ms_Wiper_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               WiperCtl *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
WiperCtl * Rte_IrvIWriteRef_Runbl_AppSwcBcm_20ms_Wiper_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_20ms_Wiper_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Wiper_Bus
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               WiperCtl*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
WiperCtl* Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Wiper_Bus(void)
{
    return &Irv_AppSwcBcm_Runbl_AppSwcBcm_50ms_Wiper_Bus;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_AppSwcBcm_20ms_FCLL_TiWngSt_FCLL_TiWngSt
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
Std_ReturnType Rte_IStatus_Runbl_AppSwcBcm_20ms_FCLL_TiWngSt_FCLL_TiWngSt(void)
{
    return Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_FCLL_TiWngSt_FCLL_TiWngSt->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_AppSwcBcm_20ms_FCLR_TiWngSt_FCLR_TiWngSt
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
Std_ReturnType Rte_IStatus_Runbl_AppSwcBcm_20ms_FCLR_TiWngSt_FCLR_TiWngSt(void)
{
    return Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_FCLR_TiWngSt_FCLR_TiWngSt->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_AppSwcBcm_20ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT
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
Std_ReturnType Rte_IStatus_Runbl_AppSwcBcm_20ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT(void)
{
    return Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_AppSwcBcm_20ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD
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
Std_ReturnType Rte_IStatus_Runbl_AppSwcBcm_20ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD(void)
{
    return Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA
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
Std_ReturnType Rte_IStatus_Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA(void)
{
    return Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_AppSwcBcm_20ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA
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
Std_ReturnType Rte_IStatus_Runbl_AppSwcBcm_20ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA(void)
{
    return Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_AppSwcBcm_20ms_IPM_EHB_B_CHA_IPM_EHB_B_CHA
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
Std_ReturnType Rte_IStatus_Runbl_AppSwcBcm_20ms_IPM_EHB_B_CHA_IPM_EHB_B_CHA(void)
{
    return Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_IPM_EHB_B_CHA_IPM_EHB_B_CHA->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_AppSwcBcm_20ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA
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
Std_ReturnType Rte_IStatus_Runbl_AppSwcBcm_20ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA(void)
{
    return Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_AppSwcBcm_20ms_IPM_HU_B_BAC_IPM_HU_B_BAC
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
Std_ReturnType Rte_IStatus_Runbl_AppSwcBcm_20ms_IPM_HU_B_BAC_IPM_HU_B_BAC(void)
{
    return Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_IPM_HU_B_BAC_IPM_HU_B_BAC->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
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
Std_ReturnType Rte_IStatus_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD(void)
{
    return Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_AppSwcBcm_20ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA
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
Std_ReturnType Rte_IStatus_Runbl_AppSwcBcm_20ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA(void)
{
    return Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_AppSwcBcm_20ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs
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
Std_ReturnType Rte_IStatus_Runbl_AppSwcBcm_20ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs(void)
{
    return Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_AppSwcBcm_50ms_IPM_ESCL_ESCLStatus_BOD_IPM_ESCL_ESCLStatus_BOD
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
Std_ReturnType Rte_IStatus_Runbl_AppSwcBcm_50ms_IPM_ESCL_ESCLStatus_BOD_IPM_ESCL_ESCLStatus_BOD(void)
{
    return Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_50ms_IPM_ESCL_ESCLStatus_BOD_IPM_ESCL_ESCLStatus_BOD->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_AppSwcBcm_50ms_IPM_INV_IMMO_Req_EPT_IPM_INV_IMMO_Req_EPT
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
Std_ReturnType Rte_IStatus_Runbl_AppSwcBcm_50ms_IPM_INV_IMMO_Req_EPT_IPM_INV_IMMO_Req_EPT(void)
{
    return Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_50ms_IPM_INV_IMMO_Req_EPT_IPM_INV_IMMO_Req_EPT->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

