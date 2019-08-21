#pragma once

#include "node.h";

/**
 * A double ended linked list.
 */
struct linkedlist_t {
	ll_node_t* head; /*!< The first element of the list. */
	ll_node_t* tail; /*!< The last element of the list. */
	unsigned int count; /*!< The number of element in the list.*/

	ll_node_t** ptr; /*!< The node at the pointer position. */
	unsigned int position; /*!< The pointer current position. */
}

/**
 * @brief Create a new linked list.
 * @returns the newly created linked list, or null when an error occure.
 */
linkedlist_t* ll_create();

/**
 * @brief Free the memory of the linked list.
 * @param ll The link list to free.
 * @note All the data in the linked list will be freed.
 */
void ll_free(linkedlist_t* ll);

/**
 * @brief Add an element at the end of the linked list.
 * @param ll The link list on which the element will be appended.
 * @param value The value stored in the new node.
 */
void ll_push_back(linkedlist_t* ll, void* value);

/**
 * @brief Add an element at the beguinning of the linked list.
 * @param ll The link list on which the element will be prepended.
 * @param value The value stored in the new node.
 */
void ll_push_front(linkedlist_t* ll, void* value);
