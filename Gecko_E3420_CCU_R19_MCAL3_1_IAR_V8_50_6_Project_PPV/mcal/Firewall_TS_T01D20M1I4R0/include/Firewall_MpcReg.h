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
 *  \file     Firewall_MpcReg.h                                                                         *
 * \brief    This file contains registers define for Firewall MPC module.                               *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/25     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef FIREWALL_MPCREG_H
#define FIREWALL_MPCREG_H
#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                 Private Macro definition                                             *
 *******************************************************************************************************/
/** \brief The address offset of the domain0 ~ 3 permissions register
 *         for the different memory port.
 */
#define MPC_DOM_PER0(n) ((uint32)((uint32)(n)*0xCU))
/** \brief The address offset of the domain4 ~ 7 permissions register                                                  \
 *         for the different memory port.                                                                              \
 */                                                                                                                    \
#define MPC_DOM_PER1(n)                                                                                                \
    ((uint32)(0x4U + ((uint32)(n)*0xCU)))

#define MPC_DOM_PER_LOCK_MASK           (0xFFU)
/** \brief The address offset of the permission lock register. */
#define MPC_DOM_PER_LOCK(n)             ((uint32)(0x8U + ((uint32)(n)*0xCU)))

/** \brief The bit offset of the domain0. */
#define DOM_PER_DOMAIN0_BIT             (4U)
/** \brief The bit offset of the domain1. */
#define DOM_PER_DOMAIN1_BIT             (8U + 4U)
/** \brief The bit offset of the domain2. */
#define DOM_PER_DOMAIN2_BIT             (16U + 4U)
/** \brief The bit offset of the domain3. */
#define DOM_PER_DOMAIN3_BIT             (24U + 4U)
/** \brief The bit offset of the domain4. */
#define DOM_PER_DOMAIN4_BIT             (4U)
/** \brief The bit offset of the domain5. */
#define DOM_PER_DOMAIN5_BIT             (8U + 4U)
/** \brief The bit offset of the domain6. */
#define DOM_PER_DOMAIN6_BIT             (16U + 4U)
/** \brief The bit offset of the domain7. */
#define DOM_PER_DOMAIN7_BIT             (24U + 4U)

/** \brief The address offset of the region start address register. */
#define MPC_RGN_START_ADDR(n)           (uint32)((0x140U + ((uint32)(n)*0x10U)))
/** \brief The address offset of the region end address register. */
#define MPC_RGN_END_ADDR(n)             (uint32)((0x144U + ((uint32)(n)*0x10U)))
/** \brief The bit mask of enabling region configuration. */
#define MPC_RGN_ENABLE                  (0x1UL << 30U)
/** \brief The bit mask of locking region configuration. */
#define MPC_RGN_LOCK                    (0x1UL << 31U)
/** \brief The address offset of the region low limit address register. */
#define RGN_LOW_LIM(n)                  (uint32)((0x148U + ((uint32)(n)*0x10U)))
/** \brief The address offset of the region up limit address register. */
#define RGN_UP_LIM(n)                   (uint32)((0x14CU + ((uint32)(n)*0x10U)))

/** \brief The address offset of the interrupt status register. */
#define MPC_FUNC_INT_STA                (uint32)(0x2E0U)
/** \brief The address offset of the interrupt control register. */
#define MPC_FUNC_INT_STA_EN             ((uint32)0x2E4U)
/** \brief The address offset of the interrupt signal register. */
#define MPC_FUNC_INT_SIG_EN             ((uint32)0x2E8U)
/** \brief The bit mask of setting register access error. */
#define MPC_REG_ACS_ERR                 (0x1U << 1U)
/** \brief The bit mask of setting memory access error. */
#define MPC_MEM_ACS_ERR                 (0x1U)

/** \brief The address offset of the response error register. */
#define MPC_RESP_ERR_DIS                ((uint32)0x2F0U)
/** \brief The bit mask of locking the response error configuration. */
#define MPC_RESP_ERR_DIS_LOCK           (0x1UL << 31U)
/** \brief The bit mask of disabling the response error feature. */
#define MPC_RESP_ERR_DIS_DIS            (0x1UL)

/** \brief Address alignment. */
#define MPC_REGION_ADDR(addr)           ((uint32)(addr) >> 12U)

/** \brief The maximum number of regions for the ROM memory port. */
#define FIREWALL_MPC_ROM_MAXREGION      (1U)
/** \brief The maximum number of regions for the RAM memory port. */
#define FIREWALL_MPC_RAM_MAXREGION      (8U)
/** \brief The maximum number of regions for the DRAM memory port. */
#define FIREWALL_MPC_DRAM_MAXREGION     (16U)
/** \brief The maximum number of regions for the XSPI memory port. */
#define FIREWALL_MPC_XSPI_MAXREGION     (16U)
/** \brief The maximum number of regions for the MB memory port. */
#define FIREWALL_MPC_MB_MAXREGION       (8U)
/** \brief The maximum number of regions for the VIC memory port. */
#define FIREWALL_MPC_VIC_MAXREGION      (1U)
/** \brief The maximum number of regions for the CR5 memory port. */
#define FIREWALL_MPC_CR5_MAXREGION      (8U)
/** \brief The maximum number of regions for the SEIP memory port. */
#define FIREWALL_MPC_SEIP_MAXREGION     (8U)
/** \brief The maximum number of regions for the GAMA memory port. */
#define FIREWALL_MPC_GAMA_MAXREGION     (8U)

/** \brief The address offset of the interrupt register of the specified memory port. */
#define MPC_FUNC_PORT_ADDR_SIZE(portId) ((uint32)((uint32)(portId)*0x400U))
/** \brief The offset address of the ROM mpc register. */
#define FIREWALL_MPC_ROMC_ADDR_OFFSET   ((uint16)0x800U)
/** \brief The offset address of the RAM1C mpc register. */
#define FIREWALL_MPC_RAM1C_ADDR_OFFSET  ((uint16)0xC00U)
/** \brief The offset address of the RAM2C mpc register. */
#define FIREWALL_MPC_RAM2C_ADDR_OFFSET  ((uint16)0x1000U)
/** \brief The offset address of the RAM3C mpc register. */
#define FIREWALL_MPC_RAM3C_ADDR_OFFSET  ((uint16)0x1400U)
/** \brief The offset address of the RAM4C mpc register. */
#define FIREWALL_MPC_RAM4C_ADDR_OFFSET  ((uint16)0x1800U)
/** \brief The offset address of the SDRAMC mpc register. */
#define FIREWALL_MPC_SDRAMC_ADDR_OFFSET ((uint16)0x1C00U)
/** \brief The offset address of the XSPI1A mpc register. */
#define FIREWALL_MPC_XSPI1A_ADDR_OFFSET ((uint16)0x2000U)
/** \brief The offset address of the XSPI1B mpc register. */
#define FIREWALL_MPC_XSPI1B_ADDR_OFFSET ((uint16)0x2400U)
/** \brief The offset address of the XSPI2A mpc register. */
#define FIREWALL_MPC_XSPI2A_ADDR_OFFSET ((uint16)0x2800U)
/** \brief The offset address of the XSPI2B mpc register. */
#define FIREWALL_MPC_XSPI2B_ADDR_OFFSET ((uint16)0x2C00U)
/** \brief The offset address of the MB mpc register. */
#define FIREWALL_MPC_MB_ADDR_OFFSET     ((uint16)0x3000U)
/** \brief The offset address of the VIC1 mpc register. */
#define FIREWALL_MPC_VIC1_ADDR_OFFSET   ((uint16)0x3400U)
/** \brief The offset address of the VIC2A mpc register. */
#define FIREWALL_MPC_VIC2A_ADDR_OFFSET  ((uint16)0x3800U)
/** \brief The offset address of the VIC2B mpc register. */
#define FIREWALL_MPC_VIC2B_ADDR_OFFSET  ((uint16)0x3C00U)
/** \brief The offset address of the VIC3A mpc register. */
#define FIREWALL_MPC_VIC3A_ADDR_OFFSET  ((uint16)0x4000U)
/** \brief The offset address of the VIC3B mpc register. */
#define FIREWALL_MPC_VIC3B_ADDR_OFFSET  ((uint16)0x4400U)
/** \brief The offset address of the CR5SF mpc register. */
#define FIREWALL_MPC_CR5SF_ADDR_OFFSET  ((uint16)0x4C00U)
/** \brief The offset address of the CR5SP0 mpc register. */
#define FIREWALL_MPC_CR5SP0_ADDR_OFFSET ((uint16)0x5000U)
/** \brief The offset address of the CR5SP1 mpc register. */
#define FIREWALL_MPC_CR5SP1_ADDR_OFFSET ((uint16)0x5400U)
/** \brief The offset address of the CR5SX0 mpc register. */
#define FIREWALL_MPC_CR5SX0_ADDR_OFFSET ((uint16)0x5800U)
/** \brief The offset address of the CR5SX1 mpc register. */
#define FIREWALL_MPC_CR5SX1_ADDR_OFFSET ((uint16)0x5C00U)
/** \brief The offset address of the SEIP mpc register. */
#define FIREWALL_MPC_SEIP_ADDR_OFFSET   ((uint16)0x6000U)
/** \brief The offset address of the GAMA mpc register. */
#define FIREWALL_MPC_GAMA_ADDR_OFFSET   ((uint16)0x6400U)

/** \brief The base address of the sf firewall sem error scr. */
#define FIREWALL_SCR_SF_BASE            (0xF0681028U)
/** \brief The bit mask of firewall Sem error. */
#define FIREWALL_SCR_SF_APB_MAC_ENB_BIT (0xFFU << 4)

#ifdef __cplusplus
}
#endif
#endif /* FIREWALL_MPCREG_H */
/* End of file */
