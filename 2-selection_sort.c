#include "sort.h"

/**
 * swap - swaps 2 values
 * @a: the first int
 * @b: the seconde int
 * Reuturn: void
*/
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * get_min_index - gets the minimum index for a sub array
 * @array: the array to sort
 * @start: the starting index of the sub array
 * @size: the size of the array
 * Return: min_index
*/
size_t get_min_index(int *array, int start, size_t size)
{
	size_t i, min_index;
	int min_value;

	min_value = array[start];
	min_index = start;
	for (i = start + 1; i < size; i++)
	{
		if (array[i] < min_value)
		{
			min_value = array[i];
			min_index = i;
		}
	}
	return (min_index);
}
/**
 * selection_sort - sorts an array using selection sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 * Return: void
*/
void selection_sort(int *array, size_t size)
{
	size_t i, min_index;

	for (i = 0; i < size; i++)
	{
		min_index = get_min_index(array, i, size);
		if (i != min_index)
		{
			swap(&array[i], &array[min_index]);
			print_array(array, size);
		}
	}
}
