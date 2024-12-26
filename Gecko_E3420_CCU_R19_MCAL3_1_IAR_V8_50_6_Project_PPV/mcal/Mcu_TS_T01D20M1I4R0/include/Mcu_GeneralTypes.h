/** *****************************************************************************************************
 * SEMIDRIVE Copyright Statement                                                                        *
 * Copyright (c) SEMIDRIVE. All rights reserved                                                         *
 *                                                                                                      *
 * This software and all rights therein are owned by SEMIDRIVE, and are                                 *
 * protected by copyright law and other relevant laws, regulations and                                  *
 * protection. Without SEMIDRIVE's prior written consent and/or related rights,                         *
 * please do not use this software or any potion thereof in any form or by any                          *
 * means. You may not reproduce, modify or distribute this software except in                           *
 * compliance with the License. Unless required by applicable law or agreed to                          *
 * in writing, software distributed under the License is distributed on                                 *
 * an 'AS IS' basis, WITHOUT WARRANTIES OF ANY KIND, either express or implied.                         *
 *                                                                                                      *
 *******************************************************************************************************/
/** *****************************************************************************************************
 *  \file     Mcu_GeneralTypes.h                                                                           *
 *  \brief    This file contains interface header for MCU MCAL driver, ...                             *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/02     <td>1.0.0                               *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef MCU_GENERALTYPES_H
#define MCU_GENERALTYPES_H
/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/

#include "Std_Types.h"
#include "RegHelper.h"

#ifdef __cplusplus
extern "C"
{
#endif
/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/
#define MCU_MODULE_ID 101
#define MCU_INSTANCE 1

/* Error Code */
/** Traceability       : SWSR_MCU_006*/
#define MCU_E_PARAM_CONFIG 0x0Au
/** Traceability       : SWSR_MCU_006*/
#define MCU_E_PARAM_CLOCK 0x0Bu
/** Traceability       : SWSR_MCU_006*/
#define MCU_E_PARAM_MODE 0x0Cu
/** Traceability       : SWSR_MCU_006*/
#define MCU_E_PARAM_RAMSECTION 0x0Du
/** Traceability       : SWSR_MCU_006*/
#define MCU_E_PLL_NOT_LOCKED 0x0Eu
/** Traceability       : SWSR_MCU_006*/
#define MCU_E_UNINIT 0x0FU
/** Traceability       : SWSR_MCU_006*/
#define MCU_E_PARAM_POINTER 0x10U
/** Traceability       : SWSR_MCU_006*/
#define MCU_E_INIT_FAILED 0x11U

/** \brief  ERROR:Error due to API duplicated invoked Mcu_Init(). */
#define MCU_E_INIT 0x80U
/** \brief  ERROR:Error due to unexpected interrupt occurred. */
#define MCU_E_INT_UNEXPECT 0x81U
/** \brief  ERROR:Error due to timeout occurred. */
#define MCU_E_TIMEOUT 0x82U
/** \brief  ERROR:Error due to return value outrange occurred. */
#define MCU_E_OUTRANGE 0x83U
/** \brief  ERROR:Error due to register locked occurred. */
#define MCU_E_REGLOCKED 0x84U
/** \brief  ERROR:Error due to cannot enter RTC mode. */
#define MCU_E_RTC_ENTER_FAIL 0x85U
/** \brief  ERROR:Error due to analog trim does not trim. */
#define MCU_E_ANALOG_TRIM_FAIL 0x86U
/** \brief  ERROR:Error due to ate analog trim does not trim. */
#define MCU_E_ATE_ANALOG_TRIM_FAIL 0x87U
/** \brief  ERROR:Error due to vd clr status fail */
#define MCU_E_VD_CLR_STA_FAIL 0x88U
/** \brief  ERROR:Error due to ap bus mnpq ratio fail */
#define MCU_E_CKGEN_AP_BUS_MNPQ_RATIO_ERROR 0x89U

/**
* \brief Service ID (APIs) for Det reporting.
*/
#define MCU_SID_INIT                        ((uint8)0x00U)
#define MCU_SID_INIT_RAM_SECTION            ((uint8)0x01U)
#define MCU_SID_INIT_CLOCK                  ((uint8)0x02U)
#define MCU_SID_DISTRIBUTE_PLL_CLOCK        ((uint8)0x03U)
#define MCU_SID_GET_PLL_STATUS              ((uint8)0x04U)
#define MCU_SID_GET_RESET_REASON            ((uint8)0x05U)
#define MCU_SID_GET_RESET_RAW_VALUE         ((uint8)0x06U)
#define MCU_SID_PERFORM_RESET               ((uint8)0x07U)
#define MCU_SID_SET_MODE                    ((uint8)0x08U)
#define MCU_SID_GET_VERSION_INFO            ((uint8)0x09U)
#define MCU_SID_INIT_PVT                    ((uint8)0x0AU)
#define MCU_SID_INIT_VD                     ((uint8)0x0BU)
#define MCU_SID_INIT_SCR                    ((uint8)0x0CU)
#define MCU_SID_SET_SEIP_CLOCK              ((uint8)0x0DU)
#define MCU_SID_SET_SLEEP_TIME              ((uint8)0x0EU)
#define MCU_SID_SET_GATE_BYMODE             ((uint8)0x0FU)
#define MCU_SID_CKGEN_DIS                   ((uint8)0x10U)
#define MCU_SID_SET_RATE                    ((uint8)0x11U)
#define MCU_SID_GET_RATE                    ((uint8)0x12U)
#define MCU_SID_MONITOR_FREQ                ((uint8)0x13U)
#define MCU_SID_CQM                         ((uint8)0x14U)
#define MCU_SID_KICK_CORE                   ((uint8)0x15U)
#define MCU_SID_GENERAL_READ                ((uint8)0x16U)
#define MCU_SID_GENERAL_WRITE               ((uint8)0x17U)
#define MCU_SID_RTC_WAKEUP                  ((uint8)0x18U)
#define MCU_SID_POWER_CONTROL_SIGNAL        ((uint8)0x19U)
#define MCU_SID_AP_PLL_BYPASS               ((uint8)0x20U)
#define MCU_SID_RTC_DOMAIN_PCLK             ((uint8)0x21U)
#define MCU_SID_VD_STA                      ((uint8)0x22U)
#define MCU_SID_VD_TRIM                     ((uint8)0x23U)
#define MCU_SID_VD_VOLT_SEL                 ((uint8)0x24U)
#define MCU_SID_ANALOG_TRIM                 ((uint8)0x25U)

#define MCU_PARAM_UNUSED(param)         ((void)((param)))

#define CALL_RET_CHECK(ret, funcall) \
    if (E_OK == (ret)) { (ret) = (funcall); }

#define MCU_CLK_PARENT_NUM 8U

#define MCU_BIT(x, bit) ((x) & (1UL << (bit)))
#define MCU_BIT_MASK(x) ((1UL << (x)) - 1UL)
#define MCU_DIV_ROUND_UP(n, d) (((n) + (d) - 1U) / (d))
#define MCU_DIV_ROUND_CLOSEST(n, d)     (((n) + ((d)/2U))/(d))

/* Dummy error id state process */
#define MCU_DUMMY_STATEMENT(state)                                      ((state) = (state))
/********************************************************************************************************
 *                                  Global Types definition                                             *
 *******************************************************************************************************/
typedef enum
{
    MCU_MODE_RUN = 0U,    /**< \brief MCU Normal running mode */
    MCU_MODE_RTC = 3U,  /**< \brief All powers excepts RTC been disabled */
    MCU_MODE_ALL = 4U
} Mcu_ModeType;

typedef enum
{
    RESET_LP_HIB   = 0U,
    RESET_LP_SLEEP = 1U,
/*PRQA S 1535 1*/
} Mcu_ResetLowpowerModeType;

/** Traceability       : SWSR_MCU_012 SWSR_MCU_013 SWSR_MCU_014*/
typedef enum
{
    MCU_POWER_ON_RESET = 0U,  /**< @brief Power On Reset (default) */
    MCU_WATCHDOG_RESET,  /**< @brief Internal Watchdog Timer Reset */
    MCU_SW_RESET,        /**< @brief Software Reset */
    MCU_RESET_UNDEFINED, /**< @brief Reset is undefined */
    MCU_SEM_RESET,       /**< @brief SEM (function safety related) reset */
    MCU_DBG_RESET,       /**< @brief Reset by Debugger */
    MCU_VDC_RESET,       /**< @brief Reset by volate detect */
    MCU_EFUSE_RESET,     /**< @brief Reset by efuse non validate detect */
    MCU_COLD_RESET,     /**< @brief Reset by ap rstgen */
    MCU_PVT_RESET,      /**< @brief Reset by PVT rstgen */
} Mcu_ResetType;

/**
 * \brief PLL Spread amplitude.
 *
 */
typedef enum
{
    CKGEN_SSC_0P0_PERCENT = 0U,     /**< SSC_DEP 0.0% */
    CKGEN_SSC_0P1_PERCENT = 1U,         /**< SSC_DEP 0.1% */
    CKGEN_SSC_0P2_PERCENT = 2U,         /**< SSC_DEP 0.2% */
    CKGEN_SSC_0P3_PERCENT = 3U,         /**< SSC_DEP 0.3% */
    CKGEN_SSC_0P4_PERCENT = 4U,         /**< SSC_DEP 0.4% */
    CKGEN_SSC_0P5_PERCENT = 5U,         /**< SSC_DEP 0.5% */
    CKGEN_SSC_0P6_PERCENT = 6U,         /**< SSC_DEP 0.6% */
    CKGEN_SSC_0P7_PERCENT = 7U,         /**< SSC_DEP 0.7% */
    CKGEN_SSC_0P8_PERCENT = 8U,         /**< SSC_DEP 0.8% */
    CKGEN_SSC_0P9_PERCENT = 9U,         /**< SSC_DEP 0.9% */
    CKGEN_SSC_1P0_PERCENT = 10U,         /**< SSC_DEP 1.0% */
    CKGEN_SSC_1P1_PERCENT = 11U,         /**< SSC_DEP 1.1% */
    CKGEN_SSC_1P2_PERCENT = 12U,         /**< SSC_DEP 1.2% */
    CKGEN_SSC_1P3_PERCENT = 13U,         /**< SSC_DEP 1.3% */
    CKGEN_SSC_1P4_PERCENT = 14U,         /**< SSC_DEP 1.4% */
    CKGEN_SSC_1P5_PERCENT = 15U,         /**< SSC_DEP 1.5% */
    CKGEN_SSC_1P6_PERCENT = 16U,         /**< SSC_DEP 1.6% */
    CKGEN_SSC_1P7_PERCENT = 17U,         /**< SSC_DEP 1.7% */
    CKGEN_SSC_1P8_PERCENT = 18U,         /**< SSC_DEP 1.8% */
    CKGEN_SSC_1P9_PERCENT = 19U,         /**< SSC_DEP 1.9% */
    CKGEN_SSC_2P0_PERCENT = 20U,         /**< SSC_DEP 2.0% */
    CKGEN_SSC_2P1_PERCENT = 21U,         /**< SSC_DEP 2.1% */
    CKGEN_SSC_2P2_PERCENT = 22U,         /**< SSC_DEP 2.2% */
    CKGEN_SSC_2P3_PERCENT = 23U,         /**< SSC_DEP 2.3% */
    CKGEN_SSC_2P4_PERCENT = 24U,         /**< SSC_DEP 2.4% */
    CKGEN_SSC_2P5_PERCENT = 25U,         /**< SSC_DEP 2.5% */
    CKGEN_SSC_2P6_PERCENT = 26U,         /**< SSC_DEP 2.6% */
    CKGEN_SSC_2P7_PERCENT = 27U,         /**< SSC_DEP 2.7% */
    CKGEN_SSC_2P8_PERCENT = 28U,         /**< SSC_DEP 2.8% */
    CKGEN_SSC_2P9_PERCENT = 29U,         /**< SSC_DEP 2.9% */
    CKGEN_SSC_3P0_PERCENT = 30U,         /**< SSC_DEP 3.0% */
    CKGEN_SSC_3P1_PERCENT = 31U,         /**< SSC_DEP 3.1% */
} Mcu_CkgenSscAmplitudeType;

/**
 * \brief PLL Spread mode.
 *
 */
typedef enum
{
    CKGEN_NO_SSC = 0U,         /**< PLL no spread */
    CKGEN_DOWN_SPREADING,     /**< PLL down spread */
    CKGEN_CENTER_SPREADING,   /**< PLL center spread */
} Mcu_CkgenSscModeType;

/**
 * \brief PLL Spread Modulation frequency.
 *
 */
typedef enum
{
    CKGEN_FREF_DIV_507 = 0U,     /**< For 16MHz ref. It's 31.5KHz */
    CKGEN_FREF_DIV_761,         /**< For 24MHz ref. It's 31.5KHz */
    CKGEN_FREF_DIV_793,         /**< For 25MHz ref. It's 31.5KHz */
    CKGEN_FREF_DIV_857,         /**< For 27MHz ref. It's 31.5KHz */
} Mcu_CkgenSscFreqType;

/**
 * \brief Temperature sensor alarm modes.
 *
 * \note Do not change the order of this structure.
 */
typedef enum
{
    /**< Alarm asserted when DOUT is above HYST_H thresholds. */
    PVT_HIGH_LEVEL_ALARM = 0U,
    /**< Alarm asserted when DOUT is below HYST_L thresholds. */
    PVT_LOW_LEVEL_ALARM,
    /**< Alarm asserted when sensored value is rising above HYST_R. */
    PVT_RISING_EDGE_ALARM,
    /**< Alarm asserted when sensored value is falling below HYST_L. */
    PVT_FALLING_EDGE_ALARM,

    PVT_ALARM_NR,
} Mcu_PvtAlarmType;

/**
 * \brief PVT core logics.
 *
 * The sensor has 2 cores, both of which have identical logics, but
 * different interrupt numbers.
 */
typedef enum
{
    PVT_CORE0 = 0U,
    PVT_CORE1 = 1U,
    PVT_CORE_NR,
} Mcu_PvtCoreIdType;

typedef uint32 Mcu_ClkRateType;
/*PRQA S 1535 1*/
typedef uint32 Mcu_ModeConfigType;
/** Traceability       : SWSR_MCU_018 SWSR_MCU_019 SWSR_MCU_020 */
typedef uint32 Mcu_RamSectionType;
typedef uint32 Mcu_ClockType;
/** Traceability       : SWSR_MCU_015 SWSR_MCU_016 SWSR_MCU_017 */
typedef uint32 Mcu_RawResetType;

/**
 * \brief Clk core type, clock core may be a clock source or frequency divider.
 */
typedef struct
{
    uint32 type;
    uint32 base;
    const struct Mcu_PreClkOpsType *ops;
    void *private;
} Mcu_ClkCoreType;

/**
 * \brief Clk node type.
 */
typedef struct Mcu_PreClkNodeType
{
    Mcu_ClkCoreType *core;
    uint32 id;
    Mcu_ClkRateType rate;
    uint8 parentsNum;
    uint8 mux;
    struct Mcu_PreClkNodeType *parent;
    struct Mcu_PreClkNodeType *parents[MCU_CLK_PARENT_NUM];
    boolean dsm_en;
} Mcu_ClkNodeType;

/**
 * \brief Clk core operation interface type.
 */
typedef struct  Mcu_PreClkOpsType
{
    Std_ReturnType (*prepare)(Mcu_ClkNodeType *clkPtr);
    Std_ReturnType (*enable)(const Mcu_ClkNodeType *clkPtr);
    Std_ReturnType (*disable)(const Mcu_ClkNodeType *clkPtr);
    uint8 (*isGated)(const Mcu_ClkNodeType *clkPtr);
    Mcu_ClkRateType (*getRate)(Mcu_ClkNodeType *clkPtr);
    Std_ReturnType (*setRate)(Mcu_ClkNodeType *clkPtr, Mcu_ClkRateType rate);
    uint8 (*selectParent)(Mcu_ClkNodeType *clkPtr, Mcu_ClkRateType rate, uint32 *best_div);
    /* only for pll */
    uint8 (*isLocked)(const Mcu_ClkNodeType *clkPtr);
    Std_ReturnType (*lowpowerCgset)(const Mcu_ClkNodeType *clkPtr, uint8 lp_mode, boolean val);
/*PRQA S 1535 1*/
} Mcu_ClkOpsType;

struct Mcu_PreResetCtlType;

/**
 * \brief reset hardware driver function table
 */
typedef struct
{
    /* assert a reset signal */
    Std_ReturnType (*assertSig)(const struct Mcu_PreResetCtlType *rstCtlPtr, uint32 id);

    /* deassert a reset signal */
    Std_ReturnType (*deassert)(const struct Mcu_PreResetCtlType *rstCtlPtr, uint32 id);

    /* assert a reset signal, and deassert automatically */
    Std_ReturnType (*reset)(const struct Mcu_PreResetCtlType *rstCtlPtr, uint32 id);

    /* check reset signal status */
    uint32 (*status)(const struct Mcu_PreResetCtlType *rstCtlPtr, uint32 id);

    /* read reset general reg */
    uint32 (*readGeneral)(const struct Mcu_PreResetCtlType *rstCtlPtr, uint32 id);

    /* write reset general reg */
    Std_ReturnType (*writeGeneral)(const struct Mcu_PreResetCtlType *rstCtlPtr, uint32 id, uint32 val);

    /* global reset */
    Std_ReturnType (*globalReset)(const struct Mcu_PreResetCtlType *sfRstCtlPtr);

} Mcu_ResetCtlOpsType;

/**
 * \brief abstract reset controller
 */
typedef struct Mcu_PreResetCtlType
{
    const Mcu_ResetCtlOpsType     *ops;
    uint32        base;
} Mcu_ResetCtlType;

/**
 * \brief abstract reset signal
 */
typedef struct
{
    const Mcu_ResetCtlType    *rstCtl;
    uint32            id;
} Mcu_ResetSigType;


typedef struct
{
    const Mcu_ClkNodeType *pllNode;
    Mcu_CkgenSscAmplitudeType amplitude;
    Mcu_CkgenSscFreqType frequency;
    Mcu_CkgenSscModeType mode;
} Mcu_PllSpreadConfigType;

/** Traceability       : SWSR_MCU_008*/
typedef struct
{
    uint32 idx;
    uint32 base;
    uint32 size;
    uint8 defaultValue;
    uint8 writeSize;
} Mcu_RamConfigType;

struct Mcu_PvtPreType;
/**
 * \brief Temperature alarm callback.
 */
typedef void (*Mcu_PvtAlarmCbType)(struct Mcu_PvtPreType *devPtr, Mcu_PvtCoreIdType core,
                                   Mcu_PvtAlarmType alarm, void *arg);

/**
 * \brief PVT core logic structure.
 *
 * The controller has 2 cores, which have unique interrupt number
 * and configuration registers.
 */
typedef struct
{
    /**< Interrupt number of the core. */
    uint32 irq;
    /**< Interrupt callback. */
    Mcu_PvtAlarmCbType alarmCb;
    /**< Interrupt callback arg. */
    void *cbArg;
    /**< Bit mask of enabled alarms of this core, using Mcu_PvtAlarmType
     * as bit shift. */
    uint32 alarmEnableMask;
} Mcu_PvtCoreType;

/**
 * \brief Process and temperature sensor structure.
 */
typedef struct Mcu_PvtPreType
{
    /**< PVT controller base address. */
    uint32 base;
    /**< Core logics. */
    Mcu_PvtCoreType core[PVT_CORE_NR];
} Mcu_PvtType;


typedef struct
{
    Mcu_PvtAlarmType type;
    float highest;
    float T1;
    float T2;
    const Mcu_PvtAlarmCbType pvtNotificationPtr;
} Mcu_PvtConfigType;
/** Traceability       : SW_SM005*/
boolean Mcu_Ip_WaitForBitTimes(uint32 base, uint32 offset, uint32 val, uint32 count);
#ifdef __cplusplus
}
#endif

#endif /* MCU_GENERALTYPES_H */
/* End of file */
