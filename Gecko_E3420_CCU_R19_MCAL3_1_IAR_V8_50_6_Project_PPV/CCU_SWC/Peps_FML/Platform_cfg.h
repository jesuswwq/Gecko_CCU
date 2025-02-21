

#ifndef __PLATFORM_CONFIG_H__
#define __PLATFORM_CONFIG_H__

#include <string.h>
#include <stdint.h>
#include "PEPS_ABI.h"
#include "Immo_AES128SWEnc.h"

#include "ME11_ABI.h"

// #include "Dio_IP.h"
// #include "irq_num_sf.h"
#include "Spi.h"
#include "SchM_Spi.h"

#include "mcu_delay.h"

#include "NCK2910_Api.h"

#define MAX_BUFFER_LENGTH 57U

// #define QN_DEBUG

// #define CALIBRATION_DEBUG

/*********************************************SPI3*****************************************************
  NCK2910���IO�ܽź궨��
    NCK2910_RDYN	: GPIO_H1
    NCK2910_RSTN	: GPIO_H3
    NCK2910_INTN	: GPIO_H0
    NCK2910_CSN		: GPIO_B0
    NCK2910_SCLK	: GPIO_B1
    NCK2910_MISO	: GPIO_B2
    NCK2910_MOSI	: GPIO_B3
*********************************************************************************************************/
#define NCK2910_INTN_PIN GPIO_D37

//	OUT_EXP_D_P27

#define PIN_NCK2910_CS GPIO_A10 // NCK2910AHNèŠ¯ç‰‡CS

#define NCK2910_CSN_HIGH() Dio_WriteChannel(PIN_NCK2910_CS, 1)
#define NCK2910_CSN_LOW() Dio_WriteChannel(PIN_NCK2910_CS, 0) // sdrv_gpio_set_pin_output_level(PIN_NCK2910_CS,0)

#define NCK2910_RSTN_HIGH() set_OUT_EXP_D_P27(1) // sdrv_gpio_set_pin_output_level(PIN_NCK2910_RESET,1)
#define NCK2910_RSTN_LOW() set_OUT_EXP_D_P27(0)  // sdrv_gpio_set_pin_output_level(PIN_NCK2910_RESET,0)

#define NJJ29C0_INTERRUPT_PIN GPIO_D28

#define PIN_NJJ29C0_CS GPIO_A9 // NJJ29C0Ð¾Æ¬CS

#define NJJ29C0_RSTN_HIGH() set_OUT_EXP_C_P00(1) // sdrv_gpio_set_pin_output_level(PIN_NJJ29C0_RESET,1)
#define NJJ29C0_RSTN_LOW() set_OUT_EXP_C_P00(0)  // sdrv_gpio_set_pin_output_level(PIN_NJJ29C0_RESET,0)

#define NJJ29C0_CSN_HIGH() Dio_WriteChannel(PIN_NJJ29C0_CS, 1) // sdrv_gpio_set_pin_output_level(PIN_NJJ29C0_CS,1)
#define NJJ29C0_CSN_LOW() Dio_WriteChannel(PIN_NJJ29C0_CS, 0)  // sdrv_gpio_set_pin_output_level(PIN_NJJ29C0_CS,0)

#define NJJ29C0_INTN_LEVEL() Dio_LevelType Get_NJJ29C0B_INT_PinLevel() // sdrv_gpio_read_pin_input_level(NJJ29C0_INTERRUPT_PIN)

typedef union
{
    uint32_t Value;
    struct
    {
        uint8 Low_byte;
        uint8 Mlow_byte;
        uint8 Mhigh_byte;
        uint8 High_byte;
    } CHAR_BYTE;
} LONG_UNION;

typedef union
{
    float value;
    struct
    {
        uint8 low_byte;
        uint8 mlow_byte;
        uint8 mhigh_byte;
        uint8 high_byte;
    } float_byte;
} FLOAT_UNION;

enum _generic_status
{
    kStatus_Success = 0,
    kStatus_Fail = 1,
    kStatus_ReadOnly = 2,
    kStatus_OutOfRange = 3,
    kStatus_InvalidArgument = 4,
    kStatus_Timeout = 5,
    kStatus_NoTransferInProgress = 6,
    kStatus_Busy = 7,
};

extern boolean NCK2910_Init_Flag;
extern boolean NJJ29C0_Init_Flag;

extern void _NCK2910_Hal_Init(void);

extern void _Nck2910_delay_us(uint32_t nus);
extern void Njj29c0_Delay(uint32_t count);

extern void Nck2910_Interrupt_En(void);
extern void NJJ29C0_Interrupt_En(void);

int NJJ29C0_Spi_ReadWrite(uint8_t *txbuf, uint8_t *rxbuf, uint32_t len);

/*********************************************************************************************************
** Function name:		NCK2910_SpiWrite
** Descriptions:		ͨ��SPI��������
** input parameters:	pu8WrBuf : SPIд����ָ��
**						WrBufLen : SPIд���峤�ȣ�unit(Byte)
** output parameters:
** Returned value:
*********************************************************************************************************/
extern void NCK2910_SpiWrite(uint8_t *pu8WrBuf, uint8_t WrBufLen);

/*********************************************************************************************************
** Function name:		NCK2910_SpiRead
** Descriptions:		ͨ��SPI������
** input parameters:	pu8RdBuf : SPI������ָ��
** output parameters:
** Returned value:
*********************************************************************************************************/
extern void NCK2910_SpiRead(uint8_t *pu8RdBuf);

#endif /*End of __PLATFORM_CONFIG_H__ */

/*--------EOF--------*/
