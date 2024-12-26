/*
 * SEMIDRIVE Copyright Statement
 * Copyright (c) SEMIDRIVE. All rights reserved
 *
 * This software and all rights therein are owned by SEMIDRIVE, and are
 * protected by copyright law and other relevant laws, regulations and
 * protection. Without SEMIDRIVE's prior written consent and/or related rights,
 * please do not use this software or any potion thereof in any form or by any
 * means. You may not reproduce, modify or distribute this software except in
 * compliance with the License. Unless required by applicable law or agreed to
 * in writing, software distributed under the License is distributed on
 * an "AS IS" basis, WITHOUT WARRANTIES OF ANY KIND, either express or implied.
 *
 * You should have received a copy of the License along with this program.
 * If not, see <http://www.semidrive.com/licenses/>.
 */

/**
 * @file  IrqM_PBCfg.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL IrqM
 * @date 2024-07-11 12:03:10
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "IrqM_Cfg.h"
#include "Mcu.h"
#include "Gpt_Types_E3.h"
#include "Gpt_Irq_E3.h"
#include "Wdg_Irq.h"
#include "Can.h"

#include "irq_num.h"
#include "irq.h"

#define IRQM_START_SEC_CODE
#include "IrqM_MemMap.h"





void IrqM_Init(void)
{
//Xtrg generating code
    //Gpt generating code
                                
    if(Mcu_GetCoreID()==CPU_ID_SF)
    {
        irq_attach(BTM1_O_BTM_INTR_NUM, Gpt_Irq1_Handle, NULL_PTR);
        irq_set_priority(BTM1_O_BTM_INTR_NUM,  10);
        irq_enable(BTM1_O_BTM_INTR_NUM);
    }
                                                            

//Icu generating code
                                
//Sent generating code
                                
//Pwm generating code
                                                                
//Adc generating code
                        

//Wdg generating code
                        
    if(Mcu_GetCoreID()==CPU_ID_SF)
    {
        irq_attach(WDT1_WDT_INTR_NUM, Wdg_Isr_Instance1, NULL_PTR);
        irq_set_priority(WDT1_WDT_INTR_NUM, 10);
        irq_enable(WDT1_WDT_INTR_NUM);
    }
                                                                    
//Spi generating code
                                                                

 //ETH Generating code
                

//Lin generating code
                                                                                                                                
//Can generating code
                                                                                    
    if (Mcu_GetCoreID()==CPU_ID_SF)
    {
        irq_attach(150, Can_Controller0IrqHandler, NULL_PTR);
        irq_set_priority(150, 10);
        irq_enable(150);
    }
                                            
    if (Mcu_GetCoreID()==CPU_ID_SF)
    {
        irq_attach(151, Can_Controller1IrqHandler, NULL_PTR);
        irq_set_priority(151, 10);
        irq_enable(151);
    }
                                                                                                                                        
}

void IrqM_DeInit(void)
{
    if(Mcu_GetCoreID()==CPU_ID_SF)
    {
        irq_disable(BTM1_O_BTM_INTR_NUM);
    }
                        
    if(Mcu_GetCoreID()==CPU_ID_SF)
    {
        irq_disable(WDT1_WDT_INTR_NUM);
    }
    
    if (Mcu_GetCoreID()==CPU_ID_SF)
    {
        irq_disable(150);
    }
                                            
    if (Mcu_GetCoreID()==CPU_ID_SF)
    {
        irq_disable(151);
    }
}


#define IRQM_STOP_SEC_CODE
#include "IrqM_MemMap.h"

#ifdef __cplusplus
}
#endif
