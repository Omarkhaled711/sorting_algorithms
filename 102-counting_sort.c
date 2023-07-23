#include "sort.h"

/**
 * counting_sort - sorts an array according to count sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 * Return: void
*/
void counting_sort(int *array, size_t size)
{
	int *count, *tempArr, k;
	size_t i;

	if (size == 0)
		return;
	k = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > k)
			k = array[i];
	}
	count = malloc((k + 1) * sizeof(int));
	if (count == NULL)
		return;
	tempArr = malloc(size * sizeof(int));
	if (tempArr == NULL)
	{
		free(count);
		return;
	}
	for (i = 0; i <= (size_t) k; i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
		count[array[i]]++;
	for (i = 1; i <= (size_t) k; i++)
		count[i] += count[i - 1];
	print_array(count, k + 1);
	for (i = 0; i < size; i++)
		tempArr[--count[array[i]]] = array[i];
	for (i = 0; i < size; i++)
		array[i] = tempArr[i];
	free(count);
	free(tempArr);
}
