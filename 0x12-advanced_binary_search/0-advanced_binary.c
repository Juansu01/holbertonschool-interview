#include "search_algos.h"

/**
 * my_binary - Searches for a value in a sorted array of integers.
 *
 * @array: Pointer to the first element in the array.
 * @size: Amount of numbers in the array.
 * @value: Number to look for.
 *
 * Return: The first index where the value is located, -1 otherwise.
 */

int my_binary(int *array, size_t size, int value)
{
    int center = ((size - 1) / 2);
    size_t i = 0;
    int res = 0;

    printf("Searching in array: ");
    for (i = 0; i < size; i++)
    {
        printf("%d", array[i])

        if (i != (size - 1))
        {
            printf(", ");
        }
        else
        {
            printf("\n");
        }
    }

    if (array[center] == value && center == 0)
        return (center);
    else if (size == 1)
        return(-1);

    if (array[center] >= value)
        return (my_binary(array, center + 1, value))

    center++;
    res = my_binary(&array[center], size - half, value);

    if (result == -1)
    {
        return (-1);
    }
    return (center + res);
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers.
 *
 * @array: Pointer to the first element in the array.
 * @size: Amount of numbers in the array.
 * @value: Number to look for.
 *
 * Return: The first index where the value is located, -1 otherwise.
 */

int advanced_binary(int *array, size_t size, int value)
{

	if (!array)
    {
        return (-1);
    }

    if (size == 0)
    {
        return (-1);
    }

    return my_binary(array, size, value);

}