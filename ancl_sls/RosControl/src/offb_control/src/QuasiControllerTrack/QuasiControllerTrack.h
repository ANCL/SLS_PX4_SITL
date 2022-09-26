//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: QuasiControllerTrack.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 25-Sep-2022 17:06:46
//

#ifndef QUASICONTROLLERTRACK_H
#define QUASICONTROLLERTRACK_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
extern void QuasiControllerTrack(const double x[16], double t,
                                 const double Kv2[2], const double Kv6[6],
                                 const double M[7], const double TParam[4],
                                 double controller_output[4]);

#endif
//
// File trailer for QuasiControllerTrack.h
//
// [EOF]
//
