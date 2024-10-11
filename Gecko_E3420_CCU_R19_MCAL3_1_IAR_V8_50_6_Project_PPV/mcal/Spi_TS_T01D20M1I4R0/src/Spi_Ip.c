/** *****************************************************************************************************
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
 *******************************************************************************************************/

/** *****************************************************************************************************
 * \file     Spi_Ip.c
 * \brief    AUTOSAR 4.3.1 MCAL Spi Driver
 *
 * <table>
 * <tr><th>Date           <th>Version
 * <tr><td>2023/07/25     <td>1.0.0
 * </table>
 *******************************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
/********************************************************************************************************
 *                                      Include header files
 *******************************************************************************************************/
#include "Mcal.h"
#include "Spi_reg.h"
#include "Spi_Ip.h"
#include "Spi_Cfg.h"
#include "RegHelper.h"
#include "Spi_Driver.h"
#include "Spi_Fault.h"
#if (SPI_ENABLE_DMA == STD_ON)
#include "Dma.h"
#endif
#define SPI_START_SEC_CONST_UNSPECIFIED
#include "Spi_MemMap.h"

#if (SPI_ENABLE_DMA == STD_ON)
/********************************************************************************************************
 *                                  Private Variable Definitions                                        *
 *******************************************************************************************************/
/*PRQA S 3218 4*/
/** \brief  this an an spi idx swap to dma instance id table */
static const Dma_PeripheralIdType Dma_ResTable[8] =
{
    DMA_CSIB1, DMA_CSIB2, DMA_CSIB3, DMA_CSIB4,
    DMA_CSIB5, DMA_CSIB6, DMA_CSIB7, DMA_CSIB8
};
/*PRQA S 3218 4*/
/** \brief  this is an dma beatsize table for differant datawidth */
static const Dma_BeatSizeType Dma_WidthTable[3] =
{
    DMA_BEAT_SIZE_1_BYTE, DMA_BEAT_SIZE_2_BYTE, DMA_BEAT_SIZE_4_BYTE
};
#endif
#define SPI_STOP_SEC_CONST_UNSPECIFIED
#include "Spi_MemMap.h"

#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

/** **************************************************************************************
 * \brief This function returns the device params check result.
 *
 * \verbatim
 * Syntax             : static sint32 Spi_Ip_ParamsCheckDevice(
 *                      const struct mld_spi_device *dev)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : dev - Pointer to mld device object.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This funtions used to check the device config params with
 *                      device init.
 * \endverbatim
 * Traceability       : SWSR_SPI_073
 *****************************************************************************************/
static sint32 Spi_Ip_ParamsCheckDevice(const struct mld_spi_device *dev)
{
    sint32 retValue = 0;
    const struct spi_dev_priv *dp;

    if (NULL_PTR == dev->devPriv)
    {
        retValue =  -1;
    }
    else
    {
        dp = dev->devPriv;

        if (dp->csIdx >= SPI_CS_IDX_MAX)
        {
            retValue =  -2;
        }/* else is not needed */
    }

    return retValue;
}
/** **************************************************************************************
 * \brief This function returns the the bus params check result.
 *
 * \verbatim
 * Syntax             : static sint32 Spi_Ip_ParamsCheckController(
 *                      const struct mld_spi_module *bus)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : bus - Pointer to mld bus object.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This funtions used to check the device config params with
 *                      bus init.
 * \endverbatim
 * Traceability       : SWSR_SPI_073
 *****************************************************************************************/
static sint32 Spi_Ip_ParamsCheckController(const struct mld_spi_module *bus)
{
    sint32 retValue = 0;

    if (NULL_PTR == bus->busPriv)
    {
        retValue = -1;
    }
    else if (0U == bus->base)
    {
        retValue = -1;
    }
    else
    {
        /* correct do nothing */
    }

    return retValue;
}
/** **************************************************************************************
 * \brief This function initialization the spi controller.
 *
 * \verbatim
 * Syntax             : static sint32 Spi_Ip_Init(const struct mld_spi_module *bus)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : configPtr - Pointer to the bus object.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 :Init pass.
 *                      other:Fail.
 *
 * Description        : Initialization the spi controller.
 * \endverbatim
 * Traceability       : SWSR_SPI_257 SW_SM005
 *****************************************************************************************/
static sint32 Spi_Ip_Init(const struct mld_spi_module *bus)
{
    sint32 retValue = 0;
    uint32 regVal, timeout;

    /* #10 necessary check */
    if ((sint32)0 != Spi_Ip_ParamsCheckController(bus))
    {
        retValue = -1;
    }
    else
    {
        /* #20 mask all irqs by default */
        writel(0xFFFF, bus->base + SPI_IRQ_MASK_OFF);
        /* #30 trig spi controller softrst */
        writel(BM_SPI_CTRL_SW_RST, bus->base + SPI_CTRL_OFF);

        /* #40 wait  controller clr softrst bit */
        for (timeout = 0; timeout < MAX_TIMEOUT_SWRST; timeout++ )
        {
            regVal = readl(bus->base + SPI_CTRL_OFF);

            if (0U == (regVal & BM_SPI_CTRL_SW_RST))
            {
                break;
            }/* else is not needed */
        }
        /* Error Inject Point */
        SpiFaultInj_Spi_Ip_Init();
        if (timeout == MAX_TIMEOUT_SWRST)
        {
            retValue = -2;
        }
        else
        {
            regVal = 0;
            /* #50 timeout and idle is must config as  4 ref will commonts */
            regVal |= FV_SPI_CTRL_TIMEOUT(4);
            regVal |= FV_SPI_CTRL_IDLE(4);
            writel(regVal, bus->base + SPI_CTRL_OFF);
            /* #60 mask all irqs  default */
            writel(0xFFFF, bus->base + SPI_IRQ_MASK_OFF);
            /*
                    #70 Set the Rx WML = 7 and Tx WML = 8 default;
                The Tx DMA Req always 8 burst and last transfer len depend on dma;
                The Rx DMA always 8 burst  when the rx fifo data num >= 8 and the last transfer depend on timeout/idle
                to trig the single req to finish the last but not over 7 datas transfer.
            */
            writel(FV_SPI_TX_FIFO_CTRL_THRD(SPI_FIFO_LEN_HALF),
                   bus->base + SPI_TX_FIFO_CTRL_OFF);
            writel(FV_SPI_RX_FIFO_CTRL_THRD(SPI_FIFO_LEN_HALF - 1U),
                   bus->base + SPI_RX_FIFO_CTRL_OFF);
            /*#70 enable spi controller default */
            writel(BM_SPI_EN_ENABLE, bus->base + SPI_EN_OFF);
        }
    }

    return retValue;
}
/** **************************************************************************************
 * \brief This function Recover the spi controller from exception.
 *
 * \verbatim
 * Syntax             : static sint32 Spi_Ip_Recover(const struct mld_spi_module *bus)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : configPtr - Pointer to the bus object.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 :DeInit pass.
 *                      other:Fail.
 *
 * Description        : Recover the spi controller from exception.
 * \endverbatim
 * Traceability       : SWSR_SPI_257 SWSR_SPI_036 SW_SM005
 *****************************************************************************************/
static sint32 Spi_Ip_Recover(const struct mld_spi_module *bus)
{
    sint32 retValue = 0;
    uint32 regVal, timeout, ctrlRegSaved;
    /* #10 disable spi  */
    writel((uint32)(~BM_SPI_EN_ENABLE), bus->base + SPI_EN_OFF);
    /* #20 disable all irqs  */
    writel(0xFFFF, bus->base + SPI_IRQ_MASK_OFF);
    /* #30 save the ctrl register val */
    ctrlRegSaved = readl(bus->base + SPI_CTRL_OFF);
    /* #40 trig spi controller softrst */
    writel(BM_SPI_CTRL_SW_RST, bus->base + SPI_CTRL_OFF);

    /* #50 wait  controller clr softrst bit */
    for (timeout = 0; timeout < MAX_TIMEOUT_SWRST; timeout++ )
    {
        regVal = readl(bus->base + SPI_CTRL_OFF);

        if (0U == (regVal & BM_SPI_CTRL_SW_RST))
        {
            break;
        }/* else is not needed */
    }

    if (timeout == MAX_TIMEOUT_SWRST)
    {
        retValue = -2;
    }
    else
    {
        /* #60  restore the ctrl register ,clear all irqs
            and msk all irq event;set en of controller.
        */
        writel(ctrlRegSaved, bus->base + SPI_CTRL_OFF);
        writel(0xFFFF, bus->base + SPI_IRQ_MASK_OFF);
        writel(0xFFFF, bus->base + SPI_IRQ_STAT_OFF);
        writel((uint32)(BM_SPI_EN_ENABLE), bus->base + SPI_EN_OFF);
    }

    return retValue;
}
/** **************************************************************************************
 * \brief This function deinitialization the spi controller.
 *
 * \verbatim
 * Syntax             : static sint32 Spi_Ip_Deinit(const struct mld_spi_module *bus)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : configPtr - Pointer to the bus object.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 :DeInit pass.
 *                      other:Fail.
 *
 * Description        : DeInitialization the spi controller.
 * \endverbatim
 * Traceability       : SWSR_SPI_257 SW_SM005
 *****************************************************************************************/
static sint32 Spi_Ip_Deinit(const struct mld_spi_module *bus)
{
    sint32 retValue = 0;
    uint32 timeout, regVal;
#if (SPI_ENABLE_DMA == STD_ON)
    struct spi_bus_priv *busPriv = (struct spi_bus_priv *)bus->busPriv;
    Dma_ChannelConfigType *dmaTxChan = busPriv->dmaChTx;
    Dma_ChannelConfigType *dmaRxChan = busPriv->dmaChRx;
#endif
    /* #10  clear all irqs and clear en of controller.*/
    writel(0xFFFF, bus->base + SPI_IRQ_MASK_OFF);
    /* #20 trig spi controller softrst */
    writel(BM_SPI_CTRL_SW_RST, bus->base + SPI_CTRL_OFF);

    /* #30 wait  controller clr softrst bit */
    for (timeout = 0; timeout < MAX_TIMEOUT_SWRST; timeout++ )
    {
        regVal = readl(bus->base + SPI_CTRL_OFF);

        if (0U == (regVal & BM_SPI_CTRL_SW_RST))
        {
            break;
        }/* else is not needed */
    }

    if (timeout == MAX_TIMEOUT_SWRST)
    {
        retValue = -2;
    }
    else
    {
        /* #40 clear all irqs and msk all irq event;
            disable controller. */
        writel(0xFFFF, bus->base + SPI_IRQ_MASK_OFF);
        writel(0xFFFF, bus->base + SPI_IRQ_STAT_OFF);
        writel((uint32)(~BM_SPI_EN_ENABLE), bus->base + SPI_EN_OFF);
#if (SPI_ENABLE_DMA == STD_ON)

        /* #50 free and stop all dma channels of this controller */
        if (NULL_PTR != dmaTxChan)
        {
            (void)Dma_Stop(dmaTxChan);
            (void)Dma_ReleaseChannel(dmaTxChan);
        }/* else is not needed */

        if (NULL_PTR != dmaRxChan)
        {
            (void)Dma_Stop(dmaRxChan);
            (void)Dma_ReleaseChannel(dmaRxChan);
        }/* else is not needed */

        /* #51 clr dma relevant status  */
        busPriv->dmaConfigured = 0;
        busPriv->dmaErr = 0;
#endif
    }

    return retValue;
}
/** **************************************************************************************
 * \brief This function set per device relevant bits.
 *
 * \verbatim
 * Syntax             : sint32 Spi_Ip_SetPerDevParameters(const struct mld_spi_module *bus,
 *                      const struct mld_spi_device *dev)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : configPtr - Pointer to the bus object.
 *                      dev - Pointer to the device object.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0:configurate pass
 *                      other:Fail.
 *
 * Description        : The function configuration the cs polarity for every cs signals.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_073
 *****************************************************************************************/
static  sint32 Spi_Ip_SetPerDevParameters(const struct mld_spi_module *bus,
        const struct mld_spi_device *dev)
{
    sint32 retValue = 0;
    uint32 ctrl ;
    const struct spi_dev_priv  *priv;

    /* #10 check the params */
    if (Spi_Ip_ParamsCheckDevice(dev) != 0)
    {
        SPI_DBG("bus%p not have dev params or params illegal.\n", bus);
        retValue = -1;
    }
    else
    {
        priv = dev->devPriv;
        /* #20 if the chip select polarity is high set the relevant
        bit to 1 otherwise set it to 0 */
        ctrl = readl(bus->base + SPI_CTRL_OFF);

        if (0U != (priv->flags & F_DEV_NSS_HIGH))
        {
            ctrl |= (FM_SPI_CTRL_NSS_POL & ((uint32)0x01 << (priv->csIdx + 8U)));
        }
        else
        {
            ctrl &= (~((uint32)0x01 << (priv->csIdx + 8U)));
        }

        writel(ctrl, bus->base + SPI_CTRL_OFF);
    }

    return retValue;
}
/** **************************************************************************************
 * \brief This function write a data ti tx fifo.
 *
 * \verbatim
 * Syntax             : static void Spi_Ip_FifoWrite(
 *                      const struct mld_spi_module  *bus,
 *                      const uint32 data)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : bus - Pointer to bus object.
 *                      data - The data write to tx fifo.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The function write an data to tx fifo.
 *
 * \endverbatim
 * Traceability       :SWSR_SPI_009
 *****************************************************************************************/
static void Spi_Ip_FifoWrite(const struct mld_spi_module  *bus, const uint32 data)
{
    /* #10 write the data to fifo ,high bits discarder by hardware when they noused */
    writel(data, bus->base + SPI_TX_FIFO_DATA_OFF);
}
/** **************************************************************************************
 * \brief This function returns data read from rx fifo.
 *
 * \verbatim
 * Syntax             : static uint32 Spi_Ip_FifoRead(const struct mld_spi_module  *bus)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : bus - Pointer to mld bus object.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : the data read from rx fifo.
 *
 * Description        : The function read a data from rx fifo.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_009
 *****************************************************************************************/
static uint32 Spi_Ip_FifoRead(const struct mld_spi_module  *bus)
{
    /* #10 read data from fifo,high bits discarder by software when they noused */
    return readl(bus->base + SPI_RX_FIFO_DATA_OFF);
}
/** **************************************************************************************
 * \brief This function returns the tx fifo status.
 *
 * \verbatim
 * Syntax             : static boolean Spi_Ip_FifoCanWrite(
 *                      const struct mld_spi_module  *bus)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : bus - Pointer to mld bus object
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : FALSE: Tx fifo is full can't to write.
 *                      TRUE: Tx fifo have spece to write .
 *
 * Description        : The function to get the tx fifo status and retuan can write or not.
 *
 * \endverbatim
 * Traceability       : SWSR SWSR_XXX_xxx
 *****************************************************************************************/
static boolean Spi_Ip_FifoCanWrite(const struct mld_spi_module  *bus)
{
    /*
        #10 Master mode rx fifo full the controller will stop send so only need check tx fifo status ;
        In transmission hold mode, need ensure that there are two free space for writing.
    */
    boolean retValue;

    const struct spi_dev_priv *devPriv = bus->async.dev->devPriv;

    uint32 regVal = readl(bus->base + SPI_FIFO_STAT_OFF);

    if (((struct spi_dev_priv *)0 != devPriv) &&
            (0U != (devPriv->flags & F_DEV_CLK_DELAY)))
    {
        /*PRQA S 4404 2*/
        /* #20 if cs hold mode enable make sure there are two free space for write */
        retValue = ((SPI_FIFO_LEN - 2U) > (FM_SPI_FIFO_STAT_TX_FIFO_DPTR & regVal));
    }
    else
    {
        /*PRQA S 4404 2*/
        /* #30 if cs hold mode disable make sure there have free space for write */
        retValue = (0U == ( regVal & BM_SPI_FIFO_STAT_TX_FULL ));
    }

    return retValue;
}
/** **************************************************************************************
 * \brief This function return the rx fifo status.
 *
 * \verbatim
 * Syntax             : static boolean Spi_Ip_FifoCanRead(const struct mld_spi_module  *bus)
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
 * Return value       : FALSE:The rx fifo is empty.
 *                      TRUE:The rx fifo is not empty.
 *
 * Description        : The funtion return True is means that the rx fifo have
 *                      data can read.
 * \endverbatim
 * Traceability       : SWSR_SPI_009
 *****************************************************************************************/
static boolean Spi_Ip_FifoCanRead(const struct mld_spi_module  *bus)
{
    /* #10 rx fifo not empty can read fifo */
    uint32 regVal = readl(bus->base + SPI_FIFO_STAT_OFF);
    /*PRQA S 4404 1*/
    return (0U == (regVal & BM_SPI_FIFO_STAT_RX_EMPTY));
}
/** **************************************************************************************
 * \brief This function to disable the spi dma request bits.
 *
 * \verbatim
 * Syntax             : static inline void Spi_Ip_DisableDmaRequest(
 *                      const struct mld_spi_module  *bus,
 *                      const uint32 flags)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : bus - Pointer to mld bus object.
 *                        flags - The Dma type hot code.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : When the transmission over the dma request need disable
 *                      separately by this function.
 *
 * \endverbatim
 * Traceability       :SWSR_SPI_258
 *****************************************************************************************/
static inline void Spi_Ip_DisableDmaRequest(const struct mld_spi_module  *bus, const uint32 flags)
{
    uint32 regVal;
    regVal = readl(bus->base + SPI_CTRL_OFF);

    /* #10 disable the rx dma request */
    if (0U != (flags & SPI_DMA_RX_ENABLE))
    {
        regVal &= (uint32)(~BM_SPI_CTRL_RX_DMA_EN);
        SPI_DBG("spi_dma rx disable\n");
    }/* else is not needed */

    /* #20 disable the tx dma request */
    if (0U != (flags & SPI_DMA_TX_ENABLE))
    {
        regVal &= (uint32)(~BM_SPI_CTRL_TX_DMA_EN);
        SPI_DBG("spi_dma tx disable\n");
    }/* else is not needed */

    writel(regVal, bus->base + SPI_CTRL_OFF);
}
#if (SPI_ENABLE_DMA == STD_ON)
/** **************************************************************************************
 * \brief This function is the dma transfer finished callback handle.
 *
 * \verbatim
 * Syntax             : static void Spi_Ip_DmaHandle(Dma_ControllerStatusType dmaStat, void *context)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : dmaStat - Dma transfer result.
 *                        context - Point to the user special handle.
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : When one dma channel transfer finished dma driver will call this funtion.
 * \endverbatim
 * Traceability       : SWSR_SPI_023 SWSR_SPI_258
 *****************************************************************************************/
static void Spi_Ip_DmaHandle(Dma_ControllerStatusType dmaStat, void *context)
{
    uint32 xferBytes;
    Dma_ChannelConfigType *chan = (Dma_ChannelConfigType *)context;
    struct mld_spi_module  *bus = (struct mld_spi_module *)chan->context;
    struct spi_bus_priv *busPriv = (struct spi_bus_priv *)bus->busPriv;
    uint8 widthShift = bus->async.widthType;
    /*
        #10 dma stop whether the transfer is pass or not.
    */
    (void)Dma_Stop(chan);
    /* Error Inject Point */
    SpiFaultInj_Spi_Ip_DmaHandleDmaStatusErr();
    if (DMA_COMPLETED == dmaStat)
    {
        /* The dma transmission is done */
        if (context == busPriv->dmaChRx)
        {
            SPI_DBG("bus%d dma rx.\n", bus->idx);
            /* #20 When rx is done, tx must also be done is rx done tx done disable all DMA request */
            Spi_Ip_DisableDmaRequest(bus, SPI_DMA_RX_ENABLE | SPI_DMA_TX_ENABLE);

            if (bus->async.isRxDummy != TRUE)
            {
#if (SPI_NO_CACHEABLE_NEEDED == STD_OFF)
                /* #30 invalidate current rx tansfer mem rang dcache*/
                Dma_InvalidateCache(bus->async.prxdata + (bus->async.rxCurr << widthShift),
                                    SPI_ROUNDUP(((bus->async.expectLen - bus->async.rxCurr) << widthShift), SPI_CACHE_LINE));
#endif
            }/* else is not needed */

            /* #40 get transfer info of curuent dma channel  */
            xferBytes = Dma_GetXferBytes(busPriv->dmaChRx, TRUE);
            xferBytes = xferBytes >> widthShift;
            /* Error Inject Point */
            SpiFaultInj_Spi_Ip_DmaHandleRxLenthErr();
            /* #50 check transfer info of curuent dma channel;
                if not meeting expectations mark asynchronous exceptions,otherwish update tranfer status.
            */
            if ((bus->async.expectLen - bus->async.rxCurr ) != xferBytes)
            {
                busPriv->dmaErr |= SPI_RX_DMA_ERR;
            }
            else
            {
                bus->async.rxCurr += xferBytes;
                bus->async.remain = bus->async.len - bus->async.rxCurr;
            }
        }
        else if (context == busPriv->dmaChTx)
        {
            SPI_DBG("bus%d dma tx.\n", bus->idx);
            /*
                #60 Tx Finish the rx high probability still in transit so only disable tx DMA Request.
            */
            Spi_Ip_DisableDmaRequest(bus, SPI_DMA_TX_ENABLE);
            /* # 80 get transfer info of curuent dma channel  */
            xferBytes = Dma_GetXferBytes(busPriv->dmaChTx, TRUE);
            xferBytes = xferBytes >> widthShift;
            /* Error Inject Point */
            SpiFaultInj_Spi_Ip_DmaHandleTxLenthErr();
            /* # 90 check transfer info of curuent dma channel;
                if not meeting expectations mark asynchronous exceptions,otherwish update tranfer status.
            */
            if ((bus->async.expectLen - bus->async.txCurr ) != xferBytes)
            {
                busPriv->dmaErr |= SPI_TX_DMA_ERR;
            }
            else
            {
                bus->async.txCurr += xferBytes;
                bus->async.remain = bus->async.len - bus->async.txCurr;
            }
        }
        else
        {
            /* do nothing,not meeting expectations maybe is a Bug? */
        }
    }
    else
    {
        /*
            DMA_IN_PROGRESS,
            DMA_PAUSED,
            DMA_ERR,
            DMA_PENDING,
            DMA_MAD_CRC_ERROR,
            DMA_PENDING DMA_PAUSED as error case.
        */
        if (context == busPriv->dmaChTx)
        {
            busPriv->dmaErr |= SPI_TX_DMA_ERR;
        }
        else
        {
            busPriv->dmaErr |= SPI_RX_DMA_ERR;
        }

        /*
            #100 Disable all DMA Request ,this time the Tx DMA Burst Request is actived.
        */
        Spi_Ip_DisableDmaRequest(bus, SPI_DMA_RX_ENABLE | SPI_DMA_TX_ENABLE);
    }

    /* #110 polling the async transmit,continue or move to next job */
    Spi_HwMainFunctionHandling(bus->idx);
}
#endif
/*PRQA S 3673  27*/
/** **************************************************************************************
 * \brief This function use to handle transmission abort.
 *
 * \verbatim
 * Syntax             : static void Spi_Ip_TransmitAbort(struct mld_spi_module  *bus)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : configPtr - Pointer to mld bus object.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : when an transmitssion abort call this to handle exception and
 *                      recover relevant hw (Spi and Dma) for next transfer.
 * \endverbatim
 * Traceability       : SWSR_SPI_036
 *****************************************************************************************/
static void Spi_Ip_TransmitAbort(struct mld_spi_module  *bus)
{
#if (SPI_ENABLE_DMA == STD_ON)
    uint32 xferBytes;
    uint8 widthShift = bus->async.widthType;
    struct spi_bus_priv *busPriv = (struct spi_bus_priv *)bus->busPriv;
#endif
    /* #10 disable all dma requests src */
    Spi_Ip_DisableDmaRequest(bus, SPI_DMA_RX_ENABLE | SPI_DMA_TX_ENABLE);
#if (SPI_ENABLE_DMA == STD_ON)

    /* #20 stop rx and update the transfer status,do not invalidate cache */
    if (NULL_PTR != busPriv->dmaChRx)
    {
        (void)Dma_Stop(busPriv->dmaChRx);
        xferBytes = Dma_GetXferBytes(busPriv->dmaChRx, TRUE);
        xferBytes >>= widthShift;
        bus->async.rxCurr = xferBytes;
        /* #30 read the data of the remaining in fifo is insufficient water level */
        Spi_Mld_ReadRemainData(bus);
    }

    /* #40 stop tx dma and update the tx status */
    if (NULL_PTR != busPriv->dmaChTx)
    {
        (void)Dma_Stop(busPriv->dmaChTx);
        xferBytes = Dma_GetXferBytes(busPriv->dmaChTx, TRUE);
        xferBytes >>= widthShift;
        bus->async.txCurr = xferBytes;
    }
#endif
    /* #50 reset the controller */
    (void)Spi_Ip_Recover(bus);
}
#if (SPI_ENABLE_DMA == STD_ON)
/** **************************************************************************************
 * \brief This function returns the version information of this module.
 *
 * \verbatim
 * Syntax             : static inline void Spi_Ip_EnableDmaRequest(
 *                      const struct mld_spi_module  *bus)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : bus - Pointer to mld bus boject.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : When the Dma channels config pass call this to enable dma request of
 *                      Spi.
 * \endverbatim
 * Traceability       : SWSR_SPI_258
 *****************************************************************************************/
static inline void Spi_Ip_EnableDmaRequest(const struct mld_spi_module  *bus)
{
    uint32 regVal;
    /* #10 enable rx and tx dma request  */
    regVal = readl(bus->base + SPI_CTRL_OFF);
    regVal |= BM_SPI_CTRL_RX_DMA_EN;
    regVal |= BM_SPI_CTRL_TX_DMA_EN;
    writel(regVal, bus->base + SPI_CTRL_OFF);
}
#endif
/** **************************************************************************************
 * \brief This function setup the irqs of spi for tramsmission.
 *
 * \verbatim
 * Syntax             : static void Spi_Ip_SetupIrqforAsyncTransmit(
 *                      const struct mld_spi_module *bus)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : bus - Pointer to mld bus boject.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The function setup the irq mask of spi.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_164
 *****************************************************************************************/
static void Spi_Ip_SetupIrqforAsyncTransmit(const struct mld_spi_module *bus)
{
    uint32 regVal;
    /*#10 defaut mask all interrupt if in polling mode */
    regVal = 0xFFFF;
    const struct spi_bus_priv  *busPriv = (struct spi_bus_priv *)bus->busPriv;

    /*#20 if enable irq unmask relevant interrupt  */
    if (SPI_IRQ_ENABLE == (busPriv->flags & SPI_IRQ_ENABLE))
    {
        /* irq mode unmask tx pre-empty interrupt*/
        regVal &= (uint32)(~BM_SPI_IRQ_MASK_TX_FIFO_PRE_EMPTY);
        /* irq mode unmask rx fifo prefull and frm_done interrupt
            frm_done irq for residue data that not over wml.
        */
        regVal &= (uint32)(~BM_SPI_IRQ_MASK_RX_FIFO_PRE_FULL);
        regVal &= (uint32)(~BM_SPI_IRQ_MASK_FRM_DONE);
    }/* else is not needed */

    SPI_DBG("%s Irq Msk:%08x\n", __FUNCTION__, regVal);

    writel(regVal, bus->base + SPI_IRQ_MASK_OFF);
}
/** **************************************************************************************
 * \brief This function returns the version information of this module.
 *
 * \verbatim
 * Syntax             : void Spi_Ip_SetIrqMask(
 *                      const struct mld_spi_module  *bus,
 *                      const uint32 irq_mask)
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
 * Description        : When the transmission finished call this to disable the irqs.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_168
 *****************************************************************************************/
static void Spi_Ip_SetIrqMask(const struct mld_spi_module  *bus, const uint32 irq_mask)
{
    uint32 regVal = readl(bus->base + SPI_IRQ_MASK_OFF);

    /* #10 Rx Finished the transmission is over need mask all relevant irqs */
    if (0U != (irq_mask & SPI_RX_READ_REQ))
    {
        regVal |= BM_SPI_IRQ_MASK_FRM_DONE;
        regVal |= BM_SPI_IRQ_MASK_TX_FIFO_PRE_EMPTY;
        regVal |= BM_SPI_IRQ_MASK_RX_FIFO_PRE_FULL;
    }/*else is not needed */

    /* #20 only tx finished the rx  probability not done only mask tx relevant irqs. */
    if (0U != (irq_mask & SPI_TX_WRITE_REQ))
    {
        regVal |= BM_SPI_IRQ_MASK_TX_FIFO_PRE_EMPTY;
    }/* else is not needed */

    SPI_DBG("%s reg:%08x\n", __FUNCTION__, regVal);
    writel(regVal, bus->base + SPI_IRQ_MASK_OFF);
}
#if (SPI_ENABLE_DMA == STD_ON)
/** **************************************************************************************
 * \brief This function returns the dma params check result.
 *
 * \verbatim
 * Syntax             : static sint32 Spi_Ip_DmaTransferCheck(
 *                                  const Dma_ChannelConfigType *dmaRxChan,
 *                                  const Dma_ChannelConfigType *dmaTxChan,
 *                                    const struct mld_vector *transmit)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : dmaRxChan - Pointer to rx dma chan handle.
 *                        dmaTxChan - Pointer to tx dma chan handle.
 *                        transmit - Pointer to curent vectors.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0: Check is pass.
 *                        Other:Fail.
 *
 * Description        : Check the buffer align size and dma chan status is OK?
 * \endverbatim
 * Traceability       : SWSR_SPI_028 SWSR_SPI_258
 *****************************************************************************************/
static sint32 Spi_Ip_DmaTransferCheck(const Dma_ChannelConfigType *dmaRxChan,
                                      const Dma_ChannelConfigType *dmaTxChan,
                                      const struct mld_vector *transmit)
{
    sint32  retValue;

    /* #10 if dma channel is allocation fail or buffer align error return error */
    if (NULL_PTR == dmaRxChan)
    {
        retValue =  -1;
    }
    else if (NULL_PTR == dmaTxChan)
    {
        retValue = -2;
    }
#if (SPI_NO_CACHEABLE_NEEDED == STD_OFF)
    else if (TRUE != transmit->isRxDummy &&
             FALSE == SPI_IS_ALIGNED(transmit->prxdata, SPI_CACHE_LINE))
    {
        /* rx is not dummy need align to 32bytes */
        retValue = -3;
    }
    else if (TRUE != transmit->isTxDummy &&
             FALSE == SPI_IS_ALIGNED(transmit->ptxdata, SPI_CACHE_LINE))
    {
        /* tx is not dummy need align to 32bytes */
        retValue = -4;
    }
#endif
    else
    {
        retValue = 0;
    }

    return retValue;
}
/** **************************************************************************************
 * \brief Initial the dma relevant channel for current transmission .
 *
 * \verbatim
 * Syntax             : static sint32 Spi_Ip_ConfigDmaChannel(struct mld_spi_module *bus)
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
 * Return value       : 0:dma chan configurate pass.
 *                        other:fail.
 *
 * Description        : Initial the dma relevant channel for current transmission .
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_002 SWSR_SPI_258
 *****************************************************************************************/
static sint32 Spi_Ip_ConfigDmaChannel(struct mld_spi_module *bus)
{

    sint32 retValue;
    Std_ReturnType dmaTxRetValue;
    Std_ReturnType dmaRxRetValue;
    Dma_DeviceConfigType dmaCfgs;
    Dma_ChannelConfigType *dmaRxChan = NULL_PTR;
    Dma_ChannelConfigType *dmaTxChan = NULL_PTR;
    Dma_BeatSizeType dmaWidth;
    Dma_InstanceConfigType dmaStaticCfgs;
    Dma_UpdateTransmissionType updateTranxferCfg;
    uint32 ptrRxData, ptrTxData, dmaXferBytes;
    const struct mld_vector *transmit = &bus->async;
    struct spi_bus_priv *priv = (struct spi_bus_priv *)bus->busPriv;

    uint8 sizeBytesShift = transmit->widthType;
    dmaWidth = Dma_WidthTable[transmit->widthType];
    Dma_BurstType rxDstInc = DMA_BURST_INCREMENTAL;
    Dma_BurstType txSrcInc = DMA_BURST_INCREMENTAL;

    /* #10 if the dma channel has configured befor only need fast retrige,
    otherwise need alloc and do first init for channel */
    if (1U == priv->dmaConfigured)
    {
        /* get dma channel */
        dmaTxChan = priv->dmaChTx;
        dmaRxChan = priv->dmaChRx;
    }
    else
    {
        /* alloc dma channel  */
        if (E_OK == Dma_GetConfigParams(Dma_ResTable[bus->idx], DMA_SPI_TX, DMA_MODULE_SPI, &dmaStaticCfgs))
        {
            dmaTxChan = Dma_RequestChannelWithId(dmaStaticCfgs.controller, dmaStaticCfgs.channelId);
            priv->dmaChTx = dmaTxChan;
        }

        if (E_OK == Dma_GetConfigParams(Dma_ResTable[bus->idx], DMA_SPI_RX, DMA_MODULE_SPI, &dmaStaticCfgs))
        {
            dmaRxChan = Dma_RequestChannelWithId(dmaStaticCfgs.controller, dmaStaticCfgs.channelId);
            priv->dmaChRx = dmaRxChan;
        }
    }

    /* 20 check the dma relevant params */
    retValue = Spi_Ip_DmaTransferCheck(dmaRxChan, dmaTxChan, transmit);

    /* #30 if params check pass do config otherwise return error to caller */
    if (0 == retValue)
    {
        /* #40 Explicit the information of dma transmission */
        ptrTxData = transmit->ptxdata + (transmit->txCurr << sizeBytesShift);
        ptrRxData = transmit->prxdata + (transmit->rxCurr << sizeBytesShift);
        dmaXferBytes = (transmit->expectLen - transmit->rxCurr) << sizeBytesShift;
        /* #50 if the tx or rx is dummy buffer inc fixed */
        if (TRUE == transmit->isTxDummy)
        {
            txSrcInc = DMA_BURST_FIXED;
            ptrTxData= transmit->ptxdata;
        }/* else is not needed */

        if (TRUE == transmit->isRxDummy)
        {
            rxDstInc = DMA_BURST_FIXED;
            ptrRxData= transmit->prxdata;
        }/* else is not needed */
        if (0U == priv->dmaConfigured)
        {
            /* #60 first init dma channel ,so need to config all params and call dma chan init;
            Because of the high time cost of dma channel configuration, only dma is fully configured
            for the first time, and only transmission information is updated later */
            dmaTxChan->context = (void *)bus;
            dmaTxChan->irqCallback = (Dma_IrqHandle)Spi_Ip_DmaHandle;
            (void)Dma_InitConfigChannel(&dmaCfgs);
            dmaCfgs.direction = DMA_MEMORY_TO_DEVICE;
            dmaCfgs.processMode = DMA_INTERRUPT;
            dmaCfgs.srcAddress  = Mcal_AddressConvert(ptrTxData);
            dmaCfgs.dstAddress = bus->base + SPI_TX_FIFO_DATA_OFF;
            dmaCfgs.srcBusWidth = dmaWidth;
            dmaCfgs.dstBusWidth = dmaWidth;
            dmaCfgs.srcMaxBurst = DMA_BURST_LENGTH_8;
            dmaCfgs.dstMaxBurst = DMA_BURST_LENGTH_8;
            dmaCfgs.srcPortSelect = DMA_PORT_AXI64;
            dmaCfgs.dstPortSelect = DMA_PORT_AHB32;
            dmaCfgs.srcIncDirection = txSrcInc;
            dmaCfgs.dstIncDirection = DMA_BURST_FIXED;
            dmaCfgs.loopMode = DMA_LOOP_MODE_2;
            dmaCfgs.flowControl = DMA_DIR_MEMORY_TO_DEVICE;
            dmaCfgs.transaction = DMA_DEVICE;

            dmaCfgs.transferMode = DMA_TRANSFER_MODE_SINGLE;
            dmaCfgs.linkListTriggerMode = DMA_TRIGGER_BY_HARDWARE;
            (void)Dma_ConfigChannel(dmaTxChan, &dmaCfgs);
            dmaTxRetValue = Dma_PrepareTransmission(dmaTxChan, dmaXferBytes);
            dmaRxChan->context = (void *)bus;
            dmaRxChan->irqCallback = (Dma_IrqHandle)Spi_Ip_DmaHandle;
            (void)Dma_InitConfigChannel(&dmaCfgs);

            dmaCfgs.direction = DMA_DEVICE_TO_MEMORY;
            dmaCfgs.processMode = DMA_INTERRUPT;
            dmaCfgs.srcAddress  = bus->base + SPI_RX_FIFO_DATA_OFF;
            dmaCfgs.dstAddress = Mcal_AddressConvert(ptrRxData);
            dmaCfgs.srcBusWidth = dmaWidth;
            dmaCfgs.dstBusWidth = dmaWidth;
            dmaCfgs.srcMaxBurst = DMA_BURST_LENGTH_8;
            dmaCfgs.dstMaxBurst = DMA_BURST_LENGTH_8;
            dmaCfgs.srcPortSelect = DMA_PORT_AHB32;
            dmaCfgs.dstPortSelect = DMA_PORT_AXI64;
            dmaCfgs.srcIncDirection = DMA_BURST_FIXED;
            dmaCfgs.dstIncDirection = rxDstInc;
            dmaCfgs.loopMode = DMA_LOOP_MODE_2;
            dmaCfgs.flowControl = DMA_DIR_DEVICE_TO_MEMORY;
            dmaCfgs.transferMode = DMA_TRANSFER_MODE_SINGLE;
            dmaCfgs.linkListTriggerMode = DMA_TRIGGER_BY_HARDWARE;
            dmaCfgs.transaction = DMA_DEVICE;

            (void)Dma_ConfigChannel(dmaRxChan, &dmaCfgs);
            dmaRxRetValue = Dma_PrepareTransmission(dmaRxChan, dmaXferBytes);

        }
        else
        {
            /* #70 fast retrige dma transfer */
            updateTranxferCfg.srcAddress = bus->base + SPI_RX_FIFO_DATA_OFF;
            updateTranxferCfg.dstAddress = ptrRxData;
            updateTranxferCfg.srcIncDirection = DMA_BURST_FIXED;
            updateTranxferCfg.dstIncDirection = rxDstInc;
            updateTranxferCfg.srcBusWidth = dmaWidth;
            updateTranxferCfg.dstBusWidth = dmaWidth;
            dmaRxRetValue = Dma_UpdateTransmitAddressAndLength(
                                priv->dmaChRx, &updateTranxferCfg, dmaXferBytes);
            updateTranxferCfg.srcAddress = ptrTxData;
            updateTranxferCfg.dstAddress = bus->base + SPI_TX_FIFO_DATA_OFF;
            updateTranxferCfg.srcIncDirection = txSrcInc;
            updateTranxferCfg.dstIncDirection = DMA_BURST_FIXED;
            updateTranxferCfg.srcBusWidth = dmaWidth;
            updateTranxferCfg.dstBusWidth = dmaWidth;
            dmaTxRetValue = Dma_UpdateTransmitAddressAndLength(
                                priv->dmaChTx, &updateTranxferCfg, dmaXferBytes);

        }

        if (E_OK == dmaTxRetValue && E_OK == dmaRxRetValue)
        {
            /* #80 set the dma channel status as configured */
            priv->dmaConfigured = 1;
#if (SPI_NO_CACHEABLE_NEEDED == STD_OFF)
            /* #90 clean the dcache ,clear cache data to main memory */
            Dma_CleanCache(ptrTxData, SPI_ROUNDUP(dmaXferBytes, SPI_CACHE_LINE));
#endif
            /*
              rx buffer flush cache reason:
                1. when the buffer size is not integer multiple of cache line size invalidate
                   may result in data loss.
                2. when the rx buffer cache flush by cache swap will cause mem write
                   confilct between CPU and DMA.
            */
            if (TRUE != transmit->isRxDummy)
            {
#if (SPI_NO_CACHEABLE_NEEDED == STD_OFF)
                /* #100 clean the dcache ,clear cache data to main memory */
                Dma_FlushCache(ptrRxData, SPI_ROUNDUP(dmaXferBytes, SPI_CACHE_LINE));
#endif
            }
            /* clean last error status */
            priv->dmaErr = 0;
            /* 110 Read Simultaneous Clear Transfer Count Register */
            (void)Dma_GetXferBytes(dmaRxChan, TRUE);
            dmaRxRetValue = Dma_Start(dmaRxChan);
            (void)Dma_GetXferBytes(dmaTxChan, TRUE);
            dmaTxRetValue = Dma_Start(dmaTxChan);
        }/* else is not needed */

        /* Error Inject Point */
        SpiFaultInj_Spi_Ip_ConfigDmaChannelErr();

        if (E_OK != dmaRxRetValue || E_OK != dmaTxRetValue)
        {
            retValue = -10;
            /* #120 dma channal init fail stop dma and return error to caller */
            (void)Dma_Stop(dmaRxChan);
            (void)Dma_Stop(dmaTxChan);
        }/* else is not needed */
    }

    SPI_DUMMY_STATEMENT(rxDstInc);
    SPI_DUMMY_STATEMENT(txSrcInc);
    return retValue;
}
#endif
/** **************************************************************************************
 * \brief This function wirte cmd to spi.
 *
 * \verbatim
 * Syntax             : static void Spi_Ip_NotFirstWriteCmd(
 *                      struct mld_spi_module  *bus)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : bus - Pointer to mld bus object.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Generate the cmd of transmission and write it to fifo.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_168 SWSR_SPI_215
 *****************************************************************************************/
static void Spi_Ip_NotFirstWriteCmd(struct mld_spi_module  *bus)
{
    const struct spi_dev_priv *devPriv;
    struct spi_bus_priv *busPriv = (struct spi_bus_priv *)bus->busPriv;
    /* #10 get last cmd val */
    uint32 cmd = busPriv->lastCmd;
    devPriv = bus->async.dev->devPriv;
    /* #20 clear the fream size filed and default do not set last bit. */
    cmd &= (uint32)(~FM_SPI_CMD_CTRL_FRAM_SIZE);
    cmd &= (uint32)~BM_SPI_CMD_CTRL_LAST;

    if (SPI_FREAM_SIZE_MAX < bus->async.remain)
    {
        /* #30 remain data greater than 1024 set fream size field as 1024 and keep clear the last bit */
        cmd |= FV_SPI_CMD_CTRL_FRAM_SIZE(SPI_FREAM_SIZE_MAX - 1U);
        bus->async.expectLen += SPI_FREAM_SIZE_MAX;
    }
    else
    {
        /* #40 less than 1024 than set fream size field as len-1 */
        cmd |= FV_SPI_CMD_CTRL_FRAM_SIZE(bus->async.remain - 1U);
        bus->async.expectLen += bus->async.remain;

        if (NULL_PTR == bus->async.next)
        {
            /* #50 the transmission do not have other vector items set the last bit */
            cmd |= BM_SPI_CMD_CTRL_LAST;
        }
        else
        {
            /* #60 the transmission have other vector items keep clear the last bit */
        }
    }

    if (0U != (devPriv->flags & F_DEV_CLK_DELAY))
    {
        /* #70 cs Hold mode the fream_size keep set as 0 (means 1). */
        cmd &= (uint32)(~FM_SPI_CMD_CTRL_FRAM_SIZE);

        /*
            #80 if the length of transmition is equel to 1 the last bit must keepping(set at #50 ) otherwise
            clean the last bit for cs hold mode.
        */
        if (bus->async.remain != SPI_FREAM_SIZE_MIN)
        {
            cmd &= (uint32)~BM_SPI_CMD_CTRL_LAST;
        }
        else
        {
            /*
                #90 default last is not set only remian < 1024 and no next vector to transmit the
                last will be set(set at #50 ), in cs hold mode last bit only set at last word so
                keep the last bit set.
            */
        }
    }/* else not needed */

    /*
        #100  write cmd register the controller there is no need to wait for the FIFO
    to have space to write, because working in full-duplex
    mode Rx ends TxFIFO must have space to write.
    */
    writel(cmd, bus->base + SPI_TX_FIFO_CMD_OFF);
    /*
        #110 record the cmd register cs hold mode need read this ,read from registers should be forbidden
        because it is possible to read a zero value
    */
    busPriv->lastCmd = cmd;

    SPI_DBG("updata cmd %08x \n", cmd);
}
/** **************************************************************************************
 * \brief This function write the cmd to spi.
 *
 * \verbatim
 * Syntax             : void Spi_IpFirstWriteCmd(struct mld_spi_module  *bus,
 *                      const struct spi_dev_priv *config)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : bus - Pointer to mld bus object.
 *                        config - Pointer to mld bus object.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Generate the first cmd of transmission and write it to fifo.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_215 SWSR_SPI_168
 *****************************************************************************************/
static void Spi_IpFirstWriteCmd(struct mld_spi_module  *bus, const struct spi_dev_priv *config)
{
    uint32 cmd = 0U, regVal;

    struct spi_bus_priv *busPriv = (struct spi_bus_priv *)bus->busPriv;

    /* #10 select the bit order of this transmit.*/
    if (0U != (config->flags & F_DEV_LSB))
    {
        cmd |= BM_SPI_CMD_CTRL_LSB;
    }/* else is not needed */

    /* #20 select tim mode order of this transmit. */
    if ( SCPO0_SCPH1 == config->mode)
    {
        cmd |= BM_SPI_CMD_CTRL_SPI_CPHA;
    }
    else if (  SCPO1_SCPH0 == config->mode)
    {
        cmd |= BM_SPI_CMD_CTRL_SPI_CPOL;
    }
    else if (  SCPO1_SCPH1 == config->mode)
    {
        cmd |= BM_SPI_CMD_CTRL_SPI_CPHA | BM_SPI_CMD_CTRL_SPI_CPOL;
    }
    else
    {
        /* No Action Required */
    }

    /* #30 fream size setup
       case 1 the len is greater than 1024.
       case 2 the len is less than 1024.
    */
    if (SPI_FREAM_SIZE_MAX < bus->async.len)
    {
        /* #40 greater than 1024 set fream size field as 1024 and keep clear the last bit */
        cmd |= FV_SPI_CMD_CTRL_FRAM_SIZE(SPI_FREAM_SIZE_MAX - 1U);
        bus->async.expectLen = SPI_FREAM_SIZE_MAX;
    }
    else
    {
        /* #50 less than 1024 set fream size field as len-1 */
        cmd |= FV_SPI_CMD_CTRL_FRAM_SIZE(bus->async.len - 1U);
        bus->async.expectLen = bus->async.len;

        if (NULL_PTR == bus->async.next)
        {
            /* #60 the transmission do not have other vector items set the last bit */
            cmd |= BM_SPI_CMD_CTRL_LAST;
        }
        else
        {
            /* #70 the transmission have other vector items keep clear the last bit */
        }
    }

    /* #80 setup the word width/baudrate division/cs id */
    cmd |= FV_SPI_CMD_CTRL_WORD_SIZE((uint32)config->width - 1U);
    cmd |= FV_SPI_CMD_CTRL_PRESSCALE((uint32)config->baudRateDivisor);
    cmd |= FV_SPI_CMD_CTRL_NSS((uint32)config->csIdx);

    /* #90 cs Hold mode the fream_size set as 0(means 1) */
    if (0U != (config->flags & F_DEV_CLK_DELAY))
    {
        cmd &= (uint32)~FM_SPI_CMD_CTRL_FRAM_SIZE;

        /*
            #100 if the length of transmition is equel to 1 the last bit must keepping otherwise
            clean the last bit for cs hold mode.
        */
        if (bus->async.len !=  SPI_FREAM_SIZE_MIN)
        {
            cmd &= (uint32)~BM_SPI_CMD_CTRL_LAST;
        }/* else not needed */
    }/* else is not needed */

    /*
        #110  write cmd register the controller there is no need to wait for the FIFO
    to have space to write, because working in full-duplex
    mode Rx ends TxFIFO must have space to write.
    */
    writel(cmd, bus->base + SPI_TX_FIFO_CMD_OFF);
    /*
        #120 record the cmd register cs hold mode need read this ,read from registers should be forbidden
        because it is possible to read a zero value
    */
    busPriv->lastCmd = cmd;
    /*
        #130 The controller is support miso sample delay half sclk sycle,
        if need enable sample point delay otherwise disable and this configuration
        only update at transmission start.
    */
    regVal = readl(bus->base + SPI_CTRL_OFF);

    if (0U != (config->flags & F_DEV_MISO_DELAY))
    {
        regVal |= BM_SPI_CTRL_SAMPLE_POINT;
    }
    else
    {
        regVal &= (uint32)(~BM_SPI_CTRL_SAMPLE_POINT);
    }

    writel(regVal, bus->base + SPI_CTRL_OFF);

    SPI_DBG("first cmd %08x\n", cmd);
}
/** **************************************************************************************
 * \brief This function use in cs hold mode repeat write cmd.
 *
 * \verbatim
 * Syntax             : void Spi_Ip_CsHoldRepeatCmd(
 *                      const struct mld_spi_module *bus,
 *                      const boolean is_last)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : bus - Pointer to mld bus object.
 *                        config - Pointer to mld bus object.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Cs Hold mode need repeat cmd between datas,call this function to
 *                      write corret cmd to spi.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_168 SWSR_SPI_215
 *****************************************************************************************/
static void Spi_Ip_CsHoldRepeatCmd(const struct mld_spi_module *bus, const boolean is_last)
{
    /* #10 get last cmd from variable hw register is unuseful */
    uint32 cmd = ((struct spi_bus_priv *)bus->busPriv)->lastCmd;
    /* #20 default clear th last and fream size */
    cmd &= (uint32)~BM_SPI_CMD_CTRL_LAST;
    cmd &= (uint32)~FM_SPI_CMD_CTRL_FRAM_SIZE;

    /* #30 if TRUE last cmd set the last bit */
    if (TRUE == is_last)
    {
        cmd |= BM_SPI_CMD_CTRL_LAST;
    }/* else is not needed */

    /* #40 update cmd to fifo */
    writel(cmd, bus->base + SPI_TX_FIFO_CMD_OFF);
}
/** *****************************************************************************************************
 * \brief This function attach the new vector to bus.
 *
 * \verbatim
 * Syntax             : void Spi_Mld_SyncMoveToNextVector( const struct mld_vector *src,
 *                                                          struct mld_vector *dst)
 *
 * Service ID[hex]    : 0x00
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : src - Pointer to new vector item.
 *                      dst - Pointer to bus transmit vector.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : first start transmit need copy the channel head vector to bus.
 *
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_007
 *******************************************************************************************************/
static void Spi_Mld_SyncMoveToNextVector( const struct mld_vector *src,
        struct mld_vector *dst)
{
    dst->len = src->len;
    dst->next = src->next;
    dst->prxdata = src->prxdata;
    dst->ptxdata = src->ptxdata;
    dst->widthType = src->widthType;
    dst->dev = src->dev;
    /* the dst is on purpose */
    dst->remain = dst->len;
    dst->rxCurr = 0;
    dst->txCurr = 0;
    dst->isRxDummy = src->isRxDummy;
    dst->isTxDummy = src->isTxDummy;
}
/** **************************************************************************************
 * \brief This function all types of transfers are handled.
 *
 * \verbatim
 * Syntax             : static sint32 Spi_Ip_VectorModeTransmissionCore(struct mld_spi_module  *bus,
 *                            const struct mld_spi_device *dev,
 *                            const struct mld_vector *transmit,
 *                            const enum spi_ops_mode mode)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : bus - Pointer to mld bus object.
 *                      dev - Pointer to mld bus object.
 *                      transmit - Pointer to the first vector item .
 *                      mode - transmit mode eg:DMA,ASYNC(IRQ),SYNC
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0:issue transmission pass.
 *                      others: fail.
 *
 * Description        : This is the core function of the transmission setup, which is
 *                      mainly responsible for the configuration of cmd and interrupt, dma and
 *                      other related registers.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_257 SW_SM005
 *****************************************************************************************/
static sint32 Spi_Ip_VectorModeTransmissionCore(struct mld_spi_module  *bus,
        const struct mld_spi_device *dev,
        const struct mld_vector *transmit,
        const enum spi_ops_mode mode)
{
#if (SPI_ENABLE_DMA == STD_ON)
    sint32  dma_ops = 0;
#endif
    sint32 retValue = 0;
    uint32 timeoutCnt, timeout, fsmSta;
    const struct spi_dev_priv *dev_mode = dev->devPriv;

    /* #10 expectLen == 0  first vector transmit generate cmd for current vector list. */
    if (0U == transmit->expectLen)
    {
        /* #20 sync vector item to bus async block */
        Spi_Mld_SyncMoveToNextVector(transmit, &bus->async);
        /* #30 config Timing only at first vector start */
        writel(dev_mode->timCtrl, bus->base + SPI_TIM_CTRL_OFF);
        /* #40 write first cmd */
        Spi_IpFirstWriteCmd(bus, dev_mode);

        /* #50 is this device is attach at soft cs pin? */
        if (F_DEV_NSS_SOFT == (dev_mode->flags & F_DEV_NSS_SOFT))
        {
            /* #60 is the soft cs already actived */
            if (SPI_STATE_CS_ACTIVEED != (bus->state & SPI_STATE_CS_ACTIVEED))
            {
                timeoutCnt = BUS_FSM_RDY_TIMEOUT(dev_mode->baudRateDivisor);

                /* #80 Software CS needs to wait for the SPI sync pad status to be ready */
                for (; timeoutCnt > 0U; timeoutCnt--)
                {
                    fsmSta = GFV_SPI_IRQ_STAT_SPI_FSM_ST(readl(bus->base + SPI_IRQ_STAT_OFF));

                    if ((fsmSta == SPI_FSM_WAIT_DATA_STA) || (fsmSta == SPI_FSM_M_STR_STA) ||
                            (fsmSta == SPI_FSM_IDLE_STA))
                    {
                        break;
                    }
                }
                /* Error Inject Point */
                SpiFaultInj_Spi_Ip_VectorModeTransmissionCoreSoftCSTimeOut();
                /* #90 is timeout ? if TRUE flags error and return  */
                if (0U == timeoutCnt)
                {
                    retValue =  -1;
                }
                else
                {
                    /* Soft Cs  active after spi mode switch ready */
                    if (0U != (dev_mode->flags & F_DEV_NSS_HIGH))
                    {
                        Spi_SetIOLevel(bus->softCs, STD_HIGH);
                    }
                    else
                    {
                        Spi_SetIOLevel(bus->softCs, STD_LOW);
                    }

                    /*set flags of Soft Cs  active */
                    bus->state |= SPI_STATE_CS_ACTIVEED;
                }
            }
            else
            {
                /* soft Cs is already asserted */
            }
        }
    }
    else
    {
        /* #100 vector transmit continue only update cmd portion field such as fram size and last bit */
        Spi_Ip_NotFirstWriteCmd(bus);
    }

    if (retValue == 0)
    {
        SPI_DBG("tx:%p rx:%p\n", bus->async.ptxdata, bus->async.ptxdata);

        if (OP_MODE_SYNC == mode)
        {
            SPI_DBG("Normal mode \n");
            /*
                #110 per ward ready need max width+start+1+fream+1+end+1 + 10 cycles call sum_cycle
                1us at 50M need 50 sclk cycles
                once register read time : 4 * APB cycle at 200M  = (1/200 us * 4) = (4/200)us
                once sclk cycle = 200*(n+1)/50 APB sycles  n is Prescaler value;
                so:
                times = 200*(n+1)*sum_cycle/4*50 = 2000*(n+1)/200  = sum_cycle*(n+1);
            */
            timeout = BUS_FIFO_PERWARD_TIMEOUT(dev_mode->timCtrl,
                                               (uint32)dev_mode->baudRateDivisor, dev_mode->width);

            /* If the transmit is not finished continue read and write fifo */
            while ((bus->async.txCurr < bus->async.expectLen) ||
                    (bus->async.rxCurr < bus->async.expectLen))
            {
                timeoutCnt = timeout;
                /* #120write fifo until tx fifo full */
                Spi_Mld_WriteRemainData(bus);
                /* #130 Read the rx fifo until fifo empty */
                Spi_Mld_ReadRemainData(bus);

                /* #140 Read the rx fifo avoid rx fifo full cause tansmission stop until the txfifo
                have space to write  */
                for (; ((boolean)0 == Spi_Ip_FifoCanWrite(bus)) && (timeoutCnt > 0U);
                        timeoutCnt--)
                {
                    Spi_Mld_ReadRemainData(bus);
                }
                /* Error Inject Point */
                SpiFaultInj_Spi_Ip_VectorModeTransmissionCoreReadTooMuch();
                /* #150 Is timeout ? */
                if (0U == timeoutCnt)
                {
                    retValue = -2;
                    break;
                }/*else is not needed */
            }

            SPI_DBG("w %d r %d e %d\n", bus->async.txCurr, bus->async.rxCurr, bus->async.expectLen);
        }
        else if (OP_MODE_ASYNC == mode)
        {
            SPI_DBG("Irq mode\n");
            /* #160 setup the irq event to drive the async transmission */
            Spi_Ip_SetupIrqforAsyncTransmit(bus);
        }
        else
        {
            /* #170 configurate the dma register for current transmitssion */
            SPI_DBG("DMA mode \n");
#if (SPI_ENABLE_DMA == STD_ON)
            dma_ops = Spi_Ip_ConfigDmaChannel(bus);

            if (dma_ops >= 0)
            {
                /* #180 configurate pass enable dma request */
                Spi_Ip_EnableDmaRequest(bus);
            }
            else
            {
                /* #190 setup dma fail,need mask all irq avoid sync Mode enable irqs. */
                retValue = -3;
            }

#else
            retValue = -3;
#endif
        }
    }/* else is not needed */

    return retValue;
}
/** **************************************************************************************
 * \brief This function provided synchronous transmission service for up layer.
 *
 * \verbatim
 * Syntax             : sint32 Spi_Ip_SyncVectorModeTransmitReceive(
 *                          struct mld_spi_module  *bus,
 *                            const struct mld_spi_device *dev,
 *                            const struct mld_vector *vector)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : bus - Pointer to mld bus object.
 *                      dev - Pointer to mld bus object.
 *                      vector - Pointer to the first vector item .
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Synchronous transmission ip level implementation.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_168
 *****************************************************************************************/
static sint32 Spi_Ip_SyncVectorModeTransmitReceive(struct mld_spi_module  *bus,
        const struct mld_spi_device *dev, const struct mld_vector *vector)
{
    /* #10 call Spi_Ip_VectorModeTransmissionCore in sync mode */
    return Spi_Ip_VectorModeTransmissionCore(bus, dev, vector, OP_MODE_SYNC);
}
/** **************************************************************************************
 * \brief This function provided asynchronous transmission service(irq) for up layer.
 *
 * \verbatim
 * Syntax             : static sint32 Spi_Ip_AsyncVectorModeTransmitReceive(
 *                      struct mld_spi_module  *bus,
 *                      const struct mld_spi_device *dev,
 *                      const struct mld_vector *vector)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : bus - Pointer to mld bus object.
 *                      dev - Pointer to mld bus object.
 *                      vector - Pointer to the first vector item .
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0:issue transmission pass.
 *                      others:issue transmission Fail.
 *
 * Description        : Asynchronous transmission(Irq) ip level implementation
 * \endverbatim
 * Traceability       : SWSR_SPI_164
 *****************************************************************************************/
static sint32 Spi_Ip_AsyncVectorModeTransmitReceive(struct mld_spi_module  *bus,
        const struct mld_spi_device *dev, const struct mld_vector *vector)
{
    /* #10 call Spi_Ip_VectorModeTransmissionCore in async mode poling or irq */
    return Spi_Ip_VectorModeTransmissionCore(bus, dev, vector, OP_MODE_ASYNC);
}
/** **************************************************************************************
 * \brief This function provided asynchronous transmission service(Dma) for up layer.
 *
 * \verbatim
 * Syntax             : static sint32 Spi_Ip_AsyncDmaVectorModeTransmitReceive(
 *                          struct mld_spi_module  *bus,
 *                          const struct mld_spi_device *dev,
 *                          const struct mld_vector *vector)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : bus - Pointer to mld bus object.
 *                      dev - Pointer to mld bus object.
 *                      vector - Pointer to the first vector item .
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0:issue transmission pass.
 *                      others:issue transmission Fail.
 *
 * Description        : DAsynchronous transmission(Dma) ip level implementation
 * \endverbatim
 * Traceability       : SWSR_SPI_164
 *****************************************************************************************/
static sint32 Spi_Ip_AsyncDmaVectorModeTransmitReceive(struct mld_spi_module  *bus,
        const struct mld_spi_device *dev, const struct mld_vector *vector)
{
    /* #10 call Spi_Ip_VectorModeTransmissionCore in async mode by dma */
    return Spi_Ip_VectorModeTransmissionCore(bus, dev, vector, OP_MODE_DMA);
}
/** **************************************************************************************
 * \brief This function returns the version information of this module.
 *
 * \verbatim
 * Syntax             : uint32 Spi_Ip_GetIrqStatus(
 *                      const struct mld_spi_module  *bus,
 *                      uint32 *const reg_vel)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : bus - Pointer to mld bus object.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : reg_vel - row irq rester status.
 *
 * Return value       : None
 *
 * Description        : Get the spi irq evnets an return events hot code.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_164 SW_SM004
 *****************************************************************************************/
static uint32 Spi_Ip_GetIrqStatus(const struct mld_spi_module  *bus, uint32 *const reg_vel)
{
    uint32 retValue = 0;
#if (SPI_ENABLE_DMA == STD_ON)
    const struct spi_bus_priv *busPriv = (struct spi_bus_priv *)bus->busPriv;
#endif
    /* #10 get spi controller hw irq event */
    uint32 irq_s = readl(bus->base + SPI_IRQ_STAT_OFF);
    /* #20 save the irq status raw val for clr */
    *reg_vel = irq_s;

    SPI_DBG("%p sta:%08x \n", bus, irq_s);
    /* #30 every irq assumes that both TxFIFO and RxFIFO need to be processed */
    retValue |=  SPI_RX_FIFO_READ | SPI_TX_FIFO_WRITE;
#if (SPI_ENABLE_DMA == STD_ON)
    /* #40 get async dma error for async core  */
    retValue |= busPriv->dmaErr;
#endif
    SPI_DBG("%s retValue:%08x\n", __FUNCTION__, retValue);
    /* return event status  */
    return retValue;
}
/** **************************************************************************************
 * \brief This function returns the version information of this module.
 *
 * \verbatim
 * Syntax             : void Spi_Ip_ClearIrqState(
 *                           const struct mld_spi_module  *bus,
 *                           const uint32 clr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : bus - Pointer to mld bus object.
 *                      clr - The irq stauts want to clean.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : clean the specify irq status.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_164
 *****************************************************************************************/
static void Spi_Ip_ClearIrqState(const struct mld_spi_module  *bus, const uint32 clr)
{
    /* #10 clean the irq events ,the events raw status from Spi_Ip_GetIrqStatus */
    writel(clr, bus->base + SPI_IRQ_STAT_OFF);
}

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#define SPI_START_SEC_CONST_UNSPECIFIED
#include "Spi_MemMap.h"
/********************************************************************************************************
 *                                  Global Variable Declarations                                        *
 *******************************************************************************************************/
/*PRQA S 1533 4*/
/** \brief  This is the spi hw relevant ops apis handle */
const struct Spi_MldOps Spi_IpOps =
{
    .spiInit = Spi_Ip_Init,
    .spiDeinit = Spi_Ip_Deinit,
    .spiVectorTransmitReceive = Spi_Ip_SyncVectorModeTransmitReceive,
    .spiVectorTransmitReceiveIrq = Spi_Ip_AsyncVectorModeTransmitReceive,
    .spiVectorTransmitReceiveDma = Spi_Ip_AsyncDmaVectorModeTransmitReceive,
    .spiWriteData = Spi_Ip_FifoWrite,
    .spiReadData = Spi_Ip_FifoRead,
    .spiCanWrite = Spi_Ip_FifoCanWrite,
    .spiCanRead = Spi_Ip_FifoCanRead,
    .spiGetIrqEvents = Spi_Ip_GetIrqStatus,
    .spiSetIrqMask = Spi_Ip_SetIrqMask,
    .spiClrIrqState = Spi_Ip_ClearIrqState,
    .spiSetPerdevConfig = Spi_Ip_SetPerDevParameters,
    .spiTransmitAbort = Spi_Ip_TransmitAbort,
    .spiRepeatCmd = Spi_Ip_CsHoldRepeatCmd,
};

#define SPI_STOP_SEC_CONST_UNSPECIFIED
#include "Spi_MemMap.h"

#ifdef __cplusplus
}
#endif
/* End of file */
