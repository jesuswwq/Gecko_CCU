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
 * @file  q21xx.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL EthTrcv plugins.
 */

#ifndef Q21XX_H
#define Q21XX_H

#ifdef __cplusplus
extern "C" {
#endif

#include "EthTrcv.h"

// 1000 BASE-T1 Operating Mode
#define MRVL_88Q211X_MODE_LEGACY    0x06B0
#define MRVL_88Q211X_MODE_DEFAULT   0x0000
#define MRVL_88Q211X_MODE_ADVERTISE 0x0002

// Current Speed
#define MRVL_88Q2112_1000BASE_T1    0x0001
#define MRVL_88Q2112_100BASE_T1     0x0000

#if ETHTRCV_Q21XX_SUPPORTED == STD_ON
extern const EthTrcv_Ops_Type  marvell_q21xx_ops;
#endif

#ifdef __cplusplus
}
#endif

#endif

