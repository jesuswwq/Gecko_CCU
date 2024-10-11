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
**  FILENAME    : LinIf_Cfg.c                                                 **
**                                                                            **
**  Created on  : 2024/01/09 15:48:55                                 **
**  Author      : HuRongbo                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : Configuration parameter of LinIf                            **
**                                                                            **
**  SPECIFICATION(S) :  AUTOSAR  classic  Platform  R19-11                    **
**                                                                            **
*******************************************************************************/
#include "LinIf_Types.h"
#if (LINIF_TP_SUPPORTED == STD_ON)
#include "LinTp_Types.h"
#endif
#include "LinSM_Cbk.h"
#include "PduR_LinIf.h"
#include "EcuM.h"
#include "LinIf_Cfg.h"
#include "Com_Cfg.h"
#include "Lin.h"

#define LINIF_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#include "LinIf_MemMap.h"
static VAR(boolean, LINIF_VAR) LinIf_TransmitPendingData[48] = {0};
#define LINIF_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#include "LinIf_MemMap.h"

#define LINIF_START_SEC_CONST_UNSPECIFIED
#include "LinIf_MemMap.h"

CONST(LinIf_TxPduType, LINIF_CONST) LinIf_TxPduData[] =
{

    {
        PduR_LinIfTxConfirmation,  /* LinIfTxConfirmationUL */
        LINIF_TXPDU_HP_EXV_Cmd_LIN1,  /* LinIfTxPduId */
        PduR_LinIfTriggerTransmit, /* LinIfTxTriggerTransmitUL */
        LINIF_UL_PDUR,             /* LinIfUserTxUL */
        PDUR_DESTPDU_HP_EXV_Cmd_LIN1   ,     /* LinIfTxPduRef */
        FALSE                       /* LinIfContainResponseErrorSignal */
    },

    {
        PduR_LinIfTxConfirmation,  /* LinIfTxConfirmationUL */
        LINIF_TXPDU_BAT_EXV_Cmd_LIN1,  /* LinIfTxPduId */
        PduR_LinIfTriggerTransmit, /* LinIfTxTriggerTransmitUL */
        LINIF_UL_PDUR,             /* LinIfUserTxUL */
        PDUR_DESTPDU_BAT_EXV_Cmd_LIN1   ,     /* LinIfTxPduRef */
        FALSE                       /* LinIfContainResponseErrorSignal */
    },

    {
        PduR_LinIfTxConfirmation,  /* LinIfTxConfirmationUL */
        LINIF_TXPDU_AC_EXV_Cmd_LIN1,  /* LinIfTxPduId */
        PduR_LinIfTriggerTransmit, /* LinIfTxTriggerTransmitUL */
        LINIF_UL_PDUR,             /* LinIfUserTxUL */
        PDUR_DESTPDU_AC_EXV_Cmd_LIN1   ,     /* LinIfTxPduRef */
        FALSE                       /* LinIfContainResponseErrorSignal */
    },

    {
        PduR_LinIfTxConfirmation,  /* LinIfTxConfirmationUL */
        LINIF_TXPDU_MCV_Cmd_LIN1,  /* LinIfTxPduId */
        PduR_LinIfTriggerTransmit, /* LinIfTxTriggerTransmitUL */
        LINIF_UL_PDUR,             /* LinIfUserTxUL */
        PDUR_DESTPDU_MCV_Cmd_LIN1   ,     /* LinIfTxPduRef */
        FALSE                       /* LinIfContainResponseErrorSignal */
    },

    {
        PduR_LinIfTxConfirmation,  /* LinIfTxConfirmationUL */
        LINIF_TXPDU_BCV_Cmd_LIN1,  /* LinIfTxPduId */
        PduR_LinIfTriggerTransmit, /* LinIfTxTriggerTransmitUL */
        LINIF_UL_PDUR,             /* LinIfUserTxUL */
        PDUR_DESTPDU_BCV_Cmd_LIN1   ,     /* LinIfTxPduRef */
        FALSE                       /* LinIfContainResponseErrorSignal */
    },

    {
        PduR_LinIfTxConfirmation,  /* LinIfTxConfirmationUL */
        LINIF_TXPDU_PMP_Cmd_LIN1,  /* LinIfTxPduId */
        PduR_LinIfTriggerTransmit, /* LinIfTxTriggerTransmitUL */
        LINIF_UL_PDUR,             /* LinIfUserTxUL */
        PDUR_DESTPDU_PMP_Cmd_LIN1   ,     /* LinIfTxPduRef */
        FALSE                       /* LinIfContainResponseErrorSignal */
    },

    {
        PduR_LinIfTxConfirmation,  /* LinIfTxConfirmationUL */
        LINIF_TXPDU_AC_EXV_Cmd_LIN2,  /* LinIfTxPduId */
        PduR_LinIfTriggerTransmit, /* LinIfTxTriggerTransmitUL */
        LINIF_UL_PDUR,             /* LinIfUserTxUL */
        PDUR_DESTPDU_AC_EXV_Cmd_LIN2   ,     /* LinIfTxPduRef */
        FALSE                       /* LinIfContainResponseErrorSignal */
    },

    {
        PduR_LinIfTxConfirmation,  /* LinIfTxConfirmationUL */
        LINIF_TXPDU_BAT_EXV_Cmd_LIN2,  /* LinIfTxPduId */
        PduR_LinIfTriggerTransmit, /* LinIfTxTriggerTransmitUL */
        LINIF_UL_PDUR,             /* LinIfUserTxUL */
        PDUR_DESTPDU_BAT_EXV_Cmd_LIN2   ,     /* LinIfTxPduRef */
        FALSE                       /* LinIfContainResponseErrorSignal */
    },

    {
        PduR_LinIfTxConfirmation,  /* LinIfTxConfirmationUL */
        LINIF_TXPDU_C3WV_Cmd_LIN2,  /* LinIfTxPduId */
        PduR_LinIfTriggerTransmit, /* LinIfTxTriggerTransmitUL */
        LINIF_UL_PDUR,             /* LinIfUserTxUL */
        PDUR_DESTPDU_C3WV_Cmd_LIN2   ,     /* LinIfTxPduRef */
        FALSE                       /* LinIfContainResponseErrorSignal */
    },

    {
        PduR_LinIfTxConfirmation,  /* LinIfTxConfirmationUL */
        LINIF_TXPDU_C5WV_Cmd_LIN2,  /* LinIfTxPduId */
        PduR_LinIfTriggerTransmit, /* LinIfTxTriggerTransmitUL */
        LINIF_UL_PDUR,             /* LinIfUserTxUL */
        PDUR_DESTPDU_C5WV_Cmd_LIN2   ,     /* LinIfTxPduRef */
        FALSE                       /* LinIfContainResponseErrorSignal */
    },

    {
        PduR_LinIfTxConfirmation,  /* LinIfTxConfirmationUL */
        LINIF_TXPDU_HP_EXV_Cmd_LIN2,  /* LinIfTxPduId */
        PduR_LinIfTriggerTransmit, /* LinIfTxTriggerTransmitUL */
        LINIF_UL_PDUR,             /* LinIfUserTxUL */
        PDUR_DESTPDU_HP_EXV_Cmd_LIN2   ,     /* LinIfTxPduRef */
        FALSE                       /* LinIfContainResponseErrorSignal */
    },

    {
        PduR_LinIfTxConfirmation,  /* LinIfTxConfirmationUL */
        LINIF_TXPDU_PMP_Cmd_LIN2,  /* LinIfTxPduId */
        PduR_LinIfTriggerTransmit, /* LinIfTxTriggerTransmitUL */
        LINIF_UL_PDUR,             /* LinIfUserTxUL */
        PDUR_DESTPDU_PMP_Cmd_LIN2   ,     /* LinIfTxPduRef */
        FALSE                       /* LinIfContainResponseErrorSignal */
    },

    {
        PduR_LinIfTxConfirmation,  /* LinIfTxConfirmationUL */
        LINIF_TXPDU_CCU_FCLCommand_LIN3,  /* LinIfTxPduId */
        PduR_LinIfTriggerTransmit, /* LinIfTxTriggerTransmitUL */
        LINIF_UL_PDUR,             /* LinIfUserTxUL */
        PDUR_DESTPDU_CCU_FCLCommand_LIN3   ,     /* LinIfTxPduRef */
        FALSE                       /* LinIfContainResponseErrorSignal */
    },

    {
        PduR_LinIfTxConfirmation,  /* LinIfTxConfirmationUL */
        LINIF_TXPDU_Frm_VehicleToInterlock_LIN3,  /* LinIfTxPduId */
        PduR_LinIfTriggerTransmit, /* LinIfTxTriggerTransmitUL */
        LINIF_UL_PDUR,             /* LinIfUserTxUL */
        PDUR_DESTPDU_Frm_VehicleToInterlock_LIN3   ,     /* LinIfTxPduRef */
        FALSE                       /* LinIfContainResponseErrorSignal */
    }
};

CONST(LinIf_RxPduType, LINIF_CONST) LinIf_RxPduData[] =
{
    {
        PduR_LinIfRxIndication, /* LinIfRxIndicationUL */
        LINIF_UL_PDUR,          /* LinIfUserRxIndicationUL */
        PDUR_SRCPDU_HP_EXV__Rsp_LIN1                      /* LinIfRxPduRef */
    },
    {
        PduR_LinIfRxIndication, /* LinIfRxIndicationUL */
        LINIF_UL_PDUR,          /* LinIfUserRxIndicationUL */
        PDUR_SRCPDU_BAT_EXV_Rsp_LIN1                      /* LinIfRxPduRef */
    },
    {
        PduR_LinIfRxIndication, /* LinIfRxIndicationUL */
        LINIF_UL_PDUR,          /* LinIfUserRxIndicationUL */
        PDUR_SRCPDU_AC_EXV_Rsp_LIN1                      /* LinIfRxPduRef */
    },
    {
        PduR_LinIfRxIndication, /* LinIfRxIndicationUL */
        LINIF_UL_PDUR,          /* LinIfUserRxIndicationUL */
        PDUR_SRCPDU_MCV_Sts_LIN1                      /* LinIfRxPduRef */
    },
    {
        PduR_LinIfRxIndication, /* LinIfRxIndicationUL */
        LINIF_UL_PDUR,          /* LinIfUserRxIndicationUL */
        PDUR_SRCPDU_BCV_Sts_LIN1                      /* LinIfRxPduRef */
    },
    {
        PduR_LinIfRxIndication, /* LinIfRxIndicationUL */
        LINIF_UL_PDUR,          /* LinIfUserRxIndicationUL */
        PDUR_SRCPDU_MotPMP_Sts_LIN1                      /* LinIfRxPduRef */
    },
    {
        PduR_LinIfRxIndication, /* LinIfRxIndicationUL */
        LINIF_UL_PDUR,          /* LinIfUserRxIndicationUL */
        PDUR_SRCPDU_BatPMP_Sts_LIN1                      /* LinIfRxPduRef */
    },
    {
        PduR_LinIfRxIndication, /* LinIfRxIndicationUL */
        LINIF_UL_PDUR,          /* LinIfUserRxIndicationUL */
        PDUR_SRCPDU_AcPMP_Sts_LIN1                      /* LinIfRxPduRef */
    },
    {
        PduR_LinIfRxIndication, /* LinIfRxIndicationUL */
        LINIF_UL_PDUR,          /* LinIfUserRxIndicationUL */
        PDUR_SRCPDU_HP_EXV_Version_LIN1                      /* LinIfRxPduRef */
    },
    {
        PduR_LinIfRxIndication, /* LinIfRxIndicationUL */
        LINIF_UL_PDUR,          /* LinIfUserRxIndicationUL */
        PDUR_SRCPDU_Bat_EXV_Version_LIN1                      /* LinIfRxPduRef */
    },
    {
        PduR_LinIfRxIndication, /* LinIfRxIndicationUL */
        LINIF_UL_PDUR,          /* LinIfUserRxIndicationUL */
        PDUR_SRCPDU_MCV_Version_LIN1                      /* LinIfRxPduRef */
    },
    {
        PduR_LinIfRxIndication, /* LinIfRxIndicationUL */
        LINIF_UL_PDUR,          /* LinIfUserRxIndicationUL */
        PDUR_SRCPDU_BCV_Version_LIN1                      /* LinIfRxPduRef */
    },
    {
        PduR_LinIfRxIndication, /* LinIfRxIndicationUL */
        LINIF_UL_PDUR,          /* LinIfUserRxIndicationUL */
        PDUR_SRCPDU_AcPMP_Version_LIN1                      /* LinIfRxPduRef */
    },
    {
        PduR_LinIfRxIndication, /* LinIfRxIndicationUL */
        LINIF_UL_PDUR,          /* LinIfUserRxIndicationUL */
        PDUR_SRCPDU_AC_EXV_Rsp_LIN2                      /* LinIfRxPduRef */
    },
    {
        PduR_LinIfRxIndication, /* LinIfRxIndicationUL */
        LINIF_UL_PDUR,          /* LinIfUserRxIndicationUL */
        PDUR_SRCPDU_AcPMP_Sts_LIN2                      /* LinIfRxPduRef */
    },
    {
        PduR_LinIfRxIndication, /* LinIfRxIndicationUL */
        LINIF_UL_PDUR,          /* LinIfUserRxIndicationUL */
        PDUR_SRCPDU_AcPMP_Version_LIN2                      /* LinIfRxPduRef */
    },
    {
        PduR_LinIfRxIndication, /* LinIfRxIndicationUL */
        LINIF_UL_PDUR,          /* LinIfUserRxIndicationUL */
        PDUR_SRCPDU_BAT_EXV_Rsp_LIN2                      /* LinIfRxPduRef */
    },
    {
        PduR_LinIfRxIndication, /* LinIfRxIndicationUL */
        LINIF_UL_PDUR,          /* LinIfUserRxIndicationUL */
        PDUR_SRCPDU_BatPMP_Sts_LIN2                      /* LinIfRxPduRef */
    },
    {
        PduR_LinIfRxIndication, /* LinIfRxIndicationUL */
        LINIF_UL_PDUR,          /* LinIfUserRxIndicationUL */
        PDUR_SRCPDU_Bat_EXV_Version_LIN2                      /* LinIfRxPduRef */
    },
    {
        PduR_LinIfRxIndication, /* LinIfRxIndicationUL */
        LINIF_UL_PDUR,          /* LinIfUserRxIndicationUL */
        PDUR_SRCPDU_C3WV_Sts_LIN2                      /* LinIfRxPduRef */
    },
    {
        PduR_LinIfRxIndication, /* LinIfRxIndicationUL */
        LINIF_UL_PDUR,          /* LinIfUserRxIndicationUL */
        PDUR_SRCPDU_C5WV_Sts_LIN2                      /* LinIfRxPduRef */
    },
    {
        PduR_LinIfRxIndication, /* LinIfRxIndicationUL */
        LINIF_UL_PDUR,          /* LinIfUserRxIndicationUL */
        PDUR_SRCPDU_HP_EXV_Rsp_LIN2                      /* LinIfRxPduRef */
    },
    {
        PduR_LinIfRxIndication, /* LinIfRxIndicationUL */
        LINIF_UL_PDUR,          /* LinIfUserRxIndicationUL */
        PDUR_SRCPDU_HP_EXV_Version_LIN2                      /* LinIfRxPduRef */
    },
    {
        PduR_LinIfRxIndication, /* LinIfRxIndicationUL */
        LINIF_UL_PDUR,          /* LinIfUserRxIndicationUL */
        PDUR_SRCPDU_MotPMP_Sts_LIN2                      /* LinIfRxPduRef */
    },
    {
        PduR_LinIfRxIndication, /* LinIfRxIndicationUL */
        LINIF_UL_PDUR,          /* LinIfUserRxIndicationUL */
        PDUR_SRCPDU_FCLL_Status_LIN3                      /* LinIfRxPduRef */
    },
    {
        PduR_LinIfRxIndication, /* LinIfRxIndicationUL */
        LINIF_UL_PDUR,          /* LinIfUserRxIndicationUL */
        PDUR_SRCPDU_FCLR_Status_LIN3                      /* LinIfRxPduRef */
    },
    {
        PduR_LinIfRxIndication, /* LinIfRxIndicationUL */
        LINIF_UL_PDUR,          /* LinIfUserRxIndicationUL */
        PDUR_SRCPDU_Frm_InterlockStatus_LIN3                      /* LinIfRxPduRef */
    },
    {
        PduR_LinIfRxIndication, /* LinIfRxIndicationUL */
        LINIF_UL_PDUR,          /* LinIfUserRxIndicationUL */
        PDUR_SRCPDU_Frm_InterlockToVehicle_LIN3                      /* LinIfRxPduRef */
    }
};

CONST(LinIf_PduDirectionType, LINIF_CONST) LinIf_PduDirectionData[] =
{
    /* index 0 */
    {
        LINIF_TX_PDU,        /* LinIfPduDirectionId */

        NULL_PTR,            /* LinIfRxPdu */

        &LinIf_TxPduData[0]             /* LinIfTxPdu */
    },
    /* index 1 */
    {
        LINIF_RX_PDU,        /* LinIfPduDirectionId */

        &LinIf_RxPduData[0],            /* LinIfRxPdu */

        NULL_PTR             /* LinIfTxPdu */
    },
    /* index 2 */
    {
        LINIF_TX_PDU,        /* LinIfPduDirectionId */

        NULL_PTR,            /* LinIfRxPdu */

        &LinIf_TxPduData[1]             /* LinIfTxPdu */
    },
    /* index 3 */
    {
        LINIF_RX_PDU,        /* LinIfPduDirectionId */

        &LinIf_RxPduData[1],            /* LinIfRxPdu */

        NULL_PTR             /* LinIfTxPdu */
    },
    /* index 4 */
    {
        LINIF_TX_PDU,        /* LinIfPduDirectionId */

        NULL_PTR,            /* LinIfRxPdu */

        &LinIf_TxPduData[2]             /* LinIfTxPdu */
    },
    /* index 5 */
    {
        LINIF_RX_PDU,        /* LinIfPduDirectionId */

        &LinIf_RxPduData[2],            /* LinIfRxPdu */

        NULL_PTR             /* LinIfTxPdu */
    },
    /* index 6 */
    {
        LINIF_TX_PDU,        /* LinIfPduDirectionId */

        NULL_PTR,            /* LinIfRxPdu */

        &LinIf_TxPduData[3]             /* LinIfTxPdu */
    },
    /* index 7 */
    {
        LINIF_RX_PDU,        /* LinIfPduDirectionId */

        &LinIf_RxPduData[3],            /* LinIfRxPdu */

        NULL_PTR             /* LinIfTxPdu */
    },
    /* index 8 */
    {
        LINIF_TX_PDU,        /* LinIfPduDirectionId */

        NULL_PTR,            /* LinIfRxPdu */

        &LinIf_TxPduData[4]             /* LinIfTxPdu */
    },
    /* index 9 */
    {
        LINIF_RX_PDU,        /* LinIfPduDirectionId */

        &LinIf_RxPduData[4],            /* LinIfRxPdu */

        NULL_PTR             /* LinIfTxPdu */
    },
    /* index 10 */
    {
        LINIF_TX_PDU,        /* LinIfPduDirectionId */

        NULL_PTR,            /* LinIfRxPdu */

        &LinIf_TxPduData[5]             /* LinIfTxPdu */
    },
    /* index 11 */
    {
        LINIF_RX_PDU,        /* LinIfPduDirectionId */

        &LinIf_RxPduData[5],            /* LinIfRxPdu */

        NULL_PTR             /* LinIfTxPdu */
    },
    /* index 12 */
    {
        LINIF_RX_PDU,        /* LinIfPduDirectionId */

        &LinIf_RxPduData[6],            /* LinIfRxPdu */

        NULL_PTR             /* LinIfTxPdu */
    },
    /* index 13 */
    {
        LINIF_RX_PDU,        /* LinIfPduDirectionId */

        &LinIf_RxPduData[7],            /* LinIfRxPdu */

        NULL_PTR             /* LinIfTxPdu */
    },
    /* index 14 */
    {
        LINIF_RX_PDU,        /* LinIfPduDirectionId */

        &LinIf_RxPduData[8],            /* LinIfRxPdu */

        NULL_PTR             /* LinIfTxPdu */
    },
    /* index 15 */
    {
        LINIF_RX_PDU,        /* LinIfPduDirectionId */

        &LinIf_RxPduData[9],            /* LinIfRxPdu */

        NULL_PTR             /* LinIfTxPdu */
    },
    /* index 16 */
    {
        LINIF_RX_PDU,        /* LinIfPduDirectionId */

        &LinIf_RxPduData[10],            /* LinIfRxPdu */

        NULL_PTR             /* LinIfTxPdu */
    },
    /* index 17 */
    {
        LINIF_RX_PDU,        /* LinIfPduDirectionId */

        &LinIf_RxPduData[11],            /* LinIfRxPdu */

        NULL_PTR             /* LinIfTxPdu */
    },
    /* index 18 */
    {
        LINIF_RX_PDU,        /* LinIfPduDirectionId */

        &LinIf_RxPduData[12],            /* LinIfRxPdu */

        NULL_PTR             /* LinIfTxPdu */
    },
    /* index 19 */
    {
        LINIF_TX_PDU,        /* LinIfPduDirectionId */

        NULL_PTR,            /* LinIfRxPdu */

        NULL_PTR             /* LinIfTxPdu */
    },
    /* index 20 */
    {
        LINIF_RX_PDU,        /* LinIfPduDirectionId */

        NULL_PTR,            /* LinIfRxPdu */

        NULL_PTR             /* LinIfTxPdu */
    },
    /* index 21 */
    {
        LINIF_TX_PDU,        /* LinIfPduDirectionId */

        NULL_PTR,            /* LinIfRxPdu */

        &LinIf_TxPduData[6]             /* LinIfTxPdu */
    },
    /* index 22 */
    {
        LINIF_RX_PDU,        /* LinIfPduDirectionId */

        &LinIf_RxPduData[13],            /* LinIfRxPdu */

        NULL_PTR             /* LinIfTxPdu */
    },
    /* index 23 */
    {
        LINIF_RX_PDU,        /* LinIfPduDirectionId */

        &LinIf_RxPduData[14],            /* LinIfRxPdu */

        NULL_PTR             /* LinIfTxPdu */
    },
    /* index 24 */
    {
        LINIF_RX_PDU,        /* LinIfPduDirectionId */

        &LinIf_RxPduData[15],            /* LinIfRxPdu */

        NULL_PTR             /* LinIfTxPdu */
    },
    /* index 25 */
    {
        LINIF_TX_PDU,        /* LinIfPduDirectionId */

        NULL_PTR,            /* LinIfRxPdu */

        &LinIf_TxPduData[7]             /* LinIfTxPdu */
    },
    /* index 26 */
    {
        LINIF_RX_PDU,        /* LinIfPduDirectionId */

        &LinIf_RxPduData[16],            /* LinIfRxPdu */

        NULL_PTR             /* LinIfTxPdu */
    },
    /* index 27 */
    {
        LINIF_RX_PDU,        /* LinIfPduDirectionId */

        &LinIf_RxPduData[17],            /* LinIfRxPdu */

        NULL_PTR             /* LinIfTxPdu */
    },
    /* index 28 */
    {
        LINIF_RX_PDU,        /* LinIfPduDirectionId */

        &LinIf_RxPduData[18],            /* LinIfRxPdu */

        NULL_PTR             /* LinIfTxPdu */
    },
    /* index 29 */
    {
        LINIF_TX_PDU,        /* LinIfPduDirectionId */

        NULL_PTR,            /* LinIfRxPdu */

        &LinIf_TxPduData[8]             /* LinIfTxPdu */
    },
    /* index 30 */
    {
        LINIF_RX_PDU,        /* LinIfPduDirectionId */

        &LinIf_RxPduData[19],            /* LinIfRxPdu */

        NULL_PTR             /* LinIfTxPdu */
    },
    /* index 31 */
    {
        LINIF_TX_PDU,        /* LinIfPduDirectionId */

        NULL_PTR,            /* LinIfRxPdu */

        &LinIf_TxPduData[9]             /* LinIfTxPdu */
    },
    /* index 32 */
    {
        LINIF_RX_PDU,        /* LinIfPduDirectionId */

        &LinIf_RxPduData[20],            /* LinIfRxPdu */

        NULL_PTR             /* LinIfTxPdu */
    },
    /* index 33 */
    {
        LINIF_TX_PDU,        /* LinIfPduDirectionId */

        NULL_PTR,            /* LinIfRxPdu */

        &LinIf_TxPduData[10]             /* LinIfTxPdu */
    },
    /* index 34 */
    {
        LINIF_RX_PDU,        /* LinIfPduDirectionId */

        &LinIf_RxPduData[21],            /* LinIfRxPdu */

        NULL_PTR             /* LinIfTxPdu */
    },
    /* index 35 */
    {
        LINIF_RX_PDU,        /* LinIfPduDirectionId */

        &LinIf_RxPduData[22],            /* LinIfRxPdu */

        NULL_PTR             /* LinIfTxPdu */
    },
    /* index 36 */
    {
        LINIF_RX_PDU,        /* LinIfPduDirectionId */

        &LinIf_RxPduData[23],            /* LinIfRxPdu */

        NULL_PTR             /* LinIfTxPdu */
    },
    /* index 37 */
    {
        LINIF_TX_PDU,        /* LinIfPduDirectionId */

        NULL_PTR,            /* LinIfRxPdu */

        &LinIf_TxPduData[11]             /* LinIfTxPdu */
    },
    /* index 38 */
    {
        LINIF_TX_PDU,        /* LinIfPduDirectionId */

        NULL_PTR,            /* LinIfRxPdu */

        NULL_PTR             /* LinIfTxPdu */
    },
    /* index 39 */
    {
        LINIF_RX_PDU,        /* LinIfPduDirectionId */

        NULL_PTR,            /* LinIfRxPdu */

        NULL_PTR             /* LinIfTxPdu */
    },
    /* index 40 */
    {
        LINIF_TX_PDU,        /* LinIfPduDirectionId */

        NULL_PTR,            /* LinIfRxPdu */

        &LinIf_TxPduData[12]             /* LinIfTxPdu */
    },
    /* index 41 */
    {
        LINIF_RX_PDU,        /* LinIfPduDirectionId */

        &LinIf_RxPduData[24],            /* LinIfRxPdu */

        NULL_PTR             /* LinIfTxPdu */
    },
    /* index 42 */
    {
        LINIF_RX_PDU,        /* LinIfPduDirectionId */

        &LinIf_RxPduData[25],            /* LinIfRxPdu */

        NULL_PTR             /* LinIfTxPdu */
    },
    /* index 43 */
    {
        LINIF_RX_PDU,        /* LinIfPduDirectionId */

        &LinIf_RxPduData[26],            /* LinIfRxPdu */

        NULL_PTR             /* LinIfTxPdu */
    },
    /* index 44 */
    {
        LINIF_RX_PDU,        /* LinIfPduDirectionId */

        &LinIf_RxPduData[27],            /* LinIfRxPdu */

        NULL_PTR             /* LinIfTxPdu */
    },
    /* index 45 */
    {
        LINIF_TX_PDU,        /* LinIfPduDirectionId */

        NULL_PTR,            /* LinIfRxPdu */

        &LinIf_TxPduData[13]             /* LinIfTxPdu */
    },
    /* index 46 */
    {
        LINIF_TX_PDU,        /* LinIfPduDirectionId */

        NULL_PTR,            /* LinIfRxPdu */

        NULL_PTR             /* LinIfTxPdu */
    },
    /* index 47 */
    {
        LINIF_RX_PDU,        /* LinIfPduDirectionId */

        NULL_PTR,            /* LinIfRxPdu */

        NULL_PTR             /* LinIfTxPdu */
    }
};

CONST(LinIf_FrameType, LINIF_CONST) LinIf_FrameData[] =
{
  /* index 0 */
  {
    LINIF_ENHANCED,             /* LinIfChecksumType */
    0xc,                       /* LinIfFrameId  */
    0x4c,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[0], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[0] /* LinIfIsTransmitPending */
  },
  /* index 1 */
  {
    LINIF_ENHANCED,             /* LinIfChecksumType */
    0x1c,                       /* LinIfFrameId  */
    0x9c,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[1], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[1] /* LinIfIsTransmitPending */
  },
  /* index 2 */
  {
    LINIF_ENHANCED,             /* LinIfChecksumType */
    0x34,                       /* LinIfFrameId  */
    0xb4,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[2], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[2] /* LinIfIsTransmitPending */
  },
  /* index 3 */
  {
    LINIF_ENHANCED,             /* LinIfChecksumType */
    0x35,                       /* LinIfFrameId  */
    0xf5,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[3], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[3] /* LinIfIsTransmitPending */
  },
  /* index 4 */
  {
    LINIF_ENHANCED,             /* LinIfChecksumType */
    0x12,                       /* LinIfFrameId  */
    0x92,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[4], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[4] /* LinIfIsTransmitPending */
  },
  /* index 5 */
  {
    LINIF_ENHANCED,             /* LinIfChecksumType */
    0x22,                       /* LinIfFrameId  */
    0xe2,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[5], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[5] /* LinIfIsTransmitPending */
  },
  /* index 6 */
  {
    LINIF_ENHANCED,             /* LinIfChecksumType */
    0x8,                       /* LinIfFrameId  */
    0x8,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[6], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[6] /* LinIfIsTransmitPending */
  },
  /* index 7 */
  {
    LINIF_ENHANCED,             /* LinIfChecksumType */
    0x19,                       /* LinIfFrameId  */
    0x99,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[7], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[7] /* LinIfIsTransmitPending */
  },
  /* index 8 */
  {
    LINIF_ENHANCED,             /* LinIfChecksumType */
    0x9,                       /* LinIfFrameId  */
    0x49,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[8], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[8] /* LinIfIsTransmitPending */
  },
  /* index 9 */
  {
    LINIF_ENHANCED,             /* LinIfChecksumType */
    0x13,                       /* LinIfFrameId  */
    0xd3,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[9], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[9] /* LinIfIsTransmitPending */
  },
  /* index 10 */
  {
    LINIF_ENHANCED,             /* LinIfChecksumType */
    0x24,                       /* LinIfFrameId  */
    0x64,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[10], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[10] /* LinIfIsTransmitPending */
  },
  /* index 11 */
  {
    LINIF_ENHANCED,             /* LinIfChecksumType */
    0x27,                       /* LinIfFrameId  */
    0xe7,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[11], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[11] /* LinIfIsTransmitPending */
  },
  /* index 12 */
  {
    LINIF_ENHANCED,             /* LinIfChecksumType */
    0x26,                       /* LinIfFrameId  */
    0xa6,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[12], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[12] /* LinIfIsTransmitPending */
  },
  /* index 13 */
  {
    LINIF_ENHANCED,             /* LinIfChecksumType */
    0x14,                       /* LinIfFrameId  */
    0x14,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[13], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[13] /* LinIfIsTransmitPending */
  },
  /* index 14 */
  {
    LINIF_ENHANCED,             /* LinIfChecksumType */
    0x11,                       /* LinIfFrameId  */
    0x11,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[14], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[14] /* LinIfIsTransmitPending */
  },
  /* index 15 */
  {
    LINIF_ENHANCED,             /* LinIfChecksumType */
    0xe,                       /* LinIfFrameId  */
    0x8e,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[15], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[15] /* LinIfIsTransmitPending */
  },
  /* index 16 */
  {
    LINIF_ENHANCED,             /* LinIfChecksumType */
    0x5,                       /* LinIfFrameId  */
    0x85,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[16], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[16] /* LinIfIsTransmitPending */
  },
  /* index 17 */
  {
    LINIF_ENHANCED,             /* LinIfChecksumType */
    0x6,                       /* LinIfFrameId  */
    0x6,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[17], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[17] /* LinIfIsTransmitPending */
  },
  /* index 18 */
  {
    LINIF_ENHANCED,             /* LinIfChecksumType */
    0xd,                       /* LinIfFrameId  */
    0xd,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[18], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[18] /* LinIfIsTransmitPending */
  },
  /* index 19 */
  {
    LINIF_CLASSIC,             /* LinIfChecksumType */
    0x3c,                       /* LinIfFrameId  */
    0x3c,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_MRF,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[19], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[19] /* LinIfIsTransmitPending */
  },
  /* index 20 */
  {
    LINIF_CLASSIC,             /* LinIfChecksumType */
    0x3d,                       /* LinIfFrameId  */
    0x7d,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_SRF,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[20], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[20] /* LinIfIsTransmitPending */
  },
  /* index 21 */
  {
    LINIF_ENHANCED,             /* LinIfChecksumType */
    0x12,                       /* LinIfFrameId  */
    0x92,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[21], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[21] /* LinIfIsTransmitPending */
  },
  /* index 22 */
  {
    LINIF_ENHANCED,             /* LinIfChecksumType */
    0x22,                       /* LinIfFrameId  */
    0xe2,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[22], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[22] /* LinIfIsTransmitPending */
  },
  /* index 23 */
  {
    LINIF_ENHANCED,             /* LinIfChecksumType */
    0x14,                       /* LinIfFrameId  */
    0x14,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[23], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[23] /* LinIfIsTransmitPending */
  },
  /* index 24 */
  {
    LINIF_ENHANCED,             /* LinIfChecksumType */
    0xd,                       /* LinIfFrameId  */
    0xd,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[24], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[24] /* LinIfIsTransmitPending */
  },
  /* index 25 */
  {
    LINIF_ENHANCED,             /* LinIfChecksumType */
    0x34,                       /* LinIfFrameId  */
    0xb4,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[25], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[25] /* LinIfIsTransmitPending */
  },
  /* index 26 */
  {
    LINIF_ENHANCED,             /* LinIfChecksumType */
    0x35,                       /* LinIfFrameId  */
    0xf5,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[26], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[26] /* LinIfIsTransmitPending */
  },
  /* index 27 */
  {
    LINIF_ENHANCED,             /* LinIfChecksumType */
    0x26,                       /* LinIfFrameId  */
    0xa6,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[27], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[27] /* LinIfIsTransmitPending */
  },
  /* index 28 */
  {
    LINIF_ENHANCED,             /* LinIfChecksumType */
    0xe,                       /* LinIfFrameId  */
    0x8e,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[28], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[28] /* LinIfIsTransmitPending */
  },
  /* index 29 */
  {
    LINIF_ENHANCED,             /* LinIfChecksumType */
    0x33,                       /* LinIfFrameId  */
    0x73,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[29], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[29] /* LinIfIsTransmitPending */
  },
  /* index 30 */
  {
    LINIF_ENHANCED,             /* LinIfChecksumType */
    0x9,                       /* LinIfFrameId  */
    0x49,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[30], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[30] /* LinIfIsTransmitPending */
  },
  /* index 31 */
  {
    LINIF_ENHANCED,             /* LinIfChecksumType */
    0x8,                       /* LinIfFrameId  */
    0x8,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[31], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[31] /* LinIfIsTransmitPending */
  },
  /* index 32 */
  {
    LINIF_ENHANCED,             /* LinIfChecksumType */
    0x19,                       /* LinIfFrameId  */
    0x99,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[32], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[32] /* LinIfIsTransmitPending */
  },
  /* index 33 */
  {
    LINIF_ENHANCED,             /* LinIfChecksumType */
    0xc,                       /* LinIfFrameId  */
    0x4c,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[33], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[33] /* LinIfIsTransmitPending */
  },
  /* index 34 */
  {
    LINIF_ENHANCED,             /* LinIfChecksumType */
    0x1c,                       /* LinIfFrameId  */
    0x9c,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[34], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[34] /* LinIfIsTransmitPending */
  },
  /* index 35 */
  {
    LINIF_ENHANCED,             /* LinIfChecksumType */
    0x11,                       /* LinIfFrameId  */
    0x11,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[35], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[35] /* LinIfIsTransmitPending */
  },
  /* index 36 */
  {
    LINIF_ENHANCED,             /* LinIfChecksumType */
    0x27,                       /* LinIfFrameId  */
    0xe7,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[36], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[36] /* LinIfIsTransmitPending */
  },
  /* index 37 */
  {
    LINIF_ENHANCED,             /* LinIfChecksumType */
    0x24,                       /* LinIfFrameId  */
    0x64,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[37], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[37] /* LinIfIsTransmitPending */
  },
  /* index 38 */
  {
    LINIF_CLASSIC,             /* LinIfChecksumType */
    0x3c,                       /* LinIfFrameId  */
    0x3c,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_MRF,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[38], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[38] /* LinIfIsTransmitPending */
  },
  /* index 39 */
  {
    LINIF_CLASSIC,             /* LinIfChecksumType */
    0x3d,                       /* LinIfFrameId  */
    0x7d,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_SRF,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[39], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[39] /* LinIfIsTransmitPending */
  },
  /* index 40 */
  {
    LINIF_ENHANCED,             /* LinIfChecksumType */
    0x2a,                       /* LinIfFrameId  */
    0x6a,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[40], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[40] /* LinIfIsTransmitPending */
  },
  /* index 41 */
  {
    LINIF_ENHANCED,             /* LinIfChecksumType */
    0x2c,                       /* LinIfFrameId  */
    0xec,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    4,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[41], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[41] /* LinIfIsTransmitPending */
  },
  /* index 42 */
  {
    LINIF_ENHANCED,             /* LinIfChecksumType */
    0x2e,                       /* LinIfFrameId  */
    0x2e,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    4,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[42], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[42] /* LinIfIsTransmitPending */
  },
  /* index 43 */
  {
    LINIF_ENHANCED,             /* LinIfChecksumType */
    0x39,                       /* LinIfFrameId  */
    0x39,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    4,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[43], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[43] /* LinIfIsTransmitPending */
  },
  /* index 44 */
  {
    LINIF_ENHANCED,             /* LinIfChecksumType */
    0x3b,                       /* LinIfFrameId  */
    0xfb,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[44], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[44] /* LinIfIsTransmitPending */
  },
  /* index 45 */
  {
    LINIF_ENHANCED,             /* LinIfChecksumType */
    0x3a,                       /* LinIfFrameId  */
    0xba,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_UNCONDITIONAL,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[45], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[45] /* LinIfIsTransmitPending */
  },
  /* index 46 */
  {
    LINIF_CLASSIC,             /* LinIfChecksumType */
    0x3c,                       /* LinIfFrameId  */
    0x3c,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_MRF,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[46], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[46] /* LinIfIsTransmitPending */
  },
  /* index 47 */
  {
    LINIF_CLASSIC,             /* LinIfChecksumType */
    0x3d,                       /* LinIfFrameId  */
    0x7d,                       /* LinIfProtectedId */
    255,                            /* LinIfFrameIndex */
    8,                          /* LinIfLength */
    LINIF_SRF,        /* LinIfFrameType */
    NULL_PTR,                   /* LinIfFixedFrameSdu */
    &LinIf_PduDirectionData[47], /* LinIfPduDirection */
    0,                          /* LinIfNumOfSubstitutionFrame */
    NULL_PTR,                    /* LinIfSubstitutionFrames */
    &LinIf_TransmitPendingData[47] /* LinIfIsTransmitPending */
  }
};

CONST(LinIf_EntryType, LINIF_CONST) LinIf_EntryData[] =
{
  {
    4,  /* LinIfDelay */
    0,  /* LinIfEntryIndex */
    0,  /* LinIfCollisionResolvingRef */
    0   /* LinIfFrameRef */
  },
  {
    4,  /* LinIfDelay */
    1,  /* LinIfEntryIndex */
    0,  /* LinIfCollisionResolvingRef */
    2   /* LinIfFrameRef */
  },
  {
    4,  /* LinIfDelay */
    2,  /* LinIfEntryIndex */
    0,  /* LinIfCollisionResolvingRef */
    4   /* LinIfFrameRef */
  },
  {
    4,  /* LinIfDelay */
    3,  /* LinIfEntryIndex */
    0,  /* LinIfCollisionResolvingRef */
    6   /* LinIfFrameRef */
  },
  {
    4,  /* LinIfDelay */
    4,  /* LinIfEntryIndex */
    0,  /* LinIfCollisionResolvingRef */
    8   /* LinIfFrameRef */
  },
  {
    4,  /* LinIfDelay */
    5,  /* LinIfEntryIndex */
    0,  /* LinIfCollisionResolvingRef */
    10   /* LinIfFrameRef */
  },
  {
    4,  /* LinIfDelay */
    6,  /* LinIfEntryIndex */
    0,  /* LinIfCollisionResolvingRef */
    1   /* LinIfFrameRef */
  },
  {
    4,  /* LinIfDelay */
    7,  /* LinIfEntryIndex */
    0,  /* LinIfCollisionResolvingRef */
    3   /* LinIfFrameRef */
  },
  {
    4,  /* LinIfDelay */
    8,  /* LinIfEntryIndex */
    0,  /* LinIfCollisionResolvingRef */
    5   /* LinIfFrameRef */
  },
  {
    4,  /* LinIfDelay */
    9,  /* LinIfEntryIndex */
    0,  /* LinIfCollisionResolvingRef */
    7   /* LinIfFrameRef */
  },
  {
    4,  /* LinIfDelay */
    10,  /* LinIfEntryIndex */
    0,  /* LinIfCollisionResolvingRef */
    9   /* LinIfFrameRef */
  },
  {
    4,  /* LinIfDelay */
    11,  /* LinIfEntryIndex */
    0,  /* LinIfCollisionResolvingRef */
    11   /* LinIfFrameRef */
  },
  {
    4,  /* LinIfDelay */
    12,  /* LinIfEntryIndex */
    0,  /* LinIfCollisionResolvingRef */
    12   /* LinIfFrameRef */
  },
  {
    4,  /* LinIfDelay */
    13,  /* LinIfEntryIndex */
    0,  /* LinIfCollisionResolvingRef */
    13   /* LinIfFrameRef */
  },
  {
    4,  /* LinIfDelay */
    14,  /* LinIfEntryIndex */
    0,  /* LinIfCollisionResolvingRef */
    14   /* LinIfFrameRef */
  },
  {
    4,  /* LinIfDelay */
    15,  /* LinIfEntryIndex */
    0,  /* LinIfCollisionResolvingRef */
    15   /* LinIfFrameRef */
  },
  {
    4,  /* LinIfDelay */
    16,  /* LinIfEntryIndex */
    0,  /* LinIfCollisionResolvingRef */
    16   /* LinIfFrameRef */
  },
  {
    4,  /* LinIfDelay */
    17,  /* LinIfEntryIndex */
    0,  /* LinIfCollisionResolvingRef */
    17   /* LinIfFrameRef */
  },
  {
    4,  /* LinIfDelay */
    18,  /* LinIfEntryIndex */
    0,  /* LinIfCollisionResolvingRef */
    18   /* LinIfFrameRef */
  },
  {
    4,  /* LinIfDelay */
    19,  /* LinIfEntryIndex */
    0,  /* LinIfCollisionResolvingRef */
    33   /* LinIfFrameRef */
  },
  {
    4,  /* LinIfDelay */
    20,  /* LinIfEntryIndex */
    0,  /* LinIfCollisionResolvingRef */
    25   /* LinIfFrameRef */
  },
  {
    4,  /* LinIfDelay */
    21,  /* LinIfEntryIndex */
    0,  /* LinIfCollisionResolvingRef */
    21   /* LinIfFrameRef */
  },
  {
    4,  /* LinIfDelay */
    22,  /* LinIfEntryIndex */
    0,  /* LinIfCollisionResolvingRef */
    29   /* LinIfFrameRef */
  },
  {
    4,  /* LinIfDelay */
    23,  /* LinIfEntryIndex */
    0,  /* LinIfCollisionResolvingRef */
    31   /* LinIfFrameRef */
  },
  {
    4,  /* LinIfDelay */
    24,  /* LinIfEntryIndex */
    0,  /* LinIfCollisionResolvingRef */
    37   /* LinIfFrameRef */
  },
  {
    4,  /* LinIfDelay */
    25,  /* LinIfEntryIndex */
    0,  /* LinIfCollisionResolvingRef */
    34   /* LinIfFrameRef */
  },
  {
    4,  /* LinIfDelay */
    26,  /* LinIfEntryIndex */
    0,  /* LinIfCollisionResolvingRef */
    26   /* LinIfFrameRef */
  },
  {
    4,  /* LinIfDelay */
    27,  /* LinIfEntryIndex */
    0,  /* LinIfCollisionResolvingRef */
    22   /* LinIfFrameRef */
  },
  {
    4,  /* LinIfDelay */
    28,  /* LinIfEntryIndex */
    0,  /* LinIfCollisionResolvingRef */
    30   /* LinIfFrameRef */
  },
  {
    4,  /* LinIfDelay */
    29,  /* LinIfEntryIndex */
    0,  /* LinIfCollisionResolvingRef */
    32   /* LinIfFrameRef */
  },
  {
    4,  /* LinIfDelay */
    30,  /* LinIfEntryIndex */
    0,  /* LinIfCollisionResolvingRef */
    36   /* LinIfFrameRef */
  },
  {
    4,  /* LinIfDelay */
    31,  /* LinIfEntryIndex */
    0,  /* LinIfCollisionResolvingRef */
    27   /* LinIfFrameRef */
  },
  {
    4,  /* LinIfDelay */
    32,  /* LinIfEntryIndex */
    0,  /* LinIfCollisionResolvingRef */
    23   /* LinIfFrameRef */
  },
  {
    4,  /* LinIfDelay */
    33,  /* LinIfEntryIndex */
    0,  /* LinIfCollisionResolvingRef */
    35   /* LinIfFrameRef */
  },
  {
    4,  /* LinIfDelay */
    34,  /* LinIfEntryIndex */
    0,  /* LinIfCollisionResolvingRef */
    28   /* LinIfFrameRef */
  },
  {
    4,  /* LinIfDelay */
    35,  /* LinIfEntryIndex */
    0,  /* LinIfCollisionResolvingRef */
    24   /* LinIfFrameRef */
  },
  {
    2,  /* LinIfDelay */
    36,  /* LinIfEntryIndex */
    0,  /* LinIfCollisionResolvingRef */
    40   /* LinIfFrameRef */
  },
  {
    3,  /* LinIfDelay */
    37,  /* LinIfEntryIndex */
    0,  /* LinIfCollisionResolvingRef */
    41   /* LinIfFrameRef */
  },
  {
    2,  /* LinIfDelay */
    38,  /* LinIfEntryIndex */
    0,  /* LinIfCollisionResolvingRef */
    40   /* LinIfFrameRef */
  },
  {
    3,  /* LinIfDelay */
    39,  /* LinIfEntryIndex */
    0,  /* LinIfCollisionResolvingRef */
    42   /* LinIfFrameRef */
  },
  {
    2,  /* LinIfDelay */
    40,  /* LinIfEntryIndex */
    0,  /* LinIfCollisionResolvingRef */
    40   /* LinIfFrameRef */
  },
  {
    3,  /* LinIfDelay */
    41,  /* LinIfEntryIndex */
    0,  /* LinIfCollisionResolvingRef */
    44   /* LinIfFrameRef */
  },
  {
    2,  /* LinIfDelay */
    42,  /* LinIfEntryIndex */
    0,  /* LinIfCollisionResolvingRef */
    40   /* LinIfFrameRef */
  },
  {
    3,  /* LinIfDelay */
    43,  /* LinIfEntryIndex */
    0,  /* LinIfCollisionResolvingRef */
    45   /* LinIfFrameRef */
  },
  {
    2,  /* LinIfDelay */
    44,  /* LinIfEntryIndex */
    0,  /* LinIfCollisionResolvingRef */
    40   /* LinIfFrameRef */
  },
  {
    3,  /* LinIfDelay */
    45,  /* LinIfEntryIndex */
    0,  /* LinIfCollisionResolvingRef */
    43   /* LinIfFrameRef */
  }
};

CONST(LinIf_ScheduleTableType, LINIF_CONST) LinIf_ScheduleTableData[] =
{
  /* NULL SCHEDULE */
  {
    LINIF_START_FROM_BEGINNING, /* LinIfResumePosition */
    LINIF_RUN_ONCE,             /* LinIfRunMode */
    LINIF_NULL_SCHEDULE_INDEX,  /* LinIfScheduleTableIndex */
    NULL_PTR,                   /* LinIfEntry */
    0                           /* LinIfNumOfEntry */
  },
  {
    LINIF_START_FROM_BEGINNING, /* LinIfResumePosition */
    LINIF_RUN_CONTINUOUS,             /* LinIfRunMode */
    LinIfScheduleTable_Schedule1_LIN1,       /* LinIfScheduleTableIndex */
    &LinIf_EntryData[0],                   /* LinIfEntry */
    14                           /* LinIfNumOfEntry */
  },
  {
    LINIF_START_FROM_BEGINNING, /* LinIfResumePosition */
    LINIF_RUN_CONTINUOUS,             /* LinIfRunMode */
    LinIfScheduleTable_Schedule2_LIN1,       /* LinIfScheduleTableIndex */
    &LinIf_EntryData[14],                   /* LinIfEntry */
    5                           /* LinIfNumOfEntry */
  },
  {
    LINIF_START_FROM_BEGINNING, /* LinIfResumePosition */
    LINIF_RUN_CONTINUOUS,             /* LinIfRunMode */
    LinIfScheduleTable_Schedule1_LIN2,       /* LinIfScheduleTableIndex */
    &LinIf_EntryData[19],                   /* LinIfEntry */
    14                           /* LinIfNumOfEntry */
  },
  {
    LINIF_START_FROM_BEGINNING, /* LinIfResumePosition */
    LINIF_RUN_CONTINUOUS,             /* LinIfRunMode */
    LinIfScheduleTable_Schedule2_LIN2,       /* LinIfScheduleTableIndex */
    &LinIf_EntryData[33],                   /* LinIfEntry */
    3                           /* LinIfNumOfEntry */
  },
  {
    LINIF_START_FROM_BEGINNING, /* LinIfResumePosition */
    LINIF_RUN_CONTINUOUS,             /* LinIfRunMode */
    LinIfScheduleTable_Schedule1_LIN3,       /* LinIfScheduleTableIndex */
    &LinIf_EntryData[36],                   /* LinIfEntry */
    10                           /* LinIfNumOfEntry */
  }
};

CONST(LinIf_LinDriverChannelRef, LINIF_CONST) LinIf_LinDriverChannelRefData[] =
{
    {
        0,                   /* LinChannelIdRef */
        0,                   /* LinDriverId */
        0  /* WakeUpSource */
    },
    {
        1,                   /* LinChannelIdRef */
        1,                   /* LinDriverId */
        0  /* WakeUpSource */
    },
    {
        2,                   /* LinChannelIdRef */
        2,                   /* LinDriverId */
        0  /* WakeUpSource */
    }
};
CONST(LinIf_MasterType, LINIF_CONST) LinIf_MasterData[] =
{
    {
        0 /* LinIfJitter */
    },
    {
        0 /* LinIfJitter */
    },
    {
        0 /* LinIfJitter */
    }
};
CONST(LinIf_NodeType, LINIF_CONST) LinIf_NodeTypeData[] =
{
    {
    LINIF_MASTER,                   /* LinIfNodeType */
    &LinIf_MasterData[0],       /* LinIfMaster */
    NULL_PTR                        /* LinIfSlave */
    },
    {
    LINIF_MASTER,                   /* LinIfNodeType */
    &LinIf_MasterData[1],       /* LinIfMaster */
    NULL_PTR                        /* LinIfSlave */
    },
    {
    LINIF_MASTER,                   /* LinIfNodeType */
    &LinIf_MasterData[2],       /* LinIfMaster */
    NULL_PTR                        /* LinIfSlave */
    }
};

CONST(LinIf_ChannelType, LINIF_CONST) LinIf_ChannelData[LINIF_NUMBER_OF_CHANNELS] =
{
  {
    4000u,                                 /* LinIfBusIdleTimeoutPeriod */
    LINIF_UL_LINSM,                     /* LinIfGotoSleepConfirmationUL */
    LinSM_GotoSleepConfirmation,        /* GotoSleepConfirmation */
    LINIF_UL_LINSM,                     /* LinIfGotoSleepIndicationUL */
    NULL_PTR,        /* GotoSleepIndication */
    0,                                /* LinIfMaxFrameCnt */
    FALSE,                               /* LinIfScheduleChangeNextTimeBase */
    LINIF_UL_LINSM,                     /* LinIfScheduleRequestConfirmationUL */
    LinSM_ScheduleRequestConfirmation,  /* ScheduleRequestConfirmation */
    LINIF_STARTUP_SLEEP,               /* LinIfStartupState */
    LINIF_UL_LINSM,                     /* LinIfWakeupConfirmationUL */
    LinSM_WakeupConfirmation,           /* WakeupConfirmation */
    &LinIf_LinDriverChannelRefData[0],  /* LinIfChannelRef */
    6,                                  /* LinIfComMNetworkHandleRef */
    21,                                  /* LinIfNumOfFrame */
    0,                                  /* LinIfFrameIndexOffset */
    &LinIf_FrameData[0],                /* LinIfFrame */
    &LinIf_NodeTypeData[0],               /* LinIfNodeType */
    2,                                  /* LinIfNumOfSchedule */
    1,                                  /* LinIfScheduleIndexOffset */
    &LinIf_ScheduleTableData[1],        /* LinIfScheduleTable */
    NULL_PTR                            /* LinIfTransceiverDrvConfig */
  },
  {
    4000u,                                 /* LinIfBusIdleTimeoutPeriod */
    LINIF_UL_LINSM,                     /* LinIfGotoSleepConfirmationUL */
    LinSM_GotoSleepConfirmation,        /* GotoSleepConfirmation */
    LINIF_UL_LINSM,                     /* LinIfGotoSleepIndicationUL */
    NULL_PTR,        /* GotoSleepIndication */
    0,                                /* LinIfMaxFrameCnt */
    FALSE,                               /* LinIfScheduleChangeNextTimeBase */
    LINIF_UL_LINSM,                     /* LinIfScheduleRequestConfirmationUL */
    LinSM_ScheduleRequestConfirmation,  /* ScheduleRequestConfirmation */
    LINIF_STARTUP_SLEEP,               /* LinIfStartupState */
    LINIF_UL_LINSM,                     /* LinIfWakeupConfirmationUL */
    LinSM_WakeupConfirmation,           /* WakeupConfirmation */
    &LinIf_LinDriverChannelRefData[1],  /* LinIfChannelRef */
    7,                                  /* LinIfComMNetworkHandleRef */
    19,                                  /* LinIfNumOfFrame */
    21,                                  /* LinIfFrameIndexOffset */
    &LinIf_FrameData[21],                /* LinIfFrame */
    &LinIf_NodeTypeData[1],               /* LinIfNodeType */
    2,                                  /* LinIfNumOfSchedule */
    3,                                  /* LinIfScheduleIndexOffset */
    &LinIf_ScheduleTableData[3],        /* LinIfScheduleTable */
    NULL_PTR                            /* LinIfTransceiverDrvConfig */
  },
  {
    4000u,                                 /* LinIfBusIdleTimeoutPeriod */
    LINIF_UL_LINSM,                     /* LinIfGotoSleepConfirmationUL */
    LinSM_GotoSleepConfirmation,        /* GotoSleepConfirmation */
    LINIF_UL_LINSM,                     /* LinIfGotoSleepIndicationUL */
    NULL_PTR,        /* GotoSleepIndication */
    0,                                /* LinIfMaxFrameCnt */
    FALSE,                               /* LinIfScheduleChangeNextTimeBase */
    LINIF_UL_LINSM,                     /* LinIfScheduleRequestConfirmationUL */
    LinSM_ScheduleRequestConfirmation,  /* ScheduleRequestConfirmation */
    LINIF_STARTUP_SLEEP,               /* LinIfStartupState */
    LINIF_UL_LINSM,                     /* LinIfWakeupConfirmationUL */
    LinSM_WakeupConfirmation,           /* WakeupConfirmation */
    &LinIf_LinDriverChannelRefData[2],  /* LinIfChannelRef */
    8,                                  /* LinIfComMNetworkHandleRef */
    8,                                  /* LinIfNumOfFrame */
    40,                                  /* LinIfFrameIndexOffset */
    &LinIf_FrameData[40],                /* LinIfFrame */
    &LinIf_NodeTypeData[2],               /* LinIfNodeType */
    1,                                  /* LinIfNumOfSchedule */
    5,                                  /* LinIfScheduleIndexOffset */
    &LinIf_ScheduleTableData[5],        /* LinIfScheduleTable */
    NULL_PTR                            /* LinIfTransceiverDrvConfig */
  }
};

CONST(LinIf_ConfigType, LINIF_CONST) LinIf_PCConfig =
{
  5,                                   /* LinIfTimeBase */
  0,                                    /* LinIfNumOfSubstitution */
  NULL_PTR,                             /* LinIfSubstitution */
  17,                                    /* LinIfNumOfTxPdu */
  LinIf_TxPduData,                      /* LinIfTxPdu */
  LinIf_FrameData,                      /* LinIfFrame */
  LinIf_ChannelData                     /* LinIfChannel */
};

CONST(Lin_DriverApiType, LINIF_CONST) Lin_DriverApi[LINIF_NUMBER_OF_DRIVERS] =
{
    {
        Lin_GetStatus,            /* LinGetStatus */
        Lin_GoToSleep,             /* LinGoToSleep */
        Lin_GoToSleepInternal,    /* LinGoToSleepInternal */
        Lin_SendFrame,               /* LinSendFrame */
        Lin_Wakeup,               /* LinWakeup */
        Lin_WakeupInternal,       /* LinWakeupInternal */
        Lin_CheckWakeup     /* LinCheckWakeup */
    },
    {
        Lin_GetStatus,            /* LinGetStatus */
        Lin_GoToSleep,             /* LinGoToSleep */
        Lin_GoToSleepInternal,    /* LinGoToSleepInternal */
        Lin_SendFrame,               /* LinSendFrame */
        Lin_Wakeup,               /* LinWakeup */
        Lin_WakeupInternal,       /* LinWakeupInternal */
        Lin_CheckWakeup     /* LinCheckWakeup */
    },
    {
        Lin_GetStatus,            /* LinGetStatus */
        Lin_GoToSleep,             /* LinGoToSleep */
        Lin_GoToSleepInternal,    /* LinGoToSleepInternal */
        Lin_SendFrame,               /* LinSendFrame */
        Lin_Wakeup,               /* LinWakeup */
        Lin_WakeupInternal,       /* LinWakeupInternal */
        Lin_CheckWakeup     /* LinCheckWakeup */
    }
};

#define LINIF_STOP_SEC_CONST_UNSPECIFIED
#include "LinIf_MemMap.h"
