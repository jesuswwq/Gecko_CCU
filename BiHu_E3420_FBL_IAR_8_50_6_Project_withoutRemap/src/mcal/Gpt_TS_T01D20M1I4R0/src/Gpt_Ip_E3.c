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
 * @file  Gpt_Ip_E3.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Gpt
 */

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
                                        INCLUDE FILES
==================================================================================================*/
#include "Gpt_Ip_E3.h"
#include "Gpt_Register.h"
#include "RegHelper.h"
#include "__regs_base.h"
#include "e3_clk.h"
#include "e3_ckgen_drv.h"
#include "e3_clock_cfg_nd.h"
#include "Mcu.h"
#include "arch.h"
/* Version and Check Begin */
/* Version Info Begin */
#define GPT_IP_C_VENDOR_ID    0x8C
#define GPT_IP_C_AR_RELEASE_MAJOR_VERSION    4
#define GPT_IP_C_AR_RELEASE_MINOR_VERSION    3
#define GPT_IP_C_AR_RELEASE_REVISION_VERSION 1
#define GPT_IP_C_SW_MAJOR_VERSION    1
#define GPT_IP_C_SW_MINOR_VERSION    0
#define GPT_IP_C_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((GPT_IP_C_AR_RELEASE_MAJOR_VERSION != GPT_IP_H_AR_RELEASE_MAJOR_VERSION)\
    || (GPT_IP_C_AR_RELEASE_MINOR_VERSION != GPT_IP_H_AR_RELEASE_MINOR_VERSION)\
    || (GPT_IP_C_AR_RELEASE_REVISION_VERSION != GPT_IP_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Gpt_Ip_E3.c and Gpt_Ip_E3.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((GPT_IP_C_SW_MAJOR_VERSION != GPT_IP_H_SW_MAJOR_VERSION)\
    || (GPT_IP_C_SW_MINOR_VERSION != GPT_IP_H_SW_MINOR_VERSION)\
    || (GPT_IP_C_SW_PATCH_VERSION != GPT_IP_H_SW_PATCH_VERSION))
#error "Opps, Gpt_Ip_E3.c and Gpt_Ip_E3.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((GPT_IP_C_AR_RELEASE_MAJOR_VERSION != GPT_REGISTER_H_AR_RELEASE_MAJOR_VERSION)\
    || (GPT_IP_C_AR_RELEASE_MINOR_VERSION != GPT_REGISTER_H_AR_RELEASE_MINOR_VERSION)\
    || (GPT_IP_C_AR_RELEASE_REVISION_VERSION != GPT_REGISTER_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Gpt_Ip_E3.c and Gpt_Register.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((GPT_IP_C_SW_MAJOR_VERSION != GPT_REGISTER_H_SW_MAJOR_VERSION)\
    || (GPT_IP_C_SW_MINOR_VERSION != GPT_REGISTER_H_SW_MINOR_VERSION)\
    || (GPT_IP_C_SW_PATCH_VERSION != GPT_REGISTER_H_SW_PATCH_VERSION))
#error "Opps, Gpt_Ip_E3.c and Gpt_Register.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((GPT_IP_C_AR_RELEASE_MAJOR_VERSION != REGHELPER_H_AR_RELEASE_MAJOR_VERSION)\
    || (GPT_IP_C_AR_RELEASE_MINOR_VERSION != REGHELPER_H_AR_RELEASE_MINOR_VERSION)\
    || (GPT_IP_C_AR_RELEASE_REVISION_VERSION != REGHELPER_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Gpt_Ip_E3.c and RegHelper.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((GPT_IP_C_SW_MAJOR_VERSION != REGHELPER_H_SW_MAJOR_VERSION)\
    || (GPT_IP_C_SW_MINOR_VERSION != REGHELPER_H_SW_MINOR_VERSION)\
    || (GPT_IP_C_SW_PATCH_VERSION != REGHELPER_H_SW_PATCH_VERSION))
#error "Opps, Gpt_Ip_E3.c and RegHelper.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */
#define GPT_CNT_G0_FREQUENCY (75000000U)
#define GPT_CNT_G1_FREQUENCY (24000000U)
#define GPT_TIME_US (1000000U)

#define GPT_CNT_G1_UPD_FLAG_INC_MASK (0x01U << 3U)
#define GPT_CNT_G1_UPD_FLAG_SI_MASK (0x01U << 2U)
#define GPT_CNT_G1_UPD_FLAG_CMP_MASK (0x01U << 1U)
#define GPT_CNT_G1_UPD_FLAG_OVF_MASK (0x01U << 0U)

#define GPT_CNT_SI_VAL_MASK_START (24U)
#define GPT_CNT_SI_VAL_MASK_WIDTH (8U)
#define GPT_CNT_INC_VAL (0x01U << 16U)

#define GPT_IP_OVF_RLD_MASK_START(ch) ((uint32)ch)
#define GPT_IP_OVFINT_EN_MASK_START(ch) ((2U + (uint32)ch))
#define GPT_IP_CMPINT_EN_MASK_START(ch) (((uint32)ch))
#define GPT_IP_EN_WIDTH  (1U)

#define GPT_IP_MAX_MODULE  (6U)
#define GPT_IP_REG_OFFSET_20H (0x20U)
#define GPT_IP_CMP1_VAL_REG_OFFSET (0x10U)

#define GPT_START_SEC_CONST_UNSPECIFIED
#include "Gpt_MemMap.h"

CONST(uint32, GPT_CONST) BTM_BASE_ADDR32[GPT_IP_MAX_MODULE] = {
    APB_BTM1_BASE,
    APB_BTM2_BASE,
    APB_BTM3_BASE,
    APB_BTM4_BASE,
#ifndef SEMIDRIVE_E3_LITE_SERIES
    APB_BTM5_BASE,
    APB_BTM6_BASE
#endif
};

#define GPT_STOP_SEC_CONST_UNSPECIFIED
#include "Gpt_MemMap.h"


#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"

FUNC(void, GPT_CODE) Gpt_Ip_Init
(
    P2CONST(Gpt_HwChannelConfigType, AUTOMATIC, GPT_APPL_CONST) pHwChannelConfig
)
{
    VAR(uint32, AUTOMATIC) TmrCntInitConfig = 0U;
    VAR(uint32, AUTOMATIC) TmrCntSiVal = 0U;
    VAR(uint32, AUTOMATIC) tms = 0U;
    /*Clear the int sta signal.*/
    REG_WRITE32(0x00UL, GPT_INT_STA_EN_ADDR32(pHwChannelConfig->u8TimerModule));
    REG_WRITE32(0x00UL, GPT_INT_SIG_EN_ADDR32(pHwChannelConfig->u8TimerModule));

    do {
        if (pHwChannelConfig->eClockRef == GPT_CLOCKREF_APB) {
            TmrCntSiVal = (((pHwChannelConfig->u8Prescaler) << GPT_CNT_SI_VAL_MASK_START) & 0xFF000000);
            TmrCntInitConfig = TmrCntSiVal | GPT_CNT_INC_VAL;
            REG_WRITE32(TmrCntInitConfig, GPT_CNT_G0_CFG_ADDR32(pHwChannelConfig->u8TimerModule));
        } else if (pHwChannelConfig->eClockRef == GPT_CLOCKREF_XTAL) {
            TmrCntSiVal = (((pHwChannelConfig->u8Prescaler) << GPT_CNT_SI_VAL_MASK_START) & 0xFF000000);
            TmrCntInitConfig = TmrCntSiVal | GPT_CNT_INC_VAL;
            REG_WRITE32(TmrCntInitConfig, GPT_CNT_G1_CFG_ADDR32(pHwChannelConfig->u8TimerModule));
            REG_WRITE32(GPT_CNT_G1_UPD_FLAG_SI_MASK, GPT_CNT_G1_UPD_ADDR32(pHwChannelConfig->u8TimerModule));

            /* Delay a while unitl si values be synced,need 4@pclk+4@24m_clk*/
            while ((REG_READ32(GPT_CNT_G1_UPD_ADDR32(pHwChannelConfig->u8TimerModule)) &
                    GPT_CNT_G1_UPD_FLAG_SI_MASK) &&
                   (tms < 10000U)) {
                ++tms;
            };
        } else {
            /* avoid warning */
        }
    } while (0);

}

FUNC(void, GPT_CODE) Gpt_Ip_DeInit
(
    P2CONST(Gpt_HwChannelConfigType, AUTOMATIC, GPT_APPL_CONST) pHwChannelConfig
)
{
    REG_RMW32(GPT_CNT_G0_EN_ADDR32(pHwChannelConfig->u8TimerModule) + \
              (GPT_IP_REG_OFFSET_20H * (uint32)(pHwChannelConfig->u8HwChannel)), 0, 1U, 0U);
    REG_RMW32(GPT_CNT_G0_CFG_ADDR32((uint32)(pHwChannelConfig->u8TimerModule)), \
              GPT_CNT_SI_VAL_MASK_START, GPT_CNT_SI_VAL_MASK_WIDTH, 1U);
    REG_RMW32(GPT_CNT_G1_CFG_ADDR32((uint32)(pHwChannelConfig->u8TimerModule)), \
              GPT_CNT_SI_VAL_MASK_START, GPT_CNT_SI_VAL_MASK_WIDTH, 1U);
    REG_WRITE32(GPT_CNT_G1_UPD_FLAG_SI_MASK, GPT_CNT_G1_UPD_ADDR32(pHwChannelConfig->u8TimerModule));
    REG_WRITE32(0x0U, GPT_CNT_G0_OVF_ADDR32(pHwChannelConfig->u8TimerModule) + \
                (GPT_IP_REG_OFFSET_20H * (uint32)(pHwChannelConfig->u8HwChannel)));

    if (TRUE == pHwChannelConfig->bNotificationEnabled) {
        REG_RMW32(GPT_INT_SIG_EN_ADDR32(pHwChannelConfig->u8TimerModule), \
                  GPT_IP_OVFINT_EN_MASK_START(pHwChannelConfig->u8HwChannel), 1U, 0U);
        REG_RMW32(GPT_INT_STA_EN_ADDR32(pHwChannelConfig->u8TimerModule), \
                  GPT_IP_OVFINT_EN_MASK_START(pHwChannelConfig->u8HwChannel), 1U, 0U);
    }

    REG_RMW32(GPT_CNT_G0_CFG_ADDR32(pHwChannelConfig->u8TimerModule) + \
              (GPT_IP_REG_OFFSET_20H * (uint32)(pHwChannelConfig->u8HwChannel)), 0, 1U, 0U);

    if (pHwChannelConfig->u8HwChannel == GPT_HW_TIMER_G1) {
        REG_WRITE32(GPT_CNT_G1_UPD_FLAG_OVF_MASK, GPT_CNT_G1_UPD_ADDR32(pHwChannelConfig->u8TimerModule));
    }
}

#if (GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
FUNC(void, GPT_CODE) Gpt_Ip_PredefDeInit
(
    P2CONST(Gpt_PredefChannelConfigType, AUTOMATIC, GPT_APPL_CONST) pPredefCfg
)
{
    REG_RMW32(GPT_CNT_G0_EN_ADDR32(pPredefCfg->u8TimerModule), \
              0, 1U, 0U);
    REG_RMW32(GPT_CNT_G0_CFG_ADDR32(pPredefCfg->u8TimerModule), \
              GPT_CNT_SI_VAL_MASK_START, 8U, 0x1U);
    REG_RMW32(GPT_CNT_G0_CFG_ADDR32(pPredefCfg->u8TimerModule), 0, 1U, 0U);
    REG_WRITE32(0x0U, GPT_CNT_G0_OVF_ADDR32(pPredefCfg->u8TimerModule));
}

FUNC(void, GPT_CODE) Gpt_Ip_StartPreDefTimer
(
    P2CONST(Gpt_PredefChannelConfigType, AUTOMATIC, GPT_APPL_CONST) pPredefCfg
)
{
    VAR(uint8, AUTOMATIC) u32Prescaler = 0U;
    VAR(uint32, AUTOMATIC) u32ApbClk = 0U;
    u32ApbClk = clk_get_rate(CLK_NODE(g_ckgen_bus_cr5_sf_div_p));

    /** @warning May generate fallthrough warning.*/
    /* AUTOSAR Provision:  If a GPT Predef Timer is enabled,
    Set the corresponding timing mode according to the selected GPT predef timer */
    switch (pPredefCfg->u8PredefTimer1us_Num) {
    case 3:
        REG_WRITE32(0xffffffffU, GPT_CNT_G0_OVF_ADDR32(pPredefCfg->u8TimerModule));
        break;

    case 2:
        REG_WRITE32(0xffffffU, GPT_CNT_G0_OVF_ADDR32(pPredefCfg->u8TimerModule));
        break;

    case 1:
        REG_WRITE32(0xffffU, GPT_CNT_G0_OVF_ADDR32(pPredefCfg->u8TimerModule));
        break;

    default:
        break;
    }

    /* Generate 1us/tick */
    u32Prescaler = (u32ApbClk / GPT_TIME_US) - 1u;
    REG_RMW32(GPT_CNT_G0_CFG_ADDR32(pPredefCfg->u8TimerModule), \
              GPT_CNT_SI_VAL_MASK_START, 8U, u32Prescaler & 0xFF);
    /* set g0 continous */
    REG_RMW32(GPT_CNT_G0_CFG_ADDR32(pPredefCfg->u8TimerModule), 0, 1U, 1U);
    REG_RMW32(GPT_CNT_G0_EN_ADDR32(pPredefCfg->u8TimerModule), 0, 1U, 1U);
}

FUNC(void, GPT_CODE) Gpt_Ip_GetPredefTimerValue
(
    P2CONST(Gpt_PredefChannelConfigType, AUTOMATIC, GPT_APPL_CONST) pPredefCfg,
    VAR(Gpt_PredefTimerType, AUTOMATIC) PredefTimer,
    P2VAR(uint32, AUTOMATIC, GPT_APPL_DATA) pTimeValue
)
{
    switch (PredefTimer) {
    case GPT_PREDEF_TIMER_1US_16BIT:
        *pTimeValue = REG_READ32(GPT_CNT_G0_VAL_ADDR32((uint32)(pPredefCfg->u8TimerModule))) & 0xffffU;
        break;

    case GPT_PREDEF_TIMER_1US_24BIT:
        *pTimeValue = REG_READ32(GPT_CNT_G0_VAL_ADDR32((uint32)(pPredefCfg->u8TimerModule))) & 0xffffffU;
        break;

    case GPT_PREDEF_TIMER_1US_32BIT:
        *pTimeValue = REG_READ32(GPT_CNT_G0_VAL_ADDR32((uint32)(pPredefCfg->u8TimerModule))) & 0xffffffffU;
        break;

    default:
        *pTimeValue = 0U;
        break;
    }
}
#endif /* GPT_PREDEFTIMER_FUNCTIONALITY_API */

FUNC(void, GPT_CODE) Gpt_Ip_StartTimer
(
    P2CONST(Gpt_HwChannelConfigType, AUTOMATIC, GPT_APPL_CONST) pHwChannelConfig,
    VAR(Gpt_ChannelModeType, AUTOMATIC) Mode,
    VAR(Gpt_ValueType, AUTOMATIC) Value,
    VAR(boolean, AUTOMATIC) bNotificationEnabled
)
{
    VAR(uint32, AUTOMATIC) tms = 0U;

    if (GPT_CH_MODE_CONTINUOUS == Mode) {
        REG_RMW32(GPT_CNT_G0_CFG_ADDR32(pHwChannelConfig->u8TimerModule) + \
                  (GPT_IP_REG_OFFSET_20H * (uint32)(pHwChannelConfig->u8HwChannel)), 0, 1U, 1U);
    } else if (GPT_CH_MODE_ONESHOT == Mode) {
        REG_RMW32(GPT_CNT_G0_CFG_ADDR32(pHwChannelConfig->u8TimerModule) + \
                  (GPT_IP_REG_OFFSET_20H * (uint32)(pHwChannelConfig->u8HwChannel)), 0, 1U, 0U);
    } else {
        /* avoid warning*/
    }

    REG_WRITE32((uint32)Value, GPT_CNT_G0_OVF_ADDR32(pHwChannelConfig->u8TimerModule) + \
                (GPT_IP_REG_OFFSET_20H * (uint32)(pHwChannelConfig->u8HwChannel)));

    if (pHwChannelConfig->u8HwChannel == GPT_HW_TIMER_G1) {
        REG_WRITE32(GPT_CNT_G1_UPD_FLAG_OVF_MASK, GPT_CNT_G1_UPD_ADDR32(pHwChannelConfig->u8TimerModule));

        /* Delay a while unitl si values be synced,need 4@pclk+4@24m_clk*/
        while ((REG_READ32(GPT_CNT_G1_UPD_ADDR32(pHwChannelConfig->u8TimerModule)) &
                GPT_CNT_G1_UPD_FLAG_OVF_MASK) &&
               (tms < 10000U)) {
            ++tms;
        };
    }

    if (TRUE == bNotificationEnabled) {
        REG_RMW32(GPT_INT_SIG_EN_ADDR32(pHwChannelConfig->u8TimerModule), \
                  GPT_IP_OVFINT_EN_MASK_START(pHwChannelConfig->u8HwChannel), 1U, 1U);
        REG_RMW32(GPT_INT_STA_EN_ADDR32(pHwChannelConfig->u8TimerModule), \
                  GPT_IP_OVFINT_EN_MASK_START(pHwChannelConfig->u8HwChannel), 1U, 1U);
    }

    REG_RMW32(GPT_CNT_G0_EN_ADDR32(pHwChannelConfig->u8TimerModule) + \
              (GPT_IP_REG_OFFSET_20H * (uint32)(pHwChannelConfig->u8HwChannel)), 0, 1U, 1U);
}

FUNC(void, GPT_CODE) Gpt_Ip_StopTimer
(
    P2CONST(Gpt_HwChannelConfigType, AUTOMATIC, GPT_APPL_CONST) pHwChannelConfig
)
{
    REG_RMW32(GPT_CNT_G0_EN_ADDR32(pHwChannelConfig->u8TimerModule) + \
              (GPT_IP_REG_OFFSET_20H * (uint32)(pHwChannelConfig->u8HwChannel)), 0, 1U, 0U);
    REG_RMW32(GPT_CNT_G0_CFG_ADDR32(pHwChannelConfig->u8TimerModule) + \
              (GPT_IP_REG_OFFSET_20H * (uint32)(pHwChannelConfig->u8HwChannel)), 0, 1U, 0U);
    REG_WRITE32(0x0U, GPT_CNT_G0_OVF_ADDR32(pHwChannelConfig->u8TimerModule) + \
                (GPT_IP_REG_OFFSET_20H * (uint32)(pHwChannelConfig->u8HwChannel)));

    if (pHwChannelConfig->u8HwChannel == GPT_HW_TIMER_G1) {
        REG_WRITE32(GPT_CNT_G1_UPD_FLAG_OVF_MASK, GPT_CNT_G1_UPD_ADDR32(pHwChannelConfig->u8TimerModule));
    }

    if (TRUE == pHwChannelConfig->bNotificationEnabled) {
        REG_RMW32(GPT_INT_SIG_EN_ADDR32(pHwChannelConfig->u8TimerModule), \
                  GPT_IP_OVFINT_EN_MASK_START(pHwChannelConfig->u8HwChannel), 1U, 0U);
        REG_RMW32(GPT_INT_STA_EN_ADDR32(pHwChannelConfig->u8TimerModule), \
                  GPT_IP_OVFINT_EN_MASK_START(pHwChannelConfig->u8HwChannel), 1U, 0U);
    }
}

FUNC(Gpt_ValueType, GPT_CODE) Gpt_Ip_GetTimeElapsed
(
    P2CONST(Gpt_HwChannelConfigType, AUTOMATIC, GPT_APPL_CONST) pHwChannelConfig,
    P2VAR(boolean, AUTOMATIC, GPT_APPL_DATA) pIsExpried
)
{
    VAR(uint32, AUTOMATIC) OverflowValue = 0U;
    VAR(uint32, AUTOMATIC) CounterValue = 0U;
    VAR(uint32, AUTOMATIC) CounterEnable = 0U;

    do {
        if (pIsExpried == NULL_PTR) {
            break;
        }

        CounterEnable = REG_READ32(GPT_CNT_G0_EN_ADDR32(pHwChannelConfig->u8TimerModule) + \
                                   (GPT_IP_REG_OFFSET_20H * (uint32)(pHwChannelConfig->u8HwChannel))) & 0x1U;
        OverflowValue = REG_READ32(GPT_CNT_G0_OVF_ADDR32(pHwChannelConfig->u8TimerModule) + \
                                   (GPT_IP_REG_OFFSET_20H * (uint32)(pHwChannelConfig->u8HwChannel)));
        CounterValue = REG_READ32(GPT_CNT_G0_VAL_ADDR32(pHwChannelConfig->u8TimerModule) + \
                                  (GPT_IP_REG_OFFSET_20H * (uint32)(pHwChannelConfig->u8HwChannel)));

        if (!CounterEnable) {
            *pIsExpried = TRUE;
            CounterValue = OverflowValue;
        } else {
            *pIsExpried = FALSE;
        }

    } while (0);

    return (Gpt_ValueType)CounterValue;
}

FUNC(void, AUTOMATIC) Gpt_Ip_EnableInterrupt
(
    P2CONST(Gpt_HwChannelConfigType, AUTOMATIC, GPT_APPL_CONST) pHwChannelConfig
)
{
    REG_RMW32(GPT_INT_SIG_EN_ADDR32(pHwChannelConfig->u8TimerModule), \
              GPT_IP_OVFINT_EN_MASK_START(pHwChannelConfig->u8HwChannel), 1U, 1U);
    REG_RMW32(GPT_INT_STA_EN_ADDR32(pHwChannelConfig->u8TimerModule), \
              GPT_IP_OVFINT_EN_MASK_START(pHwChannelConfig->u8HwChannel), 1U, 1U);
}

FUNC(void, AUTOMATIC) Gpt_Ip_DisableInterrupt
(
    P2CONST(Gpt_HwChannelConfigType, AUTOMATIC, GPT_APPL_CONST) pHwChannelConfig
)
{
    REG_RMW32(GPT_INT_SIG_EN_ADDR32(pHwChannelConfig->u8TimerModule), \
              GPT_IP_OVFINT_EN_MASK_START(pHwChannelConfig->u8HwChannel), 1U, 0U);
    REG_RMW32(GPT_INT_STA_EN_ADDR32(pHwChannelConfig->u8TimerModule), \
              GPT_IP_OVFINT_EN_MASK_START(pHwChannelConfig->u8HwChannel), 1U, 0U);
}

FUNC(uint32, AUTOMATIC) Gpt_Ip_GetInterrupt
(
    VAR(uint8, AUTOMATIC) eModule
)
{
    uint32 Value = 0U;
    Value = REG_READ32(GPT_INT_STA_ADDR32(eModule));
    return Value;
}

FUNC(void, AUTOMATIC) Gpt_Ip_ClearInterrupt
(
    VAR(uint8, AUTOMATIC) eModule,
    VAR(uint8, AUTOMATIC) Position
)
{
    REG_WRITE32( (uint32)(Position), GPT_INT_STA_ADDR32(eModule));
}

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#ifdef __cplusplus
}
#endif
