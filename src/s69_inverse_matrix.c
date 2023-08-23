/**
 * @file s69_inverse_matrix.c
 * @author cormacsi
 * @brief s69_inverse_matrix
 * @version 0.1
 * @date 2023-03-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "s69_matrix.h"

/**
 * Making the calcuation to inverse the existing matrix.
 *  The function creates the temporary matrix to store the minor values,
 * transpose it and then fills in the values of the result matrix.
 */
int _inverse(matrix_t *A, matrix_t *result, double determinant) {
  matrix_t temp;
  temp.matrix = NULL;
  s69_create_matrix(A->rows, A->columns, &temp);
  _find_minor(A, &temp);
  int error = s69_transpose(&temp, result);
  s69_remove_matrix(&temp);
  for (int i = 0; i < result->rows; i++) {
    for (int j = 0; j < result->columns; j++) {
      result->matrix[i][j] /= (double)determinant;
    }
  }
  return error;
}

/**
 * A matrix A to the power of -1 is called the inverse of
 * a square matrix A if the product of these matrices equals the identity
 * matrix. If the determinant of the matrix is zero, then it does not have an
 * inverse.
 */
int s69_inverse_matrix(matrix_t *A, matrix_t *result) {
  int error = OK;
  if (_incorrect_matrix(A) || _incorrect_result(result)) {
    error = INCORRECT_MATRIX;
  } else {
    double determinant = 0.;
    s69_determinant(A, &determinant);
    if (determinant == 0) {
      error = CALCULATION_ERROR;
    } else if (A->rows == 1) {
      s69_create_matrix(A->rows, A->columns, result);
      result->matrix[0][0] = 1 / A->matrix[0][0];
    } else {
      error = _inverse(A, result, determinant);
    }
  }
  return error;
}
