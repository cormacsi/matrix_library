/**
 * @file s69_calc_complements.c
 * @author cormacsi
 * @brief s69_calc_complements
 * @version 0.1
 * @date 2023-03-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "s69_matrix.h"

/**
 * The main purpose of this function is creation of an extra matrix.
 * The smaller matrix would not include the row and the column it gets as input.
 */
void _minor_matrix(int row, int column, matrix_t *A, matrix_t *result) {
  s69_create_matrix(A->rows - 1, A->columns - 1, result);
  for (int i = 0; i < result->rows; i++) {
    int m = (i >= row) ? i + 1 : i;
    for (int j = 0; j < result->columns; j++) {
      int n = (j >= column) ? j + 1 : j;
      result->matrix[i][j] = A->matrix[m][n];
    }
  }
}

/**
 * Additional function to find minor of a bigger matrix.
 * It gets the determinant for every position in the matrix by creating a
 * smaller extra-matrix, writes it to the result pointer and removes the
 * extra-matrix every iteration.
 */
void _find_minor(matrix_t *A, matrix_t *result) {
  if (A->rows == 1) {
    result->matrix[0][0] = 1;
  } else if (A->rows == 2) {
    result->matrix[0][0] = A->matrix[1][1];
    result->matrix[0][1] = -A->matrix[1][0];
    result->matrix[1][0] = -A->matrix[0][1];
    result->matrix[1][1] = A->matrix[0][0];
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        double determ = 0;
        matrix_t temp;
        _minor_matrix(i, j, A, &temp);
        s69_determinant(&temp, &determ);
        result->matrix[i][j] = determ * pow(-1, i + j);
        s69_remove_matrix(&temp);
      }
    }
  }
}

/**
 * Minor M(i,j) is a (n-1)-order determinant obtained by deleting
 * out the i-th row and the j-th column from the matrix A.
 * The algebraic complement of a matrix element is the value of the minor
 * multiplied by -1^(i+j).
 */
int s69_calc_complements(matrix_t *A, matrix_t *result) {
  int error = OK;
  if (_incorrect_matrix(A) || _incorrect_result(result)) {
    error = INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    error = CALCULATION_ERROR;
  } else {
    s69_create_matrix(A->rows, A->columns, result);
    _find_minor(A, result);
  }
  return error;
}
