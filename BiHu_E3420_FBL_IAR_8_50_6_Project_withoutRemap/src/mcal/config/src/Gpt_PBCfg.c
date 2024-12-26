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
 * @file  Gpt_Cfg.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Wdg
 * @date 2023-09-22 17:02:49
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Gpt_Cfg.h"
/* Version and Check Begin */
/* Version Info Begin */
#define GPT_PBCFG_C_VENDOR_ID    0x8C
#define GPT_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4
#define GPT_PBCFG_C_AR_RELEASE_MINOR_VERSION    3
#define GPT_PBCFG_C_AR_RELEASE_REVISION_VERSION 1
#define GPT_PBCFG_C_SW_MAJOR_VERSION    1
#define GPT_PBCFG_C_SW_MINOR_VERSION    0
#define GPT_PBCFG_C_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((GPT_PBCFG_C_AR_RELEASE_MAJOR_VERSION != GPT_CFG_H_AR_RELEASE_MAJOR_VERSION)\
    || (GPT_PBCFG_C_AR_RELEASE_MINOR_VERSION != GPT_CFG_H_AR_RELEASE_MINOR_VERSION)\
    || (GPT_PBCFG_C_AR_RELEASE_REVISION_VERSION != GPT_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "Opps, Gpt_PBCfg.c and Gpt_Cfg.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((GPT_PBCFG_C_SW_MAJOR_VERSION != GPT_CFG_H_SW_MAJOR_VERSION)\
    || (GPT_PBCFG_C_SW_MINOR_VERSION != GPT_CFG_H_SW_MINOR_VERSION)\
    || (GPT_PBCFG_C_SW_PATCH_VERSION != GPT_CFG_H_SW_PATCH_VERSION))
    #error "Opps, Gpt_PBCfg.c and Gpt_Cfg.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */

extern void GptNotification_1ms(void);

#define GPT_START_SEC_CONST_UNSPECIFIED
#include "Gpt_MemMap.h"
#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
static CONST(Gpt_PredefChannelConfigType, GPT_CONST) Gpt_InitPredeftimer = {
    GPT_INDEX_BTM1,
    0,
};

#endif /*GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON*/
static CONST(Gpt_ChannelConfigType, GPT_CONST) Gpt_InitChannelPB[1] =
{
    {
        &GptNotification_1ms, /* Channel notification */
        (Gpt_ValueType)(4294967295U), /* Maximum ticks value*/
        (Gpt_ChannelModeType)(GPT_CH_MODE_CONTINUOUS), /* Timer mode:continous/one-shot */
        {
            (Gpt_HwModule)(GPT_INDEX_BTM1), /* hardware module ID */
            (Gpt_HwChannel)(GPT_HW_TIMER_G1), /* GPT physical channel no. */
            (uint16)(23), /* Prescaler value */
            (TRUE),
            (Gpt_ClockRefType)(GPT_CLOCKREF_XTAL)
        },
        (uint8)0X00 /* coreid 0:sf 1:sx0 2:sx1 3:sp0 4:sp1*/
    },
};



CONST(Gpt_ConfigType, GPT_CONST)  GptChannelConfigSet =
{
    (Gpt_ChannelType)1U,
    &Gpt_InitChannelPB,
#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
    &Gpt_InitPredeftimer,
#endif /*GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON*/
};

#define GPT_STOP_SEC_CONST_UNSPECIFIED
#include "Gpt_MemMap.h"

#ifdef __cplusplus
}
#endif
