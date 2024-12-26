
#include "Fobs_Tracking_Algorithm.H"

TrendStatus overallTrend = NO_TREND; // 保存整体趋势状态的全局变量，初始为无趋势状态

//移动平均线，Moving Average，简称MA，原本的意思是移动平均，所以一般称之为移动平均线，简称均线。
void MaWindow(uint32_t data, uint8_t windowSize,uint32_t Threshold)
{
	static uint32_t window[LF_WINDOW_SIZE];
	static uint8_t	index = 0;
	static uint8_t	count = 0;
	uint32_t		sum = 0;
	uint32_t		average = 0;
	uint8_t 		i;

	// 更新窗口
	window[index]		= data;
	index				= (index + 1) % windowSize;

	// 窗口数据计数
	count++;
	// 计算平均值
	if (count == windowSize)
	{
		for (i = 0; i < windowSize; i++)
		{
			sum 				+= window[i];
		}

		average 			= sum / windowSize;

		uint32_t		diff = abs(data - average);

		if (diff > Threshold)//THRESHOLD)
		{
			if (data > average)
			{
				overallTrend		= UPWARD;		// 更新整体趋势状态为上升
			}
			else 
			{
				overallTrend		= DOWNWARD; 	// 更新整体趋势状态为下降
			}
		}
		else 
		{
			overallTrend		= NO_TREND; 		// 更新整体趋势状态为无趋势
		}
	}
}


TrendStatus FobKey_Tracking_Positioning_Algorithm(uint32_t * rssi,uint32_t rssi_len,uint32_t u32Threshold)
{
	uint8_t			size = 16;
	uint8_t 		windowSize = LF_WINDOW_SIZE;
	uint8_t 		Index;

	if(rssi_len < 16)
	{
		size = rssi_len;
	}

	for (Index = 0; Index < size; Index++)
	{
		MaWindow(rssi[Index], windowSize, u32Threshold);
	}

	return overallTrend;
}


