/**\file    
 *
 * 128 bit AES encryption and decryption module.
 *
 * Support for encryption and/or decryption is configurable. \n
 * Mode of operation (synchronous or asynchronous) is configurable. \n
 * This module is based on original code from Karl Malbrain,
 * malbrain(a)yahoo.com
 *
 * 
 * \b Application:        AES Encryption Buildingblock \n 
 * \b Module:             aes.c \n 
 * \b File-Revision:      3 \n
 * \b Changeable-by-user: No \n
 * \b Module-Owner:       Achim Berger \n
 * \b Classification:     CONFIDENTIAL \n
 * \n
 * \reqtrace{BRQ_AES.doc}{BRQ_AES_001,
 *                        BRQ_AES_002,
 *                        BRQ_AES_002}                                                                           
 */

/*============================================================================*\
 *                                                                            
 * Copyright 2007 Delphi Controls & Security, All Rights Reserved
 * - except for the public domain algorithm from Karl Malbrain -
 * It is not allowed to reproduce or utilize parts of this document in any form 
 * or by any means, including photocopying and microfilm, without permission in 
 * written by Delphi Electronics & Safety Division.                                                                                   
 *                                                                            
\*============================================================================*/

/*============================================================================*\
 * PREPROCESSOR DIRECTIVES
\*============================================================================*/

/* INCLUDE DIRECTIVES FOR STANDARD HEADERS -----------------------------------*/

/* INCLUDE DIRECTIVES FOR OTHER HEADERS --------------------------------------*/
#include "aes_cf.h"
//#include "aes_if.h"
#include "aes.h"

/* PRQA S 5087 EOF
   QAC warning: #include statements in a file should only be preceded 
                by other preprocessor directives or comments. 
   Caused by MemMap include.
*/



/* Configuration check at compile time ---------------------------------------*/
#if ((AES_OPERATIONMODE != AES_SYNCHRONOUS)&&(AES_OPERATIONMODE != AES_ASYNCHRONOUS))
  #error "No valid AES_OPERATIONMODE defined. Configure either AES_SYNCHRONOUS or AES_ASYNCHRONOUS"
#endif /* ((AES_OPERATIONMODE != AES_SYNCHRONOUS)&&(AES_OPERATIONMODE != AES_ASYNCHRONOUS)) */

#if (AES_OPERATIONMODE == AES_ASYNCHRONOUS)
  #if (AES_EXPANDKEY_ROUNDS_AT_ONCE < 1)
    #error "AES_EXPANDKEY_ROUNDS_AT_ONCE is configured below minimum limit value"
  #endif /* (AES_EXPANDKEY_ROUNDS_AT_ONCE < 1) */

  #if (AES_EXPANDKEY_ROUNDS_AT_ONCE > 40)
    #error "AES_EXPANDKEY_ROUNDS_AT_ONCE is configured above maximum limit value"
  #endif /* (AES_EXPANDKEY_ROUNDS_AT_ONCE > 40) */

  #if (AES_ENCRYPT == AES_ON)
    #if (AES_ENCRYPT_ROUNDS_AT_ONCE < 1)
      #error "AES_ENCRYPT_ROUNDS_AT_ONCE is configured below minimum limit value"
    #endif /* (AES_ENCRYPT_ROUNDS_AT_ONCE < 1) */

    #if (AES_ENCRYPT_ROUNDS_AT_ONCE > 10)
      #error "AES_ENCRYPT_ROUNDS_AT_ONCE is configured above maximum limit value"
    #endif /* (AES_ENCRYPT_ROUNDS_AT_ONCE > 10) */
  #endif /* (AES_ENCRYPT == AES_ON) */

  #if (AES_DECRYPT == AES_ON)
    #if (AES_DECRYPT_ROUNDS_AT_ONCE < 1)
      #error "AES_DECRYPT_ROUNDS_AT_ONCE is configured below minimum limit value"
    #endif /* (AES_DECRYPT_ROUNDS_AT_ONCE < 1) */

    #if (AES_DECRYPT_ROUNDS_AT_ONCE > 10)
      #error "AES_DECRYPT_ROUNDS_AT_ONCE is configured above maximum limit value"
    #endif /* (AES_DECRYPT_ROUNDS_AT_ONCE > 10) */
  #endif /* (AES_DECRYPT == AES_ON) */
#endif /* (AES_OPERATIONMODE == AES_ASYNCHRONOUS) */


/* LOCAL DEFINES FOR CONSTANTS -----------------------------------------------*/

/**
 * Number of columns in the state & expanded key. 
 * AES only supports Nb=4.
 */
#define Nb             (4)

/**
 * Number of columns in a key
 */
#define Nk             (4)

/**
 * Number of rounds for encryption
 */
#define Nr            (10)

/**
 * Number of bytes per column
 */
#define COLUMN_SIZE    (4)

/**
 * Size of Rcon-table
 */
#define RCon_SIZE     (11)

/**
 * Size of the input/output vectors: 128 bit (16 bytes)
 */
#define VECTOR_SIZE   (16)

/**
 * Size of the calculation tables: 256 bytes
 */
#define TABLE_SIZE   (256)


/* LOCAL DEFINE MACROS (#, ##) -----------------------------------------------*/

/*============================================================================*\
 * LOCAL TYPEDEF DECLARATIONS
\*============================================================================*/

/* ENUMS ---------------------------------------------------------------------*/

/**
 * AES Handler State typedef
 */
#if (AES_OPERATIONMODE == AES_ASYNCHRONOUS)
typedef enum AES_HandlerStateTag
{
  AES_EXPANDKEY_SEQ,
#if (AES_ENCRYPT == AES_ON)
  AES_ENCRYPT_SEQ,
#endif /* (AES_ENCRYPT == AES_ON) */
#if (AES_DECRYPT == AES_ON)
  AES_DECRYPT_SEQ,
#endif /* (AES_DECRYPT == AES_ON) */
  AES_IDLE
}AES_HandlerStateType;
#endif /* (AES_OPERATIONMODE == AES_ASYNCHRONOUS) */

/* STRUCTS -------------------------------------------------------------------*/

/* UNIONS --------------------------------------------------------------------*/

/* OTHER TYPEDEFS ------------------------------------------------------------*/
 
/*============================================================================*\
 * OBJECT DEFINITIONS
\*============================================================================*/

/* EXPORTED OBJECTS ----------------------------------------------------------*/

/* LOCAL OBJECTS -------------------------------------------------------------*/

#define AES_START_SEC_CONST_UNSPECIFIED
//#include "MemMap.h"

/**
 * forward s-box
 */
static const aes_uint8 Sbox[TABLE_SIZE] =
{
  0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
  0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
  0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
  0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
  0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
  0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
  0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
  0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
  0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
  0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
  0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
  0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
  0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
  0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
  0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
  0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16
};


/**
 * inverse s-box
 */
#if (AES_DECRYPT == AES_ON)
static const aes_uint8 InvSbox[TABLE_SIZE] =
{
  0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb,
  0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb,
  0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e,
  0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25,
  0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92,
  0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84,
  0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06,
  0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b,
  0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73,
  0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e,
  0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b,
  0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4,
  0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f,
  0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef,
  0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61,
  0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d
};
#endif /* (AES_DECRYPT == AES_ON) */

#define AES_STOP_SEC_CONST_UNSPECIFIED
//#include "MemMap.h"


#define AES_START_SEC_VAR_ZEROINIT_UNSPECIFIED
//#include "MemMap.h"

/**
 * used to store the expanded key 
 */
static aes_uint8 ExpandKeyBuffer[COLUMN_SIZE * Nb * (Nr + 1)];

/**
 * working buffer for encryption and decryption 
 */
static aes_uint8 StateBuffer[Nb * COLUMN_SIZE];

/**
 * used for temporary storage during encryption and decryption
 */
static aes_uint8 Tmp[COLUMN_SIZE * Nb];
#define AES_STOP_SEC_VAR_ZEROINIT_UNSPECIFIED
//#include "MemMap.h"


#if (AES_OPERATIONMODE == AES_ASYNCHRONOUS)
/**
 * AES Handler State for asynchronous operation mode
 */
#define AES_START_SEC_VAR_INIT_UNSPECIFIED
//#include "MemMap.h"
static AES_HandlerStateType AES_HandlerState = AES_IDLE;
#define AES_STOP_SEC_VAR_INIT_UNSPECIFIED
//#include "MemMap.h"

#define AES_START_SEC_VAR_ZEROINIT_UNSPECIFIED
//#include "MemMap.h"
/**
 * Stored Round Counter for asynchronous operation mode
 */
static aes_uint8  Round;

/**
 * Stored Output Pointer for asynchronous operation mode
 */
static aes_uint8* Out_ptr;
#define AES_STOP_SEC_VAR_ZEROINIT_UNSPECIFIED
//#include "MemMap.h"

#endif /* (AES_OPERATIONMODE == AES_ASYNCHRONOUS) */

/******************************************************************************/
/* For local function MixSubColumns:                                          */
/******************************************************************************/
#if (AES_ENCRYPT == AES_ON)
#define AES_START_SEC_CONST_UNSPECIFIED
//#include "MemMap.h"

  /* combined Xtimes2[Sbox[]] */
  static const aes_uint8 Xtime2Sbox[TABLE_SIZE] =
  {
    0xc6, 0xf8, 0xee, 0xf6, 0xff, 0xd6, 0xde, 0x91, 0x60, 0x02, 0xce, 0x56, 0xe7, 0xb5, 0x4d, 0xec,
    0x8f, 0x1f, 0x89, 0xfa, 0xef, 0xb2, 0x8e, 0xfb, 0x41, 0xb3, 0x5f, 0x45, 0x23, 0x53, 0xe4, 0x9b,
    0x75, 0xe1, 0x3d, 0x4c, 0x6c, 0x7e, 0xf5, 0x83, 0x68, 0x51, 0xd1, 0xf9, 0xe2, 0xab, 0x62, 0x2a,
    0x08, 0x95, 0x46, 0x9d, 0x30, 0x37, 0x0a, 0x2f, 0x0e, 0x24, 0x1b, 0xdf, 0xcd, 0x4e, 0x7f, 0xea,
    0x12, 0x1d, 0x58, 0x34, 0x36, 0xdc, 0xb4, 0x5b, 0xa4, 0x76, 0xb7, 0x7d, 0x52, 0xdd, 0x5e, 0x13,
    0xa6, 0xb9, 0x00, 0xc1, 0x40, 0xe3, 0x79, 0xb6, 0xd4, 0x8d, 0x67, 0x72, 0x94, 0x98, 0xb0, 0x85,
    0xbb, 0xc5, 0x4f, 0xed, 0x86, 0x9a, 0x66, 0x11, 0x8a, 0xe9, 0x04, 0xfe, 0xa0, 0x78, 0x25, 0x4b,
    0xa2, 0x5d, 0x80, 0x05, 0x3f, 0x21, 0x70, 0xf1, 0x63, 0x77, 0xaf, 0x42, 0x20, 0xe5, 0xfd, 0xbf,
    0x81, 0x18, 0x26, 0xc3, 0xbe, 0x35, 0x88, 0x2e, 0x93, 0x55, 0xfc, 0x7a, 0xc8, 0xba, 0x32, 0xe6,
    0xc0, 0x19, 0x9e, 0xa3, 0x44, 0x54, 0x3b, 0x0b, 0x8c, 0xc7, 0x6b, 0x28, 0xa7, 0xbc, 0x16, 0xad,
    0xdb, 0x64, 0x74, 0x14, 0x92, 0x0c, 0x48, 0xb8, 0x9f, 0xbd, 0x43, 0xc4, 0x39, 0x31, 0xd3, 0xf2,
    0xd5, 0x8b, 0x6e, 0xda, 0x01, 0xb1, 0x9c, 0x49, 0xd8, 0xac, 0xf3, 0xcf, 0xca, 0xf4, 0x47, 0x10,
    0x6f, 0xf0, 0x4a, 0x5c, 0x38, 0x57, 0x73, 0x97, 0xcb, 0xa1, 0xe8, 0x3e, 0x96, 0x61, 0x0d, 0x0f,
    0xe0, 0x7c, 0x71, 0xcc, 0x90, 0x06, 0xf7, 0x1c, 0xc2, 0x6a, 0xae, 0x69, 0x17, 0x99, 0x3a, 0x27,
    0xd9, 0xeb, 0x2b, 0x22, 0xd2, 0xa9, 0x07, 0x33, 0x2d, 0x3c, 0x15, 0xc9, 0x87, 0xaa, 0x50, 0xa5,
    0x03, 0x59, 0x09, 0x1a, 0x65, 0xd7, 0x84, 0xd0, 0x82, 0x29, 0x5a, 0x1e, 0x7b, 0xa8, 0x6d, 0x2c
  };

  /* combined Xtimes3[Sbox[]] */
  static const aes_uint8 Xtime3Sbox[TABLE_SIZE] =
  {
    0xa5, 0x84, 0x99, 0x8d, 0x0d, 0xbd, 0xb1, 0x54, 0x50, 0x03, 0xa9, 0x7d, 0x19, 0x62, 0xe6, 0x9a,
    0x45, 0x9d, 0x40, 0x87, 0x15, 0xeb, 0xc9, 0x0b, 0xec, 0x67, 0xfd, 0xea, 0xbf, 0xf7, 0x96, 0x5b,
    0xc2, 0x1c, 0xae, 0x6a, 0x5a, 0x41, 0x02, 0x4f, 0x5c, 0xf4, 0x34, 0x08, 0x93, 0x73, 0x53, 0x3f,
    0x0c, 0x52, 0x65, 0x5e, 0x28, 0xa1, 0x0f, 0xb5, 0x09, 0x36, 0x9b, 0x3d, 0x26, 0x69, 0xcd, 0x9f,
    0x1b, 0x9e, 0x74, 0x2e, 0x2d, 0xb2, 0xee, 0xfb, 0xf6, 0x4d, 0x61, 0xce, 0x7b, 0x3e, 0x71, 0x97,
    0xf5, 0x68, 0x00, 0x2c, 0x60, 0x1f, 0xc8, 0xed, 0xbe, 0x46, 0xd9, 0x4b, 0xde, 0xd4, 0xe8, 0x4a,
    0x6b, 0x2a, 0xe5, 0x16, 0xc5, 0xd7, 0x55, 0x94, 0xcf, 0x10, 0x06, 0x81, 0xf0, 0x44, 0xba, 0xe3,
    0xf3, 0xfe, 0xc0, 0x8a, 0xad, 0xbc, 0x48, 0x04, 0xdf, 0xc1, 0x75, 0x63, 0x30, 0x1a, 0x0e, 0x6d,
    0x4c, 0x14, 0x35, 0x2f, 0xe1, 0xa2, 0xcc, 0x39, 0x57, 0xf2, 0x82, 0x47, 0xac, 0xe7, 0x2b, 0x95,
    0xa0, 0x98, 0xd1, 0x7f, 0x66, 0x7e, 0xab, 0x83, 0xca, 0x29, 0xd3, 0x3c, 0x79, 0xe2, 0x1d, 0x76,
    0x3b, 0x56, 0x4e, 0x1e, 0xdb, 0x0a, 0x6c, 0xe4, 0x5d, 0x6e, 0xef, 0xa6, 0xa8, 0xa4, 0x37, 0x8b,
    0x32, 0x43, 0x59, 0xb7, 0x8c, 0x64, 0xd2, 0xe0, 0xb4, 0xfa, 0x07, 0x25, 0xaf, 0x8e, 0xe9, 0x18,
    0xd5, 0x88, 0x6f, 0x72, 0x24, 0xf1, 0xc7, 0x51, 0x23, 0x7c, 0x9c, 0x21, 0xdd, 0xdc, 0x86, 0x85,
    0x90, 0x42, 0xc4, 0xaa, 0xd8, 0x05, 0x01, 0x12, 0xa3, 0x5f, 0xf9, 0xd0, 0x91, 0x58, 0x27, 0xb9,
    0x38, 0x13, 0xb3, 0x33, 0xbb, 0x70, 0x89, 0xa7, 0xb6, 0x22, 0x92, 0x20, 0x49, 0xff, 0x78, 0x7a,
    0x8f, 0xf8, 0x80, 0x17, 0xda, 0x31, 0xc6, 0xb8, 0xc3, 0xb0, 0x77, 0x11, 0xcb, 0xfc, 0xd6, 0x3a
  };

#define AES_STOP_SEC_CONST_UNSPECIFIED
//#include "MemMap.h"
#endif /* (AES_ENCRYPT == AES_ON) */
/******************************************************************************/


/******************************************************************************/
/* For local function InvMixSubColumns:                                       */
/******************************************************************************/
#if (AES_DECRYPT == AES_ON)
#define AES_START_SEC_CONST_UNSPECIFIED
//#include "MemMap.h"
  static const aes_uint8 Xtime9[TABLE_SIZE] =
  {
    0x00, 0x09, 0x12, 0x1b, 0x24, 0x2d, 0x36, 0x3f, 0x48, 0x41, 0x5a, 0x53, 0x6c, 0x65, 0x7e, 0x77,
    0x90, 0x99, 0x82, 0x8b, 0xb4, 0xbd, 0xa6, 0xaf, 0xd8, 0xd1, 0xca, 0xc3, 0xfc, 0xf5, 0xee, 0xe7,
    0x3b, 0x32, 0x29, 0x20, 0x1f, 0x16, 0x0d, 0x04, 0x73, 0x7a, 0x61, 0x68, 0x57, 0x5e, 0x45, 0x4c,
    0xab, 0xa2, 0xb9, 0xb0, 0x8f, 0x86, 0x9d, 0x94, 0xe3, 0xea, 0xf1, 0xf8, 0xc7, 0xce, 0xd5, 0xdc,
    0x76, 0x7f, 0x64, 0x6d, 0x52, 0x5b, 0x40, 0x49, 0x3e, 0x37, 0x2c, 0x25, 0x1a, 0x13, 0x08, 0x01,
    0xe6, 0xef, 0xf4, 0xfd, 0xc2, 0xcb, 0xd0, 0xd9, 0xae, 0xa7, 0xbc, 0xb5, 0x8a, 0x83, 0x98, 0x91,
    0x4d, 0x44, 0x5f, 0x56, 0x69, 0x60, 0x7b, 0x72, 0x05, 0x0c, 0x17, 0x1e, 0x21, 0x28, 0x33, 0x3a,
    0xdd, 0xd4, 0xcf, 0xc6, 0xf9, 0xf0, 0xeb, 0xe2, 0x95, 0x9c, 0x87, 0x8e, 0xb1, 0xb8, 0xa3, 0xaa,
    0xec, 0xe5, 0xfe, 0xf7, 0xc8, 0xc1, 0xda, 0xd3, 0xa4, 0xad, 0xb6, 0xbf, 0x80, 0x89, 0x92, 0x9b,
    0x7c, 0x75, 0x6e, 0x67, 0x58, 0x51, 0x4a, 0x43, 0x34, 0x3d, 0x26, 0x2f, 0x10, 0x19, 0x02, 0x0b,
    0xd7, 0xde, 0xc5, 0xcc, 0xf3, 0xfa, 0xe1, 0xe8, 0x9f, 0x96, 0x8d, 0x84, 0xbb, 0xb2, 0xa9, 0xa0,
    0x47, 0x4e, 0x55, 0x5c, 0x63, 0x6a, 0x71, 0x78, 0x0f, 0x06, 0x1d, 0x14, 0x2b, 0x22, 0x39, 0x30,
    0x9a, 0x93, 0x88, 0x81, 0xbe, 0xb7, 0xac, 0xa5, 0xd2, 0xdb, 0xc0, 0xc9, 0xf6, 0xff, 0xe4, 0xed,
    0x0a, 0x03, 0x18, 0x11, 0x2e, 0x27, 0x3c, 0x35, 0x42, 0x4b, 0x50, 0x59, 0x66, 0x6f, 0x74, 0x7d,
    0xa1, 0xa8, 0xb3, 0xba, 0x85, 0x8c, 0x97, 0x9e, 0xe9, 0xe0, 0xfb, 0xf2, 0xcd, 0xc4, 0xdf, 0xd6,
    0x31, 0x38, 0x23, 0x2a, 0x15, 0x1c, 0x07, 0x0e, 0x79, 0x70, 0x6b, 0x62, 0x5d, 0x54, 0x4f, 0x46
  };

  static const aes_uint8 XtimeB[TABLE_SIZE] =
  {
    0x00, 0x0b, 0x16, 0x1d, 0x2c, 0x27, 0x3a, 0x31, 0x58, 0x53, 0x4e, 0x45, 0x74, 0x7f, 0x62, 0x69,
    0xb0, 0xbb, 0xa6, 0xad, 0x9c, 0x97, 0x8a, 0x81, 0xe8, 0xe3, 0xfe, 0xf5, 0xc4, 0xcf, 0xd2, 0xd9,
    0x7b, 0x70, 0x6d, 0x66, 0x57, 0x5c, 0x41, 0x4a, 0x23, 0x28, 0x35, 0x3e, 0x0f, 0x04, 0x19, 0x12,
    0xcb, 0xc0, 0xdd, 0xd6, 0xe7, 0xec, 0xf1, 0xfa, 0x93, 0x98, 0x85, 0x8e, 0xbf, 0xb4, 0xa9, 0xa2,
    0xf6, 0xfd, 0xe0, 0xeb, 0xda, 0xd1, 0xcc, 0xc7, 0xae, 0xa5, 0xb8, 0xb3, 0x82, 0x89, 0x94, 0x9f,
    0x46, 0x4d, 0x50, 0x5b, 0x6a, 0x61, 0x7c, 0x77, 0x1e, 0x15, 0x08, 0x03, 0x32, 0x39, 0x24, 0x2f,
    0x8d, 0x86, 0x9b, 0x90, 0xa1, 0xaa, 0xb7, 0xbc, 0xd5, 0xde, 0xc3, 0xc8, 0xf9, 0xf2, 0xef, 0xe4,
    0x3d, 0x36, 0x2b, 0x20, 0x11, 0x1a, 0x07, 0x0c, 0x65, 0x6e, 0x73, 0x78, 0x49, 0x42, 0x5f, 0x54,
    0xf7, 0xfc, 0xe1, 0xea, 0xdb, 0xd0, 0xcd, 0xc6, 0xaf, 0xa4, 0xb9, 0xb2, 0x83, 0x88, 0x95, 0x9e,
    0x47, 0x4c, 0x51, 0x5a, 0x6b, 0x60, 0x7d, 0x76, 0x1f, 0x14, 0x09, 0x02, 0x33, 0x38, 0x25, 0x2e,
    0x8c, 0x87, 0x9a, 0x91, 0xa0, 0xab, 0xb6, 0xbd, 0xd4, 0xdf, 0xc2, 0xc9, 0xf8, 0xf3, 0xee, 0xe5,
    0x3c, 0x37, 0x2a, 0x21, 0x10, 0x1b, 0x06, 0x0d, 0x64, 0x6f, 0x72, 0x79, 0x48, 0x43, 0x5e, 0x55,
    0x01, 0x0a, 0x17, 0x1c, 0x2d, 0x26, 0x3b, 0x30, 0x59, 0x52, 0x4f, 0x44, 0x75, 0x7e, 0x63, 0x68,
    0xb1, 0xba, 0xa7, 0xac, 0x9d, 0x96, 0x8b, 0x80, 0xe9, 0xe2, 0xff, 0xf4, 0xc5, 0xce, 0xd3, 0xd8,
    0x7a, 0x71, 0x6c, 0x67, 0x56, 0x5d, 0x40, 0x4b, 0x22, 0x29, 0x34, 0x3f, 0x0e, 0x05, 0x18, 0x13,
    0xca, 0xc1, 0xdc, 0xd7, 0xe6, 0xed, 0xf0, 0xfb, 0x92, 0x99, 0x84, 0x8f, 0xbe, 0xb5, 0xa8, 0xa3
  };

  static const aes_uint8 XtimeD[TABLE_SIZE] =
  {
    0x00, 0x0d, 0x1a, 0x17, 0x34, 0x39, 0x2e, 0x23, 0x68, 0x65, 0x72, 0x7f, 0x5c, 0x51, 0x46, 0x4b,
    0xd0, 0xdd, 0xca, 0xc7, 0xe4, 0xe9, 0xfe, 0xf3, 0xb8, 0xb5, 0xa2, 0xaf, 0x8c, 0x81, 0x96, 0x9b,
    0xbb, 0xb6, 0xa1, 0xac, 0x8f, 0x82, 0x95, 0x98, 0xd3, 0xde, 0xc9, 0xc4, 0xe7, 0xea, 0xfd, 0xf0,
    0x6b, 0x66, 0x71, 0x7c, 0x5f, 0x52, 0x45, 0x48, 0x03, 0x0e, 0x19, 0x14, 0x37, 0x3a, 0x2d, 0x20,
    0x6d, 0x60, 0x77, 0x7a, 0x59, 0x54, 0x43, 0x4e, 0x05, 0x08, 0x1f, 0x12, 0x31, 0x3c, 0x2b, 0x26,
    0xbd, 0xb0, 0xa7, 0xaa, 0x89, 0x84, 0x93, 0x9e, 0xd5, 0xd8, 0xcf, 0xc2, 0xe1, 0xec, 0xfb, 0xf6,
    0xd6, 0xdb, 0xcc, 0xc1, 0xe2, 0xef, 0xf8, 0xf5, 0xbe, 0xb3, 0xa4, 0xa9, 0x8a, 0x87, 0x90, 0x9d,
    0x06, 0x0b, 0x1c, 0x11, 0x32, 0x3f, 0x28, 0x25, 0x6e, 0x63, 0x74, 0x79, 0x5a, 0x57, 0x40, 0x4d,
    0xda, 0xd7, 0xc0, 0xcd, 0xee, 0xe3, 0xf4, 0xf9, 0xb2, 0xbf, 0xa8, 0xa5, 0x86, 0x8b, 0x9c, 0x91,
    0x0a, 0x07, 0x10, 0x1d, 0x3e, 0x33, 0x24, 0x29, 0x62, 0x6f, 0x78, 0x75, 0x56, 0x5b, 0x4c, 0x41,
    0x61, 0x6c, 0x7b, 0x76, 0x55, 0x58, 0x4f, 0x42, 0x09, 0x04, 0x13, 0x1e, 0x3d, 0x30, 0x27, 0x2a,
    0xb1, 0xbc, 0xab, 0xa6, 0x85, 0x88, 0x9f, 0x92, 0xd9, 0xd4, 0xc3, 0xce, 0xed, 0xe0, 0xf7, 0xfa,
    0xb7, 0xba, 0xad, 0xa0, 0x83, 0x8e, 0x99, 0x94, 0xdf, 0xd2, 0xc5, 0xc8, 0xeb, 0xe6, 0xf1, 0xfc,
    0x67, 0x6a, 0x7d, 0x70, 0x53, 0x5e, 0x49, 0x44, 0x0f, 0x02, 0x15, 0x18, 0x3b, 0x36, 0x21, 0x2c,
    0x0c, 0x01, 0x16, 0x1b, 0x38, 0x35, 0x22, 0x2f, 0x64, 0x69, 0x7e, 0x73, 0x50, 0x5d, 0x4a, 0x47,
    0xdc, 0xd1, 0xc6, 0xcb, 0xe8, 0xe5, 0xf2, 0xff, 0xb4, 0xb9, 0xae, 0xa3, 0x80, 0x8d, 0x9a, 0x97
  };

  static const aes_uint8 XtimeE[TABLE_SIZE] =
  {
    0x00, 0x0e, 0x1c, 0x12, 0x38, 0x36, 0x24, 0x2a, 0x70, 0x7e, 0x6c, 0x62, 0x48, 0x46, 0x54, 0x5a,
    0xe0, 0xee, 0xfc, 0xf2, 0xd8, 0xd6, 0xc4, 0xca, 0x90, 0x9e, 0x8c, 0x82, 0xa8, 0xa6, 0xb4, 0xba,
    0xdb, 0xd5, 0xc7, 0xc9, 0xe3, 0xed, 0xff, 0xf1, 0xab, 0xa5, 0xb7, 0xb9, 0x93, 0x9d, 0x8f, 0x81,
    0x3b, 0x35, 0x27, 0x29, 0x03, 0x0d, 0x1f, 0x11, 0x4b, 0x45, 0x57, 0x59, 0x73, 0x7d, 0x6f, 0x61,
    0xad, 0xa3, 0xb1, 0xbf, 0x95, 0x9b, 0x89, 0x87, 0xdd, 0xd3, 0xc1, 0xcf, 0xe5, 0xeb, 0xf9, 0xf7,
    0x4d, 0x43, 0x51, 0x5f, 0x75, 0x7b, 0x69, 0x67, 0x3d, 0x33, 0x21, 0x2f, 0x05, 0x0b, 0x19, 0x17,
    0x76, 0x78, 0x6a, 0x64, 0x4e, 0x40, 0x52, 0x5c, 0x06, 0x08, 0x1a, 0x14, 0x3e, 0x30, 0x22, 0x2c,
    0x96, 0x98, 0x8a, 0x84, 0xae, 0xa0, 0xb2, 0xbc, 0xe6, 0xe8, 0xfa, 0xf4, 0xde, 0xd0, 0xc2, 0xcc,
    0x41, 0x4f, 0x5d, 0x53, 0x79, 0x77, 0x65, 0x6b, 0x31, 0x3f, 0x2d, 0x23, 0x09, 0x07, 0x15, 0x1b,
    0xa1, 0xaf, 0xbd, 0xb3, 0x99, 0x97, 0x85, 0x8b, 0xd1, 0xdf, 0xcd, 0xc3, 0xe9, 0xe7, 0xf5, 0xfb,
    0x9a, 0x94, 0x86, 0x88, 0xa2, 0xac, 0xbe, 0xb0, 0xea, 0xe4, 0xf6, 0xf8, 0xd2, 0xdc, 0xce, 0xc0,
    0x7a, 0x74, 0x66, 0x68, 0x42, 0x4c, 0x5e, 0x50, 0x0a, 0x04, 0x16, 0x18, 0x32, 0x3c, 0x2e, 0x20,
    0xec, 0xe2, 0xf0, 0xfe, 0xd4, 0xda, 0xc8, 0xc6, 0x9c, 0x92, 0x80, 0x8e, 0xa4, 0xaa, 0xb8, 0xb6,
    0x0c, 0x02, 0x10, 0x1e, 0x34, 0x3a, 0x28, 0x26, 0x7c, 0x72, 0x60, 0x6e, 0x44, 0x4a, 0x58, 0x56,
    0x37, 0x39, 0x2b, 0x25, 0x0f, 0x01, 0x13, 0x1d, 0x47, 0x49, 0x5b, 0x55, 0x7f, 0x71, 0x63, 0x6d,
    0xd7, 0xd9, 0xcb, 0xc5, 0xef, 0xe1, 0xf3, 0xfd, 0xa7, 0xa9, 0xbb, 0xb5, 0x9f, 0x91, 0x83, 0x8d
  };

#define AES_STOP_SEC_CONST_UNSPECIFIED
//#include "MemMap.h"
#endif /* (AES_DECRYPT == AES_ON) */
/******************************************************************************/


/******************************************************************************/
/* For local function ExpandKeyRound:                                         */
/******************************************************************************/
#if (AES_OPERATIONMODE == AES_ASYNCHRONOUS)
#define AES_START_SEC_CONST_UNSPECIFIED
//#include "MemMap.h"
  static const aes_uint8 Rcon[RCon_SIZE] =
  {
    0x00, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36
  };

#define AES_STOP_SEC_CONST_UNSPECIFIED
//#include "MemMap.h"
#endif /* (AES_OPERATIONMODE == AES_ASYNCHRONOUS) */
/******************************************************************************/


/******************************************************************************/
/* For exported function AES_ExpandKey:                                       */
/******************************************************************************/
#if (AES_OPERATIONMODE == AES_SYNCHRONOUS)
#define AES_START_SEC_CONST_UNSPECIFIED
//#include "MemMap.h"
  static const aes_uint8 Rcon[RCon_SIZE] =
  {
    0x00, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36
  };

#define AES_STOP_SEC_CONST_UNSPECIFIED
//#include "MemMap.h"
#endif /* (AES_OPERATIONMODE == AES_SYNCHRONOUS) */
/******************************************************************************/


/*============================================================================*\
 * LOCAL FUNCTION PROTOTYPES
\*============================================================================*/

#if (AES_ENCRYPT == AES_ON)
static void ShiftRows(void);
#endif /* (AES_ENCRYPT == AES_ON) */

#if (AES_DECRYPT == AES_ON)
static void InvShiftRows(void);
#endif /* (AES_DECRYPT == AES_ON) */

#if (AES_ENCRYPT == AES_ON)
static void MixSubColumns(void);
#endif /* (AES_ENCRYPT == AES_ON) */

#if (AES_DECRYPT == AES_ON)
static void InvMixSubColumns(void);
#endif /* (AES_DECRYPT == AES_ON) */

static void AddRoundKey(const aes_uint8* key);

#if (AES_OPERATIONMODE == AES_ASYNCHRONOUS)
static void ExpandKeyRound(const aes_uint8 i);
#endif /* (AES_OPERATIONMODE == AES_ASYNCHRONOUS) */


/*============================================================================*\
 * LOCAL FUNCTION-LIKE-MACROS and INLINE FUNCTIONS
\*============================================================================*/


#define AES_START_SEC_CODE
//#include "MemMap.h"

#define AES_START_SEC_VAR_INIT_UNSPECIFIED
//#include "MemMap.h"

#define AES_START_SEC_CONST_UNSPECIFIED
//#include "MemMap.h"


/*============================================================================*\
 * LOCAL FUNCTIONS
\*============================================================================*/

/**
 * This function is needed for encryption and
 * exchanges columns in each of 4 rows.
 * row0 - unchanged, row1- shifted left 1,
 * row2 - shifted left 2 and row3 - shifted left 3
 */
#if (AES_ENCRYPT == AES_ON)
static void ShiftRows(void)
{
  aes_uint8 tmp;


  /* just substitute row 0 */
  StateBuffer[ 0] = Sbox[StateBuffer[ 0]];
  StateBuffer[ 4] = Sbox[StateBuffer[ 4]];
  StateBuffer[ 8] = Sbox[StateBuffer[ 8]];
  StateBuffer[12] = Sbox[StateBuffer[12]];

  /* rotate row 1 */
  tmp             = Sbox[StateBuffer[ 1]];
  StateBuffer[ 1] = Sbox[StateBuffer[ 5]];
  StateBuffer[ 5] = Sbox[StateBuffer[ 9]];
  StateBuffer[ 9] = Sbox[StateBuffer[13]];
  StateBuffer[13] = tmp;

  /* rotate row 2 */
  tmp             = Sbox[StateBuffer[ 2]];
  StateBuffer[ 2] = Sbox[StateBuffer[10]];
  StateBuffer[10] = tmp;
  tmp             = Sbox[StateBuffer[ 6]];
  StateBuffer[ 6] = Sbox[StateBuffer[14]];
  StateBuffer[14] = tmp;

  /* rotate row 3 */
  tmp             = Sbox[StateBuffer[15]];
  StateBuffer[15] = Sbox[StateBuffer[11]];
  StateBuffer[11] = Sbox[StateBuffer[ 7]];
  StateBuffer[ 7] = Sbox[StateBuffer[ 3]];
  StateBuffer[ 3] = tmp;
}
#endif /* (AES_ENCRYPT == AES_ON) */



/**
 * This function is needed for decryption and
 * restores columns in each of 4 rows.
 * row0 - unchanged, row1- shifted right 1,
 * row2 - shifted right 2 and row3 - shifted right 3
 */
#if (AES_DECRYPT == AES_ON)
static void InvShiftRows(void)
{
  aes_uint8 tmp;


  /* restore row 0 */
  StateBuffer[ 0] = InvSbox[StateBuffer[ 0]];
  StateBuffer[ 4] = InvSbox[StateBuffer[ 4]];
  StateBuffer[ 8] = InvSbox[StateBuffer[ 8]];
  StateBuffer[12] = InvSbox[StateBuffer[12]];

  /* restore row 1 */
  tmp             = InvSbox[StateBuffer[13]];
  StateBuffer[13] = InvSbox[StateBuffer[ 9]];
  StateBuffer[ 9] = InvSbox[StateBuffer[ 5]];
  StateBuffer[ 5] = InvSbox[StateBuffer[ 1]];
  StateBuffer[ 1] = tmp;

  /* restore row 2 */
  tmp             = InvSbox[StateBuffer[ 2]];
  StateBuffer[ 2] = InvSbox[StateBuffer[10]];
  StateBuffer[10] = tmp;
  tmp             = InvSbox[StateBuffer[ 6]];
  StateBuffer[ 6] = InvSbox[StateBuffer[14]];
  StateBuffer[14] = tmp;

  /* restore row 3 */
  tmp             = InvSbox[StateBuffer[ 3]];
  StateBuffer[ 3] = InvSbox[StateBuffer[ 7]];
  StateBuffer[ 7] = InvSbox[StateBuffer[11]];
  StateBuffer[11] = InvSbox[StateBuffer[15]];
  StateBuffer[15] = tmp;
}
#endif /* (AES_DECRYPT == AES_ON) */



/**
 * This function is needed for encryption.
 * "Mix sub-columns":
 * Recombine and mix each row in a column
 */
#if (AES_ENCRYPT == AES_ON)
static void MixSubColumns(void)
{
  uint8_t i;


  /* mixing column 0 */
  Tmp[0]  = (uint8_t) (Xtime2Sbox[StateBuffer[0]]  ^ Xtime3Sbox[StateBuffer[5]]
                       ^ Sbox[StateBuffer[10]]       ^ Sbox[StateBuffer[15]]);
  Tmp[1]  = (uint8_t) (Sbox[StateBuffer[0]]        ^ Xtime2Sbox[StateBuffer[5]]
                       ^ Xtime3Sbox[StateBuffer[10]] ^ Sbox[StateBuffer[15]]);
  Tmp[2]  = (uint8_t) (Sbox[StateBuffer[0]]        ^ Sbox[StateBuffer[5]]
                       ^ Xtime2Sbox[StateBuffer[10]] ^ Xtime3Sbox[StateBuffer[15]]);
  Tmp[3]  = (uint8_t) (Xtime3Sbox[StateBuffer[0]]  ^ Sbox[StateBuffer[5]]
                       ^ Sbox[StateBuffer[10]]       ^ Xtime2Sbox[StateBuffer[15]]);

  /* mixing column 1 */
  Tmp[4]  = (uint8_t) (Xtime2Sbox[StateBuffer[4]]  ^ Xtime3Sbox[StateBuffer[9]]
                       ^ Sbox[StateBuffer[14]]       ^ Sbox[StateBuffer[3]]);
  Tmp[5]  = (uint8_t) (Sbox[StateBuffer[4]]        ^ Xtime2Sbox[StateBuffer[9]]
                       ^ Xtime3Sbox[StateBuffer[14]] ^ Sbox[StateBuffer[3]]);
  Tmp[6]  = (uint8_t) (Sbox[StateBuffer[4]]        ^ Sbox[StateBuffer[9]]
                       ^ Xtime2Sbox[StateBuffer[14]] ^ Xtime3Sbox[StateBuffer[3]]);
  Tmp[7]  = (uint8_t) (Xtime3Sbox[StateBuffer[4]]  ^ Sbox[StateBuffer[9]]
                       ^ Sbox[StateBuffer[14]]       ^ Xtime2Sbox[StateBuffer[3]]);

  /* mixing column 2 */
  Tmp[8]  = (uint8_t) (Xtime2Sbox[StateBuffer[8]]  ^ Xtime3Sbox[StateBuffer[13]]
                       ^ Sbox[StateBuffer[2]]        ^ Sbox[StateBuffer[7]]);
  Tmp[9]  = (uint8_t) (Sbox[StateBuffer[8]]        ^ Xtime2Sbox[StateBuffer[13]]
                       ^ Xtime3Sbox[StateBuffer[2]]  ^ Sbox[StateBuffer[7]]);
  Tmp[10] = (uint8_t) (Sbox[StateBuffer[8]]        ^ Sbox[StateBuffer[13]]
                       ^ Xtime2Sbox[StateBuffer[2]]  ^ Xtime3Sbox[StateBuffer[7]]);
  Tmp[11] = (uint8_t) (Xtime3Sbox[StateBuffer[8]]  ^ Sbox[StateBuffer[13]]
                       ^ Sbox[StateBuffer[2]]        ^ Xtime2Sbox[StateBuffer[7]]);

  /* mixing column 3 */
  Tmp[12] = (uint8_t) (Xtime2Sbox[StateBuffer[12]] ^ Xtime3Sbox[StateBuffer[1]]
                       ^ Sbox[StateBuffer[6]]        ^ Sbox[StateBuffer[11]]);
  Tmp[13] = (uint8_t) (Sbox[StateBuffer[12]]       ^ Xtime2Sbox[StateBuffer[1]]
                       ^ Xtime3Sbox[StateBuffer[6]]  ^ Sbox[StateBuffer[11]]);
  Tmp[14] = (uint8_t) (Sbox[StateBuffer[12]]       ^ Sbox[StateBuffer[1]]
                       ^ Xtime2Sbox[StateBuffer[6]]  ^ Xtime3Sbox[StateBuffer[11]]);
  Tmp[15] = (uint8_t) (Xtime3Sbox[StateBuffer[12]] ^ Sbox[StateBuffer[1]]
                       ^ Sbox[StateBuffer[6]]        ^ Xtime2Sbox[StateBuffer[11]]);

  for (i = 0; i < VECTOR_SIZE; i++)
  {
    StateBuffer[i] = Tmp[i];
  } /* end for */
}
#endif /* (AES_ENCRYPT == AES_ON) */



/**
 * This function is needed for decryption.
 * "Invers mix sub-columns":
 * Restore and un-mix each row in a column
 */
#if (AES_DECRYPT == AES_ON)
static void InvMixSubColumns(void)
{
  aes_uint8 i;


  /* restore column 0 */
  Tmp[0]  = (aes_uint8) (XtimeE[StateBuffer[0]]  ^ XtimeB[StateBuffer[1]]
                       ^ XtimeD[StateBuffer[2]]  ^ Xtime9[StateBuffer[3]]);
  Tmp[5]  = (aes_uint8) (Xtime9[StateBuffer[0]]  ^ XtimeE[StateBuffer[1]]
                       ^ XtimeB[StateBuffer[2]]  ^ XtimeD[StateBuffer[3]]);
  Tmp[10] = (aes_uint8) (XtimeD[StateBuffer[0]]  ^ Xtime9[StateBuffer[1]]
                       ^ XtimeE[StateBuffer[2]]  ^ XtimeB[StateBuffer[3]]);
  Tmp[15] = (aes_uint8) (XtimeB[StateBuffer[0]]  ^ XtimeD[StateBuffer[1]]
                       ^ Xtime9[StateBuffer[2]]  ^ XtimeE[StateBuffer[3]]);

  /* restore column 1 */
  Tmp[4]  = (aes_uint8) (XtimeE[StateBuffer[4]]  ^ XtimeB[StateBuffer[5]]
                       ^ XtimeD[StateBuffer[6]]  ^ Xtime9[StateBuffer[7]]);
  Tmp[9]  = (aes_uint8) (Xtime9[StateBuffer[4]]  ^ XtimeE[StateBuffer[5]]
                       ^ XtimeB[StateBuffer[6]]  ^ XtimeD[StateBuffer[7]]);
  Tmp[14] = (aes_uint8) (XtimeD[StateBuffer[4]]  ^ Xtime9[StateBuffer[5]]
                       ^ XtimeE[StateBuffer[6]]  ^ XtimeB[StateBuffer[7]]);
  Tmp[3]  = (aes_uint8) (XtimeB[StateBuffer[4]]  ^ XtimeD[StateBuffer[5]]
                       ^ Xtime9[StateBuffer[6]]  ^ XtimeE[StateBuffer[7]]);

  /* restore column 2 */
  Tmp[8]  = (aes_uint8) (XtimeE[StateBuffer[8]]  ^ XtimeB[StateBuffer[9]]
                       ^ XtimeD[StateBuffer[10]] ^ Xtime9[StateBuffer[11]]);
  Tmp[13] = (aes_uint8) (Xtime9[StateBuffer[8]]  ^ XtimeE[StateBuffer[9]]
                       ^ XtimeB[StateBuffer[10]] ^ XtimeD[StateBuffer[11]]);
  Tmp[2]  = (aes_uint8) (XtimeD[StateBuffer[8]]  ^ Xtime9[StateBuffer[9]]
                       ^ XtimeE[StateBuffer[10]] ^ XtimeB[StateBuffer[11]]);
  Tmp[7]  = (aes_uint8) (XtimeB[StateBuffer[8]]  ^ XtimeD[StateBuffer[9]]
                       ^ Xtime9[StateBuffer[10]] ^ XtimeE[StateBuffer[11]]);

  /* restore column 3 */
  Tmp[12] = (aes_uint8) (XtimeE[StateBuffer[12]] ^ XtimeB[StateBuffer[13]]
                       ^ XtimeD[StateBuffer[14]] ^ Xtime9[StateBuffer[15]]);
  Tmp[1]  = (aes_uint8) (Xtime9[StateBuffer[12]] ^ XtimeE[StateBuffer[13]]
                       ^ XtimeB[StateBuffer[14]] ^ XtimeD[StateBuffer[15]]);
  Tmp[6]  = (aes_uint8) (XtimeD[StateBuffer[12]] ^ Xtime9[StateBuffer[13]]
                       ^ XtimeE[StateBuffer[14]] ^ XtimeB[StateBuffer[15]]);
  Tmp[11] = (aes_uint8) (XtimeB[StateBuffer[12]] ^ XtimeD[StateBuffer[13]]
                       ^ Xtime9[StateBuffer[14]] ^ XtimeE[StateBuffer[15]]);

  for (i = 0; i < (COLUMN_SIZE * Nb); i++)
  {
    StateBuffer[i] = InvSbox[Tmp[i]];
  } /* end for */
}
#endif /* (AES_DECRYPT == AES_ON) */



/**
 * Encrypt/decrypt columns of the key.
 * StateBuffer[0..15] ^= key[0..15]
 */
static void AddRoundKey(const aes_uint8* key)
{
  StateBuffer[ 0] ^= key[ 0];
  StateBuffer[ 1] ^= key[ 1];
  StateBuffer[ 2] ^= key[ 2];
  StateBuffer[ 3] ^= key[ 3];
  StateBuffer[ 4] ^= key[ 4];
  StateBuffer[ 5] ^= key[ 5];
  StateBuffer[ 6] ^= key[ 6];
  StateBuffer[ 7] ^= key[ 7];
  StateBuffer[ 8] ^= key[ 8];
  StateBuffer[ 9] ^= key[ 9];
  StateBuffer[10] ^= key[10];
  StateBuffer[11] ^= key[11];
  StateBuffer[12] ^= key[12];
  StateBuffer[13] ^= key[13];
  StateBuffer[14] ^= key[14];
  StateBuffer[15] ^= key[15];
}



/**
 * One round of the ExpandKey loop operation (asynchronous mode).
 *
 * \param[in]      i  actual loop counter value
 */
#if (AES_OPERATIONMODE == AES_ASYNCHRONOUS)
static void ExpandKeyRound(const aes_uint8 i)
{
  Tmp[0] = ExpandKeyBuffer[(4 * i) - 4];
  Tmp[1] = ExpandKeyBuffer[(4 * i) - 3];
  Tmp[2] = ExpandKeyBuffer[(4 * i) - 2];
  Tmp[3] = ExpandKeyBuffer[(4 * i) - 1];

  if ((i % Nk) == 0)
  {
    Tmp[4] = Tmp[3];
    Tmp[3] = Sbox[Tmp[0]];
    Tmp[0] = (aes_uint8) (Sbox[Tmp[1]] ^ Rcon[i/Nk]);
    Tmp[1] = Sbox[Tmp[2]];
    Tmp[2] = Sbox[Tmp[4]];
  }

  ExpandKeyBuffer[(4 * i) + 0] = (aes_uint8) (ExpandKeyBuffer[((4 * i) - (4 * Nk)) + 0] ^ Tmp[0]);
  ExpandKeyBuffer[(4 * i) + 1] = (aes_uint8) (ExpandKeyBuffer[((4 * i) - (4 * Nk)) + 1] ^ Tmp[1]);
  ExpandKeyBuffer[(4 * i) + 2] = (aes_uint8) (ExpandKeyBuffer[((4 * i) - (4 * Nk)) + 2] ^ Tmp[2]);
  ExpandKeyBuffer[(4 * i) + 3] = (aes_uint8) (ExpandKeyBuffer[((4 * i) - (4 * Nk)) + 3] ^ Tmp[3]);
}
#endif /* (AES_OPERATIONMODE == AES_ASYNCHRONOUS) */



/*============================================================================*\
 * EXPORTED FUNCTIONS
\*============================================================================*/

/* For detailed explanation on the exported functions see aes.h file. */
/* produce Nb bytes for each round */
#if (AES_OPERATIONMODE == AES_SYNCHRONOUS)
void AES_ExpandKey(uint8_t* key) 
{
  aes_uint8 i;


  for (i = 0; i < VECTOR_SIZE; i++)
  {
    ExpandKeyBuffer[i] = key[i];
  } /* end for */
#if 1
  for (i = Nk; i < (Nb * (Nr + 1)); i++)
  {
    Tmp[0] = ExpandKeyBuffer[(4 * i) - 4];
    Tmp[1] = ExpandKeyBuffer[(4 * i) - 3];
    Tmp[2] = ExpandKeyBuffer[(4 * i) - 2];
    Tmp[3] = ExpandKeyBuffer[(4 * i) - 1];

    if ((i % Nk) == 0)
    {
      Tmp[4] = Tmp[3];
      Tmp[3] = Sbox[Tmp[0]];
      Tmp[0] = (aes_uint8) (Sbox[Tmp[1]] ^ Rcon[i/Nk]);
      Tmp[1] = Sbox[Tmp[2]];
      Tmp[2] = Sbox[Tmp[4]];
    }

    ExpandKeyBuffer[(4 * i) + 0] = (uint8_t) (ExpandKeyBuffer[((4 * i) - (4 * Nk)) + 0] ^ Tmp[0]);
    ExpandKeyBuffer[(4 * i) + 1] = (uint8_t) (ExpandKeyBuffer[((4 * i) - (4 * Nk)) + 1] ^ Tmp[1]);
    ExpandKeyBuffer[(4 * i) + 2] = (uint8_t) (ExpandKeyBuffer[((4 * i) - (4 * Nk)) + 2] ^ Tmp[2]);
    ExpandKeyBuffer[(4 * i) + 3] = (uint8_t) (ExpandKeyBuffer[((4 * i) - (4 * Nk)) + 3] ^ Tmp[3]);
  } /* end for */
#endif
}
#endif /* (AES_OPERATIONMODE == AES_SYNCHRONOUS) */



/* For detailed explanation on the exported functions see aes.h file. */
/* encrypt one 128 bit block */
#if ((AES_OPERATIONMODE == AES_SYNCHRONOUS)&&(AES_ENCRYPT == AES_ON))
void AES_Encrypt(uint8_t* in, uint8_t* out)
{
  uint8_t i;
  uint8_t round;

  for (i = 0; i < VECTOR_SIZE; i++)
  {
    StateBuffer[i] = in[i];
  } /* end for */

  AddRoundKey(ExpandKeyBuffer);

  for(round = 1; round < (Nr + 1); round++)
  {
    if (round < Nr)
    {
      MixSubColumns();
    }
    else
    {
      ShiftRows();
    }

    AddRoundKey(&ExpandKeyBuffer[round * (Nb * COLUMN_SIZE)]);
  } /* end for */

  for (i = 0; i < VECTOR_SIZE; i++)
  {
    out[i] = StateBuffer[i];
  } /* end for */
}
#endif /* ((AES_OPERATIONMODE == AES_SYNCHRONOUS)&&(AES_ENCRYPT == AES_ON)) */



/* For detailed explanation on the exported functions see aes.h file. */
#if ((AES_OPERATIONMODE == AES_SYNCHRONOUS)&&(AES_DECRYPT == AES_ON))
void AES_Decrypt(const aes_uint8* in, aes_uint8 *out)
{
  aes_uint8 i;
  aes_uint8 round;


  for (i = 0; i < VECTOR_SIZE; i++)
  {
    StateBuffer[i] = in[i];
  } /* end for */

  AddRoundKey(&ExpandKeyBuffer[Nr * Nb * COLUMN_SIZE]);
  InvShiftRows();

  round = Nr;
  do
  {
    round--;
    AddRoundKey(&ExpandKeyBuffer[round * (Nb * COLUMN_SIZE)]);

    if (round != 0)
    {
      InvMixSubColumns();
    }
  }
  while(round > 0);

  for (i = 0; i < VECTOR_SIZE; i++)
  {
    out[i] = StateBuffer[i];
  } /* end for */
}
#endif /* ((AES_OPERATIONMODE == AES_SYNCHRONOUS)&&(AES_DECRYPT == AES_ON)) */



/* For detailed explanation on the exported functions see aes.h file. */
#if (AES_OPERATIONMODE == AES_ASYNCHRONOUS)
aes_uint8 AES_StartExpandKey(const aes_uint8* key)
{
  aes_uint8 local_return;
  aes_uint8 i;

  if(AES_HandlerState == AES_IDLE)
  { /* No other sequence in work:                    */
    /* Accept request and prepare ExpandKey sequence */
    for (i = 0; i < VECTOR_SIZE; i++)
    {
      ExpandKeyBuffer[i] = key[i];
    } /* end for */
    
    Round = Nk;  /* Start value for the ExpandKey loop operation */
    AES_HandlerState = AES_EXPANDKEY_SEQ;
    local_return = AES_ERR_OK;
  } /* end "No other sequence in work" */
  else
  { /* Another sequence is in work: */
    local_return = AES_ERR_BUSY;
  } /* end "Another sequence is in work" */
  return(local_return);
}
#endif /* (AES_OPERATIONMODE == AES_ASYNCHRONOUS) */



/* For detailed explanation on the exported functions see aes.h file. */
#if ((AES_OPERATIONMODE == AES_ASYNCHRONOUS)&&(AES_ENCRYPT == AES_ON))
aes_uint8 AES_StartEncrypt(const aes_uint8* in, aes_uint8* out)
{
  aes_uint8 local_return;
  aes_uint8 i;

  if(AES_HandlerState == AES_IDLE)
  { /* No other sequence in work:                  */
    /* Accept request and prepare Encrypt sequence */

    /* store output pointer */
    Out_ptr = out;

    /* copy input values */
    for (i = 0; i < VECTOR_SIZE; i++)
    {
      StateBuffer[i] = in[i];
    } /* end for */

    AddRoundKey(ExpandKeyBuffer);

    Round = 1;  /* Start value for the Encrypt loop operation */
    AES_HandlerState = AES_ENCRYPT_SEQ;
    local_return = AES_ERR_OK;
  } /* end "No other sequence in work" */
  else
  { /* Another sequence is in work: */
    local_return = AES_ERR_BUSY;
  } /* end "Another sequence is in work" */
  return(local_return);
}
#endif /* ((AES_OPERATIONMODE == AES_ASYNCHRONOUS)&&(AES_ENCRYPT == AES_ON)) */



/* For detailed explanation on the exported functions see aes.h file. */
#if ((AES_OPERATIONMODE == AES_ASYNCHRONOUS)&&(AES_DECRYPT == AES_ON))
aes_uint8 AES_StartDecrypt(const aes_uint8* in, aes_uint8* out)
{
  aes_uint8 local_return;
  aes_uint8 i;

  if(AES_HandlerState == AES_IDLE)
  { /* No other sequence in work:                  */
    /* Accept request and prepare Decrypt sequence */

    /* store output pointer */
    Out_ptr = out;

    /* copy input values */
    for (i = 0; i < VECTOR_SIZE; i++)
    {
      StateBuffer[i] = in[i];
    } /* end for */

    AddRoundKey(&ExpandKeyBuffer[Nr * Nb * COLUMN_SIZE]);
    InvShiftRows();

    Round = Nr;  /* Start value for the Decrypt loop operation */
    AES_HandlerState = AES_DECRYPT_SEQ;
    local_return = AES_ERR_OK;
  } /* end "No other sequence in work" */
  else
  { /* Another sequence is in work: */
    local_return = AES_ERR_BUSY;
  } /* end "Another sequence is in work" */
  return(local_return);
}
#endif /* ((AES_OPERATIONMODE == AES_ASYNCHRONOUS)&&(AES_DECRYPT == AES_ON)) */



/* For detailed explanation on the exported functions see aes.h file. */
#if (AES_OPERATIONMODE == AES_ASYNCHRONOUS)
void AES_Handler(void)
{
  /* counter for the loop operations which are done at once per call */
  /* of the handler                                                  */
  aes_uint8 rounds_at_once_cnt;
  aes_uint8 i;

  rounds_at_once_cnt = 0;

  switch(AES_HandlerState)
  {
  case AES_EXPANDKEY_SEQ:
  /*************************************************************************\
   * Do the rounds for the ExpandKey operation
  \*************************************************************************/
    do
    {
      ExpandKeyRound(Round);
      Round++;
      rounds_at_once_cnt++;
    }
    while(  (Round < (Nb * (Nr + 1)))
          &&(rounds_at_once_cnt < AES_EXPANDKEY_ROUNDS_AT_ONCE));

    if(Round >= (Nb * (Nr + 1)))
    { /* ExpandKey operation finished: */
      AES_EndExpandKey();
      AES_HandlerState = AES_IDLE;
    }
    break;

#if (AES_ENCRYPT == AES_ON)
  case AES_ENCRYPT_SEQ:
  /*************************************************************************\
   * Do the rounds for the Encrypt operation
  \*************************************************************************/
    do
    {
      if (Round < Nr)
      {
        MixSubColumns();
      }
      else
      {
        ShiftRows();
      }
      AddRoundKey(&ExpandKeyBuffer[Round * (Nb * COLUMN_SIZE)]);

      Round++;
      rounds_at_once_cnt++;
    }
    while(  (Round < (Nr + 1))
          &&(rounds_at_once_cnt < AES_ENCRYPT_ROUNDS_AT_ONCE));

    if(Round >= (Nr + 1))
    { /* all rounds for Encrypt done:       */
      /* copy result to stored destination: */
      for (i = 0; i < VECTOR_SIZE; i++)
      {
        Out_ptr[i] = StateBuffer[i];
      } /* end for */

      /* Encrypt operation finished: */
      AES_EndEncrypt();
      AES_HandlerState = AES_IDLE;
    }
    break;
#endif /* (AES_ENCRYPT == AES_ON) */

#if (AES_DECRYPT == AES_ON)
  case AES_DECRYPT_SEQ:
  /*************************************************************************\
   * Do the rounds for the Decrypt operation
  \*************************************************************************/
    do
    {
      Round--;
      AddRoundKey(&ExpandKeyBuffer[Round * (Nb * COLUMN_SIZE)]);

      if (Round != 0)
      {
        InvMixSubColumns();
      }

      rounds_at_once_cnt++;
    }
    while(  (Round > 0)
          &&(rounds_at_once_cnt < AES_DECRYPT_ROUNDS_AT_ONCE));

    if(Round == 0)
    { /* all rounds for Decrypt done:       */
      /* copy result to stored destination: */
      for (i = 0; i < VECTOR_SIZE; i++)
      {
        Out_ptr[i] = StateBuffer[i];
      } /* end for */

      /* Decrypt operation finished: */
      AES_EndDecrypt();
      AES_HandlerState = AES_IDLE;
    }
    break;
#endif /* (AES_DECRYPT == AES_ON) */

  case AES_IDLE:
  /*************************************************************************\
   * Do intentional nothing
  \*************************************************************************/
    break;

  default:
  /*************************************************************************\
   * unknown or unallowed state -> indicate system error
  \*************************************************************************/
    AES_Error_HandlerState();
    AES_HandlerState = AES_IDLE;
    break;
  }
}
#endif /* (AES_OPERATIONMODE == AES_ASYNCHRONOUS) */



/* For detailed explanation on the exported functions see aes.h file. */
#if (AES_OPERATIONMODE == AES_ASYNCHRONOUS)
aes_boolean AES_Q_Busy(void)
{
  aes_boolean local_return;


  if(AES_HandlerState == AES_IDLE)
  { /* AES_Handler statemachine is set to idle state: */
    /* indicate "not busy" */
    local_return = AES_FALSE;
  }
  else
  { /* AES_Handler statemachine is not set to idle state: */
    /* indicate "busy" */
    local_return = AES_TRUE;
  }
  return(local_return);
}
#endif /* (AES_OPERATIONMODE == AES_ASYNCHRONOUS) */


#define AES_STOP_SEC_CONST_UNSPECIFIED
//#include "MemMap.h"

#define AES_STOP_SEC_VAR_INIT_UNSPECIFIED
//#include "MemMap.h"

#define AES_STOP_SEC_CODE
//#include "MemMap.h"

/*============================================================================*\
 * AUTHOR(S) IDENTITY (AID)                                                     
 *-----------------------------------------------------------------------------  
 *                                     
 *  AID   NETID       NAME
 *  ---------------------------------------------------------------------------
 *  ABE   fzhxnn      Achim     Berger   
 *                                     
\*============================================================================*/

/*============================================================================*\
 * FILE REVISION HISTORY                                               
 *-----------------------------------------------------------------------------  
 *                                     
 *  DATE          REV         AID          SCR         TASK        
 *      SUMMARY OF CHANGES                                 
 *  ---------------------------------------------------------------------------
 *  07-12-17      1.00        ABE          12345       67890 
 *      First revision                                     
 *  ---------------------------------------------------------------------------
 *  08-01-18      1.01        ABE
 *      According to code review:
 *      Copyright exception comment added
 *  ---------------------------------------------------------------------------
 *  ---------------------------------------------------------------------------
 *  13-07-22      1.01        ABE           4031       10418
 *    Add macros from "MemMap.h"      
 *  ---------------------------------------------------------------------------
 *  14-10-13      3           ABE           6470       16212
 *    All static variables moved to the top, more macros from "MemMap.h" added
 *  ---------------------------------------------------------------------------
 *  17-09-01      2           YF            8891       23281
 *    Fix aes.c building warning
\*============================================================================*/

/* END OF FILE -------------------------------------------------------------- */
