#include "sort.h"
#include <stdio.h>

/**
 * quick_sort_hoare - Sorts an array of integers, using Quick
 * Sort algorithm and Hoare partition scheme.
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 *
 * Return: Nothing.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_hoare_recursion(array, 0, size - 1);
}

/**
 * quicksort_hoare_recursion - Perform quick sort using hoare
 * partition scheme recursively.
 * @array: Array to be sorted.
 * @low: Lower index of the array.
 * @high: higher index of the array.
 * @size: Number of elements in the array.
 *
 * Return: Nothing.
 */
void quicksort_hoare_recursion(int *array, int low, int high)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = hoare_partition(array, low, high);

		quicksort_hoare_recursion(array, low, pivot_index);
		quicksort_hoare_recursion(array, pivot_index + 1, high);
	}
}

/**
 * hoare_partition - Chooses the pivot and partitions the array using
 * the hoare partition scheme.
 * @array: Array to be sorted.
 * @low: Lower index of the array.
 * @high: higher index of the array.
 * @size: Number of elements in the array.
 *
 * Return: The index of the pivot after partitioning.
 */
int hoare_partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		do
		{
			i++;
		} while (array[i] < pivot);

		do
		{
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return(j);
		
		swap(&array[i], &array[j]);
		print_array(array, high - low + 1);
	}
}

/**
 * swap - Swap elements in an array.
 * @a: Pointer to first element in an array.
 * @b: Pointer to second element in array.
 *
 * Return: Nothing.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
