/********************************************************
 *        Copyright(c) 2020    Semidrive                *
 *        All rights reserved.                          *
 ********************************************************/

#include <soc.h>
#include "Compiler.h"
#if defined(__GNUC__) && !defined(__ARMCC_VERSION) && !defined(_GHS_C_)
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/signal.h>
#include <unistd.h>
#endif

#if !defined(SOC_host) && !defined(NO_STDLIB)

#ifdef GCOV_ENABLE
#define IRAM_ADDR_GCOV 0x00180000
unsigned char buffer_gcov[255] = {0};
int length_gcov = 0;
#endif

#define LIB_START_SEC_CODE
#include "Lib_MemMap.h"

int _read(int file, char *ptr, int len)
{
    return len;
}

int _lseek(int file, int ptr, int dir)
{
    return 0;
}

int _open(const char *path, int flags, int mode)
{
#ifdef GCOV_ENABLE
    (void) mode;
    mini_strcpy((char *)buffer_gcov, (const char *)path);
#endif
    return 0;
}

int _close(int file)
{
    return 0;
}

#if defined(LIBC_CALL_FSTAT)
int _fstat( int __fd, struct stat *__sbuf )
{
    return 0;
}
#endif

int _write(int file, char *ptr, int len)
{
#ifdef GCOV_ENABLE
    length_gcov = len;
    mini_memcpy_s((void *)IRAM_ADDR_GCOV, (const void *)ptr, len);
#endif
    return len;
}

#if defined(LIBC_CALL_ISATTY)
int _isatty(int __fildes )
{
    if (__fildes == STDOUT_FILENO || __fildes == STDIN_FILENO) {
        return 1; /* IS a terminal */
    }

    return 0;
}
#endif

void _exit(int n)
{
    while (1);
}

int _kill(int n, int m)
{
    return 0;
}

int _getpid(int n)
{
    return 1;
}

static char *heap_ptr = NULL_PTR;

char *_sbrk(int nbytes)
{
    char *base;

    if (NULL_PTR == heap_ptr) {
#if defined(CFG_PUT_HEAP_AFTER_IMG)
        heap_ptr = (char *)__data_start_rom;
#else
        heap_ptr = (char *)__heap_start;
#endif
    }

    base = heap_ptr;

#if defined(CFG_PUT_HEAP_AFTER_IMG)

    if ((heap_ptr + nbytes) < (char *)__rom_end) {
#else

    if ((heap_ptr + nbytes) < (char *)__heap_end) {
#endif
        heap_ptr += nbytes;
        return base;
    } else {
        return (char *) -1;
    }
}

#endif

#define LIB_STOP_SEC_CODE
#include "Lib_MemMap.h"
