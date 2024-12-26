/*
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
 * an "AS IS" basis, WITHOUT WARRANTIES OF ANY KIND, either express or implied.
 *
 * You should have received a copy of the License along with this program.
 * If not, see <http://www.semidrive.com/licenses/>.
 */

/**
 * @file  Dio.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Dio
 */

#ifndef DIO_H
#define DIO_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Mcal.h"
#include "Std_Types.h"
#include "Dio_Cfg.h"
#include "Det.h"
/* Version and Check Begin */
/* Version Info Begin */
#define DIO_H_VENDOR_ID    0x8C
#define DIO_H_AR_RELEASE_MAJOR_VERSION    4
#define DIO_H_AR_RELEASE_MINOR_VERSION    3
#define DIO_H_AR_RELEASE_REVISION_VERSION 1
#define DIO_H_SW_MAJOR_VERSION    1
#define DIO_H_SW_MINOR_VERSION    0
#define DIO_H_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((DIO_H_AR_RELEASE_MAJOR_VERSION != STD_TYPES_H_AR_RELEASE_MAJOR_VERSION)\
    || (DIO_H_AR_RELEASE_MINOR_VERSION != STD_TYPES_H_AR_RELEASE_MINOR_VERSION)\
    || (DIO_H_AR_RELEASE_REVISION_VERSION != STD_TYPES_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Dio.h and Std_Types.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((DIO_H_SW_MAJOR_VERSION != STD_TYPES_H_SW_MAJOR_VERSION)\
    || (DIO_H_SW_MINOR_VERSION != STD_TYPES_H_SW_MINOR_VERSION)\
    || (DIO_H_SW_PATCH_VERSION != STD_TYPES_H_SW_PATCH_VERSION))
#error "Opps, Dio.h and Std_Types.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((DIO_H_AR_RELEASE_MAJOR_VERSION != DET_H_AR_RELEASE_MAJOR_VERSION)\
    || (DIO_H_AR_RELEASE_MINOR_VERSION != DET_H_AR_RELEASE_MINOR_VERSION)\
    || (DIO_H_AR_RELEASE_REVISION_VERSION != DET_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Dio.h and Det.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((DIO_H_SW_MAJOR_VERSION != DET_H_SW_MAJOR_VERSION)\
    || (DIO_H_SW_MINOR_VERSION != DET_H_SW_MINOR_VERSION)\
    || (DIO_H_SW_PATCH_VERSION != DET_H_SW_PATCH_VERSION))
#error "Opps, Dio.h and Det.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */

#define DIO_MODULE_ID                    120
#define DIO_INSTANCE_ID                  0

/**
 * @brief   API service id.
 * @details Parameters used when raising an Det error.
 */
/* Service ID for DIO read Channel */
#define DIO_READ_CHANNEL_SID           ((uint8)0x00U)

/* Service ID for DIO write Channel */
#define DIO_WRITE_CHANNEL_SID          ((uint8)0x01U)

/* Service ID for DIO read Port */
#define DIO_READ_PORT_SID              ((uint8)0x02U)

/* Service ID for DIO write Port */
#define DIO_WRITE_PORT_SID             ((uint8)0x03U)

/* Service ID for DIO read Channel Group */
#define DIO_READ_CHANNEL_GROUP_SID     ((uint8)0x04U)

/* Service ID for DIO write Channel Group */
#define DIO_WRITE_CHANNEL_GROUP_SID    ((uint8)0x05U)

/* Service ID for DIO flip Channel */
#define DIO_FLIP_CHANNEL_SID           ((uint8)0x11U)

/* Service ID for DIO GetVersionInfo */
#define DIO_GET_VERSION_INFO_SID       ((uint8)0x12U)

/* Service ID for DIO mask write Port */
#define DIO_MASK_WRITE_PORT_SID        ((uint8)0x13U)

/* Service ID for DIO level detect */
#define DIO_MASK_EN_INT_SID            ((uint8)0x14U)

/**
 * @brief   Development Errors code.
 * @details Parameters used when raising an Det error.
 */
/* DET code to report Invalid Channel */
#define DIO_E_PARAM_INVALID_CHANNEL_ID  ((uint8)0x0AU)

/* DET code to report Invalid Port */
#define DIO_E_PARAM_INVALID_PORT_ID     ((uint8)0x14U)

/* DET code to report Invalid Channel Group */
#define DIO_E_PARAM_INVALID_GROUP       ((uint8)0x1FU)

/* Dio_Init API service called with NULL_PTR pointer parameter */
#define DIO_E_PARAM_POINTER             ((uint8)0x20U)

/* DET code to report Invalid interrupt type */
#define DIO_E_PARAM_INVALID_INT_TYPE    ((uint8)0x21U)

/**
 * @brief   Type definition.
 */

/* Type definition for possible levels that a Dio Channel can have */
typedef uint8 Dio_LevelType;

/* Non-AutoSAR.
 * Type definition for Dio direction, 0 for input and 1 for output
 */
typedef enum {
    DIO_INPUT,
    DIO_OUTPUT,
} Dio_DirectionType;

/* Non-AutoSAR.
 * Type definition for Dio detection
 * DIO_NONE: no interrupt detection enable
 * DIO_LOW_LEVEL: interrupt low level active
 * DIO_HIGH_LEVEL: interrupt high level active
 * DIO_RISING_EDGE: interrupt rising edge active
 * DIO_FALLING_EDGE: interrupt falling edge active
 * DIO_BOTH_EDGE: interrupt both edge(rising/falling) active
 */
typedef enum {
    DIO_NONE,
    DIO_LOW_LEVEL,
    DIO_HIGH_LEVEL,
    DIO_RISING_EDGE,
    DIO_FALLING_EDGE,
    DIO_BOTH_EDGE
} Dio_DetectionType;

/**
 * @brief   Returns the value of the specified DIO channel.
 *
 * @detials Returns the value of the specified DIO channel.
            Service ID 0x00, Synchronous, Reentrant.
 *
 * @param   ChannelId ID of DIO channel.
 *
 * @return  Dio_LevelType
 *          STD_HIGH The physical level of the corresponding Pin is STD_HIGH
 *          STD_LOW The physical level of the corresponding Pin is STD_LOW
 */
FUNC(Dio_LevelType, DIO_CODE) Dio_ReadChannel
(
    CONST(Dio_ChannelType, AUTOMATIC) ChannelId
);

/**
 * @brief   Service to set a level of a channel.
 *
 * @detials Service to set a level of a channel.
            Service ID 0x01, Synchronous, Reentrant.
 *
 * @param   ChannelId ID of DIO channel.
 * @param   Level Value to be written.
 */
FUNC(void, DIO_CODE) Dio_WriteChannel
(
    CONST(Dio_ChannelType, AUTOMATIC) ChannelId,
    CONST(Dio_LevelType,   AUTOMATIC) Level
);

/**
 * @brief   Returns the level of all channels of that port.
 *
 * @detials Returns the level of all channels of that port.
            Service ID 0x02, Synchronous, Reentrant.
 *
 * @param   ChannelId ID of DIO channel.
 *
 * @return  Dio_PortType Level of all channels of that port
 */
FUNC(Dio_PortLevelType, DIO_CODE) Dio_ReadPort
(
    CONST(Dio_PortType, AUTOMATIC) PortId
);

/**
 * @brief   Service to set a value of the port.
 *
 * @detials Service to set a value of the port.
            Service ID 0x03, Synchronous, Reentrant.
 *
 * @param   PortId ID of DIO channel.
 * @param   Level Value to be written.
 */
FUNC(void, DIO_CODE) Dio_WritePort
(
    CONST(Dio_PortType,      AUTOMATIC) PortId,
    CONST(Dio_PortLevelType, AUTOMATIC) Level
);

/**
 * @brief   This Service reads a subset of the adjoining bits of a port.
 *
 * @detials This Service reads a subset of the adjoining bits of a port.
            Service ID 0x04, Synchronous, Reentrant.
 *
 * @param   ChannelGroupIdPtr Pointer to ChannelGroup.
 *
 * @return  Dio_PortLevelType Level of a subset of the adjoining bits of a port.
 */
FUNC(Dio_PortLevelType, DIO_CODE) Dio_ReadChannelGroup
(
    P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) ChannelGroupIdPtr
);

/**
 * @brief   Service to set a subset of the adjoining bits of a port to a specified level.
 *
 * @detials Service to set a subset of the adjoining bits of a port to a specified level.
            Service ID 0x05, Synchronous, Reentrant.
 *
 * @param   ChannelGroupIdPtr Pointer to ChannelGroup.
 * @param   Level Value to be written.
 */
FUNC(void, DIO_CODE) Dio_WriteChannelGroup
(
    P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) ChannelGroupIdPtr,
    CONST  (Dio_PortLevelType,    AUTOMATIC)                 Level
);

/**
 * @brief   Service to flip (change from 1 to 0 or from 0 to 1) the level of a channel and return
 *          the level of the channel after flip.
 *
 * @detials Service to flip (change from 1 to 0 or from 0 to 1) the level of a channel and return the level of the channel after flip.
            Service ID 0x11, Synchronous, Reentrant.
 *
 * @param   ChannelId ID of DIO channel.
 * @return  Dio_LevelType
 *          STD_HIGH The physical level of the corresponding Pin is STD_HIGH
 *          STD_LOW The physical level of the corresponding Pin is STD_LOW
 */
#if (STD_ON == DIO_FLIP_CHANNEL_API)
FUNC(Dio_LevelType, DIO_CODE) Dio_FlipChannel
(
    CONST(Dio_ChannelType, AUTOMATIC) ChannelId
);
#endif

/**
 * @brief   Service to set the value of a given port with required mask.
 *
 * @detials Service to set the value of a given port with required mask.
            Service ID 0x13, Synchronous, Reentrant.
 *
 * @param   PortId ID of DIO Port.
 * @param   Level  Value to be written.
 * @param   Mask   Channels to be masked in the port.
 */
#if (DIO_MASKEDWRITEPORT_API == STD_ON)
FUNC(void, DIO_CODE) Dio_MaskedWritePort
(
    CONST(Dio_PortType,      AUTOMATIC) PortId,
    CONST(Dio_PortLevelType, AUTOMATIC) Level,
    CONST(Dio_PortLevelType, AUTOMATIC) Mask
);
#endif

/**
 * @brief   Service to get the version information of this module.
 *
 * @detials Service to get the version information of this module.
            Service ID 0x12, Synchronous, Reentrant.
 *
 * @param   VersionInfo Pointer to where to store the version information of this module.
 */
#if (DIO_VERSION_INFO_API == STD_ON)
FUNC(void, DIO_CODE) Dio_GetVersionInfo
(
    CONSTP2VAR(Std_VersionInfoType, AUTOMATIC, DIO_APPL_DATA) versionInfo
);

/**
 * @brief   Enable the level sensitive interrupt.
 *
 * @detials The level sensitive interupt will be init in Port Module. After interrupt trigger.
            the interrupt will be mask, so need reSet it.
 *
 * @param   InterruptType Type only valid for LEVEL sensitive(LOW_LEVEL/HIGH_LEVEL).
 */
FUNC(void, DIO_CODE) Dio_SetPinInterruptDetect
(
    VAR(Dio_ChannelType, AUTOMATIC) ChannelId,
    VAR(Dio_DetectionType, AUTOMATIC) InterruptType
);

#endif

#ifdef __cplusplus
}
#endif

#endif
