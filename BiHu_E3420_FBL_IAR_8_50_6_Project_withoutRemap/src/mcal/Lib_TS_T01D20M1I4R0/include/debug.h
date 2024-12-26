/********************************************************
 *          Copyright(c) 2018   Semidrive               *
 *******************************************************/

/**
 * @file    debug.h
 * @brief   DBG definitions.
 */

#ifndef DBG_H
#define DBG_H

#define ERROR_LEVEL     1
#define INFO_LEVEL      2

#include "mini_libc.h"

#if 0
#ifdef EN_UNIFIED_IMAGE
#include "mbox.h"
#define PRINT(fmt, args...)  do{\
                                while (!semphore_try_lock(MAILBOX, SEMPHORE_BIT_TTY));\
                                (void)mini_printf(fmt, ##args);\
                                semphore_unlock(MAILBOX, SEMPHORE_BIT_TTY);\
                            }while(0)
#else
#define PRINT(fmt, args...)  (void)mini_printf(fmt, ##args);
#endif
#else
#define PRINT(fmt, args...) 
#endif

#ifndef DEBUG_LEVEL
#define DEBUG_LEVEL 1
#warning "DEBUG_LEVEL not defined，will use default value 1. You may want to define it as 0 in production phase"
#endif

#if DEBUG_LEVEL >= INFO_LEVEL
#define DBG    PRINT
#else
#define DBG(...)
#endif

#if DEBUG_LEVEL >= ERROR_LEVEL
#define ERROR  PRINT
#else
#define ERROR(...)
#endif



#endif /* __DBG_H__ */
