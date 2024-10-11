
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

#ifndef __MCU_IRAMC_H__
#define __MCU_IRAMC_H__
#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
/* Version and Check Begin */
/* Version Info Begin */
#define MCU_IRAMC_H_VENDOR_ID    0x8C
#define MCU_IRAMC_H_AR_RELEASE_MAJOR_VERSION    4
#define MCU_IRAMC_H_AR_RELEASE_MINOR_VERSION    3
#define MCU_IRAMC_H_AR_RELEASE_REVISION_VERSION 1
#define MCU_IRAMC_H_SW_MAJOR_VERSION    1
#define MCU_IRAMC_H_SW_MINOR_VERSION    0
#define MCU_IRAMC_H_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((MCU_IRAMC_H_AR_RELEASE_MAJOR_VERSION != STD_TYPES_H_AR_RELEASE_MAJOR_VERSION)\
    || (MCU_IRAMC_H_AR_RELEASE_MINOR_VERSION != STD_TYPES_H_AR_RELEASE_MINOR_VERSION)\
    || (MCU_IRAMC_H_AR_RELEASE_REVISION_VERSION != STD_TYPES_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Mcu_Iramc.h and Std_Types.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((MCU_IRAMC_H_SW_MAJOR_VERSION != STD_TYPES_H_SW_MAJOR_VERSION)\
    || (MCU_IRAMC_H_SW_MINOR_VERSION != STD_TYPES_H_SW_MINOR_VERSION)\
    || (MCU_IRAMC_H_SW_PATCH_VERSION != STD_TYPES_H_SW_PATCH_VERSION))
#error "Opps, Mcu_Iramc.h and Std_Types.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */

typedef enum {
    IRAMC_1,
    IRAMC_2,
    IRAMC_3,
    IRAMC_4,
} iramc_index_e;

typedef enum {
    IRAMC_IDLE,
    IRAMC_PRE,
    IRAMC_RETEN1,   /* retention mode 1, memory content retain */
    IRAMC_RETEN2,   /* retention mode 2, memory content retain */
    IRAMC_PWR_DOWN, /* power down mode, memory content corrupted */
} iramc_power_mode_e;

/**
 * @brief   To config iramc power mode.
 * @details This function control iramc power.
 */
 void Mcu_IramcPowerCfg(uint32 base, iramc_power_mode_e mode);

#ifdef __cplusplus
}
#endif

#endif  /* __MCU_IRAMC_H__ */
