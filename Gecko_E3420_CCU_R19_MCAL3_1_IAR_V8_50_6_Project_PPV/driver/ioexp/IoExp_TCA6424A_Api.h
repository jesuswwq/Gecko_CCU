#ifndef _IOEXP_TCA6424_API_H_
#define _IOEXP_TCA6424_API_H_

#include "Std_Types.h"
#include "Dio.h"

typedef enum
{
    TCA6424_CHIP_A,         /* used for channel OUT_EXP_A_P00 - OUT_EXP_A_P27 */
    TCA6424_CHIP_B,         /* used for channel OUT_EXP_B_P00 - OUT_EXP_B_P27 */
    TCA6424_CHIP_C,         /* used for channel OUT_EXP_C_P00 - OUT_EXP_C_P27 */
    TCA6424_CHIP_D,         /* used for channel OUT_EXP_D_P00 - OUT_EXP_D_P27 */
    TCA6424_CHIP_E,         /* used for channel OUT_EXP_E_P00 - OUT_EXP_E_P27 */

    TCA6424_CHIP_NUM
}TCA6424_ChipID_e_;

typedef enum
{
    /*Port 0*/
    IOEXP_TCA6424_P00,
    IOEXP_TCA6424_P01,
    IOEXP_TCA6424_P02,
    IOEXP_TCA6424_P03,
    IOEXP_TCA6424_P04,
    IOEXP_TCA6424_P05,
    IOEXP_TCA6424_P06,
    IOEXP_TCA6424_P07,

    /*PORT 1*/
    IOEXP_TCA6424_P10,
    IOEXP_TCA6424_P11,
    IOEXP_TCA6424_P12,
    IOEXP_TCA6424_P13,
    IOEXP_TCA6424_P14,
    IOEXP_TCA6424_P15,
    IOEXP_TCA6424_P16,
    IOEXP_TCA6424_P17,

    /*PORT 2*/
    IOEXP_TCA6424_P20,
    IOEXP_TCA6424_P21,
    IOEXP_TCA6424_P22,
    IOEXP_TCA6424_P23,
    IOEXP_TCA6424_P24,
    IOEXP_TCA6424_P25,
    IOEXP_TCA6424_P26,
    IOEXP_TCA6424_P27,

    IOEXP_TCA6424_PORT_NUM 
    
}TCA6424_Channel_e_;

typedef enum
{
    TCA6424_PORTGROUP0,
    TCA6424_PORTGROUP1,
    TCA6424_PORTGROUP2,

    TCA6424_PORTGROUPNUM
}TCA6424_PortGoup_e_;

extern void TCA6424_Init(void);
extern Std_ReturnType IoExp_TCA6424_SetChannelOutLevel(TCA6424_ChipID_e_ ChipID, 
                                                                TCA6424_Channel_e_ ChannelNum, Dio_LevelType OutLevel);
extern Std_ReturnType IoExp_TCA6424_SetAllPortHigh(TCA6424_ChipID_e_ ChipID);
extern Std_ReturnType IoExp_TCA6424_SetAllPortLow(TCA6424_ChipID_e_ ChipID);
extern uint8 IoExp_TCA6424_GetPortInputValue(TCA6424_ChipID_e_ ChipID, TCA6424_PortGoup_e_ PortIdx);
extern Dio_LevelType IoExp_TCA6424_GetChannelInputLevel(TCA6424_ChipID_e_ ChipID, TCA6424_Channel_e_ Channel);
Dio_LevelType IoExp_TCA6424_GetChannelOutputSt(TCA6424_ChipID_e_ ChipID, TCA6424_Channel_e_ Channel);
extern Std_ReturnType AD4067_IoExp_TCA6424_SetPort0(TCA6424_ChipID_e_ ChipID, uint8 Channel);
extern Std_ReturnType AD4067_IoExp_TCA6424_SetPort2(TCA6424_ChipID_e_ ChipID, uint8 Channel);

void I2c_CanTcv_Ctr(void);
void I2c_6424_C_Ctr(void);
void I2c_6424_B_Ctr(void);
void I2c_6424_D_Ctr(void);

extern Std_ReturnType Set_WakeUp_To_HIGH(TCA6424_ChipID_e_ ChipID);
extern Std_ReturnType Set_WakeUp_To_LOW(TCA6424_ChipID_e_ ChipID);
extern Std_ReturnType Set_TCA1043_To_Normal(TCA6424_ChipID_e_ ChipID);
extern Std_ReturnType Set_TCA1043_To_GoToSleep(TCA6424_ChipID_e_ ChipID);

#endif
