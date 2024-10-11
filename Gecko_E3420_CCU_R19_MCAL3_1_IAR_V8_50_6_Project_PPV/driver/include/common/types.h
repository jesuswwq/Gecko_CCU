/*
 * types.h
 *
 * Copyright (c) 2020 Semidrive Semiconductor.
 * All rights reserved.
 *
 * Description: types interface.
 *
 * Revision History:
 * -----------------
 */

#ifndef _INCLUDE_TYPES_H
#define _INCLUDE_TYPES_H

#ifndef ASSEMBLY

#include "Platform_Types.h"

typedef volatile uint32 addr_t;
typedef volatile uint32 vaddr_t;
typedef volatile uint32 paddr_t;

#ifndef bool
typedef boolean bool;
#endif

#ifndef true
#define true  TRUE
#endif

#ifndef false
#define false FALSE
#endif

#endif

#endif
