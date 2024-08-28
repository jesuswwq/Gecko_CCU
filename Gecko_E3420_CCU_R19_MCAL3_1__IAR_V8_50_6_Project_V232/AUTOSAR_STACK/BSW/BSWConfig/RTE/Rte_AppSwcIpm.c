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
 *  @date       <2024-08-07 15:08:48>
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
        EHB_B_CHA Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_data;
        uint8 Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_ret = E_OK;
        if (E_OK == Com_ReceiveSignalGroup(EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5))
        {
            if (E_NOT_OK == Com_ReceiveSignal(EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_B_Chksum1_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_data.EHB_B_Chksum1))
            {
                Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_B_AliveCnt1_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_data.EHB_B_AliveCnt1))
            {
                Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_PBCInApplyRelsReq_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_data.EHB_PBCInApplyRelsReq))
            {
                Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_PedlTrvlSnsrPlauSta_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_data.EHB_PedlTrvlSnsrPlauSta))
            {
                Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_EPB_DynamicApplySta_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_data.EHB_EPB_DynamicApplySta))
            {
                Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_BrkPedlValPercVld_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_data.EHB_BrkPedlValPercVld))
            {
                Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_PBCRollrBenchActvVldty_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_data.EHB_PBCRollrBenchActvVldty))
            {
                Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_PBCRollrBenchActv_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_data.EHB_PBCRollrBenchActv))
            {
                Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_BrkPedlValVld_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_data.EHB_BrkPedlValVld))
            {
                Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_BrkPedlVal_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_data.EHB_BrkPedlVal))
            {
                Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_BrkPedlValPerc_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_data.EHB_BrkPedlValPerc))
            {
                Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_FaultLevel_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_data.EHB_FaultLevel))
            {
                Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_PedlTrvlSnsrFail_PDT_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_data.EHB_PedlTrvlSnsrFail_PDT))
            {
                Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_ReqBrkLiOn_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_data.EHB_ReqBrkLiOn))
            {
                Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_PedlTrvlSnsrFail_PDF_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_data.EHB_PedlTrvlSnsrFail_PDF))
            {
                Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_B_Chksum2_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_data.EHB_B_Chksum2))
            {
                Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_B_AliveCnt2_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_data.EHB_B_AliveCnt2))
            {
                Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_CDDTempOff_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_data.EHB_CDDTempOff))
            {
                Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_B_Chksum3_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_data.EHB_B_Chksum3))
            {
                Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_B_AliveCnt3_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_data.EHB_B_AliveCnt3))
            {
                Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_BrkPwrRecupTarWhlTq_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_data.EHB_BrkPwrRecupTarWhlTq))
            {
                Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_BrkPwrRecupTarWhlTqSts_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_data.EHB_BrkPwrRecupTarWhlTqSts))
            {
                Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_ABP_ActiveSta_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_data.EHB_ABP_ActiveSta))
            {
                Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_ABP_AvailableSta_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_data.EHB_ABP_AvailableSta))
            {
                Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_NoBrakeForce_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_data.EHB_NoBrakeForce))
            {
                Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_EPB_ActuatorSt_R_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_data.EHB_EPB_ActuatorSt_R))
            {
                Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_CDDAvailable_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_data.EHB_CDDAvailable))
            {
                Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_CDDActive_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_data.EHB_CDDActive))
            {
                Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_ABA_AvailableSta_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_data.EHB_ABA_AvailableSta))
            {
                Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_ABA_ActiveSta_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_data.EHB_ABA_ActiveSta))
            {
                Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_AWB_AvailableSta_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_data.EHB_AWB_AvailableSta))
            {
                Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_AWB_ActiveSta_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_data.EHB_AWB_ActiveSta))
            {
                Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_AEB_AvailableSta_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_data.EHB_AEB_AvailableSta))
            {
                Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_AEB_ActiveSta_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_data.EHB_AEB_ActiveSta))
            {
                Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_ret = E_NOT_OK;
            }
            if (E_OK == Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_ret)
            {
                Rte_Buf_Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA = Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA_data;
                Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA->status = RTE_E_OK;
            }
        }
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
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT, sizeof(BMS_1_MainState_EPT));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_BMS_2_BatState_EPT_BMS_2_BatState_EPT->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_20ms_BMS_2_BatState_EPT_BMS_2_BatState_EPT, sizeof(BMS_2_BatState_EPT));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_BMS_3_DC_ChargeState_EPT_BMS_3_DC_ChargeState_EPT->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_20ms_BMS_3_DC_ChargeState_EPT_BMS_3_DC_ChargeState_EPT, sizeof(BMS_3_DC_ChargeState_EPT));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_BMS_4_AC_ChargeState_EPT_BMS_4_AC_ChargeState_EPT->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_20ms_BMS_4_AC_ChargeState_EPT_BMS_4_AC_ChargeState_EPT, sizeof(BMS_4_AC_ChargeState_EPT));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_BMS_6_DischrgRecup_EPT_BMS_6_DischrgRecup_EPT->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_20ms_BMS_6_DischrgRecup_EPT_BMS_6_DischrgRecup_EPT, sizeof(BMS_6_DischrgRecup_EPT));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_BMS_7_CellVolt_EPT_BMS_7_CellVolt_EPT->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_20ms_BMS_7_CellVolt_EPT_BMS_7_CellVolt_EPT, sizeof(BMS_7_CellVolt_EPT));
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_CRRR_A_CHA_CRRR_A_CHA->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_20ms_CRRR_A_CHA_CRRR_A_CHA, sizeof(CRRR_A_CHA));
        EHB_A_CHA Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_data;
        uint8 Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_ret = E_OK;
        if (E_OK == Com_ReceiveSignalGroup(EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5))
        {
            if (E_NOT_OK == Com_ReceiveSignal(EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_A_Chksum_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_data.EHB_A_Chksum))
            {
                Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_A_AliveCnt_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_data.EHB_A_AliveCnt))
            {
                Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_BrkDisWipAc_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_data.EHB_BrkDisWipAc))
            {
                Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_AVHDispMSG_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_data.EHB_AVHDispMSG))
            {
                Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_CDPRequest_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_data.EHB_CDPRequest))
            {
                Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_EPB_ActuatorSt_L_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_data.EHB_EPB_ActuatorSt_L))
            {
                Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_EPB_WarnLampSta_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_data.EHB_EPB_WarnLampSta))
            {
                Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_EPB_FltSts_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_data.EHB_EPB_FltSts))
            {
                Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_EPB_RequestEcho_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_data.EHB_EPB_RequestEcho))
            {
                Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_EPB_ParkLampSta_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_data.EHB_EPB_ParkLampSta))
            {
                Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_EPB_Left_FailStatus_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_data.EHB_EPB_Left_FailStatus))
            {
                Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_EPB_SwitchSts_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_data.EHB_EPB_SwitchSts))
            {
                Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_EPB_SystemState_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_data.EHB_EPB_SystemState))
            {
                Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_EPB_DisplayMsgID_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_data.EHB_EPB_DisplayMsgID))
            {
                Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_ExtReqPrio_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_data.EHB_ExtReqPrio))
            {
                Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_HDCFucFault_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_data.EHB_HDCFucFault))
            {
                Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_BBSDfctv_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_data.EHB_BBSDfctv))
            {
                Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_BrakeLiquidLevelWarn_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_data.EHB_BrakeLiquidLevelWarn))
            {
                Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_FailureSts_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_data.EHB_FailureSts))
            {
                Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_EPB_Right_MotComd_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_data.EHB_EPB_Right_MotComd))
            {
                Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_AVHLampReq_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_data.EHB_AVHLampReq))
            {
                Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_HHC_ActiveSta_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_data.EHB_HHC_ActiveSta))
            {
                Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_RgnBrkSt_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_data.EHB_RgnBrkSt))
            {
                Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_AVHAppldSt_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_data.EHB_AVHAppldSt))
            {
                Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_ExtReqStatus_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_data.EHB_ExtReqStatus))
            {
                Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_BLA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_data.EHB_BLA))
            {
                Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_HMI_WarningOn_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_data.EHB_HMI_WarningOn))
            {
                Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_ret = E_NOT_OK;
            }
            if (E_OK == Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_ret)
            {
                Rte_Buf_Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA = Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA_data;
                Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA->status = RTE_E_OK;
            }
        }
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA, sizeof(EHB_A_CHA));
        FCM_B_CHA Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data;
        uint8 Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_OK;
        if (E_OK == Com_ReceiveSignalGroup(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5))
        {
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_B_Chksum1_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_B_Chksum1))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_B_AliveCnt1_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_B_AliveCnt1))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_LgtFctActvFlg_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_LgtFctActvFlg))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_ELKLaneOverSts_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_ELKLaneOverSts))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_SteerTqReq_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_SteerTqReq))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_ELKMode_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_ELKMode))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_ELKoSts_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_ELKoSts))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_ELKRoadEdgeSts_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_ELKRoadEdgeSts))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_EPSSetSteerWhlAgl_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_EPSSetSteerWhlAgl))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_DAEPSModeReq_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_DAEPSModeReq))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_DrvrWarnVibReq_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_DrvrWarnVibReq))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_EPSCtrlReq_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_EPSCtrlReq))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_SteerTqReqActive_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_SteerTqReqActive))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_B_Chksum2_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_B_Chksum2))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_B_AliveCnt2_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_B_AliveCnt2))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_ActDrvAsstSts_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_ActDrvAsstSts))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_SpdLimKeepDst_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_SpdLimKeepDst))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_TJAICASuppsAbortn_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_TJAICASuppsAbortn))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_TurnLampReq_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_TurnLampReq))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_OvertakeAssSysSts_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_OvertakeAssSysSts))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_LKALDWSuppsAbortn_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_LKALDWSuppsAbortn))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_HMASuppsAbortn_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_HMASuppsAbortn))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_ELKSuppsAbortn_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_ELKSuppsAbortn))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_FltSts_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_FltSts))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_B_Chksum3_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_B_Chksum3))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_B_AliveCnt3_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_B_AliveCnt3))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_ACCWhlTqReqActv_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_ACCWhlTqReqActv))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_ACCWhlTqReqVal_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_ACCWhlTqReqVal))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_ACCWhlDece_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_ACCWhlDece))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_AccTarAccrn_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_AccTarAccrn))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_EPBReqV_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_EPBReqV))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_CrvDecelSta_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_CrvDecelSta))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_AccTarAccrnReqActv_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_AccTarAccrnReqActv))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_ACCSuppAbort_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_ACCSuppAbort))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_EPBReq_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_EPBReq))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_B_Chksum4_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_B_Chksum4))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_B_AliveCnt4_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_B_AliveCnt4))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_AhdObjID_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_AhdObjID))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_AhdObjTyp_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_AhdObjTyp))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_AhdObjLgtRelSpd_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_AhdObjLgtRelSpd))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_AhdObjLatDst_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_AhdObjLatDst))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_AhdObjLgtDst_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_AhdObjLgtDst))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_B_Chksum5_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_B_Chksum5))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_B_AliveCnt5_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_B_AliveCnt5))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_AccTgtAx_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_AccTgtAx))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_AccReqStandstill_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_AccReqStandstill))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_AccReqDriveOff_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_AccReqDriveOff))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_AccTgtAxReq_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_AccTgtAxReq))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_AccMode_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_AccMode))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_AEBTgtAx_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_AEBTgtAx))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_AEBStandstillStsV_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_AEBStandstillStsV))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_AEBStandstillSts_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_AEBStandstillSts))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_AEBReq_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_AEBReq))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_AccPreKeReq_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_AccPreKeReq))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_ABAReq_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_ABAReq))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_EBAReq_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_EBAReq))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_AWBLevel_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_AWBLevel))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_ABALevel_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_ABALevel))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_ABPReq_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_ABPReq))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_AWBReq_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data.FCM_AWBReq))
            {
                Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret = E_NOT_OK;
            }
            if (E_OK == Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_ret)
            {
                Rte_Buf_Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA = Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA_data;
                Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA->status = RTE_E_OK;
            }
        }
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA, sizeof(FCM_B_CHA));
        SCS_RiSwitchSts_BOD Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD_data;
        uint8 Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD_ret = E_OK;
        if (E_OK == Com_ReceiveSignalGroup(SCS_RiSwitchSts_BOD_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6))
        {
            if (E_NOT_OK == Com_ReceiveSignal(SCS_RiSwitchSts_BOD_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6_SCS_RiSwitchSts_Chksum_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6, &Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD_data.SCS_RiSwitchSts_Chksum))
            {
                Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SCS_RiSwitchSts_BOD_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6_SCS_RiSwitchSts_AliveCnt_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6, &Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD_data.SCS_RiSwitchSts_AliveCnt))
            {
                Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SCS_RiSwitchSts_BOD_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6_SCS_Right_9Swt_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6, &Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD_data.SCS_Right_9Swt))
            {
                Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SCS_RiSwitchSts_BOD_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6_SCS_Right_10Swt_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6, &Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD_data.SCS_Right_10Swt))
            {
                Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SCS_RiSwitchSts_BOD_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6_SCS_GearShiftLeverPstReqVD_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6, &Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD_data.SCS_GearShiftLeverPstReqVD))
            {
                Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SCS_RiSwitchSts_BOD_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6_SCS_GearShiftLeverPstReq_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6, &Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD_data.SCS_GearShiftLeverPstReq))
            {
                Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SCS_RiSwitchSts_BOD_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6_SCS_RightSwtVD_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6, &Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD_data.SCS_RightSwtVD))
            {
                Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SCS_RiSwitchSts_BOD_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6_SCS_Right_11Swt_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6, &Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD_data.SCS_Right_11Swt))
            {
                Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SCS_RiSwitchSts_BOD_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6_SCS_Right_12Swt_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6, &Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD_data.SCS_Right_12Swt))
            {
                Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SCS_RiSwitchSts_BOD_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6_SCS_Right_13Swt_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6, &Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD_data.SCS_Right_13Swt))
            {
                Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SCS_RiSwitchSts_BOD_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6_SCS_Right_14Swt_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6, &Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD_data.SCS_Right_14Swt))
            {
                Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SCS_RiSwitchSts_BOD_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6_SCS_Right_15Swt_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6, &Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD_data.SCS_Right_15Swt))
            {
                Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SCS_RiSwitchSts_BOD_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6_SCS_Right_16Swt_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6, &Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD_data.SCS_Right_16Swt))
            {
                Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD_ret = E_NOT_OK;
            }
            if (E_OK == Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD_ret)
            {
                Rte_Buf_Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD = Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD_data;
                Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD->status = RTE_E_OK;
            }
        }
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD, sizeof(SCS_RiSwitchSts_BOD));
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
        SRS_1_Status_CHA Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA_data;
        uint8 Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA_ret = E_OK;
        if (E_OK == Com_ReceiveSignalGroup(SRS_1_Status_CHA_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5))
        {
            if (E_NOT_OK == Com_ReceiveSignal(SRS_1_Status_CHA_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5_SRS_1_Chksum_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA_data.SRS_1_Chksum))
            {
                Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SRS_1_Status_CHA_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5_SRS_1_AliveCnt_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA_data.SRS_1_AliveCnt))
            {
                Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SRS_1_Status_CHA_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5_SRS_DrvSeatbeltBucklestatus_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA_data.SRS_DrvSeatbeltBucklestatus))
            {
                Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SRS_1_Status_CHA_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5_SRS_DrvSeatbeltBuckleValid_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA_data.SRS_DrvSeatbeltBuckleValid))
            {
                Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SRS_1_Status_CHA_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5_SRS_PassSeatbeltBucklestatus_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA_data.SRS_PassSeatbeltBucklestatus))
            {
                Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SRS_1_Status_CHA_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5_SRS_PassSeatbeltBuckleValid_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA_data.SRS_PassSeatbeltBuckleValid))
            {
                Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SRS_1_Status_CHA_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5_SRS_MidSeatBeltBucklestatus_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA_data.SRS_MidSeatBeltBucklestatus))
            {
                Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SRS_1_Status_CHA_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5_SRS_MidSeatBeltBuckleValid_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA_data.SRS_MidSeatBeltBuckleValid))
            {
                Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SRS_1_Status_CHA_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5_SRS_PassengerAirbagSta_Rsvr_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA_data.SRS_PassengerAirbagSta_Rsvr))
            {
                Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SRS_1_Status_CHA_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5_SRS_PassSeatOccupantSensorSts_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA_data.SRS_PassSeatOccupantSensorSts))
            {
                Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SRS_1_Status_CHA_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5_SRS_PassAirbSts_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA_data.SRS_PassAirbSts))
            {
                Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SRS_1_Status_CHA_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5_SRS_CrashOutputSts_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA_data.SRS_CrashOutputSts))
            {
                Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SRS_1_Status_CHA_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5_SRS_MidSeatOccupantSensorSts_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA_data.SRS_MidSeatOccupantSensorSts))
            {
                Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SRS_1_Status_CHA_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5_SRS_DrvSeatBeltRSt_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA_data.SRS_DrvSeatBeltRSt))
            {
                Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SRS_1_Status_CHA_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5_SRS_PsSeatBeltRSt_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA_data.SRS_PsSeatBeltRSt))
            {
                Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA_ret = E_NOT_OK;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SRS_1_Status_CHA_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5_SRS_AirbagWarningLampSts_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5, &Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA_data.SRS_AirbagWarningLampSts))
            {
                Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA_ret = E_NOT_OK;
            }
            if (E_OK == Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA_ret)
            {
                Rte_Buf_Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA = Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA_data;
                Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA->status = RTE_E_OK;
            }
        }
        rte_memcpy((uint8*)&(Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA->value), (uint8*)&Rte_Buf_Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA, sizeof(SRS_1_Status_CHA));
        rte_memcpy((uint8*)&Irv_AppSwcIpm_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV, (uint8*)&Irv_AppSwcIpm_MsgActv_outputsIRV, sizeof(DT_MsgActv));
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
        Rte_WriteBuffer_Rte_Buf_Runbl_IpmMsgActv_10ms_CANCommErr_outputs_CANCommErr_outputs(Rte_Inst_AppSwcIpm.Runbl_IpmMsgActv_10ms_CANCommErr_outputs_CANCommErr_outputs->value);
        Rte_WriteBuffer_Rte_Buf_Runbl_IpmMsgActv_10ms_MsgActv_outputs_MsgActv_outputs(Rte_Inst_AppSwcIpm.Runbl_IpmMsgActv_10ms_MsgActv_outputs_MsgActv_outputs->value);
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

