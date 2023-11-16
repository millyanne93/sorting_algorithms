#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order using the
 * Bubble sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t current, last_sorted, new_last_sorted;
	int tmp;

	if (array == NULL || size < 2)
		return;
	last_sorted = size;
	while (last_sorted > 0)
	{
		new_last_sorted = 0;
		for (current = 0; current < last_sorted - 1; current++)
		{
			if (array[current] > array[current + 1])
			{
				tmp = array[current];
				array[current] = array[current + 1];
				array[current + 1] = tmp;
				new_last_sorted = current + 1;
				print_array(array, size);
			}
		}
		last_sorted = new_last_sorted;
	}
}
