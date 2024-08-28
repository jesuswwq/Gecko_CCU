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
 * \file     Dma.c                                                                                      *
 * \brief    This file contains DMA MCAL driver.                                                        *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/17     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Dma_Ip.h"
#include "Dma_ASM.h"
#include "Dma.h"
#if (DMA_DEV_ERROR_DETECT == STD_ON)
/** Traceability       : SWSR_DMA_002 */
/* Dma.c include Det.h */
#include "Det.h"
#endif /** #if (DMA_DEV_ERROR_DETECT == STD_ON) */
#if (DMA_SAFETY_ENABLE == STD_ON)
/** Traceability       : SWSR_DMA_003 */
/* Dma.c include FuSaMcalReportError.h */
#include "FuSaMcalReportError.h"
#endif /** #if (DMA_SAFETY_ENABLE == STD_ON) */
#include "Dma_Fault.h"
/********************************************************************************************************
 *                                 Imported Compiler Switch Checks                                      *
 *******************************************************************************************************/
#ifndef DMA_SW_MAJOR_VERSION
#error "DMA_SW_MAJOR_VERSION is not defined."
#endif

#ifndef DMA_SW_MINOR_VERSION
#error "DMA_SW_MINOR_VERSION is not defined."
#endif

#ifndef DMA_SW_PATCH_VERSION
#error "DMA_SW_PATCH_VERSION is not defined."
#endif

/* AUTOSAR Secification File Version Check */
#ifndef DMA_AR_RELEASE_MAJOR_VERSION
#error "DMA_AR_RELEASE_MAJOR_VERSION is not defined."
#endif

/* AUTOSAR Secification File Version Check */
#ifndef DMA_AR_RELEASE_MINOR_VERSION
#error "DMA_AR_RELEASE_MINOR_VERSION is not defined."
#endif

/* AUTOSAR Secification File Version Check */
#ifndef DMA_AR_RELEASE_REVISION_VERSION
#error "DMA_AR_RELEASE_REVISION_VERSION is not defined."
#endif

/** \brief  AUTOSAR Major and Minor release version check. */
#if(DMA_AR_RELEASE_MAJOR_VERSION != 4U)
#error "DMA_AR_RELEASE_MAJOR_VERSION does not match."
#endif

#if(DMA_AR_RELEASE_MINOR_VERSION != 3U)
#error "DMA_AR_RELEASE_MINOR_VERSION does not match."
#endif

#if(DMA_AR_RELEASE_REVISION_VERSION != 1U)
#error "DMA_AR_RELEASE_REVISION_VERSION does not match."
#endif
/********************************************************************************************************
 *                                 Private Macro definition                                             *
 *******************************************************************************************************/
/** \brief  Get module initialize state. */
/** Traceability       : SWSR_DMA_020 */
#define Dma_IsInitialized()                                             (DMA_INIT == (*Dma_InitializeState[Dma_Ip_GetCoreId()]))

/** \brief  Dummy error id state process. */
#define DMA_DUMMY_STATEMENT(state)                                      ((state) = (state))

/** \brief  E3 SF domain number ID. */
#define DMA_SF_DOMAIN                                                   (0U)

/** \brief  Dma lockstep bit position. */
#ifndef SEMIDRIVE_E3_LITE_SERIES
#define DMA_SF_DMA_SF_LOCK_STEP_EN_P                                    {DMA_SF_DOMAIN, DMA_TYPE_L31, 320U, 1U}
#else
#define DMA_SF_DMA_SF_LOCK_STEP_EN_P                                    {DMA_SF_DOMAIN, DMA_TYPE_L31, 64U, 1U}
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES */
/********************************************************************************************************
 *                                  Private Variable Definitions                                        *
 *******************************************************************************************************/
/** Traceability       : SWSR_DMA_013 SW_SM008 */
/* Support multicore and initialization states */
#define DMA_CORE0_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dma_MemMap.h"
/** \brief  Record the initialization state of the module on core0. */
DMA_LOCAL uint8 Dma_InitializeStateCore0 LOCATE_ALIGNED(DMA_CONFIG_ARCH_CACHE_LINE);
#define DMA_CORE0_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dma_MemMap.h"

#define DMA_CORE1_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dma_MemMap.h"
/** \brief  Record the initialization state of the module on core1. */
DMA_LOCAL uint8 Dma_InitializeStateCore1 LOCATE_ALIGNED(DMA_CONFIG_ARCH_CACHE_LINE);
#define DMA_CORE1_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dma_MemMap.h"

#define DMA_CORE2_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dma_MemMap.h"
/** \brief  Record the initialization state of the module on core2. */
DMA_LOCAL uint8 Dma_InitializeStateCore2 LOCATE_ALIGNED(DMA_CONFIG_ARCH_CACHE_LINE);
#define DMA_CORE2_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dma_MemMap.h"

#define DMA_CORE3_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dma_MemMap.h"
/** \brief  Record the initialization state of the module on core3. */
DMA_LOCAL uint8 Dma_InitializeStateCore3 LOCATE_ALIGNED(DMA_CONFIG_ARCH_CACHE_LINE);
#define DMA_CORE3_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dma_MemMap.h"

#define DMA_CORE4_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dma_MemMap.h"
/** \brief  Record the initialization state of the module on core4. */
DMA_LOCAL uint8 Dma_InitializeStateCore4 LOCATE_ALIGNED(DMA_CONFIG_ARCH_CACHE_LINE);
#define DMA_CORE4_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dma_MemMap.h"
/********************************************************************************************************
 *                                  Private Constant Definitions                                        *
 *******************************************************************************************************/
/** Traceability       : SWSR_DMA_013 SW_SM008 */
/* Support multicore and initialization states */
#if (DMA_NO_CACHEABLE_NEEDED == STD_ON)
#define DMA_START_SEC_VAR_NO_INIT_NO_CACHE_UNSPECIFIED
#else
#define DMA_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif /** #if (DMA_NO_CACHEABLE_NEEDED == STD_ON) */
#include "Dma_MemMap.h"
/** \brief  This is a pointer to the configuration of type const Dma_ConfigType. */
DMA_LOCAL const Dma_ConfigType *Dma_GlobalConfigPtr LOCATE_ALIGNED(DMA_CONFIG_ARCH_CACHE_LINE);
#if (DMA_NO_CACHEABLE_NEEDED == STD_ON)
#define DMA_STOP_SEC_VAR_NO_INIT_NO_CACHE_UNSPECIFIED
#else
#define DMA_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif /** #if (DMA_NO_CACHEABLE_NEEDED == STD_ON) */
#include "Dma_MemMap.h"
/********************************************************************************************************
 *                                  Global Variable Declarations                                        *
 *******************************************************************************************************/
/** Traceability       : SWSR_DMA_013 SW_SM008 */
/* Support multicore and initialization states */
#define DMA_START_SEC_CONST_UNSPECIFIED
#include "Dma_MemMap.h"
/** \brief  This is a pointer to all cores initialization states variables. */
uint8 *const Dma_InitializeState[DMA_CPU_ID_MAX] =
{
    &Dma_InitializeStateCore0,
    &Dma_InitializeStateCore1,
    &Dma_InitializeStateCore2,
    &Dma_InitializeStateCore3,
    &Dma_InitializeStateCore4,
};

/** \brief  This is a lock-step signal. *//* PRQA S 3218 1 */
DMA_LOCAL const Dma_ScrSignalType Dma_LockstepSignal = DMA_SF_DMA_SF_LOCK_STEP_EN_P;
#define DMA_STOP_SEC_CONST_UNSPECIFIED
#include "Dma_MemMap.h"
/********************************************************************************************************
 *                                  Private Function Declarations                                       *
 *******************************************************************************************************/
#define DMA_START_SEC_CODE
#include "Dma_MemMap.h"
DMA_LOCAL Std_ReturnType Dma_GetAdcModuleConfigParams(Dma_PeripheralIdType peripheralId,
        Dma_SubIdType subId, Dma_InstanceConfigType *dmaConfig);
DMA_LOCAL Std_ReturnType Dma_GetM2MModuleConfigParams(Dma_PeripheralIdType peripheralId,
        Dma_SubIdType subId, Dma_InstanceConfigType *dmaConfig);
DMA_LOCAL Std_ReturnType Dma_GetIcuModuleConfigParams(Dma_PeripheralIdType peripheralId,
        Dma_SubIdType subId, Dma_InstanceConfigType *dmaConfig);
DMA_LOCAL Std_ReturnType Dma_GetPwmModuleConfigParams(Dma_PeripheralIdType peripheralId,
        Dma_SubIdType subId, Dma_InstanceConfigType *dmaConfig);
DMA_LOCAL Std_ReturnType Dma_GetSpiModuleConfigParams(Dma_PeripheralIdType peripheralId,
        Dma_SubIdType subId, Dma_InstanceConfigType *dmaConfig);
DMA_LOCAL Std_ReturnType Dma_GetxSpiModuleConfigParams(Dma_PeripheralIdType peripheralId,
        Dma_SubIdType subId, Dma_InstanceConfigType *dmaConfig);
DMA_LOCAL Std_ReturnType Dma_GetXtrgModuleConfigParams(Dma_PeripheralIdType peripheralId,
        Dma_SubIdType subId, Dma_InstanceConfigType *dmaConfig);
DMA_LOCAL Std_ReturnType Dma_CheckRequestChannelValid(Dma_HwControllerType controllerId,
        uint32 channelId);
DMA_LOCAL Std_ReturnType Dma_CheckAddressAndChannelValid(uint32 address, uint32 channelId);
DMA_LOCAL Std_ReturnType Dma_SetLockstepMode(void);
/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
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
void Dma_Init(const Dma_ConfigType *configPtr)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId;
    uint8 coreId;

    DmaHookBegin_Dma_Init();

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check module states */
    if (Dma_IsInitialized())
    {
        errorId = DMA_E_INIT;
    }
    /* #20 Check input parameters for plausibility */
    else if (NULL_PTR == configPtr)
    {
        errorId = DMA_E_CONFIG_POINTER;
    }
    else
    {
        /* ----- Implementation ----------------------------------------------- */
        coreId = Dma_Ip_GetCoreId();
        /* #30 Enable DMA lockstep mode or not depend on EB configuration */
        errorId = Dma_SetLockstepMode();

        if ((Std_ReturnType)E_OK == errorId)
        {
            /* #40 Initialize DMA hardware unit */
            errorId = Dma_Ip_Init(&configPtr->configTableSF0[coreId]);
        } /* else not needed */

#if (DMA_LOCK_STEP_MODE == STD_OFF)

        if ((Std_ReturnType)E_OK == errorId)
        {
            /* #50 Once lockstep is enabled, SF1 controller will not be accessible */
            errorId = Dma_Ip_Init(&configPtr->configTableSF1[coreId]);
        } /* else not needed */

#endif /** #if (DMA_LOCK_STEP_MODE == STD_OFF) */

        if ((Std_ReturnType)E_OK == errorId)
        {
            /* #60 Set module state to initialized */
            (*Dma_InitializeState[coreId]) = DMA_INIT;

            /* #70 Only set value on CORE0. */
            if (NULL_PTR == Dma_GlobalConfigPtr)
            {
                Dma_GlobalConfigPtr = configPtr;
#if (DMA_NO_CACHEABLE_NEEDED == STD_OFF)
                /* PRQA S 0314 1 */
                Dma_CleanCacheRange((const void *)&Dma_GlobalConfigPtr, sizeof(Dma_GlobalConfigPtr));
#endif /** #if (DMA_NO_CACHEABLE_NEEDED == STD_OFF) */
            } /* else not needed */
        } /* else not needed */
    }

    /* ----- Development Error Report --------------------------------------- */
#if ((DMA_DEV_ERROR_DETECT == STD_ON) || (DMA_SAFETY_ENABLE == STD_ON))

    /* #80 Report default errors if any occurred */
    if ((Std_ReturnType)E_OK != errorId)
    {
#if (DMA_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(DMA_MODULE_ID, DMA_INSTANCE_ID, DMA_INIT_ID, errorId);
#endif /** #if (DMA_DEV_ERROR_DETECT == STD_ON) */
#if (DMA_SAFETY_ENABLE == STD_ON)
        (void)FuSaMcal_ReportError(DMA_MODULE_ID, DMA_INSTANCE_ID, DMA_INIT_ID, errorId);
#endif /** #if (DMA_SAFETY_ENABLE == STD_ON) */
    }

#else
    /* #90 Dummy assignment avoid compiler warning */
    DMA_DUMMY_STATEMENT(errorId);
#endif /** #if ((DMA_DEV_ERROR_DETECT == STD_ON) || (DMA_SAFETY_ENABLE == STD_ON)) */
    DmaHookEnd_Dma_Init();
}
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
 * Parameters (in)    : controllerId - Numeric identifier of the DMA controller.
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
Dma_ChannelConfigType *Dma_RequestChannelWithId(Dma_HwControllerType controllerId, uint32 channelId)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId = (Std_ReturnType)E_OK;
    Dma_ChannelConfigType *channel = NULL_PTR;

    DmaHookBegin_Dma_RequestChannelWithIdt();

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check module states */
    if (!Dma_IsInitialized())
    {
        errorId = DMA_E_UNINIT;
    }
    /* #20 Check input parameters for plausibility */
    else if ((Std_ReturnType)E_OK != Dma_CheckRequestChannelValid(controllerId, channelId))
    {
        errorId = DMA_E_PARAMS;
    }
    else
    {
        /* ----- Implementation ----------------------------------------------- */
        /* #30 Request the dma channel to prepare for following transmit */
        channel = Dma_Ip_ChannelRequest(controllerId, channelId);

        if (NULL_PTR == channel)
        {
            errorId = DMA_E_ALLOCATED;
        } /* else not needed */
    }

    /* ----- Development Error Report --------------------------------------- */
#if ((DMA_DEV_ERROR_DETECT == STD_ON) || (DMA_SAFETY_ENABLE == STD_ON))

    /* #40 Report default errors if any occurred */
    if ((Std_ReturnType)E_OK != errorId)
    {
#if (DMA_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(DMA_MODULE_ID, DMA_INSTANCE_ID, DMA_REQUEST_CHANNEL_ID, errorId);
#endif /** #if (DMA_DEV_ERROR_DETECT == STD_ON) */
#if (DMA_SAFETY_ENABLE == STD_ON)
        (void)FuSaMcal_ReportError(DMA_MODULE_ID, DMA_INSTANCE_ID, DMA_REQUEST_CHANNEL_ID, errorId);
#endif /** #if (DMA_SAFETY_ENABLE == STD_ON) */
    }

#else
    /* #50 Dummy assignment avoid compiler warning */
    DMA_DUMMY_STATEMENT(errorId);
#endif /** #if ((DMA_DEV_ERROR_DETECT == STD_ON) || (DMA_SAFETY_ENABLE == STD_ON)) */

    DmaHookEnd_Dma_RequestChannelWithId();
    return channel;
}
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
Std_ReturnType Dma_ReleaseChannel(Dma_ChannelConfigType *channel)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId;

    DmaHookBegin_Dma_ReleaseChannel();

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check initial state */
    if (!Dma_IsInitialized())
    {
        errorId = DMA_E_UNINIT;
    }
    /* #20 Check input parameters for plausibility */
    else if (NULL_PTR == channel)
    {
        errorId = DMA_E_PARAM_POINTER;
    }
    else
    {
        /* ----- Implementation ----------------------------------------------- */
        /* #30 Release the dma channel immediately, the linklist container and alocate flag will be cleared */
        errorId = Dma_Ip_ChannelFree(channel);
    }

    /* ----- Development Error Report --------------------------------------- */
#if ((DMA_DEV_ERROR_DETECT == STD_ON) || (DMA_SAFETY_ENABLE == STD_ON))

    /* #40 Report default errors if any occurred */
    if ((Std_ReturnType)E_OK != errorId)
    {
#if (DMA_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(DMA_MODULE_ID, DMA_INSTANCE_ID, DMA_RELEASE_CHANNEL_ID, errorId);
#endif /** #if (DMA_DEV_ERROR_DETECT == STD_ON) */
#if (DMA_SAFETY_ENABLE == STD_ON)
        (void)FuSaMcal_ReportError(DMA_MODULE_ID, DMA_INSTANCE_ID, DMA_RELEASE_CHANNEL_ID, errorId);
#endif /** #if (DMA_SAFETY_ENABLE == STD_ON) */
    }

#else
    /* #50 Dummy assignment avoid compiler warning */
    DMA_DUMMY_STATEMENT(errorId);
#endif /** #if ((DMA_DEV_ERROR_DETECT == STD_ON) || (DMA_SAFETY_ENABLE == STD_ON)) */

    DmaHookEnd_Dma_ReleaseChannel();
    return errorId;
}
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
Std_ReturnType Dma_ConfigChannel(const Dma_ChannelConfigType *const channel,
                                 const Dma_DeviceConfigType *const config)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId;

    DmaHookBegin_Dma_ConfigChannel();

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check module states */
    if (!Dma_IsInitialized())
    {
        errorId = DMA_E_UNINIT;
    }
    /* #20 Check input parameters for plausibility */
    else if ((NULL_PTR == channel) || (NULL_PTR == config))
    {
        errorId = DMA_E_PARAM_POINTER;
    }
    else
    {
        /* ----- Implementation ----------------------------------------------- */
        /* #30 Copy configuration parameters to channel container */
        errorId = Dma_Ip_DeviceConfig(channel, config);
    }

    /* ----- Development Error Report --------------------------------------- */
#if ((DMA_DEV_ERROR_DETECT == STD_ON) || (DMA_SAFETY_ENABLE == STD_ON))

    /* #40 Report default errors if any occurred */
    if ((Std_ReturnType)E_OK != errorId)
    {
#if (DMA_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(DMA_MODULE_ID, DMA_INSTANCE_ID, DMA_CONFIG_CHANNEL_ID, errorId);
#endif /** #if (DMA_DEV_ERROR_DETECT == STD_ON) */
#if (DMA_SAFETY_ENABLE == STD_ON)
        (void)FuSaMcal_ReportError(DMA_MODULE_ID, DMA_INSTANCE_ID, DMA_CONFIG_CHANNEL_ID, errorId);
#endif /** #if (DMA_SAFETY_ENABLE == STD_ON) */
    }

#else
    /* #50 Dummy assignment avoid compiler warning */
    DMA_DUMMY_STATEMENT(errorId);
#endif /** #if ((DMA_DEV_ERROR_DETECT == STD_ON) || (DMA_SAFETY_ENABLE == STD_ON)) */

    DmaHookEnd_Dma_ConfigChannel();
    return errorId;
}
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
Std_ReturnType Dma_PrepareTransmission(const Dma_ChannelConfigType *const channel,
                                       uint32 bufferLength)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId;

    DmaHookBegin_Dma_PrepareTransmission();

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check module states */
    if (!Dma_IsInitialized())
    {
        errorId = DMA_E_UNINIT;
    }
    /* #20 Check input parameters for plausibility */
    else if (NULL_PTR == channel)
    {
        errorId = DMA_E_PARAM_POINTER;
    }
    else if (0U == bufferLength)
    {
        errorId = DMA_E_PARAMS;
    }
    else
    {
        /* ----- Implementation ----------------------------------------------- */
        /* #30 Configuring parameters for dma channel registers for following data transfer */
        errorId = Dma_Ip_ConfigTransfer(channel, bufferLength);
    }

    /* ----- Development Error Report --------------------------------------- */
#if ((DMA_DEV_ERROR_DETECT == STD_ON) || (DMA_SAFETY_ENABLE == STD_ON))

    /* #40 Report default errors if any occurred */
    if ((Std_ReturnType)E_OK != errorId)
    {
#if (DMA_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(DMA_MODULE_ID, DMA_INSTANCE_ID, DMA_PREPARE_TRANSMISSION_ID, errorId);
#endif /** #if (DMA_DEV_ERROR_DETECT == STD_ON) */
#if (DMA_SAFETY_ENABLE == STD_ON)
        (void)FuSaMcal_ReportError(DMA_MODULE_ID, DMA_INSTANCE_ID, DMA_PREPARE_TRANSMISSION_ID, errorId);
#endif /** #if (DMA_SAFETY_ENABLE == STD_ON) */
    }

#else
    /* #50 Dummy assignment avoid compiler warning */
    DMA_DUMMY_STATEMENT(errorId);
#endif /** #if ((DMA_DEV_ERROR_DETECT == STD_ON) || (DMA_SAFETY_ENABLE == STD_ON)) */

    DmaHookEnd_Dma_PrepareTransmission();
    return errorId;
}
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
Std_ReturnType Dma_UpdateTransmitAddressAndLength(const Dma_ChannelConfigType *const channel,
        const Dma_UpdateTransmissionType *const updateConfig, uint32 length)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId;

    DmaHookBegin_Dma_UpdateTransmitAddressAndLength();

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check module states */
    if (!Dma_IsInitialized())
    {
        errorId = DMA_E_UNINIT;
    }
    /* #20 Check input parameters for plausibility */
    else if ((NULL_PTR == channel) || (NULL_PTR == updateConfig))
    {
        errorId = DMA_E_PARAM_POINTER;
    }
    else if (0U == length)
    {
        errorId = DMA_E_PARAMS;
    }
    else if ((updateConfig->srcIncDirection > DMA_BURST_FIXED)
             || (updateConfig->dstIncDirection > DMA_BURST_FIXED))
    {
        errorId = DMA_E_PARAMS;
    }
    else if ((updateConfig->srcBusWidth > DMA_BEAT_SIZE_8_BYTE)
             || (updateConfig->dstBusWidth > DMA_BEAT_SIZE_8_BYTE))
    {
        errorId = DMA_E_PARAMS;
    }
    else
    {
        /* ----- Implementation ----------------------------------------------- */
        /* #30 Only updating the source address, destination address, transmit data length and burst types registers */
        errorId = Dma_Ip_UpdateTransmitAddressAndLength(channel, updateConfig, length);
    }

    /* ----- Development Error Report --------------------------------------- */
#if ((DMA_DEV_ERROR_DETECT == STD_ON) || (DMA_SAFETY_ENABLE == STD_ON))

    /* #40 Report default errors if any occurred */
    if ((Std_ReturnType)E_OK != errorId)
    {
#if (DMA_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(DMA_MODULE_ID, DMA_INSTANCE_ID, DMA_UPDATE_ADDRESS_LENGTH_ID, errorId);
#endif /** #if (DMA_DEV_ERROR_DETECT == STD_ON) */
#if (DMA_SAFETY_ENABLE == STD_ON)
        (void)FuSaMcal_ReportError(DMA_MODULE_ID, DMA_INSTANCE_ID, DMA_UPDATE_ADDRESS_LENGTH_ID, errorId);
#endif /** #if (DMA_SAFETY_ENABLE == STD_ON) */
    }

#else
    /* #50 Dummy assignment avoid compiler warning */
    DMA_DUMMY_STATEMENT(errorId);
#endif /** #if ((DMA_DEV_ERROR_DETECT == STD_ON) || (DMA_SAFETY_ENABLE == STD_ON)) */

    DmaHookEnd_Dma_UpdateTransmitAddressAndLength();
    return errorId;
}
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
Std_ReturnType Dma_Start(const Dma_ChannelConfigType *const channel)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId;

    DmaHookBegin_Dma_Start();

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check module states */
    if (!Dma_IsInitialized())
    {
        errorId = DMA_E_UNINIT;
    }
    /* #20 Check input parameters for plausibility */
    else if (NULL_PTR == channel)
    {
        errorId = DMA_E_PARAM_POINTER;
    }
    else if ((Std_ReturnType)E_OK != Dma_CheckAddressAndChannelValid(channel->device->dmaBaseAddress,
             channel->channelId))
    {
        errorId = DMA_E_PARAMS;
    }
    else
    {
        /* ----- Implementation ----------------------------------------------- */
        /* #30 Start DMA transmission after completing configuration parameters */
        errorId = Dma_Ip_ChannelEnable(channel);
    }

    /* ----- Development Error Report --------------------------------------- */
#if ((DMA_DEV_ERROR_DETECT == STD_ON) || (DMA_SAFETY_ENABLE == STD_ON))

    /* #40 Report default errors if any occurred */
    if ((Std_ReturnType)E_OK != errorId)
    {
#if (DMA_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(DMA_MODULE_ID, DMA_INSTANCE_ID, DMA_START_ID, errorId);
#endif /** #if (DMA_DEV_ERROR_DETECT == STD_ON) */
#if (DMA_SAFETY_ENABLE == STD_ON)
        (void)FuSaMcal_ReportError(DMA_MODULE_ID, DMA_INSTANCE_ID, DMA_START_ID, errorId);
#endif /** #if (DMA_SAFETY_ENABLE == STD_ON) */
    }

#else
    /* #50 Dummy assignment avoid compiler warning */
    DMA_DUMMY_STATEMENT(errorId);
#endif /** #if ((DMA_DEV_ERROR_DETECT == STD_ON) || (DMA_SAFETY_ENABLE == STD_ON)) */

    DmaHookEnd_Dma_Start();
    return errorId;
}
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
Std_ReturnType Dma_Stop(const Dma_ChannelConfigType *const channel)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId;

    DmaHookBegin_Dma_Stop();

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check module states */
    if (!Dma_IsInitialized())
    {
        errorId = DMA_E_UNINIT;
    }
    /* #20 Check input parameters for plausibility */
    else if (NULL_PTR == channel)
    {
        errorId = DMA_E_PARAM_POINTER;
    }
    else if ((Std_ReturnType)E_OK != Dma_CheckAddressAndChannelValid(channel->device->dmaBaseAddress,
             channel->channelId))
    {
        errorId = DMA_E_PARAMS;
    }
    else
    {
        /* ----- Implementation ----------------------------------------------- */
        /* #30 Stop the dma channel immediately, even if the transmission is ongoing */
        errorId = Dma_Ip_ChannelDisable(channel);
    }

    /* ----- Development Error Report --------------------------------------- */
#if ((DMA_DEV_ERROR_DETECT == STD_ON) || (DMA_SAFETY_ENABLE == STD_ON))

    /* #40 Report default errors if any occurred */
    if ((Std_ReturnType)E_OK != errorId)
    {
#if (DMA_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(DMA_MODULE_ID, DMA_INSTANCE_ID, DMA_STOP_ID, errorId);
#endif /** #if (DMA_DEV_ERROR_DETECT == STD_ON) */
#if (DMA_SAFETY_ENABLE == STD_ON)
        (void)FuSaMcal_ReportError(DMA_MODULE_ID, DMA_INSTANCE_ID, DMA_STOP_ID, errorId);
#endif /** #if (DMA_SAFETY_ENABLE == STD_ON) */
    }

#else
    /* #50 Dummy assignment avoid compiler warning */
    DMA_DUMMY_STATEMENT(errorId);
#endif /** #if ((DMA_DEV_ERROR_DETECT == STD_ON) || (DMA_SAFETY_ENABLE == STD_ON)) */

    DmaHookEnd_Dma_Stop();
    return errorId;
}
/** *****************************************************************************************************
 * \brief This function service to returns the transmission status of the current channel.
 *
 * \verbati0m
 * Syntax             : Dma_ControllerStatusType Dma_GetChannelStatus
 *                      (
 *                          const Dma_ChannelConfigType * const channel
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
Dma_ControllerStatusType Dma_GetChannelStatus(const Dma_ChannelConfigType *const channel)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId = (Std_ReturnType)E_OK;
    Dma_ControllerStatusType status = DMA_ERR;

    DmaHookBegin_Dma_GetChannelStatus();

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check module states */
    if (!Dma_IsInitialized())
    {
        errorId = DMA_E_UNINIT;
    }
    /* #20 Check input parameters for plausibility */
    else if (NULL_PTR == channel)
    {
        errorId = DMA_E_PARAM_POINTER;
    }
    else if ((Std_ReturnType)E_OK != Dma_CheckAddressAndChannelValid(channel->device->dmaBaseAddress,
             channel->channelId))
    {
        errorId = DMA_E_PARAMS;
    }
    else
    {
        /* ----- Implementation ----------------------------------------------- */
        /* #30 Get DMA channel transmission status from register */
        status = Dma_Ip_GetChannelStatus(channel);
    }

    /* ----- Development Error Report --------------------------------------- */
#if ((DMA_DEV_ERROR_DETECT == STD_ON) || (DMA_SAFETY_ENABLE == STD_ON))

    /* #40 Report default errors if any occurred */
    if ((Std_ReturnType)E_OK != errorId)
    {
#if (DMA_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(DMA_MODULE_ID, DMA_INSTANCE_ID, DMA_GET_CHANNEL_STATUS_ID, errorId);
#endif /** #if (DMA_DEV_ERROR_DETECT == STD_ON) */
#if (DMA_SAFETY_ENABLE == STD_ON)
        (void)FuSaMcal_ReportError(DMA_MODULE_ID, DMA_INSTANCE_ID, DMA_GET_CHANNEL_STATUS_ID, errorId);
#endif /** #if (DMA_SAFETY_ENABLE == STD_ON) */
    }

#else
    /* #50 Dummy assignment avoid compiler warning */
    DMA_DUMMY_STATEMENT(errorId);
#endif /** #if ((DMA_DEV_ERROR_DETECT == STD_ON) || (DMA_SAFETY_ENABLE == STD_ON)) */

    DmaHookEnd_Dma_GetChannelStatus();
    return status;
}
/** *****************************************************************************************************
 * \brief This function service to get current channel total data length.
 *
 * \verbatim
 * Syntax             : uint32 Dma_GetXferBytes
 *                      (
 *                          const Dma_ChannelConfigType *channel
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
uint32 Dma_GetXferBytes(const Dma_ChannelConfigType *channel, uint8 clearFlag)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId = (Std_ReturnType)E_OK;
    uint32 length = 0U;

    DmaHookBegin_Dma_GetXferBytes();

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check module states */
    if (!Dma_IsInitialized())
    {
        errorId = DMA_E_UNINIT;
    }
    /* #20 Check input parameters for plausibility */
    else if (NULL_PTR == channel)
    {
        errorId = DMA_E_PARAM_POINTER;
    }
    else if ((Std_ReturnType)E_OK != Dma_CheckAddressAndChannelValid(channel->device->dmaBaseAddress,
             channel->channelId))
    {
        errorId = DMA_E_PARAMS;
    }
    else
    {
        /* ----- Implementation ----------------------------------------------- */
        /* #30 Get the data length of a single DMA transmission and whether to clear the transfer length register value */
        length = Dma_Ip_GetXferNumber(channel->device->dmaBaseAddress, channel->channelId, clearFlag);
    }

    /* ----- Development Error Report --------------------------------------- */
#if ((DMA_DEV_ERROR_DETECT == STD_ON) || (DMA_SAFETY_ENABLE == STD_ON))

    /* #40 Report default errors if any occurred */
    if ((Std_ReturnType)E_OK != errorId)
    {
#if (DMA_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(DMA_MODULE_ID, DMA_INSTANCE_ID, DMA_GET_XFER_BYTES_ID, errorId);
#endif /** #if (DMA_DEV_ERROR_DETECT == STD_ON) */
#if (DMA_SAFETY_ENABLE == STD_ON)
        (void)FuSaMcal_ReportError(DMA_MODULE_ID, DMA_INSTANCE_ID, DMA_GET_XFER_BYTES_ID, errorId);
#endif /** #if (DMA_SAFETY_ENABLE == STD_ON) */
    }

#else
    /* #50 Dummy assignment avoid compiler warning */
    DMA_DUMMY_STATEMENT(errorId);
#endif /** #if ((DMA_DEV_ERROR_DETECT == STD_ON) || (DMA_SAFETY_ENABLE == STD_ON)) */

    DmaHookEnd_Dma_GetXferBytes();
    return length;
}
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
 *                                     ...etc.
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
Std_ReturnType Dma_GetConfigParams(Dma_PeripheralIdType peripheralId, Dma_SubIdType subId,
                                   Dma_ModuleType moduleId, Dma_InstanceConfigType *dmaConfig)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId;

    DmaHookBegin_Dma_GetConfigParams();

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check module states */
    if (!Dma_IsInitialized())
    {
        errorId = DMA_E_UNINIT;
    }
    /* #20 Check input parameters for plausibility */
    else if (subId >= DMA_SUB_ID_UNDEFINE)
    {
        errorId = DMA_E_PARAM_SUB_ID;
    }
    else if (moduleId >= DMA_MODULE_UNDEFINE)
    {
        errorId = DMA_E_PARAM_MODULE_ID;
    }
    else if (NULL_PTR == dmaConfig)
    {
        errorId = DMA_E_PARAM_POINTER;
    }
    else
    {
        /* ----- Implementation ----------------------------------------------- */
        /* #30 Get the configuration information of different peripherals, such as DMA hardware unit, channel number and which core it is assigned to. */
        switch (moduleId)
        {
        case DMA_MODULE_ADC:
        {
            errorId = Dma_GetAdcModuleConfigParams(peripheralId, subId, dmaConfig);
            break;
        }

        case DMA_MODULE_ETIMER:
        {
            errorId = Dma_GetIcuModuleConfigParams(peripheralId, subId, dmaConfig);
            break;
        }

        case DMA_MODULE_PWM:
        {
            errorId = Dma_GetPwmModuleConfigParams(peripheralId, subId, dmaConfig);
            break;
        }

        case DMA_MODULE_SPI:
        {
            errorId = Dma_GetSpiModuleConfigParams(peripheralId, subId, dmaConfig);
            break;
        }

        case DMA_MODULE_XSPI:
        {
            errorId = Dma_GetxSpiModuleConfigParams(peripheralId, subId, dmaConfig);
            break;
        }

        case DMA_MODULE_MEM:
        {
            errorId = Dma_GetM2MModuleConfigParams(peripheralId, subId, dmaConfig);
            break;
        }

        case DMA_MODULE_XTRG:
        {
            errorId = Dma_GetXtrgModuleConfigParams(peripheralId, subId, dmaConfig);
            break;
        }

        default:
        {
            /* #40 Module id is not valid, normally the code does not run to here */
            errorId = DMA_E_PARAM_MODULE_ID;
            break;
        }
        }
    }

    /* ----- Development Error Report --------------------------------------- */
#if ((DMA_DEV_ERROR_DETECT == STD_ON) || (DMA_SAFETY_ENABLE == STD_ON))

    /* #50 Report default errors if any occurred */
    if ((Std_ReturnType)E_OK != errorId)
    {
#if (DMA_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(DMA_MODULE_ID, DMA_INSTANCE_ID, DMA_GET_CONFIG_PARAMS_ID, errorId);
#endif /** #if (DMA_DEV_ERROR_DETECT == STD_ON) */
#if (DMA_SAFETY_ENABLE == STD_ON)
        (void)FuSaMcal_ReportError(DMA_MODULE_ID, DMA_INSTANCE_ID, DMA_GET_CONFIG_PARAMS_ID, errorId);
#endif /** #if (DMA_SAFETY_ENABLE == STD_ON) */
    }

#else
    /* #60 Dummy assignment avoid compiler warning */
    DMA_DUMMY_STATEMENT(errorId);
#endif /** #if ((DMA_DEV_ERROR_DETECT == STD_ON) || (DMA_SAFETY_ENABLE == STD_ON)) */

    DmaHookEnd_Dma_GetConfigParams();
    return errorId;
}
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
void Dma_FlushCache(uint32 address, uint32 size)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId = (Std_ReturnType)E_OK;

    DmaHookBegin_Dma_FlushCaches();

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check input parameters for plausibility */
    if (0U == size)
    {
        errorId = DMA_E_PARAMS;
    }
    else
    {
        /* ----- Implementation ----------------------------------------------- */
        /* #20 Flush cache with specified address and size *//* PRQA S 0326 1 */
        Dma_CleanInvalidateCacheRange((const void *)address, size);
    }

    /* ----- Development Error Report --------------------------------------- */
#if ((DMA_DEV_ERROR_DETECT == STD_ON) || (DMA_SAFETY_ENABLE == STD_ON))

    /* #30 Report default errors if any occurred */
    if ((Std_ReturnType)E_OK != errorId)
    {
#if (DMA_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(DMA_MODULE_ID, DMA_INSTANCE_ID, DMA_FLUSH_CACHE_ID, errorId);
#endif /** #if (DMA_DEV_ERROR_DETECT == STD_ON) */
#if (DMA_SAFETY_ENABLE == STD_ON)
        (void)FuSaMcal_ReportError(DMA_MODULE_ID, DMA_INSTANCE_ID, DMA_FLUSH_CACHE_ID, errorId);
#endif /** #if (DMA_SAFETY_ENABLE == STD_ON) */
    }

#else
    /* #40 Dummy assignment avoid compiler warning */
    DMA_DUMMY_STATEMENT(errorId);
#endif /** #if ((DMA_DEV_ERROR_DETECT == STD_ON) || (DMA_SAFETY_ENABLE == STD_ON)) */
    DmaHookEnd_Dma_FlushCache();
}
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
 * Traceability       : SWSR_DMA_018 SWSR_DMA_019 SWSR_DMA_040 SWSR_DMA_047 SWSR_DMA_049 SW_SM006
 *******************************************************************************************************/
void Dma_InvalidateCache(uint32 address, uint32 size)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId = (Std_ReturnType)E_OK;

    DmaHookBegin_Dma_InvalidateCache();

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check input parameters for plausibility */
    if (0U == size)
    {
        errorId = DMA_E_PARAMS;
    }
    else
    {
        /* ----- Implementation ----------------------------------------------- */
        /* #20 Invalidate cache with specified address and size *//* PRQA S 0326 1 */
        Dma_InvalidateCacheRange((const void *)address, size);
    }

    /* ----- Development Error Report --------------------------------------- */
#if ((DMA_DEV_ERROR_DETECT == STD_ON) || (DMA_SAFETY_ENABLE == STD_ON))

    /* #30 Report default errors if any occurred */
    if ((Std_ReturnType)E_OK != errorId)
    {
#if (DMA_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(DMA_MODULE_ID, DMA_INSTANCE_ID, DMA_INVALIDATE_ID, errorId);
#endif /** #if (DMA_DEV_ERROR_DETECT == STD_ON) */
#if (DMA_SAFETY_ENABLE == STD_ON)
        (void)FuSaMcal_ReportError(DMA_MODULE_ID, DMA_INSTANCE_ID, DMA_INVALIDATE_ID, errorId);
#endif /** #if (DMA_SAFETY_ENABLE == STD_ON) */
    }

#else
    /* #40 Dummy assignment avoid compiler warning */
    DMA_DUMMY_STATEMENT(errorId);
#endif /** #if ((DMA_DEV_ERROR_DETECT == STD_ON) || (DMA_SAFETY_ENABLE == STD_ON)) */
    DmaHookEnd_Dma_InvalidateCache();
}
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
 * Traceability       : SWSR_DMA_018 SWSR_DMA_019 SWSR_DMA_042 SWSR_DMA_047 SWSR_DMA_049 SW_SM006
 *******************************************************************************************************/
void Dma_CleanCache(uint32 address, uint32 size)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId = (Std_ReturnType)E_OK;

    DmaHookBegin_Dma_CleanCache();

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check input parameters for plausibility */
    if (0U == size)
    {
        errorId = DMA_E_PARAMS;
    }
    else
    {
        /* ----- Implementation ----------------------------------------------- */
        /* #20 Clean cache with specified address and size *//* PRQA S 0326 1 */
        Dma_CleanCacheRange((const void *)address, size);
    }

    /* ----- Development Error Report --------------------------------------- */
#if ((DMA_DEV_ERROR_DETECT == STD_ON) || (DMA_SAFETY_ENABLE == STD_ON))

    /* #30 Report default errors if any occurred */
    if ((Std_ReturnType)E_OK != errorId)
    {
#if (DMA_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(DMA_MODULE_ID, DMA_INSTANCE_ID, DMA_CLEAN_ID, errorId);
#endif /** #if (DMA_DEV_ERROR_DETECT == STD_ON) */
#if (DMA_SAFETY_ENABLE == STD_ON)
        (void)FuSaMcal_ReportError(DMA_MODULE_ID, DMA_INSTANCE_ID, DMA_CLEAN_ID, errorId);
#endif /** #if (DMA_SAFETY_ENABLE == STD_ON) */
    }

#else
    /* #40 Dummy assignment avoid compiler warning */
    DMA_DUMMY_STATEMENT(errorId);
#endif /** #if ((DMA_DEV_ERROR_DETECT == STD_ON) || (DMA_SAFETY_ENABLE == STD_ON)) */
    DmaHookEnd_Dma_CleanCache();
}

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
Std_ReturnType Dma_ConfigurationCheck(Dma_ChannelConfigType *channel)
{
    /* Check configuration parameter wether equal to register value, if equal will return OK, otherwise return NOT OK */
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId;

    DmaHookBegin_Dma_ConfigurationCheck();

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check module states */
    if (!Dma_IsInitialized())
    {
        errorId = DMA_E_UNINIT;
    }
    /* #20 Check input parameters for plausibility */
    else if (NULL_PTR == channel)
    {
        errorId = DMA_E_PARAM_POINTER;
    }
    else
    {
        /* ----- Implementation ----------------------------------------------- */
        /* #30 Checking the consistency of configuration and register values */
        errorId = Dma_Ip_ConfigurationCheck(channel);
    }

    /* ----- Development Error Report --------------------------------------- */
#if ((DMA_DEV_ERROR_DETECT == STD_ON) || (DMA_SAFETY_ENABLE == STD_ON))

    /* #40 Report default errors if any occurred */
    if ((Std_ReturnType)E_OK != errorId)
    {
#if (DMA_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(DMA_MODULE_ID, DMA_INSTANCE_ID, DMA_CONFIG_CHECK_ID, errorId);
#endif /** #if (DMA_DEV_ERROR_DETECT == STD_ON) */
#if (DMA_SAFETY_ENABLE == STD_ON)
        (void)FuSaMcal_ReportError(DMA_MODULE_ID, DMA_INSTANCE_ID, DMA_CONFIG_CHECK_ID, errorId);
#endif /** #if (DMA_SAFETY_ENABLE == STD_ON) */
    }

#else
    /* #50 Dummy assignment avoid compiler warning */
    DMA_DUMMY_STATEMENT(errorId);
#endif /** #if ((DMA_DEV_ERROR_DETECT == STD_ON) || (DMA_SAFETY_ENABLE == STD_ON)) */

    DmaHookEnd_Dma_ConfigurationCheck();
    return errorId;
}
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
Std_ReturnType Dma_InitConfigChannel(Dma_DeviceConfigType *config)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId = (Std_ReturnType)E_OK;

    DmaHookBegin_Dma_InitConfigChannel();

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check module states */
    if (!Dma_IsInitialized())
    {
        errorId = DMA_E_UNINIT;
    }
    /* #20 Check input parameters for plausibility */
    else if (NULL_PTR == config)
    {
        errorId = DMA_E_PARAM_POINTER;
    }
    else
    {
        /* ----- Implementation ----------------------------------------------- */
        /* #30 Set configuration parameters to default value */
        config->direction           = DMA_MEMORY_TO_MEMORY;
        config->memsetValue         = 0U;
        config->periodLength        = 0U;
        config->transaction         = DMA_MEMCPY;
        config->processMode         = DMA_POLLING;
        config->srcAddress          = 0x00UL;
        config->dstAddress          = 0x00UL;
        config->srcBusWidth         = DMA_BEAT_SIZE_1_BYTE;
        config->dstBusWidth         = DMA_BEAT_SIZE_1_BYTE;
        config->srcMaxBurst         = DMA_BURST_LENGTH_1;
        config->dstMaxBurst         = DMA_BURST_LENGTH_1;
        config->srcPortSelect       = DMA_PORT_AXI64;
        config->dstPortSelect       = DMA_PORT_AXI64;
        config->srcIncDirection     = DMA_BURST_INCREMENTAL;
        config->dstIncDirection     = DMA_BURST_INCREMENTAL;
        config->srcStrideEnable     = FALSE;
        config->dstStrideEnable     = FALSE;
        config->srcStridePol        = DMA_POSITIVE_OFFSET;
        config->dstStridePol        = DMA_POSITIVE_OFFSET;
        config->srcStrideSelect     = DMA_SCSTD;
        config->srcCoarseStride     = 0U;
        config->dstStrideSelect     = DMA_SCSTD;
        config->dstCoarseStride     = 0U;
        config->srcFineStride       = 0U;
        config->dstFineStride       = 0U;
        config->bufferMode          = DMA_SINGLE_BUFFER;
        config->loopMode            = DMA_LOOP_MODE_1;
        config->flowControl         = DMA_DIR_MEMORY_TO_MEMORY;
        config->transferMode        = DMA_TRANSFER_MODE_LINKLIST;
        config->linkListTriggerMode = DMA_TRIGGER_MODE_NOT_DEFINED;
        config->switchControl       = DMA_SWT_EVT_CTL_CONTINUE_WTH_INT;
        config->muxId               = 0xFFU;
        config->bufferSize          = 0x00UL;
        config->linkListAddress     = 0x00UL;
        config->firstMad            = FALSE;
        config->lastMad             = FALSE;
        config->srcCache            = FALSE;
        config->dstCache            = FALSE;
        config->customMuxIdFlag     = (boolean)FALSE;
        config->customMuxId         = 0U;
        config->madCrcMode          = DMA_NO_MAD_CRC;
    }

    /* ----- Development Error Report --------------------------------------- */
#if ((DMA_DEV_ERROR_DETECT == STD_ON) || (DMA_SAFETY_ENABLE == STD_ON))

    /* #40 Report default errors if any occurred */
    if ((Std_ReturnType)E_OK != errorId)
    {
#if (DMA_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(DMA_MODULE_ID, DMA_INSTANCE_ID, DMA_INIT_CONFIG_ID, errorId);
#endif /** #if (DMA_DEV_ERROR_DETECT == STD_ON) */
#if (DMA_SAFETY_ENABLE == STD_ON)
        (void)FuSaMcal_ReportError(DMA_MODULE_ID, DMA_INSTANCE_ID, DMA_INIT_CONFIG_ID, errorId);
#endif /** #if (DMA_SAFETY_ENABLE == STD_ON) */
    }

#else
    /* #50 Dummy assignment avoid compiler warning */
    DMA_DUMMY_STATEMENT(errorId);
#endif /** #if ((DMA_DEV_ERROR_DETECT == STD_ON) || (DMA_SAFETY_ENABLE == STD_ON)) */

    DmaHookEnd_Dma_InitConfigChannel();
    return errorId;
}
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
 * Traceability       : SWSR_DMA_008 SWSR_DMA_009 SWSR_DMA_010 SWSR_DMA_011 SWSR_DMA_012 SWSR_DMA_014
 *                      SWSR_DMA_015 SWSR_DMA_016 SWSR_DMA_018 SWSR_DMA_019 SWSR_DMA_049 SWSR_DMA_054
 *                      SW_SM001 SW_SM006
 *******************************************************************************************************/
Std_ReturnType Dma_UpdateCyclicCRC(const Dma_ChannelConfigType *const channel)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId;

    DmaHookBegin_Dma_UpdateCyclicCRC();

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check module states */
    if (!Dma_IsInitialized())
    {
        errorId = DMA_E_UNINIT;
    }
    /* #20 Check input parameters for plausibility */
    else if (NULL_PTR == channel)
    {
        errorId = DMA_E_PARAM_POINTER;
    }
    else
    {
        /* ----- Implementation ----------------------------------------------- */
        /* #30 Only updating the source address, destination address, transmit data length and burst types registers */
        errorId = Dma_Ip_UpdateCyclicCRC(channel);
    }

    /* ----- Development Error Report --------------------------------------- */
#if ((DMA_DEV_ERROR_DETECT == STD_ON) || (DMA_SAFETY_ENABLE == STD_ON))

    /* #40 Report default errors if any occurred */
    if ((Std_ReturnType)E_OK != errorId)
    {
#if (DMA_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(DMA_MODULE_ID, DMA_INSTANCE_ID, DMA_UPDATE_CYCLI_CRC, errorId);
#endif /** #if (DMA_DEV_ERROR_DETECT == STD_ON) */
#if (DMA_SAFETY_ENABLE == STD_ON)
        (void)FuSaMcal_ReportError(DMA_MODULE_ID, DMA_INSTANCE_ID, DMA_UPDATE_CYCLI_CRC, errorId);
#endif /** #if (DMA_SAFETY_ENABLE == STD_ON) */
    }

#else
    /* #50 Dummy assignment avoid compiler warning */
    DMA_DUMMY_STATEMENT(errorId);
#endif /** #if ((DMA_DEV_ERROR_DETECT == STD_ON) || (DMA_SAFETY_ENABLE == STD_ON)) */

    DmaHookEnd_Dma_UpdateCyclicCRC();
    return errorId;
}
/** *****************************************************************************************************
 * \brief This function service to check DMA base address and channel id valid or not.
 *
 * \verbatim
 * Syntax             : void Dma_CheckAddressAndChannelValid
 *                      (
 *                          uint32 address
 *                          uint32 channelId
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : address   - Dma controller base address.
 *                      channelId - Numeric identifier of the DMA channel.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Address and channel id are legal.
 *                      DMA_E_PARAM_CHANNEL_ID: Channel id out of range.
 *                      DMA_E_BASE_ADDRESS: DMA base address invalid.
 *
 * Description        : This function service to check DMA base address and channel id valid or not
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_048 SWSR_DMA_049 SW_SM006
 *******************************************************************************************************/
DMA_LOCAL Std_ReturnType Dma_CheckAddressAndChannelValid(uint32 address, uint32 channelId)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId = (Std_ReturnType)E_OK;

    DmaHookBegin_Dma_CheckAddressAndChannelValid();
    /* ----- Implementation ----------------------------------------------- */
#if (DMA_LOCK_STEP_MODE == STD_ON)

    /* #10 Checking if the DMA channel out of range by DMA base address */
    if (DMA_SF0_BASE == address)
#else
    if ((DMA_SF0_BASE == address) || (DMA_SF1_BASE == address))
#endif /** #if (DMA_LOCK_STEP_MODE == STD_ON) */
    {
        if (channelId > DMA_SF_MAX_CHANNEL_NUMBER)
        {
            errorId = DMA_E_PARAM_CHANNEL_ID;
        }/* else not needed */
    }
    else
    {
        errorId = DMA_E_PARAM_BASE_ADDRESS;
    }

    DmaHookEnd_Dma_CheckAddressAndChannelValid();
    return errorId;
}
/** *****************************************************************************************************
 * \brief This function service to check requeset channel valid or not.
 *
 * \verbatim
 * Syntax             : void Dma_CheckRequestChannelValid
 *                      (
 *                          Dma_HwControllerType controllerId
 *                          uint32               channelId
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : controllerId - Numeric identifier of the DMA controller.
 *                      channelId    - Numeric identifier of the DMA channel.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Controller id and channel id are legal.
 *                      DMA_E_PARAM_CHANNEL_ID: Channel id out of range.
 *                      DMA_E_PARAM_CONTROLLER_ID: Controller id is out of range.
 *
 * Description        : This function service to check requeset channel valid or not.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_049 SW_SM006
 *******************************************************************************************************/
DMA_LOCAL Std_ReturnType Dma_CheckRequestChannelValid(Dma_HwControllerType controllerId,
        uint32 channelId)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId = (Std_ReturnType)E_OK;

    DmaHookBegin_Dma_CheckRequestChannelValid();
    /* ----- Implementation ----------------------------------------------- */
#if (DMA_LOCK_STEP_MODE == STD_ON)

    /* #10 Checking if the DMA channel out of range by DMA controller id */
    if (DMA_HW_SF0 == controllerId)
#else
    if ((DMA_HW_SF0 == controllerId) || (DMA_HW_SF1 == controllerId))
#endif /** #if (DMA_LOCK_STEP_MODE == STD_ON) */
    {
        if (channelId > DMA_SF_MAX_CHANNEL_NUMBER)
        {
            errorId = DMA_E_PARAM_CHANNEL_ID;
        }/* else not needed */
    }
    else
    {
        errorId = DMA_E_PARAM_CONTROLLER_ID;
    }

    DmaHookEnd_Dma_CheckRequestChannelValid();
    return errorId;
}
/** *****************************************************************************************************
 * \brief This function service to get adc module configuration parameters.
 *
 * \verbatim
 * Syntax             : void Dma_GetAdcModuleConfigParams
 *                      (
 *                          Dma_PeripheralIdType   peripheralId
 *                          Dma_SubIdType          subId
 *                          Dma_InstanceConfigType *dmaConfig
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : peripheralId - Peripheral Hw Unit index.
 *                      subId        - Peripheral sub functional index.
 *                      *dmaConfig   - Pointer to a configuration structure.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Controller id and channel id are legal.
 *                      DMA_E_PARAM_HWUNIT_ID: Channel id out of range.
 *                      DMA_E_PARAM_SUB_ID: Controller id is out of range.
 *                      DMA_E_PARAM_POINTER: Pointer is MULL_PTR.
 *                      DMA_E_CORE_ID: Channel and core assignments mismatch.
 *
 * Description        : This function service to get DMA channel configuration, which assigned to
 *                      the Adc module.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_049 SW_SM006
 *******************************************************************************************************/
DMA_LOCAL Std_ReturnType Dma_GetAdcModuleConfigParams(Dma_PeripheralIdType peripheralId,
        Dma_SubIdType subId, Dma_InstanceConfigType *dmaConfig)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId = (Std_ReturnType)E_OK;
    uint8 findResult = FALSE;
    uint8 index;
    uint8 coreId;

    DmaHookBegin_Dma_GetAdcModuleConfigParams();

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check input parameters for plausibility */
    if (peripheralId > DMA_ADC3)
    {
        errorId = DMA_E_PARAM_HWUNIT_ID;
    }
    else if (subId > DMA_ADC_FIFO3)
    {
        errorId = DMA_E_PARAM_SUB_ID;
    }
    else
    {
        /* ----- Implementation ----------------------------------------------- */
        coreId = Dma_Ip_GetCoreId();

        /* #20 Get DMA configuration parameters from ADC configuration table */
        for (index = 0U; index < Dma_GlobalConfigPtr->adcConfigTableLength; index++)
        {
            if ((peripheralId == Dma_GlobalConfigPtr->adcConfigTable[index].adcControllerId)
                    && (coreId == Dma_GlobalConfigPtr->adcConfigTable[index].coreId))
            {
                if (DMA_ADC_FIFO0 == subId)
                {
                    (*dmaConfig) = Dma_GlobalConfigPtr->adcConfigTable[index].adcFIFO0;
                }
                else if (DMA_ADC_FIFO1 == subId)
                {
                    (*dmaConfig) = Dma_GlobalConfigPtr->adcConfigTable[index].adcFIFO1;
                }
                else if (DMA_ADC_FIFO2 == subId)
                {
                    (*dmaConfig) = Dma_GlobalConfigPtr->adcConfigTable[index].adcFIFO2;
                }
                else
                {
                    (*dmaConfig) = Dma_GlobalConfigPtr->adcConfigTable[index].adcFIFO3;
                }

                /* #30 Mark Successfully get Configuration */
                findResult = TRUE;
                break;
            } /* else not needed */
        }

        if (FALSE == findResult)
        {
            /* #40 The error ID may be a DMA_E_CORE_ID or DMA_E_PARAM_HWUNIT_ID or a DMA_E_PARAM_SUB_ID */
            errorId = E_NOT_OK;
        } /* else not needed */
    }

    DmaHookEnd_Dma_GetAdcModuleConfigParams();
    return errorId;
}
/** *****************************************************************************************************
 * \brief This function service to get memory to/from memory configuration parameters.
 *
 * \verbatim
 * Syntax             : void Dma_GetM2MModuleConfigParams
 *                      (
 *                          Dma_PeripheralIdType   peripheralId
 *                          Dma_SubIdType          subId
 *                          Dma_InstanceConfigType *dmaConfig
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : peripheralId - Peripheral Hw Unit index.
 *                      subId        - Peripheral sub functional index.
 *                      *dmaConfig   - Pointer to a configuration structure.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Controller id and channel id are legal.
 *                      DMA_E_PARAM_HWUNIT_ID: Channel id out of range.
 *                      DMA_E_PARAM_SUB_ID: Controller id is out of range.
 *                      DMA_E_PARAM_POINTER: Pointer is MULL_PTR.
 *                      DMA_E_CORE_ID: Channel and core assignments mismatch.
 *
 * Description        : This function service to get DMA channel configuration, which assigned to
 *                      memory to/from memory.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_049 SW_SM006
 *******************************************************************************************************/
DMA_LOCAL Std_ReturnType Dma_GetM2MModuleConfigParams(Dma_PeripheralIdType peripheralId,
        Dma_SubIdType subId, Dma_InstanceConfigType *dmaConfig)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId = (Std_ReturnType)E_OK;
    uint8 findResult = FALSE;
    uint8 index;
    uint8 coreId;

    DmaHookBegin_Dma_GetM2MModuleConfigParams();

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check input parameters for plausibility */
    if ((peripheralId < DMA_MEM_MODE1) || (peripheralId > DMA_MEM_MODE16))
    {
        errorId = DMA_E_PARAM_HWUNIT_ID;
    }
    else if (subId != DMA_CH_MEM2MEM)
    {
        errorId = DMA_E_PARAM_SUB_ID;
    }
    else
    {
        /* ----- Implementation ----------------------------------------------- */
        coreId = Dma_Ip_GetCoreId();

        /* #20 Get DMA configuration parameters from memory from/to memory configuration table */
        for (index = 0U; index < Dma_GlobalConfigPtr->memConfigTableLength; index++)
        {
            if ((peripheralId == Dma_GlobalConfigPtr->memConfigTable[index].memoryId)
                    && (coreId == Dma_GlobalConfigPtr->memConfigTable[index].coreId))
            {
                (*dmaConfig) = Dma_GlobalConfigPtr->memConfigTable[index].memoryToMemory;
                /* #30 Mark Successfully get Configuration */
                findResult = TRUE;
                break;
            } /* else not needed */
        }

        if (FALSE == findResult)
        {
            /* #40 The error ID may be a DMA_E_CORE_ID or DMA_E_PARAM_HWUNIT_ID or a DMA_E_PARAM_SUB_ID */
            errorId = E_NOT_OK;
        } /* else not needed */
    }

    DmaHookEnd_Dma_GetM2MModuleConfigParams();
    return errorId;
}
/** *****************************************************************************************************
 * \brief This function service to get Icu module configuration parameters.
 *
 * \verbatim
 * Syntax             : void Dma_GetIcuModuleConfigParams
 *                      (
 *                          Dma_PeripheralIdType   peripheralId
 *                          Dma_SubIdType          subId
 *                          Dma_InstanceConfigType *dmaConfig
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : peripheralId - Peripheral Hw Unit index.
 *                      subId        - Peripheral sub functional index.
 *                      *dmaConfig   - Pointer to a configuration structure.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Controller id and channel id are legal.
 *                      DMA_E_PARAM_HWUNIT_ID: Channel id out of range.
 *                      DMA_E_PARAM_SUB_ID: Controller id is out of range.
 *                      DMA_E_PARAM_POINTER: Pointer is MULL_PTR.
 *                      DMA_E_CORE_ID: Channel and core assignments mismatch.
 *
 * Description        : This function service to get DMA channel configuration, which assigned to
 *                      the Icu module.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_049 SW_SM006
 *******************************************************************************************************/
DMA_LOCAL Std_ReturnType Dma_GetIcuModuleConfigParams(Dma_PeripheralIdType peripheralId,
        Dma_SubIdType subId, Dma_InstanceConfigType *dmaConfig)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId = (Std_ReturnType)E_OK;
    uint8 findResult = FALSE;
    uint8 index;
    uint8 coreId;

    DmaHookBegin_Dma_GetIcuModuleConfigParams();

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check input parameters for plausibility */
    if ((peripheralId < DMA_ICU_INDEX_ETIMER1) || (peripheralId > DMA_ICU_INDEX_ETIMER4))
    {
        errorId = DMA_E_PARAM_HWUNIT_ID;
    }
    else if ((subId < DMA_ICU_CPT_A) || (subId > DMA_ICU_CPT_CE))
    {
        errorId = DMA_E_PARAM_SUB_ID;
    }
    else
    {
        /* ----- Implementation ----------------------------------------------- */
        coreId = Dma_Ip_GetCoreId();

        /* #20 Get DMA configuration parameters from ICU configuration table */
        for (index = 0U; index < Dma_GlobalConfigPtr->icuConfigTableLength; index++)
        {
            if ((peripheralId == Dma_GlobalConfigPtr->icuConfigTable[index].icuControllerId)
                    && (coreId == Dma_GlobalConfigPtr->icuConfigTable[index].coreId))
            {
                if (DMA_ICU_CPT_A == subId)
                {
                    (*dmaConfig) = Dma_GlobalConfigPtr->icuConfigTable[index].icuCaptureA;
                }
                else if (DMA_ICU_CPT_B == subId)
                {
                    (*dmaConfig) = Dma_GlobalConfigPtr->icuConfigTable[index].icuCaptureB;
                }
                else if (DMA_ICU_CPT_C == subId)
                {
                    (*dmaConfig) = Dma_GlobalConfigPtr->icuConfigTable[index].icuCaptureC;
                }
                else if (DMA_ICU_CPT_D == subId)
                {
                    (*dmaConfig) = Dma_GlobalConfigPtr->icuConfigTable[index].icuCaptureD;
                }
                else
                {
                    (*dmaConfig) = Dma_GlobalConfigPtr->icuConfigTable[index].icuCaptureCE;
                }

                /* #30 Mark Successfully get Configuration */
                findResult = TRUE;
                break;
            } /* else not needed */
        }

        if (FALSE == findResult)
        {
            /* #40 The error ID may be a DMA_E_CORE_ID or DMA_E_PARAM_HWUNIT_ID or a DMA_E_PARAM_SUB_ID */
            errorId = E_NOT_OK;
        } /* else not needed */
    }

    DmaHookEnd_Dma_GetIcuModuleConfigParams();
    return errorId;
}
/** *****************************************************************************************************
 * \brief This function service to get Pwm module configuration parameters.
 *
 * \verbatim
 * Syntax             : void Dma_GetPwmModuleConfigParams
 *                      (
 *                          Dma_PeripheralIdType   peripheralId
 *                          Dma_SubIdType          subId
 *                          Dma_InstanceConfigType *dmaConfig
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : peripheralId - Peripheral Hw Unit index.
 *                      subId        - Peripheral sub functional index.
 *                      *dmaConfig   - Pointer to a configuration structure.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Controller id and channel id are legal.
 *                      DMA_E_PARAM_HWUNIT_ID: Channel id out of range.
 *                      DMA_E_PARAM_SUB_ID: Controller id is out of range.
 *                      DMA_E_PARAM_POINTER: Pointer is MULL_PTR.
 *                      DMA_E_CORE_ID: Channel and core assignments mismatch.
 *
 * Description        : This function service to get DMA channel configuration, which assigned to
 *                      the Pwm module.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_049 SW_SM006
 *******************************************************************************************************/
DMA_LOCAL Std_ReturnType Dma_GetPwmModuleConfigParams(Dma_PeripheralIdType peripheralId,
        Dma_SubIdType subId, Dma_InstanceConfigType *dmaConfig)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId = (Std_ReturnType)E_OK;
    uint8 findResult = FALSE;
    uint8 index;
    uint8 coreId;

    DmaHookBegin_Dma_GetPwmModuleConfigParams();

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check input parameters for plausibility */
    if ((peripheralId < DMA_EPWM1_INDEX) || (peripheralId > DMA_ETIMER4_INDEX))
    {
        errorId = DMA_E_PARAM_HWUNIT_ID;
    }
    else if ((subId < DMA_PWM_FIFO_A) || (subId > DMA_PWM_CE))
    {
        errorId = DMA_E_PARAM_SUB_ID;
    }
    else
    {
        /* ----- Implementation ----------------------------------------------- */
        coreId = Dma_Ip_GetCoreId();

        /* #20 Get DMA configuration parameters from PWM configuration table */
        for (index = 0U; index < Dma_GlobalConfigPtr->pwmConfigTableLength; index++)
        {
            if ((peripheralId == Dma_GlobalConfigPtr->pwmConfigTable[index].pwmControllerId)
                    && (coreId == Dma_GlobalConfigPtr->pwmConfigTable[index].coreId))
            {
                if (DMA_PWM_FIFO_A == subId)
                {
                    (*dmaConfig) = Dma_GlobalConfigPtr->pwmConfigTable[index].pwmFIFOA;
                }
                else if (DMA_PWM_FIFO_B == subId)
                {
                    (*dmaConfig) = Dma_GlobalConfigPtr->pwmConfigTable[index].pwmFIFOB;
                }
                else if (DMA_PWM_FIFO_C == subId)
                {
                    (*dmaConfig) = Dma_GlobalConfigPtr->pwmConfigTable[index].pwmFIFOC;
                }
                else if (DMA_PWM_FIFO_D == subId)
                {
                    (*dmaConfig) = Dma_GlobalConfigPtr->pwmConfigTable[index].pwmFIFOD;
                }
                else
                {
                    (*dmaConfig) = Dma_GlobalConfigPtr->pwmConfigTable[index].pwmCE;
                }

                /* #30 Mark Successfully get Configuration */
                findResult = TRUE;
                break;
            } /* else not needed */
        }

        if (FALSE == findResult)
        {
            /* #40 The error ID may be a DMA_E_CORE_ID or DMA_E_PARAM_HWUNIT_ID or a DMA_E_PARAM_SUB_ID */
            errorId = E_NOT_OK;
        } /* else not needed */
    }

    DmaHookEnd_Dma_GetPwmModuleConfigParams();
    return errorId;
}
/** *****************************************************************************************************
 * \brief This function service to get Spi module configuration parameters.
 *
 * \verbatim
 * Syntax             : void Dma_GetSpiModuleConfigParams
 *                      (
 *                          Dma_PeripheralIdType   peripheralId
 *                          Dma_SubIdType          subId
 *                          Dma_InstanceConfigType *dmaConfig
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : peripheralId - Peripheral Hw Unit index.
 *                      subId        - Peripheral sub functional index.
 *                      *dmaConfig   - Pointer to a configuration structure.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Controller id and channel id are legal.
 *                      DMA_E_PARAM_HWUNIT_ID: Channel id out of range.
 *                      DMA_E_PARAM_SUB_ID: Controller id is out of range.
 *                      DMA_E_PARAM_POINTER: Pointer is MULL_PTR.
 *                      DMA_E_CORE_ID: Channel and core assignments mismatch.
 *
 * Description        : This function service to get DMA channel configuration, which assigned to
 *                      the Spi module.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_049 SW_SM006
 *******************************************************************************************************/
DMA_LOCAL Std_ReturnType Dma_GetSpiModuleConfigParams(Dma_PeripheralIdType peripheralId,
        Dma_SubIdType subId, Dma_InstanceConfigType *dmaConfig)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId = (Std_ReturnType)E_OK;
    uint8 findResult = FALSE;
    uint8 index;
    uint8 coreId;

    DmaHookBegin_Dma_GetSpiModuleConfigParams();

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check input parameters for plausibility */
    if ((peripheralId < DMA_CSIB1) || (peripheralId > DMA_CSIB8))
    {
        errorId = DMA_E_PARAM_HWUNIT_ID;
    }
    else if ((subId < DMA_SPI_TX) || (subId > DMA_SPI_RX))
    {
        errorId = DMA_E_PARAM_SUB_ID;
    }
    else
    {
        /* ----- Implementation ----------------------------------------------- */
        coreId = Dma_Ip_GetCoreId();

        /* #20 Get DMA configuration parameters from SPI configuration table */
        for (index = 0U; index < Dma_GlobalConfigPtr->spiConfigTableLength; index++)
        {
            if ((peripheralId == Dma_GlobalConfigPtr->spiConfigTable[index].spiControllerId)
                    && (coreId == Dma_GlobalConfigPtr->spiConfigTable[index].coreId))
            {
                if (DMA_SPI_TX == subId)
                {
                    (*dmaConfig) = Dma_GlobalConfigPtr->spiConfigTable[index].spiTx;
                }
                else
                {
                    (*dmaConfig) = Dma_GlobalConfigPtr->spiConfigTable[index].spiRx;
                }

                /* #30 Mark Successfully get Configuration */
                findResult = TRUE;
                break;
            } /* else not needed */
        }

        if (FALSE == findResult)
        {
            /* #40 The error ID may be a DMA_E_CORE_ID or DMA_E_PARAM_HWUNIT_ID or a DMA_E_PARAM_SUB_ID */
            errorId = E_NOT_OK;
        } /* else not needed */
    }

    DmaHookEnd_Dma_GetSpiModuleConfigParams();
    return errorId;
}
/** *****************************************************************************************************
 * \brief This function service to get xSpi module configuration parameters.
 *
 * \verbatim
 * Syntax             : void Dma_GetxSpiModuleConfigParams
 *                      (
 *                          Dma_PeripheralIdType   peripheralId
 *                          Dma_SubIdType          subId
 *                          Dma_InstanceConfigType *dmaConfig
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : peripheralId - Peripheral Hw Unit index.
 *                      subId        - Peripheral sub functional index.
 *                      *dmaConfig   - Pointer to a configuration structure.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Controller id and channel id are legal.
 *                      DMA_E_PARAM_HWUNIT_ID: Channel id out of range.
 *                      DMA_E_PARAM_SUB_ID: Controller id is out of range.
 *                      DMA_E_PARAM_POINTER: Pointer is MULL_PTR.
 *                      DMA_E_CORE_ID: Channel and core assignments mismatch.
 *
 * Description        : This function service to get DMA channel configuration, which assigned to
 *                      the xSpi module.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_049 SW_SM006
 *******************************************************************************************************/
DMA_LOCAL Std_ReturnType Dma_GetxSpiModuleConfigParams(Dma_PeripheralIdType peripheralId,
        Dma_SubIdType subId, Dma_InstanceConfigType *dmaConfig)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId = (Std_ReturnType)E_OK;
    uint8 findResult = FALSE;
    uint8 index;
    uint8 coreId;

    DmaHookBegin_Dma_GetxSpiModuleConfigParams();

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check input parameters for plausibility */
    if ((peripheralId < DMA_XSPI0) || (peripheralId > DMA_XSPI1))
    {
        errorId = DMA_E_PARAM_HWUNIT_ID;
    }
    else if ((subId < DMA_XSPI_PORTA_RD) || (subId > DMA_XSPI_PORTB_WR))
    {
        errorId = DMA_E_PARAM_SUB_ID;
    }
    else
    {
        /* ----- Implementation ----------------------------------------------- */
        coreId = Dma_Ip_GetCoreId();

        /* #20 Get DMA configuration parameters from SPI configuration table */
        for (index = 0U; index < Dma_GlobalConfigPtr->xSpiConfigTableLength; index++)
        {
            if ((peripheralId == Dma_GlobalConfigPtr->xSpiConfigTable[index].xSpiControllerId)
                    && (coreId == Dma_GlobalConfigPtr->xSpiConfigTable[index].coreId))
            {
                if (DMA_XSPI_PORTA_RD == subId)
                {
                    (*dmaConfig) = Dma_GlobalConfigPtr->xSpiConfigTable[index].xSpiPortARead;
                }
                else if (DMA_XSPI_PORTA_WR == subId)
                {
                    (*dmaConfig) = Dma_GlobalConfigPtr->xSpiConfigTable[index].xSpiPortAWrite;
                }
                else if (DMA_XSPI_PORTB_RD == subId)
                {
                    (*dmaConfig) = Dma_GlobalConfigPtr->xSpiConfigTable[index].xSpiPortBRead;
                }
                else
                {
                    (*dmaConfig) = Dma_GlobalConfigPtr->xSpiConfigTable[index].xSpiPortBWrite;
                }

                /* #30 Mark Successfully get Configuration */
                findResult = TRUE;
                break;
            } /* else not needed */
        }

        if (FALSE == findResult)
        {
            /* #40 The error ID may be a DMA_E_CORE_ID or DMA_E_PARAM_HWUNIT_ID or a DMA_E_PARAM_SUB_ID */
            errorId = E_NOT_OK;
        } /* else not needed */
    }

    DmaHookEnd_Dma_GetxSpiModuleConfigParams();
    return errorId;
}

/** *****************************************************************************************************
 * \brief This function service to get XTRG module configuration parameters.
 *
 * \verbatim
 * Syntax             : void Dma_GetXtrgModuleConfigParams
 *                      (
 *                          Dma_PeripheralIdType   peripheralId
 *                          Dma_SubIdType          subId
 *                          Dma_InstanceConfigType *dmaConfig
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : peripheralId - Peripheral Hw Unit index.
 *                      subId        - Peripheral sub functional index.
 *                      *dmaConfig   - Pointer to a configuration structure.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Controller id and channel id are legal.
 *                      DMA_E_PARAM_HWUNIT_ID: Channel id out of range.
 *                      DMA_E_PARAM_SUB_ID: Controller id is out of range.
 *                      DMA_E_PARAM_POINTER: Pointer is MULL_PTR.
 *                      DMA_E_CORE_ID: Channel and core assignments mismatch.
 *
 * Description        : This function service to get DMA channel configuration, which assigned to
 *                      the XTRG module.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_049 SW_SM006
 *******************************************************************************************************/
DMA_LOCAL Std_ReturnType Dma_GetXtrgModuleConfigParams(Dma_PeripheralIdType peripheralId,
        Dma_SubIdType subId, Dma_InstanceConfigType *dmaConfig)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId = (Std_ReturnType)E_OK;
    uint8 findResult = FALSE;
    uint8 index;
    uint8 coreId;

    DmaHookBegin_Dma_GetXtrgModuleConfigParams();

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check input parameters for plausibility */
    if (peripheralId != DMA_XTRG)
    {
        errorId = DMA_E_PARAM_HWUNIT_ID;
    }
    else if ((subId < DMA_XTRG_0) || (subId > DMA_XTRG_1))
    {
        errorId = DMA_E_PARAM_SUB_ID;
    }
    else
    {
        /* ----- Implementation ----------------------------------------------- */
        coreId = Dma_Ip_GetCoreId();

        /* #20 Get DMA configuration parameters from SPI configuration table */
        for (index = 0U; index < Dma_GlobalConfigPtr->xtrgConfigTableLength; index++)
        {
            if ((peripheralId == Dma_GlobalConfigPtr->xtrgConfigTable[index].xtrgControllerId)
                    && (coreId == Dma_GlobalConfigPtr->xtrgConfigTable[index].coreId))
            {
                if (DMA_XTRG_0 == subId)
                {
                    (*dmaConfig) = Dma_GlobalConfigPtr->xtrgConfigTable[index].xtrg0;
                }
                else
                {
                    (*dmaConfig) = Dma_GlobalConfigPtr->xtrgConfigTable[index].xtrg1;
                }

                /* #30 Mark Successfully get Configuration */
                findResult = TRUE;
                break;
            } /* else not needed */
        }

        if (FALSE == findResult)
        {
            /* #40 The error ID may be a DMA_E_CORE_ID or DMA_E_PARAM_HWUNIT_ID or a DMA_E_PARAM_SUB_ID */
            errorId = E_NOT_OK;
        } /* else not needed */
    }

    DmaHookEnd_Dma_GetXtrgModuleConfigParams();
    return errorId;
}
/** *****************************************************************************************************
 * \brief This function service to set Dma controller lockstep mode.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Dma_SetLockstepMode
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
 * Return value       : E_OK: Controller id and channel id are legal.
 *                      DMA_E_LOCKSTEP: Error due to set lockstep failed.
 *
 * Description        : This function service to set Dma controller lockstep mode. If lockstep mode is
 *                      enabled, the Dma SF1 controller will not be request and accessible, only the
 *                      Dma SF0 controller can be used normally.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_005 SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_049
 *******************************************************************************************************/
DMA_LOCAL Std_ReturnType Dma_SetLockstepMode(void)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId = E_OK;
    uint8 coreId = Dma_Ip_GetCoreId();
    /* ----- Implementation ----------------------------------------------- */

    DmaHookBegin_Dma_SetLockstepMode();

    /* #10 DMA lockstep mode can only be set on SF core */
    if ((uint8)DMA_CPU_ID_CORE0 == coreId)
    {
#if (DMA_LOCK_STEP_MODE == STD_OFF)
        /* #20 Set system control register true to disable dma lockstep */
        errorId = Dma_Ip_SocScrSetBit(&Dma_LockstepSignal, TRUE);
#else
        /* #30 Set system control register false to enable dma lockstep */
        errorId = Dma_Ip_SocScrSetBit(&Dma_LockstepSignal, FALSE);
#endif /** #if (DMA_LOCK_STEP_MODE == STD_OFF) */
    }/* else not needed */

    DmaHookEnd_Dma_SetLockstepMode();
    return errorId;
}
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
void Dma_GetVersionInfo(Std_VersionInfoType *versionInfo)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId = (Std_ReturnType)E_OK;

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check input parameters for plausibility */
    if (NULL_PTR == versionInfo)
    {
        errorId = DMA_E_CONFIG_POINTER;
    }
    else
    {
        /* ----- Implementation ----------------------------------------------- */
        /* #20 Retrieve version information */
        versionInfo->vendorID = DMA_VENDOR_ID;
        versionInfo->moduleID = DMA_MODULE_ID;
        versionInfo->sw_major_version = DMA_SW_MAJOR_VERSION;
        versionInfo->sw_minor_version = DMA_SW_MINOR_VERSION;
        versionInfo->sw_patch_version = DMA_SW_PATCH_VERSION;
    }

    /* ----- Development Error Report --------------------------------------- */
#if ((DMA_DEV_ERROR_DETECT == STD_ON) || (DMA_SAFETY_ENABLE == STD_ON))

    /* #30 Report default errors if any occurred */
    if ((Std_ReturnType)E_OK != errorId)
    {
#if (DMA_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(DMA_MODULE_ID, DMA_INSTANCE_ID, DMA_VERSION_ID, errorId);
#endif /** #if (DMA_DEV_ERROR_DETECT == STD_ON) */
#if (DMA_SAFETY_ENABLE == STD_ON)
        (void)FuSaMcal_ReportError(DMA_MODULE_ID, DMA_INSTANCE_ID, DMA_VERSION_ID, errorId);
#endif /** #if (DMA_SAFETY_ENABLE == STD_ON) */
    }

#else
    /* #40 Dummy assignment avoid compiler warning */
    DMA_DUMMY_STATEMENT(errorId);
#endif /** #if ((DMA_DEV_ERROR_DETECT == STD_ON) || (DMA_SAFETY_ENABLE == STD_ON)) */
}
#endif /* DMA_GETVERSIONINFO_API == STD_ON */
#define DMA_STOP_SEC_CODE
#include "Dma_MemMap.h"

#ifdef __cplusplus
}
#endif
/* End of file */
