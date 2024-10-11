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
 * \file     Mcu_CkgenDrv.h                                                                            *
 * \brief    AUTOSAR 4.3.1 MCAL Mcu Driver                                                             *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/02     <td>1.0.0                               *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef MCU_CKGENDRV_H
#define MCU_CKGENDRV_H
/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Mcu_GeneralTypes.h"
/********************************************************************************************************
 *                                  Global Types definition                                             *
 *******************************************************************************************************/
typedef struct
{
    Mcu_ClkNodeType clkNode;
} Mcu_CkgenNodeType;

typedef struct
{
    Mcu_ClkNodeType clkNode;
    boolean runModeEn;
    boolean slpModeEn;
    boolean hibModeEn;
} Mcu_CgNodeType;

extern const struct Mcu_PreClkOpsType Mcu_ClkIpOps;

extern const struct Mcu_PreClkOpsType Mcu_ClkBusOps;

extern const struct Mcu_PreClkOpsType Mcu_ClkCoreOps;

extern const struct Mcu_PreClkOpsType Mcu_ClkGatingOps;
/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
#ifdef CONFIG_CLK_MONITOR
Std_ReturnType Mcu_Ip_CkgenClockToPad(Mcu_ClkNodeType *ckgenPtr, uint8 divNum);
#endif /** #ifdef CONFIG_CLK_MONITOR*/
/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/
#define CLK_NODE(node) (&((node).clkNode))

#endif /* MCU_CKGENDRV_H */
/* End of file */
