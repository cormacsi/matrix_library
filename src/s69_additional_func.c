/**
 * @file s69_additional_func.c
 * @author cormacsi
 * @brief Additional functions for tests and checks
 * @version 0.1
 * @date 2023-03-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "s69_matrix.h"

/**
 * The additional function for cleaning the values of the matrix.
 */
void _clear_matrix(matrix_t *A) {
  A->matrix = NULL;
  A->rows = 0;
  A->columns = 0;
}

/**
 * The function checks the pointer that gets from the user for existance in case
 * if it is NULL.
 */
int _incorrect_result(const void *result) { return !result; }

/**
 * The function checks the pointer to the existing matrix_t struct type (with
 * values) that it gets from the user for existance in case if it is NULL or the
 * pointer to the matrix is NULL or the size of the matrix is incorrect.
 */
int _incorrect_matrix(matrix_t *A) {
  return !A || !A->matrix || A->rows <= 0 || A->columns <= 0;
}

/**
 * The function takes an existing matrix as an input
 * and puts a randomly generated number to every position
 * (value) of the matrix.
 */
void _input_matrix(matrix_t *A) {
  srand((unsigned int)time(NULL));
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      A->matrix[i][j] = ((float)rand() / (float)(RAND_MAX));
    }
  }
}

/**
 * The function takes an existing matrix and a number of the
 * type double as an input and puts the number to every
 * position (value) of the matrix.
 */
void _input_some_number(matrix_t *A, double num) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      A->matrix[i][j] = num;
    }
  }
}

/**
 * Copies the first matrix to the second exicting matrix of the same size.
 * The function is only used for Unit-testing.
 */
void _copy_matrix(matrix_t *A, matrix_t *B) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      B->matrix[i][j] = A->matrix[i][j];
    }
  }
}
