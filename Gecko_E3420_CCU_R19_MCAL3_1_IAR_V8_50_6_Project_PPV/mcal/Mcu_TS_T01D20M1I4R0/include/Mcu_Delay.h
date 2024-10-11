/** *****************************************************************************************************
 * SEMIDRIVE Copyright Statement                                                                        *
 * Copyright (c) SEMIDRIVE. All rights reserved                                                         *
 *                                                                                                      *
 * This software and all rights therein are owned by SEMIDRIVE, and are                                 *
 * protected by copyright law and other relevant laws, regulations and                                  *
 * protection. Without SEMIDRIVE's prior written consent and/or related rights,                         *
 * please do not use this software or any potion thereof in any form or by any                          *
 * means. You may not reproduce, modify or distribute this software except in                           *
 * compliance with the License. Unless required by applicable law or agreed to                          *
 * in writing, software distributed under the License is distributed on                                 *
 * an 'AS IS' basis, WITHOUT WARRANTIES OF ANY KIND, either express or implied.                         *
 *                                                                                                      *
 *******************************************************************************************************/
/** *****************************************************************************************************
 *  \file     Mcu_Delay.h                                                                           *
 *  \brief    This file contains interface header for CAN MCAL driver, ...                             *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/02     <td>1.0.0                               *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef MCU_DELAY_H
#define MCU_DELAY_H

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Soc.h"

/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/
#define Mcu_Frequency          (Mcu_Ip_SocGetCoreFreq())

#define PMU_US_TO_TICK(us)      ((uint32)(((us) * (Mcu_Frequency/4000000U))/16U))

/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
uint32 read_pmccntr(void);
void Mcu_PmuCounterInit(void);
Std_ReturnType Mcu_udelay(uint32 us);
uint32 Mcu_UsToTicks(uint32 us);
uint32 Mcu_TicksToUs(uint32 ticks);


#endif /* MCU_DELAY_H */
/* End of file */
