
#ifndef __NJJ29C0B_API_H_
#define __NJJ29C0B_API_H_

#include "Std_Types.h"
#include "Dio.h"

extern void NJJ29C0B_Init(void);
extern Dio_LevelType Get_NJJ29C0B_INT_PinLevel(void);
extern Std_ReturnType NJJ29C0B_Frame_Transmit(uint8* payload_tx, uint8* rxdata, uint16 payload_len);

#endif /*__NJJ29C0B_API_H_*/