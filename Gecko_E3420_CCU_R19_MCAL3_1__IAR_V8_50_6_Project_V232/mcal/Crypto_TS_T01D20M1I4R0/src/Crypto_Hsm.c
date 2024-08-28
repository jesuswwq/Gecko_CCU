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
 * @file  Crypto_Hsm.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Crypto
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <Crypto_Hsm.h>
#include <Det.h>
#include <Mcu_Delay.h>
#include "Mcu_Soc.h"
#include <SchM_Crypto.h>
#include "cdefs.h"
#include "soc_seip_reg.h"
#include "debug.h"
#include <Crypto_Types.h>
#include <__regs_base.h>
#include "mini_libc.h"

#ifdef SEMIDRIVE_E3_LITE_SERIES
#define APB_SCR_APB_BASE (0xF08B0000ul)
#define MODULE_RESET_CONTROL_BASE (0xF08C0000ul)
/*scr release seip rst scr_l16_reg
      ce_writel(0xF30F1200, 0x1);
      0xF08C0000+ 0x1304U + 8U*(19) = 0xF08C139Cu*/
#define MODULE_RESET_CONTROL_SEIP_BASE (0xF08C139Cu)
#define APB_SCR_CTRL_SSK4_FROM_SEC_STORAGE (APB_SCR_APB_BASE+0x1400+0xC)
#else
#define APB_SCR_APB_BASE (0xf30f0000u)
#define MODULE_RESET_CONTROL_BASE (0xF30D0000)
/*scr release seip rst scr_l16_reg
      ce_writel(0xF30F1200, 0x1);
      0xF30D0000+ 0x1304U + 8U*(10) = 0xF30D1354*/
#define MODULE_RESET_CONTROL_SEIP_BASE (0xF30D1354u)
#define APB_SCR_CTRL_SSK4_FROM_SEC_STORAGE (APB_SCR_APB_BASE+0x1400)
#endif

#define CRYPTO_HSM_GEN_RSA_DEFAULT_EBIT_LEN 17

#define EFUSEC_EHSM_CFG_OFFSET 0x1300
#define EFUSEC_SEIP_SECSTORAGE_SEL_OFFSET 0x12c9

#define MODULE_RESET_CONTROL_OFF(n) (0x1304U + 8U * (n))

#define MODULE_RESET_CONTROL_RUN_MODE (0x01U << 0U)
#define MODULE_AUTO_CLEAR_RESET_CONTROL_RUN_MODE (0x01U << 6U)
#define MODULE_RESET_CONTROL_RSTA (0x01U << 29U)

#define RSTGEN_POLLs 0x10000
#define TIMEOUT_POLLs 0x1000000

#ifndef REGHELPER_H
#define REG32(addr) ((volatile uint32 *)(unsigned long int)(addr))
#define REG8(addr) ((volatile uint8 *)(unsigned long int)(addr))
#endif

#define ce_writel(a, v) (*REG32(a) = (v))
#define ce_readl(a) (*REG32(a))
#define ce_writeb(a, v) (*REG8(a) = (v))
#define ce_readb(a) (*REG8(a))

#define SEIP_ERROR (0x37)
#define SEIP_FW_VER_SUCCESS (0xE6)

/* key mac value , the otp key plaintext value should init */
#define USE_OTP_KEY_PLAIN 1

#ifndef INIT_EFUSE_FOR_TEST
#define INIT_EFUSE_FOR_TEST 1
#endif

#define CMD_BASIC_MAC_BUFF_LEN 32
#define CMD_BASIC_TWO_KEY_MAC_BUFF_LEN 64

/*must be equal to seip config*/
/*OTP key attribute*/
#define OTP_KEY_ATR_FREE_USE        (0x00)
#define OTP_KEY_ATR_MAC_AUT         (0x02)
#define OTP_KEY_ATR_DISUSE          (0x03)
#define OTP_KEY_AUT_KEY             (0x20)
#define SSK_CTRL0                   0x20009100
#define SSK_CTRL1                   0x81910000

#define SOC_OTP_KEY_GET_MAC_BUFF_LEN 128

#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_ON)
#define CRYPTO_START_SEC_VAR_NO_INIT_NO_CACHE_UNSPECIFIED
#else
#define CRYPTO_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_ON) */
#include "Crypto_MemMap.h"

uint32 get_mac_buff[SOC_OTP_KEY_GET_MAC_BUFF_LEN] ALIGNED(CACHE_LINE);

#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_ON)
#define CRYPTO_STOP_SEC_VAR_NO_INIT_NO_CACHE_UNSPECIFIED
#else
#define CRYPTO_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_ON) */
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Crypto_MemMap.h"

static Crypto_VerifyResultType *verify_resultPtr;
static uint8 check_res_count;
static uint8 init_count;

#define CRYPTO_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_VAR_INIT_UNSPECIFIED
#include "Crypto_MemMap.h"

uint8 OTP_KEY_BUFFER[] ALIGNED(CACHE_LINE) = {
    0xCF, 0x16, 0xAE, 0xCE, 0xAE, 0xE4, 0x22, 0x89,
    0x1E, 0x8B, 0xE8, 0x5F, 0xE7, 0x19, 0x71, 0x10,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x8D, 0x9B, 0x9D, 0x8A, 0x44, 0x37, 0xA4, 0xA3,
    0xBA, 0xEC, 0x22, 0x9A, 0x60, 0xF5, 0xE9, 0x0E,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x9F, 0xEB, 0xA8, 0x79, 0xC5, 0x96, 0xE5, 0x02,
    0x2C, 0x22, 0xC1, 0xEA, 0x76, 0x26, 0x0E, 0xF3,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xCB, 0xC0, 0x06, 0x8E, 0x1F, 0x3D, 0x55, 0x2A,
    0x09, 0xDE, 0xFC, 0x92, 0x9F, 0x07, 0xA4, 0x45,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x31, 0xDC, 0xE8, 0x52, 0x1C, 0x49, 0xB5, 0x1C,
    0x79, 0x3C, 0xE7, 0xEB, 0x38, 0xAB, 0x4B, 0x10,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xF0, 0xB5, 0xF5, 0xC4, 0x42, 0x84, 0x94, 0x36,
    0xB2, 0x6D, 0xCB, 0xCC, 0xB0, 0x72, 0x79, 0x8D,
    0xF8, 0x70, 0x2D, 0x36, 0xB3, 0x08, 0x9C, 0xBC,
    0x00, 0x5E, 0xA3, 0x08, 0xAA, 0x70, 0x77, 0x69,
    0xE3, 0xCF, 0xF9, 0x1C, 0x1B, 0xEC, 0x6D, 0x5D,
    0x12, 0x8E, 0x69, 0xC1, 0x43, 0x38, 0xD6, 0x95,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x64, 0x27, 0xB1, 0x55, 0x2F, 0x7F, 0x2D, 0xFA,
    0x74, 0x70, 0x7F, 0xEC, 0x47, 0xC6, 0xAC, 0x3C,
    0x16, 0x19, 0x71, 0x55, 0x46, 0x91, 0x2D, 0x92,
    0x12, 0x2A, 0x54, 0x7E, 0xF2, 0xC3, 0xC6, 0x51
};

#define CRYPTO_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"

void set_big_endian_4byte(uint8 *addr, uint32 data)
{
    uint32 *p_32;
    uint8 *p_8;

    if (((uint32)addr) & 3) {
        p_8 = (uint8 *)addr;
        *p_8     = (data >> 24) & 0xFF;
        *(p_8 + 1) = (data >> 16) & 0xFF;
        *(p_8 + 2) = (data >> 8) & 0xFF;
        *(p_8 + 3) = data & 0xFF;
    } else {
            /*PRQA S 3305 1*/
            p_32 = (uint32 *)addr;
            *p_32  = (data << 24) & 0xFF000000;
            *p_32 |= (data << 8)  & 0x00FF0000;
            *p_32 |= (data >> 8)  & 0x0000FF00;
            *p_32 |= (data >> 24) & 0x000000FF;
    }
}

void set_big_endian_2byte(uint8 *addr, uint16 data)
{
    uint8 *pdata = (uint8 *)addr;
    *(pdata) = (data >> 8) & 0xFF;
    *(pdata + 1) = data & 0xFF;
}

uint32 send_cmd_and_wait_response(uint32 cmd[8], Crypto_JobType *job, Crypto_ProcessingType IsSync)
{
    uint32 ret = 0;
    int i = 0;

    rSOCMBOX_CMD_D0  = cmd[0];
    rSOCMBOX_CMD_D1  = cmd[1];
    rSOCMBOX_CMD_D2  = cmd[2];
    rSOCMBOX_CMD_D3  = cmd[3];
    rSOCMBOX_CMD_D4  = cmd[4];
    rSOCMBOX_CMD_D5  = cmd[5];
    rSOCMBOX_CMD_D6  = cmd[6];
    rSOCMBOX_CMD_D7  = cmd[7];
    rSOCMBOX_RSP_D0  = 0;

    if (CRYPTO_PROCESSING_SYNC == IsSync) {
        rSOCMBOX_INT_EN = 0x00;
        rSOCMBOX_INT_STA = 0x01;

        while (rSOCMBOX_INT_STA != 0x02) {
            /*Timeout error*/
            if (i++ > 30000000) {
                rSOCMBOX_INT_STA = 0x02;
                return SEIP_TIME_OUT;
            }
        }

        rSOCMBOX_INT_STA = 0x02;
        ret = rSOCMBOX_RSP_D0;
    } else {
        if (NULL != job) {
            verify_resultPtr = job->jobPrimitiveInputOutput.verifyPtr;
        }
        rSOCMBOX_INT_EN = 0x02;
        /* send cmd */
        rSOCMBOX_INT_STA = 0x01;

        ret = SEIP_SUCCESS;
    }

    return ret;
}

uint8 check_rand0(void)
{
    uint32 rand_output, rand_bytes, tmp;
    uint8 *ptr;

    tmp = rSOCMBOX_CMD_D1;
    set_big_endian_4byte((uint8 *)&rand_output, tmp);
    tmp = rSOCMBOX_CMD_D2;
    set_big_endian_4byte((uint8 *)&rand_bytes, tmp);

    uint8 count = rand_bytes < 4 ? rand_bytes : 4;

    if (count == 0)
        return 0;

    ptr = (uint8 *)rand_output;
#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
    arch_invalidate_cache_range(ptr, rand_bytes);
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */
    for(int i = 0; i < count; i++) {
        tmp = rand_bytes - 1 - i;
        if (ptr[tmp])
            return 0;
    }

    return 1;
}

void check_verify(void)
{
    uint8 cmd_id = rSOCMBOX_CMD_D0;
    if ((cmd_id == VERIFY_MAC ||
        cmd_id == SM2_VERIFY_SIGNATURE ||
        cmd_id == ECDSA_VERIFY_SIGNATURE ||
        cmd_id == RSA_VERIFY_SIGNATURE) &&
        (verify_resultPtr != NULL)) {
        /* handle */
        if (SEIP_SUCCESS == rSOCMBOX_RSP_D0)
            *verify_resultPtr = CRYPTO_E_VER_OK;
        else
            *verify_resultPtr = CRYPTO_E_VER_NOT_OK;
    }
}

uint8 check_retry(void)
{
    uint32 ret = rSOCMBOX_RSP_D0;
    uint8 cmd_id = rSOCMBOX_CMD_D0;
    if ((ret == SEIP_ERROR_SM2_ENCRYPT_FAIL ||
        ret == SEIP_ERROR_SM2_SIGN_FAIL ||
        ret == SEIP_ERROR_ECDSA_VERIFY_FAIL ||
        ret == SEIP_ERROR_RSA_GET_KEY_FAIL ||
        ret == SEIP_ERROR_ECC_GET_KEY_FAIL ||
        ret == SEIP_ERROR_SM2_GET_KEY_FAIL ||
        ret == SEIP_ERROR_TRNG_FAIL) &&
        (check_res_count < RETRY_COUNT)) {
        ret = CRYPTO_HSM_BUSY;
        check_res_count++;
        rSOCMBOX_RSP_D0  = 0;
        rSOCMBOX_INT_EN = 0x02;
        /* send cmd */
        rSOCMBOX_INT_STA = 0x01;
        return 1;
    } else if ((ret == SEIP_SUCCESS) &&
        (cmd_id == GENERATE_RAND) &&
        (check_res_count < RETRY_COUNT)) {
        if (check_rand0()) {
            ret = CRYPTO_HSM_BUSY;
            check_res_count++;
            rSOCMBOX_RSP_D0  = 0;
            rSOCMBOX_INT_EN = 0x02;
            /* send cmd */
            rSOCMBOX_INT_STA = 0x01;

            return 1;
        }
    } else {
        check_res_count = 0;
    }

    return 0;
}

uint32 Crypto_Check_Response(void)
{
    uint32 ret = 0;

    if (0x02 == rSOCMBOX_INT_STA) {
        ret = rSOCMBOX_RSP_D0;
        rSOCMBOX_INT_STA = 0x02;
        rSOCMBOX_INT_EN = 0x00;
        /* if the entropy value of algorithm is not enough , need retry */
        if (check_retry())
            return CRYPTO_HSM_BUSY;

        /* If it is a verify command, the result needs to be updated.*/
        check_verify();
    } else if (!rSOCMBOX_INT_STA && !rSOCMBOX_INT_EN) {
        ret = CRYPTO_HSM_IDLE;
    } else {
        ret = CRYPTO_HSM_BUSY;
    }

    return ret;
}

#if INIT_EFUSE_FOR_TEST
void init_efuse_for_test(void)
{
    uint32  data;
    uint32 tms = 0U;

    /*bit[10] busy*/
    data = ce_readl(APB_EFUSEC_BASE + 0x0);

    while ((data & (1 << 10)) != 0 && (tms++ < TIMEOUT_POLLs)) {
        data = ce_readl(APB_EFUSEC_BASE + 0x0);
        if (tms++ >= TIMEOUT_POLLs)
            return;
    }

    /*life cycle mode*/
    ce_writel(APB_EFUSEC_BASE + 0x1304, 0x57C1EC96);

    /*analog timming 1*/
    ce_writel(APB_EFUSEC_BASE + 0x1308, 0x00000000);
    ce_writel(APB_EFUSEC_BASE + 0x130C, 0x00000000);

    /*secure flag*/
    ce_writel(APB_EFUSEC_BASE + 0x1310, 0xFFFFFFFF);

    /*PKD Public Key Digest 8x32*/
    ce_writel(APB_EFUSEC_BASE + 0x1080, 0x5C4CE1B2);
    ce_writel(APB_EFUSEC_BASE + 0x1084, 0x5BDFC679);
    ce_writel(APB_EFUSEC_BASE + 0x1088, 0x7EFEF485);
    ce_writel(APB_EFUSEC_BASE + 0x108c, 0x267ADBD8);
    ce_writel(APB_EFUSEC_BASE + 0x1090, 0xE0A79D2B);
    ce_writel(APB_EFUSEC_BASE + 0x1094, 0xA90ECB7C);
    ce_writel(APB_EFUSEC_BASE + 0x1098, 0x8C7B74F4);
    ce_writel(APB_EFUSEC_BASE + 0x109c, 0xF3A4A8CD);

    /*SSK CTRL0 CTRL1*/
    ce_writel(APB_EFUSEC_BASE + 0x1318, 0x20009100);
    ce_writel(APB_EFUSEC_BASE + 0x131C, 0x81910000);

    /*analog timming 2*/
    ce_writel(APB_EFUSEC_BASE + 0x1314, 0x00000000);

    /*FSRK*/
    ce_writel(APB_EFUSEC_BASE + 0x10c0, 0x01cca048);
    ce_writel(APB_EFUSEC_BASE + 0x10c4, 0x13e16fc6);
    ce_writel(APB_EFUSEC_BASE + 0x10c8, 0x468c8fc3);
    ce_writel(APB_EFUSEC_BASE + 0x10cc, 0x9b33e294);

    /*Debug Passphrase(DPK)*/
    ce_writel(APB_EFUSEC_BASE + 0x10E0, 0x555a8f01);
    ce_writel(APB_EFUSEC_BASE + 0x10E4, 0x97445894);
    ce_writel(APB_EFUSEC_BASE + 0x10E8, 0xe4f7ffc0);
    ce_writel(APB_EFUSEC_BASE + 0x10EC, 0xfc163902);
    ce_writel(APB_EFUSEC_BASE + 0x10F0, 0x69bffe04);
    ce_writel(APB_EFUSEC_BASE + 0x10F4, 0x6afaab9f);
    ce_writel(APB_EFUSEC_BASE + 0x10F8, 0xb2909223);
    ce_writel(APB_EFUSEC_BASE + 0x10FC, 0x605c925b);

    /*SSRK*/
    ce_writel(APB_EFUSEC_BASE + 0x10d0, 0x6f5a1159);
    ce_writel(APB_EFUSEC_BASE + 0x10d4, 0xc4c128be);
    ce_writel(APB_EFUSEC_BASE + 0x10d8, 0x51d3ab6d);
    ce_writel(APB_EFUSEC_BASE + 0x10dc, 0x79dfe324);

    /*Firmware Update Key(fuk)*/
    ce_writel(APB_EFUSEC_BASE + 0x1100, 0xe526a831);
    ce_writel(APB_EFUSEC_BASE + 0x1104, 0x91d949bb);
    ce_writel(APB_EFUSEC_BASE + 0x1108, 0xe981ea4b);
    ce_writel(APB_EFUSEC_BASE + 0x110c, 0x482b906c);
    ce_writel(APB_EFUSEC_BASE + 0x1110, 0x51422e72);
    ce_writel(APB_EFUSEC_BASE + 0x1114, 0x84e87752);
    ce_writel(APB_EFUSEC_BASE + 0x1118, 0x38da4eec);
    ce_writel(APB_EFUSEC_BASE + 0x111c, 0x588dfa57);

    /*CRC (KCRC)*/
    ce_writel(APB_EFUSEC_BASE + 0x12a0, 0xD274ED53);
    ce_writel(APB_EFUSEC_BASE + 0x12a4, 0x7C1985E9);
    ce_writel(APB_EFUSEC_BASE + 0x12a8, 0xDF4C8867);
    ce_writel(APB_EFUSEC_BASE + 0x12ac, 0xB05F2E42);
    ce_writeb(APB_EFUSEC_BASE + 0x12c9, 0x1);
}
#endif

/**
 * @brief crypto init
 *
 * This function init hsm
 *
 */
FUNC(Crypto_HsmInitReturnType, CRYPTO_CODE) Hsm_host_init
(
    Crypto_ProcessingType IsSync
)
{
    Crypto_HsmInitReturnType ret = CRYPTO_HSM_INIT_OK;
    unsigned int rdata = 0;
    unsigned int rdata_lifecycle = 0;
    uint32 tms = 0;
#if INIT_EFUSE_FOR_TEST
    init_efuse_for_test();
#endif
    /* add return value */
    ce_writel(APB_EFUSEC_BASE+ 0x1300, 0x80000000);

    /* if fuse config ssk4 from sec storage, set */
    rdata = ce_readb(APB_EFUSEC_BASE + EFUSEC_SEIP_SECSTORAGE_SEL_OFFSET);
    if ((rdata & 0x1) == 0) {
        ce_writel(APB_SCR_CTRL_SSK4_FROM_SEC_STORAGE, 0x2);
    } else {
         /* If not cleared, it may affect the test of fuse shadow register */
        ce_writel(APB_SCR_CTRL_SSK4_FROM_SEC_STORAGE, 0x0);
    }

    rdata = ce_readl(MODULE_RESET_CONTROL_SEIP_BASE);

    rdata |= MODULE_AUTO_CLEAR_RESET_CONTROL_RUN_MODE;

    ce_writel(MODULE_RESET_CONTROL_SEIP_BASE, rdata);

    rdata = ce_readl(MODULE_RESET_CONTROL_SEIP_BASE);

    rdata |= MODULE_RESET_CONTROL_RUN_MODE;

    ce_writel(MODULE_RESET_CONTROL_SEIP_BASE, rdata);

    /*polling seip reset state*/
    while ((!(ce_readl(MODULE_RESET_CONTROL_SEIP_BASE) &
              MODULE_RESET_CONTROL_RSTA)) &&
           (tms++ < RSTGEN_POLLs)) {
            if(tms >= RSTGEN_POLLs){
                return CRYPTO_HSM_INIT_RESET_FAIL;
            }
    }

    tms = 0;
    /*polling status seip boot_done*/
    do {
        tms++;
        rdata = ce_readl(APB_SEIP_BASE + 0x14);
        if (tms >= TIMEOUT_POLLs)
            return CRYPTO_HSM_INIT_BOOT_TIMEOUT;
    } while ((rdata & 0x100) == 0);

    /* if fuse config offset 16, seip_mode_sel = 10 CACC mode, 00 MAILBOX mode*/
    rdata = ce_readl(APB_EFUSEC_BASE + EFUSEC_EHSM_CFG_OFFSET);

    /*get hsm life cycle value*/
    rdata_lifecycle = ce_readl(APB_EFUSEC_BASE + 0x1304);

    /* wait for seip ready for mailbox */
    if ((rdata & 0x30000) == 0x0) {
        if(rdata_lifecycle == 0x0){
            /*test mode not rsp value*/
        }else{
            if (CRYPTO_PROCESSING_ASYNC == IsSync) {
                /* async process, Check the results later .*/
            } else {
                tms = 0;
                while (rSOCMBOX_RSP_D0 == 0x0 && (tms++ < TIMEOUT_POLLs)) {
                    if (tms >= TIMEOUT_POLLs) {
                        return CRYPTO_HSM_INIT_BOOT_TIMEOUT;
                    }
                }
                rSOCMBOX_INT_STA = 0x02;
                if (rSOCMBOX_RSP_D0 == SEIP_FW_VER_SUCCESS) {
                } else {
                    ret = CRYPTO_HSM_INIT_BOOT_FAIL;
                }
            }
        }
    } else {
        ret = CRYPTO_HSM_INIT_PRODUCT_ERROR;
    }

    return ret;
}

/**
 * @brief checking crypto init
 *
 * This function check result of init hsm
 *
 */
FUNC(Crypto_HsmInitReturnType, CRYPTO_CODE) Hsm_host_init_check
(
    void
)
{
    Crypto_HsmInitReturnType ret = CRYPTO_HSM_INIT_BOOT_FAIL;

    /*get hsm life cycle value*/
    uint32 rdata_lifecycle = ce_readl(APB_EFUSEC_BASE + 0x1304);

    if (rdata_lifecycle == 0x0) {
        ret = CRYPTO_HSM_INIT_OK;
    } else {
        if (rSOCMBOX_RSP_D0 == 0) {
            ret = CRYPTO_HSM_BUSY;
        } else {
            rSOCMBOX_INT_STA = 0x02;
            if (rSOCMBOX_RSP_D0 == SEIP_FW_VER_SUCCESS) {
                ret = CRYPTO_HSM_INIT_OK;
                init_count = 0;
            } else {
                if (init_count < RETRY_COUNT) {
                    ret = CRYPTO_HSM_BUSY;
                    init_count++;
                    Hsm_host_init(SW_CRYPTO_INIT_MODE);
                } else {
                    ret = CRYPTO_HSM_INIT_BOOT_FAIL;
                }
            }
        }
    }

    return ret;
}

uint32 aes_algo_mode_mapping(Crypto_AlgorithmModeType autosar_algo,
                                    uint8 key_sz)
{
    uint32 hsm_algo = 0xff;

    switch (autosar_algo) {
    case CRYPTO_ALGOMODE_ECB: {
        hsm_algo = (key_sz == 32 ? SKE_ALG_AES_256_ECB :
                    key_sz == 24 ? SKE_ALG_AES_192_ECB :
                    key_sz == 16 ? SKE_ALG_AES_128_ECB :
                    0xff);
        break;
    }

    case CRYPTO_ALGOMODE_CBC: {
        hsm_algo = (key_sz == 32 ? SKE_ALG_AES_256_CBC :
                    key_sz == 24 ? SKE_ALG_AES_192_CBC :
                    key_sz == 16 ? SKE_ALG_AES_128_CBC :
                    0xff);
        break;
    }

    case CRYPTO_ALGOMODE_CFB: {
        hsm_algo = (key_sz == 32 ? SKE_ALG_AES_256_CFB :
                    key_sz == 24 ? SKE_ALG_AES_192_CFB :
                    key_sz == 16 ? SKE_ALG_AES_128_CFB :
                    0xff);
        break;
    }

    case CRYPTO_ALGOMODE_OFB: {
        hsm_algo = (key_sz == 32 ? SKE_ALG_AES_256_OFB :
                    key_sz == 24 ? SKE_ALG_AES_192_OFB :
                    key_sz == 16 ? SKE_ALG_AES_128_OFB :
                    0xff);
        break;
    }

    case CRYPTO_ALGOMODE_CTR: {
        hsm_algo = (key_sz == 32 ? SKE_ALG_AES_256_CTR :
                    key_sz == 24 ? SKE_ALG_AES_192_CTR :
                    key_sz == 16 ? SKE_ALG_AES_128_CTR :
                    0xff);
        break;
    }

    case CRYPTO_ALGOMODE_XTS: {
        hsm_algo = (key_sz == 64 ? SKE_ALG_AES_256_XTS :
                    key_sz == 48 ? SKE_ALG_AES_192_XTS :
                    key_sz == 32 ? SKE_ALG_AES_128_XTS :
                    0xff);
        break;
    }

    default:
        break;
    }

    return (hsm_algo);
}

uint32 sm4_algo_mode_mapping(Crypto_AlgorithmModeType autosar_algo)
{
    uint32 hsm_algo = 0xff;

    switch (autosar_algo) {
    case CRYPTO_ALGOMODE_ECB: {
        hsm_algo = SKE_ALG_SM4_ECB;
        break;
    }

    case CRYPTO_ALGOMODE_CBC: {
        hsm_algo = SKE_ALG_SM4_CBC;
        break;
    }

    case CRYPTO_ALGOMODE_CFB: {
        hsm_algo = SKE_ALG_SM4_CFB;
        break;
    }

    case CRYPTO_ALGOMODE_OFB: {
        hsm_algo = SKE_ALG_SM4_OFB;
        break;
    }

    case CRYPTO_ALGOMODE_CTR: {
        hsm_algo = SKE_ALG_SM4_CTR;
        break;
    }

    default:
        break;
    }

    return (hsm_algo);
}

uint32 cmac_algo_mode_mapping(Crypto_AlgorithmFamilyType autosar_algo,
                              uint8 key_sz)
{
    uint32 hsm_algo = 0xff;

    switch (autosar_algo) {
        case CRYPTO_ALGOFAM_AES: {
            hsm_algo = (key_sz == 32 ? CMAC_SKE_ALG_AES_256 :
                        key_sz == 24 ? CMAC_SKE_ALG_AES_192 :
                        key_sz == 16 ? CMAC_SKE_ALG_AES_128 :
                        0xff);
            break;
        }

        default:
            break;
    }

    return (hsm_algo);
}

uint32 hmac_algo_mode_mapping(Crypto_AlgorithmFamilyType autosar_algo)
{
    uint32 hsm_algo = 0xff;

    switch (autosar_algo) {
        case CRYPTO_ALGOFAM_CUSTOM: {
            hsm_algo = HMAC_ALG_SM3;
            break;
        }
        case CRYPTO_ALGOFAM_SHA2_224: {
            hsm_algo = HMAC_ALG_SHA224;
            break;
        }
        case CRYPTO_ALGOFAM_SHA2_256: {
            hsm_algo = HMAC_ALG_SHA256;
            break;
        }
        case CRYPTO_ALGOFAM_SHA2_384: {
            hsm_algo = HMAC_ALG_SHA384;
            break;
        }
        case CRYPTO_ALGOFAM_SHA2_512: {
            hsm_algo = HMAC_ALG_SHA512;
            break;
        }
        default:
            break;
    }

    return (hsm_algo);
}

uint32 hash_algo_mapping(Crypto_AlgorithmFamilyType autosar_algo)
{
    uint32 hsm_algo = 0xff;

    switch (autosar_algo) {
    case CRYPTO_ALGOFAM_SHA2_224: {
        hsm_algo = HASH_ALG_SHA224;
        break;
    }
    case CRYPTO_ALGOFAM_SHA2_256: {
        hsm_algo = HASH_ALG_SHA256;
        break;
    }
    case CRYPTO_ALGOFAM_SHA2_384: {
        hsm_algo = HASH_ALG_SHA384;
        break;
    }
    case CRYPTO_ALGOFAM_SHA2_512: {
        hsm_algo = HASH_ALG_SHA512;
        break;
    }
    case CRYPTO_ALGOFAM_CUSTOM: {
        hsm_algo = HASH_ALG_SM3;
        break;
    }
    default:
        break;
    }

    return (hsm_algo);
}

uint32 get_hash_sz(uint8 alg)
{
    uint32 len = 0UL;
    switch (alg)
    {
    case HASH_ALG_SHA256:
    case HASH_ALG_SM3:
    case HASH_ALG_SHA512_256:
        len = 32U;
        break;
    case HASH_ALG_SHA224:
    case HASH_ALG_SHA512_224:
        len = 28U;
        break;
    case HASH_ALG_SHA384:
        len = 48U;
        break;
    case HASH_ALG_SHA512:
        len = 64U;
        break;
    default:
        break;
    }
    return len;
}

uint32 aead_algo_mode_mapping(Crypto_AlgorithmFamilyType autosar_algo,
                                    uint8 key_sz)
{
    uint32 hsm_algo = 0xff;

    switch (autosar_algo) {
    case CRYPTO_ALGOFAM_AES: {
        hsm_algo = (key_sz == 32 ? SKE_ALG_AES_256_GCM :
                    key_sz == 24 ? SKE_ALG_AES_192_GCM :
                    key_sz == 16 ? SKE_ALG_AES_128_GCM :
                    0xff);
        break;
    }

    case CRYPTO_ALGOFAM_CUSTOM: {
        hsm_algo = SKE_ALG_SM4_GCM;
        break;
    }

    default:
        break;
    }

    return (hsm_algo);
}

FUNC(Std_ReturnType, CRYPTO_CODE) Hsm_host_Aead_Encrypt
(
    Crypto_AlgorithmFamilyType algorithm,
    uint8 key_sz,
    uint8 *msg,
    uint32 msg_sz,
    hsm_keytype key_type,
    const uint8 *key_ptr,
    uint16 key_id,
    uint8 *iv,
    uint32 iv_sz,
    uint8 aad_sz,
    uint8 *cipher,
    uint32 tag_sz,
    gcm_enc_input_ptr_t *cmd_gcm_enc_input,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint16 key_id_array[2];
    uint32 cmd_buf[8];
    uint32 ret;
    cmd_aead_encrypt_gcm_t *cmd_gcm_encrypt = NULL;

    /* Arrays need to be defined first and then assigned initial values to avoid linking to
        rodata section in some compiler */
    key_id_array[0] = 0;
    key_id_array[1] = 0;
    mini_memclr_s(cmd_buf, sizeof(cmd_buf));


    /*********** encrypt ***********/
    cmd_gcm_encrypt = (cmd_aead_encrypt_gcm_t *)cmd_buf;
    cmd_gcm_encrypt->cmd_id = SKE_AEAD_ENCRYPT_GCM;
    cmd_gcm_encrypt->need_seed = 0;
    cmd_gcm_encrypt->mode = aead_algo_mode_mapping(algorithm, key_sz);

    set_big_endian_4byte((uint8 *)cmd_gcm_enc_input->aad_data_ptr,
                         (uint32)soc_to_dma_address((uint32)msg));
    set_big_endian_4byte((uint8 *)cmd_gcm_enc_input->iv_ptr,
                         (uint32)soc_to_dma_address((uint32)iv));
#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
    arch_clean_cache_range(cmd_gcm_enc_input, sizeof(gcm_enc_input_ptr_t));
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */
    set_big_endian_4byte((uint8 *)cmd_gcm_encrypt->gcm_enc_input_ptr,
                         (uint32)soc_to_dma_address((uint32)cmd_gcm_enc_input));
    set_big_endian_2byte((uint8 *)cmd_gcm_encrypt->iv_len, (uint32)iv_sz);
    set_big_endian_2byte((uint8 *)cmd_gcm_encrypt->aad_len, (uint32)aad_sz);
    set_big_endian_4byte((uint8 *)cmd_gcm_encrypt->data_len, (uint32)msg_sz);
    cmd_gcm_encrypt->tag_len = tag_sz;

    if (CMD_KEY_EXTERNAL_PLAINTEXT == key_type) {
#ifdef EXTRA_HSM_KEY_TYPE
        key_id_array[0] = 0;
        key_id_array[1] = 0;
        set_big_endian_4byte((uint8 *)cmd_gcm_encrypt->key_ptr,
                             (uint32)soc_to_dma_address((uint32)key_ptr));
#endif
    }
    else if (CMD_KEY_EXTERNAL_CIPHERTEXT == key_type) {
        key_id_array[0] = 0;
        key_id_array[1] = key_id;
        set_big_endian_4byte((uint8 *)cmd_gcm_encrypt->key_ptr,
                             (uint32)soc_to_dma_address((uint32)key_ptr));
    }
    else if (CMD_KEY_INTERNAL == key_type) {
#ifdef EXTRA_HSM_KEY_TYPE
        key_id_array[0] = key_id;
        key_id_array[1] = 0;
        set_big_endian_4byte((uint8 *)cmd_gcm_encrypt->key_ptr, (uint32)0);
#endif
    }
    else {
        return CMD_RETURN_FAIL;
    }

    set_big_endian_2byte((uint8 *)cmd_gcm_encrypt->key_id0, key_id_array[0]);
    set_big_endian_2byte((uint8 *)cmd_gcm_encrypt->key_id1, key_id_array[1]);
    set_big_endian_4byte((uint8 *)cmd_gcm_encrypt->cipher_tag_ptr,
                         (uint32)soc_to_dma_address((uint32)cipher));

    ret = send_cmd_and_wait_response((uint32 *)cmd_buf, NULL, IsSync);

    if (SEIP_SUCCESS == ret) {
        RetVal = E_OK;
    } else {
        RetVal = E_NOT_OK;
    }

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Hsm_host_Aead_Decrypt
(
    Crypto_AlgorithmFamilyType algorithm,
    uint8 key_sz,
    uint8 *cipher,
    uint32 cipher_sz,
    hsm_keytype key_type,
    const uint8 *key,
    uint16 key_id,
    uint8 *iv,
    uint8 iv_sz,
    uint8 aad_sz,
    uint8 *msg,
    uint8 *tag,
    uint32 tag_sz,
    gcm_dec_input_ptr_t *cmd_gcm_dec_input,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint16 key_id_array[2];
    uint32 cmd_buf[8];
    uint32 ret;
    cmd_aead_decrypt_gcm_t *cmd_gcm_decrypt = NULL;

    /* Arrays need to be defined first and then assigned initial values to avoid linking to
        rodata section in some compiler */
    key_id_array[0] = 0;
    key_id_array[1] = 0;
    mini_memclr_s(cmd_buf, sizeof(cmd_buf));

    /*********** decrypt ***********/
    cmd_gcm_decrypt = (cmd_aead_decrypt_gcm_t *)cmd_buf;
    cmd_gcm_decrypt->cmd_id = SKE_AEAD_DECRYPT_GCM;
    cmd_gcm_decrypt->need_seed = 0;
    cmd_gcm_decrypt->mode = aead_algo_mode_mapping(algorithm, key_sz);

    if (CMD_KEY_EXTERNAL_PLAINTEXT == key_type) {
#ifdef EXTRA_HSM_KEY_TYPE
        key_id_array[0] = 0;
        key_id_array[1] = 0;
        set_big_endian_4byte((uint8 *)cmd_gcm_decrypt->key_ptr,
                             (uint32)soc_to_dma_address((uint32)key));
#endif
    }
    else if (CMD_KEY_EXTERNAL_CIPHERTEXT == key_type) {
        key_id_array[0] = 0;
        key_id_array[1] = key_id;
        set_big_endian_4byte((uint8 *)cmd_gcm_decrypt->key_ptr,
                             (uint32)soc_to_dma_address((uint32)key));
    }
    else if (CMD_KEY_INTERNAL == key_type) {
#ifdef EXTRA_HSM_KEY_TYPE
        key_id_array[0] = key_id;
        key_id_array[1] = 0;
        set_big_endian_4byte((uint8 *)cmd_gcm_decrypt->key_ptr, (uint32)0);
#endif
    }
    else {
        return CMD_RETURN_FAIL;
    }

    set_big_endian_2byte((uint8 *)cmd_gcm_decrypt->key_id0, key_id_array[0]);
    set_big_endian_2byte((uint8 *)cmd_gcm_decrypt->key_id1, key_id_array[1]);

    set_big_endian_4byte((uint8 *)cmd_gcm_dec_input->aad_cipher_ptr,
                         (uint32)soc_to_dma_address((uint32)cipher));
    set_big_endian_4byte((uint8 *)cmd_gcm_dec_input->iv_ptr,
                         (uint32)soc_to_dma_address((uint32)iv));
    set_big_endian_4byte((uint8 *)cmd_gcm_dec_input->tag_ptr,
                         (uint32)soc_to_dma_address((uint32)tag));
#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
    arch_clean_cache_range(cmd_gcm_dec_input, sizeof(gcm_enc_input_ptr_t));
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */
    set_big_endian_4byte((uint8 *)cmd_gcm_decrypt->gcm_dec_input_ptr,
                         (uint32)soc_to_dma_address((uint32)cmd_gcm_dec_input));
    set_big_endian_2byte((uint8 *)cmd_gcm_decrypt->iv_len, (uint32)iv_sz);
    set_big_endian_2byte((uint8 *)cmd_gcm_decrypt->aad_len, (uint32)aad_sz);
    set_big_endian_4byte((uint8 *)cmd_gcm_decrypt->cipher_len, (uint32)cipher_sz);
    cmd_gcm_decrypt->tag_len = tag_sz;
    set_big_endian_4byte((uint8 *)cmd_gcm_decrypt->data_tag_ptr,
                         (uint32)soc_to_dma_address((uint32)msg));

    ret = send_cmd_and_wait_response((uint32 *)cmd_buf, NULL, IsSync);

    if (SEIP_SUCCESS == ret) {
        RetVal = E_OK;
    } else {
        RetVal = E_NOT_OK;
    }

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Hsm_host_Update_Aes
(
    const uint8 *key_ptr,
    hsm_keytype key_type,
    uint16 key_id,
    uint8 key_sz,
    Crypto_AlgorithmModeType algorithm,
    cipher_op_e operation,
    uint8 *iv_ptr,
    uint8 *in_addr,
    uint32 in_sz,
    uint8 *out_addr,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_OK;
    sint32 ret = 0;
    uint32 cmd_buf[8];
    uint16 key_id_array[2];

    cmd_ske_encrypt_t *cmd_encrypt = NULL_PTR;

    /* Arrays need to be defined first and then assigned initial values to avoid linking to
        rodata section in some compiler */
    key_id_array[0] = 0;
    key_id_array[1] = 0;
    mini_memclr_s(cmd_buf, sizeof(cmd_buf));

    cmd_encrypt = (cmd_ske_encrypt_t *)cmd_buf;
    cmd_encrypt->cmd_id = (operation == CIPHER_ENC) ?
                          SKE_ENCRYPT : SKE_DECRYPT;
    cmd_encrypt->need_seed = 0;
    cmd_encrypt->mode = aes_algo_mode_mapping(algorithm, key_sz);

    set_big_endian_4byte(cmd_encrypt->iv_ptr,
                         (uint32)soc_to_dma_address((uint32)iv_ptr));
    set_big_endian_4byte(cmd_encrypt->data_ptr,
                         (uint32)soc_to_dma_address((uint32)in_addr));

    if (CMD_KEY_EXTERNAL_PLAINTEXT == key_type) {
#ifdef EXTRA_HSM_KEY_TYPE
        key_id_array[0] = 0;
        key_id_array[1] = 0;
        set_big_endian_4byte((uint8 *)cmd_encrypt->key_ptr,
                             (uint32)soc_to_dma_address((uint32)key_ptr));
#endif
    }
    else if (CMD_KEY_EXTERNAL_CIPHERTEXT == key_type) {
        key_id_array[0] = 0;
        key_id_array[1] = key_id;
        set_big_endian_4byte((uint8 *)cmd_encrypt->key_ptr,
                             (uint32)soc_to_dma_address((uint32)key_ptr));
    }
    else if (CMD_KEY_INTERNAL == key_type) {
#ifdef EXTRA_HSM_KEY_TYPE
        key_id_array[0] = key_id;
        key_id_array[1] = 0;
        set_big_endian_4byte((uint8 *)cmd_encrypt->key_ptr, (uint32)0);
#endif
    }
    else {
        return CMD_RETURN_FAIL;
    }

    set_big_endian_2byte((uint8 *)cmd_encrypt->key_id0, key_id_array[0]);
    set_big_endian_2byte((uint8 *)cmd_encrypt->key_id1, key_id_array[1]);
    set_big_endian_4byte(cmd_encrypt->data_len, (uint32)in_sz);
    set_big_endian_4byte(cmd_encrypt->cipher_ptr,
                         (uint32)soc_to_dma_address((uint32)out_addr));

    ret = send_cmd_and_wait_response((uint32 *)cmd_buf, NULL, IsSync);

    if (SEIP_SUCCESS == ret) {
        RetVal = E_OK;
    } else {
        RetVal = E_NOT_OK;
    }

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Hsm_host_Update_Sm4
(
    const uint8 *key_ptr,
    hsm_keytype key_type,
    uint16 key_id,
    uint8 key_sz,
    Crypto_AlgorithmModeType algorithm,
    cipher_op_e operation,
    uint8 *iv_ptr,
    uint8 *in_addr,
    uint32 in_sz,
    uint8 *out_addr,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_OK;
    sint32 ret = 0;
    uint32 cmd_buf[8];
    uint16 key_id_array[2];

    /* Arrays need to be defined first and then assigned initial values to avoid linking to
        rodata section in some compiler */
    key_id_array[0] = 0;
    key_id_array[1] = 0;

    cmd_ske_encrypt_t *cmd_encrypt = NULL_PTR;

    mini_memclr_s(cmd_buf, sizeof(cmd_buf));
    cmd_encrypt = (cmd_ske_encrypt_t *)cmd_buf;
    cmd_encrypt->cmd_id = (operation == CIPHER_ENC) ?  SKE_ENCRYPT : SKE_DECRYPT;
    cmd_encrypt->need_seed = 0;
    cmd_encrypt->mode = sm4_algo_mode_mapping(algorithm);

    set_big_endian_4byte(cmd_encrypt->iv_ptr,
                         (uint32)soc_to_dma_address((uint32)iv_ptr));
    set_big_endian_4byte(cmd_encrypt->data_ptr,
                         (uint32)soc_to_dma_address((uint32)in_addr));
    if (CMD_KEY_EXTERNAL_PLAINTEXT == key_type) {
#ifdef EXTRA_HSM_KEY_TYPE
        key_id_array[0] = 0;
        key_id_array[1] = 0;
        set_big_endian_4byte((uint8 *)cmd_encrypt->key_ptr,
                             (uint32)soc_to_dma_address((uint32)key_ptr));
#endif
    }
    else if (CMD_KEY_EXTERNAL_CIPHERTEXT == key_type) {
        key_id_array[0] = 0;
        key_id_array[1] = key_id;
        set_big_endian_4byte((uint8 *)cmd_encrypt->key_ptr,
                             (uint32)soc_to_dma_address((uint32)key_ptr));
    }
    else if (CMD_KEY_INTERNAL == key_type) {
#ifdef EXTRA_HSM_KEY_TYPE
        key_id_array[0] = key_id;
        key_id_array[1] = 0;
        set_big_endian_4byte((uint8 *)cmd_encrypt->key_ptr, (uint32)0);
#endif
    }
    else {
        return CMD_RETURN_FAIL;
    }

    set_big_endian_2byte((uint8 *)cmd_encrypt->key_id0, key_id_array[0]);
    set_big_endian_2byte((uint8 *)cmd_encrypt->key_id1, key_id_array[1]);
    set_big_endian_4byte(cmd_encrypt->data_len, (uint32)in_sz);
    set_big_endian_4byte(cmd_encrypt->cipher_ptr,
                         (uint32)soc_to_dma_address((uint32)out_addr));

    ret = send_cmd_and_wait_response((uint32 *)cmd_buf, NULL, IsSync);

    if (SEIP_SUCCESS == ret) {
        RetVal = E_OK;
    } else {
        RetVal = E_NOT_OK;
    }

    return RetVal;
}

/*PRQA S 2755 2*/
FUNC(Std_ReturnType, CRYPTO_CODE) Hsm_host_Hash
(
    Crypto_AlgorithmFamilyType algorithm,
    const uint8 *Hash_DataAddr,
    uint32 inputLength,
    uint8 *Hash_DigestAddr,
    uint32 *Hash_DigestLenAddr,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_OK;
    sint32 ret = 0;
    /*for seek a cache aligned 32byte buffer*/
    uint32 output_len = 0;
    uint32 hash_algo;
    uint32 cmd_buf[CACHE_LINE*2] = {0};
    cmd_hash_t *cmd_hash = (cmd_hash_t *)ROUNDUP((uint32)cmd_buf, CACHE_LINE);

    /*In and Out addr should 32byte aligned*/
    if ((uint32)Hash_DataAddr % 32 != 0 || (uint32)Hash_DigestAddr % 32 != 0)
        return HSM_ERROR_UNALIGND;

    hash_algo = hash_algo_mapping(algorithm);
    output_len = get_hash_sz(hash_algo);

#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
    arch_clean_cache_range(Hash_DataAddr, inputLength);
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */

    mini_memclr_s(cmd_hash, sizeof(cmd_hash_t));
    cmd_hash->cmd_id = HASH_CALC;
    cmd_hash->mode = hash_algo;

    set_big_endian_4byte(cmd_hash->data_ptr,
                         (uint32)soc_to_dma_address((uint32)Hash_DataAddr));
    set_big_endian_4byte(cmd_hash->data_len, (uint32)inputLength);
    set_big_endian_4byte(cmd_hash->digest_ptr,
                         (uint32)soc_to_dma_address((uint32)Hash_DigestAddr));

#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
    arch_invalidate_cache_range(Hash_DigestAddr, output_len);
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */

    if (Hash_DigestLenAddr)
        *Hash_DigestLenAddr = output_len;
    /*PRQA S 3305 1*/
    ret = send_cmd_and_wait_response((uint32 *)cmd_hash, NULL, IsSync);

    if (SEIP_SUCCESS == ret) {
        RetVal = E_OK;
    } else {
        RetVal = E_NOT_OK;
    }

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Hsm_host_hmac_gen
(
    uint8 mode,
    uint8 *msg,
    uint32 msg_bytes,
    hsm_keytype key_type,
    uint8 *key,
    uint16 key_id,
    uint32 key_bytes,
    uint8 *mac,
    uint8 *mac_buf,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint16 key_id_array[2];
    uint32 cmd_buf[8];
    uint32 ret;
    cmd_generateMAC_t *cmd_generate_hmac = NULL;

    /* Arrays need to be defined first and then assigned initial values to avoid linking to
        rodata section in some compiler */
    key_id_array[0] = 0;
    key_id_array[1] = 0;
    mini_memclr_s(cmd_buf, sizeof(cmd_buf));

    /*********** generate hmac ***********/
    cmd_generate_hmac = (cmd_generateMAC_t *)cmd_buf;
    cmd_generate_hmac->cmd_id = GENERATE_MAC;
    cmd_generate_hmac->mode = mode;

    set_big_endian_4byte((uint8 *)cmd_generate_hmac->data_ptr,
                         (uint32)soc_to_dma_address((uint32)msg));
    set_big_endian_4byte((uint8 *)cmd_generate_hmac->data_len,
                         (uint32)msg_bytes);
    set_big_endian_4byte((uint8 *)cmd_generate_hmac->aut_info_ptr,
                         (uint32)soc_to_dma_address((uint32)mac_buf));

    if (CMD_KEY_EXTERNAL_PLAINTEXT == key_type) {
#ifdef EXTRA_HSM_KEY_TYPE
        key_id_array[0] = 0;
        key_id_array[1] = 0;
        set_big_endian_4byte((uint8 *)cmd_generate_hmac->key_ptr,
                             (uint32)soc_to_dma_address((uint32)key));
#endif
    }
    else if (CMD_KEY_EXTERNAL_CIPHERTEXT == key_type) {
        key_id_array[0] = 0;
        key_id_array[1] = key_id;
        set_big_endian_4byte((uint8 *)cmd_generate_hmac->key_ptr,
                             (uint32)soc_to_dma_address((uint32)key));
    }
    else if (CMD_KEY_INTERNAL == key_type) {
        key_id_array[0] = key_id;
        key_id_array[1] = 0;
        set_big_endian_4byte((uint8 *)cmd_generate_hmac->key_ptr, (uint32)0);
    }
    else {
        return CMD_RETURN_FAIL;
    }

    set_big_endian_2byte((uint8 *)cmd_generate_hmac->key_id0, key_id_array[0]);
    set_big_endian_2byte((uint8 *)cmd_generate_hmac->key_id1, key_id_array[1]);

    set_big_endian_2byte((uint8 *)cmd_generate_hmac->key_len, (uint16)key_bytes);
    set_big_endian_4byte((uint8 *)cmd_generate_hmac->mac_ptr,
                         (uint32)soc_to_dma_address((uint32)mac));

    ret = send_cmd_and_wait_response((uint32 *)cmd_buf, NULL, IsSync);

    if (SEIP_SUCCESS == ret) {
        RetVal = E_OK;
    } else {
        RetVal = E_NOT_OK;
    }

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Hsm_host_hmac_verify
(
    uint8 mode,
    uint8 *msg,
    uint32 msg_bytes,
    hsm_keytype key_type,
    uint8 *key,
    uint16 key_id,
    uint32 key_bytes,
    const uint8 *mac,
    uint8 mac_bytes,
    uint8 *mac_buf,
    Crypto_JobType *job,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint16 key_id_array[2];
    uint32 cmd_buf[8];
    uint32 ret;
    cmd_verifyMAC_t *cmd_verify_hmac = NULL;

    /* Arrays need to be defined first and then assigned initial values to avoid linking to
        rodata section in some compiler */
    key_id_array[0] = 0;
    key_id_array[1] = 0;
    mini_memclr_s(cmd_buf, sizeof(cmd_buf));

    /*********** verify mac ***********/
    cmd_verify_hmac = (cmd_verifyMAC_t *)cmd_buf;
    cmd_verify_hmac->cmd_id = VERIFY_MAC;
    cmd_verify_hmac->mode = mode;
    cmd_verify_hmac->mac_len = mac_bytes;

    set_big_endian_4byte((uint8 *)cmd_verify_hmac->data_ptr,
                         (uint32)soc_to_dma_address((uint32)msg));
    set_big_endian_4byte((uint8 *)cmd_verify_hmac->data_len,
                         (uint32)msg_bytes);
    set_big_endian_4byte((uint8 *)cmd_verify_hmac->aut_info_ptr,
                         (uint32)soc_to_dma_address((uint32)mac_buf));

    if (CMD_KEY_EXTERNAL_PLAINTEXT == key_type) {
#ifdef EXTRA_HSM_KEY_TYPE
        key_id_array[0] = 0;
        key_id_array[1] = 0;
        set_big_endian_4byte((uint8 *)cmd_verify_hmac->key_ptr,
                             (uint32)soc_to_dma_address((uint32)key));
#endif
    }
    else if (CMD_KEY_EXTERNAL_CIPHERTEXT == key_type) {
        key_id_array[0] = 0;
        key_id_array[1] = key_id;
        set_big_endian_4byte((uint8 *)cmd_verify_hmac->key_ptr,
                             (uint32)soc_to_dma_address((uint32)key));
    }
    else if (CMD_KEY_INTERNAL == key_type) {
        key_id_array[0] = key_id;
        key_id_array[1] = 0;
        set_big_endian_4byte((uint8 *)cmd_verify_hmac->key_ptr, (uint32)0);
    }
    else {
        return CMD_RETURN_FAIL;
    }

    set_big_endian_2byte((uint8 *)cmd_verify_hmac->key_id0, key_id_array[0]);
    set_big_endian_2byte((uint8 *)cmd_verify_hmac->key_id1, key_id_array[1]);

    set_big_endian_2byte((uint8 *)cmd_verify_hmac->key_len, (uint16)key_bytes);
    set_big_endian_4byte((uint8 *)cmd_verify_hmac->mac_ptr,
                         (uint32)soc_to_dma_address((uint32)mac));

    ret = send_cmd_and_wait_response((uint32 *)cmd_buf, job, IsSync);

    if (SEIP_SUCCESS == ret) {
        RetVal = E_OK;
    } else {
        RetVal = E_NOT_OK;
    }

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Hsm_host_cmac_gen
(
    uint8 mode,
    uint8 *msg,
    uint32 msg_bytes,
    hsm_keytype key_type,
    uint8 *key,
    uint16 key_id,
    uint8 *mac,
    uint8 *mac_buf,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint16 key_id_array[2];
    uint32 cmd_buf[8];
    uint32 ret;
    cmd_generateMAC_t *cmd_generate_ske_mac = NULL;

    /* Arrays need to be defined first and then assigned initial values to avoid linking to
        rodata section in some compiler */
    key_id_array[0] = 0;
    key_id_array[1] = 0;
    mini_memclr_s(cmd_buf, sizeof(cmd_buf));

    /*********** generate ske mac ***********/
    cmd_generate_ske_mac = (cmd_generateMAC_t *)cmd_buf;

    cmd_generate_ske_mac->cmd_id = GENERATE_MAC;
    cmd_generate_ske_mac->need_seed = 0;
    cmd_generate_ske_mac->mode = mode;

    set_big_endian_4byte((uint8 *)cmd_generate_ske_mac->aut_info_ptr,
                         (uint32)soc_to_dma_address((uint32)mac_buf));

    set_big_endian_4byte((uint8 *)cmd_generate_ske_mac->data_ptr,
                         (uint32)soc_to_dma_address((uint32)msg));
    set_big_endian_4byte((uint8 *)cmd_generate_ske_mac->data_len,
                         (uint32)msg_bytes);

    if (CMD_KEY_EXTERNAL_PLAINTEXT == key_type) {
#ifdef EXTRA_HSM_KEY_TYPE
        key_id_array[0] = 0;
        key_id_array[1] = 0;
        set_big_endian_4byte((uint8 *)cmd_generate_ske_mac->key_ptr,
                             (uint32)soc_to_dma_address((uint32)key));
#endif
    }
    else if (CMD_KEY_EXTERNAL_CIPHERTEXT == key_type) {
        key_id_array[0] = 0;
        key_id_array[1] = key_id;
        set_big_endian_4byte((uint8 *)cmd_generate_ske_mac->key_ptr,
                             (uint32)soc_to_dma_address((uint32)key));
    }
    else if (CMD_KEY_INTERNAL == key_type) {
#ifdef EXTRA_HSM_KEY_TYPE
        key_id_array[0] = key_id;
        key_id_array[1] = 0;
        set_big_endian_4byte((uint8 *)cmd_generate_ske_mac->key_ptr, (uint32)0);
#endif
    }
    else {
        return CMD_RETURN_FAIL;
    }

    set_big_endian_2byte((uint8 *)cmd_generate_ske_mac->key_id0, key_id_array[0]);
    set_big_endian_2byte((uint8 *)cmd_generate_ske_mac->key_id1, key_id_array[1]);
    set_big_endian_4byte((uint8 *)cmd_generate_ske_mac->mac_ptr,
                         (uint32)soc_to_dma_address((uint32)mac));

    ret = send_cmd_and_wait_response((uint32 *)cmd_buf, NULL, IsSync);

    if (SEIP_SUCCESS == ret) {
        RetVal = E_OK;
    } else {
        RetVal = E_NOT_OK;
    }

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Hsm_host_cmac_verify
(
    uint8 mode, uint8 *msg,
    uint32 msg_bytes,
    hsm_keytype key_type,
    uint8 *key,
    uint16 key_id,
    const uint8 *mac,
    uint8 mac_bytes,
    uint8 *mac_buf,
    Crypto_JobType *job,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint16 key_id_array[2];
    uint32 cmd_buf[8];
    uint32 ret;
    cmd_verifyMAC_t *cmd_verify_ske_mac = NULL;

    /* Arrays need to be defined first and then assigned initial values to avoid linking to
        rodata section in some compiler */
    key_id_array[0] = 0;
    key_id_array[1] = 0;
    mini_memclr_s(cmd_buf, sizeof(cmd_buf));

    /*********** generate ske mac ***********/
    cmd_verify_ske_mac = (cmd_verifyMAC_t *)cmd_buf;

    cmd_verify_ske_mac->cmd_id = VERIFY_MAC;
    cmd_verify_ske_mac->need_seed = 0;
    cmd_verify_ske_mac->mode = mode;
    cmd_verify_ske_mac->mac_len = mac_bytes;
    set_big_endian_4byte((uint8 *)cmd_verify_ske_mac->aut_info_ptr,
                         (uint32)soc_to_dma_address((uint32)mac_buf));
    set_big_endian_4byte((uint8 *)cmd_verify_ske_mac->data_ptr,
                         (uint32)soc_to_dma_address((uint32)msg));
    set_big_endian_4byte((uint8 *)cmd_verify_ske_mac->data_len, (uint32)msg_bytes);

    if (CMD_KEY_EXTERNAL_PLAINTEXT == key_type) {
#ifdef EXTRA_HSM_KEY_TYPE
        key_id_array[0] = 0;
        key_id_array[1] = 0;
        set_big_endian_4byte((uint8 *)cmd_verify_ske_mac->key_ptr,
                             (uint32)soc_to_dma_address((uint32)key));
#endif
    }
    else if (CMD_KEY_EXTERNAL_CIPHERTEXT == key_type) {
        key_id_array[0] = 0;
        key_id_array[1] = key_id;
        set_big_endian_4byte((uint8 *)cmd_verify_ske_mac->key_ptr,
                             (uint32)soc_to_dma_address((uint32)key));
    }
    else if (CMD_KEY_INTERNAL == key_type) {
#ifdef EXTRA_HSM_KEY_TYPE
        key_id_array[0] = key_id;
        key_id_array[1] = 0;
        set_big_endian_4byte((uint8 *)cmd_verify_ske_mac->key_ptr, (uint32)0);
#endif
    }
    else {
        return CMD_RETURN_FAIL;
    }

    set_big_endian_2byte((uint8 *)cmd_verify_ske_mac->key_id0, key_id_array[0]);
    set_big_endian_2byte((uint8 *)cmd_verify_ske_mac->key_id1, key_id_array[1]);
    set_big_endian_4byte((uint8 *)cmd_verify_ske_mac->mac_ptr,
                         (uint32)soc_to_dma_address((uint32)mac));

    ret = send_cmd_and_wait_response((uint32 *)cmd_buf, job, IsSync);

    if (SEIP_SUCCESS == ret) {
        RetVal = E_OK;
    } else {
        RetVal = E_NOT_OK;
    }

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Hsm_host_RsaEncrypt
(
    uint8 *n,
    uint8 *e,
    uint32 Modulus_Size,
    const uint8 *msg,
    uint8 *cipher,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint32 cmd_buf[8] = {0};
    uint32 ret = 0;
    cmd_rsa_encrypt_t *cmd_rsa_enc = NULL;
    uint32 nbitlen;

    /*********** encrypt ***********/
    cmd_rsa_enc = (cmd_rsa_encrypt_t *)cmd_buf;
    cmd_rsa_enc->cmd_id = RSA_ENCRYPT;
    nbitlen = Modulus_Size << 3;

    set_big_endian_4byte((uint8 *)cmd_rsa_enc->data_ptr,
                         (uint32)soc_to_dma_address((uint32)msg));
    set_big_endian_4byte((uint8 *)cmd_rsa_enc->e_ptr,
                         (uint32)soc_to_dma_address((uint32)e));
    set_big_endian_4byte((uint8 *)cmd_rsa_enc->cipher_ptr,
                         (uint32)soc_to_dma_address((uint32)cipher));
    set_big_endian_4byte((uint8 *)cmd_rsa_enc->n_ptr,
                         (uint32)soc_to_dma_address((uint32)n));
    set_big_endian_2byte((uint8 *)cmd_rsa_enc->n_len,
                         (uint32)nbitlen);

    ret = send_cmd_and_wait_response((uint32 *)cmd_buf, NULL, IsSync);

    if (SEIP_SUCCESS == ret) {
        RetVal = E_OK;
    } else {
        RetVal = E_NOT_OK;
    }

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Hsm_host_RsaDecrypt
(
    const uint8 *msg,
    uint8 *n,
    uint8 *e,
    uint8 *d,
    uint32 Modulus_Size,
    uint8 *out,
    hsm_keytype decrypt_key_type,
    uint16 decrypt_key_id,
    uint8 *mac_buf,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint16 key_id_array[2];
    uint32 cmd_buf[8];
    uint32 ret = 0;
    cmd_rsa_decrypt_t *cmd_rsa_dec = NULL;
    uint32 nbitlen;

    /* Arrays need to be defined first and then assigned initial values to avoid linking to
        rodata section in some compiler */
    key_id_array[0] = 0;
    key_id_array[1] = 0;
    mini_memclr_s(cmd_buf, sizeof(cmd_buf));

    /*********** decrypt ***********/
    cmd_rsa_dec = (cmd_rsa_decrypt_t *)cmd_buf;
    cmd_rsa_dec->cmd_id = RSA_DECRYPT;

    nbitlen = Modulus_Size << 3;

    cmd_rsa_dec->need_high_sec_ver = 0;

    set_big_endian_4byte((uint8 *)cmd_rsa_dec->data_ptr,
                         (uint32)soc_to_dma_address((uint32)msg));
    set_big_endian_4byte((uint8 *)cmd_rsa_dec->e_ptr,
                         (uint32)soc_to_dma_address((uint32)e));
    set_big_endian_4byte((uint8 *)cmd_rsa_dec->cipher_ptr,
                         (uint32)soc_to_dma_address((uint32)out));
    set_big_endian_4byte((uint8 *)cmd_rsa_dec->d_ptr,
                         (uint32)soc_to_dma_address((uint32)d));

    if (CMD_KEY_EXTERNAL_PLAINTEXT == decrypt_key_type) {
#ifdef EXTRA_HSM_KEY_TYPE
        key_id_array[0] = 0;
#endif
    }
    else if (CMD_KEY_EXTERNAL_CIPHERTEXT == decrypt_key_type) {
        key_id_array[0] = decrypt_key_id;
    }
    else {
        return RetVal;
    }

    set_big_endian_2byte((uint8 *)cmd_rsa_dec->key_id, key_id_array[0]);
    set_big_endian_4byte((uint8 *)cmd_rsa_dec->n_ptr,
                         (uint32)soc_to_dma_address((uint32)n));
    set_big_endian_2byte((uint8 *)cmd_rsa_dec->n_len, (uint32)nbitlen);
    set_big_endian_4byte((uint8 *)cmd_rsa_dec->aut_info_ptr,
                         (uint32)soc_to_dma_address((uint32)mac_buf));

    ret = send_cmd_and_wait_response((uint32 *)cmd_buf, NULL, IsSync);

    if (SEIP_SUCCESS == ret) {
        RetVal = E_OK;
    } else {
        RetVal = E_NOT_OK;
    }

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Hsm_host_Sign_Rsa
(
    uint8 *msg,
    uint8 *n,
    uint8 *e,
    uint8 *d,
    uint32 Modulus_Size,
    uint8 *out,
    hsm_keytype sign_key_type,
    uint16 sign_key_id,
    uint8 *mac_buf,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint16 key_id_array[2];
    uint32 cmd_buf[8];
    uint32 ret = 0;
    cmd_rsa_generate_signature_t *cmd_rsa_sign = NULL;
    uint32 nbitlen;

    /* Arrays need to be defined first and then assigned initial values to avoid linking to
        rodata section in some compiler */
    key_id_array[0] = 0;
    key_id_array[1] = 0;
    mini_memclr_s(cmd_buf, sizeof(cmd_buf));

    /*********** sign ***********/
    cmd_rsa_sign = (cmd_rsa_generate_signature_t *)cmd_buf;
    cmd_rsa_sign->cmd_id = RSA_GENERATE_SIGNATURE;

    /* if set 1, must set e value*/
    cmd_rsa_sign->need_high_sec_ver = 0;
    nbitlen = Modulus_Size << 3;

    set_big_endian_4byte((uint8 *)cmd_rsa_sign->data_ptr,
                         (uint32)soc_to_dma_address((uint32)msg));
    set_big_endian_4byte((uint8 *)cmd_rsa_sign->e_ptr,
                         (uint32)soc_to_dma_address((uint32)e));
    set_big_endian_4byte((uint8 *)cmd_rsa_sign->signature_ptr,
                         (uint32)soc_to_dma_address((uint32)out));

    if (CMD_KEY_EXTERNAL_PLAINTEXT == sign_key_type) {
#ifdef EXTRA_HSM_KEY_TYPE
        key_id_array[0] = 0;
#endif
    }
    else if (CMD_KEY_EXTERNAL_CIPHERTEXT == sign_key_type) {
        key_id_array[0] = sign_key_id;
    }
    else {
        return CMD_RETURN_FAIL;
    }

    set_big_endian_4byte((uint8 *)cmd_rsa_sign->d_ptr,
                         (uint32)soc_to_dma_address((uint32)d));
    set_big_endian_2byte((uint8 *)cmd_rsa_sign->key_id, key_id_array[0]);
    set_big_endian_4byte((uint8 *)cmd_rsa_sign->n_ptr,
                         (uint32)soc_to_dma_address((uint32)n));
    set_big_endian_2byte((uint8 *)cmd_rsa_sign->n_len, (uint32)nbitlen);
    set_big_endian_4byte((uint8 *)cmd_rsa_sign->aut_info_ptr,
                         (uint32)soc_to_dma_address((uint32)mac_buf));

    ret = send_cmd_and_wait_response((uint32 *)cmd_buf, NULL, IsSync);

    if (SEIP_SUCCESS == ret) {
        RetVal = E_OK;
    } else {
        RetVal = E_NOT_OK;
    }

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Hsm_host_Verify_Rsa
(
    uint8 *msg,
    uint8 *n,
    uint8 *e,
    uint32 Modulus_Size,
    const uint8 *signature,
    Crypto_JobType *job,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint32 cmd_buf[8] = {0};
    uint32 ret = 0;
    cmd_rsa_verify_t *cmd_rsa_verify = NULL;
    uint32 nbitlen;

    /*********** verify ***********/
    cmd_rsa_verify = (cmd_rsa_verify_t *)cmd_buf;
    cmd_rsa_verify->cmd_id = RSA_VERIFY_SIGNATURE;

    nbitlen = Modulus_Size << 3;

    set_big_endian_4byte((uint8 *)cmd_rsa_verify->data_ptr,
                         (uint32)soc_to_dma_address((uint32)msg));
    set_big_endian_4byte((uint8 *)cmd_rsa_verify->e_ptr,
                         (uint32)soc_to_dma_address((uint32)e));
    set_big_endian_4byte((uint8 *)cmd_rsa_verify->signature_ptr,
                         (uint32)soc_to_dma_address((uint32)signature));
    set_big_endian_4byte((uint8 *)cmd_rsa_verify->n_ptr,
                         (uint32)soc_to_dma_address((uint32)n));
    set_big_endian_2byte((uint8 *)cmd_rsa_verify->n_len, (uint32)nbitlen);

    ret = send_cmd_and_wait_response((uint32 *)cmd_buf, job, IsSync);

    if (SEIP_SUCCESS == ret) {
        RetVal = E_OK;
    } else {
        RetVal = E_NOT_OK;
    }

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Hsm_host_Sm2_Encrypt
(
    uint8 *msg,
    uint32 msg_len,
    uint8 *pubkey,
    uint8 *cipher,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint32 cmd_buf[8] = {0};
    uint32 ret = 0;
    uint8 count;
    cmd_sm2_encrypt_t *cmd_encrypt = NULL;

    /*********** encryption ***********/
    cmd_encrypt = (cmd_sm2_encrypt_t *)cmd_buf;
    cmd_encrypt->cmd_id = SM2_ENCRYPT;
    cmd_encrypt->need_high_sec_ver = 0;

    set_big_endian_4byte((uint8 *)cmd_encrypt->data_ptr,
                         (uint32)soc_to_dma_address((uint32)msg));
    set_big_endian_4byte((uint8 *)cmd_encrypt->data_len, (uint32)msg_len);
    set_big_endian_4byte((uint8 *)cmd_encrypt->pubKey_ptr,
                         (uint32)soc_to_dma_address((uint32)pubkey));
    set_big_endian_4byte((uint8 *)cmd_encrypt->cipher_ptr,
                         (uint32)soc_to_dma_address((uint32)cipher));

    count = RETRY_COUNT;
    do {
        ret = send_cmd_and_wait_response((uint32 *)cmd_buf, NULL, IsSync);
        if (CRYPTO_PROCESSING_ASYNC == IsSync) {
            RetVal = E_OK;
            break;
        } else {
            uint32 tmp;
            mini_memcpy_s(&tmp, cipher, 4);
            if ((SEIP_SUCCESS == ret) && (tmp != 0)) {
                RetVal = E_OK;
                break;
            } else if (SEIP_ERROR_SM2_ENCRYPT_FAIL == ret) {
                RetVal = E_NOT_OK;
                /* retry */
            } else {
                RetVal = E_NOT_OK;
                break;
            }
        }
        count--;
    } while (count);

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Hsm_host_Sm2_Decrypt
(
    uint8 *msg,
    uint8 *prikey,
    uint8 *cipher,
    uint32 cipher_len,
    hsm_keytype decrypt_key_type,
    uint16 decrypt_key_id,
    uint8 *mac_buf,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint16 key_id_array[2];
    uint32 cmd_buf[8];
    uint32 ret = 0;
    cmd_sm2_decrypt_t *cmd_decrypt = NULL;

    /* Arrays need to be defined first and then assigned initial values to avoid linking to
        rodata section in some compiler */
    key_id_array[0] = 0;
    key_id_array[1] = 0;
    mini_memclr_s(cmd_buf, sizeof(cmd_buf));

    /*********** decryption ***********/
    cmd_decrypt = (cmd_sm2_decrypt_t *)cmd_buf;
    cmd_decrypt->cmd_id = SM2_DECRYPT;

    cmd_decrypt->need_high_sec_ver = 0;

    set_big_endian_4byte((uint8 *)cmd_decrypt->cipher_ptr,
                         (uint32)soc_to_dma_address((uint32)cipher));
    set_big_endian_4byte((uint8 *)cmd_decrypt->cipher_len, cipher_len);

    if (CMD_KEY_EXTERNAL_PLAINTEXT == decrypt_key_type) {
#ifdef EXTRA_HSM_KEY_TYPE
        set_big_endian_4byte((uint8 *)cmd_decrypt->priKey_ptr,
                             (uint32)soc_to_dma_address((uint32)prikey));
        key_id_array[0] = 0;
        key_id_array[1] = 0;
#endif
    }
    else if (CMD_KEY_EXTERNAL_CIPHERTEXT == decrypt_key_type) {
        set_big_endian_4byte((uint8 *)cmd_decrypt->priKey_ptr,
                             (uint32)soc_to_dma_address((uint32)prikey));
        key_id_array[0] = 0;
        key_id_array[1] = decrypt_key_id;
    }
    else if (CMD_KEY_INTERNAL == decrypt_key_type) {
#ifdef EXTRA_HSM_KEY_TYPE
        set_big_endian_4byte((uint8 *)cmd_decrypt->priKey_ptr, 0);
        key_id_array[0] = decrypt_key_id;
        key_id_array[1] = 0;
#endif
    }

    set_big_endian_2byte((uint8 *)cmd_decrypt->key_id0, key_id_array[0]);
    set_big_endian_2byte((uint8 *)cmd_decrypt->key_id1, key_id_array[1]);
    set_big_endian_4byte((uint8 *)cmd_decrypt->data_ptr,
                         (uint32)soc_to_dma_address((uint32)msg));
    set_big_endian_4byte((uint8 *)cmd_decrypt->aut_info_ptr,
                         (uint32)soc_to_dma_address((uint32)mac_buf));

    ret = send_cmd_and_wait_response((uint32 *)cmd_buf, NULL, IsSync);
    if (CRYPTO_PROCESSING_ASYNC == IsSync) {
        return E_OK;
    } else {
        uint32 tmp;
        mini_memcpy_s(&tmp, cipher, 4);
        if ((SEIP_SUCCESS == ret) && (tmp != 0)) {
            RetVal = E_OK;
        } else {
            RetVal = E_NOT_OK;
        }
    }

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Hsm_host_Sign_Sm2
(
    uint8 *e,
    uint8 *prikey,
    hsm_keytype sign_key_type,
    uint16 sign_key_id,
    uint8 *signature,
    uint8 *mac_buf,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint16 key_id_array[2];
    uint32 cmd_buf[8];
    uint32 ret = 0;
    uint8 count;
    cmd_sm2_generatesignature_t *cmd_gen_signature = NULL;

    /* Arrays need to be defined first and then assigned initial values to avoid linking to
        rodata section in some compiler */
    key_id_array[0] = 0;
    key_id_array[1] = 0;
    mini_memclr_s(cmd_buf, sizeof(cmd_buf));

    /*********** generate signature ***********/
    cmd_gen_signature = (cmd_sm2_generatesignature_t *)cmd_buf;
    cmd_gen_signature->cmd_id = SM2_GENERATE_SIGNATURE;

    cmd_gen_signature->need_high_sec_ver = 0;

    set_big_endian_4byte((uint8 *)cmd_gen_signature->e_ptr,
                         (uint32)soc_to_dma_address((uint32)e));

    if (CMD_KEY_EXTERNAL_PLAINTEXT == sign_key_type) {
 #ifdef EXTRA_HSM_KEY_TYPE
        set_big_endian_4byte((uint8 *)cmd_gen_signature->priKey_ptr,
                             (uint32)soc_to_dma_address((uint32)prikey));
        key_id_array[0] = 0;
        key_id_array[1] = 0;
#endif
    }
    else if (CMD_KEY_EXTERNAL_CIPHERTEXT == sign_key_type) {
        set_big_endian_4byte((uint8 *)cmd_gen_signature->priKey_ptr,
                             (uint32)soc_to_dma_address((uint32)prikey));
        key_id_array[0] = 0;
        key_id_array[1] = sign_key_id;
    }
    else if (CMD_KEY_INTERNAL == sign_key_type) {
#ifdef EXTRA_HSM_KEY_TYPE
        set_big_endian_4byte((uint8 *)cmd_gen_signature->priKey_ptr, 0);
        key_id_array[0] = sign_key_id;
        key_id_array[1] = 0;
#endif
    }

    set_big_endian_2byte((uint8 *)cmd_gen_signature->key_id0, key_id_array[0]);
    set_big_endian_2byte((uint8 *)cmd_gen_signature->key_id1, key_id_array[1]);
    set_big_endian_4byte((uint8 *)cmd_gen_signature->signature_ptr,
                         (uint32)soc_to_dma_address((uint32)signature));
    set_big_endian_4byte((uint8 *)cmd_gen_signature->aut_info_ptr,
                         (uint32)soc_to_dma_address((uint32)mac_buf));

    count = RETRY_COUNT;
    do {
        ret = send_cmd_and_wait_response((uint32 *)cmd_buf, NULL, IsSync);
        if (CRYPTO_PROCESSING_ASYNC == IsSync) {
            RetVal = E_OK;
            break;
        } else {
            uint32 tmp;
            mini_memcpy_s(&tmp, signature, 4);
            if ((SEIP_SUCCESS == ret) && (tmp != 0)) {
                RetVal = E_OK;
                break;
            } else if (SEIP_ERROR_SM2_SIGN_FAIL == ret) {
                RetVal = E_NOT_OK;
                /* retry */
            } else {
                RetVal = E_NOT_OK;
                break;
            }
        }

        count--;
    } while (count);

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Hsm_host_Verify_Sm2
(
    uint8 *e,
    uint8 *pubkey,
    uint8 *signature,
    Crypto_JobType *job,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint32 cmd_buf[8] = {0};
    uint32 ret = 0;
    cmd_sm2_verifysignature_t *cmd_verify_signature = NULL;

    /*********** verify signature ***********/
    cmd_verify_signature = (cmd_sm2_verifysignature_t *)cmd_buf;
    cmd_verify_signature->cmd_id = SM2_VERIFY_SIGNATURE;

    cmd_verify_signature->need_high_sec_ver = 0;

    set_big_endian_4byte((uint8 *)cmd_verify_signature->e_ptr,
                         (uint32)soc_to_dma_address((uint32)e));
    set_big_endian_4byte((uint8 *)cmd_verify_signature->pubKey_ptr,
                         (uint32)soc_to_dma_address((uint32)pubkey));
    set_big_endian_4byte((uint8 *)cmd_verify_signature->signature_ptr,
                         (uint32)soc_to_dma_address((uint32)signature));
    ret = send_cmd_and_wait_response((uint32 *)cmd_buf, job, IsSync);

    if (SEIP_SUCCESS == ret) {
        RetVal = E_OK;
    } else {
        RetVal = E_NOT_OK;
    }

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Hsm_host_Sign_Ecdsa
(
    uint8 curve_id,
    uint8 *e,
    uint32 e_len,
    hsm_keytype sign_key_type,
    uint16 sign_key_id,
    uint8 *prikey,
    uint8 *signature,
    uint8 *mac_buf,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint16 key_id_array[2];
    uint32 cmd_buf[8];
    uint32 ret = 0;
    uint8 count;
    cmd_ecdsa_generate_signature_t *cmd_ecdsa_sign = NULL;

    /* Arrays need to be defined first and then assigned initial values to avoid linking to
        rodata section in some compiler */
    key_id_array[0] = 0;
    key_id_array[1] = 0;
    mini_memclr_s(cmd_buf, sizeof(cmd_buf));

    /*********** ecdsa sign ***********/
    cmd_ecdsa_sign = (cmd_ecdsa_generate_signature_t *)cmd_buf;
    cmd_ecdsa_sign->cmd_id = ECDSA_GENERATE_SIGNATURE;

    cmd_ecdsa_sign->curve_id = curve_id;
    cmd_ecdsa_sign->e_len = e_len;
    set_big_endian_4byte((uint8 *)cmd_ecdsa_sign->e_ptr,
                         (uint32)soc_to_dma_address((uint32)e));
    set_big_endian_4byte((uint8 *)cmd_ecdsa_sign->aut_info_ptr,
                         (uint32)soc_to_dma_address((uint32)mac_buf));

    if (CMD_KEY_EXTERNAL_PLAINTEXT == sign_key_type) {
#ifdef EXTRA_HSM_KEY_TYPE
        key_id_array[0] = 0;
        key_id_array[1] = 0;
        set_big_endian_4byte((uint8 *)cmd_ecdsa_sign->priKey_ptr,
                             (uint32)soc_to_dma_address((uint32)prikey));
#endif
    }
    else if (CMD_KEY_EXTERNAL_CIPHERTEXT == sign_key_type) {
        key_id_array[0] = 0;
        key_id_array[1] = sign_key_id;
        set_big_endian_4byte((uint8 *)cmd_ecdsa_sign->priKey_ptr,
                             (uint32)soc_to_dma_address((uint32)prikey));
    }
    else if (CMD_KEY_INTERNAL == sign_key_type) {
#ifdef EXTRA_HSM_KEY_TYPE
        set_big_endian_4byte((uint8 *)cmd_ecdsa_sign->priKey_ptr, 0);
        key_id_array[0] = sign_key_id;
        key_id_array[1] = 0;
#endif
    }
    else {
        return CMD_RETURN_FAIL;
    }

    set_big_endian_2byte((uint8 *)cmd_ecdsa_sign->key_id0, key_id_array[0]);
    set_big_endian_2byte((uint8 *)cmd_ecdsa_sign->key_id1, key_id_array[1]);
    set_big_endian_4byte((uint8 *)cmd_ecdsa_sign->signature_ptr,
                         (uint32)soc_to_dma_address((uint32)signature));

    count = RETRY_COUNT;
    do {
        ret = send_cmd_and_wait_response((uint32 *)cmd_buf, NULL, IsSync);
        if (SEIP_SUCCESS == ret) {
            RetVal = E_OK;
            break;
        } else if (SEIP_ERROR_ECDSA_VERIFY_FAIL == ret) {
            RetVal = E_NOT_OK;
            /* retry */
        } else {
            RetVal = E_NOT_OK;
            break;
        }

        count--;
    } while (count);

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Hsm_host_Verify_Ecdsa
(
    uint8 curve_id,
    uint8 *e,
    uint32 e_len,
    uint8 *pubkey,
    uint8 *signature,
    Crypto_JobType *job,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint32 cmd_buf[8] = {0};
    uint32 ret = 0;
    cmd_ecdsa_verify_signature_t *cmd_ecdsa_verify = NULL;

    /*********** ecdsa verify ***********/
    cmd_ecdsa_verify = (cmd_ecdsa_verify_signature_t *)cmd_buf;
    cmd_ecdsa_verify->cmd_id = ECDSA_VERIFY_SIGNATURE;

    cmd_ecdsa_verify->curve_id = curve_id;
    cmd_ecdsa_verify->e_len = e_len;
    set_big_endian_4byte((uint8 *)cmd_ecdsa_verify->e_ptr,
                         (uint32)soc_to_dma_address((uint32)e));
    set_big_endian_4byte((uint8 *)cmd_ecdsa_verify->pubKey_ptr,
                         (uint32)soc_to_dma_address((uint32)pubkey));
    set_big_endian_4byte((uint8 *)cmd_ecdsa_verify->signature_ptr,
                         (uint32)soc_to_dma_address((uint32)signature));

    ret = send_cmd_and_wait_response((uint32 *)cmd_buf, job, IsSync);

    if (SEIP_SUCCESS == ret) {
        RetVal = E_OK;
    } else {
        RetVal = E_NOT_OK;
    }

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Hsm_host_encrypt_key
(
    const uint8 *key_plain,
    uint32 key_plain_bytes,
    uint16 kek_keyid,
    const uint8 *key_cipher,
    Crypto_ProcessingType IsSync
)
{
    uint16 key_id_array[2];
    uint32 ret;
    uint32 cmd_buf[8];
    Std_ReturnType RetVal = E_NOT_OK;

    cmd_ske_encrypt_t *cmd_encrypt = NULL;

    /* Arrays need to be defined first and then assigned initial values to avoid linking to
        rodata section in some compiler */
    key_id_array[0] = 0;
    key_id_array[1] = 0;
    mini_memclr_s(cmd_buf, sizeof(cmd_buf));

    if (key_plain_bytes & 0x0F) {
        key_plain_bytes += 16 - (key_plain_bytes & 0x0F);
    }
    else
    {;}

    /*********** encrypt ***********/
    cmd_encrypt = (cmd_ske_encrypt_t *)cmd_buf;
    cmd_encrypt->cmd_id = SKE_ENCRYPT;
    cmd_encrypt->need_seed = 0;
    cmd_encrypt->mode = SKE_ALG_SM4_ECB;

    set_big_endian_4byte((uint8 *)cmd_encrypt->iv_ptr, 0x0);
    set_big_endian_4byte((uint8 *)cmd_encrypt->data_ptr,
						 (uint32)soc_to_dma_address((uint32)key_plain));
    set_big_endian_4byte((uint8 *)cmd_encrypt->data_len, key_plain_bytes);

    key_id_array[0] = kek_keyid;
    key_id_array[1] = 0;
    set_big_endian_4byte((uint8 *)cmd_encrypt->key_ptr, (uint32)0);

    set_big_endian_2byte((uint8 *)cmd_encrypt->key_id0, key_id_array[0]);
    set_big_endian_2byte((uint8 *)cmd_encrypt->key_id1, key_id_array[1]);
    set_big_endian_4byte((uint8 *)cmd_encrypt->cipher_ptr,
						 (uint32)soc_to_dma_address((uint32)key_cipher));

    ret = send_cmd_and_wait_response((uint32 *)cmd_buf, NULL, IsSync);

    if (SEIP_SUCCESS == ret) {
        RetVal = E_OK;
    } else {
        RetVal = E_NOT_OK;
    }

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Hsm_host_decrypt_key
(
    uint8 *key_cipher,
    uint32 key_plain_bytes,
    uint16 kek_keyid,
    uint8 *key_plain,
    Crypto_ProcessingType IsSync
)
{
    uint32 ret;
    uint16 key_id_array[2];
    uint32 cmd_buf[8];

    cmd_ske_decrypt_t *cmd_decrypt = NULL;
    Std_ReturnType RetVal = E_NOT_OK;

    /* Arrays need to be defined first and then assigned initial values to avoid linking to
        rodata section in some compiler */
    key_id_array[0] = 0;
    key_id_array[1] = 0;
    mini_memclr_s(cmd_buf, sizeof(cmd_buf));

    if (key_plain_bytes & 0x0F) {
        key_plain_bytes += 16 - (key_plain_bytes & 0x0F);
    }
    else
    {;}

    /*********** decrypt ***********/
    cmd_decrypt = (cmd_ske_decrypt_t *)cmd_buf;
    cmd_decrypt->cmd_id = SKE_DECRYPT;
    cmd_decrypt->need_seed = 0;
    cmd_decrypt->mode = SKE_ALG_SM4_ECB;

    set_big_endian_4byte((uint8 *)cmd_decrypt->iv_ptr, 0x0);
    set_big_endian_4byte((uint8 *)cmd_decrypt->cipher_ptr,
						 (uint32)soc_to_dma_address((uint32)key_cipher));
    set_big_endian_4byte((uint8 *)cmd_decrypt->cipher_len, (uint32)key_plain_bytes);
    /*the key paras keep the same as the encrypt test.*/

    key_id_array[0] = kek_keyid;
    key_id_array[1] = 0;
    set_big_endian_4byte((uint8 *)cmd_decrypt->key_ptr, (uint32)0);

    set_big_endian_2byte((uint8 *)cmd_decrypt->key_id0, key_id_array[0]);
    set_big_endian_2byte((uint8 *)cmd_decrypt->key_id1, key_id_array[1]);

    set_big_endian_4byte((uint8 *)cmd_decrypt->data_ptr,
						 (uint32)soc_to_dma_address((uint32)key_plain));

    ret = send_cmd_and_wait_response((uint32 *)cmd_buf, NULL, IsSync);

    if (SEIP_SUCCESS == ret) {
        RetVal = E_OK;
    } else {
        RetVal = E_NOT_OK;
    }

    return RetVal;
}
/*gen 256bit key , output be enc by key_id*/
FUNC(Std_ReturnType, CRYPTO_CODE) Hsm_host_GenerateKey
(
    uint16 key_id,
    uint8 *key,
    uint32 key_size,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint32 cmd_buf[8] = {0};
    uint32 ret;
    cmd_generate_key_t *cmd_get_key = NULL;

    cmd_get_key = (cmd_generate_key_t *)cmd_buf;
    cmd_get_key->cmd_id = GENERATE_KEY;
    cmd_get_key->rev1[0] = key_size & 0xFF;

    set_big_endian_2byte((uint8 *)cmd_get_key->key_id, key_id);
    set_big_endian_4byte((uint8 *)cmd_get_key->key_ptr, (uint32)key);

    ret = send_cmd_and_wait_response((uint32 *)cmd_buf, NULL, IsSync);

    if (SEIP_SUCCESS == ret) {
        RetVal = E_OK;
    } else {
        RetVal = E_NOT_OK;
    }

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Hsm_Host_rsa_generatekey
(
    uint32 Modulus_Size,
    hsm_keytype generate_key_type,
    uint16 generate_key_id,
    uint8 *raw_buff,
    uint8 *mac_buf,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint16 key_id_array[2];
    uint32 cmd_buf[8];
    uint32 ret = 0;
    uint32 nbitlen;
    uint8 *n;
    uint8 *e;
    uint8 *d;
    uint8 count;
    cmd_rsa_generatekey_t *cmd_rsa_get_key = NULL;

    /* Arrays need to be defined first and then assigned initial values to avoid linking to
        rodata section in some compiler */
    key_id_array[0] = 0;
    key_id_array[1] = 0;
    mini_memclr_s(cmd_buf, sizeof(cmd_buf));

    n = raw_buff;
    e = raw_buff + Modulus_Size;
    d = raw_buff + (Modulus_Size * 2);

    nbitlen = Modulus_Size << 3;

    /*********** generate key pair ***********/
    cmd_rsa_get_key = (cmd_rsa_generatekey_t *)cmd_buf;
    cmd_rsa_get_key->cmd_id = RSA_GENERATE_KEY;

    set_big_endian_2byte((uint8 *)cmd_rsa_get_key->e_len,
                         (uint16)CRYPTO_HSM_GEN_RSA_DEFAULT_EBIT_LEN);
    set_big_endian_2byte((uint8 *)cmd_rsa_get_key->n_len, (uint32)nbitlen);

    if (CMD_KEY_EXTERNAL_PLAINTEXT == generate_key_type) {
#ifdef EXTRA_HSM_KEY_TYPE
        key_id_array[0] = 0;
#endif
    }
    else if (CMD_KEY_EXTERNAL_CIPHERTEXT == generate_key_type) {
        key_id_array[0] = generate_key_id;
    }
    else {
        return CMD_RETURN_FAIL;
    }

    set_big_endian_2byte((uint8 *)cmd_rsa_get_key->key_id, key_id_array[0]);
    set_big_endian_4byte((uint8 *)cmd_rsa_get_key->e_ptr,
                         (uint32)soc_to_dma_address((uint32)e));
    set_big_endian_4byte((uint8 *)cmd_rsa_get_key->n_ptr,
                         (uint32)soc_to_dma_address((uint32)n));
    set_big_endian_4byte((uint8 *)cmd_rsa_get_key->d_ptr,
                         (uint32)soc_to_dma_address((uint32)d));

    count = RETRY_COUNT;
    do {
        ret = send_cmd_and_wait_response((uint32 *)cmd_buf, NULL, IsSync);
        if (SEIP_SUCCESS == ret) {
            RetVal = E_OK;
            break;
        } else if (SEIP_ERROR_RSA_GET_KEY_FAIL == ret) {
            RetVal = E_NOT_OK;
            /* retry */
        } else {
            RetVal = E_NOT_OK;
            break;
        }

        count--;
    } while (count);

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Hsm_Host_ecc_generatekey
(   uint8 curve_id,
    uint8 *prikey,
    uint8 *pubkey,
    hsm_keytype generate_key_type,
    uint16 generate_key_id,
    uint8 *mac_buf,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint16 key_id_array[2];
    uint32 cmd_buf[8];
    uint32 ret = 0;
    uint8 count;
    cmd_eccp_generatekey_t *cmd_eccp_get_key = NULL;

    /* Arrays need to be defined first and then assigned initial values to avoid linking to
        rodata section in some compiler */
    key_id_array[0] = 0;
    key_id_array[1] = 0;
    mini_memclr_s(cmd_buf, sizeof(cmd_buf));

    /*********** get key pair ***********/
    cmd_eccp_get_key = (cmd_eccp_generatekey_t *)cmd_buf;
    cmd_eccp_get_key->cmd_id = ECCP_GENERATE_KEY;

    if (CMD_KEY_EXTERNAL_PLAINTEXT == generate_key_type) {
#ifdef EXTRA_HSM_KEY_TYPE
        key_id_array[0] = 0;
#endif
    }
    else if (CMD_KEY_EXTERNAL_CIPHERTEXT == generate_key_type) {
        key_id_array[0] = generate_key_id;
    }
    else{
#ifdef EXTRA_HSM_KEY_TYPE
        key_id_array[0] = 0;
#endif
    }

    set_big_endian_2byte((uint8 *)cmd_eccp_get_key->key_id, key_id_array[0]);

    cmd_eccp_get_key->curve_id = curve_id;
    set_big_endian_4byte((uint8 *)cmd_eccp_get_key->pubKey_ptr,
                         (uint32)soc_to_dma_address((uint32)pubkey));
    set_big_endian_4byte((uint8 *)cmd_eccp_get_key->priKey_ptr,
                         (uint32)soc_to_dma_address((uint32)prikey));
    set_big_endian_4byte((uint8 *)cmd_eccp_get_key->aut_info_ptr,
                         (uint32)soc_to_dma_address((uint32)mac_buf));

    count = RETRY_COUNT;
    do {
        ret = send_cmd_and_wait_response((uint32 *)cmd_buf, NULL, IsSync);
        if (SEIP_SUCCESS == ret) {
            RetVal = E_OK;
            break;
        } else if (SEIP_ERROR_ECC_GET_KEY_FAIL == ret) {
            RetVal = E_NOT_OK;
            /* retry */
        } else {
            RetVal = E_NOT_OK;
            break;
        }

        count--;
    } while (count);

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Hsm_Host_sm2_generatekey
(
    uint8 *prikey,
    uint8 *pubkey,
    hsm_keytype generate_key_type,
    uint16 generate_key_id,
    uint8 *mac_buf,
    Crypto_ProcessingType IsSync
)
{
    uint16 key_id_array[2];
    uint32 cmd_buf[8];
    uint32 RetVal = E_NOT_OK;
    uint32 ret;
    uint8 count;
    cmd_sm2_generatekey_t *cmd_gen_key = NULL;

    /* Arrays need to be defined first and then assigned initial values to avoid linking to
        rodata section in some compiler */
    key_id_array[0] = 0;
    key_id_array[1] = 0;
    mini_memclr_s(cmd_buf, sizeof(cmd_buf));

    /*********** generate key pair ***********/
    cmd_gen_key = (cmd_sm2_generatekey_t *)cmd_buf;
    cmd_gen_key->cmd_id = SM2_GENERATE_KEY;

    if (CMD_KEY_EXTERNAL_PLAINTEXT == generate_key_type) {
#ifdef EXTRA_HSM_KEY_TYPE
        key_id_array[0] = 0;
#endif
    }
    else if (CMD_KEY_EXTERNAL_CIPHERTEXT == generate_key_type) {
        key_id_array[0] = generate_key_id;
    }else{
#ifdef EXTRA_HSM_KEY_TYPE
        key_id_array[0] = 0;
#endif
    }

    set_big_endian_2byte((uint8 *)cmd_gen_key->key_id, key_id_array[0]);
    set_big_endian_4byte((uint8 *)cmd_gen_key->pubKey_ptr,
                         (uint32)soc_to_dma_address((uint32)pubkey));
    set_big_endian_4byte((uint8 *)cmd_gen_key->priKey_ptr,
                         (uint32)soc_to_dma_address((uint32)prikey));
    set_big_endian_4byte((uint8 *)cmd_gen_key->aut_info_ptr,
                         (uint32)soc_to_dma_address((uint32)mac_buf));

    count = RETRY_COUNT;
    do {
        ret = send_cmd_and_wait_response((uint32 *)cmd_buf, NULL, IsSync);
        if (SEIP_SUCCESS == ret) {
            RetVal = E_OK;
            break;
        } else if (SEIP_ERROR_SM2_GET_KEY_FAIL == ret) {
            RetVal = E_NOT_OK;
            /* retry */
        } else {
            RetVal = E_NOT_OK;
            break;
        }

        count--;
    } while (count);

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Hsm_host_GenerateTrng
(
    uint8 *rnd,
    uint32 size,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint32 cmd_buf[8] = {0};
    uint32 ret;
    uint8 count;
    cmd_tng_t *cmd_get_random = NULL;

    DBG("Hsm_host_GenerateTrng enter-size=%d\n", size);

    cmd_get_random = (cmd_tng_t *)cmd_buf;
    cmd_get_random->cmd_id = GENERATE_RAND;

    set_big_endian_4byte((uint8 *)cmd_get_random->random_ptr,
                         (uint32)soc_to_dma_address((uint32)rnd));
    set_big_endian_4byte((uint8 *)cmd_get_random->random_len, (uint32)size);

    count = RETRY_COUNT;
    do {
        ret = send_cmd_and_wait_response((uint32 *)cmd_buf, NULL, IsSync);
        if (CRYPTO_PROCESSING_ASYNC == IsSync) {
            RetVal = E_OK;
            break;
        } else {
            if (SEIP_SUCCESS == ret) {
                if (check_rand0()) {
                    /* retry */
                    count--;
                    continue;
                }
                RetVal = E_OK;
                break;
            } else if (SEIP_ERROR_TRNG_FAIL == ret) {
                RetVal = E_NOT_OK;
                /* retry */
            } else {
                RetVal = E_NOT_OK;
                break;
            }
        }

        count--;
    } while (count);

    return RetVal;
}

#if (CRYPTO_HSM_STATE_API == STD_ON)
FUNC(Std_ReturnType, CRYPTO_CODE) cmd_get_device_status
(
    uint16 key_id,
    uint32 *device_status_buf,
    uint8 *mac_buf,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint32 cmd_buf[8] = {0};
    cmd_get_device_status_t *cmd_get_device_status = NULL;
    uint32 ret;

    cmd_get_device_status = (cmd_get_device_status_t *)cmd_buf;
    cmd_get_device_status->cmd_id = GET_DEVICE_STATUS;
    cmd_get_device_status->status_len = 16;

    set_big_endian_2byte((uint8 *)cmd_get_device_status->key_id, key_id);
    set_big_endian_4byte((uint8 *)cmd_get_device_status->device_status_ptr,
                         (uint32)soc_to_dma_address((uint32)device_status_buf));
    set_big_endian_4byte((uint8 *)cmd_get_device_status->aut_info_ptr,
                         (uint32)soc_to_dma_address((uint32)mac_buf));

    ret = send_cmd_and_wait_response((uint32 *)cmd_buf, NULL, IsSync);

    if (SEIP_SUCCESS == ret) {
        RetVal = E_OK;
    } else {
        RetVal = E_NOT_OK;
    }

    return RetVal;
}
#endif  /* CRYPTO_HSM_STATE_API == STD_ON */

#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#ifdef __cplusplus
}
#endif
