/*
 * sd_vic.S
 *
 * Copyright (c) 2020 Semidrive Semiconductor.
 * All rights reserved.
 *
 * Description: SemiDrive VIC interrupt handlers.
 *
 * Revision History:
 * -----------------
 */

#include "asm_def.h"
#include "Vic_Irq_Cfg.h"

#if defined(__ICCARM__)
    #define SYS_MODE	0x1f
    #define SVC_MODE	0x13
    #define IRQ_MODE	0x12
#else
    .set SYS_MODE,	0x1f
    .set SVC_MODE,	0x13
    .set IRQ_MODE,	0x12
#endif

#if defined(__ICCARM__)
    SECTION .text:CODE(2)
#else
    .section ".text"
#endif

#if defined(OS_FreeRTOS)
#include "sdrv_vic_freertos.S"
#else
#include "sdrv_vic_baremetal.S"
#endif

vector:
    vectored_irq_handler	0
    vectored_irq_handler	1
    vectored_irq_handler	2
    vectored_irq_handler	3
    vectored_irq_handler	4
    vectored_irq_handler	5
    vectored_irq_handler	6
    vectored_irq_handler	7
    vectored_irq_handler	8
    vectored_irq_handler	9
    vectored_irq_handler	10
    vectored_irq_handler	11
    vectored_irq_handler	12
    vectored_irq_handler	13
    vectored_irq_handler	14
    vectored_irq_handler	15
    vectored_irq_handler	16
    vectored_irq_handler	17
    vectored_irq_handler	18
    vectored_irq_handler	19
    vectored_irq_handler	20
    vectored_irq_handler	21
    vectored_irq_handler	22
    vectored_irq_handler	23
    vectored_irq_handler	24
    vectored_irq_handler	25
    vectored_irq_handler	26
    vectored_irq_handler	27
    vectored_irq_handler	28
    vectored_irq_handler	29
    vectored_irq_handler	30
    vectored_irq_handler	31
    vectored_irq_handler	32
    vectored_irq_handler	33
    vectored_irq_handler	34
    vectored_irq_handler	35
    vectored_irq_handler	36
    vectored_irq_handler	37
    vectored_irq_handler	38
    vectored_irq_handler	39
    vectored_irq_handler	40
    vectored_irq_handler	41
    vectored_irq_handler	42
    vectored_irq_handler	43
    vectored_irq_handler	44
    vectored_irq_handler	45
    vectored_irq_handler	46
    vectored_irq_handler	47
    vectored_irq_handler	48
    vectored_irq_handler	49
    vectored_irq_handler	50
    vectored_irq_handler	51
    vectored_irq_handler	52
    vectored_irq_handler	53
    vectored_irq_handler	54
    vectored_irq_handler	55
    vectored_irq_handler	56
    vectored_irq_handler	57
    vectored_irq_handler	58
    vectored_irq_handler	59
    vectored_irq_handler	60
    vectored_irq_handler	61
    vectored_irq_handler	62
    vectored_irq_handler	63
    vectored_irq_handler	64
    vectored_irq_handler	65
    vectored_irq_handler	66
    vectored_irq_handler	67
    vectored_irq_handler	68
    vectored_irq_handler	69
    vectored_irq_handler	70
    vectored_irq_handler	71
    vectored_irq_handler	72
    vectored_irq_handler	73
    vectored_irq_handler	74
    vectored_irq_handler	75
    vectored_irq_handler	76
    vectored_irq_handler	77
    vectored_irq_handler	78
    vectored_irq_handler	79
    vectored_irq_handler	80
    vectored_irq_handler	81
    vectored_irq_handler	82
    vectored_irq_handler	83
    vectored_irq_handler	84
    vectored_irq_handler	85
    vectored_irq_handler	86
    vectored_irq_handler	87
    vectored_irq_handler	88
    vectored_irq_handler	89
    vectored_irq_handler	90
    vectored_irq_handler	91
    vectored_irq_handler	92
    vectored_irq_handler	93
    vectored_irq_handler	94
    vectored_irq_handler	95
    vectored_irq_handler	96
    vectored_irq_handler	97
    vectored_irq_handler	98
    vectored_irq_handler	99
    vectored_irq_handler	100
    vectored_irq_handler	101
    vectored_irq_handler	102
    vectored_irq_handler	103
    vectored_irq_handler	104
    vectored_irq_handler	105
    vectored_irq_handler	106
    vectored_irq_handler	107
    vectored_irq_handler	108
    vectored_irq_handler	109
    vectored_irq_handler	110
    vectored_irq_handler	111
    vectored_irq_handler	112
    vectored_irq_handler	113
    vectored_irq_handler	114
    vectored_irq_handler	115
    vectored_irq_handler	116
    vectored_irq_handler	117
    vectored_irq_handler	118
    vectored_irq_handler	119
    vectored_irq_handler	120
    vectored_irq_handler	121
    vectored_irq_handler	122
    vectored_irq_handler	123
    vectored_irq_handler	124
    vectored_irq_handler	125
    vectored_irq_handler	126
    vectored_irq_handler	127
    vectored_irq_handler	128
    vectored_irq_handler	129
    vectored_irq_handler	130
    vectored_irq_handler	131
    vectored_irq_handler	132
    vectored_irq_handler	133
    vectored_irq_handler	134
    vectored_irq_handler	135
    vectored_irq_handler	136
    vectored_irq_handler	137
    vectored_irq_handler	138
    vectored_irq_handler	139
    vectored_irq_handler	140
    vectored_irq_handler	141
    vectored_irq_handler	142
    vectored_irq_handler	143
    vectored_irq_handler	144
    vectored_irq_handler	145
    vectored_irq_handler	146
    vectored_irq_handler	147
    vectored_irq_handler	148
    vectored_irq_handler	149
    vectored_irq_handler	150
    vectored_irq_handler	151
    vectored_irq_handler	152
    vectored_irq_handler	153
    vectored_irq_handler	154
    vectored_irq_handler	155
    vectored_irq_handler	156
    vectored_irq_handler	157
    vectored_irq_handler	158
    vectored_irq_handler	159
    vectored_irq_handler	160
    vectored_irq_handler	161
    vectored_irq_handler	162
    vectored_irq_handler	163
    vectored_irq_handler	164
    vectored_irq_handler	165
    vectored_irq_handler	166
    vectored_irq_handler	167
    vectored_irq_handler	168
    vectored_irq_handler	169
    vectored_irq_handler	170
    vectored_irq_handler	171
    vectored_irq_handler	172
    vectored_irq_handler	173
    vectored_irq_handler	174
    vectored_irq_handler	175
    vectored_irq_handler	176
    vectored_irq_handler	177
    vectored_irq_handler	178
    vectored_irq_handler	179
    vectored_irq_handler	180
    vectored_irq_handler	181
    vectored_irq_handler	182
    vectored_irq_handler	183
    vectored_irq_handler	184
    vectored_irq_handler	185
    vectored_irq_handler	186
    vectored_irq_handler	187
    vectored_irq_handler	188
    vectored_irq_handler	189
    vectored_irq_handler	190
    vectored_irq_handler	191
    vectored_irq_handler	192
    vectored_irq_handler	193
    vectored_irq_handler	194
    vectored_irq_handler	195
    vectored_irq_handler	196
    vectored_irq_handler	197
    vectored_irq_handler	198
    vectored_irq_handler	199
    vectored_irq_handler	200
    vectored_irq_handler	201
    vectored_irq_handler	202
    vectored_irq_handler	203
    vectored_irq_handler	204
    vectored_irq_handler	205
    vectored_irq_handler	206
    vectored_irq_handler	207
    vectored_irq_handler	208
    vectored_irq_handler	209
    vectored_irq_handler	210
    vectored_irq_handler	211
    vectored_irq_handler	212
    vectored_irq_handler	213
    vectored_irq_handler	214
    vectored_irq_handler	215
    vectored_irq_handler	216
    vectored_irq_handler	217
    vectored_irq_handler	218
    vectored_irq_handler	219
    vectored_irq_handler	220
    vectored_irq_handler	221
    vectored_irq_handler	222
    vectored_irq_handler	223
    vectored_irq_handler	224
    vectored_irq_handler	225
    vectored_irq_handler	226
    vectored_irq_handler	227
    vectored_irq_handler	228
    vectored_irq_handler	229
    vectored_irq_handler	230
    vectored_irq_handler	231
    vectored_irq_handler	232
    vectored_irq_handler	233
    vectored_irq_handler	234
    vectored_irq_handler	235
    vectored_irq_handler	236
    vectored_irq_handler	237
    vectored_irq_handler	238
    vectored_irq_handler	239
    vectored_irq_handler	240
    vectored_irq_handler	241
    vectored_irq_handler	242
    vectored_irq_handler	243
    vectored_irq_handler	244
    vectored_irq_handler	245
    vectored_irq_handler	246
    vectored_irq_handler	247
    vectored_irq_handler	248
    vectored_irq_handler	249
    vectored_irq_handler	250
    vectored_irq_handler	251
    vectored_irq_handler	252
    vectored_irq_handler	253
    vectored_irq_handler	254
    vectored_irq_handler	255

#if defined(__ICCARM__)
    END
#else
.end
#endif
