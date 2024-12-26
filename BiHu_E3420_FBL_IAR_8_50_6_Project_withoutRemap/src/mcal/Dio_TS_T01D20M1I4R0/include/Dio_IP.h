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
 * @file  Dio_IP.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Dio
 */

#ifndef DIO_IP_H
#define DIO_IP_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "Dio.h"
#include "__regs_base.h"
/* Version and Check Begin */
/* Version Info Begin */
#define DIO_IP_H_VENDOR_ID 0x8C
#define DIO_IP_H_AR_RELEASE_MAJOR_VERSION 4
#define DIO_IP_H_AR_RELEASE_MINOR_VERSION 3
#define DIO_IP_H_AR_RELEASE_REVISION_VERSION 1
#define DIO_IP_H_SW_MAJOR_VERSION 1
#define DIO_IP_H_SW_MINOR_VERSION 0
#define DIO_IP_H_SW_PATCH_VERSION 0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((DIO_IP_H_AR_RELEASE_MAJOR_VERSION != DIO_H_AR_RELEASE_MAJOR_VERSION) || (DIO_IP_H_AR_RELEASE_MINOR_VERSION != DIO_H_AR_RELEASE_MINOR_VERSION) || (DIO_IP_H_AR_RELEASE_REVISION_VERSION != DIO_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Dio_IP.h and Dio.h AutoSAR version not match!"
#endif
#endif /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((DIO_IP_H_SW_MAJOR_VERSION != DIO_H_SW_MAJOR_VERSION) || (DIO_IP_H_SW_MINOR_VERSION != DIO_H_SW_MINOR_VERSION) || (DIO_IP_H_SW_PATCH_VERSION != DIO_H_SW_PATCH_VERSION))
#error "Opps, Dio_IP.h and Dio.h Software version not match!"
#endif
#endif /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */

/**
 * @brief   GPIO INDEX.
 */
#define PIN_OFFSET(channelid) ((channelid) / 32U)
#define PIN_BIT(channelid) ((channelid) % 32U)
#define PIN_MASK(channelid) (1ul << PIN_BIT(channelid))

/**
 * @brief   GPIO MAXCHANNEL.
 */
#define DIO_SF_CHANNEL_NUM 0x87U
#define DIO_AP_CHANNEL_NUM 0x4FU

/**
 * @brief   GPIO MAXPORT.
 */
#define DIO_SF_PORT_NUM 0x5U
#define DIO_AP_PORT_NUM 0x3U

/**
 * @brief   GPIO Channel operation register.
 * @details define channel register bit operation, All channel(0-213) can be operate.
 */
#define GPIO_SET_PIN 0x04U
#define GPIO_CLEAR_PIN 0x08U
#define GPIO_TOGGLE_PIN 0x0CU

/**
 * @brief   GPIO interrupt releated bit(12/4/3).
 * @details interrupt enable/interrupt mask enable/interrupt debounce enable(2clk)
 */
#define GPIO_CTRL_INT_ENABLE(x) \
    ((((x) << GPIO_CTRL_INT_DEB_EN_BIT) | ((x) << GPIO_CTRL_INT_EN_BIT)) & (~((x) << GPIO_CTRL_INT_MASK_BIT)))

#define INT_TYPE_LEVEL 0x0UL
#define INT_TYPE_PULSE 0x1UL
#define INT_POL_LOW_NEG 0x0UL
#define INT_POL_HIGH_POS 0x1UL
#define INT_BOE_SIG_EDGE 0x0UL
#define INT_BOE_BOTH_EDGE 0x1UL

/**
 * @brief   GPIO PORT operate register define.
 */
#define GPIO_OEN_PORT_0 ((uint32)0x580U)
#define GPIO_OEN_PORT_1 ((uint32)0x590U)
#define GPIO_OEN_PORT_SIZE \
    (GPIO_OEN_PORT_1 - GPIO_OEN_PORT_0)
#define GPIO_OEN_PORT_X(n) \
    (GPIO_OEN_PORT_0 + ((n)*GPIO_OEN_PORT_SIZE))

#define GPIO_DATA_IN_PORT_0 ((uint32)0x600U)
#define GPIO_DATA_IN_PORT_1 ((uint32)0x610U)
#define GPIO_DATA_IN_PORT_SIZE \
    (GPIO_DATA_IN_PORT_1 - GPIO_DATA_IN_PORT_0)
#define GPIO_DATA_IN_PORT_X(n) \
    (GPIO_DATA_IN_PORT_0 + ((n)*GPIO_DATA_IN_PORT_SIZE))

#define GPIO_DATA_OUT_PORT_0 ((uint32)0x680U)
#define GPIO_DATA_OUT_PORT_1 ((uint32)0x690U)
#define GPIO_DATA_OUT_PORT_SIZE \
    (GPIO_DATA_OUT_PORT_1 - GPIO_DATA_OUT_PORT_0)
#define GPIO_DATA_OUT_PORT_X(n) \
    (GPIO_DATA_OUT_PORT_0 + ((n)*GPIO_DATA_OUT_PORT_SIZE))

#define GPIO_SINT_EN_PORT_0 ((uint32)0x700U)
#define GPIO_SINT_EN_PORT_1 ((uint32)0x710U)
#define GPIO_SINT_EN_PORT_SIZE \
    (GPIO_SINT_EN_PORT_1 - GPIO_SINT_EN_PORT_0)
#define GPIO_SINT_EN_PORT_X(n) \
    (GPIO_SINT_EN_PORT_0 + ((n)*GPIO_SINT_EN_PORT_SIZE))

#define GPIO_SINT_MASK_PORT_0 ((uint32)0x780U)
#define GPIO_SINT_MASK_PORT_1 ((uint32)0x790U)
#define GPIO_SINT_MASK_PORT_SIZE \
    (GPIO_SINT_MASK_PORT_1 - GPIO_SINT_MASK_PORT_0)
#define GPIO_SINT_MASK_PORT_X(n) \
    (GPIO_SINT_MASK_PORT_0 + ((n)*GPIO_SINT_MASK_PORT_SIZE))

#define GPIO_SINT_TYPE_PORT_0 ((uint32)0x800U)
#define GPIO_SINT_TYPE_PORT_1 ((uint32)0x810U)
#define GPIO_SINT_TYPE_PORT_SIZE \
    (GPIO_SINT_TYPE_PORT_1 - GPIO_SINT_TYPE_PORT_0)
#define GPIO_SINT_TYPE_PORT_X(n) \
    (GPIO_SINT_TYPE_PORT_0 + ((n)*GPIO_SINT_TYPE_PORT_SIZE))

#define GPIO_SINT_POL_PORT_0 ((uint32)0x880U)
#define GPIO_SINT_POL_PORT_1 ((uint32)0x890U)
#define GPIO_SINT_POL_PORT_SIZE \
    (GPIO_SINT_POL_PORT_1 - GPIO_SINT_POL_PORT_0)
#define GPIO_SINT_POL_PORT_X(n) \
    (GPIO_SINT_POL_PORT_0 + ((n)*GPIO_SINT_POL_PORT_SIZE))

#define GPIO_SINT_BOTH_EDGE_PORT_0 ((uint32)0x900U)
#define GPIO_SINT_BOTH_EDGE_PORT_1 ((uint32)0x910U)
#define GPIO_SINT_BOTH_EDGE_PORT_SIZE \
    (GPIO_SINT_BOTH_EDGE_PORT_1 - GPIO_SINT_BOTH_EDGE_PORT_0)
#define GPIO_SINT_BOTH_EDGE_PORT_X(n) \
    (GPIO_SINT_BOTH_EDGE_PORT_0 + ((n)*GPIO_SINT_BOTH_EDGE_PORT_SIZE))

#define GPIO_SINT_STATUS_PORT_0 ((uint32)0x980U)
#define GPIO_SINT_STATUS_PORT_1 ((uint32)0x990U)
#define GPIO_SINT_STATUS_PORT_SIZE \
    (GPIO_SINT_STATUS_PORT_1 - GPIO_SINT_STATUS_PORT_0)
#define GPIO_SINT_STATUS_PORT_X(n) \
    (GPIO_SINT_STATUS_PORT_0 + ((n)*GPIO_SINT_STATUS_PORT_SIZE))

#define GPIO_SINT_STATUS_UNMASK_PORT_0 ((uint32)0xA00U)
#define GPIO_SINT_STATUS_UNMASK_PORT_1 ((uint32)0xA10U)
#define GPIO_SINT_STATUS_UNMASK_PORT_SIZE \
    (GPIO_SINT_STATUS_UNMASK_PORT_1 - GPIO_SINT_STATUS_UNMASK_PORT_0)
#define GPIO_SINT_STATUS_UNMASK_PORT_X(n) \
    (GPIO_SINT_STATUS_UNMASK_PORT_0 +     \
     ((n)*GPIO_SINT_STATUS_UNMASK_PORT_SIZE))

#define GPIO_SINT_EDGE_CLR_PORT_0 ((uint32)0xA80U)
#define GPIO_SINT_EDGE_CLR_PORT_1 ((uint32)0xA90U)
#define GPIO_SINT_EDGE_CLR_PORT_SIZE \
    (GPIO_SINT_EDGE_CLR_PORT_1 - GPIO_SINT_EDGE_CLR_PORT_0)
#define GPIO_SINT_EDGE_CLR_PORT_X(n) \
    (GPIO_SINT_EDGE_CLR_PORT_0 + ((n)*GPIO_SINT_EDGE_CLR_PORT_SIZE))

#define GPIO_AINT_EDGE_CLR_PORT_0 ((uint32)0xE80U)
#define GPIO_AINT_EDGE_CLR_PORT_1 ((uint32)0xE90U)
#define GPIO_AINT_EDGE_CLR_PORT_SIZE \
    (GPIO_AINT_EDGE_CLR_PORT_1 - GPIO_AINT_EDGE_CLR_PORT_0)
#define GPIO_AINT_EDGE_CLR_PORT_X(n) \
    (GPIO_AINT_EDGE_CLR_PORT_0 + ((n)*GPIO_AINT_EDGE_CLR_PORT_SIZE))

#define GPIO_AINT_EN_PORT_0 ((uint32)0xB00U)
#define GPIO_AINT_EN_PORT_1 ((uint32)0xB10U)
#define GPIO_AINT_EN_PORT_SIZE \
    (GPIO_AINT_EN_PORT_1 - GPIO_AINT_EN_PORT_0)
#define GPIO_AINT_EN_PORT_X(n) \
    (GPIO_AINT_EN_PORT_0 + ((n)*GPIO_AINT_EN_PORT_SIZE))

#define GPIO_AINT_TYPE_PORT_0 ((uint32)0xC00U)
#define GPIO_AINT_TYPE_PORT_1 ((uint32)0xC10U)
#define GPIO_AINT_TYPE_PORT_SIZE \
    (GPIO_AINT_TYPE_PORT_1 - GPIO_AINT_TYPE_PORT_0)
#define GPIO_AINT_TYPE_PORT_X(n) \
    (GPIO_AINT_TYPE_PORT_0 + ((n)*GPIO_AINT_TYPE_PORT_SIZE))

#define GPIO_AINT_POL_PORT_0 ((uint32)0xC80U)
#define GPIO_AINT_POL_PORT_1 ((uint32)0xC90U)
#define GPIO_AINT_POL_PORT_SIZE \
    (GPIO_AINT_POL_PORT_1 - GPIO_AINT_POL_PORT_0)
#define GPIO_AINT_POL_PORT_X(n) \
    (GPIO_AINT_POL_PORT_0 + ((n)*GPIO_AINT_POL_PORT_SIZE))

#define GPIO_AINT_BOTH_EDGE_PORT_0 ((uint32)0xD00U)
#define GPIO_AINT_BOTH_EDGE_PORT_1 ((uint32)0xD10U)
#define GPIO_AINT_BOTH_EDGE_PORT_SIZE \
    (GPIO_AINT_BOTH_EDGE_PORT_1 - GPIO_AINT_BOTH_EDGE_PORT_0)
#define GPIO_AINT_BOTH_EDGE_PORT_X(n) \
    (GPIO_AINT_BOTH_EDGE_PORT_0 + ((n)*GPIO_AINT_BOTH_EDGE_PORT_SIZE))

#define GPIO_AINT_MASK_PORT_0 ((uint32)0xB80U)
#define GPIO_AINT_MASK_PORT_1 ((uint32)0xB90U)
#define GPIO_AINT_MASK_PORT_SIZE \
    (GPIO_AINT_MASK_PORT_1 - GPIO_AINT_MASK_PORT_0)
#define GPIO_AINT_MASK_PORT_X(n) \
    (GPIO_AINT_MASK_PORT_0 + ((n)*GPIO_AINT_MASK_PORT_SIZE))

#define GPIO_AINT_STATUS_PORT_0 ((uint32)0xD80U)
#define GPIO_AINT_STATUS_PORT_1 ((uint32)0xD90U)
#define GPIO_AINT_STATUS_PORT_SIZE \
    (GPIO_AINT_STATUS_PORT_1 - GPIO_AINT_STATUS_PORT_0)
#define GPIO_AINT_STATUS_PORT_X(n) \
    (GPIO_AINT_STATUS_PORT_0 + ((n)*GPIO_AINT_STATUS_PORT_SIZE))

LOCAL_INLINE uint32 Dio_Get_Base_per_Channel(Dio_ChannelType *Channel)
{
    VAR(uint32, AUTOMATIC) BaseAddr = 0;

    if (NULL_PTR != Channel) {
        if (DIO_SF_CHANNEL_NUM > *Channel) {
            BaseAddr = APB_GPIO_SF_BASE;
        } else {
#ifndef SEMIDRIVE_E3_LITE_SERIES
            *Channel -= DIO_SF_CHANNEL_NUM;
            BaseAddr = APB_GPIO_AP_BASE;
#endif
        }
    }

    return BaseAddr;
}

LOCAL_INLINE uint32 Dio_Get_Base_per_Port(Dio_PortType *Port)
{
    VAR(uint32, AUTOMATIC) BaseAddr = 0;

    if (NULL_PTR != Port) {
        if (DIO_SF_PORT_NUM > *Port) {
            BaseAddr = APB_GPIO_SF_BASE;
        } else {
#ifndef SEMIDRIVE_E3_LITE_SERIES
            *Port -= DIO_SF_PORT_NUM;
            BaseAddr = APB_GPIO_AP_BASE;
#endif
        }

    }

    return BaseAddr;
}

/**
 * @brief   Return pin level status.
 *
 * @detials Return channel level status.
 *
 * @param   ChannelId ID of DIO Port.
 */
FUNC(Dio_LevelType, DIO_CODE) Dio_Ip_ReadChannel
(
    CONST(Dio_ChannelType, AUTOMATIC) ChannelId
);

/**
 * @brief   Write pin level status
 *
 * @detials Write pin level status
 *
 * @param   ChannelId ID of DIO Port.
 * @param   Level Value to be written.
 */
FUNC(void, DIO_CODE) Dio_Ip_WriteChannel
(
    CONST(Dio_ChannelType, AUTOMATIC) ChannelId,
    CONST(Dio_LevelType, AUTOMATIC) Level
);

/**
 * @brief   Returns the level of all channels of that port.
 *
 * @detials Returns the level of all channels of that port.
 *
 * @param   PortId ID of DIO channel.
 *
 * @return  Dio_PortLevelType Level of a subset of the adjoining bits of a port.
 */
FUNC(Dio_PortLevelType, DIO_CODE) Dio_Ip_ReadPort
(
    CONST(Dio_PortType, AUTOMATIC) PortId
);

/**
 * @brief   Service to set a value of the port.
 *
 * @detials Service to set a value of the port.
 *
 * @param   PortId ID of DIO channel.
 * @param   Level Value to be written.
 */
FUNC(void, DIO_CODE) Dio_Ip_WritePort
(
    CONST(Dio_PortType, AUTOMATIC) PortId,
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
FUNC(Dio_PortLevelType, DIO_CODE) Dio_Ip_ReadChannelGroup
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
FUNC(void, DIO_CODE) Dio_Ip_WriteChannelGroup
(
    P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) ChannelGroupIdPtr,
    CONST(Dio_PortLevelType, AUTOMATIC) Level
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
#if (DIO_FLIP_CHANNEL_API == STD_ON)
FUNC(Dio_LevelType, DIO_CODE) Dio_Ip_FlipChannel
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
FUNC(void, DIO_CODE) Dio_Ip_MaskedWritePort
(
    CONST(Dio_PortType, AUTOMATIC) PortId,
    CONST(Dio_PortLevelType, AUTOMATIC) Level,
    CONST(Dio_PortLevelType, AUTOMATIC) Mask
);
#endif

/* Non-AutoSAR APIs */
/**
 * @brief   Set pin output direction.
 *
 * @detials Set pin output direction.
 *
 * @param   Channel ID of DIO channel.
 * @param   Direction  direction.
 */
FUNC(void, DIO_CODE) Dio_Ip_SetPinDirection
(
    VAR(Dio_ChannelType, AUTOMATIC) Channel,
    VAR(Dio_DirectionType, AUTOMATIC) Direction
);

/**
 * @brief   Configure Interrupt Trigger Conditions.
 *
 * @detials Configure Interrupt Trigger Conditions.
 *
 * @param   Channel ID of DIO channel.
 * @param   InterruptType  InterruptType Type only valid for LEVEL sensitive(LOW_LEVEL/HIGH_LEVEL).
 */
FUNC(void, DIO_CODE) Dio_Ip_EnablePinInterruptDetect
(
    VAR(Dio_ChannelType, AUTOMATIC) ChannelId,
    VAR(Dio_DetectionType, AUTOMATIC) InterruptType
);

/**
 * @brief   Configure Async Interrupt Trigger Conditions.
 *
 * @detials Configure Async Interrupt Trigger Conditions.
 *
 * @param   Channel ID of DIO channel.
 * @param   InterruptType  InterruptType Type only valid for LEVEL sensitive(LOW_LEVEL/HIGH_LEVEL).
 */
FUNC(void, DIO_CODE) Dio_Ip_EnableAsyncInterruptDetect
(
    VAR(Dio_ChannelType, AUTOMATIC) ChannelId,
    VAR(Dio_DetectionType, AUTOMATIC) InterruptType
);

/**
 * @brief   Clear interruption status.
 *
 * @detials Clear interruption status.
 *
 * @param   ChannelId ID of DIO channel.
 */
FUNC(void, DIO_CODE) Dio_Ip_IrqStatusClear
(
    CONST(Dio_ChannelType, AUTOMATIC) ChannelId
);

/**
 * @brief   Clear async interruption status.
 *
 * @detials Clear interruption status.
 *
 * @param   ChannelId ID of DIO channel.
 */
FUNC(void, DIO_CODE) Dio_Ip_AsyncIrqStatusClear
(
    CONST(Dio_ChannelType, AUTOMATIC) ChannelId
);

/**
 * @brief   Interrupt handling.
 *
 * @detials Interrupt handling.
 *
 * @param   PortId interrupt number.
 */
FUNC(void, DIO_CODE) Dio_Ip_IrqHandler
(
    VAR(uint8, AUTOMATIC) PortId
);

#ifdef __cplusplus
}
#endif

#endif
