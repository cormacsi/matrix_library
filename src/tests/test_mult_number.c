#include "test_me.h"

START_TEST(mult_number_1) {
  int rows = 100;
  int columns = 0;
  double d = 4;
  matrix_t m, result;
  m.matrix = NULL, result.matrix = NULL;
  s69_create_matrix(rows, columns, &m);
  ck_assert_int_eq(s69_mult_number(&m, d, &result), INCORRECT_MATRIX);
  s69_remove_matrix(&m);
}
END_TEST

START_TEST(mult_number_2) {
  int rows = 100;
  int columns = 0;
  double d = 4;
  matrix_t m, result;
  m.matrix = NULL, result.matrix = NULL;
  s69_create_matrix(rows, columns, &m);
  _input_some_number(&m, d);
  ck_assert_int_eq(s69_mult_number(&m, d, &result), INCORRECT_MATRIX);
  s69_remove_matrix(&m);
}

START_TEST(mult_number_3) {
  int rows = 100;
  int columns = 10;
  double d = 4;
  matrix_t m, result;
  m.matrix = NULL, result.matrix = NULL;
  m.rows = rows;
  m.columns = columns;
  ck_assert_int_eq(s69_mult_number(&m, d, &result), INCORRECT_MATRIX);
  s69_remove_matrix(&m);
}

START_TEST(mult_number_4) {
  int rows = 100;
  int columns = 100;
  double d = 4;
  matrix_t m, result;
  m.matrix = NULL, result.matrix = NULL;
  s69_create_matrix(rows, columns, &m);
  ck_assert_int_eq(s69_mult_number(&m, d, &result), OK);
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      ck_assert_double_eq(result.matrix[i][j], 0);
    }
  }
  s69_remove_matrix(&m);
  s69_remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_5) {
  int rows = 20;
  int columns = 20;
  double d = 63.4;
  matrix_t m, result;
  m.matrix = NULL, result.matrix = NULL;
  s69_create_matrix(rows, columns, &m);
  _input_some_number(&m, d);
  ck_assert_int_eq(s69_mult_number(&m, d, &result), OK);
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      ck_assert_double_eq(result.matrix[i][j], d * d);
    }
  }
  s69_remove_matrix(&m);
  s69_remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_6) {
  int rows = 20;
  int columns = 20;
  double d = 84, n = 32;
  matrix_t m, result;
  m.matrix = NULL, result.matrix = NULL;
  s69_create_matrix(rows, columns, &m);
  _input_some_number(&m, d);
  ck_assert_int_eq(s69_mult_number(&m, n, &result), OK);
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      ck_assert_double_eq(result.matrix[i][j], d * n);
    }
  }
  s69_remove_matrix(&m);
  s69_remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_7) {
  int rows = 50;
  int columns = 50;
  double d = 84;
  matrix_t m, result;
  m.matrix = NULL, result.matrix = NULL;
  s69_create_matrix(rows, columns, &m);
  _input_matrix(&m);
  ck_assert_int_eq(s69_mult_number(&m, d, &result), OK);
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      ck_assert_double_eq(result.matrix[i][j], d * m.matrix[i][j]);
    }
  }
  s69_remove_matrix(&m);
  s69_remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_8) {
  int size = 8;
  double d = 4;
  matrix_t m, result;
  m.matrix = NULL, result.matrix = NULL;
  s69_create_matrix(size, size, &m);
  ck_assert_int_eq(s69_mult_number(NULL, d, &result), INCORRECT_MATRIX);
  ck_assert_int_eq(s69_mult_number(&m, d, NULL), INCORRECT_MATRIX);
  ck_assert_int_eq(s69_mult_number(NULL, d, NULL), INCORRECT_MATRIX);
  s69_remove_matrix(&m);
}
END_TEST

Suite *test_mult_number(void) {
  Suite *s = suite_create("\033[36;1;43m-=S69_MULT_NUMBER=-\033[0m");
  TCase *tc = tcase_create("s69_mult_number_tc");

  tcase_add_test(tc, mult_number_1);
  tcase_add_test(tc, mult_number_2);
  tcase_add_test(tc, mult_number_3);
  tcase_add_test(tc, mult_number_4);
  tcase_add_test(tc, mult_number_5);
  tcase_add_test(tc, mult_number_6);
  tcase_add_test(tc, mult_number_7);
  tcase_add_test(tc, mult_number_8);

  suite_add_tcase(s, tc);
  return s;
}
