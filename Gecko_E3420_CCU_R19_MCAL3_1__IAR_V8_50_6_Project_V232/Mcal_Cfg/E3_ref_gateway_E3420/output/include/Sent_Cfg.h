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
 * @file  Sent_Cfg.h
 * @brief Semidrive. MCAL Sent
 * @date 2024-03-08 16:29:00
 */

#ifndef SENT_CFG_H
#define SENT_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Sent_Types_E3.h"

/* Version and Check Begin */
/* Version Info Begin */
#define SENT_CFG_H_VENDOR_ID    0x8C
#define SENT_CFG_H_AR_RELEASE_MAJOR_VERSION    4
#define SENT_CFG_H_AR_RELEASE_MINOR_VERSION    3
#define SENT_CFG_H_AR_RELEASE_REVISION_VERSION 1
#define SENT_CFG_H_SW_MAJOR_VERSION    1
#define SENT_CFG_H_SW_MINOR_VERSION    0
#define SENT_CFG_H_SW_PATCH_VERSION    0
/* Version Info End */
/* Version and Check End */
#define SENT_DEV_ERROR_DETECT (STD_ON)
#define SENT_DEINIT_API (STD_ON)
#define SENT_SLOW_CHANNEL_TRANSMIT (STD_OFF)
#define SENT_FAST_CHANNEL_UNSTANDARD_TRANSMIT (STD_OFF)
#define SENT_LOW_PULSE_DETECT (STD_OFF)


#define SENT_NUM_CHANNELS   (2U)

#define SentConf_SentChannel_SentChannel_0 (0u)
#define SentConf_SentChannel_SentChannel_1 (1u)

extern CONST(Sent_ConfigType, SENT_CONST) Sent_Config;


#ifdef __cplusplus
}
#endif

#endif /*SENT_CFG_H*/
