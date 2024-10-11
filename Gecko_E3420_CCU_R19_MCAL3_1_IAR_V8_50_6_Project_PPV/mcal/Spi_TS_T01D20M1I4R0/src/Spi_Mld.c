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
 * \file     Spi_Mld.c
 * \brief    AUTOSAR 4.3.1 MCAL can Driver
 *
 * <table>
 * <tr><th>Date           <th>Version
 * <tr><td>2023/07/27     <td>1.0.0
 * </table>
 *****************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif
/*****************************************************************************************
 *                       Include header files
 *****************************************************************************************/
#include "Spi_Mld.h"
#include "Spi_Ip.h"

/*****************************************************************************************
 *                       Function Declarations
 *****************************************************************************************/
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

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
 * Traceability       : SWSR_SPI_138 SW_SM006
 *****************************************************************************************/
sint32 Spi_Mld_Init(struct mld_spi_module *bus)
{
    sint32 retValue;

    if (NULL_PTR != bus->busOps->spiInit)
    {
        /*#10 clear all state bits */
        bus->state = 0;
        /*#20 touch hwuint to init it */
        retValue = bus->busOps->spiInit(bus);

        if (ERR_NONE == retValue)
        {
            /*#30 hwuint init pass set the inited bit */
            bus->state |= SPI_STATE_INITED;
        }
        else
        {
            /*#40 hwuinit init fail return error to caller */
            SPI_DBG("%s error: %d\n", __FUNCTION__, retValue);
            retValue = -ERR_LOW_LEVEL;
        }
    }
    else
    {
        /*#50 Unexpected errors which may failure , return an error to the caller  */
        SPI_DBG("%s error no bus or ops \n", __FUNCTION__);
        retValue = -ERR_API_OPS;
    }

    return retValue;
}
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
 * Traceability       : SWSR_SPI_147 SW_SM006
 *****************************************************************************************/
sint32 Spi_Mld_Deinit(struct mld_spi_module *bus)
{
    sint32 retValue ;

    if (NULL_PTR != bus->busOps->spiDeinit)
    {
        /*#10 touch hwuint to deinit it */
        retValue = bus->busOps->spiDeinit(bus);

        if (ERR_NONE != retValue)
        {
            /*#20 low level operation fail return error to caller */
            SPI_DBG("%s error: %d\n", __FUNCTION__, retValue);
            retValue = -ERR_LOW_LEVEL;
        }
        else
        {
            /*#30 clear all state bits */
            bus->state = 0;
        }
    }
    else
    {
        /*#40 Unexpected errors which may failure , return an error to the caller  */
        SPI_DBG("%s error no bus or ops \n", __FUNCTION__);
        retValue = -ERR_NO_BUS;
    }

    return retValue;
}
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
 * Traceability       : SWSR_SPI_215 SW_SM006
 *****************************************************************************************/
sint32 Spi_Mld_SyncVectorModeTransmitReceive(struct mld_spi_module *bus,
        const struct mld_spi_device *dev,
        struct mld_vector *vector)
{
    uint32 cur;
    sint32 retValue = ERR_NONE;
    struct mld_vector *tmp;

    /*#10 Check if the low layer interface is implemented ?*/
    if (NULL_PTR == bus->busOps->spiVectorTransmitReceive)
    {
        retValue = -ERR_API_OPS;
        SPI_DBG("%s E:%d\n", __FUNCTION__, -ERR_API_OPS);
    } /** else is not needed*/

    /*#20 Checks if it is initialized */
    if ((uint32)0 == (bus->state & SPI_STATE_INITED))
    {
        retValue = -ERR_NO_INIT;
        SPI_DBG("%s E:%d\n", __FUNCTION__, -ERR_NO_INIT);
    }/** else is not needed*/

    /*#30 Checking if it's Busy */
    if ((uint32)0 != (bus->state & BUS_BUSY_MASK))
    {
        retValue = -ERR_BUSY;
        SPI_DBG("%s E:%d\n", __FUNCTION__, -ERR_BUSY);
    }/** else is not needed*/

    if (retValue == ERR_NONE)
    {
        /*
            #40 set the busy bits and initialized the vector item dev point to device
            object expectLen = 0 low layel will run first cmd case;
        */
        bus->state |= SPI_STATE_BUSY_TX | SPI_STATE_BUSY_RX;
        vector->dev = dev;
        vector->expectLen =  0;
        tmp = vector;

        /*
            #50 The three spi channels list as this
            vector->next(vector)->next(vector)->next==NULL_PTR;there do this link list
            transmission one by one.if anyone fail this list tansmission will
            abort and stop immediately.
        */
        do
        {
            retValue = bus->busOps->spiVectorTransmitReceive(bus, dev, tmp);

            if (0 <= retValue)
            {
                /*
                    #60 rx path is consistently half SCLK Cycle slower than Tx path
                    so assume  the rx state to
                    represent the current transferred state.
                */
                cur = bus->async.rxCurr;

                if (cur < bus->async.len)
                {
                    /*
                        #70 The vector len is greater than 1024 so need update the
                        cmd and continue transmit.
                    */
                    bus->async.remain = bus->async.len - cur;
                    tmp = &bus->async;
                }
                else
                {
                    /** #80 The current vector transfer is finished move to next. */
                    tmp = bus->async.next;

                    if (NULL_PTR != tmp)
                    {
                        tmp->expectLen = 0;
                        tmp->dev = dev;
                    } /** else is not needed */
                }
            }
            else
            {
                retValue = -ERR_LOW_LEVEL;
            }

            /*
                #90 Vector transmission done or anyone vector transmission
                fail over synchronous transmission.
            */
        }
        while ((tmp != NULL_PTR) && (retValue >= 0));

        /*
                    #110 The transmission abort the hwUinit status  most probable is unpredictable so
                    to avoid affecting the subsequent transmission, it is necessary to restore the
                    hardware state to be expected.
                */
        if (0 > retValue)
        {
            /*
                #120 restore the hardware state to be expected.
            */
            bus->busOps->spiTransmitAbort(bus);
            SPI_DBG("%s error: %d\n", __FUNCTION__, retValue);
        } /** else is not needed */

        /*
            #130 clear the busy bits whether the transmission fails or succeeds.
        */
        bus->state &= (uint32)(~(BUS_BUSY_MASK | SPI_STATE_EXT_FLAGS));
    }/** else is not needed*/

    return retValue;
}
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
 * Traceability       : SWSR_SPI_164 SW_SM006
 *****************************************************************************************/
sint32 Spi_Mld_AsyncVectorModeTransmitReceive(struct mld_spi_module *bus,
        const struct mld_spi_device *dev,
        struct mld_vector *vector)
{
    sint32 retValue = ERR_NONE;

    /*#10 Check if the low layer interface is implemented */
    if (NULL_PTR == bus->busOps->spiVectorTransmitReceiveIrq)
    {
        retValue = -ERR_API_OPS;
        SPI_DBG("%s E:%d\n", __FUNCTION__, -ERR_API_OPS);
    } /** else is not needed*/

    /*#20 Checks if it is initialized */
    if ((uint32)0 == (bus->state & SPI_STATE_INITED))
    {
        retValue = -ERR_NO_INIT;
        SPI_DBG("%s E:%d\n", __FUNCTION__, -ERR_NO_INIT);
    }/** else is not needed*/

    /*#30 Checking if it's Busy */
    if ((uint32)0 != (bus->state & BUS_BUSY_MASK))
    {
        retValue = -ERR_BUSY;
        SPI_DBG("%s E:%d\n", __FUNCTION__, -ERR_BUSY);
    }/** else is not needed*/

    if (ERR_NONE == retValue)
    {
        /*
            #40 set the busy bits and initialized the vector item dev point to device
            object expectLen = 0 low layel will run first cmd case;
        */
        bus->state |= BUS_BUSY_MASK;
        bus->state |= BUS_BUSY_IRQ_MASK;
        /*
            #50 The three spi channels list as this
            vector->next(vector)->next(vector)->next==NULL_PTR;Spi_Mld_AsyncTransmissionCore is responsible
            for switching to write a vector when the asynchronous transfer is complete,
            failures are handled by  Spi_Mld_AsyncTransmissionCore as well.
        */
        vector->dev = dev;
        vector->expectLen =  0;
        /*
            #60 Triggers an asynchronous transfer and then followed by irq or polling asynchronous handle.
        */
        retValue = bus->busOps->spiVectorTransmitReceiveIrq(bus, dev, vector);

        if (0 > retValue)
        {
            /*
                #70 restore the hardware state to be expected.
            */
            bus->busOps->spiTransmitAbort(bus);
            /*
                #80 clear the busy bits whether the transmission fails or succeeds.
            */
            bus->state &= (uint32)(~(BUS_BUSY_MASK | BUS_BUSY_IRQ_MASK | SPI_STATE_EXT_FLAGS));
            retValue = -ERR_LOW_LEVEL;
            SPI_DBG("%s error: %d\n", __FUNCTION__, retValue);
        } /** else is not needed */
    }/** else is not needed */

    return retValue;
}
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
 * Traceability       : SWSR_SPI_164 SWSR_SPI_258 SW_SM006
 *****************************************************************************************/
sint32 Spi_Mld_AsyncDmaVectorModeTransmitReceive(struct mld_spi_module *bus,
        const struct mld_spi_device *dev,
        struct mld_vector *vector)
{
    sint32 retValue = ERR_NONE;

    /*#10 Check if the low layer interface is implemented */
    if (NULL_PTR == bus->busOps->spiVectorTransmitReceiveDma)
    {
        retValue = -ERR_API_OPS;
        SPI_DBG("%s E:%d\n", __FUNCTION__, -ERR_API_OPS);
    } /** else is not needed*/

    /*#20 Checks if it is initialized */
    if ((uint32)0 == (bus->state & SPI_STATE_INITED))
    {
        retValue = -ERR_NO_INIT;
        SPI_DBG("%s E:%d\n", __FUNCTION__, -ERR_NO_INIT);
    }/** else is not needed*/

    /*#30 Checking if it's Busy */
    if ((uint32)0 != (bus->state & BUS_BUSY_MASK))
    {
        retValue = -ERR_BUSY;
        SPI_DBG("%s E:%d\n", __FUNCTION__, -ERR_BUSY);
    }/** else is not needed*/

    if (ERR_NONE == retValue)
    {
        /*
            #40 set the busy bits and initialized the vector item dev point to device
            object expectLen = 0 low layel will run first cmd case;
        */
        bus->state |= BUS_BUSY_MASK;
        bus->state |= BUS_BUSY_DMA_MASK;
        /*
            #50 The three spi channels list as this
            vector->next(vector)->next(vector)->next==NULL_PTR;Spi_Mld_AsyncTransmissionCore is responsible
            for switching to write a vector when the asynchronous transfer is complete,
            failures are handled by  Spi_Mld_AsyncTransmissionCore as well.
        */
        vector->dev = dev;
        vector->expectLen =  0;
        /*
            #60 Triggers an asynchronous transfer and then followed by irq or polling asynchronous handle.
        */
        retValue = bus->busOps->spiVectorTransmitReceiveDma(bus, dev, vector);

        if (0 > retValue)
        {
            /*
                #70 restore the hardware state to be expected.
            */
            bus->busOps->spiTransmitAbort(bus);
            /*
                #80 clear the busy bits whether the transmission fails or succeeds.
            */
            bus->state &= (uint32)(~(BUS_BUSY_MASK | BUS_BUSY_DMA_MASK | SPI_STATE_EXT_FLAGS));
            retValue = -ERR_LOW_LEVEL;
            SPI_DBG("%s error: %d\n", __FUNCTION__, retValue);
        }/** else is not needed */
    }/** else is not needed */

    return retValue;
}
/** **************************************************************************************
 * \brief This function handle the transmission exception case.
 *
 * \verbatim
 * Syntax             : static void Spi_Mld_ErrorHandle(struct mld_spi_module *bus)
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
 * Description        : The function used to recover spi and dma status from an exception.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_256
 *****************************************************************************************/
static void Spi_Mld_ErrorHandle(struct mld_spi_module *bus)
{
    bus->state &= (uint32)(~BUS_BUSY_STATUS_MASK);
    bus->state &= (uint32)(~SPI_STATE_EXT_FLAGS);
    bus->state |= SPI_STATE_ERR_END;
    bus->busOps->spiTransmitAbort(bus);
}
/** **************************************************************************************
 * \brief This function is the core process for async transmissions.
 *
 * \verbatim
 * Syntax             : static void Spi_Mld_AsyncTransmissionCore(struct mld_spi_module *bus)
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
 * Return value       : None
 *
 * Description        : The function get the controler status and used this info to write and
 *                      read the fifo for transfer.
 * \endverbatim
 * Traceability       : SWSR_SPI_008 SWSR_SPI_009 SWSR_SPI_164 SWSR_SPI_258 SW_SM006
 *****************************************************************************************/
static void Spi_Mld_AsyncTransmissionCore(struct mld_spi_module *bus)
{
    sint32 opsRet = ERR_NONE;
    uint32 irqState = 0, event;
    struct mld_vector *inherit;

    /*
        #10 Check if the low layer interface (spiGetIrqEvents and
        spiClrIrqState) is implemented ?
    */
    if (NULL_PTR == bus->busOps->spiGetIrqEvents)
    {

        SPI_DBG("%s E:%d\n", __FUNCTION__, -ERR_API_OPS);
    }
    else if (NULL_PTR == bus->busOps->spiClrIrqState)
    {

        SPI_DBG("%s E:%d\n", __FUNCTION__, -ERR_API_OPS);
    }
    else
    {
        /*
            #20 get the irq events
        */
        event = bus->busOps->spiGetIrqEvents(bus, &irqState);

        /*
            #30 error case need first to handle.
        */
        if ((uint32)0 != (event & BUS_FIFO_STATE_ERR_MASK))
        {
            Spi_Mld_ErrorHandle(bus);
            /* error case clean event ,status is save at spi->state */
            event = 0;
        }/** else is not needed */

        if ((uint32)0 == (bus->state & BUS_BUSY_DMA_MASK))
        {
            if ((uint32)0 != (event & SPI_TX_FIFO_WRITE))
            {
                /** #40 feed data to hw ,dma mode cpu do not need do this */
                Spi_Mld_WriteRemainData(bus);
            }/** else is not needed */

            if ((uint32)0 != (event & SPI_RX_FIFO_READ))
            {
                /** #50 feed data to hw ,dma mode cpu do not need do this */
                Spi_Mld_ReadRemainData(bus);
            }/** else is not needed */
        }/** else is not needed */

        if (bus->async.txCurr >= bus->async.expectLen)
        {
            /** #60 If Tx Path finished mask tx relevent irq source.*/
            bus->busOps->spiSetIrqMask(bus, SPI_TX_WRITE_REQ);
        }

        if (bus->async.rxCurr == bus->async.expectLen)
        {
            /** #70 If Rx Path finished mask all irq source. */
            bus->busOps->spiSetIrqMask(bus, SPI_TX_WRITE_REQ | SPI_RX_READ_REQ);

            /*
                #80 If current cmd transmission is complete;Check if the current vector needs a new cmd
                or if there are further vectors to be transferred.
            */
            if (bus->async.expectLen == bus->async.len)
            {
                /** #90 Current vector item end check next need to transmit ? */
                if (NULL_PTR == bus->async.next)
                {
                    /** #110 vector end and not have others  need to transmit.  */
                    bus->state &= (uint32)(~(SPI_STATE_DMA_RX | SPI_STATE_DMA_TX));
                    bus->state &= (uint32)(~(SPI_STATE_IRQ_RX | SPI_STATE_IRQ_TX));
                    bus->state &= (uint32)(~(SPI_STATE_BUSY_RX | SPI_STATE_BUSY_TX));
                    bus->state &= (uint32)(~SPI_STATE_CS_ACTIVEED);
                    SPI_DBG("%s bus%p transmission pass\n", __FUNCTION__, bus);
                }
                else
                {
                    /** #120 vector end and  have others  move to next vector . */
                    inherit = (struct mld_vector *)bus->async.next;
                    inherit->dev = bus->async.dev;
                    inherit->expectLen = 0;

                    /** #130 Check the transport mode to ensure that the same mode is used of new vector. */
                    if ((uint32)0 != (bus->state & BUS_BUSY_DMA_MASK))
                    {
                        opsRet = bus->busOps->spiVectorTransmitReceiveDma(\
                                 bus, bus->async.dev, bus->async.next);
                    }
                    else
                    {
                        opsRet = bus->busOps->spiVectorTransmitReceiveIrq(\
                                 bus, bus->async.dev, bus->async.next);
                    }
                }
            }
            else
            {
                /*
                    #140 Current vector not end need new cmd to transmit.
                    Update the remain data  expectLen keep last.
                */
                bus->async.remain = bus->async.len - bus->async.rxCurr;

                /*
                    #150 Check the transport mode to ensure that the same mode is used of last vector.
                */
                if ((uint32)0 != (bus->state & BUS_BUSY_DMA_MASK))
                {
                    opsRet = bus->busOps->spiVectorTransmitReceiveDma(\
                             bus, bus->async.dev, &bus->async);
                }
                else
                {
                    opsRet = bus->busOps->spiVectorTransmitReceiveIrq(\
                             bus, bus->async.dev, &bus->async);
                }
            }
        }

        /*
            #160 If the asynchronously setup interface return error set the asynchronous error bit.
        */
        if (0 > opsRet)
        {
            Spi_Mld_ErrorHandle(bus);
        }

        /** #170 Unconditionally clear interrupts to avoid interruption storms. */
        bus->busOps->spiClrIrqState(bus, irqState);
    }
}
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
sint32 Spi_Mld_PollingHandle(struct mld_spi_module *bus)
{
    sint32 retValue = 2;

    /** #10 if the bus is nor inited return error to caller */
    if ((uint32)0 != (bus->state & SPI_STATE_INITED))
    {
        /** #20 polling async transmission */
        if (0U != (bus->state & BUS_BUSY_ASYNC_MASK))
        {
            Spi_Mld_AsyncTransmissionCore(bus);

            /*
                #30 If current transmission done the up layer handle move to next vector;
                otherwise continue current transmitssion.
            */
            if ((uint32)0 != (bus->state & BUS_BUSY_ASYNC_MASK))
            {
                /** the transmit is no going */
                retValue = 1;
            }
            else
            {
                /** the transmisson is finished return 0 to caller,
                caller will handle job move case */
                retValue = 0;
            }
        }/*else is not needed */
    }
    else
    {
        /** not init */
        retValue = -ERR_NO_INIT;
        SPI_DBG("%s E:%d\n", __FUNCTION__, -ERR_NO_INIT);
    }

    return retValue;
}
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
void Spi_Mld_WriteRemainData(struct mld_spi_module *bus)
{
    boolean isLast;
    boolean canWrite;
    uint32 remain, data, address;
    sint32 retValue = ERR_NONE;

    const struct spi_dev_priv *dev_priv = bus->async.dev->devPriv;

    /*
        #10 Check if the low layer interface (spiCanWrite/spiRepeatCmd/spiWriteData)
        is implemented
    */
    if (NULL_PTR == bus->busOps->spiCanWrite)
    {
        retValue = -ERR_API_OPS;
    }/** else is not needed*/

    if (NULL_PTR == bus->busOps->spiRepeatCmd)
    {
        retValue = -ERR_API_OPS;
    }/** else is not needed*/

    if (NULL_PTR == bus->busOps->spiWriteData)
    {
        retValue = -ERR_API_OPS;
    }/** else is not needed*/

    if (retValue == ERR_NONE)
    {
        /** #20  Calculate the amount of data remaining to be sent */
        remain = bus->async.expectLen -  bus->async.txCurr;
        /*
            #30 Try to write the remaining data to be sent until the TxFIFO is
            full or the data is all  written.
        */
        canWrite = bus->busOps->spiCanWrite(bus);

        while ((remain > 0U) && (TRUE == canWrite))
        {
            if (FALSE == bus->async.isTxDummy)
            {
                address = bus->async.ptxdata + (bus->async.txCurr << bus->async.widthType);

                if (SPI_DATA_WIDTH_BYTE == bus->async.widthType)
                {
                    /*PRQA S 0306  1*/
                    data = *((uint8 *)address);
                }
                else if (SPI_DATA_WIDTH_HALF_WORD == bus->async.widthType)
                {
                    /*PRQA S 0306  1*/
                    data = *((uint16 *)address);
                }
                else
                {
                    /*PRQA S 0306  1*/
                    data = *((uint32 *)address);
                }
            }
            else
            {
                /*PRQA S 0306  1*/
                data =  *((uint32 *)bus->async.ptxdata);
            }

            bus->busOps->spiWriteData(bus, data);
            bus->async.txCurr++;
            remain--;

            /*
                #40  Cs Hold mode the FIFO the actual content is [cmd:data:cmd:data:.......].
            */
            if (0U != (dev_priv->flags & F_DEV_CLK_DELAY))
            {

                if (0U < remain)
                {
                    /*
                        #50 Because FIFO layout as [cmd:data:cmd:data:.......] so as long as
                        there is need to write a cmd before writing data.
                    */
                    /*PRQA S 4404 3*/
                    isLast =  ((remain == 1U) &&
                              (bus->async.next == NULL_PTR) &&
                              (bus->async.expectLen == bus->async.len));
                    /*
                       #60 update the cmd
                    */
                    bus->busOps->spiRepeatCmd(bus, isLast);
                }
            }

            canWrite = bus->busOps->spiCanWrite(bus);
        }
    }
}
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
void Spi_Mld_ReadRemainData(struct mld_spi_module *bus)
{
    boolean canRead;
    uint32 remain, address;
    sint32 retValue = ERR_NONE;

    /*
        #10 Check if the low layer interface (spiCanRead/spiReadData)
        is implemented
    */
    if (NULL_PTR == bus->busOps->spiReadData)
    {
        retValue = -ERR_API_OPS;
    }/** else is not needed*/

    if (NULL_PTR == bus->busOps->spiCanRead)
    {
        retValue = -ERR_API_OPS;
    }/** else is not needed*/

    if (retValue == ERR_NONE)
    {
        /*
           #20  Calculate the amount of data remaining to be read.
        */
        remain = bus->async.expectLen -  bus->async.rxCurr;
        /*
            #30 Try to read the remaining data to be received until the RxFIFO is
            empty or the data is all  received.
        */
        canRead = bus->busOps->spiCanRead(bus);

        while ((remain > 0U) && (TRUE == canRead))
        {
            if (FALSE == bus->async.isRxDummy)
            {
                address = bus->async.prxdata + (bus->async.rxCurr << bus->async.widthType);

                if (SPI_DATA_WIDTH_BYTE == bus->async.widthType)
                {
                    /*PRQA S 0306  1*/
                    *((uint8 *)address) = (uint8)bus->busOps->spiReadData(bus);
                }
                else if (SPI_DATA_WIDTH_HALF_WORD == bus->async.widthType)
                {
                    /*PRQA S 0306  1*/
                    *((uint16 *)address) = (uint16)bus->busOps->spiReadData(bus);
                }
                else
                {
                    /*PRQA S 0306  1*/
                    *((uint32 *)address) = bus->busOps->spiReadData(bus);
                }
            }
            else
            {
                (void)bus->busOps->spiReadData(bus);
            }

            bus->async.rxCurr++;
            remain--;
            canRead = bus->busOps->spiCanRead(bus);
        }
    }/** else is not needed*/
}
/** *****************************************************************************************************
 * \brief This function attach a new pin as soft cs.
 *
 * \verbatim
 * Syntax             : inline void Spi_Mld_SetSoftCsId(
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
void Spi_Mld_SetSoftCsId(struct mld_spi_module *bus, uint8 pinid)
{
    bus->softCs = pinid;
}
/** *****************************************************************************************************
 * \brief This function attach the params to device .
 *
 * \verbatim
 * Syntax             : inline  void Spi_Mld_SetupDevicePrivParams(
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
void Spi_Mld_SetupDevicePrivParams(struct mld_spi_device *dev, struct spi_dev_priv *priv)
{
    dev->devPriv = priv;
}
/** *****************************************************************************************************
 * \brief This function attach a new external device to bus.
 *
 * \verbatim
 * Syntax             : inline  void Spi_Mld_DeviceAttachToBus(
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
void Spi_Mld_DeviceAttachToBus(struct mld_spi_device *dev,struct mld_spi_module *bus,boolean is_hw_cs)
{
    dev->bus = bus;

    if ((TRUE == is_hw_cs) && (NULL_PTR != bus->busOps->spiSetPerdevConfig))
    {
        (void)bus->busOps->spiSetPerdevConfig(bus, dev);
    }/*else is not needed */
}
/** *****************************************************************************************************
 * \brief This function init mld bus object.
 *
 * \verbatim
 * Syntax             : inline  void Spi_Mld_SetupBusPrivParams(
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
void Spi_Mld_SetupBusPrivParams(struct mld_spi_module *bus, uint32 base,const struct Spi_MldOps *ops,
                                struct spi_bus_priv *busPriv)
{
    bus->base = base;
    bus->busOps = ops;
    bus->busPriv = busPriv;
    bus->softCs = 0xFF;
}
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#ifdef __cplusplus
}
#endif
/** End of file */
