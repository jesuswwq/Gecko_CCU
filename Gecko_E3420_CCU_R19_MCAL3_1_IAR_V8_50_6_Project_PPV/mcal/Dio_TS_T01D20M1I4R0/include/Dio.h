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
 *  \file     Dio.h                                                                                     *
 *  \brief    This file contains interface header for DIO MCAL driver.                                  *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date                 <th>Version                                                             *
 * <tr><td>2023/07/06           <td>1.0.0                                                               *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef DIO_H
#define DIO_H

/**
 *  \defgroup MCAL_DIO DIO Driver API
 *
 *  The DIO Driver provides services for reading and writing to/from
 *      -  DIO Channels (GPIO Pins)
 *      -  DIO Ports    (GPIO whole Registers)
 *      -  DIO Channel Groups (GPIO register submask)
 *
 *  This specification is applicable to drivers only for on chip DIO pins and
 *  ports <br>
 *  This module works on pins and ports which are configured by the PORT driver
 *  for this purpose.<br>
 *  For this reason, there is no configuration and initialization of this port
 *  structure in the DIO Driver <br>
 *  \sa MCAL_DIO_CFG
 *  \sa MCAL_DIO_API
 *  \sa MCAL_DIO_MACRO
 */

/** \{ */

#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Mcal.h"
/**
 * Traceability       : SWSR_DIO_033
 */
#include "Std_Types.h"
#include "Dio_Cfg.h"
#include "Dio_Types.h"

/**
 *  \defgroup MCAL_DIO_CFG DIO Configuration.
 *
 * This files defines DIO MCAL configuration structures
 *  \{
 */

/** \} */

/**
 *  \defgroup MCAL_DIO_API DIO Api.
 *
 * This files defines DIO MCAL api
 *  \{
 */

/** \} */

/**
 *  \defgroup MCAL_DIO_MACRO DIO macro.
 *
 * This files defines DIO MCAL macro
 *  \{
 */

/** \} */

/**
 *  \addtogroup MCAL_DIO_API DIO Api
 *  \{
 */
/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
/** *****************************************************************************************************
 * \brief Returns the value of the specified DIO channel.
 *
 * \verbatim
 *  Syntax            : Dio_LevelType Dio_ReadChannel(
 *                          Dio_ChannelType ChannelId )
 *
 * Service ID[hex]    : 0x00
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : ChannelId - ID of DIO channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Dio_LevelType - STD_HIGH The physical level of the
 *                      corresponding Pin is STD_HIGH
 *                      - STD_LOW The physical level of the corresponding Pin
 *                      is STD_LOW.
 *
 * Description        : Returns the value of the specified DIO channel.
 * \endverbatim
 * Traceability       : SWSR_DIO_001 SWSR_DIO_002 SWSR_DIO_003 SWSR_DIO_004
 *                      SWSR_DIO_008 SWSR_DIO_011 SWSR_DIO_013 SWSR_DIO_016
 *                      SWSR_DIO_020 SWSR_DIO_021 SWSR_DIO_022 SWSR_DIO_025
 *                      SWSR_DIO_030 SWSR_DIO_049 SWSR_DIO_050 SWSR_DIO_076
 *                      SWSR_DIO_078 SW_SM006
 *******************************************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

/** *****************************************************************************************************
 * \brief Service to set a level of a channel.
 *
 * \verbatim
 *  Syntax            : void Dio_WriteChannel( Dio_ChannelType ChannelId,
 *                                             Dio_LevelType Level )
 *
 * Service ID[hex]    : 0x01
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : ChannelId - ID of DIO channel
 *                      Level - Value to be written
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Service to set a level of a channel.
 * \endverbatim
 * Traceability       : SWSR_DIO_001 SWSR_DIO_002 SWSR_DIO_003 SWSR_DIO_004
 *                      SWSR_DIO_008 SWSR_DIO_011 SWSR_DIO_013 SWSR_DIO_014
 *                      SWSR_DIO_016 SWSR_DIO_017 SWSR_DIO_030 SWSR_DIO_051
 *                      SWSR_DIO_052 SW_SM006
 *******************************************************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);

/** *****************************************************************************************************
 * \brief Returns the level of all channels of that port.
 *
 * \verbatim
 * Syntax             : Dio_PortLevelType Dio_ReadPort( Dio_PortType PortId )
 *
 * Service ID[hex]    : 0x02
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : PortId - ID of DIO Port
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Dio_PortLevelType - Level of all channels of that port
 *
 * Description        : Returns the level of all channels of that port.
 * \endverbatim
 * Traceability       : SWSR_DIO_001 SWSR_DIO_002 SWSR_DIO_006 SWSR_DIO_007
 *                      SWSR_DIO_008 SWSR_DIO_011 SWSR_DIO_013 SWSR_DIO_016
 *                      SWSR_DIO_020 SWSR_DIO_021 SWSR_DIO_023 SWSR_DIO_025
 *                      SWSR_DIO_031 SWSR_DIO_053 SWSR_DIO_054 SW_SM006
 *******************************************************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);

/** *****************************************************************************************************
 * \brief Service to set a value of the port.
 *
 * \verbatim
 * Syntax             : void Dio_WritePort( Dio_PortType PortId,
 *                                          Dio_PortLevelType Level )
 *
 * Service ID[hex]    : 0x03
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : PortId - ID of DIO Port
 *                      Level - Value to be written
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Service to set a value of the port.
 * \endverbatim
 * Traceability       : SWSR_DIO_001 SWSR_DIO_002 SWSR_DIO_006 SWSR_DIO_007
 *                      SWSR_DIO_008 SWSR_DIO_011 SWSR_DIO_013 SWSR_DIO_014
 *                      SWSR_DIO_016 SWSR_DIO_018 SWSR_DIO_019 SWSR_DIO_031
 *                      SWSR_DIO_055 SWSR_DIO_056 SWSR_DIO_057 SW_SM006
 *******************************************************************************************************/
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);

/** *****************************************************************************************************
 * \brief This Service reads a subset of the adjoining bits of a port
 *
 * \verbatim
 * Syntax             : Dio_PortLevelType Dio_ReadChannelGroup(
 *                              const Dio_ChannelGroupType* ChannelGroupIdPtr )
 *
 * Service ID[hex]    : 0x04
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : ChannelGroupIdPtr - Pointer to ChannelGroup
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Dio_PortLevelType - Level of a subset of the adjoining
 *                      bits of a port
 *
 * Description        : This Service read a subset of the adjoining bits of a
 *                      port.
 * \endverbatim
 * Traceability       : SWSR_DIO_001 SWSR_DIO_002 SWSR_DIO_008 SWSR_DIO_011
 *                      SWSR_DIO_013 SWSR_DIO_016 SWSR_DIO_020 SWSR_DIO_021
 *                      SWSR_DIO_024 SWSR_DIO_025 SWSR_DIO_032 SWSR_DIO_058
 *                      SWSR_DIO_059 SWSR_DIO_060 SWSR_DIO_061 SWSR_DIO_076
 *                      SWSR_DIO_078 SW_SM006
 *******************************************************************************************************/
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType *ChannelGroupIdPtr);

/** *****************************************************************************************************
 * \brief Service to set a subset of the adjoining bits of a port to a
 *  specified level
 *
 * \verbatim
 * Syntax             : void Dio_WriteChannelGroup( const Dio_ChannelGroupType*
 *                              ChannelGroupIdPtr, Dio_PortLevelType Level )
 *
 * Service ID[hex]    : 0x05
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : ChannelGroupIdPtr - Pointer to ChannelGroup
 *                      Level - Value to be written
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Service to set a subset of the adjoining bits of a port
 *                      to a specified level
 * \endverbatim
 * Traceability       : SWSR_DIO_001 SWSR_DIO_002 SWSR_DIO_008 SWSR_DIO_011
 *                      SWSR_DIO_013 SWSR_DIO_014 SWSR_DIO_016 SWSR_DIO_032
 *                      SWSR_DIO_062 SWSR_DIO_063 SWSR_DIO_064 SWSR_DIO_065
 *                      SWSR_DIO_066 SW_SM006
 *******************************************************************************************************/
void Dio_WriteChannelGroup(const Dio_ChannelGroupType *ChannelGroupIdPtr, Dio_PortLevelType Level);

#if (STD_ON == DIO_FLIP_CHANNEL_API)
/** *****************************************************************************************************
 * \brief Service to flip (change from 1 to 0 or from 0 to 1) the
 *   level of a channel and return the level of the channel
 *
 * \verbatim
 * Syntax             : Dio_LevelType Dio_FlipChannel(
 *                              Dio_ChannelType ChannelId )
 *
 * Service ID[hex]    : 0x11
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : ChannelId - ID of DIO channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Dio_LevelType - STD_HIGH The physical level of the
 *                      corresponding Pin is STD_HIGH
 *                      - STD_LOW The physical level of the corresponding Pin is
 *                      STD_LOW
 *
 * Description        : Service to flip (change from 1 to 0 or from 0 to 1) the
 *                      level of a channel and return the level of the channel
 *                      after flip
 * \endverbatim
 * Traceability       : SWSR_DIO_001 SWSR_DIO_002 SWSR_DIO_003 SWSR_DIO_004
 *                      SWSR_DIO_008 SWSR_DIO_011 SWSR_DIO_013 SWSR_DIO_014
 *                      SWSR_DIO_016 SWSR_DIO_021 SWSR_DIO_025 SWSR_DIO_070
 *                      SWSR_DIO_071 SWSR_DIO_072 SWSR_DIO_076 SWSR_DIO_078
 *                      SW_SM006 SWSR_DIO_069
 *******************************************************************************************************/
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);
#endif /* STD_ON == DIO_FLIP_CHANNEL_API */

#if (DIO_VERSION_INFO_API == STD_ON)
/** *****************************************************************************************************
 * \brief Service to get the version information of this module.
 *
 * \verbatim
 * Syntax             : void Dio_GetVersionInfo(
 *                          Std_VersionInfoType* versioninfo )
 *
 * Service ID[hex]    : 0x12
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : configPtr - Pointer to configuration set
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : versioninfo - Pointer to where to store the version
 *                      information of this module.
 *
 * Return value       : None
 *
 * Description        : Service to get the version information of this module
 * \endverbatim
 * Traceability       : SWSR_DIO_001 SWSR_DIO_002 SWSR_DIO_008 SWSR_DIO_011
 *                      SWSR_DIO_016 SWSR_DIO_067 SWSR_DIO_068 SW_SM006
 *******************************************************************************************************/
void Dio_GetVersionInfo(Std_VersionInfoType *versionInfo);
#endif /* DIO_VERSION_INFO_API == STD_ON */

/** *****************************************************************************************************
 * \brief Dio captures external levels and triggers interrupts.
 *
 * \verbatim
 * Syntax             : void Dio_SetPinInterruptDetect(
 *                              Dio_ChannelType ChannelId,
 *                              Dio_DetectionType InterruptType)
 *
 * Service ID[hex]    : 0x12
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : ChannelId - ID of DIO channel
 *                      InterruptType interupt mode
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : When the CPU enters hib/sleep mode,
 *                      it can only be awakened through asynchronous interrupts.
 * \endverbatim
 * Traceability       : SWSR_DIO_001 SWSR_DIO_002 SWSR_DIO_004 SWSR_DIO_011
 *                      SWSR_DIO_016 SWSR_DIO_073 SW_SM006
 *******************************************************************************************************/
void Dio_SetPinInterruptDetect(Dio_ChannelType ChannelId, Dio_DetectionType InterruptType);


#ifdef __cplusplus
}
#endif

/** \} */

/** \} */

#endif /* DIO_H */

/* End of file */
