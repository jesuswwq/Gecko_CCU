
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
**  FILENAME    : PduR_Cfg.h                                                  **
**                                                                            **
**  Created on  : 2023/11/23 14:59:01                                         **
**  Author      : long.zhu                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : Configuration parameter of PDUR                             **
**                                                                            **
**  SPECIFICATION(S) :   NONE                                                 **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/** <VERSION>   <DATE>     <AUTHOR>          <REVISION LOG>
 *  V1.0.0      20230818   long.zhu          Initial Version
 */

#ifndef  PDUR_CFG_H
#define  PDUR_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Dcm.h"
#include "CanTp.h"

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

#define PDUR_CANTP_TX_PDU_ID             0x0u

#define PDUR_CANTP_RX_PHY_PDU_ID         0x0u

#define PDUR_CANTP_RX_FUNC_PDU_ID        0x1u


#define PDUR_CANTP_FD_TX_PDU_ID             0x1u

#define PDUR_CANTP_FD_RX_PHY_PDU_ID         0x2u

#define PDUR_CANTP_FD_RX_FUNC_PDU_ID        0x3u

/* reference to CanTp_TxSdu->txDcmId */
#define PDUR_DCM_TX_PDU_ID               PDUR_CANTP_TX_PDU_ID

/* reference to CanTp_RxSdu->rxDcmId */
#define PDUR_DCM_RX_PHY_PDU_ID           PDUR_CANTP_RX_PHY_PDU_ID

/* reference to CanTp_RxSdu->rxDcmId */
#define PDUR_DCM_RX_FUNC_PDU_ID          PDUR_CANTP_RX_FUNC_PDU_ID

/* reference to CanTp_TxSdu->txDcmId */
#define PDUR_DCM_OTA_TX_PDU_ID               PDUR_CANTP_FD_TX_PDU_ID

/* reference to CanTp_RxSdu->rxDcmId */
#define PDUR_DCM_OTA_RX_PHY_PDU_ID           PDUR_CANTP_FD_RX_PHY_PDU_ID

/* reference to CanTp_RxSdu->rxDcmId */
#define PDUR_DCM_OTA_RX_FUNC_PDU_ID          PDUR_CANTP_FD_RX_FUNC_PDU_ID


/*Current bus mode.*/
#define BL_BUS_MODE                      BL_BUS_MODE_CAN
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
#define PduR_ProvideRxBuffer            Dcm_ProvideRxBuffer

#define PduR_RxIndication               Dcm_RxIndication

#define PduR_ProvideTxBuffer            Dcm_ProvideTxBuffer

#define PduR_TxConfirmation             Dcm_TxConfirmation

#define PduR_Service_RxFinish           Dcm_Service_RxFinish

#define PduR_StartP3cTimer              Dcm_StartP3cTimer

#define PduR_TpTransmit                 CanTp_Transmit

#endif  /* end of PDUR_CFG_H */

