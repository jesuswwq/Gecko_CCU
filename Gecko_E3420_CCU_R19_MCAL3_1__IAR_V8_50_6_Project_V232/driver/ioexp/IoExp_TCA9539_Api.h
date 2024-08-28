#ifndef _IOEXP_TCA9539_API_H_
#define _IOEXP_TCA9539_API_H_

#include "Std_Types.h"
#include "Dio.h"

typedef enum
{
    // TCA9539_CHIP_A,     //address:0x74, all output, device E
    TCA9539_CHIP_A,     //Address:0x77, all input, IDL0-IDL16
    TCA9539_CHIP_B,     //Address:0x75, all inpput, IDL17-TDX2
    
    TCA9539_CHIP_NUM
}TCA9539_ChipID_e_;

typedef enum
{
    /*Port 0*/
    IOEXP_TCA9539_P00,
    IOEXP_TCA9539_P01,
    IOEXP_TCA9539_P02,
    IOEXP_TCA9539_P03,
    IOEXP_TCA9539_P04,
    IOEXP_TCA9539_P05,
    IOEXP_TCA9539_P06,
    IOEXP_TCA9539_P07,

    /*PORT 1*/
    IOEXP_TCA9539_P10,
    IOEXP_TCA9539_P11,
    IOEXP_TCA9539_P12,
    IOEXP_TCA9539_P13,
    IOEXP_TCA9539_P14,
    IOEXP_TCA9539_P15,
    IOEXP_TCA9539_P16,
    IOEXP_TCA9539_P17,

    IOEXP_TCA9539_PORT_NUM 
    
}TCA9539_Channel_e_;

typedef enum
{
    TCA9539_PORTGROUP0,
    TCA9539_PORTGROUP1,

    TCA9539_PORTGROUPNUM
}TCA9539_PortGoup_e_;

#define CHANNEL_NUM 2
#define CHIP_PIN_ID 16
extern boolean Tca9539_IOValue[CHANNEL_NUM][CHIP_PIN_ID];

typedef uint8 ActionType;
#define REQCOM_KEEP 1U
#define REQCOM_TRIG 2U
#define RECEI_PDU 3U
#define MCU_WAKEUP 4U
#define OTHER_WAKEUP 4U
#define  WAKEUP_SOURCE_NUM 24U
typedef struct {
    uint32 BitIndex;   /**< pointer to the SDU (i.e.  *    payload data) of the PDU */
    uint8  WakeupReturnValue;        /**< length of the SDU in bytes */
    uint8  NMUserDataWakeupReas;
}WakeupSourceType;
extern WakeupSourceType WakeUpSource[WAKEUP_SOURCE_NUM];
extern void TCA9539_Init(void);
extern Std_ReturnType IoExp_TCA9539_SetChannelOutLevel(TCA9539_ChipID_e_ ChipID, 
                                                                TCA9539_Channel_e_ ChannelNum, Dio_LevelType OutLevel);
extern Std_ReturnType IoExp_TCA9539_SetAllPortHigh(TCA9539_ChipID_e_ ChipID);
extern Std_ReturnType IoExp_TCA9539_SetAllPortLow(TCA9539_ChipID_e_ ChipID);
extern Std_ReturnType IoExp_TCA9539_GetPortInputValue(TCA9539_ChipID_e_ ChipID, TCA9539_PortGoup_e_ PortIdx,uint8* PortValue);
extern Dio_LevelType IoExp_TCA9539_GetChannelInputLevel(TCA9539_ChipID_e_ ChipID, TCA9539_Channel_e_ Channel);
extern Dio_LevelType IoExp_TCA9539_GetChannelOutputSt(TCA9539_ChipID_e_ ChipID, TCA9539_Channel_e_ Channel);

#endif
