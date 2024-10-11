#ifndef __LF_TRACK_H
#define __LF_TRACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define LF_WINDOW_SIZE 	5u  // 窗口大小
#define THRESHOLD   	200u  // 波动阈值

typedef enum 
{ 
	DOWNWARD, 
	NO_TREND, 
	UPWARD 
}TrendStatus;  // 定义枚举类型表示趋势状态  强度下降   强度无明显变化  强度上升

TrendStatus FobKey_Tracking_Positioning_Algorithm(uint32_t * rssi,uint32_t rssi_len,uint32_t u32Threshold);
#endif
