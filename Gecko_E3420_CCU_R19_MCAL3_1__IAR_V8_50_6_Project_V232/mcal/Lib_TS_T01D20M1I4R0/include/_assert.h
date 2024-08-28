/********************************************************
 *        Copyright(c) 2020    Semidrive                *
 *        All rights reserved.                          *
 ********************************************************/

#ifndef ASSERT_H
#define ASSERT_H

#if DEBUG_LEVEL > 0
#define  ASSERT_ENABLE
#endif

#include "debug.h"
#ifdef ASSERT_ENABLE

#define ASSERT(expr)    \
    do {\
        if (!(expr)) {\
            DBG("Assert @ %s %d\n",__FILE__,__LINE__);\
            while(1);\
        }\
    } while (0)
#else
#define ASSERT(expr)    \
    do {\
        if (!(expr)) {}\
    } while (0)
#endif

#endif  /* __ASSERT_H__ */
