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
 *  \file     Dma_Types.h                                                                               *
 *  \brief    This file contains data structures header for DMA MCAL driver.                            *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/17     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifndef DMA_TYPES_H
#define DMA_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif
/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
/** Traceability       : SWSR_DMA_041 */
/* Import Std_Types.h */
#include "Std_Types.h"
/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/
#define DMA_LOCAL                                                       static
#define DMA_LOCAL_INLINE                                                static inline

/** \brief Cache line length are 32 bytes */
#define DMA_CONFIG_ARCH_CACHE_LINE                                      (32U)
/**
 *  \addtogroup MCAL_DMA_MACRO Dma Macro.
 *
 * This files defines DMA MCAL macros.
 *  \{
 */
/** \brief CAN Driver is NOT initialized. */
#define DMA_UNINIT                                                      (uint8)(0x00U)

/** \brief  DMA Driver is initialized. */
#define DMA_INIT                                                        (uint8)(0x01U)

/** \brief  ERROR:Error due to API duplicated invoked Dma_Init(). */
#define DMA_E_INIT                                                      (Std_ReturnType)(0x80U)

/** \brief  ERROR:Error due to API invoked without performing Dma_Init(). */
#define DMA_E_UNINIT                                                    (Std_ReturnType)(0x81U)

/** \brief  ERROR:Error due to invalid hardware unit id(s) passed as parameter. */
#define DMA_E_PARAM_HWUNIT_ID                                           (Std_ReturnType)(0x82U)

/** \brief  ERROR:Error due to invalid channel id(s) passed as parameter. */
#define DMA_E_PARAM_CHANNEL_ID                                          (Std_ReturnType)(0x83U)

/** \brief  ERROR:Error due to invalid module id(s) passed as parameter. */
#define DMA_E_PARAM_MODULE_ID                                           (Std_ReturnType)(0x84U)

/** \brief  ERROR:NULL_PTR config pointer passed as parameter. */
#define DMA_E_CONFIG_POINTER                                            (Std_ReturnType)(0x85U)

/** \brief  ERROR:Error due to invalid core id allocation. */
#define DMA_E_CORE_ID                                                   (Std_ReturnType)(0x86U)

/** \brief  ERROR:Error due to invalid subsets id(s) passed as parameter. */
#define DMA_E_PARAM_SUB_ID                                              (Std_ReturnType)(0x87U)

/** \brief  ERROR:NULL_PTR passed as parameter. */
#define DMA_E_PARAM_POINTER                                             (Std_ReturnType)(0x88U)

/** \brief  ERROR:Error due invalid parameters. */
#define DMA_E_PARAMS                                                    (Std_ReturnType)(0x89U)

/** \brief  ERROR:Error due to invalid mux id(s) passed as parameter. */
#define DMA_E_MUX_ID                                                    (Std_ReturnType)(0x90U)

/** \brief  ERROR:Error due to invalid tramsfer direction. */
#define DMA_E_DIRECTION                                                 (Std_ReturnType)(0x91U)

/** \brief  ERROR:Error due to timeout occurred. */
#define DMA_E_TIMEOUT                                                   (Std_ReturnType)(0x92U)

/** \brief  ERROR:Error due to DMA channel is occupied. */
#define DMA_E_ALLOCATED                                                 (Std_ReturnType)(0x93U)

/** \brief  ERROR:Error due to invalid Dma base address. */
#define DMA_E_PARAM_BASE_ADDRESS                                        (Std_ReturnType)(0x94U)

/** \brief  ERROR:Error due to invalid Dma controller id. */
#define DMA_E_PARAM_CONTROLLER_ID                                       (Std_ReturnType)(0x95U)

/** \brief  ERROR:Error due to set lockstep failed. */
#define DMA_E_LOCKSTEP                                                  (Std_ReturnType)(0x96U)

/** \brief  ERROR:Error due to set or free link list node. */
#define DMA_E_LINK_LIST                                                 (Std_ReturnType)(0x97U)

/** \brief  ERROR:Error due to set invalid loop mode. */
#define DMA_E_LOOP_MODE                                                 (Std_ReturnType)(0x98U)

/** \brief  ERROR:Error due to set invalid transfer mode. */
#define DMA_E_TRANSFER_MODE                                             (Std_ReturnType)(0x99U)
/** \} */
/********************************************************************************************************
 *                                  Global Types definition                                             *
 *******************************************************************************************************/
/**
 *  \addtogroup MCAL_DMA_CFG Dma Configuration.
 *
 * This files defines DMA MCAL configuration structures
 *  @{
 */
/** \brief  Dma channel(s) id types. */
typedef uint8 Dma_ChannelType;

/** \brief  Dma Hardware controller id(s) type. */
typedef enum
{
    DMA_HW_SF0 = 0U,
    DMA_HW_SF1,
    DMA_HW_UNDEFINE
} Dma_HwControllerType;

#ifndef SEMIDRIVE_E3_LITE_SERIES
/** \brief  Dma SF mux id table, indicating which modules can be supported. */
enum
{
    DMA_MUX_ID_CANFD1 = 0U,
    DMA_MUX_ID_CANFD2,
    DMA_MUX_ID_CANFD3,
    DMA_MUX_ID_CANFD4,
    DMA_MUX_ID_CANFD5,
    DMA_MUX_ID_CANFD6,
    DMA_MUX_ID_CANFD7,
    DMA_MUX_ID_CANFD8,
    DMA_MUX_ID_CANFD9,
    DMA_MUX_ID_CANFD10,
    DMA_MUX_ID_CANFD11,
    DMA_MUX_ID_CANFD12,
    DMA_MUX_ID_CANFD13,
    DMA_MUX_ID_CANFD14,
    DMA_MUX_ID_CANFD15,
    DMA_MUX_ID_CANFD16,
    DMA_MUX_ID_CANFD17,
    DMA_MUX_ID_CANFD18,
    DMA_MUX_ID_CANFD19,
    DMA_MUX_ID_CANFD20,
    DMA_MUX_ID_CANFD21,
    DMA_MUX_ID_CANFD22,
    DMA_MUX_ID_CANFD23,
    DMA_MUX_ID_CANFD24,
    DMA_MUX_ID_ETH1_REQ_0,
    DMA_MUX_ID_ETH1_REQ_1,
    DMA_MUX_ID_ETH1_REQ_2,
    DMA_MUX_ID_ETH1_REQ_3,
    DMA_MUX_ID_ETH2_REQ_0,
    DMA_MUX_ID_ETH2_REQ_1,
    DMA_MUX_ID_ETH2_REQ_2,
    DMA_MUX_ID_ETH2_REQ_3,
    DMA_MUX_ID_I2C1,
    DMA_MUX_ID_I2C2,
    DMA_MUX_ID_I2C3,
    DMA_MUX_ID_I2C4,
    DMA_MUX_ID_I2C5,
    DMA_MUX_ID_I2C6,
    DMA_MUX_ID_I2C7,
    DMA_MUX_ID_I2C8,
    DMA_MUX_ID_XSPI1_A_RD,
    DMA_MUX_ID_XSPI1_A_WR,
    DMA_MUX_ID_XSPI1_B_RD,
    DMA_MUX_ID_XSPI1_B_WR,
    DMA_MUX_ID_XSPI2_A_RD,
    DMA_MUX_ID_XSPI2_A_WR,
    DMA_MUX_ID_XSPI2_B_RD,
    DMA_MUX_ID_XSPI2_B_WR,
    DMA_MUX_ID_SPI1_RX,
    DMA_MUX_ID_SPI1_TX,
    DMA_MUX_ID_SPI2_RX,
    DMA_MUX_ID_SPI2_TX,
    DMA_MUX_ID_SPI3_RX,
    DMA_MUX_ID_SPI3_TX,
    DMA_MUX_ID_SPI4_RX,
    DMA_MUX_ID_SPI4_TX,
    DMA_MUX_ID_SPI5_RX,
    DMA_MUX_ID_SPI5_TX,
    DMA_MUX_ID_SPI6_RX,
    DMA_MUX_ID_SPI6_TX,
    DMA_MUX_ID_SPI7_RX,
    DMA_MUX_ID_SPI7_TX,
    DMA_MUX_ID_SPI8_RX,
    DMA_MUX_ID_SPI8_TX,
    DMA_MUX_ID_EPWM1_A,
    DMA_MUX_ID_EPWM1_B,
    DMA_MUX_ID_EPWM1_C,
    DMA_MUX_ID_EPWM1_D,
    DMA_MUX_ID_EPWM1_OVF,
    DMA_MUX_ID_EPWM2_A,
    DMA_MUX_ID_EPWM2_B,
    DMA_MUX_ID_EPWM2_C,
    DMA_MUX_ID_EPWM2_D,
    DMA_MUX_ID_EPWM2_OVF,
    DMA_MUX_ID_EPWM3_A,
    DMA_MUX_ID_EPWM3_B,
    DMA_MUX_ID_EPWM3_C,
    DMA_MUX_ID_EPWM3_D,
    DMA_MUX_ID_EPWM3_OVF,
    DMA_MUX_ID_EPWM4_A,
    DMA_MUX_ID_EPWM4_B,
    DMA_MUX_ID_EPWM4_C,
    DMA_MUX_ID_EPWM4_D,
    DMA_MUX_ID_EPWM4_OVF,
    DMA_MUX_ID_ETMR1_A,
    DMA_MUX_ID_ETMR1_B,
    DMA_MUX_ID_ETMR1_C,
    DMA_MUX_ID_ETMR1_D,
    DMA_MUX_ID_ETMR1_OVF,
    DMA_MUX_ID_ETMR2_A,
    DMA_MUX_ID_ETMR2_B,
    DMA_MUX_ID_ETMR2_C,
    DMA_MUX_ID_ETMR2_D,
    DMA_MUX_ID_ETMR2_OVF,
    DMA_MUX_ID_ETMR3_A,
    DMA_MUX_ID_ETMR3_B,
    DMA_MUX_ID_ETMR3_C,
    DMA_MUX_ID_ETMR3_D,
    DMA_MUX_ID_ETMR3_OVF,
    DMA_MUX_ID_ETMR4_A,
    DMA_MUX_ID_ETMR4_B,
    DMA_MUX_ID_ETMR4_C,
    DMA_MUX_ID_ETMR4_D,
    DMA_MUX_ID_ETMR4_OVF,
    DMA_MUX_ID_XTRG_0,
    DMA_MUX_ID_XTRG_1,
    DMA_MUX_ID_UART1_TX,
    DMA_MUX_ID_UART1_RX,
    DMA_MUX_ID_UART2_TX,
    DMA_MUX_ID_UART2_RX,
    DMA_MUX_ID_UART3_TX,
    DMA_MUX_ID_UART3_RX,
    DMA_MUX_ID_UART4_TX,
    DMA_MUX_ID_UART4_RX,
    DMA_MUX_ID_UART5_TX,
    DMA_MUX_ID_UART5_RX,
    DMA_MUX_ID_UART6_TX,
    DMA_MUX_ID_UART6_RX,
    DMA_MUX_ID_UART7_TX,
    DMA_MUX_ID_UART7_RX,
    DMA_MUX_ID_UART8_TX,
    DMA_MUX_ID_UART8_RX,
    DMA_MUX_ID_UART9_TX,
    DMA_MUX_ID_UART9_RX,
    DMA_MUX_ID_UART10_TX,
    DMA_MUX_ID_UART10_RX,
    DMA_MUX_ID_UART11_TX,
    DMA_MUX_ID_UART11_RX,
    DMA_MUX_ID_UART12_TX,
    DMA_MUX_ID_UART12_RX,
    DMA_MUX_ID_UART13_TX,
    DMA_MUX_ID_UART13_RX,
    DMA_MUX_ID_UART14_TX,
    DMA_MUX_ID_UART14_RX,
    DMA_MUX_ID_UART15_TX,
    DMA_MUX_ID_UART15_RX,
    DMA_MUX_ID_UART16_TX,
    DMA_MUX_ID_UART16_RX,
    DMA_MUX_ID_ADC1_0,
    DMA_MUX_ID_ADC1_1,
    DMA_MUX_ID_ADC2_0,
    DMA_MUX_ID_ADC2_1,
    DMA_MUX_ID_ADC3_0,
    DMA_MUX_ID_ADC3_1,
    DMA_MUX_ID_ISTC
};
#else
/** \brief  Dma SF mux id table, indicating which modules can be supported. */
enum
{
    DMA_MUX_ID_CANFD16 = 0U,
    DMA_MUX_ID_CANFD21,
    DMA_MUX_ID_CANFD3,
    DMA_MUX_ID_CANFD4,
    DMA_MUX_ID_CANFD5,
    DMA_MUX_ID_CANFD6,
    DMA_MUX_ID_CANFD7,
    DMA_MUX_ID_CANFD23,
    DMA_MUX_ID_ENET1_REQ_0,
    DMA_MUX_ID_ENET1_REQ_1,
    DMA_MUX_ID_ENET1_REQ_2,
    DMA_MUX_ID_ENET1_REQ_3,
    DMA_MUX_ID_I2C1,
    DMA_MUX_ID_I2C2,
    DMA_MUX_ID_I2C3,
    DMA_MUX_ID_I2C4,
    DMA_MUX_ID_I2C5,
    DMA_MUX_ID_I2C6,
    DMA_MUX_ID_XSPI1_A_RD,
    DMA_MUX_ID_XSPI1_A_WR,
    DMA_MUX_ID_XSPI1_B_RD,
    DMA_MUX_ID_XSPI1_B_WR,
    DMA_MUX_ID_SPI1_RX,
    DMA_MUX_ID_SPI1_TX,
    DMA_MUX_ID_SPI2_RX,
    DMA_MUX_ID_SPI2_TX,
    DMA_MUX_ID_SPI3_RX,
    DMA_MUX_ID_SPI3_TX,
    DMA_MUX_ID_SPI4_RX,
    DMA_MUX_ID_SPI4_TX,
    DMA_MUX_ID_SPI5_RX,
    DMA_MUX_ID_SPI5_TX,
    DMA_MUX_ID_SPI6_RX,
    DMA_MUX_ID_SPI6_TX,
    DMA_MUX_ID_EPWM1_A,
    DMA_MUX_ID_EPWM1_B,
    DMA_MUX_ID_EPWM1_C,
    DMA_MUX_ID_EPWM1_D,
    DMA_MUX_ID_EPWM1_OVF,
    DMA_MUX_ID_EPWM2_A,
    DMA_MUX_ID_EPWM2_B,
    DMA_MUX_ID_EPWM2_C,
    DMA_MUX_ID_EPWM2_D,
    DMA_MUX_ID_EPWM2_OVF,
    DMA_MUX_ID_ETMR1_A,
    DMA_MUX_ID_ETMR1_B,
    DMA_MUX_ID_ETMR1_C,
    DMA_MUX_ID_ETMR1_D,
    DMA_MUX_ID_ETMR1_OVF,
    DMA_MUX_ID_ETMR2_A,
    DMA_MUX_ID_ETMR2_B,
    DMA_MUX_ID_ETMR2_C,
    DMA_MUX_ID_ETMR2_D,
    DMA_MUX_ID_ETMR2_OVF,
    DMA_MUX_ID_XTRG_0,
    DMA_MUX_ID_XTRG_1,
    DMA_MUX_ID_UART1_TX,
    DMA_MUX_ID_UART1_RX,
    DMA_MUX_ID_UART2_TX,
    DMA_MUX_ID_UART2_RX,
    DMA_MUX_ID_UART3_TX,
    DMA_MUX_ID_UART3_RX,
    DMA_MUX_ID_UART4_TX,
    DMA_MUX_ID_UART4_RX,
    DMA_MUX_ID_UART5_TX,
    DMA_MUX_ID_UART5_RX,
    DMA_MUX_ID_UART6_TX,
    DMA_MUX_ID_UART6_RX,
    DMA_MUX_ID_UART7_TX,
    DMA_MUX_ID_UART7_RX,
    DMA_MUX_ID_UART8_TX,
    DMA_MUX_ID_UART8_RX,
    DMA_MUX_ID_UART9_TX,
    DMA_MUX_ID_UART9_RX,
    DMA_MUX_ID_UART10_TX,
    DMA_MUX_ID_UART10_RX,
    DMA_MUX_ID_UART11_TX,
    DMA_MUX_ID_UART11_RX,
    DMA_MUX_ID_UART12_TX,
    DMA_MUX_ID_UART12_RX,
    DMA_MUX_ID_ADC1_0,
    DMA_MUX_ID_ADC1_1,
    DMA_MUX_ID_ADC2_0,
    DMA_MUX_ID_ADC2_1,
    DMA_MUX_ID_ADC3_0,
    DMA_MUX_ID_ADC3_1,
    DMA_MUX_ID_SACI1_TX,
    DMA_MUX_ID_SACI1_RX,
    DMA_MUX_ID_SACI1_PDM,
    DMA_MUX_ID_ISTC
};
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES */

/** \brief  Dma hardware controller channel(s) status. */
typedef enum
{
    DMA_COMPLETED = 0U,
    DMA_IN_PROGRESS,
    DMA_BLOCK_DONE,
    DMA_PAUSED,
    DMA_ABORT,
    DMA_ERR,
    DMA_BUS_ERR,
    DMA_PENDING,
    DMA_CRC_ERROR
} Dma_ControllerStatusType;

/* This data type points to a interrupt routine */
/** \brief  This data type points to a interrupt routine. */
typedef void (*Dma_IrqHandle)(Dma_ControllerStatusType status, void *context);

/** \brief  Dma supported transfer directions. */
typedef enum
{
    DMA_MEMORY_TO_MEMORY = 0U,
    DMA_MEMORY_TO_DEVICE,
    DMA_DEVICE_TO_MEMORY,
    DMA_DEVICE_TO_DEVICE
} Dma_TransmitDirectionType;

/** \brief  MAD crc mode supported by dma(MAD: short form of Memory access description). */
typedef enum
{
    DMA_NO_MAD_CRC = 0U,     /*  DMA channel disable mad crc */
    DMA_MAD_CRC,             /* DMA channel enable mad crc */
    DMA_DATA_CRC
} Dma_MadCrcModeType;

/** \brief  Transfer type supported by dma. */
typedef enum
{
    DMA_MEMCPY = 0U,
    DMA_MEMSET,
    DMA_DEVICE,
    DMA_CYCLIC,
    DMA_TYPE_UNDEFINED
} Dma_TransactionType;

/** \brief  Dma stride mode increment method. */
typedef enum
{
    DMA_POSITIVE_OFFSET = 0U,
    DMA_NEGATIVE_OFFSET
} Dma_StrideModeType;

/** \brief  Dma stride mode increment method. */
typedef enum
{
    DMA_SCSTD = 0U,
    DMA_SFSTD
} Dma_StrideSelectType;

/** \brief  Dma supported transfer bus width. */
typedef enum
{
    DMA_BEAT_SIZE_1_BYTE = 0U,
    DMA_BEAT_SIZE_2_BYTE,
    DMA_BEAT_SIZE_4_BYTE,
    DMA_BEAT_SIZE_8_BYTE
} Dma_BeatSizeType;

/** \brief  Dma supported process mode. */
typedef enum
{
    DMA_INTERRUPT = 0U,
    DMA_POLLING
} Dma_EventProcessModeType;

/** \brief  Dma supported trigger mode. */
typedef enum
{
    DMA_TRIGGER_BY_HARDWARE = 0U,
    DMA_TRIGGER_BY_SOFTWARE,
    DMA_TRIGGER_BY_GTIMER,
    DMA_TRIGGER_BY_INTERNAL_EVENT, /* by linklist or channel linking */
    DMA_TRIGGER_MODE_NOT_DEFINED
} Dma_TriggerModeType;

/** \brief  Dma supported burst length. */
typedef enum
{
    DMA_BURST_LENGTH_1 = 0U,
    DMA_BURST_LENGTH_2,
    DMA_BURST_LENGTH_3,
    DMA_BURST_LENGTH_4,
    DMA_BURST_LENGTH_5,
    DMA_BURST_LENGTH_6,
    DMA_BURST_LENGTH_7,
    DMA_BURST_LENGTH_8,
    DMA_BURST_LENGTH_9,
    DMA_BURST_LENGTH_10,
    DMA_BURST_LENGTH_11,
    DMA_BURST_LENGTH_12,
    DMA_BURST_LENGTH_13,
    DMA_BURST_LENGTH_14,
    DMA_BURST_LENGTH_15,
    DMA_BURST_LENGTH_16,
    DMA_BURST_LENGTH_NOT_DEFINED
} Dma_BurstLengthType;

/** \brief  Dma supported tansfer bus select. */
typedef enum
{
    /* AXI64: High throughput bus for the external/internal memory access */
    DMA_PORT_AXI64 = 0U,
    /* AHB32: Low latency bus interface for peripheral access */
    DMA_PORT_AHB32,
    DMA_PROT_NOT_DEFINED
} Dma_PortSelectType;

/** \brief  Src/Dst burst type controls addressing of each burst transaction. */
typedef enum
{
    DMA_BURST_INCREMENTAL = 0U,
    DMA_BURST_FIXED,
    DMA_BURST_TYPE_UNDEFINED
} Dma_BurstType;

/** \brief  Dma supported buffer mode. */
typedef enum
{
    DMA_SINGLE_BUFFER = 0U,
    DMA_DOUBLE_BUFFER,
    DMA_CIRCULAR_BUFFER,
    DMA_2D_BUFFER,
    DMA_BUFFER_NOT_DEFINED
} Dma_BufferModeType;

/** \brief  Loop mode enable loop count feature of DMA. */
typedef enum
{
    DMA_LOOP_MODE_0 = 0U,
    DMA_LOOP_MODE_1,
    DMA_LOOP_MODE_2,
    DMA_LOOP_MODE_UNDEFINED
} Dma_LoopModeType;


/** \brief  Dma switch enevt control types. */
typedef enum
{
    /* Only working in loop mode enable with total size unfixed
    Switch Event Control (SEC[1:0]), controls
    behavior of DMA after amount of data as
    defined by BSIZE_L and BSIZE_H and LP_MODE
    is transferred by DMA
    */
    DMA_SWT_EVT_CTL_STOP_WTH_INT = 0U,
    DMA_SWT_EVT_CTL_SUSPEND_WTH_INT,
    DMA_SWT_EVT_CTL_CONTINUE_WTH_INT,
    DMA_SWT_EVT_CTL_CONTINUE_WTHOUT_INT,
    DMA_SWT_EVT_CTL_UNDEFINED
} Dma_SwitchEventControlType;

/** \brief  DMA flow control type. */
typedef enum
{
    DMA_DIR_MEMORY_TO_MEMORY = 0U,
    DMA_DIR_MEMORY_TO_DEVICE,
    DMA_DIR_DEVICE_TO_MEMORY,
    DMA_DIR_DEVICE_TO_DEVICE,
    DMA_DIR_REGISTER_TO_MEMORY,
    DMA_DIR_REGISTER_TO_DEVICE,
    DMA_DIR_MEMORY_TO_REGISTER,
    DMA_DIR_DEVICE_TO_REGISTER,
    DMA_DIR_NOT_DEFINED
} Dma_FlowControlType;

/** \brief  DMA transfer mode type. */
typedef enum
{
    DMA_TRANSFER_MODE_SINGLE = 0U,
    DMA_TRANSFER_MODE_CONTINUOUS,
    DMA_TRANSFER_MODE_LINKLIST,
    DMA_TRANSFER_MODE_CHAN_LINK,
    DMA_TRANSFER_MODE_NOT_DEFINED
} Dma_TransferModeType;

/** \brief  DMA channel(s) control states. */
typedef enum
{
    DMA_CH_CTL_STAT_STOP = 0U,
    DMA_CH_CTL_STAT_FLUSH = 1U,
    DMA_CH_CTL_STAT_REQ_FLUSH = 2U,
    DMA_CH_CTL_STAT_HALT = 3U,
    DMA_CH_CTL_STAT_RESUME = 4U,
    DMA_CH_CTL_STAT_ABORT = 5U
} Dma_ChannelControlStateType;

/** \brief  DMAinterrupt enable states. */
enum
{
    DMA_CH_INT_EN_HS_E2E_COR_ERROR = 1UL << 0U,
    DMA_CH_INT_EN_HS_E2E_UNC_ERROR = 1UL << 1U,
    DMA_CH_INT_EN_FIFO_E2E_COR_ERROR = 1UL << 2U,
    DMA_CH_INT_EN_FIFO_E2E_UNC_ERROR = 1UL << 3U,
    DMA_CH_INT_EN_AHB_RD_ERROR = 1UL << 4U,
    DMA_CH_INT_EN_AHB_WR_ERROR = 1UL << 5U,
    DMA_CH_INT_EN_AXI_RD_ERROR = 1UL << 6U,
    DMA_CH_INT_EN_AXI_WR_ERROR = 1UL << 7U,
    DMA_CH_INT_EN_CH_LINK_ERROR = 1UL << 8U,
    DMA_CH_INT_EN_MAD_CRC_ERROR = 1UL << 9U,
    DMA_CH_INT_EN_FW_RD_ERROR = 1UL << 10U,
    DMA_CH_INT_EN_FW_WR_ERROR = 1UL << 11U,
    DMA_CH_INT_EN_DATA_CRC_ERROR = 1UL << 12U,
    DMA_CH_INT_EN_PATTERN_DET_ERROR = 1UL << 13U,
    DMA_CH_INT_EN_LST_MAD_DONE = 1UL << 14U,
    DMA_CH_INT_EN_EVERY_MAD_DONE = 1UL << 15U,
    DMA_CH_INT_EN_CH_STOP = 1UL << 16U,
    DMA_CH_INT_EN_CH_FLUSH = 1UL << 17U,
    DMA_CH_INT_EN_REQ_FLUSH = 1UL << 18U,
    DMA_CH_INT_EN_CH_HALT = 1UL << 19U,
    DMA_CH_INT_EN_CH_ABORT = 1UL << 20U,
    DMA_CH_INT_EN_REQ_TIMEOUT = 1UL << 21U,
    DMA_CH_INT_EN_HS_COMP = 1UL << 23U,
    DMA_CH_INT_EN_PATTERN_POLL_MISMATCH = 1UL << 24U,
    DMA_CH_INT_EN_AXI_OUTSTD_UTID_ERROR = 1UL << 26U,
    DMA_CH_INT_EN_PS_ERROR = 1UL << 27U
};

/** \brief  Mux direction supported by dma, this is related to mux id. */
typedef enum
{
    DMA_MUX_RD = 1U, /* RD PERi to MEM -> RX */
    DMA_MUX_WR, /* MEM to PERI -> TX */
    DMA_MUX_BOTH
} Dma_MuxDirectionType;

enum
{
    DMA_CPU_ID_CORE0 = 0U,
    DMA_CPU_ID_CORE1,
    DMA_CPU_ID_CORE2,
    DMA_CPU_ID_CORE3,
    DMA_CPU_ID_CORE4,
    DMA_CPU_ID_MAX
};

struct Dma_ListNodeType
{
    struct Dma_ListNodeType *prev;
    struct Dma_ListNodeType *next;
};

/** \brief  Dma controller parameters type. */
/** Traceability       : SWSR_DMA_021 */
typedef struct
{
    uint32 dmaBaseAddress;
    struct Dma_ListNodeType channels;
    uint32 channelNumber;
} Dma_ControllerParamType;

/** \brief  Dma channel(s) configuration parameters type. */
/** Traceability       : SWSR_DMA_022 */
typedef struct
{
    uint8 channelId;
    uint8 allocated;
    struct Dma_ListNodeType node;
    const Dma_ControllerParamType *device;
    Dma_ControllerStatusType channelStatus;
    Dma_EventProcessModeType processMode;
    Dma_IrqHandle irqCallback;
    void *context;
} Dma_ChannelConfigType;

/** \brief  Dma channel(s) transfer configuration type. */
/** Traceability       : SWSR_DMA_023 */
typedef struct
{
    Dma_TransmitDirectionType direction;
    Dma_TransactionType transaction;
    Dma_EventProcessModeType processMode;
    Dma_BeatSizeType srcBusWidth;
    Dma_BeatSizeType dstBusWidth;
    /* Maximum number of words (in units of the dma_dev_bus_width_e, not bytes)
     * sent in one DMA req.
     */
    Dma_BurstLengthType srcMaxBurst;
    Dma_BurstLengthType dstMaxBurst;
    Dma_PortSelectType srcPortSelect;
    Dma_PortSelectType dstPortSelect;
    Dma_BurstType srcIncDirection;
    Dma_BurstType dstIncDirection;
    Dma_StrideModeType srcStridePol;
    Dma_StrideModeType dstStridePol;
    Dma_StrideSelectType srcStrideSelect;
    Dma_StrideSelectType dstStrideSelect;
    Dma_BufferModeType bufferMode;
    Dma_LoopModeType loopMode;
    Dma_FlowControlType flowControl;
    Dma_TransferModeType transferMode; /* single continuous linklist channellink */
    Dma_TriggerModeType linkListTriggerMode;
    Dma_MadCrcModeType madCrcMode;
    Dma_SwitchEventControlType switchControl;
    boolean srcStrideEnable;
    boolean dstStrideEnable;
    boolean firstMad;
    boolean lastMad;
    boolean srcCache;
    boolean dstCache;
    boolean customMuxIdFlag;
    uint8 memsetValue;
    uint16 muxId;
    uint16 customMuxId;
    uint32 periodLength;
    uint32 srcAddress;
    uint32 dstAddress;
    uint32 srcCoarseStride;
    uint32 dstCoarseStride;
    uint32 srcFineStride;
    uint32 dstFineStride;
    uint32 bufferSize;
    uint32 linkListAddress;
} Dma_DeviceConfigType;

/** \brief  Dma mux configuration parameter information. */
typedef struct
{
    uint16 port;
    uint32 startAddress;
    uint32 length;
    Dma_MuxDirectionType muxDirect;
} Dma_MuxParamType;

/** \brief  Dma hardware configurations: base address and mux tables. */
typedef struct
{
    uint32 baseAddress;
    const Dma_MuxParamType *muxTable;
    uint32 muxTableLength;
    const uint8 *channelIdTable;
    uint32 channelNumber;
} Dma_HwConfigType;

/** \brief  Dma link list node configutations type. */
typedef struct
{
    uint32 srcAddress;
    uint32 dstAddress;
    uint32 transactionControl;
    uint32 blockConfig;
    uint32 operationMode;
    uint32 operationData;
    uint32 madCrc;
    uint32 linkAddress;
} Dma_LinkListNodeConfigType;

/** \brief  Dma link list type. */
typedef struct
{
    uint32 physisAddress;
    struct Dma_ListNodeType linkListNode;
    struct Dma_ListNodeType linkListHead;
    Dma_LinkListNodeConfigType linkListItem;
    uint32 bitmapIndex;
} Dma_linkListType;

/** \brief  Dma link list descriptions type. */
typedef struct
{
    uint32 physisAddress;
    Dma_linkListType *memBase;
    unsigned long *memBitmap;
    uint32 memSize;
} Dma_LinkListDescType;

/** \brief  Dma controller(s), channel(s) and link list general type. */
typedef struct
{
    uint32 baseAddress; /* dmac base address */
    const Dma_HwConfigType *hwConfig;/* dmac hardware config */
} Dma_CoeffType;

/** \brief  Dma channel register configuration type. */
typedef struct
{
    Dma_ChannelConfigType channel;
    Dma_DeviceConfigType deviceConfig;
    uint32 blockSize;
    uint32 length;
    uint8 psCnt;
    Dma_CoeffType dmaConfig;
    Dma_LinkListDescType linkListDesc;
} Dma_ChannelRegType;

/** \brief  Dma local buffer type */
typedef struct
{
    uint32 bufferBaseAddress;
    uint32 bufferSize;
} Dma_LocalBufferType;

typedef struct
{
    uint32 srcAddress;
    uint32 dstAddress;
    Dma_BurstType srcIncDirection;
    Dma_BurstType dstIncDirection;
    Dma_BeatSizeType srcBusWidth;
    Dma_BeatSizeType dstBusWidth;
} Dma_UpdateTransmissionType;
/** @} */

#ifdef __cplusplus
}
#endif

#endif /** #ifndef DMA_TYPES_H */
/* End of file */
