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
 *  \file     Dma_Fault.h                                                                               *
 *  \brief    This file contains interface header for DMA Fault injection.                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/15     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef DMA_FAULT_H
#define DMA_FAULT_H

#ifdef __cplusplus
extern "C" {
#endif
/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/
/** \brief  DMA fault injection switch */

#ifndef DMA_FAULT_INJECTION
/** \brief  FUNCTION:Dma_Init() fault injection. */
#define DmaHookBegin_Dma_Init()
#define DmaHookEnd_Dma_Init()
/** \brief  FUNCTION:Dma_RequestChannelWithId() fault injection. */
#define DmaHookBegin_Dma_RequestChannelWithIdt()
#define DmaHookEnd_Dma_RequestChannelWithId()
/** \brief  FUNCTION:Dma_ReleaseChannel() fault injection. */
#define DmaHookBegin_Dma_ReleaseChannel()
#define DmaHookEnd_Dma_ReleaseChannel()
/** \brief  FUNCTION:Dma_ConfigChannel() fault injection. */
#define DmaHookBegin_Dma_ConfigChannel()
#define DmaHookEnd_Dma_ConfigChannel()
/** \brief  FUNCTION:Dma_PrepareTransmission() fault injection. */
#define DmaHookBegin_Dma_PrepareTransmission()
#define DmaHookEnd_Dma_PrepareTransmission()
/** \brief  FUNCTION:Dma_UpdateTransmitAddressAndLength() fault injection. */
#define DmaHookBegin_Dma_UpdateTransmitAddressAndLength()
#define DmaHookEnd_Dma_UpdateTransmitAddressAndLength()
/** \brief  FUNCTION:Dma_Start() fault injection. */
#define DmaHookBegin_Dma_Start()
#define DmaHookEnd_Dma_Start()
/** \brief  FUNCTION:Dma_Stop() fault injection. */
#define DmaHookBegin_Dma_Stop()
#define DmaHookEnd_Dma_Stop()
/** \brief  FUNCTION:Dma_GetChannelStatus() fault injection. */
#define DmaHookBegin_Dma_GetChannelStatus()
#define DmaHookEnd_Dma_GetChannelStatus()
/** \brief  FUNCTION:Dma_GetXferBytes() fault injection. */
#define DmaHookBegin_Dma_GetXferBytes()
#define DmaHookEnd_Dma_GetXferBytes()
/** \brief  FUNCTION:Dma_GetConfigParams() fault injection. */
#define DmaHookBegin_Dma_GetConfigParams()
#define DmaHookEnd_Dma_GetConfigParams()
/** \brief  FUNCTION:Dma_FlushCache() fault injection. */
#define DmaHookBegin_Dma_FlushCaches()
#define DmaHookEnd_Dma_FlushCache()
/** \brief  FUNCTION:Dma_InvalidateCache() fault injection. */
#define DmaHookBegin_Dma_InvalidateCache()
#define DmaHookEnd_Dma_InvalidateCache()
/** \brief  FUNCTION:Dma_CleanCache() fault injection. */
#define DmaHookBegin_Dma_CleanCache()
#define DmaHookEnd_Dma_CleanCache()
/** \brief  FUNCTION:Dma_ConfigurationCheck() fault injection. */
#define DmaHookBegin_Dma_ConfigurationCheck()
#define DmaHookEnd_Dma_ConfigurationCheck()
/** \brief  FUNCTION:Dma_InitConfigChannel() fault injection. */
#define DmaHookBegin_Dma_InitConfigChannel()
#define DmaHookEnd_Dma_InitConfigChannel()
/** \brief  FUNCTION:Dma_UpdateCyclicCRC() fault injection. */
#define DmaHookBegin_Dma_UpdateCyclicCRC()
#define DmaHookEnd_Dma_UpdateCyclicCRC()
/** \brief  FUNCTION:Dma_CheckAddressAndChannelValid() fault injection. */
#define DmaHookBegin_Dma_CheckAddressAndChannelValid()
#define DmaHookEnd_Dma_CheckAddressAndChannelValid()
/** \brief  FUNCTION:Dma_CheckRequestChannelValid() fault injection. */
#define DmaHookBegin_Dma_CheckRequestChannelValid()
#define DmaHookEnd_Dma_CheckRequestChannelValid()
/** \brief  FUNCTION:Dma_GetAdcModuleConfigParams() fault injection. */
#define DmaHookBegin_Dma_GetAdcModuleConfigParams()
#define DmaHookEnd_Dma_GetAdcModuleConfigParams()
/** \brief  FUNCTION:Dma_GetM2MModuleConfigParams() fault injection. */
#define DmaHookBegin_Dma_GetM2MModuleConfigParams()
#define DmaHookEnd_Dma_GetM2MModuleConfigParams()
/** \brief  FUNCTION:Dma_GetIcuModuleConfigParams() fault injection. */
#define DmaHookBegin_Dma_GetIcuModuleConfigParams()
#define DmaHookEnd_Dma_GetIcuModuleConfigParams()
/** \brief  FUNCTION:Dma_GetPwmModuleConfigParams() fault injection. */
#define DmaHookBegin_Dma_GetPwmModuleConfigParams()
#define DmaHookEnd_Dma_GetPwmModuleConfigParams()
/** \brief  FUNCTION:Dma_GetSpiModuleConfigParams() fault injection. */
#define DmaHookBegin_Dma_GetSpiModuleConfigParams()
#define DmaHookEnd_Dma_GetSpiModuleConfigParams()
/** \brief  FUNCTION:Dma_GetxSpiModuleConfigParams() fault injection. */
#define DmaHookBegin_Dma_GetxSpiModuleConfigParams()
#define DmaHookEnd_Dma_GetxSpiModuleConfigParams()
/** \brief  FUNCTION:Dma_GetXtrgModuleConfigParams() fault injection. */
#define DmaHookBegin_Dma_GetXtrgModuleConfigParams()
#define DmaHookEnd_Dma_GetXtrgModuleConfigParams()
/** \brief  FUNCTION:Dma_SetLockstepMode() fault injection. */
#define DmaHookBegin_Dma_SetLockstepMode()
#define DmaHookEnd_Dma_SetLockstepMode()
/** \brief  FUNCTION:Dma_Ip_SF0IrqHandler() fault injection. */
#define DmaHookBegin_Dma_Ip_SFIrqHandler()
#define DmaHookEnd_Dma_Ip_SFIrqHandler()
#define DmaHookBusError_Dma_Ip_SFIrqHandler()
#define DmaHookCRCError_Dma_Ip_SFIrqHandler()
#define DmaHookSYSError_Dma_Ip_SFIrqHandler()
#define DmaHookAbortError_Dma_Ip_SFIrqHandler()
#define DmaHookRegisterError_Dma_Ip_SFIrqHandler()
/** \brief  FUNCTION:Dma_Ip_ChannelDisable() fault injection. */
#define DmaHookTimeout_Dma_Ip_ChannelDisable()
/** \brief  FUNCTION:Dma_Ip_SetChannelCmd() fault injection. */
#define DmaHookTimeout_Dma_Ip_SetChannelCmd()
#else
#include "Dma_UserFault.h"
#endif /* #if (DMA_FAULT_INJECTION == STD_OFF) */

#ifdef __cplusplus
}
#endif

#endif /* DMA_FAULT_H */
/* End of file */
