
/**
 *
 * Copyright (C) iSOFT   (2022)
 *
 * All rights reserved.
 *
 * This document contains proprietary information belonging to iSOFT.Passing on and copying of this document, and
 * communication of its contents is not permitted without prior written authorization.
 *
 *
 *  @file               : ComM_Gent.c
 *  @version            : V1.0.0
 *  @author             : darren.zhang
 *  @date               : 2024/01/09 14:46:00
 *  @vendor             : isoft
 *  @description        : Communication Manager
 *  @specification(s)   : AUTOSAR classic Platform R19-11
 */

/*=================================================[inclusions]=======================================================*/
#include "Std_Types.h"
#include "ComM_Types.h"
#include "ComM_Gent.h"
/*============================================[external date declarations]============================================*/

BEGIN_C_DECLS
/*==========================================[external function definitions]===========================================*/

FUNC(void, COMM_CODE) ComM_ChProcessTimer(uint8 chIdx);

END_C_DECLS
/*==========================================[external function definitions]===========================================*/
#define COMM_START_SEC_CODE
#include "ComM_MemMap.h"
FUNC(void, COMM_CODE) ComM_MainFunction_Channel_CANFD3(void){  /* PRQA S 1532 */ /* MISRA Rule 8.7 */
    ComM_ChProcessTimer(0);
}
FUNC(void, COMM_CODE) ComM_MainFunction_Channel_CANFD4(void){  /* PRQA S 1532 */ /* MISRA Rule 8.7 */
    ComM_ChProcessTimer(1);
}
FUNC(void, COMM_CODE) ComM_MainFunction_Channel_CANFD5(void){  /* PRQA S 1532 */ /* MISRA Rule 8.7 */
    ComM_ChProcessTimer(2);
}
FUNC(void, COMM_CODE) ComM_MainFunction_Channel_CANFD6(void){  /* PRQA S 1532 */ /* MISRA Rule 8.7 */
    ComM_ChProcessTimer(3);
}
FUNC(void, COMM_CODE) ComM_MainFunction_Channel_CANFD7(void){  /* PRQA S 1532 */ /* MISRA Rule 8.7 */
    ComM_ChProcessTimer(4);
}
FUNC(void, COMM_CODE) ComM_MainFunction_Channel_CANFD8(void){  /* PRQA S 1532 */ /* MISRA Rule 8.7 */
    ComM_ChProcessTimer(5);
}
FUNC(void, COMM_CODE) ComM_MainFunction_ComMChannel_CCU_LIN1(void){  /* PRQA S 1532 */ /* MISRA Rule 8.7 */
    ComM_ChProcessTimer(6);
}
FUNC(void, COMM_CODE) ComM_MainFunction_ComMChannel_CCU_LIN2(void){  /* PRQA S 1532 */ /* MISRA Rule 8.7 */
    ComM_ChProcessTimer(7);
}
FUNC(void, COMM_CODE) ComM_MainFunction_ComMChannel_CCU_LIN3(void){  /* PRQA S 1532 */ /* MISRA Rule 8.7 */
    ComM_ChProcessTimer(8);
}
#define COMM_STOP_SEC_CODE
#include "ComM_MemMap.h"

