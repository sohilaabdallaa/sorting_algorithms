#include "sort.h"
#include <stdlib.h>

/**
 * merge - merges two sorted subarrays into one array
 * @array: array
 * @left: left subarray
 * @left_size: size of left subarray
 * @right: right subarray
 * @right_size: size of right subarray
 **/
void merge(int *array, int *left,
	       size_t left_size, int *right, size_t right_size)
{
	int *merged;
	size_t i, j, k;

	i = 0, j = 0, k = 0;

	merged = malloc(sizeof(int) * (left_size + right_size));
	printf("Merging...\n[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	while (i < left_size && j < right_size)
		merged[k++] = (left[i] <= right[j]) ? left[i++] : right[j++];

	while (i < left_size)
		merged[k++] = left[i++];

	while (j < right_size)
		merged[k++] = right[j++];

	for (i = 0; i < left_size + right_size; i++)
		array[i] = merged[i];
	free(merged);

	printf("[Done]: ");
	print_array(array, left_size + right_size);
}

/**
 * merge_sort - sorts an array of integers
 * @array: array
 * @size: size
 **/
void merge_sort(int *array, size_t size)
{
	size_t mid;
	int *left, *right;

	if (size < 2)
		return;

	mid = size / 2;
	left = array;
	right = array + mid;

	merge_sort(left, mid);
	merge_sort(right, size - mid);

	merge(array, left, mid, right, size - mid);
}
