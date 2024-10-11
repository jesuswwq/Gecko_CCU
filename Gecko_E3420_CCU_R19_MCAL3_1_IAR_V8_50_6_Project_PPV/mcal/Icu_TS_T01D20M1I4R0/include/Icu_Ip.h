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
 * \file     Icu_Ip.h                                                                                   *
 * \brief    This file mainly contains the definition of register operation                             *
 *           interface and data calculation interface                                                   *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/21     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef ICU_IP_H
#define ICU_IP_H

#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/

/* icu configuration file */
/** Traceability       : SWSR_ICU_001 */
#include "Icu_Cfg.h"
/* icu data types file */
#include "Icu_Types.h"
/* compiler macro file */
#include "Compiler.h"
#if (STD_ON == ICU_DMA_SUPPORT)
/* dma driver file */
#include "Dma.h"
#endif/* STD_ON == ICU_DMA_SUPPORT */
/********************************************************************************************************
 *                                         Macro definition                                             *
 *******************************************************************************************************/

/* etimer module base address macro */
#define APBMUX_ETMR4_BASE               (0xF04F0000UL)
#define APBMUX_ETMR3_BASE               (0xF04E0000UL)
#define APBMUX_ETMR2_BASE               (0xF04D0000UL)
#define APBMUX_ETMR1_BASE               (0xF04C0000UL)

/* etimer hardware information */
#ifndef SEMIDRIVE_E3_LITE_SERIES
#define TIMER_MODULE_NUMBER             (0x04U)
#define APBMUX_SCR_SF_BASE              (0xF0680000UL)
#else /* SEMIDRIVE_E3_LITE_SERIES */
#define TIMER_MODULE_NUMBER             (0x02U)
#define APBMUX_SCR_SF_BASE              (0xf08b0000UL)
#endif /* SEMIDRIVE_E3_LITE_SERIES */
#define LOCAL_CHANNEL_NUMBER            (0x04U)
/* multi capture hardware information */
#define MULTI_CPT_MODULE_NUM            (0x02U)
#define MULTI_CPT_MAX_IO_NUM            (0x20U)

/* multi capture dma channel information */
#define MULT_CPT_DMA_CHAN_NUM          (0x02U)
#define MULT_CPT_CHAN_B_INDEX          (0x00U)
#define MULT_CPT_CHAN_C_INDEX          (0x01U)

/* prevent hardware ifinite loop */
/* max upd effective time 2*(24MHz/0xFFFF = 0.3k) = 8ms, the time out must
    bigger than this value */
#define ICU_POLLING_TIME_OUT            (10000000U)

/* cache line aligned macro */
#define ICU_CONFIG_ARCH_CACHE_LINE      (32U)

/********************************************************************************************************
 *                                      GLobal variables                                                *
 *******************************************************************************************************/

/* physical to logic channel mapping */
extern uint8 Icu_PhyToLogMap[TIMER_MODULE_NUMBER][LOCAL_CHANNEL_NUMBER];

#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
/* the activation edge for sub-channel */
extern Icu_ActivationType Icu_MulEdgeSelect[MULTI_CPT_MODULE_NUM][MULTI_CPT_MAX_IO_NUM];
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */

#if (STD_ON == ICU_DMA_SUPPORT)
/* the destination buffer of dma transfer data */
extern uint32 Icu_ChanRxBuffer[NUM_OF_CHANNEL][(ICU_RX_BURST_LEN * 2U)]
                                                        LOCATE_ALIGNED(ICU_CONFIG_ARCH_CACHE_LINE);
#endif /* STD_ON == ICU_DMA_SUPPORT */

#if (STD_ON == ICU_MULTI_CAPTURE_DMA_MODE)
/* the destination buffer of channel B */
extern uint32 Icu_MulChanbBuffer[MULTI_CPT_MODULE_NUM][MULTI_CPT_BURST_LEN * 2U]
                                                        LOCATE_ALIGNED(ICU_CONFIG_ARCH_CACHE_LINE);
/* the destination buffer of channel C */
extern uint32 Icu_MulChancBuffer[MULTI_CPT_MODULE_NUM][MULTI_CPT_BURST_LEN * 2U]
                                                        LOCATE_ALIGNED(ICU_CONFIG_ARCH_CACHE_LINE);
#endif /* STD_ON == ICU_MULTI_CAPTURE_DMA_MODE */

/********************************************************************************************************
 *                                         Function definition                                          *
 *******************************************************************************************************/

#if (STD_ON == ICU_DMA_SUPPORT)
/** *****************************************************************************************************
 * \brief Interrupt handler function for timestamp mode when using dma in single
 *        capture mode
 *
 * \verbatim
 * Syntax             : void Icu_DmaIrqHandler(Dma_ControllerStatusType dmaTransSta, void* arg)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : dmaTransSta - dma trandfer date status
 *                      arg  - dma channel information
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Interrupt handler function for timestamp mode when using
 *                      dma in single capture mode
 * \endverbatim
 * Traceability       : SWSR_ICU_205
 *******************************************************************************************************/
extern void Icu_DmaIrqHandler(Dma_ControllerStatusType dmaTransSta, void* arg);
#endif /* STD_ON == ICU_DMA_SUPPORT */

#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT && STD_ON == ICU_MULTI_CAPTURE_DMA_MODE)
/** *****************************************************************************************************
 * \brief Interrupt handler function when using dma in multi capture mode
 *
 * \verbatim
 * Syntax             : void Icu_MultiCptDmaIrqHandler(Dma_ControllerStatusType dmaTransSta,
 *                                                     void* arg)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : dmaTransSta - dma trandfer date status
 *                      arg  - dma channel information
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Interrupt handler function when using dma in multi
 *                      capture mode
 * \endverbatim
 * Traceability       : SWSR_ICU_205 SWSR_ICU_206
 *******************************************************************************************************/
extern void Icu_MultiCptDmaIrqHandler(Dma_ControllerStatusType dmaTransSta, void* arg);
#endif /* STD_ON == ICU_MULTI_CAPTURE_DMA_MODE */

/** *****************************************************************************************************
 * \brief This function initializes the channel and set the etimer hardware
 *        registers
 *
 * \verbatim
 * Syntax             : Std_ReturnType Icu_Ip_ChannelInit(
 *                              const Icu_ChannelConfigType* channelConfigPtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : channelConfigPtr - pointer to icu channel configuration
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The setting result
 *
 * Description        : This function initializes the channel and set the etimer
 *                      hardware registers
 * \endverbatim
 * Traceability       : SWSR_ICU_034 SWSR_ICU_035 SWSR_ICU_037
 *                      SW_SM006
 *******************************************************************************************************/
Std_ReturnType Icu_Ip_ChannelInit(const Icu_ChannelConfigType* channelConfigPtr);

#if (STD_ON == ICU_DEINIT_API)
/** *****************************************************************************************************
 * \brief This function de-initializes the channel and set the etimer hardware
 *        registers
 *
 * \verbatim
 * Syntax             : Std_ReturnType Icu_Ip_ChannelDeInit(
 *                              const Icu_ChannelConfigType* channelConfigPtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : channelConfigPtr - pointer to icu channel configuration
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The setting result
 *
 * Description        : This function de-initializes the channel and set the
 *                      etimer hardware registers
 * \endverbatim
 * Traceability       : SWSR_ICU_045 SWSR_ICU_046 SWSR_ICU_047
 *                      SW_SM006
 *******************************************************************************************************/
Std_ReturnType Icu_Ip_ChannelDeInit(const Icu_ChannelConfigType* channelConfigPtr);
#endif /* STD_ON == ICU_DEINIT_API */

/** *****************************************************************************************************
 * \brief This function sets the active edge information
 *
 * \verbatim
 * Syntax             : Std_ReturnType Icu_Ip_SetActivationCondition(
 *                          const Icu_HwChannelConfigType*hwChannelConfigPtr,
 *                          Icu_ActivationType activation)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : hwChannelConfigPtr - pointer to hardware channel
 *                                           configuration
 *                      activation - activation edge information
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The setting result
 *
 * Description        : This function sets the active edge information
 * \endverbatim
 * Traceability       : SWSR_ICU_055
 *                      SW_SM006
 *******************************************************************************************************/
Std_ReturnType Icu_Ip_SetActivationCondition(const Icu_HwChannelConfigType*hwChannelConfigPtr, Icu_ActivationType activation);

/** *****************************************************************************************************
 * \brief This function gets the interrupt status
 *
 * \verbatim
 * Syntax             : uint32 Icu_Ip_GetInterrupt(Icu_HwModule tmrModule)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The interrupt status
 *
 * Description        : This function gets the interrupt status
 * \endverbatim
 * Traceability       : SWSR_ICU_190
 *******************************************************************************************************/
uint32 Icu_Ip_GetInterrupt(Icu_HwModule tmrModule);

/** *****************************************************************************************************
 * \brief This function clear the interrupt status
 *
 * \verbatim
 * Syntax             : Std_ReturnType Icu_Ip_ClearInterrupt(
 *                              Icu_HwModule tmrModule, Icu_HwChannel hwChannel)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module
 *                      hwChannel - etimer hardware channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The setting result
 *
 * Description        : This function clear the interrupt status
 * \endverbatim
 * Traceability       : SWSR_ICU_190
 *                      SW_SM006
 *******************************************************************************************************/
Std_ReturnType Icu_Ip_ClearInterrupt(Icu_HwModule tmrModule, Icu_HwChannel hwChannel);

/** *****************************************************************************************************
 * \brief This function gets the fifo status
 *
 * \verbatim
 * Syntax             : boolean Icu_Ip_CheckFifoSta(
 *                              Icu_HwModule tmrModule,Icu_HwChannel hwChannel)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module
 *                      hwChannel - etimer hardware channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The fifo status
 *
 * Description        : This function gets the fifo status
 * \endverbatim
 * Traceability       : SWSR_ICU_190
 *******************************************************************************************************/
boolean Icu_Ip_CheckFifoSta(Icu_HwModule tmrModule,Icu_HwChannel hwChannel);

/** *****************************************************************************************************
 * \brief This function turn on the capture channel
 *
 * \verbatim
 * Syntax             : Std_ReturnType Icu_Ip_TurnOnCapture(
 *                                  Icu_HwModule tmrModule,
 *                                  Icu_HwChannel hwChannel,
 *                                  boolean dmaSupport)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module
 *                      hwChannel - etimer hardware channel
 *                      dmaSupport - whether to use the dma mode
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The setting result
 *
 * Description        : This function turn on the capture channel
 * \endverbatim
 * Traceability       : SW_SM006
 *******************************************************************************************************/
Std_ReturnType Icu_Ip_TurnOnCapture(Icu_HwModule tmrModule, Icu_HwChannel hwChannel, boolean dmaSupport);

/** *****************************************************************************************************
 * \brief This function turn off the capture channel
 *
 * \verbatim
 * Syntax             : Std_ReturnType Icu_Ip_TurnOffCapture(
 *                              Icu_HwModule tmrModule, Icu_HwChannel hwChannel,
 *                              boolean dmaSupport)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module
 *                      hwChannel - etimer hardware channel
 *                      dmaSupport - whether to use the dma mode
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The setting result
 *
 * Description        : This function turn off the capture channel
 * \endverbatim
 * Traceability       : SW_SM006
 *******************************************************************************************************/
Std_ReturnType Icu_Ip_TurnOffCapture(Icu_HwModule tmrModule, Icu_HwChannel hwChannel, boolean dmaSupport);

/** *****************************************************************************************************
 * \brief This function gets the fifo entry number
 *
 * \verbatim
 * Syntax             : uint8 Icu_Ip_GetFifoEntry(Icu_HwModule tmrModule,
 *                                                Icu_HwChannel hwChannel)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module
 *                      hwChannel - etimer hardware channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The fifo entry number
 *
 * Description        : This function gets the fifo entry number
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
uint8 Icu_Ip_GetFifoEntry(Icu_HwModule tmrModule, Icu_HwChannel hwChannel);

/** *****************************************************************************************************
 * \brief This function gets the fifo value
 *
 * \verbatim
 * Syntax             : uint8 Icu_Ip_GetFifoEntry(Icu_HwModule tmrModule,
 *                                                Icu_HwChannel hwChannel)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module
 *                      hwChannel - etimer hardware channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The fifo value
 *
 * Description        : This function gets the fifo value
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
uint32 Icu_Ip_GetFifoVal(Icu_HwModule tmrModule, Icu_HwChannel hwChannel);

#if (STD_ON == ICU_GET_INPUTSTATE_API)
/** *****************************************************************************************************
 * \brief This function gets input status
 *
 * \verbatim
 * Syntax             : Icu_InputStateType Icu_Ip_GetInputState(
 *                              Icu_HwModule tmrModule, Icu_HwChannel hwChannel)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module
 *                      hwChannel - etimer hardware channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The input status in sigmeasurement mode
 *
 * Description        : This function gets input status
 * \endverbatim
 * Traceability       : SWSR_ICU_069 SWSR_ICU_071 SWSR_ICU_072 SWSR_ICU_073
 *******************************************************************************************************/
Icu_InputStateType Icu_Ip_GetInputState(Icu_HwModule tmrModule, Icu_HwChannel hwChannel);
#endif /* STD_ON == ICU_GET_INPUTSTATE_API */

#if (STD_ON == ICU_SIGNALMEASUREMENT_API)
/** *****************************************************************************************************
 * \brief This function starts capture in signal measurement mode
 *
 * \verbatim
 * Syntax             : Std_ReturnType Icu_Ip_StartSignalMeasurement(
 *                              const Icu_ChannelConfigType* channelConfigPtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : channelConfigPtr - pointer to icu channel configuration
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The setting result
 *
 * Description        : This function starts capture in signal measurement mode
 * \endverbatim
 * Traceability       : SWSR_ICU_153 SWSR_ICU_155
 *                      SW_SM006
 *******************************************************************************************************/
Std_ReturnType Icu_Ip_StartSignalMeasurement(const Icu_ChannelConfigType* channelConfigPtr);

/** *****************************************************************************************************
 * \brief This function stops capture in signal measurement mode
 *
 * \verbatim
 * Syntax             : Std_ReturnType Icu_Ip_StopSignalMeasurement(
 *                              const Icu_ChannelConfigType* channelConfigPtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : channelConfigPtr - pointer to icu channel configuration
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The setting result
 *
 * Description        : This function stops capture in signal measurement mode
 * \endverbatim
 * Traceability       : SWSR_ICU_161
 *                      SW_SM006
 *******************************************************************************************************/
Std_ReturnType Icu_Ip_StopSignalMeasurement(const Icu_ChannelConfigType* channelConfigPtr);

/** *****************************************************************************************************
 * \brief This function calculates the signal time in sigmeasurement mode
 *
 * \verbatim
 * Syntax             : void Icu_Ip_SigMeasurementIrq(
 *                              const Icu_ChannelConfigType* channelConfigPtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : channelConfigPtr - pointer to icu channel configuration
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function calculates the signal time in
 *                      sigmeasurement mode
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
void Icu_Ip_SigMeasurementIrq(const Icu_ChannelConfigType* channelConfigPtr);

#if (STD_ON == ICU_GET_TIMEELAPSED_API)
/** *****************************************************************************************************
 * \brief This function gets signal time in signal measurement mode
 *
 * \verbatim
 * Syntax             : Icu_ValueType Icu_Ip_GetTimeElapsed(
 *                              Icu_HwModule tmrModule, Icu_HwChannel hwChannel)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module
 *                      hwChannel - etimer hardware channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The signal time value
 *
 * Description        : This function gets signal time in signal measurement
 *                      mode
 * \endverbatim
 * Traceability       : SWSR_ICU_168 SWSR_ICU_169 SWSR_ICU_170 SWSR_ICU_171
 *                      SWSR_ICU_172 SWSR_ICU_173
 *******************************************************************************************************/
Icu_ValueType Icu_Ip_GetTimeElapsed(Icu_HwModule tmrModule, Icu_HwChannel hwChannel);
#endif /* STD_ON == ICU_GET_TIMEELAPSED_API */

#if (STD_ON == ICU_GET_DUTYCYCLE_VALUES_API)
/** *****************************************************************************************************
 * \brief This function gets dutycycle value in signal measurement mode
 *
 * \verbatim
 * Syntax             : Std_ReturnType Icu_Ip_GetDutyCycle(
 *                              Icu_HwModule tmrModule, Icu_HwChannel hwChannel,
 *                              Icu_DutyCycleType* dutyCyclePtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module
 *                      hwChannel - etimer hardware channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : dutyCyclePtr - pointer to a buffer where the results
 *
 * Return value       : The result status
 *
 * Description        : This function gets dutycycle value in signal measurement
 *                      mode
 * \endverbatim
 * Traceability       : SWSR_ICU_180 SWSR_ICU_181 SWSR_ICU_182 SWSR_ICU_183
 *                      SW_SM006
 *******************************************************************************************************/
Std_ReturnType Icu_Ip_GetDutyCycle(Icu_HwModule tmrModule, Icu_HwChannel hwChannel, Icu_DutyCycleType* dutyCyclePtr);
#endif /* STD_ON == ICU_GET_DUTYCYCLE_VALUES_API */
#endif /* STD_ON == ICU_SIGNALMEASUREMENT_API */

#if (STD_ON == ICU_DMA_SUPPORT)
/** *****************************************************************************************************
 * \brief This function setup dma channel information
 *
 * \verbatim
 * Syntax             : boolean Icu_Ip_SetupDma(
 *                              const Icu_ChannelConfigType* channelConfigPtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : channelConfigPtr - pointer to icu channel configuration
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The setting result
 *
 * Description        : This function setup dma channel information
 * \endverbatim
 * Traceability       : SWSR_ICU_205
 *******************************************************************************************************/
boolean Icu_Ip_SetupDma(const Icu_ChannelConfigType* channelConfigPtr);

/** *****************************************************************************************************
 * \brief This function free dma channel information
 *
 * \verbatim
 * Syntax             : Std_ReturnType Icu_Ip_FreeDma(uint8 logicChannel)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : logicChannel - logic channel index
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The setting result
 *
 * Description        : This function free dma channel information
 * \endverbatim
 * Traceability       : SW_SM006
 *******************************************************************************************************/
Std_ReturnType Icu_Ip_FreeDma(uint8 logicChannel);

#endif /* STD_ON == ICU_DMA_SUPPORT */

#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
/** *****************************************************************************************************
 * \brief This function initilized icu channel in multi capture mode
 *
 * \verbatim
 * Syntax             : Std_ReturnType Icu_Ip_MultiCptChannelInit(
 *                              const Icu_ChannelConfigType* channelConfigPtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : channelConfigPtr - pointer to icu channel configuration
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The setting result
 *
 * Description        : This function initilized icu channel in multi capture
 *                      mode
 * \endverbatim
 * Traceability       : SWSR_ICU_034 SWSR_ICU_035 SWSR_ICU_037
 *                      SW_SM006
 *******************************************************************************************************/
Std_ReturnType Icu_Ip_MultiCptChannelInit(const Icu_ChannelConfigType* channelConfigPtr);

#if (STD_ON == ICU_DEINIT_API)
/** *****************************************************************************************************
 * \brief This function de-initilized icu channel in multi capture mode
 *
 * \verbatim
 * Syntax             : Std_ReturnType Icu_Ip_MultiCptChannelDeInit(
 *                              const Icu_ChannelConfigType* channelConfigPtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : channelConfigPtr - pointer to icu channel configuration
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The setting result
 *
 * Description        : This function de-initilized icu channel in multi capture
 *                      mode
 * \endverbatim
 * Traceability       : SWSR_ICU_034 SWSR_ICU_035 SWSR_ICU_037
 *                      SW_SM006
 *******************************************************************************************************/
Std_ReturnType Icu_Ip_MultiCptChannelDeInit(const Icu_ChannelConfigType* channelConfigPtr);
#endif /* STD_ON == ICU_DEINIT_API */

/** *****************************************************************************************************
 * \brief This function turns on etimer capture in multi capture mode
 *
 * \verbatim
 * Syntax             : Std_ReturnType Icu_Ip_MultiCptTurnOnCapture(
 *                                      Icu_HwModule tmrModule, boolean intMode)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module
 *                      intMode - check if etimer uses interrupt mode
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The setting result
 *
 * Description        : This function turns on etimer capture in multi capture
 *                      mode
 * \endverbatim
 * Traceability       : SW_SM006
 *******************************************************************************************************/
Std_ReturnType Icu_Ip_MultiCptTurnOnCapture(Icu_HwModule tmrModule, boolean intMode);

/** *****************************************************************************************************
 * \brief This function turns off etimer capture in multi capture mode
 *
 * \verbatim
 * Syntax             : Std_ReturnType Icu_Ip_MultiCptTurnOffCapture(
 *                                      Icu_HwModule tmrModule, boolean intMode)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module
 *                      intMode - check if etimer uses interrupt mode
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The setting result
 *
 * Description        : This function turns off etimer capture in multi capture
 *                      mode
 * \endverbatim
 * Traceability       : SW_SM006
 *******************************************************************************************************/
Std_ReturnType Icu_Ip_MultiCptTurnOffCapture(Icu_HwModule tmrModule, boolean intMode);

#if (STD_ON == ICU_SIGNALMEASUREMENT_API)
/** *****************************************************************************************************
 * \brief This function starts capture signal time in multi capture mode
 *
 * \verbatim
 * Syntax             : Std_ReturnType Icu_Ip_MultiCptStartSignalMeasurement(
 *                                        Icu_HwModule tmrModule, uint8 ioChan)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module
 *                      ioChan - sub channel index in multi capture mode
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The setting result
 *
 * Description        : This function starts capture signal time in multi
 *                      capture mode
 * \endverbatim
 * Traceability       : SWSR_ICU_153 SWSR_ICU_155
 *                      SW_SM006
 *******************************************************************************************************/
Std_ReturnType Icu_Ip_MultiCptStartSignalMeasurement(Icu_HwModule tmrModule, uint8 ioChan);

/** *****************************************************************************************************
 * \brief This function starts capture signal time in multi capture mode
 *
 * \verbatim
 * Syntax             : Std_ReturnType Icu_Ip_MultiCptStopSignalMeasurement(
 *                                        Icu_HwModule tmrModule, uint8 ioChan)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module
 *                      ioChan - sub channel index in multi capture mode
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The setting result
 *
 * Description        : This function starts capture signal time in multi
 *                      capture mode
 * \endverbatim
 * Traceability       : SWSR_ICU_161
 *                      SW_SM006
 *******************************************************************************************************/
Std_ReturnType Icu_Ip_MultiCptStopSignalMeasurement(Icu_HwModule tmrModule, uint8 ioChan);

/** *****************************************************************************************************
 * \brief This function calculates the signal time in multi capture mode
 *
 * \verbatim
 * Syntax             : boolean Icu_Ip_MultiCptSigMeasurementIrq(
 *                             Icu_HwModule tmrModule, uint8 ioChan,
 *                             Icu_SignalMeasurementPropertyType sigMeasureType,
 *                             Icu_MultiCptEdgeChangeType edgeChange,
 *                              uint32 timeSpend)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module
 *                      ioChan - sub channel index in multi capture mode
 *                      sigMeasureType - sub mode of sigmeasurement mode
 *                      edgeChange - edge change type
 *                      timeSpend - time information of the level last
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The calculate result
 *
 * Description        : This function calculates the signal time in multi
 *                      capture mode
 * \endverbatim
 * Traceability       : SWSR_ICU_206
 *******************************************************************************************************/
boolean Icu_Ip_MultiCptSigMeasurementIrq(Icu_HwModule tmrModule, uint8 ioChan, Icu_SignalMeasurementPropertyType sigMeasureType, Icu_MultiCptEdgeChangeType edgeChange, uint32 timeSpend);

#if (STD_ON == ICU_GET_TIMEELAPSED_API)
/** *****************************************************************************************************
 * \brief This function gets signal time in multi capture mode
 *
 * \verbatim
 * Syntax             : Icu_ValueType  Icu_Ip_MultiCptGetTimeElapsed(
 *                                      Icu_HwModule tmrModule, uint8 ioChan)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module
 *                      ioChan - sub channel index in multi capture mode
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The signal time value
 *
 * Description        : This function gets signal time in multi capture mode
 * \endverbatim
 * Traceability       : SWSR_ICU_168 SWSR_ICU_169 SWSR_ICU_170 SWSR_ICU_171
 *                      SWSR_ICU_172 SWSR_ICU_173
 *******************************************************************************************************/
Icu_ValueType  Icu_Ip_MultiCptGetTimeElapsed(Icu_HwModule tmrModule, uint8 ioChan);
#endif /* STD_ON == ICU_GET_TIMEELAPSED_API */

#if (STD_ON == ICU_GET_DUTYCYCLE_VALUES_API)
/** *****************************************************************************************************
 * \brief This function gets dutycycle value in multi capture mode
 *
 * \verbatim
 * Syntax             : Std_ReturnType Icu_Ip_MultiCptGetDutyCycle(
 *                                      Icu_HwModule tmrModule, uint8 ioChan,
 *                                      Icu_DutyCycleType* dutyCyclePtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module
 *                      ioChan - sub channel index in multi capture mode
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : dutyCyclePtr - pointer to duty cycle information buffer
 *
 * Return value       : The setting result
 *
 * Description        : This function gets dutycycle value in in multi capture
 *                      mode
 * \endverbatim
 * Traceability       : SWSR_ICU_180 SWSR_ICU_181 SWSR_ICU_182 SWSR_ICU_183
 *                      SW_SM006
 *******************************************************************************************************/
Std_ReturnType Icu_Ip_MultiCptGetDutyCycle(Icu_HwModule tmrModule, uint8 ioChan, Icu_DutyCycleType* dutyCyclePtr);
#endif /* STD_ON == ICU_GET_DUTYCYCLE_VALUES_API */
#endif /* STD_ON == ICU_SIGNALMEASUREMENT_API */
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */

#ifdef __cplusplus
}
#endif

#endif /* ICU_IP_H */
/* End of file */
