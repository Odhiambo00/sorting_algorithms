#include "sort.h"

/**
 * quick_sort - function entry point
 * @array: array to be sorted
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	sort_fast(array, 0, size - 1, size);
}

/**
 * sort_fast - implements sort_fast
 * @array: array to be sorted
 * @first: starting index
 * @last: ending index
 * @size: size of the array
 */

void sort_fast(int *array, int first, int last, size_t size)
{
	int i = 0;

	if (first < last)
	{
		i = split(array, first, last, size);

		sort_fast(array, first, i - 1, size);
		sort_fast(array, i + 1, last, size);
	}
}

/**
 * split - takes last element as pivot and places it at its correct position in
 * a sorted array, places all elements smaller to it to the left and greater
 * elements to the right of pivot
 * @array: array to be sorted
 * @first: starting index
 * @last: ending index
 * @size: size of the array
 * Return: i
 */

int split(int *array, int first, int last, size_t size)
{
	int pivot = array[last], i = first - 1, j = first, temp = 0;

	while (j <= last - 1)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;

			if (i != j)
				print_array(array, size);
		}
		j++;
	}
	temp = 0;
	i++;
	temp = array[i];
	array[i] = array[last];
	array[last] = temp;

	if (array[i] != array[last])
		print_array(array, size);

	return (i);
}
