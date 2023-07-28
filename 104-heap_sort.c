#include <stdio.h>
#include <stdlib.h>

void heap_sort(int *array, size_t size);
void heapify(int *array, int n, int i);

void heap_sort(int *array, size_t size)
{

	int i;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i);

	for (i = size - 1; i > 0; i--)
	{
		int temp = array[0];

		array[0] = array[i];
		array[i] = temp;

		heapify(array, i, 0);
	}
}

void heapify(int *array, int n, int i)
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

		heapify(array, n, largest);
	}
}
