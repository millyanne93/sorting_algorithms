#include "sort.h"
/**
 * counting_sort - sorts an array of integers in ascending order using the
 * Counting sort algorithm
 * @array: array to sort
 * @size: size of the array to sort
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int *arr_copy, *count_arr;
	size_t idx, max_val = 0, cumulative_count = 0, temp;

	if (array == NULL || size < 2)
		return;
	arr_copy = malloc(sizeof(int) * size);
	if (arr_copy == NULL)
		return;
	for (idx = 0; idx < size; idx++)
	{
		arr_copy[idx] = array[idx];
		if (array[idx] > (int)max_val)
			max_val = array[idx];
	}
	count_arr = malloc(sizeof(int) * (max_val + 1));
	if (count_arr == NULL)
	{
		free(arr_copy);
		return;
	}
	for (idx = 0; idx <= max_val; idx++)
		count_arr[idx] = 0;
	for (idx = 0; idx < size; idx++)
		count_arr[array[idx]] += 1;
	for (idx = 0; idx <= max_val; idx++)
	{
		temp = count_arr[idx];
		count_arr[idx] = cumulative_count;
		cumulative_count += temp;
	}
	for (idx = 0; idx < size; idx++)
	{
		array[count_arr[arr_copy[idx]]] = arr_copy[idx];
		count_arr[arr_copy[idx]] += 1;
	}
	print_array(count_arr, max_val + 1);
	free(count_arr);
	free(arr_copy);
}
