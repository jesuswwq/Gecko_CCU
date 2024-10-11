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
**  FILENAME    : EcuM_Lcfg.c                                                 **
**                                                                            **
**  Created on  : 2023/08/28 15:07:16                                         **
**  Author      :                                                             **
**  Vendor      :                                                             **
**  DESCRIPTION : Configure data for Link time configuration of ECUM          **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "EcuM.h"

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
#define ECUM_START_SEC_CONST_32
#include "EcuM_MemMap.h"
/*EcuMConfigConsistencyHash, a hash value generated across all pre-compile and
 *link-time parameters of all BSW modules. This hash value is compared against
 *a field in the EcuM_ConfigType and hence allows checking the consistency of
 *the entire configuration.*/
CONST(uint32, ECUM_CONST) EcuM_ConfigConsistencyHash = 0xffuL;
#define ECUM_STOP_SEC_CONST_32
#include "EcuM_MemMap.h"

/*******************************************************************************
**                            General Notes                                   **
*******************************************************************************/

