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
 * @file  q21xx.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL EthTrcv plugins.
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "Eth.h"
#include "EthTrcv.h"
#include "q21xx.h"
#include "Mcu_Delay.h"


#define     msleep(x)     Mcu_udelay(1000*(x))

#if ETHTRCV_Q21XX_SUPPORTED == STD_ON

#define ETHTRCV_START_SEC_CODE
#include "EthTrcv_MemMap.h"

/**
 * @description: mii read data from TrcvIdx
 * @return {*}
 * @param {uint8} ctrl_idx
 * @param {uint8} devaddr
 * @param {uint32} regaddr
 */
static uint16 ma211x_read(uint8 trcv_idx, uint8 devaddr, uint32 regaddr)
{
    return (Eth_Mdio_Read(ETHTRCV_CTRL_INDEX(trcv_idx), \
                          ETHTRCV_PHY_ADDR(trcv_idx), devaddr, regaddr));
}
/**
 * @description:  mii write data to TrcvIdx
 * @return {*}
 * @param {uint8} ctrl_idx
 * @param {uint8} devaddr
 * @param {uint32} regaddr
 * @param {uint16} val
 */
static sint32 ma211x_write(uint8 trcv_idx, uint8 devaddr, uint32 regaddr, uint16 val)
{
    if (Eth_Mdio_Write(ETHTRCV_CTRL_INDEX(trcv_idx),
                       ETHTRCV_PHY_ADDR(trcv_idx), devaddr, regaddr, val)) {
        return -1;
    }

    return 0;
}
/**
 * @description: get autonego status
 * @param  {*}
 * @return 1 enable autonego;0 disable autonego
 * @param {uint8 } TrcvIdx
 */
static sint32 ma211x_get_autonego_enable(uint8  TrcvIdx)
{
    return (0x0 != (ma211x_read(TrcvIdx, 7, 0x0200) & 0x1000));
}
/**
 * @description: set autonego status
 * @return {*}
 * @param {uint8 } TrcvIdx
 * @param {sint32} is_enable
 */
static void ma211x_set_autonego_enalbe(uint8  TrcvIdx, sint32 is_enable)
{
    if (is_enable)
        ma211x_write(TrcvIdx, 7, 0x0200, 0x1200); //an_enalbe, an_restart
    else
        ma211x_write(TrcvIdx, 7, 0x0200, 0);
}
static EthTrcv_BaudRateType q21xx_get_rate(uint8 TrcvIdx)
{
    uint32 ret;

    if (ma211x_get_autonego_enable(TrcvIdx))
        ret = (ma211x_read(TrcvIdx, 7, 0x801a) & 0x4000) >> 14;
    else
        ret = ma211x_read(TrcvIdx, 1, 0x0834) & 0x0001;

    if (ret)
        return ETHTRCV_BAUD_RATE_1000MBIT;
    else
        return ETHTRCV_BAUD_RATE_100MBIT;
}
/**
 * @description:  get link  speed
 * @return  1 1000MB; 0 100MB
 * @param {uint8 } TrcvIdx
 */
static sint32 ma211x_get_speed(uint8  TrcvIdx)
{
    if (ma211x_get_autonego_enable(TrcvIdx))
        return ((ma211x_read(TrcvIdx, 7, 0x801a) & 0x4000) >> 14);
    else
        return (ma211x_read(TrcvIdx, 1, 0x0834) & 0x0001);
}
/**
 * @description: set autonego role
 * @return {*}
 * @param {uint8 } TrcvIdx
 * @param {sint32} is_master
 */
static sint32 ma211x_set_master(uint8  TrcvIdx, sint32 is_master)
{
    uint16 data = ma211x_read(TrcvIdx, 1, 0x0834);

    if (is_master == TRCV_CONN_NEG_MASTER)
        data |= 0x4000;
    else
        data &= 0xBFFF;

    return ma211x_write(TrcvIdx, 1, 0x0834, data);
}

static EthTrcv_LinkStateType maq21xx_get_link_state(uint8 TrcvIdx)
{
    uint32 data;

    if (ma211x_get_speed(TrcvIdx) == MRVL_88Q2112_1000BASE_T1) {
        data = ma211x_read(TrcvIdx, 3, 0x0901);
        data = ma211x_read(TrcvIdx, 3, 0x0901);
    } else
        data = ma211x_read(TrcvIdx, 3, 0x8109);

    if (0x4 == (data & 0x4))
        return ETHTRCV_LINK_STATE_ACTIVE;
    else
        return ETHTRCV_LINK_STATE_DOWN;
}

static sint32 ma211x_ge_init(uint8  TrcvIdx)
{
    uint16 data;

    ma211x_write(TrcvIdx, 1, 0x0900, 0x4000);

    data = ma211x_read(TrcvIdx, 1, 0x0834);
    data = (data & 0xFFF0) | 0x0001;
    ma211x_write(TrcvIdx, 1, 0x0834, data);

    ma211x_write(TrcvIdx, 3, 0xFFE4, 0x07B5);
    ma211x_write(TrcvIdx, 3, 0xFFE4, 0x06B6);
    msleep(100);

    ma211x_write(TrcvIdx, 3, 0xFFDE, 0x402F);
    ma211x_write(TrcvIdx, 3, 0xFE2A, 0x3C3D);
    ma211x_write(TrcvIdx, 3, 0xFE34, 0x4040);
    //ma211x_write(TrcvIdx, 3, 0xFE4B, 0x9337);
    ma211x_write(TrcvIdx, 3, 0xFE2A, 0x3C1D);
    ma211x_write(TrcvIdx, 3, 0xFE34, 0x0040);
    ma211x_write(TrcvIdx, 7, 0x8032, 0x0064);
    ma211x_write(TrcvIdx, 7, 0x8031, 0x0A01);
    ma211x_write(TrcvIdx, 7, 0x8031, 0x0C01);
    ma211x_write(TrcvIdx, 3, 0xFE0F, 0x0000);
    ma211x_write(TrcvIdx, 3, 0x800C, 0x0000);
    ma211x_write(TrcvIdx, 3, 0x801D, 0x0800);
    ma211x_write(TrcvIdx, 3, 0xFC00, 0x01C0);
    ma211x_write(TrcvIdx, 3, 0xFC17, 0x0425);
    ma211x_write(TrcvIdx, 3, 0xFC94, 0x5470);
    ma211x_write(TrcvIdx, 3, 0xFC95, 0x0055);
    ma211x_write(TrcvIdx, 3, 0xFC19, 0x08D8);
    ma211x_write(TrcvIdx, 3, 0xFC1a, 0x0110);
    ma211x_write(TrcvIdx, 3, 0xFC1b, 0x0A10);
    ma211x_write(TrcvIdx, 3, 0xFC3A, 0x2725);
    ma211x_write(TrcvIdx, 3, 0xFC61, 0x2627);
    ma211x_write(TrcvIdx, 3, 0xFC3B, 0x1612);
    ma211x_write(TrcvIdx, 3, 0xFC62, 0x1C12);
    ma211x_write(TrcvIdx, 3, 0xFC9D, 0x6367);
    ma211x_write(TrcvIdx, 3, 0xFC9E, 0x8060);
    ma211x_write(TrcvIdx, 3, 0xFC00, 0x01C8);
    // Tx Disable
    ma211x_write(TrcvIdx, 3, 0x8000, 0x0000);
    ma211x_write(TrcvIdx, 3, 0x8016, 0x0011);

    ma211x_write(TrcvIdx, 3, 0xFDA3, 0x1800);

    ma211x_write(TrcvIdx, 3, 0xFE02, 0x00C0);
    ma211x_write(TrcvIdx, 3, 0xFFDB, 0x0010);
    ma211x_write(TrcvIdx, 3, 0xFFF3, 0x0020);
    ma211x_write(TrcvIdx, 3, 0xFE40, 0x00A6);

    ma211x_write(TrcvIdx, 3, 0xFE60, 0x0000);
    ma211x_write(TrcvIdx, 3, 0xFE04, 0x0008);
    ma211x_write(TrcvIdx, 3, 0xFE2A, 0x3C3D);
    ma211x_write(TrcvIdx, 3, 0xFE4B, 0x9334);

    ma211x_write(TrcvIdx, 3, 0xFC10, 0xF600);
    ma211x_write(TrcvIdx, 3, 0xFC11, 0x073D);
    ma211x_write(TrcvIdx, 3, 0xFC12, 0x000D);
    //ma211x_write(TrcvIdx, 3, 0xFC13, 0x0010);
    /* RGMII TX delay */
    ma211x_write(TrcvIdx, 31, 0x8001, 0x4000);
    return 0;
}
/**
 * @description: set TrcvIdx mode
 * @return {*}
 * @param {uint8 } TrcvIdx
 * @param {uint32} op_mode
 */
static sint32 ma211x_ge_set_opmode(uint8  TrcvIdx, uint32 op_mode)
{
    if (op_mode == MRVL_88Q211X_MODE_LEGACY) {
        // Enable 1000 BASE-T1 legacy mode support
        ma211x_write(TrcvIdx, 3, 0xFDB8, 0x0001);
        ma211x_write(TrcvIdx, 3, 0xFD3D, 0x0C14);
    } else {
        // Set back to default compliant mode setting
        ma211x_write(TrcvIdx, 3, 0xFDB8, 0x0000);
        ma211x_write(TrcvIdx, 3, 0xFD3D, 0x0000);
    }

    ma211x_write(TrcvIdx, 1, 0x0902, op_mode | MRVL_88Q211X_MODE_ADVERTISE);
    return 0;
}
/**
 * @description: soft_reset
 * @return {*}
 * @param {uint8 } TrcvIdx
 */
static sint32 ma211x_ge_soft_reset(uint8  TrcvIdx)
{
    uint16 data;

    if (ma211x_get_autonego_enable(TrcvIdx))
        ma211x_write(TrcvIdx, 3, 0xFFF3, 0x0024);

    //enable low-power mode
    data = ma211x_read(TrcvIdx, 1, 0x0000);
    ma211x_write(TrcvIdx, 1, 0x0000, data | 0x0800);

    ma211x_write(TrcvIdx, 3, 0xFFF3, 0x0020);
    ma211x_write(TrcvIdx, 3, 0xFFE4, 0x000C);
    msleep(100);

    ma211x_write(TrcvIdx, 3, 0xffe4, 0x06B6);

    // disable low-power mode
    ma211x_write(TrcvIdx, 1, 0x0000, data & 0xF7FF);
    msleep(100);

    ma211x_write(TrcvIdx, 3, 0xFC47, 0x0030);
    ma211x_write(TrcvIdx, 3, 0xFC47, 0x0031);
    ma211x_write(TrcvIdx, 3, 0xFC47, 0x0030);
    ma211x_write(TrcvIdx, 3, 0xFC47, 0x0000);
    ma211x_write(TrcvIdx, 3, 0xFC47, 0x0001);
    ma211x_write(TrcvIdx, 3, 0xFC47, 0x0000);

    ma211x_write(TrcvIdx, 3, 0x0900, 0x8000);
    //  Disable Transmitters bit14 @tab57.p91
    ma211x_write(TrcvIdx, 1, 0x0900, 0x0001 << 14);
    //
    ma211x_write(TrcvIdx, 3, 0xFFE4, 0x000C);
    return 0;
}
/**
 * @description: init 100mbits mode
 * @return {*}
 * @param {uint8 } TrcvIdx
 */
static sint32 ma211x_fe_init(uint8  TrcvIdx)
{
    uint16 data = 0;

    ma211x_write(TrcvIdx, 3, 0xFA07, 0x0202);

    data = ma211x_read(TrcvIdx, 1, 0x0834);
    data = data & 0xFFF0;
    ma211x_write(TrcvIdx, 1, 0x0834, data);
    msleep(50);

    ma211x_write(TrcvIdx, 3, 0x8000, 0x0000);
    ma211x_write(TrcvIdx, 3, 0x8100, 0x0200);
    ma211x_write(TrcvIdx, 3, 0xFA1E, 0x0002);
    ma211x_write(TrcvIdx, 3, 0xFE5C, 0x2402);
    ma211x_write(TrcvIdx, 3, 0xFA12, 0x001F);
    ma211x_write(TrcvIdx, 3, 0xFA0C, 0x9E05);
    ma211x_write(TrcvIdx, 3, 0xFBDD, 0x6862);
    ma211x_write(TrcvIdx, 3, 0xFBDE, 0x736E);
    ma211x_write(TrcvIdx, 3, 0xFBDF, 0x7F79);
    ma211x_write(TrcvIdx, 3, 0xFBE0, 0x8A85);
    ma211x_write(TrcvIdx, 3, 0xFBE1, 0x9790);
    ma211x_write(TrcvIdx, 3, 0xFBE3, 0xA39D);
    ma211x_write(TrcvIdx, 3, 0xFBE4, 0xB0AA);
    ma211x_write(TrcvIdx, 3, 0xFBE5, 0x00B8);
    ma211x_write(TrcvIdx, 3, 0xFBFD, 0x0D0A);
    ma211x_write(TrcvIdx, 3, 0xFBFE, 0x0906);
    ma211x_write(TrcvIdx, 3, 0x801D, 0x8000);
    ma211x_write(TrcvIdx, 3, 0x8016, 0x0011);

    // reset pcs
    ma211x_write(TrcvIdx, 3, 0x0900, 0x8000);
    ma211x_write(TrcvIdx, 3, 0xFA07, 0x0200);
    msleep(100);

    ma211x_write(TrcvIdx, 31, 0x8001, 0xc000);
    return 0;
}
/**
 * @description: get TrcvIdx id
 * @return {*}
 * @param {uint8} TrcvIdx
 */
static sint32 q21xx_get_phy_id(uint8 TrcvIdx, uint32 *OrgUniqueIdPtr, uint8 *ModelNrPtr,
                               uint8 *RevisionNrPtr)
{
    uint16 val1, val2;

    val1 = ma211x_read(TrcvIdx, 1, 2);
    val2 = ma211x_read(TrcvIdx, 1, 3);

    *OrgUniqueIdPtr =  (val1 << 3) | (((val2 >> 10) & 0x3F) << 19);
    *ModelNrPtr = (val2 >> 4) & 0x3F;
    *RevisionNrPtr  = val2 & 0xF;
    return 0;
}
/**
 * @description: init TrcvIdx
 * @return {*}
 * @param {uint8 } TrcvIdx
 * @param {EthTrcvConfigType*} Param
 */
static sint32 ma211x_config_init(uint8  TrcvIdx, const EthTrcvConfigType *Param)
{
    ma211x_set_master(TrcvIdx, Param->ConnNegMode);
    ma211x_set_autonego_enalbe(TrcvIdx, Param->AutoNegotiation);

    if (TRCV_SPEED_100 == Param->Speed) {
        ma211x_fe_init(TrcvIdx);
    } else if (TRCV_SPEED_1000 == Param->Speed) {
        ma211x_ge_init(TrcvIdx);
        ma211x_ge_set_opmode(TrcvIdx, MRVL_88Q211X_MODE_DEFAULT);
        ma211x_ge_soft_reset(TrcvIdx);
    } else {
        return -1;
    }

    return 0;
}
static sint32 q21xx_set_mode(uint8 TrcvIdx, EthTrcv_ModeType mode)
{
    if (ETHTRCV_MODE_DOWN != mode) {
        //  Enable Transmitters bit14 @tab57.p91
        ma211x_write(TrcvIdx, 1, 0x0900, 0x0000);
    } else {
        //  disable Transmitters bit14 @tab57.p91
        ma211x_write(TrcvIdx, 1, 0x0900, 0x01 << 14 );
    }

    return 0;
}
/**
 * @description:
 * @return {*}
 * @param {uint8 } TrcvIdx
 * @param {uint32} Mode
 */

static sint32 Set_TxMode(uint8  TrcvIdx, EthTrcv_PhyTxModeType Mode)
{
    uint32 val = ma211x_read(TrcvIdx, 3, 0x8000);

    if (Mode == ETHTRCV_PHYTXMODE_NORMAL) {
        val &= (uint32)(~(0x01 << 3));
        ma211x_write(TrcvIdx, 3, 0x8000, val);
    } else if (Mode == ETHTRCV_PHYTXMODE_TX_OFF) {
        val = ma211x_read(TrcvIdx, 3, 0x8000);
        val |= 0x01 << 3;
        //  Enable Transmitters bit14 @tab57.p91
        ma211x_write(TrcvIdx, 3, 0x8000, val);
    } else {
        return -1;
    }

    return 0;
}
/**
 * @description:
 * @return {*}
 * @param {uint8 } TrcvIdx
 */
static sint32 get_signal_quality(uint8  TrcvIdx)
{
    uint32 val;
    val = ma211x_read(TrcvIdx, 3, 0x8230);
    val >>= 12;
    val &= 0xF;
    return val;
}
/**
 * @description:
 * @return {*}
 * @param {uint8 } TrcvIdx
 * @param {uint32} Mode
 */
static sint32 q21xx_set_loopback(uint8  TrcvIdx, EthTrcv_PhyLoopbackModeType Mode)
{
    uint32 val;

    if (Mode == ETHTRCV_PHYLOOPBACK_INTERNAL) {
        val = ma211x_read(TrcvIdx, 3, 0x0900);
        val |= 0x01 << 14;
        ma211x_write(TrcvIdx, 3, 0x0900, val);
    } else if (Mode == ETHTRCV_PHYLOOPBACK_REMOTE) {
        if (ma211x_get_speed(TrcvIdx) == 0) {
            val = ma211x_read(TrcvIdx, 3, 0x8100);
            val |= 0x01 << 14;
            ma211x_write(TrcvIdx, 3, 0x8100, val);
        } else {
            val = ma211x_read(TrcvIdx, 3, 0xFD00);
            val |= 0x01 << 10;
            ma211x_write(TrcvIdx, 3, 0xFD00, val);
        }
    } else {
        return -1;
    }

    return 0;
}
/**
 * @description:
 * @return {*}
 * @param {uint8 } TrcvIdx
 * @param {uint32} Mode
 */
static sint32 Set_TestMode(uint8  TrcvIdx, EthTrcv_PhyTestModeType Mode)
{
    uint32 val;

    if (Mode != ETHTRCV_PHYTESTMODE_3) {
        val = ma211x_read(TrcvIdx, 1, 0x0904);
        val &= 0x7 << 13;
        val |= Mode << 13;
        ma211x_write(TrcvIdx, 1, 0x0904, val);
        return 0;
    }

    return -1;
}
/**
 * @description:
 * @return {*}
 * @param {uint8 } TrcvIdx
 */
static EthTrcv_DuplexModeType  q21xx_get_duplex_mode(uint8  TrcvIdx)
{
    uint32 val;
    val = ma211x_read(TrcvIdx, 1, 0x8004);

    if (val & (0x01 << 12)) {
        return ETHTRCV_DUPLEX_MODE_FULL;
    }

    return ETHTRCV_DUPLEX_MODE_HALF;
}

#define ETHTRCV_STOP_SEC_CODE
#include "EthTrcv_MemMap.h"

#define ETHTRCV_START_SEC_CONST_UNSPECIFIED
#include "EthTrcv_MemMap.h"

const EthTrcv_Ops_Type  marvell_q21xx_ops = {
    .phy_init = ma211x_config_init,
    .phy_set_mode = q21xx_set_mode,
    .phy_get_mode = NULL_PTR,
    .phy_set_wakeup_mode = NULL_PTR,
    .phy_get_wakeup_mode = NULL_PTR,
    .phy_checkwakeup = NULL_PTR,
    .phy_start_auto_negotiation = NULL_PTR,
    .phy_link_state_request = NULL_PTR,
    .phy_get_link_state = maq21xx_get_link_state,
    .phy_get_rate = q21xx_get_rate,
    .phy_get_duplex_mode = q21xx_get_duplex_mode,
    .phy_set_test_mode = Set_TestMode,
    .phy_set_loopback_mode = q21xx_set_loopback,
    .phy_set_txmode = Set_TxMode,
    .phy_trigger_cable_diagnostic = NULL_PTR,
    .phy_get_cable_diagnostics_result = NULL_PTR,
    .phy_get_id = q21xx_get_phy_id,
    .phy_get_signal_quality = get_signal_quality,
};

#define ETHTRCV_STOP_SEC_CONST_UNSPECIFIED
#include "EthTrcv_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif

