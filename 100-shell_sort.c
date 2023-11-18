#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using the
 * Shell sort algorithm
 * @array: array to sort
 * @size: size of the array to sort
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t inner, outer, gap = 1;
	int temp;

	if (array == NULL || size < 2)
		return;
	while (gap < size / 3)
		gap = gap * 3 + 1;
	while (gap > 0)
	{
		for (outer = gap; outer < size; outer++)
		{
			temp = array[outer];
			inner = outer;
			while (inner >= gap && array[inner - gap] > temp)
			{
				array[inner] = array[inner - gap];
				inner -= gap;
			}
			array[inner] = temp;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
