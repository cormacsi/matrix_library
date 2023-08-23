#include "test_me.h"

int main(void) {
  int failed = 0;
  Suite *s69_string_test[] = {
      test_create_matrix(), test_remove_matrix(),  test_eq_matrix(),
      test_sum_matrix(),    test_sub_matrix(),     test_mult_number(),
      test_mult_matrix(),   test_transpose(),      test_calc_complements(),
      test_determinant(),   test_inverse_matrix(), NULL};

  for (int i = 0; s69_string_test[i] != NULL; i++) {  // (&& failed == 0)
    SRunner *sr = srunner_create(s69_string_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("Failed: %d\n", failed);

  return failed == 0 ? 0 : 1;
}
