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
 * @file  DmaAL.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Can Driver.
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "Dma_Helper.h"
#include "Mcu_Soc.h"
/* Version and Check Begin */
/* Version Info Begin */


/* Version Info End */

/* Version Check Begin */


/*########################Global variables########################*/

/* Static function */
static Std_ReturnType Dma_FindAdcModuleConfigParams(uint8 hwUnitId, Dma_SubIdEnumType subId,
        Dma_InsConfigType *dmaConfig);
static Std_ReturnType Dma_FindIcuModuleConfigParams(uint8 hwUnitId, Dma_SubIdEnumType subId,
        Dma_InsConfigType *dmaConfig);
static Std_ReturnType Dma_FindPwmModuleConfigParams(uint8 hwUnitId, Dma_SubIdEnumType subId,
        Dma_InsConfigType *dmaConfig);
static Std_ReturnType Dma_FindSpiModuleConfigParams(uint8 hwUnitId, Dma_SubIdEnumType subId,
        Dma_InsConfigType *dmaConfig);
static Std_ReturnType Dma_FindXSpiModuleConfigParams(uint8 hwUnitId, Dma_SubIdEnumType subId,
        Dma_InsConfigType *dmaConfig);

/**
 * @brief Dma find Adc module configuration parameters.
 * @param hwUnitId, subId, *dmaConfig.
 * @return errorId.
 */
static Std_ReturnType Dma_FindAdcModuleConfigParams(uint8 hwUnitId, Dma_SubIdEnumType subId,
        Dma_InsConfigType *dmaConfig)
{
    Std_ReturnType errorId = E_OK;
    uint8 index = 0U;
    uint8 coreId = 0xFFU;

    /* #10 Check the Xspi hwUnitId parameter */
    if (hwUnitId > DMA_ADC_MAX_HWUNIT_NUMBER) {
        /* #20 hwUnitId out of range */
        errorId = DMA_E_PARAM_HWUNIT_ID;
    } else {
        coreId = Mcu_GetCoreID();

        /* #30 Find dma configuration parameters */
        /*PRQA S 2877,2880,2994,2996 6*/
        for (index = 0U; index < DMA_ADC_INSTANCE_NUMBER; index++) {
            if ((hwUnitId == Dma_AdcConfigTable[index].AdcControllerId)
                && (coreId == Dma_AdcConfigTable[index].CoreId)) {
                /* #40 Set errorId to E_OK, due to multi core it may be incorrectly set  */
                errorId = E_OK;

                if (subId == DMA_ADC_FIFO0) {
                    if (NULL_PTR == Dma_AdcConfigTable[index].Adc_Fifo.Controller) {
                        errorId = DMA_E_CONFIG_POINTER;
                    } else {
                        (*dmaConfig) = Dma_AdcConfigTable[index].Adc_Fifo;
                    }
                } else if (subId == DMA_ADC_FIFO1) {
                    if (NULL_PTR == Dma_AdcConfigTable[index].Adc_Fifo.Controller) {
                        errorId = DMA_E_CONFIG_POINTER;
                    } else {
                        (*dmaConfig) = Dma_AdcConfigTable[index].Adc_Fifo;
                    }
                } else if (subId == DMA_ADC_FIFO2) {
                    if (NULL_PTR == Dma_AdcConfigTable[index].Adc_Fifo.Controller) {
                        errorId = DMA_E_CONFIG_POINTER;
                    } else {
                        (*dmaConfig) = Dma_AdcConfigTable[index].Adc_Fifo;
                    }
                } else if (subId == DMA_ADC_FIFO3) {
                    if (NULL_PTR == Dma_AdcConfigTable[index].Adc_Fifo.Controller) {
                        errorId = DMA_E_CONFIG_POINTER;
                    } else {
                        (*dmaConfig) = Dma_AdcConfigTable[index].Adc_Fifo;
                    }
                } else {
                    /* #40 subId is not valid */
                    errorId = DMA_E_PARAM_SUB_ID;
                }

                break;
            } else {
                /* #60 Core id is not valid */
                errorId = DMA_E_CORE_ID;
            }
        }
    }

    return errorId;
}
/**
 * @brief Dma find icu module configuration parameters.
 * @param hwUnitId, subId, *dmaConfig.
 * @return errorId.
 */
static Std_ReturnType Dma_FindIcuModuleConfigParams(uint8 hwUnitId, Dma_SubIdEnumType subId,
        Dma_InsConfigType *dmaConfig)
{
    Std_ReturnType errorId = E_OK;
    uint8 index = 0U;
    uint8 coreId = 0xFFU;

    /* #10 Check the icu hwUnitId parameter */
    if (hwUnitId > DMA_ICU_MAX_HWUNIT_NUMBER) {
        /* #20 hwUnitId out of range */
        errorId = DMA_E_PARAM_HWUNIT_ID;
    } else {
        coreId = Mcu_GetCoreID();

        /* #30 Find dma configuration parameters */
        /*PRQA S 2877 6*/
        for (index = 0U; index < DMA_ICU_INSTANCE_NUMBER; index++) {
            if ((hwUnitId == Dma_IcuConfigTable[index].IcuControllerId)
                && (coreId == Dma_IcuConfigTable[index].CoreId)) {
                /* #40 Set errorId to E_OK, due to multi core it may be incorrectly set  */
                errorId = E_OK;

                if (subId == DMA_ICU_CPT_A) {
                    if (NULL_PTR == Dma_IcuConfigTable[index].Icu_Capture_A.Controller) {
                        errorId = DMA_E_CONFIG_POINTER;
                    } else {
                        (*dmaConfig) = Dma_IcuConfigTable[index].Icu_Capture_A;
                    }
                } else if (subId == DMA_ICU_CPT_B) {
                    if (NULL_PTR == Dma_IcuConfigTable[index].Icu_Capture_B.Controller) {
                        errorId = DMA_E_CONFIG_POINTER;
                    } else {
                        (*dmaConfig) = Dma_IcuConfigTable[index].Icu_Capture_B;
                    }
                } else if (subId == DMA_ICU_CPT_C) {
                    if (NULL_PTR == Dma_IcuConfigTable[index].Icu_Capture_C.Controller) {
                        errorId = DMA_E_CONFIG_POINTER;
                    } else {
                        (*dmaConfig) = Dma_IcuConfigTable[index].Icu_Capture_C;
                    }
                } else if (subId == DMA_ICU_CPT_D) {
                    if (NULL_PTR == Dma_IcuConfigTable[index].Icu_Capture_D.Controller) {
                        errorId = DMA_E_CONFIG_POINTER;
                    } else {
                        (*dmaConfig) = Dma_IcuConfigTable[index].Icu_Capture_D;
                    }
                } else {
                    /* #50 subId is not valid */
                    errorId = DMA_E_PARAM_SUB_ID;
                }

                break;
            } else {
                /* #60 Core id is not valid */
                errorId = DMA_E_CORE_ID;
            }
        }
    }

    return errorId;
}
/**
 * @brief Dma find pwm module configuration parameters.
 * @param hwUnitId, subId, *dmaConfig.
 * @return errorId.
 */
static Std_ReturnType Dma_FindPwmModuleConfigParams(uint8 hwUnitId, Dma_SubIdEnumType subId,
        Dma_InsConfigType *dmaConfig)
{
    Std_ReturnType errorId = E_OK;
    uint8 index = 0U;
    uint8 coreId = 0xFFU;

    /* #10 Check the pwm hwUnitId parameter */
    if (hwUnitId > DMA_PWM_MAX_HWUNIT_NUMBER) {
        /* #20 hwUnitId out of range */
        errorId = DMA_E_PARAM_HWUNIT_ID;
    } else {
        coreId = Mcu_GetCoreID();

        /* #30 Find dma configuration parameters */
        /*PRQA S 2877 6*/
        for (index = 0U; index < DMA_PWM_INSTANCE_NUMBER; index++) {
            if ((hwUnitId == Dma_PwmConfigTable[index].PwmControllerId)
                && (coreId == Dma_PwmConfigTable[index].CoreId)) {
                /* #40 Set errorId to E_OK, due to multi core it may be incorrectly set  */
                errorId = E_OK;

                if (subId == DMA_PWM_FIFO_A) {
                    if (NULL_PTR == Dma_PwmConfigTable[index].Pwm_FIFO_A.Controller) {
                        errorId = DMA_E_CONFIG_POINTER;
                    } else {
                        (*dmaConfig) = Dma_PwmConfigTable[index].Pwm_FIFO_A;
                    }
                } else if (subId == DMA_PWM_FIFO_B) {
                    if (NULL_PTR == Dma_PwmConfigTable[index].Pwm_FIFO_B.Controller) {
                        errorId = DMA_E_CONFIG_POINTER;
                    } else {
                        (*dmaConfig) = Dma_PwmConfigTable[index].Pwm_FIFO_B;
                    }
                } else if (subId == DMA_PWM_FIFO_C) {
                    if (NULL_PTR == Dma_PwmConfigTable[index].Pwm_FIFO_C.Controller) {
                        errorId = DMA_E_CONFIG_POINTER;
                    } else {
                        (*dmaConfig) = Dma_PwmConfigTable[index].Pwm_FIFO_C;
                    }
                } else if (subId == DMA_PWM_FIFO_D) {
                    if (NULL_PTR == Dma_PwmConfigTable[index].Pwm_FIFO_D.Controller) {
                        errorId = DMA_E_CONFIG_POINTER;
                    } else {
                        (*dmaConfig) = Dma_PwmConfigTable[index].Pwm_FIFO_D;
                    }
                } else if (subId == DMA_PWM_CE) {
                    if (NULL_PTR == Dma_PwmConfigTable[index].Pwm_CE.Controller) {
                        errorId = DMA_E_CONFIG_POINTER;
                    } else {
                        (*dmaConfig) = Dma_PwmConfigTable[index].Pwm_CE;
                    }
                } else {
                    /* #50 subId is not valid */
                    errorId = DMA_E_PARAM_SUB_ID;
                }

                break;
            } else {
                /* #60 Core id is not valid */
                errorId = DMA_E_CORE_ID;
            }
        }
    }

    return errorId;
}
/**
 * @brief Dma find spi module configuration parameters.
 * @param hwUnitId, subId, *dmaConfig.
 * @return errorId.
 */
static Std_ReturnType Dma_FindSpiModuleConfigParams(uint8 hwUnitId, Dma_SubIdEnumType subId,
        Dma_InsConfigType *dmaConfig)
{
    Std_ReturnType errorId = E_OK;
    uint8 index = 0U;
    uint8 coreId = 0xFFU;

    /* #10 Check the spi hwUnitId parameter */
    if (hwUnitId > DMA_SPI_MAX_HWUNIT_NUMBER) {
        /* #20 hwUnitId out of range */
        errorId = DMA_E_PARAM_HWUNIT_ID;
    } else {
        coreId = Mcu_GetCoreID();

        /* #30 Find dma configuration parameters */
        /*PRQA S 2877 6*/
        for (index = 0U; index < DMA_SPI_INSTANCE_NUMBER; index++) {
            if ((hwUnitId == Dma_SpiConfigTable[index].SpiControllerId)
                && (coreId == Dma_SpiConfigTable[index].CoreId)) {
                /* #40 Set errorId to E_OK, due to multi core it may be incorrectly set  */
                errorId = E_OK;

                if (subId == DMA_SPI_TX) {
                    if (NULL_PTR == Dma_SpiConfigTable[index].Spi_Tx.Controller) {
                        errorId = DMA_E_CONFIG_POINTER;
                    } else {
                        (*dmaConfig) = Dma_SpiConfigTable[index].Spi_Tx;
                    }
                } else if (subId == DMA_SPI_RX) {
                    if (NULL_PTR == Dma_SpiConfigTable[index].Spi_Rx.Controller) {
                        errorId = DMA_E_CONFIG_POINTER;
                    } else {
                        (*dmaConfig) = Dma_SpiConfigTable[index].Spi_Rx;
                    }
                } else {
                    /* #50 subId is not valid */
                    errorId = DMA_E_PARAM_SUB_ID;
                }

                break;
            } else {
                /* #60 Core id is not valid */
                errorId = DMA_E_CORE_ID;
            }
        }
    }

    return errorId;
}
static Std_ReturnType Dma_FindXSpiModuleConfigParams(uint8 hwUnitId, Dma_SubIdEnumType subId,
        Dma_InsConfigType *dmaConfig)
{
    Std_ReturnType errorId = E_OK;
    uint8 index = 0U;
    uint8 coreId = 0xFFU;

    /* #10 Check the Xspi hwUnitId parameter */
    if (hwUnitId > DMA_XSPI_MAX_HWUNIT_NUMBER) {
        /* #20 hwUnitId out of range */
        errorId = DMA_E_PARAM_HWUNIT_ID;
    } else {
        coreId = Mcu_GetCoreID();

        /* #30 Find dma configuration parameters */
        for (index = 0U; index < DMA_XSPI_INSTANCE_NUMBER; index++) {
            if ((hwUnitId == Dma_XSpiConfigTable[index].XSpiControllerId)
                && (coreId == Dma_XSpiConfigTable[index].CoreId)) {
                /* #40 Set errorId to E_OK, due to multi core it may be incorrectly set  */
                errorId = E_OK;

                if (subId == DMA_XSPI_PORTA_RD) {
                    if (NULL_PTR == Dma_XSpiConfigTable[index].XSpi_PortA_Read.Controller) {
                        errorId = DMA_E_CONFIG_POINTER;
                    } else {
                        (*dmaConfig) = Dma_XSpiConfigTable[index].XSpi_PortA_Read;
                    }
                } else if (subId == DMA_XSPI_PORTA_WR) {
                    if (NULL_PTR == Dma_XSpiConfigTable[index].XSpi_PortA_Write.Controller) {
                        errorId = DMA_E_CONFIG_POINTER;
                    } else {
                        (*dmaConfig) = Dma_XSpiConfigTable[index].XSpi_PortA_Write;
                    }
                } else if (subId == DMA_XSPI_PORTB_RD) {
                    if (NULL_PTR == Dma_XSpiConfigTable[index].XSpi_PortB_Read.Controller) {
                        errorId = DMA_E_CONFIG_POINTER;
                    } else {
                        (*dmaConfig) = Dma_XSpiConfigTable[index].XSpi_PortB_Read;
                    }
                } else if (subId == DMA_XSPI_PORTB_WR) {
                    if (NULL_PTR == Dma_XSpiConfigTable[index].XSpi_PortB_Write.Controller) {
                        errorId = DMA_E_CONFIG_POINTER;
                    } else {
                        (*dmaConfig) = Dma_XSpiConfigTable[index].XSpi_PortB_Write;
                    }
                } else {
                    /* #50 subId is not valid */
                    errorId = DMA_E_PARAM_SUB_ID;
                }

                break;
            } else {
                /* #60 Core id is not valid */
                errorId = DMA_E_CORE_ID;
            }
        }
    }

    return errorId;
}
/**
 * @brief Dma get module configuration parameters.
 * @param hwUnitId, subId, moduleId, *dmaConfig.
 * @return errorId.
 */
Std_ReturnType Dma_GetConfigParams(uint8 hwUnitId, Dma_SubIdEnumType subId,
                                   Dma_ModuleEnumType moduleId, Dma_InsConfigType *dmaConfig)
{
    Std_ReturnType errorId = E_OK;

    /* #10 Check dmaConfig valid or not */
    if (NULL_PTR == dmaConfig) {
        /* #20 dmaConfig pointer is NOT valid */
        errorId = DMA_E_PARAM_POINTER;
    } else {
        /* #30 Get module configuration parameters */
        switch (moduleId) {
        case DMA_MODULE_ADC: {
            errorId = Dma_FindAdcModuleConfigParams(hwUnitId, subId, dmaConfig);
            break;
        }

        case DMA_MODULE_ETIMER: {
            /* #40 Find icu mconfiguration parameters */
            errorId = Dma_FindIcuModuleConfigParams(hwUnitId, subId, dmaConfig);
            break;
        }

        case DMA_MODULE_EPWM: {
            /* #50 Find pwm mconfiguration parameters */
            errorId = Dma_FindPwmModuleConfigParams(hwUnitId, subId, dmaConfig);
            break;
        }

        case DMA_MODULE_SPI: {
            /* #40 Find spi mconfiguration parameters */
            errorId = Dma_FindSpiModuleConfigParams(hwUnitId, subId, dmaConfig);
            break;
        }

        case DMA_MODULE_XSPI: {
            /* #50 Find Xspi mconfiguration parameters */
            errorId = Dma_FindXSpiModuleConfigParams(hwUnitId, subId, dmaConfig);
            break;
        }

        default: {
            /* #60 Module id is not valid */
            errorId = DMA_E_PARAM_MODULE_ID;
            break;
        }
        }
    }

    return errorId;
}

#ifdef __cplusplus
}
#endif
