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
//#include "Mcu_Soc.h"
#include "Scr_Reg.h"
#include "Mcu_Scr.h"
#include "__regs_base.h"
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

LOCAL_INLINE const scr_dev_t *Mcu_Ip_ScrGetDevice(const scr_signal_t *signal)
{
#ifndef SEMIDRIVE_E3_LITE_SERIES
    return (SF_DOMAIN == signal->domain) ?  &g_scr_sf : &g_scr_ap;
#else
    return &g_scr_sf;
#endif
}

LOCAL_INLINE uint32 Mcu_Ip_ScrReg(const scr_signal_t *signal)
{
    const scr_dev_t *dev = Mcu_Ip_ScrGetDevice(signal);
    uint32 reg_off = dev->reg_off[signal->type] + (signal->start_bit >> 5) * 4;
    return dev->base + (reg_off << dev->reg_shift);
}

LOCAL_INLINE uint32 Mcu_Ip_ScrReadReg(const scr_signal_t *signal)
{
    return REG_READ32(Mcu_Ip_ScrReg(signal));
}

LOCAL_INLINE void Mcu_Ip_ScrWriteReg(const scr_signal_t *signal, uint32 val)
{
    REG_WRITE32(val, Mcu_Ip_ScrReg(signal));
}

LOCAL_INLINE uint32 Mcu_Ip_ScrGetBit(const scr_signal_t *signal)
{
    uint32 val = Mcu_Ip_ScrReadReg(signal);
    uint32 start_bit = signal->start_bit & BITFIELD_POS_MSK;
    return (val >> start_bit) & BIT_MASK(signal->width);
}

LOCAL_INLINE boolean Mcu_Ip_ScrIsLocked(const scr_signal_t *signal)
{
    uint32 val = Mcu_Ip_ScrReadReg(signal);

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

LOCAL_INLINE boolean Mcu_Ip_ScrSetBit(const scr_signal_t *signal, uint32 value)
{
    uint32 val = Mcu_Ip_ScrReadReg(signal);
    boolean ret = FALSE;

    if (!Mcu_Ip_ScrIsLocked(signal)) {
        uint32 start_bit = signal->start_bit & BITFIELD_POS_MSK;
        val &= ~(BIT_MASK(signal->width) << start_bit);
        val |= value << start_bit;
        Mcu_Ip_ScrWriteReg(signal, val);
        ret = TRUE;
    }

    return ret;
}

LOCAL_INLINE boolean Mcu_Ip_ScrLock(const scr_signal_t *signal)
{
    uint32 val = Mcu_Ip_ScrReadReg(signal);
    boolean ret = FALSE;
    uint32 start_bit = signal->start_bit & BITFIELD_POS_MSK;

    if (Mcu_Ip_ScrIsLocked(signal))
    {
        ret = TRUE;
    }
    else
    {
        switch (signal->type) {
        case TYPE_L16:
            if (start_bit < 16)
                val |= BIT_MASK(signal->width) << (start_bit + 16);
            else /* sticky bit */
                val |= BIT_MASK(signal->width) << start_bit;

            Mcu_Ip_ScrWriteReg(signal, val);
            ret = TRUE;
            break;

        case TYPE_L31:
            val |= 1ul << 31;
            Mcu_Ip_ScrWriteReg(signal, val);
            ret = TRUE;
            break;

        case TYPE_R16W16:
        case TYPE_RW:
        case TYPE_RO:
        default:
            break;
        }
    }

    return ret;
}

uint32 Mcu_ScrGetBit(const scr_signal_t *signal)
{
    uint32 value = UINT32_MAX;
    if(NULL_PTR == signal)
    {
#if (STD_ON == MCU_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_INIT_SCR, MCU_E_PARAM_POINTER);
#endif /*(STD_ON == PORT_DEV_ERROR_DETECT) */
    }
    else
    {
        value = Mcu_Ip_ScrGetBit(signal);
    }
    return value;
}

boolean Mcu_ScrSetBit(const scr_signal_t *signal, uint32 value)
{
    boolean ret = FALSE;
    if(NULL_PTR == signal)
    {
#if (STD_ON == MCU_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_INIT_SCR, MCU_E_PARAM_POINTER);
#endif /*(STD_ON == PORT_DEV_ERROR_DETECT) */
    }
    {
        ret = Mcu_Ip_ScrSetBit(signal, value);
    }
    return ret;
}

boolean Mcu_ScrLock(const scr_signal_t *signal)
{
    boolean ret = FALSE;
    if(NULL_PTR == signal)
    {
#if (STD_ON == MCU_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_INIT_SCR, MCU_E_PARAM_POINTER);
#endif /*(STD_ON == PORT_DEV_ERROR_DETECT) */
    }
    else
    {
        ret = Mcu_Ip_ScrLock(signal);
    }
    return ret;
}

boolean Mcu_ScrIsLocked(const scr_signal_t *signal)
{
    boolean ret = FALSE;
    if(NULL_PTR == signal)
    {
#if (STD_ON == MCU_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_INIT_SCR, MCU_E_PARAM_POINTER);
#endif /*(STD_ON == PORT_DEV_ERROR_DETECT) */
    }
    else
    {
        ret = Mcu_Ip_ScrIsLocked(signal);
    }
    return ret;
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif
