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

#ifndef XTAL_REG_H
#define XTAL_REG_H

#ifdef __cplusplus
extern "C" {
#endif
/* Version and Check Begin */
/* Version Info Begin */
#define XTAL_REG_H_VENDOR_ID    0x8C
#define XTAL_REG_H_AR_RELEASE_MAJOR_VERSION    4
#define XTAL_REG_H_AR_RELEASE_MINOR_VERSION    3
#define XTAL_REG_H_AR_RELEASE_REVISION_VERSION 1
#define XTAL_REG_H_SW_MAJOR_VERSION    1
#define XTAL_REG_H_SW_MINOR_VERSION    0
#define XTAL_REG_H_SW_PATCH_VERSION    0
/* Version Info End */
/* Version and Check End */

//--------------------------------------------------------------------------
// Component          : semidrive.com, d_ip_fs_32k, fs_32k, r0p0
// Memory Map         : APB
// Address Block Name : AB0
// Description        : Address Block 0 of fs_32k
//--------------------------------------------------------------------------
#define FS_32K_BASE_ADDR 0xf0030000u

//--------------------------------------------------------------------------
// Register Name   : 32K_FS_GLB_CTL
// Register Offset : 0x0
// Description     : FS24M GLOBAL CONGROL REGISTER
//--------------------------------------------------------------------------
#define FS_32K_FS_GLB_CTL    0x0U

#define BM_FS_32K_FS_GLB_CTL_XTAL_ACTIVE    (0x01UL << 31U)

#define BM_FS_32K_FS_GLB_CTL_RC_ACTIVE      (0x01UL << 30U)

#define BM_FS_32K_FS_GLB_CTL_XTAL_RDY       (0x01UL << 29U)

#define BM_FS_32K_FS_GLB_CTL_RC_RDY         (0x01UL << 28U)

#define BM_FS_32K_FS_GLB_CTL_CMP_FORCE_CLR         (0x01UL << 8U)

#define BM_FS_32K_FS_GLB_CTL_EXT_OSC_EN           (0x01UL << 5U)

#define BM_FS_32K_FS_GLB_CTL_EXT_XTAL_EN           (0x01UL << 4U)

#define BM_FS_32K_FS_GLB_CTL_FS_OSC_EN             (0x01UL << 3U)

#define BM_FS_32K_FS_GLB_CTL_FS_XTAL_EN             (0x01UL << 2U)

#define BM_FS_32K_FS_GLB_CTL_FS_SRC_SEL             (0x01UL << 1U)
#define BM_FS_32K_FS_GLB_CTL_XTAL_SRC_SEL             (0x01UL << 0U)


//--------------------------------------------------------------------------
// Register Name   : FS_32K_XTAL_CTL
// Register Offset : 0x20
// Description     : XTAL CONTROL REGISTGER
//--------------------------------------------------------------------------
#define FS_32K_XTAL_CTL                                 0x20u

#define BM_FS_32K_XTAL_CTL_XTAL_RDY_DLY    (0x01UL << 6U)

#define BM_FS_32K_XTAL_CTL_POE              (0x01UL << 5U)

#define BM_FS_32K_XTAL_CTL_DS                 (0x01UL << 4U)

#define BM_FS_32K_XTAL_CTL_TE                 (0x01UL << 1U)

#define BM_FS_32K_XTAL_CTL_E0                 (0x01UL << 0U)



//--------------------------------------------------------------------------
// Register Name   : REG_AP_APB_FS_32K_LPVD_CTL
// Register Offset : 0x30
// Description     : LP VOLTAGE DETECTOR CONTROL REGISTER
//--------------------------------------------------------------------------
#define FS_32K_LPVD_CTL                         0x30u

#define BM_FS_32K_LPVD_CTL_BGOK                     (0x01UL << 31U)

#define BM_FS_32K_LPVD_CTL_V33_UV_STA               (0x01UL << 27U)

#define BM_FS_32K_LPVD_CTL_V33_OV_STA               (0x01UL << 26U)

#define BM_FS_32K_LPVD_CTL_V08_UV_STA               (0x01UL << 25U)

#define BM_FS_32K_LPVD_CTL_V08_OV_STA               (0x01UL << 24U)

#define BM_FS_32K_LPVD_CTL_LPVD_NG_CLR              (0x01UL << 21U)

#define BM_FS_32K_LPVD_CTL_LPVD_NG_STA              (0x01UL << 20U)

#define BM_FS_32K_LPVD_CTL_V33_UV_MASK              (0x01UL << 19U)

#define BM_FS_32K_LPVD_CTL_V33_OV_MASK              (0x01UL << 18U)

#define BM_FS_32K_LPVD_CTL_V08_UV_MASK              (0x01UL << 17U)

#define BM_FS_32K_LPVD_CTL_V08_OV_MASK              (0x01UL << 16U)

#define FM_FS_32K_LPVD_CTL_ATEST_SEL                (0x7U << 12U)
#define FV_FS_32K_LPVD_CTL_ATEST_SEL(v) \
    (((v) << 12U) & FM_FS_32K_LPVD_CTL_ATEST_SEL)
#define GFV_FS_32K_LPVD_CTL_ATEST_SEL(v) \
    (((v) & FM_FS_32K_LPVD_CTL_ATEST_SEL) >> 12U)


#define FM_FS_32K_LPVD_CTL_CTRL                     (0xffUL << 4U)
#define FV_FS_32K_LPVD_CTL_CTRL(v) \
    (((uint32)(v) << 4U) & FM_FS_32K_LPVD_CTL_CTRL)
#define GFV_FS_32K_LPVD_CTL_CTRL(v) \
    (((uint32)(v) & FM_FS_32K_LPVD_CTL_CTRL) >> 4U)

#define FM_FS_32K_LPVD_CTL_TRIM                     (0x7U << 1U)
#define FV_FS_32K_LPVD_CTL_TRIM(v) \
    (((v) << 1U) & FM_FS_32K_LPVD_CTL_TRIM)
#define GFV_FS_32K_LPVD_CTL_TRIM(v) \
    (((v) & FM_FS_32K_LPVD_CTL_TRIM) >> 1U)

#define BM_FS_32K_LPVD_CTL_PD                       (0x01UL << 0U)

#ifdef __cplusplus
}
#endif

#endif  /* XTAL_REG_H */
