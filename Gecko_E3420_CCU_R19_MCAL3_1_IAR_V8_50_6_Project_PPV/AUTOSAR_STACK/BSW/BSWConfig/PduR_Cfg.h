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
**  FILENAME    : PduR_Cfg.h                                                  **
**                                                                            **
**  Created on  : 2024/12/10 11:21:30                                         **
**  Author      : zhengfei.li                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : Configuration parameter of PDUR                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
#ifndef  PDUR_CFG_H
#define  PDUR_CFG_H
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "ComStack_Types.h"
#include "PduR_PBcfg.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#define PDUR_CFG_H_AR_MAJOR_VERSION  4u
#define PDUR_CFG_H_AR_MINOR_VERSION  2u
#define PDUR_CFG_H_AR_PATCH_VERSION  2u
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/

#define PDUR_ZERO_COST_OPERATION        STD_OFF

#define PDUR_DEV_ERROR_DETECT           STD_ON

#define PDUR_META_DATA_SUPPORT          STD_OFF

#define PDUR_VERSION_INFO_API           STD_OFF

#define PDUR_BSW_MODULE_SUM             6u
#define PDUR_COM      0u
#define PDUR_CANIF      1u
#define PDUR_CANNM      2u
#define PDUR_CANTP      3u
#define PDUR_DCM      4u
#define PDUR_LINIF      5u

#define PDUR_TRANSMIT_SUPPORT                 STD_ON

#define PDUR_CANCEL_TRANSMIT                  STD_OFF
#define PDUR_CHANGE_PARAMETER                 STD_OFF
#define PDUR_CANCEL_RECEIVE                   STD_OFF
#define PDUR_RX_INDICATION                    STD_ON
#define PDUR_TX_CONFIRMATION                  STD_ON
#define PDUR_TRIGGER_TRANSMIT                 STD_ON
#define PDUR_TP_STARTOFRECEPTION_TRANSMIT     STD_ON
#define PDUR_TP_COPYRXDATA                    STD_ON
#define PDUR_TP_RXINDICATION                  STD_ON
#define PDUR_TP_COPYTXDATA                    STD_ON
#define PDUR_TP_TXCONFIRMATION                STD_ON

#define PDUR_ROUTINGPATH_MAX                  215u
#define PDUR_ROUTING_PATH_GROUP_MAX           2u

#define PDUR_TP_BUFFER_SUM           0u
#define PDUR_TX_BUFFER_SUM           0u

#endif  /* end of PDUR_CFG_H */

/*******************************************************************************
**                      End of file                                           **
*******************************************************************************/

