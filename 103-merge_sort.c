#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using Merge Sort.
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 *
 * Return: Nothing.
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	merge_recursive(array, size);
}

/**
 * merge_recursive - Recursively divides and merges the array.
 * @array: Array to be sorted.
 * @size: Number of array elements.
 *
 * Return: Nothing.
 */
void merge_recursive(int *array, size_t size)
{
	size_t middle = size / 2;
	int *left = array;
	int *right = array + middle;

	if (size < 2)
		return;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, middle);
	printf("[right]: ");
	print_array(right, size - middle);
	merge_recursive(left, middle);
	merge_recursive(right, size - middle);

	merge(array, size, left, middle, right, size - middle);
}

/**
 * merge - Merges two subarrays into one sorted array.
 * @array: The initial array.
 * @size: The number of elements in the array.
 * @left: The subarray on the left.
 * @left_size: Number of elements in left subarray.
 * @right: The subarray on the right.
 * @right_size: Number of elements in the right subarray.
 *
 * Return: Nothing.
 */
void merge(int *array, size_t size, int *left, size_t left_size, int *right, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;
	int *temp = malloc(size * sizeof(int));

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
			temp[k++] = left[i++];
		else
			temp[k++] = right[j++];
	}

	while (i < left_size)
		temp[k++] = left[i++];

	while (j < right_size)
		temp[k++] = right[j++];

	for (i = 0; i < size; i++)
		array[i] = temp[i];

	printf("[Done]: ");
	print_array(array, size);
	free(temp);
}
