/**
*   @file           Platform_Types.h
*
*   @brief   AUTOSAR Base - Header file for platform dependend data type.
*   @details AUTOSAR platform types header file, to implement AutoSAR "Specification of Platform Types".
*            Please refer to this AutoSAR SWS spec for details.
*/

/********************************************************
 *        Copyright(c) 2020    Semidrive                *
 *        All rights reserved.                          *
 ********************************************************/

#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif
/* Version and Check Begin */
/* Version Info Begin */
#define PLATFORM_TYPES_H_VENDOR_ID    0x8C
#define PLATFORM_TYPES_H_AR_RELEASE_MAJOR_VERSION    4
#define PLATFORM_TYPES_H_AR_RELEASE_MINOR_VERSION    3
#define PLATFORM_TYPES_H_AR_RELEASE_REVISION_VERSION 1
#define PLATFORM_TYPES_H_SW_MAJOR_VERSION    1
#define PLATFORM_TYPES_H_SW_MINOR_VERSION    0
#define PLATFORM_TYPES_H_SW_PATCH_VERSION    0
/* Version Info End */
/* Version and Check End */



#define CPU_TYPE_8  8u
#define CPU_TYPE_16 16u
#define CPU_TYPE_32 32u
#define CPU_TYPE_64 64u

#define MSB_FIRST   0u
#define LSB_FIRST   1u

#define HIGH_BYTE_FIRST 0u
#define LOW_BYTE_FIRST  1u

/**
 * @brief          Processor type
 */
#define CPU_TYPE    (CFG_CPU_TYPE)

/**
 * @brief          Bit order on register level.
 */
#define CPU_BIT_ORDER (LSB_FIRST)

#define CPU_BYTE_ORDER (LOW_BYTE_FIRST)

#ifndef TRUE
#define TRUE (1u)
#endif
#ifndef FALSE
#define FALSE (0u)
#endif

#if (CPU_TYPE == CPU_TYPE_64)
typedef unsigned char boolean;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long long uint64;
typedef signed char sint8;
typedef signed short sint16;
typedef signed int sint32;
typedef signed long long sint64;

/* Unsigned integer at least 8 bit long. Range of at least 0 ..+255 (0x00..0xFF) - 8 bit */
typedef unsigned int uint8_least;
typedef unsigned int uint16_least;
typedef unsigned int uint32_least;

/**
* Signed integer at least 8 bit long. Range - at least -128 ..+127.
* At least 7 bit + 1 bit sign
*/
typedef signed int sint8_least;
typedef signed int sint16_least;
typedef signed int sint32_least;

typedef float float32;
typedef double float64;


#elif (CPU_TYPE == CPU_TYPE_32)
typedef unsigned char boolean;

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef unsigned long long uint64;
typedef signed char sint8;
typedef signed short sint16;
typedef signed long sint32;
typedef signed long long sint64;
typedef unsigned long uint8_least;
typedef unsigned long uint16_least;
typedef unsigned long uint32_least;
typedef signed long sint8_least;
typedef signed long sint16_least;
typedef signed long sint32_least;

typedef float float32;
typedef double float64;

#elif (CPU_TYPE == CPU_TYPE_16)
#error "This MCAL release has no CPU_TYPE_16 support."
#endif

typedef volatile uint32 addr_t;
typedef volatile uint32 vaddr_t;
typedef volatile uint32 paddr_t;

typedef boolean bool;

#ifdef __cplusplus
}
#endif

#endif /* #ifndef PLATFORM_TYPES_H */
