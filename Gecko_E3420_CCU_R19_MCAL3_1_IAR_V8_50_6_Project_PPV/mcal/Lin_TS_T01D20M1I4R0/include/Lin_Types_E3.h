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
 * @file  Lin_TYpes_E3.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Lin
 */

#ifndef LIN_TYPES_H
#define LIN_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Mcu_Modules.h"
#include "Lin_GeneralTypes.h"

#define LIN_UART_TXBREAK_BIT(bit)          (bit - 8) + 0x1
#define LIN_UART_RXBREAK_BIT(bit)          (bit - 9) + 0x1


typedef enum {
    LIN_UART_PARITY_NONE,
    LIN_UART_PARITY_EVEN,
    LIN_UART_PARITY_ODD
} lin_uart_parity_e;

typedef enum {
    LIN_UART_MASTER,
    LIN_UART_SLAVE
} lin_uart_mode_e;

typedef enum {
    LIN_UART_CLASSIC_CS,
    LIN_UART_ENHANCED_CS
} lin_uart_cs_mode_e;

typedef enum {
    LIN_UART_STOP_1BIT,
    LIN_UART_STOP_0P5BIT,
    LIN_UART_STOP_2BIT,
    LIN_UART_STOP_1P5BIT
} lin_uart_stop_e;

typedef enum {
    LIN_INITIAL_STATE,
    LIN_WAIT_FOR_WAKEUP,
    LIN_ACTIVE,
} Lin_State;

typedef enum {
    LIN_OK,
    LIN_FRAMIN_ERROR,
    LIN_PARITY_ERROR,
    LIN_OVERRUN_ERROR,
    LIN_CHKSUM_ERROR,
    LIN_LINE_ERROR
} Lin_ErrorType;

typedef enum {
    LIN_FRAMEIDLE,
    LIN_FRAMETRANSMIT,
    LIN_FRAMETRANSMITERR,
    LIN_FRAMERECEIVE,
    LIN_FRAMERECEIVEERR,
    LIN_FRAMEPENDING,
    LIN_FRAMECHECKSUMERR,
    LIN_FRAMEABORT
} Lin_FrameState;


typedef void (*Lin_CallBackFn)(uint8 numId, uint8 *dataBuffer);
typedef void (*Lin_wakeupCallBackFn)(uint8 nodeId);

typedef struct {
    uint8            pid;
    uint8            cs;
    uint8            drc;
    uint8            dl;
    uint8            txframe[8];
    uint8            rxframe[9];
    Lin_State        currentState;
    Lin_FrameState   framestate;
    Lin_ErrorType    error;
} Lin_NodeData;

typedef struct {
    Lin_NodeData         channelInfo;
    const Lin_PduType    *pduInfo;
    Lin_StatusType       ChannelState;
} Lin_Channel;

typedef struct {
    const lin_uart_parity_e parity;
    const lin_uart_stop_e stop;
    const lin_uart_mode_e mode;
    const lin_uart_cs_mode_e cs_mode;
    const uint32 frequency;
    const uint32 baud_rate;
    const boolean auto_br;
    const boolean icu_abr;
    const uint8 icu_abr_chn;
} lin_uart_cfg_t;

/* uart-gpio mapping config */
typedef struct {
    const uint8 gpio_tx;
    const uint8 gpio_rx;
} Lin_IocGpioConfig;

typedef struct {
    lin_uart_cfg_t dataPtr;
    Lin_IocGpioConfig gpio_sel;
    const Mcu_ModuleType UartModule;
} Lin_Uart;

typedef enum {
    LIN_UNINIT = 0,
    LIN_INIT
} Lin_DrvStatusType;

typedef struct {
    uint8          numberOfNodes;
    const Lin_Uart      *channels;
} Lin_ConfigType;



#ifdef __cplusplus
}
#endif

#endif /* LIN_TYPES_H */
