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
**  FILENAME    : Rte_SchM.c                                                      **
**                                                                            **
**  Created on  : 2020-11-25                                                  **
**  Author      : qinchun.yang                                                **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*  <VERSION>    <DATE>      <AUTHOR>        <REVISION LOG>
 *  V1.0.0       2020-04-08  qinchun.yang    SchM initial version.
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Rte_SchM.h"
#include "Os.h"
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE)
SchM_Start(void)
{
}

FUNC(void, RTE_CODE)
SchM_Init(P2CONST(SchM_ConfigType, AUTOMATIC, RTE_APPL_DATA) ConfigPtr)
{
    (void)ConfigPtr;
}

FUNC(void, RTE_CODE)
SchM_Deinit(void)
{
}

FUNC(void, RTE_CODE)
SchM_StartTiming(void)
{
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
