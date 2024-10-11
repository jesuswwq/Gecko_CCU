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
 *  \file     Dio.c                                                                                     *
 *  \brief    This file contains interface header for DIO MCAL driver.                                  *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date                 <th>Version                                                             *
 * <tr><td>2023/07/06           <td>1.0.0                                                               *
 * </table>                                                                                             *
 *******************************************************************************************************/

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Dio.h"
#include "Dio_Ip.h"
#include "Dio_Irq.h"
#include "Dio_Fault.h"
#if (STD_ON == DIO_SAFETY_ENABLE)
#include "FuSaMcalReportError.h"
#endif /** #if (STD_ON == DIO_SAFETY_ENABLE) */
#if (STD_ON == DIO_DEV_ERROR_DETECT)
#include "Det.h"
#endif /** #if (STD_ON == DIO_DEV_ERROR_DETECT) */

/********************************************************************************************************
 *                                 Imported Compiler Switch Checks                                      *
 *******************************************************************************************************/
#ifndef DIO_SW_MAJOR_VERSION
#error "DIO_SW_MAJOR_VERSION is not defined."
#endif

#ifndef DIO_SW_MINOR_VERSION
#error "DIO_SW_MINOR_VERSION is not defined."
#endif

#ifndef DIO_SW_PATCH_VERSION
#error "DIO_SW_PATCH_VERSION is not defined."
#endif

#ifndef DIO_AR_RELEASE_MAJOR_VERSION
#error "DIO_AR_RELEASE_MAJOR_VERSION is not defined."
#endif

#ifndef DIO_AR_RELEASE_MINOR_VERSION
#error "DIO_AR_RELEASE_MINOR_VERSION is not defined."
#endif

#ifndef DIO_AR_RELEASE_REVISION_VERSION
#error "DIO_AR_RELEASE_REVISION_VERSION is not defined."
#endif

#if(DIO_AR_RELEASE_MAJOR_VERSION != 4U)
#error "DIO_AR_RELEASE_MAJOR_VERSION does not match."
#endif

#if(DIO_AR_RELEASE_MINOR_VERSION != 3U)
#error "DIO_AR_RELEASE_MAJOR_VERSION does not match."
#endif

#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"

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
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    Dio_LevelType retVal = (Dio_LevelType)STD_LOW;
    Std_ReturnType errorId;

    /* #10 Check channel ID */
    errorId = Dio_ValidateChannel(ChannelId);

    if ((Std_ReturnType)E_OK == errorId)
    {
        retVal = Dio_Ip_ReadChannel(ChannelId);

        /* #20 Check level */
        errorId = Dio_ValidateLevel(retVal);

        if ((Std_ReturnType)E_OK != errorId)
        {
            retVal = (Dio_LevelType)STD_LOW;
        }
    } /* else not needed */

#if ((STD_ON == DIO_DEV_ERROR_DETECT) || (STD_ON == DIO_SAFETY_ENABLE))

    if ((Std_ReturnType)E_OK != errorId)
    {
#if (STD_ON == DIO_DEV_ERROR_DETECT)
        (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_READ_CHANNEL_SID,
                              errorId);
#endif /** #if (STD_ON == DIO_DEV_ERROR_DETECT) */
#if (STD_ON == DIO_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_READ_CHANNEL_SID,
                                   errorId);
#endif /** #if (STD_ON == DIO_SAFETY_ENABLE) */
    } /* else not needed */

#endif /** #if ((STD_ON == DIO_DEV_ERROR_DETECT) || (STD_ON == DIO_SAFETY_ENABLE)) */

    return retVal;
}

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
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    Std_ReturnType errorId;

    /* #10 Check channel ID */
    errorId = Dio_ValidateChannel(ChannelId);

    if ((Std_ReturnType)E_OK == errorId)
    {
        /* #20 Check level */
        errorId = Dio_ValidateLevel(Level);

        if ((Std_ReturnType)E_OK == errorId)
        {
            errorId = Dio_Ip_WriteChannel(ChannelId, Level);
        }
    } /* else not needed */

#if ((STD_ON == DIO_DEV_ERROR_DETECT) || (STD_ON == DIO_SAFETY_ENABLE))

    if ((Std_ReturnType)E_OK != errorId)
    {
#if (STD_ON == DIO_DEV_ERROR_DETECT)
        (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_WRITE_CHANNEL_SID,
                              errorId);
#endif /** #if (STD_ON == DIO_DEV_ERROR_DETECT) */
#if (STD_ON == DIO_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_WRITE_CHANNEL_SID,
                                   errorId);
#endif /** #if (STD_ON == DIO_SAFETY_ENABLE) */
    } /* else not needed */

#endif /** #if ((STD_ON == DIO_DEV_ERROR_DETECT) || (STD_ON == DIO_SAFETY_ENABLE)) */

}

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
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
    Dio_PortLevelType retVal = (Dio_PortLevelType) STD_LOW;
    Std_ReturnType errorId;

    /* #10 Check channel ID */
    errorId = Dio_ValidatePort(PortId);

    if ((Std_ReturnType)E_OK == errorId)
    {
        /* #20 Read port level */
        retVal = Dio_Ip_ReadPort(PortId);
    } /* else not needed */

#if ((STD_ON == DIO_DEV_ERROR_DETECT) || (STD_ON == DIO_SAFETY_ENABLE))

    if ((Std_ReturnType)E_OK != errorId)
    {
#if (STD_ON == DIO_DEV_ERROR_DETECT)
        (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_READ_PORT_SID,
                              errorId);
#endif /** #if (STD_ON == DIO_DEV_ERROR_DETECT) */
#if (STD_ON == DIO_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_READ_PORT_SID,
                                   errorId);
#endif /** #if (STD_ON == DIO_SAFETY_ENABLE) */
    } /* else not needed */

#endif /** #if ((STD_ON == DIO_DEV_ERROR_DETECT) || (STD_ON == DIO_SAFETY_ENABLE)) */

    return retVal;
}

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
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
    Std_ReturnType errorId;

    /* #10 Check channel ID */
    errorId = Dio_ValidatePort(PortId);

    if ((Std_ReturnType)E_OK == errorId)
    {
        /* #20 Write port level */
        errorId = Dio_Ip_WritePort(PortId, Level);
    } /* else not needed */

#if ((STD_ON == DIO_DEV_ERROR_DETECT) || (STD_ON == DIO_SAFETY_ENABLE))

    if ((Std_ReturnType)E_OK != errorId)
    {
#if (STD_ON == DIO_DEV_ERROR_DETECT)
        (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_WRITE_PORT_SID,
                              errorId);
#endif /** #if (STD_ON == DIO_DEV_ERROR_DETECT) */
#if (STD_ON == DIO_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_WRITE_PORT_SID,
                                   errorId);
#endif /** #if (STD_ON == DIO_SAFETY_ENABLE) */
    } /* else not needed */

#endif /** #if ((STD_ON == DIO_DEV_ERROR_DETECT) || (STD_ON == DIO_SAFETY_ENABLE)) */

}

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
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType *ChannelGroupIdPtr)
{
    Dio_PortLevelType retVal = (Dio_PortLevelType) STD_LOW;
    Std_ReturnType errorId = (Std_ReturnType)E_OK;
    uint32 mask = 0xffffffffUL;

    /* #10 Check parameter */
    if ((NULL_PTR == ChannelGroupIdPtr) ||
            (DIO_MAXNOOFPORT <  ChannelGroupIdPtr->port) ||
            (DIO_MAXOFFSET <  ChannelGroupIdPtr->offset))
    {
        errorId = (Std_ReturnType)DIO_E_PARAM_INVALID_GROUP;
    } /* else not needed */

    if ((Std_ReturnType)E_OK == errorId)
    {
        /* #20 Read group level */
        retVal = Dio_Ip_ReadChannelGroup(ChannelGroupIdPtr);
        /* #30 Check return value */
        if (0UL != (retVal & (~(mask >> ChannelGroupIdPtr->offset))))
        {
            retVal = (Dio_PortLevelType) STD_LOW;
            errorId = (Std_ReturnType)DIO_E_RETURN_INVALID_GROUP_LEVEL;
        } /* else not needed */
    }

#if ((STD_ON == DIO_DEV_ERROR_DETECT) || (STD_ON == DIO_SAFETY_ENABLE))

    if ((Std_ReturnType)E_OK != errorId)
    {
#if (STD_ON == DIO_DEV_ERROR_DETECT)
        (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_READ_CHANNEL_GROUP_SID,
                              errorId);
#endif /** #if (STD_ON == DIO_DEV_ERROR_DETECT) */
#if (STD_ON == DIO_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_READ_CHANNEL_GROUP_SID,
                                   errorId);
#endif /** #if (STD_ON == DIO_SAFETY_ENABLE) */
    } /* else not needed */

#endif /** #if ((STD_ON == DIO_DEV_ERROR_DETECT) || (STD_ON == DIO_SAFETY_ENABLE)) */
    return retVal;
}

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
void Dio_WriteChannelGroup(const Dio_ChannelGroupType *ChannelGroupIdPtr, Dio_PortLevelType Level)
{
    Std_ReturnType errorId = (Std_ReturnType)E_OK;

    /* #10 Check parameter */
    if ((NULL_PTR == ChannelGroupIdPtr) ||
            (DIO_MAXNOOFPORT <  ChannelGroupIdPtr->port) ||
            (DIO_MAXOFFSET <  ChannelGroupIdPtr->offset))
    {
        errorId = (Std_ReturnType)DIO_E_PARAM_INVALID_GROUP;
    } /* else not needed */

    if ((Std_ReturnType)E_OK == errorId)
    {
        /* #20 Write group level */
        Dio_Ip_WriteChannelGroup(ChannelGroupIdPtr, Level);
    }

#if ((STD_ON == DIO_DEV_ERROR_DETECT) || (STD_ON == DIO_SAFETY_ENABLE))

    if ((Std_ReturnType)E_OK != errorId)
    {
#if (STD_ON == DIO_DEV_ERROR_DETECT)
        (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_WRITE_CHANNEL_GROUP_SID,
                              errorId);
#endif /** #if (STD_ON == DIO_DEV_ERROR_DETECT) */
#if (STD_ON == DIO_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_WRITE_CHANNEL_GROUP_SID,
                                   errorId);
#endif /** #if (STD_ON == DIO_SAFETY_ENABLE) */
    }

#endif /** #if ((STD_ON == DIO_DEV_ERROR_DETECT) || (STD_ON == DIO_SAFETY_ENABLE)) */
}

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
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
    Dio_LevelType retVal;
    Std_ReturnType errorId;

    /* #10 Check channel ID */
    errorId = Dio_ValidateChannel(ChannelId);

    if ((Std_ReturnType)E_OK == errorId)
    {
        /* #20 Flip channel level,get fliped level*/
        retVal = Dio_Ip_FlipChannel(ChannelId);

        /* #30 check return level */
        errorId = Dio_ValidateLevel(retVal);
    } /* else not needed */


    if ((Std_ReturnType)E_OK != errorId)
    {
        retVal = (Dio_LevelType)STD_LOW;
#if (STD_ON == DIO_DEV_ERROR_DETECT)
        (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_FLIP_CHANNEL_SID,
                              errorId);
#endif /** #if (STD_ON == DIO_DEV_ERROR_DETECT) */
#if (STD_ON == DIO_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_FLIP_CHANNEL_SID,
                                   errorId);
#endif /** #if (STD_ON == DIO_SAFETY_ENABLE) */
    } /* else not needed */

    return retVal;
}
#endif /** #if (STD_ON == DIO_FLIP_CHANNEL_API) */

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
void Dio_GetVersionInfo(Std_VersionInfoType *versionInfo)
{
    /* #10 Check parameter */
    if (NULL_PTR == versionInfo)
    {
#if (STD_ON == DIO_DEV_ERROR_DETECT)
        (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_GET_VERSION_INFO_SID,
                              DIO_E_PARAM_POINTER);
#endif /** #if (STD_ON == DIO_DEV_ERROR_DETECT) */
#if (STD_ON == DIO_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_GET_VERSION_INFO_SID,
                                   DIO_E_PARAM_POINTER);
#endif /** #if (STD_ON == DIO_SAFETY_ENABLE) */
    }
    else
    {
        /* #20 Structure assignment */
        versionInfo->vendorID = DIO_VENDOR_ID;
        versionInfo->moduleID = DIO_MODULE_ID;
        versionInfo->sw_major_version = DIO_SW_MAJOR_VERSION;
        versionInfo->sw_minor_version = DIO_SW_MINOR_VERSION;
        versionInfo->sw_patch_version = DIO_SW_PATCH_VERSION;
    }
}
#endif /** #if (DIO_VERSION_INFO_API == STD_ON) */

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
void Dio_SetPinInterruptDetect(Dio_ChannelType ChannelId, Dio_DetectionType InterruptType)
{
    Std_ReturnType errorId = (Std_ReturnType)E_OK;

    /* #10 Check parameter */
    if (InterruptType > DIO_ASYNC_NONE)
    {
        errorId = (Std_ReturnType)DIO_E_PARAM_INVALID_INT_TYPE;
    } /* else not needed */

    if ((Std_ReturnType)E_OK == errorId)
    {
        errorId = Dio_ValidateChannel(ChannelId);

        if ((Std_ReturnType)E_OK == errorId)
        {
            /* #20 Config interrupt mode */
            if (InterruptType <= DIO_SYNC_NONE)
            {
                /* #30 Config synchronous interrupt mode */
                errorId = Dio_Ip_EnablePinInterruptDetect(ChannelId, InterruptType);
            }
            else
            {
                /* #40 Config asynchronous interrupt mode */
                errorId = Dio_Ip_EnableAsyncInterruptDetect(ChannelId, InterruptType);
            }
        } /* else not needed */
    } /* else not needed */

#if ((STD_ON == DIO_DEV_ERROR_DETECT) || (STD_ON == DIO_SAFETY_ENABLE))

    if ((Std_ReturnType)E_OK != errorId)
    {
#if (STD_ON == DIO_DEV_ERROR_DETECT)
        (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_SET_PIN_INTERRUPT_DETECT_SID,
                              errorId);
#endif /** #if (STD_ON == DIO_DEV_ERROR_DETECT) */
#if (STD_ON == DIO_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_SET_PIN_INTERRUPT_DETECT_SID,
                                   errorId);
#endif /** #if (STD_ON == DIO_SAFETY_ENABLE) */
    } /* else not needed */

#endif /** #if ((STD_ON == DIO_DEV_ERROR_DETECT) || (STD_ON == DIO_SAFETY_ENABLE)) */

}

#define DIO_ISR(id) \
ISR(DIO_Irq##id##Handler)\
{\
    Dio_Ip_IrqHandler(((uint8)id##U) - ((uint8)1));\
    DioHook_Dio_IrqTime();\
}

/** *****************************************************************************************************
 * \brief Dio captures external levels and triggers interrupts.
 *
 * \verbatim
 * Syntax             : void DIO_Irq1Handler(void)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
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
 *******************************************************************************************************/
DIO_ISR(1)

/** *****************************************************************************************************
 * \brief Dio captures external levels and triggers interrupts.
 *
 * \verbatim
 * Syntax             : void DIO_Irq2Handler(void)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
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
 *******************************************************************************************************/
DIO_ISR(2)

/** *****************************************************************************************************
 * \brief Dio captures external levels and triggers interrupts.
 *
 * \verbatim
 * Syntax             : void DIO_Irq3Handler(void)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
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
 *******************************************************************************************************/
DIO_ISR(3)

/** *****************************************************************************************************
 * \brief Dio captures external levels and triggers interrupts.
 *
 * \verbatim
 * Syntax             : void DIO_Irq4Handler(void)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
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
 *******************************************************************************************************/
DIO_ISR(4)

/** *****************************************************************************************************
 * \brief Dio captures external levels and triggers interrupts.
 *
 * \verbatim
 * Syntax             : void DIO_Irq5Handler(void)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
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
 *******************************************************************************************************/
DIO_ISR(5)

/** *****************************************************************************************************
 * \brief Dio captures external levels and triggers interrupts.
 *
 * \verbatim
 * Syntax             : ISR(DIO_SFIrqHandler)
 *
 * Service ID[hex]    : 0x13
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
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
 *******************************************************************************************************/
ISR(DIO_SFIrqHandler)
{
    uint32 i;
    boolean sta;

    /* #10 SF domain IRQ polling */
    for (i = 0UL; i < DIO_SF_PORT_NUM; i++)
    {
        sta = Dio_IP_GetInterruptSta(i);
        if (TRUE == sta)
        {
            Dio_Ip_IrqHandler(i);
        }
    }
}

#ifndef SEMIDRIVE_E3_LITE_SERIES
/** *****************************************************************************************************
 * \brief Dio captures external levels and triggers interrupts.
 *
 * \verbatim
 * Syntax             : void DIO_IrqH6andler(void)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
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
 *******************************************************************************************************/
DIO_ISR(6)

/** *****************************************************************************************************
 * \brief Dio captures external levels and triggers interrupts.
 *
 * \verbatim
 * Syntax             : void DIO_Irq7Handler(void)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
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
 *******************************************************************************************************/
DIO_ISR(7)

/** *****************************************************************************************************
 * \brief Dio captures external levels and triggers interrupts.
 *
 * \verbatim
 * Syntax             : void DIO_Irq8Handler(void)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
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
 *******************************************************************************************************/
DIO_ISR(8)

/** *****************************************************************************************************
 * \brief Dio captures external levels and triggers interrupts.
 *
 * \verbatim
 * Syntax             : ISR(DIO_APIrqHandler)
 *
 * Service ID[hex]    : 0x14
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
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
 *******************************************************************************************************/
ISR(DIO_APIrqHandler)
{
    uint32 i;
    boolean sta;

    /* #10 AP domain IRQ polling */
    for (i = 0UL; i < DIO_AP_PORT_NUM; i++)
    {
        sta = Dio_IP_GetInterruptSta(i + DIO_SF_PORT_NUM);
        if (TRUE == sta)
        {
            Dio_Ip_IrqHandler(i + DIO_SF_PORT_NUM);
        }
    }
}
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES */

#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"

/* End of file */
