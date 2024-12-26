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
 * @file  Csm_Types.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Crypto
 */

#ifndef CSM_TYPES_H
#define CSM_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif


#include "Mcal.h"


/* Structure which contains job information (job ID and job priority). */
typedef struct {
    CONST (uint32, CSM_CONST) jobId;         /* The family of the algorithm */
    CONST (uint32, CSM_CONST) jobPriority;   /* Specifies the importance of the job (the higher, the more important). */    
} Crypto_JobInfoType;

/* Enumeration of the current job state. */
typedef enum {
    CRYPTO_JOBSTATE_IDLE    = 0x00U,  /* Job is in the state "idle". This state is reached after Csm_Init() or when the "Finish" state is finished. */
    CRYPTO_JOBSTATE_ACTIVE  = 0x01U   /* Job is in the state "active". There was already some input or there are intermediate results. This state is reached, when the "update" or "start" operation  finishes. */
} Crypto_JobStateType;

/* Enumeration of the algorithm mode */
typedef enum {
    CRYPTO_ALGOMODE_NOT_SET = 0x00, /** Algorithm key is not set*/
    CRYPTO_ALGOMODE_ECB     = 0x01, /** Blockmode: Electronic Code Book*/
    CRYPTO_ALGOMODE_CBC     = 0x02, /** Blockmode: Cipher Block Chaining*/
    CRYPTO_ALGOMODE_CFB     = 0x03, /** Blockmode: Cipher Feedback Mode*/
    CRYPTO_ALGOMODE_OFB     = 0x04, /** Blockmode: Output Feedback Mode*/
    CRYPTO_ALGOMODE_CTR     = 0x05, /** Blockmode: Counter Modex*/
    CRYPTO_ALGOMODE_GCM     = 0x06, /** Blockmode: Galois/Counter Mode*/
    CRYPTO_ALGOMODE_XTS     = 0x07, /** XOR-encryption-based tweaked-codebook mode with ciphertext stealing*/
    CRYPTO_ALGOMODE_RSAES_OAEP          = 0x08, /** RSA Optimal Asymmetric Encryption Padding*/
    CRYPTO_ALGOMODE_RSAES_PKCS1_v1_5    = 0x09, /** RSA encryption/decryption with PKCS#1 v1.5 padding*/
    CRYPTO_ALGOMODE_RSASSA_PSS          = 0x0a, /** RSA Probabilistic Signature*/
    CRYPTO_ALGOMODE_RSASSA_PKCS1_v1_5   = 0x0b, /** RSA signature with PKCS#1 v1.5*/
    CRYPTO_ALGOMODE_8ROUNDS             = 0x0c, /** 8 rounds (e.g. ChaCha8)*/
    CRYPTO_ALGOMODE_12ROUNDS            = 0x0d, /** 12 rounds (e.g. ChaCha12)*/
    CRYPTO_ALGOMODE_20ROUNDS            = 0x0e, /** 20 rounds (e.g. ChaCha20)*/
    CRYPTO_ALGOMODE_HMAC                = 0x0f, /** Hashed-based MAC*/
    CRYPTO_ALGOMODE_CMAC                = 0x10, /** Cipher-based MAC*/
    CRYPTO_ALGOMODE_GMAC                = 0x11, /** Galois MAC*/
    CRYPTO_ALGOMODE_CTRDRBG             = 0x12, /** Counter-based Deterministic Random Bit Generator*/
    CRYPTO_ALGOMODE_SIPHASH_2_4         = 0x13, /** Siphash-2-4*/
    CRYPTO_ALGOMODE_SIPHASH_4_8         = 0x14, /** Siphash-4-8*/
    CRYPTO_ALGOMODE_CUSTOM              = 0xff  /** Custom algorithm mode*/
} Crypto_AlgorithmModeType;

/* Enumeration of the result type of verification operations. */
typedef enum {
    CRYPTO_E_VER_OK          = 0x00U,    /* The result of the verification is "true", i.e. the two compared elements are identical. This return code shall be given as value "0" */
    CRYPTO_E_VER_NOT_OK      = 0x01U     /* The result of the verification is "false", i.e. the two compared elements are not identical. This return code shall be given as value "1". */
} Crypto_VerifyResultType;

/* Indicator of the mode(s)/operation(s) to be performed. Enumeration which operation shall be performed.
   This enumeration is constructed from a bit mask, where the first bit indicates "Start", the second "Update" and the third "Finish".*/
typedef enum {
    CRYPTO_OPERATIONMODE_START           = 0x01U, /* Operation Mode is "Start". The job's state shall be reset, i.e. previous input data and intermediate results shall be deleted. */
    CRYPTO_OPERATIONMODE_UPDATE          = 0x02U, /* Operation Mode is "Update". Used to calculate intermediate results. */
    CRYPTO_OPERATIONMODE_STREAMSTART     = 0x03U, /* Operation Mode is "Stream Start". Mixture of "Start" and "Update". Used for streaming. */
    CRYPTO_OPERATIONMODE_FINISH          = 0x04U, /* Operation Mode is "Finish". The calculations shall be finalized */
    CRYPTO_OPERATIONMODE_SINGLECALL      = 0x07U  /* Operation Mode is "Single Call". Mixture of "Start", "Update" and "Finish". */
} Crypto_OperationModeType;

/**
 * @enum Crypto_ServiceInfoType
 * @brief Enumeration of the kind of the service.
*/
typedef enum {
    CRYPTO_HASH                 = 0x00U,  /* Hash Service */

    CRYPTO_MACGENERATE          = 0x01U,  /* MacGenerate Service */
    CRYPTO_MACVERIFY            = 0x02U,  /* MacVerify Service */ 

    CRYPTO_ENCRYPT              = 0x03U,  /* Encrypt Service */
    CRYPTO_DECRYPT              = 0x04U,  /* Decrypt Service */

    CRYPTO_AEADENCRYPT          = 0x05U,  /* AEADEncrypt Service */
    CRYPTO_AEADDECRYPT          = 0x06U,  /* AEADDecrypt Service */

    CRYPTO_SIGNATUREGENERATE    = 0x07U,  /* SignatureGenerate Service */
    CRYPTO_SIGNATUREVERIFY      = 0x08U,  /* SignatureVerify Service */

    CRYPTO_SECCOUNTERINCREMENT  = 0x09U,  /* SecureCounterIncrement Service */
    CRYPTO_SECCOUNTERREAD       = 0x0AU,  /* SecureCounterRead Service */

    CRYPTO_RANDOMGENERATE       = 0x0BU   /* RandomGenerate Service */
} Crypto_ServiceInfoType;

/* The family of the algorithm */
typedef enum {
    CRYPTO_ALGOFAM_NOT_SET      = 0x00U,
    CRYPTO_ALGOFAM_SHA1         = 0x01U,
    CRYPTO_ALGOFAM_SHA2_224     = 0x02U,
    CRYPTO_ALGOFAM_SHA2_256     = 0x03U,
    CRYPTO_ALGOFAM_SHA2_384     = 0x04U,
    CRYPTO_ALGOFAM_SHA2_512     = 0x05U,
    CRYPTO_ALGOFAM_SHA2_512_224 = 0x06U,
    CRYPTO_ALGOFAM_SHA2_512_256 = 0x07U,
    CRYPTO_ALGOFAM_SHA3_224     = 0x08U, /*not support*/
    CRYPTO_ALGOFAM_SHA3_256     = 0x09U, /*not support*/
    CRYPTO_ALGOFAM_SHA3_384     = 0x0AU, /*not support*/
    CRYPTO_ALGOFAM_SHA3_512     = 0x0BU, /*not support*/
    CRYPTO_ALGOFAM_SHAKE128     = 0x0CU, /*not support*/
    CRYPTO_ALGOFAM_SHAKE256     = 0x0DU, /*not support*/
    CRYPTO_ALGOFAM_RIPEMD160    = 0x0EU, /*not support*/
    CRYPTO_ALGOFAM_BLAKE_1_256  = 0x0FU, /*not support*/
    CRYPTO_ALGOFAM_BLAKE_1_512  = 0x10U, /*not support*/
    CRYPTO_ALGOFAM_BLAKE_2s_256 = 0x11U, /*not support*/
    CRYPTO_ALGOFAM_BLAKE_2s_512 = 0x12U, /*not support*/
    CRYPTO_ALGOFAM_3DES         = 0x13U, /*not support*/
    CRYPTO_ALGOFAM_AES          = 0x14U, /* AES-128/192/256 */
    CRYPTO_ALGOFAM_CHACHA       = 0x15U, /*not support*/
    CRYPTO_ALGOFAM_RSA          = 0x16U,
    CRYPTO_ALGOFAM_ED25519      = 0x17U,
    CRYPTO_ALGOFAM_BRAINPOOL    = 0x18U,
    CRYPTO_ALGOFAM_ECCNIST      = 0x19U,
    CRYPTO_ALGOFAM_SECURECOUNTER= 0x1AU,
    CRYPTO_ALGOFAM_RNG          = 0x1BU,
    CRYPTO_ALGOFAM_SIPHASH      = 0x1CU,
    CRYPTO_ALGOFAM_ECIES        = 0x1DU,
    CRYPTO_ALGOFAM_CUSTOM       = 0xFFU,
    CRYPTO_ALGOFAM_SM2          = 0x020U,
    CRYPTO_ALGOFAM_SM3          = 0x021U,
    CRYPTO_ALGOFAM_SM4          = 0x022U,
} Crypto_AlgorithmFamilyType;

/* Structure containing input and output information depending on the job and the crypto primitive. */
typedef struct {
    P2CONST (uint8, AUTOMATIC, CSM_APPL_CONST) inputPtr;                 /* Pointer to the input data. */
    VAR (uint32, AUTOMATIC) inputLength;                                 /* Contains the input length in bytes. */
    P2CONST (uint8, AUTOMATIC, CSM_APPL_CONST) secondaryInputPtr;        /* Pointer to the secondary input data (for MacVerify, SignatureVerify). */
    VAR (uint32, AUTOMATIC) secondaryInputLength;                        /* Contains the secondary input length in bytes. */
    P2CONST (uint8, AUTOMATIC, CSM_APPL_CONST) tertiaryInputPtr;         /* Pointer to the tertiary input data (for MacVerify, SignatureVerify). */
    VAR (uint32, AUTOMATIC) tertiaryInputLength;                         /* Contains the tertiary input length in bytes. */
    P2VAR (uint8, AUTOMATIC, CSM_APPL_DATA) outputPtr;                   /* Pointer to the output data. */
    P2VAR (uint32, AUTOMATIC, CSM_APPL_DATA) outputLengthPtr;            /* Holds a pointer to a memory location containing the output length in bytes. */
    P2VAR (uint8, AUTOMATIC, CSM_APPL_DATA) secondaryOutputPtr;          /* Pointer to the secondary output data. */
    P2VAR (uint32, AUTOMATIC, CSM_APPL_DATA) secondaryOutputLengthPtr;   /* Holds a pointer to a memory location containing the secondary output length in bytes. */
    VAR (uint64, AUTOMATIC) input64;                                     /* Versatile input parameter */
    P2VAR (Crypto_VerifyResultType, AUTOMATIC, CSM_APPL_DATA) verifyPtr; /* Output pointer to a memory location holding a Crypto_VerifyResultType */
    P2VAR (uint64, AUTOMATIC, CSM_APPL_DATA) output64Ptr;                /* Output pointer to a memory location holding an uint64. */
    VAR (Crypto_OperationModeType, AUTOMATIC) mode;                      /* Indicator of the mode(s)/operation(s) to be performed */  
} Crypto_JobPrimitiveInputOutputType;

/* Structure which determines the exact algorithm. Note, not every algorithm needs to specify all fields. AUTOSAR shall only allow valid combinations. */
typedef struct {
    VAR (Crypto_AlgorithmFamilyType, AUTOMATIC) family;           /* The family of the algorithm */
    VAR (Crypto_AlgorithmFamilyType, AUTOMATIC) secondaryFamily;  /* The secondary family of the algorithm  */
    VAR (uint32, AUTOMATIC) keyLength;                            /* The key length in bits to be used with that algorithm */
    VAR (Crypto_AlgorithmModeType, AUTOMATIC) mode;               /* The operation mode to be used with that algorithm */
} Crypto_AlgorithmInfoType;

/* Structure which contains basic information about the crypto primitive. */
typedef struct {
    CONST (uint32, CSM_CONST) resultLength;                  /* Contains the result length in bytes. */
    CONST (Crypto_ServiceInfoType, CSM_CONST) service;       /* Contains the enum of the used service, e.g. Encrypt */
    CONST (Crypto_AlgorithmInfoType, CSM_CONST) algorithm;   /* Contains the information of the used algorithm */
} Crypto_PrimitiveInfoType;

/* Enumeration of the processing type. */
typedef enum {
    CRYPTO_PROCESSING_ASYNC     = 0x00U,    /* Asynchronous job processing */
    CRYPTO_PROCESSING_SYNC      = 0x01U     /* Synchronous job processing */
} Crypto_ProcessingType;

/* Structure which contains further information, which depends on the job and the crypto primitive. */
typedef struct 
{
    CONST (uint32, CSM_CONST) callbackId;                                       /* Identifier of the callback function, to be called, if the configured service finished. */
    P2CONST (Crypto_PrimitiveInfoType, CSM_VAR, CSM_APPL_CONST) primitiveInfo;  /* Pointer to a structure containing further configuration of the crypto primitives */    
    CONST (uint32, CSM_CONST) secureCounterId;                                  /* Identifier of a secure counter. */
    CONST (uint32, CSM_CONST) cryIfKeyId;                                       /* Identifier of the CryIf key. */
    CONST (Crypto_ProcessingType, CSM_CONST) processingType;                    /* Determines the synchronous or asynchronous behavior. */
    CONST (boolean, CSM_CONST) callbackUpdateNotification;                      /* Indicates, whether the callback function shall be called, if the UPDATE operation has finished. */
} Crypto_JobPrimitiveInfoType;

/* Structure which contains further information, which depends on the job and the crypto primitive  */
typedef struct {
    VAR (uint32, AUTOMATIC) jobId;                                                    /* identifier for the job structure */
    VAR (Crypto_JobStateType, AUTOMATIC) jobState;                                      /* determines the current job state */
    VAR (Crypto_JobPrimitiveInputOutputType, AUTOMATIC) jobPrimitiveInputOutput;        /* structure containing input and output information depending on the job and the crypto primitive */
    P2CONST (Crypto_JobPrimitiveInfoType, CSM_VAR, CSM_APPL_CONST) jobPrimitiveInfo;    /* pointer to a structure containing further information, which depends on the job and the crypto primitive */
    P2CONST (Crypto_JobInfoType, CSM_VAR, CSM_APPL_CONST) jobInfo;                      /* pointer to a structure containing further information, which depends on the job and the crypto primitive */
    VAR (uint32, AUTOMATIC) cryptoKeyId;                                                /* identifier of the Crypto Driver key. The identifier shall be written by the Crypto Interface */
} Crypto_JobType;

/*-----------------key element index definition-[SWS_Csm_01022]----------------*/
/** MAC */
#define CRYPTO_KE_MAC_KEY           (1u)
#define CRYPTO_KE_MAC_PROOF         (2u)

/** Signature */
#define CRYPTO_KE_SIGNATURE_KEY     (1u)

/** Random */
#define CRYPTO_KE_RANDOM_SEED_STATE (3u)
#define CRYPTO_KE_RANDOM_ALGORITHM  (4u)

/** Cipher/AEAD */
#define CRYPTO_KE_CIPHER_KEY        (1u)
#define CRYPTO_KE_CIPHER_IV         (5u)
#define CRYPTO_KE_CIPHER_PROOF      (6u)
#define CRYPTO_KE_CIPHER_2NDKEY     (7u)    /* Second Key material*/

/** Key Exchange */
#define CRYPTO_KE_KEYEXCHANGE_BASE          (8u)
#define CRYPTO_KE_KEYEXCHANGE_PRIVKEY       (9u)
#define CRYPTO_KE_KEYEXCHANGE_OWNPUBKEY     (10u)
#define CYRPTO_KE_KEYEXCHANGE_SHAREDVALUE   (1u)
#define CRYPTO_KE_KEYEXCHANGE_ALGORITHM     (12u)

/** Key Derivation */
#define CRYPTO_KE_KEYDERIVATION_PASSWORD    (1u)
#define CRYPTO_KE_KEYDERIVATION_SALT        (13u)
#define CRYPTO_KE_KEYDERIVATION_ITERATIONS  (14u)
#define CRYPTO_KE_KEYDERIVATION_ALGORITHM   (15u)

/** Key Generate */
#define CRYPTO_KE_KEYGENERATE_KEY           (1u)
#define CRYPTO_KE_KEYGENERATE_SEED          (16u)
#define CRYPTO_KE_KEYGENERATE_ALGORITHM     (17u)

/** Certificate Parsing */
#define CRYPTO_KE_CERTIFICATE_DATA                  (0u)
#define CRYPTO_KE_CERTIFICATE_PARSING_FORMAT        (18u)
#define CRYPTO_KE_CERTIFICATE_CURRENT_TIME          (19u)
#define CRYPTO_KE_CERTIFICATE_VERSION               (20u)
#define CRYPTO_KE_CERTIFICATE_SERIALNUMBER          (21u)
#define CRYPTO_KE_CERTIFICATE_SIGNATURE_ALGORITHM   (22u)
#define CRYPTO_KE_CERTIFICATE_ISSUER                (23u)
#define CRYPTO_KE_CERTIFICATE_VALIDITY_NOT_BEFORE   (24u)
#define CRYPTO_KE_CERTIFICATE_VALIDITY_NOT_AFTER    (25u)
#define CRYPTO_KE_CERTIFICATE_SUBJECT               (26u)
#define CRYPTO_KE_CERTIFICATE_SUBJECT_PUBLIC_KEY    (1u)
#define CRYPTO_KE_CERTIFICATE_EXTENSIONS            (27u)
#define CRYPTO_KE_CERTIFICATE_SIGNATURE             (28u)

#define CRYPTO_E_BUSY                   (0x02u)
#define CRYPTO_E_SMALL_BUFFER           (0x03u)
#define CRYPTO_E_ENTROPY_EXHAUSTED      (0x04u)
#define CRYPTO_E_QUEUE_FULL             (0x05u)
#define CRYPTO_E_KEY_READ_FAIL          (0x06u)
#define CRYPTO_E_KEY_WRITE_FAIL         (0x07u)
#define CRYPTO_E_KEY_NOT_AVAILABLE      (0x08u)
#define CRYPTO_E_KEY_NOT_VALID          (0x09u)
#define CRYPTO_E_KEY_SIZE_MISMATCH      (0x0Au)
#define CRYPTO_E_COUNTER_OVERFLOW       (0x0Bu)
#define CRYPTO_E_JOB_CANCELED           (0x0Cu)

#ifdef __cplusplus
}
#endif

#endif /* #ifndef CSM_TYPES_H */
