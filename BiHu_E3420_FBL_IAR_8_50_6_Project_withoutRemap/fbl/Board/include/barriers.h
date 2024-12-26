/*
 * barriers.h
 *
 * Copyright (c) 2020 Semidrive Semiconductor.
 * All rights reserved.
 *
 * Description: ARM barriers interface.
 *
 * Revision History:
 * -----------------
 */

#ifndef INCLUDE_ARCH_BARRIERS_H
#define INCLUDE_ARCH_BARRIERS_H

#ifdef CONFIG_ARCH_ARMV7R
#include "arch/armv7-r/barriers.h"
#else
#define DSB
#define DMB
#define ISB
#endif

#endif
