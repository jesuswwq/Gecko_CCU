#ifndef _HBRIDGE_RTE_H_
#define _HBRIDGE_RTE_H_

// include adc file library
#include "Std_Types.h"
#include "MPQ6612A.h"

extern void HBridge_MPQ6612A_Ctrl(MPQ6612A_ChipSelect_e Chip,
                                    uint8 IN1Pin,uint8 IN2Pin);

#endif