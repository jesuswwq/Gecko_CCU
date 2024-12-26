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
 * @file  Spi_Types.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Spi plugins.
 */

#ifndef SPI_TYPES_H
#define SPI_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/

/* Included for pre-compile options */
#include "Spi_Cfg.h"

/* AUTOSAR standard types */
#include "Std_Types.h"
#include "Spi_Cbk.h"
#include "Port.h"

/* Type of application data buffer elements. */
typedef uint8 Spi_DataBufferType;

/* Type for defining the number of data elements of the type Spi_DataBufferType to send and / or receive by Channel */
typedef uint16 Spi_NumberOfDataType;

/* Definition of type for channel ID */
typedef uint8 Spi_ChannelType;

/* Specifies the identification (ID) for a Job. */
typedef uint16 Spi_JobType;

/* Specifies the identification (ID) for a sequence of jobs. */
typedef uint8 Spi_SequenceType;

/* Specifies the identification (ID) for a SPI Hardware microcontroller peripheral (unit). */
typedef uint8 Spi_HWUnitType;

typedef pin_mux_e Spi_PinModeType;

/* Definition of status type */
typedef enum Spi_StatusTypeTag {
    SPI_UNINIT = 0,
    SPI_IDLE = 1,
    SPI_BUSY = 2
} Spi_StatusType;

/* Definition of Job Result type */
typedef enum Spi_ChnResultTypeTag {
    SPI_CHN_OK = 0,
    SPI_CHN_PENDING,
    SPI_CHN_FAILED,
    SPI_CHN_QUEUED
} Spi_ChnResultType;

/* Definition of Job Result type */
typedef enum Spi_JobResultTypeTag {
    SPI_JOB_OK = 0,
    SPI_JOB_PENDING,
    SPI_JOB_FAILED,
    SPI_JOB_QUEUED
} Spi_JobResultType;

/* Definition of Sequence Result type */
typedef enum Spi_SeqResultTypeTag {
    SPI_SEQ_OK = 0,
    SPI_SEQ_PENDING,
    SPI_SEQ_FAILED,
    SPI_SEQ_CANCELLED
} Spi_SeqResultType;

/* Definition of type for asynchronous mode */
typedef enum Spi_AsyncModeTypeTag {
    SPI_POLLING_MODE = 0,
    SPI_INTERRUPT_MODE
} Spi_AsyncModeType;

/* Buffer usage with EB/IB channel. */
typedef enum ChannelBufferTypeTag {
    EB = 0,
    IB
} Spi_ChannelBufferType;
typedef enum {
    LSB = 0,
    MSB
} Spi_ChannelTransferType;

/* This parameter defines the SPI data shift edge. */
typedef enum Spi_DataShiftEdgeTag {
    LEADING = 0,
    TRAILING
} Spi_DataShiftEdge;

/*This parameter defines the SPI shift clock idle level. */
typedef enum Spi_ShiftClockIdleLevelTag {
    HIGH,
    LOW
} Spi_ShiftClockIdleLevel;

typedef enum Spi_CsHandlingTag {
    CS_VIA_GPIO,
    CS_VIA_PERIPHERAL_ENGINE
} Spi_CsHandling;

typedef enum {
    SPI_MASTER = 0,
    SPI_SLAVE
} Spi_HwUnitMode;

typedef enum {
    SPI_ASYNC_MODE = 0,
    SPI_SYNC_MODE
} Spi_TransferMode;

typedef struct Spi_ChannelCfgTypeTag {
    /*Buffer usage with EB/IB Channel*/
    Spi_ChannelBufferType ChannelBufferType;
    /* Transmit data width (1 up to 32 bits) */
    uint8 DataWidth;
    /* Number of IB Channels or maximum size of EB Channels*/
    Spi_NumberOfDataType BufferSize;
    /* pointer to channel internal write buffers */
    Spi_DataBufferType *WriteBufferIndex;
    /* pointer to channel internal Read buffers */
    Spi_DataBufferType *ReadBufferIndex;
    /* Transfer start LSB or MSB */
    Spi_ChannelTransferType TransferType;
    /* Default transmit value */
    uint32 DefaultValue;
} Spi_ChannelCfgType;

typedef struct Spi_JobCfgTypeTag {
    /* Data With */
    uint8 DataWidth;
    /* BitOrder Transfer start LSB or MSB */
    Spi_ChannelTransferType BitOrder;
    /* Assigned SPI HW Unit */
    uint8 DeviceIdx;
    /*HwUnitIdxCfg*/
    uint8 HwUnitIdxCfg;
    /* Assigned SPI HW Unit */
    Spi_HWUnitType HWUnit;
    /* Assigned Chip Select pin */
    uint8 CSPin;
    /* Chip select functionality on/off */
    boolean CSFunc;
    /* Spi peripheral chip pin id */
    uint8 PortPinId;
    /* Spi peripheral chip pin mux */
    Spi_PinModeType PinMux;
    /* Gpio ID simulate as chip select */
    uint8 GPIOCsPin;
    /* Enable Receive functinallity */
    boolean EnableRx;
    /* Chip Select Handling */
    Spi_CsHandling CSHandling;
    /* Chip select pin polarity high or low */
    boolean CSPolarity;
    /* Baud rate (SSI Clock Divider) */
    uint16 BaudRate;
    /* Timing between clock and chip select */
    uint8 TimeClkCs;
    /* Timing between clock and chip deselect */
    uint8 TimeClkCsEnd;
    /* Shift clock idle low or idle high */
    Spi_ShiftClockIdleLevel ShiftClk;
    /* Data shift with leading or trailing edge */
    Spi_DataShiftEdge ShiftEdge;
    /* Priority (4 levels are available from 0, the lower to 3, the higher) */
    uint8 SpiJobPriority;
    /* Pointer to Job finish callback function */
    Spi_JobEndNotifyType JobEndNotification;
    /* MCU dependent properties for the Job (only if needed) */
    /* number if channels in the Job */
    uint8 NoOfChannels;
    /* Link to channel list */
    const Spi_ChannelType *ChannelList;
    /* In master mode, delay half sclk to sample miso */
    uint8 SampleDelay;
} Spi_JobCfgType;

typedef struct Spi_SequenceCfgTypeTag {
    /* Interruptable or not interruptable after each Job */
    boolean InterruptableSequence;
    /* Sequence finish end notification function */
    Spi_SeqEndNotifyType SequenceEndNotification;
    /* Number of Jobs */
    uint16 NoOfJobs;
    /* Collection of Jobs */
    const Spi_JobType *JobList;
    /* Seq_HwMask of HwUnit */
    const uint32 SeqHwMask;
} Spi_SequenceCfgType;

typedef struct Spi_ConfigTypeTag {
    /* Definition of Channels */
    const Spi_ChannelCfgType *ChannelType;
    /* Definition of Jobs */
    const Spi_JobCfgType *JobType;
    /* Definition of Sequences */
    const Spi_SequenceCfgType *SequenceType;
} Spi_ConfigType;

typedef enum  {
    DATA_INVALID = 0,
    DATA_VALID,
} Spi_RIBDataTag;

typedef enum  {
    BUFF_INVALID = 0,
    BUFF_VALID,
} Spi_WIBDataTag;

typedef enum  {
    B_UNLOCK = 0,
    B_LOCKED,
} Spi_BuffLock;

typedef struct {
    VAR(Spi_RIBDataTag, SPI_VAR) Rx_Tag;                 /* Data Tag */
    VAR(Spi_WIBDataTag, SPI_VAR) Tx_Tag;                 /* Data Tag */
    /*IB Buf write locker */
    VAR(Spi_BuffLock, SPI_VAR) BuffLock;
} Spi_ChannelStateType;

typedef struct {
    /* the HwUnit is ID or index */
    VAR(Spi_HWUnitType, SPI_VAR) HwUnit;
    /* HwMode: spi master or slave */
    VAR(Spi_HwUnitMode, SPI_VAR) HwMode;
    /* HwDma: ture enable or false disable */
    VAR(boolean, SPI_VAR) HwDMA;
    /* Ti Mode: ture enable or false disable */
    VAR(boolean, SPI_VAR) HwTiMode;
    /* TransferMode: sync or async */
    VAR(Spi_TransferMode, SPI_VAR) TransferMode;
} Spi_HwUnitConfigType;

extern VAR(Spi_ChannelStateType, SPI_VAR) Spi_SpiChannelState[SPI_MAX_CHANNEL];

extern P2CONST(Spi_ConfigType, SPI_VAR, SPI_APPL_CONST) Spi_pSpiConfigPtr;

#ifdef __cplusplus
}
#endif

#endif /* SPI_TYPES_H */
/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/
