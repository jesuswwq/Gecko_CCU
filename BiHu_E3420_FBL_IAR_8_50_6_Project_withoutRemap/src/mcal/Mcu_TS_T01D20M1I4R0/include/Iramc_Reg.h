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

#ifndef IRAMC_REG_H
#define IRAMC_REG_H
#ifdef __cplusplus
extern "C" {
#endif
/* Version and Check Begin */
/* Version Info Begin */
#define IRAMC_REG_H_VENDOR_ID    0x8C
#define IRAMC_REG_H_AR_RELEASE_MAJOR_VERSION    4
#define IRAMC_REG_H_AR_RELEASE_MINOR_VERSION    3
#define IRAMC_REG_H_AR_RELEASE_REVISION_VERSION 1
#define IRAMC_REG_H_SW_MAJOR_VERSION    1
#define IRAMC_REG_H_SW_MINOR_VERSION    0
#define IRAMC_REG_H_SW_PATCH_VERSION    0
/* Version Info End */
/* Version and Check End */

/* Register define Start */
//--------------------------------------------------------------------------
// Register Name   : IRAMC_WRAP_DATA_INIT
// Register Offset : 0x0
// Description     : initialization all the ram data
//--------------------------------------------------------------------------
#define IRAMC_WRAP_DATA_INIT                 0x0U

#define IRAMC_WRAP_DATA_INIT_LOCK_FIELD_OFFSET 31
#define IRAMC_WRAP_DATA_INIT_LOCK_FIELD_SIZE 1

#define IRAMC_WRAP_DATA_INIT_INIT_FIELD_OFFSET 0
#define IRAMC_WRAP_DATA_INIT_INIT_FIELD_SIZE 1

#define BIT_IRAMC_WRAP_DATA_INIT_LOCK    (BIT_(31))

#define BIT_IRAMC_WRAP_DATA_INIT_INIT    (BIT_(0))

//--------------------------------------------------------------------------
// Register Name   : IRAMC_WRAP_POWER_CFG
// Register Offset : 0x4
// Description     : low power configuration
//--------------------------------------------------------------------------
#define IRAMC_WRAP_POWER_CFG                    0x4U

#define FM_IRAMC_WRAP_POWER_CFG_VAL (0x7U << 0U)
#define FV_IRAMC_WRAP_POWER_CFG_VAL(v) \
    (((v) << 0U) & FM_IRAMC_WRAP_POWER_CFG_VAL)
#define GFV_IRAMC_WRAP_POWER_CFG_VAL(v) \
    (((v) & FM_IRAMC_WRAP_POWER_CFG_VAL) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : IRAMC_WRAP_APB_INJ_EN
// Register Offset : 0x10
// Description     : apb interface error injection enable
//--------------------------------------------------------------------------
#define IRAMC_WRAP_APB_INJ_EN                       0x10U

#define IRAMC_WRAP_APB_INJ_EN_VAL_FIELD_OFFSET 0
#define IRAMC_WRAP_APB_INJ_EN_VAL_FIELD_SIZE 1

#define BIT_IRAMC_WRAP_APB_INJ_EN_VAL    (BIT_(0))

//--------------------------------------------------------------------------
// Register Name   : IRAMC_WRAP_APB_WDATA_INJ_BIT
// Register Offset : 0x14
// Description     : apb interface wdata error injection bit
//--------------------------------------------------------------------------
#define IRAMC_WRAP_APB_WDATA_INJ_BIT                0x14U

#define IRAMC_WRAP_APB_WDATA_INJ_BIT_VAL_FIELD_OFFSET 0
#define IRAMC_WRAP_APB_WDATA_INJ_BIT_VAL_FIELD_SIZE 32

#define BIT_IRAMC_WRAP_APB_WDATA_INJ_BIT_VAL_31    (BIT_(31))
#define BIT_IRAMC_WRAP_APB_WDATA_INJ_BIT_VAL_30    (BIT_(30))
#define BIT_IRAMC_WRAP_APB_WDATA_INJ_BIT_VAL_29    (BIT_(29))
#define BIT_IRAMC_WRAP_APB_WDATA_INJ_BIT_VAL_28    (BIT_(28))
#define BIT_IRAMC_WRAP_APB_WDATA_INJ_BIT_VAL_27    (BIT_(27))
#define BIT_IRAMC_WRAP_APB_WDATA_INJ_BIT_VAL_26    (BIT_(26))
#define BIT_IRAMC_WRAP_APB_WDATA_INJ_BIT_VAL_25    (BIT_(25))
#define BIT_IRAMC_WRAP_APB_WDATA_INJ_BIT_VAL_24    (BIT_(24))
#define BIT_IRAMC_WRAP_APB_WDATA_INJ_BIT_VAL_23    (BIT_(23))
#define BIT_IRAMC_WRAP_APB_WDATA_INJ_BIT_VAL_22    (BIT_(22))
#define BIT_IRAMC_WRAP_APB_WDATA_INJ_BIT_VAL_21    (BIT_(21))
#define BIT_IRAMC_WRAP_APB_WDATA_INJ_BIT_VAL_20    (BIT_(20))
#define BIT_IRAMC_WRAP_APB_WDATA_INJ_BIT_VAL_19    (BIT_(19))
#define BIT_IRAMC_WRAP_APB_WDATA_INJ_BIT_VAL_18    (BIT_(18))
#define BIT_IRAMC_WRAP_APB_WDATA_INJ_BIT_VAL_17    (BIT_(17))
#define BIT_IRAMC_WRAP_APB_WDATA_INJ_BIT_VAL_16    (BIT_(16))
#define BIT_IRAMC_WRAP_APB_WDATA_INJ_BIT_VAL_15    (BIT_(15))
#define BIT_IRAMC_WRAP_APB_WDATA_INJ_BIT_VAL_14    (BIT_(14))
#define BIT_IRAMC_WRAP_APB_WDATA_INJ_BIT_VAL_13    (BIT_(13))
#define BIT_IRAMC_WRAP_APB_WDATA_INJ_BIT_VAL_12    (BIT_(12))
#define BIT_IRAMC_WRAP_APB_WDATA_INJ_BIT_VAL_11    (BIT_(11))
#define BIT_IRAMC_WRAP_APB_WDATA_INJ_BIT_VAL_10    (BIT_(10))
#define BIT_IRAMC_WRAP_APB_WDATA_INJ_BIT_VAL_9    (BIT_(9))
#define BIT_IRAMC_WRAP_APB_WDATA_INJ_BIT_VAL_8    (BIT_(8))
#define BIT_IRAMC_WRAP_APB_WDATA_INJ_BIT_VAL_7    (BIT_(7))
#define BIT_IRAMC_WRAP_APB_WDATA_INJ_BIT_VAL_6    (BIT_(6))
#define BIT_IRAMC_WRAP_APB_WDATA_INJ_BIT_VAL_5    (BIT_(5))
#define BIT_IRAMC_WRAP_APB_WDATA_INJ_BIT_VAL_4    (BIT_(4))
#define BIT_IRAMC_WRAP_APB_WDATA_INJ_BIT_VAL_3    (BIT_(3))
#define BIT_IRAMC_WRAP_APB_WDATA_INJ_BIT_VAL_2    (BIT_(2))
#define BIT_IRAMC_WRAP_APB_WDATA_INJ_BIT_VAL_1    (BIT_(1))
#define BIT_IRAMC_WRAP_APB_WDATA_INJ_BIT_VAL_0    (BIT_(0))

//--------------------------------------------------------------------------
// Register Name   : IRAMC_WRAP_APB_WECC_INJ_BIT
// Register Offset : 0x18
// Description     : apb interface wdata ecc error injection bit
//--------------------------------------------------------------------------
#define IRAMC_WRAP_APB_WECC_INJ_BIT                     0x18U

#define IRAMC_WRAP_APB_WECC_INJ_BIT_VAL_FIELD_OFFSET 0
#define IRAMC_WRAP_APB_WECC_INJ_BIT_VAL_FIELD_SIZE 7

#define BIT_IRAMC_WRAP_APB_WECC_INJ_BIT_VAL_6    (BIT_(6))
#define BIT_IRAMC_WRAP_APB_WECC_INJ_BIT_VAL_5    (BIT_(5))
#define BIT_IRAMC_WRAP_APB_WECC_INJ_BIT_VAL_4    (BIT_(4))
#define BIT_IRAMC_WRAP_APB_WECC_INJ_BIT_VAL_3    (BIT_(3))
#define BIT_IRAMC_WRAP_APB_WECC_INJ_BIT_VAL_2    (BIT_(2))
#define BIT_IRAMC_WRAP_APB_WECC_INJ_BIT_VAL_1    (BIT_(1))
#define BIT_IRAMC_WRAP_APB_WECC_INJ_BIT_VAL_0    (BIT_(0))

//--------------------------------------------------------------------------
// Register Name   : IRAMC_WRAP_IRQ_ERR_INJ
// Register Offset : 0x1c
// Description     : interrupt output error injection
//--------------------------------------------------------------------------
#define IRAMC_WRAP_IRQ_ERR_INJ                      0x1cU

#define IRAMC_WRAP_IRQ_ERR_INJ_INJ_BIT_FIELD_OFFSET 1
#define IRAMC_WRAP_IRQ_ERR_INJ_INJ_BIT_FIELD_SIZE 2

#define IRAMC_WRAP_IRQ_ERR_INJ_ENABLE_FIELD_OFFSET 0
#define IRAMC_WRAP_IRQ_ERR_INJ_ENABLE_FIELD_SIZE 1

#define BIT_IRAMC_WRAP_IRQ_ERR_INJ_INJ_BIT_1    (BIT_(2))
#define BIT_IRAMC_WRAP_IRQ_ERR_INJ_INJ_BIT_0    (BIT_(1))

#define BIT_IRAMC_WRAP_IRQ_ERR_INJ_ENABLE    (BIT_(0))

//--------------------------------------------------------------------------
// Register Name   : IRAMC_WRAP_LSP_CMP_INJ
// Register Offset : 0x20
// Description     : lockstep error injection control
//--------------------------------------------------------------------------
#define IRAMC_WRAP_LSP_CMP_INJ                      0x20U

#define IRAMC_WRAP_LSP_CMP_INJ_ENABLE_FIELD_OFFSET 31
#define IRAMC_WRAP_LSP_CMP_INJ_ENABLE_FIELD_SIZE 1

#define IRAMC_WRAP_LSP_CMP_INJ_INJ_SEL_FIELD_OFFSET 0
#define IRAMC_WRAP_LSP_CMP_INJ_INJ_SEL_FIELD_SIZE 31

#define BIT_IRAMC_WRAP_LSP_CMP_INJ_ENABLE    (BIT_(31))

#define BIT_IRAMC_WRAP_LSP_CMP_INJ_INJ_SEL_30    (BIT_(30))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_INJ_SEL_29    (BIT_(29))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_INJ_SEL_28    (BIT_(28))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_INJ_SEL_27    (BIT_(27))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_INJ_SEL_26    (BIT_(26))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_INJ_SEL_25    (BIT_(25))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_INJ_SEL_24    (BIT_(24))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_INJ_SEL_23    (BIT_(23))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_INJ_SEL_22    (BIT_(22))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_INJ_SEL_21    (BIT_(21))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_INJ_SEL_20    (BIT_(20))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_INJ_SEL_19    (BIT_(19))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_INJ_SEL_18    (BIT_(18))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_INJ_SEL_17    (BIT_(17))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_INJ_SEL_16    (BIT_(16))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_INJ_SEL_15    (BIT_(15))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_INJ_SEL_14    (BIT_(14))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_INJ_SEL_13    (BIT_(13))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_INJ_SEL_12    (BIT_(12))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_INJ_SEL_11    (BIT_(11))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_INJ_SEL_10    (BIT_(10))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_INJ_SEL_9    (BIT_(9))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_INJ_SEL_8    (BIT_(8))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_INJ_SEL_7    (BIT_(7))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_INJ_SEL_6    (BIT_(6))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_INJ_SEL_5    (BIT_(5))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_INJ_SEL_4    (BIT_(4))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_INJ_SEL_3    (BIT_(3))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_INJ_SEL_2    (BIT_(2))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_INJ_SEL_1    (BIT_(1))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_INJ_SEL_0    (BIT_(0))

//--------------------------------------------------------------------------
// Register Name   : IRAMC_WRAP_LSP_CMP_INJ_BIT_0
// Register Offset : 0x24
// Description     : Lockstep compare error injection bit
//--------------------------------------------------------------------------
#define IRAMC_WRAP_LSP_CMP_INJ_BIT_0                   0x24U

#define IRAMC_WRAP_LSP_CMP_INJ_BIT_0_VAL_FIELD_OFFSET 0
#define IRAMC_WRAP_LSP_CMP_INJ_BIT_0_VAL_FIELD_SIZE 32

#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_0_VAL_31    (BIT_(31))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_0_VAL_30    (BIT_(30))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_0_VAL_29    (BIT_(29))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_0_VAL_28    (BIT_(28))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_0_VAL_27    (BIT_(27))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_0_VAL_26    (BIT_(26))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_0_VAL_25    (BIT_(25))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_0_VAL_24    (BIT_(24))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_0_VAL_23    (BIT_(23))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_0_VAL_22    (BIT_(22))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_0_VAL_21    (BIT_(21))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_0_VAL_20    (BIT_(20))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_0_VAL_19    (BIT_(19))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_0_VAL_18    (BIT_(18))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_0_VAL_17    (BIT_(17))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_0_VAL_16    (BIT_(16))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_0_VAL_15    (BIT_(15))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_0_VAL_14    (BIT_(14))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_0_VAL_13    (BIT_(13))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_0_VAL_12    (BIT_(12))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_0_VAL_11    (BIT_(11))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_0_VAL_10    (BIT_(10))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_0_VAL_9    (BIT_(9))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_0_VAL_8    (BIT_(8))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_0_VAL_7    (BIT_(7))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_0_VAL_6    (BIT_(6))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_0_VAL_5    (BIT_(5))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_0_VAL_4    (BIT_(4))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_0_VAL_3    (BIT_(3))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_0_VAL_2    (BIT_(2))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_0_VAL_1    (BIT_(1))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_0_VAL_0    (BIT_(0))

//--------------------------------------------------------------------------
// Register Name   : IRAMC_WRAP_LSP_CMP_INJ_BIT_1
// Register Offset : 0x28
// Description     : Lockstep compare error injection bit
//--------------------------------------------------------------------------
#define IRAMC_WRAP_LSP_CMP_INJ_BIT_1                    0x28U

#define IRAMC_WRAP_LSP_CMP_INJ_BIT_1_VAL_FIELD_OFFSET 0
#define IRAMC_WRAP_LSP_CMP_INJ_BIT_1_VAL_FIELD_SIZE 32


#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_1_VAL_31    (BIT_(31))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_1_VAL_30    (BIT_(30))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_1_VAL_29    (BIT_(29))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_1_VAL_28    (BIT_(28))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_1_VAL_27    (BIT_(27))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_1_VAL_26    (BIT_(26))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_1_VAL_25    (BIT_(25))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_1_VAL_24    (BIT_(24))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_1_VAL_23    (BIT_(23))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_1_VAL_22    (BIT_(22))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_1_VAL_21    (BIT_(21))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_1_VAL_20    (BIT_(20))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_1_VAL_19    (BIT_(19))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_1_VAL_18    (BIT_(18))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_1_VAL_17    (BIT_(17))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_1_VAL_16    (BIT_(16))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_1_VAL_15    (BIT_(15))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_1_VAL_14    (BIT_(14))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_1_VAL_13    (BIT_(13))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_1_VAL_12    (BIT_(12))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_1_VAL_11    (BIT_(11))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_1_VAL_10    (BIT_(10))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_1_VAL_9    (BIT_(9))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_1_VAL_8    (BIT_(8))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_1_VAL_7    (BIT_(7))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_1_VAL_6    (BIT_(6))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_1_VAL_5    (BIT_(5))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_1_VAL_4    (BIT_(4))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_1_VAL_3    (BIT_(3))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_1_VAL_2    (BIT_(2))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_1_VAL_1    (BIT_(1))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_1_VAL_0    (BIT_(0))

//--------------------------------------------------------------------------
// Register Name   : IRAMC_WRAP_LSP_CMP_INJ_BIT_2
// Register Offset : 0x2c
// Description     : Lockstep compare error injection bit
//--------------------------------------------------------------------------
#define IRAMC_WRAP_LSP_CMP_INJ_BIT_2                        0x2cU

#define IRAMC_WRAP_LSP_CMP_INJ_BIT_2_VAL_FIELD_OFFSET 0
#define IRAMC_WRAP_LSP_CMP_INJ_BIT_2_VAL_FIELD_SIZE 32

#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_2_VAL_31    (BIT_(31))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_2_VAL_30    (BIT_(30))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_2_VAL_29    (BIT_(29))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_2_VAL_28    (BIT_(28))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_2_VAL_27    (BIT_(27))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_2_VAL_26    (BIT_(26))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_2_VAL_25    (BIT_(25))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_2_VAL_24    (BIT_(24))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_2_VAL_23    (BIT_(23))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_2_VAL_22    (BIT_(22))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_2_VAL_21    (BIT_(21))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_2_VAL_20    (BIT_(20))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_2_VAL_19    (BIT_(19))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_2_VAL_18    (BIT_(18))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_2_VAL_17    (BIT_(17))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_2_VAL_16    (BIT_(16))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_2_VAL_15    (BIT_(15))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_2_VAL_14    (BIT_(14))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_2_VAL_13    (BIT_(13))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_2_VAL_12    (BIT_(12))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_2_VAL_11    (BIT_(11))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_2_VAL_10    (BIT_(10))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_2_VAL_9    (BIT_(9))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_2_VAL_8    (BIT_(8))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_2_VAL_7    (BIT_(7))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_2_VAL_6    (BIT_(6))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_2_VAL_5    (BIT_(5))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_2_VAL_4    (BIT_(4))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_2_VAL_3    (BIT_(3))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_2_VAL_2    (BIT_(2))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_2_VAL_1    (BIT_(1))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_2_VAL_0    (BIT_(0))

//--------------------------------------------------------------------------
// Register Name   : IRAMC_WRAP_LSP_CMP_INJ_BIT_3
// Register Offset : 0x30
// Description     : Lockstep compare error injection bit
//--------------------------------------------------------------------------
#define IRAMC_WRAP_LSP_CMP_INJ_BIT_3                        0x30U

#define IRAMC_WRAP_LSP_CMP_INJ_BIT_3_VAL_FIELD_OFFSET 0
#define IRAMC_WRAP_LSP_CMP_INJ_BIT_3_VAL_FIELD_SIZE 32


#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_3_VAL_31    (BIT_(31))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_3_VAL_30    (BIT_(30))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_3_VAL_29    (BIT_(29))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_3_VAL_28    (BIT_(28))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_3_VAL_27    (BIT_(27))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_3_VAL_26    (BIT_(26))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_3_VAL_25    (BIT_(25))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_3_VAL_24    (BIT_(24))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_3_VAL_23    (BIT_(23))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_3_VAL_22    (BIT_(22))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_3_VAL_21    (BIT_(21))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_3_VAL_20    (BIT_(20))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_3_VAL_19    (BIT_(19))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_3_VAL_18    (BIT_(18))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_3_VAL_17    (BIT_(17))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_3_VAL_16    (BIT_(16))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_3_VAL_15    (BIT_(15))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_3_VAL_14    (BIT_(14))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_3_VAL_13    (BIT_(13))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_3_VAL_12    (BIT_(12))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_3_VAL_11    (BIT_(11))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_3_VAL_10    (BIT_(10))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_3_VAL_9    (BIT_(9))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_3_VAL_8    (BIT_(8))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_3_VAL_7    (BIT_(7))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_3_VAL_6    (BIT_(6))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_3_VAL_5    (BIT_(5))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_3_VAL_4    (BIT_(4))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_3_VAL_3    (BIT_(3))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_3_VAL_2    (BIT_(2))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_3_VAL_1    (BIT_(1))
#define BIT_IRAMC_WRAP_LSP_CMP_INJ_BIT_3_VAL_0    (BIT_(0))

//--------------------------------------------------------------------------
// Register Name   : IRAMC_WRAP_INT_MASK
// Register Offset : 0xf0
// Description     : interrupt mask
//--------------------------------------------------------------------------
#define IRAMC_WRAP_INT_MASK                             0xf0U

#define IRAMC_WRAP_INT_MASK_VAL_FIELD_OFFSET 0
#define IRAMC_WRAP_INT_MASK_VAL_FIELD_SIZE 32

#define BIT_IRAMC_WRAP_INT_MASK_VAL_31    (BIT_(31))
#define BIT_IRAMC_WRAP_INT_MASK_VAL_30    (BIT_(30))
#define BIT_IRAMC_WRAP_INT_MASK_VAL_29    (BIT_(29))
#define BIT_IRAMC_WRAP_INT_MASK_VAL_28    (BIT_(28))
#define BIT_IRAMC_WRAP_INT_MASK_VAL_27    (BIT_(27))
#define BIT_IRAMC_WRAP_INT_MASK_VAL_26    (BIT_(26))
#define BIT_IRAMC_WRAP_INT_MASK_VAL_25    (BIT_(25))
#define BIT_IRAMC_WRAP_INT_MASK_VAL_24    (BIT_(24))
#define BIT_IRAMC_WRAP_INT_MASK_VAL_23    (BIT_(23))
#define BIT_IRAMC_WRAP_INT_MASK_VAL_22    (BIT_(22))
#define BIT_IRAMC_WRAP_INT_MASK_VAL_21    (BIT_(21))
#define BIT_IRAMC_WRAP_INT_MASK_VAL_20    (BIT_(20))
#define BIT_IRAMC_WRAP_INT_MASK_VAL_19    (BIT_(19))
#define BIT_IRAMC_WRAP_INT_MASK_VAL_18    (BIT_(18))
#define BIT_IRAMC_WRAP_INT_MASK_VAL_17    (BIT_(17))
#define BIT_IRAMC_WRAP_INT_MASK_VAL_16    (BIT_(16))
#define BIT_IRAMC_WRAP_INT_MASK_VAL_15    (BIT_(15))
#define BIT_IRAMC_WRAP_INT_MASK_VAL_14    (BIT_(14))
#define BIT_IRAMC_WRAP_INT_MASK_VAL_13    (BIT_(13))
#define BIT_IRAMC_WRAP_INT_MASK_VAL_12    (BIT_(12))
#define BIT_IRAMC_WRAP_INT_MASK_VAL_11    (BIT_(11))
#define BIT_IRAMC_WRAP_INT_MASK_VAL_10    (BIT_(10))
#define BIT_IRAMC_WRAP_INT_MASK_VAL_9    (BIT_(9))
#define BIT_IRAMC_WRAP_INT_MASK_VAL_8    (BIT_(8))
#define BIT_IRAMC_WRAP_INT_MASK_VAL_7    (BIT_(7))
#define BIT_IRAMC_WRAP_INT_MASK_VAL_6    (BIT_(6))
#define BIT_IRAMC_WRAP_INT_MASK_VAL_5    (BIT_(5))
#define BIT_IRAMC_WRAP_INT_MASK_VAL_4    (BIT_(4))
#define BIT_IRAMC_WRAP_INT_MASK_VAL_3    (BIT_(3))
#define BIT_IRAMC_WRAP_INT_MASK_VAL_2    (BIT_(2))
#define BIT_IRAMC_WRAP_INT_MASK_VAL_1    (BIT_(1))
#define BIT_IRAMC_WRAP_INT_MASK_VAL_0    (BIT_(0))

//--------------------------------------------------------------------------
// Register Name   : IRAMC_WRAP_INT_CLR
// Register Offset : 0xf4
// Description     : interrupt clear
//--------------------------------------------------------------------------
#define IRAMC_WRAP_INT_CLR                      0xf4U

#define IRAMC_WRAP_INT_CLR_VAL_FIELD_OFFSET 0
#define IRAMC_WRAP_INT_CLR_VAL_FIELD_SIZE 32


#define BIT_IRAMC_WRAP_INT_CLR_VAL_31    (BIT_(31))
#define BIT_IRAMC_WRAP_INT_CLR_VAL_30    (BIT_(30))
#define BIT_IRAMC_WRAP_INT_CLR_VAL_29    (BIT_(29))
#define BIT_IRAMC_WRAP_INT_CLR_VAL_28    (BIT_(28))
#define BIT_IRAMC_WRAP_INT_CLR_VAL_27    (BIT_(27))
#define BIT_IRAMC_WRAP_INT_CLR_VAL_26    (BIT_(26))
#define BIT_IRAMC_WRAP_INT_CLR_VAL_25    (BIT_(25))
#define BIT_IRAMC_WRAP_INT_CLR_VAL_24    (BIT_(24))
#define BIT_IRAMC_WRAP_INT_CLR_VAL_23    (BIT_(23))
#define BIT_IRAMC_WRAP_INT_CLR_VAL_22    (BIT_(22))
#define BIT_IRAMC_WRAP_INT_CLR_VAL_21    (BIT_(21))
#define BIT_IRAMC_WRAP_INT_CLR_VAL_20    (BIT_(20))
#define BIT_IRAMC_WRAP_INT_CLR_VAL_19    (BIT_(19))
#define BIT_IRAMC_WRAP_INT_CLR_VAL_18    (BIT_(18))
#define BIT_IRAMC_WRAP_INT_CLR_VAL_17    (BIT_(17))
#define BIT_IRAMC_WRAP_INT_CLR_VAL_16    (BIT_(16))
#define BIT_IRAMC_WRAP_INT_CLR_VAL_15    (BIT_(15))
#define BIT_IRAMC_WRAP_INT_CLR_VAL_14    (BIT_(14))
#define BIT_IRAMC_WRAP_INT_CLR_VAL_13    (BIT_(13))
#define BIT_IRAMC_WRAP_INT_CLR_VAL_12    (BIT_(12))
#define BIT_IRAMC_WRAP_INT_CLR_VAL_11    (BIT_(11))
#define BIT_IRAMC_WRAP_INT_CLR_VAL_10    (BIT_(10))
#define BIT_IRAMC_WRAP_INT_CLR_VAL_9    (BIT_(9))
#define BIT_IRAMC_WRAP_INT_CLR_VAL_8    (BIT_(8))
#define BIT_IRAMC_WRAP_INT_CLR_VAL_7    (BIT_(7))
#define BIT_IRAMC_WRAP_INT_CLR_VAL_6    (BIT_(6))
#define BIT_IRAMC_WRAP_INT_CLR_VAL_5    (BIT_(5))
#define BIT_IRAMC_WRAP_INT_CLR_VAL_4    (BIT_(4))
#define BIT_IRAMC_WRAP_INT_CLR_VAL_3    (BIT_(3))
#define BIT_IRAMC_WRAP_INT_CLR_VAL_2    (BIT_(2))
#define BIT_IRAMC_WRAP_INT_CLR_VAL_1    (BIT_(1))
#define BIT_IRAMC_WRAP_INT_CLR_VAL_0    (BIT_(0))

//--------------------------------------------------------------------------
// Register Name   : IRAMC_WRAP_INT_RAW
// Register Offset : 0xf8
// Description     : interrupt raw status
//--------------------------------------------------------------------------
#define IRAMC_WRAP_INT_RAW                          0xf8U

#define IRAMC_WRAP_INT_RAW_VAL_FIELD_OFFSET 0
#define IRAMC_WRAP_INT_RAW_VAL_FIELD_SIZE 32


#define BIT_IRAMC_WRAP_INT_RAW_VAL_31    (BIT_(31))
#define BIT_IRAMC_WRAP_INT_RAW_VAL_30    (BIT_(30))
#define BIT_IRAMC_WRAP_INT_RAW_VAL_29    (BIT_(29))
#define BIT_IRAMC_WRAP_INT_RAW_VAL_28    (BIT_(28))
#define BIT_IRAMC_WRAP_INT_RAW_VAL_27    (BIT_(27))
#define BIT_IRAMC_WRAP_INT_RAW_VAL_26    (BIT_(26))
#define BIT_IRAMC_WRAP_INT_RAW_VAL_25    (BIT_(25))
#define BIT_IRAMC_WRAP_INT_RAW_VAL_24    (BIT_(24))
#define BIT_IRAMC_WRAP_INT_RAW_VAL_23    (BIT_(23))
#define BIT_IRAMC_WRAP_INT_RAW_VAL_22    (BIT_(22))
#define BIT_IRAMC_WRAP_INT_RAW_VAL_21    (BIT_(21))
#define BIT_IRAMC_WRAP_INT_RAW_VAL_20    (BIT_(20))
#define BIT_IRAMC_WRAP_INT_RAW_VAL_19    (BIT_(19))
#define BIT_IRAMC_WRAP_INT_RAW_VAL_18    (BIT_(18))
#define BIT_IRAMC_WRAP_INT_RAW_VAL_17    (BIT_(17))
#define BIT_IRAMC_WRAP_INT_RAW_VAL_16    (BIT_(16))
#define BIT_IRAMC_WRAP_INT_RAW_VAL_15    (BIT_(15))
#define BIT_IRAMC_WRAP_INT_RAW_VAL_14    (BIT_(14))
#define BIT_IRAMC_WRAP_INT_RAW_VAL_13    (BIT_(13))
#define BIT_IRAMC_WRAP_INT_RAW_VAL_12    (BIT_(12))
#define BIT_IRAMC_WRAP_INT_RAW_VAL_11    (BIT_(11))
#define BIT_IRAMC_WRAP_INT_RAW_VAL_10    (BIT_(10))
#define BIT_IRAMC_WRAP_INT_RAW_VAL_9    (BIT_(9))
#define BIT_IRAMC_WRAP_INT_RAW_VAL_8    (BIT_(8))
#define BIT_IRAMC_WRAP_INT_RAW_VAL_7    (BIT_(7))
#define BIT_IRAMC_WRAP_INT_RAW_VAL_6    (BIT_(6))
#define BIT_IRAMC_WRAP_INT_RAW_VAL_5    (BIT_(5))
#define BIT_IRAMC_WRAP_INT_RAW_VAL_4    (BIT_(4))
#define BIT_IRAMC_WRAP_INT_RAW_VAL_3    (BIT_(3))
#define BIT_IRAMC_WRAP_INT_RAW_VAL_2    (BIT_(2))
#define BIT_IRAMC_WRAP_INT_RAW_VAL_1    (BIT_(1))
#define BIT_IRAMC_WRAP_INT_RAW_VAL_0    (BIT_(0))

//--------------------------------------------------------------------------
// Register Name   : IRAMC_WRAP_INT_STA
// Register Offset : 0xfc
// Description     : interrupt status
//--------------------------------------------------------------------------
#define IRAMC_WRAP_INT_STA                          0xfcU

#define IRAMC_WRAP_INT_STA_VAL_FIELD_OFFSET 0
#define IRAMC_WRAP_INT_STA_VAL_FIELD_SIZE 32


#define BIT_IRAMC_WRAP_INT_STA_VAL_31    (BIT_(31))
#define BIT_IRAMC_WRAP_INT_STA_VAL_30    (BIT_(30))
#define BIT_IRAMC_WRAP_INT_STA_VAL_29    (BIT_(29))
#define BIT_IRAMC_WRAP_INT_STA_VAL_28    (BIT_(28))
#define BIT_IRAMC_WRAP_INT_STA_VAL_27    (BIT_(27))
#define BIT_IRAMC_WRAP_INT_STA_VAL_26    (BIT_(26))
#define BIT_IRAMC_WRAP_INT_STA_VAL_25    (BIT_(25))
#define BIT_IRAMC_WRAP_INT_STA_VAL_24    (BIT_(24))
#define BIT_IRAMC_WRAP_INT_STA_VAL_23    (BIT_(23))
#define BIT_IRAMC_WRAP_INT_STA_VAL_22    (BIT_(22))
#define BIT_IRAMC_WRAP_INT_STA_VAL_21    (BIT_(21))
#define BIT_IRAMC_WRAP_INT_STA_VAL_20    (BIT_(20))
#define BIT_IRAMC_WRAP_INT_STA_VAL_19    (BIT_(19))
#define BIT_IRAMC_WRAP_INT_STA_VAL_18    (BIT_(18))
#define BIT_IRAMC_WRAP_INT_STA_VAL_17    (BIT_(17))
#define BIT_IRAMC_WRAP_INT_STA_VAL_16    (BIT_(16))
#define BIT_IRAMC_WRAP_INT_STA_VAL_15    (BIT_(15))
#define BIT_IRAMC_WRAP_INT_STA_VAL_14    (BIT_(14))
#define BIT_IRAMC_WRAP_INT_STA_VAL_13    (BIT_(13))
#define BIT_IRAMC_WRAP_INT_STA_VAL_12    (BIT_(12))
#define BIT_IRAMC_WRAP_INT_STA_VAL_11    (BIT_(11))
#define BIT_IRAMC_WRAP_INT_STA_VAL_10    (BIT_(10))
#define BIT_IRAMC_WRAP_INT_STA_VAL_9    (BIT_(9))
#define BIT_IRAMC_WRAP_INT_STA_VAL_8    (BIT_(8))
#define BIT_IRAMC_WRAP_INT_STA_VAL_7    (BIT_(7))
#define BIT_IRAMC_WRAP_INT_STA_VAL_6    (BIT_(6))
#define BIT_IRAMC_WRAP_INT_STA_VAL_5    (BIT_(5))
#define BIT_IRAMC_WRAP_INT_STA_VAL_4    (BIT_(4))
#define BIT_IRAMC_WRAP_INT_STA_VAL_3    (BIT_(3))
#define BIT_IRAMC_WRAP_INT_STA_VAL_2    (BIT_(2))
#define BIT_IRAMC_WRAP_INT_STA_VAL_1    (BIT_(1))
#define BIT_IRAMC_WRAP_INT_STA_VAL_0    (BIT_(0))

//--------------------------------------------------------------------------
// Register Name   : IRAMC_WRAP_BIST_CONFIG0
// Register Offset : 0x100
// Description     : bist configuration for memory
//--------------------------------------------------------------------------
#define IRAMC_WRAP_BIST_CONFIG0                         0x100U

#define IRAMC_WRAP_BIST_CONFIG0_STOP_FIELD_OFFSET 31
#define IRAMC_WRAP_BIST_CONFIG0_STOP_FIELD_SIZE 1

#define IRAMC_WRAP_BIST_CONFIG0_START_FIELD_OFFSET 30
#define IRAMC_WRAP_BIST_CONFIG0_START_FIELD_SIZE 1

#define IRAMC_WRAP_BIST_CONFIG0_MODE_FIELD_OFFSET 29
#define IRAMC_WRAP_BIST_CONFIG0_MODE_FIELD_SIZE 1

#define IRAMC_WRAP_BIST_CONFIG0_BIST_BURST_FIELD_OFFSET 24
#define IRAMC_WRAP_BIST_CONFIG0_BIST_BURST_FIELD_SIZE 4

#define IRAMC_WRAP_BIST_CONFIG0_BIST_RCL_FIELD_OFFSET 20
#define IRAMC_WRAP_BIST_CONFIG0_BIST_RCL_FIELD_SIZE 4

#define IRAMC_WRAP_BIST_CONFIG0_INTERVAL_FIELD_OFFSET 0
#define IRAMC_WRAP_BIST_CONFIG0_INTERVAL_FIELD_SIZE 20


#define BIT_IRAMC_WRAP_BIST_CONFIG0_STOP    (BIT_(31))

#define BIT_IRAMC_WRAP_BIST_CONFIG0_START    (BIT_(30))

#define BIT_IRAMC_WRAP_BIST_CONFIG0_MODE    (BIT_(29))

#define BIT_IRAMC_WRAP_BIST_CONFIG0_BIST_BURST_3    (BIT_(27))
#define BIT_IRAMC_WRAP_BIST_CONFIG0_BIST_BURST_2    (BIT_(26))
#define BIT_IRAMC_WRAP_BIST_CONFIG0_BIST_BURST_1    (BIT_(25))
#define BIT_IRAMC_WRAP_BIST_CONFIG0_BIST_BURST_0    (BIT_(24))

#define BIT_IRAMC_WRAP_BIST_CONFIG0_BIST_RCL_3    (BIT_(23))
#define BIT_IRAMC_WRAP_BIST_CONFIG0_BIST_RCL_2    (BIT_(22))
#define BIT_IRAMC_WRAP_BIST_CONFIG0_BIST_RCL_1    (BIT_(21))
#define BIT_IRAMC_WRAP_BIST_CONFIG0_BIST_RCL_0    (BIT_(20))

#define BIT_IRAMC_WRAP_BIST_CONFIG0_INTERVAL_19    (BIT_(19))
#define BIT_IRAMC_WRAP_BIST_CONFIG0_INTERVAL_18    (BIT_(18))
#define BIT_IRAMC_WRAP_BIST_CONFIG0_INTERVAL_17    (BIT_(17))
#define BIT_IRAMC_WRAP_BIST_CONFIG0_INTERVAL_16    (BIT_(16))
#define BIT_IRAMC_WRAP_BIST_CONFIG0_INTERVAL_15    (BIT_(15))
#define BIT_IRAMC_WRAP_BIST_CONFIG0_INTERVAL_14    (BIT_(14))
#define BIT_IRAMC_WRAP_BIST_CONFIG0_INTERVAL_13    (BIT_(13))
#define BIT_IRAMC_WRAP_BIST_CONFIG0_INTERVAL_12    (BIT_(12))
#define BIT_IRAMC_WRAP_BIST_CONFIG0_INTERVAL_11    (BIT_(11))
#define BIT_IRAMC_WRAP_BIST_CONFIG0_INTERVAL_10    (BIT_(10))
#define BIT_IRAMC_WRAP_BIST_CONFIG0_INTERVAL_9    (BIT_(9))
#define BIT_IRAMC_WRAP_BIST_CONFIG0_INTERVAL_8    (BIT_(8))
#define BIT_IRAMC_WRAP_BIST_CONFIG0_INTERVAL_7    (BIT_(7))
#define BIT_IRAMC_WRAP_BIST_CONFIG0_INTERVAL_6    (BIT_(6))
#define BIT_IRAMC_WRAP_BIST_CONFIG0_INTERVAL_5    (BIT_(5))
#define BIT_IRAMC_WRAP_BIST_CONFIG0_INTERVAL_4    (BIT_(4))
#define BIT_IRAMC_WRAP_BIST_CONFIG0_INTERVAL_3    (BIT_(3))
#define BIT_IRAMC_WRAP_BIST_CONFIG0_INTERVAL_2    (BIT_(2))
#define BIT_IRAMC_WRAP_BIST_CONFIG0_INTERVAL_1    (BIT_(1))
#define BIT_IRAMC_WRAP_BIST_CONFIG0_INTERVAL_0    (BIT_(0))

//--------------------------------------------------------------------------
// Register Name   : IRAMC_WRAP_BIST_CONFIG1
// Register Offset : 0x104
// Description     : bist enable and lock
//--------------------------------------------------------------------------
#define IRAMC_WRAP_BIST_CONFIG1                             0x104U

#define IRAMC_WRAP_BIST_CONFIG1_INVASIVE_LOCK_FIELD_OFFSET 17
#define IRAMC_WRAP_BIST_CONFIG1_INVASIVE_LOCK_FIELD_SIZE 1

#define IRAMC_WRAP_BIST_CONFIG1_ENABLE_LOCK_FIELD_OFFSET 16
#define IRAMC_WRAP_BIST_CONFIG1_ENABLE_LOCK_FIELD_SIZE 1

#define IRAMC_WRAP_BIST_CONFIG1_INVASIVE_FIELD_OFFSET 1
#define IRAMC_WRAP_BIST_CONFIG1_INVASIVE_FIELD_SIZE 1

#define IRAMC_WRAP_BIST_CONFIG1_ENABLE_FIELD_OFFSET 0
#define IRAMC_WRAP_BIST_CONFIG1_ENABLE_FIELD_SIZE 1


#define BIT_IRAMC_WRAP_BIST_CONFIG1_INVASIVE_LOCK    (BIT_(17))

#define BIT_IRAMC_WRAP_BIST_CONFIG1_ENABLE_LOCK    (BIT_(16))

#define BIT_IRAMC_WRAP_BIST_CONFIG1_INVASIVE    (BIT_(1))

#define BIT_IRAMC_WRAP_BIST_CONFIG1_ENABLE    (BIT_(0))

//--------------------------------------------------------------------------
// Register Name   : IRAMC_WRAP_BIST_STA_SEL
// Register Offset : 0x108
// Description     : bist result report mux
//--------------------------------------------------------------------------
#define IRAMC_WRAP_BIST_STA_SEL (                       0x108U

#define IRAMC_WRAP_BIST_STA_SEL_VAL_FIELD_OFFSET 0
#define IRAMC_WRAP_BIST_STA_SEL_VAL_FIELD_SIZE 32


#define BIT_IRAMC_WRAP_BIST_STA_SEL_VAL_31    (BIT_(31))
#define BIT_IRAMC_WRAP_BIST_STA_SEL_VAL_30    (BIT_(30))
#define BIT_IRAMC_WRAP_BIST_STA_SEL_VAL_29    (BIT_(29))
#define BIT_IRAMC_WRAP_BIST_STA_SEL_VAL_28    (BIT_(28))
#define BIT_IRAMC_WRAP_BIST_STA_SEL_VAL_27    (BIT_(27))
#define BIT_IRAMC_WRAP_BIST_STA_SEL_VAL_26    (BIT_(26))
#define BIT_IRAMC_WRAP_BIST_STA_SEL_VAL_25    (BIT_(25))
#define BIT_IRAMC_WRAP_BIST_STA_SEL_VAL_24    (BIT_(24))
#define BIT_IRAMC_WRAP_BIST_STA_SEL_VAL_23    (BIT_(23))
#define BIT_IRAMC_WRAP_BIST_STA_SEL_VAL_22    (BIT_(22))
#define BIT_IRAMC_WRAP_BIST_STA_SEL_VAL_21    (BIT_(21))
#define BIT_IRAMC_WRAP_BIST_STA_SEL_VAL_20    (BIT_(20))
#define BIT_IRAMC_WRAP_BIST_STA_SEL_VAL_19    (BIT_(19))
#define BIT_IRAMC_WRAP_BIST_STA_SEL_VAL_18    (BIT_(18))
#define BIT_IRAMC_WRAP_BIST_STA_SEL_VAL_17    (BIT_(17))
#define BIT_IRAMC_WRAP_BIST_STA_SEL_VAL_16    (BIT_(16))
#define BIT_IRAMC_WRAP_BIST_STA_SEL_VAL_15    (BIT_(15))
#define BIT_IRAMC_WRAP_BIST_STA_SEL_VAL_14    (BIT_(14))
#define BIT_IRAMC_WRAP_BIST_STA_SEL_VAL_13    (BIT_(13))
#define BIT_IRAMC_WRAP_BIST_STA_SEL_VAL_12    (BIT_(12))
#define BIT_IRAMC_WRAP_BIST_STA_SEL_VAL_11    (BIT_(11))
#define BIT_IRAMC_WRAP_BIST_STA_SEL_VAL_10    (BIT_(10))
#define BIT_IRAMC_WRAP_BIST_STA_SEL_VAL_9    (BIT_(9))
#define BIT_IRAMC_WRAP_BIST_STA_SEL_VAL_8    (BIT_(8))
#define BIT_IRAMC_WRAP_BIST_STA_SEL_VAL_7    (BIT_(7))
#define BIT_IRAMC_WRAP_BIST_STA_SEL_VAL_6    (BIT_(6))
#define BIT_IRAMC_WRAP_BIST_STA_SEL_VAL_5    (BIT_(5))
#define BIT_IRAMC_WRAP_BIST_STA_SEL_VAL_4    (BIT_(4))
#define BIT_IRAMC_WRAP_BIST_STA_SEL_VAL_3    (BIT_(3))
#define BIT_IRAMC_WRAP_BIST_STA_SEL_VAL_2    (BIT_(2))
#define BIT_IRAMC_WRAP_BIST_STA_SEL_VAL_1    (BIT_(1))
#define BIT_IRAMC_WRAP_BIST_STA_SEL_VAL_0    (BIT_(0))

//--------------------------------------------------------------------------
// Register Name   : IRAMC_WRAP_BIST_STA0
// Register Offset : 0x150
// Description     : bist result report
//--------------------------------------------------------------------------
#define IRAMC_WRAP_BIST_STA0                        0x150U

#define IRAMC_WRAP_BIST_STA0_VAL_FIELD_OFFSET 0
#define IRAMC_WRAP_BIST_STA0_VAL_FIELD_SIZE 32


#define BIT_IRAMC_WRAP_BIST_STA0_VAL_31    (BIT_(31))
#define BIT_IRAMC_WRAP_BIST_STA0_VAL_30    (BIT_(30))
#define BIT_IRAMC_WRAP_BIST_STA0_VAL_29    (BIT_(29))
#define BIT_IRAMC_WRAP_BIST_STA0_VAL_28    (BIT_(28))
#define BIT_IRAMC_WRAP_BIST_STA0_VAL_27    (BIT_(27))
#define BIT_IRAMC_WRAP_BIST_STA0_VAL_26    (BIT_(26))
#define BIT_IRAMC_WRAP_BIST_STA0_VAL_25    (BIT_(25))
#define BIT_IRAMC_WRAP_BIST_STA0_VAL_24    (BIT_(24))
#define BIT_IRAMC_WRAP_BIST_STA0_VAL_23    (BIT_(23))
#define BIT_IRAMC_WRAP_BIST_STA0_VAL_22    (BIT_(22))
#define BIT_IRAMC_WRAP_BIST_STA0_VAL_21    (BIT_(21))
#define BIT_IRAMC_WRAP_BIST_STA0_VAL_20    (BIT_(20))
#define BIT_IRAMC_WRAP_BIST_STA0_VAL_19    (BIT_(19))
#define BIT_IRAMC_WRAP_BIST_STA0_VAL_18    (BIT_(18))
#define BIT_IRAMC_WRAP_BIST_STA0_VAL_17    (BIT_(17))
#define BIT_IRAMC_WRAP_BIST_STA0_VAL_16    (BIT_(16))
#define BIT_IRAMC_WRAP_BIST_STA0_VAL_15    (BIT_(15))
#define BIT_IRAMC_WRAP_BIST_STA0_VAL_14    (BIT_(14))
#define BIT_IRAMC_WRAP_BIST_STA0_VAL_13    (BIT_(13))
#define BIT_IRAMC_WRAP_BIST_STA0_VAL_12    (BIT_(12))
#define BIT_IRAMC_WRAP_BIST_STA0_VAL_11    (BIT_(11))
#define BIT_IRAMC_WRAP_BIST_STA0_VAL_10    (BIT_(10))
#define BIT_IRAMC_WRAP_BIST_STA0_VAL_9    (BIT_(9))
#define BIT_IRAMC_WRAP_BIST_STA0_VAL_8    (BIT_(8))
#define BIT_IRAMC_WRAP_BIST_STA0_VAL_7    (BIT_(7))
#define BIT_IRAMC_WRAP_BIST_STA0_VAL_6    (BIT_(6))
#define BIT_IRAMC_WRAP_BIST_STA0_VAL_5    (BIT_(5))
#define BIT_IRAMC_WRAP_BIST_STA0_VAL_4    (BIT_(4))
#define BIT_IRAMC_WRAP_BIST_STA0_VAL_3    (BIT_(3))
#define BIT_IRAMC_WRAP_BIST_STA0_VAL_2    (BIT_(2))
#define BIT_IRAMC_WRAP_BIST_STA0_VAL_1    (BIT_(1))
#define BIT_IRAMC_WRAP_BIST_STA0_VAL_0    (BIT_(0))

//--------------------------------------------------------------------------
// Register Name   : IRAMC_WRAP_BIST_STA1
// Register Offset : 0x154
// Description     : bist result report
//--------------------------------------------------------------------------
#define IRAMC_WRAP_BIST_STA1                            0x154U

#define IRAMC_WRAP_BIST_STA1_VAL_FIELD_OFFSET 0
#define IRAMC_WRAP_BIST_STA1_VAL_FIELD_SIZE 32


#define BIT_IRAMC_WRAP_BIST_STA1_VAL_31    (BIT_(31))
#define BIT_IRAMC_WRAP_BIST_STA1_VAL_30    (BIT_(30))
#define BIT_IRAMC_WRAP_BIST_STA1_VAL_29    (BIT_(29))
#define BIT_IRAMC_WRAP_BIST_STA1_VAL_28    (BIT_(28))
#define BIT_IRAMC_WRAP_BIST_STA1_VAL_27    (BIT_(27))
#define BIT_IRAMC_WRAP_BIST_STA1_VAL_26    (BIT_(26))
#define BIT_IRAMC_WRAP_BIST_STA1_VAL_25    (BIT_(25))
#define BIT_IRAMC_WRAP_BIST_STA1_VAL_24    (BIT_(24))
#define BIT_IRAMC_WRAP_BIST_STA1_VAL_23    (BIT_(23))
#define BIT_IRAMC_WRAP_BIST_STA1_VAL_22    (BIT_(22))
#define BIT_IRAMC_WRAP_BIST_STA1_VAL_21    (BIT_(21))
#define BIT_IRAMC_WRAP_BIST_STA1_VAL_20    (BIT_(20))
#define BIT_IRAMC_WRAP_BIST_STA1_VAL_19    (BIT_(19))
#define BIT_IRAMC_WRAP_BIST_STA1_VAL_18    (BIT_(18))
#define BIT_IRAMC_WRAP_BIST_STA1_VAL_17    (BIT_(17))
#define BIT_IRAMC_WRAP_BIST_STA1_VAL_16    (BIT_(16))
#define BIT_IRAMC_WRAP_BIST_STA1_VAL_15    (BIT_(15))
#define BIT_IRAMC_WRAP_BIST_STA1_VAL_14    (BIT_(14))
#define BIT_IRAMC_WRAP_BIST_STA1_VAL_13    (BIT_(13))
#define BIT_IRAMC_WRAP_BIST_STA1_VAL_12    (BIT_(12))
#define BIT_IRAMC_WRAP_BIST_STA1_VAL_11    (BIT_(11))
#define BIT_IRAMC_WRAP_BIST_STA1_VAL_10    (BIT_(10))
#define BIT_IRAMC_WRAP_BIST_STA1_VAL_9    (BIT_(9))
#define BIT_IRAMC_WRAP_BIST_STA1_VAL_8    (BIT_(8))
#define BIT_IRAMC_WRAP_BIST_STA1_VAL_7    (BIT_(7))
#define BIT_IRAMC_WRAP_BIST_STA1_VAL_6    (BIT_(6))
#define BIT_IRAMC_WRAP_BIST_STA1_VAL_5    (BIT_(5))
#define BIT_IRAMC_WRAP_BIST_STA1_VAL_4    (BIT_(4))
#define BIT_IRAMC_WRAP_BIST_STA1_VAL_3    (BIT_(3))
#define BIT_IRAMC_WRAP_BIST_STA1_VAL_2    (BIT_(2))
#define BIT_IRAMC_WRAP_BIST_STA1_VAL_1    (BIT_(1))
#define BIT_IRAMC_WRAP_BIST_STA1_VAL_0    (BIT_(0))

//--------------------------------------------------------------------------
// Register Name   : IRAMC_WRAP_BIST_STA2
// Register Offset : 0x158
// Description     : bist result report
//--------------------------------------------------------------------------
#define IRAMC_WRAP_BIST_STA2                        0x158U

#define IRAMC_WRAP_BIST_STA2_VAL_FIELD_OFFSET 0
#define IRAMC_WRAP_BIST_STA2_VAL_FIELD_SIZE 32


#define BIT_IRAMC_WRAP_BIST_STA2_VAL_31    (BIT_(31))
#define BIT_IRAMC_WRAP_BIST_STA2_VAL_30    (BIT_(30))
#define BIT_IRAMC_WRAP_BIST_STA2_VAL_29    (BIT_(29))
#define BIT_IRAMC_WRAP_BIST_STA2_VAL_28    (BIT_(28))
#define BIT_IRAMC_WRAP_BIST_STA2_VAL_27    (BIT_(27))
#define BIT_IRAMC_WRAP_BIST_STA2_VAL_26    (BIT_(26))
#define BIT_IRAMC_WRAP_BIST_STA2_VAL_25    (BIT_(25))
#define BIT_IRAMC_WRAP_BIST_STA2_VAL_24    (BIT_(24))
#define BIT_IRAMC_WRAP_BIST_STA2_VAL_23    (BIT_(23))
#define BIT_IRAMC_WRAP_BIST_STA2_VAL_22    (BIT_(22))
#define BIT_IRAMC_WRAP_BIST_STA2_VAL_21    (BIT_(21))
#define BIT_IRAMC_WRAP_BIST_STA2_VAL_20    (BIT_(20))
#define BIT_IRAMC_WRAP_BIST_STA2_VAL_19    (BIT_(19))
#define BIT_IRAMC_WRAP_BIST_STA2_VAL_18    (BIT_(18))
#define BIT_IRAMC_WRAP_BIST_STA2_VAL_17    (BIT_(17))
#define BIT_IRAMC_WRAP_BIST_STA2_VAL_16    (BIT_(16))
#define BIT_IRAMC_WRAP_BIST_STA2_VAL_15    (BIT_(15))
#define BIT_IRAMC_WRAP_BIST_STA2_VAL_14    (BIT_(14))
#define BIT_IRAMC_WRAP_BIST_STA2_VAL_13    (BIT_(13))
#define BIT_IRAMC_WRAP_BIST_STA2_VAL_12    (BIT_(12))
#define BIT_IRAMC_WRAP_BIST_STA2_VAL_11    (BIT_(11))
#define BIT_IRAMC_WRAP_BIST_STA2_VAL_10    (BIT_(10))
#define BIT_IRAMC_WRAP_BIST_STA2_VAL_9    (BIT_(9))
#define BIT_IRAMC_WRAP_BIST_STA2_VAL_8    (BIT_(8))
#define BIT_IRAMC_WRAP_BIST_STA2_VAL_7    (BIT_(7))
#define BIT_IRAMC_WRAP_BIST_STA2_VAL_6    (BIT_(6))
#define BIT_IRAMC_WRAP_BIST_STA2_VAL_5    (BIT_(5))
#define BIT_IRAMC_WRAP_BIST_STA2_VAL_4    (BIT_(4))
#define BIT_IRAMC_WRAP_BIST_STA2_VAL_3    (BIT_(3))
#define BIT_IRAMC_WRAP_BIST_STA2_VAL_2    (BIT_(2))
#define BIT_IRAMC_WRAP_BIST_STA2_VAL_1    (BIT_(1))
#define BIT_IRAMC_WRAP_BIST_STA2_VAL_0    (BIT_(0))

//--------------------------------------------------------------------------
// Register Name   : IRAMC_WRAP_BIST_STA3
// Register Offset : 0x15c
// Description     : bist result report
//--------------------------------------------------------------------------
#define IRAMC_WRAP_BIST_STA3                            0x15cU

#define IRAMC_WRAP_BIST_STA3_VAL_FIELD_OFFSET 0
#define IRAMC_WRAP_BIST_STA3_VAL_FIELD_SIZE 32


#define BIT_IRAMC_WRAP_BIST_STA3_VAL_31    (BIT_(31))
#define BIT_IRAMC_WRAP_BIST_STA3_VAL_30    (BIT_(30))
#define BIT_IRAMC_WRAP_BIST_STA3_VAL_29    (BIT_(29))
#define BIT_IRAMC_WRAP_BIST_STA3_VAL_28    (BIT_(28))
#define BIT_IRAMC_WRAP_BIST_STA3_VAL_27    (BIT_(27))
#define BIT_IRAMC_WRAP_BIST_STA3_VAL_26    (BIT_(26))
#define BIT_IRAMC_WRAP_BIST_STA3_VAL_25    (BIT_(25))
#define BIT_IRAMC_WRAP_BIST_STA3_VAL_24    (BIT_(24))
#define BIT_IRAMC_WRAP_BIST_STA3_VAL_23    (BIT_(23))
#define BIT_IRAMC_WRAP_BIST_STA3_VAL_22    (BIT_(22))
#define BIT_IRAMC_WRAP_BIST_STA3_VAL_21    (BIT_(21))
#define BIT_IRAMC_WRAP_BIST_STA3_VAL_20    (BIT_(20))
#define BIT_IRAMC_WRAP_BIST_STA3_VAL_19    (BIT_(19))
#define BIT_IRAMC_WRAP_BIST_STA3_VAL_18    (BIT_(18))
#define BIT_IRAMC_WRAP_BIST_STA3_VAL_17    (BIT_(17))
#define BIT_IRAMC_WRAP_BIST_STA3_VAL_16    (BIT_(16))
#define BIT_IRAMC_WRAP_BIST_STA3_VAL_15    (BIT_(15))
#define BIT_IRAMC_WRAP_BIST_STA3_VAL_14    (BIT_(14))
#define BIT_IRAMC_WRAP_BIST_STA3_VAL_13    (BIT_(13))
#define BIT_IRAMC_WRAP_BIST_STA3_VAL_12    (BIT_(12))
#define BIT_IRAMC_WRAP_BIST_STA3_VAL_11    (BIT_(11))
#define BIT_IRAMC_WRAP_BIST_STA3_VAL_10    (BIT_(10))
#define BIT_IRAMC_WRAP_BIST_STA3_VAL_9    (BIT_(9))
#define BIT_IRAMC_WRAP_BIST_STA3_VAL_8    (BIT_(8))
#define BIT_IRAMC_WRAP_BIST_STA3_VAL_7    (BIT_(7))
#define BIT_IRAMC_WRAP_BIST_STA3_VAL_6    (BIT_(6))
#define BIT_IRAMC_WRAP_BIST_STA3_VAL_5    (BIT_(5))
#define BIT_IRAMC_WRAP_BIST_STA3_VAL_4    (BIT_(4))
#define BIT_IRAMC_WRAP_BIST_STA3_VAL_3    (BIT_(3))
#define BIT_IRAMC_WRAP_BIST_STA3_VAL_2    (BIT_(2))
#define BIT_IRAMC_WRAP_BIST_STA3_VAL_1    (BIT_(1))
#define BIT_IRAMC_WRAP_BIST_STA3_VAL_0    (BIT_(0))

//--------------------------------------------------------------------------
// Register Name   : IRAMC_WRAP_BIST_STA4
// Register Offset : 0x160
// Description     : bist result report
//--------------------------------------------------------------------------
#define IRAMC_WRAP_BIST_STA4                        0x160U

#define IRAMC_WRAP_BIST_STA4_VAL_FIELD_OFFSET 0
#define IRAMC_WRAP_BIST_STA4_VAL_FIELD_SIZE 32


#define BIT_IRAMC_WRAP_BIST_STA4_VAL_31    (BIT_(31))
#define BIT_IRAMC_WRAP_BIST_STA4_VAL_30    (BIT_(30))
#define BIT_IRAMC_WRAP_BIST_STA4_VAL_29    (BIT_(29))
#define BIT_IRAMC_WRAP_BIST_STA4_VAL_28    (BIT_(28))
#define BIT_IRAMC_WRAP_BIST_STA4_VAL_27    (BIT_(27))
#define BIT_IRAMC_WRAP_BIST_STA4_VAL_26    (BIT_(26))
#define BIT_IRAMC_WRAP_BIST_STA4_VAL_25    (BIT_(25))
#define BIT_IRAMC_WRAP_BIST_STA4_VAL_24    (BIT_(24))
#define BIT_IRAMC_WRAP_BIST_STA4_VAL_23    (BIT_(23))
#define BIT_IRAMC_WRAP_BIST_STA4_VAL_22    (BIT_(22))
#define BIT_IRAMC_WRAP_BIST_STA4_VAL_21    (BIT_(21))
#define BIT_IRAMC_WRAP_BIST_STA4_VAL_20    (BIT_(20))
#define BIT_IRAMC_WRAP_BIST_STA4_VAL_19    (BIT_(19))
#define BIT_IRAMC_WRAP_BIST_STA4_VAL_18    (BIT_(18))
#define BIT_IRAMC_WRAP_BIST_STA4_VAL_17    (BIT_(17))
#define BIT_IRAMC_WRAP_BIST_STA4_VAL_16    (BIT_(16))
#define BIT_IRAMC_WRAP_BIST_STA4_VAL_15    (BIT_(15))
#define BIT_IRAMC_WRAP_BIST_STA4_VAL_14    (BIT_(14))
#define BIT_IRAMC_WRAP_BIST_STA4_VAL_13    (BIT_(13))
#define BIT_IRAMC_WRAP_BIST_STA4_VAL_12    (BIT_(12))
#define BIT_IRAMC_WRAP_BIST_STA4_VAL_11    (BIT_(11))
#define BIT_IRAMC_WRAP_BIST_STA4_VAL_10    (BIT_(10))
#define BIT_IRAMC_WRAP_BIST_STA4_VAL_9    (BIT_(9))
#define BIT_IRAMC_WRAP_BIST_STA4_VAL_8    (BIT_(8))
#define BIT_IRAMC_WRAP_BIST_STA4_VAL_7    (BIT_(7))
#define BIT_IRAMC_WRAP_BIST_STA4_VAL_6    (BIT_(6))
#define BIT_IRAMC_WRAP_BIST_STA4_VAL_5    (BIT_(5))
#define BIT_IRAMC_WRAP_BIST_STA4_VAL_4    (BIT_(4))
#define BIT_IRAMC_WRAP_BIST_STA4_VAL_3    (BIT_(3))
#define BIT_IRAMC_WRAP_BIST_STA4_VAL_2    (BIT_(2))
#define BIT_IRAMC_WRAP_BIST_STA4_VAL_1    (BIT_(1))
#define BIT_IRAMC_WRAP_BIST_STA4_VAL_0    (BIT_(0))

//--------------------------------------------------------------------------
// Register Name   : IRAMC_WRAP_BIST_STA5
// Register Offset : 0x164
// Description     : bist result report
//--------------------------------------------------------------------------
#define IRAMC_WRAP_BIST_STA5                        0x164U

#define IRAMC_WRAP_BIST_STA5_VAL_FIELD_OFFSET 0
#define IRAMC_WRAP_BIST_STA5_VAL_FIELD_SIZE 32


#define BIT_IRAMC_WRAP_BIST_STA5_VAL_31    (BIT_(31))
#define BIT_IRAMC_WRAP_BIST_STA5_VAL_30    (BIT_(30))
#define BIT_IRAMC_WRAP_BIST_STA5_VAL_29    (BIT_(29))
#define BIT_IRAMC_WRAP_BIST_STA5_VAL_28    (BIT_(28))
#define BIT_IRAMC_WRAP_BIST_STA5_VAL_27    (BIT_(27))
#define BIT_IRAMC_WRAP_BIST_STA5_VAL_26    (BIT_(26))
#define BIT_IRAMC_WRAP_BIST_STA5_VAL_25    (BIT_(25))
#define BIT_IRAMC_WRAP_BIST_STA5_VAL_24    (BIT_(24))
#define BIT_IRAMC_WRAP_BIST_STA5_VAL_23    (BIT_(23))
#define BIT_IRAMC_WRAP_BIST_STA5_VAL_22    (BIT_(22))
#define BIT_IRAMC_WRAP_BIST_STA5_VAL_21    (BIT_(21))
#define BIT_IRAMC_WRAP_BIST_STA5_VAL_20    (BIT_(20))
#define BIT_IRAMC_WRAP_BIST_STA5_VAL_19    (BIT_(19))
#define BIT_IRAMC_WRAP_BIST_STA5_VAL_18    (BIT_(18))
#define BIT_IRAMC_WRAP_BIST_STA5_VAL_17    (BIT_(17))
#define BIT_IRAMC_WRAP_BIST_STA5_VAL_16    (BIT_(16))
#define BIT_IRAMC_WRAP_BIST_STA5_VAL_15    (BIT_(15))
#define BIT_IRAMC_WRAP_BIST_STA5_VAL_14    (BIT_(14))
#define BIT_IRAMC_WRAP_BIST_STA5_VAL_13    (BIT_(13))
#define BIT_IRAMC_WRAP_BIST_STA5_VAL_12    (BIT_(12))
#define BIT_IRAMC_WRAP_BIST_STA5_VAL_11    (BIT_(11))
#define BIT_IRAMC_WRAP_BIST_STA5_VAL_10    (BIT_(10))
#define BIT_IRAMC_WRAP_BIST_STA5_VAL_9    (BIT_(9))
#define BIT_IRAMC_WRAP_BIST_STA5_VAL_8    (BIT_(8))
#define BIT_IRAMC_WRAP_BIST_STA5_VAL_7    (BIT_(7))
#define BIT_IRAMC_WRAP_BIST_STA5_VAL_6    (BIT_(6))
#define BIT_IRAMC_WRAP_BIST_STA5_VAL_5    (BIT_(5))
#define BIT_IRAMC_WRAP_BIST_STA5_VAL_4    (BIT_(4))
#define BIT_IRAMC_WRAP_BIST_STA5_VAL_3    (BIT_(3))
#define BIT_IRAMC_WRAP_BIST_STA5_VAL_2    (BIT_(2))
#define BIT_IRAMC_WRAP_BIST_STA5_VAL_1    (BIT_(1))
#define BIT_IRAMC_WRAP_BIST_STA5_VAL_0    (BIT_(0))

//--------------------------------------------------------------------------
// Register Name   : IRAMC_WRAP_BIST_STA6
// Register Offset : 0x168
// Description     : bist result report
//--------------------------------------------------------------------------
#define IRAMC_WRAP_BIST_STA6                        0x168U

#define IRAMC_WRAP_BIST_STA6_VAL_FIELD_OFFSET 0
#define IRAMC_WRAP_BIST_STA6_VAL_FIELD_SIZE 32


#define BIT_IRAMC_WRAP_BIST_STA6_VAL_31    (BIT_(31))
#define BIT_IRAMC_WRAP_BIST_STA6_VAL_30    (BIT_(30))
#define BIT_IRAMC_WRAP_BIST_STA6_VAL_29    (BIT_(29))
#define BIT_IRAMC_WRAP_BIST_STA6_VAL_28    (BIT_(28))
#define BIT_IRAMC_WRAP_BIST_STA6_VAL_27    (BIT_(27))
#define BIT_IRAMC_WRAP_BIST_STA6_VAL_26    (BIT_(26))
#define BIT_IRAMC_WRAP_BIST_STA6_VAL_25    (BIT_(25))
#define BIT_IRAMC_WRAP_BIST_STA6_VAL_24    (BIT_(24))
#define BIT_IRAMC_WRAP_BIST_STA6_VAL_23    (BIT_(23))
#define BIT_IRAMC_WRAP_BIST_STA6_VAL_22    (BIT_(22))
#define BIT_IRAMC_WRAP_BIST_STA6_VAL_21    (BIT_(21))
#define BIT_IRAMC_WRAP_BIST_STA6_VAL_20    (BIT_(20))
#define BIT_IRAMC_WRAP_BIST_STA6_VAL_19    (BIT_(19))
#define BIT_IRAMC_WRAP_BIST_STA6_VAL_18    (BIT_(18))
#define BIT_IRAMC_WRAP_BIST_STA6_VAL_17    (BIT_(17))
#define BIT_IRAMC_WRAP_BIST_STA6_VAL_16    (BIT_(16))
#define BIT_IRAMC_WRAP_BIST_STA6_VAL_15    (BIT_(15))
#define BIT_IRAMC_WRAP_BIST_STA6_VAL_14    (BIT_(14))
#define BIT_IRAMC_WRAP_BIST_STA6_VAL_13    (BIT_(13))
#define BIT_IRAMC_WRAP_BIST_STA6_VAL_12    (BIT_(12))
#define BIT_IRAMC_WRAP_BIST_STA6_VAL_11    (BIT_(11))
#define BIT_IRAMC_WRAP_BIST_STA6_VAL_10    (BIT_(10))
#define BIT_IRAMC_WRAP_BIST_STA6_VAL_9    (BIT_(9))
#define BIT_IRAMC_WRAP_BIST_STA6_VAL_8    (BIT_(8))
#define BIT_IRAMC_WRAP_BIST_STA6_VAL_7    (BIT_(7))
#define BIT_IRAMC_WRAP_BIST_STA6_VAL_6    (BIT_(6))
#define BIT_IRAMC_WRAP_BIST_STA6_VAL_5    (BIT_(5))
#define BIT_IRAMC_WRAP_BIST_STA6_VAL_4    (BIT_(4))
#define BIT_IRAMC_WRAP_BIST_STA6_VAL_3    (BIT_(3))
#define BIT_IRAMC_WRAP_BIST_STA6_VAL_2    (BIT_(2))
#define BIT_IRAMC_WRAP_BIST_STA6_VAL_1    (BIT_(1))
#define BIT_IRAMC_WRAP_BIST_STA6_VAL_0    (BIT_(0))

//--------------------------------------------------------------------------
// Register Name   : IRAMC_WRAP_BIST_STA7
// Register Offset : 0x16c
// Description     : bist result report
//--------------------------------------------------------------------------
#define IRAMC_WRAP_BIST_STA7                    0x16cU

#define IRAMC_WRAP_BIST_STA7_VAL_FIELD_OFFSET 0
#define IRAMC_WRAP_BIST_STA7_VAL_FIELD_SIZE 32

#define BIT_IRAMC_WRAP_BIST_STA7_VAL_31    (BIT_(31))
#define BIT_IRAMC_WRAP_BIST_STA7_VAL_30    (BIT_(30))
#define BIT_IRAMC_WRAP_BIST_STA7_VAL_29    (BIT_(29))
#define BIT_IRAMC_WRAP_BIST_STA7_VAL_28    (BIT_(28))
#define BIT_IRAMC_WRAP_BIST_STA7_VAL_27    (BIT_(27))
#define BIT_IRAMC_WRAP_BIST_STA7_VAL_26    (BIT_(26))
#define BIT_IRAMC_WRAP_BIST_STA7_VAL_25    (BIT_(25))
#define BIT_IRAMC_WRAP_BIST_STA7_VAL_24    (BIT_(24))
#define BIT_IRAMC_WRAP_BIST_STA7_VAL_23    (BIT_(23))
#define BIT_IRAMC_WRAP_BIST_STA7_VAL_22    (BIT_(22))
#define BIT_IRAMC_WRAP_BIST_STA7_VAL_21    (BIT_(21))
#define BIT_IRAMC_WRAP_BIST_STA7_VAL_20    (BIT_(20))
#define BIT_IRAMC_WRAP_BIST_STA7_VAL_19    (BIT_(19))
#define BIT_IRAMC_WRAP_BIST_STA7_VAL_18    (BIT_(18))
#define BIT_IRAMC_WRAP_BIST_STA7_VAL_17    (BIT_(17))
#define BIT_IRAMC_WRAP_BIST_STA7_VAL_16    (BIT_(16))
#define BIT_IRAMC_WRAP_BIST_STA7_VAL_15    (BIT_(15))
#define BIT_IRAMC_WRAP_BIST_STA7_VAL_14    (BIT_(14))
#define BIT_IRAMC_WRAP_BIST_STA7_VAL_13    (BIT_(13))
#define BIT_IRAMC_WRAP_BIST_STA7_VAL_12    (BIT_(12))
#define BIT_IRAMC_WRAP_BIST_STA7_VAL_11    (BIT_(11))
#define BIT_IRAMC_WRAP_BIST_STA7_VAL_10    (BIT_(10))
#define BIT_IRAMC_WRAP_BIST_STA7_VAL_9    (BIT_(9))
#define BIT_IRAMC_WRAP_BIST_STA7_VAL_8    (BIT_(8))
#define BIT_IRAMC_WRAP_BIST_STA7_VAL_7    (BIT_(7))
#define BIT_IRAMC_WRAP_BIST_STA7_VAL_6    (BIT_(6))
#define BIT_IRAMC_WRAP_BIST_STA7_VAL_5    (BIT_(5))
#define BIT_IRAMC_WRAP_BIST_STA7_VAL_4    (BIT_(4))
#define BIT_IRAMC_WRAP_BIST_STA7_VAL_3    (BIT_(3))
#define BIT_IRAMC_WRAP_BIST_STA7_VAL_2    (BIT_(2))
#define BIT_IRAMC_WRAP_BIST_STA7_VAL_1    (BIT_(1))
#define BIT_IRAMC_WRAP_BIST_STA7_VAL_0    (BIT_(0))

//--------------------------------------------------------------------------
// Register Name   : IRAMC_WRAP_BIST_REGION0
// Register Offset : 0x170
// Description     : bist area configuration for data ram
//--------------------------------------------------------------------------
#define IRAMC_WRAP_BIST_REGION0                     0x170U

#define IRAMC_WRAP_BIST_REGION0_SIZE_FIELD_OFFSET 16
#define IRAMC_WRAP_BIST_REGION0_SIZE_FIELD_SIZE 16

#define IRAMC_WRAP_BIST_REGION0_STARTADDR_FIELD_OFFSET 0
#define IRAMC_WRAP_BIST_REGION0_STARTADDR_FIELD_SIZE 16


#define BIT_IRAMC_WRAP_BIST_REGION0_SIZE_15    (BIT_(31))
#define BIT_IRAMC_WRAP_BIST_REGION0_SIZE_14    (BIT_(30))
#define BIT_IRAMC_WRAP_BIST_REGION0_SIZE_13    (BIT_(29))
#define BIT_IRAMC_WRAP_BIST_REGION0_SIZE_12    (BIT_(28))
#define BIT_IRAMC_WRAP_BIST_REGION0_SIZE_11    (BIT_(27))
#define BIT_IRAMC_WRAP_BIST_REGION0_SIZE_10    (BIT_(26))
#define BIT_IRAMC_WRAP_BIST_REGION0_SIZE_9    (BIT_(25))
#define BIT_IRAMC_WRAP_BIST_REGION0_SIZE_8    (BIT_(24))
#define BIT_IRAMC_WRAP_BIST_REGION0_SIZE_7    (BIT_(23))
#define BIT_IRAMC_WRAP_BIST_REGION0_SIZE_6    (BIT_(22))
#define BIT_IRAMC_WRAP_BIST_REGION0_SIZE_5    (BIT_(21))
#define BIT_IRAMC_WRAP_BIST_REGION0_SIZE_4    (BIT_(20))
#define BIT_IRAMC_WRAP_BIST_REGION0_SIZE_3    (BIT_(19))
#define BIT_IRAMC_WRAP_BIST_REGION0_SIZE_2    (BIT_(18))
#define BIT_IRAMC_WRAP_BIST_REGION0_SIZE_1    (BIT_(17))
#define BIT_IRAMC_WRAP_BIST_REGION0_SIZE_0    (BIT_(16))

#define BIT_IRAMC_WRAP_BIST_REGION0_STARTADDR_15    (BIT_(15))
#define BIT_IRAMC_WRAP_BIST_REGION0_STARTADDR_14    (BIT_(14))
#define BIT_IRAMC_WRAP_BIST_REGION0_STARTADDR_13    (BIT_(13))
#define BIT_IRAMC_WRAP_BIST_REGION0_STARTADDR_12    (BIT_(12))
#define BIT_IRAMC_WRAP_BIST_REGION0_STARTADDR_11    (BIT_(11))
#define BIT_IRAMC_WRAP_BIST_REGION0_STARTADDR_10    (BIT_(10))
#define BIT_IRAMC_WRAP_BIST_REGION0_STARTADDR_9    (BIT_(9))
#define BIT_IRAMC_WRAP_BIST_REGION0_STARTADDR_8    (BIT_(8))
#define BIT_IRAMC_WRAP_BIST_REGION0_STARTADDR_7    (BIT_(7))
#define BIT_IRAMC_WRAP_BIST_REGION0_STARTADDR_6    (BIT_(6))
#define BIT_IRAMC_WRAP_BIST_REGION0_STARTADDR_5    (BIT_(5))
#define BIT_IRAMC_WRAP_BIST_REGION0_STARTADDR_4    (BIT_(4))
#define BIT_IRAMC_WRAP_BIST_REGION0_STARTADDR_3    (BIT_(3))
#define BIT_IRAMC_WRAP_BIST_REGION0_STARTADDR_2    (BIT_(2))
#define BIT_IRAMC_WRAP_BIST_REGION0_STARTADDR_1    (BIT_(1))
#define BIT_IRAMC_WRAP_BIST_REGION0_STARTADDR_0    (BIT_(0))

//--------------------------------------------------------------------------
// Register Name   : IRAMC_WRAP_BIST_REGION1
// Register Offset : 0x174
// Description     : bist area configuration for ecc ram
//--------------------------------------------------------------------------
#define IRAMC_WRAP_BIST_REGION1                         0x174U

#define IRAMC_WRAP_BIST_REGION1_SIZE_FIELD_OFFSET 16
#define IRAMC_WRAP_BIST_REGION1_SIZE_FIELD_SIZE 16

#define IRAMC_WRAP_BIST_REGION1_STARTADDR_FIELD_OFFSET 0
#define IRAMC_WRAP_BIST_REGION1_STARTADDR_FIELD_SIZE 16


#define BIT_IRAMC_WRAP_BIST_REGION1_SIZE_15    (BIT_(31))
#define BIT_IRAMC_WRAP_BIST_REGION1_SIZE_14    (BIT_(30))
#define BIT_IRAMC_WRAP_BIST_REGION1_SIZE_13    (BIT_(29))
#define BIT_IRAMC_WRAP_BIST_REGION1_SIZE_12    (BIT_(28))
#define BIT_IRAMC_WRAP_BIST_REGION1_SIZE_11    (BIT_(27))
#define BIT_IRAMC_WRAP_BIST_REGION1_SIZE_10    (BIT_(26))
#define BIT_IRAMC_WRAP_BIST_REGION1_SIZE_9    (BIT_(25))
#define BIT_IRAMC_WRAP_BIST_REGION1_SIZE_8    (BIT_(24))
#define BIT_IRAMC_WRAP_BIST_REGION1_SIZE_7    (BIT_(23))
#define BIT_IRAMC_WRAP_BIST_REGION1_SIZE_6    (BIT_(22))
#define BIT_IRAMC_WRAP_BIST_REGION1_SIZE_5    (BIT_(21))
#define BIT_IRAMC_WRAP_BIST_REGION1_SIZE_4    (BIT_(20))
#define BIT_IRAMC_WRAP_BIST_REGION1_SIZE_3    (BIT_(19))
#define BIT_IRAMC_WRAP_BIST_REGION1_SIZE_2    (BIT_(18))
#define BIT_IRAMC_WRAP_BIST_REGION1_SIZE_1    (BIT_(17))
#define BIT_IRAMC_WRAP_BIST_REGION1_SIZE_0    (BIT_(16))

#define BIT_IRAMC_WRAP_BIST_REGION1_STARTADDR_15    (BIT_(15))
#define BIT_IRAMC_WRAP_BIST_REGION1_STARTADDR_14    (BIT_(14))
#define BIT_IRAMC_WRAP_BIST_REGION1_STARTADDR_13    (BIT_(13))
#define BIT_IRAMC_WRAP_BIST_REGION1_STARTADDR_12    (BIT_(12))
#define BIT_IRAMC_WRAP_BIST_REGION1_STARTADDR_11    (BIT_(11))
#define BIT_IRAMC_WRAP_BIST_REGION1_STARTADDR_10    (BIT_(10))
#define BIT_IRAMC_WRAP_BIST_REGION1_STARTADDR_9    (BIT_(9))
#define BIT_IRAMC_WRAP_BIST_REGION1_STARTADDR_8    (BIT_(8))
#define BIT_IRAMC_WRAP_BIST_REGION1_STARTADDR_7    (BIT_(7))
#define BIT_IRAMC_WRAP_BIST_REGION1_STARTADDR_6    (BIT_(6))
#define BIT_IRAMC_WRAP_BIST_REGION1_STARTADDR_5    (BIT_(5))
#define BIT_IRAMC_WRAP_BIST_REGION1_STARTADDR_4    (BIT_(4))
#define BIT_IRAMC_WRAP_BIST_REGION1_STARTADDR_3    (BIT_(3))
#define BIT_IRAMC_WRAP_BIST_REGION1_STARTADDR_2    (BIT_(2))
#define BIT_IRAMC_WRAP_BIST_REGION1_STARTADDR_1    (BIT_(1))
#define BIT_IRAMC_WRAP_BIST_REGION1_STARTADDR_0    (BIT_(0))

//--------------------------------------------------------------------------
// Register Name   : IRAMC_WRAP_BIST_REGION2
// Register Offset : 0x178
// Description     : bist step
//--------------------------------------------------------------------------
#define IRAMC_WRAP_BIST_REGION2                     0x178U

#define IRAMC_WRAP_BIST_REGION2_ECC_STEP_FIELD_OFFSET 16
#define IRAMC_WRAP_BIST_REGION2_ECC_STEP_FIELD_SIZE 8

#define IRAMC_WRAP_BIST_REGION2_DATA_STEP_FIELD_OFFSET 0
#define IRAMC_WRAP_BIST_REGION2_DATA_STEP_FIELD_SIZE 8


#define BIT_IRAMC_WRAP_BIST_REGION2_ECC_STEP_7    (BIT_(23))
#define BIT_IRAMC_WRAP_BIST_REGION2_ECC_STEP_6    (BIT_(22))
#define BIT_IRAMC_WRAP_BIST_REGION2_ECC_STEP_5    (BIT_(21))
#define BIT_IRAMC_WRAP_BIST_REGION2_ECC_STEP_4    (BIT_(20))
#define BIT_IRAMC_WRAP_BIST_REGION2_ECC_STEP_3    (BIT_(19))
#define BIT_IRAMC_WRAP_BIST_REGION2_ECC_STEP_2    (BIT_(18))
#define BIT_IRAMC_WRAP_BIST_REGION2_ECC_STEP_1    (BIT_(17))
#define BIT_IRAMC_WRAP_BIST_REGION2_ECC_STEP_0    (BIT_(16))

#define BIT_IRAMC_WRAP_BIST_REGION2_DATA_STEP_7    (BIT_(7))
#define BIT_IRAMC_WRAP_BIST_REGION2_DATA_STEP_6    (BIT_(6))
#define BIT_IRAMC_WRAP_BIST_REGION2_DATA_STEP_5    (BIT_(5))
#define BIT_IRAMC_WRAP_BIST_REGION2_DATA_STEP_4    (BIT_(4))
#define BIT_IRAMC_WRAP_BIST_REGION2_DATA_STEP_3    (BIT_(3))
#define BIT_IRAMC_WRAP_BIST_REGION2_DATA_STEP_2    (BIT_(2))
#define BIT_IRAMC_WRAP_BIST_REGION2_DATA_STEP_1    (BIT_(1))
#define BIT_IRAMC_WRAP_BIST_REGION2_DATA_STEP_0    (BIT_(0))

#endif
