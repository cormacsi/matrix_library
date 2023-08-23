/**
 * @file s69_determinant.c
 * @author cormacsi
 * @brief s69_determinant
 * @version 0.1
 * @date 2023-03-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "s69_matrix.h"

/**
 * The function recursively finds the determinant of the matrix
 * while it's size is more than or equal to two rows and two columns.
 */
double _recursive_determ(matrix_t *A) {
  double determinant = 0;
  if (A->rows == 2) {
    determinant =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else {
    for (int i = 0; i < A->rows; i++) {
      matrix_t temp;
      _minor_matrix(0, i, A, &temp);
      determinant += A->matrix[0][i] * pow(-1, i) * _recursive_determ(&temp);
      s69_remove_matrix(&temp);
    }
  }
  return determinant;
}

/**
 * The determinant of a matrix equals the sum of the products of
 * elements of the row (column) and the corresponding algebraic complements.
 * The determinant can only be calculated for a square matrix.
 */
int s69_determinant(matrix_t *A, double *result) {
  int error = OK;
  if (_incorrect_matrix(A) || _incorrect_result(result)) {
    error = INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    error = CALCULATION_ERROR;
  } else if (A->rows == 1) {
    *result = A->matrix[0][0];
  } else {
    *result = _recursive_determ(A);
  }
  return error;
}
