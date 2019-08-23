#include <check.h>

#include "create_free/ll_create.c"
#include "create_free/ll_free.c"
#include "push/ll_push_back.c"

Suite* buildSuite(void)
{
	Suite* tsuite = suite_create("linkedlist_test");

	TCase* create_free_case = tcase_create("create_free");
	tcase_add_test(create_free_case, ll_create_test);
	tcase_add_test(create_free_case, ll_free_empty_test);
	tcase_add_test(create_free_case, ll_free_filled_test);
	suite_add_tcase(tsuite, create_free_case);

	TCase* push_case = tcase_create("push");
	tcase_add_test(push_case, ll_push_back_test);
	suite_add_tcase(tsuite, push_case);

	return tsuite;
}

int main(int argc, char* argv[])
{
	int failed;
	Suite* test_suite = buildSuite();
	SRunner* runner = srunner_create(test_suite);
	srunner_run_all(runner, CK_ENV);
	failed = srunner_ntests_failed(runner);
	srunner_free(runner);

	return failed;
}

