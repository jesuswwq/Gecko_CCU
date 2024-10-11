/********************************************************
 *          Copyright(c) 2018   Semidrive               *
 *******************************************************/

#ifndef __ASM_INC_H__
#define __ASM_INC_H__

#include <Compiler.h>

#define MODE_USR    0x10
#define MODE_FIQ    0x11
#define MODE_IRQ    0x12
#define MODE_SVC    0x13
#define MODE_ABT    0x17
#define MODE_UND    0x1B
#define MODE_SYS    0x1F

#define FUNCTION(x) .global x; .type x,"function"; x:

#endif

