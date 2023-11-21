#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly lined list using
 * the cocktail shaker algorithm.
 * @list: Pointer to the pointer to the head of the list.
 *
 * Return: Nothing.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *start = NULL;
	listint_t *end = NULL;

	if (list == NULL || *list == NULL)
		return;

	do {
		swapped = 0;
		for (start = *list; start->next != end; start = start->next)
		{
			if (start->n > start->next->n)
			{
				swap_nodes(list, start, start->next);
				swapped = 1;
			}
		}
		if (!swapped)
			break;

		end = start;

		swapped = 0;
		for (; start->prev != NULL; start = start->prev)
		{
			if (start->n < start->prev->n)
			{
				swap_nodes(list, start->prev, start);
				swapped = 1;
			}
		}
	} while (swapped);
}

/**
 * swap_nodes - Swaps the nodes in a linked list.
 * @list: Pointer to the pointer to the head of the list.
 * @a: Pointer to the node to swap.
 * @b: Pointer to the other node to swap.
 *
 * Return: Nothing.
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	if (a == NULL || b == NULL || list == NULL || *list == NULL)
		return;

	if (a->prev != NULL)
		a->prev->next = b;
	else
		*list = b;

	if (b->next != NULL)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
	print_list(*list);
}
