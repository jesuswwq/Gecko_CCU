/*
* SEMIDRIVE Copyright Statement
* Copyright (c) SEMIDRIVE. All rights reserved
*
* This software and all rights therein are owned by SEMIDRIVE, and are
* protected by copyright law and other relevant laws, regulations and
* protection. Without SEMIDRIVE's prior written consent and/or related rights,
* please do not use this software or any potion thereof in any form or by any
* means. You may not reproduce, modify or distribute this software except in
* compliance with the License. Unless required by applicable law or agreed to
* in writing, software distributed under the License is distributed on
* an "AS IS" basis, WITHOUT WARRANTIES OF ANY KIND, either express or implied.
*
* You should have received a copy of the License along with this program.
* If not, see <http://www.semidrive.com/licenses/>.
*/
#ifdef __cplusplus
extern "C" {
#endif

#include "crc32.h"

#define CRCPOLY 0xedb88320

#define LIB_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Lib_MemMap.h"

static uint32 crc32table[4][256];

#define LIB_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Lib_MemMap.h"

#define LIB_START_SEC_CODE
#include "Lib_MemMap.h"

static uint32 crc32_calculate(uint32 crc, uint8 const *buf, uint32 len, uint32 (*tab)[256])
{


    const uint32 *b;
    uint32  rem_len;
    const uint32 *t0 = tab[0], *t1 = tab[1], *t2 = tab[2], *t3 = tab[3];
    uint32 q;

    /* Align it */
    if ((long)buf & 3 && len) {
        do {
            crc = t0[(crc ^ ((*buf++))) & 255] ^ (crc >> 8);
        } while ((--len) && ((long)buf) & 3);
    }


    rem_len = len & 3;
    len = len >> 2;

    /*Has been aligned above.*/
    /*PRQA S 3305 1*/
    b = (const uint32 *)buf;

    for (--b; len; --len) {
        q = crc ^ *++b;
        crc = (t3[(q) & 255] ^ t2[(q >> 8) & 255] ^ \
               t1[(q >> 16) & 255] ^ t0[(q >> 24) & 255]);
    }

    len = rem_len;

    if (len) {
        uint8 *p = (uint8 *)(b + 1) - 1;

        do {
            crc = t0[(crc ^ ((*++p))) & 255] ^ (crc >> 8);
        } while (--len);
    }

    return crc;
}

static void crc32init(const uint32 polynomial, uint32 (*tab)[256])
{
    uint32 i, j;
    uint32 crc = 1;

    tab[0][0] = 0;

    for (i = 256 >> 1; i; i >>= 1) {
        crc = (crc >> 1) ^ ((crc & 1) ? polynomial : 0);

        for (j = 0; j < 256; j += 2 * i)
            tab[0][i + j] = crc ^ tab[0][j];
    }

    for (i = 0; i < 256; i++) {
        crc = tab[0][i];

        for (j = 1; j < 4; j++) {
            crc = tab[0][crc & 0xff] ^ (crc >> 8);
            tab[j][i] = crc;
        }
    }
}

void crc32_init(void)
{
    crc32init(CRCPOLY, crc32table);
}

uint32 crc32(uint32 crc, uint8 const *buf, uint32 len)
{
    return crc32_calculate(crc, buf, len, crc32table);
}

#define LIB_STOP_SEC_CODE
#include "Lib_MemMap.h"

#ifdef __cplusplus
}
#endif
