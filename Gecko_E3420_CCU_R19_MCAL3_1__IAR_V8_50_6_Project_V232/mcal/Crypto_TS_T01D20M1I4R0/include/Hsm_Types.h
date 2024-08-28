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
 * @file  Hsm_Types.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Crypto
 */

#ifndef HSM_TYPES_H
#define HSM_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

#include <Std_Types.h>

/* Size of MD5 data block in bytes */
#define MD5_BLOCKSIZE      64
/* Size of MD5 initialization value in bytes */
#define MD5_INITSIZE       16
/* Size of MD5 digest in bytes */
#define MD5_DIGESTSIZE     16
/* Size of SHA1 data block in bytes */
#define SHA1_BLOCKSIZE     64
/* Size of SHA1 initialization value in bytes */
#define SHA1_INITSIZE      20
/* Size of SHA1 digest in bytes */
#define SHA1_DIGESTSIZE    20
/* Size of SHA224 data block in bytes */
#define SHA224_BLOCKSIZE   64
/* Size of SHA224 initialization value in bytes */
#define SHA224_INITSIZE    32
/* Size of SHA224 digest in bytes */
#define SHA224_DIGESTSIZE  28
/* Size of SHA256 data block in bytes */
#define SHA256_BLOCKSIZE   64
/* Size of SHA256 initialization value in bytes */
#define SHA256_INITSIZE    32
/* Size of SHA256 digest in bytes */
#define SHA256_DIGESTSIZE  32
/* Size of SHA384 data block in bytes */
#define SHA384_BLOCKSIZE   128
/* Size of SHA384 initialization value in bytes */
#define SHA384_INITSIZE    64
/* Size of SHA384 digest in bytes */
#define SHA384_DIGESTSIZE  48
/* Size of SHA512 data block in bytes */
#define SHA512_BLOCKSIZE   128
/* Size of SHA512 initialization value in bytes */
#define SHA512_INITSIZE    64
/* Size of SHA512 digest in bytes */
#define SHA512_DIGESTSIZE  64
/* Size of SHA512 data block in bytes */
#define SM3_BLOCKSIZE   64
/* Size of SHA512 initialization value in bytes */
#define SM3_INITSIZE    32
/* Size of SHA512 digest in bytes */
#define SM3_DIGESTSIZE  32
/* Maximum block size to be supported */
#define MAX_BLOCKSIZE   SHA512_BLOCKSIZE
/* Maximum digest size to be supported */
#define MAX_DIGESTSIZE  SHA512_DIGESTSIZE

#define RSA_MAX_SIZE          (4096/8)

#define MAC_BUFF_MAX_SIZE          (4096/8)

#define SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK (0x1F)

typedef enum {
    ALG_HASH_MD5,
    ALG_HASH_SHA1,
    ALG_HASH_SHA224,
    ALG_HASH_SHA256,
    ALG_HASH_SHA384,
    ALG_HASH_SHA512,
    ALG_HASH_SM3,
    ALG_HASH_MAX,
} crypto_alg_hash_e;

typedef enum {
    KEY_RSA1024  =   3U,
    KEY_RSA2048  =   4U,
    KEY_RSA3072  =   5U,
    KEY_RSA4096  =   6U,

    KEY_ECDSA_P192 = 0x11U,
    KEY_ECDSA_P256 = 0x12U,
    KEY_ECDSA_P384 = 0x13U,
    KEY_ECDSA_P521 = 0x14U,

    KEY_EDDSA_ED25519 = 0x15,

    KEY_AES_128_ECB = 0x20,
    KEY_AES_128_CBC,
    KEY_AES_128_CFB,
    KEY_AES_128_OFB,
    KEY_AES_128_CTR,
    KEY_AES_128_END,

    KEY_AES_192_ECB = 0x30,
    KEY_AES_192_CBC,
    KEY_AES_192_CFB,
    KEY_AES_192_OFB,
    KEY_AES_192_CTR,
    KEY_AES_192_END,

    KEY_AES_256_ECB = 0x40,
    KEY_AES_256_CBC,
    KEY_AES_256_CFB,
    KEY_AES_256_OFB,
    KEY_AES_256_CTR,
    KEY_AES_256_END,

    KEY_HMAC_SHA1 = 0x50,
    KEY_HMAC_SHA256,
    KEY_HMAC_SHA384,
    KEY_HMAC_SHA512,
    KEY_HMAC_END,

    KEY_CMAC_128 = 0x60,
    KEY_CMAC_192,
    KEY_CMAC_256,
    KEY_CMAC_END,

} key_type_e;

typedef enum {
    ALG_PK_INVALID  =   0U,
    ALG_PK_RSA      =   1U,
    ALG_PK_RSA512   =   2U,
    ALG_PK_RSA1024  =   3U,
    ALG_PK_RSA2048  =   4U,
    ALG_PK_RSA3072  =   5U,
    ALG_PK_RSA4096  =   6U,
    ALG_PK_ECDSA    =   0x10U,
    ALG_PK_ECDSA_P192 = 0x11U,
    ALG_PK_ECDSA_P256 = 0x12U,
    ALG_PK_ECDSA_P384 = 0x13U,
    ALG_PK_ECDSA_P521 = 0x14U,
} crypto_alg_pk_e;

typedef enum {
    CIPHER_ENC,
    CIPHER_DEC,
} cipher_op_e;

#define HSM_ERROR_TIMEOUT       0x11
#define HSM_ERROR_UNALIGND      0x12

#define CMD_TEST_DMA_RAM_BASE         (0x600000UL)

#define ROM_VENDER_SM2_PUBKEY_ADDR    (0x000)
#define ROM_FIRMWARE_ADDR             (0x000)

#define SKE_MAX_KEY_IDX                                (9)   //if key is from secure port, the max key index(or the number of keys)

#define KEYID_0                                 (0)
#define KEYID_1                                 (1)
#define KEYID_2                                 (2)
#define KEYID_3                                 (3)
#define KEYID_4                                 (4)
#define KEYID_5                                 (5)
#define KEYID_6                                 (6)
#define KEYID_7                                 (7)
#define KEYID_8                                 (8)
#define KEYID_9                                 (9)
#define KEYID_MAX                               SKE_MAX_KEY_IDX
#define KEYID_HALF_MASK                         (0x8000)

#define BASIC_MGMT_CMD_BASE                     (0x00)
#define GET_DEVICE_INFO                         (BASIC_MGMT_CMD_BASE+1)
#define GET_DEVICE_STATUS                       (BASIC_MGMT_CMD_BASE+2)
#define GENERATE_RAND                           (BASIC_MGMT_CMD_BASE+3)
#define GENERATE_KEY                            (BASIC_MGMT_CMD_BASE+4)
#define SELF_DESTROY                            (BASIC_MGMT_CMD_BASE+5)
#define SEIP_JUMP                               (BASIC_MGMT_CMD_BASE+6)
#define SEIP_DISABLE                            (BASIC_MGMT_CMD_BASE+7)
#define SENSOR_CLK_CFG                          (BASIC_MGMT_CMD_BASE+8)

#define MAC_CMD_BASE                            (0x10)
#define GENERATE_MAC                            (MAC_CMD_BASE+1)
#define VERIFY_MAC                              (MAC_CMD_BASE+2)
#define GENERATE_AUTH_MAC                       (MAC_CMD_BASE+3)

#define SKE_CMD_BASE                            (0x20)
#define SKE_ENCRYPT                             (SKE_CMD_BASE+1)
#define SKE_DECRYPT                             (SKE_CMD_BASE+2)
#define SKE_AEAD_ENCRYPT_GCM                    (SKE_CMD_BASE+3)
#define SKE_AEAD_DECRYPT_GCM                    (SKE_CMD_BASE+4)

#define SM2_CMD_BASE                            (0x40)
#define SM2_GET_Z                               (SM2_CMD_BASE+1)
#define SM2_GET_E                               (SM2_CMD_BASE+2)
#define SM2_GENERATE_KEY                        (SM2_CMD_BASE+3)
#define SM2_GENERATE_SIGNATURE                  (SM2_CMD_BASE+4)
#define SM2_VERIFY_SIGNATURE                    (SM2_CMD_BASE+5)
#define SM2_ENCRYPT                             (SM2_CMD_BASE+6)
#define SM2_DECRYPT                             (SM2_CMD_BASE+7)
#define SM2_EXCHANGE_KEY                        (SM2_CMD_BASE+8)
#define SM2_GET_PUB_KEY                         (SM2_CMD_BASE+9)

#define SM9_CMD_BASE                            (0x50)
#define SM9_SIGN_GENERATE_MASTER_KEY            (SM9_CMD_BASE+1)
#define SM9_SIGN_GENERATE_USER_PRIVATE_KEY      (SM9_CMD_BASE+2)
#define SM9_GENERATE_SIGNATURE                  (SM9_CMD_BASE+3)
#define SM9_VERIFY_SIGNATURE                    (SM9_CMD_BASE+4)
#define SM9_ENC_GENERATE_MASTER_KEY             (SM9_CMD_BASE+5)
#define SM9_ENC_GENERATE_USER_PRIVATE_KEY       (SM9_CMD_BASE+6)
#define SM9_WRAP_KEY                            (SM9_CMD_BASE+7)
#define SM9_UNWRAP_KEY                          (SM9_CMD_BASE+8)
#define SM9_ENCRYPT                             (SM9_CMD_BASE+9)
#define SM9_DECRYPT                             (SM9_CMD_BASE+10)
#define SM9_EXCKEY_GENERATE_MASTER_KEY          (SM9_CMD_BASE+11)
#define SM9_EXCKEY_GENERATE_USER_PRIVATE_KEY    (SM9_CMD_BASE+12)
#define SM9_EXCKEY_GENERATE_USER_TMP_KEY        (SM9_CMD_BASE+13)
#define SM9_EXCHANGE_KEY                        (SM9_CMD_BASE+14)

#define ECCP_CMD_BASE                           (0x70)
#define ECCP_POINT_DOUBLING                     (ECCP_CMD_BASE+1)
#define ECCP_POINT_ADDITION                     (ECCP_CMD_BASE+2)
#define ECCP_POINT_MULTIPLICATION               (ECCP_CMD_BASE+3)
#define ECCP_POINT_VERIFY                       (ECCP_CMD_BASE+4)
#define ECCP_GENERATE_KEY                       (ECCP_CMD_BASE+5)
#define ECDH_EXCHANGE_KEY                       (ECCP_CMD_BASE+6)
#define ECDSA_GENERATE_SIGNATURE                (ECCP_CMD_BASE+7)
#define ECDSA_VERIFY_SIGNATURE                  (ECCP_CMD_BASE+8)

#define RSA_CMD_BASE                            (0x80)
#define RSA_GENERATE_PRIME                      (RSA_CMD_BASE+1)
#define RSA_GENERATE_KEY                        (RSA_CMD_BASE+2)
#define RSA_GENERATE_CRT_KEY                    (RSA_CMD_BASE+3)
#define RSA_ENCRYPT                             (RSA_CMD_BASE+4)
#define RSA_DECRYPT                             (RSA_CMD_BASE+5)
#define RSA_CRT_DECRYPT                         (RSA_CMD_BASE+6)
#define RSA_GENERATE_SIGNATURE                  (RSA_CMD_BASE+7)
#define RSA_CRT_GENERATE_SIGNATURE              (RSA_CMD_BASE+8)
#define RSA_VERIFY_SIGNATURE                    (RSA_CMD_BASE+9)

#define HASH_CMD_BASE                           (0xA0)
#define HASH_CALC                               (HASH_CMD_BASE+1)

typedef enum {
    CMD_KEY_INTERNAL = 0,
    CMD_KEY_EXTERNAL_PLAINTEXT,
    CMD_KEY_EXTERNAL_CIPHERTEXT,
    CMD_KEY_MAX,
} hsm_keytype;

typedef enum {
    SECP192R1 = 0,
    SECP224R1,
    SECP256R1,
    SECP384R1,
    SECP521R1,
} Crypto_ECCCurveType;

typedef enum {
    CMD_RETURN_SUCESS = 0,
    CMD_RETURN_FAIL,
    CMD_RETURN_PARAM_ERROR,
    CMD_RETURN_MAX,
} cmd_return_e;

enum {
    HASH_ALG_SM3           = 0,      // 0
    HASH_ALG_SHA256,                 //
    HASH_ALG_SHA384,                 //
    HASH_ALG_SHA512,                 //
    HASH_ALG_SHA224,                 //
    HASH_ALG_SHA512_224,             //
    HASH_ALG_SHA512_256,             // 6

    HMAC_ALG_SM3,                    // 7
    HMAC_ALG_SHA256,                 //
    HMAC_ALG_SHA384,                 //
    HMAC_ALG_SHA512,                 //
    HMAC_ALG_SHA224,                 //
    HMAC_ALG_SHA512_224,             //
    HMAC_ALG_SHA512_256,             // 13

    CBC_MAC_SKE_ALG_DES,             // 14
    CBC_MAC_SKE_ALG_TDES_128,        //
    CBC_MAC_SKE_ALG_TDES_192,        //
    CBC_MAC_SKE_ALG_AES_128,         //
    CBC_MAC_SKE_ALG_AES_192,         //
    CBC_MAC_SKE_ALG_AES_256,         //
    CBC_MAC_SKE_ALG_SM4,             // 20

    CMAC_SKE_ALG_AES_128,            // 21
    CMAC_SKE_ALG_AES_192,            //
    CMAC_SKE_ALG_AES_256,            //
    CMAC_SKE_ALG_SM4,                // 24

    SKE_ALG_DES_ECB,                 // 25
    SKE_ALG_DES_CBC,                 //
    SKE_ALG_DES_CFB,                 //
    SKE_ALG_DES_OFB,                 //
    SKE_ALG_DES_CTR,                 //
    SKE_ALG_TDES_128_ECB,            //
    SKE_ALG_TDES_128_CBC,            // 31
    SKE_ALG_TDES_128_CFB,            //
    SKE_ALG_TDES_128_OFB,            //
    SKE_ALG_TDES_128_CTR,            //
    SKE_ALG_TDES_192_ECB,            // 35
    SKE_ALG_TDES_192_CBC,            //
    SKE_ALG_TDES_192_CFB,            //
    SKE_ALG_TDES_192_OFB,            //
    SKE_ALG_TDES_192_CTR,            // 39

    SKE_ALG_AES_128_ECB,             // 40
    SKE_ALG_AES_128_CBC,             //
    SKE_ALG_AES_128_CFB,             //
    SKE_ALG_AES_128_OFB,             //
    SKE_ALG_AES_128_CTR,             //
    SKE_ALG_AES_128_XTS,             //
    SKE_ALG_AES_128_GCM,             // 46

    SKE_ALG_AES_192_ECB,             // 47
    SKE_ALG_AES_192_CBC,             //
    SKE_ALG_AES_192_CFB,             //
    SKE_ALG_AES_192_OFB,             //
    SKE_ALG_AES_192_CTR,             //
    SKE_ALG_AES_192_XTS,             //
    SKE_ALG_AES_192_GCM,             //

    SKE_ALG_AES_256_ECB,             // 54
    SKE_ALG_AES_256_CBC,             //
    SKE_ALG_AES_256_CFB,             //
    SKE_ALG_AES_256_OFB,             //
    SKE_ALG_AES_256_CTR,             //
    SKE_ALG_AES_256_XTS,             //
    SKE_ALG_AES_256_GCM,             //

    SKE_ALG_SM4_ECB,                 // 61
    SKE_ALG_SM4_CBC,                 //
    SKE_ALG_SM4_CFB,                 //
    SKE_ALG_SM4_OFB,                 //
    SKE_ALG_SM4_CTR,                 //
    SKE_ALG_SM4_XTS,                 //
    SKE_ALG_SM4_GCM,                 //

    PKE_ALG_SM2,                     // 68
    PKE_ALG_RSA,                     //
    PKE_ALG_ECC,                     //

};

typedef struct {
    uint8 n[512];
    uint8 e[512];
    uint8 d[512];
    uint8 p[512];
    uint8 q[512];
    uint8 dP[512];
    uint8 dQ[512];
    uint8 qInv[512];
} RSARawKey_Ext_Sdrv;

typedef struct {
    uint32 version;
    hsm_keytype keytype;
    uint32 keyid1;
    uint32 n_sz;
    uint8 *n;
    uint8 *e;
    uint8 *d;
    uint8 *p;
    uint8 *q;
    uint8 *dP;
    uint8 *dQ;
    uint8 *qInv;
} RSAKey_Head_Ext_Sdrv;

typedef struct {
    RSAKey_Head_Ext_Sdrv keybuff_head;
    uint8 value[4];
    /* value buff : x = 0 128 256 384 512
    uint8 n[x];
    uint8 e[x];
    uint8 d[x];
    uint8 p[x];
    uint8 q[x];
    uint8 dP[x];
    uint8 dQ[x];
    uint8 qInv[x];*/
} RSAKey_Ext_Sdrv;

#define REQ_SIZE(n) ((uint16)((uint16)8 + ((uint16)(n) * sizeof(uint32))))

typedef struct {
    uint32 n_sz;   /* n, e, d must be in the same size */
    uint8 n[512];
    uint8 e[512];
    uint8 d[512];
} rsa_key_t;

/*
 * (r,s) Signature
 */
typedef struct {
    uint32 curve_id;
    uint32 prime_sz;
    /* Public key Q(x, y) */
    uint8 x[68];
    uint8 y[68];
    /* Private key for signature generation */
    uint8 d[68];
    uint8 k[68];
} ecdsa_key_t;

typedef struct {
    uint32 curve_id;
    uint32 prime_sz;
    /* Public key Q(x, y) */
    uint8 x[68];
    uint8 y[68];
} ecdsa_pk_t;

typedef struct {
    uint32 curve_id;
    uint32 prime_sz;
    /* Public key Q(x, y) */
    uint8 Pk[32];
    uint8 Sk[32];
} eddsa_key_t;

typedef struct {
    uint32 n_sz;   /* n, e, d must be in the same size */
    uint8 n[512];
    uint8 e[512];
} rsa_pk_t;

/* bit mask to indicate owners, mapping to the CPU ID */
#define KEY_FLAG_OWNER(x)   ((x) & 0xffffu)
#define GFV_KEY_FLAG_OWNER(x)   ((x) & 0xffffu)
/* If set, indicating this key used for command authentication only */
#define KEY_FLAG_CAK            (0x01u << 16)
/* If not set, this key shall never be unwrapped into external memory */
#define KEY_FLAG_UNWRAP_ALLOWED (0x01u << 17)
/* If set, this key need to be authenticated before being used */
#define KEY_FLAG_CA_NEEDED      (0x01u << 18)
/* The CAK index to be used for command authentication */
#define KEY_FLAG_CAK_INDEX(x)   (((x) & 0x0fu) << 19)
#define GFV_KEY_FLAG_CAK_INDEX(x)   (((x) >> 19) & 0xfu)

typedef struct {
    uint16 sz;     /*size of this key: sizeof(hdr) + sizeof(key) */
    uint16 type;
    uint32 flag;
    uint32 id;
    uint32 tag;    /* fixed at : 0x304b4559:("0KEY")*/
    uint32 cak_id;
} ks_hdr_t;

#define KS_HDR_RSA(flag, type, id)  {sizeof(ks_rsa_key_t), type, flag, id, 0x304b4559}
#define KS_HDR_ECDSA(flag, type, id)  {sizeof(ks_ecdsa_key_t), type, flag, id, 0x304b4559}

typedef struct {
    ks_hdr_t hdr;
    rsa_key_t key;
} ks_rsa_key_t;

typedef struct {
    ks_hdr_t hdr;
    ecdsa_key_t key;
} ks_ecdsa_key_t;

typedef struct {
    ks_hdr_t hdr;
    eddsa_key_t key;
} ks_eddsa_key_t;

typedef struct {
    uint64 total_len;
    uint8 inter_data[128];      /*For E3*/
    uint8 residual_data[128];
    uint32 context_id;
    uint8 algo;
} hash_context;

typedef struct {
    uint8 algo_mode;
    uint8 key_len;
    uint8 operation;       /*de/encrypt */
    uint8 padding_mode;
    uint32 context_id;
    uint8 residual_data[16];
    uint8 inter_data[16];
    uint16 key_pos;
} cipher_context;

typedef struct {
    uint8 cmd_id;
    uint8 need_seed;
    uint8 rev1[1];
    uint8 mode;
    uint8 iv_ptr[4];
    uint8 data_ptr[4];
    uint8 data_len[4];
    uint8 key_id0[2];
    uint8 key_id1[2];
    uint8 key_ptr[4];
    uint8 cipher_ptr[4];
    uint8 aut_info_ptr[4];
} cmd_ske_encrypt_t;

typedef struct {
    uint8 cmd_id;
    uint8 need_seed;
    uint8 rev1[1];
    uint8 mode;
    uint8 iv_ptr[4];
    uint8 cipher_ptr[4];
    uint8 cipher_len[4];
    uint8 key_id0[2];
    uint8 key_id1[2];
    uint8 key_ptr[4];
    uint8 data_ptr[4];
    uint8 aut_info_ptr[4];
} cmd_ske_decrypt_t;

typedef struct {
    uint8 iv_ptr[4];
    uint8 aad_data_ptr[4];
} gcm_enc_input_ptr_t;

typedef struct {
    uint8 cmd_id;
    uint8 need_seed;
    uint8 mode;
    uint8 tag_len;
    uint8 gcm_enc_input_ptr[4];
    uint8 iv_len[2];
    uint8 aad_len[2];
    uint8 data_len[4];
    uint8 key_id0[2];
    uint8 key_id1[2];
    uint8 key_ptr[4];
    uint8 cipher_tag_ptr[4];
    uint8 aut_info_ptr[4];
} cmd_aead_encrypt_gcm_t;

typedef struct {
    uint8 iv_ptr[4];
    uint8 aad_cipher_ptr[4];
    uint8 tag_ptr[4];
} gcm_dec_input_ptr_t;

typedef struct {
    uint8 cmd_id;
    uint8 need_seed;
    uint8 mode;
    uint8 tag_len;
    uint8 gcm_dec_input_ptr[4];
    uint8 iv_len[2];
    uint8 aad_len[2];
    uint8 cipher_len[4];
    uint8 key_id0[2];
    uint8 key_id1[2];
    uint8 key_ptr[4];
    uint8 data_tag_ptr[4];
    uint8 aut_info_ptr[4];
} cmd_aead_decrypt_gcm_t;

typedef struct {
    uint8 cmd_id;
    uint8 rev1[1];
    uint8 key_id[2];
    uint8 key_ptr[4];
    uint8 aut_info_ptr[4];
} cmd_generate_key_t;

typedef struct {
    uint8 cmd_id;
    uint8 rev1[3];
    uint8 e_len[2];
    uint8 n_len[2];
    uint8 e_ptr[4];
    uint8 rev2[2];
    uint8 key_id[2];
    uint8 d_ptr[4];
    uint8 n_ptr[4];
    uint8 aut_info_ptr[4];
} cmd_rsa_generatekey_t;

typedef struct {
    uint8 cmd_id;
    uint8 rev1[3];
    uint8 random_ptr[4];
    uint8 random_len[4];
} cmd_tng_t;

typedef struct {
    uint8 cmd_id;
    uint8 rev1[1];
    uint8 n_len[2];
    uint8 data_ptr[4];
    uint8 e_ptr[4];
    uint8 n_ptr[4];
    uint8 cipher_ptr[4];
} cmd_rsa_encrypt_t;

typedef struct {
    uint8 cmd_id;
    uint8 need_high_sec_ver;
    uint8 n_len[2];
    uint8 cipher_ptr[4];
    uint8 rev2[2];
    uint8 key_id[2];
    uint8 e_ptr[4];
    uint8 d_ptr[4];
    uint8 n_ptr[4];
    uint8 data_ptr[4];
    uint8 aut_info_ptr[4];
} cmd_rsa_decrypt_t;

typedef struct {
    uint8 cmd_id;
    uint8 need_high_sec_ver;
    uint8 n_len[2];
    uint8 cipher_ptr[4];
    uint8 rev2[2];
    uint8 key_id[2];
    uint8 e_ptr[4];
    uint8 priKey_ptr[4];
    uint8 data_ptr[4];
    uint8 aut_info_ptr[4];
} cmd_rsa_CRT_decrypt_t;

typedef struct {
    uint8 cmd_id;
    uint8 need_high_sec_ver;
    uint8 n_len[2];
    uint8 data_ptr[4];
    uint8 rev2[2];
    uint8 key_id[2];
    uint8 e_ptr[4];
    uint8 d_ptr[4];
    uint8 n_ptr[4];
    uint8 signature_ptr[4];
    uint8 aut_info_ptr[4];
} cmd_rsa_generate_signature_t;

typedef struct {
    uint8 cmd_id;
    uint8 need_high_sec_ver;
    uint8 n_len[2];
    uint8 data_ptr[4];
    uint8 rev2[2];
    uint8 key_id[2];
    uint8 e_ptr[4];
    uint8 priKey_ptr[4];
    uint8 signature_ptr[4];
    uint8 aut_info_ptr[4];
} cmd_rsa_CRT_generate_signature_t;

typedef struct {
    uint8 cmd_id;
    uint8 rev1[1];
    uint8 n_len[2];
    uint8 data_ptr[4];
    uint8 e_ptr[4];
    uint8 n_ptr[4];
    uint8 signature_ptr[4];
} cmd_rsa_verify_t;

typedef struct {
    uint8 cmd_id;
    uint8 rev1[1];
    uint8 curve_id;
    uint8 e_len;
    uint8 e_ptr[4];
    uint8 key_id0[2];
    uint8 key_id1[2];
    uint8 priKey_ptr[4];
    uint8 signature_ptr[4];
    uint8 aut_info_ptr[4];
} cmd_ecdsa_generate_signature_t;

typedef struct {
    uint8 cmd_id;
    uint8 curve_id;
    uint8 key_id[2];
    uint8 pubKey_ptr[4];
    uint8 priKey_ptr[4];
    uint8 aut_info_ptr[4];
} cmd_eccp_generatekey_t;

typedef struct {
    uint8 cmd_id;
    uint8 rev1[1];
    uint8 curve_id;
    uint8 e_len;
    uint8 e_ptr[4];
    uint8 pubKey_ptr[4];
    uint8 signature_ptr[4];
} cmd_ecdsa_verify_signature_t;

typedef struct {
    uint8 cmd_id;
    uint8 need_seed;
    uint8 mode;
    uint8 mac_len;
    uint8 data_ptr[4];
    uint8 data_len[4];
    uint8 key_id0[2];
    uint8 key_id1[2];
    uint8 key_ptr[4];
    uint8 rev2[2];
    uint8 key_len[2];
    uint8 mac_ptr[4];
    uint8 aut_info_ptr[4];
} cmd_generateMAC_t;

typedef struct {
    uint8 cmd_id;
    uint8 rev1[1];
    uint8 key_id[2];
    uint8 pubKey_ptr[4];
    uint8 priKey_ptr[4];
    uint8 aut_info_ptr[4];
} cmd_sm2_generatekey_t;

typedef struct {
    uint8 cmd_id;
    uint8 need_high_sec_ver;
    uint8 rev1[2];
    uint8 data_ptr[4];
    uint8 data_len[4];
    uint8 pubKey_ptr[4];
    uint8 cipher_ptr[4];
} cmd_sm2_encrypt_t;

typedef struct {
    uint8 cmd_id;
    uint8 need_high_sec_ver;
    uint8 rev1[2];
    uint8 cipher_ptr[4];
    uint8 cipher_len[4];
    uint8 key_id0[2];
    uint8 key_id1[2];
    uint8 priKey_ptr[4];
    uint8 data_ptr[4];
    uint8 aut_info_ptr[4];
} cmd_sm2_decrypt_t;

typedef struct {
    uint8 cmd_id;
    uint8 need_high_sec_ver;
    uint8 rev1[2];
    uint8 e_ptr[4];
    uint8 key_id0[2];
    uint8 key_id1[2];
    uint8 priKey_ptr[4];
    uint8 signature_ptr[4];
    uint8 aut_info_ptr[4];
} cmd_sm2_generatesignature_t;

typedef struct {
    uint8 cmd_id;
    uint8 need_high_sec_ver;
    uint8 rev1[2];
    uint8 e_ptr[4];
    uint8 pubKey_ptr[4];
    uint8 signature_ptr[4];
} cmd_sm2_verifysignature_t;

typedef struct {
    uint8 cmd_id;
    uint8 need_seed;
    uint8 mode;
    uint8 mac_len;
    uint8 data_ptr[4];
    uint8 data_len[4];
    uint8 key_id0[2];
    uint8 key_id1[2];
    uint8 key_ptr[4];
    uint8 rev2[2];
    uint8 key_len[2];
    uint8 mac_ptr[4];
    uint8 aut_info_ptr[4];
} cmd_verifyMAC_t;

typedef struct {
    uint8 cmd_id;
    uint8 rev1[2];
    uint8 mode;
    uint8 data_ptr[4];
    uint8 data_len[4];
    uint8 digest_ptr[4];
} cmd_hash_t;

typedef struct {
    uint8 cmd_id;
    uint8 status_len;
    uint8 key_id[2];
    uint8 device_status_ptr[4];
    uint8 aut_info_ptr[4];
} cmd_get_device_status_t;

#ifdef __cplusplus
}
#endif

#endif /* HSM_TYPES_H */
