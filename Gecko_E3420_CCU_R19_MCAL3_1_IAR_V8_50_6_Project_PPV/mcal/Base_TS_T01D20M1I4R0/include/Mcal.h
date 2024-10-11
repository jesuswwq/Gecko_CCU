/**
 *   @file    Mcal.h
 *
 *   @brief
 *   @details
 *
 */

/********************************************************
 *        Copyright(c) 2020    Semidrive                *
 *        All rights reserved.                          *
 ********************************************************/

#ifndef MCAL_H
#define MCAL_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "OsIf.h"
#include "Compiler.h"
#include "Std_Types.h"

/* Version and Check Begin */
/* Version Info Begin */
#define MCAL_H_VENDOR_ID 0x8C
#define MCAL_H_AR_RELEASE_MAJOR_VERSION 4
#define MCAL_H_AR_RELEASE_MINOR_VERSION 3
#define MCAL_H_AR_RELEASE_REVISION_VERSION 1
#define MCAL_H_SW_MAJOR_VERSION 1
#define MCAL_H_SW_MINOR_VERSION 0
#define MCAL_H_SW_PATCH_VERSION 0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((MCAL_H_AR_RELEASE_MAJOR_VERSION != COMPILER_H_AR_RELEASE_MAJOR_VERSION) || (MCAL_H_AR_RELEASE_MINOR_VERSION != COMPILER_H_AR_RELEASE_MINOR_VERSION) || (MCAL_H_AR_RELEASE_REVISION_VERSION != COMPILER_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Mcal.h and Compiler.h AutoSAR version not match!"
#endif
#endif /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((MCAL_H_SW_MAJOR_VERSION != COMPILER_H_SW_MAJOR_VERSION) || (MCAL_H_SW_MINOR_VERSION != COMPILER_H_SW_MINOR_VERSION) || (MCAL_H_SW_PATCH_VERSION != COMPILER_H_SW_PATCH_VERSION))
#error "Opps, Mcal.h and Compiler.h Software version not match!"
#endif
#endif /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((MCAL_H_AR_RELEASE_MAJOR_VERSION != STD_TYPES_H_AR_RELEASE_MAJOR_VERSION) || (MCAL_H_AR_RELEASE_MINOR_VERSION != STD_TYPES_H_AR_RELEASE_MINOR_VERSION) || (MCAL_H_AR_RELEASE_REVISION_VERSION != STD_TYPES_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Mcal.h and Std_Types.h AutoSAR version not match!"
#endif
#endif /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((MCAL_H_SW_MAJOR_VERSION != STD_TYPES_H_SW_MAJOR_VERSION) || (MCAL_H_SW_MINOR_VERSION != STD_TYPES_H_SW_MINOR_VERSION) || (MCAL_H_SW_PATCH_VERSION != STD_TYPES_H_SW_PATCH_VERSION))
#error "Opps, Mcal.h and Std_Types.h Software version not match!"
#endif
#endif /* !DISABLE_MCAL_SW_VER_CHECK */
    /* Version Check End */
    /* Version and Check End */

#define MCAL_MODULE_ID 0



#if defined(_ARMGCC_C_) || defined(_ARMCLANG_C_)

#define ASM_KEYWORD __asm

#define EXECUTE_WAIT() ASM_KEYWORD("  wfi")

#define ALIGNED_VARS_START(sec_name, align)

#define VAR_ALIGN(v, size) __attribute__((aligned(size))) v

#define ALIGNED_VARS_STOP()

#define PACKED __attribute__((__packed__))

#define ALIGNED(x) __attribute__((aligned(x)))

    static inline void DWORD_WR(uint64 v, uint64 *dst)
    {
        uint32 v1 = v;
        uint32 v2 = (v >> 32);
        __asm volatile(
            "mov r0, %0\n\t"
            "mov r1, %1\n\t"
            "mov r2, %2\n\t"
            "stm r2, {r0-r1}\n\t"
            :
            : "r"(v1), "r"(v2), "r"(dst)
            : "r0", "r1", "r2");
    }

#define DISABLE_INTERRUPTS() ASM_KEYWORD("cpsid if")
#define ENABLE_INTERRUPTS() ASM_KEYWORD("cpsie if")

    static inline uint32 ReadMSR(void)
    {
        uint32 v = 0;
        __asm volatile(
            "mrs %0, cpsr\n"
            : "=r"(v)
            :
            :);
        return v;
    }

    static inline void WriteMSR(uint32 v)
    {
        __asm volatile(
            "msr cpsr, %0\n"
            :
            : "r"(v)
            :);
    }

#endif /* defined(_ARMGCC_C_) || defined(_ARMCLANG_C_) */

#if defined(_IAR_C_)
#include <stdalign.h>

#define EXTEND_AS_STRING(x) #x

#define ASM_KEYWORD asm

#define EXECUTE_WAIT() ASM_KEYWORD("  wfi")

#define ALIGNED_VARS_START(sec_name, align)
// c11 align macro depend with  "stdalign.h"
#define VAR_ALIGN(v, size) alignas(size) v

#define ALIGNED_VARS_STOP()

#define PACKED __packed

#define ALIGNED(x) __attribute__((aligned(x)))

    static inline void DWORD_WR(uint64 v, uint64 *dst)
    {
        uint32 v1 = v;
        uint32 v2 = (v >> 32);
        ASM_KEYWORD volatile(
            "mov r0, %0\n\t"
            "mov r1, %1\n\t"
            "mov r2, %2\n\t"
            "stm r2, {r0-r1}\n\t"
            :
            : "r"(v1), "r"(v2), "r"(dst)
            : "r0", "r1", "r2");
    }

#define DISABLE_INTERRUPTS() ASM_KEYWORD("cpsid if")
#define ENABLE_INTERRUPTS() ASM_KEYWORD("cpsie if")

    static inline uint32 ReadMSR(void)
    {
        register uint32 v = 0;

        ASM_KEYWORD volatile("mrs %0, cpsr"
                             : "=r"(v)
                             :
                             :);

        return (uint32)v;
    }

    static inline void WriteMSR(uint32 v)
    {
        ASM_KEYWORD volatile(
            "msr cpsr_cxsf, %0\n"
            :
            : "r"(v)
            :);
    }

#endif /* defined(_IAR_C_) */

#if defined(_GCC_C_)

#define ASM_KEYWORD(x) __asm__ x

#define EXECUTE_WAIT()

#define ALIGNED_VARS_START(sec_name, align)

#define VAR_ALIGN(v, size) __attribute__((aligned(size))) v

#define ALIGNED_VARS_STOP()

#define PACKED

#define ALIGNED(x) __attribute__((aligned(x)))

#define MCAL_FAULT_INJECTION_POINT(label)

    static inline void DWORD_WR(uint64 v, uint64 *dst)
    {
        *dst = v;
    }

#define DISABLE_INTERRUPTS()

    static inline uint32 ReadMSR(void)
    {
        return 0;
    }

#define WriteMSR(v)

#endif /* defined(_GCC_C_) */

#if defined(_GHS_C_)

#define ASM_KEYWORD __asm__

#define EXECUTE_WAIT()

#define ALIGNED_VARS_START(sec_name, align)

#define VAR_ALIGN(v, size) __attribute__((aligned(size))) v

#define ALIGNED_VARS_STOP()

#define PACKED

#define ALIGNED(x) __attribute__((aligned(x)))

#define MCAL_FAULT_INJECTION_POINT(label)

    static inline void DWORD_WR(uint64 v, uint64 *dst)
    {
        *(volatile uint64 *)dst = v;
    }

#define DISABLE_INTERRUPTS()

    static inline uint32 ReadMSR(void)
    {
        return 0;
    }

#define WriteMSR(v)

#endif /* defined(_GHS_C_) */

//#ifdef CRITIAL_AREA_STATISTIC
#define MAX_MODULE 16 //max module id
#define MAX_AREA 16   //max critial area
    extern uint32 start_ticks;
    extern uint32 end_ticks;
    extern uint32 max_ticks;
    extern uint32 cur_ticks;
    extern uint32 critial_area[MAX_MODULE][MAX_AREA];
    //#endif

#if defined(AUTOSAR_OS_NOT_USED)
#if defined(USE_SW_VECTOR_MODE)
#define ISR(IsrName) void IsrName(void)
#endif /* defined(USE_SW_VECTOR_MODE) */

#define EXIT_INTERRUPT()

#ifndef CRITIAL_AREA_STATISTIC
#define SuspendAllInterrupts() ASM_KEYWORD("cpsid if")
#else
#define SuspendAllInterrupts(a, b) \
    ASM_KEYWORD("cpsid if");       \
    start_ticks = read_pmccntr();

#endif

#ifndef CRITIAL_AREA_STATISTIC
#define ResumeAllInterrupts() ASM_KEYWORD("cpsie if")
#else
#define ResumeAllInterrupts(a, b)                             \
    do                                                        \
    {                                                         \
        end_ticks = read_pmccntr();                           \
        max_ticks = critial_area[a][b];                       \
        if (end_ticks > start_ticks)                          \
        {                                                     \
            cur_ticks = end_ticks - start_ticks;              \
        }                                                     \
        else                                                  \
        {                                                     \
            cur_ticks = 0xFFFFFFFF + start_ticks - end_ticks; \
        }                                                     \
        if (max_ticks < cur_ticks)                            \
        {                                                     \
            critial_area[a][b] = cur_ticks;                   \
        }                                                     \
        ASM_KEYWORD("cpsie if");                              \
    } while (0)

#endif

#else
/* Usually, ISR defined as "#define ISR(IsrName) void IsrName(void)" */
#define EXIT_INTERRUPT()
#define ISR(IsrName) void IsrName(void)

#endif /* defined(AUTOSAR_OS_NOT_USED) */

/* pointer to pointer to variable */
#define P2P2VAR(ptrtype, memclass, ptrclass) ptrtype **

#define P2P2CONST(ptrtype, memclass, ptrclass) const ptrtype **

#ifdef __cplusplus
}
#endif

#endif /* #ifndef _MCAL_H_ */
