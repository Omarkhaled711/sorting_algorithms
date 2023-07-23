#include "sort.h"

/**
 * swap - swaps 2 ints
 * @a: the first integer
 * @b: the second integer
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
 * get_gap - gets the gap using Knuth sequence
 * @size: the size of the array
 * Return: the gap
*/
size_t get_gap(size_t size)
{
	size_t gap = 1;

	while (gap < size)
	{
		gap = 3 * gap + 1;
	}
	gap = (gap - 1) / 3;
	return (gap);
}
/**
 * shell_sort - sorts the array using the shell sort
 * @array: the array to sort
 * @size: the size of the array
 * Return: void
*/
void shell_sort(int *array, size_t size)
{
	size_t gap, j, i;

	gap = get_gap(size);
	for (; gap >= 1; gap = (gap - 1) / 3)
	{
		for (j = gap; j < size; j++)
		{
			for (i = j - gap; ; i = i - gap)
			{
				if (array[i + gap] < array[i])
					swap(&array[i], &array[i + gap]);
				else
					break;
				if (gap > i)
					break;
			}
		}
		print_array(array, size);
	}
}
