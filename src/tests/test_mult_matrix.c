#include "test_me.h"

START_TEST(mult_matrix_1) {
  int rows = 100;
  int columns = 0;
  matrix_t m, n, result;
  m.matrix = NULL, n.matrix = NULL, result.matrix = NULL;
  s69_create_matrix(rows, columns, &m);
  s69_create_matrix(rows, columns, &n);
  ck_assert_int_eq(s69_mult_matrix(&m, &n, &result), INCORRECT_MATRIX);
  s69_remove_matrix(&m);
  s69_remove_matrix(&n);
}
END_TEST

START_TEST(mult_matrix_2) {
  int rows = 0;
  int columns = 10;
  matrix_t m, n, result;
  m.matrix = NULL, n.matrix = NULL, result.matrix = NULL;
  s69_create_matrix(rows, columns, &m);
  s69_create_matrix(rows, columns, &n);
  ck_assert_int_eq(s69_mult_matrix(&m, &n, &result), INCORRECT_MATRIX);
  s69_remove_matrix(&m);
  s69_remove_matrix(&n);
}
END_TEST

START_TEST(mult_matrix_3) {
  int rows = 100;
  int columns = 100;
  matrix_t m, n, result;
  m.matrix = NULL, n.matrix = NULL, result.matrix = NULL;
  s69_create_matrix(rows, columns, &m);
  n.rows = rows;
  n.columns = columns;
  n.matrix = NULL;
  ck_assert_int_eq(s69_mult_matrix(&m, &n, &result), INCORRECT_MATRIX);
  s69_remove_matrix(&m);
  s69_remove_matrix(&n);
}
END_TEST

START_TEST(mult_matrix_4) {
  int rows = 100;
  int columns = 100;
  matrix_t m, n, result;
  m.matrix = NULL, n.matrix = NULL, result.matrix = NULL;
  s69_create_matrix(rows, columns, &m);
  s69_create_matrix(rows, columns, &n);
  ck_assert_int_eq(s69_mult_matrix(&m, &n, &result), OK);
  s69_remove_matrix(&m);
  s69_remove_matrix(&n);
  s69_remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_5) {
  int rows = 100;
  int columns = 100;
  matrix_t m, n, result;
  m.matrix = NULL, n.matrix = NULL, result.matrix = NULL;
  s69_create_matrix(rows, columns + 3, &m);
  s69_create_matrix(rows - 3, columns, &n);
  ck_assert_int_eq(s69_mult_matrix(&m, &n, &result), CALCULATION_ERROR);
  s69_remove_matrix(&m);
  s69_remove_matrix(&n);
}
END_TEST

START_TEST(mult_matrix_6) {
  int a_rows = 2;
  int a_columns = 3;
  int b_rows = 3;
  int b_columns = 2;
  matrix_t m, n, result, true_res;
  m.matrix = NULL, n.matrix = NULL, result.matrix = NULL,
  true_res.matrix = NULL;

  s69_create_matrix(a_rows, a_columns, &m);
  m.matrix[0][0] = 2;
  m.matrix[0][1] = 1;
  m.matrix[0][2] = 1;
  m.matrix[1][0] = 3;
  m.matrix[1][1] = 0;
  m.matrix[1][2] = 1;

  s69_create_matrix(b_rows, b_columns, &n);
  n.matrix[0][0] = 3;
  n.matrix[0][1] = 1;
  n.matrix[1][0] = 2;
  n.matrix[1][1] = 1;
  n.matrix[2][0] = 1;
  n.matrix[2][1] = 0;

  s69_create_matrix(a_rows, b_columns, &true_res);
  true_res.matrix[0][0] = 9;
  true_res.matrix[0][1] = 3;
  true_res.matrix[1][0] = 10;
  true_res.matrix[1][1] = 3;

  ck_assert_int_eq(s69_mult_matrix(&m, &n, &result), OK);
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      ck_assert_double_eq(result.matrix[i][j], true_res.matrix[i][j]);
    }
  }
  s69_remove_matrix(&m);
  s69_remove_matrix(&n);
  s69_remove_matrix(&true_res);
  s69_remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_7) {
  int a_rows = 3;
  int a_columns = 2;
  int b_rows = 2;
  int b_columns = 3;
  matrix_t m, n, result, true_res;
  m.matrix = NULL, n.matrix = NULL, result.matrix = NULL,
  true_res.matrix = NULL;

  s69_create_matrix(a_rows, a_columns, &m);
  m.matrix[0][0] = 1;
  m.matrix[0][1] = 4;
  m.matrix[1][0] = 2;
  m.matrix[1][1] = 5;
  m.matrix[2][0] = 3;
  m.matrix[2][1] = 6;

  s69_create_matrix(b_rows, b_columns, &n);
  n.matrix[0][0] = 1;
  n.matrix[0][1] = -1;
  n.matrix[0][2] = 1;
  n.matrix[1][0] = 2;
  n.matrix[1][1] = 3;
  n.matrix[1][2] = 4;

  s69_create_matrix(a_rows, b_columns, &true_res);
  true_res.matrix[0][0] = 9;
  true_res.matrix[0][1] = 11;
  true_res.matrix[0][2] = 17;
  true_res.matrix[1][0] = 12;
  true_res.matrix[1][1] = 13;
  true_res.matrix[1][2] = 22;
  true_res.matrix[2][0] = 15;
  true_res.matrix[2][1] = 15;
  true_res.matrix[2][2] = 27;

  ck_assert_int_eq(s69_mult_matrix(&m, &n, &result), OK);
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      ck_assert_double_eq(result.matrix[i][j], true_res.matrix[i][j]);
    }
  }
  s69_remove_matrix(&m);
  s69_remove_matrix(&n);
  s69_remove_matrix(&true_res);
  s69_remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_8) {
  int size = 8;
  matrix_t m, n, result;
  m.matrix = NULL, n.matrix = NULL, result.matrix = NULL;
  s69_create_matrix(size, size, &m);
  s69_create_matrix(size, size, &n);
  ck_assert_int_eq(s69_mult_matrix(NULL, &n, &result), INCORRECT_MATRIX);
  ck_assert_int_eq(s69_mult_matrix(&m, NULL, &result), INCORRECT_MATRIX);
  ck_assert_int_eq(s69_mult_matrix(NULL, NULL, &result), INCORRECT_MATRIX);
  ck_assert_int_eq(s69_mult_matrix(&m, &n, NULL), INCORRECT_MATRIX);
  ck_assert_int_eq(s69_mult_matrix(&m, NULL, NULL), INCORRECT_MATRIX);
  ck_assert_int_eq(s69_mult_matrix(NULL, &n, NULL), INCORRECT_MATRIX);
  s69_remove_matrix(&m);
  s69_remove_matrix(&n);
}
END_TEST

Suite *test_mult_matrix(void) {
  Suite *s = suite_create("\033[36;1;43m-=S69_MULT_MATRIX=-\033[0m");
  TCase *tc = tcase_create("s69_mult_matrix_tc");

  tcase_add_test(tc, mult_matrix_1);
  tcase_add_test(tc, mult_matrix_2);
  tcase_add_test(tc, mult_matrix_3);
  tcase_add_test(tc, mult_matrix_4);
  tcase_add_test(tc, mult_matrix_5);
  tcase_add_test(tc, mult_matrix_6);
  tcase_add_test(tc, mult_matrix_7);
  tcase_add_test(tc, mult_matrix_8);

  suite_add_tcase(s, tc);
  return s;
}
