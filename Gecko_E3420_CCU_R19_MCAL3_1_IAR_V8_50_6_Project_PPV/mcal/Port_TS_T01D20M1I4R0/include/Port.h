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
 *  \file     Port.h                                                                                    *
 *  \brief    This file contains interface header for Port MCAL driver.                                 *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/14     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef PORT_H
#define PORT_H
#ifdef __cplusplus
extern "C" {
#endif
/**
 *
 * \defgroup MCAL_PORT PORT Driver
 *
 * The Port Driver MCAL provides the service for initializing the whole PORT structure of the microcontroller.<br>
 * The Port Driver implements a standardized interface specified in the AUTOSAR_SWS_PortDriver document.<br>
 * The Port Driver is part of the AUTOSAR IO<br>
 * The PORT Driver is implemented in two layers of E3 family,
 * one is the PORT service layer, which is mainly provide users with external interface functions for port pins initialization,
 * set DIO pin initial level and initial direction. Configure pin mode at runtime, set DIO pin direction at runtime , etc.
 * And other is the PORT_IP layer provide the hardware service layer, which is mainly responsible for registers reading and writing. <br>
 *
 * \sa MCAL_PORT_MACRO
 * \sa MCAL_PORT_CFG
 * \sa MCAL_PORT_API
 *
 * @{
 */

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
/** Traceability       : SWSR_PORT_019 */
#include "Std_Types.h"
/** Traceability       : SWSR_PORT_001 SWSR_PORT_014 */
#include "Port_Cfg.h"
#include "Port_Ip.h"

/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/
/**
 *  \defgroup MCAL_PORT_MACRO PORT Macro.
 *
 * This files defines PORT MCAL macros.
 *  @{
 */
/** @} */

/**
 *  \defgroup MCAL_PORT_API PORT API.
 *
 * This files defines PORT MCAL API.
 *  @{
 */
/** @} */

/**
 *  \defgroup MCAL_PORT_CFG PORT Configuration.
 *
 * This files defines PORT MCAL Configuration.
 *  @{
 */
/** @} */

/**
 *  \addtogroup MCAL_PORT_MACRO PORT Macro
 *  @{
 *
 */

/**
 *  \name PORT Driver ID Info
 *  @{
 */
/** \brief  Semi Driver Vendor ID */
#define PORT_VENDOR_ID                                                   (0x8CU)
/** \brief  PORT Driver Module ID       */
#define PORT_MODULE_ID                                                   (124U)
/** \brief PORT Driver Instance ID */
#define PORT_INSTANCE_ID                                                 (0x00U)
/** @} */

/**
 *  \name Port Driver Service Id.
 *
 *  The Service Id is one of the argument to Det_ReportError function and is
 *  used to identify the source of the error.
 *  @{
 */
/** \brief  Port_Init() Service Id */
#define PORT_SID_INIT                       (0x00U)
/** \brief  Port_SetPinDirection() Service Id */
#define PORT_SID_SET_PIN_DIRECTION          (0x01U)
/** \brief  Port_RefreshPortDirection() Service Id */
#define PORT_SID_REFRESH_PORT_DIRECTION     (0x02U)
/** \brief  Port_GetVersionInfo() Service Id */
#define PORT_SID_GET_VERSION_INFO           (0x03U)
/** \brief  Port_SetPinMode() Service Id*/
#define PORT_SID_SET_PIN_MODE               (0x04U)
/** @} */
/** @} */

/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
/**
 *  \addtogroup MCAL_PORT_API PORT API
 *  @{
 *
 */
/** *****************************************************************************************************
 * \brief Initializes the Port Driver.
 *
 * \verbatim
 * Syntax             : void Port_Init(const Port_ConfigType* ConfigPtr)
 *
 * Service ID[hex]    : 0x00
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : ConfigPtr - Pointer to configuration set
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Driver Module Initialization function.The Initialization function shall
 *                      ALL ports and port pins with the configuration set pointed to by the parameter
 *                      ConfigPtr.
 * \endverbatim
 * Traceability       : SWSR_PORT_003 SWSR_PORT_004 SWSR_PORT_005 SWSR_PORT_006
 *                      SWSR_PORT_017 SWSR_PORT_018 SWSR_PORT_033 SWSR_PORT_034
 *                      SWSR_PORT_035 SWSR_PORT_036 SWSR_PORT_037 SWSR_PORT_038
 *                      SWSR_PORT_039 SWSR_PORT_040 SWSR_PORT_055 SWSR_PORT_056
 *                      SW_SM001 SW_SM002 SW_SM006
 *******************************************************************************************************/
void Port_Init(const Port_ConfigType *ConfigPtr);

#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
/** *****************************************************************************************************
 * \brief Set the direction of the Pin during runtime.
 *
 * \verbatim
 * Syntax             : void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction)
 *
 * Service ID[hex]    : 0x01
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : Pin - Port Pin ID number
 *                      Direction - Port Pin Direction
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : For most of the pins, the direction be controlled by IPs. For instance,
 *                      UART tx pin is an output and rx is an input. An exception here is GPIO,
 *                      which direction controlled by GPIO 'dir' and these pins are ones SW
 *                      can really set their direction. To make things less-complicate, this
 *                      func only set direction of GPIOs.
 *                      Only pin configured to directChangable can be set the port pin mode during
 *                      runtime.
 *                      This function is available if the PORT_SET_PIN_DIRECTION_API is set STD_ON
 * \endverbatim
 * Traceability       : SWSR_PORT_008 SWSR_PORT_042 SWSR_PORT_043 SWSR_PORT_044
 *                      SWSR_PORT_055 SWSR_PORT_056 SW_SM001
 *******************************************************************************************************/
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction);
#endif /** #if (PORT_SET_PIN_DIRECTION_API == STD_ON)*/

/** *****************************************************************************************************
 * \brief Refreshes port pin direction.
 *
 * \verbatim
 * Syntax             : void Port_RefreshPortDirection(void)
 *
 * Service ID[hex]    : 0x02
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function shall refresh the direction of all configured ports to the
 *                      configured direction.exclude those port pins from refreshing that are configured
 *                      as pin direction changeable during runtime.
 *                      This function is available if the PORT_SET_PIN_MODE_API is set STD_ON
 *
 * \endverbatim
 * Traceability       : SWSR_PORT_010 SWSR_PORT_045 SWSR_PORT_046 SWSR_PORT_055
 *                      SWSR_PORT_056 SW_SM001
 *******************************************************************************************************/
void Port_RefreshPortDirection(void);

#if (PORT_VERSION_INFO_API == STD_ON)
/** *****************************************************************************************************
 * \brief Get version information of this driver.
 *
 * \verbatim
 * Syntax             : void Port_GetVersionInfo(Std_VersionInfoType* versioninfo)
 *
 * Service ID[hex]    : 0x03
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
 *   -                  This function is available if the PORT_VERSION_INFO_API is set STD_ON
 *
 * \endverbatim
 * Traceability       : SWSR_PORT_017 SWSR_PORT_018 SWSR_PORT_048 SWSR_PORT_049
 *                      SW_SM001 SW_SM006
 *******************************************************************************************************/
void Port_GetVersionInfo(Std_VersionInfoType *versioninfo);
#endif/** #if (PORT_VERSION_INFO_API == STD_ON) */

#if (STD_ON == PORT_SET_PIN_MODE_API)
/** *****************************************************************************************************
 * \brief Set the port pin mode of the referenced pin during runtime.
 *
 * \verbatim
 * Syntax             : void Port_SetPinMode(Port_PinType Pin,Port_PinModeType Mode)
 *
 * Service ID[hex]    : 0x04
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : Pin -  Port Pin ID number
 *                      Mode -  New Port Pin mode to be set on port pin.
 *
 * Return value       : None
 *
 * Description        : This function shall set the port pin mode of the referenced pin during runtime.
 *                      Only pin configured to modeChangable can be set the port pin mode during
 *                      runtime.
 *                      This function is available if the PORT_SET_PIN_MODE_API is set STD_ON
 *
 * \endverbatim
 * Traceability       : SWSR_PORT_031 SWSR_PORT_050 SWSR_PORT_051 SWSR_PORT_052
 *                      SWSR_PORT_055 SWSR_PORT_056 SW_SM001
 *******************************************************************************************************/
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode);
#endif /** #if (STD_ON == PORT_SET_PIN_MODE_API) */

/** @} */
/** @} */

#ifdef __cplusplus
}
#endif
/* End of file */
#endif /* PORT_H */
