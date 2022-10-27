#include "sort.h"

/**
 * copy_buffer - Copies from source into dest
 *
 * @src: source buffer
 * @dest: destination buffer
 * @size: size of buffers
 * Return: Doesn't return
 */
void copy_buffer(int *src, int *dest, int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		dest[i] = src[i];
	}

}

/**
 * _merge_sort - merges two sorted arrays in ascending order
 * @array: first set of data
 * @buff: second set of data
 * @minL: lower range of first set of data
 * @maxL: upper range of first set of data
 * @minR: lower range of second set of data
 * @maxR: upper range of second set of data
 *
 * Return: Doesn't return
 */
void _merge_sort(int *array, int *buff, int minL, int maxL, int minR, int maxR)
{
	int i = minL, j = minR, k = minL;

	while (i <= maxL || j <= maxR)
	{
		if (i <= maxL && j <= maxR)
		{
			if (buff[i] <= buff[j])
				array[k] = buff[i], k++, i++;
			else
				array[k] = buff[j], k++, j++;
		}
		else if (i > maxL && j <= maxR)
		{
			array[k] = buff[j], k++, j++;
		}
		else
		{
			array[k] = buff[i], k++, i++;
		}
	}
}

/**
 * print_range - Takes a range and prints values inside that range
 * @array: Array with values to be printed
 * @beginning: Where the range starts
 * @end: Where the range ends
 *
 * Return: Doesn't return
 */
void print_range(int *array, int beginning, int end)
{
	int i;

	for (i = beginning; i <= end; i++)
	{
		if (i > beginning)
		{
			printf(", ");
		}
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * split_data - Splits data into merge tree
 *
 * @array: Array of data to be split
 * @buff: Auxiliary array of data for merging
 * @min: Min range of data in array
 * @max: Max range of data in array
 * @size: size of total data
 *
 * Return: Doesn't return
 */
void split_data(int *array, int *buff, int min, int max, int size)
{
	int mid, tmax, minL, maxL, minR, maxR;

	if ((max - min) <= 0)
	{
		return;
	}

	mid = (max + min + 1) / 2;
	tmax = max;
	max = mid - 1;
	minL = min;
	maxL = max;
	split_data(array, buff, min, max, size);

	min = mid;
	max = tmax;
	minR = min;
	maxR = max;
	split_data(array, buff, min, max, size);

	printf("Merging...\n");
	printf("[left]: ");

	print_range(array, minL, maxL);
	printf("[right]: ");

	print_range(array, minR, maxR);
	_merge_sort(array, buff, minL, maxL, minR, maxR);
	copy_buffer(array, buff, size);

	printf("[Done]: ");
	print_range(array, minL, maxR);
}

/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge sort algorithm
 *
 * @array: array of data to be sorted
 * @size: size of data
 *
 * Return: No Return
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (size < 2)
	{
		return;
	}

	buff = malloc(sizeof(int) * size);
	if (!buff)
	{
		return;
	}

	copy_buffer(array, buff, size);

	split_data(array, buff, 0, size - 1, size);

	free(buff);
}
