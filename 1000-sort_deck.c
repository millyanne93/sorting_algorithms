#include "deck.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * get_card_value - Gets the relative value of a card from its string value
 * @str: String value of the card
 *
 * Return: Relative value of the card (0 through 12)
 */
int get_card_value(const char *str)
{
	int i;
	char *card_values[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9",
                            "10", "Jack", "Queen", "King"};

	for (i = 0; i < 13; i++)
	{
		if (strcmp(str, card_values[i]) == 0)
		{
			return (i);
		}
	}
	exit(1);
}

/**
 * swap_nodes - Swaps a node with the next node in the list
 * @list: Double pointer to the beginning of the list
 * @node: Node to swap
 *
 * Return: void
 */
void swap_nodes(deck_node_t **list, deck_node_t *node)
{
	node->next->prev = node->prev;

	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}

/**
 * sort_deck - Sorts a linked list deck of cards
 * @deck: Double pointer to the deck to sort
 *
 * Return: void
 */
void sort_deck(deck_node_t **deck)
{
	char was_swapped = 1;
	int card_value_1, card_value_2;
	deck_node_t *current_node;

	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;
	current_node = *deck;

	while (was_swapped != 0)
	{
		was_swapped = 0;

		while (current_node->next != NULL)
		{
			card_value_1 = get_card_value(current_node->card->value)
				+ 13 * current_node->card->kind;
			card_value_2 = get_card_value(current_node->next->card->value)
				+ 13 * current_node->next->card->kind;
			if (card_value_1 > card_value_2)
			{
				swap_nodes(deck, current_node);
				was_swapped = 1;
			}
			else
			{
				current_node = current_node->next;
			}
		}
		if (was_swapped == 0)
			break;
		was_swapped = 0;
		while (current_node->prev != NULL)
		{
			card_value_1 = get_card_value(current_node->card->value)
				+ 13 * current_node->card->kind;
			card_value_2 = get_card_value(current_node->prev->card->value)
				+ 13 * current_node->prev->card->kind;
			if (card_value_1 < card_value_2)
			{
				swap_nodes(deck, current_node->prev);
				was_swapped = 1;
			}
			else
			{
				current_node = current_node->prev;
			}
		}
	}
}
