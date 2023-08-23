#include "test_me.h"

START_TEST(eq_matrix_1) {
  int rows = 5;
  int columns = 5;
  matrix_t m, n;
  m.matrix = NULL;
  n.matrix = NULL;
  s69_create_matrix(rows, columns, &m);
  s69_create_matrix(rows, columns, &n);
  _input_matrix(&m);
  _copy_matrix(&m, &n);
  ck_assert_int_eq(s69_eq_matrix(&m, &n), SUCCESS);
  s69_remove_matrix(&m);
  s69_remove_matrix(&n);
}
END_TEST

START_TEST(eq_matrix_2) {
  int rows = 5;
  int columns = 5;
  matrix_t m, n;
  m.matrix = NULL;
  n.matrix = NULL;
  s69_create_matrix(rows, columns, &m);
  s69_create_matrix(rows, columns + 2, &n);
  _input_matrix(&m);
  _input_matrix(&n);
  ck_assert_int_eq(s69_eq_matrix(&m, &n), FAILURE);
  s69_remove_matrix(&m);
  s69_remove_matrix(&n);
}
END_TEST

START_TEST(eq_matrix_3) {
  int rows = 6;
  int columns = 6;
  matrix_t m, n;
  m.matrix = NULL, n.matrix = NULL;
  s69_create_matrix(rows, columns, &m);
  s69_create_matrix(rows - 2, columns, &n);
  _input_matrix(&m);
  _input_matrix(&n);
  ck_assert_int_eq(s69_eq_matrix(&m, &n), FAILURE);
  s69_remove_matrix(&m);
  s69_remove_matrix(&n);
}
END_TEST

START_TEST(eq_matrix_4) {
  int rows = 500;
  int columns = 500;
  matrix_t m, n;
  m.matrix = NULL, n.matrix = NULL;
  s69_create_matrix(rows, columns, &m);
  s69_create_matrix(rows, columns, &n);
  _input_matrix(&m);
  _copy_matrix(&m, &n);
  ck_assert_int_eq(s69_eq_matrix(&m, &n), SUCCESS);
  s69_remove_matrix(&m);
  s69_remove_matrix(&n);
}
END_TEST

START_TEST(eq_matrix_5) {
  int rows = 500;
  int columns = 500;
  matrix_t m, n;
  m.matrix = NULL, n.matrix = NULL;
  s69_create_matrix(rows, columns, &m);
  s69_create_matrix(rows, columns, &n);
  _input_matrix(&m);
  _copy_matrix(&m, &n);
  n.matrix[423][345] = 597;
  ck_assert_int_eq(s69_eq_matrix(&m, &n), FAILURE);
  s69_remove_matrix(&m);
  s69_remove_matrix(&n);
}
END_TEST

START_TEST(eq_matrix_6) {
  int rows = 6;
  int columns = 6;
  matrix_t m, n;
  m.matrix = NULL, n.matrix = NULL;
  m.rows = 0, m.columns = 0;
  n.rows = 0, n.columns = 0;
  s69_create_matrix(rows, columns, &m);
  ck_assert_int_eq(s69_eq_matrix(&m, &n), FAILURE);
  s69_remove_matrix(&m);
  s69_remove_matrix(&n);
}

START_TEST(eq_matrix_7) {
  int size = 8;
  matrix_t m, n;
  m.matrix = NULL, n.matrix = NULL;
  m.matrix = calloc(size, sizeof(double *));
  m.rows = 0, m.columns = 8;
  s69_create_matrix(size, size, &n);
  ck_assert_int_eq(s69_eq_matrix(&m, &n), FAILURE);
  if (m.matrix) free(m.matrix);
  s69_remove_matrix(&n);
}

START_TEST(eq_matrix_8) {
  int size = 8;
  matrix_t m, n;
  m.matrix = NULL, n.matrix = NULL;
  m.matrix = calloc(size, sizeof(double *));
  m.rows = 8, m.columns = 0;
  s69_create_matrix(size, size, &n);
  ck_assert_int_eq(s69_eq_matrix(&m, &n), FAILURE);
  if (m.matrix) free(m.matrix);
  s69_remove_matrix(&n);
}

Suite *test_eq_matrix(void) {
  Suite *s = suite_create("\033[36;1;43m-=S69_EQ_MATRIX=-\033[0m");
  TCase *tc = tcase_create("s69_eq_matrix_tc");

  tcase_add_test(tc, eq_matrix_1);
  tcase_add_test(tc, eq_matrix_2);
  tcase_add_test(tc, eq_matrix_3);
  tcase_add_test(tc, eq_matrix_4);
  tcase_add_test(tc, eq_matrix_5);
  tcase_add_test(tc, eq_matrix_6);
  tcase_add_test(tc, eq_matrix_7);
  tcase_add_test(tc, eq_matrix_8);

  suite_add_tcase(s, tc);
  return s;
}
