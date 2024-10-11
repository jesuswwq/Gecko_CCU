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
 * @file  dp83848.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL EthTrcv plugins.
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "Eth.h"
#include "EthTrcv.h"
#include "dp83848.h"
#include "Mcu_Delay.h"

#define DP_DBG(...)

#if ETHTRCV_DP83848X_SUPPORTED == STD_ON

#define ETHTRCV_START_SEC_CODE
#include "EthTrcv_MemMap.h"

/**
 * @description: mii read data from Trcv
 * @return {*}
 * @param {uint8} ctrl_idx
 * @param {uint8} regaddr
 */
static int dp83848_read(uint8 trcv_idx, uint8 regaddr,uint16* regval)
{
    if(E_OK == Eth_ReadMii(ETHTRCV_CTRL_INDEX(trcv_idx),
                ETHTRCV_PHY_ADDR(trcv_idx), regaddr,regval)){
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
static sint32 dp83848_write(uint8 trcv_idx, uint8 regaddr, uint16 val)
{
    return Eth_WriteMii(ETHTRCV_CTRL_INDEX(trcv_idx), ETHTRCV_PHY_ADDR(trcv_idx), regaddr, val);
}


static int dp83848_reset(uint8 trcv_idx)
{
    int timeout = 500,ret;
    uint16 reg_val;

    if (dp83848_write(trcv_idx, MII_BMCR, BMCR_RESET)) {
        DP_DBG("PHY reset failed\n");
        return -1;
    }

    while (timeout--) {
        ret = dp83848_read(trcv_idx, MII_BMCR,&reg_val);

        if (ret < 0) {
            DP_DBG("BMCR read failed\n");
            return -2;
        }

        if (!(reg_val & BMCR_RESET))
            break;

        udelay(1000);
    }

    if (timeout == 0) {
        DP_DBG("PHY reset timeout\n");
        return -3;
    }

    return 0;
}

static sint32 dp83848_get_phy_id(uint8 trcv_idx, uint32 *OrgUniqueIdPtr, \
                                 uint8 *ModelNrPtr, uint8 *RevisionNrPtr)
{
    int ret;
    uint32 oui_id;
    uint16 phyid1_reg_val,phyid2_reg_val;

    ret = dp83848_read(trcv_idx, MII_PHYSID1,&phyid1_reg_val);

    if (ret < 0) {
        DP_DBG("Read phy id1 error\n");
        return -1;
    }

    ret = dp83848_read(trcv_idx, MII_PHYSID2,&phyid2_reg_val);

    if (ret < 0) {
        DP_DBG("Read phy id2 error\n");
        return -1;
    }
    oui_id = phyid1_reg_val;
    oui_id <<=3;
    oui_id |= (((phyid2_reg_val >> 10) & 0x1F) << 19 );

    *OrgUniqueIdPtr = oui_id;
    *ModelNrPtr = (PHYID_VENDOR & phyid2_reg_val) >> 4;
    *RevisionNrPtr = PHYID_VERSION & phyid2_reg_val;
    DP_DBG("PHY_ID:%04x %04x\n", phyid1_reg_val,phyid2_reg_val);
    return 0;
}

static sint32 dp83848_config(uint8 trcv_idx, const EthTrcvConfigType *phycfg)
{
    int ret, timeout = 10000;
    uint16  reg_val;

    if (phycfg->AutoNegotiation) {
        ret = dp83848_read(trcv_idx, MII_ADVERTISE,&reg_val);

        if (ret < 0) {
            DP_DBG("Read advertise error\n");
            return ret;
        }

        reg_val |= ADVERTISE_100FULL | ADVERTISE_100HALF |
                   ADVERTISE_10FULL | ADVERTISE_10HALF;
        ret = dp83848_write(trcv_idx, MII_ADVERTISE, reg_val);

        if (ret) {
            DP_DBG("Config advertisement register failed\n");
            return ret;
        }

        ret = dp83848_read(trcv_idx, MII_BMCR,&reg_val);

        if (ret < 0) {
            DP_DBG("Read BMCR failed\n");
            return ret;
        }

        reg_val |= BMCR_ANENABLE;
        ret = dp83848_write(trcv_idx, MII_BMCR, reg_val);

        if (ret)
            DP_DBG("Write BMCR failed\n");
    } else {
        ret = dp83848_read(trcv_idx, MII_BMCR,&reg_val);

        if (ret < 0) {
            DP_DBG("Read BMCR failed\n");
            return ret;
        }

        reg_val &= ~BMCR_ANENABLE;

        if (phycfg->Speed == TRCV_SPEED_10)
            reg_val &= ~BMCR_SPEED100;
        else
            reg_val |= BMCR_SPEED100;

        if (phycfg->DuplexMode == ETHTRCV_DUPLEX_MODE_HALF)
            reg_val &= ~BMCR_FULLDPLX;
        else
            reg_val |= BMCR_FULLDPLX;

        ret = dp83848_write(trcv_idx, MII_BMCR, reg_val);

        if (ret)
            DP_DBG("Write BMCR failed\n");
    }

    if (ret)
        return ret;

    if (phycfg->AutoNegotiation) {
        DP_DBG("Wait for dp83848 link ...\n");

        while (timeout--) {
            ret = dp83848_read(trcv_idx, MII_BMSR,&reg_val);

            if ((ret >= 0) && (reg_val & BMSR_LINK_STATUS))
                break;

            udelay(1);
        }

        if ((ret < 0) || !(reg_val & BMSR_LINK_STATUS)) {
            DP_DBG ("Link failed\n");
            return -1;
        } else
            DP_DBG("Link successfully\n");
    }

    return 0;
}
void phy_dump_reg(uint8 trcv_idx)
{
    uint16 reg_val;
    for (uint8 i = 0; i < 7; i++){
        dp83848_read(trcv_idx, i,&reg_val);
        DP_DBG("%d= 0x%x\n", i, reg_val);
    }
}

static sint32 dp83848_init(uint8 trcv_idx, const EthTrcvConfigType *phycfg)
{
    DP_DBG("%s\n", __FUNCTION__);

    if (dp83848_reset(trcv_idx))
        return -1;

    if (dp83848_config(trcv_idx, phycfg))
        return -2;

    return 0;
}

static sint32 dp83848_set_mode(uint8 trcv_idx, EthTrcv_ModeType mode)
{
    int ret;
    uint16 reg_val;

    ret = dp83848_read(trcv_idx, MII_BMCR,&reg_val);

    if (ret < 0) {
        DP_DBG("Read BMCR failed\n");
        return -1;
    }

    if (ETHTRCV_MODE_ACTIVE == mode ) {
        reg_val &= ~(BMCR_ISOLATE | BMCR_PDOWN);
        ret = dp83848_write(trcv_idx, MII_BMCR, reg_val);

        if (ret) {
            DP_DBG("Config BMCR failed\n");
            return -1;
        }

        ret = dp83848_write(trcv_idx, MII_PHYCR, PHYCR_MDIX_EN | ETHTRCV_PHY_ADDR(trcv_idx));

        if (ret) {
            DP_DBG("Config PHYCR failed\n");
            return -1;
        }
    } else {
        reg_val |= (BMCR_ISOLATE | BMCR_PDOWN);
        ret = dp83848_write(trcv_idx, MII_BMCR, reg_val);

        if (ret) {
            DP_DBG("Config BMCR failed\n");
            return -1;
        }

        ret = dp83848_write(trcv_idx, MII_PHYCR, ~PHYCR_MDIX_EN | ETHTRCV_PHY_ADDR(trcv_idx));

        if (ret) {
            DP_DBG("Config PHYCR failed\n");
            return -1;
        }
    }

    return ret;
}
static EthTrcv_BaudRateType dp83848_get_rate(uint8 trcv_idx)
{
    uint16 reg_val;

    int ret = dp83848_read(trcv_idx, MII_PHYSTS,&reg_val);

    if(ret < 0){
        /* Return an impossible value */
        return ETHTRCV_BAUD_RATE_1000MBIT;
    }
    if (reg_val & PHYSTS_SPEED)
        return  ETHTRCV_BAUD_RATE_10MBIT;
    else
        return ETHTRCV_BAUD_RATE_100MBIT;

}

static EthTrcv_DuplexModeType dp83848_get_duplex(uint8 trcv_idx)
{

    uint16 reg_val;

    int ret = dp83848_read(trcv_idx, MII_PHYSTS,&reg_val);

    if(ret < 0){
        /* Return an default value */
        return ETHTRCV_DUPLEX_MODE_FULL;
    }
    if (reg_val & PHYSTS_DUPLEX)
        return  ETHTRCV_DUPLEX_MODE_FULL;
    else
        return  ETHTRCV_DUPLEX_MODE_HALF;


}

static EthTrcv_LinkStateType dp83848_get_link_state(uint8 trcv_idx)
{
    uint16 reg_val;

    int ret = dp83848_read(trcv_idx, MII_BMSR,&reg_val);

    if(ret < 0){
        /* Return an default value */
        return ETHTRCV_LINK_STATE_DOWN;
    }

    if (reg_val & BMSR_LINK_STATUS) {
        DP_DBG("Link successfully\n");
        return ETHTRCV_LINK_STATE_ACTIVE;
    } else {
        DP_DBG ("Link failed\n");
        return ETHTRCV_LINK_STATE_DOWN;
    }
}
sint32 dp83848_set_loopback_mode(uint8 trcv_idx, EthTrcv_PhyLoopbackModeType mode)
{
    uint16 reg_val;

    int ret = dp83848_read(trcv_idx, MII_BMCR,&reg_val);

    if(ret < 0){
        return -1;
    }
    if (mode == ETHTRCV_PHYLOOPBACK_NONE) {
        reg_val &=  ~BMCR_LOOPBACK;
    } else if (mode == ETHTRCV_PHYLOOPBACK_INTERNAL) {
        reg_val |=  BMCR_LOOPBACK;
    } else {
        return -1;
    }

    ret = dp83848_write(trcv_idx, MII_BMCR, reg_val);

    if (ret) {
        DP_DBG("Config BMCR failed\n");
        return -1;
    }

    ret = dp83848_read(trcv_idx, MII_PHYSTS,&reg_val);

    if(ret < 0){
        return -1;
    }
    if (reg_val & PHYSTS_LOOPBACK) {
        DP_DBG("enbale loopback pass \n");
        return  0;
    } else {
        DP_DBG("enbale loopback mode failed\n");
        return  -1;
    }
}

#define ETHTRCV_STOP_SEC_CODE
#include "EthTrcv_MemMap.h"

#define ETHTRCV_START_SEC_CONST_UNSPECIFIED
#include "EthTrcv_MemMap.h"

const EthTrcv_Ops_Type  dp83848xx_ops = {
    .phy_init = dp83848_init,
    .phy_set_mode = dp83848_set_mode,
    .phy_get_mode = NULL_PTR,
    .phy_set_wakeup_mode = NULL_PTR,
    .phy_get_wakeup_mode = NULL_PTR,
    .phy_checkwakeup = NULL_PTR,
    .phy_start_auto_negotiation = NULL_PTR,
    .phy_link_state_request = NULL_PTR,
    .phy_get_link_state = dp83848_get_link_state,
    .phy_get_rate = dp83848_get_rate,
    .phy_get_duplex_mode = dp83848_get_duplex,
    .phy_set_test_mode = NULL_PTR,
    .phy_set_loopback_mode = dp83848_set_loopback_mode,
    .phy_set_txmode = NULL_PTR,
    .phy_trigger_cable_diagnostic = NULL_PTR,
    .phy_get_cable_diagnostics_result = NULL_PTR,
    .phy_get_id = dp83848_get_phy_id,
    .phy_get_signal_quality = NULL_PTR,
};

#define ETHTRCV_STOP_SEC_CONST_UNSPECIFIED
#include "EthTrcv_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif




