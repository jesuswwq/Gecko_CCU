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
 * @file  Sent_Ip_E3.c
 * @brief Semidrive. MCAL Sent
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Sent_Ip_E3.h"
#include "RegHelper.h"
#include "Sent_Register_E3.h"
#include "Mcu_Modules.h"
#include "__regs_base.h"
#include "crc4.h"
#include "debug.h"
/* Version and Check Begin */
/* Version Info Begin */
#define SENT_IP_C_VENDOR_ID    0x8C
#define SENT_IP_C_AR_RELEASE_MAJOR_VERSION    4
#define SENT_IP_C_AR_RELEASE_MINOR_VERSION    3
#define SENT_IP_C_AR_RELEASE_REVISION_VERSION 1
#define SENT_IP_C_SW_MAJOR_VERSION    1
#define SENT_IP_C_SW_MINOR_VERSION    0
#define SENT_IP_C_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((SENT_IP_C_AR_RELEASE_MAJOR_VERSION != SENT_IP_H_AR_RELEASE_MAJOR_VERSION)\
    || (SENT_IP_C_AR_RELEASE_MINOR_VERSION != SENT_IP_H_AR_RELEASE_MINOR_VERSION)\
    || (SENT_IP_C_AR_RELEASE_REVISION_VERSION != SENT_IP_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Sent_Ip.c and Sent_Ip_E3.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((SENT_IP_C_SW_MAJOR_VERSION != SENT_IP_H_SW_MAJOR_VERSION)\
    || (SENT_IP_C_SW_MINOR_VERSION != SENT_IP_H_SW_MINOR_VERSION)\
    || (SENT_IP_C_SW_PATCH_VERSION != SENT_IP_H_SW_PATCH_VERSION))
#error "Opps, Sent_Ip.c and Sent_Ip_E3.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((SENT_IP_C_AR_RELEASE_MAJOR_VERSION != REGHELPER_H_AR_RELEASE_MAJOR_VERSION)\
    || (SENT_IP_C_AR_RELEASE_MINOR_VERSION != REGHELPER_H_AR_RELEASE_MINOR_VERSION)\
    || (SENT_IP_C_AR_RELEASE_REVISION_VERSION != REGHELPER_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Sent_Ip.c and RegHelper.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((SENT_IP_C_SW_MAJOR_VERSION != REGHELPER_H_SW_MAJOR_VERSION)\
    || (SENT_IP_C_SW_MINOR_VERSION != REGHELPER_H_SW_MINOR_VERSION)\
    || (SENT_IP_C_SW_PATCH_VERSION != REGHELPER_H_SW_PATCH_VERSION))
#error "Opps, Sent_Ip.c and RegHelper.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((SENT_IP_C_AR_RELEASE_MAJOR_VERSION != SENT_REGISTER_H_AR_RELEASE_MAJOR_VERSION)\
    || (SENT_IP_C_AR_RELEASE_MINOR_VERSION != SENT_REGISTER_H_AR_RELEASE_MINOR_VERSION)\
    || (SENT_IP_C_AR_RELEASE_REVISION_VERSION != SENT_REGISTER_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Sent_Ip.c and Sent_Register.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((SENT_IP_C_SW_MAJOR_VERSION != SENT_REGISTER_H_SW_MAJOR_VERSION)\
    || (SENT_IP_C_SW_MINOR_VERSION != SENT_REGISTER_H_SW_MINOR_VERSION)\
    || (SENT_IP_C_SW_PATCH_VERSION != SENT_REGISTER_H_SW_PATCH_VERSION))
#error "Opps, Sent_Ip.c and Sent_Register.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((SENT_IP_C_AR_RELEASE_MAJOR_VERSION != MCU_MODULES_H_AR_RELEASE_MAJOR_VERSION)\
    || (SENT_IP_C_AR_RELEASE_MINOR_VERSION != MCU_MODULES_H_AR_RELEASE_MINOR_VERSION)\
    || (SENT_IP_C_AR_RELEASE_REVISION_VERSION != MCU_MODULES_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Sent_Ip.c and Mcu_Modules.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((SENT_IP_C_SW_MAJOR_VERSION != MCU_MODULES_H_SW_MAJOR_VERSION)\
    || (SENT_IP_C_SW_MINOR_VERSION != MCU_MODULES_H_SW_MINOR_VERSION)\
    || (SENT_IP_C_SW_PATCH_VERSION != MCU_MODULES_H_SW_PATCH_VERSION))
#error "Opps, Sent_Ip.c and Mcu_Modules.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */
#define SENT_ETMR_CLOCK_FREQ 24000000

/*                 NOTE                   */
/* All of the channel is physical channel */
#define SENT_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sent_MemMap.h"

static VAR(Sent_CounterScaler, AUTOMATIC) Sent_Scaler[SENT_NUM_CHANNELS];
static VAR(boolean, SENT_VAR) SentNotificationEnable[SENT_NUM_CHANNELS];
static VAR(boolean, AUTOMATIC) Sent_Ip_aSetClkInfo[TIMER_MODULE_NUMBER];
VAR(uint32, SENT_VAR) SENT_ETMR_BASE[TIMER_MODULE_NUMBER];

VAR(Sent_Channel, AUTOMATIC) Sent_FrameInfo[SENT_NUM_CHANNELS];                 /*! @brief temporary Sent Frame data buffer */
static VAR(Sent_Channel, AUTOMATIC) gSent_Channel[SENT_NUM_CHANNELS];           /*! @brief HwChannel Sent Frame data buffer */

#define SENT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"

FUNC(void, SENT_CODE) Sent_Ip_SetBaseAddr
(
    void
)
{
    SENT_ETMR_BASE[0] = APB_ETMR1_BASE;
    SENT_ETMR_BASE[1] = APB_ETMR2_BASE;
#ifndef SEMIDRIVE_E3_LITE_SERIES
    SENT_ETMR_BASE[2] = APB_ETMR3_BASE;
    SENT_ETMR_BASE[3] = APB_ETMR4_BASE;
#endif

}

FUNC(void, SENT_CODE) Sent_Ip_ChannelInit
(
    VAR(uint8, AUTOMATIC) ChannelId,
    P2CONST(Sent_ChannelConfigType, AUTOMATIC, SENT_APPL_CONST) pChannelConfig
)
{
    VAR(uint32, AUTOMATIC) u32Timeout = 1000U;
    VAR(uint8, AUTOMATIC) TimerModule = 0U;
    VAR(uint8, AUTOMATIC) HwChannel = 0U;
    VAR(Sent_FastChannelType, AUTOMATIC) ChnFormat = SENT_STANDARD_FORMAT;
    VAR(uint8, AUTOMATIC) FifoWml = 0U;
    VAR(uint32, AUTOMATIC) u32Value = 0U;

    TimerModule = (uint8)pChannelConfig->SentHwChannelConfig->u8TimerModule;
    HwChannel = (uint8)pChannelConfig->SentHwChannelConfig->u8HwChannel;
    ChnFormat = pChannelConfig->SentHwChannelConfig->eFastChannel;
    FifoWml = (uint8)pChannelConfig->SentHwChannelConfig->u8FifoWml;

    /* set timer clock and predivider */
    if (Sent_Ip_aSetClkInfo[TimerModule] == FALSE) {
        VAR(uint32, AUTOMATIC) Clk_Mon = 0u;
        Clk_Mon = SENT_BM_CLK_MON_EN_CMP_SET | SENT_BM_CLK_MON_EN_EN_N;
        /* disable clk mon first */
        REG_WRITE32(Clk_Mon, SENT_CLK_MON_EN(TimerModule));

        /* set clk info */
        VAR(uint32, AUTOMATIC) Clk_Set = 0u;
        Clk_Set = SENT_FV_TIM_CLK_CONFIG_DIV_NUM(0);
        /* set src clock as 24M */
        Clk_Set |= SENT_FV_TIM_CLK_CONFIG_SRC_CLK_SEL(3);
        Clk_Set |= SENT_BM_TIM_CLK_CONFIG_CLK_CHANGE_UPD;
        REG_WRITE32(Clk_Set, SENT_TIM_CLK_CONFIG(TimerModule));

        do {
            /* wait for clk info effective, timeout is about 5 clock */
            u32Value = (REG_READ32(SENT_TIM_CLK_CONFIG(TimerModule)) & SENT_BM_TIM_CLK_CONFIG_CLK_CHANGE_UPD);
        } while ((0x1U == u32Value) && (u32Timeout--));

        /* enable clk mon */
        Clk_Mon = SENT_BM_CLK_MON_EN_CMP_SET | SENT_BM_CLK_MON_EN_EN_P;
        REG_WRITE32(Clk_Mon, SENT_CLK_MON_EN(TimerModule));

        Sent_Ip_aSetClkInfo[TimerModule] = TRUE;
    }

    /* calculate the expect scaler value */
    Sent_Scaler[ChannelId].u32ExpectScaler = SENT_ETMR_CLOCK_FREQ / (pChannelConfig->u32TickFrequency);
    /* set timer counter ovf value 0xffffffff */
    REG_WRITE32(0xFFFFFFFF, SENT_LOCAL_CNT_OVF_VAL(TimerModule, HwChannel));
    REG_RMW32(SENT_LOCAL_CNT_CFG(TimerModule, HwChannel), SENT_CNT_CFG_OVF_UPD_START_BIT, 1u, 1u);

    u32Timeout = 1000U;
    do {
        /* wait for timer counter overflow value updated, timeout is about 5 clock */
        u32Value = (REG_READ32(SENT_LOCAL_CNT_CFG(TimerModule,
                    HwChannel)) & (1 << SENT_CNT_CFG_OVF_UPD_START_BIT));
    } while ((0x1U == u32Value) && (u32Timeout--));

    /* cnt will start when the first cpt event happen */
    REG_RMW32(SENT_LOCAL_CNT_CFG(TimerModule, HwChannel), SENT_CNT_CFG_START_BY_FIRST_CPT_START_BIT, 1u,
              1u);
    /* reset the counter when the cpt0 event happen */
    REG_RMW32(SENT_LOCAL_CNT_CFG(TimerModule, HwChannel), SENT_CNT_CFG_CPT0_CLR_EN_START_BIT, 1u, 1u);
    /* enable timer counter */
    REG_WRITE32(1, SENT_LOCAL_CNT_EN(TimerModule, HwChannel));

    /* Set the triggered edge as falling edge */
    REG_RMW32(SENT_CPT_CONFIG(TimerModule, HwChannel), SENT_CPT_CONFIG_CPT0_TRIG_MODE_START_BIT, 2u, 1);
    /* set the local timer as capture counter */
    REG_RMW32(SENT_CPT_CONFIG(TimerModule, HwChannel), SENT_CPT_CONFIG_CNT_SEL_START_BIT, 2u, 2u);
    REG_RMW32(SENT_CPT_CTRL(TimerModule), SENT_CPT_CTRL_CPT_CONFIG_SET_START_BIT(HwChannel), 1u, 1u);

    /* set water mark level value */
    VAR(uint32, AUTOMATIC) Chn_Wml = REG_READ32(SENT_CHN_DMA_WML(TimerModule));
    Chn_Wml &= ~SENT_FM_DMA_WML_CHN(HwChannel);
    Chn_Wml |= SENT_FV_DMA_WML_CHN(FifoWml, HwChannel);
    REG_WRITE32(Chn_Wml, SENT_CHN_DMA_WML(TimerModule));

    VAR(uint32, AUTOMATIC) Dma_Ctrl = REG_READ32(SENT_CHN_DMA_CTRL(TimerModule));
    /* set dma block as capture */
    Dma_Ctrl |= SENT_FV_CHN_DMA_CTRL_CHN_SEL(1, HwChannel);
    Dma_Ctrl |= SENT_BM_CHN_DMA_CTRL_CHN_EN(HwChannel);
    REG_WRITE32(Dma_Ctrl, SENT_CHN_DMA_CTRL(TimerModule));

    /* set channel data info */
    if (ChnFormat == SENT_STANDARD_FORMAT) {
        gSent_Channel[ChannelId].FrameInfo.u8Dl = pChannelConfig->SentHwChannelConfig->eDataBitNum;
    } else if (ChnFormat == SENT_SINGLE_SECURE_FORMAT) {
        gSent_Channel[ChannelId].FrameInfo.u8Dl = SENT_DATA_WIDTH_24_BIT;
    } else if (ChnFormat == SENT_HIGH_SPEED_FORMAT) {
        gSent_Channel[ChannelId].FrameInfo.u8Dl = SENT_DATA_WIDTH_12_BIT;
    }

    /* set channel format */
    gSent_Channel[ChannelId].eChnFormat = ChnFormat;
    /* set channel notification */
    SentNotificationEnable[ChannelId] = FALSE;
    /* The hardware glitch filter is too weak, software filter may need to be added. */
    /* Filter Func*/
    if (TRUE == pChannelConfig->SentHwChannelConfig->bFiterEnable) {
        u32Value = SENT_CPT_FLT_EN | SENT_CPT_FLT_NEGEDGE_SEL | \
                    SENT_CPT_FLT_NEG_BAND_WID(pChannelConfig->SentHwChannelConfig->u8FiterBandwidth) | \
                    SENT_CPT_FLT_SMPL_INTVAL(pChannelConfig->SentHwChannelConfig->u8SampleInterval);
    }

    REG_WRITE32(u32Value, SENT_CPT_X0_FLT(TimerModule, HwChannel));
}

FUNC(void, SENT_CODE) Sent_Ip_ChannelDeInit
(
    VAR(uint8, AUTOMATIC) ChannelId,
    P2CONST(Sent_ChannelConfigType, AUTOMATIC, SENT_APPL_CONST) pChannelConfig
)
{
    VAR(uint8, AUTOMATIC) TimerModule = 0U;
    VAR(uint8, AUTOMATIC) HwChannel = 0U;
    VAR(uint32, AUTOMATIC) u32Value = 0U;
    VAR(uint32, AUTOMATIC) u32Timeout = 1000U;

    TimerModule = (uint8)pChannelConfig->SentHwChannelConfig->u8TimerModule;
    HwChannel = (uint8)pChannelConfig->SentHwChannelConfig->u8HwChannel;

    /* restore timer counter overflow value 0 */
    REG_WRITE32(0, SENT_LOCAL_CNT_OVF_VAL(TimerModule, HwChannel));
    REG_RMW32(SENT_LOCAL_CNT_CFG(TimerModule, HwChannel), SENT_CNT_CFG_OVF_UPD_START_BIT, 1u, 1u);

    do {
        /* wait for timer counter overflow value updated, timeout is about 5 clock */
        u32Value = (REG_READ32(SENT_LOCAL_CNT_CFG(TimerModule,
                     HwChannel)) & (1 << SENT_CNT_CFG_OVF_UPD_START_BIT));
    } while ((0x1U == u32Value) && (u32Timeout--));

    /* restore the cnt cfg */
    REG_RMW32(SENT_LOCAL_CNT_CFG(TimerModule, HwChannel), SENT_CNT_CFG_START_BY_FIRST_CPT_START_BIT, 1u,
              0u);
    REG_RMW32(SENT_LOCAL_CNT_CFG(TimerModule, HwChannel), SENT_CNT_CFG_CPT0_CLR_EN_START_BIT, 1u, 0u);
    /* disable timer counter */
    REG_WRITE32(0, SENT_LOCAL_CNT_EN(TimerModule, HwChannel));

    /* Set the triggered edge as default edge */
    REG_RMW32(SENT_CPT_CONFIG(TimerModule, HwChannel), SENT_CPT_CONFIG_CPT0_TRIG_MODE_START_BIT, 2u, 0);
    /* set the local timer as default counter */
    REG_RMW32(SENT_CPT_CONFIG(TimerModule, HwChannel), SENT_CPT_CONFIG_CNT_SEL_START_BIT, 2u, 0u);
    REG_RMW32(SENT_CPT_CTRL(TimerModule), SENT_CPT_CTRL_CPT_CONFIG_SET_START_BIT(HwChannel), 1u, 1u);

    /* restore water mark level value */
    VAR(uint32, AUTOMATIC) Chn_Wml = REG_READ32(SENT_CHN_DMA_WML(TimerModule));
    Chn_Wml &= ~SENT_FM_DMA_WML_CHN(HwChannel);
    Chn_Wml |= SENT_FV_DMA_WML_CHN(0, HwChannel);
    REG_WRITE32(Chn_Wml, SENT_CHN_DMA_WML(TimerModule));

    /* set dma block as default block  */
    VAR(uint32, AUTOMATIC) Dma_Ctrl = REG_READ32(SENT_CHN_DMA_CTRL(TimerModule));
    Dma_Ctrl |= SENT_FV_CHN_DMA_CTRL_CHN_SEL(0, HwChannel);
    REG_WRITE32(Dma_Ctrl, SENT_CHN_DMA_CTRL(TimerModule));

    /* The hardware glitch filter is too weak, software filter may need to be added. */
    /* Filter Func*/
    REG_WRITE32(0x0, SENT_CPT_X0_FLT(TimerModule,HwChannel));

    /* restore timer clock and predivider */
    if (Sent_Ip_aSetClkInfo[TimerModule] == TRUE) {

        /* disable clk mon first */
        VAR(uint32, AUTOMATIC) Clk_Mon = 0u;
        Clk_Mon = SENT_BM_CLK_MON_EN_CMP_SET | SENT_BM_CLK_MON_EN_EN_N;
        REG_WRITE32(Clk_Mon, SENT_CLK_MON_EN(TimerModule));

        /* set clk info */
        VAR(uint32, AUTOMATIC) Clk_Set = 0u;
        Clk_Set = SENT_FV_TIM_CLK_CONFIG_DIV_NUM(0);
        /* set src clock as default clock source */
        Clk_Set |= SENT_FV_TIM_CLK_CONFIG_SRC_CLK_SEL(0);
        Clk_Set |= SENT_BM_TIM_CLK_CONFIG_CLK_CHANGE_UPD;
        REG_WRITE32(Clk_Set, SENT_TIM_CLK_CONFIG(TimerModule));

        u32Timeout = 1000U;
        do {
            /* wait for clk info effective, timeout is about 5 clock */
            u32Value = (REG_READ32(SENT_TIM_CLK_CONFIG(TimerModule)) & 
                        SENT_BM_TIM_CLK_CONFIG_CLK_CHANGE_UPD);
        } while ((0x1U == u32Value) && (u32Timeout--));

        /* enable clk mon */
        Clk_Mon = SENT_BM_CLK_MON_EN_CMP_SET | SENT_BM_CLK_MON_EN_EN_P;
        REG_WRITE32(Clk_Mon, SENT_CLK_MON_EN(TimerModule));

        Sent_Ip_aSetClkInfo[TimerModule] = FALSE;
    }

    /* read empty fifo data, if fifo is not empty */
    while (!(REG_READ32(SENT_FIFO_STA(TimerModule)) >> ((8u * HwChannel) + 1u))) {
        u32Value = REG_READ32(SENT_FIFO_ADDR32(TimerModule, HwChannel));

        /* Avoid warnings */
        u32Value++;
    }

    /* reset eTimer HwChannel*/
    REG_RMW32(SENT_RST_CHANNEL(TimerModule), HwChannel, 1u, 1u);
    u32Timeout = 1000U;
    do {
        /* wait for HwChannel reset finished, timeout is about 5 clock */
        u32Value = (REG_READ32(SENT_RST_CHANNEL(TimerModule)) & (1U << HwChannel)); 
    } while ((0x1U == u32Value) && (u32Timeout--));

    /* restore sent parameter */
    Sent_Scaler[ChannelId].u32ExpectScaler = 0;
    Sent_Scaler[ChannelId].u32ActualScaler = 0;
    gSent_Channel[ChannelId].FrameInfo.u8Dl = 0;
    gSent_Channel[ChannelId].eChnFormat = SENT_STANDARD_FORMAT;
    SentNotificationEnable[ChannelId] = FALSE;
}


FUNC(void, SENT_CODE) Sent_Ip_StartReciever
(
    VAR(uint8, AUTOMATIC) ChannelId,
    P2CONST(Sent_HwChannelConfigType, AUTOMATIC, SENT_APPL_CONST) pHwChannelConfig
)
{
    VAR(uint8, AUTOMATIC) TimerModule = pHwChannelConfig->u8TimerModule;
    VAR(uint8, AUTOMATIC) HwChannel = pHwChannelConfig->u8HwChannel;
    /* Turn on dma req interrupt */
    REG_RMW32(SENT_INT_STA_EN_ADDR32(TimerModule), (20 + HwChannel), 1u, 1u);
    REG_RMW32(SENT_INT_SIG_EN_ADDR32(TimerModule), (20 + HwChannel), 1u, 1u);
    /* enable cpt module */
    REG_RMW32(SENT_CPT_CTRL(TimerModule), SENT_CPT_CTRL_CPT_EN_START_BIT(HwChannel), 1u, 1u);
    /* update the channel error status */
    gSent_Channel[ChannelId].eError = SENT_OK;
    /* set channel initial frame state */
    gSent_Channel[ChannelId].eCurstate = SENT_IDLE;

    if (pHwChannelConfig->bNotifyFrameOver == TRUE) {
        SentNotificationEnable[ChannelId] = TRUE;
    }
}

FUNC(void, SENT_CODE) Sent_Ip_StopReciever
(
    VAR(uint8, AUTOMATIC) ChannelId,
    P2CONST(Sent_HwChannelConfigType, AUTOMATIC, SENT_APPL_CONST) pHwChannelConfig
)
{
    VAR(uint8, AUTOMATIC) TimerModule = pHwChannelConfig->u8TimerModule;
    VAR(uint8, AUTOMATIC) HwChannel = pHwChannelConfig->u8HwChannel;
    /* Turn off dma req interrupt */
    REG_RMW32(SENT_INT_STA_EN_ADDR32(TimerModule), (20 + HwChannel), 1u, 0u);
    REG_RMW32(SENT_INT_SIG_EN_ADDR32(TimerModule), (20 + HwChannel), 1u, 0u);
    /* disable cpt module */
    REG_RMW32(SENT_CPT_CTRL(TimerModule), SENT_CPT_CTRL_CPT_EN_START_BIT(HwChannel), 1u, 0u);
    /* update the channel error status */
    gSent_Channel[ChannelId].eError = SENT_OK;
    /* set channel initial frame state */
    gSent_Channel[ChannelId].eCurstate = SENT_IDLE;
    SentNotificationEnable[ChannelId] = FALSE;
}

FUNC(void, SENT_CODE) Sent_Ip_Parse_Massage
(
    VAR(uint8, AUTOMATIC) ChannelId,
    P2CONST(Sent_ChannelConfigType, SENT_CONST, SENT_APPL_DATA) ChannelConfig
)
{
    
    VAR(uint32, AUTOMATIC) Value = (uint32)0u;
    VAR(uint8, AUTOMATIC) TimerModule;
    VAR(uint8, AUTOMATIC) HwChannel;
    VAR(uint32, AUTOMATIC) FifoSta;
    VAR(boolean, AUTOMATIC) PausePulse;
    VAR(uint32, AUTOMATIC) Reminder;
    VAR(uint32, AUTOMATIC) i;

    TimerModule = (uint8)ChannelConfig->SentHwChannelConfig->u8TimerModule;
    HwChannel = (uint8)ChannelConfig->SentHwChannelConfig->u8HwChannel;
    PausePulse = ChannelConfig->SentHwChannelConfig->bPausePulse;

    /* read empty fifo data and clear frame current status, if fifo overflow */
    if (0x1U == (REG_READ32(SENT_FIFO_STA(TimerModule)) >> ((8u * HwChannel) + 7u))) {
        while (!(REG_READ32(SENT_FIFO_STA(TimerModule)) >> ((8u * HwChannel) + 1u))) {
            VAR(uint32, AUTOMATIC) u32Value = REG_READ32(SENT_FIFO_ADDR32(TimerModule, HwChannel));

            /* Avoid warnings */
            u32Value++;
        }

        gSent_Channel[ChannelId].eCurstate = SENT_IDLE;
        gSent_Channel[ChannelId].FrameInfo.u8RxIndex = 0;
    } else {
        FifoSta = REG_READ32(SENT_FIFO_STA(TimerModule));
        
        /* read fifo value */
        for (i = 0; i < ((FifoSta >> ((8u * HwChannel) + 2u)) & 0x1fu); i++) {
            Value = REG_READ32(SENT_FIFO_ADDR32(TimerModule, HwChannel));
            
            switch (gSent_Channel[ChannelId].eCurstate) {
            case SENT_IDLE: {
                /* Verification frequency valid */
                VAR(uint32, AUTOMATIC) Scaler = Value / 56U;
                VAR(uint32, AUTOMATIC) ErrRange = (Scaler * 10U) / (Sent_Scaler[ChannelId].u32ExpectScaler);
                gSent_Channel[ChannelId].eError = SENT_OK;

                if ((ErrRange >= 8U) && (ErrRange <= 12U)) {
                    Sent_Scaler[ChannelId].u32ActualScaler = Scaler;
                    gSent_Channel[ChannelId].eCurstate = SENT_SYNC;
                } else {
                    gSent_Channel[ChannelId].eError |= SENT_SYNC_ERR;
                    gSent_Channel[ChannelId].eError |= SENT_TICK_FREQ_ERR;
                }

                break;
            }

            case SENT_SYNC: {
                VAR(uint32, AUTOMATIC) StatusTick = (Value * 10U) / (Sent_Scaler[ChannelId].u32ActualScaler);
                Reminder = StatusTick % 100U;
                Reminder = Reminder % 10U;
                (Reminder < 5) ? (StatusTick = StatusTick / 10U) : (StatusTick = (StatusTick / 10U) + 1U);

                /* Verification tick number */
                if ((StatusTick < 12U) || (StatusTick > 27U)) {
                    gSent_Channel[ChannelId].eError |= SENT_STATUS_ERR;
                }

                /* status value */
                gSent_Channel[ChannelId].FrameInfo.u8Status = (StatusTick - 12U);
                gSent_Channel[ChannelId].FrameInfo.u8RxIndex = 0;
                gSent_Channel[ChannelId].eCurstate = SENT_DATA;
                break;
            }

            case SENT_DATA: {
                VAR(uint32, AUTOMATIC) DataTick = (Value * 10U) / (Sent_Scaler[ChannelId].u32ActualScaler);
                Reminder = DataTick % 100U;
                Reminder = Reminder % 10U;
                (Reminder < 5) ? (DataTick = DataTick / 10U) : (DataTick = (DataTick / 10U) + 1);
                VAR(uint8, AUTOMATIC) RxIdx = gSent_Channel[ChannelId].FrameInfo.u8RxIndex;

                if ((DataTick < 12U) || (DataTick > 27U)) {
                    gSent_Channel[ChannelId].eError |= SENT_DATA_ERR;
                }

                /* Data Value */
                gSent_Channel[ChannelId].FrameInfo.u8Rxframe[RxIdx] = (DataTick - 12U);
                gSent_Channel[ChannelId].FrameInfo.u8RxIndex += 1U;

                if (gSent_Channel[ChannelId].FrameInfo.u8RxIndex == gSent_Channel[ChannelId].FrameInfo.u8Dl) {
                    gSent_Channel[ChannelId].FrameInfo.u8RxIndex = 0;
                    gSent_Channel[ChannelId].eCurstate = SENT_CRC;
                }

                break;
            }

            case SENT_CRC: {
                VAR(uint32, AUTOMATIC) CrcTick = (Value * 10U) / (Sent_Scaler[ChannelId].u32ActualScaler);
                Reminder = CrcTick % 100U;
                Reminder = Reminder % 10U;
                (Reminder < 5U) ? (CrcTick = CrcTick / 10U) : (CrcTick = (CrcTick / 10U) + 1U);

                if ((CrcTick < 12U) || (CrcTick > 27U)) {
                    gSent_Channel[ChannelId].eError |= SENT_CRC_ERR;
                }

                VAR(uint8, AUTOMATIC) DataLength = gSent_Channel[ChannelId].FrameInfo.u8Dl;
                VAR(uint8, AUTOMATIC) CrcCalc = crc4_calculate(5, gSent_Channel[ChannelId].FrameInfo.u8Rxframe,
                                                DataLength);

                if (CrcCalc != (CrcTick - 12)) {
                    gSent_Channel[ChannelId].eError |= SENT_CRC_ERR;
                }

                /* saved crc value */
                gSent_Channel[ChannelId].FrameInfo.u8Crc = (CrcTick - 12U);

                /* update current frame newest status */
                memcpy(&Sent_FrameInfo[ChannelId], &gSent_Channel[ChannelId], sizeof(Sent_Channel));
                Sent_FrameInfo[ChannelId].bReadFlag = TRUE;

                /* callback user function */
                if (PausePulse == TRUE) {
                    gSent_Channel[ChannelId].eCurstate = SENT_PAUSE;
                } else {
                    gSent_Channel[ChannelId].eCurstate = SENT_IDLE;

                    if (SentNotificationEnable[ChannelId] == TRUE) {
                        ChannelConfig->SentHwChannelConfig->pfFrameOverNotification();
                    }
                }
                break;
            }

            case SENT_PAUSE: {
                gSent_Channel[ChannelId].eCurstate = SENT_IDLE;

                if (SentNotificationEnable[ChannelId] == TRUE) {
                    ChannelConfig->SentHwChannelConfig->pfFrameOverNotification();
                }

                break;
            }

            default: {
                break;
            }
            }
        }
    }
}

FUNC(uint32, SENT_CODE) Sent_Ip_GetInterrupt
(
    VAR(uint8, AUTOMATIC) eModule
)
{
    return REG_READ32(SENT_INT_STA_ADDR32(eModule));
}

FUNC(void, SENT_CODE) Sent_Ip_ClearInterrupt
(
    VAR(uint8, AUTOMATIC) eModule,
    VAR(uint8, AUTOMATIC) Position
)
{
    REG_WRITE32( 1UL << Position, SENT_INT_STA_ADDR32(eModule));
}

#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#ifdef __cplusplus
}
#endif

