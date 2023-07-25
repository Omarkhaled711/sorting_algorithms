#include "sort.h"

/**
 * swap - swaps 2 integers
 * @a: the first integer
 * @b: the second integer
 * Return: void
*/
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * heapify - maintain the max heap property for the tree (array)
 * @array: the array in consideration
 * @total_size: the total size of the array as it's needed to print the arr
 * @size: the active size of the heap (array) (as we are deleting elements)
 * @i: the index of the element
 * Return: void
*/
void heapify(int *array, size_t total_size, size_t size, size_t i)
{
	size_t large = i, left, right;

	left = 2 * (i + 1) - 1;
	right = 2 * (i + 1);

	if (left < size && array[left] > array[large])
	{
		large = left;
	}
	if (right < size && array[right] > array[large])
	{
		large = right;
	}
	if (i != large)
	{
		swap(&array[i], &array[large]);
		print_array(array, total_size);
		heapify(array, total_size, size, large);
	}
}

/**
 * heap_sort - sorts an array according to heap sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 * Return: void
*/
void heap_sort(int *array, size_t size)
{
	size_t i;

	if (size == 0)
		return;
	for (i = (size / 2) - 1; ; i--)
	{
		heapify(array, size, size, i);
		if (i == 0)
			break;
	}
	for (i = size; i > 0; i--)
	{
		if (i - 1 != 0)
		{
			swap(&array[i - 1], &array[0]);
			print_array(array, size);
		}
		heapify(array, size, i - 1, 0);
	}
}

