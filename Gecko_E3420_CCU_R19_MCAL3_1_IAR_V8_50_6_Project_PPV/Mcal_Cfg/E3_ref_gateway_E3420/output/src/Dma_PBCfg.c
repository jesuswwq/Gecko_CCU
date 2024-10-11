/** *****************************************************************************************************
 * SEMIDRIVE Copyright Statement                                                                        *
 * Copyright (c) SEMIDRIVE. All rights reserved                                                         *
 *                                                                                                      *
 * This software and all rights therein are owned by SEMIDRIVE, and are                                 *
 * protected by copyright law and other relevant laws, regulations and                                  *
 * protection. Without SEMIDRIVE's prior written consent and/or related rights,                         *
 * please do not use this software or any potion thereof in any form or by any                          *
 * means. You may not reproduce, modify or distribute this software except in                           *
 * compliance with the License. Unless required by applicable law or agreed to                          *
 * in writing, software distributed under the License is distributed on                                 *
 * an 'AS IS' basis, WITHOUT WARRANTIES OF ANY KIND, either express or implied.                         *
 *                                                                                                      *
 *******************************************************************************************************/
/** *****************************************************************************************************
 *  \file     Dma_Cfg.h                                                                                 *
 *  \brief    This file contains generated pre compile configuration file for                           *
 *            DMA MCAL driver                                                                           *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date                 <th>Version                                                             *
 * <tr><td>2024-03-08 16:29:00  <td>3.0.0 R                                                             *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "__regs_base.h"
#include "Dma.h"
/********************************************************************************************************
 *                                 Private Macro definition                                             *
 *******************************************************************************************************/

/********************************************************************************************************
 *                                  Global Constant Declarations                                        *
 *******************************************************************************************************/
#define DMA_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dma_MemMap.h"
/** Traceability       : SWSR_DMA_045 */
/* DMA support configuration options for the user of E3 peripheral */
/** \brief  Dma adc module configuration parameters table */
DMA_LOCAL const Dma_AdcConfigType Dma_AdcConfigTable[] =
{
    {
        /* AdcControllerId = */DMA_HW_UNIT_UNDEFINE,
        /* CoreId          = */0xFFU,
        /* Adc_Fifo0       = */
        {
            /* *Controller = */DMA_HW_UNDEFINE,
            /* ChannelId   = */0xFFU,
        },
        /* Adc_Fifo1       = */
        {
            /* *Controller = */DMA_HW_UNDEFINE,
            /* ChannelId   = */0xFFU,
        },
        /* Adc_Fifo2       = */
        {
            /* *Controller = */DMA_HW_UNDEFINE,
            /* ChannelId   = */0xFFU,
        },
        /* Adc_Fifo3       = */
        {
            /* *Controller = */DMA_HW_UNDEFINE,
            /* ChannelId   = */0xFFU,
        }
    }
};

/** \brief  Dma icu module configuration parameters table */
DMA_LOCAL const Dma_IcuConfigType Dma_IcuConfigTable[] =
{
    {
        /* IcuControllerId = */DMA_ICU_INDEX_ETIMER1,
        /* CoreId          = */(uint8)DMA_CPU_ID_CORE0,
        /* Icu_Capture_A   = */
        {
            /* *Controller = */DMA_HW_UNDEFINE,
            /* ChannelId   = */0xFFU,
        },
        /* Icu_Capture_B   = */
        {
            /* *Controller = */DMA_HW_SF0,
            /* ChannelId   = */4U,
        },
        /* Icu_Capture_C   = */
        {
            /* *Controller = */DMA_HW_SF0,
            /* ChannelId   = */5U,
        },
        /* Icu_Capture_D   = */
        {
            /* *Controller = */DMA_HW_UNDEFINE,
            /* ChannelId   = */0xFFU,
        },
        /* Icu_Capture_CE   = */
        {
            /* *Controller = */DMA_HW_UNDEFINE,
            /* ChannelId   = */0xFFU,
        }
    },
    {
        /* IcuControllerId = */DMA_ICU_INDEX_ETIMER3,
        /* CoreId          = */(uint8)DMA_CPU_ID_CORE0,
        /* Icu_Capture_A   = */
        {
            /* *Controller = */DMA_HW_UNDEFINE,
            /* ChannelId   = */0xFFU,
        },
        /* Icu_Capture_B   = */
        {
            /* *Controller = */DMA_HW_SF0,
            /* ChannelId   = */6U,
        },
        /* Icu_Capture_C   = */
        {
            /* *Controller = */DMA_HW_UNDEFINE,
            /* ChannelId   = */0xFFU,
        },
        /* Icu_Capture_D   = */
        {
            /* *Controller = */DMA_HW_UNDEFINE,
            /* ChannelId   = */0xFFU,
        },
        /* Icu_Capture_CE   = */
        {
            /* *Controller = */DMA_HW_UNDEFINE,
            /* ChannelId   = */0xFFU,
        }
    },
    {
        /* IcuControllerId = */DMA_HW_UNIT_UNDEFINE,
        /* CoreId          = */0xFFU,
        /* Icu_Capture_A   = */
        {
            /* *Controller = */DMA_HW_UNDEFINE,
            /* ChannelId   = */0xFFU,
        },
        /* Icu_Capture_B   = */
        {
            /* *Controller = */DMA_HW_UNDEFINE,
            /* ChannelId   = */0xFFU,
        },
        /* Icu_Capture_C   = */
        {
            /* *Controller = */DMA_HW_UNDEFINE,
            /* ChannelId   = */0xFFU,
        },
        /* Icu_Capture_D   = */
        {
            /* *Controller = */DMA_HW_UNDEFINE,
            /* ChannelId   = */0xFFU,
        },
        /* Icu_Capture_CE   = */
        {
            /* *Controller = */DMA_HW_UNDEFINE,
            /* ChannelId   = */0xFFU,
        }
    }
};

/** \brief  Dma memory to memory configuration parameters table */
DMA_LOCAL const Dma_MemoryToMemoryConfigType Dma_MemToMemConfigTable[] =
{
    {
        /* memoryId        =*/DMA_HW_UNIT_UNDEFINE,
        /* CoreId          = */0xFFU,
        /* memoryToMemory  = */
        {
            /* *Controller = */DMA_HW_UNDEFINE,
            /* ChannelId   = */0xFFU,
        }
    }
};

/** \brief  Dma pwm module configuration parameters table */
DMA_LOCAL const Dma_PwmConfigType Dma_PwmConfigTable[] =
{
    {
        /* PwmControllerId = */DMA_EPWM1_INDEX,
        /* CoreId          = */(uint8)DMA_CPU_ID_CORE0,
        /* Pwm_FIFO_A      = */
        {
            /* *Controller = */DMA_HW_UNDEFINE,
            /* ChannelId   = */0xFFU,
        },
        /* Pwm_FIFO_B      = */
        {
            /* *Controller = */DMA_HW_SF0,
            /* ChannelId   = */2U,
        },
        /* Pwm_FIFO_C      = */
        {
            /* *Controller = */DMA_HW_UNDEFINE,
            /* ChannelId   = */0xFFU,
        },
        /* Pwm_FIFO_D      = */
        {
            /* *Controller = */DMA_HW_UNDEFINE,
            /* ChannelId   = */0xFFU,
        },
        /* Pwm_CE          = */
        {
            /* *Controller = */DMA_HW_UNDEFINE,
            /* ChannelId   = */0xFFU,
        }
    },
    {
        /* PwmControllerId = */DMA_EPWM2_INDEX,
        /* CoreId          = */(uint8)DMA_CPU_ID_CORE1,
        /* Pwm_FIFO_A      = */
        {
            /* *Controller = */DMA_HW_UNDEFINE,
            /* ChannelId   = */0xFFU,
        },
        /* Pwm_FIFO_B      = */
        {
            /* *Controller = */DMA_HW_SF0,
            /* ChannelId   = */3U,
        },
        /* Pwm_FIFO_C      = */
        {
            /* *Controller = */DMA_HW_UNDEFINE,
            /* ChannelId   = */0xFFU,
        },
        /* Pwm_FIFO_D      = */
        {
            /* *Controller = */DMA_HW_UNDEFINE,
            /* ChannelId   = */0xFFU,
        },
        /* Pwm_CE          = */
        {
            /* *Controller = */DMA_HW_UNDEFINE,
            /* ChannelId   = */0xFFU,
        }
    },
    {
        /* PwmControllerId = */DMA_HW_UNIT_UNDEFINE,
        /* CoreId          = */0xFFU,
        /* Pwm_FIFO_A      = */
        {
            /* *Controller = */DMA_HW_UNDEFINE,
            /* ChannelId   = */0xFFU,
        },
        /* Pwm_FIFO_B      = */
        {
            /* *Controller = */DMA_HW_UNDEFINE,
            /* ChannelId   = */0xFFU,
        },
        /* Pwm_FIFO_C      = */
        {
            /* *Controller = */DMA_HW_UNDEFINE,
            /* ChannelId   = */0xFFU,
        },
        /* Pwm_FIFO_D      = */
        {
            /* *Controller = */DMA_HW_UNDEFINE,
            /* ChannelId   = */0xFFU,
        },
        /* Pwm_CE          = */
        {
            /* *Controller = */DMA_HW_UNDEFINE,
            /* ChannelId   = */0xFFU,
        }
    }
};

/** \brief  Dma spi module configuration parameters table */
DMA_LOCAL const Dma_SpiConfigType Dma_SpiConfigTable[] =
{
    {
        /* SpiControllerId = */DMA_CSIB5,
        /* CoreId          = */(uint8)DMA_CPU_ID_CORE0,
        /* Spi_Tx          = */
        {
            /* *Controller = */DMA_HW_SF0,
            /* ChannelId   = */0U,
        },
        /* Spi_Rx          = */
        {
            /* *Controller = */DMA_HW_SF0,
            /* ChannelId   = */1U,
        }
    },
    {
        /* SpiControllerId = */DMA_HW_UNIT_UNDEFINE,
        /* CoreId          = */0xFFU,
        /* Spi_Tx          = */
        {
            /* *Controller = */DMA_HW_UNDEFINE,
            /* ChannelId   = */0xFFU,
        },
        /* Spi_Rx          = */
        {
            /* *Controller = */DMA_HW_UNDEFINE,
            /* ChannelId   = */0xFFU,
        }
    }
};

/** \brief  XSpi configuration parameters table */
DMA_LOCAL const Dma_XspiConfigType Dma_XspiConfigTable[] =
{
    {
        /* XSpiControllerId  = */DMA_XSPI0,
        /* CoreId            = */(uint8)DMA_CPU_ID_CORE0,
        /* XSpi_PortA_Read   = */
        {
            /* *Controller   = */DMA_HW_SF0,
            /* ChannelId     = */7U,
        },
        /* XSpi_PortA_Write  = */
        {
            /* *Controller   = */DMA_HW_SF0,
            /* ChannelId     = */8U,
        },
        /* XSpi_PortB_Read   = */
        {
            /* *Controller   = */DMA_HW_UNDEFINE,
            /* ChannelId     = */0xFFU,
        },
        /* XSpi_PortB_Write  = */
        {
            /* *Controller   = */DMA_HW_UNDEFINE,
            /* ChannelId     = */0xFFU,
        }
    },
    {
        /* XSpiControllerId  = */DMA_HW_UNIT_UNDEFINE,
        /* CoreId            = */0xFFU,
        /* XSpi_PortA_Read   = */
        {
            /* *Controller   = */DMA_HW_UNDEFINE,
            /* ChannelId     = */0xFFU,
        },
        /* XSpi_PortA_Write  = */
        {
            /* *Controller   = */DMA_HW_UNDEFINE,
            /* ChannelId     = */0xFFU,
        },
        /* XSpi_PortB_Read   = */
        {
            /* *Controller   = */DMA_HW_UNDEFINE,
            /* ChannelId     = */0xFFU,
        },
        /* XSpi_PortB_Write  = */
        {
            /* *Controller   = */DMA_HW_UNDEFINE,
            /* ChannelId     = */0xFFU,
        }
    }
};

/** \brief  XTRG configuration parameters table */
DMA_LOCAL const Dma_XtrgConfigType Dma_XtrgConfigTable[] =
{
    {
        /* xtrgControllerId  = */DMA_HW_UNIT_UNDEFINE,
        /* CoreId            = */0xFFU,
        /* xtrg0             = */
        {
            /* *Controller   = */DMA_HW_UNDEFINE,
            /* ChannelId     = */0xFFU,
        },
        /* xtrg1             = */
        {
            /* *Controller   = */DMA_HW_UNDEFINE,
            /* ChannelId     = */0xFFU,
        }
    }
};

/** \brief  Dma SF0 channels allocated on core SF */
DMA_LOCAL const Dma_ChannelType Dma_SF0AllocateOnCore0 [DMA_CHANNEL_SF0_ON_CORE0_NUMBER + 1U] = {0U, 1U, 2U, 4U, 5U, 6U, 7U, 8U, 0xFFU};

/** \brief  Dma SF0 channels allocated on core SX0 */
DMA_LOCAL const Dma_ChannelType Dma_SF0AllocateOnCore1[DMA_CHANNEL_SF0_ON_CORE1_NUMBER + 1U] = {3U, 0xFFU};

/** \brief  Dma SF0 channels allocated on core SX1 */
DMA_LOCAL const Dma_ChannelType Dma_SF0AllocateOnCore2[DMA_CHANNEL_SF0_ON_CORE2_NUMBER + 1U] = {0xFFU};

/** \brief  Dma SF0 channels allocated on core SP0 */
DMA_LOCAL const Dma_ChannelType Dma_SF0AllocateOnCore3[DMA_CHANNEL_SF0_ON_CORE3_NUMBER + 1U] = {0xFFU};

/** \brief  Dma SF0 channels allocated on core SP1 */
DMA_LOCAL const Dma_ChannelType Dma_SF0AllocateOnCore4[DMA_CHANNEL_SF0_ON_CORE4_NUMBER + 1U] = {0xFFU};

#if (DMA_LOCK_STEP_MODE == STD_OFF)
/** \brief  Dma SF1 channels allocated on core SF */
DMA_LOCAL const Dma_ChannelType Dma_SF1AllocateOnCore0 [DMA_CHANNEL_SF1_ON_CORE0_NUMBER + 1U] = {0xFFU};

/** \brief  Dma SF1 channels allocated on core SX0 */
DMA_LOCAL const Dma_ChannelType Dma_SF1AllocateOnCore1[DMA_CHANNEL_SF1_ON_CORE1_NUMBER + 1U] = {0xFFU};

/** \brief  Dma SF1 channels allocated on core SX1 */
DMA_LOCAL const Dma_ChannelType Dma_SF1AllocateOnCore2[DMA_CHANNEL_SF1_ON_CORE2_NUMBER + 1U] = {0xFFU};

/** \brief  Dma SF1 channels allocated on core SP0 */
DMA_LOCAL const Dma_ChannelType Dma_SF1AllocateOnCore3[DMA_CHANNEL_SF1_ON_CORE3_NUMBER + 1U] = {0xFFU};

/** \brief  Dma SF1 channels allocated on core SP1 */
DMA_LOCAL const Dma_ChannelType Dma_SF1AllocateOnCore4[DMA_CHANNEL_SF1_ON_CORE4_NUMBER + 1U] = {0xFFU};
#endif /* #if (DMA_LOCK_STEP_MODE == STD_OFF) */


#ifndef SEMIDRIVE_E3_LITE_SERIES
/** \brief  The table provides the DMA map between the peripheral modules and DMA Controller in safety domain. */
DMA_LOCAL const Dma_MuxParamType Dma_SFMuxTable[] =
{
    /* port */              /* startAddress */              /* length *//* muxDirect */
    {(uint16)DMA_MUX_ID_CANFD1,     DMA_DEVICE_BASE(CANFD1),        0x80U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_CANFD2,     DMA_DEVICE_BASE(CANFD2),        0x80U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_CANFD3,     DMA_DEVICE_BASE(CANFD3),        0x80U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_CANFD4,     DMA_DEVICE_BASE(CANFD4),        0x80U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_CANFD5,     DMA_DEVICE_BASE(CANFD5),        0x80U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_CANFD6,     DMA_DEVICE_BASE(CANFD6),        0x80U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_CANFD7,     DMA_DEVICE_BASE(CANFD7),        0x80U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_CANFD8,     DMA_DEVICE_BASE(CANFD8),        0x80U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_CANFD9,     DMA_DEVICE_BASE(CANFD9),        0x80U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_CANFD10,    DMA_DEVICE_BASE(CANFD10),       0x80U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_CANFD11,    DMA_DEVICE_BASE(CANFD11),       0x80U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_CANFD12,    DMA_DEVICE_BASE(CANFD12),       0x80U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_CANFD13,    DMA_DEVICE_BASE(CANFD13),       0x80U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_CANFD14,    DMA_DEVICE_BASE(CANFD14),       0x80U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_CANFD15,    DMA_DEVICE_BASE(CANFD15),       0x80U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_CANFD16,    DMA_DEVICE_BASE(CANFD16),       0x80U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_CANFD17,    DMA_DEVICE_BASE(CANFD17),       0x80U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_CANFD18,    DMA_DEVICE_BASE(CANFD18),       0x80U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_CANFD19,    DMA_DEVICE_BASE(CANFD19),       0x80U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_CANFD20,    DMA_DEVICE_BASE(CANFD20),       0x80U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_CANFD21,    DMA_DEVICE_BASE(CANFD21),       0x80U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_CANFD22,    DMA_DEVICE_BASE(CANFD22),       0x80U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_CANFD23,    DMA_DEVICE_BASE(CANFD23),       0x80U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_CANFD24,    DMA_DEVICE_BASE(CANFD24),       0x80U,      DMA_MUX_BOTH},
    /* port */              /* startAddress */              /* length *//* muxDirect */
    {(uint16)DMA_MUX_ID_I2C1,       DMA_DEVICE_BASE(I2C1),          0x200U,     DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_I2C2,       DMA_DEVICE_BASE(I2C2),          0x200U,     DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_I2C3,       DMA_DEVICE_BASE(I2C3),          0x200U,     DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_I2C4,       DMA_DEVICE_BASE(I2C4),          0x200U,     DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_I2C5,       DMA_DEVICE_BASE(I2C5),          0x200U,     DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_I2C6,       DMA_DEVICE_BASE(I2C6),          0x200U,     DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_I2C7,       DMA_DEVICE_BASE(I2C7),          0x200U,     DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_I2C8,       DMA_DEVICE_BASE(I2C8),          0x200U,     DMA_MUX_WR},
    /* port */              /* startAddress */              /* length *//* muxDirect */
    {(uint16)DMA_MUX_ID_I2C1,       DMA_DEVICE_BASE(I2C1),          0x300U,     DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_I2C2,       DMA_DEVICE_BASE(I2C2),          0x300U,     DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_I2C3,       DMA_DEVICE_BASE(I2C3),          0x300U,     DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_I2C4,       DMA_DEVICE_BASE(I2C4),          0x300U,     DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_I2C5,       DMA_DEVICE_BASE(I2C5),          0x300U,     DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_I2C6,       DMA_DEVICE_BASE(I2C6),          0x300U,     DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_I2C7,       DMA_DEVICE_BASE(I2C7),          0x300U,     DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_I2C8,       DMA_DEVICE_BASE(I2C8),          0x300U,     DMA_MUX_RD},
    /* port */              /* startAddress */              /* length *//* muxDirect */
    {(uint16)DMA_MUX_ID_XSPI1_A_RD, DMA_DEVICE_BASE(XSPI1PORTA),    0x380U,     DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_XSPI1_A_WR, DMA_DEVICE_BASE(XSPI1PORTA),    0x280U,     DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_XSPI1_B_RD, DMA_DEVICE_BASE(XSPI1PORTB),    0x380U,     DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_XSPI1_B_WR, DMA_DEVICE_BASE(XSPI1PORTB),    0x280U,     DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_XSPI2_A_RD, DMA_DEVICE_BASE(XSPI2PORTA),    0x380U,     DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_XSPI2_A_WR, DMA_DEVICE_BASE(XSPI2PORTA),    0x280U,     DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_XSPI2_B_RD, DMA_DEVICE_BASE(XSPI2PORTB),    0x380U,     DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_XSPI2_B_WR, DMA_DEVICE_BASE(XSPI2PORTB),    0x280U,     DMA_MUX_WR},
    /* port */              /* startAddress */              /* length *//* muxDirect */
    {(uint16)DMA_MUX_ID_SPI1_RX,    DMA_DEVICE_BASE(SPI1),          0x3000U,    DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_SPI1_TX,    DMA_DEVICE_BASE(SPI1),          0x2000U,    DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_SPI2_RX,    DMA_DEVICE_BASE(SPI2),          0x3000U,    DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_SPI2_TX,    DMA_DEVICE_BASE(SPI2),          0x2000U,    DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_SPI3_RX,    DMA_DEVICE_BASE(SPI3),          0x3000U,    DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_SPI3_TX,    DMA_DEVICE_BASE(SPI3),          0x2000U,    DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_SPI4_RX,    DMA_DEVICE_BASE(SPI4),          0x3000U,    DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_SPI4_TX,    DMA_DEVICE_BASE(SPI4),          0x2000U,    DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_SPI5_RX,    DMA_DEVICE_BASE(SPI5),          0x3000U,    DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_SPI5_TX,    DMA_DEVICE_BASE(SPI5),          0x2000U,    DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_SPI6_RX,    DMA_DEVICE_BASE(SPI6),          0x3000U,    DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_SPI6_TX,    DMA_DEVICE_BASE(SPI6),          0x2000U,    DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_SPI7_RX,    DMA_DEVICE_BASE(SPI7),          0x3000U,    DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_SPI7_TX,    DMA_DEVICE_BASE(SPI7),          0x2000U,    DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_SPI8_RX,    DMA_DEVICE_BASE(SPI8),          0x3000U,    DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_SPI8_TX,    DMA_DEVICE_BASE(SPI8),          0x2000U,    DMA_MUX_WR},
    /* port */              /* startAddress */              /* length *//* muxDirect */
    {(uint16)DMA_MUX_ID_EPWM1_A,    DMA_DEVICE_BASE(EPWM1),         0xC0U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_EPWM1_B,    DMA_DEVICE_BASE(EPWM1),         0xC4U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_EPWM1_C,    DMA_DEVICE_BASE(EPWM1),         0xC8U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_EPWM1_D,    DMA_DEVICE_BASE(EPWM1),         0xCCU,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_EPWM1_OVF,  DMA_DEVICE_BASE(EPWM1),         0x104U,     DMA_MUX_BOTH},
    /* port */              /* startAddress */              /* length *//* muxDirect */
    {(uint16)DMA_MUX_ID_EPWM2_A,    DMA_DEVICE_BASE(EPWM2),         0xC0U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_EPWM2_B,    DMA_DEVICE_BASE(EPWM2),         0xC4U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_EPWM2_C,    DMA_DEVICE_BASE(EPWM2),         0xC8U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_EPWM2_D,    DMA_DEVICE_BASE(EPWM2),         0xCCU,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_EPWM2_OVF,  DMA_DEVICE_BASE(EPWM2),         0x104U,     DMA_MUX_BOTH},
    /* port */              /* startAddress */              /* length *//* muxDirect */
    {(uint16)DMA_MUX_ID_EPWM3_A,    DMA_DEVICE_BASE(EPWM3),         0xC0U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_EPWM3_B,    DMA_DEVICE_BASE(EPWM3),         0xC4U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_EPWM3_C,    DMA_DEVICE_BASE(EPWM3),         0xC8U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_EPWM3_D,    DMA_DEVICE_BASE(EPWM3),         0xCCU,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_EPWM3_OVF,  DMA_DEVICE_BASE(EPWM3),         0x104U,     DMA_MUX_BOTH},
    /* port */              /* startAddress */              /* length *//* muxDirect */
    {(uint16)DMA_MUX_ID_EPWM4_A,    DMA_DEVICE_BASE(EPWM4),         0xC0U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_EPWM4_B,    DMA_DEVICE_BASE(EPWM4),         0xC4U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_EPWM4_C,    DMA_DEVICE_BASE(EPWM4),         0xC8U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_EPWM4_D,    DMA_DEVICE_BASE(EPWM4),         0xCCU,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_EPWM4_OVF,  DMA_DEVICE_BASE(EPWM4),         0x104U,     DMA_MUX_BOTH},
    /* port */              /* startAddress */              /* length *//* muxDirect */
    {(uint16)DMA_MUX_ID_ETMR1_A,    DMA_DEVICE_BASE(ETMR1),         0xC0U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_ETMR1_B,    DMA_DEVICE_BASE(ETMR1),         0xC4U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_ETMR1_C,    DMA_DEVICE_BASE(ETMR1),         0xC8U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_ETMR1_D,    DMA_DEVICE_BASE(ETMR1),         0xCCU,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_ETMR1_OVF,  DMA_DEVICE_BASE(ETMR1),         0x104U,     DMA_MUX_BOTH},
    /* port */              /* startAddress */              /* length *//* muxDirect */
    {(uint16)DMA_MUX_ID_ETMR2_A,    DMA_DEVICE_BASE(ETMR2),         0xC0U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_ETMR2_B,    DMA_DEVICE_BASE(ETMR2),         0xC4U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_ETMR2_C,    DMA_DEVICE_BASE(ETMR2),         0xC8U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_ETMR2_D,    DMA_DEVICE_BASE(ETMR2),         0xCCU,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_ETMR2_OVF,  DMA_DEVICE_BASE(ETMR2),         0x104U,     DMA_MUX_BOTH},
    /* port */              /* startAddress */              /* length *//* muxDirect */
    {(uint16)DMA_MUX_ID_ETMR3_A,    DMA_DEVICE_BASE(ETMR3),         0xC0U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_ETMR3_B,    DMA_DEVICE_BASE(ETMR3),         0xC4U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_ETMR3_C,    DMA_DEVICE_BASE(ETMR3),         0xC8U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_ETMR3_D,    DMA_DEVICE_BASE(ETMR3),         0xCCU,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_ETMR3_OVF,  DMA_DEVICE_BASE(ETMR3),         0x104U,     DMA_MUX_BOTH},
    /* port */              /* startAddress */              /* length *//* muxDirect */
    {(uint16)DMA_MUX_ID_ETMR4_A,    DMA_DEVICE_BASE(ETMR4),         0xC0U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_ETMR4_B,    DMA_DEVICE_BASE(ETMR4),         0xC4U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_ETMR4_C,    DMA_DEVICE_BASE(ETMR4),         0xC8U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_ETMR4_D,    DMA_DEVICE_BASE(ETMR4),         0xCCU,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_ETMR4_OVF,  DMA_DEVICE_BASE(ETMR4),         0x104U,     DMA_MUX_BOTH},
    /* port */              /* startAddress */              /* length *//* muxDirect */
    {(uint16)DMA_MUX_ID_XTRG_0,     DMA_DEVICE_BASE(XTRG),          0x200U,     DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_XTRG_1,     DMA_DEVICE_BASE(XTRG),          0x200U,     DMA_MUX_BOTH},
    /* port */              /* startAddress */              /* length *//* muxDirect */
    {(uint16)DMA_MUX_ID_UART1_TX,   DMA_DEVICE_BASE(UART1),         0x200U,     DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_UART1_RX,   DMA_DEVICE_BASE(UART1),         0x300U,     DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_UART2_TX,   DMA_DEVICE_BASE(UART2),         0x200U,     DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_UART2_RX,   DMA_DEVICE_BASE(UART2),         0x300U,     DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_UART3_TX,   DMA_DEVICE_BASE(UART3),         0x200U,     DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_UART3_RX,   DMA_DEVICE_BASE(UART3),         0x300U,     DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_UART4_TX,   DMA_DEVICE_BASE(UART4),         0x200U,     DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_UART4_RX,   DMA_DEVICE_BASE(UART4),         0x300U,     DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_UART5_TX,   DMA_DEVICE_BASE(UART5),         0x200U,     DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_UART5_RX,   DMA_DEVICE_BASE(UART5),         0x300U,     DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_UART6_TX,   DMA_DEVICE_BASE(UART6),         0x200U,     DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_UART6_RX,   DMA_DEVICE_BASE(UART6),         0x300U,     DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_UART7_TX,   DMA_DEVICE_BASE(UART7),         0x200U,     DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_UART7_RX,   DMA_DEVICE_BASE(UART7),         0x300U,     DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_UART8_TX,   DMA_DEVICE_BASE(UART8),         0x200U,     DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_UART8_RX,   DMA_DEVICE_BASE(UART8),         0x300U,     DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_UART9_TX,   DMA_DEVICE_BASE(UART9),         0x200U,     DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_UART9_RX,   DMA_DEVICE_BASE(UART9),         0x300U,     DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_UART10_TX,  DMA_DEVICE_BASE(UART10),        0x200U,     DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_UART10_RX,  DMA_DEVICE_BASE(UART10),        0x300U,     DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_UART11_TX,  DMA_DEVICE_BASE(UART11),        0x200U,     DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_UART11_RX,  DMA_DEVICE_BASE(UART11),        0x300U,     DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_UART12_TX,  DMA_DEVICE_BASE(UART12),        0x200U,     DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_UART12_RX,  DMA_DEVICE_BASE(UART12),        0x300U,     DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_UART13_TX,  DMA_DEVICE_BASE(UART13),        0x200U,     DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_UART13_RX,  DMA_DEVICE_BASE(UART13),        0x300U,     DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_UART14_TX,  DMA_DEVICE_BASE(UART14),        0x200U,     DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_UART14_RX,  DMA_DEVICE_BASE(UART14),        0x300U,     DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_UART15_TX,  DMA_DEVICE_BASE(UART15),        0x200U,     DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_UART15_RX,  DMA_DEVICE_BASE(UART15),        0x300U,     DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_UART16_TX,  DMA_DEVICE_BASE(UART16),        0x200U,     DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_UART16_RX,  DMA_DEVICE_BASE(UART16),        0x300U,     DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_ADC1_0,     DMA_DEVICE_BASE(ADC1),          0x3C0U,     DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_ADC1_1,     DMA_DEVICE_BASE(ADC1),          0x3C0U,     DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_ADC2_0,     DMA_DEVICE_BASE(ADC2),          0x3C0U,     DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_ADC2_1,     DMA_DEVICE_BASE(ADC2),          0x3C0U,     DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_ADC3_0,     DMA_DEVICE_BASE(ADC3),          0x3C0U,     DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_ADC3_1,     DMA_DEVICE_BASE(ADC3),          0x3C0U,     DMA_MUX_BOTH},
    /* port */              /* startAddress */              /* length *//* muxDirect */
    {(uint16)DMA_MUX_ID_ISTC,       DMA_DEVICE_BASE(ISTC),          0xFFFFU,    DMA_MUX_BOTH},
};
#else
/** \brief  The table provides the DMA map between the peripheral modules and DMA Controller in safety domain. */
DMA_LOCAL Dma_MuxParamType const Dma_SFMuxTable[] =
{
    /* port */              /* startAddress */              /* length *//* muxDirect */
    {(uint16)DMA_MUX_ID_CANFD16,    DMA_DEVICE_BASE(CANFD16),       0x80U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_CANFD21,    DMA_DEVICE_BASE(CANFD21),       0x80U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_CANFD3,     DMA_DEVICE_BASE(CANFD3),        0x80U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_CANFD4,     DMA_DEVICE_BASE(CANFD4),        0x80U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_CANFD5,     DMA_DEVICE_BASE(CANFD5),        0x80U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_CANFD6,     DMA_DEVICE_BASE(CANFD6),        0x80U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_CANFD7,     DMA_DEVICE_BASE(CANFD7),        0x80U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_CANFD23,    DMA_DEVICE_BASE(CANFD23),       0x80U,      DMA_MUX_BOTH},
    /* port */              /* startAddress */              /* length *//* muxDirect */
    {(uint16)DMA_MUX_ID_I2C1,       DMA_DEVICE_BASE(I2C1),          0x200U,     DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_I2C2,       DMA_DEVICE_BASE(I2C2),          0x200U,     DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_I2C3,       DMA_DEVICE_BASE(I2C3),          0x200U,     DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_I2C4,       DMA_DEVICE_BASE(I2C4),          0x200U,     DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_I2C5,       DMA_DEVICE_BASE(I2C5),          0x200U,     DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_I2C6,       DMA_DEVICE_BASE(I2C6),          0x200U,     DMA_MUX_WR},
    /* port */              /* startAddress */              /* length *//* muxDirect */
    {(uint16)DMA_MUX_ID_I2C1,       DMA_DEVICE_BASE(I2C1),          0x300U,     DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_I2C2,       DMA_DEVICE_BASE(I2C2),          0x300U,     DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_I2C3,       DMA_DEVICE_BASE(I2C3),          0x300U,     DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_I2C4,       DMA_DEVICE_BASE(I2C4),          0x300U,     DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_I2C5,       DMA_DEVICE_BASE(I2C5),          0x300U,     DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_I2C6,       DMA_DEVICE_BASE(I2C6),          0x300U,     DMA_MUX_RD},
    /* port */              /* startAddress */              /* length *//* muxDirect */
    {(uint16)DMA_MUX_ID_XSPI1_A_RD, DMA_DEVICE_BASE(XSPI1PORTA),    0x380U,     DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_XSPI1_A_WR, DMA_DEVICE_BASE(XSPI1PORTA),    0x280U,     DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_XSPI1_B_RD, DMA_DEVICE_BASE(XSPI1PORTB),    0x380U,     DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_XSPI1_B_WR, DMA_DEVICE_BASE(XSPI1PORTB),    0x280U,     DMA_MUX_WR},
    /* port */              /* startAddress */              /* length *//* muxDirect */
    {(uint16)DMA_MUX_ID_SPI1_RX,    DMA_DEVICE_BASE(SPI1),          0x3000U,    DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_SPI1_TX,    DMA_DEVICE_BASE(SPI1),          0x2000U,    DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_SPI2_RX,    DMA_DEVICE_BASE(SPI2),          0x3000U,    DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_SPI2_TX,    DMA_DEVICE_BASE(SPI2),          0x2000U,    DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_SPI3_RX,    DMA_DEVICE_BASE(SPI3),          0x3000U,    DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_SPI3_TX,    DMA_DEVICE_BASE(SPI3),          0x2000U,    DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_SPI4_RX,    DMA_DEVICE_BASE(SPI4),          0x3000U,    DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_SPI4_TX,    DMA_DEVICE_BASE(SPI4),          0x2000U,    DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_SPI5_RX,    DMA_DEVICE_BASE(SPI5),          0x3000U,    DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_SPI5_TX,    DMA_DEVICE_BASE(SPI5),          0x2000U,    DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_SPI6_RX,    DMA_DEVICE_BASE(SPI6),          0x3000U,    DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_SPI6_TX,    DMA_DEVICE_BASE(SPI6),          0x2000U,    DMA_MUX_WR},
    /* port */              /* startAddress */              /* length *//* muxDirect */
    {(uint16)DMA_MUX_ID_EPWM1_A,    DMA_DEVICE_BASE(EPWM1),         0xC0U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_EPWM1_B,    DMA_DEVICE_BASE(EPWM1),         0xC4U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_EPWM1_C,    DMA_DEVICE_BASE(EPWM1),         0xC8U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_EPWM1_D,    DMA_DEVICE_BASE(EPWM1),         0xCCU,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_EPWM1_OVF,  DMA_DEVICE_BASE(EPWM1),         0x104U,     DMA_MUX_BOTH},
    /* port */              /* startAddress */              /* length *//* muxDirect */
    {(uint16)DMA_MUX_ID_EPWM2_A,    DMA_DEVICE_BASE(EPWM2),         0xC0U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_EPWM2_B,    DMA_DEVICE_BASE(EPWM2),         0xC4U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_EPWM2_C,    DMA_DEVICE_BASE(EPWM2),         0xC8U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_EPWM2_D,    DMA_DEVICE_BASE(EPWM2),         0xCCU,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_EPWM2_OVF,  DMA_DEVICE_BASE(EPWM2),         0x104U,     DMA_MUX_BOTH},
    /* port */              /* startAddress */              /* length *//* muxDirect */
    {(uint16)DMA_MUX_ID_ETMR1_A,    DMA_DEVICE_BASE(ETMR1),         0xC0U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_ETMR1_B,    DMA_DEVICE_BASE(ETMR1),         0xC4U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_ETMR1_C,    DMA_DEVICE_BASE(ETMR1),         0xC8U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_ETMR1_D,    DMA_DEVICE_BASE(ETMR1),         0xCCU,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_ETMR1_OVF,  DMA_DEVICE_BASE(ETMR1),         0x104U,     DMA_MUX_BOTH},
    /* port */              /* startAddress */              /* length *//* muxDirect */
    {(uint16)DMA_MUX_ID_ETMR2_A,    DMA_DEVICE_BASE(ETMR2),         0xC0U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_ETMR2_B,    DMA_DEVICE_BASE(ETMR2),         0xC4U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_ETMR2_C,    DMA_DEVICE_BASE(ETMR2),         0xC8U,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_ETMR2_D,    DMA_DEVICE_BASE(ETMR2),         0xCCU,      DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_ETMR2_OVF,  DMA_DEVICE_BASE(ETMR2),         0x104U,     DMA_MUX_BOTH},
    /* port */              /* startAddress */              /* length *//* muxDirect */
    {(uint16)DMA_MUX_ID_UART1_TX,   DMA_DEVICE_BASE(UART1),         0x200U,     DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_UART1_RX,   DMA_DEVICE_BASE(UART1),         0x300U,     DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_UART2_TX,   DMA_DEVICE_BASE(UART2),         0x200U,     DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_UART2_RX,   DMA_DEVICE_BASE(UART2),         0x300U,     DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_UART3_TX,   DMA_DEVICE_BASE(UART3),         0x200U,     DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_UART3_RX,   DMA_DEVICE_BASE(UART3),         0x300U,     DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_UART4_TX,   DMA_DEVICE_BASE(UART4),         0x200U,     DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_UART4_RX,   DMA_DEVICE_BASE(UART4),         0x300U,     DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_UART5_TX,   DMA_DEVICE_BASE(UART5),         0x200U,     DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_UART5_RX,   DMA_DEVICE_BASE(UART5),         0x300U,     DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_UART6_TX,   DMA_DEVICE_BASE(UART6),         0x200U,     DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_UART6_RX,   DMA_DEVICE_BASE(UART6),         0x300U,     DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_UART7_TX,   DMA_DEVICE_BASE(UART7),         0x200U,     DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_UART7_RX,   DMA_DEVICE_BASE(UART7),         0x300U,     DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_UART8_TX,   DMA_DEVICE_BASE(UART8),         0x200U,     DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_UART8_RX,   DMA_DEVICE_BASE(UART8),         0x300U,     DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_UART9_TX,   DMA_DEVICE_BASE(UART9),         0x200U,     DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_UART9_RX,   DMA_DEVICE_BASE(UART9),         0x300U,     DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_UART10_TX,  DMA_DEVICE_BASE(UART10),        0x200U,     DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_UART10_RX,  DMA_DEVICE_BASE(UART10),        0x300U,     DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_UART11_TX,  DMA_DEVICE_BASE(UART11),        0x200U,     DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_UART11_RX,  DMA_DEVICE_BASE(UART11),        0x300U,     DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_UART12_TX,  DMA_DEVICE_BASE(UART12),        0x200U,     DMA_MUX_WR},
    {(uint16)DMA_MUX_ID_UART12_RX,  DMA_DEVICE_BASE(UART12),        0x300U,     DMA_MUX_RD},
    {(uint16)DMA_MUX_ID_ADC1_0,     DMA_DEVICE_BASE(ADC1),          0x3C0U,     DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_ADC1_1,     DMA_DEVICE_BASE(ADC1),          0x3C0U,     DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_ADC2_0,     DMA_DEVICE_BASE(ADC2),          0x3C0U,     DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_ADC2_1,     DMA_DEVICE_BASE(ADC2),          0x3C0U,     DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_ADC3_0,     DMA_DEVICE_BASE(ADC3),          0x3C0U,     DMA_MUX_BOTH},
    {(uint16)DMA_MUX_ID_ADC3_1,     DMA_DEVICE_BASE(ADC3),          0x3C0U,     DMA_MUX_BOTH},
    /* port */              /* startAddress */              /* length *//* muxDirect */
    {(uint16)DMA_MUX_ID_ISTC,       DMA_DEVICE_BASE(ISTC),          0xFFFF,     DMA_MUX_BOTH},
};
#endif /* #ifndef SEMIDRIVE_E3_LITE_SERIES */

/** \brief  The table provides the DMA controller SF0 general configuration on each core. */
DMA_LOCAL const Dma_HwConfigType Dma_SF0ConfigTable[DMA_CPU_ID_MAX] __attribute__((__aligned__(DMA_CONFIG_ARCH_CACHE_LINE))) =
{
    /* SF core */
    {
        .baseAddress        = APB_DMA_SF0_BASE,
        .muxTable           = Dma_SFMuxTable,
        .muxTableLength     = (sizeof(Dma_SFMuxTable)/sizeof(Dma_SFMuxTable[0])),
        .channelIdTable     = Dma_SF0AllocateOnCore0,
        .channelNumber      = DMA_CHANNEL_SF0_ON_CORE0_NUMBER
    },
    /* SX0 core */
    {
        .baseAddress        = APB_DMA_SF0_BASE,
        .muxTable           = Dma_SFMuxTable,
        .muxTableLength     = (sizeof(Dma_SFMuxTable)/sizeof(Dma_SFMuxTable[0])),
        .channelIdTable     = Dma_SF0AllocateOnCore1,
        .channelNumber      = DMA_CHANNEL_SF0_ON_CORE1_NUMBER
    },
    /* SX1 core */
    {
        .baseAddress        = APB_DMA_SF0_BASE,
        .muxTable           = Dma_SFMuxTable,
        .muxTableLength     = (sizeof(Dma_SFMuxTable)/sizeof(Dma_SFMuxTable[0])),
        .channelIdTable     = Dma_SF0AllocateOnCore2,
        .channelNumber      = DMA_CHANNEL_SF0_ON_CORE2_NUMBER
    },
    /* SP0 core */
    {
        .baseAddress        = APB_DMA_SF0_BASE,
        .muxTable           = Dma_SFMuxTable,
        .muxTableLength     = (sizeof(Dma_SFMuxTable)/sizeof(Dma_SFMuxTable[0])),
        .channelIdTable     = Dma_SF0AllocateOnCore3,
        .channelNumber      = DMA_CHANNEL_SF0_ON_CORE3_NUMBER
    },
    /* SP1 core */
    {
        .baseAddress        = APB_DMA_SF0_BASE,
        .muxTable           = Dma_SFMuxTable,
        .muxTableLength     = (sizeof(Dma_SFMuxTable)/sizeof(Dma_SFMuxTable[0])),
        .channelIdTable     = Dma_SF0AllocateOnCore4,
        .channelNumber      = DMA_CHANNEL_SF0_ON_CORE4_NUMBER
    }
};

#if (STD_OFF == DMA_LOCK_STEP_MODE)
/** \brief  The table provides the DMA controller SF1 general configuration on each core. */
DMA_LOCAL const Dma_HwConfigType Dma_SF1ConfigTable[DMA_CPU_ID_MAX] __attribute__((__aligned__(DMA_CONFIG_ARCH_CACHE_LINE))) =
{
    /* SF core */
    {
        .baseAddress        = APB_DMA_SF1_BASE,
        .muxTable           = Dma_SFMuxTable,
        .muxTableLength     = (sizeof(Dma_SFMuxTable)/sizeof(Dma_SFMuxTable[0])),
        .channelIdTable     = Dma_SF1AllocateOnCore0,
        .channelNumber      = DMA_CHANNEL_SF1_ON_CORE0_NUMBER
    },
    /* SX0 core */
    {
        .baseAddress        = APB_DMA_SF1_BASE,
        .muxTable           = Dma_SFMuxTable,
        .muxTableLength     = (sizeof(Dma_SFMuxTable)/sizeof(Dma_SFMuxTable[0])),
        .channelIdTable     = Dma_SF1AllocateOnCore1,
        .channelNumber      = DMA_CHANNEL_SF1_ON_CORE1_NUMBER

    },
    /* SX1 core */
    {
        .baseAddress        = APB_DMA_SF1_BASE,
        .muxTable           = Dma_SFMuxTable,
        .muxTableLength     = (sizeof(Dma_SFMuxTable)/sizeof(Dma_SFMuxTable[0])),
        .channelIdTable     = Dma_SF1AllocateOnCore2,
        .channelNumber      = DMA_CHANNEL_SF1_ON_CORE2_NUMBER
    },
    /* SP0 core */
    {
        .baseAddress        = APB_DMA_SF1_BASE,
        .muxTable           = Dma_SFMuxTable,
        .muxTableLength     = (sizeof(Dma_SFMuxTable)/sizeof(Dma_SFMuxTable[0])),
        .channelIdTable     = Dma_SF1AllocateOnCore3,
        .channelNumber      = DMA_CHANNEL_SF1_ON_CORE3_NUMBER
    },
    /* SP1 core */
    {
        .baseAddress        = APB_DMA_SF1_BASE,
        .muxTable           = Dma_SFMuxTable,
        .muxTableLength     = (sizeof(Dma_SFMuxTable)/sizeof(Dma_SFMuxTable[0])),
        .channelIdTable     = Dma_SF1AllocateOnCore4,
        .channelNumber      = DMA_CHANNEL_SF1_ON_CORE4_NUMBER
    }
};
#endif /* #if (STD_OFF == DMA_LOCK_STEP_MODE) */

/** \brief  The table provides the Dma channels allocates on each core. */
const Dma_ConfigType Dma_ConfigRootTable =
{
    .configTableSF0 = &Dma_SF0ConfigTable[0U],
#if (STD_OFF == DMA_LOCK_STEP_MODE)
    .configTableSF1 = &Dma_SF1ConfigTable[0U],
#endif /* #if (STD_OFF == DMA_LOCK_STEP_MODE) */
    .adcConfigTable = &Dma_AdcConfigTable[0u],
    .adcConfigTableLength = (sizeof(Dma_AdcConfigTable)/sizeof(Dma_AdcConfigTable[0u])),
    .icuConfigTable = &Dma_IcuConfigTable[0U],
    .icuConfigTableLength = (sizeof(Dma_IcuConfigTable)/sizeof(Dma_IcuConfigTable[0u])),
    .memConfigTable = &Dma_MemToMemConfigTable[0u],
    .memConfigTableLength = (sizeof(Dma_MemToMemConfigTable)/sizeof(Dma_MemToMemConfigTable[0u])),
    .pwmConfigTable = &Dma_PwmConfigTable[0U],
    .pwmConfigTableLength = (sizeof(Dma_PwmConfigTable)/sizeof(Dma_PwmConfigTable[0u])),
    .spiConfigTable = &Dma_SpiConfigTable[0U],
    .spiConfigTableLength = (sizeof(Dma_SpiConfigTable)/sizeof(Dma_SpiConfigTable[0u])),
    .xSpiConfigTable = &Dma_XspiConfigTable[0U],
    .xSpiConfigTableLength = (sizeof(Dma_XspiConfigTable)/sizeof(Dma_XspiConfigTable[0u])),
    .xtrgConfigTable = &Dma_XtrgConfigTable[0u],
    .xtrgConfigTableLength = (sizeof(Dma_XtrgConfigTable)/sizeof(Dma_XtrgConfigTable[0u]))
};
#define DMA_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dma_MemMap.h"
#ifdef __cplusplus
}
#endif
/* End of file */
