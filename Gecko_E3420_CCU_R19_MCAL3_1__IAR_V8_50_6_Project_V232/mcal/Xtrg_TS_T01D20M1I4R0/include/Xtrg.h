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
 *  \file     Xtrg.h
 *  \brief    This file contains interface header for CAN MCAL driver, ...
 *
 * <table>
 * <tr><th>Date           <th>Version
 * <tr><td>2023/08/04     <td>1.0.0
 * </table>
 *****************************************************************************************/
#ifndef XTRG_H
#define XTRG_H
#ifdef __cplusplus
extern "C" {
#endif
/**
 *
 * \defgroup MCAL_XTRG XTRG Driver
 *
 * The XTRG Driver MCAL provides low level access to onbaord Adc peripheral
 * present on Device.<br>
 * The Xtrg Hardware Unit cntrolled by Xtrg Driver combines one XTRG
 * controller, <br> which should be located on-chip.<br>
 *
 * \sa MCAL_XTRG_MACRO
 * \sa MCAL_XTRG_CFG
 * \sa MCAL_XTRG_API
 *  \{
 */
/*****************************************************************************************
 *                       Include header files
 *****************************************************************************************/
#include <Compiler.h>
#include "Xtrg_Ip.h"
#include "Std_Types.h"

/** \cond  Xtrg Driver Global variable */
/*****************************************************************************************
 *                    Global Constant Declarations
 *****************************************************************************************/
/** \brief  global xtrg device configuration */
extern const Xtrg_DeviceType *Xtrg_GlobalConfig;
/******************************************************************************************
 *                     Global Variable Declarations
 *****************************************************************************************/
/** \brief  xtrg notification enable/disable status */
extern Xtrg_NotifEnableType Xtrg_NotifEnableStatus[XTRG_INT_NUMBER];
/** \endcond  */
/*****************************************************************************************
 *                   Global Macro definition
 *****************************************************************************************/
/**
 *  \defgroup MCAL_XTRG_MACRO Xtrg Macro.
 *
 * This files defines XTRG MCAL macros.
 *  \{
 */

/**
 *  \name Xtrg Driver Error Id.
 *
 *  The Error Id is one of the argument to Det_ReportError function and is
 *  used to identify the error cause.
 *  @{
 */

/** \brief  Driver DET Error Id */
/** \brief  No error */
#define XTRG_NO_ERROR                                               0x80U
/** \brief  Input Pointer parameter is NULL_PTR */
#define XTRG_E_POINTER                                              0x81U
/** \brief  Software Trigger wait time out */
#define XTRG_E_SW_TRIG_TIMEOUT                                      0x82U
/** \brief  Notification is NULL_PTR */
#define XTRG_E_NULL_NOTIF                                           0x83U
/** \brief  Interrupt status is not match with enable register */
#define XTRG_E_INT_NO_MATCH                                         0x84U
/** @} */
/** \cond  Prevent variable from no use */
/** \brief Prevent variable from no use */
#define XTRG_DUMMY_STATEMENT(state)                                 ((state) = (state))
/** \endcond  */

/**
 *  \name Xtrg Driver Module ID Info
 *
 *  Defines for XTRG Driver Moudle Id
 *  \{
 */
/** \brief  Marco for Xtrg module info */
/** Traceability    : */
#ifdef XTRG_MODULE_ID
#  error XTRG_MODULE_ID already defined
#else
#  define XTRG_MODULE_ID 3333U
#endif
/** \brief  Marco for Xtrg instance id */
#define XTRG_INSTANCE_ID 0U
/** @} */

/**
 *  \name XTRG Driver Service Id.
 *
 *  The Service Id is one of the argument to Det_ReportError function and is
 *  used to identify the source of the error.
 *  @{
 */
/** \brief  Xtrg_SoftwareTrigger Api ID */
#define XTRG_API_SOFTWARE_TRIGGER 0x0U
/** \brief  Xtrg_GetSoftwareTrigState Api ID */
#define XTRG_API_GET_SOFTWARE_TRIG_STATE 0x1U
/** \brief  Xtrg_SignalMatrixConfig Api ID */
#define XTRG_API_SIGNAL_MATRIX_CONFIG 0x2U
/** \brief  Xtrg_SignalMutiplex Api ID */
#define XTRG_API_SIGNAL_MUTIPLEX 0x3U
/** \brief  Xtrg_SignalSynchronize Api ID */
#define XTRG_API_SIGNAL_SYNC 0x4U
/** \brief  Xtrg_DirectTriggerAdc Api ID */
#define XTRG_API_DIRECT_TRIG_ADC 0x5U
/** \brief  Xtrg_IndirectTriggerAdc Api ID */
#define XTRG_API_INDIRECT_TRIG_ADC 0x6U
/** \brief  Xtrg_ReadTriggeredAdcValue Api ID */
#define XTRG_API_READ_TRIG_ADC_VALUE 0x7U
/** \brief  Xtrg_IOFilterConfig Api ID */
#define XTRG_API_IO_FILTER_CONFIG 0x8U
/** \brief  Xtrg_DirTrigAdcPrioConfig Api ID */
#define XTRG_API_DIR_TRIG_ADC_PRIO_CONFIG 0x9U
/** \brief  Xtrg_InDirTrigAdcPrioConfig Api ID */
#define XTRG_API_INDIR_TRIG_ADC_PRIO_CONFIG 0xAU
/** \brief  Xtrg_InterruptEnable Api ID */
#define XTRG_API_INTERRUPT_ENABLED 0xBU
/** \brief  Xtrg_InterruptDisable Api ID */
#define XTRG_API_INTERRUPT_DISABLED 0xCU
/** \brief  Xtrg_CallbackEnable Api ID */
#define XTRG_API_CALLBACK_ENABLED 0xDU
/** \brief  Xtrg_CallbackDisable Api ID */
#define XTRG_API_CALLBACK_DISABLED 0xEU
/** \brief  Xtrg_DirTrigEnableConfig Api ID */
#define XTRG_API_DIR_TRIG_ENABLE_CONFIG 0xFU
/** \brief  Xtrg_IndirTrigEnableConfig Api ID */
#define XTRG_API_INDIR_TRIG_ENABLE_CONFIG 0x10U
/** @} */
/** @} */

/**
 *  \defgroup MCAL_XTRG_CFG Xtrg Configuration.
 *
 * This files defines XTRG MCAL configuration structures
 *  @{
 */
/** @} */

/**
 *  \defgroup MCAL_XTRG_API Xtrg Driver API.
 *
 * This files defines XTRG MCAL APIs.
 *  @{
 */

/** \brief  Api ID */
/** **************************************************************************************
 * \brief This function is used for generating specific Xtrg software
 *          trigger event or pulse.

 * \verbatim
 * Syntax             : void Xtrg_SoftwareTrigger(
 *                          const Xtrg_DeviceType *deviceCfg,
 *                          const Xtrg_SWTriggerType *softwareTriggerCfg)

 * Service ID[hex]    : 0x00

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : deviceCfg - Xtrg basic device configuration
 *                      softwareTriggerCfg - Xtrg software trigger configuration

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for generating specific Xtrg software
 *                      trigger event or pulse.
 * \endverbatim
 * Traceability       : SWSR_XTRG_015 SWSR_XTRG_016 SWSR_XTRG_036
 *****************************************************************************************/
void Xtrg_SoftwareTrigger(const Xtrg_DeviceType *deviceCfg,
                          const Xtrg_SWTriggerType *softwareTriggerCfg);
/** **************************************************************************************
 * \brief This function is used for getting the level state of specific
 *          Xtrg software trigger.

 * \verbatim
 * Syntax             : boolean Xtrg_GetSoftwareTrigState(
 *                          const Xtrg_DeviceType *deviceCfg,
 *                          Xtrg_SWTrigSelectorType triggerSelector)

 * Service ID[hex]    : 0x01

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : deviceCfg - Xtrg basic device configuration
 *                      triggerSelector - Xtrg software trigger selector

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : True - High state
 *                      False - Low state

 * Description        : This function is used for getting the level state of specific
 *                      Xtrg software trigger.
 * \endverbatim
 * Traceability       : SWSR_XTRG_015 SWSR_XTRG_016 SWSR_XTRG_037
 *****************************************************************************************/
boolean Xtrg_GetSoftwareTrigState(const Xtrg_DeviceType *deviceCfg,
                                  Xtrg_SWTrigSelectorType triggerSelector);
/** **************************************************************************************
 * \brief This function is used for configuring the Xtrg signal matrix.

 * \verbatim
 * Syntax             : void Xtrg_SignalMatrixConfig(
 *                          const Xtrg_DeviceType *deviceCfg,
 *                          const Xtrg_SigMatrixType *sigMatrixCfg)

 * Service ID[hex]    : 0x02

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : deviceCfg - Xtrg basic device configuration
 *                      sigMatrixCfg - Xtrg signal matrix configuration
 *                      en - Xtrg signal matrix enable/disable

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for configuring the Xtrg signal matrix.
 * \endverbatim
 * Traceability       : SWSR_XTRG_003 SWSR_XTRG_015 SWSR_XTRG_038
 *****************************************************************************************/
void Xtrg_SignalMatrixConfig(const Xtrg_DeviceType *deviceCfg,
                             const Xtrg_SigMatrixType *sigMatrixCfg,
                             boolean en);
/** **************************************************************************************
 * \brief This function is used for configuring the Xtrg Mutiplexing Mux.

 * \verbatim
 * Syntax             : void Xtrg_SignalMutiplex(
 *                          const Xtrg_DeviceType *deviceCfg,
 *                          const Xtrg_SignalType *mutiplexSignal)

 * Service ID[hex]    : 0x03

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : deviceCfg - Xtrg basic device configuration
 *                      mutiplexSignal - Xtrg signal for multiplexing Mux configuration

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for configuring the Xtrg Mutiplexing Mux.
 * \endverbatim
 * Traceability       : SWSR_XTRG_005 SWSR_XTRG_015 SWSR_XTRG_039
 *****************************************************************************************/
void Xtrg_SignalMutiplex(
    const Xtrg_DeviceType *deviceCfg,
    const Xtrg_SignalType *mutiplexSignal
);
/** **************************************************************************************
 * \brief This function is used for configuring the Xtrg Synchronization Mux.

 * \verbatim
 * Syntax             : void Xtrg_SignalSynchronize(
 *                          const Xtrg_DeviceType *deviceCfg,
 *                          const Xtrg_SignalType *syncSignalCfg)

 * Service ID[hex]    : 0x04

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : deviceCfg - Xtrg basic device configuration
 *                      syncSignalCfg - Xtrg signal for epwm/etimer
 *                                      synchronization configuration

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for configuring the Xtrg Synchronization
 *                      Mux.
 * \endverbatim
 * Traceability       : SWSR_XTRG_006 SWSR_XTRG_015 SWSR_XTRG_040
 *****************************************************************************************/
void Xtrg_SignalSynchronize(
    const Xtrg_DeviceType *deviceCfg,
    const Xtrg_SignalType *syncSignalCfg
);
/** **************************************************************************************
 * \brief This function is used for configuring the Xtrg Direct Trigger
 *          Mux configuration.

 * \verbatim
 * Syntax             : void Xtrg_DirectTriggerAdc(
 *                          const Xtrg_DeviceType *deviceCfg,
 *                          const Xtrg_DrtTrigMuxType *directTriggerCfg)

 * Service ID[hex]    : 0x05

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : deviceCfg - Xtrg basic device configuration
 *                      directTriggerCfg - Xtrg Direct Trigger Mux configuration

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for configuring the Xtrg Direct Trigger
 *                      Mux configuration.
 * \endverbatim
 * Traceability       : SWSR_XTRG_007 SWSR_XTRG_015 SWSR_XTRG_041
 *****************************************************************************************/
void Xtrg_DirectTriggerAdc(
    const Xtrg_DeviceType *deviceCfg,
    const Xtrg_DrtTrigMuxType *directTriggerCfg
);
/** **************************************************************************************
 * \brief This function is used for configuring the Xtrg Indirect Trigger Mux
 *          configuration.

 * \verbatim
 * Syntax             : void Xtrg_IndirectTriggerAdc(
 *                          const Xtrg_DeviceType *deviceCfg,
 *                          const Xtrg_IndrtTrigMuxType *indirectTriggerCfg)

 * Service ID[hex]    : 0x06

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : deviceCfg - Xtrg basic device configuration
 *                      indirectTriggerCfg - Xtrg Indirect Trigger Mux configuration

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for configuring the Xtrg Indirect Trigger Mux
 *                      configuration.
 * \endverbatim
 * Traceability       : SWSR_XTRG_007 SWSR_XTRG_015 SWSR_XTRG_042
 *****************************************************************************************/
void Xtrg_IndirectTriggerAdc(
    const Xtrg_DeviceType *deviceCfg,
    const Xtrg_IndrtTrigMuxType *indirectTriggerCfg
);
/** **************************************************************************************
 * \brief This function is used for reading the Adc channel conversion value
 *          which is triggered by Xtrg Trigger Mux.

 * \verbatim
 * Syntax             : uint32 Xtrg_ReadTriggeredAdcValue(
 *                          const Xtrg_DeviceType *deviceCfg,
 *                          Xtrg_TrigMuxSelectorType trigMuxSelector,
 *                          Xtrg_TrigAdcIndexType triggeredAdc)

 * Service ID[hex]    : 0x07

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : deviceCfg - Xtrg basic device configuration
 *                      trigMuxSelector - Xtrg Indirect/direct Trigger Mux
 *                      triggeredAdc - Adc triggered by Xtrg trigger Mux

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : adcConvValue - Triggered Adc channel conversion value

 * Description        : This function is used for reading the Adc channel conversion value
 *                      which is triggered by Xtrg Trigger Mux.
 * \endverbatim
 * Traceability       : SWSR_XTRG_008 SWSR_XTRG_015 SWSR_XTRG_043
 *****************************************************************************************/
uint32 Xtrg_ReadTriggeredAdcValue(
    const Xtrg_DeviceType *deviceCfg,
    Xtrg_TrigMuxSelectorType trigMuxSelector,
    Xtrg_TrigAdcIndexType triggeredAdc
);
/** **************************************************************************************
 * \brief This function is used for configuring the Xtrg I/O filter configuration.

 * \verbatim
 * Syntax             : void Xtrg_IOFilterConfig(
 *                          const Xtrg_DeviceType *deviceCfg,
 *                          const Xtrg_IOFilterType *ioFilterCfg,
 *                          boolean enable)

 * Service ID[hex]    : 0x08

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : deviceCfg - Xtrg basic device configuration
 *                      ioFilterCfg - Xtrg I/O filter configuration
 *                      enable - Enable/Disable Xtrg I/O filter configuration

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for configuring the Xtrg I/O filter
 *                      configuration.
 * \endverbatim
 * Traceability       : SWSR_XTRG_009 SWSR_XTRG_015 SWSR_XTRG_044
 *****************************************************************************************/
void Xtrg_IOFilterConfig(
    const Xtrg_DeviceType *deviceCfg,
    const Xtrg_IOFilterType *ioFilterCfg,
    boolean enable
);
/** **************************************************************************************
 * \brief This function is used for configuring Xtrg Direct Trigger Mux
 *          priority configuration.

 * \verbatim
 * Syntax             : void Xtrg_DirTrigAdcPrioConfig(
 *                          const Xtrg_DeviceType *deviceCfg,
 *                          Xtrg_DrtTrigMuxSelectorType directTmux,
 *                          Xtrg_TmuxTrigPriority priorityCfg)

 * Service ID[hex]    : 0x09

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : deviceCfg - Xtrg basic device configuration
 *                      directTmux - Xtrg direct trigger mux selectors
 *                      priorityCfg - Xtrg Direct Trigger Mux priority configuration

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for configuring Xtrg Direct Trigger Mux
 *                      priority configuration.
 * \endverbatim
 * Traceability       : SWSR_XTRG_010 SWSR_XTRG_015 SWSR_XTRG_045
 *****************************************************************************************/
void Xtrg_DirTrigAdcPrioConfig(
    const Xtrg_DeviceType *deviceCfg,
    Xtrg_DrtTrigMuxSelectorType directTmux,
    Xtrg_TmuxTrigPriority priorityCfg
);
/** **************************************************************************************
 * \brief This function is used for configuring Xtrg Indirect Trigger
 *          Mux priority configuration.

 * \verbatim
 * Syntax             : void Xtrg_InDirTrigAdcPrioConfig(
 *                          const Xtrg_DeviceType *deviceCfg,
 *                          Xtrg_IndrtTrigMuxSelectorType indirectTmux,
 *                          Xtrg_TmuxTrigPriority priorityCfg)

 * Service ID[hex]    : 0x0A

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : deviceCfg - Xtrg basic device configuration
 *                      indirectTmux - Xtrg indirect trigger mux selectors
 *                      priorityCfg - Xtrg Indirect Trigger Mux priority configuration

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for configuring Xtrg Indirect Trigger
 *                      Mux priority configuration.
 * \endverbatim
 * Traceability       : SWSR_XTRG_010 SWSR_XTRG_015 SWSR_XTRG_046
 *****************************************************************************************/
void Xtrg_InDirTrigAdcPrioConfig
(
    const Xtrg_DeviceType *deviceCfg,
    Xtrg_IndrtTrigMuxSelectorType indirectTmux,
    Xtrg_TmuxTrigPriority priorityCfg
);
/** **************************************************************************************
 * \brief This function is used for setting Xtrg interrupt configuration.

 * \verbatim
 * Syntax             : void Xtrg_InterruptEnable(
 *                          const Xtrg_DeviceType *deviceCfg,
 *                          Xtrg_NormalInterruptType interruptId)

 * Service ID[hex]    : 0x0B

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : deviceCfg - Xtrg basic device configuration
 *                      interruptId - Xtrg interrupt ID

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for setting Xtrg interrupt configuration.
 * \endverbatim
 * Traceability       : SWSR_XTRG_011 SWSR_XTRG_015 SWSR_XTRG_047
 *****************************************************************************************/
void Xtrg_InterruptEnable(
    const Xtrg_DeviceType *deviceCfg,
    Xtrg_NormalInterruptType interruptId
);
/** **************************************************************************************
 * \brief This function is used for resetting configuring Xtrg interrupt configuration.

 * \verbatim
 * Syntax             : void Xtrg_InterruptDisable(
 *                          const Xtrg_DeviceType *deviceCfg,
 *                          Xtrg_NormalInterruptType interruptId)

 * Service ID[hex]    : 0x0C

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : deviceCfg - Xtrg basic device configuration
 *                      interruptId - Xtrg interrupt ID

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for resetting configuring Xtrg
 *                      interrupt configuration.
 * \endverbatim
 * Traceability       : SWSR_XTRG_011 SWSR_XTRG_015 SWSR_XTRG_048
 *****************************************************************************************/
void Xtrg_InterruptDisable(
    const Xtrg_DeviceType *deviceCfg,
    Xtrg_NormalInterruptType interruptId
);
/** **************************************************************************************
 * \brief This function is used for setting callback function of Xtrg.

 * \verbatim
 * Syntax             : void Xtrg_CallbackEnable(
 *                          const Xtrg_DeviceType *deviceCfg,
 *                          Xtrg_NormalInterruptType interruptId)

 * Service ID[hex]    : 0x0D

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : deviceCfg - Xtrg basic device configuration
 *                      interruptId - Xtrg interrupt event

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for setting callback function of Xtrg.
 * \endverbatim
 * Traceability       : SWSR_XTRG_012 SWSR_XTRG_015 SWSR_XTRG_049
 *****************************************************************************************/
void Xtrg_CallbackEnable(
    const Xtrg_DeviceType *deviceCfg,
    Xtrg_NormalInterruptType interruptId
);
/** **************************************************************************************
 * \brief This function returns the version information of this module.

 * \verbatim
 * Syntax             : void  Xtrg_CallbackDisable(
 *                          const Xtrg_DeviceType *deviceCfg,
 *                          Xtrg_NormalInterruptType interruptId)

 * Service ID[hex]    : 0x0E

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : deviceCfg - Xtrg basic device configuration
 *                      interruptId - Xtrg interrupt event

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function returns the version information of this module.
 * \endverbatim
 * Traceability       : SWSR_XTRG_012 SWSR_XTRG_015 SWSR_XTRG_050
 *****************************************************************************************/
void Xtrg_CallbackDisable(
    const Xtrg_DeviceType *deviceCfg,
    Xtrg_NormalInterruptType interruptId
);
/** **************************************************************************************
 * \brief This function is used for enable/disable direct Tirgger Mux.

 * \verbatim
 * Syntax             : void Xtrg_DirTrigEnableConfig(
 *                          const Xtrg_DeviceType *deviceCfg,
 *                          Xtrg_DrtTrigMuxSelectorType directTmux,
 *                          boolean enable)

 * Service ID[hex]    : 0x0F

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : deviceCfg - Xtrg basic device configuration
 *                      directTmux - Xtrg direct trigger mux selectors
 *                      enable - Xtrg direct trigger mux enable/disable configuration

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for enable/disable direct Tirgger Mux.
 * \endverbatim
 * Traceability       : SWSR_XTRG_015 SWSR_XTRG_051
 *****************************************************************************************/
void Xtrg_DirTrigEnableConfig(
    const Xtrg_DeviceType *deviceCfg,
    Xtrg_DrtTrigMuxSelectorType directTmux,
    boolean enable
);
/** **************************************************************************************
 * \brief This function returns the version information of this module.

 * \verbatim
 * Syntax             : void Xtrg_IndirTrigEnableConfig(
 *                          const Xtrg_DeviceType *deviceCfg,
 *                          Xtrg_IndrtTrigMuxSelectorType directTmux,
 *                          boolean enable)

 * Service ID[hex]    : 0x10

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : deviceCfg - Xtrg basic device configuration
 *                      indirectTmux - Xtrg indirect trigger mux selectors
 *                      enable - Xtrg direct trigger mux enable/disable configuration
 *
 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function returns the version information of this module.
 * \endverbatim
 * Traceability       : SWSR_XTRG_015 SWSR_XTRG_052
 *****************************************************************************************/
void Xtrg_IndirTrigEnableConfig(
    const Xtrg_DeviceType *deviceCfg,
    Xtrg_IndrtTrigMuxSelectorType indirectTmux,
    boolean enable
);
/** @} */
/** @} */

#ifdef __cplusplus
}
#endif
#endif /* XTRG_H */
/* End of file */

