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
	size_t last_sorted = size;
	size_t current;
	int swapped = 1;
	int temp;

	if (array == NULL || size < 2)
		return;
	while (swapped)
	{
		current = 0;

		swapped = 0;

		while (current < last_sorted - 1)
		{
			if (array[current] > array[current + 1])
			{
				temp = array[current];

				array[current] = array[current + 1];
				array[current + 1] = temp;
				swapped = 1;
				print_array(array, size);
			}
			current++;
		}
		if (swapped)
			last_sorted--;
	}
}
