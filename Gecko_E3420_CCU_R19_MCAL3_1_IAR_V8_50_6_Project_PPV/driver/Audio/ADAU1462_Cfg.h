
#ifndef _ADAU1462_CFG_H_
#define _ADAU1462_CFG_H_

#include "Std_Types.h"

#define ADAU_DEVICEID   (0x0)
#define ADAU1462_WRITE  (0x00u)
#define ADAU1462_READ   (0x01u)

//Master Clock, PLL, and Clock Generator Registers
#define PLL_CTRL0       0xF000    //PLL feedback divider
#define PLL_CTRL1       0xF001    //PLL prescale divider
#define PLL_CLK_SRC     0xF002    //PLL clock source 
#define PLL_ENABLE      0xF003    //PLL enable 
#define PLL_LOCK        0xF004    //PLL lock
#define MCLK_OUT        0xF005    //CLKOUT control
#define PLL_WATCHDOG    0xF006    //Analog PLL watchdog control 
#define CLK_GEN1_M      0xF020    //Denominator (M) for Clock Generator 1
#define CLK_GEN1_N      0xF021    //Numerator (N) for Clock Generator 1
#define CLK_GEN2_M      0xF022    //Denominator (M) for Clock Generator 2
#define CLK_GEN2_N      0xF023    //Numerator (N) for Clock Generator 2
#define CLK_GEN3_M      0xF024    //Denominator (M) for Clock Generator 3
#define CLK_GEN3_N      0xF025    //Numerator (N) for Clock Generator 3
#define CLK_GEN3_SRC    0xF026    //Input source for Clock Generator 3
#define CLK_GEN3_LOCK   0xF027    //Lock bit for Clock Generator 3 input reference

//Power Reduction Registers
#define POWER_ENABLE0   0xF050  //Disables clock generators, serial ports, and ASRCs
#define POWER_ENABLE1   0xF051  //Disables PDM microphone inputs,S/PDIF interfaces, and auxiliary ADCs

//Audio Routing Matrix Registers
#define ASRC_INPUT0 ASRC       0xF100  //Sinput selector (ASRC 0, Channel 0 and Channel 1) 
#define ASRC_INPUT1 ASRC       0xF101  //Sinput selector (ASRC 1, Channel 2 and Channel 3) 
#define ASRC_INPUT2 ASRC       0xF102  //Sinput selector (ASRC 2, Channel 4 and Channel 5) 
#define ASRC_INPUT3 ASRC       0xF103  //Sinput selector (ASRC 3, Channel 6 and Channel 7) 
#define ASRC_INPUT4 ASRC       0xF104  //Sinput selector (ASRC 4, Channel 8 and Channel 9) 
#define ASRC_INPUT5 ASRC       0xF105  //Sinput selector (ASRC 5, Channel 10 and Channel 11) 
#define ASRC_INPUT6 ASRC       0xF106  //Sinput selector (ASRC 6, Channel 12 and Channel 13) 
#define ASRC_INPUT7 ASRC       0xF107  //Sinput selector (ASRC 7, Channel 14 and Channel 15) 
#define ASRC_OUT_RATE0         0xF140  //ASRC output rate (ASRC 0, Channel 0 and Channel 1) 
#define ASRC_OUT_RATE1         0xF141  //ASRC output rate (ASRC 1, Channel 2 and Channel 3) 
#define ASRC_OUT_RATE2         0xF142  //ASRC output rate (ASRC 2, Channel 4 and Channel 5) 
#define ASRC_OUT_RATE3         0xF143  //ASRC output rate (ASRC 3, Channel 6 and Channel 7) 
#define ASRC_OUT_RATE4         0xF144  //ASRC output rate (ASRC 4, Channel 8 and Channel 9) 
#define ASRC_OUT_RATE5         0xF145  //ASRC output rate (ASRC 5, Channel 10 and Channel 11)
#define ASRC_OUT_RATE6         0xF146  //ASRC output rate (ASRC 6, Channel 12 and Channel 13)
#define ASRC_OUT_RATE7         0xF147  //ASRC output rate (ASRC 7, Channel 14 and Channel 15)
#define SOUT_SOURCE0           0xF180  //Source of data for serial output port (Channel 0 and Channel 1)
#define SOUT_SOURCE1           0xF181  //Source of data for serial output port (Channel 2 and Channel 3)
#define SOUT_SOURCE2           0xF182  //Source of data for serial output port (Channel 4 and Channel 5)
#define SOUT_SOURCE3           0xF183  //Source of data for serial output port (Channel 6 and Channel 7)
#define SOUT_SOURCE4           0xF184  //Source of data for serial output port (Channel 8 and Channel 9)
#define SOUT_SOURCE5           0xF185  //Source of data for serial output port (Channel 10 and Channel 11) 
#define SOUT_SOURCE6           0xF186  //Source of data for serial output port (Channel 12 and Channel 13) 
#define SOUT_SOURCE7           0xF187  //Source of data for serial output port (Channel 14 and Channel 15) 
#define SOUT_SOURCE8           0xF188  //Source of data for serial output port (Channel 16 and Channel 17) 
#define SOUT_SOURCE9           0xF189  //Source of data for serial output port (Channel 18 and Channel 19) 
#define SOUT_SOURCE10          0xF18A  // Source of data for serial output port (Channel 20 and Channel 21) 
#define SOUT_SOURCE11          0xF18B  // Source of data for serial output port (Channel 22 and Channel 23) 
#define SOUT_SOURCE12          0xF18C  // Source of data for serial output port (Channel 24 and Channel 25) 
#define SOUT_SOURCE13          0xF18D  // Source of data for serial output port (Channel 26 and Channel 27) 
#define SOUT_SOURCE14          0xF18E  // Source of data for serial output port (Channel 28 and Channel 29) 
#define SOUT_SOURCE15          0xF18F  // Source of data for serial output port (Channel 30 and Channel 31) 
#define SOUT_SOURCE16          0xF190  // Source of data for serial output port (Channel 32 and Channel 33) 
#define SOUT_SOURCE17          0xF191  // Source of data for serial output port (Channel 34 and Channel 35) 
#define SOUT_SOURCE18          0xF192  // Source of data for serial output port (Channel 36 and Channel 37) 
#define SOUT_SOURCE19          0xF193  // Source of data for serial output port (Channel 38 and Channel 39) 
#define SOUT_SOURCE20          0xF194  // Source of data for serial output port (Channel 40 and Channel 41) 
#define SOUT_SOURCE21          0xF195  // Source of data for serial output port (Channel 42 and Channel 43) 
#define SOUT_SOURCE22          0xF196  // Source of data for serial output port (Channel 44 and Channel 45) 
#define SOUT_SOURCE23          0xF197  // Source of data for serial output port (Channel 46 and Channel 47) 
#define SPDIFTX_INPUT          0xF1C0  ///S/PDIF transmitter data selector

//Serial Port Registers
#define SERIAL_BYTE_0_0     0xF200 //Serial Port Control 0 (SDATA_IN0 pin)
#define SERIAL_BYTE_0_1     0xF201 //Serial Port Control 1 (SDATA_IN0 pin)
#define SERIAL_BYTE_1_0     0xF204 //Serial Port Control 0 (SDATA_IN1 pin)
#define SERIAL_BYTE_1_1     0xF205 //Serial Port Control 1 (SDATA_IN1 pin)
#define SERIAL_BYTE_2_0     0xF208 //Serial Port Control 0 (SDATA_IN2 pin)
#define SERIAL_BYTE_2_1     0xF209 //Serial Port Control 1 (SDATA_IN2 pin)
#define SERIAL_BYTE_3_0     0xF20C //Serial Port Control 0 (SDATA_IN3 pin)
#define SERIAL_BYTE_3_1     0xF20D //Serial Port Control 1 (SDATA_IN3 pin)
#define SERIAL_BYTE_4_0     0xF210 //Serial Port Control 0 (SDATA_OUT0 pin)
#define SERIAL_BYTE_4_1     0xF211 //Serial Port Control 1 (SDATA_OUT0 pin)
#define SERIAL_BYTE_5_0     0xF214 //Serial Port Control 0 (SDATA_OUT1 pin)
#define SERIAL_BYTE_5_1     0xF215 //Serial Port Control 1 (SDATA_OUT1 pin)
#define SERIAL_BYTE_6_0     0xF218 //Serial Port Control 0 (SDATA_OUT2 pin)
#define SERIAL_BYTE_6_1     0xF219 //Serial Port Control 1 (SDATA_OUT2 pin)
#define SERIAL_BYTE_7_0     0xF21C //Serial Port Control 0 (SDATA_OUT3 pin)
#define SERIAL_BYTE_7_1     0xF21D //Serial Port Control 1 (SDATA_OUT3 pin

//Asynchronous Sample Rate Converters Registers
#define ASRC_LOCK       0xF580     ////ASRC lock status
#define ASRC_MUTE       0xF581     //ASRC mute 
#define ASRC0_RATIO     0xF582     //ASRC ratio (//ASRC 0, Channel 0 and Channel 1)
#define ASRC1_RATIO     0xF583     //ASRC ratio (//ASRC 1, Channel 2 and Channel 3)
#define ASRC2_RATIO     0xF584     //ASRC ratio (//ASRC 2, Channel 4 and Channel 5)
#define ASRC3_RATIO     0xF585     //ASRC ratio (//ASRC 3, Channel 6 and Channel 7)
#define ASRC4_RATIO     0xF586     //ASRC ratio (//ASRC 4, Channel 8 and Channel 9)
#define ASRC5_RATIO     0xF587     //ASRC ratio (//ASRC 5, Channel 10 and Channel 11)
#define ASRC6_RATIO     0xF588     //ASRC ratio (//ASRC 6, Channel 12 and Channel 13)
#define ASRC7_RATIO     0xF589     //ASRC ratio (//ASRC 7, Channel 14 and Channel 15)

//Multipurpose Pins Registers
#define MP0_MODE        0xF510   //Multipurpose pin mode (SS_M/MP0)
#define MP1_MODE        0xF511   //Multipurpose pin mode (MOSI_M/MP1)
#define MP2_MODE        0xF512   //Multipurpose pin mode (SCL_M/SCLK_M/MP2)
#define MP3_MODE        0xF513   //Multipurpose pin mode (SDA_M/MISO_M/MP3)
#define MP4_MODE        0xF514   //Multipurpose pin mode (LRCLK_OUT0/MP4)
#define MP5_MODE        0xF515   //Multipurpose pin mode (LRCLK_OUT1/MP5)
#define MP6_MODE        0xF516   //Multipurpose pin mode (MP6)
#define MP7_MODE        0xF517   //Multipurpose pin mode (MP7)
#define MP8_MODE        0xF518   //Multipurpose pin mode (LRCLK_OUT2/MP8)
#define MP9_MODE        0xF519   //Multipurpose pin mode (LRCLK_OUT3/MP9)
#define MP10_MODE       0xF51A   //Multipurpose pin mode (LRCLK_IN0/MP10) 
#define MP11_MODE       0xF51B   //Multipurpose pin mode (LRCLK_IN1/MP11) 
#define MP12_MODE       0xF51C   //Multipurpose pin mode (LRCLK_IN2/MP12) 
#define MP13_MODE       0xF51D   //Multipurpose pin mode (LRCLK_IN3/MP13) 
#define MP0_WRITE       0xF520   //Multipurpose pin write value (SS_M/MP0)
#define MP1_WRITE       0xF521   //Multipurpose pin write value (MOSI_M/MP1)
#define MP2_WRITE       0xF522   //Multipurpose pin write value (SCL_M/SCLK_M/MP2)
#define MP3_WRITE       0xF523   //Multipurpose pin write value (SDA_M/MISO_M/MP3)
#define MP4_WRITE       0xF524   //Multipurpose pin write value (LRCLK_OUT0/MP4)
#define MP5_WRITE       0xF525   //Multipurpose pin write value (LRCLK_OUT1/MP5)
#define MP6_WRITE       0xF526   //Multipurpose pin write value (MP6)
#define MP7_WRITE       0xF527   //Multipurpose pin write value (MP7)
#define MP8_WRITE       0xF528   //Multipurpose pin write value (LRCLK_OUT2/MP8)
#define MP9_WRITE       0xF529   //Multipurpose pin write value (LRCLK_OUT3/MP9)
#define MP10_WRITE      0xF52A   //Multipurpose pin write value (LRCLK_IN0/MP10) 
#define MP11_WRITE      0xF52B   //Multipurpose pin write value (LRCLK_IN1/MP11) 
#define MP12_WRITE      0xF52C   //Multipurpose pin write value (LRCLK_IN2/MP12) 
#define MP13_WRITE      0xF52D   //Multipurpose pin write value (LRCLK_IN3/MP13) 
#define MP0_READ        0xF530   //Multipurpose pin read value (SS_M/MP0)
#define MP1_READ        0xF531   //Multipurpose pin read value (MOSI_M/MP1)
#define MP2_READ        0xF532   //Multipurpose pin read value (SCL_M/SCLK_M/MP2)
#define MP3_READ        0xF533   //Multipurpose pin read value (SDA_M/MISO_M/MP3)
#define MP4_READ        0xF534   //Multipurpose pin read value (LRCLK_OUT0/MP4)
#define MP5_READ        0xF535   //Multipurpose pin read value (LRCLK_OUT1/MP5)
#define MP6_READ        0xF536   //Multipurpose pin read value (MP6)
#define MP7_READ        0xF537   //Multipurpose pin read value (MP7)
#define MP8_READ        0xF538   //Multipurpose pin read value (LRCLK_OUT2/MP8)
#define MP9_READ        0xF539   //Multipurpose pin read value (LRCLK_OUT3/MP9)
#define MP10_READ       0xF53A   //Multipurpose pin read value (LRCLK_IN0/MP10) 
#define MP11_READ       0xF53B   //Multipurpose pin read value (LRCLK_IN1/MP11) 
#define MP12_READ       0xF53C   //Multipurpose pin read value (LRCLK_IN2/MP12) 
#define MP13_READ       0xF53D   //Multipurpose pin read value (LRCLK_IN3/MP13)

//Digital PDM Microphone Interface Registers
#define DMIC_CTRL0      0xF560      //Digital PDM microphone control (Channel 0 and Channel 1)
#define DMIC_CTRL1      0xF561      //Digital PDM microphone control (Channel 2 and Channel 3)

//Pin Drive Strength, Slew Rate, and Pull Configuration Registers
#define BCLK_IN0_PIN       0xF780       //BCLK input pin drive strength and slew rate (BCLK_IN0)
#define BCLK_IN1_PIN       0xF781       //BCLK input pin drive strength and slew rate (BCLK_IN1)
#define BCLK_IN2_PIN       0xF782       //BCLK input pin drive strength and slew rate (BCLK_IN2)
#define BCLK_IN3_PIN       0xF783       //BCLK input pin drive strength and slew rate (BCLK_IN3)
#define BCLK_OUT0_PIN      0xF784       //BCLK output pin drive strength and slew rate (BCLK_OUT0)
#define BCLK_OUT1_PIN      0xF785       //BCLK output pin drive strength and slew rate (BCLK_OUT1)
#define BCLK_OUT2_PIN      0xF786       //BCLK output pin drive strength and slew rate (BCLK_OUT2)
#define BCLK_OUT3_PIN      0xF787       //BCLK output pin drive strength and slew rate (BCLK_OUT3)
#define LRCLK_IN0_PIN      0xF788       //LRCLK input pin drive strength and slew rate (LRCLK_IN0)
#define LRCLK_IN1_PIN      0xF789       //LRCLK input pin drive strength and slew rate (LRCLK_IN1)
#define LRCLK_IN2_PIN      0xF78A       //LRCLK input pin drive strength and slew rate (LRCLK_IN2) 
#define LRCLK_IN3_PIN      0xF78B       //LRCLK input pin drive strength and slew rate (LRCLK_IN3)
#define LRCLK_OUT0_PIN     0xF78C        //LRCLK output pin drive strength and slew rate (LRCLK_OUT0)
#define LRCLK_OUT1_PIN     0xF78D        //LRCLK output pin drive strength and slew rate (LRCLK_OUT1)
#define LRCLK_OUT2_PIN     0xF78E        //LRCLK output pin drive strength and slew rate (LRCLK_OUT2)
#define LRCLK_OUT3_PIN     0xF78F        //LRCLK output pin drive strength and slew rate (LRCLK_OUT3)
#define SDATA_IN0_PIN      0xF790       //SDATA input pin drive strength and slew rate (SDATA_IN0)
#define SDATA_IN1_PIN      0xF791       //SDATA input pin drive strength and slew rate (SDATA_IN1)
#define SDATA_IN2_PIN      0xF792       //SDATA input pin drive strength and slew rate (SDATA_IN2)
#define SDATA_IN3_PIN      0xF793       //SDATA input pin drive strength and slew rate (SDATA_IN3)
#define SDATA_OUT0_PIN     0xF794        //SDATA output pin drive strength and slew rate (SDATA_OUT0)
#define SDATA_OUT1_PIN     0xF795        //SDATA output pin drive strength and slew rate (SDATA_OUT1)
#define SDATA_OUT2_PIN     0xF796        //SDATA output pin drive strength and slew rate (SDATA_OUT2)
#define SDATA_OUT3_PIN     0xF797        //SDATA output pin drive strength and slew rate (SDATA_OUT3)
#define SPDIF_TX_PIN       0xF798          //S/PDIF transmitter pin drive strength and slew rate 
#define SCLK_SCL_PIN       0xF799          //SCLK/SCL pin drive strength and slew rate 
#define MISO_SDA_PIN       0xF79A          //MISO/SDA pin drive strength and slew rate
#define SS_PIN SS/ADDR0    0xF79B          //pin drive strength and slew rate
#define MOSI_ADDR1_PIN     0xF79C          //MOSI/ADDR1 pin drive strength and slew rate 
#define SCLK_SCL_M_PIN     0xF79D          //SCL_M/SCLK_M/MP2 pin drive strength and slew rate 
#define MISO_SDA_M_PIN     0xF79E          //SDA_M/MISO_M/MP3 pin drive strength and slew rate 
#define SS_M_PIN SS_M/MP   0xF79F          //pin drive strength and slew rate 
#define MOSI_M_PIN         0xF7A0          //MOSI_M/MP1 pin drive strength and slew rate 
#define MP6_PIN MP6        0xF7A1          //pin drive strength and slew rate 
#define MP7_PIN            0xF7A2          //MP7 pin drive strength and slew rate 
#define CLKOUT_PIN         0xF7A3          //CLKOUT pin drive strength and slew rate


//DSP Core and Reliability Registers
#define HIBERNATE              0xF400   //Hibernate setting
#define START_PULSE            0xF401   //Start pulse selection
#define START_CORE             0xF402   //Instruction to start the core 0xF403 KILL_CORE Instruction to stop the core 
#define START_ADDRESS          0xF404   //Start address of the program 
#define CORE_STATUS            0xF405   //Core status
#define PANIC_CLEAR            0xF421   //Clear the panic manager 
#define PANIC_PARITY_MASK      0xF422   //Panic parity 
#define PANIC_SOFTWARE_MASK    0xF423   //Panic Mask 0 
#define PANIC_WD_MASK Panic    0xF424   //Mask 1 
#define PANIC_STACK_MASK       0xF425   //Panic Mask 2 
#define PANIC_LOOP_MASK        0xF426   //Panic Mask 3 
#define PANIC_FLAG Panic       0xF427   //flag
#define PANIC_CODE             0xF428   //Panic code 
#define EXECUTE_COUNT          0xF432   //Execute stage error program count
#define WATCHDOG_MAXCOUNT      0xF443   //Watchdog maximum count
#define WATCHDOG_PRESCALE      0xF444   //Watchdog prescale 0xF450 BLOCKINT_EN Enable block interrupts
#define BLOCKINT_VALUE         0xF451   //Value for the block interrupt counter
#define PROG_CNTR0             0xF460   //Program counter, Bits[23:16]
#define PROG_CNTR1             0xF461   //Program counter, Bits[15:0]
#define PROG_CNTR_CLEAR        0xF462   //Program counter clear 
#define PROG_CNTR_LENGTH0      0xF463   //Program counter length, Bits[23:16]
#define PROG_CNTR_LENGTH1      0xF464   //Program counter length, Bits[15:0]
#define PROG_CNTR_MAXLENGTH0   0xF465   //Program counter maximum length, Bits[23:16]

//Software Safeload Memory Address Defaults
#define data_SafeLoad[0]    0x6000   //Safeload Data Slot 0
#define data_SafeLoad[1]    0x6001   //Safeload Data Slot 1
#define data_SafeLoad[2]    0x6002   //Safeload Data Slot 2
#define data_SafeLoad[3]    0x6003   //Safeload Data Slot 3
#define data_SafeLoad[4]    0x6004   //Safeload Data Slot 4
#define address_SafeLoad    0x6005   //Target address for safeload transfer 
#define num_SafeLoad_Lower  0x6006   //Number of words to write/safeload trigger if on Page 1 lower memory 
#define num_SafeLoad_Upper  0x6007   //Number of words to write/safeload trigger if on Page 2 upper memory

//Soft Reset Register
#define SOFT_RESET 0xF890  //Software reset
#endif /*__ADAU1462_CFG_H_*/