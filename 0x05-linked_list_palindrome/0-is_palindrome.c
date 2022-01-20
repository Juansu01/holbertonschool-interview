#include "lists.h"

/**
 * is_palindrome - function that tells whether
 * a linked list is a palindrome or not.
 *
 * @head: pointer to the first node of the linked list.
 * Return: Returns 1 if its palindrome, 0 otherwise.
 */

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
