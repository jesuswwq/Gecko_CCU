/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2023)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : Aes128.h                                                       **
**                                                                            **
**  Created on  :                                                             **
**  Author      : long.zhu                                               	  **
**  Vendor      :                                                             **
**  DESCRIPTION : Aes128 algorithm.                				              **
**                                                                            **
**  SPECIFICATION(S) :  NONE                    		                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/** <VERSION>   <DATE>     <AUTHOR>          <REVISION LOG>
 *    V1.0.0    20220714   Xinglin Li	 New Version
 */

#ifndef AES128_H
#define AES128_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define AES_ENCRYPT     1 /**< AES encryption. */
#define AES_DECRYPT     0 /**< AES decryption. */

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
typedef struct
{
    int nr;                     /*!< The number of rounds. */
    uint32 *rk;               /*!< AES round keys. */
    uint32 buf[68];           /*!< Unaligned data buffer. This buffer can
                                     hold 32 extra Bytes,which can be used for
                                     one of the following purposes:
                                     <ul><li>Alignment if VIA padlock is
                                             used.</li>
                                     <li>Simplifying key expansion in the 256-bit
                                         case by generating an extra round key.
                                         </li></ul> */
}Crypto_AESData;

/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
extern Std_ReturnType Crypto_aes_setkey_enc( Crypto_AESData *ctx,uint8* key,
                    uint16 keybits);
extern Std_ReturnType Crypto_aes_setkey_dec( Crypto_AESData *ctx,uint8* key,
                    uint16 keybits);
extern Std_ReturnType Crypto_aes_crypt_ecb( Crypto_AESData *ctx,
                    uint8 mode,
                    const uint8 input[16],
                    uint8 output[16]);
extern Std_ReturnType Crypto_aes_crypt_cbc( Crypto_AESData *ctx,
        uint8 mode,uint8 length,uint8 iv[16],
		uint8* input,
		uint8* output);
extern Std_ReturnType Crypto_AESEncryptECB(uint8* key,uint8 buf[64]);
extern Std_ReturnType Crypto_AESDecryptECB(uint8* key,uint8 buf[64]);
extern Std_ReturnType Crypto_AESEncryptCBC(uint8* key,uint8 buf[64],
        uint8 iv[16],uint8 inputlength);
extern Std_ReturnType Crypto_AESDecryptCBC(uint8* key,uint8 buf[16],
        uint8 iv[16],uint8 inputlength);
extern Std_ReturnType Crypto_AESEncryptCTR(uint8* key,uint8 buf[64],
        uint8 iv[16]);
extern Std_ReturnType Crypto_AESDecryptCTR(uint8* key,uint8 buf[64],
        uint8 iv[16]);

extern void Crypto_memset(void *buf, uint32 len);

#endif /*AES128_H */
