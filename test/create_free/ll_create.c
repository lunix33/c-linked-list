#include <check.h>

#include "linkedlist.h"

START_TEST (ll_create_test)
{
	linkedlist_t* ll = ll_create(sizeof(int));
	ck_assert_uint_eq(ll->count, 0);
	ck_assert_ptr_null(ll->head);
	ck_assert_ptr_null(ll->tail);
	ck_assert_uint_eq(ll->_data_size, sizeof(int));
}
END_TEST
