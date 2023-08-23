#include "test_me.h"

START_TEST(create_matrix_1) {
  int rows = 0;
  int columns = 5;
  matrix_t m;
  m.matrix = NULL;
  int result = s69_create_matrix(rows, columns, &m);
  ck_assert_int_eq(result, INCORRECT_MATRIX);
  s69_remove_matrix(&m);
}
END_TEST

START_TEST(create_matrix_2) {
  int rows = 1;
  int columns = 0;
  matrix_t m;
  m.matrix = NULL;
  int result = s69_create_matrix(rows, columns, &m);
  ck_assert_int_eq(result, INCORRECT_MATRIX);
  s69_remove_matrix(&m);
}
END_TEST

START_TEST(create_matrix_3) {
  int rows = 4;
  int columns = -4;
  matrix_t m;
  m.matrix = NULL;
  int result = s69_create_matrix(rows, columns, &m);
  ck_assert_int_eq(result, INCORRECT_MATRIX);
  s69_remove_matrix(&m);
}
END_TEST

START_TEST(create_matrix_4) {
  int rows = 10;
  int columns = 6;
  matrix_t m;
  m.matrix = NULL;
  int result = s69_create_matrix(rows, columns, &m);
  ck_assert_int_eq(result, OK);
  s69_remove_matrix(&m);
}
END_TEST

START_TEST(create_matrix_5) {
  int rows = 4;
  int columns = 4;
  matrix_t m;
  m.matrix = NULL;
  int result = s69_create_matrix(rows, columns, &m);
  ck_assert_int_eq(result, OK);
  s69_remove_matrix(&m);
}
END_TEST

START_TEST(create_matrix_6) {
  int rows = 30;
  int columns = 5;
  matrix_t m;
  m.matrix = NULL;
  int result = s69_create_matrix(rows, columns, &m);
  ck_assert_int_eq(result, OK);
  s69_remove_matrix(&m);
}
END_TEST

START_TEST(create_matrix_7) {
  int rows = 0;
  int columns = 0;
  matrix_t m;
  m.matrix = NULL;
  int result = s69_create_matrix(rows, columns, &m);
  ck_assert_int_eq(result, INCORRECT_MATRIX);
  s69_remove_matrix(&m);
}
END_TEST

START_TEST(create_matrix_8) {
  int rows = 40;
  int columns = -40;
  matrix_t m;
  m.matrix = NULL;
  int result = s69_create_matrix(rows, columns, &m);
  ck_assert_int_eq(result, INCORRECT_MATRIX);
  s69_remove_matrix(&m);
}
END_TEST

START_TEST(create_matrix_9) {
  int rows = 50;
  int columns = 100;
  matrix_t m;
  m.matrix = NULL;
  int result = s69_create_matrix(rows, columns, &m);
  ck_assert_int_eq(result, OK);
  s69_remove_matrix(&m);
}
END_TEST

START_TEST(create_matrix_10) {
  int rows = 100;
  int columns = 100;
  matrix_t m;
  m.matrix = NULL;
  int result = s69_create_matrix(rows, columns, &m);
  ck_assert_int_eq(result, OK);
  s69_remove_matrix(&m);
}
END_TEST

START_TEST(create_matrix_11) {
  int size = 4;
  ck_assert_int_eq(s69_create_matrix(size, size, NULL), INCORRECT_MATRIX);
}
END_TEST

Suite *test_create_matrix(void) {
  Suite *s = suite_create("\033[36;1;43m-=S69_CREATE_MATRIX=-\033[0m");
  TCase *tc = tcase_create("s69_create_matrix_tc");

  tcase_add_test(tc, create_matrix_1);
  tcase_add_test(tc, create_matrix_2);
  tcase_add_test(tc, create_matrix_3);
  tcase_add_test(tc, create_matrix_4);
  tcase_add_test(tc, create_matrix_5);
  tcase_add_test(tc, create_matrix_6);
  tcase_add_test(tc, create_matrix_7);
  tcase_add_test(tc, create_matrix_8);
  tcase_add_test(tc, create_matrix_9);
  tcase_add_test(tc, create_matrix_10);
  tcase_add_test(tc, create_matrix_11);

  suite_add_tcase(s, tc);
  return s;
}
