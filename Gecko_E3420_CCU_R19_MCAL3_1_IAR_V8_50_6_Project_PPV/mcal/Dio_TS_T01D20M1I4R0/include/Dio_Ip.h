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
 *  \file     Dio_Ip.h                                                                                  *
 *  \brief    This file contains interface header for DIO MCAL driver.                                  *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date                 <th>Version                                                             *
 * <tr><td>2023/07/06           <td>1.0.0                                                               *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifndef DIO_IP_H
#define DIO_IP_H

#ifdef __cplusplus
extern "C"
{
#endif

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Dio.h"
#include "Dio_Cfg.h"

/********************************************************************************************************
 *                                 Private Macro definition                                             *
 *******************************************************************************************************/
/**  Calculate which group DIO belongs to. */
#define PIN_OFFSET(channelid) ((channelid) / 32U)
/**  Calculate which BIT DIO is in. */
#define PIN_BIT(channelid) ((channelid) % 32U)

/**  Write 1 atomic operation on register. */
#define DIO_SET_PIN 0x04UL
/**  Clear 1 atomic operation on register. */
#define DIO_CLEAR_PIN 0x08UL
/**  Toggle 1 atomic operation on register. */
#define DIO_TOGGLE_PIN 0x0CUL

/**  Configure the level trigger offset register. */
#define INT_TYPE_LEVEL 0x0UL
/**  Configure edge trigger/level trigger method. */
#define INT_TYPE_PULSE 0x1UL
/**  Configure low trigger. */
#define INT_POL_LOW_NEG 0x0UL
/**  Configure high trigger. */
#define INT_POL_HIGH_POS 0x1UL
/**  Single edge trigger. */
#define INT_BOE_SIG_EDGE 0x0UL
/**  Bilateral edge trigger. */
#define INT_BOE_BOTH_EDGE 0x1UL

/**  Output enable register start address. */
#define DIO_OEN_PORT_0 ((uint32)0x580U)
/**  Output enable register end address. */
#define DIO_OEN_PORT_1 ((uint32)0x590U)
/**  Output enable register size */
#define DIO_OEN_PORT_SIZE \
    (DIO_OEN_PORT_1 - DIO_OEN_PORT_0)
/**  Output enable register number */
#define DIO_OEN_PORT_X(n) \
    (DIO_OEN_PORT_0 + ((n)*DIO_OEN_PORT_SIZE))

/**  Input register start address. */
#define DIO_DATA_IN_PORT_0 ((uint32)0x600U)
/**  Input register end address. */
#define DIO_DATA_IN_PORT_1 ((uint32)0x610U)
/**  Input register size. */
#define DIO_DATA_IN_PORT_SIZE \
    (DIO_DATA_IN_PORT_1 - DIO_DATA_IN_PORT_0)
/**  Input register number. */
#define DIO_DATA_IN_PORT_X(n) \
    (DIO_DATA_IN_PORT_0 + ((n)*DIO_DATA_IN_PORT_SIZE))

/**  Output level register start address. */
#define DIO_DATA_OUT_PORT_0 ((uint32)0x680U)
/**  Output level register end address. */
#define DIO_DATA_OUT_PORT_1 ((uint32)0x690U)
/**  Output level register size. */
#define DIO_DATA_OUT_PORT_SIZE \
    (DIO_DATA_OUT_PORT_1 - DIO_DATA_OUT_PORT_0)
/**  Output level register size. */
#define DIO_DATA_OUT_PORT_X(n) \
    (DIO_DATA_OUT_PORT_0 + ((n)*DIO_DATA_OUT_PORT_SIZE))

/**  Synchronous interrupt enable register start address. */
#define DIO_SINT_EN_PORT_0 ((uint32)0x700U)
/**  Synchronous interrupt enable register end address. */
#define DIO_SINT_EN_PORT_1 ((uint32)0x710U)
/**  Synchronous interrupt enable register size. */
#define DIO_SINT_EN_PORT_SIZE \
    (DIO_SINT_EN_PORT_1 - DIO_SINT_EN_PORT_0)
/**  Synchronous interrupt enable register number. */
#define DIO_SINT_EN_PORT_X(n) \
    (DIO_SINT_EN_PORT_0 + ((n)*DIO_SINT_EN_PORT_SIZE))

/**  Synchronous interrupt mask register start address. */
#define DIO_SINT_MASK_PORT_0 ((uint32)0x780U)
/**  Synchronous interrupt mask register end address. */
#define DIO_SINT_MASK_PORT_1 ((uint32)0x790U)
/**  Synchronous interrupt mask register size. */
#define DIO_SINT_MASK_PORT_SIZE \
    (DIO_SINT_MASK_PORT_1 - DIO_SINT_MASK_PORT_0)
/**  Synchronous interrupt mask register number. */
#define DIO_SINT_MASK_PORT_X(n) \
    (DIO_SINT_MASK_PORT_0 + ((n)*DIO_SINT_MASK_PORT_SIZE))

/**  Synchronous interrupt type register start address. */
#define DIO_SINT_TYPE_PORT_0 ((uint32)0x800U)
/**  Synchronous interrupt type register end address. */
#define DIO_SINT_TYPE_PORT_1 ((uint32)0x810U)
/**  Synchronous interrupt type register size. */
#define DIO_SINT_TYPE_PORT_SIZE \
    (DIO_SINT_TYPE_PORT_1 - DIO_SINT_TYPE_PORT_0)
/**  Synchronous interrupt type register number. */
#define DIO_SINT_TYPE_PORT_X(n) \
    (DIO_SINT_TYPE_PORT_0 + ((n)*DIO_SINT_TYPE_PORT_SIZE))

/**  Synchronous interrupt polarity register start address. */
#define DIO_SINT_POL_PORT_0 ((uint32)0x880U)
/**  Synchronous interrupt polarity register end address. */
#define DIO_SINT_POL_PORT_1 ((uint32)0x890U)
/**  Synchronous interrupt polarity register size. */
#define DIO_SINT_POL_PORT_SIZE \
    (DIO_SINT_POL_PORT_1 - DIO_SINT_POL_PORT_0)
/**  Synchronous interrupt polarity register number. */
#define DIO_SINT_POL_PORT_X(n) \
    (DIO_SINT_POL_PORT_0 + ((n)*DIO_SINT_POL_PORT_SIZE))

/**  Synchronous interrupt both register start address. */
#define DIO_SINT_BOTH_EDGE_PORT_0 ((uint32)0x900U)
/**  Synchronous interrupt both register end address. */
#define DIO_SINT_BOTH_EDGE_PORT_1 ((uint32)0x910U)
/**  Synchronous interrupt both register size. */
#define DIO_SINT_BOTH_EDGE_PORT_SIZE \
    (DIO_SINT_BOTH_EDGE_PORT_1 - DIO_SINT_BOTH_EDGE_PORT_0)
/**  Synchronous interrupt both register number. */
#define DIO_SINT_BOTH_EDGE_PORT_X(n) \
    (DIO_SINT_BOTH_EDGE_PORT_0 + ((n)*DIO_SINT_BOTH_EDGE_PORT_SIZE))

/**  Synchronous interrupt status register start address. */
#define DIO_SINT_STATUS_PORT_0 ((uint32)0x980U)
/**  Synchronous interrupt status register end address. */
#define DIO_SINT_STATUS_PORT_1 ((uint32)0x990U)
/**  Synchronous interrupt status register size. */
#define DIO_SINT_STATUS_PORT_SIZE \
    (DIO_SINT_STATUS_PORT_1 - DIO_SINT_STATUS_PORT_0)
/**  Synchronous interrupt status register number. */
#define DIO_SINT_STATUS_PORT_X(n) \
    (DIO_SINT_STATUS_PORT_0 + ((n)*DIO_SINT_STATUS_PORT_SIZE))

/**  Synchronous interrupt clear register start address. */
#define DIO_SINT_EDGE_CLR_PORT_0 ((uint32)0xA80U)
/**  Synchronous interrupt clear register end address. */
#define DIO_SINT_EDGE_CLR_PORT_1 ((uint32)0xA90U)
/**  Synchronous interrupt clear register size. */
#define DIO_SINT_EDGE_CLR_PORT_SIZE \
    (DIO_SINT_EDGE_CLR_PORT_1 - DIO_SINT_EDGE_CLR_PORT_0)
/**  Synchronous interrupt clear register number. */
#define DIO_SINT_EDGE_CLR_PORT_X(n) \
    (DIO_SINT_EDGE_CLR_PORT_0 + ((n)*DIO_SINT_EDGE_CLR_PORT_SIZE))

/**  Aynchronous interrupt clear register start address. */
#define DIO_AINT_EDGE_CLR_PORT_0 ((uint32)0xE80U)
/**  Aynchronous interrupt clear register end address. */
#define DIO_AINT_EDGE_CLR_PORT_1 ((uint32)0xE90U)
/**  Aynchronous interrupt clear register size. */
#define DIO_AINT_EDGE_CLR_PORT_SIZE \
    (DIO_AINT_EDGE_CLR_PORT_1 - DIO_AINT_EDGE_CLR_PORT_0)
/**  Aynchronous interrupt clear register number. */
#define DIO_AINT_EDGE_CLR_PORT_X(n) \
    (DIO_AINT_EDGE_CLR_PORT_0 + ((n)*DIO_AINT_EDGE_CLR_PORT_SIZE))

/**  Aynchronous interrupt enable register start address. */
#define DIO_AINT_EN_PORT_0 ((uint32)0xB00U)
/**  Aynchronous interrupt enable register end address. */
#define DIO_AINT_EN_PORT_1 ((uint32)0xB10U)
/**  Aynchronous interrupt enable register size. */
#define DIO_AINT_EN_PORT_SIZE \
    (DIO_AINT_EN_PORT_1 - DIO_AINT_EN_PORT_0)
/**  Aynchronous interrupt enable register number. */
#define DIO_AINT_EN_PORT_X(n) \
    (DIO_AINT_EN_PORT_0 + ((n)*DIO_AINT_EN_PORT_SIZE))

/**  Aynchronous interrupt type register start address. */
#define DIO_AINT_TYPE_PORT_0 ((uint32)0xC00U)
/**  Aynchronous interrupt type register end address. */
#define DIO_AINT_TYPE_PORT_1 ((uint32)0xC10U)
/**  Aynchronous interrupt type register size. */
#define DIO_AINT_TYPE_PORT_SIZE \
    (DIO_AINT_TYPE_PORT_1 - DIO_AINT_TYPE_PORT_0)
/**  Aynchronous interrupt type register number. */
#define DIO_AINT_TYPE_PORT_X(n) \
    (DIO_AINT_TYPE_PORT_0 + ((n)*DIO_AINT_TYPE_PORT_SIZE))

/**  Aynchronous interrupt polarity register start address. */
#define DIO_AINT_POL_PORT_0 ((uint32)0xC80U)
/**  Aynchronous interrupt polarity register end address. */
#define DIO_AINT_POL_PORT_1 ((uint32)0xC90U)
/**  Aynchronous interrupt polarity register size. */
#define DIO_AINT_POL_PORT_SIZE \
    (DIO_AINT_POL_PORT_1 - DIO_AINT_POL_PORT_0)
/**  Aynchronous interrupt polarity register number. */
#define DIO_AINT_POL_PORT_X(n) \
    (DIO_AINT_POL_PORT_0 + ((n)*DIO_AINT_POL_PORT_SIZE))

/**  Aynchronous interrupt both register start address. */
#define DIO_AINT_BOTH_EDGE_PORT_0 ((uint32)0xD00U)
/**  Aynchronous interrupt both register end address. */
#define DIO_AINT_BOTH_EDGE_PORT_1 ((uint32)0xD10U)
/**  Aynchronous interrupt both register size. */
#define DIO_AINT_BOTH_EDGE_PORT_SIZE \
    (DIO_AINT_BOTH_EDGE_PORT_1 - DIO_AINT_BOTH_EDGE_PORT_0)
/**  Aynchronous interrupt both register number. */
#define DIO_AINT_BOTH_EDGE_PORT_X(n) \
    (DIO_AINT_BOTH_EDGE_PORT_0 + ((n)*DIO_AINT_BOTH_EDGE_PORT_SIZE))

/**  Aynchronous interrupt mask register start address. */
#define DIO_AINT_MASK_PORT_0 ((uint32)0xB80U)
/**  Aynchronous interrupt mask register end address. */
#define DIO_AINT_MASK_PORT_1 ((uint32)0xB90U)
/**  Aynchronous interrupt mask register size. */
#define DIO_AINT_MASK_PORT_SIZE \
    (DIO_AINT_MASK_PORT_1 - DIO_AINT_MASK_PORT_0)
/**  Aynchronous interrupt mask register number. */
#define DIO_AINT_MASK_PORT_X(n) \
    (DIO_AINT_MASK_PORT_0 + ((n)*DIO_AINT_MASK_PORT_SIZE))

/**  Aynchronous interrupt status register start address. */
#define DIO_AINT_STATUS_PORT_0 ((uint32)0xD80U)
/**  Aynchronous interrupt status register end address. */
#define DIO_AINT_STATUS_PORT_1 ((uint32)0xD90U)
/**  Aynchronous interrupt status register size. */
#define DIO_AINT_STATUS_PORT_SIZE \
    (DIO_AINT_STATUS_PORT_1 - DIO_AINT_STATUS_PORT_0)
/**  Aynchronous interrupt status register number. */
#define DIO_AINT_STATUS_PORT_X(n) \
    (DIO_AINT_STATUS_PORT_0 + ((n)*DIO_AINT_STATUS_PORT_SIZE))

/**  DIO max offset. */
#define DIO_MAXOFFSET 31U

#ifdef SEMIDRIVE_E3_LITE_SERIES
/* DIO sf Base Addr */
#define APB_DIO_SF_BASE    (0xf0c40000UL)
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES */

#ifdef SEMIDRIVE_E3_SERIES
/* DIO sf Base Addr */
#define APB_DIO_SF_BASE (0xf0740000UL)
/* DIO ap Base Addr */
#define APB_DIO_AP_BASE (0xf3120000UL)
#endif /** #ifdef SEMIDRIVE_E3_SERIES */

/********************************************************************************************************
 *                                  Private Function Declarations                                       *
 *******************************************************************************************************/
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
boolean Dio_IP_GetInterruptSta(Dio_PortType portId);

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
Std_ReturnType Dio_ValidateChannel(const Dio_ChannelType channelId);

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
Std_ReturnType Dio_ValidatePort(const Dio_PortType portId);

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
Std_ReturnType Dio_ValidateLevel(const Dio_LevelType level);

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
Dio_LevelType Dio_Ip_ReadChannel(Dio_ChannelType channelId);

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
Std_ReturnType Dio_Ip_WriteChannel(Dio_ChannelType channelId, Dio_LevelType level);

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
Dio_PortLevelType Dio_Ip_ReadPort(Dio_PortType portId);

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
Std_ReturnType Dio_Ip_WritePort(Dio_PortType portId, Dio_PortLevelType level);

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
Dio_PortLevelType Dio_Ip_ReadChannelGroup(const Dio_ChannelGroupType *channelGroupIdPtr);

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
                              Dio_PortLevelType level);

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
Dio_LevelType Dio_Ip_FlipChannel(Dio_ChannelType channelId);
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
        Dio_DetectionType interruptType);

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
        Dio_DetectionType interruptType);

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
 *                      SW_SM007
 *******************************************************************************************************/
void Dio_Ip_IrqHandler(uint32 portId);

#ifdef __cplusplus
}
#endif

#endif /* DIO_IP_H */

/* End of file */
