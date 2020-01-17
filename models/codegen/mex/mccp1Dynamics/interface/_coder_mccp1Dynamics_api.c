/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_mccp1Dynamics_api.c
 *
 * Code generation for function '_coder_mccp1Dynamics_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "mccp1Dynamics.h"
#include "_coder_mccp1Dynamics_api.h"
#include "mccp1Dynamics_data.h"

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y);
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *x, const
  char_T *identifier))[2];
static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[2];
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *model, const
  char_T *identifier, struct0_T *y);
static const mxArray *emlrt_marshallOut(const real_T u[2]);
static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  char_T *identifier))[3];
static real_T (*g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[3];
static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[2];
static real_T (*j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[3];

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[11] = { "M", "fv", "gc", "B", "C", "A0", "Ks",
    "r", "Dm", "mass", "com" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 11, fieldNames, 0U, &dims);
  thisId.fIdentifier = "M";
  y->M = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "M")),
    &thisId);
  thisId.fIdentifier = "fv";
  y->fv = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "fv")),
    &thisId);
  thisId.fIdentifier = "gc";
  y->gc = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "gc")),
    &thisId);
  thisId.fIdentifier = "B";
  y->B = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "B")),
    &thisId);
  thisId.fIdentifier = "C";
  y->C = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "C")),
    &thisId);
  thisId.fIdentifier = "A0";
  y->A0 = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "A0")),
    &thisId);
  thisId.fIdentifier = "Ks";
  y->Ks = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "Ks")),
    &thisId);
  thisId.fIdentifier = "r";
  y->r = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "r")),
    &thisId);
  thisId.fIdentifier = "Dm";
  y->Dm = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "Dm")),
    &thisId);
  thisId.fIdentifier = "mass";
  y->mass = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "mass")), &thisId);
  thisId.fIdentifier = "com";
  y->com = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "com")),
    &thisId);
  emlrtDestroyArray(&u);
}

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = h_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *x, const
  char_T *identifier))[2]
{
  real_T (*y)[2];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = e_emlrt_marshallIn(sp, emlrtAlias(x), &thisId);
  emlrtDestroyArray(&x);
  return y;
}
  static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[2]
{
  real_T (*y)[2];
  y = i_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *model, const
  char_T *identifier, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(model), &thisId, y);
  emlrtDestroyArray(&model);
}

static const mxArray *emlrt_marshallOut(const real_T u[2])
{
  const mxArray *y;
  const mxArray *m0;
  static const int32_T iv0[1] = { 0 };

  static const int32_T iv1[1] = { 2 };

  y = NULL;
  m0 = emlrtCreateNumericArray(1, iv0, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m0, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m0, iv1, 1);
  emlrtAssign(&y, m0);
  return y;
}

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  char_T *identifier))[3]
{
  real_T (*y)[3];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = g_emlrt_marshallIn(sp, emlrtAlias(u), &thisId);
  emlrtDestroyArray(&u);
  return y;
}
  static real_T (*g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[3]
{
  real_T (*y)[3];
  y = j_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[2]
{
  real_T (*ret)[2];
  static const int32_T dims[1] = { 2 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims);
  ret = (real_T (*)[2])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static real_T (*j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[3]
{
  real_T (*ret)[3];
  static const int32_T dims[1] = { 3 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims);
  ret = (real_T (*)[3])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void mccp1Dynamics_api(const mxArray * const prhs[3], const mxArray *plhs[1])
{
  real_T (*xdot)[2];
  struct0_T model;
  real_T (*x)[2];
  real_T (*u)[3];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  xdot = (real_T (*)[2])mxMalloc(sizeof(real_T [2]));

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "model", &model);
  x = d_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "x");
  u = f_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "u");

  /* Invoke the target function */
  mccp1Dynamics(&st, &model, *x, *u, *xdot);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*xdot);
}

/* End of code generation (_coder_mccp1Dynamics_api.c) */
