/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2022)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : Eep_62_Cbk.h                                                **
**                                                                            **
**  Created on  : 2022/02/15                                                  **
**  Author      : Haibin.Shao                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

/*======================[Revision   History]==================================*/
/*  <VERSION>   <DATE>      <AUTHOR>        <REVISION LOG>
 *  V1.0.0      20210123    Haibin.Shao     Initial Version

 */
/*============================================================================*/
#ifndef EEP_62_CBK_H
#define EEP_62_CBK_H

/*==============[Includes]====================================================*/
#include "Std_Types.h"
#include "Eep_62_Cfg.h"

/*===================[External Function Declarations]=========================*/
extern FUNC(void, EEP_PUBLIC_CODE) Eep_62_JobEndNotification(void);
extern FUNC(void, EEP_PUBLIC_CODE) Eep_62_JobErrorNotification(void);

#endif
