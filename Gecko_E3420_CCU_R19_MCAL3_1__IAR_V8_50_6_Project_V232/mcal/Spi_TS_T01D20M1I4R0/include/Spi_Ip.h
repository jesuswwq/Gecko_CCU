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
 *  \file     Spi_Ip.h
 *  \brief    This file contains interface header for CAN MCAL driver
 *
 * <table>
 * <tr><th>Date           <th>Version
 * <tr><td>2023/07/27     <td>1.0.0
 * </table>
 *****************************************************************************************/
#ifndef SPI_IP_H_
#define SPI_IP_H_

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
#include "Spi_Cfg.h"
#include "Spi_Mld.h"
#include "Spi_Types.h"
#if (SPI_ENABLE_DMA == STD_ON)
#include "Dma.h"
#endif
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
/** \brief  Driver IP relevant marcos */
#define  SPI_DATA_WIDTH_MIN 4U
#define  SPI_DATA_WIDTH_MAX 32U
#define  SPI_FREAM_SIZE_MAX 1024U
#define  SPI_FREAM_SIZE_MIN 1U
#define  SPI_CLK_PRESSCALE_MAX 0xFFU
#define  SPI_CS_IDX_MAX 4U
#define  SPI_BAUD_RATE_MAX 50000000U
#define  SPI_FIFO_LEN 16U
#define  SPI_FIFO_LEN_HALF 8U
/** \brief  2 mst_idle 3 mst_start  7 mst_data wait */
#define  SPI_FSM_WAIT_DATA_STA 7U
#define  SPI_FSM_M_STR_STA 3U
#define  SPI_FSM_IDLE_STA 2U

/** \brief  device flags */
#define F_DEV_LSB   0x01U
#define F_DEV_SWAP  0x02U
#define F_DEV_NSS_HIGH  0x04U
#define F_DEV_NSS_SOFT  0x08U
#define F_DEV_MISO_DELAY  0x10U
#define F_DEV_CLK_DELAY  0x20U

/** \brief bus flags */
#define SPI_SSP_MODE_ENABLE  ((uint32)0x01 << 0U)
#define SPI_DMA_RX_ENABLE  ((uint32)0x01 << 1U)
#define SPI_DMA_TX_ENABLE  ((uint32)0x01 << 2U)
#define SPI_MODE_SLAVE_ENABLE  ((uint32)0x01 << 3U)
#define SPI_HALF_DUPLEX_ENABLE  ((uint32)0x01 << 4U)
#define SPI_SIMP_DELAY_ENABLE  ((uint32)0x01 << 5U)
#define SPI_TX_IRQ_ENABLE  ((uint32)0x01 << 6U)
#define SPI_RX_IRQ_ENABLE  ((uint32)0x01 << 7U)

#define SPI_IRQ_ENABLE (SPI_RX_IRQ_ENABLE|SPI_TX_IRQ_ENABLE)


/** \brief  Driver Soc spi instance base address */
#ifdef SEMIDRIVE_E3_SERIES
#define APB_SPI7_BASE (0xf0a20000u)
#define APB_SPI5_BASE (0xf0a10000u)
#define APB_SPI3_BASE (0xf0a00000u)
#define APB_SPI1_BASE (0xf09f0000u)
#define APB_SPI8_BASE (0xf0dc0000u)
#define APB_SPI6_BASE (0xf0db0000u)
#define APB_SPI4_BASE (0xf0da0000u)
#define APB_SPI2_BASE (0xf0d90000u)
#else
#define APB_SPI6_BASE (0xf05d0000u)
#define APB_SPI5_BASE (0xf05c0000u)
#define APB_SPI4_BASE (0xf05b0000u)
#define APB_SPI3_BASE (0xf05a0000u)
#define APB_SPI2_BASE (0xf0590000u)
#define APB_SPI1_BASE (0xf0580000u)
#endif
/** \brief
    FSM ready need max 6 cycles
    1us AT=50M need 50 sclk cycles
    once register read time : 4 * APB cycle AT= 200M  = (1/200 us * 4) = (4/200)us
    once sclk cycle = 200*(n+1)/50 APB sycles  n is Prescaler value;
    so:
    times = 200*(n+1)*10/4*50 = 2000*(n+1)/200  = 10*(n+1);
*/
#define  MAX_TIMEOUT_SWRST 2560U
/** \brief  2 cycles  for internal state swap */
#define  FREAM_DELAT_COMPENSATE_BY_SOFT(delay)  ((uint32)(((delay) >= 2U )?((delay)-2U):(delay)))
/** \brief
    FSM ready need max 10 cycles
    1us AT=50M need 50 sclk cycles
    once register read time : 4 * APB cycle AT= 200M  = (1/200 us * 4) = (4/200)us
    once sclk cycle = 200*(n+1)/50 APB sycles  n is Prescaler value;
    so:
    times = 200*(n+1)*10/4*50 = 2000*(n+1)/200  = 10*(n+1);

*/
#define  BUS_FSM_RDY_TIMEOUT(baudRateDivisor) ((((uint32)(baudRateDivisor))+1U) * 10U)
/** \brief
    per ward ready need max width+start+1+fream+1+end+1+10 cycles call sum_cycle
    1us AT=50M need 50 sclk cycles
    once register read time : 4 * APB cycle AT= 200M  = (1/200 us * 4) = (4/200)us
    once sclk cycle = 200*(n+1)/50 APB sycles  n is Prescaler value;
    so:
    times = 200*(n+1)*sum_cycle/4*50 = 2000*(n+1)/200  = sum_cycle*(n+1);
*/
#define  BUS_FIFO_PERWARD_TIMEOUT(timCtrl, baudRateDivisor,width)                    \
        ((GFV_SPI_TIM_CTRL_FRM_DLY((timCtrl)) + GFV_SPI_TIM_CTRL_END_DLY((timCtrl)) + \
        GFV_SPI_TIM_CTRL_START_DLY((timCtrl)) + ((uint32)(width)) + 10U + 3U) \
        * (((uint32)(baudRateDivisor))+1U))
/** \} */

/**
 *  \addtogroup MCAL_SPI_CFG SPI Configuration.
 *  \{
 */

/*****************************************************************************************
 *                            Global Types definition
 *****************************************************************************************/
/** \brief  Dma module identify, which are currently support modules. */
struct spi_dev_priv
{
    Spi_Mode mode;
    uint32 flags;
    uint32 timCtrl;
    uint8 baudRateDivisor;
    uint8 width;
    uint8 csIdx;
};
/** \brief  Dma module identify, which are currently support modules. */
struct spi_bus_priv
{
    uint32     flags;
    uint32     lastCmd;
#if (SPI_ENABLE_DMA == STD_ON)
    boolean     dmaConfigured;
    uint32     dmaErr;
    Dma_ChannelConfigType  *dmaChRx;
    Dma_ChannelConfigType  *dmaChTx;
#endif
};

/******************************************************************************************
 *                     Global Variable Declarations
 *****************************************************************************************/
/** \brief  the hardware relevant ops apis  */
extern const struct Spi_MldOps Spi_IpOps;
/** \} */

#ifdef __cplusplus
}
#endif

/** \} */

#endif
