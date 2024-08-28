
#ifndef __TLE8108EM_H_
#define __TLE8108EM_H_

#include "Std_Types.h"

typedef enum
{
  DO_OUT_1,
  DO_OUT_2,
  DO_OUT_3,
  DO_OUT_4,
  DO_OUT_5,
  DO_OUT_6,
  DO_OUT_7,
  DO_OUT_8,

  DO_OUT_CH_MAX
}DO_OUT_Ch_t;

typedef enum
{
  TLE8108EM_OUT_STG,        //Short circuit to GND (SCG)
  TLE8108EM_OUT_OL,         //Open load (OL)
  TLE8108EM_OUT_STB_OR_OT,  //Short circuit to battery (SCB) or diagnostic overtemperature (DOT)
  TLE8108EM_OUT_OK,         //Power stage ok

  TLE8108EM_OUTST_NUM
}TLE8108EM_DiagSt_e;


extern void TLE8108EM_Init(void);
extern void TLE8108EM_SwitchToStandby(void);
extern Std_ReturnType TLE8108EM_Set_ChannelON(DO_OUT_Ch_t channel);
extern Std_ReturnType TLE8108EM_Set_ChannelOFF(DO_OUT_Ch_t channel);
extern Std_ReturnType TLE8108EM_PwmCtrlChannelOutput(DO_OUT_Ch_t channel, uint8 dutyPercent,uint32 frq);
extern Std_ReturnType TLE8108EM_Clear_ChannelError(DO_OUT_Ch_t channel);

extern Std_ReturnType TLE8108EM_Get_DiagStatus(DO_OUT_Ch_t channel, 
                                              TLE8108EM_DiagSt_e *diag_st);

extern void TLE8108EM_read_write_Ext(uint16 value);
#endif /*__TLE8108EM_H_*/