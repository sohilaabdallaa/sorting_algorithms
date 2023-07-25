#include "sort.h"

#include <malloc.h>

/**
 * merge - utility function to merge the divided arrays
 * @arr: array
 * @l: left
 * @r: right
 */

void merge (int arr[], int l, int r)
{
    int mid, i, j, k, c;
    int *temp;

    mid = (l + r) / 2;
    temp = (int *) malloc(sizeof(int) * (r - l + 1));
    i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r)
    {
        if (arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= r)
    {
        temp[k++] = arr[j++];
    }
    for (c = l; c <= r; c++)
        arr[c] = temp[c - l];
}

void mergeSortFunc(int arr[], int l, int r);

/**
 * merge_sort - wrapper function
 * @array: array 
 * @size: size 
 */
void merge_sort(int *array, size_t size)
{
    mergeSortFunc(array, 0, size - 1);
}

/**
 * mergeSort - the main merge sort function
 * @arr: array 
 * @l: left
 * @r: right
 */
void mergeSortFunc(int arr[], int l, int r)
{
    int mid;
    if (l < r)
    {
        mid = l + (r - 1) / 2;
        mergeSortFunc(arr, l, mid);
        mergeSortFunc(arr, mid + 1, r);
        merge(arr, l, r);
    }
}
