/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_AppSwcIpm.c>
 *  @brief      <>
 *  
 *  <MCU:E3420>
 *  
 *  @author     <>
 *  @date       <2024-10-10 14:07:07>
 */
/*============================================================================*/

/* Rte_AppSwcIpm.c */
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
#include "Rte_AppSwcIpm.h"
#include "Rte_Data.h"
#include "Com.h"

/*******************************************************************************
 **                        Private Function Declarations                      **
******************************************************************************/

static void Rte_PRE_Runbl_IpmCanRx_100ms(void);

static void Rte_PRE_Runbl_IpmCanRx_10ms(void);

static void Rte_PRE_Runbl_IpmCanRx_20ms(void);

static void Rte_PRE_Runbl_IpmCanRx_50ms(void);

static void Rte_PRE_Runbl_IpmMsgActv_10ms(void);

static void Rte_POST_Runbl_IpmCanRx_100ms(void);

static void Rte_POST_Runbl_IpmCanRx_10ms(void);

static void Rte_POST_Runbl_IpmCanRx_20ms(void);

static void Rte_POST_Runbl_IpmCanRx_50ms(void);

static void Rte_POST_Runbl_IpmMsgActv_10ms(void);

/*******************************************************************************
 **                        Global Function Declarations                       **
******************************************************************************/

/*******************************************************************************
 **                        Private Function Definitions                       **
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
static void Rte_PRE_Runbl_IpmCanRx_100ms(void)
{
    if (RteInitState == RTE_INITED)
    {
        SuspendAllInterrupts();
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_ACCM_Version_BOD_ACCM_Version_BOD->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_100ms_ACCM_Version_BOD_ACCM_Version_BOD, sizeof(ACCM_Version_BOD));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_BMS_5_BatTemp_EPT_BMS_5_BatTemp_EPT->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_100ms_BMS_5_BatTemp_EPT_BMS_5_BatTemp_EPT, sizeof(BMS_5_BatTemp_EPT));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_BMS_9_BattInfo_EPT_BMS_9_BattInfo_EPT->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_100ms_BMS_9_BattInfo_EPT_BMS_9_BattInfo_EPT, sizeof(BMS_9_BattInfo_EPT));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD, sizeof(COMP_AC_BOD));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC, sizeof(HU_B_BAC));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_HVCH_Status1_BOD_HVCH_Status1_BOD->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_100ms_HVCH_Status1_BOD_HVCH_Status1_BOD, sizeof(HVCH_Status1_BOD));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_HVCH_Status2_BOD_HVCH_Status2_BOD->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_100ms_HVCH_Status2_BOD_HVCH_Status2_BOD, sizeof(HVCH_Status2_BOD));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_INV_IMMO_Req_EPT_INV_IMMO_Req_EPT->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_100ms_INV_IMMO_Req_EPT_INV_IMMO_Req_EPT, sizeof(INV_IMMO_Req_EPT));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPU_DCC_1_State_EPT_IPU_DCC_1_State_EPT->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_100ms_IPU_DCC_1_State_EPT_IPU_DCC_1_State_EPT, sizeof(IPU_DCC_1_State_EPT));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPU_DCC_2_ChrgInValue_EPT_IPU_DCC_2_ChrgInValue_EPT->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_100ms_IPU_DCC_2_ChrgInValue_EPT_IPU_DCC_2_ChrgInValue_EPT, sizeof(IPU_DCC_2_ChrgInValue_EPT));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPU_OBC_1_State_EPT_IPU_OBC_1_State_EPT->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_100ms_IPU_OBC_1_State_EPT_IPU_OBC_1_State_EPT, sizeof(IPU_OBC_1_State_EPT));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPU_OBC_2_Inlet_EPT_IPU_OBC_2_Inlet_EPT->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_100ms_IPU_OBC_2_Inlet_EPT_IPU_OBC_2_Inlet_EPT, sizeof(IPU_OBC_2_Inlet_EPT));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_TBOX_BJS_Time_BAC_TBOX_BJS_Time_BAC->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_100ms_TBOX_BJS_Time_BAC_TBOX_BJS_Time_BAC, sizeof(TBOX_BJS_Time_BAC));
        rte_memcpy((uint8*)&Irv_AppSwcIpm_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV, (uint8*)&Irv_AppSwcIpm_CANCommCRCFlt_outputsIRV, sizeof(DT_CANCommCRCFlt));
        rte_memcpy((uint8*)&Irv_AppSwcIpm_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV, (uint8*)&Irv_AppSwcIpm_MsgActv_outputsIRV, sizeof(DT_MsgActv));
        ResumeAllInterrupts();
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
static void Rte_PRE_Runbl_IpmCanRx_10ms(void)
{
    if (RteInitState == RTE_INITED)
    {
        SuspendAllInterrupts();
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA, sizeof(EHB_B_CHA));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_EPS_2_StrWhlAng_CHA_EPS_2_StrWhlAng_CHA->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_10ms_EPS_2_StrWhlAng_CHA_EPS_2_StrWhlAng_CHA, sizeof(EPS_2_StrWhlAng_CHA));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_ESC_7_FuncStatus_CHA_ESC_7_FuncStatus_CHA->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_10ms_ESC_7_FuncStatus_CHA_ESC_7_FuncStatus_CHA, sizeof(ESC_7_FuncStatus_CHA));
        ESC_A_CHA Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data;
        uint8 Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_OK;
        if (E_OK == Com_ReceiveSignalGroup(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5))
        {
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_A_Chksum1_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_A_Chksum1))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_A_AliveCnt1_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_A_AliveCnt1))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_DTC_ActiveSts_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_DTC_ActiveSts))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_BrakeTempOverHeat_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_BrakeTempOverHeat))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_DTCFailureSts_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_DTCFailureSts))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_DTCRequestRBSSts_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_DTCRequestRBSSts))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_VhclStandstillSta_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_VhclStandstillSta))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_A_Chksum2_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_A_Chksum2))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_A_AliveCnt2_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_A_AliveCnt2))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WheelDirection_FL_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_WheelDirection_FL))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WheelSpeedKphV_FL_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_WheelSpeedKphV_FL))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WheelSpeedKph_FL_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_WheelSpeedKph_FL))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WheelDirection_FR_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_WheelDirection_FR))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WheelSpeedKphV_FR_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_WheelSpeedKphV_FR))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WheelSpeedKph_FR_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_WheelSpeedKph_FR))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_MasterCylinderPresr_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_MasterCylinderPresr))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_MasterCylinderPresrV_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_MasterCylinderPresrV))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_A_Chksum3_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_A_Chksum3))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_A_AliveCnt3_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_A_AliveCnt3))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WheelDirection_RL_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_WheelDirection_RL))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WheelSpeedKphV_RL_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_WheelSpeedKphV_RL))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WheelSpeedKph_RL_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_WheelSpeedKph_RL))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WheelDirection_RR_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_WheelDirection_RR))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WheelSpeedKphV_RR_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_WheelSpeedKphV_RR))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WheelSpeedKph_RR_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_WheelSpeedKph_RR))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_A_Chksum4_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_A_Chksum4))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_A_AliveCnt4_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_A_AliveCnt4))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WheelSpeedRCSts_RR_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_WheelSpeedRCSts_RR))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WheelSpeedRCSts_RL_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_WheelSpeedRCSts_RL))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WheelSpeedRCSts_FR_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_WheelSpeedRCSts_FR))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WheelSpeedRCSts_FL_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_WheelSpeedRCSts_FL))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WheelSpeedRC_FL_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_WheelSpeedRC_FL))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WheelSpeedRC_FR_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_WheelSpeedRC_FR))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WheelSpeedRC_RL_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_WheelSpeedRC_RL))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WheelSpeedRC_RR_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_WheelSpeedRC_RR))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_A_Chksum5_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_A_Chksum5))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_A_AliveCnt5_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_A_AliveCnt5))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_LatAccSensorValueVld_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_LatAccSensorValueVld))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_LongAccSensorValueVld_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_LongAccSensorValueVld))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_LongAccSensorValue_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_LongAccSensorValue))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_YawRateVld_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_YawRateVld))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_LatAccSensorValue_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_LatAccSensorValue))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_YawRate_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_YawRate))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_A_Chksum6_RihgtEPB_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_A_Chksum6_RihgtEPB))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_A_AliveCnt6_RihgtEPB_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_A_AliveCnt6_RihgtEPB))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_EPB_RightFaultState_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_EPB_RightFaultState))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_EPB_Right_Current_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_EPB_Right_Current))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_EPB_ActuatorSt_R_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_EPB_ActuatorSt_R))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_A_Chksum7_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_A_Chksum7))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_A_AliveCnt7_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_A_AliveCnt7))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WhlTqDecReqActv_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_WhlTqDecReqActv))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WhlTqDecReqVal_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_WhlTqDecReqVal))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WhlTqIncReqActv_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_WhlTqIncReqActv))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WhlTqIncReqVal_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data.ESC_WhlTqIncReqVal))
            {
                Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret = E_NOT_OK;
            }
            if (E_OK == Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_ret)
            {
                Rte_Buf_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA = Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA_data;
                Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA->status = RTE_E_OK;
            }
        }
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA, sizeof(ESC_A_CHA));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_INV_1_Value_EPT_INV_1_Value_EPT->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_10ms_INV_1_Value_EPT_INV_1_Value_EPT, sizeof(INV_1_Value_EPT));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_INV_2_Value_EPT_INV_2_Value_EPT->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_10ms_INV_2_Value_EPT_INV_2_Value_EPT, sizeof(INV_2_Value_EPT));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_INV_3_Value_EPT_INV_3_Value_EPT->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_10ms_INV_3_Value_EPT_INV_3_Value_EPT, sizeof(INV_3_Value_EPT));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_INV_4_Value_EPT_INV_4_Value_EPT->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_10ms_INV_4_Value_EPT_INV_4_Value_EPT, sizeof(INV_4_Value_EPT));
        rte_memcpy((uint8*)&Irv_AppSwcIpm_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV, (uint8*)&Irv_AppSwcIpm_CANCommCRCFlt_outputsIRV, sizeof(DT_CANCommCRCFlt));
        rte_memcpy((uint8*)&Irv_AppSwcIpm_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV, (uint8*)&Irv_AppSwcIpm_MsgActv_outputsIRV, sizeof(DT_MsgActv));
        ResumeAllInterrupts();
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
static void Rte_PRE_Runbl_IpmCanRx_20ms(void)
{
    if (RteInitState == RTE_INITED)
    {
        SuspendAllInterrupts();
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_BMS_10_DC_ChargeStates_EPT_BMS_10_DC_ChargeStates_EPT->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_20ms_BMS_10_DC_ChargeStates_EPT_BMS_10_DC_ChargeStates_EPT, sizeof(BMS_10_DC_ChargeStates_EPT));
        BMS_1_MainState_EPT Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT_data;
        uint8 Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT_ret = E_OK;
        if (E_OK == Com_ReceiveSignalGroup(BMS_1_MainState_EPT_IPDU_COM_RX_BMS_1_MainState_EPT_CANFD6_EPT_CAN2))
        {
            if (E_NOT_OK == Com_ReceiveSignal(BMS_1_MainState_EPT_IPDU_COM_RX_BMS_1_MainState_EPT_CANFD6_EPT_CAN2_BMS_1_Chksum_IPDU_COM_RX_BMS_1_MainState_EPT_CANFD6_EPT_CAN2, &Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT_data.BMS_1_Chksum))
            {
                Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_1_MainState_EPT_IPDU_COM_RX_BMS_1_MainState_EPT_CANFD6_EPT_CAN2_BMS_1_AliveCnt_IPDU_COM_RX_BMS_1_MainState_EPT_CANFD6_EPT_CAN2, &Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT_data.BMS_1_AliveCnt))
            {
                Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_1_MainState_EPT_IPDU_COM_RX_BMS_1_MainState_EPT_CANFD6_EPT_CAN2_BMS_ThermalrunawayWrn_IPDU_COM_RX_BMS_1_MainState_EPT_CANFD6_EPT_CAN2, &Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT_data.BMS_ThermalrunawayWrn))
            {
                Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_1_MainState_EPT_IPDU_COM_RX_BMS_1_MainState_EPT_CANFD6_EPT_CAN2_BMS_InsulationWrningDistgsh_IPDU_COM_RX_BMS_1_MainState_EPT_CANFD6_EPT_CAN2, &Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT_data.BMS_InsulationWrningDistgsh))
            {
                Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_1_MainState_EPT_IPDU_COM_RX_BMS_1_MainState_EPT_CANFD6_EPT_CAN2_BMS_ActlExchgCurnt_IPDU_COM_RX_BMS_1_MainState_EPT_CANFD6_EPT_CAN2, &Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT_data.BMS_ActlExchgCurnt))
            {
                Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_1_MainState_EPT_IPDU_COM_RX_BMS_1_MainState_EPT_CANFD6_EPT_CAN2_BMS_SupplyVoltageStatus_IPDU_COM_RX_BMS_1_MainState_EPT_CANFD6_EPT_CAN2, &Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT_data.BMS_SupplyVoltageStatus))
            {
                Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_1_MainState_EPT_IPDU_COM_RX_BMS_1_MainState_EPT_CANFD6_EPT_CAN2_BMS_Contactor_state_Precharge_IPDU_COM_RX_BMS_1_MainState_EPT_CANFD6_EPT_CAN2, &Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT_data.BMS_Contactor_state_Precharge))
            {
                Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_1_MainState_EPT_IPDU_COM_RX_BMS_1_MainState_EPT_CANFD6_EPT_CAN2_BMS_Contactor_state_Positive_IPDU_COM_RX_BMS_1_MainState_EPT_CANFD6_EPT_CAN2, &Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT_data.BMS_Contactor_state_Positive))
            {
                Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_1_MainState_EPT_IPDU_COM_RX_BMS_1_MainState_EPT_CANFD6_EPT_CAN2_BMS_Contactor_state_Negative_IPDU_COM_RX_BMS_1_MainState_EPT_CANFD6_EPT_CAN2, &Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT_data.BMS_Contactor_state_Negative))
            {
                Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_1_MainState_EPT_IPDU_COM_RX_BMS_1_MainState_EPT_CANFD6_EPT_CAN2_BMS_RunState_IPDU_COM_RX_BMS_1_MainState_EPT_CANFD6_EPT_CAN2, &Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT_data.BMS_RunState))
            {
                Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_1_MainState_EPT_IPDU_COM_RX_BMS_1_MainState_EPT_CANFD6_EPT_CAN2_BMS_DisChargeInterlockSta_IPDU_COM_RX_BMS_1_MainState_EPT_CANFD6_EPT_CAN2, &Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT_data.BMS_DisChargeInterlockSta))
            {
                Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_1_MainState_EPT_IPDU_COM_RX_BMS_1_MainState_EPT_CANFD6_EPT_CAN2_BMS_ChargeInterlockSta_IPDU_COM_RX_BMS_1_MainState_EPT_CANFD6_EPT_CAN2, &Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT_data.BMS_ChargeInterlockSta))
            {
                Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_1_MainState_EPT_IPDU_COM_RX_BMS_1_MainState_EPT_CANFD6_EPT_CAN2_BMS_Emeshutdown_Req_IPDU_COM_RX_BMS_1_MainState_EPT_CANFD6_EPT_CAN2, &Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT_data.BMS_Emeshutdown_Req))
            {
                Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_1_MainState_EPT_IPDU_COM_RX_BMS_1_MainState_EPT_CANFD6_EPT_CAN2_BMS_PwrTrainConnectSta_IPDU_COM_RX_BMS_1_MainState_EPT_CANFD6_EPT_CAN2, &Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT_data.BMS_PwrTrainConnectSta))
            {
                Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_1_MainState_EPT_IPDU_COM_RX_BMS_1_MainState_EPT_CANFD6_EPT_CAN2_BMS_ThermRunawayVlvSt_IPDU_COM_RX_BMS_1_MainState_EPT_CANFD6_EPT_CAN2, &Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT_data.BMS_ThermRunawayVlvSt))
            {
                Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_1_MainState_EPT_IPDU_COM_RX_BMS_1_MainState_EPT_CANFD6_EPT_CAN2_BMS_ThermRunawaySnsrFlt_IPDU_COM_RX_BMS_1_MainState_EPT_CANFD6_EPT_CAN2, &Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT_data.BMS_ThermRunawaySnsrFlt))
            {
                Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_1_MainState_EPT_IPDU_COM_RX_BMS_1_MainState_EPT_CANFD6_EPT_CAN2_BMS_Batt_BalanceSta_IPDU_COM_RX_BMS_1_MainState_EPT_CANFD6_EPT_CAN2, &Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT_data.BMS_Batt_BalanceSta))
            {
                Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_1_MainState_EPT_IPDU_COM_RX_BMS_1_MainState_EPT_CANFD6_EPT_CAN2_BMS_SysFailSta_IPDU_COM_RX_BMS_1_MainState_EPT_CANFD6_EPT_CAN2, &Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT_data.BMS_SysFailSta))
            {
                Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT_ret = E_NOT_OK;
            }
            if (E_OK == Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT_ret)
            {
                Rte_Buf_Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT = Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT_data;
                Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT->status = RTE_E_OK;
            }
        }
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT, sizeof(BMS_1_MainState_EPT));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_BMS_2_BatState_EPT_BMS_2_BatState_EPT->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_20ms_BMS_2_BatState_EPT_BMS_2_BatState_EPT, sizeof(BMS_2_BatState_EPT));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_BMS_3_DC_ChargeState_EPT_BMS_3_DC_ChargeState_EPT->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_20ms_BMS_3_DC_ChargeState_EPT_BMS_3_DC_ChargeState_EPT, sizeof(BMS_3_DC_ChargeState_EPT));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_BMS_4_AC_ChargeState_EPT_BMS_4_AC_ChargeState_EPT->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_20ms_BMS_4_AC_ChargeState_EPT_BMS_4_AC_ChargeState_EPT, sizeof(BMS_4_AC_ChargeState_EPT));
        BMS_6_DischrgRecup_EPT Runbl_IpmCanRx_20ms_BMS_6_DischrgRecup_EPT_BMS_6_DischrgRecup_EPT_data;
        uint8 Runbl_IpmCanRx_20ms_BMS_6_DischrgRecup_EPT_BMS_6_DischrgRecup_EPT_ret = E_OK;
        if (E_OK == Com_ReceiveSignalGroup(BMS_6_DischrgRecup_EPT_IPDU_COM_RX_BMS_6_DischrgRecup_EPT_CANFD6_EPT_CAN2))
        {
            if (E_NOT_OK == Com_ReceiveSignal(BMS_6_DischrgRecup_EPT_IPDU_COM_RX_BMS_6_DischrgRecup_EPT_CANFD6_EPT_CAN2_BMS_MaxConDisCurnt_IPDU_COM_RX_BMS_6_DischrgRecup_EPT_CANFD6_EPT_CAN2, &Runbl_IpmCanRx_20ms_BMS_6_DischrgRecup_EPT_BMS_6_DischrgRecup_EPT_data.BMS_MaxConDisCurnt))
            {
                Runbl_IpmCanRx_20ms_BMS_6_DischrgRecup_EPT_BMS_6_DischrgRecup_EPT_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_6_DischrgRecup_EPT_IPDU_COM_RX_BMS_6_DischrgRecup_EPT_CANFD6_EPT_CAN2_BMS_PwrRecupMaxConChrgCurnt_IPDU_COM_RX_BMS_6_DischrgRecup_EPT_CANFD6_EPT_CAN2, &Runbl_IpmCanRx_20ms_BMS_6_DischrgRecup_EPT_BMS_6_DischrgRecup_EPT_data.BMS_PwrRecupMaxConChrgCurnt))
            {
                Runbl_IpmCanRx_20ms_BMS_6_DischrgRecup_EPT_BMS_6_DischrgRecup_EPT_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_6_DischrgRecup_EPT_IPDU_COM_RX_BMS_6_DischrgRecup_EPT_CANFD6_EPT_CAN2_BMS_MaxInstanDisCurnt_IPDU_COM_RX_BMS_6_DischrgRecup_EPT_CANFD6_EPT_CAN2, &Runbl_IpmCanRx_20ms_BMS_6_DischrgRecup_EPT_BMS_6_DischrgRecup_EPT_data.BMS_MaxInstanDisCurnt))
            {
                Runbl_IpmCanRx_20ms_BMS_6_DischrgRecup_EPT_BMS_6_DischrgRecup_EPT_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_6_DischrgRecup_EPT_IPDU_COM_RX_BMS_6_DischrgRecup_EPT_CANFD6_EPT_CAN2_BMS_PwrRecupMaxInstanChrgCurnt_IPDU_COM_RX_BMS_6_DischrgRecup_EPT_CANFD6_EPT_CAN2, &Runbl_IpmCanRx_20ms_BMS_6_DischrgRecup_EPT_BMS_6_DischrgRecup_EPT_data.BMS_PwrRecupMaxInstanChrgCurnt))
            {
                Runbl_IpmCanRx_20ms_BMS_6_DischrgRecup_EPT_BMS_6_DischrgRecup_EPT_ret = E_NOT_OK;
            }
            if (E_OK == Runbl_IpmCanRx_20ms_BMS_6_DischrgRecup_EPT_BMS_6_DischrgRecup_EPT_ret)
            {
                Rte_Buf_Runbl_IpmCanRx_20ms_BMS_6_DischrgRecup_EPT_BMS_6_DischrgRecup_EPT = Runbl_IpmCanRx_20ms_BMS_6_DischrgRecup_EPT_BMS_6_DischrgRecup_EPT_data;
                Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_BMS_6_DischrgRecup_EPT_BMS_6_DischrgRecup_EPT->status = RTE_E_OK;
            }
        }
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_BMS_6_DischrgRecup_EPT_BMS_6_DischrgRecup_EPT->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_20ms_BMS_6_DischrgRecup_EPT_BMS_6_DischrgRecup_EPT, sizeof(BMS_6_DischrgRecup_EPT));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_BMS_7_CellVolt_EPT_BMS_7_CellVolt_EPT->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_20ms_BMS_7_CellVolt_EPT_BMS_7_CellVolt_EPT, sizeof(BMS_7_CellVolt_EPT));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_CRRR_A_CHA_CRRR_A_CHA->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_20ms_CRRR_A_CHA_CRRR_A_CHA, sizeof(CRRR_A_CHA));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA, sizeof(EHB_A_CHA));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA, sizeof(FCM_B_CHA));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD, sizeof(SCS_RiSwitchSts_BOD));
        rte_memcpy((uint8*)&Irv_AppSwcIpm_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV, (uint8*)&Irv_AppSwcIpm_CANCommCRCFlt_outputsIRV, sizeof(DT_CANCommCRCFlt));
        rte_memcpy((uint8*)&Irv_AppSwcIpm_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV, (uint8*)&Irv_AppSwcIpm_MsgActv_outputsIRV, sizeof(DT_MsgActv));
        ResumeAllInterrupts();
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
static void Rte_PRE_Runbl_IpmCanRx_50ms(void)
{
    if (RteInitState == RTE_INITED)
    {
        SuspendAllInterrupts();
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD, sizeof(CCP_PanelStatus_BOD));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_50ms_ESCL_ESCLStatus_BOD_ESCL_ESCLStatus_BOD->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_50ms_ESCL_ESCLStatus_BOD_ESCL_ESCLStatus_BOD, sizeof(ESCL_ESCLStatus_BOD));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD, sizeof(SCS_LeSwitchSts_BOD));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA, sizeof(SRS_1_Status_CHA));
        rte_memcpy((uint8*)&Irv_AppSwcIpm_Runbl_IpmCanRx_50ms_CANCommCRCFlt_outputsIRV, (uint8*)&Irv_AppSwcIpm_CANCommCRCFlt_outputsIRV, sizeof(DT_CANCommCRCFlt));
        rte_memcpy((uint8*)&Irv_AppSwcIpm_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV, (uint8*)&Irv_AppSwcIpm_MsgActv_outputsIRV, sizeof(DT_MsgActv));
        ResumeAllInterrupts();
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
static void Rte_PRE_Runbl_IpmMsgActv_10ms(void)
{
    if (RteInitState == RTE_INITED)
    {
        SuspendAllInterrupts();
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs->value), (uint8*)&Rte_Buf_Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs, sizeof(DAG_Comm_outputs));
        ResumeAllInterrupts();
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
static void Rte_POST_Runbl_IpmCanRx_100ms(void)
{
    if (RteInitState == RTE_INITED)
    {
        SuspendAllInterrupts();
        Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_100ms_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT->value);
        Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_100ms_IPM_BMS_9_BattInfo_EPT_IPM_BMS_9_BattInfo_EPT(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPM_BMS_9_BattInfo_EPT_IPM_BMS_9_BattInfo_EPT->value);
        Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_100ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD->value);
        Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC->value);
        Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD->value);
        Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD->value);
        Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_100ms_IPM_INV_IMMO_Req_EPT_IPM_INV_IMMO_Req_EPT(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPM_INV_IMMO_Req_EPT_IPM_INV_IMMO_Req_EPT->value);
        Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_100ms_IPM_IPU_DCC_1_State_EPT_IPM_IPU_DCC_1_State_EPT(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPM_IPU_DCC_1_State_EPT_IPM_IPU_DCC_1_State_EPT->value);
        Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_100ms_IPM_IPU_DCC_2_ChrgInValue_EPT_IPM_IPU_DCC_2_ChrgInValue_EPT(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPM_IPU_DCC_2_ChrgInValue_EPT_IPM_IPU_DCC_2_ChrgInValue_EPT->value);
        Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_100ms_IPM_IPU_OBC_1_State_EPT_IPM_IPU_OBC_1_State_EPT(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPM_IPU_OBC_1_State_EPT_IPM_IPU_OBC_1_State_EPT->value);
        Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_100ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT->value);
        Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_100ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC->value);
        ResumeAllInterrupts();
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
static void Rte_POST_Runbl_IpmCanRx_10ms(void)
{
    if (RteInitState == RTE_INITED)
    {
        SuspendAllInterrupts();
        Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_10ms_IPM_EHB_B_CHA_IPM_EHB_B_CHA(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_IPM_EHB_B_CHA_IPM_EHB_B_CHA->value);
        Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_10ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA->value);
        Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_10ms_IPM_ESC_A_CHA_IPM_ESC_A_CHA(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_IPM_ESC_A_CHA_IPM_ESC_A_CHA->value);
        Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_10ms_IPM_INV_1_Value_EPT_IPM_INV_1_Value_EPT(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_IPM_INV_1_Value_EPT_IPM_INV_1_Value_EPT->value);
        Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_10ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT->value);
        Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_10ms_IPM_INV_3_Value_EPT_IPM_INV_3_Value_EPT(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_IPM_INV_3_Value_EPT_IPM_INV_3_Value_EPT->value);
        Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_10ms_IPM_INV_4_Value_EPT_IPM_INV_4_Value_EPT(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_IPM_INV_4_Value_EPT_IPM_INV_4_Value_EPT->value);
        ResumeAllInterrupts();
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
static void Rte_POST_Runbl_IpmCanRx_20ms(void)
{
    if (RteInitState == RTE_INITED)
    {
        SuspendAllInterrupts();
        Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_20ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT->value);
        Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_20ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT->value);
        Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_20ms_IPM_BMS_2_BatState_EPT_IPM_BMS_2_BatState_EPT(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_IPM_BMS_2_BatState_EPT_IPM_BMS_2_BatState_EPT->value);
        Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_20ms_IPM_BMS_3_DC_ChargeState_EPT_IPM_BMS_3_DC_ChargeState_EPT(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_IPM_BMS_3_DC_ChargeState_EPT_IPM_BMS_3_DC_ChargeState_EPT->value);
        Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_20ms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT->value);
        Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_20ms_IPM_BMS_6_DischrgRecup_EPT_IPM_BMS_6_DischrgRecup_EPT(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_IPM_BMS_6_DischrgRecup_EPT_IPM_BMS_6_DischrgRecup_EPT->value);
        Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_20ms_IPM_BMS_7_CellVolt_EPT_IPM_BMS_7_CellVolt_EPT(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_IPM_BMS_7_CellVolt_EPT_IPM_BMS_7_CellVolt_EPT->value);
        Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA->value);
        Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_20ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA->value);
        Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_20ms_IPM_FCM_B_CHA_IPM_FCM_B_CHA(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_IPM_FCM_B_CHA_IPM_FCM_B_CHA->value);
        Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_20ms_IPM_SCS_RiSwitchSts_BOD_IPM_SCS_RiSwitchSts_BOD(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_IPM_SCS_RiSwitchSts_BOD_IPM_SCS_RiSwitchSts_BOD->value);
        ResumeAllInterrupts();
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
static void Rte_POST_Runbl_IpmCanRx_50ms(void)
{
    if (RteInitState == RTE_INITED)
    {
        SuspendAllInterrupts();
        Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_50ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_50ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD->value);
        Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_50ms_IPM_ESCL_ESCLStatus_BOD_IPM_ESCL_ESCLStatus_BOD(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_50ms_IPM_ESCL_ESCLStatus_BOD_IPM_ESCL_ESCLStatus_BOD->value);
        Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_50ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_50ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD->value);
        Rte_WriteBuffer_Rte_Buf_Runbl_IpmCanRx_50ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_50ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA->value);
        ResumeAllInterrupts();
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
static void Rte_POST_Runbl_IpmMsgActv_10ms(void)
{
    if (RteInitState == RTE_INITED)
    {
        SuspendAllInterrupts();
        Rte_WriteBuffer_Rte_Buf_Runbl_IpmMsgActv_10ms_CANCommCRCFlt_outputs_CANCommCRCFlt_outputs(Rte_Inst_AppSwcIpm.Runbl_IpmMsgActv_10ms_CANCommCRCFlt_outputs_CANCommCRCFlt_outputs->value);
        Rte_WriteBuffer_Rte_Buf_Runbl_IpmMsgActv_10ms_CANCommErr_outputs_CANCommErr_outputs(Rte_Inst_AppSwcIpm.Runbl_IpmMsgActv_10ms_CANCommErr_outputs_CANCommErr_outputs->value);
        Rte_WriteBuffer_Rte_Buf_Runbl_IpmMsgActv_10ms_MsgActv_outputs_MsgActv_outputs(Rte_Inst_AppSwcIpm.Runbl_IpmMsgActv_10ms_MsgActv_outputs_MsgActv_outputs->value);
        rte_memcpy((uint8*)&Irv_AppSwcIpm_CANCommCRCFlt_outputsIRV, (uint8*)&Irv_AppSwcIpm_Runbl_IpmMsgActv_10ms_CANCommCRCFlt_outputsIRV, sizeof(DT_CANCommCRCFlt));
        rte_memcpy((uint8*)&Irv_AppSwcIpm_MsgActv_outputsIRV, (uint8*)&Irv_AppSwcIpm_Runbl_IpmMsgActv_10ms_MsgActv_outputsIRV, sizeof(DT_MsgActv));
        ResumeAllInterrupts();
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
 **                        Global Function Definitions                        **
******************************************************************************/

/*******************************************************************************
*Function-Name        Runbl_IpmCanRx_100ms
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
void Rte_Runbl_IpmCanRx_100ms(void)
{
    Rte_PRE_Runbl_IpmCanRx_100ms();
    if (RteInitState == RTE_INITED)
    {
        Runbl_IpmCanRx_100ms();
    }
    Rte_POST_Runbl_IpmCanRx_100ms();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Runbl_IpmCanRx_10ms
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
void Rte_Runbl_IpmCanRx_10ms(void)
{
    Rte_PRE_Runbl_IpmCanRx_10ms();
    if (RteInitState == RTE_INITED)
    {
        Runbl_IpmCanRx_10ms();
    }
    Rte_POST_Runbl_IpmCanRx_10ms();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Runbl_IpmCanRx_20ms
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
void Rte_Runbl_IpmCanRx_20ms(void)
{
    Rte_PRE_Runbl_IpmCanRx_20ms();
    if (RteInitState == RTE_INITED)
    {
        Runbl_IpmCanRx_20ms();
    }
    Rte_POST_Runbl_IpmCanRx_20ms();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Runbl_IpmCanRx_50ms
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
void Rte_Runbl_IpmCanRx_50ms(void)
{
    Rte_PRE_Runbl_IpmCanRx_50ms();
    if (RteInitState == RTE_INITED)
    {
        Runbl_IpmCanRx_50ms();
    }
    Rte_POST_Runbl_IpmCanRx_50ms();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Runbl_IpmMsgActv_10ms
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
void Rte_Runbl_IpmMsgActv_10ms(void)
{
    Rte_PRE_Runbl_IpmMsgActv_10ms();
    if (RteInitState == RTE_INITED)
    {
        Runbl_IpmMsgActv_10ms();
    }
    Rte_POST_Runbl_IpmMsgActv_10ms();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        AppSwcIpm_Init
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
void Rte_AppSwcIpm_Init(void)
{
    if (RteInitState == RTE_INITED)
    {
        AppSwcIpm_Init();
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_CANCommCRCFlt*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_CANCommCRCFlt* Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV(void)
{
    return &Irv_AppSwcIpm_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_CANCommCRCFlt*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_CANCommCRCFlt* Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV(void)
{
    return &Irv_AppSwcIpm_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_CANCommCRCFlt*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_CANCommCRCFlt* Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV(void)
{
    return &Irv_AppSwcIpm_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_IpmCanRx_50ms_CANCommCRCFlt_outputsIRV
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_CANCommCRCFlt*
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_CANCommCRCFlt* Rte_IrvIRead_Runbl_IpmCanRx_50ms_CANCommCRCFlt_outputsIRV(void)
{
    return &Irv_AppSwcIpm_Runbl_IpmCanRx_50ms_CANCommCRCFlt_outputsIRV;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_IpmMsgActv_10ms_CANCommCRCFlt_outputsIRV
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
void Rte_IrvIWrite_Runbl_IpmMsgActv_10ms_CANCommCRCFlt_outputsIRV(DT_CANCommCRCFlt* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcIpm_Runbl_IpmMsgActv_10ms_CANCommCRCFlt_outputsIRV, (uint8*)data, sizeof(DT_CANCommCRCFlt));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_IpmMsgActv_10ms_CANCommCRCFlt_outputsIRV
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               DT_CANCommCRCFlt *
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
DT_CANCommCRCFlt * Rte_IrvIWriteRef_Runbl_IpmMsgActv_10ms_CANCommCRCFlt_outputsIRV(void)
{
    return &Irv_AppSwcIpm_Runbl_IpmMsgActv_10ms_CANCommCRCFlt_outputsIRV;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV
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
DT_MsgActv* Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV(void)
{
    return &Irv_AppSwcIpm_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV
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
DT_MsgActv* Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV(void)
{
    return &Irv_AppSwcIpm_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV
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
DT_MsgActv* Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV(void)
{
    return &Irv_AppSwcIpm_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV
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
DT_MsgActv* Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV(void)
{
    return &Irv_AppSwcIpm_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWrite_Runbl_IpmMsgActv_10ms_MsgActv_outputsIRV
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
void Rte_IrvIWrite_Runbl_IpmMsgActv_10ms_MsgActv_outputsIRV(DT_MsgActv* data)
{
    if (RteInitState == RTE_INITED)
    {
        rte_memcpy((uint8*)&Irv_AppSwcIpm_Runbl_IpmMsgActv_10ms_MsgActv_outputsIRV, (uint8*)data, sizeof(DT_MsgActv));
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IrvIWriteRef_Runbl_IpmMsgActv_10ms_MsgActv_outputsIRV
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
DT_MsgActv * Rte_IrvIWriteRef_Runbl_IpmMsgActv_10ms_MsgActv_outputsIRV(void)
{
    return &Irv_AppSwcIpm_Runbl_IpmMsgActv_10ms_MsgActv_outputsIRV;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_IpmCanRx_100ms_ACCM_Version_BOD_ACCM_Version_BOD
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
Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_100ms_ACCM_Version_BOD_ACCM_Version_BOD(void)
{
    return Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_ACCM_Version_BOD_ACCM_Version_BOD->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_IpmCanRx_100ms_BMS_5_BatTemp_EPT_BMS_5_BatTemp_EPT
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
Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_100ms_BMS_5_BatTemp_EPT_BMS_5_BatTemp_EPT(void)
{
    return Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_BMS_5_BatTemp_EPT_BMS_5_BatTemp_EPT->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_IpmCanRx_100ms_BMS_9_BattInfo_EPT_BMS_9_BattInfo_EPT
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
Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_100ms_BMS_9_BattInfo_EPT_BMS_9_BattInfo_EPT(void)
{
    return Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_BMS_9_BattInfo_EPT_BMS_9_BattInfo_EPT->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD
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
Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD(void)
{
    return Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC
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
Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC(void)
{
    return Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_IpmCanRx_100ms_HVCH_Status1_BOD_HVCH_Status1_BOD
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
Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_100ms_HVCH_Status1_BOD_HVCH_Status1_BOD(void)
{
    return Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_HVCH_Status1_BOD_HVCH_Status1_BOD->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_IpmCanRx_100ms_HVCH_Status2_BOD_HVCH_Status2_BOD
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
Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_100ms_HVCH_Status2_BOD_HVCH_Status2_BOD(void)
{
    return Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_HVCH_Status2_BOD_HVCH_Status2_BOD->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_IpmCanRx_100ms_INV_IMMO_Req_EPT_INV_IMMO_Req_EPT
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
Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_100ms_INV_IMMO_Req_EPT_INV_IMMO_Req_EPT(void)
{
    return Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_INV_IMMO_Req_EPT_INV_IMMO_Req_EPT->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_IpmCanRx_100ms_IPU_DCC_1_State_EPT_IPU_DCC_1_State_EPT
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
Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_100ms_IPU_DCC_1_State_EPT_IPU_DCC_1_State_EPT(void)
{
    return Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPU_DCC_1_State_EPT_IPU_DCC_1_State_EPT->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_IpmCanRx_100ms_IPU_DCC_2_ChrgInValue_EPT_IPU_DCC_2_ChrgInValue_EPT
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
Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_100ms_IPU_DCC_2_ChrgInValue_EPT_IPU_DCC_2_ChrgInValue_EPT(void)
{
    return Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPU_DCC_2_ChrgInValue_EPT_IPU_DCC_2_ChrgInValue_EPT->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_IpmCanRx_100ms_IPU_OBC_1_State_EPT_IPU_OBC_1_State_EPT
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
Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_100ms_IPU_OBC_1_State_EPT_IPU_OBC_1_State_EPT(void)
{
    return Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPU_OBC_1_State_EPT_IPU_OBC_1_State_EPT->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_IpmCanRx_100ms_IPU_OBC_2_Inlet_EPT_IPU_OBC_2_Inlet_EPT
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
Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_100ms_IPU_OBC_2_Inlet_EPT_IPU_OBC_2_Inlet_EPT(void)
{
    return Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPU_OBC_2_Inlet_EPT_IPU_OBC_2_Inlet_EPT->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_IpmCanRx_100ms_TBOX_BJS_Time_BAC_TBOX_BJS_Time_BAC
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
Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_100ms_TBOX_BJS_Time_BAC_TBOX_BJS_Time_BAC(void)
{
    return Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_TBOX_BJS_Time_BAC_TBOX_BJS_Time_BAC->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA
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
Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA(void)
{
    return Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_IpmCanRx_10ms_EPS_2_StrWhlAng_CHA_EPS_2_StrWhlAng_CHA
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
Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_10ms_EPS_2_StrWhlAng_CHA_EPS_2_StrWhlAng_CHA(void)
{
    return Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_EPS_2_StrWhlAng_CHA_EPS_2_StrWhlAng_CHA->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_IpmCanRx_10ms_ESC_7_FuncStatus_CHA_ESC_7_FuncStatus_CHA
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
Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_10ms_ESC_7_FuncStatus_CHA_ESC_7_FuncStatus_CHA(void)
{
    return Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_ESC_7_FuncStatus_CHA_ESC_7_FuncStatus_CHA->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA
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
Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA(void)
{
    return Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_IpmCanRx_10ms_INV_1_Value_EPT_INV_1_Value_EPT
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
Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_10ms_INV_1_Value_EPT_INV_1_Value_EPT(void)
{
    return Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_INV_1_Value_EPT_INV_1_Value_EPT->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_IpmCanRx_10ms_INV_2_Value_EPT_INV_2_Value_EPT
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
Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_10ms_INV_2_Value_EPT_INV_2_Value_EPT(void)
{
    return Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_INV_2_Value_EPT_INV_2_Value_EPT->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_IpmCanRx_10ms_INV_3_Value_EPT_INV_3_Value_EPT
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
Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_10ms_INV_3_Value_EPT_INV_3_Value_EPT(void)
{
    return Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_INV_3_Value_EPT_INV_3_Value_EPT->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_IpmCanRx_10ms_INV_4_Value_EPT_INV_4_Value_EPT
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
Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_10ms_INV_4_Value_EPT_INV_4_Value_EPT(void)
{
    return Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_INV_4_Value_EPT_INV_4_Value_EPT->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_IpmCanRx_20ms_BMS_10_DC_ChargeStates_EPT_BMS_10_DC_ChargeStates_EPT
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
Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_20ms_BMS_10_DC_ChargeStates_EPT_BMS_10_DC_ChargeStates_EPT(void)
{
    return Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_BMS_10_DC_ChargeStates_EPT_BMS_10_DC_ChargeStates_EPT->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT
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
Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT(void)
{
    return Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_IpmCanRx_20ms_BMS_2_BatState_EPT_BMS_2_BatState_EPT
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
Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_20ms_BMS_2_BatState_EPT_BMS_2_BatState_EPT(void)
{
    return Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_BMS_2_BatState_EPT_BMS_2_BatState_EPT->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_IpmCanRx_20ms_BMS_3_DC_ChargeState_EPT_BMS_3_DC_ChargeState_EPT
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
Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_20ms_BMS_3_DC_ChargeState_EPT_BMS_3_DC_ChargeState_EPT(void)
{
    return Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_BMS_3_DC_ChargeState_EPT_BMS_3_DC_ChargeState_EPT->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_IpmCanRx_20ms_BMS_4_AC_ChargeState_EPT_BMS_4_AC_ChargeState_EPT
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
Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_20ms_BMS_4_AC_ChargeState_EPT_BMS_4_AC_ChargeState_EPT(void)
{
    return Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_BMS_4_AC_ChargeState_EPT_BMS_4_AC_ChargeState_EPT->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_IpmCanRx_20ms_BMS_6_DischrgRecup_EPT_BMS_6_DischrgRecup_EPT
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
Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_20ms_BMS_6_DischrgRecup_EPT_BMS_6_DischrgRecup_EPT(void)
{
    return Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_BMS_6_DischrgRecup_EPT_BMS_6_DischrgRecup_EPT->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_IpmCanRx_20ms_BMS_7_CellVolt_EPT_BMS_7_CellVolt_EPT
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
Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_20ms_BMS_7_CellVolt_EPT_BMS_7_CellVolt_EPT(void)
{
    return Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_BMS_7_CellVolt_EPT_BMS_7_CellVolt_EPT->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_IpmCanRx_20ms_CRRR_A_CHA_CRRR_A_CHA
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
Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_20ms_CRRR_A_CHA_CRRR_A_CHA(void)
{
    return Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_CRRR_A_CHA_CRRR_A_CHA->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA
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
Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA(void)
{
    return Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA
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
Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA(void)
{
    return Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD
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
Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD(void)
{
    return Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD
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
Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD(void)
{
    return Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_IpmCanRx_50ms_ESCL_ESCLStatus_BOD_ESCL_ESCLStatus_BOD
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
Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_50ms_ESCL_ESCLStatus_BOD_ESCL_ESCLStatus_BOD(void)
{
    return Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_50ms_ESCL_ESCLStatus_BOD_ESCL_ESCLStatus_BOD->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD
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
Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD(void)
{
    return Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA
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
Std_ReturnType Rte_IStatus_Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA(void)
{
    return Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_IStatus_Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs
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
Std_ReturnType Rte_IStatus_Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs(void)
{
    return Rte_Inst_AppSwcIpm.Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs->status;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

