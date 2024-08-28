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
 * @file  Crypto_KeyManagement.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Crypto
 */

#ifndef CRYPTO_KEY_MANAGEMENT_H
#define CRYPTO_KEY_MANAGEMENT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Crypto_Types.h"

#define CRYPTO_KEY_MATERIAL_COMMON_ID   (0x01u)
#define CRYPTO_KEY_MATERIAL_ALT_ID      (0x07u)

#define CRYPTO_KEY_PKCS1_PRIKEY_ITEM_NUM 3 /*n e d*/
#define CRYPTO_KEY_PKCS1_PUBKEY_ITEM_NUM 2 /*n e */

/*key block storage in flash, size is defined by product, default from 3M*/
#define CRYPTO_KEY_BLOCK_STROAGE_ONFLASH_ADDR (CRYPTO_DRIVER_KEYSTORE_STARTADDR)
#define CRYPTO_KEY_BLOCK_STROAGE_FLASH_SECTOR_SIZE 0x1000U /*4K byte*/
#define CRYPTO_KEY_BLOCK_MAC_KEY_ID 4

#define CRYPTO_KEY_BLOCK_BUFF_LEN ROUNDUP((CRYPTO_DRIVER_KEYSTORE_SIZE),\
                                  CRYPTO_KEY_BLOCK_STROAGE_FLASH_SECTOR_SIZE)

typedef enum {
    CRYPTO_KEY_BLOCK_BUFF_FOR_JOB,
    CRYPTO_KEY_BLOCK_BUFF_FOR_STORE,
    CRYPTO_KEY_BLOCK_BUFF_TYPE_MAX
} Crypto_KeyBlockBuffType;

/*key block struct*/
/*
|------------head-----------|-----
| ------block magic 4byte-- |  |
| ------version 4byte------ |  |
| ------block size 4byte--- | cache align
| ------keyu num 4byte----- |  |
| ------keym num 4byte----- |  |
| ------   reserved   ----- |  |
|------------body-----------|-----
| ------key magic 4byte---- |  |
| ------cryptokeyid 4byte-- |  |
| ------keyelemid 4byte---- |  |
| ------key size 4byte----- | cache align
| ------key type 4byte----- |  |
| ------   reserved   ----- |  |
| -key value (keysize)byte- |------
| ------              ----- | cache align
| ------   reserved   ----- |------
| ------next key item------ |
| ------next key item------ |
|-------block end flag------|
|------------hmac-----------|
| ----hmac value 32byte---- |
|---------------------------|
*/
typedef struct crypto_keymanagement_keyblock_head{
    uint32 block_magic;
    uint32 version;
    uint32 block_size;
    uint32 key_current_num;
    uint32 key_max_item_num;
}crypto_keymanagement_keyblock_head_t;

typedef struct crypto_keymanagement_keyitem_head{
    uint32 key_magic;
    uint32 cryptokeyid;
    uint32 keyelementid;
    uint32 key_elem_size;
    uint32 key_write_size;
    uint32 key_type;
}crypto_keymanagement_keyitem_head_t;

/*key value 32 byte is default size, begin at key value buff, keyvalue size can > 32byte*/
typedef struct crypto_keymanagement_keyitem{
    crypto_keymanagement_keyitem_head_t keyitem_head;
    uint8 key_value[32];
}crypto_keymanagement_keyitem_t;

/**
 * @brief Get a pointer of key
 * @details Get a pointer of key
 * @param[in]   keyId
 * @param[out]   keyPtr
 * @return   E_OK/E_NOT_OK
*/
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_GetKeyPtr
(
    VAR(uint32, AUTOMATIC) keyId,
    P2VAR(Crypto_KeyType, AUTOMATIC, CRYPTO_APPL_DATA) *keyPtr
);

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
);

/**
 * @brief Get a pointer of element of key
 * @details Get a pointer of element of key
 * @param[in]   keyPtr
 * @param[in]   keyElementId
 * @param[out]  keyElementPtr
 * @return   E_OK/E_NOT_OK
*/
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_GetElementPtr
(
    P2VAR(Crypto_KeyType, AUTOMATIC, CRYPTO_APPL_DATA) keyPtr,
    VAR(uint32, AUTOMATIC) keyElementId,
    P2VAR(Crypto_KeyElementType, AUTOMATIC, CRYPTO_APPL_DATA) *keyElementPtr
);

/**
 * @brief Init Crypto_UsrCallOut_Read
 * @param[in]   Usr_Read
 * @return   E_OK/E_NOT_OK
*/
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_UsrCallOut_Read_Init
(
    Std_ReturnType (*Usr_Read)(uint8 *dst)
);

/**
 * @brief key manager initial
 * @details Initial key manager
 * @return none
*/
FUNC(void, CRYPTO_CODE) Crypto_KeyManagerInit
(
    void
);

/**
 * @brief Install a key to HSM
 * @return   E_OK/E_NOT_OK
*/
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_InstallKey
(
    Crypto_KeyType *KeyPtr,
    Crypto_KeyElementType *KeyElementPtr,
    const uint8 *pKeyContent,
    uint32 keyLength
);

#ifdef __cplusplus
}
#endif

#endif /* CRYPTO_KEYMANAGEMENT_H */
