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
**  FILENAME    : PduR_Cfg.c                                                  **
**                                                                            **
**  Created on  : 2024/01/08 10:33:45                                         **
**  Author      : zhengfei.li                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : Configuration parameter of PDUR                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "PduR.h"
#include "CanIf.h"
#include "CanTp.h"
#include "Com_Cbk.h"
#include "Dcm.h"
#include "Dcm_Cbk.h"
#include "CanNm.h"
#include "LinIf.h"
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#define PDUR_CFG_C_AR_MAJOR_VERSION  4u
#define PDUR_CFG_C_AR_MINOR_VERSION  2u
#define PDUR_CFG_C_AR_PATCH_VERSION  2u

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

#define PDUR_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"
CONST(PduRBswModuleType,PDUR_CONST)
PduR_BswModuleConfigData[PDUR_BSW_MODULE_SUM] = /* PRQA S 3408 */ /* MISRA Rule 8.4 */
{
    {
        PDUR_COM,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        Com_TriggerTransmit,
        NULL_PTR,
        Com_TxConfirmation,
        Com_RxIndication,
        NULL_PTR,
        Com_CopyTxData,
        Com_TpTxConfirmation,
        Com_StartOfReception,
        Com_CopyRxData,
        Com_TpRxIndication,
    },
    {
        PDUR_CANIF,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        CanIf_Transmit,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
    },
    {
        PDUR_CANNM,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        CanNm_Transmit,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
    },
    {
        PDUR_CANTP,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        CanTp_Transmit,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
    },
    {
        PDUR_DCM,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        Dcm_TxConfirmation,
        NULL_PTR,
        NULL_PTR,
        Dcm_CopyTxData,
        Dcm_TpTxConfirmation,
        Dcm_StartOfReception,
        Dcm_CopyRxData,
        Dcm_TpRxIndication,
    },
    {
        PDUR_LINIF,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        LinIf_Transmit,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
    },
};
#define PDUR_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"

/*******************************************************************************
**                      End of file                                           **
*******************************************************************************/

