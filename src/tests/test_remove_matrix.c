#include "test_me.h"

START_TEST(remove_matrix_1) {
  int rows = 1;
  int columns = 1;
  matrix_t m;
  m.matrix = NULL;
  s69_create_matrix(rows, columns, &m);
  s69_remove_matrix(&m);
  s69_remove_matrix(&m);
  s69_remove_matrix(NULL);
  ck_assert_ptr_null(m.matrix);
  ck_assert_int_eq(m.rows, 0);
  ck_assert_int_eq(m.columns, 0);
}
END_TEST

START_TEST(remove_matrix_2) {
  matrix_t m;
  m.matrix = NULL;
  m.rows = 0, m.columns = 0;
  s69_remove_matrix(&m);
  ck_assert_ptr_null(m.matrix);
  ck_assert_int_eq(m.rows, 0);
  ck_assert_int_eq(m.columns, 0);
}
END_TEST

START_TEST(remove_matrix_3) {
  int rows = 1;
  int columns = 1;
  matrix_t m;
  m.matrix = NULL;
  s69_create_matrix(rows, columns, &m);
  s69_remove_matrix(&m);
  ck_assert_ptr_null(m.matrix);
  ck_assert_int_eq(m.rows, 0);
  ck_assert_int_eq(m.columns, 0);
}
END_TEST

START_TEST(remove_matrix_4) {
  int rows = 10;
  int columns = 100;
  matrix_t m;
  m.matrix = NULL;
  s69_create_matrix(rows, columns, &m);
  s69_remove_matrix(&m);
  ck_assert_ptr_null(m.matrix);
  ck_assert_int_eq(m.rows, 0);
  ck_assert_int_eq(m.columns, 0);
}
END_TEST

START_TEST(remove_matrix_5) {
  int rows = 100;
  int columns = 100;
  matrix_t m;
  m.matrix = NULL;
  s69_create_matrix(rows, columns, &m);
  s69_remove_matrix(&m);
  ck_assert_ptr_null(m.matrix);
  ck_assert_int_eq(m.rows, 0);
  ck_assert_int_eq(m.columns, 0);
}
END_TEST

START_TEST(remove_matrix_6) {
  int rows = 6;
  int columns = 4;
  matrix_t m;
  m.matrix = NULL;
  m.rows = rows;
  m.columns = columns;
  m.matrix = calloc(rows, sizeof(double *));
  if (m.matrix) {
    for (int i = 0; i < rows - 2; i++) {
      m.matrix[i] = calloc(columns, sizeof(double));
    }
  }
  s69_remove_matrix(&m);
  ck_assert_ptr_null(m.matrix);
  ck_assert_int_eq(m.rows, 0);
  ck_assert_int_eq(m.columns, 0);
}
END_TEST

START_TEST(remove_matrix_7) {
  int rows = 0;
  int columns = 0;
  matrix_t m;
  m.matrix = NULL;
  s69_create_matrix(rows, columns, &m);
  s69_remove_matrix(&m);
  ck_assert_ptr_null(m.matrix);
  ck_assert_int_eq(m.rows, 0);
  ck_assert_int_eq(m.columns, 0);
}
END_TEST

Suite *test_remove_matrix(void) {
  Suite *s = suite_create("\033[36;1;43m-=S69_REMOVE_MATRIX=-\033[0m");
  TCase *tc = tcase_create("s69_remove_matrix_tc");

  tcase_add_test(tc, remove_matrix_1);
  tcase_add_test(tc, remove_matrix_2);
  tcase_add_test(tc, remove_matrix_3);
  tcase_add_test(tc, remove_matrix_4);
  tcase_add_test(tc, remove_matrix_5);
  tcase_add_test(tc, remove_matrix_6);
  tcase_add_test(tc, remove_matrix_7);

  suite_add_tcase(s, tc);
  return s;
}
