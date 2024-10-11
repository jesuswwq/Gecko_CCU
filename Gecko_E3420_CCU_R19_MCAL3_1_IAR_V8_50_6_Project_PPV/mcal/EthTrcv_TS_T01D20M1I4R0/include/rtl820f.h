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
 * @file  rtl820f.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL EthTrcv plugins.
 */

#ifndef RTL820F_H
#define RTL820F_H

#ifdef __cplusplus
extern "C" {
#endif

#include "EthTrcv.h"

#define     udelay(x)     Mcu_udelay(x)

#define MII_BMCR        0x00    /* Basic mode control register */
#define MII_BMSR        0x01    /* Basic mode status register  */
#define MII_PHYSID1     0x02    /* PHYS ID 1                   */
#define MII_PHYSID2     0x03    /* PHYS ID 2                   */
#define MII_ADVERTISE   0x04    /* Advertisement control reg   */
#define MII_LPA         0x05    /* Link partner ability reg    */
#define MII_EXPANSION       0x06    /* Expansion register          */

#define MII_PHYSTS          0x10
#define MII_PHYCR           0x19

/* Basic mode control register. */
#define BMCR_RESV           0x003f  /* Unused...                   */
#define BMCR_SPEED1000      0x0040  /* MSB of Speed (1000)         */
#define BMCR_CTST           0x0080  /* Collision test              */
#define BMCR_FULLDPLX       0x0100  /* Full duplex                 */
#define BMCR_ANRESTART      0x0200  /* Auto negotiation restart    */
#define BMCR_ISOLATE        0x0400  /* Isolate data paths from MII */
#define BMCR_PDOWN          0x0800  /* Enable low power state      */
#define BMCR_ANENABLE       0x1000  /* Enable auto negotiation     */
#define BMCR_SPEED100       0x2000  /* Select 100Mbps              */
#define BMCR_LOOPBACK       0x4000  /* TXD loopback bits           */
#define BMCR_RESET          0x8000  /* Reset to default state      */
#define BMCR_SPEED10        0x0000  /* Select 10Mbps               */


#ifndef GENMASK
#define GENMASK(h, l) \
    (((~0UL) - (1UL << (l)) + 1) & (~0UL >> (32 - 1 - (h))))
#endif

#define PHYID_OUI       GENMASK(31,10)
#define PHYID_VENDOR    GENMASK(9,4)
#define PHYID_VERSION   GENMASK(3,0)


#if ETHTRCV_RTL820F_SUPPORTED == STD_ON
extern const EthTrcv_Ops_Type rtl820f_ops;
#endif

#ifdef __cplusplus
}
#endif

#endif
