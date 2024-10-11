/** **************************************************************************************
 * SEMIDRIVE Copyright Statement
 * Copyright (c) SEMIDRIVE. All rights reserved
 *
 * This software and all rights therein are owned by SEMIDRIVE, and are
 * protected by copyright law and other relevant laws, regulations and
 * protection. Without SEMIDRIVE's prior written consent and/or related rights,
 * please do not use this software or any potion thereof in any form or by any
 * means. You may not reproduce, modify or distribute this software except in
 * compliance with the License. Unless required by applicable law or agreed to
 * in writing, software distributed under the License is distributed on
 * an 'AS IS' basis, WITHOUT WARRANTIES OF ANY KIND, either express or implied.
 *
 *****************************************************************************************/
/** **************************************************************************************
 *  \file     Xtrg_Types.h
 *  \brief    This file contains interface header for CAN MCAL driver, ...
 *
 * <table>
 * <tr><th>Date           <th>Version
 * <tr><td>2023/08/04     <td>1.0.0
 * </table>
 *****************************************************************************************/
#ifndef XTRG_TYPES_H
#define XTRG_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif
/*****************************************************************************************
 *                       Include header files
 *****************************************************************************************/
#include "Platform_Types.h"
/** \brief Marco for xtrg indirect TidPoolx_TargetConfig target choose */
#define XTRG_TARGETLUT0 0U
#define XTRG_TARGETLUT1 1U
#define XTRG_TARGETLUT2 2U
#define XTRG_TARGETLUT3 3U
#define XTRG_TARGETLUT4 4U
#define XTRG_TARGETLUT5 5U
#define XTRG_TARGETLUT6 6U
#define XTRG_TARGETLUT7 7U
/** \brief Marco for xtrg indirect TidPoolx_TargetConfig triggered adc choose */
#define XTRG_INDRT_TRIG_ADC_ENTRY0 0U
#define XTRG_INDRT_TRIG_ADC_ENTRY1 1U
#define XTRG_INDRT_TRIG_ADC_ENTRY2 2U
#define XTRG_INDRT_TRIG_ADC_ENTRY3 3U
#define XTRG_INDRT_TRIG_ADC_ENTRY4 4U
#define XTRG_INDRT_TRIG_ADC_ENTRY5 5U
#define XTRG_INDRT_TRIG_ADC_ENTRY6 6U
#define XTRG_INDRT_TRIG_ADC_ENTRY7 7U
#define XTRG_INDRT_TRIG_ADC_ENTRY8 8U
#define XTRG_INDRT_TRIG_ADC_ENTRY9 9U
#define XTRG_INDRT_TRIG_ADC_ENTRY10 10U
#define XTRG_INDRT_TRIG_ADC_ENTRY11 11U
#define XTRG_INDRT_TRIG_ADC_ENTRY12 12U
#define XTRG_INDRT_TRIG_ADC_ENTRY13 13U
#define XTRG_INDRT_TRIG_ADC_ENTRY14 14U
#define XTRG_INDRT_TRIG_ADC_ENTRY15 15U
#define XTRG_INDRT_TRIG_ADC_ENTRY16 16U
#define XTRG_INDRT_TRIG_ADC_ENTRY17 17U
#define XTRG_INDRT_TRIG_ADC_ENTRY18 18U
#define XTRG_INDRT_TRIG_ADC_ENTRY19 19U
#define XTRG_INDRT_TRIG_ADC_ENTRY20 20U
#define XTRG_INDRT_TRIG_ADC_ENTRY21 21U
#define XTRG_INDRT_TRIG_ADC_ENTRY22 22U
#define XTRG_INDRT_TRIG_ADC_ENTRY23 23U
#define XTRG_INDRT_TRIG_ADC_ENTRY24 24U
#define XTRG_INDRT_TRIG_ADC_ENTRY25 25U
#define XTRG_INDRT_TRIG_ADC_ENTRY26 26U
#define XTRG_INDRT_TRIG_ADC_ENTRY27 27U
#define XTRG_INDRT_TRIG_ADC_ENTRY28 28U
#define XTRG_INDRT_TRIG_ADC_ENTRY29 29U
#define XTRG_INDRT_TRIG_ADC_ENTRY30 30U
#define XTRG_INDRT_TRIG_ADC_ENTRY31 31U

/**
 *  \addtogroup MCAL_XTRG_CFG Xtrg Configuration.
 *
 * This files defines XTRG MCAL configuration structures
 *  \{
 */
/** \brief Type for xtrg error id */
typedef uint8 Xtrg_ErrorIdType;

/** \brief  data structure containing the index number of signals when
 * different functions are involved in Xtrg different signal groups. */
/** Traceability    :SWSR_XTRG_018 */
typedef struct
{
    /** \brief  total signal number in one signal group */
    uint32 sigNumber;
    /** \brief  signal matrix signal index number in one signal group */
    uint32 ssigNumber;
    /** \brief  normal signal index number in one signal group */
    uint32 smuxNumber;
    /** \brief  synchronization signal index number in one signal group */
    uint32 syncmuxNumber;
} Xtrg_SignalIndexType;

/** \brief  Type for eight Xtrg software trigger selector */
/** Traceability    :SWSR_XTRG_019 */
typedef enum
{
    XTRG_SWT_SELECTOR0 = 0U,
    XTRG_SWT_SELECTOR1,
    XTRG_SWT_SELECTOR2,
    XTRG_SWT_SELECTOR3,
    XTRG_SWT_SELECTOR4,
    XTRG_SWT_SELECTOR5,
    XTRG_SWT_SELECTOR6,
    XTRG_SWT_SELECTOR7,
} Xtrg_SWTrigSelectorType;
/** \brief  Type for Xtrg software trigger event */
/** Traceability    :SWSR_XTRG_001 SWSR_XTRG_020 */
typedef enum
{
    XTRG_SWT_PULSE_EVENT = 0U,
    XTRG_SWT_TOGGLE_EVENT,
    XTRG_SWT_LOW_EVENT,
    XTRG_SWT_HIGH_EVENT,
} Xtrg_SWTrigEventType;
/** \brief  Type for Xtrg pulse detect mode event */
/** Traceability    :SWSR_XTRG_004 SWSR_XTRG_022 */
typedef enum
{
    XTRG_PULSE_POSEDGE_DETECT = 0U,
    XTRG_PULSE_NEGEDGE_DETECT,
    XTRG_PULSE_BOTHEDGE_DETECT,
} Xtrg_PulseEdgeDetectType;

/** \brief  Type for Xtrg signal martrix selector */
/** Traceability    :SWSR_XTRG_003 SWSR_XTRG_004 SWSR_XTRG_023 */
typedef enum
{
    XTRG_SIG_MATRIX0 = 0U,
    XTRG_SIG_MATRIX1,
    XTRG_SIG_MATRIX2,
    XTRG_SIG_MATRIX3,
    XTRG_SIG_MATRIX4,
    XTRG_SIG_MATRIX5,
    XTRG_SIG_MATRIX6,
    XTRG_SIG_MATRIX7,
    XTRG_SIG_MATRIX8,
    XTRG_SIG_MATRIX9,
    XTRG_SIG_MATRIX10,
    XTRG_SIG_MATRIX11,
    XTRG_SIG_MATRIX12,
    XTRG_SIG_MATRIX13,
    XTRG_SIG_MATRIX14,
    XTRG_SIG_MATRIX15,
} Xtrg_SigMatrixSelectorType;

/** \brief  Type for Xtrg direct tmux selector */
/** Traceability    :SWSR_XTRG_027 */
typedef enum
{
    XTRG_DRT_TRG_MUX0 = 0U,
    XTRG_DRT_TRG_MUX1,
    XTRG_DRT_TRG_MUX2,
    XTRG_DRT_TRG_MUX3,
    XTRG_DRT_TRG_MUX4,
    XTRG_DRT_TRG_MUX5,
    XTRG_DRT_TRG_MUX6,
    XTRG_DRT_TRG_MUX7,
} Xtrg_DrtTrigMuxSelectorType;

/** \brief  Type for Xtrg dir/inder tmux target lut triggered adc */
/** Traceability    :SWSR_XTRG_007 SWSR_XTRG_053 */
typedef enum
{
    XTRG_TRIG_NONE = 0U,
    XTRG_TRIG_ADC1,
    XTRG_TRIG_ADC2,
    XTRG_TRIG_ADC1_AND_ADC2,
    XTRG_TRIG_ADC3,
    XTRG_TRIG_ADC1_AND_ADC3,
    XTRG_TRIG_ADC2_AND_ADC3,
    XTRG_TRIG_ADC1_AND_ADC2_AND_ADC3,
} Xtrg_TrigTargetType;

#ifndef SEMIDRIVE_E3_LITE_SERIES
/** \brief  Type for Xtrg direct tmux triggered id select */
/** Traceability    :SWSR_XTRG_007 SWSR_XTRG_054 */
typedef enum
{
    XTRG_DRT_TRG_ID_ETIMER1 = 0U,
    XTRG_DRT_TRG_ID_ETIMER2,
    XTRG_DRT_TRG_ID_ETIMER3,
    XTRG_DRT_TRG_ID_ETIMER4,
    XTRG_DRT_TRG_ID_EPWM1,
    XTRG_DRT_TRG_ID_EPWM2,
    XTRG_DRT_TRG_ID_EPWM3,
    XTRG_DRT_TRG_ID_EPWM4,
} Xtrg_DrtTrigIdType;
#else
/** \brief  Type for Xtrg direct tmux triggered id select */
/** Traceability    :SWSR_XTRG_007  */
typedef enum
{
    XTRG_DRT_TRG_ID_ETIMER1 = 0U,
    XTRG_DRT_TRG_ID_ETIMER2,
    XTRG_DRT_TRG_ID_EPWM1,
    XTRG_DRT_TRG_ID_EPWM2,
} Xtrg_DrtTrigIdType;
#endif

/** \brief  Type for Xtrg indirect tmux selector */
/** Traceability    :SWSR_XTRG_007  SWSR_XTRG_029 */
typedef enum
{
    XTRG_INDRT_TRG_MUX0 = 0U,
    XTRG_INDRT_TRG_MUX1,
    XTRG_INDRT_TRG_MUX2,
    XTRG_INDRT_TRG_MUX3,
    XTRG_INDRT_TRG_MUX4,
    XTRG_INDRT_TRG_MUX5,
    XTRG_INDRT_TRG_MUX6,
    XTRG_INDRT_TRG_MUX7,
} Xtrg_IndrtTrigMuxSelectorType;

/** \brief  Type for Xtrg indirect tmux tidpool end index select */
/** Traceability    :SWSR_XTRG_007 SWSR_XTRG_055 */
typedef enum
{
    XTRG_TIDPOOL0 = 0U,
    XTRG_TIDPOOL1,
    XTRG_TIDPOOL2,
    XTRG_TIDPOOL3,
    XTRG_TIDPOOL4,
    XTRG_TIDPOOL5,
    XTRG_TIDPOOL6,
    XTRG_TIDPOOL7,
} Xtrg_IndrtTrigTidIndexType;

/** \brief  Type for Xtrg dir/indirect tmux selector */
/** Traceability    :SWSR_XTRG_008 SWSR_XTRG_031 */
typedef enum
{
    XTRG_TRG_MUX0 = 0U,
    XTRG_TRG_MUX1,
    XTRG_TRG_MUX2,
    XTRG_TRG_MUX3,
    XTRG_TRG_MUX4,
    XTRG_TRG_MUX5,
    XTRG_TRG_MUX6,
    XTRG_TRG_MUX7,
} Xtrg_TrigMuxSelectorType;

/** \brief  Type for Xtrg dir/indirect tmux triggered adc selector */
/** Traceability    :SWSR_XTRG_008 SWSR_XTRG_032 */
typedef enum
{
    XTRG_TRG_ADC1 = 0U,
    XTRG_TRG_ADC2,
    XTRG_TRG_ADC3,
} Xtrg_TrigAdcIndexType;

/** \brief  Type for Xtrg dir/indirect tmux priority */
/** Traceability    :SWSR_XTRG_056 */
typedef enum
{
    XTRG_TMUX_PRIORITY0 = 0U,
    XTRG_TMUX_PRIORITY1,
    XTRG_TMUX_PRIORITY2,
    XTRG_TMUX_PRIORITY3,
    XTRG_TMUX_PRIORITY4,
    XTRG_TMUX_PRIORITY5,
    XTRG_TMUX_PRIORITY6,
    XTRG_TMUX_PRIORITY7,
} Xtrg_TmuxTrigPriority;

/** \brief  Type for xtrg interrupt event */
/** Traceability    :SWSR_XTRG_011 SWSR_XTRG_035 */
typedef enum
{
    XTRG_TMUX0_DONE = 16U,
    XTRG_TMUX1_DONE,
    XTRG_TMUX2_DONE,
    XTRG_TMUX3_DONE,
    XTRG_TMUX4_DONE,
    XTRG_TMUX5_DONE,
    XTRG_TMUX6_DONE,
    XTRG_TMUX7_DONE,
} Xtrg_NormalInterruptType;

/** \brief Type for xtrg callback */
/** Traceability    :SWSR_XTRG_012 */
typedef void (*Xtrg_CallbackType)(void *arg, uint8 event);

/** \brief  Type for xtrg notification enabled status */
/** Traceability    :SWSR_XTRG_057 */
typedef enum
{
    XTRG_NOTIF_DISABLED = 0U,
    XTRG_NOTIF_ENABLED,
} Xtrg_NotifEnableType;

/** \brief  data structure containing the configuration of Xtrg
 * software trigger including software trigger selector,
 * event and the pulse width if the event is pulse event.  */
/** Traceability    :SWSR_XTRG_021 */

typedef struct
{
    Xtrg_SWTrigSelectorType trigSelector;
    Xtrg_SWTrigEventType trigEvent;
    uint16 pulseWidth;
} Xtrg_SWTriggerType;

/** \brief  Data structure containing the configuration of Xtrg signal
 *  matrix 5 inputs including input signal, edge detect enable,
 *  edge detect mode. */
/** Traceability    :SWSR_XTRG_003 SWSR_XTRG_004 SWSR_XTRG_024 */
typedef struct
{
    uint32 matrixInput;
    boolean edgeDetect;
    Xtrg_PulseEdgeDetectType edgeDetectMode;
} Xtrg_SigMatrixInputType;

/** \brief  Data structure containing the configuration of Xtrg
 * signal matrix including signal matrix selector,truth table
 * value and signal matrix 5 input signals configuration. */
/** Traceability    :SWSR_XTRG_003 SWSR_XTRG_004 SWSR_XTRG_025 */
typedef struct
{
    Xtrg_SigMatrixInputType matrixInputCfg[5];
    uint32 truthTable;
    Xtrg_SigMatrixSelectorType matrixSelector;
} Xtrg_SigMatrixType;

/** \brief  Data structure containing the configuration of Xtrg
 * signal matrix including signal matrix selector,truth table
 * value and signal matrix 5 input signals configuration. */
/** Traceability    :SWSR_XTRG_005 SWSR_XTRG_006 SWSR_XTRG_026 */
typedef struct
{
    uint32 signalInput;
    uint32 signalOutput;
} Xtrg_SignalType;

/** \brief  Data structure containing the configuration of Xtrg
 * direct trigger mux including trigger source signal,trigger index,
 * direct trigger mux selector and 8 trigger targets. */
/** Traceability    :SWSR_XTRG_007 SWSR_XTRG_028 */
typedef struct
{
    Xtrg_DrtTrigMuxSelectorType directTmux;
    Xtrg_DrtTrigIdType tidSignal;
    uint32 triggerSource;
    Xtrg_TrigTargetType targetCfg[8];
} Xtrg_DrtTrigMuxType;

/** \brief Data structure containing the configuration of Xtrg indirect
 * trigger mux including trigger source signal,term target index,term
 * target value,indirect trigger mux selector 8 trigger targets and tid
 * pool value. */
/** Traceability    :SWSR_XTRG_007 SWSR_XTRG_030 */
typedef struct
{
    Xtrg_IndrtTrigMuxSelectorType indirectTmux;
    Xtrg_IndrtTrigTidIndexType targetTidIndex;
    Xtrg_TrigTargetType targetCfg[8];
    uint8 tidPool[8][2];
    uint32 triggerSource;
} Xtrg_IndrtTrigMuxType;

/** \brief Data structure containing the configuration of Xtrg IO filter
 * including the signal index,edge detecting mode,positive edge and
 * negative edge detecting interval and sampling interval. */
/** Traceability    :SWSR_XTRG_009 SWSR_XTRG_033 */
typedef struct
{
    uint32 ioInput;
    Xtrg_PulseEdgeDetectType ioFilterMode;
    uint32 posDetIntvl;
    uint32 negDetIntvl;
    uint32 samplingIntvl;
} Xtrg_IOFilterType;

/** \brief Data structure containing the configuration of Xtrg device
 * including xtrg device base,xtrg callback and custom information. */
/** Traceability    :SWSR_XTRG_012 SWSR_XTRG_034 */
typedef struct
{
    volatile uint32 base;
    Xtrg_CallbackType cb;
    void *arg;
} Xtrg_DeviceType;
/** \} */
#ifdef __cplusplus
}
#endif
#endif /* XTRG_TYPES_H */
/* End of file */
