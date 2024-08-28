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
 *  \file     Spi_Mld.h
 *  \brief    This file contains interface header for CAN MCAL driver
 *
 * <table>
 * <tr><th>Date           <th>Version
 * <tr><td>2023/07/27     <td>1.0.0
 * </table>
 *****************************************************************************************/

#ifndef MLD_SPI_H_
#define MLD_SPI_H_

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

#ifdef __cplusplus
extern "C" {
#endif
/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#ifdef SPI_DEBUG_LOG
#include "debug.h"
#endif
#include "Compiler.h"
#include "Spi_Types.h"
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
#ifdef SPI_DEBUG_LOG
#define SPI_DBG  PRINT
#else
#define SPI_DBG(...)
#endif

/** \brief  ip levev return val */
#define ERR_NONE       ((sint32)0)
#define ERR_NO_INIT    ((sint32)1)
#define ERR_API_OPS    ((sint32)2)
#define ERR_NO_BUS     ((sint32)3)
#define ERR_LOW_LEVEL  ((sint32)4)
#define ERR_BUSY       ((sint32)5)
/** \brief  data width */
#define SPI_DATA_WIDTH_BYTE  0U
#define SPI_DATA_WIDTH_HALF_WORD 1U
#define SPI_DATA_WIDTH_WORD 2U

/** \brief  irq event type flags */
#define SPI_RX_FIFO_READ   ((uint32)0x01 << 0U)
#define SPI_TX_FIFO_WRITE  ((uint32)0x01 << 1U)
#define SPI_TX_FIFO_UDR    ((uint32)0x01 << 2U)
#define SPI_RX_FIFO_OVR    ((uint32)0x01 << 3U)
#define SPI_TX_DMA_ERR     ((uint32)0x01 << 4U)
#define SPI_RX_DMA_ERR     ((uint32)0x01 << 5U)

/** \brief  bus status flags */
#define SPI_STATE_UNINIT       ((uint32)0x0)
#define SPI_STATE_INITED       ((uint32)0x1)
#define SPI_STATE_BUSY_TX      ((uint32)0x02)
#define SPI_STATE_BUSY_RX      ((uint32)0x04)
#define SPI_STATE_IRQ_ACT      ((uint32)0x08)
#define SPI_STATE_DMA_TX       ((uint32)0x10)
#define SPI_STATE_DMA_RX       ((uint32)0x20)
#define SPI_STATE_IRQ_TX       ((uint32)0x40)
#define SPI_STATE_IRQ_RX       ((uint32)0x80)
#define SPI_STATE_IS_SLAVE     ((uint32)0x100)
#define SPI_STATE_IS_UNS_EN    ((uint32)0x200)
#define SPI_STATE_ERR_END      ((uint32)0x400)
#define SPI_STATE_CS_ACTIVEED  ((uint32)0x800)
#define SPI_STATE_CS_INVLD_EN  ((uint32)0x1000)
#define SPI_STATE_EN_VLD_CS    ((uint32)0x2000)

/** \brief  irq event type flags */
#define SPI_TRASPORT_FINISH  ((uint32)0x01 << 0)
#define SPI_RX_READ_REQ      ((uint32)0x01 << 1)
#define SPI_TX_WRITE_REQ     ((uint32)0x01 << 2)
#define SPI_CS_INVLD_REQ     ((uint32)0x01 << 3)
#define SPI_TX_EMPTY_REQ     ((uint32)0x01 << 4)

#define BUS_BUSY_MASK   (SPI_STATE_BUSY_TX|SPI_STATE_BUSY_RX)
#define BUS_BUSY_DMA_MASK   (SPI_STATE_DMA_TX|SPI_STATE_DMA_RX)
#define BUS_BUSY_IRQ_MASK   (SPI_STATE_IRQ_TX|SPI_STATE_IRQ_RX)
#define BUS_FIFO_STATE_MASK (SPI_RX_FIFO_READ|SPI_TX_FIFO_WRITE|SPI_TX_FIFO_UDR|SPI_RX_FIFO_OVR)
#define BUS_FIFO_STATE_ERR_MASK (SPI_TX_FIFO_UDR|SPI_RX_FIFO_OVR|SPI_TX_DMA_ERR|SPI_RX_DMA_ERR)
#define BUS_BUSY_ASYNC_MASK    (BUS_BUSY_DMA_MASK|BUS_BUSY_IRQ_MASK)
#define BUS_BUSY_STATUS_MASK    (BUS_BUSY_MASK|BUS_BUSY_ASYNC_MASK)

#define SPI_STATE_EXT_FLAGS     (SPI_STATE_IS_UNS_EN | SPI_STATE_CS_ACTIVEED |\
                                SPI_STATE_CS_INVLD_EN | SPI_STATE_EN_VLD_CS)
/** \} */

struct mld_spi_module;
struct mld_spi_device;
struct mld_vector;
struct spi_dev_priv;
struct spi_bus_priv;
/**
 *  \addtogroup MCAL_SPI_CFG SPI Configuration.
 *  \{
 */
/********************************************************************************************************
 *                                  Global Types definition                                             *
 *******************************************************************************************************/
/** \brief  enum defining the transmission type */
enum spi_ops_mode
{
    OP_MODE_SYNC = 0,
    OP_MODE_ASYNC,
    OP_MODE_DMA,
};
/** \brief  Structure defining the hw transmission need funtions */
struct Spi_MldOps
{

    sint32 (*spiInit)(const struct mld_spi_module *bus);
    sint32 (*spiDeinit)(const struct mld_spi_module *bus);
    void (*spiWriteData)(const struct mld_spi_module  *bus, uint32 data);
    uint32 (*spiReadData)(const struct mld_spi_module  *bus);
    boolean (*spiCanWrite)(const struct mld_spi_module  *bus);
    boolean (*spiCanRead)(const struct mld_spi_module  *bus);

    void (*spiSetIrqMask)(const struct mld_spi_module  *bus, \
                          uint32 mask_type);
    void (*spiClrIrqState)(const struct mld_spi_module  *bus, uint32 clr);

    sint32 (*spiSetPerdevConfig)(const struct mld_spi_module *bus, \
                                 const struct mld_spi_device *dev);

    sint32 (*spiVectorTransmitReceive)(struct mld_spi_module  *bus, \
                                       const struct mld_spi_device *dev, \
                                       const struct mld_vector *vector);
    sint32 (*spiVectorTransmitReceiveIrq)(struct mld_spi_module  *bus, \
                                          const struct mld_spi_device *dev, \
                                          const struct mld_vector *vector);
    sint32 (*spiVectorTransmitReceiveDma)(struct mld_spi_module  *bus, \
                                          const struct mld_spi_device *dev, \
                                          const struct mld_vector *vector);
    uint32 (*spiGetIrqEvents)(const struct mld_spi_module *bus,
                              uint32 *const irq_status);
    void (*spiTransmitAbort)(struct mld_spi_module *bus);
    void (*spiRepeatCmd)(const struct mld_spi_module *bus,
                         const boolean is_last);
};
/** \brief  Structure defining the one spi channel */
struct mld_vector
{
    /* async mode need this*/
    uint32 len;
    /* prxdata */
    uint32 prxdata;
    /* ptxdata */
    uint32 ptxdata;
    /* data_width */
    uint8 widthType;
    /* transmitssion object device  */
    const struct mld_spi_device *dev;
    /* list to transmit */
    struct mld_vector *next;
    /* prxdata */
    uint32 rxCurr;
    /* ptxdata */
    uint32 txCurr;
    /* remain of this item */
    uint32 remain;
    /* once except of this item */
    uint32 expectLen;
    /* is ignore rx of up */
    boolean isRxDummy;
    /* is ignore tx of up */
    boolean isTxDummy;
};
/** \brief  Structure defining the mld bus object */
struct mld_spi_module
{
    volatile uint32 base;
    /* bus num */
    uint8 idx;
    /* status */
    uint32 state;
    /* spi common ops*/
    const struct Spi_MldOps *busOps;
    /* ip special params */
    struct spi_bus_priv *busPriv;
    /* soft cs pin id*/
    uint8 softCs;
    /* soft cs pin id*/
    Spi_PinModeType oldMux;
    /* asycn mode need this*/
    struct mld_vector async;
};
/** \brief  Structure defining the mld device object */
struct mld_spi_device
{
    /* spi bus ops*/
    struct mld_spi_module *bus;
    /* device special ops and params */
    struct spi_dev_priv *devPriv;
};
/** \} */
/**
 *  \addtogroup MCAL_SPI_API SPI Api.
 *  \{
 */
/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
/** *****************************************************************************************************
 * \brief This function attach a new pin as soft cs.
 *
 * \verbatim
 * Syntax             : void Spi_Mld_SetSoftCsId(
 *                      struct mld_spi_module *bus, uint8 pinid)
 *
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : bus - Pointer to mld bus object.
 *                      pinid - Pinid.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Attach a new pin as soft cs.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_011
 *******************************************************************************************************/
void Spi_Mld_SetSoftCsId(struct mld_spi_module *bus, uint8 pinid);
/** *****************************************************************************************************
 * \brief This function attach the params to device .
 *
 * \verbatim
 * Syntax             : void Spi_Mld_SetupDevicePrivParams(
 *                          struct mld_spi_device *dev,
 *                          struct spi_dev_priv *priv)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : dev - Pointer to extenal device object.
 *                      priv - per device params.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : set the mld device priv params.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_138
 *******************************************************************************************************/
void Spi_Mld_SetupDevicePrivParams(struct mld_spi_device *dev, struct spi_dev_priv *priv);
/** *****************************************************************************************************
 * \brief This function attach a new external device to bus.
 *
 * \verbatim
 * Syntax             : void Spi_Mld_DeviceAttachToBus(
 *                                      struct mld_spi_device *dev,
 *                                      struct mld_spi_module *bus,
 *                                      boolean is_hw_cs)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : dev - Pointer to device object
 *                      bus - Pointer to mld bus object
 *                      is_hw_cs - indict the device cs info is hw cs or not.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Set the per external device relevant register feild.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_138
 *******************************************************************************************************/
void Spi_Mld_DeviceAttachToBus(struct mld_spi_device *dev,struct mld_spi_module *bus,
                                        boolean is_hw_cs);
/** *****************************************************************************************************
 * \brief This function init mld bus object.
 *
 * \verbatim
 * Syntax             : void Spi_Mld_SetupBusPrivParams(
 *                      struct mld_spi_module *bus, uint32 base,
 *                      const struct Spi_MldOps *ops, void *busPriv)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : bus - Pointer to configuration set.
 *                      base - The Controller  register base address.
 *                      ops - Pointer to controller ops apis.
 *                      busPriv - per hw relevant params.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Init mld spi bus object.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_138
 *******************************************************************************************************/
void Spi_Mld_SetupBusPrivParams(struct mld_spi_module *bus, uint32 base,
        const struct Spi_MldOps *ops, struct spi_bus_priv *busPriv);
/** **************************************************************************************
 * \brief Init the bus object and hw cotroller.
 *
 * \verbatim
 * Syntax             : sint32 Spi_Mld_Init(struct mld_spi_module *bus)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : bus - Pointer to the bus object.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0: init pass.
 *                      other: init fail.
 *
 * Description        : init the bus object and hw cotroller.
 * \endverbatim
 * Traceability       : SWSR_SPI_138
 *****************************************************************************************/
sint32 Spi_Mld_Init(struct mld_spi_module *bus);
/** **************************************************************************************
 * \brief Deinit the bus object and hw cotroller.
 *
 * \verbatim
 * Syntax             : sint32 Spi_Mld_Deinit(struct mld_spi_module *bus)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : bus - Pointer to the bus object.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0: init pass.
 *                      other: init fail.
 *
 * Description        : Deinit the bus object and hw cotroller.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_147
 *****************************************************************************************/
sint32 Spi_Mld_Deinit(struct mld_spi_module *bus);
/** **************************************************************************************
 * \brief This function provides vectors transmission by sync mode.
 *
 * \verbatim
 * Syntax             : sint32 Spi_Mld_SyncVectorModeTransmitReceive(struct mld_spi_module *bus,
 *                                        const struct mld_spi_device *dev,
 *                                        struct mld_vector *vector)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : bus - Pointer to the bus object.
 *                      dev  - Pointer to the device object.
 *                      vector - Pointer to the vector object.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0: init pass.
 *                      other: init fail.
 *
 * Description        : This function provides vectors transmission by sync mode.
 * \endverbatim
 * Traceability       : SWSR_SPI_215
 *****************************************************************************************/
sint32 Spi_Mld_SyncVectorModeTransmitReceive(struct mld_spi_module *bus,
        const struct mld_spi_device *dev,
        struct mld_vector *vector);
/** **************************************************************************************
 * \brief This function provides vectors transmission by irq or pooling mode.
 *
 * \verbatim
 * Syntax             : sint32 Spi_Mld_AsyncVectorModeTransmitReceive(struct mld_spi_module *bus,
 *                             const struct mld_spi_device *dev,
 *                             struct mld_vector *vector)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : bus - Pointer to the bus object.
 *                      dev  - Pointer to the device object.
 *                      vector - Pointer to the vector object.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function provides vectors  transmission by irq or pooling mode.
 * \endverbatim
 * Traceability       : SWSR_SPI_164
 *****************************************************************************************/
sint32 Spi_Mld_AsyncVectorModeTransmitReceive(struct mld_spi_module *bus,
        const struct mld_spi_device *dev,
        struct mld_vector *vector);
/** **************************************************************************************
 * \brief This function provides vectors  transmission by dma mode.
 *
 * \verbatim
 * Syntax             : sint32 Spi_Mld_AsyncDmaVectorModeTransmitReceive(
 *                              struct mld_spi_module *bus,
 *                              const struct mld_spi_device *dev,
 *                              struct mld_vector *vector)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : bus - Pointer to the bus object.
 *                      dev  - Pointer to the device object.
 *                      vector - Pointer to the vector object.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function provides vectors  transmission by dma mode.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_164 SWSR_SPI_258
 *****************************************************************************************/
sint32 Spi_Mld_AsyncDmaVectorModeTransmitReceive(struct mld_spi_module *bus,
        const struct mld_spi_device *dev,
        struct mld_vector *vector);
/** **************************************************************************************
 * \brief This function will called by irq and polling mainfuntion.
 *
 * \verbatim
 * Syntax             : sint32 Spi_Mld_PollingHandle(struct mld_spi_module *bus)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Rentrant
 *
 * Parameters (in)    : bus - Pointer to the bus object.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0: transmission is finished .
 *                      1: transmission is going.
 *                      other: error .
 *
 * Description        : Handler fifo write and read for transmission and return the
 *                      transmisson status.
 * \endverbatim
 * Traceability       : SWSR_SPI_008 SWSR_SPI_009 SWSR_SPI_164 SWSR_SPI_258
 *****************************************************************************************/
sint32 Spi_Mld_PollingHandle(struct mld_spi_module *bus);
/** **************************************************************************************
 * \brief This function write the data to tx fifo.
 *
 * \verbatim
 * Syntax             : void Spi_Mld_WriteRemainData(struct mld_spi_module *bus)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : bus - Pointer to the bus object.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The funtion write the remain data to tx fifo onto fifo full or
 *                      finish writting.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_002 SWSR_SPI_020
 *****************************************************************************************/
void Spi_Mld_WriteRemainData(struct mld_spi_module *bus);
/** **************************************************************************************
 * \brief This function read the data from rx fifo.
 *
 * \verbatim
 * Syntax             : void Spi_Mld_ReadRemainData(struct mld_spi_module *bus)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : bus - Pointer to the bus object.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The funtion read the remain data from fifo onto rx fifo empty or not
 *                      remain data need read.
 * \endverbatim
 * Traceability       : SWSR_SPI_002 SWSR_SPI_020
 *****************************************************************************************/
void Spi_Mld_ReadRemainData(struct mld_spi_module *bus);

#ifdef __cplusplus
}
#endif
/** \} */

/** \} */

#endif

