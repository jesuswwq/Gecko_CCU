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
 * @file  Dma_PBCfg.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL IrqM
 * @date 2023-09-22 17:02:48
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Dma_Helper.h"
#include "irq_num.h"

/* Dma adc module configuration parameters table */
CONST(Dma_AdcConfigType, DMA_CONST) Dma_AdcConfigTable[DMA_ADC_INSTANCE_NUMBER + 1U] =
{
    {
        /* AdcControllerId = */0xFFU,
        /* CoreId          = */0xFFU,
        /* Adc_Fifo        = */
        {
            /* *Controller = */NULL_PTR,
            /* ChannelId   = */0xFFU,
        }
    }
};

/* Dma spi module configuration parameters table */
CONST(Dma_SpiConfigType, DMA_CONST) Dma_SpiConfigTable[DMA_SPI_INSTANCE_NUMBER + 1U] = 
{
    {
        /* SpiControllerId = */0xFFU,
        /* CoreId          = */0xFFU,
        /* Spi_Tx          = */
        {
            /* *Controller = */NULL_PTR,
            /* ChannelId   = */0xFFU,
        },
        /* Spi_Rx          = */
        {
            /* *Controller = */NULL_PTR,
            /* ChannelId   = */0xFFU,
        }
    }
};

/* Dma pwm module configuration parameters table */
CONST(Dma_PwmConfigType, DMA_CONST) Dma_PwmConfigTable[DMA_PWM_INSTANCE_NUMBER + 1U] = 
{
    {
        /* PwmControllerId = */0xFFU,
        /* CoreId          = */0xFFU,
        /* Pwm_FIFO_A      = */
        {
            /* *Controller = */NULL_PTR,
            /* ChannelId   = */0xFFU,
        },
        /* Pwm_FIFO_B      = */
        {
            /* *Controller = */NULL_PTR,
            /* ChannelId   = */0xFFU,
        },
        /* Pwm_FIFO_C      = */
        {
            /* *Controller = */NULL_PTR,
            /* ChannelId   = */0xFFU,
        },
        /* Pwm_FIFO_D      = */
        {
            /* *Controller = */NULL_PTR,
            /* ChannelId   = */0xFFU,
        },
        /* Pwm_CE          = */
        {
            /* *Controller = */NULL_PTR,
            /* ChannelId   = */0xFFU,
        }
    }
};

/* Dma icu module configuration parameters table */
CONST(Dma_IcuConfigType, DMA_CONST) Dma_IcuConfigTable[DMA_ICU_INSTANCE_NUMBER + 1U] = 
{
    {
        /* IcuControllerId = */0xFFU,
        /* CoreId          = */0xFFU,
        /* Icu_Capture_A   = */
        {
            /* *Controller = */NULL_PTR,
            /* ChannelId   = */0xFFU,
        },
        /* Icu_Capture_B   = */
        {
            /* *Controller = */NULL_PTR,
            /* ChannelId   = */0xFFU,
        },
        /* Icu_Capture_C   = */
        {
            /* *Controller = */NULL_PTR,
            /* ChannelId   = */0xFFU,
        },
        /* Icu_Capture_D   = */
        {
            /* *Controller = */NULL_PTR,
            /* ChannelId   = */0xFFU,
        },
    }
};

/* XSpi configuration parameters table */
CONST(Dma_XSpiConfigType, DMA_CONST) Dma_XSpiConfigTable[DMA_XSPI_INSTANCE_NUMBER + 1U] =
{
    {
        /* XSpiControllerId  = */0U,
        /* CoreId            = */CPU_ID_SF,
        /* XSpi_PortA_Read   = */
        {
            /* *Controller   = */NULL_PTR,
            /* ChannelId     = */0xFFU,
        },
        /* XSpi_PortA_Write  = */
        {
            /* *Controller   = */&DMA_INSTANCE_SF_0[CPU_ID_SF],
            /* ChannelId     = */0U,
        },
        /* XSpi_PortB_Read   = */
        {
            /* *Controller   = */NULL_PTR,
            /* ChannelId     = */0xFFU,
        },
        /* XSpi_PortB_Write  = */
        {
            /* *Controller   = */NULL_PTR,
            /* ChannelId     = */0xFFU,
        }
    },
    {
        /* XSpiControllerId  = */0xFFU,
        /* CoreId            = */0xFFU,
        /* XSpi_PortA_Read   = */
        {
            /* *Controller   = */NULL_PTR,
            /* ChannelId     = */0xFFU,
        },
        /* XSpi_PortA_Write  = */
        {
            /* *Controller   = */NULL_PTR,
            /* ChannelId     = */0xFFU,
        },
        /* XSpi_PortB_Read   = */
        {
            /* *Controller   = */NULL_PTR,
            /* ChannelId     = */0xFFU,
        },
        /* XSpi_PortB_Write  = */
        {
            /* *Controller   = */NULL_PTR,
            /* ChannelId     = */0xFFU,
        }
    }
};



/* Dma SF0 channels allocated on core SF */
CONST(Dma_ChannelType, DMA_CONST) Dma_SF0AllocateOnSF [DMA_CHANNEL_SF0_ON_SF_NUMBER + 1U ] = {0xFFU};

/* Dma SF1 channels allocated on core SF */
CONST(Dma_ChannelType, DMA_CONST) Dma_SF1AllocateOnSF [DMA_CHANNEL_SF1_ON_SF_NUMBER + 1U ] = {0xFFU};

/* Dma AP channels allocated on core SF */
CONST(Dma_ChannelType, DMA_CONST) Dma_APAllocateOnSF  [DMA_CHANNEL_AP0_ON_SF_NUMBER + 1U ] = {0xFFU};

/* Dma SF0 channels allocated on core SX0 */
CONST(Dma_ChannelType, DMA_CONST) Dma_SF0AllocateOnSX0[DMA_CHANNEL_SF0_ON_SX0_NUMBER + 1U] = {0xFFU};

/* Dma SF1 channels allocated on core SX0 */
CONST(Dma_ChannelType, DMA_CONST) Dma_SF1AllocateOnSX0[DMA_CHANNEL_SF1_ON_SX0_NUMBER + 1U] = {0xFFU};

/* Dma AP channels allocated on core SX0 */
CONST(Dma_ChannelType, DMA_CONST) Dma_APAllocateOnSX0 [DMA_CHANNEL_AP0_ON_SX0_NUMBER + 1U] = {0xFFU};

/* Dma SF0 channels allocated on core SX1 */
CONST(Dma_ChannelType, DMA_CONST) Dma_SF0AllocateOnSX1[DMA_CHANNEL_SF0_ON_SX1_NUMBER + 1U] = {0xFFU};

/* Dma SF1 channels allocated on core SX1 */
CONST(Dma_ChannelType, DMA_CONST) Dma_SF1AllocateOnSX1[DMA_CHANNEL_SF1_ON_SX1_NUMBER + 1U] = {0xFFU};

/* Dma AP channels allocated on core SX1 */
CONST(Dma_ChannelType, DMA_CONST) Dma_APAllocateOnSX1 [DMA_CHANNEL_AP0_ON_SX1_NUMBER + 1U] = {0xFFU};

/* Dma SF0 channels allocated on core SP0 */
CONST(Dma_ChannelType, DMA_CONST) Dma_SF0AllocateOnSP0[DMA_CHANNEL_SF0_ON_SP0_NUMBER + 1U] = {0xFFU};

/* Dma SF1 channels allocated on core SP0 */
CONST(Dma_ChannelType, DMA_CONST) Dma_SF1AllocateOnSP0[DMA_CHANNEL_SF1_ON_SP0_NUMBER + 1U] = {0xFFU};

/* Dma AP channels allocated on core SP0 */
CONST(Dma_ChannelType, DMA_CONST) Dma_APAllocateOnSP0 [DMA_CHANNEL_AP0_ON_SP0_NUMBER + 1U] = {0xFFU};

/* Dma SF0 channels allocated on core SP1 */
CONST(Dma_ChannelType, DMA_CONST) Dma_SF0AllocateOnSP1[DMA_CHANNEL_SF0_ON_SP1_NUMBER + 1U] = {0xFFU};

/* Dma SF1 channels allocated on core SP1 */
CONST(Dma_ChannelType, DMA_CONST) Dma_SF1AllocateOnSP1[DMA_CHANNEL_SF1_ON_SP1_NUMBER + 1U] = {0xFFU};

/* Dma AP channels allocated on core SP1 */
CONST(Dma_ChannelType, DMA_CONST) Dma_APAllocateOnSP1 [DMA_CHANNEL_AP0_ON_SP1_NUMBER + 1U] = {0xFFU};



extern void sdrv_dma_sf0_irq0_handler(void);
extern void sdrv_dma_sf0_irq1_handler(void);
extern void sdrv_dma_sf0_irq2_handler(void);
extern void sdrv_dma_sf0_irq3_handler(void);
extern void sdrv_dma_sf0_irq4_handler(void);
extern void sdrv_dma_sf0_irq5_handler(void);
extern void sdrv_dma_sf0_irq6_handler(void);
extern void sdrv_dma_sf0_irq7_handler(void);
extern void sdrv_dma_sf0_irq8_handler(void);
extern void sdrv_dma_sf0_irq9_handler(void);
extern void sdrv_dma_sf0_irq10_handler(void);
extern void sdrv_dma_sf0_irq11_handler(void);
extern void sdrv_dma_sf0_irq12_handler(void);
extern void sdrv_dma_sf0_irq13_handler(void);
extern void sdrv_dma_sf0_irq14_handler(void);
extern void sdrv_dma_sf0_irq15_handler(void);
extern void sdrv_dma_sf0_irq16_handler(void);
extern void sdrv_dma_sf0_irq17_handler(void);
extern void sdrv_dma_sf0_irq18_handler(void);
extern void sdrv_dma_sf0_irq19_handler(void);
extern void sdrv_dma_sf0_irq20_handler(void);
extern void sdrv_dma_sf0_irq21_handler(void);
extern void sdrv_dma_sf0_irq22_handler(void);
extern void sdrv_dma_sf0_irq23_handler(void);
#if (STD_OFF == DMA_LOCK_STEP_MODE)
extern void sdrv_dma_sf1_irq0_handler(void);
extern void sdrv_dma_sf1_irq1_handler(void);
extern void sdrv_dma_sf1_irq2_handler(void);
extern void sdrv_dma_sf1_irq3_handler(void);
extern void sdrv_dma_sf1_irq4_handler(void);
extern void sdrv_dma_sf1_irq5_handler(void);
extern void sdrv_dma_sf1_irq6_handler(void);
extern void sdrv_dma_sf1_irq7_handler(void);
extern void sdrv_dma_sf1_irq8_handler(void);
extern void sdrv_dma_sf1_irq9_handler(void);
extern void sdrv_dma_sf1_irq10_handler(void);
extern void sdrv_dma_sf1_irq11_handler(void);
extern void sdrv_dma_sf1_irq12_handler(void);
extern void sdrv_dma_sf1_irq13_handler(void);
extern void sdrv_dma_sf1_irq14_handler(void);
extern void sdrv_dma_sf1_irq15_handler(void);
extern void sdrv_dma_sf1_irq16_handler(void);
extern void sdrv_dma_sf1_irq17_handler(void);
extern void sdrv_dma_sf1_irq18_handler(void);
extern void sdrv_dma_sf1_irq19_handler(void);
extern void sdrv_dma_sf1_irq20_handler(void);
extern void sdrv_dma_sf1_irq21_handler(void);
extern void sdrv_dma_sf1_irq22_handler(void);
extern void sdrv_dma_sf1_irq23_handler(void);
#endif /* #if (STD_OFF == DMA_LOCK_STEP_MODE) */
extern void sdrv_dma_ap0_irq0_handler(void);
extern void sdrv_dma_ap0_irq1_handler(void);
extern void sdrv_dma_ap0_irq2_handler(void);
extern void sdrv_dma_ap0_irq3_handler(void);
extern void sdrv_dma_ap0_irq4_handler(void);
extern void sdrv_dma_ap0_irq5_handler(void);
extern void sdrv_dma_ap0_irq6_handler(void);
extern void sdrv_dma_ap0_irq7_handler(void);
static CONST(Dma_InterruptConfigType, DMA_CONST) Dma_SFInterruptConfigTable[DMA_CHANNEL_SF0_ON_SF_NUMBER + DMA_CHANNEL_SF1_ON_SF_NUMBER + DMA_CHANNEL_AP0_ON_SF_NUMBER + 1U] =
{
    {
        /* InterruptNumber  = */0xFFFFFFFFU,
        /* InterruptRoutine = */NULL_PTR
    }
};

static CONST(Dma_InterruptConfigType, DMA_CONST) Dma_SX0InterruptConfigTable[DMA_CHANNEL_SF0_ON_SX0_NUMBER + DMA_CHANNEL_SF1_ON_SX0_NUMBER + DMA_CHANNEL_AP0_ON_SX0_NUMBER + 1U] =
{
    {
        /* InterruptNumber  = */0xFFFFFFFFU,
        /* InterruptRoutine = */NULL_PTR
    }
};

static CONST(Dma_InterruptConfigType, DMA_CONST) Dma_SX1InterruptConfigTable[DMA_CHANNEL_SF0_ON_SX1_NUMBER + DMA_CHANNEL_SF1_ON_SX1_NUMBER + DMA_CHANNEL_AP0_ON_SX1_NUMBER + 1U] =
{
    {
        /* InterruptNumber  = */0xFFFFFFFFU,
        /* InterruptRoutine = */NULL_PTR
    }
};


static CONST(Dma_InterruptConfigType, DMA_CONST) Dma_SP0InterruptConfigTable[DMA_CHANNEL_SF0_ON_SP0_NUMBER + DMA_CHANNEL_SF1_ON_SP0_NUMBER + DMA_CHANNEL_AP0_ON_SP0_NUMBER + 1U] =
{
    {
        /* InterruptNumber  = */0xFFFFFFFFU,
        /* InterruptRoutine = */NULL_PTR
    }
};

static CONST(Dma_InterruptConfigType, DMA_CONST) Dma_SP1InterruptConfigTable[DMA_CHANNEL_SF0_ON_SP1_NUMBER + DMA_CHANNEL_SF1_ON_SP1_NUMBER + DMA_CHANNEL_AP0_ON_SP1_NUMBER + 1U] =
{
    {
        /* InterruptNumber  = */0xFFFFFFFFU,
        /* InterruptRoutine = */NULL_PTR
    }
};


/* Dma channels allocates on every core table */
CONST(Dma_ChannelAllocateOnCoreType, DMA_CONST) Dma_ChannelAllocateOnCoreTable[CPU_ID_MAX] =
{
    /* SF core */
    {
        /* *SF0Channel_Allocate        = */&Dma_SF0AllocateOnSF [0U],
        /* SF0_Channel_Allocate_length = */DMA_CHANNEL_SF0_ON_SF_NUMBER,
        /* *SF1Channel_Allocate        = */&Dma_SF1AllocateOnSF [0U],
        /* SF1_Channel_Allocate_length = */DMA_CHANNEL_SF1_ON_SF_NUMBER,
        /* *APChannel_Allocate         = */&Dma_APAllocateOnSF  [0U],
        /* AP_Channel_Allocate_length  = */DMA_CHANNEL_AP0_ON_SF_NUMBER,
        /* InterruptParams             = */&Dma_SFInterruptConfigTable[0U]
    },
    /* SX0 core */
    {
        /* *SF0_Channel_Allocate       = */&Dma_SF0AllocateOnSX0[0U],
        /* SF0_Channel_Allocate_length = */DMA_CHANNEL_SF0_ON_SX0_NUMBER,
        /* *SF1_Channel_Allocate       = */&Dma_SF1AllocateOnSX0[0U],
        /* SF1_Channel_Allocate_length = */DMA_CHANNEL_SF1_ON_SX0_NUMBER,
        /* *AP_Channel_Allocate        = */&Dma_APAllocateOnSX0 [0U],
        /* AP_Channel_Allocate_length  = */DMA_CHANNEL_AP0_ON_SX0_NUMBER,
        /* InterruptParams             = */&Dma_SX0InterruptConfigTable[0U]
    },
    /* SX1 core */
    {
        /* *SF0_Channel_Allocate       = */&Dma_SF0AllocateOnSX1[0U],
        /* SF0_Channel_Allocate_length = */DMA_CHANNEL_SF0_ON_SX1_NUMBER,
        /* *SF1_Channel_Allocate       = */&Dma_SF1AllocateOnSX1[0U],
        /* SF1_Channel_Allocate_length = */DMA_CHANNEL_SF1_ON_SX1_NUMBER,
        /* *AP_Channel_Allocate        = */&Dma_APAllocateOnSX1 [0U],
        /* AP_Channel_Allocate_length  = */DMA_CHANNEL_AP0_ON_SX1_NUMBER,
        /* InterruptParams             = */&Dma_SX1InterruptConfigTable[0U]
    },
    /* SP0 core */
    {
        /* *SF0_Channel_Allocate       = */&Dma_SF0AllocateOnSP0[0U],
        /* SF0_Channel_Allocate_length = */DMA_CHANNEL_SF0_ON_SP0_NUMBER,
        /* *SF1_Channel_Allocate       = */&Dma_SF1AllocateOnSP0[0U],
        /* SF1_Channel_Allocate_length = */DMA_CHANNEL_SF1_ON_SP0_NUMBER,
        /* *AP_Channel_Allocate        = */&Dma_APAllocateOnSP0 [0U],
        /* AP_Channel_Allocate_length  = */DMA_CHANNEL_AP0_ON_SP0_NUMBER,
        /* InterruptParams             = */&Dma_SP0InterruptConfigTable[0U]
    },
    /* SP1 core */
    {
        /* *SF0_Channel_Allocate       = */&Dma_SF0AllocateOnSP1[0U],
        /* SF0_Channel_Allocate_length = */DMA_CHANNEL_SF0_ON_SP1_NUMBER,
        /* *SF1_Channel_Allocate       = */&Dma_SF1AllocateOnSP1[0U],
        /* SF1_Channel_Allocate_length = */DMA_CHANNEL_SF1_ON_SP1_NUMBER,
        /* *AP_Channel_Allocate        = */&Dma_APAllocateOnSP1 [0U],
        /* AP_Channel_Allocate_length  = */DMA_CHANNEL_AP0_ON_SP1_NUMBER,
        /* InterruptParams             = */&Dma_SP1InterruptConfigTable[0U]
    }
};

#ifdef __cplusplus
}
#endif
