#pragma once

struct ll_node_t {
	ll_node_t* next;
	ll_node_t* prev;
	void* value
}

/**
 * @brief Create a new link list node.
 * @param value The value stored in the node.
 * @param next The next node.
 * @param prev The previous node.
 */
ll_node_t* ll_node_create(void* value, ll_node_t* next, ll_node_t* prev);

/**
 * @brief Free the memory occupied by a node.
 * @param n The node to be freed.
 */
void ll_node_free(ll_node_t* n);
