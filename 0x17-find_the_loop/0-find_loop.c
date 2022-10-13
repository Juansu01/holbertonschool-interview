#include "lists.h"

/**
 * find_listint_loop - Finds address of node where the loop starts.
 * @head: Pointer to the beginning of linked list.
 * Return: Address of node, NULL otherwise.
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tortoise, *hare;

	if (head == NULL)
	{
		return (NULL);
	}
	tortoise = head;
	hare = tortoise;
	while (tortoise && hare && hare->next)
	{
		tortoise = tortoise->next;
		hare = (hare->next)->next;
		if (hare == tortoise)
		{
			tortoise = head;
			while (tortoise && hare)
			{
				if (tortoise == hare)
				{
					return (tortoise);
				}

				tortoise = tortoise->next;
				hare = hare->next;
			}
		}
	}
	return (NULL);
}
