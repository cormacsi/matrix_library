/**
 * @file s69_eq_matrix.c
 * @author cormacsi
 * @brief s69_eq_matrix
 * @version 0.1
 * @date 2023-03-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "s69_matrix.h"

/**
 * The function takes two pointers to matrices, checks both of them for
 * correctness and equal values. The matrices A, B are equal |A = B| if they
 * have the same dimensions and the corresponding elements are identical, thus
 * for all i and j: A(i,j) = B(i,j).
 */
int s69_eq_matrix(matrix_t *A, matrix_t *B) {
  int result;
  if (_incorrect_matrix(A) || _incorrect_matrix(B))
    result = FAILURE;
  else if (A->rows != B->rows || A->columns != B->columns)
    result = FAILURE;
  else {
    result = SUCCESS;
    for (int i = 0; i < A->rows && result; i++) {
      for (int j = 0; j < A->columns && result; j++) {
        double m = fabs(A->matrix[i][j] - B->matrix[i][j]);
        if (m >= 1e-06) result = FAILURE;
      }
    }
  }
  return result;
}