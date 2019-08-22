#include <stdint.h>
#include <stdlib.h>

#include "node.h"

ll_node_t* ll_node_create(void* value, unsigned int data_size, ll_node_t* next, ll_node_t* prev) {
	ll_node_t* n = malloc(sizeof(ll_node_t));
	n->next = next;
	n->prev = prev;

	// Copy value into the list.
	n->value = malloc(data_size);
	memcpy(n->value, value, data_size);

	return n;
}

void ll_node_free(ll_node_t* n) {
	// Relink the nodes.
	if (n->next != NULL)
		n->next->prev = n->prev;
	if (n->prev != NULL)
		n->prev->next = n->next;

	// Free the node memory.
	free(n->value);
	free(n);
}
