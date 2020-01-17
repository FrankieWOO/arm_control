/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mccp1Dynamics.c
 *
 * Code generation for function 'mccp1Dynamics'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "mccp1Dynamics.h"
#include "mpower.h"
#include "error.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 4,     /* lineNo */
  "mccp1Dynamics",                     /* fcnName */
  "D:\\Dropbox\\workspace\\ws_matlab\\arm_control\\models\\mccp1Dynamics.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 10,  /* lineNo */
  "mccp1Dynamics",                     /* fcnName */
  "D:\\Dropbox\\workspace\\ws_matlab\\arm_control\\models\\mccp1Dynamics.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 16,  /* lineNo */
  "mccp1Dynamics",                     /* fcnName */
  "D:\\Dropbox\\workspace\\ws_matlab\\arm_control\\models\\mccp1Dynamics.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 12,  /* lineNo */
  "sqrt",                              /* fcnName */
  "D:\\MATLAB\\R2017a\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"/* pathName */
};

/* Function Definitions */
void mccp1Dynamics(const emlrtStack *sp, const struct0_T *model, const real_T x
                   [2], const real_T u[3], real_T xdot[2])
{
  real_T b_x;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;

  /* MCCP1DYNAMICS Summary of this function goes here */
  /*    Detailed explanation goes here */
  st.site = &emlrtRSI;
  b_st.site = &b_emlrtRSI;
  c_st.site = &c_emlrtRSI;
  b_x = (mpower(model->B) + mpower(model->C)) - 2.0 * model->B * model->C *
    muDoubleScalarCos(u[0] - x[0]);
  if (b_x < 0.0) {
    d_st.site = &f_emlrtRSI;
    error(&d_st);
  }

  xdot[0] = x[1];
  xdot[1] = (((model->Ks * model->B * model->C * muDoubleScalarSin(u[0] - x[0]) *
               (1.0 + (model->r * u[1] - model->A0) / muDoubleScalarSqrt(b_x)) -
               model->Dm * u[2] * x[1]) - model->fv * x[1]) + -model->mass *
             model->com * model->gc * muDoubleScalarSin(x[0])) / model->M;
}

/* End of code generation (mccp1Dynamics.c) */
