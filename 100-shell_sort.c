#include "sort.h"
/**
 * shell_sort - sorts an array of integers in ascending order
 *	using the Shell sort algorithm, using the Knuth sequence
 * @array: pointer to array of int.
 * @size: size of the array.
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, gap = 0;
	int num;

	if (array == NULL || size < 2)
		return;
	while (gap < size)
		gap = gap * 3 + 1;

	while (gap > 1)
	{
		gap = (gap - 1) / 3;
		for (i = gap; i < size; i++)
		{
			j = i;
			num = array[i];
			while (j >= gap && array[j - gap] > num)
			{
				array[j] = array[j - gap];
				j = j - gap;
			}
			array[j] = num;
		}
		print_array(array, size);
	}
}
