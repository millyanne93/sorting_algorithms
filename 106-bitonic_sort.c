#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two elements in an array.
 * @arr: The array to perform the swap.
 * @first: Index of the first element to be swapped.
 * @second: Index of the second element to be swapped.
 * @asc: Indicates the order for swapping.
 */
void _swap(int arr[], int first, int second, int asc)
{
	int temp;

	if (asc == (arr[first] > arr[second]))
	{
		temp = arr[first];
		arr[first] = arr[second];
		arr[second] = temp;
	}
}

/**
 * merge - Merges bitonic sequences recursively in both orders.
 * @arr: The array to perform merging.
 * @low: The starting index of the elements to be merged.
 * @elems: The number of elements to be merged.
 * @asc: Indicates the order for merging.
 */
void _merge(int arr[], int low, int elems, int asc)
{
	int mid, i;

	if (elems > 1) 
	{
		mid = elems / 2;
		for (i = low; i < low + mid; i++)
			_swap(arr, i, i + mid, asc);
		_merge(arr, low, mid, asc);
		_merge(arr, low + mid, mid, asc);
	}
}

/**
 * bitonic_sort_recursive - Performs bitonic sort recursively.
 * @arr: The array to be sorted.
 * @low: The starting index of the elements to be sorted.
 * @elems: The number of elements to be sorted.
 * @asc: Indicates the order for sorting (1 for ascending, 0 for descending).
 * @size: The size of the array.
 */
void bitonic_sort_recursive(int arr[], int low, int elems, int asc, int size)
{
	int mid;

	if (elems > 1)
	{
		if (asc >= 1)
		{
			printf("Merging [%i/%i] (UP):\n", elems, size);
			print_array(&arr[low], elems);
		}
		else
		{
			printf("Merging [%i/%i] (DOWN):\n", elems, size);
			print_array(&arr[low], elems);
		}
		mid = elems / 2;
		bitonic_sort_recursive(arr, low, mid, 1, size);
		bitonic_sort_recursive(arr, low + mid, mid, 0, size);
		_merge(arr, low, elems, asc);
		if (asc <= 0)
		{
			printf("Result [%i/%i] (DOWN):\n", elems, size);
			print_array(&arr[low], elems);
		}
		if (asc >= 1)
		{
			printf("Result [%i/%i] (UP):\n", elems, size);
			print_array(&arr[low], elems);
		}
	}
}

/**
 * bitonic_sort - Performs bitonic sort on the given array.
 * @arr: The array to be sorted.
 * @size: The size of the array.
 */
void bitonic_sort(int *arr, size_t size) 
{
	int asc = 1;

	if (!arr || size < 2)
		return;
	bitonic_sort_recursive(arr, 0, size, asc, size);
}
