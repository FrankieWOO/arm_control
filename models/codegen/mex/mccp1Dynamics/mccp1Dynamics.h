/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mccp1Dynamics.h
 *
 * Code generation for function 'mccp1Dynamics'
 *
 */

#ifndef MCCP1DYNAMICS_H
#define MCCP1DYNAMICS_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "mccp1Dynamics_types.h"

/* Function Declarations */
extern void mccp1Dynamics(const emlrtStack *sp, const struct0_T *model, const
  real_T x[2], const real_T u[3], real_T xdot[2]);

#endif

/* End of code generation (mccp1Dynamics.h) */
