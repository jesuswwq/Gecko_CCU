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
**  FILENAME    : BswM_Types.h                                                  **
**                                                                            **
**  Created on  : 2020-03-24                                                  **
**  Author      : qinchun.yang                                                **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

#ifndef BSWM_TYPES_H
#define BSWM_TYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "BswM_Cfg.h"
#include "ComStack_Types.h"
#include "Rte_BswM_Type.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define BSWM_V_4_2_2  0u
#define BSWM_V_R19_11 1u

/*Event request port status*/
#define BSWM_EVENT_IS_SET     1u
#define BSWM_EVENT_IS_CLEARED 0u
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/*initialization status of BSWM module*/
typedef enum
{
    BSWM_UNINITED,
    BSWM_INITED
} BswM_InitStatusType;

/*BswMRequestProcessing*/
typedef enum
{
    BSWM_DEFERRED = 0u,
    BSWM_IMMEDIATE
} BswM_RqstPortProcessType;

/*BswMRule result type, e.g. for BswMRuleInitState*/
typedef enum
{
    BSWM_FALSE = 0u,
    BSWM_TRUE,
    BSWM_UNDEFINED
} BswM_RuleStateType;

/*BswM Action List Execution type*/
typedef enum
{
    BSWM_CONDITION = 0u,
    BSWM_TRIGGER
} BswM_ActionListExecutionType;

/*target Action type*/
typedef enum
{
    BSWM_CLEAR_EVENT_REQST = 0,
    BSWM_COMM_ALLOW_COM,
    BSWM_COMM_MODE_LIMITATION,
    BSWM_COMM_MODE_SWITCH,
    BSWM_CORE_HALT_MODE,
    BSWM_DEADLINE_MONITOR_CONTROL,
#if (BSWM_ECUM_VERSION == BSWM_V_4_2_2)
    BSWM_ECUM_GO_DOWN,
    BSWM_ECUM_GO_HALT,
    BSWM_ECUM_GO_POLL,
#else
    BSWM_ECUM_GO_DOWN_HALT_POLL,
#endif /*(BSWM_ECUM_VERSION == BSWM_V_4_2_2)*/
    BSWM_ECUM_DRIVER_INIT_BSWM,
    BSWM_ECUM_SELECT_SHUTDOWN_TARGET,
    BSWM_ECUM_STATE_SWITCH,
    BSWM_ETHIF_SWITCH_PORT_GROUP,
    BSWM_FRSM_ALL_SLOTS,
    BSWM_J1939DCM_STATE_SWITCH,
    BSWM_J1939RM_STATE_SWITCH,
    BSWM_LIN_SCHEDULE_SWITCH,
    BSWM_NM_CONTROL,
    BSWM_PDU_GROUP_SWITCH,
    BSWM_PDU_ROUTER_CONTROL,
    BSWM_RTE_MODE_REQUEST,
    BSWM_RTE_START,
    BSWM_RTE_STOP,
    BSWM_RTE_SWITCH,
    BSWM_SCHM_SWITCH,
    BSWM_SD_CLIENT_SERVICE_MODE_REQUEST,
    BSWM_SD_CONSUMED_EVENT_GROUP_MODE_REQUEST,
    BSWM_SD_SERVER_SERVICE_MODE_REQUEST,
    BSWM_SWITCH_IPDU_MODE,
    BSWM_TIMER_CONTROL,
    BSWM_TRIGGER_IPDU_SEND,
    BSWM_USER_CALLOUT
} BswM_ActionEnumType;

/*BswM action item enumeration type*/
typedef enum
{
    BSWM_ACTIONITEM_ACTION = 0u,
    BSWM_ACTIONITEM_ACTIONLIST,
    BSWM_ACTIONITEM_RULE
} BswM_ActionListItemEnumType;

/*BswM timer enumeration type*/
typedef enum
{
    BSWM_TIMER_START = 0u,
    BSWM_TIMER_STOP,
    BSWM_TIMER_EXPIRED
} BswM_TimerEnumType;
/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

#endif /* BSWM_TYPES_H */
