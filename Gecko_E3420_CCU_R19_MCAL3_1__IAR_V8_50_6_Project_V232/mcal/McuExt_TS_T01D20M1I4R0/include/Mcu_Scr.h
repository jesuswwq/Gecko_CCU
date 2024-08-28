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

#ifndef SCR_H
#define SCR_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
/* Version and Check Begin */
/* Version Info Begin */
#define MCU_SCR_H_VENDOR_ID    0x8C
#define MCU_SCR_H_AR_RELEASE_MAJOR_VERSION    4
#define MCU_SCR_H_AR_RELEASE_MINOR_VERSION    3
#define MCU_SCR_H_AR_RELEASE_REVISION_VERSION 1
#define MCU_SCR_H_SW_MAJOR_VERSION    1
#define MCU_SCR_H_SW_MINOR_VERSION    0
#define MCU_SCR_H_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((MCU_SCR_H_AR_RELEASE_MAJOR_VERSION != STD_TYPES_H_AR_RELEASE_MAJOR_VERSION)\
    || (MCU_SCR_H_AR_RELEASE_MINOR_VERSION != STD_TYPES_H_AR_RELEASE_MINOR_VERSION)\
    || (MCU_SCR_H_AR_RELEASE_REVISION_VERSION != STD_TYPES_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Mcu_Scr.h and Std_Types.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((MCU_SCR_H_SW_MAJOR_VERSION != STD_TYPES_H_SW_MAJOR_VERSION)\
    || (MCU_SCR_H_SW_MINOR_VERSION != STD_TYPES_H_SW_MINOR_VERSION)\
    || (MCU_SCR_H_SW_PATCH_VERSION != STD_TYPES_H_SW_PATCH_VERSION))
#error "Opps, Mcu_Scr.h and Std_Types.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */

#define TYPE_RW 0
#define TYPE_RO 1
#define TYPE_L16 2
#define TYPE_L31 3
#define TYPE_R16W16 4

#define TYPE_MAX 5

#define SF_DOMAIN 0
#define AP_DOMAIN 1

#define BITFIELD_POS_MSK    0x1Fu

//#define BIT_MASK(x) (((x) >= sizeof(unsigned long) * 8) ? (0UL-1) : ((1UL << (x)) - 1))

typedef struct scr_signal {
    uint8         domain;
    uint16        type;       /* signal type */
    uint16        start_bit;
    uint16        width;
} scr_signal_t;

typedef struct scr_dev {
    uint32 base;
    uint32 reg_off[TYPE_MAX];  /* register offset for different types. */
    int reg_shift;               /* register address shift */
} scr_dev_t;

/**
 * @brief To get one bit of SCR register
 * @param[in] dev     Scr device instance.
 * @param[in] signal  Scr signal structure.
 */
uint32 Mcu_ScrGetBit(const scr_signal_t *signal);

/**
 * @brief To set one bit of SCR register
 * @param[in] dev       Scr device instance.
 * @param[in] signal    Scr signal structure.
 * @param[in] pos       value.
 */
boolean Mcu_ScrSetBit(const scr_signal_t *signal, uint32 value);

/**
 * @brief To lock SCR signal
 * @param[in] dev       Scr device instance.
 * @param[in] signal    Scr signal structure.
 */
boolean Mcu_ScrLock(const scr_signal_t *signal);

/**
 * @brief To get whether SCR signal is locked
 * @param[in] dev       Scr device instance.
 * @param[in] signal    Scr signal structure.
 * @param[in] pos       value.
 */
boolean Mcu_ScrIsLocked(const scr_signal_t *signal);

#ifdef __cplusplus
}
#endif

#endif  /* SCR_H */
