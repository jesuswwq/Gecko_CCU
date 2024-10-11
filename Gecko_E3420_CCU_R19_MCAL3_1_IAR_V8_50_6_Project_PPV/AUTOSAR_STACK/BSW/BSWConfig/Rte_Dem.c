/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_Dem.c>
 *  @brief      <>
 *  
 *  <MCU:E3420>
 *  
 *  @author     <>
 *  @date       <2023-12-19 13:18:44>
 */
/*============================================================================*/

#include "Rte_Dem.h"
#include "Dem_Internal.h"
#define DEM_UNUSED(a) (void)(a)
uint8 ICU_ICUTotalOdometer[3]={0x00};
uint8 ESC_VehicleSpeed[2]={0x00};
Std_ReturnType  Rte_ReadGear( uint8* Buffer )
{
    DEM_UNUSED(Buffer);
    *Buffer = VGSM_VehActGearPstn_enum;
    return E_OK;
}
Std_ReturnType  Rte_AgedCounter( uint8* Buffer )
{
    DEM_UNUSED(Buffer);
    *Buffer = DemInternalData.AgedCounter;
    return E_OK;
}
Std_ReturnType  Rte_ReadPowerMode( uint8* Buffer )
{
    DEM_UNUSED(Buffer);
    *Buffer = VOPM_BCMSysPwrMode_enum;
    return E_OK;
}
Std_ReturnType  Rte_ReadSpeed( uint8* Buffer )
{
    DEM_UNUSED(Buffer);
    Buffer[0] =  Buffer_DcmDspData_0xF201H[0];
    Buffer[1] =  Buffer_DcmDspData_0xF201H[1]; 
    return E_OK;
}
Std_ReturnType  Rte_ReadPowerVoltage( uint8* Buffer )
{
    DEM_UNUSED(Buffer);
    uint16 BatteryVoltage = GetHw_LowBatValtage();
    *Buffer =(uint8) (BatteryVoltage/100);
    return E_OK;
}
Std_ReturnType  Rte_ReadBjsTime( uint8* Buffer )
{
    DEM_UNUSED(Buffer);
    Buffer[0] =  UDS_TBOX_BJS_Time_Year;
    Buffer[1] =  UDS_TBOX_BJS_Time_Month;
    Buffer[2] =  UDS_TBOX_BJS_Time_Day;
    Buffer[3] =  UDS_TBOX_BJS_Time_Hour;
    Buffer[4] =  UDS_TBOX_BJS_Time_Min;
    Buffer[5] =  UDS_TBOX_BJS_Time_Sec;
    return E_OK;
}
Std_ReturnType  Rte_ReadOdometerOfMalfunction( uint8* Buffer )
{
    DEM_UNUSED(Buffer);
    Buffer[0] = ICU_ICUTotalOdometer[0];
    Buffer[1] = ICU_ICUTotalOdometer[1];
    Buffer[2] = ICU_ICUTotalOdometer[2];
    return E_OK;
}
Std_ReturnType  Rte_ReadOperateMode( uint8* Buffer )
{
    DEM_UNUSED(Buffer);
    *Buffer = VHVM_PTActOprtMode_enum;
    return E_OK;
}