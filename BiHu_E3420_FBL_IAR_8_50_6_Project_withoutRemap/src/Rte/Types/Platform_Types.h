#ifndef PLATFORM_H
#define PLATFORM_H
#ifdef __cplusplus
extern "C"{
#endif
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#define CPU_TYPE_8 8
#define CPU_TYPE_16 16
#define CPU_TYPE_32 32
#define CPU_TYPE_64 64
#define MSB_FIRST 0
#define LSB_FIRST 1
#define HIGH_BYTE_FIRST 0
#define LOW_BYTE_FIRST 1
#define CPU_TYPE (CPU_TYPE_32)
#define CPU_BIT_ORDER  (LSB_FIRST)
#define CPU_BYTE_ORDER (LOW_BYTE_FIRST)
#ifndef TRUE
#if !defined(NO_STDINT_H)
    #define TRUE true
#else
    #define TRUE 1
#endif
#endif
#ifndef FALSE
#if !defined(NO_STDINT_H)
    #define FALSE false
#else
    #define FALSE 0
#endif
#endif
#ifndef HIGH
    #define HIGH 1
#endif
#ifndef LOW
    #define LOW 0
#endif
#ifndef ENABLE
    #define ENABLE 1
#endif
#ifndef DISABLE
    #define DISABLE 0
#endif
#ifndef SUCCESS
    #define SUCCESS 1
#endif
#ifndef ERROR
    #define ERROR 0
#endif
#if !defined(NO_STDINT_H)
#if (CPU_TYPE == CPU_TYPE_64) || (CPU_TYPE == CPU_TYPE_32) || (CPU_TYPE == CPU_TYPE_16)
typedef bool boolean;
typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;
typedef int8_t sint8;
typedef int16_t sint16;
typedef int32_t sint32;
typedef int64_t sint64;
typedef uint_least8_t uint8_least;
typedef uint_least16_t uint16_least;
typedef uint_least32_t uint32_least;
typedef int_least8_t sint8_least;
typedef int_least16_t sint16_least;
typedef int_least32_t sint32_least;
typedef float float32;
typedef double float64;
#endif
#else
#if (CPU_TYPE == CPU_TYPE_64)
#elif (CPU_TYPE == CPU_TYPE_32)
#elif (CPU_TYPE == CPU_TYPE_16)
#endif
#endif
#ifdef __cplusplus
}
#endif
#endif
