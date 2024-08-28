/********************************************************
 *        Copyright(c) 2020    Semidrive                *
 *        All rights reserved.                          *
 ********************************************************/

/**
 * @file    mem_libc.c
 * @brief   secure version of mem_xxx routines
 */

#if defined(_IAR_C_)
#pragma optimize=none
#elif defined(_GCC_C_)
#pragma GCC optimize ("O0")
#endif

#include <_assert.h>
#include <arch.h>

#define LIB_START_SEC_CODE
#include "Lib_MemMap.h"

void *mini_memcpy_s(void *dst, const void *src, uint32 size)
{
    /*PRQA S 0326 6*/
    uint32 align_src = (unsigned long)src % 4UL;
    uint32 align_dst = (unsigned long)dst % 4UL;
    uint32 sz_saved = size;
    uint8 *dst_p = (uint8 *)dst;
    const uint8 *src_p = (const uint8 *)src;
    uint32 i = 0;

    ASSERT((NULL_PTR != dst_p));    /* copy from 0 is allowed */
    ASSERT(((unsigned long)(-1ULL) - (unsigned long)dst_p) > (unsigned long)size);
    ASSERT(((unsigned long)(-1ULL) - (unsigned long)src_p) > (unsigned long)size);

    if (align_src != align_dst) {
        for (; size > 0; size--, dst_p++, src_p++) {
            *dst_p = *src_p;
        }
    } else {
        uint32 bytes;

        if (0 != align_src) {
            bytes = size > (4 - align_dst) ? (4 - align_dst) : size;

            for (i = 0; i < bytes ; i++, size--, dst_p++, src_p++) {
                *dst_p = *src_p;
            }
        }

        if (size > 4) {
            bytes = size / 4 * 4;
#if defined(MEMCPY_ASM_OPTIMIZED)
            memcpy_4bytes_aligned(dst_p, src_p, bytes);
            dst_p += bytes;
            src_p += bytes;
#else
            uint32 *u32_src_p = (uint32 *)src_p;
            uint32 *u32_dst_p = (uint32 *)dst_p;

            for (uint32 i = 0; i < bytes / 4; i++, src_p += 4, dst_p += 4) {
                *u32_dst_p++ = *u32_src_p++;
            }

#endif
            size -= bytes;
        }

        for (; size > 0; size--, dst_p++, src_p++) {
            *dst_p = *src_p;
        }
    }

    /*PRQA S 2995 2*/
    ASSERT((0 == size) && (dst == (dst_p - sz_saved))
           && (src  == (src_p - sz_saved)));

    return dst;
}

void mini_memclr_s(void *dst, uint32 size)
{
    /*PRQA S 0326 6*/
    uint32 align = (unsigned long)dst % 4;
    uint32 bytes;
    uint8 *dst_p = (uint8 *)dst;
    uint32 sz_saved = size;

    ASSERT(NULL_PTR != dst_p);
    ASSERT(((unsigned long)(-1ULL) - (unsigned long)dst_p) > (unsigned long)size);

    if (align != 0) {
        bytes = size > (4 - align) ? (4 - align) : size;

        for (; bytes > 0; bytes--, size--, dst_p++) {
            *dst_p = 0;
        }
    }

    if (size > 4) {
        bytes = size / 4 * 4;
#if defined(MEMCLR_ASM_OPTIMIZED)
        memclr_4bytes_aligned(dst_p, bytes);
        size -= bytes;
        dst_p += bytes;
#else
        uint32 *u32_dst_p = (uint32 *)dst_p;

        for (; bytes > 0;
             bytes -= 4, size -= 4, dst_p += 4, u32_dst_p++) {
            *u32_dst_p = 0;
        }

#endif
    }

    for (; size > 0; size--, dst_p++) {
        *dst_p = 0;
    }

    /*PRQA S 2995 2*/
    ASSERT((0 == size) && ((uint8 *)dst + sz_saved == dst_p));
}

/*
 * memcmp is not heavily used in this project, so the char by char comparision is
 * acceptable here.
 */
sint32 mini_memcmp_s(const void *mem1, const void *mem2, uint32 size)
{
    uint32 res = 0;
    const uint8 *mem1_p = (const uint8 *)mem1, *mem2_p = (const uint8 *)mem2;
    uint32 sz_saved = size;

    ASSERT((NULL_PTR != mem1_p) && (NULL_PTR != mem2_p));
    ASSERT(((unsigned long)(-1ULL) - (unsigned long)mem1_p) > (unsigned long)size);
    ASSERT(((unsigned long)(-1ULL) - (unsigned long)mem2_p) > (unsigned long)size);

    for (; size > 0; size--, mem1_p++, mem2_p++) {
        res |= (*mem1_p != *mem2_p);
    }

    /*PRQA S 2992 3*/
    /*PRQA S 2995 2*/
    /*PRQA S 2996 2*/
    ASSERT((0 == size) && (mem1 == mem1_p - sz_saved)
           && (mem2 == mem2_p - sz_saved));

    return res;
}

void *mini_memset_s(void *dst, int val, uint32 size)
{
    uint8 *dst_p = (uint8 *)dst;
    uint32 sz_saved = size;

    ASSERT(NULL_PTR != dst_p);
    ASSERT(((unsigned long)(-1ULL) - (unsigned long)dst_p) > (unsigned long)size);

    for (; size > 0; size--, dst_p++) {
        *dst_p = (uint8)val;
    }

    /*PRQA S 2992 3*/
    /*PRQA S 2995 2*/
    /*PRQA S 2996 2*/
    ASSERT((0 == size) && (dst == dst_p - sz_saved));

    return dst;
}

void *mini_memmove_s(void *dst, const void *src, uint32 size)
{
    uint8 *dst_p = (uint8 *)dst;
    const uint8 *src_p = (const uint8 *) src;
    int i = 0;

    ASSERT((NULL_PTR != dst_p));    /* move from 0 is allowed */

    ASSERT(((unsigned long)(-1ULL) - (unsigned long)dst_p) > (unsigned long)size);
    ASSERT(((unsigned long)(-1ULL) - (unsigned long)src_p) > (unsigned long)size);

    uint32 dis = src_p > dst_p ? (uint32)(unsigned long)(src_p - dst_p) :
                 (uint32)(unsigned long)(dst_p - src_p);

    if ((0 == dis) || (0 == size)) {
        /* do nothing */
    } else if ( (dis >= size) || (src_p > dst_p)) {
        mini_memcpy_s(dst_p, src_p, size);
    } else {
        /* from end */
        src_p += size;
        dst_p += size;

        for (i = size; i > 0; i--) {
            dst_p--;
            src_p--;
            *dst_p = *src_p;
        }

        /*PRQA S 2995 2*/
        ASSERT((dst_p == (uint8 *)dst) && (src_p == (uint8 *)src));
    }

    return dst;
}

#if defined(NO_STDLIB)
void *memcpy (void *dst, const void *src, uint32 sz)
{
    mini_memcpy_s(dst, src, sz);

    return dst;
}

void *memset(void *dst, int val, uint32 sz)
{
    return mini_memset_s(dst, (uint8)val, sz);
}
#endif

void *mini_mem_rvscpy_s(void *dst, const void *src, uint32 sz)
{
    const uint8 *p_src = (const uint8 *)src + sz - 1;
    uint8 *p_dst = (uint8 *)dst;
    uint32 sz_saved = sz;

    ASSERT((NULL_PTR != dst) && (sz > 0));

    while (sz) {
        *p_dst++ = *p_src--;
        sz--;
    }
    /*PRQA S 2995 6*/
    /*PRQA S 2996 6*/
    /*PRQA S 2991 6*/
    /*PRQA S 2992 6*/
    ASSERT((0 == sz)
           && ((p_src + 1) == (uint8 *)src)
           && (p_dst == ((uint8 *)dst + sz_saved)));

    return dst;
}

/* memory reverse */
void *mini_mem_rvs_s(void *mem, uint32 sz)
{
    uint32 n = (sz + 1) / 2;
    uint8 *begin = (uint8 *)mem;
    /*PRQA S 2822 6*/
    uint8 *end = (uint8 *) (mem) + sz - 1;

    ASSERT((NULL_PTR != mem) && (sz > 0));

    while (n) {
        uint8 tmp = *begin;
        *begin = *end;
        *end = tmp;
        begin++;
        end--;
        n--;
    }
    /*PRQA S 2996 6*/
    /*PRQA S 2995 6*/
    /*PRQA S 2992 6*/
    /*PRQA S 2991 6*/
    ASSERT(0 == n);

    return mem;
}

#define LIB_STOP_SEC_CODE
#include "Lib_MemMap.h"
