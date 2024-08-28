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
 *  \file     Firewall_PpcReg.h                                                                         *
 * \brief    This file contains registers define for Firewall PPC module.                               *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/25     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifndef FIREWALL_PPC_REG_H
#define FIREWALL_PPC_REG_H

#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                 Private Macro definition                                             *
 *******************************************************************************************************/
/** \brief The offset address of the apbmux1 ppc register. */
#define FIREWALL_PPC_APBMUX_OFFSET ((uint32)0x8000U)
/** \brief The size of the apbmux ppc register. */
#define FIREWALL_PPC_APBMUX_SIZE   ((uint32)0x800U)

/** \brief The offset address of the ppc permission0 register. */
#define FIREWALL_PPC_DOM_PER0_0    ((uint32)0x00U)
/** \brief The size of the ppc permission0 register. */
#define FIREWALL_PPC_DOM_PER0_SIZE ((uint32)0x0CU)
/** \brief The offset address of the ppc permission0 register for differet peripherals or apb regions. */
#define FIREWALL_PPC_DOM_PER0_X(n) ((((uint32)(n))) * FIREWALL_PPC_DOM_PER0_SIZE)
/** \brief The address of the ppc permission0 register for differet peripherals or apb regions. */
#define FIREWALL_PPC_DOMPER0_ADDR(base, apbmuxId, ipId)                                                                \
    ((uint32)(base) + FIREWALL_PPC_APBMUX_OFFSET + (FIREWALL_PPC_APBMUX_SIZE * ((uint32)(apbmuxId))) +                 \
     FIREWALL_PPC_DOM_PER0_X(ipId))

/** \brief The offset address of the ppc permission1 register. */
#define FIREWALL_PPC_DOM_PER1_0    ((uint32)0x04U)
/** \brief The size of the ppc permission1 register. */
#define FIREWALL_PPC_DOM_PER1_SIZE ((uint32)0x0CU)
/** \brief The offset address of the ppc permission1 register for differet peripherals or apb regions. */
#define FIREWALL_PPC_DOM_PER1_X(n) (FIREWALL_PPC_DOM_PER1_0 + ((((uint32)(n))) * FIREWALL_PPC_DOM_PER1_SIZE))
/** \brief The address of the ppc permission1 register for differet peripherals or apb regions. */
#define FIREWALL_PPC_DOMPER1_ADDR(base, apbmuxId, ipId)                                                                \
    ((uint32)(base) + FIREWALL_PPC_APBMUX_OFFSET + (FIREWALL_PPC_APBMUX_SIZE * ((uint32)(apbmuxId))) +                 \
     FIREWALL_PPC_DOM_PER1_X(ipId))

/** \brief The offset address of the ppc permission lock register. */
#define FIREWALL_PPC_DOM_PER_LOCK_0    ((uint32)0x08U)
/** \brief The size of the ppc permission lock register. */
#define FIREWALL_PPC_DOM_PER_LOCK_SIZE ((uint32)0x0CU)
/** \brief The offset address of the ppc permission lock register for differet peripherals or apb regions. */
#define FIREWALL_PPC_DOM_PER_LOCK_X(n)                                                                                 \
    (FIREWALL_PPC_DOM_PER_LOCK_0 + ((((uint32)(n)) * FIREWALL_PPC_DOM_PER_LOCK_SIZE)))
/** \brief The address of the ppc permission lock register for differet peripherals or apb regions. */
#define FIREWALL_PPC_DOM_PER_LOCK_ADDR(base, apbmuxId, ipId)                                                           \
    ((uint32)(base) + FIREWALL_PPC_APBMUX_OFFSET + (FIREWALL_PPC_APBMUX_SIZE * ((uint32)(apbmuxId))) +                 \
     FIREWALL_PPC_DOM_PER_LOCK_X(ipId))

/** \brief The offset address of the start address register. */
#define FIREWALL_PPC_RGN_START_ADDR_0    ((uint32)0x640U)
/** \brief The size of the start address register. */
#define FIREWALL_PPC_RGN_START_ADDR_SIZE ((uint32)0x08U)
/** \brief The offset bit of the start address of the apb region. */
#define FIREWALL_PPC_RGN_START_ADDR_BIT  (0U)
/** \brief The offset address of the start address register for different apb regions. */
#define FIREWALL_PPC_RGN_START_ADDR_X(n)                                                                               \
    (FIREWALL_PPC_RGN_START_ADDR_0 + (((uint32)(n)) * FIREWALL_PPC_RGN_START_ADDR_SIZE))
/** \brief The address of the start address register for different apb regions. */
#define FIREWALL_PPC_RGN_START_REG_ADDR(base, apbmuxId, regionId)                                                      \
    ((uint32)(base) + FIREWALL_PPC_APBMUX_OFFSET + (FIREWALL_PPC_APBMUX_SIZE * ((uint32)(apbmuxId))) +                 \
     FIREWALL_PPC_RGN_START_ADDR_X(regionId))

/** \brief The offset address of the end address register. */
#define FIREWALL_PPC_RGN_END_ADDR_0    ((uint32)0x644U)
/** \brief The size of the end address register. */
#define FIREWALL_PPC_RGN_END_ADDR_SIZE ((uint32)0x08U)
/** \brief The offset bit of the end address of the apb region. */
#define FIREWALL_PPC_RGN_END_ADDR_BIT  (0U)
/** \brief The bit mask of locking the address configuration of the apb region. */
#define FIREWALL_PPC_RGN_END_ADDR_LOCK (1UL << 31U)
/** \brief The offset address of the end address register for different apb regions. */
#define FIREWALL_PPC_RGN_END_ADDR_X(n) (FIREWALL_PPC_RGN_END_ADDR_0 + (((uint32)(n)) * FIREWALL_PPC_RGN_END_ADDR_SIZE))
/** \brief The address of the end address register for different apb regions. */
#define FIREWALL_PPC_RGN_END_REG_ADDR(base, apbmuxId, regionId)                                                        \
    ((uint32)(base) + FIREWALL_PPC_APBMUX_OFFSET + (FIREWALL_PPC_APBMUX_SIZE * ((uint32)(apbmuxId))) +                 \
     FIREWALL_PPC_RGN_END_ADDR_X(regionId))

/** \brief The offset address of the interrupt status register. */
#define FIREWALL_PPC_FUNC_INT_STA_OFFSET      ((uint32)0x6f0U)
/** \brief The bit mask of the register error interrupt. */
#define FIREWALL_PPC_FUNC_INT_STA_REG_RES_ERR (1UL << 1)
/** \brief The bit mask of the peripheral error interrupt. */
#define FIREWALL_PPC_FUNC_INT_STA_PER_RES_ERR (1UL)
/** \brief The address of the interrupt status register for different apbmuxs. */
#define FIREWALL_PPC_FUNC_INT_STA_ADDR(base, apbmuxId)                                                                 \
    ((uint32)(base) + FIREWALL_PPC_APBMUX_OFFSET + (FIREWALL_PPC_APBMUX_SIZE * ((uint32)(apbmuxId))) +                 \
     FIREWALL_PPC_FUNC_INT_STA_OFFSET)

/** \brief The offset address of the interrupt enable register. */
#define FIREWALL_PPC_FUNC_INT_STA_EN_OFFSET      ((uint32)0x6f4U)
/** \brief The bit mask of enabling the register error interrupt. */
#define FIREWALL_PPC_FUNC_INT_STA_EN_REG_RES_ERR (1UL << 1)
/** \brief The bit mask of enabling the peripheral error interrupt. */
#define FIREWALL_PPC_FUNC_INT_STA_EN_PER_RES_ERR (1UL)
/** \brief The address of the interrupt enable register for different apbmuxs. */
#define FIREWALL_PPC_FUNC_INT_STA_EN_ADDR(base, apbmuxId)                                                              \
    ((uint32)(base) + FIREWALL_PPC_APBMUX_OFFSET + (FIREWALL_PPC_APBMUX_SIZE * ((uint32)(apbmuxId))) +                 \
     FIREWALL_PPC_FUNC_INT_STA_EN_OFFSET)

/** \brief The offset address of the interrupt signal register. */
#define FIREWALL_PPC_FUNC_INT_SIG_EN_OFFSET      ((uint32)0x6f8U)
/** \brief The bit mask of enabling the register error interrupt signal. */
#define FIREWALL_PPC_FUNC_INT_SIG_EN_REG_RES_ERR (1UL << 1)
/** \brief The bit mask of enabling the peripheral error interrupt signal. */
#define FIREWALL_PPC_FUNC_INT_SIG_EN_PER_RES_ERR (1UL)
/** \brief The address of the interrupt signal register for different apbmuxs. */
#define FIREWALL_PPC_FUNC_INT_SIG_EN_ADDR(base, apbmuxId)                                                              \
    ((uint32)(base) + FIREWALL_PPC_APBMUX_OFFSET + (FIREWALL_PPC_APBMUX_SIZE * ((uint32)(apbmuxId))) +                 \
     FIREWALL_PPC_FUNC_INT_SIG_EN_OFFSET)

/** \brief The offset address of the response error disable register. */
#define FIREWALL_PPC_PESP_ERR_DIS_OFFSET ((uint32)0x6fcU)
/** \brief The bit mask of locking the response error disable register. */
#define FIREWALL_PPC_PESP_ERR_LOCK       (1UL << 31U)
/** \brief The bit mask of enabling the response error disable feature. */
#define FIREWALL_PPC_PESP_ERR_DIS_ENABLE (1UL)
/** \brief The address of the response error disable register. */
#define FIREWALL_PPC_PESP_ERR_DIS_ADDR(base, apbmuxId)                                                                 \
    ((uint32)(base) + FIREWALL_PPC_APBMUX_OFFSET + (FIREWALL_PPC_APBMUX_SIZE * ((uint32)(apbmuxId))) +                 \
     FIREWALL_PPC_PESP_ERR_DIS_OFFSET)

/** \brief The offset bit of privilege mode permission for domain0. */
#define FIREWALL_PPC_DOM0_PRIVILEGED_BIT (4U)
/** \brief The offset bit of user mode permission for domain0. */
#define FIREWALL_PPC_DOM0_USER_BIT       (6U)
/** \brief The offset bit of privilege mode permission for domain1. */
#define FIREWALL_PPC_DOM1_PRIVILEGED_BIT (12U)
/** \brief The offset bit of user mode permission for domain1. */
#define FIREWALL_PPC_DOM1_USER_BIT       (14U)
/** \brief The offset bit of privilege mode permission for domain2. */
#define FIREWALL_PPC_DOM2_PRIVILEGED_BIT (20U)
/** \brief The offset bit of user mode permission for domain2. */
#define FIREWALL_PPC_DOM2_USER_BIT       (22U)
/** \brief The offset bit of privilege mode permission for domain3. */
#define FIREWALL_PPC_DOM3_PRIVILEGED_BIT (28U)
/** \brief The offset bit of user mode permission for domain3. */
#define FIREWALL_PPC_DOM3_USER_BIT       (30U)
/** \brief The offset bit of privilege mode permission for domain4. */
#define FIREWALL_PPC_DOM4_PRIVILEGED_BIT (4U)
/** \brief The offset bit of user mode permission for domain4. */
#define FIREWALL_PPC_DOM4_USER_BIT       (6U)
/** \brief The offset bit of privilege mode permission for domain5. */
#define FIREWALL_PPC_DOM5_PRIVILEGED_BIT (12U)
/** \brief The offset bit of user mode permission for domain5. */
#define FIREWALL_PPC_DOM5_USER_BIT       (14U)
/** \brief The offset bit of privilege mode permission for domain6. */
#define FIREWALL_PPC_DOM6_PRIVILEGED_BIT (20U)
/** \brief The offset bit of user mode permission for domain6. */
#define FIREWALL_PPC_DOM6_USER_BIT       (22U)
/** \brief The offset bit of privilege mode permission for domain7. */
#define FIREWALL_PPC_DOM7_PRIVILEGED_BIT (28U)
/** \brief The offset bit of user mode permission for domain7. */
#define FIREWALL_PPC_DOM7_USER_BIT       (30U)

/** \brief The bit mask of locking permission configurations. */
#define FIREWALL_PPC_PERMISSION_LOCK     (0xFFUL)
/** \brief The bit mask of enabling the configuration of permissions. */
#define FIREWALL_PPC_RGN_EN              (1UL << 30U)

/** \brief The maximum number of peripherals. */
#define FIREWALL_PPC_IP_MAXNUM           (288U)
/** \brief The maximum number of regions in one apbmux. */
#define FIREWALL_PPC_APBMUXREGION_MAXNUM (16U)
/** \brief The maximum number of regions in PPC module. */
#define FIREWALL_PPC_REGION_MAXNUM       (FIREWALL_PPC_APBMUXREGION_MAXNUM * FIREWALL_PPC_APBMUX_MAXNUM)
/** \brief Support 30 bits address. */
#define FIREWALL_PPC_ADDR(addr)          ((uint32)(addr)&0x3fffffffU)

#ifdef __cplusplus
}
#endif

#endif /* FIREWALL_PPC_REG_H */
/* End of file */
