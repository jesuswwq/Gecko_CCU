/*
 * File: XcpTest.h
 *
 * Code generated for Simulink model 'XcpTest'.
 *
 * Model version                  : 1.12
 * Simulink Coder version         : 8.5 (R2013b) 08-Aug-2013
 * C/C++ source code generated on : Tue Sep 17 09:27:02 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_XcpTest_h_
#define RTW_HEADER_XcpTest_h_
#ifndef XcpTest_COMMON_INCLUDES_
# define XcpTest_COMMON_INCLUDES_
#include <stddef.h>
#include "Xcprtwtypes.h"
#endif                                 /* XcpTest_COMMON_INCLUDES_ */

#include "XcpTest_types.h"

/* Includes for objects with custom storage classes. */
#include "XcpData.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif


/* Real-time Model Data Structure */
struct tag_RTM_XcpTest_T {
  const char_T * volatile errorStatus;
};

/* Model entry point functions */
extern void XcpTest_initialize(void);
extern void XcpTest_step(void);
extern void XcpTest_terminate(void);

/* Real-time Model object */
extern RT_MODEL_XcpTest_T *const XcpTest_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'XcpTest'
 */
#endif                                 /* RTW_HEADER_XcpTest_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
