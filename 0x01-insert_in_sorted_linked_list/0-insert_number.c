#include "lists.h"

/**
 * insert_node - adds a new node at the end of a listint_t list
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be added
 * Return: address of the new element or NULL if it fails
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *current;
	unsigned int index = 0;

	current = *head;

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;

	while (current != NULL)
	{
		if (number < current->next->n)
		{
			new->next = current->next;
			current->next = new;
			return (new);
		}
		current = current->next;
		index++;
	}

	return (new);
}
