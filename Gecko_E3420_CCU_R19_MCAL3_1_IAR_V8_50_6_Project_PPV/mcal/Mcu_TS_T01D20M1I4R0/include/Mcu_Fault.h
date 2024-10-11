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
 *  \file     Mcu_Fault.h                                                                               *
 *  \brief    This file contains interface header for Mcu MCAL driver, ...                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/09/13     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef MCU_FAULT_H
#define MCU_FAULT_H


#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Std_Types.h"

/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/
#ifndef MCU_FAULT_INJECTION
/** \brief  FUNCTION:Mcu_EnterCheck() fault injection. */
#define McuHookBegin_Mcu_EnterCheck()
#define McuHookEnd_Mcu_EnterCheck()
/** \brief  FUNCTION:Mcu_AnalogTrimVd() fault injection. */
#define McuHookBegin_Mcu_AnalogTrimVd()
#define McuHookEnd_Mcu_AnalogTrimVd()
/** \brief  FUNCTION:Mcu_AteAnalogTrimVd() fault injection. */
#define McuHookBegin_Mcu_AteAnalogTrimVd()
#define McuHookEnd_Mcu_AteAnalogTrimVd()

#else
#include "Mcu_UserFault.h"
#endif /* #ifndef MCU_FAULT_INJECTION */
#ifdef __cplusplus
}
#endif

#endif /* MCU_FAULT_H */
/* End of file */
