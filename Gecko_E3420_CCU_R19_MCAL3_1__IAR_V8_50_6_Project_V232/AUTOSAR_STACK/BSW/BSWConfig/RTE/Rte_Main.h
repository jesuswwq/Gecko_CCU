/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_Main.h>
 *  @brief      <>
 *  
 *  <MCU:E3420>
 *  
 *  @author     <>
 *  @date       <2024-07-16 14:42:52>
 */
/*============================================================================*/

/* Rte_Main.h */

#ifndef RTE_MAIN_H
#define RTE_MAIN_H

/*******************************************************************************
 **                        Revision Control History                           **
******************************************************************************/

/*******************************************************************************
 **                        Version Information                                **
******************************************************************************/

/*******************************************************************************
 **                        Include Section                                    **
******************************************************************************/

#ifdef __cplusplus
extern "C" {

#endif
#include "Rte.h"

Std_ReturnType Rte_Start(void);
Std_ReturnType Rte_Stop(void);
void Os_TaskEntry_Rte_OsTask_Core0_Init(void);
void Os_TaskEntry_Rte_OsTask__Core0_100ms(void);
void Os_TaskEntry_Rte_OsTask__Core0_10ms(void);
void Os_TaskEntry_Rte_OsTask__Core0_20ms(void);
void Os_TaskEntry_Rte_OsTask__Core0_50ms(void);

#ifdef __cplusplus
}
#endif

#endif

