/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2016)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : Os_Trap.c                                                   **
**                                                                            **
**  Created on  :                                                             **
**  Author      : shun.li                                                     **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>    <DATE>    <AUTHOR>        <REVISION LOG>
 *  V0.1.0     2021-07-06   shun.li        Initial version.
 */
/*============================================================================*/
#include "Os_Internal.h"

#define OS_START_SEC_CODE
#include "Os_MemMap.h"

void TrapExceptionHandler(void)
{
    #if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
    Os_ArchSetTruReg();
    #endif /* ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC)) */

    #if ((OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
    #if (TRUE == CFG_PROTECTIONHOOK)
    uint32 WhoHook = OS_TMPROT_HOOK_OSAPP;

    if (OS_LEVEL_TASK == Os_SCB.sysOsLevel)
    {
        WhoHook = OS_TMPROT_HOOK_TASK;
    }
    else if (OS_LEVEL_ISR2 == Os_SCB.sysOsLevel)
    {
        WhoHook = OS_TMPROT_HOOK_ISR;
    }
    else
    {
        /* Do nothing. */
    }
    #endif /* TRUE == CFG_PROTECTIONHOOK */
    #endif /* (OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC)*/

    #if ((OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
    #if (TRUE == CFG_ERRORHOOK)
    (void)ErrorHook(E_OS_PROTECTION_MEMORY);
    #endif /* TRUE == CFG_ERRORHOOK */
    /* OS245:  protection exception hook. */
    #if (TRUE == CFG_PROTECTIONHOOK)
    (void)Os_CallProtectionHook(E_OS_PROTECTION_MEMORY, WhoHook);
    #endif /* TRUE == CFG_PROTECTIONHOOK */
    #else /* CFG_SC ==  OS_SC1 */
    #if (TRUE == CFG_ERRORHOOK)
    (void)ErrorHook(E_OS_PROTECTION_MEMORY);
    #endif /* TRUE == CFG_ERRORHOOK */
    while(1)
    {
        /* nothing to do. */
    }
    #endif /* (OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC)*/
}
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
/*=======[E N D   O F   F I L E]==============================================*/