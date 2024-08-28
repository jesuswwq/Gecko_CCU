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
 *  \file     Dio_Cfg.c                                                                                 *
 *  \brief    AUTOSAR 4.3.1 MCAL DIO config                                                             *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date                 <th>Version                                                             *
 * <tr><td>2024-03-08 16:29:00      <td>1.0.0 R                                            *
 * </table>                                                                                             *
 *******************************************************************************************************/

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Dio.h"

#define DIO_START_SEC_CONST_UNSPECIFIED
#include "Dio_MemMap.h"


#define DIO_STOP_SEC_CONST_UNSPECIFIED
#include "Dio_MemMap.h"


#define DIO_START_SEC_VAR_INIT_UNSPECIFIED
#include "Dio_MemMap.h"

/*PRQA S 1533  4*/
/**
 * Traceability       : SWSR_DIO_074
 */
void (*Dio_InterruptNotification)(Dio_ChannelType channelId) = NULL_PTR;

#define DIO_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Dio_MemMap.h"

/* End of file */
