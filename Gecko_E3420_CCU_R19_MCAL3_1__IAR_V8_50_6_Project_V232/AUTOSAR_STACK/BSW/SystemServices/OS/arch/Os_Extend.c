/********************************************************************/
/*  Copyright (C) 2009-2011, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  File         Os_Extened.c
 *  Brief        Extended functions by FAW
 *
 *  Revision History:
 *
 *     V0.1.0  2015-03-23  Initial version, add this file.
 *     V0.2.0  2019-08-21  shun.li & zhiqiang.huang   Functional safety initial version.
 *     V1.0.0  2019-11-21  shun.li   Functional safety version.
 */
 /*******************************************************************/

/*=======[I N C L U D E S]====================================================*/
#include "Os_Extend.h"
/*=======[I N T E R N A L   D A T A]==========================================*/

/*=======[F U N C T I O N   I M P L E M E N T A T I O N S]====================*/
#define OS_START_SEC_CODE
#include "Os_MemMap.h"

/********************************************************************/
/*
 * Brief                <Provide Version information to user.>
 * Service ID           <none>
 * Sync/Async           <none>
 * Reentrancy           <Yes>
 * param-eventId[in]    <Versioninfo>
 * Param-Name[out]      <no>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * REQ ID               <None>
 */
/********************************************************************/
FUNC(void, OS_CODE) osGetVersionInfo(Std_VersionInfoType * osVerInfoPtr)
{
    if (NULL_PTR == osVerInfoPtr)
    {
        /*nothing to do*/
    }
    else
    {
        osVerInfoPtr->vendorID = OS_VENDOR_ID;
        osVerInfoPtr->moduleID = OS_MODULE_ID;
        //osVerInfoPtr->instanceID = 0;
        osVerInfoPtr->sw_major_version = OS_CFG_H_SW_MAJOR_VERSION;
        osVerInfoPtr->sw_minor_version = OS_CFG_H_SW_MINOR_VERSION;
        osVerInfoPtr->sw_patch_version = OS_CFG_H_SW_PATCH_VERSION;
    }
}
#if (CHECK_STACK_USAGE > 0)
/********************************************************************/
/*
 * Brief                <Get max usage of system,task,ISR2 stack.>
 * Service ID           <none>
 * Sync/Async           <none>
 * Reentrancy           <Yes>
 * param-eventId[in]    <id>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <osStackUsageType>
 * PreCondition         <None>
 * REQ ID               <DD_1_0707, DD_1_0709, DD_1_0708, DD_1_1323, DD_1_1324, DD_1_1325>
 */
/********************************************************************/
FUNC(osStackUsageType, OS_CODE) osGetStackUsage(osStackObject stack, uint16 id)
{
    osStackUsageType MaxUsage = 0U;
    uint32 const* ptr = NULL_PTR;
    uint32 const* stackBottom = NULL_PTR;
    uint32 const* stackTop = NULL_PTR;
    boolean Status = TRUE;
    OS_ARCH_DECLARE_CRITICAL();

    id = Os_GetObjLocalId(id);

    switch (stack)
    {
        case OS_STACK_SYSTEM:
        {
            stackBottom = Os_SystemStack->stackBottom;
            stackTop = Os_SystemStack->stackTop;
        }
        break;

        #if (CFG_TASK_MAX > 0U)
        case OS_STACK_TASK:
        {
            /* Input_para check. */
            if (id >= Os_CfgTaskMax)
            {
                Status = FALSE;
            }

            stackBottom = Os_TaskStack[id].stackBottom;
            stackTop = Os_TaskStack[id].stackTop;
        }
        break;
        #endif /* CFG_TASK_MAX > 0U */

        #if (CFG_ISR2_MAX > 0U)
        case OS_STACK_ISR2:
        {
            /* Input_para check. */
            if (id >= Os_CfgIsr2Max)
            {
                Status = FALSE;
            }

            stackBottom = Os_ISR2Stack[id].stackBottom;
            stackTop = Os_ISR2Stack[id].stackTop;
        }
        break;
        #endif /* CFG_ISR2_MAX > 0U */

        /*add comments to pass QAC.*/
        default:
            /* Nothing to do. */
            Status = FALSE;
            break;
    }

    if ((boolean)TRUE == Status)
    {
        OS_ARCH_ENTRY_CRITICAL();

        /*
         * MISRA-C:2004 Rule 17.4
         * Msg(4:0489) The integer value 1 is being added or subtracted from a
         *             pointer.
         */
        /* In stack storage area, all bytes are initialized to magic word(0xCC).
         * if this byte is used, the value will be changed. */
        for (ptr = stackBottom; ptr < stackTop; ptr++)
        {
            if (OS_STACK_FILL_PATTERN != (*ptr))
            {
                break;
            }
        }

        MaxUsage = (osStackUsageType)(stackTop - ptr);

        OS_ARCH_EXIT_CRITICAL();
    }

    return MaxUsage;
}
#endif

/********************************************************************/
/*
 * Brief                <check ISR source>
 * Service ID           <none>
 * Sync/Async           <none>
 * Reentrancy           <Yes>
 * param-eventId[in]    <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <StatusType>
 * PreCondition         <None>
 * REQ ID               <None>
 */
/********************************************************************/
FUNC(StatusType, OS_CODE) osCheckISRSource(uint32 Source)
{
    StatusType osRet = FALSE;

    /* OS263. */
    #if ((CFG_ISR2_MAX > 0) && (CFG_SC == OS_SC4))
    if (OS_LEVEL_ISR2 == Os_SCB.sysOsLevel)
    {
        if (OS_ISR_CATEGORY2 == Os_IsrCfg[Os_IntCfgIsrId].OsIsrCatType)
        {
            if (Source == Os_IsrCfg[Os_IntCfgIsrId].OsIsrSrc)
            {
                osRet=TRUE;
            }
        }
    }
    #else
    (void)Source;
    #endif /* (CFG_ISR2_MAX > 0) && (CFG_SC == OS_SC4) */

    return osRet;
}

/********************************************************************/
/*
 * Brief                <check whether CPU information is correct.>
 * Service ID           <none>
 * Sync/Async           <none>
 * Reentrancy           <Yes>
 * param-eventId[in]    <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <StatusType>
 * PreCondition         <None>
 * REQ ID               <None>
 */
/********************************************************************/
FUNC(void, OS_CODE) osCheckCPUInformation(void)
{
   
}

/********************************************************************/
/*
 * Brief                <check whether safety register is correct.>
 * Service ID           <none>
 * Sync/Async           <none>
 * Reentrancy           <Yes>
 * param-eventId[in]    <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * REQ ID               <None>
 */
/********************************************************************/
FUNC(void, OS_CODE) osCheckSafeTRegister(void)
{
    
}
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

/*=======[E N D   O F   F I L E]==============================================*/
