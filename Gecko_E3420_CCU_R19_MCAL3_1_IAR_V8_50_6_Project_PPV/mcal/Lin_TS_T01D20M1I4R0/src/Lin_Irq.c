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
 * @file  Lin_Irq.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Lin
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Lin_Irq.h"
#include "Lin_Hw.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_ISR(id) \
ISR(Lin_Irq##id##_Handle)\
{\
    uint32 numNodeID = Lin_HwGetNode((Mcu_ModuleType)UART##id);\
    if (numNodeID < LIN_NUM_CHANNELS) {\
        Lin_TransmitCallBk(numNodeID);\
    }\
}

LIN_ISR(1)
LIN_ISR(2)
LIN_ISR(3)
LIN_ISR(4)
LIN_ISR(5)
LIN_ISR(6)
LIN_ISR(7)
LIN_ISR(8)
LIN_ISR(9)
LIN_ISR(10)
LIN_ISR(11)
LIN_ISR(12)
#ifndef SEMIDRIVE_E3_LITE_SERIES
LIN_ISR(13)
LIN_ISR(14)
LIN_ISR(15)
LIN_ISR(16)
#endif

#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#ifdef __cplusplus
}
#endif
