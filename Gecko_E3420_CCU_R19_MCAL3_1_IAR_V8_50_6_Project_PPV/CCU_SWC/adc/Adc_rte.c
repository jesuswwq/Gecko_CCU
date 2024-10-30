#include "Adc_rte.h"
#include "irq_num_e3_l.h"

static uint8 AD4067Achannel[adsize_4067A] = {1, 5, 6, 7, 8, 9, 10, 11, 13,14, 15}; 
static uint8 AD4067Bchannel[adsize_4067B] = {6, 12, 13, 14};
static uint8 AD4067Cchannel[adsize_4067C] = {6};
static uint8 AD4067Dchannel[adsize_4067D] = {0, 1, 2, 3, 7, 8, 6, 12 ,13, 5};
static uint8 AD4067Echannel[adsize_4067E] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
uint8 AD4067Ccount = 0;
uint8 AD4067Bcount = 0;
uint8 AD4067Acount = 0;
uint8 AD4067Dcount = 0;
uint8 AD4067Ecount = 0;
uint8 ADCSta_Error = 0;

uint32 AD4067Avalue[adsize_4067A] = {0};
uint32 AD4067Bvalue[adsize_4067B] = {0};
uint32 AD4067Cvalue[adsize_4067C] = {0};
uint32 AD4067Dvalue[adsize_4067D] = {0};
uint32 AD4067Evalue[adsize_4067E] = {0};

Adc_ValueGroupType adc2_group0_resultbuffer[buffersizeAdc0] = {0};
Adc_ValueGroupType adc2_group1_resultbuffer[buffersizeAdc1] = {0};
Adc_ValueGroupType adc2_group2_resultbuffer[buffersizeAdc2] = {0};


Adc_ValueGroupType adc2_group0_tmpbuffer[buffersizeAdc0] = {0};
Adc_ValueGroupType adc2_group1_tmpbuffer[buffersizeAdc1] = {0};
Adc_ValueGroupType adc2_group2_tmpbuffer[buffersizeAdc2] = {0};
#pragma default_function_attributes = @".iram_func"
static void ADGroup2_Select_Channel(void)
{	  
    Set_AD_Channel(0, AD4067Achannel[AD4067Acount]);
    Set_AD_Channel(1, AD4067Bchannel[AD4067Bcount]);
    Set_AD_Channel(2, AD4067Cchannel[AD4067Ccount]);
    Set_AD_Channel(3, AD4067Dchannel[AD4067Dcount]);
    Set_AD_Channel(4, AD4067Echannel[AD4067Ecount]);
}
void Adc_rte_init(void)
{
	Adc_SetupResultBuffer(0, adc2_group0_tmpbuffer);
	Adc_SetupResultBuffer(1, adc2_group1_tmpbuffer);
	Adc_SetupResultBuffer(2, adc2_group2_tmpbuffer);
  
}
void Adc_InitGroupsStatus_error(uint8 Group)
{
        Adc_AllGroupInfo[Group].groupStatus = ADC_IDLE;
        Adc_AllGroupInfo[Group].groupValueStatus = ADC_STREAM_COMPLETED;
        Adc_AllGroupInfo[Group].groupConvFinishIndex = 0U;
  
}


void ADC2_ReadGroup2_4067(void)
{
//    uint16 times = 0;
        SuspendAllInterrupts();
        irq_enable(SADC2_O_SADC_INTR_NUM);

    Adc_StartGroupConversion(2);

        ResumeAllInterrupts();

        while(ADC_STREAM_COMPLETED != Adc_GetGroupStatus(2));
        Adc_ReadGroup(2, adc2_group2_resultbuffer);  
        if (AD4067Acount < (adsize_4067A - 1))
                {
                        AD4067Avalue[AD4067Acount] = adc2_group2_resultbuffer[0];
                        AD4067Acount++;
                 }
                else
                {
                        AD4067Avalue[AD4067Acount] = adc2_group2_resultbuffer[0];
                        AD4067Acount = 0;
                }

                //B
                if (AD4067Bcount < (adsize_4067B - 1))
                {
                        AD4067Bvalue[AD4067Bcount] = adc2_group2_resultbuffer[1];
                        AD4067Bcount++;
                }
                else
                {
                        AD4067Bvalue[AD4067Bcount] = adc2_group2_resultbuffer[1];
                        AD4067Bcount = 0;
                }

                //C
                AD4067Cvalue[0] = adc2_group2_resultbuffer[2];

                
                // D      
                if (AD4067Dcount < (adsize_4067D - 1))
                {
                        AD4067Dvalue[AD4067Dcount] = adc2_group2_resultbuffer[3];
                        AD4067Dcount++;
                }
                else
                {
                        AD4067Dvalue[AD4067Dcount] = adc2_group2_resultbuffer[3];
                        AD4067Dcount = 0;
                }

                //E
                if (AD4067Ecount < (adsize_4067E - 1))
                {
                        AD4067Evalue[AD4067Ecount] = adc2_group2_resultbuffer[4];
                        AD4067Ecount++;
                }
                else
                {
                        AD4067Evalue[AD4067Ecount] = adc2_group2_resultbuffer[4];
                        AD4067Ecount = 0;
                }

                ADGroup2_Select_Channel();
}


void ADC2_ReadGroup0(void)
{
        SuspendAllInterrupts();
        irq_enable(SADC2_O_SADC_INTR_NUM);

	Adc_StartGroupConversion(0);
        
        ResumeAllInterrupts();
        
        while(ADC_STREAM_COMPLETED != Adc_GetGroupStatus(0));
        Adc_ReadGroup(0, adc2_group0_resultbuffer);
}

void ADC2_ReadGroup1(void)
{
        SuspendAllInterrupts();
        irq_enable(SADC2_O_SADC_INTR_NUM);

	Adc_StartGroupConversion(1);

        ResumeAllInterrupts();
        
        while(ADC_STREAM_COMPLETED != Adc_GetGroupStatus(1));
        Adc_ReadGroup(1, adc2_group1_resultbuffer);
}

#ifdef TESTCODE
uint16 TestAdcGroup1[buffersizeAdc1] = {0};
void TestAdcSample()
{
	for (int i = 0; i < buffersizeAdc1; i++)
	{
		TestAdcGroup1[i] = ((float)adc2_group0_resultbuffer[i]) / 4095.0 * 3300.0 * 6.0 / 5.0;
	}
}
#endif
#pragma default_function_attributes =
