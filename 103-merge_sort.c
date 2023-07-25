#include "sort.h"


/**
 * print_array_from - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 * @start: the starting index to print from
 */
void print_array_from(const int *array, size_t size, size_t start)
{
	size_t i;

	i = start;
	while (array && i < size)
	{
		if (i > start)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}

/**
 * merge - merges 2 sub arrays in a sorted way
 * @array: the array to sort
 * @left: the start of the sub array
 * @mid: the middle element in the sub array
 * @right: the ending index of the sub array (excluded)
 * @temp_arr: the temp array to store in
 * Return: void
*/
void merge(int *array, size_t left, size_t mid, size_t right, int *temp_arr)
{
	size_t i = left, j = mid, k = left;

	printf("Merging...\n");
	printf("[left]: ");
	print_array_from(array, mid, left);
	printf("[right]: ");
	print_array_from(array, right, mid);
	while (i < mid && j < right)
	{
		if (array[i] <= array[j])
		{
			temp_arr[k] = array[i];
			i++;
		}
		else
		{
			temp_arr[k] = array[j];
			j++;
		}
		k++;
	}
	while (i < mid)
	{
		temp_arr[k] = array[i];
		i++;
		k++;
	}
	while (j < right)
	{
		temp_arr[k] = array[j];
		j++;
		k++;
	}
	for (k = left; k < right; k++)
		array[k] = temp_arr[k];
	printf("[Done]: ");
	print_array_from(array, right, left);

}
/**
 * merge_sorting - implements merge sort algorithm
 * @array: the array to sort
 * @left: the starting index of the sub array
 * @right: the ending index of the sub array (excluded)
 * @temp_arr: temp array to store resuls in
 * Return: void
 *
*/
void merge_sorting(int *array, size_t left, size_t right, int *temp_arr)
{
	int mid;

	if (left + 1 >= right)
		return;

	mid = left + (right - left) / 2;
	merge_sorting(array, left, mid, temp_arr);
	merge_sorting(array, mid, right, temp_arr);
	merge(array, left, mid, right, temp_arr);

}

/**
 * merge_sort - a wrapping function for merge sorting
 * @array: the array to sort
 * @size: the size of the array
 * Reutrn: void
*/
void merge_sort(int *array, size_t size)
{
	int *temp_arr;

	temp_arr = malloc(size * sizeof(int));
	if (temp_arr == NULL)
		return;
	merge_sorting(array, 0, size, temp_arr);
	free(temp_arr);
}
