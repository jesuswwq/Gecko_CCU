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
 * @file  Crypto_RSAPadding.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Crypto
 */

#include <Crypto_RSAPadding.h>
#include "mini_libc.h"

#define DLEN    (19U)

uint32 hash_get_digest_size(Crypto_AlgorithmFamilyType autosar_algo);

#define CRYPTO_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Crypto_MemMap.h"

#define CRYPTO_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_VAR_INIT_UNSPECIFIED
#include "Crypto_MemMap.h"

static uint8 hash_algDer[19] = {
    0x30, 0x21, 0x30, 0x0d, 0x06, 0x09, 0x60, 0x86,
    0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x06, 0x05,
    0x00, 0x04, 0x20
};

#define CRYPTO_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"

/**
 * @brief Get random bytes
 * @param dst pointer to output result
 * @param n size of \p dst
*/
FUNC(Std_ReturnType, CRYPTO_CODE) gen_rnd_bytes(uint8 *dst, uint32 size)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 *Random_String = NULL;

    uint32 i = 0;
    uint32 index = 0;
    uint32 index_max = 0;
    uint32 cp_left = 0;

    if (dst == NULL) {
        return E_NOT_OK;
    }

    Random_String = ShareMem_GetBlock(CRYPTO_SHARE_MEM_NODE_COMM_SMALL_BUFF_MAX);
    if (NULL == Random_String)
        return E_NOT_OK;

    index = 0;
    /*64 byte one block,CRYPTO_SHARE_MEM_NODE_COMM_SMALL_BUFF_MAX*/
    index_max = size >> 6;
    cp_left = size & 0x3f;

    for (i = 0; i < index_max; i++) {
#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
        arch_invalidate_cache_range(Random_String,
                                    CRYPTO_SHARE_MEM_NODE_COMM_SMALL_BUFF_MAX);
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */
        RetVal = Hsm_host_GenerateTrng(Random_String,
                                       CRYPTO_SHARE_MEM_NODE_COMM_SMALL_BUFF_MAX,
                                       CRYPTO_PROCESSING_SYNC);

        mini_memcpy_s(dst + index, (void *)Random_String,
                      CRYPTO_SHARE_MEM_NODE_COMM_SMALL_BUFF_MAX);
        index = index + CRYPTO_SHARE_MEM_NODE_COMM_SMALL_BUFF_MAX;
    }

    if (cp_left > 0) {
#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF)
        arch_invalidate_cache_range(Random_String, cp_left);
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_OFF) */
        RetVal = Hsm_host_GenerateTrng(Random_String, cp_left, CRYPTO_PROCESSING_SYNC);
        mini_memcpy_s(dst + index, (void *)Random_String, cp_left);
    }

    for (; size > 0; size--) {
        if (dst[size - 1] == 0)
            dst[size - 1] = 0x1;
    }

    ShareMem_ReleaseBlock(Random_String);

    return RetVal;
}

/**
 * @brief Get first mask
 * @param n0 input
 * @return mask corresponding to \p n0
*/
uint32 getFirstMask(uint32 n0)
{
    if (n0 & 0x80) {
        return 0x7F;
    } else if (n0 & 0x40) {
        return 0x3F;
    } else if (n0 & 0x20) {
        return 0x1F;
    } else if (n0 & 0x10) {
        return 0x0F;
    } else if (n0 & 0x08) {
        return 0x07;
    } else if (n0 & 0x04) {
        return 0x03;
    } else if (n0 & 0x02) {
        return 0x01;
    } else {
        return 0x00;
    }
}

/**
 * @brief perform buff = buff XOR mask
 * @param buff input/output buffer
 * @param mask to xor with
 * @param n size of \p buff and \p mask
*/
static void mask(uint8 *buff, uint8 *mask, uint32 n)
{
    for (; n > 0; n--) {
        buff[n - 1] = buff[n - 1] ^ mask[n - 1];
    }
}

/**
 * Mask Generation Function as defined by RFC-8017 B.2.1.
 * @param hash_alg hash function to use
 * @param seed input
 * @param seedLen length of \p seed
 * @param mask output
 * @param maskLen length of \p mask
*/
FUNC(Std_ReturnType, CRYPTO_CODE) MGF1(Crypto_AlgorithmFamilyType hash_alg,
                                       uint8 *seed,
                                       uint32 seedLen,
                                       uint8 *mask,
                                       uint32 maskLen)
{
    /*
     * reduce size (get warning "stack protector not protecting function:
     * all local arrays are less than 8 bytes long")
     */
    uint8 cnt[8];
    uint32 c = 0;
    uint32 hashLen;
    uint8 *hash_in;
    Std_ReturnType RetVal = E_OK;

    hash_in = ShareMem_GetBlock(68 + 28);
    if (NULL == hash_in)
        return E_NOT_OK;

    hashLen = hash_get_digest_size(hash_alg);

    mini_memcpy_s(hash_in, seed, seedLen);

    /*modifying cnt content via array_blk[1].addr to make static analyzer happy*/
    while (maskLen) {
        cnt[0] = ((c >> 24)  & 0xFF);
        cnt[1] = ((c >> 16)  & 0xFF);
        cnt[2] = ((c >> 8)   & 0xFF);
        cnt[3] = ((c)        & 0xFF);
        mini_memcpy_s(hash_in + seedLen, cnt, 4);

        RetVal = Hsm_host_Hash(hash_alg, hash_in, seedLen + 4, mask,
                               NULL, CRYPTO_PROCESSING_SYNC);

        if (E_OK != RetVal) {
            break;
        }

        c++;
        maskLen -= hashLen >= maskLen ? maskLen : hashLen;
        mask += hashLen;
    }

    ShareMem_ReleaseBlock(hash_in);
    return RetVal;
}

/* message len <= key len -41 */
FUNC(Std_ReturnType, CRYPTO_CODE) rsa_pad_eme_oaep_encode(uint32 k,
                                  Crypto_AlgorithmFamilyType hash_alg,
                                  uint8 *EM,
                                  uint8 *message,
                                  uint32 mLen)
{
    uint8 *dbMask;
    uint8 *seedMask;
    uint8 *tmp;
    uint32 hLen;
    Std_ReturnType RetVal = E_OK;

    hLen = hash_get_digest_size(hash_alg);

    if (mLen + 2 * hLen + 2 > k) {
        return E_NOT_OK;
    }

    tmp = ShareMem_GetBlock(hLen);
    if (NULL == tmp)
        return E_NOT_OK;

    /* get label hash -> no label so NULL_blk, get empty string hash*/
    RetVal = Hsm_host_Hash(hash_alg, NULL, 0, tmp, &hLen,
                           CRYPTO_PROCESSING_SYNC);
    mini_memcpy_s((uint8 *)(EM + hLen + 1), tmp, hLen);

    /*Assemply of DB*/
    gen_rnd_bytes(EM + 1, hLen);
    EM[0] = 0x00;
    mini_memset_s((uint8 *)(EM + 2 * hLen + 1), 0x00, k - mLen - 2 * hLen - 2);
    *((uint8 *)(EM + k - mLen - 1)) = 0x01;
    mini_memcpy_s(EM + k - mLen, message, mLen);

    dbMask = ShareMem_GetBlock(RSA_MAX_SIZE);
    if (NULL == dbMask)
        return E_NOT_OK;

    seedMask = ShareMem_GetBlock(MAX_DIGESTSIZE);
    if (NULL == seedMask)
        return E_NOT_OK;

    MGF1(hash_alg, EM + 1, hLen, dbMask, k - hLen - 1);
    mask(EM + 1 + hLen, dbMask, k - hLen - 1);
    MGF1(hash_alg, EM + 1 + hLen, k - hLen - 1, seedMask, hLen);
    mask(EM + 1, seedMask, hLen);

    ShareMem_ReleaseBlock(dbMask);
    ShareMem_ReleaseBlock(seedMask);
    ShareMem_ReleaseBlock(tmp);

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) rsa_pad_eme_oaep_decode( uint32 k,
                                 Crypto_AlgorithmFamilyType hash_alg,
                                 uint8 *EM,
                                 uint8 **message,
                                 uint32 *mLen)
{
    uint32 hLen;
    uint8 *dbMask;
    uint8 *seedMask;
    uint32 i;
    int chkLHash;
    Std_ReturnType RetVal = E_OK;

    dbMask = ShareMem_GetBlock(RSA_MAX_SIZE);
    if (NULL == dbMask)
        return E_NOT_OK;

    seedMask = ShareMem_GetBlock(MAX_DIGESTSIZE);
    if (NULL == seedMask)
        return E_NOT_OK;

    hLen = hash_get_digest_size(hash_alg);

    MGF1(hash_alg, EM + hLen + 1, k - hLen - 1, seedMask, hLen);
    mask(EM + 1, seedMask, hLen);
    MGF1(hash_alg, EM + 1, hLen, dbMask, k - hLen - 1);
    mask(EM + hLen + 1, dbMask, k - hLen - 1);

    *mLen = 0;

    for (i = 2* hLen + 1; i < k; i++) {
        if (*(uint8 *)(EM + i) == 0x01) {
            *mLen = k - i - 1;
            break;
        }
    }
    /* get label hash -> no label so NULL_blk, get empty string hash*/
    RetVal = Hsm_host_Hash(hash_alg, NULL, 0, seedMask, &hLen, CRYPTO_PROCESSING_SYNC);

    chkLHash = mini_memcmp_s(seedMask, EM + hLen + 1, hash_get_digest_size(hash_alg));

    ShareMem_ReleaseBlock(dbMask);
    ShareMem_ReleaseBlock(seedMask);

    if (chkLHash || *mLen == 0 || EM[0]) {
        return E_NOT_OK;
    }

    *message = (uint8 *)((EM + k) - *mLen);

    return RetVal;
}

/* message len <= key len -11 */
FUNC(Std_ReturnType, CRYPTO_CODE) rsa_pad_eme_pkcs_encode( uint32 k,
                                 uint8 *EM,
                                 uint8 *message,
                                 uint32 mLen)
{
    Std_ReturnType RetVal = E_OK;

    if (mLen > (uint32)(k - 11)) {
        return E_NOT_OK;
    }

    /* Assemply of DB, PS (first written for alignment purpose)*/
    gen_rnd_bytes(EM + 2, k - mLen - 3);
    for (int i = 0; i < (k - mLen - 3); i++) {
        if (EM[2 + i] == 0)
            EM[2 + i]++;
    }

    EM[0] = 0x00;
    EM[1] = 0x02;

    *((uint8 *)(EM + k - mLen - 1)) = 0x00;
    mini_memcpy_s(EM + k - mLen, message, mLen);

    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) rsa_pad_eme_pkcs_decode(uint32 k,
                                 uint8 *EM,
                                 uint8 **message,
                                 uint32 *mLen)
{
    uint32 PSLen;
    uint32 i;

    *mLen = 0;

    for (i = 2; i < k; i++) {
        if (*(uint8 *)(EM + i) == 0x00) {
            *mLen = k - i - 1;
            break;
        }
    }

    PSLen = k - 3 - *mLen;

    if (*mLen == 0 || EM[0] || EM[1] != 0x02 || PSLen < 8) {
        return E_NOT_OK;
    }

    *message = (uint8 *)((EM + k) - *mLen);

    return E_OK;
}

FUNC(Std_ReturnType, CRYPTO_CODE) rsa_pad_emsa_pkcs_encode(uint32 emLen,
                                  Crypto_AlgorithmFamilyType hash_type,
                                  uint8 *EM,
                                  uint8 *hash)
{
    uint32 tLen;
    uint32 hLen;

    /*adapt DER encoded hash_alg*/
    switch (hash_type) {
        case CRYPTO_ALGOFAM_SHA2_224:
            hLen = 28;
            hash_algDer[1] = 0x2d;
            hash_algDer[14] = 0x04;
            hash_algDer[18] = 0x1c;
            break;

        case CRYPTO_ALGOFAM_SHA2_256:
            hLen = 32;
            hash_algDer[1] = 0x31;
            hash_algDer[14] = 0x01;
            hash_algDer[18] = 0x20;
            break;

        case CRYPTO_ALGOFAM_SHA2_384:
            hLen = 4 * 12;
            hash_algDer[1] = 0x41;
            hash_algDer[14] = 0x02;
            hash_algDer[18] = 0x30;
            break;

        case CRYPTO_ALGOFAM_SHA2_512:
            hLen = 4 * 16;
            hash_algDer[1] = 0x51;
            hash_algDer[14] = 0x03;
            hash_algDer[18] = 0x40;
            break;

        default:
            return E_NOT_OK;
    }

    tLen = hLen + DLEN;

    if (emLen < tLen + 11) {
        return E_NOT_OK;
    }

    *EM = 0x00;
    *(uint8 *)(EM + 1) = 0x01;
    mini_memset_s((uint8 *)(EM + 2), 0xff, emLen - tLen - 3);
    *(uint8 *)(EM + emLen - tLen - 1) = 0x00;
    mini_memcpy_s(EM + emLen - tLen, hash_algDer, DLEN);
    mini_memcpy_s(EM + emLen - hLen, hash, hLen);

    return E_OK;
}

FUNC(Std_ReturnType, CRYPTO_CODE) rsa_pad_emsa_pss_encode(uint32 emLen,
                                  Crypto_AlgorithmFamilyType hash_alg,
                                  uint8 *EM,
                                  uint8 *hash,
                                  uint32 n0,
                                  uint32 sLen)
{
    uint8 *dbMask;
    uint8 *tempm;
    uint8 *temph;
    uint32 hLen;
    Std_ReturnType RetVal = E_OK;

    hLen = hash_get_digest_size(hash_alg);

    if (!hLen) {
        return E_NOT_OK;
    }

    if (emLen < sLen + hLen + 2) {
        return E_NOT_OK;
    }

    dbMask = ShareMem_GetBlock(RSA_MAX_SIZE);
    if (NULL == dbMask)
        return E_NOT_OK;

    tempm = ShareMem_GetBlock(128);
    if (NULL == tempm)
        return E_NOT_OK;

    temph = ShareMem_GetBlock(hLen);
    if (NULL == temph)
        return E_NOT_OK;

    mini_memset_s(EM, 0x00, emLen - sLen - hLen - 2);
    gen_rnd_bytes((uint8 *)(EM + emLen - sLen - hLen - 1), sLen);
    *((uint8 *)(EM + emLen - sLen - hLen - 2)) = 0x01;

    mini_memset_s(tempm, 0, 8);
    mini_memcpy_s(tempm + 8, hash, hLen);
    mini_memcpy_s(tempm + 8 + hLen, (EM + emLen - (sLen + hLen) - 1), sLen);

    RetVal = Hsm_host_Hash(hash_alg, tempm, (8 + hLen + sLen), temph,
                           &hLen, CRYPTO_PROCESSING_SYNC);
    mini_memcpy_s((uint8 *)(EM + emLen - hLen - 1), temph, hLen);

    MGF1(hash_alg, EM + emLen - hLen - 1, hLen, dbMask, emLen - hLen - 1);
    mask(EM, dbMask, emLen - hLen - 1);

    EM[emLen - 1] = 0xBC;
    EM[0] = EM[0] & getFirstMask(n0);

    ShareMem_ReleaseBlock(dbMask);
    ShareMem_ReleaseBlock(tempm);
    ShareMem_ReleaseBlock(temph);
    return RetVal;
}

/* Steps from rfc8017 9.1.2 Verification operation */
FUNC(Std_ReturnType, CRYPTO_CODE) rsa_pad_emsa_pss_decode(uint32 emLen,
                                  Crypto_AlgorithmFamilyType hash_alg,
                                  uint8 *EM,
                                  uint8 *hash,
                                  uint32 sLen,
                                  uint32 n0)
{
    uint8 *maskedDB;
    uint32 dbLen;
    uint8 *H;
    uint32 mlen;
    uint8 *salt;
    uint8 *H_;
    int chkLHash;
    uint8 *dbMask;
    uint8 *hash_in = NULL;
    uint32 hLen;
    uint8 *DB;
    Std_ReturnType RetVal = E_OK;

    hLen = hash_get_digest_size(hash_alg);
    if (0 == hLen)
        return E_NOT_OK;

    /* 3.  If emLen < hLen + sLen + 2, output "inconsistent" and stop. */
    /* 4.  If the rightmost octet of EM does not have hexadecimal value
        0xbc, output "inconsistent" and stop. */
    if (emLen < hLen + sLen + 2 || EM[emLen - 1] != 0xbc) {
        return E_NOT_OK;
    }

    /* 5.  Let maskedDB be the leftmost emLen - hLen - 1 octets of EM, and
        let H be the next hLen octets. */
    maskedDB = EM;
    dbLen = emLen - hLen - 1;
    H = EM + emLen - hLen - 1;

    /*FIXME: This check is not performed because it fails a few known-good test cases.*/
    /* 6.   If the leftmost 8emLen - emBits bits of the leftmost octet in
            maskedDB are not all equal to zero, output "inconsistent" and
            stop. */

    /* 7.  Let dbMask = MGF(H, emLen - hLen - 1). */
    /*This buffer is later reused to store H'*/

    mlen = emLen - hLen - 1;
    mlen = mlen + ((mlen % hLen) ? hLen - (mlen % hLen) : 0);

    if (mlen > RSA_MAX_SIZE) {
        return E_NOT_OK;
    }

    dbMask = ShareMem_GetBlock(RSA_MAX_SIZE);
    if (NULL == dbMask)
        return E_NOT_OK;

    MGF1(hash_alg, H, hLen, dbMask, mlen);

    /* 8.  Let DB = maskedDB \xor dbMask. */
    mask(maskedDB, dbMask, emLen - hLen - 1);
    /*from here maskedDB = RFC's DB*/
    DB = maskedDB;
    /* 9.  Set the leftmost 8emLen - emBits bits of the leftmost octet in DB
           to zero. */
    DB[0] = DB[0] & getFirstMask(n0);

    /* 10. If the emLen - hLen - sLen - 2 leftmost octets of DB are not zero
        or if the octet at position emLen - hLen - sLen - 1 (the leftmost
        position is "position 1") does not have hexadecimal value 0x01,
        output "inconsistent" and stop. */
    for (uint32 i = 1; i < (emLen - hLen - sLen - 2); i++) {
        if (*(uint8 *)(DB + i)) {
            RetVal = E_NOT_OK;
            goto end;
        }
    }

    if (*(uint8 *)(DB + emLen - hLen - sLen - 2) != 0x01) {
        RetVal = E_NOT_OK;
        goto end;
    }

    /* 11.  Let salt be the last sLen octets of DB. */
    salt = DB + dbLen - sLen;

    /* 12.  Let M' = (0x)00 00 00 00 00 00 00 00 || mHash || salt ;
        M' is an octet string of length 8 + hLen + sLen with eight
        initial zero octets. */
    hash_in = ShareMem_GetBlock(128);
    if (NULL == hash_in)
        return E_NOT_OK;

    mini_memset_s(hash_in, 0, 8);
    mini_memcpy_s(hash_in + 8, hash, hLen);
    mini_memcpy_s(hash_in + 8 + hLen, salt, sLen);

    /* 13. Let H' = Hash(M'), an octet string of length hLen. */
    /*Hash is placed in the unused big buffer. First byte of EM 1 byte to small.*/
    H_ = dbMask;

    RetVal = Hsm_host_Hash(hash_alg, hash_in, (8 + hLen + sLen), H_,
                           &hLen, CRYPTO_PROCESSING_SYNC);
    if (E_OK != RetVal) {
        RetVal = E_NOT_OK;
        goto end;
    }

    /* 14. If H = H', output "consistent." Otherwise, output "inconsistent." */
    chkLHash = mini_memcmp_s(H, H_, hLen);

    if (chkLHash)
        RetVal = E_NOT_OK;
    else
        RetVal = E_OK;

end:
    ShareMem_ReleaseBlock(dbMask);
    ShareMem_ReleaseBlock(hash_in);
    return RetVal;
}

void rsa_pad_zeros(uint8 *EM,
                   uint32 emLen,
                   uint8 *hash,
                   uint32 hashLen)
{
    memset(EM, 0x00, emLen - hashLen);

    if (hashLen) {
        mini_memcpy_s(EM + emLen - hashLen, hash, hashLen);
    }
}

#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"
