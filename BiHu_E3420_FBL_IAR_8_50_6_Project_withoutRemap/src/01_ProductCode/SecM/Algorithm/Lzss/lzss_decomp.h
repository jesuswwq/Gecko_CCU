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
**  FILENAME    : lzss_decomp.h                                               **
**                                                                            **
**  Created on  :                                                             **
**  Author      : lzss decomp.                                            	  **
**  Vendor      :                                                             **
**  DESCRIPTION : function declarations for CRC.                              **
**                                                                            **
**  SPECIFICATION(S) :  NONE                    		                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/** <VERSION>   <DATE>     <AUTHOR>          <REVISION LOG>
 *    V1.0.0    20220322   long.zhu	     modify Function and variable type
 */
#ifndef _LZSS_DECOMP_H_
#define _LZSS_DECOMP_H_

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Platform_Types.h"

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define COMP_BUFFER_LEN 	128u

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
typedef struct
{
	uint8 *buff;
	uint8  mask;
	uint32 rack;
	uint32 pacifier_counter;
	uint32 PcCount;
	uint16 lastreaminbit;
	uint8  lastreaminbitlength;
} BIT_BUFF;

/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
/******************************************************************************/
/**
 * @brief               <Init Decomp.>
 *
 * 						<init Decomp variable.> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
extern void Lzss_InitDecomp(void);
/******************************************************************************/
/**
 * @brief               <Lzss algorithm decomp.>
 *
 * 						<Lzss algorithm decomp.>
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
extern void Lzss_Decomp(uint8 *Buf, uint32 Length, BIT_BUFF *outBuf);

#endif /* _LZSS_DECOMP_H_ */
