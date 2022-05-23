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
	int result;

	current = *head;
	n = 0;
	while (current != NULL)
	{
		current = current->next;
		n++;
	}
	current = *head;
	result = is_palindrome_two(head, n);

	return (result);
}

/**
 * is_palindrome_two - function that tells whether
 * a linked list is a palindrome or not.
 *
 * @head: pointer to the first node of the linked list.
 * @my_size: integer to be used to set my_arr size.
 * Return: Returns 1 if its palindrome, 0 otherwise.
 */

int is_palindrome_two(listint_t **head, int my_size)
{
	listint_t *current;
	unsigned int n; /* number of nodes */
	int my_arr[my_size];

	current = *head;
	n = 0;
	while (current != NULL)
	{
		current = current->next;
		n++;
	}
	current = *head;

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
