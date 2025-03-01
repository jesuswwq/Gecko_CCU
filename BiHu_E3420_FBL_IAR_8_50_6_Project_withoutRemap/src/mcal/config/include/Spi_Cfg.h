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
 * @file Spi_Cfg.h
 * @brief AutoSAR SPI configuration header file
 * @details Automatically generated by user settings
 * @date 2023-09-21 19:24:34
 */

#ifndef SPI_CFG_H
#define SPI_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Mcu_Cfg.h"
#define SPI_MAX_CORES MAX_CORE_NUM
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#define SPI_AR_RELEASE_MAJOR_VERSION_VALUE 4U
#define SPI_AR_RELEASE_MINOR_VERSION_VALUE 3U
#define SPI_AR_RELEASE_REVISION_VERSION_VALUE 1U

#define SPI_SW_MAJOR_VERSION_VALUE  1U
#define SPI_SW_MINOR_VERSION_VALUE  0U
#define SPI_SW_PATCH_VERSION_VALUE  0U

/* Instance ID of the SPI SpiDriver*/
#define SPI_INSTANCE_ID_VALUE 0U

#define SPI_VENDOR_ID_VALUE 0x8C
#define SPI_MODULE_ID_VALUE 83U

/* Priority level */
#define SPI_PRIORITY_LEVEL 0x80U

/* Number of Spi Drivers configured */
#define SPI_TOTAL_DRIVERS                     1U
/* Total Number of HW units configured*/
#define SPI_TOTAL_HW_COUNT      8U
/* Total Number of SpiChannel configured */
#define SPI_TOTAL_CH_COUNT	1U
/*  Total Number of SpiJob configured */
#define SPI_TOTAL_JOB_COUNT	1U
/* Total  Number of SpiSequence configured */
#define SPI_TOTAL_SEQ_COUNT	1U
/* Total  Number of device configured */
#define SPI_TOTAL_DEV_COUNT	SPI_TOTAL_JOB_COUNT

#define SPI_MAX_CHANNEL     SPI_TOTAL_CH_COUNT
#define SPI_MAX_JOB         SPI_TOTAL_JOB_COUNT
#define SPI_MAX_SEQUENCE    SPI_TOTAL_SEQ_COUNT

/*Reference to configured DEM event to report "Hardware failure". If the reference is not configured the error shall not be reported.*/
#define SPI_E_HARDWARE_ERROR (STD_OFF)


#define SPI_ENABLE_SLAVE STD_OFF


#define SPI_ENABLE_DMA  STD_OFF

#if (SPI_ENABLE_DMA == STD_ON)
#define SPI_BUFF_ALIGN_LEN 32
#else
#define SPI_BUFF_ALIGN_LEN 4
#endif

#if (SPI_ENABLE_DMA == STD_ON)
#define BUFF_SIZE_ROUNDUP_LEN 32
#else
#define BUFF_SIZE_ROUNDUP_LEN 1
#endif

/*Switches the Spi_Cancel function ON or OFF.*/
#define	SPI_CANCEL_API	(STD_ON)

/* Specifies whether concurrent Spi_SyncTransmit() is supported */
#define SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT  (STD_ON)

/* Selects the SPI Handler/Driver Channel Buffers usage allowed and
*delivered.
*IB = 0; EB = 1; IB/EB = 2;
*/
#define SPI_CHANNEL_BUFFERS_ALLOWED 0x2U

/* Switches the development error detection and notification on or off. */
#define SPI_DEV_ERROR_DETECT  (STD_ON)

/* Switches the Spi_GetHWUnitStatus function ON or OFF. */
#define SPI_HW_STATUS_API  (STD_ON)

/* Switches the Interruptible Sequences handling functionality ON or OFF. */
#define SPI_INTERRUPTIBLE_SEQ_ALLOWED  (STD_ON)

/* Selects the SPI Handler/Driver level of scalable functionality that is available and delivered. */
#define SPI_LEVEL_DELIVERED SPI_LEVEL_2

/* This parameter defines the cycle time of the function Spi_MainFunction_Handling in seconds. The parameter is not used by the driver it self, but it is used by upper layer. */
#define SPI_MAIN_FUNCTIONPERIOD	(0.01)


/*Configuration: SPI_VERSION_INFO_API
- if STD_ON, Function Spi_GetVersionInfo is available
- if STD_OFF,Function Spi_GetVersionInfo is not available
*/
#define SPI_VERSION_INFO_API	(STD_ON)

#define ENABLE_SLAVE_MCS_TRIG	(STD_OFF)



/*Switches the Spi single core function ON or OFF.*/
#define	SPI_SINGLE_CORE_HANDLER	(STD_ON)
#define	SPI_SINGLE_CORE_ID	        0

/*Switches the Spi single core function ON or OFF.*/
#define	SPI_CFG_CORES	(1U)


/* Handle for configured SpiChannel */
#define SpiConf_SpiChannel_SpiChannel_TJA1145  ((Spi_ChannelType)0U)


/* Handle for configured SpiJob */
#define SpiConf_SpiJob_SpiJob_TJA1145  ((Spi_JobType)0U)

/* Handle for configured SpiSequence */
#define SpiConf_SpiSequence_SpiSequence_TJA1145  ((Spi_SequenceType)0U)


/* Handles for external  HW unit USED  */
#define CSIB1 ((Spi_HWUnitType)0U)
#define CSIB2 ((Spi_HWUnitType)1U)
#define CSIB3 ((Spi_HWUnitType)2U)
#define CSIB4 ((Spi_HWUnitType)3U)
#define CSIB5 ((Spi_HWUnitType)4U)
#define CSIB6 ((Spi_HWUnitType)5U)
#define CSIB7 ((Spi_HWUnitType)6U)
#define CSIB8 ((Spi_HWUnitType)7U)
/* Handles for Chip Select(Slave select) allocated to the Job*/
/* 16 slave select pins are available */
#define SPI_CS_0 (0U)
#define SPI_CS_1 (1U)
#define SPI_CS_2 (2U)
#define SPI_CS_3 (3U)


/* write buffers size*/
#define SPI_BUFFER_SIZE_CHANNEL_0  (8U)

/* Switche to enable or disable Hardware loop back . */
#define SPI_HW_LOOPBACK STD_ON
#ifdef __cplusplus
}
#endif

#endif  /* SPI_CFG_H */

/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/
