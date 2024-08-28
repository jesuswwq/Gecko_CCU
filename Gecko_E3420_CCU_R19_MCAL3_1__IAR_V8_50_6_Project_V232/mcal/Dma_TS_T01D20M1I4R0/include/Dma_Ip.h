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
 *  \file     Dma_IP.h                                                                                  *
 *  \brief    This file contains interface header for DMA ip MCAL driver.                               *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/18     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifndef DMA_IP_H
#define DMA_IP_H

#ifdef __cplusplus
extern "C" {
#endif
/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Dma_Types.h"
/** Traceability       : SWSR_DMA_001 */
#include "Dma_Cfg.h"
/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/
#ifndef SEMIDRIVE_E3_LITE_SERIES
/** \brief  DMA controller SF0 base address. */
#define DMA_SF0_BASE                                                    (0xf0500000U)
/** \brief  DMA controller SF1 base address. */
#define DMA_SF1_BASE                                                    (0xf0540000U)
#else
/** \brief  DMA controller SF0 base address. */
#define DMA_SF0_BASE                                                    (0xf0970000U)
/** \brief  DMA controller SF1 base address. */
#define DMA_SF1_BASE                                                    (0xf09b0000U)
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES */

#define DMA_TYPE_L31                                                    (3U)
/********************************************************************************************************
 *                                  Global Types definition                                             *
 *******************************************************************************************************/
/** \brief  Dma system controller register signal, which is set dma lockstep mode. */
typedef struct
{
    uint8         domain;
    uint16        type;       /* signal type */
    uint16        startBit;
    uint16        width;
} Dma_ScrSignalType;

/********************************************************************************************************
 *                                  Global Variable Declarations                                        *
 *******************************************************************************************************/
/** \brief  Record the initialization status of the module on all cores. */
extern uint8 *const Dma_InitializeState[DMA_CPU_ID_MAX];
/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
#define DMA_START_SEC_CODE
#include "Dma_MemMap.h"
/** *****************************************************************************************************
 * \brief This function initialize DMA controller ip layer.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Dma_Ip_Init
 *                      (
 *                          const Dma_HwConfigType *config
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *681
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : *config      - Pointer to configuration set.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Get core variable successful.
 *                      DMA_E_CONFIG_POINTER: Config pointer is NULL_PTR.
 *                      DMA_E_PARAMS: Input parameter error.
 *
 * Description        : This function initialize DMA controller ip layer.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_004 SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_049 SW_SM006
 *******************************************************************************************************/
extern Std_ReturnType Dma_Ip_Init(const Dma_HwConfigType *config);
/** *****************************************************************************************************
 * \brief This function servce to request DMA controller channel.
 *
 * \verbatim
 * Syntax             : Dma_ChannelConfigType *Dma_Ip_ChannelRequest
 *                      (
 *                          Dma_HwControllerType controllerId
 *                          uint32 channelId
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : controllerId - Dma controller base address.
 *                      channelId    - Numeric identifier of the DMA controller.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : cptr: If request channel is successful, return the channel's configuration
 *                      pointer.
 *
 * Description        : Only request channel(s) that have been configured in EB. If request is
 *                      successful, the channel will be marked as allocated.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_049 SW_SM006
 *******************************************************************************************************/
extern Dma_ChannelConfigType *Dma_Ip_ChannelRequest(Dma_HwControllerType controllerId,
        uint32 channelId);
/** *****************************************************************************************************
 * \brief This function servce to release DMA controller channel.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Dma_Ip_ChannelFree
 *                      (
 *                          Dma_ChannelConfigType *channel
 *                      )
 *
 * Service ID[hex]    : None
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
 *                      DMA_E_PARAM_POINTER: Pointer is NULL_PTR.
 *
 * Description        : Release the DMA channel so that the new request can succeed, if the release
 *                      is successful, the channel status is set to unallocated.
 * \endverbatim
 * Traceability       : SWSR_DMA_049 SW_SM007 SW_SM006
 *******************************************************************************************************/
extern Std_ReturnType Dma_Ip_ChannelFree(Dma_ChannelConfigType *channel);
/** *****************************************************************************************************
 * \brief This function servce to set configuration pointer to an initial value.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Dma_Ip_DeviceConfig
 *                      (
 *                          const Dma_ChannelConfigType * const channel
 *                          const Dma_DeviceConfigType * const config
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : *channel - Pointer to a selected channel configuration structure.
 *                      *config  - Pointer to a user configuration parameters.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Copy configuration parameters successful.
 *                      DMA_E_PARAM_POINTER: Pointer is NULL_PTR.
 *
 * Description        : Copy DMA register configuration parameters to selected channel.
 * \endverbatim
 * Traceability       : SWSR_DMA_006 SWSR_DMA_007 SWSR_DMA_008 SWSR_DMA_009 SWSR_DMA_010 SWSR_DMA_011
 *                      SWSR_DMA_012 SWSR_DMA_014 SWSR_DMA_016 SWSR_DMA_049 SW_SM007 SW_SM006
 *******************************************************************************************************/
extern Std_ReturnType Dma_Ip_DeviceConfig(const Dma_ChannelConfigType *const channel,
        const Dma_DeviceConfigType *const config);
/** *****************************************************************************************************
 * \brief This function servce to set channel register from user configuration parameters.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Dma_Ip_ConfigTransfer
 *                      (
 *                          const Dma_ChannelConfigType * const channel
 *                          uint32 length
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : *channel - Pointer to a selected channel configuration structure.
 *                      length   - Total transmit data length.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Check configuration parameters passed.
 *                      DMA_E_PARAMS: Input parameter error.
 *                      DMA_E_PARAM_POINTER: Pointer is NULL_PTR.
 *
 * Description        : Set channel register from user configuration parameters.
 * \endverbatim
 * Traceability       : SWSR_DMA_006 SWSR_DMA_007 SWSR_DMA_008 SWSR_DMA_009 SWSR_DMA_010 SWSR_DMA_011
 *                      SWSR_DMA_012 SWSR_DMA_013 SWSR_DMA_014 SWSR_DMA_015 SWSR_DMA_016 SWSR_DMA_020
 *                      SWSR_DMA_049 SW_SM007 SW_SM006
 *******************************************************************************************************/
extern Std_ReturnType Dma_Ip_ConfigTransfer(const Dma_ChannelConfigType *const channel,
        uint32 length);
/** *****************************************************************************************************
 * \brief This function service to start transmit data on the DMA channel.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Dma_Ip_ChannelEnable
 *                      (
 *                          const Dma_ChannelConfigType * const channel
 *                      )
 *
 * Service ID[hex]    : None
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
 * Return value       : E_OK: Check configuration parameters passed.
 *                      DMA_E_PARAM_POINTER: Pointer is NULL_PTR.
 *
 * Description        : Enable current DMA channel transfer. If current configuration is memory to/from
 *                      memory or memory to peripheral will start the transfer immediately, if current
 *                      configuration is peripheral to memory need to wait for hardware request.
 * \endverbatim
 * Traceability       : SWSR_DMA_049 SW_SM007 SW_SM006
 *******************************************************************************************************/
extern Std_ReturnType Dma_Ip_ChannelEnable(const Dma_ChannelConfigType *const channel);
/** *****************************************************************************************************
 * \brief This function service to stop transmit data on the DMA channel.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Dma_Ip_ChannelDisable
 *                      (
 *                          const Dma_ChannelConfigType * const channel
 *                      )
 *
 * Service ID[hex]    : None
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
 * Return value       : E_OK: Check configuration parameters passed.
 *                      DMA_E_PARAM_POINTER: Pointer is NULL_PTR.
 *
 * Description        : Disable current DMA channel transfer.
 * \endverbatim
 * Traceability       : SWSR_DMA_049 SW_SM007 SW_SM006
 *******************************************************************************************************/
extern Std_ReturnType Dma_Ip_ChannelDisable(const Dma_ChannelConfigType *const channel);
/** *****************************************************************************************************
 * \brief This function service to returns the transmission status of the current channel0.
 *
 * \verbatim
 * Syntax             : Dma_ControllerStatusType Dma_Ip_GetChannelStatus
 *                      (
 *                          const Dma_ChannelConfigType * const channel
 *                      )
 *
 * Service ID[hex]    : None
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
 * Return value       : DMA_COMPLETED     : Current channel transmission completed.
 *                      DMA_IN_PROGRESS   : Current channel transmission in progress.
 *
 * Description        : This function support only updating the source address, destination address an0d
 *                      transmit data length registers.
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
extern Dma_ControllerStatusType Dma_Ip_GetChannelStatus(const Dma_ChannelConfigType *const channel);
/** *****************************************************************************************************
 * \brief This function service to get current channel total transfer length.
 *
 * \verbatim
 * Syntax             : uint32 Dma_Ip_GetXferNumber
 *                      (
 *                          uint32 dmaBaseAddress
 *                          uint32 channelId
 *                          uint8 clearFlag
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : dmabaseAddress - Dma controller base address.
 *                      channelId      - Numeric identifier of the DMA channel.
 *                      clearFlag      - Clear data transfer length register or not.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Return total transfer length.
 *
 * Description        : This function service to get current channel total transfer length.
 * \endverbatim
 * Traceability       : SWSR_DMA_048
 *******************************************************************************************************/
extern uint32 Dma_Ip_GetXferNumber(uint32 dmaBaseAddress, uint32 channelId, uint8 clearFlag);
#if (DMA_UPDATE_CONFIG_API == STD_ON)
/** *****************************************************************************************************
 * \brief This function service to update transmission address and length information.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Dma_Ip_UpdateTransmitAddressAndLength
 *                      (
 *                          const Dma_ChannelConfigType * const channel
 *                          const Dma_UpdateTransmissionType * const updateConfig
 *                          uint32 length
 *                      )
 *
 * Service ID[hex]    : None
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
 * Return value       : E_OK: Free link list node successful.
 *                      DMA_E_PARAMS: Input parameters error.
 *
 * Description        : This function support only updating the source address, destination address,
 *                      transmit data length and burst types registers. If you do not want to update
 *                      burst type, you can pass DMA_BURST_TYPE_UNDEFINED parameters to srcIncDirection
 *                      and dstIncDirection, and then ip layer function will bypass burst type
 *                      configuration.
 * \endverbatim
 * Traceability       : SWSR_DMA_015 SWSR_DMA_046 SWSR_DMA_049 SW_SM007 SW_SM006
 *******************************************************************************************************/
extern Std_ReturnType Dma_Ip_UpdateTransmitAddressAndLength(const Dma_ChannelConfigType *const
        channel, const Dma_UpdateTransmissionType *const updateConfig, uint32 length);
#endif /** #if (DMA_UPDATE_CONFIG_API == STD_ON) */
#if (DMA_CONFIG_CHECK_API == STD_ON)
/** *****************************************************************************************************
 * \brief This function service to check configuration parameters.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Dma_Ip_ConfigurationCheck
 *                      (
 *                          Dma_ChannelConfigType *channel
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : *channel   - Pointer to a selected channel configuration structure.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Configuration check successful.
 *                      E_NOT_OK: Configuration check failed.
 *                      DMA_E_PARAMS: Input parameters error.
 *                      DMA_E_PARAM_POINTER: DMA_E_PARAM_POINTER: Pointer is NULL_PTR.
 *
 * Description        : This function service to check configuration parameters.
 * \endverbatim
 * Traceability       : SWSR_DMA_049 SWSR_DMA_052 SW_SM006
 *******************************************************************************************************/
extern Std_ReturnType Dma_Ip_ConfigurationCheck(Dma_ChannelConfigType *channel);
#endif /** #if (DMA_CONFIG_CHECK_API == STD_ON) */
/** *****************************************************************************************************
 * \brief This function servce to update MAD crc, valid only in cyclic and DMA_MAD_CRC mode.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Dma_Ip_UpdateCyclicCRC
 *                      (
 *                          const Dma_ChannelConfigType * const channel
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : *channel   - Pointer to a selected channel configuration structure.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Configuration check successful.
 *                      DMA_E_PARAMS: Input parameters error.
 *                      DMA_E_PARAM_POINTER: DMA_E_PARAM_POINTER: Pointer is NULL_PTR.
 *                      DMA_E_TIMEOUT: Unexpect recalculating CRC error occurred.
 *
 * Description        : If you are using DMA_CYCLIC transaction mode and DMA_TRANSFER_MODE_LINKLIST
 *                      transferMode mode and enable DMA_MAD_CRC, when transfer launch to the last node,
 *                      you must recalculating CRC values of all link list nodes.
 * \endverbatim
 * Traceability       : SWSR_DMA_049 SWSR_DMA_054 SW_SM006
 *******************************************************************************************************/
extern Std_ReturnType Dma_Ip_UpdateCyclicCRC(const Dma_ChannelConfigType *const channel);
/** *****************************************************************************************************
 * \brief This function service to set DMA lockstep bit to soc system control register.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Dma_Ip_SocScrSetBit
 *                      (
 *                          const Dma_ScrSignalType * const signalPtr
 *                          uint32 value
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : *signalPtr - Pointer to a selected signal configuration.
 *                      value      - True or False.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Configuration check successful.
 *                      DMA_E_LOCKSTEP: Error due to set lockstep failed.
 *
 * Description        : This function service to set DMA lockstep bit to soc system control register.
 * \endverbatim
 * Traceability       : SWSR_DMA_005
 *******************************************************************************************************/
extern Std_ReturnType Dma_Ip_SocScrSetBit(const Dma_ScrSignalType *const signalPtr, uint32 value);
/** *****************************************************************************************************
 * \brief This function service to get core id.
 *
 * \verbatim
 * Syntax             : uint8 Dma_Ip_GetCoreId
 *                      (
 *                          Dma_ScrSignalType *signalPtr
 *                          uint32 value
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
 * Return value       : Return core id.
 *
 * Description        : This function service to get core id.
 * \endverbatim
 * Traceability       : SWSR_DMA_013
 *******************************************************************************************************/
extern uint8 Dma_Ip_GetCoreId(void);
/** *****************************************************************************************************
 * \brief This function service to dma controller SF0 interrupt service routine.
 *
 * \verbatim
 * Syntax             : voids Dma_Ip_SF0IrqHandler
 *                      (
 *                          uint32 channelId
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : channelId - Numeric identifier of the DMA channel.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function service to dma controller SF0 interrupt service routine.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004 SW_SM006
 *******************************************************************************************************/
extern void Dma_Ip_SF0IrqHandler(uint32 channelId);
#if (DMA_LOCK_STEP_MODE == STD_OFF)
/** *****************************************************************************************************
 * \brief This function service to dma controller SF1 interrupt service routine.
 *
 * \verbatim
 * Syntax             : void Dma_Ip_SF1IrqHandler
 *                      (
 *                          uint32 channelId
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : channelId - Numeric identifier of the DMA channel.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function service to dma controller SF1 interrupt service routine.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004 SW_SM006
 *******************************************************************************************************/
extern void Dma_Ip_SF1IrqHandler(uint32 channelId);
#endif /** #if (DMA_LOCK_STEP_MODE == STD_OFF) */
#define DMA_STOP_SEC_CODE

#ifdef __cplusplus
}
#endif

#include "Dma_MemMap.h"
#endif /* #ifndef DMA_IP_H_ */
/* End of file */
