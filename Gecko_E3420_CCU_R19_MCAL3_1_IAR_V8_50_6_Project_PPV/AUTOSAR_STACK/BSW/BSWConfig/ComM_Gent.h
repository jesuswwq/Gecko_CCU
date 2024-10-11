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
 *  @file               : ComM_Gent.h
 *  @version            : V1.0.0
 *  @author             : darren.zhang
 *  @date               : 2024/01/09 14:46:00
 *  @vendor             : isoft
 *  @description        : Communication Manager
 *  @specification(s)   : AUTOSAR classic Platform R19-11
 */

/*=================================================[inclusions]=======================================================*/
#ifndef COMM_GENT_H_
#define COMM_GENT_H_

/*========================================[external function declarations]============================================*/

BEGIN_C_DECLS

FUNC(void, COMM_CODE) ComM_MainFunction_Channel_CANFD3(void);

FUNC(void, COMM_CODE) ComM_MainFunction_Channel_CANFD4(void);

FUNC(void, COMM_CODE) ComM_MainFunction_Channel_CANFD5(void);

FUNC(void, COMM_CODE) ComM_MainFunction_Channel_CANFD6(void);

FUNC(void, COMM_CODE) ComM_MainFunction_Channel_CANFD7(void);

FUNC(void, COMM_CODE) ComM_MainFunction_Channel_CANFD8(void);

FUNC(void, COMM_CODE) ComM_MainFunction_ComMChannel_CCU_LIN1(void);

FUNC(void, COMM_CODE) ComM_MainFunction_ComMChannel_CCU_LIN2(void);

FUNC(void, COMM_CODE) ComM_MainFunction_ComMChannel_CCU_LIN3(void);

END_C_DECLS

#endif/* COMM_GENT_H_ */

