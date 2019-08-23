#include <stdlib.h>

#include "linkedlist.h"

linkedlist_t* ll_create(unsigned int data_size)
{
	linkedlist_t* ll = malloc(sizeof(linkedlist_t));
	if (ll != NULL) {
		ll->head = NULL;
		ll->tail = NULL;
		ll->count = 0;
		ll->_data_size = data_size;
	}

	return ll;
}

void ll_free(linkedlist_t** ll_ptr)
{
	linkedlist_t* ll = *ll_ptr;

	// Free every nodes.
	for (ll_node_t* i = ll->head; ll->head != NULL; i = ll->head) {
		ll->head = i->next;
		ll_node_free(&i);
	}

	// Free the linked list.
	free(ll);
	*ll_ptr = NULL;
}

void ll_push_back(linkedlist_t* ll, void* value)
{
	ll_node_t* n = ll_node_create(value, ll->_data_size, NULL, ll->tail);

	// Adjust linked list.
	ll->tail = n;
	if (ll->count == 0)
		ll->head = n;
	ll->count++;
}

void ll_push_front(linkedlist_t* ll, void* value)
{
	ll_node_t* n = ll_node_create(value, ll->_data_size, ll->head, NULL);

	// Adjust linked list.
	ll->head = n;
	if (ll->count == 0)
		ll->tail = n;
	ll->count++;
}

void ll_pop_back(linkedlist_t* ll)
{
	if (ll->count == 0) {
		return;
	} else if (ll->count == 1) {
		ll_node_free(&(ll->tail));
		ll->head = NULL;
		ll->tail = NULL;
	} else {
		ll->tail = ll->tail->prev;
		ll_node_free(&(ll->tail->next));
	}

	ll->count--;
}

void ll_pop_front(linkedlist_t* ll)
{
	if (ll->count > 1) {
		ll->head = ll->head->next;
		ll_node_free(&(ll->head->prev));
	} else {
		ll_pop_back(ll);
		return;
	}

	ll->count--;
}

ll_node_t* ll_get_pos(linkedlist_t* ll, int pos)
{
	// Can't go over the number of items in the list.
	if (pos >= ll->count)
		return NULL;

	ll_node_t* ptr = (pos >= 0) ? ll->head : ll->tail;
	unsigned int distance = abs(pos);
	for (unsigned int i = 0; i < distance; i++) {
		// Move ptr
		if (pos >= 0)
			ptr = ptr->next;
		else
			ptr = ptr->prev;

		// Should not encounter NULL in the list.
		if (ptr == NULL)
			break;
	}

	return ptr;
}
