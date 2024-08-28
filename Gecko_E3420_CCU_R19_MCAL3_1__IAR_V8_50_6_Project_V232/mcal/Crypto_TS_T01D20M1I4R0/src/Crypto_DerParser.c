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
 * @file  Crypto_DerParser.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Crypto
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Crypto_DerParser.h"
#include "mini_libc.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"

static void Crypto_Parse_GetRaw
(
    const uint8 *pKey,
    uint8 *output_buffer,
    uint32 len
)
{
    uint32 i;

    for (i = 0; i < len; i++) {
        output_buffer[i] = pKey[i];
    }
}
static uint8 Crypto_Parse_GetLen
(
    const uint8 **pKey,
    const uint8 *end,
    uint32 *len
)
{
    uint8 RetVal = E_OK;
    uint8 LengthLen;
    uint8 *temp = (uint8 *)len;
    uint32 i;

    if ((end - *pKey) <= 0) {
        return (CRYPTO_ERR_ASN1_OUT_OF_RANGE);
    }

    if (**pKey > 0x7fu) {
        /*long mode > 127  */
        LengthLen = *((*pKey)++) & 0x7fu;

        if (LengthLen > 4u) {
            return (CRYPTO_ERR_ASN1_OUT_OF_RANGE);
        }

        if ((end - *pKey) < LengthLen) {
            return (CRYPTO_ERR_ASN1_OUT_OF_RANGE);
        }

        for (i = 0x0u; i < LengthLen; i++) {
            temp[LengthLen - 1u - i] = *((*pKey)++);
        }
    } else {
        /*short mode <= 127*/
        *len = *((*pKey)++);
    }

    return (RetVal);
}

static uint8 Crypto_Parse_GetTag
(
    const uint8 **pKey,
    const uint8 *end,
    uint32 *len,
    uint8 TagNum
)
{
    uint8 RetVal;

    do {
        if ((end - *pKey) <= 0) {
            RetVal = CRYPTO_ERR_ASN1_OUT_OF_RANGE;
            break;
        }

        if (**pKey != TagNum) {
            RetVal = E_NOT_OK;
            break;
        }

        (*pKey)++;
        RetVal = Crypto_Parse_GetLen(pKey, end, len);
    } while (0);

    return RetVal;
}

Std_ReturnType Crypto_Parse_PKCS1_KEYMODULUSLEN
(
    const uint8 **pKey,
    const uint8 *end,
    uint8 keytype,
    uint32 *modulusLen
)
{
    Std_ReturnType RetVal = E_OK;
    uint32 len = 0x0UL;
    const uint8 *pKey_back;

    pKey_back = *pKey;
    do {
        /*parse head*/
        if (Crypto_Parse_GetTag(pKey, end, &len, CRYPTO_ASN1_CONSTRUCTED | CRYPTO_ASN1_SEQUENCE) != E_OK) {
            RetVal = E_NOT_OK;
            break;
        }

        if ((*pKey + len) != end) {
            RetVal = E_NOT_OK;
            break;
        }

        if(CRYPTO_ASN1_PKCS1_KEYTYPE_PRIKEY == keytype){
            /*get the version*/
            if (Crypto_Parse_GetTag(pKey, end, &len, CRYPTO_ASN1_INTEGER) != E_OK) {
                RetVal = E_NOT_OK;
                break;
            }

            if (**pKey != 0UL) {
                /*According to the [SWS_Crypto_00185],the version shall be '0'*/
                RetVal = E_NOT_OK;
                break;
            }

            *pKey += len;
        }

        /*get the N len*/
        if (Crypto_Parse_GetTag(pKey, end, &len, CRYPTO_ASN1_INTEGER) != E_OK) {
            RetVal = E_NOT_OK;
            break;
        }
        /*sign bit*/
        if (0U == (*pKey)[0] ) {
            *pKey += 1U;
            len--;
        }

        *modulusLen = len;
    } while (0);

    *pKey = pKey_back;
    return RetVal;
}
/**
    @brief: Get PKCS#1(RSA) public key

    RSAPublicKey ::= SEQUENCE {
        modulus           INTEGER,  -- n
        publicExponent    INTEGER   -- e
    }
*/
Std_ReturnType Crypto_Parse_PKCS1_PUBKEY
(
    const uint8 **pKey,
    const uint8 *end,
    RSAKey_Ext_Sdrv *rsa_key
)
{
    Std_ReturnType RetVal = E_OK;
    uint32 len = 0x0UL;
    const uint8 *pKey_back;

    pKey_back = *pKey;
    do {
        /*parse head*/
        if (Crypto_Parse_GetTag(pKey, end, &len, CRYPTO_ASN1_CONSTRUCTED | CRYPTO_ASN1_SEQUENCE) != E_OK) {
            RetVal = E_NOT_OK;
            break;
        }

        if ((*pKey + len) != end) {
            RetVal = E_NOT_OK;
            break;
        }

        /*get the N*/
        if (Crypto_Parse_GetTag(pKey, end, &len, CRYPTO_ASN1_INTEGER) != E_OK) {
            RetVal = E_NOT_OK;
            break;
        }

        /*sign bit*/
        if (0U == (*pKey)[0] ) {
            *pKey += 1U;
            len--;
        }

        rsa_key->keybuff_head.n_sz = len;
        rsa_key->keybuff_head.n = (uint8 *)rsa_key + ROUNDUP(sizeof(RSAKey_Head_Ext_Sdrv), CACHE_LINE);
        rsa_key->keybuff_head.e = rsa_key->keybuff_head.n + len;

        Crypto_Parse_GetRaw(*pKey, rsa_key->keybuff_head.n, len);
        *pKey += len;

        /*get the E*/
        if (Crypto_Parse_GetTag(pKey, end, &len, CRYPTO_ASN1_INTEGER) != E_OK) {
            RetVal = E_NOT_OK;
            break;
        }

        mini_memclr_s(rsa_key->keybuff_head.e, rsa_key->keybuff_head.n_sz - len);
        Crypto_Parse_GetRaw(*pKey, (rsa_key->keybuff_head.e + rsa_key->keybuff_head.n_sz - len), len);
        *pKey += len;

        if (*pKey != end) {
            RetVal = E_NOT_OK;
        }
    } while (0);

    *pKey = pKey_back;
    return RetVal;
}

/**
    @brief: Get PKCS#1(RSA) private key
RSAPrivateKey ::= SEQUENCE {
    version           Version,
    modulus           INTEGER,  -- n
    publicExponent    INTEGER,  -- e
    privateExponent   INTEGER,  -- d
    prime1            INTEGER,  -- p
    prime2            INTEGER,  -- q
    exponent1         INTEGER,  -- d mod (p-1)
    exponent2         INTEGER,  -- d mod (q-1)
    coefficient       INTEGER,  -- (inverse of q) mod p
    otherPrimeInfos   OtherPrimeInfos OPTIONAL
}
*/
Std_ReturnType Crypto_Parse_PKCS1_PRIKEY
(
    const uint8 **pKey,
    const uint8 *end,
    RSAKey_Ext_Sdrv *rsa_key
)
{
    Std_ReturnType RetVal = E_OK;
    uint32 len = 0x0UL;
    const uint8 *pKey_back;

    pKey_back = *pKey;
    do {
        if (Crypto_Parse_GetTag(pKey, end, &len, CRYPTO_ASN1_CONSTRUCTED | CRYPTO_ASN1_SEQUENCE) != E_OK) {
            RetVal = E_NOT_OK;
            break;
        }

        if ((*pKey + len) != end) {
            RetVal = E_NOT_OK;
            break;
        }

        /*get the version*/
        if (Crypto_Parse_GetTag(pKey, end, &len, CRYPTO_ASN1_INTEGER) != E_OK) {
            RetVal = E_NOT_OK;
            break;
        }

        if (**pKey != 0UL) {
            /*According to the [SWS_Crypto_00185],the version shall be '0'*/
            RetVal = E_NOT_OK;
            break;
        }

        *pKey += len;

        /*get the N*/
        if (Crypto_Parse_GetTag(pKey, end, &len, CRYPTO_ASN1_INTEGER) != E_OK) {
            RetVal = E_NOT_OK;
            break;
        }

        /*sign bit*/
        if (0U == (*pKey)[0] ) {
            *pKey += 1U;
            len--;
        }

        if (NULL == rsa_key) {
            RetVal = E_NOT_OK;
            break;
        }

        rsa_key->keybuff_head.n_sz = len;
        rsa_key->keybuff_head.n = (uint8 *)rsa_key + ROUNDUP(sizeof(RSAKey_Head_Ext_Sdrv), CACHE_LINE);
        rsa_key->keybuff_head.e = rsa_key->keybuff_head.n + len;
        rsa_key->keybuff_head.d = rsa_key->keybuff_head.e + len;

        Crypto_Parse_GetRaw(*pKey, rsa_key->keybuff_head.n, len);
        *pKey += len;

        /*get the E*/
        if (Crypto_Parse_GetTag(pKey, end, &len, CRYPTO_ASN1_INTEGER) != E_OK) {
            RetVal = E_NOT_OK;
            break;
        }

        /*sign bit*/
        if (0U == (*pKey)[0] ) {
            *pKey += 1U;
            len--;
        }
        /*e buff only update new e len buff, so must clean other buff*/
        mini_memclr_s(rsa_key->keybuff_head.e, rsa_key->keybuff_head.n_sz - len);
        Crypto_Parse_GetRaw(*pKey, (rsa_key->keybuff_head.e + rsa_key->keybuff_head.n_sz - len), len);
        *pKey += len;

        /*get the D*/
        if (Crypto_Parse_GetTag(pKey, end, &len, CRYPTO_ASN1_INTEGER) != E_OK) {
            RetVal = E_NOT_OK;
            break;
        }

        /*sign bit*/
        if (0U == (*pKey)[0] ) {
            *pKey += 1U;
            len--;
        }
        Crypto_Parse_GetRaw(*pKey, rsa_key->keybuff_head.d, len);
        *pKey += len;

        if (*pKey > end) {
            RetVal = E_NOT_OK;
        }
    } while (0);

    *pKey = pKey_back;
    return RetVal;
}

#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"
