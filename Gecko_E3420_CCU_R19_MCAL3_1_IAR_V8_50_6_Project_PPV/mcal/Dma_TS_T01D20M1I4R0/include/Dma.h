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
 *  \file     Dma.h                                                                                     *
 *  \brief    This file contains interface header for DMA MCAL driver.                                  *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/17     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifndef DMA_H_
#define DMA_H_

#ifdef __cplusplus
extern "C" {
#endif
/**
 *
 * \defgroup MCAL_DMA DMA Driver
 *
 * The Dma Driver MCAL provides low level access to onbaord Dma peripheral
 * present on Device.<br>
 * The Dma Hardware Unit cntrolled by Dma Driver combines one or several Dma
 * controllers, <br>
 * which may be located on-chip or as external standalone devices of the same
 * type, with common or separate Hardware Objects<br>
 *
 * \sa MCAL_DMA_MACRO
 * \sa MCAL_DMA_CFG
 * \sa MCAL_DMA_API
 *  \{
 */

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Dma_Types.h"
#include "Dma_Cfg.h"
#include "Mcal.h"
/********************************************************************************************************
 *                                      Macro definition                                                *
 *******************************************************************************************************/
/**
 *  \defgroup MCAL_DMA_MACRO Dma Macro.
 *
 * This files defines DMA MCAL macros.
 *  \{
 */

/**
 *  \name Dma Driver Module SW Version Info
 *
 *  Defines for DMA Driver version used for compatibility checks
 *  @{
 */
/** @} */

/**
 *  \name Dma Driver ID Info
 *  @{
 */
/** \brief  Semi Driver Vendor ID */
#define DMA_VENDOR_ID                                                   (0x8CU)
/** \brief  Dma Driver Module ID       */
#define DMA_MODULE_ID                                                   (255U)
/** \brief Dma Driver Instance ID */
#define DMA_INSTANCE_ID                                                 (0x00U)
/** @} */

/**
 *  \name Dma Driver Service Id.
 *
 *  The Service Id is one of the argument to Det_ReportError function and is
 *  used to identify the source of the error.
 *  @{
 */
/** \brief  FUNCTION:Dma_Init() */
/* Traceability: SWSR SWSR_Spi_xxx */
#define DMA_INIT_ID                                                     (0x00U)
/** \brief  FUNCTION:Dma_RequestChannelWithId()  */
#define DMA_REQUEST_CHANNEL_ID                                          (0x01U)
/** \brief  FUNCTION:Dma_ReleaseChannel()  */
#define DMA_RELEASE_CHANNEL_ID                                          (0x02U)
/** \brief  FUNCTION:Dma_ConfigChannel()  */
#define DMA_CONFIG_CHANNEL_ID                                           (0x03U)
/** \brief  FUNCTION:Dma_PrepareTransmission()  */
#define DMA_PREPARE_TRANSMISSION_ID                                     (0x04U)
/** \brief  FUNCTION:Dma_UpdateTransmitAddressAndLength()  */
#define DMA_UPDATE_ADDRESS_LENGTH_ID                                    (0x05U)
/** \brief  FUNCTION:Dma_Start()  */
#define DMA_START_ID                                                    (0x06U)
/** \brief  FUNCTION:Dma_Stop()  */
#define DMA_STOP_ID                                                     (0x07U)
/** \brief  FUNCTION:Dma_GetChannelStatus()  */
#define DMA_GET_CHANNEL_STATUS_ID                                       (0x08U)
/** \brief  FUNCTION:Dma_GetXferBytes()  */
#define DMA_GET_XFER_BYTES_ID                                           (0x09U)
/** \brief  FUNCTION:Dma_GetConfigParams()  */
#define DMA_GET_CONFIG_PARAMS_ID                                        (0x0AU)
/** \brief  FUNCTION:Dma_FlushCache()  */
#define DMA_FLUSH_CACHE_ID                                              (0x0BU)
/** \brief  FUNCTION:Dma_InvalidateCache()  */
#define DMA_INVALIDATE_ID                                               (0x0CU)
/** \brief  FUNCTION:Dma_CleanCache ()  */
#define DMA_CLEAN_ID                                                    (0x0DU)
/** \brief  FUNCTION:Dma_ConfigurationCheck ()  */
#define DMA_CONFIG_CHECK_ID                                             (0x0EU)
/** \brief  FUNCTION:Dma_InitConfigChannel ()  */
#define DMA_INIT_CONFIG_ID                                              (0x0FU)
/** \brief  FUNCTION:Dma_GetVersionInfo()  */
#define DMA_VERSION_ID                                                  (0x10U)
/** \brief  FUNCTION:Dma_UpdateCyclicCRC()  */
#define DMA_UPDATE_CYCLI_CRC                                            (0x11U)
/** @} */
/** @} */
/** \cond  Get Peripheral controller base address */
#define DMA_DEVICE_BASE(dev)                                            (APB_##dev##_BASE)
/** \endcond  */
/********************************************************************************************************
 *                                      Types definition                                                *
 *******************************************************************************************************/
/**
 *  \defgroup MCAL_DMA_CFG Dma Configuration.
 *
 * This files defines DMA MCAL configuration structures
 *  @{
 */

/** \brief  Dma module identify, which are currently support modules. */
/** Traceability       : SWSR_DMA_025 */
typedef enum
{
    DMA_MODULE_ADC = 0U,
    DMA_MODULE_ETIMER,
    DMA_MODULE_PWM,
    DMA_MODULE_SPI,
    DMA_MODULE_XSPI,
    DMA_MODULE_MEM,
    DMA_MODULE_XTRG,
    DMA_MODULE_UNDEFINE
} Dma_ModuleType;

/** \brief  Dma sub ids, each module has dedicated sub id(s). */
/** Traceability       : SWSR_DMA_024 */
typedef enum
{
    /* Adc sub id */
    DMA_ADC_FIFO0 = 0U,
    DMA_ADC_FIFO1,
    DMA_ADC_FIFO2,
    DMA_ADC_FIFO3,
    /* Icu sub id */
    DMA_ICU_CPT_A,
    DMA_ICU_CPT_B,
    DMA_ICU_CPT_C,
    DMA_ICU_CPT_D,
    DMA_ICU_CPT_CE,
    /* Mme sub id */
    DMA_CH_MEM2MEM,
    /* Pwm sub id */
    DMA_PWM_FIFO_A,
    DMA_PWM_FIFO_B,
    DMA_PWM_FIFO_C,
    DMA_PWM_FIFO_D,
    DMA_PWM_CE,
    /* Spi sub id */
    DMA_SPI_TX,
    DMA_SPI_RX,
    /* xSpi sub id */
    DMA_XSPI_PORTA_RD,
    DMA_XSPI_PORTA_WR,
    DMA_XSPI_PORTB_RD,
    DMA_XSPI_PORTB_WR,
    DMA_XTRG_0,
    DMA_XTRG_1,
    DMA_SUB_ID_UNDEFINE
} Dma_SubIdType;

/** \brief  Dma adc hardware unit(s) module id(s). */
typedef enum
{
    /* ADC */
    DMA_ADC1 = 0U,
    DMA_ADC2,
    DMA_ADC3,
    /* ICU */
    DMA_ICU_INDEX_ETIMER1,
    DMA_ICU_INDEX_ETIMER2,
    DMA_ICU_INDEX_ETIMER3,
    DMA_ICU_INDEX_ETIMER4,
    /* Memory to memory */
    DMA_MEM_MODE1,
    DMA_MEM_MODE2,
    DMA_MEM_MODE3,
    DMA_MEM_MODE4,
    DMA_MEM_MODE5,
    DMA_MEM_MODE6,
    DMA_MEM_MODE7,
    DMA_MEM_MODE8,
    DMA_MEM_MODE9,
    DMA_MEM_MODE10,
    DMA_MEM_MODE11,
    DMA_MEM_MODE12,
    DMA_MEM_MODE13,
    DMA_MEM_MODE14,
    DMA_MEM_MODE15,
    DMA_MEM_MODE16,
    /* PWM */
    DMA_EPWM1_INDEX,
    DMA_EPWM2_INDEX,
    DMA_EPWM3_INDEX,
    DMA_EPWM4_INDEX,
    DMA_ETIMER1_INDEX,
    DMA_ETIMER2_INDEX,
    DMA_ETIMER3_INDEX,
    DMA_ETIMER4_INDEX,
    /* SPI */
    DMA_CSIB1,
    DMA_CSIB2,
    DMA_CSIB3,
    DMA_CSIB4,
    DMA_CSIB5,
    DMA_CSIB6,
    DMA_CSIB7,
    DMA_CSIB8,
    /* xSpi */
    DMA_XSPI0,
    DMA_XSPI1,
    DMA_XTRG,
    DMA_HW_UNIT_UNDEFINE
} Dma_PeripheralIdType;

/** \brief  Dma instance configuration parameters. */
/** Traceability       : SWSR_DMA_026 */
typedef struct
{
    /** Pointer to dma controller configuration parameters */
    Dma_HwControllerType controller;
    /** Dma channels id, range: 0-23 */
    uint8 channelId;
} Dma_InstanceConfigType;

/** \brief  Mempry from/to memory configuration parameters, multicore are already supported. */
typedef struct
{
    /** Which adc controller is configured on a dma channel */
    Dma_PeripheralIdType memoryId;
    /** CoreId for multicore */
    uint8 coreId;
    /** Assign a dma channel to memory to memory transmit */
    Dma_InstanceConfigType memoryToMemory;
} Dma_MemoryToMemoryConfigType;

/** \brief  Adc configuration parameters, multicore are already supported. */
typedef struct
{
    /** Which adc controller is configured on a dma channel */
    Dma_PeripheralIdType adcControllerId;
    /** CoreId for multicore */
    uint8 coreId;
    /** Assign a dma channel to Adc transmit */
    Dma_InstanceConfigType adcFIFO0;
    Dma_InstanceConfigType adcFIFO1;
    Dma_InstanceConfigType adcFIFO2;
    Dma_InstanceConfigType adcFIFO3;
} Dma_AdcConfigType;

/** \brief  Spi configuration parameters, multicore are already supported. */
typedef struct
{
    /** Which spi controller is configured on a dma channel */
    Dma_PeripheralIdType spiControllerId;
    /** CoreId for multicore */
    uint8 coreId;
    /** Assign a dma channel to Spi transmit */
    Dma_InstanceConfigType spiTx;
    /** Assign a dma channel to Spi receive */
    Dma_InstanceConfigType spiRx;
} Dma_SpiConfigType;

/** \brief  Pwm configuration parameters, multicore are already supported. */
typedef struct
{
    /** Which pwm controller is configured on a dma channel */
    Dma_PeripheralIdType pwmControllerId;
    /** CoreId for multicore */
    uint8 coreId;
    /** Assign a dma channel to PWM_FIFO_A */
    Dma_InstanceConfigType pwmFIFOA;
    /** Assign a dma channel to PWM_FIFO_B */
    Dma_InstanceConfigType pwmFIFOB;
    /** Assign a dma channel to PWM_FIFO_C */
    Dma_InstanceConfigType pwmFIFOC;
    /** Assign a dma channel to PWM_FIFO_D */
    Dma_InstanceConfigType pwmFIFOD;
    /** Assign a dma channel to PWM_CE */
    Dma_InstanceConfigType pwmCE;
} Dma_PwmConfigType;

/** \brief  Icu configuration parameters, multicore are already supported. */
typedef struct
{
    /** Which icu controller is configured on a dma channel */
    Dma_PeripheralIdType icuControllerId;
    /** CoreId for multicore */
    uint8 coreId;
    /* Assign a dma channel to ICU_CPT_A */
    Dma_InstanceConfigType icuCaptureA;
    /** Assign a dma channel to ICU_CPT_B */
    Dma_InstanceConfigType icuCaptureB;
    /*** Assign a dma channel to ICU_CPT_C */
    Dma_InstanceConfigType icuCaptureC;
    /** Assign a dma channel to ICU_CPT_D */
    Dma_InstanceConfigType icuCaptureD;
    /** Assign a dma channel to ICU_CPT_CE */
    Dma_InstanceConfigType icuCaptureCE;
} Dma_IcuConfigType;

/** \brief  xSpi configuration parameters, multicore are already supported. */
typedef struct
{
    /** Which xSpi controller is configured on a dma channel */
    Dma_PeripheralIdType xSpiControllerId;
    /** CoreId for multicore */
    uint8 coreId;
    /** Assign a dma channel to XSpi portA read */
    Dma_InstanceConfigType xSpiPortARead;
    /** Assign a dma channel to XSpi portA write */
    Dma_InstanceConfigType xSpiPortAWrite;
    /** Assign a dma channel to XSpi portB read */
    Dma_InstanceConfigType xSpiPortBRead;
    /** Assign a dma channel to XSpi portB write */
    Dma_InstanceConfigType xSpiPortBWrite;
} Dma_XspiConfigType;

/** \brief  Xtrg configuration parameters, multicore are already supported. */
typedef struct
{
    /** Which adc controller is configured on a dma channel */
    Dma_PeripheralIdType xtrgControllerId;
    /** CoreId for multicore */
    uint8 coreId;
    /** Assign a dma channel to memory to memory transmit */
    Dma_InstanceConfigType xtrg0;
    Dma_InstanceConfigType xtrg1;
} Dma_XtrgConfigType;


/** \brief  Dma channel(s) assignment on each core. */
typedef struct
{
    /** Dma controller SF0 base configuration table */
    const Dma_HwConfigType *configTableSF0;
#if (STD_OFF == DMA_LOCK_STEP_MODE)
    /** Dma controller SF1 base configuration table */
    const Dma_HwConfigType *configTableSF1;
#endif /** #if (STD_OFF == DMA_LOCK_STEP_MODE) */
    /** DMA channel usage information by ADC */
    const Dma_AdcConfigType *adcConfigTable;
    uint8 adcConfigTableLength;
    /** DMA channel usage information by ICU */
    const Dma_IcuConfigType *icuConfigTable;
    uint8 icuConfigTableLength;
    /** DMA channel usage information by mem */
    const Dma_MemoryToMemoryConfigType *memConfigTable;
    uint8 memConfigTableLength;
    /** DMA channel usage information by PWM */
    const Dma_PwmConfigType *pwmConfigTable;
    uint8 pwmConfigTableLength;
    /** DMA channel usage information by SPI */
    const Dma_SpiConfigType *spiConfigTable;
    uint8 spiConfigTableLength;
    /** DMA channel usage information by XSPI */
    const Dma_XspiConfigType *xSpiConfigTable;
    uint8 xSpiConfigTableLength;
    /** DMA channel usage information by XTRG */
    const Dma_XtrgConfigType *xtrgConfigTable;
    uint8 xtrgConfigTableLength;
} Dma_ConfigType;
/** @} */
/********************************************************************************************************
 *                                      Global variables                                                *
 *******************************************************************************************************/
/** \cond  Dma channels allocates on every core table  */
extern const Dma_ConfigType Dma_ConfigRootTable;
/** \endcond  */
/**
 *  \defgroup MCAL_DMA_API Dma Driver API.
 *
 * This files defines DMA MCAL macros.
 *  @{
 */
/********************************************************************************************************
 *                                      Global fcuntion                                                 *
 *******************************************************************************************************/
#define DMA_START_SEC_CODE
#include "Dma_MemMap.h"
/** *****************************************************************************************************
 * \brief This function initialize DMA controller and set DMA lockstep mode.
 *
 * \verbatim
 * Syntax             : void Dma_Init
 *                      (
 *                          const Dma_ConfigType* configPtr
 *                      )
 *
 * Service ID[hex]    : 0x00
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
 * Description        : Driver Module Initialization function.The Initialization function shall
 *                      initialize all DMA relevant registers with the values of the structure
 *                      referenced by the parameter ConfigPtr.
 * \endverbatim
 * Traceability       : SWSR_DMA_004 SWSR_DMA_005 SWSR_DMA_013 SWSR_DMA_019 SWSR_DMA_020 SWSR_DMA_027
 *                      SWSR_DMA_049 SW_SM002 SW_SM006
 *******************************************************************************************************/
extern void Dma_Init(const Dma_ConfigType *configPtr);
/** *****************************************************************************************************
 * \brief
 *
 * \verbatim
 * Syntax             : Dma_ChannelConfigType *Dma_RequestChannelWithId
 *                      (
 *                          Dma_HwControllerType controllerId
 *                          uint32               channelId
 *                      )
 *
 * Service ID[hex]    : 0x01
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : controllerId - Numeric identifier of the DMA controller
 *                      channelId    - Numeric identifier of the DMA channel.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Return the channel pointer, which record channel configurations
 *
 * Description        : Only request channel(s) that have been configured in EB. If request is
 *                      successful, the channel will be marked as allocated.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_018 SWSR_DMA_019 SWSR_DMA_028 SWSR_DMA_049 SW_SM001
 *                      SW_SM006
 *******************************************************************************************************/
extern Dma_ChannelConfigType *Dma_RequestChannelWithId(Dma_HwControllerType controllerId,
        uint32 channelId);
/** *****************************************************************************************************
 * \brief This function servce to release DMA controller channel.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Dma_ReleaseChannel
 *                      (
 *                          Dma_ChannelConfigType *channel
 *                      )
 *
 * Service ID[hex]    : 0x02
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : *channel - Pointer to a selected channel configuration structure.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Release successful.
 *                      DMA_E_UNINIT: DMA driver is not initialized.
 *                      DMA_E_PARAM_POINTER: Pointer is NULL_PTR.
 *
 * Description        : Release the DMA channel so that the new request can succeed, if the release
 *                      is successful, the channel status is set to unallocated.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_018 SWSR_DMA_019 SWSR_DMA_029 SWSR_DMA_049 SWSR_DMA_050
 *                      SW_SM001 SW_SM006
 *******************************************************************************************************/
extern Std_ReturnType Dma_ReleaseChannel(Dma_ChannelConfigType *channel);
/** *****************************************************************************************************
 * \brief This function servce to set configuration pointer to an initial value.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Dma_ConfigChannel
 *                      (
 *                          const Dma_ChannelConfigType * const channel
 *                          const Dma_DeviceConfigType  * const config
 *                      )
 *
 * Service ID[hex]    : 0x03
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : *channel - Pointer to a selected channel configuration structure.
 *                      *config  - Pointer to register configuration structure.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Copy configuration parameters successful.
 *                      DMA_E_UNINIT: DMA driver is not initialized.
 *                      DMA_E_PARAM_POINTER: Pointer is NULL_PTR.
 *
 * Description        : Copy DMA register configuration parameters to selected channel.
 * \endverbatim
 * Traceability       : SWSR_DMA_006 SWSR_DMA_007 SWSR_DMA_008 SWSR_DMA_009 SWSR_DMA_010 SWSR_DMA_011
 *                      SWSR_DMA_012 SWSR_DMA_014 SWSR_DMA_015 SWSR_DMA_016 SWSR_DMA_018 SWSR_DMA_019
 *                      SWSR_DMA_030 SWSR_DMA_049 SWSR_DMA_050 SW_SM001 SW_SM006
 *******************************************************************************************************/
extern Std_ReturnType Dma_ConfigChannel(const Dma_ChannelConfigType *const channel,
                                        const Dma_DeviceConfigType *const config);
/** *****************************************************************************************************
 * \brief This function service to prepare transmission on the DMA channel.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Dma_PrepareTransmission
 *                      (
 *                          const Dma_ChannelConfigType * const channel
 *                          uint32  bufferLength
 *                      )
 *
 * Service ID[hex]    : 0x04
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : *channel     - Pointer to a selected channel configuration structure.
 *                      bufferLength - Total transmit data length.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Write configuration to register successful.
 *                      DMA_E_UNINIT: DMA driver is not initialized.
 *                      DMA_E_PARAM_POINTER: Pointer is NULL_PTR.
 *                      DMA_E_PARAMS: Input parameter error.
 *
 * Description        : This function service to write configuration parameters to channel hardware
 *                      registers. Once the write is completed the DMA is ready for transfer.
 * \endverbatim
 * Traceability       : SWSR_DMA_006 SWSR_DMA_007 SWSR_DMA_008 SWSR_DMA_009 SWSR_DMA_010 SWSR_DMA_011
 *                      SWSR_DMA_012 SWSR_DMA_013 SWSR_DMA_014 SWSR_DMA_015 SWSR_DMA_016 SWSR_DMA_018
 *                      SWSR_DMA_019 SWSR_DMA_031 SWSR_DMA_049 SWSR_DMA_050 SW_SM001 SW_SM006
 *******************************************************************************************************/
extern Std_ReturnType Dma_PrepareTransmission(const Dma_ChannelConfigType *const channel,
        uint32 bufferLength);
#if (DMA_UPDATE_CONFIG_API == STD_ON)
/** *****************************************************************************************************
 * \brief This function service to update transmission address and length information.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Dma_UpdateTransmitAddressAndLength
 *                      (
 *                          const Dma_ChannelConfigType * const channel
 *                          const Dma_UpdateTransmissionType * const updateConfig
 *                          uint32                length
 *                      )
 *
 * Service ID[hex]    : 0x05
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : *channel        - Pointer to a selected channel configuration structure.
 *                      *updateConfig   - Pointer to a update info.
 *                      length          - Total transmit data length.

 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Update address and length successful.
 *                      DMA_E_UNINIT: DMA driver is not initialized.
 *                      DMA_E_PARAM_POINTER: Pointer is NULL_PTR.
 *                      DMA_E_PARAMS: Input parameter error.
 *
 * Description        : This function support only updating the source address, destination address,
 *                      transmit data length and burst types registers. If you do not want to update
 *                      burst type, you can pass DMA_BURST_TYPE_UNDEFINED parameters to srcIncDirection
 *                      and dstIncDirection, and then ip layer function will bypass burst type
 *                      configuration.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_018 SWSR_DMA_019 SWSR_DMA_032 SWSR_DMA_046 SWSR_DMA_049
 *                      SWSR_DMA_050 SW_SM001 SW_SM006
 *******************************************************************************************************/
extern Std_ReturnType Dma_UpdateTransmitAddressAndLength(const Dma_ChannelConfigType *const channel,
        const Dma_UpdateTransmissionType *const updateConfig, uint32 length);
#endif /** #if (DMA_UPDATE_CONFIG_API == STD_ON) */
/** *****************************************************************************************************
 * \brief This function service to start transmit data on the DMA channel.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Dma_Start
 *                      (
 *                          const Dma_ChannelConfigType * const channel
 *                      )
 *
 * Service ID[hex]    : 0x06
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : *channel - Pointer to a selected channel configuration structure.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Start tramsfer successful.
 *                      DMA_E_UNINIT: DMA driver is not initialized.
 *                      DMA_E_PARAM_POINTER: Pointer is NULL_PTR.
 *                      DMA_E_PARAMS: Input parameter error.
 *
 * Description        : Enable current DMA channel transfer. If current configuration is memory to/from
 *                      memory or memory to peripheral will start the transfer immediately, if current
 *                      configuration is peripheral to memory need to wait for hardware request.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_018 SWSR_DMA_019 SWSR_DMA_033 SWSR_DMA_049 SWSR_DMA_050
 *                      SW_SM001 SW_SM006
 *******************************************************************************************************/
extern Std_ReturnType Dma_Start(const Dma_ChannelConfigType *const channel);
/** *****************************************************************************************************
 * \brief This function service to stop transmit data on the DMA channel.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Dma_Stop
 *                      (
 *                          const Dma_ChannelConfigType * const channel
 *                      )
 *
 * Service ID[hex]    : 0x07
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : *channel - Pointer to a selected channel configuration structure.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Stop transfer successful.
 *                      DMA_E_UNINIT: DMA driver is not initialized.
 *                      DMA_E_PARAM_POINTER: Pointer is NULL_PTR.
 *                      DMA_E_PARAMS: Input parameter error.
 *
 * Description        : Disable current DMA channel transfer.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_018 SWSR_DMA_019 SWSR_DMA_034 SWSR_DMA_049 SWSR_DMA_050
 *                      SW_SM001 SW_SM006
 *******************************************************************************************************/
extern Std_ReturnType Dma_Stop(const Dma_ChannelConfigType *const channel);
/** *****************************************************************************************************
 * \brief This function service to returns the transmission status of the current channel.
 *
 * \verbati0m
 * Syntax             : Dma_ControllerStatusType Dma_GetChannelStatus
 *                      (
 *                          const Dma_ChannelConfigType * const channe0l
 *                      )
 *
 * Service ID[hex]    : 0x08
 *
 * Sync/Async         : Synchronou0s
 *
 * Reentrancy         : Reentran0t
 *
 * Parameters (in)    : *channel   - Pointer to a selected channel configuration structure.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : DMA_COMPLETED     : Current channel transmission completed.
 *                      DMA_IN_PROGRESS   : Current channel transmission in progress.
 *                      DMA_PAUSED        : Current channel transmission is suspended.
 *                      DMA_ABORT         : Current channel transmission aborted.
 *                      DMA_ERR           : Current channel transmission an error occurred.
 *                      DMA_PENDING       : Current channel transmission pending.
 *                      DMA_MAD_CRC_ERROR : Current channel transmission MAD crc error occurred.
 *
 * Description        : This function support only updating the source address, destination address and
 *                      transmit data length registers.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_018 SWSR_DMA_019 SWSR_DMA_035 SWSR_DMA_049 SW_SM001
 *                      SW_SM006
 *******************************************************************************************************/
extern Dma_ControllerStatusType Dma_GetChannelStatus(const Dma_ChannelConfigType *const channel);
/** *****************************************************************************************************
 * \brief This function service to get current channel total data length.
 *
 * \verbatim
 * Syntax             : uint32 Dma_GetXferBytes
 *                      (
 *                          Dma_ChannelConfigType *channel
 *                          uint8 clearFlag
 *                      )
 *
 * Service ID[hex]    : 0x09
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : *channel  - Pointer to a selected channel configuration structure.
 *                      clearFlag - Clear data transfer length register or not.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Total data length of MAD transmission
 *
 * Description        : This function service to get current channel total data length of MAD
 *                      transmission.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_018 SWSR_DMA_019 SWSR_DMA_036 SWSR_DMA_048 SWSR_DMA_049
 *                      SW_SM001 SW_SM006
 *******************************************************************************************************/
extern uint32 Dma_GetXferBytes(const Dma_ChannelConfigType *channel, uint8 clearFlag);
/** *****************************************************************************************************
 * \brief This function service to get DMA channel configurations from EB tool.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Dma_GetConfigParams
 *                      (
 *                          Dma_PeripheralIdType   peripheralId
 *                          Dma_SubIdType          subId
 *                          Dma_ModuleType         moduleId
 *                          Dma_InstanceConfigType *dmaConfig
 *                      )
 *
 * Service ID[hex]    : 0x0A
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : peripheralId - Peripheral Hw Unit index.
 *                      subId        - Peripheral sub functional index.
 *                      moduleId     - DMA_MODULE_ADC
 *                                     DMA_MODULE_ETIMER
 *                                     DMA_MODULE_PWM
 *                                     DMA_MODULE_SPI
 *                                     DMA_MODULE_XSPI
 *                      *dmaConfig   - Pointer to a configuration structure.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Get configurations successful.
 *                      DMA_E_UNINIT: DMA driver is not initialized.
 *                      DMA_E_PARAM_POINTER: Pointer is NULL_PTR.
 *                      DMA_E_PARAMS: Input parameter error.
 *
 * Description        : This function service to get current channel configurations from EB tool. The
 *                      configuration parameters include which channel is assigned to which peripheral
 *                      and which core.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_018 SWSR_DMA_019 SWSR_DMA_037 SWSR_DMA_049 SW_SM001
 *                      SW_SM006
 *******************************************************************************************************/
extern Std_ReturnType Dma_GetConfigParams(Dma_PeripheralIdType peripheralId, Dma_SubIdType subId,
        Dma_ModuleType moduleId, Dma_InstanceConfigType *dmaConfig);
/** *****************************************************************************************************
 * \brief This function service to flush cache.
 *
 * \verbatim
 * Syntax             : void Dma_FlushCache
 *                      (
 *                          uint32 Address
 *                          uint32 size
 *                      )
 *
 * Service ID[hex]    : 0x0B
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : address - Start address.
 *                      size    - Buffer size.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function service to clean and then invalidate cache memory.
 * \endverbatim
 * Traceability       : SWSR_DMA_018 SWSR_DMA_019 SWSR_DMA_039 SWSR_DMA_047 SWSR_DMA_049 SW_SM006
 *******************************************************************************************************/
extern void Dma_FlushCache(uint32 address, uint32 size);
/** *****************************************************************************************************
 * \brief This function service to invalidae cache.
 *
 * \verbatim
 * Syntax             : void Dma_InvalidateCache
 *                      (
 *                          uint32 address
 *                          uint32 size
 *                      )
 *
 * Service ID[hex]    : 0x0C
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : address - Start address.
 *                      size    - Buffer size.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function service to read new data from RAM or ROM memory to cache.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_018 SWSR_DMA_019 SWSR_DMA_039 SWSR_DMA_047 SWSR_DMA_049 SW_SM006
 *******************************************************************************************************/
extern void Dma_InvalidateCache(uint32 address, uint32 size);
/** *****************************************************************************************************
 * \brief This function service to clean cache.
 *
 * \verbatim
 * Syntax             : void Dma_CleanCache
 *                      (
 *                          uint32 address
 *                          uint32 size
 *                      )
 *
 * Service ID[hex]    : 0x0D
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : address - Start address.
 *                      size    - Buffer size.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function service to write cache memory data to RAM memor
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_018 SWSR_DMA_019 SWSR_DMA_039 SWSR_DMA_047 SWSR_DMA_049 SW_SM006
 *******************************************************************************************************/
extern void Dma_CleanCache(uint32 address, uint32 size);
#if (DMA_CONFIG_CHECK_API == STD_ON)
/** *****************************************************************************************************
 * \brief This function is service to check if the configuration is correct or not.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Dma_ConfigurationCheck
 *                      (
 *                          Dma_ChannelConfigType *channel
 *                      )
 *
 * Service ID[hex]    : 0x0E
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : *channel - Pointer to a selected channel configuration structure.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Register configurations check successful.
 *                      E_NOT_OK: Invalid parameters or error occurred.
 *                      DMA_E_UNINIT: DMA driver is not initialized.
 *                      DMA_E_PARAM_POINTER: Pointer is NULL_PTR.
 *
 * Description        : This function will read back MAD registers value and then check the configuration
 *                      parameters and register value for consistency.
 * \endverbatim
 * Traceability       : SWSR_DMA_018 SWSR_DMA_019 SWSR_DMA_049 SWSR_DMA_050 SWSR_DMA_052 SW_SM001
 *                      SW_SM006
 *******************************************************************************************************/
extern Std_ReturnType Dma_ConfigurationCheck(Dma_ChannelConfigType *channel);
#endif /** #if (DMA_CONFIG_CHECK_API == STD_ON) */
/** *****************************************************************************************************
 * \brief This function servce to set configuration pointer to an initial value.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Dma_InitConfigChannel
 *                      (
 *                          Dma_DeviceConfigType *config
 *                      )
 *
 * Service ID[hex]    : 0x0F
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : *config - Pointer to configuration parameter.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Initialization configurations successful.
 *                      DMA_E_UNINIT: DMA driver is not initialized.
 *                      DMA_E_PARAM_POINTER: Pointer is NULL_PTR.
 *
 * Description        : Set configuration parameters to default value.
 * \endverbatim
 * Traceability       : SWSR_DMA_006 SWSR_DMA_007 SWSR_DMA_008 SWSR_DMA_009 SWSR_DMA_010 SWSR_DMA_011
 *                      SWSR_DMA_012 SWSR_DMA_014 SWSR_DMA_015 SWSR_DMA_016 SWSR_DMA_018 SWSR_DMA_019
 *                      SWSR_DMA_049 SWSR_DMA_053 SW_SM001 SW_SM006
 *******************************************************************************************************/
extern Std_ReturnType Dma_InitConfigChannel(Dma_DeviceConfigType *config);
/** *****************************************************************************************************
 * \brief This function servce to update MAD crc, valid only in cyclic and DMA_MAD_CRC mode.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Dma_UpdateCyclicCRC
 *                      (
 *                          const Dma_ChannelConfigType * const channel
 *                      )
 *
 * Service ID[hex]    : 0x11
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : *channel - Pointer to a selected channel configuration structure.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: CRC upeate successfully.
 *                      DMA_E_UNINIT: DMA driver is not initialized.
 *                      DMA_E_PARAM_POINTER: Pointer is NULL_PTR.
 *                      DMA_E_TIMEOUT: Unexpect recalculating CRC error occurred.
 *
 * Description        : If you are using DMA_CYCLIC transaction mode and DMA_TRANSFER_MODE_LINKLIST
 *                      transferMode mode and enable DMA_MAD_CRC, when transfer launch to the last node,
 *                      you must recalculating CRC values of all link list nodes.
 * \endverbatim
 * Traceability       : None.
 *******************************************************************************************************/
extern Std_ReturnType Dma_UpdateCyclicCRC(const Dma_ChannelConfigType *const channel);
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF0Irq0Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF0Irq0Handler);
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF0Irq1Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF0Irq1Handler);
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF0Irq2Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF0Irq2Handler);
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF0Irq3Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF0Irq3Handler);
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF0Irq4Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF0Irq4Handler);
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF0Irq5Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF0Irq5Handler);
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF0Irq6Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF0Irq6Handler);
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF0Irq7Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF0Irq7Handler);
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF0Irq8Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF0Irq8Handler);
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF0Irq9Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF0Irq9Handler);
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF0Irq10Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF0Irq10Handler);
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF0Irq11Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF0Irq11Handler);
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF0Irq12Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF0Irq12Handler);
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF0Irq13Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF0Irq13Handler);
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF0Irq14Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF0Irq14Handler);
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF0Irq15Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF0Irq15Handler);
#ifndef SEMIDRIVE_E3_LITE_SERIES
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF0Irq16Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF0Irq16Handler);
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF0Irq17Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF0Irq17Handler);
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF0Irq18Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF0Irq18Handler);
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF0Irq19Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF0Irq19Handler);
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF0Irq20Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF0Irq20Handler);
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF0Irq21Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF0Irq21Handler);
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF0Irq22Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF0Irq22Handler);
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF0Irq23Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF0Irq23Handler);
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES */
#if (STD_OFF == DMA_LOCK_STEP_MODE)
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF1Irq0Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF1Irq0Handler);
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF1Irq1Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF1Irq1Handler);
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF1Irq2Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF1Irq2Handler);
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF1Irq3Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF1Irq3Handler);
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF1Irq4Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF1Irq4Handler);
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF1Irq5Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF1Irq5Handler);
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF1Irq6Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF1Irq6Handler);
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF1Irq7Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF1Irq7Handler);
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF1Irq8Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF1Irq8Handler);
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF1Irq9Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF1Irq9Handler);
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF1Irq10Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF1Irq10Handler);
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF1Irq11Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF1Irq11Handler);
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF1Irq12Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF1Irq12Handler);
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF1Irq13Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF1Irq13Handler);
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF1Irq14Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF1Irq14Handler);
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF1Irq15Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF1Irq15Handler);
#ifndef SEMIDRIVE_E3_LITE_SERIES
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF1Irq16Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF1Irq16Handler);
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF1Irq17Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF1Irq17Handler);
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF1Irq18Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF1Irq18Handler);
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF1Irq19Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF1Irq19Handler);
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF1Irq20Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF1Irq20Handler);
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF1Irq21Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF1Irq21Handler);
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF1Irq22Handler
 *                      (
 *                          void
 *                      )                                                                               *
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF1Irq22Handler);
/** ****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void Dma_SF1Irq23Handler
 *                      (
 *                          void
 *                      )
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
 * Description        : Service to irq handler.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051
 *******************************************************************************************************/
ISR(Dma_SF1Irq23Handler);
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES */
#endif /** #if (STD_OFF == DMA_LOCK_STEP_MODE) */
#if (DMA_GETVERSIONINFO_API == STD_ON)
/** *****************************************************************************************************
 * \brief This function service to return module version info.
 *
 * \verbatim
 * Syntax             : void Dma_GetVersionInfo
 *                      (
 *                          Std_VersionInfoType versionInfo
 *                      )
 *
 * Service ID[hex]    : 0x10
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : versioninfo - Pointer to where to store the version information of this module.
 *
 * Return value       : None
 *
 * Description        : This function returns the version information of this module
 *                      The version information include : Module ID, Vendor ID.
 *                      Vendor specific version numbers.
 *   -                  This function is available if the DMA_VERSION_INFO_API is set STD_ON
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_017 SWSR_DMA_019 SWSR_DMA_038 SWSR_DMA_049 SW_SM001 SW_SM006
 *******************************************************************************************************/
extern void Dma_GetVersionInfo(Std_VersionInfoType *versionInfo);
#endif /** #if (DMA_GETVERSIONINFO_API == STD_ON) */
#define DMA_STOP_SEC_CODE
#include "Dma_MemMap.h"
/** @} */
/** @} */

#ifdef __cplusplus
}
#endif
#endif /* #ifndef DMA_H_ */
/* End of file */
