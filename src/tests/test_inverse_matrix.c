#include "test_me.h"

START_TEST(inverse_matrix_1) {
  int rows = 100;
  int columns = 0;
  matrix_t m, result;
  m.matrix = NULL, result.matrix = NULL;
  s69_create_matrix(rows, columns, &m);
  ck_assert_int_eq(s69_inverse_matrix(&m, &result), INCORRECT_MATRIX);
  s69_remove_matrix(&m);
}
END_TEST

START_TEST(inverse_matrix_2) {
  int rows = 0;
  int columns = 100;
  matrix_t m, result;
  m.matrix = NULL, result.matrix = NULL;
  s69_create_matrix(rows, columns, &m);
  ck_assert_int_eq(s69_inverse_matrix(&m, &result), INCORRECT_MATRIX);
  s69_remove_matrix(&m);
}
END_TEST

START_TEST(inverse_matrix_3) {
  int rows = 10;
  int columns = 8;
  matrix_t m, result;
  m.matrix = NULL, result.matrix = NULL;
  s69_create_matrix(rows, columns, &m);
  ck_assert_int_eq(s69_inverse_matrix(&m, &result), CALCULATION_ERROR);
  s69_remove_matrix(&m);
}
END_TEST

START_TEST(inverse_matrix_4) {
  int size = 1;
  matrix_t m, result;
  m.matrix = NULL, result.matrix = NULL;
  double num = 6;
  s69_create_matrix(size, size, &m);
  _input_some_number(&m, num);
  ck_assert_int_eq(s69_inverse_matrix(&m, &result), OK);
  s69_remove_matrix(&m);
  s69_remove_matrix(&result);
}
END_TEST

START_TEST(inverse_matrix_5) {
  int size = 1;
  matrix_t m, result;
  m.matrix = NULL, result.matrix = NULL;
  double num = 6.7890;
  s69_create_matrix(size, size, &m);
  _input_some_number(&m, num);
  ck_assert_int_eq(s69_inverse_matrix(&m, &result), OK);
  s69_remove_matrix(&m);
  s69_remove_matrix(&result);
}
END_TEST

START_TEST(inverse_matrix_6) {
  int size = 3;
  matrix_t m, result;
  m.matrix = NULL, result.matrix = NULL;
  s69_create_matrix(size, size, &m);
  ck_assert_int_eq(s69_inverse_matrix(&m, &result), CALCULATION_ERROR);
  s69_remove_matrix(&m);
}
END_TEST

START_TEST(inverse_matrix_7) {
  int size = 3;
  matrix_t m, result;
  m.matrix = NULL, result.matrix = NULL;
  s69_create_matrix(size, size, &m);
  for (int i = 0, n = 1; i < size; i++) {
    for (int j = 0; j < size; j++) {
      m.matrix[i][j] = n++;
    }
  }
  ck_assert_int_eq(s69_inverse_matrix(&m, &result), CALCULATION_ERROR);
  s69_remove_matrix(&m);
}
END_TEST

START_TEST(inverse_matrix_8) {
  int size = 2;
  matrix_t m, result, real;
  m.matrix = NULL, result.matrix = NULL, real.matrix = NULL;

  s69_create_matrix(size, size, &m);
  m.matrix[0][0] = 1.;
  m.matrix[0][1] = 2.;
  m.matrix[1][0] = 3.;
  m.matrix[1][1] = 4.;

  s69_create_matrix(size, size, &real);
  real.matrix[0][0] = -2;
  real.matrix[0][1] = 1;
  real.matrix[1][0] = 1.5;
  real.matrix[1][1] = -0.5;

  ck_assert_int_eq(s69_inverse_matrix(&m, &result), OK);
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      ck_assert_double_eq(result.matrix[i][j], real.matrix[i][j]);
    }
  }
  s69_remove_matrix(&m);
  s69_remove_matrix(&real);
  s69_remove_matrix(&result);
}
END_TEST

START_TEST(inverse_matrix_9) {
  int size = 4;
  matrix_t m, result, real;
  m.matrix = NULL, result.matrix = NULL, real.matrix = NULL;

  s69_create_matrix(size, size, &m);
  m.matrix[0][0] = -2;
  m.matrix[0][1] = -3;
  m.matrix[0][2] = 0;
  m.matrix[0][3] = -2;

  m.matrix[1][0] = 0;
  m.matrix[1][1] = 1;
  m.matrix[1][2] = 4;
  m.matrix[1][3] = 4;

  m.matrix[2][0] = 3;
  m.matrix[2][1] = 1;
  m.matrix[2][2] = 1;
  m.matrix[2][3] = 0;

  m.matrix[3][0] = -1;
  m.matrix[3][1] = 0;
  m.matrix[3][2] = 2;
  m.matrix[3][3] = 2;

  s69_create_matrix(size, size, &real);
  real.matrix[0][0] = 1;
  real.matrix[0][1] = 5;
  real.matrix[0][2] = -2;
  real.matrix[0][3] = -9;

  real.matrix[1][0] = -2;
  real.matrix[1][1] = -9;
  real.matrix[1][2] = 4;
  real.matrix[1][3] = 16;

  real.matrix[2][0] = -1;
  real.matrix[2][1] = -6;
  real.matrix[2][2] = 3;
  real.matrix[2][3] = 11;

  real.matrix[3][0] = 3 / 2.;
  real.matrix[3][1] = 17 / 2.;
  real.matrix[3][2] = -4;
  real.matrix[3][3] = -15;

  double determinant = 0;
  ck_assert_int_eq(s69_determinant(&m, &determinant), OK);
  ck_assert_double_eq(determinant, 2);

  ck_assert_int_eq(s69_inverse_matrix(&m, &result), OK);
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      ck_assert_double_eq(result.matrix[i][j], real.matrix[i][j]);
    }
  }
  s69_remove_matrix(&m);
  s69_remove_matrix(&real);
  s69_remove_matrix(&result);
}
END_TEST

START_TEST(inverse_matrix_10) {
  int size = 5;
  matrix_t m, result, real;
  m.matrix = NULL, result.matrix = NULL, real.matrix = NULL;

  s69_create_matrix(size, size, &m);
  m.matrix[0][0] = 5;
  m.matrix[0][1] = 6;
  m.matrix[0][2] = 3;
  m.matrix[0][3] = 2;
  m.matrix[0][4] = 0;

  m.matrix[1][0] = -3;
  m.matrix[1][1] = -4;
  m.matrix[1][2] = 6;
  m.matrix[1][3] = 1;
  m.matrix[1][4] = 2;

  m.matrix[2][0] = 1;
  m.matrix[2][1] = 2;
  m.matrix[2][2] = 6;
  m.matrix[2][3] = 4;
  m.matrix[2][4] = 0;

  m.matrix[3][0] = 5;
  m.matrix[3][1] = 5;
  m.matrix[3][2] = 2;
  m.matrix[3][3] = 0;
  m.matrix[3][4] = 1;

  m.matrix[4][0] = 3;
  m.matrix[4][1] = 6;
  m.matrix[4][2] = 0;
  m.matrix[4][3] = 4;
  m.matrix[4][4] = 0;

  s69_create_matrix(size, size, &real);
  real.matrix[0][0] = -17 / 2.;
  real.matrix[0][1] = -3.;
  real.matrix[0][2] = 21 / 4.;
  real.matrix[0][3] = 6.;
  real.matrix[0][4] = -1 / 4.;

  real.matrix[1][0] = 157 / 20.;
  real.matrix[1][1] = 27 / 10.;
  real.matrix[1][2] = -193 / 40.;
  real.matrix[1][3] = -27 / 5.;
  real.matrix[1][4] = 9 / 40.;

  real.matrix[2][0] = 12 / 5.;
  real.matrix[2][1] = 4 / 5.;
  real.matrix[2][2] = -13 / 10.;
  real.matrix[2][3] = -8 / 5.;
  real.matrix[2][4] = -1 / 10.;

  real.matrix[3][0] = -27 / 5.;
  real.matrix[3][1] = -9 / 5.;
  real.matrix[3][2] = 33 / 10.;
  real.matrix[3][3] = 18 / 5.;
  real.matrix[3][4] = 1 / 10.;

  real.matrix[4][0] = -31 / 20.;
  real.matrix[4][1] = -1 / 10.;
  real.matrix[4][2] = 19 / 40.;
  real.matrix[4][3] = 6 / 5.;
  real.matrix[4][4] = 13 / 40.;

  double determinant = 0;
  ck_assert_int_eq(s69_determinant(&m, &determinant), OK);
  ck_assert_double_eq(determinant, -40);

  ck_assert_int_eq(s69_inverse_matrix(&m, &result), OK);
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      ck_assert_double_eq(result.matrix[i][j], real.matrix[i][j]);
    }
  }
  s69_remove_matrix(&m);
  s69_remove_matrix(&real);
  s69_remove_matrix(&result);
}
END_TEST

START_TEST(inverse_matrix_11) {
  int size = 4;
  matrix_t m, result;
  m.matrix = NULL, result.matrix = NULL;
  s69_create_matrix(size, size, &m);
  ck_assert_int_eq(s69_inverse_matrix(NULL, &result), INCORRECT_MATRIX);
  ck_assert_int_eq(s69_inverse_matrix(&m, NULL), INCORRECT_MATRIX);
  ck_assert_int_eq(s69_inverse_matrix(NULL, NULL), INCORRECT_MATRIX);
  s69_remove_matrix(&m);
}
END_TEST

Suite *test_inverse_matrix(void) {
  Suite *s = suite_create("\033[36;1;43m-=S69_INVERSE_MATRIX=-\033[0m");
  TCase *tc = tcase_create("s69_inverse_matrix_tc");

  tcase_add_test(tc, inverse_matrix_1);
  tcase_add_test(tc, inverse_matrix_2);
  tcase_add_test(tc, inverse_matrix_3);
  tcase_add_test(tc, inverse_matrix_4);
  tcase_add_test(tc, inverse_matrix_5);
  tcase_add_test(tc, inverse_matrix_6);
  tcase_add_test(tc, inverse_matrix_7);
  tcase_add_test(tc, inverse_matrix_8);
  tcase_add_test(tc, inverse_matrix_9);
  tcase_add_test(tc, inverse_matrix_10);
  tcase_add_test(tc, inverse_matrix_11);

  suite_add_tcase(s, tc);
  return s;
}
