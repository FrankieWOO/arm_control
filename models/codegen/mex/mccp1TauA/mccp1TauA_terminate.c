/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mccp1TauA_terminate.c
 *
 * Code generation for function 'mccp1TauA_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "mccp1TauA.h"
#include "mccp1TauA_terminate.h"
#include "_coder_mccp1TauA_mex.h"
#include "mccp1TauA_data.h"

/* Function Definitions */
void mccp1TauA_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void mccp1TauA_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (mccp1TauA_terminate.c) */
