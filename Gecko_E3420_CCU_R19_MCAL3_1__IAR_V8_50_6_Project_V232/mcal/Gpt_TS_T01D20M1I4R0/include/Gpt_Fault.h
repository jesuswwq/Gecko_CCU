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
 *  \file     Gpt_Fault.h                                                                               *
 *  \brief    This file contains interface header for GPT Fault injection.                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/15     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef GPT_FAULT_H
#define GPT_FAULT_H

#ifdef __cplusplus
extern "C" {
#endif
/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/

#ifndef GPT_FAULT_INJECTION
/** \brief  FUNCTION:Irq_handler fault injection. */
#define GptHookBegin_Gpt_UnexpectedInterruption()
#define GptHookEnd_Gpt_UnexpectedInterruption()
#define GptHookBegin_Gpt_InitUnexpectedInterruption()
#define GptHookEnd_Gpt_InitUnexpectedInterruption()
#else
#include "Gpt_UserFault.h"
#endif /* #ifndef GPT_FAULT_INJECTION */

#ifdef __cplusplus
}
#endif

#endif /* GPT_FAULT_H */
/* End of file */
