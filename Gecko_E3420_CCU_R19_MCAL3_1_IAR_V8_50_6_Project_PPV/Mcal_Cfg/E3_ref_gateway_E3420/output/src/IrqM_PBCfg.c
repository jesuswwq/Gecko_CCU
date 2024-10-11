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
 * @date 2024-03-08 16:29:00
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "IrqM_Cfg.h"
#include "Mcu.h"
#include "Icu_Irq.h"
#include "Icu_Types.h"
#include "Sent_Irq_E3.h"
#include "Sent_Types_E3.h"
#include "Gpt_Types.h"
#include "Gpt_Irq.h"
#include "Pwm_Irq.h"
#include "Adc_irq.h"
#include "Can.h"
#include "Lin_Irq.h"
#include "dwmac.h"
#include "Spi_Irq.h"

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
                                                    
    if(Mcu_GetCoreID()==CPU_ID_SF)
    {
        irq_attach(BTM2_O_BTM_INTR_NUM, Gpt_Irq2_Handle, NULL_PTR);
        irq_set_priority(BTM2_O_BTM_INTR_NUM,  10);
        irq_enable(BTM2_O_BTM_INTR_NUM);
    }
                                                            
    if(Mcu_GetCoreID()==CPU_ID_SF)
    {
        irq_attach(BTM4_O_BTM_INTR_NUM, Gpt_Irq4_Handle, NULL_PTR);
        irq_set_priority(BTM4_O_BTM_INTR_NUM,  10);
        irq_enable(BTM4_O_BTM_INTR_NUM);
    }
                                                    
    if(Mcu_GetCoreID()==CPU_ID_SF)
    {
        irq_attach(BTM5_O_BTM_INTR_NUM, Gpt_Irq5_Handle, NULL_PTR);
        irq_set_priority(BTM5_O_BTM_INTR_NUM,  10);
        irq_enable(BTM5_O_BTM_INTR_NUM);
    }
                                                    
    if(Mcu_GetCoreID()==CPU_ID_SF)
    {
        irq_attach(BTM6_O_BTM_INTR_NUM, Gpt_Irq6_Handle, NULL_PTR);
        irq_set_priority(BTM6_O_BTM_INTR_NUM,  10);
        irq_enable(BTM6_O_BTM_INTR_NUM);
    }
    
    

//Icu generating code
                                            
    if(Mcu_GetCoreID()==CPU_ID_SF)
    {
        irq_attach(ETMR1_CHN_A_INTR_NUM, Icu_Irq1_Handle, NULL_PTR);
        irq_set_priority(ETMR1_CHN_A_INTR_NUM, 10);
        irq_enable(ETMR1_CHN_A_INTR_NUM);
    }
                                                            
    if(Mcu_GetCoreID()==CPU_ID_SF)
    {
        irq_attach(ETMR3_CHN_A_INTR_NUM, Icu_Irq3_Handle, NULL_PTR);
        irq_set_priority(ETMR3_CHN_A_INTR_NUM, 10);
        irq_enable(ETMR3_CHN_A_INTR_NUM);
    }
                
//Sent generating code
                                                    
    if(Mcu_GetCoreID()==CPU_ID_SF)
    {
        irq_attach(ETMR2_CHN_A_INTR_NUM, Sent_Irq2_Handle, NULL_PTR);
        irq_set_priority(ETMR2_CHN_A_INTR_NUM, 10);
        irq_enable(ETMR2_CHN_A_INTR_NUM);
    }
                        
//Pwm generating code
                        
    if(Mcu_GetCoreID()==CPU_ID_SF)
    {
        irq_attach(EPWM1_CHN_A_INTR_NUM, Pwm_Irq1Handler, NULL_PTR);
        irq_attach(EPWM1_CNT_OVF_INTR_NUM, Pwm_Irq1Handler, NULL_PTR);
        irq_set_priority(EPWM1_CHN_A_INTR_NUM, 10);
        irq_set_priority(EPWM1_CNT_OVF_INTR_NUM, 10);
        irq_enable(EPWM1_CHN_A_INTR_NUM);
        irq_enable(EPWM1_CNT_OVF_INTR_NUM);
    }
                                                            
    if(Mcu_GetCoreID()==CPU_ID_SF)
    {
        irq_attach(EPWM2_CHN_A_INTR_NUM, Pwm_Irq2Handler, NULL_PTR);
        irq_attach(EPWM2_CNT_OVF_INTR_NUM, Pwm_Irq2Handler, NULL_PTR);
        irq_set_priority(EPWM2_CHN_A_INTR_NUM, 10);
        irq_set_priority(EPWM2_CNT_OVF_INTR_NUM, 10);
        irq_enable(EPWM2_CHN_A_INTR_NUM);
        irq_enable(EPWM2_CNT_OVF_INTR_NUM);
    }
                                                                                    
    if(Mcu_GetCoreID()==CPU_ID_SF)
    {
        irq_attach(EPWM4_CHN_A_INTR_NUM, Pwm_Irq4Handler, NULL_PTR);
        irq_attach(EPWM4_CNT_OVF_INTR_NUM, Pwm_Irq4Handler, NULL_PTR);
        irq_set_priority(EPWM4_CHN_A_INTR_NUM, 10);
        irq_set_priority(EPWM4_CNT_OVF_INTR_NUM, 10);
        irq_enable(EPWM4_CHN_A_INTR_NUM);
        irq_enable(EPWM4_CNT_OVF_INTR_NUM);
    }
                                                            
//Adc generating code
                                                    
    if(Mcu_GetCoreID()==CPU_ID_SF)
    {
        irq_attach(SADC2_O_SADC_INTR_NUM, Adc_EndGroupConvUnit2, NULL_PTR);
        irq_set_priority(SADC2_O_SADC_INTR_NUM, 10);
        irq_enable(SADC2_O_SADC_INTR_NUM);
    }
                

//Wdg generating code
                                                        
//Spi generating code
                                                                        
    if(Mcu_GetCoreID()==CPU_ID_SX0)
    {
        irq_attach(SPI1_SPI_INTR_NUM, Spi1_IrqHandler, NULL_PTR);
        irq_set_priority(SPI1_SPI_INTR_NUM, 10);
        irq_enable(SPI1_SPI_INTR_NUM);
    }
                                                            
    if(Mcu_GetCoreID()==CPU_ID_SF)
    {
        irq_attach(SPI2_SPI_INTR_NUM, Spi2_IrqHandler, NULL_PTR);
        irq_set_priority(SPI2_SPI_INTR_NUM, 10);
        irq_enable(SPI2_SPI_INTR_NUM);
    }
                                                                                            
    if(Mcu_GetCoreID()==CPU_ID_SF)
    {
        irq_attach(SPI3_SPI_INTR_NUM, Spi3_IrqHandler, NULL_PTR);
        irq_set_priority(SPI3_SPI_INTR_NUM, 10);
        irq_enable(SPI3_SPI_INTR_NUM);
    }
                                                                                                            
    if(Mcu_GetCoreID()==CPU_ID_SX0)
    {
        irq_attach(SPI4_SPI_INTR_NUM, Spi4_IrqHandler, NULL_PTR);
        irq_set_priority(SPI4_SPI_INTR_NUM, 10);
        irq_enable(SPI4_SPI_INTR_NUM);
    }
                                            
    if(Mcu_GetCoreID()==CPU_ID_SF)
    {
        irq_attach(SPI5_SPI_INTR_NUM, Spi5_IrqHandler, NULL_PTR);
        irq_set_priority(SPI5_SPI_INTR_NUM, 10);
        irq_enable(SPI5_SPI_INTR_NUM);
    }
                                                                                                                                
    if(Mcu_GetCoreID()==CPU_ID_SF)
    {
        irq_attach(SPI6_SPI_INTR_NUM, Spi6_IrqHandler, NULL_PTR);
        irq_set_priority(SPI6_SPI_INTR_NUM, 10);
        irq_enable(SPI6_SPI_INTR_NUM);
    }
                                        
    if(Mcu_GetCoreID()==CPU_ID_SF)
    {
        irq_attach(SPI7_SPI_INTR_NUM, Spi7_IrqHandler, NULL_PTR);
        irq_set_priority(SPI7_SPI_INTR_NUM, 10);
        irq_enable(SPI7_SPI_INTR_NUM);
    }
                                                                                                                                
    if(Mcu_GetCoreID()==CPU_ID_SF)
    {
        irq_attach(SPI8_SPI_INTR_NUM, Spi8_IrqHandler, NULL_PTR);
        irq_set_priority(SPI8_SPI_INTR_NUM, 10);
        irq_enable(SPI8_SPI_INTR_NUM);
    }
        

 //ETH Generating code
                                            
    if(Mcu_GetCoreID()==CPU_ID_SF)
    {
        irq_attach(ETH1_SBD_INTR_NUM, eth0_handle, NULL_PTR);
        irq_set_priority(ETH1_SBD_INTR_NUM, 10);
        irq_enable(ETH1_SBD_INTR_NUM);
    }
                                                    
    if(Mcu_GetCoreID()==CPU_ID_SF)
    {
        irq_attach(ETH2_SBD_INTR_NUM, eth1_handle, NULL_PTR);
        irq_set_priority(ETH2_SBD_INTR_NUM, 10);
        irq_enable(ETH2_SBD_INTR_NUM);
    }
        

//Lin generating code
                                                            
    if(Mcu_GetCoreID()==CPU_ID_SF)
    {
        irq_attach(UART3_INTR_NUM, Lin_Irq3_Handle, NULL_PTR);
        irq_set_priority(UART3_INTR_NUM, 10);
        irq_enable(UART3_INTR_NUM);
    }
                                                                                                            
    if(Mcu_GetCoreID()==CPU_ID_SF)
    {
        irq_attach(UART11_INTR_NUM, Lin_Irq11_Handle, NULL_PTR);
        irq_set_priority(UART11_INTR_NUM, 10);
        irq_enable(UART11_INTR_NUM);
    }
                                                                    
    if(Mcu_GetCoreID()==CPU_ID_SF)
    {
        irq_attach(UART14_INTR_NUM, Lin_Irq14_Handle, NULL_PTR);
        irq_set_priority(UART14_INTR_NUM, 10);
        irq_enable(UART14_INTR_NUM);
    }
                        
//Can generating code
                                                            
    if (Mcu_GetCoreID()==CPU_ID_SF)
    {
        irq_attach(146, Can_Controller0IrqHandler, NULL_PTR);
        irq_set_priority(146, 10);
        irq_enable(146);
    }
                                                    
    if (Mcu_GetCoreID()==CPU_ID_SF)
    {
        irq_attach(147, Can_Controller1IrqHandler, NULL_PTR);
        irq_set_priority(147, 10);
        irq_enable(147);
    }
                                                    
    if (Mcu_GetCoreID()==CPU_ID_SF)
    {
        irq_attach(148, Can_Controller2IrqHandler, NULL_PTR);
        irq_set_priority(148, 10);
        irq_enable(148);
    }
                                                    
    if (Mcu_GetCoreID()==CPU_ID_SF)
    {
        irq_attach(149, Can_Controller3IrqHandler, NULL_PTR);
        irq_set_priority(149, 10);
        irq_enable(149);
    }
                                                    
    if (Mcu_GetCoreID()==CPU_ID_SF)
    {
        irq_attach(150, Can_Controller4IrqHandler, NULL_PTR);
        irq_set_priority(150, 10);
        irq_enable(150);
    }
                                                    
    if (Mcu_GetCoreID()==CPU_ID_SF)
    {
        irq_attach(151, Can_Controller5IrqHandler, NULL_PTR);
        irq_set_priority(151, 10);
        irq_enable(151);
    }
                                                                                                                                        

}

#define IRQM_STOP_SEC_CODE
#include "IrqM_MemMap.h"

#ifdef __cplusplus
}
#endif
