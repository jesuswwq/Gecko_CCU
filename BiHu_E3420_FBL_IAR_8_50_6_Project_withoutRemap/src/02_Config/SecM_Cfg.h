
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
**  FILENAME    : SecM_Cfg.h                                                  **
**                                                                            **
**  Created on  : 2023/11/23 14:59:01                                         **
**  Author      : long.zhu                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : Config File for Security Module.                            **
**                                                                            **
**  SPECIFICATION(S) : NONE                                                   **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/** <VERSION>   <DATE>     <AUTHOR>          <REVISION LOG>
 *  V1.0.0     20230818     long.zhu         Initial Version
 */

#ifndef SECM_CFG_H
#define SECM_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* security constant length */
#define SECM_SECCONST_LENGTH            0x4u

/* CAL check length once for SecM_ProcessCal. */
#define SECM_CAL_BUFFER_LEN            0x1000u

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/
/* security constant for security access */
extern const uint8 SecM_SecConst[SECM_SECCONST_LENGTH];

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

#endif/* endif of SECM_CFG_H */

