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
 *  \file     Xtrg_Fault.h                                                                               *
 *  \brief    This file contains interface header for XTRG Fault injection.                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/15     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef XTRG_FAULT_H
#define XTRG_FAULT_H

#ifdef __cplusplus
extern "C" {
#endif
/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/
/** \brief  XTRG fault injection switch */
#ifndef XTRG_FAULT_INJECTION
#define XTRG_FAULT_INJECTION                                              (STD_OFF)
#endif

#if (XTRG_FAULT_INJECTION == STD_OFF)
/** \brief  FUNCTION:Xtrg_Ip_SoftwareTriggerTimeOut() fault injection software trigger timeout. */
#define XtrgFaultInj_Xtrg_Ip_SoftwareTriggerTimeOut()
/** \brief  FUNCTION:Xtrg_InterruptHandleNoMatch() fault injection interrupt error. */
#define XtrgFaultInj_Xtrg_InterruptHandleNoMatch()
/** \brief  FUNCTION:Xtrg_InterruptHandleNoMatch() fault injection record error status. */
#define XtrgFaultInj_XtrgFaultIntErrorStatus();

#else
#include "Xtrg_UserFault.h"
extern volatile Xtrg_ErrorIdType Xtrg_IntErrorStatus;
#endif /* #if (ADC_FAULT_INJECTION == STD_OFF) */

#ifdef __cplusplus
}
#endif

#endif /* XTRG_FAULT_H */
/* End of file */
