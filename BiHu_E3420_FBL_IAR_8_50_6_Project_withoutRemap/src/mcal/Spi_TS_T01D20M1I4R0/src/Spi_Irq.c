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
 * @file  Spi_Irq.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Spi plugins.
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "Spi.h"
#include "Spi_reg.h"

#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

#if ( SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || ( SPI_LEVEL_DELIVERED == SPI_LEVEL_2)

static FUNC(void, SPI_CODE)
spi_intr_hdlr(P2VAR(void, AUTOMATIC, SPI_VAR) arg)
{
    struct Spi_Driver_Handler *PerCoreHandler = &SpiHandler[Spi_GetCoreID()];
    struct Spi_Scheduler *Sche = &PerCoreHandler->Scheduler;
    struct mld_spi_module *spi = (struct mld_spi_module *)arg;

    if (Sche->SchedulerMode == SPI_INTERRUPT_MODE) {
        Spi_HwMainFunctionHandling(spi->idx);
    }
}

void Spi1_IrqHandler(void)
{
    struct mld_spi_module *Spi = &SpiHandler[Spi_GetCoreID()].SpiBus[CSIB1].Bus;
    spi_intr_hdlr((void *)Spi);

    if (!Spi->state) {
        /*  Unexpected interrupt, mask all interrupts */
        writel(0xFFFF, APB_SPI1_BASE + SPI_IRQ_MASK_OFF);
    }
}

void Spi2_IrqHandler(void)
{
    struct mld_spi_module *Spi = &SpiHandler[Spi_GetCoreID()].SpiBus[CSIB2].Bus;
    spi_intr_hdlr((void *)Spi);

    if (!Spi->state) {
        /*  Unexpected interrupt, mask all interrupts */
        writel(0xFFFF, APB_SPI2_BASE + SPI_IRQ_MASK_OFF);
    }
}

void Spi3_IrqHandler(void)
{
    struct mld_spi_module *Spi = &SpiHandler[Spi_GetCoreID()].SpiBus[CSIB3].Bus;
    spi_intr_hdlr((void *)Spi);

    if (!Spi->state) {
        /*  Unexpected interrupt, mask all interrupts */
        writel(0xFFFF, APB_SPI3_BASE + SPI_IRQ_MASK_OFF);
    }
}

void Spi4_IrqHandler(void)
{
    struct mld_spi_module *Spi = &SpiHandler[Spi_GetCoreID()].SpiBus[CSIB4].Bus;
    spi_intr_hdlr((void *)Spi);

    if (!Spi->state) {
        /*  Unexpected interrupt, mask all interrupts */
        writel(0xFFFF, APB_SPI4_BASE + SPI_IRQ_MASK_OFF);
    }
}

void Spi5_IrqHandler(void)
{
    struct mld_spi_module *Spi = &SpiHandler[Spi_GetCoreID()].SpiBus[CSIB5].Bus;
    spi_intr_hdlr((void *)Spi);

    if (!Spi->state) {
        /*  Unexpected interrupt, mask all interrupts */
        writel(0xFFFF, APB_SPI5_BASE + SPI_IRQ_MASK_OFF);
    }
}

void Spi6_IrqHandler(void)
{
    struct mld_spi_module *Spi = &SpiHandler[Spi_GetCoreID()].SpiBus[CSIB6].Bus;
    spi_intr_hdlr((void *)Spi);

    if (!Spi->state) {
        /*  Unexpected interrupt, mask all interrupts */
        writel(0xFFFF, APB_SPI6_BASE + SPI_IRQ_MASK_OFF);
    }
}

#ifdef SEMIDRIVE_E3_SERIES
void Spi7_IrqHandler(void)
{
    struct mld_spi_module *Spi = &SpiHandler[Spi_GetCoreID()].SpiBus[CSIB7].Bus;
    spi_intr_hdlr((void *)Spi);

    if (!Spi->state) {
        /*  Unexpected interrupt, mask all interrupts */
        writel(0xFFFF, APB_SPI7_BASE + SPI_IRQ_MASK_OFF);
    }
}

void Spi8_IrqHandler(void)
{
    struct mld_spi_module *Spi = &SpiHandler[Spi_GetCoreID()].SpiBus[CSIB8].Bus;
    spi_intr_hdlr((void *)Spi);

    if (!Spi->state) {
        /*  Unexpected interrupt, mask all interrupts */
        writel(0xFFFF, APB_SPI8_BASE + SPI_IRQ_MASK_OFF);
    }
}
#endif

#endif

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#ifdef __cplusplus
}
#endif
