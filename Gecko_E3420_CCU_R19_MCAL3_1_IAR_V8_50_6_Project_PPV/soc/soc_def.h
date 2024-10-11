/********************************************************
 *          Copyright(c) 2018   Semidrive               *
 ********************************************************/

#ifndef SOC_DEF_H
#define SOC_DEF_H

#include "Mcu_Modules.h"
#include "Mcu_Delay.h"

#define IRAM_INIT_TIMEOUT_us    10000u
#define SOC_TMR_CLK_SRC_SEL     2   /* 24MHz, safety.fsrefclk output */
#define SOC_TMR_CLK_DIV         23

#define SOC_us_TO_TICK(us)      (Mcu_UsToTicks(us))
#define SOC_TICK_TO_us(tick)    (tick)

#define IRAM_CTRL_DATA_INIT_OFF   0x80
#define BM_DATA_INIT_INIT   (0x01U << 0U)

#define SAFE_DIV(x) (x)
#define SEMPHORE_BIT_TTY    31

#define GICD_OFFSET (0x1000)
#define GICC_OFFSET (0x2000)

typedef Mcu_ModuleType  module_e;

#endif  /* SOC_DEF_H */
