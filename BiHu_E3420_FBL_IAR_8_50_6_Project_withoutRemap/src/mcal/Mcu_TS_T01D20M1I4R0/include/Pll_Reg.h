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

#ifndef MCU_PLLREG_H
#define MCU_PLLREG_H

#ifdef __cplusplus
extern "C" {
#endif
/* Version and Check Begin */
/* Version Info Begin */
#define PLL_REG_H_VENDOR_ID    0x8C
#define PLL_REG_H_AR_RELEASE_MAJOR_VERSION    4
#define PLL_REG_H_AR_RELEASE_MINOR_VERSION    3
#define PLL_REG_H_AR_RELEASE_REVISION_VERSION 1
#define PLL_REG_H_SW_MAJOR_VERSION    1
#define PLL_REG_H_SW_MINOR_VERSION    0
#define PLL_REG_H_SW_PATCH_VERSION    0
/* Version Info End */
/* Version and Check End */

#define PLL_CTRL_OFF    0x0U

#define BM_PLL_CTRL_LOCK    (0x01UL << 31U)

#define BM_PLL_CTRL_PLL_DIVD_CG_EN  (0x01UL << 21U)

#define BM_PLL_CTRL_PLL_DIVC_CG_EN  (0x01UL << 20U)

#define BM_PLL_CTRL_PLL_DIVB_CG_EN  (0x01UL << 19U)

#define BM_PLL_CTRL_PLL_DIVA_CG_EN  (0x01UL << 18U)

#define BM_PLL_CTRL_BYPASS  (0x01UL << 17U)

#define BM_PLL_CTRL_PLLPOSTCG_EN    (0x01UL << 16U)

#define BM_PLL_CTRL_FOUTPOSTDIVEN   (0x01U << 4U)

#define BM_PLL_CTRL_FOUT4PHASEEN    (0x01U << 3U)

#define BM_PLL_CTRL_DACEN   (0x01U << 2U)

#define BM_PLL_CTRL_INT_MODE    (0x01U << 1U)

#define BM_PLL_CTRL_PLLEN   (0x01U << 0U)

#define PLL_DIV_OFF 0x4U

#define FM_PLL_DIV_POSTDIV2 (0x7U << 9U)
#define FV_PLL_DIV_POSTDIV2(v) \
    (((v) << 9U) & FM_PLL_DIV_POSTDIV2)
#define GFV_PLL_DIV_POSTDIV2(v) \
    (((v) & FM_PLL_DIV_POSTDIV2) >> 9U)

#define FM_PLL_DIV_POSTDIV1 (0x7U << 6U)
#define FV_PLL_DIV_POSTDIV1(v) \
    (((v) << 6U) & FM_PLL_DIV_POSTDIV1)
#define GFV_PLL_DIV_POSTDIV1(v) \
    (((v) & FM_PLL_DIV_POSTDIV1) >> 6U)

#define FM_PLL_DIV_REFDIV   (0x3fU << 0U)
#define FV_PLL_DIV_REFDIV(v) \
    (((v) << 0U) & FM_PLL_DIV_REFDIV)
#define GFV_PLL_DIV_REFDIV(v) \
    (((v) & FM_PLL_DIV_REFDIV) >> 0U)

#define PLL_FBDIV_OFF   0x8U

#define FM_PLL_FBDIV_FBDIV  (0xfffU << 0U)
#define FV_PLL_FBDIV_FBDIV(v) \
    (((v) << 0U) & FM_PLL_FBDIV_FBDIV)
#define GFV_PLL_FBDIV_FBDIV(v) \
    (((v) & FM_PLL_FBDIV_FBDIV) >> 0U)

#define PLL_FRAC_OFF    0xcU

#define FM_PLL_FRAC_FRAC    (0xffffffU << 0U)
#define FV_PLL_FRAC_FRAC(v) \
    (((v) << 0U) & FM_PLL_FRAC_FRAC)
#define GFV_PLL_FRAC_FRAC(v) \
    (((v) & FM_PLL_FRAC_FRAC) >> 0U)

#define PLL_DESKEW_OFF  0x10U

#define FM_PLL_DESKEW_DSKEWCALIN    (0xfffU << 6U)
#define FV_PLL_DESKEW_DSKEWCALIN(v) \
    (((v) << 6U) & FM_PLL_DESKEW_DSKEWCALIN)
#define GFV_PLL_DESKEW_DSKEWCALIN(v) \
    (((v) & FM_PLL_DESKEW_DSKEWCALIN) >> 6U)

#define FM_PLL_DESKEW_DSKEWCALCNT   (0x7U << 3U)
#define FV_PLL_DESKEW_DSKEWCALCNT(v) \
    (((v) << 3U) & FM_PLL_DESKEW_DSKEWCALCNT)
#define GFV_PLL_DESKEW_DSKEWCALCNT(v) \
    (((v) & FM_PLL_DESKEW_DSKEWCALCNT) >> 3U)

#define BM_PLL_DESKEW_DSKEWCALBYP   (0x01U << 2U)

#define BM_PLL_DESKEW_DSKEWFASTCAL  (0x01U << 1U)

#define BM_PLL_DESKEW_DSKEWCALEN    (0x01U << 0U)

#define PLL_DESKEW_STA_OFF  0x14U

#define FM_PLL_DESKEW_STA_DSKEWCALOUT   (0xfffU << 5U)
#define FV_PLL_DESKEW_STA_DSKEWCALOUT(v) \
    (((v) << 5U) & FM_PLL_DESKEW_STA_DSKEWCALOUT)
#define GFV_PLL_DESKEW_STA_DSKEWCALOUT(v) \
    (((v) & FM_PLL_DESKEW_STA_DSKEWCALOUT) >> 5U)

#define FM_PLL_DESKEW_STA_DSKEWCALLOCKCNT   (0xfU << 1U)
#define FV_PLL_DESKEW_STA_DSKEWCALLOCKCNT(v) \
    (((v) << 1U) & FM_PLL_DESKEW_STA_DSKEWCALLOCKCNT)
#define GFV_PLL_DESKEW_STA_DSKEWCALLOCKCNT(v) \
    (((v) & FM_PLL_DESKEW_STA_DSKEWCALLOCKCNT) >> 1U)

#define BM_PLL_DESKEW_STA_DSKEWCALLOCK  (0x01U << 0U)

#define PLL_SSMOD_OFF   0x18U

#define FM_PLL_SSMOD_DIVVAL (0x3fU << 9U)
#define FV_PLL_SSMOD_DIVVAL(v) \
    (((v) << 9U) & FM_PLL_SSMOD_DIVVAL)
#define GFV_PLL_SSMOD_DIVVAL(v) \
    (((v) & FM_PLL_SSMOD_DIVVAL) >> 9U)

#define FM_PLL_SSMOD_SPREAD (0x1fU << 4U)
#define FV_PLL_SSMOD_SPREAD(v) \
    (((v) << 4U) & FM_PLL_SSMOD_SPREAD)
#define GFV_PLL_SSMOD_SPREAD(v) \
    (((v) & FM_PLL_SSMOD_SPREAD) >> 4U)

#define BM_PLL_SSMOD_DOWNSPREAD (0x01U << 3U)

#define BM_PLL_SSMOD_RESETPTR   (0x01U << 2U)

#define BM_PLL_SSMOD_DISABLE_SSCG   (0x01U << 1U)

#define BM_PLL_SSMOD_MOD_RESET  (0x01U << 0U)

#define PLL_OUT_DIV_1_OFF   0x20U

#define BM_PLL_OUT_DIV_1_DIV_BUSY_B (0x01UL << 31U)

#define FM_PLL_OUT_DIV_1_DIV_NUM_B  (0xfUL << 16U)
#define FV_PLL_OUT_DIV_1_DIV_NUM_B(v) \
    (((uint32)(v) << 16U) & FM_PLL_OUT_DIV_1_DIV_NUM_B)
#define GFV_PLL_OUT_DIV_1_DIV_NUM_B(v) \
    (((v) & FM_PLL_OUT_DIV_1_DIV_NUM_B) >> 16U)

#define BM_PLL_OUT_DIV_1_DIV_BUSY_A (0x01UL << 15U)

#define FM_PLL_OUT_DIV_1_DIV_NUM_A  (0xfUL << 0U)
#define FV_PLL_OUT_DIV_1_DIV_NUM_A(v) \
    (((uint32)(v) << 0U) & FM_PLL_OUT_DIV_1_DIV_NUM_A)
#define GFV_PLL_OUT_DIV_1_DIV_NUM_A(v) \
    (((v) & FM_PLL_OUT_DIV_1_DIV_NUM_A) >> 0U)

#define PLL_OUT_DIV_2_OFF   0x24U

#define BM_PLL_OUT_DIV_2_DIV_BUSY_D (0x01UL << 31U)

#define FM_PLL_OUT_DIV_2_DIV_NUM_D  (0xfUL << 16U)
#define FV_PLL_OUT_DIV_2_DIV_NUM_D(v) \
    (((uint32)(v) << 16U) & FM_PLL_OUT_DIV_2_DIV_NUM_D)
#define GFV_PLL_OUT_DIV_2_DIV_NUM_D(v) \
    (((v) & FM_PLL_OUT_DIV_2_DIV_NUM_D) >> 16U)

#define BM_PLL_OUT_DIV_2_DIV_BUSY_C (0x01UL << 15U)

#define FM_PLL_OUT_DIV_2_DIV_NUM_C  (0xfUL << 0U)
#define FV_PLL_OUT_DIV_2_DIV_NUM_C(v) \
    (((uint32)(v) << 0U) & FM_PLL_OUT_DIV_2_DIV_NUM_C)
#define GFV_PLL_OUT_DIV_2_DIV_NUM_C(v) \
    (((v) & FM_PLL_OUT_DIV_2_DIV_NUM_C) >> 0U)

#ifdef __cplusplus
}
#endif

#endif  /* MCU_PLLREG_H */
