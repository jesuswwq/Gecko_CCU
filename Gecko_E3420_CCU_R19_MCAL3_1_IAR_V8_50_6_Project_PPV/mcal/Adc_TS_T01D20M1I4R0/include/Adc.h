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
 *  \file     Adc.h
 *  \brief    This file contains external interface of Adc dreiver
 *
 * <table>
 * <tr><th>Date           <th>Version
 * <tr><td>2023/07/28     <td>1.0.0
 * </table>
 *****************************************************************************************/
#ifndef ADC_H
#define ADC_H

#ifdef __cplusplus
extern "C" {
#endif
/**
 *
 * \defgroup MCAL_ADC ADC Driver
 *
 * The ADC Driver MCAL provides low level access to onbaord Adc peripheral
 * present on Device.<br>
 * The Adc Hardware Unit cntrolled by Adc Driver combines one or several Adc
 * controllers, <br>
 * which may be located on-chip or as external standalone devices of the same
 * type, with common or separate Hardware Objects<br>
 *
 * \sa MCAL_ADC_MACRO
 * \sa MCAL_ADC_CFG
 * \sa MCAL_ADC_API
 *  \{
 */

/*****************************************************************************************
 *                       Include header files
 *****************************************************************************************/
#include "Adc_Types.h"
#include "Adc_ConfigTypes.h"
#include "Adc_Version.h"
/******************************************************************************************
 *                     Global Variable Declarations
 *****************************************************************************************/
/** \cond  Adc Driver Global variable */
/** \brief  save all group information */
extern Adc_GroupStatusType Adc_AllGroupInfo[ADC_USED_GROUP_COUNT];
/** \brief  indicate whether adc is initialized */
extern Adc_GlobalStateType Adc_GlobalState;
/** \brief  save the user config */
extern const Adc_ConfigType *Adc_GlobalConfigPtr;
/** \endcond  */

/**
 *  \defgroup MCAL_ADC_MACRO Adc Macro.
 *
 * This files defines ADC MCAL macros.
 *  \{
 */

/**
 *  \name Adc Driver Service Id.
 *
 *  The Service Id is one of the argument to Det_ReportError function and is
 *  used to identify the source of the error.
 *  @{
 */

/** \brief  ADC Driver services IDs */
/** \brief  Service Id definition of the init service */
#define ADC_API_INIT                            ( (uint8)0x00U )
/** \brief  Service Id definition of the deinit service */
#define ADC_API_DEINIT                          ( (uint8)0x01U )
/** \brief  Service Id definition of the start group conversion service */
#define ADC_API_START_GROUP_CONVERSION          ( (uint8)0x02U )
/** \brief  Service Id definition of the stop group conversion service */
#define ADC_API_STOP_GROUP_CONVERSION           ( (uint8)0x03U )
/** \brief  Service Id definition of the read group service */
#define ADC_API_READ_GROUP                      ( (uint8)0x04U )
/** \brief  Service Id definition of the enable hardware trigger service */
#define ADC_API_ENABLE_HARDWARE_TRIGGER         ( (uint8)0x05U )
/** \brief  Service Id definition of the disable hardware trigger service.*/
#define ADC_API_DISABLE_HARDWARE_TRIGGER        ( (uint8)0x06U )
/** \brief  Service Id definition of the enable group notification service */
#define ADC_API_ENABLE_GROUP_NOTIFICATION       ( (uint8)0x07U )
/** \brief  Service Id definition of the disable group notification service */
#define ADC_API_DISABLE_GROUP_NOTIFICATION      ( (uint8)0x08U )
/** \brief  Service Id definition of the get group status service */
#define ADC_API_GET_GROUP_STATUS                ( (uint8)0x09U )
/** \brief  Service Id definition of the get version info service */
#define ADC_API_GET_VERSION_INFO                ( (uint8)0x0AU )
/** \brief  Service Id definition of the get stream last pointer service */
#define ADC_API_GET_STREAM_LAST_POINTER         ( (uint8)0x0BU )
/** \brief  Service Id definition of setup result buffer service */
#define ADC_API_SETUP_RESULT_BUFFER             ( (uint8)0x0CU )
/** \brief  Service Id definition of setting for power state */
#define ADC_API_SET_POWER_STATE                 ( (uint8)0x10U )
/** \brief  Service Id definition of getting current power state */
#define ADC_API_GET_CURRENT_POWER_STATE         ( (uint8)0x11U )
/** \brief  Service Id definition of getting target power state */
#define ADC_API_GET_TARGET_POWER_STATE          ( (uint8)0x12U )
/** \brief  Service Id definition of preparation for power state */
#define ADC_API_PREPARE_POWER_STATE             ( (uint8)0x13U )
/** @} */

/**
 *  \name Adc Driver Error Id.
 *
 *  The Error Id is one of the argument to Det_ReportError function and is
 *  used to identify the error cause.
 *  @{
 */
/** \brief  ADC Development errors IDs */
/** \brief  Error Id definition of Adc driver is not initialized */
#define ADC_E_UNINIT                            0x0AU
/** \brief  Error Id definition of any group is converting */
#define ADC_E_BUSY                              0x0BU
/** \brief  Error Id definition of any group is already ADC_IDLE
 *          or no valid conversion values can be get  */
#define ADC_E_IDLE                              0x0CU
/** \brief  Error Id definition of Adc driver is already initialized */
#define ADC_E_ALREADY_INITIALIZED               0x0DU
/** \brief  Error Id definition of passing a NULL_PTR */
#define ADC_E_PARAM_POINTER                     0x0EU
/** \brief  Error Id definition of passing a group id out of range */
#define ADC_E_PARAM_GROUP                       0x15U
/** \brief  Error Id definition of trigger source can not match related Apis */
#define ADC_E_WRONG_TRIGG_SRC                   0x17U
/** \brief  Error Id definition of group notification is NULL_PTR */
#define ADC_E_NOTIF_CAPABILITY                  0x18U
/** \brief  Error Id definition of no setting result buffer before start Apis */
#define ADC_E_BUFFER_UNINIT                     0x19U
/** \brief  Error Id definition of any group is converting for set power Apis */
#define ADC_E_NOT_DISENGAGED                    0x1AU
/** \brief  Error Id definition of power state is not supported */
#define ADC_E_POWER_STATE_NOT_SUPPORTED         0x1BU
/** \brief  Error Id definition of changing power state is not started
 *          by Adc_PreparePowerState. */
#define ADC_E_PERIPHERAL_NOT_PREPARED           0x1DU
/** \brief  Error Id definition of no errors */
#define ADC_NO_ERROR                            0x80U
/** \brief  Error Id definition of initialization failed */
#define ADC_E_INIT_FAIL                         0x81U
/** \brief  Error Id definition of dma config failed */
#define ADC_E_DMA_CFG_FAIL                      0x82U
/** \brief  Error Id definition of clearing fifo failed */
#define ADC_E_FIFO_POLLING_TIMEOUT              0x83U
/** \brief  Error Id definition of not enabled Adc interrupt */
#define ADC_E_INT_NOT_ENABLE                    0x84U
/** \brief  Error Id definition of interrupt triggered with wrong group */
#define ADC_E_INT_SOURCE                        0x85U
/** \brief  Error Id definition of can not match conversion values
 *          with group configuration */
#define ADC_E_VALUE_MATCH                       0x86U
/** \brief  Error Id definition of hardware trigger is enabled */
#define ADC_E_HW_BUSY                           0x87U
/** \brief  Error Id definition of preparation for same power state as
 *          current power state. */
#define ADC_E_PREPARE_SAME_STATE                0x88U
/** \brief  Error Id definition of dma start failed */
#define ADC_E_DMA_START_FAIL                    0x89U
/** \brief  Error Id definition of dma stop failed */
#define ADC_E_DMA_STOP_FAIL                     0x90U
/** \brief  Error Id definition of dma release failed */
#define ADC_E_DMA_RELEASE_FAIL                  0x91U
/** \brief  Error Id definition of Adc start conversion failed */
#define ADC_E_START_FAIL                        0x92U
/** \brief  Error Id definition of Adc stop conversion failed */
#define ADC_E_STOP_FAIL                         0x93U
/** \brief  Error Id definition of Adc deInit failed */
#define ADC_E_DEINIT_FAIL                       0x94U
/** \brief  Error Id definition of Adc interrupt triggered by
 *          unconfigured unit */
#define ADC_E_TRIG_INT_ID                       0x95U
/** @} */
/** @} */
/** \cond  Prevent variable from no use */
/** \brief Prevent variable from no use */
#define ADC_DUMMY_STATEMENT(state)           ((void)(state))
/** \endcond  */

/**
 *  \defgroup MCAL_ADC_CFG Adc Configuration.
 *
 * This files defines ADC MCAL configuration structures
 *  @{
 */
/** @} */

/**
 *  \defgroup MCAL_ADC_API Adc Driver API.
 *
 * This files defines ADC MCAL APIs.
 *  @{
 */

/** **************************************************************************************
 * \brief This function initializes the ADC hardware units and driver.

 * \verbatim
 * Syntax             : void Adc_Init(
 *                          const Adc_ConfigType* ConfigPtr)

 * Service ID[hex]    : 0x00

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : ConfigPtr - Pointer to configuration set

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : Initializes the ADC hardware units and driver.
 * \endverbatim
 * Traceability       : SWSR_ADC_051 SWSR_ADC_052 SWSR_ADC_192 SWSR_ADC_194
 *                      SW_SM002 SW_SM006
 *****************************************************************************************/
void Adc_Init(const Adc_ConfigType *ConfigPtr);
#if(ADC_DEINIT_API == STD_ON)
/** **************************************************************************************
 * \brief This function returns all ADC HW Units to a state comparable to
 *        their power on reset state.

 * \verbatim
 * Syntax             : void Adc_DeInit(
 *                          void)

 * Service ID[hex]    : 0x01

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : None

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : Returns all ADC HW Units to a state comparable to
 *                      their power on reset state.
 * \endverbatim
 * Traceability       : SWSR_ADC_066 SWSR_ADC_068 SWSR_ADC_192 SWSR_ADC_194 SW_SM001
 *****************************************************************************************/
void Adc_DeInit(void);
#endif /* #if(ADC_DEINIT_API == STD_ON) */
/** **************************************************************************************
 * \brief This function provides Adc Group with a result buffer.

 * \verbatim
 * Syntax             : Std_ReturnType Adc_SetupResultBuffer(
 *                          Adc_GroupType Group, Adc_ValueGroupType* DataBufferPtr)
 *

 * Service ID[hex]    : 0x0c

 * Sync/Async         : Synchronous

 * Reentrancy         : Reentrant

 * Parameters (in)    : Group - Numeric ID of requested ADC channel group
 *                      DataBufferPtr - Pointer to result data buffer

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : E_OK: result buffer pointer initialized correctly
 *                      E_NOT_OK: operation failed or development error

 * Description        : Initializes ADC driver with the group specific result buffer
 *                      start address where the conversion results will be stored.
 *                      The application has to ensure that the application buffer,
 *                      where DataBufferPtr points to, can hold all the conversion
 *                      results of the specified group.
 *                      The initialization with Adc_SetupResultBuffer is required
 *                      after reset, before a group conversion can be started.
 * \endverbatim
 * Traceability       : SWSR_ADC_059 SWSR_ADC_060 SWSR_ADC_192 SWSR_ADC_194
 *                      SW_SM001 SW_SM006
 *****************************************************************************************/
Std_ReturnType Adc_SetupResultBuffer(Adc_GroupType Group,
                                     Adc_ValueGroupType *DataBufferPtr);
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
/** **************************************************************************************
 * \brief This function start the conversion of all channels of the requested
 *        ADC Channel group.

 * \verbatim
 * Syntax             : void Adc_StartGroupConversion(
 *                          Adc_GroupType Group)

 * Service ID[hex]    : 0x02

 * Sync/Async         : Asynchronous

 * Reentrancy         : Reentrant

 * Parameters (in)    : Group - Numeric ID of requested ADC Channel group

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : Start the conversion of all channels of the requested
 *                      ADC Channel group.
 * \endverbatim
 * Traceability       : SWSR_ADC_073 SWSR_ADC_074 SWSR_ADC_075 SWSR_ADC_192 SWSR_ADC_194
 *                      SW_SM001 SW_SM006 SW_SM007
 *****************************************************************************************/
void Adc_StartGroupConversion(Adc_GroupType Group);
/** **************************************************************************************
 * \brief This function stop the conversion of all channels of the requested
 *        ADC Channel group.

 * \verbatim
 * Syntax             : void Adc_StopGroupConversion(
 *                          Adc_GroupType Group)

 * Service ID[hex]    : 0x03

 * Sync/Async         : Synchronous

 * Reentrancy         : Reentrant

 * Parameters (in)    : Group - Numeric ID of requested ADC Channel group

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : Stop the conversion of all channels of the requested
 *                      ADC Channel group.
 * \endverbatim
 * Traceability       : SWSR_ADC_084 SWSR_ADC_085 SWSR_ADC_087 SWSR_ADC_088 SWSR_ADC_089
 *                      SWSR_ADC_194 SW_SM001 SW_SM006 SW_SM007
 *****************************************************************************************/
void Adc_StopGroupConversion(Adc_GroupType Group);
#endif /* #if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */
#if (ADC_READ_GROUP_API == STD_ON)
/** **************************************************************************************
 * \brief This function returns the latest round conversion value of the requested Group.

 * \verbatim
 * Syntax             : Std_ReturnType Adc_ReadGroup(
 *                          Adc_GroupType Group, Adc_ValueGroupType* DataBufferPtr)

 * Service ID[hex]    : 0x04

 * Sync/Async         : Synchronous

 * Reentrancy         : Reentrant

 * Parameters (in)    : Group - Numeric ID of requested ADC channel group

 * Parameters (inout) : None

 * Parameters (out)   : DataBufferPtr - ADC results of all channels of the selected group
 *                      are stored in the data buffer addressed with the pointer

 * Return value       : E_OK: results are available and written to the data buffer
 *                      E_NOT_OK: no results are available or development error occured

 * Description        : Reads the group conversion result of the last completed conversion
 *                      round of the requested group and stores the channel values starting
 *                      at the DataBufferPtr address. The group channel values are stored
 *                      in ascending channel number order (in contrast to the storage layout
 *                      of the result buffer if streaming access is configured).
 * \endverbatim
 * Traceability       : SWSR_ADC_011 SWSR_ADC_095 SWSR_ADC_192 SWSR_ADC_194 SW_SM001
 *                      SW_SM006
 *****************************************************************************************/
Std_ReturnType Adc_ReadGroup(Adc_GroupType Group, Adc_ValueGroupType *DataBufferPtr);
#endif /* #if (ADC_READ_GROUP_API == STD_ON) */
#if (ADC_HW_TRIGGER_API == STD_ON)
/** **************************************************************************************
 * \brief This function enables the hardware trigger for the requested ADC Channel group.

 * \verbatim
 * Syntax             : void Adc_EnableHardwareTrigger(
 *                          Adc_GroupType Group)

 * Service ID[hex]    : 0x05

 * Sync/Async         : Asynchronous

 * Reentrancy         : Reentrant

 * Parameters (in)    : Group - Numeric ID of requested ADC Channel group

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : Enables the hardware trigger for the requested ADC Channel group
 * \endverbatim
 * Traceability       : SWSR_ADC_166 SWSR_ADC_167 SWSR_ADC_192 SWSR_ADC_194 SW_SM001
 *                      SW_SM006 SW_SM007
 *****************************************************************************************/
void Adc_EnableHardwareTrigger (Adc_GroupType Group);
/** **************************************************************************************
 * \brief This function disables the hardware trigger for the requested
 *        ADC Channel group.

 * \verbatim
 * Syntax             : void Adc_DisableHardwareTrigger(
 *                          Adc_GroupType Group)

 * Service ID[hex]    : 0x06

 * Sync/Async         : Synchronous

 * Reentrancy         : Reentrant

 * Parameters (in)    : Group - Numeric ID of requested ADC Channel group

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function disables the hardware trigger for the requested
 *                      ADC Channel group.
 * \endverbatim
 * Traceability       : SWSR_ADC_179 SWSR_ADC_180 SWSR_ADC_181 SWSR_ADC_182 SWSR_ADC_192
 *                      SWSR_ADC_194 SW_SM001 SW_SM006 SW_SM007
 *****************************************************************************************/
void Adc_DisableHardwareTrigger(Adc_GroupType Group);
#endif /* #if (ADC_HW_TRIGGER_API == STD_ON) */
#if(ADC_GRP_NOTIF_CAPABILITY == STD_ON)
/** **************************************************************************************
 * \brief This function enables the notification mechanism for
 *        the requested ADC Channel group.

 * \verbatim
 * Syntax             : void Adc_EnableGroupNotification(
 *                          Adc_GroupType Group)

 * Service ID[hex]    : 0x07

 * Sync/Async         : Synchronous

 * Reentrancy         : Reentrant

 * Parameters (in)    : Group - Numeric ID of requested ADC Channel group

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function enables the notification mechanism for
 *                      the requested ADC Channel group.
 * \endverbatim
 * Traceability       : SWSR_ADC_018 SWSR_ADC_104 SWSR_ADC_105 SWSR_ADC_192 SWSR_ADC_194
 *                      SW_SM001 SW_SM006
 *****************************************************************************************/
void Adc_EnableGroupNotification(Adc_GroupType Group);
/** **************************************************************************************
 * \brief This function disables the notification mechanism for the
 *        requested ADC Channel group.

 * \verbatim
 * Syntax             : void Adc_DisableGroupNotification(
 *                          Adc_GroupType Group)

 * Service ID[hex]    : 0x08

 * Sync/Async         : Synchronous

 * Reentrancy         : Reentrant

 * Parameters (in)    : Group - Numeric ID of requested ADC Channel group

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function disables the notification mechanism for the
 *                      requested ADC Channel group.
 * \endverbatim
 * Traceability       : SWSR_ADC_110 SWSR_ADC_111 SWSR_ADC_192 SWSR_ADC_194 SW_SM001
 *                      SW_SM006
 *****************************************************************************************/
void Adc_DisableGroupNotification(Adc_GroupType Group);
#endif /* #if(ADC_GRP_NOTIF_CAPABILITY == STD_ON) */
/** **************************************************************************************
 * \brief This function returns the conversion status of the requested ADC Channel group.

 * \verbatim
 * Syntax             : Adc_StatusType Adc_GetGroupStatus(
 *                          Adc_GroupType Group)

 * Service ID[hex]    : 0x09

 * Sync/Async         : Synchronous

 * Reentrancy         : Reentrant

 * Parameters (in)    : Group - Numeric ID of requested ADC Channel group

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : Conversion status for the requested group

 * Description        : This function returns the conversion status of the requested
 *                      ADC Channel group.
 * \endverbatim
 * Traceability       : SWSR_ADC_012 SWSR_ADC_116 SWSR_ADC_117 SWSR_ADC_118 SWSR_ADC_119
 *                      SWSR_ADC_120 SWSR_ADC_192 SWSR_ADC_194 SW_SM001 SW_SM006
 *****************************************************************************************/
Adc_StatusType Adc_GetGroupStatus(Adc_GroupType Group);
/** **************************************************************************************
 * \brief This function returns the number of valid samples per channel and points to
 *        a position of the last completed conversion.

 * \verbatim
 * Syntax             : Adc_StreamNumSampleType Adc_GetStreamLastPointer(
 *                          Adc_GroupType Group, Adc_ValueGroupType** PtrToSamplePtr)

 * Service ID[hex]    : 0x0b

 * Sync/Async         : Synchronous

 * Reentrancy         : Reentrant

 * Parameters (in)    : Group - Numeric ID of requested ADC Channel group

 * Parameters (inout) : None

 * Parameters (out)   : PtrToSamplePtr - Pointer to result buffer pointer

 * Return value       : Number of valid samples per channel

 * Description        : Returns the number of valid samples per channel, stored in the
 *                      result buffer.Reads a pointer, pointing to a position in the
 *                      group result buffer. With the pointer position, the results of
 *                      all group channels of the last completed conversion round can be
 *                      accessed.With the pointer and the return value, all valid group
 *                      conversion results can be accessed (the user has to take the
 *                      layout of the result buffer into account).
 * \endverbatim
 * Traceability       : SWSR_ADC_010 SWSR_ADC_123 SWSR_ADC_126 SWSR_ADC_192 SWSR_ADC_194
 *                      SW_SM001 SW_SM006
 *****************************************************************************************/
Adc_StreamNumSampleType Adc_GetStreamLastPointer(Adc_GroupType Group,
        Adc_ValueGroupType **PtrToSamplePtr);
#if (ADC_VERSION_INFO_API == STD_ON)
/** **************************************************************************************
 * \brief This function returns the version information of this module.

 * \verbatim
 * Syntax             : void Adc_GetVersionInfo(
 *                          Std_VersionInfoType* versioninfo)

 * Service ID[hex]    : 0x0a

 * Sync/Async         : Synchronous

 * Reentrancy         : Reentrant

 * Parameters (in)    : None

 * Parameters (inout) : None

 * Parameters (out)   : versioninfo - Pointer to where to store the version information
 *                      of this module

 * Return value       : None

 * Description        : Returns the version information of this module.
 * \endverbatim
 * Traceability       : SWSR_ADC_131 SWSR_ADC_192 SWSR_ADC_194 SW_SM006
 *****************************************************************************************/
void Adc_GetVersionInfo(Std_VersionInfoType *versioninfo);
#endif /* #if (ADC_VERSION_INFO_API == STD_ON) */
#if (ADC_POWER_STATE_SUPPORTED == STD_ON)
/** **************************************************************************************
 * \brief This function sets Adc power state.

 * \verbatim
 * Syntax             : Std_ReturnType Adc_SetPowerState(
 *                          Adc_PowerStateRequestResultType* Result)

 * Service ID[hex]    : 0x10

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : None

 * Parameters (inout) : None

 * Parameters (out)   : Result - If the API returns E_OK:
 *                      ADC_SERVICE_ACCEPTED: Power state change executed
 *                      If the API returns E_NOT_OK:
 *                      ADC_NOT_INIT: ADC Module not initialized
 *                      ADC_SEQUENCE_ERROR: wrong API call sequence

 * Return value       : E_OK: Power Mode changed
 *                      E_NOT_OK: request rejected

 * Description        : This API configures the Adc module so that it enters the already
 *                      prepared power state, chosen between a predefined set of configured
 *                      ones.
 * \endverbatim
 * Traceability       : SWSR_ADC_023 SWSR_ADC_027 SWSR_ADC_030 SWSR_ADC_133 SWSR_ADC_135
 *                      SWSR_ADC_192 SWSR_ADC_194 SW_SM001 SW_SM006
 *****************************************************************************************/
Std_ReturnType Adc_SetPowerState(Adc_PowerStateRequestResultType *Result);
/** **************************************************************************************
 * \brief This function returns the current power state of the ADC HW unit.

 * \verbatim
 * Syntax             : Std_ReturnType GetCurrentPowerState(
 *                          Adc_PowerStateType* CurrentPowerState,
 *                          Adc_PowerStateRequestResultType* Result)

 * Service ID[hex]    : 0x11

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : None

 * Parameters (inout) : None

 * Parameters (out)   : CurrentPowerState - The current power mode of the ADC HW Unit
 *                      is returned in this parameter
 *                      Result - If the API returns E_OK:
 *                      ADC_SERVICE_ACCEPTED: Current power mode was returned
 *                      If the API returns E_NOT_OK:
 *                      ADC_NOT_INIT: ADC Module not initialized

 * Return value       : E_OK: Mode could be read
 *                      E_NOT_OK: Service is rejected

 * Description        : This API returns the current power state of the ADC HW unit.
 * \endverbatim
 * Traceability       : SWSR_ADC_023 SWSR_ADC_024 SWSR_ADC_027 SWSR_ADC_142 SWSR_ADC_192
 *                      SWSR_ADC_194 SW_SM001 SW_SM006
 *****************************************************************************************/
Std_ReturnType Adc_GetCurrentPowerState(Adc_PowerStateType *CurrentPowerState,
                                        Adc_PowerStateRequestResultType *Result);
/** **************************************************************************************
 * \brief This function rreturns the Target power state of the ADC HW unit.

 * \verbatim
 * Syntax             : Std_ReturnType Adc_GetTargetPowerState(
 *                          Adc_PowerStateType* TargetPowerState
 *                          Adc_PowerStateRequestResultType* Result)

 * Service ID[hex]    : 0x12

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : configPtr - Pointer to configuration set

 * Parameters (inout) : None

 * Parameters (out)   : TargetPowerState - The Target power mode of the ADC HW Unit
 *                      is returned in this parameter
 *                      Result - If the API returns E_OK:
 *                      ADC_SERVICE_ACCEPTED:Target power mode was returned
 *                      If the API returns E_NOT_OK:
 *                      ADC_NOT_INIT: ADC Module not initialized

 * Return value       : E_OK: Mode could be read
 *                      E_NOT_OK: Service is rejected

 * Description        : This function rreturns the Target power state of the ADC HW unit.
 * \endverbatim
 * Traceability       : SWSR_ADC_023 SWSR_ADC_024 SWSR_ADC_027 SWSR_ADC_144 SWSR_ADC_145
 *                      SWSR_ADC_192 SWSR_ADC_194 SW_SM001 SW_SM006
 *****************************************************************************************/
Std_ReturnType Adc_GetTargetPowerState(Adc_PowerStateType *TargetPowerState,
                                       Adc_PowerStateRequestResultType *Result);
/** **************************************************************************************
 * \brief This function starts the needed process to allow the ADC HW module to enter the
 *        requested power state.

 * \verbatim
 * Syntax             : Std_ReturnType Adc_PreparePowerState(
 *                          Adc_PowerStateType PowerState,
 *                          Adc_PowerStateRequestResultType* Result)

 * Service ID[hex]    : 0x13

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : PowerState - The target power state intended to be attained

 * Parameters (inout) : None

 * Parameters (out)   : Result - If the API returns E_OK:
 *                      ADC_SERVICE_ACCEPTED: ADC Module power state preparation was
 *                      started.
 *                      If the API returns E_NOT_OK:
 *                      ADC_NOT_INIT: ADC Module not initialized
 *                      ADC_SEQUENCE_ERROR: wrong API call sequence (Current
 *                      Power State = Target Power State)
 *                      ADC_POWER_STATE_NOT_SUPP: ADC Module does not
 *                      support the requested power state
 *                      ADC_TRANS_NOT_POSSIBLE: ADC Module cannot transition
 *                      directly from the current power state

 * Return value       : E_OK: Preparation process started
 *                      E_NOT_OK: Service is rejected

 * Description        : This function starts the needed process to allow the ADC HW module to enter the
 *                      requested power state.
 * \endverbatim
 * Traceability       : SWSR_ADC_023 SWSR_ADC_025 SWSR_ADC_027 SWSR_ADC_030
 *                      SWSR_ADC_134 SWSR_ADC_147 SWSR_ADC_192 SWSR_ADC_194
 *                      SW_SM001 SW_SM006
 *****************************************************************************************/
Std_ReturnType Adc_PreparePowerState(Adc_PowerStateType PowerState,
                                     Adc_PowerStateRequestResultType *Result);
#endif /* #if (ADC_POWER_STATE_SUPPORTED == STD_ON) */
/** @} */
#ifdef __cplusplus
}
#endif

#endif /* ADC_H */
/* End of file */

