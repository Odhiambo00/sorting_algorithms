#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of ints in ascending order
 * using Insertion sort algo
 * @list: pointer to doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *first, *last, *temp;

	if (!list || !*list)
		return;

	last = (*list);
	first = (*list)->next;

	while (first)
	{
		while (last && first->n < last->n)
		{
			if (last->prev)
				last->prev->next = first;
			else
				*list = first;

			if (first->next)
				first->next->prev = last;

			temp = first->next;
			first->next = last;
			first->prev = last->prev;
			last->next = temp;
			last->prev = first;

			print_list(*list);
			last = first->prev;
		}
		first = first->next;

		if (first)
			last = first->prev;
	}
}
