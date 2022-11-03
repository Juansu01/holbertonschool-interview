#include "list.h"

/**
 * add_node_end - Adds a new node to the end of linked list
 *
 * @list: List to add the node to.
 * @str: String that will be inserted into the new node.
 * Return: Address of new node, NULL otherwise.
 */

List *add_node_end(List **list, char *str)
{
    List *new_node = NULL;
    char *string = NULL;

    if (!list)
    {
        return (NULL);
    }

    new_node = malloc(sizeof(List));
    if (!new_node)
    {
        return (NULL);
    }

    string = strdup(str);
    if (string == NULL)
    {
        free(new_node);
        return (NULL);
    }

    new_node->str = string;

    if (!*list)
    {
        new_node->next = new_node;
		new_node->prev = new_node;
		*list = new_node;
		return (new_node);
    }

    new_node->next = *list;
	new_node->prev = (*list)->prev;

	(*list)->prev = new_node;
	new_node->prev->next = new_node;

	return (new_node);
}

/**
 * add_node_begin - Adds a new node to the end of linked list
 *
 * @list: List to add the node to.
 * @str: String that will be inserted into the new node.
 * Return: Address of new node, NULL otherwise.
 */

List *add_node_begin(List **list, char *str)
{
    List *new_node = NULL;
    char *string = NULL;

    if (!list)
    {
        return (NULL);
    }

    new_node = malloc(sizeof(List));
    if (!new_node)
    {
        return (NULL);
    }

    string = strdup(str);
    if (string == NULL)
    {
        free(new_node);
        return (NULL);
    }

    new_node->str = string;

    if (*list)
	{
		new_node->next = *list;
		new_node->prev = (*list)->prev;
		(*list)->prev = new_node;
		if (new_node->prev)
        {
			new_node->prev->next = new_node;
        }
	}
	else
	{
		new_node->prev = new_node;
		new_node->next = new_node;
	}

	*list = new_node;

	return (new_node);
}