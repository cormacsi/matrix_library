/**
 * @file s69_create_matrix.c
 * @author cormacsi
 * @brief s69_create_matrix
 * @version 0.1
 * @date 2023-03-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "s69_matrix.h"

/**
 * The function takes two integer numbers and a pointer to matrix
 * as input and creates a matrix of a specific size.
 */
int s69_create_matrix(int rows, int columns, matrix_t *result) {
  int error = _incorrect_result(result);
  if (!error) {
    _clear_matrix(result);
    if (rows < 1 || columns < 1)
      error = INCORRECT_MATRIX;
    else {
      result->rows = rows;
      result->columns = columns;
      result->matrix = calloc(rows, sizeof(double *));
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = calloc(columns, sizeof(double));
      }
    }
  }
  return error;
}
