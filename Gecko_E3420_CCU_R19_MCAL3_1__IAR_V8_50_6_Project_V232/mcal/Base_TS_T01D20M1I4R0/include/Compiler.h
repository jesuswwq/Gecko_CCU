/**
*   @file           Compiler.h
*
*   @brief   Compiler abstraction
*   @details To implement AutoSAR "Specification of Compiler Abstraction, CP, 4.3.1" to provide
*            compiler indenpendency to other modules.
*/

/********************************************************
 *        Copyright(c) 2020    Semidrive                 *
 *        All rights reserved.                           *
 ********************************************************/
#ifndef COMPILER_H
#define COMPILER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Compiler_Cfg.h"
#include "CompilerDefinition.h"
/* Version and Check Begin */
/* Version Info Begin */
#define COMPILER_H_VENDOR_ID    0x8C
#define COMPILER_H_AR_RELEASE_MAJOR_VERSION    4
#define COMPILER_H_AR_RELEASE_MINOR_VERSION    3
#define COMPILER_H_AR_RELEASE_REVISION_VERSION 1
#define COMPILER_H_SW_MAJOR_VERSION    1
#define COMPILER_H_SW_MINOR_VERSION    0
#define COMPILER_H_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((COMPILER_H_AR_RELEASE_MAJOR_VERSION != COMPILER_CFG_H_AR_RELEASE_MAJOR_VERSION)\
    || (COMPILER_H_AR_RELEASE_MINOR_VERSION != COMPILER_CFG_H_AR_RELEASE_MINOR_VERSION)\
    || (COMPILER_H_AR_RELEASE_REVISION_VERSION != COMPILER_CFG_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Compiler.h and Compiler_Cfg.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((COMPILER_H_SW_MAJOR_VERSION != COMPILER_CFG_H_SW_MAJOR_VERSION)\
    || (COMPILER_H_SW_MINOR_VERSION != COMPILER_CFG_H_SW_MINOR_VERSION)\
    || (COMPILER_H_SW_PATCH_VERSION != COMPILER_CFG_H_SW_PATCH_VERSION))
#error "Opps, Compiler.h and Compiler_Cfg.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((COMPILER_H_AR_RELEASE_MAJOR_VERSION != COMPILERDEFINITION_H_AR_RELEASE_MAJOR_VERSION)\
    || (COMPILER_H_AR_RELEASE_MINOR_VERSION != COMPILERDEFINITION_H_AR_RELEASE_MINOR_VERSION)\
    || (COMPILER_H_AR_RELEASE_REVISION_VERSION != COMPILERDEFINITION_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Compiler.h and CompilerDefinition.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((COMPILER_H_SW_MAJOR_VERSION != COMPILERDEFINITION_H_SW_MAJOR_VERSION)\
    || (COMPILER_H_SW_MINOR_VERSION != COMPILERDEFINITION_H_SW_MINOR_VERSION)\
    || (COMPILER_H_SW_PATCH_VERSION != COMPILERDEFINITION_H_SW_PATCH_VERSION))
#error "Opps, Compiler.h and CompilerDefinition.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */


/**
 * @brief The memory class AUTOMATIC shall be provided as empty definition, used for
          the declaration of local pointers. [SWS_COMPILER_00046]
 */
#define AUTOMATIC

/**
 * @brief The memory class TYPEDEF shall be provided as empty definition. This memory
 *        class shall be used within type definitions, where no memory qualifier can be
 *        specified. This can be necessary for defining pointer types, with e.g. P2VAR,
 *        where the macros require two parameters. First parameter can be specified in the
 *        type definition (distance to the memory location referenced by the pointer), but
 *        the second one (memory allocation of the pointer itself) cannot be defined at this
 *        time. Hence, memory class TYPEDEF shall be applied. [SWS_COMPILER_00059]
 */
#define TYPEDEF

/**
 * @brief The compiler abstraction shall provide the NULL_PTR define with a void pointer
 *        to zero definition.
 */
#define NULL_PTR ((void *)0)

/**
 * SWS_COMPILER_00010] The compiler abstraction shall define a symbol for the
 * target compiler according to the following naming convention:
 * _<COMPILERNAME>_C_<PLATFORMNAME>_
 * For G9x MCAL, the compiler list is as followed:
 *      _ARMGCC_C_      (for arm-none-eabi-gcc)
 *      _ARMCLANG_C_    (for ARMCompiler6)
 *      _IAR_C_G9x          (for IAR)

 * _IAR_C_G9x not supported yet.
 */

#ifdef  DISPERSE_PER_CORE_RW_SECTION
#define LOCATE_ALIGNED(size)
#endif

/* SWS  8.2.1 General definitions */
#if defined(_ARMGCC_C_)
#define INLINE  inline
#define LOCAL_INLINE    static inline
#define INTERRUPT_FUNC
#define VECTOR_TBL_BASE __vector_tbl_start
#define ASM_PUBLIC  .global
#define ASM_EXTERN  .extern
#define ASM_WORD    .word
#define ASM_FUNCTION(x) .global x; .type x,"function"; x:
#define ASM_FUNCTION_END(x)
#define ASM         __asm__
#ifndef DISPERSE_PER_CORE_RW_SECTION
#define LOCATE_ALIGNED(size)  __attribute__((aligned((size))))
#endif
#endif /* defined(_ARMGCC_C_) */

#if defined(_GCC_C_)
#define INLINE  inline
#define LOCAL_INLINE    static inline
#define INTERRUPT_FUNC
#define ASM         __asm__
#endif /* defined(_GCC_C_) */

#if defined(_ARMCLANG_C_)
#define INLINE  inline
#define LOCAL_INLINE    static inline
#define INTERRUPT_FUNC
#define VECTOR_TBL_BASE Image$$vector$$Base
#define ASM_PUBLIC  .global
#define ASM_EXTERN  .extern
#define ASM_WORD    .word
#define ASM_FUNCTION(x) .global x; .type x,"function"; x:
#define ASM_FUNCTION_END(x)
#define ASM         __asm__
#ifndef DISPERSE_PER_CORE_RW_SECTION
#define LOCATE_ALIGNED(size)  __attribute__((aligned((size))))
#endif
#endif /* defined(_ARMCLANG_C_) */

#if defined(_GHS_C_)
#define INLINE  inline
#define LOCAL_INLINE    static inline
#define INTERRUPT_FUNC
#define VECTOR_TBL_BASE __vector_tbl_start
#define ASM_PUBLIC  .export
#define ASM_EXTERN  .import
#define ASM_WORD    .word
#define ASM_FUNCTION(x) x:
#define ASM_FUNCTION_END(x)  .endf x
#define ASM         __asm__
#ifndef DISPERSE_PER_CORE_RW_SECTION
#define LOCATE_ALIGNED(size)  __attribute__((aligned((size))))
#endif
#endif /* defined(_GHS_C_) */

#if defined(_IAR_C_)
#define INLINE  inline
#define LOCAL_INLINE    static inline
#define INTERRUPT_FUNC
#define VECTOR_TBL_BASE intvec_start__
#define ASM_PUBLIC  PUBLIC
#define ASM_EXTERN  EXTERN
#define ASM_WORD    DC32
#define ASM_FUNCTION(x) x:
#define ASM_FUNCTION_END(x)
#define ASM         asm
#ifndef DISPERSE_PER_CORE_RW_SECTION
#define LOCATE_ALIGNED(size)  __attribute__((aligned((size))))
#endif
#endif /* #ifdef _IAR_C_ */

/* 8.2.2 Function definitions */
/**
 * @brief FUNC macro for the declaration and definition of functions.
 *
 *   @param   retype      return type of the function
 *   @param   memclass    classification of the function itself
 */
#define FUNC(rettype, memclass) rettype
/**
* @brief FUNC_P2CONST macro for the declaration and definition of functions returning a pointer to a constant
*/
#define FUNC_P2CONST(rettype, ptrclass, memclass) const ptrclass rettype * memclass
/**
* @brief FUNC_P2VAR macro for the declaration and definition of functions returning a pointer to a variable.
*/
#define FUNC_P2VAR(rettype, ptrclass, memclass) ptrclass rettype * memclass

/* 8.2.3 Pointer definitions */
/**
 * @brief Definition of pointers in RAM, pointing to variables. See [SWS_COMPILER_00006]
 */
#define P2VAR(ptrtype, memclass, ptrclass) ptrtype *
/**
 * @brief iDefinition of pointers in RAM pointing to constants.
 */
#define P2CONST(ptrtype, memclass, ptrclass) const ptrtype *
/**
 * @brief Constant pointers accessing variables.
 */
#define CONSTP2VAR(ptrtype, memclass, ptrclass) ptrtype * const
/**
* @brief Constant pointers accessing constants.
*/
#define CONSTP2CONST(ptrtype, memclass, ptrclass) const ptrtype * const
/**
* @brief Pointers to functions.
*/
#define P2FUNC(rettype, ptrclass, fctname) rettype (*fctname)
/**
 * @brief The compiler abstraction for const pointer to function.
 */
#define CONSTP2FUNC(rettype, ptrclass, fctname) rettype (* const fctname)

/* 8.2.4 Constant definitions */
/**
 * @brief CONST macro
 */
#define CONST(type, memclass) const type

/* 8.2.5 Variable definitions */
/**
 * @brief VAR macro for the declaration and definition of variables.
 */
#define VAR(vartype, memclass) vartype

#ifndef  NULL
#define  NULL    NULL_PTR
#endif

#ifndef  UINT32_MAX
#define  UINT32_MAX  (0xFFFFFFFFU)
#endif

#ifdef __cplusplus
}
#endif

#endif /* !defined(COMPILER_H) */
