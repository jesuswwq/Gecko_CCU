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
 * @file  DmaAL.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Can Driver.
 */
#ifndef DMA_HELPER_H
#define DMA_HELPER_H


#include "Std_Types.h"
#include "Mcu.h"
#include "irq.h"
#include "Dma_Drv.h"
#include "Dma_Cfg.h"

#define DMA_E_PARAM_POINTER         0x0AU
#define DMA_E_PARAM_HWUNIT_ID       0x0BU
#define DMA_E_PARAM_SUB_ID          0x0CU
#define DMA_E_PARAM_MODULE_ID       0x0DU
#define DMA_E_CONFIG_POINTER        0x0DU
#define DMA_E_CORE_ID               0X0EU
/* Dma instance configuration parameter */
/* DMA instance id 0 */
#define DMA_INSTANCE_SF_0           dma_sf0

#if (STD_OFF == DMA_LOCK_STEP_MODE)
/* DMA instance id 1 */
#define DMA_INSTANCE_SF_1           dma_sf1
#endif /* #if (STD_OFF == DMA_LOCK_STEP_MODE) */
#ifndef SEMIDRIVE_E3_LITE_SERIES
/* DMA instance id 2 */
#define DMA_INSTANCE_AP_0           dma_ap0[0U]
#endif /* #ifndef SEMIDRIVE_E3_LITE_SERIES */

typedef uint32 Dma_ChannelType;

/* Modules support by DMA  */
typedef enum {
    DMA_MODULE_ADC = 0,
    DMA_MODULE_ETIMER,
    DMA_MODULE_EPWM,
    DMA_MODULE_SPI,
    DMA_MODULE_XSPI
} Dma_ModuleEnumType;

/* Sub modules Id */
typedef enum {
    /* Spi sub id */
    DMA_SPI_TX = 0U,
    DMA_SPI_RX,
    /* Pwm sub id */
    DMA_PWM_FIFO_A,
    DMA_PWM_FIFO_B,
    DMA_PWM_FIFO_C,
    DMA_PWM_FIFO_D,
    DMA_PWM_CE,
    /* Icu sub id */
    DMA_ICU_CPT_A,
    DMA_ICU_CPT_B,
    DMA_ICU_CPT_C,
    DMA_ICU_CPT_D,
    /* Xspi sub id */
    DMA_XSPI_PORTA_RD,
    DMA_XSPI_PORTA_WR,
    DMA_XSPI_PORTB_RD,
    DMA_XSPI_PORTB_WR,
    /* Adc sub id */
    DMA_ADC_FIFO0,
    DMA_ADC_FIFO1,
    DMA_ADC_FIFO2,
    DMA_ADC_FIFO3
} Dma_SubIdEnumType;

typedef enum {
    DMA_ADC1 = 0,
    DMA_ADC2,
    DMA_ADC3
} Dma_AdcEnumType;


typedef struct {
    /* Pointer to dma controller configuration parameters */
    dma_dev_t *Controller;
    /* Dma channels id, range: 0-23 */
    uint8 ChannelId;
} Dma_InsConfigType;

typedef struct {
    /* Which adc controller is configured on a dma channel */
    uint8 AdcControllerId;
    /* CoreId for multicore */
    uint8 CoreId;
    /* Assign a dma channel to Adc transmit */
    Dma_InsConfigType Adc_Fifo;
} Dma_AdcConfigType;

typedef struct {
    /* Which spi controller is configured on a dma channel */
    uint8 SpiControllerId;
    /* CoreId for multicore */
    uint8 CoreId;
    /* Assign a dma channel to Spi transmit */
    Dma_InsConfigType Spi_Tx;
    /* Assign a dma channel to Spi receive */
    Dma_InsConfigType Spi_Rx;
} Dma_SpiConfigType;


typedef struct {
    /* Which pwm controller is configured on a dma channel */
    uint8 PwmControllerId;
    /* CoreId for multicore */
    uint8 CoreId;
    /* Assign a dma channel to PWM_FIFO_A */
    Dma_InsConfigType Pwm_FIFO_A;
    /* Assign a dma channel to PWM_FIFO_B */
    Dma_InsConfigType Pwm_FIFO_B;
    /* Assign a dma channel to PWM_FIFO_C */
    Dma_InsConfigType Pwm_FIFO_C;
    /* Assign a dma channel to PWM_FIFO_D */
    Dma_InsConfigType Pwm_FIFO_D;
    /* Assign a dma channel to PWM_CE */
    Dma_InsConfigType Pwm_CE;
} Dma_PwmConfigType;

typedef struct {
    /* Which spi controller is configured on a dma channel */
    uint8 IcuControllerId;
    /* CoreId for multicore */
    uint8 CoreId;
    /* Assign a dma channel to ICU_CPT_A */
    Dma_InsConfigType Icu_Capture_A;
    /* Assign a dma channel to ICU_CPT_B */
    Dma_InsConfigType Icu_Capture_B;
    /* Assign a dma channel to ICU_CPT_C */
    Dma_InsConfigType Icu_Capture_C;
    /* Assign a dma channel to ICU_CPT_D */
    Dma_InsConfigType Icu_Capture_D;
} Dma_IcuConfigType;

typedef struct {
    /* Which spi controller is configured on a dma channel */
    uint8 XSpiControllerId;
    /* CoreId for multicore */
    uint8 CoreId;
    /* Assign a dma channel to XSpi portA read */
    Dma_InsConfigType XSpi_PortA_Read;
    /* Assign a dma channel to XSpi portA write */
    Dma_InsConfigType XSpi_PortA_Write;
    /* Assign a dma channel to XSpi portB read */
    Dma_InsConfigType XSpi_PortB_Read;
    /* Assign a dma channel to XSpi portB write */
    Dma_InsConfigType XSpi_PortB_Write;
} Dma_XSpiConfigType;

typedef struct {
    uint32      InterruptNumber;
    irq_handler InterruptRoutine;
} Dma_InterruptConfigType;

typedef struct {
    const Dma_ChannelType         *SF0_Channel_Allocate;
    uint32                   SF0_Channel_Allocate_length;
    const Dma_ChannelType         *SF1_Channel_Allocate;
    uint32                   SF1_Channel_Allocate_length;
    const Dma_ChannelType         *AP_Channel_Allocate;
    uint32                   AP_Channel_Allocate_length;
    const Dma_InterruptConfigType *InterruptParams;
} Dma_ChannelAllocateOnCoreType;


/* Adc configuration parameters table */
extern CONST(Dma_AdcConfigType, DMA_CONST) Dma_AdcConfigTable[DMA_ADC_INSTANCE_NUMBER + 1U];
/* Icu configuration parameters table */
extern CONST(Dma_IcuConfigType, DMA_CONST) Dma_IcuConfigTable[DMA_ICU_INSTANCE_NUMBER + 1U];
/* Pwm configuration parameters table */
extern CONST(Dma_PwmConfigType, DMA_CONST) Dma_PwmConfigTable[DMA_PWM_INSTANCE_NUMBER + 1U];
/* Spi configuration parameters table */
extern CONST(Dma_SpiConfigType, DMA_CONST) Dma_SpiConfigTable[DMA_SPI_INSTANCE_NUMBER + 1U];
/* XSpi configuration parameters table */
extern CONST(Dma_XSpiConfigType, DMA_CONST) Dma_XSpiConfigTable[DMA_XSPI_INSTANCE_NUMBER + 1U];
/* Which dma sf0 channels are allocated on sf cores */
extern CONST(Dma_ChannelType, DMA_CONST) Dma_SF0AllocateOnSF[DMA_CHANNEL_SF0_ON_SF_NUMBER + 1U ];
/* Which dma sf1 channels are allocated on sf cores */
extern CONST(Dma_ChannelType, DMA_CONST) Dma_SF1AllocateOnSF[DMA_CHANNEL_SF1_ON_SF_NUMBER + 1U ];
/* Which dma ap channels are allocated on sf cores */
extern CONST(Dma_ChannelType, DMA_CONST) Dma_APAllocateOnSF[DMA_CHANNEL_AP0_ON_SF_NUMBER + 1U ];
/* Which dma sf0 channels are allocated on sx0 cores */
extern CONST(Dma_ChannelType, DMA_CONST) Dma_SF0AllocateOnSX0[DMA_CHANNEL_SF0_ON_SX0_NUMBER + 1U];
/* Which dma sf1 channels are allocated on sx0 cores */
extern CONST(Dma_ChannelType, DMA_CONST) Dma_SF1AllocateOnSX0[DMA_CHANNEL_SF1_ON_SX0_NUMBER + 1U];
/* Which dma ap channels are allocated on sx0 cores */
extern CONST(Dma_ChannelType, DMA_CONST) Dma_APAllocateOnSX0[DMA_CHANNEL_AP0_ON_SX0_NUMBER + 1U];
/* Which dma sf0 channels are allocated on sx1 cores */
extern CONST(Dma_ChannelType, DMA_CONST) Dma_SF0AllocateOnSX1[DMA_CHANNEL_SF0_ON_SX1_NUMBER + 1U];
/* Which dma sf1 channels are allocated on sx1 cores */
extern CONST(Dma_ChannelType, DMA_CONST) Dma_SF1AllocateOnSX1[DMA_CHANNEL_SF1_ON_SX1_NUMBER + 1U];
/* Which dma ap channels are allocated on sx1 cores */
extern CONST(Dma_ChannelType, DMA_CONST) Dma_APAllocateOnSX1[DMA_CHANNEL_AP0_ON_SX1_NUMBER + 1U];
/* Which dma sf0 channels are allocated on sp0 cores */
extern CONST(Dma_ChannelType, DMA_CONST) Dma_SF0AllocateOnSP0[DMA_CHANNEL_SF0_ON_SP0_NUMBER + 1U];
/* Which dma sf1 channels are allocated on sp0 cores */
extern CONST(Dma_ChannelType, DMA_CONST) Dma_SF1AllocateOnSP0[DMA_CHANNEL_SF1_ON_SP0_NUMBER + 1U];
/* Which dma ap channels are allocated on sp0 cores */
extern CONST(Dma_ChannelType, DMA_CONST) Dma_APAllocateOnSP0[DMA_CHANNEL_AP0_ON_SP0_NUMBER + 1U];
/* Which dma sf0 channels are allocated on sp1 cores */
extern CONST(Dma_ChannelType, DMA_CONST) Dma_SF0AllocateOnSP1[DMA_CHANNEL_SF0_ON_SP1_NUMBER + 1U];
/* Which dma sf1 channels are allocated on sp1 cores */
extern CONST(Dma_ChannelType, DMA_CONST) Dma_SF1AllocateOnSP1[DMA_CHANNEL_SF1_ON_SP1_NUMBER + 1U];
/* Which dma ap channels are allocated on sp1 cores */
extern CONST(Dma_ChannelType, DMA_CONST) Dma_APAllocateOnSP1[DMA_CHANNEL_AP0_ON_SP1_NUMBER + 1U];

/* Dma channels allocates on every core table */
extern CONST(Dma_ChannelAllocateOnCoreType, DMA_CONST) Dma_ChannelAllocateOnCoreTable[CPU_ID_MAX];
/**
 * @brief Dma get module configuration parameters.
 * @param hwUnitId, subId, moduleId, *dmaConfig.
 * @return errorId.
 */
extern Std_ReturnType Dma_GetConfigParams(uint8 hwUnitId, Dma_SubIdEnumType subId,
        Dma_ModuleEnumType moduleId, Dma_InsConfigType *dmaConfig);

#endif /* #ifndef DMA_HELPER_H */
