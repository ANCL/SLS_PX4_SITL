//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: QuasiController.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 27-Aug-2022 17:12:42
//

#ifndef QUASICONTROLLER_H
#define QUASICONTROLLER_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
extern void QuasiController(const double x_data[], const int x_size[2],
                            const double Kv2[2], const double Kv6[6],
                            const double M[3], double controller_output[4]);

#endif
//
// File trailer for QuasiController.h
//
// [EOF]
//
