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
 *  \file     Dio_Types.h                                                                               *
 *  \brief    This file contains interface header for DIO MCAL driver.                                  *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date                 <th>Version                                                             *
 * <tr><td>2023/07/06           <td>1.0.0                                                               *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef DIO_TYPES_H
#define DIO_TYPES_H

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Platform_Types.h"

/**
 *  \addtogroup MCAL_DIO_MACRO DIO macro
 *  \{
 */

/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/
/** \{ */
/** \brief Semidrive Vendor ID */
#define DIO_VENDOR_ID    0x8C
/** \brief  Driver Implementation Major Version. */
#define DIO_MODULE_ID                    120
/** \brief  Driver Implementation Major Version. */
#define DIO_INSTANCE_ID                  0
/** \} */

/** \{ */
/** \brief Dio_ReadChannel() */
#define DIO_READ_CHANNEL_SID           ((uint8)0x00U)

/** \brief Dio_WriteChannel() */
#define DIO_WRITE_CHANNEL_SID          ((uint8)0x01U)

/** \brief Dio_WritePort() */
#define DIO_READ_PORT_SID              ((uint8)0x02U)

/** \brief Dio_WritePort() */
#define DIO_WRITE_PORT_SID             ((uint8)0x03U)

/** \brief Dio_ReadChannelGroup() */
#define DIO_READ_CHANNEL_GROUP_SID     ((uint8)0x04U)

/** \brief Dio_WriteChannelGroup() */
#define DIO_WRITE_CHANNEL_GROUP_SID    ((uint8)0x05U)

/** \brief Dio_FlipChannel() */
#define DIO_FLIP_CHANNEL_SID           ((uint8)0x11U)

/** \brief Dio_GetVersionInfo() */
#define DIO_GET_VERSION_INFO_SID       ((uint8)0x12U)

/** \brief Dio_SetPinInterruptDetect() */
#define DIO_SET_PIN_INTERRUPT_DETECT_SID       ((uint8)0x20U)
/** \} */

/** \{ */
/** \brief ERROR:API service called with invalid channel ID */
/**
 * Traceability       : SWSR_DIO_026
 */
#define DIO_E_PARAM_INVALID_CHANNEL_ID  ((uint8)0x0AU)

/** \brief ERROR:API service called with invalid level */
#define DIO_E_INVALID_CHANNEL_LEVEL  ((uint8)0x80U)

/** \brief ERROR:API service called with invalid port ID */
/**
 * Traceability       : SWSR_DIO_027
 */
#define DIO_E_PARAM_INVALID_PORT_ID     ((uint8)0x14U)

/** \brief ERROR:API service called with invalid channel group ID */
/**
 * Traceability       : SWSR_DIO_028
 */
#define DIO_E_PARAM_INVALID_GROUP       ((uint8)0x1FU)

/** \brief ERROR:API service called with return invalid level */
#define DIO_E_RETURN_INVALID_GROUP_LEVEL       ((uint8)0x81U)

/** \brief ERROR:Dio_GetVersionInfo() called with NULL_PTR as parameter */
/**
 * Traceability       : SWSR_DIO_029
 */
#define DIO_E_PARAM_POINTER             ((uint8)0x20U)

/** \brief ERROR:Dio_SetPinInterruptDetect() called with type as parameter */
#define DIO_E_PARAM_INVALID_INT_TYPE    ((uint8)0x21U)
/** \} */

/** \{ */
/** \brief input mode */
#define DIO_INPUT 0UL
/** \brief output mode */
#define DIO_OUTPUT 1UL
/** \} */
/** \} */

/**
 *  \addtogroup MCAL_DIO_CFG DIO Configuration
 *  \{
 */
/********************************************************************************************************
 *                                  Global Types definition                                             *
 *******************************************************************************************************/
/** \{ */
/**
 *  \brief type definition for identifying DIO channels (meaning single port
 *  pins)
 */
/**
 * Traceability       : SWSR_DIO_035
 */
typedef uint32 Dio_ChannelType;

/**
 *  \brief type definition for setting DIO channnel level values (allowed
 *  values: STD_HIGH and STD_LOW)
 */
/**
 * Traceability       : SWSR_DIO_046 SWSR_DIO_047 SWSR_DIO_048
 */
typedef uint32 Dio_LevelType;

/** \brief type definition for identifying ports */
/**
 * Traceability       : SWSR_DIO_039 SWSR_DIO_040 SWSR_DIO_041
 */
typedef uint32 Dio_PortType;

/**
 *  \brief type definition for setting port level values
 *
 *  This is a bitmask, where each bit with value '1' sets the corresponding port
 *  pin to HIGH and '0' sets the pin to LOW)SWSR_DIO_034
 */
/**
 * Traceability       : SWSR_DIO_034 SWSR_DIO_035 SWSR_DIO_036 SWSR_DIO_037
 *                      SWSR_DIO_038
 */
typedef uint32 Dio_PortLevelType;
/** \} */

/* {\ */
/**
 *  \brief  Type definition for identifying channel groups (meaning a set of pins in one port)
 */
/**
 * Traceability       : SWSR_DIO_043 SWSR_DIO_044 SWSR_DIO_045
 */
typedef struct
{
    Dio_PortType port;
    /**< port ID of a channel group */
    uint32 offset;
    /**< shifts channel group values, so it is always "right" aligned */
    Dio_PortLevelType  mask;
    /**< bitmask where a '1' represents a pin handled by this channel group */
} Dio_ChannelGroupType;
/* \} */

/** \{ */
/**
 * \brief dio interrupt mode config.
 */
typedef enum
{
    DIO_SYNC_LOW_LEVEL = 0U,
    /**< synchronous low level mode */
    DIO_SYNC_HIGH_LEVEL,
    /**< synchronous high level mode */
    DIO_SYNC_RISING_EDGE,
    /**< synchronous rising mode */
    DIO_SYNC_FALLING_EDGE,
    /**< synchronous falling mode */
    DIO_SYNC_BOTH_EDGE,
    /**< synchronous Bilateral margin mode */
    DIO_SYNC_NONE,
    /**< synchronous interrupt off */
    DIO_ASYNC_LOW_LEVEL,
    /**< async low level mode */
    DIO_ASYNC_HIGH_LEVEL,
    /**< async high level mode */
    DIO_ASYNC_RISING_EDGE,
    /**< async rising mode */
    DIO_ASYNC_FALLING_EDGE,
    /**< async falling mode */
    DIO_ASYNC_BOTH_EDGE,
    /**< async Bilateral margin mode */
    DIO_ASYNC_NONE
    /**< async interrupt off */
} Dio_DetectionType;
/** \} */

/** \} */

#endif /* DIO_TYPES_H */

/* End of file */
