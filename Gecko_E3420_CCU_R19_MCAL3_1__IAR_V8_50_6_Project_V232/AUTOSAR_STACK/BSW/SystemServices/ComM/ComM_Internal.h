/***********************************************************************************************************************
**                                                                                                                    **
** Copyright (C) iSOFT   (2022)                                                                                       **
**                                                                                                                    **
** All rights reserved.                                                                                               **
**                                                                                                                    **
** This document contains proprietary information belonging to iSOFT.Passing on and copying of this document, and     **
** communication of its contents is not permitted without prior written authorization.                                **
**                                                                                                                    **
************************************************************************************************************************
**                                                                                                                    **
**  @file               : ComM_Internal.h                                                                             **
**  @version            : V1.0.0                                                                                      **
**  @author             : darren.zhang                                                                                **
**  @date               : 2022/01/07                                                                                  **
**  @vendor             : isoft                                                                                       **
**  @description        : Communication Manager                                                                       **
**  @specification(s)   : AUTOSAR classic Platform R19-11                                                             **
**                                                                                                                    **
***********************************************************************************************************************/
#ifndef COMM_INTERNAL_H_
#define COMM_INTERNAL_H_

/*=================================================[inclusions]=======================================================*/
#include "ComM_Cfg.h"
#include "Std_Types.h"
#if defined(COMM_FUNC_TRACE_SUPPORT) || defined(COMM_FUNC_CHECK)
#include "func_trace.h"
#endif /* defined(COMM_FUNC_TRACE_SUPPORT) || defined(COMM_FUNC_CHECK) */
#include "ComStack_Types.h"
#if (COMM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* (COMM_DEV_ERROR_DETECT == STD_ON) */
#include "ComM_Types.h"

/*====================================================[macros]========================================================*/

#if defined(COMM_FUNC_TRACE_SUPPORT)
#define COMM_FUNC_TRACE_ENTRY(...) FuncTrace_Entry(__VA_ARGS__)
#define COMM_FUNC_TRACE_EXIT(...)  FuncTrace_Exit(__VA_ARGS__)
#define COMM_FUNC_TRACE_MARK(...)  FuncTrace_Mark(__VA_ARGS__)
#else
#define COMM_FUNC_TRACE_ENTRY(...)
#define COMM_FUNC_TRACE_EXIT(...)
#define COMM_FUNC_TRACE_MARK(...)
#endif /* defined(COMM_FUNC_TRACE_SUPPORT) */

#if !defined(COMM_FUNC_CHECK)
#define COMM_FUNC_CHECK 0
#endif /* !defined(COMM_FUNC_CHECK) */

#if COMM_FUNC_CHECK
#define COMM_CHECK_OUTPUT(...) FuncCheckOutput(__VA_ARGS__)
#else
#define COMM_CHECK_OUTPUT(...)
#endif /* COMM_FUNC_CHECK */

#if !defined(COMM_LOCAL)
#define COMM_LOCAL static
#endif /* !defined(COMM_LOCAL) */

#if !defined(COMM_EXTEND_FUNCTION_SUPPORT)
#define COMM_EXTEND_FUNCTION_SUPPORT 0
#endif /* !defined(COMM_EXTEND_FUNCTION_SUPPORT) */

#if !defined(COMM_LOCAL_INLINE)
#define COMM_LOCAL_INLINE LOCAL_INLINE
#endif /* !defined(COMM_LOCAL_INLINE) */

#if (STD_ON == COMM_DEV_ERROR_DETECT)
#if !defined(COMM_DET_REPORT)
/** \brief Macro for reporting an error to DET
 **
 ** \param[in] api Service ID of the API function
 ** \param[in] error Error code reported to Det module */
#define COMM_DET_REPORT(api, error)                                              \
    do                                                                           \
    {                                                                            \
        (void)Det_ReportError(COMM_MODULE_ID, COMM_INSTANCE_ID, (api), (error)); \
    } while (0)
#endif /* !defined(COMM_DET_REPORT) */
#else
#define COMM_DET_REPORT(api, error)
#endif /* STD_ON  == FOTAMASTER_DEV_ERROR_DETECT */

#define COMM_VLU_MAPU8_NUM(idx)   (((uint8)(idx) + 7u) / 8u)
#define COMM_VLU_MAPU8_BYTE(idx)  ((uint8)((uint8)(idx) >> 3u))
#define COMM_VLU_MAPU8_INDEX(idx) ((uint8)(idx) & (uint8)0x07u)
#define COMM_VLU_MAPU8_MASK(idx)  ((uint8)((uint8)1u << (COMM_VLU_MAPU8_INDEX(idx))))

#define COMM_VLU_MAPU32_NUM(idx)   ((idx) + 31u) / 32u)
#define COMM_VLU_MAPU32_BYTE(idx)  ((idx) / 32u)
#define COMM_VLU_MAPU32_INDEX(idx) ((idx)&0x1fu)
#define COMM_VLU_MAPU32_MASK(idx)  (((uint32)1u << (COMM_VLU_MAPU32_INDEX(idx))))

#if !defined(COMM_PARA_UNUSED)
#define COMM_PARA_UNUSED(x) ((void)(x))
#endif /* !defined(COMM_PARA_UNUSED) */

/*=============================================[type definitions]=====================================================*/

typedef uint32 uintx;

typedef struct
{
#define COMM_ECU_GROUP_CLS_NOMODE_LIMIT COMM_MASK_LIMIT_TO_NOCOM
#define COMM_ECU_GROUP_CLS_WAKEUP_LIMIT COMM_MASK_INHIBIT_WAKEUP
    uint8 ecuGroupClass;
    uint16 inhibitCnt;
} ComM_StoryDataType;

#endif /* COMM_INTERNAL_H_ */
