/*
 * TLE75xxx.h
 *
 *  
 *      Author: 
 */

#ifndef TLE75242_CFG_H_
#define TLE75242_CFG_H_

#include "Platform_Types.h"


#define	TLE75242_RREG_ADDRESS_STDDIAG	0x01U

#define TLE75242_CHANNEL_NUM 			8U

#define    TLE75242_CMD_WRITE     0x8000
#define    TLE75242_CMD_READ      0x4002

#define    TLE75242_REG_OUT             0x00	//0000,00	Power output control register
#define    TLE75242_REG_BIM             0x01	//0000,01	Bulb Inrush Mode
#define    TLE75242_REG_MAPIN0          0x04	//0001,00	Input Mapping (Input Pin 0)
#define    TLE75242_REG_MAPIN1          0x05	//0001,01	Input Mapping (Input Pin 1)
#define    TLE75242_REG_INST            0x06	//0001,10	Input Status Monitor
#define    TLE75242_REG_DIAG_IOL        0x08	//0010,00	Open Load diagnostic current control
#define    TLE75242_REG_DIAG_OSM        0x09	//0010,01	Output Status Monitor
#define    TLE75242_REG_DIAG_OLON       0x0A	//0010,10	Open Load at ON monitor
#define    TLE75242_REG_DIAG_OLONEN     0x0B	//0010,11	Open Load at ON diagnostic control
#define    TLE75242_REG_HWCR            0x0C	//0011,00	Hardware Configuration Register
#define    TLE75242_REG_HWCR_OCL        0x0D	//0011,01	Output Clear Latch
#define    TLE75242_REG_HWCR_PWM        0x0E	//0011,10	PWM Configuration Register
#define    TLE75242_REG_HWCR_CR0        0x4 	//0100,--	PMW Generator Configuration 0
#define    TLE75242_REG_HWCR_CR1        0x5 	//0101,--	PMW Generator Configuration 1
#define    TLE75242_REG_HWCR_OUT        0x24	//1001,00	PWM Generator Output Control
#define    TLE75242_REG_HWCR_MAP        0x25	//1001,01	PWM Generator Output Mapping

typedef struct
{
    uint16 IDLE_Pin;
    uint16 IN0_Pin;
    uint16 IN1_Pin;
}TLE75242_CtrlPin_t_;

typedef enum{
	TLE75242_NOERROR,
	TLE75242_OLOFF,
	TLE75242_OLON,
	TLE75242_OVERLOAD,
	TLE75242_BOTHRERROR
}Tle75242_Dev_State;

typedef union{
	struct{
	uint16 UNUSED 	:1;
	uint16 UVRVS	:1;
	uint16 LOPVDD	:1;
	uint16 MODE		:2;
	uint16 TER		:1;
	uint16 OLON		:1;
	uint16 OLOFF	:1;
	uint16 ERRn		:8;
	}bitdef;
	uint16 worddef;
}TLE75242_StdDiag_t;

typedef union{
	struct{
	uint16 UNUSED 	:1;
	uint16 UVRVS	:1;
	uint16 LOPVDD	:1;
	uint16 MODE		:2;
	uint16 TER		:1;
	uint16 UNUSED1	:1;
	uint16 OLOFF	:1;
	uint16 ERRn		:8;
	}bitdef;
	uint16 worddef;
}TLE75602_StdDiag_t;

#define TEST_MSKBIT( u8data, bitmask )  (((u8data)&((uint8)(bitmask)))!= 0u)
#define GET_BITPOS( u8data, bitpos )  (TEST_MSKBIT((u8data),((uint8)1u<<((uint8)(bitpos))))?TRUE :FALSE)

void TLE75242_1_PWM_Cfg(uint8 hwcr_pwm, uint16 hwcr_cr0, uint16 hwcr_cr1, uint8 pwm_map, uint8 pwm_out);
void TLE75242_2_PWM_Cfg(uint8 hwcr_pwm, uint16 hwcr_cr0, uint16 hwcr_cr1, uint8 pwm_map, uint8 pwm_out);
void TLE75602_PWM_Cfg(uint8 hwcr_pwm, uint16 hwcr_cr0, uint16 hwcr_cr1, uint8 pwm_map, uint8 pwm_out);


extern uint8 TLE75242_1_Diag_ERRn(void);
extern void Tle75242_1_vPrtc(void);
extern boolean Tle75242_1_DIAG_Overload(uint8 u8ChannelIndex);
extern boolean Tle75242_1_DIAG_OlOff();
extern uint8 Tle75242_1_Diag_OlOff_Channel(void);
extern boolean Tle75242_1_DIAG_OLON(void);
extern uint8 Tle75242_1_Diag_OlON_Channel(void);
void Tle75242_1_tGetStdDiag(TLE75242_StdDiag_t *pStdDiag);
void Tle75242_1_OLON_Diag_Loop(void);

extern void TLE75242_2_CHANEL3_PWM_OUT(uint16 Cmd);



#endif /* TLE75XXX_H_ */
