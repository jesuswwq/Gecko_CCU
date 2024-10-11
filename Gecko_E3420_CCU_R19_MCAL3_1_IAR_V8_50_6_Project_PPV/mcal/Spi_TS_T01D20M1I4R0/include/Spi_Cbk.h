/** **************************************************************************************
 * SEMIDRIVE Copyright Statement
 * Copyright (c) SEMIDRIVE. All rights reserved
 *
 * This software and all rights therein are owned by SEMIDRIVE, and are
 * protected by copyright law and other relevant laws, regulations and
 * protection. Without SEMIDRIVE's prior written consent and/or related rights,
 * please do not use this software or any potion thereof in any form or by any
 * means. You may not reproduce, modify or distribute this software except in
 * compliance with the License. Unless required by applicable law or agreed to
 * in writing, software distributed under the License is distributed on
 * an 'AS IS' basis, WITHOUT WARRANTIES OF ANY KIND, either express or implied.
 *
 *****************************************************************************************/
/** **************************************************************************************
 *  \file     Spi_Cbk.h
 *  \brief    This file contains interface header for CAN MCAL driver
 *
 * <table>
 * <tr><th>Date           <th>Version
 * <tr><td>2023/07/27     <td>1.0.0
 * </table>
 *****************************************************************************************/

#ifndef SPI_CBK_H
#define SPI_CBK_H

/**
 *  \defgroup MCAL_SPI SPI Driver Type defines.
 *
 *  The SPI Handler/Driver provides services for reading from and writing to devices
 *  connected via SPI busses.
 *
 *  This spi driver provide only master mode transmission via chip spi controllers
 *  depend on user configurations <br>
 *  This module relevanto to dam module in dma mode, too short transmission dma mode
 *  is not recommended.<br>
 *  \sa MCAL_SPI_CFG
 */
/** \{ */

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************************
 *                       Include header files
 *****************************************************************************************/
/* AUTOSAR standard types */
#include "Std_Types.h"
/**
 *  \defgroup MCAL_SPI_CFG SPI types defines.
 *
 * This files defines SPI MCAL configuration structures
 *  \{
 */
/** \} */

/**
 *  \addtogroup MCAL_SPI_CFG SPI types defines.
 *  \{
 */
/*****************************************************************************************
 *                            Global Types definition
 *****************************************************************************************/
/** \brief  typedef for job end notification function pointer */
/** Traceability       : SWSR_SPI_245 SWSR_SPI_248 SWSR_SPI_249 SWSR_SPI_244 */
typedef void (*Spi_JobEndNotifyType)(void);

/* typedef for sequence end notification function pointer */
/** Traceability       : SWSR_SPI_245 SWSR_SPI_252 SWSR_SPI_244 */
typedef void (*Spi_SeqEndNotifyType)(void);

/** \} */

#ifdef __cplusplus
}
#endif

/** \} */

#endif /** SPI_TYPES_H */
/** End of file */
