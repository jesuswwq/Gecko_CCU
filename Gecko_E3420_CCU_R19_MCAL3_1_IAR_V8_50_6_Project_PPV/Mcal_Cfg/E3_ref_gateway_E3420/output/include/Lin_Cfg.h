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
 * @file  Lin_Cfg.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Lin
 * @date 2024-03-08 16:29:00
 */

#ifndef LIN_CFG_H
#define LIN_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

#include "Lin_Types_E3.h"

#define LIN_DEV_ERROR_DETECT  (STD_OFF)

/* lin auto baudrate detect  */
#define LIN_ICU_ABR_DETECT  (STD_OFF)

/*
Configuration: LIN_TX_ERROR_DETECT
- if STD_ON, Function tx err detect is available
- if STD_OFF,Function tx err detect is not available
- Note: only sf domain gpio can support tx err detect
*/
#define LIN_TX_ERROR_DETECT  (STD_ON)

/*
Configuration: LIN_VERSION_INFO_API
- if STD_ON, Function Lin_GetVersionInfo is available
- if STD_OFF,Function Lin_GetVersionInfo is not available
*/
#define LIN_VERSION_INFO_API  (STD_OFF)
#define LIN_SLAVE_MODE_USED (STD_OFF)

/*
Configuration: LIN_INDEX
*/
#define LIN_INDEX  (0U)

/*
Configuration : LIN_MAXIMUM_CHANNEL
It is the maximum lin channels configured.
*/
#define LIN_NUM_CHANNELS   (3U)

extern CONST(Lin_ConfigType, LIN_CONST) LinGlobalConfig;

#ifdef __cplusplus
}
#endif

#endif  /* LIN_CFG_H */
