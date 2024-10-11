/********************************************************
 *        Copyright(c) 2020    Semidrive                *
 *        All rights reserved.                          *
 ********************************************************/
#ifndef CRC32_H
#define CRC32_H
#include "Std_Types.h"

void crc32_init(void);
uint32 crc32(uint32 crc,  uint8 const *buf, uint32 len);
uint32 sfs_crc32(uint32 crc, uint8 const *buf, uint32 len);

#endif
