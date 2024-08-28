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
 *  \file     Mcu_PllDrv.h                                                                           *
 *  \brief    This file contains interface header for MCU MCAL driver, ...                             *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/02     <td>1.0.0                               *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef MCU_PLLDRV_H
#define MCU_PLLDRV_H

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Mcu_Pll.h"
#include "Mcu_GeneralTypes.h"
/********************************************************************************************************
 *                                  Global Types definition                                             *
 *******************************************************************************************************/

typedef struct
{
    Mcu_ClkNodeType clkNode;
} Mcu_PllNodeType;

extern const struct Mcu_PreClkOpsType Mcu_PllOps;
/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
Std_ReturnType Mcu_Ip_PllDrvConfigSpread(const Mcu_PllSpreadConfigType *pllConfigPtr);

#endif /* MCU_PLLDRV_H */
/* End of file */
