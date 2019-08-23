#pragma once

typedef struct ll_node_t ll_node_t;

/**
 * A double linked list data node.
 */
struct ll_node_t {
	ll_node_t* next;
	ll_node_t* prev;
	void* value;
};

/**
 * @brief Create a new link list node.
 * @param value The value stored in the node.
 * @param next The next node.
 * @param prev The previous node.
 */
ll_node_t* ll_node_create(
	void* value, unsigned int data_size,
	ll_node_t* next, ll_node_t* prev);

/**
 * @brief Free the memory occupied by a node.
 * @param n_ptr A pointer to the node pointer to be freed.
 * @note If the node was successfully freed, then the node pointer will be NULL.
 */
void ll_node_free(ll_node_t** n_ptr);
