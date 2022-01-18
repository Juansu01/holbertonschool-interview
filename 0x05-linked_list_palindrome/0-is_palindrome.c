#include "lists.h"


int is_palindrome(listint_t **head)
{
	listint_t *current;
	unsigned int n; /* number of nodes */

	current = *head;
	n = 0;
	while (current != NULL)
	{
		current = current->next;
		n++;
	}
	current = *head;
	int my_arr[n];
	n = 0;
	while (current != NULL)
	{
		my_arr[n] = current->n;
		current = current->next;
		n++;
	}
	current = *head;

	while (n != 0)
	{
		n--;
		while (current != NULL)
		{
			if (my_arr[n] != current->n)
			{
				return (0);
			}
			current = current->next;
			break;
		}

	}

	return (1);
}
