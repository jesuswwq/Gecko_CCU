/*
 * irq_wrapper.c
 *
 * Copyright (c) 2020 Semidrive Semiconductor.
 * All rights reserved.
 *
 * Description: irq wrapper interface.
 *
 * Revision History:
 * -----------------
 */

#include "irq.h"
#include "debug.h"

#define IRQM_START_SEC_CODE
#include "IrqM_MemMap.h"

void BareMetalBadIRQHandler(void)
{
    DBG("FIQ timeout!\n");

    while (1);
}

void BareMetalIRQHandler(void)
{
#ifdef USE_STACK_COLORATION
    if (!arch_check_exception_stack()) {
        ssdk_printf(SSDK_ALERT, "exception stack overflow!\n");
        return;
    }
#endif

    if (-1 == irq_dispatch()) {
        /* fiq timeout */
        BareMetalBadIRQHandler();
    }
}

void BareMetalBadFIQHandler(void)
{
    DBG("IRQ timeout!\n");

    while (1);
}

void BareMetalFIQHandler(void)
{
    if (-1 == irq_dispatch()) {
        /* irq timeout */
        BareMetalBadFIQHandler();
    }
}

void vApplicationIRQHandler(void)
{
    if (-1 == irq_dispatch()) {
        /* fiq timeout */
        BareMetalBadIRQHandler();
    }
}

#define IRQM_STOP_SEC_CODE
#include "IrqM_MemMap.h"
