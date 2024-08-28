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
**  FILENAME    : BswM_Cfg.h                                                  **
**                                                                            **
**  Created on  : 2024/01/10 17:27:46                                           **
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
/*  <VERSION>    <DATE>        <AUTHOR>        <REVISION LOG>
 *  V1.0.0       2020-03-24  qinchun.yang    R19_11 BswM initial version.
 */
#ifndef BSWM_CFG_H
#define BSWM_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/*For compatibility with v4.2.2 and vR1911*/
#define BSWM_ECUM_VERSION                       BSWM_V_R19_11
#define BSWM_COM_VERSION                       BSWM_V_4_2_2

#define BSWM_EVENT_RQSTPORT_ENABLE            STD_OFF

#define BSWM_MODE_RQSTPORT_ENABLE             STD_ON

/*BswMDevErrorDetect*/
#define BSWM_DEV_ERROR_DETECT                STD_ON

/*BswMCanSMEnabled*/
#define BSWM_CANSM_ENABLED                    STD_ON

/*BswMCanSMIcomEnabled*/
#define BSWM_CANSM_ICOM_ENABLED                STD_OFF

/*BswMComEnabled*/
#define BSWM_COM_ENABLED                    STD_ON

/*BswMComMEnabled*/
#define BSWM_COMM_ENABLED                    STD_ON

#define BSWM_COMM_MODE_LIMITATION_ENABLED    STD_OFF

#define BSWM_COMM_PNC_ENABLED               STD_OFF

/*BswMDcmEnabled*/
#define BSWM_DCM_ENABLED                    STD_ON

/*BswMEcuMEnabled*/
#define BSWM_ECUM_ENABLED                    STD_ON

/*BswMEthIfEnabled*/
#define BSWM_ETHIF_ENABLED                  STD_OFF

/*BswMEthSMEnabled*/
#define BSWM_ETHSM_ENABLED                    STD_OFF

/*BswMFrSMEnabled*/
#define BSWM_FRSM_ENABLED                    STD_OFF

/*BswMGenericRequestEnabled*/
#define BSWM_GENERIC_REQUEST_ENABLED        STD_ON

/*BswMJ1939DcmEnabled*/
#define  BSWM_J1939DCM_ENABLED                STD_OFF

/*BswMJ1939RmEnabled, calculated according to the action existence*/
#define BSWM_J1939RM_ENABLED                   STD_OFF       /* create J1939Rm */

/*BswMJ1939NmEnabled*/
#define BSWM_J1939NM_ENABLED                STD_OFF

/*BswMLinSMEnabled*/
#define BSWM_LINSM_ENABLED                    STD_ON

/*BswMLinTPEnabled*/
#define BSWM_LINTP_ENABLED                    STD_OFF

/*BswMNMEnabled*/
#define BSWM_NM_ENABLED                        STD_ON

/*BswMPduREnabled, calculated according to the action existence*/
#define BSWM_PDUR_ENABLED                   STD_ON          /* create Pdur */

/*BswMNvMEnabled*/
#define BSWM_NVM_ENABLED                    STD_ON

/*BswMSchMEnabled*/
#define BSWM_SCHM_ENABLED                    STD_OFF

/*BswMSdEnabled*/
#define BSWM_SD_ENABLED                        STD_OFF

/*BswMRteEnabled, calculated according to the SWC RTE request port and action existence*/
#define BSWM_RTE_ENABLED                       STD_OFF

#define BSWM_TIMER_ENABLED                    STD_ON

/*BswMVersionInfoApi*/
#define BSWM_VERSION_INFO_API                STD_OFF

/*BswMWdgMEnabled*/
#define BSWM_WDGM_ENABLED                    STD_OFF

#define BSWM_MULTI_PARTITION_ENABLED       STD_OFF

#define BSWM_MAX_NUM_CORE                   1u

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
typedef uint8 BswM_TimerIdxType;

typedef uint8 BswM_EventRqstPortIdxType;

typedef uint8 BswM_RuleIndexType;

typedef uint8 BswM_ActionListIndexType;

typedef uint8 BswM_ComIpduGruType;

typedef uint8 BswM_ModeGroupType;

/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
extern void BswM_Run_Callout(void);
extern void BSWM_AppRun_Callout(void);
extern void BSWM_EnterAppRun(void);
extern void BSWM_EnterShutDown(void);
extern void BswM_PowerON_KL15_Check_Callout(void);
extern void NvM_ReadAll(void);
extern void BswM_ReadAllFinish_CallOut(void);
extern void BswM_WriteAllFinish_CallOut(void);

#endif /* BSWM_CFG_H */
