/********************************************************************************************************
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
 *  \file     Wdg_Reg.h                                                                                 *
 *  \brief    This file contains interface header for WDG MCAL driver, ...                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/17     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef WDG_REG_H
#define WDG_REG_H

/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/

/** \brief Driver Implementation Major Version */
#define WDG_REG_H_SW_MAJOR_VERSION    1
/** \brief Driver Implementation Minor Version */
#define WDG_REG_H_SW_MINOR_VERSION    0
/** \brief Driver Implementation Patch Version */
#define WDG_REG_H_SW_PATCH_VERSION    0
/* @} */
/**
 *  \brief WDG Driver Module Register  Bit Width INFO
 *
 *  Defines for  Bit Width INFO define
 *  @{
 */
/** \brief Driver function 1 bit width */
#define WDT_1BIT_WIDTH                 (0x1U)
/** \brief Driver function 2 bit width */
#define WDT_2BIT_WIDTH                 (0x2U)
/** \brief Driver function 3 bit width */
#define WDT_3BIT_WIDTH                 (0x3U)
/** \brief Driver function 8 bit width */
#define WDT_8BIT_WIDTH                 (0x8U)
/** \brief Driver function 16 bit width */
#define WDT_16BIT_WIDTH                (16U)
/** \brief Driver function 0 bit offset */
#define WDT_0BIT_OFFSET                (0x0U)
/** \brief Driver function 1 bit offset */
#define WDT_1BIT_OFFSET                (0x1U)
/** \brief Driver function 2 bit offset */
#define WDT_2BIT_OFFSET                (0x2U)
/** \brief Driver function 3 bit offset */
#define WDT_3BIT_OFFSET                (0x3U)
/** \brief Driver function 16 bit offset */
#define WDT_16BIT_OFFSET                (16U)

/** \brief Driver function 3 bit mask */
#define WDT_3BIT_MASK                  (0x7U)
/**
 *  \brief WDG Driver Module Register Info
 *
 *  Defines for WDG Register define
 *  @{
 */
/** \brief Driver WDT_CTRL register offset */
#define WDT_CTRL_OFF                 (0x0U)
/** \brief Driver WDT_CTRL DIV Number config mask */
#define FM_WDT_CTRL_PRE_DIV_NUM (0xffffU)
/** \brief Driver WDT_CTRL DIV Number */
#define FV_WDT_CTRL_PRE_DIV_NUM(v) \
    ((((v)) & FM_WDT_CTRL_PRE_DIV_NUM))

/** \brief Driver WDT_CTRL enable state bit offset*/
#define BM_WDT_CTRL_WDT_EN_STA       (10U)
/** \brief Driver WDT_CTRL enable src bit offset*/
#define BM_WDT_CTRL_WDT_EN_SRC       (8U)
/** \brief Driver WDT_CTRL debug halt enable bit offset*/
#define BM_WDT_CTRL_DBG_HALT_EN      (7U)
/** \brief Driver WDT_CTRL auto restart bit offset*/
#define BM_WDT_CTRL_AUTO_RESTART     (6U)
/** \brief Driver WDT_CTRL WTC SRC bit offset*/
#define BM_WDT_CTRL_WTC_SRC          (5U)
/** \brief Driver WDT_CTRL CLK SRC bit offset*/
#define FM_WDT_CTRL_CLK_SRC          (0x7U)
/** \brief Driver WDT_CTRL CLK SRC bit value*/
#define FV_WDT_CTRL_CLK_SRC(v) \
              (((v)) & FM_WDT_CTRL_CLK_SRC)

/** \brief Driver WDT_CTRL WDT enable bit offset*/
#define BM_WDT_CTRL_WDT_EN           (1U)
/** \brief Driver WDT_CTRL WDT software reset support bit offset*/
#define BM_WDT_CTRL_SOFT_RST         (0U)
/** \brief Driver WDT_WTC register offset */
#define WDT_WTC_OFF                  (0x4U)
/** \brief Driver WDT_WRC_CTL register offset */
#define WDT_WRC_CTL_OFF (0x8U)
/** \brief Driver WDT_WRC_CTL trigger bit offset */
#define BM_WDT_WRC_CTL_REFR_TRIG    (3U)
/** \brief Driver WDT_WRC_CTL mode1 enable bit offset */
#define BM_WDT_WRC_CTL_MODE1_EN (1U)
/** \brief Driver WDT_WRC_CTL mode0 enable bit offset */
#define BM_WDT_WRC_CTL_MODE0_EN (0U)
/** \brief Driver WDT_WRC_VAL register offset */
#define WDT_WRC_VAL_OFF (0xcU)
/** \brief Driver WDT_RST_CTL register offset */
#define WDT_RST_CTL_OFF (0x14U)
/** \brief Driver WDT_RST_CTL_RST_WIN WDT pulse weigth set offset */
#define BM_WDT_RST_CTL_RST_WIN   (20U)
/** \brief Driver WDT_RST_CTL WDT reset enable bit offset */
#define BM_WDT_RST_CTL_WDT_RST_EN   (18U)
/** \brief Driver WDT_RST_CTL INT reset enable bit offset */
#define BM_WDT_RST_CTL_INT_RST_EN   (16U)
/** \brief Driver WDT_EXT_RST_CTL register offset */
#define WDT_EXT_RST_CTL_OFF (0x18U)
/** \brief Driver WDT_EXT_RST_CTL reset counter offset */
#define BM_WDT_EXT_RST_CTL_RST_CNT (0U)
/** \brief Driver WDT_EXT_RST_CTL extern reset mode bit offset */
#define BM_WDT_EXT_RST_CTL_EXT_RST_MODE (17U)
/** \brief Driver WDT_EXT_RST_CTL extern reset mode enable bit offset */
#define BM_WDT_EXT_RST_CTL_EXT_RST_EN   (16U)
/** \brief Driver WDT_EXT_RST_CTL extern reset window bit offset */
#define BM_WDT_EXT_RST_CTL_RST_WIN   (20U)
/** \brief Driver WDT_INT register offset */
#define WDT_INT_OFF (0x24U)
/** \brief Driver WDT_INT over flow interrupt clear bit offset */
#define BM_WDT_INT_OVFLOW_INT_CLR   (8U)
/** \brief Driver WDT_INT ill window refr interrupt clear bit offset */
#define BM_WDT_INT_ILL_WIN_REFR_INT_CLR (6U)
/** \brief Driver RST_REQ_MON register offset */
#define RST_REQ_MON_OFF (0x28U)
/** \brief Driver RST_REQ_MON internal reset request monitor offset */
#define BM_RST_REQ_MON_INT_RST_REQ_REC (2U)
/** \brief Driver WDT_LOCK register offset */
#define WDT_LOCK_OFF (0x40U)
/** \brief Driver WDT_LOCK EXT_RST_LOCK bit offset */
#define BM_WDT_LOCK_EXT_RST_LOCK (4U)
#endif  /* __WDT_REG_H__ */
/* End of file */
