//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mldivide.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 25-Sep-2022 16:03:15
//

// Include Files
#include "mldivide.h"
#include "rt_nonfinite.h"
#include <algorithm>
#include <cmath>

// Function Definitions
//
// Arguments    : const double A[16]
//                double B[4]
// Return Type  : void
//
namespace coder {
void mldivide(const double A[16], double B[4])
{
  double b_A[16];
  int a;
  int i;
  int jA;
  signed char ipiv[4];
  std::copy(&A[0], &A[16], &b_A[0]);
  ipiv[0] = 1;
  ipiv[1] = 2;
  ipiv[2] = 3;
  ipiv[3] = 4;
  for (int j{0}; j < 3; j++) {
    double smax;
    int b_tmp;
    int jp1j;
    int mmj_tmp;
    signed char i1;
    mmj_tmp = 2 - j;
    b_tmp = j * 5;
    jp1j = b_tmp + 2;
    jA = 4 - j;
    a = 0;
    smax = std::abs(b_A[b_tmp]);
    for (int k{2}; k <= jA; k++) {
      double s;
      s = std::abs(b_A[(b_tmp + k) - 1]);
      if (s > smax) {
        a = k - 1;
        smax = s;
      }
    }
    if (b_A[b_tmp + a] != 0.0) {
      if (a != 0) {
        jA = j + a;
        ipiv[j] = static_cast<signed char>(jA + 1);
        smax = b_A[j];
        b_A[j] = b_A[jA];
        b_A[jA] = smax;
        smax = b_A[j + 4];
        b_A[j + 4] = b_A[jA + 4];
        b_A[jA + 4] = smax;
        smax = b_A[j + 8];
        b_A[j + 8] = b_A[jA + 8];
        b_A[jA + 8] = smax;
        smax = b_A[j + 12];
        b_A[j + 12] = b_A[jA + 12];
        b_A[jA + 12] = smax;
      }
      i = (b_tmp - j) + 4;
      for (a = jp1j; a <= i; a++) {
        b_A[a - 1] /= b_A[b_tmp];
      }
    }
    jA = b_tmp;
    for (jp1j = 0; jp1j <= mmj_tmp; jp1j++) {
      smax = b_A[(b_tmp + (jp1j << 2)) + 4];
      if (smax != 0.0) {
        i = jA + 6;
        a = (jA - j) + 8;
        for (int k{i}; k <= a; k++) {
          b_A[k - 1] += b_A[((b_tmp + k) - jA) - 5] * -smax;
        }
      }
      jA += 4;
    }
    i1 = ipiv[j];
    if (i1 != j + 1) {
      smax = B[j];
      B[j] = B[i1 - 1];
      B[i1 - 1] = smax;
    }
  }
  for (int k{0}; k < 4; k++) {
    jA = k << 2;
    if (B[k] != 0.0) {
      i = k + 2;
      for (a = i; a < 5; a++) {
        B[a - 1] -= B[k] * b_A[(a + jA) - 1];
      }
    }
  }
  for (int k{3}; k >= 0; k--) {
    jA = k << 2;
    if (B[k] != 0.0) {
      B[k] /= b_A[k + jA];
      for (a = 0; a < k; a++) {
        B[a] -= B[k] * b_A[a + jA];
      }
    }
  }
}

} // namespace coder

//
// File trailer for mldivide.cpp
//
// [EOF]
//
