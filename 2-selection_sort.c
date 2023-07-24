#include"sort.h"
/**
 * selection_sort - sorts an array of integers
 *	in ascending order using the Selection sort algorithm
 * @array: pointer to array of int numbers
 * @size: int size of array
 * Return Void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j = 0;
	size_t mini, temp = 0;

	for (i = 0; i < size - 1; i++)
	{
		mini = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[mini])
			{
				mini = j;
			}
		}
		if (mini != i)
		{
			temp = array[i];
			array[i] = array[mini];
			array[mini] = temp;
			print_array(array, size);
		}
	}
}
