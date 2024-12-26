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
 * @file  Spi_Driver.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Spi plugins.
 */

#ifndef SPI_DRIVER_H
#define SPI_DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "cdefs.h"
#include "mld_spi.h"
#include "e3_ip_spi.h"
#include "Spi_Types.h"
#include "Spi_PbCfg.h"
#include "Mcu.h"
#include "arch.h"

#if (SPI_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Release version information */
#define SPI_DRIVER_AR_RELEASE_MAJOR_VERSION SPI_AR_RELEASE_MAJOR_VERSION
#define SPI_DRIVER_AR_RELEASE_MINOR_VERSION SPI_AR_RELEASE_MINOR_VERSION
#define SPI_DRIVER_AR_RELEASE_REVISION_VERSION \
    SPI_AR_RELEASE_REVISION_VERSION

/* File version information */
#define SPI_DRIVER_SW_MAJOR_VERSION SPI_SW_MAJOR_VERSION
#define SPI_DRIVER_SW_MINOR_VERSION SPI_SW_MINOR_VERSION

#define DW_SSI_TXFTLR_THRESHOLD_VALUE  (0U)

#define DW_SSI_RXFTLR_THRESHOLD_VALUE  (0U)
/*******************************************************************************
**                      Global Symbols                                      **
*******************************************************************************/
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
typedef enum {
    SCPO0_SCPH0 = 0x0,
    SCPO0_SCPH1 = 0x1,
    SCPO1_SCPH0 = 0x2,
    SCPO1_SCPH1 = 0x3
} Spi_clock_mode;

typedef struct Spi_EBDataTypeTag {
    /*Buffer for data source */
    const Spi_DataBufferType *SrcDataBufferPtr;
    /*Buffer for data destination */
    Spi_DataBufferType *DesDataBufferPtr;
    /*Length of buffer */
    Spi_NumberOfDataType Length;
} Spi_EBDataType;

typedef enum Spi_SeqQueueStatusTypeTag {
    SPI_SEQ_QUEUE_INIT = 0,
    SPI_SEQ_QUEUE_PENDING,
    SPI_SEQ_QUEUE_SCHEDULED,
    SPI_SEQ_QUEUE_IN_PROGRESS,
    SPI_SEQ_QUEUE_OK
} Spi_SeqQueueStatusType;

#ifndef SPI_LEVEL_DELIVERED
#error "No define 'SPI_LEVEL_DELIVERED' "
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))

struct Spi_list {
    struct Spi_list *Next;
    struct Spi_list *Prev;
};
#ifndef _offsetof
#define _offsetof(type, member)  \
    ((uint32)(&((type *)0)->member))
#endif

#define GetJobNode(ptr) \
    ((struct Spi_JobNode *)(((uint32)(ptr)) - _offsetof(struct Spi_JobNode, Node)))


#define GetSeqNode(ptr) \
    ((struct Spi_SeqNode *)(((uint32)(ptr)) - _offsetof(struct Spi_SeqNode, Node)))

struct Spi_JobNode {
    boolean IsActive;
    uint8   JobId;
    uint8   SeqId;
    struct Spi_list Node;
};
enum {
    ASYNC_SCHE_UNINIT,
    ASYNC_SCHE_IDLE,
    ASYNC_SCHE_ACTIVE,
};
struct Spi_SeqNode {
    /* seq id*/
    uint16   SeqId;
    /* seq priorty*/
    uint8   Priorty;
    /* Can Interrupt ? */
    uint8   Interruptable;
    /* Job Queue list head */
    struct Spi_list JobQueue;
    /* Cur Job index */
    struct Spi_JobNode *CurJob;
    /* Seq Queue Node  */
    struct Spi_list Node;
    /* seq in queue */
    uint8 SeqInQueue;
};
#endif


struct Spi_Scheduler {
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
     (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
    uint8 State;
    /* scheduled Seq Count */
    uint8 ActiveJobCnt;
    /* need schedule Seq Count */
    uint8 PendingSeqCnt;
    /* Hardware status mask */
    uint32 HwStatusMask;
    /* Global variable for Async mode  */
    Spi_AsyncModeType SchedulerMode;
    /* Seq Queue list head */
    struct Spi_list  SeqQueue;
    /* Record the job currently being processed by each controller */
    struct Spi_JobNode *JobCurr[SPI_TOTAL_HW_COUNT];
#else
#if  (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_ON)
    /* Hardware status mask */
    uint32 HwStatusMask;
#endif
#endif

};

struct SpiBus {
    /* mld bus  */
    struct mld_spi_module Bus;
    /* mld bus Priv parameter  */
    struct spi_bus_priv   Bus_Priv;
};
struct SpiDevice {
    /* mld device */
    struct mld_spi_device Device;
    /* mld device Priv parameter*/
    struct spi_dev_priv   Device_Priv;
};
/* A variable which is going to access configptr for Spi_ConfigType*/
struct Spi_Driver_Handler {
    /* Spi Controllers */
    struct SpiBus        SpiBus[SPI_TOTAL_HW_COUNT];
    /* Spi Slave Device  */
    struct SpiDevice     SpiDevice[SPI_TOTAL_DEV_COUNT];
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
    /* Job Note list item */
    struct Spi_JobNode  JobNode[SPI_TOTAL_DEV_COUNT];
    /* Seq Note list item */
    struct Spi_SeqNode  SeqNode[SPI_TOTAL_SEQ_COUNT];
#endif
    /* mld async vector item  */
    struct mld_spi_async  SpiChannelCB[SPI_MAX_CHANNEL];
    /*BUFF data  valid state */
    Spi_ChannelStateType  Spi_SpiChannelState[SPI_MAX_CHANNEL];
    /* async state machine */
    Spi_StatusType Spi_HandlerAsyncStatus;
    /* sync state machine */
    Spi_StatusType Spi_HandlerStatus;
    /* store EB pointer */
    Spi_EBDataType ExtBuff[SPI_TOTAL_CH_COUNT];
    /* Job result */
    Spi_JobResultType JobResult[SPI_TOTAL_JOB_COUNT];
    /* Seq result */
    Spi_SeqResultType SeqResult[SPI_TOTAL_SEQ_COUNT];
    /*Sync mode Seq Count */
    uint16  SpiSyncSeqActiveCnt;
    /* Async Seq Cancel status */
#if SPI_CANCEL_API == STD_ON
    uint8    SeqCancel[SPI_TOTAL_SEQ_COUNT];
#endif
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
     (SPI_LEVEL_DELIVERED == SPI_LEVEL_2 ) || \
     (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_ON))
    /* async scheduler only useed in LEVELx  X > 0*/
    struct Spi_Scheduler Scheduler;
#endif
} __attribute__((aligned(CACHE_LINE)));

extern VAR( struct Spi_Driver_Handler, SPI_VAR) SpiHandler[SPI_CFG_CORES];

/* To initialise basic Hardware Registers */
extern FUNC(Std_ReturnType, SPI_CODE) Spi_HWInit(void);
/* To De-Initialise the Hardware unit */
extern FUNC(Std_ReturnType, SPI_CODE) Spi_HWDeInit(void);
/* To perform basic DET checks related to channels */
extern FUNC(Std_ReturnType, SPI_CODE) Spi_ChannelDetCheck(const Spi_ChannelType Channel,
        const uint8 SId);
/* To perform basic Det Checks for sequence Transmission request */
extern FUNC(Std_ReturnType, SPI_CODE) Spi_SeqIdDetCheck(const Spi_SequenceType Sequence,
        const uint8 SId);
/* To transmits the sequence  */
extern FUNC(Std_ReturnType, SPI_CODE) Spi_SeqSyncTransmit(Spi_SequenceType SequenceId,
        const Spi_SequenceCfgType *PtrSeqConfig);
/* This function reads the HW status from  DW_SSI_SR register */
extern  FUNC(Spi_StatusType, SPI_CODE) Spi_GetHWStatus(Spi_HWUnitType HwUnit);
/* Initialise global  data.*/
extern FUNC(void, SPI_CODE) Spi_InitData(void);
/* */
extern FUNC(void, SPI_CODE) Spi_HwMainFunctionHandling(uint8 Hwidx);
/* */
extern Std_ReturnType Spi_HwAsyncTransmit(Spi_SequenceType Sequence);
/* */
extern void Spi_LocalParametersCheck(boolean expression,
                                     uint8 API_ID,
                                     uint8 ERROR_ID,
                                     Std_ReturnType *ReturnValue);
/* */
extern void Spi_AsyncModeSet(Spi_AsyncModeType mode);

static inline uint8 Spi_GetCoreID(void)
{
#if (SPI_SINGLE_CORE_HANDLER == STD_OFF)
    return Mcu_GetCoreID();
#else
    return SPI_SINGLE_CORE_ID;
#endif
}

#if (SPI_ENABLE_SLAVE == STD_ON && SPI_CANCEL_API == STD_ON)
void Spi_SlaveSeqCancel(Spi_SequenceType SeqId);
#endif

#if (SPI_DEV_ERROR_DETECT == STD_ON)
uint32 GetSpiChannelAssignCoreId(Spi_ChannelType Channel);
uint32 GetSpiJobAssignCoreId(Spi_JobType JobId);
uint32 GetSpiSequenceAssignCoreId(Spi_SequenceType Sequence);
#endif

#ifdef __cplusplus
}
#endif

#endif /* SPI_DRIVER_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
