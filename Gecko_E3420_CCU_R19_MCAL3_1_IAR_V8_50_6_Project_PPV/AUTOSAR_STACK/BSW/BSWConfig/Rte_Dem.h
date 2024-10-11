/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_Dem.h>
 *  @brief      <>
 *  
 *  <MCU:E3420>
 *  
 *  @author     <>
 *  @date       <2023-11-23 14:33:24>
 */
/*============================================================================*/

#ifndef RTEDEM_H
#define RTEDEM_H

#include "Dem_Types.h"
#include "NvM_Types.h"
extern  uint8  NvM_InitReadAll_Flag;
extern  uint8 volatile VGSM_VehActGearPstn_enum;
extern  uint8 volatile VOPM_BCMSysPwrMode_enum;
extern  uint8 volatile VHVM_PTActOprtMode_enum;
extern  uint8 ICU_ICUTotalOdometer[3];
extern  uint8 ESC_VehicleSpeed[2];
extern uint8 Buffer_DcmDspData_0xF201H[2];
extern  uint8 volatile UDS_TBOX_BJS_Time_Year;
extern  uint8 volatile UDS_TBOX_BJS_Time_Month;
extern  uint8 volatile UDS_TBOX_BJS_Time_Day;
extern  uint8 volatile UDS_TBOX_BJS_Time_Hour;
extern  uint8 volatile UDS_TBOX_BJS_Time_Min;
extern  uint8 volatile UDS_TBOX_BJS_Time_Sec;
extern Std_ReturnType  Rte_ReadGear( uint8* Buffer );
extern Std_ReturnType  Rte_AgedCounter( uint8* Buffer );
extern Std_ReturnType  Rte_ReadPowerMode( uint8* Buffer );
extern Std_ReturnType  Rte_ReadSpeed( uint8* Buffer );
extern Std_ReturnType  Rte_ReadPowerVoltage( uint8* Buffer );
extern Std_ReturnType  Rte_ReadBjsTime( uint8* Buffer );
extern Std_ReturnType  Rte_ReadOdometerOfMalfunction( uint8* Buffer );
extern Std_ReturnType  Rte_ReadOperateMode( uint8* Buffer );
#endif /*RTEDEM_H*/
