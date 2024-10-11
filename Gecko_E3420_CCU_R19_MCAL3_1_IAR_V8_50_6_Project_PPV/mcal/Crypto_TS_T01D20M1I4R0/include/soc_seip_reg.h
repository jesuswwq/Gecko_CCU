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
 * @file  soc_seip_reg.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Crypto
 */

#ifndef SOC_SEIP_REG_H
#define SOC_SEIP_REG_H

#ifdef __cplusplus
extern "C" {
#endif

#define MBOX_SOCBASE            (0x021d8000)
#define rSOCMBOX_CMD_D0         *((volatile unsigned int *)(MBOX_SOCBASE + 0x00))
#define rSOCMBOX_CMD_D1         *((volatile unsigned int *)(MBOX_SOCBASE + 0x04))
#define rSOCMBOX_CMD_D2         *((volatile unsigned int *)(MBOX_SOCBASE + 0x08))
#define rSOCMBOX_CMD_D3         *((volatile unsigned int *)(MBOX_SOCBASE + 0x0C))
#define rSOCMBOX_CMD_D4         *((volatile unsigned int *)(MBOX_SOCBASE + 0x10))
#define rSOCMBOX_CMD_D5         *((volatile unsigned int *)(MBOX_SOCBASE + 0x14))
#define rSOCMBOX_CMD_D6         *((volatile unsigned int *)(MBOX_SOCBASE + 0x18))
#define rSOCMBOX_CMD_D7         *((volatile unsigned int *)(MBOX_SOCBASE + 0x1C))
#define rSOCMBOX_RSP_D0         *((volatile unsigned int *)(MBOX_SOCBASE + 0x20))
#define rSOCMBOX_INT_STA        *((volatile unsigned int *)(MBOX_SOCBASE + 0x24))
#define rSOCMBOX_INT_EN         *((volatile unsigned int *)(MBOX_SOCBASE + 0x28))

#ifdef __cplusplus
}
#endif

#endif
