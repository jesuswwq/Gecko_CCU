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

#ifndef SCR_REG_H
#define SCR_REG_H

#ifdef __cplusplus
extern "C" {
#endif
/* Version and Check Begin */
/* Version Info Begin */
#define SCR_REG_H_VENDOR_ID    0x8C
#define SCR_REG_H_AR_RELEASE_MAJOR_VERSION    4
#define SCR_REG_H_AR_RELEASE_MINOR_VERSION    3
#define SCR_REG_H_AR_RELEASE_REVISION_VERSION 1
#define SCR_REG_H_SW_MAJOR_VERSION    1
#define SCR_REG_H_SW_MINOR_VERSION    0
#define SCR_REG_H_SW_PATCH_VERSION    0
/* Version Info End */
/* Version and Check End */

#define SCR_RW_OFF  0x0U

#define FM_SCR_RW_SC_REG    (0xffffffffU << 0U)
#define FV_SCR_RW_SC_REG(v) \
    (((v) << 0U) & FM_SCR_RW_SC_REG)
#define GFV_SCR_RW_SC_REG(v) \
    (((v) & FM_SCR_RW_SC_REG) >> 0U)

#define SCR_RO_OFF  0x100U

#define FM_SCR_RO_SC_REG    (0xffffffffU << 0U)
#define FV_SCR_RO_SC_REG(v) \
    (((v) << 0U) & FM_SCR_RO_SC_REG)
#define GFV_SCR_RO_SC_REG(v) \
    (((v) & FM_SCR_RO_SC_REG) >> 0U)

#define SCR_L16_OFF 0x200U

#define BM_SCR_L16_SC_STICKY_15 (0x01U << 31U)

#define BM_SCR_L16_SC_STICKY_14 (0x01U << 30U)

#define BM_SCR_L16_SC_STICKY_13 (0x01U << 29U)

#define BM_SCR_L16_SC_STICKY_12 (0x01U << 28U)

#define BM_SCR_L16_SC_STICKY_11 (0x01U << 27U)

#define BM_SCR_L16_SC_STICKY_10 (0x01U << 26U)

#define BM_SCR_L16_SC_STICKY_9  (0x01U << 25U)

#define BM_SCR_L16_SC_STICKY_8  (0x01U << 24U)

#define BM_SCR_L16_SC_STICKY_7  (0x01U << 23U)

#define BM_SCR_L16_SC_STICKY_6  (0x01U << 22U)

#define BM_SCR_L16_SC_STICKY_5  (0x01U << 21U)

#define BM_SCR_L16_SC_STICKY_4  (0x01U << 20U)

#define BM_SCR_L16_SC_STICKY_3  (0x01U << 19U)

#define BM_SCR_L16_SC_STICKY_2  (0x01U << 18U)

#define BM_SCR_L16_SC_STICKY_1  (0x01U << 17U)

#define BM_SCR_L16_SC_STICKY_0  (0x01U << 16U)

#define BM_SCR_L16_SC_REG_15    (0x01U << 15U)

#define BM_SCR_L16_SC_REG_14    (0x01U << 14U)

#define BM_SCR_L16_SC_REG_13    (0x01U << 13U)

#define BM_SCR_L16_SC_REG_12    (0x01U << 12U)

#define BM_SCR_L16_SC_REG_11    (0x01U << 11U)

#define BM_SCR_L16_SC_REG_10    (0x01U << 10U)

#define BM_SCR_L16_SC_REG_9 (0x01U << 9U)

#define BM_SCR_L16_SC_REG_8 (0x01U << 8U)

#define BM_SCR_L16_SC_REG_7 (0x01U << 7U)

#define BM_SCR_L16_SC_REG_6 (0x01U << 6U)

#define BM_SCR_L16_SC_REG_5 (0x01U << 5U)

#define BM_SCR_L16_SC_REG_4 (0x01U << 4U)

#define BM_SCR_L16_SC_REG_3 (0x01U << 3U)

#define BM_SCR_L16_SC_REG_2 (0x01U << 2U)

#define BM_SCR_L16_SC_REG_1 (0x01U << 1U)

#define BM_SCR_L16_SC_REG_0 (0x01U << 0U)

#define SCR_L31_OFF 0x400U

#define BM_SCR_L31_SC_LOCK  (0x01U << 31U)

#define FM_SCR_L31_SC_REG   (0x7fffffffU << 0U)
#define FV_SCR_L31_SC_REG(v) \
    (((v) << 0U) & FM_SCR_L31_SC_REG)
#define GFV_SCR_L31_SC_REG(v) \
    (((v) & FM_SCR_L31_SC_REG) >> 0U)

#define SCR_R16W16_OFF  0x600U

#define FM_SCR_R16W16_SC_ROREG  (0xffffU << 16U)
#define FV_SCR_R16W16_SC_ROREG(v) \
    (((v) << 16U) & FM_SCR_R16W16_SC_ROREG)
#define GFV_SCR_R16W16_SC_ROREG(v) \
    (((v) & FM_SCR_R16W16_SC_ROREG) >> 16U)

#define FM_SCR_R16W16_SC_REG    (0xffffU << 0U)
#define FV_SCR_R16W16_SC_REG(v) \
    (((v) << 0U) & FM_SCR_R16W16_SC_REG)
#define GFV_SCR_R16W16_SC_REG(v) \
    (((v) & FM_SCR_R16W16_SC_REG) >> 0U)

#ifdef __cplusplus
}
#endif

#endif  /* SCR_REG_H */
