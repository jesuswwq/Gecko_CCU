/*----------------------------------------------------------------------------+
|                                                                             |
|              Copyright (C),  NXP Semiconductors Germany GmbH, BL AS&C       |
|                                                                             |
|  All rights are reserved. Reproduction in whole or in part is prohibited    |
|           without the written consent of the copyright owner.               |
|                                                                             |
|  NXP reserves the right to make changes without notice at any time.         |
| NXP makes no warranty, expressed, implied or statutory, including but       |
| not limited to any implied warranty of merchantibility or fitness for any   |
|   particular purpose, or that the use will not infringe any third party     |
| patent, copyright or trademark. NXP must not be liable for any loss or      |
|                      damage arising from its use.                           |
|                                                                             |
+-----------------------------------------------------------------------------+
|                       Hitag2/Pro/AES on ABIC 2 Demonstrator 
|
| Name of the Project:  NX100611A - HT-Pro on ABIC2
|                       NX100727A - HT-AES on ABIC2
| Used Platform:        PCF7953P
| File:                 AES128SWEnc.h
|
| Author(s):            B. Biehl   (telos GmbH, Schlüterstr. 16, 20146 Hamburg)
|
|
+----------+-----+-----------+-------+-----------------------------------------
|   DATE   | Ver |   State   |   By  |            CHANGES DONE
+----------+-----+-----------+-------+-----------------------------------------
| 02.07.10 | 1.0 |           | Biehl | created
+----------+-----+-----------+-------+-----------------------------------------
| 16.07.10 |     |           | Biehl | include compile switch for HT-Pro
+----------+-----+-----------+-------+-----------------------------------------
| 02.08.10 |     |           | Biehl | derive module from HT-Pro Demonstrator
+----------+-----+-----------+-------+-----------------------------------------
| 
+------------------------------------------------------------------------------
| Description:
|
+-----------------------------------------------------------------------------*/


#ifndef __AES128SWENC_H
#define __AES128SWENC_H

#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define BYTE      uint8_t

#define IDATA

#define XDATA     const

#define bit bool

/* Fetch bit "b" out of "a" */
#define GETBIT(a,b)    (uint8_t) ( ( (a) & ( 1u << (b) ) ) >> (b) )

//Prototypes
void AESInit (BYTE IDATA * pcAESInbuf);

void AES128Enc (BYTE IDATA * pcAESSecretKey);

void AESCrypt (BYTE IDATA * pcAESData, BYTE pcAESLen);

#endif    // __AES128SWENC_H