#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void heap_sort(int *array, size_t size);
void heapify(int *array, int n, int i, size_t size);

/**
 * heap_sort - heap sort
 * @array: array
 * @size: size
 */

void heap_sort(int *array, size_t size)
{

	int i;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		int temp = array[0];

		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}

/**
 * heapify - heapify func
 * @array: array
 * @n: size
 * @i: largest
 * @size: size
 */

void heapify(int *array, int n, int i, size_t size)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && array[l] > array[largest])
		largest = l;

	if (r < n && array[r] > array[largest])
		largest = r;

	if (largest != i)
	{
		int temp = array[i];

		array[i] = array[largest];
		array[largest] = temp;

		print_array(array, size);
		heapify(array, n, largest, size);
	}
}
