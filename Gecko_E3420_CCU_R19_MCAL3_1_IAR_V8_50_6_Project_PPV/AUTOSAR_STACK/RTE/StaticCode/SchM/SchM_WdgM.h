#ifndef SCHM_WDGM_H_
#define SCHM_WDGM_H_

#include "Os.h"

#define SchM_Enter_WdgM() SuspendAllInterrupts()
#define SchM_Exit_WdgM()  ResumeAllInterrupts()

#endif /* End of SCHM_WDGM_H*/
