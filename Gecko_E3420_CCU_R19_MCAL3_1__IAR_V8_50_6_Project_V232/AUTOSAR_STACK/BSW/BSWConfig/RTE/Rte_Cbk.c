/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_Cbk.c>
 *  @brief      <>
 *  
 *  <MCU:E3420>
 *  
 *  @author     <>
 *  @date       <2024-08-07 15:08:41>
 */
/*============================================================================*/

/* Rte_Cbk.c */
/*******************************************************************************
 **                        Revision Control History                           **
******************************************************************************/

/*******************************************************************************
 **                        Version Information                                **
******************************************************************************/

/*******************************************************************************
 **                        Include Section                                    **
******************************************************************************/
#include "Rte_Cbk.h"
#include "Rte_Data.h"
#include "Com.h"
#define RTE_CORE
#include "Rte_AppSwcBcm.h"
#include "Rte_AppSwcIpm.h"
#include "Rte_AppSwcOpm.h"
#include "Rte_ME11.h"
#include "Rte_AppSwcVcu.h"
#include "Dem.h"
#include "IoExp_TCA9539_Api.h"

/*******************************************************************************
 **                        Global Function                                    **
******************************************************************************/

/*******************************************************************************
*Function-Name        Rte_COMCbkRxTOut_BMS_2_BatState_EPT_IPDU_COM_BMS_2_BatState_EPT
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
void Rte_COMCbkRxTOut_BMS_2_BatState_EPT_IPDU_COM_BMS_2_BatState_EPT(void)
{
    if (RteInitState == RTE_INITED)
    {
        Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_BMS_2_BatState_EPT_BMS_2_BatState_EPT->status |= RTE_E_TIMEOUT;
    }
    if((IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P10) == 1) || (IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P11) == 1))
    {
    Dem_UdsStatusByteType tmp = 0;
    if (E_OK == Dem_GetEventStatus(DemEventParameter_0xC11287, &tmp))
	{
		if (DEM_UDS_STATUS_TF != (tmp & DEM_UDS_STATUS_TF))
		{
			Dem_SetEventStatus(DemEventParameter_0xC11287, DEM_EVENT_STATUS_FAILED);
		}
	}

    }
    
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbkRxTOut_COMP_AC_BOD_IPDU_COM_COMP_AC_BOD
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
void Rte_COMCbkRxTOut_COMP_AC_BOD_IPDU_COM_COMP_AC_BOD(void)
{
    if (RteInitState == RTE_INITED)
    {
        Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD->status |= RTE_E_TIMEOUT;
    }
    if((IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P10) == 1) || (IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P11) == 1))
    {
    Dem_UdsStatusByteType tmp = 0;
    if (E_OK == Dem_GetEventStatus(DemEventParameter_0xC10F87, &tmp))
	{
		if (DEM_UDS_STATUS_TF != (tmp & DEM_UDS_STATUS_TF))
		{
			Dem_SetEventStatus(DemEventParameter_0xC10F87, DEM_EVENT_STATUS_FAILED);
		}
	}
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbkRxTOut_CRRR_A_CHA_IPDU_COM_CRRR_A_CHA
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
void Rte_COMCbkRxTOut_CRRR_A_CHA_IPDU_COM_CRRR_A_CHA(void)
{
    if (RteInitState == RTE_INITED)
    {
    }
    if((IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P10) == 1) || (IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P11) == 1))
    {
    Dem_UdsStatusByteType tmp = 0;
    if (E_OK == Dem_GetEventStatus(DemEventParameter_0xD11287, &tmp))
	{
		if (DEM_UDS_STATUS_TF != (tmp & DEM_UDS_STATUS_TF))
		{
			Dem_SetEventStatus(DemEventParameter_0xD11287, DEM_EVENT_STATUS_FAILED);
		}
	}
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbkRxTOut_EPS_2_StrWhlAng_CHA_IPDU_COM_EPS_2_StrWhlAng_CHA
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
void Rte_COMCbkRxTOut_EPS_2_StrWhlAng_CHA_IPDU_COM_EPS_2_StrWhlAng_CHA(void)
{
    if (RteInitState == RTE_INITED)
    {
        Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_EPS_2_StrWhlAng_CHA_EPS_2_StrWhlAng_CHA->status |= RTE_E_TIMEOUT;
    }
    if((IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P10) == 1) || (IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P11) == 1))
    {
    Dem_UdsStatusByteType tmp = 0;
    if (E_OK == Dem_GetEventStatus(DemEventParameter_0xC13087, &tmp))
	{
		if (DEM_UDS_STATUS_TF != (tmp & DEM_UDS_STATUS_TF))
		{
			Dem_SetEventStatus(DemEventParameter_0xC13087, DEM_EVENT_STATUS_FAILED);
		}
	}
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbkRxTOut_ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5
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
void Rte_COMCbkRxTOut_ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5(void)
{
    if((IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P10) == 1) || (IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P11) == 1))
    {
    Dem_UdsStatusByteType tmp = 0;
    if (E_OK == Dem_GetEventStatus(DemEventParameter_0xC12287, &tmp))
	{
		if (DEM_UDS_STATUS_TF != (tmp & DEM_UDS_STATUS_TF))
		{
			Dem_SetEventStatus(DemEventParameter_0xC12287, DEM_EVENT_STATUS_FAILED);
		}
	}
    }
    if (RteInitState == RTE_INITED)
    {
        Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_ESC_7_FuncStatus_CHA_ESC_7_FuncStatus_CHA->status |= RTE_E_TIMEOUT;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbkRxTOut_FCM_D_CHA_IPDU_COM_RX_FCM_D_CHA_CANFD3_CHA_CAN5
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
void Rte_COMCbkRxTOut_FCM_D_CHA_IPDU_COM_RX_FCM_D_CHA_CANFD3_CHA_CAN5(void)
{
    if((IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P10) == 1) || (IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P11) == 1))
    {
    Dem_UdsStatusByteType tmp = 0;
    if (E_OK == Dem_GetEventStatus(DemEventParameter_0xD10287, &tmp))
	{
		if (DEM_UDS_STATUS_TF != (tmp & DEM_UDS_STATUS_TF))
		{
			Dem_SetEventStatus(DemEventParameter_0xD10287, DEM_EVENT_STATUS_FAILED);
		}
	}
    }
    if (RteInitState == RTE_INITED)
    {
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbkRxTOut_HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1
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
void Rte_COMCbkRxTOut_HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC->status |= RTE_E_TIMEOUT;
    }
    if((IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P10) == 1) || (IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P11) == 1))
    {
     Dem_UdsStatusByteType tmp = 0;
    if (E_OK == Dem_GetEventStatus(DemEventParameter_0xD11D87, &tmp))
	{
		if (DEM_UDS_STATUS_TF != (tmp & DEM_UDS_STATUS_TF))
		{
			Dem_SetEventStatus(DemEventParameter_0xD11D87, DEM_EVENT_STATUS_FAILED);
		}
	}
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbkRxTOut_HVCH_Status1_BOD_IPDU_COM_HVCH_Status1_BOD
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
void Rte_COMCbkRxTOut_HVCH_Status1_BOD_IPDU_COM_HVCH_Status1_BOD(void)
{
    if (RteInitState == RTE_INITED)
    {
        Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_HVCH_Status1_BOD_HVCH_Status1_BOD->status |= RTE_E_TIMEOUT;
    }
    if((IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P10) == 1) || (IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P11) == 1))
    {
    Dem_UdsStatusByteType tmp = 0;
    if (E_OK == Dem_GetEventStatus(DemEventParameter_0xC23087, &tmp))
	{
		if (DEM_UDS_STATUS_TF != (tmp & DEM_UDS_STATUS_TF))
		{
			Dem_SetEventStatus(DemEventParameter_0xC23087, DEM_EVENT_STATUS_FAILED);
		}
	}
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbkRxTOut_ICU_2_Odo_BAC_IPDU_COM_ICU_2_Odo_BAC
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
void Rte_COMCbkRxTOut_ICU_2_Odo_BAC_IPDU_COM_ICU_2_Odo_BAC(void)
{
    if (RteInitState == RTE_INITED)
    {
    }
    if((IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P10) == 1) || (IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P11) == 1))
    {
    Dem_UdsStatusByteType tmp = 0;
    if (E_OK == Dem_GetEventStatus(DemEventParameter_0xD11687, &tmp))
	{
		if (DEM_UDS_STATUS_TF != (tmp & DEM_UDS_STATUS_TF))
		{
			Dem_SetEventStatus(DemEventParameter_0xD11687, DEM_EVENT_STATUS_FAILED);
		}
	}
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbkRxTOut_IPU_OBC_1_State_EPT_IPDU_COM_IPU_OBC_1_State_EPT
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
void Rte_COMCbkRxTOut_IPU_OBC_1_State_EPT_IPDU_COM_IPU_OBC_1_State_EPT(void)
{
    if (RteInitState == RTE_INITED)
    {
        Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPU_OBC_1_State_EPT_IPU_OBC_1_State_EPT->status |= RTE_E_TIMEOUT;
    }
    if((IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P10) == 1) || (IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P11) == 1))
    {
    Dem_UdsStatusByteType tmp = 0;
    if (E_OK == Dem_GetEventStatus(DemEventParameter_0xC14687, &tmp))
	{
		if (DEM_UDS_STATUS_TF != (tmp & DEM_UDS_STATUS_TF))
		{
			Dem_SetEventStatus(DemEventParameter_0xC14687, DEM_EVENT_STATUS_FAILED);
		}
	}
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbkRxTOut_PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5
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
void Rte_COMCbkRxTOut_PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5(void)
{
    if((IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P10) == 1) || (IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P11) == 1))
    {
    Dem_UdsStatusByteType tmp = 0;
    if (E_OK == Dem_GetEventStatus(DemEventParameter_0xD10E87, &tmp))
	{
		if (DEM_UDS_STATUS_TF != (tmp & DEM_UDS_STATUS_TF))
		{
			Dem_SetEventStatus(DemEventParameter_0xD10E87, DEM_EVENT_STATUS_FAILED);
		}
	}
    }
    if (RteInitState == RTE_INITED)
    {
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbkRxTOut_SRS_2_YRSOriginalSts_CHA_IPDU_COM_SRS_2_YRSOriginalSts_CHA
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
void Rte_COMCbkRxTOut_SRS_2_YRSOriginalSts_CHA_IPDU_COM_SRS_2_YRSOriginalSts_CHA(void)
{
    if (RteInitState == RTE_INITED)
    {
    }
    if((IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P10) == 1) || (IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P11) == 1))
    {
     Dem_UdsStatusByteType tmp = 0;
    if (E_OK == Dem_GetEventStatus(DemEventParameter_0xC15187, &tmp))
	{
		if (DEM_UDS_STATUS_TF != (tmp & DEM_UDS_STATUS_TF))
		{
			Dem_SetEventStatus(DemEventParameter_0xC15187, DEM_EVENT_STATUS_FAILED);
		}
	}
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbkRxTOut_TBOX_BJS_Time_BAC_IPDU_COM_TBOX_BJS_Time_BAC
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
void Rte_COMCbkRxTOut_TBOX_BJS_Time_BAC_IPDU_COM_TBOX_BJS_Time_BAC(void)
{
    if (RteInitState == RTE_INITED)
    {
        Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_TBOX_BJS_Time_BAC_TBOX_BJS_Time_BAC->status |= RTE_E_TIMEOUT;
    }
    if((IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P10) == 1) || (IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P11) == 1))
    {
    Dem_UdsStatusByteType tmp = 0;
    if (E_OK == Dem_GetEventStatus(DemEventParameter_0xC19887, &tmp))
	{
		if (DEM_UDS_STATUS_TF != (tmp & DEM_UDS_STATUS_TF))
		{
			Dem_SetEventStatus(DemEventParameter_0xC19887, DEM_EVENT_STATUS_FAILED);
		}
	}
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbkTxTOut_VCU_1_InvCmd_EPT_IPDU_COM_VCU_1_InvCmd_EPT
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
void Rte_COMCbkTxTOut_VCU_1_InvCmd_EPT_IPDU_COM_VCU_1_InvCmd_EPT(void)
{
    if (RteInitState == RTE_INITED)
    {
        Rte_Inst_AppSwcOpm.Runbl_OpmCanTx_10ms_VCU_1_InvCmd_EPT_VCU_1_InvCmd_EPT->status |= RTE_E_TIMEOUT;
    }
    if((IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P10) == 1) || (IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P11) == 1))
    {
    Dem_UdsStatusByteType tmp = 0;
    if (E_OK == Dem_GetEventStatus(DemEventParameter_0xD10887, &tmp))
	{
		if (DEM_UDS_STATUS_TF != (tmp & DEM_UDS_STATUS_TF))
		{
			Dem_SetEventStatus(DemEventParameter_0xD10887, DEM_EVENT_STATUS_FAILED);
		}
	}
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_ACCM_Version_BOD_IPDU_COM_ACCM_Version_BOD
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
void Rte_COMCbk_ACCM_Version_BOD_IPDU_COM_ACCM_Version_BOD(void)
{
    if (RteInitState == RTE_INITED)
    {
        ACCM_Version_BOD data;
        boolean isSuccess = TRUE;
        if (E_OK == Com_ReceiveSignalGroup(ACCM_Version_BOD_IPDU_COM_ACCM_Version_BOD))
        {
            if (E_NOT_OK == Com_ReceiveSignal(ACCM_Version_BOD_IPDU_COM_ACCM_Version_BOD_Client_Number_IPDU_COM_ACCM_Version_BOD, &data.Client_Number))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ACCM_Version_BOD_IPDU_COM_ACCM_Version_BOD_APP_Version_Max_IPDU_COM_ACCM_Version_BOD, &data.APP_Version_Max))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ACCM_Version_BOD_IPDU_COM_ACCM_Version_BOD_APP_Version_Min_IPDU_COM_ACCM_Version_BOD, &data.APP_Version_Min))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ACCM_Version_BOD_IPDU_COM_ACCM_Version_BOD_Hardware_Version_Max_IPDU_COM_ACCM_Version_BOD, &data.Hardware_Version_Max))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ACCM_Version_BOD_IPDU_COM_ACCM_Version_BOD_Hardware_Version_Min_IPDU_COM_ACCM_Version_BOD, &data.Hardware_Version_Min))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ACCM_Version_BOD_IPDU_COM_ACCM_Version_BOD_Boot_Version_IPDU_COM_ACCM_Version_BOD, &data.Boot_Version))
            {
                isSuccess = FALSE;
            }
            if (isSuccess == TRUE)
            {
                if (isSuccess == TRUE)
                {
                    rte_memcpy((uint8*)&Rte_Buf_Runbl_IpmCanRx_100ms_ACCM_Version_BOD_ACCM_Version_BOD,(uint8*)&data,sizeof(ACCM_Version_BOD));
                    Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_ACCM_Version_BOD_ACCM_Version_BOD->status = RTE_E_OK;
                }
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_AcPMP_HWVersion_AcPMP_Version_LIN1
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
void Rte_COMCbk_AcPMP_HWVersion_AcPMP_Version_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 AcPMP_HWVersion_AcPMP_Version_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(AcPMP_HWVersion_AcPMP_Version_LIN1, &AcPMP_HWVersion_AcPMP_Version_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)AcPMP_HWVersion_AcPMP_Version_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_AcPMP_HWVersion_AcPMP_HWVersion = data;
                Rte_Inst_ME11.Task_100ms_AcPMP_HWVersion_AcPMP_HWVersion->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_AcPMP_HWVersion_AcPMP_Version_LIN2
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
void Rte_COMCbk_AcPMP_HWVersion_AcPMP_Version_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 AcPMP_HWVersion_AcPMP_Version_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(AcPMP_HWVersion_AcPMP_Version_LIN2, &AcPMP_HWVersion_AcPMP_Version_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)AcPMP_HWVersion_AcPMP_Version_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_AcPMP_HWVersion_AcPMP_HWVersion = data;
                Rte_Inst_ME11.Task_100ms_AcPMP_HWVersion_AcPMP_HWVersion->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_AcPMP_PartNumber_AcPMP_Version_LIN1
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
void Rte_COMCbk_AcPMP_PartNumber_AcPMP_Version_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 AcPMP_PartNumber_AcPMP_Version_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(AcPMP_PartNumber_AcPMP_Version_LIN1, &AcPMP_PartNumber_AcPMP_Version_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)AcPMP_PartNumber_AcPMP_Version_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_AcPMP_PartNumber_AcPMP_PartNumber = data;
                Rte_Inst_ME11.Task_100ms_AcPMP_PartNumber_AcPMP_PartNumber->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_AcPMP_PartNumber_AcPMP_Version_LIN2
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
void Rte_COMCbk_AcPMP_PartNumber_AcPMP_Version_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 AcPMP_PartNumber_AcPMP_Version_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(AcPMP_PartNumber_AcPMP_Version_LIN2, &AcPMP_PartNumber_AcPMP_Version_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)AcPMP_PartNumber_AcPMP_Version_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_AcPMP_PartNumber_AcPMP_PartNumber = data;
                Rte_Inst_ME11.Task_100ms_AcPMP_PartNumber_AcPMP_PartNumber->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_AcPMP_ProjectCode1_AcPMP_Version_LIN1
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
void Rte_COMCbk_AcPMP_ProjectCode1_AcPMP_Version_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 AcPMP_ProjectCode1_AcPMP_Version_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(AcPMP_ProjectCode1_AcPMP_Version_LIN1, &AcPMP_ProjectCode1_AcPMP_Version_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)AcPMP_ProjectCode1_AcPMP_Version_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_AcPMP_ProjectCode1_AcPMP_ProjectCode1 = data;
                Rte_Inst_ME11.Task_100ms_AcPMP_ProjectCode1_AcPMP_ProjectCode1->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_AcPMP_ProjectCode1_AcPMP_Version_LIN2
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
void Rte_COMCbk_AcPMP_ProjectCode1_AcPMP_Version_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 AcPMP_ProjectCode1_AcPMP_Version_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(AcPMP_ProjectCode1_AcPMP_Version_LIN2, &AcPMP_ProjectCode1_AcPMP_Version_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)AcPMP_ProjectCode1_AcPMP_Version_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_AcPMP_ProjectCode1_AcPMP_ProjectCode1 = data;
                Rte_Inst_ME11.Task_100ms_AcPMP_ProjectCode1_AcPMP_ProjectCode1->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_AcPMP_ProjectCode2_AcPMP_Version_LIN1
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
void Rte_COMCbk_AcPMP_ProjectCode2_AcPMP_Version_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 AcPMP_ProjectCode2_AcPMP_Version_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(AcPMP_ProjectCode2_AcPMP_Version_LIN1, &AcPMP_ProjectCode2_AcPMP_Version_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)AcPMP_ProjectCode2_AcPMP_Version_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_AcPMP_ProjectCode2_AcPMP_ProjectCode2 = data;
                Rte_Inst_ME11.Task_100ms_AcPMP_ProjectCode2_AcPMP_ProjectCode2->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_AcPMP_ProjectCode2_AcPMP_Version_LIN2
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
void Rte_COMCbk_AcPMP_ProjectCode2_AcPMP_Version_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 AcPMP_ProjectCode2_AcPMP_Version_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(AcPMP_ProjectCode2_AcPMP_Version_LIN2, &AcPMP_ProjectCode2_AcPMP_Version_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)AcPMP_ProjectCode2_AcPMP_Version_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_AcPMP_ProjectCode2_AcPMP_ProjectCode2 = data;
                Rte_Inst_ME11.Task_100ms_AcPMP_ProjectCode2_AcPMP_ProjectCode2->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_AcPMP_PumpDryRunningSta_AcPMP_Sts_LIN1
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
void Rte_COMCbk_AcPMP_PumpDryRunningSta_AcPMP_Sts_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        Boolean data;
        boolean isSuccess = TRUE;
        boolean AcPMP_PumpDryRunningSta_AcPMP_Sts_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(AcPMP_PumpDryRunningSta_AcPMP_Sts_LIN1, &AcPMP_PumpDryRunningSta_AcPMP_Sts_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (Boolean)AcPMP_PumpDryRunningSta_AcPMP_Sts_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_AcPMP_PumpDryRunningSta_AcPMP_PumpDryRunningSta = data;
                Rte_Inst_ME11.Task_100ms_AcPMP_PumpDryRunningSta_AcPMP_PumpDryRunningSta->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_AcPMP_PumpDryRunningSta_AcPMP_Sts_LIN2
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
void Rte_COMCbk_AcPMP_PumpDryRunningSta_AcPMP_Sts_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        Boolean data;
        boolean isSuccess = TRUE;
        boolean AcPMP_PumpDryRunningSta_AcPMP_Sts_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(AcPMP_PumpDryRunningSta_AcPMP_Sts_LIN2, &AcPMP_PumpDryRunningSta_AcPMP_Sts_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (Boolean)AcPMP_PumpDryRunningSta_AcPMP_Sts_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_AcPMP_PumpDryRunningSta_AcPMP_PumpDryRunningSta = data;
                Rte_Inst_ME11.Task_100ms_AcPMP_PumpDryRunningSta_AcPMP_PumpDryRunningSta->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_AcPMP_PumpInputVolt_AcPMP_Sts_LIN1
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
void Rte_COMCbk_AcPMP_PumpInputVolt_AcPMP_Sts_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 AcPMP_PumpInputVolt_AcPMP_Sts_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(AcPMP_PumpInputVolt_AcPMP_Sts_LIN1, &AcPMP_PumpInputVolt_AcPMP_Sts_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)AcPMP_PumpInputVolt_AcPMP_Sts_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_AcPMP_PumpInputVolt_AcPMP_PumpInputVolt = data;
                Rte_Inst_ME11.Task_100ms_AcPMP_PumpInputVolt_AcPMP_PumpInputVolt->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_AcPMP_PumpInputVolt_AcPMP_Sts_LIN2
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
void Rte_COMCbk_AcPMP_PumpInputVolt_AcPMP_Sts_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 AcPMP_PumpInputVolt_AcPMP_Sts_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(AcPMP_PumpInputVolt_AcPMP_Sts_LIN2, &AcPMP_PumpInputVolt_AcPMP_Sts_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)AcPMP_PumpInputVolt_AcPMP_Sts_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_AcPMP_PumpInputVolt_AcPMP_PumpInputVolt = data;
                Rte_Inst_ME11.Task_100ms_AcPMP_PumpInputVolt_AcPMP_PumpInputVolt->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_AcPMP_PumpMotorSta_AcPMP_Sts_LIN1
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
void Rte_COMCbk_AcPMP_PumpMotorSta_AcPMP_Sts_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 AcPMP_PumpMotorSta_AcPMP_Sts_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(AcPMP_PumpMotorSta_AcPMP_Sts_LIN1, &AcPMP_PumpMotorSta_AcPMP_Sts_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)AcPMP_PumpMotorSta_AcPMP_Sts_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_AcPMP_PumpMotorSta_AcPMP_PumpMotorSta = data;
                Rte_Inst_ME11.Task_100ms_AcPMP_PumpMotorSta_AcPMP_PumpMotorSta->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_AcPMP_PumpMotorSta_AcPMP_Sts_LIN2
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
void Rte_COMCbk_AcPMP_PumpMotorSta_AcPMP_Sts_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 AcPMP_PumpMotorSta_AcPMP_Sts_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(AcPMP_PumpMotorSta_AcPMP_Sts_LIN2, &AcPMP_PumpMotorSta_AcPMP_Sts_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)AcPMP_PumpMotorSta_AcPMP_Sts_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_AcPMP_PumpMotorSta_AcPMP_PumpMotorSta = data;
                Rte_Inst_ME11.Task_100ms_AcPMP_PumpMotorSta_AcPMP_PumpMotorSta->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_AcPMP_PumpPowerSta_AcPMP_Sts_LIN1
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
void Rte_COMCbk_AcPMP_PumpPowerSta_AcPMP_Sts_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 AcPMP_PumpPowerSta_AcPMP_Sts_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(AcPMP_PumpPowerSta_AcPMP_Sts_LIN1, &AcPMP_PumpPowerSta_AcPMP_Sts_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)AcPMP_PumpPowerSta_AcPMP_Sts_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_AcPMP_PumpPowerSta_AcPMP_PumpPowerSta = data;
                Rte_Inst_ME11.Task_100ms_AcPMP_PumpPowerSta_AcPMP_PumpPowerSta->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_AcPMP_PumpPowerSta_AcPMP_Sts_LIN2
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
void Rte_COMCbk_AcPMP_PumpPowerSta_AcPMP_Sts_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 AcPMP_PumpPowerSta_AcPMP_Sts_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(AcPMP_PumpPowerSta_AcPMP_Sts_LIN2, &AcPMP_PumpPowerSta_AcPMP_Sts_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)AcPMP_PumpPowerSta_AcPMP_Sts_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_AcPMP_PumpPowerSta_AcPMP_PumpPowerSta = data;
                Rte_Inst_ME11.Task_100ms_AcPMP_PumpPowerSta_AcPMP_PumpPowerSta->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_AcPMP_PumpTempSta_AcPMP_Sts_LIN1
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
void Rte_COMCbk_AcPMP_PumpTempSta_AcPMP_Sts_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 AcPMP_PumpTempSta_AcPMP_Sts_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(AcPMP_PumpTempSta_AcPMP_Sts_LIN1, &AcPMP_PumpTempSta_AcPMP_Sts_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)AcPMP_PumpTempSta_AcPMP_Sts_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_AcPMP_PumpTempSta_AcPMP_PumpTempSta = data;
                Rte_Inst_ME11.Task_100ms_AcPMP_PumpTempSta_AcPMP_PumpTempSta->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_AcPMP_PumpTempSta_AcPMP_Sts_LIN2
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
void Rte_COMCbk_AcPMP_PumpTempSta_AcPMP_Sts_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 AcPMP_PumpTempSta_AcPMP_Sts_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(AcPMP_PumpTempSta_AcPMP_Sts_LIN2, &AcPMP_PumpTempSta_AcPMP_Sts_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)AcPMP_PumpTempSta_AcPMP_Sts_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_AcPMP_PumpTempSta_AcPMP_PumpTempSta = data;
                Rte_Inst_ME11.Task_100ms_AcPMP_PumpTempSta_AcPMP_PumpTempSta->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_AcPMP_RESP_ERROR_AcPMP_Sts_LIN1
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
void Rte_COMCbk_AcPMP_RESP_ERROR_AcPMP_Sts_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        Boolean data;
        boolean isSuccess = TRUE;
        boolean AcPMP_RESP_ERROR_AcPMP_Sts_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(AcPMP_RESP_ERROR_AcPMP_Sts_LIN1, &AcPMP_RESP_ERROR_AcPMP_Sts_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (Boolean)AcPMP_RESP_ERROR_AcPMP_Sts_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_AcPMP_RESP_ERROR_AcPMP_RESP_ERROR = data;
                Rte_Inst_ME11.Task_100ms_AcPMP_RESP_ERROR_AcPMP_RESP_ERROR->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_AcPMP_RESP_ERROR_AcPMP_Sts_LIN2
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
void Rte_COMCbk_AcPMP_RESP_ERROR_AcPMP_Sts_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        Boolean data;
        boolean isSuccess = TRUE;
        boolean AcPMP_RESP_ERROR_AcPMP_Sts_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(AcPMP_RESP_ERROR_AcPMP_Sts_LIN2, &AcPMP_RESP_ERROR_AcPMP_Sts_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (Boolean)AcPMP_RESP_ERROR_AcPMP_Sts_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_AcPMP_RESP_ERROR_AcPMP_RESP_ERROR = data;
                Rte_Inst_ME11.Task_100ms_AcPMP_RESP_ERROR_AcPMP_RESP_ERROR->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_AcPMP_RealRPM_AcPMP_Sts_LIN1
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
void Rte_COMCbk_AcPMP_RealRPM_AcPMP_Sts_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 AcPMP_RealRPM_AcPMP_Sts_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(AcPMP_RealRPM_AcPMP_Sts_LIN1, &AcPMP_RealRPM_AcPMP_Sts_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)AcPMP_RealRPM_AcPMP_Sts_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_AcPMP_RealRPM_AcPMP_RealRPM = data;
                Rte_Inst_ME11.Task_100ms_AcPMP_RealRPM_AcPMP_RealRPM->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_AcPMP_RealRPM_AcPMP_Sts_LIN2
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
void Rte_COMCbk_AcPMP_RealRPM_AcPMP_Sts_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 AcPMP_RealRPM_AcPMP_Sts_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(AcPMP_RealRPM_AcPMP_Sts_LIN2, &AcPMP_RealRPM_AcPMP_Sts_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)AcPMP_RealRPM_AcPMP_Sts_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_AcPMP_RealRPM_AcPMP_RealRPM = data;
                Rte_Inst_ME11.Task_100ms_AcPMP_RealRPM_AcPMP_RealRPM->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_AcPMP_SWVersion_Main_AcPMP_Version_LIN1
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
void Rte_COMCbk_AcPMP_SWVersion_Main_AcPMP_Version_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 AcPMP_SWVersion_Main_AcPMP_Version_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(AcPMP_SWVersion_Main_AcPMP_Version_LIN1, &AcPMP_SWVersion_Main_AcPMP_Version_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)AcPMP_SWVersion_Main_AcPMP_Version_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_AcPMP_SWVersion_Main_AcPMP_SWVersion_Main = data;
                Rte_Inst_ME11.Task_100ms_AcPMP_SWVersion_Main_AcPMP_SWVersion_Main->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_AcPMP_SWVersion_Main_AcPMP_Version_LIN2
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
void Rte_COMCbk_AcPMP_SWVersion_Main_AcPMP_Version_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 AcPMP_SWVersion_Main_AcPMP_Version_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(AcPMP_SWVersion_Main_AcPMP_Version_LIN2, &AcPMP_SWVersion_Main_AcPMP_Version_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)AcPMP_SWVersion_Main_AcPMP_Version_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_AcPMP_SWVersion_Main_AcPMP_SWVersion_Main = data;
                Rte_Inst_ME11.Task_100ms_AcPMP_SWVersion_Main_AcPMP_SWVersion_Main->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_AcPMP_SWVersion_Patch_AcPMP_Version_LIN1
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
void Rte_COMCbk_AcPMP_SWVersion_Patch_AcPMP_Version_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 AcPMP_SWVersion_Patch_AcPMP_Version_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(AcPMP_SWVersion_Patch_AcPMP_Version_LIN1, &AcPMP_SWVersion_Patch_AcPMP_Version_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)AcPMP_SWVersion_Patch_AcPMP_Version_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_AcPMP_SWVersion_Patch_AcPMP_SWVersion_Patch = data;
                Rte_Inst_ME11.Task_100ms_AcPMP_SWVersion_Patch_AcPMP_SWVersion_Patch->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_AcPMP_SWVersion_Patch_AcPMP_Version_LIN2
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
void Rte_COMCbk_AcPMP_SWVersion_Patch_AcPMP_Version_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 AcPMP_SWVersion_Patch_AcPMP_Version_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(AcPMP_SWVersion_Patch_AcPMP_Version_LIN2, &AcPMP_SWVersion_Patch_AcPMP_Version_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)AcPMP_SWVersion_Patch_AcPMP_Version_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_AcPMP_SWVersion_Patch_AcPMP_SWVersion_Patch = data;
                Rte_Inst_ME11.Task_100ms_AcPMP_SWVersion_Patch_AcPMP_SWVersion_Patch->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_AcPMP_SWVersion_Sub_AcPMP_Version_LIN1
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
void Rte_COMCbk_AcPMP_SWVersion_Sub_AcPMP_Version_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 AcPMP_SWVersion_Sub_AcPMP_Version_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(AcPMP_SWVersion_Sub_AcPMP_Version_LIN1, &AcPMP_SWVersion_Sub_AcPMP_Version_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)AcPMP_SWVersion_Sub_AcPMP_Version_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_AcPMP_SWVersion_Sub_AcPMP_SWVersion_Sub = data;
                Rte_Inst_ME11.Task_100ms_AcPMP_SWVersion_Sub_AcPMP_SWVersion_Sub->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_AcPMP_SWVersion_Sub_AcPMP_Version_LIN2
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
void Rte_COMCbk_AcPMP_SWVersion_Sub_AcPMP_Version_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 AcPMP_SWVersion_Sub_AcPMP_Version_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(AcPMP_SWVersion_Sub_AcPMP_Version_LIN2, &AcPMP_SWVersion_Sub_AcPMP_Version_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)AcPMP_SWVersion_Sub_AcPMP_Version_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_AcPMP_SWVersion_Sub_AcPMP_SWVersion_Sub = data;
                Rte_Inst_ME11.Task_100ms_AcPMP_SWVersion_Sub_AcPMP_SWVersion_Sub->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_AcPMP_SupplierNumber_AcPMP_Version_LIN1
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
void Rte_COMCbk_AcPMP_SupplierNumber_AcPMP_Version_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 AcPMP_SupplierNumber_AcPMP_Version_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(AcPMP_SupplierNumber_AcPMP_Version_LIN1, &AcPMP_SupplierNumber_AcPMP_Version_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)AcPMP_SupplierNumber_AcPMP_Version_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_AcPMP_SupplierNumber_AcPMP_SupplierNumber = data;
                Rte_Inst_ME11.Task_100ms_AcPMP_SupplierNumber_AcPMP_SupplierNumber->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_AcPMP_SupplierNumber_AcPMP_Version_LIN2
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
void Rte_COMCbk_AcPMP_SupplierNumber_AcPMP_Version_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 AcPMP_SupplierNumber_AcPMP_Version_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(AcPMP_SupplierNumber_AcPMP_Version_LIN2, &AcPMP_SupplierNumber_AcPMP_Version_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)AcPMP_SupplierNumber_AcPMP_Version_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_AcPMP_SupplierNumber_AcPMP_SupplierNumber = data;
                Rte_Inst_ME11.Task_100ms_AcPMP_SupplierNumber_AcPMP_SupplierNumber->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_BAT_EXV_CurrentPosition_B_BAT_EXV_Rsp_LIN1
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
void Rte_COMCbk_BAT_EXV_CurrentPosition_B_BAT_EXV_Rsp_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt16 data;
        boolean isSuccess = TRUE;
        uint16 BAT_EXV_CurrentPosition_B_BAT_EXV_Rsp_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(BAT_EXV_CurrentPosition_B_BAT_EXV_Rsp_LIN1, &BAT_EXV_CurrentPosition_B_BAT_EXV_Rsp_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt16)BAT_EXV_CurrentPosition_B_BAT_EXV_Rsp_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_BAT_EXV_CurrentPosition_B_BAT_EXV_CurrentPosition_B = data;
                Rte_Inst_ME11.Task_100ms_BAT_EXV_CurrentPosition_B_BAT_EXV_CurrentPosition_B->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_BAT_EXV_CurrentPosition_B_BAT_EXV_Rsp_LIN2
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
void Rte_COMCbk_BAT_EXV_CurrentPosition_B_BAT_EXV_Rsp_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt16 data;
        boolean isSuccess = TRUE;
        uint16 BAT_EXV_CurrentPosition_B_BAT_EXV_Rsp_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(BAT_EXV_CurrentPosition_B_BAT_EXV_Rsp_LIN2, &BAT_EXV_CurrentPosition_B_BAT_EXV_Rsp_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt16)BAT_EXV_CurrentPosition_B_BAT_EXV_Rsp_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_BAT_EXV_CurrentPosition_B_BAT_EXV_CurrentPosition_B = data;
                Rte_Inst_ME11.Task_100ms_BAT_EXV_CurrentPosition_B_BAT_EXV_CurrentPosition_B->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_BAT_EXV_FaultState_B_BAT_EXV_Rsp_LIN1
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
void Rte_COMCbk_BAT_EXV_FaultState_B_BAT_EXV_Rsp_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 BAT_EXV_FaultState_B_BAT_EXV_Rsp_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(BAT_EXV_FaultState_B_BAT_EXV_Rsp_LIN1, &BAT_EXV_FaultState_B_BAT_EXV_Rsp_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)BAT_EXV_FaultState_B_BAT_EXV_Rsp_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_BAT_EXV_FaultState_B_BAT_EXV_FaultState_B = data;
                Rte_Inst_ME11.Task_100ms_BAT_EXV_FaultState_B_BAT_EXV_FaultState_B->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_BAT_EXV_FaultState_B_BAT_EXV_Rsp_LIN2
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
void Rte_COMCbk_BAT_EXV_FaultState_B_BAT_EXV_Rsp_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 BAT_EXV_FaultState_B_BAT_EXV_Rsp_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(BAT_EXV_FaultState_B_BAT_EXV_Rsp_LIN2, &BAT_EXV_FaultState_B_BAT_EXV_Rsp_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)BAT_EXV_FaultState_B_BAT_EXV_Rsp_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_BAT_EXV_FaultState_B_BAT_EXV_FaultState_B = data;
                Rte_Inst_ME11.Task_100ms_BAT_EXV_FaultState_B_BAT_EXV_FaultState_B->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_BAT_EXV_ResponseError_B_BAT_EXV_Rsp_LIN1
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
void Rte_COMCbk_BAT_EXV_ResponseError_B_BAT_EXV_Rsp_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        Boolean data;
        boolean isSuccess = TRUE;
        boolean BAT_EXV_ResponseError_B_BAT_EXV_Rsp_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(BAT_EXV_ResponseError_B_BAT_EXV_Rsp_LIN1, &BAT_EXV_ResponseError_B_BAT_EXV_Rsp_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (Boolean)BAT_EXV_ResponseError_B_BAT_EXV_Rsp_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_BAT_EXV_ResponseError_B_BAT_EXV_ResponseError_B = data;
                Rte_Inst_ME11.Task_100ms_BAT_EXV_ResponseError_B_BAT_EXV_ResponseError_B->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_BAT_EXV_ResponseError_B_BAT_EXV_Rsp_LIN2
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
void Rte_COMCbk_BAT_EXV_ResponseError_B_BAT_EXV_Rsp_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        Boolean data;
        boolean isSuccess = TRUE;
        boolean BAT_EXV_ResponseError_B_BAT_EXV_Rsp_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(BAT_EXV_ResponseError_B_BAT_EXV_Rsp_LIN2, &BAT_EXV_ResponseError_B_BAT_EXV_Rsp_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (Boolean)BAT_EXV_ResponseError_B_BAT_EXV_Rsp_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_BAT_EXV_ResponseError_B_BAT_EXV_ResponseError_B = data;
                Rte_Inst_ME11.Task_100ms_BAT_EXV_ResponseError_B_BAT_EXV_ResponseError_B->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_BAT_EXV_RunState_B_BAT_EXV_Rsp_LIN1
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
void Rte_COMCbk_BAT_EXV_RunState_B_BAT_EXV_Rsp_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        Boolean data;
        boolean isSuccess = TRUE;
        boolean BAT_EXV_RunState_B_BAT_EXV_Rsp_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(BAT_EXV_RunState_B_BAT_EXV_Rsp_LIN1, &BAT_EXV_RunState_B_BAT_EXV_Rsp_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (Boolean)BAT_EXV_RunState_B_BAT_EXV_Rsp_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_BAT_EXV_RunState_B_BAT_EXV_RunState_B = data;
                Rte_Inst_ME11.Task_100ms_BAT_EXV_RunState_B_BAT_EXV_RunState_B->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_BAT_EXV_RunState_B_BAT_EXV_Rsp_LIN2
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
void Rte_COMCbk_BAT_EXV_RunState_B_BAT_EXV_Rsp_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        Boolean data;
        boolean isSuccess = TRUE;
        boolean BAT_EXV_RunState_B_BAT_EXV_Rsp_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(BAT_EXV_RunState_B_BAT_EXV_Rsp_LIN2, &BAT_EXV_RunState_B_BAT_EXV_Rsp_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (Boolean)BAT_EXV_RunState_B_BAT_EXV_Rsp_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_BAT_EXV_RunState_B_BAT_EXV_RunState_B = data;
                Rte_Inst_ME11.Task_100ms_BAT_EXV_RunState_B_BAT_EXV_RunState_B->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_BAT_EXV_SupplierLabel_BAT_EXV_Rsp_LIN1
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
void Rte_COMCbk_BAT_EXV_SupplierLabel_BAT_EXV_Rsp_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        Boolean data;
        boolean isSuccess = TRUE;
        boolean BAT_EXV_SupplierLabel_BAT_EXV_Rsp_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(BAT_EXV_SupplierLabel_BAT_EXV_Rsp_LIN1, &BAT_EXV_SupplierLabel_BAT_EXV_Rsp_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (Boolean)BAT_EXV_SupplierLabel_BAT_EXV_Rsp_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_BAT_EXV_SupplierLabel_BAT_EXV_SupplierLabel = data;
                Rte_Inst_ME11.Task_100ms_BAT_EXV_SupplierLabel_BAT_EXV_SupplierLabel->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_BAT_EXV_SupplierLabel_BAT_EXV_Rsp_LIN2
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
void Rte_COMCbk_BAT_EXV_SupplierLabel_BAT_EXV_Rsp_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        Boolean data;
        boolean isSuccess = TRUE;
        boolean BAT_EXV_SupplierLabel_BAT_EXV_Rsp_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(BAT_EXV_SupplierLabel_BAT_EXV_Rsp_LIN2, &BAT_EXV_SupplierLabel_BAT_EXV_Rsp_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (Boolean)BAT_EXV_SupplierLabel_BAT_EXV_Rsp_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_BAT_EXV_SupplierLabel_BAT_EXV_SupplierLabel = data;
                Rte_Inst_ME11.Task_100ms_BAT_EXV_SupplierLabel_BAT_EXV_SupplierLabel->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_BAT_EXV_VoltageState_B_BAT_EXV_Rsp_LIN1
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
void Rte_COMCbk_BAT_EXV_VoltageState_B_BAT_EXV_Rsp_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 BAT_EXV_VoltageState_B_BAT_EXV_Rsp_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(BAT_EXV_VoltageState_B_BAT_EXV_Rsp_LIN1, &BAT_EXV_VoltageState_B_BAT_EXV_Rsp_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)BAT_EXV_VoltageState_B_BAT_EXV_Rsp_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_BAT_EXV_VoltageState_B_BAT_EXV_VoltageState_B = data;
                Rte_Inst_ME11.Task_100ms_BAT_EXV_VoltageState_B_BAT_EXV_VoltageState_B->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_BAT_EXV_VoltageState_B_BAT_EXV_Rsp_LIN2
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
void Rte_COMCbk_BAT_EXV_VoltageState_B_BAT_EXV_Rsp_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 BAT_EXV_VoltageState_B_BAT_EXV_Rsp_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(BAT_EXV_VoltageState_B_BAT_EXV_Rsp_LIN2, &BAT_EXV_VoltageState_B_BAT_EXV_Rsp_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)BAT_EXV_VoltageState_B_BAT_EXV_Rsp_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_BAT_EXV_VoltageState_B_BAT_EXV_VoltageState_B = data;
                Rte_Inst_ME11.Task_100ms_BAT_EXV_VoltageState_B_BAT_EXV_VoltageState_B->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_BAT_EXV_Warning_OverTemp_BAT_EXV_Rsp_LIN2
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
void Rte_COMCbk_BAT_EXV_Warning_OverTemp_BAT_EXV_Rsp_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        Boolean data;
        boolean isSuccess = TRUE;
        boolean BAT_EXV_Warning_OverTemp_BAT_EXV_Rsp_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(BAT_EXV_Warning_OverTemp_BAT_EXV_Rsp_LIN2, &BAT_EXV_Warning_OverTemp_BAT_EXV_Rsp_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (Boolean)BAT_EXV_Warning_OverTemp_BAT_EXV_Rsp_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_BAT_EXV_Warning_OverTemp_BAT_EXV_Warning_OverTemp = data;
                Rte_Inst_ME11.Task_100ms_BAT_EXV_Warning_OverTemp_BAT_EXV_Warning_OverTemp->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_BAT_EXV_initialize_status_BAT_EXV_Rsp_LIN2
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
void Rte_COMCbk_BAT_EXV_initialize_status_BAT_EXV_Rsp_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 BAT_EXV_initialize_status_BAT_EXV_Rsp_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(BAT_EXV_initialize_status_BAT_EXV_Rsp_LIN2, &BAT_EXV_initialize_status_BAT_EXV_Rsp_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)BAT_EXV_initialize_status_BAT_EXV_Rsp_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_BAT_EXV_initialize_status_BAT_EXV_initialize_status = data;
                Rte_Inst_ME11.Task_100ms_BAT_EXV_initialize_status_BAT_EXV_initialize_status->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_BMS_10_DC_ChargeStates_EPT_IPDU_COM_BMS_10_DC_ChargeStates_EPT
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
void Rte_COMCbk_BMS_10_DC_ChargeStates_EPT_IPDU_COM_BMS_10_DC_ChargeStates_EPT(void)
{
    if (RteInitState == RTE_INITED)
    {
        BMS_10_DC_ChargeStates_EPT data;
        boolean isSuccess = TRUE;
        if (E_OK == Com_ReceiveSignalGroup(BMS_10_DC_ChargeStates_EPT_IPDU_COM_BMS_10_DC_ChargeStates_EPT))
        {
            if (E_NOT_OK == Com_ReceiveSignal(BMS_10_DC_ChargeStates_EPT_IPDU_COM_BMS_10_DC_ChargeStates_EPT_BMS_10_Chksum_IPDU_COM_BMS_10_DC_ChargeStates_EPT, &data.BMS_10_Chksum))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_10_DC_ChargeStates_EPT_IPDU_COM_BMS_10_DC_ChargeStates_EPT_BMS_10_AliveCnt_IPDU_COM_BMS_10_DC_ChargeStates_EPT, &data.BMS_10_AliveCnt))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_10_DC_ChargeStates_EPT_IPDU_COM_BMS_10_DC_ChargeStates_EPT_BMS_DCS_InletConnectSta_IPDU_COM_BMS_10_DC_ChargeStates_EPT, &data.BMS_DCS_InletConnectSta))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_10_DC_ChargeStates_EPT_IPDU_COM_BMS_10_DC_ChargeStates_EPT_BMS_DC_AC_RemChrgTime_IPDU_COM_BMS_10_DC_ChargeStates_EPT, &data.BMS_DC_AC_RemChrgTime))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_10_DC_ChargeStates_EPT_IPDU_COM_BMS_10_DC_ChargeStates_EPT_BMS_DCS_ActlChrgCurrent_IPDU_COM_BMS_10_DC_ChargeStates_EPT, &data.BMS_DCS_ActlChrgCurrent))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_10_DC_ChargeStates_EPT_IPDU_COM_BMS_10_DC_ChargeStates_EPT_BMS_DCS_ActOprtMode_IPDU_COM_BMS_10_DC_ChargeStates_EPT, &data.BMS_DCS_ActOprtMode))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_10_DC_ChargeStates_EPT_IPDU_COM_BMS_10_DC_ChargeStates_EPT_BMS_DCS_ActlChrgVoltage_IPDU_COM_BMS_10_DC_ChargeStates_EPT, &data.BMS_DCS_ActlChrgVoltage))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_10_DC_ChargeStates_EPT_IPDU_COM_BMS_10_DC_ChargeStates_EPT_BMS_DCS_ActlChrgPower_IPDU_COM_BMS_10_DC_ChargeStates_EPT, &data.BMS_DCS_ActlChrgPower))
            {
                isSuccess = FALSE;
            }
            if (isSuccess == TRUE)
            {
                if (isSuccess == TRUE)
                {
                    rte_memcpy((uint8*)&Rte_Buf_Runbl_IpmCanRx_20ms_BMS_10_DC_ChargeStates_EPT_BMS_10_DC_ChargeStates_EPT,(uint8*)&data,sizeof(BMS_10_DC_ChargeStates_EPT));
                    Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_BMS_10_DC_ChargeStates_EPT_BMS_10_DC_ChargeStates_EPT->status = RTE_E_OK;
                }
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_BMS_1_MainState_EPT_IPDU_COM_BMS_1_MainState_EPT
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
void Rte_COMCbk_BMS_1_MainState_EPT_IPDU_COM_BMS_1_MainState_EPT(void)
{
    if (RteInitState == RTE_INITED)
    {
        BMS_1_MainState_EPT data;
        boolean isSuccess = TRUE;
        if (E_OK == Com_ReceiveSignalGroup(BMS_1_MainState_EPT_IPDU_COM_BMS_1_MainState_EPT))
        {
            if (E_NOT_OK == Com_ReceiveSignal(BMS_1_MainState_EPT_IPDU_COM_BMS_1_MainState_EPT_BMS_1_Chksum_IPDU_COM_BMS_1_MainState_EPT, &data.BMS_1_Chksum))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_1_MainState_EPT_IPDU_COM_BMS_1_MainState_EPT_BMS_1_AliveCnt_IPDU_COM_BMS_1_MainState_EPT, &data.BMS_1_AliveCnt))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_1_MainState_EPT_IPDU_COM_BMS_1_MainState_EPT_BMS_ThermalrunawayWrn_IPDU_COM_BMS_1_MainState_EPT, &data.BMS_ThermalrunawayWrn))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_1_MainState_EPT_IPDU_COM_BMS_1_MainState_EPT_BMS_InsulationWrningDistgsh_IPDU_COM_BMS_1_MainState_EPT, &data.BMS_InsulationWrningDistgsh))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_1_MainState_EPT_IPDU_COM_BMS_1_MainState_EPT_BMS_ActlExchgCurnt_IPDU_COM_BMS_1_MainState_EPT, &data.BMS_ActlExchgCurnt))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_1_MainState_EPT_IPDU_COM_BMS_1_MainState_EPT_BMS_SupplyVoltageStatus_IPDU_COM_BMS_1_MainState_EPT, &data.BMS_SupplyVoltageStatus))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_1_MainState_EPT_IPDU_COM_BMS_1_MainState_EPT_BMS_Contactor_state_Precharge_IPDU_COM_BMS_1_MainState_EPT, &data.BMS_Contactor_state_Precharge))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_1_MainState_EPT_IPDU_COM_BMS_1_MainState_EPT_BMS_Contactor_state_Positive_IPDU_COM_BMS_1_MainState_EPT, &data.BMS_Contactor_state_Positive))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_1_MainState_EPT_IPDU_COM_BMS_1_MainState_EPT_BMS_Contactor_state_Negative_IPDU_COM_BMS_1_MainState_EPT, &data.BMS_Contactor_state_Negative))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_1_MainState_EPT_IPDU_COM_BMS_1_MainState_EPT_BMS_RunState_IPDU_COM_BMS_1_MainState_EPT, &data.BMS_RunState))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_1_MainState_EPT_IPDU_COM_BMS_1_MainState_EPT_BMS_DisChargeInterlockSta_IPDU_COM_BMS_1_MainState_EPT, &data.BMS_DisChargeInterlockSta))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_1_MainState_EPT_IPDU_COM_BMS_1_MainState_EPT_BMS_ChargeInterlockSta_IPDU_COM_BMS_1_MainState_EPT, &data.BMS_ChargeInterlockSta))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_1_MainState_EPT_IPDU_COM_BMS_1_MainState_EPT_BMS_Emeshutdown_Req_IPDU_COM_BMS_1_MainState_EPT, &data.BMS_Emeshutdown_Req))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_1_MainState_EPT_IPDU_COM_BMS_1_MainState_EPT_BMS_PwrTrainConnectSta_IPDU_COM_BMS_1_MainState_EPT, &data.BMS_PwrTrainConnectSta))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_1_MainState_EPT_IPDU_COM_BMS_1_MainState_EPT_BMS_ErrTabIndex_IPDU_COM_BMS_1_MainState_EPT, &data.BMS_ErrTabIndex))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_1_MainState_EPT_IPDU_COM_BMS_1_MainState_EPT_BMS_BAS_WakeUp_IPDU_COM_BMS_1_MainState_EPT, &data.BMS_BAS_WakeUp))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_1_MainState_EPT_IPDU_COM_BMS_1_MainState_EPT_BMS_ThermRunawayVlvSt_IPDU_COM_BMS_1_MainState_EPT, &data.BMS_ThermRunawayVlvSt))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_1_MainState_EPT_IPDU_COM_BMS_1_MainState_EPT_BMS_ThermRunawaySnsrFlt_IPDU_COM_BMS_1_MainState_EPT, &data.BMS_ThermRunawaySnsrFlt))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_1_MainState_EPT_IPDU_COM_BMS_1_MainState_EPT_BMS_Batt_BalanceSta_IPDU_COM_BMS_1_MainState_EPT, &data.BMS_Batt_BalanceSta))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_1_MainState_EPT_IPDU_COM_BMS_1_MainState_EPT_BMS_SysFailSta_IPDU_COM_BMS_1_MainState_EPT, &data.BMS_SysFailSta))
            {
                isSuccess = FALSE;
            }
            if (isSuccess == TRUE)
            {
                if (isSuccess == TRUE)
                {
                    rte_memcpy((uint8*)&Rte_Buf_Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT,(uint8*)&data,sizeof(BMS_1_MainState_EPT));
                    Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT->status = RTE_E_OK;
                }
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_BMS_2_BatState_EPT_IPDU_COM_BMS_2_BatState_EPT
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
void Rte_COMCbk_BMS_2_BatState_EPT_IPDU_COM_BMS_2_BatState_EPT(void)
{
    if((IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P10) == 1) || (IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P11) == 1))
    {
    Dem_UdsStatusByteType tmp = 0;
	if (E_OK == Dem_GetEventStatus(DemEventParameter_0xC11287, &tmp))
	{
		if (DEM_UDS_STATUS_TF == (tmp & DEM_UDS_STATUS_TF))
		{
			Dem_SetEventStatus(DemEventParameter_0xC11287, DEM_EVENT_STATUS_PASSED);
		}
	}
    }
    if (RteInitState == RTE_INITED)
    {
        BMS_2_BatState_EPT data;
        boolean isSuccess = TRUE;
        if (E_OK == Com_ReceiveSignalGroup(BMS_2_BatState_EPT_IPDU_COM_BMS_2_BatState_EPT))
        {
            if (E_NOT_OK == Com_ReceiveSignal(BMS_2_BatState_EPT_IPDU_COM_BMS_2_BatState_EPT_BMS_2_Chksum_IPDU_COM_BMS_2_BatState_EPT, &data.BMS_2_Chksum))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_2_BatState_EPT_IPDU_COM_BMS_2_BatState_EPT_BMS_2_AliveCnt_IPDU_COM_BMS_2_BatState_EPT, &data.BMS_2_AliveCnt))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_2_BatState_EPT_IPDU_COM_BMS_2_BatState_EPT_BMS_HVBatActlVoltage_IPDU_COM_BMS_2_BatState_EPT, &data.BMS_HVBatActlVoltage))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_2_BatState_EPT_IPDU_COM_BMS_2_BatState_EPT_BMS_BatSOC_Rpt_IPDU_COM_BMS_2_BatState_EPT, &data.BMS_BatSOC_Rpt))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_2_BatState_EPT_IPDU_COM_BMS_2_BatState_EPT_BMS_BatSOH_IPDU_COM_BMS_2_BatState_EPT, &data.BMS_BatSOH))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_2_BatState_EPT_IPDU_COM_BMS_2_BatState_EPT_BMS_HVBatActlVoltageV_IPDU_COM_BMS_2_BatState_EPT, &data.BMS_HVBatActlVoltageV))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_2_BatState_EPT_IPDU_COM_BMS_2_BatState_EPT_BMS_BatSOC_Actl_IPDU_COM_BMS_2_BatState_EPT, &data.BMS_BatSOC_Actl))
            {
                isSuccess = FALSE;
            }
            if (isSuccess == TRUE)
            {
                if (isSuccess == TRUE)
                {
                    rte_memcpy((uint8*)&Rte_Buf_Runbl_IpmCanRx_20ms_BMS_2_BatState_EPT_BMS_2_BatState_EPT,(uint8*)&data,sizeof(BMS_2_BatState_EPT));
                    Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_BMS_2_BatState_EPT_BMS_2_BatState_EPT->status = RTE_E_OK;
                }
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_BMS_3_DC_ChargeState_EPT_IPDU_COM_BMS_3_DC_ChargeState_EPT
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
void Rte_COMCbk_BMS_3_DC_ChargeState_EPT_IPDU_COM_BMS_3_DC_ChargeState_EPT(void)
{
    if (RteInitState == RTE_INITED)
    {
        BMS_3_DC_ChargeState_EPT data;
        boolean isSuccess = TRUE;
        if (E_OK == Com_ReceiveSignalGroup(BMS_3_DC_ChargeState_EPT_IPDU_COM_BMS_3_DC_ChargeState_EPT))
        {
            if (E_NOT_OK == Com_ReceiveSignal(BMS_3_DC_ChargeState_EPT_IPDU_COM_BMS_3_DC_ChargeState_EPT_BMS_3_Chksum_IPDU_COM_BMS_3_DC_ChargeState_EPT, &data.BMS_3_Chksum))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_3_DC_ChargeState_EPT_IPDU_COM_BMS_3_DC_ChargeState_EPT_BMS_3_AliveCnt_IPDU_COM_BMS_3_DC_ChargeState_EPT, &data.BMS_3_AliveCnt))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_3_DC_ChargeState_EPT_IPDU_COM_BMS_3_DC_ChargeState_EPT_BMS_TempMax_DCChargeSocket_IPDU_COM_BMS_3_DC_ChargeState_EPT, &data.BMS_TempMax_DCChargeSocket))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_3_DC_ChargeState_EPT_IPDU_COM_BMS_3_DC_ChargeState_EPT_BMS_PCB_TempMax_IPDU_COM_BMS_3_DC_ChargeState_EPT, &data.BMS_PCB_TempMax))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_3_DC_ChargeState_EPT_IPDU_COM_BMS_3_DC_ChargeState_EPT_BMS_MaxAllowChrgCur_DC_IPDU_COM_BMS_3_DC_ChargeState_EPT, &data.BMS_MaxAllowChrgCur_DC))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_3_DC_ChargeState_EPT_IPDU_COM_BMS_3_DC_ChargeState_EPT_BMS_Electronic_Lock_Ctrl_IPDU_COM_BMS_3_DC_ChargeState_EPT, &data.BMS_Electronic_Lock_Ctrl))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_3_DC_ChargeState_EPT_IPDU_COM_BMS_3_DC_ChargeState_EPT_BMS_MaxAllowChrgVol_DC_IPDU_COM_BMS_3_DC_ChargeState_EPT, &data.BMS_MaxAllowChrgVol_DC))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_3_DC_ChargeState_EPT_IPDU_COM_BMS_3_DC_ChargeState_EPT_BMS_DCS_ChrgAPlus_IPDU_COM_BMS_3_DC_ChargeState_EPT, &data.BMS_DCS_ChrgAPlus))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_3_DC_ChargeState_EPT_IPDU_COM_BMS_3_DC_ChargeState_EPT_BMS_DCS_ChargeRequest_IPDU_COM_BMS_3_DC_ChargeState_EPT, &data.BMS_DCS_ChargeRequest))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_3_DC_ChargeState_EPT_IPDU_COM_BMS_3_DC_ChargeState_EPT_BMS_Contactor_state_DCCharger_IPDU_COM_BMS_3_DC_ChargeState_EPT, &data.BMS_Contactor_state_DCCharger))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_3_DC_ChargeState_EPT_IPDU_COM_BMS_3_DC_ChargeState_EPT_BMS_Electronic_Lock_State_IPDU_COM_BMS_3_DC_ChargeState_EPT, &data.BMS_Electronic_Lock_State))
            {
                isSuccess = FALSE;
            }
            if (isSuccess == TRUE)
            {
                if (isSuccess == TRUE)
                {
                    rte_memcpy((uint8*)&Rte_Buf_Runbl_IpmCanRx_20ms_BMS_3_DC_ChargeState_EPT_BMS_3_DC_ChargeState_EPT,(uint8*)&data,sizeof(BMS_3_DC_ChargeState_EPT));
                    Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_BMS_3_DC_ChargeState_EPT_BMS_3_DC_ChargeState_EPT->status = RTE_E_OK;
                }
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_BMS_4_AC_ChargeState_EPT_IPDU_COM_BMS_4_AC_ChargeState_EPT
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
void Rte_COMCbk_BMS_4_AC_ChargeState_EPT_IPDU_COM_BMS_4_AC_ChargeState_EPT(void)
{
    if (RteInitState == RTE_INITED)
    {
        BMS_4_AC_ChargeState_EPT data;
        boolean isSuccess = TRUE;
        if (E_OK == Com_ReceiveSignalGroup(BMS_4_AC_ChargeState_EPT_IPDU_COM_BMS_4_AC_ChargeState_EPT))
        {
            if (E_NOT_OK == Com_ReceiveSignal(BMS_4_AC_ChargeState_EPT_IPDU_COM_BMS_4_AC_ChargeState_EPT_BMS_4_Chksum_IPDU_COM_BMS_4_AC_ChargeState_EPT, &data.BMS_4_Chksum))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_4_AC_ChargeState_EPT_IPDU_COM_BMS_4_AC_ChargeState_EPT_BMS_4_AliveCnt_IPDU_COM_BMS_4_AC_ChargeState_EPT, &data.BMS_4_AliveCnt))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_4_AC_ChargeState_EPT_IPDU_COM_BMS_4_AC_ChargeState_EPT_BMS_ACChrgAtclSta_IPDU_COM_BMS_4_AC_ChargeState_EPT, &data.BMS_ACChrgAtclSta))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_4_AC_ChargeState_EPT_IPDU_COM_BMS_4_AC_ChargeState_EPT_BMS_OutletCoolantActlTempValid_IPDU_COM_BMS_4_AC_ChargeState_EPT, &data.BMS_OutletCoolantActlTempValid))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_4_AC_ChargeState_EPT_IPDU_COM_BMS_4_AC_ChargeState_EPT_BMS_OutletCoolantActlTemp_IPDU_COM_BMS_4_AC_ChargeState_EPT, &data.BMS_OutletCoolantActlTemp))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_4_AC_ChargeState_EPT_IPDU_COM_BMS_4_AC_ChargeState_EPT_BMS_InletCoolantActlTempValid_IPDU_COM_BMS_4_AC_ChargeState_EPT, &data.BMS_InletCoolantActlTempValid))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_4_AC_ChargeState_EPT_IPDU_COM_BMS_4_AC_ChargeState_EPT_BMS_InletCoolantActlTemp_IPDU_COM_BMS_4_AC_ChargeState_EPT, &data.BMS_InletCoolantActlTemp))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_4_AC_ChargeState_EPT_IPDU_COM_BMS_4_AC_ChargeState_EPT_BMS_IsoResistance_IPDU_COM_BMS_4_AC_ChargeState_EPT, &data.BMS_IsoResistance))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_4_AC_ChargeState_EPT_IPDU_COM_BMS_4_AC_ChargeState_EPT_BMS_MaxChrgVoltage_AC_IPDU_COM_BMS_4_AC_ChargeState_EPT, &data.BMS_MaxChrgVoltage_AC))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_4_AC_ChargeState_EPT_IPDU_COM_BMS_4_AC_ChargeState_EPT_BMS_MaxChrgCurrent_AC_IPDU_COM_BMS_4_AC_ChargeState_EPT, &data.BMS_MaxChrgCurrent_AC))
            {
                isSuccess = FALSE;
            }
            if (isSuccess == TRUE)
            {
                if (isSuccess == TRUE)
                {
                    rte_memcpy((uint8*)&Rte_Buf_Runbl_IpmCanRx_20ms_BMS_4_AC_ChargeState_EPT_BMS_4_AC_ChargeState_EPT,(uint8*)&data,sizeof(BMS_4_AC_ChargeState_EPT));
                    Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_BMS_4_AC_ChargeState_EPT_BMS_4_AC_ChargeState_EPT->status = RTE_E_OK;
                }
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_BMS_5_BatTemp_EPT_IPDU_COM_BMS_5_BatTemp_EPT
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
void Rte_COMCbk_BMS_5_BatTemp_EPT_IPDU_COM_BMS_5_BatTemp_EPT(void)
{
    if (RteInitState == RTE_INITED)
    {
        BMS_5_BatTemp_EPT data;
        boolean isSuccess = TRUE;
        if (E_OK == Com_ReceiveSignalGroup(BMS_5_BatTemp_EPT_IPDU_COM_BMS_5_BatTemp_EPT))
        {
            if (E_NOT_OK == Com_ReceiveSignal(BMS_5_BatTemp_EPT_IPDU_COM_BMS_5_BatTemp_EPT_BMS_5_Chksum_IPDU_COM_BMS_5_BatTemp_EPT, &data.BMS_5_Chksum))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_5_BatTemp_EPT_IPDU_COM_BMS_5_BatTemp_EPT_BMS_5_AliveCnt_IPDU_COM_BMS_5_BatTemp_EPT, &data.BMS_5_AliveCnt))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_5_BatTemp_EPT_IPDU_COM_BMS_5_BatTemp_EPT_BMS_HVBatCellTempValid_IPDU_COM_BMS_5_BatTemp_EPT, &data.BMS_HVBatCellTempValid))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_5_BatTemp_EPT_IPDU_COM_BMS_5_BatTemp_EPT_BMS_MinTempProbeCod_IPDU_COM_BMS_5_BatTemp_EPT, &data.BMS_MinTempProbeCod))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_5_BatTemp_EPT_IPDU_COM_BMS_5_BatTemp_EPT_BMS_HVBatCellTempAve_IPDU_COM_BMS_5_BatTemp_EPT, &data.BMS_HVBatCellTempAve))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_5_BatTemp_EPT_IPDU_COM_BMS_5_BatTemp_EPT_BMS_HVBatCellTempMax_IPDU_COM_BMS_5_BatTemp_EPT, &data.BMS_HVBatCellTempMax))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_5_BatTemp_EPT_IPDU_COM_BMS_5_BatTemp_EPT_BMS_HVBatCellTempMin_IPDU_COM_BMS_5_BatTemp_EPT, &data.BMS_HVBatCellTempMin))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_5_BatTemp_EPT_IPDU_COM_BMS_5_BatTemp_EPT_BMS_MaxTempProbeCod_IPDU_COM_BMS_5_BatTemp_EPT, &data.BMS_MaxTempProbeCod))
            {
                isSuccess = FALSE;
            }
            if (isSuccess == TRUE)
            {
                if (isSuccess == TRUE)
                {
                    rte_memcpy((uint8*)&Rte_Buf_Runbl_IpmCanRx_100ms_BMS_5_BatTemp_EPT_BMS_5_BatTemp_EPT,(uint8*)&data,sizeof(BMS_5_BatTemp_EPT));
                    Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_BMS_5_BatTemp_EPT_BMS_5_BatTemp_EPT->status = RTE_E_OK;
                }
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_BMS_6_DischrgRecup_EPT_IPDU_COM_BMS_6_DischrgRecup_EPT
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
void Rte_COMCbk_BMS_6_DischrgRecup_EPT_IPDU_COM_BMS_6_DischrgRecup_EPT(void)
{
    if (RteInitState == RTE_INITED)
    {
        BMS_6_DischrgRecup_EPT data;
        boolean isSuccess = TRUE;
        if (E_OK == Com_ReceiveSignalGroup(BMS_6_DischrgRecup_EPT_IPDU_COM_BMS_6_DischrgRecup_EPT))
        {
            if (E_NOT_OK == Com_ReceiveSignal(BMS_6_DischrgRecup_EPT_IPDU_COM_BMS_6_DischrgRecup_EPT_BMS_MaxConDisCurnt_IPDU_COM_BMS_6_DischrgRecup_EPT, &data.BMS_MaxConDisCurnt))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_6_DischrgRecup_EPT_IPDU_COM_BMS_6_DischrgRecup_EPT_BMS_PwrRecupMaxConChrgCurnt_IPDU_COM_BMS_6_DischrgRecup_EPT, &data.BMS_PwrRecupMaxConChrgCurnt))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_6_DischrgRecup_EPT_IPDU_COM_BMS_6_DischrgRecup_EPT_BMS_MaxInstanDisCurnt_IPDU_COM_BMS_6_DischrgRecup_EPT, &data.BMS_MaxInstanDisCurnt))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_6_DischrgRecup_EPT_IPDU_COM_BMS_6_DischrgRecup_EPT_BMS_PwrRecupMaxInstanChrgCurnt_IPDU_COM_BMS_6_DischrgRecup_EPT, &data.BMS_PwrRecupMaxInstanChrgCurnt))
            {
                isSuccess = FALSE;
            }
            if (isSuccess == TRUE)
            {
                if (isSuccess == TRUE)
                {
                    rte_memcpy((uint8*)&Rte_Buf_Runbl_IpmCanRx_20ms_BMS_6_DischrgRecup_EPT_BMS_6_DischrgRecup_EPT,(uint8*)&data,sizeof(BMS_6_DischrgRecup_EPT));
                    Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_BMS_6_DischrgRecup_EPT_BMS_6_DischrgRecup_EPT->status = RTE_E_OK;
                }
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_BMS_7_CellVolt_EPT_IPDU_COM_BMS_7_CellVolt_EPT
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
void Rte_COMCbk_BMS_7_CellVolt_EPT_IPDU_COM_BMS_7_CellVolt_EPT(void)
{
    if (RteInitState == RTE_INITED)
    {
        BMS_7_CellVolt_EPT data;
        boolean isSuccess = TRUE;
        if (E_OK == Com_ReceiveSignalGroup(BMS_7_CellVolt_EPT_IPDU_COM_BMS_7_CellVolt_EPT))
        {
            if (E_NOT_OK == Com_ReceiveSignal(BMS_7_CellVolt_EPT_IPDU_COM_BMS_7_CellVolt_EPT_BMS_CellVolMax_IPDU_COM_BMS_7_CellVolt_EPT, &data.BMS_CellVolMax))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_7_CellVolt_EPT_IPDU_COM_BMS_7_CellVolt_EPT_BMS_MaxVolCellCod_IPDU_COM_BMS_7_CellVolt_EPT, &data.BMS_MaxVolCellCod))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_7_CellVolt_EPT_IPDU_COM_BMS_7_CellVolt_EPT_BMS_CellVolAve_IPDU_COM_BMS_7_CellVolt_EPT, &data.BMS_CellVolAve))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_7_CellVolt_EPT_IPDU_COM_BMS_7_CellVolt_EPT_BMS_CellVolMin_IPDU_COM_BMS_7_CellVolt_EPT, &data.BMS_CellVolMin))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_7_CellVolt_EPT_IPDU_COM_BMS_7_CellVolt_EPT_BMS_MinVolCellCod_IPDU_COM_BMS_7_CellVolt_EPT, &data.BMS_MinVolCellCod))
            {
                isSuccess = FALSE;
            }
            if (isSuccess == TRUE)
            {
                if (isSuccess == TRUE)
                {
                    rte_memcpy((uint8*)&Rte_Buf_Runbl_IpmCanRx_20ms_BMS_7_CellVolt_EPT_BMS_7_CellVolt_EPT,(uint8*)&data,sizeof(BMS_7_CellVolt_EPT));
                    Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_20ms_BMS_7_CellVolt_EPT_BMS_7_CellVolt_EPT->status = RTE_E_OK;
                }
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_BMS_9_BattInfo_EPT_IPDU_COM_BMS_9_BattInfo_EPT
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
void Rte_COMCbk_BMS_9_BattInfo_EPT_IPDU_COM_BMS_9_BattInfo_EPT(void)
{
    if (RteInitState == RTE_INITED)
    {
        BMS_9_BattInfo_EPT data;
        boolean isSuccess = TRUE;
        if (E_OK == Com_ReceiveSignalGroup(BMS_9_BattInfo_EPT_IPDU_COM_BMS_9_BattInfo_EPT))
        {
            if (E_NOT_OK == Com_ReceiveSignal(BMS_9_BattInfo_EPT_IPDU_COM_BMS_9_BattInfo_EPT_BMS_BatteryType_IPDU_COM_BMS_9_BattInfo_EPT, &data.BMS_BatteryType))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_9_BattInfo_EPT_IPDU_COM_BMS_9_BattInfo_EPT_BMS_HW_Version_IPDU_COM_BMS_9_BattInfo_EPT, &data.BMS_HW_Version))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_9_BattInfo_EPT_IPDU_COM_BMS_9_BattInfo_EPT_BMS_Pack_Identity_IPDU_COM_BMS_9_BattInfo_EPT, &data.BMS_Pack_Identity))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_9_BattInfo_EPT_IPDU_COM_BMS_9_BattInfo_EPT_BMS_SW_Version_IPDU_COM_BMS_9_BattInfo_EPT, &data.BMS_SW_Version))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_9_BattInfo_EPT_IPDU_COM_BMS_9_BattInfo_EPT_BMS_BatCapacity_IPDU_COM_BMS_9_BattInfo_EPT, &data.BMS_BatCapacity))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(BMS_9_BattInfo_EPT_IPDU_COM_BMS_9_BattInfo_EPT_BMS_NomCellCap_IPDU_COM_BMS_9_BattInfo_EPT, &data.BMS_NomCellCap))
            {
                isSuccess = FALSE;
            }
            if (isSuccess == TRUE)
            {
                if (isSuccess == TRUE)
                {
                    rte_memcpy((uint8*)&Rte_Buf_Runbl_IpmCanRx_100ms_BMS_9_BattInfo_EPT_BMS_9_BattInfo_EPT,(uint8*)&data,sizeof(BMS_9_BattInfo_EPT));
                    Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_BMS_9_BattInfo_EPT_BMS_9_BattInfo_EPT->status = RTE_E_OK;
                }
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_BatPMP_PumpDryRunningSta_BatPMP_Sts_LIN1
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
void Rte_COMCbk_BatPMP_PumpDryRunningSta_BatPMP_Sts_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        Boolean data;
        boolean isSuccess = TRUE;
        boolean BatPMP_PumpDryRunningSta_BatPMP_Sts_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(BatPMP_PumpDryRunningSta_BatPMP_Sts_LIN1, &BatPMP_PumpDryRunningSta_BatPMP_Sts_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (Boolean)BatPMP_PumpDryRunningSta_BatPMP_Sts_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_BatPMP_PumpDryRunningSta_BatPMP_PumpDryRunningSta = data;
                Rte_Inst_ME11.Task_100ms_BatPMP_PumpDryRunningSta_BatPMP_PumpDryRunningSta->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_BatPMP_PumpDryRunningSta_BatPMP_Sts_LIN2
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
void Rte_COMCbk_BatPMP_PumpDryRunningSta_BatPMP_Sts_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        Boolean data;
        boolean isSuccess = TRUE;
        boolean BatPMP_PumpDryRunningSta_BatPMP_Sts_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(BatPMP_PumpDryRunningSta_BatPMP_Sts_LIN2, &BatPMP_PumpDryRunningSta_BatPMP_Sts_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (Boolean)BatPMP_PumpDryRunningSta_BatPMP_Sts_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_BatPMP_PumpDryRunningSta_BatPMP_PumpDryRunningSta = data;
                Rte_Inst_ME11.Task_100ms_BatPMP_PumpDryRunningSta_BatPMP_PumpDryRunningSta->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_BatPMP_PumpInputVolt_BatPMP_Sts_LIN1
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
void Rte_COMCbk_BatPMP_PumpInputVolt_BatPMP_Sts_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 BatPMP_PumpInputVolt_BatPMP_Sts_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(BatPMP_PumpInputVolt_BatPMP_Sts_LIN1, &BatPMP_PumpInputVolt_BatPMP_Sts_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)BatPMP_PumpInputVolt_BatPMP_Sts_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_BatPMP_PumpInputVolt_BatPMP_PumpInputVolt = data;
                Rte_Inst_ME11.Task_100ms_BatPMP_PumpInputVolt_BatPMP_PumpInputVolt->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_BatPMP_PumpInputVolt_BatPMP_Sts_LIN2
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
void Rte_COMCbk_BatPMP_PumpInputVolt_BatPMP_Sts_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 BatPMP_PumpInputVolt_BatPMP_Sts_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(BatPMP_PumpInputVolt_BatPMP_Sts_LIN2, &BatPMP_PumpInputVolt_BatPMP_Sts_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)BatPMP_PumpInputVolt_BatPMP_Sts_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_BatPMP_PumpInputVolt_BatPMP_PumpInputVolt = data;
                Rte_Inst_ME11.Task_100ms_BatPMP_PumpInputVolt_BatPMP_PumpInputVolt->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_BatPMP_PumpMotorSta_BatPMP_Sts_LIN1
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
void Rte_COMCbk_BatPMP_PumpMotorSta_BatPMP_Sts_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 BatPMP_PumpMotorSta_BatPMP_Sts_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(BatPMP_PumpMotorSta_BatPMP_Sts_LIN1, &BatPMP_PumpMotorSta_BatPMP_Sts_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)BatPMP_PumpMotorSta_BatPMP_Sts_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_BatPMP_PumpMotorSta_BatPMP_PumpMotorSta = data;
                Rte_Inst_ME11.Task_100ms_BatPMP_PumpMotorSta_BatPMP_PumpMotorSta->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_BatPMP_PumpMotorSta_BatPMP_Sts_LIN2
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
void Rte_COMCbk_BatPMP_PumpMotorSta_BatPMP_Sts_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 BatPMP_PumpMotorSta_BatPMP_Sts_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(BatPMP_PumpMotorSta_BatPMP_Sts_LIN2, &BatPMP_PumpMotorSta_BatPMP_Sts_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)BatPMP_PumpMotorSta_BatPMP_Sts_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_BatPMP_PumpMotorSta_BatPMP_PumpMotorSta = data;
                Rte_Inst_ME11.Task_100ms_BatPMP_PumpMotorSta_BatPMP_PumpMotorSta->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_BatPMP_PumpPowerSta_BatPMP_Sts_LIN1
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
void Rte_COMCbk_BatPMP_PumpPowerSta_BatPMP_Sts_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 BatPMP_PumpPowerSta_BatPMP_Sts_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(BatPMP_PumpPowerSta_BatPMP_Sts_LIN1, &BatPMP_PumpPowerSta_BatPMP_Sts_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)BatPMP_PumpPowerSta_BatPMP_Sts_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_BatPMP_PumpPowerSta_BatPMP_PumpPowerSta = data;
                Rte_Inst_ME11.Task_100ms_BatPMP_PumpPowerSta_BatPMP_PumpPowerSta->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_BatPMP_PumpPowerSta_BatPMP_Sts_LIN2
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
void Rte_COMCbk_BatPMP_PumpPowerSta_BatPMP_Sts_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 BatPMP_PumpPowerSta_BatPMP_Sts_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(BatPMP_PumpPowerSta_BatPMP_Sts_LIN2, &BatPMP_PumpPowerSta_BatPMP_Sts_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)BatPMP_PumpPowerSta_BatPMP_Sts_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_BatPMP_PumpPowerSta_BatPMP_PumpPowerSta = data;
                Rte_Inst_ME11.Task_100ms_BatPMP_PumpPowerSta_BatPMP_PumpPowerSta->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_BatPMP_PumpTempSta_BatPMP_Sts_LIN1
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
void Rte_COMCbk_BatPMP_PumpTempSta_BatPMP_Sts_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 BatPMP_PumpTempSta_BatPMP_Sts_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(BatPMP_PumpTempSta_BatPMP_Sts_LIN1, &BatPMP_PumpTempSta_BatPMP_Sts_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)BatPMP_PumpTempSta_BatPMP_Sts_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_BatPMP_PumpTempSta_BatPMP_PumpTempSta = data;
                Rte_Inst_ME11.Task_100ms_BatPMP_PumpTempSta_BatPMP_PumpTempSta->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_BatPMP_PumpTempSta_BatPMP_Sts_LIN2
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
void Rte_COMCbk_BatPMP_PumpTempSta_BatPMP_Sts_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 BatPMP_PumpTempSta_BatPMP_Sts_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(BatPMP_PumpTempSta_BatPMP_Sts_LIN2, &BatPMP_PumpTempSta_BatPMP_Sts_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)BatPMP_PumpTempSta_BatPMP_Sts_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_BatPMP_PumpTempSta_BatPMP_PumpTempSta = data;
                Rte_Inst_ME11.Task_100ms_BatPMP_PumpTempSta_BatPMP_PumpTempSta->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_BatPMP_RESP_ERROR_BatPMP_Sts_LIN1
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
void Rte_COMCbk_BatPMP_RESP_ERROR_BatPMP_Sts_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        Boolean data;
        boolean isSuccess = TRUE;
        boolean BatPMP_RESP_ERROR_BatPMP_Sts_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(BatPMP_RESP_ERROR_BatPMP_Sts_LIN1, &BatPMP_RESP_ERROR_BatPMP_Sts_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (Boolean)BatPMP_RESP_ERROR_BatPMP_Sts_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_BatPMP_RESP_ERROR_BatPMP_RESP_ERROR = data;
                Rte_Inst_ME11.Task_100ms_BatPMP_RESP_ERROR_BatPMP_RESP_ERROR->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_BatPMP_RESP_ERROR_BatPMP_Sts_LIN2
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
void Rte_COMCbk_BatPMP_RESP_ERROR_BatPMP_Sts_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        Boolean data;
        boolean isSuccess = TRUE;
        boolean BatPMP_RESP_ERROR_BatPMP_Sts_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(BatPMP_RESP_ERROR_BatPMP_Sts_LIN2, &BatPMP_RESP_ERROR_BatPMP_Sts_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (Boolean)BatPMP_RESP_ERROR_BatPMP_Sts_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_BatPMP_RESP_ERROR_BatPMP_RESP_ERROR = data;
                Rte_Inst_ME11.Task_100ms_BatPMP_RESP_ERROR_BatPMP_RESP_ERROR->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_BatPMP_RealRPM_BatPMP_Sts_LIN1
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
void Rte_COMCbk_BatPMP_RealRPM_BatPMP_Sts_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 BatPMP_RealRPM_BatPMP_Sts_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(BatPMP_RealRPM_BatPMP_Sts_LIN1, &BatPMP_RealRPM_BatPMP_Sts_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)BatPMP_RealRPM_BatPMP_Sts_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_BatPMP_RealRPM_BatPMP_RealRPM = data;
                Rte_Inst_ME11.Task_100ms_BatPMP_RealRPM_BatPMP_RealRPM->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_BatPMP_RealRPM_BatPMP_Sts_LIN2
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
void Rte_COMCbk_BatPMP_RealRPM_BatPMP_Sts_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 BatPMP_RealRPM_BatPMP_Sts_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(BatPMP_RealRPM_BatPMP_Sts_LIN2, &BatPMP_RealRPM_BatPMP_Sts_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)BatPMP_RealRPM_BatPMP_Sts_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_BatPMP_RealRPM_BatPMP_RealRPM = data;
                Rte_Inst_ME11.Task_100ms_BatPMP_RealRPM_BatPMP_RealRPM->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_Bat_EXV_HWVersion_Bat_EXV_Version_LIN1
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
void Rte_COMCbk_Bat_EXV_HWVersion_Bat_EXV_Version_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 Bat_EXV_HWVersion_Bat_EXV_Version_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(Bat_EXV_HWVersion_Bat_EXV_Version_LIN1, &Bat_EXV_HWVersion_Bat_EXV_Version_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)Bat_EXV_HWVersion_Bat_EXV_Version_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_Bat_EXV_HWVersion_Bat_EXV_HWVersion = data;
                Rte_Inst_ME11.Task_100ms_Bat_EXV_HWVersion_Bat_EXV_HWVersion->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_Bat_EXV_HWVersion_Bat_EXV_Version_LIN2
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
void Rte_COMCbk_Bat_EXV_HWVersion_Bat_EXV_Version_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 Bat_EXV_HWVersion_Bat_EXV_Version_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(Bat_EXV_HWVersion_Bat_EXV_Version_LIN2, &Bat_EXV_HWVersion_Bat_EXV_Version_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)Bat_EXV_HWVersion_Bat_EXV_Version_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_Bat_EXV_HWVersion_Bat_EXV_HWVersion = data;
                Rte_Inst_ME11.Task_100ms_Bat_EXV_HWVersion_Bat_EXV_HWVersion->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_Bat_EXV_PartNumber_Bat_EXV_Version_LIN1
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
void Rte_COMCbk_Bat_EXV_PartNumber_Bat_EXV_Version_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 Bat_EXV_PartNumber_Bat_EXV_Version_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(Bat_EXV_PartNumber_Bat_EXV_Version_LIN1, &Bat_EXV_PartNumber_Bat_EXV_Version_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)Bat_EXV_PartNumber_Bat_EXV_Version_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_Bat_EXV_PartNumber_Bat_EXV_PartNumber = data;
                Rte_Inst_ME11.Task_100ms_Bat_EXV_PartNumber_Bat_EXV_PartNumber->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_Bat_EXV_PartNumber_Bat_EXV_Version_LIN2
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
void Rte_COMCbk_Bat_EXV_PartNumber_Bat_EXV_Version_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 Bat_EXV_PartNumber_Bat_EXV_Version_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(Bat_EXV_PartNumber_Bat_EXV_Version_LIN2, &Bat_EXV_PartNumber_Bat_EXV_Version_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)Bat_EXV_PartNumber_Bat_EXV_Version_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_Bat_EXV_PartNumber_Bat_EXV_PartNumber = data;
                Rte_Inst_ME11.Task_100ms_Bat_EXV_PartNumber_Bat_EXV_PartNumber->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_Bat_EXV_ProjectCode1_Bat_EXV_Version_LIN1
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
void Rte_COMCbk_Bat_EXV_ProjectCode1_Bat_EXV_Version_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 Bat_EXV_ProjectCode1_Bat_EXV_Version_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(Bat_EXV_ProjectCode1_Bat_EXV_Version_LIN1, &Bat_EXV_ProjectCode1_Bat_EXV_Version_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)Bat_EXV_ProjectCode1_Bat_EXV_Version_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_Bat_EXV_ProjectCode1_Bat_EXV_ProjectCode1 = data;
                Rte_Inst_ME11.Task_100ms_Bat_EXV_ProjectCode1_Bat_EXV_ProjectCode1->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_Bat_EXV_ProjectCode1_Bat_EXV_Version_LIN2
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
void Rte_COMCbk_Bat_EXV_ProjectCode1_Bat_EXV_Version_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 Bat_EXV_ProjectCode1_Bat_EXV_Version_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(Bat_EXV_ProjectCode1_Bat_EXV_Version_LIN2, &Bat_EXV_ProjectCode1_Bat_EXV_Version_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)Bat_EXV_ProjectCode1_Bat_EXV_Version_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_Bat_EXV_ProjectCode1_Bat_EXV_ProjectCode1 = data;
                Rte_Inst_ME11.Task_100ms_Bat_EXV_ProjectCode1_Bat_EXV_ProjectCode1->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_Bat_EXV_ProjectCode2_Bat_EXV_Version_LIN1
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
void Rte_COMCbk_Bat_EXV_ProjectCode2_Bat_EXV_Version_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 Bat_EXV_ProjectCode2_Bat_EXV_Version_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(Bat_EXV_ProjectCode2_Bat_EXV_Version_LIN1, &Bat_EXV_ProjectCode2_Bat_EXV_Version_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)Bat_EXV_ProjectCode2_Bat_EXV_Version_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_Bat_EXV_ProjectCode2_Bat_EXV_ProjectCode2 = data;
                Rte_Inst_ME11.Task_100ms_Bat_EXV_ProjectCode2_Bat_EXV_ProjectCode2->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_Bat_EXV_ProjectCode2_Bat_EXV_Version_LIN2
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
void Rte_COMCbk_Bat_EXV_ProjectCode2_Bat_EXV_Version_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 Bat_EXV_ProjectCode2_Bat_EXV_Version_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(Bat_EXV_ProjectCode2_Bat_EXV_Version_LIN2, &Bat_EXV_ProjectCode2_Bat_EXV_Version_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)Bat_EXV_ProjectCode2_Bat_EXV_Version_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_Bat_EXV_ProjectCode2_Bat_EXV_ProjectCode2 = data;
                Rte_Inst_ME11.Task_100ms_Bat_EXV_ProjectCode2_Bat_EXV_ProjectCode2->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_Bat_EXV_SWVersion_Main_Bat_EXV_Version_LIN1
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
void Rte_COMCbk_Bat_EXV_SWVersion_Main_Bat_EXV_Version_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 Bat_EXV_SWVersion_Main_Bat_EXV_Version_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(Bat_EXV_SWVersion_Main_Bat_EXV_Version_LIN1, &Bat_EXV_SWVersion_Main_Bat_EXV_Version_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)Bat_EXV_SWVersion_Main_Bat_EXV_Version_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_Bat_EXV_SWVersion_Main_Bat_EXV_SWVersion_Main = data;
                Rte_Inst_ME11.Task_100ms_Bat_EXV_SWVersion_Main_Bat_EXV_SWVersion_Main->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_Bat_EXV_SWVersion_Main_Bat_EXV_Version_LIN2
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
void Rte_COMCbk_Bat_EXV_SWVersion_Main_Bat_EXV_Version_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 Bat_EXV_SWVersion_Main_Bat_EXV_Version_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(Bat_EXV_SWVersion_Main_Bat_EXV_Version_LIN2, &Bat_EXV_SWVersion_Main_Bat_EXV_Version_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)Bat_EXV_SWVersion_Main_Bat_EXV_Version_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_Bat_EXV_SWVersion_Main_Bat_EXV_SWVersion_Main = data;
                Rte_Inst_ME11.Task_100ms_Bat_EXV_SWVersion_Main_Bat_EXV_SWVersion_Main->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_Bat_EXV_SWVersion_Patch_Bat_EXV_Version_LIN1
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
void Rte_COMCbk_Bat_EXV_SWVersion_Patch_Bat_EXV_Version_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 Bat_EXV_SWVersion_Patch_Bat_EXV_Version_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(Bat_EXV_SWVersion_Patch_Bat_EXV_Version_LIN1, &Bat_EXV_SWVersion_Patch_Bat_EXV_Version_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)Bat_EXV_SWVersion_Patch_Bat_EXV_Version_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_Bat_EXV_SWVersion_Patch_Bat_EXV_SWVersion_Patch = data;
                Rte_Inst_ME11.Task_100ms_Bat_EXV_SWVersion_Patch_Bat_EXV_SWVersion_Patch->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_Bat_EXV_SWVersion_Patch_Bat_EXV_Version_LIN2
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
void Rte_COMCbk_Bat_EXV_SWVersion_Patch_Bat_EXV_Version_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 Bat_EXV_SWVersion_Patch_Bat_EXV_Version_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(Bat_EXV_SWVersion_Patch_Bat_EXV_Version_LIN2, &Bat_EXV_SWVersion_Patch_Bat_EXV_Version_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)Bat_EXV_SWVersion_Patch_Bat_EXV_Version_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_Bat_EXV_SWVersion_Patch_Bat_EXV_SWVersion_Patch = data;
                Rte_Inst_ME11.Task_100ms_Bat_EXV_SWVersion_Patch_Bat_EXV_SWVersion_Patch->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_Bat_EXV_SWVersion_Sub_Bat_EXV_Version_LIN1
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
void Rte_COMCbk_Bat_EXV_SWVersion_Sub_Bat_EXV_Version_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 Bat_EXV_SWVersion_Sub_Bat_EXV_Version_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(Bat_EXV_SWVersion_Sub_Bat_EXV_Version_LIN1, &Bat_EXV_SWVersion_Sub_Bat_EXV_Version_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)Bat_EXV_SWVersion_Sub_Bat_EXV_Version_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_Bat_EXV_SWVersion_Sub_Bat_EXV_SWVersion_Sub = data;
                Rte_Inst_ME11.Task_100ms_Bat_EXV_SWVersion_Sub_Bat_EXV_SWVersion_Sub->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_Bat_EXV_SWVersion_Sub_Bat_EXV_Version_LIN2
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
void Rte_COMCbk_Bat_EXV_SWVersion_Sub_Bat_EXV_Version_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 Bat_EXV_SWVersion_Sub_Bat_EXV_Version_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(Bat_EXV_SWVersion_Sub_Bat_EXV_Version_LIN2, &Bat_EXV_SWVersion_Sub_Bat_EXV_Version_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)Bat_EXV_SWVersion_Sub_Bat_EXV_Version_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_Bat_EXV_SWVersion_Sub_Bat_EXV_SWVersion_Sub = data;
                Rte_Inst_ME11.Task_100ms_Bat_EXV_SWVersion_Sub_Bat_EXV_SWVersion_Sub->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_Bat_EXV_SupplierNumber_Bat_EXV_Version_LIN1
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
void Rte_COMCbk_Bat_EXV_SupplierNumber_Bat_EXV_Version_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 Bat_EXV_SupplierNumber_Bat_EXV_Version_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(Bat_EXV_SupplierNumber_Bat_EXV_Version_LIN1, &Bat_EXV_SupplierNumber_Bat_EXV_Version_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)Bat_EXV_SupplierNumber_Bat_EXV_Version_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_Bat_EXV_SupplierNumber_Bat_EXV_SupplierNumber = data;
                Rte_Inst_ME11.Task_100ms_Bat_EXV_SupplierNumber_Bat_EXV_SupplierNumber->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_Bat_EXV_SupplierNumber_Bat_EXV_Version_LIN2
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
void Rte_COMCbk_Bat_EXV_SupplierNumber_Bat_EXV_Version_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 Bat_EXV_SupplierNumber_Bat_EXV_Version_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(Bat_EXV_SupplierNumber_Bat_EXV_Version_LIN2, &Bat_EXV_SupplierNumber_Bat_EXV_Version_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)Bat_EXV_SupplierNumber_Bat_EXV_Version_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_Bat_EXV_SupplierNumber_Bat_EXV_SupplierNumber = data;
                Rte_Inst_ME11.Task_100ms_Bat_EXV_SupplierNumber_Bat_EXV_SupplierNumber->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_C3WV_ErrResp_C3WV_Sts_LIN2
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
void Rte_COMCbk_C3WV_ErrResp_C3WV_Sts_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        Boolean data;
        boolean isSuccess = TRUE;
        boolean C3WV_ErrResp_C3WV_Sts_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(C3WV_ErrResp_C3WV_Sts_LIN2, &C3WV_ErrResp_C3WV_Sts_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (Boolean)C3WV_ErrResp_C3WV_Sts_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_C3WV_ErrResp_C3WV_ErrResp = data;
                Rte_Inst_ME11.Task_100ms_C3WV_ErrResp_C3WV_ErrResp->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_C3WV_FltSts_C3WV_Sts_LIN2
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
void Rte_COMCbk_C3WV_FltSts_C3WV_Sts_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 C3WV_FltSts_C3WV_Sts_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(C3WV_FltSts_C3WV_Sts_LIN2, &C3WV_FltSts_C3WV_Sts_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)C3WV_FltSts_C3WV_Sts_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_C3WV_FltSts_C3WV_FltSts = data;
                Rte_Inst_ME11.Task_100ms_C3WV_FltSts_C3WV_FltSts->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_C3WV_Mode_C3WV_Sts_LIN2
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
void Rte_COMCbk_C3WV_Mode_C3WV_Sts_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 C3WV_Mode_C3WV_Sts_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(C3WV_Mode_C3WV_Sts_LIN2, &C3WV_Mode_C3WV_Sts_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)C3WV_Mode_C3WV_Sts_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_C3WV_Mode_C3WV_Mode = data;
                Rte_Inst_ME11.Task_100ms_C3WV_Mode_C3WV_Mode->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_C3WV_PosRec_C3WV_Sts_LIN2
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
void Rte_COMCbk_C3WV_PosRec_C3WV_Sts_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt16 data;
        boolean isSuccess = TRUE;
        uint16 C3WV_PosRec_C3WV_Sts_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(C3WV_PosRec_C3WV_Sts_LIN2, &C3WV_PosRec_C3WV_Sts_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt16)C3WV_PosRec_C3WV_Sts_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_C3WV_PosRec_C3WV_PosRec = data;
                Rte_Inst_ME11.Task_100ms_C3WV_PosRec_C3WV_PosRec->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_C3WV_RunSts_C3WV_Sts_LIN2
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
void Rte_COMCbk_C3WV_RunSts_C3WV_Sts_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        Boolean data;
        boolean isSuccess = TRUE;
        boolean C3WV_RunSts_C3WV_Sts_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(C3WV_RunSts_C3WV_Sts_LIN2, &C3WV_RunSts_C3WV_Sts_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (Boolean)C3WV_RunSts_C3WV_Sts_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_C3WV_RunSts_C3WV_RunSts = data;
                Rte_Inst_ME11.Task_100ms_C3WV_RunSts_C3WV_RunSts->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_C3WV_SpdLvl_C3WV_Sts_LIN2
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
void Rte_COMCbk_C3WV_SpdLvl_C3WV_Sts_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_C3WV_TempSts_C3WV_Sts_LIN2
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
void Rte_COMCbk_C3WV_TempSts_C3WV_Sts_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 C3WV_TempSts_C3WV_Sts_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(C3WV_TempSts_C3WV_Sts_LIN2, &C3WV_TempSts_C3WV_Sts_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)C3WV_TempSts_C3WV_Sts_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_C3WV_TempSts_C3WV_TempSts = data;
                Rte_Inst_ME11.Task_100ms_C3WV_TempSts_C3WV_TempSts->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_C3WV_VoltSts_C3WV_Sts_LIN2
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
void Rte_COMCbk_C3WV_VoltSts_C3WV_Sts_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 C3WV_VoltSts_C3WV_Sts_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(C3WV_VoltSts_C3WV_Sts_LIN2, &C3WV_VoltSts_C3WV_Sts_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)C3WV_VoltSts_C3WV_Sts_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_C3WV_VoltSts_C3WV_VoltSts = data;
                Rte_Inst_ME11.Task_100ms_C3WV_VoltSts_C3WV_VoltSts->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_C5WVFltSts_C5WV_Sts_LIN2
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
void Rte_COMCbk_C5WVFltSts_C5WV_Sts_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 C5WVFltSts_C5WV_Sts_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(C5WVFltSts_C5WV_Sts_LIN2, &C5WVFltSts_C5WV_Sts_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)C5WVFltSts_C5WV_Sts_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_C5WVFltSts_C5WVFltSts = data;
                Rte_Inst_ME11.Task_100ms_C5WVFltSts_C5WVFltSts->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_C5WVMode_C5WV_Sts_LIN2
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
void Rte_COMCbk_C5WVMode_C5WV_Sts_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 C5WVMode_C5WV_Sts_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(C5WVMode_C5WV_Sts_LIN2, &C5WVMode_C5WV_Sts_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)C5WVMode_C5WV_Sts_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_C5WVMode_C5WVMode = data;
                Rte_Inst_ME11.Task_100ms_C5WVMode_C5WVMode->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_C5WVPosRec_C5WV_Sts_LIN2
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
void Rte_COMCbk_C5WVPosRec_C5WV_Sts_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt16 data;
        boolean isSuccess = TRUE;
        uint16 C5WVPosRec_C5WV_Sts_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(C5WVPosRec_C5WV_Sts_LIN2, &C5WVPosRec_C5WV_Sts_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt16)C5WVPosRec_C5WV_Sts_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_C5WVPosRec_C5WVPosRec = data;
                Rte_Inst_ME11.Task_100ms_C5WVPosRec_C5WVPosRec->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_C5WVRunSts_C5WV_Sts_LIN2
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
void Rte_COMCbk_C5WVRunSts_C5WV_Sts_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        Boolean data;
        boolean isSuccess = TRUE;
        boolean C5WVRunSts_C5WV_Sts_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(C5WVRunSts_C5WV_Sts_LIN2, &C5WVRunSts_C5WV_Sts_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (Boolean)C5WVRunSts_C5WV_Sts_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_C5WVRunSts_C5WVRunSts = data;
                Rte_Inst_ME11.Task_100ms_C5WVRunSts_C5WVRunSts->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_C5WVSpdLvl_C5WV_Sts_LIN2
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
void Rte_COMCbk_C5WVSpdLvl_C5WV_Sts_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 C5WVSpdLvl_C5WV_Sts_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(C5WVSpdLvl_C5WV_Sts_LIN2, &C5WVSpdLvl_C5WV_Sts_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)C5WVSpdLvl_C5WV_Sts_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_C5WVSpdLvl_C5WVSpdLvl = data;
                Rte_Inst_ME11.Task_100ms_C5WVSpdLvl_C5WVSpdLvl->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_C5WVTempSts_C5WV_Sts_LIN2
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
void Rte_COMCbk_C5WVTempSts_C5WV_Sts_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 C5WVTempSts_C5WV_Sts_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(C5WVTempSts_C5WV_Sts_LIN2, &C5WVTempSts_C5WV_Sts_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)C5WVTempSts_C5WV_Sts_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_C5WVTempSts_C5WVTempSts = data;
                Rte_Inst_ME11.Task_100ms_C5WVTempSts_C5WVTempSts->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_C5WVVoltSts_C5WV_Sts_LIN2
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
void Rte_COMCbk_C5WVVoltSts_C5WV_Sts_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 C5WVVoltSts_C5WV_Sts_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(C5WVVoltSts_C5WV_Sts_LIN2, &C5WVVoltSts_C5WV_Sts_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)C5WVVoltSts_C5WV_Sts_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_C5WVVoltSts_C5WVVoltSts = data;
                Rte_Inst_ME11.Task_100ms_C5WVVoltSts_C5WVVoltSts->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD
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
void Rte_COMCbk_CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD(void)
{
    if (RteInitState == RTE_INITED)
    {
        CCP_PanelStatus_BOD data;
        boolean isSuccess = TRUE;
        if (E_OK == Com_ReceiveSignalGroup(CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD))
        {
            if (E_NOT_OK == Com_ReceiveSignal(CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD_CCP_Checksum_IPDU_COM_CCP_PanelStatus_BOD, &data.CCP_Checksum))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD_CCP_RollingCounter_IPDU_COM_CCP_PanelStatus_BOD, &data.CCP_RollingCounter))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD_CCP_TempAddKey_IPDU_COM_CCP_PanelStatus_BOD, &data.CCP_TempAddKey))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD_CCP_TempDecreaseKey_IPDU_COM_CCP_PanelStatus_BOD, &data.CCP_TempDecreaseKey))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD_CCP_BlowerLevelAddKey_IPDU_COM_CCP_PanelStatus_BOD, &data.CCP_BlowerLevelAddKey))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD_CCP_BlowerLvlDecreaseKey_IPDU_COM_CCP_PanelStatus_BOD, &data.CCP_BlowerLvlDecreaseKey))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD_CCP_BlowingModeNextKey_IPDU_COM_CCP_PanelStatus_BOD, &data.CCP_BlowingModeNextKey))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD_CCP_BlowingModePreviousKey_IPDU_COM_CCP_PanelStatus_BOD, &data.CCP_BlowingModePreviousKey))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD_CCP_ACSwitchKey_IPDU_COM_CCP_PanelStatus_BOD, &data.CCP_ACSwitchKey))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD_CCP_ACAutoKey_IPDU_COM_CCP_PanelStatus_BOD, &data.CCP_ACAutoKey))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD_CCP_RearViewMirrHeatingKey_IPDU_COM_CCP_PanelStatus_BOD, &data.CCP_RearViewMirrHeatingKey))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD_CCP_AirInletModeKey_IPDU_COM_CCP_PanelStatus_BOD, &data.CCP_AirInletModeKey))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD_CCP_FrontWindDefrostKey_IPDU_COM_CCP_PanelStatus_BOD, &data.CCP_FrontWindDefrostKey))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD_CCP_ModeKey_IPDU_COM_CCP_PanelStatus_BOD, &data.CCP_ModeKey))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD_CCP_HazardKey_IPDU_COM_CCP_PanelStatus_BOD, &data.CCP_HazardKey))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD_CCP_CentralLockKey_IPDU_COM_CCP_PanelStatus_BOD, &data.CCP_CentralLockKey))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD_CCP_TPMSKey_IPDU_COM_CCP_PanelStatus_BOD, &data.CCP_TPMSKey))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD_CCP_ESCOFFKey_IPDU_COM_CCP_PanelStatus_BOD, &data.CCP_ESCOFFKey))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD_CCP_AVASOffKey_IPDU_COM_CCP_PanelStatus_BOD, &data.CCP_AVASOffKey))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD_CCP_HDCKey_IPDU_COM_CCP_PanelStatus_BOD, &data.CCP_HDCKey))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD_CCP_AVHKey_IPDU_COM_CCP_PanelStatus_BOD, &data.CCP_AVHKey))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD_CCP_PwrRecupLevelKey_IPDU_COM_CCP_PanelStatus_BOD, &data.CCP_PwrRecupLevelKey))
            {
                isSuccess = FALSE;
            }
            if (isSuccess == TRUE)
            {
                if (isSuccess == TRUE)
                {
                    rte_memcpy((uint8*)&Rte_Buf_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD,(uint8*)&data,sizeof(CCP_PanelStatus_BOD));
                    Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD->status = RTE_E_OK;
                }
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_COMP_AC_BOD_IPDU_COM_COMP_AC_BOD
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
void Rte_COMCbk_COMP_AC_BOD_IPDU_COM_COMP_AC_BOD(void)
{
    if((IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P10) == 1) || (IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P11) == 1))
    {
    Dem_UdsStatusByteType tmp = 0;
	if (E_OK == Dem_GetEventStatus(DemEventParameter_0xC10F87, &tmp))
	{
		if (DEM_UDS_STATUS_TF == (tmp & DEM_UDS_STATUS_TF))
		{
			Dem_SetEventStatus(DemEventParameter_0xC10F87, DEM_EVENT_STATUS_PASSED);
		}
	}
    }
    if (RteInitState == RTE_INITED)
    {
        COMP_AC_BOD data;
        boolean isSuccess = TRUE;
        if (E_OK == Com_ReceiveSignalGroup(COMP_AC_BOD_IPDU_COM_COMP_AC_BOD))
        {
            if (E_NOT_OK == Com_ReceiveSignal(COMP_AC_BOD_IPDU_COM_COMP_AC_BOD_COMP_Checksum_IPDU_COM_COMP_AC_BOD, &data.COMP_Checksum))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(COMP_AC_BOD_IPDU_COM_COMP_AC_BOD_COMP_RollingCounter_IPDU_COM_COMP_AC_BOD, &data.COMP_RollingCounter))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(COMP_AC_BOD_IPDU_COM_COMP_AC_BOD_COMP_OverDuty_IPDU_COM_COMP_AC_BOD, &data.COMP_OverDuty))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(COMP_AC_BOD_IPDU_COM_COMP_AC_BOD_COMP_Commu_Error_IPDU_COM_COMP_AC_BOD, &data.COMP_Commu_Error))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(COMP_AC_BOD_IPDU_COM_COMP_AC_BOD_COMP_PI_Saturation_IPDU_COM_COMP_AC_BOD, &data.COMP_PI_Saturation))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(COMP_AC_BOD_IPDU_COM_COMP_AC_BOD_COMP_LoseStep_IPDU_COM_COMP_AC_BOD, &data.COMP_LoseStep))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(COMP_AC_BOD_IPDU_COM_COMP_AC_BOD_COMP_SelfCheckError_IPDU_COM_COMP_AC_BOD, &data.COMP_SelfCheckError))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(COMP_AC_BOD_IPDU_COM_COMP_AC_BOD_COMP_IPM_Error_IPDU_COM_COMP_AC_BOD, &data.COMP_IPM_Error))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(COMP_AC_BOD_IPDU_COM_COMP_AC_BOD_COMP_TempError_IPDU_COM_COMP_AC_BOD, &data.COMP_TempError))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(COMP_AC_BOD_IPDU_COM_COMP_AC_BOD_COMP_LvError_IPDU_COM_COMP_AC_BOD, &data.COMP_LvError))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(COMP_AC_BOD_IPDU_COM_COMP_AC_BOD_COMP_HvError_IPDU_COM_COMP_AC_BOD, &data.COMP_HvError))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(COMP_AC_BOD_IPDU_COM_COMP_AC_BOD_COMP_OverCurrent_IPDU_COM_COMP_AC_BOD, &data.COMP_OverCurrent))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(COMP_AC_BOD_IPDU_COM_COMP_AC_BOD_COMP_EcompST_IPDU_COM_COMP_AC_BOD, &data.COMP_EcompST))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(COMP_AC_BOD_IPDU_COM_COMP_AC_BOD_COMP_CurrentOffset_IPDU_COM_COMP_AC_BOD, &data.COMP_CurrentOffset))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(COMP_AC_BOD_IPDU_COM_COMP_AC_BOD_COMP_CANBusOff_IPDU_COM_COMP_AC_BOD, &data.COMP_CANBusOff))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(COMP_AC_BOD_IPDU_COM_COMP_AC_BOD_ECUHighVoltInterlockSignal_IPDU_COM_COMP_AC_BOD, &data.ECUHighVoltInterlockSignal))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(COMP_AC_BOD_IPDU_COM_COMP_AC_BOD_COMP_Temperature_IPDU_COM_COMP_AC_BOD, &data.COMP_Temperature))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(COMP_AC_BOD_IPDU_COM_COMP_AC_BOD_COMP_InputCurrent_IPDU_COM_COMP_AC_BOD, &data.COMP_InputCurrent))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(COMP_AC_BOD_IPDU_COM_COMP_AC_BOD_COMP_High_Voltage_IPDU_COM_COMP_AC_BOD, &data.COMP_High_Voltage))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(COMP_AC_BOD_IPDU_COM_COMP_AC_BOD_COMP_EcompActSpd_IPDU_COM_COMP_AC_BOD, &data.COMP_EcompActSpd))
            {
                isSuccess = FALSE;
            }
            if (isSuccess == TRUE)
            {
                if (isSuccess == TRUE)
                {
                    rte_memcpy((uint8*)&Rte_Buf_Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD,(uint8*)&data,sizeof(COMP_AC_BOD));
                    Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD->status = RTE_E_OK;
                }
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_CRRR_A_CHA_IPDU_COM_CRRR_A_CHA
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
void Rte_COMCbk_CRRR_A_CHA_IPDU_COM_CRRR_A_CHA(void)
{
    if (RteInitState == RTE_INITED)
    {
    }
    if((IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P10) == 1) || (IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P11) == 1))
    {
     Dem_UdsStatusByteType tmp = 0;
	if (E_OK == Dem_GetEventStatus(DemEventParameter_0xD11287, &tmp))
	{
		if (DEM_UDS_STATUS_TF == (tmp & DEM_UDS_STATUS_TF))
		{
			Dem_SetEventStatus(DemEventParameter_0xD11287, DEM_EVENT_STATUS_PASSED);
		}
	}
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_EPS_2_StrWhlAng_CHA_IPDU_COM_EPS_2_StrWhlAng_CHA
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
void Rte_COMCbk_EPS_2_StrWhlAng_CHA_IPDU_COM_EPS_2_StrWhlAng_CHA(void)
{
    if((IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P10) == 1) || (IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P11) == 1))
    {
    Dem_UdsStatusByteType tmp = 0;
	if (E_OK == Dem_GetEventStatus(DemEventParameter_0xC13087, &tmp))
	{
		if (DEM_UDS_STATUS_TF == (tmp & DEM_UDS_STATUS_TF))
		{
			Dem_SetEventStatus(DemEventParameter_0xC13087, DEM_EVENT_STATUS_PASSED);
		}
	}
    }
    if (RteInitState == RTE_INITED)
    {
        EPS_2_StrWhlAng_CHA data;
        boolean isSuccess = TRUE;
        if (E_OK == Com_ReceiveSignalGroup(EPS_2_StrWhlAng_CHA_IPDU_COM_EPS_2_StrWhlAng_CHA))
        {
            if (E_NOT_OK == Com_ReceiveSignal(EPS_2_StrWhlAng_CHA_IPDU_COM_EPS_2_StrWhlAng_CHA_EPS_2_Chksum_IPDU_COM_EPS_2_StrWhlAng_CHA, &data.EPS_2_Chksum))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EPS_2_StrWhlAng_CHA_IPDU_COM_EPS_2_StrWhlAng_CHA_EPS_2_AliveCnt_IPDU_COM_EPS_2_StrWhlAng_CHA, &data.EPS_2_AliveCnt))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EPS_2_StrWhlAng_CHA_IPDU_COM_EPS_2_StrWhlAng_CHA_EPS_SteerWheelAngle_IPDU_COM_EPS_2_StrWhlAng_CHA, &data.EPS_SteerWheelAngle))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EPS_2_StrWhlAng_CHA_IPDU_COM_EPS_2_StrWhlAng_CHA_EPS_SteerWheelAngleValid_IPDU_COM_EPS_2_StrWhlAng_CHA, &data.EPS_SteerWheelAngleValid))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EPS_2_StrWhlAng_CHA_IPDU_COM_EPS_2_StrWhlAng_CHA_EPS_RotSpeed_IPDU_COM_EPS_2_StrWhlAng_CHA, &data.EPS_RotSpeed))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EPS_2_StrWhlAng_CHA_IPDU_COM_EPS_2_StrWhlAng_CHA_EPS_SteerWheelAngleCalibrated_IPDU_COM_EPS_2_StrWhlAng_CHA, &data.EPS_SteerWheelAngleCalibrated))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EPS_2_StrWhlAng_CHA_IPDU_COM_EPS_2_StrWhlAng_CHA_EPS_SteerWheelAngleFailure_IPDU_COM_EPS_2_StrWhlAng_CHA, &data.EPS_SteerWheelAngleFailure))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(EPS_2_StrWhlAng_CHA_IPDU_COM_EPS_2_StrWhlAng_CHA_EPS_ElectricPowerSta_IPDU_COM_EPS_2_StrWhlAng_CHA, &data.EPS_ElectricPowerSta))
            {
                isSuccess = FALSE;
            }
            if (isSuccess == TRUE)
            {
                if (isSuccess == TRUE)
                {
                    rte_memcpy((uint8*)&Rte_Buf_Runbl_IpmCanRx_10ms_EPS_2_StrWhlAng_CHA_EPS_2_StrWhlAng_CHA,(uint8*)&data,sizeof(EPS_2_StrWhlAng_CHA));
                    Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_EPS_2_StrWhlAng_CHA_EPS_2_StrWhlAng_CHA->status = RTE_E_OK;
                }
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_ESCL_ESCLStatus_BOD_IPDU_COM_ESCL_ESCLStatus_BOD
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
void Rte_COMCbk_ESCL_ESCLStatus_BOD_IPDU_COM_ESCL_ESCLStatus_BOD(void)
{
    if (RteInitState == RTE_INITED)
    {
        ESCL_ESCLStatus_BOD data;
        boolean isSuccess = TRUE;
        if (E_OK == Com_ReceiveSignalGroup(ESCL_ESCLStatus_BOD_IPDU_COM_ESCL_ESCLStatus_BOD))
        {
            if (E_NOT_OK == Com_ReceiveSignal(ESCL_ESCLStatus_BOD_IPDU_COM_ESCL_ESCLStatus_BOD_ESCL_UnOrLock_feedback_IPDU_COM_ESCL_ESCLStatus_BOD, &data.ESCL_UnOrLock_feedback))
            {
                isSuccess = FALSE;
            }
            if (isSuccess == TRUE)
            {
                if (isSuccess == TRUE)
                {
                    rte_memcpy((uint8*)&Rte_Buf_Runbl_IpmCanRx_50ms_ESCL_ESCLStatus_BOD_ESCL_ESCLStatus_BOD,(uint8*)&data,sizeof(ESCL_ESCLStatus_BOD));
                    Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_50ms_ESCL_ESCLStatus_BOD_ESCL_ESCLStatus_BOD->status = RTE_E_OK;
                }
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5
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
void Rte_COMCbk_ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5(void)
{
    if((IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P10) == 1) || (IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P11) == 1))
    {
    Dem_UdsStatusByteType tmp = 0;
	if (E_OK == Dem_GetEventStatus(DemEventParameter_0xC12287, &tmp))
	{
		if (DEM_UDS_STATUS_TF == (tmp & DEM_UDS_STATUS_TF))
		{
			Dem_SetEventStatus(DemEventParameter_0xC12287, DEM_EVENT_STATUS_PASSED);
		}
	}
    }
    if (RteInitState == RTE_INITED)
    {
        ESC_7_FuncStatus_CHA data;
        boolean isSuccess = TRUE;
        if (E_OK == Com_ReceiveSignalGroup(ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5))
        {
            if (E_NOT_OK == Com_ReceiveSignal(ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_ESC_7_Chksum_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5, &data.ESC_7_Chksum))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_ESC_7_AliveCnt_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5, &data.ESC_7_AliveCnt))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_ESC_ESCorTCSFailed_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5, &data.ESC_ESCorTCSFailed))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_ESC_ABSActiveSta_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5, &data.ESC_ABSActiveSta))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_ESC_VehicleSpeedV_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5, &data.ESC_VehicleSpeedV))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_ESC_VehicleSpeed_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5, &data.ESC_VehicleSpeed))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_ESC_EBDFailed_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5, &data.ESC_EBDFailed))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_ESC_ABSFailed_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5, &data.ESC_ABSFailed))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_ESC_TCSActiveSta_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5, &data.ESC_TCSActiveSta))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_ESC_ESPActiveSta_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5, &data.ESC_ESPActiveSta))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_ESC_ReqBrakeLightOn_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5, &data.ESC_ReqBrakeLightOn))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_ESC_RMIActiveSta_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5, &data.ESC_RMIActiveSta))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_ESC_HMI_WarningOn_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5, &data.ESC_HMI_WarningOn))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_ESC_CDPAvailable_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5, &data.ESC_CDPAvailable))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_ESC_CDPActive_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5, &data.ESC_CDPActive))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_ESC_ESSAvailable_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5, &data.ESC_ESSAvailable))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_ESC_ESSActive_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5, &data.ESC_ESSActive))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_ESC_EBDActiveSta_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5, &data.ESC_EBDActiveSta))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_ESC_FaultLevel_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5, &data.ESC_FaultLevel))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_ESC_ESCDisable_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5, &data.ESC_ESCDisable))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_ESC_SlopePercentV_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5, &data.ESC_SlopePercentV))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_ESC_PALAResponse_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5, &data.ESC_PALAResponse))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_ESC_SlopePercent_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5, &data.ESC_SlopePercent))
            {
                isSuccess = FALSE;
            }
            if (isSuccess == TRUE)
            {
                if (isSuccess == TRUE)
                {
                    rte_memcpy((uint8*)&Rte_Buf_Runbl_IpmCanRx_10ms_ESC_7_FuncStatus_CHA_ESC_7_FuncStatus_CHA,(uint8*)&data,sizeof(ESC_7_FuncStatus_CHA));
                    Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_ESC_7_FuncStatus_CHA_ESC_7_FuncStatus_CHA->status = RTE_E_OK;
                }
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_EXV_CurrentInitState_AC_EXV_Rsp_LIN1
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
void Rte_COMCbk_EXV_CurrentInitState_AC_EXV_Rsp_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 EXV_CurrentInitState_AC_EXV_Rsp_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(EXV_CurrentInitState_AC_EXV_Rsp_LIN1, &EXV_CurrentInitState_AC_EXV_Rsp_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)EXV_CurrentInitState_AC_EXV_Rsp_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_EXV_CurrentInitState_EXV_CurrentInitState = data;
                Rte_Inst_ME11.Task_100ms_EXV_CurrentInitState_EXV_CurrentInitState->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_EXV_CurrentInitState_AC_EXV_Rsp_LIN2
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
void Rte_COMCbk_EXV_CurrentInitState_AC_EXV_Rsp_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 EXV_CurrentInitState_AC_EXV_Rsp_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(EXV_CurrentInitState_AC_EXV_Rsp_LIN2, &EXV_CurrentInitState_AC_EXV_Rsp_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)EXV_CurrentInitState_AC_EXV_Rsp_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_EXV_CurrentInitState_EXV_CurrentInitState = data;
                Rte_Inst_ME11.Task_100ms_EXV_CurrentInitState_EXV_CurrentInitState->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_EXV_CurrentPosition_AC_EXV_Rsp_LIN1
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
void Rte_COMCbk_EXV_CurrentPosition_AC_EXV_Rsp_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt16 data;
        boolean isSuccess = TRUE;
        uint16 EXV_CurrentPosition_AC_EXV_Rsp_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(EXV_CurrentPosition_AC_EXV_Rsp_LIN1, &EXV_CurrentPosition_AC_EXV_Rsp_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt16)EXV_CurrentPosition_AC_EXV_Rsp_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_EXV_CurrentPosition_EXV_CurrentPosition = data;
                Rte_Inst_ME11.Task_100ms_EXV_CurrentPosition_EXV_CurrentPosition->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_EXV_CurrentPosition_AC_EXV_Rsp_LIN2
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
void Rte_COMCbk_EXV_CurrentPosition_AC_EXV_Rsp_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt16 data;
        boolean isSuccess = TRUE;
        uint16 EXV_CurrentPosition_AC_EXV_Rsp_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(EXV_CurrentPosition_AC_EXV_Rsp_LIN2, &EXV_CurrentPosition_AC_EXV_Rsp_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt16)EXV_CurrentPosition_AC_EXV_Rsp_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_EXV_CurrentPosition_EXV_CurrentPosition = data;
                Rte_Inst_ME11.Task_100ms_EXV_CurrentPosition_EXV_CurrentPosition->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_EXV_FaultState_AC_EXV_Rsp_LIN1
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
void Rte_COMCbk_EXV_FaultState_AC_EXV_Rsp_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 EXV_FaultState_AC_EXV_Rsp_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(EXV_FaultState_AC_EXV_Rsp_LIN1, &EXV_FaultState_AC_EXV_Rsp_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)EXV_FaultState_AC_EXV_Rsp_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_EXV_FaultState_EXV_FaultState = data;
                Rte_Inst_ME11.Task_100ms_EXV_FaultState_EXV_FaultState->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_EXV_FaultState_AC_EXV_Rsp_LIN2
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
void Rte_COMCbk_EXV_FaultState_AC_EXV_Rsp_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 EXV_FaultState_AC_EXV_Rsp_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(EXV_FaultState_AC_EXV_Rsp_LIN2, &EXV_FaultState_AC_EXV_Rsp_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)EXV_FaultState_AC_EXV_Rsp_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_EXV_FaultState_EXV_FaultState = data;
                Rte_Inst_ME11.Task_100ms_EXV_FaultState_EXV_FaultState->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_EXV_ResponseError_AC_EXV_Rsp_LIN1
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
void Rte_COMCbk_EXV_ResponseError_AC_EXV_Rsp_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        Boolean data;
        boolean isSuccess = TRUE;
        boolean EXV_ResponseError_AC_EXV_Rsp_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(EXV_ResponseError_AC_EXV_Rsp_LIN1, &EXV_ResponseError_AC_EXV_Rsp_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (Boolean)EXV_ResponseError_AC_EXV_Rsp_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_EXV_ResponseError_EXV_ResponseError = data;
                Rte_Inst_ME11.Task_100ms_EXV_ResponseError_EXV_ResponseError->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_EXV_ResponseError_AC_EXV_Rsp_LIN2
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
void Rte_COMCbk_EXV_ResponseError_AC_EXV_Rsp_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        Boolean data;
        boolean isSuccess = TRUE;
        boolean EXV_ResponseError_AC_EXV_Rsp_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(EXV_ResponseError_AC_EXV_Rsp_LIN2, &EXV_ResponseError_AC_EXV_Rsp_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (Boolean)EXV_ResponseError_AC_EXV_Rsp_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_EXV_ResponseError_EXV_ResponseError = data;
                Rte_Inst_ME11.Task_100ms_EXV_ResponseError_EXV_ResponseError->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_EXV_RunState_AC_EXV_Rsp_LIN1
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
void Rte_COMCbk_EXV_RunState_AC_EXV_Rsp_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        Boolean data;
        boolean isSuccess = TRUE;
        boolean EXV_RunState_AC_EXV_Rsp_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(EXV_RunState_AC_EXV_Rsp_LIN1, &EXV_RunState_AC_EXV_Rsp_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (Boolean)EXV_RunState_AC_EXV_Rsp_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_EXV_RunState_EXV_RunState = data;
                Rte_Inst_ME11.Task_100ms_EXV_RunState_EXV_RunState->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_EXV_RunState_AC_EXV_Rsp_LIN2
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
void Rte_COMCbk_EXV_RunState_AC_EXV_Rsp_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        Boolean data;
        boolean isSuccess = TRUE;
        boolean EXV_RunState_AC_EXV_Rsp_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(EXV_RunState_AC_EXV_Rsp_LIN2, &EXV_RunState_AC_EXV_Rsp_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (Boolean)EXV_RunState_AC_EXV_Rsp_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_EXV_RunState_EXV_RunState = data;
                Rte_Inst_ME11.Task_100ms_EXV_RunState_EXV_RunState->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_EXV_TemperatureWarn_AC_EXV_Rsp_LIN1
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
void Rte_COMCbk_EXV_TemperatureWarn_AC_EXV_Rsp_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 EXV_TemperatureWarn_AC_EXV_Rsp_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(EXV_TemperatureWarn_AC_EXV_Rsp_LIN1, &EXV_TemperatureWarn_AC_EXV_Rsp_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)EXV_TemperatureWarn_AC_EXV_Rsp_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_EXV_TemperatureWarn_EXV_TemperatureWarn = data;
                Rte_Inst_ME11.Task_100ms_EXV_TemperatureWarn_EXV_TemperatureWarn->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_EXV_TemperatureWarn_AC_EXV_Rsp_LIN2
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
void Rte_COMCbk_EXV_TemperatureWarn_AC_EXV_Rsp_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 EXV_TemperatureWarn_AC_EXV_Rsp_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(EXV_TemperatureWarn_AC_EXV_Rsp_LIN2, &EXV_TemperatureWarn_AC_EXV_Rsp_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)EXV_TemperatureWarn_AC_EXV_Rsp_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_EXV_TemperatureWarn_EXV_TemperatureWarn = data;
                Rte_Inst_ME11.Task_100ms_EXV_TemperatureWarn_EXV_TemperatureWarn->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_EXV_VoltageState_AC_EXV_Rsp_LIN1
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
void Rte_COMCbk_EXV_VoltageState_AC_EXV_Rsp_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 EXV_VoltageState_AC_EXV_Rsp_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(EXV_VoltageState_AC_EXV_Rsp_LIN1, &EXV_VoltageState_AC_EXV_Rsp_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)EXV_VoltageState_AC_EXV_Rsp_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_EXV_VoltageState_EXV_VoltageState = data;
                Rte_Inst_ME11.Task_100ms_EXV_VoltageState_EXV_VoltageState->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_EXV_VoltageState_AC_EXV_Rsp_LIN2
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
void Rte_COMCbk_EXV_VoltageState_AC_EXV_Rsp_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 EXV_VoltageState_AC_EXV_Rsp_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(EXV_VoltageState_AC_EXV_Rsp_LIN2, &EXV_VoltageState_AC_EXV_Rsp_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)EXV_VoltageState_AC_EXV_Rsp_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_EXV_VoltageState_EXV_VoltageState = data;
                Rte_Inst_ME11.Task_100ms_EXV_VoltageState_EXV_VoltageState->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_ErrRespC5WV_C5WV_Sts_LIN2
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
void Rte_COMCbk_ErrRespC5WV_C5WV_Sts_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        Boolean data;
        boolean isSuccess = TRUE;
        boolean ErrRespC5WV_C5WV_Sts_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(ErrRespC5WV_C5WV_Sts_LIN2, &ErrRespC5WV_C5WV_Sts_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (Boolean)ErrRespC5WV_C5WV_Sts_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_ErrRespC5WV_ErrRespC5WV = data;
                Rte_Inst_ME11.Task_100ms_ErrRespC5WV_ErrRespC5WV->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_FCLL_TiWngSt_FCLL_Status_LIN3
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
void Rte_COMCbk_FCLL_TiWngSt_FCLL_Status_LIN3(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        boolean FCLL_TiWngSt_FCLL_Status_LIN3_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(FCLL_TiWngSt_FCLL_Status_LIN3, &FCLL_TiWngSt_FCLL_Status_LIN3_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)FCLL_TiWngSt_FCLL_Status_LIN3_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Runbl_AppSwcBcm_20ms_FCLL_TiWngSt_FCLL_TiWngSt = data;
                Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_FCLL_TiWngSt_FCLL_TiWngSt->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_FCLR_TiWngSt_FCLR_Status_LIN3
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
void Rte_COMCbk_FCLR_TiWngSt_FCLR_Status_LIN3(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        boolean FCLR_TiWngSt_FCLR_Status_LIN3_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(FCLR_TiWngSt_FCLR_Status_LIN3, &FCLR_TiWngSt_FCLR_Status_LIN3_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)FCLR_TiWngSt_FCLR_Status_LIN3_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Runbl_AppSwcBcm_20ms_FCLR_TiWngSt_FCLR_TiWngSt = data;
                Rte_Inst_AppSwcBcm.Runbl_AppSwcBcm_20ms_FCLR_TiWngSt_FCLR_TiWngSt->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_FCM_D_CHA_IPDU_COM_RX_FCM_D_CHA_CANFD3_CHA_CAN5
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
void Rte_COMCbk_FCM_D_CHA_IPDU_COM_RX_FCM_D_CHA_CANFD3_CHA_CAN5(void)
{
    if (RteInitState == RTE_INITED)
    {
    }
    if((IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P10) == 1) || (IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P11) == 1))
    {
    Dem_UdsStatusByteType tmp = 0;
	if (E_OK == Dem_GetEventStatus(DemEventParameter_0xD10287, &tmp))
	{
		if (DEM_UDS_STATUS_TF == (tmp & DEM_UDS_STATUS_TF))
		{
			Dem_SetEventStatus(DemEventParameter_0xD10287, DEM_EVENT_STATUS_PASSED);
		}
	}
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_HP_EXV_CurrentPosition_B_HP_EXV_Rsp_LIN2
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
void Rte_COMCbk_HP_EXV_CurrentPosition_B_HP_EXV_Rsp_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt16 data;
        boolean isSuccess = TRUE;
        uint16 HP_EXV_CurrentPosition_B_HP_EXV_Rsp_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(HP_EXV_CurrentPosition_B_HP_EXV_Rsp_LIN2, &HP_EXV_CurrentPosition_B_HP_EXV_Rsp_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt16)HP_EXV_CurrentPosition_B_HP_EXV_Rsp_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_HP_EXV_CurrentPosition_B_HP_EXV_CurrentPosition_B = data;
                Rte_Inst_ME11.Task_100ms_HP_EXV_CurrentPosition_B_HP_EXV_CurrentPosition_B->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_HP_EXV_CurrentPosition_B_HP_EXV__Rsp_LIN1
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
void Rte_COMCbk_HP_EXV_CurrentPosition_B_HP_EXV__Rsp_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt16 data;
        boolean isSuccess = TRUE;
        uint16 HP_EXV_CurrentPosition_B_HP_EXV__Rsp_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(HP_EXV_CurrentPosition_B_HP_EXV__Rsp_LIN1, &HP_EXV_CurrentPosition_B_HP_EXV__Rsp_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt16)HP_EXV_CurrentPosition_B_HP_EXV__Rsp_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_HP_EXV_CurrentPosition_B_HP_EXV_CurrentPosition_B = data;
                Rte_Inst_ME11.Task_100ms_HP_EXV_CurrentPosition_B_HP_EXV_CurrentPosition_B->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_HP_EXV_FaultState_B_HP_EXV_Rsp_LIN2
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
void Rte_COMCbk_HP_EXV_FaultState_B_HP_EXV_Rsp_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 HP_EXV_FaultState_B_HP_EXV_Rsp_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(HP_EXV_FaultState_B_HP_EXV_Rsp_LIN2, &HP_EXV_FaultState_B_HP_EXV_Rsp_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)HP_EXV_FaultState_B_HP_EXV_Rsp_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_HP_EXV_FaultState_B_HP_EXV_FaultState_B = data;
                Rte_Inst_ME11.Task_100ms_HP_EXV_FaultState_B_HP_EXV_FaultState_B->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_HP_EXV_FaultState_B_HP_EXV__Rsp_LIN1
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
void Rte_COMCbk_HP_EXV_FaultState_B_HP_EXV__Rsp_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 HP_EXV_FaultState_B_HP_EXV__Rsp_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(HP_EXV_FaultState_B_HP_EXV__Rsp_LIN1, &HP_EXV_FaultState_B_HP_EXV__Rsp_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)HP_EXV_FaultState_B_HP_EXV__Rsp_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_HP_EXV_FaultState_B_HP_EXV_FaultState_B = data;
                Rte_Inst_ME11.Task_100ms_HP_EXV_FaultState_B_HP_EXV_FaultState_B->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_HP_EXV_HWVersion_HP_EXV_Version_LIN1
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
void Rte_COMCbk_HP_EXV_HWVersion_HP_EXV_Version_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 HP_EXV_HWVersion_HP_EXV_Version_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(HP_EXV_HWVersion_HP_EXV_Version_LIN1, &HP_EXV_HWVersion_HP_EXV_Version_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)HP_EXV_HWVersion_HP_EXV_Version_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_HP_EXV_HWVersion_HP_EXV_HWVersion = data;
                Rte_Inst_ME11.Task_100ms_HP_EXV_HWVersion_HP_EXV_HWVersion->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_HP_EXV_HWVersion_HP_EXV_Version_LIN2
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
void Rte_COMCbk_HP_EXV_HWVersion_HP_EXV_Version_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 HP_EXV_HWVersion_HP_EXV_Version_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(HP_EXV_HWVersion_HP_EXV_Version_LIN2, &HP_EXV_HWVersion_HP_EXV_Version_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)HP_EXV_HWVersion_HP_EXV_Version_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_HP_EXV_HWVersion_HP_EXV_HWVersion = data;
                Rte_Inst_ME11.Task_100ms_HP_EXV_HWVersion_HP_EXV_HWVersion->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_HP_EXV_PartNumber_HP_EXV_Version_LIN1
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
void Rte_COMCbk_HP_EXV_PartNumber_HP_EXV_Version_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 HP_EXV_PartNumber_HP_EXV_Version_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(HP_EXV_PartNumber_HP_EXV_Version_LIN1, &HP_EXV_PartNumber_HP_EXV_Version_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)HP_EXV_PartNumber_HP_EXV_Version_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_HP_EXV_PartNumber_HP_EXV_PartNumber = data;
                Rte_Inst_ME11.Task_100ms_HP_EXV_PartNumber_HP_EXV_PartNumber->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_HP_EXV_PartNumber_HP_EXV_Version_LIN2
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
void Rte_COMCbk_HP_EXV_PartNumber_HP_EXV_Version_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 HP_EXV_PartNumber_HP_EXV_Version_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(HP_EXV_PartNumber_HP_EXV_Version_LIN2, &HP_EXV_PartNumber_HP_EXV_Version_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)HP_EXV_PartNumber_HP_EXV_Version_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_HP_EXV_PartNumber_HP_EXV_PartNumber = data;
                Rte_Inst_ME11.Task_100ms_HP_EXV_PartNumber_HP_EXV_PartNumber->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_HP_EXV_ProjectCode1_HP_EXV_Version_LIN1
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
void Rte_COMCbk_HP_EXV_ProjectCode1_HP_EXV_Version_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 HP_EXV_ProjectCode1_HP_EXV_Version_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(HP_EXV_ProjectCode1_HP_EXV_Version_LIN1, &HP_EXV_ProjectCode1_HP_EXV_Version_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)HP_EXV_ProjectCode1_HP_EXV_Version_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_HP_EXV_ProjectCode1_HP_EXV_ProjectCode1 = data;
                Rte_Inst_ME11.Task_100ms_HP_EXV_ProjectCode1_HP_EXV_ProjectCode1->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_HP_EXV_ProjectCode1_HP_EXV_Version_LIN2
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
void Rte_COMCbk_HP_EXV_ProjectCode1_HP_EXV_Version_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 HP_EXV_ProjectCode1_HP_EXV_Version_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(HP_EXV_ProjectCode1_HP_EXV_Version_LIN2, &HP_EXV_ProjectCode1_HP_EXV_Version_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)HP_EXV_ProjectCode1_HP_EXV_Version_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_HP_EXV_ProjectCode1_HP_EXV_ProjectCode1 = data;
                Rte_Inst_ME11.Task_100ms_HP_EXV_ProjectCode1_HP_EXV_ProjectCode1->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_HP_EXV_ProjectCode2_HP_EXV_Version_LIN1
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
void Rte_COMCbk_HP_EXV_ProjectCode2_HP_EXV_Version_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 HP_EXV_ProjectCode2_HP_EXV_Version_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(HP_EXV_ProjectCode2_HP_EXV_Version_LIN1, &HP_EXV_ProjectCode2_HP_EXV_Version_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)HP_EXV_ProjectCode2_HP_EXV_Version_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_HP_EXV_ProjectCode2_HP_EXV_ProjectCode2 = data;
                Rte_Inst_ME11.Task_100ms_HP_EXV_ProjectCode2_HP_EXV_ProjectCode2->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_HP_EXV_ProjectCode2_HP_EXV_Version_LIN2
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
void Rte_COMCbk_HP_EXV_ProjectCode2_HP_EXV_Version_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 HP_EXV_ProjectCode2_HP_EXV_Version_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(HP_EXV_ProjectCode2_HP_EXV_Version_LIN2, &HP_EXV_ProjectCode2_HP_EXV_Version_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)HP_EXV_ProjectCode2_HP_EXV_Version_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_HP_EXV_ProjectCode2_HP_EXV_ProjectCode2 = data;
                Rte_Inst_ME11.Task_100ms_HP_EXV_ProjectCode2_HP_EXV_ProjectCode2->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_HP_EXV_ResponseError_B_HP_EXV_Rsp_LIN2
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
void Rte_COMCbk_HP_EXV_ResponseError_B_HP_EXV_Rsp_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        Boolean data;
        boolean isSuccess = TRUE;
        boolean HP_EXV_ResponseError_B_HP_EXV_Rsp_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(HP_EXV_ResponseError_B_HP_EXV_Rsp_LIN2, &HP_EXV_ResponseError_B_HP_EXV_Rsp_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (Boolean)HP_EXV_ResponseError_B_HP_EXV_Rsp_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_HP_EXV_ResponseError_B_HP_EXV_ResponseError_B = data;
                Rte_Inst_ME11.Task_100ms_HP_EXV_ResponseError_B_HP_EXV_ResponseError_B->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_HP_EXV_ResponseError_B_HP_EXV__Rsp_LIN1
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
void Rte_COMCbk_HP_EXV_ResponseError_B_HP_EXV__Rsp_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        Boolean data;
        boolean isSuccess = TRUE;
        boolean HP_EXV_ResponseError_B_HP_EXV__Rsp_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(HP_EXV_ResponseError_B_HP_EXV__Rsp_LIN1, &HP_EXV_ResponseError_B_HP_EXV__Rsp_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (Boolean)HP_EXV_ResponseError_B_HP_EXV__Rsp_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_HP_EXV_ResponseError_B_HP_EXV_ResponseError_B = data;
                Rte_Inst_ME11.Task_100ms_HP_EXV_ResponseError_B_HP_EXV_ResponseError_B->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_HP_EXV_RunState_B_HP_EXV_Rsp_LIN2
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
void Rte_COMCbk_HP_EXV_RunState_B_HP_EXV_Rsp_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        Boolean data;
        boolean isSuccess = TRUE;
        boolean HP_EXV_RunState_B_HP_EXV_Rsp_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(HP_EXV_RunState_B_HP_EXV_Rsp_LIN2, &HP_EXV_RunState_B_HP_EXV_Rsp_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (Boolean)HP_EXV_RunState_B_HP_EXV_Rsp_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_HP_EXV_RunState_B_HP_EXV_RunState_B = data;
                Rte_Inst_ME11.Task_100ms_HP_EXV_RunState_B_HP_EXV_RunState_B->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_HP_EXV_RunState_B_HP_EXV__Rsp_LIN1
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
void Rte_COMCbk_HP_EXV_RunState_B_HP_EXV__Rsp_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        Boolean data;
        boolean isSuccess = TRUE;
        boolean HP_EXV_RunState_B_HP_EXV__Rsp_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(HP_EXV_RunState_B_HP_EXV__Rsp_LIN1, &HP_EXV_RunState_B_HP_EXV__Rsp_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (Boolean)HP_EXV_RunState_B_HP_EXV__Rsp_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_HP_EXV_RunState_B_HP_EXV_RunState_B = data;
                Rte_Inst_ME11.Task_100ms_HP_EXV_RunState_B_HP_EXV_RunState_B->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_HP_EXV_SWVersion_Main_HP_EXV_Version_LIN1
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
void Rte_COMCbk_HP_EXV_SWVersion_Main_HP_EXV_Version_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 HP_EXV_SWVersion_Main_HP_EXV_Version_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(HP_EXV_SWVersion_Main_HP_EXV_Version_LIN1, &HP_EXV_SWVersion_Main_HP_EXV_Version_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)HP_EXV_SWVersion_Main_HP_EXV_Version_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_HP_EXV_SWVersion_Main_HP_EXV_SWVersion_Main = data;
                Rte_Inst_ME11.Task_100ms_HP_EXV_SWVersion_Main_HP_EXV_SWVersion_Main->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_HP_EXV_SWVersion_Main_HP_EXV_Version_LIN2
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
void Rte_COMCbk_HP_EXV_SWVersion_Main_HP_EXV_Version_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 HP_EXV_SWVersion_Main_HP_EXV_Version_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(HP_EXV_SWVersion_Main_HP_EXV_Version_LIN2, &HP_EXV_SWVersion_Main_HP_EXV_Version_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)HP_EXV_SWVersion_Main_HP_EXV_Version_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_HP_EXV_SWVersion_Main_HP_EXV_SWVersion_Main = data;
                Rte_Inst_ME11.Task_100ms_HP_EXV_SWVersion_Main_HP_EXV_SWVersion_Main->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_HP_EXV_SWVersion_Patch_HP_EXV_Version_LIN1
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
void Rte_COMCbk_HP_EXV_SWVersion_Patch_HP_EXV_Version_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 HP_EXV_SWVersion_Patch_HP_EXV_Version_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(HP_EXV_SWVersion_Patch_HP_EXV_Version_LIN1, &HP_EXV_SWVersion_Patch_HP_EXV_Version_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)HP_EXV_SWVersion_Patch_HP_EXV_Version_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_HP_EXV_SWVersion_Patch_HP_EXV_SWVersion_Patch = data;
                Rte_Inst_ME11.Task_100ms_HP_EXV_SWVersion_Patch_HP_EXV_SWVersion_Patch->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_HP_EXV_SWVersion_Patch_HP_EXV_Version_LIN2
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
void Rte_COMCbk_HP_EXV_SWVersion_Patch_HP_EXV_Version_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 HP_EXV_SWVersion_Patch_HP_EXV_Version_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(HP_EXV_SWVersion_Patch_HP_EXV_Version_LIN2, &HP_EXV_SWVersion_Patch_HP_EXV_Version_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)HP_EXV_SWVersion_Patch_HP_EXV_Version_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_HP_EXV_SWVersion_Patch_HP_EXV_SWVersion_Patch = data;
                Rte_Inst_ME11.Task_100ms_HP_EXV_SWVersion_Patch_HP_EXV_SWVersion_Patch->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_HP_EXV_SWVersion_Sub_HP_EXV_Version_LIN1
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
void Rte_COMCbk_HP_EXV_SWVersion_Sub_HP_EXV_Version_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 HP_EXV_SWVersion_Sub_HP_EXV_Version_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(HP_EXV_SWVersion_Sub_HP_EXV_Version_LIN1, &HP_EXV_SWVersion_Sub_HP_EXV_Version_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)HP_EXV_SWVersion_Sub_HP_EXV_Version_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_HP_EXV_SWVersion_Sub_HP_EXV_SWVersion_Sub = data;
                Rte_Inst_ME11.Task_100ms_HP_EXV_SWVersion_Sub_HP_EXV_SWVersion_Sub->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_HP_EXV_SWVersion_Sub_HP_EXV_Version_LIN2
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
void Rte_COMCbk_HP_EXV_SWVersion_Sub_HP_EXV_Version_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 HP_EXV_SWVersion_Sub_HP_EXV_Version_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(HP_EXV_SWVersion_Sub_HP_EXV_Version_LIN2, &HP_EXV_SWVersion_Sub_HP_EXV_Version_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)HP_EXV_SWVersion_Sub_HP_EXV_Version_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_HP_EXV_SWVersion_Sub_HP_EXV_SWVersion_Sub = data;
                Rte_Inst_ME11.Task_100ms_HP_EXV_SWVersion_Sub_HP_EXV_SWVersion_Sub->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_HP_EXV_SupplierLabel_HP_EXV_Rsp_LIN2
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
void Rte_COMCbk_HP_EXV_SupplierLabel_HP_EXV_Rsp_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        Boolean data;
        boolean isSuccess = TRUE;
        boolean HP_EXV_SupplierLabel_HP_EXV_Rsp_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(HP_EXV_SupplierLabel_HP_EXV_Rsp_LIN2, &HP_EXV_SupplierLabel_HP_EXV_Rsp_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (Boolean)HP_EXV_SupplierLabel_HP_EXV_Rsp_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_HP_EXV_SupplierLabel_HP_EXV_SupplierLabel = data;
                Rte_Inst_ME11.Task_100ms_HP_EXV_SupplierLabel_HP_EXV_SupplierLabel->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_HP_EXV_SupplierLabel_HP_EXV__Rsp_LIN1
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
void Rte_COMCbk_HP_EXV_SupplierLabel_HP_EXV__Rsp_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        Boolean data;
        boolean isSuccess = TRUE;
        boolean HP_EXV_SupplierLabel_HP_EXV__Rsp_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(HP_EXV_SupplierLabel_HP_EXV__Rsp_LIN1, &HP_EXV_SupplierLabel_HP_EXV__Rsp_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (Boolean)HP_EXV_SupplierLabel_HP_EXV__Rsp_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_HP_EXV_SupplierLabel_HP_EXV_SupplierLabel = data;
                Rte_Inst_ME11.Task_100ms_HP_EXV_SupplierLabel_HP_EXV_SupplierLabel->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_HP_EXV_SupplierNumber_HP_EXV_Version_LIN1
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
void Rte_COMCbk_HP_EXV_SupplierNumber_HP_EXV_Version_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 HP_EXV_SupplierNumber_HP_EXV_Version_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(HP_EXV_SupplierNumber_HP_EXV_Version_LIN1, &HP_EXV_SupplierNumber_HP_EXV_Version_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)HP_EXV_SupplierNumber_HP_EXV_Version_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_HP_EXV_SupplierNumber_HP_EXV_SupplierNumber = data;
                Rte_Inst_ME11.Task_100ms_HP_EXV_SupplierNumber_HP_EXV_SupplierNumber->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_HP_EXV_SupplierNumber_HP_EXV_Version_LIN2
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
void Rte_COMCbk_HP_EXV_SupplierNumber_HP_EXV_Version_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 HP_EXV_SupplierNumber_HP_EXV_Version_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(HP_EXV_SupplierNumber_HP_EXV_Version_LIN2, &HP_EXV_SupplierNumber_HP_EXV_Version_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)HP_EXV_SupplierNumber_HP_EXV_Version_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_HP_EXV_SupplierNumber_HP_EXV_SupplierNumber = data;
                Rte_Inst_ME11.Task_100ms_HP_EXV_SupplierNumber_HP_EXV_SupplierNumber->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_HP_EXV_VoltageState_B_HP_EXV_Rsp_LIN2
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
void Rte_COMCbk_HP_EXV_VoltageState_B_HP_EXV_Rsp_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 HP_EXV_VoltageState_B_HP_EXV_Rsp_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(HP_EXV_VoltageState_B_HP_EXV_Rsp_LIN2, &HP_EXV_VoltageState_B_HP_EXV_Rsp_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)HP_EXV_VoltageState_B_HP_EXV_Rsp_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_HP_EXV_VoltageState_B_HP_EXV_VoltageState_B = data;
                Rte_Inst_ME11.Task_100ms_HP_EXV_VoltageState_B_HP_EXV_VoltageState_B->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_HP_EXV_VoltageState_B_HP_EXV__Rsp_LIN1
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
void Rte_COMCbk_HP_EXV_VoltageState_B_HP_EXV__Rsp_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 HP_EXV_VoltageState_B_HP_EXV__Rsp_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(HP_EXV_VoltageState_B_HP_EXV__Rsp_LIN1, &HP_EXV_VoltageState_B_HP_EXV__Rsp_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)HP_EXV_VoltageState_B_HP_EXV__Rsp_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_HP_EXV_VoltageState_B_HP_EXV_VoltageState_B = data;
                Rte_Inst_ME11.Task_100ms_HP_EXV_VoltageState_B_HP_EXV_VoltageState_B->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_HP_EXV_Warning_OverTemp_HP_EXV_Rsp_LIN2
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
void Rte_COMCbk_HP_EXV_Warning_OverTemp_HP_EXV_Rsp_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        Boolean data;
        boolean isSuccess = TRUE;
        boolean HP_EXV_Warning_OverTemp_HP_EXV_Rsp_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(HP_EXV_Warning_OverTemp_HP_EXV_Rsp_LIN2, &HP_EXV_Warning_OverTemp_HP_EXV_Rsp_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (Boolean)HP_EXV_Warning_OverTemp_HP_EXV_Rsp_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_HP_EXV_Warning_OverTemp_HP_EXV_Warning_OverTemp = data;
                Rte_Inst_ME11.Task_100ms_HP_EXV_Warning_OverTemp_HP_EXV_Warning_OverTemp->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_HP_EXV_Warning_OverTemp_HP_EXV__Rsp_LIN1
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
void Rte_COMCbk_HP_EXV_Warning_OverTemp_HP_EXV__Rsp_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        Boolean data;
        boolean isSuccess = TRUE;
        boolean HP_EXV_Warning_OverTemp_HP_EXV__Rsp_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(HP_EXV_Warning_OverTemp_HP_EXV__Rsp_LIN1, &HP_EXV_Warning_OverTemp_HP_EXV__Rsp_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (Boolean)HP_EXV_Warning_OverTemp_HP_EXV__Rsp_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_HP_EXV_Warning_OverTemp_HP_EXV_Warning_OverTemp = data;
                Rte_Inst_ME11.Task_100ms_HP_EXV_Warning_OverTemp_HP_EXV_Warning_OverTemp->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_HP_EXV_initialize_status_HP_EXV_Rsp_LIN2
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
void Rte_COMCbk_HP_EXV_initialize_status_HP_EXV_Rsp_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 HP_EXV_initialize_status_HP_EXV_Rsp_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(HP_EXV_initialize_status_HP_EXV_Rsp_LIN2, &HP_EXV_initialize_status_HP_EXV_Rsp_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)HP_EXV_initialize_status_HP_EXV_Rsp_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_HP_EXV_initialize_status_HP_EXV_initialize_status = data;
                Rte_Inst_ME11.Task_100ms_HP_EXV_initialize_status_HP_EXV_initialize_status->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_HP_EXV_initialize_status_HP_EXV__Rsp_LIN1
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
void Rte_COMCbk_HP_EXV_initialize_status_HP_EXV__Rsp_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 HP_EXV_initialize_status_HP_EXV__Rsp_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(HP_EXV_initialize_status_HP_EXV__Rsp_LIN1, &HP_EXV_initialize_status_HP_EXV__Rsp_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)HP_EXV_initialize_status_HP_EXV__Rsp_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_HP_EXV_initialize_status_HP_EXV_initialize_status = data;
                Rte_Inst_ME11.Task_100ms_HP_EXV_initialize_status_HP_EXV_initialize_status->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1
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
void Rte_COMCbk_HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1(void)
{
    if((IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P10) == 1) || (IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P11) == 1))
    {
    Dem_UdsStatusByteType tmp = 0;
	if (E_OK == Dem_GetEventStatus(DemEventParameter_0xD11D87, &tmp))
	{
		if (DEM_UDS_STATUS_TF == (tmp & DEM_UDS_STATUS_TF))
		{
			Dem_SetEventStatus(DemEventParameter_0xD11D87, DEM_EVENT_STATUS_PASSED);
		}
	}
    }
    if (RteInitState == RTE_INITED)
    {
        HU_B_BAC data;
        boolean isSuccess = TRUE;
        if (E_OK == Com_ReceiveSignalGroup(HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1))
        {
            if (E_NOT_OK == Com_ReceiveSignal(HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_B_Chksum1_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1, &data.HU_B_Chksum1))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_B_AliveCnt1_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1, &data.HU_B_AliveCnt1))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_HybridEcoModeSet_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1, &data.HU_HybridEcoModeSet))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_LeftTempSet_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1, &data.HU_LeftTempSet))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_ACPowerCtl_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1, &data.HU_ACPowerCtl))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_AirInletModeSet_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1, &data.HU_AirInletModeSet))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_FrontFanSpdSet_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1, &data.HU_FrontFanSpdSet))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_ManualDefrostCtl_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1, &data.HU_ManualDefrostCtl))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_BlowerModeSet_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1, &data.HU_BlowerModeSet))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_FlwrMeHmCtrl_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1, &data.HU_FlwrMeHmCtrl))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_IllmndEntrySts_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1, &data.HU_IllmndEntrySts))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_LockHornOnSt_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1, &data.HU_LockHornOnSt))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_ACAutoCtl_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1, &data.HU_ACAutoCtl))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_DrivingModeSelect_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1, &data.HU_DrivingModeSelect))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_B_Chksum2_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1, &data.HU_B_Chksum2))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_B_AliveCnt2_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1, &data.HU_B_AliveCnt2))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_ParkAutoUnlckSet_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1, &data.HU_ParkAutoUnlckSet))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_OverspdCntrlLockSet_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1, &data.HU_OverspdCntrlLockSet))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_TrunkLockSwCtrl_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1, &data.HU_TrunkLockSwCtrl))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_ChgWiperMtMdSwSet_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1, &data.HU_ChgWiperMtMdSwSet))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_TPMSResetReq_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1, &data.HU_TPMSResetReq))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_MaiDrvrSeatHeat_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1, &data.HU_MaiDrvrSeatHeat))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_PwrOFFReq_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1, &data.HU_PwrOFFReq))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_WiprIntlTimeSet_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1, &data.HU_WiprIntlTimeSet))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_CDC_BackLadjval_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1, &data.CDC_BackLadjval))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_RearMirrorHeat_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1, &data.HU_RearMirrorHeat))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_SteerWhlHeat_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1, &data.HU_SteerWhlHeat))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_IllmndUnlockSts_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1, &data.HU_IllmndUnlockSts))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_IllmndLockSts_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1, &data.HU_IllmndLockSts))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_CoastRecupModeSelect_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1, &data.HU_CoastRecupModeSelect))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_PeristalsisModeEnb_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1, &data.HU_PeristalsisModeEnb))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_RecuperatePowerSet_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1, &data.HU_RecuperatePowerSet))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_DrivingPowerSet_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1, &data.HU_DrivingPowerSet))
            {
                isSuccess = FALSE;
            }
            if (isSuccess == TRUE)
            {
                if (isSuccess == TRUE)
                {
                    rte_memcpy((uint8*)&Rte_Buf_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC,(uint8*)&data,sizeof(HU_B_BAC));
                    Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC->status = RTE_E_OK;
                }
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_HVCH_Status1_BOD_IPDU_COM_HVCH_Status1_BOD
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
void Rte_COMCbk_HVCH_Status1_BOD_IPDU_COM_HVCH_Status1_BOD(void)
{
    if((IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P10) == 1) || (IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P11) == 1))
    {
    Dem_UdsStatusByteType tmp = 0;
	if (E_OK == Dem_GetEventStatus(DemEventParameter_0xC23087, &tmp))
	{
		if (DEM_UDS_STATUS_TF == (tmp & DEM_UDS_STATUS_TF))
		{
			Dem_SetEventStatus(DemEventParameter_0xC23087, DEM_EVENT_STATUS_PASSED);
		}
	}
    }
    if (RteInitState == RTE_INITED)
    {
        HVCH_Status1_BOD data;
        boolean isSuccess = TRUE;
        if (E_OK == Com_ReceiveSignalGroup(HVCH_Status1_BOD_IPDU_COM_HVCH_Status1_BOD))
        {
            if (E_NOT_OK == Com_ReceiveSignal(HVCH_Status1_BOD_IPDU_COM_HVCH_Status1_BOD_HVCHSts1_Checksum_IPDU_COM_HVCH_Status1_BOD, &data.HVCHSts1_Checksum))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(HVCH_Status1_BOD_IPDU_COM_HVCH_Status1_BOD_HVCHSts1_RollingCounter_IPDU_COM_HVCH_Status1_BOD, &data.HVCHSts1_RollingCounter))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(HVCH_Status1_BOD_IPDU_COM_HVCH_Status1_BOD_HVCH_InletTemp_IPDU_COM_HVCH_Status1_BOD, &data.HVCH_InletTemp))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(HVCH_Status1_BOD_IPDU_COM_HVCH_Status1_BOD_HVCH_OutletTemp_IPDU_COM_HVCH_Status1_BOD, &data.HVCH_OutletTemp))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(HVCH_Status1_BOD_IPDU_COM_HVCH_Status1_BOD_HVCH_PCBTemp_IPDU_COM_HVCH_Status1_BOD, &data.HVCH_PCBTemp))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(HVCH_Status1_BOD_IPDU_COM_HVCH_Status1_BOD_HVCH_State_IPDU_COM_HVCH_Status1_BOD, &data.HVCH_State))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(HVCH_Status1_BOD_IPDU_COM_HVCH_Status1_BOD_HVCH_HVState_IPDU_COM_HVCH_Status1_BOD, &data.HVCH_HVState))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(HVCH_Status1_BOD_IPDU_COM_HVCH_Status1_BOD_HVCH_WorkMode_IPDU_COM_HVCH_Status1_BOD, &data.HVCH_WorkMode))
            {
                isSuccess = FALSE;
            }
            if (isSuccess == TRUE)
            {
                if (isSuccess == TRUE)
                {
                    rte_memcpy((uint8*)&Rte_Buf_Runbl_IpmCanRx_100ms_HVCH_Status1_BOD_HVCH_Status1_BOD,(uint8*)&data,sizeof(HVCH_Status1_BOD));
                    Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_HVCH_Status1_BOD_HVCH_Status1_BOD->status = RTE_E_OK;
                }
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_HVCH_Status2_BOD_IPDU_COM_HVCH_Status2_BOD
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
void Rte_COMCbk_HVCH_Status2_BOD_IPDU_COM_HVCH_Status2_BOD(void)
{
    if (RteInitState == RTE_INITED)
    {
        HVCH_Status2_BOD data;
        boolean isSuccess = TRUE;
        if (E_OK == Com_ReceiveSignalGroup(HVCH_Status2_BOD_IPDU_COM_HVCH_Status2_BOD))
        {
            if (E_NOT_OK == Com_ReceiveSignal(HVCH_Status2_BOD_IPDU_COM_HVCH_Status2_BOD_HVCHSts2_Checksum_IPDU_COM_HVCH_Status2_BOD, &data.HVCHSts2_Checksum))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(HVCH_Status2_BOD_IPDU_COM_HVCH_Status2_BOD_HVCHSts2_RollingCounter_IPDU_COM_HVCH_Status2_BOD, &data.HVCHSts2_RollingCounter))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(HVCH_Status2_BOD_IPDU_COM_HVCH_Status2_BOD_HVCH_FaultCode_IPDU_COM_HVCH_Status2_BOD, &data.HVCH_FaultCode))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(HVCH_Status2_BOD_IPDU_COM_HVCH_Status2_BOD_HVCH_HV_Volts_IPDU_COM_HVCH_Status2_BOD, &data.HVCH_HV_Volts))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(HVCH_Status2_BOD_IPDU_COM_HVCH_Status2_BOD_HVCH_Current_IPDU_COM_HVCH_Status2_BOD, &data.HVCH_Current))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(HVCH_Status2_BOD_IPDU_COM_HVCH_Status2_BOD_HVCH_Power_IPDU_COM_HVCH_Status2_BOD, &data.HVCH_Power))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(HVCH_Status2_BOD_IPDU_COM_HVCH_Status2_BOD_HVCH_WorkState_IPDU_COM_HVCH_Status2_BOD, &data.HVCH_WorkState))
            {
                isSuccess = FALSE;
            }
            if (isSuccess == TRUE)
            {
                if (isSuccess == TRUE)
                {
                    rte_memcpy((uint8*)&Rte_Buf_Runbl_IpmCanRx_100ms_HVCH_Status2_BOD_HVCH_Status2_BOD,(uint8*)&data,sizeof(HVCH_Status2_BOD));
                    Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_HVCH_Status2_BOD_HVCH_Status2_BOD->status = RTE_E_OK;
                }
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_ICU_2_Odo_BAC_IPDU_COM_ICU_2_Odo_BAC
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
void Rte_COMCbk_ICU_2_Odo_BAC_IPDU_COM_ICU_2_Odo_BAC(void)
{
    if (RteInitState == RTE_INITED)
    {
    }
    if((IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P10) == 1) || (IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P11) == 1))
    {
    Dem_UdsStatusByteType tmp = 0;
	if (E_OK == Dem_GetEventStatus(DemEventParameter_0xD11687, &tmp))
	{
		if (DEM_UDS_STATUS_TF == (tmp & DEM_UDS_STATUS_TF))
		{
			Dem_SetEventStatus(DemEventParameter_0xD11687, DEM_EVENT_STATUS_PASSED);
		}
	}
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_INV_1_Value_EPT_IPDU_COM_INV_1_Value_EPT
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
void Rte_COMCbk_INV_1_Value_EPT_IPDU_COM_INV_1_Value_EPT(void)
{
    if (RteInitState == RTE_INITED)
    {
        INV_1_Value_EPT data;
        boolean isSuccess = TRUE;
        if (E_OK == Com_ReceiveSignalGroup(INV_1_Value_EPT_IPDU_COM_INV_1_Value_EPT))
        {
            if (E_NOT_OK == Com_ReceiveSignal(INV_1_Value_EPT_IPDU_COM_INV_1_Value_EPT_INV_1_CheckSum_IPDU_COM_INV_1_Value_EPT, &data.INV_1_CheckSum))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(INV_1_Value_EPT_IPDU_COM_INV_1_Value_EPT_INV_1_RollingCounter_IPDU_COM_INV_1_Value_EPT, &data.INV_1_RollingCounter))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(INV_1_Value_EPT_IPDU_COM_INV_1_Value_EPT_INV_1_MotMode_IPDU_COM_INV_1_Value_EPT, &data.INV_1_MotMode))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(INV_1_Value_EPT_IPDU_COM_INV_1_Value_EPT_INV_1_ActTorque_IPDU_COM_INV_1_Value_EPT, &data.INV_1_ActTorque))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(INV_1_Value_EPT_IPDU_COM_INV_1_Value_EPT_INV_1_HasDerating_IPDU_COM_INV_1_Value_EPT, &data.INV_1_HasDerating))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(INV_1_Value_EPT_IPDU_COM_INV_1_Value_EPT_INV_1_MotSpeed_IPDU_COM_INV_1_Value_EPT, &data.INV_1_MotSpeed))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(INV_1_Value_EPT_IPDU_COM_INV_1_Value_EPT_INV_PreprogmFlg_IPDU_COM_INV_1_Value_EPT, &data.INV_PreprogmFlg))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(INV_1_Value_EPT_IPDU_COM_INV_1_Value_EPT_INV_SkidStaus_IPDU_COM_INV_1_Value_EPT, &data.INV_SkidStaus))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(INV_1_Value_EPT_IPDU_COM_INV_1_Value_EPT_INV_1_PreChargeAllowed_IPDU_COM_INV_1_Value_EPT, &data.INV_1_PreChargeAllowed))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(INV_1_Value_EPT_IPDU_COM_INV_1_Value_EPT_INV_1_ShutdownAllowed_IPDU_COM_INV_1_Value_EPT, &data.INV_1_ShutdownAllowed))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(INV_1_Value_EPT_IPDU_COM_INV_1_Value_EPT_INV_1_ActiveDischarge_Status_IPDU_COM_INV_1_Value_EPT, &data.INV_1_ActiveDischarge_Status))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(INV_1_Value_EPT_IPDU_COM_INV_1_Value_EPT_INV_AntithftAuthRslt_IPDU_COM_INV_1_Value_EPT, &data.INV_AntithftAuthRslt))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(INV_1_Value_EPT_IPDU_COM_INV_1_Value_EPT_INV_1_ActMode_IPDU_COM_INV_1_Value_EPT, &data.INV_1_ActMode))
            {
                isSuccess = FALSE;
            }
            if (isSuccess == TRUE)
            {
                if (isSuccess == TRUE)
                {
                    rte_memcpy((uint8*)&Rte_Buf_Runbl_IpmCanRx_10ms_INV_1_Value_EPT_INV_1_Value_EPT,(uint8*)&data,sizeof(INV_1_Value_EPT));
                    Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_INV_1_Value_EPT_INV_1_Value_EPT->status = RTE_E_OK;
                }
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_INV_2_Value_EPT_IPDU_COM_INV_2_Value_EPT
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
void Rte_COMCbk_INV_2_Value_EPT_IPDU_COM_INV_2_Value_EPT(void)
{
    if (RteInitState == RTE_INITED)
    {
        INV_2_Value_EPT data;
        boolean isSuccess = TRUE;
        if (E_OK == Com_ReceiveSignalGroup(INV_2_Value_EPT_IPDU_COM_INV_2_Value_EPT))
        {
            if (E_NOT_OK == Com_ReceiveSignal(INV_2_Value_EPT_IPDU_COM_INV_2_Value_EPT_INV_2_CheckSum_IPDU_COM_INV_2_Value_EPT, &data.INV_2_CheckSum))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(INV_2_Value_EPT_IPDU_COM_INV_2_Value_EPT_INV_2_RollingCounter_IPDU_COM_INV_2_Value_EPT, &data.INV_2_RollingCounter))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(INV_2_Value_EPT_IPDU_COM_INV_2_Value_EPT_INV_2_Derating_IPDU_COM_INV_2_Value_EPT, &data.INV_2_Derating))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(INV_2_Value_EPT_IPDU_COM_INV_2_Value_EPT_INV_2_MotorMaxTem_IPDU_COM_INV_2_Value_EPT, &data.INV_2_MotorMaxTem))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(INV_2_Value_EPT_IPDU_COM_INV_2_Value_EPT_INV_2_IgbtMaxTem_IPDU_COM_INV_2_Value_EPT, &data.INV_2_IgbtMaxTem))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(INV_2_Value_EPT_IPDU_COM_INV_2_Value_EPT_INV_2_InpCurrent_IPDU_COM_INV_2_Value_EPT, &data.INV_2_InpCurrent))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(INV_2_Value_EPT_IPDU_COM_INV_2_Value_EPT_INV_2_InpVoltage_IPDU_COM_INV_2_Value_EPT, &data.INV_2_InpVoltage))
            {
                isSuccess = FALSE;
            }
            if (isSuccess == TRUE)
            {
                if (isSuccess == TRUE)
                {
                    rte_memcpy((uint8*)&Rte_Buf_Runbl_IpmCanRx_10ms_INV_2_Value_EPT_INV_2_Value_EPT,(uint8*)&data,sizeof(INV_2_Value_EPT));
                    Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_INV_2_Value_EPT_INV_2_Value_EPT->status = RTE_E_OK;
                }
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_INV_3_Value_EPT_IPDU_COM_INV_3_Value_EPT
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
void Rte_COMCbk_INV_3_Value_EPT_IPDU_COM_INV_3_Value_EPT(void)
{
    if (RteInitState == RTE_INITED)
    {
        INV_3_Value_EPT data;
        boolean isSuccess = TRUE;
        if (E_OK == Com_ReceiveSignalGroup(INV_3_Value_EPT_IPDU_COM_INV_3_Value_EPT))
        {
            if (E_NOT_OK == Com_ReceiveSignal(INV_3_Value_EPT_IPDU_COM_INV_3_Value_EPT_INV_3_CheckSum_IPDU_COM_INV_3_Value_EPT, &data.INV_3_CheckSum))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(INV_3_Value_EPT_IPDU_COM_INV_3_Value_EPT_INV_3_RollingCounter_IPDU_COM_INV_3_Value_EPT, &data.INV_3_RollingCounter))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(INV_3_Value_EPT_IPDU_COM_INV_3_Value_EPT_INV_3_DriveTqAllowedMax_IPDU_COM_INV_3_Value_EPT, &data.INV_3_DriveTqAllowedMax))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(INV_3_Value_EPT_IPDU_COM_INV_3_Value_EPT_INV_ActiveDampingMark_IPDU_COM_INV_3_Value_EPT, &data.INV_ActiveDampingMark))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(INV_3_Value_EPT_IPDU_COM_INV_3_Value_EPT_INV_3_RecuperationTqAllowedMax_IPDU_COM_INV_3_Value_EPT, &data.INV_3_RecuperationTqAllowedMax))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(INV_3_Value_EPT_IPDU_COM_INV_3_Value_EPT_INV_ActiveDampingValue_IPDU_COM_INV_3_Value_EPT, &data.INV_ActiveDampingValue))
            {
                isSuccess = FALSE;
            }
            if (isSuccess == TRUE)
            {
                if (isSuccess == TRUE)
                {
                    rte_memcpy((uint8*)&Rte_Buf_Runbl_IpmCanRx_10ms_INV_3_Value_EPT_INV_3_Value_EPT,(uint8*)&data,sizeof(INV_3_Value_EPT));
                    Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_INV_3_Value_EPT_INV_3_Value_EPT->status = RTE_E_OK;
                }
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_INV_4_Value_EPT_IPDU_COM_INV_4_Value_EPT
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
void Rte_COMCbk_INV_4_Value_EPT_IPDU_COM_INV_4_Value_EPT(void)
{
    if (RteInitState == RTE_INITED)
    {
        INV_4_Value_EPT data;
        boolean isSuccess = TRUE;
        if (E_OK == Com_ReceiveSignalGroup(INV_4_Value_EPT_IPDU_COM_INV_4_Value_EPT))
        {
            if (E_NOT_OK == Com_ReceiveSignal(INV_4_Value_EPT_IPDU_COM_INV_4_Value_EPT_INV_4_CheckSum_IPDU_COM_INV_4_Value_EPT, &data.INV_4_CheckSum))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(INV_4_Value_EPT_IPDU_COM_INV_4_Value_EPT_INV_4_RollingCounter_IPDU_COM_INV_4_Value_EPT, &data.INV_4_RollingCounter))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(INV_4_Value_EPT_IPDU_COM_INV_4_Value_EPT_INV_4_FaultLevl_IPDU_COM_INV_4_Value_EPT, &data.INV_4_FaultLevl))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(INV_4_Value_EPT_IPDU_COM_INV_4_Value_EPT_INV_4_ErrBits_IPDU_COM_INV_4_Value_EPT, &data.INV_4_ErrBits))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(INV_4_Value_EPT_IPDU_COM_INV_4_Value_EPT_INV_4_PhaseV_AC_Current_IPDU_COM_INV_4_Value_EPT, &data.INV_4_PhaseV_AC_Current))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(INV_4_Value_EPT_IPDU_COM_INV_4_Value_EPT_INV_4_PhaseU_AC_Current_IPDU_COM_INV_4_Value_EPT, &data.INV_4_PhaseU_AC_Current))
            {
                isSuccess = FALSE;
            }
            if (isSuccess == TRUE)
            {
                if (isSuccess == TRUE)
                {
                    rte_memcpy((uint8*)&Rte_Buf_Runbl_IpmCanRx_10ms_INV_4_Value_EPT_INV_4_Value_EPT,(uint8*)&data,sizeof(INV_4_Value_EPT));
                    Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_10ms_INV_4_Value_EPT_INV_4_Value_EPT->status = RTE_E_OK;
                }
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_INV_IMMO_Req_EPT_IPDU_COM_INV_IMMO_Req_EPT
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
void Rte_COMCbk_INV_IMMO_Req_EPT_IPDU_COM_INV_IMMO_Req_EPT(void)
{
    if (RteInitState == RTE_INITED)
    {
        INV_IMMO_Req_EPT data;
        boolean isSuccess = TRUE;
        if (E_OK == Com_ReceiveSignalGroup(INV_IMMO_Req_EPT_IPDU_COM_INV_IMMO_Req_EPT))
        {
            if (E_NOT_OK == Com_ReceiveSignal(INV_IMMO_Req_EPT_IPDU_COM_INV_IMMO_Req_EPT_INV_LrngSubID_IPDU_COM_INV_IMMO_Req_EPT, &data.INV_LrngSubID))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(INV_IMMO_Req_EPT_IPDU_COM_INV_IMMO_Req_EPT_INV_LrngSts_IPDU_COM_INV_IMMO_Req_EPT, &data.INV_LrngSts))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(INV_IMMO_Req_EPT_IPDU_COM_INV_IMMO_Req_EPT_INV_LrngData02_IPDU_COM_INV_IMMO_Req_EPT, &data.INV_LrngData02))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(INV_IMMO_Req_EPT_IPDU_COM_INV_IMMO_Req_EPT_INV_LrngData03_IPDU_COM_INV_IMMO_Req_EPT, &data.INV_LrngData03))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(INV_IMMO_Req_EPT_IPDU_COM_INV_IMMO_Req_EPT_INV_LrngData04_IPDU_COM_INV_IMMO_Req_EPT, &data.INV_LrngData04))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(INV_IMMO_Req_EPT_IPDU_COM_INV_IMMO_Req_EPT_INV_LrngData05_IPDU_COM_INV_IMMO_Req_EPT, &data.INV_LrngData05))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(INV_IMMO_Req_EPT_IPDU_COM_INV_IMMO_Req_EPT_INV_LrngData06_IPDU_COM_INV_IMMO_Req_EPT, &data.INV_LrngData06))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(INV_IMMO_Req_EPT_IPDU_COM_INV_IMMO_Req_EPT_INV_LrngData07_IPDU_COM_INV_IMMO_Req_EPT, &data.INV_LrngData07))
            {
                isSuccess = FALSE;
            }
            if (isSuccess == TRUE)
            {
                if (isSuccess == TRUE)
                {
                    rte_memcpy((uint8*)&Rte_Buf_Runbl_IpmCanRx_100ms_INV_IMMO_Req_EPT_INV_IMMO_Req_EPT,(uint8*)&data,sizeof(INV_IMMO_Req_EPT));
                    Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_INV_IMMO_Req_EPT_INV_IMMO_Req_EPT->status = RTE_E_OK;
                }
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_IPU_DCC_1_State_EPT_IPDU_COM_IPU_DCC_1_State_EPT
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
void Rte_COMCbk_IPU_DCC_1_State_EPT_IPDU_COM_IPU_DCC_1_State_EPT(void)
{
    if (RteInitState == RTE_INITED)
    {
        IPU_DCC_1_State_EPT data;
        boolean isSuccess = TRUE;
        if (E_OK == Com_ReceiveSignalGroup(IPU_DCC_1_State_EPT_IPDU_COM_IPU_DCC_1_State_EPT))
        {
            if (E_NOT_OK == Com_ReceiveSignal(IPU_DCC_1_State_EPT_IPDU_COM_IPU_DCC_1_State_EPT_IPU_DCC_1_Chksum_IPDU_COM_IPU_DCC_1_State_EPT, &data.IPU_DCC_1_Chksum))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(IPU_DCC_1_State_EPT_IPDU_COM_IPU_DCC_1_State_EPT_IPU_DCC_1_AliveCnt_IPDU_COM_IPU_DCC_1_State_EPT, &data.IPU_DCC_1_AliveCnt))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(IPU_DCC_1_State_EPT_IPDU_COM_IPU_DCC_1_State_EPT_IPU_DCC_LowVolActlVol_IPDU_COM_IPU_DCC_1_State_EPT, &data.IPU_DCC_LowVolActlVol))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(IPU_DCC_1_State_EPT_IPDU_COM_IPU_DCC_1_State_EPT_IPU_DCC_ActlOprtMode_IPDU_COM_IPU_DCC_1_State_EPT, &data.IPU_DCC_ActlOprtMode))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(IPU_DCC_1_State_EPT_IPDU_COM_IPU_DCC_1_State_EPT_IPU_DCC_LowVolActlCur_IPDU_COM_IPU_DCC_1_State_EPT, &data.IPU_DCC_LowVolActlCur))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(IPU_DCC_1_State_EPT_IPDU_COM_IPU_DCC_1_State_EPT_IPU_HVILFailSta_IPDU_COM_IPU_DCC_1_State_EPT, &data.IPU_HVILFailSta))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(IPU_DCC_1_State_EPT_IPDU_COM_IPU_DCC_1_State_EPT_IPU_DCC_SysFailSta_IPDU_COM_IPU_DCC_1_State_EPT, &data.IPU_DCC_SysFailSta))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(IPU_DCC_1_State_EPT_IPDU_COM_IPU_DCC_1_State_EPT_IPU_OverTemperatureFail_IPDU_COM_IPU_DCC_1_State_EPT, &data.IPU_OverTemperatureFail))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(IPU_DCC_1_State_EPT_IPDU_COM_IPU_DCC_1_State_EPT_IPU_DCC_DeratingOprtSta_IPDU_COM_IPU_DCC_1_State_EPT, &data.IPU_DCC_DeratingOprtSta))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(IPU_DCC_1_State_EPT_IPDU_COM_IPU_DCC_1_State_EPT_IPU_DCC_PrechargeComplete_IPDU_COM_IPU_DCC_1_State_EPT, &data.IPU_DCC_PrechargeComplete))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(IPU_DCC_1_State_EPT_IPDU_COM_IPU_DCC_1_State_EPT_IPU_DCC_Errbit_IPDU_COM_IPU_DCC_1_State_EPT, &data.IPU_DCC_Errbit))
            {
                isSuccess = FALSE;
            }
            if (isSuccess == TRUE)
            {
                if (isSuccess == TRUE)
                {
                    rte_memcpy((uint8*)&Rte_Buf_Runbl_IpmCanRx_100ms_IPU_DCC_1_State_EPT_IPU_DCC_1_State_EPT,(uint8*)&data,sizeof(IPU_DCC_1_State_EPT));
                    Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPU_DCC_1_State_EPT_IPU_DCC_1_State_EPT->status = RTE_E_OK;
                }
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_IPU_DCC_2_ChrgInValue_EPT_IPDU_COM_IPU_DCC_2_ChrgInValue_EPT
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
void Rte_COMCbk_IPU_DCC_2_ChrgInValue_EPT_IPDU_COM_IPU_DCC_2_ChrgInValue_EPT(void)
{
    if (RteInitState == RTE_INITED)
    {
        IPU_DCC_2_ChrgInValue_EPT data;
        boolean isSuccess = TRUE;
        if (E_OK == Com_ReceiveSignalGroup(IPU_DCC_2_ChrgInValue_EPT_IPDU_COM_IPU_DCC_2_ChrgInValue_EPT))
        {
            if (E_NOT_OK == Com_ReceiveSignal(IPU_DCC_2_ChrgInValue_EPT_IPDU_COM_IPU_DCC_2_ChrgInValue_EPT_IPU_DCC_2_Chksum_IPDU_COM_IPU_DCC_2_ChrgInValue_EPT, &data.IPU_DCC_2_Chksum))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(IPU_DCC_2_ChrgInValue_EPT_IPDU_COM_IPU_DCC_2_ChrgInValue_EPT_IPU_DCC_2_AliveCnt_IPDU_COM_IPU_DCC_2_ChrgInValue_EPT, &data.IPU_DCC_2_AliveCnt))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(IPU_DCC_2_ChrgInValue_EPT_IPDU_COM_IPU_DCC_2_ChrgInValue_EPT_IPU_DCC_HighVoltActlCur_IPDU_COM_IPU_DCC_2_ChrgInValue_EPT, &data.IPU_DCC_HighVoltActlCur))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(IPU_DCC_2_ChrgInValue_EPT_IPDU_COM_IPU_DCC_2_ChrgInValue_EPT_IPU_DCC_HighVoltActlVol_IPDU_COM_IPU_DCC_2_ChrgInValue_EPT, &data.IPU_DCC_HighVoltActlVol))
            {
                isSuccess = FALSE;
            }
            if (isSuccess == TRUE)
            {
                if (isSuccess == TRUE)
                {
                    rte_memcpy((uint8*)&Rte_Buf_Runbl_IpmCanRx_100ms_IPU_DCC_2_ChrgInValue_EPT_IPU_DCC_2_ChrgInValue_EPT,(uint8*)&data,sizeof(IPU_DCC_2_ChrgInValue_EPT));
                    Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPU_DCC_2_ChrgInValue_EPT_IPU_DCC_2_ChrgInValue_EPT->status = RTE_E_OK;
                }
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_IPU_OBC_1_State_EPT_IPDU_COM_IPU_OBC_1_State_EPT
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
void Rte_COMCbk_IPU_OBC_1_State_EPT_IPDU_COM_IPU_OBC_1_State_EPT(void)
{
    if((IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P10) == 1) || (IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P11) == 1))
    {
    Dem_UdsStatusByteType tmp = 0;
	if (E_OK == Dem_GetEventStatus(DemEventParameter_0xC14687, &tmp))
	{
		if (DEM_UDS_STATUS_TF == (tmp & DEM_UDS_STATUS_TF))
		{
			Dem_SetEventStatus(DemEventParameter_0xC14687, DEM_EVENT_STATUS_PASSED);
		}
	}
    }
    if (RteInitState == RTE_INITED)
    {
        IPU_OBC_1_State_EPT data;
        boolean isSuccess = TRUE;
        if (E_OK == Com_ReceiveSignalGroup(IPU_OBC_1_State_EPT_IPDU_COM_IPU_OBC_1_State_EPT))
        {
            if (E_NOT_OK == Com_ReceiveSignal(IPU_OBC_1_State_EPT_IPDU_COM_IPU_OBC_1_State_EPT_IPU_OBC_1_Chksum_IPDU_COM_IPU_OBC_1_State_EPT, &data.IPU_OBC_1_Chksum))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(IPU_OBC_1_State_EPT_IPDU_COM_IPU_OBC_1_State_EPT_IPU_OBC_1_AliveCnt_IPDU_COM_IPU_OBC_1_State_EPT, &data.IPU_OBC_1_AliveCnt))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(IPU_OBC_1_State_EPT_IPDU_COM_IPU_OBC_1_State_EPT_IPU_OBC_ConnectMainSta_IPDU_COM_IPU_OBC_1_State_EPT, &data.IPU_OBC_ConnectMainSta))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(IPU_OBC_1_State_EPT_IPDU_COM_IPU_OBC_1_State_EPT_IPU_OBC_HVDC_ActlCur_IPDU_COM_IPU_OBC_1_State_EPT, &data.IPU_OBC_HVDC_ActlCur))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(IPU_OBC_1_State_EPT_IPDU_COM_IPU_OBC_1_State_EPT_IPU_OBC_SysFailSta_IPDU_COM_IPU_OBC_1_State_EPT, &data.IPU_OBC_SysFailSta))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(IPU_OBC_1_State_EPT_IPDU_COM_IPU_OBC_1_State_EPT_IPU_OBC_InletConnctSta_IPDU_COM_IPU_OBC_1_State_EPT, &data.IPU_OBC_InletConnctSta))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(IPU_OBC_1_State_EPT_IPDU_COM_IPU_OBC_1_State_EPT_IPU_OBC_Request_IPDU_COM_IPU_OBC_1_State_EPT, &data.IPU_OBC_Request))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(IPU_OBC_1_State_EPT_IPDU_COM_IPU_OBC_1_State_EPT_IPU_OBC_HVDC_ActlVol_IPDU_COM_IPU_OBC_1_State_EPT, &data.IPU_OBC_HVDC_ActlVol))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(IPU_OBC_1_State_EPT_IPDU_COM_IPU_OBC_1_State_EPT_IPU_OBC_ActlOprtMode_IPDU_COM_IPU_OBC_1_State_EPT, &data.IPU_OBC_ActlOprtMode))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(IPU_OBC_1_State_EPT_IPDU_COM_IPU_OBC_1_State_EPT_IPU_OBC_InleltActlPower_IPDU_COM_IPU_OBC_1_State_EPT, &data.IPU_OBC_InleltActlPower))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(IPU_OBC_1_State_EPT_IPDU_COM_IPU_OBC_1_State_EPT_IPU_OBC_Errbit_IPDU_COM_IPU_OBC_1_State_EPT, &data.IPU_OBC_Errbit))
            {
                isSuccess = FALSE;
            }
            if (isSuccess == TRUE)
            {
                if (isSuccess == TRUE)
                {
                    rte_memcpy((uint8*)&Rte_Buf_Runbl_IpmCanRx_100ms_IPU_OBC_1_State_EPT_IPU_OBC_1_State_EPT,(uint8*)&data,sizeof(IPU_OBC_1_State_EPT));
                    Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPU_OBC_1_State_EPT_IPU_OBC_1_State_EPT->status = RTE_E_OK;
                }
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_IPU_OBC_2_Inlet_EPT_IPDU_COM_IPU_OBC_2_Inlet_EPT
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
void Rte_COMCbk_IPU_OBC_2_Inlet_EPT_IPDU_COM_IPU_OBC_2_Inlet_EPT(void)
{
    if (RteInitState == RTE_INITED)
    {
        IPU_OBC_2_Inlet_EPT data;
        boolean isSuccess = TRUE;
        if (E_OK == Com_ReceiveSignalGroup(IPU_OBC_2_Inlet_EPT_IPDU_COM_IPU_OBC_2_Inlet_EPT))
        {
            if (E_NOT_OK == Com_ReceiveSignal(IPU_OBC_2_Inlet_EPT_IPDU_COM_IPU_OBC_2_Inlet_EPT_IPU_OBC_2_Chksum_IPDU_COM_IPU_OBC_2_Inlet_EPT, &data.IPU_OBC_2_Chksum))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(IPU_OBC_2_Inlet_EPT_IPDU_COM_IPU_OBC_2_Inlet_EPT_IPU_OBC_2_AliveCnt_IPDU_COM_IPU_OBC_2_Inlet_EPT, &data.IPU_OBC_2_AliveCnt))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(IPU_OBC_2_Inlet_EPT_IPDU_COM_IPU_OBC_2_Inlet_EPT_IPU_DeviceIntTemp_IPDU_COM_IPU_OBC_2_Inlet_EPT, &data.IPU_DeviceIntTemp))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(IPU_OBC_2_Inlet_EPT_IPDU_COM_IPU_OBC_2_Inlet_EPT_IPU_OBC_TempInlet_IPDU_COM_IPU_OBC_2_Inlet_EPT, &data.IPU_OBC_TempInlet))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(IPU_OBC_2_Inlet_EPT_IPDU_COM_IPU_OBC_2_Inlet_EPT_IPU_OBC_S2_State_IPDU_COM_IPU_OBC_2_Inlet_EPT, &data.IPU_OBC_S2_State))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(IPU_OBC_2_Inlet_EPT_IPDU_COM_IPU_OBC_2_Inlet_EPT_IPU_OBC_Wake_Up_Mode_IPDU_COM_IPU_OBC_2_Inlet_EPT, &data.IPU_OBC_Wake_Up_Mode))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(IPU_OBC_2_Inlet_EPT_IPDU_COM_IPU_OBC_2_Inlet_EPT_IPU_OBC_Inlet_Electronic_Lock_IPDU_COM_IPU_OBC_2_Inlet_EPT, &data.IPU_OBC_Inlet_Electronic_Lock))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(IPU_OBC_2_Inlet_EPT_IPDU_COM_IPU_OBC_2_Inlet_EPT_IPU_OBC_ACMaxPwAllow_IPDU_COM_IPU_OBC_2_Inlet_EPT, &data.IPU_OBC_ACMaxPwAllow))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(IPU_OBC_2_Inlet_EPT_IPDU_COM_IPU_OBC_2_Inlet_EPT_IPU_OBC_VoltageOkL3_IPDU_COM_IPU_OBC_2_Inlet_EPT, &data.IPU_OBC_VoltageOkL3))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(IPU_OBC_2_Inlet_EPT_IPDU_COM_IPU_OBC_2_Inlet_EPT_IPU_OBC_VoltageOkL2_IPDU_COM_IPU_OBC_2_Inlet_EPT, &data.IPU_OBC_VoltageOkL2))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(IPU_OBC_2_Inlet_EPT_IPDU_COM_IPU_OBC_2_Inlet_EPT_IPU_OBC_VoltageOkL1_IPDU_COM_IPU_OBC_2_Inlet_EPT, &data.IPU_OBC_VoltageOkL1))
            {
                isSuccess = FALSE;
            }
            if (isSuccess == TRUE)
            {
                if (isSuccess == TRUE)
                {
                    rte_memcpy((uint8*)&Rte_Buf_Runbl_IpmCanRx_100ms_IPU_OBC_2_Inlet_EPT_IPU_OBC_2_Inlet_EPT,(uint8*)&data,sizeof(IPU_OBC_2_Inlet_EPT));
                    Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_IPU_OBC_2_Inlet_EPT_IPU_OBC_2_Inlet_EPT->status = RTE_E_OK;
                }
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_MotPMP_PumpDryRunningSta_MotPMP_Sts_LIN1
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
void Rte_COMCbk_MotPMP_PumpDryRunningSta_MotPMP_Sts_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        Boolean data;
        boolean isSuccess = TRUE;
        boolean MotPMP_PumpDryRunningSta_MotPMP_Sts_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(MotPMP_PumpDryRunningSta_MotPMP_Sts_LIN1, &MotPMP_PumpDryRunningSta_MotPMP_Sts_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (Boolean)MotPMP_PumpDryRunningSta_MotPMP_Sts_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_MotPMP_PumpDryRunningSta_MotPMP_PumpDryRunningSta = data;
                Rte_Inst_ME11.Task_100ms_MotPMP_PumpDryRunningSta_MotPMP_PumpDryRunningSta->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_MotPMP_PumpDryRunningSta_MotPMP_Sts_LIN2
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
void Rte_COMCbk_MotPMP_PumpDryRunningSta_MotPMP_Sts_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        Boolean data;
        boolean isSuccess = TRUE;
        boolean MotPMP_PumpDryRunningSta_MotPMP_Sts_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(MotPMP_PumpDryRunningSta_MotPMP_Sts_LIN2, &MotPMP_PumpDryRunningSta_MotPMP_Sts_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (Boolean)MotPMP_PumpDryRunningSta_MotPMP_Sts_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_MotPMP_PumpDryRunningSta_MotPMP_PumpDryRunningSta = data;
                Rte_Inst_ME11.Task_100ms_MotPMP_PumpDryRunningSta_MotPMP_PumpDryRunningSta->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_MotPMP_PumpInputVolt_MotPMP_Sts_LIN1
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
void Rte_COMCbk_MotPMP_PumpInputVolt_MotPMP_Sts_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 MotPMP_PumpInputVolt_MotPMP_Sts_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(MotPMP_PumpInputVolt_MotPMP_Sts_LIN1, &MotPMP_PumpInputVolt_MotPMP_Sts_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)MotPMP_PumpInputVolt_MotPMP_Sts_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_MotPMP_PumpInputVolt_MotPMP_PumpInputVolt = data;
                Rte_Inst_ME11.Task_100ms_MotPMP_PumpInputVolt_MotPMP_PumpInputVolt->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_MotPMP_PumpInputVolt_MotPMP_Sts_LIN2
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
void Rte_COMCbk_MotPMP_PumpInputVolt_MotPMP_Sts_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 MotPMP_PumpInputVolt_MotPMP_Sts_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(MotPMP_PumpInputVolt_MotPMP_Sts_LIN2, &MotPMP_PumpInputVolt_MotPMP_Sts_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)MotPMP_PumpInputVolt_MotPMP_Sts_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_MotPMP_PumpInputVolt_MotPMP_PumpInputVolt = data;
                Rte_Inst_ME11.Task_100ms_MotPMP_PumpInputVolt_MotPMP_PumpInputVolt->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_MotPMP_PumpMotorSta_MotPMP_Sts_LIN1
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
void Rte_COMCbk_MotPMP_PumpMotorSta_MotPMP_Sts_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 MotPMP_PumpMotorSta_MotPMP_Sts_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(MotPMP_PumpMotorSta_MotPMP_Sts_LIN1, &MotPMP_PumpMotorSta_MotPMP_Sts_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)MotPMP_PumpMotorSta_MotPMP_Sts_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_MotPMP_PumpMotorSta_MotPMP_PumpMotorSta = data;
                Rte_Inst_ME11.Task_100ms_MotPMP_PumpMotorSta_MotPMP_PumpMotorSta->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_MotPMP_PumpMotorSta_MotPMP_Sts_LIN2
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
void Rte_COMCbk_MotPMP_PumpMotorSta_MotPMP_Sts_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 MotPMP_PumpMotorSta_MotPMP_Sts_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(MotPMP_PumpMotorSta_MotPMP_Sts_LIN2, &MotPMP_PumpMotorSta_MotPMP_Sts_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)MotPMP_PumpMotorSta_MotPMP_Sts_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_MotPMP_PumpMotorSta_MotPMP_PumpMotorSta = data;
                Rte_Inst_ME11.Task_100ms_MotPMP_PumpMotorSta_MotPMP_PumpMotorSta->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_MotPMP_PumpPowerSta_MotPMP_Sts_LIN1
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
void Rte_COMCbk_MotPMP_PumpPowerSta_MotPMP_Sts_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 MotPMP_PumpPowerSta_MotPMP_Sts_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(MotPMP_PumpPowerSta_MotPMP_Sts_LIN1, &MotPMP_PumpPowerSta_MotPMP_Sts_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)MotPMP_PumpPowerSta_MotPMP_Sts_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_MotPMP_PumpPowerSta_MotPMP_PumpPowerSta = data;
                Rte_Inst_ME11.Task_100ms_MotPMP_PumpPowerSta_MotPMP_PumpPowerSta->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_MotPMP_PumpPowerSta_MotPMP_Sts_LIN2
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
void Rte_COMCbk_MotPMP_PumpPowerSta_MotPMP_Sts_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 MotPMP_PumpPowerSta_MotPMP_Sts_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(MotPMP_PumpPowerSta_MotPMP_Sts_LIN2, &MotPMP_PumpPowerSta_MotPMP_Sts_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)MotPMP_PumpPowerSta_MotPMP_Sts_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_MotPMP_PumpPowerSta_MotPMP_PumpPowerSta = data;
                Rte_Inst_ME11.Task_100ms_MotPMP_PumpPowerSta_MotPMP_PumpPowerSta->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_MotPMP_PumpTempSta_MotPMP_Sts_LIN1
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
void Rte_COMCbk_MotPMP_PumpTempSta_MotPMP_Sts_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 MotPMP_PumpTempSta_MotPMP_Sts_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(MotPMP_PumpTempSta_MotPMP_Sts_LIN1, &MotPMP_PumpTempSta_MotPMP_Sts_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)MotPMP_PumpTempSta_MotPMP_Sts_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_MotPMP_PumpTempSta_MotPMP_PumpTempSta = data;
                Rte_Inst_ME11.Task_100ms_MotPMP_PumpTempSta_MotPMP_PumpTempSta->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_MotPMP_PumpTempSta_MotPMP_Sts_LIN2
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
void Rte_COMCbk_MotPMP_PumpTempSta_MotPMP_Sts_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 MotPMP_PumpTempSta_MotPMP_Sts_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(MotPMP_PumpTempSta_MotPMP_Sts_LIN2, &MotPMP_PumpTempSta_MotPMP_Sts_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)MotPMP_PumpTempSta_MotPMP_Sts_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_MotPMP_PumpTempSta_MotPMP_PumpTempSta = data;
                Rte_Inst_ME11.Task_100ms_MotPMP_PumpTempSta_MotPMP_PumpTempSta->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_MotPMP_RESP_ERROR_MotPMP_Sts_LIN1
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
void Rte_COMCbk_MotPMP_RESP_ERROR_MotPMP_Sts_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        Boolean data;
        boolean isSuccess = TRUE;
        boolean MotPMP_RESP_ERROR_MotPMP_Sts_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(MotPMP_RESP_ERROR_MotPMP_Sts_LIN1, &MotPMP_RESP_ERROR_MotPMP_Sts_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (Boolean)MotPMP_RESP_ERROR_MotPMP_Sts_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_MotPMP_RESP_ERROR_MotPMP_RESP_ERROR = data;
                Rte_Inst_ME11.Task_100ms_MotPMP_RESP_ERROR_MotPMP_RESP_ERROR->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_MotPMP_RESP_ERROR_MotPMP_Sts_LIN2
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
void Rte_COMCbk_MotPMP_RESP_ERROR_MotPMP_Sts_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        Boolean data;
        boolean isSuccess = TRUE;
        boolean MotPMP_RESP_ERROR_MotPMP_Sts_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(MotPMP_RESP_ERROR_MotPMP_Sts_LIN2, &MotPMP_RESP_ERROR_MotPMP_Sts_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (Boolean)MotPMP_RESP_ERROR_MotPMP_Sts_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_MotPMP_RESP_ERROR_MotPMP_RESP_ERROR = data;
                Rte_Inst_ME11.Task_100ms_MotPMP_RESP_ERROR_MotPMP_RESP_ERROR->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_MotPMP_RealRPM_MotPMP_Sts_LIN1
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
void Rte_COMCbk_MotPMP_RealRPM_MotPMP_Sts_LIN1(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 MotPMP_RealRPM_MotPMP_Sts_LIN1_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(MotPMP_RealRPM_MotPMP_Sts_LIN1, &MotPMP_RealRPM_MotPMP_Sts_LIN1_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)MotPMP_RealRPM_MotPMP_Sts_LIN1_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_MotPMP_RealRPM_MotPMP_RealRPM = data;
                Rte_Inst_ME11.Task_100ms_MotPMP_RealRPM_MotPMP_RealRPM->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_MotPMP_RealRPM_MotPMP_Sts_LIN2
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
void Rte_COMCbk_MotPMP_RealRPM_MotPMP_Sts_LIN2(void)
{
    if (RteInitState == RTE_INITED)
    {
        UInt8 data;
        boolean isSuccess = TRUE;
        uint8 MotPMP_RealRPM_MotPMP_Sts_LIN2_buf;
        Std_ReturnType comStatus;
        comStatus = Com_ReceiveSignal(MotPMP_RealRPM_MotPMP_Sts_LIN2, &MotPMP_RealRPM_MotPMP_Sts_LIN2_buf);
        if (comStatus != E_OK)
        {
            isSuccess = FALSE;
        }
        else
        {
            data = (UInt8)MotPMP_RealRPM_MotPMP_Sts_LIN2_buf;
            if (isSuccess == TRUE)
            {
                Rte_Buf_Task_100ms_MotPMP_RealRPM_MotPMP_RealRPM = data;
                Rte_Inst_ME11.Task_100ms_MotPMP_RealRPM_MotPMP_RealRPM->status = RTE_E_OK;
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5
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
void Rte_COMCbk_PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5(void)
{
    if((IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P10) == 1) || (IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P11) == 1))
    {
    Dem_UdsStatusByteType tmp = 0;
	if (E_OK == Dem_GetEventStatus(DemEventParameter_0xD10E87, &tmp))
	{
		if (DEM_UDS_STATUS_TF == (tmp & DEM_UDS_STATUS_TF))
		{
			Dem_SetEventStatus(DemEventParameter_0xD10E87, DEM_EVENT_STATUS_PASSED);
		}
	}
    }
    if (RteInitState == RTE_INITED)
    {
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD
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
void Rte_COMCbk_SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD(void)
{
    if (RteInitState == RTE_INITED)
    {
        SCS_LeSwitchSts_BOD data;
        boolean isSuccess = TRUE;
        if (E_OK == Com_ReceiveSignalGroup(SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD))
        {
            if (E_NOT_OK == Com_ReceiveSignal(SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_Chksum_IPDU_COM_SCS_LeSwitchSts_BOD, &data.SCS_LeSwitchSts_Chksum))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_AliveCnt_IPDU_COM_SCS_LeSwitchSts_BOD, &data.SCS_LeSwitchSts_AliveCnt))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_FrntWshrSwtSt_IPDU_COM_SCS_LeSwitchSts_BOD, &data.SCS_FrntWshrSwtSt))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_FrntWshrSwtStVD_IPDU_COM_SCS_LeSwitchSts_BOD, &data.SCS_FrntWshrSwtStVD))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_RearWiprSwtSt_IPDU_COM_SCS_LeSwitchSts_BOD, &data.SCS_RearWiprSwtSt))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_FrntWiprSwtSt_IPDU_COM_SCS_LeSwitchSts_BOD, &data.SCS_FrntWiprSwtSt))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_WasrSwtStVD_IPDU_COM_SCS_LeSwitchSts_BOD, &data.SCS_WasrSwtStVD))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_WiprSwtStVD_IPDU_COM_SCS_LeSwitchSts_BOD, &data.SCS_WiprSwtStVD))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_PositionLightswitchSt_IPDU_COM_SCS_LeSwitchSts_BOD, &data.SCS_PositionLightswitchSt))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_LowBeamSwtSt_IPDU_COM_SCS_LeSwitchSts_BOD, &data.SCS_LowBeamSwtSt))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_HiBeamSwtSt_IPDU_COM_SCS_LeSwitchSts_BOD, &data.SCS_HiBeamSwtSt))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_OverVehBeamSwtSt_IPDU_COM_SCS_LeSwitchSts_BOD, &data.SCS_OverVehBeamSwtSt))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_LampAutoSt_IPDU_COM_SCS_LeSwitchSts_BOD, &data.SCS_LampAutoSt))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_LeTurnLmpSwtSt_IPDU_COM_SCS_LeSwitchSts_BOD, &data.SCS_LeTurnLmpSwtSt))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_RiTurnLmpSwtSt_IPDU_COM_SCS_LeSwitchSts_BOD, &data.SCS_RiTurnLmpSwtSt))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_Left_1Swt_IPDU_COM_SCS_LeSwitchSts_BOD, &data.SCS_Left_1Swt))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_Left_2Swt_IPDU_COM_SCS_LeSwitchSts_BOD, &data.SCS_Left_2Swt))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_Left_3Swt_IPDU_COM_SCS_LeSwitchSts_BOD, &data.SCS_Left_3Swt))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_Left_4Swt_IPDU_COM_SCS_LeSwitchSts_BOD, &data.SCS_Left_4Swt))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_Left_5Swt_IPDU_COM_SCS_LeSwitchSts_BOD, &data.SCS_Left_5Swt))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_Left_6Swt_IPDU_COM_SCS_LeSwitchSts_BOD, &data.SCS_Left_6Swt))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_KnobBeamSwtStVD_IPDU_COM_SCS_LeSwitchSts_BOD, &data.SCS_KnobBeamSwtStVD))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_RodBeamSwtStVD_IPDU_COM_SCS_LeSwitchSts_BOD, &data.SCS_RodBeamSwtStVD))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_Left_7Swt_IPDU_COM_SCS_LeSwitchSts_BOD, &data.SCS_Left_7Swt))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_Left_8Swt_IPDU_COM_SCS_LeSwitchSts_BOD, &data.SCS_Left_8Swt))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_LeftSwtVD_IPDU_COM_SCS_LeSwitchSts_BOD, &data.SCS_LeftSwtVD))
            {
                isSuccess = FALSE;
            }
            if (isSuccess == TRUE)
            {
                if (isSuccess == TRUE)
                {
                    rte_memcpy((uint8*)&Rte_Buf_Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD,(uint8*)&data,sizeof(SCS_LeSwitchSts_BOD));
                    Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD->status = RTE_E_OK;
                }
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_SRS_2_YRSOriginalSts_CHA_IPDU_COM_SRS_2_YRSOriginalSts_CHA
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
void Rte_COMCbk_SRS_2_YRSOriginalSts_CHA_IPDU_COM_SRS_2_YRSOriginalSts_CHA(void)
{
    if (RteInitState == RTE_INITED)
    {
    }
    if((IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P10) == 1) || (IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P11) == 1))
    {
    Dem_UdsStatusByteType tmp = 0;
	if (E_OK == Dem_GetEventStatus(DemEventParameter_0xC15187, &tmp))
	{
		if (DEM_UDS_STATUS_TF == (tmp & DEM_UDS_STATUS_TF))
		{
			Dem_SetEventStatus(DemEventParameter_0xC15187, DEM_EVENT_STATUS_PASSED);
		}
	}
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_TBOX_BJS_Time_BAC_IPDU_COM_TBOX_BJS_Time_BAC
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
void Rte_COMCbk_TBOX_BJS_Time_BAC_IPDU_COM_TBOX_BJS_Time_BAC(void)
{
    if((IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P10) == 1) || (IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P11) == 1))
    {
    Dem_UdsStatusByteType tmp = 0;
	if (E_OK == Dem_GetEventStatus(DemEventParameter_0xC19887, &tmp))
	{
		if (DEM_UDS_STATUS_TF == (tmp & DEM_UDS_STATUS_TF))
		{
			Dem_SetEventStatus(DemEventParameter_0xC19887, DEM_EVENT_STATUS_PASSED);
		}
	}
    }
    if (RteInitState == RTE_INITED)
    {
        TBOX_BJS_Time_BAC data;
        boolean isSuccess = TRUE;
        if (E_OK == Com_ReceiveSignalGroup(TBOX_BJS_Time_BAC_IPDU_COM_TBOX_BJS_Time_BAC))
        {
            if (E_NOT_OK == Com_ReceiveSignal(TBOX_BJS_Time_BAC_IPDU_COM_TBOX_BJS_Time_BAC_TBOX_BJS_Chksum_IPDU_COM_TBOX_BJS_Time_BAC, &data.TBOX_BJS_Chksum))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(TBOX_BJS_Time_BAC_IPDU_COM_TBOX_BJS_Time_BAC_TBOX_BJS_AliveCnt_IPDU_COM_TBOX_BJS_Time_BAC, &data.TBOX_BJS_AliveCnt))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(TBOX_BJS_Time_BAC_IPDU_COM_TBOX_BJS_Time_BAC_TBOX_BJS_Time_Year_IPDU_COM_TBOX_BJS_Time_BAC, &data.TBOX_BJS_Time_Year))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(TBOX_BJS_Time_BAC_IPDU_COM_TBOX_BJS_Time_BAC_TBOX_BJS_Time_Month_IPDU_COM_TBOX_BJS_Time_BAC, &data.TBOX_BJS_Time_Month))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(TBOX_BJS_Time_BAC_IPDU_COM_TBOX_BJS_Time_BAC_TBOX_BJS_Time_Day_IPDU_COM_TBOX_BJS_Time_BAC, &data.TBOX_BJS_Time_Day))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(TBOX_BJS_Time_BAC_IPDU_COM_TBOX_BJS_Time_BAC_TBOX_BJS_Time_Hour_IPDU_COM_TBOX_BJS_Time_BAC, &data.TBOX_BJS_Time_Hour))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(TBOX_BJS_Time_BAC_IPDU_COM_TBOX_BJS_Time_BAC_TBOX_BJS_Time_Min_IPDU_COM_TBOX_BJS_Time_BAC, &data.TBOX_BJS_Time_Min))
            {
                isSuccess = FALSE;
            }
            if (E_NOT_OK == Com_ReceiveSignal(TBOX_BJS_Time_BAC_IPDU_COM_TBOX_BJS_Time_BAC_TBOX_BJS_Time_Sec_IPDU_COM_TBOX_BJS_Time_BAC, &data.TBOX_BJS_Time_Sec))
            {
                isSuccess = FALSE;
            }
            if (isSuccess == TRUE)
            {
                if (isSuccess == TRUE)
                {
                    rte_memcpy((uint8*)&Rte_Buf_Runbl_IpmCanRx_100ms_TBOX_BJS_Time_BAC_TBOX_BJS_Time_BAC,(uint8*)&data,sizeof(TBOX_BJS_Time_BAC));
                    Rte_Inst_AppSwcIpm.Runbl_IpmCanRx_100ms_TBOX_BJS_Time_BAC_TBOX_BJS_Time_BAC->status = RTE_E_OK;
                }
            }
        }
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_COMCbk_VCU_1_InvCmd_EPT_IPDU_COM_VCU_1_InvCmd_EPT
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
void Rte_COMCbk_VCU_1_InvCmd_EPT_IPDU_COM_VCU_1_InvCmd_EPT(void)
{
    if (RteInitState == RTE_INITED)
    {
    }
    if((IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P10) == 1) || (IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,IOEXP_TCA9539_P11) == 1))
    {
    Dem_UdsStatusByteType tmp = 0;
	if (E_OK == Dem_GetEventStatus(DemEventParameter_0xD10887, &tmp))
	{
		if (DEM_UDS_STATUS_TF == (tmp & DEM_UDS_STATUS_TF))
		{
			Dem_SetEventStatus(DemEventParameter_0xD10887, DEM_EVENT_STATUS_PASSED);
		}
	}
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

