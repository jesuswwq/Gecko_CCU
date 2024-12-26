/********************************************************
 *  Copyright(c) 2019   Semidrive       *
 *  All Right Reserved.
 *******************************************************/

#ifndef HELPER_H
#define HELPER_H

#include "RegHelper.h"

#define REG64(addr) ((volatile uint64_t *)(unsigned long)(addr))
#define REG32(addr) ((volatile uint32 *)(unsigned long)(addr))
#define REG16(addr) ((volatile uint16 *)(unsigned long)(addr))
#define REG8(addr) ((volatile uint8 *)(unsigned long)(addr))

#define RMWREG64(addr, startbit, width, val) *REG64(addr) = (*REG64(addr) & ~(((1<<(width)) - 1) << (startbit))) | ((val) << (startbit))
#define RMWREG32(addr, startbit, width, val) *REG32(addr) = (*REG32(addr) & ~(((1<<(width)) - 1) << (startbit))) | ((val) << (startbit))
#define RMWREG16(addr, startbit, width, val) *REG16(addr) = (*REG16(addr) & ~(((1<<(width)) - 1) << (startbit))) | ((val) << (startbit))
#define RMWREG8(addr, startbit, width, val) *REG8(addr) = (*REG8(addr) & ~(((1<<(width)) - 1) << (startbit))) | ((val) << (startbit))

#define REG_RMWREG64(addr, startbit, width, val)    RMWREG64(addr, startbit, width, val)
#define REG_RMWREG32(addr, startbit, width, val)    RMWREG32(addr, startbit, width, val)
#define REG_RMWREG16(addr, startbit, width, val)    RMWREG16(addr, startbit, width, val)
#define REG_RMWREG8(addr, startbit, width, val)     RMWREG8(addr, startbit, width, val)

#define BIT_(x)     (0x01u << (x))

#define UNUSED_VAR(x)   (x) = (x)

#define __WEAK__    __attribute__((weak))

#define FLD_OFFSET(st, fld)     ((uint32)(unsigned long)(&(((st*)0)->fld)))

#define GET_BITS(v, s, w)   \
        (((v) >> (s)) & (0xffffffff >> (32 - (w))))

#define _MIN(a, b) (((a) < (b)) ? (a) : (b))
#define _MAX(a, b) (((a) > (b)) ? (a) : (b))


#define B2W(b0, b1, b2, b3) \
    ((b0) | ((b1) << 8) | ((b2) << 16) | ((b3) << 24))

#endif  /* HELPER_H */
