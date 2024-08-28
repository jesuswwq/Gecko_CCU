
#ifndef __NCK2910_API_H_
#define __NCK2910_API_H_

#include "Std_Types.h"
#include "Dio.h"

extern void NCK2910_Init(void);
extern boolean Is_NCK2910_RDY_N_Active(void);
extern boolean Is_NCK2910_INT_Active(void);
extern Std_ReturnType NCK2910_Frame_Transmit(uint8 cmd, uint8 sub_cmd, uint8* payload_tx, uint8* rxdata, uint8 payload_len);

#endif /*__NCK2910_API_H_*/