/********************************************************
 *          Copyright(c) 2018   Semidrive               *
 *******************************************************/

/**
 * @file    exception.c
 * @brief   exception handlers
 */

#include "debug.h"

#if defined(CFG_FUSAPKG_EN)
#include "FuncSafetyPkg.h"
#endif

typedef struct {
    uint32 r0;
    uint32 r1;
    uint32 r2;
    uint32 r3;
    uint32 r4;
    uint32 r5;
    uint32 r6;
    uint32 r7;
    uint32 r8;
    uint32 r9;
    uint32 r10;
    uint32 r11;
    uint32 r12;
    uint32 lr;
    uint32 lr_saved;
    uint32 spsr;
} expt_frame_t, *expt_frame_p;

static void dump_exception_ctx(expt_frame_p frame)
{
    PRINT("Exception Ctx dump...\n");
    PRINT("Current stack at:%x\n", frame);
    PRINT(" r0: 0x%x\n", frame->r0);
    PRINT(" r1: 0x%x\n", frame->r1);
    PRINT(" r2: 0x%x\n", frame->r2);
    PRINT(" r3: 0x%x\n", frame->r3);
    PRINT(" r4: 0x%x\n", frame->r4);
    PRINT(" r5: 0x%x\n", frame->r5);
    PRINT(" r6: 0x%x\n", frame->r6);
    PRINT(" r7: 0x%x\n", frame->r7);
    PRINT(" r8: 0x%x\n", frame->r8);
    PRINT(" r9: 0x%x\n", frame->r9);
    PRINT(" r10: 0x%x\n", frame->r10);
    PRINT(" r11: 0x%x\n", frame->r11);
    PRINT(" r12: 0x%x\n", frame->r12);
    PRINT(" lr: 0x%x\n", frame->lr);
    PRINT(" spsr: 0x%x\n", frame->spsr);
    PRINT(" lr_saved: 0x%x\n", frame->lr_saved);

#ifdef STRACE

extern uint32 mYGetCurrStack(uint32 *a);
#define DUMP_STACK_DEPTH    (7u)
    /*if turn on '-mapcs-frame',
     r12 represent IP as last function's stack pointer.
     push {...fp ,ip, lr, pc}
     sub fp, ip, #4
     */
    extern uint32 __stack_end;
    extern uint32 __stack_start;
    uint32 i = 0;

    uint32 last_stack = frame->r11 + 4;  //sub fp, ip, #4

    DBG("STACK TRACE Start :%x\n", last_stack);
    if ((last_stack > (uint32)&__stack_start) && (last_stack < (uint32)&__stack_end)) {
        /* in bare metal */
        DBG("in bare metal\n\n");

        while ((i < DUMP_STACK_DEPTH) &&
                (last_stack > (uint32)&__stack_start) &&
                (last_stack < (uint32)&__stack_end)) {
            DBG("    Func Addr:   0x%x\n",  *(uint32 *)(last_stack - 4) - 8 -4);  //sub 8byte pre-fetch addr
            DBG("    Called Position Addr: 0x%x\n",  *(uint32 *)(last_stack - 8) - 4);
            i++;
            /*get the IP address in stack*/

            last_stack = *(uint32 *)(last_stack - 0x10u) + 4;
        }
    } else {
        /* in operation system */
        DBG("in operation system\n\n");

        uint32 stack_addr[2]={0,0};
        mYGetCurrStack(stack_addr);

        while ((i < DUMP_STACK_DEPTH) &&
                (last_stack > stack_addr[0]) &&
                (last_stack < stack_addr[1])) {
            DBG("    Func Addr:   0x%x\n",  *(uint32 *)(last_stack - 4) - 8 -4);  //sub 8byte pre-fetch addr
            DBG("    Called Position Addr: 0x%x\n",  *(uint32 *)(last_stack - 8) - 4);
            i++;
            /*get the IP address in stack*/

            last_stack = *(uint32 *)(last_stack - 0x10u) + 4;
        }
    }

#endif
}

void default_exception_hdlr(expt_frame_p frame)
{
#if ((defined(CFG_FUSAPKG_EN)) && ((FUSAPKG_ATCM_2BIT_ERROR_INJECT_POWER_ON == STD_ON) || (FUSAPKG_B0TCM_2BIT_ERROR_INJECT_POWER_ON == STD_ON) || (FUSAPKG_B1TCM_2BIT_ERROR_INJECT_POWER_ON == STD_ON)))
    if(Inject2bitTcmErrFlg == TRUE) {
        Tcm_Inject_2Bit_Err_Exception_Handlr();

    } else {
#endif
        dump_exception_ctx(frame);
        while (1);
#if ((defined(CFG_FUSAPKG_EN)) && ((FUSAPKG_ATCM_2BIT_ERROR_INJECT_POWER_ON == STD_ON) || (FUSAPKG_B0TCM_2BIT_ERROR_INJECT_POWER_ON == STD_ON) || (FUSAPKG_B1TCM_2BIT_ERROR_INJECT_POWER_ON == STD_ON)))
    }
#endif
}
