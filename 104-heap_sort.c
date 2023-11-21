#include "sort.h"

/**
 * fixHeap - Fixes a heap using sift-down
 * @array: Array representing the heap
 * @root: Root index of the heap
 * @end: Last index of the heap
 * @size: Size of the array
 */
void fixHeap(int *array, size_t root, size_t end, size_t size)
{
	size_t left, right, swap;
	int temp;

	for (; (left = (2 * root) + 1) <= end; root = swap)
	{
		swap = root;
		right = left + 1;
		if (array[swap] < array[left])
			swap = left;
		if (right <= end && array[swap] < array[right])
			swap = right;
		if (swap == root)
			return;
		temp = array[root];
		array[root] = array[swap];
		array[swap] = temp;
		print_array(array, size);
	}
}

/**
 * buildHeap - Builds a heap from an unsorted array
 * @array: Array to convert into a heap
 * @size: Size of the array
 */
void buildHeap(int *array, size_t size)
{
	size_t parent;

	for (parent = ((size - 1) - 1) / 2; 1; parent--)
	{
		fixHeap(array, parent, size - 1, size);
		if (parent == 0)
			break;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort
 * @array: Array to sort
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t end;
	int temp;

	if (array == NULL || size < 2)
		return;
	buildHeap(array, size);
	end = size - 1;
	while (end > 0)
	{
		temp = array[end];
		array[end] = array[0];
		array[0] = temp;
		print_array(array, size);
		end--;
		fixHeap(array, 0, end, size);
	}
}
