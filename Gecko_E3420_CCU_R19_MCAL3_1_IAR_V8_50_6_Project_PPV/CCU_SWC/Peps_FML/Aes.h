#ifndef AES_H
#define AES_H

/**\file
 *
 * Functional header of the 128 bit AES encryption and decryption module.
 *
 * Support for encryption and/or decryption is configurable. \n
 * Mode of operation (synchronous or asynchronous) is configurable. \n
 * This module is based on original code from Karl Malbrain,
 * malbrain(a)yahoo.com
 *
 * 
 * \b Application:        AES Encryption Buildingblock \n 
 * \b Module:             aes.h \n 
 * \b File-Revision:      1.01 \n
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
//#include "aes_tp.h"
#include "aes_cf.h"
#include "stdint.h"

/* EXPORTED DEFINES FOR CONSTANTS --------------------------------------------*/

/**
 * Error code definition for the return values of the AES_Start_x- API-routines
 * in asynchronous operation mode.
 * 
 * No error detected. The request is accepted.
 */
#define AES_ERR_OK                (aes_uint8)(0x01u)

/**
 * Error code definition for the return values of the AES_Start_x- API-routines
 * in asynchronous operation mode.
 * 
 * The request is rejected because the AES_Handler is busy with a
 * previous started sequence.
 */
#define AES_ERR_BUSY              (aes_uint8)(0x02u)


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

/**
 * Function to expand the AES security key.
 * 
 * Only available if AES_OPERATIONMODE is set to AES_SYNCHRONOUS.
 * \n
 * This function generates the round-keys - which are necessary for encryption
 * and decryption - from the 128 bit AES security key.
 * \n
 * Must be called at least once after system startup / 
 * after a change of the actual AES security key data, 
 * before AES_Encrypt or AES_Decrypt can be used.
 * 
 * \param[in]      key Pointer to the 16 byte array (128 bit) 
 *                     with the AES security key data that shall be used for
 *                     subsequent encryption or decryption
 *
 * \Reentrancy     non-reentrant
 * \Synchronism    synchronous
 * \Precondition   (System startup or a change of the AES key data)
 * \n
 */
#if (AES_OPERATIONMODE == AES_SYNCHRONOUS)
extern void AES_ExpandKey(uint8_t* key);
#endif /* (AES_OPERATIONMODE == AES_SYNCHRONOUS) */
  
/**
 * Function to do the AES encryption.
 * 
 * Only available if AES_OPERATIONMODE is set to AES_SYNCHRONOUS and
 * if AES_ENCRYPT is set to AES_ON.
 * \n
 * This function generates 16 bytes encrypted output data from
 * 16 bytes plain input data.
 * 
 * \param[in]      in  Pointer to the 16 byte array
 *                     with the input data that shall be encrypted
 * \param[in,out]  out Pointer to the 16 byte array
 *                     where the encrypted output data shall be stored
 * 
 * \Reentrancy     non-reentrant
 * \Synchronism    synchronous
 * \Precondition   AES_ExpandKey must have been called before 
 *                 (at least once for the actual used AES key data)
 * \n
 * \reqtrace{BRQ_AES.doc}{BRQ_AES_001}                                                                           
 */
#if ((AES_OPERATIONMODE == AES_SYNCHRONOUS)&&(AES_ENCRYPT == AES_ON))
extern void AES_Encrypt(uint8_t* in, uint8_t* out);
#endif /* ((AES_OPERATIONMODE == AES_SYNCHRONOUS)&&(AES_ENCRYPT == AES_ON)) */
  
/**
 * Function to do the AES decryption.
 * 
 * Only available if AES_OPERATIONMODE is set to AES_SYNCHRONOUS and
 * if AES_DECRYPT is set to AES_ON.
 * \n
 * This function generates 16 bytes decrypted output data from
 * 16 bytes encrypted input data.
 * 
 * \param[in]      in  Pointer to the 16 byte array
 *                     with the input data that shall be decrypted
 * \param[in,out]  out Pointer to the 16 byte array
 *                     where the decrypted output data shall be stored
 * 
 * \Reentrancy     non-reentrant
 * \Synchronism    synchronous
 * \Precondition   AES_ExpandKey must have been called before 
 *                 (at least once for the actual used AES key data)
 * \n
 * \reqtrace{BRQ_AES.doc}{BRQ_AES_002}                                                                           
 */
#if ((AES_OPERATIONMODE == AES_SYNCHRONOUS)&&(AES_DECRYPT == AES_ON))
extern void AES_Decrypt(const uint8_t * in, uint8_t * out);
#endif /* ((AES_OPERATIONMODE == AES_SYNCHRONOUS)&&(AES_DECRYPT == AES_ON)) */

 /**
 * Function to request the expanding of the AES security key.
 * 
 * Only available if AES_OPERATIONMODE is set to AES_ASYNCHRONOUS.
 * \n
 * This function requests the sequence to generate the round-keys - which are necessary for encryption
 * and decryption - from the 128 bit AES security key.
 * An accepted ExpandKey sequence ends in the configurable callback routine AES_EndExpandKey.
 * \n
 * Must be called at least once after system startup / 
 * after a change of the actual AES security key data, 
 * before AES_StartEncrypt or AES_StartDecrypt can be used.
 * 
 * \param[in]      key Pointer to the 16 byte array (128 bit) 
 *                     with the AES security key data that shall be used for
 *                     subsequent encryption or decryption sequences
 * \return         
 *                 - AES_ERR_OK:   request accepted \n
 *                 - AES_ERR_BUSY: request rejected, another sequence is in work
 * 
 * \Reentrancy     non-reentrant
 * \Synchronism    asynchronous
 * \Precondition   (System startup or a change of the AES key data)
 * \n
 */
#if (AES_OPERATIONMODE == AES_ASYNCHRONOUS)
extern aes_uint8 AES_StartExpandKey(const aes_uint8* key);
#endif /* (AES_OPERATIONMODE == AES_ASYNCHRONOUS) */

 /**
 * Function to request the AES encryption sequence.
 * 
 * Only available if AES_OPERATIONMODE is set to AES_ASYNCHRONOUS and
 * if AES_ENCRYPT is set to AES_ON.
 * \n
 * This function requests the sequence to generate 16 bytes encrypted output data from
 * 16 bytes plain input data.
 * An accepted encryption sequence ends in the configurable callback routine AES_EndEncrypt.
 * \n
 * \param[in]      in  Pointer to the 16 byte array
 *                     with the input data that shall be encrypted
 * \param[in,out]  out Pointer to the 16 byte array
 *                     where the encrypted output data shall be stored
 * \return         
 *                 - AES_ERR_OK:   request accepted \n
 *                 - AES_ERR_BUSY: request rejected, another sequence is in work
 * 
 * \Reentrancy     non-reentrant
 * \Synchronism    asynchronous
 * \Precondition   The ExpandKey sequence (AES_StartExpandKey) must be done once for the 
 *                 actual AES key data before calling this function.
 * \n
 * \reqtrace{BRQ_AES.doc}{BRQ_AES_001}                                                                           
 */
#if ((AES_OPERATIONMODE == AES_ASYNCHRONOUS)&&(AES_ENCRYPT == AES_ON))
extern aes_uint8 AES_StartEncrypt(const aes_uint8* in, aes_uint8* out);
#endif /* ((AES_OPERATIONMODE == AES_ASYNCHRONOUS)&&(AES_ENCRYPT == AES_ON)) */

 /**
 * Function to request the AES decryption sequence.
 * 
 * Only available if AES_OPERATIONMODE is set to AES_ASYNCHRONOUS and
 * if AES_DECRYPT is set to AES_ON.
 * \n
 * This function requests the sequence to generate 16 bytes decrypted output data from
 * 16 bytes encrypted input data.
 * An accepted decryption sequence ends in the configurable callback routine AES_EndDecrypt.
 * \n
 * \param[in]      in  Pointer to the 16 byte array
 *                     with the encrypted input data that shall be decrypted
 * \param[in,out]  out Pointer to the 16 byte array
 *                     where the decrypted output data shall be stored
 * \return         
 *                 - AES_ERR_OK:   request accepted \n
 *                 - AES_ERR_BUSY: request rejected, another sequence is in work
 * 
 * \Reentrancy     non-reentrant
 * \Synchronism    asynchronous
 * \Precondition   The ExpandKey sequence (AES_StartExpandKey) must be done once for the 
 *                 actual AES key data before calling this function.
 * \n
 * \reqtrace{BRQ_AES.doc}{BRQ_AES_002}                                                                           
 */
#if ((AES_OPERATIONMODE == AES_ASYNCHRONOUS)&&(AES_DECRYPT == AES_ON))
extern aes_uint8 AES_StartDecrypt(const aes_uint8* in, aes_uint8* out);
#endif /* ((AES_OPERATIONMODE == AES_ASYNCHRONOUS)&&(AES_DECRYPT == AES_ON)) */

/**
 * Handler statemachine which does the requested ExpandKey/ Encrypt/ Decrypt
 * sequences step by step in asynchronous operation mode.
 * 
 * Only available if AES_OPERATIONMODE is set to AES_ASYNCHRONOUS.
 * \n
 * Must be called frequently to get the work done.
 * No specific periodic cycle time necessary.
 * 
 * \param[in]      ---
 * 
 * \Reentrancy     non-reentrant
 * \Synchronism    asynchronous
 * \Precondition   ---
 * \n
 * \reqtrace{BRQ_AES.doc}{BRQ_AES_006}                                                                           
 */
#if (AES_OPERATIONMODE == AES_ASYNCHRONOUS)
extern void AES_Handler(void);
#endif /* (AES_OPERATIONMODE == AES_ASYNCHRONOUS) */

 /**
 * A help function to get information about whether the AES_Handler needs 
 * to be called or not.
 * 
 * Only available if AES_OPERATIONMODE is set to AES_ASYNCHRONOUS
 * \n
 * Can be used to detect the end of a requested sequence.
 * 
 * \param[in]      ---
 * \return         
 *                 - AES_FALSE: AES_Handler statemachine is set to idle state \n
 *                            - no need to call the AES_Handler \n
 *                            - a new sequence can be requested
 *                            .
 *                 - AES_TRUE: AES_Handler statemachine is not in idle state \n
 *                            - call the AES_Handler to finish the sequence
 *                            .
 * 
 * \Reentrancy     non-reentrant
 * \Synchronism    asynchronous
 * \Precondition   ---
 * \n
 * \reqtrace{BRQ_AES.doc}{BRQ_AES_006}                                                                           
 */
#if (AES_OPERATIONMODE == AES_ASYNCHRONOUS)
extern aes_boolean AES_Q_Busy(void);
#endif /* (AES_OPERATIONMODE == AES_ASYNCHRONOUS) */
 
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
 * FILE REVISION HISTORY                                               
 *-----------------------------------------------------------------------------  
 *                                     
 *  DATE          REV         AID          SCR         TASK        
 *      SUMMARY OF CHANGES                                 
 *  ---------------------------------------------------------------------------
 *  07-12-04      1.00        ABE          12345       67890 
 *      First revision                                     
 *  ---------------------------------------------------------------------------
 *  08-01-18      1.01        ABE
 *      According to code review:
 *      Removal of unused (empty) "reqtrace" comment lines
 *  ---------------------------------------------------------------------------
 *  19-08-01    BSA-1531    YF
 *  update DigKeyMgr logic
\*============================================================================*/

#endif   /* #ifdef AES_H */
/* END OF FILE -------------------------------------------------------------- */
