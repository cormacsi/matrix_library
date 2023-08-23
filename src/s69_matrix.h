/**
 * @file s69_matrix.h
 * @author cormacsi
 * @brief Head file for the project
 * @version 0.1
 * @date 2023-03-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SRC_s69_MATRIX_H
#define SRC_s69_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * @addtogroup Defined Variables
 * @brief Defined global variables
 * @{
 */
#define FAILURE 0 /**< The integer value of a failure result */
#define SUCCESS 1 /**< The integer value of a success result */

/** @brief The enum type of the result values.
 * The result values are OK (zero), INCORRECT_MATRIX (one), CALCULATION_ERROR
 * (two).
 */
enum result { OK, INCORRECT_MATRIX, CALCULATION_ERROR };

/** @brief The struct type matrix consists of a double pointer to the matrix,
 * the integer value of the matrix's rows and the integer value of the matrix's
 * columns.
 */
typedef struct matrix_struct {
  double **matrix; /**< Double pointr to the matrix of the type double */
  int rows;        /**< The matrix's rows */
  int columns;     /**< The matrix's columns */
} matrix_t;
/**
 * @}
 *
 */

/**
 * @addtogroup Matrix Operations
 * @brief Main functions for all operations with matrices
 * @{
 */

/**
 * @brief Creating matrices
 * @param rows The integer number for rows of a matrix
 * @param columns The integer number for columns of a matrix
 * @param result The pointer to which the result of the created matrix will be
 * written
 * @retval 0 OK
 * @retval 1 Error, incorrect matrix
 * @retval 2 Calculation error
 */
int s69_create_matrix(int rows, int columns, matrix_t *result);

/**
 * @brief Cleaning of matrices
 * @param A The pointer to the struct type matrix_t
 */
void s69_remove_matrix(matrix_t *A);

/**
 * @brief Matrix comparison
 * @param A The pointer to the first matrix to compare
 * @param B The pointer to the second matrix to compare
 * @retval 0 FAILURE
 * @retval 1 SUCCESS
 */
int s69_eq_matrix(matrix_t *A, matrix_t *B);

/**
 * @brief Adding matrices
 * @param A The pointer to the first matrix to add
 * @param B The pointer to the second matrix to add
 * @param result The pointer to which the result of the created matrix will be
 * written
 * @retval 0 OK
 * @retval 1 Error, incorrect matrix
 * @retval 2 Calculation error
 */
int s69_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

/**
 * @brief Subtracting matrices
 * @param A The minuend
 * @param B The subtrahend
 * @param result The pointer to which the result of the created matrix will be
 * written
 * @retval 0 OK
 * @retval 1 Error, incorrect matrix
 * @retval 2 Calculation error
 */
int s69_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

/**
 * @brief Matrix multiplication by scalar
 * @param A The pointer to the matrix to multiply
 * @param number The scalar: an integer value to multiply each matrix's value
 * @param result The pointer to which the result of the created matrix will be
 * written
 * @retval 0 OK
 * @retval 1 Error, incorrect matrix
 * @retval 2 Calculation error
 */
int s69_mult_number(matrix_t *A, double number, matrix_t *result);

/**
 * @brief Multiplication of two matrices
 * @param A The pointer to the first matrix to multiply
 * @param B The pointer to the second matrix to multiply
 * @param result The pointer to which the result of the created matrix will be
 * written
 * @retval 0 OK
 * @retval 1 Error, incorrect matrix
 * @retval 2 Calculation error
 */
int s69_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

/**
 * @brief Matrix transpose
 * @param A The pointer to the matrix to transpose
 * @param result The pointer to which the result of the created matrix will be
 * written
 * @retval 0 OK
 * @retval 1 Error, incorrect matrix
 * @retval 2 Calculation error
 */
int s69_transpose(matrix_t *A, matrix_t *result);

/**
 * @brief Minor of matrix and matrix of algebraic complements
 * @param A The pointer to the matrix
 * @param result The pointer to which the result of the created matrix will be
 * written
 * @retval 0 OK
 * @retval 1 Error, incorrect matrix
 * @retval 2 Calculation error
 */
int s69_calc_complements(matrix_t *A, matrix_t *result);

/**
 * @brief Matrix determinant
 * @param A The pointer to the matrix to find the determinant
 * @param result The pointer to which the result will be written
 * @retval 0 OK
 * @retval 1 Error, incorrect matrix
 * @retval 2 Calculation error
 */
int s69_determinant(matrix_t *A, double *result);

/**
 * @brief Inverse of the matrix
 * @param A The pointer to the matrix to inverse
 * @param result The pointer to which the result of the created matrix will be
 * written
 * @retval 0 OK
 * @retval 1 Error, incorrect matrix
 * @retval 2 Calculation error
 */
int s69_inverse_matrix(matrix_t *A, matrix_t *result);

/**
 * @}
 *
 */

/**
 * @addtogroup Additional Functions
 * @brief Additional functions for tests and checks
 * @{
 */

/**
 * @brief Cleaning the matrix
 * @param A The pointer to the matrix
 */
void _clear_matrix(matrix_t *A);

/**
 * @brief Matrix check for correctness and existence
 * @param A The pointer to the matrix
 * @retval 0 Correct
 * @retval 1 Incorrect
 */
int _incorrect_matrix(matrix_t *A);

/**
 * @brief The pointer check for existence
 * @param result The const pointer to the result value
 * @retval 0 Correct
 * @retval 1 Incorrect
 */
int _incorrect_result(const void *result);

/**
 * @brief Fills random values in every position of the matrix
 * @param A The pointer to the matrix
 */
void _input_matrix(matrix_t *A);

/**
 * @brief Input the specific number to every position in the matrix
 * @param A The pointer to the matrix
 * @param num The number of the type double
 */
void _input_some_number(matrix_t *A, double num);

/**
 * @brief Copy the values of the matrix to another matrix
 * @param A The pointer to the matrix to copy
 * @param B The pointer to which the matrix is copied
 */
void _copy_matrix(matrix_t *A, matrix_t *B);

/**
 * @brief The function for the recursive way to find the determinant
 * @param A The pointer to the matrix
 * @return double The determinant of the specific smaller matrix
 */
double _recursive_determ(matrix_t *A);

/**
 * @brief Creation of a smaller matrix excluding a specific row and a specific
 * column
 * @param row The specific row to exclude
 * @param column The specific column to exclude
 * @param A The pointer to the matrix
 * @param result The pointer to which the result of the created matrix will be
 * written
 */
void _minor_matrix(int row, int column, matrix_t *A, matrix_t *result);

/**
 * @brief Finding the minors of the matrix
 * @param A The pointer to the matrix
 * @param result The pointer to which the result of the created matrix will be
 * written
 */
void _find_minor(matrix_t *A, matrix_t *result);

/**
 * @}
 *
 */

#endif /* s69_MATRIX_H */