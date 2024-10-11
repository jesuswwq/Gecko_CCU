#ifndef _IOEXP_TCA6408_CFG_H_
#define _IOEXP_TCA6408_CFG_H_

#include "I2c.h"
#include "Dio.h"

#define MACRO *(unsigned char*)&

/**************************************************************************************************************/
/***                                        MACRO Define                                                    ***/
/*****                                                                                                     ****/
/**************************************************************************************************************/


/************************** I2C Address ***************************************/
#define TCA6408_ADDRESS		0x20 		//address:0x74, all output, device E
						
/************************** I2C Registers *************************************/
#define TCA6408_INPUT_REG		0x00		// Input status register
#define TCA6408_OUTPUT_REG 		0x01		// Output register to change state of output BIT set to 1, output set HIGH
#define TCA6408_POLARITY_REG 	0x02		// Polarity inversion register. BIT '1' inverts input polarity of register 0x00
#define TCA6408_CONFIG_REG   	0x03		// Configuration register. BIT = '1' sets port to input BIT = '0' sets port to output

#define TCA6408_PORTDIR_OUTPUT   (0x0U)
#define TCA6408_PORTDIR_INPUT    (0x1U)  
/**************************************************************************************************************/
/***                                        Configration                                                    ***/
/*****                          user could change based on project                                         ****/
/**************************************************************************************************************/
//PORTdir config                                 
#define TCA6408_PORTDIRALLOUT (uint8)((TCA6408_PORTDIR_OUTPUT<<7)|(TCA6408_PORTDIR_OUTPUT<<6)|(TCA6408_PORTDIR_OUTPUT<<5) \
                                     |(TCA6408_PORTDIR_OUTPUT<<4)|(TCA6408_PORTDIR_OUTPUT<<3)|(TCA6408_PORTDIR_OUTPUT<<2) \
                                     |(TCA6408_PORTDIR_OUTPUT<<1)|(TCA6408_PORTDIR_OUTPUT<<0))  

#define TCA6408_PORTDIRALLIN (uint8)((TCA6408_PORTDIR_INPUT<<7)|(TCA6408_PORTDIR_INPUT<<6)|(TCA6408_PORTDIR_INPUT<<5) \
                                     |(TCA6408_PORTDIR_INPUT<<4)|(TCA6408_PORTDIR_INPUT<<3)|(TCA6408_PORTDIR_INPUT<<2) \
                                     |(TCA6408_PORTDIR_INPUT<<1)|(TCA6408_PORTDIR_INPUT<<0))  

#define TCA6408_PORTDIR TCA6408_PORTDIRALLIN                     
/**************************************************************************************************************/
/***                                        Type  Define                                                    ***/
/*****                                                                                                     ****/
/**************************************************************************************************************/
typedef struct
{
    uint8            I2C_Channel;
//    I2c_adap_dev_t*  I2C_CtrlBlock;
    uint8            Device_Addr;
    uint8            PortDir;
	Dio_ChannelType  RstPin;
}TCA6408_Ctrl_t;    

struct TCA6408_sBit{
	unsigned char B0:1;
	unsigned char B1:1;
	unsigned char B2:1;
	unsigned char B3:1;
	unsigned char B4:1;
	unsigned char B5:1;
	unsigned char B6:1;
	unsigned char B7:1;

};

union TCA6408_uInput{
	unsigned char	all;
	struct TCA6408_sBit bit;
};

struct TCA6408_sInputP{
	union TCA6408_uInput P0;
	union TCA6408_uInput P1;
	union TCA6408_uInput P2;
};

union TCA6408_uInputA{
	unsigned long 		all;
	struct TCA6408_sInputP	 	Port;
};



union TCA6408_uOutputP0{
	unsigned char 		all;
	struct TCA6408_sBit	bit;
};


struct TCA6408_sOutput{
	union TCA6408_uOutputP0	P0;
	union TCA6408_uOutputP0	P1;
	union TCA6408_uOutputP0	P2;
};

union TCA6408_uOutput{
	unsigned long	all;
	struct TCA6408_sOutput	Port;
};

union TCA6408_uPolarityInversionP0{
	unsigned char all;
	struct TCA6408_sBit bit;
};

union  TCA6408_uPolarityInversionP1{
	unsigned char	all;
	struct TCA6408_sBit bit;
};


struct TCA6408_sPolarityInversion{
	union TCA6408_uPolarityInversionP0	P0;
	union TCA6408_uPolarityInversionP0	P1;
};

union TCA6408_uPolarityInversion{
	unsigned long all;
	struct TCA6408_sPolarityInversion Port;
};

union TCA6408_uConfigP0{
	unsigned char all;
	struct TCA6408_sBit bit;
};

union  TCA6408_uConfigP1{
	unsigned char	all;
	struct TCA6408_sBit bit;
};

struct TCA6408_sConfig{
	union TCA6408_uConfigP0	P0;
	union TCA6408_uConfigP0	P1;
};

union TCA6408_uConfig{
	unsigned long all;
	struct TCA6408_sConfig Port;
};



typedef struct {
	union TCA6408_uInputA 				Input;
	union TCA6408_uOutput				Output;
	union TCA6408_uPolarityInversion	PolarityInversion;
	union TCA6408_uConfig				Config;
} TCA6408Regs;


#endif