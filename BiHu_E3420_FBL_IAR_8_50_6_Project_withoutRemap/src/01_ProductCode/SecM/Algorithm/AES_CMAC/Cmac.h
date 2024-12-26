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
**  FILENAME    : Cmac.h                                                      **
**                                                                            **
**  Created on  :                                                             **
**  Author      :  Xinglin Li                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : Cmac algorithm.                                             **
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

#ifndef CMAC_H
#define CMAC_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
/********************************************************************************/
/****
 * brief			:Crypto_GernerateMAC
 *
 * Sync/Async		: <Synchronous>
 * Reentrancy		: <Non reentrant>
 * param[in]		: <MAC : Pointer to message authentication code>
 *                    <Key : Pointer to encryption key>
 *                    <IVKey : Pointer to the initial vector>
 *                    <add : Pointer for plain text input>
 *                    <inputlength : Enter plain text length>
 * param[out]	    : <NONE>
 * param[in/out]	: <NONE>
 * return		    : <NONE>
 */
/********************************************************************************/
Std_ReturnType Crypto_GernerateMAC(
		uint8* Key,
        uint8* inputData,
        uint32 inputlength,
		uint8* OutPutData);

#endif /* CMAC_H */
