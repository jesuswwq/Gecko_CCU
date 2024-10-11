#ifndef _IOEXP_TCA6408_API_H_
#define _IOEXP_TCA6408_API_H_

#include "Std_Types.h"
#include "Dio.h"

typedef enum
{
    TCA6408_CHIP_A,     //address:0x20, IDX3-IDX10
    
    TCA6408_CHIP_NUM
}TCA6408_ChipID_e_;

typedef enum
{
    IOEXP_TCA6408_P00,
    IOEXP_TCA6408_P01,
    IOEXP_TCA6408_P02,
    IOEXP_TCA6408_P03,
    IOEXP_TCA6408_P04,
    IOEXP_TCA6408_P05,
    IOEXP_TCA6408_P06,
    IOEXP_TCA6408_P07,

    IOEXP_TCA6408_PORT_NUM 
    
}TCA6408_Channel_e_;


extern void TCA6408_Init(void);
extern uint8 IoExp_TCA6408_GetPortInputValue(void);
extern Dio_LevelType IoExp_TCA6408_GetChannelInputLevel(TCA6408_Channel_e_ Channel);

/*those api used for port configured as output*/
// extern Std_ReturnType IoExp_TCA6408_SetChannelOutLevel(TCA6408_Channel_e_ ChannelNum, Dio_LevelType OutLevel);
// extern Std_ReturnType IoExp_TCA6408_SetAllPortHigh(void);
// extern Std_ReturnType IoExp_TCA6408_SetAllPortLow(void);
// extern Dio_LevelType IoExp_TCA6408_GetChannelOutputSt(TCA6408_Channel_e_ Channel);

#endif
