
/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2023)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : Dcm_Cfg.h                                                   **
**                                                                            **
**  Created on  : 2024/01/05 14:43:47                                         **
**  Author      : long.zhu                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : Dcm Configuration file.                                     **
**                                                                            **
**  SPECIFICATION(S) :   UDS Service - ISO14229                               **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/** <VERSION>   <DATE>     <AUTHOR>          <REVISION LOG>
 *  V1.0.0     20230818    long.zhu          Initial Version
 */
#ifndef DCM_CFG_H
#define DCM_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "GptIf_Cfg.h"
#include "Dcm_Types.h"

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* use for the MCU time offset, for example, the P2 time is 50ms, if you
 * configure the p2 to 50,the MCU maybe response 78 at 51ms, it is exceed the
 * configure time 50, so you shall consider this question.  */
#define DCM_TIME_OFFSET             (0u)

/* Positive response inhibition */
#define DCM_SUPPRESS_POS_SUPPORT            STD_ON

/* 19 Service enable or not*/
#define DCM_SERVICE_0X19_ENABLE             STD_OFF

/* 38 Service enable or not*/
#define DCM_SERVICE_0X38_ENABLE             STD_OFF

/** main receive buffer size */
/* @type:uint16 range:1~4095 note:NONE */
#define DCM_RX_BUF_SIZE             4095u

/** main send buffer size */
/* @type:uint16 range:1~4095 note:NONE */
#define DCM_TX_BUF_SIZE             400u

/* DCM protocol time :P2
 * @type:define range:1~65535 note:unit ms
 */
#define DCM_P2MAX_TIME              (50u)

/* DCM protocol time :P2*
 * @type:define range:1~65535 note:unit ms
 */
#define DCM_P2SMAX_TIME            (5000u)

/* DCM protocol time :S3
 * @type:define range:1~65535 note:unit ms
 */
#define DCM_P3MAX_TIME              (5000u)

/* DCM protocol time :P4
 * @type:define range:1~65535 note:unit ms
 */
#define DCM_P4MAX_TIME              50000u

/* DCM protocol time :P4 of erase routine service;
 * @type:define range:1~65535 note:unit ms
 */
#define DCM_P4MAX_TIME_ERASE        500000u

/* DCM main task tick time
 * type:define
 */
#define DCM_MAIN_TICK               GPT_PERIOD_TIME

/** DCM security access time */
/* security access timeout on boot */
/* @type:define range:0~65535 note:unit ms */
#define DCM_SECURITY_TIME_ON_BOOT   0u

/* security access timeout when failed */
/* @type:define range:0~65535 note:unit ms */
#define DCM_SECURITY_TIME           10000uL

/* security access attempt max num */
/* @type:define range:0~65535 note:NONE */
#define DCM_SECURITY_ATTEMPT_NUM    3u

/** service table num */
/* @type:define range:1~255 note:reference to Dcm_ServiceTable */
#define DCM_SERVICE_NUM             12u

/** session mode num */
/* @type:define range:1~3 note:reference to Dcm_SessionRow */
#define DCM_SESSION_NUM             3u

/** reset mode num */
/* @type:define range:1~255 note:reference to Dcm_ResetRow */
#define DCM_RESET_NUM               3u

/** read data ID num */
/* @type:define range:0~255 note:reference to Dcm_ReadDidRow */
#define DCM_READDID_NUM             1u

/** security level num,not include locked level */
/* @type:define range:1~2 note:reference to Dcm_SecurityRow */
#define DCM_SECURITY_NUM            1u

/* the length of seed */
#define DCM_SEED_MAX_LENGTH         0x4u

/* the length of key  */
#define DCM_KEY_MAX_LENGTH          0x4u

/** routine control ID num */
/* @type:define range:1~255 note:reference to Dcm_RoutineControlRow */
#define DCM_ROUTINE_CONTROL_NUM     5u

/** communication control num */
/* @type:define range:0~255 note:reference to Dcm_ComControlRow */
#define DCM_COM_CONTROL_NUM         4u

/** write data ID num */
/* @type:define range:1~255 note:reference to Dcm_WriteDidRow */
#define DCM_WRITEDID_NUM            1u

/** download row num */
/* @type:define range:1~255 note:reference to Dcm_DownloadRow */
#define DCM_DOWNLOADROW_NUM         1u

/** test present num */
/* @type:define range:0~255 note:reference to Dcm_testPresentRow */
#define DCM_TESTPRESENT_NUM         1u

/** DTC setting mode num */
/* @type:define range:0~255 note:reference to Dcm_DTCSettingRow */
#define DCM_DTC_SET_NUM             2u

/*service 27 security access lock type*/
#define DCM_SECURITY_LEV5              0x5u

/* service 22 maxinum number of DIDs received at a time */
#define DCM_READDID_MAX_NUM         256u

#define DCM_PDU_GRP_NUM         2u

/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/
extern const Dcm_ServiceTableType Dcm_ServiceTable[DCM_SERVICE_NUM];

extern const Dcm_SessionRowType Dcm_SessionRow[DCM_SESSION_NUM];

#if (DCM_RESET_NUM > 0u)
extern const Dcm_ResetRowType Dcm_ResetRow[DCM_RESET_NUM];
#endif

#if (DCM_READDID_NUM > 0u)
extern const Dcm_ReadDidRowType Dcm_ReadDidRow[DCM_READDID_NUM];
#endif

extern const Dcm_SecurityRowType Dcm_SecurityRow[DCM_SECURITY_NUM];

#if (DCM_COM_CONTROL_NUM > 0u)
extern const Dcm_ComControlRowType Dcm_ComControlRow[DCM_COM_CONTROL_NUM];
#endif

#if (DCM_WRITEDID_NUM > 0u)
extern const Dcm_WriteDidRowType Dcm_WriteDidRow[DCM_WRITEDID_NUM];
#endif

#if (DCM_ROUTINE_CONTROL_NUM > 0u)
extern const Dcm_RoutineControlRowType Dcm_RoutineControlRow[DCM_ROUTINE_CONTROL_NUM];
#endif

extern const Dcm_DownloadRowType Dcm_DownloadRow[DCM_DOWNLOADROW_NUM];

#if (DCM_SERVICE_0X38_ENABLE == STD_ON)
extern const Dcm_RequestFileTransferType Dcm_RequestFileTransfer;
#endif

extern const Dcm_testPresentRowType Dcm_testPresentRow[DCM_TESTPRESENT_NUM];

#if (DCM_DTC_SET_NUM > 0u)
extern const Dcm_DTCSettingRowType Dcm_DTCSettingRow[DCM_DTC_SET_NUM];
#endif

#if (DCM_PDU_GRP_NUM > 0u)
extern const PduIdGrpType Dcm_PduID_Cfg[DCM_PDU_GRP_NUM];
#endif
/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

#endif/* endif of DCM_CFG_H */

