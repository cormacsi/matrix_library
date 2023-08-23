/**
 * @file s69_mult_number.c
 * @author cormacsi
 * @brief s69_mult_number
 * @version 0.1
 * @date 2023-03-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "s69_matrix.h"

/**
 * The product of the matrix A = m × n by the number λ
 * is the matrix B = m × n = λ × A whose elements are
 * defined by the equations B = λ × A(i,j).
 */
int s69_mult_number(matrix_t *A, double number, matrix_t *result) {
  int error = OK;
  if (_incorrect_matrix(A) || _incorrect_result(result))
    error = INCORRECT_MATRIX;
  else {
    error = s69_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }
  return error;
}
