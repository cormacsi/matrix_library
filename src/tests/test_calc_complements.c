#include "test_me.h"

START_TEST(calc_complements_1) {
  int rows = 100;
  int columns = 0;
  matrix_t m, result;
  m.matrix = NULL, result.matrix = NULL;
  s69_create_matrix(rows, columns, &m);
  ck_assert_int_eq(s69_calc_complements(&m, &result), INCORRECT_MATRIX);
  s69_remove_matrix(&m);
}
END_TEST

START_TEST(calc_complements_2) {
  int rows = 0;
  int columns = 100;
  matrix_t m, result;
  m.matrix = NULL, result.matrix = NULL;
  s69_create_matrix(rows, columns, &m);
  ck_assert_int_eq(s69_calc_complements(&m, &result), INCORRECT_MATRIX);
  s69_remove_matrix(&m);
}
END_TEST

START_TEST(calc_complements_3) {
  int rows = 10;
  int columns = 8;
  matrix_t m, result;
  m.matrix = NULL, result.matrix = NULL;
  s69_create_matrix(rows, columns, &m);
  ck_assert_int_eq(s69_calc_complements(&m, &result), CALCULATION_ERROR);
  s69_remove_matrix(&m);
}
END_TEST

START_TEST(calc_complements_4) {
  int size = 1;
  matrix_t m, result;
  m.matrix = NULL, result.matrix = NULL;
  double num = 1;
  s69_create_matrix(size, size, &m);
  _input_some_number(&m, num);
  ck_assert_int_eq(s69_calc_complements(&m, &result), OK);
  ck_assert_double_eq(result.matrix[0][0], num);
  s69_remove_matrix(&m);
  s69_remove_matrix(&result);
}
END_TEST

START_TEST(calc_complements_5) {
  int size = 1;
  matrix_t m, result;
  m.matrix = NULL, result.matrix = NULL;
  double num = 1;
  s69_create_matrix(size, size, &m);
  _input_some_number(&m, num);
  ck_assert_int_eq(s69_calc_complements(&m, &result), OK);
  ck_assert_double_eq(result.matrix[0][0], num);
  s69_remove_matrix(&m);
  s69_remove_matrix(&result);
}
END_TEST

START_TEST(calc_complements_6) {
  int size = 1;
  matrix_t m, result;
  m.matrix = NULL, result.matrix = NULL;
  s69_create_matrix(size, size, &m);
  ck_assert_int_eq(s69_calc_complements(&m, &result), OK);
  ck_assert_double_eq(result.matrix[0][0], 1);
  s69_remove_matrix(&m);
  s69_remove_matrix(&result);
}
END_TEST

START_TEST(calc_complements_7) {
  int size = 2;
  matrix_t m, result, real;
  m.matrix = NULL, result.matrix = NULL, real.matrix = NULL;

  s69_create_matrix(size, size, &m);
  m.matrix[0][0] = 1.;
  m.matrix[0][1] = 2.;
  m.matrix[1][0] = 3.;
  m.matrix[1][1] = 4.;

  s69_create_matrix(size, size, &real);
  real.matrix[0][0] = 4.;
  real.matrix[0][1] = -3.;
  real.matrix[1][0] = -2.;
  real.matrix[1][1] = 1.;

  ck_assert_int_eq(s69_calc_complements(&m, &result), OK);
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

START_TEST(calc_complements_8) {
  int size = 2;
  matrix_t m, result, real;
  m.matrix = NULL, result.matrix = NULL, real.matrix = NULL;

  s69_create_matrix(size, size, &m);
  m.matrix[0][0] = 1.2;
  m.matrix[0][1] = 3.4;
  m.matrix[1][0] = 2.7;
  m.matrix[1][1] = 5.2;

  s69_create_matrix(size, size, &real);
  real.matrix[0][0] = 5.2;
  real.matrix[0][1] = -2.7;
  real.matrix[1][0] = -3.4;
  real.matrix[1][1] = 1.2;

  ck_assert_int_eq(s69_calc_complements(&m, &result), OK);
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

START_TEST(calc_complements_9) {
  int size = 3;
  matrix_t m, result, real;
  m.matrix = NULL, result.matrix = NULL, real.matrix = NULL;
  s69_create_matrix(size, size, &m);
  s69_create_matrix(size, size, &real);
  ck_assert_int_eq(s69_calc_complements(&m, &result), OK);
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

START_TEST(calc_complements_10) {
  int size = 3;
  matrix_t m, result;
  m.matrix = NULL, result.matrix = NULL;
  s69_create_matrix(size, size, &m);
  _input_some_number(&m, size);

  ck_assert_int_eq(s69_calc_complements(&m, &result), OK);
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      ck_assert_double_eq(result.matrix[i][j], OK);
    }
  }
  s69_remove_matrix(&m);
  s69_remove_matrix(&result);
}
END_TEST

START_TEST(calc_complements_11) {
  int size = 3;
  matrix_t m, result, real;
  m.matrix = NULL, result.matrix = NULL, real.matrix = NULL;

  s69_create_matrix(size, size, &m);
  m.matrix[0][0] = 1;
  m.matrix[0][1] = 2;
  m.matrix[0][2] = 3;

  m.matrix[1][0] = 0;
  m.matrix[1][1] = 4;
  m.matrix[1][2] = 2;

  m.matrix[2][0] = 5;
  m.matrix[2][1] = 2;
  m.matrix[2][2] = 1;

  s69_create_matrix(size, size, &real);
  real.matrix[0][0] = 0;
  real.matrix[0][1] = 10;
  real.matrix[0][2] = -20;

  real.matrix[1][0] = 4;
  real.matrix[1][1] = -14;
  real.matrix[1][2] = 8;

  real.matrix[2][0] = -8;
  real.matrix[2][1] = -2;
  real.matrix[2][2] = 4;

  ck_assert_int_eq(s69_calc_complements(&m, &result), OK);
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

START_TEST(calc_complements_12) {
  int size = 8;
  matrix_t m, result, real;
  m.matrix = NULL, result.matrix = NULL, real.matrix = NULL;

  s69_create_matrix(size, size, &m);

  for (int i = 0, n = 1; i < size; i++) {
    for (int j = 0; j < size; j++) {
      m.matrix[i][j] = n++;
    }
  }

  s69_create_matrix(size, size, &real);

  ck_assert_int_eq(s69_calc_complements(&m, &result), OK);
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

START_TEST(calc_complements_13) {
  int size = 4;
  matrix_t m, result;
  m.matrix = NULL, result.matrix = NULL;
  s69_create_matrix(size, size, &m);
  ck_assert_int_eq(s69_calc_complements(NULL, &result), INCORRECT_MATRIX);
  ck_assert_int_eq(s69_calc_complements(&m, NULL), INCORRECT_MATRIX);
  ck_assert_int_eq(s69_calc_complements(NULL, NULL), INCORRECT_MATRIX);
  s69_remove_matrix(&m);
}
END_TEST

Suite *test_calc_complements(void) {
  Suite *s = suite_create("\033[36;1;43m-=S69_CALC_COMPLEMENTS=-\033[0m");
  TCase *tc = tcase_create("s69_calc_complements_tc");

  tcase_add_test(tc, calc_complements_1);
  tcase_add_test(tc, calc_complements_2);
  tcase_add_test(tc, calc_complements_3);
  tcase_add_test(tc, calc_complements_4);
  tcase_add_test(tc, calc_complements_5);
  tcase_add_test(tc, calc_complements_6);
  tcase_add_test(tc, calc_complements_7);
  tcase_add_test(tc, calc_complements_8);
  tcase_add_test(tc, calc_complements_9);
  tcase_add_test(tc, calc_complements_10);
  tcase_add_test(tc, calc_complements_11);
  tcase_add_test(tc, calc_complements_12);
  tcase_add_test(tc, calc_complements_13);

  suite_add_tcase(s, tc);
  return s;
}
