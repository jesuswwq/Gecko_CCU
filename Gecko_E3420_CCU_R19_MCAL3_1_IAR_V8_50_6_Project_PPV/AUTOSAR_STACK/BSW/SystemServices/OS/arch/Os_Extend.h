/*============================================================================*/
/*  Copyright (C) 2009-2011, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Os_Extend.h>
 *  @brief      <>
 *  
 * <Compiler:  IAR    MCU:CYT2BX>
 *  
 *  @author     <bo.zeng>
 *  @date       <07-08-2015>
 */
/*============================================================================*/
/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>    <DATE>    <AUTHOR>    <REVISION LOG>
 *  V0.1.0       2015-08-07  bo.zeng       Initial version.
 *  V0.2.0       2019-08-21  shun.li & zhiqiang.huang   Functional safety initial version.
 *  V1.0.0       2019-11-21  shun.li       Functional safety version.
 */
/*============================================================================*/
#ifndef OS_EXTEND_H
#define OS_EXTEND_H

/*=======[M I S R A C  R U L E  V I O L A T I O N]============================*/
/*  <MESSAGE ID>    <CODE LINE>    <REASON>
 */
/*============================================================================*/

/*=======[I N C L U D E S]====================================================*/
#include "Os_Types.h"
#include "Os_Internal.h"
/*=======[M A C R O S]========================================================*/
/* Types of stack usage. */
/* DD_1_0058 */
typedef uint32           osStackUsageType;

/* The type of context save area. */
/* DD_1_0059 */
typedef uint32           osCsaUsageType;

/* Enumeration type of stack object. */
/* DD_1_0060 */
typedef enum
{
    OS_STACK_SYSTEM      = 0U,
    OS_STACK_TASK        = 1U,
    OS_STACK_ISR2        = 2U
}osStackObject;

/*=======[E X T E R N A L   D A T A]==========================================*/

/*=======[F U N C T I O N   D E C L A R A T I O N S]========*/
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
FUNC(void, OS_CODE) osGetVersionInfo(Std_VersionInfoType * osVerInfoPtr);

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
 * REQ ID               <None>
 */
/********************************************************************/
FUNC(osStackUsageType, OS_CODE) osGetStackUsage(osStackObject stack, uint16 id);
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
extern FUNC(StatusType, OS_CODE) osCheckISRSource(uint32 Source);

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
FUNC(void, OS_CODE) osCheckCPUInformation(void);

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
FUNC(void, OS_CODE) osCheckSafeTRegister(void);

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
#endif /* #ifndef OS_EXTEND_H */
/*=======[E N D   O F   F I L E]==============================================*/
