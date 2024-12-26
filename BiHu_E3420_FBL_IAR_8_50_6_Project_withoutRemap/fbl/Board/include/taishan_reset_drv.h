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
#ifndef TAISHAN_RESET_DRV_H_
#define TAISHAN_RESET_DRV_H_

#include <types.h>
#include "reset.h"

#define TAISHAN_RESET_CORE     1
#define TAISHAN_RESET_LATENT   2
#define TAISHAN_RESET_MISSION  3
#define TAISHAN_RESET_MODULE   4
#define TAISHAN_RESET_IST      5
#define TAISHAN_RESET_DEBUG    6

#define TAISHAN_RESET_TYPE_SHIFT  24

#define TAISHAN_RESET_SIG_ID(type, idx) \
    ((uint32)((((uint32)(type)) << ((uint32)TAISHAN_RESET_TYPE_SHIFT)) | ((uint32)(idx))))

#define TAISHAN_RESET_TYPE(id)   ((uint32)(((uint32)(id)) >> ((uint32)TAISHAN_RESET_TYPE_SHIFT)))
#define TAISHAN_RESET_INDEX(id)  ((uint32)(((uint32)(id)) & BIT_MASK(TAISHAN_RESET_TYPE_SHIFT)))

#define TAISHAN_RESET_GENERAL_REG_NUM  8

/**
 * @brief SAF reset signal id.
 */
typedef enum reset_signal_safety {
    RSTSIG_SAF_RSTGEN_AP        = TAISHAN_RESET_SIG_ID(TAISHAN_RESET_CORE, 0),
    RSTSIG_SAF_CR5_SAF,
    RSTSIG_SAF_CR5_SP0,
    RSTSIG_SAF_CR5_SP1,
    RSTSIG_SAF_CR5_SX0,
    RSTSIG_SAF_CR5_SX1,
    RSTSIG_SAF_MAC              = TAISHAN_RESET_SIG_ID(TAISHAN_RESET_LATENT, 0),
    RSTSIG_SAF_SCR_BOOT         = TAISHAN_RESET_SIG_ID(TAISHAN_RESET_LATENT, 0),
    RSTSIG_SAF_GPIO_SF          = TAISHAN_RESET_SIG_ID(TAISHAN_RESET_LATENT, 0),
    RSTSIG_SAF_WDT1_2           = TAISHAN_RESET_SIG_ID(TAISHAN_RESET_LATENT, 0),
    RSTSIG_SAF_SEM              = TAISHAN_RESET_SIG_ID(TAISHAN_RESET_LATENT, 0),
    RSTSIG_SAF_ANA_SF,
    RSTSIG_SAF_SCR_SF,
    RSTSIG_SAF_UART             = TAISHAN_RESET_SIG_ID(TAISHAN_RESET_MISSION, 3),
    RSTSIG_SAF_SPI              = TAISHAN_RESET_SIG_ID(TAISHAN_RESET_MISSION, 3),
    RSTSIG_SAF_I2C              = TAISHAN_RESET_SIG_ID(TAISHAN_RESET_MISSION, 3),
    RSTSIG_SAF_FLEXRAY          = TAISHAN_RESET_SIG_ID(TAISHAN_RESET_MISSION, 3),
    RSTSIG_SAF_WDT5_6           = TAISHAN_RESET_SIG_ID(TAISHAN_RESET_MISSION, 3),
    RSTSIG_SAF_WDT3_4           = TAISHAN_RESET_SIG_ID(TAISHAN_RESET_MISSION, 5),
    RSTSIG_SAF_MISSION6         = TAISHAN_RESET_SIG_ID(TAISHAN_RESET_MISSION, 6),
    RSTSIG_SAF_LDO              = TAISHAN_RESET_SIG_ID(TAISHAN_RESET_MISSION, 8),
    RSTSIG_SAF_DCDC             = TAISHAN_RESET_SIG_ID(TAISHAN_RESET_MISSION, 9),
    RSTSIG_SAF_CANFD1           = TAISHAN_RESET_SIG_ID(TAISHAN_RESET_MODULE, 0),
    RSTSIG_SAF_CANFD2,
    RSTSIG_SAF_CANFD3_4,
    RSTSIG_SAF_CANFD5_8,
    RSTSIG_SAF_CANFD9_16,
    RSTSIG_SAF_CANFD17_24,
    RSTSIG_SAF_XSPI1A           = TAISHAN_RESET_SIG_ID(TAISHAN_RESET_MODULE, 10),
    RSTSIG_SAF_XSPI1B,
    RSTSIG_SAF_XSPI2A,
    RSTSIG_SAF_XSPI2B,
    RSTSIG_SAF_DMA_RST0         = TAISHAN_RESET_SIG_ID(TAISHAN_RESET_MODULE, 15),
    RSTSIG_SAF_DMA_RST1,
    RSTSIG_SAF_ENET1,
    RSTSIG_SAF_ENET2,
    RSTSIG_SAF_GAMA1            = TAISHAN_RESET_SIG_ID(TAISHAN_RESET_MODULE, 21),
    RSTSIG_SAF_AHB_SYNCUP_GAMA1 = TAISHAN_RESET_SIG_ID(TAISHAN_RESET_MODULE, 21),
    RSTSIG_SAF_GAMA2,
    RSTSIG_SAF_AHB_SYNCUP_GAMA2 = TAISHAN_RESET_SIG_ID(TAISHAN_RESET_MODULE, 22),
    RSTSIG_SAF_VIC1,
    RSTSIG_SAF_VIC2_PORTA,
    RSTSIG_SAF_VIC2_PORTB,
    RSTSIG_SAF_VIC3_PORTA       = TAISHAN_RESET_SIG_ID(TAISHAN_RESET_MODULE, 27),
    RSTSIG_SAF_VIC3_PORTB,
    RSTSIG_SAF_XSPI_SLV,
    RSTSIG_SAF_MB,
    RSTSIG_SAF_XTRG,
    RSTSIG_SAF_DEBUG            = TAISHAN_RESET_SIG_ID(TAISHAN_RESET_DEBUG, 0),
} reset_signal_safety_e;

/**
 * @brief AP reset signal id.
 */
typedef enum reset_signal_ap {
    RSTSIG_AP_DISP_MUX     = TAISHAN_RESET_SIG_ID(TAISHAN_RESET_MISSION, 0),
    RSTSIG_AP_GPIO_AP      = TAISHAN_RESET_SIG_ID(TAISHAN_RESET_MISSION, 0),
    RSTSIG_AP_WDT8         = TAISHAN_RESET_SIG_ID(TAISHAN_RESET_MISSION, 0),
    RSTSIG_AP_SCR_AP       = TAISHAN_RESET_SIG_ID(TAISHAN_RESET_MISSION, 0),
    RSTSIG_AP_MISSION1     = TAISHAN_RESET_SIG_ID(TAISHAN_RESET_MISSION, 1),
    RSTSIG_AP_CSI          = TAISHAN_RESET_SIG_ID(TAISHAN_RESET_MODULE, 0),
    RSTSIG_AP_DC,
    RSTSIG_AP_G2D,
    RSTSIG_AP_SDRAMC,
    RSTSIG_AP_SACI1,
    RSTSIG_AP_SACI2,//5
    RSTSIG_AP_DMA_AP,
    RSTSIG_AP_SEHC1,
    RSTSIG_AP_SEHC2,
    RSTSIG_AP_USB,
    RSTSIG_AP_SEIP,//10
    RSTSIG_AP_LVDS_SS     = TAISHAN_RESET_SIG_ID(TAISHAN_RESET_MODULE, 12),
    RSTSIG_AP_DEBUG       = TAISHAN_RESET_SIG_ID(TAISHAN_RESET_DEBUG, 0),
} reset_signal_ap_e;

/**
 * @brief Abstract semidrive rstgen device.
*/
typedef struct taishan_reset_ctl {
    paddr_t        base;
} taishan_reset_ctl_t;

/**
 * @brief Initialize the  SemiDrive RESET controller.
 *
 * @param[in] rst_ctl Common reset device.
 * @param[in] sdrv_rst_ctl SemiDrive reset device.
 * @return 0 if OK, or a negative error code.
 */
sint32 taishan_reset_init(reset_ctl_t *rst_ctl, taishan_reset_ctl_t *taishan_rst_ctl);
#endif /* TAISHAN_RESET_DRV_H_ */
