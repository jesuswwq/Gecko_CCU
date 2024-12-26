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
 * @file  Gpt_Register.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Gpt
 */

#ifndef GPT_REGISTER_H
#define GPT_REGISTER_H
#ifdef __cplusplus
extern "C" {
#endif
/* Version and Check Begin */
/* Version Info Begin */
#define GPT_REGISTER_H_VENDOR_ID    0x8C
#define GPT_REGISTER_H_AR_RELEASE_MAJOR_VERSION    4
#define GPT_REGISTER_H_AR_RELEASE_MINOR_VERSION    3
#define GPT_REGISTER_H_AR_RELEASE_REVISION_VERSION 1
#define GPT_REGISTER_H_SW_MAJOR_VERSION    1
#define GPT_REGISTER_H_SW_MINOR_VERSION    0
#define GPT_REGISTER_H_SW_PATCH_VERSION    0
/* Version Info End */
/* Version and Check End */

extern CONST(uint32, GPT_CONST) BTM_BASE_ADDR32[];

/* G0 and G1 common control */
#define GPT_COM_CTRL_ADDR32(tm) (BTM_BASE_ADDR32[tm])

/* G0 Timer */
#define GPT_CNT_G0_EN_ADDR32(tm) (BTM_BASE_ADDR32[tm] + (uint32)0x4U)
#define GPT_CNT_G0_CFG_ADDR32(tm) (BTM_BASE_ADDR32[tm] + (uint32)0x8U)
#define GPT_CNT_G0_OVF_ADDR32(tm) (BTM_BASE_ADDR32[tm] + (uint32)0xCU)
#define GPT_CNT_G0_CMP_ADDR32(tm) (BTM_BASE_ADDR32[tm] + (uint32)0x10U)
#define GPT_CNT_G0_VAL_ADDR32(tm) (BTM_BASE_ADDR32[tm] + (uint32)0x14U)
#define GPT_CNT_G0_HOLD_ADDR32(tm) (BTM_BASE_ADDR32[tm] + (uint32)0x18U)

/* G1 Timer */
#define GPT_CNT_G1_EN_ADDR32(tm) (BTM_BASE_ADDR32[tm] + (uint32)0x24U)
#define GPT_CNT_G1_CFG_ADDR32(tm) (BTM_BASE_ADDR32[tm] + (uint32)0x28U)
#define GPT_CNT_G1_OVF_ADDR32(tm) (BTM_BASE_ADDR32[tm] + (uint32)0x2CU)
#define GPT_CNT_G1_CMP_ADDR32(tm) (BTM_BASE_ADDR32[tm] + (uint32)0x30U)
#define GPT_CNT_G1_VAL_ADDR32(tm) (BTM_BASE_ADDR32[tm] + (uint32)0x34U)
#define GPT_CNT_G1_UPD_ADDR32(tm) (BTM_BASE_ADDR32[tm] + (uint32)0x38U)
#define GPT_CNT_G1_HOLD_ADDR32(tm) (BTM_BASE_ADDR32[tm] + (uint32)0x3CU)

/* INT control */
#define GPT_INT_STA_ADDR32(tm)    (BTM_BASE_ADDR32[tm] + (uint32)0x40U)
#define GPT_INT_STA_EN_ADDR32(tm)    (BTM_BASE_ADDR32[tm] + (uint32)0x44U)
#define GPT_INT_SIG_EN_ADDR32(tm)    (BTM_BASE_ADDR32[tm] + (uint32)0x48U)

/* FUSA control */
#define GPT_COR_ERR_INT_STA_ADDR32(tm)    (BTM_BASE_ADDR32[tm] + (uint32)0x4CU)
#define GPT_COR_ERR_INT_STA_EN_ADDR32(tm) (BTM_BASE_ADDR32[tm] + (uint32)0x50U)
#define GPT_COR_ERR_INT_SIG_EN_ADDR32(tm) (BTM_BASE_ADDR32[tm] + (uint32)0x54U)
#define GPT_UNCOR_ERR_INT_STA_ADDR32(tm)    (BTM_BASE_ADDR32[tm] + (uint32)0x58U)
#define GPT_UNCOR_ERR_INT_STA_EN_ADDR32(tm) (BTM_BASE_ADDR32[tm] + (uint32)0x5CU)
#define GPT_UNCOR_ERR_INT_SIG_EN_ADDR32(tm) (BTM_BASE_ADDR32[tm] + (uint32)0x60U)

#define GPT_PWDATA_ADDR32(tm) (BTM_BASE_ADDR32[tm] + (uint32)0x64U)
#define GPT_PWCODE_ADDR32(tm) (BTM_BASE_ADDR32[tm] + (uint32)0x68U)
#define GPT_IRQ_ERR_ADDR32(tm) (BTM_BASE_ADDR32[tm] + (uint32)0x6CU)
#define GPT_LSP_ADDR32(tm) (BTM_BASE_ADDR32[tm] + (uint32)0x70U)
#define GPT_SELF_TEST_MODE_ADDR32(tm) (BTM_BASE_ADDR32[tm] + (uint32)0x74U)

#ifdef __cplusplus
}
#endif

#endif /*GPT_REGISTER_H*/
