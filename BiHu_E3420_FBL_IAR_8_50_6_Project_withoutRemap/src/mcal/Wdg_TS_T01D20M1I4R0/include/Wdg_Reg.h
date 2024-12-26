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
 * @file  Wdg_Reg.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Wdg
 */

#ifndef WDT_REG_H
#define WDT_REG_H

/* Version and Check Begin */
/* Version Info Begin */
#define WDG_REG_H_VENDOR_ID    0x8C
#define WDG_REG_H_AR_RELEASE_MAJOR_VERSION    4
#define WDG_REG_H_AR_RELEASE_MINOR_VERSION    3
#define WDG_REG_H_AR_RELEASE_REVISION_VERSION 1
#define WDG_REG_H_SW_MAJOR_VERSION    1
#define WDG_REG_H_SW_MINOR_VERSION    0
#define WDG_REG_H_SW_PATCH_VERSION    0
/* Version Info End */
/* Version and Check End */
#define WDT_CTRL_OFF                 0x0U

#define FM_WDT_CTRL_PRE_DIV_NUM (0xffffU)
#define FV_WDT_CTRL_PRE_DIV_NUM(v) \
    (((v)) & FM_WDT_CTRL_PRE_DIV_NUM)
#define GFV_WDT_CTRL_PRE_DIV_NUM(v) \
    (((v) & FM_WDT_CTRL_PRE_DIV_NUM))

#define BM_WDT_CTRL_WDT_EN_STA       (10U)

#define BM_WDT_CTRL_SELFTEST_TRIG    (9U)

#define BM_WDT_CTRL_WDT_EN_SRC       (8U)

#define BM_WDT_CTRL_DBG_HALT_EN      (7U)

#define BM_WDT_CTRL_AUTO_RESTART     (6U)

#define BM_WDT_CTRL_WTC_SRC          (5U)

#define FM_WDT_CTRL_CLK_SRC          (0x7U)
#define FV_WDT_CTRL_CLK_SRC(v) \
              (((v)) & FM_WDT_CTRL_CLK_SRC)
#define GFV_WDT_CTRL_CLK_SRC(v) \
              (((v) & FM_WDT_CTRL_CLK_SRC))

#define BM_WDT_CTRL_WDT_EN           (1U)

#define BM_WDT_CTRL_SOFT_RST         (0U)

#define WDT_WTC_OFF                  (0x4U)

#define FM_WDT_WTC_WTC_VAL  (0xffffffffU << 0U)
#define FV_WDT_WTC_WTC_VAL(v) \
    (((v) << 0U) & FM_WDT_WTC_WTC_VAL)
#define GFV_WDT_WTC_WTC_VAL(v) \
    (((v) & FM_WDT_WTC_WTC_VAL) >> 0U)

#define WDT_WRC_CTL_OFF 0x8U

#define BM_WDT_WRC_CTL_REFR_TRIG    (3U)

#define BM_WDT_WRC_CTL_SEQ_REFR_EN  (2U)

#define BM_WDT_WRC_CTL_MODE1_EN (1U)

#define BM_WDT_WRC_CTL_MODE0_EN (0U)

#define WDT_WRC_VAL_OFF 0xcU

#define FM_WDT_WRC_VAL_WIN_LOW_LIMIT    (0xffffffffU << 0U)
#define FV_WDT_WRC_VAL_WIN_LOW_LIMIT(v) \
    (((v) << 0U) & FM_WDT_WRC_VAL_WIN_LOW_LIMIT)
#define GFV_WDT_WRC_VAL_WIN_LOW_LIMIT(v) \
    (((v) & FM_WDT_WRC_VAL_WIN_LOW_LIMIT) >> 0U)

#define WDT_WRC_SEQ_OFF 0x10U

#define FM_WDT_WRC_SEQ_SEQ_DELTA    (0xffffffffU << 0U)
#define FV_WDT_WRC_SEQ_SEQ_DELTA(v) \
    (((v) << 0U) & FM_WDT_WRC_SEQ_SEQ_DELTA)
#define GFV_WDT_WRC_SEQ_SEQ_DELTA(v) \
    (((v) & FM_WDT_WRC_SEQ_SEQ_DELTA) >> 0U)

#define WDT_RST_CTL_OFF 0x14U

#define BM_WDT_RST_CTL_RST_WIN  (20U)

#define BM_WDT_RST_CTL_WDT_RST_EN   (18U)

#define BM_WDT_RST_CTL_INT_RST_MODE (17U)

#define BM_WDT_RST_CTL_INT_RST_EN   (16U)

#define FM_WDT_RST_CTL_RST_CNT  (0xffffU << 0U)

#define WDT_EXT_RST_CTL_OFF 0x18U

#define BM_WDT_EXT_RST_CTL_RST_WIN  (20U)

#define BM_WDT_EXT_RST_CTL_EXT_RST_MODE (17U)

#define BM_WDT_EXT_RST_CTL_EXT_RST_EN   (16U)

#define FM_WDT_EXT_RST_CTL_RST_CNT  (0xffffU << 0U)

#define WDT_CNT_OFF 0x1cU

#define FM_WDT_CNT_WDT_CNT  (0xffffffffU << 0U)
#define FV_WDT_CNT_WDT_CNT(v) \
    (((v) << 0U) & FM_WDT_CNT_WDT_CNT)
#define GFV_WDT_CNT_WDT_CNT(v) \
    (((v) & FM_WDT_CNT_WDT_CNT) >> 0U)

#define WDT_TSW_OFF 0x20U

#define FM_WDT_TSW_TSW  (0xffffffffU << 0U)
#define FV_WDT_TSW_TSW(v) \
    (((v) << 0U) & FM_WDT_TSW_TSW)
#define GFV_WDT_TSW_TSW(v) \
    (((v) & FM_WDT_TSW_TSW) >> 0U)

#define WDT_INT_OFF 0x24U

#define BM_WDT_INT_OVFLOW_INT_CLR   (8U)

#define BM_WDT_INT_ILL_SEQ_REFR_INT_CLR (7U)

#define BM_WDT_INT_ILL_WIN_REFR_INT_CLR (6U)

#define BM_WDT_INT_OVFLOW_INT_STA   (5U)

#define BM_WDT_INT_ILL_SEQ_REFR_INT_STA (4U)

#define BM_WDT_INT_ILL_WIN_REFR_INT_STA (3U)

#define BM_WDT_INT_OVFLOW_INT_EN    (2U)

#define BM_WDT_INT_ILL_SEQ_REFR_INT_EN  (1U)

#define BM_WDT_INT_ILL_WIN_REFR_INT_EN  (0U)

#define WDT_LOCK_OFF               0x40U

#define BM_WDT_LOCK_CLK_SRC_LOCK   (6U)

#define BM_WDT_LOCK_INT_LOCK       (5U)

#define BM_WDT_LOCK_EXT_RST_LOCK   (4U)

#define BM_WDT_LOCK_RST_LOCK       (3U)

#define BM_WDT_LOCK_WRC_LOCK       (2U)

#define BM_WDT_LOCK_WTC_LOCK       (1U)

#define BM_WDT_LOCK_CTL_LOCK       (0U)

#endif  /* __WDT_REG_H__ */
