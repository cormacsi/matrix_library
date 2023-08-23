/**
 * @file s69_remove_matrix.c
 * @author your name (you@domain.com)
 * @brief s69_remove_matrix
 * @version 0.1
 * @date 2023-03-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "s69_matrix.h"

/**
 * The function takes a pointer to the matrix struct,
 * checks for the existence of a pointer and cleans it if pointers and values
 * exist.
 */
void s69_remove_matrix(matrix_t *A) {
  if (A) {
    if (A->matrix) {
      for (int i = 0; i < A->rows; i++) {
        if (A->matrix[i]) free(A->matrix[i]);
        A->matrix[i] = NULL;
      }
      free(A->matrix);
      A->matrix = NULL;
    }
    if (A->rows) A->rows = 0;
    if (A->columns) A->columns = 0;
  }
}
