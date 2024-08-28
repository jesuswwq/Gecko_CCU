/********************************************************
 *        Copyright(c) 2020    Semidrive                *
 *        All rights reserved.                          *
 ********************************************************/

#include <Std_Types.h>
#include <_assert.h>

#define LIB_START_SEC_CODE
#include "Lib_MemMap.h"

static inline uint32 hexchar_to_num(char c)
{
    return  (((c) >= '0' && (c) <= '9') ? (c - '0') : \
             ((c) >= 'a' && (c) <= 'f') ? ((c - 'a') + 10) : \
             ((c) >= 'A' && (c) <= 'F') ? ((c - 'A') + 10) : 0);
}

/* Just as 'strlen', this function takes a null terminated byte string and
 * return its length. The length does not include the null character. */
uint32 mini_strlen(const char *str)
{
    uint32 sz = 0;

    while (*str++ != '\0') {
        sz++;
    }

    return sz;
}

char *mini_strcpy(char *to, const char *from)
{
    ASSERT((NULL_PTR != to) && (NULL_PTR != from));

    char *p = to;

    while ('\0' != (*to++ = *from++));

    return p;
}

/* Note: this secure version's return is not aligned to strncmp_s */
int mini_strncmp_s(const char *s1, const char *s2, uint32 n)
{
    ASSERT((NULL_PTR != s1) && (NULL_PTR != s2));

    int res = 0;

    while (n && *s1) {
        res |= (*s1++ != *s2++);
        n--;
    }

    return res;
}

int mini_strcmp_s(const char *s1, const char *s2)
{
    ASSERT((NULL_PTR != s1) && (NULL_PTR != s2));

    int res = 0;

    while ((*s1 != '\0') && (*s2 != '\0')) {
        res |= (*s1++ != *s2++);
    }

    return res | (*s1 != '\0') | (*s2 != '\0');
}

/* endptr/base ignored, they are taken as NULL_PTR/0 */
unsigned long int mini_strtoul(const char *str, char **endptr, int base)
{
    unsigned long int v = 0;
    const char *p = str;
    uint32 n = 0;
    uint32 radix = 1;

    while (*p++ != '\0') {
        n++;
    }

    p = str;

    if (n == 1) {   /* if only one digit, it has to be '0 - 9'*/
        if (*p >= '0' && *p <= '9') {
            v = *p - '0';
        }
    } else if ( (n >= 2)) {
        /* '0x' gives 0
         * '12a5' gives 1205
         * 0x12p5 gives 0x1205
         */
        if ((*p == '0') && (*(p + 1) == 'x' || *(p + 1) == 'X')) { /* radix = 16*/
            radix = 16;
            p += 2;
            n -= 2;
        } else {
            radix = 10;
        }

        while (n--) {
            v = radix * v + hexchar_to_num(*p++);
        }
    }

    return v;
}

#define LIB_STOP_SEC_CODE
#include "Lib_MemMap.h"
