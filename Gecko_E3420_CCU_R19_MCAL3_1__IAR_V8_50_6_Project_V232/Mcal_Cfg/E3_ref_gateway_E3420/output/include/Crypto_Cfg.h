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
 * @file  Crypto_Cfg.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Crypto
 * @date 2024-03-08 16:29:00
 */

#ifndef CRYPTO_CFG_H
#define CRYPTO_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

#define CRYPTO_DEV_ERROR_DETECT (STD_ON)
#define CRYPTO_VERSION_INFO_API (STD_ON)
#define CRYPTO_HSM_STATE_API (STD_ON)
/** \brief  Define if global variables need to be placed in non-cache area or not */
#define CRYPTO_NO_CACHEABLE_NEEDED (STD_OFF)

#define CRYPTO_KEY_ELEMENT_NUM   (30U)
#define CRYPTO_KEY_NUM   (13U)
#define CRYPTO_MAX_KEY_ID (CRYPTO_KEY_NUM)
#define CRYPTO_KEY_LIST_NUM   (CRYPTO_KEY_NUM + 1U)
#define CRYPTO_MAX_KEY_ELEMENT_ID  (28U)
#define CRYPTO_DRIVER_OBJ_NUM    (5U)
#define CRYPTO_DRIVEROBJ_QUEUE_SIZE (3U)
#define CRYPTO_DRIVER_KEYSTORE_SIZE (16384U)
#define CRYPTO_DRIVER_KEYSTORE_STARTADDR (1048576U)

/* the context not support currently */
#define CRYPTO_CONTEXT_NUM       (1U)

/* driver objects index */
#define CryptoConf_CryptoDriverObject_hash_object (1U)
#define CryptoConf_CryptoDriverObject_aes_object (2U)
#define CryptoConf_CryptoDriverObject_rng_object (3U)
#define CryptoConf_CryptoDriverObject_mac_object (4U)
#define CryptoConf_CryptoDriverObject_PK (5U)

/* key elements index */
#define CryptoConf_CryptoKeyElement_Hmac_key1 (0U)
#define CryptoConf_CryptoKeyElement_Hmac_key2 (1U)
#define CryptoConf_CryptoKeyElement_Hmac_key3 (2U)
#define CryptoConf_CryptoKeyElement_Hmac_key4 (3U)
#define CryptoConf_CryptoKeyElement_Cipher_IV1 (4U)
#define CryptoConf_CryptoKeyElement_Cipher_IV2 (5U)
#define CryptoConf_CryptoKeyElement_Cipher_IV3 (6U)
#define CryptoConf_CryptoKeyElement_Cipher_IV4 (7U)
#define CryptoConf_CryptoKeyElement_Cipher_key1 (8U)
#define CryptoConf_CryptoKeyElement_Cipher_key2 (9U)
#define CryptoConf_CryptoKeyElement_Cipher_key3 (10U)
#define CryptoConf_CryptoKeyElement_Cipher_key4 (11U)
#define CryptoConf_CryptoKeyElement_RSA_KeyPri_RAW_1024_1 (12U)
#define CryptoConf_CryptoKeyElement_RSA_KeyPub_RAW_1024_1 (13U)
#define CryptoConf_CryptoKeyElement_RSA_KeyPri_RAW_2048_1 (14U)
#define CryptoConf_CryptoKeyElement_RSA_KeyPub_RAW_2048_1 (15U)
#define CryptoConf_CryptoKeyElement_RSA_KeyPri_RAW_4096_1 (16U)
#define CryptoConf_CryptoKeyElement_RSA_KeyPub_RAW_4096_1 (17U)
#define CryptoConf_CryptoKeyElement_RSA_KeyPri_PKCS_1024_1 (18U)
#define CryptoConf_CryptoKeyElement_RSA_KeyPub_PKCS_1024_1 (19U)
#define CryptoConf_CryptoKeyElement_RSA_KeyPri_PKCS_2048_1 (20U)
#define CryptoConf_CryptoKeyElement_RSA_KeyPub_PKCS_2048_1 (21U)
#define CryptoConf_CryptoKeyElement_RSA_KeyPri_PKCS_4096_1 (22U)
#define CryptoConf_CryptoKeyElement_RSA_KeyPub_PKCS_4096_1 (23U)
#define CryptoConf_CryptoKeyElement_ECC_KeyPri_P192R1_1 (24U)
#define CryptoConf_CryptoKeyElement_ECC_KeyPub_P192R1_1 (25U)
#define CryptoConf_CryptoKeyElement_ECC_KeyPri_P256R1_1 (26U)
#define CryptoConf_CryptoKeyElement_ECC_KeyPub_P256R1_1 (27U)
#define CryptoConf_CryptoKeyElement_ECC_KeyPri_P521R1_1 (28U)
#define CryptoConf_CryptoKeyElement_ECC_KeyPub_P521R1_1 (29U)


/* key index */
#define CryptoConf_CryptoKey_CryptoKey_0 (1U)
#define CryptoConf_CryptoKey_CryptoKey_1 (2U)
#define CryptoConf_CryptoKey_CryptoKey_2 (3U)
#define CryptoConf_CryptoKey_CryptoKey_3 (4U)
#define CryptoConf_CryptoKey_CryptoKey_4 (5U)
#define CryptoConf_CryptoKey_CryptoKey_5 (6U)
#define CryptoConf_CryptoKey_CryptoKey_6 (7U)
#define CryptoConf_CryptoKey_CryptoKey_7 (8U)
#define CryptoConf_CryptoKey_CryptoKey_8 (9U)
#define CryptoConf_CryptoKey_CryptoKey_9 (10U)
#define CryptoConf_CryptoKey_CryptoKey_10 (11U)
#define CryptoConf_CryptoKey_CryptoKey_11 (12U)
#define CryptoConf_CryptoKey_CryptoKey_12 (13U)


#define CRYPTO_PRECOMPILE_SUPPORT (STD_ON)

#ifdef __cplusplus
}
#endif
#endif /*CRYPTO_CFG_H*/
