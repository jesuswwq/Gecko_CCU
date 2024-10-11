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
 *  \file     Firewall_DioReg.h                                                                         *
 * \brief    This file contains registers define for Firewall DIO module.                               *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/25     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef FIREWALL_DIOREG_H
#define FIREWALL_DIOREG_H
#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                 Private Macro definition                                             *
 *******************************************************************************************************/
/** \brief The offset address of the dio permission0 register. */
#define FIREWALL_DIO_DOM_PER0N_0           ((uint32)0x00U)
/** \brief The size of the dio permission0 register. */
#define FIREWALL_DIO_DOM_PER0N_SIZE        ((uint32)0x0CU)
/** \brief The offset address of the dio permission0 register for different cores. */
#define FIREWALL_DIO_DOM_PER0N_ADDR(n)     (FIREWALL_DIO_DOM_PER0N_0 + ((n)*FIREWALL_DIO_DOM_PER0N_SIZE))

/** \brief The offset address of the dio permission1 register. */
#define FIREWALL_DIO_DOM_PER1N_0           ((uint32)0x04U)
/** \brief The size of the dio permission1 register. */
#define FIREWALL_DIO_DOM_PER1N_SIZE        ((uint32)0x0CU)
/** \brief The offset address of the dio permission1 register for different cores. */
#define FIREWALL_DIO_DOM_PER1N_ADDR(n)     (FIREWALL_DIO_DOM_PER1N_0 + ((n)*FIREWALL_DIO_DOM_PER1N_SIZE))

/** \brief The offset address of the dio permission lock register. */
#define FIREWALL_DIO_DOM_PER_LOCKN_0       ((uint32)0x08U)
/** \brief The size of the dio permission lock register. */
#define FIREWALL_DIO_DOM_PER_LOCKN_SIZE    ((uint32)0x0CU)
/** \brief The bit mask of locking the dio permission. */
#define FIREWALL_DIO_DOM_PER_LOCK          (0xFFUL)
/** \brief The offset address of the dio permission lock register for different cores. */
#define FIREWALL_DIO_DOM_PER_LOCKN_ADDR(n) (FIREWALL_DIO_DOM_PER_LOCKN_0 + ((n)*FIREWALL_DIO_DOM_PER_LOCKN_SIZE))

/** \brief The offset address of the dio core select register. */
#define FIREWALL_DIO_DGSELN_0              ((uint32)0x140U)
/** \brief The size of the dio core select register. */
#define FIREWALL_DIO_DGSELN_SIZE           ((uint32)0x04U)
/** \brief The offset bit of the dio core select. */
#define FIREWALL_DIO_RGN_DGSEL_BIT         (1U)
/** \brief The bit mask of enabling the dio permission control. */
#define FIREWALL_DIO_RGN_EN                (1UL)
/** \brief The bit mask of locking the dio permission control. */
#define FIREWALL_DIO_RGN_LOCK              (1UL << 31U)
/** \brief The offset address of the dio core select register for different pin channels. */
#define FIREWALL_DIO_DGSELN_ADDR(n)        (FIREWALL_DIO_DGSELN_0 + ((n)*FIREWALL_DIO_DGSELN_SIZE))

/** \brief The offset bit of privilege mode permission for domain0. */
#define FIREWALL_DIO_DOM0_PRIVILEGED_BIT   (4U)
/** \brief The offset bit of user mode permission for domain0. */
#define FIREWALL_DIO_DOM0_USER_BIT         (6U)
/** \brief The offset bit of privilege mode permission for domain1. */
#define FIREWALL_DIO_DOM1_PRIVILEGED_BIT   (12U)
/** \brief The offset bit of user mode permission for domain1. */
#define FIREWALL_DIO_DOM1_USER_BIT         (14U)
/** \brief The offset bit of privilege mode permission for domain2. */
#define FIREWALL_DIO_DOM2_PRIVILEGED_BIT   (20U)
/** \brief The offset bit of user mode permission for domain2. */
#define FIREWALL_DIO_DOM2_USER_BIT         (22U)
/** \brief The offset bit of privilege mode permission for domain3. */
#define FIREWALL_DIO_DOM3_PRIVILEGED_BIT   (28U)
/** \brief The offset bit of user mode permission for domain3. */
#define FIREWALL_DIO_DOM3_USER_BIT         (30U)
/** \brief The offset bit of privilege mode permission for domain4. */
#define FIREWALL_DIO_DOM4_PRIVILEGED_BIT   (4U)
/** \brief The offset bit of user mode permission for domain4. */
#define FIREWALL_DIO_DOM4_USER_BIT         (6U)
/** \brief The offset bit of privilege mode permission for domain5. */
#define FIREWALL_DIO_DOM5_PRIVILEGED_BIT   (12U)
/** \brief The offset bit of user mode permission for domain5. */
#define FIREWALL_DIO_DOM5_USER_BIT         (14U)
/** \brief The offset bit of privilege mode permission for domain6. */
#define FIREWALL_DIO_DOM6_PRIVILEGED_BIT   (20U)
/** \brief The offset bit of user mode permission for domain6. */
#define FIREWALL_DIO_DOM6_USER_BIT         (22U)
/** \brief The offset bit of privilege mode permission for domain7. */
#define FIREWALL_DIO_DOM7_PRIVILEGED_BIT   (28U)
/** \brief The offset bit of user mode permission for domain7. */
#define FIREWALL_DIO_DOM7_USER_BIT         (30U)

/** \brief The id of SF domain in dio module. */
#define FIREWALL_DIO_DGSEL_SF              (0U)
/** \brief The id of SP0 domain in dio module. */
#define FIREWALL_DIO_DGSEL_SP0             (1U)
/** \brief The id of SP1 domain in dio module. */
#define FIREWALL_DIO_DGSEL_SP1             (2U)
/** \brief The id of SX0 domain in dio module. */
#define FIREWALL_DIO_DGSEL_SX0             (3U)
/** \brief The id of SX1 domain in dio module. */
#define FIREWALL_DIO_DGSEL_SX1             (4U)

/** \brief The maximum number of cores. */
#define FIREWALL_DIO_CORE_MAXNUM           (5U)
/** \brief The maximum number of dio pin channels. */
#define FIREWALL_DIO_CHANNEL_MAXNUM        (214U)
/** \brief The maximum number of sf dio pin channels. */
#define FIREWALL_DIO_SF_MAXNUM             (0x87U)
/** \brief The maximum number of ap dio pin channels. */
#define FIREWALL_DIO_AP_MAXNUM             (0x4FU)

#ifdef __cplusplus
}
#endif
#endif /* FIREWALL_DIOREG_H */
/* End of file */
