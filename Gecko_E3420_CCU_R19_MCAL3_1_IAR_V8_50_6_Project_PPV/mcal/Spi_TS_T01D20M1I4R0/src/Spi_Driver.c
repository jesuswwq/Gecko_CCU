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
 * \file     Spi_Driver.c
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

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Spi.h"
#include "Spi_Cfg.h"
#include "Spi_Types.h"
#include "Spi_Driver.h"
#include "Spi_reg.h"
#include "SchM_Spi.h"
#include "RegHelper.h"
#if (SPI_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
/********************************************************************************************************
 *                                 Private Macro definition                                             *
 *******************************************************************************************************/
/** \brief  Spi pin relevant macros  */

#define  E3_SAFETY_PIN_NUM  135U
#define  E3_PIN_NUM_MAX     214U
#define  E3L_PIN_NUM_MAX    125U
#define  PINMUX_OFFSET      0x2000U

#ifdef SEMIDRIVE_E3_SERIES
#define SPI_SF_PIN_IDX_MAX  E3_SAFETY_PIN_NUM
#define SPI_PIN_IDX_MAX     E3_PIN_NUM_MAX
#define APB_IOMUXC_SF_BASE (0xf0630000u)
#define APB_IOMUXC_AP_BASE (0xf30e0000u)
#else
#define SPI_PIN_IDX_MAX     E3L_PIN_NUM_MAX
#define APB_IOMUXC_SF_BASE (0xf0860000u)
#define SPI_SF_PIN_IDX_MAX  SPI_PIN_IDX_MAX
#endif

#define PIN_IS_ILLEGAL(pin)     (SPI_PIN_IDX_MAX <= (pin))

#ifdef SEMIDRIVE_E3_SERIES
#define APB_GPIO_AP_BASE (0xf3120000u)
#define APB_GPIO_SF_BASE (0xf0740000u)
#else
#define APB_GPIO_SF_BASE (0xf0c40000u)
#endif

#define SPI_SET_PIN 0x04U
#define SPI_CLEAR_PIN 0x08U
#define SPI_DATA_OUT_PORT_0 ((uint32)0x680U)
#define SPI_DATA_OUT_PORT_1 ((uint32)0x690U)
#define SPI_DATA_OUT_PORT_SIZE \
    (SPI_DATA_OUT_PORT_1 - SPI_DATA_OUT_PORT_0)
#define SPI_DATA_OUT_PORT_X(n) \
    (SPI_DATA_OUT_PORT_0 + ((n)*SPI_DATA_OUT_PORT_SIZE))
/** \brief gpio group register address offset */
#define SPIP_GPIO_OEN_OFFSET(n) ((uint32)0x580U + ((n)*0x10U))
/******************************************************************************************
 *                     Global Variable Declarations
 *****************************************************************************************/
/********************************************************************************************************
 *                                  Private Variable Definitions                                        *
 *******************************************************************************************************/
/** \brief  core 0 driver handler data  */
#define SPI_CORE0_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Spi_MemMap.h"
#if SPI_CFG_ENABLE_CORE0 == STD_ON
static  struct Spi_Driver_Handler SpiHandler_Core0 LOCATE_ALIGNED(SPI_CACHE_LINE);
#endif
#define SPI_CORE0_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Spi_MemMap.h"
/** \brief  core 1 driver handler data  */
#define SPI_CORE1_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Spi_MemMap.h"
#if SPI_CFG_ENABLE_CORE1 == STD_ON
static  struct Spi_Driver_Handler  SpiHandler_Core1 LOCATE_ALIGNED(SPI_CACHE_LINE);
#endif
#define SPI_CORE1_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Spi_MemMap.h"
/** \brief  core 2 driver handler data  */
#define SPI_CORE2_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Spi_MemMap.h"
#if SPI_CFG_ENABLE_CORE2 == STD_ON
static  struct Spi_Driver_Handler  SpiHandler_Core2 LOCATE_ALIGNED(SPI_CACHE_LINE);
#endif
#define SPI_CORE2_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Spi_MemMap.h"
/** \brief  core 3 driver handler data  */
#define SPI_CORE3_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Spi_MemMap.h"
#if SPI_CFG_ENABLE_CORE3 == STD_ON
static  struct Spi_Driver_Handler  SpiHandler_Core3 LOCATE_ALIGNED(SPI_CACHE_LINE);
#endif
#define SPI_CORE3_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Spi_MemMap.h"
/** \brief  core 4 driver handler data  */
#define SPI_CORE4_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Spi_MemMap.h"
#if SPI_CFG_ENABLE_CORE4 == STD_ON
static  struct Spi_Driver_Handler  SpiHandler_Core4 LOCATE_ALIGNED(SPI_CACHE_LINE);
#endif
#define SPI_CORE4_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Spi_MemMap.h"

#define SPI_START_SEC_CONST_UNSPECIFIED
#include "Spi_MemMap.h"
/******************************************************************************************
 *                     Global Variable Declarations
 *****************************************************************************************/
/** \brief  This is the core spi driver handler global variable object */
/* Traceability       :  SWSR_SPI_255 */
struct Spi_Driver_Handler *const Spi_Handler[5] =
{
#if SPI_CFG_ENABLE_CORE0 == STD_ON
    &SpiHandler_Core0,
#else
    NULL_PTR,
#endif
#if SPI_CFG_ENABLE_CORE1 == STD_ON
    &SpiHandler_Core1,
#else
    NULL_PTR,
#endif
#if SPI_CFG_ENABLE_CORE2 == STD_ON
    &SpiHandler_Core2,
#else
    NULL_PTR,
#endif
#if SPI_CFG_ENABLE_CORE3 == STD_ON
    &SpiHandler_Core3,
#else
    NULL_PTR,
#endif
#if SPI_CFG_ENABLE_CORE4 == STD_ON
    &SpiHandler_Core4,
#else
    NULL_PTR,
#endif
};
/*PRQA S 3218 5*/
/** \brief  This is the spi controller apb register base */
static const uint32 Spi_BaseAddr[SPI_TOTAL_HW_COUNT] =
{
    APB_SPI1_BASE,
    APB_SPI2_BASE,
    APB_SPI3_BASE,
    APB_SPI4_BASE,
    APB_SPI5_BASE,
    APB_SPI6_BASE,
#ifdef SEMIDRIVE_E3_SERIES
    APB_SPI7_BASE,
    APB_SPI8_BASE
#endif
};

#define SPI_STOP_SEC_CONST_UNSPECIFIED
#include "Spi_MemMap.h"

#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
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
uint8 Spi_GetCoreID(void)
{
    return GetCoreID();
}
/** *****************************************************************************************************
 * \brief This function set the specify pin muxid.
 *
 * \verbatim
 * Syntax             : void Spi_SetPinMux(uint32 pin, Spi_PinModeType mux)
 *
 * Service ID[hex]    : NA
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : pin - Specify the pin id.
 *                      mux - New mux val.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Set the specify pin mux value.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_004 SWSR_SPI_012 SWSR_SPI_011
 *******************************************************************************************************/
static void Spi_SetPinMux(uint32 pin, Spi_PinModeType mux)
{
    /* pin is legal do not need check */
    uint32 addr, pinIndex = pin, regVal;

#ifdef SEMIDRIVE_E3_SERIES

    if (pin < E3_SAFETY_PIN_NUM)
    {
        pinIndex += 1U;
        addr = APB_IOMUXC_SF_BASE + PINMUX_OFFSET;
    }
    else
    {
        pinIndex -= E3_SAFETY_PIN_NUM;
        addr = APB_IOMUXC_AP_BASE + PINMUX_OFFSET;
    }

#else
    pinIndex += 1U;
    addr = APB_IOMUXC_SF_BASE + PINMUX_OFFSET;
#endif
    addr =  addr + (pinIndex << 2U);
    regVal = readl(addr);
    regVal &= ~(uint32)0xFU;
    regVal |= (uint32)mux & 0xFU;
    writel(regVal, addr);
}
/** *****************************************************************************************************
 * \brief This function returns the specify pin mux value.
 *
 * \verbatim
 * Syntax             : Spi_PinModeType Spi_GetPinMux(uint32 pin)
 *
 * Service ID[hex]    : NA
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : pin - Specify pin id.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Mux value of the pin.
 *
 * Description        : The function get the specify pin id curent mux configuration.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_004 SWSR_SPI_012 SWSR_SPI_011
 *******************************************************************************************************/
static Spi_PinModeType Spi_GetPinMux(uint32 pin)
{
    /* pin is legal do not need check */
    uint32 addr, pinIndex = pin, regVal;
    Spi_PinModeType oldMux;
#ifdef SEMIDRIVE_E3_SERIES

    if (pin < E3_SAFETY_PIN_NUM)
    {
        pinIndex += 1U;
        addr = APB_IOMUXC_SF_BASE + PINMUX_OFFSET;
    }
    else
    {
        pinIndex -= E3_SAFETY_PIN_NUM;
        addr = APB_IOMUXC_AP_BASE + PINMUX_OFFSET;
    }

#else
    pinIndex += 1U;
    addr = APB_IOMUXC_SF_BASE + PINMUX_OFFSET;
#endif
    addr =  addr + (pinIndex << 2U);
    regVal = readl(addr);
    /*PRQA S 4342,4394,1841,4542 2*/
    oldMux = (Spi_PinModeType)(regVal & 0xF);

    return oldMux;
}
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
 * Traceability       : SWSR_SPI_004 SWSR_SPI_012 SWSR_SPI_011
 *******************************************************************************************************/
void Spi_SetIOLevel(uint32 pin, uint32 level)
{
    uint32  address ;
    uint32  channelId = pin;
#ifdef SEMIDRIVE_E3_SERIES

    if (SPI_SF_PIN_IDX_MAX > pin)
    {
        address = APB_GPIO_SF_BASE;
    }
    else
    {
        channelId -= SPI_SF_PIN_IDX_MAX;
        address = APB_GPIO_AP_BASE;
    }

#else
    address = APB_GPIO_SF_BASE;
#endif

    if (STD_HIGH == level)
    {
        address = address + SPI_DATA_OUT_PORT_X((channelId / 32U)) + SPI_SET_PIN;
    }
    else
    {
        address = address + SPI_DATA_OUT_PORT_X((channelId / 32U)) + SPI_CLEAR_PIN;
    }

    writel((uint32)0x01U << (channelId % 32U), address);
}
/** *****************************************************************************************************
 * \brief This function set the pin as outpu mode.
 *
 * \verbatim
 * Syntax             : void Spi_SetPadOutputMode(uint32 channel)
 *
 * Service ID[hex]    : NA
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : pin - Specify pin id.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The funtion use to set the pin as output mode for soft chip select.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_004 SWSR_SPI_012 SWSR_SPI_011
 *******************************************************************************************************/
static void Spi_SetPadOutputMode(uint32 pin)
{
    uint32  address;
    uint32  channelId = pin;
#ifdef SEMIDRIVE_E3_SERIES

    if (SPI_SF_PIN_IDX_MAX > pin)
    {
        address = APB_GPIO_SF_BASE;
    }
    else
    {
        channelId -= SPI_SF_PIN_IDX_MAX;
        address = APB_GPIO_AP_BASE;
    }

#else
    address = APB_GPIO_SF_BASE;
#endif
    address = address +  SPIP_GPIO_OEN_OFFSET(channelId / 32U) + SPI_SET_PIN;

    writel((uint32)0x01U << (channelId % 32U), address);
}
#if (SPI_ENABLE_DMA == STD_ON)
/** **************************************************************************************
 * \brief This function returns the HwUint Config.
 *
 * \verbatim
 * Syntax             : static inline const Spi_HwUnitConfigType *
 *                      Spi_GetHwUnitConfig(uint8 hwUnitId)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : hwUnitId - Pointer to configuration set
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Get the HwUint configurations .
 * \endverbatim
 * Traceability       : SWSR_SPI_258
 *****************************************************************************************/
static inline const Spi_HwUnitConfigType *Spi_GetHwUnitConfig(uint8 hwUnitId)
{
    uint8 idx;
    const Spi_HwUnitConfigType *hwCfgPtr = NULL_PTR;

    for (idx = 0; idx < SPI_TOTAL_HW_COUNT; idx++)
    {
        /* #10 busIdx is not config order, is need HwUinitid ? */
        if (hwUnitId == Spi_HwUnitConfig[idx].hwUnitId)
        {
            /* #20 return the HwUintConfig ? */
            hwCfgPtr =  &Spi_HwUnitConfig[idx];
            break;
        }
    }

    /* #30 User do not config thie hwUnitId */
    return hwCfgPtr;
}
#endif
/** **************************************************************************************
 * \brief This function set the hw cs0 in dessert status and soft cs pin to ready for output.
 *
 * \verbatim
 * Syntax             : static void Spi_HardWareQuirkCs(uint32 pinId,Spi_PinModeType mode,
 *                      uint32 csp,boolean isStart)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : pinId - The pin of hwCs0 of specify HwUint.
 *                       mode - The new mux mode.
 *                       csp - Current cs signal polarity.
 *                       isStart - Is transmit start point.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Set the cs0 Pin disconnect to spi and keep dessert status than set soft
 *                      cs pin mode as output and default status is dessert too.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_004 SWSR_SPI_012
 *****************************************************************************************/
static void Spi_HardWareQuirkCs(uint32 pinId, Spi_PinModeType mode, uint32 csp, boolean isStart)
{
    /* #10 is the transmisson start need to assert cs signal */
    if (TRUE == isStart)
    {
        /* #20 CS CSPolarity LOW == 1 HIGH == 0 ,if cs assery  Polarity is low set this to high */
        Spi_SetIOLevel(pinId, (csp == STD_HIGH) ? STD_HIGH : STD_LOW);
        /* #30 set pad as GPIO ,to avoid Chip Selecting Multiple Slaves */
        Spi_SetPadOutputMode(pinId);
        /* #40 Set the mux to 0 to disconnect from Spi controller */
        Spi_SetPinMux(pinId, mode);
    }
    else
    {
        /* #50 transmission over recover pad mux as Spi CS0 and the pad
        was controled by Spi controller */
        Spi_SetPinMux(pinId, mode);
    }
}
/** **************************************************************************************
 * \brief This function Init the mld bus priv datas.
 *
 * \verbatim
 * Syntax             : static void Spi_BusPrivInit(uint8 busIdx)
 *
 * Service ID[hex]    : 0x00
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : busIdx - Pointer to configuration set
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The function init the mld bus priv variables by the Config.
 * \endverbatim
 * Traceability       : SWSR_SPI_073 SWSR_SPI_082 SWSR_SPI_083 SWSR_SPI_136 SWSR_SPI_137
 *                      SWSR_SPI_138 SWSR_SPI_139
 *****************************************************************************************/
static void Spi_BusPrivInit(uint8 busIdx)
{
    uint8 coreId = Spi_GetCoreID();
    struct Spi_Driver_Handler *perCoreHandler = Spi_Handler[coreId];
    /* #10 clean the mode flags */
    perCoreHandler->spiBus[busIdx].busPriv.flags = 0;
#if (SPI_ENABLE_DMA == STD_ON)
    /* #20 Get the HuUnt User configuration, if user not config the controller
    default mode is not enable dma  */
    const Spi_HwUnitConfigType *hwUnitConfigPtr =  Spi_GetHwUnitConfig(busIdx);

    if (hwUnitConfigPtr != NULL_PTR)
    {
        if (hwUnitConfigPtr->isEnableDMA == TRUE)
        {
            /* #30 User not config the controller default mode is not enable dma  */
            perCoreHandler->spiBus[busIdx].busPriv.flags |= SPI_DMA_TX_ENABLE | SPI_DMA_RX_ENABLE;
        } /** else is not needed */
    }/** else is not needed */

    /* #40 Init the dma relevent various  */
    perCoreHandler->spiBus[busIdx].busPriv.dmaChRx = NULL_PTR;
    perCoreHandler->spiBus[busIdx].busPriv.dmaChTx = NULL_PTR;
    perCoreHandler->spiBus[busIdx].busPriv.dmaErr = 0;
    perCoreHandler->spiBus[busIdx].busPriv.dmaConfigured = 0;
#endif
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_1)
    /* #50 if delivered level is 1 only support irq mode not support polling mode  */
    perCoreHandler->spiBus[busIdx].busPriv.flags |= SPI_TX_IRQ_ENABLE | SPI_RX_IRQ_ENABLE;
#endif
}
/** **************************************************************************************
 * \brief This function init the mld device priv datas.
 *
 * \verbatim
 * Syntax             : void Spi_DevicePrivInit(uint8 devIdx, const Spi_JobCfgType *jobCfg)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : devIdx - logic job id.
 *                      jobCfg - Specift Job's confugrtation.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The function init the mld device priv variables by the Config.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_073 SWSR_SPI_082 SWSR_SPI_083 SWSR_SPI_136 SWSR_SPI_137
 *                      SWSR_SPI_138 SWSR_SPI_139
 *****************************************************************************************/
static void Spi_DevicePrivInit(uint8 devIdx, const Spi_JobCfgType *jobCfg)
{
    Spi_Mode mode;
    uint8 coreId = Spi_GetCoreID();
    struct Spi_Driver_Handler *perCoreHandler = Spi_Handler[coreId];
    const  Spi_HwUnitConfigType *hwUnitConfigPtr =
        &Spi_HwUnitConfig[jobCfg->hwIdxOfHwUnitCfgs];

    /*#10  device Spi Timming mode Config */
    if (HIGH == jobCfg->idleLevel)
    {
        /* CPOL = 1*/
        if (TRAILING == jobCfg->shiftEdge)
        {
            /* CPOA = 0 mode = 2*/
            mode = SCPO1_SCPH0;
        }
        else
        {
            /* CPOA = 1 mode = 3*/
            mode = SCPO1_SCPH1;
        }
    }
    else
    {
        /* CPOL = 0 */
        if (TRAILING == jobCfg->shiftEdge)
        {
            /* CPOA = 0 mode = 0*/
            mode = SCPO0_SCPH0;
        }
        else
        {
            /* CPOA = 1 mode = 1*/
            mode = SCPO0_SCPH1;
        }
    }

    perCoreHandler->spiDevice[devIdx].devicePriv.mode = mode;

    /* #20 config device baudrate/chip slecte / timming/bit order/
        chip slecte polarity/ miso delay/clk hold
    */
    perCoreHandler->spiDevice[devIdx].devicePriv.baudRateDivisor = jobCfg->baudRateDiv;
    perCoreHandler->spiDevice[devIdx].devicePriv.csIdx  = jobCfg->CSIdx;
    perCoreHandler->spiDevice[devIdx].devicePriv.width = jobCfg->dataWidth;
    perCoreHandler->spiDevice[devIdx].devicePriv.timCtrl = FV_SPI_TIM_CTRL_START_DLY(
                jobCfg->timeClk2Cs);
    perCoreHandler->spiDevice[devIdx].devicePriv.timCtrl |= FV_SPI_TIM_CTRL_END_DLY(
                jobCfg->timeClk2CsEnd);
    /* The software cost about 20 us and needs to be compensated */
    /*PRQA S 4391 2*/
    perCoreHandler->spiDevice[devIdx].devicePriv.timCtrl |= FV_SPI_TIM_CTRL_FRM_DLY(
                FREAM_DELAT_COMPENSATE_BY_SOFT(jobCfg->timeFrameDelay));
    perCoreHandler->spiDevice[devIdx].devicePriv.flags = 0;

    if (LSB == jobCfg->bitOrder)
    {
        perCoreHandler->spiDevice[devIdx].devicePriv.flags |= F_DEV_LSB;
    }

    if ((uint8)HIGH == jobCfg->CSPolarity)
    {
        perCoreHandler->spiDevice[devIdx].devicePriv.flags |= F_DEV_NSS_HIGH;
    }

    if (TRUE == jobCfg->isSampleDelay)
    {
        perCoreHandler->spiDevice[devIdx].devicePriv.flags |= F_DEV_MISO_DELAY;
    }

    /* #30 Vio cs cmd will select cs0 as cs */
    if (CS_VIA_GPIO == jobCfg->CSHandling)
    {
        perCoreHandler->spiDevice[devIdx].devicePriv.csIdx = 0;
        perCoreHandler->spiDevice[devIdx].devicePriv.flags |= F_DEV_NSS_SOFT;
    }

    /* #40 dma mode do not support this feature so not enable */
    if (0U != jobCfg->timeFrameDelay)
    {
        if (FALSE == hwUnitConfigPtr->isEnableDMA )
        {
            perCoreHandler->spiDevice[devIdx].devicePriv.flags |= F_DEV_CLK_DELAY;
        }
        else
        {
            /* dma mode not support cs hold mode  */
        }
    }
}

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
/** **************************************************************************************
 * \brief This function used to get the sequence next job by currenr jobid.
 *
 * \verbatim
 * Syntax             : static inline struct Spi_list *Spi_GetNextJobNode(
 *                            const Spi_SequenceCfgType *sequenceCfg,
 *                            uint16 jobIndexNext)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : sequenceCfg - Pointer to specify sequence config.
 *                      jobIndexNext -  next job id.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Return the next job's node ptr or NULL_PTR.
 *
 * Description        : The funtion get the sequence next job by currenr jobid
 * \endverbatim
 * Traceability       : SWSR_SPI_007
 *****************************************************************************************/
static inline struct Spi_list *Spi_GetNextJobNode(
    const Spi_SequenceCfgType *sequenceCfg,
    uint16 jobIndexNext)
{
    uint16 jobIdNext;
    uint8 coreId = Spi_GetCoreID();
    /* #10 default return is null */
    struct Spi_list *tempjobNode = NULL_PTR;
    struct Spi_Driver_Handler *perCoreHandler = Spi_Handler[coreId];

    /* #20 If input job index is in range */
    if (sequenceCfg->numOfJobs > jobIndexNext)
    {
        jobIdNext = sequenceCfg->jobList[jobIndexNext];
        /* #30 Get the node object */
        tempjobNode =  &perCoreHandler->jobNode[jobIdNext].node;
    }

    /* #40 return the node object */
    return tempjobNode;
}
#endif

/** **************************************************************************************
 * \brief This function initialize the async transmit scheduler.
 *
 * \verbatim
 * Syntax             : static void Spi_SchedulerInit(const Spi_ConfigType* configPtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : configPtr - Pointer to configuration set.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function initialize the async transmit scheduler.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_141
 *****************************************************************************************/
static void Spi_SchedulerInit(const Spi_ConfigType *configPtr)
{
    uint16 jobId, jobIndex, jobChannelsCnt;
    uint8  seqIndex, channelIndex, channelId, channelNextId;
    uint8  coreId = Spi_GetCoreID();

    struct Spi_Driver_Handler *perCoreHandler = Spi_Handler[coreId];
    struct mld_vector *spiChannelCB = perCoreHandler->spiChannelCB;
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
     (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
    uint8 hwUintIndex;
    struct Spi_SeqNode  *seqNode = perCoreHandler->seqNode;
    struct Spi_JobNode  *jobNode = perCoreHandler->jobNode;
#endif
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
     (SPI_LEVEL_DELIVERED == SPI_LEVEL_2) || \
     (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_ON))
    struct Spi_Scheduler *pSchduler = &perCoreHandler->scheduler;
#endif
    const Spi_JobCfgType *ptrJobCfg = configPtr->jobCfgs;
    const Spi_SequenceCfgType *ptrSequenceCfg = configPtr->sequenceCfgs;

    for (seqIndex = 0; seqIndex < SPI_TOTAL_SEQ_COUNT; seqIndex++)
    {
        /* #10 Iterate over all jobs  */
        for (jobIndex = 0 ; jobIndex < ptrSequenceCfg[seqIndex].numOfJobs; jobIndex++)
        {
            /* #20 Iterate over all jobs and  make a linked list of jobs */
            jobId = ptrSequenceCfg[seqIndex].jobList[jobIndex];
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
            jobNode[jobId].node.next = Spi_GetNextJobNode(&ptrSequenceCfg[seqIndex], jobIndex + 1U);
            jobNode[jobId].seqId = seqIndex;
            jobNode[jobId].jobId = jobId;
            jobNode[jobId].isActive = 0;
#endif
            /* #30 get job channel cnt */
            jobChannelsCnt = ptrJobCfg[jobId].numOfChannels;

            /* #40 Iterate over all channels and make a linked list of channels  */
            for (channelIndex = 0; channelIndex < jobChannelsCnt; channelIndex++)
            {
                channelId = ptrJobCfg[jobId].channelList[channelIndex];
                channelNextId = ptrJobCfg[jobId].channelList[channelIndex + (uint8)1];
                spiChannelCB[channelId].next = &spiChannelCB[channelNextId];
            }

            /* #50 step #40 cause the last channel next point over range fix it */
            spiChannelCB[ptrJobCfg[jobId].channelList[jobChannelsCnt - (uint8)1]].next = NULL_PTR;
        }

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
        /* #60 Init sequence node and add job list to squence node  */
        seqNode[seqIndex].jobList.next = &jobNode[ptrSequenceCfg[seqIndex].jobList[0]].node;
        seqNode[seqIndex].jobList.prev = NULL_PTR;
        seqNode[seqIndex].node.next = NULL_PTR;
        seqNode[seqIndex].node.prev = NULL_PTR;
        seqNode[seqIndex].seqId = seqIndex;
        seqNode[seqIndex].pCurrJobNode = NULL_PTR;
        /* seq priority depends on the highest priority of all jobs*/
        seqNode[seqIndex].priorty = ptrJobCfg[ptrSequenceCfg[seqIndex].jobList[0]].spiJobPriority;
        seqNode[seqIndex].interruptable = ptrSequenceCfg[seqIndex].interruptableSequence;
#endif
    }

    /* #70 SyncTransmit parallel  ongoing sequence num init as 0 */
    perCoreHandler->spiSyncSeqActiveCnt = 0;

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))

    /* #80 Init the hwUinit jobId handler */
    for (hwUintIndex = 0; hwUintIndex < SPI_TOTAL_HW_COUNT; hwUintIndex++)
    {
        pSchduler->hwCurrJob[hwUintIndex] = NULL_PTR;
    }

    /* #90 Init the schduler private data such as state/seqQueue/HwMask etc  */
    pSchduler->schedulerState = ASYNC_SCHE_IDLE;
    pSchduler->seqsQueue.next = &pSchduler->seqsQueue;
    pSchduler->seqsQueue.prev = &pSchduler->seqsQueue;
    /* 100 The HwMask every bits means an hwUnitId status 1 means useable
        delivery level =1 only for async mode and for both async/sync when level2.
    */
    pSchduler->hwStatusMask = Spi_InstanceMask_Config[coreId];
    pSchduler->pendingSeqsCnt = 0;
    pSchduler->activeJobsCnt = 0;
    /*
        LEVEL1 default is Irq mode and not support switch mode.
        LEVEL2 default is polling mode  and support switch mode.
    */
#if ( SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
    pSchduler->schedulerMode = SPI_POLLING_MODE;
#elif ( SPI_LEVEL_DELIVERED == SPI_LEVEL_1)
    pSchduler->schedulerMode = SPI_INTERRUPT_MODE;
#endif

#elif (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_ON)
    pSchduler->hwStatusMask = Spi_InstanceMask_Config[coreId];
#endif
}
/** **************************************************************************************
 * \brief This function returns the check result of transmission .
 *
 * \verbatim
 * Syntax             : uint32 Spi_TransmitExternalBuffCheck(
 *                      const Spi_SequenceType sequence,
 *                      const Spi_EBDataType *eBState)
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
 * Description        : Check the transmission setup is ok?
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_194
 *****************************************************************************************/
static uint32 Spi_TransmitExternalBuffCheck(const Spi_SequenceType sequence,
        const Spi_EBDataType *eBState)
{
    uint8  chanIdx;
    uint16 jobIndex;
    uint32 retVal = 0;
    Spi_ChannelType channelId;
    const Spi_JobCfgType *ptrJobConfig;
    /* #10 get the sequence static config info */
    const Spi_SequenceCfgType *ptrSeqConfig = &Spi_SequenceConfig[sequence];

    /* #20  */
    for (jobIndex = 0; (jobIndex < ptrSeqConfig->numOfJobs) && (0U == retVal); jobIndex++)
    {
        ptrJobConfig = &Spi_JobConfig[ptrSeqConfig->jobList[jobIndex]];

        for (chanIdx = 0; (chanIdx < ptrJobConfig->numOfChannels) && (0U == retVal); chanIdx++)
        {
            channelId = ptrJobConfig->channelList[chanIdx];

            if (EB == Spi_ChannelConfig[channelId].channelBufferType)
            {
                if (0U == eBState[channelId].length)
                {
                    /* length error   */
                    retVal = 1;
                }
                else if ((NULL_PTR == eBState[channelId].srcDataBufferPtr) &&
                         (NULL_PTR == eBState[channelId].desDataBufferPtr))
                {
                    /* buffer address error   */
                    retVal = 2;
                }
                else
                {
                    /* Do Nothing  */
                }
            }/* else not needed */
        }
    }

    return retVal;
}
/** **************************************************************************************
 * \brief This function use to check the buffer has seted befor any transmission.
 *
 * \verbatim
 * Syntax             : static Std_ReturnType Spi_BufferHasSetuped(Spi_SequenceType sequence)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : sequence - Specify the sequqnece Id.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: The check is passed.
 *                      E_NOT_OK: The check is failed.
 *
 * Description        : heck the buffer has seted or not befor any transmission.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_177
 *****************************************************************************************/
static Std_ReturnType Spi_BufferHasSetuped(const Spi_SequenceType sequence)
{
    uint8  chanIdx;
    uint16 jobIndex;
    Std_ReturnType retVal = E_OK;
    Spi_ChannelType channelId;
    uint8 coreId = Spi_GetCoreID();
    const Spi_JobCfgType *ptrJobConfig;
    const struct Spi_Driver_Handler *perCoreHandler = Spi_Handler[coreId];
    /* #10 get the sequence static config info */
    const Spi_SequenceCfgType *ptrSeqConfig = &Spi_SequenceConfig[sequence];

    /* #20  all the channel of this seqeucen are valid */
    for (jobIndex = 0; (jobIndex < ptrSeqConfig->numOfJobs) && (E_OK == retVal); jobIndex++)
    {
        ptrJobConfig = &Spi_JobConfig[ptrSeqConfig->jobList[jobIndex]];

        for (chanIdx = 0; (chanIdx < ptrJobConfig->numOfChannels) && (E_OK == retVal); chanIdx++)
        {
            channelId = ptrJobConfig->channelList[chanIdx];

            if (perCoreHandler->spiChannelState[channelId] != DATA_VALID)
            {
                retVal = E_NOT_OK;
            }/* else not needed */
        }
    }

    return retVal;
}
#if ( SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || ( SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
#if (SPI_INTERRUPTIBLE_SEQ_ALLOWED == STD_ON)
/** **************************************************************************************
 * \brief This function returns the insert node of schduler seuence queue.
 *
 * \verbatim
 * Syntax             : static struct Spi_SeqNode *Spi_GetInsertSeqNode(
 *                          struct Spi_Scheduler *pSchduler,
 *                          const struct Spi_SeqNode *newSeq)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : pSchduler - Pointer to the scheduler object.
 *                      newSeq - Point to new sequence node object.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Get the insert node point from current schduler sequence queue.
 * \endverbatim
 * Traceability       : SWSR_SPI_042 SWSR_SPI_051
 *****************************************************************************************/
static struct Spi_SeqNode *Spi_GetInsertSeqNode(const struct Spi_Scheduler *const pSchduler,
        const struct Spi_SeqNode *newSeq)
{
    struct Spi_SeqNode *tempSeqNode = NULL_PTR;
    const struct Spi_list   *node = &pSchduler->seqsQueue;

    /* #10 serch the sequence from priority high to low */
    while (node->next != &pSchduler->seqsQueue)
    {
        /*PRQA S 0306,2810 3*/
        tempSeqNode = GetSeqNode(node->next);

        /* #20 if the new sequence share the HwUint with current sequence
         ,contrast priority*/
        if (0U != (Spi_SequenceConfig[tempSeqNode->seqId].seqHwMask &
                   Spi_SequenceConfig[newSeq->seqId].seqHwMask))
        {
            /* #30 The new Seq and the current Seq share the same hwUnitId*/
            if ((TRUE == tempSeqNode->interruptable) &&
                    (tempSeqNode->priorty < newSeq->priorty))
            {
                /* #40 The current Seq can be interrupted and the priority is lower than the new Seq*/
                break;
            }
        }/* else not needed */
        /* set the node to null */
        tempSeqNode = NULL_PTR;
        /* #50 Move to next item */
        node = node->next;
    }

    return tempSeqNode;
}
#endif
/** **************************************************************************************
 * \brief Enquque one sequence to scheduler pending seq list.
 *
 * \verbatim
 * Syntax             : static Std_ReturnType Spi_ScheOneSequence(Spi_SequenceType sequenceId)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : sequenceId - specify the sequence id.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK:Issue the sequence async transmit pass.
 *                      E_NOT_OK:Issue the sequence async transmit Fail
 *
 * Description        : Enquque one sequence to scheduler pending seq list and try
 *                      to trriger once transfer.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_052 SWSR_SPI_053 SWSR_SPI_054 SWSR_SPI_055
 *                      SWSR_SPI_056 SWSR_SPI_058 SWSR_SPI_059
 *****************************************************************************************/
static Std_ReturnType Spi_ScheOneSequence(Spi_SequenceType sequenceId)
{
    Std_ReturnType retValue = E_OK;
#if (SPI_INTERRUPTIBLE_SEQ_ALLOWED == STD_ON)
    struct Spi_SeqNode *insertSeqNode;
#endif
    uint8 coreId = Spi_GetCoreID();
    struct Spi_Driver_Handler *perCoreHandler = Spi_Handler[coreId];
    struct Spi_Scheduler *pSchduler = &perCoreHandler->scheduler;
    struct Spi_SeqNode *seqNode = perCoreHandler->seqNode;
    const Spi_SequenceCfgType *ptrSeqConfig = &Spi_SequenceConfig[sequenceId];

    /*#10 Make sure EB Buff was Setuped and validate */
    if(E_OK != Spi_BufferHasSetuped(sequenceId))
    {
        retValue = E_NOT_OK;
    }
    else if (0U != Spi_TransmitExternalBuffCheck(sequenceId,
            perCoreHandler->externalBuffCb) )
    {
        retValue = E_NOT_OK;
    }
    /*#20 check the hwuint useable */
    else if ((ptrSeqConfig->seqHwMask & Spi_InstanceMask_Config[coreId])
             != ptrSeqConfig->seqHwMask)
    {
        retValue = E_NOT_OK;
    }
    else
    {
#if (SPI_INTERRUPTIBLE_SEQ_ALLOWED == STD_ON)
        /* #30 Find the insertion point,if the return is NULL_PTR Insert To Tail. */
        insertSeqNode = Spi_GetInsertSeqNode(pSchduler, &seqNode[sequenceId]);

        if (NULL_PTR != insertSeqNode)
        {
            /* #40 new sequence priority high than ,so insert new sequence to queue
            and preempt curr sequence  */
            seqNode[sequenceId].node.next = &insertSeqNode->node;
            seqNode[sequenceId].node.prev = insertSeqNode->node.prev;
            insertSeqNode->node.prev->next = &seqNode[sequenceId].node;
            insertSeqNode->node.prev = &seqNode[sequenceId].node;
            SPI_DBG("Insert Seq %d to Seq prev.\n", sequenceId, insertSeqNode->seqId);
        }
        else
        {
#endif
            /* #50 new sequence add to tail ,seqsQueue.prev point to last Seq queue item*/
            /* new seq link to old tail;queue tail<----prev<-new */
            seqNode[sequenceId].node.prev = pSchduler->seqsQueue.prev;
            /* new seq loop to sche node;new->next-->queue head */
            seqNode[sequenceId].node.next = pSchduler->seqsQueue.prev->next;
            /* set the taill seq  next to new seq;queue tail ->next---> new */
            pSchduler->seqsQueue.prev->next = &seqNode[sequenceId].node;
            /* update the tail ptr;new<---prev<-queue head*/
            pSchduler->seqsQueue.prev =  &seqNode[sequenceId].node;
            SPI_DBG("Add Seq %d to queue Tail.\n", sequenceId);
#if (SPI_INTERRUPTIBLE_SEQ_ALLOWED == STD_ON)
        }

#endif
        /* 60 Pending sequence num add  */
        pSchduler->pendingSeqsCnt++;
        /* 70 Set the seuqnece node status in queue as true */
        seqNode[sequenceId].seqIsInQueue = TRUE;
    }

    return retValue;
}
/** **************************************************************************************
 * \brief This function put an job to controler start transfer.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Spi_StartScheJob(const struct Spi_JobNode *jobNode)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : jobNode - Pointer to JobNode.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK:Issue the one job  transmit pass.
 *                      E_NOT_OK:Issue the one job async transmit Fail
 *
 * Description        : The function setup an async transmission for specify spi job.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_010 SWSR_SPI_011 SWSR_SPI_017 SWSR_SPI_018 SWSR_SPI_027
 *                      SWSR_SPI_173 SWSR_SPI_192 SWSR_SPI_193
 *****************************************************************************************/
static Std_ReturnType Spi_StartScheJob(const struct Spi_JobNode *jobNode)
{
    uint32  length;
    uint16  channelId, channelidx;
    sint32  mldRet;
    const Spi_DataBufferType *pCurrentTxBuffer;
    const Spi_DataBufferType *pCurrentRxBuffer;
    Std_ReturnType retValue = E_OK;
    uint8 coreId = Spi_GetCoreID();
    struct Spi_Driver_Handler *perCoreHandler = Spi_Handler[coreId];
    const Spi_JobCfgType *ptrJobCfg = &Spi_JobConfig[jobNode->jobId];
    const Spi_ChannelCfgType *ptrChannelConfig;

    const struct mld_spi_device *dev =
            &perCoreHandler->spiDevice[ptrJobCfg->deviceIdx].device;
#if (SPI_ENABLE_DMA == STD_ON)
    /* #10 hwUnitConfigPtr == NULL_PTR is not possibility */
    const Spi_HwUnitConfigType *hwUnitConfigPtr =
        &Spi_HwUnitConfig[ptrJobCfg->hwIdxOfHwUnitCfgs];
#endif

    /* #20 update all relevent channel control block such as buffer/lenth etc */
    for (channelidx = 0; channelidx < ptrJobCfg->numOfChannels; channelidx++)
    {
        channelId = ptrJobCfg->channelList[channelidx];
        ptrChannelConfig = &(Spi_ChannelConfig[channelId]);

        if (IB == ptrChannelConfig->channelBufferType)
        {
            /* the channel is an internal buffer get the buffer from configurations */
            pCurrentRxBuffer = (Spi_DataBufferType *)ptrChannelConfig->readBufferIndex;
            pCurrentTxBuffer = (const Spi_DataBufferType *)ptrChannelConfig->writeBufferIndex;
            length = ptrChannelConfig->bufferSize;
        }
        else
        {
            /* the channel is an external buffer get the buffer from user setup */
            pCurrentRxBuffer = (Spi_DataBufferType *)perCoreHandler->externalBuffCb[channelId].desDataBufferPtr;
            pCurrentTxBuffer = (const Spi_DataBufferType *)
                               perCoreHandler->externalBuffCb[channelId].srcDataBufferPtr;
            length = perCoreHandler->externalBuffCb[channelId].length;
        }

        /* #30 update lenth and tx buffer rx buffer probably
            null only when the channel is external buffer type */

        perCoreHandler->spiChannelCB[channelId].len = length;

        /* #40 update the buffer width type */
        if ( 0x9u > ptrChannelConfig->dataWidth)
        {
            perCoreHandler->spiChannelCB[channelId].widthType = SPI_DATA_WIDTH_BYTE;
        }
        else if (0x11U > ptrChannelConfig->dataWidth)
        {
            perCoreHandler->spiChannelCB[channelId].widthType = SPI_DATA_WIDTH_HALF_WORD;
        }
        else
        {
            perCoreHandler->spiChannelCB[channelId].widthType = SPI_DATA_WIDTH_WORD;
        }

        /* if user do not care abort the pCurrentRxBuffer probably as Null ,
           Internal buffer always duplex mode */
        if (NULL_PTR != pCurrentRxBuffer)
        {
            /*PRQA S 0306 1*/
            perCoreHandler->spiChannelCB[channelId].prxdata = (uint32)pCurrentRxBuffer;
            perCoreHandler->spiChannelCB[channelId].isRxDummy = 0;
        }
        else
        {
            /*PRQA S 0306 1*/
            perCoreHandler->spiChannelCB[channelId].prxdata = (uint32)&perCoreHandler->dummyRxBuffer;
            perCoreHandler->spiChannelCB[channelId].isRxDummy = 1;
        }

        if (NULL_PTR != pCurrentTxBuffer)
        {
            /*PRQA S 0306 1*/
            perCoreHandler->spiChannelCB[channelId].ptxdata = (uint32)pCurrentTxBuffer;
            perCoreHandler->spiChannelCB[channelId].isTxDummy = 0;
        }
        else
        {
            /*PRQA S 0306 1*/
            perCoreHandler->spiChannelCB[channelId].ptxdata = (uint32)&perCoreHandler->dummyTxBuffer;
            perCoreHandler->spiChannelCB[channelId].isTxDummy = 1;
        }
    }

    /* get the first channel for transmit start */
    channelId = ptrJobCfg->channelList[0];

    /* #50 If this job is soft cs with external device */
    if (CS_VIA_GPIO == ptrJobCfg->CSHandling)
    {
        if (TRUE == ptrJobCfg->hwCS0Enable)
        {
            /* #60  save the old mux of cs0 */
            dev->bus->oldMux = Spi_GetPinMux(ptrJobCfg->hwCs0PinId);
            /* #70 set the cs0 pad  level and direction as output last mux to  GPIO ,
            to avoid Chip Selecting Multiple Slaves*/
            Spi_HardWareQuirkCs(ptrJobCfg->hwCs0PinId, SPI_PIN_MUX_ALT0,
                                ptrJobCfg->HwCSPolarity, TRUE);
        }

        /* attach the pin index to low level */
        Spi_Mld_SetSoftCsId(dev->bus, ptrJobCfg->softCsPin);
    }/* else is not needed */

#if (SPI_ENABLE_DMA == STD_ON)

    /* #80 call mld layer setup async transmission */
    if (TRUE == hwUnitConfigPtr->isEnableDMA)
    {
        SPI_DBG("J:%d jobId Start to process DMA mode\n", jobNode->jobId);
        mldRet = Spi_Mld_AsyncDmaVectorModeTransmitReceive(dev->bus, dev,
                 &perCoreHandler->spiChannelCB[channelId]);
    }
    else
    {
#endif

        SPI_DBG("J:%d jobId Start to process IRQ mode\n", jobNode->jobId);
        mldRet = Spi_Mld_AsyncVectorModeTransmitReceive(dev->bus, dev,
                 &perCoreHandler->spiChannelCB[channelId]);
#if (SPI_ENABLE_DMA == STD_ON)
    }

#endif

    /* #90 If mld layer setup async transmission fail return Error to caller */
    if (0 > mldRet)
    {
        SPI_DBG("Oops:%s %d %p %p %d\n", __FUNCTION__, __LINE__, dev->bus, dev, channelId);
        retValue = E_NOT_OK;
    }

    return retValue;
}
/** **************************************************************************************
 * \brief This function serch scheduler sequence queue and select one job to transfer.
 *
 * \verbatim
 * Syntax             : void Spi_ScheduleOnce(void)
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
 * Description        : Called When One jobId Finish.This function will be called by interrupted and
 *                      non-interrupted parts of the code, need to critical section protection.
 * \endverbatim
 * Traceability       : SWSR_SPI_009 SWSR_SPI_043 SWSR_SPI_044 SWSR_SPI_051
 *                      SWSR_SPI_064 SWSR_SPI_174
 *****************************************************************************************/
static void Spi_ScheduleOnce(void)
{
    uint8 hwUnitId;
    struct Spi_SeqNode *seqItem;
    const struct Spi_list  *seqLinkList;
    uint8 coreId = Spi_GetCoreID();
    struct Spi_Driver_Handler *perCoreHandler = Spi_Handler[coreId];
    struct Spi_Scheduler *pSchduler = &perCoreHandler->scheduler;
    const Spi_JobCfgType *ptrJobCfg = Spi_JobConfig;
#if (SPI_CANCEL_API == STD_ON)
    const Spi_SequenceCfgType *ptrSeqCfg = Spi_SequenceConfig;
#endif

    /* #10 if the schuler is not inited  should not touch other variables */
    if (ASYNC_SCHE_UNINIT != pSchduler->schedulerState)
    {
        /*
            #20 hwStatusMask may never be 0 in multi-core,at this time, depending on pSchduler->pendingSeqsCnt > 0
            and next does not point to the queue head, that is, the queue is not empty, the jobId under Seq
            will be processed.
            when has unprocessed seq or has Controller is idle or linked list is empty.Some risk points
            here are that when the queue is very large, it will cause the interrupt masking time to be too long.
            Enter exclusive area avoid context switch(between the #20 to #140 )cause abnormal driver behavior
        */
        SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_00();
        seqLinkList = pSchduler->seqsQueue.next;

        /* #30 To avoid long processing times in irq handler the traversal is not greedy and will
           only traverse the queue once  seqLinkList == NULL_PTR is impossible  */
        while ((pSchduler->pendingSeqsCnt > 0U) &&
                (pSchduler->hwStatusMask != 0U) &&
                (seqLinkList != &pSchduler->seqsQueue))
        {
            /*PRQA S 0306,2810 2*/
            seqItem = GetSeqNode(seqLinkList);
#if (SPI_CANCEL_API == STD_ON)

            /* #40 If the Cancel operation is enabled the sequence will be
              canceled befor it was dispatched */
            if (TRUE == perCoreHandler->seqIsCancel[seqItem->seqId])
            {
                /*
                    #50 cancel the seq remove and all jobs of Seq from queue.Seq Canceled ,
                    other job not execute ,state keek queued */
                if (TRUE == seqItem->seqIsInQueue)
                {
                    seqItem->node.next->prev = seqItem->node.prev;
                    seqItem->node.prev->next = seqItem->node.next;
                    seqItem->seqIsInQueue = FALSE;
                    pSchduler->pendingSeqsCnt--;
                }/* else is not needed */

                /* #60 clean the sequence progress info for next transmission */
                if (NULL_PTR != seqItem->pCurrJobNode)
                {
                    seqItem->pCurrJobNode->isActive = 0;
                    seqItem->pCurrJobNode = NULL_PTR;
                }/* else is not needed */

                /* 70 Set the seuence reseult as Cancelled and clear the cancel request */
                perCoreHandler->seqResultArr[seqItem->seqId] = SPI_SEQ_CANCELLED;
                perCoreHandler->seqIsCancel[seqItem->seqId] = FALSE;

                /* 71 Sequence canceled the notification should call if needed */
                if (NULL_PTR != ptrSeqCfg[seqItem->seqId].sequenceEndNotification)
                {
                    ptrSeqCfg[seqItem->seqId].sequenceEndNotification();
                }/* else is not needed */

                SPI_DBG("S:%d Seq Canceled.\n", seqItem->seqId);
            }
            else
#endif
            {
                SPI_DBG("The Seq%p Id:%d CJ:%p\n", seqItem, seqItem->seqId, seqItem->pCurrJobNode);

                /* #80 if the sequence current job is null means that it is not start */
                if (NULL_PTR == seqItem->pCurrJobNode)
                {
                    /* Get first jobId of this sequence to process */
                    /*PRQA S 0306,2810 2*/
                    seqItem->pCurrJobNode = GetJobNode(seqItem->jobList.next);
                }
                else
                {
                    /* Has been updated by the jobId handler to the next jobId */
                }


                /* Get Hwindex cached it  */
                hwUnitId = ptrJobCfg[seqItem->pCurrJobNode->jobId].hwUnitId;

                /*
                    # 90 seqItem->pCurrJobNode->isActive = 1 means job Busy.
                    pSchduler->hwStatusMask releavent bits is 0 means hwUnitId Busy.
                */
                if ((FALSE == seqItem->pCurrJobNode->isActive) &&
                        (0U != (pSchduler->hwStatusMask & ((uint8)0x01 << hwUnitId))))
                {
                    /*
                            #100 This part of the code needs to be placed here when
                        critical protection is not added. After adding critical protection,
                        it can be moved to the branch of jobId OK..
                    */
                    if (E_OK != Spi_StartScheJob(seqItem->pCurrJobNode))
                    {
                        /*
                            #110 Start Exception;Remove all  Jobs of this sequence from queue.
                        */
                        seqItem->node.next->prev = seqItem->node.prev;
                        seqItem->node.prev->next = seqItem->node.next;
                        seqItem->seqIsInQueue = FALSE;
                        pSchduler->pendingSeqsCnt--;
                        pSchduler->hwCurrJob[hwUnitId] = NULL_PTR;

                        perCoreHandler->seqResultArr[seqItem->pCurrJobNode->seqId] = SPI_SEQ_FAILED;
                        perCoreHandler->jobResultArr[seqItem->pCurrJobNode->jobId] = SPI_JOB_FAILED;

                        SPI_DBG("S:%d J:%d jobId Start Fail\n", seqItem->pCurrJobNode->seqId, seqItem->pCurrJobNode->jobId);
                        seqItem->pCurrJobNode = NULL_PTR;
                    }
                    else
                    {
                        /* #120 Start jobId Pass   */
                        pSchduler->hwCurrJob[hwUnitId] = seqItem->pCurrJobNode;
                        pSchduler->hwStatusMask &= (~((uint8)0x01 << hwUnitId));
                        seqItem->pCurrJobNode->isActive = 1;
                        pSchduler->activeJobsCnt++;
                        perCoreHandler->handlerAsyncStatus = SPI_BUSY;
                        perCoreHandler->jobResultArr[seqItem->pCurrJobNode->jobId] = SPI_JOB_PENDING;

                        SPI_DBG("S:%d J:%d jobId Start on Spi%d\n", seqItem->pCurrJobNode->seqId,
                                seqItem->pCurrJobNode->jobId,
                                ptrJobCfg[seqItem->pCurrJobNode->jobId].hwUnitId + 1);
                    }
                }
                else
                {
                    SPI_DBG("The Spi%d is Busy or jobId%d is Busy.\n", hwUnitId + 1, seqItem->pCurrJobNode->jobId);
                }

            }

            /* #130 move to next sequence try to start transmit */
            seqLinkList =  seqLinkList->next;
        }

        /* #140 Exit exclusive area */
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_00();
    }
    else
    {
        SPI_DBG("pSchduler is not Inited \n");
    }
}
/** **************************************************************************************
 * \brief This function handle a job end.
 *
 * \verbatim
 * Syntax             : void Spi_JobHandleFuntion(uint8 hwUnitId)
 *
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
 * Description        : When the Job end (Pass or Fail) irq or polling mode will call this
 *                      function to handle Job end and select next job to do.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_011 SWSR_SPI_036 SWSR_SPI_039 SWSR_SPI_040 SWSR_SPI_046
 *                      SWSR_SPI_047 SWSR_SPI_048 SWSR_SPI_049 SWSR_SPI_050 SWSR_SPI_062
 *                      SWSR_SPI_063 SWSR_SPI_065 SWSR_SPI_168 SWSR_SPI_169 SWSR_SPI_175
 *                      SWSR_SPI_251 SWSR_SPI_253
 *****************************************************************************************/
static void Spi_JobHandleFuntion(uint8 hwUnitId)
{
    Spi_PinModeType oldMux;
    struct Spi_JobNode *jobItem;
    const Spi_JobCfgType *ptrJobCfg;
    boolean needSeqNotification = FALSE;
    boolean needSeqQeueuMaintain = FALSE;
    uint8 coreId = Spi_GetCoreID();
    struct Spi_Driver_Handler *perCoreHandler = Spi_Handler[coreId];
    struct Spi_Scheduler *pSchduler = &perCoreHandler->scheduler;
    const Spi_SequenceCfgType *sequenceId = Spi_SequenceConfig;
    struct Spi_SeqNode  *seqNode = perCoreHandler->seqNode;

    SPI_DBG("%s Spi%d \n", __FUNCTION__, hwUnitId + 1);

    if (SPI_BUSY == perCoreHandler->handlerAsyncStatus)
    {
        /* #10 The hwUnitId finished once jobId  get the job node by hwUnit curren job log variable  */
        jobItem = pSchduler->hwCurrJob[hwUnitId];

        /* Unexpected interrupts can cause jobItem  to be null */
        if (NULL_PTR != jobItem)
        {
            ptrJobCfg = &Spi_JobConfig[jobItem->jobId];

            SPI_DBG("J %p S:%d J:%d jobId finished.\n", jobItem, jobItem->seqId, jobItem->jobId);

            /* #20 If this job is soft cs need recover the hw cs port mux */
            if (CS_VIA_GPIO == ptrJobCfg->CSHandling)
            {
                if (TRUE == ptrJobCfg->hwCS0Enable)
                {
                    /* Resotry pinCs0Mux configure  */
                    oldMux = perCoreHandler->spiBus[ptrJobCfg->hwUnitId].
                             bus.oldMux;

                    Spi_HardWareQuirkCs(ptrJobCfg->hwCs0PinId, oldMux,
                                        ptrJobCfg->HwCSPolarity, FALSE);
                }

                /* # deassert the soft cs */
                if ((uint8)LOW ==  ptrJobCfg->CSPolarity)
                {
                    Spi_SetIOLevel(ptrJobCfg->softCsPin, STD_HIGH);
                }
                else
                {
                    Spi_SetIOLevel(ptrJobCfg->softCsPin, STD_LOW);
                }
            }/* else is not needed */

            /*
                #30 Except err ,seq end ,or canceled seq.jobItem->node.next is const
                do not need critical protection.The large critical section is used
                here to protect when pSchduler->schedulerState = ASYNC_SCHE_IDLE and then
                seqNode[jobItem->seqId].pCurrJobNode is updated and jobItem->seqId is not
                pending, if the asynchronous transfer of jobItem->seqId is called again ,
                which will affect the enqueuing behavior and introduce uncertainty.
            */
            if (0U != (perCoreHandler->spiBus[ptrJobCfg->hwUnitId].bus.state & SPI_STATE_ERR_END))
            {
                /* #40 jobId Failed stop other all of the sequence jobs that is not tramsmit */
                perCoreHandler->jobResultArr[jobItem->jobId] = SPI_JOB_FAILED;
                perCoreHandler->seqResultArr[jobItem->seqId] = SPI_SEQ_FAILED;
                perCoreHandler->spiBus[ptrJobCfg->hwUnitId].bus.state &= (uint32)(~SPI_STATE_ERR_END);
                /* sequenceId fail notification need called */
                needSeqNotification = TRUE;
                /* remove sequence from sequence queue */
                needSeqQeueuMaintain = TRUE;
#if (SPI_DEV_ERROR_DETECT == STD_ON)
                /* Tx FIFO UDR,RX OVR,DMA Error will report here  */
                (void)Det_ReportRuntimeError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_ASYNCTRANSMIT_SID,
                                             SPI_E_ASYNC_ERROR);
#endif
                SPI_DBG("J %p S:%d J:%d jobId Fail.\n", jobItem, jobItem->seqId, jobItem->jobId);
            }
            else if (jobItem->node.next == NULL_PTR)
            {
                /* #50 sequenceId Transmit Finished set the job result as OK . */
                perCoreHandler->jobResultArr[jobItem->jobId] = SPI_JOB_OK;

                /* #60 The sequenceId was canceled and the current jobId was completed in an uncertain order, so it is
                    possible that the Sequencer result has been updated elsewhere, so this is only
                    updated if the sequenceId is pending*/
                SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_00();
                if (SPI_SEQ_PENDING == perCoreHandler->seqResultArr[jobItem->seqId])
                {
                    perCoreHandler->seqResultArr[jobItem->seqId] = SPI_SEQ_OK;
                }/* else is not needed */
                SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_00();
                /* sequenceId pass notification need called */
                needSeqNotification = TRUE;
                /* remove sequence from sequence queue */
                needSeqQeueuMaintain = TRUE;
            }
            else
            {
                /* #70 have next job to do ,only update current job status as ok
                    and move sequence next job to next */
                perCoreHandler->jobResultArr[jobItem->jobId] = SPI_JOB_OK;
                /*PRQA S 0306,2810 2*/
                seqNode[jobItem->seqId].pCurrJobNode = GetJobNode(jobItem->node.next);
            }

            SPI_DBG("J:%d jobId End.\n", jobItem->jobId);

            /* #80 free controller  */
            pSchduler->hwStatusMask |= ((uint8)0x01 << ptrJobCfg->hwUnitId);

            SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_00();

            if (TRUE == needSeqQeueuMaintain)
            {

                seqNode[jobItem->seqId].pCurrJobNode = NULL_PTR;

                /* 90 remove the sequence from sequence form queue ,seqIsInQueue use to avoid the
                cancel already removed the sequence  while the last job ongoing */
                if (TRUE == seqNode[jobItem->seqId].seqIsInQueue)
                {
                    seqNode[jobItem->seqId].node.next->prev = seqNode[jobItem->seqId].node.prev;
                    seqNode[jobItem->seqId].node.prev->next = seqNode[jobItem->seqId].node.next;
                    seqNode[jobItem->seqId].seqIsInQueue = FALSE;
                    pSchduler->pendingSeqsCnt--;
                }
                else
                {
                    /* 101 if it not in queue it was canceled */
                    needSeqNotification = 0;
                }

                SPI_DBG("S:%d Seq End.\n", jobItem->seqId);
            }/* else is not needed */

            /* #100 Note:Update the state machine before Notifaction to avoid exceptions
                when calling asynchronous transfers in Notifaction. */
            pSchduler->activeJobsCnt--;
            /* finish curr job */
            jobItem->isActive = 0;
            /* avoid polling mode Notification multi called */
            pSchduler->hwCurrJob[hwUnitId] = NULL_PTR;

            /* #110 Have pending sequence need resche */
            if (0U < pSchduler->pendingSeqsCnt)
            {
                Spi_ScheduleOnce();
            }/* else is not needed */

            if (0U == pSchduler->activeJobsCnt)
            {
                perCoreHandler->handlerAsyncStatus = SPI_IDLE;
            }
            /* #120 Exit exclusive area */
            SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_00();
            /*
                #130 Here pSchduler->pendingSeqsCnt may be 0, if (pSchduler->pendingSeqsCnt)
                should be placed befor Notifaction to support starting a new
                asynchronous transfer in Notifaction Ref SWS_Spi_00270.
            */
            if (NULL_PTR != ptrJobCfg->jobEndNotification)
            {
                ptrJobCfg->jobEndNotification();
                SPI_DBG("S:%d J:%d jobId Finish Notification.\n", jobItem->seqId, jobItem->jobId);
            }/* else is not needed */

            if ((TRUE == needSeqNotification) &&
                    (NULL_PTR != sequenceId[jobItem->seqId].sequenceEndNotification))
            {
                sequenceId[jobItem->seqId].sequenceEndNotification();
                SPI_DBG("S:%d Seq Finish Notification.\n", jobItem->seqId);
            }/* else is not needed */
        }
        else
        {
            /* Poling mode this case will happen */
        }
    }
    else
    {
        /* Poling mode this case will happen */
        SPI_DBG("AS:%d SS:%d\n", perCoreHandler->handlerAsyncStatus, perCoreHandler->handlerStatus);
    }
}
#endif
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
void Spi_InitData(const Spi_ConfigType *configPtr)
{
    uint8 hwid ,chidx;
    Spi_JobType jobIdx;
    Spi_SequenceType seqIndex;
    uint8 coreId = Spi_GetCoreID();
    const Spi_JobCfgType *ptrJobCfg = configPtr->jobCfgs;
    struct Spi_Driver_Handler *perCoreHandler = Spi_Handler[coreId];

    /* #10 Initialise every Hw bus unit private data*/
    for (hwid = 0; hwid < SPI_TOTAL_HW_COUNT; hwid++)
    {
        Spi_BusPrivInit(hwid);
    }

    /* #20 Initialise  every device  private data */
    for (jobIdx = 0; jobIdx < SPI_TOTAL_JOB_COUNT; jobIdx++)
    {
        Spi_DevicePrivInit(ptrJobCfg[jobIdx].deviceIdx, &ptrJobCfg[jobIdx]);
    }

    /* #30 Initialise jobId result array */
    for (jobIdx = 0; jobIdx < SPI_TOTAL_JOB_COUNT; jobIdx++)
    {
        perCoreHandler->jobResultArr[jobIdx] = SPI_JOB_OK;
    }

    /* #30 Initialise sequence result array */
    for (seqIndex = 0; seqIndex < SPI_TOTAL_SEQ_COUNT; seqIndex++)
    {
        perCoreHandler->seqResultArr[seqIndex] = SPI_SEQ_OK;
#if SPI_CANCEL_API == STD_ON
        /* Initialise sequenceId cancel array */
        perCoreHandler->seqIsCancel[seqIndex] = FALSE;
#endif
    }
    /* #40 Initialise all channel status */
    for (chidx = 0; chidx < SPI_MAX_CHANNEL; chidx++)
    {
        perCoreHandler->spiChannelState[chidx] = DATA_INVALID;
    }
    /* #40 Init Scheduer Dependent Parameter*/
    Spi_SchedulerInit(configPtr);
}
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
                      const Spi_AsyncModeType mode)
{
    uint8 hwIdx;
    uint8 coreId = Spi_GetCoreID();
    struct Spi_Scheduler *pSchduler = &perCoreHandler->scheduler;

    /* #10 switch all relenvent hwUint async mechanism */
    for (hwIdx = 0; hwIdx < SPI_TOTAL_HW_COUNT; hwIdx++)
    {
        /* #20 This hwUint is assigned to the current core ?*/
        if (0U != (Spi_InstanceMask_Config[coreId] & ((uint8)0x01 << hwIdx)))
        {
            if (SPI_POLLING_MODE == mode)
            {
                /* clear the irq enable flags */
                perCoreHandler->spiBus[hwIdx].busPriv.flags &=
                    (uint32)(~(SPI_TX_IRQ_ENABLE | SPI_RX_IRQ_ENABLE));
            }
            else
            {
                /* set the irq enable flags */
                perCoreHandler->spiBus[hwIdx].busPriv.flags |=
                    SPI_TX_IRQ_ENABLE | SPI_RX_IRQ_ENABLE;
            }
        }/* else if not needed */
    }

    /* #30 update the scheduler mode to new mode */
    pSchduler->schedulerMode = mode;
}
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
Std_ReturnType Spi_HWInit(const Spi_ConfigType *configPtr)
{
    uint8 jobIdx;
    uint8 hwUnitId;
    uint8 hwUnitIdx;
    uint8 deviceIdx;
    Std_ReturnType retValue = E_OK;
    uint8 coreId = Spi_GetCoreID();

    const Spi_JobCfgType *ptrJobCfg = configPtr->jobCfgs;
    struct Spi_Driver_Handler *perCoreHandler = Spi_Handler[coreId];

    /* #10 initialize mld HwUnits objects */
    for (hwUnitIdx = 0; hwUnitIdx < SPI_TOTAL_HW_COUNT; hwUnitIdx++)
    {
        Spi_Mld_SetupBusPrivParams(&perCoreHandler->spiBus[hwUnitIdx].bus, \
                                   Spi_BaseAddr[hwUnitIdx], &Spi_IpOps, \
                                   &perCoreHandler->spiBus[hwUnitIdx].busPriv);

        perCoreHandler->spiBus[hwUnitIdx].bus.idx = hwUnitIdx;

        /* #20 This hwUint is assigned to the current core ?*/
        if (0U != (Spi_InstanceMask_Config[coreId] & ((uint8)0x01 << hwUnitIdx)))
        {
            /* init the hwUnitIdx by call low layer ops */
            if (0 != Spi_Mld_Init(&perCoreHandler->spiBus[hwUnitIdx].bus))
            {
                retValue =  E_NOT_OK;
                break;
            }
        }/*else is not needed */
    }

    /* #30 Initialize all mld device object */
    for (jobIdx = 0; ((jobIdx < SPI_TOTAL_JOB_COUNT) && (retValue == E_OK)); jobIdx++)
    {
        /* get the spi HW units and device id  the jobIdx == deviceIdx */
        hwUnitId = ptrJobCfg[jobIdx].hwUnitId;
        /* deviceIdx = ptrJobCfg[jobIdx].deviceIdx */
        deviceIdx = jobIdx;
        /* spi device init */
        Spi_Mld_SetupDevicePrivParams(&perCoreHandler->spiDevice[deviceIdx].device, \
                                      &perCoreHandler->spiDevice[deviceIdx].devicePriv);

        /*
            #40 spi device attach spi ,There will set the cs polarity;
            the upper layer should prevent that different devices
            on the same bus use the same cs signal.
            soft cs do not need touch hw cs config bits.
        */
        if (0U != (Spi_InstanceMask_Config[coreId] & ((uint8)0x01 << hwUnitId)))
        {
            /*PRQA S 4404  3*/
            Spi_Mld_DeviceAttachToBus(&perCoreHandler->spiDevice[deviceIdx].device, \
                                      &perCoreHandler->spiBus[hwUnitId].bus,
                                      ((Spi_CsHandling)CS_VIA_PERIPHERAL_ENGINE ==
                                       ptrJobCfg[deviceIdx].CSHandling));
        }
    }

    return retValue;
}

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
Std_ReturnType Spi_HWDeInit(uint8 coreId)
{
    uint8 busIdx;
    Std_ReturnType retValue = E_OK;
    struct Spi_Driver_Handler *perCoreHandler = Spi_Handler[coreId];

    /* #10 Deinit all HwUinit that is assigned to the current core */
    for (busIdx = 0; busIdx < SPI_TOTAL_HW_COUNT; busIdx++)
    {
        if (0U != (Spi_InstanceMask_Config[coreId] & ((uint8)((uint8)0x01 << busIdx))))
        {
            if (0 != Spi_Mld_Deinit(&perCoreHandler->spiBus[busIdx].bus))
            {
                /* Try another HwUinit deinie even if there is an error */
                retValue = E_NOT_OK;
            }/* else is not needed */
        }/* else is not needed */
    }

    return retValue;
}
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_0) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
/** **************************************************************************************
 * \brief This function use to transmit an spi job synchronous.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Spi_JobSyncTransmit(Spi_JobType jobId,
 *                          const Spi_JobCfgType *ptrJobConfig)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : jobId - Specify the job Id.
 *                      ptrJobConfig - Pointer to Job configuration.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: The transmission is passed.
 *                      E_NOT_OK: The transmitssion is failed.
 *
 * Description        : The Job SyncTransmit implementation.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_002 SWSR_SPI_010 SWSR_SPI_011 SWSR_SPI_017 SWSR_SPI_018
 *                      SWSR_SPI_027 SWSR_SPI_035 SWSR_SPI_047 SWSR_SPI_049 SWSR_SPI_062
 *                      SWSR_SPI_173 SWSR_SPI_192 SWSR_SPI_193
 *****************************************************************************************/
static Std_ReturnType Spi_JobSyncTransmit(Spi_JobType jobId,
        const Spi_JobCfgType *ptrJobConfig)
{
    sint32  retValue;
    uint16  length;
    uint16  channelId;
    Spi_PinModeType oldMux;
    Spi_ChannelType channIdx;
    uint8 coreId = Spi_GetCoreID();
    Std_ReturnType returnValue = E_OK;
    const Spi_DataBufferType *pCurrentTxBuffer;
    const Spi_DataBufferType *pCurrentRxBuffer;
    struct Spi_Driver_Handler *perCoreHandler = Spi_Handler[coreId];
    const Spi_ChannelCfgType *ptrChannelConfig;
    const struct mld_spi_device *dev =
            &perCoreHandler->spiDevice[ptrJobConfig->deviceIdx].device;

    /* #10 when the seuqnece is start to transmit  set the jobId result as pending */
    perCoreHandler->jobResultArr[jobId] = SPI_JOB_PENDING;

    /* #20 is the this job is soft chip select mode do pin setup */
    if (CS_VIA_GPIO == ptrJobConfig->CSHandling)
    {
        /* is the hw cs index 0 signal was used for another device need
        to disconnect is from spi controler */
        if (TRUE == ptrJobConfig->hwCS0Enable)
        {
            oldMux = Spi_GetPinMux(ptrJobConfig->hwCs0PinId);
            /* set port state befor tramsmit data */
            Spi_HardWareQuirkCs(ptrJobConfig->hwCs0PinId, SPI_PIN_MUX_ALT0,
                                ptrJobConfig->HwCSPolarity, TRUE);
        }

        /* set the soft cs pin index low layer software */
        Spi_Mld_SetSoftCsId(dev->bus, ptrJobConfig->softCsPin);
    }

    /* #30 Send the Data configured for the channels with in the jobId */
    for (channIdx = 0; channIdx < ptrJobConfig->numOfChannels; channIdx++)
    {
        channelId = ptrJobConfig->channelList[channIdx];
        ptrChannelConfig = &(Spi_ChannelConfig[channelId]);

        /* #40 if the channel type is internal buffer  get the buffer
        from configurations  otherwise get from user setup*/
        if (IB == ptrChannelConfig->channelBufferType)
        {
            /* get from driver defined buffers */
            pCurrentRxBuffer = (Spi_DataBufferType *)ptrChannelConfig->readBufferIndex;
            pCurrentTxBuffer = (const Spi_DataBufferType *)ptrChannelConfig->writeBufferIndex;
            length = (uint16)ptrChannelConfig->bufferSize;
        }
        else
        {
            /* get from users setup buffers,Des and Src  probably is NULL_PTR but not both */
            pCurrentRxBuffer = (Spi_DataBufferType *)perCoreHandler->externalBuffCb[\
                               channelId].desDataBufferPtr;

            pCurrentTxBuffer = (const Spi_DataBufferType *)perCoreHandler->externalBuffCb[\
                               channelId].srcDataBufferPtr;
            length = perCoreHandler->externalBuffCb[channelId].length;
        }

        /* update to relevent channale control blocks */
        perCoreHandler->spiChannelCB[channelId].len = length;

        /* update the buffer width type */
        if (0x9u > ptrChannelConfig->dataWidth  )
        {
            perCoreHandler->spiChannelCB[channelId].widthType = SPI_DATA_WIDTH_BYTE;
        }
        else if (0x11U > ptrChannelConfig->dataWidth )
        {
            perCoreHandler->spiChannelCB[channelId].widthType = SPI_DATA_WIDTH_HALF_WORD;
        }
        else
        {
            perCoreHandler->spiChannelCB[channelId].widthType = SPI_DATA_WIDTH_WORD;
        }

        /* IB Buffer ignore the user rx enable or not and the EB If the buffer is null point to dummy buffer  */
        if (NULL_PTR != pCurrentRxBuffer)
        {
            /*PRQA S 0306  1*/
            perCoreHandler->spiChannelCB[channelId].prxdata = (uint32)pCurrentRxBuffer;
            perCoreHandler->spiChannelCB[channelId].isRxDummy = 0;
        }
        else
        {
            /*PRQA S 0306  1*/
            perCoreHandler->spiChannelCB[channelId].prxdata = (uint32)&perCoreHandler->dummyRxBuffer;
            perCoreHandler->spiChannelCB[channelId].isRxDummy = 1;
        }

        if (NULL_PTR != pCurrentTxBuffer)
        {
            /*PRQA S 0306  1*/
            perCoreHandler->spiChannelCB[channelId].ptxdata = (uint32)pCurrentTxBuffer;
            perCoreHandler->spiChannelCB[channelId].isTxDummy = 0;
        }
        else
        {
            /*PRQA S 0306  1*/
            perCoreHandler->spiChannelCB[channelId].ptxdata = (uint32)&perCoreHandler->dummyTxBuffer;
            perCoreHandler->spiChannelCB[channelId].isTxDummy = 1;
        }
    }

    channelId = ptrJobConfig->channelList[0];
    /* #50  start the sequence to transmit synchronous */
    retValue = Spi_Mld_SyncVectorModeTransmitReceive(dev->bus, dev,
               &perCoreHandler->spiChannelCB[channelId]);

    /* Set the jobId status result */
    if ( 0 > retValue )
    {
        returnValue = E_NOT_OK;
        perCoreHandler->jobResultArr[jobId] = SPI_JOB_FAILED;
    }
    else
    {
        perCoreHandler->jobResultArr[jobId] = SPI_JOB_OK;
    }

    /*#60 if the job is soft chip select mode need restore the hw and deassert the chip select */
    if (CS_VIA_GPIO == ptrJobConfig->CSHandling)
    {
        /* Hw cs0 is used fron anther extenal device need recover cs0 pin mux */
        if (TRUE == ptrJobConfig->hwCS0Enable)
        {
            /*PRQA S 2962 2*/
            Spi_HardWareQuirkCs(ptrJobConfig->hwCs0PinId, oldMux,
                                ptrJobConfig->HwCSPolarity, FALSE);
        }

        /* deassert the soft cs signal */
        if ((uint8)LOW == ptrJobConfig->CSPolarity )
        {
            Spi_SetIOLevel(ptrJobConfig->softCsPin, STD_HIGH);
        }
        else
        {
            Spi_SetIOLevel(ptrJobConfig->softCsPin, STD_LOW);
        }
    }

    if (NULL_PTR != ptrJobConfig->jobEndNotification)
    {
        ptrJobConfig->jobEndNotification();
    }/* else is not needed */

    return returnValue;
}
#endif

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
 *                      SWSR_SPI_063 SWSR_SPI_251 SWSR_SPI_253 SWSR_SPI_244
 *****************************************************************************************/
Std_ReturnType Spi_SeqSyncTransmit(Spi_SequenceType sequenceId,
                                   const Spi_SequenceCfgType *ptrSeqConfig)
{
    uint16 jobIndex;
    uint8 coreId = Spi_GetCoreID();
    const Spi_JobCfgType *tmpPtrJobConfig;
    Std_ReturnType returnValue = Spi_BufferHasSetuped(sequenceId);
    struct Spi_Driver_Handler *perCoreHandler = Spi_Handler[coreId];

    /* #10 update sequence status to Pending */
    perCoreHandler->seqResultArr[sequenceId] = SPI_SEQ_PENDING;

    /* #11 check the eb buffer */
    if(0u != Spi_TransmitExternalBuffCheck(sequenceId,perCoreHandler->externalBuffCb)){
        returnValue = E_NOT_OK;
    }

    /* #20 transmit the jobs of this sequence  one bu one,is anyone fail sequence
    transmirssion will abort */
    for (jobIndex = 0; ((jobIndex < (ptrSeqConfig->numOfJobs)) &&
                        (returnValue == E_OK)); jobIndex++)
    {
        tmpPtrJobConfig = &Spi_JobConfig[ptrSeqConfig->jobList[jobIndex]];
        returnValue = Spi_JobSyncTransmit(ptrSeqConfig->jobList[jobIndex], tmpPtrJobConfig);
    }

    /* #30 update the sequenceId result */
    if (E_OK == returnValue)
    {
        /* Change sequence status to OK */
        perCoreHandler->seqResultArr[sequenceId] = SPI_SEQ_OK;
    }
    else
    {
        perCoreHandler->seqResultArr[sequenceId] = SPI_SEQ_FAILED;
    }

    /* #40 If Needed callback the notfication */
    if (NULL_PTR != ptrSeqConfig->sequenceEndNotification)
    {
        ptrSeqConfig->sequenceEndNotification();
    }/* else is not needed */

    return returnValue;
}
#endif
/** *****************************************************************************************************
 * \brief This function returns the specify spi controler status .
 *
 * \verbatim
 * Syntax             : Spi_StatusType Spi_GetHWStatus(Spi_HWUnitType hwUnitId)
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
Spi_StatusType Spi_GetHWStatus(Spi_HWUnitType hwUnitId)
{
    Spi_StatusType retValue;
    uint8 coreId = Spi_GetCoreID();
    const struct Spi_Driver_Handler *perCoreHandler = Spi_Handler[coreId];
    const struct mld_spi_module *bus = &perCoreHandler->spiBus[hwUnitId].bus;

    /* #10 get the specify HwUint Status */
    if (0U == (bus->state & SPI_STATE_INITED))
    {
        retValue = SPI_UNINIT;
    }
    else if (0U != (bus->state & BUS_BUSY_MASK))
    {
        retValue = SPI_BUSY;
    }
    else
    {
        retValue = SPI_IDLE;
    }

    return retValue;
}

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
void Spi_TriggerOnceSchedule(void)
{
    /* #10 Try trigger once aysnc sequence transmit */
    Spi_ScheduleOnce();
}
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
 *                        E_NOT_OK: Transmission command has not been accepted
 *
 * Description        : Service to transmit data on the SPI bus.
 * \endverbatim
 * Traceability       : SWSR_SPI_038 SWSR_SPI_165 SWSR_SPI_166 SWSR_SPI_167 SWSR_SPI_170
 *                      SWSR_SPI_171
 *****************************************************************************************/
Std_ReturnType Spi_HwAsyncTransmit(Spi_SequenceType sequenceId)
{
    uint16 jobIdx;
    Spi_JobType jobId;
    uint8 coreId = Spi_GetCoreID();
    Std_ReturnType returnValue = E_OK;
    struct Spi_Driver_Handler *perCoreHandler = Spi_Handler[coreId];
    const struct Spi_Scheduler *pSchduler = &perCoreHandler->scheduler;
    const Spi_SequenceCfgType *seqConfigPtr = &Spi_SequenceConfig[sequenceId];
    SPI_DBG("%s call param %d \n", __FUNCTION__, sequenceId);

    /*#10 check Async scheduler not init */
    if ((enum scheSta)ASYNC_SCHE_UNINIT == pSchduler->schedulerState)
    {
        returnValue =  E_NOT_OK;
    }
    else
    {
        /* #20 Enter exclusive area avoid context switch(between the #20 to #90) cause
            abnormal driver behavior */
        SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_014();

        /* #30 Check whether the sequence is already running or not */
        if (SPI_SEQ_PENDING == perCoreHandler->seqResultArr[sequenceId])
        {
            /* Exit exclusive area */
            SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_014();
#if (SPI_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportRuntimeError(SPI_MODULE_ID, SPI_INSTANCE_ID,
                                         SPI_ASYNCTRANSMIT_SID,
                                         SPI_E_SEQ_PENDING);
#endif
            returnValue =  E_NOT_OK;
        }
        else
        {
            /* #40 enqueue the new sequence to schdule queue */
            if (E_OK != Spi_ScheOneSequence(sequenceId))
            {
                /* Exit exclusive area */
                SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_014();
                returnValue =  E_NOT_OK;
            }
            else
            {
                /* #50 [SWS_Spi_00020] The function Spi_AsyncTransmit shall take over the given parameter,
                    initiate a transmission,set the sequence result to SPI_SEQ_PENDING */
                perCoreHandler->seqResultArr[sequenceId] = SPI_SEQ_PENDING;
#if SPI_CANCEL_API == STD_ON
                /* #60 Clear last dummy cancel flags ,avoid the last cancel requenst not
                take effect and remain to next */
                perCoreHandler->seqIsCancel[sequenceId] = FALSE;
#endif
                /* Exit exclusive area */
                SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_014();
                /* #70 [SWS_Spi_00194]When the function Spi_AsyncTransmit is called,
                    shall take over the given parameter and set the jobId status to SPI_JOB_QUEUED,*/
                for (jobIdx = 0; jobIdx < seqConfigPtr->numOfJobs; jobIdx++)
                {
                    jobId = seqConfigPtr->jobList[jobIdx];
                    perCoreHandler->jobResultArr[jobId] = SPI_JOB_QUEUED;
                }

                /*  #80 trigger schedule try to select one job of ant sequence to transmit */
                Spi_ScheduleOnce();
            }
        }
    }

    return returnValue;
}
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
void Spi_HwMainFunctionHandling(const uint8 Hwidx)
{
#if ( SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || ( SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
    const uint8 coreId = Spi_GetCoreID();
    struct Spi_Driver_Handler *perCoreHandler = Spi_Handler[coreId];
    /* #10 mld async core function to handle FIFO read/write and transfer status maintenance */
    sint32 retValue = Spi_Mld_PollingHandle(&perCoreHandler->spiBus[Hwidx].bus);

    /* #20 if the Spi_Mld_PollingHandle return 0 means one job is finished
    tranmsit hav an hwUint is idle can schduler next job to transmit */
    if (0 == retValue)
    {
        /* #30 do Job finished pricess and selecr next job to transmit */
        Spi_JobHandleFuntion(Hwidx);
    }

#endif
} /* end of Spi_HwMainFunctionHandling */
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
uint8 Spi_GetSpiChannelAssignCoreId(const Spi_ChannelType channel)
{
    uint16 jobIdx, chan;
    uint8 coreId = 0xFFU, coreIdx;

    for (jobIdx = 0; (jobIdx < SPI_TOTAL_JOB_COUNT) && (0xFFU == coreId); jobIdx++)
    {
        for (chan = 0; (chan < Spi_JobConfig[jobIdx].numOfChannels) && (0xFFU == coreId); chan++)
        {
            if (Spi_JobConfig[jobIdx].channelList[chan] == channel)
            {
                for (coreIdx = 0; (coreIdx < (uint8)5) && (0xFFU == coreId); coreIdx++)
                {
                    if (0U != (Spi_InstanceMask_Config[coreIdx] &
                               ((uint8)0x01 << Spi_JobConfig[jobIdx].hwUnitId)))
                    {
                        coreId = coreIdx;
                    }
                }
            }
        }
    }

    /*Default assign to sf core */
    if ( 0xFFU == coreId )
    {
        coreId = 0;
    }

    return coreId;
}
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
uint8 Spi_GetSpiJobAssignCoreId(const Spi_JobType jobId)
{
    uint8 coreIdx;
    /*Default assign to sf core */
    uint8 coreId = 0;

    for (coreIdx = 0; coreIdx < (uint8)5; coreIdx++)
    {
        if (0U != (Spi_InstanceMask_Config[coreIdx] &
                   ((uint8)0x01 << Spi_JobConfig[jobId].hwUnitId)))
        {
            coreId = coreIdx;
            break;
        }
    }

    return coreId;
}
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
uint8 Spi_GetSpiSequenceAssignCoreId(const Spi_SequenceType sequenceId)
{
    return Spi_GetSpiJobAssignCoreId(Spi_SequenceConfig[sequenceId].jobList[0]);
}

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#ifdef __cplusplus
}
#endif
/** End of file */
