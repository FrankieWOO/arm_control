/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mccp1Dynamics_initialize.c
 *
 * Code generation for function 'mccp1Dynamics_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "mccp1Dynamics.h"
#include "mccp1Dynamics_initialize.h"
#include "_coder_mccp1Dynamics_mex.h"
#include "mccp1Dynamics_data.h"

/* Function Definitions */
void mccp1Dynamics_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (mccp1Dynamics_initialize.c) */
