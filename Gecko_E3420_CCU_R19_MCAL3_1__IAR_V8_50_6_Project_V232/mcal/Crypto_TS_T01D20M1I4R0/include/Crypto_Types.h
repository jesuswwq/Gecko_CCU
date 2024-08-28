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
 * @file  Crypto_Types.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Crypto
 */

#ifndef CRYPTO_TYPES_H
#define CRYPTO_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
#include "Mcal.h"
#include "Csm_Types.h"
#include "Hsm_Types.h"

typedef enum {
    CRYPTO_WA_DENIED        = 0x01U,
    CRYPTO_WA_INTERNAL_COPY = 0x02U,
    CRYPTO_WA_ALLOWED       = 0x03U,
    CRYPTO_WA_ENCRYPTED     = 0x04U
} Crypto_KeyElementWriteAccessType;

typedef enum {
    CRYPTO_RA_DENIED         = 0x01U,
    CRYPTO_RA_INTERNAL_COPY  = 0x02U,
    CRYPTO_RA_ALLOWED        = 0x03U,
    CRYPTO_RA_ENCRYPTED      = 0x04U
} Crypto_KeyElementReadAccessType;

/* key format */
typedef enum {
    CRYPTO_KE_FORMAT_BIN_OCTET                       = 0x01U,
    CRYPTO_KE_FORMAT_BIN_SHEKEYS                     = 0x02U,   /*not support*/
    CRYPTO_KE_FORMAT_BIN_IDENT_PRIVATEKEY_PKCS8      = 0x03U,   /*PKCS#8*/
    CRYPTO_KE_FORMAT_BIN_IDENT_PUBLICKEY             = 0x04U,   /*PKCS#8*/
    CRYPTO_KE_FORMAT_BIN_RSA_PRIVATEKEY              = 0x05U,   /*PKCS#1*/
    CRYPTO_KE_FORMAT_BIN_RSA_PUBLICKEY               = 0x06U,   /*PKCS#1*/
    CRYPTO_KE_FORMAT_BIN_CERT_X509_V3                = 0x07U,
    CRYPTO_KE_FORMAT_BIN_CERT_CVC                    = 0x08U,    /*not support*/
    CRYPTO_KE_FORMAT_BIN_SDRV_PLAINTEXT              = 0x09U,
    CRYPTO_KE_FORMAT_BIN_SDRV_CIPHERTEXT             = 0x0aU,
    CRYPTO_KE_FORMAT_BIN_SDRV_INTERNAL               = 0x0bU
} Crypto_KeyElementFormatType;

typedef enum {
    CRYPTO_DRIVER_UNINIT = 0x0u,
    CRYPTO_DRIVER_IDLE   = 0x1u
} Crypto_DriverStateType;

typedef enum {
    CRYPTO_DRIVER_OBJECT_IDLE   = 0x0U,
    CRYPTO_DRIVER_OBJECT_ACTIVE = 0x1U
} Crypto_DriverObjectStateType;

/**
    The key content follow the autosar specification,but the key type can
not be distingushed cleared. So, we add this enum type for this purpose.
pke use bit0~7 0xFF , ske use bit8~15 0xFF00,
*/
typedef enum {
    CRYPTO_KEYTYPE_P192_PUB  = 0x01u,
    CRYPTO_KEYTYPE_P192_PRI  = 0x02u,
    CRYPTO_KEYTYPE_P224_PUB  = 0x03u,
    CRYPTO_KEYTYPE_P224_PRI  = 0x04u,
    CRYPTO_KEYTYPE_P256_PUB  = 0x05u,
    CRYPTO_KEYTYPE_P256_PRI  = 0x06u,
    CRYPTO_KEYTYPE_P384_PUB  = 0x07u,
    CRYPTO_KEYTYPE_P384_PRI  = 0x08u,
    CRYPTO_KEYTYPE_P521_PUB  = 0x09u,
    CRYPTO_KEYTYPE_P521_PRI  = 0x0au,
    CRYPTO_KEYTYPE_SM2P256_PUB  = 0x0bu,
    CRYPTO_KEYTYPE_SM2P256_PRI  = 0x0cu,
    CRYPTO_KEYTYPE_ED25519_PUB  = 0x0du,
    CRYPTO_KEYTYPE_ED25519_PRI  = 0x0eu,
    CRYPTO_KEYTYPE_RSA1024_PUB  = 0x0fU,
    CRYPTO_KEYTYPE_RSA1024_PRI  = 0x10U,
    CRYPTO_KEYTYPE_RSA2048_PUB  = 0x11U,
    CRYPTO_KEYTYPE_RSA2048_PRI  = 0x12U,
    CRYPTO_KEYTYPE_RSA3072_PUB  = 0x13U,
    CRYPTO_KEYTYPE_RSA3072_PRI  = 0x14U,
    CRYPTO_KEYTYPE_RSA4096_PUB  = 0x15U,
    CRYPTO_KEYTYPE_RSA4096_PRI  = 0x16U,
    CRYPTO_KEYTYPE_SKE_KEY_128  = 0x100u,
    CRYPTO_KEYTYPE_SKE_KEY_192  = 0x200u,
    CRYPTO_KEYTYPE_SKE_KEY_256  = 0x300u,
    CRYPTO_KEYTYPE_MAC_KEY      = 0x400u,
    CRYPTO_KEYTYPE_MAX
} Crypto_KeyTypeType;

#define CRYPTO_KEYTYPE_PKE_MASK 0xFF
#define CRYPTO_KEYTYPE_SKE_MASK 0xFF00

/*used for element raw data flag, store element dircte enc data, not parse data*/
#define CRYPTO_KEYTYPE_ELEMENT_RAW (CRYPTO_KEYTYPE_MAX+1)

typedef enum {
    CRYPTO_NULL_PTR     = 0x00U,
    CRYPTO_INVALID_LEN  = 0x01U,
    CRYPTO_NO_ERROR     = 0x02U,
    CRYPTO_NOT_OK       = 0x03U
} Crypto_ErrorType;

typedef struct {
    CONST(uint32,                          CRYPTO_CONST) u32CryptoKeyElementGlobalId;
    CONST(uint32,                          CRYPTO_CONST) u32CryptoKeyElementId;
    CONST(boolean,                         CRYPTO_CONST) bCryptoKeyElementAllowPartialAccess;
    CONST(Crypto_KeyElementFormatType,     CRYPTO_CONST) eCryptoKeyElementFormatType;
    CONST(boolean,                         CRYPTO_CONST) bCryptoKeyElementPersist;
    CONST(Crypto_KeyElementReadAccessType, CRYPTO_CONST) eCryptoKeyElementReadAccess;
    CONST(Crypto_KeyElementWriteAccessType, CRYPTO_CONST) eCryptoKeyElementWriteAccess;
    CONST(uint32,                          CRYPTO_CONST) u32CryptoKeyElementSize;
    P2VAR(uint8,            AUTOMATIC, CRYPTO_APPL_DATA) pCryptoElementContent;
    VAR(uint32,                              CRYPTO_VAR) u32CryptoElementWritedSize;
} Crypto_KeyElementType;

typedef struct {
    CONST (Crypto_ServiceInfoType, CRYPTO_CONST) eService;
    CONST (Crypto_AlgorithmFamilyType, CRYPTO_CONST) eFamily;
    CONST (Crypto_AlgorithmModeType, CRYPTO_CONST) eMode;
    CONST (Crypto_AlgorithmFamilyType, CRYPTO_CONST) eSecondaryFamily;
} Crypto_PrimitiveType;

typedef struct {
    CONST(uint32, CRYPTO_CONST)                         u32CryptoKeyId;
    CONST(uint32, CRYPTO_CONST)                         u32CryptoKeyDeriveIterations;
    VAR(boolean, AUTOMATIC)                             bCryptoKeyValid;
    CONST(uint32, CRYPTO_CONST)                         u32ElementsNum;
    CONSTP2CONST(uint32, CRYPTO_VAR, CRYPTO_APPL_CONST) u32CryptoKeyElements;
    CONST(Crypto_KeyTypeType, CRYPTO_CONST)             CryptoKeyType;
    CONST(uint32, CRYPTO_CONST)                         u32CryptoKeyPairId;
    VAR(hsm_keytype, CRYPTO_VAR)                        CryptoHSMKeyType;
} Crypto_KeyType;

typedef struct {
    CONST(uint32, CRYPTO_CONST) u32DriverObjectId;
    CONST(uint32, CRYPTO_CONST) u32JobQueueSize;
    CONSTP2CONST(Crypto_PrimitiveType, CRYPTO_VAR, CRYPTO_APPL_CONST) pCryptoPrimitives;
    CONST(uint32, CRYPTO_CONST) u32CryptoPrimitivesSize;
} Crypto_ObjectType;

#ifdef __cplusplus
}
#endif

#endif /* CRYPTO_TYPES_H */
