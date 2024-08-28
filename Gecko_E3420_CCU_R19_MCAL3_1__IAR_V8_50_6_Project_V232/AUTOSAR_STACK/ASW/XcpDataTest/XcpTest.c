/*
 * File: XcpTest.c
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

#include "XcpTest.h"
#include "XcpTest_private.h"

/* Real-time model */
RT_MODEL_XcpTest_T XcpTest_M_;
RT_MODEL_XcpTest_T *const XcpTest_M = &XcpTest_M_;

/* Model step function */
void XcpTest_step(void)
{
  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   */
  //Mea_A = (uint16)Calib_A + (uint16)Calib_B;
  Mea_A = Calib_A + Calib_B;
}

/* Model initialize function */
void XcpTest_initialize(void)
{
  /* Registration code */

  /* initialize error status */


  /* block I/O */
  /* custom signals */
  Mea_A = 0U;
}
 
/* Model terminate function */
void XcpTest_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
