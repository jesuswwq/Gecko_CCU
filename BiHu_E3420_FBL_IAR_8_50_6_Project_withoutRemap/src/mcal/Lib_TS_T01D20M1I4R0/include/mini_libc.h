/********************************************************
 *        Copyright(c) 2020    Semidrive                *
 *        All rights reserved.                          *
 ********************************************************/

/**
 * @file    mini_libc.h
 * @brief   header file of mini_libc
 */

#ifndef MINI_LIBC_H
#define MINI_LIBC_H

#include "Platform_Types.h"


int mini_printf(const char *fmt, ...);

void *mini_memcpy_s(void *dst, const void *src, uint32 size);
void mini_memclr_s(void *dst, uint32 size);
sint32 mini_memcmp_s(const void *mem1, const void *mem2, uint32 size);
void *mini_memset_s(void *dst, int val, uint32 size);
void *mini_memmove_s(void *dst, const void *src, uint32 size);
uint32 mini_strlen(const char *str);
char *mini_strcpy(char *to, const char *from);
void *mini_mem_rvscpy_s(void *dst, const void *src, uint32 sz);
void *mini_mem_rvs_s(void *mem, uint32 sz);
int mini_strncmp_s(const char *s1, const char *s2, uint32 n);
int mini_strcmp_s(const char *s1, const char *s2);
unsigned long int mini_strtoul(const char *str, char **endptr, int base);

#if defined(NO_STDLIB)
void *memset(void *dst, int val, uint32 sz);
void *memcpy (void *dst, const void *src, uint32 sz);
#define memclr  mini_memclr_s
#define memcmp  mini_memcmp_s
#define memmove mini_memmove_s
#define strlen  mini_strlen
#define strcpy  mini_strcpy
#define strncmp mini_strncmp_s
#define strcmp mini_strcmp_s
#define strtoul mini_strtoul
#else
#define memclr(dst, sz)  memset((void*)(dst), 0, sz)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#endif

#endif /*MINI_LIBC_H */
