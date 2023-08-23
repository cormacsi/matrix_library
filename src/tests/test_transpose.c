#include "test_me.h"

START_TEST(transpose_1) {
  int rows = 0;
  int columns = 5;
  matrix_t m, result;
  m.matrix = NULL, result.matrix = NULL;
  s69_create_matrix(rows, columns, &m);
  ck_assert_int_eq(s69_transpose(&m, &result), INCORRECT_MATRIX);
  s69_remove_matrix(&m);
}
END_TEST

START_TEST(transpose_2) {
  int rows = 5;
  int columns = 0;
  matrix_t m, result;
  m.matrix = NULL, result.matrix = NULL;
  s69_create_matrix(rows, columns, &m);
  ck_assert_int_eq(s69_transpose(&m, &result), INCORRECT_MATRIX);
  s69_remove_matrix(&m);
}
END_TEST

START_TEST(transpose_3) {
  int rows = 5;
  int columns = 5;
  matrix_t m, result;
  m.matrix = NULL, result.matrix = NULL;
  m.rows = rows;
  m.columns = columns;
  ck_assert_int_eq(s69_transpose(&m, &result), INCORRECT_MATRIX);
  s69_remove_matrix(&m);
}
END_TEST

START_TEST(transpose_4) {
  int rows = 3;
  int columns = 2;
  matrix_t m, result, true_res;
  m.matrix = NULL, result.matrix = NULL, true_res.matrix = NULL;

  s69_create_matrix(rows, columns, &m);
  m.matrix[0][0] = 1;
  m.matrix[0][1] = 4;
  m.matrix[1][0] = 2;
  m.matrix[1][1] = 5;
  m.matrix[2][0] = 3;
  m.matrix[2][1] = 6;

  s69_create_matrix(columns, rows, &true_res);
  true_res.matrix[0][0] = 1;
  true_res.matrix[0][1] = 2;
  true_res.matrix[0][2] = 3;
  true_res.matrix[1][0] = 4;
  true_res.matrix[1][1] = 5;
  true_res.matrix[1][2] = 6;

  ck_assert_int_eq(s69_transpose(&m, &result), OK);
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      ck_assert_double_eq(result.matrix[i][j], true_res.matrix[i][j]);
    }
  }
  s69_remove_matrix(&m);
  s69_remove_matrix(&true_res);
  s69_remove_matrix(&result);
}
END_TEST

START_TEST(transpose_5) {
  int rows = 300;
  int columns = 200;
  double num = 5;
  matrix_t m, result, true_res;
  m.matrix = NULL, result.matrix = NULL, true_res.matrix = NULL;

  s69_create_matrix(rows, columns, &m);
  _input_some_number(&m, num);
  m.matrix[277][189] = 2;

  s69_create_matrix(columns, rows, &true_res);
  _input_some_number(&true_res, num);
  true_res.matrix[189][277] = 2;

  ck_assert_int_eq(s69_transpose(&m, &result), OK);
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      ck_assert_double_eq(result.matrix[i][j], true_res.matrix[i][j]);
    }
  }
  s69_remove_matrix(&m);
  s69_remove_matrix(&true_res);
  s69_remove_matrix(&result);
}
END_TEST

START_TEST(transpose_6) {
  int size = 10;
  matrix_t m, result;
  m.matrix = NULL, result.matrix = NULL;
  s69_create_matrix(size, size, &m);
  ck_assert_int_eq(s69_transpose(&m, NULL), INCORRECT_MATRIX);
  ck_assert_int_eq(s69_transpose(NULL, &result), INCORRECT_MATRIX);
  ck_assert_int_eq(s69_transpose(NULL, NULL), INCORRECT_MATRIX);
  s69_remove_matrix(&m);
}
END_TEST

Suite *test_transpose(void) {
  Suite *s = suite_create("\033[36;1;43m-=S69_TRANSPOSE=-\033[0m");
  TCase *tc = tcase_create("s69_transpose_tc");

  tcase_add_test(tc, transpose_1);
  tcase_add_test(tc, transpose_2);
  tcase_add_test(tc, transpose_3);
  tcase_add_test(tc, transpose_4);
  tcase_add_test(tc, transpose_5);
  tcase_add_test(tc, transpose_6);

  suite_add_tcase(s, tc);
  return s;
}
