/*============================================================================*/
/** Copyright (C) 2009-2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <GptIf.c>
 *  @brief      <>
 *
 *  <Compiler: don't care     MCU: don't care >
 *  @brief      <Macro and function declarations for ${tmpl} Module>
 *
 *  @author     <Your Name>
 *  @date       <2023-08-15 17:08:27>
 *
 *
 *
 *  May be changed by User [yes/no]: no
 */
/*============================================================================*/
/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/** <VERSION>   <DATE>      <AUTHOR>     <REVISION LOG> */
/*@{*/
#define GPTIF_C
/*@}*/
/*=======[I N C L U D E S]====================================================*/
/*=======[Includes]===========================================================*/
/*@{*/
#include "GptIf.h"


/* ----------------projectCfg ---------------- */
#include "Gpt.h"
/* ----------------projectCfg end---------------- */
/*@}*/
/*=======[Private define]=====================================================*/
/*@{*/
#define hw_gpt_chann GptConf_GptChannelConfiguration_GptChannelConfiguration_0
#define hw_get_remaining Gpt_GetTimeRemaining
#define hw_get_Elapsed Gpt_GetTimeElapsed
#define GPTIF_DELTA_CHANNEL 2U
/*@}*/
/*=======[Private types]======================================================*/
/*=======[Private function prototypes]========================================*/
/*=======[Private variables]==================================================*/
/*@{*/
static struct gptGeneralType
{
    volatile boolean _1ms;
    volatile uint32 _tick;
} gpt = {0, 0};

static struct gptRandomType
{
    boolean run;
    uint32 value;
    uint32 tempValue;
} random = {FALSE, 0, 0};

static struct gptDeltaTickType
{
    uint32 cur;
    uint32 last;
    uint32 delta;
} tick[GPTIF_DELTA_CHANNEL] = {{0, 0, 0}, {0, 0, 0}};
/*@}*/
/*=======[Private functions]==================================================*/
/******************************************************************************/
/*
 * @brief              [GptNotification_1ms description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [args                description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [NONE]
 */
/******************************************************************************/
void GptNotification_1ms(void)
{
    if (FALSE == gpt._1ms)
    {
        gpt._1ms = TRUE;
    }

    gpt._tick = gpt._tick + 1u;
}
/******************************************************************************/
/*
 * @brief              [GptIf_Init description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [NONE]
 */
/******************************************************************************/
void GptIf_Init(void)
{
    Gpt_Init(&GptChannelConfigSet);
    Gpt_StartTimer((Gpt_ChannelType)GptConf_GptChannelConfiguration_GptChannelConfiguration_0, 1000U);
    Gpt_EnableNotification(GptConf_GptChannelConfiguration_GptChannelConfiguration_0);

}

/******************************************************************************/
/*
 * @brief              [GptIf_Deinit description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [NONE]
 */
/******************************************************************************/
void GptIf_Deinit(void)
{
	Gpt_DeInit();
}
/******************************************************************************/
/*
 * @brief              [GptIf_GetFlag description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
boolean GptIf_GetFlag(void)
{
    boolean flag_1ms = FALSE;

    /*
     * gpt._1ms = (boolean)(READ_BIT(TIMER_CTRL_MODULE->SR, TIMER_CTRL_SR_TIF_Mask(hw_gpt_chann)));
     */
    if (TRUE == gpt._1ms)
    {
        flag_1ms = TRUE;
        gpt._1ms = FALSE;
    }

    /*
     * SET_BIT(TIMER_CTRL_MODULE->SR, TIMER_CTRL_SR_TIF_Mask(hw_gpt_chann));
     */
    return flag_1ms;
}
/******************************************************************************/
/*
 * @brief              [GptIf_GetTick description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
uint32 GptIf_GetTick(void)
{
    return gpt._tick;
}
/******************************************************************************/
/*
 * @brief              [GptIf_Random_Updata description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [NONE]
 */
/******************************************************************************/
void GptIf_Random_Updata(void)
{
    uint32 curValue;

    if (random.run == TRUE)
    {
        curValue = hw_get_remaining(hw_gpt_chann);

        if (random.tempValue > curValue)
        {
            curValue = random.tempValue - curValue;

            random.tempValue -= (curValue >> 3u);
        }
        else
        {
            curValue = curValue - random.tempValue;

            random.tempValue += (curValue >> 3u);
        }

        random.value = (random.value & 0x07u) + ((random.tempValue & (~0x07u)) << 3u);
    }
}
/******************************************************************************/
/*
 * @brief              [GptIf_Random_Get description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
uint32 GptIf_Random_Get(void)
{
    if (random.run == TRUE)
    {
        random.run = FALSE;
    }

    return random.value + hw_get_Elapsed(hw_gpt_chann);
}
/******************************************************************************/
/*
 * @brief              [GptIf_TickDeltaGet description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [index              description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
uint32 GptIf_TickDeltaGet(uint8 index)
{
    uint32 ret = 0;

    volatile uint32 TickResolution;
    volatile uint32 BaseTicks;
    if (GPTIF_DELTA_CHANNEL > index)
    {
#if 0
        TickResolution = Mcal_DelayTickResolution();
        BaseTicks = Mcal_DelayGetTick();
        tick[index].cur = BaseTicks;
#else
        tick[index].cur = GptIf_GetTick();
#endif
        tick[index].delta = tick[index].cur - tick[index].last;
        tick[index].last = tick[index].cur;
#if 0
        tick[index].delta *=TickResolution;
        tick[index].delta /=1000000UL;
#endif
        ret = tick[index].delta;
    }

    return ret;
}


/*=======[E N D   O F   F I L E]==============================================*/


