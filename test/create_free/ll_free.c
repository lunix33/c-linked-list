#include <check.h>

#include "linkedlist.h"

START_TEST (ll_free_empty_test)
{
	linkedlist_t* ll = ll_create(sizeof(int));
	ck_assert_ptr_nonnull(ll);
	ll_free(&ll);
	ck_assert_ptr_null(ll);
}
END_TEST

START_TEST (ll_free_filled_test)
{
	// Not done yet...
	//ck_assert_int_eq(1, 1);
	ck_abort();
}
END_TEST
