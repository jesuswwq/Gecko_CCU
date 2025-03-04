#include "LoopFifo.h"

extern UHF_MessageTypeDef  nck2910recvFrame[5];
extern uint8_t u8Print_Num_Buf[8];

extern uint32_t ulPortSetInterruptMask( void );
extern void vPortClearInterruptMask( uint32_t ulNewMaskValue );

/*********************************************************************************************************
   Init FIFO
*********************************************************************************************************/
void Fifo_Init(LPFifo_TypeDef *pFifo,uint32_t VarLen)
{
//	pFifo -> Ptr	= (VarType *)malloc(VarLen * sizeof(VarType));
	pFifo -> Ptr	=  &nck2910recvFrame[0];
	pFifo -> Size	= VarLen;
    pFifo -> Head	= 0;
    pFifo -> Tail	= 0;	
	pFifo -> Len	= 0;
}

void Print_Fifo_Init(PrintFifo_TypeDef *pFifo,uint32_t VarLen)
{
//	pFifo -> Ptr	= (VarType *)malloc(VarLen * sizeof(VarType));
	pFifo -> Ptr	=  &u8Print_Num_Buf[0];
	pFifo -> Size	= VarLen;
    pFifo -> Head	= 0;
    pFifo -> Tail	= 0;	
	pFifo -> Len	= 0;
}


/*********************************************************************************************************
	Deinit FIFO
*********************************************************************************************************/
tBool Fifo_DeInit(LPFifo_TypeDef *pFifo)
{
	if(pFifo -> Len == 0)
	{
		return True;
	}
	else 
		return False;
}



/*********************************************************************************************************
	Check FIFO  Message Number
*********************************************************************************************************/
uint32_t Check_FifoMessageNumber(LPFifo_TypeDef *pFifo)
{
	return pFifo->Len;
}


/*********************************************************************************************************
    Check FIFO State
*********************************************************************************************************/
tBool Fifo_IsFull(LPFifo_TypeDef *pFifo)
{
	tBool ret = Undifined;
    if(pFifo -> Len == pFifo ->Size)
    {
    	ret = True;
    }else
    {
    	ret = False;
    }
    return ret;
}

tBool Print_Fifo_IsFull(PrintFifo_TypeDef *pFifo)
{
	tBool ret = Undifined;
    if(pFifo -> Len == pFifo ->Size)
    {
    	ret = True;
    }else
    {
    	ret = False;
    }
    return ret;
}
/*********************************************************************************************************
    Check FIFO State
*********************************************************************************************************/
tBool Fifo_IsEmpty(LPFifo_TypeDef *pFifo)
{
	tBool ret = Undifined;
    if(pFifo -> Len == 0)
    {
    	ret = True;
    }else
    {
    	ret = False;
    }
    return ret;
}

tBool Print_Fifo_IsEmpty(PrintFifo_TypeDef *pFifo)
{
	tBool ret = Undifined;
    if(pFifo -> Len == 0)
    {
    	ret = True;
    }else
    {
    	ret = False;
    }
    return ret;
}


/*********************************************************************************************************
	Write Infor to FIFO
*********************************************************************************************************/
void Fifo_Write(LPFifo_TypeDef *pFifo,VarType Var)
{
	// ulPortSetInterruptMask();
    *(pFifo -> Ptr + pFifo -> Head) = Var;
    pFifo -> Head = (pFifo -> Head + 1) % pFifo -> Size;
    pFifo -> Len ++;
    // vPortClearInterruptMask(0);
}

void Print_Fifo_Write(PrintFifo_TypeDef *pFifo,uint8_t Vr)
{
	// ulPortSetInterruptMask();
    *(pFifo -> Ptr + pFifo -> Head) = Vr;
    pFifo -> Head = (pFifo -> Head + 1) % pFifo -> Size;
    pFifo -> Len ++;
    // vPortClearInterruptMask(0);
}

/*********************************************************************************************************
	Read Infor From FiFO
*********************************************************************************************************/
VarType Fifo_Read(LPFifo_TypeDef *pFifo)
{
	VarType ReceiveData;
	// ulPortSetInterruptMask();
    ReceiveData = *(pFifo -> Ptr + pFifo -> Tail);
	pFifo -> Tail = (pFifo -> Tail + 1) % (pFifo -> Size);
	pFifo -> Len --;
    // vPortClearInterruptMask(0);
    return ReceiveData;
}

uint8_t Print_Fifo_Read(PrintFifo_TypeDef *pFifo)
{
	uint8_t ReceiveData;
	// ulPortSetInterruptMask();
    ReceiveData = *(pFifo -> Ptr + pFifo -> Tail);
	pFifo -> Tail = (pFifo -> Tail + 1) % (pFifo -> Size);
	pFifo -> Len --;
    // vPortClearInterruptMask(0);
    return ReceiveData;
}

