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
**  FILENAME    : Det_Externals.c                                             **
**                                                                            **
**  Created on  : 2023-08-29 10:41:31                                         **
**  Author      : ShaoHaiBin                                                  **
**  Vendor      : isoft                                                       **
**  DESCRIPTION : Implementation for Det                                      **
**                                                                            **
**  SPECIFICATION(S) :            **                                          **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
** Configuration description :
** All configurations of the DET module are not dependent on tool generation,
** and all configuration items are fixed
*******************************************************************************/

/*==============================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==============================================================================*/
#include "Det_Externals.h"

/* todo: Add the header file reference for the corresponding module */

#define DET_START_SEC_CODE
#include "Det_MemMap.h"

#define DET_STOP_SEC_CODE
#include "Det_MemMap.h"
