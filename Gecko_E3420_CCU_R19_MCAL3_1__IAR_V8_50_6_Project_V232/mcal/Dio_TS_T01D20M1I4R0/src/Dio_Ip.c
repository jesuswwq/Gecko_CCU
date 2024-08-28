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
 *  \file     Dio_IP.c                                                                                  *
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
#include "Dio_Ip.h"
#include "RegHelper.h"
#include "SchM_Dio.h"
#include "Dio_Irq.h"
#include "Dio_Fault.h"

#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"

/********************************************************************************************************
 *                                  Private Function Declarations                                       *
 *******************************************************************************************************/
/** *****************************************************************************************************
 * Syntax             : uint8 Dio_Ip_GetLowestInterruptBitPos(
 *                          uint32 reg)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : reg - Interrupt status
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : uint8 - Bit tag number.
 *
 * Description        : Obtain which bit in the interrupt state is 1
 *******************************************************************************************************/
static uint8 Dio_Ip_GetLowestInterruptBitPos(uint32 reg)
{
    uint8 pos = 0U;
    uint32 regVal = reg;

    /* #10 get low interrupt bit pos */
    while ((regVal & 0x01UL) == 0x0UL)
    {
        regVal >>= 1UL;
        ++pos;
    }

    return pos;
}

/** *****************************************************************************************************
 * Syntax             : static inline uint32 Dio_IP_GetBasePerChannel(
 *                          Dio_ChannelType *channel)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : channel * - Pointer to channel ID
 *
 * Parameters (out)   : None
 *
 * Return value       : Address - DIO base address
 *
 * Description        : Get DIO base address.
 *******************************************************************************************************/
LOCAL_INLINE uint32 Dio_IP_GetBasePerChannel(Dio_ChannelType *channel)
{
    uint32 baseAddr = 0;

    if (NULL_PTR != channel)
    {
        if (DIO_SF_CHANNEL_NUM > *channel)
        {
            baseAddr = APB_DIO_SF_BASE;
        }
        else
        {
#ifndef SEMIDRIVE_E3_LITE_SERIES
            *channel -= DIO_SF_CHANNEL_NUM;
            baseAddr = APB_DIO_AP_BASE;
#endif
        }
    } /* else not needed */

    return baseAddr;
}

/** *****************************************************************************************************
 * Syntax             : static inline uint32 Dio_IP_GetBasePerPort(
 *                          Dio_PortType *port)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : port * - Pointer to port ID
 *
 * Parameters (out)   : None
 *
 * Return value       : Address - DIO base address
 *
 * Description        : Get DIO base address.
 *******************************************************************************************************/
LOCAL_INLINE uint32 Dio_IP_GetBasePerPort(Dio_PortType *port)
{
    uint32 baseAddr = 0;

    if (NULL_PTR != port)
    {
        if (DIO_SF_PORT_NUM > *port)
        {
            baseAddr = APB_DIO_SF_BASE;
        }
        else
        {
#ifndef SEMIDRIVE_E3_LITE_SERIES
            *port -= DIO_SF_PORT_NUM;
            baseAddr = APB_DIO_AP_BASE;
#endif
        }

    } /* else not needed */

    return baseAddr;
}

/** *****************************************************************************************************
 * Syntax             : boolean Dio_IP_GetInterruptSta(
 *                          Dio_PortType portId)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : portId  -  port ID
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Interrupt status bool
 *
 * Description        : Get DIO Interrupt status
 *******************************************************************************************************/
boolean Dio_IP_GetInterruptSta(Dio_PortType portId)
{
    uint32 baseAddr;
    uint32 registerVal;
    Dio_PortType dioPortId = portId;
    boolean Irqstatus = FALSE;

    baseAddr = Dio_IP_GetBasePerPort(&dioPortId);

    registerVal = REG_READ32(baseAddr + DIO_SINT_STATUS_PORT_X(dioPortId));
    registerVal |= REG_READ32(baseAddr + DIO_AINT_STATUS_PORT_X(dioPortId));

    if (0UL < registerVal)
    {
        Irqstatus = TRUE;
    }

    return Irqstatus;
}

/** *****************************************************************************************************
 * Syntax             : Std_ReturnType Dio_ValidateChannel(
 *                              Dio_ChannelType channelId)
 *
 * Service ID[hex]    : None
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
 * Return value       : Error ID or E_NOT_OK
 *
 * Description        : Verify whether the channelID is correct,
 *                      and return E_NOT_OK if it is correct, otherwise return Error ID.
 *
 * Traceability       : SW_SM006
 *******************************************************************************************************/
Std_ReturnType Dio_ValidateChannel(const Dio_ChannelType channelId)
{
    Std_ReturnType errorId = (Std_ReturnType)E_OK;

    /* #10 validate channel ID */
    if (DIO_MAXNOOFCHANNEL <= channelId)
    {
        errorId = (Std_ReturnType)DIO_E_PARAM_INVALID_CHANNEL_ID;
    } /* else not needed */

    return errorId;
}

/** *****************************************************************************************************
 * Syntax             : Std_ReturnType Dio_ValidatePort(
 *                              Dio_ChannelType portId)
 *
 * Service ID[hex]    : None
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
 * Return value       : Error ID or E_NOT_OK
 *
 * Description        : Verify whether the portId is correct,
 *                      and return E_NOT_OK if it is correct, otherwise return Error ID.
 *
 * Traceability       : SW_SM006
 *******************************************************************************************************/
Std_ReturnType Dio_ValidatePort(const Dio_PortType portId)
{
    Std_ReturnType errorId = (Std_ReturnType)E_OK;

    /* #10 validate port ID ID */
    if (DIO_MAXNOOFPORT < portId)
    {
        errorId = (Std_ReturnType)DIO_E_PARAM_INVALID_PORT_ID;
    } /* else not needed */

    return errorId;
}

/** *****************************************************************************************************
 * Syntax             : Std_ReturnType Dio_ValidateLevel(
 *                              Dio_ChannelType level)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : Level - Value to be written
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Error ID or E_NOT_OK
 *
 * Description        : Verify whether the level is correct,
 *                      and return E_NOT_OK if it is correct, otherwise return Error ID.
 *
 * Traceability       : SW_SM006
 *******************************************************************************************************/
Std_ReturnType Dio_ValidateLevel(const Dio_LevelType level)
{
    Std_ReturnType errorId = (Std_ReturnType)E_OK;

    /* #10 validate level */
    if (((Dio_LevelType)STD_LOW != level) &&
            ((Dio_LevelType)STD_HIGH != level))
    {
        errorId = (Std_ReturnType)DIO_E_INVALID_CHANNEL_LEVEL;
    } /* else not needed */

    return errorId;
}

/** *****************************************************************************************************
 * Syntax             : void Dio_ValidateInterrupt(
 *                              const uint32 portId, const uint32 baseAddr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Rreentrant
 *
 * Parameters (in)    : portId - ID of DIO Port
 *                      baseAddr - dio base address
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Check if the interrupt is expected,
 *                      and if it is unexpected, clear the interrupt status bit.
 *
 * Traceability       : SWSR_DIO_075 SW_SM004
 *******************************************************************************************************/
static void Dio_ValidateInterrupt(const uint32 portId, const uint32 baseAddr)
{
    uint32 registerVal;
    uint32 interruptEnableBits;
    uint32 maskBit;

    /* #10 get sint status */
    registerVal = REG_READ32(baseAddr + DIO_SINT_STATUS_PORT_X(portId));

    /* Error Inject Point */
    DioHook_Dio_UnexpectedInterruption();

    /* #20 get sint enable bits */
    interruptEnableBits = REG_READ32(baseAddr + DIO_SINT_EN_PORT_X(portId));

    /* #30 mask status */
    maskBit = registerVal & (~interruptEnableBits);
    REG_WRITE32(maskBit, baseAddr + DIO_SINT_MASK_PORT_X(portId) + DIO_SET_PIN);

    /* #40 get asint status */
    registerVal = REG_READ32(baseAddr + DIO_AINT_STATUS_PORT_X(portId));

    /* Error Inject Point */
    DioHook_Dio_UnexpectedInterruption();

    /* #50 get asint enable bits */
    interruptEnableBits = REG_READ32(baseAddr + DIO_AINT_EN_PORT_X(portId));

    /* #60 async mask status */
    maskBit = registerVal & (~interruptEnableBits);
    REG_WRITE32(maskBit, baseAddr + DIO_AINT_MASK_PORT_X(portId) + DIO_SET_PIN);

    ASM_KEYWORD("dsb sy");
}

/** *****************************************************************************************************
 * Syntax             : Dio_LevelType Dio_Ip_ReadChannel(
 *                          Dio_ChannelType ChannelId )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : ChannelId - ID of DIO channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : port * - Pointer to port ID
 *
 * Return value       : Dio_LevelType - STD_HIGH The physical level of the
 *                      corresponding Pin is STD_HIGH
 *                      - STD_LOW The physical level of the corresponding Pin
 *                      is STD_LOW.
 *
 * Description        : Returns the value of the specified DIO channel.
 * Traceability       : SWSR_DIO_001 SWSR_DIO_003 SWSR_DIO_004 SWSR_DIO_008
 *                      SWSR_DIO_020 SWSR_DIO_022 SWSR_DIO_025
 *******************************************************************************************************/
Dio_LevelType Dio_Ip_ReadChannel(Dio_ChannelType channelId)
{
    uint32 registerVal;
    uint32 gpioBaseAddr;
    Dio_LevelType retVal = (Dio_LevelType)STD_LOW;
    Std_ReturnType errorId;
    Dio_ChannelType dioChannelId = channelId;

    /* #10 get base address */
    gpioBaseAddr = Dio_IP_GetBasePerChannel(&dioChannelId);

    /* #20 validate base address and dioChannelId id */
    errorId = Dio_ValidateChannel(dioChannelId);

    if ((Std_ReturnType)E_OK == errorId)
    {
        /* #30 get dioChannelId level */
        registerVal = REG_READ32(gpioBaseAddr + DIO_DATA_IN_PORT_X(PIN_OFFSET((uint32)dioChannelId)));

        /* #40 decide the return value */
        if (0UL != (registerVal & (uint32)(0x01UL << PIN_BIT((uint32)dioChannelId))))
        {
            retVal = (Dio_LevelType)STD_HIGH;
        } /* else not needed */
    } /* else not needed */

    if ((Std_ReturnType)E_OK != errorId)
    {
        retVal = (Dio_LevelType)DIO_E_PARAM_INVALID_CHANNEL_ID;
    } /* else not needed */

    return retVal;
}

/** *****************************************************************************************************
 *  Syntax            : Std_ReturnType Dio_Ip_WriteChannel( Dio_ChannelType ChannelId,
 *                                             Dio_LevelType Level )
 *
 * Service ID[hex]    : None
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
 * Return value       : Whether the write was successful.
 *
 * Description        : Service to set a level of a channel.
 * Traceability       : SWSR_DIO_001 SWSR_DIO_002 SWSR_DIO_003 SWSR_DIO_004
 *                      SWSR_DIO_008 SWSR_DIO_015 SWSR_DIO_017 SW_SM007
 *******************************************************************************************************/
Std_ReturnType Dio_Ip_WriteChannel(Dio_ChannelType channelId, Dio_LevelType level)
{
    uint32 gpioBaseAddr;
    Std_ReturnType errorId;
    Dio_ChannelType dioChannelId = channelId;

    /* #10 get base address */
    gpioBaseAddr = Dio_IP_GetBasePerChannel(&dioChannelId);

    /* #20 validate base address and dioChannelId id */
    errorId = Dio_ValidateChannel(dioChannelId);

    if ((Std_ReturnType)E_OK == errorId)
    {
        /* #30 Write dioChannelId level */
        if ((Dio_LevelType)STD_HIGH == level)
        {
            REG_WRITE32((uint32)0x01U << PIN_BIT((uint32)dioChannelId),
                        gpioBaseAddr + DIO_DATA_OUT_PORT_X(PIN_OFFSET((uint32)dioChannelId)) + DIO_SET_PIN);
        }
            else if ((Dio_LevelType)STD_LOW == level)
        {
            REG_WRITE32((uint32)0x01U << PIN_BIT((uint32)dioChannelId),
                        gpioBaseAddr + DIO_DATA_OUT_PORT_X(PIN_OFFSET((uint32)dioChannelId)) + DIO_CLEAR_PIN);
        }
        else
        {
            /* else not needed */
        }
    } /* else not needed */

    return errorId;
}

/** *****************************************************************************************************
 * Syntax             : Dio_PortLevelType Dio_Ip_ReadPort( Dio_PortType PortId )
 *
 * Service ID[hex]    : None
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
 * Traceability       : SWSR_DIO_001 SWSR_DIO_002 SWSR_DIO_006 SWSR_DIO_007
 *                      SWSR_DIO_008 SWSR_DIO_020 SWSR_DIO_023 SWSR_DIO_025
 *                      SWSR_DIO_076 SWSR_DIO_078
 *******************************************************************************************************/
Dio_PortLevelType Dio_Ip_ReadPort(Dio_PortType portId)
{
    Dio_PortLevelType retVal;
    uint32 gpioBaseAddr;
    Dio_PortType port = portId;

    /* #10 get base address */
    gpioBaseAddr = Dio_IP_GetBasePerPort(&port);

    /* #20 get port level */
    retVal = (Dio_PortLevelType)(REG_READ32(gpioBaseAddr + (uint32)DIO_DATA_IN_PORT_X((uint32)port)));

    return retVal;
}

/** *****************************************************************************************************
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
 * Traceability       : SWSR_DIO_001 SWSR_DIO_002 SWSR_DIO_006 SWSR_DIO_007
 *                      SWSR_DIO_008 SWSR_DIO_015 SWSR_DIO_018 SWSR_DIO_019
 *                      SWSR_DIO_076 SWSR_DIO_078
 *******************************************************************************************************/
Std_ReturnType Dio_Ip_WritePort(Dio_PortType portId, Dio_PortLevelType level)
{
    uint32 gpioBaseAddr;
    Dio_PortType port = portId;
    Std_ReturnType errorId;

    /* #10 get base address */
    gpioBaseAddr = Dio_IP_GetBasePerPort(&port);

    /* #20 validate portID/BaseAaddress */
    errorId = Dio_ValidatePort(port);

    if ((Std_ReturnType)E_OK == errorId)
    {
        /* #30 Write port level */
        REG_WRITE32(level, gpioBaseAddr + DIO_DATA_OUT_PORT_X(port));
    } /* else not needed */

    return errorId;
}

/** *****************************************************************************************************
 * Syntax             : Dio_PortLevelType Dio_Ip_ReadChannelGroup(
 *                              const Dio_ChannelGroupType* ChannelGroupIdPtr )
 *
 * Service ID[hex]    : None
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
 * Traceability       : SWSR_DIO_001 SWSR_DIO_002 SWSR_DIO_008 SWSR_DIO_020
 *                      SWSR_DIO_024 SWSR_DIO_025
 *******************************************************************************************************/
Dio_PortLevelType Dio_Ip_ReadChannelGroup(const Dio_ChannelGroupType *channelGroupIdPtr)
{
    uint32 registerVal;
    Dio_PortLevelType retVal;

    /* read ChannelGroup data in */
    /* #10 Determine if it is an SF domain DIO */
    if (DIO_SF_PORT_NUM > channelGroupIdPtr->port)
    {
        /* #20 Get port level */
        registerVal = REG_READ32((uint32)APB_DIO_SF_BASE + (uint32)DIO_DATA_IN_PORT_X(
                                     channelGroupIdPtr->port));
        /* #30 Calculate val */
        retVal = (Dio_PortLevelType)(((uint32)registerVal & (uint32)channelGroupIdPtr->mask) >>
                                     channelGroupIdPtr->offset);
    }
    /* #40 AP domain DIO */
    else
    {
#ifndef SEMIDRIVE_E3_LITE_SERIES
        /* #50 Get port level */
        registerVal = REG_READ32(APB_DIO_AP_BASE + (uint32)DIO_DATA_IN_PORT_X(channelGroupIdPtr->port -
                                 (uint32)DIO_SF_PORT_NUM));
        /* #60 Calculate val */
        retVal = (Dio_PortLevelType)(((uint32)registerVal & (uint32)channelGroupIdPtr->mask) >>
                                     channelGroupIdPtr->offset);
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES */
    }

    return retVal;
}

/** *****************************************************************************************************
 * Syntax             : void Dio_Ip_WriteChannelGroup( const Dio_ChannelGroupType*
 *                              ChannelGroupIdPtr, Dio_PortLevelType Level )
 *
 * Service ID[hex]    : None
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
 * Traceability       : SWSR_DIO_001 SWSR_DIO_002 SWSR_DIO_008 SWSR_DIO_015
 *                      SW_SM007
 *******************************************************************************************************/
void Dio_Ip_WriteChannelGroup(const Dio_ChannelGroupType *channelGroupIdPtr,
                              Dio_PortLevelType level)
{
    uint32 portVal;
    uint32 registerVal;

    /* #10 Calculate Write Val. */
    portVal = (uint32)(((uint32)level << (uint32)channelGroupIdPtr->offset) &
                       (uint32) channelGroupIdPtr->mask);

    /* #20 Enter exclusive area. */
    SchM_Enter_Dio_DIO_EXCLUSIVE_AREA_00();

    /* #30 Determine if it is an SF domain DIO */
    if (DIO_SF_PORT_NUM > channelGroupIdPtr->port)
    {
        /* #40 read the DATA out first */
        registerVal = REG_READ32(APB_DIO_SF_BASE + DIO_DATA_OUT_PORT_X(channelGroupIdPtr->port));
        registerVal &= (~((uint32) channelGroupIdPtr->mask));
        /* #50 write the ChannelGroup data out */
        REG_WRITE32((registerVal | portVal),
                    APB_DIO_SF_BASE + DIO_DATA_OUT_PORT_X(channelGroupIdPtr->port));
    }
    /* #60 AP domain DIO */
    else
    {
#ifndef SEMIDRIVE_E3_LITE_SERIES
        /* #70 read the DATA out first */
        registerVal = REG_READ32(APB_DIO_AP_BASE + DIO_DATA_OUT_PORT_X(channelGroupIdPtr->port -
                                 (uint32)DIO_SF_PORT_NUM));
        registerVal &= (~((uint32) channelGroupIdPtr->mask));
        /* #80 write the ChannelGroup data out */
        REG_WRITE32((registerVal | portVal),
                    APB_DIO_AP_BASE + DIO_DATA_OUT_PORT_X(channelGroupIdPtr->port - (uint32)DIO_SF_PORT_NUM));
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES */
    }

    /* #90 Exit exclusive area. */
    SchM_Exit_Dio_DIO_EXCLUSIVE_AREA_00();
}


#if (DIO_FLIP_CHANNEL_API == STD_ON)
/** *****************************************************************************************************
 * Syntax             : Dio_LevelType Dio_Ip_FlipChannel(
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
 * Traceability       : SWSR_DIO_001 SWSR_DIO_002 SWSR_DIO_003 SWSR_DIO_004
 *                      SWSR_DIO_008 SWSR_DIO_015 SWSR_DIO_025 SWSR_DIO_076
 *                      SWSR_DIO_078 SW_SM007
 *******************************************************************************************************/
Dio_LevelType Dio_Ip_FlipChannel(Dio_ChannelType channelId)
{
    Dio_LevelType retVal;
    uint32 registerVal;
    uint32 gpioBaseAddr;
    Std_ReturnType errorId;
    Dio_ChannelType dioChannelId = channelId;

    /* #10 get base address */
    gpioBaseAddr = Dio_IP_GetBasePerChannel(&dioChannelId);

    /* #20 validate channelID/baseaddress. */
    errorId = Dio_ValidateChannel(dioChannelId);

    if ((Std_ReturnType)E_OK != errorId)
    {
        retVal = 0xffffffffUL;
    }
    else
    {
        /* #30 flip the dioChannelId */
        SchM_Enter_Dio_DIO_EXCLUSIVE_AREA_00();
        REG_WRITE32((uint32)0x01U << PIN_BIT((uint32)dioChannelId),
                    gpioBaseAddr + DIO_DATA_OUT_PORT_X(PIN_OFFSET((uint32)dioChannelId)) + DIO_TOGGLE_PIN);

        /* #40 read the data in flipped */
        registerVal = REG_READ32(gpioBaseAddr + DIO_DATA_OUT_PORT_X(PIN_OFFSET((uint32)dioChannelId))) &
                        (0x01UL << PIN_BIT((uint32)dioChannelId));
        retVal = (Dio_LevelType)(registerVal >> PIN_BIT((uint32)dioChannelId));
        SchM_Exit_Dio_DIO_EXCLUSIVE_AREA_00();
    }

    return retVal;
}
#endif

/** *****************************************************************************************************
 * Syntax             : void Dio_Ip_EnablePinInterruptDetect(
 *                              Dio_ChannelType ChannelId,
 *                              Dio_DetectionType InterruptType)
 *
 * Service ID[hex]    : None
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
 * Return value       : Std_ReturnType - Whether the write was successful
 *
 * Description        : When the CPU enters hib/sleep mode,
 *                      it can only be awakened through asynchronous interrupts.
 * Traceability       : SWSR_DIO_001 SWSR_DIO_002 SWSR_DIO_004 SWSR_DIO_076 SWSR_DIO_078
 *                      SW_SM007
 *******************************************************************************************************/
Std_ReturnType Dio_Ip_EnablePinInterruptDetect(Dio_ChannelType channelId,
        Dio_DetectionType interruptType)
{
    uint32 gpioBaseAddr;
    uint32 registerVal;
    uint32 direction;
    Std_ReturnType errorId;
    Dio_ChannelType dioChannelId = channelId;

    /* #10 get base address */
    gpioBaseAddr = Dio_IP_GetBasePerChannel(&dioChannelId);

    /* #20 validate channel ID. */
    errorId = Dio_ValidateChannel(dioChannelId);

    if ((Std_ReturnType)E_OK == errorId)
    {
        /* #30 get channel direction. */
        registerVal = REG_READ32(gpioBaseAddr + DIO_OEN_PORT_X(PIN_OFFSET((uint32)dioChannelId)));

        direction = (uint32)((registerVal >> PIN_BIT((uint32)dioChannelId)) & 0x1UL);

        if ((DIO_OUTPUT == direction) ||
                (DIO_SYNC_NONE == interruptType))
        {
            /* #40 clear interrupt status */
            REG_WRITE32((uint32)0x1 << PIN_BIT((uint32)dioChannelId),
                        gpioBaseAddr + DIO_SINT_EDGE_CLR_PORT_X(PIN_OFFSET((uint32)dioChannelId)) + DIO_CLEAR_PIN);
            /* #50 disable the interrupt */
            REG_WRITE32((uint32)0x1 << PIN_BIT((uint32)dioChannelId),
                        gpioBaseAddr + DIO_SINT_EN_PORT_X(PIN_OFFSET((uint32)dioChannelId)) + DIO_CLEAR_PIN);
        }
        else
        {
            /* #60 clear last configs */
            REG_WRITE32((uint32)0x1 << PIN_BIT((uint32)dioChannelId),
                        gpioBaseAddr + DIO_SINT_EN_PORT_X(PIN_OFFSET((uint32)dioChannelId)) + DIO_CLEAR_PIN);
            REG_WRITE32((uint32)0x1U << PIN_BIT((uint32)dioChannelId),
                        gpioBaseAddr + DIO_SINT_TYPE_PORT_X(PIN_OFFSET((uint32)dioChannelId)) + DIO_CLEAR_PIN);
            REG_WRITE32((uint32)0x1U << PIN_BIT((uint32)dioChannelId),
                        gpioBaseAddr + DIO_SINT_POL_PORT_X(PIN_OFFSET((uint32)dioChannelId)) + DIO_CLEAR_PIN);
            REG_WRITE32((uint32)0x1U << PIN_BIT((uint32)dioChannelId),
                        gpioBaseAddr + DIO_SINT_BOTH_EDGE_PORT_X(PIN_OFFSET((uint32)dioChannelId)) + DIO_CLEAR_PIN);

            /* #70 config interrupt mode */
            switch (interruptType)
            {
            case DIO_SYNC_LOW_LEVEL:
                /* Configure low level interrupts according to the above three sentences */
                break;

            case DIO_SYNC_HIGH_LEVEL:
                REG_WRITE32(INT_POL_HIGH_POS << PIN_BIT((uint32)dioChannelId),
                            gpioBaseAddr + DIO_SINT_POL_PORT_X(PIN_OFFSET((uint32)dioChannelId)) + DIO_SET_PIN);
                break;

            case DIO_SYNC_RISING_EDGE:
                REG_WRITE32(INT_TYPE_PULSE << PIN_BIT((uint32)dioChannelId),
                            gpioBaseAddr + DIO_SINT_TYPE_PORT_X(PIN_OFFSET((uint32)dioChannelId)) + DIO_SET_PIN);
                REG_WRITE32(INT_POL_HIGH_POS << PIN_BIT((uint32)dioChannelId),
                            gpioBaseAddr + DIO_SINT_POL_PORT_X(PIN_OFFSET((uint32)dioChannelId)) + DIO_SET_PIN);
                break;

            case DIO_SYNC_FALLING_EDGE:
                REG_WRITE32(INT_TYPE_PULSE << PIN_BIT((uint32)dioChannelId),
                            gpioBaseAddr + DIO_SINT_TYPE_PORT_X(PIN_OFFSET((uint32)dioChannelId)) + DIO_SET_PIN);
                break;

            case DIO_SYNC_BOTH_EDGE:
                REG_WRITE32(INT_TYPE_PULSE << PIN_BIT((uint32)dioChannelId),
                            gpioBaseAddr + DIO_SINT_TYPE_PORT_X(PIN_OFFSET((uint32)dioChannelId)) + DIO_SET_PIN);
                REG_WRITE32(INT_BOE_BOTH_EDGE << PIN_BIT((uint32)dioChannelId),
                            gpioBaseAddr + DIO_SINT_BOTH_EDGE_PORT_X(PIN_OFFSET((uint32)dioChannelId)) + DIO_SET_PIN);
                break;

            default:
                /* Do Nothing */
                break;
            }

            /* #80 enable interrupt */
            /*mask interrupt */
            REG_WRITE32((uint32)0x1U << PIN_BIT((uint32)dioChannelId),
                        gpioBaseAddr + DIO_SINT_MASK_PORT_X(PIN_OFFSET((uint32)dioChannelId)) + DIO_SET_PIN);

            /* clear interrupt status */
            REG_WRITE32((uint32)0x1U << PIN_BIT((uint32)dioChannelId),
                        gpioBaseAddr + DIO_SINT_EDGE_CLR_PORT_X(PIN_OFFSET((uint32)dioChannelId)) + DIO_CLEAR_PIN);

            /* unmask interrupt */
            REG_WRITE32((uint32)0x1U << PIN_BIT((uint32)dioChannelId),
                        gpioBaseAddr + DIO_SINT_MASK_PORT_X(PIN_OFFSET((uint32)dioChannelId)) + DIO_CLEAR_PIN);

            /* enable interrupt */
            REG_WRITE32((uint32)0x1U << PIN_BIT((uint32)dioChannelId),
                        gpioBaseAddr + DIO_SINT_EN_PORT_X(PIN_OFFSET((uint32)dioChannelId)) + DIO_SET_PIN);
        } /* else not needed */
    } /* else not needed */

    return errorId;
}

/** *****************************************************************************************************
 * Syntax             : void Dio_Ip_EnableAsyncInterruptDetect(
 *                              Dio_ChannelType ChannelId,
 *                              Dio_DetectionType InterruptType)
 *
 * Service ID[hex]    : None
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
 * Return value       : Std_ReturnType - Whether the write was successful
 *
 * Description        : When the CPU enters hib/sleep mode,
 *                      it can only be awakened through asynchronous interrupts.
 * Traceability       : SWSR_DIO_001 SWSR_DIO_002 SWSR_DIO_004 SWSR_DIO_076 SWSR_DIO_078
 *                      SW_SM007
 *******************************************************************************************************/
Std_ReturnType Dio_Ip_EnableAsyncInterruptDetect(Dio_ChannelType channelId,
        Dio_DetectionType interruptType)
{
    uint32 gpioBaseAddr;
    uint32 registerVal;
    uint32 direction;
    Std_ReturnType errorId;
    Dio_ChannelType dioChannelId = channelId;

    /* #10 get base address */
    gpioBaseAddr = Dio_IP_GetBasePerChannel(&dioChannelId);

    /* #20 validate channel ID. */
    errorId = Dio_ValidateChannel(dioChannelId);

    if ((Std_ReturnType)E_OK == errorId)
    {
        /* #30 get channel direction. */
        registerVal = REG_READ32(gpioBaseAddr + DIO_OEN_PORT_X(PIN_OFFSET((uint32)dioChannelId)));

        direction = (uint32)((registerVal >> PIN_BIT((uint32)dioChannelId)) & 0x1UL);

        if ((DIO_OUTPUT == direction) ||
                (DIO_ASYNC_NONE == interruptType))
        {
            /* #40 clear interrupt status */
            REG_WRITE32((uint32)0x1 << PIN_BIT((uint32)dioChannelId),
                        gpioBaseAddr + DIO_AINT_EDGE_CLR_PORT_X(PIN_OFFSET((uint32)dioChannelId)) + DIO_CLEAR_PIN);
            /* #50 disable the interrupt */
            REG_WRITE32((uint32)0x1 << PIN_BIT((uint32)dioChannelId),
                        gpioBaseAddr + DIO_AINT_EN_PORT_X(PIN_OFFSET((uint32)dioChannelId)) + DIO_CLEAR_PIN);
        }
        else
        {
            /* #60 clear last configs */
            REG_WRITE32((uint32)0x1 << PIN_BIT((uint32)dioChannelId),
                        gpioBaseAddr + DIO_AINT_EN_PORT_X(PIN_OFFSET((uint32)dioChannelId)) + DIO_CLEAR_PIN);
            REG_WRITE32((uint32)0x1U << PIN_BIT((uint32)dioChannelId),
                        gpioBaseAddr + DIO_AINT_TYPE_PORT_X(PIN_OFFSET((uint32)dioChannelId)) + DIO_CLEAR_PIN);
            REG_WRITE32((uint32)0x1U << PIN_BIT((uint32)dioChannelId),
                        gpioBaseAddr + DIO_AINT_POL_PORT_X(PIN_OFFSET((uint32)dioChannelId)) + DIO_CLEAR_PIN);
            REG_WRITE32((uint32)0x1U << PIN_BIT((uint32)dioChannelId),
                        gpioBaseAddr + DIO_AINT_BOTH_EDGE_PORT_X(PIN_OFFSET((uint32)dioChannelId)) + DIO_CLEAR_PIN);

            /* #70 config interrupt mode */
            switch (interruptType)
            {
            case DIO_ASYNC_LOW_LEVEL:
                /* Configure low level interrupts according to the above three sentences */
                break;

            case DIO_ASYNC_HIGH_LEVEL:
                REG_WRITE32(INT_POL_HIGH_POS << PIN_BIT((uint32)dioChannelId),
                            gpioBaseAddr + DIO_AINT_POL_PORT_X(PIN_OFFSET((uint32)dioChannelId)) + DIO_SET_PIN);
                break;

            case DIO_ASYNC_RISING_EDGE:
                REG_WRITE32(INT_TYPE_PULSE << PIN_BIT((uint32)dioChannelId),
                            gpioBaseAddr + DIO_AINT_TYPE_PORT_X(PIN_OFFSET((uint32)dioChannelId)) + DIO_SET_PIN);
                REG_WRITE32(INT_POL_HIGH_POS << PIN_BIT((uint32)dioChannelId),
                            gpioBaseAddr + DIO_AINT_POL_PORT_X(PIN_OFFSET((uint32)dioChannelId)) + DIO_SET_PIN);
                break;

            case DIO_ASYNC_FALLING_EDGE:
                REG_WRITE32(INT_TYPE_PULSE << PIN_BIT((uint32)dioChannelId),
                            gpioBaseAddr + DIO_AINT_TYPE_PORT_X(PIN_OFFSET((uint32)dioChannelId)) + DIO_SET_PIN);
                break;

            case DIO_ASYNC_BOTH_EDGE:
                REG_WRITE32(INT_TYPE_PULSE << PIN_BIT((uint32)dioChannelId),
                            gpioBaseAddr + DIO_AINT_TYPE_PORT_X(PIN_OFFSET((uint32)dioChannelId)) + DIO_SET_PIN);
                REG_WRITE32(INT_BOE_BOTH_EDGE << PIN_BIT((uint32)dioChannelId),
                            gpioBaseAddr + DIO_AINT_BOTH_EDGE_PORT_X(PIN_OFFSET((uint32)dioChannelId)) + DIO_SET_PIN);
                break;

            default:
                /* Do Nothing */
                break;
            }

            /* #80 enable interrupt */
            /*mask interrupt */
            REG_WRITE32((uint32)0x1U << PIN_BIT((uint32)dioChannelId),
                        gpioBaseAddr + DIO_AINT_MASK_PORT_X(PIN_OFFSET((uint32)dioChannelId)) + DIO_SET_PIN);

            /* clear interrupt status */
            REG_WRITE32((uint32)0x1U << PIN_BIT((uint32)dioChannelId),
                        gpioBaseAddr + DIO_AINT_EDGE_CLR_PORT_X(PIN_OFFSET((uint32)dioChannelId)) + DIO_CLEAR_PIN);

            /* unmask interrupt */
            REG_WRITE32((uint32)0x1U << PIN_BIT((uint32)dioChannelId),
                        gpioBaseAddr + DIO_AINT_MASK_PORT_X(PIN_OFFSET((uint32)dioChannelId)) + DIO_CLEAR_PIN);

            /* enable interrupt */
            REG_WRITE32((uint32)0x1U << PIN_BIT((uint32)dioChannelId),
                        gpioBaseAddr + DIO_AINT_EN_PORT_X(PIN_OFFSET((uint32)dioChannelId)) + DIO_SET_PIN);
        }
    } /* else not needed */

    return errorId;
}

/** *****************************************************************************************************
 * Syntax             : void Dio_Ip_IrqHandler(
 *                              uint32 portId)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : portId - ID of DIO Port
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Interrupt handling function.
 * Traceability       : SWSR_DIO_001 SWSR_DIO_002 SWSR_DIO_075 SWSR_DIO_076 SWSR_DIO_078
 *                      SW_SM004 SW_SM007
 *******************************************************************************************************/
void Dio_Ip_IrqHandler(uint32 portId)
{
    uint32 v;
    uint32 registerVal;
    uint32 gpioBaseAddr;
    uint32 channelId;
    Std_ReturnType errorId;
    uint32 dioPortId = portId;

    /* #10 get base address */
    gpioBaseAddr = Dio_IP_GetBasePerPort(&dioPortId);

    /* #20 Parameter validation */
    errorId = Dio_ValidatePort(dioPortId);

    if ((Std_ReturnType)E_OK == errorId)
    {
        Dio_ValidateInterrupt(dioPortId, gpioBaseAddr);

        /* clear sync irq */
        /* #30 get sync irq status */
        registerVal = REG_READ32(gpioBaseAddr + DIO_SINT_STATUS_PORT_X(dioPortId));
        while (registerVal > 0UL)
        {
            /* #40 get channel ID */
            if (APB_DIO_SF_BASE == gpioBaseAddr)
            {
                channelId = Dio_Ip_GetLowestInterruptBitPos(registerVal) + ((uint32)dioPortId * 32U);
            }
            else
            {
                channelId = Dio_Ip_GetLowestInterruptBitPos(registerVal) + ((uint32)dioPortId * 32U) +
                            DIO_SF_CHANNEL_NUM;
            }

            /* #50 validate channel ID */
            errorId = Dio_ValidateChannel(channelId);
            if ((Std_ReturnType)E_OK != errorId)
            {
                break;
            } /* else not needed */

            /* #60 call user application */
            if (NULL_PTR != Dio_InterruptNotification)
            {
                Dio_InterruptNotification(channelId);
            }

#ifndef SEMIDRIVE_E3_LITE_SERIES

            if (APB_DIO_AP_BASE == gpioBaseAddr)
            {
                channelId -= DIO_SF_CHANNEL_NUM;
            } /* else not needed */

#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES */
            v = REG_READ32(gpioBaseAddr + DIO_SINT_TYPE_PORT_X(PIN_OFFSET(channelId)));

            /* #70 clear interrupt status */
            if ((v & (0x1UL << PIN_BIT(channelId))) != 0U)
            {
                /* pulse sensitive, clear the interrupt status bit */
                REG_WRITE32(0x1UL << PIN_BIT(channelId),
                            gpioBaseAddr + DIO_SINT_EDGE_CLR_PORT_X(PIN_OFFSET(channelId)) + DIO_SET_PIN);
                ASM_KEYWORD("dsb sy");
            }
            else
            {
                /* level sensitive, mask the interrupt after interrupt occour */
                REG_WRITE32(0x1UL << PIN_BIT(channelId),
                            gpioBaseAddr + DIO_SINT_MASK_PORT_X(PIN_OFFSET(channelId)) + DIO_SET_PIN);
                ASM_KEYWORD("dsb sy");
                REG_WRITE32(0x1UL << PIN_BIT(channelId),
                            gpioBaseAddr + DIO_SINT_EDGE_CLR_PORT_X(PIN_OFFSET(channelId)) + DIO_SET_PIN);
                ASM_KEYWORD("dsb sy");
            }
            registerVal = REG_READ32(gpioBaseAddr + DIO_SINT_STATUS_PORT_X(dioPortId));
        }

        /* clear async irq */
        /* #80 get async irq status */
        registerVal = REG_READ32(gpioBaseAddr + DIO_AINT_STATUS_PORT_X(dioPortId));
        while (registerVal > 0UL)
        {
            /* #90 get channel ID */
            if (APB_DIO_SF_BASE == gpioBaseAddr)
            {
                channelId = Dio_Ip_GetLowestInterruptBitPos(registerVal) + ((uint32)dioPortId * 32U);
            }
            else
            {
                channelId = Dio_Ip_GetLowestInterruptBitPos(registerVal) + ((uint32)dioPortId * 32U) +
                            DIO_SF_CHANNEL_NUM;
            }

            /* #100 validate channel ID */
            errorId = Dio_ValidateChannel(channelId);
            if ((Std_ReturnType)E_OK != errorId)
            {
                break;
            } /* else not needed */

            /* #110 call user application */
            if (NULL_PTR != Dio_InterruptNotification)
            {
                Dio_InterruptNotification(channelId);
            }

#ifndef SEMIDRIVE_E3_LITE_SERIES

            if (APB_DIO_AP_BASE == gpioBaseAddr)
            {
                channelId -= DIO_SF_CHANNEL_NUM;
            } /* else not needed */

#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES */
            v = REG_READ32(gpioBaseAddr + DIO_AINT_TYPE_PORT_X(PIN_OFFSET(channelId)));

            /* #120 clear interrupt status */
            if ((v & (0x1UL << PIN_BIT(channelId))) != 0U)
            {
                /* pulse sensitive, clear the interrupt status bit */
                REG_WRITE32(0x1UL << PIN_BIT(channelId),
                            gpioBaseAddr + DIO_AINT_EDGE_CLR_PORT_X(PIN_OFFSET(channelId)) + DIO_SET_PIN);
                ASM_KEYWORD("dsb sy");
            }
            else
            {
                /* level sensitive, mask the interrupt after interrupt occour */
                REG_WRITE32(0x1UL << PIN_BIT(channelId),
                            gpioBaseAddr + DIO_AINT_MASK_PORT_X(PIN_OFFSET(channelId)) + DIO_SET_PIN);
                ASM_KEYWORD("dsb sy");
                REG_WRITE32(0x1UL << PIN_BIT(channelId),
                            gpioBaseAddr + DIO_AINT_EDGE_CLR_PORT_X(PIN_OFFSET(channelId)) + DIO_SET_PIN);
                ASM_KEYWORD("dsb sy");
            }
            registerVal = REG_READ32(gpioBaseAddr + DIO_AINT_STATUS_PORT_X(dioPortId));
        }
    } /* else not needed */
}

#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"

/* End of file */
