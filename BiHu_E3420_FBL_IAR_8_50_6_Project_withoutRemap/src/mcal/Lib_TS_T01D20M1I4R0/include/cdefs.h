/********************************************************
 *        Copyright(c) 2020    Semidrive                *
 *        All rights reserved.                          *
 ********************************************************/

#ifndef CDEFS_H
#define CDEFS_H

#ifndef ROUNDUP
#define ROUNDUP(a, b) (((a) + (uint32)((b)-1)) & (uint32)~((b)-1))
#endif

#define ROUNDDOWN(a, b) ((a) & ~((b)-1))

#define ALIGN(a, b) ROUNDUP(a, b)
#define IS_ALIGNED(a, b) (!(((unsigned long)(a)) & (((unsigned long)(b))-1)))

#define _MIN(a, b) (((a) < (b)) ? (a) : (b))
#define _MAX(a, b) (((a) > (b)) ? (a) : (b))

#define DIV_ROUND_UP(n,d) (((n) + (d) - 1) / (d))

#define _offsetof(type, member) (uint32)&(((type*)0)->member)

#define containerof(ptr, type, member) \
    ((type *)((unsigned long)(ptr) - _offsetof(type, member)))


#define ARRAY_SZ(x) (sizeof(x)/sizeof(x[0]))

typedef void (*fv_v) (void);

#define __dead2        __attribute__((__noreturn__))
#define __deprecated    __attribute__((__deprecated__))
#define __packed    __attribute__((__packed__))
#define __used        __attribute__((__used__))
#define __unused    __attribute__((__unused__))
#define __aligned(x)    __attribute__((__aligned__(x)))
#define __section(x)    __attribute__((__section__(x)))
#if RECLAIM_INIT_CODE
/*
 * Add each function to a section that is unique so the functions can still
 * be garbage collected
 */
#define __init        __section(".text.init." __FILE__ "." __XSTRING(__LINE__))
#else
#define __init
#endif

#if defined(__ICCARM__)
#define _SECTION(x)  @ #x
#define _USED   __root
#else
#define _SECTION(x)  __attribute__((section(#x)))
#define _USED    __attribute__((used))
#define __no_init
#endif

#define __printflike(fmtarg, firstvararg) \
        __attribute__((__format__ (__printf__, fmtarg, firstvararg)))

#ifndef __weak_reference
#define __weak_reference(sym, alias)    \
    __asm__(".weak alias");        \
    __asm__(".equ alias, sym")
#endif

#define __STRING(x)    #x
#define __XSTRING(x)    __STRING(x)

#endif /* CDEFS_H */
