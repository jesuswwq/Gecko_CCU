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
 * @file  Crypto_DerParser.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Crypto
 */

#ifndef CRYPTO_DER_PARSER_H
#define CRYPTO_DER_PARSER_H

#ifdef __cplusplus
extern "C" {
#endif
//#include "param.h"
#include "arch.h"
#include "Hsm_Types.h"

#ifndef ROUNDUP
#define ROUNDUP(a, b) (((a) + (uint32)((b)-1)) & (uint32)~((b)-1))
#endif

/*Tag type*/
#define CRYPTO_ASN1_BOOLEAN                 0x01
#define CRYPTO_ASN1_INTEGER                 0x02
#define CRYPTO_ASN1_BIT_STRING              0x03
#define CRYPTO_ASN1_OCTET_STRING            0x04
#define CRYPTO_ASN1_NULL                    0x05
#define CRYPTO_ASN1_OID                     0x06
#define CRYPTO_ASN1_UTF8_STRING             0x0C
#define CRYPTO_ASN1_SEQUENCE                0x10
#define CRYPTO_ASN1_SET                     0x11
#define CRYPTO_ASN1_PRINTABLE_STRING        0x13
#define CRYPTO_ASN1_T61_STRING              0x14
#define CRYPTO_ASN1_IA5_STRING              0x16
#define CRYPTO_ASN1_UTC_TIME                0x17


#define CRYPTO_ASN1_GENERALIZED_TIME        0x18
#define CRYPTO_ASN1_UNIVERSAL_STRING        0x1C
#define CRYPTO_ASN1_BMP_STRING              0x1E
/**/
#define CRYPTO_ASN1_CONSTRUCTED             (0x20)

/*Class Type*/
#define CRYPTO_ASN1_UNIVERSAL               (0x00)
#define CRYPTO_ASN1_APPLICATION             (0x40)
#define CRYPTO_ASN1_CONTEXT_SPECIFIC        (0x80)
#define CRYPTO_ASN1_PRIVATE                 (0xC0)

/*Error Type*/
#define CRYPTO_ERR_ASN1_OUT_OF_RANGE        (0x10u)

/*Class Type*/
#define CRYPTO_ASN1_PKCS1_KEYTYPE_PRIKEY    (0x00)
#define CRYPTO_ASN1_PKCS1_KEYTYPE_PUBKEY    (0x01)

Std_ReturnType Crypto_Parse_PKCS1_KEYMODULUSLEN
(
    const uint8 **pKey,
    const uint8 *end,
    uint8 keytype,
    uint32 *modulusLen
);

Std_ReturnType Crypto_Parse_PKCS1_PUBKEY
(
    const uint8 **pKey,
    const uint8 *end,
    RSAKey_Ext_Sdrv *rsa_key
);

Std_ReturnType Crypto_Parse_PKCS1_PRIKEY
(
    const uint8 **pKey,
    const uint8 *end,
    RSAKey_Ext_Sdrv *rsa_key
);

#ifdef __cplusplus
}
#endif
#endif /* CRYPTO_DER_PARSER_H */
