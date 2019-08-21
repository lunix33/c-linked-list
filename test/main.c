#include <check.h>

#include "linkedlist.h"

Suite* buildSuite(void)
{
	Suite* tsuite = suite_create("ini_tests");
	TCase* tcase = tcase_create("parse");
	//tcase_add_test(tcase, parse_test);
	suite_add_tcase(tsuite, tcase);

	return tsuite;
}

int main(int argc, char* argv[])
{
	int failed;
	Suite* test_suite = buildSuite();
	SRunner* runner = srunner_create(test_suite);
	srunner_run_all(runner, CK_NORMAL);
	failed = srunner_ntests_failed(runner);
	srunner_free(runner);

	return failed;
}

