#include "test_me.h"

START_TEST(sum_matrix_1) {
  int rows = 5;
  int columns = 5;
  matrix_t m, n, result;
  m.matrix = NULL, n.matrix = NULL, result.matrix = NULL;
  m.rows = 0, m.columns = 0;
  n.rows = 0, n.columns = 0;
  s69_create_matrix(rows, columns, &m);
  s69_create_matrix(rows, columns - 2, &n);
  _input_matrix(&m);
  _input_matrix(&n);
  ck_assert_int_eq(s69_sum_matrix(&m, &n, &result), CALCULATION_ERROR);
  s69_remove_matrix(&m);
  s69_remove_matrix(&n);
}
END_TEST

START_TEST(sum_matrix_2) {
  int rows = 5;
  int columns = 5;
  matrix_t m, n, result;
  m.matrix = NULL, n.matrix = NULL, result.matrix = NULL;
  s69_create_matrix(rows, columns, &m);
  s69_create_matrix(rows - 2, columns, &n);
  _input_matrix(&m);
  _input_matrix(&n);
  ck_assert_int_eq(s69_sum_matrix(&m, &n, &result), CALCULATION_ERROR);
  s69_remove_matrix(&m);
  s69_remove_matrix(&n);
}
END_TEST

START_TEST(sum_matrix_3) {
  int rows = 6;
  int columns = 6;
  matrix_t m, n, result;
  m.matrix = NULL, n.matrix = NULL, result.matrix = NULL;
  m.rows = 0, m.columns = 0;
  n.rows = 0, n.columns = 0;
  s69_create_matrix(rows, columns, &m);
  ck_assert_int_eq(s69_sum_matrix(&m, &n, &result), INCORRECT_MATRIX);
  s69_remove_matrix(&m);
}

START_TEST(sum_matrix_4) {
  int rows = 6;
  int columns = 6;
  matrix_t m, n, result;
  m.matrix = NULL, n.matrix = NULL, result.matrix = NULL;
  m.rows = 0, m.columns = 0;
  n.rows = 0, n.columns = 0;
  s69_create_matrix(rows, columns, &n);
  ck_assert_int_eq(s69_sum_matrix(&m, &n, &result), INCORRECT_MATRIX);
  s69_remove_matrix(&n);
}

START_TEST(sum_matrix_5) {
  int rows = 0;
  int columns = 6;
  matrix_t m, n, result;
  m.matrix = NULL, n.matrix = NULL, result.matrix = NULL;
  s69_create_matrix(rows, columns, &m);
  s69_create_matrix(rows, columns, &n);
  n.columns = columns;
  ck_assert_int_eq(s69_sum_matrix(&m, &n, &result), INCORRECT_MATRIX);
  s69_remove_matrix(&m);
  s69_remove_matrix(&n);
}

START_TEST(sum_matrix_6) {
  int size = 10;
  matrix_t m, n, result;
  s69_create_matrix(size, size, &m);
  s69_create_matrix(size, size, &n);
  ck_assert_int_eq(s69_sum_matrix(NULL, &n, &result), INCORRECT_MATRIX);
  ck_assert_int_eq(s69_sum_matrix(&m, NULL, &result), INCORRECT_MATRIX);
  ck_assert_int_eq(s69_sum_matrix(&m, &n, NULL), INCORRECT_MATRIX);
  s69_remove_matrix(&m);
  s69_remove_matrix(&n);
}

START_TEST(sum_matrix_7) {
  int rows = 15;
  int columns = 10;
  double d = 4000;
  matrix_t m, n, result;
  m.matrix = NULL, n.matrix = NULL, result.matrix = NULL;
  s69_create_matrix(rows, columns, &m);
  s69_create_matrix(rows, columns, &n);
  _input_some_number(&m, d);
  _input_some_number(&n, d);
  ck_assert_int_eq(s69_sum_matrix(&m, &n, &result), OK);
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      ck_assert_double_eq(result.matrix[i][j], d * 2);
    }
  }
  s69_remove_matrix(&m);
  s69_remove_matrix(&n);
  s69_remove_matrix(&result);
}
END_TEST

Suite *test_sum_matrix(void) {
  Suite *s = suite_create("\033[36;1;43m-=S69_SUM_MATRIX=-\033[0m");
  TCase *tc = tcase_create("s69_sum_matrix_tc");

  tcase_add_test(tc, sum_matrix_1);
  tcase_add_test(tc, sum_matrix_2);
  tcase_add_test(tc, sum_matrix_3);
  tcase_add_test(tc, sum_matrix_4);
  tcase_add_test(tc, sum_matrix_5);
  tcase_add_test(tc, sum_matrix_6);
  tcase_add_test(tc, sum_matrix_7);

  suite_add_tcase(s, tc);
  return s;
}
