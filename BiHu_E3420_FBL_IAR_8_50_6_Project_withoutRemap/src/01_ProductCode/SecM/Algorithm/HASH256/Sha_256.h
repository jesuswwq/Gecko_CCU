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
**  FILENAME    : Sha_256.h                                                   **
**                                                                            **
**  Created on  :                                                             **
**  Author      : long.zhu                                               	  **
**  Vendor      :                                                             **
**  DESCRIPTION : Compute SHA256 hash value source file.                      **
**                                                                            **
**  SPECIFICATION(S) :  NONE                    		                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/** <VERSION>   <DATE>     <AUTHOR>          <REVISION LOG>
 *  V1.0.0       20190907  long.zhu    		Initial version
 *  V1.0.1       20200314  Lianren.Wu    	QAC 9.5 test
 */

#ifndef SHA_256_H
#define SHA_256_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define RET_OK  			0u
#define RET_OVER_LIMIT 		1u

#define SHA256_LENGTH		32u

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/** return type for SecM module */
typedef uint8 SecM_Sha256_StatusType;

typedef struct
{
	uint8   Value[SHA256_LENGTH];
	uint32  DwordBufBytes;
	uint32  ByteNumLo;
	uint32  ByteNumHi;
	uint32  reg[8u]; /** h0 to h 7 -- old value store*/
	uint32  DwordBuf[16u]; /** data store */
	uint32  Padding[64u];
}Sha256Calc;

/** struct type for Crc */
typedef struct
{
    /* CRC buffer point */
    const uint8 *Sha256SourceBuffer;
    /* Sha256 length */
    uint16 Sha256ByteCount;
    /* current Sha256 value */
    Sha256Calc CurrentSha256;

} SecM_Sha256ParamType;

/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
/******************************************************************************/
/**
 * @brief               <initialization>
 *
 * <Sha 256 calculation initialization> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <t(IN)>
 * @param[out]          <t(OUT)>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
extern void Sha256Calc_init( Sha256Calc* t);

/******************************************************************************/
/**
 * @brief               <Sha256Calc_calculate>
 *
 * <Sha 256 calculation> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <t(IN),dp(IN),dl(IN)>
 * @param[out]          <t(OUT)>
 * @param[in/out]       <NONE>
 * @return              <ret>
 */
/******************************************************************************/
extern uint8 Sha256Calc_calculate( Sha256Calc* t, const uint8* dp, uint32 dl );

#endif/* endif of _SHA_256_H */
