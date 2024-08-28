/*
 * CanIf_DiagRoute.h
 *
 *  Created on: 2023.1.13
 *      Author: Henry
 */

#ifndef COMMUNICATION_CAN_CANIF_CANIF_DIAGROUTE_H_
#define COMMUNICATION_CAN_CANIF_CANIF_DIAGROUTE_H_

#include "CanIf.h"

#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
extern FUNC(void, CANIF_CODE) CanIf_DiagPduRoute(
    uint32 id,
    PduIdType pduIdIndex,
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr);


extern uint16 DCM_Active_Timer;
extern uint8 DCM_Req_ComM_Flag;
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"

#endif /* COMMUNICATION_CAN_CANIF_CANIF_DIAGROUTE_H_ */
