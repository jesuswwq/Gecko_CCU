#ifndef _ADC_RTE_H_
#define _ADC_RTE_H_

// include adc file library
#include "AD_CD4067.h"
#include "stdint.h"
#include "Platform_Types.h"
#include "Adc_Types.h"
#include "IoExp_TCA6424A_Api.h"
#include "Adc.h"

#define buffersizeAdc0 3 // VCU
#define buffersizeAdc1 10  // MCU
#define buffersizeAdc2 5 // 扩展芯片
#define adsize_4067A 11
#define adsize_4067B 4
#define adsize_4067C 1
#define adsize_4067D 10 //移除掉4,5,6channel；
#define adsize_4067E 10

extern void Adc_rte_init(void);
extern void ADC2_ReadGroup2_4067(void);

extern void ADC2_ReadGroup0(void);
extern void ADC2_ReadGroup1(void);

//extern void TestAdcSample();

#endif