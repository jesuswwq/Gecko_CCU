/********************************************************
 *  Copyright(c) 2018   Semidrive       *
 *******************************************************/

/**
 * @file    min_printf.c
 * @brief   a light-weight version of printf
 */

#include <stdarg.h>
#include <soc.h>
#include <Mcu.h>
// #include "mbox.h"

#if defined(CFG_AOS)
#include "autosar_task.h"
extern void TaskSuspendAll( void );
extern BaseType_t xTaskResumeAll( void );
#endif

/* Implemented by SOC */
extern void send_char(uint8);

static const char assic[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                             'a', 'b', 'c', 'd', 'e', 'f'
                            };

static const unsigned int dec_base[] = {
    1UL,
    10UL,
    100UL,
    1000UL,
    10000UL,
    100000UL,
    1000000UL,
    10000000UL,
    100000000UL,
    1000000000UL,
};


static const char* core_str[]={"SF:  ","SX0: ","SX1: ", "SP0: ","SP1: "};
static void printf_core(void)
{
    const char *who = core_str[Mcu_GetCoreID()];
    while (*who != '\0') {
        send_char(*who);
        who++;
    }
}
/*
 * Format tag prototype is "%[flags][width][.precision][length]specifier"
 *      flags: -, +, space, #, O
 *      .precision: .number
 *      length: h, I, L
 *      width: number, *
 */
int mini_printf(const char *fmt, ...)
{
    va_list args;
    const char *p = NULL_PTR, *str = NULL_PTR,*scan = NULL_PTR;
    int ival = 0, i = 0;
    unsigned int digit = 0, msb_processed = 0, index = 0, width = 8;
    float fv;

    va_start(args, fmt);

#if defined(CFG_AOS)
    //TaskSuspendAll();
#endif
    for (scan = fmt; *scan; scan++) {
        if (*scan == '\n') {
            printf_core();
            break;
        }
    }

    for (p = fmt; *p; p++) {
        if (*p != '%') {
            if (*p == '\n') {
                uint8 c = '\r';
                send_char(c);
            }

            send_char(*p);
            continue;
        }

        p++;

        while (*p != 'c' && *p != 'd'
               && *p != 'X' && *p != 'x'
               && *p != 'p' && *p != 'u'
               && *p != 's' && *p != 'f') {
            if (*p >= '0' && *p <= '9' && *(p - 1) != '.' && *(p - 2) != '.') {
                width = *p - '0';

                if (width < 1) {
                    width = 1;
                }
            }

            p++;
        }

        switch (*p) {
        case 'd':
            ival = va_arg(args, int);

            if (ival < 0) {
                send_char('-');
                ival = 0 - ival;
            }

            msb_processed = 0;

            for (i = 9; i >= 0; i--) {
                digit = ival / dec_base[i];
                ival = ival % dec_base[i];

                if ((digit > 0) || (msb_processed)) {
                    send_char(digit + '0');
                    msb_processed = 1;
                }
            }

            /* all digits are zeros */
            if (!msb_processed) {
                send_char('0');
            }

            break;

        case 'x':
        case 'X':
        case 'u':
        case 'p':
            ival = va_arg(args, int);

            for (i = width - 1; i >= 0; i--) {
                index = (ival >> (i) * 4) & 0xFUL;
                send_char(assic[index]);
            }

            width = 8;
            break;

        case 's':
            for (str = va_arg(args, char *); *str; str++) {
                send_char(*str);
            }

            break;

        case 'c':
            send_char(va_arg(args, int));
            break;
        case 'f':

            fv = va_arg(args, double);
            ival = (int)fv;
            if (ival < 0) {
                ival = - ival;
                send_char('-');
            }

            msb_processed = 0;
            for (i = 9; i >= 0; i--) {
                digit = ival / dec_base[i];
                ival = ival % dec_base[i];
                if ((digit > 0) || (msb_processed)) {
                    send_char(digit + '0');
                    msb_processed = 1;
                }
            }
            /* all digits are zeros */
            if (!msb_processed) {
                send_char('0');
            }
            send_char('.');
            /* remain four digits after the decimal point */
            ival = (int)(fv * 10000);
            ival = ival % 10000;
            msb_processed = 0;
            for (i = 3; i >= 0; i--) {
                digit = ival / dec_base[i];
                ival = ival % dec_base[i];
                if ((digit != 0) || (msb_processed)) {
                    send_char(digit + '0');
                    msb_processed = 1;
                }
            }
            /* all digits are zeros */
            if (!msb_processed) {
                send_char('0');
            }

            break;
        default:
            break;
        }
    }

#if defined(CFG_AOS)
    //xTaskResumeAll();
#endif
    va_end(args);

    return 0;
}
