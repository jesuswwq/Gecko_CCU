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
 *  \file     Mcu_Clk.h                                                                           *
 *  \brief    This file contains interface header for CAN MCAL driver, ...                             *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/02     <td>1.0.0                               *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef MCU_CLK_H
#define MCU_CLK_H


#ifdef __cplusplus
extern "C" {
#endif
/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Mcu_GeneralTypes.h"
/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
/**
 * \brief Clk prepare interface.
 * \details Used for generate clock tree's node by platform or borad code,
 *          other code like app or driver should not use this ops.
 * \param[in] clk Clk node data.
 * \return int
 * \retval 0: sucess
 * \retval other: failed
 * \note The api not find the most suitable parent clock node,
 *       so if user specify a improper parent clock source,
 *       the clock actual frequency may has a big bias to target frequency.
 *       If you not consider clock divisible, and need high accuracy clock
 *       frequency, you can get the actual frequency use Mcu_Ip_ClkGetRate api.
 * \par Example
 * \code{c}

 *
 *   Mcu_Ip_ClkPrepare(&g_pll2_vco);
 *
 *   You can get the actual rate like this.
 *   Mcu_ClkRateType rate = Mcu_Ip_ClkGetRate(g_pll2_vco_node);
 * \endcode
 */
Std_ReturnType Mcu_Ip_ClkPrepare(Mcu_ClkNodeType *clkPtr);

/**
 * \brief Clk set rate interface, set one clk node rate.
 * \param[in] clk Clk node data.
 * \param[in] rate The clk rate to be set.
 * \return int
 * \retval 0: sucess
 * \retval other: failed
 * \note This api not set the parent clock node, but will use the parent clock
 *       node's rate to calculate divider's param.
 * \warning Some clk node may be not support clock_set_rate api when it has child node.
 *          This api always used for clock tree leaf node.
 * \par Example
 * \code{c}
 *   About clock_node param, reference Mcu_Ip_ClkPrepare function example.
 *   Mcu_Ip_ClkSetRate(&g_ckgen_saf_ip_timer1, 398000000U);
 *
 *   You can get the actual rate like this.
 *   Mcu_ClkRateType rate = Mcu_Ip_ClkGetRate(g_ckgen_saf_ip_timer1_node);
 * \endcode
 */
Std_ReturnType Mcu_Ip_ClkSetRate(Mcu_ClkNodeType *clkPtr, Mcu_ClkRateType rate);

/**
 * \brief Clk get rate interface, get one clk node rate.
 * \param[in] clk Clk node data.
 * \return Mcu_ClkRateType Clk rate value.
 */
Mcu_ClkRateType Mcu_Ip_ClkGetRate(Mcu_ClkNodeType *clkPtr);

/**
 * \brief Clk enable interface, enable one clk node if it has clock gate capacity.
 * \param[in] clk Clk node data.
 * \return int
 * \retval 0: sucess
 * \retval other: failed
 * \par Example
 * \code{c}
 *   About clock_node param, reference Mcu_Ip_ClkPrepare function example.
 *   Mcu_Ip_ClkEnable(g_ckgen_saf_ip_timer1_node);
 * \endcode
 */
Std_ReturnType Mcu_Ip_ClkEnable(const Mcu_ClkNodeType *clkPtr);

/**
 * \brief Clk disable interface, disable one clk node if it has clock gate capacity.
 * \param[in] clk Clk node data.
 * \warning Some clk node may be not support clock_set_rate api when it has child node.
 *          This api always used for clock tree leaf node.
 *          node's rate to calculate divider's param.
 * \par Example
 * \code{c}
 *   About clock_node param, reference Mcu_Ip_ClkPrepare function example.
 *   Mcu_Ip_ClkDisable(g_ckgen_saf_ip_timer1_node);
 * \endcode
 */
Std_ReturnType Mcu_Ip_ClkDisable(const Mcu_ClkNodeType *clkPtr);

/**
 * \brief Clk check gated interface.
 * \param[in] clk Clk node data.
 * \par Example
 * \code{c}
 *   About clock_node param, reference Mcu_Ip_ClkPrepare function example.
 *   Mcu_Ip_ClkIsGated(g_ckgen_saf_ip_timer1_node);
 * \endcode
 */
uint8 Mcu_Ip_ClkIsGated(const Mcu_ClkNodeType *clkPtr);

/**
 * \brief pll check locked interface.
 * \param[in] clk Clk node data.
 * \par Example
 * \code{c}
 *   About clock_node param, reference Mcu_Ip_ClkPrepare function example.
 *   Mcu_Ip_ClkIsGated(g_pll2_vco_node);
 * \endcode
 */
/** Traceability       : SW_MCU_SM011*/
uint8 Mcu_Ip_ClkIsLocked(const Mcu_ClkNodeType *clkPtr);

#ifdef __cplusplus
}
#endif

#endif /* MCU_CLK_H */
/* End of file */
