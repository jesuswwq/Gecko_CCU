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
 * @file  Crypto_PBCfg.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Crypto
 * @date 2024-03-08 16:29:00
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "arch.h"
#include "Crypto_Cfg.h"
#include "Crypto_Types.h"
#include "Crypto_KeyManagement.h"

/******************Generated DriverObject*****************/
#define CRYPTO_DRIVEROBJ0_PRIMITIVE_NUM (6u)
#define CRYPTO_DRIVEROBJ1_PRIMITIVE_NUM (26u)
#define CRYPTO_DRIVEROBJ2_PRIMITIVE_NUM (1u)
#define CRYPTO_DRIVEROBJ3_PRIMITIVE_NUM (12u)
#define CRYPTO_DRIVEROBJ4_PRIMITIVE_NUM (14u)

#define CRYPTO_START_SEC_VAR_INIT_UNSPECIFIED
#include "Crypto_MemMap.h"

static Crypto_PrimitiveType aDriverObj0_Primitives[CRYPTO_DRIVEROBJ0_PRIMITIVE_NUM] = {
    {
        .eService = CRYPTO_HASH,
        .eFamily = CRYPTO_ALGOFAM_SHA1,
        .eMode = CRYPTO_ALGOMODE_NOT_SET,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
    {
        .eService = CRYPTO_HASH,
        .eFamily = CRYPTO_ALGOFAM_SHA2_224,
        .eMode = CRYPTO_ALGOMODE_NOT_SET,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
    {
        .eService = CRYPTO_HASH,
        .eFamily = CRYPTO_ALGOFAM_SHA2_256,
        .eMode = CRYPTO_ALGOMODE_NOT_SET,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
    {
        .eService = CRYPTO_HASH,
        .eFamily = CRYPTO_ALGOFAM_SHA2_384,
        .eMode = CRYPTO_ALGOMODE_NOT_SET,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
    {
        .eService = CRYPTO_HASH,
        .eFamily = CRYPTO_ALGOFAM_SHA2_512,
        .eMode = CRYPTO_ALGOMODE_NOT_SET,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
    {
        .eService = CRYPTO_HASH,
        .eFamily = CRYPTO_ALGOFAM_SHA2_512,
        .eMode = CRYPTO_ALGOMODE_NOT_SET,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
};
static Crypto_PrimitiveType aDriverObj1_Primitives[CRYPTO_DRIVEROBJ1_PRIMITIVE_NUM] = {
    {
        .eService = CRYPTO_ENCRYPT,
        .eFamily = CRYPTO_ALGOFAM_AES,
        .eMode = CRYPTO_ALGOMODE_ECB,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
    {
        .eService = CRYPTO_ENCRYPT,
        .eFamily = CRYPTO_ALGOFAM_AES,
        .eMode = CRYPTO_ALGOMODE_CBC,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
    {
        .eService = CRYPTO_ENCRYPT,
        .eFamily = CRYPTO_ALGOFAM_AES,
        .eMode = CRYPTO_ALGOMODE_CFB,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
    {
        .eService = CRYPTO_ENCRYPT,
        .eFamily = CRYPTO_ALGOFAM_AES,
        .eMode = CRYPTO_ALGOMODE_OFB,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
    {
        .eService = CRYPTO_ENCRYPT,
        .eFamily = CRYPTO_ALGOFAM_AES,
        .eMode = CRYPTO_ALGOMODE_CTR,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
    {
        .eService = CRYPTO_DECRYPT,
        .eFamily = CRYPTO_ALGOFAM_AES,
        .eMode = CRYPTO_ALGOMODE_ECB,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
    {
        .eService = CRYPTO_DECRYPT,
        .eFamily = CRYPTO_ALGOFAM_AES,
        .eMode = CRYPTO_ALGOMODE_CBC,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
    {
        .eService = CRYPTO_DECRYPT,
        .eFamily = CRYPTO_ALGOFAM_AES,
        .eMode = CRYPTO_ALGOMODE_CFB,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
    {
        .eService = CRYPTO_DECRYPT,
        .eFamily = CRYPTO_ALGOFAM_AES,
        .eMode = CRYPTO_ALGOMODE_OFB,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
    {
        .eService = CRYPTO_DECRYPT,
        .eFamily = CRYPTO_ALGOFAM_AES,
        .eMode = CRYPTO_ALGOMODE_CTR,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
    {
        .eService = CRYPTO_AEADENCRYPT,
        .eFamily = CRYPTO_ALGOFAM_AES,
        .eMode = CRYPTO_ALGOMODE_GCM,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
    {
        .eService = CRYPTO_AEADENCRYPT,
        .eFamily = CRYPTO_ALGOFAM_AES,
        .eMode = CRYPTO_ALGOMODE_CTR,
        .eSecondaryFamily = CRYPTO_ALGOFAM_AES
    },
    {
        .eService = CRYPTO_AEADDECRYPT,
        .eFamily = CRYPTO_ALGOFAM_AES,
        .eMode = CRYPTO_ALGOMODE_GCM,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
    {
        .eService = CRYPTO_AEADDECRYPT,
        .eFamily = CRYPTO_ALGOFAM_AES,
        .eMode = CRYPTO_ALGOMODE_CBC,
        .eSecondaryFamily = CRYPTO_ALGOFAM_AES
    },
    {
        .eService = CRYPTO_ENCRYPT,
        .eFamily = CRYPTO_ALGOFAM_AES,
        .eMode = CRYPTO_ALGOMODE_XTS,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
    {
        .eService = CRYPTO_DECRYPT,
        .eFamily = CRYPTO_ALGOFAM_AES,
        .eMode = CRYPTO_ALGOMODE_XTS,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
    {
        .eService = CRYPTO_ENCRYPT,
        .eFamily = CRYPTO_ALGOFAM_CUSTOM,
        .eMode = CRYPTO_ALGOMODE_ECB,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
    {
        .eService = CRYPTO_ENCRYPT,
        .eFamily = CRYPTO_ALGOFAM_CUSTOM,
        .eMode = CRYPTO_ALGOMODE_CBC,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
    {
        .eService = CRYPTO_ENCRYPT,
        .eFamily = CRYPTO_ALGOFAM_CUSTOM,
        .eMode = CRYPTO_ALGOMODE_CFB,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
    {
        .eService = CRYPTO_ENCRYPT,
        .eFamily = CRYPTO_ALGOFAM_CUSTOM,
        .eMode = CRYPTO_ALGOMODE_OFB,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
    {
        .eService = CRYPTO_ENCRYPT,
        .eFamily = CRYPTO_ALGOFAM_CUSTOM,
        .eMode = CRYPTO_ALGOMODE_CTR,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
    {
        .eService = CRYPTO_DECRYPT,
        .eFamily = CRYPTO_ALGOFAM_CUSTOM,
        .eMode = CRYPTO_ALGOMODE_ECB,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
    {
        .eService = CRYPTO_DECRYPT,
        .eFamily = CRYPTO_ALGOFAM_CUSTOM,
        .eMode = CRYPTO_ALGOMODE_CBC,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
    {
        .eService = CRYPTO_DECRYPT,
        .eFamily = CRYPTO_ALGOFAM_CUSTOM,
        .eMode = CRYPTO_ALGOMODE_CFB,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
    {
        .eService = CRYPTO_DECRYPT,
        .eFamily = CRYPTO_ALGOFAM_CUSTOM,
        .eMode = CRYPTO_ALGOMODE_OFB,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
    {
        .eService = CRYPTO_DECRYPT,
        .eFamily = CRYPTO_ALGOFAM_CUSTOM,
        .eMode = CRYPTO_ALGOMODE_CTR,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
};
static Crypto_PrimitiveType aDriverObj2_Primitives[CRYPTO_DRIVEROBJ2_PRIMITIVE_NUM] = {
    {
        .eService = CRYPTO_RANDOMGENERATE,
        .eFamily = CRYPTO_ALGOFAM_RNG,
        .eMode = CRYPTO_ALGOMODE_NOT_SET,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
};
static Crypto_PrimitiveType aDriverObj3_Primitives[CRYPTO_DRIVEROBJ3_PRIMITIVE_NUM] = {
    {
        .eService = CRYPTO_MACGENERATE,
        .eFamily = CRYPTO_ALGOFAM_SHA1,
        .eMode = CRYPTO_ALGOMODE_HMAC,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
    {
        .eService = CRYPTO_MACGENERATE,
        .eFamily = CRYPTO_ALGOFAM_SHA2_224,
        .eMode = CRYPTO_ALGOMODE_HMAC,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
    {
        .eService = CRYPTO_MACGENERATE,
        .eFamily = CRYPTO_ALGOFAM_SHA2_256,
        .eMode = CRYPTO_ALGOMODE_HMAC,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
    {
        .eService = CRYPTO_MACGENERATE,
        .eFamily = CRYPTO_ALGOFAM_SHA2_384,
        .eMode = CRYPTO_ALGOMODE_HMAC,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
    {
        .eService = CRYPTO_MACGENERATE,
        .eFamily = CRYPTO_ALGOFAM_SHA2_512,
        .eMode = CRYPTO_ALGOMODE_HMAC,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
    {
        .eService = CRYPTO_MACVERIFY,
        .eFamily = CRYPTO_ALGOFAM_SHA1,
        .eMode = CRYPTO_ALGOMODE_HMAC,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
    {
        .eService = CRYPTO_MACVERIFY,
        .eFamily = CRYPTO_ALGOFAM_SHA2_224,
        .eMode = CRYPTO_ALGOMODE_HMAC,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
    {
        .eService = CRYPTO_MACVERIFY,
        .eFamily = CRYPTO_ALGOFAM_SHA2_256,
        .eMode = CRYPTO_ALGOMODE_HMAC,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
    {
        .eService = CRYPTO_MACVERIFY,
        .eFamily = CRYPTO_ALGOFAM_SHA2_384,
        .eMode = CRYPTO_ALGOMODE_HMAC,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
    {
        .eService = CRYPTO_MACVERIFY,
        .eFamily = CRYPTO_ALGOFAM_SHA2_512,
        .eMode = CRYPTO_ALGOMODE_HMAC,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
    {
        .eService = CRYPTO_MACGENERATE,
        .eFamily = CRYPTO_ALGOFAM_AES,
        .eMode = CRYPTO_ALGOMODE_CMAC,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
    {
        .eService = CRYPTO_MACVERIFY,
        .eFamily = CRYPTO_ALGOFAM_AES,
        .eMode = CRYPTO_ALGOMODE_CMAC,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
};
static Crypto_PrimitiveType aDriverObj4_Primitives[CRYPTO_DRIVEROBJ4_PRIMITIVE_NUM] = {
    {
        .eService = CRYPTO_ENCRYPT,
        .eFamily = CRYPTO_ALGOFAM_RSA,
        .eMode = CRYPTO_ALGOMODE_RSAES_OAEP,
        .eSecondaryFamily = CRYPTO_ALGOFAM_SHA2_256
    },
    {
        .eService = CRYPTO_ENCRYPT,
        .eFamily = CRYPTO_ALGOFAM_RSA,
        .eMode = CRYPTO_ALGOMODE_RSAES_PKCS1_v1_5,
        .eSecondaryFamily = CRYPTO_ALGOFAM_SHA2_256
    },
    {
        .eService = CRYPTO_DECRYPT,
        .eFamily = CRYPTO_ALGOFAM_RSA,
        .eMode = CRYPTO_ALGOMODE_RSAES_OAEP,
        .eSecondaryFamily = CRYPTO_ALGOFAM_SHA2_256
    },
    {
        .eService = CRYPTO_DECRYPT,
        .eFamily = CRYPTO_ALGOFAM_RSA,
        .eMode = CRYPTO_ALGOMODE_RSAES_PKCS1_v1_5,
        .eSecondaryFamily = CRYPTO_ALGOFAM_SHA2_256
    },
    {
        .eService = CRYPTO_SIGNATUREGENERATE,
        .eFamily = CRYPTO_ALGOFAM_RSA,
        .eMode = CRYPTO_ALGOMODE_RSASSA_PKCS1_v1_5,
        .eSecondaryFamily = CRYPTO_ALGOFAM_SHA2_256
    },
    {
        .eService = CRYPTO_SIGNATUREGENERATE,
        .eFamily = CRYPTO_ALGOFAM_RSA,
        .eMode = CRYPTO_ALGOMODE_RSASSA_PSS,
        .eSecondaryFamily = CRYPTO_ALGOFAM_SHA2_256
    },
    {
        .eService = CRYPTO_SIGNATUREVERIFY,
        .eFamily = CRYPTO_ALGOFAM_RSA,
        .eMode = CRYPTO_ALGOMODE_RSASSA_PKCS1_v1_5,
        .eSecondaryFamily = CRYPTO_ALGOFAM_SHA2_256
    },
    {
        .eService = CRYPTO_SIGNATUREVERIFY,
        .eFamily = CRYPTO_ALGOFAM_RSA,
        .eMode = CRYPTO_ALGOMODE_RSASSA_PSS,
        .eSecondaryFamily = CRYPTO_ALGOFAM_SHA2_256
    },
    {
        .eService = CRYPTO_SIGNATUREGENERATE,
        .eFamily = CRYPTO_ALGOFAM_ECCNIST,
        .eMode = CRYPTO_ALGOMODE_NOT_SET,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
    {
        .eService = CRYPTO_SIGNATUREVERIFY,
        .eFamily = CRYPTO_ALGOFAM_ECCNIST,
        .eMode = CRYPTO_ALGOMODE_NOT_SET,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
    {
        .eService = CRYPTO_SIGNATUREGENERATE,
        .eFamily = CRYPTO_ALGOFAM_ECIES,
        .eMode = CRYPTO_ALGOMODE_NOT_SET,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
    {
        .eService = CRYPTO_SIGNATUREVERIFY,
        .eFamily = CRYPTO_ALGOFAM_ECIES,
        .eMode = CRYPTO_ALGOMODE_NOT_SET,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
    {
        .eService = CRYPTO_SIGNATUREGENERATE,
        .eFamily = CRYPTO_ALGOFAM_ED25519,
        .eMode = CRYPTO_ALGOMODE_NOT_SET,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
    {
        .eService = CRYPTO_SIGNATUREVERIFY,
        .eFamily = CRYPTO_ALGOFAM_ED25519,
        .eMode = CRYPTO_ALGOMODE_NOT_SET,
        .eSecondaryFamily = CRYPTO_ALGOFAM_NOT_SET
    },
};

Crypto_ObjectType Crypto_aDriverObjectList[CRYPTO_DRIVER_OBJ_NUM] = {
    {
        .u32DriverObjectId = 1,
        .u32JobQueueSize = CRYPTO_DRIVEROBJ_QUEUE_SIZE,
        .pCryptoPrimitives = aDriverObj0_Primitives,
        .u32CryptoPrimitivesSize = CRYPTO_DRIVEROBJ0_PRIMITIVE_NUM
    },
    {
        .u32DriverObjectId = 2,
        .u32JobQueueSize = CRYPTO_DRIVEROBJ_QUEUE_SIZE,
        .pCryptoPrimitives = aDriverObj1_Primitives,
        .u32CryptoPrimitivesSize = CRYPTO_DRIVEROBJ1_PRIMITIVE_NUM
    },
    {
        .u32DriverObjectId = 3,
        .u32JobQueueSize = CRYPTO_DRIVEROBJ_QUEUE_SIZE,
        .pCryptoPrimitives = aDriverObj2_Primitives,
        .u32CryptoPrimitivesSize = CRYPTO_DRIVEROBJ2_PRIMITIVE_NUM
    },
    {
        .u32DriverObjectId = 4,
        .u32JobQueueSize = CRYPTO_DRIVEROBJ_QUEUE_SIZE,
        .pCryptoPrimitives = aDriverObj3_Primitives,
        .u32CryptoPrimitivesSize = CRYPTO_DRIVEROBJ3_PRIMITIVE_NUM
    },
    {
        .u32DriverObjectId = 5,
        .u32JobQueueSize = CRYPTO_DRIVEROBJ_QUEUE_SIZE,
        .pCryptoPrimitives = aDriverObj4_Primitives,
        .u32CryptoPrimitivesSize = CRYPTO_DRIVEROBJ4_PRIMITIVE_NUM
    },
};

/***********************Generated key**************************/


static Crypto_KeyElementType Key_Element_0 = {
    .u32CryptoKeyElementId = 1,
    .bCryptoKeyElementAllowPartialAccess = TRUE,
    .eCryptoKeyElementFormatType = CRYPTO_KE_FORMAT_BIN_OCTET,
    .bCryptoKeyElementPersist = TRUE,
    .eCryptoKeyElementReadAccess = CRYPTO_RA_ALLOWED,
    .eCryptoKeyElementWriteAccess = CRYPTO_WA_ALLOWED,
    .u32CryptoKeyElementSize = 32,
    .pCryptoElementContent = NULL_PTR,
    .u32CryptoElementWritedSize = 0
};
static Crypto_KeyElementType Key_Element_1 = {
    .u32CryptoKeyElementId = 1,
    .bCryptoKeyElementAllowPartialAccess = TRUE,
    .eCryptoKeyElementFormatType = CRYPTO_KE_FORMAT_BIN_OCTET,
    .bCryptoKeyElementPersist = TRUE,
    .eCryptoKeyElementReadAccess = CRYPTO_RA_ALLOWED,
    .eCryptoKeyElementWriteAccess = CRYPTO_WA_ALLOWED,
    .u32CryptoKeyElementSize = 32,
    .pCryptoElementContent = NULL_PTR,
    .u32CryptoElementWritedSize = 0
};
static Crypto_KeyElementType Key_Element_2 = {
    .u32CryptoKeyElementId = 1,
    .bCryptoKeyElementAllowPartialAccess = TRUE,
    .eCryptoKeyElementFormatType = CRYPTO_KE_FORMAT_BIN_OCTET,
    .bCryptoKeyElementPersist = TRUE,
    .eCryptoKeyElementReadAccess = CRYPTO_RA_ALLOWED,
    .eCryptoKeyElementWriteAccess = CRYPTO_WA_ALLOWED,
    .u32CryptoKeyElementSize = 32,
    .pCryptoElementContent = NULL_PTR,
    .u32CryptoElementWritedSize = 0
};
static Crypto_KeyElementType Key_Element_3 = {
    .u32CryptoKeyElementId = 1,
    .bCryptoKeyElementAllowPartialAccess = TRUE,
    .eCryptoKeyElementFormatType = CRYPTO_KE_FORMAT_BIN_OCTET,
    .bCryptoKeyElementPersist = TRUE,
    .eCryptoKeyElementReadAccess = CRYPTO_RA_ALLOWED,
    .eCryptoKeyElementWriteAccess = CRYPTO_WA_ALLOWED,
    .u32CryptoKeyElementSize = 32,
    .pCryptoElementContent = NULL_PTR,
    .u32CryptoElementWritedSize = 0
};
static Crypto_KeyElementType Key_Element_4 = {
    .u32CryptoKeyElementId = 5,
    .bCryptoKeyElementAllowPartialAccess = TRUE,
    .eCryptoKeyElementFormatType = CRYPTO_KE_FORMAT_BIN_OCTET,
    .bCryptoKeyElementPersist = TRUE,
    .eCryptoKeyElementReadAccess = CRYPTO_RA_ALLOWED,
    .eCryptoKeyElementWriteAccess = CRYPTO_WA_ALLOWED,
    .u32CryptoKeyElementSize = 32,
    .pCryptoElementContent = NULL_PTR,
    .u32CryptoElementWritedSize = 0
};
static Crypto_KeyElementType Key_Element_5 = {
    .u32CryptoKeyElementId = 5,
    .bCryptoKeyElementAllowPartialAccess = TRUE,
    .eCryptoKeyElementFormatType = CRYPTO_KE_FORMAT_BIN_OCTET,
    .bCryptoKeyElementPersist = TRUE,
    .eCryptoKeyElementReadAccess = CRYPTO_RA_ALLOWED,
    .eCryptoKeyElementWriteAccess = CRYPTO_WA_ALLOWED,
    .u32CryptoKeyElementSize = 32,
    .pCryptoElementContent = NULL_PTR,
    .u32CryptoElementWritedSize = 0
};
static Crypto_KeyElementType Key_Element_6 = {
    .u32CryptoKeyElementId = 5,
    .bCryptoKeyElementAllowPartialAccess = TRUE,
    .eCryptoKeyElementFormatType = CRYPTO_KE_FORMAT_BIN_OCTET,
    .bCryptoKeyElementPersist = TRUE,
    .eCryptoKeyElementReadAccess = CRYPTO_RA_ALLOWED,
    .eCryptoKeyElementWriteAccess = CRYPTO_WA_ALLOWED,
    .u32CryptoKeyElementSize = 32,
    .pCryptoElementContent = NULL_PTR,
    .u32CryptoElementWritedSize = 0
};
static Crypto_KeyElementType Key_Element_7 = {
    .u32CryptoKeyElementId = 5,
    .bCryptoKeyElementAllowPartialAccess = TRUE,
    .eCryptoKeyElementFormatType = CRYPTO_KE_FORMAT_BIN_OCTET,
    .bCryptoKeyElementPersist = TRUE,
    .eCryptoKeyElementReadAccess = CRYPTO_RA_ALLOWED,
    .eCryptoKeyElementWriteAccess = CRYPTO_WA_ALLOWED,
    .u32CryptoKeyElementSize = 32,
    .pCryptoElementContent = NULL_PTR,
    .u32CryptoElementWritedSize = 0
};
static Crypto_KeyElementType Key_Element_8 = {
    .u32CryptoKeyElementId = 1,
    .bCryptoKeyElementAllowPartialAccess = TRUE,
    .eCryptoKeyElementFormatType = CRYPTO_KE_FORMAT_BIN_OCTET,
    .bCryptoKeyElementPersist = TRUE,
    .eCryptoKeyElementReadAccess = CRYPTO_RA_ALLOWED,
    .eCryptoKeyElementWriteAccess = CRYPTO_WA_ALLOWED,
    .u32CryptoKeyElementSize = 32,
    .pCryptoElementContent = NULL_PTR,
    .u32CryptoElementWritedSize = 0
};
static Crypto_KeyElementType Key_Element_9 = {
    .u32CryptoKeyElementId = 1,
    .bCryptoKeyElementAllowPartialAccess = TRUE,
    .eCryptoKeyElementFormatType = CRYPTO_KE_FORMAT_BIN_OCTET,
    .bCryptoKeyElementPersist = TRUE,
    .eCryptoKeyElementReadAccess = CRYPTO_RA_ALLOWED,
    .eCryptoKeyElementWriteAccess = CRYPTO_WA_ALLOWED,
    .u32CryptoKeyElementSize = 32,
    .pCryptoElementContent = NULL_PTR,
    .u32CryptoElementWritedSize = 0
};
static Crypto_KeyElementType Key_Element_10 = {
    .u32CryptoKeyElementId = 7,
    .bCryptoKeyElementAllowPartialAccess = TRUE,
    .eCryptoKeyElementFormatType = CRYPTO_KE_FORMAT_BIN_OCTET,
    .bCryptoKeyElementPersist = TRUE,
    .eCryptoKeyElementReadAccess = CRYPTO_RA_ALLOWED,
    .eCryptoKeyElementWriteAccess = CRYPTO_WA_ALLOWED,
    .u32CryptoKeyElementSize = 32,
    .pCryptoElementContent = NULL_PTR,
    .u32CryptoElementWritedSize = 0
};
static Crypto_KeyElementType Key_Element_11 = {
    .u32CryptoKeyElementId = 7,
    .bCryptoKeyElementAllowPartialAccess = TRUE,
    .eCryptoKeyElementFormatType = CRYPTO_KE_FORMAT_BIN_OCTET,
    .bCryptoKeyElementPersist = TRUE,
    .eCryptoKeyElementReadAccess = CRYPTO_RA_ALLOWED,
    .eCryptoKeyElementWriteAccess = CRYPTO_WA_ALLOWED,
    .u32CryptoKeyElementSize = 32,
    .pCryptoElementContent = NULL_PTR,
    .u32CryptoElementWritedSize = 0
};
static Crypto_KeyElementType Key_Element_12 = {
    .u32CryptoKeyElementId = 1,
    .bCryptoKeyElementAllowPartialAccess = TRUE,
    .eCryptoKeyElementFormatType = CRYPTO_KE_FORMAT_BIN_OCTET,
    .bCryptoKeyElementPersist = TRUE,
    .eCryptoKeyElementReadAccess = CRYPTO_RA_ALLOWED,
    .eCryptoKeyElementWriteAccess = CRYPTO_WA_ALLOWED,
    .u32CryptoKeyElementSize = 384,
    .pCryptoElementContent = NULL_PTR,
    .u32CryptoElementWritedSize = 0
};
static Crypto_KeyElementType Key_Element_13 = {
    .u32CryptoKeyElementId = 1,
    .bCryptoKeyElementAllowPartialAccess = TRUE,
    .eCryptoKeyElementFormatType = CRYPTO_KE_FORMAT_BIN_OCTET,
    .bCryptoKeyElementPersist = TRUE,
    .eCryptoKeyElementReadAccess = CRYPTO_RA_ALLOWED,
    .eCryptoKeyElementWriteAccess = CRYPTO_WA_ALLOWED,
    .u32CryptoKeyElementSize = 256,
    .pCryptoElementContent = NULL_PTR,
    .u32CryptoElementWritedSize = 0
};
static Crypto_KeyElementType Key_Element_14 = {
    .u32CryptoKeyElementId = 1,
    .bCryptoKeyElementAllowPartialAccess = TRUE,
    .eCryptoKeyElementFormatType = CRYPTO_KE_FORMAT_BIN_OCTET,
    .bCryptoKeyElementPersist = TRUE,
    .eCryptoKeyElementReadAccess = CRYPTO_RA_ALLOWED,
    .eCryptoKeyElementWriteAccess = CRYPTO_WA_ALLOWED,
    .u32CryptoKeyElementSize = 768,
    .pCryptoElementContent = NULL_PTR,
    .u32CryptoElementWritedSize = 0
};
static Crypto_KeyElementType Key_Element_15 = {
    .u32CryptoKeyElementId = 1,
    .bCryptoKeyElementAllowPartialAccess = TRUE,
    .eCryptoKeyElementFormatType = CRYPTO_KE_FORMAT_BIN_OCTET,
    .bCryptoKeyElementPersist = TRUE,
    .eCryptoKeyElementReadAccess = CRYPTO_RA_ALLOWED,
    .eCryptoKeyElementWriteAccess = CRYPTO_WA_ALLOWED,
    .u32CryptoKeyElementSize = 512,
    .pCryptoElementContent = NULL_PTR,
    .u32CryptoElementWritedSize = 0
};
static Crypto_KeyElementType Key_Element_16 = {
    .u32CryptoKeyElementId = 1,
    .bCryptoKeyElementAllowPartialAccess = TRUE,
    .eCryptoKeyElementFormatType = CRYPTO_KE_FORMAT_BIN_OCTET,
    .bCryptoKeyElementPersist = TRUE,
    .eCryptoKeyElementReadAccess = CRYPTO_RA_ALLOWED,
    .eCryptoKeyElementWriteAccess = CRYPTO_WA_ALLOWED,
    .u32CryptoKeyElementSize = 1536,
    .pCryptoElementContent = NULL_PTR,
    .u32CryptoElementWritedSize = 0
};
static Crypto_KeyElementType Key_Element_17 = {
    .u32CryptoKeyElementId = 1,
    .bCryptoKeyElementAllowPartialAccess = TRUE,
    .eCryptoKeyElementFormatType = CRYPTO_KE_FORMAT_BIN_OCTET,
    .bCryptoKeyElementPersist = TRUE,
    .eCryptoKeyElementReadAccess = CRYPTO_RA_ALLOWED,
    .eCryptoKeyElementWriteAccess = CRYPTO_WA_ALLOWED,
    .u32CryptoKeyElementSize = 1024,
    .pCryptoElementContent = NULL_PTR,
    .u32CryptoElementWritedSize = 0
};
static Crypto_KeyElementType Key_Element_18 = {
    .u32CryptoKeyElementId = 1,
    .bCryptoKeyElementAllowPartialAccess = TRUE,
    .eCryptoKeyElementFormatType = CRYPTO_KE_FORMAT_BIN_RSA_PRIVATEKEY,
    .bCryptoKeyElementPersist = TRUE,
    .eCryptoKeyElementReadAccess = CRYPTO_RA_ALLOWED,
    .eCryptoKeyElementWriteAccess = CRYPTO_WA_ALLOWED,
    .u32CryptoKeyElementSize = 626,
    .pCryptoElementContent = NULL_PTR,
    .u32CryptoElementWritedSize = 0
};
static Crypto_KeyElementType Key_Element_19 = {
    .u32CryptoKeyElementId = 1,
    .bCryptoKeyElementAllowPartialAccess = TRUE,
    .eCryptoKeyElementFormatType = CRYPTO_KE_FORMAT_BIN_RSA_PUBLICKEY,
    .bCryptoKeyElementPersist = TRUE,
    .eCryptoKeyElementReadAccess = CRYPTO_RA_ALLOWED,
    .eCryptoKeyElementWriteAccess = CRYPTO_WA_ALLOWED,
    .u32CryptoKeyElementSize = 142,
    .pCryptoElementContent = NULL_PTR,
    .u32CryptoElementWritedSize = 0
};
static Crypto_KeyElementType Key_Element_20 = {
    .u32CryptoKeyElementId = 1,
    .bCryptoKeyElementAllowPartialAccess = TRUE,
    .eCryptoKeyElementFormatType = CRYPTO_KE_FORMAT_BIN_RSA_PRIVATEKEY,
    .bCryptoKeyElementPersist = TRUE,
    .eCryptoKeyElementReadAccess = CRYPTO_RA_ALLOWED,
    .eCryptoKeyElementWriteAccess = CRYPTO_WA_ALLOWED,
    .u32CryptoKeyElementSize = 1230,
    .pCryptoElementContent = NULL_PTR,
    .u32CryptoElementWritedSize = 0
};
static Crypto_KeyElementType Key_Element_21 = {
    .u32CryptoKeyElementId = 1,
    .bCryptoKeyElementAllowPartialAccess = TRUE,
    .eCryptoKeyElementFormatType = CRYPTO_KE_FORMAT_BIN_RSA_PUBLICKEY,
    .bCryptoKeyElementPersist = TRUE,
    .eCryptoKeyElementReadAccess = CRYPTO_RA_ALLOWED,
    .eCryptoKeyElementWriteAccess = CRYPTO_WA_ALLOWED,
    .u32CryptoKeyElementSize = 278,
    .pCryptoElementContent = NULL_PTR,
    .u32CryptoElementWritedSize = 0
};
static Crypto_KeyElementType Key_Element_22 = {
    .u32CryptoKeyElementId = 1,
    .bCryptoKeyElementAllowPartialAccess = TRUE,
    .eCryptoKeyElementFormatType = CRYPTO_KE_FORMAT_BIN_RSA_PRIVATEKEY,
    .bCryptoKeyElementPersist = TRUE,
    .eCryptoKeyElementReadAccess = CRYPTO_RA_ALLOWED,
    .eCryptoKeyElementWriteAccess = CRYPTO_WA_ALLOWED,
    .u32CryptoKeyElementSize = 2384,
    .pCryptoElementContent = NULL_PTR,
    .u32CryptoElementWritedSize = 0
};
static Crypto_KeyElementType Key_Element_23 = {
    .u32CryptoKeyElementId = 1,
    .bCryptoKeyElementAllowPartialAccess = TRUE,
    .eCryptoKeyElementFormatType = CRYPTO_KE_FORMAT_BIN_RSA_PUBLICKEY,
    .bCryptoKeyElementPersist = TRUE,
    .eCryptoKeyElementReadAccess = CRYPTO_RA_ALLOWED,
    .eCryptoKeyElementWriteAccess = CRYPTO_WA_ALLOWED,
    .u32CryptoKeyElementSize = 534,
    .pCryptoElementContent = NULL_PTR,
    .u32CryptoElementWritedSize = 0
};
static Crypto_KeyElementType Key_Element_24 = {
    .u32CryptoKeyElementId = 1,
    .bCryptoKeyElementAllowPartialAccess = TRUE,
    .eCryptoKeyElementFormatType = CRYPTO_KE_FORMAT_BIN_OCTET,
    .bCryptoKeyElementPersist = TRUE,
    .eCryptoKeyElementReadAccess = CRYPTO_RA_ALLOWED,
    .eCryptoKeyElementWriteAccess = CRYPTO_WA_ALLOWED,
    .u32CryptoKeyElementSize = 24,
    .pCryptoElementContent = NULL_PTR,
    .u32CryptoElementWritedSize = 0
};
static Crypto_KeyElementType Key_Element_25 = {
    .u32CryptoKeyElementId = 1,
    .bCryptoKeyElementAllowPartialAccess = TRUE,
    .eCryptoKeyElementFormatType = CRYPTO_KE_FORMAT_BIN_OCTET,
    .bCryptoKeyElementPersist = TRUE,
    .eCryptoKeyElementReadAccess = CRYPTO_RA_ALLOWED,
    .eCryptoKeyElementWriteAccess = CRYPTO_WA_ALLOWED,
    .u32CryptoKeyElementSize = 48,
    .pCryptoElementContent = NULL_PTR,
    .u32CryptoElementWritedSize = 0
};
static Crypto_KeyElementType Key_Element_26 = {
    .u32CryptoKeyElementId = 1,
    .bCryptoKeyElementAllowPartialAccess = TRUE,
    .eCryptoKeyElementFormatType = CRYPTO_KE_FORMAT_BIN_OCTET,
    .bCryptoKeyElementPersist = TRUE,
    .eCryptoKeyElementReadAccess = CRYPTO_RA_ALLOWED,
    .eCryptoKeyElementWriteAccess = CRYPTO_WA_ALLOWED,
    .u32CryptoKeyElementSize = 32,
    .pCryptoElementContent = NULL_PTR,
    .u32CryptoElementWritedSize = 0
};
static Crypto_KeyElementType Key_Element_27 = {
    .u32CryptoKeyElementId = 1,
    .bCryptoKeyElementAllowPartialAccess = TRUE,
    .eCryptoKeyElementFormatType = CRYPTO_KE_FORMAT_BIN_OCTET,
    .bCryptoKeyElementPersist = TRUE,
    .eCryptoKeyElementReadAccess = CRYPTO_RA_ALLOWED,
    .eCryptoKeyElementWriteAccess = CRYPTO_WA_ALLOWED,
    .u32CryptoKeyElementSize = 64,
    .pCryptoElementContent = NULL_PTR,
    .u32CryptoElementWritedSize = 0
};
static Crypto_KeyElementType Key_Element_28 = {
    .u32CryptoKeyElementId = 1,
    .bCryptoKeyElementAllowPartialAccess = TRUE,
    .eCryptoKeyElementFormatType = CRYPTO_KE_FORMAT_BIN_OCTET,
    .bCryptoKeyElementPersist = TRUE,
    .eCryptoKeyElementReadAccess = CRYPTO_RA_ALLOWED,
    .eCryptoKeyElementWriteAccess = CRYPTO_WA_ALLOWED,
    .u32CryptoKeyElementSize = 66,
    .pCryptoElementContent = NULL_PTR,
    .u32CryptoElementWritedSize = 0
};
static Crypto_KeyElementType Key_Element_29 = {
    .u32CryptoKeyElementId = 1,
    .bCryptoKeyElementAllowPartialAccess = TRUE,
    .eCryptoKeyElementFormatType = CRYPTO_KE_FORMAT_BIN_OCTET,
    .bCryptoKeyElementPersist = TRUE,
    .eCryptoKeyElementReadAccess = CRYPTO_RA_ALLOWED,
    .eCryptoKeyElementWriteAccess = CRYPTO_WA_ALLOWED,
    .u32CryptoKeyElementSize = 132,
    .pCryptoElementContent = NULL_PTR,
    .u32CryptoElementWritedSize = 0
};

P2VAR(Crypto_KeyElementType, AUTOMATIC, CRYPTO_VAR) aElementList[CRYPTO_KEY_ELEMENT_NUM] = {
    &Key_Element_0,
    &Key_Element_1,
    &Key_Element_2,
    &Key_Element_3,
    &Key_Element_4,
    &Key_Element_5,
    &Key_Element_6,
    &Key_Element_7,
    &Key_Element_8,
    &Key_Element_9,
    &Key_Element_10,
    &Key_Element_11,
    &Key_Element_12,
    &Key_Element_13,
    &Key_Element_14,
    &Key_Element_15,
    &Key_Element_16,
    &Key_Element_17,
    &Key_Element_18,
    &Key_Element_19,
    &Key_Element_20,
    &Key_Element_21,
    &Key_Element_22,
    &Key_Element_23,
    &Key_Element_24,
    &Key_Element_25,
    &Key_Element_26,
    &Key_Element_27,
    &Key_Element_28,
    &Key_Element_29,
};
#define CRYPTO_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CONST_UNSPECIFIED
#include "Crypto_MemMap.h"
/*Used Key Type*/
static const uint32 Key0_ElementTypes[2] = {4,8,};
static const uint32 Key1_ElementTypes[3] = {5,9,10,};
static const uint32 Key2_ElementTypes[2] = {5,0,};
static const uint32 Key3_ElementTypes[1] = {12,};
static const uint32 Key4_ElementTypes[1] = {13,};
static const uint32 Key5_ElementTypes[1] = {14,};
static const uint32 Key6_ElementTypes[1] = {15,};
static const uint32 Key7_ElementTypes[1] = {16,};
static const uint32 Key8_ElementTypes[1] = {17,};
static const uint32 Key9_ElementTypes[1] = {22,};
static const uint32 Key10_ElementTypes[1] = {23,};
static const uint32 Key11_ElementTypes[1] = {28,};
static const uint32 Key12_ElementTypes[1] = {29,};
#define CRYPTO_STOP_SEC_CONST_UNSPECIFIED
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Crypto_MemMap.h"
/* key List */
/*zero key*/
Crypto_KeyType Key;
#define CRYPTO_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_VAR_INIT_UNSPECIFIED
#include "Crypto_MemMap.h"
Crypto_KeyType Key_0 = {
    .u32CryptoKeyId = 1,
    .u32CryptoKeyDeriveIterations = 1,
    .bCryptoKeyValid = FALSE,
    .u32ElementsNum = 2,
    .u32CryptoKeyElements = Key0_ElementTypes,
    .CryptoKeyType = CRYPTO_KEYTYPE_SKE_KEY_256,
    .u32CryptoKeyPairId = 1,
    .CryptoHSMKeyType = CMD_KEY_EXTERNAL_CIPHERTEXT
};
Crypto_KeyType Key_1 = {
    .u32CryptoKeyId = 2,
    .u32CryptoKeyDeriveIterations = 1,
    .bCryptoKeyValid = FALSE,
    .u32ElementsNum = 3,
    .u32CryptoKeyElements = Key1_ElementTypes,
    .CryptoKeyType = CRYPTO_KEYTYPE_SKE_KEY_256,
    .u32CryptoKeyPairId = 1,
    .CryptoHSMKeyType = CMD_KEY_EXTERNAL_CIPHERTEXT
};
Crypto_KeyType Key_2 = {
    .u32CryptoKeyId = 3,
    .u32CryptoKeyDeriveIterations = 1,
    .bCryptoKeyValid = FALSE,
    .u32ElementsNum = 2,
    .u32CryptoKeyElements = Key2_ElementTypes,
    .CryptoKeyType = CRYPTO_KEYTYPE_MAC_KEY,
    .u32CryptoKeyPairId = 1,
    .CryptoHSMKeyType = CMD_KEY_EXTERNAL_CIPHERTEXT
};
Crypto_KeyType Key_3 = {
    .u32CryptoKeyId = 4,
    .u32CryptoKeyDeriveIterations = 1,
    .bCryptoKeyValid = FALSE,
    .u32ElementsNum = 1,
    .u32CryptoKeyElements = Key3_ElementTypes,
    .CryptoKeyType = CRYPTO_KEYTYPE_RSA1024_PRI,
    .u32CryptoKeyPairId = 5,
    .CryptoHSMKeyType = CMD_KEY_EXTERNAL_CIPHERTEXT
};
Crypto_KeyType Key_4 = {
    .u32CryptoKeyId = 5,
    .u32CryptoKeyDeriveIterations = 1,
    .bCryptoKeyValid = FALSE,
    .u32ElementsNum = 1,
    .u32CryptoKeyElements = Key4_ElementTypes,
    .CryptoKeyType = CRYPTO_KEYTYPE_RSA1024_PUB,
    .u32CryptoKeyPairId = 4,
    .CryptoHSMKeyType = CMD_KEY_EXTERNAL_CIPHERTEXT
};
Crypto_KeyType Key_5 = {
    .u32CryptoKeyId = 6,
    .u32CryptoKeyDeriveIterations = 1,
    .bCryptoKeyValid = FALSE,
    .u32ElementsNum = 1,
    .u32CryptoKeyElements = Key5_ElementTypes,
    .CryptoKeyType = CRYPTO_KEYTYPE_RSA2048_PRI,
    .u32CryptoKeyPairId = 7,
    .CryptoHSMKeyType = CMD_KEY_EXTERNAL_CIPHERTEXT
};
Crypto_KeyType Key_6 = {
    .u32CryptoKeyId = 7,
    .u32CryptoKeyDeriveIterations = 1,
    .bCryptoKeyValid = FALSE,
    .u32ElementsNum = 1,
    .u32CryptoKeyElements = Key6_ElementTypes,
    .CryptoKeyType = CRYPTO_KEYTYPE_RSA2048_PUB,
    .u32CryptoKeyPairId = 6,
    .CryptoHSMKeyType = CMD_KEY_EXTERNAL_CIPHERTEXT
};
Crypto_KeyType Key_7 = {
    .u32CryptoKeyId = 8,
    .u32CryptoKeyDeriveIterations = 1,
    .bCryptoKeyValid = FALSE,
    .u32ElementsNum = 1,
    .u32CryptoKeyElements = Key7_ElementTypes,
    .CryptoKeyType = CRYPTO_KEYTYPE_RSA4096_PRI,
    .u32CryptoKeyPairId = 9,
    .CryptoHSMKeyType = CMD_KEY_EXTERNAL_CIPHERTEXT
};
Crypto_KeyType Key_8 = {
    .u32CryptoKeyId = 9,
    .u32CryptoKeyDeriveIterations = 1,
    .bCryptoKeyValid = FALSE,
    .u32ElementsNum = 1,
    .u32CryptoKeyElements = Key8_ElementTypes,
    .CryptoKeyType = CRYPTO_KEYTYPE_RSA4096_PUB,
    .u32CryptoKeyPairId = 8,
    .CryptoHSMKeyType = CMD_KEY_EXTERNAL_CIPHERTEXT
};
Crypto_KeyType Key_9 = {
    .u32CryptoKeyId = 10,
    .u32CryptoKeyDeriveIterations = 1,
    .bCryptoKeyValid = FALSE,
    .u32ElementsNum = 1,
    .u32CryptoKeyElements = Key9_ElementTypes,
    .CryptoKeyType = CRYPTO_KEYTYPE_RSA4096_PRI,
    .u32CryptoKeyPairId = 11,
    .CryptoHSMKeyType = CMD_KEY_EXTERNAL_CIPHERTEXT
};
Crypto_KeyType Key_10 = {
    .u32CryptoKeyId = 11,
    .u32CryptoKeyDeriveIterations = 1,
    .bCryptoKeyValid = FALSE,
    .u32ElementsNum = 1,
    .u32CryptoKeyElements = Key10_ElementTypes,
    .CryptoKeyType = CRYPTO_KEYTYPE_RSA4096_PUB,
    .u32CryptoKeyPairId = 10,
    .CryptoHSMKeyType = CMD_KEY_EXTERNAL_CIPHERTEXT
};
Crypto_KeyType Key_11 = {
    .u32CryptoKeyId = 12,
    .u32CryptoKeyDeriveIterations = 1,
    .bCryptoKeyValid = FALSE,
    .u32ElementsNum = 1,
    .u32CryptoKeyElements = Key11_ElementTypes,
    .CryptoKeyType = CRYPTO_KEYTYPE_P521_PRI,
    .u32CryptoKeyPairId = 13,
    .CryptoHSMKeyType = CMD_KEY_EXTERNAL_CIPHERTEXT
};
Crypto_KeyType Key_12 = {
    .u32CryptoKeyId = 13,
    .u32CryptoKeyDeriveIterations = 1,
    .bCryptoKeyValid = FALSE,
    .u32ElementsNum = 1,
    .u32CryptoKeyElements = Key12_ElementTypes,
    .CryptoKeyType = CRYPTO_KEYTYPE_P521_PUB,
    .u32CryptoKeyPairId = 12,
    .CryptoHSMKeyType = CMD_KEY_EXTERNAL_CIPHERTEXT
};

P2VAR(Crypto_KeyType, AUTOMATIC, CRYPTO_VAR) aKeyList[CRYPTO_KEY_LIST_NUM] = {
    &Key,
    &Key_0,
    &Key_1,
    &Key_2,
    &Key_3,
    &Key_4,
    &Key_5,
    &Key_6,
    &Key_7,
    &Key_8,
    &Key_9,
    &Key_10,
    &Key_11,
    &Key_12};
#define CRYPTO_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Crypto_MemMap.h"

#ifdef __cplusplus
}
#endif
