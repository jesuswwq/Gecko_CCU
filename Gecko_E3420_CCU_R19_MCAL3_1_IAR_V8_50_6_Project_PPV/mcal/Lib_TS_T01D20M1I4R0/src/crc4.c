/********************************************************
 *        Copyright(c) 2022    Semidrive                *
 *        All rights reserved.                          *
 ********************************************************/
#include "crc4.h"

#define LIB_START_SEC_CONST_UNSPECIFIED
#include "Lib_MemMap.h"

const uint8 CRC4_Table[16] = {0, 13, 7, 10, 14, 3, 9, 4, 1, 12, 6, 11, 15, 2, 8, 5};

#define LIB_STOP_SEC_CONST_UNSPECIFIED
#include "Lib_MemMap.h"

#define LIB_START_SEC_CODE
#include "Lib_MemMap.h"

uint8 crc4_calculate(uint8 initial_value, uint8 const *message, uint8 len)
{
    uint8 crc_val = initial_value;
    int i = 0;

    for ( ; i < len; i++) {
        crc_val = CRC4_Table[crc_val] ^ message[i];
    }

    crc_val = 0 ^ CRC4_Table[crc_val];
    return crc_val;
}

#define LIB_STOP_SEC_CODE
#include "Lib_MemMap.h"
