#ifndef _IOEXP_TCA6424_CFG_H_
#define _IOEXP_TCA6424_CFG_H_

#include "I2c.h"
#include "Dio.h"

#define MACRO *(unsigned char*)&

/**************************************************************************************************************/
/***                                        MACRO Define                                                    ***/
/*****                                                                                                     ****/
/**************************************************************************************************************/


/************************** I2C Address ***************************************/
#define TCA6424A_A_ADDRESS		0x23 		// I2C Address 0100 01 + ADDR + R/W
#define TCA6424A_C_ADDRESS		0x22 		// I2C Address 0100 01 + ADDR + R/W
#define TCA6424A_B_ADDRESS		0x23 		// I2C Address 0100 01 + ADDR + R/W
#define TCA6424A_D_ADDRESS		0x22 		// I2C Address 0100 01 + ADDR + R/W	
#define TCA6424A_E_ADDRESS		0x22 		// I2C Address 0100 01 + ADDR + R/W											
/************************** I2C Registers *************************************/
#define TCA6424A_INPUT_REG0		0x00		// Input status register
#define TCA6424A_INPUT_REG1		0x01		// Input status register
#define TCA6424A_INPUT_REG2		0x02		// Input status register
#define TCA6424A_OUTPUT_REG0	0x04		// Output register to change state of output BIT set to 1, output set HIGH
#define TCA6424A_OUTPUT_REG1	0x05		// Output register to change state of output BIT set to 1, output set HIGH
#define TCA6424A_OUTPUT_REG2	0x06		// Output register to change state of output BIT set to 1, output set HIGH
#define TCA6424A_POLARITY_REG0 	0x08		// Polarity inversion register. BIT '1' inverts input polarity of register 0x00
#define TCA6424A_POLARITY_REG1 	0x09		// Polarity inversion register. BIT '1' inverts input polarity of register 0x00
#define TCA6424A_POLARITY_REG2 	0x0A		// Polarity inversion register. BIT '1' inverts input polarity of register 0x00
#define TCA6424A_CONFIG_REG0   	0x0C		// Configuration register. BIT = '1' sets port to input BIT = '0' sets port to output
#define TCA6424A_CONFIG_REG1   	0x0D		// Configuration register. BIT = '1' sets port to input BIT = '0' sets port to output
#define TCA6424A_CONFIG_REG2   	0x0E		// Configuration register. BIT = '1' sets port to input BIT = '0' sets port to output

#define TCA6424_CMD_WRIRE       (0x80U)
#define TCA6424_CMD_READ        (0x0U)

#define TCA6424_PORTDIR_OUTPUT   (0x0U)
#define TCA6424_PORTDIR_INPUT    (0x1U)  
/**************************************************************************************************************/
/***                                        Configration                                                    ***/
/*****                          user could change based on project                                         ****/
/**************************************************************************************************************/
//PORTdir config
#define TCA6424_PORT0DIR (uint8)((TCA6424_PORTDIR_OUTPUT<<7)|(TCA6424_PORTDIR_OUTPUT<<6)|(TCA6424_PORTDIR_OUTPUT<<5) \
                                 |(TCA6424_PORTDIR_OUTPUT<<4)|(TCA6424_PORTDIR_OUTPUT<<3)|(TCA6424_PORTDIR_OUTPUT<<2) \
                                 |(TCA6424_PORTDIR_OUTPUT<<1)|(TCA6424_PORTDIR_OUTPUT<<0))

#define TCA6424_PORT1DIR (uint8)((TCA6424_PORTDIR_OUTPUT<<7)|(TCA6424_PORTDIR_OUTPUT<<6)|(TCA6424_PORTDIR_OUTPUT<<5) \
                                 |(TCA6424_PORTDIR_OUTPUT<<4)|(TCA6424_PORTDIR_OUTPUT<<3)|(TCA6424_PORTDIR_OUTPUT<<2) \
                                 |(TCA6424_PORTDIR_OUTPUT<<1)|(TCA6424_PORTDIR_OUTPUT<<0))
                                 
#define TCA6424_PORTDIRALLOUT (uint8)((TCA6424_PORTDIR_OUTPUT<<7)|(TCA6424_PORTDIR_OUTPUT<<6)|(TCA6424_PORTDIR_OUTPUT<<5) \
                                     |(TCA6424_PORTDIR_OUTPUT<<4)|(TCA6424_PORTDIR_OUTPUT<<3)|(TCA6424_PORTDIR_OUTPUT<<2) \
                                     |(TCA6424_PORTDIR_OUTPUT<<1)|(TCA6424_PORTDIR_OUTPUT<<0))  

#define TCA6424_PORTDIRALLIN (uint8)((TCA6424_PORTDIR_INPUT<<7)|(TCA6424_PORTDIR_INPUT<<6)|(TCA6424_PORTDIR_INPUT<<5) \
                                     |(TCA6424_PORTDIR_INPUT<<4)|(TCA6424_PORTDIR_INPUT<<3)|(TCA6424_PORTDIR_INPUT<<2) \
                                     |(TCA6424_PORTDIR_INPUT<<1)|(TCA6424_PORTDIR_INPUT<<0))  

//TCA6424_CHIP_C                                     
#define TCA6424_C_PORT0DIR (uint8)((TCA6424_PORTDIR_OUTPUT<<7)|(TCA6424_PORTDIR_OUTPUT<<6)|(TCA6424_PORTDIR_OUTPUT<<5) \
                                  |(TCA6424_PORTDIR_INPUT<<4)|(TCA6424_PORTDIR_INPUT<<3)|(TCA6424_PORTDIR_OUTPUT<<2) \
                                  |(TCA6424_PORTDIR_INPUT<<1)|(TCA6424_PORTDIR_OUTPUT<<0))

#define TCA6424_C_PORT1DIR (uint8)((TCA6424_PORTDIR_OUTPUT<<7)|(TCA6424_PORTDIR_OUTPUT<<6)|(TCA6424_PORTDIR_OUTPUT<<5) \
                                  |(TCA6424_PORTDIR_OUTPUT<<4)|(TCA6424_PORTDIR_INPUT<<3)|(TCA6424_PORTDIR_INPUT<<2) \
                                  |(TCA6424_PORTDIR_OUTPUT<<1)|(TCA6424_PORTDIR_OUTPUT<<0)) 

#define TCA6424_C_PORT2DIR (uint8)((TCA6424_PORTDIR_INPUT<<7)|(TCA6424_PORTDIR_INPUT<<6)|(TCA6424_PORTDIR_INPUT<<5) \
                                  |(TCA6424_PORTDIR_INPUT<<4)|(TCA6424_PORTDIR_INPUT<<3)|(TCA6424_PORTDIR_OUTPUT<<2) \
                                  |(TCA6424_PORTDIR_OUTPUT<<1)|(TCA6424_PORTDIR_OUTPUT<<0)) 

//TCA6424_CHIP_D
#define TCA6424_D_PORT0DIR (uint8)((TCA6424_PORTDIR_OUTPUT<<7)|(TCA6424_PORTDIR_OUTPUT<<6)|(TCA6424_PORTDIR_OUTPUT<<5) \
                                  |(TCA6424_PORTDIR_OUTPUT<<4)|(TCA6424_PORTDIR_OUTPUT<<3)|(TCA6424_PORTDIR_OUTPUT<<2) \
                                  |(TCA6424_PORTDIR_OUTPUT<<1)|(TCA6424_PORTDIR_OUTPUT<<0))

#define TCA6424_D_PORT1DIR (uint8)((TCA6424_PORTDIR_OUTPUT<<7)|(TCA6424_PORTDIR_INPUT<<6)|(TCA6424_PORTDIR_OUTPUT<<5) \
                                  |(TCA6424_PORTDIR_OUTPUT<<4)|(TCA6424_PORTDIR_OUTPUT<<3)|(TCA6424_PORTDIR_OUTPUT<<2) \
                                  |(TCA6424_PORTDIR_OUTPUT<<1)|(TCA6424_PORTDIR_OUTPUT<<0)) 

#define TCA6424_D_PORT2DIR (uint8)((TCA6424_PORTDIR_OUTPUT<<7)|(TCA6424_PORTDIR_OUTPUT<<6)|(TCA6424_PORTDIR_OUTPUT<<5) \
                                  |(TCA6424_PORTDIR_OUTPUT<<4)|(TCA6424_PORTDIR_OUTPUT<<3)|(TCA6424_PORTDIR_OUTPUT<<2) \
                                  |(TCA6424_PORTDIR_OUTPUT<<1)|(TCA6424_PORTDIR_OUTPUT<<0))                             
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
    uint8            Port2Dir;
    Dio_ChannelType  RstPin;
}TCA6424_Ctrl_t;    

struct TCA6424A_sBit{
	unsigned char B0:1;
	unsigned char B1:1;
	unsigned char B2:1;
	unsigned char B3:1;
	unsigned char B4:1;
	unsigned char B5:1;
	unsigned char B6:1;
	unsigned char B7:1;

};

union TCA6424_uInput{
	unsigned char	all;
	struct TCA6424A_sBit bit;
};

struct TCA6424A_sInputP{
	union TCA6424_uInput P0;
	union TCA6424_uInput P1;
	union TCA6424_uInput P2;
};

union TCA6424A_uInputA{
	unsigned long 		all;
	struct TCA6424A_sInputP	 	Port;
};



union TCA6424A_uOutputP0{
	unsigned char 		all;
	struct TCA6424A_sBit	bit;
};


struct TCA6424A_sOutput{
	union TCA6424A_uOutputP0	P0;
	union TCA6424A_uOutputP0	P1;
	union TCA6424A_uOutputP0	P2;
};

union TCA6424A_uOutput{
	unsigned long	all;
	struct TCA6424A_sOutput	Port;
};

union TCA6424A_uPolarityInversionP0{
	unsigned char all;
	struct TCA6424A_sBit bit;
};

union  TCA6424A_uPolarityInversionP1{
	unsigned char	all;
	struct TCA6424A_sBit bit;
};

union  TCA6424A_uPolarityInversionP2{
	unsigned char	all;
	struct TCA6424A_sBit bit;
};

struct TCA6424A_sPolarityInversion{
	union TCA6424A_uPolarityInversionP0	P0;
	union TCA6424A_uPolarityInversionP0	P1;
	union TCA6424A_uPolarityInversionP0	P2;
};

union TCA6424A_uPolarityInversion{
	unsigned long all;
	struct TCA6424A_sPolarityInversion Port;
};

union TCA6424A_uConfigP0{
	unsigned char all;
	struct TCA6424A_sBit bit;
};

union  TCA6424A_uConfigP1{
	unsigned char	all;
	struct TCA6424A_sBit bit;
};

union  TCA6424A_uConfigP2{
	unsigned char	all;
	struct TCA6424A_sBit bit;
};

struct TCA6424A_sConfig{
	union TCA6424A_uConfigP0	P0;
	union TCA6424A_uConfigP0	P1;
	union TCA6424A_uConfigP0	P2;
};

union TCA6424A_uConfig{
	unsigned long all;
	struct TCA6424A_sConfig Port;
};



typedef struct {
	union TCA6424A_uInputA 				Input;
	union TCA6424A_uOutput				Output;
	union TCA6424A_uPolarityInversion	PolarityInversion;
	union TCA6424A_uConfig				Config;
} TCA6424ARegs;


#endif