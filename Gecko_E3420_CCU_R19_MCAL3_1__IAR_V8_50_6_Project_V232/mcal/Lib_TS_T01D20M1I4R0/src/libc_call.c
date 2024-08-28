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
#include <mini_libc.h>
#include "debug.h"
#include "cdefs.h"

#define LIBC_CALL_FSTAT
#define LIBC_CALL_ISATTY

#if !defined(SOC_host)

extern unsigned long __heap_start[];
extern unsigned long __heap_end[];

#define MAX_FILE_NAME_LENGTH    (256)
#define MAX_FILE_NUMBER         (1)
#define MAX_FILE_MEMORY_SIZE    (64 * 1024)

/* Standard file descriptors. */
#ifndef STDIN_FILENO
#define STDIN_FILENO            0 /* Standard input. */
#endif

#ifndef STDOUT_FILENO
#define STDOUT_FILENO           1 /* Standard output. */
#endif

#ifndef STDERR_FILENO
#define STDERR_FILENO           2 /* Standard error output. */
#endif

#define MIN_FILE_HANDLE_INDEX   (STDERR_FILENO + 1)

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];    /* path + file name */
    long int cur_pos;                      /* current file pointer position for file start */
    unsigned int size;                        /* current file bytes */
    unsigned int refcnt;                /* current file open times */
    int fd;                             /* current file fd index */
    int flags;                          /* current file follow flags mode */
    unsigned int mode;                        /* current file open mode */
    unsigned int reserved;
} fd_t;

#define LIB_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Lib_MemMap.h"

#ifdef GCOV_ENABLE
static fd_t file_handle[MAX_FILE_NUMBER] _SECTION(.gcov_buffer);
static char file_buffer[MAX_FILE_NUMBER][MAX_FILE_MEMORY_SIZE] _SECTION(.gcov_buffer);
#endif

#define LIB_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Lib_MemMap.h"

#define LIB_START_SEC_CODE
#include "Lib_MemMap.h"

void gcov_print(char *ptr, int len)
{
#ifdef GCOV_ENABLE
    int i = 0, j = 0;

    for (i = 0; i < len; i += 16) {
        PRINT("\n%08x: ", i);

        for (j = 0; j < 16; j++) {
            if (i + j < len) {
                PRINT("%02x", ptr[i + j]);
            } else {
                PRINT("  ");
            }

            if (j % 2 == 1) {
                PRINT(" ");
            }
        }

        for (j = 0; j < 16; j++) {
            if (i + j < len) {
                if (ptr[i + j] >= 0x20 && ptr[i + j] <= 0x7e) {
                    PRINT("%c", ptr[i + j]);
                } else {
                    PRINT(".");
                }

            } else {
                PRINT(" ");
            }
        }

        PRINT("    ");
    }

#endif
}

int _open(const char *path, int flags, unsigned int mode)
{
    int ret = -1;
#ifdef GCOV_ENABLE
    int value = -1;

    if (path == NULL) {
        PRINT("open : file path pointer equal to NULL\r\n");
    } else {
        PRINT("\r\nopen :gcda file: %s\r\n", path);

        /* Search for copies of files with the same name */
        for (int i = 0; i < MAX_FILE_NUMBER; i++) {
            if (!mini_memcmp_s(path, file_handle[i].name, mini_strlen(path))) {
                /* Found file with the same name */
                if ((file_handle[i].flags == flags) && (file_handle[i].mode == mode)) {
                    /* current file open times update */
                    file_handle[i].refcnt++;

                    /* return current fd */
                    ret = file_handle[i].fd;
                    value = 0;
                } else {
                    PRINT("open : File Access Mode Conflicts with Allowed Access Mode\r\n");
                    value = -2;
                }

                break;
            }
        }

        if (value == -1) {
            /* loop for search for the first idle fd */
            for (int i = 0; i < MAX_FILE_NUMBER; i++) {
                if (file_handle[i].refcnt == 0) {
                    file_handle[i].fd = MIN_FILE_HANDLE_INDEX + i;
                    file_handle[i].flags = flags;
                    file_handle[i].mode = mode;
                    file_handle[i].cur_pos = 0;
                    file_handle[i].size = 0;
                    file_handle[i].refcnt = 1;
                    ret = file_handle[i].fd;
                    value = 0;
                    break;
                }
            }
        }

        if (value == -1) {
            PRINT("open ::File does not match open or idle fd \r\n");
        } else {
            PRINT("open ::fd: %d\n", ret);
        }
    }

#endif
    return ret;
}

int _close(int fd)
{
    int ret = -1;

#ifdef GCOV_ENABLE

    if (fd < MIN_FILE_HANDLE_INDEX) {
        PRINT("close : File fd is illegal \r\n");
    } else {
        int index = fd - MIN_FILE_HANDLE_INDEX;

        if (file_handle[index].refcnt > 0) {
            file_handle[index].refcnt--;

            if (file_handle[index].refcnt == 0) {
                PRINT("close::fd:%d\r\n", fd);
                PRINT("\nlength_gcov: 0x%x\n", file_handle[index].size);
                gcov_print(file_buffer[index], file_handle[index].size);
                file_handle[index].fd = 0;
                file_handle[index].flags = O_RDONLY;
                file_handle[index].mode = 0;
                file_handle[index].cur_pos = 0;
                file_handle[index].size = 0;
            }
        }

        ret = 0;
    }

#endif
    return ret;
}

unsigned int _read(int fd, void *buf, unsigned int len)
{
    unsigned int length = -1;

#ifdef GCOV_ENABLE

    if (fd < MIN_FILE_HANDLE_INDEX) {
        PRINT("read : File fd is illegal \r\n");
    } else if (buf == NULL) {
        PRINT("read : File pointer equal to NULL\r\n");
    } else {

        char *array = (char *)buf;
        /* Calculate the current fd index */
        int index = fd - MIN_FILE_HANDLE_INDEX;

        if (file_handle[index].flags == O_WRONLY) {
            PRINT("read : file flags operation is illegal\r\n");
        } else if (file_handle[index].refcnt == 0) {
            PRINT("read : file not open, fd = %d, refcnt = 0x%x\r\n", fd, file_handle[index].refcnt);
        } else {

            /* Calculate the current number of readable bytes */
            if ((file_handle[index].size - file_handle[index].cur_pos) > len) {
                length = len;
            } else {
                length = file_handle[index].size - file_handle[index].cur_pos;
            }

            /* copy data from buffer to user */
            for (int i = 0; i < length; i++) {
                array[i] = file_buffer[index][file_handle[index].cur_pos++];
            }

            PRINT("read ::fd:%d len:0x%x\r\n", fd, len);
        }
    }

#endif
    return length;
}

unsigned int _write(int fd, const void *buf, unsigned int len)
{
    unsigned int length = -1;

#ifdef GCOV_ENABLE

    if (buf == NULL) {
        PRINT("write : File pointer equal to NULL\r\n");
    } else {

        char *array = (char *)buf;

        if (fd < MIN_FILE_HANDLE_INDEX) {
            while (len--) {PRINT("%c", array);}
        } else {

            /* Calculate the current fd index */
            int index = fd - MIN_FILE_HANDLE_INDEX;

            if (file_handle[index].flags == O_RDONLY) {
                PRINT("write : file flags operation is illegal\r\n");
            } else if (file_handle[index].refcnt == 0) {
                PRINT("write : file not open, fd = %d, refcnt = 0x%x\r\n", fd, file_handle[index].refcnt);

            } else {

                /* Calculate the current number of readable bytes */
                if ((file_handle[index].cur_pos + len) < MAX_FILE_MEMORY_SIZE) {
                    length = len;
                } else {
                    length = MAX_FILE_MEMORY_SIZE - file_handle[index].cur_pos;
                }

                file_handle[index].size = file_handle[index].cur_pos + length;

                /* copy data from buffer to user */
                for (int i = 0; i < length; i++) {
                    file_buffer[index][file_handle[index].cur_pos++] = array[i];
                }

                PRINT("write::fd:%d len:0x%x\r\n", fd, len);
            }
        }
    }

#endif
    return length;
}

long int _lseek(int fd, long int offset, int whence)
{
    long int pos = -1;

#ifdef GCOV_ENABLE
    int index = 0;
    long int value = 0;

    if (fd < MIN_FILE_HANDLE_INDEX) {
        PRINT("lseek : File fd is illegal \r\n");
        value = -1;
    } else {
        /* Calculate the current fd index */
        index = fd - MIN_FILE_HANDLE_INDEX;

        if (file_handle[index].refcnt == 0) {
            PRINT("lseek : file not open, fd = %d, refcnt = %d\r\n", fd, file_handle[index].refcnt);
            value = -1;
        } else {

            switch (whence) {
            case SEEK_SET:
                if (offset <= file_handle[index].size) {
                    file_handle[index].cur_pos = offset;
                } else {
                    PRINT("lseek : Offset exceeds the maximum size\r\n");
                }

                break;

            case SEEK_CUR:
                if ((file_handle[index].cur_pos + offset) < file_handle[index].size) {
                    file_handle[index].cur_pos += offset;
                } else {
                    PRINT("lseek : Offset exceeds the maximum size\r\n");
                }

                break;

            case SEEK_END:
                if ((file_handle[index].size - offset) < 0) {
                    PRINT("lseek : Offset exceeds the maximum size\r\n");
                } else {
                    file_handle[index].cur_pos = file_handle[index].size - offset - 1;
                }

                break;

            default:
                PRINT("lseek : whence parameter is illegal\r\n");
                value = -1;
                break;
            }
        }
    }

    if (value == 0) {
        pos = file_handle[index].cur_pos;
        PRINT("lseek::fd:%d offset:0x%x whence:0x%x\r\n", fd, offset, whence);
    }

#endif
    return pos;
}

#if defined(LIBC_CALL_FSTAT)
int _fstat( int fd, struct stat *sbuf )
{
    return 0;
}
#endif

#if defined(LIBC_CALL_ISATTY)
int _isatty(int fd)
{
    if ((fd == STDOUT_FILENO) || (fd == STDIN_FILENO) || (fd == STDERR_FILENO)) {
        return 1; /* IS a terminal */
    }

    return 0;
}
#endif

void _fini(void)
{

}

int str_endswith(char *str, char *suffix)
{
    int res = 1;
    int str_len = mini_strlen(str);
    int suffix_len = mini_strlen(suffix);

    if (0 == mini_strncmp_s(suffix, str + str_len - suffix_len, suffix_len)) {
        res = 0;
    }

    return res;
}

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

    if ((heap_ptr + nbytes) < (char *)__rom_end)
#else

    if ((heap_ptr + nbytes) < (char *)__heap_end)
#endif
    {
        heap_ptr += nbytes;
        return base;
    } else {
        return (char *) -1;
    }
}

#define LIB_STOP_SEC_CODE
#include "Lib_MemMap.h"

#endif
