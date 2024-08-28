#ifndef _IOEXP_TCA9539_CFG_H_
#define _IOEXP_TCA9539_CFG_H_

#include "I2c.h"
#include "Dio.h"

#define MACRO *(unsigned char*)&

/**************************************************************************************************************/
/***                                        MACRO Define                                                    ***/
/*****                                                                                                     ****/
/**************************************************************************************************************/


/************************** I2C Address ***************************************/
/*#define TCA9539_A_ADDRESS		0x74 		//address:0x74, all output, device E*/
#define TCA9539_A_ADDRESS		0x77 		//Address:0x77, all input, IDL0-IDL16
#define TCA9539_B_ADDRESS		0x75 		//Address:0x75, all inpput, IDL17-TDX2								
/************************** I2C Registers *************************************/
#define TCA9539_INPUT_REG0		0x00		// Input status register
#define TCA9539_INPUT_REG1		0x01		// Input status register
#define TCA9539_OUTPUT_REG0 	0x02		// Output register to change state of output BIT set to 1, output set HIGH
#define TCA9539_OUTPUT_REG1	    0x03		// Output register to change state of output BIT set to 1, output set HIGH
#define TCA9539_POLARITY_REG0 	0x04		// Polarity inversion register. BIT '1' inverts input polarity of register 0x00
#define TCA9539_POLARITY_REG1 	0x05		// Polarity inversion register. BIT '1' inverts input polarity of register 0x00
#define TCA9539_CONFIG_REG0   	0x06		// Configuration register. BIT = '1' sets port to input BIT = '0' sets port to output
#define TCA9539_CONFIG_REG1   	0x07		// Configuration register. BIT = '1' sets port to input BIT = '0' sets port to output

#define TCA9539_PORTDIR_OUTPUT   (0x0U)
#define TCA9539_PORTDIR_INPUT    (0x1U)  
/**************************************************************************************************************/
/***                                        Configration                                                    ***/
/*****                          user could change based on project                                         ****/
/**************************************************************************************************************/
//PORTdir config
#define TCA9539_PORT0DIR (uint8)((TCA9539_PORTDIR_OUTPUT<<7)|(TCA9539_PORTDIR_OUTPUT<<6)|(TCA9539_PORTDIR_OUTPUT<<5) \
                                 |(TCA9539_PORTDIR_OUTPUT<<4)|(TCA9539_PORTDIR_OUTPUT<<3)|(TCA9539_PORTDIR_OUTPUT<<2) \
                                 |(TCA9539_PORTDIR_OUTPUT<<1)|(TCA9539_PORTDIR_OUTPUT<<0))

#define TCA9539_PORT1DIR (uint8)((TCA9539_PORTDIR_OUTPUT<<7)|(TCA9539_PORTDIR_OUTPUT<<6)|(TCA9539_PORTDIR_OUTPUT<<5) \
                                 |(TCA9539_PORTDIR_OUTPUT<<4)|(TCA9539_PORTDIR_OUTPUT<<3)|(TCA9539_PORTDIR_OUTPUT<<2) \
                                 |(TCA9539_PORTDIR_OUTPUT<<1)|(TCA9539_PORTDIR_OUTPUT<<0))
                                 
#define TCA9539_PORTDIRALLOUT (uint8)((TCA9539_PORTDIR_OUTPUT<<7)|(TCA9539_PORTDIR_OUTPUT<<6)|(TCA9539_PORTDIR_OUTPUT<<5) \
                                     |(TCA9539_PORTDIR_OUTPUT<<4)|(TCA9539_PORTDIR_OUTPUT<<3)|(TCA9539_PORTDIR_OUTPUT<<2) \
                                     |(TCA9539_PORTDIR_OUTPUT<<1)|(TCA9539_PORTDIR_OUTPUT<<0))  

#define TCA9539_PORTDIRALLIN (uint8)((TCA9539_PORTDIR_INPUT<<7)|(TCA9539_PORTDIR_INPUT<<6)|(TCA9539_PORTDIR_INPUT<<5) \
                                     |(TCA9539_PORTDIR_INPUT<<4)|(TCA9539_PORTDIR_INPUT<<3)|(TCA9539_PORTDIR_INPUT<<2) \
                                     |(TCA9539_PORTDIR_INPUT<<1)|(TCA9539_PORTDIR_INPUT<<0))  
                      
/**************************************************************************************************************/
/***                                        Type  Define                                                    ***/
/*****                                                                                                     ****/
/**************************************************************************************************************/
typedef struct
{
    uint8            I2C_Channel;
//    I2c_adap_dev_t*  I2C_CtrlBlock;
    uint8            Device_Addr;
    uint8            Port0Dir;
    uint8            Port1Dir;
	Dio_ChannelType  RstPin;
}TCA9539_Ctrl_t;    

struct TCA9539_sBit{
	unsigned char B0:1;
	unsigned char B1:1;
	unsigned char B2:1;
	unsigned char B3:1;
	unsigned char B4:1;
	unsigned char B5:1;
	unsigned char B6:1;
	unsigned char B7:1;

};

union TCA9539_uInput{
	unsigned char	all;
	struct TCA9539_sBit bit;
};

struct TCA9539_sInputP{
	union TCA9539_uInput P0;
	union TCA9539_uInput P1;
	union TCA9539_uInput P2;
};

union TCA9539_uInputA{
	unsigned long 		all;
	struct TCA9539_sInputP	 	Port;
};



union TCA9539_uOutputP0{
	unsigned char 		all;
	struct TCA9539_sBit	bit;
};


struct TCA9539_sOutput{
	union TCA9539_uOutputP0	P0;
	union TCA9539_uOutputP0	P1;
	union TCA9539_uOutputP0	P2;
};

union TCA9539_uOutput{
	unsigned long	all;
	struct TCA9539_sOutput	Port;
};

union TCA9539_uPolarityInversionP0{
	unsigned char all;
	struct TCA9539_sBit bit;
};

union  TCA9539_uPolarityInversionP1{
	unsigned char	all;
	struct TCA9539_sBit bit;
};


struct TCA9539_sPolarityInversion{
	union TCA9539_uPolarityInversionP0	P0;
	union TCA9539_uPolarityInversionP0	P1;
};

union TCA9539_uPolarityInversion{
	unsigned long all;
	struct TCA9539_sPolarityInversion Port;
};

union TCA9539_uConfigP0{
	unsigned char all;
	struct TCA9539_sBit bit;
};

union  TCA9539_uConfigP1{
	unsigned char	all;
	struct TCA9539_sBit bit;
};

struct TCA9539_sConfig{
	union TCA9539_uConfigP0	P0;
	union TCA9539_uConfigP0	P1;
};

union TCA9539_uConfig{
	unsigned long all;
	struct TCA9539_sConfig Port;
};



typedef struct {
	union TCA9539_uInputA 				Input;
	union TCA9539_uOutput				Output;
	union TCA9539_uPolarityInversion	PolarityInversion;
	union TCA9539_uConfig				Config;
} TCA9539Regs;


#endif