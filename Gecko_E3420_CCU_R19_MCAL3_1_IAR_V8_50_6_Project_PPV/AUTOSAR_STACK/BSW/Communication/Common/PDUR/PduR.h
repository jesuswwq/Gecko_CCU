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
**  FILENAME    : PduR.h                                                      **
**                                                                            **
**  Created on  :                                                             **
**  Author      : zhengfei.li                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : API declaration and type definitions of PDUR                **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2 and R19_11            **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
#ifndef PDUR_H
#define PDUR_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "PduR_Types.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define PDUR_VENDOR_ID          62u
#define PDUR_MODULE_ID          51u
#define PDUR_INSTANCE_ID        0u
#define PDUR_H_AR_MAJOR_VERSION 4u
#define PDUR_H_AR_MINOR_VERSION 2u
#define PDUR_H_AR_PATCH_VERSION 2u
#define PDUR_H_SW_MAJOR_VERSION 2u
#define PDUR_H_SW_MINOR_VERSION 1u
#define PDUR_H_SW_PATCH_VERSION 1u

#if (STD_OFF == PDUR_ZERO_COST_OPERATION)

#if (STD_ON == PDUR_DEV_ERROR_DETECT)
/* General function id */
#define PDUR_INIT_ID               (0xF0u)
#define PDUR_GETVERSIONINFO_ID     (0xF1u)
#define PDUR_GETCONFIGURATIONID_ID (0xF2u)
#define PDUR_ENABLEROUTING_ID      (0xF3u)

#define PDUR_TRANSMIT_ID           (0x49u)
#define PDUR_CANCELTRANSMIT_ID     (0x4Au)
#define PDUR_CHANGEPARAMETER_ID    (0x4Bu)
#define PDUR_CANCELRECEIVE_ID      (0x4Cu)

#define PDUR_TPCOPYRXDATA_ID       (0x44u)
#define PDUR_TPRXINDICATION_ID     (0x45u)
#define PDUR_TPSTARTOFRECEPTION_ID (0x46u)
#define PDUR_TPCOPYTXDATA_ID       (0x43u)
#define PDUR_TPTXCONFIRMATION_ID   (0x48u)

/* Error Classification */
#define PDUR_E_INIT_FAILED                   (0x00u)
#define PDUR_E_PARAM_POINTER                 (0x09u)
#define PDUR_E_UNINIT                        (0x01u)
#define PDUR_E_PDU_ID_INVALID                (0x02u)
#define PDUR_E_ROUTING_PATH_GROUP_ID_INVALID (0x08u)
#endif /*STD_ON == PDUR_DEV_ERROR_DETECT*/

/*The API and DET Ref to Det_ReportRuntimeError*/
#define PDUR_DISABLEROUTING_ID    (0xF4u)
#define PDUR_IFRXINDICATION_ID    (0x42u)
#define PDUR_IFTRIGGERTRANSMIT_ID (0x41u)
#define PDUR_IFTXCONFIRMATION_ID  (0x40u)
#define PDUR_E_TP_TX_REQ_REJECTED (0x03u)
#define PDUR_E_PDU_INSTANCES_LOST (0x0Au)

/*the Private Macro Definition*/
#define PDUR_UNUSED_UINT8           (0xFFu)
#define PDUR_UNUSED_UINT16          (0xFFFFu)
#define PDUR_NOUSED(paramter)       (void)(paramter)

#define PDUR_ROUTEPATHGROUP_CFG(id) (PduR_ConfigStd->PduRRoutingPathGroupRef[id])

#define PDUR_DESTPDU_CFG(id)        (PduR_ConfigStd->PduRDestPduRef[id])

#define PDUR_SRCEPDU_CFG(id)        (PduR_ConfigStd->PduRSrcPduRef[id])

#define PDUR_ROUTINGPATH_CFG(id) \
    (PduR_ConfigStd->PduRRoutingTableRef[PduR_ConfigStd->PduRConfigId].PduRRoutingPathRef[id])

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

#if (STD_ON == PDUR_VERSION_INFO_API)
#if (STD_ON == PDUR_DEV_ERROR_DETECT)
#define PduR_GetVersionInfo(VersionInfo)                                                                     \
    do                                                                                                       \
    {                                                                                                        \
        if (NULL_PTR == (VersionInfo))                                                                       \
        {                                                                                                    \
            Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_GETVERSIONINFO_ID, PDUR_E_PARAM_POINTER); \
        }                                                                                                    \
        else                                                                                                 \
        {                                                                                                    \
            (VersionInfo)->vendorID = PDUR_VENDOR_ID;                                                        \
            (VersionInfo)->moduleID = PDUR_MODULE_ID;                                                        \
            (VersionInfo)->sw_major_version = PDUR_H_SW_MAJOR_VERSION;                                       \
            (VersionInfo)->sw_minor_version = PDUR_H_SW_MINOR_VERSION;                                       \
            (VersionInfo)->sw_patch_version = PDUR_H_SW_PATCH_VERSION;                                       \
        }                                                                                                    \
    } while (0)
#else
#define PduR_GetVersionInfo(VersionInfo)                           \
    do                                                             \
    {                                                              \
        (VersionInfo)->vendorID = PDUR_VENDOR_ID;                  \
        (VersionInfo)->moduleID = PDUR_MODULE_ID;                  \
        (VersionInfo)->sw_major_version = PDUR_H_SW_MAJOR_VERSION; \
        (VersionInfo)->sw_minor_version = PDUR_H_SW_MINOR_VERSION; \
        (VersionInfo)->sw_patch_version = PDUR_H_SW_PATCH_VERSION; \
    } while (0)
#endif
#endif

extern FUNC(void, PDUR_CODE) PduR_Init(P2CONST(PduR_PBConfigType, AUTOMATIC, PDUR_CONST_PBCFG) ConfigPtr);

extern FUNC(PduR_PBConfigIdType, PDUR_CODE) PduR_GetConfigurationId(void);

extern FUNC(void, PDUR_CODE) PduR_EnableRouting(PduR_RoutingPathGroupIdType id);

extern FUNC(void, PDUR_CODE) PduR_DisableRouting(PduR_RoutingPathGroupIdType id, boolean initialize);

extern FUNC(Std_ReturnType, PDUR_CODE)
    PduR_Transmit(PduIdType id, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info);

extern FUNC(Std_ReturnType, PDUR_CODE) PduR_CancelTransmit(PduIdType id);

extern FUNC(Std_ReturnType, PDUR_CODE) PduR_ChangeParameter(PduIdType id, TPParameterType parameter, uint16 value);

extern FUNC(Std_ReturnType, PDUR_CODE) PduR_CancelReceive(PduIdType id);

extern FUNC(void, PDUR_CODE)
    PduR_IfRxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr);

extern FUNC(void, PDUR_CODE) PduR_IfTxConfirmation(PduIdType TxPduId);

extern FUNC(Std_ReturnType, PDUR_CODE)
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    PduR_IfTriggerTransmit(PduIdType TxPduId, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr);
/* PRQA S 3432 -- */ /* MISRA Rule 20.7 */

extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_TpStartOfReception(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    PduLengthType TpSduLength,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr);
/* PRQA S 3432 -- */ /* MISRA Rule 20.7 */

extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_TpCopyRxData(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr);
/* PRQA S 3432 -- */ /* MISRA Rule 20.7 */

extern FUNC(void, PDUR_CODE) PduR_TpRxIndication(PduIdType id, Std_ReturnType result);

extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_TpCopyTxData(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2CONST(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr);
/* PRQA S 3432 -- */ /* MISRA Rule 20.7 */

extern FUNC(void, PDUR_CODE) PduR_TpTxConfirmation(PduIdType id, Std_ReturnType result);

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
/*PduR PB Configuration Run Time point parameter*/
extern P2CONST(PduR_PBConfigType, PDUR_VAR, PDUR_CONST) PduR_ConfigStd;
/*define in PduR_PBcfg.c*/
extern CONST(PduR_PBConfigType, PDUR_CONST_PBCFG) PduR_PBConfigData;

#endif /*STD_OFF == PDUR_ZERO_COST_OPERATION*/

#endif /* end of PDUR_H */
/*******************************************************************************
**                      End Of File                                           **
*******************************************************************************/
