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
 *  @file               : Rte_ComM_Type.h
 *  @version            : V2.1.1
 *  @author             : darren.zhang
 *  @date               : 2024/01/09 14:46:00 
 *  @vendor             : isoft
 *  @description        : Communication Manager
 *  @specification(s)   : AUTOSAR classic Platform R19-11
 */

#ifndef RTE_COMM_TYPE_H_
#define RTE_COMM_TYPE_H_
/*=================================================[inclusions]=======================================================*/
#include "Std_Types.h"

/*====================================================[macros]========================================================*/

#if !defined(RTE_COMM_TYPE_LOCAL)
#define RTE_COMM_TYPE_LOCAL 1
#endif /* !defined(RTE_COMM_TYPE_LOCAL) */

/*=============================================[type definitions]=====================================================*/
/** @ref SWS_ComM_00669 */
typedef uint8 ComM_InhibitionStatusType;
#if !defined(COMM_MASK_INHIBIT_WAKEUP)
#define COMM_MASK_INHIBIT_WAKEUP 0x1u
#endif /* !defined(COMM_MASK_INHIBIT_WAKEUP) */

#if !defined(COMM_MASK_LIMIT_TO_NOCOM)
#define COMM_MASK_LIMIT_TO_NOCOM 0x2u
#endif /* !defined(COMM_MASK_LIMIT_TO_NOCOM) */

/** @ref SWS_ComM_00672 */
typedef uint8 ComM_ModeType;
#if !defined(COMM_NO_COMMUNICATION)
#define COMM_NO_COMMUNICATION 0u
#endif /* !defined(COMM_NO_COMMUNICATION) */

#if !defined(COMM_SILENT_COMMUNICATION)
#define COMM_SILENT_COMMUNICATION 1u
#endif /* !defined(COMM_SILENT_COMMUNICATION) */

#if !defined(COMM_FULL_COMMUNICATION)
#define COMM_FULL_COMMUNICATION 2u
#endif /* !defined(COMM_FULL_COMMUNICATION) */

#if !defined(COMM_FULL_COMMUNICATION_WITH_WAKEUP_REQUEST)
#define COMM_FULL_COMMUNICATION_WITH_WAKEUP_REQUEST 3u
#endif /* !defined(COMM_FULL_COMMUNICATION_WITH_WAKEUP_REQUEST) */

/** \brief mode switch used types */
#if !defined(RTE_MODE_ComMMode_COMM_FULL_COMMUNICATION)
#define RTE_MODE_ComMMode_COMM_FULL_COMMUNICATION (0u)
#endif /* !defined(RTE_MODE_ComMMode_COMM_FULL_COMMUNICATION) */

#if !defined(RTE_MODE_ComMMode_COMM_NO_COMMUNICATION)
#define RTE_MODE_ComMMode_COMM_NO_COMMUNICATION (1U)
#endif /* !defined(RTE_MODE_ComMMode_COMM_NO_COMMUNICATION) */

#if !defined(RTE_MODE_ComMMode_COMM_SILENT_COMMUNICATION)
#define RTE_MODE_ComMMode_COMM_SILENT_COMMUNICATION (2U)
#endif /* !defined(RTE_MODE_ComMMode_COMM_SILENT_COMMUNICATION) */

/** @ref SWS_ComM_00670 */
typedef uint8 ComM_UserHandleType;

/** @ref SWS_ComM_01005 */


/** @ref SWS_ComM_01005 */
typedef uint8 ComM_UserHandleSubArrayType_Channel_CANFD3[1];

/** @ref SWS_ComM_00906 */
typedef struct{

    uint8 numberOfRequesters;
    ComM_UserHandleSubArrayType_Channel_CANFD3 handleArray;
}ComM_UserHandleArrayType_Channel_CANFD3;

/** @ref SWS_ComM_01005 */
typedef uint8 ComM_UserHandleSubArrayType_Channel_CANFD4[1];

/** @ref SWS_ComM_00906 */
typedef struct{

    uint8 numberOfRequesters;
    ComM_UserHandleSubArrayType_Channel_CANFD4 handleArray;
}ComM_UserHandleArrayType_Channel_CANFD4;

/** @ref SWS_ComM_01005 */
typedef uint8 ComM_UserHandleSubArrayType_Channel_CANFD5[1];

/** @ref SWS_ComM_00906 */
typedef struct{

    uint8 numberOfRequesters;
    ComM_UserHandleSubArrayType_Channel_CANFD5 handleArray;
}ComM_UserHandleArrayType_Channel_CANFD5;

/** @ref SWS_ComM_01005 */
typedef uint8 ComM_UserHandleSubArrayType_Channel_CANFD6[1];

/** @ref SWS_ComM_00906 */
typedef struct{

    uint8 numberOfRequesters;
    ComM_UserHandleSubArrayType_Channel_CANFD6 handleArray;
}ComM_UserHandleArrayType_Channel_CANFD6;

/** @ref SWS_ComM_01005 */
typedef uint8 ComM_UserHandleSubArrayType_Channel_CANFD7[1];

/** @ref SWS_ComM_00906 */
typedef struct{

    uint8 numberOfRequesters;
    ComM_UserHandleSubArrayType_Channel_CANFD7 handleArray;
}ComM_UserHandleArrayType_Channel_CANFD7;

/** @ref SWS_ComM_01005 */
typedef uint8 ComM_UserHandleSubArrayType_Channel_CANFD8[1];

/** @ref SWS_ComM_00906 */
typedef struct{

    uint8 numberOfRequesters;
    ComM_UserHandleSubArrayType_Channel_CANFD8 handleArray;
}ComM_UserHandleArrayType_Channel_CANFD8;

typedef uint8 ComM_UserHandleSubArrayType_ComMChannel_CCU_LIN1[1];

/** @ref SWS_ComM_00906 */
typedef struct{

    uint8 numberOfRequesters;
    ComM_UserHandleSubArrayType_ComMChannel_CCU_LIN1 handleArray;
}ComM_UserHandleArrayType_ComMChannel_CCU_LIN1;

/** @ref SWS_ComM_01005 */
typedef uint8 ComM_UserHandleSubArrayType_ComMChannel_CCU_LIN2[1];

/** @ref SWS_ComM_00906 */
typedef struct{

    uint8 numberOfRequesters;
    ComM_UserHandleSubArrayType_ComMChannel_CCU_LIN2 handleArray;
}ComM_UserHandleArrayType_ComMChannel_CCU_LIN2;

/** @ref SWS_ComM_01005 */
typedef uint8 ComM_UserHandleSubArrayType_ComMChannel_CCU_LIN3[1];

/** @ref SWS_ComM_00906 */
typedef struct{

    uint8 numberOfRequesters;
    ComM_UserHandleSubArrayType_ComMChannel_CCU_LIN3 handleArray;
}ComM_UserHandleArrayType_ComMChannel_CCU_LIN3;
#endif /* RTE_COMM_TYPE_H_ */

