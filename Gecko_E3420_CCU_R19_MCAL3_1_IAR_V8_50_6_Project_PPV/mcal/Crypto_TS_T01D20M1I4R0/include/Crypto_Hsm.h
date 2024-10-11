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
 * @file  Crypto_Hsm.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Crypto
 */

#ifndef CRYPTO_HSM_H
#define CRYPTO_HSM_H

#ifdef __cplusplus
extern "C" {
#endif
#include "arch.h"
#include "Hsm_Types.h"
#include "Csm_Types.h"
#include "Crypto_Cfg.h"

#define RETRY_COUNT (20)

#ifdef ASYNC_CRYPTO_INIT_ENABLE
#define SW_CRYPTO_INIT_MODE CRYPTO_PROCESSING_ASYNC
#else
#define SW_CRYPTO_INIT_MODE CRYPTO_PROCESSING_SYNC
#endif

/* seip error code */
enum ERR_CODE {
    SEIP_SUCCESS                   = 0xA5,
    SEIP_ERROR                     = 0x37,
    SEIP_FW_VER_SUCCESS            = 0xE6,
    SEIP_FW_VER_ERROR              = 0x37,
    SEIP_SKE_ALARM                 = 0x38,
    SEIP_ERROR_NOT_ALIGNED_BY_WORD = 0x40,
    SEIP_ERROR_MODE_INVALID        = 0x41,
    SEIP_ERROR_VALUE_INVALID       = 0x42,
    SEIP_ERROR_LENGTH_INVALID      = 0x43,
    SEIP_ERROR_KEK_ENCRYPT_FAIL    = 0x44,
    SEIP_ERROR_KEK_DECRYPT_FAIL    = 0x45,
    SEIP_ERROR_KEYID0_FAIL         = 0x46,
    SEIP_ERROR_KEYID1_FAIL         = 0x47,
    SEIP_ERROR_KEYID2_FAIL         = 0x48,
    SEIP_ERROR_KEYID3_FAIL         = 0x49,
    SEIP_ERROR_KEYID_ZERO          = 0x4A,
    SEIP_ERROR_KEYID_INVALID       = 0x4B,
    SEIP_ERROR_KEYID_INVALID2      = 0x4C,
    SEIP_ERROR_AUTH_KEY_FAIL       = 0x4D,
    SEIP_ERROR_SKE_FAIL            = 0x4E,
    SEIP_ERROR_SKE_ALG_INVALID     = 0x4F,
    SEIP_ERROR_SKE_SET_SEED_FAIL   = 0x50,
    SEIP_ERROR_TRNG_FAIL           = 0x51,
    SEIP_ERROR_BOOTMODE_FAIL       = 0x52,
    SEIP_ERROR_COMPARE_FAIL        = 0x53,
    SEIP_ERROR_COMPARE_FAIL2       = 0x54,
    SEIP_ERROR_COMPARE_FAIL3       = 0x55,
    SEIP_ERROR_HASH_ALG_INVALID    = 0x56,
    SEIP_ERROR_HASH_FAIL           = 0x57,
    SEIP_ERROR_HMAC_FAIL           = 0x58,
    SEIP_ERROR_ECC_CURVE_INVALID   = 0x59,
    SEIP_ERROR_ECC_PD_FAIL         = 0x5A,
    SEIP_ERROR_ECC_PA_FAIL         = 0x5B,
    SEIP_ERROR_ECC_PM_FAIL         = 0x5C,
    SEIP_ERROR_ECC_GET_KEY_FAIL    = 0x5D,
    SEIP_ERROR_ECDSA_SIGN_FAIL     = 0x5E,
    SEIP_ERROR_ECDSA_VERIFY_FAIL   = 0x5F,
    SEIP_ERROR_GET_PRIME_FAIL      = 0x60,
    SEIP_ERROR_RSA_GET_KEY_FAIL    = 0x61,
    SEIP_ERROR_RSA_FAIL            = 0x62,
    SEIP_ERROR_SM2_GET_KEY_FAIL    = 0x63,
    SEIP_ERROR_SM2_SIGN_FAIL       = 0x64,
    SEIP_ERROR_SM2_VERIFY_FAIL     = 0x65,
    SEIP_ERROR_SM2_ENCRYPT_FAIL    = 0x66,
    SEIP_ERROR_SM2_DECRYPT_FAIL    = 0x67,
    SEIP_ERROR_SM2_EXCHANGE_FAIL   = 0x68,
    SEIP_ERROR_SM9_FAIL            = 0x69,
    SEIP_TIME_OUT                  = 0xFF,
};

/* Enumeration of the algorithm mode */
typedef enum {
    /** hsm init success*/
    CRYPTO_HSM_INIT_OK = 0x00,
    /** hsm reset fail,check power*/
    CRYPTO_HSM_INIT_RESET_FAIL     = 0x01,
    /** hsm boot timeout, check HSM reg mem region type*/
    CRYPTO_HSM_INIT_BOOT_TIMEOUT     = 0x02,
    /** hsm boot fail, check clk&reset*/
    CRYPTO_HSM_INIT_BOOT_FAIL     = 0x03,
    /** hsm product flag error ,check fuse*/
    CRYPTO_HSM_INIT_PRODUCT_ERROR     = 0x04,
    CRYPTO_HSM_BUSY,
    CRYPTO_HSM_IDLE,
    CRYPTO_HSM_INIT_TYPE_MAX /** HSM init return type max*/
} Crypto_HsmInitReturnType;



FUNC(Crypto_HsmInitReturnType, CRYPTO_CODE) Hsm_host_init
(
    Crypto_ProcessingType IsSync
);

FUNC(Crypto_HsmInitReturnType, CRYPTO_CODE) Hsm_host_init_check
(
    void
);

FUNC(Std_ReturnType, CRYPTO_CODE) Hsm_host_RsaEncrypt
(
    uint8 *n,
    uint8 *e,
    uint32 Modulus_Size,
    const uint8 *msg,
    uint8 *cipher,
    Crypto_ProcessingType IsSync
);

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
);

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
);

FUNC(Std_ReturnType, CRYPTO_CODE) Hsm_host_Verify_Rsa
(
    uint8 *msg,
    uint8 *n,
    uint8 *e,
    uint32 Modulus_Size,
    const uint8 *signature,
    Crypto_JobType *job,
    Crypto_ProcessingType IsSync
);

FUNC(Std_ReturnType, CRYPTO_CODE) Hsm_host_Sm2_Encrypt
(
    uint8 *msg,
    uint32 msg_len,
    uint8 *pubkey,
    uint8 *cipher,
    Crypto_ProcessingType IsSync
);

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
);

FUNC(Std_ReturnType, CRYPTO_CODE) Hsm_host_Sign_Sm2
(
    uint8 *e,
    uint8 *prikey,
    hsm_keytype sign_key_type,
    uint16 sign_key_id,
    uint8 *signature,
    uint8 *mac_buf,
    Crypto_ProcessingType IsSync
);

FUNC(Std_ReturnType, CRYPTO_CODE) Hsm_host_Verify_Sm2
(
    uint8 *e,
    uint8 *pubkey,
    uint8 *signature,
    Crypto_JobType *job,
    Crypto_ProcessingType IsSync
);

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
);

FUNC(Std_ReturnType, CRYPTO_CODE) Hsm_host_Verify_Ecdsa
(
    uint8 curve_id,
    uint8 *e,
    uint32 e_len,
    uint8 *pubkey,
    uint8 *signature,
    Crypto_JobType *job,
    Crypto_ProcessingType IsSync
);

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
);

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
);

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
);

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
);

FUNC(Std_ReturnType, CRYPTO_CODE) Hsm_host_Hash
(
    Crypto_AlgorithmFamilyType algorithm,
    const uint8 *Hash_DataAddr,
    uint32 inputLength,
    uint8 *Hash_DigestAddr,
    uint32 *Hash_DigestLenAddr,
    Crypto_ProcessingType IsSync
);

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
);

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
);

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
);

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
);

FUNC(Std_ReturnType, CRYPTO_CODE) Hsm_host_encrypt_key
(
    const uint8 *key_plain,
    uint32 key_plain_bytes,
    uint16 kek_keyid,
    const uint8 *key_cipher,
    Crypto_ProcessingType IsSync
);

FUNC(Std_ReturnType, CRYPTO_CODE) Hsm_host_decrypt_key
(
    uint8 *key_cipher,
    uint32 key_plain_bytes,
    uint16 kek_keyid,
    uint8 *key_plain,
    Crypto_ProcessingType IsSync
);

FUNC(Std_ReturnType, CRYPTO_CODE) Hsm_host_GenerateKey
(
    uint16 key_id,
    uint8 *key,
    uint32 key_size,
    Crypto_ProcessingType IsSync
);

FUNC(Std_ReturnType, CRYPTO_CODE) Hsm_Host_rsa_generatekey
(
    uint32 Modulus_Size,
    hsm_keytype generate_key_type,
    uint16 generate_key_id,
    uint8 *raw_buff,
    uint8 *mac_buf,
    Crypto_ProcessingType IsSync
);

FUNC(Std_ReturnType, CRYPTO_CODE) Hsm_Host_ecc_generatekey
(   uint8 curve_id,
    uint8 *prikey,
    uint8 *pubkey,
    hsm_keytype generate_key_type,
    uint16 generate_key_id,
    uint8 *mac_buf,
    Crypto_ProcessingType IsSync
);

FUNC(Std_ReturnType, CRYPTO_CODE) Hsm_Host_sm2_generatekey
(
    uint8 *prikey,
    uint8 *pubkey,
    hsm_keytype generate_key_type,
    uint16 generate_key_id,
    uint8 *mac_buf,
    Crypto_ProcessingType IsSync
);

FUNC(Std_ReturnType, CRYPTO_CODE) Hsm_host_GenerateTrng
(
    uint8 *rnd,
    uint32 size,
    Crypto_ProcessingType IsSync
);

#if (CRYPTO_HSM_STATE_API == STD_ON)
FUNC(Std_ReturnType, CRYPTO_CODE) cmd_get_device_status
(
    uint16 key_id,
    uint32 *device_status_buf,
    uint8 *mac_buf,
    Crypto_ProcessingType IsSync
);
#endif  /* CRYPTO_HSM_STATE_API == STD_ON */

uint32 cmac_algo_mode_mapping(Crypto_AlgorithmFamilyType autosar_algo,
                              uint8 key_sz);
uint32 hmac_algo_mode_mapping(Crypto_AlgorithmFamilyType autosar_algo);

uint32 Crypto_Check_Response(void);
void Crypto_Set_ASYNC_RSA(void);

#ifdef __cplusplus
}
#endif

#endif /* CRYPTO_HSM_H */
