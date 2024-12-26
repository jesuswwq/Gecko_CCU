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
 * @file  Spi_Cbk.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Spi plugins.
 */

#ifndef SPI_CBK_H
#define SPI_CBK_H

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
/* AUTOSAR standard types */
#include "Std_Types.h"

/* typedef for job end notification function pointer */
typedef P2FUNC( void, SPI_APPL_CODE, Spi_JobEndNotifyType )( void );

/* typedef for sequence end notification function pointer */
typedef P2FUNC( void, SPI_APPL_CODE, Spi_SeqEndNotifyType )( void );

#ifdef __cplusplus
}
#endif

#endif /* SPI_TYPES_H */
/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/
