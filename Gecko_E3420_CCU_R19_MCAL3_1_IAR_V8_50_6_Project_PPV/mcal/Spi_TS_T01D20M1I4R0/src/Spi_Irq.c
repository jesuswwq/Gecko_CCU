/** **************************************************************************************
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
 * an 'AS IS' basis, WITHOUT WARRANTIES OF ANY KIND, either express or implied.
 *
 *****************************************************************************************/
/** **************************************************************************************
 * \file     Spi_Irq.c
 * \brief    AUTOSAR 4.3.1 MCAL can Driver
 *
 * <table>
 * <tr><th>Date           <th>Version
 * <tr><td>2023/07/27     <td>1.0.0
 * </table>
 *****************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
/*****************************************************************************************
 *                       Include header files
 *****************************************************************************************/
#include "Spi_Cfg.h"
#include "Spi_Irq.h"
#include "Spi_reg.h"
#include "Spi_Driver.h"
#include "RegHelper.h"

/******************************************************************************************
 *                          Global Function Declarations
 *****************************************************************************************/
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

#if ( SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || ( SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
/** **************************************************************************************
 * \brief This function is the comment irq handler.
 *
 * \verbatim
 * Syntax             : static void spi_intr_hdlr(const struct mld_spi_module *spi)
 *
 *
 * Service ID[hex]    : 0x00
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : spi - Pointer to Spi instance set
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : comm irq service funtion.
 * \endverbatim
 * Traceability       : SWSR_SPI_237
 *****************************************************************************************/
static void spi_intr_hdlr(const struct mld_spi_module *spi)
{
    uint8 coreId = Spi_GetCoreID();
    const struct Spi_Driver_Handler *PerCoreHandler = Spi_Handler[coreId];
    const struct Spi_Scheduler *Sche = &PerCoreHandler->scheduler;

    if (SPI_INTERRUPT_MODE == Sche->schedulerMode)
    {
        Spi_HwMainFunctionHandling(spi->idx);
    }
}
/** **************************************************************************************
 * \brief This function handle the spi instance interrupt.
 *
 * \verbatim
 * Syntax             : ISR(Spi1_IrqHandler)
 *
 * Service ID[hex]    : 0x00
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The irq handler of spi1.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_237 SWSR_SPI_256 SW_SM003
 *****************************************************************************************/
ISR(Spi1_IrqHandler)
{
    const struct mld_spi_module *spiBus = &(Spi_Handler[Spi_GetCoreID()]->spiBus[CSIB1].bus);
    spi_intr_hdlr(spiBus);

    if ((uint32)0 == (spiBus->state & (uint32)0x1))
    {
        /*  Unexpected interrupt, mask all interrupts */
        writel(0xFFFF, APB_SPI1_BASE + SPI_IRQ_MASK_OFF);
    }
}
/** **************************************************************************************
 * \brief This function handle the spi instance interrupt.
 *
 * \verbatim
 * Syntax             : ISR(Spi2_IrqHandler)
 *
 * Service ID[hex]    : 0x00
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The irq handler of spi2.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_237 SWSR_SPI_256 SW_SM003
 *****************************************************************************************/
ISR(Spi2_IrqHandler)
{
    const struct mld_spi_module *spiBus = &(Spi_Handler[Spi_GetCoreID()]->spiBus[CSIB2].bus);
    spi_intr_hdlr(spiBus);

    if ((uint32)0 == (spiBus->state & (uint32)0x1))
    {
        /*  Unexpected interrupt, mask all interrupts */
        writel(0xFFFF, APB_SPI2_BASE + SPI_IRQ_MASK_OFF);
    }
}
/** **************************************************************************************
 * \brief This function handle the spi instance interrupt.
 *
 * \verbatim
 * Syntax             : ISR(Spi3_IrqHandler)
 *
 * Service ID[hex]    : 0x00
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The irq handler of spi3.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_237 SWSR_SPI_256 SW_SM003
 *****************************************************************************************/
ISR(Spi3_IrqHandler)
{
    const struct mld_spi_module *spiBus = &(Spi_Handler[Spi_GetCoreID()]->spiBus[CSIB3].bus);
    spi_intr_hdlr(spiBus);

    if ((uint32)0 == (spiBus->state & (uint32)0x1))
    {
        /*  Unexpected interrupt, mask all interrupts */
        writel(0xFFFF, APB_SPI3_BASE + SPI_IRQ_MASK_OFF);
    }
}
/** **************************************************************************************
 * \brief This function handle the spi instance interrupt.
 *
 * \verbatim
 * Syntax             : ISR(Spi4_IrqHandler)
 *
 * Service ID[hex]    : 0x00
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The irq handler of spi4.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_237 SWSR_SPI_256 SW_SM003
 *****************************************************************************************/
ISR(Spi4_IrqHandler)
{
    const struct mld_spi_module *spiBus = &(Spi_Handler[Spi_GetCoreID()]->spiBus[CSIB4].bus);
    spi_intr_hdlr(spiBus);

    if ((uint32)0 == (spiBus->state & (uint32)0x1))
    {
        /*  Unexpected interrupt, mask all interrupts */
        writel(0xFFFF, APB_SPI4_BASE + SPI_IRQ_MASK_OFF);
    }
}
/** **************************************************************************************
 * \brief This function handle the spi instance interrupt.
 *
 * \verbatim
 * Syntax             : ISR(Spi5_IrqHandler)
 *
 * Service ID[hex]    : 0x00
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The irq handler of spi5.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_237 SWSR_SPI_256 SW_SM003
 *****************************************************************************************/
ISR(Spi5_IrqHandler)
{
    const struct mld_spi_module *spiBus = &(Spi_Handler[Spi_GetCoreID()]->spiBus[CSIB5].bus);
    spi_intr_hdlr(spiBus);

    if ((uint32)0 == (spiBus->state & (uint32)0x1))
    {
        /*  Unexpected interrupt, mask all interrupts */
        writel(0xFFFF, APB_SPI5_BASE + SPI_IRQ_MASK_OFF);
    }
}
/** **************************************************************************************
 * \brief This function handle the spi instance interrupt.
 *
 * \verbatim
 * Syntax             : ISR(Spi6_IrqHandler)
 *
 * Service ID[hex]    : 0x00
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The irq handler of spi6.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_237 SWSR_SPI_256 SW_SM003
 *****************************************************************************************/
ISR(Spi6_IrqHandler)
{
    const struct mld_spi_module *spiBus = &(Spi_Handler[Spi_GetCoreID()]->spiBus[CSIB6].bus);
    spi_intr_hdlr(spiBus);

    if ((uint32)0 == (spiBus->state & (uint32)0x1))
    {
        /*  Unexpected interrupt, mask all interrupts */
        writel(0xFFFF, APB_SPI6_BASE + SPI_IRQ_MASK_OFF);
    }
}

#ifdef SEMIDRIVE_E3_SERIES
/** **************************************************************************************
 * \brief This function handle the spi instance interrupt.
 *
 * \verbatim
 * Syntax             : ISR(Spi7_IrqHandler)
 *
 * Service ID[hex]    : 0x00
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The irq handler of spi7.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_237 SWSR_SPI_256 SW_SM003
 *****************************************************************************************/
ISR(Spi7_IrqHandler)
{
    const struct mld_spi_module *spiBus = &(Spi_Handler[Spi_GetCoreID()]->spiBus[CSIB7].bus);
    spi_intr_hdlr(spiBus);

    if ((uint32)0 == (spiBus->state & (uint32)0x1))
    {
        /*  Unexpected interrupt, mask all interrupts */
        writel(0xFFFF, APB_SPI7_BASE + SPI_IRQ_MASK_OFF);
    }
}
/** **************************************************************************************
 * \brief This function handle the spi instance interrupt.
 *
 * \verbatim
 * Syntax             : ISR(Spi8_IrqHandler)
 *
 * Service ID[hex]    : 0x00
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The irq handler of spi8.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_237 SWSR_SPI_256 SW_SM003
 *****************************************************************************************/
ISR(Spi8_IrqHandler)
{
    const struct mld_spi_module *spiBus = &(Spi_Handler[Spi_GetCoreID()]->spiBus[CSIB8].bus);
    spi_intr_hdlr(spiBus);

    if ((uint32)0 == (spiBus->state & (uint32)0x1))
    {
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
/** End of file */

