#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>

/**
 * radix_sort - Sorts an array of integers in ascending order
 * using the Radix sort algorithm.
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 *
 * Return: Nothing.
 */
void radix_sort(int *array, size_t size)
{
	int max = find_max(array, size);
	int exp;

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		count_sort(array, size, exp);
		print_array(array, size);
	}
}

/**
 * count_sort - Performs count sort on the array.
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 * @exp: The current digit place.
 *
 * Return: Nothing.
 */
void count_sort(int *array, size_t size, int exp)
{
	int *output = malloc(size * sizeof(int));
	int count[10] = {0};
	size_t i;

	if (!output)
		return;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i < SIZE_MAX; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}

/**
 * find_max - Finds the maximum value in an array.
 * @array: The array to find to the max value of.
 * @size: The number of elements in the array.
 *
 * Return: The maximum value.
 */
int find_max(int *array, size_t size)
{
	int max = INT_MIN;
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}
