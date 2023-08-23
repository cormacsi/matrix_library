/**
 * @file s69_transpose.c
 * @author cormacsi
 * @brief s69_transpose
 * @version 0.1
 * @date 2023-03-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "s69_matrix.h"

/**
 * The transpose of matrix A is in switching its rows
 *  with its columns with their numbers retained.
 */
int s69_transpose(matrix_t *A, matrix_t *result) {
  int error = OK;
  if (_incorrect_matrix(A) || _incorrect_result(result)) {
    error = INCORRECT_MATRIX;
  } else {
    error = s69_create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = A->matrix[j][i];
      }
    }
  }
  return error;
}
