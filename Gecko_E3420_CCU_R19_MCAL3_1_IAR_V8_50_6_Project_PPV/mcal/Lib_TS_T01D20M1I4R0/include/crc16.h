/********************************************************
 *        Copyright(c) 2022    Semidrive                *
 *        All rights reserved.                          *
 ********************************************************/
#ifndef CRC16_H
#define CRC16_H
#include "Std_Types.h"

unsigned short update_crc16(unsigned short crc, const unsigned char *buf,
                            unsigned int length);
unsigned short crc16(const unsigned char *buf, unsigned int length);

#endif
