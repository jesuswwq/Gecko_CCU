/********************************************************
 *      Copyright(c) 2019   Semidrive  Semiconductor    *
 *      All rights reserved.                            *
 ********************************************************/
#ifndef __UART_H__
#define __UART_H__

#include <soc_def.h>

#ifdef EN_UNIFIED_IMAGE
#include <ring.h>
#include "Mcu_Soc.h"
#endif
#if defined(BOARD_E3_z1)
#define UART_ROOT_CLK_FREQ  138750000u
#else
#define UART_ROOT_CLK_FREQ  83380000u
#endif

typedef enum {
    RS232,
    RS422,
    RS485,
} protocol_e;

typedef enum {
    UART_PARITY_EVEN,
    UART_PARITY_ODD,
    UART_PARITY_NONE,
} parity_e;

typedef enum {
    STOP_1BIT,
    STOP_1P5BIT,
    STOP_2BIT,
} uart_stop_e;

typedef enum {
    FLOW_CTRL_HW,
    FLOW_CTRL_CHAR,
    FLOW_CTRL_NONE,
} flow_ctrl_e;

typedef struct {
    protocol_e protocol;
    parity_e parity;
    uart_stop_e stop;
    flow_ctrl_e flow_ctrl;
    uint8 data_bits;
    uint32 baud_rate;
    boolean auto_br;
} uart_cfg_t;

typedef struct {
    sint32 (*init)(unsigned long b, uart_cfg_t *cfg);
    sint32 (*uart_tx)(unsigned long b, uint8 *data, uint32 sz);
    sint32 (*uart_rx)(unsigned long b, uint8 *data, uint32 sz);
    void (*uart_enable_auto_br)(unsigned long b);
    void (*uart_disable_auto_br)(unsigned long b);
    sint32 (*uart_chk_auto_br)(unsigned long b);
    void (*uart_clr_rx_fifo)(unsigned long b);
} uart_ops_t;

#ifdef EN_UNIFIED_IMAGE

#define   V_UART_FIFO_D_SHIFT  (5u)
#define   V_UART_FIFO_D  (0x1 << V_UART_FIFO_D_SHIFT)
#define   MAX_CORES  (5u)


typedef struct {
    ring_buf_t  ring;
    uint8 membuf[V_UART_FIFO_D];
} v_uart_t;

#endif

sint32 uart_init(module_e m, uart_cfg_t *cfg);
sint32 uart_tx(module_e m, uint8 *data, uint32 sz);
sint32 uart_rx(module_e m, uint8 *data, uint32 sz);
sint32 uart_chk_auto_br(module_e m);
boolean uart_is_enabled(module_e m);
void uart_enable_auto_br(module_e m);
void uart_disable_auto_br(module_e m);
void uart_clr_rx_fifo(module_e m);

#ifdef EN_UNIFIED_IMAGE
sint32 uart_rx_vuart(uint8 CoreId, uint8 *data, uint32 sz);
#endif

#endif  /* __UART_H__ */
