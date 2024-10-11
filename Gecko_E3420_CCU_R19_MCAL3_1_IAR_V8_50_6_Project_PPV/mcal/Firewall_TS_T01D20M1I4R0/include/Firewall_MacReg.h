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
 *  \file     Firewall_MacReg.h                                                                         *
 * \brief    This file contains registers define for Firewall MAC module.                               *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/25     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef FIREWALL_MACREG_H
#define FIREWALL_MACREG_H
#ifdef __cplusplus
extern "C" {
#endif

#include "Firewall_Type.h"

/** \brief The offset address of the master domain assignment register. */
#define MAC_MDA_OFFSET_ADDR(n)    ((uint32)((uint32)(n)*0x8U))
/** \brief The bit mask of locking the master domain assignment register. */
#define MAC_MDA_LOCK              ((uint32)(0x1UL << 31U))
/** \brief The domain id range is 0 ~ 7. */
#define MAC_MDA_DID_VALUE(did)    ((uint32)(did)&0x7U)

/** \brief The offset address of the master transaction attribute register. */
#define MAC_MAA_ADDR(n)           ((uint32)(0x4U + ((uint32)(n)*0x8U)))
/** \brief The bit mask of locking the master transaction privileged/user attribute. */
#define MAC_MAA_PRI_LOCK          ((uint32)(0x1UL << 5U))
/** \brief The bit mask of locking the master transaction secure/non-secure attribute. */
#define MAC_MAA_SEC_LOCK          ((uint32)(0x1UL << 2U))

/** \brief The offset address of the global manager register. */
#define MAC_ACS_DID               ((uint32)0x200U)
/** \brief The bit mask of locking the global manager configuration. */
#define MAC_ACS_DID_LOCK          ((uint32)(0x1UL << 31U))
/** \brief The domain id range is 0 ~ 7. */
#define MAC_ACS_DID_VALUE(did)    ((uint32)((did)&0x7U))

/** \brief The offset address of the response error disable register. */
#define MAC_RESP_ERR_DIS          ((uint32)0x3FCU)
/** \brief The bit mask of locking the response error disable configurations for MAC/MPC/PPC. */
#define MAC_RESP_ERR_DIS_ALL_LOCK ((uint32)(0x1UL << 31U))
/** \brief The bit mask of locking the response error disable configurations for MAC. */
#define MAC_RESP_ERR_DIS_MAC_LOCK ((uint32)(0x1UL << 30U))
/** \brief The bit mask of disabling the response error feature for MAC/MPC/PPC. */
#define MAC_RESP_ERR_DIS_ALL_DIS  ((uint32)(0x1UL << 1U))
/** \brief The bit mask of disabling the response error feature for MAC. */
#define MAC_RESP_ERR_DIS_MAC_DIS  ((uint32)(0x1UL))

/** \brief The offset address of the MAC interrupt status register. */
#define MAC_FUNC_INT_STA          ((uint32)0x2E0U)
/** \brief The offset address of the MAC interrupt controller register. */
#define MAC_FUNC_INT_STA_EN       ((uint32)0x2E4U)
/** \brief The offset address of the MAC interrupt signal register. */
#define MAC_FUNC_INT_SIG_EN       ((uint32)0x2E8U)



#ifdef __cplusplus
}
#endif

#endif /* FIREWALL_MACREG_H */
/* End of file */
