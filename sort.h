#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include "stdlib.h"

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Print Functions */

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);


/* Sorting Algorithms Functions */

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void swap(int *a, int *b);
void fixHeap(int *array, size_t root, size_t end, size_t size);
void buildHeap(int *array, size_t size);
int partition(int arr[], int low, int high);
void quicksort_recursion(int *array, int low, int high, size_t size);
void swap_nodes(listint_t **list, listint_t *a, listint_t *b);
void bitonic_sort_recursive(int arr[], int low, int elems, int asc, int size);
void _merge(int arr[], int low, int elems, int asc);
void _swap(int arr[], int first, int second, int asc);
int lomuto_partition(int *array, int low, int high, size_t size);

/*Advanced Tasks*/
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge(int *array, size_t size, int *left, size_t left_size,
		int *right, size_t right_size);
void merge_recursive(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
int find_max(int *array, size_t size);
void count_sort(int *array, size_t size, int exp);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void quicksort_hoare_recursion(int *array, int low, int high);
int hoare_partition(int *array, int low, int high);

#endif /* SORT_H */
