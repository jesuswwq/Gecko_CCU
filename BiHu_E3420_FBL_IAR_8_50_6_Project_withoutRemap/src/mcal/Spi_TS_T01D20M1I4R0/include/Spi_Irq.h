/*
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
 * an "AS IS" basis, WITHOUT WARRANTIES OF ANY KIND, either express or implied.
 *
 * You should have received a copy of the License along with this program.
 * If not, see <http://www.semidrive.com/licenses/>.
 */

/**
 * @file  Spi_Irq.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Spi plugins.
 */

#ifndef SPI_IRQ_H
#define SPI_IRQ_H

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Release version information */
#define SPI_DRIVER_AR_RELEASE_MAJOR_VERSION SPI_AR_RELEASE_MAJOR_VERSION
#define SPI_DRIVER_AR_RELEASE_MINOR_VERSION SPI_AR_RELEASE_MINOR_VERSION
#define SPI_DRIVER_AR_RELEASE_REVISION_VERSION SPI_AR_RELEASE_REVISION_VERSION

/* File version information */
#define SPI_DRIVER_SW_MAJOR_VERSION SPI_SW_MAJOR_VERSION
#define SPI_DRIVER_SW_MINOR_VERSION SPI_SW_MINOR_VERSION

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#if ( SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || ( SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
extern void Spi1_IrqHandler(void);
extern void Spi2_IrqHandler(void);
extern void Spi3_IrqHandler(void);
extern void Spi4_IrqHandler(void);
extern void Spi5_IrqHandler(void);
extern void Spi6_IrqHandler(void);
extern void Spi7_IrqHandler(void);
extern void Spi8_IrqHandler(void);
#endif

#ifdef __cplusplus
}
#endif

#endif /* SPI_IRQs_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
