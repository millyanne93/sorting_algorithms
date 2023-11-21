#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two elements in an array
 * @a: Pointer to first integer.
 * @b: Pointer to second integer.
 *
 * Return: Nothing.
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - Implements the Lomuto partition scheme.
 * @array: The array to be sorted.
 * @low: Starting index of the partition.
 * @high: Last index of the partition.
 * @size: Size of the array.
 *
 * Return: Index of the pivot element.
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot;
	int i;
	int j;

	pivot = array[high];
	i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			swap(&array[i], &array[j]);
			i++;
			print_array(array, size);
		}
	}
	swap(&array[i], &array[high]);
	print_array(array, size);

	return (i);
}

/**
 * quicksort_recursion - Recursive function to perform quicksort.
 * @array: The array to be sorted.
 * @low: Starting index of the partition.
 * @high: Last index of the partition.
 * @size: Size of the array.
 *
 * Return: Nothing.
 */
void quicksort_recursion(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, low, high, size);
		quicksort_recursion(array, low, pivot_index - 1, size);
		quicksort_recursion(array, pivot_index + 1, high, size);
	}
}

/**
 * quicksort - Sorts integers using quicksort algorithm.
 * @array: Array to be sorted.
 * @size: Size of the array.
 *
 * Return: Nothing.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	quicksort_recursion(array, 0, size - 1, size);
}