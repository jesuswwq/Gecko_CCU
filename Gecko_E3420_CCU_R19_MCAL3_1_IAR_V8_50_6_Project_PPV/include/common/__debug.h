/*
 * debug.h
 *
 * Copyright (c) 2020 Semidrive Semiconductor.
 * All rights reserved.
 *
 * Description: debug interface.
 *
 * Revision History:
 * -----------------
 */

#ifndef _INCLUDE_DEBUG_H
#define _INCLUDE_DEBUG_H

#include "__compiler.h"
#include "types.h"
#include "debug.h"
#include <stdio.h>
#include <_assert.h>

#define __CONFIG_DEBUG
#define CONFIG_DEBUG_LEVEL 2

/* SSDK debug level */
#define SSDK_EMERG     0  /* System is unusable */
#define SSDK_ALERT     1  /* Action must be taken immediately */
#define SSDK_CRIT      2  /* Critical conditions */
#define SSDK_ERR       3  /* Error conditions */
#define SSDK_WARNING   4  /* Warning conditions */
#define SSDK_NOTICE    5  /* Normal, but significant, condition */
#define SSDK_INFO      6  /* Informational message */
#define SSDK_DEBUG     7  /* Debug-level message */

/* SSDK printf */
#ifdef __CONFIG_DEBUG
#define ssdk_printf(level, x...)    do { if ((level) <= CONFIG_DEBUG_LEVEL) {PRINT(x); } } while (0)
#define PANIC()
#else
#define ssdk_printf(level, x...) PRINT(x)
#define PANIC()
#endif

__BEGIN_CDECLS

/*
 * panic function.
 *
 * @param[in] filename Panic file name.
 * @param[in] linenum  Panic line num.
 */
#ifdef CONFIG_DEBUG
void ssdk_panic(const uint8_t *filename, int linenum);
#else
#define ssdk_panic(filename, linenum)
#endif

/*
 * hex dump function.
 *
 * @param[in] ptr dump data address.
 * @param[in] len dump data length.
 */
#ifdef CONFIG_DEBUG
void hexdump(const void *ptr, uint32 len);
#else
#define hexdump(ptr, len)
#endif

/*
 * hex dump8 function with display address.
 *
 * @param[in] ptr dump data address.
 * @param[in] len dump data length.
 * @param[in] disp_addr display address.
 */
#ifdef CONFIG_DEBUG
void hexdump8_ex(const void *ptr, uint32 len, uint64_t disp_addr);
#else
#define hexdump8_ex(ptr, len, disp_addr)
#endif

__END_CDECLS

#endif
