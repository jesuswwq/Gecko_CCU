/*
 * TLE75xxx.h
 *
 *  
 *      Author: 
 */

#ifndef TLE75004_API_H_
#define TLE75004_API_H_

#include "Platform_Types.h"

typedef enum{
	TLE75004_NOERROR,
	TLE75004_OLOFF,
	TLE75004_OLON,
	TLE75004_OVERLOAD,
	TLE75004_BOTHRERROR
}TLE75004_Dev_State;

typedef enum
{
	TLE75004_LS_OUT0,
	TLE75004_LS_OUT1,
	TLE75004_LS_OUT2,
	TLE75004_LS_OUT3,

	TLE75004_LS_OUTCHNUM
}TLE75004_Channel_e_;

typedef enum
{
	TLE75004_CH_OFF,
	TLE75004_CH_ON,

	TLE75004_CH_STNUM
}TLE75004_ChSt_e_;

void TLE75004_Init(void);
void TLE75004_Ctrl_PortOut(TLE75004_Channel_e_ Channel, TLE75004_ChSt_e_ ChannelSt);

void TLE75004_Output(uint8 CMD);
extern void TLE75004_ClearAllOutputChError(void);
extern void TLE75004_ResetChip(void);

extern uint8 TLE75004_Diag_ERRn(void);
extern boolean TLE75004_DIAG_Overload(uint8 u8ChannelIndex);
extern boolean TLE75004_DIAG_OlOff();


#endif /* TLE75XXX_H_ */
