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
 * @file  Lin_Hw.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Lin
 */

#if !defined (LIN_HW_H)
#define LIN_HW_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Lin_Types_E3.h"
#include "Lin_Cfg.h"
/* Formula to calculate message time for one frame in micro seconds*/

#define LIN_CALCPARITY1(id)         (((uint8) ((id & 0x01)) ^      \
                                             ((id & 0x02)>>1) ^   \
                                             ((id & 0x04)>>2) ^   \
                                             ((id & 0x10)>>4)) << 6)

#define LIN_CALCPARITY2(id)         (((uint8) ((id & 0x02)>>1) ^  \
                                             ((id & 0x08)>>3) ^   \
                                             ((id & 0x04)>>4) ^   \
                                             ((id & 0x10)>>5)) << 7)

#define LIN_SYNCBYTE        0x55
#define LIN_SYNCBREAK       0x00

#define LIN_STATUS_OVERRUN         0x2
#define LIN_STATUS_SUCCESS         0x1

#define LIN_DATA_POS               0X03
#define LIN_SYNC_POS               0x00
#define LIN_SYNC_LEN               0x01

#define LIN_HEADER_POS             0x01
#define LIN_HEADER_LENGTH          0x02


#define LIN_INTR0_RXCHKSUMERR   (0x01U << 26U)

#define LIN_INTR0_RXCHKSUMPASS  (0x01U << 25U)

#define LIN_INTR0_RXPIDERR  (0x01U << 24U)

#define LIN_INTR0_RXPIDPASS (0x01U << 23U)

#define LIN_INTR0_APBCMDABORT   (0x01U << 22U)

#define LIN_INTR0_APBCMDDONE    (0x01U << 21U)

#define LIN_INTEN0_STARTERRE    (0x01U << 20U)

#define LIN_INTR0_ABRFAILE  (0x01U << 19U)

#define LIN_INTR0_ABRPASSE  (0x01U << 18U)

#define LIN_INTR0_TC    (0x01U << 17U)

#define LIN_INTR0_RXBREAK   (0x01U << 13U)

#define LIN_INTR0_NOISEERR   (0x01U << 11U)

#define LIN_INTR0_BAUDRATEERRE  (0x01U << 10U)

#define LIN_INTR0_FRAMEERR   (0x01U << 9U)

#define LIN_INTR0_PARITYERR  (0x01U << 8U)

#define LIN_INTR0_RXFOVF (0x01U << 5U)

#define LIN_INTR0_TXFOVF (0x01U << 4U)

#define LIN_INTR0_RXFUDF (0x01U << 3U)

#define LIN_INTR0_TXFUDF (0x01U << 2U)

#define LIN_INTR0_RXFWF (0x01U << 1U)

#define LIN_INTR0_TXFWE (0x01U << 0U)


/* lin sleep id */
#define LIN_SLEEP_PID               0x3C
/* lin wake up id */
#define LIN_WAKE_UP_PID               0x3E

/* Function should be called from operating system once */

Std_ReturnType Lin_NodeInit(uint8 numNodeId);



void Lin_HwSetNodePdu(Lin_NodeData *locNodePdu, const Lin_PduType *locPdu);

uint8 Lin_HwSendFrame(uint8 ChannelID);

void Lin_HwGoToSleep(uint8 Channel);

Std_ReturnType Lin_HwWakeup(uint8 numNodeId);

uint32 Lin_HwGetNode(Mcu_ModuleType UartId);

void Lin_HwRstMod(uint8 ChannelID);

void Lin_TransmitCallBk(uint8 numNodeId);

void Lin_UartInit(const Lin_Uart *Lin_UartCfg);

void Lin_UartTransmit(const Lin_Uart *Lin_UartCfg, uint8 cs, uint8 *point2data, uint8 numberBytes);

void Lin_Uart_Set_Break(const Lin_Uart *Lin_UartCfg);

void Lin_UartRxBreakCtrl(const Lin_Uart *Lin_UartCfg, uint8 bitNum);

void Lin_UartGetChar(const Lin_Uart *Lin_UartCfg, uint8 *data, uint8 numberBytes);

uint32 Lin_UartGetInt(const Lin_Uart *Lin_UartCfg);

void Lin_UartClearInt(const Lin_Uart *Lin_UartCfg, uint32 state);

void Lin_UartSetCs(const Lin_Uart *Lin_UartCfg, uint8 PduCs);

void Lin_UartReceive(const Lin_Uart *Lin_UartCfg, uint8 cs, uint8 numberBytes);

void Lin_UartPidSet(const Lin_Uart *Lin_UartCfg, uint8 Pid);

uint8 Lin_UartPidGet(const Lin_Uart *Lin_UartCfg);

void Lin_UartClrTxFifo(const Lin_Uart *Lin_UartCfg);

void Lin_UartClrRxFifo(const Lin_Uart *Lin_UartCfg);

void Lin_UartSetAbr(const Lin_Uart *Lin_UartCfg);

void Lin_UartSetAbrEn(const Lin_Uart *Lin_UartCfg, boolean enable);

void Lin_Uart_Set_Baudrate(const Lin_Uart *Lin_UartCfg, uint32 calcbaud);

void Lin_UartRstMod(const Lin_Uart *Lin_UartCfg);

#if (LIN_TX_ERROR_DETECT== STD_ON)
void Lin_IocInit(uint8 numNodeId, const Lin_Uart *Lin_UartCfg);

void Lin_IocEnable(uint8 numNodeId, boolean enable);

boolean Lin_IocTxErrCheck(uint8 numNodeId);
#endif /* LIN_TX_ERROR_DETECT */

#if (LIN_ICU_ABR_DETECT == STD_ON)
void Lin_NodeIcuAbrInit(uint8 numNodeID);
#endif /* LIN_ICU_ABR_DETECT */

#ifdef __cplusplus
}
#endif

#endif /* LIN_H */
