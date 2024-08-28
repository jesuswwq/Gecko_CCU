/********************************************************
 *      Copyright(c) 2020   Semidrive                   *
 *      All rights reserved.                            *
 ********************************************************/

#ifndef __SHELL_H__
#define __SHELL_H__

#include <Std_Types.h>
#include <cdefs.h>

typedef struct {
    char *cmd_str;
    uint32 (*func)(uint32 argc, char *argv[]);
    char *help_str;
    int  coremask;
} shell_cmd_t;

#define SHELL_CMD(str, func, help)  \
    _USED const shell_cmd_t _shell_cmd_##func##_ _SECTION(shell_cmd) = {\
                    str,\
                    func,\
                    help,\
                    0x1\
                };

#define SHELL_CMD_MCORE(str, func, help,mask)  \
    _USED const shell_cmd_t _shell_cmd_##func##_ _SECTION(shell_cmd) = {\
                    str,\
                    func,\
                    help,\
                    mask\
                };

void shell_loop(void);

#endif  /* __SHELL_H__ */
