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
 * @file  Sent_Register_E3.h
 * @brief Semidrive. MCAL Sent
 */


#ifndef SENT_REGISTER_E3_H
#define SENT_REGISTER_E3_H

#ifdef __cplusplus
extern "C" {
#endif
/* Version and Check Begin */
/* Version Info Begin */
#define SENT_REGISTER_H_VENDOR_ID    0x8C
#define SENT_REGISTER_H_AR_RELEASE_MAJOR_VERSION    4
#define SENT_REGISTER_H_AR_RELEASE_MINOR_VERSION    3
#define SENT_REGISTER_H_AR_RELEASE_REVISION_VERSION 1
#define SENT_REGISTER_H_SW_MAJOR_VERSION    1
#define SENT_REGISTER_H_SW_MINOR_VERSION    0
#define SENT_REGISTER_H_SW_PATCH_VERSION    0
/* Version Info End */
/* Version and Check End */

extern VAR(uint32, SENT_VAR) SENT_ETMR_BASE[TIMER_MODULE_NUMBER];

#define SENT_INT_STA_ADDR32(tm)          (SENT_ETMR_BASE[tm])
#define SENT_INT_STA_EN_ADDR32(tm)       (SENT_ETMR_BASE[tm] + (uint32)0x4U)
#define SENT_INT_SIG_EN_ADDR32(tm)       (SENT_ETMR_BASE[tm] + (uint32)0x8U)

#define SENT_FIFO_ADDR32(tm, cha)        (SENT_ETMR_BASE[tm] + (uint32)0xC0U + ((uint32)cha*0x4u))

#define SENT_TIM_CLK_CONFIG(tm)          (SENT_ETMR_BASE[tm] + (uint32)0xA0U)
#define SENT_BM_TIM_CLK_CONFIG_CLK_CHANGE_UPD (0x01U << 31U)
#define SENT_FM_TIM_CLK_CONFIG_SRC_CLK_SEL (0x3U << 16U)
#define SENT_FV_TIM_CLK_CONFIG_SRC_CLK_SEL(v) \
    (((v) << 16U) & SENT_FM_TIM_CLK_CONFIG_SRC_CLK_SEL)
#define SENT_FM_TIM_CLK_CONFIG_DIV_NUM (0xffffU << 0U)
#define SENT_FV_TIM_CLK_CONFIG_DIV_NUM(v) \
    (((v) << 0U) & SENT_FM_TIM_CLK_CONFIG_DIV_NUM)

#define SENT_RST_CHANNEL(tm)             (SENT_ETMR_BASE[tm] + (uint32)0xA8U)

#define SENT_FIFO_STA(tm)                (SENT_ETMR_BASE[tm] + (uint32)0xD0U)

#define SENT_CLK_MON_EN(tm)              (SENT_ETMR_BASE[tm] + (uint32)0xA4U)
#define SENT_BM_CLK_MON_EN_CMP_SET (0x01U << 2U)
#define SENT_BM_CLK_MON_EN_EN_N (0x01U << 1U)
#define SENT_BM_CLK_MON_EN_EN_P (0x01U << 0U)


#define SENT_LOCAL_CNT_CFG(tm,cha)       (SENT_ETMR_BASE[tm] + 0x148U + (cha)*0x20)

#define SENT_CNT_CFG_START_BY_FIRST_CPT_START_BIT 25
#define SENT_CNT_CFG_CPT1_CLR_EN_START_BIT 24
#define SENT_CNT_CFG_CPT0_CLR_EN_START_BIT 23
#define SENT_CNT_CFG_INIT_UPD_START_BIT 16
#define SENT_CNT_CFG_OVF_UPD_START_BIT 17


#define ETMR_BM_LCNT_CFG_OVF_RST_DIS (0x01U << 28U)
#define ETMR_BM_LCNT_CFG_DELTA_TIME_EN (0x01U << 27U)
#define ETMR_BM_LCNT_CFG_SIG_EN (0x01U << 26U)
#define ETMR_BM_LCNT_CFG_START_BY_FIRST_CPT (0x01U << 25U)
#define ETMR_BM_LCNT_CFG_CPT1_CLR_EN (0x01U << 24U)
#define ETMR_BM_LCNT_CFG_CPT0_CLR_EN (0x01U << 23U)
#define ETMR_FM_LCNT_CFG_SIG_TRIG_SEL (0x3U << 21U)
#define ETMR_FV_LCNT_CFG_SIG_TRIG_SEL(v) \
    (((v) << 21U) & ETMR_FM_LCNT_CFG_SIG_TRIG_SEL)
#define ETMR_BM_LCNT_CFG_NO_STOP_OVF_MODE (0x01U << 20U)
#define ETMR_BM_LCNT_CFG_NO_STOP_MODE (0x01U << 19U)
#define ETMR_BM_LCNT_CFG_CON_MODE (0x01U << 18U)
#define ETMR_BM_LCNT_CFG_OVF_UPD (0x01U << 17U)
#define ETMR_BM_LCNT_CFG_INIT_UPD (0x01U << 16U)
#define ETMR_FM_LCNT_CFG_INTERVAL (0xffU << 8U)
#define ETMR_FV_LCNT_CFG_INTERVAL(v) \
    (((v) << 8U) & ETMR_FM_LCNT_CFG_INTERVAL)
#define ETMR_BM_LCNT_CFG_CE_EN (0x01U << 7U)
#define ETMR_FM_LCNT_CFG_CLR_TRIG_SEL (0x3U << 5U)
#define ETMR_FV_LCNT_CFG_CLR_TRIG_SEL(v) \
    (((v) << 5U) & ETMR_FM_LCNT_CFG_CLR_TRIG_SEL)
#define ETMR_FM_LCNT_CFG_SET_UPD_SEL (0x3U << 3U)
#define ETMR_FV_LCNT_CFG_SET_UPD_SEL(v) \
    (((v) << 3U) & ETMR_FM_LCNT_CFG_SET_UPD_SEL)
#define ETMR_FM_LCNT_CFG_SET_TRIG_SEL (0x3U << 1U)
#define ETMR_FV_LCNT_CFG_SET_TRIG_SEL(v) \
    (((v) << 1U) & ETMR_FM_LCNT_CFG_SET_TRIG_SEL)
#define ETMR_BM_LCNT_CFG_FRC_RLD (0x01U << 0U)


#define SENT_LOCAL_CNT(tm,cha)           (SENT_ETMR_BASE[tm] + 0x150U + (cha)*0x20)

#define SENT_LOCAL_CNT_EN(tm, cha)       (SENT_ETMR_BASE[tm] + 0x14Cu + ((uint32)cha*0x20u))
#define SENT_LOCAL_CNT_OVF_VAL(tm, cha)  (SENT_ETMR_BASE[tm] + 0x144u + ((uint32)cha*0x20u))

#define SENT_CPT_CONFIG(tm, cha)         (SENT_ETMR_BASE[tm] + 0x200u + ((uint32)cha*0x4u))
#define SENT_CPT_CONFIG_CPT0_TRIG_MODE_START_BIT                   (2u)
#define SENT_CPT_CONFIG_CPT1_TRIG_MODE_START_BIT                   (4u)
#define SENT_CPT_CONFIG_CNT_SEL_START_BIT                          (6u)

#define SENT_CHN_DMA_CTRL(tm)            (SENT_ETMR_BASE[tm] + (uint32)0xB0U)
#define SENT_BM_CHN_DMA_CTRL_CHN_16BIT_MODE(cha) (0x01U << (16U + (cha)))
#define SENT_BM_CHN_DMA_CTRL_CHN_SIG_MASK(cha) (0x01U << (12U + (cha)))
#define SENT_FM_CHN_DMA_CTRL_CHN_SEL(cha) (0x3U << (4U + (cha)*0x2U))
#define SENT_FV_CHN_DMA_CTRL_CHN_SEL(v, cha) \
    (((v) << (4U + (cha)*0x2U)) & SENT_FM_CHN_DMA_CTRL_CHN_SEL(cha))
#define SENT_BM_CHN_DMA_CTRL_CHN_EN(cha) (0x01U << (cha))


#define SENT_CHN_DMA_WML(tm)          (SENT_ETMR_BASE[tm] + (uint32)0xB4U)
#define SENT_FM_DMA_WML_CHN(cha) (0xfU << ((cha)*0x8U))
#define SENT_FV_DMA_WML_CHN(v, cha) \
    (((v) << ((cha)*0x8U)) & SENT_FM_DMA_WML_CHN(cha))

#define SENT_CPT_X0_FLT(tm, cha)         (SENT_ETMR_BASE[tm] + 0x400u + ((uint32)cha*0x4u))
#define SENT_CPT_FLT_EN             (0x1U << 0U)
#define SENT_CPT_FLT_DISEN          (0x0U << 0U)
#define SENT_CPT_FLT_POSEDGE_SEL    (0x0U << 1U)
#define SENT_CPT_FLT_NEGEDGE_SEL    (0x1U << 1U)
#define SENT_CPT_FLT_BOTHEDGE_SEL   (0x2U << 1U)
#define SENT_CPT_FLT_POS_BAND_WID(v) ((v & 0xFU) << 4U)
#define SENT_CPT_FLT_NEG_BAND_WID(v) ((v & 0xFU) << 8U)
#define SENT_CPT_FLT_SMPL_INTVAL(v)  ((v & 0xFFU) << 12U)

#define SENT_CPT_CTRL(tm)                (SENT_ETMR_BASE[tm] + (uint32)0x210U)
#define SENT_CPT_CTRL_CPT_CONFIG_SET_START_BIT(cha)     (4U + (cha))
#define SENT_CPT_CTRL_CPT_EN_START_BIT(cha)      (cha)

#ifdef __cplusplus
}
#endif

#endif /*SENT_REGISTER_E3_H*/
