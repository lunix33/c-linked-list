#pragma once

#include "node.h"

/**
 * A double ended linked list.
 */
typedef struct linkedlist_t {
	ll_node_t* head; /*!< The first element of the list. */
	ll_node_t* tail; /*!< The last element of the list. */
	unsigned int count; /*!< The number of element in the list.*/
	unsigned int _data_size; /*!< The size of the data in the linked list. -- Not ment to be changed.*/
} linkedlist_t;

/**
 * @brief Create a new linked list.
 * @param data_size The size of the data contained in the linked list.
 * @returns the newly created linked list, or null when an error occure.
 */
linkedlist_t* ll_create(unsigned int data_size);

/**
 * @brief Free the memory of the linked list.
 * @param ll_ptr A pointer to the linkedlist pointer.
 * @note
 * 	All the data in the linked list will be freed.
 * 	If the linked list is successfully freed, then the linked list will be NULL.
 */
void ll_free(linkedlist_t** ll_ptr);

/**
 * @brief Add an element at the end of the linked list.
 * @param ll The link list on which the element will be appended.
 * @param value The value stored in the new node.
 * @param data_size The size of the value.
 * @note The value is copied to the lined list memory.
 */
void ll_push_back(linkedlist_t* ll, void* value);

/**
 * @brief Add an element at the beguinning of the linked list.
 * @param ll The link list on which the element will be prepended.
 * @param value The value stored in the new node.
 * @note The value is copied to the lined list memory.
 */
void ll_push_front(linkedlist_t* ll, void* value);

/**
 * @brief Remove the last node of the linked list.
 * @param ll The linked list on which we're removing an element from.
 */
void ll_pop_back(linkedlist_t* ll);

/**
 * @brief Get the node at the specified position.
 * @param ll The linked list in which the search must be done.
 * @param pos The position of the node (zero indexed).
 * @returns The node at the specified position, or NULL on fail.
 */
ll_node_t* ll_get_pos(linkedlist_t* ll, int pos);
