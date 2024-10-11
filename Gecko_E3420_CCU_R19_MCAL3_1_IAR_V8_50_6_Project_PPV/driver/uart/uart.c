/********************************************************
 *      Copyright(c) 2019   Semidrive  Semiconductor    *
 *      All rights reserved.                            *
 ********************************************************/

#include "Mcu_Modules.h"
#include "uart.h"

#include "cdefs.h"
#include "irq_num.h"
#include "irq.h"
#include "Mcu_Delay.h"

extern uart_ops_t uart_ctl;

static uint32 uart_enabled = 0;

#ifdef EN_UNIFIED_IMAGE

v_uart_t  virtual_uart[MAX_CORES] _SECTION(.dma_buffer);

static void vuart_init(void)
{
    for(uint8 core=0;core < MAX_CORES ;core++)
        ring_buf_create(&virtual_uart[core].ring,virtual_uart[core].membuf,V_UART_FIFO_D_SHIFT);
}

sint32 uart_rx_vuart(uint8 CoreId, uint8 *data, uint32 sz)
{
    if(ring_buf_len(&virtual_uart[CoreId].ring)){
        if(ring_buf_get(&virtual_uart[CoreId].ring,data,sz) != sz){
            return -1;
        }
    }else{
        return -1;
    }
    return 0;
}

static sint32 uart_tx_vuart(uint8 CoreId, uint8 *data, uint32 sz)
{

    if(ring_buf_len(&virtual_uart[CoreId].ring) < virtual_uart[CoreId].ring.size){
        if(ring_buf_put(&virtual_uart[CoreId].ring,data,sz) != sz ){
            return -1;
        }
    }else{
        return -1;
    }
    return 0;
}

uint32 uart_rx_irq(unsigned long b, uint8 *data, uint32 sz);

void uart_rx_handle(void)
{
    uint8 data;
    unsigned long b = Mcu_GetModuleBase(TTY_UART);
    if(uart_rx_irq(b,&data,1)){
        for(uint8 core=0;core < MAX_CORES ;core++){
            uart_tx_vuart(core,&data,1);
        }
    }
}
#endif

sint32 uart_init(module_e m, uart_cfg_t *cfg)
{
    unsigned long b = Mcu_GetModuleBase(m);

    sint32 res = uart_ctl.init(b, cfg);

    uart_enabled |= (0x01u << (m - UART1));
#ifdef EN_UNIFIED_IMAGE
    vuart_init();

    irq_attach(UART1_INTR_NUM+ (m - UART1), uart_rx_handle, NULL);
    irq_set_priority(UART1_INTR_NUM+ (m - UART1), 10);
    irq_enable(UART1_INTR_NUM+ (m - UART1));
#endif
    return res;
}

sint32 uart_tx(module_e m, uint8 *data, uint32 sz)
{
    unsigned long b = Mcu_GetModuleBase(m);
    return uart_ctl.uart_tx(b, data, sz);
}

sint32 uart_rx(module_e m, uint8 *data, uint32 sz)
{
    unsigned long b = Mcu_GetModuleBase(m);
    return uart_ctl.uart_rx(b, data, sz);
}

boolean uart_is_enabled(module_e m)
{
    return !!(uart_enabled & (0x01u << (m - UART1)));
}

sint32 uart_chk_auto_br(module_e m)
{
    unsigned long b = Mcu_GetModuleBase(m);
    if (NULL_PTR != uart_ctl.uart_chk_auto_br) {
        return uart_ctl.uart_chk_auto_br(b);
    } else {
        return -1;
    }
}

void uart_enable_auto_br(module_e m)
{
    unsigned long b = Mcu_GetModuleBase(m);
    if (NULL_PTR != uart_ctl.uart_enable_auto_br) {
        uart_ctl.uart_enable_auto_br(b);
    }
}

void uart_disable_auto_br(module_e m)
{
    unsigned long b = Mcu_GetModuleBase(m);
    if (NULL_PTR != uart_ctl.uart_disable_auto_br) {
        uart_ctl.uart_disable_auto_br(b);
    }
}

void uart_clr_rx_fifo(module_e m)
{
    unsigned long b = Mcu_GetModuleBase(m);
    if (NULL_PTR != uart_ctl.uart_clr_rx_fifo) {
        uart_ctl.uart_clr_rx_fifo(b);
    }
}
