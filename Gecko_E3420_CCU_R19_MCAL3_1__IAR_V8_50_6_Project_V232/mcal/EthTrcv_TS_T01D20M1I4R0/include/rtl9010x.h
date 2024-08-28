/*
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
 * an "AS IS" basis, WITHOUT WARRANTIES OF ANY KIND, either express or implied.
 *
 * You should have received a copy of the License along with this program.
 * If not, see <http://www.semidrive.com/licenses/>.
 */

/**
 * @file  rtl9010x.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL EthTrcv plugins.
 */

#ifndef RTL9010X_H
#define RTL9010X_H

#ifdef __cplusplus
extern "C" {
#endif

#include "EthTrcv.h"

#define MII_BMCR        0x00    /* Basic mode control register */
#define MII_BMSR        0x01    /* Basic mode status register  */
#define MII_PHYSID1     0x02    /* PHYS ID 1                   */
#define MII_PHYSID2     0x03    /* PHYS ID 2                   */


#ifndef GENMASK
#define GENMASK(h, l) \
    (((~0UL) - (1UL << (l)) + 1) & (~0UL >> (32 - 1 - (h))))
#endif

#define PHYID_OUI       GENMASK(31,10)
#define PHYID_VENDOR    GENMASK(9,4)
#define PHYID_VERSION   GENMASK(3,0)

#define PHY_LOOPBACK   (0x01<<14)

#define PHYSR_SPEED   GENMASK(5,4)
#define PHYSR_SPEED_OFFSET   4
#define PHYSR_SPEED_100M   1
#define PHYSR_SPEED_1000M  2


#if ETHTRCV_RTL9010X_SUPPORTED == STD_ON
extern const EthTrcv_Ops_Type rtl9010x_ops;
#endif

#ifdef __cplusplus
}
#endif

#endif

