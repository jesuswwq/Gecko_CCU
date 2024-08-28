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
 * @file  Crypto_KeyManagement.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Crypto
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Crypto_KeyManagement.h"
#include "Det.h"
#include "Crypto_Cfg.h"
#include "Crypto.h"
#include "RegHelper.h"
#include "Crypto_Hsm.h"
#include "Crypto_ShareMem.h"
#include "Crypto_DerParser.h"
#include "Hsm_Types.h"
#include "mini_libc.h"

#define CRYPTO_KEY_SUPPORT_KEYELEMENT_PERSIST 1

/*key block storage in flash, size is defined by product, default from 1M*/
#define CRYPTO_KEY_BLOCK_STROAGE_ONFLASH_ADDR (CRYPTO_DRIVER_KEYSTORE_STARTADDR)
#define CRYPTO_KEY_BLOCK_STROAGE_FLASH_SECTOR_SIZE 0x1000U /*4K byte*/
#define CRYPTO_KEY_BLOCK_MAC_KEY_ID 4

#define CRYPTO_KEY_BLOCK_BUFF_LEN ROUNDUP((CRYPTO_DRIVER_KEYSTORE_SIZE), CRYPTO_KEY_BLOCK_STROAGE_FLASH_SECTOR_SIZE)
#define CRYPTO_KEY_BLOCK_BUFF_HMAC_LEN SM3_DIGESTSIZE
#define CRYPTO_KEY_BLOCK_BUFF_BODY_LEN (CRYPTO_KEY_BLOCK_BUFF_LEN - CRYPTO_KEY_BLOCK_BUFF_HMAC_LEN)
#define CRYPTO_KEY_BLOCK_KEY_ITEM_NUM 100
#define CRYPTO_KEY_BLOCK_MAGIC  0x4B424F42 /* KBOB keyblob*/
#define CRYPTO_KEY_ELEMENT_MAGIC  0x4B454C45 /* KELE keyelement*/
#define CRYPTO_KEY_ELEMENT_ENC_KEY_ID 4 /*use otp key to enc key element*/

extern P2VAR(Crypto_KeyElementType, AUTOMATIC, CRYPTO_VAR) aElementList[CRYPTO_KEY_ELEMENT_NUM];
extern P2VAR(Crypto_KeyType, AUTOMATIC, CRYPTO_VAR) aKeyList[CRYPTO_KEY_LIST_NUM];
extern Crypto_DriverStateType Crypto_gDriverState;

#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_ON)
#define CRYPTO_START_SEC_VAR_NO_INIT_NO_CACHE_UNSPECIFIED
#else
#define CRYPTO_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_ON) */
#include "Crypto_MemMap.h"

/*used for load key from flash, and update key in iram*/
uint8 __attribute__((aligned(CACHE_LINE))) key_block_buff[CRYPTO_KEY_BLOCK_BUFF_LEN];

#if CRYPTO_KEY_SUPPORT_KEYELEMENT_PERSIST
/*this buff for record keyelmentpersist key store to flash*/
uint8 __attribute__((aligned(CACHE_LINE))) key_block_buff_store[CRYPTO_KEY_BLOCK_BUFF_LEN];
#endif

/*usd for gen key block hmac*/
uint8 __attribute__((aligned(CACHE_LINE))) key_manage_mac_buff[ROUNDUP(SM3_DIGESTSIZE, CACHE_LINE)];

#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_ON)
#define CRYPTO_STOP_SEC_VAR_NO_INIT_NO_CACHE_UNSPECIFIED
#else
#define CRYPTO_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_ON) */
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Crypto_MemMap.h"

static Std_ReturnType (*Crypto_UsrCallOut_Read)(uint8 *dst);

#define CRYPTO_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_VAR_INIT_UNSPECIFIED
#include "Crypto_MemMap.h"

static uint32 Crypto_KeymanagementState = E_NOT_OK;

#define CRYPTO_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"

static uint8 *Crypto_Key_Get_KeyBlockBuff(Crypto_KeyBlockBuffType Buff_Type)
{
    uint8 *pReturnBuff;

    switch (Buff_Type)
    {
        case CRYPTO_KEY_BLOCK_BUFF_FOR_JOB:
            pReturnBuff = &key_block_buff[0];
            break;
#if CRYPTO_KEY_SUPPORT_KEYELEMENT_PERSIST
        case CRYPTO_KEY_BLOCK_BUFF_FOR_STORE:
            pReturnBuff = &key_block_buff_store[0];
            break;
#endif
        default:
            pReturnBuff = NULL_PTR;
            break;
    }

    return pReturnBuff;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Key_UpdateKeyWriteSize
(
    Crypto_KeyElementType *KeyElementPtr,
    uint32 write_size
)
{
    Std_ReturnType RetVal = E_OK;
    crypto_keymanagement_keyitem_head_t *keyitem_head;
    uint8 *pKeyElem;

    pKeyElem = KeyElementPtr->pCryptoElementContent;
    if ((uint32)pKeyElem & 0x3) {
        return E_NOT_OK;
    }
    /*PRQA S 3305 1*/
    keyitem_head = (crypto_keymanagement_keyitem_head_t *)(pKeyElem - ROUNDUP(sizeof(crypto_keymanagement_keyitem_head_t), CACHE_LINE));

    if(write_size == 0){
        KeyElementPtr->u32CryptoElementWritedSize = keyitem_head->key_write_size;
    }else{
        keyitem_head->key_write_size = write_size;
        KeyElementPtr->u32CryptoElementWritedSize = write_size;
    }

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Key_UpdateKeyElementStoreBuff
(
    uint8 *pKeyElemSrc,
    uint8 *pKeyElemTo,
    uint32 write_size
)
{
    Std_ReturnType RetVal = E_OK;
    crypto_keymanagement_keyitem_head_t *keyitem_head;
    uint8 *pKeyElemSrc_Str;
    uint8 *pKeyElemTo_Str;

    if ((uint32)pKeyElemSrc & 0x3) {
        return E_NOT_OK;
    }
    /*PRQA S 3305 1*/
    keyitem_head = (crypto_keymanagement_keyitem_head_t *)(pKeyElemSrc - ROUNDUP(sizeof(crypto_keymanagement_keyitem_head_t), CACHE_LINE));

    if(keyitem_head->key_write_size != write_size){
        RetVal = E_NOT_OK;
    }else{
        pKeyElemSrc_Str = (pKeyElemSrc - ROUNDUP(sizeof(crypto_keymanagement_keyitem_head_t), CACHE_LINE));
        pKeyElemTo_Str = (pKeyElemTo - ROUNDUP(sizeof(crypto_keymanagement_keyitem_head_t), CACHE_LINE));
        mini_memcpy_s(pKeyElemTo_Str, pKeyElemSrc_Str, (write_size + ROUNDUP(sizeof(crypto_keymanagement_keyitem_head_t), CACHE_LINE)));
    }

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Key_RSA_Pub
(
    Crypto_KeyType *KeyPtr,
    Crypto_KeyElementType *KeyElementPtr,
    const uint8 *pKeyContent,
    uint32 KeyLength,
    uint32 modulus_size
)
{
    Std_ReturnType RetVal = E_OK;
    RSAKey_Ext_Sdrv *rsa_key;
    uint32 keybuff_len;
    uint8 *keyelembuff = NULL_PTR;
    uint8 *pStoreCryptoElementContent = NULL_PTR;
    uint32 keyElementId;
    crypto_keymanagement_keyitem_head_t *keyitem_head;

    if (KeyLength < (modulus_size * 2U)) {
        RetVal = E_NOT_OK;
    } else {

        keyElementId = KeyElementPtr->u32CryptoKeyElementId;

        keybuff_len = (modulus_size*CRYPTO_KEY_PKCS1_PUBKEY_ITEM_NUM) +
                       ROUNDUP(sizeof(RSAKey_Head_Ext_Sdrv), CACHE_LINE);
        /*get keybuff node in keystore block buff*/
        RetVal = Crypto_GetElementBuffInBlock(KeyPtr->u32CryptoKeyId, keyElementId,
                                              KeyPtr->CryptoKeyType, &keyelembuff,
                                              keybuff_len, CRYPTO_KEY_BLOCK_BUFF_FOR_JOB, TRUE);
        if(RetVal == E_OK){
            if ((uint32)keyelembuff & 0x3) {
                return E_NOT_OK;
            }
            /*PRQA S 3305 1*/
            rsa_key = (RSAKey_Ext_Sdrv *)keyelembuff;
            rsa_key->keybuff_head.n_sz = modulus_size;
            rsa_key->keybuff_head.n = (uint8 *)rsa_key + ROUNDUP(sizeof(RSAKey_Head_Ext_Sdrv), CACHE_LINE);
            rsa_key->keybuff_head.e = rsa_key->keybuff_head.n + modulus_size;

            /*copy n e buff*/
            mini_memcpy_s(rsa_key->keybuff_head.n, pKeyContent, modulus_size*2);
        } else {
            return E_NOT_OK;
        }
        /*PRQA S 3305 1*/
        keyitem_head = (crypto_keymanagement_keyitem_head_t *)(keyelembuff - ROUNDUP(sizeof(crypto_keymanagement_keyitem_head_t), CACHE_LINE));
        keyitem_head->key_write_size = keybuff_len;

        /*update key to storebuff for Fls sync*/
        if (TRUE == KeyElementPtr->bCryptoKeyElementPersist) {
            RetVal = Crypto_GetElementBuffInBlock(KeyPtr->u32CryptoKeyId, keyElementId,
                                                  KeyPtr->CryptoKeyType,
                                                  &(pStoreCryptoElementContent),
                                                  keybuff_len, CRYPTO_KEY_BLOCK_BUFF_FOR_STORE, TRUE);
            /*update block store buff*/
            if(RetVal == E_OK){
                Crypto_Key_UpdateKeyElementStoreBuff(keyelembuff, pStoreCryptoElementContent, keybuff_len);
            }
        }
    }

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Key_RSA_Pri
(
    Crypto_KeyType *KeyPtr,
    Crypto_KeyElementType *KeyElementPtr,
    const uint8 *pKeyContent,
    uint32 KeyLength,
    uint32 modulus_size
)
{
    Std_ReturnType RetVal = E_OK;
    RSAKey_Ext_Sdrv *rsa_key;
    uint32 keybuff_len;
    uint8 *keyelembuff = NULL_PTR;
    uint8 *pStoreCryptoElementContent = NULL_PTR;
    uint32 keyElementId;
    crypto_keymanagement_keyitem_head_t *keyitem_head;

    if (KeyLength < (modulus_size * 3U)) {
        RetVal = E_NOT_OK;
    } else {

        keyElementId = KeyElementPtr->u32CryptoKeyElementId;

        keybuff_len = (modulus_size*CRYPTO_KEY_PKCS1_PRIKEY_ITEM_NUM) + ROUNDUP(sizeof(RSAKey_Head_Ext_Sdrv), CACHE_LINE);
        /*get keybuff node in keystore block buff*/
        RetVal = Crypto_GetElementBuffInBlock(KeyPtr->u32CryptoKeyId, keyElementId, KeyPtr->CryptoKeyType, &keyelembuff, keybuff_len, CRYPTO_KEY_BLOCK_BUFF_FOR_JOB, TRUE);
        if (RetVal == E_OK) {
            if ((uint32)keyelembuff & 0x3) {
                return E_NOT_OK;
            }
            /*PRQA S 3305 1*/
            rsa_key = (RSAKey_Ext_Sdrv *)keyelembuff;

            rsa_key->keybuff_head.n_sz = modulus_size;
            rsa_key->keybuff_head.n = (uint8 *)rsa_key + ROUNDUP(sizeof(RSAKey_Head_Ext_Sdrv), CACHE_LINE);
            rsa_key->keybuff_head.e = rsa_key->keybuff_head.n + modulus_size;
            rsa_key->keybuff_head.d = rsa_key->keybuff_head.e + modulus_size;

            /*copy n e buff*/
            mini_memcpy_s(rsa_key->keybuff_head.n, pKeyContent, modulus_size*2);

            /*enc pri key d buff*/
            mini_memcpy_s(rsa_key->keybuff_head.d, pKeyContent + (modulus_size * 2), rsa_key->keybuff_head.n_sz);
#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
            flush_dcache_range((uint32)(rsa_key->keybuff_head.d), rsa_key->keybuff_head.n_sz);
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */
            Hsm_host_encrypt_key(rsa_key->keybuff_head.d, rsa_key->keybuff_head.n_sz, CRYPTO_KEY_ELEMENT_ENC_KEY_ID, rsa_key->keybuff_head.d, CRYPTO_PROCESSING_SYNC);
        } else {
            return E_NOT_OK;
        }

        rsa_key->keybuff_head.keytype = CMD_KEY_EXTERNAL_CIPHERTEXT;
        rsa_key->keybuff_head.keyid1 = CRYPTO_KEY_ELEMENT_ENC_KEY_ID;
        /*PRQA S 3305 1*/
        keyitem_head = (crypto_keymanagement_keyitem_head_t *)(keyelembuff - ROUNDUP(sizeof(crypto_keymanagement_keyitem_head_t), CACHE_LINE));
        keyitem_head->key_write_size = keybuff_len;

        /*update key to storebuff for Fls sync*/
        if (TRUE == KeyElementPtr->bCryptoKeyElementPersist) {
            RetVal = Crypto_GetElementBuffInBlock(KeyPtr->u32CryptoKeyId, keyElementId, KeyPtr->CryptoKeyType, &(pStoreCryptoElementContent), keybuff_len, CRYPTO_KEY_BLOCK_BUFF_FOR_STORE, TRUE);
            /*update block store buff*/
            if(RetVal == E_OK){
                Crypto_Key_UpdateKeyElementStoreBuff(keyelembuff, pStoreCryptoElementContent, keybuff_len);
            }
        }
    }

    return RetVal;
}

/*--------------------------------------------------------------*/
/*PRQA S 2755 2*/
static FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Key_BIN_OCTET
(
    Crypto_KeyType *KeyPtr,
    Crypto_KeyElementType *KeyElementPtr,
    const uint8 *pKeyContent,
    uint32 KeyLength
)
{
    Std_ReturnType RetVal;

    switch (KeyPtr->CryptoKeyType) {

    case CRYPTO_KEYTYPE_P192_PUB:
    case CRYPTO_KEYTYPE_P192_PRI:
    case CRYPTO_KEYTYPE_P224_PUB:
    case CRYPTO_KEYTYPE_P224_PRI:
    case CRYPTO_KEYTYPE_P256_PUB:
    case CRYPTO_KEYTYPE_P256_PRI:
    case CRYPTO_KEYTYPE_P384_PUB:
    case CRYPTO_KEYTYPE_P384_PRI:
    case CRYPTO_KEYTYPE_P521_PUB:
    case CRYPTO_KEYTYPE_P521_PRI:
    case CRYPTO_KEYTYPE_SM2P256_PUB:
    case CRYPTO_KEYTYPE_SM2P256_PRI:
    case CRYPTO_KEYTYPE_ED25519_PUB:
    case CRYPTO_KEYTYPE_ED25519_PRI:
    {
        /*not support*/
        RetVal = E_OK;
        break;
    }
    case CRYPTO_KEYTYPE_RSA1024_PUB: {
        RetVal = Crypto_Key_RSA_Pub (KeyPtr, KeyElementPtr, pKeyContent, KeyLength, 128U);
        break;
    }

    case CRYPTO_KEYTYPE_RSA1024_PRI: {
        RetVal = Crypto_Key_RSA_Pri (KeyPtr, KeyElementPtr, pKeyContent, KeyLength, 128U);
        break;
    }

    case CRYPTO_KEYTYPE_RSA2048_PUB: {
        RetVal = Crypto_Key_RSA_Pub (KeyPtr, KeyElementPtr, pKeyContent, KeyLength, 256U);
        break;
    }

    case CRYPTO_KEYTYPE_RSA2048_PRI: {
        RetVal = Crypto_Key_RSA_Pri (KeyPtr, KeyElementPtr, pKeyContent, KeyLength, 256U);
        break;
    }

    case CRYPTO_KEYTYPE_RSA3072_PUB: {
        RetVal = Crypto_Key_RSA_Pub (KeyPtr, KeyElementPtr, pKeyContent, KeyLength, 384U);
        break;
    }

    case CRYPTO_KEYTYPE_RSA3072_PRI: {
        RetVal = Crypto_Key_RSA_Pri (KeyPtr, KeyElementPtr, pKeyContent, KeyLength, 384U);
        break;
    }

    case CRYPTO_KEYTYPE_RSA4096_PUB: {
        RetVal = Crypto_Key_RSA_Pub (KeyPtr, KeyElementPtr, pKeyContent, KeyLength, 512U);
        break;
    }

    case CRYPTO_KEYTYPE_RSA4096_PRI: {
        RetVal = Crypto_Key_RSA_Pri (KeyPtr, KeyElementPtr, pKeyContent, KeyLength, 512U);
        break;
    }

    default : {
        RetVal = E_NOT_OK;
        break;
    }
    }

    return RetVal;
}

static FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Key_PKCS1_PUB
(
    Crypto_KeyType *KeyPtr,
    Crypto_KeyElementType *KeyElementPtr,
    const uint8 *pKeyContent,
    uint32 KeyLength
)
{
    Std_ReturnType RetVal;
    RSAKey_Ext_Sdrv *KeyDataAddr;
    uint32 modulus_len;
    uint32 keybuff_len;
    uint8 *keyelembuff;
    uint8 *pStoreCryptoElementContent;
    crypto_keymanagement_keyitem_head_t *keyitem_head;

    uint32 keyElementId;

    keyElementId = KeyElementPtr->u32CryptoKeyElementId;

    RetVal = Crypto_Parse_PKCS1_KEYMODULUSLEN(&pKeyContent, (uint8 *)(pKeyContent + KeyLength), CRYPTO_ASN1_PKCS1_KEYTYPE_PUBKEY, &modulus_len);

    if(RetVal == E_OK){
        keybuff_len = (modulus_len*CRYPTO_KEY_PKCS1_PUBKEY_ITEM_NUM) + ROUNDUP(sizeof(RSAKey_Head_Ext_Sdrv), CACHE_LINE);
        /*get keybuff node in keystore block buff*/
        RetVal = Crypto_GetElementBuffInBlock(KeyPtr->u32CryptoKeyId, keyElementId, KeyPtr->CryptoKeyType, &keyelembuff, keybuff_len, CRYPTO_KEY_BLOCK_BUFF_FOR_JOB, TRUE);
        if(RetVal == E_OK){
            if ((uint32)keyelembuff & 0x3) {
                return E_NOT_OK;
            }
            /*PRQA S 3305 1*/
            KeyDataAddr = (RSAKey_Ext_Sdrv *)keyelembuff;
            RetVal = Crypto_Parse_PKCS1_PUBKEY(&pKeyContent, (uint8 *)(pKeyContent + KeyLength), KeyDataAddr);
            if (RetVal != E_OK)
                return E_NOT_OK;

            /*PRQA S 3305 1*/
            keyitem_head = (crypto_keymanagement_keyitem_head_t *)(keyelembuff - ROUNDUP(sizeof(crypto_keymanagement_keyitem_head_t), CACHE_LINE));
            keyitem_head->key_write_size = keybuff_len;

            /*update key to storebuff for Fls sync*/
            if (TRUE == KeyElementPtr->bCryptoKeyElementPersist) {
                RetVal = Crypto_GetElementBuffInBlock(KeyPtr->u32CryptoKeyId, keyElementId, KeyPtr->CryptoKeyType, &(pStoreCryptoElementContent), keybuff_len, CRYPTO_KEY_BLOCK_BUFF_FOR_STORE, TRUE);
                /*update block store buff*/
                if(RetVal == E_OK){
                    Crypto_Key_UpdateKeyElementStoreBuff(keyelembuff, pStoreCryptoElementContent, keybuff_len);
                }
            }
        }
    }

    return RetVal;
}

static FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Key_PKCS1_PRI
(
    Crypto_KeyType *KeyPtr,
    Crypto_KeyElementType *KeyElementPtr,
    const uint8 *pKeyContent,
    uint32 KeyLength
)
{
    Std_ReturnType RetVal;
    RSAKey_Ext_Sdrv *KeyDataAddr;
    uint32 modulus_len;
    uint32 keybuff_len;
    uint8 *keyelembuff = NULL_PTR;
    uint8 *pStoreCryptoElementContent = NULL_PTR;
    uint32 keyElementId;
    crypto_keymanagement_keyitem_head_t *keyitem_head;

    keyElementId = KeyElementPtr->u32CryptoKeyElementId;
    RetVal = Crypto_Parse_PKCS1_KEYMODULUSLEN(&pKeyContent, (uint8 *)(pKeyContent + KeyLength), CRYPTO_ASN1_PKCS1_KEYTYPE_PRIKEY, &modulus_len);

    if(RetVal == E_OK){
        keybuff_len = (modulus_len*CRYPTO_KEY_PKCS1_PRIKEY_ITEM_NUM) + ROUNDUP(sizeof(RSAKey_Head_Ext_Sdrv), CACHE_LINE);
        /*get keybuff node in keystore block buff*/
        RetVal = Crypto_GetElementBuffInBlock(KeyPtr->u32CryptoKeyId, keyElementId, KeyPtr->CryptoKeyType, &keyelembuff, keybuff_len, CRYPTO_KEY_BLOCK_BUFF_FOR_JOB, TRUE);
        if(RetVal == E_OK){
            if ((uint32)keyelembuff & 0x3) {
                return E_NOT_OK;
            }
            /*PRQA S 3305 1*/
            KeyDataAddr = (RSAKey_Ext_Sdrv *)keyelembuff;
            RetVal = Crypto_Parse_PKCS1_PRIKEY(&pKeyContent, (uint8 *)(pKeyContent + KeyLength), KeyDataAddr);
            if(RetVal == E_OK){
#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
                /*enc pri key*/
                flush_dcache_range((uint32)(KeyDataAddr->keybuff_head.d), KeyDataAddr->keybuff_head.n_sz);
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */
                Hsm_host_encrypt_key(KeyDataAddr->keybuff_head.d, KeyDataAddr->keybuff_head.n_sz, CRYPTO_KEY_ELEMENT_ENC_KEY_ID, KeyDataAddr->keybuff_head.d, CRYPTO_PROCESSING_SYNC);
                KeyDataAddr->keybuff_head.keytype = CMD_KEY_EXTERNAL_CIPHERTEXT;
                KeyDataAddr->keybuff_head.keyid1 = CRYPTO_KEY_ELEMENT_ENC_KEY_ID;
            }
            /*PRQA S 3305 1*/
            keyitem_head = (crypto_keymanagement_keyitem_head_t *)(keyelembuff - ROUNDUP(sizeof(crypto_keymanagement_keyitem_head_t), CACHE_LINE));
            keyitem_head->key_write_size = keybuff_len;

            /*update key to storebuff for Fls sync*/
            if (TRUE == KeyElementPtr->bCryptoKeyElementPersist) {
                RetVal = Crypto_GetElementBuffInBlock(KeyPtr->u32CryptoKeyId, keyElementId, KeyPtr->CryptoKeyType, &(pStoreCryptoElementContent), keybuff_len, CRYPTO_KEY_BLOCK_BUFF_FOR_STORE, TRUE);
                /*update block store buff*/
                if(RetVal == E_OK){
                    Crypto_Key_UpdateKeyElementStoreBuff(keyelembuff, pStoreCryptoElementContent, keybuff_len);
                }
            }
        }
    }

    return RetVal;
}

/*read and write key from flash*/
static FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_ReadKeyBlobFromFls
(
    Std_ReturnType (*Crypto_UsrCallOut_Read)(uint8 *dst),
    uint8 *pKeyBlobPtr
)
{
    Std_ReturnType RetVal = E_OK;
    crypto_keymanagement_keyblock_head_t *keyblock_head;

    if (Crypto_UsrCallOut_Read == NULL)
        return E_NOT_OK;

    /*read data from flash*/
    RetVal = Crypto_UsrCallOut_Read(pKeyBlobPtr);
    if (RetVal != E_OK)
        return RetVal;
    if ((uint32)pKeyBlobPtr & 0x3) {
        return E_NOT_OK;
    }
    /*check keyblock hmac*/
    /*PRQA S 3305 1*/
    keyblock_head = (crypto_keymanagement_keyblock_head_t *)pKeyBlobPtr;

    if (keyblock_head->block_magic != CRYPTO_KEY_BLOCK_MAGIC) {
        /*keyblock buff is empty, need init*/
        mini_memclr_s(pKeyBlobPtr, CRYPTO_KEY_BLOCK_BUFF_LEN);
    }else{
        /*check keyblock hmac*/
       // mini_memcpy_s(key_manage_mac_buff, pKeyBlobPtr + CRYPTO_KEY_BLOCK_BUFF_BODY_LEN, CRYPTO_KEY_BLOCK_BUFF_HMAC_LEN);
#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
        arch_clean_cache_range(pKeyBlobPtr, CRYPTO_KEY_BLOCK_BUFF_LEN);
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */
        RetVal = Hsm_host_hmac_verify(HMAC_ALG_SM3, pKeyBlobPtr,
                                      CRYPTO_KEY_BLOCK_BUFF_BODY_LEN,
                                      CMD_KEY_INTERNAL, NULL_PTR,
                                      CRYPTO_KEY_BLOCK_MAC_KEY_ID,
                                      64, pKeyBlobPtr + CRYPTO_KEY_BLOCK_BUFF_BODY_LEN,
                                      CRYPTO_KEY_BLOCK_BUFF_HMAC_LEN, NULL_PTR,
                                      NULL, CRYPTO_PROCESSING_SYNC);
    }

    return RetVal;
}

/*input keyemelement value is cipher text*/
static FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_WriteKeyBlobToFls
(
    Std_ReturnType (*Crypto_UsrCallOut_Sync)(uint8 *pKeyBlobPtr),
    uint8 *pKeyBlobPtr
)
{
    Std_ReturnType RetVal = E_NOT_OK;
#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
    /*update hmac value*/
    arch_clean_cache_range(pKeyBlobPtr, CRYPTO_KEY_BLOCK_BUFF_BODY_LEN);
    arch_invalidate_cache_range(pKeyBlobPtr + CRYPTO_KEY_BLOCK_BUFF_BODY_LEN, CRYPTO_KEY_BLOCK_BUFF_HMAC_LEN);
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */
    RetVal = Hsm_host_hmac_gen(HMAC_ALG_SM3, pKeyBlobPtr,
                               CRYPTO_KEY_BLOCK_BUFF_BODY_LEN, CMD_KEY_INTERNAL,
                               NULL_PTR, CRYPTO_KEY_BLOCK_MAC_KEY_ID, 64,
                               pKeyBlobPtr + CRYPTO_KEY_BLOCK_BUFF_BODY_LEN, NULL_PTR, CRYPTO_PROCESSING_SYNC);

    if ((RetVal == E_OK) && (Crypto_UsrCallOut_Sync != NULL))
        RetVal = Crypto_UsrCallOut_Sync(pKeyBlobPtr);
    else
        RetVal = E_NOT_OK;

    return RetVal;
}

/*hsmtype key buff in block buff*/
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_GetElementBuffInBlock
(
    uint32 u32CryptoKeyId,
    uint32 u32KeyElementId,
    uint32 u32KeyType,
    P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) *KeyElemPtr,
    uint32 inLength,
    Crypto_KeyBlockBuffType Buff_Type,
    boolean isCreatNew
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    crypto_keymanagement_keyblock_head_t *keyblock_head;
    crypto_keymanagement_keyitem_t *keyelem_item;
    crypto_keymanagement_keyitem_t *keyelem_item_current;
    uint8 *p_blockbuff_end;
    uint32 i;
    uint8 *key_block;

    key_block = Crypto_Key_Get_KeyBlockBuff(Buff_Type);

    if(key_block == NULL_PTR || ((uint32)key_block & 0x3)) {
        return E_NOT_OK;
    }
    /*PRQA S 3305 1*/
    keyblock_head = (crypto_keymanagement_keyblock_head_t *)key_block;
    /*pointer to the last byte addr*/
    p_blockbuff_end = key_block + CRYPTO_KEY_BLOCK_BUFF_BODY_LEN;
    /*check block buff is init*/

    /*set keyvalue to blockbuff*/
    /*update block buff, not flush to flash. flush only at poweroff or force sync*/
    /*PRQA S 3305 1*/
    keyelem_item = (crypto_keymanagement_keyitem_t *)(key_block + ROUNDUP(sizeof(crypto_keymanagement_keyblock_head_t), CACHE_LINE));

    keyelem_item_current = keyelem_item;
    for (i = 0; i < keyblock_head->key_max_item_num; i++) {

        if(keyelem_item_current->keyitem_head.key_magic == CRYPTO_KEY_ELEMENT_MAGIC){
            /*keyelement item is not empty*/
            if((keyelem_item_current->keyitem_head.cryptokeyid == u32CryptoKeyId)
            &&(keyelem_item_current->keyitem_head.keyelementid == u32KeyElementId)
            &&(keyelem_item_current->keyitem_head.key_type == u32KeyType))
            {
                *KeyElemPtr = (uint8 *)keyelem_item_current + ROUNDUP(sizeof(crypto_keymanagement_keyitem_head_t), CACHE_LINE);
                RetVal = E_OK;
                break;
            }else{
                /*get next key item, offset = key head size + key value size, addr will be opr as pointer, so must 4byte align*/
                /*PRQA S 3305 1*/
                keyelem_item_current = (crypto_keymanagement_keyitem_t *)(((uint8 *)keyelem_item_current)+ROUNDUP((keyelem_item_current->keyitem_head.key_elem_size), CACHE_LINE)+ROUNDUP(sizeof(crypto_keymanagement_keyitem_head_t), CACHE_LINE));
            }
        }else{
            if(isCreatNew == TRUE){
                /*keyelement item is empty, creat new item*/
                if(p_blockbuff_end > ((uint8 *)keyelem_item_current) + ROUNDUP(inLength, CACHE_LINE) + ROUNDUP(sizeof(crypto_keymanagement_keyitem_head_t), CACHE_LINE)){
                    keyelem_item_current->keyitem_head.key_magic = CRYPTO_KEY_ELEMENT_MAGIC;
                    keyelem_item_current->keyitem_head.cryptokeyid = u32CryptoKeyId;
                    keyelem_item_current->keyitem_head.keyelementid = u32KeyElementId;
                    keyelem_item_current->keyitem_head.key_type = u32KeyType;
                    keyelem_item_current->keyitem_head.key_elem_size = inLength;
                    keyblock_head->key_current_num++;
                    *KeyElemPtr = (uint8 *)keyelem_item_current + ROUNDUP(sizeof(crypto_keymanagement_keyitem_head_t), CACHE_LINE);
                    RetVal = E_OK;
                }else{
                    RetVal = E_NOT_OK;
                }
            }else{
                RetVal = E_NOT_OK;
            }

            break;
        }
    }

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_InstallKey
(
    Crypto_KeyType *KeyPtr,
    Crypto_KeyElementType *KeyElementPtr,
    const uint8 *pKeyContent,
    uint32 keyLength
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    Crypto_KeyElementFormatType ElementFormat;

    do {

        if ((KeyPtr == NULL_PTR)||(KeyElementPtr == NULL_PTR)) {
            RetVal = E_NOT_OK;
            break;
        }

        ElementFormat = KeyElementPtr->eCryptoKeyElementFormatType;

        if (pKeyContent != NULL_PTR) {

            switch (ElementFormat) {
                case CRYPTO_KE_FORMAT_BIN_OCTET: {
                    RetVal = Crypto_Key_BIN_OCTET(KeyPtr, KeyElementPtr, pKeyContent, keyLength);
                    break;
                }
                case CRYPTO_KE_FORMAT_BIN_RSA_PRIVATEKEY: {
                    RetVal = Crypto_Key_PKCS1_PRI(KeyPtr, KeyElementPtr, pKeyContent, keyLength);
                    break;
                }
                case CRYPTO_KE_FORMAT_BIN_RSA_PUBLICKEY: {
                    RetVal = Crypto_Key_PKCS1_PUB(KeyPtr, KeyElementPtr, pKeyContent, keyLength);
                    break;
                }
                default: {
                    RetVal = E_NOT_OK;
                    break;
                }
            }
        }
    } while (0);

    if (RetVal != E_OK) {
        RetVal = CRYPTO_E_KEY_INSTALL_FAIL;
    }
    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_GetKeyPtr
(
    VAR(uint32, AUTOMATIC) keyId,
    P2VAR(Crypto_KeyType, AUTOMATIC, CRYPTO_APPL_DATA) *keyPtr
)
{
    Std_ReturnType RetVal = E_OK;
    uint32 i = 0x0UL;

    while (i < CRYPTO_KEY_LIST_NUM) {
        if (keyId == aKeyList[i]->u32CryptoKeyId) {
            *keyPtr = aKeyList[i];
            break;
        }

        i++;
    }

    if (i == CRYPTO_KEY_LIST_NUM) {
        RetVal = CRYPTO_E_KEY_NOT_AVAILABLE;
    }

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_GetElementPtr
(
    P2VAR(Crypto_KeyType, AUTOMATIC, CRYPTO_APPL_DATA) keyPtr,
    VAR(uint32, AUTOMATIC) keyElementId,
    P2VAR(Crypto_KeyElementType, AUTOMATIC, CRYPTO_APPL_DATA) *keyElementPtr
)
{
    Std_ReturnType RetVal = E_OK;
    uint32 i = 0x0UL;
    uint32 ElementGlobalIndex;

    if (NULL_PTR != keyPtr) {
        while (i < keyPtr->u32ElementsNum) {
            ElementGlobalIndex = keyPtr->u32CryptoKeyElements[i];

            if (keyElementId == aElementList[ElementGlobalIndex]->u32CryptoKeyElementId) {
                *keyElementPtr = aElementList[ElementGlobalIndex];
                if(aElementList[ElementGlobalIndex]->pCryptoElementContent == NULL_PTR){
                    /*init pCryptoElementContent*/
                    RetVal = Crypto_GetElementBuffInBlock(keyPtr->u32CryptoKeyId, keyElementId,
                                                          CRYPTO_KEYTYPE_ELEMENT_RAW,
                                                          &(aElementList[ElementGlobalIndex]->pCryptoElementContent),
                                                          aElementList[ElementGlobalIndex]->u32CryptoKeyElementSize,
                                                          CRYPTO_KEY_BLOCK_BUFF_FOR_JOB, TRUE);
                    if (RetVal == E_OK) {
                        if(aElementList[ElementGlobalIndex]->bCryptoKeyElementPersist == TRUE){
                            /*update writesize*/
                            Crypto_Key_UpdateKeyWriteSize(aElementList[ElementGlobalIndex], 0);
                        }
                    }
                }
                break;
            }

            i++;
        }

        if (i == keyPtr->u32ElementsNum) {
            RetVal = CRYPTO_E_KEY_NOT_AVAILABLE;
        }
    } else {
        RetVal = E_NOT_OK;
    }

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_UsrCallOut_Read_Init
(
    Std_ReturnType (*Usr_Read)(uint8 *dst)
)
{
    Std_ReturnType RetVal;

    if (Usr_Read) {
        Crypto_UsrCallOut_Read = Usr_Read;
        RetVal = E_OK;
    } else {
        RetVal = E_NOT_OK;
    }

    return RetVal;
}

FUNC(void, CRYPTO_CODE) Crypto_KeyManagerInit
(
    void
)
{
    Std_ReturnType RetVal;
    crypto_keymanagement_keyblock_head_t *keyblock_head;
    uint8 *key_block;
    uint8 *key_block_for_store;

    if (E_NOT_OK == Crypto_KeymanagementState) {
        key_block = Crypto_Key_Get_KeyBlockBuff(CRYPTO_KEY_BLOCK_BUFF_FOR_JOB);

        if ((uint32)key_block & 0x3) {
#if (CRYPTO_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError\
            (\
             (uint16)CRYPTO_MODULE_ID, \
             (uint8)CRYPTO_INSTANCE_ID, \
             (uint8)CRYPTO_INIT_ID, \
             (uint8)CRYPTO_E_PARAM_POINTER \
            );
#endif /* CRYPTO_DEV_ERROR_DETECT == STD_ON */
            return;
        }

        /* Load the key from flash to key_block_buff */
        RetVal = Crypto_ReadKeyBlobFromFls(Crypto_UsrCallOut_Read, key_block);

        if (E_OK == RetVal) {
            /*load keyblock buff from flash success*/
            /*PRQA S 3305 1*/
            keyblock_head = (crypto_keymanagement_keyblock_head_t *)key_block;
            if(keyblock_head->block_magic == CRYPTO_KEY_BLOCK_MAGIC){

            }else{
                /*keyblock in flash is empty, init keyblock buff head info*/
                keyblock_head->block_magic = CRYPTO_KEY_BLOCK_MAGIC;
                keyblock_head->version = 0x1234;
                keyblock_head->block_size = CRYPTO_KEY_BLOCK_BUFF_LEN;
                keyblock_head->key_max_item_num = CRYPTO_KEY_BLOCK_KEY_ITEM_NUM;
            }
        }else{
            /*load fail*/
            mini_memclr_s(key_block, CRYPTO_KEY_BLOCK_BUFF_LEN);
            /*PRQA S 3305 1*/
            keyblock_head = (crypto_keymanagement_keyblock_head_t *)key_block;
            /*init keyblock buff head info, can run in ram*/
            keyblock_head->block_magic = CRYPTO_KEY_BLOCK_MAGIC;
            keyblock_head->version = 0x1234;
            keyblock_head->block_size = CRYPTO_KEY_BLOCK_BUFF_LEN;
            keyblock_head->key_max_item_num = CRYPTO_KEY_BLOCK_KEY_ITEM_NUM;
            /* Prevents multiple initialization calls */
            for (int i = 0; i < CRYPTO_KEY_ELEMENT_NUM; i++) {
                if (NULL != aElementList[i]->pCryptoElementContent)
                    aElementList[i]->pCryptoElementContent = NULL;
            }
        }

        #if CRYPTO_KEY_SUPPORT_KEYELEMENT_PERSIST
        /*init store buff*/
        key_block_for_store = Crypto_Key_Get_KeyBlockBuff(CRYPTO_KEY_BLOCK_BUFF_FOR_STORE);
        mini_memcpy_s(key_block_for_store, key_block, CRYPTO_KEY_BLOCK_BUFF_LEN);
        #endif
        if (E_OK == RetVal) {
            Crypto_KeymanagementState = E_OK;
        }
    }
}

/*store key element to flash*/
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_KeyElementSync
(
    Std_ReturnType (*Crypto_UsrCallOut_Sync)(uint8 *pKeyBlobPtr)
)
{
    Std_ReturnType RetVal;
    uint8 *key_block;
    #if CRYPTO_KEY_SUPPORT_KEYELEMENT_PERSIST
    key_block = Crypto_Key_Get_KeyBlockBuff(CRYPTO_KEY_BLOCK_BUFF_FOR_STORE);
    #else
    key_block = Crypto_Key_Get_KeyBlockBuff(CRYPTO_KEY_BLOCK_BUFF_FOR_JOB);
    #endif
    RetVal = Crypto_WriteKeyBlobToFls(Crypto_UsrCallOut_Sync, key_block);
    return RetVal;
}

/*erase keystore domian*/
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_KeyElementErase
(
    Std_ReturnType (*Crypto_UsrCallOut_Erase)(void)
)
{
    Std_ReturnType RetVal = E_NOT_OK;

    if (Crypto_UsrCallOut_Erase != NULL)
        RetVal = Crypto_UsrCallOut_Erase();

    return RetVal;
}

/* Warning: The hsm has no internal nonvolatile ,not support 'Persist' */
/*PRQA S 2755 1*/
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_KeyElementSet
(
    VAR(uint32, AUTOMATIC) u32CryptoKeyId,
    VAR(uint32, AUTOMATIC) u32KeyElementId,
    P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_CONST) pKeyPtr,
    VAR(uint32, AUTOMATIC) u32KeyLength
)
{
    Std_ReturnType RetVal;
    Crypto_KeyType *KeyPtr;
    Crypto_KeyElementType *KeyElementPtr = NULL_PTR;
    uint8 *pStoreCryptoElementContent;

#if (CRYPTO_DEV_ERROR_DETECT == STD_ON)

    if (CRYPTO_DRIVER_UNINIT == Crypto_gDriverState) {
        (void)Det_ReportError\
        (\
         (uint16)CRYPTO_MODULE_ID, \
         (uint8)CRYPTO_INSTANCE_ID, \
         (uint8)CRYPTO_KEY_ELEMENT_SET_ID, \
         (uint8)CRYPTO_E_UNINIT \
        );
        RetVal = E_NOT_OK;
    } else if (u32CryptoKeyId > CRYPTO_MAX_KEY_ID) {    /*From 1 to */
        (void)Det_ReportError\
        (\
         (uint16)CRYPTO_MODULE_ID, \
         (uint8)CRYPTO_INSTANCE_ID, \
         (uint8)CRYPTO_KEY_ELEMENT_SET_ID, \
         (uint8)CRYPTO_E_PARAM_HANDLE \
        );
        RetVal = E_NOT_OK;
    } else if (u32KeyElementId > CRYPTO_MAX_KEY_ELEMENT_ID) {
        (void)Det_ReportError\
        (\
         (uint16)CRYPTO_MODULE_ID, \
         (uint8)CRYPTO_INSTANCE_ID, \
         (uint8)CRYPTO_KEY_ELEMENT_SET_ID, \
         (uint8)CRYPTO_E_PARAM_HANDLE \
        );
        RetVal = E_NOT_OK;
    } else if (NULL_PTR == pKeyPtr) {
        (void)Det_ReportError\
        (\
         (uint16)CRYPTO_MODULE_ID, \
         (uint8)CRYPTO_INSTANCE_ID, \
         (uint8)CRYPTO_KEY_ELEMENT_SET_ID, \
         (uint8)CRYPTO_E_PARAM_POINTER \
        );
        RetVal = E_NOT_OK;
    } else if (0u == u32KeyLength) {
        (void)Det_ReportError\
        (\
         (uint16)CRYPTO_MODULE_ID, \
         (uint8)CRYPTO_INSTANCE_ID, \
         (uint8)CRYPTO_KEY_ELEMENT_SET_ID, \
         (uint8)CRYPTO_E_PARAM_VALUE \
        );
        RetVal = E_NOT_OK;
    } else {
#endif /* CRYPTO_DEV_ERROR_DETECT == STD_ON */
        RetVal = Crypto_GetKeyPtr(u32CryptoKeyId, &KeyPtr);

        if (E_OK == RetVal) {
            RetVal = Crypto_GetElementPtr(KeyPtr, u32KeyElementId, &KeyElementPtr);

            if (E_OK == RetVal && KeyElementPtr != NULL_PTR) {
                if (CRYPTO_WA_DENIED != KeyElementPtr->eCryptoKeyElementWriteAccess) {
                    if (((u32KeyLength < KeyElementPtr->u32CryptoKeyElementSize) &&
                         (FALSE == KeyElementPtr->bCryptoKeyElementAllowPartialAccess))
                         ||(u32KeyLength > KeyElementPtr->u32CryptoKeyElementSize)) {
                        RetVal = CRYPTO_E_KEY_SIZE_MISMATCH;
                    } else {
                        /* check pubkey */
                        if ((KeyPtr->CryptoKeyType < CRYPTO_KEYTYPE_RSA4096_PRI) &&
                            (KeyPtr->CryptoKeyType % 2 != 0)) {
                              mini_memcpy_s(KeyElementPtr->pCryptoElementContent,
                                            pKeyPtr, u32KeyLength);
                        } else {
#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
                        /*encrty keyelement*/
                        arch_clean_cache_range(pKeyPtr, u32KeyLength);
                        arch_invalidate_cache_range(KeyElementPtr->pCryptoElementContent,
                                                    u32KeyLength);
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */
                        Hsm_host_encrypt_key(pKeyPtr, u32KeyLength,
                                             CRYPTO_KEY_ELEMENT_ENC_KEY_ID,
                                             KeyElementPtr->pCryptoElementContent,
                                             CRYPTO_PROCESSING_SYNC);
                        }

                        Crypto_Key_UpdateKeyWriteSize(KeyElementPtr, u32KeyLength);

                        /*update key to storebuff for Fls sync*/
                        if (TRUE == KeyElementPtr->bCryptoKeyElementPersist) {
                            RetVal = Crypto_GetElementBuffInBlock(KeyPtr->u32CryptoKeyId,
                                                                  u32KeyElementId,
                                                                  CRYPTO_KEYTYPE_ELEMENT_RAW,
                                                                  &(pStoreCryptoElementContent),
                                                                  KeyElementPtr->u32CryptoKeyElementSize,
                                                                  CRYPTO_KEY_BLOCK_BUFF_FOR_STORE, TRUE);
                            /*update block store buff*/
                            if(RetVal == E_OK){
                                Crypto_Key_UpdateKeyElementStoreBuff(KeyElementPtr->pCryptoElementContent,
                                                                     pStoreCryptoElementContent, u32KeyLength);
                            }
                        }

                        /*set cryptokeyhsmkeytype*/
                        KeyPtr->CryptoHSMKeyType = CMD_KEY_EXTERNAL_CIPHERTEXT;

                        /*only pke key need parse*/
                        if((KeyPtr->CryptoKeyType & CRYPTO_KEYTYPE_PKE_MASK) != 0){
                            /*parse keyelement and encrypt pri key, write in blockbuff*/
                            RetVal = Crypto_InstallKey(KeyPtr, KeyElementPtr,
                                                       pKeyPtr, u32KeyLength);
                        }

                        KeyPtr->bCryptoKeyValid = FALSE;
                    }
                } else {
                    RetVal = CRYPTO_E_KEY_WRITE_FAIL;
                }
            }
        }

#if (CRYPTO_DEV_ERROR_DETECT == STD_ON)
    }

#endif /* CRYPTO_DEV_ERROR_DETECT == STD_ON */

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_KeySetValid
(
    VAR(uint32, AUTOMATIC) u32CryptoKeyId
)
{
    Std_ReturnType RetVal;
    Crypto_KeyType *KeyPtr;

#if (CRYPTO_DEV_ERROR_DETECT == STD_ON)

    if (CRYPTO_DRIVER_UNINIT == Crypto_gDriverState) {
        (void)Det_ReportError\
        (\
         (uint16)CRYPTO_MODULE_ID, \
         (uint8)CRYPTO_INSTANCE_ID, \
         (uint8)CRYPTO_KEY_SET_VALID_ID, \
         (uint8)CRYPTO_E_UNINIT \
        );
        RetVal = E_NOT_OK;
    } else if (u32CryptoKeyId > CRYPTO_MAX_KEY_ID) {    /*From 0 to */
        (void)Det_ReportError\
        (\
         (uint16)CRYPTO_MODULE_ID, \
         (uint8)CRYPTO_INSTANCE_ID, \
         (uint8)CRYPTO_KEY_SET_VALID_ID, \
         (uint8)CRYPTO_E_PARAM_HANDLE \
        );
        RetVal = E_NOT_OK;
    } else {
#endif /* CRYPTO_DEV_ERROR_DETECT == STD_ON */

        RetVal = Crypto_GetKeyPtr(u32CryptoKeyId, &KeyPtr);

        if (E_OK == RetVal) {
            KeyPtr->bCryptoKeyValid = TRUE;
        }
#if (CRYPTO_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* CRYPTO_DEV_ERROR_DETECT == STD_ON */

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_KeyElementGet
(
    VAR(uint32, AUTOMATIC) u32CryptoKeyId,
    VAR(uint32, AUTOMATIC) u32KeyElementId,
    P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pResultPtr,
    P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pResultLengthPtr
)
{
    Std_ReturnType RetVal;
    Crypto_KeyType *KeyPtr;
    Crypto_KeyElementType *KeyElementPtr = NULL_PTR;
    uint32 i = 0x0UL;
#if (CRYPTO_DEV_ERROR_DETECT == STD_ON)

    if (CRYPTO_DRIVER_UNINIT == Crypto_gDriverState) {
        (void)Det_ReportError\
        (\
         (uint16)CRYPTO_MODULE_ID, \
         (uint8)CRYPTO_INSTANCE_ID, \
         (uint8)CRYPTO_KEY_ELEMENT_GET_ID, \
         (uint8)CRYPTO_E_UNINIT \
        );
        RetVal = E_NOT_OK;
    } else if (u32CryptoKeyId > CRYPTO_MAX_KEY_ID) {    /*From 0 to */
        (void)Det_ReportError\
        (\
         (uint16)CRYPTO_MODULE_ID, \
         (uint8)CRYPTO_INSTANCE_ID, \
         (uint8)CRYPTO_KEY_ELEMENT_GET_ID, \
         (uint8)CRYPTO_E_PARAM_HANDLE \
        );
        RetVal = E_NOT_OK;
    } else if (u32KeyElementId > CRYPTO_MAX_KEY_ELEMENT_ID) {
        (void)Det_ReportError\
        (\
         (uint16)CRYPTO_MODULE_ID, \
         (uint8)CRYPTO_INSTANCE_ID, \
         (uint8)CRYPTO_KEY_ELEMENT_GET_ID, \
         (uint8)CRYPTO_E_PARAM_HANDLE \
        );
        RetVal = E_NOT_OK;
    } else if (NULL_PTR == pResultPtr) {
        (void)Det_ReportError\
        (\
         (uint16)CRYPTO_MODULE_ID, \
         (uint8)CRYPTO_INSTANCE_ID, \
         (uint8)CRYPTO_KEY_ELEMENT_GET_ID, \
         (uint8)CRYPTO_E_PARAM_POINTER \
        );
        RetVal = E_NOT_OK;
    } else if (NULL_PTR == pResultLengthPtr) {
        (void)Det_ReportError\
        (\
         (uint16)CRYPTO_MODULE_ID, \
         (uint8)CRYPTO_INSTANCE_ID, \
         (uint8)CRYPTO_KEY_ELEMENT_GET_ID, \
         (uint8)CRYPTO_E_PARAM_POINTER \
        );
        RetVal = E_NOT_OK;
    } else if (0u == *pResultLengthPtr) {
        (void)Det_ReportError\
        (\
         (uint16)CRYPTO_MODULE_ID, \
         (uint8)CRYPTO_INSTANCE_ID, \
         (uint8)CRYPTO_KEY_ELEMENT_GET_ID, \
         (uint8)CRYPTO_E_PARAM_VALUE \
        );
        RetVal = E_NOT_OK;
    } else {
#endif /* CRYPTO_DEV_ERROR_DETECT == STD_ON */

        RetVal = Crypto_GetKeyPtr(u32CryptoKeyId, &KeyPtr);

        if (E_OK == RetVal) {
            RetVal = Crypto_GetElementPtr(KeyPtr, u32KeyElementId,
                                          &KeyElementPtr);
            if (E_OK == RetVal && KeyElementPtr != NULL_PTR) {
                if (CRYPTO_RA_DENIED ==
                    KeyElementPtr->eCryptoKeyElementReadAccess) {
                    RetVal = CRYPTO_E_KEY_READ_FAIL;
                } else {
                    if (*pResultLengthPtr <
                        KeyElementPtr->u32CryptoElementWritedSize) {
                        if (TRUE == KeyElementPtr->
                            bCryptoKeyElementAllowPartialAccess) {
                            while (i < *pResultLengthPtr) {
                                pResultPtr[i] = KeyElementPtr->
                                                pCryptoElementContent[i];
                                i++;
                            }

                        } else {
                                RetVal = CRYPTO_E_SMALL_BUFFER;
                        }
                    } else {
                        while (i < KeyElementPtr->u32CryptoElementWritedSize) {
                            pResultPtr[i] = KeyElementPtr->
                                            pCryptoElementContent[i];
                            i++;
                        }
                        *pResultLengthPtr = KeyElementPtr->
                                            u32CryptoElementWritedSize;
                    }
                }
            }
        }

        if (CRYPTO_E_KEY_NOT_AVAILABLE == RetVal) {
            (void)Det_ReportRuntimeError\
            (\
             (uint16)CRYPTO_MODULE_ID, \
             (uint8)CRYPTO_INSTANCE_ID, \
             (uint8)CRYPTO_KEY_ELEMENT_GET_ID, \
             (uint8)CRYPTO_E_RE_KEY_NOT_AVAILABLE \
            );
        } else if (CRYPTO_E_KEY_READ_FAIL == RetVal) {
            (void)Det_ReportRuntimeError\
            (\
             (uint16)CRYPTO_MODULE_ID, \
             (uint8)CRYPTO_INSTANCE_ID, \
             (uint8)CRYPTO_KEY_ELEMENT_GET_ID, \
             (uint8)CRYPTO_E_RE_KEY_READ_FAIL \
            );
        }

#if (CRYPTO_DEV_ERROR_DETECT == STD_ON)
    }

#endif /* CRYPTO_DEV_ERROR_DETECT == STD_ON */
    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_KeyElementCopy
(
    VAR(uint32, AUTOMATIC) u32CryptoKeyId,
    VAR(uint32, AUTOMATIC) u32KeyElementId,
    VAR(uint32, AUTOMATIC) u32TargetCryptoKeyId,
    VAR(uint32, AUTOMATIC) u32TargetKeyElementId
)
{
    Std_ReturnType RetVal;
    Crypto_KeyType *KeyPtr;
    Crypto_KeyElementType *sKeyElementPtr = NULL_PTR;
    Crypto_KeyElementType *dKeyElementPtr = NULL_PTR;
    uint32 i = 0x0UL;

#if (CRYPTO_DEV_ERROR_DETECT == STD_ON)

    if (CRYPTO_DRIVER_UNINIT == Crypto_gDriverState) {
        (void)Det_ReportError\
        (\
         (uint16)CRYPTO_MODULE_ID, \
         (uint8)CRYPTO_INSTANCE_ID, \
         (uint8)CRYPTO_KEY_ELEMENT_COPY_ID, \
         (uint8)CRYPTO_E_UNINIT \
        );
        RetVal = E_NOT_OK;
    } else if (u32CryptoKeyId > CRYPTO_MAX_KEY_ID) {    /*From 0 to */
        (void)Det_ReportError\
        (\
         (uint16)CRYPTO_MODULE_ID, \
         (uint8)CRYPTO_INSTANCE_ID, \
         (uint8)CRYPTO_KEY_ELEMENT_COPY_ID, \
         (uint8)CRYPTO_E_PARAM_HANDLE \
        );
        RetVal = E_NOT_OK;
    } else if (u32TargetCryptoKeyId > CRYPTO_MAX_KEY_ID) {    /*From 0 to */
        (void)Det_ReportError\
        (\
         (uint16)CRYPTO_MODULE_ID, \
         (uint8)CRYPTO_INSTANCE_ID, \
         (uint8)CRYPTO_KEY_ELEMENT_COPY_ID, \
         (uint8)CRYPTO_E_PARAM_HANDLE \
        );
        RetVal = E_NOT_OK;
    } else if (u32KeyElementId > CRYPTO_MAX_KEY_ELEMENT_ID) {
        (void)Det_ReportError\
        (\
         (uint16)CRYPTO_MODULE_ID, \
         (uint8)CRYPTO_INSTANCE_ID, \
         (uint8)CRYPTO_KEY_ELEMENT_COPY_ID, \
         (uint8)CRYPTO_E_PARAM_HANDLE \
        );
        RetVal = E_NOT_OK;
    } else if (u32TargetKeyElementId > CRYPTO_MAX_KEY_ELEMENT_ID) {
        (void)Det_ReportError\
        (\
         (uint16)CRYPTO_MODULE_ID, \
         (uint8)CRYPTO_INSTANCE_ID, \
         (uint8)CRYPTO_KEY_ELEMENT_COPY_ID, \
         (uint8)CRYPTO_E_PARAM_HANDLE \
        );
        RetVal = E_NOT_OK;
    } else {
#endif /* CRYPTO_DEV_ERROR_DETECT == STD_ON */

        do {
            RetVal = Crypto_GetKeyPtr(u32CryptoKeyId, &KeyPtr);

            if (E_OK == RetVal) {
                RetVal = Crypto_GetElementPtr(KeyPtr, u32KeyElementId,
                                              &sKeyElementPtr);
                if (E_OK == RetVal && sKeyElementPtr != NULL_PTR) {
                    if (CRYPTO_RA_DENIED ==
                        sKeyElementPtr->eCryptoKeyElementReadAccess) {
                        RetVal = CRYPTO_E_KEY_READ_FAIL;
                    }
                }
            }

            if (RetVal != E_OK) {
                break;
            }

            RetVal = Crypto_GetKeyPtr(u32TargetCryptoKeyId, &KeyPtr);

            if (E_OK == RetVal) {
                RetVal = Crypto_GetElementPtr(KeyPtr, u32TargetKeyElementId,
                                              &dKeyElementPtr);
                if (E_OK == RetVal && dKeyElementPtr != NULL_PTR) {
                    if (CRYPTO_WA_DENIED ==
                        dKeyElementPtr->eCryptoKeyElementWriteAccess) {
                        RetVal = CRYPTO_E_KEY_WRITE_FAIL;
                    }
                }
            }
        } while(0);

        if ((E_OK == RetVal) && (sKeyElementPtr != NULL_PTR) &&
            (dKeyElementPtr != NULL_PTR)) {
            if (sKeyElementPtr->u32CryptoKeyElementSize !=
                dKeyElementPtr->u32CryptoKeyElementSize) {
                RetVal = CRYPTO_E_KEY_SIZE_MISMATCH;
            } else {
                while (i < sKeyElementPtr->u32CryptoElementWritedSize) {
                        dKeyElementPtr->pCryptoElementContent[i] =
                        sKeyElementPtr->pCryptoElementContent[i];
                        i++;
                }

                Crypto_Key_UpdateKeyWriteSize(dKeyElementPtr, i);
            }
        }

#if (CRYPTO_DEV_ERROR_DETECT == STD_ON)
    }

#endif /* CRYPTO_DEV_ERROR_DETECT == STD_ON */

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_KeyCopy
(
    VAR(uint32, AUTOMATIC) u32CryptoKeyId,
    VAR(uint32, AUTOMATIC) u32TargetCryptoKeyId
)
{
    Std_ReturnType RetVal;
    Crypto_KeyType *sKeyPtr;
    uint32 i = 0x0UL;
    uint32 ElementNum;
    uint32 ElementGlobalIndex;
    uint32 TempElementId;

#if (CRYPTO_DEV_ERROR_DETECT == STD_ON)

    if (CRYPTO_DRIVER_UNINIT == Crypto_gDriverState) {
        (void)Det_ReportError\
        (\
         (uint16)CRYPTO_MODULE_ID, \
         (uint8)CRYPTO_INSTANCE_ID, \
         (uint8)CRYPTO_KEY_COPY_ID, \
         (uint8)CRYPTO_E_UNINIT \
        );
        RetVal = E_NOT_OK;
    } else if (u32CryptoKeyId > CRYPTO_MAX_KEY_ID) {/*From 0 to */
        (void)Det_ReportError\
        (\
         (uint16)CRYPTO_MODULE_ID, \
         (uint8)CRYPTO_INSTANCE_ID, \
         (uint8)CRYPTO_KEY_COPY_ID, \
         (uint8)CRYPTO_E_PARAM_HANDLE \
        );
        RetVal = E_NOT_OK;
    } else if (u32TargetCryptoKeyId > CRYPTO_MAX_KEY_ID) {/*From 0 to */
        (void)Det_ReportError\
        (\
         (uint16)CRYPTO_MODULE_ID, \
         (uint8)CRYPTO_INSTANCE_ID, \
         (uint8)CRYPTO_KEY_COPY_ID, \
         (uint8)CRYPTO_E_PARAM_HANDLE \
        );
        RetVal = E_NOT_OK;
    } else {
#endif /* CRYPTO_DEV_ERROR_DETECT == STD_ON */

        RetVal = Crypto_GetKeyPtr(u32CryptoKeyId, &sKeyPtr);

        if (E_OK == RetVal) {
            ElementNum = sKeyPtr->u32ElementsNum;

            while (i < ElementNum) {
                ElementGlobalIndex = sKeyPtr->u32CryptoKeyElements[i];
                TempElementId = aElementList[ElementGlobalIndex]->
                                u32CryptoKeyElementId;
                RetVal = Crypto_KeyElementCopy(u32CryptoKeyId, TempElementId,
                                               u32TargetCryptoKeyId,
                                               TempElementId);
                if (E_OK != RetVal) {
                    break;
                }

                i++;
            }
        }

#if (CRYPTO_DEV_ERROR_DETECT == STD_ON)
    }

#endif /* CRYPTO_DEV_ERROR_DETECT == STD_ON */
    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_KeyElementIdsGet
(
    VAR(uint32, AUTOMATIC) u32CryptoKeyId,
    P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pKeyElementIdsPtr,
    P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pKeyElementIdsLengthPtr
)
{
    Std_ReturnType RetVal;
    Crypto_KeyType *KeyPtr;
    uint32 i = 0x0UL;

#if (CRYPTO_DEV_ERROR_DETECT == STD_ON)

    if (CRYPTO_DRIVER_UNINIT == Crypto_gDriverState) {
        (void)Det_ReportError\
        (\
         (uint16)CRYPTO_MODULE_ID, \
         (uint8)CRYPTO_INSTANCE_ID, \
         (uint8)CRYPTO_KEY_ELEMENT_IDS_GET_ID, \
         (uint8)CRYPTO_E_UNINIT \
        );
        RetVal = E_NOT_OK;
    } else if (u32CryptoKeyId > CRYPTO_MAX_KEY_ID) {    /*From 0 to */
        (void)Det_ReportError\
        (\
         (uint16)CRYPTO_MODULE_ID, \
         (uint8)CRYPTO_INSTANCE_ID, \
         (uint8)CRYPTO_KEY_ELEMENT_IDS_GET_ID, \
         (uint8)CRYPTO_E_PARAM_HANDLE \
        );
        RetVal = E_NOT_OK;
    } else {
#endif /* CRYPTO_DEV_ERROR_DETECT == STD_ON */

        if ((NULL_PTR == pKeyElementIdsPtr) ||
            (NULL_PTR == pKeyElementIdsLengthPtr)) {
            RetVal = E_NOT_OK;
        } else {
            RetVal = Crypto_GetKeyPtr(u32CryptoKeyId, &KeyPtr);

            if (E_OK == RetVal) {
                if (KeyPtr->u32ElementsNum > *pKeyElementIdsLengthPtr) {
                    RetVal = CRYPTO_E_SMALL_BUFFER;
                } else {
                    while (i < KeyPtr->u32ElementsNum) {
                        pKeyElementIdsPtr[i] =
                        aElementList[KeyPtr->u32CryptoKeyElements[i]]->
                        u32CryptoKeyElementId;
                        i++;
                    }
                    *pKeyElementIdsLengthPtr = KeyPtr->u32ElementsNum;
                }
            }
        }

#if (CRYPTO_DEV_ERROR_DETECT == STD_ON)
    }

#endif /* CRYPTO_DEV_ERROR_DETECT == STD_ON */
    return RetVal;
}

/*PRQA S 2755 2*/
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_KeyGenerate
(
    VAR(uint32, AUTOMATIC) u32CryptoKeyId
)
{
    Std_ReturnType RetVal;
    Crypto_KeyType *KeyPtr;
    Crypto_KeyType *KeyPairPtr;
    Crypto_KeyElementType *KeyElementPtr = NULL_PTR;
    Crypto_KeyElementType *KeyPairElementPtr = NULL_PTR;
    uint32 Modulus_Size;
    uint8 *pStoreCryptoElementContent;

#if (CRYPTO_DEV_ERROR_DETECT == STD_ON)

    if (CRYPTO_DRIVER_UNINIT == Crypto_gDriverState) {
        (void)Det_ReportError\
        (\
         (uint16)CRYPTO_MODULE_ID, \
         (uint8)CRYPTO_INSTANCE_ID, \
         (uint8)CRYPTO_KEY_GENERATE_ID, \
         (uint8)CRYPTO_E_UNINIT \
        );
        RetVal = E_NOT_OK;
    } else if (u32CryptoKeyId > CRYPTO_MAX_KEY_ID) {    /*From 0 to */
        (void)Det_ReportError\
        (\
         (uint16)CRYPTO_MODULE_ID, \
         (uint8)CRYPTO_INSTANCE_ID, \
         (uint8)CRYPTO_KEY_GENERATE_ID, \
         (uint8)CRYPTO_E_PARAM_HANDLE \
        );
        RetVal = E_NOT_OK;
    } else {
#endif /* CRYPTO_DEV_ERROR_DETECT == STD_ON */

        RetVal = Crypto_GetKeyPtr(u32CryptoKeyId, &KeyPtr);

        if (E_OK == RetVal) {
            RetVal = Crypto_GetElementPtr(KeyPtr, CRYPTO_KEY_MATERIAL_COMMON_ID,
                                          &KeyElementPtr);

            if (E_OK == RetVal && NULL_PTR != KeyElementPtr) {

                if((KeyPtr->CryptoKeyType >> 8)  != 0){
                    switch (KeyPtr->CryptoKeyType)
                    {
                        case CRYPTO_KEYTYPE_SKE_KEY_128:
                            KeyElementPtr->u32CryptoElementWritedSize = 16;
                            break;
                        case CRYPTO_KEYTYPE_SKE_KEY_192:
                            KeyElementPtr->u32CryptoElementWritedSize = 24;
                            break;
                        case CRYPTO_KEYTYPE_SKE_KEY_256:
                            KeyElementPtr->u32CryptoElementWritedSize = 32;
                            break;
                        default:
                            KeyElementPtr->u32CryptoElementWritedSize = 32;
                            break;
                    }

                    RetVal = Hsm_host_GenerateKey(CRYPTO_KEY_ELEMENT_ENC_KEY_ID,
                                                  KeyElementPtr->pCryptoElementContent,
                                                  KeyElementPtr->u32CryptoElementWritedSize,
                                                  CRYPTO_PROCESSING_SYNC);
#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
                    arch_invalidate_cache_range(KeyElementPtr->pCryptoElementContent,
                                                KeyElementPtr->u32CryptoElementWritedSize);
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */
                    Crypto_Key_UpdateKeyWriteSize(KeyElementPtr,
                                                  KeyElementPtr->u32CryptoElementWritedSize);

                /*update key to storebuff for Fls sync*/
                if (TRUE == KeyElementPtr->bCryptoKeyElementPersist) {
                    RetVal = Crypto_GetElementBuffInBlock(KeyPtr->u32CryptoKeyId,
                                                          KeyElementPtr->u32CryptoKeyElementId,
                                                          CRYPTO_KEYTYPE_ELEMENT_RAW,
                                                          &(pStoreCryptoElementContent),
                                                          KeyElementPtr->u32CryptoKeyElementSize,
                                                          CRYPTO_KEY_BLOCK_BUFF_FOR_STORE, TRUE);
                    /*update block store buff*/
                    if(RetVal == E_OK){
                        Crypto_Key_UpdateKeyElementStoreBuff(KeyElementPtr->pCryptoElementContent,
                                                             pStoreCryptoElementContent,
                                                             KeyElementPtr->u32CryptoElementWritedSize);
                    }
                }
            } else {
                /*only support raw type key generate*/
                if(KeyElementPtr->eCryptoKeyElementFormatType != CRYPTO_KE_FORMAT_BIN_OCTET){
                    return E_NOT_OK;
                }
                if (KeyPtr->CryptoKeyType >= CRYPTO_KEYTYPE_RSA1024_PUB &&
                    KeyPtr->CryptoKeyType <= CRYPTO_KEYTYPE_RSA4096_PRI){

                    switch (KeyPtr->CryptoKeyType)
                    {
                        case CRYPTO_KEYTYPE_RSA1024_PRI:
                            Modulus_Size = 128;
                            break;
                        case CRYPTO_KEYTYPE_RSA2048_PRI:
                            Modulus_Size = 256;
                            break;
                        case CRYPTO_KEYTYPE_RSA3072_PRI:
                            Modulus_Size = 384;
                            break;
                        case CRYPTO_KEYTYPE_RSA4096_PRI:
                            Modulus_Size = 512;
                            break;
                        default:
                            return E_NOT_OK;
                    }
                    /*gen pri key*/
                    RetVal = Hsm_Host_rsa_generatekey(Modulus_Size,
                                                      CMD_KEY_EXTERNAL_PLAINTEXT,
                                                      0, KeyElementPtr->pCryptoElementContent,
                                                      NULL_PTR, CRYPTO_PROCESSING_SYNC);
#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
                    arch_invalidate_cache_range(KeyElementPtr->pCryptoElementContent,
                                                Modulus_Size*3);
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */
                    Crypto_Key_UpdateKeyWriteSize(KeyElementPtr, Modulus_Size*3);

                    /*parse keyelement and encrypt pri key, write in blockbuff*/
                    Crypto_InstallKey(KeyPtr, KeyElementPtr,
                                      KeyElementPtr->pCryptoElementContent,
                                      Modulus_Size*3);

                    /*update pub key*/
                    RetVal = Crypto_GetKeyPtr(KeyPtr->u32CryptoKeyPairId, &KeyPairPtr);

                    if (E_OK == RetVal) {
                        RetVal = Crypto_GetElementPtr(KeyPairPtr,
                                                      CRYPTO_KEY_MATERIAL_COMMON_ID,
                                                      &KeyPairElementPtr);
                        if (E_OK == RetVal && NULL_PTR != KeyPairElementPtr) {
                            if(KeyPairElementPtr->eCryptoKeyElementFormatType !=
                               CRYPTO_KE_FORMAT_BIN_OCTET){
                                return E_NOT_OK;
                            }
                            /*copy n e buff*/
                            mini_memcpy_s(KeyPairElementPtr->pCryptoElementContent,
                                          KeyElementPtr->pCryptoElementContent,
                                          Modulus_Size*2);

                            Crypto_Key_UpdateKeyWriteSize(KeyPairElementPtr,
                                                          Modulus_Size*2);
                            /*install key*/
                            Crypto_InstallKey(KeyPairPtr, KeyPairElementPtr,
                                              KeyPairElementPtr->pCryptoElementContent,
                                              Modulus_Size*2);
                        }

                        /*update key to storebuff for Fls sync*/
                        if (TRUE == KeyPairElementPtr->bCryptoKeyElementPersist) {
                            RetVal = Crypto_GetElementBuffInBlock(KeyPairPtr->u32CryptoKeyId,
                                                                  KeyPairElementPtr->u32CryptoKeyElementId,
                                                                  CRYPTO_KEYTYPE_ELEMENT_RAW,
                                                                  &(pStoreCryptoElementContent),
                                                                  KeyPairElementPtr->u32CryptoKeyElementSize,
                                                                  CRYPTO_KEY_BLOCK_BUFF_FOR_STORE, TRUE);
                            /*update block store buff*/
                            if(RetVal == E_OK){
                                Crypto_Key_UpdateKeyElementStoreBuff(KeyPairElementPtr->pCryptoElementContent,
                                                                     pStoreCryptoElementContent,
                                                                     KeyPairElementPtr->u32CryptoElementWritedSize);
                            }
                        }
                    }

                    /*enc key element*/
                    Hsm_host_encrypt_key(KeyElementPtr->pCryptoElementContent,
                                         Modulus_Size*3, CRYPTO_KEY_ELEMENT_ENC_KEY_ID,
                                         KeyElementPtr->pCryptoElementContent,
                                         CRYPTO_PROCESSING_SYNC);
#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
                    arch_invalidate_cache_range(KeyElementPtr->pCryptoElementContent,
                                                Modulus_Size*3);
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */
                    /*update key to storebuff for Fls sync*/
                    if (TRUE == KeyElementPtr->bCryptoKeyElementPersist) {
                        RetVal = Crypto_GetElementBuffInBlock(KeyPtr->u32CryptoKeyId,
                                                              KeyElementPtr->u32CryptoKeyElementId,
                                                              CRYPTO_KEYTYPE_ELEMENT_RAW,
                                                              &(pStoreCryptoElementContent),
                                                              KeyElementPtr->u32CryptoKeyElementSize,
                                                              CRYPTO_KEY_BLOCK_BUFF_FOR_STORE, TRUE);
                        /*update block store buff*/
                        if(RetVal == E_OK){
                            Crypto_Key_UpdateKeyElementStoreBuff(KeyElementPtr->pCryptoElementContent,
                                                                 pStoreCryptoElementContent,
                                                                 KeyElementPtr->u32CryptoElementWritedSize);
                        }
                    }
                } else if (KeyPtr->CryptoKeyType >= CRYPTO_KEYTYPE_P192_PUB &&
                            KeyPtr->CryptoKeyType <= CRYPTO_KEYTYPE_SM2P256_PRI) {
                    uint8 curve_id;
                    uint32 key_len;
                    switch (KeyPtr->CryptoKeyType)
                    {
                        case CRYPTO_KEYTYPE_P192_PRI:
                            curve_id = 0;
                            key_len = 24;
                            break;
                        case CRYPTO_KEYTYPE_P224_PRI:
                            curve_id = 1;
                            key_len = 28;
                            break;
                        case CRYPTO_KEYTYPE_P256_PRI:
                        case CRYPTO_KEYTYPE_SM2P256_PRI:
                            curve_id = 2;
                            key_len = 32;
                            break;
                        case CRYPTO_KEYTYPE_P384_PRI:
                            curve_id = 3;
                            key_len = 48;
                            break;
                        case CRYPTO_KEYTYPE_P521_PRI:
                            curve_id = 4;
                            key_len = 66;
                            break;
                        default:
                            return E_NOT_OK;
                    }

                    RetVal = Crypto_GetKeyPtr(KeyPtr->u32CryptoKeyPairId, &KeyPairPtr);
                    if (RetVal != E_OK)
                        return RetVal;

                    RetVal = Crypto_GetElementPtr(KeyPairPtr,
                                                  CRYPTO_KEY_MATERIAL_COMMON_ID,
                                                  &KeyPairElementPtr);
                    if (RetVal != E_OK || (KeyPairElementPtr == NULL))
                        return RetVal;

                    Crypto_Key_UpdateKeyWriteSize(KeyElementPtr, key_len);
                    Crypto_Key_UpdateKeyWriteSize(KeyPairElementPtr, key_len * 2);
                    if (KeyPtr->CryptoKeyType == CRYPTO_KEYTYPE_SM2P256_PRI)
                    {
                        RetVal = Hsm_Host_sm2_generatekey(KeyElementPtr->pCryptoElementContent,
                                    KeyPairElementPtr->pCryptoElementContent,
                                    CMD_KEY_EXTERNAL_CIPHERTEXT,
                                    CRYPTO_KEY_ELEMENT_ENC_KEY_ID, NULL_PTR, CRYPTO_PROCESSING_SYNC);
                        if (RetVal != E_OK)
                           return RetVal;
                    }
                    else
                    {
                        /*gen key*/
                        RetVal = Hsm_Host_ecc_generatekey(curve_id,
                                    KeyElementPtr->pCryptoElementContent,
                                    KeyPairElementPtr->pCryptoElementContent,
                                    CMD_KEY_EXTERNAL_CIPHERTEXT,
                                    CRYPTO_KEY_ELEMENT_ENC_KEY_ID, NULL_PTR,
                                    CRYPTO_PROCESSING_SYNC);
                        if (RetVal != E_OK)
                           return RetVal;
                    }
#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
                    arch_invalidate_cache_range(KeyElementPtr->pCryptoElementContent, key_len);
                    arch_invalidate_cache_range(KeyPairElementPtr->pCryptoElementContent, key_len * 2);
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */
                    /*update key to storebuff for Fls sync*/
                    if (TRUE == KeyElementPtr->bCryptoKeyElementPersist) {
                        RetVal = Crypto_GetElementBuffInBlock(KeyPtr->u32CryptoKeyId,
                                                              KeyElementPtr->u32CryptoKeyElementId,
                                                              CRYPTO_KEYTYPE_ELEMENT_RAW, &(pStoreCryptoElementContent),
                                                              KeyElementPtr->u32CryptoKeyElementSize,
                                                              CRYPTO_KEY_BLOCK_BUFF_FOR_STORE, TRUE);
                        /*update block store buff*/
                        if(RetVal == E_OK){
                            Crypto_Key_UpdateKeyElementStoreBuff(KeyElementPtr->pCryptoElementContent,
                                                                 pStoreCryptoElementContent,
                                                                 KeyElementPtr->u32CryptoElementWritedSize);
                        }
                    }
                    if (TRUE == KeyPairElementPtr->bCryptoKeyElementPersist) {
                        RetVal = Crypto_GetElementBuffInBlock(KeyPairPtr->u32CryptoKeyId,
                                                              KeyPairElementPtr->u32CryptoKeyElementId,
                                                              CRYPTO_KEYTYPE_ELEMENT_RAW,
                                                              &(pStoreCryptoElementContent),
                                                              KeyPairElementPtr->u32CryptoKeyElementSize,
                                                              CRYPTO_KEY_BLOCK_BUFF_FOR_STORE, TRUE);
                        /*update block store buff*/
                        if(RetVal == E_OK){
                            Crypto_Key_UpdateKeyElementStoreBuff(KeyPairElementPtr->pCryptoElementContent,
                                                                 pStoreCryptoElementContent,
                                                                 KeyPairElementPtr->u32CryptoElementWritedSize);
                        }
                    }
                }
            }
            /*set cryptokeyhsmkeytype*/
            KeyPtr->CryptoHSMKeyType = CMD_KEY_EXTERNAL_CIPHERTEXT;
        }
    }

#if (CRYPTO_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* CRYPTO_DEV_ERROR_DETECT == STD_ON */

    return RetVal;
}

#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#ifdef __cplusplus
}
#endif
