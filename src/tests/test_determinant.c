#include "test_me.h"

START_TEST(determinant_1) {
  int rows = 100;
  int columns = 0;
  matrix_t m;
  m.matrix = NULL;
  double result = 0;
  s69_create_matrix(rows, columns, &m);
  ck_assert_int_eq(s69_determinant(&m, &result), INCORRECT_MATRIX);
  s69_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_2) {
  int rows = 0;
  int columns = 100;
  matrix_t m;
  m.matrix = NULL;
  double result = 0;
  s69_create_matrix(rows, columns, &m);
  ck_assert_int_eq(s69_determinant(&m, &result), INCORRECT_MATRIX);
  s69_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_3) {
  int rows = 10;
  int columns = 8;
  matrix_t m;
  m.matrix = NULL;
  double result = 0;
  s69_create_matrix(rows, columns, &m);
  ck_assert_int_eq(s69_determinant(&m, &result), CALCULATION_ERROR);
  s69_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_4) {
  int size = 1;
  matrix_t m;
  m.matrix = NULL;
  double num = 6;
  double result = 0;
  s69_create_matrix(size, size, &m);
  _input_some_number(&m, num);
  ck_assert_int_eq(s69_determinant(&m, &result), OK);
  ck_assert_double_eq(result, num);
  s69_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_5) {
  int size = 1;
  matrix_t m;
  m.matrix = NULL;
  double num = 6.7890;
  double result = 0;
  s69_create_matrix(size, size, &m);
  _input_some_number(&m, num);
  ck_assert_int_eq(s69_determinant(&m, &result), OK);
  ck_assert_double_eq(result, num);
  s69_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_6) {
  int size = 1;
  matrix_t m;
  m.matrix = NULL;
  double result = 0;
  s69_create_matrix(size, size, &m);
  ck_assert_int_eq(s69_determinant(&m, &result), OK);
  ck_assert_double_eq(result, OK);
  s69_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_7) {
  int size = 2;
  matrix_t m;
  m.matrix = NULL;
  double result = 0;
  s69_create_matrix(size, size, &m);
  m.matrix[0][0] = 12;
  m.matrix[0][1] = 34;
  m.matrix[1][0] = 27;
  m.matrix[1][1] = 5;
  ck_assert_int_eq(s69_determinant(&m, &result), OK);
  ck_assert_double_eq(result, -858);
  s69_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_8) {
  int size = 2;
  matrix_t m;
  m.matrix = NULL;
  double result = 0;
  double true_res = -2.94;
  s69_create_matrix(size, size, &m);
  m.matrix[0][0] = 1.2;
  m.matrix[0][1] = 3.4;
  m.matrix[1][0] = 2.7;
  m.matrix[1][1] = 5.2;
  ck_assert_int_eq(s69_determinant(&m, &result), OK);
  ck_assert_double_eq_tol(result, true_res, 1e-6);
  s69_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_9) {
  int size = 3;
  matrix_t m;
  m.matrix = NULL;
  double result = 0;
  double true_res = 0;
  s69_create_matrix(size, size, &m);
  ck_assert_int_eq(s69_determinant(&m, &result), OK);
  ck_assert_double_eq(result, true_res);
  s69_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_10) {
  int size = 3;
  matrix_t m;
  m.matrix = NULL;
  double result = 0;
  double true_res = 0;
  s69_create_matrix(size, size, &m);
  for (int i = 0, n = 1; i < size; i++) {
    for (int j = 0; j < size; j++) {
      m.matrix[i][j] = n++;
    }
  }
  ck_assert_int_eq(s69_determinant(&m, &result), OK);
  ck_assert_double_eq(result, true_res);
  s69_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_11) {
  int size = 3;
  matrix_t m;
  m.matrix = NULL;
  double result = 0;
  double true_res = 0;
  s69_create_matrix(size, size, &m);
  _input_some_number(&m, size * size);
  ck_assert_int_eq(s69_determinant(&m, &result), OK);
  ck_assert_double_eq(result, true_res);
  s69_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_12) {
  int size = 3;
  matrix_t m;
  m.matrix = NULL;
  double result = 0;
  double true_res = -306;
  s69_create_matrix(size, size, &m);

  m.matrix[0][0] = 6;
  m.matrix[0][1] = 1;
  m.matrix[0][2] = 1;

  m.matrix[1][0] = 4;
  m.matrix[1][1] = -2;
  m.matrix[1][2] = 5;

  m.matrix[2][0] = 2;
  m.matrix[2][1] = 8;
  m.matrix[2][2] = 7;

  ck_assert_int_eq(s69_determinant(&m, &result), OK);
  ck_assert_double_eq(result, true_res);
  s69_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_13) {
  int size = 4;
  matrix_t m;
  m.matrix = NULL;
  double result = 0;
  s69_create_matrix(size, size, &m);
  ck_assert_int_eq(s69_determinant(NULL, &result), INCORRECT_MATRIX);
  ck_assert_int_eq(s69_determinant(&m, NULL), INCORRECT_MATRIX);
  ck_assert_int_eq(s69_determinant(NULL, NULL), INCORRECT_MATRIX);
  s69_remove_matrix(&m);
}
END_TEST

Suite *test_determinant(void) {
  Suite *s = suite_create("\033[36;1;43m-=S69_DETERMINANT=-\033[0m");
  TCase *tc = tcase_create("s69_determinant_tc");

  tcase_add_test(tc, determinant_1);
  tcase_add_test(tc, determinant_2);
  tcase_add_test(tc, determinant_3);
  tcase_add_test(tc, determinant_4);
  tcase_add_test(tc, determinant_5);
  tcase_add_test(tc, determinant_6);
  tcase_add_test(tc, determinant_7);
  tcase_add_test(tc, determinant_8);
  tcase_add_test(tc, determinant_9);
  tcase_add_test(tc, determinant_10);
  tcase_add_test(tc, determinant_11);
  tcase_add_test(tc, determinant_12);
  tcase_add_test(tc, determinant_13);

  suite_add_tcase(s, tc);
  return s;
}
