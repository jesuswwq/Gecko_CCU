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
 * @file Spi_PbCfg.h
 * @brief AutoSAR SPI configuration header file
 * @details Automatically generated by user settings
 * @date 2023-09-21 19:24:34
 */


#ifndef SPI_PBCFG_H_INCLUDED
#define SPI_PBCFG_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Spi_Types.h"

extern CONST(Spi_ConfigType, SPI_CONST) Spi_Config[SPI_TOTAL_DRIVERS];
extern CONST(Spi_ChannelCfgType, SPI_CONST) Spi_ChannelConfig[SPI_TOTAL_CH_COUNT];
extern CONST(Spi_JobCfgType, SPI_CONST) Spi_JobConfig[SPI_TOTAL_JOB_COUNT];
extern CONST(Spi_SequenceCfgType, SPI_CONST) Spi_SequenceConfig[SPI_TOTAL_SEQ_COUNT];
extern CONST(Spi_HwUnitConfigType, SPI_CONST) Spi_HwUnitConfig[SPI_TOTAL_HW_COUNT];
extern CONST(uint8, SPI_CONST) Spi_InstanceMask_Config[5];

#ifdef __cplusplus
}
#endif

#endif /*!defined(SPI_PBCFG_H_INCLUDED)*/

/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/
