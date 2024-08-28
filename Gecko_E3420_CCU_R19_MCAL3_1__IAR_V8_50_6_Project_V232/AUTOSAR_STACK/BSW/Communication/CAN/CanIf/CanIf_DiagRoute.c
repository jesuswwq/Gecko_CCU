/*
 * CanIf_DiagRoute.c
 *
 *  Created on: 2023.1.13
 *      Author: Henry
 */
#include "CanIf_DiagRoute.h"
#include "Can.h"
#include "CanNm.h"
#include <string.h>

#define DIAG_CANID                0x00000700u

uint16 DCM_Active_Timer = 0;
uint8 DCM_Req_ComM_Flag = 0;
/*********************************************/


#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
FUNC(void, CANIF_CODE)
CanIf_DiagPduRoute(
	uint32 id,
    PduIdType pduIdIndex,
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr)
{

	if((id & DIAG_CANID) == DIAG_CANID)
	{
		if((NM_MODE_NETWORK == CanNm_ChRunTime[0].cannmMode)&&(NM_MODE_NETWORK == CanNm_ChRunTime[1].cannmMode)&&
		(NM_MODE_NETWORK == CanNm_ChRunTime[2].cannmMode)&&(NM_MODE_NETWORK == CanNm_ChRunTime[3].cannmMode))
		{
		DCM_Active_Timer = (5000/10);
		DCM_Req_ComM_Flag = 1;
	}
	}

    if(CANIF_RXPDU_CANIF_RX_Diag_FuncReq_OBD == pduIdIndex)
    {
		CanIf_Transmit(CANIF_TXPDU_CANIF_Diag_FuncReq_TX_CHA,PduInfoPtr);
		CanIf_Transmit(CANIF_TXPDU_CANIF_Diag_FuncReq_TX_BOD,PduInfoPtr);
		CanIf_Transmit(CANIF_TXPDU_CANIF_Diag_FuncReq_TX_EPT,PduInfoPtr);
		CanIf_Transmit(CANIF_TXPDU_CANIF_TX_Diag_FuncReq_BAC,PduInfoPtr);
    }

	if(CANIF_RXPDU_CANIF_RX_Diag_FuncReq_BAC == pduIdIndex)
    {
		CanIf_Transmit(CANIF_TXPDU_CANIF_Diag_FuncReq_TX_CHA,PduInfoPtr);
		CanIf_Transmit(CANIF_TXPDU_CANIF_Diag_FuncReq_TX_BOD,PduInfoPtr);
		CanIf_Transmit(CANIF_TXPDU_CANIF_Diag_FuncReq_TX_EPT,PduInfoPtr);
    }
}

#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
