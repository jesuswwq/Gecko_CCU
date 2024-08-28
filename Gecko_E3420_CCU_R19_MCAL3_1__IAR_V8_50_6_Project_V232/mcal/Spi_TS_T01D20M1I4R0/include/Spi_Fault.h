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
 *  \file     Spi_Fault.h                                                                               *
 *  \brief    This file contains interface header for SPI Fault injection.                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/15     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef SPI_FAULT_H
#define SPI_FAULT_H

#ifdef __cplusplus
extern "C" {
#endif
/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/
/** \brief  SPI fault injection switch */
#ifndef SPI_FAULT_INJECTION
#define SPI_FAULT_INJECTION                                              (STD_OFF)
#endif

#if (SPI_FAULT_INJECTION == STD_OFF)

/** \brief  FUNCTION:Spi_Ip_Init() fault injection. */
#define SpiFaultInj_Spi_Ip_Init()
/** \brief  FUNCTION:Spi_Ip_DmaHandle() fault injection. */
#define SpiFaultInj_Spi_Ip_DmaHandleDmaStatusErr()
/** \brief  FUNCTION:Spi_Ip_DmaHandle() fault injection. */
#define SpiFaultInj_Spi_Ip_DmaHandleRxLenthErr()
/** \brief  FUNCTION:Spi_Ip_DmaHandle() fault injection. */
#define SpiFaultInj_Spi_Ip_DmaHandleTxLenthErr()
/** \brief  FUNCTION:Spi_Ip_VectorModeTransmissionCore() fault injection. */
#define SpiFaultInj_Spi_Ip_VectorModeTransmissionCoreSoftCSTimeOut()
/** \brief  FUNCTION:Spi_Ip_VectorModeTransmissionCore() fault injection. */
#define SpiFaultInj_Spi_Ip_VectorModeTransmissionCoreReadTooMuch()
/** \brief  FUNCTION:SpiFaultInj_Spi_Ip_ConfigDmaChannel() fault injection. */
#define SpiFaultInj_Spi_Ip_ConfigDmaChannelErr()

#else
#include "Spi_UserFault.h"
#endif /* #if (SPI_FAULT_INJECTION == STD_OFF) */

#ifdef __cplusplus
}
#endif

#endif /* SPI_FAULT_H */
/* End of file */
