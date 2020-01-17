/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_mccp1Dynamics_mex.c
 *
 * Code generation for function '_coder_mccp1Dynamics_mex'
 *
 */

/* Include files */
#include "mccp1Dynamics.h"
#include "_coder_mccp1Dynamics_mex.h"
#include "mccp1Dynamics_terminate.h"
#include "_coder_mccp1Dynamics_api.h"
#include "mccp1Dynamics_initialize.h"
#include "mccp1Dynamics_data.h"

/* Function Declarations */
static void mccp1Dynamics_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T
  nrhs, const mxArray *prhs[3]);

/* Function Definitions */
static void mccp1Dynamics_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T
  nrhs, const mxArray *prhs[3])
{
  int32_T n;
  const mxArray *inputs[3];
  const mxArray *outputs[1];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4,
                        13, "mccp1Dynamics");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 13,
                        "mccp1Dynamics");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* Call the function. */
  mccp1Dynamics_api(inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  mccp1Dynamics_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(mccp1Dynamics_atexit);

  /* Initialize the memory manager. */
  /* Module initialization. */
  mccp1Dynamics_initialize();

  /* Dispatch the entry-point. */
  mccp1Dynamics_mexFunction(nlhs, plhs, nrhs, prhs);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_mccp1Dynamics_mex.c) */
