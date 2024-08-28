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
 * @file  rtl820f.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL EthTrcv plugins.
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Eth.h"
#include "EthTrcv.h"
#include "rtl820f.h"
#include "Mcu_Delay.h"

#define PHY_DBG(...)

#if ETHTRCV_RTL820F_SUPPORTED == STD_ON
#define     usleep(x)     Mcu_udelay(x)

#define ETHTRCV_START_SEC_CODE
#include "EthTrcv_MemMap.h"

/**
 * @description: mii read data from Trcv
 * @return {*}
 * @param {uint8} ctrl_idx
 * @param {uint8} regaddr
 */
static int rtl820f_read(uint8 trcv_idx, uint8 regaddr,uint16* regval)
{
    if(E_OK == Eth_ReadMii(ETHTRCV_CTRL_INDEX(trcv_idx),
            ETHTRCV_PHY_ADDR(trcv_idx), regaddr, regval)){
        return 0;
    }
    return -1;
}
/**
 * @description:  mii write data to TrcvIdx
 * @return {*}
 * @param {uint8} ctrl_idx
 * @param {uint8} regaddr
 * @param {uint16} val
 */
static sint32 rtl820f_write(uint8 trcv_idx, uint8 regaddr, uint16 val)
{
    return Eth_WriteMii(ETHTRCV_CTRL_INDEX(trcv_idx), ETHTRCV_PHY_ADDR(trcv_idx), regaddr, val);
}


static int rtl820f_reset(uint8 trcv_idx)
{
    int timeout = 500,ret;
    uint16 reg_val;

    if (rtl820f_write(trcv_idx, MII_BMCR, BMCR_RESET)) {
        PHY_DBG("PHY reset failed\n");
        return -1;
    }

    while (timeout--) {
        ret = rtl820f_read(trcv_idx, MII_BMCR,&reg_val);

        if (ret < 0) {
            PHY_DBG("BMCR read failed\n");
            return -2;
        }

        if (!(reg_val & BMCR_RESET))
            break;

        udelay(1000);
    }

    if (reg_val & BMCR_RESET) {
        PHY_DBG("PHY reset timeout\n");
        return -3;
    }

    return 0;
}

static sint32 rtl820f_initial_config(uint8 trcv_idx, const EthTrcvConfigType *phycfg)
{
    int ret = 0;

    uint16 reg_val;

    if (rtl820f_reset(trcv_idx)) {
        return -1;
    }

    ret = rtl820f_read(trcv_idx, 0,&reg_val);

    if(ret < 0){
        return -1;
    }

    if (phycfg->DuplexMode == ETHTRCV_DUPLEX_MODE_FULL)
        reg_val |= BIT(8);
    else
        reg_val &= ~BIT(8);

    /* auto negotiation */
    if (phycfg->AutoNegotiation)
        reg_val |= BIT(12);
    else
        reg_val &= ~BIT(12);

    if (phycfg->Speed == TRCV_SPEED_100)
        /* speed */
        reg_val |= BIT(13);
    else if (phycfg->Speed == TRCV_SPEED_10)
        /* speed */
        reg_val &= ~BIT(13);
    else {
        /* default config */
    }

    /* default power down*/
    reg_val &= ~(BIT(11));

    rtl820f_write(trcv_idx, 0, reg_val);

    return 0;
}


static EthTrcv_BaudRateType rtl820f_get_rate(uint8 trcv_idx)
{
    uint16 reg_val;

    int  ret = rtl820f_read(trcv_idx, 0x1a,&reg_val);

    if(ret < 0){
        /* default val is 100Mbits */
        return ETHTRCV_BAUD_RATE_100MBIT;
    }
    if (reg_val) {
        return ETHTRCV_BAUD_RATE_10MBIT;
    } else {
        return ETHTRCV_BAUD_RATE_100MBIT;
    }
}

static EthTrcv_LinkStateType rtl820f_get_link_status(uint8 trcv_idx)
{
    uint16 reg_val;

    int ret = rtl820f_read(trcv_idx, MII_BMSR,&reg_val);

    if(ret < 0){
        /* default status is link down */
        return ETHTRCV_LINK_STATE_DOWN;
    }
    if (reg_val & BIT(2))
        return ETHTRCV_LINK_STATE_ACTIVE;
    else
        return ETHTRCV_LINK_STATE_DOWN;
}

static EthTrcv_DuplexModeType rtl820f_get_duplex_mode(uint8 trcv_idx)
{
    uint16 reg_val;

    int ret  = rtl820f_read(trcv_idx, MII_BMSR,&reg_val);

    if(ret < 0 ){
        /* default is full duplex mode */
        return ETHTRCV_DUPLEX_MODE_FULL;
    }
    if (reg_val & BIT(8))
        return ETHTRCV_DUPLEX_MODE_FULL;
    else
        return ETHTRCV_DUPLEX_MODE_HALF;
}

sint32 rtl820f_set_loopback(uint8 trcv_idx, EthTrcv_PhyLoopbackModeType mode)
{
    uint16 reg_val;

    int ret = rtl820f_read(trcv_idx, MII_BMCR,&reg_val);

    if(ret < 0){
        return -1;
    }

    if (mode == ETHTRCV_PHYLOOPBACK_NONE) {
        reg_val &=  ~(BIT(14));
    } else if (mode == ETHTRCV_PHYLOOPBACK_INTERNAL) {
        reg_val |=  BIT(14);
    } else {
        return -1;
    }

    ret = rtl820f_write(trcv_idx, MII_BMCR, reg_val);

    if (ret) {
        PHY_DBG("Config BMCR failed\n");
        return -1;
    }

    return 0;
}

static sint32 rtl820f_init(uint8 trcv_idx, const EthTrcvConfigType *cfg)
{
    int ret = 0, timeout = 1000;

    ret = rtl820f_initial_config(trcv_idx, cfg);

    if (!ret && cfg->AutoNegotiation) {
        PHY_DBG("Wait for rtl820 link ...\n");

        while (timeout--) {
            ret = rtl820f_get_link_status(trcv_idx);

            if (ret == ETHTRCV_LINK_STATE_ACTIVE) {
                PHY_DBG("Link successfully\n");
                return ret;
            }
        }

        PHY_DBG("Link failed\n");
    }

    return ret;
}

static sint32 rtl820f_get_phy_id(uint8 trcv_idx, uint32 *OrgUniqueIdPtr, \
                                 uint8 *ModelNrPtr, uint8 *RevisionNrPtr)
{
    uint16 reg_val;
    uint32 id_reg;

    int ret = rtl820f_read(trcv_idx, MII_PHYSID1,&reg_val);

    if (ret < 0) {
        PHY_DBG("Read phy id1 error\n");
        return -1;
    }
    id_reg = reg_val;
    id_reg <<= 16;

    ret = rtl820f_read(trcv_idx, MII_PHYSID2,&reg_val);

    if (ret < 0) {
        PHY_DBG("Read phy id2 error\n");
        return -1;
    }
    id_reg |= reg_val;

    *OrgUniqueIdPtr = (PHYID_OUI & id_reg) >> 10 ;
    *ModelNrPtr = (PHYID_VENDOR & reg_val) >> 4;
    *RevisionNrPtr = PHYID_VERSION & reg_val;
    PHY_DBG("PHY_ID:%08x\n", id_reg);
    return 0;
}

static sint32 rtl820f_set_mode(uint8 trcv_idx, EthTrcv_ModeType mode)
{
    uint16 reg_val;

    int ret = rtl820f_read(trcv_idx, 0,&reg_val);

    if(ret < 0){
        return -1;
    }
    if (ETHTRCV_MODE_ACTIVE == mode ) {
        reg_val &= ~BIT(11);
    } else {
        reg_val |= BIT(11);
    }

    if (rtl820f_write(trcv_idx, 0, reg_val)) {
        return -1;
    }

    return 0;
}

#define ETHTRCV_STOP_SEC_CODE
#include "EthTrcv_MemMap.h"

#define ETHTRCV_START_SEC_CONST_UNSPECIFIED
#include "EthTrcv_MemMap.h"

const EthTrcv_Ops_Type rtl820f_ops = {
    .phy_init = rtl820f_init,
    .phy_set_mode = rtl820f_set_mode,
    .phy_get_mode = NULL_PTR,
    .phy_set_wakeup_mode = NULL_PTR,
    .phy_get_wakeup_mode = NULL_PTR,
    .phy_checkwakeup = NULL_PTR,
    .phy_start_auto_negotiation = NULL_PTR,
    .phy_link_state_request = NULL_PTR,
    .phy_get_link_state = rtl820f_get_link_status,
    .phy_get_rate = rtl820f_get_rate,
    .phy_get_duplex_mode = rtl820f_get_duplex_mode,
    .phy_set_test_mode = NULL_PTR,
    .phy_set_loopback_mode = rtl820f_set_loopback,
    .phy_set_txmode = NULL_PTR,
    .phy_trigger_cable_diagnostic = NULL_PTR,
    .phy_get_cable_diagnostics_result = NULL_PTR,
    .phy_get_id = rtl820f_get_phy_id,
    .phy_get_signal_quality = NULL_PTR,
};

#define ETHTRCV_STOP_SEC_CONST_UNSPECIFIED
#include "EthTrcv_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif
