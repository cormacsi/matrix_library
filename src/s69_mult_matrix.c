/**
 * @file s69_mult_matrix.c
 * @author cormacsi
 * @brief s69_mult_matrix
 * @version 0.1
 * @date 2023-03-02
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "s69_matrix.h"

/**
 * The product of A = m × k by B = k × n is a matrix C = m × n = A × B
 *  of size m × n whose elements are defined by the equation C(i,j)
 * = A(i,1) × B(1,j) + A(i,2) × B(2,j) + ... + A(i,k) × B(k,j).
 */
int s69_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = OK;
  if (_incorrect_matrix(A) || _incorrect_matrix(B) ||
      _incorrect_result(result)) {
    error = INCORRECT_MATRIX;
  } else if (A->columns != B->rows) {
    error = CALCULATION_ERROR;
  } else {
    error = s69_create_matrix(A->rows, B->columns, result);
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        for (int k = 0; k < A->columns; k++) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  }
  return error;
}
