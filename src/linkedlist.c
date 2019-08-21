#include <stdlib.h>

#include "linkedlist.h"

linkedlist_t* ll_create() {
	linkedlist_t* ll = malloc(sizeof(linkedlist_t));
	if (ll != NULL) {
		ll->head = NULL;
		ll->tail = NULL;
		ll->ptr = NULL;
		ll->count = 0;
		ll->position = 0;
	}

	return ll;
}

void ll_free(linkedlist_t* ll) {
	// Free every nodes.
	while (ll->head != NULL) {
		ll_node_t next = ll->head->next;
		ll_node_free(ll->head);
		ll->head = next;
	}

	// Free the linked list.
	free(ll);
}

void ll_push_back(linkedlist_t* ll, void* value) {
	
}

void ll_push_front(linkedlist_t* ll, void* value) {

}