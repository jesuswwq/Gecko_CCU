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
 *  @file               : SchM_ComM.h
 *  @version            : V1.0.0
 *  @author             : darren.zhang
 *  @date               : 2022/01/07
 *  @vendor             : isoft
 *  @description        : Communication Manager
 *  @specification(s)   : AUTOSAR classic Platform R19-11
 *
 */
#ifndef SCHM_COMM_H_
#define SCHM_COMM_H_

#include "Os.h"
#include "ComM_Gent.h"

/* base lock ComM_MainFunction() */
#if !defined(SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_0)
#define SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_0()
#endif /* !defined(SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_0) */

#if !defined(SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_0)
#define SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_0()
#endif /* !defined(SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_0) */

/* base lock local Sender-Receiver var */
#if !defined(SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_1)
#define SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_1()
#endif /* !defined(SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_0) */

#if !defined(SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_1)
#define SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_1()
#endif /* !defined(SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_0) */

#endif /* SCHM_COMM_H_ */
