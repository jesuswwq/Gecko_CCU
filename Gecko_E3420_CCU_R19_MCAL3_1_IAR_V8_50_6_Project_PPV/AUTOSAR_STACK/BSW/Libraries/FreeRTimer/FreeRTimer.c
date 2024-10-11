
/******************************* references ************************************/
#include "FreeRTimer.h"
#include "Os_Processor.h"
#include "Os.h"
/****************************** implementations ********************************/
uint32 Frt_ReadOutMS(void)
{
    uint32 OSCurMs;
    CoreIdType coreId;
    coreId = Os_ArchGetCoreID();
    switch (coreId)
    {
#if (TRUE == CFG_CORE0_AUTOSAROS_ENABLE)
    case OS_CORE_ID_0: {
        (void)GetCounterValue(SystemTimer_Core0, &OSCurMs);
        /*tick to ms*/
        OSCurMs = OS_TICKS2MS_SystemTimer_Core0(OSCurMs);
        break;
    }
#endif
#if (TRUE == CFG_CORE1_AUTOSAROS_ENABLE)
    case OS_CORE_ID_1: {
        (void)GetCounterValue(SystemTimer_Core1, &OSCurMs);
        OSCurMs = OS_TICKS2MS_SystemTimer_Core1(OSCurMs);
        break;
    }
#endif
#if (TRUE == CFG_CORE2_AUTOSAROS_ENABLE)
    case OS_CORE_ID_2: {
        (void)GetCounterValue(SystemTimer_Core2, &OSCurMs);
        OSCurMs = OS_TICKS2MS_SystemTimer_Core2(OSCurMs);
        break;
    }
#endif
    default:
        break;
    }

    return (OSCurMs);
}

uint32 Frt_ReadOutUS(void)
{
    uint32 OSCurUs;
    CoreIdType coreId;
    coreId = Os_ArchGetCoreID();
    switch (coreId)
    {
#if (TRUE == CFG_CORE0_AUTOSAROS_ENABLE)
    case OS_CORE_ID_0: {
        (void)GetCounterValue(SystemTimer_Core0, &OSCurUs);
        /*tick to us*/
        OSCurUs = OS_TICKS2US_SystemTimer_Core0(OSCurUs);
        break;
    }
#endif
#if (TRUE == CFG_CORE1_AUTOSAROS_ENABLE)
    case OS_CORE_ID_1: {
        (void)GetCounterValue(SystemTimer_Core1, &OSCurUs);
        OSCurUs = OS_TICKS2US_SystemTimer_Core1(OSCurUs);
        break;
    }
#endif
#if (TRUE == CFG_CORE2_AUTOSAROS_ENABLE)
    case OS_CORE_ID_2: {
        (void)GetCounterValue(SystemTimer_Core2, &OSCurUs);
        OSCurUs = OS_TICKS2US_SystemTimer_Core2(OSCurUs);
        break;
    }
#endif
    default:
        break;
    }

    return (OSCurUs);
}

uint32 Frt_CalculateElapsedMS(uint32 OldCurMs)
{
    uint32 ElapsedMs;
    CoreIdType coreId;
    coreId = Os_ArchGetCoreID();
    switch (coreId)
    {
#if (TRUE == CFG_CORE0_AUTOSAROS_ENABLE)
    case OS_CORE_ID_0: {
        /*ms to tick*/
        OldCurMs = OS_MS2TICKS_SystemTimer_Core0(OldCurMs);
        (void)GetElapsedValue(SystemTimer_Core0, &OldCurMs, &ElapsedMs);
        ElapsedMs = OS_TICKS2MS_SystemTimer_Core0(ElapsedMs);
        break;
    }
#endif
#if (TRUE == CFG_CORE1_AUTOSAROS_ENABLE)
    case OS_CORE_ID_1: {
        OldCurMs = OS_MS2TICKS_SystemTimer_Core1(OldCurMs);
        (void)GetElapsedValue(SystemTimer_Core1, &OldCurMs, &ElapsedMs);
        ElapsedMs = OS_TICKS2MS_SystemTimer_Core1(ElapsedMs);
        break;
    }
#endif
#if (TRUE == CFG_CORE2_AUTOSAROS_ENABLE)
    case OS_CORE_ID_2: {
        OldCurMs = OS_MS2TICKS_SystemTimer_Core2(OldCurMs);
        (void)GetElapsedValue(SystemTimer_Core2, &OldCurMs, &ElapsedMs);
        ElapsedMs = OS_TICKS2MS_SystemTimer_Core2(ElapsedMs);
        break;
    }
#endif
    default:
        break;
    }

    return (ElapsedMs);
}

uint32 Frt_CalculateElapsedUS(uint32 OldCurUs)
{
    uint32 ElapsedUs;
    CoreIdType coreId;
    coreId = Os_ArchGetCoreID();
    switch (coreId)
    {
#if (TRUE == CFG_CORE0_AUTOSAROS_ENABLE)
    case OS_CORE_ID_0: {
        /*us to tick*/
        OldCurUs = OS_US2TICKS_SystemTimer_Core0(OldCurUs);
        (void)GetElapsedValue(SystemTimer_Core0, &OldCurUs, &ElapsedUs);
        ElapsedUs = OS_TICKS2US_SystemTimer_Core0(ElapsedUs);
        break;
    }
#endif
#if (TRUE == CFG_CORE1_AUTOSAROS_ENABLE)
    case OS_CORE_ID_1: {
        OldCurUs = OS_US2TICKS_SystemTimer_Core1(OldCurUs);
        (void)GetElapsedValue(SystemTimer_Core1, &OldCurUs, &ElapsedUs);
        ElapsedUs = OS_TICKS2US_SystemTimer_Core1(ElapsedUs);
        break;
    }
#endif
#if (TRUE == CFG_CORE2_AUTOSAROS_ENABLE)
    case OS_CORE_ID_2: {
        OldCurUs = OS_US2TICKS_SystemTimer_Core2(OldCurUs);
        (void)GetElapsedValue(SystemTimer_Core2, &OldCurUs, &ElapsedUs);
        ElapsedUs = OS_TICKS2US_SystemTimer_Core2(ElapsedUs);
        break;
    }
#endif
    default:
        break;
    }

    return (ElapsedUs);
}
