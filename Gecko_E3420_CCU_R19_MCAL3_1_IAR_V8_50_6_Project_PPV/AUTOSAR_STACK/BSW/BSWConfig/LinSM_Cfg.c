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
**  FILENAME    : LinSM_cfg.c                                                 **
**                                                                            **
**  Created on  : 2024/01/09 10:06:25                                 **
**  Author      : HuRongbo                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : Pre-compile parameter definition of LinSM                   **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                                 Includes                                   **
*******************************************************************************/
#include "LinSM.h"

/*******************************************************************************
**                               Configuration                                **
*******************************************************************************/
#define LINSM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "LinSM_MemMap.h"
static CONST(LinSM_ScheduleType, LINSM_CONST)  LinSM_ScheduleData[]=
{
    {
        LINSM_LinIfScheduleTable_Schedule1_LIN1, /* LinSMScheduleIndex */
        LinIfScheduleTable_Schedule1_LIN1    /* LinSMScheduleIndexRef */
    },
    {
        LINSM_LinIfScheduleTable_Schedule2_LIN1, /* LinSMScheduleIndex */
        LinIfScheduleTable_Schedule2_LIN1    /* LinSMScheduleIndexRef */
    },
    {
        LINSM_LinIfScheduleTable_Schedule1_LIN2, /* LinSMScheduleIndex */
        LinIfScheduleTable_Schedule1_LIN2    /* LinSMScheduleIndexRef */
    },
    {
        LINSM_LinIfScheduleTable_Schedule2_LIN2, /* LinSMScheduleIndex */
        LinIfScheduleTable_Schedule2_LIN2    /* LinSMScheduleIndexRef */
    },
    {
        LINSM_LinIfScheduleTable_Schedule1_LIN3, /* LinSMScheduleIndex */
        LinIfScheduleTable_Schedule1_LIN3    /* LinSMScheduleIndexRef */
    },
};

static CONST(LinSM_ChannelType, LINSM_CONST)  LinSM_ChannelCfg[LINSM_CHANNEL_NUM] =
{

    {
        20u,                     /* LinSMConfirmationTimeout */
        LINSM_MASTER,               /* LinSMNodeType */
        0u,  /* LinSMSilenceAfterWakeupTimeout */
        STD_OFF,                /* LinSMTransceiverPassiveModeSupport */
        FALSE,                    /* LinSMTransceiverPassiveMode */
        ComMChannel_CCU_LIN1,                        /* LinSMComMNetworkHandleRef */
        &LinSM_ScheduleData[0],    /* LinSMSchedule */
        2u                        /* LinSMScheduleNum */
    },
    {
        20u,                     /* LinSMConfirmationTimeout */
        LINSM_MASTER,               /* LinSMNodeType */
        0u,  /* LinSMSilenceAfterWakeupTimeout */
        STD_OFF,                /* LinSMTransceiverPassiveModeSupport */
        FALSE,                    /* LinSMTransceiverPassiveMode */
        ComMChannel_CCU_LIN2,                        /* LinSMComMNetworkHandleRef */
        &LinSM_ScheduleData[2],    /* LinSMSchedule */
        2u                        /* LinSMScheduleNum */
    },
    {
        20u,                     /* LinSMConfirmationTimeout */
        LINSM_MASTER,               /* LinSMNodeType */
        0u,  /* LinSMSilenceAfterWakeupTimeout */
        STD_OFF,                /* LinSMTransceiverPassiveModeSupport */
        FALSE,                    /* LinSMTransceiverPassiveMode */
        ComMChannel_CCU_LIN3,                        /* LinSMComMNetworkHandleRef */
        &LinSM_ScheduleData[4],    /* LinSMSchedule */
        1u                        /* LinSMScheduleNum */
    },
};

CONST(LinSM_ConfigType, LINSM_CONST)  LinSM_PCConfig =  /* PRQA S 1531 */ /* MISRA Rule 8.7 */
{
    2,                  /* LinSMModeRequestRepetitionMax */
    LinSM_ChannelCfg    /* LinSMChannel */
};
#define LINSM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "LinSM_MemMap.h"

