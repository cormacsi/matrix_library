/**
 * @file s69_sum_matrix.c
 * @author cormacsi
 * @brief s69_sum_matrix
 * @version 0.1
 * @date 2023-03-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "s69_matrix.h"

/**
 * The sum of two matrices A = m × n and B = m × n of the same size
 * is a matrix C = m × n = A + B of the same size whose elements
 * are defined by the equations C(i,j) = A(i,j) + B(i,j).
 */
int s69_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = OK;
  if (_incorrect_matrix(A) || _incorrect_matrix(B) ||
      _incorrect_result(result)) {
    error = INCORRECT_MATRIX;
  } else if (A->rows != B->rows || A->columns != B->columns) {
    error = CALCULATION_ERROR;
  } else {
    error = s69_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  }
  return error;
}
