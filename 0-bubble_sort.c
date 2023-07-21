#include "sort.h"

/**
 * swap - swaps 2 numbers
 * @a: the first number
 * @b: the second number
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
 * bubble_sort - sorts an array using bubble sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 * Return: void
*/

void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < (size - i - 1); j++)
		{
			if (array[j + 1] < array[j])
			{
				swap(&array[j + 1], &array[j]);
				print_array(array, size);
			}
		}
	}
}
