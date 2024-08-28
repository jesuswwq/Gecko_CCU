#ifndef BSWM_CHECK_ACTION_H
#define BSWM_CHECK_ACTION_H

#include "ComStack_Types.h"

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
//#include "BswM_Internal.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
void Cycle_HW_NM_Check(void);
void Cycle_ComM_Manage(void);
void NM_UserDataPackup(void);
void HW_NM_Check_BeforeRTC(void);

#define BSWM_TEST 0U

extern uint8 NM_Sleep_Counter;
extern uint8 ComM_Req_NO_ComM;
extern uint8 ComM_Request_Flag;
extern NetworkHandleType Nm_Rx_NetWorkID;
extern uint8 CCUWakeupReturnValue;
extern uint8 App_ComMReqFlag;
extern uint8 HW_Active_ComReq;
extern uint16 HW_Trigger_Timer;
extern uint16 RTC_Timer;
extern uint8 FirstWakeUpSource500ms;
extern uint8 FirstNMFlag;
extern uint8 ActiveNMReqFlag;


typedef struct {
    uint8  used;
    uint32 ReadResult;   /**< pointer to the SDU (i.e.  *    payload data) of the PDU */
}TCA9539TrigerType;
typedef struct {
    TCA9539TrigerType  TCA9539Triger[2];
    uint8 new;   /**< pointer to the SDU (i.e.  *    payload data) of the PDU */
}TCA9539SumTrigerType;
extern uint32 TCA9539SumTrigerReadResult;
#endif
