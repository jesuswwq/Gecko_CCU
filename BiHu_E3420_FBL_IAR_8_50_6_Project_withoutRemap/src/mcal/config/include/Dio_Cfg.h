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
 * @file  Dio_Cfg.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Dio
 * @date 2023-09-22 17:02:49
 */

#ifndef DIO_CFG_H
#define DIO_CFG_H

#ifdef __cplusplus
extern "C" {
#endif
/* Version and Check Begin */
/* Version Info Begin */
#define DIO_CFG_H_VENDOR_ID    0x8C
#define DIO_CFG_H_AR_RELEASE_MAJOR_VERSION    4
#define DIO_CFG_H_AR_RELEASE_MINOR_VERSION    3
#define DIO_CFG_H_AR_RELEASE_REVISION_VERSION 1
#define DIO_CFG_H_SW_MAJOR_VERSION    1
#define DIO_CFG_H_SW_MINOR_VERSION    0
#define DIO_CFG_H_SW_PATCH_VERSION    0
/* Version Info End */
/* Version and Check End */

/**
* @brief    Function Development Error Detection eaable switch.
*/
#define DIO_DEV_ERROR_DETECT                (STD_OFF)
/**
* @brief    Function Dio_GetVersionInfo() enable switch.
*/
#define DIO_VERSION_INFO_API                (STD_ON)

/**
* @brief    Function Dio_GetVersionInfo() enable switch.
*/
#define DIO_FLIP_CHANNEL_API                (STD_ON)

/**
* @brief    Function Dio_MaskedWritePort() enable switch.
*/
#define DIO_MASKEDWRITEPORT_API             (STD_ON)

/**
* @brief    PORT number and Port channel mask define.
*/
#define DIO_MAXNOOFPORT                     ((Dio_PortType)7U)
#define DIO_MAXNOOFCHANNEL                  ((Dio_ChannelType)214U)


/**
* @brief    Symbolic name for port.
*/
#define DioConf_DioPort_DioPort_5  ((uint8)0x05U)

/**
* @brief    Symbolic name for channel.
*/
#define DioConf_DioChannel_RESET_6424_A_C_IN ((uint16)147U)

/**
* @brief    Symbolic name for port.
*/
#define DioConf_DioPort_DioPort_2  ((uint8)0x02U)

/**
* @brief    Symbolic name for channel.
*/
#define DioConf_DioChannel_TCA6424_INT ((uint16)91U)

/* Type definition for numeric id of Dio Port */
typedef uint8 Dio_PortType;

/* Type definition for level of a Dio Port */
typedef uint32 Dio_PortLevelType;

/* Type definition of a Dio Channel Group */
typedef struct {
    VAR(Dio_PortType, AUTOMATIC) port; /* Port Number on which Channel Group is defined */
    VAR(uint8, AUTOMATIC) offset; /* Defines the position of group from LSB */
    VAR(Dio_PortLevelType, AUTOMATIC)  mask; /* Defines the Position of Channel Group */
} Dio_ChannelGroupType;

typedef void (*Dio_NotifyType)(void);

typedef enum {
    RISINGEDGE,
    FALLINGEDGE,
    BOTHEDGE
}Dio_ISRType;

typedef enum {
    ISR_ENABLE,
    ISR_DISABLE
}Dio_ISREnableType;

typedef enum {
    Debounce_ENABLE,
    Debounce_DISABLE
}Dio_ISRDebounceType;

/* Type definition for numeric id of Dio Channels */
typedef uint16 Dio_ChannelType;

typedef struct {
    VAR(Dio_ChannelType, AUTOMATIC)   ChannelId;
    VAR(boolean, AUTOMATIC) ISREnable;
    VAR(Dio_ISRType, AUTOMATIC) ISRType;
    VAR(boolean, AUTOMATIC) ISRDebounce;
    VAR(Dio_NotifyType, AUTOMATIC) pfChannelNotification;
}Dio_ChannelISRConfigType;

typedef struct {
    VAR(Dio_ChannelISRConfigType , AUTOMATIC) ChannelGroupISR;
}Dio_ChannelGroupISRConfigType;

typedef struct {
    VAR(uint8, AUTOMATIC) PortIdx;
    P2CONST(Dio_ChannelGroupISRConfigType, AUTOMATIC, DIO_CONST) pChannelISRCfg;
}Dio_PortISRConfigType;


#ifdef __cplusplus
}
#endif

#endif
