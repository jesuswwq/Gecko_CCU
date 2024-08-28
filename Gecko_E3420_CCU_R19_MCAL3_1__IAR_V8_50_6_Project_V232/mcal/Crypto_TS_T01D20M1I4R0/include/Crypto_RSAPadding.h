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
 * @file  Crypto_RSAPadding.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Crypto
 */

#ifndef CRYPTO_RSAPADDING_H
#define CRYPTO_RSAPADDING_H

#ifdef __cplusplus
extern "C" {
#endif
#include "Crypto_Hsm.h"
#include "Crypto_ShareMem.h"
#include "Crypto_Types.h"
#include "Hsm_Types.h"

/**
 * Encode a message using OAEP
 * @param  k        RSA parameter length in bytes
 * @param  hashType The hash function to use (default is SHA1)
 * @param  EM       Pointer to the encoded message (EM) buffer
 * @param  message  Block containing address of the message to encode
 * @param  mLen     Length of the message to be encoded (bytes)
 * @param  rng      Random number generator to use
 * @return          CRYPTOLIB_SUCCESS when no error occurs
 */
FUNC(Std_ReturnType, CRYPTO_CODE) rsa_pad_eme_oaep_encode(uint32 k,
                                 Crypto_AlgorithmFamilyType hash_alg,
                                 uint8 *EM,
                                 uint8 *message,
                                 uint32 mLen);

/**
 * Decode a message using OEAP
 * @param  k        RSA parameter length in bytes
 * @param  hashType the hash function to use (default is SHA1)
 * @param  EM       Pointer to the encoded message (EM) buffer
 * @param  message  Output: Pointer to the decoded message. The decoding is
 *                  done in place within the limits of the EM buffer.
 * @param  mLen     Output: Length of the decoded message
 * @return          CRYPTOLIB_SUCCESS when no error occurs
 */
FUNC(Std_ReturnType, CRYPTO_CODE) rsa_pad_eme_oaep_decode( uint32 k,
                                 Crypto_AlgorithmFamilyType hash_alg,
                                 uint8 *EM,
                                 uint8 **message,
                                 uint32 *mLen);

/**
 * Encode message using PKCS
 * @param  k        RSA parameter length in bytes
 * @param  EM       Pointer to the encoded message (EM) buffer
 * @param  message  Block containing address of the message to encode
 * @param  mLen     Len of the message to be encoded (bytes)
 * @param  rng      random number generator to use
 * @return          CRYPTOLIB_SUCCESS when no error occurs
 */
FUNC(Std_ReturnType, CRYPTO_CODE) rsa_pad_eme_pkcs_encode( uint32 k,
                                 uint8 *EM,
                                 uint8 *message,
                                 uint32 mLen);

/**
 * Decodes encoded message using PKCS. message will point to the decoded message in EM
 * @param  k        RSA param length in bytes
 * @param  EM       Pointer to the encoded message (EM) buffer
 * @param  message  Output: Pointer to the decoded message in EM. The decoding
 *                  is done in place within the limits of the EM buffer.
 * @param  mLen     Output: Length of the decoded message (bytes)
 * @return          CRYPTOLIB_SUCCESS when no error occurs
 */
FUNC(Std_ReturnType, CRYPTO_CODE) rsa_pad_eme_pkcs_decode(uint32 k,
                                 uint8 *EM,
                                 uint8 **message,
                                 uint32 *mLen);

/**
 * Encode hash using PKCS
 * @param  emLen     Length of encoded message (EM) buffer (RSA parameter length
 *                   in bytes)
 * @param  hashype Hash function used for hashing \p hash (also used for the
 *                   PKCS algorithm)
 * @param  EM        Output: Pointer to the encoded message buffer
 * @param  hash      Input: Hash to encode
 * @return           CRYPTOLIB_SUCCESS if no error occurs
 */
FUNC(Std_ReturnType, CRYPTO_CODE) rsa_pad_emsa_pkcs_encode(uint32 emLen,
                                  Crypto_AlgorithmFamilyType hash_type,
                                  uint8 *EM,
                                  uint8 *hash);
/**
 * Encode hash using PSS. This function uses a salt length equal to the hash
 * digest length.
 * @param  emLen     Length of encoded message (EM) buffer (RSA parameter length
 *                   in bytes)
 * @param  hashType  Hash function used for hashing \p hash (also used for PKCS
 *                   algorithm)
 * @param  EM        Output: Pointer to the encoded message buffer
 * @param  hash      Input: Hash to encode
 * @param  n0        MSB of the modulus (for masking in order to match the
 *                   modulus size)
 * @param  sLen      Intended length of the salt
 * @param  rng       Random number generator to use
 * @return           CRYPTOLIB_SUCCESS if no error occurs
 */
FUNC(Std_ReturnType, CRYPTO_CODE) rsa_pad_emsa_pss_encode(uint32 emLen,
                                 Crypto_AlgorithmFamilyType hash_alg,
                                 uint8 *EM,
                                 uint8 *hash,
                                 uint32 n0,
                                 uint32 sLen);
/**
 * Decode encoded message using PSS and compares hash to the decoded hash
 * @param  emLen     Length of encoded message (EM) buffer (RSA parameter length
 *                   in bytes)
 * @param  hashType  Hash function used for hasing \p hash
 * @param  EM        Input: Pointer to the encoded message buffer
 * @param  hash      Hash to compare with
 * @param  sLen      Intended length of the salt
 * @param  n0        MSB of the modulus (for masking in order to match the
 *                   modulus size)
 * @return           CRYPTOLIB_SUCCESS if no error occurs and hash is valid
 */
FUNC(Std_ReturnType, CRYPTO_CODE) rsa_pad_emsa_pss_decode(uint32 emLen,
                                 Crypto_AlgorithmFamilyType hash_alg,
                                 uint8 *EM,
                                 uint8 *hash,
                                 uint32 sLen,
                                 uint32 n0);
/**
 * Pads the hash of \p hashLen to \p EM of \p emLen. MSBs are set to 0.
 *
 * \warning There should not be overlapping between \p EM and \p hash !
 * @param EM      Destination buffer (pointer)
 * @param emLen   Length of the destination buffer (bytes)
 * @param hash    Input to pad
 * @param hashLen Length of the input
 */
void rsa_pad_zeros(uint8 *EM,
                   uint32 emLen,
                   uint8 *hash,
                   uint32 hashLen);

#ifdef __cplusplus
}
#endif

#endif /* CRYPTO_RSAPADDING_H */
