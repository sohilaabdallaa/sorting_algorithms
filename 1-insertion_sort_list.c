#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of
 * integers in ascending order
 * using the Insertion sort algorithm
 *
 * @list: Double pointer to the head of the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current_node = NULL;
	listint_t *temp_node = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current_node = (*list)->next;

	while (current_node != NULL)
	{
		while (current_node->prev != NULL && current_node->n < current_node->prev->n)
		{
			temp_node = current_node;

			if (current_node->next != NULL)
				current_node->next->prev = temp_node->prev;

			current_node->prev->next = temp_node->next;

			current_node = current_node->prev;

			temp_node->prev = current_node->prev;
			temp_node->next = current_node;

			if (current_node->prev != NULL)
				current_node->prev->next = temp_node;
			current_node->prev = temp_node;

			if (temp_node->prev == NULL)
				*list = temp_node;

			print_list(*list);

			current_node = current_node->prev;
		}

		current_node = current_node->next;
	}
}
