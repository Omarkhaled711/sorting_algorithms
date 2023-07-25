#include "sort.h"


/**
 * get_max - gets the max num in an array
 * @array: the array to search in
 * @size: the size of the array
 * Return: the max number
*/
int get_max(int *array, size_t size)
{
	int num = 0;
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (array[i] > num)
			num = array[i];
	}
	return  (num);
}

/**
 * count_sort - sorts digit based on position value according to count sort
 * @array: the array to sort
 * @size: the size of the array
 * @pos: the postion to consider (units, tens, hunderds, ...etc)
 * Return: void
*/
void count_sort(int *array, size_t size, int pos)
{
	int count[10] = {0}, *temp_arr;
	size_t i;

	temp_arr = malloc(size * sizeof(int));
	if (temp_arr == NULL)
		return;
	for (i = 0; i < size; i++)
		count[(array[i] / pos) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = size - 1; ; i--)
	{
		temp_arr[--count[(array[i] / pos) % 10]] = array[i];
		if (i == 0)
			break;
		/* doing it like that because size_t types cannot be -ve */
	}
	for (i = 0; i < size; i++)
		array[i] = temp_arr[i];
	free(temp_arr);
}

/**
 * radix_sort - sorts an array according to radix sort
 * @array: the array to sort
 * @size: the size of the array
 * Return: void
*/
void radix_sort(int *array, size_t size)
{
	int pos, max_num;

	if (size == 0)
		return;
	max_num = get_max(array, size);
	for (pos = 1; max_num / pos > 0; pos *= 10)
	{
		count_sort(array, size, pos);
		print_array(array, size);
	}
}
