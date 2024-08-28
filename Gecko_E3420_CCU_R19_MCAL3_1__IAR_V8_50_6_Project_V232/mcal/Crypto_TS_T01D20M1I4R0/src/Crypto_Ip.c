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
 * @file  Crypto_Ip.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Crypto
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Crypto_ShareMem.h"
#include "Crypto_KeyManagement.h"
#include "Crypto.h"
#include "Crypto_Ip.h"
#include "Crypto_RSAPadding.h"
#include "RegHelper.h"
#include "Crypto_Hsm.h"
#include "cdefs.h"

#include "mini_libc.h"
#include "arch.h"
#include "soc_seip_reg.h"

#define CRYPTO_IP_UNINITED_JOB_ID   (0xffffffffUL)
#define CRYPTO_IP_UNUSED_CONTEXT_ID (0xffffffffUL)
/*byte in unit*/

#define HASH_PADDING_LENGTH(x)      (CRYPTO_MAX_SHARE_DATA_BLOCK_SIZE(x) - (x/8))
#define HASH_MOD_SIZE(x)            (x/8*7)

#define CRYPTO_IP_HASH_INTER_DATA_LEN_MAX       (128)

/*context is used for ongoing job, sync type job only one job ongoing*/
#define CRYPTO_IP_CIPHER_CONTEXT_NUM            (2)
#define CRYPTO_IP_CIPHER_BLOCK_LEN_MAX          (32)
#define CRYPTO_IP_CIPHER_DUALKEY_LEN_MAX        (64)

#define CRYPTO_IP_RSA_CONTEXT_NUM               (2)
#define CRYPTO_IP_RSA_HASH_LEN_MAX              (64) /*SHA512*/
#define CRYPTO_IP_RSA_PADDING_MSG_LEN_MAX       (512) /*RSA 4096/8*/

#define CRYPTO_IP_MAC_CONTEXT_NUM               (2)
#define CRYPTO_IP_MAC_BLOCK_PADDING_LEN_MAX     (512)

#define CRYPTO_IP_TRNG_OUT_LEN_MAX              (128)

#define DEVICE_STATUS_LEN                       (16)

typedef struct {
    uint32 context_id;
    uint64 total_len;
    uint8 *inter_data;
    uint8 *residual_data;
    uint8 algo;
} Crypto_Ip_HashContextType;

typedef struct {
    uint32 context_id;
    Crypto_AlgorithmModeType algo_mode;
    Crypto_AlgorithmFamilyType algo;
    uint8 key_len;
    cipher_op_e operation; /*de/encrypt */
    uint8 padding_mode;
    uint8 *inter_iv_data;
    uint8 *dualkey_data;
    uint8 *gcm_input;
    uint16 key_id;
} Crypto_Ip_CipherContextType;

typedef struct {
    uint32 context_id;
    uint8 *hash_data;
    uint8 *msg_data;
    uint8 *mac_data;
    uint32 *key_data;
    uint32 n_sz;    /* n, e, d must be in the same size */
    uint32 msg_len;
    uint32 key_len;
    uint16 key_id;
} Crypto_Ip_PKContextType;

typedef struct {
    uint32 context_id;
    uint8 *msg_data;
    uint8 *mac_data;
    uint16 key_id;
} Crypto_Ip_MACContextType;

typedef struct {
    uint32 context_id;
    uint8 *out_data;
} Crypto_Ip_TRNGContextType;

typedef void(*Crypto_Async_Callback)(void);

#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_ON)
#define CRYPTO_START_SEC_VAR_NO_INIT_NO_CACHE_UNSPECIFIED
#else
#define CRYPTO_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_ON) */
#include "Crypto_MemMap.h"

uint8 __attribute__((aligned(CACHE_LINE))) HashContext_inter_buff[ROUNDUP(CRYPTO_IP_HASH_INTER_DATA_LEN_MAX, CACHE_LINE)];
uint8 __attribute__((aligned(CACHE_LINE))) HashContext_residual_buff[ROUNDUP(CRYPTO_IP_HASH_INTER_DATA_LEN_MAX, CACHE_LINE)];

/* hold the dual key for xts mode */
uint8 __attribute__((aligned(CACHE_LINE))) CipherContext_dualkey_buff[ROUNDUP(CRYPTO_IP_CIPHER_DUALKEY_LEN_MAX, CACHE_LINE)];
uint8 __attribute__((aligned(CACHE_LINE))) CipherContext_iv_buff[ROUNDUP(CRYPTO_IP_CIPHER_BLOCK_LEN_MAX, CACHE_LINE)];
uint8 __attribute__((aligned(CACHE_LINE))) CipherContext_gcm_buff[CACHE_LINE];

uint8 __attribute__((aligned(CACHE_LINE))) RSAContext_hash_buff[ROUNDUP(CRYPTO_IP_RSA_PADDING_MSG_LEN_MAX, CACHE_LINE)];
uint8 __attribute__((aligned(CACHE_LINE))) RSAContext_msg_buff[ROUNDUP(CRYPTO_IP_RSA_PADDING_MSG_LEN_MAX, CACHE_LINE)];
uint8 __attribute__((aligned(CACHE_LINE))) RSAContext_mac_buff[ROUNDUP(MAC_BUFF_MAX_SIZE, CACHE_LINE)];
RSAKey_Ext_Sdrv __attribute__((aligned(CACHE_LINE))) RSAContext_key_buff[CRYPTO_IP_RSA_CONTEXT_NUM];

uint8 __attribute__((aligned(CACHE_LINE))) MACContext_msg_buff[ROUNDUP(CRYPTO_IP_MAC_BLOCK_PADDING_LEN_MAX, CACHE_LINE)];
uint8 __attribute__((aligned(CACHE_LINE))) MACContext_mac_buff[ROUNDUP(MAC_BUFF_MAX_SIZE, CACHE_LINE)];

uint8 __attribute__((aligned(CACHE_LINE))) TRNGContext_data_buff[ROUNDUP(CRYPTO_IP_TRNG_OUT_LEN_MAX, CACHE_LINE)];

#if (CRYPTO_HSM_STATE_API == STD_ON)
static uint32 __attribute__((aligned(CACHE_LINE))) device_status_buf[ROUNDUP(DEVICE_STATUS_LEN, CACHE_LINE) / 4];
static uint8 __attribute__((aligned(CACHE_LINE))) device_status_mac_buf[ROUNDUP(MAC_BUFF_MAX_SIZE, CACHE_LINE)];
#endif

#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_ON)
#define CRYPTO_STOP_SEC_VAR_NO_INIT_NO_CACHE_UNSPECIFIED
#else
#define CRYPTO_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_ON) */
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Crypto_MemMap.h"

static Crypto_Ip_CipherContextType  aCipherContext;
static Crypto_Ip_PKContextType  aPKContext;
static Crypto_Ip_MACContextType  aMACContext;
static Crypto_Ip_HashContextType aHashContext;
static Crypto_Ip_TRNGContextType aTrngContext;

/* crypto driver obj context, has Current Job info */
static Crypto_ContextType aDriverObj_Context[CRYPTO_DRIVER_OBJ_NUM];
extern Crypto_ObjectType Crypto_aDriverObjectList[CRYPTO_DRIVER_OBJ_NUM];

static uint64 SecureCounter;

#define CRYPTO_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"

uint32 hash_get_digest_size(Crypto_AlgorithmFamilyType autosar_algo);
uint32 get_mac_size(uint32 mac_type);

static FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_RandomGenerate
(
    uint32 objectId,
    uint8 Operate,
    Crypto_ContextType *current_context,
    Crypto_ProcessingType IsSync
);

static FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_SecCountRead
(
    uint32 objectId,
    uint8 Operate,
    Crypto_ContextType *current_context
);

static FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_SecCountInc
(
    uint32 objectId,
    uint8 Operate,
    Crypto_ContextType *current_context
);

static FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_AeadEncrypto
(
    uint32 objectId,
    uint8 Operate,
    Crypto_ContextType *current_context,
    Crypto_ProcessingType IsSync
);

static FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_AeadDecrypto
(
    uint32 objectId,
    uint8 Operate,
    Crypto_ContextType *current_context,
    Crypto_ProcessingType IsSync
);

static FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_Encrypto
(
    uint32 objectId,
    uint8 Operate,
    Crypto_ContextType *current_context,
    Crypto_ProcessingType IsSync
);

static FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_Decrypto
(
    uint32 objectId,
    uint8 Operate,
    Crypto_ContextType *current_context,
    Crypto_ProcessingType IsSync
);

static FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_Hash
(
    uint32 objectId,
    uint8 Operate,
    Crypto_ContextType *current_context,
    Crypto_ProcessingType IsSync
);

static FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_MacGenerate
(
    uint32 objectId,
    uint8 Operate,
    Crypto_ContextType *current_context,
    Crypto_ProcessingType IsSync
);

static FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_MacVerify
(
    uint32 objectId,
    uint8 Operate,
    Crypto_ContextType *current_context,
    Crypto_ProcessingType IsSync
);

static FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_SignatureGenerate
(
    uint32 objectId,
    uint8 Operate,
    Crypto_ContextType *current_context,
    Crypto_ProcessingType IsSync
);

static FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_SignatureVerify
(
    uint32 objectId,
    uint8 Operate,
    Crypto_ContextType *current_context,
    Crypto_ProcessingType IsSync
);

uint32 hash_get_digest_size(Crypto_AlgorithmFamilyType autosar_algo)
{
    uint32 hash_len = 0;

    switch (autosar_algo) {
    case CRYPTO_ALGOFAM_SHA2_224:
    case CRYPTO_ALGOFAM_SHA2_512_224: {
        hash_len = SHA224_DIGESTSIZE;
        break;
    }
    case CRYPTO_ALGOFAM_SHA2_256:
    case CRYPTO_ALGOFAM_SHA2_512_256: {
        hash_len = SHA256_DIGESTSIZE;
        break;
    }
    case CRYPTO_ALGOFAM_SHA2_384: {
        hash_len = SHA384_DIGESTSIZE;
        break;
    }
    case CRYPTO_ALGOFAM_SHA2_512: {
        hash_len = SHA512_DIGESTSIZE;
        break;
    }
    case CRYPTO_ALGOFAM_CUSTOM: {
        hash_len = SM3_DIGESTSIZE;
        break;
    }
    default:
        break;
    }
    return hash_len;
}

uint32 get_mac_size(uint32 mac_type)
{
    uint32 mac_len = 0;

    switch (mac_type) {
    case HMAC_ALG_SHA224:
    case HMAC_ALG_SHA512_224: {
        mac_len = SHA224_DIGESTSIZE;
        break;
    }
    case HMAC_ALG_SHA256:
    case HMAC_ALG_SHA512_256: {
        mac_len = SHA256_DIGESTSIZE;
        break;
    }
    case HMAC_ALG_SHA384: {
        mac_len = SHA384_DIGESTSIZE;
        break;
    }
    case HMAC_ALG_SHA512: {
        mac_len = SHA512_DIGESTSIZE;
        break;
    }
    case HMAC_ALG_SM3: {
        mac_len = SM3_DIGESTSIZE;
        break;
    }
    /*cmac size is chiper one block size*/
    case CMAC_SKE_ALG_AES_128: {
        mac_len = 16;
        break;
    }
    case CMAC_SKE_ALG_AES_192: {
        mac_len = 24;
        break;
    }
    case CMAC_SKE_ALG_AES_256: {
        mac_len = 32;
        break;
    }
    case CMAC_SKE_ALG_SM4: {
        mac_len = 16;
        break;
    }
    default:
        break;
    }
    return mac_len;
}

/*PRQA S 2755 2*/
static FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_JobHandle
(
    uint32 objectId,
    uint8 Operate,
    Crypto_ContextType *current_context,
    Crypto_ProcessingType IsSync
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal = E_OK;
    Crypto_ServiceInfoType crypto_service;

    crypto_service = current_context->aJobInfo.aJob.jobPrimitiveInfo->primitiveInfo->service;

    switch (crypto_service) {
        case CRYPTO_HASH: {
            RetVal = Crypto_Ip_Hash(objectId, Operate, current_context, IsSync);
            break;
        }

        case CRYPTO_MACGENERATE: {
            RetVal = Crypto_Ip_MacGenerate(objectId, Operate, current_context, IsSync);
            break;
        }

        case CRYPTO_MACVERIFY: {
            RetVal = Crypto_Ip_MacVerify(objectId, Operate, current_context, IsSync);
            break;
        }

        case CRYPTO_ENCRYPT: {
            RetVal = Crypto_Ip_Encrypto(objectId, Operate, current_context, IsSync);
            break;
        }

        case CRYPTO_DECRYPT: {
            RetVal = Crypto_Ip_Decrypto(objectId, Operate, current_context, IsSync);
            break;
        }

        case CRYPTO_AEADENCRYPT: {
            RetVal = Crypto_Ip_AeadEncrypto(objectId, Operate, current_context, IsSync);
            break;
        }

        case CRYPTO_AEADDECRYPT: {
            RetVal = Crypto_Ip_AeadDecrypto(objectId, Operate, current_context, IsSync);
            break;
        }

        case CRYPTO_SIGNATUREGENERATE: {
            RetVal = Crypto_Ip_SignatureGenerate(objectId, Operate, current_context, IsSync);
            break;
        }

        case CRYPTO_SIGNATUREVERIFY: {
            RetVal = Crypto_Ip_SignatureVerify(objectId, Operate, current_context, IsSync);
            break;
        }

        case CRYPTO_SECCOUNTERINCREMENT: {
            RetVal = Crypto_Ip_SecCountInc(objectId, Operate, current_context);
            break;
        }

        case CRYPTO_SECCOUNTERREAD: {
            RetVal = Crypto_Ip_SecCountRead(objectId, Operate, current_context);
            break;
        }

        case CRYPTO_RANDOMGENERATE: {
            RetVal = Crypto_Ip_RandomGenerate(objectId, Operate, current_context, IsSync);
            break;
        }

        default: {
            break;
        }
    }

    return RetVal;
}

static FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_DoHmacGenerate
(
    uint32 objectId,
    Crypto_ContextType *current_context,
    uint8 algorithm,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_OK;
    uint32 mode;
    Crypto_AlgorithmFamilyType Algorithm_Mode;
    Crypto_JobType *job;

    Crypto_KeyType *KeyPtr;
    Crypto_KeyElementType *KeyElementPtr;
    uint8 *msg_DataAddr;
    uint32 msg_DataSize;
    uint8 *Output_DataAddr;
    Crypto_Ip_MACContextType *Context;

    job = &(current_context->aJobInfo.aJob);

    msg_DataSize  = job->jobPrimitiveInputOutput.inputLength;
    Output_DataAddr = job->jobPrimitiveInputOutput.outputPtr;

    Algorithm_Mode = job->jobPrimitiveInfo->primitiveInfo->algorithm.family;

    do {

        RetVal = Crypto_GetKeyPtr(job->cryptoKeyId, &KeyPtr);
        if (E_OK != RetVal) {
            break;
        }
        RetVal = Crypto_GetElementPtr(KeyPtr, CRYPTO_KEY_MATERIAL_COMMON_ID, &KeyElementPtr);
        if (E_OK != RetVal) {
            break;
        }

        Context = (Crypto_Ip_MACContextType *)(current_context->pIpContext);
        if (Context == NULL_PTR) {
            return E_NOT_OK;
        }

        /* MAC msg must block align, padding 0*/
        if (msg_DataSize & 0x0F) {
            if(msg_DataSize > CRYPTO_IP_MAC_BLOCK_PADDING_LEN_MAX){
                return E_NOT_OK;
            }else{
                mini_memcpy_s(Context->msg_data, job->jobPrimitiveInputOutput.inputPtr, msg_DataSize);
                mini_memclr_s(Context->msg_data + msg_DataSize, 16 - (msg_DataSize & 0x0F));
                msg_DataAddr  = Context->msg_data;
            }
        }else{
            msg_DataAddr  = (uint8 *)job->jobPrimitiveInputOutput.inputPtr;
        }

        mode = hmac_algo_mode_mapping(Algorithm_Mode);

        *(job->jobPrimitiveInputOutput.outputLengthPtr) = get_mac_size(mode);

        if ((((uint32)msg_DataAddr & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0) ||
            (((uint32)Output_DataAddr & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0)) {
            RetVal = E_NOT_OK;
            return RetVal;
        }

#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
        arch_clean_cache_range(msg_DataAddr, msg_DataSize);
        arch_clean_cache_range(KeyElementPtr->pCryptoElementContent, KeyElementPtr->u32CryptoElementWritedSize);
        arch_invalidate_cache_range(Output_DataAddr, *(job->jobPrimitiveInputOutput.outputLengthPtr));
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */

        RetVal = Hsm_host_hmac_gen((uint8)mode, msg_DataAddr, msg_DataSize,
                                    KeyPtr->CryptoHSMKeyType,
                                    KeyElementPtr->pCryptoElementContent,
                                    CRYPTO_KEY_ELEMENT_ENC_KEY_ID,
                                    KeyElementPtr->u32CryptoElementWritedSize,
                                    Output_DataAddr, Context->mac_data, IsSync);

    } while (0);
    (void)objectId;

    return RetVal;
}

static FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_DoHmacVerify
(
    uint32 objectId,
    Crypto_ContextType *current_context,
    uint8 algorithm,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_OK;
    uint32 mode;
    Crypto_AlgorithmFamilyType  Algorithm_Mode;

    Crypto_KeyType *KeyPtr;
    Crypto_KeyElementType *KeyElementPtr;
    uint8 *msg_DataAddr;
    uint32 msg_DataSize;
    const uint8 *Mac_DataAddr;
    uint32 Mac_DataSize;
    Crypto_Ip_MACContextType *Context;

    Crypto_JobType *job;

    job = &(current_context->aJobInfo.aJob);

    msg_DataSize  = job->jobPrimitiveInputOutput.inputLength;
    Mac_DataAddr = job->jobPrimitiveInputOutput.secondaryInputPtr;
    Mac_DataSize = job->jobPrimitiveInputOutput.secondaryInputLength;

    Algorithm_Mode = job->jobPrimitiveInfo->primitiveInfo->algorithm.family;

    do {

        RetVal = Crypto_GetKeyPtr(job->cryptoKeyId, &KeyPtr);
        if (E_OK != RetVal) {
            break;
        }
        RetVal = Crypto_GetElementPtr(KeyPtr, CRYPTO_KEY_MATERIAL_COMMON_ID, &KeyElementPtr);
        if (E_OK != RetVal) {
            break;
        }

        Context = (Crypto_Ip_MACContextType *)(current_context->pIpContext);
        if (Context == NULL_PTR) {
            return E_NOT_OK;
        }

        /* MAC msg must block align, padding 0*/
        if (msg_DataSize & 0x0F) {
            if(msg_DataSize > CRYPTO_IP_MAC_BLOCK_PADDING_LEN_MAX){
                return E_NOT_OK;
            }else{
                mini_memcpy_s(Context->msg_data, job->jobPrimitiveInputOutput.inputPtr, msg_DataSize);
                mini_memclr_s(Context->msg_data + msg_DataSize, 16 - (msg_DataSize & 0x0F));
                msg_DataAddr  = Context->msg_data;
            }
        }else{
            msg_DataAddr  = (uint8 *)job->jobPrimitiveInputOutput.inputPtr;
        }

        mode = hmac_algo_mode_mapping(Algorithm_Mode);

        if ((((uint32)msg_DataAddr & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0) ||
            (((uint32)Mac_DataAddr & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0)) {
            RetVal = E_NOT_OK;
            return RetVal;
        }

#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
        arch_clean_cache_range(msg_DataAddr, msg_DataSize);
        arch_clean_cache_range(KeyElementPtr->pCryptoElementContent, KeyElementPtr->u32CryptoElementWritedSize);
        arch_clean_cache_range(Mac_DataAddr, Mac_DataSize);
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */

        RetVal = Hsm_host_hmac_verify((uint8)mode, msg_DataAddr, msg_DataSize,
                                       KeyPtr->CryptoHSMKeyType,
                                       KeyElementPtr->pCryptoElementContent,
                                       CRYPTO_KEY_ELEMENT_ENC_KEY_ID,
                                       KeyElementPtr->u32CryptoElementWritedSize,
                                       Mac_DataAddr, Mac_DataSize, Context->mac_data,
                                       job, IsSync);

    } while (0);
    (void)objectId;

    return RetVal;
}

static FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_DoCmacGenerate
(
    uint32 objectId,
    Crypto_ContextType *current_context,
    uint8 algorithm,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_OK;
    uint8 mode;
    Crypto_AlgorithmFamilyType  Algorithm_Mode;

    Crypto_KeyType *KeyPtr;
    Crypto_KeyElementType *KeyElementPtr;
    uint8 *msg_DataAddr;
    uint32 msg_DataSize;
    uint8 *Output_DataAddr;
    Crypto_Ip_MACContextType *Context;
    Crypto_JobType *job;

    job = &(current_context->aJobInfo.aJob);

    msg_DataSize  = job->jobPrimitiveInputOutput.inputLength;
    Output_DataAddr = job->jobPrimitiveInputOutput.outputPtr;

    Algorithm_Mode = job->jobPrimitiveInfo->primitiveInfo->algorithm.family;

    do {

        RetVal = Crypto_GetKeyPtr(job->cryptoKeyId, &KeyPtr);
        if (E_OK != RetVal) {
            break;
        }
        RetVal = Crypto_GetElementPtr(KeyPtr, CRYPTO_KEY_MATERIAL_COMMON_ID, &KeyElementPtr);
        if (E_OK != RetVal) {
            break;
        }

        Context = (Crypto_Ip_MACContextType *)(current_context->pIpContext);
        if (Context == NULL_PTR) {
            return E_NOT_OK;
        }

        /* MAC msg must block align, padding 0*/
        if (msg_DataSize & 0x0F) {
            if(msg_DataSize > CRYPTO_IP_MAC_BLOCK_PADDING_LEN_MAX){
                return E_NOT_OK;
            }else{
                mini_memcpy_s(Context->msg_data, job->jobPrimitiveInputOutput.inputPtr, msg_DataSize);
                mini_memclr_s(Context->msg_data + msg_DataSize, 16 - (msg_DataSize & 0x0F));
                msg_DataAddr  = Context->msg_data;
            }
        }else{
            msg_DataAddr  = (uint8 *)job->jobPrimitiveInputOutput.inputPtr;
        }

        mode = cmac_algo_mode_mapping(Algorithm_Mode, KeyElementPtr->u32CryptoElementWritedSize);

        *(job->jobPrimitiveInputOutput.outputLengthPtr) = get_mac_size(mode);

        if ((((uint32)msg_DataAddr & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0) ||
            (((uint32)Output_DataAddr & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0)) {
            RetVal = E_NOT_OK;
            return RetVal;
        }

#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
        arch_clean_cache_range(msg_DataAddr, msg_DataSize);
        arch_clean_cache_range(KeyElementPtr->pCryptoElementContent, KeyElementPtr->u32CryptoElementWritedSize);
        arch_invalidate_cache_range(Output_DataAddr, *(job->jobPrimitiveInputOutput.outputLengthPtr));
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */

        RetVal = Hsm_host_cmac_gen((uint8)mode, msg_DataAddr, msg_DataSize,
                                    KeyPtr->CryptoHSMKeyType,
                                    KeyElementPtr->pCryptoElementContent,
                                    CRYPTO_KEY_ELEMENT_ENC_KEY_ID,
                                    Output_DataAddr, Context->mac_data, IsSync);

    } while (0);

    (void)objectId;

    return RetVal;
}

static FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_DoCmacVerify
(
    uint32 objectId,
    Crypto_ContextType *current_context,
    uint8 algorithm,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_OK;
    uint8 mode;
    Crypto_AlgorithmFamilyType Algorithm_Mode;

    Crypto_KeyType *KeyPtr;
    Crypto_KeyElementType *KeyElementPtr;
    uint8 *msg_DataAddr;
    uint32 msg_DataSize;
    const uint8 *Mac_DataAddr;
    uint32 Mac_DataSize;
    Crypto_Ip_MACContextType *Context;

    Crypto_JobType *job;

    job = &(current_context->aJobInfo.aJob);

    msg_DataSize  = job->jobPrimitiveInputOutput.inputLength;
    Mac_DataAddr = job->jobPrimitiveInputOutput.secondaryInputPtr;
    Mac_DataSize = job->jobPrimitiveInputOutput.secondaryInputLength;

    Algorithm_Mode = job->jobPrimitiveInfo->primitiveInfo->algorithm.family;

    do {

        RetVal = Crypto_GetKeyPtr(job->cryptoKeyId, &KeyPtr);
        if (E_OK != RetVal) {
            break;
        }
        RetVal = Crypto_GetElementPtr(KeyPtr, CRYPTO_KEY_MATERIAL_COMMON_ID, &KeyElementPtr);
        if (E_OK != RetVal) {
            break;
        }

        Context = (Crypto_Ip_MACContextType *)(current_context->pIpContext);
        if (Context == NULL_PTR) {
            return E_NOT_OK;
        }

        /* MAC msg must block align, padding 0*/
        if (msg_DataSize & 0x0F) {
            if(msg_DataSize > CRYPTO_IP_MAC_BLOCK_PADDING_LEN_MAX){
                return E_NOT_OK;
            }else{
                mini_memcpy_s(Context->msg_data, job->jobPrimitiveInputOutput.inputPtr, msg_DataSize);
                mini_memclr_s(Context->msg_data + msg_DataSize, 16 - (msg_DataSize & 0x0F));
                msg_DataAddr  = Context->msg_data;
            }
        }else{
            msg_DataAddr  = (uint8 *)job->jobPrimitiveInputOutput.inputPtr;
        }

        mode = cmac_algo_mode_mapping(Algorithm_Mode, KeyElementPtr->u32CryptoElementWritedSize);

        if ((((uint32)msg_DataAddr & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0) ||
            (((uint32)Mac_DataAddr & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0)) {
            RetVal = E_NOT_OK;
            return RetVal;
        }

#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
        arch_clean_cache_range(msg_DataAddr, msg_DataSize);
        arch_clean_cache_range(KeyElementPtr->pCryptoElementContent, KeyElementPtr->u32CryptoElementWritedSize);
        arch_clean_cache_range(Mac_DataAddr, Mac_DataSize);
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */

        RetVal = Hsm_host_cmac_verify((uint8)mode, msg_DataAddr, msg_DataSize,
                                      KeyPtr->CryptoHSMKeyType,
                                      KeyElementPtr->pCryptoElementContent,
                                      CRYPTO_KEY_ELEMENT_ENC_KEY_ID,
                                      Mac_DataAddr, Mac_DataSize, Context->mac_data,
                                      job, IsSync);

    } while (0);

    (void)objectId;

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_Encrypt_RSA
(
    uint32 objectId,
    Crypto_ContextType *current_context,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_OK;
    uint8 *Input_DataAddr;
    uint8 *Output_DataAddr;

    Crypto_KeyType *KeyPtr;
    RSAKey_Ext_Sdrv *Key_pub;
    Crypto_Ip_PKContextType *Context;
    Crypto_JobType *job;
    uint32 Modulus_Size;

    job = &(current_context->aJobInfo.aJob);

    /* get pubkey value */
    RetVal = Crypto_GetKeyPtr(job->cryptoKeyId, &KeyPtr);

    if (E_OK != RetVal) {
        return RetVal;
    }

    Context = (Crypto_Ip_PKContextType *)(current_context->pIpContext);
    if (Context == NULL_PTR) {
        return E_NOT_OK;
    }

    RetVal = Crypto_GetElementBuffInBlock(job->cryptoKeyId, CRYPTO_KE_SIGNATURE_KEY,
                                          KeyPtr->CryptoKeyType, (uint8 **)&(Context->key_data),
                                          0, CRYPTO_KEY_BLOCK_BUFF_FOR_JOB, FALSE);
    if (E_OK != RetVal) {
        return RetVal;
    }

    Key_pub = (RSAKey_Ext_Sdrv *)(Context->key_data);
    Modulus_Size = Key_pub->keybuff_head.n_sz;
    /*update n e for img update(memmap changed, keyaddr store in flash is old)*/
    Key_pub->keybuff_head.n = (uint8 *)Key_pub + ROUNDUP(sizeof(RSAKey_Head_Ext_Sdrv), CACHE_LINE);
    Key_pub->keybuff_head.e = Key_pub->keybuff_head.n + Modulus_Size;

    Output_DataAddr = job->jobPrimitiveInputOutput.outputPtr;
    Input_DataAddr = (uint8 *)job->jobPrimitiveInputOutput.inputPtr;
    *job->jobPrimitiveInputOutput.outputLengthPtr = Modulus_Size;

    Context->context_id = job->jobId;

    do {
        /*check buff cache align and sync cache*/
        if ((((uint32)Input_DataAddr & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0)
        || (((uint32)Output_DataAddr & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0)
        || (((uint32)Key_pub->keybuff_head.n & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0)
        || (((uint32)Key_pub->keybuff_head.e & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0)) {
            RetVal = E_NOT_OK;
            return RetVal;
        }

#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
        arch_clean_cache_range(Input_DataAddr, Modulus_Size);
        arch_clean_cache_range(Key_pub->keybuff_head.n, Modulus_Size);
        arch_clean_cache_range(Key_pub->keybuff_head.e, Modulus_Size);
        arch_invalidate_cache_range(Output_DataAddr, Modulus_Size);
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */

        RetVal = Hsm_host_RsaEncrypt(Key_pub->keybuff_head.n, Key_pub->keybuff_head.e,
                                     Modulus_Size, Input_DataAddr, Output_DataAddr, IsSync);

    } while (0);

    /* release context */
    Context->context_id = CRYPTO_IP_UNUSED_CONTEXT_ID;

    (void)objectId;

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_Decrypt_RSA
(
    uint32 objectId,
    Crypto_ContextType *current_context,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_OK;
    const uint8 *Cipher_Addr;
    uint8 *Output_DataAddr;

    Crypto_KeyType *KeyPtr;
    RSAKey_Ext_Sdrv *Key_pri;
    Crypto_JobType *job;

    Crypto_Ip_PKContextType *Context;

    uint32 Modulus_Size;

    job = &(current_context->aJobInfo.aJob);

    Context = (Crypto_Ip_PKContextType *)(current_context->pIpContext);
    if (Context == NULL_PTR) {
        return E_NOT_OK;
    }
    Context->context_id = job->jobId;

    RetVal = Crypto_GetKeyPtr(job->cryptoKeyId, &KeyPtr);
    if (E_OK != RetVal) {
        return RetVal;
    }

    RetVal = Crypto_GetElementBuffInBlock(job->cryptoKeyId, CRYPTO_KE_SIGNATURE_KEY,
                                          KeyPtr->CryptoKeyType, (uint8 **)&(Context->key_data),
                                          0, CRYPTO_KEY_BLOCK_BUFF_FOR_JOB, FALSE);
    if (E_OK != RetVal) {
        return RetVal;
    }

    Key_pri = (RSAKey_Ext_Sdrv *)(Context->key_data);

    Modulus_Size = Key_pri->keybuff_head.n_sz;

    /*update n e d for img update(memmap changed, keyaddr store in flash is old)*/
    Key_pri->keybuff_head.n = (uint8 *)Key_pri + ROUNDUP(sizeof(RSAKey_Head_Ext_Sdrv), CACHE_LINE);
    Key_pri->keybuff_head.e = Key_pri->keybuff_head.n + Modulus_Size;
    Key_pri->keybuff_head.d = Key_pri->keybuff_head.e + Modulus_Size;

    if (Modulus_Size != job->jobPrimitiveInputOutput.inputLength) {
        return E_NOT_OK;
    }

    Cipher_Addr = job->jobPrimitiveInputOutput.inputPtr;
    Output_DataAddr = job->jobPrimitiveInputOutput.outputPtr;
    if ((((uint32)Cipher_Addr & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0) ||
        (((uint32)Output_DataAddr & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0)) {
            RetVal = E_NOT_OK;
            return RetVal;
    }

#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
    arch_clean_cache_range(Cipher_Addr, Modulus_Size);
    arch_invalidate_cache_range(Output_DataAddr, Modulus_Size);
    arch_clean_cache_range(Key_pri->keybuff_head.n, Modulus_Size);
    arch_clean_cache_range(Key_pri->keybuff_head.e, Modulus_Size);
    arch_clean_cache_range(Key_pri->keybuff_head.d, Modulus_Size);
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */

    RetVal = Hsm_host_RsaDecrypt(Cipher_Addr, Key_pri->keybuff_head.n,
                                 Key_pri->keybuff_head.e, Key_pri->keybuff_head.d,
                                 Modulus_Size, Output_DataAddr,
                                 Key_pri->keybuff_head.keytype,
                                 Key_pri->keybuff_head.keyid1,Context->mac_data,
                                 IsSync);

    if (E_OK == RetVal) {
        *job->jobPrimitiveInputOutput.outputLengthPtr = Modulus_Size;
    }

    /* release context */
    Context->context_id = CRYPTO_IP_UNUSED_CONTEXT_ID;
    (void)objectId;

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_Encrypt_RSAES_OAEP
(
    uint32 objectId,
    Crypto_ContextType *current_context,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_OK;
    uint8 *Padded_Msg;
    uint8 *Output_DataAddr;

    Crypto_KeyType *KeyPtr;
    RSAKey_Ext_Sdrv *Key_pub;
    Crypto_Ip_PKContextType *Context;
    Crypto_JobType *job;

    uint32 Modulus_Size;
    uint32 Msg_Len;

    job = &(current_context->aJobInfo.aJob);

    /* get pubkey value */
    RetVal = Crypto_GetKeyPtr(job->cryptoKeyId, &KeyPtr);

    if (E_OK != RetVal) {
        return RetVal;
    }

    Context = (Crypto_Ip_PKContextType *)(current_context->pIpContext);
    if (Context == NULL_PTR) {
        return E_NOT_OK;
    }

    RetVal = Crypto_GetElementBuffInBlock(job->cryptoKeyId, CRYPTO_KE_SIGNATURE_KEY,
                                          KeyPtr->CryptoKeyType, (uint8 **)&(Context->key_data),
                                          0, CRYPTO_KEY_BLOCK_BUFF_FOR_JOB, FALSE);
    if (E_OK != RetVal) {
        return RetVal;
    }

    Key_pub = (RSAKey_Ext_Sdrv *)(Context->key_data);

    Modulus_Size = Key_pub->keybuff_head.n_sz;

    /*update n e for img update(memmap changed, keyaddr store in flash is old)*/
    Key_pub->keybuff_head.n = (uint8 *)Key_pub + ROUNDUP(sizeof(RSAKey_Head_Ext_Sdrv), CACHE_LINE);
    Key_pub->keybuff_head.e = Key_pub->keybuff_head.n + Modulus_Size;

    Msg_Len = job->jobPrimitiveInputOutput.inputLength;

    Output_DataAddr = job->jobPrimitiveInputOutput.outputPtr;
    *job->jobPrimitiveInputOutput.outputLengthPtr = Modulus_Size;

    Context->context_id = job->jobId;

    /* get a mem area of padding msg*/
    Padded_Msg = Context->msg_data;

    do {
        RetVal = rsa_pad_eme_oaep_encode(Modulus_Size,
                                         job->jobPrimitiveInfo->primitiveInfo->algorithm.secondaryFamily,
                                         Padded_Msg,
                                         (uint8 *)job->jobPrimitiveInputOutput.inputPtr,
                                         Msg_Len);
        if (RetVal == E_NOT_OK) {
            break;
        }

        /*check buff cache align and sync cache*/
        if ((((uint32)Padded_Msg & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0)
        || (((uint32)Output_DataAddr & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0)
        || (((uint32)Key_pub->keybuff_head.n & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0)
        || (((uint32)Key_pub->keybuff_head.e & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0)) {
            RetVal = E_NOT_OK;
            return RetVal;
        }

#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
        arch_clean_cache_range(Padded_Msg, Modulus_Size);
        arch_clean_cache_range(Key_pub->keybuff_head.n, Modulus_Size);
        arch_clean_cache_range(Key_pub->keybuff_head.e, Modulus_Size);
        arch_invalidate_cache_range(Output_DataAddr, Modulus_Size);
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */

        RetVal = Hsm_host_RsaEncrypt(Key_pub->keybuff_head.n, Key_pub->keybuff_head.e,
                                     Modulus_Size, Padded_Msg, Output_DataAddr,
                                     CRYPTO_PROCESSING_SYNC);

    } while (0);

    /* release context */
    Context->context_id = CRYPTO_IP_UNUSED_CONTEXT_ID;

    (void)objectId;

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_Decrypt_RSAES_OAEP
(
    uint32 objectId,
    Crypto_ContextType *current_context,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_OK;
    const uint8 *Cipher_Addr;
    uint8 *Output_DataAddr;
    uint8 *Output_Addr_backup;

    Crypto_KeyType *KeyPtr;
    RSAKey_Ext_Sdrv *Key_pri;
    Crypto_JobType *job;

    Crypto_Ip_PKContextType *Context;

    uint32 Modulus_Size;

    job = &(current_context->aJobInfo.aJob);

    Context = (Crypto_Ip_PKContextType *)(current_context->pIpContext);
    if (Context == NULL_PTR) {
        return E_NOT_OK;
    }
    Context->context_id = job->jobId;

    RetVal = Crypto_GetKeyPtr(job->cryptoKeyId, &KeyPtr);
    if (E_OK != RetVal) {
        return RetVal;
    }

    RetVal = Crypto_GetElementBuffInBlock(job->cryptoKeyId, CRYPTO_KE_SIGNATURE_KEY,
                                          KeyPtr->CryptoKeyType, (uint8 **)&(Context->key_data),
                                          0, CRYPTO_KEY_BLOCK_BUFF_FOR_JOB, FALSE);
    if (E_OK != RetVal) {
        return RetVal;
    }

    Key_pri = (RSAKey_Ext_Sdrv *)(Context->key_data);

    Modulus_Size = Key_pri->keybuff_head.n_sz;

    /*update n e d for img update(memmap changed, keyaddr store in flash is old)*/
    Key_pri->keybuff_head.n = (uint8 *)Key_pri + ROUNDUP(sizeof(RSAKey_Head_Ext_Sdrv), CACHE_LINE);
    Key_pri->keybuff_head.e = Key_pri->keybuff_head.n + Modulus_Size;
    Key_pri->keybuff_head.d = Key_pri->keybuff_head.e + Modulus_Size;

    if (Modulus_Size != job->jobPrimitiveInputOutput.inputLength) {
        return E_NOT_OK;
    }

    Cipher_Addr = job->jobPrimitiveInputOutput.inputPtr;
    Output_DataAddr = job->jobPrimitiveInputOutput.outputPtr;
    if ((((uint32)Cipher_Addr & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0) ||
        (((uint32)Output_DataAddr & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0)) {
            RetVal = E_NOT_OK;
            return RetVal;
    }

#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
    arch_clean_cache_range(Cipher_Addr, Modulus_Size);
    arch_invalidate_cache_range(Output_DataAddr, Modulus_Size);
    arch_clean_cache_range(Key_pri->keybuff_head.n, Modulus_Size);
    arch_clean_cache_range(Key_pri->keybuff_head.e, Modulus_Size);
    arch_clean_cache_range(Key_pri->keybuff_head.d, Modulus_Size);
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */

    RetVal = Hsm_host_RsaDecrypt(Cipher_Addr, Key_pri->keybuff_head.n,
                                 Key_pri->keybuff_head.e, Key_pri->keybuff_head.d,
                                 Modulus_Size, Output_DataAddr,
                                 Key_pri->keybuff_head.keytype,
                                 Key_pri->keybuff_head.keyid1,Context->mac_data,
                                 CRYPTO_PROCESSING_SYNC);

    if (E_OK == RetVal) {
        Output_Addr_backup = Output_DataAddr;
        rsa_pad_eme_oaep_decode(Modulus_Size,
                                job->jobPrimitiveInfo->primitiveInfo->algorithm.secondaryFamily,
                                Output_DataAddr,&Output_DataAddr,
                                 job->jobPrimitiveInputOutput.outputLengthPtr);
        mini_memcpy_s(Output_Addr_backup, Output_DataAddr, *job->jobPrimitiveInputOutput.outputLengthPtr);
    }

    /* release context */
    Context->context_id = CRYPTO_IP_UNUSED_CONTEXT_ID;
    (void)objectId;

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_Encrypt_RSAES_PKCS1_v1_5
(
    uint32 objectId,
    Crypto_ContextType *current_context,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_OK;
    uint8 *Padded_Msg;
    uint8 *Output_DataAddr;

    Crypto_KeyType *KeyPtr;
    RSAKey_Ext_Sdrv *Key_pub;
    Crypto_Ip_PKContextType *Context;
    Crypto_JobType *job;

    uint32 Modulus_Size;
    uint32 Msg_Len;
    uint32 Random_Len;

    job = &(current_context->aJobInfo.aJob);


    /* get pubkey value */

    RetVal = Crypto_GetKeyPtr(job->cryptoKeyId, &KeyPtr);

    if (E_OK != RetVal) {
        return RetVal;
    }

    Context = (Crypto_Ip_PKContextType *)(current_context->pIpContext);
    if (Context == NULL_PTR) {
        return E_NOT_OK;
    }

    RetVal = Crypto_GetElementBuffInBlock(job->cryptoKeyId, CRYPTO_KE_SIGNATURE_KEY,
                                          KeyPtr->CryptoKeyType, (uint8 **)&(Context->key_data),
                                          0, CRYPTO_KEY_BLOCK_BUFF_FOR_JOB, FALSE);
    if (E_OK != RetVal) {
        return RetVal;
    }

    Key_pub = (RSAKey_Ext_Sdrv *)(Context->key_data);

    Modulus_Size = Key_pub->keybuff_head.n_sz;

    /*update n e for img update(memmap changed, keyaddr store in flash is old)*/
    Key_pub->keybuff_head.n = (uint8 *)Key_pub + ROUNDUP(sizeof(RSAKey_Head_Ext_Sdrv), CACHE_LINE);
    Key_pub->keybuff_head.e = Key_pub->keybuff_head.n + Modulus_Size;

    Msg_Len = job->jobPrimitiveInputOutput.inputLength;
    Random_Len = Modulus_Size - Msg_Len - 3U;

    Output_DataAddr = job->jobPrimitiveInputOutput.outputPtr;
    *job->jobPrimitiveInputOutput.outputLengthPtr = Modulus_Size;

    Context->context_id = job->jobId;

    /* get a mem area of padding msg*/
    Padded_Msg = Context->msg_data;

    do {
        if (Random_Len < 8U) {
            /* The length of random number must not less than 8. */
            RetVal = E_NOT_OK;
            break;
        }

        RetVal = rsa_pad_eme_pkcs_encode(Modulus_Size, Padded_Msg,
                                         (uint8 *)job->jobPrimitiveInputOutput.inputPtr,
                                         Msg_Len);
        if (RetVal == E_NOT_OK) {
            break;
        }

        /*check buff cache align and sync cache*/
        if ((((uint32)Padded_Msg & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0)
        || (((uint32)Output_DataAddr & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0)
        || (((uint32)Key_pub->keybuff_head.n & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0)
        || (((uint32)Key_pub->keybuff_head.e & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0)) {
            RetVal = E_NOT_OK;
            return RetVal;
        }

#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
        arch_clean_cache_range(Padded_Msg, Modulus_Size);
        arch_clean_cache_range(Key_pub->keybuff_head.n, Modulus_Size);
        arch_clean_cache_range(Key_pub->keybuff_head.e, Modulus_Size);
        arch_invalidate_cache_range(Output_DataAddr, Modulus_Size);
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */

        RetVal = Hsm_host_RsaEncrypt(Key_pub->keybuff_head.n, Key_pub->keybuff_head.e,
                                     Modulus_Size, Padded_Msg, Output_DataAddr,
                                     CRYPTO_PROCESSING_SYNC);

    } while (0);

    /* release context */
    Context->context_id = CRYPTO_IP_UNUSED_CONTEXT_ID;

    (void)objectId;

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_Decrypt_RSAES_PKCS1_v1_5
(
    uint32 objectId,
    Crypto_ContextType *current_context,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_OK;
    const uint8 *Cipher_Addr;
    uint8 *Output_DataAddr;
    uint8 *Output_Addr_backup;

    Crypto_KeyType *KeyPtr;
    RSAKey_Ext_Sdrv *Key_pri;
    Crypto_JobType *job;

    Crypto_Ip_PKContextType *Context;

    uint32 Modulus_Size;

    job = &(current_context->aJobInfo.aJob);

    Context = (Crypto_Ip_PKContextType *)(current_context->pIpContext);
    if (Context == NULL_PTR) {
        return E_NOT_OK;
    }
    Context->context_id = job->jobId;

    /* get key value, only support CRYPTO_KE_FORMAT_BIN_ RSA_PRIVATEKEY,
     * private keys is defined according to RFC3447 */
    RetVal = Crypto_GetKeyPtr(job->cryptoKeyId, &KeyPtr);

    if (E_OK != RetVal) {
        return RetVal;
    }

    RetVal = Crypto_GetElementBuffInBlock(job->cryptoKeyId, CRYPTO_KE_SIGNATURE_KEY,
                                          KeyPtr->CryptoKeyType, (uint8 **)&(Context->key_data),
                                          0, CRYPTO_KEY_BLOCK_BUFF_FOR_JOB, FALSE);
    if (E_OK != RetVal) {
        return RetVal;
    }

    Key_pri = (RSAKey_Ext_Sdrv *)(Context->key_data);

    Modulus_Size = Key_pri->keybuff_head.n_sz;

    /*update n e d for img update(memmap changed, keyaddr store in flash is old)*/
    Key_pri->keybuff_head.n = (uint8 *)Key_pri + ROUNDUP(sizeof(RSAKey_Head_Ext_Sdrv), CACHE_LINE);
    Key_pri->keybuff_head.e = Key_pri->keybuff_head.n + Modulus_Size;
    Key_pri->keybuff_head.d = Key_pri->keybuff_head.e + Modulus_Size;

    if (Modulus_Size != job->jobPrimitiveInputOutput.inputLength) {
        return E_NOT_OK;
    }

    Cipher_Addr = job->jobPrimitiveInputOutput.inputPtr;
    Output_DataAddr = job->jobPrimitiveInputOutput.outputPtr;
    if ((((uint32)Cipher_Addr & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0) ||
        (((uint32)Output_DataAddr & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0)) {
            RetVal = E_NOT_OK;
            return RetVal;
    }

#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
    arch_clean_cache_range(Cipher_Addr, Modulus_Size);
    arch_invalidate_cache_range(Output_DataAddr, Modulus_Size);
    arch_clean_cache_range(Key_pri->keybuff_head.n, Modulus_Size);
    arch_clean_cache_range(Key_pri->keybuff_head.e, Modulus_Size);
    arch_clean_cache_range(Key_pri->keybuff_head.d, Modulus_Size);
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */

    RetVal = Hsm_host_RsaDecrypt(Cipher_Addr, Key_pri->keybuff_head.n,
                                 Key_pri->keybuff_head.e,
                                 Key_pri->keybuff_head.d, Modulus_Size,
                                 Output_DataAddr,Key_pri->keybuff_head.keytype,
                                 Key_pri->keybuff_head.keyid1,Context->mac_data,
                                 CRYPTO_PROCESSING_SYNC);

    if (E_OK == RetVal) {
        Output_Addr_backup = Output_DataAddr;
        rsa_pad_eme_pkcs_decode(Modulus_Size,Output_DataAddr,&Output_DataAddr,
                                job->jobPrimitiveInputOutput.outputLengthPtr);
        mini_memcpy_s(Output_Addr_backup, Output_DataAddr, *job->jobPrimitiveInputOutput.outputLengthPtr);
    }

    /* release context */
    Context->context_id = CRYPTO_IP_UNUSED_CONTEXT_ID;
    (void)objectId;

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_Encrypt_SM2
(
    uint32 objectId,
    Crypto_ContextType *current_context,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_OK;
    uint8 *Output_DataAddr;
    uint8 *Msg;
    uint32 Msg_Len;
    uint8 *Key_pub;

    Crypto_KeyType *KeyPtr;
    Crypto_KeyElementType *KeyElementPtr;
    Crypto_Ip_PKContextType *Context;
    Crypto_JobType *job;

    job = &(current_context->aJobInfo.aJob);

    /* get pubkey value */
    RetVal = Crypto_GetKeyPtr(job->cryptoKeyId, &KeyPtr);

    if (E_OK != RetVal) {
        return RetVal;
    }

    Context = (Crypto_Ip_PKContextType *)(current_context->pIpContext);
    if (Context == NULL_PTR) {
        return E_NOT_OK;
    }

    RetVal = Crypto_GetElementPtr(KeyPtr, CRYPTO_KE_SIGNATURE_KEY, &KeyElementPtr);
    if (E_OK != RetVal) {
        return E_NOT_OK;
    }

    Key_pub = KeyElementPtr->pCryptoElementContent;
    Msg = (uint8 *)job->jobPrimitiveInputOutput.inputPtr;
    Msg_Len = job->jobPrimitiveInputOutput.inputLength;
    Output_DataAddr = job->jobPrimitiveInputOutput.outputPtr;
    Context->context_id = job->jobId;

    do {
        /*check buff cache align and sync cache*/
        if ((((uint32)Msg & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0)
        || (((uint32)Output_DataAddr & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0)) {
            RetVal = E_NOT_OK;
            return RetVal;
        }

#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
        arch_clean_cache_range(Msg, Msg_Len);
        arch_clean_cache_range(Key_pub, 64);
        arch_invalidate_cache_range(Output_DataAddr, Msg_Len + 97);
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */

        *job->jobPrimitiveInputOutput.outputLengthPtr = Msg_Len + 97;

        RetVal = Hsm_host_Sm2_Encrypt(Msg, Msg_Len, Key_pub, Output_DataAddr, IsSync);

    } while (0);

    /* release context */
    Context->context_id = CRYPTO_IP_UNUSED_CONTEXT_ID;

    (void)objectId;

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_Decrypt_SM2
(
    uint32 objectId,
    Crypto_ContextType *current_context,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_OK;
    Crypto_Ip_PKContextType *Context;
    Crypto_JobType *job;

    Crypto_KeyType *KeyPtr;
    Crypto_KeyElementType *KeyElementPtr;
    uint8 *Key_pri;
    const uint8 *Cipher_Addr;
    uint32 Cipher_len;
    uint8 *Output_DataAddr;

    Context = (Crypto_Ip_PKContextType *)(current_context->pIpContext);
    if (Context == NULL_PTR) {
        return E_NOT_OK;
    }

    job = &(current_context->aJobInfo.aJob);
    Context->context_id = job->jobId;

    RetVal = Crypto_GetKeyPtr(job->cryptoKeyId, &KeyPtr);
    if (E_OK != RetVal) {
        return RetVal;
    }

    RetVal = Crypto_GetElementPtr(KeyPtr, CRYPTO_KE_SIGNATURE_KEY, &KeyElementPtr);
    if (E_OK != RetVal) {
        return E_NOT_OK;
    }

    Key_pri = KeyElementPtr->pCryptoElementContent;
    Cipher_len = job->jobPrimitiveInputOutput.inputLength;
    Cipher_Addr = job->jobPrimitiveInputOutput.inputPtr;
    Output_DataAddr = job->jobPrimitiveInputOutput.outputPtr;

    if ((((uint32)Output_DataAddr & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0)
        || (((uint32)Cipher_Addr & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0)
        || (((uint32)Key_pri & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0)) {
            RetVal = E_NOT_OK;
            return RetVal;
    }

#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
    arch_clean_cache_range(Key_pri, 32);
    arch_clean_cache_range(Cipher_Addr, Cipher_len);
    arch_invalidate_cache_range(Output_DataAddr, Cipher_len - 97);
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */

    *job->jobPrimitiveInputOutput.outputLengthPtr = Cipher_len - 97;

    RetVal = Hsm_host_Sm2_Decrypt(Output_DataAddr, Key_pri,
                                  (uint8 *)Cipher_Addr, Cipher_len,
                                  CMD_KEY_EXTERNAL_CIPHERTEXT,
                                  CRYPTO_KEY_ELEMENT_ENC_KEY_ID,
                                  Context->mac_data, IsSync);

    /* release context */
    Context->context_id = CRYPTO_IP_UNUSED_CONTEXT_ID;
    (void)objectId;

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_AES_Start
(
    Crypto_ContextType *current_context,
    Crypto_AlgorithmModeType algorithm,
    cipher_op_e operation,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_OK;
    uint32 Iv_Size;
    Crypto_KeyType *KeyPtr;
    Crypto_KeyElementType *KeyElementPtr;
    Crypto_Ip_CipherContextType *Context;
    Crypto_JobType *job;

    job = &(current_context->aJobInfo.aJob);

    Context = (Crypto_Ip_CipherContextType *)(current_context->pIpContext);

    do {

        if (Context == NULL_PTR) {
            break;
        }

        Context->operation  = operation;
        Context->context_id = job->jobId;
        Context->algo_mode  = algorithm;
        Context->key_id     = job->cryptoKeyId;

        if (CRYPTO_ALGOMODE_ECB != algorithm) {
            RetVal = Crypto_GetKeyPtr(job->cryptoKeyId, &KeyPtr);

            if (E_OK == RetVal) {
                RetVal = Crypto_GetElementPtr(KeyPtr, CRYPTO_KE_CIPHER_IV, &KeyElementPtr);
                if (E_OK != RetVal) {
                    break;
                }
            } else {
                break;
            }

            Iv_Size = KeyElementPtr->u32CryptoElementWritedSize;
            if (16 < Iv_Size) {
                RetVal = CRYPTO_E_SHARE_MEM_SMALL;
            } else {
                //mini_memcpy_s(Context->inter_data, KeyElementPtr->pCryptoElementContent, Iv_Size);
#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
                arch_clean_cache_range(KeyElementPtr->pCryptoElementContent, Iv_Size);
                arch_invalidate_cache_range(Context->inter_iv_data, Iv_Size);
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */
                Hsm_host_decrypt_key(KeyElementPtr->pCryptoElementContent, Iv_Size,
                                     CRYPTO_KEY_ELEMENT_ENC_KEY_ID,
                                     Context->inter_iv_data, CRYPTO_PROCESSING_SYNC);
            }
        }
    } while (0);

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_AES_Update
(
    Crypto_ContextType *current_context,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_OK;

    return RetVal;
}

/* Add padding operation */
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_AES_Finish
(
    Crypto_ContextType *current_context,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_OK;

    Crypto_Ip_CipherContextType *Context;

    Crypto_KeyType *KeyPtr;
    Crypto_KeyElementType *KeyElementPtr = NULL_PTR;
    Crypto_KeyElementType *KeyElementPtr2 = NULL_PTR;

    Crypto_JobType *job;

    uint8 KeyLen = 0;
    uint8 *keyAddr;
    uint8 *Input_DataAddr;
    uint32 Input_DataSize;
    uint8 *Output_DataAddr;

    job = &(current_context->aJobInfo.aJob);

    Input_DataSize  = job->jobPrimitiveInputOutput.inputLength;
    Input_DataAddr  = (uint8 *)job->jobPrimitiveInputOutput.inputPtr;
    Output_DataAddr = job->jobPrimitiveInputOutput.outputPtr;

    do {
        Context = (Crypto_Ip_CipherContextType *)(current_context->pIpContext);
        if (Context == NULL_PTR) {
            break;
        }

        /* padding the data */
        if (Input_DataSize % 16 != 0) {
            /* need padding */
        }

        RetVal = Crypto_GetKeyPtr(job->cryptoKeyId, &KeyPtr);
        if (E_OK != RetVal) {
            break;
        }

        RetVal = Crypto_GetElementPtr(KeyPtr, CRYPTO_KE_CIPHER_KEY, &KeyElementPtr);
        if (E_OK != RetVal) {
            break;
        }

        KeyLen  = KeyElementPtr->u32CryptoElementWritedSize;
        keyAddr = KeyElementPtr->pCryptoElementContent;

        if (CRYPTO_ALGOMODE_XTS == Context->algo_mode) {
            RetVal = Crypto_GetElementPtr(KeyPtr, CRYPTO_KE_CIPHER_2NDKEY, &KeyElementPtr2);
            if (E_OK != RetVal) {
                break;
            }
            /* If the second Key is existed, the driver combines the key and second key. Only for xts mode. */
            if (KeyElementPtr->u32CryptoElementWritedSize == KeyElementPtr2->u32CryptoElementWritedSize) {
                mini_memcpy_s(Context->dualkey_data, KeyElementPtr->pCryptoElementContent, KeyLen);
                mini_memcpy_s((Context->dualkey_data+KeyLen), KeyElementPtr2->pCryptoElementContent, KeyLen);
                keyAddr = Context->dualkey_data;
                KeyLen += KeyLen;
            } else {
                RetVal = E_NOT_OK;
                break;
            }
        }

        /*check buff cache align and sync cache*/
        if ((((uint32)Input_DataAddr & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0)
        || (((uint32)Output_DataAddr & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0)
        || (((uint32)keyAddr & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0)) {
            RetVal = E_NOT_OK;
            return RetVal;
        }

        if (CRYPTO_ALGOMODE_ECB != Context->algo_mode) {
#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
            arch_clean_cache_range(Context->inter_iv_data, 16);
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */
        }
#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
        arch_clean_cache_range(keyAddr, KeyLen);
        arch_clean_cache_range(Input_DataAddr, Input_DataSize);
        arch_invalidate_cache_range(Output_DataAddr, Input_DataSize);
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */

        RetVal = Hsm_host_Update_Aes( keyAddr,
                                      KeyPtr->CryptoHSMKeyType,
                                      CRYPTO_KEY_ELEMENT_ENC_KEY_ID,
                                      KeyLen,
                                      Context->algo_mode,
                                      Context->operation,
                                      Context->inter_iv_data,
                                      Input_DataAddr,
                                      Input_DataSize,   //Should be multiple of block
                                      Output_DataAddr, IsSync);
        if (E_OK == RetVal) {
            *(job->jobPrimitiveInputOutput.outputLengthPtr) = Input_DataSize;
        }

        Context->context_id = CRYPTO_IP_UNUSED_CONTEXT_ID;

    } while (0);

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_SM4_Start
(
    Crypto_ContextType *current_context,
    Crypto_AlgorithmModeType algorithm,
    cipher_op_e operation,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_OK;
    uint32 Iv_Size;
    Crypto_KeyType *KeyPtr;
    Crypto_KeyElementType *KeyElementPtr;
    Crypto_Ip_CipherContextType *Context;
    Crypto_JobType *job;

    job = &(current_context->aJobInfo.aJob);

    Context = (Crypto_Ip_CipherContextType *)(current_context->pIpContext);

    do {

        if (Context == NULL_PTR) {
            break;
        }

        Context->operation  = operation;
        Context->context_id = job->jobId;
        Context->algo_mode  = algorithm;
        Context->key_id     = job->cryptoKeyId;

        if (CRYPTO_ALGOMODE_ECB != algorithm) {
            RetVal = Crypto_GetKeyPtr(job->cryptoKeyId, &KeyPtr);

            if (E_OK == RetVal) {
                RetVal = Crypto_GetElementPtr(KeyPtr, CRYPTO_KE_CIPHER_IV, &KeyElementPtr);
                if (E_OK != RetVal) {
                    break;
                }
            } else {
                break;
            }

            Iv_Size = KeyElementPtr->u32CryptoElementWritedSize;
            if (16 < Iv_Size) {
                RetVal = CRYPTO_E_SHARE_MEM_SMALL;
            } else {
                //mini_memcpy_s(Context->inter_data, KeyElementPtr->pCryptoElementContent, Iv_Size);
#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
                arch_clean_cache_range(KeyElementPtr->pCryptoElementContent, Iv_Size);
                arch_invalidate_cache_range(Context->inter_iv_data, Iv_Size);
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */
                Hsm_host_decrypt_key(KeyElementPtr->pCryptoElementContent, Iv_Size,
                                     CRYPTO_KEY_ELEMENT_ENC_KEY_ID,
                                     Context->inter_iv_data, CRYPTO_PROCESSING_SYNC);
            }
        }
    } while (0);

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_SM4_Update
(
    Crypto_ContextType *current_context,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_OK;
    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_SM4_Finish
(
    Crypto_ContextType *current_context,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_OK;

    Crypto_Ip_CipherContextType *Context;
    Crypto_KeyType *KeyPtr;
    Crypto_KeyElementType *KeyElementPtr = NULL_PTR;
    Crypto_JobType *job;

    uint8 KeyLen = 0;
    uint8 *keyAddr;
    uint8 *Input_DataAddr;
    uint32 Input_DataSize;
    uint8 *Output_DataAddr;

    job = &(current_context->aJobInfo.aJob);

    Input_DataSize  = job->jobPrimitiveInputOutput.inputLength;
    Input_DataAddr  = (uint8 *)job->jobPrimitiveInputOutput.inputPtr;
    Output_DataAddr = job->jobPrimitiveInputOutput.outputPtr;

    do {
        Context = (Crypto_Ip_CipherContextType *)(current_context->pIpContext);
        if (Context == NULL_PTR) {
            break;
        }

        /* padding the data */
        if (Input_DataSize % 16 != 0) {
            /* need padding */
        }

        RetVal = Crypto_GetKeyPtr(job->cryptoKeyId, &KeyPtr);
        if (E_OK != RetVal) {
            break;
        }

        RetVal = Crypto_GetElementPtr(KeyPtr, CRYPTO_KE_CIPHER_KEY, &KeyElementPtr);
        if (E_OK != RetVal) {
            break;
        }

        KeyLen  = KeyElementPtr->u32CryptoElementWritedSize;
        keyAddr = KeyElementPtr->pCryptoElementContent;

        /*check buff cache align and sync cache*/
        if ((((uint32)Input_DataAddr & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0)
        || (((uint32)Output_DataAddr & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0)
        || (((uint32)keyAddr & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0)) {
            RetVal = E_NOT_OK;
            return RetVal;
        }

        if (CRYPTO_ALGOMODE_ECB != Context->algo_mode) {
#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
            arch_clean_cache_range(Context->inter_iv_data, 16);
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */
        }
#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
        arch_clean_cache_range(keyAddr, KeyLen);
        arch_clean_cache_range(Input_DataAddr, Input_DataSize);
        arch_invalidate_cache_range(Output_DataAddr, Input_DataSize);
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */

        RetVal = Hsm_host_Update_Sm4( keyAddr,
                                      KeyPtr->CryptoHSMKeyType,
                                      CRYPTO_KEY_ELEMENT_ENC_KEY_ID,
                                      KeyLen,
                                      Context->algo_mode,
                                      Context->operation,
                                      Context->inter_iv_data,
                                      Input_DataAddr,
                                      Input_DataSize,   //Should be multiple of block
                                      Output_DataAddr, IsSync);
        if (E_OK == RetVal) {
            *(job->jobPrimitiveInputOutput.outputLengthPtr) = Input_DataSize;
        }

        Context->context_id = CRYPTO_IP_UNUSED_CONTEXT_ID;

    } while (0);

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_AES_Crypto
(
    cipher_op_e DeOrEn,
    uint8 Operate,
    Crypto_ContextType *current_context,
    Crypto_AlgorithmModeType algorithm,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_OK;

    if ((uint8)CRYPTO_OPERATIONMODE_START == Operate) {
        RetVal = Crypto_Ip_AES_Start(current_context, algorithm, DeOrEn, IsSync);
    } else if ((uint8)CRYPTO_OPERATIONMODE_UPDATE == Operate) {
        RetVal = Crypto_Ip_AES_Update(current_context, IsSync);
    } else if ((uint8)CRYPTO_OPERATIONMODE_FINISH == Operate) {
        RetVal = Crypto_Ip_AES_Finish(current_context, IsSync);
    }

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_SM4_Crypto
(
    cipher_op_e DeOrEn,
    uint8 Operate,
    Crypto_ContextType *current_context,
    Crypto_AlgorithmModeType algorithm,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_OK;

    if ((uint8)CRYPTO_OPERATIONMODE_START == Operate) {
        RetVal = Crypto_Ip_SM4_Start(current_context, algorithm, DeOrEn, IsSync);
    } else if ((uint8)CRYPTO_OPERATIONMODE_UPDATE == Operate) {
        RetVal = Crypto_Ip_SM4_Update(current_context, IsSync);
    } else if ((uint8)CRYPTO_OPERATIONMODE_FINISH == Operate) {
        RetVal = Crypto_Ip_SM4_Finish(current_context, IsSync);
    }

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_Aead_Start
(
    Crypto_ContextType *current_context,
    Crypto_AlgorithmModeType algo_mode,
    Crypto_AlgorithmFamilyType algo,
    cipher_op_e operation,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_OK;
    uint32 Iv_Size;
    Crypto_KeyType *KeyPtr;
    Crypto_KeyElementType *KeyElementPtr;
    Crypto_Ip_CipherContextType *Context;
    Crypto_JobType *job;

    job = &(current_context->aJobInfo.aJob);

    Context = (Crypto_Ip_CipherContextType *)(current_context->pIpContext);

    do {
        if (Context == NULL_PTR) {
            break;
        }

        Context->operation  = operation;
        Context->context_id = job->jobId;
        Context->algo_mode  = algo_mode;
        Context->algo       = algo;
        Context->key_id     = job->cryptoKeyId;

        RetVal = Crypto_GetKeyPtr(job->cryptoKeyId, &KeyPtr);

        if (E_OK == RetVal) {
            RetVal = Crypto_GetElementPtr(KeyPtr, CRYPTO_KE_CIPHER_IV, &KeyElementPtr);
            if (E_OK != RetVal) {
                break;
            }
        } else {
            break;
        }

        Iv_Size = KeyElementPtr->u32CryptoElementWritedSize;
        if (16 < Iv_Size) {
            RetVal = CRYPTO_E_SHARE_MEM_SMALL;
        } else {
#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
            arch_clean_cache_range(KeyElementPtr->pCryptoElementContent, Iv_Size);
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */
            mini_memclr_s(Context->inter_iv_data, 16);
#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
            arch_invalidate_cache_range(Context->inter_iv_data, Iv_Size);
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */
            Hsm_host_decrypt_key(KeyElementPtr->pCryptoElementContent, Iv_Size,
                                 CRYPTO_KEY_ELEMENT_ENC_KEY_ID, Context->inter_iv_data,
                                 CRYPTO_PROCESSING_SYNC);
        }

    } while (0);

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_Aead_Update
(
    Crypto_ContextType *current_context,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_OK;

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_Aead_Finish
(
    Crypto_ContextType *current_context,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_OK;

    Crypto_Ip_CipherContextType *Context;

    Crypto_KeyType *KeyPtr;
    Crypto_KeyElementType *KeyElementPtr = NULL_PTR;

    Crypto_JobType *job;
    uint8 KeyLen = 0;
    uint8 *keyAddr;
    uint8 *Input_DataAddr;
    uint32 Input_DataSize;
    uint32 Add_DataSize;
    uint8 *Tag_DataAddr;
    uint32 Tag_DataSize;
    uint8 *Output_DataAddr;

    job = &(current_context->aJobInfo.aJob);

    Input_DataAddr  = (uint8 *)job->jobPrimitiveInputOutput.inputPtr;
    Input_DataSize  = job->jobPrimitiveInputOutput.inputLength;
    Add_DataSize    = job->jobPrimitiveInputOutput.secondaryInputLength;
    Tag_DataAddr    = (uint8 *)job->jobPrimitiveInputOutput.tertiaryInputPtr;
    Tag_DataSize    = job->jobPrimitiveInputOutput.tertiaryInputLength;
    Output_DataAddr = job->jobPrimitiveInputOutput.outputPtr;

    do {
        Context = (Crypto_Ip_CipherContextType *)(current_context->pIpContext);
        if (Context == NULL_PTR) {
            break;
        }

        RetVal = Crypto_GetKeyPtr(job->cryptoKeyId, &KeyPtr);
        if (E_OK != RetVal) {
            break;
        }

        RetVal = Crypto_GetElementPtr(KeyPtr, CRYPTO_KE_CIPHER_KEY, &KeyElementPtr);
        if (E_OK != RetVal) {
            break;
        }

        KeyLen  = KeyElementPtr->u32CryptoElementWritedSize;
        keyAddr = KeyElementPtr->pCryptoElementContent;

        /*check buff cache align and sync cache*/
        if ((((uint32)Input_DataAddr & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0)
        || (((uint32)Output_DataAddr & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0)
        || (((uint32)keyAddr & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0)) {
            RetVal = E_NOT_OK;
            return RetVal;
        }
#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
        arch_clean_cache_range(Context->inter_iv_data, 12);
        arch_clean_cache_range(keyAddr, KeyLen);
        arch_clean_cache_range(Input_DataAddr, Input_DataSize);
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */
        uint32 wordlen = ((Input_DataSize + 15) & (uint32)(~0x0Fu)) / 4;
#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
        arch_invalidate_cache_range(Output_DataAddr, wordlen * 4 + 16);
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */

        if (Context->operation == CIPHER_ENC) {
        RetVal = Hsm_host_Aead_Encrypt(Context->algo, KeyLen, Input_DataAddr,
                                       Input_DataSize, CMD_KEY_EXTERNAL_CIPHERTEXT,
                                       keyAddr, CRYPTO_KEY_ELEMENT_ENC_KEY_ID,
                                       Context->inter_iv_data, 12,
                                       Add_DataSize, Output_DataAddr, Tag_DataSize,
                                       (gcm_enc_input_ptr_t *)Context->gcm_input,
                                       IsSync);
        } else {
        if (((uint32)Tag_DataAddr & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0) {
            RetVal = E_NOT_OK;
            return RetVal;
        }
        /*set tag*/
        mini_memset_s(Tag_DataAddr + Tag_DataSize, 0, 16 - Tag_DataSize);
#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
        arch_clean_cache_range(Tag_DataAddr, 16);
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */
        RetVal = Hsm_host_Aead_Decrypt(Context->algo, KeyLen, Input_DataAddr,
                                       Input_DataSize, CMD_KEY_EXTERNAL_CIPHERTEXT,
                                       keyAddr, CRYPTO_KEY_ELEMENT_ENC_KEY_ID,
                                       Context->inter_iv_data, 12,
                                       Add_DataSize, Output_DataAddr, Tag_DataAddr,
                                       Tag_DataSize,
                                       (gcm_dec_input_ptr_t *)Context->gcm_input,
                                       IsSync);
        }

        if (E_OK == RetVal) {
            *(job->jobPrimitiveInputOutput.outputLengthPtr) = wordlen * 4 + 16;
        }

        Context->context_id = CRYPTO_IP_UNUSED_CONTEXT_ID;
    } while (0);

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_Aead_Crypto
(
    cipher_op_e DeOrEn,
    uint8 Operate,
    Crypto_ContextType *current_context,
    Crypto_AlgorithmModeType algo_mode,
    Crypto_AlgorithmFamilyType algo,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_OK;

    if ((uint8)CRYPTO_OPERATIONMODE_START == Operate) {
        RetVal = Crypto_Ip_Aead_Start(current_context, algo_mode, algo, DeOrEn, IsSync);
    } else if ((uint8)CRYPTO_OPERATIONMODE_UPDATE == Operate) {
        RetVal = Crypto_Ip_Aead_Update(current_context, IsSync);
    } else if ((uint8)CRYPTO_OPERATIONMODE_FINISH == Operate) {
        RetVal = Crypto_Ip_Aead_Finish(current_context, IsSync);
    }

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_Rsa_Sign
(
    uint32 objectId,
    Crypto_ContextType *current_context,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_OK;
    uint32 HASH_DataSize;
    uint8 *Output_DataAddr;
    Crypto_KeyType *KeyPtr;
    RSAKey_Ext_Sdrv *Key_pri;
    Crypto_Ip_PKContextType *Context;
    uint32 Modulus_Size;
    Crypto_JobType *job;
    uint32 slen;
    Crypto_AlgorithmModeType alg_mode;

    job = &(current_context->aJobInfo.aJob);
    alg_mode = job->jobPrimitiveInfo->primitiveInfo->algorithm.mode;

    Output_DataAddr = job->jobPrimitiveInputOutput.outputPtr;
    if (((uint32)Output_DataAddr & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0) {
        RetVal = E_NOT_OK;
        return RetVal;
    }

    /*
     * get key value, only support CRYPTO_KE_FORMAT_BIN_ RSA_PRIVATEKEY,
     * private keys is defined according to RFC3447
     */
    RetVal = Crypto_GetKeyPtr(job->cryptoKeyId, &KeyPtr);
    if (E_OK != RetVal) {
        return RetVal;
    }

    Context = (Crypto_Ip_PKContextType *)(current_context->pIpContext);
    if (Context == NULL_PTR) {
        return E_NOT_OK;
    }
    Context->context_id = job->jobId;

    RetVal = Crypto_GetElementBuffInBlock(job->cryptoKeyId, CRYPTO_KE_SIGNATURE_KEY,
                                          KeyPtr->CryptoKeyType, (uint8 **)&(Context->key_data),
                                          0, CRYPTO_KEY_BLOCK_BUFF_FOR_JOB, FALSE);
    if(RetVal != E_OK){
        return RetVal;
    }

    Key_pri = (RSAKey_Ext_Sdrv *)(Context->key_data);
    Modulus_Size = Key_pri->keybuff_head.n_sz;
    /*update n e d for img update(memmap changed, keyaddr store in flash is old)*/
    Key_pri->keybuff_head.n = (uint8 *)Key_pri + ROUNDUP(sizeof(RSAKey_Head_Ext_Sdrv), CACHE_LINE);
    Key_pri->keybuff_head.e = Key_pri->keybuff_head.n + Modulus_Size;
    Key_pri->keybuff_head.d = Key_pri->keybuff_head.e + Modulus_Size;

    /* handle hash or not */
    if (CRYPTO_ALGOMODE_RSASSA_PKCS1_v1_5 == alg_mode ||
        CRYPTO_ALGOMODE_RSASSA_PSS == alg_mode) {
        RetVal = Hsm_host_Hash(job->jobPrimitiveInfo->primitiveInfo->algorithm.secondaryFamily,
                               job->jobPrimitiveInputOutput.inputPtr,
                               job->jobPrimitiveInputOutput.inputLength,
                               Context->hash_data, &HASH_DataSize, CRYPTO_PROCESSING_SYNC);
        if(RetVal != E_OK){
            return RetVal;
        }
    } else {
        /* do nothing */
    }

    /* get msg */
    if (CRYPTO_ALGOMODE_RSASSA_PKCS1_v1_5 == alg_mode) {
        RetVal = rsa_pad_emsa_pkcs_encode(Modulus_Size, job->jobPrimitiveInfo->primitiveInfo->algorithm.secondaryFamily,
                                          Context->msg_data, Context->hash_data);
    } else if (CRYPTO_ALGOMODE_RSASSA_PSS == alg_mode) {
        slen = Modulus_Size - HASH_DataSize - 2;
        RetVal = rsa_pad_emsa_pss_encode(Modulus_Size,
                                         job->jobPrimitiveInfo->primitiveInfo->
                                         algorithm.secondaryFamily,
                                         Context->msg_data, Context->hash_data,
                                         *(Key_pri->keybuff_head.n), slen);
    } else {
        if (job->jobPrimitiveInputOutput.inputLength > Modulus_Size)
                return E_NOT_OK;

        slen = Modulus_Size - job->jobPrimitiveInputOutput.inputLength;
        mini_memcpy_s(Context->msg_data, job->jobPrimitiveInputOutput.inputPtr,
                      job->jobPrimitiveInputOutput.inputLength);
        mini_memclr_s(&Context->msg_data[job->jobPrimitiveInputOutput.inputLength], slen);
    }
#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
    arch_clean_cache_range(Key_pri->keybuff_head.n, Modulus_Size);
    arch_clean_cache_range(Key_pri->keybuff_head.e, Modulus_Size);
    arch_clean_cache_range(Key_pri->keybuff_head.d, Modulus_Size);
    arch_clean_cache_range(Context->msg_data, Modulus_Size);
    arch_invalidate_cache_range(Output_DataAddr, Modulus_Size);
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */
    RetVal = Hsm_host_Sign_Rsa(Context->msg_data, Key_pri->keybuff_head.n,
                               Key_pri->keybuff_head.e, Key_pri->keybuff_head.d,
                               Modulus_Size, Output_DataAddr,Key_pri->keybuff_head.keytype,
                               Key_pri->keybuff_head.keyid1,Context->mac_data, IsSync);

    Context->context_id = CRYPTO_IP_UNUSED_CONTEXT_ID;

    (void)objectId;

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_Rsa_Verify
(
    uint32 objectId,
    Crypto_ContextType *current_context,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_OK;
    const uint8 *sign_DataAddr;
    uint8 *EM_DataAddr;
    uint32 HASH_DataSize;

    Crypto_KeyType *KeyPtr;
    RSAKey_Ext_Sdrv *Key_pub;
    Crypto_Ip_PKContextType *Context;
    uint32 Modulus_Size;
    Crypto_JobType *job;
    uint32 slen;
    Crypto_AlgorithmModeType alg_mode;

    job = &(current_context->aJobInfo.aJob);
    alg_mode = job->jobPrimitiveInfo->primitiveInfo->algorithm.mode;

    /*
     * get key value, only support CRYPTO_KE_FORMAT_BIN_ RSA_PRIVATEKEY,
     * private keys is defined according to RFC3447.
     */
    RetVal = Crypto_GetKeyPtr(job->cryptoKeyId, &KeyPtr);
    if (E_OK != RetVal) {
        return RetVal;
    }

    Context = (Crypto_Ip_PKContextType *)(current_context->pIpContext);
    if (Context == NULL_PTR) {
        return E_NOT_OK;
    }
    Context->context_id = job->jobId;

    sign_DataAddr = job->jobPrimitiveInputOutput.secondaryInputPtr;
    if (((uint32)sign_DataAddr & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0) {
        RetVal = E_NOT_OK;
        return RetVal;
    }

    /*parse keyelement into context*/
    //Crypto_InstallKey(job->cryptoKeyId, Context->key_data);
    /*get key from hsmkeybuff*/
    RetVal = Crypto_GetElementBuffInBlock(job->cryptoKeyId, CRYPTO_KE_SIGNATURE_KEY,
                                          KeyPtr->CryptoKeyType, (uint8 **)&(Context->key_data),
                                          0, CRYPTO_KEY_BLOCK_BUFF_FOR_JOB, FALSE);
    if (RetVal != E_OK) {
        return E_NOT_OK;
    }

    Key_pub = (RSAKey_Ext_Sdrv *)(Context->key_data);
    Modulus_Size = Key_pub->keybuff_head.n_sz;
    /*update n e for img update(memmap changed, keyaddr store in flash is old)*/
    Key_pub->keybuff_head.n = (uint8 *)Key_pub + ROUNDUP(sizeof(RSAKey_Head_Ext_Sdrv), CACHE_LINE);
    Key_pub->keybuff_head.e = Key_pub->keybuff_head.n + Modulus_Size;

    /* handle hash or not */
    if (CRYPTO_ALGOMODE_RSASSA_PKCS1_v1_5 == alg_mode ||
        CRYPTO_ALGOMODE_RSASSA_PSS == alg_mode) {
        RetVal = Hsm_host_Hash(job->jobPrimitiveInfo->primitiveInfo->algorithm.secondaryFamily,
                               job->jobPrimitiveInputOutput.inputPtr,
                               job->jobPrimitiveInputOutput.inputLength,
                               Context->hash_data, &HASH_DataSize, CRYPTO_PROCESSING_SYNC);
        if(RetVal != E_OK){
            return RetVal;
        }
    } else {
        /* do nothing */
    }

    EM_DataAddr = Context->msg_data;
    if (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_RSASSA_PSS) {
#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
        arch_clean_cache_range(sign_DataAddr, Modulus_Size);
        arch_clean_cache_range(Key_pub->keybuff_head.n, Modulus_Size);
        arch_clean_cache_range(Key_pub->keybuff_head.e, Modulus_Size);
        arch_invalidate_cache_range(EM_DataAddr, Modulus_Size);
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */
        RetVal = Hsm_host_RsaEncrypt(Key_pub->keybuff_head.n, Key_pub->keybuff_head.e,
                                     Modulus_Size, sign_DataAddr, EM_DataAddr,
                                     CRYPTO_PROCESSING_SYNC);

        if (RetVal == E_OK) {
            slen = Modulus_Size - HASH_DataSize - 2;
            RetVal = rsa_pad_emsa_pss_decode(Modulus_Size,
                                             job->jobPrimitiveInfo->
                                             primitiveInfo->algorithm.
                                             secondaryFamily, EM_DataAddr,
                                             Context->hash_data, slen,
                                             *(Key_pub->keybuff_head.n));
        }
    } else {
        if (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_RSASSA_PKCS1_v1_5) {
            RetVal = rsa_pad_emsa_pkcs_encode(Modulus_Size, job->jobPrimitiveInfo->primitiveInfo->algorithm.secondaryFamily,
                                              Context->msg_data, Context->hash_data);
        } else {
            if (job->jobPrimitiveInputOutput.inputLength > Modulus_Size)
                return E_NOT_OK;

            slen = Modulus_Size - job->jobPrimitiveInputOutput.inputLength;
            mini_memcpy_s(EM_DataAddr, job->jobPrimitiveInputOutput.inputPtr,
                          job->jobPrimitiveInputOutput.inputLength);
            mini_memclr_s(&EM_DataAddr[job->jobPrimitiveInputOutput.inputLength], slen);
        }
#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
        arch_clean_cache_range(sign_DataAddr, Modulus_Size);
        arch_clean_cache_range(Key_pub->keybuff_head.n, Modulus_Size);
        arch_clean_cache_range(Key_pub->keybuff_head.e, Modulus_Size);
        arch_clean_cache_range(EM_DataAddr, Modulus_Size);
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */
        RetVal = Hsm_host_Verify_Rsa(EM_DataAddr, Key_pub->keybuff_head.n,
                                     Key_pub->keybuff_head.e, Modulus_Size,
                                     sign_DataAddr, job, IsSync);
    }

    if (CRYPTO_PROCESSING_SYNC == IsSync) {
        /* sync verify result */
        if (E_OK == RetVal) {
            *(job->jobPrimitiveInputOutput.verifyPtr) = CRYPTO_E_VER_OK;
        } else {
            *(job->jobPrimitiveInputOutput.verifyPtr) = CRYPTO_E_VER_NOT_OK;
        }
    }

    Context->context_id = CRYPTO_IP_UNUSED_CONTEXT_ID;

    (void)objectId;

    return RetVal;
}

static uint8 ecc_curve_mapping(uint32 pubkey_len)
{
    uint8 ecc_curve_id = 0xff;

    switch (pubkey_len) {
    case 48:
        ecc_curve_id = SECP192R1;
        break;
    case 56:
        ecc_curve_id = SECP224R1;
        break;
    case 64:
        ecc_curve_id = SECP256R1;
        break;
    case 96:
        ecc_curve_id = SECP384R1;
        break;
    case 132:
        ecc_curve_id = SECP521R1;
        break;
    default:
        break;
    }

    return (ecc_curve_id);
}

static FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_Ecdsa_Sign
(
    uint32 objectId,
    Crypto_ContextType *current_context,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_OK;

    Crypto_Ip_PKContextType *Context;
    Crypto_KeyType *KeyPtr;
    Crypto_KeyElementType *KeyElementPtr = NULL_PTR;
    Crypto_JobType *job;

    uint8 *E_DataAddr;
    uint32 E_Len;
    uint8 *Key_DataAddr;
    uint32 Key_Len;
    uint8 *Signature_DataAddr;
    uint8 curve_id;

    Context = (Crypto_Ip_PKContextType *)(current_context->pIpContext);
    if (Context == NULL_PTR) {
        return E_NOT_OK;
    }

    job = &(current_context->aJobInfo.aJob);
    Context->context_id = job->jobId;
    E_Len = job->jobPrimitiveInputOutput.inputLength;
    E_DataAddr = (uint8 *)job->jobPrimitiveInputOutput.inputPtr;
    Signature_DataAddr = job->jobPrimitiveInputOutput.outputPtr;

    RetVal = Crypto_GetKeyPtr(job->cryptoKeyId, &KeyPtr);
    if (E_OK != RetVal) {
        return E_NOT_OK;
    }

    RetVal = Crypto_GetElementPtr(KeyPtr, CRYPTO_KE_SIGNATURE_KEY, &KeyElementPtr);
    if (E_OK != RetVal) {
        return E_NOT_OK;
    }

    Key_Len = KeyElementPtr->u32CryptoElementWritedSize;
    Key_DataAddr = KeyElementPtr->pCryptoElementContent;

    /*check buff cache align and sync cache*/
    if ((((uint32)E_DataAddr & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0)
    || (((uint32)Signature_DataAddr & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0)
    || (((uint32)Key_DataAddr & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0)) {
        RetVal = E_NOT_OK;
        return RetVal;
    }
#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
    uint32 Signature_Len = *(job->jobPrimitiveInputOutput.outputLengthPtr);
    arch_clean_cache_range(Key_DataAddr, Key_Len);
    arch_clean_cache_range(E_DataAddr, E_Len);
    arch_invalidate_cache_range(Signature_DataAddr, Signature_Len);
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */
    curve_id = ecc_curve_mapping(Key_Len * 2);
    RetVal = Hsm_host_Sign_Ecdsa(curve_id, E_DataAddr,E_Len,KeyPtr->CryptoHSMKeyType,
                                 CRYPTO_KEY_ELEMENT_ENC_KEY_ID,Key_DataAddr,
                                 Signature_DataAddr, Context->mac_data, IsSync);

    Context->context_id = CRYPTO_IP_UNUSED_CONTEXT_ID;
    (void)objectId;

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_Ecdsa_Verify
(
    uint32 objectId,
    Crypto_ContextType *current_context,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_OK;

    Crypto_Ip_PKContextType *Context;
    Crypto_KeyType *KeyPtr;
    Crypto_KeyElementType *KeyElementPtr = NULL_PTR;
    Crypto_JobType *job;

    uint8 *E_DataAddr;
    uint32 E_Len;
    uint8 *Key_DataAddr;
    uint32 Key_Len;
    uint8 *Signature_DataAddr;
    uint8 curve_id;

    job = &(current_context->aJobInfo.aJob);

    Context = (Crypto_Ip_PKContextType *)(current_context->pIpContext);
    if (Context == NULL_PTR) {
        return E_NOT_OK;
    }

    RetVal = Crypto_GetKeyPtr(job->cryptoKeyId, &KeyPtr);
    if (E_OK != RetVal) {
        return E_NOT_OK;
    }

    RetVal = Crypto_GetElementPtr(KeyPtr, CRYPTO_KE_SIGNATURE_KEY, &KeyElementPtr);
    if (E_OK != RetVal) {
        return E_NOT_OK;
    }

    Context->context_id = job->jobId;
    E_DataAddr = (uint8 *)job->jobPrimitiveInputOutput.inputPtr;
    E_Len = job->jobPrimitiveInputOutput.inputLength;
    Key_DataAddr = KeyElementPtr->pCryptoElementContent;
    Key_Len = KeyElementPtr->u32CryptoElementWritedSize;

    Signature_DataAddr = (uint8 *)job->jobPrimitiveInputOutput.secondaryInputPtr;
    if (((uint32)Signature_DataAddr & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0) {
        RetVal = E_NOT_OK;
        return RetVal;
    }
#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
    uint32 Signature_Len = job->jobPrimitiveInputOutput.secondaryInputLength;
    arch_clean_cache_range(Signature_DataAddr, Signature_Len);
    arch_clean_cache_range(Key_DataAddr, Key_Len);
    arch_clean_cache_range(E_DataAddr, E_Len);
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */
    curve_id = ecc_curve_mapping(Key_Len);
    RetVal = Hsm_host_Verify_Ecdsa(curve_id, E_DataAddr, E_Len, Key_DataAddr,
                                   Signature_DataAddr, job, IsSync);

    if (CRYPTO_PROCESSING_SYNC == IsSync) {
        /* sync verify result */
        if (E_OK == RetVal) {
            *(job->jobPrimitiveInputOutput.verifyPtr) = CRYPTO_E_VER_OK;
        }else{
            *(job->jobPrimitiveInputOutput.verifyPtr) = CRYPTO_E_VER_NOT_OK;
        }
    }

    Context->context_id = CRYPTO_IP_UNUSED_CONTEXT_ID;
    (void)objectId;

    return RetVal;
}

static FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_Sm2_Sign
(
    uint32 objectId,
    Crypto_ContextType *current_context,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_OK;

    Crypto_Ip_PKContextType *Context;
    Crypto_KeyType *KeyPtr;
    Crypto_KeyElementType *KeyElementPtr = NULL_PTR;
    Crypto_JobType *job;

    uint8 *E_DataAddr;
    uint8 *Key_DataAddr;
    uint8 *Signature_DataAddr;

    Context = (Crypto_Ip_PKContextType *)(current_context->pIpContext);
    if (Context == NULL_PTR) {
        return E_NOT_OK;
    }

    job = &(current_context->aJobInfo.aJob);
    Context->context_id = job->jobId;
    E_DataAddr = (uint8 *)job->jobPrimitiveInputOutput.inputPtr;
    Signature_DataAddr = job->jobPrimitiveInputOutput.outputPtr;

    RetVal = Crypto_GetKeyPtr(job->cryptoKeyId, &KeyPtr);
    if (E_OK != RetVal) {
        return E_NOT_OK;
    }

    RetVal = Crypto_GetElementPtr(KeyPtr, CRYPTO_KE_SIGNATURE_KEY, &KeyElementPtr);
    if (E_OK != RetVal) {
        return E_NOT_OK;
    }

    Key_DataAddr = KeyElementPtr->pCryptoElementContent;

    /*check buff cache align and sync cache*/
    if ((((uint32)E_DataAddr & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0)
    || (((uint32)Signature_DataAddr & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0)
    || (((uint32)Key_DataAddr & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0)) {
        RetVal = E_NOT_OK;
        return RetVal;
    }
#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
    uint32 E_Len = job->jobPrimitiveInputOutput.inputLength;
    uint32 Signature_Len = *(job->jobPrimitiveInputOutput.outputLengthPtr);
    uint32 Key_Len = KeyElementPtr->u32CryptoElementWritedSize;
    arch_clean_cache_range(Key_DataAddr, Key_Len);
    arch_clean_cache_range(E_DataAddr, E_Len);
    arch_invalidate_cache_range(Signature_DataAddr, Signature_Len);
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */
    RetVal = Hsm_host_Sign_Sm2(E_DataAddr, Key_DataAddr, KeyPtr->CryptoHSMKeyType,
                               CRYPTO_KEY_ELEMENT_ENC_KEY_ID,
                               Signature_DataAddr,Context->mac_data, IsSync);

    Context->context_id = CRYPTO_IP_UNUSED_CONTEXT_ID;
    (void)objectId;

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_Sm2_Verify
(
    uint32 objectId,
    Crypto_ContextType *current_context,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_OK;

    Crypto_Ip_PKContextType *Context;
    Crypto_KeyType *KeyPtr;
    Crypto_KeyElementType *KeyElementPtr = NULL_PTR;
    Crypto_JobType *job;

    uint8 *E_DataAddr;
    uint8 *Key_DataAddr;
    uint8 *Signature_DataAddr;

    job = &(current_context->aJobInfo.aJob);

    Context = (Crypto_Ip_PKContextType *)(current_context->pIpContext);
    if (Context == NULL_PTR) {
        return E_NOT_OK;
    }

    RetVal = Crypto_GetKeyPtr(job->cryptoKeyId, &KeyPtr);
    if (E_OK != RetVal) {
        return E_NOT_OK;
    }

    RetVal = Crypto_GetElementPtr(KeyPtr, CRYPTO_KE_SIGNATURE_KEY, &KeyElementPtr);
    if (E_OK != RetVal) {
        return E_NOT_OK;
    }

    Context->context_id = job->jobId;
    E_DataAddr = (uint8 *)job->jobPrimitiveInputOutput.inputPtr;
    Key_DataAddr = KeyElementPtr->pCryptoElementContent;
    Signature_DataAddr = (uint8 *)job->jobPrimitiveInputOutput.secondaryInputPtr;

    if (((uint32)Signature_DataAddr & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0) {
        RetVal = E_NOT_OK;
        return RetVal;
    }

#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
    uint32 E_Len = job->jobPrimitiveInputOutput.inputLength;
    uint32 Key_Len = KeyElementPtr->u32CryptoElementWritedSize;
    uint32 Signature_Len = job->jobPrimitiveInputOutput.secondaryInputLength;

    arch_clean_cache_range(Signature_DataAddr, Signature_Len);
    arch_clean_cache_range(Key_DataAddr, Key_Len);
    arch_clean_cache_range(E_DataAddr, E_Len);
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */

    RetVal = Hsm_host_Verify_Sm2(E_DataAddr, Key_DataAddr,
                                 Signature_DataAddr, job, IsSync);
    if (CRYPTO_PROCESSING_SYNC == IsSync) {
        /* sync verify result*/
        if (E_OK == RetVal) {
            *(job->jobPrimitiveInputOutput.verifyPtr) = CRYPTO_E_VER_OK;
        }else{
            *(job->jobPrimitiveInputOutput.verifyPtr) = CRYPTO_E_VER_NOT_OK;
        }
    }

    Context->context_id = CRYPTO_IP_UNUSED_CONTEXT_ID;
    (void)objectId;

    return RetVal;
}

/*--------------------------------------------------------------------------------------------------------------------------*/
static FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_Hash
(
    uint32 objectId,
    uint8 Operate,
    Crypto_ContextType *current_context,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_OK;
    Crypto_JobType *job;
    Crypto_AlgorithmFamilyType alogrithm;

    if ((uint8)CRYPTO_OPERATIONMODE_FINISH != Operate) {
        return E_OK;
    }

    job = &(current_context->aJobInfo.aJob);

    alogrithm = current_context->Alogrithm;

    /*Check the hash algorithm of support*/
    if (((alogrithm <= CRYPTO_ALGOFAM_SHA2_512_256) &&
         (alogrithm >= CRYPTO_ALGOFAM_SHA2_224))
        || (alogrithm == CRYPTO_ALGOFAM_CUSTOM)) {
    } else {
        RetVal = CRYPTO_E_ALGO_UNSUPPORT;
    }

    if (E_OK == RetVal) {
            RetVal = Hsm_host_Hash(alogrithm, job->jobPrimitiveInputOutput.inputPtr,
                                   job->jobPrimitiveInputOutput.inputLength, job->jobPrimitiveInputOutput.outputPtr,
                                   job->jobPrimitiveInputOutput.outputLengthPtr, IsSync);
    }

    return RetVal;
}

static FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_MacGenerate
(
    uint32 objectId,
    uint8 Operate,
    Crypto_ContextType *current_context,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_NOT_OK;

    Crypto_AlgorithmModeType mac_mode;

    if ((uint8)CRYPTO_OPERATIONMODE_FINISH != Operate) {
        return E_OK;
    }

    mac_mode = current_context->aJobInfo.aJob.jobPrimitiveInfo->primitiveInfo->algorithm.mode;

    switch (mac_mode) {
        case CRYPTO_ALGOMODE_HMAC: {
            RetVal = Crypto_Ip_DoHmacGenerate(objectId, current_context, 0u, IsSync);
            break;
        }

        case CRYPTO_ALGOMODE_CMAC: {
            RetVal = Crypto_Ip_DoCmacGenerate(objectId, current_context, 1u, IsSync);
            break;
        }

        case CRYPTO_ALGOMODE_GMAC: {
            /** not support gmac*/
            break;
        }

        default : {
            /*The algorithm that not be supported*/
            break;
        }
    }

    return RetVal;
}

static FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_MacVerify
(
    uint32 objectId,
    uint8 Operate,
    Crypto_ContextType *current_context,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_NOT_OK;

    Crypto_AlgorithmModeType algo_mode;
    Crypto_JobType *job;

    job = &(current_context->aJobInfo.aJob);

    algo_mode = job->jobPrimitiveInfo->primitiveInfo->algorithm.mode;

    if ((uint8)CRYPTO_OPERATIONMODE_FINISH != Operate) {
        return E_OK;
    }

    switch (algo_mode) {
        case CRYPTO_ALGOMODE_HMAC: {
            RetVal = Crypto_Ip_DoHmacVerify(objectId, current_context, 0u, IsSync);
            break;
        }

        case CRYPTO_ALGOMODE_CMAC: {
            RetVal = Crypto_Ip_DoCmacVerify(objectId, current_context, 1u, IsSync);
            break;
        }

        default : {
            /*The algorithm that not be supported*/
            break;
        }
    }

    if (CRYPTO_PROCESSING_SYNC == IsSync) {
        if(RetVal == E_OK){
            *(job->jobPrimitiveInputOutput.verifyPtr) = CRYPTO_E_VER_OK;
        }else{
            *(job->jobPrimitiveInputOutput.verifyPtr) = CRYPTO_E_VER_NOT_OK;
        }
    }

    return RetVal;
}

static FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_Encrypto
(
    uint32 objectId,
    uint8 Operate,
    Crypto_ContextType *current_context,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_OK;
    Crypto_AlgorithmFamilyType algo;
    Crypto_AlgorithmModeType algo_mode;
    Crypto_JobType *job;

    job = &(current_context->aJobInfo.aJob);

    algo = job->jobPrimitiveInfo->primitiveInfo->algorithm.family;
    algo_mode = job->jobPrimitiveInfo->primitiveInfo->algorithm.mode;

    if (CRYPTO_ALGOFAM_AES == algo) {
        switch (algo_mode) {
        case CRYPTO_ALGOMODE_ECB:
        case CRYPTO_ALGOMODE_CBC:
        case CRYPTO_ALGOMODE_CFB:
        case CRYPTO_ALGOMODE_OFB:
        case CRYPTO_ALGOMODE_CTR:
        case CRYPTO_ALGOMODE_XTS: {/*key1||key2 Iv(tweak)*/
            RetVal = Crypto_Ip_AES_Crypto(CIPHER_ENC, Operate, current_context, algo_mode, IsSync);
            break;
        default:
            break;
        }
        }
    } else if (CRYPTO_ALGOFAM_CUSTOM == algo && CRYPTO_ALGOMODE_NOT_SET == algo_mode) {
        if ((uint8)CRYPTO_OPERATIONMODE_FINISH != Operate) {
            return E_OK;
        }
        RetVal = Crypto_Ip_Encrypt_SM2(objectId, current_context, IsSync);
    } else {
        switch (algo_mode) {
        case CRYPTO_ALGOMODE_ECB:
        case CRYPTO_ALGOMODE_CBC:
        case CRYPTO_ALGOMODE_CFB:
        case CRYPTO_ALGOMODE_CTR:
        case CRYPTO_ALGOMODE_OFB: {
            RetVal = Crypto_Ip_SM4_Crypto(CIPHER_ENC, Operate, current_context,
                                          algo_mode, IsSync);
            break;
        }
        case CRYPTO_ALGOMODE_RSAES_OAEP: {      /*RSA PKCS v2.1*/
            if ((uint8)CRYPTO_OPERATIONMODE_FINISH != Operate) {
                return E_OK;
            }
            RetVal = Crypto_Ip_Encrypt_RSAES_OAEP(objectId, current_context, IsSync);
            break;
        }
        case CRYPTO_ALGOMODE_RSAES_PKCS1_v1_5: {    /*RSA PKCS v1.5*/
            if ((uint8)CRYPTO_OPERATIONMODE_FINISH != Operate) {
                return E_OK;
            }
            RetVal = Crypto_Ip_Encrypt_RSAES_PKCS1_v1_5(objectId, current_context, IsSync);
            break;
        }
        case CRYPTO_ALGOMODE_NOT_SET: {
            if ((uint8)CRYPTO_OPERATIONMODE_FINISH != Operate) {
                return E_OK;
            }
            RetVal = Crypto_Ip_Encrypt_RSA(objectId, current_context, IsSync);
            break;
        }
        default: {
            break;
        }
        }
    }

    return RetVal;
}

static FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_Decrypto
(
    uint32 objectId,
    uint8 Operate,
    Crypto_ContextType *current_context,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_OK;
    Crypto_AlgorithmFamilyType algo;
    Crypto_AlgorithmModeType algo_mode;
    Crypto_JobType *job;

    job = &(current_context->aJobInfo.aJob);

    algo = job->jobPrimitiveInfo->primitiveInfo->algorithm.family;
    algo_mode = job->jobPrimitiveInfo->primitiveInfo->algorithm.mode;

    if (CRYPTO_ALGOFAM_AES == algo) {
        switch (algo_mode) {
        case CRYPTO_ALGOMODE_ECB:
        case CRYPTO_ALGOMODE_CBC:
        case CRYPTO_ALGOMODE_CFB:
        case CRYPTO_ALGOMODE_OFB:
        case CRYPTO_ALGOMODE_CTR:
        case CRYPTO_ALGOMODE_XTS: {/*key1 key2 Iv(tweak)*/
            RetVal = Crypto_Ip_AES_Crypto(CIPHER_DEC, Operate, current_context,
                                          algo_mode, IsSync);
            break;
        default:
            break;
        }
        }
    } else if (CRYPTO_ALGOFAM_CUSTOM == algo && CRYPTO_ALGOMODE_NOT_SET == algo_mode){
        if ((uint8)CRYPTO_OPERATIONMODE_FINISH != Operate) {
            return E_OK;
        }
        RetVal = Crypto_Ip_Decrypt_SM2(objectId, current_context, IsSync);
    } else {
        switch (algo_mode) {
        case CRYPTO_ALGOMODE_ECB:
        case CRYPTO_ALGOMODE_CBC:
        case CRYPTO_ALGOMODE_CFB:
        case CRYPTO_ALGOMODE_CTR:
        case CRYPTO_ALGOMODE_OFB: {
            RetVal = Crypto_Ip_SM4_Crypto(CIPHER_DEC, Operate, current_context,
                                          algo_mode, IsSync);
            break;
        }
        case CRYPTO_ALGOMODE_RSAES_OAEP: {      /*RSA PKCS v2.1*/
            if ((uint8)CRYPTO_OPERATIONMODE_FINISH != Operate) {
                return E_OK;
            }
            RetVal = Crypto_Ip_Decrypt_RSAES_OAEP(objectId, current_context, IsSync);
            break;
        }
        case CRYPTO_ALGOMODE_RSAES_PKCS1_v1_5: {    /*RSA PKCS v1.5*/
            if ((uint8)CRYPTO_OPERATIONMODE_FINISH != Operate) {
                return E_OK;
            }
            RetVal = Crypto_Ip_Decrypt_RSAES_PKCS1_v1_5(objectId, current_context, IsSync);
            break;
        }
        case CRYPTO_ALGOMODE_NOT_SET: {
            if ((uint8)CRYPTO_OPERATIONMODE_FINISH != Operate) {
                return E_OK;
            }
            RetVal = Crypto_Ip_Decrypt_RSA(objectId, current_context, IsSync);
            break;
        }
        default: {
            break;
        }
        }
    }

    return RetVal;
}

static FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_AeadEncrypto
(
    uint32 objectId,
    uint8 Operate,
    Crypto_ContextType *current_context,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    Crypto_AlgorithmFamilyType algo;
    Crypto_AlgorithmModeType algo_mode;
    Crypto_JobType *job;

    job = &(current_context->aJobInfo.aJob);

    algo = job->jobPrimitiveInfo->primitiveInfo->algorithm.family;
    algo_mode = job->jobPrimitiveInfo->primitiveInfo->algorithm.mode;

    RetVal = Crypto_Ip_Aead_Crypto(CIPHER_ENC, Operate, current_context,
                                   algo_mode, algo, IsSync);

    return RetVal;
}

static FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_AeadDecrypto
(
    uint32 objectId,
    uint8 Operate,
    Crypto_ContextType *current_context,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_OK;
    Crypto_AlgorithmFamilyType algo;
    Crypto_AlgorithmModeType algo_mode;
    Crypto_JobType *job;

    job = &(current_context->aJobInfo.aJob);

    algo = job->jobPrimitiveInfo->primitiveInfo->algorithm.family;
    algo_mode = job->jobPrimitiveInfo->primitiveInfo->algorithm.mode;

    RetVal = Crypto_Ip_Aead_Crypto(CIPHER_DEC, Operate, current_context,
                                   algo_mode, algo, IsSync);

    return RetVal;
}

/*At present, the counter is shared with all driver object.*/
static FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_SecCountInc
(
    uint32 objectId,
    uint8 Operate,
    Crypto_ContextType *current_context
)
{
    Std_ReturnType RetVal = E_OK;

    if ((uint8)CRYPTO_OPERATIONMODE_FINISH == Operate) {
        /*A atomic operation*/
        SecureCounter += 0x1LLU;
    }
    (void)objectId;

    return RetVal;
}

static FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_SecCountRead
(
    uint32 objectId,
    uint8 Operate,
    Crypto_ContextType *current_context
)
{
    Std_ReturnType RetVal = E_OK;
    Crypto_JobType *job;

    job = &(current_context->aJobInfo.aJob);

    if ((uint8)CRYPTO_OPERATIONMODE_FINISH == Operate) {
        if (NULL_PTR == job->jobPrimitiveInputOutput.output64Ptr) {
            RetVal = E_NOT_OK;
            /*DET ERROR REPORT*/
        } else {
            *(job->jobPrimitiveInputOutput.output64Ptr) = SecureCounter;
        }
    }
    (void)objectId;

    return RetVal;
}

static FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_RandomGenerate
(
    uint32 objectId,
    uint8 Operate,
    Crypto_ContextType *current_context,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_OK;
    uint8 *Random_OutputAddr;
    Crypto_JobType *job;
    Crypto_Ip_TRNGContextType *Context;
    uint32 index_max = 0;
    uint32 cp_left = 0;
    uint32 i;

    job = &(current_context->aJobInfo.aJob);

    /* init random buff. */
    Random_OutputAddr = job->jobPrimitiveInputOutput.outputPtr;

    /* for OPERATIONMODE_SINGLECALL
     * return ok for bypass begin update operation
     */
    if ((uint8)CRYPTO_OPERATIONMODE_FINISH != Operate) {
        return E_OK;
    }

    if (Random_OutputAddr == NULL) {
        return E_NOT_OK;
    }
#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
    /* check output buff cache align */
    if (((uint32)Random_OutputAddr & SEIP_CACHE_ALIGN_32BYTE_ADDR_MASK) != 0 ) {
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */
        /* get context buff */
        Context = (Crypto_Ip_TRNGContextType *)(current_context->pIpContext);
        if (Context == NULL_PTR) {
            return E_NOT_OK;
        }

        /* get loop size */
        /* CRYPTO_IP_TRNG_OUT_LEN_MAX(128) byte one cp */
        index_max = *(job->jobPrimitiveInputOutput.outputLengthPtr) >> 7;
        cp_left = *(job->jobPrimitiveInputOutput.outputLengthPtr) & 0x7F;

        /* loop get */
        for (i = 0; i < index_max; i++) {
            RetVal = Hsm_host_GenerateTrng(Context->out_data,
                                           CRYPTO_IP_TRNG_OUT_LEN_MAX,
                                           CRYPTO_PROCESSING_SYNC);
            if (E_OK == RetVal) {
                mini_memcpy_s(Random_OutputAddr + CRYPTO_IP_TRNG_OUT_LEN_MAX*i,
                              Context->out_data, CRYPTO_IP_TRNG_OUT_LEN_MAX);
            }else{
                return RetVal;
            }
        }

        /* get last one */
        if (cp_left > 0) {
            RetVal = Hsm_host_GenerateTrng(Context->out_data,
                                           CRYPTO_IP_TRNG_OUT_LEN_MAX,
                                           CRYPTO_PROCESSING_SYNC);
            if (E_OK == RetVal) {
                mini_memcpy_s(Random_OutputAddr + CRYPTO_IP_TRNG_OUT_LEN_MAX*i,
                              Context->out_data, cp_left);
            }
        }
#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
        return RetVal;

    } else {
        arch_invalidate_cache_range(Random_OutputAddr, *(job->jobPrimitiveInputOutput.outputLengthPtr));
        /* finish operate. */
        RetVal = Hsm_host_GenerateTrng(Random_OutputAddr,
                     *(job->jobPrimitiveInputOutput.outputLengthPtr), IsSync);
    }
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */

    (void)objectId;

    return RetVal;
}

static FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_SignatureGenerate
(
    uint32 objectId,
    uint8 Operate,
    Crypto_ContextType *current_context,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_OK;
    Crypto_JobType *job;
    Crypto_AlgorithmFamilyType algo;

    job = &(current_context->aJobInfo.aJob);

    algo = job->jobPrimitiveInfo->primitiveInfo->algorithm.family;

    if ((uint8)CRYPTO_OPERATIONMODE_FINISH != Operate) {
        return E_OK;
    }

    switch (algo) {
    case CRYPTO_ALGOFAM_RSA: {
        RetVal = Crypto_Ip_Rsa_Sign(objectId, current_context, IsSync);
        break;
    }
    case CRYPTO_ALGOFAM_ECCNIST: {
        RetVal = Crypto_Ip_Ecdsa_Sign(objectId, current_context, IsSync);
        break;
    }

    case CRYPTO_ALGOFAM_CUSTOM: {
        RetVal = Crypto_Ip_Sm2_Sign(objectId, current_context, IsSync);
        break;
    }
    case CRYPTO_ALGOFAM_ED25519:
    default:
        break;
    }

    return RetVal;
}

static FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_SignatureVerify
(
    uint32 objectId,
    uint8 Operate,
    Crypto_ContextType *current_context,
    Crypto_ProcessingType IsSync
)
{
    Std_ReturnType RetVal = E_OK;
    Crypto_JobType *job;
    Crypto_AlgorithmFamilyType algo;

    job = &(current_context->aJobInfo.aJob);

    algo = job->jobPrimitiveInfo->primitiveInfo->algorithm.family;

    if ((uint8)CRYPTO_OPERATIONMODE_FINISH != Operate) {
        return E_OK;
    }

    switch (algo) {
    case CRYPTO_ALGOFAM_RSA: {
        RetVal = Crypto_Ip_Rsa_Verify(objectId, current_context, IsSync);
        break;
    }
    case CRYPTO_ALGOFAM_ECCNIST: {
        /* The Elliptic curve will be selected accroding to Key Length
            EC_p192r1,EC_p256r1,EC_p384r1,EC_p521r1.
        */
        RetVal = Crypto_Ip_Ecdsa_Verify(objectId, current_context, IsSync);
        break;
    }
    case CRYPTO_ALGOFAM_CUSTOM : {
        RetVal = Crypto_Ip_Sm2_Verify(objectId, current_context, IsSync);
        break;
    }
    case CRYPTO_ALGOFAM_ED25519 :
    default : {
        /*Other Signature algorithm will be added in future*/
        break;
    }
    }

    return RetVal;
}
/*==================EXTERNAL FUNCTION IMPLEMENT========================*/
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_Init
(
    void
)
{
    Std_ReturnType RetVal = E_OK;

    /*init cipher context for cipher job*/
    aCipherContext.context_id = CRYPTO_IP_UNUSED_CONTEXT_ID;
    aCipherContext.inter_iv_data = (void *)(&CipherContext_iv_buff);
    aCipherContext.dualkey_data = (void *)(&CipherContext_dualkey_buff);
    aCipherContext.gcm_input = (void *)(CipherContext_gcm_buff);

    /*init rsa context for PK job*/
    aPKContext.context_id = CRYPTO_IP_UNUSED_CONTEXT_ID;
    aPKContext.hash_data = (void *)(&RSAContext_hash_buff);
    aPKContext.msg_data = (void *)(&RSAContext_msg_buff);
    aPKContext.mac_data = (void *)(&RSAContext_mac_buff);
    aPKContext.key_data = (void *)(&RSAContext_key_buff);

    /*init MAC context for MAC job*/
    aMACContext.context_id = CRYPTO_IP_UNUSED_CONTEXT_ID;
    aMACContext.msg_data = (void *)(&MACContext_msg_buff);
    aMACContext.mac_data = (void *)(&MACContext_mac_buff);

    /*init Hash context for hash job*/
    aHashContext.context_id = CRYPTO_IP_UNUSED_CONTEXT_ID;
    aHashContext.inter_data = (void *)(&HashContext_inter_buff);
    aHashContext.residual_data = (void *)(&HashContext_residual_buff);

    /*init trng context for trng job*/
    aTrngContext.context_id = CRYPTO_IP_UNUSED_CONTEXT_ID;
    aTrngContext.out_data = (void *)(&TRNGContext_data_buff);

    /* init hsm ip*/
    uint8 count = RETRY_COUNT;
    uint32 hsm_init_rst = 0UL;

    do {
        hsm_init_rst = Hsm_host_init(SW_CRYPTO_INIT_MODE);
        if (hsm_init_rst == CRYPTO_HSM_INIT_OK) {
            RetVal = E_OK;
            break;
        } else if (hsm_init_rst == CRYPTO_HSM_INIT_BOOT_FAIL) {
            RetVal = E_NOT_OK;
        } else {
            RetVal = E_NOT_OK;
            break;
        }

        count--;
    } while (count);

    return RetVal;
}

static FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_InitJobQueue
(
    VAR(uint32, AUTOMATIC) objectId,
    Crypto_ObjectType *current_crypto_obj,
    Crypto_ContextType *current_context
)
{
    uint32 i = 0x0UL;
    uint32 index_temp = 0x0UL;
    VAR(Std_ReturnType, AUTOMATIC) RetVal = E_OK;

    if(current_crypto_obj->u32JobQueueSize == 0){
        return CRYPTO_E_QUEUE_FULL;
    }

    /*init job queue info*/
    current_context->aJobsQueueInfo.u32JobQueueUsedSize = 0;
    /*init empty job queue doubly linked lists*/
    current_context->aJobsQueueInfo.pHeadUsedJobQueue = NULL_PTR;
    current_context->aJobsQueueInfo.pHeadEmptyJobQueue =
        &(current_context->aDriverObj_JobQueue[0]);

    for(i = 0; i < current_crypto_obj->u32JobQueueSize; i++){
        if(i == (current_crypto_obj->u32JobQueueSize - 1)){
            /*last node next point to first node*/
            index_temp = 0;
        }else{
            index_temp = i+1;
        }
        current_context->aDriverObj_JobQueue[i].pJobQueueNodeNext =
            &(current_context->aDriverObj_JobQueue[index_temp]);
        if(i == 0){
            /*first node pre point to last node*/
            index_temp = current_crypto_obj->u32JobQueueSize - 1;
        }else{
            index_temp = i-1;
        }
        current_context->aDriverObj_JobQueue[i].pJobQueueNodePre =
            &(current_context->aDriverObj_JobQueue[index_temp]);
    }

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_InitDriverObjContext
(
    VAR(uint32, AUTOMATIC) objectId
)
{
    Crypto_ObjectType *current_crypto_obj;
    Crypto_ContextType *current_context;
    VAR(Std_ReturnType, AUTOMATIC) RetVal;

    /*get crypto driver obj context*/
    RetVal = Crypto_Ip_GetCryptoDriverObj(objectId, &current_crypto_obj,
                                          &current_context);
    if (RetVal != E_OK)
        return RetVal;

    /*init jobqueue*/
    Crypto_Ip_InitJobQueue(objectId, current_crypto_obj, current_context);

    /*init ipcontext*/
    switch (current_crypto_obj->pCryptoPrimitives->eService)
    {
        case CRYPTO_HASH:
            current_context->pIpContext = (uint32 *)&aHashContext;
            break;
        case CRYPTO_MACGENERATE:
        case CRYPTO_MACVERIFY:
            current_context->pIpContext = (uint32 *)&aMACContext;
            break;
        case CRYPTO_RANDOMGENERATE:
            current_context->pIpContext = (uint32 *)&aTrngContext;
            break;
        default:
            break;
    }

    switch (current_crypto_obj->pCryptoPrimitives->eFamily)
    {
        case CRYPTO_ALGOFAM_AES:
            current_context->pIpContext = (uint32 *)&aCipherContext;
            break;
        case CRYPTO_ALGOFAM_RSA:
        case CRYPTO_ALGOFAM_ECCNIST:
            current_context->pIpContext = (uint32 *)&aPKContext;
            break;
        default:
            break;
    }
    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_JobPushQueue
(
    VAR(uint32, AUTOMATIC) objectId,
    P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_APPL_DATA) job
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal = E_OK;
    uint32 i = 0x0UL;
    Crypto_QueueNodeType *JobsQueueEmptyNode;
    Crypto_QueueNodeType *JobsQueueNode_temp;

    Crypto_ObjectType *current_crypto_obj;
    Crypto_ContextType *current_context;

    /*get crypto driver obj*/
    RetVal = Crypto_Ip_GetCryptoDriverObj(objectId, &current_crypto_obj,
                                          &current_context);
    if (RetVal != E_OK)
        return RetVal;

    if(current_crypto_obj->u32JobQueueSize == 0){
        return CRYPTO_E_QUEUE_FULL;
    }

    /*check queue full*/
    if (current_context->aJobsQueueInfo.u32JobQueueUsedSize >=
        current_crypto_obj->u32JobQueueSize){
        return CRYPTO_E_QUEUE_FULL;
    }

    /*get empty node */
    JobsQueueEmptyNode = current_context->aJobsQueueInfo.pHeadEmptyJobQueue;
    if(JobsQueueEmptyNode == NULL_PTR){
        return CRYPTO_E_QUEUE_FULL;
    }else{
        /*last node*/
        if(JobsQueueEmptyNode->pJobQueueNodeNext == JobsQueueEmptyNode){
            current_context->aJobsQueueInfo.pHeadEmptyJobQueue = NULL_PTR;
        }else{
            /*update empty node list, delet first node*/
            current_context->aJobsQueueInfo.pHeadEmptyJobQueue =
                current_context->aJobsQueueInfo.pHeadEmptyJobQueue->
                                                pJobQueueNodeNext;

            JobsQueueEmptyNode->pJobQueueNodePre->pJobQueueNodeNext =
                JobsQueueEmptyNode->pJobQueueNodeNext;
            JobsQueueEmptyNode->pJobQueueNodeNext->pJobQueueNodePre =
                JobsQueueEmptyNode->pJobQueueNodePre;
        }
    }

    /*copy job info*/
    mini_memcpy_s((uint8 *)&(JobsQueueEmptyNode->aJob), (uint8 *)job,
                  sizeof(Crypto_JobType));

    /*add job node into usedqueuelist*/
    JobsQueueNode_temp = current_context->aJobsQueueInfo.pHeadUsedJobQueue;
    if(JobsQueueNode_temp == NULL_PTR){
        /*used queue is empty*/
        current_context->aJobsQueueInfo.pHeadUsedJobQueue =
            JobsQueueEmptyNode;
        JobsQueueEmptyNode->pJobQueueNodeNext = JobsQueueEmptyNode;
        JobsQueueEmptyNode->pJobQueueNodePre = JobsQueueEmptyNode;
        current_context->aJobsQueueInfo.u32JobQueueUsedSize++;
    }else{

        for (i = 0; i < current_context->aJobsQueueInfo.u32JobQueueUsedSize;
             i++) {
            if (JobsQueueEmptyNode->aJob.jobInfo->jobPriority >
                JobsQueueNode_temp->aJob.jobInfo->jobPriority)
            {
                /*pre node link*/
                JobsQueueNode_temp->pJobQueueNodePre->pJobQueueNodeNext =
                    JobsQueueEmptyNode;
                JobsQueueEmptyNode->pJobQueueNodePre =
                    JobsQueueNode_temp->pJobQueueNodePre;
                /*next node link*/
                JobsQueueEmptyNode->pJobQueueNodeNext = JobsQueueNode_temp;
                JobsQueueNode_temp->pJobQueueNodePre = JobsQueueEmptyNode;

                current_context->aJobsQueueInfo.u32JobQueueUsedSize++;

                /*first node*/
                if(i == 0){
                    current_context->aJobsQueueInfo.pHeadUsedJobQueue =
                        JobsQueueEmptyNode;
                }
                break;
            }else{
                /*add to last node*/
                if(i == (current_context->aJobsQueueInfo.u32JobQueueUsedSize - 1)){
                    /*pre node link*/
                    JobsQueueNode_temp->pJobQueueNodeNext->pJobQueueNodePre = JobsQueueEmptyNode;
                    JobsQueueEmptyNode->pJobQueueNodeNext = JobsQueueNode_temp->pJobQueueNodeNext;

                    /*next node link*/
                    JobsQueueNode_temp->pJobQueueNodeNext = JobsQueueEmptyNode;
                    JobsQueueEmptyNode->pJobQueueNodePre = JobsQueueNode_temp;

                    current_context->aJobsQueueInfo.u32JobQueueUsedSize++;
                    break;
                }else{
                    JobsQueueNode_temp = JobsQueueNode_temp->pJobQueueNodeNext;
                }
            }

        }
    }

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_JobPopQueue
(
    VAR(uint32, AUTOMATIC) objectId,
    P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_APPL_DATA) job
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal = E_OK;
    Crypto_QueueNodeType *JobsQueueNode;
    Crypto_QueueNodeType *JobsQueueNode_temp;

    Crypto_ObjectType *current_crypto_obj;
    Crypto_ContextType *current_context;

    /*get crypto driver obj*/
    RetVal = Crypto_Ip_GetCryptoDriverObj(objectId, &current_crypto_obj, &current_context);
    if (RetVal)
        return RetVal;

    if(current_crypto_obj->u32JobQueueSize == 0){
        return CRYPTO_E_QUEUE_FULL;
    }

    /*check queue empty*/
    if ((current_context->aJobsQueueInfo.u32JobQueueUsedSize > current_crypto_obj->u32JobQueueSize)
        || (current_context->aJobsQueueInfo.u32JobQueueUsedSize == 0)){
        return CRYPTO_E_QUEUE_FULL;
    }
    /*get use node */
    JobsQueueNode = current_context->aJobsQueueInfo.pHeadUsedJobQueue;
    /*update used node list, delet first node*/
    current_context->aJobsQueueInfo.pHeadUsedJobQueue = current_context->aJobsQueueInfo.pHeadUsedJobQueue->pJobQueueNodeNext;

    JobsQueueNode->pJobQueueNodePre->pJobQueueNodeNext = JobsQueueNode->pJobQueueNodeNext;
    JobsQueueNode->pJobQueueNodeNext->pJobQueueNodePre = JobsQueueNode->pJobQueueNodePre;

    /*copy job info*/
    mini_memcpy_s((uint8 *)job, (uint8 *)&(JobsQueueNode->aJob), sizeof(Crypto_JobType));

    /*add job node into emptyqueuelist*/
    JobsQueueNode_temp = current_context->aJobsQueueInfo.pHeadEmptyJobQueue;
    if(JobsQueueNode_temp == NULL_PTR){
        /*empty queue is empty*/
        JobsQueueNode->pJobQueueNodeNext = JobsQueueNode;
        JobsQueueNode->pJobQueueNodePre = JobsQueueNode;
    }else{
            /*pre node link*/
            JobsQueueNode_temp->pJobQueueNodePre->pJobQueueNodeNext = JobsQueueNode;
            JobsQueueNode->pJobQueueNodePre = JobsQueueNode_temp->pJobQueueNodePre;
            /*next node link*/
            JobsQueueNode->pJobQueueNodeNext = JobsQueueNode_temp;
            JobsQueueNode_temp->pJobQueueNodePre = JobsQueueNode;
    }

    current_context->aJobsQueueInfo.pHeadEmptyJobQueue = JobsQueueNode;
    current_context->aJobsQueueInfo.u32JobQueueUsedSize--;

    if (current_context->aJobsQueueInfo.u32JobQueueUsedSize == 0) {
        current_context->aJobsQueueInfo.pHeadUsedJobQueue = NULL;
    }

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_GetCryptoDriverObj
(
    uint32 objectId,
    P2VAR(Crypto_ObjectType, AUTOMATIC, CRYPTO_APPL_DATA) *objPtr,
    P2VAR(Crypto_ContextType, AUTOMATIC, CRYPTO_APPL_DATA) *contextPtr
)
{
    Std_ReturnType RetVal = E_OK;
    if(objectId <= CRYPTO_DRIVER_OBJ_NUM){
        *objPtr = &Crypto_aDriverObjectList[objectId - 1];
        *contextPtr = &aDriverObj_Context[objectId - 1];
    }else{
        RetVal = CRYPTO_E_SDRV_DEF_CRYPTOID_OVERFLOW;
    }
    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_ProcessHandle
(
    uint32 objectId,
    Crypto_JobType *job,
    Crypto_ContextType *current_context,
    Crypto_OperationModeType Operation
)
{
    Std_ReturnType RetVal = E_OK;
    Crypto_ProcessingType IsSync = job->jobPrimitiveInfo->processingType;

    switch (Operation) {
        case CRYPTO_OPERATIONMODE_START: {
            /*init current job info for driver obj*/
            job->jobState = CRYPTO_JOBSTATE_ACTIVE;
            mini_memcpy_s((uint8 *)&(current_context->aJobInfo.aJob), (uint8 *)job, sizeof(Crypto_JobType));
            current_context->aJobInfo.nextOpMode = CRYPTO_OPERATIONMODE_UPDATE;
            current_context->Alogrithm = job->jobPrimitiveInfo->primitiveInfo->algorithm.family;

            RetVal = Crypto_Ip_JobHandle(objectId, CRYPTO_OPERATIONMODE_START, current_context, IsSync);

            break;
        }

        case CRYPTO_OPERATIONMODE_UPDATE: {
            if((current_context->aJobInfo.nextOpMode & CRYPTO_OPERATIONMODE_UPDATE) == 0){
                /*must begin with start status*/
                RetVal = E_NOT_OK;
            }else{
                current_context->aJobInfo.nextOpMode |= CRYPTO_OPERATIONMODE_FINISH;
                RetVal = Crypto_Ip_JobHandle(objectId, CRYPTO_OPERATIONMODE_UPDATE, current_context, IsSync);
            }

            break;
        }

        case CRYPTO_OPERATIONMODE_FINISH: {

            if((current_context->aJobInfo.nextOpMode & CRYPTO_OPERATIONMODE_FINISH) == 0){
                /*must after update status*/
                RetVal = E_NOT_OK;
            }else{
                RetVal = Crypto_Ip_JobHandle(objectId, CRYPTO_OPERATIONMODE_FINISH, current_context,
                                                IsSync);
                /*job finish, goto idle*/
                mini_memclr_s((uint8 *)&(current_context->aJobInfo.aJob), sizeof(Crypto_JobType));
                current_context->aJobInfo.nextOpMode = 0;
                job->jobState = CRYPTO_JOBSTATE_IDLE;
            }
            break;
        }

        default: {
            RetVal = E_NOT_OK;
            break;
        }
    }
    if(RetVal == E_NOT_OK){
        /*error happened, goto idle*/
        mini_memclr_s((uint8 *)&(current_context->aJobInfo.aJob), sizeof(Crypto_JobType));
        job->jobState = CRYPTO_JOBSTATE_IDLE;
    }

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_ProcessJob
(
    uint32 objectId,
    Crypto_JobType *job,
    Crypto_ContextType *current_context
)
{
    Std_ReturnType RetVal = E_OK;
    Crypto_OperationModeType Operations;
    uint32 i;
    uint8 Operate;

    Operations = (job->jobPrimitiveInputOutput.mode);

    if (current_context->JobId != job->jobId) {
        /* [SWS_Crypto_00014] A Crypto Driver Object shall only support
         * processing one job at one time. Can't handle other job
         */
        return E_NOT_OK;
    }

    /*crypto driver obj in busy status, will change context data*/
    current_context->CryptoDriverObjState = CRYPTO_IP_CRYPTODRIVEROBJ_STATE_BUSY;
    current_context->aJobInfo.CurrentaJobState = CRYPTO_IP_AJOB_STATE_NORMAL;

    /*process handle*/
    for (i = 0u; i < 0x3u; i++) {
        Operate = Operations & (0x1u << i);

        if ((Operate > 0x0u) && (E_OK == RetVal)) {
            RetVal = Crypto_Ip_ProcessHandle(objectId, job, current_context, (Crypto_OperationModeType)Operate);
        }
    }

    /*crypto driver obj in idle status*/
    current_context->CryptoDriverObjState = CRYPTO_IP_CRYPTODRIVEROBJ_STATE_IDLE;

    if (RetVal != E_OK) {
        return E_NOT_OK;
    }

    return RetVal;
}

#if (CRYPTO_HSM_STATE_API == STD_ON)
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Get_Status
(
    uint32 *device_status
)
{
    Std_ReturnType RetVal = E_OK;

    RetVal = cmd_get_device_status(CRYPTO_KEY_ELEMENT_ENC_KEY_ID,
                                   device_status_buf,
                                   (uint8 *)device_status_mac_buf,
                                   CRYPTO_PROCESSING_SYNC);
    if (RetVal != E_OK) {
        return E_NOT_OK;
    }
#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
    arch_invalidate_cache_range(device_status_buf, 16);
    arch_invalidate_cache_range(device_status, 16);
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */
    Hsm_host_decrypt_key((uint8 *)device_status_buf, 16, CRYPTO_KEY_ELEMENT_ENC_KEY_ID,
                         (uint8 *)device_status, CRYPTO_PROCESSING_SYNC);

    return RetVal;
}
#endif /* CRYPTO_HSM_STATE_API == STD_ON */

#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#ifdef __cplusplus
}
#endif
