/********************************************************
 *        Copyright(c) 2022    Semidrive                *
 *        All rights reserved.                          *
 ********************************************************/
#ifndef CRC4_H
#define CRC4_H
#include "Std_Types.h"

uint8 crc4_calculate(uint8 crc,  uint8 const *message, uint8 len);

#endif
