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
 *  \file     Spi_Driver.h
 *  \brief    This file contains interface header for CAN MCAL driver
 *
 * <table>
 * <tr><th>Date           <th>Version
 * <tr><td>2023/07/27     <td>1.0.0
 * </table>
 *****************************************************************************************/

#ifndef SPI_DRIVER_H
#define SPI_DRIVER_H

/**
 *  \defgroup MCAL_SPI SPI Driver
 *
 *  The SPI Handler/Driver provides services for reading from and writing to devices
 *  connected via SPI busses.
 *
 *  This spi driver provide only master mode transmission via chip spi controllers
 *  depend on user configurations <br>
 *  This module relevanto to dam module in dma mode, too short transmission dma mode
 *  is not recommended.<br>
 *  \sa MCAL_SPI_CFG
 *  \sa MCAL_SPI_API
 *  \sa MCAL_SPI_MACRO
 */
/** \{ */

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************************
 *                       Include header files
 *****************************************************************************************/
#include "cdefs.h"
#include "Spi_Mld.h"
#include "Spi_Ip.h"
#include "Spi_Types.h"
#include "Spi_Cfg.h"
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

/*****************************************************************************************
 *                   Global Macro definition
 *****************************************************************************************/

/** \brief  AUTOSAR Release version information */
#define SPI_DRIVER_AR_RELEASE_MAJOR_VERSION SPI_AR_RELEASE_MAJOR_VERSION
#define SPI_DRIVER_AR_RELEASE_MINOR_VERSION SPI_AR_RELEASE_MINOR_VERSION
#define SPI_DRIVER_AR_RELEASE_REVISION_VERSION SPI_AR_RELEASE_REVISION_VERSION

/** \brief  File version information */
#define SPI_DRIVER_SW_MAJOR_VERSION SPI_SW_MAJOR_VERSION
#define SPI_DRIVER_SW_MINOR_VERSION SPI_SW_MINOR_VERSION
/** \brief  Dummy  state process. */
#define SPI_DUMMY_STATEMENT(v)              ((void)(v))
/** \brief  get the member offset of struct */
/* Traceability       :  SWSR_SPI_005 */
#define SD_OFFSETOF(type, member)  ((uint32)(&(((type)0)->member)))

/** \brief  Get the Jobnode from none member */
/* Traceability       :  SWSR_SPI_005 */
#define GetJobNode(ptr) ((struct Spi_JobNode *)(((uint32)(ptr)) - (SD_OFFSETOF(struct Spi_JobNode*, node))))

/** \brief  Get the Seqnode from none member */
/* Traceability       :  SWSR_SPI_005 */
#define GetSeqNode(ptr) ((struct Spi_SeqNode *)(((uint32)(ptr)) - (SD_OFFSETOF(struct Spi_SeqNode*, node))))

/** \} */

/**
 *  \addtogroup MCAL_SPI_CFG SPI Configuration.
 *  \{
 */

/*****************************************************************************************
 *                            Global Types definition
 *****************************************************************************************/
/** \brief  Dma module identify, which are currently support modules. */
/** Traceability       : SWSR_SPI_115 SWSR_SPI_117 */
typedef struct Spi_EBDataTypeTag
{
    /*Buffer for data source */
    const Spi_DataBufferType *srcDataBufferPtr;
    /*Buffer for data destination */
    Spi_DataBufferType *desDataBufferPtr;
    /*Length of buffer */
    Spi_NumberOfDataType length;
} Spi_EBDataType;

#ifndef SPI_LEVEL_DELIVERED
#error "No define 'SPI_LEVEL_DELIVERED' "
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
/** \brief  Spi list manage data struct . */
/* Traceability       :  SWSR_SPI_005 SWSR_SPI_045 */
struct Spi_list
{
    struct Spi_list *next;
    struct Spi_list *prev;
};

/** \brief  Spi Job node for schedule . */
/* Traceability       :  SWSR_SPI_005 */
struct Spi_JobNode
{
    boolean isActive;
    uint16   jobId;
    uint8   seqId;
    struct Spi_list node;
};
/** \brief  Spi schedule status . */
/* Traceability       :  SWSR_SPI_005 */
enum scheSta
{
    ASYNC_SCHE_UNINIT,
    ASYNC_SCHE_IDLE,
    ASYNC_SCHE_ACTIVE,
};
/** \brief  Spi Seq node for schedule . */
/* Traceability       :  SWSR_SPI_005 */
struct Spi_SeqNode
{
    /* seq id*/
    uint8   seqId;
    /* seq priorty*/
    uint8   priorty;
    /* Can Interrupt ? */
    uint8   interruptable;
    /* Job Queue list head */
    struct Spi_list jobList;
    /* Cur Job index */
    struct Spi_JobNode *pCurrJobNode;
    /* Seq Queue node  */
    struct Spi_list node;
    /* seq in queue */
    uint8 seqIsInQueue;
};
#endif
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
     (SPI_LEVEL_DELIVERED == SPI_LEVEL_2 ) || \
     (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_ON))
/** \brief  Spi Schedule  struct. */
/* Traceability       :  SWSR_SPI_005 */
struct Spi_Scheduler
{
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
     (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
    enum scheSta schedulerState;
    /* scheduled Seq Count */
    uint8 activeJobsCnt;
    /* need schedule Seq Count */
    uint8 pendingSeqsCnt;
    /* Hardware status mask */
    uint8 hwStatusMask;
    /* Global variable for Async mode  */
    Spi_AsyncModeType schedulerMode;
    /* Seq Queue list head */
    struct Spi_list  seqsQueue;
    /* Record the job currently being processed by each controller */
    struct Spi_JobNode *hwCurrJob[SPI_TOTAL_HW_COUNT];
#else
#if  (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_ON)
    /* Hardware status mask */
    uint8 hwStatusMask;
#endif
#endif
};
#endif
/** \brief  Spi Schedule  struct. */
struct SpiBus
{
    /* mld bus  */
    struct mld_spi_module bus;
    /* mld bus Priv parameter  */
    struct spi_bus_priv   busPriv;
};
/** \brief  Spi Schedule  struct. */
struct SpiDevice
{
    /* mld device */
    struct mld_spi_device device;
    /* mld device Priv parameter*/
    struct spi_dev_priv   devicePriv;
};
/** \brief  per-core driver handler struct */
struct Spi_Driver_Handler
{
    /* Spi Controllers */
    struct SpiBus        spiBus[SPI_TOTAL_HW_COUNT];
    /* Spi Slave device  */
    struct SpiDevice     spiDevice[SPI_TOTAL_DEV_COUNT];
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
    /* Job Note list item */
    struct Spi_JobNode  jobNode[SPI_TOTAL_DEV_COUNT];
    /* Seq Note list item */
    struct Spi_SeqNode  seqNode[SPI_TOTAL_SEQ_COUNT];
#endif
    /* mld async vector item  */
    struct mld_vector  spiChannelCB[SPI_MAX_CHANNEL];
    /*BUFF lock state */
    Spi_BuffLock_t  spiChannelLock[SPI_MAX_CHANNEL];
    /*BUFF data  valid state */
    Spi_BuffState_t spiChannelState[SPI_MAX_CHANNEL];
    /* async state machine */
    Spi_StatusType handlerAsyncStatus;
    /* sync state machine */
    Spi_StatusType handlerStatus;
    /* store EB pointer */
    Spi_EBDataType externalBuffCb[SPI_TOTAL_CH_COUNT];
    /* Job result */
    Spi_JobResultType jobResultArr[SPI_TOTAL_JOB_COUNT];
    /* Seq result */
    Spi_SeqResultType seqResultArr[SPI_TOTAL_SEQ_COUNT];
    /*Sync mode Seq Count */
    uint8  spiSyncSeqActiveCnt;
    /* Async Seq Cancel status */
#if SPI_CANCEL_API == STD_ON
    uint8    seqIsCancel[SPI_TOTAL_SEQ_COUNT];
#endif
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
     (SPI_LEVEL_DELIVERED == SPI_LEVEL_2 ) || \
     (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_ON))
    /* async scheduler only useed in LEVELx  X > 0*/
    struct Spi_Scheduler scheduler;
#endif
    /* for rx ingnal dma mode*/
    uint32 dummyRxBuffer;
    /* for tx default mode */
    uint32 dummyTxBuffer;
};

/** \brief  This is the core spi driver handler global variable object */
/* Traceability       :  SWSR_SPI_255 */
extern struct Spi_Driver_Handler *const Spi_Handler[5];

/** \} */

/*****************************************************************************************
 *                                  Private Function Declarations
 *****************************************************************************************/


/**
 *  \addtogroup MCAL_SPI_API SPI Api.
 *  \{
 */
 /** *****************************************************************************************************
 * \brief This function return  the coreid of executer.
 *
 * \verbatim
 * Syntax             : uint8 Spi_GetCoreID(void)
 *
 * Service ID[hex]    : NA
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
 * Description        : get the core id.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_255
 *******************************************************************************************************/
uint8 Spi_GetCoreID(void);
/** *****************************************************************************************************
 * \brief This function set the pin output value.
 *
 * \verbatim
 * Syntax             : void Spi_SetIOLevel(uint32 channel, uint32 level)
 *
 * Service ID[hex]    : 0x00
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : pin - Specify pin id.
 *                      level - New output value.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The funtion use to set the pin output value.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_012
 *******************************************************************************************************/
void Spi_SetIOLevel(uint32 pin, uint32 level);
/** **************************************************************************************
 * \brief This function Init the driver global variables.
 *
 * \verbatim
 * Syntax             : void Spi_InitData(const Spi_ConfigType *configPtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : configPtr - Pointer to configuration set
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Init the driver global variables and async scheduler.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_038 SWSR_SPI_104 SWSR_SPI_110 SWSR_SPI_140
 *****************************************************************************************/
void Spi_InitData(const Spi_ConfigType *configPtr);
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
/** **************************************************************************************
 * \brief This function update the mechanism of aync transmission.
 *
 * \verbatim
 * Syntax             : void Spi_AsyncModeSet(
 *                          struct Spi_Driver_Handler *perCoreHandler,
 *                          const Spi_AsyncModeType mode)
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : perCoreHandler - Pointer Spi driver handler set.
 *                      mode - new async mechanism.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : If the async transmission is idle will accept the requires
 *                      otherwish will reject .
 * \endverbatim
 * Traceability       : SWSR_SPI_037 SWSR_SPI_135
 *****************************************************************************************/
void Spi_AsyncModeSet(struct Spi_Driver_Handler *perCoreHandler,
                      const Spi_AsyncModeType mode);
#endif
/** **************************************************************************************
 * \brief This function init the HardWare .
 *
 * \verbatim
 * Syntax             : Std_ReturnType Spi_HWInit(const Spi_ConfigType *configPtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : configPtr - Pointer to configuration set
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK:Init pass.
 *                      E_NOT_OK:Init fail.
 *
 * Description        : Init the Hardware and mld bus/device objects.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_073 SWSR_SPI_082 SWSR_SPI_083 SWSR_SPI_136 SWSR_SPI_137
 *                      SWSR_SPI_138 SWSR_SPI_139
 *****************************************************************************************/
Std_ReturnType Spi_HWInit(const Spi_ConfigType *configPtr);
/** **************************************************************************************
 * \brief This function deinit the hwuints.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Spi_HWDeInit(uint8 coreId)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : coreID - Core Id.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Hardware deinit Pass.
 *                      E_NOT_OK:Hardware deinit Fail.
 *
 * Description        : Deinitialization the hardware controller status to por state.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_142 SWSR_SPI_143 SWSR_SPI_144 SWSR_SPI_145 SWSR_SPI_146
 *                      SWSR_SPI_147 SWSR_SPI_148 SWSR_SPI_149 SWSR_SPI_150
 *****************************************************************************************/
Std_ReturnType Spi_HWDeInit(uint8 coreId);
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_0) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
/** **************************************************************************************
 * \brief This function use to transmit an spi sqeuence synchronous .
 *
 * \verbatim
 * Syntax             : Std_ReturnType Spi_SeqSyncTransmit(Spi_SequenceType sequenceId,
 *                                  const Spi_SequenceCfgType *ptrSeqConfig)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : configPtr - Pointer to configuration set
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK:The sequence  transmission is pass.
 *                      E_NOT_OK:The sequence transmission is fail.
 *
 * Description        : The Sequence Transmit implementation.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_009 SWSR_SPI_011 SWSR_SPI_036 SWSR_SPI_048 SWSR_SPI_050
 *                      SWSR_SPI_063 SWSR_SPI_251 SWSR_SPI_253
 *****************************************************************************************/
Std_ReturnType Spi_SeqSyncTransmit(Spi_SequenceType sequenceId,
                                   const Spi_SequenceCfgType *ptrSeqConfig);
#endif
/** *****************************************************************************************************
 * \brief This function returns the specify spi controler status .
 *
 * \verbatim
 * Syntax             : Spi_StatusType Spi_GetHWStatus(Spi_HWUnitType hwUnitId)
 *
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : hwUnitId - Specify the hwunit id.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : SPI_UNINIT - Spi controler is not inited.
 *                      SPI_BUSY - Spi controler is busy.
 *                      SPI_IDLE - Spi controler is idle.
 *
 * Description        : Get the the specify HwUint status.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_070 SWSR_SPI_079 SWSR_SPI_080 SWSR_SPI_099
 *                      SWSR_SPI_100 SWSR_SPI_221 SWSR_SPI_222 SWSR_SPI_223
 *                      SWSR_SPI_224 SWSR_SPI_225 SWSR_SPI_226
 *******************************************************************************************************/
Spi_StatusType Spi_GetHWStatus(Spi_HWUnitType hwUnitId);
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
/** **************************************************************************************
 * \brief This function select a job form schedule queue to transfer.
 *
 * \verbatim
 * Syntax             : void Spi_TriggerOnceSchedule(void)
 *
 *
 * Service ID[hex]    : None
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
 * Description        : Call by SyncTransmit function when a sequence transfer end.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_005
 *****************************************************************************************/
void Spi_TriggerOnceSchedule(void);
#endif
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
/** **************************************************************************************
 * \brief Service to transmit data on the SPI bus.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Spi_HwAsyncTransmit(Spi_SequenceType sequenceId)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : sequenceId - Specify the seuqence ID.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Transmission command has been accepted
 *                      E_NOT_OK: Transmission command has not been accepted
 *
 * Description        : Service to transmit data on the SPI bus.
 * \endverbatim
 * Traceability       : SWSR_SPI_038 SWSR_SPI_165 SWSR_SPI_166 SWSR_SPI_167 SWSR_SPI_170
 *                      SWSR_SPI_171
 *****************************************************************************************/
Std_ReturnType Spi_HwAsyncTransmit(Spi_SequenceType sequenceId);
#endif
/** *****************************************************************************************************
 * \brief This function use in polling mode to polling a controler transfer.
 *
 * \verbatim
 * Syntax             : void Spi_HwMainFunctionHandling(const uint8 Hwidx)
 *
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : Hwidx - specify the HwUint id.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Polling mode polling main function.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_071 SWSR_SPI_081 SWSR_SPI_241
 *******************************************************************************************************/
void Spi_HwMainFunctionHandling(const uint8 Hwidx);
/** *****************************************************************************************************
 * \brief This function returns current channel core id.
 *
 * \verbatim
 * Syntax             : uint8 Spi_GetSpiChannelAssignCoreId(const Spi_ChannelType channel)
 *
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : channel - Specify the channel id.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Multi core env the channel assign to specify core others core should not access.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_255
 *******************************************************************************************************/
uint8 Spi_GetSpiChannelAssignCoreId(const Spi_ChannelType channel);
/** *****************************************************************************************************
 * \brief This function returns current jobs core id.
 *
 * \verbatim
 * Syntax             : uint8 Spi_GetSpiJobAssignCoreId(const Spi_JobType jobId)
 *
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : jobId - Specify the job id.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Multi core env the job assign to specify core others core should not access.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_255
 *******************************************************************************************************/
uint8 Spi_GetSpiJobAssignCoreId(const Spi_JobType jobId);
/** *****************************************************************************************************
 * \brief This function returns current sequence core id.
 *
 * \verbatim
 * Syntax             : uint8 Spi_GetSpiSequenceAssignCoreId(const Spi_SequenceType sequenceId)
 *
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : sequenceId - Specify the sequenceId id.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Multi core env the squence assign to specify core others core should not access.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_255
 *******************************************************************************************************/
uint8 Spi_GetSpiSequenceAssignCoreId(const Spi_SequenceType sequenceId);

/** \} */
#ifdef __cplusplus
}
#endif

/** \} */

#endif /* SPI_DRIVER_H */

/* End of file */

