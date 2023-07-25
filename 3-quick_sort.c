#include "sort.h"

int partition(int arr[], int low, int high);


/**
 * quickSort - the driver or main function for quick sort
 * @arr: array to be sorted
 * @low: lower bound of the array
 * @high: higher bound of the array
 *
 */


void quickSort(int arr[], int low, int high)
{
	int partition_index;

	if (low < high)
	{
		partition_index = partition(arr, low, high);
		quickSort(arr, low, partition_index - 1);
		quickSort(arr, partition_index + 1, high);
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
 * partition - function to partition the array and a utility function for quicksort
 * @arr: array to be sorted
 * @low: lower bound of the array
 * @high: higher bound of the array
 *
 * Return: return the index
 */


int partition(int arr[], int low, int high)
{
	int pivot, i, j;

	pivot = arr[high];

	i =  (low - 1);

	for (j = low; j < high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[j], &arr[i]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);

}
