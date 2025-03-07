
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
**  FILENAME    : Cal_Cfg.h                                                   **
**                                                                            **
**  Created on  : 2023/09/15 16:21:42                                         **
**  Author      : long.zhu                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : Config File for CRC Module.                                 **
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
#ifndef CAL_CFG_H
#define CAL_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/*  CRC method */
#define CAL_CRC16          0x00u
#define CAL_CRC32          0x01u
#define CAL_CRC8           0x02u
#define CAL_HASH256        0x03u
#define CAL_AES128_CMAC    0x04u

#define CAL_METHOD    CAL_CRC32

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

#endif

