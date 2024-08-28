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
**  FILENAME    : Nm_Lcfg.c                                                   **
**                                                                            **
**  Created on  :                                                             **
**  Author      : Wanglili                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Nm.h"
#include "ComM_Cfg.h"
#include "CanNm.h"
/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/
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

#define NM_START_SEC_CONST_UNSPECIFIED
#include "Nm_MemMap.h"
static const Nm_SpecificLowLayerApiType Nm_CanNmSpecificApi=
{
    CanNm_NetworkRequest,
    CanNm_NetworkRelease,
    CanNm_PassiveStartUp,
    CanNm_DisableCommunication,
    CanNm_EnableCommunication,
    CanNm_GetUserData,
    CanNm_GetPduData,
    CanNm_RepeatMessageRequest,
    CanNm_GetNodeIdentifier,
    CanNm_GetLocalNodeIdentifier,
    CanNm_GetState,
};
#define NM_STOP_SEC_CONST_UNSPECIFIED
#include "Nm_MemMap.h"

#define NM_START_SEC_CONST_UNSPECIFIED
#include "Nm_MemMap.h"
const Nm_ChannelLConfigType Nm_ChLConfig[NM_NUMBER_OF_CHANNELS] = /* PRQA S 1531 */ /* MISRA Rule 8.7 */
{
    {
        NM_BUSNM_CANNM,    /* NmStandardBusType */
        {
            3,        /* NmComMChannelRef */
        },
        &Nm_CanNmSpecificApi,     /*busNmApi */
        FALSE, /*NmStateReportEnabled*/
        {
            0xff
        },
    },
    {
        NM_BUSNM_CANNM,    /* NmStandardBusType */
        {
            5,        /* NmComMChannelRef */
        },
        &Nm_CanNmSpecificApi,     /*busNmApi */
        FALSE, /*NmStateReportEnabled*/
        {
            0xff
        },
    },
    {
        NM_BUSNM_CANNM,    /* NmStandardBusType */
        {
            0,        /* NmComMChannelRef */
        },
        &Nm_CanNmSpecificApi,     /*busNmApi */
        FALSE, /*NmStateReportEnabled*/
        {
            0xff
        },
    },
    {
        NM_BUSNM_CANNM,    /* NmStandardBusType */
        {
            2,        /* NmComMChannelRef */
        },
        &Nm_CanNmSpecificApi,     /*busNmApi */
        FALSE, /*NmStateReportEnabled*/
        {
            0xff
        },
    },
};
#define NM_STOP_SEC_CONST_UNSPECIFIED
#include "Nm_MemMap.h"

