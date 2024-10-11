
#ifndef __TLE94103_H_
#define __TLE94103_H_

#include "Std_Types.h"


/****************************************************CONFIGURATION************************************************************/
//bit 7: OP
#define TLE94103_OP_READ    0
#define TLE94103_OP_WRITE   1

//bit 6:2:address
#define HB_ACT_1_CTRL_REG      (0x00u)      /*Half-bridge output control 1, LS or HS enable, rw*/
#define FM_CLK_CTRL_REG        (0x0Cu)      /*Frequency modulation select, rw*/
#define HB_OLBLK_CTRL_REG      (0x1Au)      /*1B: Open load failures are not reported in the GEF, rw*/
#define HB_CONFIG_CTRL_REG     (0x19u)      /*Device Configuration control,DEV_IDn, r*/
#define HB_SYS_DIAG_1_REG      (0x06u)      /*Global status 1, rc*/
#define HB_SYS_DIAG_2_REG      (0x16u)      /*Overcurrent error status of half-bridge outputs 1 - 4, rc*/
#define HB_SYS_DIAG_3_REG      (0x06u)      /*Open load error status of half-bridge outputs 1 - 4, rc*/

//bit 1:LABT
#define NO_DAISY_CHAIN_LABT 1
#define DASY_CHAIN_LABT     0

/****************************************************Global API*********************************************************/
typedef enum
{
  TLE94103_CHIP_A,
  TLE94103_CHIP_B,

  TLE94103_CHIP_NUM
}TLE94103_CHIPID_e;

typedef enum
{
  TLE94103_OUT_1,
  TLE94103_OUT_2,
  TLE94103_OUT_3,

  TLE94103_OUT_CH_MAX
}TLE94103_OUT_Ch_e;

typedef enum
{
  TLE94103_FM_DISABLE,
  TLE94103_FM_FREQ15625HZ,
  TLE94103_FM_FREQ31250HZ,
  TLE94103_FM_FREQ62500HZ,

  TLE94103_FM_MAX
}TLE94103_FMModulation_e;

typedef enum
{
  TLE94103_NOERR,                         /*chip no error detect*/
  TLE94103_COM_SPI_ERR,                   /* SPI error detection */
  TLE94103_OUT_OPENLOAD_OVERCURRENT,      /* Load error detection (logic OR combination of Open Load and Overcurrent*/
  TLE94103_VS_UV,                         /*VS Undervoltage error detection*/
  TLE94103_VS_OV,                         /*VS Overvoltage error detection*/
  TLE94103_TEMPERATURE_SHUTDOWN,          /*Temperature shutdown error detection*/
  TLE94103_TEMPERATURE_WARNING,           /*Temperature pre-warning error detection*/

  TLE94103_ERRMAX
}TLE94103_CHIP_GlobalDiag_e;


extern void TLE94103_Init(void);
extern void TLE94103_SwitchToSleep(TLE94103_CHIPID_e ChipID);
extern Std_ReturnType TLE94103_Set_HSChannelON(TLE94103_CHIPID_e ChipID, TLE94103_OUT_Ch_e channel);
extern Std_ReturnType TLE94103_Set_LSChannelON(TLE94103_CHIPID_e ChipID, TLE94103_OUT_Ch_e channel);
extern Std_ReturnType TLE94103_Set_ChannelOFF(TLE94103_CHIPID_e ChipID, TLE94103_OUT_Ch_e channel);
extern uint8 TLE94103_Get_DeviceID(TLE94103_CHIPID_e ChipID);
extern Std_ReturnType TLE94103_Set_FM_Modulation(TLE94103_CHIPID_e ChipID,TLE94103_FMModulation_e FMMode);
extern Std_ReturnType TLE94103_Clear_ChannelError(TLE94103_OUT_Ch_e channel);

extern TLE94103_CHIP_GlobalDiag_e TLE94103_DiagChip_Status(TLE94103_CHIPID_e ChipID);
extern boolean TLE94103_DiagHSCh_OverCurrent(TLE94103_CHIPID_e ChipID, TLE94103_OUT_Ch_e channel);
extern boolean TLE94103_DiagLSCh_OverCurrent(TLE94103_CHIPID_e ChipID, TLE94103_OUT_Ch_e channel);
extern boolean TLE94103_DiagHSCh_Openload(TLE94103_CHIPID_e ChipID, TLE94103_OUT_Ch_e channel);
extern boolean TLE94103_DiagLSCh_Openload(TLE94103_CHIPID_e ChipID, TLE94103_OUT_Ch_e channel);
#endif /*__TLE94103_H_*/