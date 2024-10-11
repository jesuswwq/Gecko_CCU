#ifndef AES_CF_H
#define AES_CF_H

#define aes_uint8 uint8_t
/**\file    
 *
 * Configurable c-header-file that contains the configuration interface 
 * of this Buildingblock.
 * 
 * \b Application:        AES Encryption Buildingblock \n 
 * \b Module:             aes_cf.h \n 
 * \b File-Revision:      1.01 \n
 * \b Changeable-by-user: Yes \n
 * \b Module-Owner:       Achim Berger \n
 * \b Classification:     CONFIDENTIAL \n
 * \n
 */

/*============================================================================*\
 *                                                                            
 * Copyright 2007 Delphi Controls & Security, All Rights Reserved         
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
 
/* EXPORTED DEFINES FOR CONSTANTS --------------------------------------------*/

/**
 * Do not change this define.
 */
#define AES_OFF          (0)

/**
 * Do not change this define.
 */
#define AES_ON           (!AES_OFF)

/**
 * Do not change this define.
 */
#define AES_SYNCHRONOUS  (1)

/**
 * Do not change this define.
 */
#define AES_ASYNCHRONOUS (2)

/**
 * User configurable define.
 *
 * Choose the mode of operation for the AES Buildingblock here.
 * Configure either AES_SYNCHRONOUS or AES_ASYNCHRONOUS.
 * \n
 * \n
 * BB users with a suitable fast processor should choose AES_SYNCHRONOUS
 * for the synchronous way of processing with these API routines:
 * - AES_ExpandKey
 * - AES_Encrypt
 * - AES_Decrypt
 * .
 * \n
 * BB users with a slow system can choose AES_ASYNCHRONOUS
 * for the asynchronous way of processing in cooperative multitasking 
 * with these API- and Interface- routines:
 * - AES_StartExpandKey
 * - AES_StartEncrypt
 * - AES_StartDecrypt
 * - AES_Handler
 * - AES_Q_Busy
 * - AES_EndExpandKey
 * - AES_EndEncrypt
 * - AES_EndDecrypt
 * - AES_Error_HandlerState
 * .
 * \n
 * \reqtrace{BRQ_AES.doc}{BRQ_AES_006}                                                                           
 */
#define AES_OPERATIONMODE (AES_SYNCHRONOUS)

/**
 * User configurable define.
 *
 * Choose the availability of the encryption part here.
 * Configure either AES_ON or AES_OFF.
 * \n
 * BB users with applications which do only need to decrypt 
 * AES encrypted data can de-activate the encryption part and safe resources.
 * \n
 * \reqtrace{BRQ_AES.doc}{BRQ_AES_004}
 */
#define AES_ENCRYPT       (AES_ON)

/**
 * User configurable define.
 *
 * Choose the availability of the decryption part here.
 * Configure either AES_ON or AES_OFF.
 * \n
 * BB users with applications which only need to calculate AES encrypted data 
 * can de-activate the Decryption part and safe resources.
 * \n
 * \reqtrace{BRQ_AES.doc}{BRQ_AES_005}
 */
#define AES_DECRYPT       (AES_ON)

/**
 * User configurable define.
 *
 * If AES_OPERATIONMODE is set to AES_ASYNCHRONOUS:
 * Choose the amount of "ExpandKey" rounds per handler call here.
 * Configure a number in the range between (min) 1 and (max) 40.
 * \n
 * Hint:
 * BB users with configuration values close to the maximum value
 * should consider to use the synchronous way of processing instead.
 * \n
 * \reqtrace{BRQ_AES.doc}{BRQ_AES_006}
 */
#define AES_EXPANDKEY_ROUNDS_AT_ONCE   (2)

/**
 * User configurable define.
 *
 * If AES_OPERATIONMODE is set to AES_ASYNCHRONOUS and
 * AES_ENCRYPT is set to AES_ON:
 * Choose the amount of "Encrypt" rounds per handler call here.
 * Configure a number in the range between (min) 1 and (max) 10.
 * \n
 * Hint:
 * BB users with configuration values close to the maximum value
 * should consider to use the synchronous way of processing instead.
 * \n
 * \reqtrace{BRQ_AES.doc}{BRQ_AES_006}
 */
#define AES_ENCRYPT_ROUNDS_AT_ONCE     (2)

/**
 * User configurable define.
 *
 * If AES_OPERATIONMODE is set to AES_ASYNCHRONOUS and
 * AES_DECRYPT is set to AES_ON:
 * Choose the amount of "Decrypt" rounds per handler call here.
 * Configure a number in the range between (min) 1 and (max) 10.
 * \n
 * Hint:
 * BB users with configuration values close to the maximum value
 * should consider to use the synchronous way of processing instead.
 * \n
 * \reqtrace{BRQ_AES.doc}{BRQ_AES_006}
 */
#define AES_DECRYPT_ROUNDS_AT_ONCE     (2)


/* EXPORTED DEFINE MACROS (#, ##) --------------------------------------------*/

/*============================================================================*\
 * EXPORTED TYPEDEF DECLARATIONS
\*============================================================================*/

/* ENUMS ---------------------------------------------------------------------*/

/* STRUCTS -------------------------------------------------------------------*/

/* UNIONS --------------------------------------------------------------------*/

/* OTHER TYPEDEFS ------------------------------------------------------------*/
 
/*============================================================================*\
 * EXPORTED OBJECT DECLARATIONS
\*============================================================================*/

/*============================================================================*\
 * EXPORTED FUNCTIONS PROTOTYPES
\*============================================================================*/
 
/*============================================================================*\
 * EXPORTED FUNCTION-LIKE-MACROS and INLINE FUNCTIONS
\*============================================================================*/

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
 * FILE REVISION HISTORY, BB
 *-----------------------------------------------------------------------------  
 *                                     
 *  DATE          REV         AID          SCR         TASK        
 *      SUMMARY OF CHANGES                                 
 *  ---------------------------------------------------------------------------
 *  07-12-05      1.00        ABE          12345       67890 
 *      First revision                                     
 *  ---------------------------------------------------------------------------
 *  08-01-18      1.01        ABE
 *      According to code review:
 *      Removal of unused (empty) "reqtrace" comment lines
 *  ---------------------------------------------------------------------------
\*============================================================================*/

/*============================================================================*\
 * FILE REVISION HISTORY, BB User Project
 *-----------------------------------------------------------------------------  
 *                                     
 *  DATE          REV         AID          SCR         TASK        
 *      SUMMARY OF CHANGES                                 
 *  ---------------------------------------------------------------------------
 *  13-07-19      1.00        ABE          4031       10417
 *      First revision for VO30BC
 *  ---------------------------------------------------------------------------
 *  19-08-01    BSA-1531    YF
 *  update DigKeyMgr logic
\*============================================================================*/

#endif   /* #ifdef AES_CF_H */
/* END OF FILE -------------------------------------------------------------- */
