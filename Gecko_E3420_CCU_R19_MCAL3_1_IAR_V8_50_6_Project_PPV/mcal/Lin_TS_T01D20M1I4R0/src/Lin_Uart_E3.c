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
 * @file  Lin_Uart_E3.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Lin
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Lin_Types_E3.h"
#include "RegHelper.h"
#include "uart_reg_e3.h"
#include "SchM_Lin.h"
#include "Lin_Cfg.h"
#if defined(SEMIDRIVE_E3_LITE_SERIES)
#include "Mcu.h"
#endif

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_POLLING_TIME_OUT    (1000U)

/* initialize UART module and corresponding configuration*/
void Lin_UartInit(const Lin_Uart *Lin_UartCfg)
{
    if (NULL_PTR == Lin_UartCfg) {
        return;
    }
    const lin_uart_cfg_t *hardwareCfg = &(Lin_UartCfg->dataPtr);
    uint32 PollTime = 0u;
    uint32 Lin_BaseAddr = Mcu_GetModuleBase((Mcu_ModuleType)Lin_UartCfg->UartModule);
    uint32 Mod_Ctrl = REG_READ32(Lin_BaseAddr + MCR0_OFF);
    /* set module operation mode */
    Mod_Ctrl &= ~FM_MCR0_OPMOD;
    Mod_Ctrl |= FV_MCR0_OPMOD(hardwareCfg->mode + 1);
    REG_WRITE32(Mod_Ctrl, Lin_BaseAddr + MCR0_OFF);

    /* clear all interrupt */
    REG_WRITE32(0xFFFFFFFF, Lin_BaseAddr + INTR0_OFF);
    uint32 Pcr0 = REG_READ32(Lin_BaseAddr + PCR0_OFF);
    /* set data bit: 8 bit */
    Pcr0 &= ~FM_PCR0_DATABIT;
    Pcr0 |= FV_PCR0_DATABIT(0);
    /* set stop bit */
    Pcr0 &= ~FM_PCR0_STOPBIT;
    Pcr0 |= FV_PCR0_STOPBIT(hardwareCfg->stop);
    /* set parity */
    Pcr0 &= ~FM_PCR0_PARITYBIT;
    Pcr0 |= FV_PCR0_PARITYBIT(hardwareCfg->parity);
    Pcr0 |= BM_PCR0_TRANSFERMODE;
    REG_WRITE32(Pcr0, Lin_BaseAddr + PCR0_OFF);

    /* set baud rate */
    uint32 Pcr1 = 0;

    uint32 Freq = hardwareCfg->frequency;
    uint32 Baud = hardwareCfg->baud_rate;
    uint32 Baudrate = Freq / Baud;
    Pcr1 = REG_READ32(Lin_BaseAddr + PCR1_OFF);
    Pcr1 &= ~FM_PCR1_BAUDRATECNT;
    Pcr1 |= FV_PCR1_BAUDRATECNT(Baudrate);
    REG_WRITE32(Pcr1, Lin_BaseAddr + PCR1_OFF);

    /* clear fifo */
    REG_WRITE32(BM_FCR0_CLRTXF, Lin_BaseAddr + FCR0_OFF);
    REG_WRITE32(BM_FCR1_CLRRXF, Lin_BaseAddr + FCR1_OFF);

    /* disable dma */
    REG_WRITE32((BM_DMACR_TXDMAE | BM_DMACR_RXDMAE), Lin_BaseAddr + DMACR_OFF);

    /* set rx noise filter : shorter than 1 cycle */
    uint32 Pcr8 = REG_READ32(Lin_BaseAddr + PCR8_OFF);
    Pcr8 &= ~FM_PCR8_RXFILTCTL;
    Pcr8 |= FV_PCR8_RXFILTCTL(3);
    Pcr8 |= BM_PCR8_RXSYNCEN;
    REG_WRITE32(Pcr8, Lin_BaseAddr + PCR8_OFF);

    /* set break bit : 13 bit*/
    uint32 Pcr4 = REG_READ32(Lin_BaseAddr + PCR4_OFF);
    Pcr4 &= ~FM_PCR4_TXBREAKCTL;
    Pcr4 |= FV_PCR4_TXBREAKCTL(LIN_UART_TXBREAK_BIT(13));
    REG_WRITE32(Pcr4, Lin_BaseAddr + PCR4_OFF);
    Pcr1 = REG_READ32(Lin_BaseAddr + PCR1_OFF);
    Pcr1 &= ~FM_PCR1_RXBREAKCTL;
    /* master mode will set brek bit to 0 when corresponding channel wakeup */
    Pcr1 |= FV_PCR1_RXBREAKCTL(LIN_UART_RXBREAK_BIT(11));
    REG_WRITE32(Pcr1, Lin_BaseAddr + PCR1_OFF);

    /* set frame time out value : (2 ^ 21) cycle */
    uint32 Pcr7 = REG_READ32(Lin_BaseAddr + PCR7_OFF);
    Pcr7 &= ~FM_PCR7_PCMDTO;
    if (hardwareCfg->baud_rate >= 1000 && hardwareCfg->baud_rate < 2000) {
        /* baud rate (1k - 2k) : 200ms time out */
        Pcr7 |= GFV_PCR7_PCMDTO(0x0B);
    } else if (hardwareCfg->baud_rate >= 2000 && hardwareCfg->baud_rate < 5000) {
        /* baud rate (2k - 5k) : 100ms time out */
        Pcr7 |= GFV_PCR7_PCMDTO(0x0C);
    } else if (hardwareCfg->baud_rate >= 5000 && hardwareCfg->baud_rate < 10000) {
        /* baud rate (5k - 10k) : 50ms time out */
        Pcr7 |= GFV_PCR7_PCMDTO(0x0D);
    } else if (hardwareCfg->baud_rate >= 10000 && hardwareCfg->baud_rate < 15000) {
        /* baud rate (10k - 15k) : 25ms time out */
        Pcr7 |= GFV_PCR7_PCMDTO(0x0E);
    } else if (hardwareCfg->baud_rate >= 15000 && hardwareCfg->baud_rate <= 20000) {
        /* baud rate (15k - 20k) : 12ms time out */
        Pcr7 |= GFV_PCR7_PCMDTO(0x0F);
    }

    REG_WRITE32(Pcr7, Lin_BaseAddr + PCR7_OFF);

    /* set lin related int enable */
    uint32 Lin_Int = 0;
    Lin_Int |= BM_INTEN0_APBCMDDONEE | BM_INTEN0_APBCMDABORTE |
               BM_INTEN0_RXCHKSUMPASSE | BM_INTEN0_RXCHKSUMERRE |
               BM_INTEN0_RXPIDPASSE | BM_INTEN0_RXPIDERRE |
               BM_INTR0_STARTERR | BM_INTR0_NOISEERR |
               BM_INTR0_FRAMEERR | BM_INTR0_PARITYERR |
               BM_INTR0_RXFOVF | BM_INTR0_TXFOVF | BM_INTR0_RXFUDF | BM_INTR0_TXFUDF |
               BM_INTR0_RXBREAK;
#if defined(SEMIDRIVE_E3_LITE_SERIES)
    /* e3 lite 1.1 chip ignore baudrate err */
    if (Mcu_GetChipVersion() == 0x0U) {
#endif
        Lin_Int |= BM_INTR0_BAUDRATEERR;
#if defined(SEMIDRIVE_E3_LITE_SERIES)
    }
#endif
#if (LIN_ICU_ABR_DETECT == STD_OFF)
    Lin_Int |= BM_INTEN0_ABRPASSE | BM_INTEN0_ABRFAILE;
#endif
    REG_WRITE32(Lin_Int, Lin_BaseAddr + INTEN0_OFF);

    if (hardwareCfg->mode == LIN_UART_SLAVE) {
        /* set check sum type */
        uint32 Pcr6 = REG_READ32(Lin_BaseAddr + PCR6_OFF);
        Pcr6 |= ((hardwareCfg->cs_mode) << 3);
        REG_WRITE32(Pcr6, Lin_BaseAddr + PCR6_OFF);
    }

    Pcr0 = REG_READ32(Lin_BaseAddr + PCR0_OFF);
    Pcr0 |= BM_PCR0_TXEN;
    Pcr0 |= BM_PCR0_RXEN;
    REG_WRITE32(Pcr0, Lin_BaseAddr + PCR0_OFF);

    /* reset the module */
    Mod_Ctrl = REG_READ32(Lin_BaseAddr + MCR0_OFF);
    Mod_Ctrl |= BM_MCR0_MODRST;
    REG_WRITE32(Mod_Ctrl, Lin_BaseAddr + MCR0_OFF);
    /* Delay a while unitl setting be synced,need (4*pclk+4*24m_clk) */
    while ((REG_READ32(Lin_BaseAddr + MCR0_OFF) & BM_MCR0_MODRST) && (PollTime < LIN_POLLING_TIME_OUT)){
        PollTime++;
    }
    /* enable the module */
    Mod_Ctrl = REG_READ32(Lin_BaseAddr + MCR0_OFF);
    Mod_Ctrl |= BM_MCR0_MODEN;
    REG_WRITE32(Mod_Ctrl, Lin_BaseAddr + MCR0_OFF);

    /* When using icu for auto baud rate detection, the original uart abr function does not need to be set */
#if (LIN_ICU_ABR_DETECT == STD_OFF)
    if ((hardwareCfg->mode == LIN_UART_SLAVE) && (hardwareCfg->auto_br == TRUE)) {
        /* set auto baud rate */
        Pcr0 = REG_READ32(Lin_BaseAddr + PCR0_OFF);
        Pcr0 &= ~FM_PCR0_ABRCTL0;
        Pcr0 &= ~FM_PCR0_ABRCTL1;
        Pcr0 |= BM_PCR0_ABREN;
        Pcr0 |= FV_PCR0_ABRCTL0(0);
        Pcr0 |= GFV_PCR0_ABRCTL1(0);
        REG_WRITE32(Pcr0, Lin_BaseAddr + PCR0_OFF);
    }
#endif

}

void Lin_UartPidSet(const Lin_Uart *Lin_UartCfg, uint8 Pid)
{
    uint32 Lin_BaseAddr = Mcu_GetModuleBase((Mcu_ModuleType)(Lin_UartCfg->UartModule));
    uint32 CmdCsr1 = REG_READ32(Lin_BaseAddr + CMDCSR1_OFF);
    CmdCsr1 &= ~FM_CMDCSR1_PID;
    CmdCsr1 |= FV_CMDCSR1_PID(Pid);
    REG_WRITE32(CmdCsr1, Lin_BaseAddr + CMDCSR1_OFF);
}



uint8 Lin_UartPidGet(const Lin_Uart *Lin_UartCfg)
{
    uint8 Pid = 0;
    uint32 Lin_BaseAddr = Mcu_GetModuleBase((Mcu_ModuleType)(Lin_UartCfg->UartModule));
    /* workaround : solve the situation that sometimes will get a wrong pid value */
    uint32 Psr4 = REG_READ32(Lin_BaseAddr + PSR4_OFF);
    Pid = Psr4 & FM_PSR4_LINPID;
    return Pid;
}


void Lin_UartTransmit(const Lin_Uart *Lin_UartCfg, uint8 cs, uint8 *point2data, uint8 numberBytes)
{
    uint32 Lin_BaseAddr = Mcu_GetModuleBase((Mcu_ModuleType)(Lin_UartCfg->UartModule));
    uint8 i = 0U;
    uint32 Cmdcsr1 = REG_READ32(Lin_BaseAddr + CMDCSR1_OFF);
    Cmdcsr1 &= ~FM_CMDCSR1_TXBYTENUM;
    Cmdcsr1 |= FV_CMDCSR1_TXBYTENUM(numberBytes);
    Cmdcsr1 &= ~FM_CMDCSR1_RXBYTENUM;
    Cmdcsr1 |= FV_CMDCSR1_RXBYTENUM(0);
    REG_WRITE32(Cmdcsr1, Lin_BaseAddr + CMDCSR1_OFF);
    uint32 Mcr0 = REG_READ32(Lin_BaseAddr + MCR0_OFF);

    /* opmod=1 : master mode */
    if (GFV_MCR0_OPMOD(Mcr0) == 1) {
        /* set check sum type */
        uint32 Pcr6 = REG_READ32(Lin_BaseAddr + PCR6_OFF);
        Pcr6 &= ~BM_PCR6_CHKSUMTYP;
        Pcr6 |= (cs << 3);
        REG_WRITE32(Pcr6, Lin_BaseAddr + PCR6_OFF);
    }

    /* clr tx fifo */
    uint32 Fcr0 = REG_READ32(Lin_BaseAddr + FCR0_OFF);
    Fcr0 |= BM_FCR0_CLRTXF;
    REG_WRITE32(Fcr0, Lin_BaseAddr + FCR0_OFF);
    /* Guarantees write fifo and doorbell continuity */
    SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_00();
    uint32 Cmdcsr0 = FV_CMDCSR0_DOORBELL(0xA53C);
    REG_WRITE32(Cmdcsr0, Lin_BaseAddr + CMDCSR0_OFF);

    while (i < numberBytes) {
        REG_WRITE32(*point2data, Lin_BaseAddr + TX_OFF);
        i++;
        point2data++;
    }

    SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_00();
}

void Lin_Uart_Set_Break(const Lin_Uart *Lin_UartCfg)
{
    uint32 Lin_BaseAddr = Mcu_GetModuleBase((Mcu_ModuleType)(Lin_UartCfg->UartModule));
    uint32 Pcr4 = REG_READ32(Lin_BaseAddr + PCR4_OFF);
    Pcr4 |= BM_PCR4_TXBREAK;
    REG_WRITE32(Pcr4, Lin_BaseAddr + PCR4_OFF);
}

void Lin_UartRxBreakCtrl(const Lin_Uart *Lin_UartCfg, uint8 bitNum)
{
    uint32 Lin_BaseAddr = Mcu_GetModuleBase((Mcu_ModuleType)(Lin_UartCfg->UartModule));
    uint32 Pcr1 = REG_READ32(Lin_BaseAddr + PCR1_OFF);
    Pcr1 &= ~FM_PCR1_RXBREAKCTL;
    /* master mode will set break bit to 0 when wakeup */
    if (bitNum != 0) {
        Pcr1 |= FV_PCR1_RXBREAKCTL(LIN_UART_RXBREAK_BIT(bitNum));
    }
    REG_WRITE32(Pcr1, Lin_BaseAddr + PCR1_OFF);
}

void Lin_UartReceive(const Lin_Uart *Lin_UartCfg, uint8 cs, uint8 numberBytes)
{
    /* Guarantees write reg and rx doorbell continuity */
    SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_01();
    uint32 Lin_BaseAddr = Mcu_GetModuleBase((Mcu_ModuleType)(Lin_UartCfg->UartModule));
    uint32 Cmdcsr1 = REG_READ32(Lin_BaseAddr + CMDCSR1_OFF);
    Cmdcsr1 &= ~FM_CMDCSR1_TXBYTENUM;
    Cmdcsr1 |= FV_CMDCSR1_TXBYTENUM(0);
    Cmdcsr1 &= ~FM_CMDCSR1_RXBYTENUM;
    Cmdcsr1 |= FV_CMDCSR1_RXBYTENUM(numberBytes);
    REG_WRITE32(Cmdcsr1, Lin_BaseAddr + CMDCSR1_OFF);

    uint32 Mcr0 = REG_READ32(Lin_BaseAddr + MCR0_OFF);

    /* opmod=1 : master mode */
    if ((Mcr0 & FM_MCR0_OPMOD) == (0x1 << 4)) {
        /* set check sum type */
        uint32 Pcr6 = REG_READ32(Lin_BaseAddr + PCR6_OFF);
        Pcr6 &= ~BM_PCR6_CHKSUMTYP;
        Pcr6 |= (cs << 3);
        REG_WRITE32(Pcr6, Lin_BaseAddr + PCR6_OFF);
    }

    uint32 Cmdcsr0 = FV_CMDCSR0_DOORBELL(0xA53C);
    REG_WRITE32(Cmdcsr0, Lin_BaseAddr + CMDCSR0_OFF);
    SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_01();
}

void Lin_UartGetChar(const Lin_Uart *Lin_UartCfg, uint8 *data, uint8 numberBytes)
{
    uint32 Lin_BaseAddr = Mcu_GetModuleBase((Mcu_ModuleType)(Lin_UartCfg->UartModule));

    uint32 Fifo_Sta = REG_READ32(Lin_BaseAddr + FSR1_OFF);
    uint32 Rx_Byte_Num = GFV_FSR1_FILLLVL(Fifo_Sta);
    if (Rx_Byte_Num < numberBytes) {
        /* make sure the fifo data is not read out of bounds */
        uint32 Fcr1 = REG_READ32(Lin_BaseAddr + FCR1_OFF);
        Fcr1 |= BM_FCR1_CLRRXF;
        /* clr rx fifo */
        REG_WRITE32(Fcr1, Lin_BaseAddr + FCR1_OFF);
    } else {
        for (uint8 i = 0; i < numberBytes; i++) {
            while (REG_READ32(Lin_BaseAddr + FSR1_OFF) & BM_FSR1_EMPTY) {
                ;
            }
            data[i] = REG_READ32(Lin_BaseAddr + RX_OFF);
        }
    }
}


uint32 Lin_UartGetInt(const Lin_Uart *Lin_UartCfg)
{
    uint32 Lin_BaseAddr = Mcu_GetModuleBase((Mcu_ModuleType)(Lin_UartCfg->UartModule));
    uint32 Lin_Int = REG_READ32(Lin_BaseAddr + INTR0_OFF);
    return Lin_Int;
}

void Lin_UartClearInt(const Lin_Uart *Lin_UartCfg, uint32 state)
{
    uint32 Lin_BaseAddr = Mcu_GetModuleBase((Mcu_ModuleType)(Lin_UartCfg->UartModule));
    REG_WRITE32(state, Lin_BaseAddr + INTR0_OFF);
}

void Lin_UartClrTxFifo(const Lin_Uart *Lin_UartCfg)
{
    uint32 Lin_BaseAddr = Mcu_GetModuleBase((Mcu_ModuleType)(Lin_UartCfg->UartModule));

    uint32 Fcr0 = REG_READ32(Lin_BaseAddr + FCR0_OFF);
    Fcr0 |= BM_FCR0_CLRTXF;
    REG_WRITE32(Fcr0, Lin_BaseAddr + FCR0_OFF);
}

void Lin_UartClrRxFifo(const Lin_Uart *Lin_UartCfg)
{
    uint32 Lin_BaseAddr = Mcu_GetModuleBase((Mcu_ModuleType)(Lin_UartCfg->UartModule));

    uint32 Fcr1 = REG_READ32(Lin_BaseAddr + FCR1_OFF);
    Fcr1 |= BM_FCR1_CLRRXF;
    REG_WRITE32(Fcr1, Lin_BaseAddr + FCR1_OFF);

}

void Lin_UartSetAbr(const Lin_Uart *Lin_UartCfg)
{
    const lin_uart_cfg_t *hardwareCfg = &(Lin_UartCfg->dataPtr);
    uint32 Lin_BaseAddr = Mcu_GetModuleBase((Mcu_ModuleType)(Lin_UartCfg->UartModule));
    uint32 Freq = hardwareCfg->frequency;

    uint32 Psr1 = REG_READ32(Lin_BaseAddr + PSR1_OFF);
    Psr1 &= FM_PSR1_AUTOBAUDRATE;
#if defined(SEMIDRIVE_E3_LITE_SERIES)
    /* e3 lite 1.1 chip noneed dis able abr anymore */
    if (Mcu_GetChipVersion() == 0x0U) {
#endif
        uint32 Pcr1 = REG_READ32(Lin_BaseAddr + PCR1_OFF);
        Pcr1 &= ~FM_PCR1_BAUDRATECNT;
        Pcr1 |= FV_PCR1_BAUDRATECNT(Psr1);
        REG_WRITE32(Pcr1, Lin_BaseAddr + PCR1_OFF);
#if defined(SEMIDRIVE_E3_LITE_SERIES)
    }
#endif
    uint32 baud_rate = Freq / Psr1;
    /* set frame time out value */
    uint32 Pcr7 = REG_READ32(Lin_BaseAddr + PCR7_OFF);
    Pcr7 &= ~FM_PCR7_PCMDTO;
    if (baud_rate >= 1000 && baud_rate < 2000) {
        /* baud rate (1k - 2k) : 200ms time out */
        Pcr7 |= GFV_PCR7_PCMDTO(0x0B);
    } else if (baud_rate >= 2000 && baud_rate < 5000) {
        /* baud rate (2k - 5k) : 100ms time out */
        Pcr7 |= GFV_PCR7_PCMDTO(0x0C);
    } else if (baud_rate >= 5000 && baud_rate < 10000) {
        /* baud rate (5k - 10k) : 50ms time out */
        Pcr7 |= GFV_PCR7_PCMDTO(0x0D);
    } else if (baud_rate >= 10000 && baud_rate < 15000) {
        /* baud rate (10k - 15k) : 25ms time out */
        Pcr7 |= GFV_PCR7_PCMDTO(0x0E);
    } else if (baud_rate >= 15000 && baud_rate <= 20000) {
        /* baud rate (15k - 20k) : 12ms time out */
        Pcr7 |= GFV_PCR7_PCMDTO(0x0F);
    }

    REG_WRITE32(Pcr7, Lin_BaseAddr + PCR7_OFF);
}

void Lin_UartSetAbrEn(const Lin_Uart *Lin_UartCfg, boolean enable)
{
    uint32 Lin_BaseAddr = Mcu_GetModuleBase((Mcu_ModuleType)(Lin_UartCfg->UartModule));
    uint32 Pcr0 = REG_READ32(Lin_BaseAddr + PCR0_OFF);

    if (enable) {
        Pcr0 |= BM_PCR0_ABREN;
    } else {
        Pcr0 &= ~BM_PCR0_ABREN;
    }

    REG_WRITE32(Pcr0, Lin_BaseAddr + PCR0_OFF);

}

void Lin_Uart_Set_Baudrate(const Lin_Uart *Lin_UartCfg, uint32 calcbaud)
{
    if (NULL_PTR == Lin_UartCfg) {
        return;
    }
    const lin_uart_cfg_t *hardwareCfg = &(Lin_UartCfg->dataPtr);
    uint32 Lin_BaseAddr = Mcu_GetModuleBase((Mcu_ModuleType)Lin_UartCfg->UartModule);
    /* set baud rate */
    uint32 Pcr1 = 0;
    uint32 Freq = hardwareCfg->frequency;
    uint32 Baudrate = Freq / calcbaud;
    Pcr1 = REG_READ32(Lin_BaseAddr + PCR1_OFF);
    Pcr1 &= ~FM_PCR1_BAUDRATECNT;
    Pcr1 |= FV_PCR1_BAUDRATECNT(Baudrate);
    REG_WRITE32(Pcr1, Lin_BaseAddr + PCR1_OFF);
}

void Lin_UartRstMod(const Lin_Uart *Lin_UartCfg)
{
    uint32 Lin_BaseAddr = Mcu_GetModuleBase((Mcu_ModuleType)(Lin_UartCfg->UartModule));
    /* controller will auto detect the baud rate until module reset */
    uint32 Mod_Ctrl = REG_READ32(Lin_BaseAddr + MCR0_OFF);
    Mod_Ctrl |= BM_MCR0_MODRST;
    REG_WRITE32(Mod_Ctrl, Lin_BaseAddr + MCR0_OFF);
    uint32 PollTime = 0u;

    while (REG_READ32(Lin_BaseAddr + MCR0_OFF) & BM_MCR0_MODRST) {
        /* prevent system hang */
        if (PollTime > LIN_POLLING_TIME_OUT) {
            break;
        }

        PollTime ++;
    }
}

#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#ifdef __cplusplus
}
#endif
