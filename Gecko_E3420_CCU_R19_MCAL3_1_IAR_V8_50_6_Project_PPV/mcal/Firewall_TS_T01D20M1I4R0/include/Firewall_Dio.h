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
 *  \file     Firewall_Dio.h                                                                            *
 * \brief    This file contains interface header for Firewall DIO MCAL driver                           *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/25     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifndef FIREWALL_DIO_H
#define FIREWALL_DIO_H

#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Firewall_Type.h"

/** *****************************************************************************************************
 * \brief This function Configure the dio rule space and perimissions.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Firewall_DioRuleSpaceConfigure
 *                      (
 *                          const Firewall_DioCoreCfgType *dioCoreCfgPtr,
 *                          uint8 coreNum,
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : No reentrant
 *
 * Parameters (in)    : dioCoreCfgPtr - The pointer to the dio cores' configuration
 *                      coreNum - The number of the core configurations
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Configure the dio rule space and perimissions success.
 *                      FIREWALL_E_NULL_POINTER: The pointer is a NULL_PTR.
 *                      FIREWALL_E_DIO_CORE_NUM: The number of the core configurations is unvalid.
 *
 * Description        : This function Configure the dio rule space and perimissions.
 *                      This function should be called only once.
 *
 * \endverbatim
 * Traceability       : SWSR_FIREWALL_008 SWSR_FIREWALL_016 SWSR_FIREWALL_018 SM006
 *******************************************************************************************************/
Std_ReturnType Firewall_DioRuleSpaceConfigure(const Firewall_DioCoreCfgType *dioCoreCfgPtr, uint8 coreNum);

#ifdef __cplusplus
}
#endif

#endif /* FIREWALL_DIO_H */
/* End of file */
