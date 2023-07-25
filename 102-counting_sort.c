#include "sort.h"

/**
 * max_num - function to get the max num
 * @array: array
 * @n: size
 * Return: max
 */

int max_num(int array[], int n)
{
	int i;
	int max;

	max = array[0];
	for (i = 1; i < n; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort - function to implement count sort
 * @array: array
 * @size: size
 */

void counting_sort(int array[], int size)
{
	int i;
	int max;
	int *temp, *count;

	max = max_num(array, size);
	temp = (int *) malloc((size + 1) * sizeof(int));
	count = (int *) malloc((max + 1) * sizeof(int));

	for (i = 0; i <= max; ++i)
	{
		count[i] = 0;
	}

	for (i = 0; i < size; i++)
	{
		count[array[i]]++;

	}

	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];


	for (i = size - 1; i >= 0; i--)
	{
		temp[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (i = 0; i < size; i++)
	{
		array[i] = temp[i];

	}

	print_array(count, max + 1);
	free(temp);
	free(count);
}
