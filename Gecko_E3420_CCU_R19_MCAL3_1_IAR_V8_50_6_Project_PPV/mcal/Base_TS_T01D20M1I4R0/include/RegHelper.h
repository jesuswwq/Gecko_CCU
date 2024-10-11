/**
 *   @file    RegHelper.h
 *
 *   @brief   HW register access layer.
 */

/********************************************************
 *        Copyright(c) 2020    Semidrive                *
 *        All rights reserved.                          *
 ********************************************************/

#ifndef REGHELPER_H
#define REGHELPER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
/* Version and Check Begin */
/* Version Info Begin */
#define REGHELPER_H_VENDOR_ID    0x8C
#define REGHELPER_H_AR_RELEASE_MAJOR_VERSION    4
#define REGHELPER_H_AR_RELEASE_MINOR_VERSION    3
#define REGHELPER_H_AR_RELEASE_REVISION_VERSION 1
#define REGHELPER_H_SW_MAJOR_VERSION    1
#define REGHELPER_H_SW_MINOR_VERSION    0
#define REGHELPER_H_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((REGHELPER_H_AR_RELEASE_MAJOR_VERSION != PLATFORM_TYPES_H_AR_RELEASE_MAJOR_VERSION)\
    || (REGHELPER_H_AR_RELEASE_MINOR_VERSION != PLATFORM_TYPES_H_AR_RELEASE_MINOR_VERSION)\
    || (REGHELPER_H_AR_RELEASE_REVISION_VERSION != PLATFORM_TYPES_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, RegHelper.h and Platform_Types.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((REGHELPER_H_SW_MAJOR_VERSION != PLATFORM_TYPES_H_SW_MAJOR_VERSION)\
    || (REGHELPER_H_SW_MINOR_VERSION != PLATFORM_TYPES_H_SW_MINOR_VERSION)\
    || (REGHELPER_H_SW_PATCH_VERSION != PLATFORM_TYPES_H_SW_PATCH_VERSION))
#error "Opps, RegHelper.h and Platform_Types.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */

#define writell(v, a)   (*(volatile uint64*)(a)) = (uint64) (v)
#define readll(a)       (*(volatile uint64*)(a))
#define readl(a)        (*(volatile uint32*)(a))
#define writel(v, a)    (*(volatile uint32*)(a)) = (uint32) (v)
#define readh(a)        (*(volatile uint16*)(a))
#define writeh(v, a)    (*(volatile uint16*)(a)) = (uint16) (v)
#define readb(a)        (*(volatile uint8*)(a))
#define writeb(v, a)    (*(volatile uint8*)(a))  = (uint8) (v)


#define REG64(addr) ((volatile uint64 *)(addr))
#define REG32(addr) ((volatile uint32 *)(addr))
#define REG16(addr) ((volatile uint16 *)(addr))
#define REG8(addr) ((volatile uint8 *)(addr))


#define RMWREG64(addr, startbit, width, val)                                    \
              do{                                                               \
                uint64 temp = *REG64(addr);                                     \
                temp &= ~((((uint64)1u<<(width)) - 1u) << (startbit));          \
                temp |= ((uint64)(val) << (startbit));                          \
                *REG64(addr) = temp;                                            \
              }while(0)

#define RMWREG32(addr, startbit, width, val)                                    \
              do{                                                               \
                uint32 temp = *REG32(addr);                                     \
                temp &= ~((((uint32)1u<<(width)) - 1u) << (startbit));          \
                temp |= ((uint32)(val) << (startbit));                          \
                *REG32(addr) = temp;                                            \
              }while(0)

#define RMWREG16(addr, startbit, width, val)                                    \
              do{                                                               \
                uint16 temp = *REG16(addr);                                     \
                temp &= ~((((uint16)1u<<(width)) - 1u) << (startbit));          \
                temp |= ((uint16)(val) << (startbit));                          \
                *REG16(addr) = temp;                                            \
              }while(0)

#define RMWREG8(addr, startbit, width, val)                                    \
              do{                                                               \
                uint8 temp = *REG8(addr);                                       \
                temp &= ~((((uint8)1u<<(width)) - 1u) << (startbit));           \
                temp |= ((uint8)(val) << (startbit));                           \
                *REG8(addr) = temp;                                             \
              }while(0)

#define reg32(addr)     (*(volatile uint32 *)(addr))
#define reg16(addr)     (*(volatile uint16 *)(addr))
#define reg8(addr)      (*(volatile uint8 *)(addr))

#define rmw64           RMWREG64
#define rmw32           RMWREG32
#define rmw16           RMWREG16
#define rmw8            RMWREG8

#define REG_READ32(a)   readl((a))
#define REG_READ16(a)   readh(a)
#define REG_READ8(a)    readb(a)

#define REG_WRITE32(v, a)   writel((v), (a))
#define REG_WRITE16(v, a)   writeh(v, a)
#define REG_WRITE8(v, a)    writeb(v, a)

#define REG_RMW32   RMWREG32
#define REG_RMW16   RMWREG16
#define REG_RMW8    RMWREG8

#define BIT(nr)       (1U << (nr))
#define BITS_WIDTH(x) ((1U << (x)) - 1)
#define BIT_MASK(x) (((x) >= (sizeof(unsigned long) * 8U)) ? (0xFFFFFFFFU) : ((1UL << (x)) - 1UL))
#define SET_BITS32(x, start, width) (x = ((uint32)x | ((BITS_WIDTH(width)) << start)))
#define CLEAR_BITS32(x, start, width) (x = ((uint32)x & (~((BITS_WIDTH(width)) << start))))
#define GET_ONE_BYTE(v, start_bit) (((uint32)v & (0xFF << start_bit)) >> start_bit)
#define BIT_SHIFT(x, bit) (((x) >> (bit)) & 1)
#define BITS(x, high, low) ((x) & (((1UL<<((high)+1))-1) & ~((1UL<<(low))-1)))
#define BITS_SHIFT(x, high, low) (((x) >> (low)) & ((1UL<<((high)-(low)+1))-1))





LOCAL_INLINE Std_ReturnType Reg_Write_ReadBack32(uint32 v, uint32 a, uint32 mask)
{
    writel(v, a);
    if((v & mask) == (readl(a) & mask)) {
        return E_OK;
    } else {
        return E_NOT_OK;
    }
}

LOCAL_INLINE Std_ReturnType Reg_RMW_ReadBack32(uint32 addr, uint32 startbit, uint32 width, uint32 val, uint32 mask)
{
    rmw32(addr, startbit, width, val);
    if((val & mask) == (((readl(addr)>>startbit)&((1u<<(width)) - 1u)) & mask)) {
        return E_OK;
    } else {
        return E_NOT_OK;
    }
}

#ifdef __cplusplus
}
#endif
#endif  /* REGHELPER_H */
