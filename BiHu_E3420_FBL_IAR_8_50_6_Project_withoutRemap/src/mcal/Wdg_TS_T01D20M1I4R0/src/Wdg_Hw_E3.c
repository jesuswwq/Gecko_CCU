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
 * @file  Wdg_Hw_E3.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Wdg
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "__regs_base.h"
#include "Wdg_Reg.h"
#include "RegHelper.h"
#include "Wdg_Hw_E3.h"
#include "SchM_Wdg.h"
#include "arch.h"
/* Version and Check Begin */
/* Version Info Begin */
#define WDG_IP_C_VENDOR_ID    0x8C
#define WDG_IP_C_AR_RELEASE_MAJOR_VERSION    4
#define WDG_IP_C_AR_RELEASE_MINOR_VERSION    3
#define WDG_IP_C_AR_RELEASE_REVISION_VERSION 1
#define WDG_IP_C_SW_MAJOR_VERSION    1
#define WDG_IP_C_SW_MINOR_VERSION    0
#define WDG_IP_C_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((WDG_IP_C_AR_RELEASE_MAJOR_VERSION != WDG_REG_H_AR_RELEASE_MAJOR_VERSION)\
    || (WDG_IP_C_AR_RELEASE_MINOR_VERSION != WDG_REG_H_AR_RELEASE_MINOR_VERSION)\
    || (WDG_IP_C_AR_RELEASE_REVISION_VERSION != WDG_REG_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Wdg_Ip.c and Wdg_Reg.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((WDG_IP_C_SW_MAJOR_VERSION != WDG_REG_H_SW_MAJOR_VERSION)\
    || (WDG_IP_C_SW_MINOR_VERSION != WDG_REG_H_SW_MINOR_VERSION)\
    || (WDG_IP_C_SW_PATCH_VERSION != WDG_REG_H_SW_PATCH_VERSION))
#error "Opps, Wdg_Ip.c and Wdg_Reg.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((WDG_IP_C_AR_RELEASE_MAJOR_VERSION != REGHELPER_H_AR_RELEASE_MAJOR_VERSION)\
    || (WDG_IP_C_AR_RELEASE_MINOR_VERSION != REGHELPER_H_AR_RELEASE_MINOR_VERSION)\
    || (WDG_IP_C_AR_RELEASE_REVISION_VERSION != REGHELPER_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Wdg_Ip.c and RegHelper.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((WDG_IP_C_SW_MAJOR_VERSION != REGHELPER_H_SW_MAJOR_VERSION)\
    || (WDG_IP_C_SW_MINOR_VERSION != REGHELPER_H_SW_MINOR_VERSION)\
    || (WDG_IP_C_SW_PATCH_VERSION != REGHELPER_H_SW_PATCH_VERSION))
#error "Opps, Wdg_Ip.c and RegHelper.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((WDG_IP_C_AR_RELEASE_MAJOR_VERSION != SCHM_WDG_H_AR_RELEASE_MAJOR_VERSION)\
    || (WDG_IP_C_AR_RELEASE_MINOR_VERSION != SCHM_WDG_H_AR_RELEASE_MINOR_VERSION)\
    || (WDG_IP_C_AR_RELEASE_REVISION_VERSION != SCHM_WDG_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Wdg_Ip.c and SchM_Wdg.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((WDG_IP_C_SW_MAJOR_VERSION != SCHM_WDG_H_SW_MAJOR_VERSION)\
    || (WDG_IP_C_SW_MINOR_VERSION != SCHM_WDG_H_SW_MINOR_VERSION)\
    || (WDG_IP_C_SW_PATCH_VERSION != SCHM_WDG_H_SW_PATCH_VERSION))
#error "Opps, Wdg_Ip.c and SchM_Wdg.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */

/* Only register interrupt for timeout */
#define INTERRUPT_MASK    (0x4U)

#define WDG_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Wdg_MemMap.h"

#if (WDG_CHANNEL_NUM == 1)
static VAR(uint32, WDG_VAR) Wdg_Ip_TimeRatio1  __attribute__((aligned(CACHE_LINE)));
#elif (WDG_CHANNEL_NUM == 2)
static VAR(uint32, WDG_VAR) Wdg_Ip_TimeRatio1  __attribute__((aligned(CACHE_LINE)));
static VAR(uint32, WDG_VAR) Wdg_Ip_TimeRatio2  __attribute__((aligned(CACHE_LINE)));
#elif (WDG_CHANNEL_NUM == 3)
static VAR(uint32, WDG_VAR) Wdg_Ip_TimeRatio1  __attribute__((aligned(CACHE_LINE)));
static VAR(uint32, WDG_VAR) Wdg_Ip_TimeRatio2  __attribute__((aligned(CACHE_LINE)));
static VAR(uint32, WDG_VAR) Wdg_Ip_TimeRatio3  __attribute__((aligned(CACHE_LINE)));
#elif (WDG_CHANNEL_NUM == 4)
static VAR(uint32, WDG_VAR) Wdg_Ip_TimeRatio1  __attribute__((aligned(CACHE_LINE)));
static VAR(uint32, WDG_VAR) Wdg_Ip_TimeRatio2  __attribute__((aligned(CACHE_LINE)));
static VAR(uint32, WDG_VAR) Wdg_Ip_TimeRatio3  __attribute__((aligned(CACHE_LINE)));
static VAR(uint32, WDG_VAR) Wdg_Ip_TimeRatio4  __attribute__((aligned(CACHE_LINE)));
#elif (WDG_CHANNEL_NUM == 5)
static VAR(uint32, WDG_VAR) Wdg_Ip_TimeRatio1  __attribute__((aligned(CACHE_LINE)));
static VAR(uint32, WDG_VAR) Wdg_Ip_TimeRatio2  __attribute__((aligned(CACHE_LINE)));
static VAR(uint32, WDG_VAR) Wdg_Ip_TimeRatio3  __attribute__((aligned(CACHE_LINE)));
static VAR(uint32, WDG_VAR) Wdg_Ip_TimeRatio4  __attribute__((aligned(CACHE_LINE)));
static VAR(uint32, WDG_VAR) Wdg_Ip_TimeRatio5  __attribute__((aligned(CACHE_LINE)));
#elif (WDG_CHANNEL_NUM == 6)
static VAR(uint32, WDG_VAR) Wdg_Ip_TimeRatio1  __attribute__((aligned(CACHE_LINE)));
static VAR(uint32, WDG_VAR) Wdg_Ip_TimeRatio2  __attribute__((aligned(CACHE_LINE)));
static VAR(uint32, WDG_VAR) Wdg_Ip_TimeRatio3  __attribute__((aligned(CACHE_LINE)));
static VAR(uint32, WDG_VAR) Wdg_Ip_TimeRatio4  __attribute__((aligned(CACHE_LINE)));
static VAR(uint32, WDG_VAR) Wdg_Ip_TimeRatio5  __attribute__((aligned(CACHE_LINE)));
static VAR(uint32, WDG_VAR) Wdg_Ip_TimeRatio6  __attribute__((aligned(CACHE_LINE)));
#elif (WDG_CHANNEL_NUM == 7)
static VAR(uint32, WDG_VAR) Wdg_Ip_TimeRatio1  __attribute__((aligned(CACHE_LINE)));
static VAR(uint32, WDG_VAR) Wdg_Ip_TimeRatio2  __attribute__((aligned(CACHE_LINE)));
static VAR(uint32, WDG_VAR) Wdg_Ip_TimeRatio3  __attribute__((aligned(CACHE_LINE)));
static VAR(uint32, WDG_VAR) Wdg_Ip_TimeRatio4  __attribute__((aligned(CACHE_LINE)));
static VAR(uint32, WDG_VAR) Wdg_Ip_TimeRatio5  __attribute__((aligned(CACHE_LINE)));
static VAR(uint32, WDG_VAR) Wdg_Ip_TimeRatio6  __attribute__((aligned(CACHE_LINE)));
static VAR(uint32, WDG_VAR) Wdg_Ip_TimeRatio7  __attribute__((aligned(CACHE_LINE)));
#endif

#define WDG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Wdg_MemMap.h"

#define WDG_START_SEC_CONST_UNSPECIFIED
#include "Wdg_MemMap.h"

static CONSTP2VAR(uint32, WDG_CONST, WDG_APPL_DATA) Wdg_Ip_TimeRatio_Ptr[WDG_CHANNEL_NUM] = {
#if (WDG_CHANNEL_NUM == 1)
    &Wdg_Ip_TimeRatio1,
#elif (WDG_CHANNEL_NUM == 2)
    &Wdg_Ip_TimeRatio1,
    &Wdg_Ip_TimeRatio2,
#elif (WDG_CHANNEL_NUM == 3)
    &Wdg_Ip_TimeRatio1,
    &Wdg_Ip_TimeRatio2,
    &Wdg_Ip_TimeRatio3,
#elif (WDG_CHANNEL_NUM == 4)
    &Wdg_Ip_TimeRatio1,
    &Wdg_Ip_TimeRatio2,
    &Wdg_Ip_TimeRatio3,
    &Wdg_Ip_TimeRatio4,
#elif (WDG_CHANNEL_NUM == 5)
    &Wdg_Ip_TimeRatio1,
    &Wdg_Ip_TimeRatio2,
    &Wdg_Ip_TimeRatio3,
    &Wdg_Ip_TimeRatio4,
    &Wdg_Ip_TimeRatio5,
#elif (WDG_CHANNEL_NUM == 6)
    &Wdg_Ip_TimeRatio1,
    &Wdg_Ip_TimeRatio2,
    &Wdg_Ip_TimeRatio3,
    &Wdg_Ip_TimeRatio4,
    &Wdg_Ip_TimeRatio5,
    &Wdg_Ip_TimeRatio6,
#elif (WDG_CHANNEL_NUM == 7)
    &Wdg_Ip_TimeRatio1,
    &Wdg_Ip_TimeRatio2,
    &Wdg_Ip_TimeRatio3,
    &Wdg_Ip_TimeRatio4,
    &Wdg_Ip_TimeRatio5,
    &Wdg_Ip_TimeRatio6,
    &Wdg_Ip_TimeRatio7,
#endif
};

static CONST(uint32, WDG_CONST) Wdg_BaseAddr[WDG_INSTANCE_NUM] = {
    APB_WDT1_BASE,
    APB_WDT2_BASE,
#ifndef SEMIDRIVE_E3_LITE_SERIES
    APB_WDT3_BASE,
    APB_WDT4_BASE,
    APB_WDT5_BASE,
    APB_WDT6_BASE,
#else
    0U,
    0U,
    0U,
    0U,
#endif
    APB_WDT8_BASE,
};

#define WDG_STOP_SEC_CONST_UNSPECIFIED
#include "Wdg_MemMap.h"

#define WDG_START_SEC_CODE
#include "Wdg_MemMap.h"
/**
 * @brief Wdg Ip initial
 * @param[in]  pModeSetting Pointer to mode setting.
 * @param[in]  uInitTimeout Initial Timeout (in ms).
 * @param[in]  Wdg_InstanceID Watchdog driver instance id.
 * @return   none
*/
FUNC(void, WDG_CODE) Wdg_Ip_Init
(
    P2CONST(Wdg_Ip_ModeConfigType, AUTOMATIC, WDG_APPL_CONST) pModeSetting,
    VAR(uint16, AUTOMATIC) uInitTimeout,
    VAR(uint8, AUTOMATIC) Wdg_InstanceID
)
{
    VAR(uint32, AUTOMATIC) RegVal = 0U;
    VAR(uint8, AUTOMATIC) u8channel = 0xFF;
    VAR(uint32, AUTOMATIC) tms = 0U;
    u8channel = Wdg_InstanceChanCfg[Wdg_InstanceID].Wdg_u8Channel;

    REG_RMW32((Wdg_BaseAddr[Wdg_InstanceID] + WDT_CTRL_OFF), BM_WDT_CTRL_WDT_EN, 1U, 0U);
    REG_RMW32(Wdg_BaseAddr[Wdg_InstanceID] + WDT_CTRL_OFF, BM_WDT_CTRL_WDT_EN_SRC, 1U, 1U);

    while (((((uint32)0x1U << BM_WDT_CTRL_WDT_EN_STA) & REG_READ32(Wdg_BaseAddr[Wdg_InstanceID] +
             WDT_CTRL_OFF)) > 0U) &&
           (tms < 10000U)) {
        /*wait until turn off wdg,delay 3 clk for 24M*/
        ++tms;
    }

    tms = 0U;
#if (WDG_REG_WRITE_READBACK_CHECK == STD_ON)
    Std_ReturnType RetVal = E_OK;
#endif

    do {
#if (WDG_REG_WRITE_READBACK_CHECK == STD_ON)
        RetVal = Reg_RMW_ReadBack32(Wdg_BaseAddr[Wdg_InstanceID] + WDT_RST_CTL_OFF,
                                    BM_WDT_RST_CTL_WDT_RST_EN, 1U, 1U, 0xffffffffUL);

        if (E_OK != RetVal) {
            break;
        }

#else
        REG_RMW32(Wdg_BaseAddr[Wdg_InstanceID] + WDT_RST_CTL_OFF, BM_WDT_RST_CTL_WDT_RST_EN, 1U, 1U);
#endif

        if (WDG_INTERRUPT == pModeSetting->eTimeoutBehavior) {
#if (WDG_REG_WRITE_READBACK_CHECK == STD_ON)
            RetVal = Reg_RMW_ReadBack32(Wdg_BaseAddr[Wdg_InstanceID] + WDT_INT_OFF, 0, 3, INTERRUPT_MASK,
                                        0xffffffffUL);

            if (E_OK != RetVal) {
                break;
            }

            RetVal = Reg_RMW_ReadBack32(Wdg_BaseAddr[Wdg_InstanceID] + WDT_RST_CTL_OFF,
                                        BM_WDT_RST_CTL_INT_RST_EN, 1U, 0U, 0xffffffffUL);

            if (E_OK != RetVal) {
                break;
            }

#else
            REG_RMW32(Wdg_BaseAddr[Wdg_InstanceID] + WDT_INT_OFF, 0, 3U, INTERRUPT_MASK);
            REG_RMW32(Wdg_BaseAddr[Wdg_InstanceID] + WDT_RST_CTL_OFF, BM_WDT_RST_CTL_INT_RST_EN, 1U, 0U);
#endif
        } else if (WDG_RESET == pModeSetting->eTimeoutBehavior) {
            /* default Level mode */
#if (WDG_REG_WRITE_READBACK_CHECK == STD_ON)
            RetVal = Reg_RMW_ReadBack32(Wdg_BaseAddr[Wdg_InstanceID] + WDT_INT_OFF, 0, 3, 0, 0xffffffffUL);

            if (E_OK != RetVal) {
                break;
            }

            RetVal = Reg_RMW_ReadBack32(Wdg_BaseAddr[Wdg_InstanceID] + WDT_RST_CTL_OFF,
                                        BM_WDT_RST_CTL_INT_RST_EN, 1U, 1U, 0xffffffffUL);

            if (E_OK != RetVal) {
                break;
            }

#else
            REG_RMW32(Wdg_BaseAddr[Wdg_InstanceID] + WDT_INT_OFF, 0, 3U, 0x0u);
            REG_RMW32(Wdg_BaseAddr[Wdg_InstanceID] + WDT_RST_CTL_OFF, BM_WDT_RST_CTL_INT_RST_EN, 1U, 1U);
#endif
        } else {
            REG_RMW32(Wdg_BaseAddr[Wdg_InstanceID] + WDT_INT_OFF, 0, 3U, INTERRUPT_MASK);
            /*Set delay time between overflow and reset. Maxium 2.7ms for 24MHz reference clk.*/
            REG_RMW32(Wdg_BaseAddr[Wdg_InstanceID] + WDT_RST_CTL_OFF, 0, 16U, 65535U);
            REG_RMW32(Wdg_BaseAddr[Wdg_InstanceID] + WDT_RST_CTL_OFF, BM_WDT_RST_CTL_INT_RST_EN, 1U, 1U);
        }

        /* Level mode */
        if (TRUE == pModeSetting->bExternalSignalEnable) {
#if (WDG_REG_WRITE_READBACK_CHECK == STD_ON)
            RetVal = Reg_RMW_ReadBack32(Wdg_BaseAddr[Wdg_InstanceID] + WDT_EXT_RST_CTL_OFF,
                                        BM_WDT_EXT_RST_CTL_EXT_RST_MODE, 1U, 0U, 0xffffffffUL);

            if (E_OK != RetVal) {
                break;
            }

            RetVal = Reg_RMW_ReadBack32(Wdg_BaseAddr[Wdg_InstanceID] + WDT_EXT_RST_CTL_OFF,
                                        BM_WDT_EXT_RST_CTL_EXT_RST_EN, 1U, 1U, 0xffffffffUL);

            if (E_OK != RetVal) {
                break;
            }

#else
            REG_RMW32(Wdg_BaseAddr[Wdg_InstanceID] + WDT_EXT_RST_CTL_OFF, BM_WDT_EXT_RST_CTL_EXT_RST_MODE, 1U,
                      0U);
            REG_RMW32(Wdg_BaseAddr[Wdg_InstanceID] + WDT_EXT_RST_CTL_OFF, BM_WDT_EXT_RST_CTL_EXT_RST_EN, 1U,
                      1U);
#endif

        }

        if (0u != pModeSetting->uClockFrequency) {
            RegVal = REG_READ32(Wdg_BaseAddr[Wdg_InstanceID] + WDT_CTRL_OFF);
            *(Wdg_Ip_TimeRatio_Ptr[u8channel]) = pModeSetting->uClockFrequency / (24000U * 1000U);
            RegVal |= (uint32)FV_WDT_CTRL_PRE_DIV_NUM(23999U) << 16U;
#if (WDG_DEBUG_SUPPORT == STD_ON)
            RegVal |= 0x1U << BM_WDT_CTRL_DBG_HALT_EN;
#endif
            RegVal |= 0x1U << BM_WDT_CTRL_AUTO_RESTART;
            RegVal |= 0x1U << BM_WDT_CTRL_WTC_SRC;
#if (WDG_REG_WRITE_READBACK_CHECK == STD_ON)
            RetVal = Reg_Write_ReadBack32(RegVal, Wdg_BaseAddr[Wdg_InstanceID] + WDT_CTRL_OFF, 0xffffffffUL);

            if (E_OK != RetVal) {
                break;
            }

#else
            REG_WRITE32(RegVal, Wdg_BaseAddr[Wdg_InstanceID] + WDT_CTRL_OFF);
#endif

            RegVal = (uInitTimeout + 1U) * (*(Wdg_Ip_TimeRatio_Ptr[u8channel]));

#if (WDG_REG_WRITE_READBACK_CHECK == STD_ON)
            RetVal = Reg_Write_ReadBack32(RegVal, Wdg_BaseAddr[Wdg_InstanceID] + WDT_WTC_OFF, 0xffffffffUL);

            if (E_OK != RetVal) {
                break;
            }

#else
            REG_WRITE32(RegVal, Wdg_BaseAddr[Wdg_InstanceID] + WDT_WTC_OFF);
#endif

            switch (pModeSetting->eTriggerCondition) {
            case NO_CONDITION_MODE:
#if (WDG_REG_WRITE_READBACK_CHECK == STD_ON)
                RetVal = Reg_Write_ReadBack32((uint32)((uint32)0x1U << BM_WDT_WRC_CTL_MODE0_EN),
                                              Wdg_BaseAddr[Wdg_InstanceID] + WDT_WRC_CTL_OFF, 0xffffffffUL);
#else
                REG_WRITE32((uint32)((uint32)0x1U << BM_WDT_WRC_CTL_MODE0_EN),
                            Wdg_BaseAddr[Wdg_InstanceID] + WDT_WRC_CTL_OFF);
#endif
                break;

            case WINDOW_BASED_MODE:
#if (WDG_REG_WRITE_READBACK_CHECK == STD_ON)
                RetVal = Reg_Write_ReadBack32((pModeSetting->uRefreshTime + 1U),
                                              Wdg_BaseAddr[Wdg_InstanceID] + WDT_WRC_VAL_OFF, 0xffffffffUL);

                if (E_OK != RetVal) {
                    break;
                }

                RetVal = Reg_Write_ReadBack32((0x1U << BM_WDT_WRC_CTL_MODE1_EN) | (0x1U << BM_WDT_WRC_CTL_MODE0_EN),
                                              Wdg_BaseAddr[Wdg_InstanceID] + WDT_WRC_CTL_OFF, 0xffffffffUL);
#else
                REG_WRITE32((pModeSetting->uRefreshTime + 1U), Wdg_BaseAddr[Wdg_InstanceID] + WDT_WRC_VAL_OFF);
                REG_WRITE32((0x1U << BM_WDT_WRC_CTL_MODE1_EN) | (0x1U << BM_WDT_WRC_CTL_MODE0_EN),
                            Wdg_BaseAddr[Wdg_InstanceID] + WDT_WRC_CTL_OFF);
#endif
                break;

            default:
                break;
            }

            /* Using main_clk: source clock is ss 24M*/
#if (WDG_REG_WRITE_READBACK_CHECK == STD_ON)

            if (E_OK != RetVal) {
                break;
            }

            RetVal = Reg_RMW_ReadBack32(Wdg_BaseAddr[Wdg_InstanceID] + WDT_CTRL_OFF, 2, 3,
                                        FV_WDT_CTRL_CLK_SRC(0x0U), 0xffffffffUL);

            if (E_OK != RetVal) {
                break;
            }

            RetVal = Reg_RMW_ReadBack32(Wdg_BaseAddr[Wdg_InstanceID] + WDT_CTRL_OFF, BM_WDT_CTRL_WDT_EN, 1U, 1U,
                                        0xffffffffUL);

            if (E_OK != RetVal) {
                break;
            }

#else
            REG_RMW32(Wdg_BaseAddr[Wdg_InstanceID] + WDT_CTRL_OFF, 2, 3, FV_WDT_CTRL_CLK_SRC(0x0U));
            REG_RMW32(Wdg_BaseAddr[Wdg_InstanceID] + WDT_CTRL_OFF, BM_WDT_CTRL_WDT_EN, 1U, 1U);
#endif

            while ((!((((uint32)0x1U << BM_WDT_CTRL_WDT_EN_STA) & REG_READ32(Wdg_BaseAddr[Wdg_InstanceID] +
                       WDT_CTRL_OFF)) > 0U)) &&
                   (tms < 10000U)) {
                /*wait until enable success,delay 3 clk for 24M*/
                ++tms;
            }

            tms = 0U;
            REG_RMW32(Wdg_BaseAddr[Wdg_InstanceID] + WDT_CTRL_OFF, BM_WDT_CTRL_SOFT_RST, 1U, 1U);

            while (((((0x1U << BM_WDT_CTRL_SOFT_RST) & REG_READ32(Wdg_BaseAddr[Wdg_InstanceID] +
                      WDT_CTRL_OFF))) > 0U) &&
                   (tms < 10000U)) {
                /*wait until soft reset success,delay 3 clk for 24M*/
                ++tms;
            }

            tms = 0U;
        }
    } while (0);

#if (WDG_REG_WRITE_READBACK_CHECK == STD_ON)

    if ((E_OK != RetVal) && (WdgReadBackCheck_ErrorNotification != NULL_PTR)) {
        WdgReadBackCheck_ErrorNotification();
    }

#endif
}

/**
 * @brief Wdg Ip set mode
 * @param[in]  pModeSetting Pointer to mode setting.
 * @param[in]  Wdg_InstanceID Watchdog driver instance id.
 * @return   none
 * @implements
*/
FUNC(void, WDG_CODE) Wdg_Ip_SetMode
(
    P2CONST(Wdg_Ip_ModeConfigType, AUTOMATIC, WDG_APPL_CONST) pModeSetting,
    VAR(uint8, AUTOMATIC) Wdg_InstanceID
)
{
    VAR(uint32, AUTOMATIC) RegVal = 0U;
    VAR(uint8, AUTOMATIC) u8channel = 0xFF;
    VAR(uint32, AUTOMATIC) tms = 0U;
    u8channel = Wdg_InstanceChanCfg[Wdg_InstanceID].Wdg_u8Channel;

    REG_RMW32(Wdg_BaseAddr[Wdg_InstanceID] + WDT_CTRL_OFF, BM_WDT_CTRL_WDT_EN_SRC, 1U, 1U);

    if (WDG_INTERRUPT == pModeSetting->eTimeoutBehavior) {
        REG_RMW32(Wdg_BaseAddr[Wdg_InstanceID] + WDT_INT_OFF, 0, 3U, INTERRUPT_MASK);
        REG_RMW32(Wdg_BaseAddr[Wdg_InstanceID] + WDT_RST_CTL_OFF, BM_WDT_RST_CTL_INT_RST_EN, 1U, 0U);
    } else if (WDG_RESET == pModeSetting->eTimeoutBehavior) {
        REG_RMW32(Wdg_BaseAddr[Wdg_InstanceID] + WDT_INT_OFF, 0, 3U, 0x0u);
        REG_RMW32(Wdg_BaseAddr[Wdg_InstanceID] + WDT_RST_CTL_OFF, BM_WDT_RST_CTL_INT_RST_EN, 1U, 1U);
    } else {
        REG_RMW32(Wdg_BaseAddr[Wdg_InstanceID] + WDT_INT_OFF, 0, 3U, INTERRUPT_MASK);
        /*Set delay time between overflow and reset. Maxium 2.7ms for 24MHz reference clk.*/
        REG_RMW32(Wdg_BaseAddr[Wdg_InstanceID] + WDT_RST_CTL_OFF, 0, 16U, 65535U);
        REG_RMW32(Wdg_BaseAddr[Wdg_InstanceID] + WDT_RST_CTL_OFF, BM_WDT_RST_CTL_INT_RST_EN, 1U, 1U);
    }

    /* Level mode */
    if ((uint32)TRUE == pModeSetting->bExternalSignalEnable) {
        REG_RMW32(Wdg_BaseAddr[Wdg_InstanceID] + WDT_EXT_RST_CTL_OFF, BM_WDT_EXT_RST_CTL_EXT_RST_MODE, 1U,
                  0U);
        REG_RMW32(Wdg_BaseAddr[Wdg_InstanceID] + WDT_EXT_RST_CTL_OFF, BM_WDT_EXT_RST_CTL_EXT_RST_EN, 1U,
                  1U);
    }

    if (0u != pModeSetting->uClockFrequency) {
        RegVal = REG_READ32(Wdg_BaseAddr[Wdg_InstanceID] + WDT_CTRL_OFF);
        *(Wdg_Ip_TimeRatio_Ptr[u8channel]) = pModeSetting->uClockFrequency / (24000U * 1000U);
        RegVal |= (uint32)FV_WDT_CTRL_PRE_DIV_NUM(23999U) << 16U;
#if (WDG_DEBUG_SUPPORT == STD_ON)
        RegVal |= 0x1U << BM_WDT_CTRL_DBG_HALT_EN;
#endif
        RegVal |= 0x1U << BM_WDT_CTRL_AUTO_RESTART;
        RegVal |= 0x1U << BM_WDT_CTRL_WTC_SRC;
        REG_WRITE32(RegVal, Wdg_BaseAddr[Wdg_InstanceID] + WDT_CTRL_OFF);
        RegVal = (pModeSetting->uTimeoutPeriod + 1U) * (*(Wdg_Ip_TimeRatio_Ptr[u8channel]));
        REG_WRITE32(RegVal, Wdg_BaseAddr[Wdg_InstanceID] + WDT_WTC_OFF);

        switch (pModeSetting->eTriggerCondition) {
        case NO_CONDITION_MODE:
            REG_WRITE32((uint32)((uint32)0x1U << BM_WDT_WRC_CTL_MODE0_EN),
                        Wdg_BaseAddr[Wdg_InstanceID] + WDT_WRC_CTL_OFF);
            break;

        case WINDOW_BASED_MODE:
            REG_WRITE32((uint32)((uint32)0x1U << BM_WDT_WRC_CTL_MODE1_EN) | (0x1U << BM_WDT_WRC_CTL_MODE0_EN),
                        Wdg_BaseAddr[Wdg_InstanceID] + WDT_WRC_CTL_OFF);
            REG_WRITE32((pModeSetting->uRefreshTime + 1U), Wdg_BaseAddr[Wdg_InstanceID] + WDT_WRC_VAL_OFF);
            break;

        default:
            break;
        }

        /* Using main_clk: source clock is ss 24M*/
        REG_RMW32(Wdg_BaseAddr[Wdg_InstanceID] + WDT_CTRL_OFF, 2, 3, FV_WDT_CTRL_CLK_SRC(0x0U));
        REG_RMW32(Wdg_BaseAddr[Wdg_InstanceID] + WDT_CTRL_OFF, BM_WDT_CTRL_WDT_EN, 1U, 1U);

        while ((!((((uint32)0x1U << BM_WDT_CTRL_WDT_EN_STA) & REG_READ32(Wdg_BaseAddr[Wdg_InstanceID] +
                   WDT_CTRL_OFF)) > 0U)) &&
               (tms < 10000U)) {
            /*wait until enable success,delay 3 clk for 24M*/
            ++tms;
        }

        tms = 0U;
        REG_RMW32(Wdg_BaseAddr[Wdg_InstanceID] + WDT_CTRL_OFF, BM_WDT_CTRL_SOFT_RST, 1U, 1U);

        while (((((0x1U << BM_WDT_CTRL_SOFT_RST) & REG_READ32(Wdg_BaseAddr[Wdg_InstanceID] +
                  WDT_CTRL_OFF))) > 0U) &&
               (tms < 10000U)) {
            /*wait until soft reset success,delay 3 clk for 24M*/
            ++tms;
        }

        tms = 0U;
    } else {
        REG_RMW32(Wdg_BaseAddr[Wdg_InstanceID] + WDT_CTRL_OFF, BM_WDT_CTRL_WDT_EN, 1U, 0U);

        while (((((uint32)0x1U << BM_WDT_CTRL_WDT_EN_STA) & REG_READ32(Wdg_BaseAddr[Wdg_InstanceID] +
                 WDT_CTRL_OFF)) > 0U) &&
               (tms < 10000U)) {
            /*wait until turn off wdg,delay 3 clk for 24M*/
            ++tms;
        }

        tms = 0U;
        REG_RMW32(Wdg_BaseAddr[Wdg_InstanceID] + WDT_INT_OFF, 0, 3U, 0x0U);
    }
}

/**
 * @brief Wdg Ip set trigger condition
 * @param[in]  Timeout Timeout timeout value (in ms)
 * @param[in]  Wdg_InstanceID Watchdog driver instance id.
 * @return   none
*/
FUNC(void, WDG_CODE) Wdg_Ip_SetTriggerCondition
(
    VAR(uint16, AUTOMATIC) Timeout,
    VAR(uint8, AUTOMATIC) Wdg_InstanceID
)
{
    VAR(uint8, AUTOMATIC) u8channel = 0xFF;
    u8channel = Wdg_InstanceChanCfg[Wdg_InstanceID].Wdg_u8Channel;
    REG_RMW32(Wdg_BaseAddr[Wdg_InstanceID] + WDT_WRC_CTL_OFF, BM_WDT_WRC_CTL_REFR_TRIG, 1U, 1);

    /*For SWS_Wdg_00140, if users pass '0',wdg will almost reset immediately*/
    if (0U == Timeout) {
        REG_WRITE32(1U, Wdg_BaseAddr[Wdg_InstanceID] + WDT_WTC_OFF);
    } else {
        REG_WRITE32((Timeout + 1U) * (*(Wdg_Ip_TimeRatio_Ptr[u8channel])),
                    Wdg_BaseAddr[Wdg_InstanceID] + WDT_WTC_OFF);
    }

    REG_RMW32(Wdg_BaseAddr[Wdg_InstanceID] + WDT_WRC_CTL_OFF, BM_WDT_WRC_CTL_REFR_TRIG, 1U, 1);
}

/**
 * @brief Wdg Ip clear interrupt flag. Be called by Wdg_CommonInterrupt.
 * @param[in]  Wdg_InstanceID Watchdog driver instance id.
 * @return   none
*/
FUNC(void, WDG_CODE) Wdg_Ip_ClearInterruptFlag
(
    VAR(uint8, AUTOMATIC) Wdg_InstanceID
)
{
    REG_RMW32(Wdg_BaseAddr[Wdg_InstanceID] + WDT_INT_OFF, BM_WDT_INT_OVFLOW_INT_CLR, 1U, 1);
    /*Not generating interrupt when trigger in wrong timing*/
    /*REG_RMW32(Wdg_BaseAddr[Wdg_InstanceID] + WDT_INT_OFF, BM_WDT_INT_ILL_WIN_REFR_INT_CLR, 1U, 1);*/
}

/**
 * @brief Wdg ip set mode
 * @param[in]  pModeSetting Pointer to mode setting.
 * @param[in]  Wdg_InstanceID Watchdog driver instance id.
 * @return   none
 * @implements
*/
FUNC(void, WDG_CODE) Wdg_Ip_TriggerRoutine
(
    VAR(uint8, AUTOMATIC) Wdg_InstanceID
)
{
    REG_RMW32(Wdg_BaseAddr[Wdg_InstanceID] + WDT_WRC_CTL_OFF, BM_WDT_WRC_CTL_REFR_TRIG, 1U, 1);
}

#define WDG_STOP_SEC_CODE
#include "Wdg_MemMap.h"

#ifdef __cplusplus
}
#endif
