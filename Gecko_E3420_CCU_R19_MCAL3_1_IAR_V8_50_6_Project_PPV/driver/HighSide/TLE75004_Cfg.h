/*
 * TLE75xxx.h
 *
 *  
 *      Author: 
 */

#ifndef TLE75004_CFG_H_
#define TLE75004_CFG_H_

#include "Spi.h"
#include "Platform_Types.h"

#define	TLE75004_RREG_ADDRESS_STDDIAG	0x01U

#define TLE75004_CHANNEL_NUM 			4U

#define    TLE75004_CMD_WRITE     0x8000
#define    TLE75004_CMD_READ      0x4002

#define    TLE75004_REG_OUT         	0x00	//0000,00	Power output control register
#define    TLE75004_REG_MAPIN0         	0x04	//0001,00	Input Mapping (Input Pin 0)
#define    TLE75004_REG_MAPIN1         	0x05	//0001,01	Input Mapping (Input Pin 1)
#define    TLE75004_REG_INST         	0x06	//0001,10	Input Status Monitor
#define    TLE75004_REG_DIAG_IOL        0x08	//0010,00	Open Load diagnostic current control
#define    TLE75004_REG_DIAG_OSM        0x09	//0010,01	Output Status Monitor
#define    TLE75004_REG_HWCR        	0x0C	//0011,00	Hardware Configuration Register
#define    TLE75004_REG_HWCR_OCL    	0x0D	//0011,01	Output Clear Latch

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
}TLE75004_StdDiag_t;

#endif /* TLE75XXX_H_ */
