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

#ifdef __cplusplus
extern "C" {
#endif

#include "RegHelper.h"
#include "Mcu_Soc.h"
#include "Scr_Reg.h"
#include "Mcu_Scr.h"
/* Version and Check Begin */
/* Version Info Begin */
#define MCU_SCR_C_VENDOR_ID    0x8C
#define MCU_SCR_C_AR_RELEASE_MAJOR_VERSION    4
#define MCU_SCR_C_AR_RELEASE_MINOR_VERSION    3
#define MCU_SCR_C_AR_RELEASE_REVISION_VERSION 1
#define MCU_SCR_C_SW_MAJOR_VERSION    1
#define MCU_SCR_C_SW_MINOR_VERSION    0
#define MCU_SCR_C_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((MCU_SCR_C_AR_RELEASE_MAJOR_VERSION != MCU_SOC_H_AR_RELEASE_MAJOR_VERSION)\
    || (MCU_SCR_C_AR_RELEASE_MINOR_VERSION != MCU_SOC_H_AR_RELEASE_MINOR_VERSION)\
    || (MCU_SCR_C_AR_RELEASE_REVISION_VERSION != MCU_SOC_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Mcu_Scr.c and Mcu_Soc.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((MCU_SCR_C_SW_MAJOR_VERSION != MCU_SOC_H_SW_MAJOR_VERSION)\
    || (MCU_SCR_C_SW_MINOR_VERSION != MCU_SOC_H_SW_MINOR_VERSION)\
    || (MCU_SCR_C_SW_PATCH_VERSION != MCU_SOC_H_SW_PATCH_VERSION))
#error "Opps, Mcu_Scr.c and Mcu_Soc.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((MCU_SCR_C_AR_RELEASE_MAJOR_VERSION != SCR_REG_H_AR_RELEASE_MAJOR_VERSION)\
    || (MCU_SCR_C_AR_RELEASE_MINOR_VERSION != SCR_REG_H_AR_RELEASE_MINOR_VERSION)\
    || (MCU_SCR_C_AR_RELEASE_REVISION_VERSION != SCR_REG_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Mcu_Scr.c and Scr_Reg.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((MCU_SCR_C_SW_MAJOR_VERSION != SCR_REG_H_SW_MAJOR_VERSION)\
    || (MCU_SCR_C_SW_MINOR_VERSION != SCR_REG_H_SW_MINOR_VERSION)\
    || (MCU_SCR_C_SW_PATCH_VERSION != SCR_REG_H_SW_PATCH_VERSION))
#error "Opps, Mcu_Scr.c and Scr_Reg.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((MCU_SCR_C_AR_RELEASE_MAJOR_VERSION != MCU_SCR_H_AR_RELEASE_MAJOR_VERSION)\
    || (MCU_SCR_C_AR_RELEASE_MINOR_VERSION != MCU_SCR_H_AR_RELEASE_MINOR_VERSION)\
    || (MCU_SCR_C_AR_RELEASE_REVISION_VERSION != MCU_SCR_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Mcu_Scr.c and Mcu_Scr.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((MCU_SCR_C_SW_MAJOR_VERSION != MCU_SCR_H_SW_MAJOR_VERSION)\
    || (MCU_SCR_C_SW_MINOR_VERSION != MCU_SCR_H_SW_MINOR_VERSION)\
    || (MCU_SCR_C_SW_PATCH_VERSION != MCU_SCR_H_SW_PATCH_VERSION))
#error "Opps, Mcu_Scr.c and Mcu_Scr.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */

#define MCU_START_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

/* scr device */
const scr_dev_t g_scr_sf = {
    .base = APB_SCR_SF_BASE,
    .reg_shift = 0,
    .reg_off = {
        [TYPE_RW] = 0x1000,
        [TYPE_RO] = 0x1100,
        [TYPE_L16] = 0x1200,
        [TYPE_L31] = 0x1400,
        [TYPE_R16W16] = 0x1600,
    },
};
#ifndef SEMIDRIVE_E3_LITE_SERIES
const scr_dev_t g_scr_ap = {
    .base = APB_SCR_AP_BASE,
    .reg_shift = 0,
    .reg_off = {
        [TYPE_RW] = 0x1000,
        [TYPE_RO] = 0x1100,
        [TYPE_L16] = 0x1200,
        [TYPE_L31] = 0x1400,
        [TYPE_R16W16] = 0x1600,
    },
};
#endif
#define MCU_STOP_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

LOCAL_INLINE const scr_dev_t *scr_get_device(const scr_signal_t *signal)
{
#ifndef SEMIDRIVE_E3_LITE_SERIES
    return (SF_DOMAIN == signal->domain) ?  &g_scr_sf : &g_scr_ap;
#else
    return &g_scr_sf;
#endif
}

LOCAL_INLINE uint32 scr_reg(const scr_signal_t *signal)
{
    const scr_dev_t *dev = scr_get_device(signal);
    uint32 reg_off = dev->reg_off[signal->type] + (signal->start_bit >> 5) * 4;
    return dev->base + (reg_off << dev->reg_shift);
}

LOCAL_INLINE uint32 scr_read_reg(const scr_signal_t *signal)
{
    return REG_READ32(scr_reg(signal));
}

LOCAL_INLINE void scr_write_reg(const scr_signal_t *signal, uint32 val)
{
    REG_WRITE32(val, scr_reg(signal));
}

LOCAL_INLINE uint32 scr_get_bit(const scr_signal_t *signal)
{
    uint32 val = scr_read_reg(signal);
    uint32 start_bit = signal->start_bit & BITFIELD_POS_MSK;
    return (val >> start_bit) & BIT_MASK(signal->width);
}

LOCAL_INLINE boolean scr_is_locked(const scr_signal_t *signal)
{
    uint32 val = scr_read_reg(signal);

    boolean locked;
    uint32 start_bit = signal->start_bit & BITFIELD_POS_MSK;

    switch (signal->type) {
    case TYPE_L16:
        if (start_bit < 16)
            locked = (val & (1ul << (start_bit + 16))) >> (start_bit + 16);
        else
            locked = (val & (1ul << start_bit)) >> start_bit;

        break;

    case TYPE_L31:
        locked = (val & (1ul << 31)) >> 31;
        break;

    /* Read only bits are considered locked.*/
    case TYPE_R16W16:
        locked = start_bit >= 16;
        break;

    case TYPE_RO:
        locked = TRUE;
        break;

    case TYPE_RW:
    default:
        locked = FALSE;
        break;
    }

    return locked;
}

LOCAL_INLINE boolean scr_set_bit(const scr_signal_t *signal, uint32 value)
{
    uint32 val = scr_read_reg(signal);
    boolean ret = FALSE;

    if (!scr_is_locked(signal)) {
        uint32 start_bit = signal->start_bit & BITFIELD_POS_MSK;
        val &= ~(BIT_MASK(signal->width) << start_bit);
        val |= value << start_bit;
        scr_write_reg(signal, val);
        ret = TRUE;
    }

    return ret;
}

LOCAL_INLINE boolean scr_lock(const scr_signal_t *signal)
{
    if (scr_is_locked(signal))
        return TRUE;

    uint32 val = scr_read_reg(signal);
    boolean ret = FALSE;
    uint32 start_bit = signal->start_bit & BITFIELD_POS_MSK;

    switch (signal->type) {
    case TYPE_L16:
        if (start_bit < 16)
            val |= BIT_MASK(signal->width) << (start_bit + 16);
        else /* sticky bit */
            val |= BIT_MASK(signal->width) << start_bit;

        scr_write_reg(signal, val);
        ret = TRUE;
        break;

    case TYPE_L31:
        val |= 1ul << 31;
        scr_write_reg(signal, val);
        ret = TRUE;
        break;

    case TYPE_R16W16:
    case TYPE_RW:
    case TYPE_RO:
    default:
        break;
    }

    return ret;
}

uint32 Mcu_ScrGetBit(const scr_signal_t *signal)
{
    return  scr_get_bit(signal);
}

boolean Mcu_ScrSetBit(const scr_signal_t *signal, uint32 value)
{
    return scr_set_bit(signal, value);
}

boolean Mcu_ScrLock(const scr_signal_t *signal)
{
    return scr_lock(signal);
}

boolean Mcu_ScrIsLocked(const scr_signal_t *signal)
{
    return scr_is_locked(signal);
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif
