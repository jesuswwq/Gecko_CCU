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
 * @file  Sent_Types_E3.h
 * @brief Semidrive. MCAL Sent
 */


#ifndef SENT_TYPES_E3_H
#define SENT_TYPES_E3_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
/* Version and Check Begin */
/* Version Info Begin */
#define SENT_TYPES_H_VENDOR_ID    0x8C
#define SENT_TYPES_H_AR_RELEASE_MAJOR_VERSION    4
#define SENT_TYPES_H_AR_RELEASE_MINOR_VERSION    3
#define SENT_TYPES_H_AR_RELEASE_REVISION_VERSION 1
#define SENT_TYPES_H_SW_MAJOR_VERSION    1
#define SENT_TYPES_H_SW_MINOR_VERSION    0
#define SENT_TYPES_H_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((SENT_TYPES_H_AR_RELEASE_MAJOR_VERSION != STD_TYPES_H_AR_RELEASE_MAJOR_VERSION)\
    || (SENT_TYPES_H_AR_RELEASE_MINOR_VERSION != STD_TYPES_H_AR_RELEASE_MINOR_VERSION)\
    || (SENT_TYPES_H_AR_RELEASE_REVISION_VERSION != STD_TYPES_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Sent_Types_E3.h and Std_Types.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((SENT_TYPES_H_SW_MAJOR_VERSION != STD_TYPES_H_SW_MAJOR_VERSION)\
    || (SENT_TYPES_H_SW_MINOR_VERSION != STD_TYPES_H_SW_MINOR_VERSION)\
    || (SENT_TYPES_H_SW_PATCH_VERSION != STD_TYPES_H_SW_PATCH_VERSION))
#error "Opps, Sent_Types_E3.h and Std_Types.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */

/* Version Check End */
/* Version and Check End */

typedef uint8 Sent_IndexType;
typedef uint8 Sent_ChannelType;
typedef uint32 Sent_EdgeNumberType;
typedef uint32 Sent_ValueType;

typedef void(*Sent_FrameOverNotifType)(void);

/**
 * @enum Sent_HwModule
 * @brief Timer module index id
*/
typedef enum {
    SENT_INDEX_ETIMER1 = 0U,
    SENT_INDEX_ETIMER2 = 1U,
#ifndef SEMIDRIVE_E3_LITE_SERIES
    SENT_INDEX_ETIMER3 = 2U,
    SENT_INDEX_ETIMER4 = 3U,
#endif
} Sent_HwModule;

/**
 * @enum Sent_HwChannel
 * @brief Timer module hardware Channel id
*/
typedef enum {
    SENT_HW_CPT_A  = 0U,
    SENT_HW_CPT_B  = 1U,
    SENT_HW_CPT_C  = 2U,
    SENT_HW_CPT_D  = 3U
} Sent_HwChannel;

/**
 * @enum Sent_ClockRefType
 * @brief Timer module reference clock source
*/
typedef enum {
    SENT_SEL_HF_CLK = 0,
    SENT_SEL_AHF_CLK,
    SENT_SEL_EXT_CLK,
    SENT_SEL_LP_CLK,
} Sent_ClockRefType;

/**
 * @enum Sent_State
 * @brief Sent frame current status
*/
typedef enum {
    SENT_IDLE = 0U,
    SENT_SYNC,
    SENT_STATUS,
    SENT_DATA,
    SENT_CRC,
    SENT_PAUSE
} Sent_State;

/**
 * @enum Sent_ErrType
 * @brief Sent frame current error
*/
typedef enum {
    SENT_OK             = 0U,
    SENT_SYNC_ERR       = (1U << 0U),   /*! @brief Sync/Calibration pulse is not 56 ticks. */
    SENT_STATUS_ERR     = (1U << 1U),   /*! @brief Status signal error. */
    SENT_DATA_ERR       = (1U << 2U),   /*! @brief Nibble data is bigger than 15. */
    SENT_CRC_ERR        = (1U << 3U),   /*! @brief Nibble data is bigger than 15. */
    SENT_LOW_PULSE_ERR  = (1U << 4U),   /*! @brief Nibble low pulse width error. */
    SENT_MSB_NOT_ZERO   = (1U << 5U),   /*! @brief SENT_HIGH_SPEED_FORMAT Only. */
    SENT_INV_MSN_ERR    = (1U << 6U),   /*! @brief SENT_SINGLE_SECURE_FORMAT Only. */
    SENT_CONUNTER_VAL_ERR = (1U << 7U), /*! @brief SENT_SINGLE_SECURE_FORMAT Only. */
    SENT_TICK_FREQ_ERR  = (1U << 8U),   /*! @brief SENT_SINGLE_SECURE_FORMAT Only. */
    /*PRQA S 0646  1*/
    SENT_NOT_OK         = (1U << 31U),  /*! @brief SENT_SINGLE_SECURE_FORMAT Only. */
} Sent_ErrType;

/**
 * @enum Sent_FastChannelType
 * @brief Fast Channel Format Type
*/
typedef enum {
    SENT_STANDARD_FORMAT = 0U,
    SENT_SINGLE_SECURE_FORMAT,
    SENT_HIGH_SPEED_FORMAT
} Sent_FastChannelType;

/**
 * @enum Sent_BitNum
 * @brief Sent message section length
*/
typedef enum {
    SENT_DATA_WIDTH_4_BIT = 1,
    SENT_DATA_WIDTH_8_BIT,
    SENT_DATA_WIDTH_12_BIT,
    SENT_DATA_WIDTH_16_BIT,
    SENT_DATA_WIDTH_20_BIT,
    SENT_DATA_WIDTH_24_BIT,
} Sent_BitNum;

/**
 * @enum Sent_Frame
 * @brief Sent Frame Format Type
*/
typedef struct {
    VAR(uint8, AUTOMATIC) u8Dl;              /*! @brief Sent Frame message length */
    VAR(uint8, AUTOMATIC) u8RxIndex;         /*! @brief Sent Frame current message index */
    VAR(uint8, AUTOMATIC) u8Status;          /*! @brief Sent Frame status section value */
    VAR(uint8, AUTOMATIC) u8Rxframe[6];      /*! @brief Sent Frame message section */
    VAR(uint8, AUTOMATIC) u8Crc;             /*! @brief Sent Frame CRC section */
} Sent_Frame;

typedef struct {
    VAR(Sent_Frame, AUTOMATIC)           FrameInfo;  /*! @brief Sent frame infomation */
    VAR(Sent_FastChannelType, AUTOMATIC) eChnFormat; /*! @brief Sent Channel format */
    VAR(Sent_State, AUTOMATIC)           eCurstate;  /*! @brief Sent Channel current status */
    VAR(Sent_ErrType, AUTOMATIC)         eError;     /*! @brief Sent Channel current error infomation */
    VAR(boolean, AUTOMATIC)              bReadFlag;  /*! @brief Sent Channel current newest status */
} Sent_Channel;

typedef struct {
    VAR(uint32, AUTOMATIC) u32TotalFrame;
    VAR(uint32, AUTOMATIC) u32CorrectFrame;
    VAR(uint32, AUTOMATIC) u32ErrFrame;
} Sent_FrameNum;

/**
 * @struct Sent_CounterScaler
 * @brief Sent_Scaler value
*/
typedef struct {
    VAR(uint32, AUTOMATIC) u32ExpectScaler;       /*! @brief Theoretical calculation Tick prescaler*/
    VAR(uint32, AUTOMATIC) u32ActualScaler;       /*! @brief Actual synchronization segment Tick prescaler*/
} Sent_CounterScaler;

/**
 * @struct Sent_HwChannelConfigType
 * @brief Hardware Channel descriptions
*/
typedef struct {
    VAR(Sent_HwModule, AUTOMATIC) u8TimerModule;            /*! @brief Timer module ID ,0-1: Timer 0/1*/
    VAR(Sent_HwChannel, AUTOMATIC) u8HwChannel;             /*! @brief SENT hw channel ID,2-5:LOCAL_A/B/C/D */
    VAR(Sent_FastChannelType, AUTOMATIC) eFastChannel;      /*! @brief Fast Channel Format Type*/
    VAR(Sent_BitNum, AUTOMATIC) eDataBitNum;                /*! @brief Data bit number*/
    VAR(uint8, AUTOMATIC) u8LowPulseWid;                    /*! @brief Low Pulse Width*/
    VAR(uint8, AUTOMATIC) u8FifoWml;                        /*! @brief Fifo water mark level */
    VAR(boolean, AUTOMATIC) bFiterEnable;                   /*! @brief software fiter function enable */
    VAR(uint8, AUTOMATIC) u8SampleInterval;                 /*! @brief fiter function fiter interval clock */
    VAR(uint8, AUTOMATIC) u8FiterBandwidth;                 /*! @brief fiter function fiter negedge capture bandwidth */
    VAR(boolean, AUTOMATIC) bPausePulse;                    /*! @brief Pause Pulse */
    VAR(boolean, AUTOMATIC) bNotifyFrameOver;               /*! @brief FrameOverNotification function enable*/
    VAR(Sent_FrameOverNotifType, AUTOMATIC) pfFrameOverNotification; /*! @brief FrameOverNotification function pointer */
} Sent_HwChannelConfigType;

/**
 * @struct Sent_ChannelConfigType
 * @brief This type contains logic channel config data.
*/
typedef struct {
    VAR(uint32, AUTOMATIC) u32TickFrequency;            /*! @brief Transmitter frequency */
    P2CONST(Sent_HwChannelConfigType, SENT_CONST,
            SENT_APPL_DATA) SentHwChannelConfig;        /*! @brief hardware channel config */
} Sent_ChannelConfigType;

/**
 * @struct Sent_ConfigType
 * @brief This type contains initialization data.
*/
typedef struct {
    CONST(Sent_ChannelConfigType, SENT_CONST) (*ptrChannelConfig)[];
} Sent_ConfigType;

#ifdef __cplusplus
}
#endif

#endif /* SENT_TYPES_E3_H */

