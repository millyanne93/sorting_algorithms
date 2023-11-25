#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list using
 * the cocktail shaker algorithm.
 * @list: Pointer to the pointer to the head of the list.
 *
 * Return: Nothing.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *temp;

	if (list == NULL || *list == NULL)
		return;
	temp = *list;
	while (swapped != 0)
	{
		swapped = 0;
		while (temp->next != NULL)
		{
			if (temp->next->n < temp->n)
			{
				swap_nodes(list, temp, temp->next);
				swapped = 1;
				print_list(*list);
			}
			else
				temp = temp->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		while (temp->prev != NULL)
		{
			if (temp->prev->n > temp->n)
			{
				swap_nodes(list, temp->prev, temp);
				swapped = 1;
				print_list(*list);
			}
			else
				temp = temp->prev;
		}
	}
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

	if (a->next != NULL)
		a->next->prev = a;
}
