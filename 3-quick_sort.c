#include "sort.h"

/**
 * swap - swaps 2 ints
 * @a: the first int
 * @b: the second int
 * Return: void
*/
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - splits the array to 2 parts, where pivot is in the middle
 * @array: the array to sort
 * @size: the size of the array
 * @low: the lowest index in the sub array to sort
 * @high: the highes index in the sub array to sort
 * Return: the index of the pivot
*/
int partition(int *array, size_t size, int low, int high)
{
	int pivot, i = low, j;

	pivot = array[high];
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			if (j != i)
			{
				swap(&array[j], &array[i]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != high)
	{
		swap(&array[high], &array[i]);
		print_array(array, size);
	}
	return (i);
}
/**
 * quick_sorting - the quick sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 * @low: the lowest index in the sub array to sort
 * @high: the highes value in the sub array to sort
 * Return: void
*/
void quick_sorting(int *array, size_t size, int low, int high)
{
	int part;

	if (low >= high)
	{
		return;
	}
	part = partition(array, size, low, high);
	quick_sorting(array, size, low, part - 1);
	quick_sorting(array, size, part + 1, high);
}
/**
 * quick_sort - a wrapper function for the quick sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 * Return: void
*/
void quick_sort(int *array, size_t size)
{
	quick_sorting(array, size, 0, size - 1);
}
