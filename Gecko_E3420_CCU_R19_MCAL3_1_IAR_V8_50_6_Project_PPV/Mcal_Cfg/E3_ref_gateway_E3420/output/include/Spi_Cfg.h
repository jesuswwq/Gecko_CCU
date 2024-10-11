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
 *  \file     Spi_Cfg.h
 *  \brief    This file contains interface header for CAN MCAL driver
 *
 * <table>
 * <tr><th>Date           <th>Version
 * <tr><td>2024-03-08 16:29:00     <td>1.0.0 R
 * </table>
 *****************************************************************************************/
#ifndef SPI_CFG_H
#define SPI_CFG_H

#ifdef __cplusplus
extern "C" {
#endif
/*****************************************************************************************
 *                   Global Macro definition
 *****************************************************************************************/
/** \brief AuToSar Version of the SpiDriver*/
#define SPI_AR_RELEASE_MAJOR_VERSION 4U
#define SPI_AR_RELEASE_MINOR_VERSION 3U
#define SPI_AR_RELEASE_REVISION_VERSION 1U
/** \brief SoftWare version of the SpiDriver*/
#define SPI_SW_MAJOR_VERSION  3U
#define SPI_SW_MINOR_VERSION  1U
#define SPI_SW_PATCH_VERSION  0U

/** \brief Instance ID of the SPI SpiDriver*/
#define SPI_INSTANCE_ID 0U

#define SPI_VENDOR_ID 0x8C
#define SPI_MODULE_ID 83U

/** \brief Spi module levels */
#define SPI_LEVEL_0 0u
#define SPI_LEVEL_1 1u
#define SPI_LEVEL_2 2u

/** \brief  Number of Spi Drivers configured */
#define SPI_TOTAL_DRIVERS       1U
/** \brief  Total Number of HW units configured */
/** Traceability       : SWSR_SPI_033 */
#define SPI_TOTAL_HW_COUNT      8U
/** \brief  Total Number of SpiChannel configured */
#define SPI_TOTAL_CH_COUNT	42U
/** \brief  Total Number of SpiJob configured */
#define SPI_TOTAL_JOB_COUNT	21U
/** \brief  Total  Number of SpiSequence configured */
#define SPI_TOTAL_SEQ_COUNT	15U
/** \brief  Total  Number of device configured */
#define SPI_TOTAL_DEV_COUNT	SPI_TOTAL_JOB_COUNT

#define SPI_MAX_CHANNEL     SPI_TOTAL_CH_COUNT
#define SPI_MAX_JOB         SPI_TOTAL_JOB_COUNT
#define SPI_MAX_SEQUENCE    SPI_TOTAL_SEQ_COUNT

/** \brief  Reference to configured DEM event to report "Hardware failure".
 * If the reference is not configured the error shall not be reported.*/
#define SPI_E_HARDWARE_ERROR (STD_OFF)
/** \brief  Dma enable or not */

#define SPI_ENABLE_DMA  STD_OFF
/** \brief  IB buffer align size */
#define SPI_BUFF_ALIGN_LEN 32U
/** \brief  IB buffer size roundup size */
#define BUFF_SIZE_ROUNDUP_LEN 32U
/** \brief  Switches the Spi_Cancel function ON or OFF.*/
#define	SPI_CANCEL_API	(STD_ON)
/** \brief  Specifies whether concurrent Spi_SyncTransmit() is supported */
#define SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT  (STD_ON)
/** \brief  Selects the SPI Handler/Driver Channel Buffers usage allowed and delivered.
*           IB = 0; EB = 1; IB/EB = 2;*/
#define SPI_CHANNEL_BUFFERS_ALLOWED 0x2U

/** \brief  Switches the development error detection and notification on or off. */
#define SPI_DEV_ERROR_DETECT  (STD_ON)
/** \brief Switches the Function Safety check and notification on or off. */
#define SPI_SAFETY_ENABLE  (STD_OFF)

/** \brief  Switches the Spi_GetHWUnitStatus function ON or OFF. */
#define SPI_HW_STATUS_API  (STD_ON)

/** \brief  Switches the Interruptible Sequences handling functionality ON or OFF. */
#define SPI_INTERRUPTIBLE_SEQ_ALLOWED  (STD_ON)

/** \brief  Selects the SPI Handler/Driver level of scalable functionality that is available and delivered. */
#define SPI_LEVEL_DELIVERED SPI_LEVEL_2

/** \brief  This parameter defines the cycle time of the function Spi_MainFunction_Handling in seconds. The parameter is not used by the driver it self, but it is used by upper layer. */
#define SPI_MAIN_FUNCTIONPERIOD	(0.01)


/** \brief  Configuration: SPI_VERSION_INFO_API
- if STD_ON, Function Spi_GetVersionInfo is available
- if STD_OFF,Function Spi_GetVersionInfo is not available
*/
#define SPI_VERSION_INFO_API	(STD_ON)
/** \brief  Configuration: SPI_NO_CACHEABLE_NEEDED
- if STD_ON, Spi driver will not include dcache maintain code.
- if STD_OFF,Spi driver will include dcache maintain code.
*/
#define SPI_NO_CACHEABLE_NEEDED	(STD_OFF)

/* ResourceManager has spi configurations */
/** \brief  core0 is enable spi */
#define SPI_CFG_ENABLE_CORE0 STD_ON
/** \brief  core1 is enable spi */
#define SPI_CFG_ENABLE_CORE1 STD_ON
/** \brief  core2 is not enable spi */
#define SPI_CFG_ENABLE_CORE2 STD_OFF
/** \brief  core3 is not enable spi */
#define SPI_CFG_ENABLE_CORE3 STD_OFF
/** \brief  core4 is not enable spi */
#define SPI_CFG_ENABLE_CORE4 STD_OFF
/** \brief  Handle for configured SpiChannel */
#define SpiConf_SpiChannel_SpiChannel_0  ((Spi_ChannelType)0U)
#define SpiConf_SpiChannel_SpiChannel_1  ((Spi_ChannelType)1U)
#define SpiConf_SpiChannel_SpiChannel_2  ((Spi_ChannelType)2U)
#define SpiConf_SpiChannel_SpiChannel_3  ((Spi_ChannelType)3U)
#define SpiConf_SpiChannel_SpiChannel_4  ((Spi_ChannelType)4U)
#define SpiConf_SpiChannel_SpiChannel_5  ((Spi_ChannelType)5U)
#define SpiConf_SpiChannel_SpiChannel_6  ((Spi_ChannelType)6U)
#define SpiConf_SpiChannel_SpiChannel_7  ((Spi_ChannelType)7U)
#define SpiConf_SpiChannel_SpiChannel_8  ((Spi_ChannelType)8U)
#define SpiConf_SpiChannel_SpiChannel_9  ((Spi_ChannelType)9U)
#define SpiConf_SpiChannel_SpiChannel_10  ((Spi_ChannelType)10U)
#define SpiConf_SpiChannel_SpiChannel_11  ((Spi_ChannelType)11U)
#define SpiConf_SpiChannel_SpiChannel_12  ((Spi_ChannelType)12U)
#define SpiConf_SpiChannel_SpiChannel_13  ((Spi_ChannelType)13U)
#define SpiConf_SpiChannel_SpiChannel_14  ((Spi_ChannelType)14U)
#define SpiConf_SpiChannel_SpiChannel_15  ((Spi_ChannelType)15U)
#define SpiConf_SpiChannel_SpiChannel_16  ((Spi_ChannelType)16U)
#define SpiConf_SpiChannel_SpiChannel_17  ((Spi_ChannelType)17U)
#define SpiConf_SpiChannel_SpiChannel_18  ((Spi_ChannelType)18U)
#define SpiConf_SpiChannel_SpiChannel_19  ((Spi_ChannelType)19U)
#define SpiConf_SpiChannel_SpiChannel_20  ((Spi_ChannelType)20U)
#define SpiConf_SpiChannel_SpiChannel_21  ((Spi_ChannelType)21U)
#define SpiConf_SpiChannel_SpiChannel_22  ((Spi_ChannelType)22U)
#define SpiConf_SpiChannel_SpiChannel_23  ((Spi_ChannelType)23U)
#define SpiConf_SpiChannel_SpiChannel_24  ((Spi_ChannelType)24U)
#define SpiConf_SpiChannel_SpiChannel_25  ((Spi_ChannelType)25U)
#define SpiConf_SpiChannel_SpiChannel_26  ((Spi_ChannelType)26U)
#define SpiConf_SpiChannel_SpiChannel_27  ((Spi_ChannelType)27U)
#define SpiConf_SpiChannel_SpiChannel_28  ((Spi_ChannelType)28U)
#define SpiConf_SpiChannel_SpiChannel_29  ((Spi_ChannelType)29U)
#define SpiConf_SpiChannel_SpiChannel_30  ((Spi_ChannelType)30U)
#define SpiConf_SpiChannel_SpiChannel_31  ((Spi_ChannelType)31U)
#define SpiConf_SpiChannel_SpiChannel_32  ((Spi_ChannelType)32U)
#define SpiConf_SpiChannel_SpiChannel_TLE75242A  ((Spi_ChannelType)33U)
#define SpiConf_SpiChannel_SpiChannel_TLE75242B  ((Spi_ChannelType)34U)
#define SpiConf_SpiChannel_SpiChannel_TLE75004  ((Spi_ChannelType)35U)
#define SpiConf_SpiChannel_SpiChannel_TLE8108EM  ((Spi_ChannelType)36U)
#define SpiConf_SpiChannel_SpiChannel_NCK2910  ((Spi_ChannelType)37U)
#define SpiConf_SpiChannel_SpiChannel_NJJ29C0B  ((Spi_ChannelType)38U)
#define SpiConf_SpiChannel_SpiChannel_TLE94103B  ((Spi_ChannelType)39U)
#define SpiConf_SpiChannel_SpiChannel_TLE94103A  ((Spi_ChannelType)40U)
#define SpiConf_SpiChannel_SpiChannel_ADAU1462  ((Spi_ChannelType)41U)


/** \brief  Handle for configured SpiJob */
#define SpiConf_SpiJob_SpiJob_0  ((Spi_JobType)0U)
#define SpiConf_SpiJob_SpiJob_1  ((Spi_JobType)1U)
#define SpiConf_SpiJob_SpiJob_2  ((Spi_JobType)2U)
#define SpiConf_SpiJob_SpiJob_3  ((Spi_JobType)3U)
#define SpiConf_SpiJob_SpiJob_4  ((Spi_JobType)4U)
#define SpiConf_SpiJob_SpiJob_5  ((Spi_JobType)5U)
#define SpiConf_SpiJob_SpiJob_6  ((Spi_JobType)6U)
#define SpiConf_SpiJob_SpiJob_7  ((Spi_JobType)7U)
#define SpiConf_SpiJob_SpiJob_8  ((Spi_JobType)8U)
#define SpiConf_SpiJob_SpiJob_9  ((Spi_JobType)9U)
#define SpiConf_SpiJob_SpiJob_slave  ((Spi_JobType)10U)
#define SpiConf_SpiJob_SpiJob_sbc  ((Spi_JobType)11U)
#define SpiConf_SpiJob_SpiJob_TLE75242A  ((Spi_JobType)12U)
#define SpiConf_SpiJob_SpiJob_TLE75242B  ((Spi_JobType)13U)
#define SpiConf_SpiJob_SpiJob_TLE75004  ((Spi_JobType)14U)
#define SpiConf_SpiJob_SpiJob_TLE8108EM  ((Spi_JobType)15U)
#define SpiConf_SpiJob_SpiJob_NCK2910  ((Spi_JobType)16U)
#define SpiConf_SpiJob_SpiJob_NJJ29C0B  ((Spi_JobType)17U)
#define SpiConf_SpiJob_SpiJob_TLE94103B  ((Spi_JobType)18U)
#define SpiConf_SpiJob_SpiJob_TLE94103A  ((Spi_JobType)19U)
#define SpiConf_SpiJob_SpiJob_ADAU1462  ((Spi_JobType)20U)

/** \brief  Handle for configured SpiSequence */
#define SpiConf_SpiSequence_SpiSequence_0  ((Spi_SequenceType)0U)
#define SpiConf_SpiSequence_SpiSequence_1  ((Spi_SequenceType)1U)
#define SpiConf_SpiSequence_SpiSequence_2  ((Spi_SequenceType)2U)
#define SpiConf_SpiSequence_SpiSequence_3  ((Spi_SequenceType)3U)
#define SpiConf_SpiSequence_SpiSequence_4  ((Spi_SequenceType)4U)
#define SpiConf_SpiSequence_SpiSequence_5  ((Spi_SequenceType)5U)
#define SpiConf_SpiSequence_SpiSequence_TLE75242A  ((Spi_SequenceType)6U)
#define SpiConf_SpiSequence_SpiSequence_TLE75242B  ((Spi_SequenceType)7U)
#define SpiConf_SpiSequence_SpiSequence_TLE75004  ((Spi_SequenceType)8U)
#define SpiConf_SpiSequence_SpiSequence_TLE8108EM  ((Spi_SequenceType)9U)
#define SpiConf_SpiSequence_SpiSequence_NCK2910  ((Spi_SequenceType)10U)
#define SpiConf_SpiSequence_SpiSequence_NJJ29C0B  ((Spi_SequenceType)11U)
#define SpiConf_SpiSequence_SpiSequence_TLE94103B  ((Spi_SequenceType)12U)
#define SpiConf_SpiSequence_SpiSequence_TLE94103A  ((Spi_SequenceType)13U)
#define SpiConf_SpiSequence_SpiSequence_ADAU1462  ((Spi_SequenceType)14U)


/** \brief  Handles for external  HW unit USED  */
#define CSIB1 ((Spi_HWUnitType)0U)
#define CSIB2 ((Spi_HWUnitType)1U)
#define CSIB3 ((Spi_HWUnitType)2U)
#define CSIB4 ((Spi_HWUnitType)3U)
#define CSIB5 ((Spi_HWUnitType)4U)
#define CSIB6 ((Spi_HWUnitType)5U)
#define CSIB7 ((Spi_HWUnitType)6U)
#define CSIB8 ((Spi_HWUnitType)7U)
/** \brief  Handles for Chip Select(Slave select) allocated to the Job */
#define SPI_CS_0 (0U)
#define SPI_CS_1 (1U)
#define SPI_CS_2 (2U)
#define SPI_CS_3 (3U)


/** \brief  write buffers size*/
#define SPI_BUFFER_SIZE_CHANNEL_0  (64U)
#define SPI_BUFFER_SIZE_CHANNEL_1  (128U)
#define SPI_BUFFER_SIZE_CHANNEL_2  (1024U)
#define SPI_BUFFER_SIZE_CHANNEL_3  (2048U)
#define SPI_BUFFER_SIZE_CHANNEL_4  (3072U)
#define SPI_BUFFER_SIZE_CHANNEL_5  (2048U)
#define SPI_BUFFER_SIZE_CHANNEL_6  (256U)
#define SPI_BUFFER_SIZE_CHANNEL_7  (128U)
#define SPI_BUFFER_SIZE_CHANNEL_8  (64U)
#define SPI_BUFFER_SIZE_CHANNEL_9  (8U)
#define SPI_BUFFER_SIZE_CHANNEL_10  (16U)
#define SPI_BUFFER_SIZE_CHANNEL_11  (32U)
#define SPI_BUFFER_SIZE_CHANNEL_12  (64U)
#define SPI_BUFFER_SIZE_CHANNEL_13  (128U)
#define SPI_BUFFER_SIZE_CHANNEL_14  (245U)
#define SPI_BUFFER_SIZE_CHANNEL_15  (8U)
#define SPI_BUFFER_SIZE_CHANNEL_16  (16U)
#define SPI_BUFFER_SIZE_CHANNEL_17  (32U)
#define SPI_BUFFER_SIZE_CHANNEL_18  (256U)
#define SPI_BUFFER_SIZE_CHANNEL_19  (128U)
#define SPI_BUFFER_SIZE_CHANNEL_20  (1024U)
#define SPI_BUFFER_SIZE_CHANNEL_21  (1466U)
#define SPI_BUFFER_SIZE_CHANNEL_22  (2050U)
#define SPI_BUFFER_SIZE_CHANNEL_23  (100U)
#define SPI_BUFFER_SIZE_CHANNEL_24  (40U)
#define SPI_BUFFER_SIZE_CHANNEL_25  (50U)
#define SPI_BUFFER_SIZE_CHANNEL_26  (34U)
#define SPI_BUFFER_SIZE_CHANNEL_27  (60U)
#define SPI_BUFFER_SIZE_CHANNEL_28  (30U)
#define SPI_BUFFER_SIZE_CHANNEL_29  (900U)
#define SPI_BUFFER_SIZE_CHANNEL_30  (40U)
#define SPI_BUFFER_SIZE_CHANNEL_31  (970U)
#define SPI_BUFFER_SIZE_CHANNEL_32  (2U)
#define SPI_BUFFER_SIZE_CHANNEL_33  (4U)
#define SPI_BUFFER_SIZE_CHANNEL_34  (4U)
#define SPI_BUFFER_SIZE_CHANNEL_35  (8U)
#define SPI_BUFFER_SIZE_CHANNEL_36  (1U)
#define SPI_BUFFER_SIZE_CHANNEL_37  (255U)
#define SPI_BUFFER_SIZE_CHANNEL_38  (255U)
#define SPI_BUFFER_SIZE_CHANNEL_39  (4U)
#define SPI_BUFFER_SIZE_CHANNEL_40  (4U)
#define SPI_BUFFER_SIZE_CHANNEL_41  (255U)

/** \brief  Switche to enable or disable Hardware loop back . */
#define SPI_HW_LOOPBACK STD_OFF

#ifdef __cplusplus
}
#endif

#endif  /* SPI_CFG_H */

/* End of file */

