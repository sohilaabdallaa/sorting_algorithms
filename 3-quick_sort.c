#include "sort.h"

int partition(int arr[], int low, int high, int size);
void quickSort(int *array, int low, int high, size_t size);


/**
 * quick_sort - the driver or main function for quick sort
 * @array: array to be sorted
 * @size: higher bound of the array
 *
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quickSort(array, 0, size - 1, size);
}

/**
 * quickSort - function to help the wraper
 * @array: arr
 * @low: lower end
 * @high: higher end
 * @size: size
 */

void quickSort(int *array, int low, int high, size_t size)
{
	size_t partition_index;

	if (low < high)
	{
		partition_index = partition(array, low, high, size);
		quickSort(array, low, partition_index - 1, size);
		quickSort(array, partition_index + 1, high, size);
	}
}

/**
 * swap - function to swap two elements
 * @a: first element
 * @b: second element
 */

void swap(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

/**
 * partition - function to partition the array
 * and a utility function for quicksort
 * @arr: array to be sorted
 * @low: lower bound of the array
 * @high: higher bound of the array
 * @size: size
 *
 * Return: return the index
 */


int partition(int arr[], int low, int high, int size)
{
	int pivot, i, j;

	pivot = arr[high];

	i = (low - 1);

	for (j = low; j < high; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			if (arr[i] != arr[j])
			{
				swap(&arr[j], &arr[i]);
				print_array(arr, size);
			}
		}
	}
	if (arr[i + 1] != arr[high])
	{
		swap(&arr[i + 1], &arr[high]);
		print_array(arr, size);
	}
	return (i + 1);

}
