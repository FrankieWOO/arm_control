/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mccp1TauA.c
 *
 * Code generation for function 'mccp1TauA'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "mccp1TauA.h"
#include "mpower.h"
#include "error.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 5,     /* lineNo */
  "mccp1TauA",                         /* fcnName */
  "D:\\Dropbox\\workspace\\ws_matlab\\arm_control\\models\\mccp1TauA.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 12,  /* lineNo */
  "sqrt",                              /* fcnName */
  "D:\\MATLAB\\R2017a\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"/* pathName */
};

/* Function Definitions */
real_T mccp1TauA(const emlrtStack *sp, const struct0_T *obj, const real_T x[2],
                 const real_T u[3])
{
  real_T b_x;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;

  /* MCCP1TAUA Summary of this function goes here */
  /*    Detailed explanation goes here */
  st.site = &emlrtRSI;
  b_x = (mpower(obj->B) + mpower(obj->C)) - 2.0 * obj->B * obj->C *
    muDoubleScalarCos(u[0] - x[0]);
  if (b_x < 0.0) {
    b_st.site = &d_emlrtRSI;
    error(&b_st);
  }

  return obj->Ks * obj->B * obj->C * muDoubleScalarSin(u[0] - x[0]) * (1.0 +
    (obj->r * u[1] - obj->A0) / muDoubleScalarSqrt(b_x)) - obj->Dm * u[2] * x[1];
}

/* End of code generation (mccp1TauA.c) */
