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
 * lomuto_partition - Implements the Lomuto partition scheme.
 * @array: The array to be sorted.
 * @low: Starting index of the partition.
 * @high: Last index of the partition.
 * @size: Size of the array.
 *
 * Return: Index of the pivot element.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot;
	int i;
	int j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
			swap(&array[i], &array[j]);
			print_array(array, size);
			}
		}
	}
	if (array[i +1] != array[high])
	{
	swap(&array[i + 1], &array[high]);
	print_array(array, size);
	}
	return (i + 1);
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
		pivot_index = lomuto_partition(array, low, high, size);
		quicksort_recursion(array, low, pivot_index - 1, size);
		quicksort_recursion(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Sorts integers using quicksort algorithm.
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
