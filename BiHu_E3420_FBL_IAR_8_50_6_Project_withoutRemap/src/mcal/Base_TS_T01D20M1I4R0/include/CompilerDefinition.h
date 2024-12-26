/**
 *   @file           CompilerDefinition.h
 *
 *   @brief   Compiler definitions per active compiler.
 */

/********************************************************
 *        Copyright(c) 2020    Semidrive                *
 *        All rights reserved.                          *
 ********************************************************/

#ifndef COMPILERDEFINITION_H
#define COMPILERDEFINITION_H

#ifdef __cplusplus
extern "C" {
#endif
/* Version and Check Begin */
/* Version Info Begin */
#define COMPILERDEFINITION_H_VENDOR_ID    0x8C
#define COMPILERDEFINITION_H_AR_RELEASE_MAJOR_VERSION    4
#define COMPILERDEFINITION_H_AR_RELEASE_MINOR_VERSION    3
#define COMPILERDEFINITION_H_AR_RELEASE_REVISION_VERSION 1
#define COMPILERDEFINITION_H_SW_MAJOR_VERSION    1
#define COMPILERDEFINITION_H_SW_MINOR_VERSION    0
#define COMPILERDEFINITION_H_SW_PATCH_VERSION    0
/* Version Info End */
/* Version and Check End */



#if __ARMCC_VERSION > 6000000
    #if (defined(__clang__))
        /* ARM Compiler6 Clang */
        #define _ARMCLANG_C_
    #endif  /* defined(__clang__)*/
#elif (defined(__ICCARM__))
    /* IAR compiler */
    #define _IAR_C_
#elif (defined(__ghs__))
    /* GreenHills compiler */
    #define _GHS_C_
#elif (defined(__GNUC__))
    #if (defined(__unix__))
    /* gcc (for Linux host)*/
        #define _GCC_C_
    #else
    /*  arm-none-eabi-gcc */
        #define _ARMGCC_C_
    #endif
#else
    #error "Compilor not supported yet!"
#endif

#ifdef __cplusplus
}
#endif

#endif /* #ifndef COMPILERDEFINITION_H */
