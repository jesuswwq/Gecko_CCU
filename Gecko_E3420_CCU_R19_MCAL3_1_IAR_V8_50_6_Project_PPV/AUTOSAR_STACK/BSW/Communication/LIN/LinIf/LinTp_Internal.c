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
**  FILENAME    : LinIf_Internal.c                                            **
**                                                                            **
**  Created on  :                                                             **
**  Author      : HuRongbo                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/* <VERSION>   <DATE>     <AUTHOR>   <REVISION LOG>
 * V2.0.0      20200721   HuRongbo   Initial version
 * V2.0.1      20201117   HuRongbo   Fix bug when receive broadcast NAD return
 *                                   NULL_PTR
 * V2.0.2      20211123   HuRongbo   Fix bug when config functional NAD receive
 *                                   any NAD
 * V2.0.3      20220711   HuRongbo   QAC check issue fix
 */
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "LinIf_Cfg.h"
#if (LINIF_TP_SUPPORTED == STD_ON)
#include "LinTp_Types.h"
#include "LinTp_Internal.h"
#include "LinIf_Internal.h"
#include "LinIf_Slave.h"
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

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define LINIF_START_SEC_CODE
#include "LinIf_MemMap.h"
/******************************************************************************/
/*
 * Brief: Gets the configuration pointer by receive 'NAD'
 * Param-Name[in]: ch: LinIf channel
 *                 Nad: received 'NAD'
 * Param-Name[out]: None
 * Param-Name[in/out]: None
 * Return: const LinTp_RxNSduType*
 * PreCondition: None
 * CallByAPI: This is a internal function
 */
/******************************************************************************/
FUNC(P2CONST(LinTp_RxNSduType, AUTOMATIC, LINIF_APPL_CONST), LINIF_CODE)
LinTp_GetRxNSduByNad(NetworkHandleType ch, uint8 Nad)
{
    P2CONST(LinTp_RxNSduType, AUTOMATIC, LINIF_CONST) rxNSdu = &LINTP_GET_RXNSDU(0u);
    P2CONST(LinTp_RxNSduType, AUTOMATIC, LINIF_CONST) retRxNSdu = NULL_PTR;
    uint16 idx = LINTP_GET_RXNSDU_NUM;
    uint8 runtimeNad;
    boolean findFlag = FALSE;
    Std_ReturnType ret;

    while (idx > 0u)
    {
        if (rxNSdu->LinTpRxNSduChannelRef == LINIF_GET_COMM_NETWORK(ch))
        {
            if (((rxNSdu->LinTpRxNSduNad == LINTP_FUNCTIONAL_REQ_NAD)
                 || (rxNSdu->LinTpRxNSduNad == LINTP_BROADCAST_REQ_NAD))
                && (rxNSdu->LinTpRxNSduNad == Nad))
            {
                findFlag = TRUE;
            }
            else
            {
#if (STD_ON == LINIF_SLAVE_SUPPORT)
                if (LINIF_SLAVE == LINIF_GET_NODETYPE(ch))
                {
                    ret = LinIf_SlaveGetConfigedNAD(ch, &runtimeNad);
                    if ((E_OK == ret) && (runtimeNad == Nad))
                    {
                        findFlag = TRUE;
                    }
                }
                else
#endif /* STD_ON == LINIF_SLAVE_SUPPORT */
                {
                    if (rxNSdu->LinTpRxNSduNad == Nad)
                    {
                        findFlag = TRUE;
                    }
                }
            }

            if (TRUE == findFlag)
            {
                retRxNSdu = rxNSdu;
                break;
            }
        }

        idx--;
        rxNSdu++;
    }
    return retRxNSdu;
}

#define LINIF_STOP_SEC_CODE
#include "LinIf_MemMap.h"
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

#endif /* #if (LINIF_TP_SUPPORTED == STD_ON) */
