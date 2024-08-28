typedef long BaseType_t;
#define pdFALSE			( ( BaseType_t ) 0 )
#define pdTRUE			( ( BaseType_t ) 1 )
#include "vPortTaskUsersFPU.h"
#include "stdint.h"

/* Saved as part of the task context.  If ulPortTaskHasFPUContext is non-zero then
a floating point context must be saved and restored for the task. */
uint32_t ulPortTaskHasFPUContext = pdFALSE;

void vPortTaskUsesFPU( void )
{
uint32_t ulInitialFPSCR = 0;

	/* A task is registering the fact that it needs an FPU context.  Set the
	FPU flag (which is saved as part of the task context). */
	ulPortTaskHasFPUContext = pdTRUE;

	/* Initialise the floating point status register. */
	__asm volatile ( "FMXR 	FPSCR, %0" :: "r" (ulInitialFPSCR) : "memory" );
}