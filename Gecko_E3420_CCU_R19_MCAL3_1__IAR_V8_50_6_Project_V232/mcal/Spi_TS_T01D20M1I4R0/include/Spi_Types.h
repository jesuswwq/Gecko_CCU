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
 *  \file     Spi_Types.h
 *  \brief    This file contains interface header for CAN MCAL driver
 *
 * <table>
 * <tr><th>Date           <th>Version
 * <tr><td>2023/07/27     <td>1.0.0
 * </table>
 *****************************************************************************************/
#ifndef SPI_TYPES_H
#define SPI_TYPES_H

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
 *  \sa MCAL_SPI_MACRO
 */
/** \{ */

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************************
 *                       Include header files
 *****************************************************************************************/
#include "Spi_Cfg.h"
#include "Std_Types.h"
#include "Spi_Cbk.h"
/**
 *  \defgroup MCAL_SPI_CFG SPI types defines.
 *
 * This files defines SPI MCAL configuration structures
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
/*****************************************************************************************
 *                   Global Macro definition
 *****************************************************************************************/
/** \brief  Spi Arch relevant cache line size */
#define SPI_CACHE_LINE          (32U)
/** \brief  Spi round up marco */
#define SPI_ROUNDUP(a, b)       \
        ((uint32)(((uint32)(a) + ((uint32)(b)-1U)) & ~((uint32)(b)-1U)))
/** \brief  Spi checking alignment */
#define SPI_IS_ALIGNED(a, b)    \
        ((boolean)((uint32)0 == (  ((uint32)(a)) & (((uint32)(b))-1U))))

/** \} */

/**
 *  \addtogroup MCAL_SPI_CFG SPI types defines.
 *  \{
 */
/*****************************************************************************************
 *                            Global Types definition
 *****************************************************************************************/
/** \brief Type of data buffer . */
/** Traceability       : SWSR_SPI_114 SWSR_SPI_115 */
typedef uint8 Spi_DataBufferType;

/** \brief Type for defining the number of data elements of the type Spi_DataBufferType
 * to send and / or receive by Channel */
/** Traceability       : SWSR_SPI_116 SWSR_SPI_117 */
typedef uint16 Spi_NumberOfDataType;
/** \brief Definition of type for channel ID */
/** Traceability       : SWSR_SPI_087 SWSR_SPI_118 SWSR_SPI_119 SWSR_SPI_120 */
typedef uint8 Spi_ChannelType;

/** \brief Specifies the identification (ID) for a Job. */
/** Traceability       : SWSR_SPI_121 SWSR_SPI_122 SWSR_SPI_123 */
typedef uint16 Spi_JobType;

/** \brief Specifies the identification (ID) for a sequence of jobs. */
/** Traceability       : SWSR_SPI_124 SWSR_SPI_125 SWSR_SPI_126 */
typedef uint8 Spi_SequenceType;

/** \brief Specifies the identification (ID) for a SPI Hardware microcontroller
 *         peripheral (unit). */
/** Traceability       : SWSR_SPI_127 SWSR_SPI_128 SWSR_SPI_129 */
typedef uint8 Spi_HWUnitType;

/** \brief Specifies the Soft Chip Select Mux (ID) for a job. */
typedef enum
{
    SPI_PIN_MUX_ALT0 = 0u,
    SPI_PIN_MUX_ALT1 = 1u,
    SPI_PIN_MUX_ALT2 = 2u,
    SPI_PIN_MUX_ALT3 = 3u,
    SPI_PIN_MUX_ALT4 = 4u,
    SPI_PIN_MUX_ALT5 = 5u,
    SPI_PIN_MUX_ALT6 = 6u,
    SPI_PIN_MUX_ALT7 = 7u,
    SPI_PIN_MUX_ALT8 = 8u,
    SPI_PIN_MUX_ALT9 = 9u,
} Spi_PinModeType;

/** \brief Definition of status type */
/** Traceability       : SWSR_SPI_091 SWSR_SPI_092 SWSR_SPI_093 SWSR_SPI_094 SWSR_SPI_095 */
typedef enum Spi_StatusTypeTag
{
    SPI_UNINIT = 0,
    SPI_IDLE = 1,
    SPI_BUSY = 2
} Spi_StatusType;

/** \brief Definition of Job Result type */
/** Traceability       : SWSR_SPI_101 SWSR_SPI_102 SWSR_SPI_103 */
typedef enum Spi_JobResultTypeTag
{
    SPI_JOB_OK = 0,
    SPI_JOB_PENDING,
    SPI_JOB_FAILED,
    SPI_JOB_QUEUED
} Spi_JobResultType;

/** \brief Definition of Sequence Result type */
/** Traceability       : SWSR_SPI_106 SWSR_SPI_107 SWSR_SPI_108 SWSR_SPI_109 */
typedef enum Spi_SeqResultTypeTag
{
    SPI_SEQ_OK = 0,
    SPI_SEQ_PENDING,
    SPI_SEQ_FAILED,
    SPI_SEQ_CANCELLED
} Spi_SeqResultType;

/** \brief Definition of type for asynchronous mode */
/** Traceability       : SWSR_SPI_130 SWSR_SPI_131 SWSR_SPI_132 SWSR_SPI_133 */
typedef enum Spi_AsyncModeTypeTag
{
    SPI_POLLING_MODE = 0,
    SPI_INTERRUPT_MODE
} Spi_AsyncModeType;

/** \brief Buffer usage with EB/IB channel. */
typedef enum ChannelBufferTypeTag
{
    EB = 0,
    IB
} Spi_ChannelBufferType;
/** \brief Bits order usage with lsb/msb channel. */
typedef enum
{
    LSB = 0,
    MSB
} Spi_ChannelTransferType;

/** \brief This parameter defines the SPI data shift edge. */
typedef enum Spi_DataShiftEdgeTag
{
    LEADING = 0,
    TRAILING
} Spi_DataShiftEdge;

/** \brief This parameter defines the SPI shift clock idle level. */
typedef enum Spi_ShiftClockIdleLevelTag
{
    HIGH,
    LOW
} Spi_ShiftClockIdleLevel;

/** \brief This parameter defines the SPI chip select mode(soft/hw). */
typedef enum Spi_CsHandlingTag
{
    CS_VIA_GPIO,
    CS_VIA_PERIPHERAL_ENGINE
} Spi_CsHandling;

/** \brief This parameter defines the SPI controler mode(salve/master only support in fusa). */
/** Traceability       : SWSR_SPI_001 */
typedef enum
{
    SPI_MASTER = 0,
} Spi_HwUnitMode;

/** \brief This parameter defines the SPI Job mode. */
typedef enum
{
    SPI_ASYNC_MODE = 0,
    SPI_SYNC_MODE
} Spi_TransferMode;

/** \brief This parameter defines the SPI IB buffer data stutus. */
typedef enum
{
    DATA_INVALID = 0,
    DATA_VALID,
}Spi_BuffState_t;
/** \brief This parameter defines the SPI buffer locker stutus. */
typedef enum
{
    B_UNLOCK = 0,
    B_LOCKED,
} Spi_BuffLock_t;

/** \brief This parameter defines the SPI Timming Mode. */
typedef enum
{
    SCPO0_SCPH0 = 0x0,
    SCPO0_SCPH1 = 0x1,
    SCPO1_SCPH0 = 0x2,
    SCPO1_SCPH1 = 0x3
} Spi_Mode;

/** \brief This parameter defines the spi channle Cfgs. */
/** Traceability       : SWSR_SPI_087 SWSR_SPI_117 */
typedef struct Spi_ChannelCfgTypeTag
{
    /*Buffer usage with EB/IB Channel*/
    Spi_ChannelBufferType channelBufferType;
    /* Transmit data width (1 up to 32 bits) */
    uint8 dataWidth;
    /* Number of IB Channels or maximum size of EB Channels*/
    Spi_NumberOfDataType bufferSize;
    /* pointer to channel internal write buffers */
    Spi_DataBufferType *writeBufferIndex;
    /* pointer to channel internal Read buffers */
    Spi_DataBufferType *readBufferIndex;
    /* Transfer start LSB or MSB */
    Spi_ChannelTransferType bitOrder;
    /* Default transmit value */
    uint32 defaultValue;
} Spi_ChannelCfgType;

/** \brief This parameter defines the spi channle Cfgs. */
/** Traceability       : SWSR_SPI_013 SWSR_SPI_014 SWSR_SPI_088 SWSR_SPI_090
 *                       SWSR_SPI_242 SWSR_SPI_244 SWSR_SPI_246 SWSR_SPI_250 */
typedef struct Spi_JobCfgTypeTag
{
    /* Data With */
    uint8 dataWidth;
    /* bitOrder Transfer start LSB or MSB */
    Spi_ChannelTransferType bitOrder;
    /* Assigned SPI HW Unit */
    uint8 deviceIdx;
    /*hwIdxOfHwUnitCfgs*/
    uint8 hwIdxOfHwUnitCfgs;
    /* Assigned SPI HW Unit */
    Spi_HWUnitType hwUnitId;
    /* Assigned Chip Select pin */
    uint8 CSIdx;
    /* Chip select functionality on/off */
    boolean hwCS0Enable;
    /* Spi peripheral chip pin id */
    uint8 hwCs0PinId;
    /* Gpio ID simulate as chip select */
    uint8 softCsPin;
    /* Enable Receive functinallity */
    boolean IsEnableRx;
    /* Chip Select Handling */
    Spi_CsHandling CSHandling;
    /* Chip select pin polarity high or low */
    uint8 CSPolarity;
    /* hw Chip select pin idle polarity high or low */
    uint8 HwCSPolarity;
    /* Baud rate (SSI Clock Divider) */
    uint8 baudRateDiv;
    /* Timing between clock and chip select */
    uint8 timeClk2Cs;
    /* Timing between clock and chip deselect */
    uint8 timeClk2CsEnd;
    /* Timing between two transmissions  chip select */
    uint8 timeFrameDelay;
    /* Shift clock idle low or idle high */
    Spi_ShiftClockIdleLevel idleLevel;
    /* Data shift with leading or trailing edge */
    Spi_DataShiftEdge shiftEdge;
    /* Priority (4 levels are available from 0, the lower to 3, the higher) */
    uint8 spiJobPriority;
    /* Pointer to Job finish callback function */
    Spi_JobEndNotifyType jobEndNotification;
    /* MCU dependent properties for the Job (only if needed) */
    /* number if channels in the Job */
    uint8 numOfChannels;
    /* Link to channel list */
    const Spi_ChannelType *channelList;
    /* In master mode, delay half sclk to sample miso */
    uint8 isSampleDelay;
} Spi_JobCfgType;

/** \brief This parameter defines the spi sequence Cfgs. */
/** Traceability       : SWSR_SPI_016 SWSR_SPI_057 SWSR_SPI_089 SWSR_SPI_243
 *                       SWSR_SPI_244 SWSR_SPI_246 */
typedef struct Spi_SequenceCfgTypeTag
{
    /* interruptable or not interruptable after each Job */
    boolean interruptableSequence;
    /* Sequence finish end notification function */
    Spi_SeqEndNotifyType sequenceEndNotification;
    /* Number of Jobs */
    uint16 numOfJobs;
    /* Collection of Jobs */
    const Spi_JobType *jobList;
    /* Seq_HwMask of hwUnitId */
    const uint8 seqHwMask;
} Spi_SequenceCfgType;

/** \brief  This type of the external data structure shall contain the
 *          initialization data for the SPI Handler/Driver. */
/** Traceability       : SWSR_SPI_084 SWSR_SPI_085 SWSR_SPI_086 */
typedef struct Spi_ConfigTypeTag
{
    /* Definition of Channels */
    const Spi_ChannelCfgType *channelCfgs;
    /* Definition of Jobs */
    const Spi_JobCfgType *jobCfgs;
    /* Definition of Sequences */
    const Spi_SequenceCfgType *sequenceCfgs;
} Spi_ConfigType;

/** \brief This parameter defines the SPI HwUinit Mode. */
typedef struct
{
    /* the hwUnitId is ID or index */
    VAR(Spi_HWUnitType, SPI_VAR) hwUnitId;
    /* hwMode: spi master or slave */
    VAR(Spi_HwUnitMode, SPI_VAR) hwMode;
    /* HwDma: ture enable or false disable */
    VAR(boolean, SPI_VAR) isEnableDMA;
    /* Ti Mode: ture enable or false disable */
    VAR(boolean, SPI_VAR) isEnableTiMod;
    /* transferMode: sync or async */
    VAR(Spi_TransferMode, SPI_VAR) transferMode;
} Spi_HwUnitConfigType;

/** \} */

#ifdef __cplusplus
}
#endif

/** \} */

#endif /** SPI_TYPES_H */
/** End of file */

