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
 * @file  Crypto.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Crypto
 */

#ifndef CRYPTO_H
#define CRYPTO_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Crypto_Cfg.h"
#include "Crypto_Types.h"
#include "Crypto_KeyManagement.h"

/* Runtime Error */
#define CRYPTO_E_RE_SMALL_BUFFER        (0x00u)
#define CRYPTO_E_RE_KEY_NOT_AVAILABLE   (0x01u)
#define CRYPTO_E_RE_KEY_READ_FAIL       (0x02u)
#define CRYPTO_E_RE_ENTROPY_EXHAUSTED   (0x03u)

/* Development Error */
#define CRYPTO_E_UNINIT             (0x00u)
#define CRYPTO_E_INIT_FAILED        (0x01u)
#define CRYPTO_E_PARAM_POINTER      (0x02u)
#define CRYPTO_E_PARAM_HANDLE       (0x04u)
#define CRYPTO_E_PARAM_VALUE        (0x05u)

/*Vendor Def Error Code*/
#define CRYPTO_E_ALGO_UNSUPPORT         (0x50u)
#define CRYPTO_E_SHARE_MEM_RUN_OUT      (0x51u)
#define CRYPTO_E_SHARE_MEM_SMALL        (0x52u)
#define CRYPTO_E_KEY_INSTALL_FAIL       (0x53u)

#define CRYPTO_MODULE_ID                (114u)
#define CRYPTO_INSTANCE_ID              (1u)

/* Service ID */
#define CRYPTO_INIT_ID                      (0x00u)
#define CRYPTO_PROCESS_JOB_ID               (0x03u)
#define CRYPTO_PROCESS_CANCEL_JOB_ID        (0x0eu)
#define CRYPTO_GET_VERSION_INFO_ID          (0x01u)
#define CRYPTO_KEY_ELEMENT_SET_ID           (0x04u)
#define CRYPTO_KEY_SET_VALID_ID             (0x05u)
#define CRYPTO_KEY_VALID_SET_ID             (0x05u)
#define CRYPTO_KEY_ELEMENT_GET_ID           (0x06u)
#define CRYPTO_KEY_ELEMENT_COPY_ID          (0x0fu)
#define CRYPTO_KEY_COPY_ID                  (0x10u)
#define CRYPTO_KEY_ELEMENT_IDS_GET_ID       (0x11u)
#define CRYPTO_RANDOM_SEED_ID               (0x0du)
#define CRYPTO_KEY_GENERATE_ID              (0x07u)
#define CRYPTO_KEY_DERIVE_ID                (0x08u)
#define CRYPTO_KEY_EXCHANGE_CALC_PUB_ID     (0x09u)
#define CRYPTO_KEY_EXCHANGE_CALC_SECRET_ID  (0x0Au)
#define CERTIFICATE_PARSE_ID                (0x0Bu)
#define CERTIFICATE_VERIFY_ID               (0x12u)
#define CRYPTO_MAIN_FUNCTION_ID             (0x0cu)


#define CRYPTO_MAX_DRIVER_OBJ_NUM           (4u)


#if ( CRYPTO_VERSION_INFO_API == STD_ON )
/**
 * @brief Get the Crypto module version
 * @details Get version
 * @param[out]  version
 * @return   none
*/
FUNC(void, CRYPTO_CODE) Crypto_GetVersionInfo
(
    P2VAR( Std_VersionInfoType, AUTOMATIC, CRYPTO_APPL_DATA ) pVersioninfo
);
#endif  /* CRYPTO_VERSION_INFO_API == STD_ON */

/**
 * @brief Execute the crypto algo.
 * @details Start to handle the crypto job.
 * @param[in]  u32ObjectId The driver object ID
 * @param[in]  pJob Pointer to job.
 * @return     E_OK/E_NOT_OK
*/
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_ProcessJob
(
    VAR(uint32, AUTOMATIC) u32ObjectId,
    Crypto_JobType *pJob
);

/**
 * @brief Delete the job in queue.
 * @details delete the job which not handled.
 * @param[in]  u32ObjectId The driver object ID
 * @param[in]  pJob Pointer to job.
 * @return   E_OK/E_NOT_OK
*/
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_CancelJob
(
    VAR(uint32, AUTOMATIC) u32ObjectId,
    P2VAR(Crypto_JobInfoType, CSM_VAR, CSM_APPL_CONST) pJob
);

/**
 * @brief Initializes the Crypto_Init driver
 * @details Init
 * @return none
*/
FUNC(void, CRYPTO_CODE) Crypto_Init
(
    void
);

/**
 * @brief Crypto_MainFunction
 * @details not support
 * @param[in]  none
 * @return     none
*/
FUNC(void, CRYPTO_CODE) Crypto_MainFunction( void );

/**
 * @brief Certificate Parse
 * @details not support
 * @param[in]  u32CryptoKeyId key id
 * @return   E_OK/E_NOT_OK
*/
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_CertificateParse
(
    VAR(uint32, AUTOMATIC) u32CryptoKeyId
);

/**
 * @brief Certificate Verify
 * @details not support
 * @param[in]  u32CryptoKeyId
 * @param[in]  u32VerifyCryptoKeyId
 * @param[out]  pVerifyPtr verify result
 * @return     E_OK/E_NOT_OK
*/
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_CertificateVerify
(
    VAR(uint32, AUTOMATIC) u32CryptoKeyId,
    VAR(uint32, AUTOMATIC) u32VerifyCryptoKeyId,
    P2VAR(Crypto_VerifyResultType, AUTOMATIC, CRYPTO_APPL_DATA) pVerifyPtr
);

/**
 * @brief Set the key element
 * @details Set the key element
 * @param[in]  u32CryptoKeyId
 * @param[in]  u32KeyElementId  Element ID
 * @param[in]  pKeyPtr          Pointer to element content
 * @param[in]  u32KeyLength     Element length
 * @return   none
*/
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_KeyElementSet
(
    VAR(uint32, AUTOMATIC) u32CryptoKeyId,
    VAR(uint32, AUTOMATIC) u32KeyElementId,
    P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_CONST) pKeyPtr,
    VAR(uint32, AUTOMATIC) u32KeyLength
);

/**
 * @brief Change the key state to valid
 * @details If any elements was changed, the key will be invalidated.
 * @param[in]  u32CryptoKeyId
 * @return   E_OK/E_NOT_OK
*/
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_KeySetValid
(
    VAR(uint32, AUTOMATIC) u32CryptoKeyId
);

/**
 * @brief Get a element of the key
 * @details Get a element of the key
 * @param[in]  u32CryptoKeyId
 * @param[in]  u32KeyElementId
 * @param[out]  pResultPtr
 * @param[out]  pResultLengthPtr
 * @return   E_OK/E_NOT_OK
*/
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_KeyElementGet
(
    VAR(uint32, AUTOMATIC) u32CryptoKeyId,
    VAR(uint32, AUTOMATIC) u32KeyElementId,
    P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pResultPtr,
    P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pResultLengthPtr
);

/**
 * @brief Copy a element to other key
 * @details Copy a element to other key
 * @param[in]  u32CryptoKeyId
 * @param[in]  u32KeyElementId
 * @param[in]  u32TargetCryptoKeyId
 * @param[in]  u32TargetKeyElementId
 * @return   E_OK/E_NOT_OK
*/
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_KeyElementCopy
(
    VAR(uint32, AUTOMATIC) u32CryptoKeyId,
    VAR(uint32, AUTOMATIC) u32KeyElementId,
    VAR(uint32, AUTOMATIC) u32TargetCryptoKeyId,
    VAR(uint32, AUTOMATIC) u32TargetKeyElementId
);

/**
 * @brief Copy key content to other key
 * @details Copy key content to other key
 * @param[in]  u32CryptoKeyId
 * @param[in]  u32TargetCryptoKeyId
 * @return   E_OK/E_NOT_OK
*/
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_KeyCopy
(
    VAR(uint32, AUTOMATIC) u32CryptoKeyId,
    VAR(uint32, AUTOMATIC) u32TargetCryptoKeyId
);

/**
 * @brief Get multi elements from the key
 * @details Get multi elements from the key
 * @param[in]   u32CryptoKeyId
 * @param[in]   pKeyElementIdsLengthPtr
 * @param[out]  pKeyElementIdsPtr
 * @return   E_OK/E_NOT_OK
*/
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_KeyElementIdsGet
(
    VAR(uint32, AUTOMATIC) u32CryptoKeyId,
    P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pKeyElementIdsPtr,
    P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pKeyElementIdsLengthPtr
);

/**
 * @brief Generate the random seed
 * @details not needed, hardware random number generator
 * @param[in]  u32CryptoKeyId
 * @param[out]  pSeedPtr
 * @param[in]  u32SeedLength
 * @return   E_OK/E_NOT_OK
*/
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_RandomSeed
(
    VAR(uint32, AUTOMATIC) u32CryptoKeyId,
    P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_CONST) pSeedPtr,
    VAR(uint32, AUTOMATIC) u32SeedLength
);

/**
 * @brief Generate the key
 * @details Only support generating the sym key.
 * @param[in]  u32CryptoKeyId
 * @return   E_OK/E_NOT_OK
*/
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_KeyGenerate
(
    VAR(uint32, AUTOMATIC) u32CryptoKeyId
);

/**
 * @brief Derive the key
 * @details not support currently.
 * @param[in]  u32CryptoKeyId
 * @param[in]  u32TargetCryptoKeyId
 * @return   E_OK/E_NOT_OK
*/
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_KeyDerive
(
    VAR(uint32, AUTOMATIC) u32CryptoKeyId,
    VAR(uint32, AUTOMATIC) u32TargetCryptoKeyId
);

/**
 * @brief store allkey on flash
 * @details not support currently.
 * @param[in]  Crypto_UsrCallOut_Sync
 * @return   E_OK/E_NOT_OK
*/
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_KeyElementSync
(
    Std_ReturnType (*Crypto_UsrCallOut_Sync)(uint8 *pKeyBlobPtr)
);

/**
 * @brief Erase allkey store on flash
 * @details not support currently.
 * @param[in]  Crypto_UsrCallOut_Erase
 * @return   E_OK/E_NOT_OK
*/
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_KeyElementErase
(
    Std_ReturnType (*Crypto_UsrCallOut_Erase)(void)
);

/**
 * @brief key exchange(get public key)
 * @details not support currently.
 * @param[in]  u32CryptoKeyId
 * @param[out]  pPublicValuePtr
 * @param[out]  pPublicValuePtr
 * @return   E_OK/E_NOT_OK
*/
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_KeyExchangeCalcPubVal
(
    VAR(uint32, AUTOMATIC) u32CryptoKeyId,
    P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPublicValuePtr,
    P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pPublicValueLengthPtr
);

/**
 * @brief key exchange(get secret key)
 * @details  not support currently.
 * @param[in]  u32CryptoKeyId
 * @param[out]  pPartnerPublicValuePtr
 * @param[out]  u32PartnerPublicValueLength
 * @return    E_OK/E_NOT_OK
*/
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_KeyExchangeCalcSecret
(
    VAR(uint32, AUTOMATIC) u32CryptoKeyId,
    P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_CONST) pPartnerPublicValuePtr,
    VAR(uint32, AUTOMATIC) u32PartnerPublicValueLength
);

#ifdef __cplusplus
}
#endif

#endif /* CRYPTO_H */

