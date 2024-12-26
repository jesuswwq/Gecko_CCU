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
 * @file  Dio_UserCallouts.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Dio
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Dio_UserCallouts.h"
#if defined(DEBUG_ENABLE)
#include "debug.h"
#endif

#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"

FUNC(void, DIO_CODE) Dio_UserCallouts
(
    VAR(uint8, AUTOMATIC) ChannelId
)
{
#if defined(DEBUG_ENABLE)
    DBG("Gpio interrupt occur, channelID %d \n", ChannelId);
#endif
}

#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"

#ifdef __cplusplus
}
#endif


