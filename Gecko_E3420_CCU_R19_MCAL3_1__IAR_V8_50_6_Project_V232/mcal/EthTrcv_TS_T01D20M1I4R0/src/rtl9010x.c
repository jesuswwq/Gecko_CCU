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
 * @file  rtl9010x.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL EthTrcv plugins.
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "Eth.h"
#include "EthTrcv.h"
#include "rtl9010x.h"
#include "Mcu_Delay.h"

#define PHY_DBG(...)

#if ETHTRCV_RTL9010X_SUPPORTED == STD_ON
#define     usleep(x)     Mcu_udelay(x)

#define ETHTRCV_START_SEC_CODE
#include "EthTrcv_MemMap.h"

/**
 * @description: mii read data from Trcv
 * @return {*}
 * @param {uint8} ctrl_idx
 * @param {uint8} regaddr
 */
static int rtl9010_read(uint8 trcv_idx, uint8 regaddr,uint16* reg_val)
{
    if( E_OK == Eth_ReadMii(ETHTRCV_CTRL_INDEX(trcv_idx),
        ETHTRCV_PHY_ADDR(trcv_idx), regaddr, reg_val)){
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
static sint32 rtl9010_write(uint8 trcv_idx, uint8 regaddr, uint16 val)
{
    return Eth_WriteMii(ETHTRCV_CTRL_INDEX(trcv_idx), ETHTRCV_PHY_ADDR(trcv_idx), regaddr, val);
}


static int rtl9010_initial_config(uint8 trcv_idx)
{
    int ret = 0;
    int timer = 2000; // set a 2ms timer
    uint16 reg_val;

    // PHY Parameter Start //
    rtl9010_write(trcv_idx, 31, 0x0BC4);
    rtl9010_write(trcv_idx, 21, 0x16FE);

    rtl9010_write(trcv_idx, 27, 0xB820);
    rtl9010_write(trcv_idx, 28, 0x0010);
    rtl9010_write(trcv_idx, 27, 0xB830);
    rtl9010_write(trcv_idx, 28, 0x8000);
    rtl9010_write(trcv_idx, 27, 0xB800);

    ret = rtl9010_read(trcv_idx, 28,&reg_val);

    if(ret < 0){
        return -1;
    }
    while (!(reg_val & 0x0040)) {
        rtl9010_write(trcv_idx, 27, 0xB800);

        ret = rtl9010_read(trcv_idx, 28,&reg_val);

        if(ret < 0){
            return -1;
        }

        timer--;

        if (timer == 0) {
            return -1;
        }
    }

    rtl9010_write(trcv_idx, 27, 0x8020);
    rtl9010_write(trcv_idx, 28, 0x9100);
    rtl9010_write(trcv_idx, 27, 0xB82E);
    rtl9010_write(trcv_idx, 28, 0x0001);

    rtl9010_write(trcv_idx, 27, 0xB820);
    rtl9010_write(trcv_idx, 28, 0x0290);
    rtl9010_write(trcv_idx, 27, 0xA012);
    rtl9010_write(trcv_idx, 28, 0x0000);
    rtl9010_write(trcv_idx, 27, 0xA014);
    rtl9010_write(trcv_idx, 28, 0xD700);
    rtl9010_write(trcv_idx, 28, 0x880F);
    rtl9010_write(trcv_idx, 28, 0x262D);
    rtl9010_write(trcv_idx, 27, 0xA01A);
    rtl9010_write(trcv_idx, 28, 0x0000);
    rtl9010_write(trcv_idx, 27, 0xA000);
    rtl9010_write(trcv_idx, 28, 0x162C);
    rtl9010_write(trcv_idx, 27, 0xB820);
    rtl9010_write(trcv_idx, 28, 0x0210);
    rtl9010_write(trcv_idx, 27, 0xB82E);
    rtl9010_write(trcv_idx, 28, 0x0000);
    rtl9010_write(trcv_idx, 27, 0x8020);
    rtl9010_write(trcv_idx, 28, 0x0000);
    rtl9010_write(trcv_idx, 27, 0xB820);
    rtl9010_write(trcv_idx, 28, 0x0000);

    rtl9010_write(trcv_idx, 27, 0xB800);

    ret = rtl9010_read(trcv_idx, 28,&reg_val);

    if(ret < 0){
        return -1;
    }

    timer = 2000; // set a 2ms timer

    while (reg_val & 0x0040) {
        rtl9010_write(trcv_idx, 27, 0xB800);

        ret = rtl9010_read(trcv_idx, 28,&reg_val);

        if(ret < 0){
            return -1;
        }

        timer--;

        if (timer == 0) {
            return -2;
        }
    }

    // End //

    /* Set rx delay to 2ns. */
    rtl9010_write(trcv_idx, 27, 0xD04A);
    rtl9010_write(trcv_idx, 28, 7);

    /* Set tx delay to 2ns. */
    rtl9010_write(trcv_idx, 27, 0xD084);
    rtl9010_write(trcv_idx, 28, 0x4007);

    rtl9010_write(trcv_idx, 0, 0x8000); // PHY soft-reset
    reg_val = 0;

    while (reg_val != 0x0140) {   // Check soft-reset complete
        ret = rtl9010_read(trcv_idx, 0,&reg_val);

        if(ret < 0){
            return -1;
        }
    }
    ret = rtl9010_read(trcv_idx, 0,&reg_val);
    if(ret < 0){
        return -1;
    }

    PHY_DBG("BMCR%08x\n", reg_val);
    reg_val |= 0x01 << 11;
    rtl9010_write(trcv_idx, 0, reg_val);
    return 0;
}

static int rtl9010_initial_with_nway_config(uint8 trcv_idx)
{
    int ret = 0;
    int timer = 2000; // set a 2ms timer
    uint16 reg_val;

    // PHY Parameter Start //
    rtl9010_write(trcv_idx, 31, 0x0A54);
    rtl9010_write(trcv_idx, 21, 0xFA06);
    rtl9010_write(trcv_idx, 31, 0x0BC4);
    rtl9010_write(trcv_idx, 21, 0x16FE);

    rtl9010_write(trcv_idx, 27, 0xB820);
    rtl9010_write(trcv_idx, 28, 0x0010);
    rtl9010_write(trcv_idx, 27, 0xB830);
    rtl9010_write(trcv_idx, 28, 0x8000);
    rtl9010_write(trcv_idx, 27, 0xB800);

    ret = rtl9010_read(trcv_idx, 28,&reg_val);

    if(ret < 0 ){
        return -1;
    }

    while (!(reg_val & 0x0040)) {
        rtl9010_write(trcv_idx, 27, 0xB800);

        ret = rtl9010_read(trcv_idx, 28,&reg_val);

        if(ret < 0 ){
            return -1;
        }

        timer--;

        if (timer == 0) {
            return -1;
        }
    }

    rtl9010_write(trcv_idx, 27, 0x8020);
    rtl9010_write(trcv_idx, 28, 0x9100);
    rtl9010_write(trcv_idx, 27, 0xB82E);
    rtl9010_write(trcv_idx, 28, 0x0001);

    rtl9010_write(trcv_idx, 27, 0xB820);
    rtl9010_write(trcv_idx, 28, 0x0290);
    rtl9010_write(trcv_idx, 27, 0xA012);
    rtl9010_write(trcv_idx, 28, 0x0000);
    rtl9010_write(trcv_idx, 27, 0xA014);
    rtl9010_write(trcv_idx, 28, 0x2C03);
    rtl9010_write(trcv_idx, 28, 0x2C07);
    rtl9010_write(trcv_idx, 28, 0x2C0B);
    rtl9010_write(trcv_idx, 28, 0x6054);
    rtl9010_write(trcv_idx, 28, 0xA701);
    rtl9010_write(trcv_idx, 28, 0xD500);
    rtl9010_write(trcv_idx, 28, 0x2108);
    rtl9010_write(trcv_idx, 28, 0x4054);
    rtl9010_write(trcv_idx, 28, 0x8701);
    rtl9010_write(trcv_idx, 28, 0xA74A);
    rtl9010_write(trcv_idx, 28, 0x20DE);
    rtl9010_write(trcv_idx, 28, 0xD700);
    rtl9010_write(trcv_idx, 28, 0x880F);
    rtl9010_write(trcv_idx, 28, 0x262D);
    rtl9010_write(trcv_idx, 27, 0xA01A);
    rtl9010_write(trcv_idx, 28, 0x0000);
    rtl9010_write(trcv_idx, 27, 0xA004);
    rtl9010_write(trcv_idx, 28, 0x062C);
    rtl9010_write(trcv_idx, 27, 0xA002);
    rtl9010_write(trcv_idx, 28, 0x00DD);
    rtl9010_write(trcv_idx, 27, 0xA000);
    rtl9010_write(trcv_idx, 28, 0x7107);
    rtl9010_write(trcv_idx, 27, 0xB820);
    rtl9010_write(trcv_idx, 28, 0x0210);

    rtl9010_write(trcv_idx, 27, 0xB82E);
    rtl9010_write(trcv_idx, 28, 0x0000);
    rtl9010_write(trcv_idx, 27, 0x8020);
    rtl9010_write(trcv_idx, 28, 0x0000);
    rtl9010_write(trcv_idx, 27, 0xB820);
    rtl9010_write(trcv_idx, 28, 0x0000);

    rtl9010_write(trcv_idx, 27, 0xB800);

    ret = rtl9010_read(trcv_idx, 28,&reg_val);

    if(ret < 0 ){
        return -1;
    }

    timer = 2000; // set a 2ms timer

    while (reg_val & 0x0040) {
        rtl9010_write(trcv_idx, 27, 0xB800);
        ret = rtl9010_read(trcv_idx, 28,&reg_val);

        if(ret < 0 ){
            return -1;
        }

        timer--;

        if (timer == 0) {
            return -2;
        }
    }

    // End //

    /* Set rx delay to 2ns. */
    rtl9010_write(trcv_idx, 27, 0xD04A);
    rtl9010_write(trcv_idx, 28, 7);

    /* Set tx delay to 2ns. */
    rtl9010_write(trcv_idx, 27, 0xD084);
    rtl9010_write(trcv_idx, 28, 0x4007);

    rtl9010_write(trcv_idx, 0, 0x8000); // PHY soft-reset
    reg_val = 0;

    while (reg_val != 0x0140) {   // Check soft-reset complete
        ret = rtl9010_read(trcv_idx, 0,&reg_val);

        if(ret < 0 ){
            return -1;
        }
    }

    return 0;
}
static EthTrcv_BaudRateType rtl9010x_get_rate(uint8 trcv_idx)
{
    uint16 reg_val;

    int ret = rtl9010_read(trcv_idx, 0x1a,&reg_val);

    if(ret){
        /* default 1000Mbps */
        return ETHTRCV_BAUD_RATE_1000MBIT;
    }
    reg_val &= PHYSR_SPEED;
    reg_val = reg_val >> PHYSR_SPEED_OFFSET;

    if (reg_val == PHYSR_SPEED_100M) {
        return ETHTRCV_BAUD_RATE_100MBIT;
    } else {
        return ETHTRCV_BAUD_RATE_1000MBIT;
    }
}

static EthTrcv_LinkStateType rtl9010_get_link_status(uint8 trcv_idx)
{
    uint16 reg_val;
    int locok = 0;
    int remok = 0;
    int link_status = 0;
    int pcs_status;
    int pcs_status_checkOK = 0;
    EthTrcv_BaudRateType speed;

    int ret = rtl9010_read(trcv_idx, 1,&reg_val);
    ret = rtl9010_read(trcv_idx, 1,&reg_val);//Read twice for current link status.

    if(ret < 0){
        /* default is link down */
        return ETHTRCV_LINK_STATE_DOWN;
    }

    link_status = (reg_val & 0x0004);

    rtl9010_write(trcv_idx, 31, 0x0A60);

    ret = rtl9010_read(trcv_idx, 16,&reg_val);//Read twice for current link status.
    if(ret < 0){
        /* default is link down */
        return ETHTRCV_LINK_STATE_DOWN;
    }

    pcs_status = (reg_val & 0x00FF);
    /* dummy read */
    rtl9010_read(trcv_idx, 1,&reg_val);

    speed = rtl9010x_get_rate(trcv_idx);

    if (speed == ETHTRCV_BAUD_RATE_1000MBIT) {
        ret = rtl9010_read(trcv_idx, 10,&reg_val);//Read twice for current link status.
        if(ret < 0){
            /* default is link down */
            return ETHTRCV_LINK_STATE_DOWN;
        }
        locok = ((reg_val & 0x2000) == 0x2000);
        remok = ((reg_val & 0x1000) == 0x1000);

        if (pcs_status == 0x0037)
            pcs_status_checkOK = 1;
    } else {
        rtl9010_write(trcv_idx, 31, 0x0A64);
        ret = rtl9010_read(trcv_idx, 23,&reg_val);//Read twice for current link status.
        if(ret < 0){
            /* default is link down */
            return ETHTRCV_LINK_STATE_DOWN;
        }
        locok = ((reg_val & 0x0004) == 0x0004);
        remok = ((reg_val & 0x0400) == 0x0400);

        if (pcs_status == 0x0044)
            pcs_status_checkOK = 1;
    }

    PHY_DBG("link_status = 0x%04X\r\n", link_status);
    PHY_DBG("locok = 0x%04X\r\n", locok);
    PHY_DBG("remok = 0x%04X\r\n", remok);
    PHY_DBG("pcs_status = 0x%04X\r\n", pcs_status);

    if ((link_status == 0x0004) & (locok) & (remok) &
        pcs_status_checkOK)
        return ETHTRCV_LINK_STATE_ACTIVE;
    else
        return ETHTRCV_LINK_STATE_DOWN;
}

static EthTrcv_DuplexModeType rtl9010_get_duplex_mode(uint8 trcv_idx)
{
    (void)trcv_idx;
    return ETHTRCV_DUPLEX_MODE_FULL;
}

sint32 rtl9010_set_loopback(uint8 trcv_idx, EthTrcv_PhyLoopbackModeType mode)
{
    uint16 reg_val;

    int ret = rtl9010_read(trcv_idx, MII_BMCR,&reg_val);

    if(ret < 0){
        return -1;
    }
    if (mode == ETHTRCV_PHYLOOPBACK_NONE) {
        reg_val &=  ~PHY_LOOPBACK;
    } else if (mode == ETHTRCV_PHYLOOPBACK_INTERNAL) {
        reg_val |=  PHY_LOOPBACK;
    } else {
        return -1;
    }

    ret = rtl9010_write(trcv_idx, MII_BMCR, reg_val);

    if (ret) {
        PHY_DBG("Config BMCR failed\n");
        return -1;
    }

    return 0;
}

static sint32 rtl9010_init(uint8 trcv_idx, const EthTrcvConfigType *cfg)
{
    int ret = 0, timeout = 1000;
    uint16 reg_val;

    if (cfg->AutoNegotiation)
        ret = rtl9010_initial_with_nway_config(trcv_idx);
    else {
        ret = rtl9010_initial_config(trcv_idx);
        ret = rtl9010_read(trcv_idx, 9,&reg_val);
        if(ret < 0){
            return -1;
        }
        if (cfg->ConnNegMode == TRCV_CONN_NEG_SLAVE)
            reg_val &= ~(0x1 << 11);
        else
            reg_val |= 0x1 << 11;

        rtl9010_write(trcv_idx, 9, reg_val);
    }

    if (!ret && cfg->AutoNegotiation) {
        PHY_DBG("Wait for rtl9010 link ...\n");

        while (timeout--) {
            ret = rtl9010_get_link_status(trcv_idx);

            if (ret == ETHTRCV_LINK_STATE_ACTIVE) {
                PHY_DBG("Link successfully\n");
                return ret;
            }
        }

        PHY_DBG("Link failed\n");
    }

    return ret;
}

static sint32 rtl9010x_get_phy_id(uint8 trcv_idx, uint32 *OrgUniqueIdPtr, \
                                  uint8 *ModelNrPtr, uint8 *RevisionNrPtr)
{
    uint16 reg_val;
    uint32 id;

    int ret = rtl9010_read(trcv_idx, MII_PHYSID1,&reg_val);

    if (ret < 0) {
        PHY_DBG("Read phy id1 error\n");
        return -1;
    }
    id = reg_val << 16;

    ret = rtl9010_read(trcv_idx, MII_PHYSID2,&reg_val);

    if (ret < 0) {
        PHY_DBG("Read phy id2 error\n");
        return -1;
    }

    id |= reg_val;

    *OrgUniqueIdPtr = (PHYID_OUI & id) >> 10 ;
    *ModelNrPtr = (PHYID_VENDOR & id) >> 4;
    *RevisionNrPtr = PHYID_VERSION & id;
    PHY_DBG("PHY_ID:%08x\n", id);
    return 0;
}

sint32 rtl9010_config_init(uint8 trcv_idx, const EthTrcvConfigType *cfg)
{
    return rtl9010_init(trcv_idx, cfg);
}
static sint32 rtl9010_set_mode(uint8 trcv_idx, EthTrcv_ModeType mode)
{
    uint16 reg_val;

    int ret = rtl9010_read(trcv_idx, 0,&reg_val);

    if(ret < 0){
        return -1;
    }

    PHY_DBG("BMCR%08x\n", reg_val);

    if (ETHTRCV_MODE_ACTIVE == mode ) {
        reg_val &= ~(0x01 << 11);
    } else {
        reg_val |= 0x01 << 11;
    }

    if (rtl9010_write(trcv_idx, 0, reg_val)) {
        return -1;
    }

    return 0;
}

#define ETHTRCV_STOP_SEC_CODE
#include "EthTrcv_MemMap.h"

#define ETHTRCV_START_SEC_CONST_UNSPECIFIED
#include "EthTrcv_MemMap.h"

const EthTrcv_Ops_Type rtl9010x_ops = {
    .phy_init = rtl9010_config_init,
    .phy_set_mode = rtl9010_set_mode,
    .phy_get_mode = NULL_PTR,
    .phy_set_wakeup_mode = NULL_PTR,
    .phy_get_wakeup_mode = NULL_PTR,
    .phy_checkwakeup = NULL_PTR,
    .phy_start_auto_negotiation = NULL_PTR,
    .phy_link_state_request = NULL_PTR,
    .phy_get_link_state = rtl9010_get_link_status,
    .phy_get_rate = rtl9010x_get_rate,
    .phy_get_duplex_mode = rtl9010_get_duplex_mode,
    .phy_set_test_mode = NULL_PTR,
    .phy_set_loopback_mode = rtl9010_set_loopback,
    .phy_set_txmode = NULL_PTR,
    .phy_trigger_cable_diagnostic = NULL_PTR,
    .phy_get_cable_diagnostics_result = NULL_PTR,
    .phy_get_id = rtl9010x_get_phy_id,
    .phy_get_signal_quality = NULL_PTR,
};

#define ETHTRCV_STOP_SEC_CONST_UNSPECIFIED
#include "EthTrcv_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif
