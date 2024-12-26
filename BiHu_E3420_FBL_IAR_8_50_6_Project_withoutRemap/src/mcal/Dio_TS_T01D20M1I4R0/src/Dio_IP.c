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
 * @file  Dio_IP.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Dio
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "__regs_base.h"
#include "Dio_IP.h"
#include "Dio_UserCallouts.h"
#include "RegHelper.h"
#include "SchM_Dio.h"
#include "Dio_Irq.h"
#include "arch.h"
/* Version and Check Begin */
/* Version Info Begin */
#define DIO_IP_C_VENDOR_ID    0x8C
#define DIO_IP_C_AR_RELEASE_MAJOR_VERSION    4
#define DIO_IP_C_AR_RELEASE_MINOR_VERSION    3
#define DIO_IP_C_AR_RELEASE_REVISION_VERSION 1
#define DIO_IP_C_SW_MAJOR_VERSION    1
#define DIO_IP_C_SW_MINOR_VERSION    0
#define DIO_IP_C_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((DIO_IP_C_AR_RELEASE_MAJOR_VERSION != DIO_IP_H_AR_RELEASE_MAJOR_VERSION)\
    || (DIO_IP_C_AR_RELEASE_MINOR_VERSION != DIO_IP_H_AR_RELEASE_MINOR_VERSION)\
    || (DIO_IP_C_AR_RELEASE_REVISION_VERSION != DIO_IP_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Dio_IP.c and Dio_IP.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((DIO_IP_C_SW_MAJOR_VERSION != DIO_IP_H_SW_MAJOR_VERSION)\
    || (DIO_IP_C_SW_MINOR_VERSION != DIO_IP_H_SW_MINOR_VERSION)\
    || (DIO_IP_C_SW_PATCH_VERSION != DIO_IP_H_SW_PATCH_VERSION))
#error "Opps, Dio_IP.c and Dio_IP.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((DIO_IP_C_AR_RELEASE_MAJOR_VERSION != REGHELPER_H_AR_RELEASE_MAJOR_VERSION)\
    || (DIO_IP_C_AR_RELEASE_MINOR_VERSION != REGHELPER_H_AR_RELEASE_MINOR_VERSION)\
    || (DIO_IP_C_AR_RELEASE_REVISION_VERSION != REGHELPER_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Dio_IP.c and RegHelper.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((DIO_IP_C_SW_MAJOR_VERSION != REGHELPER_H_SW_MAJOR_VERSION)\
    || (DIO_IP_C_SW_MINOR_VERSION != REGHELPER_H_SW_MINOR_VERSION)\
    || (DIO_IP_C_SW_PATCH_VERSION != REGHELPER_H_SW_PATCH_VERSION))
#error "Opps, Dio_IP.c and RegHelper.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((DIO_IP_C_AR_RELEASE_MAJOR_VERSION != SCHM_DIO_H_AR_RELEASE_MAJOR_VERSION)\
    || (DIO_IP_C_AR_RELEASE_MINOR_VERSION != SCHM_DIO_H_AR_RELEASE_MINOR_VERSION)\
    || (DIO_IP_C_AR_RELEASE_REVISION_VERSION != SCHM_DIO_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Dio_IP.c and SchM_Dio.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((DIO_IP_C_SW_MAJOR_VERSION != SCHM_DIO_H_SW_MAJOR_VERSION)\
    || (DIO_IP_C_SW_MINOR_VERSION != SCHM_DIO_H_SW_MINOR_VERSION)\
    || (DIO_IP_C_SW_PATCH_VERSION != SCHM_DIO_H_SW_PATCH_VERSION))
#error "Opps, Dio_IP.c and SchM_Dio.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */

#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"

/* find the lowest bit position */
static FUNC(uint8, DIO_CODE) GetLowestINTBitPos
(
    VAR(uint32, AUTOMATIC) reg
)
{
    uint8 pos = 0U;

    while ((reg & 0x01U) == 0x0U) {
        reg >>= 1;
        ++pos;
    }

    return pos;
}

FUNC (Dio_LevelType, DIO_CODE) Dio_Ip_ReadChannel
(
    CONST(Dio_ChannelType, AUTOMATIC) ChannelId
)
{
    VAR(uint32, AUTOMATIC) RegisterVal = 0U;
    VAR(uint32, AUTOMATIC) GpioBaseAddr = 0U;
    VAR(Dio_LevelType, AUTOMATIC) RetVal = (Dio_LevelType)STD_LOW;
    VAR(Dio_ChannelType, AUTOMATIC) Channel = ChannelId;

    GpioBaseAddr = Dio_Get_Base_per_Channel(&Channel);

    RegisterVal = REG_READ32(GpioBaseAddr + GPIO_DATA_IN_PORT_X(PIN_OFFSET((uint32)Channel)));

    /* Read the Channel level and decide the return value */
    if ((RegisterVal & (uint32)(0x01UL << PIN_BIT((uint32)Channel))) != 0U) {
        RetVal = (Dio_LevelType)STD_HIGH;
    } else {
        /* No action required, Required by MISRA  */
    }

    return RetVal;
}

FUNC (void, DIO_CODE) Dio_Ip_WriteChannel
(
    CONST(Dio_ChannelType, AUTOMATIC)   ChannelId,
    CONST(Dio_LevelType, AUTOMATIC)     Level
)
{
    VAR(Dio_ChannelType, AUTOMATIC) Channel = ChannelId;
    VAR(uint32, AUTOMATIC) GpioBaseAddr;

    GpioBaseAddr = Dio_Get_Base_per_Channel(&Channel);

    if ((Dio_LevelType)STD_HIGH == Level) {
        REG_WRITE32((uint32)0x01U << PIN_BIT((uint32)Channel),
                    GpioBaseAddr + GPIO_DATA_OUT_PORT_X(PIN_OFFSET((uint32)Channel)) + GPIO_SET_PIN);
    } else if ((Dio_LevelType)STD_LOW == Level) {
        REG_WRITE32((uint32)0x01U << PIN_BIT((uint32)Channel),
                    GpioBaseAddr + GPIO_DATA_OUT_PORT_X(PIN_OFFSET((uint32)Channel)) + GPIO_CLEAR_PIN);
    } else {
        /* No action required, Required by MISRA  */
    }
}

FUNC(Dio_PortLevelType, DIO_CODE) Dio_Ip_ReadPort
(
    CONST(Dio_PortType, AUTOMATIC) PortId
)
{
    VAR(Dio_PortLevelType, AUTOMATIC) RetVal = 0U;
    VAR(uint32, AUTOMATIC) GpioBaseAddr = 0U;
    VAR(Dio_PortType, AUTOMATIC) Port = PortId;

    GpioBaseAddr = Dio_Get_Base_per_Port(&Port);

    RetVal = (Dio_PortLevelType)(REG_READ32(GpioBaseAddr + (uint32)GPIO_DATA_IN_PORT_X((uint32)Port)));

    return RetVal;
}

FUNC(void, DIO_CODE) Dio_Ip_WritePort
(
    CONST(Dio_PortType,      AUTOMATIC) PortId,
    CONST(Dio_PortLevelType, AUTOMATIC) Level
)
{
    VAR(uint32, AUTOMATIC) GpioBaseAddr = 0U;
    VAR(Dio_PortType, AUTOMATIC) Port = PortId;

    /* write the data out */
    GpioBaseAddr = Dio_Get_Base_per_Port(&Port);

    REG_WRITE32(Level, GpioBaseAddr + GPIO_DATA_OUT_PORT_X(Port));
}

FUNC(Dio_PortLevelType, DIO_CODE) Dio_Ip_ReadChannelGroup
(
    P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) ChannelGroupIdPtr
)
{
    VAR(uint32, AUTOMATIC) RegisterVal = 0U;
    VAR(Dio_PortLevelType, AUTOMATIC) RetVal = 0U;

    /* read ChannelGroup data in */
    if (DIO_SF_PORT_NUM > ChannelGroupIdPtr->port) {
        RegisterVal = REG_READ32((uint32)APB_GPIO_SF_BASE + (uint32)GPIO_DATA_IN_PORT_X(
                                     ChannelGroupIdPtr->port));
        RetVal = (Dio_PortLevelType)(((uint32)RegisterVal & (uint32)ChannelGroupIdPtr->mask) >>
                                     ChannelGroupIdPtr->offset);
    } else {
#ifndef SEMIDRIVE_E3_LITE_SERIES
        RegisterVal = REG_READ32(APB_GPIO_AP_BASE + (uint32)GPIO_DATA_IN_PORT_X(ChannelGroupIdPtr->port -
                                 (uint32)DIO_SF_PORT_NUM));
        RetVal = (Dio_PortLevelType)(((uint32)RegisterVal & (uint32)ChannelGroupIdPtr->mask) >>
                                     ChannelGroupIdPtr->offset);
#endif
    }

    return RetVal;
}

FUNC(void, DIO_CODE) Dio_Ip_WriteChannelGroup
(
    P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) ChannelGroupIdPtr,
    CONST  (Dio_PortLevelType,    AUTOMATIC)                 Level
)
{
    VAR(uint32, AUTOMATIC) PortVal = 0U;
    VAR(uint32, AUTOMATIC) RegisterVal = 0U;

    PortVal = (uint32)(((uint32)Level << (uint32)ChannelGroupIdPtr->offset) &
                       (uint32) ChannelGroupIdPtr->mask);

    SchM_Enter_Dio_DIO_EXCLUSIVE_AREA_00();

    if (DIO_SF_PORT_NUM > ChannelGroupIdPtr->port) {
        /* read the DATA out first */
        RegisterVal = REG_READ32(APB_GPIO_SF_BASE + GPIO_DATA_OUT_PORT_X(ChannelGroupIdPtr->port));
        RegisterVal &= (~((uint32) ChannelGroupIdPtr->mask));
        /* write the ChannelGroup data out */
        REG_WRITE32((RegisterVal | PortVal),
                    APB_GPIO_SF_BASE + GPIO_DATA_OUT_PORT_X(ChannelGroupIdPtr->port));
    } else {
#ifndef SEMIDRIVE_E3_LITE_SERIES
        /* read the DATA out first */
        RegisterVal = REG_READ32(APB_GPIO_AP_BASE + GPIO_DATA_OUT_PORT_X(ChannelGroupIdPtr->port -
                                 (uint32)DIO_SF_PORT_NUM));
        RegisterVal &= (~((uint32) ChannelGroupIdPtr->mask));
        /* write the ChannelGroup data out */
        REG_WRITE32((RegisterVal | PortVal),
                    APB_GPIO_AP_BASE + GPIO_DATA_OUT_PORT_X(ChannelGroupIdPtr->port - (uint32)DIO_SF_PORT_NUM));
#endif
    }

    SchM_Exit_Dio_DIO_EXCLUSIVE_AREA_00();
}


#if (DIO_FLIP_CHANNEL_API == STD_ON)
FUNC(Dio_LevelType, DIO_CODE) Dio_Ip_FlipChannel
(
    CONST(Dio_ChannelType, AUTOMATIC) ChannelId
)
{
    VAR(Dio_LevelType, AUTOMATIC) RetVal = 0U;
    VAR(uint32, AUTOMATIC) RegisterVal = 0U;
    VAR(Dio_ChannelType, AUTOMATIC) Channel = ChannelId;
    VAR(uint32, AUTOMATIC) GpioBaseAddr = 0U;

    GpioBaseAddr = Dio_Get_Base_per_Channel(&Channel);

    /* flip the Channel */
    REG_WRITE32((uint32)0x01U << PIN_BIT((uint32)Channel),
                GpioBaseAddr + GPIO_DATA_OUT_PORT_X(PIN_OFFSET((uint32)Channel)) + GPIO_TOGGLE_PIN);

    /* read the data in flipped */
    RegisterVal = REG_READ32(GpioBaseAddr + GPIO_DATA_OUT_PORT_X(PIN_OFFSET((uint32)Channel))) &
                  (0x01UL << PIN_BIT((uint32)Channel));
    RetVal = (Dio_LevelType)(RegisterVal >> PIN_BIT((uint32)Channel));

    return RetVal;
}
#endif

#if (DIO_MASKEDWRITEPORT_API == STD_ON)
FUNC(void, DIO_CODE) Dio_Ip_MaskedWritePort
(
    CONST(Dio_PortType,      AUTOMATIC) PortId,
    CONST(Dio_PortLevelType, AUTOMATIC) Level,
    CONST(Dio_PortLevelType, AUTOMATIC) Mask
)
{
    VAR(uint32, AUTOMATIC) RegisterVal = 0U;
    VAR(Dio_PortType, AUTOMATIC) Port = PortId;
    VAR(uint32, AUTOMATIC) GpioBaseAddr = 0U;

    GpioBaseAddr = Dio_Get_Base_per_Port(&Port);

    SchM_Enter_Dio_DIO_EXCLUSIVE_AREA_01();

    /* read the DATA out first, and clear Masked bits */
    RegisterVal = REG_READ32(GpioBaseAddr + GPIO_DATA_OUT_PORT_X(Port));
    RegisterVal &= (~Mask);

    /* write the ChannelGroup data out */
    REG_WRITE32((RegisterVal | (Level & Mask)), GpioBaseAddr + GPIO_DATA_OUT_PORT_X(Port));

    SchM_Exit_Dio_DIO_EXCLUSIVE_AREA_01();
}
#endif

/* Non-AutoSAR APIs */

FUNC(void, DIO_CODE) Dio_Ip_SetPinDirection
(
    VAR(Dio_ChannelType, AUTOMATIC) Channel,
    VAR(Dio_DirectionType, AUTOMATIC) Direction
)
{
    VAR(uint32, AUTOMATIC) RegisterVal = 0U;
    VAR(uint32, AUTOMATIC) GpioBaseAddr = 0U;

    GpioBaseAddr = Dio_Get_Base_per_Channel(&Channel);

    SchM_Enter_Dio_DIO_EXCLUSIVE_AREA_01();

    RegisterVal = REG_READ32(GpioBaseAddr + GPIO_OEN_PORT_X(PIN_OFFSET((uint32)Channel)));
    RegisterVal &= ~(0x01UL << PIN_BIT((uint32)Channel));

    if (DIO_OUTPUT == Direction) {
        RegisterVal |= ((uint32)0x01U << PIN_BIT((uint32)Channel));
    }

    REG_WRITE32(RegisterVal, GpioBaseAddr + GPIO_OEN_PORT_X(PIN_OFFSET((uint32)Channel)));

    SchM_Exit_Dio_DIO_EXCLUSIVE_AREA_01();
}

FUNC(void, DIO_CODE) Dio_Ip_EnablePinInterruptDetect
(
    VAR(Dio_ChannelType, AUTOMATIC) ChannelId,
    VAR(Dio_DetectionType, AUTOMATIC) InterruptType
)
{
    VAR(uint32, AUTOMATIC) GpioBaseAddr = 0U;
    VAR(uint32, AUTOMATIC) RegisterVal = 0U;
    VAR(Dio_DirectionType, AUTOMATIC) Direction = DIO_INPUT;

    GpioBaseAddr = Dio_Get_Base_per_Channel(&ChannelId);

    RegisterVal = REG_READ32(GpioBaseAddr + GPIO_OEN_PORT_X(PIN_OFFSET((uint32)ChannelId)));

    Direction = (Dio_DirectionType)(uint32)((RegisterVal >> PIN_BIT((uint32)ChannelId)) & 0x1UL);

    if ((DIO_OUTPUT == Direction) || (InterruptType == DIO_NONE)) {
        /* clear interrupt status */
        REG_WRITE32((uint32)0x1 << PIN_BIT((uint32)ChannelId),
                    GpioBaseAddr + GPIO_SINT_EDGE_CLR_PORT_X(PIN_OFFSET((uint32)ChannelId)) + GPIO_CLEAR_PIN);
        /* disable the interrupt */
        REG_WRITE32((uint32)0x1 << PIN_BIT((uint32)ChannelId),
                    GpioBaseAddr + GPIO_SINT_EN_PORT_X(PIN_OFFSET((uint32)ChannelId)) + GPIO_CLEAR_PIN);
    } else {
        REG_WRITE32((uint32)0x1U << PIN_BIT((uint32)ChannelId),
                    GpioBaseAddr + GPIO_SINT_TYPE_PORT_X(PIN_OFFSET((uint32)ChannelId)) + GPIO_CLEAR_PIN);
        REG_WRITE32((uint32)0x1U << PIN_BIT((uint32)ChannelId),
                    GpioBaseAddr + GPIO_SINT_POL_PORT_X(PIN_OFFSET((uint32)ChannelId)) + GPIO_CLEAR_PIN);
        REG_WRITE32((uint32)0x1U << PIN_BIT((uint32)ChannelId),
                    GpioBaseAddr + GPIO_SINT_BOTH_EDGE_PORT_X(PIN_OFFSET((uint32)ChannelId)) + GPIO_CLEAR_PIN);

        switch (InterruptType) {
        case DIO_LOW_LEVEL:
            /* Configure low level interrupts according to the above three sentences */
            break;

        case DIO_HIGH_LEVEL:
            REG_WRITE32(INT_POL_HIGH_POS << PIN_BIT((uint32)ChannelId),
                        GpioBaseAddr + GPIO_SINT_POL_PORT_X(PIN_OFFSET((uint32)ChannelId)) + GPIO_SET_PIN);
            break;

        case DIO_RISING_EDGE:
            REG_WRITE32(INT_TYPE_PULSE << PIN_BIT((uint32)ChannelId),
                        GpioBaseAddr + GPIO_SINT_TYPE_PORT_X(PIN_OFFSET((uint32)ChannelId)) + GPIO_SET_PIN);
            REG_WRITE32(INT_POL_HIGH_POS << PIN_BIT((uint32)ChannelId),
                        GpioBaseAddr + GPIO_SINT_POL_PORT_X(PIN_OFFSET((uint32)ChannelId)) + GPIO_SET_PIN);
            break;

        case DIO_FALLING_EDGE:
            REG_WRITE32(INT_TYPE_PULSE << PIN_BIT((uint32)ChannelId),
                        GpioBaseAddr + GPIO_SINT_TYPE_PORT_X(PIN_OFFSET((uint32)ChannelId)) + GPIO_SET_PIN);
            break;

        case DIO_BOTH_EDGE:
            REG_WRITE32(INT_TYPE_PULSE << PIN_BIT((uint32)ChannelId),
                        GpioBaseAddr + GPIO_SINT_TYPE_PORT_X(PIN_OFFSET((uint32)ChannelId)) + GPIO_SET_PIN);
            REG_WRITE32(INT_BOE_BOTH_EDGE << PIN_BIT((uint32)ChannelId),
                        GpioBaseAddr + GPIO_SINT_BOTH_EDGE_PORT_X(PIN_OFFSET((uint32)ChannelId)) + GPIO_SET_PIN);
            break;

        default:
            break;
        }

        /*mask interrupt */
        REG_WRITE32((uint32)0x1U << PIN_BIT((uint32)ChannelId),
                    GpioBaseAddr + GPIO_SINT_MASK_PORT_X(PIN_OFFSET((uint32)ChannelId)) + GPIO_SET_PIN);

        /* clear interrupt status */
        REG_WRITE32((uint32)0x1U << PIN_BIT((uint32)ChannelId),
                    GpioBaseAddr + GPIO_SINT_EDGE_CLR_PORT_X(PIN_OFFSET((uint32)ChannelId)) + GPIO_CLEAR_PIN);

        /* unmask interrupt */
        REG_WRITE32((uint32)0x1U << PIN_BIT((uint32)ChannelId),
                    GpioBaseAddr + GPIO_SINT_MASK_PORT_X(PIN_OFFSET((uint32)ChannelId)) + GPIO_CLEAR_PIN);

        /* enable interrupt */
        REG_WRITE32((uint32)0x1U << PIN_BIT((uint32)ChannelId),
                    GpioBaseAddr + GPIO_SINT_EN_PORT_X(PIN_OFFSET((uint32)ChannelId)) + GPIO_SET_PIN);
    }

}

FUNC(void, DIO_CODE) Dio_Ip_EnableAsyncInterruptDetect
(
    VAR(Dio_ChannelType, AUTOMATIC) ChannelId,
    VAR(Dio_DetectionType, AUTOMATIC) InterruptType
)
{
    VAR(uint32, AUTOMATIC) GpioBaseAddr = 0U;
    VAR(uint32, AUTOMATIC) RegisterVal = 0U;
    VAR(Dio_DirectionType, AUTOMATIC) Direction = DIO_INPUT;

    GpioBaseAddr = Dio_Get_Base_per_Channel(&ChannelId);

    RegisterVal = REG_READ32(GpioBaseAddr + GPIO_OEN_PORT_X(PIN_OFFSET((uint32)ChannelId)));

    Direction = (Dio_DirectionType)(uint32)((RegisterVal >> PIN_BIT((uint32)ChannelId)) & 0x1UL);

    if ((DIO_OUTPUT == Direction) || (InterruptType == DIO_NONE)) {
        /* clear interrupt status */
        REG_WRITE32((uint32)0x1 << PIN_BIT((uint32)ChannelId),
                    GpioBaseAddr + GPIO_AINT_EDGE_CLR_PORT_X(PIN_OFFSET((uint32)ChannelId)) + GPIO_CLEAR_PIN);
        /* disable the interrupt */
        REG_WRITE32((uint32)0x1 << PIN_BIT((uint32)ChannelId),
                    GpioBaseAddr + GPIO_AINT_EN_PORT_X(PIN_OFFSET((uint32)ChannelId)) + GPIO_CLEAR_PIN);
    } else {
        REG_WRITE32((uint32)0x1U << PIN_BIT((uint32)ChannelId),
                    GpioBaseAddr + GPIO_AINT_TYPE_PORT_X(PIN_OFFSET((uint32)ChannelId)) + GPIO_CLEAR_PIN);
        REG_WRITE32((uint32)0x1U << PIN_BIT((uint32)ChannelId),
                    GpioBaseAddr + GPIO_AINT_POL_PORT_X(PIN_OFFSET((uint32)ChannelId)) + GPIO_CLEAR_PIN);
        REG_WRITE32((uint32)0x1U << PIN_BIT((uint32)ChannelId),
                    GpioBaseAddr + GPIO_AINT_BOTH_EDGE_PORT_X(PIN_OFFSET((uint32)ChannelId)) + GPIO_CLEAR_PIN);

        switch (InterruptType) {
        case DIO_LOW_LEVEL:
            /* Configure low level interrupts according to the above three sentences */
            break;

        case DIO_HIGH_LEVEL:
            REG_WRITE32(INT_POL_HIGH_POS << PIN_BIT((uint32)ChannelId),
                        GpioBaseAddr + GPIO_AINT_POL_PORT_X(PIN_OFFSET((uint32)ChannelId)) + GPIO_SET_PIN);
            break;

        case DIO_RISING_EDGE:
            REG_WRITE32(INT_TYPE_PULSE << PIN_BIT((uint32)ChannelId),
                        GpioBaseAddr + GPIO_AINT_TYPE_PORT_X(PIN_OFFSET((uint32)ChannelId)) + GPIO_SET_PIN);
            REG_WRITE32(INT_POL_HIGH_POS << PIN_BIT((uint32)ChannelId),
                        GpioBaseAddr + GPIO_AINT_POL_PORT_X(PIN_OFFSET((uint32)ChannelId)) + GPIO_SET_PIN);
            break;

        case DIO_FALLING_EDGE:
            REG_WRITE32(INT_TYPE_PULSE << PIN_BIT((uint32)ChannelId),
                        GpioBaseAddr + GPIO_AINT_TYPE_PORT_X(PIN_OFFSET((uint32)ChannelId)) + GPIO_SET_PIN);
            break;

        case DIO_BOTH_EDGE:
            REG_WRITE32(INT_TYPE_PULSE << PIN_BIT((uint32)ChannelId),
                        GpioBaseAddr + GPIO_AINT_TYPE_PORT_X(PIN_OFFSET((uint32)ChannelId)) + GPIO_SET_PIN);
            REG_WRITE32(INT_BOE_BOTH_EDGE << PIN_BIT((uint32)ChannelId),
                        GpioBaseAddr + GPIO_AINT_BOTH_EDGE_PORT_X(PIN_OFFSET((uint32)ChannelId)) + GPIO_SET_PIN);
            break;

        default:
            break;
        }

        /*mask interrupt */
        REG_WRITE32((uint32)0x1U << PIN_BIT((uint32)ChannelId),
                    GpioBaseAddr + GPIO_AINT_MASK_PORT_X(PIN_OFFSET((uint32)ChannelId)) + GPIO_SET_PIN);

        /* clear interrupt status */
        REG_WRITE32((uint32)0x1U << PIN_BIT((uint32)ChannelId),
                    GpioBaseAddr + GPIO_AINT_EDGE_CLR_PORT_X(PIN_OFFSET((uint32)ChannelId)) + GPIO_CLEAR_PIN);

        /* unmask interrupt */
        REG_WRITE32((uint32)0x1U << PIN_BIT((uint32)ChannelId),
                    GpioBaseAddr + GPIO_AINT_MASK_PORT_X(PIN_OFFSET((uint32)ChannelId)) + GPIO_CLEAR_PIN);

        /* enable interrupt */
        REG_WRITE32((uint32)0x1U << PIN_BIT((uint32)ChannelId),
                    GpioBaseAddr + GPIO_AINT_EN_PORT_X(PIN_OFFSET((uint32)ChannelId)) + GPIO_SET_PIN);
    }

}

FUNC(void, DIO_CODE) Dio_Ip_IrqHandler
(
    VAR(uint8, AUTOMATIC) PortId
)
{
    VAR(uint32, AUTOMATIC) v = 0U;
    VAR(uint32, AUTOMATIC) RegisterVal = 0U;
    VAR(uint32, AUTOMATIC) GpioBaseAddr = 0U;
    VAR(uint32, AUTOMATIC) ChannelId = 0U;

    GpioBaseAddr = Dio_Get_Base_per_Port(&PortId);

    /* clear sync irq */
    while ((RegisterVal = REG_READ32(GpioBaseAddr + GPIO_SINT_STATUS_PORT_X(PortId))) > 0U) {

        if (APB_GPIO_SF_BASE == GpioBaseAddr) {
            ChannelId = GetLowestINTBitPos(RegisterVal) + (uint32)PortId * 32U;
        } else {
            ChannelId = GetLowestINTBitPos(RegisterVal) + (uint32)PortId * 32U + DIO_SF_CHANNEL_NUM;
        }

        /* call user application */
        Dio_UserCallouts((uint8)ChannelId);
#ifndef SEMIDRIVE_E3_LITE_SERIES
        if (APB_GPIO_AP_BASE == GpioBaseAddr) {
            ChannelId -= DIO_SF_CHANNEL_NUM;
        }
#endif
        v = REG_READ32(GpioBaseAddr + GPIO_SINT_TYPE_PORT_X(PIN_OFFSET(ChannelId)));

        if ((v & (0x1UL << PIN_BIT(ChannelId))) != 0U) {
            /* pulse sensitive, clear the interrupt status bit */
            REG_WRITE32(0x1UL << PIN_BIT(ChannelId),
                        GpioBaseAddr + GPIO_SINT_EDGE_CLR_PORT_X(PIN_OFFSET(ChannelId)) + GPIO_SET_PIN);
        } else {
            /* level sensitive, mask the interrupt after interrupt occour */
            REG_WRITE32(0x1UL << PIN_BIT(ChannelId),
                        GpioBaseAddr + GPIO_SINT_MASK_PORT_X(PIN_OFFSET(ChannelId)) + GPIO_SET_PIN);
        }
    }

    /* clear async irq */
    while ((RegisterVal = REG_READ32(GpioBaseAddr + GPIO_AINT_STATUS_PORT_X(PortId))) > 0U) {

        if (APB_GPIO_SF_BASE == GpioBaseAddr) {
            ChannelId = GetLowestINTBitPos(RegisterVal) + (uint32)PortId * 32U;
        } else {
            ChannelId = GetLowestINTBitPos(RegisterVal) + (uint32)PortId * 32U + DIO_SF_CHANNEL_NUM;
        }

        /* call user application */
        Dio_UserCallouts((uint8)ChannelId);
#ifndef SEMIDRIVE_E3_LITE_SERIES
        if (APB_GPIO_AP_BASE == GpioBaseAddr) {
            ChannelId -= DIO_SF_CHANNEL_NUM;
        }
#endif
        v = REG_READ32(GpioBaseAddr + GPIO_AINT_STATUS_PORT_X(PIN_OFFSET(ChannelId)));

        if ((v & (0x1UL << PIN_BIT(ChannelId))) != 0U) {
            /* pulse sensitive, clear the interrupt status bit */
            REG_WRITE32(0x1UL << PIN_BIT(ChannelId),
                        GpioBaseAddr + GPIO_AINT_EDGE_CLR_PORT_X(PIN_OFFSET(ChannelId)) + GPIO_SET_PIN);
            dsb();
        } else {
            /* level sensitive, mask the interrupt after interrupt occour */
            REG_WRITE32(0x1UL << PIN_BIT(ChannelId),
                        GpioBaseAddr + GPIO_AINT_MASK_PORT_X(PIN_OFFSET(ChannelId)) + GPIO_SET_PIN);
            dsb();
        }
    }

}

FUNC(void, DIO_CODE) Dio_Ip_IrqStatusClear
(
    CONST(Dio_ChannelType, AUTOMATIC) ChannelId
)
{
    VAR(uint32, AUTOMATIC) v = 0U;
    VAR(Dio_ChannelType, AUTOMATIC) Channel = ChannelId;
    VAR(uint32, AUTOMATIC) GpioBaseAddr = 0U;

    GpioBaseAddr = Dio_Get_Base_per_Channel(&Channel);

    v = REG_READ32(GpioBaseAddr + GPIO_SINT_TYPE_PORT_X(PIN_OFFSET((uint32)Channel)));

    if ((v & ((uint32)0x1U << PIN_BIT((uint32)Channel))) != 0U) {
        /* pulse sensitive, clear the interrupt status bit */
        REG_WRITE32((uint32)0x1U << PIN_BIT((uint32)Channel),
                    GpioBaseAddr + GPIO_SINT_EDGE_CLR_PORT_X(PIN_OFFSET((uint32)Channel)) + GPIO_SET_PIN);
    } else {
        /* level sensitive, mask the interrupt after interrupt occour */
        REG_WRITE32((uint32)0x1U << PIN_BIT((uint32)Channel),
                    GpioBaseAddr + GPIO_SINT_MASK_PORT_X(PIN_OFFSET((uint32)Channel)) + GPIO_SET_PIN);
    }

}

FUNC(void, DIO_CODE) Dio_Ip_AsyncIrqStatusClear
(
    CONST(Dio_ChannelType, AUTOMATIC) ChannelId
)
{
    VAR(uint32, AUTOMATIC) v = 0U;
    VAR(Dio_ChannelType, AUTOMATIC) Channel = ChannelId;
    VAR(uint32, AUTOMATIC) GpioBaseAddr = 0U;

    GpioBaseAddr = Dio_Get_Base_per_Channel(&Channel);

    v = REG_READ32(GpioBaseAddr + GPIO_AINT_TYPE_PORT_X(PIN_OFFSET((uint32)Channel)));

    if ((v & ((uint32)0x1U << PIN_BIT((uint32)Channel))) != 0U) {
        /* pulse sensitive, clear the interrupt status bit */
        REG_WRITE32((uint32)0x1U << PIN_BIT((uint32)Channel),
                    GpioBaseAddr + GPIO_AINT_EDGE_CLR_PORT_X(PIN_OFFSET((uint32)Channel)) + GPIO_SET_PIN);
        dsb();
    } else {
        /* level sensitive, mask the interrupt after interrupt occour */
        REG_WRITE32((uint32)0x1U << PIN_BIT((uint32)Channel),
                    GpioBaseAddr + GPIO_AINT_MASK_PORT_X(PIN_OFFSET((uint32)Channel)) + GPIO_SET_PIN);
        dsb();
    }

}

#define DIO_ISR(id) \
ISR(GPIO_Irq##id##Handler)\
{\
    Dio_Ip_IrqHandler(((uint8)id##U) - ((uint8)1));\
}

DIO_ISR(1)
DIO_ISR(2)
DIO_ISR(3)
DIO_ISR(4)
DIO_ISR(5)
DIO_ISR(6)
DIO_ISR(7)
DIO_ISR(8)

#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"

#ifdef __cplusplus
}
#endif
