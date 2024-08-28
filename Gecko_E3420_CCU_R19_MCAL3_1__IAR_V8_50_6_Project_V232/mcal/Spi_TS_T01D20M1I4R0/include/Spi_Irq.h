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
 *  \file     Spi_Irq.h
 *  \brief    This file contains interface header for CAN MCAL driver
 *
 * <table>
 * <tr><th>Date           <th>Version
 * <tr><td>2023/07/27     <td>1.0.0
 * </table>
 *****************************************************************************************/

#ifndef SPI_IRQ_H
#define SPI_IRQ_H

#ifdef __cplusplus
extern "C" {
#endif
/**
 *  \defgroup MCAL_SPI SPI Driver MLD API
 *
 *  The SPI Handler/Driver provides services for reading from and writing to devices
 *  connected via SPI busses.
 *
 *  This spi driver provide only master mode transmission via chip spi controllers
 *  depend on user configurations <br>
 *  This module relevanto to dam module in dma mode, too short transmission dma mode
 *  is not recommended.<br>
 *  \sa MCAL_SPI_MLD_CFG
 *  \sa MCAL_SPI_API
 *  \sa MCAL_SPI_MACRO
 */
/** \{ */

/*****************************************************************************************
 *                       Include header files
 *****************************************************************************************/
#include "Spi.h"
#include "Mcal.h"
#include "Spi_Cfg.h"
#include "Std_Types.h"
/**
 *  \defgroup MCAL_SPI_CFG SPI Configuration.
 *
 * This files defines SPI MCAL configuration structures
 *  \{
 */

/** \} */

/**
 *  \defgroup MCAL_SPI_API SPI Api.
 *
 * This files defines SPI MCAL api
 *  \{
 */

/** \} */

/**
 *  \defgroup MCAL_SPI_MACRO SPI macro.
 *
 * This files defines SPI MCAL macro
 *  \{
 */

/** \} */

/**
 *  \addtogroup MCAL_SPI_MACRO SPI macro.
 *  \{
 */
/** \brief  AUTOSAR Release version information */
#define SPI_DRIVER_AR_RELEASE_MAJOR_VERSION SPI_AR_RELEASE_MAJOR_VERSION
#define SPI_DRIVER_AR_RELEASE_MINOR_VERSION SPI_AR_RELEASE_MINOR_VERSION
#define SPI_DRIVER_AR_RELEASE_REVISION_VERSION SPI_AR_RELEASE_REVISION_VERSION

/** \brief  File version information */
#define SPI_DRIVER_SW_MAJOR_VERSION SPI_SW_MAJOR_VERSION
#define SPI_DRIVER_SW_MINOR_VERSION SPI_SW_MINOR_VERSION
/** \} */

/**
 *  \addtogroup MCAL_SPI_API SPI Api.
 *  \{
 */

/*****************************************************************************************
 *                                  Private Function Declarations
 *****************************************************************************************/
#if ( SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || ( SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
/** **************************************************************************************
 * \brief This function handle the spi instance interrupt.
 *
 * \verbatim
 * Syntax             : ISR(Spi1_IrqHandler)
 *
 * Service ID[hex]    : 0x00
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The irq handler of spi1.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_237 SWSR_SPI_256
 *****************************************************************************************/
ISR(Spi1_IrqHandler);
/** **************************************************************************************
 * \brief This function handle the spi instance interrupt.
 *
 * \verbatim
 * Syntax             : ISR(Spi2_IrqHandler)
 *
 * Service ID[hex]    : 0x00
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The irq handler of spi2.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_237 SWSR_SPI_256
 *****************************************************************************************/
ISR(Spi2_IrqHandler);
/** **************************************************************************************
 * \brief This function handle the spi instance interrupt.
 *
 * \verbatim
 * Syntax             : ISR(Spi3_IrqHandler)
 *
 * Service ID[hex]    : 0x00
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The irq handler of spi3.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_237 SWSR_SPI_256
 *****************************************************************************************/
ISR(Spi3_IrqHandler);
/** **************************************************************************************
 * \brief This function handle the spi instance interrupt.
 *
 * \verbatim
 * Syntax             : ISR(Spi4_IrqHandler)
 *
 * Service ID[hex]    : 0x00
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The irq handler of spi4.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_237 SWSR_SPI_256
 *****************************************************************************************/
ISR(Spi4_IrqHandler);
/** **************************************************************************************
 * \brief This function handle the spi instance interrupt.
 *
 * \verbatim
 * Syntax             : ISR(Spi5_IrqHandler)
 *
 * Service ID[hex]    : 0x00
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The irq handler of spi5.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_237 SWSR_SPI_256
 *****************************************************************************************/
ISR(Spi5_IrqHandler);
/** **************************************************************************************
 * \brief This function handle the spi instance interrupt.
 *
 * \verbatim
 * Syntax             : ISR(Spi6_IrqHandler)
 *
 * Service ID[hex]    : 0x00
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The irq handler of spi6.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_237 SWSR_SPI_256
 *****************************************************************************************/
ISR(Spi6_IrqHandler);
#ifdef SEMIDRIVE_E3_SERIES
/** **************************************************************************************
 * \brief This function handle the spi instance interrupt.
 *
 * \verbatim
 * Syntax             : ISR(Spi7_IrqHandler)
 *
 * Service ID[hex]    : 0x00
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The irq handler of spi7.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_237 SWSR_SPI_256
 *****************************************************************************************/
ISR(Spi7_IrqHandler);
/** **************************************************************************************
 * \brief This function handle the spi instance interrupt.
 *
 * \verbatim
 * Syntax             : ISR(Spi8_IrqHandler)
 *
 * Service ID[hex]    : 0x00
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The irq handler of spi8.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_237 SWSR_SPI_256
 *****************************************************************************************/
ISR(Spi8_IrqHandler);
#endif
#endif
/** \} */

#ifdef __cplusplus
}
#endif

/** \} */

#endif /* SPI_IRQs_H */
/* End of file */

