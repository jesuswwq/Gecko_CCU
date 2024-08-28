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
 *  \file     Fls_Fault.h                                                                               *
 *  \brief    This file contains interface header for FLS Fault injection.                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/15     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef FLS_FAULT_H
#define FLS_FAULT_H

#ifdef __cplusplus
extern "C" {
#endif
/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/

#ifndef FLS_FAULT_INJECTION
/** \brief  FUNCTION:Trans fault injection. */
#define FlsHookError_Fls_IpErase()
#define FlsHookError_Fls_HyperBusErase()
#define FlsHookError_Fls_IpRead()
#define FlsHookError_Fls_IpWrite()
#else
#include "Fls_UserFault.h"
#endif /* #ifndef FLS_FAULT_INJECTION */

#ifdef __cplusplus
}
#endif

#endif /* FLS_FAULT_H */
/* End of file */
