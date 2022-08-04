#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 *
 * Return: Pointer on the first node where value is located or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	size_t i;
	skiplist_t *position, *node_min;

	if (!list)
	{
		return (NULL);
	}

	position = list, node_min = list;
	while (position && position->next && (position->n) < value)
	{
		node_min = position;
		if (position->express)
		{
			position = position->express;

			printf("Value checked at index ");
			printf("[%lu] = [%d]\n", position->index, position->n);
		}
		else
			while (position->next)
				position = position->next;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
		   node_min->index, position->index);

	for (i = node_min->index;
		 i <= (position->index) && (node_min->n <= value);
		 i++, node_min = node_min->next)
	{
		printf("Value checked at index [%lu] = [%d]\n", i, node_min->n);
		if (node_min && (node_min->n) == value)
			return (node_min);
	}

	if (node_min)
		printf("Value checked at index [%lu] = [%d]\n", i, node_min->n);

	return (NULL);
}
