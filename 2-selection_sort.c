#include "sort.h"
#include <stdio.h>

/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: The array
 * @size: The size of the array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t pass = 0;
	size_t min;
	size_t i;
	int temp;

	if (array == NULL || size < 2)
		return;
	while (pass < size - 1)
	{
		min = pass;
		i = pass + 1;
		while (i < size)
		{
			if (array[i] < array[min])
				min = i;
			i++;
		}
		if (min != pass)
		{
			temp = array[pass];
			array[pass] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
		pass++;
	}
}
