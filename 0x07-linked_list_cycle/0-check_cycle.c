#include "lists.h"

/**
 * check_cycle - This function checks if there's a cycle
 * in the list.
 * @list: Pointer to head of list.
 * Return: Returns 1 if list has a cycle, 0 otherwise.
 */


int check_cycle(listint_t *list)
{

    listint_t *cur = NULL, *after_cur = NULL;

    if (!list)
    {
        return (0);
    }

    if (!list->next)
    {
        return (0);
    }

    cur = list;
    after_cur = list->next;

    while (after_cur && after_cur->next)
    {
        if (cur == after_cur)
        {
            return (1);
        }

        cur = cur->next;
        after_cur = after_cur->next->next;
    }

    if (after_cur)
    {
        if (after_cur == cur)
        {
            return (1);
        }
    }

    return (0);
}
