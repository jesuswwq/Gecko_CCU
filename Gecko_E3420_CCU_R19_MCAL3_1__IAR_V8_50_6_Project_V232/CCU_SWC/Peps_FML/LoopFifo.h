#ifndef __LOOP_FIFO_H__
#define __LOOP_FIFO_H__

#include "NCK2910.h"

#define VarType		UHF_MessageTypeDef

typedef enum
{
	Undifined,
    True,
    False,
}tBool;

typedef struct
{ 
    volatile uint32_t  	Head;         	
    volatile uint32_t  	Tail;         
	volatile uint32_t  	Len;		
	volatile uint32_t  	Size;			   
	volatile VarType *  Ptr;
} LPFifo_TypeDef;

void Fifo_Init(LPFifo_TypeDef *pFifo,uint32_t VarLen);
tBool Fifo_DeInit(LPFifo_TypeDef *pFifo);
uint32_t Check_FifoMessageNumber(LPFifo_TypeDef *pFifo);
tBool Fifo_IsFull(LPFifo_TypeDef *pFifo);
tBool Fifo_IsEmpty(LPFifo_TypeDef *pFifo);
void Fifo_Write(LPFifo_TypeDef *pFifo,VarType Var);
VarType Fifo_Read(LPFifo_TypeDef *pFifo);


#endif
