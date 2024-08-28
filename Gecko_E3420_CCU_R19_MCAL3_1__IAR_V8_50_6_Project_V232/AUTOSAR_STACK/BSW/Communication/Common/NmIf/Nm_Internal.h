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
**  FILENAME    : Nm_Internal.h                                               **
**                                                                            **
**  Created on  :                                                             **
**  Author      : Wanglili                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
#ifndef NM_INTERNAL_H_
#define NM_INTERNAL_H_

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "NmStack_Types.h"

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define NM_MODULE_ID   ((uint16)(29u))
#define NM_VENDOR_ID   ((uint16)(62u))
#define NM_INSTANCE_ID ((uint8)(0u))

#if (STD_ON == NM_DEV_ERROR_DETECT)
#define NM_DET_REPORT(Appid, ErrorId) ((void)Det_ReportError(NM_MODULE_ID, NM_INSTANCE_ID, (Appid), (ErrorId)))
#else
#define NM_DET_REPORT(Appid, ErrorId)
#endif /* STD_ON == NM_DEV_ERROR_DETECT */

/* claclulate array element count */
#define NM_UBOND(x) (sizeof(x) / sizeof((x)[0]))

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* used cycle find */
typedef uint32 uintx;

#if (STD_ON == NM_STATE_CHANGE_IND_ENABLED)
/* nm state and report signal value */
typedef struct
{
    /* nmPreviousState */
    Nm_StateType nmPreSta;
    /* nmCurrentState */
    Nm_StateType nmCurSta;
    /* report singnal value */
    uint8 signalVal;
} Nm_StateReportKindType;
#endif /* STD_ON == NM_STATE_CHANGE_IND_ENABLED */
#if (STD_ON == NM_COORDINATOR_SUPPORT_ENABLED)

/* shutdown timer type */
typedef uint16 shutdownTimerType;

typedef enum
{
    /*shut down coordinated initial state*/
    NM_SHUTDOWN_STU_INIT = 0x0u,
    /*shut down coordinated start*/
    NM_SHUTDOWN_STU_START,
    /*shut down coordinated cancel*/
    NM_SHUTDOWN_STU_ABORT,
    /*shut down coordinated is going,network not relase*/
    NM_SHUTDOWN_STU_RUN,
    /*shut down coordinated success,network relase*/
    NM_SHUTDOWN_STU_STOP,
} Nm_ShutdownStatusType;

/* nm inner channel struct */
typedef struct
{
    /* remote sleep indication */
    boolean remoteSleepIndFlg;
    /* bus awake flage */
    boolean busAwakeFlg;
    /* notify lower layer network request */
    boolean lowLayNetRequest;
    /* ComM request network */
    boolean upLayNetRequest;
    /* allow shutdown */
    boolean allowShutdown;
#if (STD_ON == NM_COORDINATOR_SYNC_SUPPORT)
    /* coordinator ready sleep bit */
    boolean coorRSB;
#endif /* STD_ON ==  NM_COORDINATOR_SYNC_SUPPORT */
    boolean lowLayBusSyncPoint;
    /* shutdown timer */
    shutdownTimerType shutdownTimer;
} Nm_InnerChannelType;

typedef struct
{
    Nm_ShutdownStatusType shutdownStatus;
} Nm_InnerClusterType;

#endif /* STD_ON == NM_COORDINATOR_SUPPORT_ENABLED */

/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/
/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
#endif /* NM_INTERNAL_H_ */
