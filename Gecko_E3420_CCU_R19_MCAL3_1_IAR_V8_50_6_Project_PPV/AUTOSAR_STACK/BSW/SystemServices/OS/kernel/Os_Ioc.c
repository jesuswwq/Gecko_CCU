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
**  FILENAME    : Os_Ioc.c                                                    **
**                                                                            **
**  Created on  :                                                             **
**  Author      : shun.li                                                     **
**  Vendor      :                                                             **
**  DESCRIPTION : IOC manager                                                 **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>    <DATE>    <AUTHOR>    <REVISION LOG>
 *  V0.1.0       2020-01-06  shun.li    Initial version.
 *  V0.2.0       2020-03-21  shun.li    Add multiple pipes parallel communication.
 *  V0.3.0       2020-10-29  shun.li    Repair the api function of IocEmptyQueue,
 *                                      and repair the pipe communication of LIFO rule.
 *  V0.4.0       2021-04-13  shun.li    code review.
 *  V0.5.0       2021-04-28  shun.li    Modify code to adapt MISRA C specification.
 *  V1.0.0       2022-02-23  shun.li    Repair the FIFO communication and adjust the code rule.
 */
/*============================================================================*/

/*=======[M I S R A C  R U L E  V I O L A T I O N]============================*/
/*  <MESSAGE ID>    <CODE LINE>    <REASON>
 */
/*============================================================================*/

/*=======[I N C L U D E S]====================================================*/
#include "Os_Internal.h"

#if (CFG_IOC_MAX > 0U) /* PRQA S 3332 */ /* MISRA Rule 20.9 */
#define LIST_HEAD_INIT(name) \
    {                        \
        &(name)              \
    }
#define LIST_HEAD(name)                    Os_IocListNodeType name = LIST_HEAD_INIT(name)
#define OS_OFFSETOF(TYPE, MEMBER)          ((uint32)(&((TYPE*)0)->MEMBER))
#define OS_CONTAINER_OF(ptr, type, member) (type*)((void*)((char*)(ptr)-OS_OFFSETOF(type, member)));

#if (CFG_IOC_MAX_LOCAL > 0U)
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
static Os_IocCBType* OSIocCBLocalPtr = (Os_IocCBType*)0;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
static Os_IocMsgCBType* OSIocMsgCBlocalPtr = (Os_IocMsgCBType*)0;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
static Os_IocListNodeType* OSIocMsgHeadLocalPtr = (Os_IocListNodeType*)0;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
static Os_IocListNodeType* OSIocMsgNodeLocalPtr = (Os_IocListNodeType*)0;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
static Os_IocU16Type OSIocCfgLocalMax = (Os_IocU16Type)0;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
static Os_IocU16Type OSIocMsgCfgLocalMax = (Os_IocU16Type)0;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
static const Os_IocBuffType* OSIocBuffLocalPtr = (Os_IocBuffType*)0;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
static const Os_IocPipeCfgType* OSStdPipeCfgLocalPtr = (Os_IocPipeCfgType*)0;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#endif

#if (CFG_IOC_MAX_GLOBAL > 0U)
#define OS_START_SEC_VAR_NOINIT_GLOBAL
#include "Os_MemMap.h"
static const Os_IocBuffType* OSIocBuffGlobalPtr = (Os_IocBuffType*)0;
#define OS_STOP_SEC_VAR_NOINIT_GLOBAL
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_NOINIT_GLOBAL
#include "Os_MemMap.h"
static Os_IocCBType* OSIocCBGlobalPtr = (Os_IocCBType*)0;
#define OS_STOP_SEC_VAR_NOINIT_GLOBAL
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_NOINIT_GLOBAL
#include "Os_MemMap.h"
static Os_IocMsgCBType* OSIocMsgCBGlobalPtr = (Os_IocMsgCBType*)0;
#define OS_STOP_SEC_VAR_NOINIT_GLOBAL
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_NOINIT_GLOBAL
#include "Os_MemMap.h"
static Os_IocU16Type OSIocCfgGlobalMax = (uint16)0;
#define OS_STOP_SEC_VAR_NOINIT_GLOBAL
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_NOINIT_GLOBAL
#include "Os_MemMap.h"
static Os_IocU16Type OSIocMsgCfgGlobalMax = (uint16)0;
#define OS_STOP_SEC_VAR_NOINIT_GLOBAL
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_NOINIT_GLOBAL
#include "Os_MemMap.h"
static Os_IocListNodeType* OSIocMsgHeadGlobalPtr = (Os_IocListNodeType*)0;
#define OS_STOP_SEC_VAR_NOINIT_GLOBAL
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_NOINIT_GLOBAL
#include "Os_MemMap.h"
static Os_IocListNodeType* OSIocMsgNodeGlobalPtr = (Os_IocListNodeType*)0;
#define OS_STOP_SEC_VAR_NOINIT_GLOBAL
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_NOINIT_GLOBAL
#include "Os_MemMap.h"
static const Os_IocPipeCfgType* OSStdPipeCfgGlobalPtr = (Os_IocPipeCfgType*)0;
#define OS_STOP_SEC_VAR_NOINIT_GLOBAL
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_NOINIT_GLOBAL
#include "Os_MemMap.h"
static Os_IocU32Type Os_IocMailLock = (Os_IocU32Type)0;
#define OS_STOP_SEC_VAR_NOINIT_GLOBAL
#include "Os_MemMap.h"
#endif

#if (CFG_IOC_MAX_GLOBAL > 0U)
#define OS_START_SEC_VAR_NOINIT_GLOBAL
#include "Os_MemMap.h"
static LIST_HEAD(OSIocMsgGlobalHead);
#define OS_STOP_SEC_VAR_NOINIT_GLOBAL
#include "Os_MemMap.h"
#endif

#if (CFG_IOC_MAX_LOCAL > 0U)
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
static LIST_HEAD(OSIocMsgLocalHead);
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#endif

/*=======[I N T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/
#if (CFG_IOC_MAX_LOCAL > 0U)
static FUNC(StatusType, OS_CODE) Os_IocInterReceive(Os_IocAbsIdType absId, const Os_IocDataSourceType* pRcvData);
#endif

#if (CFG_IOC_MAX_LOCAL > 0U)
static FUNC(StatusType, OS_CODE) Os_IocInterTransmit(Os_IocAbsIdType absId, const Os_IocDataSourceType* transData);
#endif

#if (CFG_IOC_MAX_GLOBAL > 0U)
static FUNC(StatusType, OS_CODE) Os_IocCrossTransmit(Os_IocAbsIdType absId, const Os_IocDataSourceType* transData);
#endif

static FUNC(StatusType, OS_CODE) Os_LLSendData(const Os_IocDataSourceType* pData, Os_IocCBType* pIocCB);

static FUNC(Os_IocMsgCBType*, OS_CODE) Os_MallocMessage(Os_IocListNodeType** pqHead, Os_IocListNodeType** pqNode);

static FUNC(StatusType, OS_CODE) Os_LLWriteData(const Os_IocDataSourceType* pData, Os_IocCBType* pIocCB);

static FUNC(void, OS_CODE) Os_InsertListAfter(Os_IocListNodeType* pNode, Os_IocListNodeType** pqObject);

#if (TRUE == OS_IOC_CHECKINPARA)
static FUNC(StatusType, OS_CODE) Os_IocCheckInPara(Os_IocAbsIdType absId, const Os_IocDataSourceType* pData);
#endif

static FUNC(StatusType, OS_CODE)
    Os_IocCheckPipeMemPoolUsage(Os_IocAbsIdType absId, const Os_IocDataSourceType* pDataSource, StatusType* outRet);

static FUNC(void, OS_CODE) Os_MemCopyWithOut(
    void* dest,
    void* src,
    Os_IocU32Type size,
    Os_BuffDataDirectionType directOfData,
    Os_IocU8Type** pOut);

static FUNC(void, OS_CODE) Os_MemCopyWithoutOut(void* dest, void* src, Os_IocU32Type size);

#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
static FUNC(StatusType, OS_CODE)
    Os_CheckSafeContext(Os_IocAbsIdType ix, Os_IocTransferType transfer, StatusType* outRet);
#endif

/*=======[F U N C T I O N   I M P L E M E N T A T I O N S]====================*/
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
/******************************************************************************/
/*
 * Brief                <Init IOC control block.>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <>
 * REQ ID               <>
 */
/******************************************************************************/
static FUNC(void, OS_CODE) Os_InitIocCB(void)
{
    Os_IocU16Type ix;
    Os_IocDateType memSize;
    Os_IocMemPoolType* pMemPool;
    const Os_IocPipePrpeType* pPipeCfg;

/* NOTE!! ++-->Init the global area to cross-core IOC communication in master core. */
#if (CFG_IOC_MAX_GLOBAL > 0U)
    if (OS_CORE_ID_MASTER == Os_SCB.sysCore)
    {
        for (ix = (Os_IocU16Type)0; ix < OSIocCfgGlobalMax; ix++)
        {
            pPipeCfg = OSStdPipeCfgGlobalPtr[ix].IocPipeCfgPtr;
            memSize = pPipeCfg->IocMemPoolSize;
            pMemPool = OSIocBuffGlobalPtr[ix].MemPtr;
            OSIocCBGlobalPtr[ix].IocMemPoolPtr = pMemPool;
            OSIocCBGlobalPtr[ix].IocListHead.IocNextNode = (Os_IocListNodeType*)0;
            OSIocCBGlobalPtr[ix].IocPipelistCnt = (Os_IoclistCntType)0;
            OSIocCBGlobalPtr[ix].IocPtrTailNode = &(OSIocCBGlobalPtr[ix].IocListHead);
            OSIocCBGlobalPtr[ix].IocMemPoolHeadPtr = pMemPool;
            OSIocCBGlobalPtr[ix].IocMemPoolTailPtr = pMemPool + memSize - 1u; /* PRQA S 0488 */ /* MISRA Rule 18.4 */
            OSIocCBGlobalPtr[ix].IocMemPoolUsage = (Os_IocDateType)0;
            OSIocCBGlobalPtr[ix].IocCoreComMark = pPipeCfg->IocCfgComMark;
            OSIocCBGlobalPtr[ix].IocSemantics = pPipeCfg->IocCfgSemantics;
            OSIocCBGlobalPtr[ix].IocQueueCom = pPipeCfg->IocCfgQueueCom;
            OSIocCBGlobalPtr[ix].IocInParaNum = pPipeCfg->IocCfgInParaNum;
        }
    }
#endif

/* NOTE!! ++-->Each core shall init local IOC control block. */
#if (CFG_IOC_MAX_LOCAL > 0U)
    for (ix = (Os_IocU16Type)0; ix < OSIocCfgLocalMax; ix++)
    {
        pPipeCfg = OSStdPipeCfgLocalPtr[ix].IocPipeCfgPtr;
        memSize = pPipeCfg->IocMemPoolSize;
        pMemPool = OSIocBuffLocalPtr[ix].MemPtr;
        OSIocCBLocalPtr[ix].IocMemPoolPtr = pMemPool;
        OSIocCBLocalPtr[ix].IocListHead.IocNextNode = (Os_IocListNodeType*)0;
        OSIocCBLocalPtr[ix].IocPipelistCnt = (Os_IoclistCntType)0;
        OSIocCBLocalPtr[ix].IocPtrTailNode = &(OSIocCBLocalPtr[ix].IocListHead);
        OSIocCBLocalPtr[ix].IocMemPoolHeadPtr = pMemPool;
        OSIocCBLocalPtr[ix].IocMemPoolTailPtr = pMemPool + memSize - 1u; /* PRQA S 0488 */ /* MISRA Rule 18.4 */
        OSIocCBLocalPtr[ix].IocMemPoolUsage = (Os_IocDateType)0;
        OSIocCBLocalPtr[ix].IocCoreComMark = pPipeCfg->IocCfgComMark;
        OSIocCBLocalPtr[ix].IocSemantics = pPipeCfg->IocCfgSemantics;
        OSIocCBLocalPtr[ix].IocQueueCom = pPipeCfg->IocCfgQueueCom;
        OSIocCBLocalPtr[ix].IocInParaNum = pPipeCfg->IocCfgInParaNum;
    }
#endif
}

/******************************************************************************/
/*
 * Brief                <Init the IOC message control block.>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <>
 * REQ ID               <>
 */
/******************************************************************************/
static FUNC(void, OS_CODE) Os_InitIocMsgCB(void)
{
    Os_IocU16Type ix;

/* NOTE!! ++-->Init global IOC message control block. */
#if (CFG_IOC_MAX_GLOBAL > 0U)
    if (OS_CORE_ID_MASTER == Os_SCB.sysCore)
    {
        for (ix = (Os_IocU16Type)0; ix < OSIocMsgCfgGlobalMax; ix++)
        {
            OSIocMsgCBGlobalPtr[ix].IocPtrMemPoolPosition = (Os_IocMemPoolPtrType)0;
            OSIocMsgCBGlobalPtr[ix].IocDataLenth = 0xFFFFFFFFU;
            OSIocMsgCBGlobalPtr[ix].IocListNodeInfo.IocNextNode = (Os_IocListNodeType*)0;
            OSIocMsgCBGlobalPtr[ix].IocMsgFormat = MSG_FORMAT_ONE;
        }
    }
#endif

/* NOTE!! ++-->Init local IOC message control block. */
#if (CFG_IOC_MAX_LOCAL > 0U)
    for (ix = (Os_IocU16Type)0; ix < OSIocMsgCfgLocalMax; ix++)
    {
        OSIocMsgCBlocalPtr[ix].IocPtrMemPoolPosition = (Os_IocMemPoolPtrType)0;
        OSIocMsgCBlocalPtr[ix].IocDataLenth = 0XFFFFFFFFU;
        OSIocMsgCBlocalPtr[ix].IocListNodeInfo.IocNextNode = (Os_IocListNodeType*)0;
        OSIocMsgCBlocalPtr[ix].IocMsgFormat = MSG_FORMAT_ONE;
    }
#endif
}

/******************************************************************************/
/*
 * Brief                <Init the IOC control block list.>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <>
 * REQ ID               <>
 */
/******************************************************************************/
static FUNC(void, OS_CODE) Os_InitIocMsgList(void)
{
    Os_IocU16Type ix;
#if (CFG_IOC_MAX_LOCAL > 0U)
    OSIocMsgHeadLocalPtr = &OSIocMsgLocalHead;
    OSIocMsgNodeLocalPtr = &OSIocMsgLocalHead;
#endif

/* NOTE!! ++-->Init global IOC message list. */
#if (CFG_IOC_MAX_GLOBAL > 0U)
    if (OS_CORE_ID_MASTER == Os_SCB.sysCore)
    {
        OSIocMsgHeadGlobalPtr = &OSIocMsgGlobalHead;
        OSIocMsgNodeGlobalPtr = &OSIocMsgGlobalHead;
        for (ix = (Os_IocU16Type)0; ix < OSIocMsgCfgGlobalMax; ix++)
        {
            Os_InsertListAfter(&(OSIocMsgCBGlobalPtr[ix].IocListNodeInfo), &OSIocMsgNodeGlobalPtr);
        }
    }
#endif

/* NOTE!! ++-->Init local IOC message list. */
#if (CFG_IOC_MAX_LOCAL > 0U)
    for (ix = (Os_IocU16Type)0; ix < OSIocMsgCfgLocalMax; ix++)
    {
        Os_InsertListAfter(&(OSIocMsgCBlocalPtr[ix].IocListNodeInfo), &OSIocMsgNodeLocalPtr);
    }
#endif
}

/******************************************************************************/
/*
 * Brief                <Init the IOC control block list>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <>
 * REQ ID               <>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_InitIoc(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    switch (Os_SCB.sysCore)
    {
    case 0:
#if (CFG_TASK_MAX_CORE0 > 0U)
#if ((CFG_IOC_MAX_CORE0 > 0U) || (CFG_IOC_MAX_GLOBAL > 0U))
#if (CFG_IOC_MAX_CORE0 > 0U)
        OSIocCBLocalPtr = Os_IocCBCore0;
        OSIocMsgCBlocalPtr = Os_IocMsgCBCore0;
        OSIocCfgLocalMax = CFG_IOC_MAX_CORE0;
        OSIocMsgCfgLocalMax = OS_IOCCOM_MSG_MAX_CORE0;
        OSIocBuffLocalPtr = &Os_IocCom_Core0_LMemPool_Ix[0];
        OSStdPipeCfgLocalPtr = &Os_IocPipe_Cfg_Core0[0];
#endif

#if (CFG_IOC_MAX_GLOBAL > 0U)
        OSIocCBGlobalPtr = Os_IocCBGlobal;
        OSIocMsgCBGlobalPtr = Os_IocMsgCBShare;
        OSIocBuffGlobalPtr = &Os_IocCom_Core_GMemPool_Ix[0];
        OSIocCfgGlobalMax = CFG_IOC_MAX_GLOBAL;
        OSIocMsgCfgGlobalMax = OS_IOCCOM_MSG_MAX_GLOBAL;
        OSStdPipeCfgGlobalPtr = &Os_IocPipe_Cfg_Global[0];
#endif
#endif
#endif
        break;

    case 1:
#if (CFG_TASK_MAX_CORE1 > 0U)
#if (CFG_IOC_MAX_CORE1 > 0U)
        OSIocCBLocalPtr = Os_IocCBCore1;
        OSIocMsgCBlocalPtr = Os_IocMsgCBCore1;
        OSIocCfgLocalMax = CFG_IOC_MAX_CORE1;
        OSIocMsgCfgLocalMax = OS_IOCCOM_MSG_MAX_CORE1;
        OSIocBuffLocalPtr = &Os_IocCom_Core1_LMemPool_Ix[0];
        OSStdPipeCfgLocalPtr = &Os_IocPipe_Cfg_Core1[0];
#endif
#endif
        break;

    case 2:
#if (CFG_TASK_MAX_CORE2 > 0U)
#if (CFG_IOC_MAX_CORE2 > 0U)
        OSIocCBLocalPtr = Os_IocCBCore2;
        OSIocMsgCBlocalPtr = Os_IocMsgCBCore2;
        OSIocCfgLocalMax = CFG_IOC_MAX_CORE2;
        OSIocMsgCfgLocalMax = OS_IOCCOM_MSG_MAX_CORE2;
        OSIocBuffLocalPtr = &Os_IocCom_Core2_LMemPool_Ix[0];
        OSStdPipeCfgLocalPtr = &Os_IocPipe_Cfg_Core2[0];
#endif
#endif
        break;

    case 3:
#if (CFG_TASK_MAX_CORE3 > 0U)
#if (CFG_IOC_MAX_CORE3 > 0U)
        OSIocCBLocalPtr = Os_IocCBCore3;
        OSIocMsgCBlocalPtr = Os_IocMsgCBCore3;
        OSIocCfgLocalMax = CFG_IOC_MAX_CORE3;
        OSIocMsgCfgLocalMax = OS_IOCCOM_MSG_MAX_CORE3;
        OSIocBuffLocalPtr = &Os_IocCom_Core3_LMemPool_Ix[0];
        OSStdPipeCfgLocalPtr = &Os_IocPipe_Cfg_Core3[0];
#endif
#endif
        break;

    case 4:
#if (CFG_TASK_MAX_CORE4 > 0U)
#if (CFG_IOC_MAX_CORE4 > 0U)
        OSIocCBLocalPtr = Os_IocCBCore4;
        OSIocMsgCBlocalPtr = Os_IocMsgCBCore4;
        OSIocCfgLocalMax = CFG_IOC_MAX_CORE4;
        OSIocMsgCfgLocalMax = OS_IOCCOM_MSG_MAX_CORE4;
        OSIocBuffLocalPtr = &Os_IocCom_Core4_LMemPool_Ix[0];
        OSStdPipeCfgLocalPtr = &Os_IocPipe_Cfg_Core4[0];
#endif
#endif
        break;

    case 5:
#if (CFG_TASK_MAX_CORE5 > 0U)
#if (CFG_IOC_MAX_CORE5 > 0U)
        OSIocCBLocalPtr = Os_IocCBCore5;
        OSIocMsgCBlocalPtr = Os_IocMsgCBCore5;
        OSIocCfgLocalMax = CFG_IOC_MAX_CORE5;
        OSIocMsgCfgLocalMax = OS_IOCCOM_MSG_MAX_CORE5;
        OSIocBuffLocalPtr = &Os_IocCom_Core5_LMemPool_Ix[0];
        OSStdPipeCfgLocalPtr = &Os_IocPipe_Cfg_Core5[0];
#endif
#endif
        break;
    default:
        while (1)
        {
            /* NOTE!! ++-->Nothing to do. */
        }
        break; /* PRQA S 2880 */ /* MISRA Rule 2.1 */
    }

    /* NOTE!! ++-->Init IOC control block. */
    Os_InitIocCB();
    /* NOTE!! ++-->Init IOC message control block.*/
    Os_InitIocMsgCB();
    /* NOTE!! ++-->Init IOC message control block list.*/
    Os_InitIocMsgList();
}

/******************************************************************************/
/*
 * Brief                <check memory pool.>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <>
 * REQ ID               <>
 */
/******************************************************************************/
static FUNC(StatusType, OS_CODE)
    Os_CheckMemPoolUsage(const Os_IocDataSourceType* pDataSrc, const Os_IocCBType* pICB, Os_IocRelPipeNumType absId)
{
    Os_IocU8Type ix;
    Os_IocDateType dataLength = (Os_IocDateType)0;
    Os_IocDateType preCalcLength;
    Os_IocCoreComType absComMark;
    Os_IocRelPipeNumType relId;
    Os_IocDateType memSize = 0;
    StatusType err;
    const Os_IocCBType* p_icb = pICB;

    if ((Os_IocU8Type)1 == p_icb->IocInParaNum)
    {
        preCalcLength = pDataSrc->IocDataLenth + p_icb->IocMemPoolUsage;
    }
    else
    {
        for (ix = (Os_IocU8Type)0; ix < p_icb->IocInParaNum; ix++)
        {
            dataLength = pDataSrc[ix].IocDataLenth + dataLength;
        }
        preCalcLength = dataLength + p_icb->IocMemPoolUsage;
    }

    absComMark = Os_IocCfgIdDesc[absId].IocCfgCoreComMark;
    relId = Os_IocCfgIdDesc[absId].Ioc_RelPipeIndex;

#if (CFG_IOC_MAX_GLOBAL > 0U)
    if (CROSS_CORE_COM == absComMark)
    {
        memSize = OSStdPipeCfgGlobalPtr[relId].IocPipeCfgPtr->IocMemPoolSize;
    }
#endif

#if (CFG_IOC_MAX_LOCAL > 0U)
    if (INTER_CORE_COM == absComMark)
    {
        memSize = OSStdPipeCfgLocalPtr[relId].IocPipeCfgPtr->IocMemPoolSize;
    }
#endif

    if (p_icb->IocMemPoolUsage > memSize)
    {
        /* NOTE!! ++-->The IOC pipe's memory pool is full. */
        err = IOC_E_LIMIT;
    }
    else if (preCalcLength > memSize)
    {
        /* NOTE!! ++-->The IOC service refuses an IOC request
         * to avoid internal buffer overflow. */
        err = IOC_E_LOST_DATA;
    }
    else
    {
        err = IOC_E_OK;
    }

    return err;
}

/******************************************************************************/
/*
 * Brief                <The API will insert node into the list.>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <>
 * REQ ID               <>
 */
/******************************************************************************/
static FUNC(void, OS_CODE) Os_InsertListBefore(Os_IocListNodeType* pNode, Os_IocCBType* pqObject)
{
    Os_IocListNodeType** ptr;
    Os_IocListNodeType* ptr1;

    ptr = &(pqObject->IocListHead.IocNextNode);
    if ((*ptr) != (Os_IocListNodeType*)0)
    {
        ptr1 = *ptr;
        *ptr = pNode;
        pNode->IocNextNode = ptr1;
    }
    else
    {
        *ptr = pNode;
        pqObject->IocPtrTailNode = pNode;
    }

    return;
}

/******************************************************************************/
/*
 * Brief                <The API will insert node into the list.>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <>
 * REQ ID               <>
 */
/******************************************************************************/
static FUNC(void, OS_CODE) Os_InsertListAfter(Os_IocListNodeType* pNode, Os_IocListNodeType** pqObject)
{
    Os_IocListNodeType** ptr;

    ptr = pqObject;
    (*ptr)->IocNextNode = pNode;
    /* NOTE!! ++-->Update the pointer. */
    *ptr = (*ptr)->IocNextNode;
}

/******************************************************************************/
/*
 * Brief                <Get a message control block from message control
 *                       block list.>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <>
 * REQ ID               <>
 */
/******************************************************************************/
static FUNC(Os_IocMsgCBType*, OS_CODE) Os_MallocMessage(Os_IocListNodeType** pqHead, Os_IocListNodeType** pqNode)
{
    Os_IocMsgCBType* pMsgCB;
    Os_IocListNodeType* ptr;
    Os_IocListNodeType* ptr1;
    Os_IocListNodeType* ptr2;

    ptr = *pqHead;
    ptr1 = ptr->IocNextNode;
    if (((Os_IocListNodeType*)0 != ptr1) && (ptr != ptr1->IocNextNode))
    {
        ptr2 = ptr1->IocNextNode;
        ptr->IocNextNode = ptr2;
        ptr1->IocNextNode = (Os_IocListNodeType*)0;

        if ((Os_IocListNodeType*)0 == ptr->IocNextNode)
        {
            *pqNode = *pqHead;
        }
        /* PRQA S 0488,0306,2810,3432++ */ /* MISRA Rule 18.4,11.4,1.3,20.7 */
        pMsgCB = OS_CONTAINER_OF(ptr1, Os_IocMsgCBType, IocListNodeInfo);
        /* PRQA S 0488,0306,2810,3432-- */ /* MISRA Rule 18.4,11.4,1.3,20.7 */
    }
    else
    {
        pMsgCB = (Os_IocMsgCBType*)0;
    }

    return pMsgCB;
}

/******************************************************************************/
/*
 * Brief                <Write data in lower level.>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <>
 * REQ ID               <>
 */
/******************************************************************************/
static FUNC(StatusType, OS_CODE) Os_LLWriteData(const Os_IocDataSourceType* pData, Os_IocCBType* pIocCB)
{
    StatusType Os_RetErr;
    Os_IocU8Type index;
    Os_IocMemPoolPtrType tempMemPoolPos;
    Os_IocMemPoolPtrType tempMemPoolPos1;
    Os_IocU8Type packNum;

    packNum = pIocCB->IocInParaNum;
    if ((Os_IocU8Type)1 == packNum)
    {
        /* NOTE!! ++-->Data will be copied to memory pool. */
        (void)Os_MemCopyWithoutOut(pIocCB->IocMemPoolPtr, pData->IocDataPtr, pData->IocDataLenth);

        /* NOTE!! ++-->In memory pool, using condition of memory pool shall be recorded. */
        pIocCB->IocMemPoolUsage = pData->IocDataLenth;
        /* NOTE!! ++-->Update the number of node. */
        pIocCB->IocPipelistCnt = (Os_IoclistCntType)1;
    }
    else
    {
        pIocCB->IocMemPoolUsage = (Os_IocDateType)0;
        tempMemPoolPos = pIocCB->IocMemPoolPtr;

        for (index = (Os_IocU8Type)0; index < packNum; index++)
        {
            /* NOTE!! ++-->Data will be copied to memory pool. */
            /* Record the initial location of the memory pool. */
            (void)Os_MemCopyWithOut(
                tempMemPoolPos,
                pData[index].IocDataPtr,
                pData[index].IocDataLenth,
                DIRECTION_INBUFF,
                &tempMemPoolPos1);
            tempMemPoolPos = tempMemPoolPos1;

            /* NOTE!! ++-->In memory pool, using condition of
             * memory pool shall be recorded. */
            pIocCB->IocMemPoolUsage += pData[index].IocDataLenth;
        }
        /* NOTE!! ++-->Update the number of node. */
        pIocCB->IocPipelistCnt = (Os_IoclistCntType)1;
    }

    Os_RetErr = IOC_E_OK;

    return Os_RetErr;
}

/******************************************************************************/
/*
 * Brief                <Sending data will be written into the mail.>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <>
 * REQ ID               <>
 */
/******************************************************************************/
static FUNC(void, OS_CODE)
    Os_SaveDataToMailForLIFO(Os_IocMsgCBType* pMailCB, const Os_IocDataSourceType* pData, Os_IocCBType* pIocCB)
{
    Os_IocU8Type packNum;
    Os_IocU8Type index;
    Os_IocDateType tempDateLenth = (Os_IocDateType)0;
    Os_IocMemPoolPtrType ptr;

    packNum = pIocCB->IocInParaNum;
    if ((Os_IocU8Type)1 == packNum)
    {
        pMailCB->IocDataLenth = pData->IocDataLenth;

        /* NOTE!! ++-->Data will be copied to memory pool. */
        (void)Os_MemCopyWithOut(pIocCB->IocMemPoolPtr, pData->IocDataPtr, pData->IocDataLenth, DIRECTION_INBUFF, &ptr);
        pIocCB->IocMemPoolPtr = ptr;

        /* NOTE!! ++-->In memory pool, using condition of memory pool shall be recorded. */
        pIocCB->IocMemPoolUsage += pData->IocDataLenth;
    }
    else
    {
        for (index = (Os_IocU8Type)0; index < packNum; index++)
        {
            tempDateLenth += pData[index].IocDataLenth;
            /* NOTE!! ++-->Data will be copied to memory pool. */
            (void)Os_MemCopyWithOut(
                pIocCB->IocMemPoolPtr,
                pData[index].IocDataPtr,
                pData[index].IocDataLenth,
                DIRECTION_INBUFF,
                &ptr);
            pIocCB->IocMemPoolPtr = ptr;

            /* NOTE!! ++-->In memory pool, using condition of memory pool shall be recorded. */
            pIocCB->IocMemPoolUsage += pData[index].IocDataLenth;
        }

        pMailCB->IocDataLenth = tempDateLenth;
    }

    pMailCB->IocMsgFormat = MSG_FORMAT_ONE;
    pMailCB->IocPtrMemPoolPosition = pIocCB->IocMemPoolPtr;

    return;
}

/******************************************************************************/
/*
 * Brief                <Sending data will be written into the mail.>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <>
 * REQ ID               <>
 */
/******************************************************************************/
static FUNC(void, OS_CODE)
    Os_SaveDataToMailForFIFO(Os_IocMsgCBType* pMailCB, const Os_IocDataSourceType* pData, Os_IocCBType* pIocCB)
{
    Os_IocU8Type packNum;
    Os_IocU8Type index;
    Os_IocDateType tempDateLenth = (Os_IocDateType)0;
    Os_IocDateType residEndMem;
    Os_IocMsgFormatType msgFormat;
    Os_IocMemPoolPtrType ptr;
    Os_IocDateType memBlock1;
    Os_IocDateType memBlock2;
    Os_IocDateType* pBuff;

    if (pIocCB->IocMemPoolPtr > pIocCB->IocMemPoolTailPtr)
    {
        while (1)
        {
            /* NOTE!! ++-->Nothing to do. */
        }
    }

    packNum = pIocCB->IocInParaNum;
    msgFormat = MSG_FORMAT_ONE;
    if ((Os_IocU8Type)1 == packNum)
    {
        /* PRQA S 1820,0488++ */ /* MISRA Rule 10.4,18.4 */
        residEndMem = pIocCB->IocMemPoolTailPtr - pIocCB->IocMemPoolPtr + 1u;
        /* PRQA S 1820,0488-- */ /* MISRA Rule 10.4,18.4 */
        pMailCB->IocDataLenth = pData->IocDataLenth;
        if (residEndMem >= pData->IocDataLenth)
        {
            /* NOTE!! ++-->Data will be copied to memory pool. */
            (void)Os_MemCopyWithOut(
                pIocCB->IocMemPoolPtr,
                pData->IocDataPtr,
                pData->IocDataLenth,
                DIRECTION_INBUFF,
                &ptr);
            pIocCB->IocMemPoolPtr = ptr;
        }
        else
        {
            memBlock1 = residEndMem;
            memBlock2 = pData->IocDataLenth - memBlock1;
            /* NOTE!! ++-->Data will be copied to memory pool. */
            (void)Os_MemCopyWithOut(pIocCB->IocMemPoolPtr, pData->IocDataPtr, memBlock1, DIRECTION_INBUFF, &ptr);
            pIocCB->IocMemPoolPtr = ptr;

            if (pIocCB->IocMemPoolPtr < pIocCB->IocMemPoolTailPtr)
            {
                while (1)
                {
                    /* NOTE!! ++-->Nothing to do. */
                }
            }

            /* PRQA S 0488++ */ /* MISRA Rule 18.4 */
            pBuff = (Os_IocDateType*)(((Os_IocU8Type*)(pData->IocDataPtr) + memBlock1));
            /* PRQA S 0488-- */ /* MISRA Rule 18.4 */
            /* NOTE!! ++-->Data will be copied to memory pool. */
            pIocCB->IocMemPoolPtr = pIocCB->IocMemPoolHeadPtr;
            (void)Os_MemCopyWithOut(pIocCB->IocMemPoolPtr, pBuff, memBlock2, DIRECTION_INBUFF, &ptr);
            pIocCB->IocMemPoolPtr = ptr;

            msgFormat = MSG_FORMAT_TWO;
        }

        if (pIocCB->IocMemPoolPtr > pIocCB->IocMemPoolTailPtr)
        {
            pIocCB->IocMemPoolPtr = pIocCB->IocMemPoolHeadPtr;
        }
        /* NOTE!! ++-->In memory pool, using condition of memory pool shall be recorded. */
        pIocCB->IocMemPoolUsage += pData->IocDataLenth;
    }
    else
    {
        for (index = (Os_IocU8Type)0; index < packNum; index++)
        {
            tempDateLenth += pData[index].IocDataLenth;
            /* PRQA S 1820,0488++ */ /* MISRA Rule 10.4,18.4 */
            residEndMem = pIocCB->IocMemPoolTailPtr - pIocCB->IocMemPoolPtr + 1u;
            /* PRQA S 1820,0488-- */ /* MISRA Rule 10.4,18.4 */

            if (residEndMem >= pData[index].IocDataLenth)
            {
                /* NOTE!! ++-->Data will be copied to memory pool. */
                (void)Os_MemCopyWithOut(
                    pIocCB->IocMemPoolPtr,
                    pData[index].IocDataPtr,
                    pData[index].IocDataLenth,
                    DIRECTION_INBUFF,
                    &ptr);
                pIocCB->IocMemPoolPtr = ptr;

                if (pIocCB->IocMemPoolPtr > pIocCB->IocMemPoolTailPtr)
                {
                    pIocCB->IocMemPoolPtr = pIocCB->IocMemPoolHeadPtr;
                    if (index <= (packNum - 2u))
                    {
                        msgFormat = MSG_FORMAT_TWO;
                    }
                }
            }
            else
            {
                memBlock1 = residEndMem;
                memBlock2 = pData[index].IocDataLenth - memBlock1;

                /* NOTE!! ++-->Data will be copied to memory pool. */
                (void)Os_MemCopyWithOut(
                    pIocCB->IocMemPoolPtr,
                    pData[index].IocDataPtr,
                    memBlock1,
                    DIRECTION_INBUFF,
                    &ptr);
                pIocCB->IocMemPoolPtr = ptr;

                if (pIocCB->IocMemPoolPtr < pIocCB->IocMemPoolTailPtr)
                {
                    while (1)
                    {
                        /* NOTE!! ++-->nothing to do. */
                    }
                }

                /* PRQA S 0488++ */ /* MISRA Rule 18.4 */
                pBuff = (Os_IocDateType*)((Os_IocU8Type*)(pData[index].IocDataPtr) + memBlock1);
                /* PRQA S 0488-- */ /* MISRA Rule 18.4 */
                /* NOTE!! ++-->Data will be copied to memory pool. */
                pIocCB->IocMemPoolPtr = pIocCB->IocMemPoolHeadPtr;
                (void)Os_MemCopyWithOut(pIocCB->IocMemPoolPtr, pBuff, memBlock2, DIRECTION_INBUFF, &ptr);
                pIocCB->IocMemPoolPtr = ptr;

                msgFormat = MSG_FORMAT_TWO;
                if (pIocCB->IocMemPoolPtr > pIocCB->IocMemPoolTailPtr)
                {
                    pIocCB->IocMemPoolPtr = pIocCB->IocMemPoolHeadPtr;
                }
            }
            /* NOTE!! ++-->In memory pool, using condition of memory pool shall be recorded. */
            pIocCB->IocMemPoolUsage += pData[index].IocDataLenth;
        }
        pMailCB->IocDataLenth = tempDateLenth;
    }

    pMailCB->IocMsgFormat = msgFormat;

    if (pIocCB->IocMemPoolPtr == pIocCB->IocMemPoolHeadPtr)
    {
        pMailCB->IocPtrMemPoolPosition = pIocCB->IocMemPoolTailPtr + 1u;
    }
    else
    {
        pMailCB->IocPtrMemPoolPosition = pIocCB->IocMemPoolPtr;
    }

    return;
}

/******************************************************************************/
/*
 * Brief                <Send data in lower level.>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <>
 * REQ ID               <>
 */
/******************************************************************************/
static FUNC(StatusType, OS_CODE) Os_LLSendData(const Os_IocDataSourceType* pData, Os_IocCBType* pIocCB)
{
    Os_IocMsgCBType* workMail = NULL_PTR;
    Os_IocCoreComType comMark;
    StatusType Os_RetErr;

    if ((Os_IocCBType*)0 != pIocCB)
    {
        comMark = pIocCB->IocCoreComMark;
/* NOTE!! ++-->Malloc a message control block and the message control
 * will be loaded in mail. */
#if (CFG_IOC_MAX_LOCAL > 0U)
        if (INTER_CORE_COM == comMark)
        {
            workMail = Os_MallocMessage(&OSIocMsgHeadLocalPtr, &OSIocMsgNodeLocalPtr);
        }
#endif

#if (CFG_IOC_MAX_GLOBAL > 0U)
        if (CROSS_CORE_COM == comMark)
        {
            Os_GetSpinlock(&Os_IocMailLock);
            workMail = Os_MallocMessage(&OSIocMsgHeadGlobalPtr, &OSIocMsgNodeGlobalPtr);
            Os_ReleaseSpinlock(&Os_IocMailLock);
        }
#endif

        if (workMail != (Os_IocMsgCBType*)0)
        {
            if (QUEUED_FIFO == pIocCB->IocQueueCom)
            {
                /* NOTE!! ++-->Data should be written into the mailbox. */
                (void)Os_SaveDataToMailForFIFO(workMail, pData, pIocCB);
                /* NOTE!! ++-->insert into pipe list. */
                (void)Os_InsertListAfter(&(workMail->IocListNodeInfo), &(pIocCB->IocPtrTailNode));
            }
            else
            {
                /* NOTE!! ++-->Data should be written into the mailbox. */
                (void)Os_SaveDataToMailForLIFO(workMail, pData, pIocCB);
                /* NOTE!! ++-->insert into pipe list. */
                (void)Os_InsertListBefore(&(workMail->IocListNodeInfo), pIocCB);
            }

            /* NOTE!! ++-->Update the number of node in the pipe list. */
            pIocCB->IocPipelistCnt++;
            Os_RetErr = IOC_E_OK;
        }
        else
        {
            Os_RetErr = IOC_E_NOK;
        }
    }
    else
    {
        Os_RetErr = IOC_E_NOK;
    }

    return Os_RetErr;
}

/******************************************************************************/
/*
 * Brief                <The API will copy data from source to destination.>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <>
 * REQ ID               <>
 */
/******************************************************************************/
static FUNC(void, OS_CODE) Os_MemCopyWithoutOut(void* dest, void* src, Os_IocU32Type size)
{
    Os_IocU8Type* pDest;
    Os_IocU8Type* pSrc;
    Os_IocU32Type num;

    pDest = (Os_IocU8Type*)dest;
    pSrc = (Os_IocU8Type*)src;
    num = size;

    if ((NULL_PTR != pDest) && (NULL_PTR != pSrc))
    {
        while (num > (Os_IocU32Type)0)
        {
            /* PRQA S 3440++ */ /* MISRA Rule 13.3 */
            *(pDest++) = *(pSrc++);
            num--;
            /* PRQA S 3440-- */ /* MISRA Rule 13.3 */
        }
    }
    else
    {
        while (1)
        {
            /* NOTE!! ++-->enter endless loop */
        }
    }
}

/******************************************************************************/
/*
 * Brief                <The API will copy data from source to destination.>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <>
 * REQ ID               <>
 */
/******************************************************************************/
static FUNC(void, OS_CODE) Os_MemCopyWithOut(
    void* dest,
    void* src,
    Os_IocU32Type size,
    Os_BuffDataDirectionType directOfData,
    Os_IocU8Type** pOut)
{
    Os_IocU8Type* pDest;
    Os_IocU8Type* pSrc;
    Os_IocU32Type num;

    pDest = (Os_IocU8Type*)dest;
    pSrc = (Os_IocU8Type*)src;
    num = size;

    if ((NULL_PTR != pDest) && (NULL_PTR != pSrc))
    {
        while (num > (Os_IocU32Type)0)
        {
            /* PRQA S 3440++ */ /* MISRA Rule 13.3 */
            *(pDest++) = *(pSrc++);
            num--;
            /* PRQA S 3440-- */ /* MISRA Rule 13.3 */
        }
    }
    else
    {
        while (1)
        {
            /* NOTE!! ++-->enter endless loop. */
        }
    }

    if (DIRECTION_INBUFF == directOfData)
    {
        (*pOut) = pDest;
    }
    else
    {
        (*pOut) = pSrc;
    }
}

#if (CFG_IOC_MAX_GLOBAL > 0U)
/******************************************************************************/
/*
 * Brief                <In middle level, the API will transmit cross-core data.>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <>
 * REQ ID               <>
 */
/******************************************************************************/
static FUNC(StatusType, OS_CODE) Os_IocCrossTransmit(Os_IocAbsIdType absId, const Os_IocDataSourceType* transData)
{
    StatusType Os_RetErr;
    Os_IocCBType* pIocCB;
    Os_IocSemanticsType tempSema;
    Os_IocRelPipeNumType relPipeNum;

    OS_ARCH_DECLARE_CRITICAL();

    relPipeNum = Os_IocCfgIdDesc[absId].Ioc_RelPipeIndex;
    pIocCB = &OSIocCBGlobalPtr[relPipeNum];
    tempSema = pIocCB->IocSemantics;

    /* NOTE!! ++-->Enter critical section. */
    Os_GetSpinlock(&Os_IocSpinlock[relPipeNum]);
    OS_ARCH_ENTRY_CRITICAL();

    Os_RetErr = Os_CheckMemPoolUsage(transData, pIocCB, absId);
    if (IOC_E_OK == Os_RetErr)
    {
        if (CAT1_UNQUEUED == tempSema)
        {
            Os_RetErr = Os_LLWriteData(transData, pIocCB);
        }
        else
        {
            Os_RetErr = Os_LLSendData(transData, pIocCB);
        }
    }

    /* NOTE!! ++-->Exit critical section. */
    OS_ARCH_EXIT_CRITICAL();
    Os_ReleaseSpinlock(&Os_IocSpinlock[relPipeNum]);

    return Os_RetErr;
}
#endif

#if (CFG_IOC_MAX_LOCAL > 0U)
/******************************************************************************/
/*
 * Brief                <In middle level, the API will transmit inter-core data.>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <>
 * REQ ID               <>
 */
/******************************************************************************/
static FUNC(StatusType, OS_CODE) Os_IocInterTransmit(Os_IocAbsIdType absId, const Os_IocDataSourceType* transData)
{
    StatusType Os_RetErr;
    Os_IocCBType* pIocCB;
    Os_IocRelPipeNumType relPipeNum;
    Os_IocSemanticsType tempSema;

    OS_ARCH_DECLARE_CRITICAL();

    relPipeNum = Os_IocCfgIdDesc[absId].Ioc_RelPipeIndex;
    pIocCB = &OSIocCBLocalPtr[relPipeNum];
    tempSema = pIocCB->IocSemantics;
    /* NOTE!! ++-->Enter critical section. */
    OS_ARCH_ENTRY_CRITICAL();

    Os_RetErr = Os_CheckMemPoolUsage(transData, pIocCB, absId);
    if (IOC_E_OK == Os_RetErr)
    {
        /* NOTE!! ++-->Call the low-level function to transmit data. */
        if (CAT1_UNQUEUED == tempSema)
        {
            Os_RetErr = Os_LLWriteData(transData, pIocCB);
        }
        else
        {
            Os_RetErr = Os_LLSendData(transData, pIocCB);
        }
    }

    /* NOTE!! ++-->Exit critical section. */
    OS_ARCH_EXIT_CRITICAL();

    return Os_RetErr;
}
#endif

#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
/******************************************************************************/
/*
 * Brief                <The API will check that whether the byte number of
 *                       the API's input parameter is the same as the ORIENTAIS
 *                       Studio configuration.>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <>
 * REQ ID               <>
 */
/******************************************************************************/
static FUNC(StatusType, OS_CODE)
    Os_CheckSafeContext(Os_IocAbsIdType ix, Os_IocTransferType transfer, StatusType* outRet)
{
    Os_IocCoreComType tempComMark;
    Os_IocRelPipeNumType relPipeNum;
    const Os_IocMaskType* pMask;
    const Os_IocPipeCfgType* pStdPipeCfg;
    StatusType Os_RetErr;

    tempComMark = Os_IocCfgIdDesc[ix].IocCfgCoreComMark;
    relPipeNum = Os_IocCfgIdDesc[ix].Ioc_RelPipeIndex;

#if (CFG_IOC_MAX_GLOBAL > 0U)
    if (CROSS_CORE_COM == tempComMark)
    {
        pStdPipeCfg = OSStdPipeCfgGlobalPtr;
    }
#endif
#if (CFG_IOC_MAX_LOCAL > 0U)
    if (INTER_CORE_COM == tempComMark)
    {
        pStdPipeCfg = OSStdPipeCfgLocalPtr;
    }
#endif
    if (IOC_SND_SIDE == transfer)
    {
        /* PRQA S 2962++ */ /* MISRA Rule 9.1 */
        pMask = pStdPipeCfg[relPipeNum].IocPipeCfgPtr->IocSndMask;
        /* PRQA S 2962-- */ /* MISRA Rule 9.1 */
    }
    else if (IOC_RCV_SIDE == transfer)
    {
        pMask = pStdPipeCfg[relPipeNum].IocPipeCfgPtr->IocRcvMask;
    }
    else
    {
        while (1)
        {
            /* NOTE!! ++-->Enter endless loop. */
        }
    }
    /* PRQA S 0404++ */ /* MISRA Rule 1.3,13.2 */
    if ((((Os_IocU16Type)1 << (Os_SCB.sysRunningAppID & (Os_IocU16Type)0x0F))
         & (pMask[Os_SCB.sysRunningAppID >> (Os_IocU16Type)4]))
        == (Os_IocU16Type)0)
    /* PRQA S 0404-- */ /* MISRA Rule 1.3,13.2 */
    {
        Os_RetErr = IOC_E_NOK;
    }
    else if (Os_AppCB[Os_SCB.sysRunningAppID].appState != APPLICATION_ACCESSIBLE)
    {
        Os_RetErr = E_OS_ACCESS;
    }
    else
    {
        Os_RetErr = IOC_E_OK;
    }

    *outRet = Os_RetErr;

    return Os_RetErr;
}
#endif

#if (TRUE == OS_IOC_CHECKINPARA)
/******************************************************************************/
/*
 * Brief                <The API will check that whether the byte number of
 *                       the API's input parameter is the same as the ORIENTAIS
 *                       Studio configuration.>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <>
 * REQ ID               <>
 */
/******************************************************************************/
static FUNC(StatusType, OS_CODE) Os_IocCheckInPara(Os_IocAbsIdType absId, const Os_IocDataSourceType* pData)
{
    StatusType Os_RetErr;
    StatusType tempErr = IOC_E_NOK;
    Os_IocU8Type index;
    Os_IocDateType byteNum;
    Os_IocCoreComType tempComMark;
    Os_IocU8Type packNum = 0;
    Os_IocRelPipeNumType relPipeNum;
    const Os_IocPipeCfgType* pStdPipe;

    /* NOTE!! ++-->Get flag of communication. */
    tempComMark = Os_IocCfgIdDesc[absId].IocCfgCoreComMark;
    /* NOTE!! ++-->Get the relative pipe number. */
    relPipeNum = Os_IocCfgIdDesc[absId].Ioc_RelPipeIndex;

#if (CFG_IOC_MAX_GLOBAL > 0U)
    if (CROSS_CORE_COM == tempComMark)
    {
        pStdPipe = &OSStdPipeCfgGlobalPtr[relPipeNum];
        packNum = OSStdPipeCfgGlobalPtr[relPipeNum].IocPipeCfgPtr->IocCfgInParaNum;
    }
#endif

#if (CFG_IOC_MAX_LOCAL > 0U)
    if (INTER_CORE_COM == tempComMark)
    {
        pStdPipe = &OSStdPipeCfgLocalPtr[relPipeNum];
        packNum = OSStdPipeCfgLocalPtr[relPipeNum].IocPipeCfgPtr->IocCfgInParaNum;
    }
#endif

    for (index = (Os_IocU8Type)0; index < packNum; index++)
    {
        /* PRQA S 2962++ */ /* MISRA Rule 9.1 */
        byteNum = pStdPipe->IocPipeCfgPtr->IocDataPrpeRef[index].IocDataLength;
        /* PRQA S 2962-- */ /* MISRA Rule 9.1 */
        if (pData[index].IocDataLenth != byteNum)
        {
            tempErr = IOC_E_OK;
            break;
        }
    }

    if (IOC_E_OK == tempErr)
    {
        Os_RetErr = IOC_E_NOK;
    }
    else
    {
        Os_RetErr = IOC_E_OK;
    }

    return Os_RetErr;
}
#endif

/******************************************************************************/
/*
 * Brief                <The API shall check the usage of the pipe memory pool.>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <>
 * REQ ID               <>
 */
/******************************************************************************/
static FUNC(StatusType, OS_CODE)
    Os_IocCheckPipeMemPoolUsage(Os_IocAbsIdType absId, const Os_IocDataSourceType* pDataSource, StatusType* outRet)
{
    StatusType Os_RetErr;
    const Os_IocCBType* pIocCB;
    Os_IocCoreComType tempComMark;
    Os_IocRelPipeNumType relPipeNum;

    /* NOTE!! ++-->Get the relative pipe number. */
    relPipeNum = Os_IocCfgIdDesc[absId].Ioc_RelPipeIndex;
    /* NOTE!! ++-->Get flag of communication. */
    tempComMark = Os_IocCfgIdDesc[absId].IocCfgCoreComMark;

#if (CFG_IOC_MAX_LOCAL > 0U)
    if (INTER_CORE_COM == tempComMark)
    {
        pIocCB = &OSIocCBLocalPtr[relPipeNum];
    }
#endif

#if (CFG_IOC_MAX_GLOBAL > 0U)
    if (CROSS_CORE_COM == tempComMark)
    {
        pIocCB = &OSIocCBGlobalPtr[relPipeNum];
    }
#endif

    /* PRQA S 2962++ */ /* MISRA Rule 9.1 */
    Os_RetErr = Os_CheckMemPoolUsage(pDataSource, pIocCB, absId);
    /* PRQA S 2962-- */ /* MISRA Rule 9.1 */

    *outRet = Os_RetErr;

    return Os_RetErr;
}

/******************************************************************************/
/*
 * Brief                <In high level, the API will transmit data.
 *                       According to core communication property, the API will
 *                       select middle-level function to transmit data.>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <>
 * REQ ID               <>
 */
/******************************************************************************/
/* PRQA S 1532++ */ /* MISRA Rule 8.7 */
FUNC(StatusType, OS_CODE) Os_IocHLTransmit(Os_IocAbsIdType absId, const Os_IocDataSourceType* pData)
/* PRQA S 1532-- */ /* MISRA Rule 8.7 */
{
    StatusType Os_RetErr;
    Os_IocCoreComType tempComMark;
    Os_IocRelPipeNumType relPipeNum;
    Os_IocExeNotifyType pFunPipeExeNotify;
#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
    Os_IocPipeOsPosType tempOsPos;
#endif
    StatusType stdOut;

    OS_IOCHLTRANSMIT_DEFINE();
    OS_IOCHLTRANSMIT_ENTRY();
#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif

    tempComMark = Os_IocCfgIdDesc[absId].IocCfgCoreComMark;
    relPipeNum = Os_IocCfgIdDesc[absId].Ioc_RelPipeIndex;

#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
#if (CFG_IOC_MAX_GLOBAL > 0U)
    if (CROSS_CORE_COM == tempComMark)
    {
        tempOsPos = OSStdPipeCfgGlobalPtr[relPipeNum].IocPipeCfgPtr->IocPipeOsPos;
    }
#endif
#if (CFG_IOC_MAX_LOCAL > 0U)
    if (INTER_CORE_COM == tempComMark)
    {
        tempOsPos = OSStdPipeCfgLocalPtr[relPipeNum].IocPipeCfgPtr->IocPipeOsPos;
    }
#endif
#endif

    if (IOC_E_OK != Os_IocCheckPipeMemPoolUsage(absId, pData, &stdOut))
    {
        Os_RetErr = stdOut;
    }
#if (TRUE == OS_IOC_CHECKINPARA)
    else if (IOC_E_OK != Os_IocCheckInPara(absId, pData))
    {
        Os_RetErr = IOC_E_NOK;
    }
#endif
#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
    /* PRQA S 2962++ */ /* MISRA Rule 9.1 */
    else if (tempOsPos != IOC_SND_SIDE_NOS)
    /* PRQA S 2962-- */ /* MISRA Rule 9.1 */
    {
        if (IOC_E_OK != Os_CheckSafeContext(absId, IOC_SND_SIDE, &stdOut))
        {
            Os_RetErr = stdOut;
        }
        else
        {
            Os_RetErr = IOC_E_OK;
        }
    }
#endif
    else
    {
        Os_RetErr = IOC_E_OK;
    }

    if (IOC_E_OK == Os_RetErr)
    {
#if (CFG_IOC_MAX_LOCAL > 0U)
        if (INTER_CORE_COM == tempComMark)
        {
            if (relPipeNum > OSIocCfgLocalMax)
            {
                Os_RetErr = IOC_E_NOK;
            }
            else
            {
                Os_RetErr = Os_IocInterTransmit(absId, pData);
            }
        }
#endif

#if (CFG_IOC_MAX_GLOBAL > 0U)
        if (CROSS_CORE_COM == tempComMark)
        {
            if (relPipeNum > OSIocCfgGlobalMax)
            {
                Os_RetErr = IOC_E_NOK;
            }
            else
            {
                Os_RetErr = Os_IocCrossTransmit(absId, pData);
            }
        }
#endif
    }

    if (IOC_E_OK == Os_RetErr)
    {
#if (CFG_IOC_MAX_GLOBAL > 0U)
        if (CROSS_CORE_COM == tempComMark)
        {
            pFunPipeExeNotify = OSStdPipeCfgGlobalPtr[relPipeNum].IocPipeCfgPtr->IocExeNotify;
        }
#endif
#if (CFG_IOC_MAX_LOCAL > 0U)
        if (INTER_CORE_COM == tempComMark)
        {
            pFunPipeExeNotify = OSStdPipeCfgLocalPtr[relPipeNum].IocPipeCfgPtr->IocExeNotify;
        }
#endif

        /* PRQA S 2962++ */ /* MISRA Rule 9.1 */
        if (pFunPipeExeNotify != (Os_IocExeNotifyType)0)
        /* PRQA S 2962-- */ /* MISRA Rule 9.1 */
        {
            (void)pFunPipeExeNotify();
        }
    }

    OS_IOCHLTRANSMIT_EXIT();

    return Os_RetErr;
}

/******************************************************************************/
/*
 * Brief                <get the first node of mail control block>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <>
 * REQ ID               <>
 */
/******************************************************************************/
static FUNC(Os_IocMsgCBType*, OS_CODE) Os_MallocMail(Os_IocListNodeType* pNode, Os_IocListNodeType** pTail)
{
    Os_IocMsgCBType* pMailEntry;
    Os_IocListNodeType* ptr1;
    Os_IocListNodeType* ptr2;

    ptr1 = pNode->IocNextNode;

    if (ptr1 != (Os_IocListNodeType*)0)
    {
        /* NOTE!! ++-->The pipe list isn't null. */
        ptr2 = ptr1->IocNextNode;
        pNode->IocNextNode = ptr2;

        ptr1->IocNextNode = (Os_IocListNodeType*)0;

        if ((Os_IocListNodeType*)0 == ptr2)
        {
            *pTail = pNode;
        }

        /* NOTE!! ++-->Get the node's entry. */
        /* PRQA S 0488,0306,2810,3432++ */ /* MISRA Rule 18.4,11.4,1.3,20.7 */
        pMailEntry = OS_CONTAINER_OF(ptr1, Os_IocMsgCBType, IocListNodeInfo);
        /* PRQA S 0488,0306,2810,3432-- */ /* MISRA Rule 18.4,11.4,1.3,20.7 */
    }
    else
    {
        /* NOTE!! ++-->The pipe list is null. */
        pMailEntry = (Os_IocMsgCBType*)0;
    }

    return pMailEntry;
}

/******************************************************************************/
/*
 * Brief                <Release multiple mail block.>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <>
 * REQ ID               <>
 */
/******************************************************************************/
static FUNC(void, OS_CODE) Os_ReleaseMultiMail(
    Os_IocListNodeType* pMailNodePrev,
    Os_IocListNodeType* pMailNodeNext,
    Os_IocListNodeType* const* pqHead)
{
    Os_IocListNodeType* ptr;
    Os_IocListNodeType* ptr1;

    ptr = *pqHead;
    ptr1 = ptr->IocNextNode;

    if ((pMailNodePrev != (Os_IocListNodeType*)0) && (pMailNodeNext != (Os_IocListNodeType*)0))
    {
        ptr->IocNextNode = pMailNodePrev;
        pMailNodeNext->IocNextNode = ptr1;
    }
    else
    {
        while (1)
        {
            /* NOTE!! ++-->Enter endless loop. */
        }
    }

    return;
}

/******************************************************************************/
/*
 * Brief                <Release mail block.>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <>
 * REQ ID               <>
 */
/******************************************************************************/
static FUNC(void, OS_CODE) Os_ReleaseMail(Os_IocMsgCBType* pMailCB, Os_IocListNodeType* const* pqHead)
{
    Os_IocMsgCBType* ptr1;
    Os_IocListNodeType* ptr2;
    Os_IocListNodeType* ptr;

    ptr = *pqHead;
    if ((Os_IocMsgCBType*)0 != pMailCB)
    {
        /* NOTE!! ++-->The mail control block will be inserted in message list. */
        ptr1 = pMailCB;
        ptr2 = ptr->IocNextNode;
        ptr->IocNextNode = &ptr1->IocListNodeInfo;
        ptr1->IocListNodeInfo.IocNextNode = ptr2;
    }
    else
    {
        while (1)
        {
            /* NOTE!! ++-->enter endless loop */
        }
    }
}

/******************************************************************************/
/*
 * Brief                <Read data in lower level.>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_InitSystem>
 * REQ ID               <>
 */
/******************************************************************************/
static FUNC(StatusType, OS_CODE) Os_LLReadData(const Os_IocDataSourceType* pData, const Os_IocCBType* pIocCB)
{
    StatusType Os_RetErr;
    Os_IocU8Type index;
    Os_IocMemPoolPtrType tempMemPoolPos;
    Os_IocMemPoolPtrType tempMemPoolPos1;
    Os_IocU8Type packNum;

    if (pIocCB != (Os_IocCBType*)0)
    {
        packNum = pIocCB->IocInParaNum;
        if ((Os_IocU8Type)1 == packNum)
        {
            /* NOTE!! ++-->The reception will get the data from memory pool.*/
            Os_MemCopyWithoutOut(pData->IocDataPtr, pIocCB->IocMemPoolPtr, pIocCB->IocMemPoolUsage);
        }
        else
        {
            /* NOTE!! ++-->Record the initial location of the memory pool. */
            tempMemPoolPos = pIocCB->IocMemPoolPtr;

            for (index = (Os_IocU8Type)0; index < packNum; index++)
            {
                /* NOTE!! ++-->The reception will get the data from memory pool.*/
                (void)Os_MemCopyWithOut(
                    pData[index].IocDataPtr,
                    tempMemPoolPos,
                    pData[index].IocDataLenth,
                    DIRECTION_OUTBUFF,
                    &tempMemPoolPos1);
                tempMemPoolPos = tempMemPoolPos1;
            }
        }

        Os_RetErr = IOC_E_OK;
    }
    else
    {
        Os_RetErr = IOC_E_NOK;
    }

    return Os_RetErr;
}

/******************************************************************************/
/*
 * Brief                <The purpose of the API is obtaining data from memory pool.>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_InitSystem>
 * REQ ID               <>
 */
/******************************************************************************/
static FUNC(void, OS_CODE) Os_GetDataFromMemPoolForLIFO(
    const Os_IocDataSourceType* pData,
    Os_IocCBType* const pIocCB,
    Os_IocMsgCBType* pMailCB)
{
    Os_IocMemPoolType* ptr;
    Os_IocMemPoolType* tempMemPoolPos;
    Os_IocMemPoolType* tempMemPoolPos1;
    Os_IocU8Type index;
    Os_IocU8Type packNum;

    packNum = pIocCB->IocInParaNum;
    ptr = pMailCB->IocPtrMemPoolPosition - pMailCB->IocDataLenth; /* PRQA S 0488 */ /* MISRA Rule 18.4 */
    tempMemPoolPos = ptr;

    if ((Os_IocU8Type)1 == packNum)
    {
        /* NOTE!! ++-->The reception will get the data from memory pool.*/
        Os_MemCopyWithoutOut(pData->IocDataPtr, ptr, pMailCB->IocDataLenth);
    }
    else
    {
        for (index = (Os_IocU8Type)0; index < packNum; index++)
        {
            /* NOTE!! ++-->The reception will get the data from memory pool.*/
            Os_MemCopyWithOut(
                pData[index].IocDataPtr,
                tempMemPoolPos,
                pData[index].IocDataLenth,
                DIRECTION_OUTBUFF,
                &tempMemPoolPos1);
            tempMemPoolPos = tempMemPoolPos1;
        }
    }

    pMailCB->IocPtrMemPoolPosition = (Os_IocMemPoolPtrType)0;
    pIocCB->IocMemPoolPtr = ptr;
}

/******************************************************************************/
/*
 * Brief                <The purpose of the API is obtaining data from memory pool.>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_InitSystem>
 * REQ ID               <>
 */
/******************************************************************************/
static FUNC(void, OS_CODE) Os_GetDataFromMemPoolForFIFO(
    const Os_IocDataSourceType* pData,
    const Os_IocCBType* pIocCB,
    Os_IocMsgCBType* pMailCB)
{
    Os_IocMemPoolType* ptr;
    Os_IocMemPoolType* ptr1;
    Os_IocMemPoolType* ptr2;
    Os_IocU8Type index;
    Os_IocU8Type packNum;
    Os_IocDateType memBlock1;
    Os_IocDateType memBlock2;
    Os_IocDateType memSize;

    packNum = pIocCB->IocInParaNum;
    if ((Os_IocU8Type)1 == packNum)
    {
        if (MSG_FORMAT_ONE == pMailCB->IocMsgFormat)
        {
            ptr = pMailCB->IocPtrMemPoolPosition - pMailCB->IocDataLenth; /* PRQA S 0488 */ /* MISRA Rule 18.4 */
            /* NOTE!! ++-->The reception will get the data from memory pool.*/
            Os_MemCopyWithoutOut(pData->IocDataPtr, ptr, pMailCB->IocDataLenth);
        }
        else
        {
            /* PRQA S 4434,0488++ */ /* MISRA Rule 10.3,18.4 */
            memBlock2 = pMailCB->IocPtrMemPoolPosition - pIocCB->IocMemPoolHeadPtr;
            /* PRQA S 4434,0488-- */ /* MISRA Rule 10.3,18.4 */
            memBlock1 = pMailCB->IocDataLenth - memBlock2;

            /* NOTE!! ++-->1. block 1 copy.*/
            ptr = pIocCB->IocMemPoolTailPtr - memBlock1 + 1u; /* PRQA S 0488 */ /* MISRA Rule 18.4 */
            ptr1 = pData->IocDataPtr;
            Os_MemCopyWithoutOut(ptr1, ptr, memBlock1);

            /* NOTE!! ++-->2. block 2 copy.*/
            ptr = pIocCB->IocMemPoolHeadPtr;
            ptr1 = (Os_IocU8Type*)(pData->IocDataPtr) + memBlock1; /* PRQA S 0488 */ /* MISRA Rule 18.4 */
            Os_MemCopyWithoutOut(ptr1, ptr, memBlock2);
        }
    }
    else
    {
        if (MSG_FORMAT_ONE == pMailCB->IocMsgFormat)
        {
            ptr = pMailCB->IocPtrMemPoolPosition - pMailCB->IocDataLenth; /* PRQA S 0488 */ /* MISRA Rule 18.4 */
            for (index = (Os_IocU8Type)0; index < packNum; index++)
            {
                ptr1 = pData[index].IocDataPtr;
                /* NOTE!! ++-->The reception will get the data from memory pool.*/
                Os_MemCopyWithOut(ptr1, ptr, pData[index].IocDataLenth, DIRECTION_OUTBUFF, &ptr2);
                ptr = ptr2;
                if (ptr > pIocCB->IocMemPoolTailPtr)
                {
                    ptr = pIocCB->IocMemPoolHeadPtr;
                }
            }
        }
        else
        {
            /* PRQA S 4434,0488++ */ /* MISRA Rule 10.3,18.4 */
            memBlock2 = pMailCB->IocPtrMemPoolPosition - pIocCB->IocMemPoolHeadPtr;
            /* PRQA S 4434,0488-- */ /* MISRA Rule 10.3,18.4 */
            memBlock1 = pMailCB->IocDataLenth - memBlock2;
            memSize = memBlock1;
            ptr = pIocCB->IocMemPoolTailPtr - memBlock1 + 1u; /* PRQA S 0488 */ /* MISRA Rule 18.4 */
            for (index = (Os_IocU8Type)0; index < packNum; index++)
            {
                ptr1 = pData[index].IocDataPtr;
                if (memSize >= pData[index].IocDataLenth)
                {
                    /* NOTE!! ++-->1. block 1 copy. */
                    Os_MemCopyWithOut(ptr1, ptr, pData[index].IocDataLenth, DIRECTION_OUTBUFF, &ptr2);
                    ptr = ptr2;
                    memSize -= pData[index].IocDataLenth;
                }
                else if ((memSize > 0u) && (memSize < pData[index].IocDataLenth))
                {
                    /* NOTE!! ++-->block1 & block2 copy. */
                    /* NOTE!! ++-->block 1 copy. */
                    Os_MemCopyWithOut(ptr1, ptr, memSize, DIRECTION_OUTBUFF, &ptr2);
                    ptr = ptr2;
                    if (ptr < pIocCB->IocMemPoolTailPtr)
                    {
                        while (1)
                        {
                            /* NOTE!! ++-->nothing to do. */
                        }
                    }

                    /* NOTE!! ++-->block 2 copy. */
                    ptr1 = (Os_IocU8Type*)(pData[index].IocDataPtr) + memSize; /* PRQA S 0488 */ /* MISRA Rule 18.4 */
                    memSize = pData[index].IocDataLenth - memSize;
                    ptr = pIocCB->IocMemPoolHeadPtr;
                    (void)Os_MemCopyWithOut(ptr1, ptr, memSize, DIRECTION_OUTBUFF, &ptr2);
                    ptr = ptr2;
                    memSize = memBlock2 - memSize;
                }
                else
                {
                    while (1)
                    {
                        /* NOTE!! ++-->nothing to do. */
                    }
                }
                if (ptr > pIocCB->IocMemPoolTailPtr)
                {
                    ptr = pIocCB->IocMemPoolHeadPtr;
                    memSize = memBlock2;
                }
            }
        }
    }

    pMailCB->IocPtrMemPoolPosition = (Os_IocMemPoolPtrType)0;
}

/******************************************************************************/
/*
 * Brief                <Receive data in lower level.>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_InitSystem>
 * REQ ID               <>
 */
/******************************************************************************/
static FUNC(StatusType, OS_CODE) Os_LLReceiveData(const Os_IocDataSourceType* pData, Os_IocCBType* pIocCB)
{
    Os_IocMsgCBType* pWorkMailCB = NULL_PTR;
    StatusType Os_RetErr;
    Os_IocCoreComType tempComMark;

    if (pIocCB != (Os_IocCBType*)0)
    {
        tempComMark = pIocCB->IocCoreComMark;
/* NOTE!! ++-->Get the mail control block from the pipe list. */
#if (CFG_IOC_MAX_GLOBAL > 0U)
        if (CROSS_CORE_COM == tempComMark)
        {
            Os_GetSpinlock(&Os_IocMailLock);
            pWorkMailCB = Os_MallocMail(&pIocCB->IocListHead, &pIocCB->IocPtrTailNode);
            Os_ReleaseSpinlock(&Os_IocMailLock);
        }
#endif

#if (CFG_IOC_MAX_LOCAL > 0U)
        if (INTER_CORE_COM == tempComMark)
        {
            pWorkMailCB = Os_MallocMail(&pIocCB->IocListHead, &pIocCB->IocPtrTailNode);
        }
#endif
        if (pWorkMailCB != (Os_IocMsgCBType*)0)
        {
            /* NOTE!! ++-->Reception has received mail data, so the mail data'address
             * shall be calculated in memory pool. */
            if (QUEUED_FIFO == pIocCB->IocQueueCom)
            {
                (void)Os_GetDataFromMemPoolForFIFO(pData, pIocCB, pWorkMailCB);
            }
            else
            {
                (void)Os_GetDataFromMemPoolForLIFO(pData, pIocCB, pWorkMailCB);
            }

/* NOTE!! ++-->Release the IOC control block. */
#if (CFG_IOC_MAX_GLOBAL > 0U)
            if (CROSS_CORE_COM == tempComMark)
            {
                Os_GetSpinlock(&Os_IocMailLock);
                (void)Os_ReleaseMail(pWorkMailCB, &OSIocMsgHeadGlobalPtr);
                Os_ReleaseSpinlock(&Os_IocMailLock);
            }
#endif

#if (CFG_IOC_MAX_LOCAL > 0U)
            if (INTER_CORE_COM == tempComMark)
            {
                (void)Os_ReleaseMail(pWorkMailCB, &OSIocMsgHeadLocalPtr);
            }
#endif

            /* NOTE!! ++-->In memory pool, using condition of memory pool shall be recorded. */
            pIocCB->IocMemPoolUsage -= pWorkMailCB->IocDataLenth;
            pIocCB->IocPipelistCnt--;

            Os_RetErr = IOC_E_OK;
        }
        else
        {
            Os_RetErr = IOC_E_NOK;
        }
    }
    else
    {
        Os_RetErr = IOC_E_NOK;
    }

    return Os_RetErr;
}

#if (CFG_IOC_MAX_GLOBAL > 0U)
/******************************************************************************/
/*
 * Brief                <In middle level, the API will receive cross-core data.>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <>
 * REQ ID               <>
 */
/******************************************************************************/
static FUNC(StatusType, OS_CODE) Os_IocCrossReceive(Os_IocAbsIdType absId, const Os_IocDataSourceType* pRcvData)
{
    StatusType Os_RetErr;
    Os_IocSemanticsType tempSema;
    Os_IocCBType* pIocCBEntry;
    Os_IocRelPipeNumType relPipeNum;

    OS_ARCH_DECLARE_CRITICAL();

    /* NOTE!! ++-->Get the relative pipe number. */
    relPipeNum = Os_IocCfgIdDesc[absId].Ioc_RelPipeIndex;
    pIocCBEntry = &OSIocCBGlobalPtr[relPipeNum];
    tempSema = pIocCBEntry->IocSemantics;

    /* NOTE!! ++-->Enter critical section. */
    (void)Os_GetSpinlock(&Os_IocSpinlock[relPipeNum]);
    OS_ARCH_ENTRY_CRITICAL();

    /* NOTE!! ++-->According to communication semantics, selecting the low-level
     * function to receive cross-core data. */
    if (pIocCBEntry->IocPipelistCnt > (Os_IoclistCntType)0)
    {
        if (CAT1_UNQUEUED == tempSema)
        {
            Os_RetErr = Os_LLReadData(pRcvData, pIocCBEntry);
        }
        else /* NOTE!! ++-->CAT2_QUEUED == tempSema */
        {
            Os_RetErr = Os_LLReceiveData(pRcvData, pIocCBEntry);
        }
    }
    else
    {
        Os_RetErr = IOC_E_NO_DATA;
    }

    /* NOTE!! ++-->Exit critical section. */
    OS_ARCH_EXIT_CRITICAL();
    (void)Os_ReleaseSpinlock(&Os_IocSpinlock[relPipeNum]);

    return Os_RetErr;
}
#endif

#if (CFG_IOC_MAX_LOCAL > 0U)
/******************************************************************************/
/*
 * Brief                <In middle level, the API will receive inter-core data.>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_InitSystem>
 * REQ ID               <>
 */
/******************************************************************************/
static FUNC(StatusType, OS_CODE) Os_IocInterReceive(Os_IocAbsIdType absId, const Os_IocDataSourceType* pRcvData)
{
    StatusType Os_RetErr;
    Os_IocSemanticsType tempSema;
    Os_IocCBType* pIocCBEntry;
    Os_IocRelPipeNumType relPipeNum;

    /* NOTE!! ++-->Get the relative pipe number. */
    relPipeNum = Os_IocCfgIdDesc[absId].Ioc_RelPipeIndex;
    pIocCBEntry = &OSIocCBLocalPtr[relPipeNum];
    tempSema = pIocCBEntry->IocSemantics;
    OS_ARCH_DECLARE_CRITICAL();

    /* NOTE!! ++-->Enter critical section. */
    OS_ARCH_ENTRY_CRITICAL();
    if (pIocCBEntry->IocPipelistCnt > (Os_IoclistCntType)0)
    {
        /* NOTE!! ++-->Call the low-level function to receive data. */
        if (CAT1_UNQUEUED == tempSema)
        {
            Os_RetErr = Os_LLReadData(pRcvData, pIocCBEntry);
        }
        else /* NOTE!! ++-->CAT1_QUEUED == tempSema */
        {
            Os_RetErr = Os_LLReceiveData(pRcvData, pIocCBEntry);
        }
    }
    else
    {
        Os_RetErr = IOC_E_NO_DATA;
    }

    /* NOTE!! ++-->Exit critical section. */
    OS_ARCH_EXIT_CRITICAL();

    return Os_RetErr;
}
#endif

/******************************************************************************/
/*
 * Brief                <In high level, the purpose of the API is receive data.
 *                       According to core communication property, the API will
 *                       select middle-level function to receive data.>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <>
 * REQ ID               <>
 */
/******************************************************************************/
/* PRQA S 1532++ */ /* MISRA Rule 8.7 */
FUNC(StatusType, OS_CODE) Os_IocHLReceive(Os_IocAbsIdType absId, const Os_IocDataSourceType* pData)
/* PRQA S 1532-- */ /* MISRA Rule 8.7 */
{
    StatusType Os_RetErr = IOC_E_OK;
    Os_IocCoreComType tempComMark;
    Os_IocRelPipeNumType relPipeNum;
    Os_IocCallbackType pFunPipeRcvCallback;
#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
    Os_IocPipeOsPosType tempOsPos = IOC_COM_INVALID;
    StatusType stdOut = E_NOT_OK;
#endif

    OS_IOCHLRCV_DEFINE();
    OS_IOCHLRCV_ENTRY();
#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif

    /* NOTE!! ++-->Get the relative pipe number. */
    relPipeNum = Os_IocCfgIdDesc[absId].Ioc_RelPipeIndex;
    tempComMark = Os_IocCfgIdDesc[absId].IocCfgCoreComMark;

#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
#if (CFG_IOC_MAX_GLOBAL > 0U)
    if (CROSS_CORE_COM == tempComMark)
    {
        tempOsPos = OSStdPipeCfgGlobalPtr[relPipeNum].IocPipeCfgPtr->IocPipeOsPos;
    }
#endif
#if (CFG_IOC_MAX_LOCAL > 0U)
    if (INTER_CORE_COM == tempComMark)
    {
        tempOsPos = OSStdPipeCfgLocalPtr[relPipeNum].IocPipeCfgPtr->IocPipeOsPos;
    }
#endif
#endif

#if (TRUE == OS_IOC_CHECKINPARA)
    if (IOC_E_OK != Os_IocCheckInPara(absId, pData))
    {
        Os_RetErr = IOC_E_NOK;
    }
#endif
#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
    if (IOC_E_OK == Os_RetErr)
    {
        if (tempOsPos != IOC_RCV_SIDE_NOS)
        {
            if (IOC_E_OK != Os_CheckSafeContext(absId, IOC_RCV_SIDE, &stdOut))
            {
                Os_RetErr = stdOut;
            }
            else
            {
                Os_RetErr = IOC_E_OK;
            }
        }
    }
#endif

    if (IOC_E_OK == Os_RetErr)
    {
#if (CFG_IOC_MAX_LOCAL > 0U)
        if (INTER_CORE_COM == tempComMark)
        {
            if (relPipeNum > OSIocCfgLocalMax)
            {
                Os_RetErr = IOC_E_NOK;
            }
            else
            {
                Os_RetErr = Os_IocInterReceive(absId, pData);
            }
        }
#endif

#if (CFG_IOC_MAX_GLOBAL > 0U)
        if (CROSS_CORE_COM == tempComMark)
        {
            if (relPipeNum > OSIocCfgGlobalMax)
            {
                Os_RetErr = IOC_E_NOK;
            }
            else
            {
                Os_RetErr = Os_IocCrossReceive(absId, pData);
            }
        }
#endif
    }

    if (IOC_E_OK == Os_RetErr)
    {
#if (CFG_IOC_MAX_GLOBAL > 0U)
        if (CROSS_CORE_COM == tempComMark)
        {
            pFunPipeRcvCallback = OSStdPipeCfgGlobalPtr[relPipeNum].IocPipeCfgPtr->IocReceiverPullCB;
        }
#endif
#if (CFG_IOC_MAX_LOCAL > 0U)
        if (INTER_CORE_COM == tempComMark)
        {
            pFunPipeRcvCallback = OSStdPipeCfgLocalPtr[relPipeNum].IocPipeCfgPtr->IocReceiverPullCB;
        }
#endif

        /* PRQA S 2962++ */ /* MISRA Rule 9.1 */
        if (pFunPipeRcvCallback != (Os_IocCallbackType)0)
        /* PRQA S 2962-- */ /* MISRA Rule 9.1 */
        {
            (void)pFunPipeRcvCallback();
        }
    }

    OS_IOCHLRCV_EXIT();
    return Os_RetErr;
}

/******************************************************************************/
/*
 * Brief                <Clear mail data.>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_InitSystem>
 * REQ ID               <>
 */
/******************************************************************************/
static FUNC(void, OS_CODE) Os_ClearMailData(Os_IocCBType* pIocCB, Os_IocCoreComType comMark, Os_IocSemanticsType sema)
{
    Os_IocMsgCBType* pMailCB;
    Os_IocListNodeType* ptr1;
    Os_IocListNodeType* ptr2;
    Os_IocU16Type ix;
    Os_IoclistCntType cnt;

    if (CAT2_QUEUED == sema)
    {
        ptr1 = pIocCB->IocListHead.IocNextNode;
        cnt = pIocCB->IocPipelistCnt;

        /* NOTE!! ++-->Clear all mail content of the pipe. */
        for (ix = (Os_IocU16Type)0; ix < cnt; ix++)
        {
            /* PRQA S 0488,0306,2810,3432++ */ /* MISRA Rule 18.4,11.4,1.3,20.7 */
            pMailCB = OS_CONTAINER_OF(ptr1, Os_IocMsgCBType, IocListNodeInfo);
            /* PRQA S 0488,0306,2810,3432-- */ /* MISRA Rule 18.4,11.4,1.3,20.7 */
            pMailCB->IocDataLenth = (Os_IocDateType)0;
            pMailCB->IocPtrMemPoolPosition = (Os_IocMemPoolPtrType)0;
            ptr1 = ptr1->IocNextNode;
        }

        ptr1 = pIocCB->IocListHead.IocNextNode;
        ptr2 = pIocCB->IocPtrTailNode;

/* NOTE!! ++-->Release multiple mail control block. */
#if (CFG_IOC_MAX_GLOBAL > 0U)
        if (CROSS_CORE_COM == comMark)
        {
            Os_GetSpinlock(&Os_IocMailLock);
            (void)Os_ReleaseMultiMail(ptr1, ptr2, &OSIocMsgHeadGlobalPtr);
            Os_ReleaseSpinlock(&Os_IocMailLock);
        }
#endif

#if (CFG_IOC_MAX_LOCAL > 0U)
        if (INTER_CORE_COM == comMark)
        {
            (void)Os_ReleaseMultiMail(ptr1, ptr2, &OSIocMsgHeadLocalPtr);
        }
#endif

        pIocCB->IocListHead.IocNextNode = (Os_IocListNodeType*)0;
        pIocCB->IocPtrTailNode = &(pIocCB->IocListHead);
    }
    else
    {
        /* NOTE!! ++-->Nothing to do. */
    }

    /* NOTE!! ++-->Clear the recording information of control block. */
    pIocCB->IocMemPoolPtr = pIocCB->IocMemPoolHeadPtr;
    pIocCB->IocMemPoolUsage = (Os_IocDateType)0;
    pIocCB->IocPipelistCnt = (Os_IoclistCntType)0;

    return;
}

#if (CFG_IOC_MAX_GLOBAL > 0U)
/******************************************************************************/
/*
 * Brief                <In case of queued communication identified by the <IocId>
 *                       in the function name, the content of the IOC internal
 *                       communication queue shall be deleted.>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_InitSystem>
 * REQ ID               <>
 */
/******************************************************************************/
static FUNC(StatusType, OS_CODE) Os_LLEmptyCrossQueue(Os_IocU16Type index)
{
    StatusType Os_RetErr = IOC_E_NOK; /* PRQA S 2981 */ /* MISRA Rule 2.2 */
    Os_IocCBType* pIocCBEntry;
    Os_IocSemanticsType tempSema;

    OS_ARCH_DECLARE_CRITICAL();

    pIocCBEntry = &OSIocCBGlobalPtr[index];
    tempSema = pIocCBEntry->IocSemantics;

    /* NOTE!! ++-->Enter critical section. */
    (void)Os_GetSpinlock(&Os_IocSpinlock[index]);
    OS_ARCH_ENTRY_CRITICAL();

    if (pIocCBEntry->IocPipelistCnt != (Os_IoclistCntType)0)
    {
        if (CAT1_UNQUEUED == tempSema)
        {
            (void)Os_ClearMailData(pIocCBEntry, CROSS_CORE_COM, CAT1_UNQUEUED);
        }
        else /* NOTE!! ++-->CAT2_QUEUED == tempSema */
        {
            (void)Os_ClearMailData(pIocCBEntry, CROSS_CORE_COM, CAT2_QUEUED);
        }
    }
    else
    {
        /* NOTE!! ++-->Nothing to do. */
    }

    /* NOTE!! ++-->Exit critical section. */
    OS_ARCH_EXIT_CRITICAL();
    (void)Os_ReleaseSpinlock(&Os_IocSpinlock[index]);

    Os_RetErr = IOC_E_OK;

    return Os_RetErr;
}
#endif

#if (CFG_IOC_MAX_LOCAL > 0U)
/******************************************************************************/
/*
 * Brief                <In case of queued communication identified by the <IocId>
 *                       in the function name, the content of the IOC internal
 *                       communication queue shall be deleted.>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_InitSystem>
 * REQ ID               <>
 */
/******************************************************************************/
static FUNC(StatusType, OS_CODE) Os_LLEmptyInterQueue(Os_IocU16Type index)
{
    StatusType Os_RetErr;
    Os_IocCBType* pIocCBEntry;
    Os_IocSemanticsType tempSema;

    OS_ARCH_DECLARE_CRITICAL();

    pIocCBEntry = &OSIocCBLocalPtr[index];
    tempSema = pIocCBEntry->IocSemantics;

    /* NOTE!! ++-->Enter critical section. */
    OS_ARCH_ENTRY_CRITICAL();

    if (pIocCBEntry->IocPipelistCnt != (Os_IoclistCntType)0)
    {
        if (CAT1_UNQUEUED == tempSema)
        {
            (void)Os_ClearMailData(pIocCBEntry, INTER_CORE_COM, CAT1_UNQUEUED);
        }
        else /* NOTE!! ++-->CAT2_QUEUED == tempSema */
        {
            (void)Os_ClearMailData(pIocCBEntry, INTER_CORE_COM, CAT2_QUEUED);
        }
    }
    else
    {
        /* NOTE!! ++--> Nothing to do. */
    }

    /* NOTE!! ++-->Exit critical section. */
    OS_ARCH_EXIT_CRITICAL();

    Os_RetErr = IOC_E_OK;

    return Os_RetErr;
}
#endif

/******************************************************************************/
/*
 * Brief                <In case of queued communication identified by the <IocId>
 *                       in the function name, the content of the IOC internal
 *                       communication queue shall be deleted.>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_InitSystem>
 * REQ ID               <>
 */
/******************************************************************************/
FUNC(StatusType, OS_CODE) Os_IocHLEmptyQueue(Os_IocAbsIdType absId) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    StatusType Os_RetErr = IOC_E_NOK;
    Os_IocCoreComType tempCoreCom;
    Os_IocRelPipeNumType relPipeNum;

    OS_IOCHLEPTQUE_DEFINE();
    OS_IOCHLEPTQUE_ENTRY();
#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif

    /* NOTE!! ++-->Get flag of communication. */
    tempCoreCom = Os_IocCfgIdDesc[absId].IocCfgCoreComMark;
    /* NOTE!! ++-->Get the relative pipe number. */
    relPipeNum = Os_IocCfgIdDesc[absId].Ioc_RelPipeIndex;

#if (CFG_IOC_MAX_GLOBAL > 0U)
    if (CROSS_CORE_COM == tempCoreCom)
    {
        Os_RetErr = Os_LLEmptyCrossQueue(relPipeNum);
    }
#endif

#if (CFG_IOC_MAX_LOCAL > 0U)
    if (INTER_CORE_COM == tempCoreCom)
    {
        Os_RetErr = Os_LLEmptyInterQueue(relPipeNum);
    }
#endif

    OS_IOCHLEPTQUE_EXIT();
    return Os_RetErr;
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
#endif /* */
/*=======[E N D   O F   F I L E]==============================================*/
