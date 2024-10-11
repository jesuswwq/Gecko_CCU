/********************************************************
 *      Copyright(c) 2020   Semidrive                   *
 *      All rights reserved.                            *
 ********************************************************/

#include <soc.h>
#include <uart.h>
#include "mini_libc.h"
#include "shell.h"
#include "debug.h"
#include "Mcu.h"
#include "lnk_sym.h"
#ifdef GCOV_ENABLE
#include "gcov.h"
#endif

#define CR_CHAR     (0x0d)
#define MAX_SHELL_HISTORY   0x1
#define MAX_SHELL_LINE_SZ   0x80
#define MAX_SHELL_ARGC      8u

#define IS_HEX_CHAR(x)   \
        (((x >= 'a') && (x <= 'z'))\
            || ((x >= 'A') && (x <= 'Z'))\
            || ((x >= '0') && (x <= '9')))
#ifndef EN_UNIFIED_IMAGE
static char str_buf[MAX_SHELL_HISTORY][MAX_SHELL_LINE_SZ];
static uint32 history_n = 0;
#endif
#if defined(SHELL_AUTO_CMD) /* for test purpose only */
extern char *auto_cmd[];
#endif

#ifdef EN_UNIFIED_IMAGE
uint8  need_run_case(const uint32 mask)
{
    uint8 CoreId = Mcu_GetCoreID();

    if (mask & (0x1 << CoreId)) {
        return 1;
    } else {
        return 0;
    }
}
#endif

sint32 shell_parse_run(char *line)
{
    char buf[MAX_SHELL_LINE_SZ];
    strcpy(buf, line);
    char *p = buf;
    char *argv[MAX_SHELL_ARGC];

    for (int i = 0; i < MAX_SHELL_ARGC; i++) {
        argv[i] = NULL_PTR;
    }

    boolean wd_begin = FALSE;
    uint32 argc = 0;

    while (*p != '\0' && *p != 0x0d) {
        if (IS_HEX_CHAR(*p) || (*p == '_')) {
            if (!wd_begin) {
                wd_begin = TRUE;
                argv[argc++] = p;
            }
        } else {
            *p = '\0';
            wd_begin = FALSE;
        }

        p++;
    }
    *p = '\0';
    if (argc < 1) {
        return -1;
    }

    shell_cmd_t *cmd = (shell_cmd_t *)(unsigned long)__start_shell_cmd;
    boolean found = FALSE;

    for (; cmd < (shell_cmd_t *)(unsigned long)__stop_shell_cmd; cmd++) {
        if (0 == strcmp(argv[0], cmd->cmd_str)) {
            found = TRUE;
            break;
        }
    }

    if (found && (NULL_PTR != cmd->func)) {
#ifdef EN_UNIFIED_IMAGE
        if (need_run_case(cmd->coremask)) {
            return cmd->func(argc, argv);
        }else{
            return 0;
        }
#else
        return cmd->func(argc, argv);
#endif
    } else {
        PRINT("\nInvalid commond: %s\n", argv[0]);
        return -2;
    }
}

void shell_loop(void)
{
    char c;
    char b;
    uint8 lf_nl = 0x0a;
    sint32 cur_buf_idx = 0;
    sint32 cur_line_pos = 0;
#ifdef EN_UNIFIED_IMAGE
    uint32 history_n = 0;
    char str_buf[MAX_SHELL_HISTORY][MAX_SHELL_LINE_SZ];
#endif
#if defined(SHELL_AUTO_CMD) /* for test purpose only */
    char **p_cmd = auto_cmd;

    for (; *p_cmd != NULL_PTR; p_cmd++) {
        PRINT("autorun: %s\n", *p_cmd);
        shell_parse_run(*p_cmd);
    }

#endif
#ifdef EN_UNIFIED_IMAGE
    uint8 CoreId = Mcu_GetCoreID();

    if (0 == CoreId)
#endif
        PRINT("\n\r#>");

    while (1) {
#ifdef EN_UNIFIED_IMAGE

        if (0 == uart_rx_vuart(CoreId, (uint8 *)&c, 1)) {
#else

        if (0 == uart_rx(TTY_UART, (uint8 *)&c, 1)) {
#endif

            if (cur_line_pos < MAX_SHELL_LINE_SZ - 1) {
                str_buf[cur_buf_idx][cur_line_pos++] = c;

                if (IS_HEX_CHAR(c)
                    || (c == 0x0d) || (c == 0x20)   /* CR || Space */
                    || (c == '_')
                    || (c == 0x08u) || (c == 0x7f)) { /* BS || DEL  */
                    if ((c == 0x08u) || (c == 0x7f)) {
                        if (cur_line_pos > 0) {
                            if (cur_line_pos == 1) {
                                cur_line_pos = 0;
                            } else {
                                cur_line_pos -= 2;
                                c = 0x08;
                                b = ' ';
#ifdef EN_UNIFIED_IMAGE

                                if (CoreId == 0) {
#endif
                                    uart_tx(TTY_UART, (uint8 *)&c, 1);
                                    uart_tx(TTY_UART, (uint8 *)&b, 1);
                                    uart_tx(TTY_UART, (uint8 *)&c, 1);
#ifdef EN_UNIFIED_IMAGE
                                }

#endif
                            }
                        }
                    } else {
#ifdef EN_UNIFIED_IMAGE

                        if (CoreId == 0 && cur_line_pos > 0) {
#else

                        if (cur_line_pos > 0) {
#endif
                          if(CR_CHAR == c){
                            uart_tx(TTY_UART, &lf_nl, 1);
                          }
                          uart_tx(TTY_UART, (uint8 *)&c, 1);   /* echo */
                        }

                    }
                }

                if (c == 0x0du) {
#ifdef EN_UNIFIED_IMAGE

                    if (CoreId == 0)
#endif
                        PRINT("\n");

                    if (cur_line_pos < MAX_SHELL_LINE_SZ - 1)
                        str_buf[cur_buf_idx][cur_line_pos + 1] = '\0';

                    if (0 == shell_parse_run(&str_buf[cur_buf_idx][0])) {
                        history_n++;
                        cur_buf_idx++;

                        if (cur_buf_idx >= MAX_SHELL_HISTORY) {
                            cur_buf_idx = 0u;
                        }
                    }

                    cur_line_pos = 0;
#ifdef EN_UNIFIED_IMAGE

                    if (CoreId == 0)
#endif
                        PRINT("\n\r#>");
                }

#if defined(SHELL_UP_DOWN)
                else if (c == 38u) {   /* up */
                    if (history_n > 1) {
                        cur_buf_idx--;

                        if (cur_buf_idx < 0) {
                            cur_buf_idx = history_n < MAX_SHELL_HISTORY ? history - 1 : MAX_SHELL_HISTORY - 1;
                        }

#ifdef EN_UNIFIED_IMAGE

                        if (CoreId == 0)
#endif
                            PRINT("#>%s", &str_buf[cur_buf_idx][0]);
                    }
                } else if (c == 40u) {  /* down */
                    if (history_n > 1) {
                        cur_buf_idx++;
                        cur_buf_idx = cur_buf_idx % MAX_SHELL_HISTORY;
#ifdef EN_UNIFIED_IMAGE

                        if (CoreId == 0)
#endif
                            PRINT("%s", &str_buf[cur_buf_idx][0]);
                    }
                }

#endif
            }
        }
    }
}

uint32 help(uint32 argc, char *argv[])
{
#ifdef EN_UNIFIED_IMAGE
    uint8 CoreId = Mcu_GetCoreID();
#endif
    shell_cmd_t *cmd = (shell_cmd_t *)(unsigned long)__start_shell_cmd;

    if (1u == argc) {
#ifdef EN_UNIFIED_IMAGE

        if (CoreId == 0)
#endif
            PRINT("Command List\n");

        for (; cmd < (shell_cmd_t *)(unsigned long)__stop_shell_cmd; cmd++) {
#ifdef EN_UNIFIED_IMAGE

            if (CoreId == 0)
#endif
                PRINT("%s\n", cmd->cmd_str);
        }

#ifdef EN_UNIFIED_IMAGE

        if (CoreId == 0)
#endif
            PRINT("Usage: help [cmd]\n");

        return 0;
    }

    boolean found = FALSE;

    for (; cmd < (shell_cmd_t *)(unsigned long)__stop_shell_cmd; cmd++) {
        if (0 == strcmp(argv[1], cmd->cmd_str)) {
            found = TRUE;
            break;
        }
    }

    if (found && (NULL_PTR != cmd->help_str)) {
#ifdef EN_UNIFIED_IMAGE

        if (CoreId == 0)
#endif
            PRINT("%s\n", cmd->help_str);
    }

    return 0;
}

#ifdef GCOV_ENABLE
uint32 gcov_dump_execute(uint32 argc, char *argv[])
{
    __gcov_dump();
    return 0;
}
#endif

SHELL_CMD("help", help, "Shell help")
#ifdef GCOV_ENABLE
SHELL_CMD("gcov_dump", gcov_dump_execute, "gcov dump execution")
#endif
