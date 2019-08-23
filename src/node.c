#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"

ll_node_t* ll_node_create(
	void* value, unsigned int data_size,
	ll_node_t* next, ll_node_t* prev)
{
	// Create new node.
	ll_node_t* n = malloc(sizeof(ll_node_t));
	n->next = next;
	n->prev = prev;

	// Relink nodes.
	if (n->next != NULL)
		n->next->prev = n;
	if (n->prev != NULL)
		n->prev->next = n;

	// Copy value into the list.
	n->value = malloc(data_size);
	memcpy(n->value, value, data_size);

	return n;
}

void ll_node_free(ll_node_t** n_ptr)
{
	ll_node_t* n = *n_ptr;

	// Relink the nodes.
	if (n->next != NULL)
		n->next->prev = n->prev;
	if (n->prev != NULL)
		n->prev->next = n->next;

	// Free the node memory.
	free(n->value);
	free(n);

	*n_ptr = NULL;
}
