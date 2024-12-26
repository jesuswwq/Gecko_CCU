/********************************************************
 *        Copyright(c) 2020    Semidrive                *
 *        All rights reserved.                          *
 ********************************************************/

/**
 * @file    send_char.c
 * @brief   send_char function which be called by mini_printf
 */
#if 0
#include <uart.h>

#define LIB_START_SEC_CODE
#include "Lib_MemMap.h"

void send_char(uint8 c)
{
    uart_tx(TTY_UART, &c, 1);
}

#define LIB_STOP_SEC_CODE
#include "Lib_MemMap.h"
#endif
